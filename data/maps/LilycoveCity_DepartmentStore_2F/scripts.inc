LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
	.string "Learn to use items properly.\n"
	.string "That's basic, really.$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
	.string "My husband is waiting at home.\n"
	.string "What would make a good gift for him?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
	.string "I'm leaving on a long journey soon.\n"
	.string "I need to stock up on items.$"

LillyCove_2ndfloor_CustomShop_Intro::
	lock
	faceplayer
	message LillyCove_2ndfloor_CustomShop_Intro_Text_0
	waitmessage
	pokemart ChocoMart2
	msgbox LillyCove_2ndfloor_CustomShop_Intro_Text_1
	release
	end


	.align 2
ChocoMart2:
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_LOADED_DICE
	.2byte ITEM_COVERT_CLOAK
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_SCROLL_OF_DARKNESS
	.2byte ITEM_SCROLL_OF_WATERS
	.2byte ITEM_NONE

	.align 2
ChocoMartIncense:
	.2byte ITEM_FULL_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_ODD_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_WAVE_INCENSE
	.2byte ITEM_NONE

ChocoScript_Incense_Seller::
	lock
	faceplayer
	message ChocoScript_Incense_Seller_Text_0
	waitmessage
	pokemart ChocoMartIncense
	msgbox LillyCove_2ndfloor_CustomShop_Intro_Text_1
	release
	end


ChocoScript_I_Love_Balls::
	lock
	faceplayer
	message ChocoScript_I_Love_Balls_Text_0
	waitmessage
	pokemart ChocoMartBalls
	msgbox LillyCove_2ndfloor_CustomShop_Intro_Text_1
	release
	end


	.align 2
ChocoMartBalls:
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FAST_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_CHERISH_BALL
	.2byte ITEM_IRON_BALL
	.2byte ITEM_NONE

LillyCove_2ndfloor_CustomShop_Intro_Text_0:
	.string "The circus of value!$"

LillyCove_2ndfloor_CustomShop_Intro_Text_1:
	.string "Please Come Again.$"

ChocoScript_Incense_Seller_Text_0:
	.string "Wanna make some babies?$"

ChocoScript_I_Love_Balls_Text_0:
	.string "I love balls!$"
