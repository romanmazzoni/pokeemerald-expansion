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
	setflag FLAG_reshiram
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


navelrock_fork_fight_zekrom::
	lockall
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZEKROM, 50, ITEM_TOXIC_ORB
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_zekrom
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


grove_fight_Cresselia::
	lockall
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CRESSELIA, 30, ITEM_MOON_STONE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Cresselia
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


fight_Calyrex::
	lockall
	playmoncry SPECIES_CALYREX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CALYREX, 40, ITEM_SACHET
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Calyrex
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


fight_Giratina::
	lockall
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GIRATINA, 30, ITEM_GRISEOUS_ORB
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Giratina
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


fight_kyurem::
	lockall
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KYUREM, 50, ITEM_DNA_SPLICERS
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Kyurem
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


fight_hoopa::
	lockall
	playmoncry SPECIES_HOOPA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_HOOPA, 30, ITEM_PRISON_BOTTLE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Hoopa
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


fight_NECROZMA::
	lockall
	playmoncry SPECIES_NECROZMA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_NECROZMA, 50, ITEM_STARDUST
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Necrozma
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

