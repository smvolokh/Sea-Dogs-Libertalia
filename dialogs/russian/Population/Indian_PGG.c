// Другие ПГГ
void ProcessDialogEvent()
{
	ref NPChar, sld;
	string sTmp, sLoc;
	aref Link, NextDiag;

	ref    	rItm, rItem;
	string 	attr, attrLoc, sGun, sBullet, attrL, sAttr;
	int    	iTemp, iTax, iFortValue, i;
	aref 	rType;

	int iHour;
	int iRnd = -1;
	int iAns;
	string sLocation;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // индекс в конце
 	    Dialog.CurrentNode = "SetGunBullets2";
	}
    if (CheckNPCQuestDate(npchar, "Card_date"))
	{
		SetNPCQuestDate(npchar, "Card_date");
		npchar.money = 5000 + (rand(10)+1) * makeint(100 * 	sti(PChar.rank) * (10.0 / MOD_SKILL_ENEMY_RATE));
	}
	switch(Dialog.CurrentNode)
	{

case "First time":
dialog.text = "Привет тебе, морской брат! Рад видеть тебя наш деревня! Я могу помочь тебе?";
link.l1 = "Приветствую! Я тут подумал"+ GetSexPhrase("","а") +", не хочешь ко мне присоединиться? Вместе мы сможем хорошие дела провернуть.";
link.l1.go = "companion";
link.l2 = "Поторгуем, брат?";
link.l2.go = "Trade_1";
link.l3 = "Здравствуй, друг! Не желаеешь ли партейку, отдохнуть от дел?";
link.l3.go = "Play_Game";
link.l4 = "Я просто решил снова поприветствовать тебя! Удачи!";
link.l4.go = "exit";	
break;

		case "companion":
		Dialog.Text = "Если вы читаете это, значит, вы поймали баг ;) Сообщите об этом Navy, подробно, как вы его поймали :)";
		link.l1 = "Обязательно!!!!";
		link.l1.go = "exit";
		//раз в день.
		if (CheckAttribute(NPChar, "Companion_Talk") && GetNpcQuestPastDayParam(NPChar, "Companion_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("Я тебе всё сказать.", "Мы уже говорить об этом, брат.");
			link.l1 = RandPhraseSimple("Как я мог"+ GetSexPhrase("","ла") +" забыть?!", "И правда. Удачи!");
			link.l1.go = "exit";
			break;
		}
		//корабль где?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("Где твой каноэ? Как я могу идти вместе с тобой?", "Сначала найди большой каноэ, брат, а потом только что-то предлагай	...");
link.l1 = RandPhraseSimple("Не беспокойся, друг, скоро у меня будет каноэ!", "Ой, это временное недоразумение... Не волнуйся.");
			link.l1.go = "exit";
			break;
		}
		//не друг индеям
		if (sti(pchar.questTemp.Indian.relation) < 89)
		{
			Dialog.Text = RandPhraseSimple("Ты не друг индеец, я не пой	ти с тобой.", "Я не буду идти за тобой, ты не друг индеец.");
link.l1 = RandPhraseSimple("Ну, как хочешь...", "Что ж, счастливо оставаться.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//есть ли место для компаньона
		if (GetCompanionQuantity(pchar) > 7)
		{
			Dialog.Text = RandPhraseSimple("В твоём войске много каноэ, я не пойду с тобой.", "У тебя и так много каноэ, зачем тебе ещё одно?");
			link.l1 = "Да... Может может ты и прав.";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
break;
		}
		if (SetCompanionIndex(pchar, -1, sti(NPChar.index)) != -1)
		{
			Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
					RandPhraseSimple("Я пойду за тобой, брат! Вместе мы убьём много врагов!", "Ты быть хороший воин, вместе мы соберём много скальпов!"), 
					LinkRandPhrase("Я согласен. Теперь мы пойдём одной тропой.", 
					"Духи мне подсказывают, что я должен идти за тобой! Я согласен.", "Я пойду за тобой. Теперь у нас одна дорога на двоих, брат."));
			link.l1 = RandPhraseSimple("Отлично, жду тебя в море!", "По рукам! Мы будем отличной командой.");
			link.l1.go = "exit_company";
			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
            	NPChar.Payment = true;
                
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			SetCharacterRemovable(NPChar, true);
			SaveCurrentNpcQuestDateParam(NPChar, "Companion.CheckRelation");
		}
		else
		{
			Dialog.Text = RandPhraseSimple("В твоём войске много каноэ, я не пойду с тобой.", "У тебя и так много каноэ, зачем тебе ещё одно?");
			link.l1 = "Да... Может ты и прав.";
			link.l1.go = "exit";
		}
		break;

		
	// на Тайясаль
		case "tieyasal":
			dialog.text = "Духи хранят тебя, брат. Я пойти за тобой и в этот поход!";
			link.l1 = "Спасибо, брат! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Когда мы будем отправляться?";
			link.l1 = "Немного позже. А пока подготовимся к походу.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21_1");
			npchar.quest.Tieyasal = "teleport";
		break;

//  Приказы для компаньона -->			
			case "Companion_Tasks":
			dialog.Text = "Внимательно слушаю.";
			Link.l1 = "Это касается абордажа.";
			Link.l1.go = "Companion_TaskBoarding";
			Link.l2 = "Это касается твоего корабля.";
			Link.l2.go = "Companion_TaskChange";
			Link.l3 = "Пока ничего.";
			Link.l3.go = "exit_company";
			break;

		case "Companion_TaskBoarding":
			dialog.Text = "Что скажешь?";
			Link.l1 = "Я хочу чтобы ты не брал корабли на абордаж. Побереги себя и свою команду.";
			Link.l1.go = "Companion_TaskBoardingNo";
			Link.l2 = "Мне нужно чтобы ты брал вражеские корабли на абордаж.";
			Link.l2.go = "Companion_TaskBoardingYes";
		break;
		
		case "Companion_TaskChange":
			dialog.Text = "Что скажешь?";
			Link.l1 = "Я хочу чтобы ты не менял свой корабль после абордажа. Он слишком ценен.";
			Link.l1.go = "Companion_TaskChangeNo";
			Link.l2 = "Когда будешь брать врагов на абордаж, посмотри, вдруг кораблик приличный будет, тогда бери себе.";
			Link.l2.go = "Companion_TaskChangeYes";
		break;
		
		case "Companion_TaskBoardingNo":
			dialog.Text = "Хорошо.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = false;
		break;
		
		case "Companion_TaskBoardingYes":
			dialog.Text = "Будет исполнено.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = true;
		break;
		
		case "Companion_TaskChangeNo":
			dialog.Text = "Так точно.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = false;
		break;
		
		case "Companion_TaskChangeYes":
			dialog.Text = "Будет исполнено.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = true;
		break;
// Приказы для компаньона  <--

//  Выходы -->	
	
		case "exit_quest":
			Dialog.Text = "Я же сказал, что жду тебя на своём каноэ!";
			link.l1 = "Да-да. Я помню...";
			link.l1.go = "exit_1488";
		break;

		case "exit_1488":
		NextDiag.CurrentNode = "exit_quest";
		DialogExit();
		break;
		
		case "Exit_ShowParam":
			NextDiag.CurrentNode = "First time";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;

	case "Exit_ShowParam_1488":
			NextDiag.CurrentNode = "Quest_1_End";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;


			case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "exit_duel":
			NextDiag.CurrentNode = "exit_1";
			DialogExit();
		break;

		case "exit_1":	
			Dialog.Text = "До встречи в море, мерзавец.";
			link.l1 = "Говори-говори, да не заговаривайся."; 
			link.l1.go = "exit_duel";
		break;	

		case "exit_sit":			
			NextDiag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

		case "exit_company":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
		break;

	case "exit_huber":
			NextDiag.CurrentNode = "Gover_Main";
			DialogExit();
		break;

case "exit_228":	
Dialog.Text = "Что-то ещё?";
link.l1 = "Да нет, ничего."; 
link.l1.go = "exit_uvol";
break;
	
case "exit_uvol":
NextDiag.CurrentNode = "exit_228";
DialogExit();
break;
	
case "exit_148":
NextDiag.CurrentNode = "Quest_1_End";
DialogExit();
break;

// Выходы <--

//  Приказы -->	

case "exit_2":
dialog.Text = "Слушаю тебя, брат!";
Link.l1 = "Слушай мою команду!";
Link.l1.go = "prikaz";
if (CheckAttribute(NPChar, "IsCompanionClone"))
			{
	dialog.text = "Да, брат?";
	Link.l1 = "У меня есть для тебя несколько приказов.";
	Link.l1.go = "Companion_Tasks";
			}
	if (IsCompanion(NPChar))
			{
	dialog.Text = "Скоро мы снова мыйдем в море!";
	Link.l1 = "Да, я тоже рад.";
	Link.l1.go = "exit_company";
			}
		break;

case "prikaz":
dialog.Text = "Да, брат?";
if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l1 = ""+npchar.name+", я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты готов последовать за своим капитаном?";
				Link.l1.go = "tieyasal";
			}
			
			if (isOfficer(Npchar)) // проверка для кампуса, где слотовые офы
			{
				Link.l2 = "Слушай мой приказ!";
				Link.l2.go = "stay_follow";
			}

           		// boal отчет о корабле
			if(CheckAttribute(NPChar, "treasurer") && NPChar.treasurer == 1)
			{
			    Link.l3 = "Дай мне полный отчет о корабле, " + GetStrSmallRegister(XI_ConvertString("treasurer")) + ".";
			    Link.l3.go = "QMASTER_1";
			        
			    // Warship. Автозакупка товара
			    if(!CheckAttribute(PChar, "TransferGoods.Enable"))
			    {
				    Link.l11 = "Я хочу, чтобы, во время стоянки в колонии, ты закупал товары.";
				    Link.l11.go = "TransferGoodsEnable";
			    }
			    else
			    {
				    Link.l11 = "Знаешь, закупать товары в колониях не нужно.";
				    Link.l11.go = "TransferGoodsDisable";
			    }
			}
			
			if (pchar.location != "My_Campus") // patch-5
			{
			Link.l4 = "Я более не нуждаюсь в ваших услугах.";
			Link.l4.go = "AsYouWish";
			}
			
			
			// по тек локации определим можно ли тут приказать  -->
			if(IsEntity(loadedLocation))
			{
				if(CheckAttribute(loadedLocation, "fastreload"))
				{
					iTemp = FindColony(loadedLocation.fastreload);
					if(iTemp != -1)
					{
						sld = GetColonyByIndex(iTemp);
						if(sti(sld.HeroOwn) == true && !CheckAttribute(sld, "OfficerIdx"))
						{
							NPChar.ColonyIdx = iTemp;
							Link.l5 = "Я назначаю тебя наместником этого города!";
							Link.l5.go = "Gover_Hire";
						}
					}
				}
			}
			
			Link.l6 = "Ничего. Вольно.";
			Link.l6.go = "exit_company";
		break;
		
		case "TransferGoodsEnable":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
	        {
				dialog.text = "Капитан, какие товары?! Нужно сначала корабль где-нибудь раздобыть!";
				Link.l1 = "Да, ты прав.";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
	        }
	        	
			PChar.TransferGoods.Enable = true;
		//	PChar.TransferGoods.TreasurerID = NPChar.id;
			Dialog.text = "Будет исполнено, "+ GetSexPhrase("господин","госпожа") +" капитан!";
			Link.l1 = "Вольно.";
			Link.l1.go = "TransferGoodsEnable_2";
        break;
        	
		case "TransferGoodsEnable_2":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
			LaunchTransferGoodsScreen(); // Интерфейс автозакупки товаров
		break;
		
		case "TransferGoodsDisable":
			DeleteAttribute(PChar, "TransferGoods.Enable");
			Dialog.text = "Будет исполнено, "+ GetSexPhrase("господин","госпожа") +" капитан.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;


case "QMASTER_1":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
			{
				dialog.text = "Капитан, но у нас ведь нет корабля!";
				Link.l1 = "Спасибо, напомнил...";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
			}
			
			dialog.text = "Максимальная активность крыс в рейсе " +
			FloatToString(50.0 / (2.0+GetSummonSkillFromNameToOld(PChar, SKILL_REPAIR) + GetSummonSkillFromNameToOld(PChar,SKILL_SNEAK)), 1) +
			"% от количества груза. На "+GetCrewQuantity(PChar) + " матросов нужно " + makeint((GetCrewQuantity(PChar)+6) / 10) + " провианта в день. Это без учета перевозимых рабов.";
			Link.l1 = "Спасибо.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;
        
        case "stay_follow":
            dialog.Text = "Какие будут приказания?";
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l4 = "Я хочу, чтобы ты держался на определенном расстоянии от цели.";
				Link.l4.go = "TargetDistance";
			}
            Link.l1 = "Стой здесь!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "Следуй за мной и не отставай!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "Нужно изменить тип боеприпаса для твоего огнестрельного оружия.";
					Link.l3.go = "SetGunBullets";
				}	
			}		
		break;

		case "SetGunBullets":
			Dialog.Text = "Выбор типа боеприпаса :";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = "exit_2";
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
		case "TargetDistance":
			dialog.text = "На каком именно, капитан? Укажите в метрах, но не более 20-ти.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "Капитан, что за дурной тон!";
				link.l1 = "Извини, ошибочка вышла...";
				link.l1.go = "exit_company";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "Я буду стоять на месте, никуда не двигаясь. Вас это устраивает, капитан?";
				link.l1 = "Да, именно это от тебя и требуется.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "Я кажется говорил, что более 20 метров от цели мне держаться нельзя.";
				link.l1 = "Хорошо, держись на расстоянии в 20 метров.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "Задачу понял, принимаю к сведению.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit_company";
			npchar.MusketerDistance = iTemp;
		break;

		case "AsYouWish":
			// проверка на море -->
			if (bSeaActive)
			{
				attr = Sea_FindNearColony();
				if (attr == "none")
				{
					dialog.text = "Капитан, хоть мне и непонятна причина такого заявления - давайте вернёмся к этому вопросу на берегу. Или вы решили просто выбросить меня за борт?";
					Link.l1 = "Хм... нет, я не это имел"+ GetSexPhrase("","а") +" в виду. Оставайся, пока не придём в порт.";
					Link.l1.go = "exit_company";	
					break;	
				}
			}
			// проверка на море <--
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) < 41) //герой против злодея
			{
				dialog.text = RandPhraseSimple(LinkRandPhrase("Вот это новость!","С какой это радости?!","С чего это вдруг?!"), RandPhraseSimple("Капитан, вы в своём уме? Сообщать такие новости ни с того, ни с сего!","Ого! И чем это я вам не угодил?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Я решил"+ GetSexPhrase("","а") +" навести порядок в эскадре. И, поскольку мне не нравятся твои взаимоотношения с коллегами,","Твои достоинства оказались не так хороши, как расписывалось при найме, поэтому","Головорезов и проходимцев в моей команде не будет! Поэтому"), LinkRandPhrase("Мне стало известно, что ты тайком таскаешь ром и спаиваешь команду, тем самым ослабляя её боевой дух. Поэтому","Мне чертовски надоели твои разбойничьи замашки, я не намерен"+ GetSexPhrase("","а") +" терпеть их бесконечно. Так что,","Ты постоянно проводишь время в кают-компании за игрой в карты или кости, отвлекая других офицеров от несения службы. Это не может продолжаться бесконечно, поэтому")) + " собирайся и покинь судно.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A1_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A1_strife";
				}
				break;	
			}
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) >= 41) // герой против героя
			{
				dialog.text = RandPhraseSimple(RandPhraseSimple("Могу я узнать причины такого решения?","Наверняка такое решение имеет веские причины?"), RandPhraseSimple("Прошу объясниться, капитан","Весьма неожиданно. Но хотелось бы знать основания."));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Меня категорически не устраивает твоё отношение к своим обязанностям.","К сожалению, из тебя не вышло толкового офицера, и наверное уже не выйдет...","Ты хороший офицер, и исправно нёс службу, но здесь наши пути расходятся. И не спрашивай меня почему."), LinkRandPhrase("Я предупреждал"+ GetSexPhrase("","а") +", что страсть к рому тебя погубит. Как я могу довериться в бою человеку, который саблей в ножны попасть не может?","Моряка из тебя, скажем прямо, не вышло... Думаю, на берегу ты добьешься большего.","Меня давно не устраивает твоя квалификация, но сейчас я наконец-то наш"+ GetSexPhrase("ел","ла") +" достойную замену."));
				Link.l1.go = "Get_out_A2";
				break;	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) >= 41) // злодей против героя 
			{		
				dialog.text = RandPhraseSimple(RandPhraseSimple("Хм. Могу я узнать причины?","Это серьёзное заявление. Могу я узнать, что конкретно вас не устраивает?"), RandPhraseSimple("Прошу объясниться, капитан.","Надеюсь, у такого заявления имеются веские основания?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Меня совершенно не устраивает твоя квалификация, поэтому","К сожалению, из тебя не вышло толкового офицера. Так что,","Мне чертовски надоели твои благородные порывы. Я не намерен"+ GetSexPhrase("","а") +" терпеть их бесконечно, так что,"), LinkRandPhrase("До меня дошли слухи, что именно ты подбиваешь команду к неповиновению. Беспорядков на моём судне не будет! И не нужно благодарить, что я раньше не вышвырнул"+ GetSexPhrase("","а") +" тебя за борт... Так что,","Твои благородные принципы делают тебе честь, но они идут вразрез с разбойной жизнью вольного капера. Так что,","Меня категорически не устраивает твоё отношение к своим обязанностям. Поэтому")) + " собирайся и покинь судно.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A3_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A3_strife";
				}	
				break;
	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) < 41) // злодей против злодея
			{	
				dialog.text = RandPhraseSimple(LinkRandPhrase("Капитан, я никак не ожидал такого поворота! Может объясните, что произошло?","Капитан, что за муха вас укусила?!","Как прикажете это понимать, капитан?!"), RandPhraseSimple("Как же так, капитан?! Ещё сутра всё было нормально, а тут - на тебе...","Ого! Думаю, вы найдёте пару слов для объяснения?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Ты редкостный бездарь и неумеха - тебе бы юнгой в каботажное плавание. Я и так слишком долго терпел"+ GetSexPhrase("","а") +". Так что,","Ты давно меня не устраиваешь, но сейчас я наконец-то наш"+ GetSexPhrase("ел","ла") +" достойную замену. Так что,","Мне стало известно, что ты тайком таскаешь ром и спаиваешь команду, тем самым ослабляя её боевой дух. Поэтому"), LinkRandPhrase("При найме ты распинался, что лучшего офицера не найти на всём флоте, а на поверку оказался обыкновенным лоботрясом, так что","Я предупреждал"+ GetSexPhrase("","а") +", что твоё пьянство плохо кончится. Почему я долж"+ GetSexPhrase("ен","на") +" всё за тебя делать сам"+ GetSexPhrase("","а") +"? Так что,","Вместо несения службы, ты постоянно торчишь в кают-компании за игрой в карты или кости. Надеюсь, ты не думал, что так может продолжаться бесконечно? Так что,")) + " собирайся и проваливай.";
				Link.l1.go = "Get_out_A4";
				break;
			}
		break;
	
		case "Get_out_A1_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Вот значит как! Ну ладно, воля ваша. Но учтите: к вам я больше не вернусь. Ещё просить будете...","Признаться, ваши игры в благородство мне тоже как-то не по душе. Так что - прощайте...", "Ну и чёрт с вами! Оставайтесь со своими лизоблюдами. Тоже мне - 'герой'!"), LinkRandPhrase("Да мне у вас никогда и не нравилось, не судно, а грузовая баржа. Развели благородный пансион...","Да меня самого с души воротит от таких сослуживцев. В кают-компанию хоть не заходи, как на подбор - одни маменькины сынки...","Хорошо, капитан, будь по-вашему. Но, видит Бог, у меня за кормой чисто..."));
			Link.l1 = "Стой. Сейчас я не могу оставить судно без офицера. Но позднее мы ещё вернемся к этому разговору.";
			Link.l1.go = "exit_bad";
			Link.l2 = "Вот и ступай с Богом.";
			Link.l2.go = "Exit_Fire_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Не кипятись. Я приготовил"+ GetSexPhrase("","а") +" тебе выходное пособие "+sti(NPChar.rank)*500+" песо. Надеюсь, это снимет все вопросы.";
				Link.l3.go = "Get_out_А1_ForMoney";
			}
		break;

		case "Get_out_A1_strife":
			dialog.text = LinkRandPhrase("Позвольте! Что значит 'покинь судно'?! Не для того я свою голову под картечь подставлял, чтоб вы могли меня вышвырнуть, когда вздумается!", "Ха! 'покинь судно'! Вы думаете, я позволю вышвырнуть себя, как котёнка?!", "Полегче, капитан, в серьёзной компании так дела не решаются. Я не позволю обращаться с собой, как с салагой.");
			Link.l1 = "Хорошо, оставайся. Но лишь пока я не найду достойную замену." ;
			Link.l1.go = "exit_bad";
			Link.l2 = "Я повторяю - твоя служба закончена. Можешь собирать вещи.";
			Link.l2.go = "Get_out_A1_strife_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Не кипятись. Я приготовил"+ GetSexPhrase("","а") +" тебе выходное пособие "+sti(NPChar.rank)*500+" песо. Надеюсь, это снимет все вопросы.";
				Link.l3.go = "Get_out_А1_ForMoney";
			}
		break;

		case "Get_out_A1_strife_1":
			dialog.text = RandPhraseSimple("Да я и не горю желанием у вас задерживаться. Только без компенсации покидать судно не собираюсь!", "Да я теперь и сам не останусь на вашем корыте. Только извольте сначала выплатить компенсацию!") + " "+sti(NPChar.rank)*1000+" песо, и мы забудем друг о друге.";
			Link.l1 = "Я погорячил"+ GetSexPhrase("ся","ась") +"... Прими мои извинения, и возвращайся на пост.";
			Link.l1.go = "exit_bad1";
			Link.l2 = "О каких деньгах может идти речь, если ты регулярно получал свою долю? Всё это изрядно смахивает на вымогательство!";
			Link.l2.go = "Get_out_А1_strife_battle";
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l3 = "Ладно. Сдай экипировку и получишь то, о чём просишь.";
				Link.l3.go = "Get_out_А1_chang";
			}
		break;

		case "Get_out_А1_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "Ну, это совсем другое дело. Прощайте!";
			Link.l1 = "Надеюсь, наши дороги больше не пересекутся.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_А1_strife_battle":
			dialog.text = LinkRandPhrase("Считайте это компенсацией моральных издержек. Я никому не позволю так с собой обращаться! А кто посмеет, тот очень пожалеет об этом!", "Это не вымогательство, а компенсация бездарно потраченного времени! И я её получу, чего бы мне это ни стоило!", "Я потратил слишком много времени на службу у так"+ GetSexPhrase("ого чистоплюя","ую чистоплюйку") +" как вы. За это время можно было озолотиться грабежом торговцев. Теперь хочу компенсировать упущенную выгоду.");
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l1 = "Ладно. Вот твои деньги... А теперь убирайся отсюда!";
				Link.l1.go = "Get_out_А1_ForMoney_angry";
			}
			Link.l2 = "Ты забываешься! Я не позволю всяким недоумкам повышать на себя голос!";
			Link.l2.go = "Get_out_А1_strife_death";
		break;

		case "Get_out_А1_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("good");
			dialog.text = "Давай-давай, капитан! Покажи, каков"+ GetSexPhrase("","а") +" ты против серьёзного соперника!";
			Link.l1 = "Видит Бог, я этого не хотел"+ GetSexPhrase("","а") +"!";
			Link.l1.go = "Get_out_fight";
		break;
	
		case "Get_out_А1_ForMoney_angry":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			OfficersReaction("bad");
			dialog.text = "Ну, это совсем другое дело. Прощайте!";
			Link.l1 = "Надеюсь, наши дороги больше не пересекутся.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_A2":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Ну что ж, значит не судьба. Прощайте, капитан, не поминайте лихом...","Очень жаль, капитан. Но, видит Бог, я старался. Прощайте.","Ну, капитан, вам не угодишь!.. Счастливо оставаться."), LinkRandPhrase("Жаль, капитан. Мне очень нравилось служить у вас.","Вот ведь как бывает... Но я зла не держу, прощайте.","Вы несправедливы ко мне, капитан. Но я уважаю ваше решение. Прощайте."));
			Link.l1 = "Стой, я передумал"+ GetSexPhrase("","а") +". Давай вернём к этому разговору позже.";
			Link.l1.go = "exit_good";
			Link.l2 = "Не огорчайся. Удачи тебе...";
			Link.l2.go = "exit_fire_2";
			Link.l3 = "Постой... Я тебя неплохо экипировал"+ GetSexPhrase("","а") +". Нужно бы вернуть вещички - мне вон какую ораву снаряжать нужно...";
			Link.l3.go = "Return_items_A2";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l4 = "Постой... Не хочу отпускать тебя с пустыми руками. Вот держи "+sti(NPChar.rank)*500+" песо, пригодятся, пока будешь искать новую работу.";
			}
			Link.l4.go = "Im_kind_A2";
		break;

		case "Return_items_A2":
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "Да о чём речь, конечно забирайте...";
			Link.l1 = "Я знал"+ GetSexPhrase("","а") +", что ты меня правильно поймёшь...";
			Link.l1.go = "Get_out_А2_chang";
		break;

		case "Im_kind_A2":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeOfficersLoyality("good_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "Спасибо вам, капитан! Какая неожиданная щедрость. У меня тут осталось кое-что из ваших вещей, может желаете их вернуть?";
			Link.l1 = "Да пожалуй... Сейчас найти хороший клинок ой как непросто...";
			Link.l1.go = "Get_out_А2_chang";
			Link.l2 = "Не нужно. Оставь себе в память о службе под моим началом...";
			Link.l2.go = "exit_fire_2";
		break;

		case "Get_out_A3_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Ну что ж, воля ваша. Но учтите: к вам я больше не вернусь, даже если придётся помирать с голоду.","Признаться, ваши бандитские замашки мне тоже не по душе. Так что, это рано или поздно должно было случиться... И не нужно выдумывать никаких причин.","Ну и оставайтесь со своими головорезами. На вашем судне приличному человеку в кают-компанию зайти стыдно. Развели бордель, прости меня Господи!"), LinkRandPhrase("Признаться, у меня тоже душа не лежит к такой службе. Набрали в команду одних проходимцев - не с кем добрым словом обмолвиться.","Да, если вы будете так относиться к личному составу - от вас все сами разбегутся. Никаких причин выдумывать не придётся.","Меня утешает то, что наша неприязнь взаимна. Счастливо оставаться."));
			Link.l1 = "Стой. Сейчас не самый удачный момент тебя списывать. Но все претензии остаются в силе.";
			Link.l1.go = "exit_bad";
			Link.l2 = "Иди-иди. Обойдусь без твоих нравоучений.";
			Link.l2.go = "exit_fire_3";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Подожди. Дам тебе на дорогу "+sti(NPChar.rank)*500+" песо. А то помрёшь под забором, а мне потом перед Богом отвечать.";
				Link.l3.go = "Get_out_А3_ForMoney";
			}
		break;

		case "Get_out_А3_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("И на том спасибо. Прощайте...", "Благодарю за понимание. Счастливо оставаться.", "Вот теперь мы в расчёте. Всего хорошего...");
			Link.l1 = "Я знал"+ GetSexPhrase("","а") +", что ты меня правильно поймёшь...";
			Link.l1.go = "exit_fire_3";
		break;
	
		case "Get_out_A3_strife":
			dialog.text = LinkRandPhrase("Но, капитан, при таком раскладе я остаюсь совсем на мели. Вы же не хотите отправить меня с корабля прямо на паперть?", "Вы несправедливы ко мне, капитан. Но я готов забыть обиду, если получу достойную компенсацию.", "И это ваша благодарность за все мои боевые ранения? Думаю, без денежной компенсации тут не обойтись.");
			Link.l1 = "Ладно, я передумал"+ GetSexPhrase("","а") +". Пока оставайся, но мы ещё вернёмся к этому разговору.";
			Link.l1.go = "exit_bad";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l2 = "Ну, об этом можешь не переживать. Держи "+sti(NPChar.rank)*500+" песо. Думаю, на первое время хватит.";
				Link.l2.go = "Get_out_А3_ForMoney";
				Link.l3 = "Я дам тебе денег. Но, благодаря мне, ты неплохо экипирован - вещички нужно бы вернуть.";
				Link.l3.go = "Return_items_A3";
			}
			Link.l4 = "Ого! А как же регулярно получаемая тобой доля?! Я так и знал"+ GetSexPhrase("","а") +", что всё закончится нытьём и выпрашиванием подачки.";
			Link.l4.go = "Get_out_A3_strife_1";
		break;

		case "Return_items_A3":
			dialog.text = "Я знал, что вы это скажете, но экипировку сможете забрать только, когда я получу "+sti(NPChar.rank)*1000+" песо. Или вам придётся снимать её с трупа.";
			Link.l1 = "Хорошо, держи свои деньги.";
			Link.l1.go = "Get_out_А3_chang";
			Link.l2 = "Да в своём ли ты уме?! Требовать такую сумму за то, что я дал тебе бесплатно! Похоже, такое низкое качество, как жадность, всё-таки одержало верх над твоей напускной благодетелью.";
			Link.l2.go = "Get_out_A3_strife_1";
		break;

		case "Get_out_A3_strife_1":
			dialog.text = "Вы не смеете меня оскорблять! Я, может и не самый лучший на флоте, но всё же боевой офицер. И заставлю уважать себя, даже так"+ GetSexPhrase("ого","ую") +" невежу как вы!";
			Link.l1 = "Если тебе ещё не ясно, то повторю - можешь не клянчить, всё равно ничего не получишь.";
			Link.l1.go = "Get_out_А3_strife_death";
		break;

		case "Get_out_А3_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("bad");
			dialog.text = "Ну, уж удовлетворение-то я получу в любом случае!!";
			Link.l1 = "Да это вызов! Ну, что ж, как пожелаешь...";
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_A4":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Вот так всегда! Всю душу на службе отдаёшь, а тебе - бац, и без выходного пособия!","Да что ж это за напасть такая?! Не успеешь наняться, как тебя тут же коленкой под зад. Уж и не знаю, кому свечку ставить...","Вот те на! Уже третье увольнение за год - и всё по понедельникам. Этим капитанам хоть на глаза с похмелья не показывайся!"), LinkRandPhrase("Ну ладно, пусть так. Только не приведи Господь нам больше встретиться.","Ну что ж, воля ваша. Но учтите: лучшего офицера вам всё равно не найти.","Хорошо, капитан, будь по-вашему. Но, видит Бог - у меня за кормой чисто..."));
			Link.l1 = "Стой. Сейчас не самый удачный момент тебя списывать. Но все претензии остаются в силе.";
			Link.l1.go = "exit_good";
			Link.l2 = RandPhraseSimple("Топай-топай. И благодари Бога, что я сегодня в хорошем настроении.", "Давай-давай. Всё равно из тебя офицер, как из дерьма пуля.");
			Link.l2.go = "exit_fire_4";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Подожди. Дам тебе на дорогу "+sti(NPChar.rank)*500+" песо. А то помрёшь под забором, а мне потом перед Богом отвечать.";
				Link.l3.go = "Get_out_А4_ForMoney";
			}
			Link.l4 = "Постой... Я тебя неплохо экипировал"+ GetSexPhrase("","а") +" - вещички нужно бы вернуть.";
			Link.l4.go = "Return_items_A4";
		break;

		case "Get_out_А4_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("Вот спасибо, капитан! Вот так уважили...", "Благодарю за понимание. Счастливо оставаться.", "Вот теперь мы в расчёте. Всего хорошего...");
			Link.l1 = "Счастливо. Только не оставь их все в ближайшей таверне.";
			Link.l1.go = "exit_fire_4";
		break;

		case "Return_items_A4":
			if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
			{
				dialog.text = LinkRandPhrase("Вот теперь ещё и экипировку забираете! Да пропади оно всё пропадом! Ей-богу в рыбаки подамся...", "Вижу, вы меня дочиста раздеть решили. Что ж, забирайте. Одна теперь дорога - на паперть...", "Благодарю покорно! Теперь ещё и обчистить решили. Эх, судьбина!.. Забирайте, будь оно всё неладно...");
				Link.l1 = "Давай-давай. Всё равно из тебя офицер, как из дерьма пуля.";
				Link.l1.go = "Get_out_А4_chang_1";
			}
			else	
			{
				dialog.text = RandPhraseSimple("Будь по-вашему, капитан, только сначала выдайте мне "+sti(NPChar.rank)*1000+" песо. Будем считать это компенсацией моральных издержек.", "Хорошо. Только за это я хочу получить "+sti(NPChar.rank)*1000+" песо в качестве компенсации за нелёгкую службу.");
				if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
				{
					Link.l1 = "Вот пройдоха! Ладно, держи свои деньги.";
					Link.l1.go = "Get_out_А4_chang";
				}
				Link.l2 = "Да ты никак рехнулся?! Смеешь просить столько денег за то, что я сам"+ GetSexPhrase("","а") +" же тебе дал"+ GetSexPhrase("","а") +"!";
				Link.l2.go = "Get_out_A4_strife";
				Link.l3 = "Ах-ха! Да я пошутил"+ GetSexPhrase("","а") +"! Разве я могу вышвырнуть старого друга, как дырявый картуз!";
				Link.l3.go = "exit_bad1";
			}
		break;

		case "Get_out_A4_strife":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "Ну, тогда ничего и не получите! Я с места не двинусь, пока не услышу, как звенят мои деньги!";
			Link.l1 = RandPhraseSimple("Сейчас ты услышишь, как звенит мой клинок!", "Значит, тебя унесут вперёд ногами!");
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_fight":
			CheckForReleaseOfficer(GetCharacterIndex(Npchar.id));
			RemovePassenger(Pchar, Npchar);
			LAi_CharacterDisableDialog(NPChar);
			LAi_SetWarriorType(Npchar);
			LAi_group_MoveCharacter(Npchar, "TmpEnemy");
			LAi_group_SetHearRadius("TmpEnemy", 100.0);
			LAi_group_FightGroupsEx("TmpEnemy", LAI_GROUP_PLAYER, true, Pchar, -1, false, false);
			if (PChar.location == Get_My_Cabin() || findsubstr(PChar.location, "_tavern" , 0) != -1 || findsubstr(PChar.location, "_store" , 0) != -1)
            {
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
				LAi_group_SetCheck("TmpEnemy", "CannotFightCurLocation");
				LAi_group_SetCheck("TmpEnemy", "MainHeroFightModeOff");
            }
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

	    case "Get_out_А1_chang": // интерфейс обмена
			NextDiag.CurrentNode =  "Exit_228";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А2_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_2";
			LAi_CharacterDisableDialog(NPChar);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А3_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_3";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А4_chang_1": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А4_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

	    case "exit_bad":
			Npchar.loyality = makeint(Npchar.loyality) - 3;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_bad1":
			Npchar.loyality = makeint(Npchar.loyality) - 2;
			ChangeOfficersLoyality("bad_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			NextDiag.CurrentNode = "exit_2";
		
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_good":
			Npchar.loyality = makeint(Npchar.loyality) - 1;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_fire_1":	//navy -->			
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_1";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = "exit_228";
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_2":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_2";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_3":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_3";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_4":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_4";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_5":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_1";
			OfficersReaction("good");
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "Fired_1":
			NextDiag.CurrentNode = "Fired_1";      
			dialog.text = "Ну чего ещё? Мы, кажется, уже всё решили! Ноги моей больше на вашем судне не будет.";
			Link.l1 = RandPhraseSimple("Ступай-ступай. Невелика потеря.", "Иди-иди. Удерживать не стану.");	
			Link.l1.go = "Exit_228";
		break;

		case "Fired_2":
			NextDiag.CurrentNode = "Fired_2"; 
			dialog.text = "Что-то ещё, капитан? Мне казалось, что мы уже всё решили...";
			Link.l1 = "Нет, ничего. Просто попрощаться хотел"+ GetSexPhrase("","а") +"...";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_3":
			NextDiag.CurrentNode = "Fired_3"; 
			dialog.text = "Капитан, все вопросы решены, претензии высказаны. Не хотите же вы после всего этого сказать, что передумали.";
			Link.l1 = "Иди-иди. Невелика потеря.";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_4":
			NextDiag.CurrentNode = "Fired_4"; 
			dialog.text = "Капитан, ну какие ещё могут быть вопросы? Я, сказать по совести, очень на вас обижен, и никакого желания возвращаться не имею...";
			Link.l1 = "Иди-иди. Нужен ты мне больно, только палубу пачкал.";	 
			Link.l1.go = "Exit_228";
		break;
		
		// boal 05.09.03 offecer need to go to abordage -->
	    case "Boal_Stay":           //SetCharacterTask_Stay(Characters[Npchar.index]); // it's a mistic but here doesn't work :(
            //Log_SetStringToLog(Npchar.id +" "+Npchar.index);
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "Есть изменить дислокация!";
		    Link.l1 = "Вольно.";
		    Link.l1.go = "exit_company";
		    Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
	    break;
		
	    case "Boal_Follow":
		    SetCharacterTask_FollowCharacter(Npchar, PChar); // it works here!!!
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "Есть изменить дислокация!";
		    Link.l1 = "Вольно.";
		    Link.l1.go = "exit_company";
	    break;
        // boal 05.09.03 offecer need to go to abordage <--

//////////////////////////////    офицер-наместник -->
		case "Gover_Hire":
            dialog.Text = "Почту за честь!";
            Link.l1 = "Следи за порядком и процветанием города, я буду иногда приплывать за собранной пошлиной.";
			Link.l1.go = "Exit_Gover_Hire";
            Link.l2 = "Я передумал"+ GetSexPhrase("","а") +".";
            Link.l2.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
        break;

        case "Exit_Gover_Hire":
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            attr = sld.id + "_townhall";

            // снимем пассажира -->
			CheckForReleaseOfficer(sti(NPChar.index));
			RemovePassenger(pchar, NPChar);
			// снимем пассажира <--
		    sld.OfficerIdx = sti(NPChar.index);
			ChangeCharacterAddressGroup(NPChar, attr, "sit", "sit1");
			LAi_SetHuberTypeNoGroup(NPChar);
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
            LAi_LoginInCaptureTown(NPChar, true);
			//  СЖ -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_1");
			AddQuestUserData("Gen_CityCapture", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  СЖ <--
			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Main":
            iTemp = GetNpcQuestPastDayParam(NPChar, "GoverTalkDate");
            if (iTemp > 0)
            {
				dialog.Text = "Какие быть приказания? Последний ваш визит был " + FindRussianDaysString(iTemp) + " назад.";
			}
			else
			{
			    dialog.Text = "Какие быть приказания?";
			}

            Link.l1 = "Какую сумму налогов ты " + NPCharSexPhrase(NPChar, "собрал", "собрала") + " на данный момент?";
        	Link.l1.go = "Gover_Tax";
            Link.l8 = "Ты " + NPCharSexPhrase(NPChar, "нужен", "нужна") + " мне на корабле, я снимаю тебя с городской службы.";
            Link.l8.go = "Gover_Fire";
			Link.l9 = "Всего хорошего.";
            Link.l9.go = "exit_huber";
            NextDiag.CurrentNode = "Gover_Main";
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
        break;

        case "Gover_Tax":
            iTemp = GetNpcQuestPastDayParam(NPChar, "StartTaxDate");
            iTax  = makeint((GetCharacterSkillSimple(NPChar, SKILL_COMMERCE) + GetCharacterSkillSimple(NPChar, SKILL_LEADERSHIP)) / 2);
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
			if (CheckAttribute(sld, "FortValue"))
			{
			    iFortValue = sti(sld.FortValue);
			}
			else
			{
			    iFortValue = 20;
			}
			NPChar.Gover_Tax_Sum = iFortValue*iTax*iTemp;
			dialog.Text = "Мои навыки позволяют мне собирать " + FindRussianMoneyString(iFortValue*iTax) + " в день. За " + FindRussianDaysString(iTemp) + " я " + NPCharSexPhrase(NPChar, "собрал", "собрала") + " " + FindRussianMoneyString(sti(NPChar.Gover_Tax_Sum)) + ".";
			if (sti(NPChar.Gover_Tax_Sum) > 0)
			{
			    Link.l1 = "Я хочу забрать всю сумму налогов.";
            	Link.l1.go = "Gover_Tax_Get";
			}
			Link.l2 = "Благодарю за службу!";
            Link.l2.go = "exit_huber";
        break;

        case "Gover_Tax_Get":
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            AddMoneyToCharacter(Pchar, sti(NPChar.Gover_Tax_Sum));

			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Fire":
            dialog.Text = "Замечательно! Быть сухопутной крысой не мой удел.";
            Link.l8 = "Вот и славно.";
            Link.l8.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
		sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            DeleteAttribute(sld, "OfficerIdx");
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
		AddDialogExitQuestFunction("PGG_BecomeHiredOfficer");
		
		DeleteAttribute(NPChar, "Quest.Officer");
		DeleteAttribute(NPChar, "PGGAi.Task");
		DeleteAttribute(NPChar, "PGGAi.LockService");	
		DeleteAttribute(NPChar, "OfficerIdx");
            //  СЖ -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_2");
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  СЖ <--
        break;
        //////////////////////////////    офицер-наместник <--


//  игры  -->
case "Play_Game":
			dialog.text = "Давай! Отдых никогда не вредил здоровью... только кошельку... В какие игры играть будем?";
			link.l1 = "Перекинемся в карты на солидный интерес?";
			link.l1.go = "Cards_begin";
   			link.l2 = "Погремим костями в покер-джокер?";
			link.l2.go = "Dice_begin";
			link.l10 = "Прошу простить меня, но меня ждут дела.";
			link.l10.go = "exit";
		break;

	//  карты -->
        case "Card_Game":
            if (!CheckNPCQuestDate(npchar, "Card_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Card_date_Yet");
                dialog.text = "Я не буду играть с тобой!";
    			link.l1 = "Как будет угодно.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Card_date_begin"))
				{
					dialog.text = "Давай! Отдых никогда не вредил здоровью... только кошельку...";
	    			link.l1 = "Замечательно.";
	    			link.l1.go = "Cards_begin";
	    			link.l2 = "По каким правилам игра?";
	    			link.l2.go = "Cards_Rule";
    			}
    			else
    			{
					dialog.text = "Духи говорить, что мне надо остановиться.";
	    			link.l1 = "Как будет угодно.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Cards_Rule":
   			dialog.text = CARDS_RULE;
			link.l1 = "Что ж, давайте начнем!";
			link.l1.go = "Cards_begin";
			link.l3 = "Нет, это не для меня...";
			link.l3.go = "exit";
		break;

		case "Cards_begin":
			dialog.text = "Отлично! Давай теперь определимся со ставкой.";
			link.l1 = "Играем по 1000 песо.";
			link.l1.go = "Cards_Node_100";
			link.l2 = "Давайте по 5000 песо.";
			link.l2.go = "Cards_Node_500";
	    		link.l3 = "Погоди! По каким правилам игра?";
	    		link.l3.go = "Cards_Rule";
			link.l4 = "Пожалуй, мне пора.";
			link.l4.go = "exit";
		break;

		case "Cards_Node_100":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "Я не буду играть с тобой. Духи говорят, что ты нечестен в играх.";
                link.l1 = "Все врут твои духи!";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "Шутить, " + GetAddress_Form(NPChar) + "? У тебя нет денег!";
                link.l1 = "Бывает.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "Все! Духи говорить, что мне надо остановиться...";
                link.l1 = "Жаль.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 1000 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 1000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_Node_500":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "Я не буду играть с тобой. Духи говорят, что ты нечестен в играх.";
                link.l1 = "Все врут твои духи!";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckCardsGameBigRate())
		    {
                dialog.text = "Я слышал, что ты очень хорошо играешь. Я не буду играть с тобой по такой большой ставка.";
                link.l1 = "Давай по более низким ставкам?";
			    link.l1.go = "Cards_Node_100";
				link.l2 = "Извини, мне пора.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "Шутить, " + GetAddress_Form(npchar) + "? У тебя нет 15000 песо!";
                link.l1 = "Будут!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "Духи говорить, что мне надо остановиться...";
                link.l1 = "Как угодно.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 5000 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 5000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_begin_go":
            SetNPCQuestDate(npchar, "Card_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchCardsGame();
		break;
	    // карты <--

	    //  кости -->
        case "Dice_Game":
            if (!CheckNPCQuestDate(npchar, "Dice_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Dice_date_Yet");
                dialog.text = "Я не буду играть с тобой!";
    			link.l1 = "Как угодно.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Dice_date_begin"))
				{
					dialog.text = "Давай! Отдых никогда не вредил здоровью... только кошельку...";
	    			link.l1 = "Замечательно.";
	    			link.l1.go = "Dice_begin";
	    			link.l2 = "По каким правилам игра?";
	    			link.l2.go = "Dice_Rule";
    			}
    			else
    			{
					dialog.text = "Духи говорить, что мне надо остановиться.";
	    			link.l1 = "Как будет угодно.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Dice_Rule":
   			dialog.text = DICE_RULE;
			link.l1 = "Что ж, давай начнем!";
			link.l1.go = "Dice_begin";
			link.l3 = "Нет, это не для меня...";
			link.l3.go = "exit";
		break;

		case "Dice_begin":
			dialog.text = "Замечательно! Давайте определимся со ставкой.";
			link.l1 = "Играем по 500 песо за кубик.";
			link.l1.go = "Dice_Node_100";
			link.l2 = "Давай по 2000 песо за кубик.";
			link.l2.go = "Dice_Node_500";
			link.l3 = "Погоди! По каким правилам игра?";
	    		link.l3.go = "Dice_Rule";
			link.l4 = "Пожалуй, мне пора.";
			link.l4.go = "exit";
		break;

		case "Dice_Node_100":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "Я не буду играть с тобой. Духи говорят, что ты нечестен в играх.";
                link.l1 = "Все врут твои духи!";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "Шутить, " + GetAddress_Form(NPChar) + "? У тебя нет денег!";
                link.l1 = "Бывает.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "Все! Духи говорить, что мне надо остановиться...";
                link.l1 = "Жаль.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 500 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 500;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_Node_500":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "О Вас ходит слава непревзойдённого шулера. Я не буду с Вами играть.";
                link.l1 = "Все врут! Ну и не нужно.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckDiceGameBigRate())
		    {
                dialog.text = "Я слышал, что ты очень хорошо играешь. Я не буду играть с тобой по такой большой ставка.";
                link.l1 = "Давай по более низким ставкам?";
			    link.l1.go = "Dice_Node_100";
				link.l2 = "Извините, мне пора.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "Шутить, " + GetAddress_Form(NPChar) + "? У тебя нет 15000 песо!";
                link.l1 = "Будут!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "Прости, но нет. Такие ставки не доведут до добра меня.";
                link.l1 = "Как угодно.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 2000 монет за кубик.";
			link.l1 = "Начали!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 2000;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_begin_go":
            SetNPCQuestDate(npchar, "Dice_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchDiceGame();
		break;
	    // кости <--

	// игры <--

//  Торговля -->
case "Trade_1":
		//корабль где?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("Где твой каноэ? Как я могу идти вместе с тобой?", "Сначала найди большой каноэ, брат, а потом только что-то предлагай	...");
link.l1 = RandPhraseSimple("Не беспокойся, друг, скоро у меня будет каноэ!", "Ой, это временное недоразумение... Не волнуйся.");
			link.l1.go = "exit";
			break;
			}
			dialog.text = "Почему бы и нет, брат.";
			link.l1 = "Пойдём смотреть товары.";
			link.l1.go = "Trade_2";
			link.l2 = "Прошу прощения, но я передумал"+ GetSexPhrase("","а") +".";
			link.l2.go = "exit";
		break;
		
		case "Trade_2":
			FillShipStore(NPChar);
	    	pchar.shiptrade.character = NPChar.id;
   			NextDiag.TempNode = "First time";
		    DialogExit();
		    DeleteAttribute(pchar, "PriceList.StoreManIdx"); // не вести лог по кораблям
		    LaunchStore(SHIP_STORE);
		break;

// Торговля <--

	}
}