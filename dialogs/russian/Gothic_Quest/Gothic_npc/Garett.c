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
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_HELLO_09_00.wav");
		dialog.text = "���, ���, ����� ����, ������� �� �� ���� �� ���� ������� ��������.";
		link.l1 = "...";
		link.l1.go = "Garett_1";			
		break;

		case "Garett_1":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_HELLO_09_01.wav");
		dialog.text = "�� ��� ������, ���� ���� ���-������ ������������ ������ � ����.";
		link.l1 = "...";
		link.l1.go = "Garett_2";			
		break;

		case "Garett_2":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_HELLO_09_02.wav");
		dialog.text = "� ���� ������� ����������� ��� ������, ����, ������, ��, ��� ���� ����� ������������.";
		link.l1 = "...";
		link.l1.go = "Garett_3";			
		break;

		case "Garett_3":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_HELLO_09_03.wav");
		dialog.text = "����� ��������, ���� ���� ����� ������� ��� � �������.";
		link.l1 = "...";
		link.l1.go = "exit";
		link.l2 = "����� �����������, ��� ��� � ��� �� �������.";
		link.l2.go = "trade";	
		NextDiag.TempNode = "Garett_2";		
		break;

		case "trade":
		DialogExit();
		NextDiag.TempNode = "Garett_2";
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		LaunchItemsTrade(npchar, 0);
		break;

		case "Garett":
		dialog.text = "...";
		link.l1 = "��� �� ������ � ��������.";
		link.l1.go = "Garett_bandits";
		link.l2 = "��� �� ������ ��� ������� � ��������.";
		link.l2.go = "Garett_Francis";
		link.l3 = "��� ������� ����, ����� ��?";
		link.l3.go = "Garett_Greg";
		link.l4 = "������ �� ��������� ���� ������?";
		link.l4.go = "Garett_warez";
		link.l5 = "���������, ��� ��� � ���� �� �������";
		link.l5.go = "Garett_trade";
		link.l6 = "� ������ ����.";
		link.l6.go = "Garett_exit";			
		break;

		case "Garett_exit":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\EXIT_1.wav");
		dialog.text = "....";
		link.l1 = "� ������ ����.";
		link.l1.go = "exit";
		NextDiag.TempNode = "Garett";
		break;

		case "Garett_trade":
		DialogExit();
		NextDiag.TempNode = "Garett";
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		LaunchItemsTrade(npchar, 0);
		break;

		case "Garett_bandits":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_BANDITS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������ � ��������.";
		link.l1.go = "Garett_bandits_1";			
		break;

		case "Garett_bandits_1":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_BANDITS_09_01.wav");
		dialog.text = "�� ���� ���� ����� �������� � �����.";
		link.l1 = "...";
		link.l1.go = "Garett_bandits_2";			
		break;

		case "Garett_bandits_2":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_BANDITS_09_02.wav");
		dialog.text = "�� �������� ����� ������� � ���� ������.";
		link.l1 = "...";
		link.l1.go = "Garett_bandits_3";			
		break;

		case "Garett_bandits_3":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_BANDITS_09_03.wav");
		dialog.text = "� ������ ���� �������� ��� ������� ������� ������� ����������� � ������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Garett";
	                     npchar = CharacterFromID("GSkip");
	                     npchar.dialog.currentnode = "Skip_Bandits";			
		break;

		case "Garett_Francis":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������ ��� ������� � ��������.";
		link.l1.go = "Garett_Francis_1";			
		break;

		case "Garett_Francis_1":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_01.wav");
		dialog.text = "����� ����� ���, �� ������� �� ��������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_2";			
		break;

		case "Garett_Francis_2":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_02.wav");
		dialog.text = "�� ����� ������, ����� �� ���� �������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_3";			
		break;

		case "Garett_Francis_3":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_03.wav");
		dialog.text = "�� ���� ������� �� ����� ��������� �������� ���� ������� ������� �� �������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_4";			
		break;

		case "Garett_Francis_4":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_04.wav");
		dialog.text = "��� �� �������� ������ ���������� ������ ����� �� ������ ��������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_5";			
		break;

		case "Garett_Francis_5":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_05.wav");
		dialog.text = "� ��������� ������ �������������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_6";			
		break;

		case "Garett_Francis_6":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_06.wav");
		dialog.text = "�������, ��� ���� ����� �������.";
		link.l1 = "...";
		link.l1.go = "Garett_Francis_7";			
		break;

		case "Garett_Francis_7":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_FRANCIS_09_07.wav");
		dialog.text = "�� �� ������� ���� ������� ��� � ����!";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Garett";		
		break;

		case "Garett_Greg":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ������� ����, ����� ��?";
		link.l1.go = "Garett_Greg_1";			
		break;

		case "Garett_Greg_1":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_01.wav");
		dialog.text = "� ���� ������ ������� ������ ����� �� ������.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_2";			
		break;

		case "Garett_Greg_2":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_02.wav");
		dialog.text = "� ���� �� �� ����� �� �������������.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_3";			
		break;

		case "Garett_Greg_3":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_03.wav");
		dialog.text = "������� ��� ��������, ������ ��� ����� �������, ������� �����, ��� �� �� �� ������� ����.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_4";			
		break;

		case "Garett_Greg_4":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_04.wav");
		dialog.text = "� ���� ��� ��������, ���-������ ������������� ������, ������� ��� �� �������� ����.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_5";			
		break;

		case "Garett_Greg_5":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_05.wav");
		dialog.text = "������� �� ����������� ������� � ����� ������� ������.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_6";			
		break;

		case "Garett_Greg_6":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_06.wav");
		dialog.text = "������� ��, ���� ������� ����, ������� ��� � ����.";
		link.l1 = "...";
		link.l1.go = "Garett_Greg_7";			
		break;

		case "Garett_Greg_7":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_GREG_09_07.wav");
		dialog.text = "��������� �� ��� ���-������ �������, �� ��� ��������� �� ����� ������ �����������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Garett";		
		break;

		case "Garett_warez":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_WAREZ_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ �� ��������� ���� ������?";
		link.l1.go = "Garett_warez_1";			
		break;

		case "Garett_warez_1":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_WAREZ_09_01.wav");
		dialog.text = "����� ���� ����� � �������, �� ������ �� ���� �������� ��������� �����.";
		link.l1 = "...";
		link.l1.go = "Garett_warez_2";			
		break;

		case "Garett_warez_2":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_WAREZ_09_02.wav");
		dialog.text = "�� ��������� ������� ����� �� ���, �� �� ������ �������� ��������.";
		link.l1 = "...";
		link.l1.go = "Garett_warez_3";			
		break;

		case "Garett_warez_3":
	                     PlaySound("VOICE\Russian\gotica\GARETT\DIA_ADDON_GARETT_WAREZ_09_03.wav");
		dialog.text = "�� ������ � ��� � ��������� �����, ��� ��� ��� ������ ����������� � ����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Garett";		
		break;




		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Garett_officer":
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
			NextDiag.TempNode = "Garett_officer";
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