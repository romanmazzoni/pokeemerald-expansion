Route135_MapScripts::
	.byte 0

ROUTE135_fight_Koridon::
	lockall
	playmoncry SPECIES_KORAIDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KORAIDON, 55, ITEM_IRON_BALL
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_KORAIDON
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

ROUTE135_fight_Miraidon::
	lockall
	playmoncry SPECIES_MIRAIDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MIRAIDON, 55, ITEM_IRON_BALL
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_MIRAIDON
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

ROUTE135_SIGN::
	lockall
	msgbox ROUTE135_SIGN_Text_0
	releaseall
	return


ROUTE135_SIGN_Text_0:
	.string "I had to put these guys\n"
	.string "in the game somewhere.$"
	
