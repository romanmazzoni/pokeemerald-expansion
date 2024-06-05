VictoryRoad_B3F_MapScripts::
	.byte 0

VR3_LORE::
	lockall
	msgbox VR3_LORE_Text_0
	releaseall
	return


VR3_ROCK::
	lockall
	msgbox VR3_ROCK_Text_0
	releaseall
	return


VR4_ROCK::
	lockall
	msgbox VR4_ROCK_Text_0
	releaseall
	return


VR3_fight_YVELTAL::
	lockall
	playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_YVELTAL, 55, ITEM_IRON_BALL
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_YVELTAL
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


VR3_fight_XERNEAS::
	lockall
	playmoncry SPECIES_XERNEAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_XERNEAS, 55, ITEM_AIR_BALLOON
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_XERNEAS
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return


VR3_LORE_Text_0:
	.string "Theres some really boring lore written\n"
	.string "on the wall.\p"
	.string "You decide to not read it.$"

VR3_ROCK_Text_0:
	.string "This rock mourns for its fallen\n"
	.string "rockrades.\p"
	.string "You feel a tinge of guilt and decide to\n"
	.string "spare it.$"

VR4_ROCK_Text_0:
	.string "There is no item in this rock.\p"
	.string "This room sucks.$"
