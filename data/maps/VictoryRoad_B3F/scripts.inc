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


VR3_fight_YVELTAL::
	lockall
	setflag FLAG_YVELTAL
	playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_YVELTAL, 55, ITEM_IRON_BALL
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
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
	compare VAR_RESULT, 0
	goto_if_ne VR3_fight_XERNEAS_2
VR3_fight_XERNEAS_1:
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	waitmessage
	releaseall
	return

VR3_fight_XERNEAS_2:
	setflag FLAG_XERNEAS
	goto VR3_fight_XERNEAS_1


VR3_LORE_Text_0:
	.string "Theres some really boring lore written\n"
	.string "on the wall.\p"
	.string "You decide to not read it.$"

VR3_ROCK_Text_0:
	.string "This rock moarns for its fallen\n"
	.string "rockrades. You feel a tinge of guilt\l"
	.string "and spare it.$"
