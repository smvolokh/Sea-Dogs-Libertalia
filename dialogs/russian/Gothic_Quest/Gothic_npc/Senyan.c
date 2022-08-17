// ������ ������ ������ 
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
			dialog.text = "������ "+pchar.name+"?";
			link.l1 = "��� ��������?";
			link.l1.go = "Senyan_01";			
		break;

		case "Senyan_01":
			dialog.text = "�� ��, �� ��, ��� �� ���?";
			link.l1 = "";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;



// ********************* ������ (� ������� �������-��-���) ******************************

		case "Senyan":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                   dialog.text = "�, ��� ��� � ��� �����!";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_1";
		break;

		case "Senyan_1":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_01.wav");
            	                   dialog.text = "�� - ��, �� - �� ��� �� ���! � ���� ��� ���� ���� ������� ������� � ������ �������.";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_2";
		break;

		case "Senyan_2":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_15_00.wav");
            	                   dialog.text = "";
        	                    link.l1 = "� ������ �������� ��� ������ �������...";
        	                    link.l1.go = "Senyan_3";
		break;

		case "Senyan_3":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_02.wav");
            	                   dialog.text = "���� ���� ����� � ��� ������, ������ - �� ��� ������� ���� ����.";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_4";
		break;

		case "Senyan_4":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_03.wav");
            	                   dialog.text = "� ���� ��� ������ ���� - ��� ����� ����...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_5";
		break;

		case "Senyan_5":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_15_04.wav");
            	                   dialog.text = "";
        	                    link.l1 = "������ ��� ��������!";
        	                    link.l1.go = "Senyan_6";
		break;

		case "Senyan_6":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_05.wav");
            	                   dialog.text = "������ �� ������� �� ���� ��� ������ �������, ������ � ������ � ����� �������� - ���...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_7";
		break;

		case "Senyan_7":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_BAD_12_06.wav");
            	                   dialog.text = "�� �����, ��� ������ � ������ ������ �����, ���� ����� ����� �� ������� - ��� �����?";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_8";
		break;

		case "Senyan_8":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_15_01.wav");
            	                   dialog.text = "";
        	                    link.l1 = "�, ��� �� ������� �������?";
        	                    link.l1.go = "Senyan_9";
		break;

		case "Senyan_9":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_02.wav");
            	                   dialog.text = "��, � �� ���� ��� ��� ���� �������, �� �� ����� ���� ������� ����������� ������...";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_10";
		break;

		case "Senyan_10":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_03.wav");
            	                   dialog.text = "������ �������, ��� ���� ������� ����� ����� ���� ���� �� �����!";
        	                    link.l1 = "";
        	                    link.l1.go = "Senyan_11";
		break;

		case "Senyan_11":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_GOOD_12_04.wav");
            	                   dialog.text = "� � ������� ���������� � �����������! ������ ���� ����� ����� ���� � ������� ���� - ���, ��� �� ���������.";
        	                    link.l1 = "�������, ��� ������� � �����, �������.";
        	                    link.l1.go = "Senyan_End";
		break;

 		case "Senyan_End":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_8.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_Senyan");
		break;


// ********************* ������ (�� ���������) ******************************


		case "Senyan_coast":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                   dialog.text = "�, ��� ��� � ��� �����!";
        	                    link.l1 = "����� ��...";
        	                    link.l1.go = "Senyan_coast_1";
		break;

		case "Senyan_coast_1":
			dialog.text = "��� �� ��������� � ������� �� ������ ����� � ������� ��� ������� � �����... � ����� ��� � ������ ����� ����������� �� ����. ��� �����, ��� ��� ���� � ����...";
			link.l1 = "� � �����-��, ��� �� ���!";
			link.l1.go = "Senyan_coast_2";
		break;

		case "Senyan_coast_2":
			dialog.text = "� ������� ������ ��-�� ������ �������. ��� ���� ������� �����. ������ ��� �� ��� �� �����...";
			link.l1 = "������ �� ��� ����? ��� - ������ ������ � ������?";
			link.l1.go = "Senyan_coast_3";
		break;

		case "Senyan_coast_3":
		dialog.text = "� ������ � ����, ��� ������ ��� �� ������� ��� ��������, ������ �� ������� ����� ����� ��������?";
		link.l1 = "��, ������, ��� ���, �� � ���� ������ � ���� ������ ������ �����. ��� ������ ��� � ������?";
		link.l1.go = "Senyan_coast_4";
		break;

		case "Senyan_coast_4":
			dialog.text = "���� ���� �����.";
			link.l1 = "������!";
			link.l1.go = "Senyan_coast_5";
		break;

		case "Senyan_coast_5":
			dialog.text = "� ���� ��� ���� ������ ����, ���� ������ � ����� ������.";
			link.l1 = "���������!";
			link.l1.go = "Senyan_coast_6";
		break;

		case "Senyan_coast_6":
			dialog.text = "��� � �� ����� � ������ �����, �������� �� �������� ��� � ��������.";
			link.l1 = "���� ��������, �� �� �� ����������� �����!";
			link.l1.go = "Senyan_coast_7";
		break;

		case "Senyan_coast_7":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_1.wav");
			dialog.text = "...";
			link.l1 = "�� ������  �� ���� �� �������?";
			link.l1.go = "Senyan_coast_8";
		break;

		case "Senyan_coast_8":
 	                   PlaySound("VOICE\Russian\gotica\SENYAN\DIA_ADDON_SENYAN_ATTENTAT_JA_12_01.wav");
			dialog.text = "� ����, ��� �� ����� ������������.";
			link.l1 = "����� ���� ����!";
			link.l1.go = "Senyan_hired_1";
		break;


		case "Senyan_hired_1"://������� - � �������
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_YES.wav");
		DialogExit();
		DeleteAttribute(npchar, "LifeDay");
		npchar.quest.OfficerPrice = sti(pchar.rank)*700;
		npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
		npchar.CompanionDisable = true; //������ � ���������� - ����� �� �������
		LAi_SetImmortal(npchar, false);
		npchar.HalfImmortal = true; //����� �� ����� � ���������� ���
		npchar.loyality = MAX_LOYALITY;
	                    AddPassenger(pchar, npchar, false);
	                    SetCharacterRemovable(npchar, true);
	                     npchar.Payment = true;
	                     npchar.DontClearDead = true;
	                     LAi_SetOfficerType(npchar);
	                     npchar.greeting = "Gr_Senyan";
                                          npchar.FaceId = 405; //������
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
		AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
		AddCharacterExpToSkill(pchar, "Leadership", 50);
		break;


// ********************* ������ ( � ������) ******************************

		case "SenyanBelizHouse_Smithy":
            	                    dialog.text = "...";
        	                    link.l1 = "��, ��, ��... �������� �������.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_1";
		break;

		case "SenyanBelizHouse_Smithy_1":
            	                    dialog.text = "����� �������� �������, �� ���������. �� ������ ������ ������� �� �����!";
        	                    link.l1 = "��... � ����� � ������...��������...";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_2";
		break;

		case "SenyanBelizHouse_Smithy_2":
            	                    dialog.text = "������! � ���� � ���� ������� ���� �������.";
        	                    link.l1 = "������.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_3";
		break;

		case "SenyanBelizHouse_Smithy_3":
            	                    dialog.text = "� ���� ����� � �������� ������ ������� ��������, �� ������� �� ��������, � ������� ���� � ������ ���� ������. � ���� ����� � ������� � � ������ ��������� ��� ����� ������, ������� ������� � �����.";
        	                    link.l1 = "��... ����, ������. �� � ������� ����, ��� �, ����� �������� �������.";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_4";
		break;

		case "SenyanBelizHouse_Smithy_4":
            	                    dialog.text = "���� ������ � ��� �����!";
        	                    link.l1 = "�����...";
        	                    link.l1.go = "SenyanBelizHouse_Smithy_End";
		break;

 		case "SenyanBelizHouse_Smithy_End":
                                          NextDiag.CurrentNode = "First time";
		DialogExit();      
		AddDialogExitQuestFunction("Gothic_SenyanBelizHouse_SmithyExit");
		break;

// ********************* ������ (� ������ ���-�������) ******************************

		case "Senyan_Raven":
 	                     PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_1084_SENYAN_HI_12_00.wav");
            	                     dialog.text = "�, ��� ��� � ��� �����!";
        	                     link.l1 = "����� ��...";
        	                     link.l1.go = "Senyan_Raven_1";
		break;

		case "Senyan_Raven_1":
            	                     dialog.text = "��, � ���� ���� �������, �� ���� ��� �������!";
        	                     link.l1 = "������...";
        	                     link.l1.go = "Senyan_Raven_2";
		break;

		case "Senyan_Raven_2":
            	                     dialog.text = "��� ����� �������.";
        	                     link.l1 = "� ������.";
        	                     link.l1.go = "Senyan_Raven_3";
		break;

		case "Senyan_Raven_3":
            	                     dialog.text = "� ���� ���� � ����� �������.";
        	                     link.l1 = "� �������, �� ����� �������� �� �������� ������� �� ��� ������ ����������.";
        	                     link.l1.go = "Senyan_Raven_4";
		break;

		case "Senyan_Raven_4":
            	                     dialog.text = "������, ����� �� ���� �������, ��������� ���������� �������� ����� � �� ��� ��������, �� ��� ���������! ����� ����� � ���� ���� �����-����� ���� ���, ��� �� ������ �������� ������ - �� �������� �����.";
        	                     link.l1 = "��������, ������� ����! ����� ���������. ������������, ����� ���������� � ������� ��� ������� ��� ������ ������ � ��������.";
        	                     link.l1.go = "Senyan_Raven_5";
		break;

		case "Senyan_Raven_5":
 	                     PlaySound("VOICE\Russian\gotica\SENYAN\DIA_ADDON_SENYAN_ATTENTAT_JA_12_01.wav");
            	                     dialog.text = "� ����, ��� �� ����� ������������. ���� �������, ��� �������� � ������.";
        	                     link.l1 = "����� ���� ����.";
        	                     link.l1.go = "Senyan_Raven_6";
		break;

		case "Senyan_Raven_6":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY_YES.wav");
		DialogExit();
		AddDialogExitQuest("GothicAPS_Quarhodron");
		DeleteAttribute(npchar, "LifeDay");
		npchar.quest.OfficerPrice = sti(pchar.rank)*500;
		npchar.OfficerWantToGo.DontGo = true;//�� �������� ����
		npchar.loyality = MAX_LOYALITY;
		AddPassenger(pchar, npchar, false);
		SetCharacterRemovable(npchar, true);
		npchar.Payment = true;
		npchar.CanTakeMushket = true;
	                     npchar.DontClearDead = true;
		LAi_SetOfficerType(npchar);
	                     npchar.greeting = "Gr_Senyan";
                                          npchar.FaceId = 405; //������
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
























		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Senyan_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Senyan_officer";
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
			link.l1 = "�������, ������! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
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