// Джек смотритель маяка
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int poison_price;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Lighthouse\" + NPChar.City + "_Lighthouse.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
    int iTest, iTemp;
	string sTemp;
	bool ok;
    iTest = FindColony(NPChar.City); // город
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                                PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_00.wav");
			dialog.text = "Привет сухопутная крыса, похоже сейчас ты на мели?";
			link.l1 = "Ошибаешься, приятель.";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JACKSettlement" && !CheckAttribute(npchar, "quest.JACKSettlement"))
			{
				link.l1 = "";
				link.l1.go = "Jack_meeting";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "Расскажи мне о маяке.";
				link.l1.go = "ChaniSettlementGoJack";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "MayakNoDieenemy" && !CheckAttribute(npchar, "quest.MayakNoDieenemy"))
			{
				link.l1 = "Я сделал это, я уничтожил врага.";
				link.l1.go = "MayakNoDieenemy";
			}

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JackMayak" && !CheckAttribute(npchar, "quest.JackMayak"))
			{
				link.l1 = "";
				link.l1.go = "JackMayak";
			}
		break;

/// ********************** Джек смотритель маяка  ***********************************

		case "Jack_meeting":
			dialog.text = "";
			link.l1 = "Почему ты так решил?";
			link.l1.go = "Jack_meeting_2";
		break;

	case "Jack_meeting_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_01.wav");
            	dialog.text = "У тебя жабры какие-то бледные.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_3";
		break;

	case "Jack_meeting_3":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_02.wav");
            	dialog.text = "Не бери в голову " + GetSexPhrase("парень","девчонка") + ", всё что тебе нужно это крепкий морской бриз.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_4";
		break;

	case "Jack_meeting_4":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Ты часто бываешь в городе?";
        	link.l1.go = "Jack_meeting_5";
		break;

 	case "Jack_meeting_5":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_01.wav");
            	dialog.text = "Я всегда говорю, город настолько хорош, на сколько хорош его порт.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_6";
		break;

 	case "Jack_meeting_6":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_02.wav");
            	dialog.text = "Порт - это ворота в мир, здесь все встречаются и всё начинается здесь!!!";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_7";
		break;

 	case "Jack_meeting_7":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_03.wav");
            	dialog.text = "А когда в порту царит запустение - город неминуемо ждёт та же участь.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_8";
		break;

 	case "Jack_meeting_8":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Расскажи мне об этом порте?";
        	link.l1.go = "Jack_meeting_9";
		break;

 	case "Jack_meeting_9":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_14_02.wav");
            	dialog.text = "Здесь никого не осталось, кроме празношатающегося сброда, корабли сюда больше не заходят и торговля пришла в упадок, этому порту, похоже, скоро придёт конец.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_10";
		break;

 	case "Jack_meeting_10":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Что ты имеешь ввиду под сбродом?";
        	link.l1.go = "Jack_meeting_11";
		break;

 	case "Jack_meeting_11":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_14_01.wav");
            	dialog.text = "Посмотри на них, это же сборище лодырей большинство из них даже не знает, что такое работа. Они только и делают, что пьют все дни напролёт и относят свои последние гроши в бордель.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_12";
		break;

 	case "Jack_meeting_12":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_14_02.wav");
            	dialog.text = "Говорю тебе, держись от них подальше!!!";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_13";
		break;

 	case "Jack_meeting_13":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Так почему ты не уедешь отсюда?";
        	link.l1.go = "Jack_meeting_14";
		break;

 	case "Jack_meeting_14":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_01.wav");
            	dialog.text = "Сегодня никто не возьмёт на корабль старого морского волка вроде меня.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_15";
		break;

 	case "Jack_meeting_15":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_02.wav");
            	dialog.text = "Большинство пологают, что старый Джек ни на что не годен, и что его старые кости разъедает подагра.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_16";
		break;

 	case "Jack_meeting_16":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_15_03.wav");
            	dialog.text = "";
        	link.l1 = "И, они правы?";
        	link.l1.go = "Jack_meeting_17";
		break;

 	case "Jack_meeting_17":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_04.wav");
            	dialog.text = "ВЗДОР, как только я опять почувствую под своими ногами палубу я дам фору любому из этих нахальных юнцов!!!";
        	link.l1 = "Ты ничего подозрительного не заметил в день убийства двух женщин из борделя?";
        	link.l1.go = "Jack_meeting_18";
		break;

 	case "Jack_meeting_18":
            	dialog.text = "Я тебе скажу, что на другой стороне острова есть маяк.";
        	link.l1 = "Маяк? И причём тут маяк?";
        	link.l1.go = "Jack_meeting_19";
		break;

 	case "Jack_meeting_19":
            	dialog.text = "Не перебивай, мой маяк, но проход туда находится под завалом и этот завал я расчищал делая проход к маяку, а это сброд - думали, что я краду ихнее пойло.";
        	link.l1 = "Хорошо, а ты там, когда расчищал проход, ничего подозрительного не заметил.";
        	link.l1.go = "Jack_meeting_20";
		break;

 	case "Jack_meeting_20":
            	dialog.text = "Нет, ничего, но я почувствовал чужой взгляд, аж до мурашек, обернулся никого не увидел, подумал это от переутомления, а на следущий день узнал о убийстве этих бедняжек!!!";
        	link.l1 = "В какое время ты почувствовал взгляд?";
        	link.l1.go = "Jack_meeting_21";
		break;

 	case "Jack_meeting_21":
            	dialog.text = "Ну, это было около двенадцати ночи.";
        	link.l1 = "Спасибо за рассказ, мне пора.";
        	link.l1.go = "exit_1";
		break;

		case "Exit_1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.JACKSettlement = "true";
		pchar.questTemp.JACKSettlement = sti(pchar.questTemp.JACKSettlement)+1;
		if (sti(pchar.questTemp.JACKSettlement) == 2) 
		{
		AddDialogExitQuestFunction("JACK_SettlementOver");
		}
		else
		{
		AddDialogExitQuestFunction("JACK_Settlement_0");
		}
		break;


 	case "ChaniSettlementGoJack":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_03.wav");
            	dialog.text = "В этом нет ничего сложного совсем, но этот старый маяк стал мне родным домом.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_1";
		break;

 	case "ChaniSettlementGoJack_1":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_04.wav");
            	dialog.text = "Но я так давно не был в нём.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_2";
		break;

 	case "ChaniSettlementGoJack_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_06.wav");
            	dialog.text = "С тех пор как эти подонки захватили мой маяк, я не осмеливаюсь подходить ближе чем на двадцать футов, это очень плохие люди.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_3";
		break;

 	case "ChaniSettlementGoJack_3":
            	dialog.text = "";
        	link.l1 = "Похоже на твоём маяке не люди а нежить, и тебе повезло, если бы ты задержался ещё немного при раскопках в подвале, мы бы с тобой сейчас не разговаривали. Я хочу тебя предупредить, что бы ты держался подальше от погреба, до тех пор пока мы не очистим твой маяк от этой нечести.";
        	link.l1.go = "ChaniSettlementGoJack_4";
		break;

 	case "ChaniSettlementGoJack_4":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_00.wav");
            	dialog.text = "Надеюсь, ты знаешь, что делаешь приятель?";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_5";
		break;

 	case "ChaniSettlementGoJack_5":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_15_01.wav");
            	dialog.text = "";
        	link.l1 = "На это не уйдёт много времени.";
        	link.l1.go = "ChaniSettlementGoJack_6";
		break;

 	case "ChaniSettlementGoJack_6":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_02.wav");
            	dialog.text = "Будь осторожен и возвращайся назад целым и невредимым!";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_7";
		break;

 	case "ChaniSettlementGoJack_7":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_04.wav");
            	dialog.text = "Если на нас опять обрушится этот ад я уведу корабль отсюда, с тобой или без тебя, ты слышал!";
        	link.l1 = "";
        	link.l1.go = "exit_2";
		break;

 	case "Exit_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_15_05.wav");
	DialogExit();
	NextDiag.CurrentNode = NextDiag.TempNode;
	npchar.quest.ChaniSettlementGoTorus = "true";
	pchar.questTemp.ChaniSettlementGoTorus = sti(pchar.questTemp.ChaniSettlementGoTorus)+1;
	if (sti(pchar.questTemp.ChaniSettlementGoTorus) == 2) 
	{
	AddDialogExitQuestFunction("PRESENT");
	}
	break;


 	case "MayakNoDieenemy":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_UNDEADDRAGONDEAD_15_00.wav");
            	dialog.text = "";
        	link.l1 = "Я сделал это, я уничтожил врага.";
        	link.l1.go = "MayakNoDieenemy_1";
		break;

 	case "MayakNoDieenemy_1":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_BANDITENWEG_14_01.wav");
            	dialog.text = "Это правда! Наконец - то я смогу опять вернуться к своей работе.";
        	link.l1 = "";
        	link.l1.go = "MayakNoDieenemy_2";
		break;

 	case "MayakNoDieenemy_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_BANDITENWEG_14_02.wav");
            	dialog.text = "Пойдём со мной к маяку, оттуда ты сможешь насладиться потрясающим видом на море.";
        	link.l1 = "";
        	link.l1.go = "MayakNoDieenemy_3";
		break;

 	case "MayakNoDieenemy_3":
	PlaySound("VOICE\Russian\GOTHIC\GG\GG_6.wav");
            	dialog.text = "";
        	link.l1 = "Хорошо...";
        	link.l1.go = "exit_3";
		break;

		case "Exit_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.MayakNoDieenemy = "true";
	                   LAi_SetPlayerType(Pchar);
                                      pchar.GenQuest.CantRun = true;//запрет бега
	                   AddDialogExitQuestFunction("MayakNoDieenemy_1");
		break;


	case "JackMayak":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_LIGHTHOUSEFREE_14_01.wav");
            	dialog.text = "Спасибо, поднимись по лестнице на верх, от туда открывается такой потрясающий вид. Чувствуй себя здесь как дома.";
        	link.l1 = "Хорошо.";
        	link.l1.go = "Exit_JackMayak";
		break;

		case "Exit_JackMayak":
		npchar.quest.JackMayak = "true";
	                   PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_02.wav");
		ChangeCharacterComplexReputation(pchar, "nobility", 10);
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                   AddDialogExitQuestFunction("Jack_Golighthouse_6");
		break;


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;



	}
}


