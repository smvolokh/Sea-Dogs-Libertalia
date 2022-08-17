// Хильда, жена Лобарта фермера
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

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_HALLO_17_00.wav");
		dialog.text = "Эй, тебя сюда звали, немедленно убирайся из моего дома, здесь не подают милостыню.";
		link.l1 = "...";
		link.l1.go = "First time_1";

	                 if(CheckAttribute(pchar, "questTemp.GothicHildaturnip") && pchar.questTemp.GothicHildaturnip == "turnip" && !CheckAttribute(npchar, "quest.turnip"))
		{
		link.l1 = "Я принёс тебе репу.";
		link.l1.go = "Hilda_turnip";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicHilda_griddle.over") && pchar.questTemp.GothicHilda_griddle.over == "griddle" && !CheckAttribute(npchar, "quest.griddle"))
		{
		link.l1 = "Вот твоя сковородка.";
		link.l1.go = "Hilda_griddle";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicHilda_griddleLate") && pchar.questTemp.GothicHilda_griddleLate == "griddleLate" && !CheckAttribute(npchar, "quest.griddleLate"))
		{
		link.l1 = "...";
		link.l1.go = "Hilda_griddleLate";
		}

		break;

		case "First time_1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_WASZUESSEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты дашь мне что-нибудь поесть!";
		link.l1.go = "First time_2";
		break;

		case "First time_2":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_WASZUESSEN_17_04.wav");
		dialog.text = "Мы  не собираемся кормить всяких лодырей, убирайся.";
		link.l1 = "...";
		link.l1.go = "exit";
		break;

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;


		case "Hilda_Trade":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_TRADE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Покажи мне свои товары.";
		link.l1.go = "Hilda_Trade_1";
		break;

		case "Hilda_Trade_1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_TRADE_16_01.wav");
		dialog.text = "Выбирай.";
		link.l1 = "...";
		link.l1.go = "Hilda_Trade_exit";
		break;

		case "Hilda_Trade_exit":
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LaunchItemsTrade(npchar, 0);
		break;


		case "Hilda":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_HALLO_17_00.wav");
		dialog.text = "Эй, тебя сюда звали, немедленно убирайся из моего дома, здесь не подают милостыню.";
		link.l1 = "...";
		link.l1.go = "exit";
		break;

		case "Hilda_Morework_1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_BRINGBEET_17_02.wav");
		dialog.text = "Раз уж ты всё равно здесь я видела как мимо прошёл странствующий торговец, это было несколько минут назад.";
		link.l1 = "...";
		link.l1.go = "Hilda_Morework_2";
		break;

		case "Hilda_Morework_2":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_BRINGBEET_17_03.wav");
		dialog.text = "Я думаю он где - нибудь остановился по пути в город, сходи к нему, может у него найдётся сковородка для меня.";
		link.l1 = "...";
		link.l1.go = "Hilda_Morework_3";
		break;

		case "Hilda_Morework_3":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_EINKAUFEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Дай мне золото, я схожу к этому торговцу для тебя.";
		link.l1.go = "Hilda_Morework_4";
		break;

		case "Hilda_Morework_4":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_EINKAUFEN_17_01.wav");
		dialog.text = "А тебе можно доверять! Только попробуй потратить эти деньги на выпивку, слышишь...";
		link.l1 = "...";
		link.l1.go = "exit_griddle";
		break;

		case "Exit_griddle":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 20);
		Log_Info("Вы получили 20 дублонов");
		npchar.quest.Morework = "true";
		npchar.quest.turnip = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
                                          pchar.questTemp.GothicCanthar = "griddle";
		break;


		case "Hilda_griddle":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNEGEHOLT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Вот твоя сковородка.";
		link.l1.go = "Hilda_griddle1";
		break;

		case "Hilda_griddle1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNEGEHOLT_17_01.wav");
		dialog.text = "Отлично, посмотрим, хорошая ли она!";
		link.l1 = "...";
		link.l1.go = "Hilda_griddle_1";
		break;

		case "Hilda_griddle_1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "griddle", -1);
		npchar.quest.griddle = "true";
		npchar.quest.griddleLate = "true";
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_WASZUESSEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты дашь мне, что - нибудь поесть?";
		link.l1.go = "Hilda_griddle_2";
		break;

		case "Hilda_griddle_2":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_WASZUESSEN_17_01.wav");
		dialog.text = "Вот возьми, ты хороший парень.";
		link.l1 = "...";
		link.l1.go = "Hilda_griddle_3";
		if (AddSPECIALValue(pchar, SPECIAL_C, 0) == SPECIAL_MAX)
		{
			    AddSPECIALValue(pchar, SPECIAL_C, 1);
		}
		break;

		case "Hilda_griddle_3":
		PlaySound("interface\important_item.wav");
		link.l1.go = "Hilda_griddle_4";
		break;

		case "Hilda_griddle_4":
		PlaySound("Ambient\Tavern\glotok_001.wav");
		dialog.text = "...";
		link.l1 = "Как вкусно!";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicHilda_PlusSkill_Charisma");
		break;

		case "Hilda_krank_helfen":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_KRANK_HELFEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Могу я чем - нибудь помочь!";
		link.l1.go = "Hilda_krank_helfen_1";
		break;

		case "Hilda_krank_helfen_1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_KRANK_HELFEN_17_01.wav");
		dialog.text = "Было бы великолепно если бы ты смог сходить к Ватрасу и принести лекарство от него.";
		link.l1 = "...";
		link.l1.go = "Hilda_krank_helfen_2";
		break;

		case "Hilda_krank_helfen_2":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_KRANK_HELFEN_17_02.wav");
		dialog.text = "Он знает, что мне нужно, самой мне не дойти.";
		link.l1 = "...";
		link.l1.go = "Hilda_krank_helfen_3";
		break;

		case "Hilda_krank_helfen_3":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_KRANK_BESSERUNG_15_00.wav");
		dialog.text = "...";
		link.l1 = "Поправляйся, а мне нужно идти.";
		link.l1.go = "Hilda_krank_helfen_4";
		break;

		case "Hilda_krank_helfen_4":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_KRANK_BESSERUNG_17_01.wav");
		dialog.text = "Остаётся надеяться, что вскоре мне станет лучше.";
		link.l1 = "...";
		link.l1.go = "exit";
                                          pchar.questTemp.GothicHilda_Frauhelen = "Frauhelen";
		break;

		case "Hilda_griddleLate":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_00.wav");
		dialog.text = "У тебя ещё хватает наглости появляться здесь! Что ты сделал с моими деньгами, ты бездельник...";
		link.l1 = "...";
		link.l1.go = "Hilda_griddleLate_1";
		break;

		case "Hilda_griddleLate_1":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_01.wav");
		dialog.text = "Где ты шлялся всё это время, где мои деньги, что я дала на сковороду.";
		link.l1 = "...";
		link.l1.go = "Hilda_griddleLate_2";
		break;

		case "Hilda_griddleLate_2":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_15_02.wav");
		dialog.text = "...";
		link.l1 = "Извини, я немного подзадержался вот твоя сковородка.";
		link.l1.go = "Hilda_griddleLate_3";
		break;

		case "Hilda_griddleLate_3":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_03.wav");
		dialog.text = "А, давай же её сюда. Ну и нахал же ты, просто невероятно...";
		link.l1 = "...";
		link.l1.go = "Hilda_griddle_1";
		break;

		case "Hilda_turnip":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_BRINGBEET_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я принёс тебе репу.";
		link.l1.go = "Hilda_turnip1";
		break;

		case "Hilda_turnip1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "turnip", -1);
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_BRINGBEET_17_01.wav");
		dialog.text = "Отлично, этого должно хватить, что бы накормить наших работников до отвала.";
		link.l1 = "...";
		link.l1.go = "Hilda_Morework_1";
		break;


















//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках		
		case "Woman_FackYou":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_07.wav");
		dialog.text = "Прочь с глаз моих, грязный вор!";
		link.l1 = "Вот дура!";
		link.l1.go = "exit_setOwner";
		LAi_group_Attack(NPChar, Pchar);
		break;

		case "fight":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		LAi_group_Attack(NPChar, Pchar);
		if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
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
