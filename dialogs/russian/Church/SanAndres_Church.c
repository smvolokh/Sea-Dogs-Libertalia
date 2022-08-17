// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, "+ GetSexPhrase("сын мой","дочь моя") +"?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, "+ GetSexPhrase("сын мой","дочь моя") +"...", "И в третий раз говорю тебе, "+ GetSexPhrase("сын мой","дочь моя") +": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, "+ GetSexPhrase("сын мой","дочь моя") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		// Отступники веры
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_sailorSanAndresChurch" && !CheckAttribute(npchar, "quest.APS_SailorSanAndresChurch"))
		{
		link.l1 = "Дело вот в чем. В одной из таверн я познакомился с одним странным моряком - Бальсемио Монтехо. После произошедших с ним страшных событий он находится в очень плохом душевном состоянии.";
		link.l1.go = "SailorSanAndres";
		}
		break;

		case "SailorSanAndres":
		dialog.text = "Я понимаю, о ком идет речь. Я давно приглашал его к себе, ведь при нашей церкви жили двое прежних его товарищей, тоже участвовавших в тех событиях, о которых ты упомянул" + GetSexPhrase("","а") + ". Я помогал им чем мог, но вылечить их души мне не удалось.";
		link.l1 = "А где же они сейчас?";
		link.l1.go = "SailorSanAndres_1";
		break;
		
		case "SailorSanAndres_1":
		dialog.text = "На местном кладбище, царствие им небесное!";
		link.l1 = "Скажите, святой отец, эти двое усопших ничего не оставили вам перед смертью?";
		link.l1.go = "SailorSanAndres_2";
		break;
		
		case "SailorSanAndres_2":
		dialog.text = "Ты говоришь о части карты, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "? Я разочарую тебя - ничего такого они не оставляли. И я от всего сердца не советую тебе связываться с этой историей!";
		link.l1 = "Святой отец, я хочу разобраться в происшедшем.";
		link.l1.go = "SailorSanAndres_3";
		break;
		
		case "SailorSanAndres_3":
		dialog.text = "Ну что ж, я вижу - мне не отговорить тебя. Будь бдител" + GetSexPhrase("ен","ьна") + ", " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", и не забывай Господа нашего! Сегодня о них спрашивал ещё один человек.";
		link.l1 = "Ещё один человек! Как мне его найти, как выглядит?";
		link.l1.go = "SailorSanAndres_4";
		break;

		case "SailorSanAndres_4":
		dialog.text = "Думаю он ещё в городе, а выглядит в железном колпаке, кирасе в красной рубахе и в жёлтых гольфах по виду испанец.";
		link.l1 = "Спасибо, святой отец!";
		link.l1.go = "exit";
	                     npchar.quest.APS_SailorSanAndresChurch = "true";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_14");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}



