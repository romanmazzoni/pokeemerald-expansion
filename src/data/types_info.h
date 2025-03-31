#include "constants/battle.h"
#include "constants/pokemon.h"

#define X UQ_4_12
#define ______ X(1.0) // Regular effectiveness.

// Type matchup updates.                                                Attacker      Defender
#define STL_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_6 ? X(1.0) : X(0.5))  // Ghost/Dark -> Steel
#define PSN_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(0.5) : X(2.0))  // Bug        -> Poison
#define BUG_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(1.0) : X(2.0))  // Poison     -> Bug
#define PSY_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(2.0) : X(0.0))  // Ghost      -> Psychic
#define FIR_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(0.5) : X(1.0))  // Ice        -> Fire

const uq4_12_t gTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{//                   Defender -->
 //  Attacker           None   Normal Fighting Flying  Poison  Ground   Rock    Bug     Ghost   Steel  Mystery  Fire   Water   Grass  Electric Psychic   Ice   Dragon   Dark   Fairy   Stellar
    [TYPE_NONE]     = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_NORMAL]   = {______, ______, ______, ______, ______, ______, X(0.5), ______, X(0.0), X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FIGHTING] = {______, X(2.0), ______, X(0.5), X(0.5), ______, X(2.0), X(0.5), X(0.0), X(2.0), ______, ______, ______, ______, ______, X(0.5), X(2.0), ______, X(2.0), X(0.5), ______},
    [TYPE_FLYING]   = {______, ______, X(2.0), ______, ______, ______, X(0.5), X(2.0), ______, X(0.5), ______, ______, ______, X(2.0), X(0.5), ______, ______, ______, ______, ______, ______},
    [TYPE_POISON]   = {______, ______, ______, ______, X(0.5), X(0.5), X(0.5), BUG_RS, X(0.5), X(0.0), ______, ______, ______, X(2.0), ______, ______, ______, ______, ______, X(2.0), ______},
    [TYPE_GROUND]   = {______, ______, ______, X(0.0), X(2.0), ______, X(2.0), X(0.5), ______, X(2.0), ______, X(2.0), ______, X(0.5), X(2.0), ______, ______, ______, ______, ______, ______},
    [TYPE_ROCK]     = {______, ______, X(0.5), X(2.0), ______, X(0.5), ______, X(2.0), ______, X(0.5), ______, X(2.0), ______, ______, ______, ______, X(2.0), ______, ______, ______, ______},
    [TYPE_BUG]      = {______, ______, X(0.5), X(0.5), PSN_RS, ______, ______, ______, X(0.5), X(0.5), ______, X(0.5), ______, X(2.0), ______, X(2.0), ______, ______, X(2.0), X(0.5), ______},
    [TYPE_GHOST]    = {______, X(0.0), ______, ______, ______, ______, ______, ______, X(2.0), STL_RS, ______, ______, ______, ______, ______, PSY_RS, ______, ______, X(0.5), ______, ______},
    [TYPE_STEEL]    = {______, ______, ______, ______, ______, ______, X(2.0), ______, ______, X(0.5), ______, X(0.5), X(0.5), ______, X(0.5), ______, X(2.0), ______, ______, X(2.0), ______},
    [TYPE_MYSTERY]  = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FIRE]     = {______, ______, ______, ______, ______, ______, X(0.5), X(2.0), ______, X(2.0), ______, X(0.5), X(0.5), X(2.0), ______, ______, X(2.0), X(0.5), ______, ______, ______},
    [TYPE_WATER]    = {______, ______, ______, ______, ______, X(2.0), X(2.0), ______, ______, ______, ______, X(2.0), X(0.5), X(0.5), ______, ______, ______, X(0.5), ______, ______, ______},
    [TYPE_GRASS]    = {______, ______, ______, X(0.5), X(0.5), X(2.0), X(2.0), X(0.5), ______, X(0.5), ______, X(0.5), X(2.0), X(0.5), ______, ______, ______, X(0.5), ______, ______, ______},
    [TYPE_ELECTRIC] = {______, ______, ______, X(2.0), ______, X(0.0), ______, ______, ______, ______, ______, ______, X(2.0), X(0.5), X(0.5), ______, ______, X(0.5), ______, ______, ______},
    [TYPE_PSYCHIC]  = {______, ______, X(2.0), ______, X(2.0), ______, ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, X(0.5), ______, ______, X(0.0), ______, ______},
    [TYPE_ICE]      = {______, ______, ______, X(2.0), ______, X(2.0), ______, ______, ______, X(0.5), ______, FIR_RS, X(0.5), X(2.0), ______, ______, X(0.5), X(2.0), ______, ______, ______},
    [TYPE_DRAGON]   = {______, ______, ______, ______, ______, ______, ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, X(2.0), ______, X(0.0), ______},
    [TYPE_DARK]     = {______, ______, X(0.5), ______, ______, ______, ______, ______, X(2.0), STL_RS, ______, ______, ______, ______, ______, X(2.0), ______, ______, X(0.5), X(0.5), ______},
    [TYPE_FAIRY]    = {______, ______, X(2.0), ______, X(0.5), ______, ______, ______, ______, X(0.5), ______, X(0.5), ______, ______, ______, ______, ______, X(2.0), X(2.0), ______, ______},
    [TYPE_STELLAR]  = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
};

#undef ______
#undef X

// Notes regarding custom data:
// - The "generic" field is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
// - In this array there's commented-out data such as references to type-resist berries that would otherwise would go unused.
//   However, we figured this information would be useful for users that want to add their own types as a reminder of
//   what data would they need to add in order to have their new types be fully fledged like official types.
// - Changing "isHiddenPowerType" for any type will change the distribution of all Hidden Power types from vanilla.
const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NONE] =
    {
        .name = _("None"),
        .generic = _("a move"),
        .palette = 15, // Uses TYPE_MYSTERY's icon
        .teraTypeRGBValue = RGB_WHITE,
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_NormalTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = TRUE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_NORMAL] =
    {
        .name = _("Normal"),
        .generic = _("a NORMAL move"),
        .palette = 13,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB_WHITE, // custom
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_NormalTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
        //.enhanceItem = ITEM_SILK_SCARF,
        //.berry = ITEM_CHILAN_BERRY,
        //.gem = ITEM_NORMAL_GEM,
        //.zCrystal = ITEM_NORMALIUM_Z,
        //.teraShard = ITEM_NORMAL_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_NORMAL,
    },
    [TYPE_FIGHTING] =
    {
        .name = _("Fighting"),
        .generic = _("a FIGHTING move"),
        .palette = 13,
        .zMove = MOVE_ALL_OUT_PUMMELING,
        .maxMove = MOVE_MAX_KNUCKLE,
        .teraTypeRGBValue = RGB(26, 8, 14),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_FightingTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_BLACK_BELT,
        //.berry = ITEM_CHOPLE_BERRY,
        //.gem = ITEM_FIGHTING_GEM,
        //.zCrystal = ITEM_FIGHTINIUM_Z,
        //.plate = ITEM_FIST_PLATE,
        //.memory = ITEM_FIGHTING_MEMORY,
        //.teraShard = ITEM_FIGHTING_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_FIGHTING,
    },
    [TYPE_FLYING] =
    {
        .name = _("Flying"),
        .generic = _("a FLYING move"),
        .palette = 14,
        .zMove = MOVE_SUPERSONIC_SKYSTRIKE,
        .maxMove = MOVE_MAX_AIRSTREAM,
        .teraTypeRGBValue = RGB(31, 26, 7),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_FlyingTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_SHARP_BEAK,
        //.berry = ITEM_COBA_BERRY,
        //.gem = ITEM_FLYING_GEM,
        //.zCrystal = ITEM_FLYINIUM_Z,
        //.plate = ITEM_SKY_PLATE,
        //.memory = ITEM_FLYING_MEMORY,
        //.teraShard = ITEM_FLYING_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_FLYING,
    },
    [TYPE_POISON] =
    {
        .name = _("Poison"),
        .generic = _("a POISON move"),
        .palette = 14,
        .zMove = MOVE_ACID_DOWNPOUR,
        .maxMove = MOVE_MAX_OOZE,
        .teraTypeRGBValue = RGB(26, 10, 25), // custom
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_PoisonTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_POISON_BARB,
        //.berry = ITEM_KEBIA_BERRY,
        //.gem = ITEM_POISON_GEM,
        //.zCrystal = ITEM_POISONIUM_Z,
        //.plate = ITEM_TOXIC_PLATE,
        //.memory = ITEM_POISON_MEMORY,
        //.teraShard = ITEM_POISON_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_POISON,
    },
    [TYPE_GROUND] =
    {
        .name = _("Ground"),
        .generic = _("a GROUND move"),
        .palette = 13,
        .zMove = MOVE_TECTONIC_RAGE,
        .maxMove = MOVE_MAX_QUAKE,
        .teraTypeRGBValue = RGB(25, 23, 18),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_GroundTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_SOFT_SAND,
        //.berry = ITEM_SHUCA_BERRY,
        //.gem = ITEM_GROUND_GEM,
        //.zCrystal = ITEM_GROUNDIUM_Z,
        //.plate = ITEM_EARTH_PLATE,
        //.memory = ITEM_GROUND_MEMORY,
        //.teraShard = ITEM_GROUND_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_GROUND,
    },
    [TYPE_ROCK] =
    {
        .name = _("Rock"),
        .generic = _("a ROCK move"),
        .palette = 13,
        .zMove = MOVE_CONTINENTAL_CRUSH,
        .maxMove = MOVE_MAX_ROCKFALL,
        .teraTypeRGBValue = RGB(18, 16, 8), // custom
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_RockTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_HARD_STONE,
        //.berry = ITEM_CHARTI_BERRY,
        //.gem = ITEM_ROCK_GEM,
        //.zCrystal = ITEM_ROCKIUM_Z,
        //.plate = ITEM_STONE_PLATE,
        //.memory = ITEM_ROCK_MEMORY,
        //.teraShard = ITEM_ROCK_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_ROCK,
    },
    [TYPE_BUG] =
    {
        .name = _("Bug"),
        .generic = _("a BUG move"),
        .palette = 15,
        .zMove = MOVE_SAVAGE_SPIN_OUT,
        .maxMove = MOVE_MAX_FLUTTERBY,
        .teraTypeRGBValue = RGB(18, 24, 6),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_BugTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_SILVER_POWDER,
        //.berry = ITEM_TANGA_BERRY,
        //.gem = ITEM_BUG_GEM,
        //.zCrystal = ITEM_BUGINIUM_Z,
        //.plate = ITEM_INSECT_PLATE,
        //.memory = ITEM_BUG_MEMORY,
        //.teraShard = ITEM_BUG_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_BUG,
    },
    [TYPE_GHOST] =
    {
        .name = _("Ghost"),
        .generic = _("a GHOST move"),
        .palette = 14,
        .zMove = MOVE_NEVER_ENDING_NIGHTMARE,
        .maxMove = MOVE_MAX_PHANTASM,
        .teraTypeRGBValue = RGB(12, 10, 16),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_GhostTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_SPELL_TAG,
        //.berry = ITEM_KASIB_BERRY,
        //.gem = ITEM_GHOST_GEM,
        //.zCrystal = ITEM_GHOSTIUM_Z,
        //.plate = ITEM_SPOOKY_PLATE,
        //.memory = ITEM_GHOST_MEMORY,
        //.teraShard = ITEM_GHOST_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_GHOST,
    },
    [TYPE_STEEL] =
    {
        .name = _("Steel"),
        .generic = _("a STEEL move"),
        .palette = 13,
        .zMove = MOVE_CORKSCREW_CRASH,
        .maxMove = MOVE_MAX_STEELSPIKE,
        .teraTypeRGBValue = RGB(19, 19, 20),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_SteelTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_METAL_COAT,
        //.berry = ITEM_BABIRI_BERRY,
        //.gem = ITEM_STEEL_GEM,
        //.zCrystal = ITEM_STEELIUM_Z,
        //.plate = ITEM_IRON_PLATE,
        //.memory = ITEM_STEEL_MEMORY,
        //.teraShard = ITEM_STEEL_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_STEEL,
    },
    [TYPE_MYSTERY] =
    {
        .name = _("???"),
        .generic = _("a ??? move"),
        .palette = 15,
        .teraTypeRGBValue = RGB_WHITE,
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = TRUE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_FIRE] =
    {
        .name = _("Fire"),
        .generic = _("a FIRE move"),
        .palette = 13,
        .zMove = MOVE_INFERNO_OVERDRIVE,
        .maxMove = MOVE_MAX_FLARE,
        .teraTypeRGBValue = RGB(31, 20, 11),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FireTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_CHARCOAL,
        //.berry = ITEM_OCCA_BERRY,
        //.gem = ITEM_FIRE_GEM,
        //.zCrystal = ITEM_FIRIUM_Z,
        //.plate = ITEM_FLAME_PLATE,
        //.memory = ITEM_FIRE_MEMORY,
        //.teraShard = ITEM_FIRE_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_FIRE,
    },
    [TYPE_WATER] =
    {
        .name = _("Water"),
        .generic = _("a WATER move"),
        .palette = 14,
        .zMove = MOVE_HYDRO_VORTEX,
        .maxMove = MOVE_MAX_GEYSER,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_WaterTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_MYSTIC_WATER,
        //.berry = ITEM_PASSHO_BERRY,
        //.gem = ITEM_WATER_GEM,
        //.zCrystal = ITEM_WATERIUM_Z,
        //.plate = ITEM_SPLASH_PLATE,
        //.memory = ITEM_WATER_MEMORY,
        //.teraShard = ITEM_WATER_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_WATER,
    },
    [TYPE_GRASS] =
    {
        .name = _("Grass"),
        .generic = _("a GRASS move"),
        .palette = 15,
        .zMove = MOVE_BLOOM_DOOM,
        .maxMove = MOVE_MAX_OVERGROWTH,
        .teraTypeRGBValue = RGB(12, 24, 11),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_GrassTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_MIRACLE_SEED,
        //.berry = ITEM_RINDO_BERRY,
        //.gem = ITEM_GRASS_GEM,
        //.zCrystal = ITEM_GRASSIUM_Z,
        //.plate = ITEM_MEADOW_PLATE,
        //.memory = ITEM_GRASS_MEMORY,
        //.teraShard = ITEM_GRASS_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_GRASS,
    },
    [TYPE_ELECTRIC] =
    {
        .name = _("Electric"),
        .generic = _("an ELECTRIC move"),
        .palette = 13,
        .zMove = MOVE_GIGAVOLT_HAVOC,
        .maxMove = MOVE_MAX_LIGHTNING,
        .teraTypeRGBValue = RGB(30, 26, 7),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_ElectricTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_MAGNET,
        //.berry = ITEM_WACAN_BERRY,
        //.gem = ITEM_ELECTRIC_GEM,
        //.zCrystal = ITEM_ELECTRIUM_Z,
        //.plate = ITEM_ZAP_PLATE,
        //.memory = ITEM_ELECTRIC_MEMORY,
        //.teraShard = ITEM_ELECTRIC_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_ELECTRIC,
    },
    [TYPE_PSYCHIC] =
    {
        .name = _("Psychic"),
        .generic = _("a PSYCHIC move"),
        .palette = 14,
        .zMove = MOVE_SHATTERED_PSYCHE,
        .maxMove = MOVE_MAX_MINDSTORM,
        .teraTypeRGBValue = RGB(31, 14, 15),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_PsychicTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_TWISTED_SPOON,
        //.berry = ITEM_PAYAPA_BERRY,
        //.gem = ITEM_PSYCHIC_GEM,
        //.zCrystal = ITEM_PSYCHIUM_Z,
        //.plate = ITEM_MIND_PLATE,
        //.memory = ITEM_PSYCHIC_MEMORY,
        //.teraShard = ITEM_PSYCHIC_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_PSYCHIC,
    },
    [TYPE_ICE] =
    {
        .name = _("Ice"),
        .generic = _("an ICE move"),
        .palette = 14,
        .zMove = MOVE_SUBZERO_SLAMMER,
        .maxMove = MOVE_MAX_HAILSTORM,
        .teraTypeRGBValue = RGB(14, 26, 25),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_IceTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_NEVER_MELT_ICE,
        //.berry = ITEM_YACHE_BERRY,
        //.gem = ITEM_ICE_GEM,
        //.zCrystal = ITEM_ICIUM_Z,
        //.plate = ITEM_ICICLE_PLATE,
        //.memory = ITEM_ICE_MEMORY,
        //.teraShard = ITEM_ICE_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_ICE,
    },
    [TYPE_DRAGON] =
    {
        .name = _("Dragon"),
        .generic = _("a DRAGON move"),
        .palette = 15,
        .zMove = MOVE_DEVASTATING_DRAKE,
        .maxMove = MOVE_MAX_WYRMWIND,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DragonTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_DRAGON_FANG,
        //.berry = ITEM_HABAN_BERRY,
        //.gem = ITEM_DRAGON_GEM,
        //.zCrystal = ITEM_DRAGONIUM_Z,
        //.plate = ITEM_DRACO_PLATE,
        //.memory = ITEM_DRAGON_MEMORY,
        //.teraShard = ITEM_DRAGON_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_DRAGON,
    },
    [TYPE_DARK] =
    {
        .name = _("Dark"),
        .generic = _("a DARK move"),
        .palette = 13,
        .zMove = MOVE_BLACK_HOLE_ECLIPSE,
        .maxMove = MOVE_MAX_DARKNESS,
        .teraTypeRGBValue = RGB(6, 5, 8),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DarkTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
        //.enhanceItem = ITEM_BLACK_GLASSES,
        //.berry = ITEM_COLBUR_BERRY,
        //.gem = ITEM_DARK_GEM,
        //.zCrystal = ITEM_DARKINIUM_Z,
        //.plate = ITEM_DREAD_PLATE,
        //.memory = ITEM_DARK_MEMORY,
        //.teraShard = ITEM_DARK_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_DARK,
    },
    [TYPE_FAIRY] =
    {
        .name = _("Fairy"),
        .generic = _("a FAIRY move"),
        .palette = 14,
        .zMove = MOVE_TWINKLE_TACKLE,
        .maxMove = MOVE_MAX_STARFALL,
        .teraTypeRGBValue = RGB(31, 15, 21),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FairyTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
        //.enhanceItem = ITEM_FAIRY_FEATHER,
        //.berry = ITEM_ROSELI_BERRY,
        //.gem = ITEM_FAIRY_GEM,
        //.zCrystal = ITEM_FAIRIUM_Z,
        //.plate = ITEM_PIXIE_PLATE,
        //.memory = ITEM_FAIRY_MEMORY,
        //.teraShard = ITEM_FAIRY_TERA_SHARD,
        //.arceusForm = SPECIES_ARCEUS_FAIRY,
    },
    [TYPE_STELLAR] =
    {
        .name = _("Stellar"),
        .generic = _("a STELLAR move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = TRUE,
        .isHiddenPowerType = FALSE,
        // .teraShard = ITEM_STELLAR_TERA_SHARD,
    },
    [TYPE_FURRY] =
    {
        .name = _("FURRY"),
        .generic = _("a FURRY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_BEAR] =
    {
        .name = _("BEAR"),
        .generic = _("a BEAR move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FRUITY] =
    {
        .name = _("FRUITY"),
        .generic = _("a FRUITY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_TREE] =
    {
        .name = _("TREE"),
        .generic = _("a TREE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SHUCKLE] =
    {
        .name = _("SHUCKLE"),
        .generic = _("a SHUCKLE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_UGLY] =
    {
        .name = _("UGLY"),
        .generic = _("a UGLY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_MASSIVE] =
    {
        .name = _("MASSIVE"),
        .generic = _("a MASSIVE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SHORT] =
    {
        .name = _("SHORT"),
        .generic = _("a SHORT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_KING] =
    {
        .name = _("KING"),
        .generic = _("a KING move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_GOD] =
    {
        .name = _("GOD"),
        .generic = _("a GOD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SPACE] =
    {
        .name = _("SPACE"),
        .generic = _("a SPACE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_STALL] =
    {
        .name = _("STALL"),
        .generic = _("a STALL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LOSER] =
    {
        .name = _("LOSER"),
        .generic = _("a LOSER move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_EVIL] =
    {
        .name = _("EVIL"),
        .generic = _("a EVIL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FUN] =
    {
        .name = _("FUN"),
        .generic = _("a FUN move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_NERD] =
    {
        .name = _("NERD"),
        .generic = _("a NERD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_OAK] =
    {
        .name = _("OAK"),
        .generic = _("a OAK move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_WOOD] =
    {
        .name = _("WOOD"),
        .generic = _("a WOOD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_TABLE] =
    {
        .name = _("TABLE"),
        .generic = _("a TABLE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_BEE] =
    {
        .name = _("BEE"),
        .generic = _("a BEE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_COOL] =
    {
        .name = _("COOL"),
        .generic = _("a COOL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FISH] =
    {
        .name = _("FISH"),
        .generic = _("a FISH move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_HARD] =
    {
        .name = _("HARD"),
        .generic = _("a HARD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FAKE] =
    {
        .name = _("FAKE"),
        .generic = _("a FAKE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_TRAIN] =
    {
        .name = _("TRAIN"),
        .generic = _("a TRAIN move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_GOOFY] =
    {
        .name = _("GOOFY"),
        .generic = _("a GOOFY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SUBMISSIVE] =
    {
        .name = _("SUB"),
        .generic = _("a SUBMISIVE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_WAFFLEHOUSE] =
    {
        .name = _("WAFFLE"),
        .generic = _("a WAFLEHOSE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_EGO] =
    {
        .name = _("EGO"),
        .generic = _("a EGO move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_WIZARD] =
    {
        .name = _("WIZARD"),
        .generic = _("a WIZARD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SONG] =
    {
        .name = _("SONG"),
        .generic = _("a SONG move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_TECH] =
    {
        .name = _("TECH"),
        .generic = _("a TECH move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SNOW] =
    {
        .name = _("SNOW"),
        .generic = _("a SNOW move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SMART] =
    {
        .name = _("SMART"),
        .generic = _("a SMART move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_STUPID] =
    {
        .name = _("STUPID"),
        .generic = _("a STUPID move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_MONEY] =
    {
        .name = _("MONEY"),
        .generic = _("a MONEY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_DOG] =
    {
        .name = _("DOG"),
        .generic = _("a DOG move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_CAT] =
    {
        .name = _("CAT"),
        .generic = _("a CAT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_PITBULL] =
    {
        .name = _("PITBULL"),
        .generic = _("a PITBULL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_NINJA] =
    {
        .name = _("NINJA"),
        .generic = _("a NINJA move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_HMSLAVE] =
    {
        .name = _("HMSLAVE"),
        .generic = _("a HMSLAVE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_RED] =
    {
        .name = _("RED"),
        .generic = _("a RED move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_BLUE] =
    {
        .name = _("BLUE"),
        .generic = _("a BLUE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SCARY] =
    {
        .name = _("SCARY"),
        .generic = _("a SCARY move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SPORTS] =
    {
        .name = _("SPORTS"),
        .generic = _("a SPORTS move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SOFT] =
    {
        .name = _("SOFT"),
        .generic = _("a SOFT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SLEDGE] =
    {
        .name = _("SLEDGE"),
        .generic = _("a SLEDGE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_EXPLOSION] =
    {
        .name = _("BOOM"),
        .generic = _("a EXPLOSION move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_TURTLE] =
    {
        .name = _("TURTLE"),
        .generic = _("a TURTLE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_DINO] =
    {
        .name = _("DINO"),
        .generic = _("a DINO move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_DANCE] =
    {
        .name = _("DANCE"),
        .generic = _("a DANCE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SAND] =
    {
        .name = _("SAND"),
        .generic = _("a SAND move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_HUMAN] =
    {
        .name = _("HUMAN"),
        .generic = _("a HUMAN move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LAVA] =
    {
        .name = _("LAVA"),
        .generic = _("a LAVA move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SNAKE] =
    {
        .name = _("SNAKE"),
        .generic = _("a SNAKE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LANCE] =
    {
        .name = _("LANCE"),
        .generic = _("a LANCE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_VOID] =
    {
        .name = _("VOID"),
        .generic = _("a VOID move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_BANANA] =
    {
        .name = _("BANANA"),
        .generic = _("a BANANA move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LOVE] =
    {
        .name = _("LOVE"),
        .generic = _("a LOVE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_OLD] =
    {
        .name = _("OLD"),
        .generic = _("a OLD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_REVERSE] =
    {
        .name = _("REVERSE"),
        .generic = _("a REVERSE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_BALL] =
    {
        .name = _("BALL"),
        .generic = _("a BALL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_WATER2] =
    {
        .name = _("WATER2"),
        .generic = _("a WATER2 move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_HOT] =
    {
        .name = _("HOT"),
        .generic = _("a HOT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_DEATH] =
    {
        .name = _("DEATH"),
        .generic = _("a DEATH move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SHROOM] =
    {
        .name = _("SHROOM"),
        .generic = _("a SHROOM move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FAT] =
    {
        .name = _("FAT"),
        .generic = _("a FAT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LIGHT] =
    {
        .name = _("LIGHT"),
        .generic = _("a LIGHT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LIFE] =
    {
        .name = _("LIFE"),
        .generic = _("a LIFE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_LOUD] =
    {
        .name = _("LOUD"),
        .generic = _("a LOUD move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_WALL] =
    {
        .name = _("WALL"),
        .generic = _("a WALL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_FAST] =
    {
        .name = _("FAST"),
        .generic = _("a FAST move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_PLURAL] =
    {
        .name = _("PLURAL"),
        .generic = _("a PLURAL move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_HUNT] =
    {
        .name = _("HUNT"),
        .generic = _("a HUNT move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_GLASS] =
    {
        .name = _("GLASS"),
        .generic = _("a GLASS move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_ON] =
    {
        .name = _("ON"),
        .generic = _("a ON move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_SWEET] =
    {
        .name = _("SWEET"),
        .generic = _("a SWEET move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_PLAGUE] =
    {
        .name = _("PLAGUE"),
        .generic = _("a PLAGUE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_DOCTOR] =
    {
        .name = _("DOCTOR"),
        .generic = _("a DOCTOR move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_JOKE] =
    {
        .name = _("JOKE"),
        .generic = _("a JOKE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_VIABLE] =
    {
        .name = _("VIABLE"),
        .generic = _("a VIABLE move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },[TYPE_101] =
    {
        .name = _("101"),
        .generic = _("a 101 move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .paletteTMHM = gItemIconPalette_NormalTMHM, // failsafe
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
};
