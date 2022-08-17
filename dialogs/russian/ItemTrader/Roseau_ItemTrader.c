// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Опять вопросы, " + GetAddress_Form(NPChar) + "...", "Вопросы, вопросы... Может торговлей займемся, " + GetAddress_Form(NPChar) + "?",
                          "Послушайте, ну сколько можно пустые разговоры вести?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Нет вопросов...", "Сейчас мне не о чем говорить"), "Эх, опять...",
                      "Да, действительно лучше торговаться...", "Хм, извини, торговец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "Killwork" && !CheckAttribute(npchar, "quest.Killwork"))
			{
				link.l1 = "Ты можешь сделать предсказание - шучу?";
				link.l1.go = "Killwork";
			}
		break;
		
			// Розо или Шарлотт-Таун
 		case "Killwork":
        	                  dialog.text = "Капитан, могу погадать на удачу!";
		link.l1 = "Не до гаданий - красавица? Столько народу и никто, ничего не знает, что происходит в соседнем доме?";
    		link.l1.go = "Killwork_1";
		break;

                                      case "Killwork_1":
		dialog.text = "Э, дорогой - мы цыгане всё знаем!";
		link.l1 = "Тогда скажи или нагадай кто убийца женщин в борделе?";
		link.l1.go = "Killwork_2";
  		break;

                                      case "Killwork_2":
		dialog.text = "Про это не знаю? В тот день убийства, я ранним утром видела как в город вошёл из сельвы Константино, может тебе это поможет.";
		link.l1 = "Спасибо, мне пора.";
		link.l1.go = "exit";
		npchar.quest.Killwork = "true";
		AddDialogExitQuestFunction("KillworkRoseaugirl_1");
  		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

