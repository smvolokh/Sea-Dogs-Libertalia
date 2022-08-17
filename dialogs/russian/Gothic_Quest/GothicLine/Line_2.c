// диалоговый файл на гот. линейку
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	float locx, locy, locz;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    switch (Dialog.CurrentNode)
    {
        case "First time":
			dialog.text = "Не о чем говорить.";
			link.l1 = "Ладно...";
            link.l1.go = "exit";

//>>>>>>>>>>>>========= Разброс диалогов по персонажам =====================

			if (npchar.id == "AnnaDeLeiva")// квест, донна Анна в спальне
            {
    			dialog.text = "Боже! Что случилось? Вы прибыли от Генерала Ли? Что это был за шум?";
    			link.l1 = "Сударыня, не знаю, печальные это для вас новости или нет, но я был"+ GetSexPhrase("","а") +" вынужден"+ GetSexPhrase("","а") +" убить вашего супруга. У нас нет времени на переживания и обмороки, нужно немедленно бежать! Генерал Ли в Сент-Луи ждет вас.";
    			link.l1.go = "Gothic_1";
            }

			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toHavana")// квест, Инесс
            {
    		             dialog.text = "Посмотри на себя, ты откуда такой взялся - а?";
    			link.l1 = "";
    			link.l1.go = "Gothic_2_1";
            }
			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_SeekHoseBrothers")
            {
    			dialog.text = "Поторопитесь, сеньор"+ GetSexPhrase("","ита") +". Я уверяю вас - жизнь донны Анны висит на волоске...";
    			link.l1 = "Все будет в порядке, уважаемая Инес, не беспокойтесь.";
    			link.l1.go = "exit";
            }
			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork")
            {
    			dialog.text = "Ну что, капитан, какие новости?";
    			link.l1 = "Все в порядке, проблем с родственниками донны Анны более не существует...";
    			link.l1.go = "Gothic_2_4";
            }


            if (npchar.id == "LoranDeGraf")// Лоран де Граф, квест
            {
    			dialog.text = "Судар"+ GetSexPhrase("ь","ыня") +", сейчас не время для разговоров! Идет бой.";
    			link.l1 = "Да-да, я знаю...";
    			link.l1.go = "exit";
            }
			if (pchar.questTemp.GothicLee == "SeekBible_WeWon" && npchar.id == "LoranDeGraf")// Лоран де Граф, квест 
            {
    			dialog.text = "Я в крайней степени благодарен вам за помощь, судар"+ GetSexPhrase("ь","ыня") +". Вы подоспели как нельзя вовремя. Позвольте представиться, меня зовут Лоран де Граф.";
    			link.l1 = "Знаю, я как раз искал"+ GetSexPhrase("","а") +" встречи с вами сначала в Шарлотт-Тауне, затем на Тортуге.";
    			link.l1.go = "Gothic_3_10";
            }
            if (pchar.questTemp.GothicLee == "SeekBible_IHaveMap")
            {
    			dialog.text = "Мне кажется, что наша сделка завершена, судар"+ GetSexPhrase("ь","ыня") +".";
    			link.l1 = "Верно, завершена.";
    			link.l1.go = "exit";
            }
            if (pchar.questTemp.GothicLee == "SeekBible_SeekMoney")
            {
    			dialog.text = "Вы уже нашли деньги, судар"+ GetSexPhrase("ь","ыня") +"?";
                if (sti(pchar.money) >= 235000)
                {
                    link.l1 = "Да, наш"+ GetSexPhrase("ел","ла") +". И готов"+ GetSexPhrase("","а") +" их выложить тебе...";
        			link.l1.go = "Gothic_3_13";
                }
                else
                {
                    link.l1 = "Нет еще, я в поиске...";
        			link.l1.go = "exit";
                }
            }

            if (pchar.questTemp.GothicLee == "Francisco")// квест, базар с Франциско
            {
    			dialog.text = "Вот мы и встретилиь, неизвестный герой древней эпохи?";
    			link.l1 = "Что... Какого черта вам от меня нужно и где ваш дорогой Декстер?";
    			link.l1.go = "Gothic_4_1";
            }

			if (npchar.id == "Gorn" && pchar.questTemp.GothicLee == "RockBras_toSeekPlace")//квест, базар с Горном. 
            {
    			dialog.text = NPCStringReactionRepeat("Вот это да! Кто это осмелился на такое?!", "Ну, давай продолжим наш разговор. Так кто же ты так"+ GetSexPhrase("ой","ая") +", геро"+ GetSexPhrase("й","иня") +" нашего времени?", "Продолжим? Так кто ты так"+ GetSexPhrase("ой","ая") +"?", "Хм, давай закончим наш разговор. Кто ты так"+ GetSexPhrase("ой","ая") +"?", "block", 0, npchar, Dialog.CurrentNode);
    			if (LAi_group_GetTarget(pchar) <= 3)
				{
					link.l1 = HeroStringReactionRepeat("Я осмелил"+ GetSexPhrase("ся","ась") +". Зовут меня "+GetFullName(pchar)+". Я приш"+ GetSexPhrase("ел","ла") +", чтобы вытащить тебя отсюда.", "Давай продолжим... Меня зовут "+GetFullName(pchar)+", я приш"+ GetSexPhrase("ел","ла") +" за тобой.", "Меня зовут "+GetFullName(pchar)+", я приш"+ GetSexPhrase("ел","ла") +" за тобой.", "Давай закончим, не вопрос. Меня зовут "+GetFullName(pchar)+", я приш"+ GetSexPhrase("ел","ла") +" за тобой.", npchar, Dialog.CurrentNode);
    				link.l1.go = "Gothic_5_1";
				}
				else
				{
					link.l1 = "Сейчас не время говорить, надо разделаться со всеми в этом месте!";
    				link.l1.go = "Gothic_5_Late";
				}
				// --> типа опоздал...
				if (GetQuestPastDayParam("questTemp") > 12)
				{
    				dialog.text = "Это ты?..";
    				link.l1 = "Да, и я приш"+ GetSexPhrase("ел","ла") +" за тобой, меня послал Ли...";
    				link.l1.go = "Gothic_5_8";
				}
				else SaveCurrentQuestDateParam("questTemp"); //чтобы не глюкнуло во время боя
				// <-- типа опоздал...
            }
			if (npchar.id == "Gorn" && pchar.questTemp.GothicLee == "empty")//квест , базар с Горном в резиденции Ли. 
            {
    			dialog.text = ""+pchar.name+", я еще не имел возможности поблагодарить тебя.";
    			link.l1 = "Все в порядке, дружище...";
    			link.l1.go = "Gothic_5_5";
            }

			if (npchar.id == "CaptainGay")//квес, базар с кэпом Геем. 
            {
    			dialog.text = "Ты кто так"+ GetSexPhrase("ой","ая") +"?";
    			link.l1 = "Неважно, кто я. Тебе привет от Бартоломью Роджерса. Он очень хочет познакомиться с твоим судовым журналом.";
    			link.l1.go = "Gothic_6_1";
            }			

		break;
//<<<<<<<<<<<<===== Разброс диалогов по персонажам =====================
        case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;


//********************************* Похищение донны Анны. Квест №3 **********************************
 		case "Gothic_1":
			dialog.text = "Хосе мертв... Видит Господь, я этого не хотела... Он нашел письмо, которое я писала ему, и запер меня здесь...";
			link.l1 = "Я знаю, сеньора, догадал"+ GetSexPhrase("ся","ась") +"... Я прошу вас следовать за мной. Будьте внимательны, сударыня...";
			link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_HavanaOut";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1 = "location";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1.location = "Cuba2";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition = "GothicLeeTakeAnna_DelivShip";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

//********************************* Проблемы донны Анны. Квест **********************************
 	              case "Gothic_2_1":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ADD_17_19.wav");
		dialog.text = " Сеньор"+ GetSexPhrase("","ита") +", кто вы? И что вам нужно в моем доме?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_001";
		break;

 		case "Gothic_2_001":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_4.wav");
		dialog.text = "";
		link.l1 = "Я спустился с гор и прибыл"+ GetSexPhrase("","а") +" сюда по поручению донны Анны, вашей подруги. Насколько мне известно, вы известили ее о некой опасности...";
    		link.l1.go = "Gothic_2_002";
		break;

 	              case "Gothic_2_002":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ADD_17_22.wav");
		dialog.text = "Не говори мне я всё знаю?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_003";
		break;

 	              case "Gothic_2_003":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ANYNEWS_17_01.wav");
		dialog.text = "Мне почему-то кажется что тебя не особо волнует проблемы других людей?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_004";
		break;

 	              case "Gothic_2_004":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_2.wav");
		dialog.text = "";
		link.l1 = "Э, я думаю!!!";
    		link.l1.go = "Gothic_2_005";
		break;

 		case "Gothic_2_005":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_STANDARD_16_02.wav");
		dialog.text = "Я могла бы тебе рассказать милый, но не здесь!!! Здесь нас могут подслушивать, давай поднимимся на верх, иди за мной.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_006";
		break;

 		case "Gothic_2_006":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
		dialog.text = "";
		link.l1 = "Хорошо.";
    		link.l1.go = "Gothic_2_007";
		break;

 		case "Gothic_2_007":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload3", "GothicLee_InesDeLasCierras", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

 		case "Gothic_2_03":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_15_00.wav");
		dialog.text = "";
		link.l1 = "Ну а теперь, мы можем поговорить?";
    		link.l1.go = "Gothic_2_04";
		break;

 		case "Gothic_2_04":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_16_01.wav");
		dialog.text = "Да, здесь нас не подслушают.";
		link.l1 = "А, ей правда грозит смертельная опасность?";
    		link.l1.go = "Gothic_2_05";
		break;

 		case "Gothic_2_05":
		dialog.text = "Да, это так. Сеньор"+ GetSexPhrase("","ита") +", донне де Лейва грозит смертельная опасность! Генерал-губернатор Гаваны дон Хуан де Кордова предпринял расследование по этому поводу и выяснил все обстоятельства бегства донны Анны на Гваделупу.\n"+
				         "Все, что он узнал, он сообщил родственникам убитого дона Хосе. А дон Хосе Рамирес де Лейва - потомок старинного кастильского рода. По законам чести донна Анна должна поплатиться за свою неверность.";
			link.l1 = "До Гваделупы им не добраться...";
    		                     link.l1.go = "Gothic_2_06";
		break;

 		case "Gothic_2_06":
			dialog.text = "Ошибаетесь, сеньор"+ GetSexPhrase("","ита") +". Сюда уже прибыли двоюродные братья дона Хосе. Мне довелось их видеть, и поверьте мне, это настоящие головорезы. Когда кастильский дворянин свершает месть, ему не страшен сам дьявол!";
			link.l1 = "Ну, дьявола я им не обещаю, зато могу показаться собственной персоной. Не подскажете, где я могу их найти?";
    		                     link.l1.go = "Gothic_2_07";
		break;

 		case "Gothic_2_07":
			dialog.text = "Вчера они отправились в джунгли, в городе их нет. По всей видимости, они налаживают отношения с контрабандистами, чтобы скрытно проникнуть на Гваделупу.";
			link.l1 = "Надо успеть перехватить их в джунглях! Если они успеют вернуться в город, мне придется воевать со всем испанским гарнизоном. Спасибо вам, уважаемая Инес. Я никогда не верил"+ GetSexPhrase("","а") +" в женскую дружбу, но вы, отважная женщина, убедили меня в обратном.";
    		                     link.l1.go = "Gothic_2_08";
		break;

 		case "Gothic_2_08":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_SONST_16_06.wav");
			dialog.text = "Не хочешь позабавиться перед тем как уедешь!";
			link.l1 = "";
    		                   link.l1.go = "Gothic_2_Sex";
		break;

 		case "Gothic_2_Sex":
			dialog.text = "";
			link.l1 = "Думаю, ДА!!!";
    		                   link.l1.go = "Gothic_2_YesSex";
			link.l2 = "Спасибо но мне нужно идти...";
    		                   link.l2.go = "Gothic_2_NoSex";
		break;

 		case "Gothic_2_NoSex":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_WEITER_15_00.wav");
			dialog.text = "";
			link.l1 = "Спасибо но мне нужно идти...";
    		                   link.l1.go = "Gothic_2_NoSex_1";
		break;

 		case "Gothic_2_NoSex_1":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_WEITER_16_01.wav");
			dialog.text = "Очень жаль, ну чтож тогда в другой раз.";
			link.l1 = "";
    		                   link.l1.go = "Gothic_2_NoSex_exit";
		break;

 		case "Gothic_2_NoSex_exit":
                                      PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_SeekHoseBrothers";
		AddQuestRecord("GothicLee_2_KillAnnaHanters", "3");	
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex", GetSexPhrase("","а"));
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex1", GetSexPhrase("ен","на"));
		
		npchar.LifeDay = 1; // уберем нпс
		SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
		locations[FindLocation("Mayak10")].DisableEncounters = true; //энкаутеры закроем
		LAi_LocationDisableOfficersGen("Mayak10", true); //офицеров не пускать
		Pchar.quest.GothicLeeAnna_InShore.win_condition.l1 = "location";
			Pchar.quest.GothicLeeAnna_InShore.win_condition.l1.location = "Mayak10";
		Pchar.quest.GothicLeeAnna_InShore.win_condition = "GothicLeeAnna_InShore";
		break;



 		case "Gothic_2_YesSex":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_7.wav");
		dialog.text = "";
		link.l1 = "Думаю, ДА!!!";
    		link.l1.go = "Gothic_2_YesSex_1";
		break;

 		case "Gothic_2_YesSex_1":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_HOCHGEHEN_16_01.wav");
		dialog.text = "Сегодня тебе выпал счастливый билет - детка, пойдём!!!";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_2";
		break;

 		case "Gothic_2_YesSex_2":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_POPPEN_16_00.wav");
		dialog.text = "Следующие пару часов пренадлежит только нам.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_3";
		break;

 		case "Gothic_2_YesSex_3":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_POPPEN_16_01.wav");
		dialog.text = "Расслабься, ложись и получай удовольствие.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_4";
		break;

 		case "Gothic_2_YesSex_4":
		sld = CharacterFromID("InesDeLasCierras");
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
                                      pchar.GenQuest.BrothelCount = 0;
   		AddDialogExitQuest("PlaySexx_1");
		NextDiag.CurrentNode = "Gothic_2_09";
		DialogExit();
		break;

 		case "Gothic_2_09":
		dialog.text = "Ох...ты такой первобытный, дикий...";
		link.l1 = "Мне, пора...";
    		link.l1.go = "exit";
		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_SeekHoseBrothers";
		AddQuestRecord("GothicLee_2_KillAnnaHanters", "3");	
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex", GetSexPhrase("","а"));
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex1", GetSexPhrase("ен","на"));
		
		npchar.LifeDay = 1; // уберем нпс
		SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
		locations[FindLocation("Mayak10")].DisableEncounters = true; //энкаутеры закроем
		LAi_LocationDisableOfficersGen("Mayak10", true); //офицеров не пускать
		Pchar.quest.GothicLeeAnna_InShore.win_condition.l1 = "location";
			Pchar.quest.GothicLeeAnna_InShore.win_condition.l1.location = "Mayak10";
		Pchar.quest.GothicLeeAnna_InShore.win_condition = "GothicLeeAnna_InShore";
		break;

 		case "Gothic_2_4":
		dialog.text = "Фуф, это очень хорошо. Теперь донне Анне можно будет вздохнуть спокойно...";
		link.l1 = "Полагаю, что да.";
    		link.l1.go = "exit";
		break;

//********************************* Поики библии. Квест **********************************

		case "Gothic_3_10":
			dialog.text = "Кто вы и чем я могу помочь?";
			link.l1 = "Меня зовут " + GetFullName(pchar) + ", я хотел"+ GetSexPhrase("","а") +" бы купить у вас книгу, которую вы предлагали к продаже в обществе Торуса.";
			link.l1.go = "Gothic_3_11";
    	break;
		case "Gothic_3_11":
			dialog.text = "А-а-а, вот как? Хорошо, это можно устроить. Книга оказалась подделкой, но я знаю точное место захоронения Самуэля Кохэно и уверен, что книга оригинал при нем, он с ней при жизни не расстовался\nПроблема в том, что это место закрыто изнутри и защищено магией, взломать дверку мне не удалось, и тогда я предпринял больше узнать о этой защите\nМои поиски привели меня в библиотеку инквезиции, пришлось прибегнуть простым способом подкупа одного из старейшин, как видишь не всё гладко..., да и пергамент на очень древнем языке описан, так что моим поискам похоже конец\nТак вот, предлагаю условия сделки, с учетом твоей помощи: ты платишь мне 235 тысяч, и я даю тебе этот пергамент и называю место захоронения Самуэля Кохэно.";
			link.l1 = "А не слишком ли много - 235 тысяч?";
			link.l1.go = "Gothic_3_12";
    	break;
		case "Gothic_3_12":
			dialog.text = "Нет. Дело в том, что по моим иследованиям в том схроне еще кое-что лежит. Так что это цена за знания и поиски, ну и за весь клад!";
            if (sti(pchar.money) >= 235000)
            {
                link.l1 = "Согласен. Вот твои деньги!";
    			link.l1.go = "Gothic_3_13";
    			AddMoneyToCharacter(pchar, -235000);
            }
            else
            {
                link.l1 = "Нет, таких денег у меня сейчас нет. Придется заглянуть к тебе позже.";
    			link.l1.go = "Gothic_3_15";
            }
    	break;
		case "Gothic_3_13":
			dialog.text = "Извольте получить пергамент. Послушай, вот эта письменность на очень древнем языке? Будь так добр, скажи мне, зачем он тебе?";
			link.l1 = "Ха, попробую разобраться!";
			link.l1.go = "Gothic_3_14";
                                                              GiveItem2Character(pchar, "LegransMap");
    	break;
		case "Gothic_3_14":
			dialog.text = "Ну-ну, попытайся! Что ж, выгодная сделка для нас обоих, удачи.";
			link.l1 = "Это точно. Я благодар"+ GetSexPhrase("ен","на") +" тебе, Лоран де Граф. Надеюсь, еще увидимся.";
			link.l1.go = "exit";
            AddQuestRecord("GothicLee_3_SeekBible", "9");
            NPChar.LifeDay = 2;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
            pchar.questTemp.GothicLee = "SeekBible_IHaveMap";
            pchar.questTemp.GothicLee = "SeekBible_crypt";
            pchar.GenQuestBox.FortFrance_crypt = true;
            pchar.GenQuestBox.FortFrance_crypt.box3.items.jewelry5 = 200;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry17 = 300;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.blade_32 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.q_blade_10 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.mushket5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.cirass5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potion2 = 5;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.clock2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry7 = 5;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.obereg_10 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potion2 = 10;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potionwine = 3;
			                                                                       pchar.GenQuestBox.FortFrance_crypt.box4.items.recipe_totem_07 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry2 = 30;		
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry3 = 60;		
            pchar.GenQuestBox.FortFrance_crypt.box4.items.talisman2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.chest = 5;
			                                                                                    pchar.GenQuestBox.FortFrance_crypt.box4.items.icollection = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.amulet_9= 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_6 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_11 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_8 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box2.items.Bible = 1;
            pchar.GenQuestBox.FortFrance_crypt.box2.items.sextant3 = 1;

           DoQuestCheckDelay("SeekBible_FortFrance_Graveyard", 3.5);
        break;
		case "Gothic_3_15":
			dialog.text = "Прекрасно, судар"+ GetSexPhrase("ь","ыня") +". Вы сможете найти меня на Тортуге в таверне.";
			link.l1 = "Хорошо, скоро буду у тебя, жди.";
			link.l1.go = "exit";
			pchar.questTemp.GothicLee = "SeekBible_SeekMoney";
			              pchar.quest.SeekBible_DeGrafToTavern.win_condition.l1 = "MapEnter";
              pchar.quest.SeekBible_DeGrafToTavern.win_condition = "SeekBible_DeGrafToTavern";
    	break;

//*************************** Квест, диалоги с Франциско ***************************

 		case "Gothic_4_1":
			dialog.text = "Я знаю, ваше происхождение, откуда вы прибыли, и уменя к тебе масса вопросов! Да-да, мне многое известно, поэтому давай всё по порядку.";
			link.l1 = "Даже и если известно кто я, это не даёт тебе право истреблять подобных себе, не так ли, как там тебя?";
			link.l1.go = "Gothic_4_2";
		break;
 		case "Gothic_4_2":
			dialog.text = "А вот здесь ты ошибаешься, это наш мир, наша эпоха и наша история, чужакам вроде тебя тут не место, мы стоим и будем стоять на страже нашего мира во славу Господа.";
			link.l1 = "Во славу Господа, убивать не в чем не повиных людей, Шарль де Мор убит вашими молитвами не так ли?!";
			link.l1.go = "Gothic_4_3";
		break;
 		case "Gothic_4_3":
			dialog.text = "Здесь не наша вина, вина Декстора, как выяснилось он также из вашего мира. Он обманул нас и решил с нашей помощью убрать тебя, объявив что ты являешься демоном в человеческом обличии, и у нас небыло выбора, тот молодой дворянин погиб от его рук.";
			link.l1 = "Тогда как вы узнали?";
			link.l1.go = "Gothic_4_4";
		break;
 		case "Gothic_4_4":
			dialog.text = "Пару лет назад мне попался один интересный пергамент написаный свежими чернилами, а вот сама бумага очень древняя, меня заинтерисовал этот пергамент автором его являлся некий Ватрас, я решил занятся этим автором и выяснить всё досканально.";
			link.l1 = "И...";
			link.l1.go = "Gothic_4_5";
		break;

 		case "Gothic_4_5":
			dialog.text = "На днях я нашел этого человека, сначала принял его за сумашедшего, но входе длительных разговорах понял, что это не так, вот он мне и рассказал о вашей далекой вселенной, о барьере, о демоне Спящем, и то что ты его уничтожил, и многое другое.";
			link.l1 = "Ясно...И что ты намерен делать?";
			link.l1.go = "Gothic_4_6";
		break;

 		case "Gothic_4_6":
			dialog.text = "Следуй за мной.";
			link.l1 = "";
			link.l1.go = "Gothic_4_7";
		break;

 		case "Gothic_4_7": // к обезьянке
		chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload9", "Monkey", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "Monkey_1":
			dialog.text = "Итак, перед нами обезьяна, точнее то что от неё осталось, обезьяна нежить, на ней лежит индейское заклятие смерти, но она живая. Теперь идем дальше...";
			link.l1 = "";
			link.l1.go = "Gothic_4_8";
		break;

		case "Gothic_4_8": // к скелету
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "skeleton", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "skeleton_1":
			dialog.text = "Вот ещё одна нежить, но уже из останков человека давно умершего, полагаю на нем использовали африканскую магию вуду, идем дальше.";
			link.l1 = "";
			link.l1.go = "Gothic_4_9";
		break;

		case "Gothic_4_9": // к орку
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload12", "Orc", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "Orc_1":
			dialog.text = "А вот это форма проявления нам не известна, может ты просвятишь?";
			link.l1 = "";
			link.l1.go = "Orc_2";
                                                         DoQuestFunctionDelay("ORC_AMBIENT_SHORT", 0.4);
		break;

		case "Orc_2":
			dialog.text = "";
			link.l1 = "Как интересно? Это орк, точнее то что отнего осталось, повидимому он был шаманом орочей орды, откуда он у вас?";
			link.l1.go = "Orc_3";
		break;

		case "Orc_3":
			dialog.text = "Его поймали не долеко от Белиза, значит он от туда, откуда и вы!";
			link.l1 = "";
			link.l1.go = "Orc_4";
		break;

		case "Orc_4":
			dialog.text = "";
			link.l1 = "Ну, вобщем.... да!";
			link.l1.go = "Gothic_4_10";
		break;

 		case "Gothic_4_10": // к дверям
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload30", "Francisco_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "gate_1":
			dialog.text = "Я не до конца, понимаю Бога, что здесь происходит, орки, нежити, вы с далекого прошлого, надеюсь только на Всевышнего, что наш мир не исчезнет как ваш.";
			link.l1 = "Что...";
			link.l1.go = "gate_2";
		break;

		case "gate_2":
			dialog.text = "А ты не знал? Ватрас маг воды, так он себя называл, об этом так же рассказал.";
			link.l1 = "Где он?";
			link.l1.go = "gate_3";
		break;

		case "gate_3":
			dialog.text = "Я отпустил его, мне не извесно куда он ушёл. А что касаемо тебя, иди с миром, и избавь нас от этих демонов как избавил свой мир от Спящего, за этой дверью найдешь Декстора.";
			link.l1 = "";
			link.l1.go = "Gothic_4_11";
		break;

 		case "Gothic_4_11":
		      chrDisableReloadToLocation = false;
		      pchar.questTemp.GothicLee = "Inquisition_afterFrancisco";
                                          LAi_SetActorType(npchar);
                                          LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 40.0);
                                          LAi_SetPlayerType(pchar);
                                          DoQuestCheckDelay("Berglars_Dexter1", 5.5);
     DialogExit();
	int n = Findlocation("Graveyard_church");
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Shore111";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore111";
	locations[n].locators_radius.reload.reload1_back = 2;
	int nn = Findlocation("Shore111");
	Locations[nn].reload.l1.name = "reload1_back";
	Locations[nn].reload.l1.go = "Graveyard_church";
	Locations[nn].reload.l1.emerge = "reload1";
	Locations[nn].reload.l1.autoreload = "1";
	Locations[nn].locators_radius.reload.reload1_back = 3.0;
		break;

//********************************* Вызволение Горна. Квест **********************************
 		case "Gothic_5_1":
    		if (LAi_group_GetTarget(pchar) <= 0)
			{
	           PlaySound("VOICE\Russian\gotica\GORN\GORNDJG_HALLO_01.wav");
				dialog.text = "Я рад и счастлив, "+ GetSexPhrase("приятель","подруга") +". Но тебя я не знаю, может, ты скажешь, кто тебя сюда отправил?";
				link.l1 =  "Не кто иной, как Генерал Ли. Полагаю, ты знаешь, кто это... Ну ладно, теперь давай убираться отсюда на корабль, нас ждут в Сент-Луи. Ты можешь держать оружие?";
    			link.l1.go = "Gothic_5_2";
			}
			else
			{
				dialog.text = "Я очень рад...";
				link.l1 = "Договорим позже, надо разделаться тут со всеми...";
    			link.l1.go = "Gothic_5_Late";
			}
		break;
 		case "Gothic_5_2":
    		if (LAi_group_GetTarget(pchar) <= 0)
			{
				dialog.text = "Увы, нет. Местные святые отцы переломали мне руки...";
				link.l1 =  "Это плохо... Тогда следуй за мной по пятам - будем прорываться.";
    			link.l1.go = "Gothic_5_3";
			}
			else
			{
				dialog.text = "Увы, нет...";
				link.l1 = "Договорим потом, надо разделаться со всеми здесь!";
    			link.l1.go = "Gothic_5_Late";
			}
		break;
 		case "Gothic_5_3":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNDJG_01.wav");
			dialog.text = "Хорошо, как скажешь. У меня выбор невелик...";
			link.l1 = "Тогда вперед, корсар! И не отставай.";
    		link.l1.go = "Gothic_5_4";
		break;
 		case "Gothic_5_4":
			bDisableFastReload = false;
			AddQuestRecord("GothicLee_5_RockBras", "2");
			AddQuestUserData("GothicLee_5_RockBras", "sSex", GetSexPhrase("ел","ла"));
			Pchar.quest.RockBras_DelivShip.win_condition.l1 = "location";
			Pchar.quest.RockBras_DelivShip.win_condition.l1.location = "Cuba1";
			Pchar.quest.RockBras_DelivShip.win_condition = "RockBras_DelivShip";
			LAi_SetActorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;
 		case "Gothic_5_5":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNNW_02.wav");
			dialog.text = "Послушай, я хочу тебя отблагодарить за спасение моей жизни. Деньгами помочь не могу - я должен внести изрядную сумму в казну Франции.\n"+
				          "Но я могу дать тебе вещицу, которая значит для корсара гораздо больше, чем деньги.";
			link.l1 = "Отказываться не буду, тем более, что мне очень интересно...";
    		link.l1.go = "Gothic_5_6";
		break;
		case "Gothic_5_6":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNNW_03.wav");
            dialog.text = "В общем, слушай меня внимательно... Под городом Форт де Франс, что на Мартинике, есть подземелье в доме. В этом подземелье у меня припрятана одна очень ценная и нужная нашему брату вещичка...\n"+
				          "Что это - говорить не буду, сам"+ GetSexPhrase("","а") +" увидишь... В общем, я дарю тебе то, что ты там найдешь.";
			link.l1 = "Однако, необычный подарок, прямо скажем... Ну да ладно, дареному коню в зубы не глядят. Выздоравливай Горн...";
            link.l1.go = "Gothic_5_7";
        break;
		case "Gothic_5_7":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			DeleteAttribute(npchar, "RebirthPhantom");
         	                                npchar.LifeDay = 0; // уберем нпс
			pchar.GenQuestRandItem.FortFrance_Graveyard_Dungeon = true;
			pchar.GenQuestRandItem.FortFrance_Graveyard_Dungeon.randitem3 = "cirass4";
			DialogExit();
		                DoQuestCheckDelay("Gorn_tavern", 15.0);
        break;
 		case "Gothic_5_8":
			dialog.text = "Ты опоздал"+ GetSexPhrase("","а") +"... Всю эту неделю они пытали меня... Теперь... меня уже ничто не спасет... У-у-угх...";
			link.l1 = "Черт возьми, он умер!";
    		link.l1.go = "Gothic_5_9";
		break;
 		case "Gothic_5_9":
			bDisableFastReload = true;
			LAi_KillCharacter(npchar);
			DeleteAttribute(npchar, "RebirthPhantom");
         	                                npchar.LifeDay = 0; // уберем нпс
			pchar.questTemp.GothicLee = "RockBras_RockIsAgony";
			DialogExit();
		break;
 		case "Gothic_5_Late":
			bDisableFastReload = true;
			LAi_ActorWaitDialog(npchar, pchar);
			DialogExit();
		break;

//********************************* Объехать трех корсаров. Квест **********************************
        case "Gothic_6_1":
            dialog.text = "Ага, этот мерзавец сам не может прийти за мной и посылает своих прихвостней! Надеюсь, твоя душа, прежде чем попасть в ад, успеет шепнуть ему, что ждет каждого, кто посмеет...";
            link.l1 = "Утомил. Займемся делом, капитан...";
            link.l1.go = "Gothic_6_2";
        break;
 		case "Gothic_6_2":
			chrDisableReloadToLocation = true;
			LocatorReloadEnterDisable("PortRoyal_tavern", "reload2_back", true);
            LAi_group_MoveCharacter(npchar, "EnemyFight");
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "CanFightCurLocation");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;


	}
}
