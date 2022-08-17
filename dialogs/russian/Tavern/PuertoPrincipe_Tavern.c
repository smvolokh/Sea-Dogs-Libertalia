// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
// Отступники веры
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_Tavern" && !CheckAttribute(npchar, "quest.APS_Tavern"))
			{
				link.l1 = "Налей мне что-нибудь по крепче?";
				link.l1.go = "APS_1";
			}
		break;

		// Отступники веры
		case "APS_1":
		dialog.text = "Налью, но попозже! При всём уважении кэп, убийсво монаха - дурная примета.";
		link.l1 = "Я не верю в приметы...";
		link.l1.go = "Exit";
		npchar.quest.APS_Tavern = "true";
		AddDialogExitQuest("GothicApostates_APS_PuertoPrincipeTavern");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

