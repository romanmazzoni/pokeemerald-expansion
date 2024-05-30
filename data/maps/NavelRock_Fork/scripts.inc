NavelRock_Fork_MapScripts::
	.byte 0

navelrock_fork_fight_reshiram::
	lockall
	playmoncry SPECIES_RESHIRAM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RESHIRAM, 50, ITEM_SITRUS_BERRY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne navelrock_fork_fight_reshiram_2
navelrock_fork_fight_reshiram_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

navelrock_fork_fight_reshiram_2:
	setflag FLAG_reshiram
	goto navelrock_fork_fight_reshiram_1


navelrock_fork_fight_zekrom::
	lockall
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZEKROM, 50, ITEM_TOXIC_ORB
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne navelrock_fork_fight_zekrom_2
navelrock_fork_fight_zekrom_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

navelrock_fork_fight_zekrom_2:
	setflag FLAG_zekrom
	goto navelrock_fork_fight_zekrom_1

