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

Regiroom_Regigigas::
	lockall
	setflag FLAG_Regigigas
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 50, ITEM_ROCK_MEMORY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


Regiroom_Regidrago::
	lockall
	setflag FLAG_Regidrago
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 50, ITEM_DRACO_PLATE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


Regiroom_Regieleki::
	lockall
	setflag FLAG_Regieleki
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 50, ITEM_ZAP_PLATE
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

