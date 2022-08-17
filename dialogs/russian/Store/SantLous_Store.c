// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Спрашивай, чего ты хочешь?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушай, это магазин, здесь люди покупают что-то. Не отвлекай меня!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Гм, не буду...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

    		//квест Черной Гаргульи, начальный диалог
			if (pchar.questTemp.BlueBird == "begin")
			{
				dialog.text = RandPhraseSimple("Капитан, прошу вас, помогите нам!!!", "Капитан, я прошу у вас помощи от имени всех торговцев!");
				link.l1 = "Что случилось? Чем я могу вам помочь?"; 
				link.l1.go = "RBlueBird";
				break;
			}		

		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		Квест получения Черной Гаргульи
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "RBlueBird":
			dialog.text = "Эх, капитан, не случилось, а случается уже давно. Мы, торговцы Карибского моря, на грани разорения. А во всем виновата проклятая 'Черная Горгулья'...";
			link.l1 = "'Черная Горгулья'?";
			link.l1.go = "RBlueBird_1";
		break;
		case "RBlueBird_1":
			dialog.text = "Да, этот чертовый бриг, уйти от него в море невозможно. Грабит только корабли торговцев. Большие караваны, усиленные военными кораблями, не трогает.";
			link.l1 = "А почему вы сказали, что торговцы разоряются? Ведь товары все равно поступают сюда с этими караванами.";
			link.l1.go = "RBlueBird_2";
		break;
		case "RBlueBird_2":
			dialog.text = "Поступают, верно. Но все дело в том, что оборот при таком раскладе становится невыгодным. Лучше всего иметь свой шлюп или флейт, самим закупать товары в Старом Свете и везти сюда. Вот это - торговля!\nА когда мы закупаем товары у перевозчиков - тут уже не до прибылей, речь идет о простом выживании.";
			link.l1 = "Понятно. И как раз ваши корабли берет на абордаж бриг...";
			link.l1.go = "RBlueBird_3";
		break;
		case "RBlueBird_3":
			dialog.text = "Именно так. Уже почти все торговцы потеряли собственные корабли, черт ее дери, эту 'Черную Горгулью'!";
			link.l1 = "М-да, печально для вас... Ну, так что же вы хотите от меня?";
			link.l1.go = "RBlueBird_4";
		break;
		case "RBlueBird_4":
			dialog.text = "Мы хотим, чтобы вы уничтожили эту сизокрылую выхухоль, мать ее перемать!!!";
			link.l1 = "И что я буду с этого иметь?";
			link.l1.go = "RBlueBird_5";
		break;
		case "RBlueBird_5":
			dialog.text = "Я соберу со всех коллег достойную оплату для вас за эту работу. Пятьдесят тысяч пиастров я могу вам твердо обещать. Чертов бриг должен пойти на дно!";
			link.l1 = "За такие деньги, приятель, я и пальцем не шевельну. Ищи дурака!";
			link.l1.go = "RBlueBird_close";
			link.l2 = "Хм, эти деньги меня интересуют. Я готов"+ GetSexPhrase("","а") +" взяться за это дело. Каковы сроки выполнения?";
			link.l2.go = "RBlueBird_6";
		break;
		case "RBlueBird_6":
			dialog.text = "Вы не ограничены во времени. Я прекрасно понимаю, что сделать это будет нелегко, черт возьми! Сказать по правде, мы уже привлекали наемных убийц к этому делу, хотели убрать капитана. Безрезультатно...";
			link.l1 = "Вот как? Вы можете подробней об этом рассказать?";
			link.l1.go = "RBlueBird_7";
		break;
		case "RBlueBird_7":
			dialog.text = "Ну, скинулись мы и наняли кое-кого, чтобы он разыскал кэпа этого брига среди пиратов. Ничего не вышло, наш наймит с полгода рыскал по Карибам, но ничего не нашел. Черт его знает, где они базируются и куда сбывают награбленное...";
			link.l1 = "Та-а-а-ак, приятель, это уже что-то. А теперь послушай мои условия сделки.";
			link.l1.go = "RBlueBird_8";
		break;
		case "RBlueBird_8":
			dialog.text = "Внимательно слушаю, " + GetAddress_Form(NPChar) + "." ;
			link.l1 = "Эта сделка между тобой и мной, деньги собирай, как хочешь, но никому не болтай, что я взял"+ GetSexPhrase("ся","ась") +" за это дело. И второе. Ты сказал, что потеряли свои корабли ПОЧТИ все торговцы. Что значит 'почти'?";
			link.l1.go = "RBlueBird_9";
		break;
		case "RBlueBird_9":
			dialog.text = "У одного торговца остался флейт. Но он счастливчик, ни разу не попадал на этот бриг. Он - наша единственная надежда закрепиться здесь, уже все наши ему должны. Если бы он не поддерживал нас в трудную минуту - всем давно пришел бы конец. Он еще никому не отказывал в просьбах дать денег в долг!";
			link.l1 = "Понятно. Почти святой! И как же его зовут?";
			link.l1.go = "RBlueBird_10";
		break;
		case "RBlueBird_10":
			dialog.text = "Паскаль Вуазье. Он содержит лавку на Исла-Тесоро в пиратском поселении. Так вы беретесь за дело?";
			link.l1 = "Вы принимаете мое условие о молчании?";
			link.l1.go = "RBlueBird_11";
		break;
		case "RBlueBird_11":
			dialog.text = "Безусловно!";
			link.l1 = "Тогда берусь. Я начинаю поиски с этого дня, надеюсь вскоре закончить.";
			link.l1.go = "RBlueBird_12";
		break;
		case "RBlueBird_12":
			dialog.text = "Эх, вашими бы устами, да мед пить! Ну что же, приступайте. Очень надеюсь, что все будет проходить так, как вы сказали.";
			link.l1 = "Будет, можете не сомневаться!";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "toBermudes";
			pchar.questTemp.BlueBird.traiderId = npchar.id; //запомним Id торговца
			SetQuestHeader("Xebeca_BlueBird");
			AddQuestRecord("Xebeca_BlueBird", "1");
			AddQuestUserData("Xebeca_BlueBird", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("Xebeca_BlueBird", "sName", GetFullName(npchar));
		break;

		case "RBlueBird_close":
			dialog.text = "Ну что же, очень жаль. Пожалуй, мы поищем 'дурака' в другом месте...";
			link.l1 = "Гм...";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "over";
		break;
		case "RBlueBirdWon":
			dialog.text = "Прекрасная новость, скажу я вам! Наконец-то мы сможем заняться торговлей по-настоящему... Вы хотите получить деньги прямо сейчас?";
			link.l1 = "Да, желательно...";
			link.l1.go = "RBlueBirdWon_1";
			int chComp;                                                             
			for (int i=0; i<=COMPANION_MAX; i++)	
        	{
                chComp = GetCompanionIndex(pchar, i);
                if(chComp != -1 && RealShips[sti(characters[chComp].ship.type)].Name == "VALCIRIA_QUEST1")
        		{	
					dialog.text = "Хм, подождите... Насколько мне известно, вы сумели настигнуть бриг, но не потопили его! Теперь он находится в вашем владении.";
					link.l1 = "Да, это так. Ну и в чем проблема?";
					link.l1.go = "RBlueBirdWon_10";
					break;
                }
            }
			break;

		case "RBlueBirdWon_1":
			dialog.text = "Без проблем, извольте получить. Деньги в сундуках. Здесь даже немного больше пятидесяти тысяч.";
			link.l1 = "Спасибо, мы в расчете. Желаю всего наилучшего... Кстати, а вы не хотите узнать, кто стоял за всем этим?";
			link.l1.go = "RBlueBirdWon_2";
			TakeNItems(pchar, "chest", 4);
			Log_Info("Вы получили кредитные сундуки");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+10;
		break;

		case "RBlueBirdWon_2":
			dialog.text = "Хм, очень будет интересно узнать...";
			link.l1 = "Это самый 'святой' торговец в Карибском море - Паскаль Вуазье.";
			link.l1.go = "RBlueBirdWon_3";
		break;
		case "RBlueBirdWon_3":
			dialog.text = "Не может быть!..";
			link.l1 = "Может. Доказательств, к сожалению, у меня нет, но вы имейте в виду, кто ссужает вам ваши же деньги.";
			link.l1.go = "RBlueBirdWon_4";
		break;
		case "RBlueBirdWon_4":
			dialog.text = "Хм, все это нужно проверить... Ну что же, спасибо вам за работу и за информацию.";
			link.l1 = "Да не за что, это вами оплачено. Прощайте.";
			link.l1.go = "exit";
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.questTemp.BlueBird = "over";
		break;

		case "RBlueBirdWon_10":
			dialog.text = "Проблема в том, что этот проклятый корабль теперь у вас в руках. А вы, кстати, тоже пират! И кто вам помешает грабить торговцев точно так же, как это делал предыдущий хозяин?";
			link.l1 = "Хм, вопрос, конечно, интересный... Однако, я выполнил"+ GetSexPhrase("","а") +" работу!";
			link.l1.go = "RBlueBirdWon_11";
		break;
		case "RBlueBirdWon_11":
			dialog.text = "Нет, вы ее не выполнили. Мы договаривались о потоплении 'Черной Горгульи', а не об абордаже.";
			link.l1 = "Хм, вот значит как! Ну что же, я вас понял"+ GetSexPhrase("","а") +"... Всего наилучшего, передавайте мой пламенный привет вашим коллегам.";
			link.l1.go = "RBlueBirdWon_12";
		break;
		case "RBlueBirdWon_12":
			dialog.text = "Передам всенепременно! Прощайте, и впредь держите свое слово 'от' и 'до'.";
			link.l1 = "Обязательно. Но я не прощаюсь...";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "9");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("Xebeca_BlueBird", "sSex1", GetSexPhrase("полный кретин","полная дура"));
			pchar.questTemp.BlueBird = "returnMoney";
			pchar.questTemp.BlueBird = "SantLous_toTavern";
		break;

		case "RBlueBirdDieHard":
			dialog.text = "Очень и очень жаль. Ну что же, вы не перв"+ GetSexPhrase("ый","ая") +", кто берется за это дело, и у кого ничего не выходит. Плохо, придется нам и далее прозябать...";
			link.l1 = "Надеюсь, все придет в норму со временем...";
			link.l1.go = "RBlueBirdDieHard_1";
		break;
		case "RBlueBirdDieHard_1":
			dialog.text = "Это уж точно. Вот живем тут в суете, и наивно полагаем, что именно вокруг нас земля вертится. Ан нет, из земли взято, в землю и уйдем\nХех, что-то меня на лирику потянуло.";
			link.l1 = "Бывает... Ну что же, прощайте.";
			link.l1.go = "exit";
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.questTemp.BlueBird = "over";
		break;

		case "RBlueBird_retMoney_1":
			dialog.text = "Ах ты, мерзав"+ GetSexPhrase("ец","ка") +"!";
			link.l1 = "Я бы вас не трогал"+ GetSexPhrase("","а") +", если бы вы не начали жульничать!";
			link.l1.go = "RBlueBird_retMoney_2";
		break;
		case "RBlueBird_retMoney_2":
			dialog.text = "А-а-ать, черт! Стража, хватай е"+ GetSexPhrase("го","е") +"!! Далеко тебе не уйти, мерзав"+ GetSexPhrase("ец","ка") +"...";
			link.l1 = "Ха, а стражи здесь нет. Лучше бы вернул мои деньги, проныра. Иначе буду лечить вас дальше...";
			link.l1.go = "RBlueBird_retMoney_3";
		break;

		case "RBlueBird_retMoney_3":
			dialog.text = "Будь ты проклят"+ GetSexPhrase("","а") +", мерзав"+ GetSexPhrase("ец","ка") +"! Как я жалею, что связался с тобой!";
			link.l1 = "Друг мой, вы сами виноваты, нужно было держаться договора.";
			link.l1.go = "RBlueBird_retMoney_4";
		break;
		case "RBlueBird_retMoney_4":
			dialog.text = "Какого договора, нашего с вами? Я его неукоснительно придерживался! Это вы его нарушили, не потопив бриг!";
			link.l1 = "Мон шер, не надо так кричать, это пагубно отражается на голосовых связках. А вдруг не сможете потом разговаривать? В общем, я готов"+ GetSexPhrase("","а") +" говорить с вами только на умеренных тонах...";
			link.l1.go = "RBlueBird_retMoney_5";
		break;
		case "RBlueBird_retMoney_5":
			dialog.text = "Ну хорошо, хотя тон здесь ни при чем. Это вы нарушили условия сделки, а не мы - вот суть вопроса!";
			link.l1 = "Хех! Вы, торговцы, большие мастера эдаких заковык в договорах. Знаю я ваши штучки. Где-то запятую не поставил, и смысл текста сразу меняется.";
			link.l1.go = "RBlueBird_retMoney_6";
		break;
		case "RBlueBird_retMoney_6":
			dialog.text = "При чем здесь запятые? У нас с вами была устная договоренность.";
			link.l1 = "Ну, это я образно выражаюсь. Смысл в том, что вы зацепились за возможность кинуть меня на бабки, и сделали это. А я пират, мне недосуг разбираться в двойных смыслах ваших условий.";
			link.l1.go = "RBlueBird_retMoney_7";
		break;
		case "RBlueBird_retMoney_7":
			dialog.text = "Каких условий?";
			link.l1 = "Условий наших договоренностей. Вам мешала 'Черная Горгулья' - я решил"+ GetSexPhrase("","а") +" эту проблему. Если бы вы отдали мне мои деньги, то я вас и пальцем бы не тронул"+ GetSexPhrase("","а") +". Так что все ваши проблемы от вашей мудрости, так сказать...";
			link.l1.go = "RBlueBird_retMoney_8";
		break;
		case "RBlueBird_retMoney_8":
			dialog.text = "Ну ладно, забирайте ваши 50 тысяч и убирайтесь отсюда!";
			link.l1 = "Не так быстро, мон шер. Все дело в том, что я понес"+ GetSexPhrase("","ла") +" дополнительные финансовые издержки, пытаясь вразумить вас. Не говоря уже о моральном ущербе. Поэтому сумма выросла.";
			link.l1.go = "RBlueBird_retMoney_9";
		break;
		case "RBlueBird_retMoney_9":
			dialog.text = "И что это за новая сумма? Назовите ее.";
			link.l1 = "Увеличьте ее в четыре раза. 200 тысяч, и я оставлю вас в покое. Иначе - разорю. А потом убью. Сначала вашу семью, а потом вас...";
			link.l1.go = "RBlueBird_retMoney_10";
		break;
		case "RBlueBird_retMoney_10":
			dialog.text = "Да ты - дьявол"+ GetSexPhrase("","ица") +"!!";
			link.l1 = "И очень, очень зл"+ GetSexPhrase("ой дьявол","ая дьяволица") +"...";
			link.l1.go = "RBlueBird_retMoney_11";
		break;
		case "RBlueBird_retMoney_11":
			dialog.text = "Хорошо. Вот твои деньги - четырнадцать сундуков. Здесь даже больше двухсот тысяч. А теперь убирайся! И оставь нас в покое!";
			link.l1 = "Всенепременно. Теперь, когда вы рассчитались со мной, 'Черная Горгулья' вам более не угрожает. Прощайте, удачи в делах коммерческих...";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.BlueBird");
			pchar.questTemp.BlueBird = "over"; //закрываем квест
			TakeNItems(pchar, "chest", 14);
			Log_Info("Вы получили кредитные сундуки");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Xebeca_BlueBird", "14");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("Xebeca_BlueBird", "sSex1", GetSexPhrase("ен","ьна"));
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
		break;


	}
	UnloadSegment(NPChar.FileDialog2);
}

