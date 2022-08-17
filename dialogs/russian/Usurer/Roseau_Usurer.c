// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "М-да, позвольте угадаю... Опять ничего существенного?",
                          "Послушайте, я финансами оперирую, а не на вопросы отвечаю...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Вы угадали, простите...", "Я понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышал об этом, может, что видел, может мысли какие - нибудь?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlottePRESENT" && !CheckAttribute(npchar, "quest.RoseauCharlottePRESENT"))
			{
				link.l1 = "Я по поводу вознаграждения...";
				link.l1.go = "RoseauCharlottePRESENT";
			}
		break;

			// Розо или Шарлотт-Таун
 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Нет, ни каких мыслей, всё это странно и ужасно!!!";
		link.l1 = "Ну, может кого подозреваете?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Нет.";
		link.l1 = "Если, что вспомните сообщите либо мне, либо Торусу!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "Хорошо.";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

                                      case "RoseauCharlottePRESENT":
		dialog.text = "Да, Торус мне говорил, извольте получить?";
		link.l1 = "";
		link.l1.go = "PRESENT_1";
  		break;

                                      case "PRESENT_1":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_1.wav");
		dialog.text = "";
		link.l1 = "Да!";
		link.l1.go = "PRESENT_2";
  		break;

                                       case "PRESENT_2":
		 TakeNItems(pchar, "gold_dublon", 300);
		 Log_Info("Вы получили 300 дублонов");
                                     PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		 DialogExit();
		 NextDiag.CurrentNode = NextDiag.TempNode;
		 npchar.quest.RoseauCharlottePRESENT = "true";
  		 break;





	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}