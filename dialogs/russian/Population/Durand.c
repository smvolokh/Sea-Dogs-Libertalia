// ���� ����� - �������� ������ �� �����, �������
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
			dialog.text = "��, ���������� �� ��������� ���!";
			link.l1 = "������, �������, ���-�� ��������� �������. ���� ����� "+GetFullName(pchar)+", � ��� ��� ���?";
			link.l1.go = "Durand_1";			
		break;

		case "Durand_1":
			dialog.text = "������ ���������, ���. ���� ����� ����������� ��������.";
			link.l1 = "��! �����? ��������, �������� � ����. �� ������ ������ �����...";
			link.l1.go = "Durand_2";			
		break;

		case "Durand_2":
			dialog.text = "������ �����, �������? �� �� ���� �� �� ����������� ����-������� ��������?";
			link.l1 = "�� �������� ��! � ����� ���� � ����� ������. ������� � �� �����. ������ ������ ����� ����� ������ �� �����. ������� ������?";
			link.l1.go = "Durand_3";			
		break;

	case "Durand_3":
			dialog.text = "������� ������? ������� �����! ��� �� � ���� ������ ��������, ������� � ��� ����� ������� ���� �� ����� ���������!";
			link.l1 = "��� �� ���������? ��������� ���� �� ���������!";
			link.l1.go = "Durand_4";			
		break;

	case "Durand_4":
			dialog.text = "���������? ��... ��, ������ �����. ���� ���� ���. ����� � ���-�� ����� �������� � ������ ���������� � �������. �� ��� �����: ''������� ������, ����� ���� �������� �����!'' - ���, ��� �� �� ���! ׸�� �� ������ ����� ��������� � ��� �����������! �� �� �����, ���������� � � �����, � ���� ���� �� ������, ������ � � ����, � ��� ������. �������� � ���, ������, � ��� ���� ����������� ������!";
			link.l1 = "������? ������� ��! ��� ����� ����� �� ���?";
			link.l1.go = "Durand_5";			
		break;

	case "Durand_5":
			dialog.text = "���, �� ���������, � ������ ������!";
			link.l1 = "�����-�����. ��� ���� ������?";
			link.l1.go = "Durand_6";			
		break;

	case "Durand_6":
			dialog.text = "���, � ��� ��� �... ��, ��! ���� ����������� ������ � ��� ������� ����! �� ����� � ������� �����, ����� ������ ��� ����� ����������� �������, ��� ����� ����� �����... ����������� ������, � ��� �� ���� ��� ���������� ������ ������ ����������� ����������! ������� �� ������ � ��� �������:  ''������ ���������� ���������� ���������! ������� ����� ��� ����!'' - �, �������, �������� ������ �� ���������, ��� ������� ����� ����� � �� ��� ����� ��������...";
			link.l1 = "��, � ����������� ����� ����� �� ������?";
			link.l1.go = "Durand_7";			
		break;

	case "Durand_7":
			dialog.text = "�� ����, "+pchar.name+"! ��� ������, �����-�� �� ����� ��� � ����� � ���������� ��������, � ������ � ����� � ���� �� ����� ������� ���... ���� ���� ������� �� ���������, ���� ��������� ����� �� ��������� �� ��������...";
			link.l1 = "���, ������� ��������...";
			link.l1.go = "Durand_8";			
		break;

	case "Durand_8":
			dialog.text = "� ��! ��� ���, ������� �� ���: ''������ ����������! ������� ����� ��-��������, � �� �� ���� ��� � �������!'' - � ��� ����� ����������� ���� ������, � ��� ������������ � ���� ��� ������ �� ����� �������! ��������� �����������, ����� ����, �������� � ���� �� ���� �����������. ���������� ����� ���� �������, ��� ������ �� ����� ����������� ����� ���� ���� �������. �������� �� � ��� ������ ����������. � �� �����, ��� ��, �����! ������ � ���� �������, � ���! ������ �������� �� ��� � ����������, ��� � ����� �����, ��� ��� �� � �� �����.\n� � �������� ���, ��� ����� ���� ������, ��������� ��� �������� � ������ � �����������. ������ ������ �� ���� � ������, � ����� ����� ����� �� ����� �������� ���������! ���, ��� ������� ���������, �������� � ���, ��� ���������, ������. � � ����������, ��� �� � ������� ���� ����, �� � �������� ���� ������ - ��� ��� ���� ����� ���������... �� ��� � ��������. �� ������ �� ����� ��� �������� ������� �����, ��� � ��� ������ �������, ������ ��������� ���� ����� ��� ���������� ������ �� ���������! �� ��� �� � �������� ��������� ������������� �� �����.";
			link.l1 = "���, �������� �������... ������, ������ ��� �����������, ��� �� ������� ��������. � �� ��� � ������� ����� �� �������? �����, ����� � ���� � ������ � ���� ������!";
		link.l1.go = "Durand_9";			
		break;

	case "Durand_9":
			dialog.text = "������ �� ������, "+pchar.name+", ���� � ��� ������ ������������� � �����! ��... ��� ������ ���������� ���� ����. �� �������, � ���� � ��� ����? ����� � ������, ����� �����������... ��� ���� ������, ������� � ������ �����������. ������ ���� �� ����� � �������� ��� ������ ���.";
			link.l1 = "����� �������� ����� ���� ������ �� ������? ������� �� ������?";
		link.l1.go = "Durand_10";		
		break;

	case "Durand_10":
			dialog.text = "��� ���, ���, � ���� ������ ���������� � ������ ������� � ���� ����� �� ����. � ������ � ����� ����� ����� ����.";
			link.l1 = "���! ����� ���������. �����, ���� � ������� �, �� �� ������� �� ��� � �������?";
		link.l1.go = "Durand_11";		
		break;

	case "Durand_11":
			dialog.text = ""+pchar.name+", ������ ��������� ��� ����? �� ����� �������� � �� ������ � ���� � ������� �����, � � ����� ���� � ����� � �������� ������� ����������!";
			link.l1 = "�����, �� ����� ������ ������� ������, �����?";
		link.l1.go = "Durand_12";		
		break;

	case "Durand_12":
			if(makeint(Pchar.money) >= 100000)
			{
     		dialog.text = "��, �������, ���! � ��� ��������?";
			link.l1 = "����� ������, ����� ������������ � �� ��������� � ��������.";
			link.l1.go = "Durand_13";
			link.l2 = "������, � ��������� ������ ����� � �� ������� � ����� ���������.";
link.l2.go = "Exit_Durand";	
			}
			else
			{
              dialog.text = "��, �������, ���! � ��� ��������?";
			link.l2 = "������, � ��������� ������ ����� � �� ������� � ����� ���������.";
link.l2.go = "Exit_Durand";					
			}
		break;

	case "Durand_13":
		dialog.text = "� �������� ���� ��� ����, �������!";
		link.l1 = "�����!";
		link.l1.go = "Durand_hired_1";		
	break;

	case "Exit_Durand":
		dialog.text = "��, ���� � ����������� �����, ���. ���������� ������ ��� ��� �������!";
		link.l1 = "������ ����� ������ �� ��������!";
		link.l1.go = "Exit_Durand_1";		
	break;


	case "Second time":
		if(makeint(Pchar.money) >= 100000)
		{
dialog.text = "���, �� ����� ������ ��� ������ ����� �����?";
link.l1 = "��, ����� ������, ����� ������������ � �� ��������� � ��������.";
		link.l1.go = "Durand_13";
link.l2 = "��, � ����� ����� ������ �����. ������� �������.";
link.l2.go = "Exit_Durand";	
		}
		else
		{
dialog.text = "���, �� ����� ������ ��� ������ ����� �����?";
link.l2 = "��, � ����� ����� ������ �����. ������� �������.";
link.l2.go = "Exit_Durand";					
			}
		break;

case "Durand_hired_1"://����� - � �������                                              chrDisableReloadToLocation = false;//������� �������
DialogExit();
DeleteAttribute(npchar, "LifeDay");
AddMoneyToCharacter(Pchar, -100000);
npchar.quest.OfficerPrice = sti(pchar.rank)*500;
npchar.OfficerWantToGo.DontGo = true;//�� �������� ����
npchar.loyality = MAX_LOYALITY;
AddPassenger(pchar, npchar, false);
SetCharacterRemovable(npchar, true);
npchar.Payment = true;
npchar.DontClearDead = true;
LAi_SetOfficerType(npchar);
npchar.greeting = "Gr_Diego";
NextDiag.CurrentNode = "Durand_officer";
npchar.quest.meeting = true;
npchar.HoldEquip = true;
LAi_SetImmortal(npchar, false);
TakeNItems(npchar, "Rumm", 1);
LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Durand_officer":
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
			NextDiag.TempNode = "Durand_officer";
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
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, �� ��������. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
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


		case "Exit_Durand_1":
			NextDiag.CurrentNode = "Second time";
			DialogExit();
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