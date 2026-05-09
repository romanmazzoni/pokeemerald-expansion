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

ROUTE135_Hiker1::
	lockall
	faceplayer
	msgbox ROUTE135_Hiker1_Text_0
	releaseall
	return

ROUTE135_Hiker2::
	lockall
	faceplayer
	msgbox ROUTE135_Hiker2_Text_0
	releaseall
	return


ROUTE135_SIGN_Text_0:
	.string "I had to put these guys\n"
	.string "in the game somewhere.$"

ROUTE135_Hiker1_Text_0:
	.string "We really just ran out\n"
	.string "of room for the remaining legendaries.\p"
	.string "Just shove em all here I guess.$"

ROUTE135_Hiker2_Text_0:
	.string "Nothing useful in here.\n"
	.string "Just a few smolvivies.$"
