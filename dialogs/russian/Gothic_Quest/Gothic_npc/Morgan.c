// ������ ����� � ������� ����� 
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
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��, ��!";
		link.l1.go = "Morgan_1";			
		break;

		case "Morgan_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_01.wav");
		dialog.text = "�, �, ��� ���� �����.";
		link.l1 = "...";
		link.l1.go = "Morgan_2";			
		break;

		case "Morgan_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_02.wav");
		dialog.text = "��������� ���� ��� ��������?";
		link.l1 = "...";
		link.l1.go = "Morgan_3";			
		break;

		case "Morgan_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_03.wav");
		dialog.text = "�, ���, �� ������ ����� �������. �������� ����...";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";		
		break;

		case "Morgan_Francis":
		dialog.text = "...";
		link.l1 = "��� �� ������� � ��������?";
		link.l1.go = "Morgan_Francis_0";
		link.l2 = "������ ����� � ������.";
		link.l2.go = "Morgan_Foundthem_0";
		link.l3 = "��� ���� ����.";
		link.l3.go = "GothicPiratosMorgan_exit";			
		break;

		case "GothicPiratosMorgan_exit":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\EXIT_2.wav");
		dialog.text = "....";
		link.l1 = "��� ���� ����.";
		link.l1.go = "GothicPiratosMorgan_exit_1";
		break;

		case "GothicPiratosMorgan_exit_1":
		NextDiag.TempNode = "Morgan_Francis";
		DialogExit();	
		break;

		case "Morgan_Foundthem_0":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ ����� � ������.";
		link.l1.go = "Morgan_Foundthem_1";			
		break;

		case "Morgan_Foundthem_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_01.wav");
		dialog.text = "�� ��������� ��� � ���.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_2";			
		break;

		case "Morgan_Foundthem_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_02.wav");
		dialog.text = "��������� ��� ������ � ���� ��������.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_3";			
		break;

		case "Morgan_Foundthem_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_03.wav");
		dialog.text = "� � ������ ���� �� ������.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_4";			
		break;

		case "Morgan_Foundthem_4":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_04.wav");
		dialog.text = "���, ������� �� ��� ���� ��� ������, �� ������� � ���� � �����.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_5";			
		break;

		case "Morgan_Foundthem_5":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_05.wav");
		dialog.text = "�� � �� ����������� ���������, � ������ ��� ������� ��������.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_6";			
		break;

		case "Morgan_Foundthem_6":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_06.wav");
		dialog.text = "���� ������ �� ������, ������� ��� ���, � ���� �������� �������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_Francis";		
		break;

		case "Morgan_Francis_0":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������� � ��������?";
		link.l1.go = "Morgan_Francis_1";			
		break;

		case "Morgan_Francis_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_01.wav");
		dialog.text = "� �� ���� �� ���� ������ ����, ���� �� �� ��� �� �����.";
		link.l1 = "...";
		link.l1.go = "Morgan_Francis_2";			
		break;

		case "Morgan_Francis_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_15_02.wav");
		dialog.text = "...";
		link.l1 = "�� ����� ���������?";
		link.l1.go = "Morgan_Francis_3";			
		break;

		case "Morgan_Francis_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_03.wav");
		dialog.text = "�� - �� - ��, �� ������, ��� �� �������...";
		link.l1 = "...";
		link.l1.go = "Morgan_Francis_4";			
		break;

		case "Morgan_Francis_4":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_04.wav");
		dialog.text = "�� ����� ������� ����, ������� ����� ������� ������� ������� - �������� �����...";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_Francis";		
		break;

		case "Morgan_Foundthem_end":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ ����� � ������.";
		link.l1.go = "Morgan_Foundthem_end_1";			
		break;

		case "Morgan_Foundthem_end_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_07.wav");
		dialog.text = "��, ������, ��� � ����?";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_end_2";		
		break;

		case "Morgan_Foundthem_end_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_01.wav");
		dialog.text = "...";
		link.l1 = "� ����� ��.";
		link.l1.go = "Morgan_Foundthem_end_3";		
		break;

		case "Morgan_Foundthem_end_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_03.wav");
		dialog.text = "...";
		link.l1 = "��� ������.";
		link.l1.go = "Morgan_noring";		
		break;

		case "Morgan_noring":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_08.wav");
		dialog.text = "�, ������? ��� � �������?";
		if (CheckCharacterItem(pchar, "jewelry28"))
		{
		link.l1 = "��� ���.";
		link.l1.go = "Morgan_noring_1";	
		}
		else
		{
		link.l1 = "� ��� ��� ������.";
		link.l1.go = "Morgan_noring_fail";	
		}
		break;

		case "Morgan_noring_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���.";
		link.l1.go = "Morgan_noring_2";		
		break;

		case "Morgan_noring_2":
		RemoveItems(PChar, "jewelry28", 1);
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_07_01.wav");
		dialog.text = "��, ��� ���. ������� ����...";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_3";		
		break;

		case "Morgan_noring_3":
                                          TakeNItems(pchar, "architects_table_12", 1);
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_07_02.wav");
		dialog.text = "���, ������ ��� �������� ��������, �������� ��� �� ������ ������ �����������, �� ������ �� �� ������ ��������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";		
		break;

		case "Morgan_noring_fail":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� ��� ������.";
		link.l1.go = "Morgan_noring_fail_1";		
		break;

		case "Morgan_noring_fail_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_01.wav");
		dialog.text = "�� ������ ��� �����, ������.";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_fail_2";		
		break;

		case "Morgan_noring_fail_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_02.wav");
		dialog.text = "��� ��������� ������, ���������� �������� �������.";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_fail_3";		
		break;

		case "Morgan_noring_fail_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_03.wav");
		dialog.text = "�� ������ ��� �����, ������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";		
		break;

		case "Morgan_01":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ���� ��� �����-������ ������?";
		link.l1.go = "Morgan_02";		
		break;

		case "Morgan_02":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_07_01.wav");
		dialog.text = "���� ���.";
		link.l1 = "...";
		link.l1.go = "Morgan_03";		
		break;

		case "Morgan_03":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_07_02.wav");
		dialog.text = "�������, ������, ����� ����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";			
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Morgan_officer":
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
			NextDiag.TempNode = "Morgan_officer";
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