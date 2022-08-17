
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		
		
		
		case "Start_GameMyCabin":
			dialog.text = "Ха-ха-ха. Я жду тебя....";
			link.l1 = "Подонок!";
			link.l1.go = "Start_GameMyCabin_exit";
		break;
		
        case "Start_GameMyCabin_exit":
		if (pchar.quest.main_line == "Takhion_Q8Q2_Repeat")
		{	AddDialogExitQuest("quest_HeadOfState_8_ToFury");	}
		else
		{	AddDialogExitQuest("Start_GameMyCabin_Beatrice3");	}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	case "quest_OnStrangerTides_Flsb":
			dialog.text = "";
			link.l1 = "Пора убираться отсюда, Джон. Ну-ка, давай...";
			link.l1.go = "quest_OnStrangerTides_Flsb_End";
		break;
		    case "quest_OnStrangerTides_Flsb_End":
			AddDialogExitQuest("quest_OnStrangerTides_1_DrFlshb_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;
			
	case "quest_OnStrangerTides_Flsb_2":
			dialog.text = "Наконец-то ты пришёл в себя. Как себя чувствуешь?";
			link.l1 = "Чёрт... г-где я... а-р-р-р-, как-к-каая боль...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_1";
		break;	
		case "quest_OnStrangerTides_Flsb_2_1":
			dialog.text = "Тихо, тихо... ты в безопасности. Я снял этот дом, здесь нас никто не найдёт. Ни кто бы то ни было ещё.";
			link.l1 = "Бр-р-рай-йан?";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_2";
		break;	
		case "quest_OnStrangerTides_Flsb_2_2":
			dialog.text = "Да, да, я! Чёрт, тебе крепко досталось... дьявол...";
			link.l1 = "А-г-р-р... Бр-райан... Б-б-боль...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_3";
		break;		
		case "quest_OnStrangerTides_Flsb_2_3":
			dialog.text = "Спокойно ты! Да, ситуация не из лучших, но ты должен радоваться, что вообще остался жив! И что я пришёл, что я вернулся за тобой... а ведь я мог этого и не сделать, Джон! Ты понимаешь?";
			link.l1 = "Д-да... спас-сибо, Б-р-райан...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_4";
		break;	
		case "quest_OnStrangerTides_Flsb_2_4":
			dialog.text = "Не вешай нос, Джон. Когда ты поправишься, а ты обязательно поправишься, мы с тобой вернёмся в игру. Мы отомстим ублюдкам, сделавшим это с тобой!  Слышишь меня? Мы отомстим всем нашим врагам!";
			link.l1 = "Мы от-то-мстим...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_Ext";
		break;		
		    case "quest_OnStrangerTides_Flsb_2_Ext":
			AddDialogExitQuest("quest_OnStrangerTides_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;		
	
	case "quest_HeadOfState_1":
			dialog.text = "Наконец-то! Я уже заждался тебя. Какого чёрта, где ты пропадал" + GetSexPhrase("","а") + "?";
			link.l1 = "Что? Ты кто такой?";
			link.l1.go = "quest_HeadOfState_1_1";
		break;	
		case "quest_HeadOfState_1_1":
			dialog.text = "Что?.. Ты не узнаёшь меня?";
			link.l1 = "Вроде нет... а должен?";
			link.l1.go = "quest_HeadOfState_1_2";
		break;	
		case "quest_HeadOfState_1_2":
			dialog.text = "Дьявол! Это всё это проклятое место... Я Брайан Резак.";
			link.l1 = "А, Резак! Я слышал о тебе. Кажется, лидер Белых?..";
			link.l1.go = "quest_HeadOfState_1_3";
		break;		
		case "quest_HeadOfState_1_3":
			dialog.text = "Что?! Дьявол тебя подери, "+ GetFullName(Pchar)+", какие к чёртовой матери Белые! Я рад, что ты здесь, правда, рад. Я знаю, между нами не всё было гладко, много всякой чертовщины натворили, но слушай – всё, что нам нужно – это выбраться отсюда. Нам здесь никто не поможет кроме нас самих! Выберемся, вытащим Беатрис – и я скроюсь! И Джона прихвачу с собой. Ты меня больше никогда не увидишь. Но сейчас мне нужна твоя помощь. Что скажешь?";
			link.l1 = "Прости... я... я не совсем понимаю тебя. Кто такая Беатрис?";
			link.l1.go = "quest_HeadOfState_1_4";
		break;		
		case "quest_HeadOfState_1_4":
			dialog.text = "Чёрт... ты так" + GetSexPhrase("ой","ая") + " же, как и эта девчонка! Чёрт, ну почему я-то остался таким же, как и был там?! А вы, вы все словно младенцы, словно с чистого листа!";
			link.l1 = "О чём ты?";
			link.l1.go = "quest_HeadOfState_1_5";
		break;	
		case "quest_HeadOfState_1_5":
			dialog.text = "Послушай, парень: тебя зовут "+ GetFullName(Pchar)+". Ты был" + GetSexPhrase("","а") + " испанским капитаном, свободным капером. Ты однажды прибыл" + GetSexPhrase("","а") + " в Карибское море из Европы, из города Сан-Себастьян, по ложному назначению. Тебе пришлось пройти через многое, в том числе... через меня. Ну, это можно опустить. У тебя была любимая сестрёнка – Беатрис . Ты ведь помнишь? Рыжая такая, зелёные глаза.";
			link.l1 = "Хм... рыжая говоришь...";
			link.l1.go = "quest_HeadOfState_1_6";
		break;	
		case "quest_HeadOfState_1_6":
			dialog.text = "Она, конечно, никогда не любила тебя слишком сильно. Но несколько лет назад вас разлучил шторм. Тебя выбросило на берег, а твой корабль, команда и девчонка Беатрис – пропали без вести. С тех пор ты искал" + GetSexPhrase("","а") + " её и именно поэтому в конце концов очутил" + GetSexPhrase("ся","ась") + " здесь.";
			link.l1 = "Так значит... Беллатриса?..";
			link.l1.go = "quest_HeadOfState_1_7";
		break;	
		case "quest_HeadOfState_1_7":
			dialog.text = "Так её здесь зовут. Но это роли не играет. Да, Беатрис здесь. Та, которую ты искал" + GetSexPhrase("","а") + " все эти годы. Ты буквально в метрах от неё. Но всё это ни черта не даёт, пока мы гниём здесь взаперти!";
			link.l1 = "Взаперти?";
			link.l1.go = "quest_HeadOfState_1_8";
		break;	
		case "quest_HeadOfState_1_8":
			dialog.text = "Это ловушка, " + PChar.name + ". Я не до конца изучил её, но знаю, что отсюда можно выбраться, хотя никто из жителей никогда не поверит в это. Они словно заколдованы! Им невозможно ничего втолковать. Они здесь все рехнувшиеся. Либо вообще мертвецы с того света.";
			link.l1 = "Почему ты хочешь выбраться?";
			link.l1.go = "quest_HeadOfState_1_9";
		break;	
		case "quest_HeadOfState_1_9":
			dialog.text = "Дьявол, да это же ненастоящий мир, " + PChar.name + "! Это – тюрьма. Тюрьма разума и тела одновременно. Ты здесь останешься навечно, ты здесь становишься другим, ты уже потерял всю свою память, но это только начало... Он уничтожит тебя, понимаешь? Он уничтожит тебя изнутри.";
			link.l1 = "Кто? Кто уничтожит меня?";
			link.l1.go = "quest_HeadOfState_1_10";
		break;	
		case "quest_HeadOfState_1_10":
			dialog.text = "Чёртов чокнутый, что здесь заправляет, " + PChar.name + "! Архитектор! Ты ведь знаком с ним?";
			link.l1 = "А, конечно. С Его Величеством я в хороших отношениях. Я выполняю для него некоторые поручения... Мы готовимся к Белому Восстанию.";
			link.l1.go = "quest_HeadOfState_1_11";
		break;	
		case "quest_HeadOfState_1_11":
			dialog.text = "Что?!? " + PChar.name + ", брось эту чертовщину! Я подозреваю, что он единственный знает, что здесь происходит на самом деле, но я не хочу знать подробностей! Я хочу просто убраться отсюда! И раз уж ты заговорил о Восстании – да, и это наш единственный шанс!";
			link.l1 = "Хочешь сказать, ты помогаешь Белым только ради своей выгоды?..";
			link.l1.go = "quest_HeadOfState_1_12";
		break;	
		case "quest_HeadOfState_1_12":
			dialog.text = "Дьявола на твою голову, " + PChar.name + ", какие Белые, какие Чёрные, какая выгода, здесь все сумасшедшие, это же полное безумие, нам просто нужно убраться отсюда! Ты, я и Беатрис! Мы трое, только нас троих ещё можно спасти. Беатрис провела здесь слишком много времени, но я верю, что её тоже можно спасти. Её разум ещё не до конца затуманен. Она доверяет мне и уж она точно поверит тебе.";
			link.l1 = "Почему я должен верить тебе?";
			link.l1.go = "quest_HeadOfState_1_13";
		break;	
		case "quest_HeadOfState_1_13":
			dialog.text = "Чёрт... да потому что я Брайан Резак. Потому что я реальный человек, потому что ты знаешь меня! Потому что я знаю как выбраться, потому что здесь со мной Беатрис, да сколько ещё тебе причин нужно назвать?!?";
			link.l1 = "Пока не было ни одной убедительной. Видишь ли, я верю Его Величеству.";
			link.l1.go = "quest_HeadOfState_1_14";
		break;	
		case "quest_HeadOfState_1_14":
			dialog.text = "Проклятье... ладно, слушай. Знаешь, где сейчас на самом деле крошка Беатрис? Нет, она не на ‘Веласко’, как думают все эти болваны из Палаты! Это я внушил им, что она там, но её там нет! На самом деле она заточена на 'Тартарусе'! Это он её туда посадил! Архитектор!";
			link.l1 = "Что ж... я долж" + GetSexPhrase("ен","на") + " увидеть её.";
			link.l1.go = "quest_HeadOfState_1_15";
		break;	
		case "quest_HeadOfState_1_15":
			dialog.text = "Нет, это невозможно! Тебя не пустят на 'Тартарус'. Для этого нужно личное разрешение Архитектора.";
			link.l1 = "Ну, тогда я пойду и получу его.";
			link.l1.go = "quest_HeadOfState_1_16";
		break;	
		case "quest_HeadOfState_1_16":
			dialog.text = "Стой, " + PChar.name + "! " + PChar.name + "! Чёрт, чёрт!..";
			link.l1 = "";
			link.l1.go = "quest_HeadOfState_1_Ext";
		break;			
		    case "quest_HeadOfState_1_Ext":
			AddDialogExitQuest("quest_HeadOfState_4_VelRezakGoOut");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;
			
	case "quest_HeadOfState_2":
			dialog.text = "" + PChar.name + ", Беатрис здесь! Она на 'Тартарусе'! Мы должны освободить её и сбежать отсюда!";
			link.l1 = "Нет! Ты лжёшь мне! Она изменила мне с тобой!";
			link.l1.go = "quest_HeadOfState_2_1";
		break;
		case "quest_HeadOfState_2_1":
			dialog.text = "Что? Что за чушь ты несёшь?!";
			link.l1 = "";
			link.l1.go = "quest_HeadOfState_2_Ext";
		break;	
		    case "quest_HeadOfState_2_Ext":
			AddDialogExitQuest("quest_HeadOfState_6_7thFightDlgHmslf2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;	

	case "quest_HeadOfState_3":
			dialog.text = "";
			link.l1 = "Всё кончено, Резак! Я не знаю, как ты выжил, но я это исправлю!";
			link.l1.go = "quest_HeadOfState_3_1";
		break;	
		case "quest_HeadOfState_3_1":
			dialog.text = "Идиот" + GetSexPhrase("","ка") + "... ты идиот" + GetSexPhrase("","ка") + "! Ты ни черта не понимаешь!";
			link.l1 = "Отправляйся в ад, дьявол!!!";
			link.l1.go = "quest_HeadOfState_3_Ext";
		break;	
		    case "quest_HeadOfState_3_Ext":
			AddDialogExitQuest("quest_HeadOfState_8_FuryShot");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;		
			
		
		
	}
}


