// ���� ����� � ������� ����� 
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
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� � ���� ����!";
		link.l1.go = "Bill_1";			
		break;

		case "Bill_1":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_HELLO_03_01.wav");
		dialog.text = "���� ������� ���� �����!";
		link.l1 = "...";
		link.l1.go = "Bill_2";			
		break;

		case "Bill_2":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_HELLO_03_02.wav");
		dialog.text = "����� ���, ��� �� ������� ��� ������, ��� ������ � �������.";
		link.l1 = "...";
		link.l1.go = "Bill_3";			
		break;

		case "Bill_3":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_HELLO_03_03.wav");
		dialog.text = "� ���� �� �� ����� �����, ����� ������ ���� � ������ ��� ������.";
		link.l1 = "...";
		link.l1.go = "Bill_4";			
		break;

		case "Bill_4":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ����� �� ��� ������?";
		link.l1.go = "Bill_5";			
		break;

		case "Bill_5":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_01.wav");
		dialog.text = "��� ���������, ������.";
		link.l1 = "...";
		link.l1.go = "Bill_6";			
		break;

		case "Bill_6":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_02.wav");
		dialog.text = "���� �����, ��� �������� �� �������� ��� ������ ������.";
		link.l1 = "...";
		link.l1.go = "Bill_7";			
		break;

		case "Bill_7":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_03.wav");
		dialog.text = "������� � �����, ��� �� ����� �� ����� �� ���������.";
		link.l1 = "...";
		link.l1.go = "Bill_8";			
		break;

		case "Bill_8":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_04.wav");
		dialog.text = "���� ������� ������� ������ �� ��� �������, ��� ������������ ������ ��� �� �������.";
		link.l1 = "...";
		link.l1.go = "Bill_9";			
		break;

		case "Bill_9":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_05.wav");
		dialog.text = "�� � ������ ������ ����� ���� ����� �� ����.";
		link.l1 = "...";
		link.l1.go = "Bill_10";			
		break;

		case "Bill_10":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PLANKS_03_06.wav");
		dialog.text = "���� �� � ����, ��� ����� �� ������, � �� ������� � ��������.";
		link.l1 = "...";
		link.l1.go = "Bill_11";			
		break;

		case "Bill_11":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� ������ ����?";
		link.l1.go = "Bill_12";			
		break;

		case "Bill_12":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM_03_01.wav");
		dialog.text = "��� �������, � ��� ���������.";
		link.l1 = "...";
		link.l1.go = "Bill_13";			
		break;

		case "Bill_13":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM_03_02.wav");
		dialog.text = "� �� ��� ����� ������������� � �������, ���� � ���� ��������� �� ������ ���� ������, �� ��� ����� ������� �� ��������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bill_11";		
		break;

		case "Bill_AngusHanc":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_ANGUSNHANK_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� ������ � �����.";
		link.l1.go = "Bill_AngusHanc_1";			
		break;

		case "Bill_AngusHanc_1":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_ANGUSNHANK_03_01.wav");
		dialog.text = "� �� ���� ��� ���, ������ ���� ������� �� �����.";
		link.l1 = "...";
		link.l1.go = "Bill_AngusHanc_2";			
		break;

		case "Bill_AngusHanc_2":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_ANGUSNHANK_15_02.wav");
		dialog.text = "...";
		link.l1 = "�� ���� ��������, �����?";
		link.l1.go = "Bill_AngusHanc_3";			
		break;

		case "Bill_AngusHanc_3":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_ANGUSNHANK_03_03.wav");
		dialog.text = "��, ��� � ����, ��� ��, ��� ��� ������ ���� ���������� � ��������� � ����� �� ������ ��������� ������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bill_11";			
		break;

		case "Bill_foundfriends":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ����� ����� ������.";
		link.l1.go = "Bill_foundfriends_1";			
		break;

		case "Bill_foundfriends_1":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_03_01.wav");
		dialog.text = "�, ��� ���?";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_2";			
		break;

		case "Bill_foundfriends_2":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_15_02.wav");
		dialog.text = "...";
		link.l1 = "��� ������.";
		link.l1.go = "Bill_foundfriends_3";			
		break;

		case "Bill_foundfriends_3":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_03_03.wav");
		dialog.text = "��������� �������, ��� ����� ��.";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_4";			
		break;

		case "Bill_foundfriends_4":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_03_04.wav");
		dialog.text = "׸����� ������, �� ������ ������ � ���.";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_5";			
		break;

		case "Bill_foundfriends_5":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_FOUNDFRIENDS_03_05.wav");
		dialog.text = "���� �� � ������ ���� ��� ��� ��������, ��� ��� ������!";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_6";			
		break;

		case "Bill_foundfriends_6":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_JUANMURDER_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� ��� ���� ����� � ������.";
		link.l1.go = "Bill_foundfriends_7";			
		break;

		case "Bill_foundfriends_7":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_JUANMURDER_03_01.wav");
		dialog.text = "���, ��� ��� ������!";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_8";			
		break;

		case "Bill_foundfriends_8":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_JUANMURDER_15_02.wav");
		dialog.text = "...";
		link.l1 = "���� �� ��������, ��� ����� ����.";
		link.l1.go = "Bill_foundfriends_9";			
		break;

		case "Bill_foundfriends_9":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_JUANMURDER_03_03.wav");
		dialog.text = "�� ������ ��������� ����� ����, �� ������� ����!";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_10";			
		break;

		case "Bill_foundfriends_10":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_JUANMURDER_03_04.wav");
		dialog.text = "��� �� ������ ��� ����� � ���.";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_11";			
		break;

		case "Bill_foundfriends_11":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_KILLEDESTEBAN_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ����.";
		link.l1.go = "Bill_foundfriends_12";			
		break;

		case "Bill_foundfriends_12":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_KILLEDESTEBAN_03_01.wav");
		dialog.text = "�� �������?";
		link.l1 = "...";
		link.l1.go = "Bill_foundfriends_13";			
		break;

		case "Bill_foundfriends_13":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_KILLEDESTEBAN_15_02.wav");
		dialog.text = "...";
		link.l1 = "��������� �����...";
		link.l1.go = "Bill_foundfriends_14";			
		break;

		case "Bill_foundfriends_14":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_KILLEDESTEBAN_03_03.wav");
		dialog.text = "�� �����, �� ������� ���� ��� ������ ������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bill_Perm";			
		break;

		case "Bill_Perm":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM2_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������� ������?";
		link.l1.go = "Bill_Perm_1";			
		break;

		case "Bill_Perm_1":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM2_03_01.wav");
		dialog.text = "�, � �������.";
		link.l1 = "...";
		link.l1.go = "Bill_Perm_2";			
		break;

		case "Bill_Perm_2":
	                     PlaySound("VOICE\Russian\gotica\BILL\DIA_ADDON_BILL_PERM2_03_02.wav");
		dialog.text = "���� ������� ���������� �������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bill_Perm";			
		break;













		case "Bill_JunglefortBandits":
		dialog.text = "...";
		link.l1 = "����� ����� ��������� ��������, ��� ������ � �����, ��� ����� ���������.";
		link.l1.go = "Bill_JunglefortBandits_1";
		break;


		case "Bill_JunglefortBandits_1":
		dialog.text = "�����, ������. ������� � ����� ���������� ����� ��� ��� �� ������ ������. � � ���� ������� ������ ���� ����� � ���� ��� ���� �����. �� ���������!";
		link.l1 = "������, ����. �� �������!";
		link.l1.go = "Bill_JunglefortBandits_2";
		npchar.quest.Junglefort_Band = "true";
		break;
		
		case "Bill_JunglefortBandits_2": 
		chrDisableReloadToLocation = true;//������� �������
		DialogExit();
		LAi_SetActorType(npchar);
		ChangeCharacterAddressGroup(npchar, pchar.location, "goto", "goto4");
		LAi_ActorGoToLocation(npchar, "reload", "reload2_back", "none", "", "", "OpenTheDoors", -1);

		if (CheckAttribute(npchar, "quest.Junglefort_Band"))
		{
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l1 = "location";
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l1.location = "Shore129";
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l2 = "Timer";
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l2.date.hour  = sti(GetTime());
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l2.date.day   = GetAddingDataDay(0, 0, 2);
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l2.date.month = GetAddingDataMonth(0, 0, 2);
		pchar.quest.Gothic_JunglefortPrepareAttack.win_condition.l2.date.year  = GetAddingDataYear(0, 0, 2);
		pchar.quest.Gothic_JunglefortPrepareAttack.function = "Gothic_JunglefortBanditsPrepareAttack";
		SetFunctionTimerCondition("Gothic_JunglefortBanditsAttackOver", 0, 0, 4, false); // ������
		}
		else SetFunctionTimerCondition("Gothic_JunglefortBanditsDestroyed", 0, 0, 10, false); // ������

		break;

		case "Junglefort_attack":
		dialog.text = "��� ���� ������, "+pchar.name+". ��� ���� ������. ������������ � �����?";
		link.l1 = "��, ����. ��� ����� ����� � ���.";
		link.l1.go = "Junglefort_attack_1";
		break;
		
		case "Junglefort_attack_1":
		dialog.text = "����� ���������. ����� ��������� � ������� �������� ����� �� ���� �����. �� �������� ������� ����� �������. ������!";
		link.l1 = "������!";
		link.l1.go = "Junglefort_attack_2";
		break;
		
		case "Junglefort_attack_2":
                                    pchar.questTemp.Gothic.JunglefortAttack = "Gothic.JunglefortAttack";
		DialogExit();
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		for (i=1; i<=2; i++)
		{
		sld = characterFromId("GBill_off_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		for (i=1; i<=5; i++)
		{
		sld = characterFromId("GBill_sold_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		chrDisableReloadToLocation = false;//������� �������
		LocatorReloadEnterDisable("Shore129", "boat", true);
                                    npchar.quest.Junglefortexit = "true";
		pchar.quest.Gothic_JunglefortAttack_06.win_condition.l1 = "location";
		pchar.quest.Gothic_JunglefortAttack_06.win_condition.l1.location = "Trinidad_House_Jungle_fort";
		pchar.quest.Gothic_JunglefortAttack_06.function = "Gothic_JunglefortexitAttackTail";
		break;


		case "Bill_JunglefortBandits_3":
		dialog.text = "����� ��� �������� ������ ����, ��� �����, ��� ���� ��� '�� ���'.";
		link.l1 = "...";
		link.l1.go = "Bill_JunglefortBandits_4";
		break;

		case "Bill_JunglefortBandits_4":
                                    DialogExit();
		chrDisableReloadToLocation = false;
		pchar.quest.GothicJungle_fort_Trinidad.win_condition.l1 = "location";
		pchar.quest.GothicJungle_fort_Trinidad.win_condition.l1.location = "Jungle_fort_Trinidad";
		pchar.quest.GothicJungle_fort_Trinidad.function = "Gothic_GBillJunglefortexitAttack_2";
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		for (i=1; i<=2; i++)
		{
		sld = characterFromId("GBill_off_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		for (i=1; i<=5; i++)
		{
		sld = characterFromId("GBill_sold_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
	                  for (i=1; i<=4; i++)
	                 {
		sld = characterFromId("Ourmine_sold_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		break;

		case "Bill_JunglefortBandits_8":
		dialog.text = "����� ��� �������� ������ ����, ��� �����, ��� ���� ��� '�� ���'.";
		link.l1 = "...";
		link.l1.go = "Bill_JunglefortBandits_9";
		break;

		case "Bill_JunglefortBandits_9":
                                    DialogExit();
		chrDisableReloadToLocation = false;
		AddDialogExitQuestFunction("Gothic_GBillJunglefortexitAttack_3");
		break;



		case "GBill_off":
		dialog.text = LinkRandPhrase("�� ������ ���� ������� ��������, ��� ������ ������!","��� �� �������� ������� ��� ������� �� ��� ���� ���������!","��������� �������� �� ����� �� �������� �����! �� ������ ������ ��� ������!");
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "GBill_off";
		break;
		
		case "GBill_sold":
		dialog.text = LinkRandPhrase("�� ������ � ���!","������� ���� ��������!","��� ��� �� �����, � ��� ���������!");
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "GBill_sold";
		break;











		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Alligator_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "����, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Alligator_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ����������?";
            Link.l1 = "���� �����!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "������ �� ���� � �� ��������!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "����� �������� ��� ���������� ��� ������ �������������� ������.";
					Link.l3.go = "SetGunBullets";
				}	
			}


		break;

		
		case "SetGunBullets":
			Dialog.Text = "����� ���� ����������:";
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
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
        break;
	//<-- ----------------------------------- ���������� ���� ----------------------------------------
	
	// �� ��������
		case "tieyasal":
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, �� ������. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
			link.l1 = "�������, ����! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ����� ������������?";
			link.l1 = "������� �����. � ���� ������������ � ������.";
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