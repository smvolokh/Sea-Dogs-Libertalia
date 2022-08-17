// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "И в третий раз говорю тебе, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Падре я по поручению Торуса расследую убийство в борделе, ничего не слышали об этом ужасном деле?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
		break;

			// Розо или Шарлотт-Таун

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Нет, сын мой!!!";
		link.l1 = "И вы готовы поручится за каждого?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Я верю в Бога и верю людям! Люди не могли такое сделать!!!";
		link.l1 = "Тогда кто по вашему мнению мог совершить такой тяжкий грех?";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "Я не могу знать, я всего лишь человек сын мой, но убеждён, что правосудие свершится, кем бы или чем бы оно не было.";
		link.l1 = "Спасибо, мне пора.";
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