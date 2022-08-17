// ������ ������, �� �� �������� ������
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
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "MainBegin")
			{
				dialog.text = "��, ����������, " + pchar.name + ". ��� ���� ������!";
				link.l1 = "������!? ��� ��?";
				link.l1.go = "SJ_talk";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "MeetTonzag")
			{
				dialog.text = "����������, " + pchar.name + ". � ��� � ����� � ���� ����� - ���� ��� ��� ���������. �, ����, �����, �� ����, ��� � �������. � ��������!";
				link.l1 = "������� ������� ������� �� ����� ���, ������!";
				link.l1.go = "SJ_talk_11";
				break;
			}
			dialog.text = "������ ����. � ��� �� ��� ����?";
			link.l1 = "���. ��������, � ������. ����� ���� ��������. �� ��������.";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "SJ_talk":
			dialog.text = "�� ���� ���� ��� ���� ������. �� ��� ��������� ��� - ������. ������ ������.";
			link.l1 = "��� ��� ��! � ���� ��� ���� ������... � � ���� � �� ����� � ���� �����. �� ������� �������� �� ��� �� �������.";
			link.l1.go = "SJ_talk_1";
		break;
		
		case "SJ_talk_1":
			dialog.text = "����� ������ �������, � ��������� �� ��������� ���� ������� ��������, ��� ������� ����������� ������ ������ ������ ����. �����������, ��� �� ���� ����� ������� ����� �������, ��� ���-�� ��������, � ���������� �� ����� ������� ���������� �� �������. �, ��� ������, �� ���.";
			link.l1 = "��� �����. � ��� ��������� � ����������� ������ ����, �� ��� �� ����� ��� ��� �� �������... ������� �� �������.";
			link.l1.go = "SJ_talk_2";
		break;
		
		case "SJ_talk_2":
			dialog.text = "����� ���� �����, ������� ������� ������ ������������ ������ - ��� ������� ���� ������ �� ���������. � �������� ������ ������ � ����... ����� ���� ��, ��� ���� �� ������ � ���� ������� ��� � �������� ���� ����. �������, ��� �������� ��� ������ - � ������� ������� ��, ��� ����� ��. ������ ���� ������ ��� ������ �� ��������...";
			link.l1 = "�� ��� - ����? �������...";
			link.l1.go = "SJ_talk_3";
		break;
		
		case "SJ_talk_3":
			dialog.text = "��. � ���� �� ������� ��� �������� � �����, � �������� ������ ������, ��������, �� ��� ����� ��������. � ������� ���, ������ ����� � �����, � �������, ������ ��� �� ����� �������� ������. �� ���� ��� ����� ��� �������� ������... ��� � ������ ���. ������ �� ������������ � ���� � ����, ��� ��������� �������. ����� �����, ��� �� ������� ���.";
			link.l1 = "��� ���� �������� ������ �� ������� - ������ ��������?";
			link.l1.go = "SJ_talk_4";
		break;
		
		case "SJ_talk_4":
			dialog.text = "��, � �����, ��. �� ������ ���, ������, ����������� - ��� ������ �� �����, � ��� ������� ��������� �������� ����������, � ���������� � �������� ������ ��� ���������� ���� - ������� ������������ �����, �� �������� ��������.";
			link.l1 = "��� ���-��...";
			link.l1.go = "SJ_talk_5";
		break;
		
		case "SJ_talk_5":
			dialog.text = "������-��... �� ���, ������� ��������� � ��� ����?";
			link.l1 = "� ������ �� � ���? ����� ���� �� ����� ������? �� ���� ����, � � ���� ������.";
			link.l1.go = "SJ_talk_6";
		break;
		
		case "SJ_talk_6":
			dialog.text = "������ ���, ������, �� � ���� �� ����������. �� �������, ������� ����� ������ ����� ��� ������������ ��������� �� ��������, �� ������� �������� � ������� ����������, �� �� �������� ���� �� ���������. ���� � �� ����������� ������, ��� ��� �������.";
			if (pchar.Ship.Type == SHIP_NOTUSED)
			{
				link.l1 = "� �������. ����� � ���� ����. ��� ������ ����, ������� ��� ����������, �� � ������� �� ��������.";
				link.l1.go = "SJ_talk_7";
			}
			else
			{
				link.l1 = "� �������. ����� � ���� ����, � ������� ����.";
				link.l1.go = "SJ_talk_8";
			}
		break;
		
		case "SJ_talk_7":
			dialog.text = "�� ��������� �� ������ �����. ����� ���� ������� ����� ��� ������, � ������ ���� ���� ���������� ������ � ����� �������� �� ����� �������. ��� �����, ��� �� ��� � �������� �� ������. � �������� ������� �� ������ � ������� ���� � ���������� ����������� ���� ������.";
			link.l1 = "�������! � � ����� �� ��������.";
			link.l1.go = "SJ_talk_9";
			pchar.Ship.Type = GenerateShipHand(pchar, SHIP_CAREERLUGGER, 12, 580, 30, 800, 20000, 16.5, 65.5, 1.6);
			pchar.Ship.name = "������";
			SetBaseShipData(pchar);
			pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
			SetCrewQuantityFull(pchar);
			pchar.Ship.Crew.Morale = 80;
			pchar.Ship.Crew.Exp.Sailors = 90;
			pchar.Ship.Crew.Exp.Cannoners = 70;
			pchar.Ship.Crew.Exp.Soldiers = 70;
			SetCharacterGoods(pchar, GOOD_BALLS, 100);
			SetCharacterGoods(pchar, GOOD_GRAPES, 100);
			SetCharacterGoods(pchar, GOOD_KNIPPELS, 100);
			SetCharacterGoods(pchar, GOOD_BOMBS, 100);
			SetCharacterGoods(pchar, GOOD_FOOD, 100);
			SetCharacterGoods(pchar, GOOD_POWDER, 300);
			SetCharacterGoods(pchar, GOOD_WEAPON, 60);
			SetCharacterGoods(pchar, GOOD_MEDICAMENT, 60);
		break;
		
		case "SJ_talk_8":
			AddMoneyToCharacter(pchar, 15000);
			dialog.text = "��, � ���� �������� ���� ������ �� ������. ��� 15 000 - ������ � ���� �� ������ ������ ���, � ���������. ����� ��������.";
			link.l1 = "�� ����. ����� ������. ���� �� �� ��, ��� �� � ��� ������ ��� �� ������������ ��.";
			link.l1.go = "SJ_talk_9";
		break;
		
		case "SJ_talk_9":
			dialog.text = "�����, " + pchar.name + ", ��� ���� ����. � ��������� � ���� �� ������� ������������. ���� � ���� ������ ����������� - ����������� �����. ���������!";
			link.l1 = "�����, ������!";
			link.l1.go = "SJ_talk_10";
		break;
		
		case "SJ_talk_10":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 10);
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-13");
			pchar.questTemp.HWIC.Self = "HuntFleetwood";
		break;
		
		case "SJ_talk_11":
			dialog.text = "�� ���������� �������� � ���� �������� ���� ���� ������ - �� ������� ������� ���� � ��������. � ������ ������ � �����. � ���� � ���� ��������� �������� - �� ����� ���������� ����... ���� ����.";
			link.l1 = "�� ������� �������! ������, ������...";
			link.l1.go = "SJ_talk_12";
		break;
		
		case "SJ_talk_12":
			DialogExit();
			GiveItem2Character(pchar, "cirass7");//���� ����
			sld = characterFromId("Merdok");
			LAi_SetOwnerType(sld);
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			AddQuestRecord("Holl_Gambit", "3-35");
		break;
		
		case "Tonzag_hired":
			dialog.text = "�������, � ���� ���� � ���� ����. � ��������� ����� ���� �������, �� ����, ��� ��� ������ ���� ���� � ���� ��������� �� �������� ���. ������ ���� � ���� �������� �� ������� - �� ���������.";
			link.l1 = "� �������������, ������! ����� ���������� � �������!";
			link.l1.go = "Tonzag_hired_1";
			link.l2 = "������, � �� ���� ����������� ���� � ���� ������ �����. ������� �� �����������, �� � �� ���� ���� ��������� ����������� �����.";
			link.l2.go = "Tonzag_exit";
		break;
		
		case "Tonzag_hired_1"://������� - � �������
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			npchar.OfficerWantToGo.DontGo = true;
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			LAi_SetOfficerType(npchar);
			npchar.greeting = "tonzag_hire";
			NextDiag.CurrentNode = "tonzag_officer";
			npchar.quest.meeting = true;
			npchar.HoldEquip = true;
			LAi_SetImmortal(npchar, false);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
		break;
		
		case "Tonzag_exit":
			dialog.text = "��, ��� �������, " + pchar.name + ". �����. �����, ��� ����������. ������� ���� � ����� ��������!";
			link.l1 = "� ���� ����� ��������, �������!";
			link.l1.go = "Tonzag_exit_1";
		break;
		
		case "Tonzag_exit_1":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			DialogExit();
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "tonzag_officer":
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
			NextDiag.TempNode = "tonzag_officer";
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
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, � �����. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
			link.l1 = "�������, ������! � ���, ��� �� ������ � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ����� ������������?";
			link.l1 = "������� �����. � ���� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "23");
			npchar.quest.Tieyasal = "teleport";
		break;
	}
}