Common_EventScript_PkmnCenterUnionNurse::
	lock
	faceplayer
	message Common_EventScript_PkmnCenterUnionNurse_Text_0
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	release
	end


EventScript_PkmnCenterUnionNurse_Multichoice::
	checktrainerflag TRAINER_BRAWLY_1
	goto_if 0, EventScript_PkmnCenterUnionNurse_Multichoice_1
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, EventScript_PkmnCenterUnionNurse_Multichoice_Text_0, EventScript_PkmnCenterUnionNurse_Multichoice_Text_5, EventScript_PkmnCenterUnionNurse_Multichoice_Text_2, EventScript_PkmnCenterUnionNurse_Multichoice_Text_3
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterUnionNurse_Multichoice_10
	case 1, EventScript_PkmnCenterUnionNurse_Multichoice_11
	case 2, EventScript_PkmnCenterUnionNurse_Multichoice_12
	return

EventScript_PkmnCenterUnionNurse_Multichoice_1:
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, EventScript_PkmnCenterUnionNurse_Multichoice_Text_0, EventScript_PkmnCenterUnionNurse_Multichoice_Text_1, EventScript_PkmnCenterUnionNurse_Multichoice_Text_2, EventScript_PkmnCenterUnionNurse_Multichoice_Text_3
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterUnionNurse_Multichoice_5
	case 1, EventScript_PkmnCenterUnionNurse_Multichoice_6
	case 2, EventScript_PkmnCenterUnionNurse_Multichoice_7
	return

EventScript_PkmnCenterUnionNurse_Multichoice_5:
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_6:
	msgbox EventScript_PkmnCenterUnionNurse_Multichoice_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterUnionNurse
	return

EventScript_PkmnCenterUnionNurse_Multichoice_7:
	call EventScript_PkmnCenterUnionNurse_ChangeNature
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_10:
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_11:
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_12:
	call EventScript_PkmnCenterUnionNurse_ChangeNature
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return


EventScript_PkmnCenterUnionNurse_MoveRelearn::
	checktrainerflag TRAINER_BRAWLY_1
	goto_if 1, EventScript_PkmnCenterUnionNurse_MoveRelearn_2
EventScript_PkmnCenterUnionNurse_MoveRelearn_1:
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_5
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_9
	compare VAR_0x8005, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_10
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_14
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_3
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_2:
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_7
	goto EventScript_PkmnCenterUnionNurse_MoveRelearn_1

EventScript_PkmnCenterUnionNurse_MoveRelearn_5:
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_7:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterUnionNurse
	goto EventScript_PkmnCenterUnionNurse_MoveRelearn_1

EventScript_PkmnCenterUnionNurse_MoveRelearn_9:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_10:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_14:
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return


EventScript_PkmnCenterUnionNurse_ChangeNickname::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_4
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNickname_8
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_2
EventScript_PkmnCenterUnionNurse_ChangeNickname_7:
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_2:
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_4:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_0
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	return

EventScript_PkmnCenterUnionNurse_ChangeNickname_8:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_1
	goto EventScript_PkmnCenterUnionNurse_ChangeNickname_7


EventScript_PkmnCenterUnionNurse_ChangeNature::
	lock
	faceplayer
	checkitem ITEM_HEART_SCALE
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNature_2
EventScript_PkmnCenterUnionNurse_ChangeNature_1:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_0
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNature_5
EventScript_PkmnCenterUnionNurse_ChangeNature_4:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNature_8
	special BufferMonNickname
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_2
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_3, NATURE_HARDY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_4, NATURE_LONELY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_5, NATURE_BRAVE
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_6, NATURE_ADAMANT
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_7, NATURE_NAUGHTY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_8, NATURE_BOLD
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_9, NATURE_DOCILE
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_10, NATURE_RELAXED
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_11, NATURE_IMPISH
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_12, NATURE_LAX
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_13, NATURE_TIMID
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_14, NATURE_HASTY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_15, NATURE_SERIOUS
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_16, NATURE_JOLLY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_17, NATURE_NAIVE
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_18, NATURE_MODEST
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_19, NATURE_MILD
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_20, NATURE_QUIET
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_21, NATURE_BASHFUL
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_22, NATURE_RASH
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_23, NATURE_CALM
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_24, NATURE_GENTLE
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_25, NATURE_SASSY
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_26, NATURE_CAREFUL
	dynmultipush EventScript_PkmnCenterUnionNurse_ChangeNature_Text_27, NATURE_QUIRKY
	dynmultipush EventScript_PkmnCenterUnionNurse_Multichoice_Text_3, MULTI_B_PRESSED
	dynmultistack 0, 0, TRUE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNature_11
EventScript_PkmnCenterUnionNurse_ChangeNature_10:
	copyvar VAR_0x8005, VAR_RESULT
	buffernaturename STR_VAR_2, VAR_RESULT
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_28, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_PkmnCenterUnionNurse_ChangeNature_14
EventScript_PkmnCenterUnionNurse_ChangeNature_13:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_29
	fadescreen FADE_TO_BLACK
	special ChangeMonNature
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_30
	removeitem ITEM_HEART_SCALE, 1
	release
	end

EventScript_PkmnCenterUnionNurse_ChangeNature_2:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterUnionNurse
	goto EventScript_PkmnCenterUnionNurse_ChangeNature_1

EventScript_PkmnCenterUnionNurse_ChangeNature_5:
	goto EventScript_PkmnCenterUnionNurse_Multichoice
	goto EventScript_PkmnCenterUnionNurse_ChangeNature_4

EventScript_PkmnCenterUnionNurse_ChangeNature_8:
	msgbox EventScript_PkmnCenterUnionNurse_ChangeNature_Text_1
	release
	end

EventScript_PkmnCenterUnionNurse_ChangeNature_11:
	goto EventScript_PkmnCenterUnionNurse_Multichoice
	goto EventScript_PkmnCenterUnionNurse_ChangeNature_10

EventScript_PkmnCenterUnionNurse_ChangeNature_14:
	goto EventScript_PkmnCenterUnionNurse_Multichoice
	goto EventScript_PkmnCenterUnionNurse_ChangeNature_13


EventScript_AccessTimeChanger::
	lock
	dynmultipush EventScript_AccessTimeChanger_Text_0, TIME_DAY
	dynmultipush EventScript_AccessTimeChanger_Text_1, TIME_EVENING
	dynmultipush EventScript_AccessTimeChanger_Text_2, TIME_NIGHT
	dynmultistack 0, 0, FALSE, 3, FALSE, 0xFF, DYN_MULTICHOICE_CB_NONE
	settimeofday VAR_RESULT
	release
	end


EventScript_AccessAbilityChanger::
	lock
	faceplayer
	msgbox EventScript_AccessAbilityChanger_Text_0
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_AccessAbilityChanger_2
EventScript_AccessAbilityChanger_1:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq EventScript_AccessAbilityChanger_5
EventScript_AccessAbilityChanger_4:
	special BufferMonNickname
	special BufferMonAbilities
	msgbox EventScript_AccessAbilityChanger_Text_2
	compare VAR_0x8006, ABILITY_NONE
	goto_if_ne EventScript_AccessAbilityChanger_8
EventScript_AccessAbilityChanger_7:
	compare VAR_0x8007, ABILITY_NONE
	goto_if_ne EventScript_AccessAbilityChanger_11
EventScript_AccessAbilityChanger_10:
	compare VAR_0x8008, ABILITY_NONE
	goto_if_ne EventScript_AccessAbilityChanger_14
EventScript_AccessAbilityChanger_13:
	dynmultistack 0, 0, TRUE, 3, FALSE, 0xFF, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, ABILITY_NONE
	goto_if_eq EventScript_AccessAbilityChanger_17
	switch VAR_RESULT
	case VAR_0x8006, EventScript_AccessAbilityChanger_21
	case VAR_0x8007, EventScript_AccessAbilityChanger_22
	case VAR_0x8008, EventScript_AccessAbilityChanger_23
EventScript_AccessAbilityChanger_19:
	bufferabilityname STR_VAR_2, VAR_RESULT
	msgbox EventScript_AccessAbilityChanger_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_AccessAbilityChanger_25
	special ChangeMonAbility
	msgbox EventScript_AccessAbilityChanger_Text_5
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	release
	end

EventScript_AccessAbilityChanger_2:
	goto EventScript_AccessAbilityChanger
	goto EventScript_AccessAbilityChanger_1

EventScript_AccessAbilityChanger_5:
	msgbox EventScript_AccessAbilityChanger_Text_1
	goto EventScript_AccessAbilityChanger
	goto EventScript_AccessAbilityChanger_4

EventScript_AccessAbilityChanger_8:
	bufferabilityname STR_VAR_2, VAR_0x8006
	dynmultipush EventScript_AccessAbilityChanger_Text_3, VAR_0x8006
	goto EventScript_AccessAbilityChanger_7

EventScript_AccessAbilityChanger_11:
	bufferabilityname STR_VAR_2, VAR_0x8007
	dynmultipush EventScript_AccessAbilityChanger_Text_3, VAR_0x8007
	goto EventScript_AccessAbilityChanger_10

EventScript_AccessAbilityChanger_14:
	bufferabilityname STR_VAR_2, VAR_0x8008
	dynmultipush EventScript_AccessAbilityChanger_Text_3, VAR_0x8008
	goto EventScript_AccessAbilityChanger_13

EventScript_AccessAbilityChanger_17:
	end

EventScript_AccessAbilityChanger_21:
	setvar VAR_0x8009, 0
	goto EventScript_AccessAbilityChanger_19

EventScript_AccessAbilityChanger_22:
	setvar VAR_0x8009, 1
	goto EventScript_AccessAbilityChanger_19

EventScript_AccessAbilityChanger_23:
	setvar VAR_0x8009, 2
	goto EventScript_AccessAbilityChanger_19

EventScript_AccessAbilityChanger_25:
	end


Common_EventScript_PkmnCenterUnionNurse_Text_0:
	.string "Hi, I'm the Pokéhelper! and How may I\n"
	.string "help you today?$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_0:
	.string "Change nickname$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_1:
	.string "Relearn move {FIXED_CASE}{COLOR RED}LOCKED$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_2:
	.string "Change Nature$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_3:
	.string "Cancel$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_4:
	.string "You'll have to defeat Brawly first\n"
	.string "before using this Feature!$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_5:
	.string "Relearn move$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0:
	.string "sorry but to use this Feature you'll\n"
	.string "need to show me a heartscale.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1:
	.string "There are no moves available to teach\n"
	.string "to an Egg.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2:
	.string "Unfortunately, there are no moves\n"
	.string "available for that Pokémon.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_3:
	.string "Thank you for using the Move Relearner!$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_0:
	.string "You cannot nickname an Egg.$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_1:
	.string "From now on, this Pokémon will be known\n"
	.string "as {STR_VAR_1}.$"

EventScript_PkmnCenterUnionNurse_ChangeNickname_Text_2:
	.string "The Pokémon's name will remain\n"
	.string "unchanged.$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_0:
	.string "Which Pokémon should I train?$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_1:
	.string "How foolish! An Egg cannot train!$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_2:
	.string "Which new Nature suits {STR_VAR_1}\n"
	.string "best?$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_3:
	.string "Hardy$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_4:
	.string "Lonely$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_5:
	.string "Brave$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_6:
	.string "Adamant$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_7:
	.string "Naughty$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_8:
	.string "Bold$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_9:
	.string "Docile$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_10:
	.string "Relaxed$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_11:
	.string "Impish$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_12:
	.string "Lax$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_13:
	.string "Timid$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_14:
	.string "Hasty$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_15:
	.string "Serious$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_16:
	.string "Jolly$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_17:
	.string "Naive$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_18:
	.string "Modest$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_19:
	.string "Mild$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_20:
	.string "Quiet$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_21:
	.string "Bashful$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_22:
	.string "Rash$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_23:
	.string "Calm$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_24:
	.string "Gentle$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_25:
	.string "Sassy$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_26:
	.string "Careful$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_27:
	.string "Quirky$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_28:
	.string "So {STR_VAR_1} should acquire the\n"
	.string "{STR_VAR_2} Nature?$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_29:
	.string "Excellent. We shall begin at once!$"

EventScript_PkmnCenterUnionNurse_ChangeNature_Text_30:
	.string "{STR_VAR_1}'s training is complete.\p"
	.string "Come back if you need to train another\n"
	.string "Pokémon.$"

EventScript_AccessTimeChanger_Text_0:
	.string "Day$"

EventScript_AccessTimeChanger_Text_1:
	.string "Night$"

EventScript_AccessTimeChanger_Text_2:
	.string "Dusk$"

EventScript_AccessAbilityChanger_Text_0:
	.string "Wich Pokemon Would like to have its\n"
	.string "ability changed?$"

EventScript_AccessAbilityChanger_Text_1:
	.string "An egg doesn't have abilities.$"

EventScript_AccessAbilityChanger_Text_2:
	.string "Which Ability should {STR_VAR_1}\n"
	.string "learn?$"

EventScript_AccessAbilityChanger_Text_3:
	.string "{STR_VAR_2}$"

EventScript_AccessAbilityChanger_Text_4:
	.string "So {STR_VAR_1} should learn the\n"
	.string "{STR_VAR_2} Ability?$"

EventScript_AccessAbilityChanger_Text_5:
	.string "{STR_VAR_1}'s Ability is changed!$"

PkmnCenterUnionNurse_AnythingElse::
	.string "Is there anything else I can help you\n"
	.string "with today?$"
