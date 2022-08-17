// Абуоин предсказатель
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
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_HALLO_13_00.wav");
			dialog.text = "Приветствую тебя мой друг, присять на мой скромный коврик и насладись дымом из моей трубки!";
			link.l1 = "Ну как, время ещё не пришло?";
			link.l1.go = "no_guess_exit";
			link.l2 = "Приветствую, Абуоин! Давай поторгуем!";
			link.l2.go = "trade";

	if (CheckAttribute(npchar, "quest.AbuyinInfo_25"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_25"))
		{
		link.l2 = "Время ещё не настало для пророчества?";
		link.l2.go = "WEISSAGUNG_1";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 25)
		{
		link.l2 = "Принес я тебе 25 дублонов. Делай предсказание.";
		link.l2.go = "guess_05";
		}
                     }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_100"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_100"))
		{
		link.l2 = "Время ещё не настало для пророчества?";
		link.l2.go = "WEISSAGUNG_2";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 100)
		{
		link.l2 = "Я принес тебе 100 дублонов. Делай предсказание.";
		link.l2.go = "guess_22";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_250"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_250"))
		{
		link.l2 = "Время ещё не настало для пророчества?";
		link.l2.go = "WEISSAGUNG_3";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 250)
		{
		link.l2 = "Я принес тебе 250 дублонов. Делай предсказание.";
		link.l2.go = "guess_32";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_500"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_500"))
		{
		link.l2 = "Время ещё не настало для пророчества?";
		link.l2.go = "WEISSAGUNG_4";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l2 = "Я принес тебе 500 дублонов. Делай предсказание.";
		link.l2.go = "guess_42";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_1000"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_1000"))
		{
		link.l2 = "Время ещё не настало для пророчества?";
		link.l2.go = "WEISSAGUNG_4";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 1000)
		{
		link.l2 = "Я принес тебе 1000 дублонов. Делай предсказание.";
		link.l2.go = "guess_42";
		}
	
          }
}
		link.l15 = "Спасибо, ничего. До свидания.";
		link.l15.go = "exit";

		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
			dialog.text = LinkRandPhrase(GetFullName(pchar) + ", рад тебя видеть! О, сын загадочного будущего. Зачем пожаловал"+ GetSexPhrase("","а") +" на этот раз?",
                                         RandSwear() + " Кого я вижу?! Сын загадочного будущего " + GetFullName(pchar) + ". Какими судьбами на острове?",
                                         "Так-так, "+ GetFullName(pchar)+ " у меня в гостях. Ну что, какие вопросы, "+ GetSexPhrase("друг","подруга") +"?");
			link.l1 = RandPhraseSimple("Просто заскочил"+ GetSexPhrase("","а") +" проведать тебя.", "Время ещё не настало для пророчества?");
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";

	break;


/// ********************** Абуоин предсказатель  ***********************************
//------------------------------ первая встреча------------------------------------------------

	case "Abuyin":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_HALLO_13_00.wav");
            	dialog.text = "Приветствую тебя мой друг, присять на мой скромный коврик и насладись дымом из моей трубки! С кем имею честь, о " + GetSexPhrase("сын","дочь") + " загадочного будущего?";
        	link.l1 = "";
        	link.l1.go = "Abuyin_1";
	break;

	 case "Abuyin_1":
	 PlaySound("VOICE\Russian\GOTHIC\GG\GG_1.wav");
            	 dialog.text = "";
        	 link.l1 = "Я, искатель приключений с юга!";
        	 link.l1.go = "Abuyin_2";
	  break;

	 case "Abuyin_2":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_DU_15_00.wav");
            	 dialog.text = "";
        	 link.l1 = "Кто ты!";
        	 link.l1.go = "Abuyin_3";
	  break;

	case "Abuyin_3":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_DU_13_01.wav");
            	dialog.text = "Меня зовут Абуоин.......";
        	link.l1 = "";
        	link.l1.go = "Abuyin_4";
	break;

	case "Abuyin_4":
	PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Ты можешь сделать пророчество?";
        	link.l1.go = "Abuyin_5";
	break;

	case "Abuyin_5":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_01.wav");
            	dialog.text = "О, сын загадочного будущего, сейчас я не в силах приподнять завесу времени?";
        	link.l1 = "";
        	link.l1.go = "Abuyin_6";
	break;

	case "Abuyin_6":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_15_03.wav");
            	dialog.text = "";
        	link.l1 = "А когда это будет?";
        	link.l1.go = "Abuyin_7";
	break;

	case "Abuyin_7":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_02.wav");
            	dialog.text = "Только когда время подаст мне очередной знак, я смогу помочь тебе ещё раз.";
        	link.l1 = "";
        	link.l1.go = "Abuyin_8";
	break;

	case "Abuyin_8":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_04.wav");
            	dialog.text = "Когда будущее станет настоящим и ты продолжишь свой путь.";
        	link.l1 = "";
        	link.l1.go = "exit";
                   DoQuestFunctionDelay("SMALLTALK_L", 2.5);
	break;

//-------------------------------------------------предсказания-------------------------------------------------

//-------------------------------------------------1 пророчество-------------------------------------------------

		case "WEISSAGUNG_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты можешь сделать пророчество?";
			link.l1.go = "guess_00";
		break;

		case "guess_00":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_13_01.wav");
			dialog.text = "Да, время ушло в перед и я могу сделать пророчество если у тебя найдется несколько монет.";
			link.l1 = "Пожалуй, я передумал" + GetSexPhrase("","а") + ". Неохота что-то...";
			link.l1.go = "exit";
			link.l2 = "Сколько денег ты просишь?";
			link.l2.go = "guess_01";
		break;

		case "guess_01":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_02.wav");
			dialog.text = "";
			link.l1 = "Сколько?";
			link.l1.go = "guess_02";
		break;

		case "guess_02":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_01.wav");
			dialog.text = "Я к твоим услугам за скромное вознагрождение о отец щедрости!";
			link.l1 = "";
			link.l1.go = "guess_03";
		break;


		case "guess_03":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_03.wav");
			dialog.text = "За какие то 25 монет я рискну заглянуть в будущее!";
			if (GetCharacterItem(pchar, "gold_dublon") >= 25)
			{
				link.l1 = "Хорошо, вот тебе 25 дублонов... Делай предсказание.";
				link.l1.go = "guess_04";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold";
			}
		break;

		case "exit_gold":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня не достаточно золота...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_25;
		break;

		case "guess_04":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "guess_05";
		break;

		case "guess_05":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 25);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_06";
		break;

		case "guess_06":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_04.wav");
			dialog.text = "Но помни будущее всегда не определенно, всё что в моих силах это уловить лишь крошечные фрагменты времени!";
			link.l1 = "";
			link.l1.go = "guess_07";
		break;

		case "guess_07":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "Раскажи мне о будущем.";
			link.l1.go = "guess_08";
		break;

		case "guess_08":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_13_01.wav");
			dialog.text = "Хорошо о жаждущий знаний я сейчас войду в состояние транса, ты готов?";
			link.l1 = "";
			link.l1.go = "guess_09";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_09":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "Давай к делу?";
			link.l1.go = "TRANCE_1";
		break;


	
/// ********************** 1 пророчество ***********************************

		case "TRANCE_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_00.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_1";
			
		break;

		case "TRANCE_1_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_01.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_2";
		break;

		case "TRANCE_1_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_02.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_3";
		break;

		case "TRANCE_1_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_03.wav");
			dialog.text = "Это всё, что я мог увидеть!";
			link.l1 = "";
			link.l1.go = "guess_exit_1";
		break;


/// ********************** 2 пророчество ***********************************


		case "WEISSAGUNG_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты можешь сделать пророчество?";
			link.l1.go = "guess_20";
		break;

		case "guess_20":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_13_02.wav");
			dialog.text = "О, отец монет, я прошу у тебя 100 золотых в обмен на взгляд в туманное будущее.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "Хорошо, вот тебе 100 дублонов... Делай предсказание.";
				link.l1.go = "guess_21";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_100";
			}
		break;

		case "exit_gold_100":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня не достаточно золота...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_100;
		break;

		case "guess_21":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "Вот твоё золото...";
		link.l1 = "";
		link.l1.go = "guess_22";
		break;

		case "guess_22":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 100);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_23";
		break;

		case "guess_23":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "Раскажи мне о будущем.";
			link.l1.go = "guess_24";
		break;

		case "guess_24":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_13_01.wav");
			dialog.text = "Хорошо, о сын мужества я сейчас войду в состояние транса, ты готов?";
			link.l1 = "";
			link.l1.go = "guess_25";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_25":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "Давай к делу?";
			link.l1.go = "TRANCE_2";
		break;

/// ********************** 2 пророчество ***********************************

		case "TRANCE_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_00.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_1";
			
		break;

		case "TRANCE_2_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_01.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_2";
		break;

		case "TRANCE_2_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_02.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_3";
		break;

		case "TRANCE_2_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_03.wav");
			dialog.text = "Это всё, что я мог увидеть!";
			link.l1 = "";
			link.l1.go = "guess_exit_2";
		break;


/// ********************** 3 пророчество ***********************************


		case "WEISSAGUNG_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты можешь сделать пророчество?";
			link.l1.go = "guess_30";
		break;

		case "guess_30":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_13_02.wav");
			dialog.text = "О, отец монет, я прошу у тебя 250 золотых в обмен на взгляд в туманное будущее.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "Хорошо, вот тебе 250 дублонов... Делай предсказание.";
				link.l1.go = "guess_31";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_250";
			}
		break;

		case "exit_gold_250":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня не достаточно золота...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_250;
		break;

		case "guess_31":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "Вот твоё золото...";
		link.l1 = "";
		link.l1.go = "guess_32";
		break;

		case "guess_32":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 250);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_33";
		break;

		case "guess_33":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "Раскажи мне о будущем.";
			link.l1.go = "guess_34";
		break;

		case "guess_34":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_13_01.wav");
			dialog.text = "Хорошо, о сын знаний я сейчас войду в состояние транса, ты готов?";
			link.l1 = "";
			link.l1.go = "guess_35";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_35":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "Давай к делу?";
			link.l1.go = "TRANCE_3";
		break;

/// ********************** 3 пророчество ***********************************

		case "TRANCE_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_00.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_1";
			
		break;

		case "TRANCE_3_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_01.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_2";
		break;

		case "TRANCE_3_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_02.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_3";
		break;

		case "TRANCE_3_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_03.wav");
			dialog.text = "Это всё, что я мог увидеть!";
			link.l1 = "";
			link.l1.go = "guess_exit_3";
		break;


/// ********************** 4 пророчество ***********************************


		case "WEISSAGUNG_4":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты можешь сделать пророчество?";
			link.l1.go = "guess_40";
		break;

		case "guess_40":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_13_02.wav");
			dialog.text = "О, отец монет, я прошу у тебя 500 золотых в обмен на взгляд в туманное будущее.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "Хорошо, вот тебе 500 дублонов... Делай предсказание.";
				link.l1.go = "guess_41";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_500";
			}
		break;

		case "exit_gold_500":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня не достаточно золота...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_500;
		break;

		case "guess_41":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "Вот твоё золото...";
		link.l1 = "";
		link.l1.go = "guess_42";
		break;

		case "guess_42":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 500);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_43";
		break;

		case "guess_43":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "Раскажи мне о будущем.";
			link.l1.go = "guess_44";
		break;

		case "guess_44":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_13_01.wav");
			dialog.text = "Хорошо, о сын знаний я сейчас войду в состояние транса, ты готов?";
			link.l1 = "";
			link.l1.go = "guess_45";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_45":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "Давай к делу?";
			link.l1.go = "TRANCE_4";
		break;

/// ********************** 4 пророчество ***********************************

		case "TRANCE_4":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_00.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_1";
			
		break;

		case "TRANCE_4_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_01.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_2";
		break;

		case "TRANCE_4_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_02.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_3";
		break;

		case "TRANCE_4_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_03.wav");
			dialog.text = "Это всё, что я мог увидеть!";
			link.l1 = "";
			link.l1.go = "guess_exit_4";
		break;


/// ********************** 5 пророчество ***********************************


		case "WEISSAGUNG_5":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты можешь сделать пророчество?";
			link.l1.go = "guess_50";
		break;

		case "guess_50":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_13_02.wav");
			dialog.text = "О, отец монет, я прошу у тебя 1000 золотых в обмен на взгляд в туманное будущее.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 1000)
			{
				link.l1 = "Хорошо, вот тебе 1000 дублонов... Делай предсказание.";
				link.l1.go = "guess_51";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_1000";
			}
		break;

		case "exit_gold_1000":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "У меня не достаточно золота...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_1000;
		break;

		case "guess_51":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "Вот твоё золото...";
		link.l1 = "";
		link.l1.go = "guess_52";
		break;

		case "guess_52":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 1000);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_53";
		break;

		case "guess_53":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "Раскажи мне о будущем.";
			link.l1.go = "guess_54";
		break;

		case "guess_54":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_13_01.wav");
			dialog.text = "Хорошо, о сын знаний я сейчас войду в состояние транса, ты готов?";
			link.l1 = "";
			link.l1.go = "guess_55";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_55":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "Давай к делу?";
			link.l1.go = "TRANCE_5";
		break;

/// ********************** 5 пророчество ***********************************

		case "TRANCE_5":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_00.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_1";
			
		break;

		case "TRANCE_5_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_01.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_2";
		break;

		case "TRANCE_5_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_02.wav");
			dialog.text = "Пророчествует ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_3";
		break;

		case "TRANCE_5_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_03.wav");
			dialog.text = "Это всё, что я мог увидеть!";
			link.l1 = "";
			link.l1.go = "guess_exit_5";
		break;


/// *********************************************************
		case "guess_exit_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                         DeleteAttribute(npchar, "quest.AbuyinInfo_25");
 
// --> ---здесь даем направление квеста Розо или Шарлотта -------------------------------

                                                         DoQuestFunctionDelay("GothicTorus_StartRoseauCharlotte", 10.0);

// --> ----------------------------------
		break;



		case "guess_exit_2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                       DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_100");

// --> ---здесь даем направление квеста по Аскольду -------------------------------

	                   DoQuestCheckDelay("Ascold_begin", 0.3);	

// --> ----------------------------------

		break;

		case "guess_exit_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_250");
		break;

		case "guess_exit_4":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_500");
		break;

		case "guess_exit_5":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                       DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_1000");
		break;

/// *********************************************************

		case "no_guess_exit":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00");
			dialog.text = "";
			link.l1 = "Ты можешь сделать предсказние?";
			link.l1.go = "no_guess_exit_1";
		break;
		case "no_guess_exit_1":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_01.wav");
			dialog.text = "О, сын загадочного будущего, сейчас я не в силах приподнять завесу времени?";
			link.l1 = "";
			link.l1.go = "no_guess_exit_2";
		break;
		case "no_guess_exit_2":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_15_03.wav");
			dialog.text = "";
			link.l1 = "А когда это будет?";
			link.l1.go = "no_guess_exit_3";
		break;
		case "no_guess_exit_3":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_02.wav");
			dialog.text = "Только когда время подаст мне очередной знак, я смогу помочь тебе ещё раз.";
			link.l1 = "";
			link.l1.go = "no_guess_exit_4";
		break;
		case "no_guess_exit_4":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_04.wav");
			dialog.text = "Когда будущее станет настоящим и ты продолжишь свой путь.";
			link.l1 = "";
			link.l1.go = "no_guess_exit_5";
		break;
		case "no_guess_exit_5":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

/// *********************************************************

		case "trade":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(20) + ".wav");	
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
			NextDiag.TempNode = "First time";
		break;

//----------------------------------------- специальные реакции -----------------------------------------------

		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Что ты там копаешься, а? Да ты вор!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой!", "По сундукам шарить вздумал?! Тебе это даром не пройдет!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Ах, вот, значит, как?! По сундукам шарить вздумал?! Тебе это даром не пройдет!";
			link.l1 = "Вот дура!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


	}
}
