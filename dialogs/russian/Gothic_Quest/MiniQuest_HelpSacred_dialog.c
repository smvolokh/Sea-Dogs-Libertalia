
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	

	switch(Dialog.CurrentNode)
	{

	case "First time":
            	dialog.text = "Доброй ночи, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ".";
        	link.l1 = "Приветствую.";
        	link.l1.go = "1";
		break;


		case "1":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "И в третий раз говорю тебе, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "End";


				if(PChar.HelpSacredInquisition == "1" && PChar.location == "LeFransua_HouseInsideR9")
				{

					link.l2 = "Простите, святой отец?";
					link.l2.go = "HelpSacredInquisition_1";					
	
					break;
				}

				if(PChar.HelpSacredInquisition == "Good" && PChar.location == "LeFransua_HouseInsideR9")
				{
					link.l2 = "Натан Рич понёс заслуженное наказание, и получил бесплатный билет в ад, святой отец.";
					link.l2.go = "HelpSacredInquisition_6";	
				}
				
					break;				

						
		// ПОМОЩЬ СВЯТОЙ ИНКВИЗИЦИИ -->


		case "HelpSacredInquisition_1":
			dialog.text = "Проходи раз приш" + GetSexPhrase("ёл","ла") + ", расказывай?";
			link.l1 = "А что вы делаете здесь в этом городке, здесь же одни пираты и разбойники?.";
			link.l1.go = "HelpSacredInquisition_2";
		break;

		case "HelpSacredInquisition_2":
			dialog.text = "Я служитель церкви, и господь посылает таких как я в такие места, что поделать у нас нет выбора. А Бог нужен всем даже отпетым негодяем?";
			link.l1 = "Скорее всего вы правы?.";
			link.l1.go = "HelpSacred_3";
		break;

		case "HelpSacred_3":
			dialog.text = "Вы слышали новость, прямо под носом у святой инквизиции некий капитан  распространял слухи о том, что любой человек может обладать силой Бога?";
			link.l1 = "Наверное он был сильно пьян или просто безумец?.";
			link.l1.go = "HelpSacred_4";
		break;
		
		case "HelpSacred_4":
			dialog.text = "За подобные речи инквизиция не прощает, похоже он сильно попал и поверте мне он не жилец?";
			link.l1 = "Да, дела?.";
			link.l1.go = "HelpSacred_5";
		break;

		case "HelpSacred_5":
			dialog.text = "Вы можите помочь, отыскать этого безумца и передать его нам если это будет возможно.";
			link.l1 = "Вы хотите...";
			link.l1.go = "HelpSacredInquisition_3";
		break;
		
		case "HelpSacredInquisition_3":
			dialog.text = "Да! Найдите и покарайте! Мы простим вам все грехи на которые вам придется пойти, дабы свершить правосудие. И, конечно же, вознаградим.";
			link.l1 = "Нет. Быть божественным поборником это не по мне.";
			link.l1.go = "HelpSacredInquisition_4";			
			link.l2 = "Хорошо. А у вас есть хоть малейшее представление, где его искать? Или, как его зовут?";
			link.l2.go = "HelpSacredInquisition_5";
		break;

		case "HelpSacredInquisition_4":
			PChar.HelpSacredInquisition = "END";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "HelpSacredInquisition_5":
			dialog.text = "Если б я только знал, где его искать. Начни с Сантьяго может повезет. А зовут его Натан Рич.";
			link.l1 = "Что ж, начинаю поиски. До встречи, святой отец.";
			link.l1.go = "End";
			AddDialogExitQuestFunction("HelpSacredInquisitionStart");
		break;

		case "HelpSacredInquisition_6":
			dialog.text = "Святая Инквизиция благодарит вас, капитан " + GetName(PChar, "f") + ".";
			link.l1 = "Спасибо, святой отец.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("HelpSacredInquisitionEnd");
		break;


 		case "End":
                NextDiag.CurrentNode = "Fifth time";
		DialogExit();
		break;

	case "Fifth time":
            	dialog.text = "Доброй ночи, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ", капитан " + PChar.name + "! Как у вас идут дела?";
        	link.l1 = "Неплохо. Простите, но я спешу.";
        	link.l1.go = "20";
		break;

		case "20":
            	dialog.text = "Конечно, не смею вас задерживать.";
        	link.l1 = "";
        	link.l1.go = "End";
		break;



		// ПОМОЩЬ СВЯТОЙ ИНКВИЗИЦИИ <--
	}
}
