// Куарходрон предводитель армии Янкендара
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, n, iTemp;
	string sTemp;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	bool ok;
                        int iTest;
                        ref rColony;
                        string sFrom_sea = "";
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // индекс в конце
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_00.wav");
		dialog.text = "Почему ты нарушаешь мой покой - страж.";
		link.l1 = "...";
		link.l1.go = "Quarhodron1";			
		break;

		case "Quarhodron1":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_02.wav");
		dialog.text = "Ленглонтании асири...";
		link.l1 = "...";
		link.l1.go = "Quarhodron2";			
		break;

		case "Quarhodron2":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_03.wav");
		dialog.text = "Ленглонтании...";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;





		case "Quarhodron":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_02.wav");
		dialog.text = "Ленглонтании асири...";
		link.l1 = "...";
		link.l1.go = "Quarhodron_2";			
		break;

		case "Quarhodron_2":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_03.wav");
		dialog.text = "Ленглонтании...";
		link.l1 = "...";
		link.l1.go = "Quarhodron_3";			
		break;

		case "Quarhodron_3":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_TEMPEL_15_00.wav");
		dialog.text = "...";
		link.l1 = "Расскажи мне как попасть в храм Аддоноса.";
		link.l1.go = "Quarhodron_4";
		link.l2 = "Кто ты!";
		link.l2.go = "Quarhodron_04";	
		link.l3 = "Послушай меня в храм Аддоноса смог попасть очень злой человек.";
		link.l3.go = "Quarhodron_004";				
		break;

		case "Quarhodron_004":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Послушай меня в храм Аддоноса смог попасть очень злой человек.";
		link.l1.go = "Quarhodron_005";			
		break;

		case "Quarhodron_005":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_03.wav");
		dialog.text = "Ленглонтании...";
		link.l1 = "...";
		link.l1.go = "Quarhodron_006";			
		break;

		case "Quarhodron_006":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_00.wav");
		dialog.text = "Почему ты нарушаешь мой покой - страж.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_20";			
		break;

		case "Quarhodron_04":
	                     PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_1.wav");
		dialog.text = "...";
		link.l1 = "Кто ты!";
		link.l1.go = "Quarhodron_05";			
		break;

		case "Quarhodron_05":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_11_01.wav");
		dialog.text = "Я, Куарходрон когда - то я был предводителем армии Янкендара.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_06";			
		break;

		case "Quarhodron_06":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_11_02.wav");
		dialog.text = "Ты пробудил меня.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_7";			
		break;

		case "Quarhodron_4":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_TEMPEL_11_01.wav");
		dialog.text = "Храм останется закрытым на веки, так решил совет.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_5";			
		break;

		case "Quarhodron_5":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_SCHWERT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что находится в храме Адданоса!";
		link.l1.go = "Quarhodron_6";			
		break;

		case "Quarhodron_6":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_SCHWERT_11_01.wav");
		dialog.text = "Моя величайшая печаль, моё величайшее разочарование.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_7";			
		break;

		case "Quarhodron_7":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_RAVEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Кто - то с мог проникнуть в храм Аддоноса.";
		link.l1.go = "Quarhodron_8";			
		break;

		case "Quarhodron_8":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_RAVEN_11_01.wav");
		dialog.text = "Вздор, я лично запечатал дверь, войти в храм не возможно.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_9";			
		break;

		case "Quarhodron_9":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_RAVEN_15_02.wav");
		dialog.text = "...";
		link.l1 = "В самом деле!";
		link.l1.go = "Quarhodron_10";			
		break;

		case "Quarhodron_10":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_FRECH_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мудрость древних по истене поразительна...";
		link.l1.go = "Quarhodron_11";			
		break;

		case "Quarhodron_11":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_FRECH_11_01.wav");
		dialog.text = "Человек твоего положения не должен так разговаривать.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_12";			
		break;

		case "Quarhodron_12":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_FRECH_11_02.wav");
		dialog.text = "Я не могу освободиться от впечатления, что ты не тот за кого себя выдаёшь.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_13";			
		break;

		case "Quarhodron_13":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_FRECH_11_03.wav");
		dialog.text = "Если тебе нужна моя помощь ты должен доказать, что ты говоришь мне правду.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_14";			
		break;

		case "Quarhodron_14":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_FRECH_11_04.wav");
		dialog.text = "Ответь на мои вопросы, что бы я мог убедиться, что не выдаю чужаку наши тайны.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_15";			
		break;

		case "Quarhodron_15":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Послушай меня в храм Аддоноса смог попасть очень злой человек.";
		link.l1.go = "Quarhodron_16";			
		break;

		case "Quarhodron_16":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_01.wav");
		dialog.text = "...";
		link.l1 = "Если ты не поможешь мне попасть в храм немедленно, мы можем опаздать и тогда всем нам придёт конец.";
		link.l1.go = "Quarhodron_17";			
		break;

		case "Quarhodron_17":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_11_02.wav");
		dialog.text = "Этого не может быть, во всем Янкендаре лишь мы с верховным жрецом Кардимоном знаем как открыть ворота в храм.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_18";			
		break;

		case "Quarhodron_18":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_03.wav");
		dialog.text = "...";
		link.l1 = "Ну, значит твой приятель Кардимон проболтался.";
		link.l1.go = "Quarhodron_19";			
		break;

		case "Quarhodron_19":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_04.wav");
		dialog.text = "...";
		link.l1 = "Ворота были открыты, я видел это собственными глазами.";
		link.l1.go = "Quarhodron_20";			
		break;

		case "Quarhodron_20":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_00.wav");
		dialog.text = "Я тебе не верю.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_21";			
		break;

		case "Quarhodron_21":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_03.wav");
		dialog.text = "Если ты действительно страж мёртвых ты сможешь ответить на все мои вопросы.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_quest";			
		break;

		case "Quarhodron_quest":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Спрашивай...";
		link.l1.go = "Quarhodronquest";			
		break;

		case "Quarhodronquest":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_11_03.wav");
		dialog.text = "Какой касте ты пренадлежишь.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest_P";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest_N";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest_N";					
		break;

		case "Quarhodronquest_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_04.wav");
		dialog.text = "Кто закрыл портал, что бы не пропустить зло в наш мир.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest1";
		break;

		case "Quarhodronquest_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_04.wav");
		dialog.text = "Кто закрыл портал, что бы не пропустить зло в наш мир.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest1";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest1":
		dialog.text = "Кто закрыл портал, что бы не пропустить зло в наш мир.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest1_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest1_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest1_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest1_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest1_N";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest1_P";					
		break;

		case "Quarhodronquest1_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_05.wav");
		dialog.text = "Кто облехчает страдания раненым и ухаживает за больными.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest2";
		break;

		case "Quarhodronquest1_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_05.wav");
		dialog.text = "Кто облехчает страдания раненым и ухаживает за больными.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest2";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest2":
		dialog.text = "Кто облехчает страдания раненым и ухаживает за больными.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest2_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest2_P";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest2_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest2_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest2_N";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest2_N";					
		break;

		case "Quarhodronquest2_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_06.wav");
		dialog.text = "За кем остаётся последнее слово в совете пяти.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest3";
		break;

		case "Quarhodronquest2_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_06.wav");
		dialog.text = "За кем остаётся последнее слово в совете пяти.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest3";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest3":
		dialog.text = "За кем остаётся последнее слово в совете пяти.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest3_P";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest3_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest3_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest3_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest3_N";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest3_N";					
		break;

		case "Quarhodronquest3_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_07.wav");
		dialog.text = "Кто привёл в наш мир зло.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest4";
		break;

		case "Quarhodronquest3_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_07.wav");
		dialog.text = "Кто привёл в наш мир зло.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest4";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest4":
		dialog.text = "Кто привёл в наш мир зло.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest4_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest4_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest4_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest4_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest4_P";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest4_N";					
		break;

		case "Quarhodronquest4_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_08.wav");
		dialog.text = "Кто может отдать мне прямой приказ.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest5";
		break;

		case "Quarhodronquest4_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_08.wav");
		dialog.text = "Кто может отдать мне прямой приказ.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest5";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest5":
		dialog.text = "Кто может отдать мне прямой приказ.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest5_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest5_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest5_P";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest5_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest5_N";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest5_N";					
		break;

		case "Quarhodronquest5_P":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_09.wav");
		dialog.text = "Кто защищает людей Янкендара от нападения врагов.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest6";
		break;

		case "Quarhodronquest5_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_09.wav");
		dialog.text = "Кто защищает людей Янкендара от нападения врагов.";
		link.l1 = "";
		link.l1.go = "Quarhodronquest6";
		pchar.questTemp.Quarhodron.QuestionquestFail = "true";
		break;

		case "Quarhodronquest6":
		dialog.text = "Кто защищает людей Янкендара от нападения врагов.";
		link.l1 = "Учёные.";
		link.l1.go = "Quarhodronquest6_N";
		link.l2 = "Целители.";
		link.l2.go = "Quarhodronquest6_N";
		link.l3 = "Жрецы.";
		link.l3.go = "Quarhodronquest6_N";
		link.l4 = "Стражи мёртвых.";
		link.l4.go = "Quarhodronquest6_N";
		link.l5 = "Воины.";
		link.l5.go = "Quarhodronquest6_P";
		link.l6 = "Я не знаю.";
		link.l6.go = "Quarhodronquest6_N";					
		break;

		case "Quarhodronquest6_P":
		if (CheckAttribute(pchar, "questTemp.Quarhodron.QuarhodronquestFail"))
		{
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_TESTFAILED_11_00.wav");
		dialog.text = "Не правильные ответы выдают твои злые намерения.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_N1";			
		}
		else
		{
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_NOPLAN_11_01.wav");
		dialog.text = "Хорошо, я верю тебе и поэтому помогу.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_P1";
		}			
		break;

		case "Quarhodronquest6_N":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_TESTFAILED_11_00.wav");
		dialog.text = "Не правильные ответы выдают твои злые намерения.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_N1";			
		break;

		case "Quarhodron_N1":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_TESTFAILED_11_01.wav");
		dialog.text = "Я не стану тебе помогать.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_N2";			
		break;

		case "Quarhodron_N2":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_FRAGEN_CHOICES_11_01.wav");
		dialog.text = "Возвращайся когда решишь сказать мне правду.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_exit";
		break;

		case "Quarhodron_Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("Gothic_CryptQuarhodron_4");
		break;

		case "Quarhodron_P1":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_01.wav");
		dialog.text = "Говори, что тебе нужно.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_25";			
		break;

		case "Quarhodron_25":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Послушай меня в храм Аддоноса смог попасть очень злой человек.";
		link.l1.go = "Quarhodron_26";			
		break;

		case "Quarhodron_26":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_01.wav");
		dialog.text = "...";
		link.l1 = "Если ты не поможешь мне попасть в храм немедленно, мы можем опаздать и тогда всем нам придёт конец.";
		link.l1.go = "Quarhodron_27";			
		break;

		case "Quarhodron_27":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_11_05.wav");
		dialog.text = "По твоему голосу я слышу, что ты говоришь правду, больше я не буду сомневаться в твоих словах.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_28";			
		break;

		case "Quarhodron_28":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_15_06.wav");
		dialog.text = "...";
		link.l1 = "Надеюсь.";
		link.l1.go = "Quarhodron_29";			
		break;

		case "Quarhodron_29":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_11_07.wav");
		dialog.text = "Я дам тебе каменную табличку на которой записаны тайные слова, произнеси их перед запечатанными воротами храма и они распахнуться перед тобой.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_30";			
		break;

		case "Quarhodron_30":
		 TakeNItems(pchar, "architects_table_1", 1);
		 PlaySound("interface\important_item.wav");
		 Log_Info("Вы получили каменную табличку");
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_11_08.wav");
		dialog.text = "Моё время подходит к концу, увы больше я ни чем помочь не смогу.";
		link.l1 = "...";
		link.l1.go = "Quarhodron_31";			
		break;

		case "Quarhodron_31":
	                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_GIBMIRKEY_11_11.wav");
		dialog.text = "Силы покидают меня, прощай, когда - нибудь мы снова встретимся в стране мёртвых.";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuest("Gothic_CryptQuarhodron_5");		                                          RemoveItems(PChar, "QuarhodronMyxirNotice", 1);	
		break;









//К какой касте ты принадлежишь - Стражи мертвых
//Кто защищает людей от нападения - Воины
//Кто может отдать прямой приказ - Жрецы (Священники)
//Кто привел в мир зло - Воины
//В совете пяти последнее слово за кем остается - Ученые
//Кто ухаживает за ранеными - Целители
//Кто закрыл портал, чтобы зло не прошло в мир - Не знаю (Ты этого знать не можешь)

		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Alligator_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Джек, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Alligator_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "Какие приказания?";
            Link.l1 = "Стой здесь!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "Следуй за мной и не отставай!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "Нужно изменить тип боеприпаса для твоего огнестрельного оружия.";
					Link.l3.go = "SetGunBullets";
				}	
			}


		break;

		
		case "SetGunBullets":
			Dialog.Text = "Выбор типа боеприпаса:";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
        case "Boal_Stay":
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
            dialog.Text = "Есть изменить дислокацию!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "Есть изменить дислокацию!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
        break;
	//<-- ----------------------------------- офицерский блок ----------------------------------------
	
	// на Тайясаль
		case "tieyasal":
			dialog.text = "Ты чертовски удачлив, кэп. Я рад, что присоединился к тебе тогда, на Терксе. И проглоти меня акула, если я не поддержу тебя и в этом предприятии!";
			link.l1 = "Спасибо, Джек! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Когда мы будем отправляться?";
			link.l1 = "Немного позже. А пока подготовимся к походу.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21_1");
			npchar.quest.Tieyasal = "teleport";
		break;


		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit1":			
			DialogExit();
		break;



	}
}