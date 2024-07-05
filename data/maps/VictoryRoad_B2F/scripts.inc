VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "The pokemon I caught,\n"
	.string "They are all real!\l"
	.string "Everyone uses these!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "WAHHHHH?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Wait till I upgrade to\n"
	.string "porygon8!\p"
	.string "You won't stand a chance!$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "The little shrimp is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "I hate children.\p"
	.string "Why don't you just go outside\n"
	.string "and catch a bird in real life?$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Sweet!$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "I can't begin to know when!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "Good times never seemed so good.\n"
	.string "I've been inclined\l"
	.string "To believe they never would!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of GYM BADGES.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!\p"
	.string "Just think about world champ\n"
	.string "WolfyVGC!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "You're better than me!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "I have 8 badges.\n"
	.string "That should be more than$"
	.string "a chump like you.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh…\n"
	.string "It hurts…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the POKéMON LEAGUE.\p"
	.string "It's all I can do to feign calm.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Not rattled in the least bit!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"
