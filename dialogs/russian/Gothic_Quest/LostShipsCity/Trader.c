
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	if (CheckAttribute(npchar, "quest.takeMap")) Log_SetStringToLog("Статус: " + npchar.quest.takeMap);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				npchar.quest.meeting = "1";
				if (CheckAttribute(loadedLocation, "storm"))
				{
					dialog.text = "Чертов шторм! Хотя уже пошел на убыль... Я так понимаю, что ты - "+ GetSexPhrase("новый гражданин","новая гражданка") +" Города.";
					link.l1 = "Капитан " + GetFullName(pchar) + " собственной персоной. А шторм - не беда!";
					link.l1.go = "FS_1";
				}
				else
				{
					dialog.text = "А-а, ну вот ты и ко мне пожаловал"+ GetSexPhrase("","а") +". Я так понимаю, что ты - "+ GetSexPhrase("новый гражданин","новая гражданка") +" Города.";
					link.l1 = "Капитан " + GetFullName(pchar) + " собственной персоной.";
					link.l1.go = "FT_1";
				}
			}
			else
			{
				dialog.text = "Желаешь что-нибудь купить или продать?";
				link.l1 = "Покажи, что там у тебя есть.";
				link.l1.go = "Trade_exit";
				//квест получения карты -->
				if (!CheckAttribute(npchar, "quest.takeMap"))
				{
					link.l2 = "Дружище, я слышал"+ GetSexPhrase("","а") +", что у тебя есть карта Города. Ты знаешь, в данный момент мне бы она очень пригодилась. А то бегаю здесь, как слепой котенок, не освоил"+ GetSexPhrase("ся","ась") +" еще...";
					link.l2.go = "tekeMap_begin";
				}
				if (CheckAttribute(npchar, "quest.takeMap") && npchar.quest.takeMap == "mapIsToken" && !CheckCharacterItem(pchar, "map_LSCC"))
				{
					link.l2 = "Приятель, ты часом не сбрендил? Такие деньги за паршивый клочок бумаги, гордо именуемый картой Города?";
					link.l2.go = "tekeMap_off";
				}
				if (CheckAttribute(npchar, "quest.takeMap") && npchar.quest.takeMap == "discount")
				{
					link.l2 = "Послушай, дружище, " + npchar.quest.takeMap.name + " просила меня переговорить с тобой еще раз по поводу карты Города.";
					link.l2.go = "tekeMap_on";
				}
				//<-- квест получения карты
				link.l3 = "Спасибо, не интересует.";
				link.l3.go = "exit";
				//поиск товаров на воздушный шар
				if (pchar.questTemp.LSCC == "toSeekGoods" && !CheckAttribute(pchar, "questTemp.LSCC.goods.trader"))
				{
					link.l8 = "Слушай, я хочу купить у тебя кое-что особенное.";
					link.l8.go = "SeekGoods";
				}
				if (pchar.questTemp.LSCC == "toSeekGoods" && CheckAttribute(pchar, "questTemp.LSCC.goods.trader") && sti(pchar.questTemp.LSCC.goods.trader))
				{
					link.l8 = "Я по поводу покупки тех товаров, что ты мне обещал.";
					link.l8.go = "SeekGoodsOk";
				}
				//поиски команды на корвет
				if (pchar.questTemp.LSCC == "toSeekPeopleInCrew")
				{
					link.l8 = "Слушай, есть серьезный разговор. Я набираю команду.";
					link.l8.go = "SeekCrew";
				}
				NextDiag.TempNode = "First time";
			}
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "FS_1":
			dialog.text = "А ты откуда знаешь, что беда, а что нет?.. Ладно, плохое у меня настроение сегодня. Меня зовут " + GetFullName(npchar) + ", я хозяин этого магазина. Будем знакомы.";
			link.l1 = "Будем.";
			link.l1.go = "exit";
		break;
		case "FT_1":
			dialog.text = "Отлично! А меня зовут " + GetFullName(npchar) + ", я хозяин этого магазина. Будем знакомы.";
			link.l1 = "Будем.";
			link.l1.go = "exit";
		break;

		case "Trade_exit":
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(npchar, 0);
		break;

		//поиск товаров на воздушный шар
		case "SeekGoods":
			dialog.text = "Всегда к твоим услугам, "+ GetSexPhrase("приятель","" + pchar.name + "") +". Заказывай!";
			link.l1 = "Слушай, таких товаров в твоем ассортименте я еще не встречал"+ GetSexPhrase("","а") +". Это бомбы, книпеля, порох, провиант, парусина, доски, лекарства...";
			link.l1.go = "SeekGoods_1";
		break;
		case "SeekGoods_1":
			dialog.text = "Ну, из того, что ты перечислил"+ GetSexPhrase("","а") +", здесь в цене только провиант и парусина, доски и лекарства. Остальное просто никому не нужно.";
			link.l1 = "А у тебя что-нибудь есть?";
			link.l1.go = "SeekGoods_2";
		break;
		case "SeekGoods_2":
			dialog.text = "Провиант тебе могу продать. Он довольно дорогой.";
			link.l1 = "Мне нужно 20 центнеров. Сколько это будет стоить?";
			link.l1.go = "SeekGoods_3";
		break;
		case "SeekGoods_3":
			dialog.text = "Тридцать пять тысяч монет.";
			link.l1 = "Сколько?! А со скидкой?";
			link.l1.go = "SeekGoods_4";
		break;
		case "SeekGoods_4":
			dialog.text = "Извини, но скидки не предусмотрены. В нагрузку подкину тебе парусины и досок за пять тысяч золотых. Итого, если ты желаешь все это приобрести, то готовь 40 тысяч.";
			if (sti(pchar.money) >= 40000)
			{
				link.l1 = "Я готов"+ GetSexPhrase("","а") +" заплатить.";
				link.l1.go = "SeekGoods_5";
			}
			else
			{
				link.l1 = "У меня нет таких денег.";
				link.l1.go = "SeekGoods_notMoney";
			}
		break;
		case "SeekGoods_notMoney":
			dialog.text = "Ну, приходи, когда будут.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC.goods.trader = true;
		break;

		case "SeekGoods_5":
			dialog.text = "Отлично, "+ GetSexPhrase("дружище","" + pchar.name + "") +". Куда тебе все это сгрузить?";
			link.l1 = "Слушай, отправь все это на 'Сан Габриэль'. 'Касперов' там уже нет, если ты не в курсе...";
			link.l1.go = "SeekGoods_6";
		break;
		case "SeekGoods_6":
			dialog.text = "Я в курсе. Все сделаю.";
			link.l1 = "Спасибо тебе, приятель.";
			link.l1.go = "exit";
			AddQuestRecord("ISS_MainLine", "46");
			AddMoneyToCharacter(pchar, -40000);
			AddCharacterGoods(pchar, GOOD_FOOD, 200);
			AddCharacterGoods(pchar, GOOD_PLANKS, 50);
			AddCharacterGoods(pchar, GOOD_SAILCLOTH, 50);
			pchar.questTemp.LSC.goods.trader = false;
		break;

		case "SeekGoodsOk":
			dialog.text = "Раздобыл"+ GetSexPhrase("","а") +" деньги?";
			if (sti(pchar.money) >= 40000)
			{
				link.l1 = "Да. И готов"+ GetSexPhrase("","а") +" заплатить.";
				link.l1.go = "SeekGoods_5";
			}
			else
			{
				link.l1 = "Нет еще...";
				link.l1.go = "SeekGoods_notMoney";
			}
		break;
		//найм команды
		case "SeekCrew":
			dialog.text = NPCStringReactionRepeat("Какую команду?", 
				"Мы уже говорили об этом.", 
				"Это уже обсуждено, второй раз повторяю.",
                "Хватит, утомил"+ GetSexPhrase("","а") +"...", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("На мой воздушный шар. Я ухожу из Города.", 
				"Да... Извини, запамятовал"+ GetSexPhrase("","а") +".",
                "Как знаешь...", 
				"Ну, ладно...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("SeekCrew_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "SeekCrew_1":
			dialog.text = "Хех, а ты далеко пойдешь... Ты ведь знаешь, что нарушаешь Закон Города?";
			link.l1 = "Знаю. Но я спасаю свою жизнь. Дело в том, что Город будет разрушен надвигающимся штормом.";
			link.l1.go = "SeekCrew_2";
		break;
		case "SeekCrew_2":
			dialog.text = "Н-да, и к гадалке не ходи...";
			link.l1 = "Ты мне не веришь?";
			link.l1.go = "SeekCrew_3";
		break;
		case "SeekCrew_3":
			dialog.text = "Нет, не верю. И не хочу больше об этом говорить.";
			link.l1 = "Хм... Ну как знаешь.";
			link.l1.go = "exit";
		break;
		//квест получения карты Города
		case "tekeMap_begin":
			dialog.text = "Понимаю, с новыми гражданами всегда так...";
			link.l1 = "Ну так что, карта у тебя есть?";
			link.l1.go = "tekeMap_begin_1";
		break;
		case "tekeMap_begin_1":
			dialog.text = "Есть, тебя не обманули.";
			link.l1 = "Дружище, мне она нужна.";
			link.l1.go = "tekeMap_begin_2";
		break;
		case "tekeMap_begin_2":
			dialog.text = "Сто тысяч золотом, приятель! Сто тысяч золотом - и прямо сейчас.";
			if(makeint(Pchar.money) >= 100000)
			{
				link.l1 = "Сколько?? Да ты что, сдурел - просить такие деньги за бумагу с картинками?!";
				link.l1.go = "tekeMap_stid_nopay";
				link.l2 = "Без проблем. Держи свои песо.";
				link.l2.go = "tekeMap_stid_paymoney";
			}
			link.l3 = "Послушай, но у меня нет таких денег!";
			link.l3.go = "tekeMap_stid_nomoney";
		break;
		case "tekeMap_stid_nopay":
			dialog.text = "Не считай меня простофилей - карта стоит намного дороже. А свою байку про 'картинки' будешь рассказывать гусыне на заднем дворе таверны - тебе поверит только сын панамского верфиста... Если удастся завладеть картой - еще благодарить меня будешь. А, если не удастся - то бегай, ха-ха-ха...";
			link.l1 = "Ладно, черт с тобой. Держи.";
			link.l1.go = "tekeMap_stid_paymoney";
			link.l2 = "Не каркай. Обойдёшься без золота - сам"+ GetSexPhrase("","а") +" найду.";
			link.l2.go = "tekeMap_stid_goaway";
		break;	

		case "tekeMap_stid_nomoney":
			dialog.text = "Ну что ж - видно не судьба тебе достать 'карту'. Подожду, пока моей картой заинтересуется кто-то посолиднее. А ждать, что ты разбогатеешь, смысла нет... Так что, хочешь - бери, не хочешь не бери. А я тебе не помощник.";
			link.l1 = "Ну что, прощай. Не напрасно тебя называют пройдохой. Мог заработать немного песо, а не заработал - зато много...";
			link.l1.go = "exit";
			npchar.quest.takeMap = "veteran";
		break;	

		case "tekeMap_stid_goaway":
			dialog.text = "Как знаешь. Хозяин - барин. Удачных забегов!";
			link.l1 = "Прощай.";
			link.l1.go = "exit";
			npchar.quest.takeMap = "veteran";
		break;	

		case "tekeMap_stid_paymoney":
			AddMoneyToCharacter(Pchar, -100000);
			dialog.text = "О-о, у меня появил"+ GetSexPhrase("ся щедрый приятель","ась щедрая приятельница") +"! Я даже стал подумывать - не продешевил ли я! Ну, да ладно - чего не сделаешь ради бескорыстной дружбы...";
			link.l1 = "Спасибо!";
			link.l1.go = "tekeMap_stid_paymoney_1";
		break;

		case "tekeMap_stid_paymoney_1":
			TakeNItems(pchar, "map_LSCC", 1);
			Log_Info("Вы получили карту");
			dialog.text = "Удачи.";
			link.l1 = "Хм...";
			link.l1.go = "exit";
			npchar.quest.takeMap = "veteran";
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
				dialog.text = NPCharSexPhrase(NPChar, "Острожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции	

	}
}
