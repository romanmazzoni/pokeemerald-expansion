NavelRock_Fork_MapScripts::
	.byte 0

navelrock_fork_fight_reshiram::
	lockall
	setflag FLAG_reshiram
	playmoncry SPECIES_RESHIRAM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RESHIRAM, 50, ITEM_SITRUS_BERRY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


navelrock_fork_fight_zekrom::
	lockall
	setflag FLAG_zekrom
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZEKROM, 50, ITEM_TOXIC_ORB
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

