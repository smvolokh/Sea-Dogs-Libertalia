// ����� ������ �������� �� 
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
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_HALLO_15_00.wav");
			dialog.text = "...";
			link.l1 = "��� ����?";
			link.l1.go = "Wolf_1";			
		break;

		case "Wolf_1":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_HALLO_08_01.wav");
			dialog.text = "��, � ���� ���� �� �� �������!";
			link.l1 = "...";
			link.l1.go = "Wolf_2";			
		break;

		case "Wolf_2":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_HALLO_08_02.wav");
			dialog.text = "��� ���� ����� �����?";
			link.l1 = "...";
			link.l1.go = "Wolf_3";			
		break;

		case "Wolf_3":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_15_00.wav");
			dialog.text = "...";
			link.l1 = "� ���� ������������� � ���.";
			link.l1.go = "Wolf_4";			
		break;

		case "Wolf_4":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_08_01.wav");
			dialog.text = "������ �� � ��� � �� ���� ������ ������, � ����� ��� �� ��������� ���� ����� - ���� ����������.";
			link.l1 = "...";
			link.l1.go = "Wolf_5";			
		break;

		case "Wolf_5":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_08_02.wav");
			dialog.text = "�� �� ����������, ��� ���� ��� ������ ������� �������� �������� ������.";
			link.l1 = "...";
			link.l1.go = "Wolf_6";			
		break;

		case "Wolf_6":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_08_03.wav");
			dialog.text = "� ��������� ����� �� ������� ������� ������ � ���� ������ ������ ������� ����� �� ������� ����.";
			link.l1 = "...";
			link.l1.go = "Wolf_7";			
		break;

		case "Wolf_7":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_08_04.wav");
			dialog.text = "� ��� - �� ��� ����� ����, �� ��������� ������ ����������.";
			link.l1 = "...";
			link.l1.go = "Wolf_8";			
		break;

		case "Wolf_8":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_15_05.wav");
			dialog.text = "...";
			link.l1 = "����� ������ ���, ��� ����� ������� �������� � �����.";
			link.l1.go = "Wolf_9";			
		break;

		case "Wolf_9":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNAJOIN_08_06.wav");
			dialog.text = "�� ������ ���� �������...";
			link.l1 = "...";
			link.l1.go = "Wolf_10";			
		break;

		case "Wolf_10":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNALEARN_15_00.wav");
			dialog.text = "...";
			link.l1 = "�� ������ ������� ���� ���� - ������!";
			link.l1.go = "Wolf_11";			
		break;

		case "Wolf_11":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_WANNALEARN_08_01.wav");
			dialog.text = "� ���� ������� ���� �������� ��������� � �����, ���� ������, ������� ��� ������ ������ ������.";
			link.l1 = "...";
			link.l1.go = "Wolf_12";			
		break;

		case "Wolf_12":
	                                   PlaySound("VOICE\Russian\gotica\WOLF\DIA_WOLF_BENGAR_NOCHNICHT_15_00.wav");
			dialog.text = "...";
			link.l1 = "� ������� ��� ����.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
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