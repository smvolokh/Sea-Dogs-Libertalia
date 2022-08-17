// Бальтрам торговец
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
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_01.wav");
		dialog.text = "Боюсь, что мне придётся разочаровать тебя, в ностоящий момент я мало, что могу предложить.";
		link.l1 = "";
		link.l1.go = "First time_exit";
		break;

		case "First time_exit":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_04.wav");
			dialog.text = "Я не самого лучшего мнения о вас - наёмников, от вас одни проблемы.";
			link.l1 = "Ну, тогда до встречи...";
			link.l1.go = "exit";

		NextDiag.TempNode = "First time";
		break;

			

		case "Baltram_hallo":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_00.wav");
			dialog.text = "Добро пожаловать чужеземец, меня зовут Бальрам, ты хочешь запастись продовольствием?";
			link.l1 = "Покажи мне свои товары.";
			link.l1.go = "Baltram_hallo_1";
		break;

		case "Baltram_hallo_1":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_WAREZ_15_00.wav");
			dialog.text = "";
			link.l1 = "Покажи мне свои товары.";
			link.l1.go = "Baltram_hallo_2";
		break;		

		case "Baltram_hallo_2":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_01.wav");
			dialog.text = "Боюсь, что мне придётся разочаровать тебя, в ностоящий момент я мало, что могу предложить.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_3";
		break;

		case "Baltram_hallo_3":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_02.wav");
			dialog.text = "Но скоро я жду новую поставку.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_4";
		break;

		case "Baltram_hallo_4":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_03.wav");
			dialog.text = "Если ты пришёл купить у меня съестные припасы, ты пришёл напрасно.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_5";
		break;

		case "Baltram_hallo_5":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_LARESABLOESE_15_06.wav");
			dialog.text = "";
			link.l1 = "Понятно, может ещё увидимся!";
			link.l1.go = "exit";
		break;								






		case "1":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_15_00.wav");
			dialog.text = "";
			link.l1 = "Значит ты торгуешь с пиратами?";
			link.l1.go = "1_7";
		break;

		case "1_7":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_01_03.wav");
			dialog.text = "Что же мне было делать, времена сейчас тяжелые каждый выкручивается как может.";
			link.l1 = "Ты прав, времена тяжелые?";
			link.l1.go = "1_8";
		break;

		case "1_8":
			dialog.text = "";
			link.l1 = "Я доставил" + GetSexPhrase("","а") + " тебе дневник капитана Томми Толстяка и весть о его гибели у берегов Гваделупы, царство ему небесное.";
			link.l1.go = "1_9";
		break;
		
		case "1_9":
			dialog.text = "Что, но как. Объяснитесь!";
			link.l1 = "Этого мне не известно, но так случилось, что я завладел" + GetSexPhrase("","а") + " его дневником. Я узнал" + GetSexPhrase("","а") + " из дневника, что он должен быть доставлен вам груз какао и без промедления взял" + GetSexPhrase("","а") + " курс на Мартинику.";
			link.l1.go = "1_10";
		                   PlaySound("interface\important_item.wav");
			TakeNItems(PChar, "PortmansBook", -1);
		break;
		
		case "1_10":
			dialog.text = "Очень прескорбно, неважно. Я надеялся продать товар за приличные деньги, жаль.";
			link.l1 = "Жаль, чего?";
			link.l1.go = "1_11";
		break;

		case "1_11":
			dialog.text = "Ничего!";
			link.l1 = "";
			link.l1.go = "1_12";
		break;
		
		case "1_12":
			dialog.text = "Неважно! Теперь уже неважно. А теперь, ближе к делу, я готов заплатить вам за хлопоты 750 песо.";
			link.l1 = "750 песо? Вообще - то я...";
			link.l1.go = "1_13";
		break;
		
		case "1_13":
			dialog.text = "Я понимаю, но всё же, хоть, что - то.";
			link.l1 = "Хорошо, давайте ваши деньги.";
			link.l1.go = "1_14";
		break;
				
		case "1_14":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 750);
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "1_15";
		break;

		case "1_15":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_JOB_15_00.wav");
			dialog.text = "";
			link.l1 = "У тебя есть работа для меня?";
			link.l1.go = "1_16";
		break;

		case "1_16":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_00.wav");
			dialog.text = "Ты ищешь работу?";
			link.l1 = "";
			link.l1.go = "1_17";
		break;

		case "1_17":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_02.wav");
			dialog.text = "Мой мальчик на побегушках не вернулся а я жду поставку от фермера Акила!!!";
			link.l1 = "";
			link.l1.go = "1_18";
		break;

		case "1_18":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_01.wav");
			dialog.text = "";
			link.l1 = "Конечно, а что нужно!";
			link.l1.go = "1_19";
		break;

		case "1_19":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_03.wav");
			dialog.text = "";
			link.l1 = "И во сколько ты оцениваешь эту работу?";
			link.l1.go = "1_20";
		break;

		case "1_20":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_04.wav");
			dialog.text = "Я дам тебе 50 золотых монет!";
			link.l1 = "";
			link.l1.go = "1_21";
		break;

		case "1_21":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_05.wav");
			dialog.text = "";
			link.l1 = "Отлично я согласен, где его найти.";
			link.l1.go = "1_22";
		break;

		case "1_22":
			dialog.text = "Он находится в южной части этого острова, небольшая ферма с небольшим домом.";
			link.l1 = "";
			link.l1.go = "1_23";
		break;

		case "1_23":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("Gothic_Akil");
		break;

		case "1_24":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LIEFERUNG_15_00.wav");
		                   PlaySound("interface\important_item.wav");
		                   RemoveItems(PChar, "cask_whisky", 1);
			dialog.text = "";
			link.l1 = "Я принес пакет от Акила!";
			link.l1.go = "1_25";
		break;

		case "1_25":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LIEFERUNG_01_01.wav");
			dialog.text = "Превосходно, теперь я опять смогу торговать свежими продуктами, вот твои 50 золотых монет.";
			link.l1 = "";
			link.l1.go = "1_26";
		break;

		case "1_26":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			TakeNItems(pchar, "gold_dublon", 50);
			Log_Info("Вы получили 50 дублонов");
			PlaySound("interface\important_item.wav");

			dialog.text = "";
			link.l1 = "";
			link.l1.go = "1_27";
		break;

		case "1_27":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LETUSTRADE_15_00.wav");
			dialog.text = "";
			link.l1 = "Может нам опять поработать в месте?";
			link.l1.go = "1_28";
		break;

		case "1_28":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_04.wav");
			dialog.text = "Я не самого лучшего мнения о вас - наёмников, от вас одни проблемы, но с тобой мы сработаемся, немного позже. Загляни через пару дней, возможно что - нибудь и будет!";
			link.l1 = "";
			link.l1.go = "1_29";
		break;

		case "1_29":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDelivery_taimer");
		break;


		
		case "2_1":
			dialog.text = "Ты как раз вовремя.\nНеобходимо доставить небольшую партию корабельного шелка Акиле в Порт-о-Принс, ты его уже знаешь, теперь он не фермер, а торговый представитель, вот так - то.\nМы решили заняться более крупными делами.\nВыполнишь, в накладе не останешься, и получишь от него 7000 песо. Ну, что согласен? Советую не отказываться.";
			link.l1 = "Я соглас" + GetSexPhrase("ен","на") + ".";
			link.l1.go = "2_2";
			link.l2 = "Нет, я отказываюсь.";
			link.l2.go = "2_5";
		break;
		
		case "2_2":
			dialog.text = "Отлично. На Эспаньоле Акил в городе арендует дом, найти просто, только ради Иннаса, осторожней с шелком. Однако дорогой груз.";
			link.l1 = "Хорошо, я всё понял" + GetSexPhrase("","а") + ".";
			link.l1.go = "2_3";
		break;

		case "2_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDeliverySilk");
		break;
		
		case "2_4":
			dialog.text = "И вот, это письмо передай Акиле. Это всё. Попутного ветра, капитан "+ GetFullName(Pchar)+"!";
			link.l1 = "Удачного дня.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAgree");
		break;

		case "2_5":
			dialog.text = "Попутного ветра, капитан "+ GetFullName(Pchar)+"!";
			link.l1 = "Удачного дня.";
			link.l1.go = "exit_1";
		                   AddDialogExitQuestFunction("No_Baltram");
		break;
		
 		case "exit_1":
                                       NextDiag.CurrentNode = "Exit2";
		DialogExit();
		AddDialogExitQuestFunction("GothicDeliveryCancel");
		break;


		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner2":
			AddMoneyToCharacter(PChar, -sti(PChar.StealItemsMoney));
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner3":
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;



		case "BaltramCaleuche":// квест Калеуче
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_PIRAT_01_04.wav");
		dialog.text = "Однако я считаю, что бандиты ещё хуже. Ах, это вы, капитан "+ GetFullName(Pchar)+"?";
		link.l1 = "Что вы здесь делаете, как вы здесь оказались месье Бальтрам?";
		link.l1.go = "BaltramCaleuche_1";
		break;

		case "BaltramCaleuche_1":
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_PIRAT_01_02.wav");
		dialog.text = "Насколько я знаю попасть сюда можно только на корабле?";
		link.l1 = "Как умно?";
		link.l1.go = "BaltramCaleuche_2_1";
		break;

		case "BaltramCaleuche_2_1":
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_WAS_15_00.wav");
		dialog.text = "...";
		link.l1 = "И чем же ты торговал? Может расскажешь?";
		link.l1.go = "BaltramCaleuche_2";
		break;
		
		case "BaltramCaleuche_2":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_WAS_01_01.wav");
		dialog.text = "В основном я продовал им еду, а меня в Порт-Рояле поимели как мальчишку. Болтали вчера с товарищем про бизнес, и выразил он свое главное опасение: стоит заняться в Порт-Рояле малым бизнесом, и непременно должны появиться вежливые джентельмены, предлагающие свои услуги крышевания, и призывающие делиться баблом\nА в случае отказа, совершенно случайно будут продовать кирпичи, индейские побрякушки по выгодной цене, а особо несговорчивых приласкают трубой по макушке в темной подворотне.";
		link.l1 = "Да, ну и дела. Ну а ты?";
		link.l1.go = "BaltramCaleuche_3";
		break;

		case "BaltramCaleuche_3":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_WAREZ_01_02.wav");
		dialog.text = "Что-то подобное обязательно должно было случиться. Я в отказ, зачем мне крыша. Вот и мне предложили купить индейские побрякушки, чёрт бы побрал этого Моргана со своим писарем, пришлось купить от греха подальше. Нет, я ни ногой в Порт-Роял больше.";
		link.l1 = "Слушай, давай я у тебя куплю, эти индейские штучки?";
		link.l1.go = "BaltramCaleuche_4";
		break;

		case "BaltramCaleuche_4":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HAVEYOURWAREZ_01_05.wav");
		dialog.text = "Теперь ничто не мешает нам вести дела?";
		link.l1 = "";
		link.l1.go = "BaltramCaleuche_5_1";
		break;

		case "BaltramCaleuche_5_1":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_13.wav");
		dialog.text = "";
		link.l1 = "Сколько ты хочешь?";
		link.l1.go = "BaltramCaleuche_5";
		break;

		case "BaltramCaleuche_5":
 	        PlaySound("VOICE\Russian\gotica\SVM_1\SVM_4_GOLD_300.wav");
		dialog.text = "300 золотых монет.";
		link.l1 = "";
		link.l1.go = "BaltramCaleuche_6";
		break;

		case "BaltramCaleuche_6":
		if (GetCharacterItem(pchar, "gold_dublon") >= 300)
		{
		link.l1 = "Вот, твоё золото.";
		link.l1.go = "BaltramCaleuche_7";
		}
		link.l2 = "Извени у меня нет денег.";
		link.l2.go = "BaltramCaleuche_10";
		break;

		case "BaltramCaleuche_7":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		RemoveItems(pchar, "gold_dublon", 300);
		Log_Info("Вы отдали 300 дублонов");
                dialog.text = "Замечательно! Месье, деньги наши - товар ваши!";
		link.l1 = "Спасибо, ещё увидимся?";
		link.l1.go = "BaltramCaleuche_8";
		break;

		case "BaltramCaleuche_8":
	        Log_Info("Вы получили странные индейские побрякушки");
		PlaySound("interface\important_item.wav");
                DialogExit();
                NextDiag.TempNode = "First time";
                NextDiag.CurrentNode = NextDiag.TempNode;
		GiveItem2Character(pchar, "kaleuche_amulet1");
		GiveItem2Character(pchar, "indian_3");
		GiveItem2Character(pchar, "amulet_4");
		GiveItem2Character(pchar, "obereg_5");
		break;

		case "BaltramCaleuche_9":
                dialog.text = "Есть деньги?";
		if (GetCharacterItem(pchar, "gold_dublon") >= 300)
		{
			link.l1 = "Да, вот три сотни дублонов.";
			link.l1.go = "BaltramCaleuche_7";
		}
		link.l2 = "Пока нет, я еще работаю над этим.";
		link.l2.go = "BaltramCaleuche_10";
		break;
		
		case "BaltramCaleuche_10":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
                DialogExit();
		npchar.dialog.currentnode = "BaltramCaleuche_9";
		break;


		case "Baltramrocur":// Addon 2016-1 Jason пиратская линейка

		dialog.text = "Ах, это Вы, капитан "+ GetFullName(Pchar)+"! Приветсвую Вас!";
		link.l1 = "Добрый день. Что Вы здесь делаете, месье Бальтрам?";
		link.l1.go = "Baltramrocur_1";
		break;

		case "Baltramrocur_1":
		dialog.text = "Путешествую, знакомлюсь с людьми, продаю товар.";
		link.l1 = "А что Вы продаёте?";
		link.l1.go = "Baltramrocur_2";
		break;
		
		case "Baltramrocur_2":
		dialog.text = "Продаю в основном лекарства, оружие, которого здесь полно. Поэтому никто не берет этот товар. А негоция чаем, копрой, кофе и ванилью идёт в убыток, спасибо соедней плантации. Жаль, но похоже сюда я напрасно приехал.";
		link.l1 = "Какая удача! Мне как раз необходимо оружие!";
		link.l1.go = "Baltramrocur_3";
		break;

		case "Baltramrocur_3":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_SPERRE_01_00.wav");
		dialog.text = "Только задёшево я его не продам! Мне нужны деньги на обратный путь до Мартиники.";
		link.l1 = "Никаких проблем. Мне нужно три десятка строевых пистолей, да заряды к ним. Также необходимы лечебные зелья. Под сотню пузырьков. Ну и парочка мушкетов с двумя десятками зарядов на каждый. У Вас имеется такой товар, мсье Бальтрам?";
		link.l1.go = "Baltramrocur_4";
		break;

		case "Baltramrocur_4":
		dialog.text = "Да, всё перчисленное есть в наличии. Но продам я только оптом со всем моим остальным товаром: кофе, копра и ваниль. Что скажете?";
		link.l1 = "Сколько?";
		link.l1.go = "Baltramrocur_5";
		break;

		case "Baltramrocur_5":
 		dialog.text = "Пять сотен дублонов.";
		link.l1 = "По рукам.";
		link.l1.go = "Baltramrocur_6";
		break;

		case "Baltramrocur_6":
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l1 = "Вот, держите.";
		link.l1.go = "Baltramrocur_7";
		}
		link.l2 = "Подождите минутку. Я мигом.";
		link.l2.go = "Baltram_10";
		break;

		case "Baltramrocur_7":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                                      PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		RemoveItems(pchar, "gold_dublon", 500);
		Log_Info("Вы отдали 500 дублонов");
                                     	dialog.text = "Замечательно! Деньги наши - товар ваши!";
		link.l1 = "Спасибо, ещё увидимся!";
		link.l1.go = "Baltramrocur_8";
		break;

		case "Baltramrocur_8":
		PlaySound("interface\important_item.wav");
                                      DialogExit();
                                      NextDiag.TempNode = "First time";
                                      NextDiag.CurrentNode = NextDiag.TempNode;
		TakeNItems(pchar, "pistol1", 30);
		TakeNItems(pchar, "mushket1", 2);
		TakeNItems(pchar, "potion1", 90);
		TakeNItems(pchar, "bullet", 100);
		TakeNItems(pchar, "GunPowder", 100);
RemoveCharacterGoods(sld, GOOD_COFFEE, 100);
SetCharacterGoods(pchar, GOOD_COFFEE, 100);
RemoveCharacterGoods(sld, GOOD_CINNAMON, 100);
SetCharacterGoods(pchar, GOOD_CINNAMON, 100);
RemoveCharacterGoods(sld, GOOD_COPRA, 100);
SetCharacterGoods(pchar, GOOD_COPRA, 100);
	RemoveCharacterGoods(sld, GOOD_TEA, 100);
	SetCharacterGoods(pchar, GOOD_TEA, 100);
		break;

		case "Baltramrocur_9":
            dialog.text = "Принесли деньги?";
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l1 = "Да, вот пять сотен дублонов.";
		link.l1.go = "Baltramrocur_7";
		}
		link.l2 = "Пока нет.";
		link.l2.go = "Baltram_10";
		break;
		
		case "Baltram_10":
           DialogExit();
		npchar.dialog.currentnode = "Baltramrocur_9";
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


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}