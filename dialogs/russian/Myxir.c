// Маг воды Миксер
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
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                  dialog.text = "Мне в руки попадалось множество бессмысленных манускриптов?";
        	                  link.l1 = "Это очень интересно!"; 
        	                  link.l1.go = "Myxir_1";		
		break;

		case "Myxir_1":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_TALKEDTOGHOST_12_02.wav");
            	                  dialog.text = "Невероятно, меня всё больше и больше восхищают эти зодчие?";
        	                  link.l1 = "..."; 
	                  link.l1.go = "exit";	
		
		if(CheckAttribute(pchar, "questTemp.GothicMonbar") && pchar.questTemp.GothicMonbar == "MonbarLineMyxir" && !CheckAttribute(npchar, "quest.MonbarLineMyxir"))
                                   {
                                    dialog.text = "Кто вы!";
            	                  link.l1 = "Я владелец этого дома.";
                                    link.l1.go = "MonbarLineMyxir";
       	                  }

		if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "MyxirTakeCoin" && !CheckAttribute(npchar, "quest.MyxirTakeCoin"))
                                   {
                                    dialog.text = "...";
            	                  link.l1 = "Я розыскиваю месье Миксера.";
                                    link.l1.go = "MyxirTakeCoin";
       	                  }

		if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "Myxir_architects_table" && !CheckAttribute(npchar, "quest.Myxir_architects_table"))
                                   {
                                    dialog.text = "Невероятно, меня всё больше и больше восхищают эти зодчие?";
            	                  link.l1 = "Мне удалось найти древнюю табличку Зодчих, вот посмотри.";
                                    link.l1.go = "Myxir_architects_table";
       	                  }
		if(CheckAttribute(pchar, "questTemp.APSH") && pchar.questTemp.APSH == "APSH_Myxir" && !CheckAttribute(npchar, "quest.architects_table_7"))
                                   {
                                    dialog.text = "Невероятно, меня всё больше и больше восхищают эти зодчие?";
            	                  link.l1 = "У меня кое, что есть для тебя, вот посмотри.";
                                       link.l1.go = "APSH_Myxir_table";
       	                  }
		if(CheckAttribute(pchar, "questTemp.Quarhodron") && pchar.questTemp.Quarhodron == "Quarhodron_Myxir" && !CheckAttribute(npchar, "quest.architects_table_Quarhodron"))
                                   {
                                       dialog.text = "...";
            	                  link.l1 = "Есть новые находки!";
                                       link.l1.go = "Myxir_Quarhodron";
       	                  }

		break;
		
		case "APSH_Myxir_table":
            	dialog.text = "Хорошо, давай посмотрим.";
        	 link.l1 = "...";
        	 link.l1.go = "APSH_Myxir_table_1";
                      break;

		case "APSH_Myxir_table_1":
		RemoveItems(PChar, "architects_table_7", 1);
		PlaySound("interface\important_item.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                     npchar.quest.architects_table_7 = "true";
						 DoQuestFunctionDelay("GothicAPSH_architects", 0.01);
                                          //DoQuestFunctionDelay("GothicAPSH_architects", 1.0);
		break;

                                       case "APSH_Myxir_table_2":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_HALLO_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Всё в порядке!";
        	                   link.l1.go = "APSH_Myxir_table_3";
	                   break;

	                  case "APSH_Myxir_table_3":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_10.wav");
            	                   dialog.text = "Здесь написано, как тот кто верит в Аддоноса - может вызвать духа.";
        	                   link.l1 = "Вызвать духа! Как интересно, могу ли я попробовать? Мне как раз нужно найти одного типа давно умершего.";
        	                   link.l1.go = "APSH_Myxir_table_4";
	                   break;

		 case "APSH_Myxir_table_4":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_11.wav");
            	                       dialog.text = "Да.";
        	                       link.l1 = "Ты думаешь это сработает!";
        	                       link.l1.go = "APSH_Myxir_table_5";
		  break;

		 case "APSH_Myxir_table_5":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                      dialog.text = "Мне в руки попадалось множество бессмысленных манускриптов?";
        	                       link.l1 = "...";
        	                       link.l1.go = "APSH_Myxir_table_6";
		   break;

		 case "APSH_Myxir_table_6":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_13.wav");
            	                       dialog.text = "Например, записи Ибериона предводителя братства Спящего.";
        	                       link.l1 = "...";
        	                       link.l1.go = "APSH_Myxir_table_7";
		  break;

		 case "APSH_Myxir_table_7":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_14.wav");
            	                      dialog.text = "Но автору этих записей - я верю.";
        	                      link.l1 = "...";
        	                      link.l1.go = "APSH_Myxir_table_8";
		 break;

		 case "APSH_Myxir_table_8":
	                     PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_15_00.wav");
            	                     dialog.text = "...";
        	                     link.l1 = "И что же мне нужно сделать, что бы вызвать этого духа!";
        	                     link.l1.go = "APSH_Myxir_table_9";
		 break;

		 case "APSH_Myxir_table_9":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_02.wav");
            	                      dialog.text = "Духа вызвать можно при помощи заклинания стражи мертвых, вот я записал его.";
        	                     link.l1 = "Отлично.";
        	                     link.l1.go = "APSH_Myxir_table_10";
	                    break;

		 case "APSH_Myxir_table_10":
		 TakeNItems(pchar, "APSHMyxirNotice", 1);
		 PlaySound("interface\important_item.wav");
		 Log_Info("Вы получили заклинания стражи мертвых");
            	                      dialog.text = "Это всё, так же тебе необходимо выбрать место для вызова духа.";
        	                      link.l1 = "Место мне известно. Что ж попробую, вызвать духа Чарли Вейна.";
        	                      link.l1.go = "APSH_Myxir_table_11";
		 break;

	case "APSH_Myxir_table_11":
	AddQuestRecord("APSH", "10");
	NextDiag.CurrentNode = NextDiag.TempNode;
	DialogExit();
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.location = "Shore127";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.locator = "reload2";
	PChar.quest.GothicApostatesAPSH_8.function = "APSH_Iroquois";
	break;
	case "Myxir_Quarhodron":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "Есть новые находки!";
        	                      link.l1.go = "Myxir_Quarhodron_1";
		 break;

		 case "Myxir_Quarhodron_1":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_01.wav");
            	                      dialog.text = "Зодчие просто поражают меня.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_2";
		 break;

		 case "Myxir_Quarhodron_2":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_02.wav");
            	                      dialog.text = "Жаль, что они все мертвы как и их язык.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_3";
		 break;

		 case "Myxir_Quarhodron_3":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_03.wav");
            	                      dialog.text = "Даже их могущественные ритуалы и духи предков не смогли спасти их.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_4";
		 break;

		 case "Myxir_Quarhodron_4":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_04.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "Духи предков!";
        	                      link.l1.go = "Myxir_Quarhodron_5";
		 break;

		 case "Myxir_Quarhodron_5":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_05.wav");
            	                      dialog.text = "Зодчие жили в тесных связях с миром духов.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_6";
		 break;

		 case "Myxir_Quarhodron_6":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_06.wav");
            	                      dialog.text = "Если я правильно понял они верили, что их предки поддерживают с ними постоянный контакт.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_7";
		 break;

		 case "Myxir_Quarhodron_7":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_07.wav");
            	                      dialog.text = "Они регулярно проводили ритуалы призывающие духов, духи давали им советы и помогали достичь просвещения.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_8";
		 break;

		 case "Myxir_Quarhodron_8":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "Та нежить, что мне доводилось встречать была не очень - то разговорчивой.";
        	                      link.l1.go = "Myxir_Quarhodron_9";
		 break;

		 case "Myxir_Quarhodron_9":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_01.wav");
            	                      dialog.text = "Но Зодчие призывали не злобных бездушных созданий таких как зомби или скелеты.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_10";
		 break;

		 case "Myxir_Quarhodron_10":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_02.wav");
            	                      dialog.text = "Им удавалось вызывать духов великих воинов, жрецов и правителей.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_11";
		 break;

		 case "Myxir_Quarhodron_11":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_03.wav");
            	                      dialog.text = "Я не сомневаюсь, что они на самом деле существовали.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_12";
		 break;

		 case "Myxir_Quarhodron_12":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "Как работали эти ритуалы?";
        	                      link.l1.go = "Myxir_Quarhodron_13";
		 break;

		 case "Myxir_Quarhodron_13":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_01.wav");
            	                      dialog.text = "Стражам мёртвых были известны особые заклинания которые использовались для умиротворения духов.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_14";
		 break;

		 case "Myxir_Quarhodron_14":
		RemoveItems(PChar, "architects_table_8", 1);
		PlaySound("interface\important_item.wav");
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_01.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "Ворон проник в храм и закрыл его двери из внутри.";
        	                      link.l1.go = "Myxir_Quarhodron_15";
		 break;

		 case "Myxir_Quarhodron_15":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_03.wav");
            	                      dialog.text = "О, Аддонос...";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_16";
		 break;

		 case "Myxir_Quarhodron_16":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_04.wav");
            	                      dialog.text = "Должно быть, что бы узнать как открыть ворота он призвал Верховного жреца Кардимона.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_17";
		 break;

		 case "Myxir_Quarhodron_17":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_05.wav");
            	                      dialog.text = "Судя по записям, его гробница была в пещерах под крепостью.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_18";
		 break;

		 case "Myxir_Quarhodron_18":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_06.wav");
            	                      dialog.text = "Ты должен поступить так же.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_19";
		 break;

		 case "Myxir_Quarhodron_19":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_07.wav");
            	                      dialog.text = "Но Кардимона тебе уже вызвать не удастся.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_20";
		 break;

		 case "Myxir_Quarhodron_20":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_08.wav");
            	                      dialog.text = "На западе долины (острова Провиденсия) находится гробница Куарходрона предводителя воинов.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_21";
		 break;

		 case "Myxir_Quarhodron_21":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_09.wav");
            	                      dialog.text = "Ты должен отыскать её и пробудить Куарходрона.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_22";
		 break;

		 case "Myxir_Quarhodron_22":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTPERM_12_01.wav");
            	                      dialog.text = "Найди его гробницу и прочитай заклинание стражи мёртвых.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_23";
		 break;

		 case "Myxir_Quarhodron_23":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTPERM_12_02.wav");
            	                      dialog.text = "Я записал слова, ты должен просто прочитать их в слух.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_24";
		 break;

		 case "Myxir_Quarhodron_24":
		 TakeNItems(pchar, "QuarhodronMyxirNotice", 1);
		 PlaySound("interface\important_item.wav");
		 Log_Info("Вы получили заклинания стражи мертвых");
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_03.wav");
            	                      dialog.text = "Это всё теперь тебе нужно отыскать гробницу.";
        	                      link.l1 = "Понятно!";
        	                      link.l1.go = "Myxir_Quarhodron_25";
		 break;

		case "Myxir_Quarhodron_25":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                     npchar.quest.architects_table_Quarhodron = "true";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_Quarhodron_Myxir_1");
		break;


		//--> ----------------------------------- Миксер знакомство ------------------------------------------

		 case "MyxirTakeCoin":
            	                   dialog.text = "Я слушаю.";
        	                   link.l1 = "У меня есть старинная монета, похожая на золотую, особой ценности эта монета не представляет, но вокруг неё происходят загадочные вещи, связанные с духами давно умерших и я подозреваю, что за этим может стоять демон, который убивает людей, тем самым набирает силу и ему очень нужна эта монета. Мне сказали, что вы мне можете помочь.";
        	                   link.l1.go = "MyxirTakeCoin_1";
		 break;

		case "MyxirTakeCoin_1":
            	                  dialog.text = "И чем же я могу помочь?";
        	                  link.l1 = "Мне необходимо знать где скрывается демон, я хочу с ним встретится.";
        	                  link.l1.go = "MyxirTakeCoin_2";
		break;

		case "MyxirTakeCoin_2":
            	                  dialog.text = "Значит благородные намериния, спасти мир?";
        	                  link.l1 = "Да.";
        	                  link.l1.go = "MyxirTakeCoin_3";
		break;

		case "MyxirTakeCoin_3":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "А чем ты здесь занимаешься.";
        	                  link.l1.go = "MyxirTakeCoin_4";
		break;

		case "MyxirTakeCoin_4":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_01.wav");
            	                  dialog.text = "Я изучаю язык Зодчих.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_5";
		break;

		case "MyxirTakeCoin_5":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_02.wav");
            	                  dialog.text = "Язык это ключ к тому, что бы понять этих людей.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_6";
		break;

		case "MyxirTakeCoin_6":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_03.wav");
            	                  dialog.text = "Каждый из нас должен выучить этот язык, иначе экспедиция закончится даже неначавшись.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_7";
		break;

		case "MyxirTakeCoin_7":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_04.wav");
            	                  dialog.text = "Зодчие выбивали свои тексты на каменных табличках к сожалению многие из них были разбиты или украдены.";
        	                  link.l1 = "И, что эта за экспедиция!";
        	                  link.l1.go = "MyxirTakeCoin_8";
		break;

		case "MyxirTakeCoin_8":
            	                  dialog.text = "Я не могу тебе этого сказать.";
        	                  link.l1 = "Хорошо, тогда,";
        	                  link.l1.go = "MyxirTakeCoin_9";
		break;

		case "MyxirTakeCoin_9":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "Как работали эти ритуалы.";
        	                  link.l1.go = "MyxirTakeCoin_10";
		break;

		case "MyxirTakeCoin_10":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_01.wav");
            	                  dialog.text = "Стражам мертвых были известны особые заклянания которые использовались для умиротворения духов.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_11";
		break;

		case "MyxirTakeCoin_11":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_02.wav");
            	                  dialog.text = "Жаль, что все они мертвы как и их язык.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_12";
		break;

		case "MyxirTakeCoin_12":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_03.wav");
            	                  dialog.text = "Даже их могущественые ритуалы и духи предков не могли спасти их.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_13";
		break;

		case "MyxirTakeCoin_13":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_04.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "Духи предков?";
        	                  link.l1.go = "MyxirTakeCoin_14";
		break;

		case "MyxirTakeCoin_14":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_05.wav");
            	                  dialog.text = "Зодчие жили в тесных связях с миром духов.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_15";
		break;

		case "MyxirTakeCoin_15":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_06.wav");
            	                  dialog.text = "Если я правильно понял они верили, что их предки поддерживают постоянный контакт.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_16";
		break;

		case "MyxirTakeCoin_16":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_07.wav");
            	                  dialog.text = "Они регулярно проводили ритуалы призывающие духов, духи давали советы и помогали достичь просвящения.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_17";
		break;

		case "MyxirTakeCoin_17":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_02.wav");
            	                  dialog.text = "Впрочем описания которые я здесь нахожу большой части мало понятной, очень редко мне удаётся найти чёткий ответ на интерисующий меня вопрос.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_18";
		break;

		case "MyxirTakeCoin_18":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "Та нежить, что мне доводилось встречать была не очень - то разговорчивой.";
        	                  link.l1.go = "MyxirTakeCoin_19";
		break;

		case "MyxirTakeCoin_19":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_01.wav");
            	                  dialog.text = "Но Зодчие призывали незлобных, бездушных созданий таких как зомби или скелеты.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_20";
		break;

		case "MyxirTakeCoin_20":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_02.wav");
            	                  dialog.text = "Им удавалось вызывать духов, великих воинов, жрецов и правителей.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_21";
		break;

		case "MyxirTakeCoin_21":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_03.wav");
            	                  dialog.text = "Я не сомневаюсь, что они на самом деле существовали.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_22";
		break;

		case "MyxirTakeCoin_22":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "Что же можно узнать из этих табличек.";
        	                  link.l1.go = "MyxirTakeCoin_23";
		break;

		case "MyxirTakeCoin_23":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_12_01.wav");
            	                  dialog.text = "На них записаны знания древнего народа.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_24";
		break;

		case "MyxirTakeCoin_24":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_12_03.wav");
            	                  dialog.text = "Для тех кто способен их прочесть они являются настоящим сокровищем.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_25";
		break;

		case "MyxirTakeCoin_25":
            	                  dialog.text = "Но к сожалению у меня недостаточно фрагментов для полной картины, я располагаю четырьмя табличками, должно быть пять.";
        	                  link.l1 = "Хорошо, если я найду такую табличку, ты сможешь её прочитать, для того что бы вызвать этот дух, ну или хотя бы узнать место обитания этого существа и какая связь между духами и монетами.";
        	                  link.l1.go = "MyxirTakeCoin_26";
		break;

		case "MyxirTakeCoin_26":
            	                  dialog.text = "Думаю, да, Зодчие могли это делать, они не отличались от нас. Покажи мне эту монету.";
        	                  link.l1 = "Вот, смотри.";
        	                  link.l1.go = "MyxirTakeCoin_27";
		break;

		case "MyxirTakeCoin_27":
		RemoveItems(PChar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("Вы отдали монету");
            	                  dialog.text = "Знакомый сплав, это не золото. Гравюра на монете отображает, нет я могу ошибиться, мне нужно время кое - что проверить.";
        	                  link.l1 = "Хорошо, тогда я займусь поисками таблички Зодчих, а ты раскопай информацию по монете.";
        	                  link.l1.go = "MyxirTakeCoin_28";
		break;

		case "MyxirTakeCoin_28":
		TakeNItems(pchar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("Вы получили старинную монету");
            	                  dialog.text = "Договорились. Те таблички которые у меня есть, были найдены возле древних храмов инков.";
        	                  link.l1 = "Спасибо за подсказку. Увидимся, я не прощаюсь.";
        	                  link.l1.go = "MyxirTakeCoin_29";
		break;

		case "MyxirTakeCoin_29":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.MyxirTakeCoin = "true";
                                    DoQuestFunctionDelay("GothicObsession_MyxirTakeCoin", 2.0);
		break;

		//--> ----------------------------------- Миксер знакомство ------------------------------------------

		 case "Myxir_architects_table":
            	                   dialog.text = "Отлично, дай мне её, я постараюсь прочесть, возможно нам повезёт.";
        	                   link.l1 = "Как скажешь.";
        	                   link.l1.go = "Myxir_architects_table_1";
		 break;

		case "Myxir_architects_table_1":
	                 PlaySound("VOICE\Russian\GOTHIC\GG\GG_60.wav");
		RemoveItems(PChar, "architects_table", 1);
		PlaySound("interface\important_item.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.Myxir_architects_table = "true";
                                    DoQuestFunctionDelay("GothicObsession_table_Myxir", 1.0);
		break;

		 case "Myxir_architects_table_2":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_HALLO_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Всё в порядке!";
        	                   link.l1.go = "Myxir_architects_table_3";
		 break;

		 case "Myxir_architects_table_3":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_10.wav");
            	                   dialog.text = "Здесь написано, как тот кто верит в Аданаса - может вызвать духа.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_4";
		 break;

		 case "Myxir_architects_table_4":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_11.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Ты думаешь это сработает!";
        	                   link.l1.go = "Myxir_architects_table_5";
		 break;

		 case "Myxir_architects_table_5":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                   dialog.text = "Мне в руки попадалось множество бессмысленных манускриптов?";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_6";
		 break;

		 case "Myxir_architects_table_6":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_13.wav");
            	                   dialog.text = "Например, записи Ибириона предводителя братства Спящего.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_7";
		 break;

		 case "Myxir_architects_table_7":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_14.wav");
            	                   dialog.text = "Но автору этих записей - я верю.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_8";
		 break;

		 case "Myxir_architects_table_8":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Братсво Спящего распростроняли не одну лишь ложь, Спящий на самом деле существовал.";
        	                   link.l1.go = "Myxir_architects_table_9";
		 break;

		 case "Myxir_architects_table_9":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_01.wav");
            	                   dialog.text = "Не то о чём они говорили застовляло сомниваться в их правдивости, а те слова которые они использовали.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_10";
		 break;

		 case "Myxir_architects_table_10":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_02.wav");
            	                   dialog.text = "Речи членов братства были запутаны и не понятны, их разум был затуманен болотной травой которую они курили без остановки.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_11";
		 break;

		 case "Myxir_architects_table_11":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_03.wav");
            	                   dialog.text = "А текст на этой табличке написан серьёзным и разумным человеком, это убеждает меня в правдивости его слов.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_12";
		 break;

		 case "Myxir_architects_table_12":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "И что же мне нужно сделать, что бы вызвать этого духа!";
        	                   link.l1.go = "Myxir_architects_table_13";
		 break;

		 case "Myxir_architects_table_13":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_02.wav");
            	                   dialog.text = "Духа вызвать можно при помощи заклинания стражи мертвых, вот я записал его.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_14";
		 break;

		 case "Myxir_architects_table_14":
		TakeNItems(pchar, "MyxirNotice", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("Вы получили заклинания стражи мертвых");
            	                   dialog.text = "Это всё.";
        	                   link.l1 = "Подожди минутку, что насчет монет!";
        	                   link.l1.go = "Myxir_architects_table_15";
		 break;

		 case "Myxir_architects_table_15":
            	                   dialog.text = "Как монета, она не имеет ценности, ценность имеет сплав, из такого же сплава когда - то в древности делали украшения, больше я ничего не смог выяснить по этому вопросу.";
        	                   link.l1 = "Ну, спасибо и на этом!";
        	                   link.l1.go = "Myxir_architects_table_16";
		 break;

		case "Myxir_architects_table_16":
	                  AddQuestRecord("Obsession", "7");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.Myxir_architects_table = "true";
		break;










		
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