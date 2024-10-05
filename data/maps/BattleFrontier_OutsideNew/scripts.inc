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

NewBattleFrontierRoute_Text_HouseSign::
	.string "The Pokemon breeder House.$"

Route107_Text_FrankIntro::
	.string "The Pokemon breeder House.$"

Route107_Text_FrankDefeated::
	.string "The Pokemon breeder House.$"

Route107_Text_FrankPostBattle::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank2Intro::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank2Defeated::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank2PostBattle::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank3Intro::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank3Defeated::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank3PostBattle::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank4Intro::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank4Defeated::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank4PostBattle::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank5Intro::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank5Defeated::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank5PostBattle::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank6Intro::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank6Defeated::
	.string "The Pokemon breeder House.$"

Route107_Text_Frank6PostBattle::
	.string "The Pokemon breeder House.$"