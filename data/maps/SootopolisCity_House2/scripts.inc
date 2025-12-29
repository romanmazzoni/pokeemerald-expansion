SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "At its peak are two orbs placed side\n"
	.string "by side. You can use them for\l"
	.string "primal forms?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Yes, two orbs side by side…\p"
	.string "The sight of them together…\n"
	.string "So stealable…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Is that right?\n"
	.string "Perhaps you ought to visit and see…$"
