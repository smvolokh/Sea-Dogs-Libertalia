// Торус Шардонэ, глава буканьеров и авторитетный вор и пират.
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;

// ============================= блок angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //ловушка первого срабатывания
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //сюда расписываем реакцию ангри. В npchar.angry.name пробелы удалены!!!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                    if (npchar.angry.name == "I_know_you_good") Dialog.CurrentNode = "AngryRepeat_2";
					if (npchar.angry.name == "BlueBird_1") Dialog.CurrentNode = "AngryRepeat_1";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("У тебя дело ко мне? Нет? Тогда не отвлекай меня.","Ха, " + pchar.name + "! У тебя дело ко мне? Нет? Тогда не отвлекай меня.") +"",
                         "Я кажется ясно выразился.", "Хотя я выразился и ясно, но ты продолжаешь отвлекать меня!",
                         "Та-а-ак, это уже похоже на грубость, меня это утомило.", "repeat", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Уже ухожу.",
                                               "Конечно, Торус...",
                                               "Извини, Торус...",
                                               "Ой...", npchar, Dialog.CurrentNode);
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
			//поиски брига "Черная Горгулья"
			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "Слушай, Торус, тут такое дело... В общем, не чалилась ли у тебя в порту бриг ''Черная Горгулья''?";
				link.l1.go = "BlueBird_1";
			}
			if (pchar.questTemp.BlueBird == "weWon")
			{
				link.l1 = "Представляешь, я таки отловил"+ GetSexPhrase("","а") +" этот бриг ''Черную Горгулью''!";
				link.l1.go = "BlueBird_6";
			}
			//пиратская линейка начало
			if (pchar.questTemp.piratesLine == "begin" && !CheckAttribute(pchar, "QuestTemp.AndreAbelQuest"))	
			{
				link.l1 = "Торус, я тут работу ищу какую-нибудь...";
				link.l1.go = "PL_Q1_1";
			}

			if (pchar.questTemp.piratesLine == "KillLoy_toJackman")
			{
				link.l1 = "Я ищу своего друга Эдварда Лоу, Скип сказал, что он у тебя.";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain")
			{				
				dialog.text = ""+ GetSexPhrase("Что надо?! Я не в настроении отвечать на твои вопросы!","Что надо, " + pchar.name + "? Я сейчас очень занят...") +"";
				link.l1 = "Кажется, у нас с тобой есть общее дело - Эдвард Лоу.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork" && !CheckAttribute(npchar, "quest.PQ3"))
			{
				dialog.text = "Вернул"+ GetSexPhrase("ся","ась") +"! Да не с пустыми руками!";
				link.l1 = "Готов"+ GetSexPhrase("","а") +" сообщить, что Эдвард Лоу умер с ужасом в глазах и твоим именем в ушах.";
				link.l1.go = "PL_SEAWOLF";				
			}
			if (pchar.questTemp.piratesLine == "Panama_backToShip")
			{
				dialog.text = "А, раз тебя видеть, " + pchar.name + ". Ну, что скажешь?";
				link.l1 = "Ты знаешь о том, что сделал Морган в Панаме?";
				link.l1.go = "PL_Q8";				
			}
			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotte" && !CheckAttribute(npchar, "quest.RoseauCharlotte"))
			{
				link.l1 = "Здорова, Торус! Как поживаешь? Я помню тебя, ты был одним из стражников в старом лагере!";
				link.l1.go = "RoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "NoKillwork" && !CheckAttribute(npchar, "quest.NoKillwork"))
			{
				link.l1 = "Торус, ты был прав, никто ничего не видел и не слышал.";
				link.l1.go = "NoKillwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "Торус, похоже я напал на след. Старина Джек расчищал завал к своему Маяку через винный погреб, и ему повезло, что он ещё жив. Ночью там, в подвале появляется демон и уже в человеческом обличии благодаря телам женщин из борделя...";
				link.l1.go = "ChaniSettlementGoTorus";
			}

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toTorus" && !CheckAttribute(npchar, "quest.RevengeCorsair_toTorus"))
			{
				link.l1 = "Торус, я слышал, что тебя почтил своим присутствием сам хранитель кодеса Маркус Тиракс, мне он срочно нужен - я должен кое что ему передать - это важно, не подскажешь куда он взял курс?";
				link.l1.go = "RevengeCorsair_toTorus";
			}

			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("У тебя крыша поехала? Вообразил себя мясником? Все пираты злы на тебя, приятель, так что лучше тебе убраться отсюда побыстрее.", "Ты, приятель, похоже, из ума выжил. Руки чесались сильно? Теперь не обессудь - здесь тебе делать нечего. Вали отсюда побыстрее!");
				link.l1 = RandPhraseSimple("Послушай, я хочу исправить ситуацию...", "Помоги мне решить эту проблему...");
				link.l1.go = "Roseau_town";
				break;
			}
			//поручение капитана - выкуп
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && NPChar.city == pchar.GenQuest.CaptainComission.PiratesCity)
			{
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
				{
					link.l1 = "Я по поводу твоего пленника.";
					link.l1.go = "CapComission1";
					DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
				}	
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.PirateShips"))
				{
					link.l1 = "Здравствуй Торус, я по поводу твоего поручения.";
					link.l1.go = "CapComission3";
				}
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
				{
					link.l1 = "Я по поводу твоего пленника.";
					link.l1.go = "CapComission6";
				}
			}
	
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
            dialog.text = NPCStringReactionRepeat(GetFullName(pchar) + ", рад тебя видеть! Зачем пожаловал"+ GetSexPhrase("","а") +" на этот раз?",
                         "Ну что тебе еще?", "Долго это будет продолжаться? Если тебе делать нечего, не отвлекай других!",
                         "Ты "+ GetSexPhrase("хороший капер","хорошая девушка") +", поэтому живи пока. Но общаться и разговаривать с тобой я больше не желаю.", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Да, собственно, просто так заглянул"+ GetSexPhrase("","а") +", проведать. Ничего по делу нет.",
                                               "Ничего, просто так...",
                                               "Хорошо, Торус, извини...",
                                               "Вот черт возьми, доиграл"+ GetSexPhrase("ся","ась") +"!!!", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";

			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("У тебя крыша поехала? Вообразил себя мясником? Все пираты злы на тебя, приятель, так что лучше тебе убраться отсюда побыстрее.", "Ты, приятель, похоже, из ума выжил. Руки чесались сильно? Теперь не обессудь - здесь тебе делать нечего. Вали отсюда побыстрее!");
				link.l1 = RandPhraseSimple("Послушай, я хочу исправить ситуацию...", "Помоги мне решить эту проблему...");
				link.l1.go = "Roseau_town";
				break;
			}
			//поиски брига Черная Горгулья
			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "Слушай, Торус, тут такое дело... В общем, не чалилась ли у тебя в порту бриг ''Черная Горгулья''?";
				link.l1.go = "BlueBird_1";
			}
			if (pchar.questTemp.BlueBird == "weWon")
			{
				link.l1 = "Представляешь, я таки отловил"+ GetSexPhrase("","а") +" этот бриг ''Черная Горгулья''!";
				link.l1.go = "BlueBird_6";
			}
			//пиратскся линейка начало
			if (pchar.questTemp.piratesLine == "KillLoy_toJackman")
			{
				link.l1 = "Я ищу своего друга Эдварда Лоу, Скип сказал, что он у тебя.";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain")
			{				
				dialog.text = ""+ GetSexPhrase("Что надо?! Я не в настроении отвечать на твои вопросы!","Что надо, " + pchar.name + "? Я очень занят...") +"";
				link.l1 = "Кажется, у нас есть с тобой общее дело. Эдвард Лоу.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork" && !CheckAttribute(npchar, "quest.PQ3"))
			{
				dialog.text = "Вернул"+ GetSexPhrase("ся","ась") +"! Да не с пустыми руками!";
				link.l1 = "Готов"+ GetSexPhrase("","а") +" сообщить, что Эдвард Лоу умер с ужасом в глазах и твоим именем в ушах.";
				link.l1.go = "PL_SEAWOLF";				
			}
			if (pchar.questTemp.piratesLine == "Panama_backToShip")
			{
				dialog.text = "А, рад тебя видеть, " + pchar.name + ". Ну, что скажешь?";
				link.l1 = "Ты знаешь о том, что сделал Морган в Панаме?";
				link.l1.go = "PL_Q8";				
			}
			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotte" && !CheckAttribute(npchar, "quest.RoseauCharlotte"))
			{
				link.l1 = "Здарова, Торус! Как поживаешь?";
				link.l1.go = "RoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "NoKillwork" && !CheckAttribute(npchar, "quest.NoKillwork"))
			{
				link.l1 = "Торус, ты был прав, никто ничего не видел и не слышал.";
				link.l1.go = "NoKillwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "Торус, похоже я напал на след. Старина Джек расчищал завал к своему Маяку через винный погреб, и ему повезло, что он ещё жив. Ночью там, в подвале появляется демон и уже в человеческом обличии благодаря телам женщин из борделя...";
				link.l1.go = "ChaniSettlementGoTorus";
			}

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toTorus" && !CheckAttribute(npchar, "quest.RevengeCorsair_toTorus"))
			{
				link.l1 = "Торус, я слышал, что тебя почтил своим присутствием сам хранитель кодекса Маркус Тиракс, мне он срочно нужен - я должен кое что ему передать - это важно, не подскажешь куда он взял курс?";
				link.l1.go = "RevengeCorsair_toTorus";
			}

			//поручение капитана - выкуп
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
			{
				link.l1 = "Я по поводу твоего пленника.";
				link.l1.go = "CapComission1";
				DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
			}
		break;
		//********************* пиратка, направление на квест №1 *********************
		case "PL_Q1_1":
			if(CheckAttribute(NPChar, "notQuestLine")) 
			{
				dialog.text = "Поговаривают, что ты у английских властей в большом фаворе. Неужели каперский патент перестал приносить доход?! Не стану я с тобой сотрудничать, слишком велик риск оказаться на виселице в результате твоей работы. Не взыщи...";
				link.l1 = "Ясно... Да я, собственно, просто так спросил"+ GetSexPhrase("","а") +". На всякий случай...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "У меня работы нет. Но если ты ничем не занят"+ GetSexPhrase("","а") +", то отправляйся в Вестпунт -  поищи там капитана Гудли. У него обычно всегда что-то есть.";
				link.l1 = "А что за работа у него бывает?";
				link.l1.go = "PL_Q1_2";
			}	
		
		break;

//======================= пиратская линейка ===================================

		case "PL_Q1_2":
			dialog.text = "Да когда как. Сам"+ GetSexPhrase("","а") +" у него спросишь.";
			link.l1 = "Понятно...";
			link.l1.go = "exit";
			pchar.questTemp.piratesLine = "toFirstQuest";
			AddQuestRecord("Pir_Line_0_Waiting", "2");

	sld = GetCharacter(NPC_GenerateCharacter("QuestPirate1", "officer_9", "man", "man", 20, PIRATE, -1, true, "quest"));
	sld.name = "Капитан";
	sld.lastname = "Гудли";
	sld.rank = 20;
	sld.city = "PuertoPrincipe";
	sld.location	= "Vestpunt_town";
	sld.location.group = "goto";
	sld.location.locator = "goto8";
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "PiratesMan1";
	sld.greeting = "Gr_EvilPirate";
	sld.talker = 8; //начать диалог
	sld.TiedItems.itm1.model = "HandsItems\meet";
	sld.TiedItems.itm1.locator = "Saber_hand";	
	sld.TiedItems.itm2.model = "HandsItems\cup";
	sld.TiedItems.itm2.locator = "Saber_hand";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

		break;

		//********************* пиратка, квест №3, поиски Лоу *********************
		case "PL_Q3_1":
			dialog.text = "Друга?! Хо! Ты удачно заш"+ GetSexPhrase("ел, приятель","ла") +", . Эй, ребята! А ну вали е"+ GetSexPhrase("го","е") +"!!!";
			link.l1 = "Не понял"+ GetSexPhrase("","а") +"!..";
			link.l1.go = "PL_Q3_fight";
		break;
		case "PL_Q3_fight":
			LAi_LocationFightDisable(&Locations[FindLocation("Roseau_Roomtownhall")], false);
			chrDisableReloadToLocation = true; // закрыть выход из локации.
            for (i=1; i<=3; i++)
            {
                sld = GetCharacter(NPC_GenerateCharacter("QuestPir_"+i, "pirate_"+i, "man", "man", 100, PIRATE, 0, true, "quest"));
                FantomMakeCoolFighter(sld, 100, 100, 100, "topor_02", "pistol3", "bullet", 100);
            	LAi_SetWarriorType(sld);
				LAi_SetImmortal(sld, true);
            	sld.Dialog.Filename = "Gothic_Quest\EngLineNpc_2.c";
                LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
               	ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
            }
            LAi_group_SetLookRadius("PIRATE_CITIZENS", 100);
            LAi_group_SetRelation("PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("PIRATE_CITIZENS", LAI_GROUP_PLAYER, false);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "PL_Q3_2":
			dialog.text = "Лоу?! Какие у тебя дела с Лоу?";
			link.l1 = "У меня нет дел с Лоу. Он чем-то досадил Моргану, а мне поручено этот конфликт уладить. Теперь понимаешь, зачем я его ищу?";
			link.l1.go = "PL_Q3_3";	
		break;
		case "PL_Q3_3":
			dialog.text = "Хм. Он и Моргану успел подгадить? Нельзя сказать, что я этим сильно расстроен. Но этот проходимец украл мой бриг!";
			link.l1 = "Да, я знаю, мастер на верфи мне всё рассказал.";
			link.l1.go = "PL_Q3_4";
		break;
		case "PL_Q3_4":
			dialog.text = "Да уж, тот еще гусь! У него все мозги опилками припорошены! Это ж надо додуматься, что я ему письма буду писать! Да от моей резиденции до его конуры заяц в два прыжка доскачет! А он приковылял на следующий день! Денежки захотел получить, за то, что мой бриг проморгал.\nКогда мои молодцы выкидывали этого строгальщика за порог, я ему так и сказал: Не найдется ''Морской Волк'' - шкуру живьем спущу и деньги в нее заверну! Чтоб нести легче было.";;
			link.l1 = "Но ведь он очень неплохой мастер, только рассеянный больно...";
			link.l1.go = "PL_Q3_5";
		break;
		case "PL_Q3_5":
			dialog.text = "Да это я так, сгоряча. Не буду я его трогать, никто в здравом уме такими мастерами не разбрасывается. Но я просто в ярости оттого, что у меня украли корабль! А Скип пусть маленько подрожит, умнее в следующий раз будет.\n" +
				"Значит, говоришь, убить Эдварда Лоу хочешь. Как ты понял, я тоже этого желаю. Я хочу, чтоб вор знал, за что умирает... Чтобы он знал - от Торуса безнаказанно не уходят! И чтоб все это знали! Все!!! Поэтому хочу тебя попросить, пусть Лоу знает, что смерть к нему пришла от меня, не от Моргана, а от МЕНЯ! Я думаю ты меня понимаешь.";
			link.l1 = "Хорошо, перед смертью он это услышит. Торус, ответь мне на один вопрос.";
			link.l1.go = "PL_Q3_6";
		break;
		case "PL_Q3_6":
			dialog.text = "Какой?";
			link.l1 = "Почему ты так о Моргане отозвался? Вы же вроде друзья.";
			link.l1.go = "PL_Q3_7";
		break;
		case "PL_Q3_7":
			dialog.text = "Хм, друзья... Что ж отвечу, если поймешь... Береговое Братство, Джентльмены Удачи, сокровища, женщины, слава!  Знакомые слова, правда? Когда мы юны и наивны, романтика этих слов манит нас, как мотыльков манит огонь свечи... и мы послушно летим ему навстречу.\n" +
				"Но люди все разные, кто-то из нас кружит рядом, не решаясь приблизиться, кто-то обжегся и летит прочь, кто-то безрассудно сгорает, не рассчитав своих сил. А кто-то, чьи нервы крепки, как шомпол, в этом огне перерождается, и несет его на своей шкуре, обжигая всё вокруг. Хм, я смотрю, ты не понимаешь о чем я... Слышал"+ GetSexPhrase("","а") +", наверное, выражение: ''человек человеку волк''? Так вот, все мы - волчья стая...\n"+"Стая возьмет добычу гораздо крупнее, чем волк-одиночка. Но стаю ведет вожак, которому всегда достаётся кусок добычи больше и волчица слаще. Все волки ему подчиняются, но ждут... ждут, когда он ошибется! Потому что каждый волк хочет кусок добычи побольше и волчицу послаще... Вот такая романтика.";
			link.l1 = "Гхм-да, лучше бы я не спрашивал"+ GetSexPhrase("","а") +". Мотыльки, волки... Кто сильнее - тот и прав. Я был"+ GetSexPhrase("","а") +" и останусь вол"+ GetSexPhrase("ком","чицей") +"-одиночкой. И пусть я добуду меньше, чем стая, зато "+ GetSexPhrase("волчицу себе выберу, какую сам захочу","буду делать то, что сама решу") +".";
			link.l1.go = "PL_Q3_8";
		break;
		case "PL_Q3_8":
			dialog.text = "Ха-ха-ха, ну беги, вол"+ GetSexPhrase("к","чица") +"-одиночка! И возвращайся с добычей!";
			link.l1 = "Жди, скоро буду.";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			AddQuestRecord("Pir_Line_3_KillLoy", "12");
			pchar.questTemp.piratesLine = "KillLoy_2toTavernAgain";
		break;
		//после поисков Лоу
		case "PL_SEAWOLF":
			NextDiag.TempNode = "I_know_you_good";
			npchar.quest.PQ3 = true;
	                                       int iMar = 0;
	                                       for(i = 0; i < COMPANION_MAX; i++)
	                                     {
		                    iTemp = GetCompanionIndex(pchar, i);
		                    if(iTemp > 0)
		                  {
			sld = GetCharacter(iTemp);
			if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_BRIGSW && sld.ship.name == "Морской волк") iMar = 1;
		     }
	                   } // есть ли у нас Морской волк
	                    if (iMar == 1) // есть
	                  {
				dialog.text = "Именно этих слов я и ждал. Вижу, что еще и мой Корсарский Бриг сумел"+ GetSexPhrase("","а") +" прихватить! Молодец. Ты доказал"+ GetSexPhrase("","а") +", что ты – Вол"+ GetSexPhrase("к","чица") +"! Поэтому с чистым сердцем отдаю тебе ''Морского Волка'', владей по праву! Хотел бы я иметь "+ GetSexPhrase("такого парня","такую лихую деваху") +", как ты, в своей команде!";
				link.l1 = "Я - свободный капитан, Торус. Но твои слова - честь для меня!";
				link.l1.go = "exit";
				AddQuestRecord("Pir_Line_3_KillLoy", "19");
			ChangeCharacterComplexReputation(pchar, "nobility", 3);	
			}
			else
			{
				dialog.text = "Именно этих слов я и ждал. Ну что же, спасибо тебе, "+ GetSexPhrase("приятель","подруга") +". В награду за труды даю тебе 20 тысяч песо!";
				link.l1 = "Спасибо, Торус! Эти деньги мне пригодятся.";
				link.l1.go = "exit";
				AddMoneyToCharacter(pchar, 20000);
				AddQuestRecord("Pir_Line_3_KillLoy", "20");	
				AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","а"));
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
			ChangeCharacterComplexReputation(pchar, "nobility", 3);	
			}
		break;

		//********************* пиратка, квест №6. двойник *********************
		case "PL_Q6":
			dialog.text = "О-о-о, кого я вижу?! Глазам не верю!";
			link.l1 = "Морган послал к тебе сказать, что капитан Гудли мертв.";
			link.l1.go = "PL_Q6_1";
		break;
		case "PL_Q6_1":
			dialog.text = "Вот так, значит... Новость не из приятных... И как это случилось?";
			link.l1 = "Я убил"+ GetSexPhrase("","а") +" его в резиденции Моргана... Понимаешь, тут история такая неприятная. Я по его поручению убрал"+ GetSexPhrase("","а") +" Джона Эйвори, а оказалось, что это доверенное лицо Моргана.";
			link.l1.go = "PL_Q6_2";
		break;
		case "PL_Q6_2":
			dialog.text = "Эйвори что, тоже мертв?";
			link.l1 = "Угу... В общем, в итоге Гудли на очной ставке у Моргана отказался признать, что это он нанимал меня на Эйвори. Хорошо, что Генри предварительно кое-что выяснил, и мне не пришлось доказывать, что я не верблюд.";
			link.l1.go = "PL_Q6_3";
		break;
		case "PL_Q6_3":
			dialog.text = "Ха, ну дела! А ты не в курсе, что ты еще захватил"+ GetSexPhrase("","а") +" Сида Боннета - одного из моих кэпов, и сдал"+ GetSexPhrase("","а") +" его испанцам?";
			link.l1 = "Я?!!";
			link.l1.go = "PL_Q6_4";
		break;
		case "PL_Q6_4":
			dialog.text = "Да, именно такие ходят слухи. Поэтому я слегка опешил от того, что увидел тебя здесь.";
			link.l1 = "Дьявол!! Этого ещё не хватало!";
			link.l1.go = "PL_Q6_5";
		break;
		case "PL_Q6_5":
			dialog.text = "Отправляйся к заливу Косумель, что северней Белиза. Там у бухты на фрегате ''Антверпен'' стоит Джон Лидс, у него там проблемы с командой. Мне кажется, тебе будет очень интересно его навестить...";
			link.l1 = "Хорошо, Торус, так и сделаю.";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			SetQuestHeader("Pir_Line_6_Jackman");
			AddQuestRecord("Pir_Line_6_Jackman", "2");
			AddQuestUserData("Pir_Line_6_Jackman", "sSex", GetSexPhrase("","а"));
			pchar.questTemp.piratesLine = "PL6Brother_toSantaCatalina";
			//ставим Джона Лидса в залив Косумель
			sld = GetCharacter(NPC_GenerateCharacter("JohnLids", "mercen_12", "man", "man", 30, sti(pchar.nation), -1, true, "soldier"));	
			FantomMakeCoolSailor(sld, SHIP_FRIGATE, "Антверпен", CANNON_TYPE_CULVERINE_LBS18, 80, 60, 60);
			sld.name = "Джон";
			sld.lastname = "Лидс";
			sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
			sld.dialog.currentnode   = "First time";	        
			sld.DeckDialogNode = "JohnLids";		
			sld.Abordage.Enable = false;
			sld.AnalizeShips = true; 
			sld.AlwaysFriend = true;
			sld.ShipEnemyDisable = true;
			sld.Ship.Mode = "Pirate";
			sld.greeting = "Gr_MiddPirate";
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			Group_AddCharacter("LidsGroup", "JohnLids");
			Group_SetGroupCommander("LidsGroup", "JohnLids");			
			Group_SetAddress("LidsGroup", "Beliz", "quest_ships", "Quest_ship_11");
			Group_SetTaskNone("LidsGroup");
		break;

		case "PL_Q6_after":
			dialog.text = "Джон уже рассказал мне о твоей операции с "+ GetSexPhrase("двойником","''сеcтричкой''") +". Тебе удалось узнать что-нибудь конкретное?";
			link.l1 = "Поговорить удалось, да и только. Он"+ GetSexPhrase("","а") +" слишком торопил"+ GetSexPhrase("ся","ась") +", видать, боял"+ GetSexPhrase("ся","ась") +" сболтнуть что-то лишнее.";
			link.l1.go = "PL_Q6_after_1";
		break;
		case "PL_Q6_after_1":
			dialog.text = "Это плохо. За тобой шлейф какой-то тянется, сплошные курьезы. Пока удача на твоей стороне, но стоит тебе оступиться - и тогда конец! Морган тебе не поможет.";
			link.l1 = "Я понимаю. "+ GetSexPhrase("Двойник","''Сестричка''") +" явно что-то знал"+ GetSexPhrase("","а") +"... Надо пытаться выяснить, кто за всем этим стоит.";
			link.l1.go = "PL_Q6_after_2";
		break;
		case "PL_Q6_after_2":
			dialog.text = "Верно. Ну что же, хорошо, что ты ко мне заскочил"+ GetSexPhrase("","а") +", прояснили некоторые важные детали, так сказать. Теперь отправляйся к Моргану, поведай ему о свое"+ GetSexPhrase("м двойнике","й ''сестричке''") +".";
			link.l1 = "Да, было бы неплохо... Скажи, Торус, а что ты подумал, когда услышал, что я сдал"+ GetSexPhrase("","а") +" испанцам Сида Боннета?";
			link.l1.go = "PL_Q6_after_3";
		break;
		case "PL_Q6_after_3":
			dialog.text = "Хм, а вот этого тебе лучше не знать... Тебе просто повезло, что Лидс запер "+ GetSexPhrase("двойника","''сестричку''") +" у Белиза, и "+ GetSexPhrase("тот человек","та девка") +", что сдал"+ GetSexPhrase("","а") +" Боннета, не мог"+ GetSexPhrase("","ла") +" появиться здесь так скоро, как появил"+ GetSexPhrase("ся","ась") +" ты.";
			link.l1 = "Понятно. Значит действительно повезло.";
			link.l1.go = "exit";
			SetQuestHeader("Pir_Line_6_Jackman");
			AddQuestRecord("Pir_Line_6_Jackman", "5");
			QuestSetCurrentNode("Henry Morgan", "PL_Q7_begin");
			sld = characterFromId("Henry Morgan");
			LAi_SetHuberTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
		break;

		//********************* Пиратская линейка *********************
		case "PL_Q8_deck":
			dialog.text = "Ты зря теряешь время у меня на палубе. Нам нужно срочно идти на Порто Белло!";
			link.l1 = "Да, я помню...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;
		case "PL_Q8_deck_1":
			dialog.text = "Хм, опять ты время теряешь, не пойму я тебя...";
			link.l1 = "Все в порядке, не переживай, Торус.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;

		case "PL_Q8":
			dialog.text = "Знаю, конечно...";
			link.l1 = "Что скажешь по этому поводу?";
			link.l1.go = "PL_Q8_1";
		break;
		case "PL_Q8_1":
			dialog.text = "Ничего не скажу. Да и вообще, это не наше дело, ни наш мир, пусть они строят свою цивилизацию как хотят! Так что с этими делами ко мне больше не лезь.";
			link.l1 = "Черт, как же так?!";
			link.l1.go = "PL_Q8_2";
		break;
		case "PL_Q8_2":
			dialog.text = "А вот так! В общем, я свое слово тебе сказал! Кстати Генерал Ли придерживается такой же точки зрения.";
			link.l1 = "Хм, ясно... А где он?";
			link.l1.go = "PL_Q8_3";
		break;

		case "PL_Q8_3":
			dialog.text = "Не знаю, знаю одно - будет примерно через год.";
			link.l1 = "Понятно...?";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			pchar.questTemp.piratesLine = "Panama_inEngland";
		break;


		//*************************** Генератор "Поручение капитана - Выкуп" **********************
		case "CapComission1":
			dialog.text = "Хо-хо. Ты думаешь, у меня только одни пленник? Называй, кого конкретно имеешь в виду?";
			link.l1 = pchar.GenQuest.CaptainComission.SlaveName + ". Есть такой?";
			link.l1.go = "CapComission2";
			DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
		break;

		case "CapComission2":
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.DaysLeft"))
			{
				dialog.text = "Был. Я его продал к чёртовой матери этому плантатору с Барбадоса - полковнику Бишопу, он заезжал на прошлой неделе.";
				link.l1 = "Вот чёрт...";
				link.l1.go = "CapComission2_1";
			}
			else
			{
				dialog.text = "А-а, ну наконец-то. Я уж было подумывал продать его к чёртовой матери этому плантатору с Барбадоса, он должен появиться у меня через неделю-другую... Ты выкуп привез"+ GetSexPhrase("","ла") +"?";
				link.l1 = "Слушай, Торус, тут такое дело... В общем, у меня нет таких денег. Но я готов"+ GetSexPhrase("","а") +" отработать.";
				link.l1.go = "CapComission2_2";
				if(makeint(pchar.money) > 150000)
				{
					link.l2 = "Хорошо, что не продал. Вот деньги - 150000 песо. Где я могу его забрать?"
					link.l2.go = "CapComission2_3";
				}	
			}
		break;
		
		case "CapComission2_1":
			dialog.text = "Долго ты телил"+ GetSexPhrase("ся","ась") +"... А кстати, этот невольник к тебе каким боком? Я, помнится, его родственникам выкуп назначал.";
			link.l1 = "Да я по поручению этих родственников и приехал"+ GetSexPhrase("","а") +".";
			link.l1.go = "CapComission2_11";
		break;
		
		case "CapComission2_11":
			dialog.text = "Ну, опоздал"+ GetSexPhrase("","а") +" ты - что я могу поделать?";
			link.l1 = "Слушай, а за сколько продал, если не секрет?"; 
			link.l1.go = "CapComission2_12";
		break;
		
		case "CapComission2_12":
			dialog.text = "Э-э, не секрет, конечно, но я тебе не скажу. А то смеяться будешь, ха-ха-ха-ха... Ну, бывай.";
			link.l1 = "Счастливо.";
			link.l1.go = "exit";
			AddQuestRecord("CaptainComission1", "10");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			CaptainComission_GenerateManager();
		break;
		
		case "CapComission2_2":
			if(rand(1) == 0)
			{
				dialog.text = "Гхм-гхм... Есть у меня одно дело... Даже не знаю, как начать... В общем, нужно пустить ко дну одного зарвавшегося пирата.";
				link.l1 = "А разве нельзя убрать его в джунглях?";
				link.l1.go = "CapComission2_2_1";
			}
			else
			{
				dialog.text = "Ну, " + pchar.name + ", ты же знаешь, что так дела не делаются. Приходи с деньгами и получишь своего заморыша, хе-хе.";
				link.l1 = "Ну ладно, до встречи.";
				link.l1.go = "CapComission2_4";
			}
		break;

		case "CapComission2_2_1":
			dialog.text = "Ну, понимаешь ли, так серьёзные дела не делаются... Мне не смерть его нужна, мне нужно отбить охоту у слишком ретивых разевать рот на мою часть добычи. Хотя, если он отправится к осьминогам - я не огорчусь.";
			link.l1 = "А почему тебе не послать за ним своих людей?";
			link.l1.go = "CapComission2_2_2";
		break;
		
		case "CapComission2_2_2":
			CaptainComission_GetRandomShore();
			pchar.GenQuest.CaptainComission.ShipName1 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.ShipName2 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.UnknownPirateName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);
			sLoc = XI_ConvertString(pchar.GenQuest.CaptainComission.Island + "Abl");
			dialog.text = "Хм... В общем некий " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.UnknownPirateName, NAME_NOM) + " убедил часть пиратов, что в нашем тайнике близ " + XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Gen") + " есть и их доля. Недавно они снялись с якоря и на двух судах ''" + pchar.GenQuest.CaptainComission.ShipName1 + "'' и ''" + pchar.GenQuest.CaptainComission.ShipName2 + "'' ушли к " + sLoc + ". Понимаешь теперь, почему я не могу поручить это дело своим людям?";
			link.l1 = "Понятно. И сколько у меня есть времени?";
			link.l1.go = "CapComission2_2_3";
		break;
		
		case "CapComission2_2_3":
			dialog.text = "Думаю, дней 12-15, не больше. Мне важно, чтоб они не успели добраться до тайника, иначе топить их с ценным грузом на борту не будет смысла. Уж лучше пусть везут его сюда.";
			link.l1 = "Хорошо, я берусь за это дело. Постараюсь успеть.";
			link.l1.go = "CapComission2_2_4";
		break;
		
		case "CapComission2_2_4":
			AddQuestRecord("CaptainComission1", "24");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sShipName1", pchar.GenQuest.CaptainComission.ShipName1);
			AddQuestUserData("CaptainComission1", "sShipName2", pchar.GenQuest.CaptainComission.ShipName2);
			AddQuestUserData("CaptainComission1", "sShoreName", XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Abl"));
			AddQuestUserData("CaptainComission1", "sShoreType", XI_ConvertString(GetIslandByArealName(pchar.GenQuest.CaptainComission.Island) + "Dat"));
			pchar.quest.CapComission_PirateAttack.win_condition.l1 = "location";
            pchar.quest.CapComission_PirateAttack.win_condition.l1.location = pchar.GenQuest.CaptainComission.Island;
            pchar.quest.CapComission_PirateAttack.function = "CaptainComission_GeneratePirateShips"; 
			SetFunctionTimerCondition("CaptainComission_PirateShipsOver", 0, 0, 15, false);
			pchar.GenQuest.CaptainComission.PirateShips = "goaway";	
			DialogExit();
		break;
		
		case "CapComission2_3":
			dialog.text = "Не переживай. Мои люди доставят его к тебе на борт. А он тебе кто?";
			link.l1 = "Никто. Я выполняю поручение его родственника.";
			link.l1.go = "CapComission2_31";
		break;
		
		case "CapComission2_31":
			dialog.text = "А-а, это хорошо. А то я уж было расстроился, что продешевил, назначив такую низкую цену за твоего человека. Ха-ха-ха-ха... Ну, бывай.";
			link.l1 = "Счастливо.";
			link.l1.go = "CapComission2_32";
		break;
		
		case "CapComission2_32":
			AddQuestRecord("CaptainComission1", "9");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City));			
			addMoneyToCharacter(pchar, -150000);
			DialogExit();
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission2_4":
			if(!CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				AddQuestRecord("CaptainComission1", "31");
				AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			}	
			pchar.GenQuest.CaptainComission.RepeatSpeak = true;		
			DialogExit();
		break;
		
		case "CapComission3":
			dialog.text = "Ну что, " + GetFullName(pchar) + ", пустил"+ GetSexPhrase("","а") +" на дно моего приятеля?.. хе-хе-хе...";
			if(pchar.GenQuest.CaptainComission.PirateShips == "goaway")
			{
				link.l1 = "Нет. Я не успел"+ GetSexPhrase("","а") +" их догнать. И на обратном пути они мне не попадались.";
				link.l1.go = "CapComission4";
			}
			if(pchar.GenQuest.CaptainComission.PirateShips == "died")	
			{
				link.l1 = "Да, как и договаривались - отправил"+ GetSexPhrase("","а") +" кормить акул.";
				link.l1.go = "CapComission5";
			}
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
		break;
		
		case "CapComission4":
			dialog.text = "Чёрт! Попадались - не попадались, какая теперь разница?.. Ну, и что ты предложишь дальше?";
			link.l1 = "Может, у тебя есть какое-нибудь поручение попроще?";
			link.l1.go = "CapComission4_1";
			link.l2 = "Слушай, Торус, уступи мне этого пленника подешевле...";
			link.l2.go = "CapComission4_2";
		break;
		
		case "CapComission4_1":
			dialog.text = "Нет.";
			link.l1 = "...Ну, тогда счастливо оставаться...";
			link.l1.go = "CapComission4_3";
		break;
		
		case "CapComission4_2":
			dialog.text = "Подешевле?!! Только что из-за твоей нерасторопности я лишился своего тайника! И теперь я могу уступить его подороже! Забирай за 200000, если хочешь.";
			link.l1 = "Дорого это... Прощай...";
			link.l1.go = "CapComission4_4";
			if(sti(pchar.money) >= 200000)
			{
				link.l2 = "А чёрт, держи свои деньги.";
				link.l2.go = "CapComission4_5";
			}	
		break;
		
		case "CapComission4_3":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "27");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","ла"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_DAT));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();
		break;
		
		case "CapComission4_4":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "28");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
		break;
		
		case "CapComission4_5":
			dialog.text = "Можешь забрать заморыша...";
			link.l1 = "Счастливо оставаться.";
			link.l1.go = "CapComission4_6";
		break;
		
		case "CapComission4_6":
			addMoneyToCharacter(pchar, -200000);
			AddQuestRecord("CaptainComission1", "29");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			pchar.GenQuest.CaptainComission.SlaveAddMoney = true;
			DialogExit();	
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission5":
			dialog.text = "Хо-хо! Вот это работа! Забирай своего заморыша и бывай здоров"+ GetSexPhrase("","а") +".";
			link.l1 = "Спасибо. Счастливо оставаться.";
			link.l1.go = "CapComission5_1";
		break;
		
		case "CapComission5_1":
			AddQuestRecord("CaptainComission1", "34");
			AddQuestUserData("CaptainComission1", "sName", pchar.GenQuest.CaptainComission.SlaveName);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission6":
			dialog.text = "Ты выкуп привез"+ GetSexPhrase("","ла") +"? Ведь я не шутил, когда сказал, что продам его плантаторам.";			
			link.l1 = "Слушай, "+ NPChar.name +", тут такое дело... В общем, у меня нет таких денег. Но я готов"+ GetSexPhrase("","а") +" отработать.";
			link.l1.go = "CapComission2_2";
			if(makeint(pchar.money) > 150000)
			{
				link.l2 = "Хорошо, что не продал. Вот деньги - 150000 песо. Где я могу его забрать?"
				link.l2.go = "CapComission2_3";
			}			
		break;

		//*************************** Квест "Сопровождение флейта "Орион"" **********************
        case "Andre_Abel_Quest_Torus_Dialog_1":
			dialog.text = "Что тебе от меня нужно, " + pchar.name + "?";
			link.l1 = "Я по делу, Торус...";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_2";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_2":
			dialog.text = "Выкладывай, что у тебя за дело.";
			link.l1 = "Даже не знаю как начать... В общем, я думаю, ты помнишь торговца по имени Андре Абель?";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_3";
		break;

		case "Andre_Abel_Quest_Torus_Dialog_3":
			dialog.text = "Абель?! Ха-ха... Ну что, одумался этот пройдоха?! Может ты уже привёз"+ GetSexPhrase("","ла") +" от него мою долю?";
			link.l1 = "Нет, не привёз"+ GetSexPhrase("","ла") +". Благодаря твоим стараниям, он сейчас полностью на мели, и просит прекратить его преследовать. Даже подумывает совсем свернуть дело.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_4";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_4":
			dialog.text = "А кто мне помешает его преследовать? Ты?! Думаешь, я не знаю, что он сменил корабль и торчит сейчас в Порт-о-Принсе?! Решил, что может меня надуть?!\nКороче, пусть даже не надеется улизнуть. Я не успокоюсь, пока не получу всё, что мне причитается.";
			link.l1 = "Ну что ж, решать, конечно, тебе."+ GetSexPhrase(" Только не забывай, что Земля круглая, а море большое...","") +"";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_5";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_5":
			dialog.text = ""+ GetSexPhrase("Что ты сказал?! Ты что, пытаешься мне угрожать в моей же резиденции?!\nРебята, а ну-ка вышвырните этого молодчика к чёртовой матери отсюда!","Ну конечно же мне, а кому еще! У тебя все, или еще что сказать хочешь?") +"";
			link.l1 = ""+ GetSexPhrase("Что ты, Торус? Какие угрозы? Просто напомнил, что на всё воля Провидения.","Все. Бывай, Торус.") +"";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_6";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_6":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			DoFunctionReloadToLocation("Roseau_town", "reload", "reload8_back", "Andre_Abel_Quest_After_First_Torus_Dialog");
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_7":
			dialog.text = "Опять ты? Если не привёз"+ GetSexPhrase("","ла") +" денег от Абеля, то лучше сразу разворачивайся оверштаг и не зли меня.";
			link.l1 = "Денег не привёз"+ GetSexPhrase("","ла") +", зато привёз"+ GetSexPhrase("","ла") +" письмо от Моргана.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_8";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_8":
			dialog.text = "Хм, письмо от Моргана? Ну так давай его сюда!";
			link.l1 = "Держи...";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_9";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_9":
			dialog.text = "Дьявол! Опять этот Абель?! \nЛадно, пусть живёт покамест, у меня появились дела поважнее.";
			link.l1 = "Вот и отлично.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_10";
			TakeItemFromCharacter(PChar, "letter_1");	
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_10":
			dialog.text = "Только передай "+ GetSexPhrase("своему дружку","ему") +", что я обид не прощаю! Так что пусть не попадается мне на глаза, если жить хочет..."+ GetSexPhrase(" А теперь проваливай, вместе со своим Абелем!","") +"";
			link.l1 = "Всё передам, как есть. "+ GetSexPhrase("Счастливо оставаться","Пока, Торус") +".";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_11";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_11":
			DialogExit();
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddQuestRecord("Andre_Abel_Quest", "22");
			AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
			PChar.QuestTemp.Andre_Abel_Quest_Complete = true;
		break;

        //********************** поиски брига "Черная Горгулья" ***********************
        case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("М-да, знаменитое стало корыто, что и говорить... А тебе-то зачем понадобился этот бриг?", 
				"Мы уже говорили об этом бриге.", 
				"Опять про то же?",
                "Что?! Опять?! Ну с меня хватит...", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Да видишь ли, очень ей интересуются одна группа товарищей...", 
				"Да, Торус, верно.",
                "Хм, ноты попутал"+ GetSexPhrase("","а") +", пардон...", 
				"Ай-ай!..", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
  		break;
		case "BlueBird_2":
			dialog.text = "Хе-хе, уж не торговцы ли? А то слышал я, что здорово им достается от этой ''Черной Горгульи''.";
			link.l1 = "Торговцы действительно интересуются этим бригом. Но, знаешь, мне и само"+ GetSexPhrase("му","й") +" интересно до жути, что за пернатый такой, от которого уйти нельзя. Это что же идельный каперский парусник по сути своей!";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "Ха, это так! Не ты первый, кто на нее целится из Берегового Братства, да вот никто еще не изловил. Что до меня, то лично мне эта ''птица-чудо'' не интересна - больно мала для серьезных дел.";
			link.l1 = "Торус, так ты знаешь, где бриг?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "Нет, конечно. Видеть - видел в окрестных водах, но в порт не заходила.";
			link.l1 = "Может, поделишься соображениями, где искать?";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "Нет, думал уже об этом. Ни одной здравой мысли кроме одной, с таким кароблём засаду я бы устроил на мелководье или рифах, но на сколько мне известно, есть не много мест в этом бассейне, начни поиски с Исла-Тесоро.";
			link.l1 = "Понятно. Ну что ж, спасибо и на этом, приятель.";
			link.l1.go = "exit";
		break;

		case "BlueBird_6":
			dialog.text = NPCStringReactionRepeat("Хм, поздравляю. Большая удача, черт побери! Молодец.", 
				"Поздравляю еще раз.", 
				"Это я уже слышал...",
                "Ха, да ты хвастун"+ GetSexPhrase("","ишка") +", "+ GetSexPhrase("приятель","подруга") +", каких Карибы еще не видели!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Спасибо, Торус. Доброе слово и кошке приятно...", 
				"Еще раз спасибо, Торус.",
                "А, ну да...", 
				"Горжусь этим!", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		//поиски супер-мушкета
		case "Mushket":
			dialog.text = "" + GetFullName(pchar) + " - значит будут проблемы!!!";
			link.l1 = "Торус всё шутки - шутишь?";
			link.l1.go = "Mushket_01";
		break;

		case "Mushket_01":
			dialog.text = "Говори за чем пожаловал?";
			link.l1 = "Слушай, Торус, тебе ни о чем не говорит слово ''стрела''? Может быть, одного из твоих парней так кличут, или судно пиратское так называется?";
			link.l1.go = "Mushket_1";
		break;

		case "Mushket_1":
			dialog.text = "Хм, есть такое судно - очень неплохой бриг, пожалуй, лучший на архипелаге. Только водит его не мой человек, а псих по имени Альберт Зиверт. Если бы я его сразу раскусил - ни за что бы не позволил мастеру Скипу строить для него такой кораблик.";
			link.l1 = "Чем это он тебе не угодил? Мне его найти нужно.";
			link.l1.go = "Mushket_2";
			DeleteAttribute(pchar, "questTemp.mushkett2x2");
		break;
		case "Mushket_2":
			dialog.text = "Здесь я не помощник - он сам по себе. Поговаривают - копит золото, чтоб вернуться в Европу. Я хотел его пристроить к делу, но он пустил на дно двух моих посыльных, и я перестал его искать. А он, естественно, перестал заходить в Шарлотт-Таун.\nДа и в другие порты тоже - слишком заметный у него бриг, вот и таскает за собой якорь по бухтам, а весь товар меняет на золото у контрабандистов. Так что, никто из моих с ним не якшается, если узнаю - лично на якорь поставлю.";
			link.l1 = "Да уж... Может, посоветуешь что?";
			link.l1.go = "Mushket_3";
		break;
		case "Mushket_3":
			dialog.text = "Искать, когда будешь ходить в море. Смотри внимательно за проходящими кораблями - этот бриг ты точно не пропустишь, ещё спроси у Бартоломью Роджерса этот скряга может знать...";
			link.l1 = "Ясно. Ну что ж, спасибо тебе, Торус.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "2");
		                sld = characterFromId("LeFransua_Mayor");
		                sld.dialog.currentnode = "Mushkett";
		break;
 
        //********************** Гот. линейка Ли***********************

 		case "GothicLee3_quest":
			dialog.text = "Слушаю тебя, зачем пожаловал"+ GetSexPhrase("","а") +" ко мне?";
			link.l1 = "Я прибыл"+ GetSexPhrase("","а") +" сюда по делу, ищу одного пирата, который пытался продать необычную Библию.";
			link.l1.go = "Gothic_3_1";
  		break;
 		case "Gothic_3_1":
			dialog.text = "Черт, было что-то... Вспомнить не могу... Но кто-то точно похвалялся редкой книгой, говорил, что христианская...";
			link.l1 = "И что?";
			link.l1.go = "Gothic_3_2";
  		break;
 		case "Gothic_3_2":
			dialog.text = "Да ничего. Не помню, разговор мельком был... Да и не до Библии нам было - в борделе развлекались, как-никак!";
			link.l1 = "Хм, а в каком борделе?";
			link.l1.go = "Gothic_3_3";
  		break;
 		case "Gothic_3_3":
			dialog.text = "Что в Форт-де-Франсе.";
			link.l1 = "Понятно... Спасибо, Торус.";
			link.l1.go = "exit";
			AddQuestRecord("GothicLee_3_SeekBible", "3");
			pchar.questTemp.GothicLee = "SeekBible_toFFBrothel";
			NextDiag.TempNode = "First time";
  		break;

        case "GothicLee6_talk":
            dialog.text = "Надо же, капитан " + GetFullName(pchar) + " пожаловал"+ GetSexPhrase("","а") +"! Весьма рад! Выкладывай – я же вижу, что тебе не терпится сообщить что-то интересное.";
            link.l1 = "В общем, ничего особенно интересного я не предложу. Всего только отказаться от участия в грядущей войне между Англией и Голландией.";
            link.l1.go = "Gothic_6_1";
        break;
        case "Gothic_6_1":
            dialog.text = "Да уж, действительно ничего интересного. Тем более, что я и сам не собирался впутываться в это дело. Голландев трогать - глупость, на которую пойдет только полный идиот. Так что твои покровители заставили тебя сделать лишний крюк.";
            link.l1 = "Не лишний. По крайней мере, я узнал"+ GetSexPhrase("","а") +" о твоем нейтралитете от тебя лично, а не из третьих рук.";
            link.l1.go = "exit";
			pchar.questTemp.Count = makeint(pchar.questTemp.Count)+1;
			NextDiag.TempNode = "I_know_you_good";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "5");
        break;

        //********************** "Розо" или "Шарлотт-Таун" ***********************

                                                         case "RoseauCharlotte":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты не помнишь меня? Я из старого лагеря.";
			link.l1.go = "RoseauCharlotte_1";
  		                   break;

                                                         case "RoseauCharlotte_1":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_01.wav");
			dialog.text = "Ты был одним из заключённых, возможно ты был одним из моих стражников и это делает нас теперь друзьями?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_2";
  		                   break;

                                                         case "RoseauCharlotte_1":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_02.wav");
			dialog.text = "Нет не делает!!!";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_2";
  		                   break;

                                                          case "RoseauCharlotte_2":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_03.wav");
			dialog.text = "Может быть ты тот кто уничтожил барьер, а может тот кто убил моих приятелей?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_3";
  		                   break;

                                                         case "RoseauCharlotte_3":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_04.wav");
			dialog.text = "И, что?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_4";
  		                   break;

                                                          case "RoseauCharlotte_4":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_05.wav");
			dialog.text = "Эти времена прошли! Что привело тебя сюда?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_5";
  		                    break;

                                                         case "RoseauCharlotte_5":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_5.wav");
			dialog.text = "";
			link.l1 = "Где я могу найти работу?";
			link.l1.go = "RoseauCharlotte_6";
  		                   break;

                                                         case "RoseauCharlotte_6":
			dialog.text = "Работу можешь найти в портовом управлении, в таверне Красный Фонарь, в магазине, на другом острове, я не знаю, походи, поспрашивай у людей....";
			link.l1 = "Да, да я это знаю, но хотелось бы, что - нибудь?";
			link.l1.go = "RoseauCharlotte_7";
  		                    break;

                                                          case "RoseauCharlotte_7":
			dialog.text = "Возможно, ты ведь тот парень, на сколько я помню всех доставал вопросами! Хм, есть одно дело.... Незнаю как тебе сказать.";
			link.l1 = "Говори как есть, что за дело!!!";
			link.l1.go = "RoseauCharlotte_8";
  		                   break;

                                                          case "RoseauCharlotte_8":
			dialog.text = "Давай, встетимся в борделе, я лучше покажу.";
			link.l1 = "Хорошо...";
			link.l1.go = "RoseauCharlotte_9";
  		                   break;

                                                          case "RoseauCharlotte_9":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			DialogExit();
		                   AddDialogExitQuestFunction("RoseauCharlotte_toBrothel");
  		                   break;

                                                         case "RoseauCharlotte_10":
			dialog.text = "Странно, столько людей, и никто ничего не видел?";
			link.l1 = "О чём идет речь? Кто - то потерял кольцо и ты решил вместе со мной поискать его?";
			link.l1.go = "RoseauCharlotte_11";
  		                   break;

                                                         case "RoseauCharlotte_11":
			dialog.text = "Кольцо? Ты бы ещё вспомнил о драгоценных камнях за городскими воротами. Что за бред ты несёшь? Немного терпения. Скоро всё увидишь?";
			link.l1 = "Ладно...";
			link.l1.go = "RoseauCharlotte_12";
  		                   break;

                                                          case "RoseauCharlotte_12":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload3", "Roseau_SecBrRoom", "goto", "goto3", "OpenRoseauBrothel", -1);
  		                   break;


                                                          case "RoseauCharlotte_Brothel":
	                                       sld = CharacterFromID("Torus");
	                                       LAi_ActorTurnToCharacter(sld, characterFromID("Roseau_Hostess"));
			dialog.text = "Съюзан, может, что вспомнила той ночью?";
			link.l1 = "Торус, я до сих пор не могу придти в себя, какой ужас, какой ужас...";
			link.l1.go = "RoseauCharlotte_Brothel_1";
  		                   break;

                                                          case "RoseauCharlotte_Brothel_1":
			dialog.text = "Успокойтесь, Съюзан, ну хоть что-нибудь?";
			link.l1 = "Нет, ни чего не видела, прошу вас месье...";
			link.l1.go = "RoseauCharlotte_Brothel_2";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_2":
			dialog.text = "Хорошо, ключ у вас?";
			link.l1 = "Да.";
			link.l1.go = "RoseauCharlotte_Brothel_3";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_3":
			dialog.text = "Откройте пожалуйста дверь?";
			link.l1 = "Хорошо.";
			link.l1.go = "RoseauCharlotte_Brothel_4";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_4":
			DialogExit();
			sld = characterFromId("Roseau_Hostess");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload2", "DoubleTalkWithRoseauHostess", -1.0);
  		                   break;

                                                          case "RoseauCharlotte_Brothel_5":
			DialogExit();
                                                          PlaySound("interface\key.wav");//щелк!
		                   AddDialogExitQuestFunction("RoseauCharlotte_SecBrBrothel");
  		                   break;



                                                         case "RoseauCharlotte_Brothel_6":
			dialog.text = "Как ты уже понял, речь идёт о убийстве? Но это не простое убийство и я бы не стал тут заморачиваться с тобой, поэтому мне нужны толковые, дотошные люди, вроде тебя.";
			link.l1 = "Хм...Кто был убит?";
			link.l1.go = "RoseauCharlotte_Brothel_7";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_7":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_31.wav");
			dialog.text = "Идём сам всё увидишь?";
			link.l1 = "";
			link.l1.go = "exit";
		                   AddDialogExitQuestFunction("RoseauCharlotte_BackDoor");
  		                   break;

                                                          case "RoseauCharlotte_BackDoor":
			dialog.text = "Ну, что, что ты думаешь об этом?";
			link.l1 = "Да, такое не каждый день увидишь, в наших местах такие дела проделовал мракорис, тел нет, крови нет и следов так же нет.";
			link.l1.go = "RoseauCharlotte_BackDoor_1";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_1":
			dialog.text = "Вот и я говорю - странно, здесь таких животных нет, а всё указывает либо на маньяка, либо...";
			link.l1 = "Говори!";
			link.l1.go = "RoseauCharlotte_BackDoor_2";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_2":
			dialog.text = "Я имею виду дикарей, здесь неподолёку есть деревня с местными аборигенами, но они вроде как мирные, да и с ними мы в хороших отношениях, хотя чёрт знает их, сегодня мирные, завтра воинственные.";
			link.l1 = "А ты там спрашивал?";
			link.l1.go = "RoseauCharlotte_BackDoor_3";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_3":
			dialog.text = "Навел тут шоруху везде где можно - я в тупике. Столько народу и никто, ничего, не слышал и не видел.";
			link.l1 = "Тогда, что ты хочешь от меня?";
			link.l1.go = "RoseauCharlotte_BackDoor_4";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_4":
			dialog.text = "Лицо ты тут новое, возможно я что - то упустил. Вот я и думаю с твоей помощью прощупать почву ещё раз. Расспроси всех влиятельных людей города, может кто - нибудь, что вспомнил.";
			link.l1 = "Ладно, я посмотрю, что можно сделать?";
			link.l1.go = "RoseauCharlotte_BackDoor_5";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_5":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\HOLDEINGOLD_2.wav");
		                  DialogExit();
		                  AddDialogExitQuestFunction("RoseauCharlotte_BackDoor_03");
  		                   break;

                                                          case "NoKillwork":
			dialog.text = "Так, давай поподробнее, что ты предпринял?";
			link.l1 = "Ну, я опросил всех влиятельных людей города, включая травника Константино, куратора Аршамбо де Ансильона, торговцев - в общем всех и никто, ничего не видел, не слышал...";
			link.l1.go = "NoKillwork_1";
  		                   break;

                                                          case "NoKillwork_1":
			dialog.text = "Вот чёрт!";
			link.l1 = "Кстати, куратор со мной напрочь отказался говорить и отвечать на мои вопросы. Хочу предупредить, что он на тебя составил докладную на тему всего того, что происходит в поселении на имя Шевалье Филиппа де Пуанси.";
			link.l1.go = "NoKillwork_2";
  		                   break;

                                                          case "NoKillwork_2":
			dialog.text = "А, теперь понятно кто за этим стоит - вот кто крыс канцелярский!";
			link.l1 = "Честно говоря, я подозревал его как возможного заказчика или соучастника, но мои предположения оказались беспочвенными.";
			link.l1.go = "NoKillwork_3";
  		                   break;

                                                          case "NoKillwork_3":
			dialog.text = "И, что ты предпринял?";
			link.l1 = "Ну, он любитель ночных прогулок, вот я и решил проследить за ним, так он, как оказалось всего лишь встречается с индианкой племяни Шаганумби и не более того.";
			link.l1.go = "NoKillwork_4";
  		                   break;

                                                          case "NoKillwork_4":
			dialog.text = "Хм, как интересно, ха - ха - ха, погоди-ка...";
			link.l1 = "О чём это ты?";
			link.l1.go = "NoKillwork_5";
  		                   break;

                                                          case "NoKillwork_5":
			dialog.text = "Жди меня здесь я скоро вернусь.";
			link.l1 = "Хорошо.";
			link.l1.go = "NoKillwork_6";
  		                   break;

                                                          case "NoKillwork_6":
		                   DialogExit();
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_Mayor");
  		                   break;

                                                          case "NoKillwork_7":
			dialog.text = "Ха, ты бы видел его рожу, ну ты молодец!";
			link.l1 = "Что ты имеешь ввиду?";
			link.l1.go = "NoKillwork_8";
  		                   break;

                                                          case "NoKillwork_8":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_30.wav");
		                   DialogExit();
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_Mayor_4");
  		                   break;

                                                          case "NoKillwork_9":
			dialog.text = "Я говорю о перевоплощении человека... Как быстро из гордого, надменного, самовлюблённого варга - превращается в безобидного пушистого зайца, а всего - то необходимо чуточку правды!\nТы и представить не можешь, как дворянин, с таким высоким положением, приближенный к королю и занимается любовью с женщинами третьего сорта. Если такой слушок прокатится по Карибам, его ожидают очень неприятные насмешки и поверь такая история докатится до самого Короля.\nХа, раньше я  был на его крючке - теперь он на моём!Он как миленький свой доклад разорвал на моих глазах, но конкретно по делу в ту ночь ничего нет, встретил только старого Джека, любителя маяков выходящего из винного погреба, он там постоянно ошивается.";
			link.l1 = "Что за Джек?";
			link.l1.go = "NoKillwork_10";
  		                   break;

                                                          case "NoKillwork_10":
			dialog.text = "Ворчливый старик, бывший капитан, да ты его должен знать!";
			link.l1 = "Пойду-ка пообщаюсь с ним...";
			link.l1.go = "NoKillwork_11";
  		                   break;

                                                          case "NoKillwork_11":
			dialog.text = "Если ты насчет убийства, то думаю он бесполезен.";
			link.l1 = "Ну, просто поговорю, за спрос денег не берут, во всяком случае хуже не будет?";
			link.l1.go = "NoKillwork_12";
  		                   break;

                                                          case "NoKillwork_12":
			dialog.text = "Дело твоё. И спасибо тебе, ты молодец, ха - ха! Держи краба! Да, рожа куратора - это, что - то.";
			link.l1 = "";
			link.l1.go = "exit";
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_JACK");
  		                   break;

                                                          case "ChaniSettlementGoTorus":
			dialog.text = "И, ты там был?";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_1":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_1.wav");
			dialog.text = "";
			link.l1 = "Я был в этом подвале!!!";
			link.l1.go = "ChaniSettlementGoTorus_2";
  		                   break;

                                                          case "ChaniSettlementGoTorus_2":
			dialog.text = "И, что ты видел?";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_3";
  		                   break;

                                                          case "ChaniSettlementGoTorus_3":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_3.wav");
			dialog.text = "";
			link.l1 = "Там внизу толпы монстров.";
			link.l1.go = "ChaniSettlementGoTorus_4";
  		                   break;

                                                          case "ChaniSettlementGoTorus_4":
			dialog.text = "Этого ещё не хватало, что ж, хотя сложно в это поверить, а кто ещё может подтвердить?";
			link.l1 = "Я там был не один Торус, со мной была Чани, Кики племени Шаганумби, дочь Чаки Бокира тебе это о чём - то говорит?";
			link.l1.go = "ChaniSettlementGoTorus_5";
  		                   break;

                                                          case "ChaniSettlementGoTorus_5":
			dialog.text = "Да, говорит...? Хорошо, я тебе верю.";
			link.l1 = "Кстати она просила, что бы ты извинился перед её народом, я полагаю если ты этого не сделаешь всех вас ждёт таже участь, что и в борделе!!!";
			link.l1.go = "ChaniSettlementGoTorus_6";
  		                   break;

                                                          case "ChaniSettlementGoTorus_6":
			dialog.text = "Я понимаю, на них наехал с горяча - был не прав! Хорошо я схожу к ним.";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_7";
  		                   break;

                                                          case "ChaniSettlementGoTorus_7":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_1.wav");
			dialog.text = "";
			link.l1 = "И...Что ты намерен делать дальше?";
			link.l1.go = "ChaniSettlementGoTorus_8";
  		                   break;

                                                          case "ChaniSettlementGoTorus_8":
			dialog.text = "Принесу извинения, буду готовится к устронению этого демона, наберу смелых людей и выдвинусь ночью на охоту...";
			link.l1 = "Да чуть не забыл, куратор Аршамбо де Ансильон передал тебе привет и похоже освободилась кресло губернатора. Он всё и всех послал куда подальше и ушёл к своей женщине индианке, вот так...";
			link.l1.go = "ChaniSettlementGoTorus_9";
  		                   break;

                                                          case "ChaniSettlementGoTorus_9":
			dialog.text = "Хм, непредвиденный ход, но это его дело. И так, что касается тебя, ты останешся со мной или нет, в борьбе с этим демоном?";
			link.l1 = "Думаю, да...";
			link.l1.go = "ChaniSettlementGoTorus_Yes";
			link.l2 = "Хм, нет...";
			link.l2.go = "ChaniSettlementGoTorus_No";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_6.wav");
			dialog.text = "";
			link.l1 = "Хм, нет...";
			link.l1.go = "ChaniSettlementGoTorus_No1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No1":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			dialog.text = "Как знаешь, хотя я рассчитывал на тебя! Но тем не менее выбор сделан, работой твоей я доволен. Для тебя я собрал небольшую сумму денег, изволь получить.";
			link.l1 = "Спасибо...";
			link.l1.go = "ChaniSettlementGoTorus_No2";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_13.wav");
			dialog.text = "";
			link.l1 = "Спасибо...";
			link.l1.go = "exit_No";
  		                   break;

                                                          case "exit_No":
			TakeNItems(pchar, "gold_dublon", 200);
			Log_Info("Вы получили 200 дублонов");
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_41.wav");
		                   DialogExit();
					pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.ChaniSettlementGoTorus = "true";
		                   AddDialogExitQuestFunction("No_ChaniSettlement");
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_7.wav");
			dialog.text = "";
			link.l1 = "Думаю, да...";
			link.l1.go = "ChaniSettlementGoTorus_Yes1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes1":
			dialog.text = "Отлично, я дам распоряжение за проделанную работу, денежным вознаграждением в размере 300 золотых монет в виде дублонов, получить сможешь у моего казначея Маттео и у травника Константино возми зелья для борьбы, но прежде, если не говорил со старым Джеком, то предупреди его, что бы не совался туда...";
			link.l1 = "Спасибо.";
			link.l1.go = "ChaniSettlementGoTorus_Yes2";
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-10;
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_13.wav");
			dialog.text = "";
			link.l1 = "Спасибо...";
			link.l1.go = "ChaniSettlementGoTorus_Yes3";
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes3":
			dialog.text = "Ну, мне пора выдвигаться в деревню, встретимся вечером перед маяком, не подведи...";
			link.l1 = "Смотри, что бы тебя не съели, я очень огорчусь!!!";
			link.l1.go = "exit_Yes";
  		                   break;

                                                          case "exit_Yes":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_56.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.ChaniSettlementGoTorus = "true";
		                   AddDialogExitQuestFunction("Yes_ChaniSettlement");
		                   pchar.questTemp.ChaniSettlementGoTorus = sti(pchar.questTemp.ChaniSettlementGoTorus)+1;
		                   if (sti(pchar.questTemp.ChaniSettlementGoTorus) == 2) 
		                   {
		                   AddDialogExitQuestFunction("PRESENT");
		                   }
  		                   break;




 		case "":
			dialog.text = "";
			link.l1 = "Понятно... Спасибо, Торус.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
  		break;


		//********************* Месть корсара *********************

   		case "RevengeCorsair_toTorus":
		dialog.text = "Да, Маркус Тиракс был у меня несколько дней назад, а тебе я вот, что скажу, не делал бы ты резких выводов, Барон, черные метки на всех нас распространяются.";
		link.l1 = "Что ты этим хочешь сказать?";
		link.l1.go = "RevengeCorsair_toTorus_1";
		break;

   		case "RevengeCorsair_toTorus_1":
		dialog.text = "Ничего... Есть кодекс, Морган адмирал - этим всё сказано.";
		link.l1 = "Понятно, не томи Торус - куда он направился?";
		link.l1.go = "RevengeCorsair_toTorus_2";
		break;

   		case "RevengeCorsair_toTorus_2":
		dialog.text = "К другим Баронам - искать поддержку к кому именно не подскажу.";
		link.l1 = "Я тебя услышал - бывай.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_toTorus = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_10");
		break;


 		case "Lets_go_bussines":
			dialog.text = "Рад тебя видеть, " + pchar.name + ". Какими судьбами на Доминике?";
			link.l1 = "Я по делу. Мы с Морганом атакуем Куману, ты примешь участие в деле?";
			link.l1.go = "Gothic_RevengeCorsair_6";
  		break;

 		case "Gothic_RevengeCorsair_6":
            if (GetCompanionQuantity(pchar) < 8) 
            {
    			dialog.text = "С Морганом! Хех, мой фрегат стоит на рейде, команда укомплектована, я всегда готов.";
    			link.l1 = "Тогда выступаем немедленно!";
    			link.l1.go = "Gothic_RevengeCorsair_7";
            }
            else
            {
    			dialog.text = "У вас и без меня комплект, так что без меня на этот раз.";
    			link.l1 = "Ну что ж, как знаешь, будь здоров.";
    			link.l1.go = "exit";
                NextDiag.TempNode = "First time";
            }
  		break;

 		case "Gothic_RevengeCorsair_7":
	        AddQuestRecord("RevengeCorsair", "13");
                LAi_SetActorType(npchar);
                LAi_ActorSetStayMode(npchar);
                ChangeCharacterAddressGroup(npchar, "Roseau_Roomtownhall", "goto", "goto6");
                CharacterIntoCompanionAndGoOut(pchar, npchar, "reload", "reload1", 10, false);
                Fantom_SetBalls(npchar, "pirate");
                npchar.CompanionEnemyEnable = false;  // нет отпора при обстреле
                pchar.questTemp.CompanionQuantity = makeint(sti(pchar.questTemp.CompanionQuantity) + 1);
                pchar.questTemp.CompanionQuantity.Torus = true;
                NextDiag.TempNode = "Have_hot_bussines";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;

		//Торус
		npchar = characterFromId("Torus");
		FantomMakeCoolSailor(npchar, SHIP_FRIGATE_L, "Миртана", CANNON_TYPE_CULVERINE_LBS36, 90, 90, 90);
	SetShipSailsFromFile(npchar, "ships/parus_sail_whole_white_pirate_9.tga");
		npchar.CompanionEnemyEnable = false;  // нет отпора при обстреле
		SetCharacterRemovable(npchar, false);
SetCrewQuantityFull(npchar); 
npchar.ship.Crew.Morale = 80;
npchar.Ship.Crew.Exp.Sailors = 100;
npchar.Ship.Crew.Exp.Cannoners = 100;
npchar.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(npchar, GOOD_BALLS, 3000);
SetCharacterGoods(npchar, GOOD_GRAPES, 2500);
SetCharacterGoods(npchar, GOOD_KNIPPELS, 2000);
SetCharacterGoods(npchar, GOOD_BOMBS, 1500);
SetCharacterGoods(npchar, GOOD_POWDER, 10000);
SetCharacterGoods(npchar, GOOD_WEAPON, 1000);
SetCharacterGoods(npchar, GOOD_FOOD, 2500);
SetCharacterGoods(npchar, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(npchar, GOOD_RUM, 350);
SetCharacterGoods(npchar, GOOD_PLANKS, 100);
SetCharacterGoods(npchar, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(npchar, "Capacity");
		LAi_SetImmortal(npchar, false);
                LAi_NoRebirthDisable(npchar);
		LAi_RebirthOldName(npchar);
		SetCompanionIndex(pchar, -1, sti(npchar.index));

  		break;

	 	case "Have_hot_bussines":   // Если геймеру вдруг захочется еще пообщаться, не знаю, сможет ли. Но на всякий случай.
			dialog.text = "Черт возьми, время работает против нас!";
            link.l1 = "Поспешим!";
			link.l1.go = "exit";
            NextDiag.TempNode = "Have_hot_bussines";
  		break;

	 	case "Gold_found_in_fort":    // Нода разговора в форте Куманы
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.Torus") && !IsCompanion(characterFromID("Torus")))
    		{
            	dialog.text = "Ты все видел"+ GetSexPhrase("","а") +" - мой корвет был потоплен проклятыми испанцами! Но это не беда, команда почти в полном составе вышла сухой из воды и мы продолжили драться уже на суше."+
                              "А компенсацией за труды нам будет золото. Хех, чертовы испанцы, попытались спрятать золото. Но ты был"+ GetSexPhrase("","а") +" прав"+ GetSexPhrase("","а") +", золото было здесь. Три с лишним тонны золота наше!" +
                              "Говорю это, а душа поет. Век бы такие слова говорил.";
            }
            else
            {
    			dialog.text = "Чертовы испанцы, попытались спрятать золото. Но ты был"+ GetSexPhrase("","а") +" прав"+ GetSexPhrase("","а") +", золото было здесь. Три с лишним тонны золота наше!" +
                               "Говорю это, а душа поет. Век бы такие слова говорил.";
            }
            link.l1 = "А я век бы слушал"+ GetSexPhrase("","а") +"!";
			link.l1.go = "Step_8";
        break;

	 	case "Step_8":
			dialog.text = "Ха-ха... Ты - хороший корсар, " + pchar.name + " " + pchar.lastname + ". Я желаю тебе удачи, "+ GetSexPhrase("друг","подруга") +".\n"+
                          "Мои головорезы рвутся домой после хорошей работы. Знай, что на Доминике всегда рады тебя видеть.";
			link.l1 = "Еще увидимся!";
			link.l1.go = "Step_9";
        break;

	 	case "Step_9":
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15.0);
            DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
        break;

		
		// ============== Грабеж среди бела дня, попытка залезть в сундуки =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Грабеж среди бела дня!!! Это что же такое делается?! Ну, погоди, "+ GetSexPhrase("приятель","подруга") +"...", "Эй, ты чего это там копаешься?! Никак, вздумал"+ GetSexPhrase("","а") +" ограбить меня? Ну, тогда тебе конец...", "Постой, ты куда это полез"+ GetSexPhrase("","ла") +"? Да ты вор"+ GetSexPhrase("","овка") +", оказывается! Ну, считай, что ты приплыл"+ GetSexPhrase("","а") +", родн"+ GetSexPhrase("ой","ая") +"...");
			link.l1 = LinkRandPhrase("Дьявол!!", "Каррамба!!", "А-ать, черт!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("Пошел вон","Убирайся") +" отсюда!", "Вон из моей резеденции!");
			link.l1 = "Ай...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Торусом через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Тебе не стоит отвлекать меня от дела пустыми обращениями. Впредь результат может быть более плачевным...";
        			link.l1 = "Я понял"+ GetSexPhrase("","а") +".";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryRepeat_2":
            dialog.text = RandPhraseSimple("Ты меня изрядно утомил"+ GetSexPhrase("","а") +", никакого общения.", "Я не хочу с тобой общаться, так что тебе лучше меня не беспокоить.");
			link.l1 = RandPhraseSimple("Ну как знаешь...", "Хм, ну что же...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Торусом через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Надеюсь, впредь ты не будешь утомлять меня пустыми разговорами, иначе мне придется тебя убить. Признаюсь, мне это будет очень неприятно.";
        			link.l1 = "Торус, ты можешь быть уверен - не буду...";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("Roseau_town","reload","reload8_back");
		break;
		// <<<<<<<<<<<<============= блок нод angry =============================
		case "Roseau_town":
            dialog.text = "Решить проблему? Да ты сам понимаешь, чего ты наворотил? В общем, принесешь мне миллион песо - я уговорю ребят, чтобы они забыли твои ''подвиги''. Нет - можешь катиться на все четыре стороны.";
			if (sti(Pchar.money) >= 1000000)
			{
				link.l1 = "Хорошо, я готов заплатить.";
				link.l1.go = "Roseau_town_pay";
			}
			link.l2 = "Я всё понял. Ухожу.";
			link.l2.go = "Roseau_town_exit";
		break;
		
		case "Roseau_town_exit":
			DialogExit();
            bDisableFastReload = true;//закрыть переход
			pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
			pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
			pchar.quest.pirate_in_town.function = "TownPirate_battle";
		break;
		
		case "Roseau_town_pay":
            dialog.text = "Вот и славно! Считай, что свою репутацию ты восстановил. Но впредь, я надеюсь, ты больше не будешь делать таких мерзостей.";
			link.l1 = "Не буду. Уж очень дорого они обходятся. Прощай...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			pchar.GenQuest.Piratekill = 0;
		break;

	}
}

void SetMushketCapitainInWorld()
{

}


