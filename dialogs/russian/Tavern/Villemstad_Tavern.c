// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Все сплетни города "+ GetCityName(npchar.city) +" к вашим услугам. Что бы вы хотели узнать?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Что ты заладил как попугай одно и то же...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, забыл" + GetSexPhrase("","а") + " что-то...",
                      "Да уж, действительно в третий раз...", "Да уж...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "Слышал"+ GetSexPhrase("","а") +", у вас на острове заваруха была серьезная... Рабы, вроде, восстали.";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "Слышал, что гнусный негодяй - Барт Португалец - наконец-таки попался в руки правосудия! Он у вас в тюрьме? А когда состоится его казнь, не в курсе? Я бы пришел посмотреть, у меня с этим мерзавцем свои счеты...";
                link.l1.go = "Portugal";
            }
	                                      // ==> Мистер и Мисси Смит
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "Smithy_DouwesenTavern" && !CheckAttribute(npchar, "quest.Smithy_DouwesenTavern"))
			{
				dialog.text = "Я слушаю тебя.";
				link.l1 = "Мне нужна некто Крошимер Говард, где я могу её найти?";
				link.l1.go = "Smithy";
			}

			// Винсент Венто
			if(CheckAttribute(pchar, "questTemp.vento") && pchar.questTemp.vento == "start")
			{
				link.l2 = "Ты случайно не помнишь офицера, который заходил недавно в таверну?";
				link.l2.go = "OfficerVinsentVento_1";
			}
			
			if(CheckAttribute(pchar, "questTemp.vento") && pchar.questTemp.vento == "Have_documents" && !CheckAttribute(NPChar, "OfficerVinsentVento"))
			{
				link.l2 = "Слушай, а ты не знаешь, кто из местных тут неплохо рисует?";
				link.l2.go = "OfficerVinsentVento_4";
			}


			// ==> Проверяем поле состояния квестов.
			switch(pchar.questTemp.State)
			{
			case "Intelligence_Curacao_tavern":
				link.l1 = "Послушай, мне нужно узнать кое-что...";
				link.l1.go = "Step_E4_1";
				break;
			case "Intelligence_Curacao_dWant_pay_tavern":
				dialog.text = "Созрел" + GetSexPhrase("","а") + "?";
				link.l1 = "Созрел" + GetSexPhrase("","а") + ". Держи свою тысячу.";
				link.l1.go = "E4_OK_pay";
				link.l2 = "Тысячу монет за два слова?! Это слишком много!";
				link.l2.go = "E4_dWant_pay";
				break;
			case "Intelligence_Curacao_NoMoney_tavern":
				dialog.text = "Подкопил" + GetSexPhrase("","а") + " деньжат?";
				link.l1 = "Да, вроде бы, подкопил" + GetSexPhrase("","а") + ".";
				link.l1.go = "E4_OK_pay";
				break;
			case "Inquisition_toCuracao":
				dialog.text = "Я слушаю тебя.";
				link.l1 = "Меня интересуют люди: Джоао Ильхайо, Йозеф Нунен де Фонкесао, и Яков Лопез де Фонсека. Что ты можешь сказать про них?";
				link.l1.go = "Step_S2_1";
				break;
			case "Inquisition_afterFrancisco":
				dialog.text = "Я слушаю тебя.";
				link.l1 = "Меня интересуют люди: Джоао Ильхайо, Йозеф Нунен де Фонкесао, и Яков Лопез де Фонсека. Что ты можешь сказать про них?";
				link.l1.go = "Step_S2_1";
				break;
			case "Fr2Letter_SeekProblems":
				dialog.text = "Внимательно слушаю " + GetSexPhrase("дорогого французского гостя","дорогую францужинку") + "!";
				link.l1 = "Я хочу понять, какого черта генерал-губернатор Стэвезант засадил за решетку официального курьера Франции. Что у вас тут, разрази дьявол, происходит?";
				link.l1.go = "Step_F2_1";
				break;
			}
			if (pchar.questTemp.LSCC == "toVillemstadTavern")
			{
				dialog.text = "Я слушаю тебя.";
				link.l1 = "Послушай, мне тут надо ключик заказать к сундуку.";
				link.l1.go = "MasterKeys";
			}
			if (pchar.questTemp.LSCC == "toMasterKeysNoMoney")
			{
				dialog.text = "Внимательно слушаю тебя.";
				link.l1 = "Слушай, мне нужен мастер ключей, ты не видел его?";
				link.l1.go = "MasterKeysNM";
			}
			if (pchar.questTemp.LSCC == "toTalkStuvesant")
			{
				dialog.text = "Внимательно слушаю.";
				link.l1 = "Послушай, ты не знал такого бродягу - Тизера Дэна? Говорят, что он жил у вас в городе некоторое время.";
				link.l1.go = "TizerFind";
			}

			if(PChar.SmallMongrel == "5")
			{
				link.l1 = "Слушай, не появлялся ли в окрестностях острова пиратский корабль?";
				link.l1.go = "SmallMongrel_1";
			}
            // <== Проверяем поле состояния квестов.

			//ОЗГ, Хален
			if (pchar.questTemp.Headhunter == "hunt_halen")
			{
				link.l1 = "Послушай, ты не знаешь, где найти Мартина ван Халена?";
				link.l1.go = "Halen_tavern_1";
			}
			if (pchar.questTemp.Headhunter == "halen_still")
			{
				link.l1 = "Что у тебя здесь творится?! Меня только что пытались убить прямо в комнате!";
				link.l1.go = "Halen_tavern_1_1";
			}
			if (pchar.questTemp.Headhunter == "halen_wait")
			{
				link.l1 = "Ну что, Мартин ван Хален не объявлялся?";
				link.l1.go = "Halen_tavern_6_6";
			}
			//ОЗГ, Хален
 		break;

//********************** Мистер и Мисси Смит **********************
 		case "Smithy":
    		dialog.text = "Крошимер Говард?";
    		link.l1 = "Да.";
    		link.l1.go = "Smithy_1";
 		break;

 		case "Smithy_1":
    		dialog.text = "Не слышал о такой!";
    		link.l1 = "Ладно, забыли!";
    		link.l1.go = "exit";
		npchar.quest.Smithy_DouwesenTavern = "true";
 		break;


//*************************** Квест №4 английки, разведка в Кюрасао ***************************
 		case "Step_E4_1":
    		dialog.text = "Чем смогу - помогу. Спрашивай.";
    		link.l1 = "У меня скопилось кое-какое барахло, золотишко, камни... Нужно сдать, только тихо. В общем, мне нужен человек не особо щепетильный.";
    		link.l1.go = "Step_E4_2";
 		break;
 		case "Step_E4_2":
    		dialog.text = "Хм, 1000 монет и ты узнаешь его имя.";
    		link.l1 = "А не слишком ли много просишь за два слова?";
    		link.l1.go = "E4_dWant_pay";
    		link.l2 = "Держи свою тысячу.";
    		link.l2.go = "E4_OK_pay";
 		break;
 		case "E4_dWant_pay":
    		dialog.text = "Нет, слишком мало. Не хочешь платить - попробуй в другом месте узнать. Все равно придешь.";
    		link.l1 = "Что ж, последую твоему совету. Попробую узнать в другом месте.";
    		link.l1.go = "exit";
    		pchar.questTemp.State = "Intelligence_Curacao_dWant_pay_tavern";
 		break;
 		case "E4_OK_pay":
            if (sti(pchar.money) >= 1000)
            {
        		dialog.text = "Этого человека зовут Йозеф Нунен де Фонкесао. Он негоциант, прибыл сюда с теми янсенистами, которые организовали здесь довольно многочисленную общину, Йозеф и является главным ее организатором и руководителем.\n"+
                         "Но если все эти янсенисты - люди как люди, то этот человек совести не имеет, он сразу стал ростовщиком в городе. Деньги дает охотно и любые, но если не вернул ему долга день в день, то будешь сидеть в тюрьме следующим утром.\n"+
                         "На его совести уже не одна голодная смерть и не одно самоубийство, а ему все нипочем.";
        		link.l1 = "А что же генерал-губернатор?";
        		link.l1.go = "Step_E4_3";
            }
            else
            {
        		dialog.text = "Хех, " + GetSexPhrase("братец","сестричка") + ", денег нет? Что ж ты мне голову морочишь? Приходи, когда будут.";
        		link.l1 = "Да, не пустят на банкет, когда в кармане баксов нет...";
        		link.l1.go = "exit";
        		pchar.questTemp.State = "Intelligence_Curacao_NoMoney_tavern";
        		//ChangeCharacterReputation(pchar, -1); TO_DO eddy
            }
 		break;
 		case "Step_E4_3":
    		dialog.text = "Наш генерал-губернатор, по всему видать, помогает Йозефу в выколачивании долгов. Йозеф - желанный гость в его доме.";
    		link.l1 = "Так если он с властями дружит, то мне опасно с ним связываться!";
    		link.l1.go = "Step_E4_4";
 		break;
 		case "Step_E4_4":
    		dialog.text = "Совсем не опасно. Прикупит он у тебя твое барахло, конечно, не по ценам магазина, но и сдавать не будет. Так что иди смело, тебя не первого отправляю к нему.";
    		link.l1 = "Что ж, спасибо.";
    		link.l1.go = "exit";
    		pchar.questTemp.State = "Intelligence_Curacao_toYozef";
    		AddMoneyToCharacter(pchar, -1000);
    		AddQuestRecord("Eng_Line_4_Intelligence_Curacao", "2");
 		break;
//*************************** Квест №2 испанки, задания Инквизиции ***************************
 		case "Step_S2_1":
    		dialog.text =  NPCStringReactionRepeat("Джоао Ильхайо - хороший человек, торгует честно, товар дешевый, деньги под процент не ссужает. Яков Лопез де Фонсека - компаньон Джоао Ильхайо, они содержат магазин вместе. А вот Йозеф Нунен де Фонкесао - ростовщик, на его совести не одно самоубийство людей, которых он разорил.",
            "На эту тему мы уже говорили...", "Опять двадцать пять?", "Хм, ну сколько можно, а?...", "block", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("Прямо дьявол во плоти!", "Да, точно", "Нет, извини...", "Пардон...", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_S2_2", "none", "none", "none", npchar, Dialog.CurrentNode);
 		break;
 		case "Step_S2_2":
    		dialog.text = "Может и не сам дьявол, но на подручного тянет вполне.";
    		link.l1 = "Спасибо, дружище, ты мне очень помог.";
    		link.l1.go = "exit";
 		break;
//*************************** Квест №2 фр.линейки, доставка письма Стэвезанту ***************************
 		case "Step_F2_1":
    		dialog.text =  NPCStringReactionRepeat("И неудивительно. Шутка ли, за месяц пираты на галеоне уже девятнадцать наших кораблей ограбили и на дно пустили. Из них два - с товарами самого генерал-губернатора. Вот он и смотрит на всех незнакомцев волком!",
            "На эту тему мы уже говорили...", "Опять двадцать пять?", "Хм, ну сколько можно, а?...", "block", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("А что, я оказал" + GetSexPhrase("ся","ась") + " сам" + GetSexPhrase("ым","ой") + " подозрительн" + GetSexPhrase("ым","ой") + " из всех?", "Да, точно.", "Нет, извини...", "Пардон...", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_F2_2", "none", "none", "none", npchar, Dialog.CurrentNode);
 		break;
 		case "Step_F2_2":
    		dialog.text = "Да вы, скорее всего, просто под горячую руку подвернулись. Встречаются и более странные типы.\n"+
				          "Вон, кстати, смотрите, за тем столиком в углу, справа от тебя, сидят двое. Что за люди? Впервые их вижу, а стражу вызывать вроде не за что - я дорожу репутацией своего заведения. Потолкуйте с ними, если хотите!";
    		link.l1 = "Спасибо, дружище, ты мне очень помог.";
    		link.l1.go = "exit";
 		break;
//*************************** ГПК, Мастер Ключей ***************************
		case "MasterKeys":
			dialog.text = "А-а, ну это тебе к Мастеру Ключей надо.";
			link.l1 = "Что за Мастер Ключей?";
			link.l1.go = "MasterKeys_1";
		break;
		case "MasterKeys_1":
			dialog.text = "Так называет Хилла Корнера за то, что он на сундуки и двери замки делает с ключами.";
			link.l1 = "Хм, а это местный мастер?";
			link.l1.go = "MasterKeys_2";
		break;
		case "MasterKeys_2":
			dialog.text = "Ага. Вот он сидит, справа от тебя за круглым столиком.";
			link.l1 = "Понял" + GetSexPhrase("","а") + ", спасибо.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toMasterKeys";
		break;

		case "MasterKeysNM":
			dialog.text = "Да вот же он, на своем обычном месте справа от тебя за столиком.";
			link.l1 = "А-а-а, спасибо...";
			link.l1.go = "exit";
			if (!LAi_CheckLocatorFree("sit", "sit1"))
			{
				FreeSitLocator("Villemstad_tavern", "sit1");
			}
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("GiveKeyMan")], "Villemstad_tavern", "sit", "sit1");
		break;
		//ищем Тизера
		case "TizerFind":
			dialog.text = NPCStringReactionRepeat("Как не знать, его весь город знал! Знатный был выдумщик...", 
				"Слушай, я тебу уже рассказывал об этом.", 
				"Мы уже говорили об этом.",
                "Прошу прощения, но на столь длинное повествование у меня больше нет времени.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Как понять?", 
				"А-а, да, я помню.",
                "Да, конечно.", 
				"Понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("TizerFind_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "TizerFind_1":
			dialog.text = "Ну, понимаешь, он неплохо зарабатывал сказками о своих приключениях. Сейчас это очень модно - путешествия и открытие новых земель у всех на устах!";
			link.l1 = "Про остров, небось, рассказывал?";
			link.l1.go = "TizerFind_2";
		break;
		case "TizerFind_2":
			dialog.text = "И про остров тоже! В общем, с ним было весело. Вот, бывало, скажет: 'Вы не были на Таити?' - и народ начинает собираться вокруг. А уж рассказчик он был что надо! Жаль уехал от нас.";
			link.l1 = "Куда?";
			link.l1.go = "TizerFind_3";
		break;
		case "TizerFind_3":
			dialog.text = "Не знаю, никому не сказал. Просто в один день я его у себя в таверне не увидел - и все. Могу больше сказать - искали его коллеги, так сказать, бродяги, то есть. Не знаю, нашли или нет...";
			link.l1 = "Нет, не нашли.";
			link.l1.go = "TizerFind_4";
		break;
		case "TizerFind_4":
			dialog.text = "Жаль, хороший был человек, хоть и бродяга. Знаешь, бывают люди с обостренным чувством справделивости. Вот Тизер был из таких, да еще жизнь его изрядно побила. Рассказы об Острове Справедливости были его любимой темой.";
			link.l1 = "Хм, и что говорил-то?";
			link.l1.go = "TizerFind_5";
		break;
		case "TizerFind_5":
			dialog.text = "Что есть где-то рядом остров, состоящий из кораблей! Что люди там живут очень неплохо, и все равны между собой. Ну, рай на земле, в общем. Утопия.";
			link.l1 = "А генерал-губернатор ваш как к нищим относится?";
			link.l1.go = "TizerFind_6";
		break;
		case "TizerFind_6":
			dialog.text = "Ты знаешь, очень плохо. Тизер рассказывал, что был продан в рабство, а наш Матиас рабов за людей не считает, и бывших тоже.";
			link.l1 = "Ясно. Слушай, говорят, Бек дела имеет с Голландской Вест-Индской компанией, и...";
			link.l1.go = "TizerFind_7";
		break;
		case "TizerFind_7":
			dialog.text = "Т-с-с!! Тихо, приятель" + GetSexPhrase("","ница") + ". Об этих связях нашего Матиаса говорить не принято. И спрашивать тоже не рекомендую - отгребешь неприятностей по самое небалуйся!";
			link.l1 = "А в чем дело то?";
			link.l1.go = "TizerFind_8";
		break;
		case "TizerFind_8":
			dialog.text = "Эта компания шутить не любит, приятель" + GetSexPhrase("","ница") + ". И ты не смотри, что конторы их в основном расположены в Европе и Индийском океане. Здесь они тоже присутствуют, но не так явно...";
			link.l1 = "Черт!.. А где же их можно найти?";
			link.l1.go = "TizerFind_9";
		break;
		case "TizerFind_9":
			dialog.text = "А зачем они тебе?";
			link.l1 = "Хочу предложить свои услуги в грузовых перевозках.";
			link.l1.go = "TizerFind_10";
		break;
		case "TizerFind_10":
			dialog.text = "Знаешь, " + GetSexPhrase("приятель","дорогуша") + ", компания эта свои дела делает без участия таких, как ты. Поговаривают, что сам Кюрасао принадлежит ей, да и не только этот остров!..";
			link.l1 = "Вот дьявол! Серьезная контора.";
			link.l1.go = "TizerFind_11";
		break;
		case "TizerFind_11":
			dialog.text = "Ага. Мой тебе совет - не пытайся делать с ними дела, здесь они работают только с нашим Беком. Понял" + GetSexPhrase("","а") + "?";
			link.l1 = "Понял" + GetSexPhrase("","а") + "... Ну, дружище, спасибо тебе за столь подробное изложение. Очень было интересно.";
			link.l1.go = "TizerFind_12";
		break;
		case "TizerFind_12":
			dialog.text = "Да не за что. Я и сам рад поболтать.";
			link.l1 = "Будь здоров.";
			link.l1.go = "exit";
			AddQuestRecord("ISS_PoorsMurder", "8");
		break;

//---------------------------------------------------------------------------------------------------------------
		// Винсент Венто
		case "OfficerVinsentVento_1":
			dialog.text = "Да, голландский офицер, заказал у меня пару стаканов слабенького рому, а что случилось?";
			link.l1 = "А ты случайно не обратил внимания, не крутился ли кто вокруг него?";
			link.l1.go = "OfficerVinsentVento_2";
		break;
		
		case "OfficerVinsentVento_2":
			dialog.text = "Сейчас вспомню... Нет, вроде он один сидел... Хотя постойте, сразу же за ним пулей вылетел Бил... Точно, практически вместе вышли!";
			link.l1 = "А кто такой этот Бил?";
			link.l1.go = "OfficerVinsentVento_3";
		break;
		
		case "OfficerVinsentVento_3":
			dialog.text = "Бил - боцман у французского корсара Тревора д'Версера, сейчас он снимает дом возле местного банка.";
			link.l1 = "Спасибо за информацию.";
			link.l1.go = "Exit";
			AddDialogExitQuest("OfficerVinsentVento_bill");
		break;
		
		case "OfficerVinsentVento_4":
			dialog.text = "Рисует? Отчего же, знаю. Один молодой человек недавно рисовал портрет моей супруги - получилось просто изумительно! Весь город заказывает у него портреты. Его дом находится около нашего банка.";
			link.l1 = "Спасибо.";
			link.l1.go = "Exit";
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes");
			NPChar.OfficerVinsentVento = 1;
		break;

		// МАЛЕНЬКИЙ УБЛЮДОК -->
		case "SmallMongrel_1":
			dialog.text = "Да, был у нас тут один случай с корсарской бригантиной! Хотите расскажу?";
			link.l1 = "С удовольствием послушаю.";
			link.l1.go = "SmallMongrel_2";
		break;
		
		case "SmallMongrel_2":
			dialog.text = "Ну, слушайте. Дня три-четыре назад, рано утром дозорные форта заметили пиратскую бригантину, медленно приближающуяся к гавани Виллемстада. Комендант форта, недолго думая, приказал пустить ко дну пиратскую посудину, но знаете, что из этого вышло?";
			link.l1 = "Что?";
			link.l1.go = "SmallMongrel_3";
		break;
		
		case "SmallMongrel_3":
			dialog.text = "Канониры форта ни разу не попали в бригантину! Вы только представьте, капитан, пиратский корабль входит в гавань Виллемстада под ураганным шквалом огня, но все ядра ложатся мимо него, в воду. И даже когда корабль полностью остановился, канониры не смогли поразить цель.";
			link.l1 = "...(улыбается)... Дрянь, выходит, ваши канониры, " + GetName(NPChar, "n") + ".";
			link.l1.go = "SmallMongrel_4";
		break;
		
		case "SmallMongrel_4":
			dialog.text = "Нет, капитан, канониры свою работу знают. Три баркаса для учебной стрельбы, специально расставленных в заливе днём этого дня они расстреляли в считанные секунды.";
			link.l1 = "А что дальше с бригантиной-то было?";
			link.l1.go = "SmallMongrel_5";
		break;
		
		case "SmallMongrel_5":
			dialog.text = "Дальше, больше, капитан. К бригантине выслали шлюпку с десятью солдатами. Вы не поверите, что они увидели, которые взошли на борт бригантины.";
			link.l1 = "Эм-м... Мёртвую команду?";
			link.l1.go = "SmallMongrel_6";
		break;
		
		case "SmallMongrel_6":
			dialog.text = "...(удивлённо)... Откуда вы знаете?!";
			link.l1 = "Догадал" + GetSexPhrase("ся","ась") + ". Продолжай, что было дальше?";
			link.l1.go = "SmallMongrel_7";
		break;
		
		case "SmallMongrel_7":
			dialog.text = "Палуба была усеяна трупами, у которых были перерезаны глотки. Кровь залила буквально всё. Ужасное зрелище.";
			link.l1 = "Да уж, а что потом?";
			link.l1.go = "SmallMongrel_8";
		break;
		
		case "SmallMongrel_8":
			dialog.text = "Палубу очистили от трупов, корабль привели в порядок, и он вошёл в состав Голландского Флота. Но на этом загадочные события не закончились. Ночью его выкрали со стоянки. Как - непонятно. Светила яркая луна, вся гавань Виллемстада была как на ладони, но дозорные умудрились проворонить корабль.";
			link.l1 = "Чёрт, вот это история, а есть предположения, кто мог выкрасть корабль?";
			link.l1.go = "SmallMongrel_9";
		break;
		
		case "SmallMongrel_9":
			string sPortMan = GetName(&Characters[GetCharacterIndex("Villemstad_PortMan")], "f");
			dialog.text = "Не знаю, капитан, об этом лучше спросить заведующего портовым управлением. Его имя " + sPortMan + ".";
			link.l1 = "Спасибо за потрясающую историю, " + GetName(NPChar, "n") + ".";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SmallMongrelToCuracaoPortMan");
		break;
		// МАЛЕНЬКИЙ УБЛЮДОК <--


		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Да уж, такого никогда не бывало... Больше тысячи рабов участвовали в бунте. Две плантации сожгли дотла, а хозяев убили почти всех поголовно. Комендант опасался, что они на город пойдут - ввел военное положение. А все началось с истории любви двух невольников - Таманго и Изауры...";
			link.l1 = "Интересно! Расскажи подробнее, кто это?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Таманго и Изаура - это рабы с плантации Бленхейм, ну, с той, которую сожгли первой. Любовь у них была. А потом приехал из Европы сын хозяина плантации, Леонсио, и положил глаз на Изауру. В общем, решил наложницей своей сделать. Это очень не понравилось Таманго, да и Изаура была не в восторге - любила она этого черномазого\nА надо сказать, что Таманго у себя в Африке был каким-то не то вождем, не то царьком... Здоров он, как бык, топором махать мастер, да и среди рабов авторитет. Вот и подбил их на восстание\nНочью напали на охрану и вырезали всех голландцев в Бленхейме. Изаура открыла им ворота усадьбы - они и там всех перебили. Потом пошли всей толпой на соседнюю плантацию, Бленбург, и устроили там такую же резню. Затем ушли в джунгли и исчезли без следа...";
			link.l1 = "Вот так история! Прямо сюжет для романа! И откуда ты все это знаешь?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Слухи, "+ GetSexPhrase("минхер","госпожа") +", слухами земля полнится. Ром развязывает языки, достаточно просто слушать...";
			link.l1 = "И чем все закончилось? Нашли этих черномазых?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "Какое там! Пока не подоспело подкрепление, никто и шагу в джунгли не делал. Потом прибыл военный корабль с отрядом солдат, обыскали они остров - никого нет.";
			link.l1 = "Ну ты подумай! Тысяча человек - и все как в воду канули!";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "Именно, "+ GetSexPhrase("минхер","госпожа") +"! В воду они и канули!";
			link.l1 = "Ты это о чем сейчас, " + npchar.name + "? Не понимаю что-то...";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "Хе-хе... Бьюсь об заклад - уплыли они с острова. Дело в том, что на следующую ночь после восстания со стоянки кораблей пропал барк. Не пить мне рому до конца дней моих, если это не дело рук Таманго и его братии! Поэтому и нет их на острове.";
			link.l1 = "Ладно, спасибо за интересный рассказ, " + npchar.name + ". Хотя не представляю, как негры могут управляться с парусами.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "Ну, видать могут... Может, кто из них раньше матросом ходил. Заглядывайте ко мне еще, " + pchar.name + ", не забывайте, а я вам еще историй приготовлю.";
			link.l1 = "Спасибо! Ну, мне пора.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Да, отловили этого пирата, всё верно. И вы можете себе представить как? Его подобрали на шлюпке, одного, посреди моря. Он даже пикнуть не успел, как отправился в трюм к крысам. Забавно, правда - такой опасный пират и так глупо попасться!";
			link.l1 = "И чего его в одиночку в море понесло?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Наверно, решил слинять от своих подельничков, не иначе... не поделили чего-то. А теперь им занялась сама Компания - а с этими ребятами шутки плохи. Говорят, он не так давно захватил судно Компании с чем-то ценным. Видимо, только потому, что из него хотят выудить некие сведения, он до сих пор не болтается на виселице.";
			link.l1 = "Так когда состоится его казнь, ты не знаешь?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Этого никто не знает. Думаю - как узнает Компания, что хочет, так и повяжут ему пеньковый галстук. Португалец сейчас в тюрьме под надежной охраной. Недавно к нам привезли еще и его боцмана - с тем так еще удивительнее - он сам сдался голландцам в Филипсбурге. Ну, они его и пристроили по соседству с бывшим капитаном, хе-хе...";
			link.l1 = "Чудеса да и только! Ладно, буду следить за новостями. Не хочу пропустить это представление. Бывай, "+npchar.name+"!";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;

		//ОЗГ, Хален
		case "Halen_tavern_1":
			dialog.text = "Нет, его сейчас здесь нет. Он ушел в плавание, но вернется со дня на день. Можете остановиться у меня. Когда он вернется - я вам сообщу.";
			link.l1 = "Понятно. Мне нужно его подождать. Ну, тогда я сниму комнату у тебя?";
			link.l1.go = "Halen_tavern_2";
		break;
		
		case "Halen_tavern_2":
			dialog.text = "Да, конечно. C вас 100 золотых.";
			link.l1 = "Хорошо. Открывай свою комнату.";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "halen_room";
			LocatorReloadEnterDisable("Villemstad_tavern", "reload2_back", false);
            AddMoneyToCharacter(pchar, -100);
			Pchar.quest.Headhunter_inRoom.win_condition.l1 = "location";
			Pchar.quest.Headhunter_inRoom.win_condition.l1.location = "Villemstad_tavern_upstairs";
			Pchar.quest.Headhunter_inRoom.function = "RatHunters_inRoom";
			AddQuestRecord("Headhunt", "27");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
			pchar.quest.Headhunter_HalenOver.over = "yes";
		break;
		
		case "Halen_tavern_1_1":
			dialog.text = "Да что вы такое говорите? Я прикажу немедленно позвать коменданта!";
			link.l1 = "Зови. И могильщиков тоже зови - я прикончил"+ GetSexPhrase("","а") +" этих двух типов.";
			link.l1.go = "Halen_tavern_2_2";
		break;
		
		case "Halen_tavern_2_2":
			dialog.text = "Мать пресвятая Богородица! Какой кошмар! И это в моей таверне...";
			link.l1 = "Успокойся. Лучше сделай так: тихонько вывези трупы через задний двор, не поднимая лишнего шума, чтобы не повредило репутации твоего заведения... Не думаю, что эта парочка из местных, так что никто ничего и не узнает. Ты видел, как они заходили? Два типа, в черном, лица закрыты платками.";
			link.l1.go = "Halen_tavern_4_4";
		break;
		
		case "Halen_tavern_4_4":
			dialog.text = "Нет... Не видел. Господи... Да что же это за наказание!";
			link.l1 = "Ты перестанешь наконец причитать? Не видел, говоришь? Впрочем, другого ответа я и не ожидал"+ GetSexPhrase("","а") +"... А ты часом не в сговоре с ними? А то я...";
			link.l1.go = "Halen_tavern_5_5";
		break;
		
		case "Halen_tavern_5_5":
			dialog.text = "Что вы, "+ GetSexPhrase("благородный господин","благородная госпожа") +"! Вот вам истинный крест, никогда бы греха на душу не взял...";
			link.l1 = "Хорошо-хорошо, я тебе верю. Мартин не объявлялся, не слышал?";
			link.l1.go = "Halen_tavern_6_6";
		break;
		
		case "Halen_tavern_6_6":
			if (makeint(environment.time) > 18.0 || makeint(environment.time) < 6.0)
			{
				dialog.text = "Нет, не появлялся. Приходите завтра утром - возможно, у меня будут новости.";
				link.l1 = "Хорошо.";
				link.l1.go = "exit";
				pchar.questTemp.Headhunter = "halen_wait";
				break;
			}
			dialog.text = "Вы как раз вовремя! Корвет Мартина ван Халена бросил якорь в нашем порту.";
			link.l1 = "Отлично! Значит, Мартин уже в городе?";
			link.l1.go = "Halen_tavern_7_7";
		break;
		
		case "Halen_tavern_7_7":
			dialog.text = "Да, он отправился с визитом к генерал-губернатору сразу по прибытию. Думаю, если поторопитесь - застанете его у резиденции. Или найдете его на корабле.";
			link.l1 = "Понял"+ GetSexPhrase("","а") +". Уже бегу. Спасибо тебе!";
			link.l1.go = "Halen_tavern_8_8";
		break;
		
		case "Halen_tavern_8_8":
			AddQuestRecord("Headhunt", "29");
			pchar.questTemp.Headhunter = "halen_town";
			CreateHalen();
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

