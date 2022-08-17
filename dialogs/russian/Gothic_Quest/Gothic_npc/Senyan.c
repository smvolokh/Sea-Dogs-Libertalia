// Сеньян хитрый бандит 
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
			dialog.text = "Привет "+pchar.name+"?";
			link.l1 = "Как здоровье?";
			link.l1.go = "Senyan_01";			
		break;

		case "Senyan_01":
			dialog.text = "Ну ка, ну ка, вот ты где?";
			link.l1 = "";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;



// ********************* Сеньян (в таверне Саванна-ла-Мар) ******************************

		case "Senyan":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                   dialog.text = "А, кто это у нас здесь!";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_1";
		break;

		case "Senyan_1":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_01.wav");
            	                   dialog.text = "Ну - ка, ну - ка вот ты где! У меня для тебя есть хорошие новости и плохие новости.";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_2";
		break;

		case "Senyan_2":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_15_00.wav");
            	                   dialog.text = "";
        	                    link.l1 = "С начало расскажи мне плохие новости...";
        	                    link.l1.go = "Senyan_3";
		break;

		case "Senyan_3":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_02.wav");
            	                   dialog.text = "Тебя ищет Ворон и его охрана, вообще - то все бандиты ищут тебя.";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_4";
		break;

		case "Senyan_4":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_03.wav");
            	                   dialog.text = "И если они найдут тебя - они убьют тебя...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_5";
		break;

		case "Senyan_5":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_15_04.wav");
            	                   dialog.text = "";
        	                    link.l1 = "Многие уже пытались!";
        	                    link.l1.go = "Senyan_6";
		break;

		case "Senyan_6":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_05.wav");
            	                   dialog.text = "Значит ты дерёшься не хуже чем плетёшь интриги, придти в лагерь в таких доспехах - это...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_7";
		break;

		case "Senyan_7":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_06.wav");
            	                   dialog.text = "Всё равно, что придти к волкам будучи овцой, твоя жизнь весит на волоске - сын риска?";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_8";
		break;

		case "Senyan_8":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_15_01.wav");
            	                   dialog.text = "";
        	                    link.l1 = "А, что за хорошие новости?";
        	                    link.l1.go = "Senyan_9";
		break;

		case "Senyan_9":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_02.wav");
            	                   dialog.text = "Ну, я не знаю как это тебе удалось, но ты нажил себе парочку влиятельных врагов...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_10";
		break;

		case "Senyan_10":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_03.wav");
            	                   dialog.text = "Можешь считать, что тебе повезло никто кроме меня тебя не узнал!";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_11";
		break;

		case "Senyan_11":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_04.wav");
            	                   dialog.text = "А я человек понимающий и дружелюбный! Мистер Смит будет ждать тебя в таверне Сент - Луи, что на Гваделупе.";
        	                    link.l1 = "Отлично, мне кажется я понял, спасибо.";
        	                    link.l1.go = "Senyan_End";
		break;

 		case "Senyan_End":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_8.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_Senyan");
		break;


// ********************* Сеньян (на Мартинике) ******************************


		case "Senyan_coast":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                   dialog.text = "А, кто это у нас здесь!";
        	                    link.l1 = "Опять ты...";
        	                    link.l1.go = "Senyan_coast_1";
		break;

		case "Senyan_coast_1":
			dialog.text = "Как ты понимаешь я работал на Дэвида Смита и являлся его глазами и ушами... Я видел бой и похоже Кэрол ускользнула от тебя. Это плохо, как для тебя и меня...";
			link.l1 = "А с тобой-то, что не так!";
			link.l1.go = "Senyan_coast_2";
		break;

		case "Senyan_coast_2":
			dialog.text = "Я лишился работы из-за твоего провала. Это было условие Смита. Теперь ему мы оба не нужны...";
			link.l1 = "Значит ты без дела? Что - нибудь знаешь о Вороне?";
			link.l1.go = "Senyan_coast_3";
		break;

		case "Senyan_coast_3":
		dialog.text = "О Вороне я знаю, вот только где он обитает мне неведомо, похоже он мистеру Смиту рогов наставил?";
		link.l1 = "Ха, похоже, что так, но у меня теперь с этой сучкой личные счёты. Вот только где её искать?";
		link.l1.go = "Senyan_coast_4";
		break;

		case "Senyan_coast_4":
			dialog.text = "Есть одна мысль.";
			link.l1 = "Говори!";
			link.l1.go = "Senyan_coast_5";
		break;

		case "Senyan_coast_5":
			dialog.text = "Я знаю где живёт Джулия Смит, дочь Дэвида и Кэрол Смитов.";
			link.l1 = "Продолжай!";
			link.l1.go = "Senyan_coast_6";
		break;

		case "Senyan_coast_6":
			dialog.text = "Дом её на Мэйне в городе Белиз, возможно ей известно где её родители.";
			link.l1 = "Мало вероятно, но всё же попробовать можно!";
			link.l1.go = "Senyan_coast_7";
		break;

		case "Senyan_coast_7":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_1.wav");
			dialog.text = "...";
			link.l1 = "Ты пойдёшь  со мной на корабле?";
			link.l1.go = "Senyan_coast_8";
		break;

		case "Senyan_coast_8":
 	                   PlaySound("VOICE\Russian\gotica\SENYAN\DIA_ADDON_SENYAN_ATTENTAT_JA_12_01.wav");
			dialog.text = "Я знал, что мы можем договориться.";
			link.l1 = "Пакуй свои вещи!";
			link.l1.go = "Senyan_hired_1";
		break;


		case "Senyan_hired_1"://Сеньяна - в офицеры
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_YES.wav");
		DialogExit();
		DeleteAttribute(npchar, "LifeDay");
		npchar.quest.OfficerPrice = sti(pchar.rank)*700;
		npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
		npchar.CompanionDisable = true; //нельзя в компаньоны - чтобы не утонула
		LAi_SetImmortal(npchar, false);
		npchar.HalfImmortal = true; //чтобы не убили в сухопутном бою
		npchar.loyality = MAX_LOYALITY;
	                    AddPassenger(pchar, npchar, false);
	                    SetCharacterRemovable(npchar, true);
	                     npchar.Payment = true;
	                     npchar.DontClearDead = true;
	                     LAi_SetOfficerType(npchar);
	                     npchar.greeting = "Gr_Senyan";
                                          npchar.FaceId = 405; //Сеньян
		 NextDiag.CurrentNode = "Senyan_officer";
		 npchar.quest.meeting = true;
		 npchar.HoldEquip = true;
	                      LAi_SetImmortal(npchar, false);
	                      TakeNItems(npchar, "Rumm", 1);
	                      LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
		 SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
		 AddCharacterExpToSkill(pchar, "Leadership", 100);
                                          DoQuestFunctionDelay("Gothic_SmithySeaShore_1", 1.1);

		npchar.quest.talk = "Senyan_PuertoRico";
		AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
		AddCharacterExpToSkill(pchar, "Leadership", 50);
		break;


// ********************* Сеньян ( в Белизе) ******************************

		case "SenyanBelizHouse_Smithy":
            	                    dialog.text = "...";
        	                    link.l1 = "Хо, хо, хо... Зачётный выстрел.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_1";
		break;

		case "SenyanBelizHouse_Smithy_1":
            	                    dialog.text = "Прошу прощения капитан, не удержался. По правде говоря целился по ногам!";
        	                    link.l1 = "Хм... А попал в голову...Красавец...";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_2";
		break;

		case "SenyanBelizHouse_Smithy_2":
            	                    dialog.text = "Бывает! У меня к тебе срочное дело капитан.";
        	                    link.l1 = "Говори.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_3";
		break;

		case "SenyanBelizHouse_Smithy_3":
            	                    dialog.text = "В этом порту я встретил своего старого рудокопа, он работал на Эстебана, а Эстебан друг и правая рука Ворона. Я хочу сойти с корабля и о Вороне разузнать как можно больше, поэтому капитан я здесь.";
        	                    link.l1 = "Хм... Жаль, Сеньян. Но и понимаю тебя, что ж, желаю успешных поисков.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_4";
		break;

		case "SenyanBelizHouse_Smithy_4":
            	                    dialog.text = "Если повезёт я дам знать!";
        	                    link.l1 = "Понял...";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_End";
		break;

 		case "SenyanBelizHouse_Smithy_End":
                                          NextDiag.CurrentNode = "First time";
		DialogExit();      
		AddDialogExitQuestFunction("Gothic_SenyanBelizHouse_SmithyExit");
		break;

// ********************* Сеньян (в городе Сан-Андреас) ******************************

		case "Senyan_Raven":
 	                     PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                     dialog.text = "А, кто это у нас здесь!";
        	                     link.l1 = "Опять ты...";
        	                     link.l1.go = "Senyan_Raven_1";
		break;

		case "Senyan_Raven_1":
            	                     dialog.text = "Да, у меня есть новости, на этот раз хорошие!";
        	                     link.l1 = "Говори...";
        	                     link.l1.go = "Senyan_Raven_2";
		break;

		case "Senyan_Raven_2":
            	                     dialog.text = "При одном условии.";
        	                     link.l1 = "Я слушаю.";
        	                     link.l1.go = "Senyan_Raven_3";
		break;

		case "Senyan_Raven_3":
            	                     dialog.text = "Я хочу быть в твоей команде.";
        	                     link.l1 = "Я подумаю, всё будет зависить от новостей которые ты мне хочешь рассказать.";
        	                     link.l1.go = "Senyan_Raven_4";
		break;

		case "Senyan_Raven_4":
            	                     dialog.text = "Хорошо, Ворон на этом острове, занимался раскопками древнего храма и он его раскопал, ну как интересно! Зайти можно с моря пляж Санта-Мария дель Мар, ещё он вскрыл гробницу какого - то древнего жреца.";
        	                     link.l1 = "Говоришь, древний храм! Стоит проверить. Договорились, добро пожаловать в команду при условии без всяких уходов и приходов.";
        	                     link.l1.go = "Senyan_Raven_5";
		break;

		case "Senyan_Raven_5":
 	                     PlaySound("VOICE\Russian\gotica\SENYAN\DIA_ADDON_SENYAN_ATTENTAT_JA_12_01.wav");
            	                     dialog.text = "Я знал, что мы можем договориться. Есть капитан, без приходов и уходов.";
        	                     link.l1 = "Пакуй свои вещи.";
        	                     link.l1.go = "Senyan_Raven_6";
		break;

		case "Senyan_Raven_6":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_YES.wav");
		DialogExit();
		AddDialogExitQuest("GothicAPS_Quarhodron");
		DeleteAttribute(npchar, "LifeDay");
		npchar.quest.OfficerPrice = sti(pchar.rank)*500;
		npchar.OfficerWantToGo.DontGo = true;//не пытаться уйти
		npchar.loyality = MAX_LOYALITY;
		AddPassenger(pchar, npchar, false);
		SetCharacterRemovable(npchar, true);
		npchar.Payment = true;
		npchar.CanTakeMushket = true;
	                     npchar.DontClearDead = true;
		LAi_SetOfficerType(npchar);
	                     npchar.greeting = "Gr_Senyan";
                                          npchar.FaceId = 405; //Сеньян
		NextDiag.CurrentNode = "Senyan_officer";
		npchar.quest.meeting = true;
		npchar.HoldEquip = true;
		LAi_SetImmortal(npchar, false);
	                     TakeNItems(npchar, "Rumm", 1);
		LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
		SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
		ChangeCharacterComplexReputation(pchar, "nobility", 5);
		AddCharacterExpToSkill(pchar, "Leadership", 100);
		break;
























		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Senyan_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Сеньян, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Senyan_officer";
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
			link.l1 = "Спасибо, Сеньян! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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