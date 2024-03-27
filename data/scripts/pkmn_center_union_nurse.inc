Common_EventScript_PkmnCenterUnionNurse::
	lock
	faceplayer
	message Common_EventScript_PkmnCenterUnionNurse_Text_0
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	release
	end


EventScript_PkmnCenterUnionNurse_Multichoice::
	message EventScript_PkmnCenterUnionNurse_Multichoice_Text_0
	waitmessage
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, EventScript_PkmnCenterUnionNurse_Multichoice_Text_1, EventScript_PkmnCenterUnionNurse_Multichoice_Text_2, EventScript_PkmnCenterUnionNurse_Multichoice_Text_3, EventScript_PkmnCenterUnionNurse_Multichoice_Text_4
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterUnionNurse_Multichoice_2
	case 1, EventScript_PkmnCenterUnionNurse_Multichoice_3
	case 2, EventScript_PkmnCenterUnionNurse_Multichoice_4
	return

EventScript_PkmnCenterUnionNurse_Multichoice_2:
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_3:
	call EventScript_PkmnCenterUnionNurse_ChangeNickname
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return

EventScript_PkmnCenterUnionNurse_Multichoice_4:
	call EventScript_PkmnCenterUnionNurse_ChangeNature
	message PkmnCenterUnionNurse_AnythingElse
	waitmessage
	call EventScript_PkmnCenterUnionNurse_Multichoice
	return


EventScript_PkmnCenterUnionNurse_MoveRelearn::
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_2
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_4
	compare VAR_0x8005, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_5
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq EventScript_PkmnCenterUnionNurse_MoveRelearn_9
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_2:
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_4:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_5:
	msgbox EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1
	call EventScript_PkmnCenterUnionNurse_MoveRelearn
	return

EventScript_PkmnCenterUnionNurse_MoveRelearn_9:
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
	compare VAR_RESULT, NO
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
	dynmultipush EventScript_PkmnCenterUnionNurse_Multichoice_Text_4, MULTI_B_PRESSED
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
	release
	end

EventScript_PkmnCenterUnionNurse_ChangeNature_2:
	goto EventScript_PkmnCenterUnionNurse_Multichoice
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
	dynmultistack 0, 0, FALSE, 4, FALSE, 0xFF, DYN_MULTICHOICE_CB_NONE
	settimeofday VAR_RESULT
	release
	end


Common_EventScript_PkmnCenterUnionNurse_Text_0:
	.string "Hi, I'm the Pokéhelper!$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_0:
	.string "How may I help you today?$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_1:
	.string "Relearn move$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_2:
	.string "Change nickname$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_3:
	.string "Change Nature$"

EventScript_PkmnCenterUnionNurse_Multichoice_Text_4:
	.string "Cancel$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_0:
	.string "There are no moves available to teach\n"
	.string "to an Egg.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_1:
	.string "Unfortunately, there are no moves\n"
	.string "available for that Pokémon.$"

EventScript_PkmnCenterUnionNurse_MoveRelearn_Text_2:
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

PkmnCenterUnionNurse_AnythingElse::
	.string "Is there anything else I can help you\n"
	.string "with today?$"
