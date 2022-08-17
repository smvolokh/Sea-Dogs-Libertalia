// ������� ����� � ������� ����� 
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

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "GothicPiratosFrancis_NoMoney" && !CheckAttribute(npchar, "quest.GothicPiratosFrancis_NoMoney"))
		{
		dialog.text = "��������" + GetSexPhrase("","�") + " �������?";
		link.l1 = "��, ����� ��, ��������" + GetSexPhrase("","�") + ".";
		link.l1.go = "GothicPiratosFrancis_key_pay_2000";
		}

                                          LocatorReloadEnterDisable("Trinidad_House_Jungle", "reload2_back", true);//������� ������
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_GREGSHUT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ������!";
		link.l1.go = "Francis_1";			
		break;

		case "Francis_1":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_GREGSHUT_13_01.wav");
		dialog.text = "��� ��� ����������� �����.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;

		case "Francis_Greg":
                                          LocatorReloadEnterDisable("Trinidad_House_Jungle", "reload2_back", true);//������� ������
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_GREGSHUT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ������!";
		link.l1.go = "Francis_Greg_1";			
		break;

		case "Francis_Greg_1":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_GREGSHUT_13_01.wav");
		dialog.text = "��� ��� ����������� �����.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_2";			
		break;

		case "Francis_Greg_2":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_LETMEIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ������ ������� � ������ �����.";
		link.l1.go = "Francis_Greg_3";			
		break;

		case "Francis_Greg_3":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_LETMEIN_13_01.wav");
		dialog.text = "� ������ ������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_4";			
		break;

		case "Francis_Greg_4":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_LETMEIN_13_02.wav");
		dialog.text = "����� ������ ���, � � ����� �����, ��� �� ��� �� �������� ���������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_5";			
		break;

		case "Francis_Greg_5":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_LETMEIN_13_03.wav");
		dialog.text = "���, ��� ����� �� ����, � �� ���������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Francis_Greg_6";			
		break;

		case "Francis_Greg_6":
		dialog.text = "...";
		link.l1 = "���� ���� ���������?";
		link.l1.go = "Francis_Greg_7";
		link.l2 = "��� �, ����� ��������� ��� �� ���� ����������� ����������.";
		link.l2.go = "Francis_Greg_07";	
		link.l3 = "� ��� ���� ��� ������ �������.";
		link.l3.go = "Francis_Greg_007";			
		break;

		case "Francis_Greg_007":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� ���� ��� ������ �������.";
		link.l1.go = "Francis_Greg_008";			
		break;

		case "Francis_Greg_008":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_13_01.wav");
		dialog.text = "������, �� ������� ���� �������� ���� �� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_009";			
		break;

		case "Francis_Greg_009":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_13_02.wav");
		dialog.text = "���� � ������ �������...";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_0010";			
		break;

		case "Francis_Greg_0010":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_13_03.wav");
		dialog.text = "��, �����, ����� ������, � ����� ������ �� ������ �� ������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosFrancis_key_pay_2000";			
		break;

		case "GothicPiratosFrancis_key_pay_2000":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_11.wav");
		dialog.text = "...";
		link.l1 = "������, ��� ������.";
		link.l1.go = "GothicPiratosFrancis_key_pay_0";
		break;

		case "GothicPiratosFrancis_key_pay_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "...";
		link.l1 = "...";
		link.l1.go = "GothicPiratosFrancis_key";
		break;

 		case "GothicPiratosFrancis_key":                                    
            if (sti(pchar.money) >= 2000)
            {
        		dialog.text = "��� ����.";
        		link.l1 = "...";
        		link.l1.go = "Francis_Greg_0011";
            }
            else
            {
        		dialog.text = "���, " + GetSexPhrase("������","���������") + ", ����� ���? ��� � �� ��� ������ ��������? �������, ����� �����.";
        		link.l1 = "��, �� ������ �� ������, ����� � ������� ������ ���...";
        		link.l1.go = "exit";
        		pchar.questTemp.GothicPiratosGreg = "GothicPiratosFrancis_NoMoney";
	ChangeCharacterComplexReputation(pchar, "nobility", -1);
               }
 		break;

		case "Francis_Greg_0011":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_13_04.wav");
		dialog.text = "��� ����.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_0012";
		GiveItem2Character(pchar, "key1");			
		break;

		case "Francis_Greg_0012":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_2000GOLD_13_05.wav");
		dialog.text = "������� ���� ���� �� �������� � �� ���� ������ ������������ �� ����, �����...";
		link.l1 = "...";
		link.l1.go = "exit";
		npchar.quest.GothicPiratosFrancis_NoMoney = "true";
    		AddMoneyToCharacter(pchar, -2000);
		AddDialogExitQuestFunction("GothicEng_Franciskey");	
		break;

		case "Francis_Greg_07":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUFSMAUL_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �, ����� ��������� ��� �� ���� ����������� ����������.";
		link.l1.go = "Francis_Greg_08";			
		break;

		case "Francis_Greg_08":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUFSMAUL_13_01.wav");
		dialog.text = "���, ����� � �������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_09";			
		break;

		case "Francis_Greg_09":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUFSMAUL_13_02.wav");
		dialog.text = "�� �� ����� ����������, � ����� ���� ��������� ��������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_010";
		NextDiag.TempNode = "Francis_Greg_6";			
		break;

		case "Francis_Greg_010":
		DialogExit();
		NextDiag.TempNode = "Francis_Greg_6";	
		AddDialogExitQuestFunction("GothicEng_FrancisFight");	
		break;

		case "Francis_Greg_7":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ���� ���������?";
		link.l1.go = "Francis_Greg_8";			
		break;

		case "Francis_Greg_8":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_01.wav");
		dialog.text = "������ �� ������� ��� �������, ��� �� ��� ������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_9";			
		break;

		case "Francis_Greg_9":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_02.wav");
		dialog.text = "����� �����, ��, ��� ���, ���� ��������� ���������� ����� ����� �������� �������� �����.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_10";			
		break;

		case "Francis_Greg_10":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_03.wav");
		dialog.text = "� �� ������� �� ��������, ����...";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_11";			
		break;

		case "Francis_Greg_11":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_04.wav");
		dialog.text = "� ������ ���������� ���� ������� ��������� ��� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_12";			
		break;

		case "Francis_Greg_12":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_05.wav");
		dialog.text = "��������� ������, ��� ������ ���� �������� ���, ��� ����� ������ �� ��� �� �����������������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_13";			
		break;

		case "Francis_Greg_13":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_06.wav");
		dialog.text = "��� ����� �������� ����� ���� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_14";			
		break;

		case "Francis_Greg_14":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_07.wav");
		dialog.text = "� ��� �� �������� � ���, ��� ����� �����������, �������...";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_15";			
		break;

		case "Francis_Greg_15":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_08.wav");
		dialog.text = "� ��� �� �������� ��� � ���, ��� ������� ���������� � ��� ������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_16";			
		break;

		case "Francis_Greg_16":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_ABOUTGREG_13_09.wav");
		dialog.text = "������� ���������� ��� � ���� ����� ������� ������������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Francis_Greg_6";			
		break;

		case "Francis_Greg_20":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUSGESCHISSEN_13_00.wav");
		dialog.text = "��������� ����, ���� �������� ���� ������ ����� �� ��� ���, ���� �� ������� �� ��������� �� ������ ������.";
		link.l1 = "...";
		link.l1.go = "Francis_Greg_21";			
		break;

		case "Francis_Greg_21":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUSGESCHISSEN_13_01.wav");
		dialog.text = "������ ���� � �����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Francis_Greg_20";
		AddDialogExitQuestFunction("GothicGreg_Francis_End");	
		break;

		case "Francis_Greg_22":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_AUSGESCHISSEN_13_01.wav");
		dialog.text = "������ ���� � �����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Francis_Greg_22";	
		break;

		case "Francis_business":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_BUSINESS_15_03.wav");
		dialog.text = "...";
		link.l1 = "� ����� ��� �������, ���� ������ � ������������� �����, ��� �� ���� ����� - �� ��� ��?";
		link.l1.go = "Francis_business_1";			
		break;

		case "Francis_business_1":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_01.wav");
		dialog.text = "��, ��, ������� ������ �� ����� ���� �����.";
		link.l1 = "...";
		link.l1.go = "Francis_business_2";			
		break;

		case "Francis_business_2":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_02.wav");
		dialog.text = "�, ��, ���� ���� �� ��� ���� ��� �����.";
		link.l1 = "...";
		link.l1.go = "Francis_business_3";			
		break;

		case "Francis_business_3":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_03.wav");
		dialog.text = "�� �� �� �������, ��� ����� ������� ����, �� ��� ��?";
		link.l1 = "...";
		link.l1.go = "Francis_business_4";			
		break;

		case "Francis_business_4":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_KEY_BUSINESS_15_01.wav");
		dialog.text = "...";
		link.l1 = "�� ������� �� � ����� �������� ������.";
		link.l1.go = "Francis_business_5";			
		break;

		case "Francis_business_5":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_04.wav");
		dialog.text = "�, ������� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_business_6";			
		break;

		case "Francis_business_6":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_09.wav");
		dialog.text = "�� ����� ���������.";
		link.l1 = "...";
		link.l1.go = "Francis_business_7";			
		break;

		case "Francis_business_7":
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_10.wav");
		dialog.text = "��� ����� ��� ������ �������.";
		link.l1 = "...";
		link.l1.go = "Francis_business_8";			
		break;

		case "Francis_business_8":
                                          AddMoneyToCharacter(pchar, 2000);
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_11.wav");
		dialog.text = "� �� ���� � ������� ��� ������� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_business_9";			
		break;

		case "Francis_business_9":
                                          AddMoneyToCharacter(pchar, 500);
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_12.wav");
		dialog.text = "��� �����, ������� �������.";
		link.l1 = "...";
		link.l1.go = "Francis_business_10";			
		break;

		case "Francis_business_10":
		RemoveItems(PChar, "PortmansBook", 1);
		PlaySound("interface\important_item.wav");
	                     PlaySound("VOICE\Russian\gotica\FRANCIS\DIA_ADDON_FRANCIS_BUCH_13_13.wav");
		dialog.text = "� ������ ����� ��� ���� ��� �����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Francis_Greg_22";		
		break;

		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Francis_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "�������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Francis_officer";
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
			link.l1 = "�������, �������! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
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