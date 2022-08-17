// boal 25/04/04 общий диалог церковь
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
	case "First time":
            	dialog.text = "Добрый день, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ".";
        	link.l1 = "Приветствую.";
        	link.l1.go = "1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

		case "1":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "И в третий раз говорю тебе, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

   			link.l2 = RandPhraseSimple("Я хочу внести пожертвования.", "Хочу пожертвовать на благое дело.");
    			link.l2.go = "donation";

			link.l3 = "Извините, мне пора идти.";
			link.l3.go = "exit";
		break;

		case "donation":
			dialog.Text = "Конечно, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ". Сколько ты желаешь пожертвовать Святой Церкви?";
			Link.l1 = "Простите, святой отец, но пожертвования не будет.";
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{
				Link.l2 = "К сожалению, немного. 100 пиастров.";
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = "1000 пиастров. Я думаю, этого хватит.";
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{
				Link.l4 = "Мне везет с деньгами, поэтому я пожертвую 5000 пиастров.";
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			dialog.Text = "Хм... Это ваше решение, и вы вправе его изменить. Но не забывайте о том, что все это зачтется вам после смерти.";
			Link.l1 = "Мне еще далеко до смерти! Давайте лучше сменим тему.";
			Link.l1.go = "2";
			Link.l2 = "Извините, святой отец, мне пора.";
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			AddMoneyToCharacter(pchar, -100);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 100;
			dialog.Text = "От лица Святой Церкви благодарю вас, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", за ваш дар.";
			Link.l1 = "Мне надо поговорить с вами, святой отец.";
			Link.l1.go = "ispoved";
			Link.l2 = "Извините, святой отец, мне пора.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_1000":
			AddMoneyToCharacter(pchar, -1000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 1000;
			dialog.Text = "От лица Святой Церкви благодарю вас, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", за ваш дар.";
            Link.l1 = "Мне надо поговорить с вами, святой отец.";
			Link.l1.go = "ispoved";
			Link.l2 = "Извините, святой отец, мне пора.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_5000":
			AddMoneyToCharacter(pchar, -5000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 5000;
			dialog.Text = "От лица Святой Церкви благодарю вас, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", за ваш дар.";
            Link.l1 = "Мне надо поговорить с вами, святой отец.";
			Link.l1.go = "ispoved";
			Link.l2 = "Извините, святой отец, мне пора.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "2":
			dialog.Text = "Тем не мение, от лица Святой Церкви благодарю вас, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", за ваше понимание.";
			Link.l1 = "Извините, святой отец, мне пора.";
			Link.l1.go = "exit";
		break;

		case "ispoved":
			dialog.text = "Конечно же, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", я тебя слушаю.";
			link.l1 = "Я передумал. Может быть в другой раз.";
			link.l1.go = "exit";
			link.l2 = "Я так грешен, святой отец...";
			link.l2.go = "ispoved_1";
		break;

		case "ispoved_1":
			dialog.text = "Все мы грешны.";
			link.l1 = "Да, но я... Я топил и грабил корабли, я убивал...";
			link.l1.go = "ispoved_2";
		break;

		case "ispoved_2":
			dialog.text = "Но ведь среди них не было тех, кто плавал под флагом " + NationNameGenitive(sti(NPChar.nation)) + "?";
			link.l1 = "Нет, конечно, святой отец.";
			link.l1.go = "ispoved_3";
			link.l2 = "Были и такие, святой отец.";
			link.l2.go = "ispoved_4";
		break;

		case "ispoved_3":
			dialog.text = "Тогда Господь прощает тебе твои грехи.";
			link.l1 = "Спасибо, святой отец, я пойду.";
			link.l1.go = "exit";
		break;

		case "ispoved_4":
			dialog.text = "Господь никогда не простит тебе этот грех!";
			link.l1 = "Прощайте, святой отец.";
			link.l1.go = "exit";		
		break;


	}
}

