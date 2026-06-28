Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "I heard about a cave called CHARGESTONE\n"
	.string "CAVE.\p"
	.string "People rumor that the spirits of\n"
	.string "electric are revived there. Could\l"
	.string "be thinking of the wrong game?$"

Route119_House_Text_Wingull:
	.string "WINGULL: Pihyoh!$"

