#define DIPLOMAT_SUM 80000

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	int iSumm = 0;
	string s1;
	
	if (!CheckAttribute(npchar, "PatentPrice"))
    {
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.PatentPrice = (6000 + rand(4) * 500);
        else npchar.PatentPrice = (8000 + rand(6) * 1000);
    }
    int i;
    string attrLoc;
	ref    sld;
	
    attrLoc   = Dialog.CurrentNode;
    
    if (findsubstr(attrLoc, "SetNationPatent_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.nation = strcut(attrLoc, i+1, strlen(attrLoc)-1); // индех в конце
 	    Dialog.CurrentNode = "patent_2";
 	}
 	
 	if (findsubstr(attrLoc, "SetNationLicence_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.LicenceNation = strcut(attrLoc, i+1, strlen(attrLoc)-1); // индех в конце
 	    Dialog.CurrentNode = "NationLicenceType";
 	}

 	if (findsubstr(attrLoc, "NationLicenceType_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.LicenceType = strcut(attrLoc, i+1, strlen(attrLoc)-1); // индех в конце
 	    Dialog.CurrentNode = "NationLicenceType2";
 	}
 	
 	if (findsubstr(attrLoc, "RelationTo_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
        npchar.quest.relation      = strcut(attrLoc, i+1, strlen(attrLoc)-1); // индех в конце
		// проверка на уже договор
		attrLoc = "RelationAgent" + GetNationNameByType(sti(npchar.quest.relation));
		if (CheckAttribute(Pchar, "GenQuest." + attrLoc) && sti(Pchar.GenQuest.(attrLoc)) == true)
		{
		    Dialog.CurrentNode = "RelationYet";
		}
		else
		{
 	    	Dialog.CurrentNode = "RelationAny_Done";
 	    	npchar.quest.relation.summ = CalculateRelationSum(sti(npchar.quest.relation));
 	    }
 	}
 	
 	if (findsubstr(attrLoc, "CityPay_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.quest.CityIdx = strcut(attrLoc, i+1, strlen(attrLoc)-1); // индех в конце
 	    Dialog.CurrentNode = "CityInfo";
 	}
 	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "Рад видеть вас снова.";
			link.l1 = "Мне опять нужны ваши услуги.";
			link.l1.go = "relation";
			link.l2 = "Я уже ухожу.";
			link.l2.go = "exit";

			// генератор  "Найденные документы"
			if ((pchar.questTemp.different == "GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakAgent"))			
			{
				link.l4 = "Хочу предложить сделку."
				link.l4.go = "D_ShipLetters_1"; 
				pchar.questTemp.different.GiveShipLetters.speakAgent = true;
			}			

			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Позвольте представиться, я являюсь тем человеком, который может замолвить за вас словечко тому или иному губернатору. За плату, естественно, но поверьте, мои услуги самого высшего качества, и вы не пожалеете, если воспользуетесь моими талантами.";
				link.l1 = "Очень интересно, продолжай.";
				link.l1.go = "relation";
				link.l2 = "Может быть, в другой раз.";
				link.l2.go = "exit";
				npchar.quest.meeting = "1";
			}
			
			NextDiag.TempNode = "First time";
		break;

		//*************************** Генератор - "Найденные судовые документы" **************		
		case "D_ShipLetters_1":
			dialog.text = "Излагайте условия.";
			s1 = "У меня, по счастливой случайности, оказался абсолютно легальный пакет судовых документов, еще не заявленных в розыск.";
			s1 = s1 + "Судно на плаву и не исключено из реестра, не беспокойтесь. Просто разиня-владелец умудрился потерять эти бумаги...";
			link.l1 = s1;
			link.l1.go = "D_ShipLetters_2";
		break;
		case "D_ShipLetters_2":
			s1 = "Дайте-ка взглянуть! Действительно, отметки совсем свежие. Что же, удача Вам благоволит, "+ GetSexPhrase("сударь","сударыня") +"! ";
			s1 = s1 + "Мне как раз понадобился именно такой комплект, и я, в свою очередь предлагаю Вам " + sti(pchar.questTemp.different.GiveShipLetters.price5) + " песо. Что скажете?";
			dialog.text = s1;
			link.l1 = "Воистину королевская щедрость! Конечно же я "+ GetSexPhrase("согласен","согласна") +"!";
			link.l1.go = "D_ShipLetters_3";
			link.l2 = "Пожалуй, нет.";
			link.l2.go = "exit";
		break;
		case "D_ShipLetters_3":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price5)); 
			OfficersReaction("bad"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //снимаем таймер 
			AddQuestRecord("GiveShipLetters", "9");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
		
		case "relation":
			dialog.text = "Давайте посмотрим, чем я могу вам помочь.";
            if (ChangeCharacterNationReputation(pchar, ENGLAND, 0) < 0)
			{
				link.l3 = "Я хочу помириться с Англией.";
				link.l3.go = "RelationTo_0";
			}
			
			if (ChangeCharacterNationReputation(pchar, FRANCE, 0) < 0)
			{
				link.l1 = "Я хочу помириться с Францией.";
				link.l1.go = "RelationTo_1";
			}
			if (ChangeCharacterNationReputation(pchar, SPAIN, 0) < 0)
			{
				link.l2 = "Я хочу помириться с Испанией.";
				link.l2.go = "RelationTo_2";
			}

			if (ChangeCharacterNationReputation(pchar, HOLLAND, 0) < 0)
			{
				link.l4 = "Я хочу помириться с Голландией.";
				link.l4.go = "RelationTo_3";
			}
			if (ChangeContrabandRelation(pchar, 0) <= 5)
            {
                Link.l5 = "Я хочу помириться с контрабандистами.";
				Link.l5.go = "Contraband";
            }
            Link.l8 = "Мне нужен каперский патент.";
			Link.l8.go = "patent_0";
			
			Link.l9 = "Есть торговая лицензия Голландской Вест-Индской Компании?";
			Link.l9.go = "Licence";
			
			if (isHeroOwnCity(true))
			{
				Link.l10 = "У меня вопрос, связанный с принадлежностью поселений.";
				Link.l10.go = "City_Buy";
			}
			
			link.l99 = "Знаете, я думаю, что обойдусь своими силами.";
			link.l99.go = "exit";
		break;
		
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "Есть, конечно. Но я считаю должным вас предупредить, что Компания дорожит своим именем, поэтому к лицензиатам предъявлются определенные требования на весь срок действия лицензии, а именно - никаких агрессивных действий в отношении торговых кораблей любой нации\nВ случае выявления такого факта ваша лицензия будет немедленно аннулирована. Также вы лишитесь документа, если по каким-то причинам, неважно каким, вступите в конфликт с Голландией. Это понятно?";
				link.l1 = "Безусловно. Я приму это к сведению.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "На какой срок вы хотите получить лицензию?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;
		
		case "licence_0":
			dialog.text = "Лицензия дает право беспрепятственного входа в любой порт любой нации, поскольку подтверждает ваши мирные намерения и объясняет цель вашего прибытия - торговать. Однако если у вас есть проблемы с законом у той страны, в порт которой вы намерены явиться, лицензия вам не поможет. Более того - у вас ее просто изымут. Учтите это\nЕсли вы собираетесь торговать с враждебной вам державой - не забудьте перед входом в порт поднять дружественный флаг - это избавит вас от ненужных проблем, поскольку канониры фортов и патрули в городах имеют склонность сначала стрелять, и только потом разбираться\nДа, чуть не забыл: оплата производится исключительно золотыми дублонами... Ну, теперь, наверное, все прояснили. На какой срок вы хотите получить лицензию?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l9 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l9.go = "exit";
		break;
		
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			//npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*1000;
			// вариант с дублонами
			if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*3;
        else npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "Месье, пожалуйста, говорите четче, не заикайтесь и не мямлите. Я вас плохо расслышал. Так на сколько дней вам нужна лицензия?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "Минимальный срок, на который мы выдаем лицензию - двадцать дней. На сколько суток вам выписать - на двадцать, или больше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "Максимальный срок, на который мы выдаем лицензию - полгода. На сколько суток вам выписать - на сто восемьдесят, или меньше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "На "+FindRussianDaysString(sti(fQty))+"? Хорошо. Стоимость такой лицензии составит "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
			//if (sti(pchar.money) >= sti(npchar.quest.lcc_summ))
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "Да, конечно, устраивает.";
				link.l1.go = "licence_2";
			}
			link.l2 = "К сожалению, у меня нет сейчас с собой столько денег. Я зайду к вам за лицензией позже.";
			link.l2.go = "exit";
		break;
		
		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l9 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l9.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			//AddMoneyToCharacter(pchar, -sti(npchar.quest.lcc_summ));
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "Так, одну минуту... Сейчас поставим подпись и печать... Вот, готово. Получите ваш документ.";
			link.l9 = "Спасибо! До свидания, месье.";
			link.l9.go = "exit";
		break;
		
		case "NationLicenceType2":
			if (IsCharacterPerkOn(pchar, "Trustworthy")) iSumm = sti(npchar.LicenceType) * MOD_SKILL_ENEMY_RATE * 500 + 200000 + (sti(PChar.rank)*1000) - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 1000;
			else iSumm = sti(npchar.LicenceType) * MOD_SKILL_ENEMY_RATE * 1000 + 300000 + (sti(PChar.rank)*2000) - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 1000;
        	dialog.text = "Итак, торговая лицензия " + XI_ConvertString(Nations[sti(npchar.LicenceNation)].Name + "Gen") + " сроком на " + sti(npchar.LicenceType) + " дней, цена " + FindRussianMoneyString(iSumm) + ".";
		    link.l1 = "Меня устраивает.";
		    if(makeint(Pchar.money) < iSumm)
            {
				Link.l1.go = "No_money";
			}
            else
			{
				link.l1.go = "NationLicenceType3";
			}
			link.l9 = "Я передумал"+ GetSexPhrase("","а") +".";
			link.l9.go = "exit";
		break;
		
		case "NationLicenceType3":
            //iSumm = sti(npchar.LicenceType) * (2000 * MOD_SKILL_ENEMY_RATE) - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 2000 + sti(PChar.rank)*10000;
			if (IsCharacterPerkOn(pchar, "Trustworthy"))  iSumm = sti(npchar.LicenceType) * MOD_SKILL_ENEMY_RATE * 500 + 200000 + (sti(PChar.rank)*1000) - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 1000;
			else iSumm = sti(npchar.LicenceType) * MOD_SKILL_ENEMY_RATE * 1000 + 300000 + (sti(PChar.rank)*2000) - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 1000;
			dialog.text = "Вот ваш документ. Входить в порт нужно под дружественным флагом. Помните, патруль может проверить, не просрочена ли лицензия.";
			link.l9 = "Спасибо.";
			link.l9.go = "exit";
			AddMoneyToCharacter(pchar, -iSumm);
			GiveNationLicence(sti(npchar.LicenceNation), sti(npchar.LicenceType));
		break;
		
        case "No_money":
			dialog.text = "Отлично! Обратитесь ко мне, когда будет нужная сумма.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
		break;
		
        case "patent_0":
			dialog.text = "Замечательно! Для этого вы должны доказать свою преданность державе" + 
                          " безупречной службой. Отправляйтесь к любому губернатору" + //NationNameGenitive(sti(NPChar.nation)) +
                          " и выполните ряд его заданий. После этого он выдаст вам патент.";
			link.l1 = "Скажите, "+GetAddress_FormToNPC(NPChar) + ", а можно как-нибудь обойти эту формальность? ";
			link.l1.go = "patent_1";
			link.l2 = "Прощайте, "+GetAddress_FormToNPC(NPChar);
			link.l2.go = "exit";
		break;
		
		case "patent_1":
			dialog.text = "Вы имеете в виду подкуп должностного лица!? Хотите, чтобы я выдал вам патент сам?";
			link.l1 = "Именно!";
            if (GetCharacterSkillToOld(PChar, SKILL_FORTUNE) > rand(11) || bBettaTestMode)
            {
			    link.l1.go = "patent_2_give";
			}
			else
			{
                link.l1.go = "patent_2_none";
			}
			link.l2 = "Нет. Всего хорошего, "+GetAddress_FormToNPC(NPChar);
			link.l2.go = "exit";
		break;
		
		case "patent_2_none":
			dialog.text = "В данный момент я не располагаю такими связями, чтобы раздобыть чистый бланк патента со всеми печатями и подписями.";
            link.l1 = "Жаль. Прощайте, "+GetAddress_FormToNPC(NPChar);
			link.l1.go = "exit";
		break;
		
		case "patent_2_give":
			dialog.text = "Хорошо, я смогу это устроить. Какой патент вам нужен?";
			if (GetPatentNation() != ENGLAND)
			{
			    link.l1 = "Англии";
				link.l1.go = "SetNationPatent_0";
			}
			if (GetPatentNation() != FRANCE)
			{
			    link.l2 = "Франции";
				link.l2.go = "SetNationPatent_1";
			}
			if (GetPatentNation() != SPAIN)
			{
			    link.l3 = "Испании";
				link.l3.go = "SetNationPatent_2";
			}
			if (GetPatentNation() != HOLLAND)
			{
			    link.l4 = "Голландии";
				link.l4.go = "SetNationPatent_3";
			}
			link.l9 = "Знаете, я думаю, что обойдусь своими силами.";
			link.l9.go = "exit";
		break;
		
		case "patent_2":
            //pchar.PatentPrice = 8000 + (sti(NPChar.PatentPrice) * sti(pchar.rank));
			// pchar.PatentPrice = 350000 - (GetSummonSkillFromName(PChar, SKILL_COMMERCE) + GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 2000 + 6000 * sti(pchar.rank) * MOD_SKILL_ENEMY_RATE;
			if (IsCharacterPerkOn(pchar, "Trustworthy")) pchar.PatentPrice = 100000 * MOD_SKILL_ENEMY_RATE - (GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 5000 + 35000 + (sti(PChar.rank)*5000);
			else pchar.PatentPrice = 150000 * MOD_SKILL_ENEMY_RATE - (GetSummonSkillFromName(PChar, SKILL_LEADERSHIP)) * 5000 + 500000 + (sti(PChar.rank)*5000);
            switch (sti(NPChar.nation))
            {
			    case PIRATE :
                    dialog.text = "Явный баг, если видите - сообщите ALexusB";
                    link.l1 = "Неплохая перспектива. Я "+ GetSexPhrase("согласен","согласна") +" на ваши условия!";
                    break;
                case HOLLAND :
                    dialog.text = "Голландия почти мирная страна, у вас станет много друзей и мало врагов. А сам патент обойдется вам всего лишь в "+pchar.PatentPrice+" песо.";
                    link.l1 = "Неплохая перспектива. Я "+ GetSexPhrase("согласен","согласна") +" на ваши условия!";
                    break;
                case FRANCE :
                    dialog.text = "Друзья и враги Франции станут вашими. Вы сможете топить корабли врагов. А сам патент обойдется вам всего лишь в "+pchar.PatentPrice+" песо.";
                    link.l1 = "Отличная перспектива! Мне плевать, кому служить! Послужу и французам!";
                    break;
                case SPAIN :
                    dialog.text = "У Испании много врагов и они тут же станут вашими! Испанцы - нация морских воинов. Патент обойдется вам всего лишь в "+pchar.PatentPrice+" песо.";
                    link.l1 = "Вы один предлагаете мне что-то стоящее! Получите эти жалкие гроши за романтику кровавого боя и новые задания высокопоставленных особ!";
                    break;
                case ENGLAND :
                    dialog.text = "Если честно, таким образом генерал-губернатор Англии набивает свой карман. А сам патент обойдется вам всего лишь в "+pchar.PatentPrice+" песо.";
                    link.l1 = "Я "+ GetSexPhrase("согласен","согласна") +" отдать ему свои кровные деньги, которые добыл"+ GetSexPhrase("","а") +" контрабандой и абордажами!!";
                    break;
			}

            if(makeint(Pchar.money) < makeint(pchar.PatentPrice))
            {
				Link.l1.go = "No_money";
			}
            else
			{
				link.l1.go = "patent_3";
			}

			link.l2 = "Нет, это не для меня!";
			link.l2.go = "exit";
		break;

		case "patent_3":
            pchar.PatentNation = NationShortName(sti(NPChar.nation));
			dialog.text = "Я рад, что мы договорились. По рукам.";
			link.l1 = "Прощайте, "+GetAddress_FormToNPC(NPChar);
			link.l1.go = "exit";
			AddDialogExitQuest("any_patent_take");
		break;

		case "Contraband":
			if (IsCharacterPerkOn(pchar, "Trustworthy")) Pchar.questTemp.Relations.sum = makeint(0.3 * stf(Pchar.rank)/stf(Pchar.reputation)*DIPLOMAT_SUM);
			else Pchar.questTemp.Relations.sum = makeint(0.1 * stf(Pchar.rank)/stf(Pchar.reputation)*DIPLOMAT_SUM);
			dialog.Text = "Хорошо. Это обойдется в " + Pchar.questTemp.Relations.sum + " золотых.";
			Link.l1 = "Я соглас"+ GetSexPhrase("ен","на") +".";
			if(makeint(Pchar.money) < makeint(Pchar.questTemp.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Contraband_Agreed";
			}
			Link.l2 = "Пожалуй, я передумал"+ GetSexPhrase("","а") +".";
			Link.l2.go = "exit";
		break;
		
		case "Contraband_Agreed":
			dialog.Text = "Замечательно, я все улажу. Они будут иметь с вами дело.";
			Link.l99 = "Спасибо.";
			Link.l99.go = "exit";
			ChangeContrabandRelation(pchar, 25);
			AddMoneyToCharacter(pchar, -sti(Pchar.questTemp.Relations.sum));
		break;
        // boal <--
		case "RelationAny_Done":
			iSumm = sti(npchar.quest.relation.summ);
			dialog.text = "Хм-м... даже не знаю, что сказать. Я, конечно, смогу выполнить вашу просьбу о примирении с "+ XI_ConvertString(Nations[sti(npchar.quest.relation)].Name + "Abl") +", но это будет вам стоить " + FindRussianMoneyString(iSumm) + ".";
			if(sti(pchar.money) >= iSumm)
			{
				link.l1 = "Думаю, у меня все равно нет выбора. Так что вот ваши деньги.";
				link.l1.go = "relation3";
			}
			link.l2 = "Нет, это слишком большая сумма. Прощайте.";
			link.l2.go = "exit";
		break;

		case "relation3":
			dialog.text = "Отлично! С вами удивительно легко иметь дело. Можете быть спокойны, по истечении максимум 15 дней ваши дела будут улажены.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(npchar.quest.relation.summ));
			ChangeNationRelationFromRelationAgent(npchar);
			attrLoc = "RelationAgent" + GetNationNameByType(sti(npchar.quest.relation));
            Pchar.GenQuest.(attrLoc) = true;
		break;
		
		case "RelationYet":
			dialog.Text = "За вас уже пошло ходатайство. Ждите, так быстро дела не делаются.";
			Link.l99 = "Спасибо.";
			Link.l99.go = "exit";
		break;
		
		case "City_Buy":
			dialog.Text = "Принадлежность какого поселения вы хотите обсудить?";
			for (i=0; i<MAX_COLONIES; i++)
			{
				if (sti(colonies[i].HeroOwn) == true && sti(colonies[i].isBought) == false)
				{
					sld = GetFortCommander(colonies[i].id);
					attrLoc = "l" + i;
					Link.(attrLoc) = GetCityName(colonies[i].id) + " - " + XI_ConvertString(GetNationNameByType(sti(sld.Default.nation)));
					Link.(attrLoc).go = "CityPay_" + i;
				}
			}
			Link.l99 = "Нет. Ничего.";
			Link.l99.go = "exit";
		break;
		
		case "CityInfo":
            i = sti(NPChar.quest.CityIdx);
            sld = GetFortCommander(colonies[i].id);
            iSumm = TWN_CityCost(colonies[i].id);
			dialog.Text = "Город " + GetCityName(colonies[i].id) + ", принадлежал " + XI_ConvertString(GetNationNameByType(sti(sld.Default.nation)) + "Gen") + ", сумма выкупа для прекращения попыток отбить поселение составит " + FindRussianMoneyString(iSumm) + ".";
   			if(sti(pchar.money) >= iSumm)
			{
			    Link.l1 = "Да, меня это вполне устраивает.";
				Link.l1.go = "City_Buy_End";
			}
			Link.l99 = "Нет, спасибо. Не интересно.";
			Link.l99.go = "exit";
		break;
		
		case "City_Buy_End":
            i = sti(NPChar.quest.CityIdx);
            TWN_RealeseForMoney(colonies[i].id, true);
			dialog.Text = "Хорошо, информация о сделке пошла. Попыток захвата города " + GetCityName(colonies[i].id) + " больше не будет.";
			Link.l2 = "Спасибо. Всего хорошего.";
			Link.l2.go = "exit";
			Link.l3 = "Еще один вопрос.";
			Link.l3.go = "relation";
		break;
	}
}

