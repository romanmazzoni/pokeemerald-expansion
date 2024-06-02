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


grove_fight_Cresselia::
	lockall
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CRESSELIA, 30, ITEM_MOON_STONE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne grove_fight_Cresselia_2
grove_fight_Cresselia_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

grove_fight_Cresselia_2:
	setflag FLAG_Cresselia
	goto grove_fight_Cresselia_1


fight_Calyrex::
	lockall
	playmoncry SPECIES_CALYREX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CALYREX, 40, ITEM_SACHET
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne fight_Calyrex_2
fight_Calyrex_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

fight_Calyrex_2:
	setflag FLAG_Calyrex
	goto fight_Calyrex_1


fight_Giratina::
	lockall
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GIRATINA, 50, ITEM_GRISEOUS_ORB
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne fight_Giratina_2
fight_Giratina_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

fight_Giratina_2:
	setflag FLAG_Giratina
	goto fight_Giratina_1


fight_kyurem::
	lockall
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KYUREM, 50, ITEM_DNA_SPLICERS
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne fight_kyurem_2
fight_kyurem_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

fight_kyurem_2:
	setflag FLAG_Kyurem
	goto fight_kyurem_1


fight_hoopa::
	lockall
	playmoncry SPECIES_HOOPA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_HOOPA, 50, ITEM_PRISON_BOTTLE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne fight_hoopa_2
fight_hoopa_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

fight_hoopa_2:
	setflag FLAG_Hoopa
	goto fight_hoopa_1


fight_NECROZMA::
	lockall
	playmoncry SPECIES_NECROZMA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_NECROZMA, 50, ITEM_STARDUST
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 0
	goto_if_ne fight_NECROZMA_2
fight_NECROZMA_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

fight_NECROZMA_2:
	setflag FLAG_Necrozma
	goto fight_NECROZMA_1

