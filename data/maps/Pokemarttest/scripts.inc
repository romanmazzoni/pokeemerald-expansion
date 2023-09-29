Pokemarttest_MapScripts::
	.byte 0


Littleroot_Mart_Employee::
	lock
	faceplayer
	message Littleroot_Mart_Employee_Text_0
	waitmessage
	pokemart MyMartItems
	msgbox Littleroot_Mart_Employee_Text_1
	release
	end


	.align 2
MyMartItems:
	.2byte ITEM_BLUE_ORB
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_NONE

Littleroot_Mart_Employee_Text_0:
	.string "How may I serve you?$"

Littleroot_Mart_Employee_Text_1:
	.string "Please Come Again.$"
