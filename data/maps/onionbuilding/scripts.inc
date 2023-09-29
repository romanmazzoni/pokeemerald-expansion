onionbuilding_MapScripts::
	.byte 0

onionbuilding_eventScript_getAFreeLegendary::
	lockall
	showmonpic SPECIES_JIRACHI, 10, 3
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary_2
	hidemonpic
	msgbox NewProfessor_NotChosen
onionbuilding_eventScript_getAFreeLegendary_1:
	waitmessage
	releaseall
	end

onionbuilding_eventScript_getAFreeLegendary_2:
	givemon SPECIES_JIRACHI, 50, ITEM_MASTER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary_6
	hidemonpic
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_2
	goto onionbuilding_eventScript_getAFreeLegendary_1

onionbuilding_eventScript_getAFreeLegendary_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknamePartyMon
	goto onionbuilding_eventScript_getAFreeLegendary_1

onionbuilding_eventScript_getAFreeLegendary_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknameBoxMon
	goto onionbuilding_eventScript_getAFreeLegendary_1


onionbuilding_eventScript_getAFreeLegendary2::
	lockall
	showmonpic SPECIES_CELEBI, 10, 3
	msgbox onionbuilding_eventScript_getAFreeLegendary2_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary2_2
	hidemonpic
	msgbox NewProfessor_NotChosen
onionbuilding_eventScript_getAFreeLegendary2_1:
	waitmessage
	releaseall
	end

onionbuilding_eventScript_getAFreeLegendary2_2:
	givemon SPECIES_CELEBI, 50, ITEM_MASTER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary2_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary2_6
	hidemonpic
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_2
	goto onionbuilding_eventScript_getAFreeLegendary2_1

onionbuilding_eventScript_getAFreeLegendary2_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary2_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknamePartyMon
	goto onionbuilding_eventScript_getAFreeLegendary2_1

onionbuilding_eventScript_getAFreeLegendary2_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary2_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknameBoxMon
	goto onionbuilding_eventScript_getAFreeLegendary2_1


onionbuilding_eventScript_getAFreeLegendary3::
	lockall
	showmonpic SPECIES_VICTINI, 10, 3
	msgbox onionbuilding_eventScript_getAFreeLegendary3_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary3_2
	hidemonpic
	msgbox NewProfessor_NotChosen
onionbuilding_eventScript_getAFreeLegendary3_1:
	waitmessage
	releaseall
	end

onionbuilding_eventScript_getAFreeLegendary3_2:
	givemon SPECIES_VICTINI, 50, ITEM_MASTER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary3_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq onionbuilding_eventScript_getAFreeLegendary3_6
	hidemonpic
	msgbox onionbuilding_eventScript_getAFreeLegendary_Text_2
	goto onionbuilding_eventScript_getAFreeLegendary3_1

onionbuilding_eventScript_getAFreeLegendary3_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary3_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknamePartyMon
	goto onionbuilding_eventScript_getAFreeLegendary3_1

onionbuilding_eventScript_getAFreeLegendary3_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox onionbuilding_eventScript_getAFreeLegendary3_Text_1
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_TAKESTARTINGLEGENDARY
	call NicknameBoxMon
	goto onionbuilding_eventScript_getAFreeLegendary3_1


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


onionbuilding_eventscrpt_guytalking::
	lockall
	msgbox onionbuilding_eventscrpt_guytalking_Text_0
	releaseall
	return


onionbuilding_eventScript_getAFreeLegendary_Text_0:
	.string "Do you want to choose Jirachi?$"

onionbuilding_eventScript_getAFreeLegendary_Text_1:
	.string "Recieved Jirachi$"

onionbuilding_eventScript_getAFreeLegendary_Text_2:
	.string "No More Room$"

onionbuilding_eventScript_getAFreeLegendary2_Text_0:
	.string "Do you want to choose Celebi?$"

onionbuilding_eventScript_getAFreeLegendary2_Text_1:
	.string "Recieved Celebi$"

onionbuilding_eventScript_getAFreeLegendary3_Text_0:
	.string "Do you want to choose Victini?$"

onionbuilding_eventScript_getAFreeLegendary3_Text_1:
	.string "Recieved Victini$"

NicknamePartyMon_Text_0:
	.string "Give it a nickname?$"

onionbuilding_eventscrpt_guytalking_Text_0:
	.string "Yeah you want a free legendary? im\n"
	.string "mostly here for a test. look at how long\l"
	.string "i can talk for isnt this awesome?????$"

NewProfessor_NotChosen::
	.string "You did not choose the Pokemon$"
