// Ватрас маг с другой эпохи

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

	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_HEAL_05_01.wav");
            	dialog.text = "";
        	link.l1 = "Расскажи мне о ваших Богах!"; 
        	link.l1.go = "Vatras_01";
		break;

	case "Vatras_01":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_05_01.wav");
            	dialog.text = "";
        	link.l1 = "Расскажи мне о Ада носе"; 
        	link.l1.go = "Vatras_010";
        	link.l2 = "Расскажи мне о Инносе"; 
        	link.l2.go = "Vatras_020";
        	link.l3 = "Расскажи мне о Беллиаре"; 
        	link.l3.go = "Vatras_030";
        	link.l4 = "Прошу на борт моего корабля"; 
        	link.l4.go = "Vatras_040";
	NextDiag.TempNode = "First time";
		break;


		case "Vatras_010":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_ADANOS_05_01.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_011";
		break;
		case "Vatras_011":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_ADANOS_05_02.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_012";
		break;
		case "Vatras_012":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_ADANOS_05_03.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_01";
		break;

		case "Vatras_020":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_INNOS_05_01.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_021";
		break;
		case "Vatras_021":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_INNOS_05_02.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_022";
		break;
		case "Vatras_022":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_INNOS_05_03.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_01";
		break;

		case "Vatras_030":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_BELIAR_05_01.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_031";
		break;
		case "Vatras_031":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_BELIAR_05_02.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_032";
		break;
		case "Vatras_032":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GODS_BELIAR_05_03.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_01";
		break;


		case "Vatras_040":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GREET_05_00.wav");
            	dialog.text = "";
        	link.l1 = ""; 
        	link.l1.go = "Vatras_1";
		break;

		case "Vatras_1":
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			npchar.quest.OfficerPrice = sti(pchar.rank)*700;
			npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
			npchar.CompanionDisable = true; //нельзя в компаньоны - чтобы не утонул
			LAi_SetImmortal(npchar, false);
			npchar.HalfImmortal = true; //чтобы не убили в сухопутном бою
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			npchar.DontClearDead = true;
			NextDiag.CurrentNode = "Vatras_officer";
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			// на локацию 
			npchar.quest.talk = "Vatras_2";
			pchar.quest.Gotica_Myxir.win_condition.l1 = "location";
			pchar.quest.Gotica_Myxir.win_condition.l1.location = "LeFransua_port";
			pchar.quest.Gotica_Myxir.function = "Vatras_port";
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			npchar.greeting = "";
		break;


	case "Vatras_2":
	PlaySound("VOICE\Russian\gotica\VATRAS\DIA_VATRAS_GREET_05_00.wav");
            	dialog.text = "Благадарю капитан, я чувствую он где - то рядом, я найду его сам.";
        	link.l1 = "Ваше чутьё не обманывает."; 
        	link.l1.go = "Vatras_3";  
		break;

	case "Vatras_3":
	DialogExit();
	LAi_SetActorType(npchar);
                        LAi_ActorGoToLocation(npchar, "reload", "reload3", "LeFransua_town", "goto", "goto3", "VatrasHouse_David", -1);
	DoQuestFunctionDelay("VatrasHouse_David", 35.0);	
	break;

						
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Vatras_officer":
			dialog.text = "Капитан?";
			if (CheckAttribute(pchar, "questTemp.Gotica.BarbTemptation") && pchar.questTemp.Gotica.BarbTemptation == "Vatras")
			{
				Link.l3 = "Ватрас, я бы хотел с тобой посоветоваться.!";
				Link.l3.go = "islatesoro";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Vatras_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "Какие будут приказания?";
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
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}