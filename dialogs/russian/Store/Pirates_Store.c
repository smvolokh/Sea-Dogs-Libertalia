// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	bool bOk;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Спрашивай, чего ты хочешь?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушай, это магазин, здесь люди покупают что-то. Не отвлекай меня!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Гм, не буду...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "Послушай, "+npchar.name+", ты не видел в последнее время на Исла Тесоро Мигеля Дичозо?";
				link.l1.go = "tieyasal";
			}

			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "Уважаемый, я ищу один необычный корабль, бриг 'Черная Горгулья'. Ничего о ней не слышали? За любую информацию о ней я "+ GetSexPhrase("готов","готова") +" заплатить...";
				link.l1.go = "BlueBird_1";
			}
			bOk = pchar.questTemp.Headhunter == "end_quest_full" || pchar.questTemp.BlueBird == "weWon" || pchar.questTemp.BlueBird == "returnMoney" || pchar.questTemp.BlueBird == "over"; 
			if (bOk && !CheckAttribute(pchar,"questTemp.BlueBird.speakWon"))
			{
				link.l1 = "Паскаль я хочу тебе сказать, бриг 'Черная Горгулья' на тебя работать не будет, как тебе такой расклад?";
				link.l1.go = "BlueBird_3";
			}

			// Addon 2016-1 Jason пиратская линейка
			if(CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "pasq_start")
			{
				link.l1 = ""+npchar.name+", я прибыл от Маркуса Тиракса. Он сказал, что вам нужен человек для работы.";
				link.l1.go = "mtraxx";
			}
			if(CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "pasq_win")
			{
				link.l1 = ""+npchar.name+", 'Розбоом' найден и захвачен. Приступим к выгрузке товара и расчету?";
				link.l1.go = "mtraxx_5";
			}

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toBermudes" && !CheckAttribute(npchar, "quest.RevengeCorsair_toBermudes"))
			{
				link.l1 = "Уважаемый Паскаль не примете ли груз испанского золота захваченный с Куманы?";
				link.l1.go = "RevengeCorsair_Store";
			}

		break;
				
		// город майя
		case "tieyasal":
			dialog.text = "Видел. Он закупал припасы на свой корабль у меня. Кстати, совсем недавно. Вы буквально на несколько дней разминулись. Кстати, быть может, он еще где-то в поселке. Я, знаешь ли, не шпионю за людьми. Поспрашивай еще, глядишь - отыщется твой дон.";
			link.l1 = "Понятно. Спасибо за сведения!";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			DialogExit();
			npchar.quest.tieyasal = "true";
		break;

		case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("Я ничего не знаю об этом корабле. Если это все, что вы хотели, то уходите.", 
				"Опять? Я все вам сказал.", 
				"Что, снова про то же?",
                "Да когда же это кончится?! Прошу вас, не отвлекайте меня от работы!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Что-то не очень вы любезны, милейший!", 
				"Да-да, я помню...",
                "Ага.", 
				"Хорошо, хорошо...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
		break;
		case "BlueBird_2":
			dialog.text = "Я вам не милейший, ром хлестать и под забором с вами валяться не имел удовольствия.";
			link.l1 = "О как! Да я просто "+ GetSexPhrase("спросил","спросила") +". Ну ладно, спасибо и на этом...";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "2");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("ся","ась"));
		break;

		case "BlueBird_3":
				dialog.text = "Пошёл прочь, сукин сын, я ещё с тобой поквитаюсь!";
				link.l1 = "Да ладно, ты так не нервничай и побереги голосовые связки, а то это может пагубно отразиться на твоём хлипком здоровье.";
				link.l1.go = "exit_BlueBird";
		break;

		case "exit_BlueBird":
			DialogExit();
			pchar.questTemp.BlueBird.speakWon = true;
		break;

		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
			pchar.quest.Mtraxx_PasqualeLate.over = "yes";
            dialog.text = "Именно так! Очень хорошо, вы прибыли вовремя. Теперь излагаю суть дела...";
			link.l1 = "Внимательно вас слушаю.";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
			string sTemp = GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.questTemp.Mtraxx.Crdn.Ship), "Name")));
            dialog.text = "В данный момент к нашим водам приближается голландский корабль из Виллемстада - "+sTemp+" под названием 'Розбоом' с трюмом, полным черного дерева, в сопровождении одного корабля охранения. Каким маршрутом он идет - через Синт-Маартен или через Эспаньолу - мне неведомо, но я точно знаю дату и координаты места, где этот караван встретится с третьим голландским кораблем, и под его охраной конвой двинется на север, в Европу\nВаша задача - найти голландцев в указанном мной месте, отбить 'Розбоом', захватить весь его груз и доставить мне. С вами рассчитаемся сразу же после доставки товара.";
			link.l1 = "Задача ясна. Место и день?";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
			int i = sti(pchar.questTemp.Mtraxx.Crdn.minN2)-10;
			int n = sti(pchar.questTemp.Mtraxx.Crdn.minW2)-10;
            dialog.text = "Встреча голландцев назначена в следующем месте: "+sti(pchar.questTemp.Mtraxx.Crdn.degN)+" градусов "+i+" минут северной широты, "+sti(pchar.questTemp.Mtraxx.Crdn.degW)+" градусов "+n+" минут западной долготы. Это где-то на юг или юго-запад от Исла-Тесоро, я в этом плохо соображаю, вы моряк - разберетесь. Дата - через 5 дней, не считая сегодняшний.";
			link.l1 = "Сейчас все запишем... понятно. Ну, тогда не будем терять времени!";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "Удачи, капитан. Жду вас с товаром.";
			link.l1 = "...";
			link.l1.go = "mtraxx_4";
		break;
		
		case "mtraxx_4":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_convoy";
		   i = sti(pchar.questTemp.Mtraxx.Crdn.minN2)-10;
           n = sti(pchar.questTemp.Mtraxx.Crdn.minW2)-10;
		   AddQuestRecord("Roger_4", "3");
		   AddQuestUserData("Roger_4", "sShip", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.questTemp.Mtraxx.Crdn.Ship), "Name")+ "Gen")));
		   AddQuestUserData("Roger_4", "sdegN", sti(pchar.questTemp.Mtraxx.Crdn.degN));
		   AddQuestUserData("Roger_4", "sminN", i);
		   AddQuestUserData("Roger_4", "sdegW", sti(pchar.questTemp.Mtraxx.Crdn.degW));
		   AddQuestUserData("Roger_4", "sminW", n);
		   SetFunctionTimerCondition("Mtraxx_PasqualeTimeConvoy", 0, 0, 6, false);
		   SetFunctionTimerCondition("Mtraxx_PasqualeConvoyOver", 0, 0, 7, false);
		break;
		
		case "mtraxx_5":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_EBONY);
			if (iTotalTemp < 1)
			{
				dialog.text = "Вы издеваетесь, молодой человек? В ваших трюмах нет ни одного центнера черного дерева! Вы меня нагло надули! Это вам даром не пройдет - я пожалуюсь Маркусу Тираксу! Убирайтесь вон!!";
				link.l1 = "Гм...";
				link.l1.go = "mtraxx_6";
				break;
			}
			if (iTotalTemp < makeint(sti(pchar.questTemp.Mtraxx.Crdn.Ebony)/4))
			{
				dialog.text = "Вы издеваетесь, молодой человек? В ваших трюмах жалкие крохи от того количества черного дерева, что было на 'Розбоом'! Вы меня нагло надули! Это вам даром не пройдет - я пожалуюсь Маркусу Тираксу! Убирайтесь вон!!";
				link.l1 = "Гм...";
				link.l1.go = "mtraxx_6";
				break;
			}
			if (iTotalTemp < sti(pchar.questTemp.Mtraxx.Crdn.Ebony)-20)
			{
				dialog.text = "На 'Розбоом' должно было быть не меньше "+FindRussianQtyString(sti(pchar.questTemp.Mtraxx.Crdn.Ebony))+" черного дерева. Почему вы привезли меньше?";
				link.l1 = "Так это - часть груза пришлось бросить в бою. И еще крысы сожрали, треклятые...";
				link.l1.go = "mtraxx_7";
				break;
			}
            dialog.text = "Очень хорошо. Сколько у вас товара? "+FindRussianQtyString(iTotalTemp)+"? Отлично! Я заплачу вам по 150 песо за единицу товара.";
			link.l1 = "По 150 песо? Но мне кажется, что это дерево стоит гораздо дороже...";
			link.l1.go = "mtraxx_10";
		break;
		
		case "mtraxx_6":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_angry";
		   DoQuestReloadToLocation("Pirates_town", "reload", "reload6", "");
		   AddQuestRecord("Roger_4", "8");
		   CloseQuestHeader("Roger_4");
		   QuestSetCurrentNode("Terrax", "mtraxx_34");
		break;
		
		case "mtraxx_7":
            dialog.text = "Крысы? Ну-ну... Впрочем, ладно. Я заплачу вам по 100 песо за единицу товара и можете быть свободны.";
			link.l1 = "Всего по 100 песо? Но это же грабеж!";
			link.l1.go = "mtraxx_8";
		break;
		
		case "mtraxx_8":
			AddMoneyToCharacter(pchar, iTotalTemp*100);
			RemoveCharacterGoods(pchar, GOOD_EBONY, iTotalTemp);
            dialog.text = "Грабеж - это по вашей части, капитан, а я просто торговец. Берите ваши деньги и прекратим эти споры - вы и так нажились на мне, сбыв где-то часть моего товара...";
			link.l1 = "Ну и черт с вами!";
			link.l1.go = "mtraxx_9";
		break;
		
		case "mtraxx_9":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_fail";
		   AddQuestRecord("Roger_4", "8");
		   CloseQuestHeader("Roger_4");
		   QuestSetCurrentNode("Terrax", "mtraxx_34");
		break;
		
		case "mtraxx_10":
            dialog.text = "Вам правильно кажется, капитан, но во-первых, попробуйте продать дороже награбленный товар - я посмотрю, сколько вам за него заплатят. Цена, предложенная вам, очень высока. Во-вторых, без моей наводки вы бы никогда не нашли этот караван, а там, кроме дерева, было наверняка что-то еще, но, заметьте - я не требую от вас более ничего. В-третьих, я похвалю вас перед Маркусом Тираксом, а это - поверьте - дорогого стоит. Ну и в-четвертых, должен же бедный торговец на что-то жить.";
			link.l1 = "Ух! Под градом таких аргументов я отступаю, "+npchar.name+". Приступим к расчету.";
			link.l1.go = "mtraxx_11";
		break;
		
		case "mtraxx_11":
			AddMoneyToCharacter(pchar, iTotalTemp*150);
			RemoveCharacterGoods(pchar, GOOD_EBONY, iTotalTemp);
            dialog.text = "Вот и славно. Получите ваши деньги. Было приятно с вами работать. Заглядывайте, не забывайте. Удачи в море!";
			link.l1 = "И вам успехов в торговле...";
			link.l1.go = "mtraxx_12";
		break;
		
		case "mtraxx_12":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_complete";
		   AddQuestRecord("Roger_4", "9");
		   pchar.quest.mtr_pasq_fin.win_condition.l1 = "location";
		   pchar.quest.mtr_pasq_fin.win_condition.l1.location = "Pirates_town";
		   pchar.quest.mtr_pasq_fin.function = "Mtraxx_PasqualeJeffry";
		   bDisableFastReload = true;
		break;

		//********************* Месть корсара *********************

   		case "RevengeCorsair_Store":
		dialog.text = "Золото, испанское ЗОЛОТО, о, да, ты обратился по адресу.";
		link.l1 = "Хе...Старый пройдоха, я знал, что могу у тебя сбыть награбленное, приступим к делам.";
		link.l1.go = "RevengeCorsair_Store_1";
		break;

 		case "RevengeCorsair_Store_1":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_GOLD);
			if (iTotalTemp < 500)
			{
					dialog.text = "Шутить изволите... Капитан, кроме крыс на вашем корабле ничего нет!";
					link.l1 = "Чёрт, как так-то!";
					link.l1.go = "sale_gold_fail";
					break;
					}
					dialog.text = "Само собой, сколько готов отдать?";
					link.l1 = "Готов продать всё, всё будет зависеть от цены!";
					link.l1.go = "sale_gold_all";		
					break;

   		case "sale_gold_all":
		dialog.text = "Прекрасно!";
		link.l1 = "И...";
		link.l1.go = "sale_gold_all_1";
		break;

	 	case "sale_gold_all_1":
            if (GetCargoMaxSpace(pchar) >= RecalculateCargoLoad(pchar))
            {
		dialog.text = "Твоя добыча золота - " + pchar.Ship.Cargo.Goods.gold + " центнера. Возьму по 1000 песо за единицу веса, что скажешь!";
           }     
		link.l1 = "Договорились, начинай разгрузку, Паскаль. Еще увидимся. Эх, закачу попойку в вашей дыре на пару недель, век воли не видать...";
		link.l1.go = "RevengeCorsair_Store_2";
		break;		

   		case "RevengeCorsair_Store_2":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "Давай, Барон, хорошего отдыха, эх жаль Маркус этого не увидел - царство ему небесное!";
		link.l1 = "Да, хороший был корсар. Заходи в кабак, налью за свой счёт - помянем Маркуса!";
		link.l1.go = "RevengeCorsair_Store_3";
   		RemoveCharacterGoods(Pchar, GOOD_GOLD, sti(pchar.questTemp.CumanaGoldQty));
		AddMoneyToCharacter(pchar, makeint(sti(pchar.questTemp.CumanaGoldQty)*1000));
		break;

   		case "RevengeCorsair_Store_3":
		dialog.text = "Некогда мне пить, золото надо почистить от крысинного помёта!";
		link.l1 = "Как знаешь, было бы предложенно.";
		link.l1.go = "exit";
                                         DeleteAttribute(pchar, "questTemp.CumanaGoldQty");
		npchar.quest.RevengeCorsair_toBermudes = "true";
	                     AddDialogExitQuestFunction("Gothic_RevengeCorsair_19");
		break;

		case "sale_gold_fail":
		DialogExit();
		AddQuestRecord("RevengeCorsair", "18_1");
		CloseQuestHeader("RevengeCorsair");				                                            npchar.quest.RevengeCorsair_toBermudes = "true";
	                     AddDialogExitQuestFunction("Gothic_RevengeCorsair_18_1");
		break;			


	}
	UnloadSegment(NPChar.FileDialog2);
}