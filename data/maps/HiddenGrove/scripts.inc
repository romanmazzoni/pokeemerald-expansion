HiddenGrove_MapScripts::
	.byte 0
grove_fight_Cresselia::
	lock
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CRESSELIA, 50, ITEM_NONE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Cresselia
	release
	end
