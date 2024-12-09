BattleFrontier_OutsideNew_MapScripts::
	.byte 0

newBattleRoute_EventScript_Frank::
	trainerbattle_single TRAINER_FRANK, Route107_Text_FrankIntro, Route107_Text_FrankDefeated
	msgbox Route107_Text_FrankPostBattle, MSGBOX_AUTOCLOSE
	end

newBattleRoute_EventScript_Frank2::
	trainerbattle_single TRAINER_FRANK2, Route107_Text_Frank2Intro, Route107_Text_Frank2Defeated
	msgbox Route107_Text_Frank2PostBattle, MSGBOX_AUTOCLOSE
	end

newBattleRoute_EventScript_Frank3::
	trainerbattle_single TRAINER_FRANK3, Route107_Text_Frank3Intro, Route107_Text_Frank3Defeated
	msgbox Route107_Text_Frank3PostBattle, MSGBOX_AUTOCLOSE
	end

newBattleRoute_EventScript_Frank4::
	trainerbattle_single TRAINER_FRANK4, Route107_Text_Frank4Intro, Route107_Text_Frank4Defeated
	msgbox Route107_Text_Frank4PostBattle, MSGBOX_AUTOCLOSE
	end

newBattleRoute_EventScript_Frank5::
	trainerbattle_single TRAINER_FRANK5, Route107_Text_Frank5Intro, Route107_Text_Frank5Defeated
	msgbox Route107_Text_Frank5PostBattle, MSGBOX_AUTOCLOSE
	end

newBattleRoute_EventScript_Frank6::
	trainerbattle_single TRAINER_FRANK6, Route107_Text_Frank6Intro, Route107_Text_Frank6Defeated
	msgbox Route107_Text_Frank6PostBattle, MSGBOX_AUTOCLOSE
	end

NewBattleFrontierRoute_EventScript_ItemMasterBall::
	finditem ITEM_MASTER_BALL
	end

NewBattleFrontierRoute_EventScript_ItemHeartScale::
	finditem ITEM_HEART_SCALE
	end

NewBattleFrontierRoute_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

NewBattleFrontierRoute_EventScript_ItemChoiceSpecs::
	finditem ITEM_CHOICE_SPECS
	end

NewBattleFrontierRoute_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

NewBattleFrontierRoute_EventScript_ItemWideLens::
	finditem ITEM_WIDE_LENS
	end

NewBattleFrontierRoute_EventScript_ItemDuskStone::
	finditem ITEM_DUSK_STONE
	end


NewBattleFrontierRoute_Text_HouseSign::
	.string "The Pokemon breeder House.$"

Route107_Text_FrankIntro::
	.string "Hey guys its me Frank.$"

Route107_Text_FrankDefeated::
	.string "Needed more focus band procs.$"

Route107_Text_FrankPostBattle::
	.string "Oh! This was a POKEMON battle...$"

Route107_Text_Frank2Intro::
	.string "Wanna play some spies vs mercs?$"

Route107_Text_Frank2Defeated::
	.string "I should've installed counter\n"
	.string "strike source...$"

Route107_Text_Frank2PostBattle::
	.string "I beat kingdom hearts on impoppable.\n"
	.string "I don't need this.$"

Route107_Text_Frank3Intro::
	.string "Hey guys it's me Jeff Lynne.\n"
	.string "Go listen to my new song:\l"
	.string "Electrical light orchestra.$"

Route107_Text_Frank3Defeated::
	.string "Now my old world is gone for dead.$"

Route107_Text_Frank3PostBattle::
	.string "They don't envy me, yeah...$"

Route107_Text_Frank4Intro::
	.string "UHUHUuu...\n"
	.string "Do not panic!$"

Route107_Text_Frank4Defeated::
	.string "Thats funny man. Good job.$"

Route107_Text_Frank4PostBattle::
	.string "It's all ogre now.$"

Route107_Text_Frank5Intro::
	.string "Choose these pokemon but they're all\n"
	.string "rotisserie chickens or some dumb\l"
	.string "thing like that.$"

Route107_Text_Frank5Defeated::
	.string "The final countdown...$"

Route107_Text_Frank5PostBattle::
	.string "Losses no longer affect me.$"

Route107_Text_Frank6Intro::
	.string "There is no way dude??\n"
	.string "A battle??$"

Route107_Text_Frank6Defeated::
	.string "Wow! That was the CRAZIEST battle\n"
	.string "we have ever done.$"

Route107_Text_Frank6PostBattle::
	.string "I am a father.$"

Route107_Text_MaxieTime::
	.string "Oh hey there {PLAYER}!\n"
	.string "I knew you would show up here!\p"
	.string "I went to the strongest place that\n"
	.string "I know of.\p"
	.string "I did a bit more research\n"
	.string "and it turns out, the orbs are\l"
	.string "just held items.\p"
	.string "Anyway, I've been waiting around\n"
	.string "here cause y'know, if anyone should\l"
	.string "get the orbs, it should be you!\p"
	.string "However!\p"
	.string "I can't just give them to you...\p"
	.string "I mean I would...\p"
	.string "But wouldn't a battle be more fun?$"

NewBattleFrontierRoute_EventScript_MaxieEnters::
	lockall
	applymovement 15, MyMovement
	waitmovement 15
	face_up
	msgbox Route107_Text_MaxieTime
	trainerbattle_no_intro TRAINER_FRANK7, NewBattleFrontierRoute_EventScript_MaxieEnters_Text_0
	setflag FLAG_NewMaxieFlag
	msgbox NewBattleFrontierRoute_EventScript_MaxieEnters_Text_1
	giveitem ITEM_RED_ORB
	giveitem ITEM_BLUE_ORB
	msgbox NewBattleFrontierRoute_EventScript_MaxieEnters_Text_2
	applymovement 15, Maxiemove2
	waitmovement 15
	removeobject 15
	setvar VAR_NewMaxieVar, 1
	releaseall
	return


MyMovement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Maxiemove2:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewBattleFrontierRoute_EventScript_Memorycaveguy::
	lockall
	msgbox NewBattleFrontierRoute_EventScript_Memorycaveguy_Text_0
	releaseall
	return


NewBattleFrontierRoute_EventScript_Memorycaveguy2::
	lockall
	msgbox NewBattleFrontierRoute_EventScript_Memorycaveguy2_Text_0
	releaseall
	return


NewBattleFrontierRoute_EventScript_Memorycaveguy3::
	lockall
	msgbox NewBattleFrontierRoute_EventScript_Memorycaveguy3_Text_0
	releaseall
	return


NewBattleFrontierRoute_EventScript_MaxieEnters_Text_0:
	.string "Well, you earned it!$"

NewBattleFrontierRoute_EventScript_MaxieEnters_Text_1:
	.string "Don't tell anyone I stole these back.\n"
	.string "They still think they gots the real\l"
	.string "ones up there.$"

NewBattleFrontierRoute_EventScript_MaxieEnters_Text_2:
	.string "Whelp, I'm off.$"

NewBattleFrontierRoute_EventScript_Memorycaveguy_Text_0:
	.string "This cave seems familiar.\p"
	.string "It seems to have pokemon that I\n"
	.string "previous missed out on catching!$"

NewBattleFrontierRoute_EventScript_Memorycaveguy2_Text_0:
	.string "I remember this place...$"

NewBattleFrontierRoute_EventScript_Memorycaveguy3_Text_0:
	.string "I took all the fossils. Too slow chump!$"