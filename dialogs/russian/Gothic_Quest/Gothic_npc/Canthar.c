// Кантар хитрый торговец
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	
	switch(Dialog.CurrentNode)
	{

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_TRADE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Покажи мне свои товары.";
		link.l1.go = "Canthar_Trade_1";
		break;

		case "Canthar_Trade_1":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_TRADE_09_01.wav");
		dialog.text = "Выбирай.";
		link.l1 = "...";
		link.l1.go = "Canthar_Trade_exit";

	                 if(CheckAttribute(pchar, "questTemp.GothicCanthar") && pchar.questTemp.GothicCanthar == "griddle" && !CheckAttribute(npchar, "quest.griddle"))
		{
		link.l1 = "У тебя есть в продаже сковородка?";
		link.l1.go = "Canthar_griddle";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicCanthar") && pchar.questTemp.GothicCanthar == "Canthar_20" && !CheckAttribute(npchar, "quest.Canthar_20"))
	       {
		if (GetCharacterItem(pchar, "gold_dublon") >= 20)
		{
		link.l1 = "Давай сюда сковородку.";
		link.l1.go = "Canthar_griddle_1";
		}
                              }

		break;

		case "Canthar_Trade_exit":
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LaunchItemsTrade(npchar, 0);
		break;


		case "Canthar_hallo":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_00.wav");
		dialog.text = "Посмотрите кто у нас здесь!";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_1";			
		break;

		case "Canthar_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_01.wav");
		dialog.text = "Ты ведь идёшь в город, я не прав?";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_2";			
		break;

		case "Canthar_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "Может быть.";
		link.l1.go = "Canthar_hallo_3";			
		break;

		case "Canthar_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_03.wav");
		dialog.text = "Хх...Ты похож на беглеца, все беглецы направляются в город.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_4";			
		break;

		case "Canthar_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_04.wav");
		dialog.text = "Возможно ты даже беглый каторжник из колонии.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_5";			
		break;

		case "Canthar_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_05.wav");
		dialog.text = "Меня не волнует от куда ты пришёл, но мне кажется у меня есть интересное предложение для тебя.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_6";			
		break;

		case "Canthar_hallo_6":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_PAYPRICEINCITY_15_02.wav");
		dialog.text = "...";
		link.l1 = "Что ты хочешь?";
		link.l1.go = "Canthar_hallo_7";			
		break;

		case "Canthar_hallo_7":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_01.wav");
		dialog.text = "Судя по тому как ты выглядишь, стража никогда не пустят тебя в город.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_8";			
		break;

		case "Canthar_hallo_8":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_02.wav");
		dialog.text = "Если ты будешь говорить так же убедительно со стражами у ворот как говоришь со мной, они никогда не пустят тебя в город.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_9";			
		break;

		case "Canthar_hallo_9":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_03.wav");
		dialog.text = "Я могу помочь попасть тебе в город.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_10";			
		break;

		case "Canthar_hallo_10":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_04.wav");
		dialog.text = "У меня есть вот этот клочок бумаги с королевской печатью и подписью губернатора, пропуск.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_11";			
		break;

		case "Canthar_hallo_11":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_05.wav");
		dialog.text = "С этим пропуском в кармане ты сможешь спокойно войти в город и стражам придётся пропустить тебя.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_12";			
		break;

		case "Canthar_hallo_12":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_06.wav");
		dialog.text = "Тебе это интересно?";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_13";			
		break;

		case "Canthar_hallo_13":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_HOWYOUIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "А как ты попадёшь в город!";
		link.l1.go = "Canthar_hallo_14";			
		break;

		case "Canthar_hallo_14":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_HOWYOUIN_09_01.wav");
		dialog.text = "Стражи знают меня, я им просто скажу, что потерял пропуск.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_15";			
		break;

		case "Canthar_hallo_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что ты хочешь за этот пропуск.";
		link.l1.go = "Canthar_hallo_16";			
		break;

		case "Canthar_hallo_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_01.wav");
		dialog.text = "Я знал, что не ошибся в тебе.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_17";			
		break;

		case "Canthar_hallo_17":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_02.wav");
		dialog.text = "Послушай, ты получишь от меня пропуск прямо сейчас.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_18";			
		break;

		case "Canthar_hallo_18":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_15_03.wav");
		dialog.text = "...";
		link.l1 = "Просто так!";
		link.l1.go = "Canthar_hallo_19";			
		break;

		case "Canthar_hallo_19":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_04.wav");
		dialog.text = "Да.. Но, если я тебя встречу в городе, ты будешь должен оказать мне услугу.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_20";			
		break;

		case "Canthar_hallo_20":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_05.wav");
		dialog.text = "Ну, что договорились.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_21";			
		break;

		case "Canthar_hallo_21":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_STRINGS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Это похоже на подвох!";
		link.l1.go = "Canthar_hallo_22";			
		break;

		case "Canthar_hallo_22":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_STRINGS_09_01.wav");
		dialog.text = "Нет, никакого подвоха, ты просто окажешь мне услугу.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_23";			
		break;

		case "Canthar_hallo_23":
		dialog.text = "...";
		link.l1 = "Нет, оставь эту бумагу себе.";
		link.l1.go = "Canthar_hallo_NO_15";
		link.l2 = "Конечно, давай сюда эту бумагу.";
		link.l2.go = "Canthar_hallo_OK_15";			
		break;
	
		case "Canthar_hallo_NO_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Нет, оставь эту бумагу себе.";
		link.l1.go = "Canthar_hallo_NO_16";			
		break;

		case "Canthar_hallo_NO_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_09_01.wav");
		dialog.text = "Хм, похоже я, не до оценил тебя.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_NO_17";			
		break;

		case "Canthar_hallo_NO_17":
                                         //pchar.questTemp.GothicCanthar = "griddle";
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_09_02.wav");
		dialog.text = "Ладно, тебе нужно, что - нибудь ещё, может показать тебе мои товары?";
		link.l1 = "...";
		link.l1.go = "First time";			
		break;				
	
		case "Canthar_hallo_OK_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_15_00.wav");
		dialog.text = "...";
		link.l1 = "Конечно, давай сюда эту бумагу.";
		link.l1.go = "Canthar_hallo_OK_16";			
		break;

		case "Canthar_hallo_OK_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_01.wav");
		dialog.text = "Держи, но обращайся с ней аккуратно, она очень ценная.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_OK_17";			
		break;

		case "Canthar_hallo_OK_17":
		GiveItem2Character(pchar, "VerifyPaper");
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_02.wav");
		dialog.text = "И ещё одно, да же и не думай нарушить своё слово.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_OK_18";			
		break;

		case "Canthar_hallo_OK_18":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_03.wav");
		dialog.text = "Я торговец и имею очень большое влияние в городе просто так тебе это с рук не сойдёт, уж поверь мне.";
		link.l1 = "...";
		link.l1.go = "exit";			
		break;					



       		case "Canthar_griddle":
		dialog.text = "Да, у меня много чего есть и сковородка в том числе.";
		link.l1 = "Назови цену.";
		link.l1.go = "Canthar_griddle_1";
		break;

       		case "Canthar_griddle_1":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_9_GOLD_20.wav");
		dialog.text = "20 золотых монет.";
		if (GetCharacterItem(pchar, "gold_dublon") >= 20)
		{
		link.l1 = "Хорошо, вот тебе 20 дублонов... Давай сюда сковородку.";
		link.l1.go = "guess_04";
		}
		else
		{
		link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
		link.l1.go = "exit_gold_1";
		}
		break;

		case "exit_gold_1":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня недостаточно золота...";
		link.l1 = "...";
		link.l1.go = "exit_no_gold_20";
		break;

		case "Exit_no_gold_20":
		npchar.quest.griddle = "true";
                                          pchar.questTemp.GothicCanthar = "Canthar_20";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;  

		case "guess_04":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "...";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "guess_05";
		break;

		case "guess_05":
		GiveItem2Character(pchar, "griddle");
		Log_Info("Вы получили сковородку");
		PlaySound("interface\important_item.wav");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 20);
		dialog.text = "...";
		link.l1 = "...";
		link.l1.go = "exit_5";
		break;

		case "Exit_5":
		npchar.quest.Canthar_20 = "true";
		npchar.quest.griddle = "true";
                                          pchar.questTemp.GothicHilda_griddle.over = "griddle";	
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		SetFunctionTimerCondition("Hilda_griddle_Remove", 0, 0, 1, false);
		break;  












//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Что ты там копаешься, а? Да ты вор!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой!", "По сундукам шарить вздумал?! Тебе это даром не пройдет!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Ах, вот, значит, как?! По сундукам шарить вздумал?! Тебе это даром не пройдет!";
			link.l1 = "Вот дура!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//замечание по обнаженному оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Слушай, ты бы убрал оружие. А то нервируешь немного...", "Знаешь, у нас тут не принято сабелькой размахивать. Убери оружие.", "Слушай, что ты, как д'Артаньян, бегаешь тут, шпагой машешь? Убери оружие, не к лицу это серьезному мужчине...");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажешь...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
				link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "Осторожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции	

	}
}
