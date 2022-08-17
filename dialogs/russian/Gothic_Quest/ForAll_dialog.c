
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sGem, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Не о чем говорить.";
			link.l1 = "Ладно...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//--------------------------- линейка ГПК --------------------------------
		//заказчик устранения всех нищих
		case "Begin_PoorKill":
			dialog.text = "Добрый день, капитан. Не откажетесь переговорить со мной об одном деле?";
			link.l1 = "Отчего не поговорить? С удовольствием!";
			link.l1.go = "Begin_PoorKill_1";
		break;

		case "Begin_PoorKill_close":
			dialog.text = "Хм, понятно... Ну что же, очень жаль.";
			link.l1 = "...";
			link.l1.go = "Exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			ChangeCharacterComplexReputation(pchar, "nobility", 15);
			pchar.questTemp.LSCC = "PoorIsGood";
			SetQuestHeader("ISS_PoorsMurder");
			AddQuestRecord("ISS_PoorsMurder", "12");
			AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("ым","ой"));
		break;

		case "Begin_PoorKill_1":
			dialog.text = "Прекрасно! Сразу видно делового человека.";
			link.l1 = "Ближе к делу, милейший.";
			link.l1.go = "Begin_PoorKill_2";
		break;
		case "Begin_PoorKill_2":
			dialog.text = "Ха-ха, мне нравится ваша хватка!\nНу что же, для начала предлагаю познакомиться. Меня зовут " + GetFullName(npchar) + ". Простите, но я навел справки о вас и знаю, что вы - капитан " + GetFullName(pchar) + ". Также мне известно, что вы капер. Это так?";
			link.l1 = "Верно. Обо мне вы осведомлены хорошо. А кто же вы по роду своей деятельности?";
			link.l1.go = "Begin_PoorKill_3";
		break;
		case "Begin_PoorKill_3":
			dialog.text = "Я - деловой человек, скажем так.";
			link.l1 = "Прекрасно. И что за дело у вас ко мне?";
			link.l1.go = "Begin_PoorKill_4";
		break;
		case "Begin_PoorKill_4":
			dialog.text = "Да, собственно, пустяк для "+ GetSexPhrase("такого храброго человека","такой храброй девушки") +", как вы. Дело в том, что мой работодатель всерьез озаботился состоянием морали и нравственности на островах Карибского моря. Да-да, именно так!";
			link.l1 = "Рад"+ GetSexPhrase("","а") +" за вашего работодателя. Однако моралист из меня неважный...";
			link.l1.go = "Begin_PoorKill_5";
		break;
		case "Begin_PoorKill_5":
			dialog.text = "Зато 'санитар леса' будет прекрасный!";
			link.l1 = "О чем это вы? Повторюсь: ближе к делу, милейший...";
			link.l1.go = "Begin_PoorKill_6";
		break;
		case "Begin_PoorKill_6":
			dialog.text = "Ну, хорошо. Мне нужно, чтобы вы избавили нас от нищих и попрошаек в городах. Причем везде, в каждом городе, независимо от национальной принадлежности. За эту работу мы готовы вам заплатить миллион песо!";
			link.l1 = "Ты за кого меня принимаешь? За наемн"+ GetSexPhrase("ого","ую") +" убийцу?! Вали-ка отсюда, приятель, пока цел...";
			link.l1.go = "Begin_PoorKill_close";
		break;
		//воришка ключа 
		case "GiveKeyMan":
			dialog.text = "Что?";
			link.l1 = "Хм, послушай, это ты Мастер Ключей?";
			link.l1.go = "GiveKeyMan_1";
		break;
		case "GiveKeyMan_1":
			dialog.text = "Я. А ты кто так"+ GetSexPhrase("ой","ая") +"?";
			link.l1 = "Меня зовут капитан " + GetFullName(pchar) + ".";
			link.l1.go = "GiveKeyMan_2";
		break;
		case "GiveKeyMan_2":
			dialog.text = "И что тебе нужно, капитан " + GetFullName(pchar) + "?";
			link.l1 = "Послушай, это ты делал сундуки в доме губернатора Матиаса Бека? Хочу заказать себе такой же, с замком.";
			link.l1.go = "GiveKeyMan_3";
		break;
		case "GiveKeyMan_3":
			dialog.text = "Тот, что с замком, делал я. И могу сказать без преувеличений, что ты обратил"+ GetSexPhrase("ся","ась") +" по адресу. Я самый известный Мастер Ключей! Есть, правда, тезка у меня - узкоглазая падла, но он мне и в подметки не годится. Так что именно я и есть настоящий Мастер Ключей!";
			link.l1 = "Ну, отлично! Значит, вот что я желаю. Мне нужен точно такой же сундук, как у генерал-губернатора.";
			link.l1.go = "GiveKeyMan_4";
		break;
		case "GiveKeyMan_4":
			dialog.text = "Хех, одинаковые сундуки я не делаю - не мануфактура, знаешь ли! У меня каждое изделие - штучная работа. Да и где это видано, одинаковые замки ставить? Ведь ключи будут подходить.";
			link.l1 = "Знаешь, приятель, вот это и есть то самое, о чем я веду речь...";
			link.l1.go = "GiveKeyMan_5";
		break;
		case "GiveKeyMan_5":
			dialog.text = "Ха! Да ты "+ GetSexPhrase("непростой заказчик","непростая заказчица") +", как я погляжу...";
			link.l1 = "Вот именно, дружище!!! За непростой заказ - непростой гонорар...";
			link.l1.go = "GiveKeyMan_6";
		break;
		case "GiveKeyMan_6":
			dialog.text = "Непростой гонорар, говоришь?.. Я так понимаю, что тебе нужен только ключ.";
			link.l1 = "Именно так.";
			link.l1.go = "GiveKeyMan_7";
		break;
		case "GiveKeyMan_7":
			npchar.quest.price = makeint((sti(pchar.money)/4*3)/1000)*1000;
			if (sti(npchar.quest.price) > 10000)
			{
				dialog.text = "М-м... хорошо! Я хочу за этот ключ " + FindRussianMoneyString(sti(npchar.quest.price)) + ".";
				link.l1 = "Каррамба, неплохая цена!";
				link.l1.go = "GiveKeyMan_10";
			}
			else
			{
				dialog.text = "Хо-о-о, "+ GetSexPhrase("приятель, да ты голодранец","подруга, да ты голодранка") +"!!! О каких гонорарах с тобой можно говорить?! Знаешь, у кого ветер в карманах свищет, тот моим клиентом не является. И куда я раньше смотрел?";
				link.l1 = "Что это значит?!";
				link.l1.go = "GiveKeyMan_8";
			}
		break;
		case "GiveKeyMan_8":
			dialog.text = "Это значит, "+ GetSexPhrase("приятель","подруга") +", что даже мои обычные услуги тебе не по карману, не говоря уже о специальных. Приходи, как заработаешь пиастров, а сейчас не лезь ко мне.";
			link.l1 = "Ладно, найду тебя позже...";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toMasterKeysNoMoney";
			NextDiag.TempNode = "GiveKeyMan_NoMoney";
		break;
		case "GiveKeyMan_NoMoney":
			if (sti(pchar.money) >= 20000)
			{
				npchar.quest.price = makeint((sti(pchar.money)/5*4)/1000)*1000;
				dialog.text = "Ну вот, уже лучше, как говорится... Давай вернемся к нашему разговору о ключе. В общем, я готов его тебе сделать, предположим, за " + FindRussianMoneyString(sti(npchar.quest.price)) + ".";
				link.l1 = "Хе-хе, неплохо!!";
				link.l1.go = "GiveKeyMan_10";
			}
			else
			{
				dialog.text = "Даже и не лезь ко мне со своими предложениями. Ты как был"+ GetSexPhrase("","а") +" без гроша в кармане, так и остал"+ GetSexPhrase("ся","ась") +". Такие клиенты мне не нужны.";
				link.l1 = "Хм, подсоберу еще деньжат.";
				link.l1.go = "exit";
			}
		break;
		case "GiveKeyMan_10":
			dialog.text = "Мелочиться не привык. Сам"+ GetSexPhrase("","а") +" понимаешь, я же Мастер Ключей! В общем, раскошеливайся и дело с концом. Иначе никак!";
			link.l1 = "Хм, похоже, что деваться точно некуда... Слушай, а может, скинешь цену?";
			link.l1.go = "GiveKeyMan_11";
		break;
		case "GiveKeyMan_11":
			dialog.text = "Нет, "+ GetSexPhrase("приятель","подруга") +". Ты же сам"+ GetSexPhrase("","а") +" понимаешь, о чем просишь...";
			link.l1 = "Забирай. Где мой ключ?";
			link.l1.go = "GiveKeyMan_12";
			AddMoneyToCharacter(pchar, -sti(npchar.quest.price));
		break;
		case "GiveKeyMan_12":
			dialog.text = "Его надо изготовить. Приходи ко мне денька через два. Я живу в доме недалеко от лестницы в церковь.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
			SetTimerFunction("LSCC_openMasterHouse", 0, 0, 2);
			LocatorReloadEnterDisable("Villemstad_town", "houseSp5", true);
			npchar.location = "none";
			AddQuestRecord("ISS_PoorsMurder", "6");
		break;

		case "GiveKeyManInside":
			dialog.text = "Ага, вот и ты!";
			link.l1 = "Ага, вот и я! Где мой ключ?";
			link.l1.go = "GiveKeyManInside_1";
		break;
		case "GiveKeyManInside_1":
			dialog.text = "Ключ?.. Хм, ты знаешь, мне неприятно это говорить, но с тобой очень желает побеседовать генерал-губернатор.";
			link.l1 = "Ты что же, настучал, паршивец?!";
			link.l1.go = "GiveKeyManInside_2";
		break;
		case "GiveKeyManInside_2":
			dialog.text = "А как ты хотел"+ GetSexPhrase("","а") +"? Я же не враг сам себе... В общем, тут солдаты, они тебя проводят...";
			link.l1 = "Ах ты, паразит! Что ж ты тогда деньги брал?!";
			link.l1.go = "GiveKeyManInside_3";
		break;
		case "GiveKeyManInside_3":
			dialog.text = "За работу. Ключ-то я сделал, как и обещал. Я слово свое держу!";
			link.l1 = "Ну-ну...";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			AddDialogExitQuestFunction("LSCC_enterSoldiers");			
		break;
		//арестовывающий офицер
		case "MK_HollOfficer":
			dialog.text = "Пройдемте со мной, капитан!";
			link.l1 = "Куда это?";
			link.l1.go = "MK_HollOfficer_1";
		break;
		case "MK_HollOfficer_1":
			dialog.text = "В изолятор временного содержания. До выяснения, так сказать... И не вздумайте дурить, иначе я буду вынужден применить силу!";
			link.l1 = "Эх, офицер, вся беда в том, что и я буду вынужден"+ GetSexPhrase("","а") +" применить силу...";
			link.l1.go = "MK_HollOfficer_2";
		break;
		case "MK_HollOfficer_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Villemstad_houseSp5")], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//заказчик нищих в Мариго
		case "PKInMarigo":
			dialog.text = "Хм, я не планировал встречаться с вами еще раз! Вы уже выполнили задание? Проблемы с депозитом?";
			link.l1 = "Да нет, с депозитом все в порядке. Вы знаете, дело в том, что я никак не могу найти одного бродягу - Тизера Дэна.";
			link.l1.go = "PKInMarigo_1";
		break;
		case "PKInMarigo_1":
			dialog.text = "О нем можете не переживать, вы его уже не найдете. Позаботьтесь об остальных.";
			link.l1 = "Понятно... Ну а все-таки, где Тизер?";
			link.l1.go = "PKInMarigo_2";
		break;
		case "PKInMarigo_2":
			dialog.text = "Я что, неясно говорю? Тизер Дэн в заявочный список не входит. Вы понимаете меня?";
			link.l1 = "Понимаю, конечно. Но все-таки, очень хотелось бы узнать, где он.";
			link.l1.go = "PKInMarigo_3";
		break;
		case "PKInMarigo_3":
			dialog.text = "Что-то мне не нравится ваша настойчивость. Если будете продолжать в том же духе, то последуете прямиком за Тизером.";
			link.l1 = "Значит, он мертв...";
			link.l1.go = "PKInMarigo_4";
		break;
		case "PKInMarigo_4":
			dialog.text = "Мертвее не бывает. А теперь извольте объясниться относительно вашего любопытства!";
			link.l1 = "Хорошо. Я знаю, что вы являетесь представителем Голландской Вест-Индской компании в Карибском море. Знаю также, что вы ведете дела с губернатором Матиасом Беком. И еще я хочу знать, какого черта вам не угодили местные бродяги.";
			link.l1.go = "PKInMarigo_5";
		break;
		case "PKInMarigo_5":
			dialog.text = "А не слишком ли много вы хотите?";
			link.l1 = "Это еще не все мои вопросы к вам. Я хочу знать об Острове!";
			link.l1.go = "PKInMarigo_6";
		break;
		case "PKInMarigo_6":
			dialog.text = "Вы хоть понимаете, во что лезете, капитан? Плавайте себе на здоровье, щипайте отдельных торговцев - это не страшно. Но вот лезть в дела компании, которой принадлежит целый Индийский океан - это безумие.\n"+
				"Выполняйте взятые на себя обязательства, снимайте депозит - и продолжайте куролесить на здоровье, никто вас пальцем не тронет. А вот ваше любопытство очень быстро сведет вас в могилу. Я даю вам последний шанс, капитан, уйти отсюда с миром.";
			link.l1 = "Полагаю, что этим шансом я пользоваться не буду. Я хочу знать все еще и о предметах роскоши, падения цен на которые вы так опасаетесь...";
			link.l1.go = "PKInMarigo_7";
		break;
		case "PKInMarigo_7":
			dialog.text = "У-у-у, капитан, боюсь, что ваша песенка спета. Как говорил один мой знакомый, ныне покойный: 'Я слишком много знал...'.";
			link.l1 = "Ну и что ты сделаешь, хорёк вест-индский?";
			link.l1.go = "PKInMarigo_8";
		break;
		case "PKInMarigo_8":

			dialog.text = "Убью. Причем прямо сейчас!";
			link.l1 = "Панталоны не потеряй, когда убивать будешь...";
			link.l1.go = "PKInMarigo_9";
		break;
		case "PKInMarigo_9":
			chrDisableReloadToLocation = true; 
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_group_Attack(npchar, pchar);
			pchar.quest.PQ8_afterFight.win_condition.l1 = "NPC_Death";
			pchar.quest.PQ8_afterFight.win_condition.l1.character = "PoorKillSponsor";
			pchar.quest.PQ8_afterFight.win_condition = "OpenTheDoors";
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//мент в Протекторе
		case "LSCCQuestMent":
			dialog.text = "Ну, говори, что там у тебя за новости?";
			link.l1 = "Ты это о чем?";
			link.l1.go = "LSCCQuestMent_1";
		break;
		case "LSCCQuestMent_1":
			dialog.text = "Хватит прикидываться! Андре мне все рассказал о твоих намеках.";
			link.l1 = "Вот идиот!..";
			link.l1.go = "LSCCQuestMent_2";
		break;
		case "LSCCQuestMent_2":
			dialog.text = "Андре Лабор – законопослушный гражданин города. А вот тебе придется все мне рассказать о Тизере Дэне, иначе завтра тобой будет заниматься адмирал.";
			link.l1 = "Так он еще не знает? Да ведь это же прекрасно!.. Хм, боюсь, тебе придется умереть.";
			link.l1.go = "LSCCQuestMent_3";
		break;
		case "LSCCQuestMent_3":
			dialog.text = "Что?!! Андре, ко мне!";
			link.l1 = "Ха, так плотник на стреме? И это тоже превосходно!";
			link.l1.go = "LSCCQuestMent_4";
		break;
		case "LSCCQuestMent_4":
			AddQuestRecord("ISS_MainLine", "9");
			pchar.questTemp.LSCC = "afterFightInProtector";
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_SetWarriorTypeNoGroup(npchar);
			sld = characterFromId("AndreLabor");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//одиночный нарвал, которого надо замочить
		case "LSCCQuestNarval":
			dialog.text = "Что ты тут делаешь?!";
			link.l1 = "Я? Ну, как тебе сказать...";
			link.l1.go = "LSCCQuestNarval_1";
		break;
		case "LSCCQuestNarval_1":
			dialog.text = "Ты что, "+ GetSexPhrase("придурок","дуреха") +", не знаешь, что это - территория 'нарвалов'?";
			link.l1 = "Да знаю...";
			link.l1.go = "LSCCQuestNarval_2";
		break;
		case "LSCCQuestNarval_2":
			dialog.text = "Ты что, "+ GetSexPhrase("безумный","безумная") +", смерти ищешь?";
			link.l1 = "Ну, да... Только твоей смерти. Извини, приятель, но мне придется тебя убить.";
			link.l1.go = "LSCCQuestNarval_3";
		break;
		case "LSCCQuestNarval_3":
			AddQuestRecord("ISS_MainLine", "11");
			AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("ся","ась"));
			pchar.questTemp.LSCC = "toAdmNarvalRing";
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_SetWarriorTypeNoGroup(npchar);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		//--------------------------- дача брига Черная Горгулья --------------------------------
		//капитан брига Черная Горгулья
		case "BlueBirdCapitain":
			dialog.text = "Хотел бы я знать, кто ты так"+ GetSexPhrase("ой","ая") +"...";
			link.l1 = "Меня зовут " + GetFullName(pchar) + ". Я - капер.";
			link.l1.go = "BlueBirdCapitain_1";
		break;
		case "BlueBirdCapitain_1":
			dialog.text = "И какого дьявола ты напал"+ GetSexPhrase("","а") +" на мой бриг?!!";
			link.l1 = "Это заказ, я долж"+ GetSexPhrase("ен","на") +" пустить вас на дно. Уж слишком вы испортили отношения с торговцами...";
			link.l1.go = "BlueBirdCapitain_2";
		break;
		case "BlueBirdCapitain_2":
			dialog.text = "И это капер говорит?! Сам"+ GetSexPhrase("","а") +"-то ты тоже, небось, торговцев не жалуешь...";
			link.l1 = "Это работа, приятель, ничего личного. Ты мне вот что лучше скажи, как вы с Паскалем связь поддерживаете? Мне просто интересно, уж очень тяжело искать вас было.";
			link.l1.go = "BlueBirdCapitain_3";
		break;
		case "BlueBirdCapitain_3":
			dialog.text = "Не твое дело, каррамба! За небольшую передышку тебе спасибо, а теперь продолжим!";
			link.l1 = "Ну, хорошо...";
			link.l1.go = "BlueBirdCapitain_4";
		break;		
		case "BlueBirdCapitain_4":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogExitWithBattle(""); 
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;	
		//капитаны флейтов торговцев
		case "BlueBirdTrader":
			dialog.text = "Черт возьми, почему вы напали на нас?!!";
			link.l1 = "Это возмездие твоему хозяину, приятель. Против тебя я ничего не имею.";
			link.l1.go = "BlueBirdTrader_1";
		break;
		case "BlueBirdTrader_1":
			dialog.text = "Отрадно слышать...";
			link.l1 = "Сейчас берешь шлюпку, и с остатками команды можешь возвращаться к хозяину. Скажи, что " + GetFullName(pchar) + " передает ему привет.";
			link.l1.go = "BlueBirdTrader_2";
		break;
		case "BlueBirdTrader_2":
			dialog.text = "Привет передам обязательно.";
			link.l1 = "Тогда на этом все. Живи пока...";
			link.l1.go = "BlueBirdTrader_3";
		break;
		case "BlueBirdTrader_3":
			QuestAboardCabinDialogNotBattle(); 
            DialogExit();
		break;	
		//--------------------------- жемчужный промысел, Шарп --------------------------------
		//капитан Шарп, первый базар на палубе
		case "DeckSharp":	//на палубе
			dialog.text = ""+ GetSexPhrase("Здравствуй, приятель. Чему обязан за удовольствие видеть тебя на моем бриге","Хо-о, какие у нас гости! Чему обязан за удовольствие видеть тебя на моем бриге, прекрасная амазонка") +"?";
			link.l1 = "Приветствую капитана Бартоломью Шарпа! С трудом разыскал"+ GetSexPhrase("","а") +" тебя...";
			link.l1.go = "DeckSharp_1";
			npchar.quest.meeting = true;
			//блокировка генератора, если взят грабеж от Моргана
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("Приятель","Подруга") +", я сейчас занят! Ничем тебе помочь не могу. Без обид...";
				link.l1 = "Ну ладно, дружище...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "DeckSharp_1":
			dialog.text = "Да, это нелегко... Так что привело тебя ко мне"+ GetSexPhrase("",", красавица") +"?";
			link.l1 = "Ты знаешь, приятель, я хочу на жемчужные промыслы наведаться. Подзаработать, так сказать...";
			link.l1.go = "DeckSharp_2";
		break;
		case "DeckSharp_2":
			dialog.text = "О-о-о, родственная душа!!! Так какие проблемы? Наведывайся!";
			link.l1 = "Проблема в том, что я не знаю, где они промысел ведут. Они же очень скрытные и перемещаются постоянно! Вот, приш"+ GetSexPhrase("ел","ла") +" к тебе за советом как к специалисту в этом деле.";
			link.l1.go = "DeckSharp_3";
		break;
		case "DeckSharp_3":
			dialog.text = "Хм, да уж, ловцы жемчуга нынче хитрые пошли, голыми руками их не возьмешь\nНу что же, помогу тебе для первого раза, дам наводку на промысел.";
			link.l1 = "Эх, Шарп, дружище, спасибо тебе!";
			link.l1.go = "DeckSharp_4";
		break;
		case "DeckSharp_4":
			dialog.text = "Да чего уж там, не стоит благодарностей\nВ общем, слушай стратегию нашего дела. Итак, ловцы жемчуга ведут себя очень аккуратно, промышляют только у необитаемых островов или подальше от любопытных, так сказать\nПоэтому приходится брать их тепленькими, как раз, когда они в море и находятся!";
			link.l1 = "Слушай, а как ты узнаешь, где они ловят в данный момент?";
			link.l1.go = "DeckSharp_5";
		break;		
		case "DeckSharp_5":
			dialog.text = "Это мой большой секрет. Не скажу никому"+ GetSexPhrase("",", даже такой милашке, как ты") +", даже не проси!";
			link.l1 = "Хм, ну ладно, как знаешь...";
			link.l1.go = "DeckSharp_6";
		break;
		case "DeckSharp_6":
			GetPerlShore(); //где промысел ведется
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.Sharp.PearlAreal.add")) sTemp = pchar.questTemp.Sharp.PearlAreal.add; 
			dialog.text = "Значит, слушай. Есть на " + XI_ConvertString(pchar.questTemp.Sharp.PearlAreal + "Dat") + " место, под названием " + GetConvertStr(pchar.questTemp.Sharp.PearlAreal.Shore, "LocLables.txt") +
				sTemp + ". Если ты успеешь туда за " + FindRussianDaysString(sti(pchar.questTemp.Sharp.PearlAreal.terms)) + ", то ловцы жемчуга будут там.";
			link.l1 = "Понял"+ GetSexPhrase("","а") +". Спасибо тебе, Бартоломью.";
			link.l1.go = "DeckSharp_7";
		break;
		case "DeckSharp_7":
			dialog.text = RandPhraseSimple(""+ GetSexPhrase("Зови меня капитан Шарп! Мне так больше нравится","Для тебя - просто Барти, красавица") +".", ""+ GetSexPhrase("Я предпочитаю, чтобы меня называли капитан Шарп","Для такой милашки, как ты - просто Барти") +"!");
			link.l1 = "Хм, ясно. Спасибо тебе, "+ GetSexPhrase("капитан Шарп","Барти") +". Ты мне здорово помог!";
			link.l1.go = "DeckSharp_8";
		break;
		case "DeckSharp_8":
			dialog.text = RandPhraseSimple(""+ GetSexPhrase("Да не за что, приятель, ежели что - обращайся...","Обращайся еще, моя красавица. А может, как-нибудь встретимся, так сказать, в неофициальной обстановке?") +"",""+ GetSexPhrase("Помогать коллегам - священный долг, так сказать... Заходи еще, чем смогу - помогу!","Заходи еще, чем смогу - помогу. " + pchar.name + ", а может, продолжим наше общение...в другом, более уютном месте?") +"");
			link.l1 = ""+ GetSexPhrase("Всенепременно, капитан Шарп!!","Ты неисправимый ловелас, Барти. Еще увидимся!") +"";
			link.l1.go = "DeckSharp_8exit";
		break;	
		case "DeckSharp_8exit":
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.Sharp.PearlAreal.add")) sTemp = pchar.questTemp.Sharp.PearlAreal.add; 
			NextDiag.TempNode = "DeckSharp_over";
			npchar.DeckDialogNode = "NewDeckSharp"; //новая нода на палубу
			pchar.questTemp.Sharp = "toPearl"; //флаг квеста - на промысел!!!
			AddQuestRecord("SharpPearl", "5");
			AddQuestUserData("SharpPearl", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("SharpPearl", "sSex1", GetSexPhrase("Ой, капитана Шарпа!","Ловеласа Барти..."));
			AddQuestUserData("SharpPearl", "iDay", FindRussianDaysString(sti(pchar.questTemp.Sharp.PearlAreal.terms)));
			AddQuestUserData("SharpPearl", "sAreal", XI_ConvertString(pchar.questTemp.Sharp.PearlAreal + "Dat"));
			AddQuestUserData("SharpPearl", "sTarget", GetConvertStr(pchar.questTemp.Sharp.PearlAreal.Shore, "LocLables.txt") + sTemp);
			pchar.quest.SeaPearl_login.win_condition.l1 = "location";
			pchar.quest.SeaPearl_login.win_condition.l1.location = pchar.questTemp.Sharp.PearlAreal.Island;
			pchar.quest.SeaPearl_login.function = "SeaPearl_login";
			SetTimerFunction("SeaPearl_Late", 0, 0, sti(pchar.questTemp.Sharp.PearlAreal.terms));
			if (pchar.location != "Deck_Near_Ship")
			{
				LAi_SetActorTypeNoGroup(npchar);
				LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 15.0);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//капитан Шарп, последующие разговоры на палубе
		case "NewDeckSharp":
			dialog.text = "О-о-о, кого я вижу?! Приветствую "+ GetSexPhrase("единомышленника","тебя, красавица") +"!";
			link.l1 = "Здравствуй, капитан Шарп. Как поживаешь?";
			link.l1.go = "NewDeckSharp_1";
			//блокировка генератора, если взят грабеж от Моргана
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("Приятель","Подруга") +", я сейчас занят! Ничем тебе помочь не могу. Без обид...";
				link.l1 = "Ну ладно, дружище...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "NewDeckSharp_1":
			dialog.text = "Да все путем, "+ GetSexPhrase("приятель","дорогуша") +", жаловаться грех\nНу, рассказывай, зачем пожаловал"+ GetSexPhrase("","а") +" на этот раз?";
			link.l1 = "Да все за тем же, приятель, за наводкой на промыслы...";
			link.l1.go = "NewDeckSharp_2";
		break;
		case "NewDeckSharp_2":
			if (pchar.questTemp.Sharp.SeekSpy == "alwaysKnow" || pchar.questTemp.Sharp.SeekSpy == "over")
			{
				dialog.text = "Ты знаешь, "+ GetSexPhrase("приятель","дорогуша") +", у меня с этим делом проблемы. Пропал у меня один доверенный человек из команды, а с ним... Ну, в общем, не знаю я, где ловцы.";
				link.l1 = "М-да, печально... Ну что же, такова жизнь. Прощай, Шарп.";
				link.l1.go = "exit";
				CloseQuestHeader("SharpPearl");
				NextDiag.TempNode = "DeckSharp_noWork";
				pchar.questTemp.Sharp = "over";
			}
			else
			{
				dialog.text = "Хм, дело это, конечно, хорошее. Но я не могу использовать свой ресурс на тебя,  "+ GetSexPhrase("приятель,","красотка,") +" мне самому жить надо!";
				link.l1 = "Какой ресурс использовать?";
				link.l1.go = "NewDeckSharp_3";
			}
		break;
		case "NewDeckSharp_3":
			dialog.text = "Обыкновенный. "+ GetSexPhrase("Не твое дело, собственно","Не любопытствуй, все равно не скажу") +".\nВ общем, я тебе наводку дать могу, но не просто так. Ты долж"+ GetSexPhrase("ен","на") +" будешь мне компенсировать упущенную выгоду, "+ GetSexPhrase("приятель","дорогуша") +".";
			link.l1 = "Хм, ну и сколько ты хочешь?";
			link.l1.go = "NewDeckSharp_4";
		break;
		case "NewDeckSharp_4":
			dialog.text = "Ну, полагаю, что сумма в " + FindRussianMoneyString(sti(pchar.questTemp.Sharp.price)) + " меня устроит.";
			link.l1 = "Эй, друг капитан Шарп, что за дела? Это слишком много для меня на данный момент! Будь другом, сбрось цену.";
			link.l1.go = "NewDeckSharp_noMoney";
			if (sti(pchar.money) >= sti(pchar.questTemp.Sharp.price))
			{
				link.l2 = "Ну что же, я соглас"+ GetSexPhrase("ен","на") +", приятель. Забирай свою компенсацию!";
				link.l2.go = "NewDeckSharp_GiveMoney";
			}
		break;

		case "NewDeckSharp_GiveMoney":
			dialog.text = "Ну, вот и ладушки! Такой подход мне по душе, "+ GetSexPhrase("приятель","дорогуша") +".";
			link.l1 = "Это здорово. Так что там с наводкой?";
			link.l1.go = "DeckSharp_6";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharp.price));
		break;
		case "NewDeckSharp_noMoney":
			if ((sti(pchar.questTemp.Sharp.price)*10) < sti(pchar.money))
			{
				if (pchar.location == "Deck_Near_Ship")
				{			
					dialog.text = ""+ GetSexPhrase("Алле Хагель! Ты чего, " + pchar.name + ", лоха нашел?! Я те не сявка лямой, а КАПИТАН ШАРП!! Звучит гордо, понял?! Думаешь, я не знаю, что денег у тебя прилично имеется? Знаю, приятель, это мне прекрасно известно. Так что, давай, раскошеливайся или вали с моей палубы на все четыре стороны относительно зюйд-веста!","Алле Хагель! " + pchar.name + ", ты, конечно, деваха красивая и боевая, однако и я не сявка лямой, а КАПИТАН ШАРП! Звучит гордо! Думаешь, я не знаю, что денег у тебя прилично имеется? Знаю, дорогуша, это мне прекрасно известно. У нас с тобой деловые отношения...кхм, жаль, однако, что только деловые. В общем, или раскошеливайся, или ищи ныряльщиков самостоятельно") +"..";
					link.l1 = ""+ GetSexPhrase("Бартоломью, ты чего завелся?! Скрипишь, как рангоут... Я к тебе не клотик пришел швабрить и не якорь точить. Так что ты аккуратней в выражениях. Помни, с кем разговариваешь","Бартоломью, ты чего раздухарился? Ты это, аккуратнее в выражениях, я тебе не какая-нибудь там девка бордельная, не забывай этого") +"...";
				}
				else
				{
					dialog.text = ""+ GetSexPhrase("Че-то я не понял, ты меня за лоха держишь? Ты чего меня лечишь, думаешь, я не знаю, что денег у тебя прилично имеется? Знаю, приятель, это мне прекрасно известно. Так что, давай, раскошеливайся или ищи ловцов жемчуга где-нибудь на зюйд-зюйд-ост отсюда, к примеру","Эй, " + pchar.name + ", ты что, меня развести пытаешься? Ты что, думаешь, я не знаю, что денег у тебя прилично имеется? Знаю, красавица, это мне прекрасно известно. У нас с тобой деловые отношения... по крайней мере, пока. Так что, или делись со мной, ищи ловцов жемчуга где-нибудь на зюйд-зюйд-ост отсюда, к примеру") +"...";
					link.l1 = "Бартоломью, ты не заводись, а то скрипишь, как рангоут. Помни, с кем разговариваешь...";
				}
				link.l1.go = "NewDeckSharp_5";
			}
			else
			{
				if (sti(pchar.questTemp.Sharp.price.evil))
				{	//Шарп не в настроении
					dialog.text = "Нет, "+ GetSexPhrase("приятель","дорогуша") +", только не сегодня! У меня самого дела идут неважно, а тут еще ты со своими просьбами. В меценаты я не записывался. Деньги на бочку, в общем...";
					link.l1 = "М-да, жаль, Шарп, очень жаль. Я думал"+ GetSexPhrase("","а") +", ты настоящий друг...";
					link.l1.go = "NewDeckSharp_7";
					if (sti(pchar.money) >= sti(pchar.questTemp.Sharp.price))
					{
						link.l2 = "Да, деваться некуда. Но уж больно мне жемчуга не хватает для полного карибского счастья... Забирай свою компенсацию!";
						link.l2.go = "NewDeckSharp_GiveMoney";
					}
				}
				else
				{
					dialog.text = "Ну ладно, так уж и быть, сегодня я добрый чего-то не в меру... Помогу тебе!";
					link.l1 = "Вот это правильно! Вот это по-берегово-братски!.. Так что там с наводкой, благодетель Шарп?";
					link.l1.go = "DeckSharp_6";
				}
			}
		break;
		case "NewDeckSharp_5":
			dialog.text = "Ладно, извини, погорячился. Однако, это сути дела не меняет. Не надо быть так"+ GetSexPhrase("им","ой") +" скрягой, " + pchar.name + ", это плохо отражается на цвете лица... В общем, деньги на бочку, или наводки ты не получишь.";
			link.l1 = "Ну хорошо, забирай свою компенсацию!";
			link.l1.go = "NewDeckSharp_6";
			link.l2 = "Не-е, окажусь я от этого дела. Потом как-нибудь...";
			link.l2.go = "NewDeckSharp_7";
		break;
		case "NewDeckSharp_6":
			dialog.text = "Ну вот, это другое дело! Уважаю капитана, коллегу и соратни"+ GetSexPhrase("ка","цу") +"!"+ GetSexPhrase(""," И вообще, просто замечательную женщину!") +"";
			link.l1 = "Взаимно, Шарп, взаимно. Ну, так что там с наводкой?";
			link.l1.go = "DeckSharp_6";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharp.price));
		break;
		case "NewDeckSharp_7":
			dialog.text = "Ну, как знаешь. Прощай!";
			link.l1 = "Всего хорошего...";
			link.l1.go = "NewDeckSharp_7exit";
		break;
		case "NewDeckSharp_7exit":
			AddQuestRecord("SharpPearl", "10");
			CloseQuestHeader("SharpPearl");
			pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
			pchar.questTemp.Sharp.brothelChance = rand(10);
			NextDiag.TempNode = "DeckSharp_overBad";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			if (pchar.location != "Deck_Near_Ship")
			{
				LAi_SetActorTypeNoGroup(npchar);
				LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 15.0);
			}
		break;

		case "DeckSharp_over":
			dialog.text = "Мы все обсудили, "+ GetSexPhrase("приятель","подруга") +". На твоем месте я бы не стал терять времени.";
			link.l1 = "Да, капитан Шарп.";
			link.l1.go = "exit";
		break;
		case "DeckSharp_overBad":
			dialog.text = "Поговорили уже...";
			link.l1 = "Да уж...";
			link.l1.go = "exit";
		break;
		case "DeckSharp_noWork":
			dialog.text = "Ничем не могу помочь, "+ GetSexPhrase("дружище","дорогуша") +". Сам страдаю без дела. Теперь придется опять за галеонами гоняться...";
			link.l1 = "Ну, с возвращением, приятель!";
			link.l1.go = "exit";
			CloseQuestHeader("SharpPearl");
		break;
		//капитан Шарп, первый разговор в городе на улице
		case "CitySharp":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "А-а-а, капитан " + pchar.lastname + "! Слушаю тебя внимательно.";
				link.l1 = "Бартоломью, я так рад"+ GetSexPhrase("","а") +" встрече! Пришлось тебя поискать, но в этом городе повезло...";
				link.l1.go = "CitySharp_1";
				npchar.quest.meeting = true;
			}
			else
			{
				dialog.text = "Ох, кого я вижу в этом городе?! Это же "+ GetSexPhrase("капитан " + pchar.lastname + ", мой соратник и единомышленник","" + pchar.name + ", моя соратница и единомышленница! Ты прекрасна, как никогда") +"!";
				link.l1 = "Да, Бартоломью, это я"+ GetSexPhrase(" собственной персоной",". Спасибо за комплимент") +".";
				link.l1.go = "CitySharp_2";
			}
		break;

		case "CitySharp_1":
			dialog.text = "Так, чему обязан за такое внимание?";
			link.l1 = "Понимаешь, я тут собрал"+ GetSexPhrase("ся","ась") +" наведаться на жемчужные промыслы, а ты в этом деле признанный специалист.";
			link.l1.go = "DeckSharp_2";
		break;
		case "CitySharp_2":
			dialog.text = ""+ GetSexPhrase("Эх, дружище, рад тебя видеть! Ну что, начнем, пожалуй... Сначала в кабак, потом по девкам. Ты каких предпочитаешь, мулаток или белых? У меня тут такие связи - закачаешься","Э-э-х, " + pchar.name + ", когда я вижу тебя, у меня сердце аж замирает") +"!";
			link.l1 = "Слушай, "+ GetSexPhrase("Шарп","Бартоломью") +", мне сейчас не до "+ GetSexPhrase("этого","лирики") +", извини. Я по делу к тебе.";
			link.l1.go = "CitySharp_3";
			//блокировка генератора, если взят грабеж от Моргана
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("Приятель","Дорогуша") +", я сейчас занят! Ничем тебе помочь не могу. Без обид...";
				link.l1 = "Ну ладно, дружище...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "CitySharp_3":
			dialog.text = "Ну-у-у, "+ GetSexPhrase("так не интересно","вот так всегда") +"... А что за дело?";
			link.l1 = "Да вот, решил"+ GetSexPhrase("","а") +" избавить ловцов жемчуга от лишнего...";
			link.l1.go = "NewDeckSharp_2";
		break;
		//капитан Шарп в борделе
		case "BrothelSharp":
			dialog.text = ""+ GetSexPhrase("О-о-о, " + pchar.lastname + ", дружище!! Пойдем со мной наверх, там так весело!!!","О-о-о, " + pchar.name + ", это ты, красавица? Ну вот, теперь я опять буду целую неделю думать только о тебе...") +"";
			link.l1 = ""+ GetSexPhrase("Нет, приятель, сейчас не могу, занят.","Да ладно тебе, Бартоломью, неделю он думать будет..") +". Я к тебе по делу";
			link.l1.go = "BrothelSharp_1";
			//блокировка генератора, если взят грабеж от Моргана
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("Приятель","Дорогуша") +", я сейчас занят! Ничем тебе помочь не могу. Без обид...";
				link.l1 = "Ну ладно, дружище...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "BrothelSharp_1":
			dialog.text = ""+ GetSexPhrase("Говори...","Эх, правду тебе говорю, " + pchar.name + ". Ну ладно, что там у тебя?") +"";
			link.l1 = "Хочу опять наведаться к ловцам жемчуга, потрясти их немного.";
			link.l1.go = "NewDeckSharp_2";
		break;
		//Эмилио Гарсиа. в бухте Сан-Хуна дель Норте
		case "SharpSeekSpy_Emi":
			dialog.text = "Дьявол, нас подслушивают!!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog");
		break;
		case "SharpSeekSpy_fri":
			dialog.text = "А-а-а, да это же капитан " + pchar.lastname + "! Вот уж не ожидал вас здесь увидеть...";
			link.l1 = "Хех, сюрприз! А я тебя знаю, приятель?";
			link.l1.go = "SharpSeekSpy_fri_1";
		break;
		case "SharpSeekSpy_fri_1":
			dialog.text = "Ну, как сказать... Вы, может быть, меня не заприметили, но я вас запомнил хорошо, когда вы посещали наш бриг 'Шарпоносец'.";
			link.l1 = "Ха! Так ты из команды Шарпа?! Значит, я прибыл"+ GetSexPhrase("","а") +" точно по адресу.";
			link.l1.go = "SharpSeekSpy_fri_2";
		break;
		case "SharpSeekSpy_fri_2":
			dialog.text = "Не понимаю смысла сказанного, капитан.";
			link.l1 = "Понимаешь, приятель, мне было очень интересно узнать, где же Шарп наводки берет на тартаны ловцов. Теперь узнал"+ GetSexPhrase("","а") +".";
			link.l1.go = "SharpSeekSpy_fri_3";
		break;
		case "SharpSeekSpy_fri_3":
			dialog.text = "Капитан, за эту тайну Шарп может и убить...";
			link.l1 = "Ага, и тут я "+ GetSexPhrase("наложил в штаны","испугалась") +". К тому же эту тайну очень хочет знать кое-кто на жемчужных промыслах...";
			link.l1.go = "SharpSeekSpy_fri_4";
		break;
		case "SharpSeekSpy_fri_4":
			dialog.text = "И кто же этот любитель тайн?";
			link.l1 = "М-м-м...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog_2");
		break;
		case "SharpSeekSpy_Emi_1":
			dialog.text = "А что, не ясно? Конечно, кто-то из офицеров!\nКороче, надо мочить "+ GetSexPhrase("его","ее") +". За дело...";
			link.l1 = "Ну, попробуйте...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog_3");
		break;


		//несчастный мушкетер
		case "OffMushketer":
			dialog.text = "Приветствую "+ GetSexPhrase("гостя","прекрасную гостью") +" в моем доме. Что вы хотели здесь?";
			link.l1 = "Познакомиться. Меня зовут капитан " + GetFullName(pchar) + ".";
			link.l1.go = "OffM_1";
		break;
		case "OffM_1":
			dialog.text = "Рад знакомству, капитан. Чем я могу вам помочь?";
			link.l1 = "Да так, ничем особенным... А вы по виду человек военный. Еще на службе состоите?";
			link.l1.go = "OffM_2";
		break;
		case "OffM_2":
			dialog.text = "Уже нет, уволен.";
			link.l1 = "Понятно. А кем были в армии?";
			link.l1.go = "OffM_4";
		break;
		case "OffM_4":
			dialog.text = "Мушкетером. Я был лучшим стрелком в полку!";
			link.l1 = "Ха, такие люди мне нужны. Не желаете пойти служить офицером ко мне в команду?";
			link.l1.go = "OffM_5";
		break;
		case "OffM_5":
			dialog.text = "Спасибо за предложение, но вынужден отказаться.";
			link.l1 = "Скажите, а почему? Если не секрет, конечно...";
			link.l1.go = "OffM_6";
		break;
		case "OffM_6":
			dialog.text = "Все дело в психической травме. Не могу брать в руки оружие!";
			link.l1 = "Странно все это. А как же вы воевали в армии?";
			link.l1.go = "OffM_7";
		break;
		case "OffM_7":
			dialog.text = "Понимаете, мне в свое время достался французкий мушкетон, каких мало. Два ствола, усовершенствованная казенная часть, позволяющая заряжать быстрее. В общем, настоящее произведение искусства, работа мастера.\n"+
				"И так я к этому оружию привязался, что другого ничего не признаю.";
			link.l1 = "И где этот чудо-мушкетон сейчас?";
			link.l1.go = "OffM_8";
		break;
		case "OffM_8":
			dialog.text = "Эх-х, даже вспоминать больно... Когда я плыл сюда из Старого Света, на нас напали пираты. Я хотел открыть по ним огонь, и поверьте мне, уложил бы немало этих головорезов. Но наша же команда набросилась на меня и скрутила!..";
			link.l1 = "Поверь мне, они поступили правильно. Вы хотя бы остались живы.";
			link.l1.go = "OffM_9";
		break;
		case "OffM_9":
			dialog.text = "Жив, но без моего мушкетона! А что это за жизнь!..";
			link.l1 = "Ну, может другой найдется, подобный...";
			link.l1.go = "OffM_10";
		break;
		case "OffM_10":
			dialog.text = "Найдется?.. Хм, послушайте, если вы найдете мой двуствольный мушкетон, то я пойду к вам в офицеры. Обещаю.";
			link.l1 = "Ну что же, я вас понял"+ GetSexPhrase("","а") +". А кто захватил ваш корабль, когда это было?";
			link.l1.go = "OffM_11";
		break;
		case "OffM_11":
			dialog.text = "Было это уже пару лет назад, с тех пор и маюсь. Кто были те пираты - я не видел, лежал связанным с мешком на голове. Команда о какой-то стреле вопила, но что это такое - мне не известно.";
			link.l1 = "М-да, ситуация... Ну что же, как говорится, будем искать. Если мне ваш мушкетон попадется, то обязательно принесу его сюда.";
			link.l1.go = "OffM_12";
		break;
		case "OffM_12":
			dialog.text = "Спасибо вам. Буду ждать с нетерпением.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
		                sld = characterFromId("Torus");
		                sld.dialog.currentnode = "Mushket";
			pchar.questTemp.mushkett2x2 = true;
			AddQuestRecord("SeekDoubleMushket", "1");
			NextDiag.TempNode = "OffM_result";	
		break;

		case "OffM_result":
			dialog.text = "Вы нашли мой мушкетон?";
			if (CheckCharacterItem(pchar, "mushkett2x2"))
			{
				link.l1 = "Да...? Нет...?, дружище, наш"+ GetSexPhrase("ел","ла") +". Но, вот есть, одноствольный мушкет, тоже не плохой?";
				link.l1.go = "OffM_result_1";
			}
			else
			{
				link.l1 = "Нет еще. Но я занимаюсь этим.";
				link.l1.go = "exit";
			}
		break;

		case "OffM_result_1":
			dialog.text = "Ну, давай!";
			link.l1 = "Вот возьми фитильный мушкет. Теперь я жду исполнения вашего обещания стать моим офицером.";
			link.l1.go = "mushket1";
			link.l2 = "Вот возьми свой мушкетон. Теперь я жду исполнения вашего обещания стать моим офицером.";
			link.l2.go = "mushkett2x2";
		break;

		case "mushket1":
			dialog.text = "Хм...";
			link.l1 = "Что-то не так?";
			link.l1.go = "exit_hire1";
			PlaySound("interface\important_item.wav");
			TakeItemFromCharacter(pchar, "mushket1");
			Npchar.quest.OfficerPrice = sti(pchar.rank)*300;
		break;

		case "mushkett2x2":
			dialog.text = "Да, это он! Спасибо, кэп!";
	link.l1 = "Пожалуйста, что насчёт поступления на службу?";
			link.l1.go = "OffM_result_2";
			PlaySound("interface\important_item.wav");
			TakeItemFromCharacter(pchar, "mushkett2x2");
			Npchar.quest.OfficerPrice = sti(pchar.rank)*300;
		break;

		case "exit_hire1":
			dialog.text = "Нет, с таким оружием я воевать не буду, так что удачи тебе и не забывай смазывать почаще моё ружьё.";
			link.l1 = "Дело твоё, было бы предложено.";
			link.l1.go = "exit_hire2";
		break;

		case "exit_hire2":
			AddQuestRecord("SeekDoubleMushket", "3_1");
			CloseQuestHeader("SeekDoubleMushket");
			dialog.text = "Всего хорошего.";
			link.l1 = "И тебе не хворать.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "OffM_result_2":
			dialog.text = "Мое слово железное. Я готов. Только давайте обсудим размер моего гонорара. За свою верную службу я хочу получать " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " в месяц.";
			link.l1 = "А вам не кажется, что это чересчур?";
			link.l1.go = "OffM_trade";
			link.l1 = "Ну, хорошо, я соглас"+ GetSexPhrase("ен","на") +".";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_trade":
			dialog.text = "Нет, я стою гораздо больше.";
			link.l1 = "Ну, хорошо, я соглас"+ GetSexPhrase("ен","на") +".";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_Ok":
			Npchar.quest.OfficerPrice.add = sti(pchar.rank)*1000;
			dialog.text = "Хорошо. Но это еще не все. Я требую единовременного пособия, так сказать. Поиздержался без работы, вот и надо оплатить долги. Думаю, что " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " меня устроят.";
			link.l1 = "Чего?!!";
			link.l1.go = "OffM_Ok_1";
		break;
		case "OffM_Ok_1":
			dialog.text = "Того! И никак иначе... В общем, решайте.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "Нет у меня таких денег.";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "Это очень дорого для меня.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "Хорошо, я соглас"+ GetSexPhrase("ен","на") +".";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
		case "OffM_noMoney":
			dialog.text = "Значит, приходите, как разбогатеете. Удачи.";
			link.l1 = "Спасибо...";
			link.l1.go = "exit";
		break;
		case "OffM_Ok_3":
			dialog.text = "Вот, теперь совсем другое дело! Я готов вам служить верой и правдой.";
			link.l1 = "Отлично. Добро пожаловать в команду.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			AddQuestRecord("SeekDoubleMushket", "3");
			CloseQuestHeader("SeekDoubleMushket");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "MusketeerEnglish_2";
			npchar.model.animation = "mushketer";
			npchar.MusketerDistance = 5;
			npchar.greeting = "Gr_questOfficer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;

			GiveItem2Character(npchar, "mushkett2x2");
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			GiveItem2Character(npchar, "spyglass1");
			EquipCharacterByItem(npchar, "spyglass1");
			GiveItem2Character(npchar, "cirass6");
			EquipCharacterByItem(npchar, "cirass6");
			AddItems(chr, "grapeshot", 	100);
			AddItems(chr, "gunpowder", 	100);
			LAi_SetCharacterUseBullet(npchar, "grapeshot");  
			TakeNItems(npchar, "potion2", 5);

			DialogExit();
		break;
		case "OffM_TWO":
			dialog.text = "Ну что, как там у вас дела с финансами? Напомню, что я хочу " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " единовременного пособия и " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " ежемесячного заработка.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "Нет, не потяну пока...";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "Это очень дорого для меня.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "Хорошо, я соглас"+ GetSexPhrase("ен","на") +".";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
	}
}


void GetPerlShore()
{	
	switch (rand(4))
	{
		case 0:
			pchar.questTemp.Sharp.PearlAreal = "Mein";
			pchar.questTemp.Sharp.PearlAreal.Island = "Beliz";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore_ship2";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_8";
			pchar.questTemp.Sharp.PearlAreal.add = ". Это рядом с Белизом";
			break;
		case 1:
			pchar.questTemp.Sharp.PearlAreal = "Mein";
			pchar.questTemp.Sharp.PearlAreal.Island = "Cumana";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore18";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_8";
			pchar.questTemp.Sharp.PearlAreal.add = ". Это рядом с Куманой";
			break;
		case 2:
			pchar.questTemp.Sharp.PearlAreal = "Dominica";
			pchar.questTemp.Sharp.PearlAreal.Island = "Dominica";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore26";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_3";
			break;
		case 3:
			pchar.questTemp.Sharp.PearlAreal = "Terks";
			pchar.questTemp.Sharp.PearlAreal.Island = "Terks";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore56";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_1";
			break;
		case 4:
			pchar.questTemp.Sharp.PearlAreal = "Caiman";
			pchar.questTemp.Sharp.PearlAreal.Island = "Caiman";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore17";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_1";
			break;
	}
	pchar.questTemp.Sharp.PearlAreal.terms = rand(5) + 5; //сроки
	pchar.questTemp.Sharp.PearlAreal.qtyShips = rand(6) + 6; //кол-во тартан ловцов
	pchar.questTemp.Sharp.PearlAreal.SmallPearlQty = 0; //для итогового подсчета
	pchar.questTemp.Sharp.PearlAreal.BigPearlQty = 0;
}

void SetSeekCapCitizenParam(ref npchar, int iNation)
{
	//создаем кэпов
	int Rank = sti(pchar.rank) + 5;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("SeekCitizCap_" + npchar.index, "", "man", "man", Rank, iNation, -1, true));
	switch (npchar.quest.SeekCap)
	{
		case "manSlave": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "CitizCap";
			sld.DeckDialogNode = "CitizCap_inDeck";
		break;
		case "manRapeWife": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "RapeWifeCap";
			sld.DeckDialogNode = "RapeWifeCap_inDeck";
		break;
		case "manFriend": 
			SetCaptanModelByEncType(sld, "trade");
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			sld.dialog.currentnode = "FriendCap";
			sld.DeckDialogNode = "FriendCap_inDeck";
		break;
		case "womanHasband": 
			SetCaptanModelByEncType(sld, "trade");
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			sld.dialog.currentnode = "HasbandCap";
			sld.DeckDialogNode = "HasbandCap_inDeck";
		break;
		case "womanRevenge": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "RevengeCap";
			sld.DeckDialogNode = "RevengeCap_inDeck";
		break;
		case "womanPirates": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "PiratesCap";
			sld.DeckDialogNode = "PiratesCap_inDeck";
		break;
	}
	sld.dialog.filename = "Quest\ForAll_dialog.c";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.DontRansackCaptain = true; //не сдаваться
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	//в морскую группу кэпа
	string sGroup = "SeekCapShip_" + sld.index;
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	//записываем данные в структуры портмана и кэпа
	npchar.quest.SeekCap.capId = sld.id //Id искомого кэпа
	npchar.quest.SeekCap.capName = GetFullName(sld); //имя искомого кэпа
	npchar.quest.SeekCap.shipName = sld.Ship.name; //имя украденного корабля
	npchar.quest.SeekCap.shipTapeName = RealShips[sti(sld.Ship.Type)].BaseName; //название украденного корабля
	npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1) * 1000) + (sti(pchar.rank)*500); //вознаграждение
	npchar.quest.gem = GenQuestCitizen_GenerateGem(); //камешки
	sld.quest = "InMap"; //личный флаг искомого кэпа
	sld.quest.SeekCap = npchar.quest.SeekCap; //запишем кэпу флаг квеста
	sld.quest.nation = iNation; //запомним базовую нацию кэпа
	sld.city = SelectAnyColony(npchar.city); //определим колонию, откуда кэп-вор выйдет
	sld.quest.targetCity = SelectAnyColony2(npchar.city, sld.city); //определим колонию, куда он придет
	Log_TestInfo("Разыскиваемый кэп " + sld.id + " вышел из: " + sld.city + " и направился в: " + sld.quest.targetCity);
	sld.quest.cribCity = npchar.city; //город, где ошивается квестодатель
	//==> на карту
	sld.mapEnc.type = "trade";
	//выбор типа кораблика на карте
	switch (npchar.quest.SeekCap)
	{
		case "manSlave":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manRapeWife":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manFriend":	 sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanHasband": sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanRevenge": sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "womanPirates": sld.mapEnc.worldMapShip = "Galleon_red"; break;
	}
	sld.mapEnc.Name = XI_ConvertString(npchar.quest.SeekCap.shipTapeName) + " '" + npchar.quest.SeekCap.shipName + "'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //дней доехать даем с запасом
	Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, daysQty);
	//прерывание на смерть кэпа
	string sTemp = "SCQ_" + sld.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = sld.id;
	pchar.quest.(sTemp).function = "SCQ_seekCapIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	//прерывание на смерть квестодателя
	sTemp = "SCQ_" + npchar.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = npchar.id;
	pchar.quest.(sTemp).function = "SCQ_CitizenIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	pchar.quest.(sTemp).CitizenId = npchar.id;
	//заносим Id кэпа в базу нпс-кэпов
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "citizen"; //идентификатор квеста
	NullCharacter.capitainBase.(sTemp).questGiver = npchar.id; //запомним Id квестодателя для затирки в случае чего
	NullCharacter.capitainBase.(sTemp).Tilte1 = sld.quest.cribCity + "SCQ_" + npchar.quest.SeekCap; //заголовок квестбука
	NullCharacter.capitainBase.(sTemp).Tilte2 = "SCQ_" + npchar.quest.SeekCap; //имя квеста в квестбуке
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

string GenQuestCitizen_GenerateGem() // камни
{
	string itemID;
	switch(rand(5))
	{
		case 0:
			itemID = "jewelry1";	
		break;
		case 1:
			itemID = "jewelry2"; 
		break;
		case 2:
			itemID = "jewelry3"; 
		break;
		case 3:
			itemID = "jewelry4"; 
		break;
		case 4:
			itemID = "jewelry5"; 
		break;
		case 5:
			itemID = "jewelry17"; 
		break;
	}
	return itemID;
}