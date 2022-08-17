// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "М-да, позвольте угадаю... Опять ничего существенного?",
                          "Послушайте, я финансами оперирую, а не на вопросы отвечаю...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Вы угадали, простите...", "Я понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			// Отступники веры

			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerPortoBello" && !CheckAttribute(npchar, "quest.APS_usurerPortoBello"))
			{
				link.l2 = "Меня направил сюда Магистр, я ищу одного человека, он должен сюда прибыть с поручением от Иезуитов.";
				link.l2.go = "ApostatesAPS_1";
			}
			
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerPortoBelloOver" && !CheckAttribute(npchar, "quest.APS_usurerPortoBelloOver"))
			{
				dialog.text = ""+pchar.lastname+", вы опоздали! Этот человек уже приходил и куда он теперь направился, я понятия не имею...";
				link.l3 = "...";
				link.l3.go = "Exit";
								 npchar.quest.APS_usurerPortoBelloOver = "true";
				AddDialogExitQuestFunction("GothicApostatesAPSCPortoBelloEND");
			}
			
			if(CheckAttribute(pchar, "ChurchQuest") && pchar.ChurchQuest == "to_PortoBello_Usurer")
	        {
				link.l4 = "Вы знаете человека по имени Рэндольф Кэннелл, не так ли?";
				link.l4.go = "ChurchQuest_3";
			}

			
			
		break;
		
		// ********************* Отступники веры ******************

		case "ApostatesAPS_1":
			dialog.text = "Очень хорошо, капитан. Не далее, как сегодня утром у меня пытались выведать информацию о Магистре. Я попросил этого человека, что бы он зашел к вечеру, дабы оттянуть время.";
			link.l1 = "Отличная новость! Значит, я прибыл" + GetSexPhrase("","а") + " вовремя.";
			link.l1.go = "ApostatesAPS_2";
		break;
		
		case "ApostatesAPS_2":
			dialog.text = "Да, капитан, можете спокойно идти отдохнуть и расслабиться в таверне. Приходите ночью, братья тоже будут здесь.";
			link.l1 = "Хорошо, кстати, мне Магистр сказал, что я могу получить у тебя 15000 песо.";
			link.l1.go = "ApostatesAPS_3";
		break;
		
		case "ApostatesAPS_3":
		    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			AddMoneyToCharacter(pchar, 15000);
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			dialog.text = "Конечно-конечно, вот ваши деньги. Кстати, вы всегда можете рассчитывать на хороший займ у меня под мизерные проценты, хе-хе.";
			link.l1 = "Знаю я ваши ‘мизерные’ проценты... Ладно, до вечера.";
			link.l1.go = "Exit";
			npchar.quest.APS_usurerPortoBello = "true";
			AddDialogExitQuest("GothicApostates_APS_wait");
		break;
		
		case "ChurchQuest_3":
		    dialog.text = "А к чему вы это спрашиваете?";
		    link.l1 = "Да так, нужно с ним переговорить.";
		    link.l1.go = "ChurchQuest_5_1";
	    break;

	    case "ChurchQuest_5_1":
		    dialog.text = "О чем же?";
		    link.l1 = "Говорят, он отличный лекарь и помог вам когда-то, я надеюсь, что он поможет и моей тетушке.";
		    link.l1.go = "ChurchQuest_5_2";
	    break;

	    case "ChurchQuest_5_2":
			dialog.text = "Что же с вашей тетушкой?";
			link.l1 = "О, у нее подагра, теперь только компрессы и припарки Квинтиуса Апиуса могут ее спасти от страшных мучений.";
			link.l1.go = "ChurchQuest_5_3";
	    break;

		case "ChurchQuest_5_3":
			dialog.text = "Так, а я-то тут причем?";
			link.l1 = "Я знаю, он помог вам. Может быть, вы в курсе, как я могу найти его.";
			link.l1.go = "ChurchQuest_5_4";
		break;

		case "ChurchQuest_5_4":
			dialog.text = "Он должен зайти ко мне сегодня ночью, можете его подождать.";
			link.l1 = "Конечно, я его дождусь.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_on_Beliz_search_Apius2");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

