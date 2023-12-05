.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEPHEN, MeteorFalls_StevensCave_Text_StevenDefeat2
	msgbox MeteorFalls_StevensCave_Text_StevenDefeat3, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_StevenDefeat3, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a GOD amongst men?\p"
	.string "Well then you know whats coming.\p"
	.string "You've been undeafeated up to now\n"
	.string "But even gods must die.\p"
	.string "Wait that doesn't make sense.\p"
	.string "Anyway, the time has come to test you.\p"
	.string "Okay, {PLAYER}{KUN}, you're out of luck\n"
	.string "Now for a challenge worthy of a champion!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Well, you've worked hard for this!\p"
	.string "And you did not disappoint!$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: HAHA! \n"
	.string "WELL DONE WELL DONE!\l"
	.string "That wasn't even a close battle.\p"
	.string "I haven't lost a battle to anyone\n"
	.string "in a considerable bit of time.\p"
	.string "You really are worth my time.\p"
	.string "I guess this was fate {PLAYER}{KUN}.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "STEPHEN: I must admit I was holding back\n"
	.string "but don't worry about that anymore\p"
	.string "Hey, {PLAYER}{KUN} promise you'll keep up?$"

MeteorFalls_StevensCave_Text_StevenDefeat2:
	.string "I can't go on\p"
	.string "There is no stopping you!$"

MeteorFalls_StevensCave_Text_StevenDefeat3:
	.string "STEPHEN: Nothing more to say about it\n"
	.string "You beat me while I was going all out\p"
	.string "You are the true champion of Hoenn.\n"
	.string "A title well deserved.$"
