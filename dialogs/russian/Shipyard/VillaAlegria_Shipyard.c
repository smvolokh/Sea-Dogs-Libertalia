// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "У себя на верфи, а и вообще в городе, я таких однообразно любознательных не видал.",
                          "Ну что за вопросы? Мое дело - корабли строить, давайте этим и займемся.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить."), "Хм, что-то с памятью моей стало...",
                      "Хм, однако...", "Давайте...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажи, имя 'Хуан' тебе что-нибудь говорит?";
				link.l1.go = "Consumption";
			}

		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Нет. Совершенно ни о чем.";
			link.l1 = "Ясно. Извини за беспокойство...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

