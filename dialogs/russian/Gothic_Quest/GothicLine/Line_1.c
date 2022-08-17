// диалоговый файл №1 на гот. линейку
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
    float locx, locy, locz;
	string sTemp, attrName;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    switch (Dialog.CurrentNode)
    {
        case "First time":
			dialog.text = "Не о чем говорить.";
			link.l1 = "Ладно...";
            link.l1.go = "exit";

//>>>>>>>>>>>>========= Разброс диалогов по персонажам =====================

			if (npchar.id == "DeLeiva")// квест, база с мужем донны Анны
            {
    			dialog.text = "Ну что же, вот мы и дождались нашего гостя. Добро пожаловать на ужин, "+ GetSexPhrase("месье","мадемуазель") +". Главное блюдо для вас сегодня - добрая толедская сталь!";
				link.l1 = "Вот так встреча! А в чем дело?!";
    			link.l1.go = "Gothic_1";
            }
			if (npchar.id == "DeLeivaBrother_1" || npchar.id == "DeLeivaBrother_2")// квест, братья де Лейва
            {
    			dialog.text = "Что тебе здесь нужно?";
    			link.l1 = "";
    			link.l1.go = "Gothic_2_2";
            }

               // Квест библии, Аарон дает задание
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_toAaron")
            {
    			dialog.text = "Рад видеть вас, "+ GetSexPhrase("друг мой","" + pchar.name + "") +". Зачем пожаловали?";
    			link.l1 = "Минхер, я откомандирован"+ GetSexPhrase("","а") +" в ваше распоряжение Генералом Ли.";
    			link.l1.go = "Gothic_3_1";
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_toBermudes")
            {
    			dialog.text = "С нетерпением ожидаю вашего доклада о поисках.";
    			link.l1 = "Я занимаюсь этим, результаты будут...";
    			link.l1.go = "exit";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_DeGrafIsDead")
            {
    			dialog.text = "С нетерпением ожидаю вашего доклада о поисках.";
    			link.l1 = "Минхер, мне удалось выяснить, кто продавал искомую христианскую книгу. Этого флибустьера зовут Лоран де Граф. Вернее, звали, так как он погиб. Когда я добрал"+ GetSexPhrase("ся","ась") +" до него у берегов Картахены, он вел бой с очень мощной испанской эскадрой. Мне не удалось спасти его фрегат, сам Лоран утонул вместе с кораблем. Боюсь, что это все, книгу найти теперь просто невозможно.";
    			link.l1.go = "Gothic_3_12";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_DeGrafDieHard")
            {
    			dialog.text = "С нетерпением ожидаю вашего доклада о поисках.";
    			link.l1 = "Минхер, мне удалось выяснить, кто продавал искомую христианскую книгу. Этого флибустьера зовут Лоран де Граф. Когда я наш"+ GetSexPhrase("ел","ла") +" его близ Картахены, он вел бой с очень мощной испанской эскадрой. Я не смог"+ GetSexPhrase("","ла") +" ничем помочь де Графу, силы были слишком неравны. Мне пришлось покинуть поле боя.";
    			link.l1.go = "Gothic_3_12";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_BadResult")
            {
    			dialog.text = "Мне более нечего вам сказать. Отправляйтесь к Ли.";
    			link.l1 = "Хорошо, минхер.";
    			link.l1.go = "exit";
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_WeWon")
            {
    			dialog.text = "С нетерпением ожидаю вашего доклада о поисках.";
    			link.l1 = "Мне ничего не удалось отыскать. Я вынужден"+ GetSexPhrase("","а") +" закончить поиски.";
    			link.l1.go = "Gothic_3_12";
    			link.l2 = "Все ищу, дерусь, топлю испанцев... Но книгу не наш"+ GetSexPhrase("ел","ла") +" пока... Однако продолжу поиски...";
    			link.l2.go = "exit";
			}			
			if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_IHaveMap")
            {
                dialog.text = "С нетерпением ожидаю вашего доклада о поисках.";
    			link.l1 = "Мне ничего не удалось отыскать. Я вынужден"+ GetSexPhrase("","а") +" закончить поиски.";
    			link.l1.go = "Gothic_3_12";
				if (CheckCharacterItem(pchar, "Bible"))
				{
           			link.l2 = "Мне удалось добыть какую-то книгу. Не знаю, то ли это, что вы ищете, но крест на обложке точно есть.";
        			link.l2.go = "Gothic_3_13";
                }
                else
                {
        			link.l2 = "Я пока не сумел"+ GetSexPhrase("","а") +" разыскать книгу, но я нахожусь в поиске. Вам нужно подождать...";
        			link.l2.go = "exit";
                }
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_GoodResult")
            {
    			dialog.text = "Я и вся наша община молимся за вас...";
    			link.l1 = "Хех, спасибо...";
    			link.l1.go = "exit";
            }

			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "ThreeCorsairs_toBonrepo") //Квест. Маркиз Бонрепо в Бас-Тере
            {
    			dialog.text = "С кем имею честь?..";
    			link.l1 = "Капитан " + GetFullName(pchar) + ". Я прибыл"+ GetSexPhrase("","а") +" к вам по распоряжению Генерала Ли.";
    			link.l1.go = "Gothic_6_1";
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "ThreeCorsairs_toSeek") 
            {
    			dialog.text = "Итак, как успешно продвигается ваша миссия?";
    			if (sti(pchar.questTemp.Count) == 3)
				{
					link.l1 = "Она выполнена. Все трое не будут участвовать в войне на стороне Англии.";
    				link.l1.go = "Gothic_6_9";
				}
				else
				{
					link.l1 = "Пока мне не удалось встретиться со всеми, но я работаю над этим.";
    				link.l1.go = "exit";
				}
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "EndWar_toBorepo")
            {
    			dialog.text = "А-а-а, барон"+ GetSexPhrase("","есса") +"! Рад вас видеть. Скажу больше - я ждал вас...";
    			link.l1 = "Рад"+ GetSexPhrase("","а") +" вас видеть так же, маркиз.";
    			link.l1.go = "Gothic_12_1";
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "EndOfQuestLine")
            {
    			dialog.text = "Все, барон"+ GetSexPhrase("","есса") +", я вас больше не задерживаю. Прощайте...";
    			link.l1 = "Прощайте, маркиз...";
    			link.l1.go = "exit";
            }

		break;
//<<<<<<<<<<<<===== Разброс диалогов по персонажам =====================
        case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;

//********************************* Драка с мужем де Лейва. **********************************
 		case "Gothic_1":
			dialog.text = "Нет, ну как вам нравится... В чужой дом посреди ночи вламывается "+ GetSexPhrase("мужчина","какая-то посторонняя девка") +", а потом спрашивает: 'А в чем дело?!'\n"+
				          "Не стройте из себя идиот"+ GetSexPhrase("а","ку") +"! Моя жена заперта, я нашел у нее это чертово кольцо Ли.";
			link.l1 = "Все ясно... Ну что же, приложу все силы для того, чтобы угостить вас блюдом, которое вы уготовили мне сегодня.";
    		link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			dialog.text = "Начнем трапезу!";
			link.l1 = "Начнем, пожалуй...";
    		link.l1.go = "Gothic_3";
		break;
 		case "Gothic_3":
			LAi_LocationFightDisable(loadedLocation, false); 
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			LAi_SetPlayerType(pchar);
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
            DoQuestFunctionDelay("GothicLee_Havana_FightInHouse", 11.0);
		break;

//********************************* Драка с братьями. **********************************

 		case "Gothic_2_2":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_1013_BANDIT_FROMCAVALORN_01_01.wav");
			dialog.text = "Что такое?";
			link.l1 = "";
    		link.l1.go = "Gothic_2_3";
		break;
 		case "Gothic_2_3":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_10008_BANDIT_SOUP_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты рудакоп?";
    		link.l1.go = "Gothic_2_4";
		break;
 		case "Gothic_2_4":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_10008_BANDIT_SOUP_01_01.wav");
			dialog.text = "Ты по штанам так решил - нет я ношу их просто потому что так удобно. Какое тебе до этого дело?";
			link.l1 = "Не было бы дела, не спрашивал"+ GetSexPhrase("","а") +" бы, поверьте уж...";
    		link.l1.go = "Gothic_2_5";
		break;
 		case "Gothic_2_5":
			dialog.text = "Возможно. И что тебе нужно от нас?";
			link.l1 = "Сеньоры, не вы ли родственники дона Хосе Рамиреса де Лейва? Я так понял"+ GetSexPhrase("","а") +", вы замыслили отомстить за дона Хосе?";
    		link.l1.go = "Gothic_2_6";
		break;
 		case "Gothic_2_6":
			dialog.text = "Немедленно говори, кто ты. Иначе я отрежу тебе твой длинный язык.";
			link.l1 = "Я "+ GetSexPhrase("тот","та") +", кто отправил"+ GetSexPhrase("","а") +" уважаемого дона Хосе на тот свет. Еще и слуг его туда же, вслед за хозяином.";
    		link.l1.go = "Gothic_2_7";
		break;
 		case "Gothic_2_7":
			dialog.text = "Аргх, удача сегодня с нами! Полдела сделано, брат, осталось найти эту бестию Анну, и мы можем возвращаться домой.";
			link.l1 = "А как же я?!";
    		link.l1.go = "Gothic_2_8";
		break;
 		case "Gothic_2_8":
			dialog.text = "А тебя уже нет... Вперед, брат, покончим с "+ GetSexPhrase("этим мерзавцем","этой дрянью") +"!";
			link.l1 = "Я с такой трактовкой моего бытия не соглас"+ GetSexPhrase("ен","на") +". Я есть! Ну, давайте начнем...";
    		link.l1.go = "Gothic_2_9";
		break;
 		case "Gothic_2_9":
			LAi_LocationDisableOfficersGen("Mayak10", false); //офицеров пускать
			pchar.questTemp.GothicLee = "GothicLeeAnnaHant_GoodWork";
			LAi_LocationFightDisable(&Locations[FindLocation("Mayak10")], false); 			
			LAi_group_Delete("EnemyFight");
			for (i=1; i<=2; i++)
            {				
				LAi_group_MoveCharacter(characterFromId("DeLeivaBrother_"+i), "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddQuestRecord("GothicLee_2_KillAnnaHanters", "4");
	                                          LocatorReloadEnterDisable("SantLous_townhall", "reload2", true);
		                     DoQuestCheckDelay("AnnaHant_GoodWork", 55.0);
			DialogExit();
		break;

//********************************* Поиски Библии. Квест №8 **********************************
        case "Gothic_3_1":
			dialog.text = "О-о-о, это очень здорово, что именно вы будете помогать мне в поисках. Мне уже довелось видеть вас в деле.";
			link.l1 = "О каких поисках идет речь? Ли ничего конкретного не сказал...";
			link.l1.go = "Gothic_3_2";
		break;
        case "Gothic_3_2":
			dialog.text = "Все верно, "+ GetSexPhrase("друг мой","" + pchar.name + "") +"
. Но давайте по порядку.\n"+
                          "Первым приверженцем учения Янсения, бежавшим из Европы в Кюрасао около двадцати лет назад, был некто Самуэль Кохэно. Он был очень богатым человеком, и однажды ему удалось через посредников выкупить за баснословные деньги в самой канцелярии Инквизиции в Севилье один очень и очень таинственный документ. Речь идет об еще одном Евангелии.\n"+
                          "Будучи христиан"+ GetSexPhrase("ином","кой") +", вы, наверное, читали Ветхий и Новый заветы?";
			link.l1 = "Что я могу сказать, не без этого...";
			link.l1.go = "Gothic_3_3";
		break;
        case "Gothic_3_3":
			dialog.text = "А знаете ли вы, что библейские тексты, которыми мы сейчас располагаем, не являются первоисточниками, так сказать...";
			link.l1 = "Как это понимать?";
			link.l1.go = "Gothic_3_4";
		break;
        case "Gothic_3_4":
			dialog.text = "Дело в том, что Библию не написали сразу же после Воскресения Христа. Прошло достаточно много времени, прежде чем окрепшая церковь озаботилась необходимостью сбора и классификации христианского материала, дабы привести веру к единым догмам.\n"+
                          "Вот тогда-то и произошла детальная ревизия всего, что находилось в то время в руках церкви. Когда сбор и анализ информации был проведен, оказалось, что некоторые вещи прямо противоречат друг другу. Тогда был проведен церковный собор на самом высоком уровне, где и принимались решения относительно того, можно ли считать тот или иной документ истинным.";
			link.l1 = "Очень интересно. Но какое это отношение имеет к моему заданию?";
			link.l1.go = "Gothic_3_5";
		break;
        case "Gothic_3_5":
			dialog.text = "Терпение, "+ GetSexPhrase("друг мой","" + pchar.name + "") +", и вам все станет ясно.\n"+
                          "Итак, многое было признано ересью и либо уничтожалось, либо пряталось так глубоко и надежно, что вытащить это вновь на свет Божий не представлялось возможным. Но Самуэлю это удалось! За астрономическую сумму он сумел подкупить иезуита-архивариуса и тот выкрал из тайных хранилищ Инквизиции неизвестное доселе Евангелие!\n"+
                          "Самуэль немедленно бежал из Старого Света, но несчастия преследовали его буквально на каждом шагу. В результате этот богатейший и достойнейший человек лишился всего, был продан в рабство и сгинул на плантациях сахарного тростника где-то здесь, в английских поселениях.";
			link.l1 = "Я долж"+ GetSexPhrase("ен","на") +" найти место его смерти?";
			link.l1.go = "Gothic_3_6";
		break;
        case "Gothic_3_6":
			dialog.text = "Нет, в этом нет никакого смысла. Вы должны найти пропавший трактат.";
			link.l1 = "Даже не представляю себе, за что можно зацепиться, с чего начать поиски...";
			link.l1.go = "Gothic_3_7";
		break;
        case "Gothic_3_7":
			dialog.text = "Зацепка есть, именно она и явилась катализатором того, что я выпросил вас у Генерала Ли.";
			link.l1 = "Слушаю вас внимательно, Аарон.";
			link.l1.go = "Gothic_3_8";
		break;
        case "Gothic_3_8":
			dialog.text = "До меня дошли слухи, что один из английских каперов в поселении в Шарлотт-Тауне намеревался продать старую христианскую книгу, написанную на неизвестном ему языке.";
			link.l1 = "Хм, но если язык неизвестен, то как он определил, что книга христианская?";
			link.l1.go = "Gothic_3_9";
		break;
        case "Gothic_3_9":
			dialog.text = "По изображениям распятия на книге, "+ GetSexPhrase("друг мой","" + pchar.name + "") +".";
			link.l1 = "Понятно... Хорошо, как имя этого пирата?";
			link.l1.go = "Gothic_3_10";
		break;
        case "Gothic_3_10":
			dialog.text = "Я не знаю.";
			link.l1 = "Вот как... Ну что же, полагаю, я смогу узнать и его имя, и где эта книга сейчас.";
			link.l1.go = "Gothic_3_11";
		break;
        case "Gothic_3_11":
			dialog.text = "Я уверен в этом практически на сто процентов. Приступайте, "+ GetSexPhrase("друг мой","" + pchar.name + "") +". В случае успеха награда будет очень высокой.";
			link.l1 = "Эта обнадеживающая новость, несомненно, придаст мне рвения. До встречи, Аарон, я немедленно приступаю к поискам.";
			link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_toBermudes";
            AddQuestRecord("GothicLee_3_SeekBible", "2");
            QuestSetCurrentNode("Torus", "GothicLee3_quest");
		break;
        case "Gothic_3_12":
			dialog.text = "Это очень и очень плохо... Ну что же, вы мне больше не нужны. Отправляйтесь обратно к Ли.";
			link.l1 = "Хорошо, минхер.";
			link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_BadResult";
            NPChar.LifeDay = 0;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
		break;
        case "Gothic_3_13":
			dialog.text = "Так, давайте посмотрим... Да, это именно то, что мы потеряли! Вы нашли утерянное сокровище Самуэля Кохэно! Господи, Слава Тебе!!!";
			link.l1 = "Ныне, и присно, и вовеки веков. Аминь.";
			link.l1.go = "Gothic_3_14";
			TakeItemFromCharacter(pchar, "Bible");
		break;
        case "Gothic_3_14":
			dialog.text = GetFullName(pchar) + ", я обещал вам, что награда ваша будет очень высокой. Во сколько вы оцените свою работу?";
			link.l1 = "Ну, у меня были накладные расходы, я потратил"+ GetSexPhrase("","а") +" 235 тысяч на покупку. Все, что вы предложите мне сверх данной суммы, и будет являться наградой.";
			link.l1.go = "Gothic_3_15";
		break;
        case "Gothic_3_15":
			dialog.text = "Сверх этого я предложу вам один миллион. И безграничное уважение нашей общины до скончания века, которое, кстати, скоро придет...";
			link.l1 = "Хех, миллион - это неплохо, даже очень неплохо! А что это вы про конец света заговорили?";
			link.l1.go = "Gothic_3_16";
		break;
        case "Gothic_3_16":
			dialog.text = "Бренное существование человечества на этой земле - трагедия людей. Но скоро все придет в норму, к тому, с чего началось...";
			link.l1 = "Вы это серьезно? Проклятье, испортили мне все настроение от получения такой значительной суммы. Ну да ладно... Вы, пожалуй, ожидайте развязки своей трагедии, а я займусь более прозаичными вещами - суетой сует. С такой суммой в кармане эта моя личная трагедия существования доставит мне очень много приятных минут.";
			link.l1.go = "Gothic_3_17";
		break;
        case "Gothic_3_17":
			dialog.text = "Прощайте, и да хранит вас Господь!";
			link.l1 = "И вам всего самого наилучшего. Прощайте.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 1235000);
            pchar.questTemp.GothicLee = "SeekBible_GoodResult";
            AddQuestRecord("GothicLee_3_SeekBible", "10");
			AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("","а"));
            NPChar.LifeDay = 0;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
		break;

//********************************* Маркиз Бонрепо. Квест **********************************
 		case "Gothic_6_1":
			dialog.text = "Ага, наконец-то! А я уже начал волноваться. Генерал Ли сообщил мне о вас много лестного. Я надеюсь, что вы полностью оправдаете его и мое доверие. И учтите: все, что вы здесь услышите, никогда не должно стать известным кому-либо, кроме вас.";
			link.l1 = "Я предупрежден"+ GetSexPhrase("","а") +" об этом...";
    		link.l1.go = "Gothic_6_2";
		break;
 		case "Gothic_6_2":
			dialog.text = "Великолепно! Итак, к делу.\n"+
				          "Сейчас в европейской политике очень сложное положение. Назревает очередная торговая война между Англией и Голландией, а наш великий Король-Солнце Людовик XIV начинает деволюционную войну с Испанией.";
			link.l1 = "Простите, маркиз... Какую войну? Революционную?!";
    		link.l1.go = "Gothic_6_3";
		break;
 		case "Gothic_6_3":
			dialog.text = "Гм... Ну да, откуда же знать простому каперу.\n"+
				          "Деволюционная война - это война за наследственное право на некоторые территории. Такой для Франции, несомненно, является часть Фландрии и Бургундия, находящиеся сейчас под испанским владычеством. Это благое дело, поскольку голландцы вот уже сотню лет стремятся сбросить иго испанских дьяволов, рядящихся в церковные рясы.\n"+
						  "Для успешного ведения войны мы в крайней степени нуждаемся в деньгах голландцев, так что необходимо помешать нападению англичан на их колонии. Задание контролирует лично Жан-Батист Кольбер, надеюсь, вы знаете, кто это...";
			link.l1 = "Каким образом я долж"+ GetSexPhrase("ен","на") +" это сделать?";
    		link.l1.go = "Gothic_6_4";
		break;
 		case "Gothic_6_4":
			dialog.text = "Голландцы в состоянии постоять за себя, если генерал-губернатор Ямайки сэр Эдвард Дойли не получит подкреплений. А в этих водах они могут рассчитывать только на помощь известных корсаров, имеющих вес и авторитет в Береговом братстве.\n"+
				          "Таких, кто мог бы серьезно повлиять на ход войны, всего трое: Генри Морган на Ямайке, Торус - в поселении на Доминике, Бартоломью Роджерс в Ле Франсуа. Ваша задача – встретиться с каждым из них и убедить ни в коем случае не нападать на голландские колонии и суда. Для этой братии главное - выгода, так что средств не жалейте!";
			link.l1 = "И где же я долж"+ GetSexPhrase("ен","на") +" взять эти средства?";
    		link.l1.go = "Gothic_6_5";
		break;
 		case "Gothic_6_5":
			dialog.text = "Признаюсь, вы меня удивили. Вас рекомендовали мне, как на редкость умного и находчивого человека! Если бы эти средства у меня были - зачем, спрашивается, понадобилась бы ваша помощь? Впрочем, вы вправе отказаться, но...";
			link.l1 = "Но что тогда?";
    		link.l1.go = "Gothic_6_6";
		break;
 		case "Gothic_6_6":
			dialog.text = "Тогда мне придется отправить вас в тюрьму. Вы ведь, "+ GetSexPhrase("милейший","дорогая") +", стали обладател"+ GetSexPhrase("ем","ьницей") +" государственной тайны! С такими знаниями нелояльные люди на свободе не разгуливают.";
			link.l1 = "Сначала надо меня задержать, а это не так-то просто!";
    		link.l1.go = "Gothic_6_Fight";
			link.l2 = "Ну что ж, если король не может обойтись без моих песо, так и быть, я помогу ему!";
    		link.l2.go = "Gothic_6_7";
		break;

 		case "Gothic_6_Fight":
			CloseQuestHeader("GothicLee_6_ThreeCorsairs");
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
            for (i=1; i<=4; i++)
            {
                sld = GetCharacter(NPC_GenerateCharacter("Guard_"+i, "Guard_fra_"+(rand(7)+1), "man", "man", 30, FRANCE, 0, true, "soldier"));
				FantomMakeCoolFighter(sld, 30, 65, 50, BLADE_LONG, "pistol3", "bullet", 40);
            	LAi_SetWarriorType(sld);
                LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
               	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
            }
			LAi_group_AttackGroup("FRANCE_CITIZENS", LAI_GROUP_PLAYER);
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(NPChar, "reload", "reload1", "none", "", "", "CanFightCurLocation", 10.0);
			NPChar.LifeDay = 0;
			pchar.questTemp.GothicLee = "QuestLineBreake";
			AddQuestRecord("Gothic_6_ThreeCorsairs", "2");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

 		case "Gothic_6_7":
			dialog.text = "Вот прекрасно! Генерал Ли в вас не ошибался. Итак, я жду вас с хорошими новостями.";
			link.l1 = "Я все сделаю, маркиз.";
    		link.l1.go = "exit";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "3");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("","а"));
			pchar.questTemp.GothicLee = "ThreeCorsairs_toSeek";
			SaveCurrentQuestDateParam("questTemp");
            // ==>  Помещаем Моргана на Антигуа и даем ноду доступа к квестам
         QuestSetCurrentNode("Henry Morgan", "GothicLee6_talk");
            sld = characterFromID("Henry Morgan");
            LAi_SetLoginTime(sld, 0.0, 24.0);
            // ==>  Даем ноду доступа к квестам Бартоломью Роджерсу
            QuestSetCurrentNode("LeFransua_Mayor", "GothicLee6_talk");
            // ==>  Даем ноду доступа к квестам Торусу
            QuestSetCurrentNode("Torus", "GothicLee6_talk");
            // ==>  Оформляем счетчик посещения корсаров, в итоге должен == 3
            pchar.questTemp.Count = "0";
		break;

 		case "Gothic_6_9":
			dialog.text = "Должен заметить, что это было одно из самых непростых дипломатических поручений, которые я давал кому-либо. Человеку, который так блестяще справляется с подобными делами, просто не пристало ходить в простолюдинах. По счастью, мне даны полномочия пожаловать вам "+ GetSexPhrase("баронский титул","титул баронессы") +"! Такие люди, как вы, нужны Франции!";
			link.l1 = "Э-э... а... "+ GetSexPhrase("Баронский титул","Титул баронессы") +"? А как быть с тратами, которые я понес"+ GetSexPhrase("","ла") +"?..";
    		link.l1.go = "Gothic_6_10";
		break;
 		case "Gothic_6_10":
			dialog.text = "Ох, пират всегда останется пиратом! Ха-ха!\n"+
				          "Поверьте, "+ GetSexPhrase("милейший","дорогая") +", я даю вам гораздо больше, чем презренный металл! Я даю вам честь и уважение самого короля! А сейчас не смею вас задерживать, вас ждет Генерал Ли. Кажется, у него для вас опять какое-то важное дело... Прощайте.";
			link.l1 = "Прощайте, интендант Бонрепо...";
    		link.l1.go = "Gothic_6_11";
		break;
 		case "Gothic_6_11":
            ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Henry Morgan")], "PortRoyal_houseS1", "sit", "sit2");//Моргана на место
                    sld = characterFromID("Henry Morgan");
	     LAi_SetHuberType(sld);
			pchar.questTemp.GothicLee = "ThreeCorsairs_backGovernor";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "8");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("стал дворянином","стала дворянкой"));
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex1", GetSexPhrase("му","й"));
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex2", GetSexPhrase("ен","на"));
            LAi_SetActorType(npchar);
            LAi_ActorGoToLocation(NPChar, "reload", "reload1", "none", "", "", "", 6.0);
			if (PChar.sex == "woman")
			{
			pchar.name = "баронесса " + pchar.name;
			}
			else
			{
			pchar.name = "барон " + pchar.name;
			}
            DialogExit();
		break;

//********************************* Конец войне. Квест **********************************
 		case "Gothic_12_1":
			dialog.text = "Итак, как вы уже знаете, деволюционная война с Испанией закончена. Испания повержена!";
			link.l1 = "Да, маркиз, превосходная новость.";
    		link.l1.go = "Gothic_12_2";
		break;
 		case "Gothic_12_2":
			dialog.text = "Ваши заслуги оценены по достоинству - о вас теперь знает сам Людовик...";
			link.l1 = "Маркиз, честно говоря, мне бы хотелось несколько иной оценки моих заслуг перед Францией.";
    		link.l1.go = "Gothic_12_3";
		break;
 		case "Gothic_12_3":
			dialog.text = "Что вы имеете в виду?";
			link.l1 = "Я говорю о денежной компенсации своих затрат в этой войне. Я на своих плечах вынес"+ GetSexPhrase("","ла") +" бремя боевых действий с испанцами и хотел"+ GetSexPhrase("","а") +" бы получить компенсацию.";
    		link.l1.go = "Gothic_12_4";
		break;
 		case "Gothic_12_4":
			dialog.text = "Послушайте, вы стали дворян"+ GetSexPhrase("ином","кой") +", о вас знает Лувр! Вам этого мало?!";
			link.l1 = "Для моего самолюбия - это больше, чем много. Но я о другом говорю - о деньгах...";
    		link.l1.go = "Gothic_12_5";
		break;
 		case "Gothic_12_5":
			dialog.text = "Барон"+ GetSexPhrase("","есса") +", не делайте из меня идиота, я же не требую с вас отчета о захваченных в городах трофеях. Это и есть ваш гонорар.";
			link.l1 = "Хм, теперь ясно...";
    		link.l1.go = "Gothic_12_6";
		break;
 		case "Gothic_12_6":
			dialog.text = "Очень хорошо, что мы прояснили все нюансы, барон"+ GetSexPhrase("","есса") +". А теперь к делу - 'Солей Руаяль' выводится из состава вашей эскадры.";
			link.l1 = "Понятно...";
    		link.l1.go = "Gothic_12_7";
		break;
 		case "Gothic_12_7":
			dialog.text = "Через месяц я отправляю этот великолепный корабль в Старый Свет. Так что я благодарен вам за то, что вы сохранили его в надлежащем виде.";
			link.l1 = "Спасибо за благодарность, маркиз...";
    		link.l1.go = "Gothic_12_8";
		break;
 		case "Gothic_12_8":
			dialog.text = "Не стоит, барон"+ GetSexPhrase("","есса") +"... Ну что же, не смею вас задерживать более, до свидания.";
			link.l1 = "Всего хорошего, маркиз.";
    		link.l1.go = "exit";
			npchar.LifeDay = 0;
			pchar.questTemp.GothicLee = "EndOfQuestLine";
			AddQuestRecord("GothicLee_12_EndOfWar", "2");
			AddQuestUserData("GothicLee_12_EndOfWar", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("GothicLee_12_EndOfWar", "sSex1", GetSexPhrase("му","й"));
			CloseQuestHeader("GothicLee_12_EndOfWar");
            DeleteAttribute(pchar, "questTemp.Waiting_time");
			//==> в течение месяца Солей Руаяль можно взять себе.			
			sld = characterFromId("SoleiRoyalCaptain");
			RemoveCharacterCompanion(pchar, sld);
			SetCrewQuantityFull(sld);
			Fantom_SetBalls(sld, "pirate");
			sld.GenQuest.CrewMaltaMode  = true;
			sld.Ship.Mode = "Malta";
			Group_AddCharacter("SoleiRoyal", "SoleiRoyalCaptain");
			Group_SetGroupCommander("SoleiRoyal", "SoleiRoyalCaptain");
			Group_SetAddress("SoleiRoyal", "Guadeloupe", "Quest_ships", "quest_ship_1");
			SetTimerCondition("EndOfWar_TakeOutShip", 0, 0, 30, false);
			AddTitleNextRate(sti(NPChar.nation), 5);
			ChangeCharacterReputation(pchar, 5);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
			AddCharacterExpToSkill(pchar, "Repair", 630);
			AddCharacterExpToSkill(pchar, "Sneak", 490);
			AddCharacterExpToSkill(pchar, "FencingLight", 530);
			AddCharacterExpToSkill(pchar, "FencingHeavy", 530);
			AddCharacterExpToSkill(pchar, "Fencing", 530);
			AddCharacterExpToSkill(pchar, "Pistol", 530);
			AddCharacterExpToSkill(pchar, "Fortune", 660);
			AddCharacterExpToSkill(pchar, "Accuracy", 520);
			AddCharacterExpToSkill(pchar, "Grappling", 750);
			//слухи
			AddSimpleRumour("Говорят, что вы теперь барон"+ GetSexPhrase("","есса") +"! Вы баловень судьбы, капитан...", sti(npchar.nation), 5, 1);
		break;



    }
}
