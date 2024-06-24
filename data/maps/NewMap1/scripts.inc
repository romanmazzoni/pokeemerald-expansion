    NewMap1_MapScripts::
	.byte 0

    Regigigas_sign::
	lockall
	braillemsgbox Regigigas_sign_Text_0
	releaseall
	return

	Regigigas_sign2::
	lockall
	braillemsgbox Regigigas_sign_Text_1
	releaseall
	return

	Regigigas_sign3::
	lockall
	braillemsgbox Regigigas_sign_Text_2
	releaseall
	return

Regigigas_sign_Text_0:
	brailleformat 3, 2, 27, 17, 6, 5	
	.braille "L DID\n"
	.braille "YOU KNOW$"

Regigigas_sign_Text_1:
	brailleformat 3, 2, 27, 17, 6, 5	
	.braille "GODS OF\n"
	.braille "DEATH$"

Regigigas_sign_Text_2:
	brailleformat 3, 2, 27, 17, 6, 5	
	.braille "LOVE\n"
	.braille "APPLES?$"

    Regiroom_EventScript_Regired::
	trainerbattle_single TRAINER_RED, Regiroom_Text_REDIntro, Regiroom_Text_REDDefeat
	msgbox Regiroom_Text_REDPostBattle, MSGBOX_AUTOCLOSE
    return

    Regiroom_Text_REDIntro:
	.string "Prove yourself.$"

    Regiroom_Text_REDDefeat:
	.string "Good enough.$"
    
	Regiroom_Text_REDPostBattle:
	.string "No reason for me\p"
    .string "to stop you.$"

Regiroom_EventScript_RedBattle::
	lockall
	goto_if_unset FLAG_BADGE08_GET, Regiroom_EventScript_RedBattle_2
	goto Regiroom_EventScript_Regired
	setflag FLAG_regired_battle
	fadescreen FADE_TO_BLACK
	removeobject 4
	fadescreen FADE_FROM_BLACK
Regiroom_EventScript_RedBattle_1:
	releaseall
	return

Regiroom_EventScript_RedBattle_2:
	msgbox Regiroom_EventScript_RedBattle_Text_0
	goto Regiroom_EventScript_RedBattle_1


Regiroom_Regigigas::
	lockall
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 50, ITEM_ROCK_MEMORY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Regigigas
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


Regiroom_Regidrago::
	lockall
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 50, ITEM_DRACO_PLATE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Regidrago
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


Regiroom_Regieleki::
	lockall
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 50, ITEM_ZAP_PLATE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_Regieleki
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


Regiroom_EventScript_RedBattle_Text_0:
	.string "I guard these three beings. You are not\n"
	.string "ready to face me. Come back when you\l"
	.string "have 8 gym badges.$"
