// ������� ������ - ����� ����-������ � ��������� ������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
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
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "baker":
			dialog.text = "��������� ���, �������! ���� �� ����, ����� � ��� ��� �����...";
			link.l1 = "���� � ����: ������ �� � ������, ��� ��������� � ������� ������� � ��������. �� � ��� ���� ���� ��������� �� ��� �����.";
			link.l1.go = "baker_1";
		break;
		
		case "baker_1":
			dialog.text = "��� ���� �������, �������?";
			link.l1 = "���� ���������� ���� �������. �� ��� ����� ��������, ��� ������. ������ ��� �� ��� ������ ����� ������. � ������ � �������� ������. ��, ��� �����, �������� �� �������� �������� ��� �����. �������, �� ��� �� �� ��� ����������? ������ ����?";
			link.l1.go = "baker_2";
		break;
		
		case "baker_2":
			dialog.text = "��... �� �� ����?";
			link.l1 = "��� �� ����! ��� � ���� ���� '�� ����', ���� �� ����� ��� �����! ���� ���������� �� ������� ��� �����, ������� ��, ��� ����� �������� ����� ����. �����-������ ������, ���������. ����� ���� ���-�� ���� � �������� ��� �������... ��������! � ���-�� �� �����. �� ���, ��������, ��� ����� - ���? �� �� ���� ������� ���!";
			link.l1.go = "baker_3";
		break;
		
		case "baker_3":
			dialog.text = "��-�-�! �� ������ �� ������. ������ �� �� �� ������, � � �� ���� �������...";
			link.l1 = "���-���. ���������� ��� �������� � ��������. ������, ����� ������� ������ ������, � ������� ��� ���� ���������... ����������, ����� ���?";
			link.l1.go = "baker_4";
		break;
		
		case "baker_4":
			dialog.text = "��� ���, �������... � ��� ���� ����.";
			link.l1 = "�������, ��� ��� ������������ ��� ��������� ��������. �� ����� �� ���� �������. ��� �� �� ������� ���, ��� ���� ������� �� � ������������. ���������� ��� ���, ��� ������, � � �������, ��� ��� ������. ��������, � ��� ����� �����, � ��� �� �������� ������ ��� ����������. ������ � ������.";
			link.l1.go = "baker_5";
		break;
		
		case "baker_5":
			dialog.text = "�� ���! ������ ����� ��� ������ �����. � ���� ����� �� ��� ������ ��� ����. ������� � ��� ���� �� �������� ���������. �������, '����������'.";
			link.l1 = "���������. ����� ���������.";
			link.l1.go = "baker_6";
		break;
		
		case "baker_6":
			dialog.text = "�����! ��� ���������� ��� ������� � �����, ���� � �� ����� �� ��������. �� ��� � �������� ������������� ����� ��� ������ ��������������, ������� � ���������� �� ������ ������. ����� ����������� �� ������ � �������, ���������� �������������� ��� ����\n���������� ��������� �� ����� � ����������� ����� � ����� � ���� �������. ������� ����� '��������' ��� ���� �������������. ����� �������, ��� ������� �������� ��������� �������� � ������ ��� ���������, ������ �������� ��������� �������, ������ ��� ������ ��...";
			link.l1 = "�� ������� ������ ���������?";
			link.l1.go = "baker_7";
		break;
		
		case "baker_7":
			dialog.text = "��� ��� ��������� ���. � �� ������, ��� ��� ������ ����� ��-�������. ������� �������. � ��� ��� ��� �� �������� �� ������� ��� �����, � ����� ���� �� ������. � �� ����� �����, ��� ���� ���� �����-�� ������� ����, ������ ������� ������ �� ������\n� ��� � ��������� ������� ��� �������. ���� ��� ��������� � �����, � ������ �����. ����� �����, ��� � ��� ������������ ����������. � ��� ������, �������� ���� � ����� �������. ��-����, � �������� ���� � ���� ���� �������.";
			link.l1 = "������. ��� �� ���� ������ ����� ������... �-�-�, ��������? �� �������� �� ����������� ������ ��������?";
			link.l1.go = "baker_8";
		break;
		
		case "baker_8":
			dialog.text = "�� ����. ���������� �� �������� � ���� ������ ������� ���. �� � ��� ����� ���, ��� ����, � ������� � ����, ��� ������. � ���� � �������� ���� ��� ������, ������� ��� ��� ����� �������� ����� ����. � ��� ��������, �� ������ ������, � ������ ���� � �����\n��� ��������... ��� ������� � �������� ������, � ��� ��� - ��� ���������� ������������� ������������ �����... ��� ����, �������������� ������ ����������...";
			link.l1 = "����! ��� ����� ���������?";
			link.l1.go = "baker_9";
		break;
		
		case "baker_9":
			dialog.text = "�-�-�! ��� ����� ��������� �������. ���, ��� ������ ������ ������. ����� �������� ���, ��� '�������� � �����'. ��� ����� ����� ����� ����� ������. ������� ����� �� �����... ����, � ��� ��������! ��, ��������, ����� ������� ��� �����\n������ �� �� ��� ���� ��� ������! �������� ������! ��� ��� � ���� ���� � ������� ��� ��� ��������� �� ��������. ������ ����, ��� ���� �������� ����. ������ �������! �� ��������� �������, ������ ������ �������\n� ��� ��� ��� ����� ���. �� ��� ���������� �������� �.�. ����� ��� �������? ������, ��� ���� ����� ����� ���...";
			link.l1 = "����������! ��� ����� ��� ����������� ��������� � ���������� ��������. � �� ��������� � ���� ����������, ��� ������ - ��� ��� ��� ���������, �� ��� ���, ���� � �� ��������� �� ���� ���� �����. ������ �����������, �������, � ���� �� ����� �� � ������������.";
			link.l1.go = "baker_10";
		break;
		
		case "baker_10":
			DialogExit();
			sld = characterFromId("Baker_Cap");
			LAi_SetImmortal(sld, false);
			sld.lifeday = 0;
			//sld.ship.hp = 0;
			//sld.SinkTenPercent = true;
			bQuestDisableMapEnter = false;
			GiveItem2Character(pchar, "shark_teeth");
			GiveItem2Character(pchar, "letter_jess");
			GiveItem2Character(pchar, "letter_baker"); // ��������� �������
			ChangeItemDescribe("letter_baker", "itmdescr_letter_baker"); // Addon-2016 Jason
			AddQuestRecordInfo("Legend_CapBucher", "1");
			AddQuestRecordInfo("Letter_jess", "1");
			AddQuestRecord("Shadows", "5");
			pchar.questTemp.Saga.Shadows = "islatesoro";
			// � �������
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.CompanionDisable = true; //������ � ����������
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			npchar.DontClearDead = true;
			NextDiag.CurrentNode = "Baker_officer";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			AddCharacterExpToSkill(pchar, "Sailing", 50);
			AddCharacterExpToSkill(pchar, "Fortune", 100);
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Baker_officer":
			dialog.text = "��, �������?";
			Link.l1 = "������ ��� ������!";
            Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Baker_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ���� ����������?";
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
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}