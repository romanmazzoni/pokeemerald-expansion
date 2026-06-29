/**
 * Gen 1 importer for Google Sheets.
 *
 * How to use:
 * 1) Put your species table in sheet "Sheet1" (or change SHEET_NAME).
 *    - Column A: Species name (Bulbasaur, Ivysaur, ...)
 *    - Columns B-D: Type1, Type2, Type3 (will be overwritten)
 *    - Columns F-H: Innate1, Innate2, Innate3 (will be overwritten)
 * 2) Choose ONE source mode:
 *    - Embedded mode (recommended): paste full gen_1_families.h text into
 *      EMBEDDED_GEN1_SOURCE below.
 *    - Sheet mode: paste gen_1_families.h into sheet "RawGen1" in chunks down column A.
 *    Example: A1 has first chunk, A2 has next chunk, etc.
 * 3) Run importGen1TypesAndInnates().
 */

const SHEET_NAME = 'Sheet1';
const RAW_SHEET_NAME = 'RawGen1';
const RAW_SOURCE_COLUMN = 1; // A

// Embedded mode: paste full gen_1_families.h text between the backticks.
// Leave empty to use sheet mode (RawGen1 column A chunks).
const EMBEDDED_GEN1_SOURCE = ``;

const COL = {
  speciesName: 1, // A
  type1: 2,       // B
  type2: 3,       // C
  type3: 4,       // D
  innate1: 6,     // F
  innate2: 7,     // G
  innate3: 8      // H
};

function importGen1TypesAndInnates() {
  const ss = SpreadsheetApp.getActiveSpreadsheet();
  const sheet = ss.getSheetByName(SHEET_NAME);

  if (!sheet) {
    throw new Error('Missing sheet: ' + SHEET_NAME);
  }

  const source = getSourceText(ss);
  if (!source.trim()) {
    throw new Error('Source is empty. Paste into EMBEDDED_GEN1_SOURCE or use ' + RAW_SHEET_NAME + ' column A (A1, A2, A3, ...).');
  }

  const parsedByName = parseSpeciesInfo(source);

  const lastRow = sheet.getLastRow();
  if (lastRow < 2) {
    return;
  }

  const speciesRange = sheet.getRange(2, COL.speciesName, lastRow - 1, 1);
  const speciesValues = speciesRange.getValues();

  const typeOut = [];
  const innateOut = [];

  for (let i = 0; i < speciesValues.length; i++) {
    const sheetName = normalizeName(speciesValues[i][0]);
    const data = parsedByName.get(sheetName);

    if (!data) {
      typeOut.push(['', '', '']);
      innateOut.push(['', '', '']);
      continue;
    }

    typeOut.push([
      data.types[0] || '',
      data.types[1] || '',
      data.types[2] || ''
    ]);

    innateOut.push([
      data.innates[0] || '',
      data.innates[1] || '',
      data.innates[2] || ''
    ]);
  }

  sheet.getRange(2, COL.type1, typeOut.length, 3).setValues(typeOut);
  sheet.getRange(2, COL.innate1, innateOut.length, 3).setValues(innateOut);
}

function getSourceText(ss) {
  const embedded = String(EMBEDDED_GEN1_SOURCE || '');
  if (embedded.trim()) {
    return embedded;
  }

  const rawSheet = ss.getSheetByName(RAW_SHEET_NAME);
  if (!rawSheet) {
    throw new Error('Missing sheet: ' + RAW_SHEET_NAME + '. Create it, or use EMBEDDED_GEN1_SOURCE.');
  }

  return getRawSourceText(rawSheet);
}

function getRawSourceText(rawSheet) {
  const lastRow = rawSheet.getLastRow();
  if (lastRow < 1) {
    return '';
  }

  const values = rawSheet.getRange(1, RAW_SOURCE_COLUMN, lastRow, 1).getValues();
  const chunks = [];

  for (let i = 0; i < values.length; i++) {
    const chunk = String(values[i][0] || '');
    if (!chunk.trim()) {
      continue;
    }
    chunks.push(chunk);
  }

  return chunks.join('\n');
}

function parseSpeciesInfo(text) {
  const map = new Map();

  // Species block: [SPECIES_X] = { ... },
  const blockRegex = /\[SPECIES_([A-Z0-9_]+)\]\s*=\s*\{([\s\S]*?)^\s*\},/gm;
  let match;

  while ((match = blockRegex.exec(text)) !== null) {
    const speciesConst = match[1];
    const body = match[2];

    const speciesName = extractSpeciesName(body);
    const natDexConst = extractNatDexConst(body);
    const types = extractMacroValues(body, 'types', 'MON_TYPES');
    const innates = extractBraceValues(body, 'innates');

    if (!speciesName || !natDexConst) {
      continue;
    }

    // Keep canonical entries and ignore forms like _MEGA/_GALAR/_ALOLA,
    // which usually have natDex of another species.
    if (natDexConst !== speciesConst) {
      continue;
    }

    const key = normalizeName(speciesName);

    if (!map.has(key)) {
      map.set(key, {
        speciesName,
        types: types.map(formatToken),
        innates: innates.map(formatToken)
      });
    }
  }

  return map;
}

function extractSpeciesName(body) {
  const m = body.match(/^\s*\.speciesName\s*=\s*_\("([^"]+)"\)/m);
  return m ? m[1] : '';
}

function extractNatDexConst(body) {
  const m = body.match(/^\s*\.natDexNum\s*=\s*NATIONAL_DEX_([A-Z0-9_]+)\s*,/m);
  return m ? m[1] : '';
}

function extractMacroValues(body, fieldName, macroName) {
  const line = getActiveFieldLine(body, fieldName);
  if (!line) return [];

  const macro = new RegExp(macroName + '\\(([^)]*)\\)');
  const m = line.match(macro);
  if (!m) return [];

  return m[1]
    .split(',')
    .map(s => s.trim())
    .filter(Boolean)
    .map(s => s.replace(/^TYPE_/, ''));
}

function extractBraceValues(body, fieldName) {
  const line = getActiveFieldLine(body, fieldName);
  if (!line) return [];

  const m = line.match(/\{([^}]*)\}/);
  if (!m) return [];

  return m[1]
    .split(',')
    .map(s => s.trim())
    .filter(Boolean)
    .map(s => s.replace(/^ABILITY_/, ''));
}

function getActiveFieldLine(body, fieldName) {
  const lines = body.split('\n');
  const fieldRegex = new RegExp('^\\s*\\.' + fieldName + '\\s*=');
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    if (line.trim().startsWith('//')) {
      continue;
    }
    if (fieldRegex.test(line)) {
      return line;
    }
  }
  return '';
}

function formatToken(token) {
  // Keeps custom tokens readable (e.g. SHOULEIL -> Shouleil).
  return token
    .toLowerCase()
    .split('_')
    .map(w => w ? (w[0].toUpperCase() + w.slice(1)) : w)
    .join(' ');
}

function normalizeName(name) {
  return String(name || '')
    .trim()
    .toLowerCase()
    .replace(/[\.'’\-\s]/g, '');
}
