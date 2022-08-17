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

	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerSavLaMar" && !CheckAttribute(npchar, "quest.APS_usurerSavLaMar"))
	{
		link.l1 = "Ты не в курсе, куда все подевались!";
		link.l1.go = "ApostatesAPS_1";
	}
	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_BankSavLaMar" && !CheckAttribute(npchar, "quest.APS_BankSavLaMar"))
	{
		link.l1 = "Я тебя предупреждал, с этими ребятами шутки плохи!";
		link.l1.go = "ApostatesAPS_4";
	}

		break;

	// ********************* Отступники веры ******************

		case "ApostatesAPS_1":
		dialog.text = "Капитан, была замечена эскадра Иезуитов около острова, Магистр со своими людьми ушли от греха подальше.";
		link.l1 = "Ты знаешь куда они могли уйти!";
		link.l1.go = "ApostatesAPS_2";
		break;
		
		case "ApostatesAPS_2":
		dialog.text = "Знаю, но я не могу вам это сказать, уж простите.";
		link.l1 = "Хорошо, но почему ты не ушёл с ними, если сюда заявятся Иезуиты тебе может это стоить жизни.";
		link.l1.go = "ApostatesAPS_3";
		break;
		
		case "ApostatesAPS_3":
	                     ChangeCharacterComplexReputation(pchar, "nobility", 5);
		dialog.text = "Возможно, я не боюсь. Но думаю наврят ли они посмеют в этом поселении навязывать свои порядки. А вот тебе нужно уходить как можно скорее.";
		link.l1 = "Мм... Спасибо за совет.";
		link.l1.go = "Exit";
	                     npchar.quest.APS_usurerSavLaMar = "true";
		AddDialogExitQuest("GothicApostates_APS_SavLaMarfrom");
		break;

		case "ApostatesAPS_4":
		dialog.text = "Не могу поверить, что бы священики были садистами, значит я правильно выбрал сторону и ни о чём не сожалею.";
		link.l1 = "....";
		link.l1.go = "Exit";
	                     npchar.quest.APS_BankSavLaMar = "true";
		AddDialogExitQuest("GothicApostatesAPS_BankSavLaMar");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

