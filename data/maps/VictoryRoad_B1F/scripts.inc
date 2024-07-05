VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "The thought that I'm getting closer to\n"
	.string "the POKéMON LEAGUE…\p"
	.string "I'm getting stage fright…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "I couldn't do a thing…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "The POKéMON LEAGUE became distant\n"
	.string "again… No victory here…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Dominating your friends is\n"
	.string "such a mixed bag.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "In TF2.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "What do you think I meant?$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "You are not my friend.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "You are my brother, my friend!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "I love biceps!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "My POKéMON are comically\n"
	.string "awe inspiring!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "It's laughable how bad they are!$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Even outside of battle, I sense\n"
	.string "they can barely open a jar\l"
	.string "of peanut butter.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Okay, no need to get your back up!\n"
	.string "Relax, let's take it easy!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Whoa!\n"
	.string "Wonderful!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Sure, this is VICTORY ROAD.\p"
	.string "But it's not all that different from\n"
	.string "the path you've taken so far.\p"
	.string "It even uses a lot of the same\n"
	.string "tiles as other caves you've been to!$"
