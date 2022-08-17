// диалоги обитателей плантаций
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp, i, n;
	string sTemp;
	bool bOk;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
        case "First time":
			dialog.text = "Вы что-то хотели?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// рабы
		case "plantation_slave":
			dialog.text = RandPhraseSimple(RandPhraseSimple("Я так устал - просто с ног валюсь.", "Нет больше сил так жить!"), RandPhraseSimple("Эта работа слишком тяжелая для меня.", "Надсмотрщики уже не оставили живого места на моей шкуре!"));				
			link.l1 = RandPhraseSimple("Сочувствую, приятель.", "Мне жаль тебя.");
			link.l1.go = "exit";				
		break;
		
		// рабы-пираты по пиратской линейке
		case "pirate_slave":
			dialog.text = RandPhraseSimple(RandPhraseSimple("Слушай, отстань от меня!", "Отвали."), RandPhraseSimple("Что тебе от меня нужно?!", "Катись к черту!"));				
			link.l1 = RandPhraseSimple("Гм...", "Ну-ну...");
			link.l1.go = "exit";				
		break;
		
		// охрана - солдаты
		case "plantation_soldier":
            dialog.text = RandPhraseSimple(RandPhraseSimple("Все вопросы - к управляющему плантацией.", "Только не отвлекай рабов от работы своими разговорами, приятель."), RandPhraseSimple("Моя задача - гонять этих бездельников.", "Ну и жарища же сегодня... впрочем, как и всегда."));
			link.l1 = RandPhraseSimple("Понятно...", "Ясно...");
			link.l1.go = "exit";
		break;
	// охрана - солдаты
		case "rudnik_soldier":
            dialog.text = RandPhraseSimple(RandPhraseSimple("Все вопросы - к управляющему рудника. Он у себя в кабинете, который расположен недалеко от шахты.", "Только не отвлекай рабов и заключённых от работы своими разговорами, приятель."), RandPhraseSimple("Моя задача - гонять этих бездельников.", "Ну и жарища же сегодня... впрочем, как и всегда."));
			link.l1 = RandPhraseSimple("Понятно...", "Ясно...");
			link.l1.go = "exit";
		break;
			// охрана - протектор
			case "plantation_protector":
              if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				if (sti(pchar.nation) == PIRATE)
				{
					PlaySound("VOICE\Russian\soldier_arest_1.wav");
    				dialog.text = RandPhraseSimple("Пираты на нашей плантации?! Ну дела... Хватай его!!", "Это пират!! Держи его!!!");
					link.l1 = RandPhraseSimple("Пират, ну и что?..", "Хех, попробуйте схватить.");
					link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с комендантом!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = RandPhraseSimple("Хо-хо, да ведь ты ходишь под флагом "+NationNameGenitive(sti(pchar.nation))+"! Думаю, комендант обрадуется, когда мы сдадим ему тебя!", "Так-так, что-то у нас тут "+NationNameAblative(sti(pchar.nation))+" завоняло! Шпионишь, мерзавец? Пора тебя познакомить с нашим комендантом!");
				link.l1 = RandPhraseSimple("Сейчас я тебя познакомлю с моей саблей.", "Думаю, что я сначала сдам тебя чертям.");
			link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с комендантом!");
			link.l2.go = "NotPegYou2";
			}
			break;
			}
			else
			{
				if (GetNationRelation(sti(NPChar.nation), GetBaseHeroNation()) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
				{
					if (sti(pchar.nation) == PIRATE)
					{
						PlaySound("VOICE\Russian\soldier_arest_1.wav");
						dialog.text = RandPhraseSimple("Пират?! Ну дела... Хватай его!!", "Это пират!! Держи его!!!");
						link.l1 = RandPhraseSimple("Да, пират, ну и что?..", "Хех, попробуйте схватить...");
				link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с комендантом!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("Кто ты и что тебе здесь нужно?", "Стой! Что ты забыл здесь?");
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "Я хочу пройти к управляющему плантацией для обсуждения торговых сделок. У меня есть торговая лицензия.";
						link.l1.go = "Licence";
					}
					else
					{
						link.l1 = "Я хочу пройти к управляющему плантацией для обсуждения торговых сделок.";
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) link.l1.go = "PegYou";
						else link.l1.go = "NotPegYou";
					}
				}
				else
				{
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("Кто ты и что тебе здесь нужно?", "Стой! Что ты забыл здесь?");
					link.l1 = "Я хочу пройти к управляющему плантацией для обсуждения торговых сделок.";
					link.l1.go = "NotPegYou";
				}
			}
		break;
		// охрана - протектор
		case "Rudnik_protector":
              if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				if (sti(pchar.nation) == PIRATE)
				{
					PlaySound("VOICE\Russian\soldier_arest_1.wav");
    				dialog.text = RandPhraseSimple("Пираты на нашем руднике?! Ну дела... Хватай его!!", "Это пират!! Держи его!!!");
					link.l1 = RandPhraseSimple("Пират, ну и что?..", "Хех, попробуйте схватить.");
					link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с комендантом!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = RandPhraseSimple("Хо-хо, да ведь ты ходишь под флагом "+NationNameGenitive(sti(pchar.nation))+"! Думаю, начальник обрадуется, когда мы сдадим ему тебя!", "Так-так, что-то у нас тут "+NationNameAblative(sti(pchar.nation))+" завоняло! Шпионишь, мерзавец? Пора тебя познакомить с нашим начальником!");
				link.l1 = RandPhraseSimple("Сейчас я тебя познакомлю с моей саблей.", "Думаю, что я сначала сдам тебя чертям.");
			link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с начальством!");
			link.l2.go = "NotPegYou2";
			}
			break;
			}
			else
			{
				if (GetNationRelation(sti(NPChar.nation), GetBaseHeroNation()) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
				{
					if (sti(pchar.nation) == PIRATE)
					{
						PlaySound("VOICE\Russian\soldier_arest_1.wav");
						dialog.text = RandPhraseSimple("Пират?! Ну дела... Хватай его!!", "Это пират!! Держи его!!!");
						link.l1 = RandPhraseSimple("Да, пират, ну и что?..", "Хех, попробуйте схватить...");
				link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с начальством!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("Кто ты и что тебе здесь нужно?", "Стой! Что ты забыл здесь?");
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "Я хочу пройти к управляющему рудником для обсуждения торговых сделок. У меня есть торговая лицензия.";
						link.l1.go = "Licence";
					}
					else
					{
						link.l1 = "Я хочу пройти к управляющему рудником для обсуждения торговых сделок.";
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) link.l1.go = "PegYou";
						else link.l1.go = "NotPegYou";
					}
				}
				else
				{
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("Кто ты и что тебе здесь нужно?", "Стой! Что ты забыл здесь?");
					link.l1 = "Я хочу пройти к управляющему рудником для обсуждения торговых сделок.";
					link.l1.go = "NotPegYou";
				}
			}
		break;

		case "Licence":
			iTemp = GetDaysContinueNationLicence(HOLLAND);
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -12)
			{
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = "Лицензия? Постой-ка... Не смеши! Я узнал тебя! Твои портреты висят в каждой казарме, и за твою поимку обещана хорошая награда. Взять его!";
				link.l1 = RandPhraseSimple("Аргх!..", "Ну, ты сам напросился...");
				link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с начальством!");
			link.l2.go = "NotPegYou2";
			}
			break;
			}
			if (iTemp == -1)
			{
				PlaySound("VOICE\Russian\soldier_arest_1.wav");
				dialog.text = "Сейчас посмотрим... Ха! Твоя лицензия просрочена и поэтому недействительна. Пожалуй, надо сдать тебя в комендатуру, голубчик...";
				link.l1 = RandPhraseSimple("Как бы не так!", "После дождичка, в четверг...");
				link.l1.go = "fight"; 
			TakeNationLicence(HOLLAND);
		Link.l2 = "Начальник, не кипишуй, может договоримся?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с начальством!");
			link.l2.go = "NotPegYou2";
			}
			break;
			}
			dialog.text = "Хорошо. Можешь проходить. Веди себя прилично и не приставай к рабам, а то им достанется из-за тебя.";
			link.l1 = "Не беспокойся, приятель.";
			link.l1.go = "plantation_exit";
		break;
		
		case "PegYou":
			PlaySound("VOICE\Russian\soldier_arest_2.wav");
            dialog.text = "Торговых сделок? Ха-ха! Меня не проведешь! Да от тебя на милю несет "+NationNameAblative(sti(GetBaseHeroNation()))+"! Шпионишь, мерзавец? Пора тебе познакомиться с нашим комендантом.";
			link.l1 = "Нет, это тебе пора познакомиться с моей саблей.";
			link.l1.go = "fight"; 
Link.l2 = "Начальник, не кипишуй, может договоримся?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("Солдат, взгляни на меня. Разве я похож на преступника?", "Совсем солдатня распоясалась... Придется поговорить об этом с начальством!");
			link.l2.go = "NotPegYou2";
			}
			break;

		case "NotPegYou":
            dialog.text = "Хорошо. Можешь проходить. Веди себя прилично и не приставай к рабам, а то им достанется из-за тебя.";
			link.l1 = "Не беспокойся, приятель.";
			link.l1.go = "plantation_exit";
		break;

	case "NotPegYou2":
			dialog.text = RandPhraseSimple("Ладно. Все в порядке, вы можете идти, " + GetAddress_Form(pchar) + ".", "Что-то я немного подустал в карауле... Все в порядке, " + GetAddress_Form(pchar) + ", прошу прощения.");
			link.l1 = "Так-то!";
			link.l1.go = "plantation_exit";
			break;

		case "plantation_exit":
           DialogExit();
		   NextDiag.CurrentNode = "plantation_repeat";
		break;
		
		case "plantation_repeat":
            dialog.text = "Давай, проходи уже, не стой, как истукан!";
			link.l1 = "...";
			link.l1.go = "plantation_exit";
		break;
		
		// управляющий в Маракайбо // Addon 2016-1 Jason
		case "Plantator":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "plant_2" && GetSquadronGoods(pchar, GOOD_SLAVES) >= 50)
			{
				dialog.text = "По какому делу зашли, сеньор?";
				link.l1 = TimeGreeting()+", сеньор. У меня к вам деловое предложение. В трюмах моего корабля находятся рабы, "+FindRussianQtyString(sti(GetSquadronGoods(pchar, GOOD_SLAVES)))+". Не желаете ли их приобрести по сходной цене?";
				link.l1.go = "mtraxx";
				break;
			}
            dialog.text = "По какому делу зашли, сеньор?";
			link.l1 = "Просто гулял по окрестностям Маракайбо и заглянул на вашу плантацию. Я уже ухожу.";
			link.l1.go = "plantator_x";
		break;
		
		case "plantator_x":
           DialogExit();
		   npchar.dialog.currentnode = "plantator";
		break;
		
		case "plantator_1":
			bOk = GetSquadronGoods(pchar, GOOD_COFFEE) >= 500 || GetSquadronGoods(pchar, GOOD_CINNAMON) >= 500 || GetSquadronGoods(pchar, GOOD_COPRA) >= 500;
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "plant_6" && bOk)
			{
				dialog.text = "А, это опять вы, сеньор. Как ваши дела?";
				link.l1 = "Я к вам с деловым предложением. У вас на плантации производят сахар и какао. Я хочу приобрести вашу продукцию, но не за деньги, а в обмен на мои товары. Может, поторгуемся?";
				link.l1.go = "mtraxx_5";
				break;
			}
            dialog.text = "А, это опять вы, сеньор. Как ваши дела?";
			link.l1 = "Спасибо, все отлично...";
			link.l1.go = "plantator_1x";
		break;
		
		case "plantator_1x":
           DialogExit();
		   npchar.dialog.currentnode = "plantator_1";
		break;
		
		case "mtraxx":
            dialog.text = "Вынужден вас огорчить, сеньор, но в данный момент наша плантация в рабах не нуждается. Недавно капитан Эдуардо де Лосада обеспечил наши потребности висельниками-пиратами, захваченными им в боевом рейде. Так что...";
			link.l1 = "Пираты работают на вашей плантации? Ох, сеньор, и как вы можете спать спокойно?";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Охрана у нас хорошая, так что бунта бояться нечего. Но в чем-то вы правы: эти канальи совсем не желают нормально работать. Я бы не покупал их, но дон губернатор так настойчиво просил уважить дона де Лосада... да и цену тот установил совсем невысокую.";
			link.l1 = "Понятно. Придется идти в Лос-Текес... Да, сеньор, вы не позволите мне немного погулять по вашей плантации и осмотреть ее? Возможно, я бы приобрел вашу продукцию на продажу...";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "Вы торговец?";
			link.l1 = "Ну, в какой-то степени да. Профессиональным купцом я себя не назову, конечно, но от выгодной негоции никогда не отказываюсь.";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "Это интересно. Ну что же, я не возражаю против вашего присутствия. Гуляйте, смотрите. Если что-то надумаете - приходите, обсудим.";
			link.l1 = "Спасибо, сеньор. Думаю, мы еще продолжим нашу беседу.";
			link.l1.go = "mtraxx_4";
		break;
		
		case "mtraxx_4":
           DialogExit();
		   NextDiag.CurrentNode = "plantator_1";
		   pchar.questTemp.Mtraxx = "plant_3";
		   AddQuestRecord("Roger_3", "5");
		   Mtraxx_PlantSetMaxRocur();
		break;
		
		case "mtraxx_5":
            dialog.text = "Почему бы и нет? Какие товары вы предлагаете на обмен?";
			if (GetSquadronGoods(pchar, GOOD_COFFEE) >= 500)
			{
				link.l1 = "Пятьсот ящиков кофе.";
				link.l1.go = "mtraxx_coffee";
			}
			if (GetSquadronGoods(pchar, GOOD_CINNAMON) >= 500)
			{
				link.l2 = "Пятьсот ящиков ванили.";
				link.l2.go = "mtraxx_cinnamon";
			}
			if (GetSquadronGoods(pchar, GOOD_COPRA) >= 500)
			{
				link.l3 = "Пятьсот ящиков копры.";
				link.l3.go = "mtraxx_copra";
			}
			if (GetSquadronGoods(pchar, GOOD_TEA) >= 500)
			{
				link.l4 = "Пятьсот ящиков чая.";
				link.l4.go = "mtraxx_tea";
			}
		break;
		
		case "mtraxx_coffee":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 16;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 100;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 100;
            dialog.text = "Пятьсот ящиков кофе? Так-так... Давайте прикинем... (считает) Я готов обменять ваш кофе на "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" мешков сахара и "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ящиков какао. Согласны?";
			link.l1 = "М-м-м... Я рассчитывал немного на большее... Но ладно. Я согласен!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_cinnamon":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 24;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 106;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 106;
            dialog.text = "Пятьсот ящиков ванили? Так-так... Давайте прикинем... (считает) Я готов обменять вашу ваниль на "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" мешков сахара и "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ящиков какао. Согласны?";
			link.l1 = "М-м-м... Я рассчитывал немного на большее... Но ладно. Я согласен!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_copra":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 25;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 100;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 100;
            dialog.text = "Пятьсот ящиков копры? Так-так... Давайте прикинем... (считает) Я готов обменять вашу копру на "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" мешков сахара и "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ящиков какао. Согласны?";
			link.l1 = "М-м-м... Я рассчитывал немного на большее... Но ладно. Я согласен!";
			link.l1.go = "mtraxx_6";
		break;

		case "mtraxx_tea":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 26;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 110;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 110;
            dialog.text = "Пятьсот ящиков чая? Так-так... Давайте прикинем... (считает) Я готов обменять ваш чай на "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" мешков сахара и "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ящиков какао. Согласны?";
			link.l1 = "М-м-м... Я рассчитывал немного на большее... Но ладно. Я согласен!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_6":
            dialog.text = "Очень хорошо! Для нас обоих это выгодная сделка! Когда произведем обмен?";
			link.l1 = "Мне надо подготовить товар. Да и вам, наверное, тоже. Начнем завтра в четыре часа вечера - как раз к закату солнца мои люди перенесут вам на плантацию все ящики.";
			link.l1.go = "mtraxx_7";
		break;
		
		
		case "mtraxx_7":
            dialog.text = "Договорились. Тогда до завтра, сеньор!";
			link.l1 = "До завтра...";
			link.l1.go = "mtraxx_8";
		break;
		
		case "mtraxx_8":
            DialogExit();
			NextDiag.CurrentNode = "plantator_1";
			AddQuestRecord("Roger_3", "10");
			Mtraxx_PlantSetMaxRocur_1();
			pchar.questTemp.Mtraxx = "plant_7";
			pchar.GenQuest.CannotWait = true;//запрет ожидания
			pchar.quest.mtraxx_plant_goods.win_condition.l1 = "ExitFromLocation";
			pchar.quest.mtraxx_plant_goods.win_condition.l1.location = pchar.location;
			pchar.quest.mtraxx_plant_goods.function = "Mtraxx_PlantFindRocurDay";
		break;
		
		case "mtraxx_9":
            dialog.text = "Ну вот, сеньор, мы и закончили. Если вам понадобится еще сахар, или какао - жду вас. На продажу, на обмен - всегда пожалуйста!";
			link.l1 = "Если прибыль с этой негоции окажется достаточно весомой - мы с вами еще встретимся. А сейчас позвольте откланяться - мне пора.";
			link.l1.go = "mtraxx_10";
		break;
		
		
		case "mtraxx_10":
            dialog.text = "Всего доброго, сеньор!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PlantAfterTrading");
		break;

	//замечение по обнаженному оружию
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
				link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "Чего размахался своей железкой? Убери её немедленно! Нечего народ пугать...", "Зачем народ пугаешь? Убери свою железяку быстро!");
				link.l1 = RandPhraseSimple("Понял"+ GetSexPhrase("","а") +".", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;

		//замечение по обнаженному оружию
		case "SoldierNotBlade":
			dialog.text = LinkRandPhrase("Чего вы клинком размахиваете?! Немедленно уберите оружие!", "Приказываю вам немедленно убрать оружие!", "Эй, " + GetAddress_Form(NPChar) + ", не пугайте народ! Уберите оружие.");
			link.l1 = LinkRandPhrase("Хорошо, убираю...", "Уже "+ GetSexPhrase("убрал","убрала") +".", "Как скажешь...");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("Черта с два!", "Сейчас пущу его в дело!", "Уберу, когда время придёт.");
			link.l2.go = "fight";
			npchar.greeting = "soldier_common";
			NextDiag.TempNode = "First Time";
		break;

//============================== Взятка =========================

	case "GiveMeSomeMoney":	
			dialog.snd = "Voice\COGU\COGU005";		
			dialog.text = "Кто знает, капитан, может и договримся...";
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000) 
			{ 
				Link.l1 = "Отлично, "+sti(NPChar.rank)*1000+" песо устроит?"; 
				Link.l1.go = "Bribe"; 
			} 
			Link.l2 = "Эх, не получится у нас с тобой договориться... Извини, ничего личного, дружище!"; 
			Link.l2.go = "fight"; 
		break;

		case "TryingToGiveBribe":
			dialog.snd = "Voice\COGU\COGU006";
			dialog.text = "Предлагаете взятку? Нет уж, мне честь мундира дороже! Извольте следовать за мной!";
			Link.l1 = "Проклятье! Жаль вас разочаровывать, сударь, но никуда я с вами не пойду!";
			Link.l1.go = "fight";
		break;

case "Bribe": 
			dialog.text = "Вполне, капитан."; 
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000))); 
			Link.l1 = "Договорились."; 
			Link.l1.go = "Bribe_1"; 
		break; 
case "Bribe_1": 
dialog.text = "Ступапйте с миром и не попадайтесь мне на глаза!"; 
			Link.l1 = "Разумеется."; 
AddCharacterExpToSkill(PChar, "Leadership", 500); 
AddCharacterExpToSkill(PChar, "Sneak", 500); 
AddCharacterExpToSkill(PChar, "Commerce", 500); 
AddCharacterExpToSkill(PChar, "Fortune", 500); 
PlaySound("_CheatSurfMenu_\Gold.wav");
			Link.l1.go = "plantation_exit"; 
		break; 
	}
} 
