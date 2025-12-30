Route1152_MapScripts::
	.byte 0
fight_Calyrex::
	lock
	playmoncry SPECIES_CALYREX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CALYREX, 50, ITEM_NONE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Calyrex
	release
	end

