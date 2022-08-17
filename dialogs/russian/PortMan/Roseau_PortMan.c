// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушайте, если вы не по делам порта, то не стоит меня вопросами донимать.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Извините, но портовые дела меня сейчас не интересуют.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышали об этом, может, что видели, может мысли какие - нибудь?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

			// Розо или Шарлотт-Таун
 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Сколько не ломал голову по этому проишествию, не одной здравой мысли, даже следов крови нет!!!";
		link.l1 = "Ну, может быть оборотень?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Нет, я в эти сказки не верю, оборотни, вампиры и тому подобное, всё это детские страшилки!";
		link.l1 = "Ну, не может же сама голова отделится от тела и уйти, чтобы никто не видел и тем более - две.";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "С вами я полностью согласен, загадка, поэтому никакой здравой мысли. Прошу прощения, но я ничем не могу помочь.";
		link.l1 = "Ладно, я понял.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

