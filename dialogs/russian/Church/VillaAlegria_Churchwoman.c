// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "И в третий раз говорю тебе, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Не сейчас, " + GetSexPhrase("сестра","сестра") + "..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, " + GetSexPhrase("сестра","сестра") + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажите, " + GetSexPhrase("святой отец","сестра") + ", а имя 'Хуан' вам что-нибудь говорит?";
				link.l1.go = "Consumption";
			}
		
		break;

		//Цена чахотки
		case "Consumption":
			dialog.text = "Нет, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ". В нашем городе много прихожан с таким именем.";
			link.l1 = "Ясно. Простите за беспокойство, " + GetSexPhrase("сестра","сестра") + "...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
