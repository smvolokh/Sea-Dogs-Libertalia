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
	                  PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_10.wav");
		dialog.text = "...";
		link.l1 = "�� � �������!";
		link.l1.go = "Matt_1";			
		break;

		case "Matt_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_HELLO_10_01.wav");
		dialog.text = "�, �������, ���������, ��� ������ ���������� ������ �������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;

		case "Matt_JunglefortBandits":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_15_03.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������ � ��������?";
		link.l1.go = "Matt_JunglefortBandits_1";
		link.l2 = "��� �� c������ � ��������?";
		link.l2.go = "Matt_Francis";
		break;

		case "Matt_Francis":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FRANCIS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� c������ � ��������?";
		link.l1.go = "Matt_Francis_1";
		break;

		case "Matt_Francis_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FRANCIS_10_01.wav");
		dialog.text = "����� ����, ��� �� ����� � �� ����������� �� ������ ������������?";
		link.l1 = "...";
		link.l1.go = "Matt_Francis_2";
		break;

		case "Matt_Francis_2":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_JOB_15_00.wav");
		dialog.text = "���-������ ���?";
		link.l1 = "...";
    		link.l1.go = "Matt_Francis_3";
		break;

		case "Matt_Francis_3":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FRANCIS_10_03.wav");
		dialog.text = "���� ��������. ��, ���, ������ ������ � ������ �� ��������.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "Matt_JunglefortBandits";
		break;

		case "Matt_JunglefortBandits_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_10_01.wav");
		dialog.text = "�� ������ �����, ����� ����, ��� ��� ���������� ������ � �� ����� ��� ����������� ��� ������!";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_2";
		break;

		case "Matt_JunglefortBandits_2":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_10_02.wav");
		dialog.text = "� ��� ����� ������...";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_3";
		break;

		case "Matt_JunglefortBandits_3":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_10_03.wav");
		dialog.text = "�� �� ������� ���� � ��� ���� ����� ������, �� �� ��������� ������ ������ ��� � �� ���������.";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_4";
		break;

		case "Matt_JunglefortBandits_4":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_10_04.wav");
		dialog.text = "�� � ����������, ��� ��� ������� �� �������� �������.";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_5";
		break;

		case "Matt_JunglefortBandits_5":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_10_05.wav");
		dialog.text = "����� ��� ������ ������� ���������.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "Matt_JunglefortBandits";
		break;

		case "Matt_Followme":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_15_00.wav");
		dialog.text = "...";
		link.l1 = "����� �� ����.";
		link.l1.go = "Matt_Followme_1";
		break;

		case "Matt_Followme_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_01.wav");
		dialog.text = "� �� ���� ������ ������ ����, � �������...";
		link.l1 = "...";
		link.l1.go = "Matt_Followme_2";
		break;

		case "Matt_Followme_2":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_15_01.wav");
		dialog.text = "...";
		link.l1 = "�� ������ ��� ������.";
		link.l1.go = "Matt_Followme_3";
		break;

		case "Matt_Followme_3":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_15_03.wav");
		dialog.text = "...";
		link.l1 = "������ �����.";
		link.l1.go = "Matt_Followme_4";
		break;

		case "Matt_Followme_4":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_03.wav");
		dialog.text = "�������, ������� ��� ������� �� ������ - ��� ���...";
		link.l1 = "...";
		link.l1.go = "Matt_Followme_5";
		break;

		case "Matt_Followme_5":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_04.wav");
		dialog.text = "� ���� �� ������������?";
		link.l1 = "...";
		link.l1.go = "Matt_Followme_6";
		break;

		case "Matt_Followme_6":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_CLEARCANYON_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� ������ �������� ������ �� ������.";
		link.l1.go = "Matt_Followme_7";
		break;

		case "Matt_Followme_7":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_CLEARCANYON_10_01.wav");
		dialog.text = "�� ��������? ��� �� �����, � � ����� ������������ ����� �����.";
		link.l1 = "...";
		link.l1.go = "Matt_Followme_8";
		pchar.questTemp.Followme = sti(pchar.questTemp.Followme)+1;
	                     if (sti(pchar.questTemp.Followme) == 2) 
	                     {
                                          DoQuestFunctionDelay("FollowmeJOB", 1.1);
	                      }	
		break;

		case "Matt_Followme_8":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_CLEARCANYON_10_03.wav");
		dialog.text = "��, ������� � ���� ���������� ������� �������� ����� ��� ��� �����������.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicGreg_Matt");
		break;

		case "Matt_Followme_9":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_TOOFAR_10_01.wav");
		dialog.text = "������ ���� ������� ���� ������, �������.";
		link.l1 = "...";
		link.l1.go = "Matt_Followme_10";
		break;

		case "Matt_Followme_10":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_TOOFAR_10_03.wav");
		dialog.text = "�� � �������� ������������ � ������.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicGreg_Matt_End");
		break;


		case "Matt_JunglefortBandits_6":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_15_00.wav");
		dialog.text = "...";
		link.l1 = "����� �� ����.";
		link.l1.go = "Matt_JunglefortBandits_7";
		break;

		case "Matt_JunglefortBandits_7":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_01.wav");
		dialog.text = "� �� ���� ������ ������ ����, � �������...";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_8";
		break;

		case "Matt_JunglefortBandits_8":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_15_01.wav");
		dialog.text = "...";
		link.l1 = "�� ������ ��� ������.";
		link.l1.go = "Matt_JunglefortBandits_9";
		break;

		case "Matt_JunglefortBandits_9":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_03.wav");
		dialog.text = "�������, ������� ��� ������� �� ������ - ��� ���...";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_10";
		break;

		case "Matt_JunglefortBandits_10":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_10_04.wav");
		dialog.text = "� ���� �� ������������?";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_11";
		break;

		case "Matt_JunglefortBandits_11":
		dialog.text = "...";
		link.l1 = "����� ����� ��������� ��������, ��� ������ � �����.";
		link.l1.go = "Matt_JunglefortBandits_12";
		break;

		case "Matt_JunglefortBandits_12":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_CLEARCANYON_10_03.wav");
		dialog.text = "��, ������� � ���� ���������� ������� �������� ����� ��� ��� �����������. ����������� � ���� ����� ����� ��� ���, ������ ����� ��������. � � ���� ������� ������ ���� �����. �� ���������!";
		link.l1 = "������, ����. �� �������.";
		link.l1.go = "Matt_JunglefortBandits_13";
		npchar.quest.Junglefort_Band = "true";
		break;

		case "Matt_JunglefortBandits_13": 
		chrDisableReloadToLocation = true;//������� �������
		DialogExit();
		LAi_SetActorType(npchar);
		ChangeCharacterAddressGroup(npchar, pchar.location, "goto", "ass3");
		LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);

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
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_ALRIGHT_15_01.wav");
		dialog.text = "...";
		link.l1 = "��� ����?";
		link.l1.go = "Junglefort_attack_1";
		break;
		
		case "Junglefort_attack_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_ALRIGHT_10_01.wav");
		dialog.text = "�� � ������� �������. ��� ���� ������. ����� ��������� � ������� �������� ����� �� ���� �����. �� �������� ������� ����� �������, ������� ���������� ������� ������� ���� ���� � �� ������ ������� � ��� ��������. ������!";
		link.l1 = "...";
		link.l1.go = "Junglefort_attack_2";
		break;

		case "Junglefort_attack_2":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_SHUTUP_15_00.wav");
                                          LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload4_back", false);//������� ������
		dialog.text = "...";
		link.l1 = "�������� � ��� �� ����.";
		link.l1.go = "Junglefort_attack_3";
		break;
		
		case "Junglefort_attack_3":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_FOLLOWME_SHUTUP_10_01.wav");
		DialogExit();
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		for (i=1; i<=2; i++)
		{
		sld = characterFromId("GMatt_off_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		for (i=1; i<=5; i++)
		{
		sld = characterFromId("GMatt_sold_"+i);
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

		case "Matt_JunglefortBandits_Attack":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_JOB_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ������ ���.";
		link.l1.go = "Matt_JunglefortBandits_Attack_1";
		break;

		case "Matt_JunglefortBandits_Attack_1":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_ALRIGHT_10_02.wav");
		dialog.text = "����� ����� �����, �������� ����� �� �� �����.";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_Attack_2";
		break;

		case "Matt_JunglefortBandits_Attack_2":
                                    PlaySound("Ambient\Tavern\naliv_003.wav");
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_BANDITS_15_02.wav");
		dialog.text = "...";
		link.l1 = "��.";
		link.l1.go = "Matt_JunglefortBandits_Attack_3";
		break;

		case "Matt_JunglefortBandits_Attack_3":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_ALRIGHT_10_01.wav");
                                    DialogExit();
		chrDisableReloadToLocation = false;
		pchar.quest.GothicJungle_fort_Trinidad.win_condition.l1 = "location";
		pchar.quest.GothicJungle_fort_Trinidad.win_condition.l1.location = "Jungle_fort_Trinidad";
		pchar.quest.GothicJungle_fort_Trinidad.function = "Gothic_GMattJunglefortexitAttack_2";
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		for (i=1; i<=2; i++)
		{
		sld = characterFromId("GMatt_off_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
		for (i=1; i<=5; i++)
		{
		sld = characterFromId("GMatt_sold_"+i);
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

		case "Matt_JunglefortBandits_Attack_4":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_TOOFAR_10_01.wav");
		dialog.text = "������ ���� ������� ���� ������, �������.";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_Attack_5";
		break;

		case "Matt_JunglefortBandits_Attack_5":
	                  PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_TOOFAR_10_03.wav");
		dialog.text = "�� � �������� ������������ � ������.";
		link.l1 = "...";
		link.l1.go = "Matt_JunglefortBandits_Attack_6";
		break;

		case "Matt_JunglefortBandits_Attack_6":
	                  for (i=1; i<=4; i++)
	                 {
		sld = characterFromId("Ourmine_sold_"+i);
		LAi_SetActorType(sld);
		LAi_ActorFollowEverywhere(sld, "", -1);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
                                    DialogExit();
		chrDisableReloadToLocation = false;
		AddDialogExitQuestFunction("Gothic_GMattJunglefortexitAttack_3");
		break;

		case "GMatt_off":
		dialog.text = LinkRandPhrase("�� ������ ���� ������� ��������, ��� ������ ������!","��� �� �������� ������� ��� ������� �� ��� ���� ���������!","������ �������! �� ������ ������ ��� ������!");
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "GMatt_off";
		break;
		
		case "GMatt_sold":
		dialog.text = LinkRandPhrase("�� ������ � ���!","������� ���� ��������!","��� ��� �� �����, � ��� ���������!");
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "GMatt_sold";
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