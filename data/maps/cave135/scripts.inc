cave135_MapScripts::
	.byte 0

ROUTE135Cave_Hiker::
	lockall
	faceplayer
	msgbox ROUTE135Cave_Hiker_Text_0
	releaseall
	return


ROUTE135Cave_Hiker_Text_0:
	.string "And just like that my personal\n"
	.string "secret cave is ruined.$"

