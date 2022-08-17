// Акил хитрый торговец
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
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_EXIT_13_02.wav");
            	dialog.text = "Пока, всегда рад помочь чем - нибудь.";
        	link.l1 = "";
        	link.l1.go = "exit";
		break;


	case "Exit1":
				dialog.text = "Ах, это вы, капитан "+ GetFullName(Pchar)+"? Как продвигаются ваши дела по поводу моего поручения?";
				link.l1 = "Все в полном порядке, Акил.";
        	link.l1.go = "Exit";
		break;

		case "1_1":
 	PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_1.wav");
			dialog.text = "";
			link.l1 = "Кто ты?";
			link.l1.go = "1_2";
		break;

		case "1_2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_01.wav");
			dialog.text = "Меня зовут Акил, я фермер на этом маленьком клочке земли!";
			link.l1 = "";
			link.l1.go = "1_3";
		break;

		case "1_3":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_LIEFERUNG_15_00.wav");
			dialog.text = "";
			link.l1 = "Меня прислал Бальтрам, я должен забрать посылку для него.";
			link.l1.go = "1_4";
		break;

		case "1_4":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_LIEFERUNG_13_01.wav");
			dialog.text = "Так ты его новый посыльный, хорошо я уже приготовил её.";
			link.l1 = "";
			link.l1.go = "1_5";
		break;

		case "1_5":
		PlaySound("interface\important_item.wav");
		GiveItem2Character(pchar, "cask_whisky");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDelivery_Baltram");
		break;









		
		case "1":
			dialog.text = "";
			link.l1 = "Я прив" + GetSexPhrase("ёз","езла") + " вам партию шелка от Бальтрама и письмо.";
			link.l1.go = "2";
		break;
		
		case "2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_EHRE_13_01.wav");
			dialog.text = "Ты настоящий друг, да хранит тебя Иннас на твоём пути?";
			link.l1 = "";
			link.l1.go = "3";
		break;
		
		case "3":
			TakeNItems(PChar, "BaltramNotice_0", -1);
			dialog.text = "...(читает письмо)... Вот это да! Бальтрам пишит, что вы убили самого Толстяка. Молодец, снимаю шляпу.";
			link.l1 = "Похоже он что-то попутал я его не убивал" + GetSexPhrase("","а") + ". Послушай, Акил, быть может, поговорим о деле? Ты ждал свой шелк, я жду свою награду. Давайте, наконец, покончим с этим.";
			link.l1.go = "4";
		break;
		
		case "4":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_AKILSSCHAF_13_01.wav");
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, 50);
			dialog.text = "Очень хорошо, вот несколько золотых, шесть тысяч песо надеюсь этого достаточно.";
			link.l1 = "Мы договаривались о семи тысячах. Шесть меня никак не устаивают.";
			link.l1.go = "5";
		break;
		
		case "5":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 6000);
			dialog.text = "Мы с вами ни о чём не договаривались, мес" + GetSexPhrase("ье","сис") + " "+ GetFullName(Pchar)+". Это Бальтрам вам соврал, сказав, что я заплачу семь тысяч. Если вам угодно, требуйте вашу тысячу у Бальтрама. У меня больше денег нет.";
			link.l1 = "Нет, ты заплатишь мне, Акил! Меня предупреждали, что ты постоянно пытаешься одурачить тех, с кем работаешь. Со мной это не пройдёт. Немедленно отдавай тысячу или... или я за себя не отвечаю . Я предупредил" + GetSexPhrase("","а") + ".";
			link.l1.go = "6";
		break;
		
		case "6":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 1000);
			dialog.text = "Ну, хорошо, хорошо, вот твоя тысяча. Успокоил" + GetSexPhrase("ся","ась") + "?";
			link.l1 = "Эх, врезать бы тебе пару раз, чтоб не повадно было.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "Надо же как-то выживать. Часто приходится работать с теми, кто не может или не хочет бороться за свои деньги. Сложно не воспользоваться случаем и не попытаться нагреть кого-нибудь на пару тысяч. Но вы мне нравитесь! Умеете добиваться своего. И у меня есть для вас работа. Вернее будет работа.";
			link.l1 = "Только если попытаешься ещё раз меня...";
			link.l1.go = "8";
		break;
		
		case "8":
			dialog.text = "...(перебивая)... Нет, конечно, нет, больше никогда. Заходите в течение недели, и получите отличное задание. Придёте?";
			link.l1 = "Так и быть, буду заходить.";
			link.l1.go = "9";
		break;
		
		case "9":
			dialog.text = "Вот и славно, вот и хорошо! Буду ждать вас.";
			link.l1 = "Счастливо оставаться.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryTimer");
		break;



		
		case "10":
 	                                      PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_HELP.wav");
			dialog.text = "Помогите!!!";
			link.l1 = "";
			link.l1.go = "10_1";
		break;

		case "10_1":
	                                       PlaySound("VOICE\Russian\GOTHIC\RENGARU_01.wav");
			dialog.text = "Чёрт, я сваливаю от сюда!!!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilExit");
		break;



		
		case "11":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_15_02.wav");
			dialog.text = "";
			link.l1 = "Кто эти люди?";
			link.l1.go = "2_11";
		break;

		case "2_11":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_00.wav");
			dialog.text = "Слава Иннасу, я уже думал мне конец!";
			link.l1 = "";
			link.l1.go = "2_12";
		break;

		case "2_12":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_04.wav");
			dialog.text = "Это наёмники с фермы Онара, эти ублюдки, только и знают, что грабить и убивать!";
			link.l1 = "";
			link.l1.go = "2_13";
		break;

		case "2_13":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_05.wav");
			dialog.text = "Я боялся худшего, ты их убил?";
			link.l1 = "Да, бандиты мертвы.";
			link.l1.go = "2_14";
		break;

		case "2_14":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_06.wav");
			dialog.text = "Ах, слава Иннасу до этого не дошло, скажи, что я могу сделать для тебя?";
			link.l1 = "";
			link.l1.go = "2_15";
		break;

		case "2_15":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_GOLD_15_00.wav");
			dialog.text = "";
			link.l1 = "Как насчёт нескольких золотых.";
			link.l1.go = "2_16";
		break;
		
		case "2_16":
			AddMoneyToCharacter(PChar, 5000);
			dialog.text = "Слава богу! Вот держи 5000 песо за помощь. Если бы не ты, меня бы здесь уже не было.";
			link.l1 = "Так это и была та работа, которую ты хотел мне поручить?";
			link.l1.go = "2_17";
		break;
		
		case "2_17":
			dialog.text = "Нет, нет, я хотел попросить доставить груз. Но тут появились эти отморозки и начали требовать мои сбережения. Я знал, что ты придёшь ко мне, и специально тянул время, дожидаясь твоего прихода.";
			link.l1 = "Мог бы хотя бы остаться и помочь мне! Двое против троих куда лучше, чем в одиночку.";
			link.l1.go = "2_18";
		break;
		
		case "2_18":
			dialog.text = "Я совсем не умею держать шпагу в руках, "+ GetFullName(Pchar)+". А ты настоящ" + GetSexPhrase("ий","ая") + " " + GetSexPhrase("боец","фектовальщица") + ", ты убил" + GetSexPhrase("","а") + " Толстяка, и я был уверен, что ты сможешь совладать с теми тремя. Спасибо.";
			link.l1 = "Да не убивал" + GetSexPhrase("","а") + " я Толстяка это тебе Бальтрам наплел, корче ты заплатил мне, я довол" + GetSexPhrase("ен","ьна") + ". А как насчёт работы? Тебе какой-то груз надо было доставить?";
			link.l1.go = "2_19";
		break;
		
		case "2_19":
			dialog.text = "Доставку груза я поручу другому человеку, а вот тебе хочу предложить заказ. Я знаю, кто подослал тех троих и хочу с ним поквитаться. Это мой давний соперник, который не раз пытался мне насолить. Я хочу, чтобы ты его убил" + GetSexPhrase("","а") + ". Соглас" + GetSexPhrase("ен","на") + "?";
			link.l1 = "Сколько заплатишь?";
			link.l1.go = "2_20";
		break;
		
		case "2_20":
			dialog.text = "В сундуке его дома найдёшь 20 000 песо и коллекцию уникального оружия. Он начал собирать её ещё в молодости. Ну что, соглас" + GetSexPhrase("ен","на") + "?";
			link.l1 = "Отлично. Его имя и где он живёт.";
			link.l1.go = "2_21";
		break;
		
		case "2_21":
			dialog.text = "Его имя Лютеро, он живёт в Филипсбурге, в Синт-Маартене, в поселке не долеко от города. Как найдёшь - без разговоров убей.";
			link.l1 = "Хорошо, я понял" + GetSexPhrase("","а") + ".";
			link.l1.go = "2_22";
		break;
		
		case "2_22":
			dialog.text = "Вот и славно, вот и хорошо! Я буду ждать тебя в своём доме. Счастливого пути.";
			link.l1 = "Удачного дня, Акил.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilBackToHouse");
		break;

		case "12":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_15_00.wav");
			dialog.text = "";
			link.l1 = "У тебя какие - то проблемы?";
			link.l1.go = "12_1";
		break;

		case "12_1":
	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_13_01.wav");
			dialog.text = "Ааа, нет, нет, всё в порядке, тебе лучше уйти сейчас.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Angardo");
		break;

		case "12_2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_15_02.wav");
			dialog.text = "";
			link.l1 = "Ты в этом уверен... У меня к тебе куча вопросов...";
			link.l1.go = "12_3";
		break;
		case "12_3":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_13_03.wav");
			dialog.text = "Э, да, да, всё в порядке, я сейчас не могу говорить с тобой...";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Angardo_1");
		break;



 		case "Exit":
                NextDiag.CurrentNode = "Exit1";
		DialogExit();
		break;


	}
}
