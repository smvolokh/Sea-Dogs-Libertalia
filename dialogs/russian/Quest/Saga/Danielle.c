// ������� ���� - ���� ��������� �����
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sTemp, sAttr, sGun, sBullet, attrL;

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
		case "First time": //������ ������� - ����������
			PlaySound("VOICE\Russian\saga\Denny Hawk-02.wav");
			dialog.text = "������, ���������! ��� �������, ��� ����, ��� ������� ���� �����.";
			link.l1 = "�� ����� �������? �������, ���� ��� ���������� ���� � ���� ������ �������� ���� ����� ���������� �������.";
			link.l1.go = "meeting";			
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			PlaySound("VOICE\Russian\saga\Denny Hawk-01.wav");
			dialog.text = "�� ����� ������ �� ��� ����, �������. ����� ���� �� ���� ����� ������� ��������. � � ���� � ���� ���������� ��������. � ��� �� �������. � ����� ���� ����� ��������� ����.";
			link.l1 = "��� ��� ��! ��� �� � ���� �� ����� ����... �-�-�, ����� ����, ��� ������� ��� ������ ��� ����������� ������ �������?";
			link.l1.go = "meeting_1";
		break;
		
		case "meeting_1":
			dialog.text = "��� �����. ����, ������ ������ ��� ��� �� ����� �������� ������, ���, ������� � � � ���, �� ������������ ���� �� ���� ����, ��� ����� � ���� �� ��� ����, �� ��� ������. ��� ��� ����� � ����, �����!\n� ����� �������� �� ��������� � �����, ��� � ���� ��������, ��������� ������ �� ������ ����� ���� � ������� �� ��������. � ������, ��� �� ������ � ���������, �� ������ �������, ��� ��� �� ���. � ���������� ��� ������ ��� ��� �����. ���������� ������� �� ���, �� ��� �� � ������ ��� ���� ����� �����������\n�� ������������� ������� ����� ����� ���� � ������� ������� ��������? ��� ������ ��������?";
			link.l1 = "������������, ����� ����, ��������. �� � ���, �������, �����, ���� ������ �� ������ ������������� �� ���� ����� �����������. ����� � ����� ��� ���, ��� ��� ��������. ���� ��� ���� ��� ������� - ��������. ���� ������� ������, ������ � ������. ���� ����� ��-��������.";
			link.l1.go = "meeting_2";
		break;
		
		case "meeting_2":
			dialog.text = "�-��-��, ����� �� �������! �� ����� ����, �������... �������� � ���� � ������ �������. ����, ��� �� �� �� ���������, � ���� ���� ������. � ���... ����� �� '��'. ������, ��� ���� ����� �� ���������. �� ����� ���, � � ���� ����������� ����. � ��� ���� ����� ����. ������ ���� � ���� � �������, �� ���������. ���� �� ������ ������, ���� ������� ���� ����� � �������.";
			link.l1 = "������ ���� ��� �����������... �����. ������� ������, ��� �� ���������� ��������� ���� � ��������. ���� ������� ������ �����-������ �����������?";
			link.l1.go = "meeting_3";
		break;
		
		case "meeting_3":
			dialog.text = "�������, �� ����� ����������, ����� �������� �������� �� ���. ���� ������� ������, ��� ������ �������, �� ������ ������� ��������� �����, ������� �� �����. ����� ����� � ����� ������������� ����� �� �����. �� ��� � �� ����� �������, ��� ��� �� ��� �� �������� � ����� �� �������. ��� ��� ����� ����� ������� ������� ����\n�� �� ����� ��� ������. � ��� ���� ���� ����� ����� - ����������. ����� ���-�� �������� ��� ������-�� ����������, ������� ��� ��� �������. �� � � ���� ��� ����� ������ �� ������. � ���� �� ����������� ���� ��� ��� ������, ��� ����� ������ ������� �� ������������. ��������� �� �� � ���. ����� � ����� �� ����� ����� �����������.";
			link.l1 = "��� ���-��! ����� ������� ���� ������������. ��� ��������� ��������� �������, � ������� ����� ���� �����?";
			link.l1.go = "meeting_4";
		break;
		
		case "meeting_4":
			dialog.text = "������� ��������� � ������� ��������. ����� ����� ��������� �� ����� ������� � ����������� �� ����� �� ������ ������. � ������ ������, ���� ��� �� �������. � �������� ����, ������� ������� ������ �������� ��� ������ ����, ������������� ����� �������� �� �������. ���� � ��� ���� ���. ������ ����������. ������, �������� ����, � ������ �����.";
			link.l1 = "���������. �����, ���������� � ����. ��������� � ������� - ����� ������, ��� ������ ������. �� ������?";
			link.l1.go = "meeting_5";
		break;
		
		case "meeting_5":
			dialog.text = "�����������! �������, ������. ����� ����, ��� ��� �������� �������� �� �������-��-���, � ������ � �����, ��� �����������. � ���� ��, � �� ���������� � ���� ���������.";
			link.l1 = "�������. ����� ������������ �� �������.";
			link.l1.go = "meeting_6";
		break;
		
		case "meeting_6":
			dialog.text = "����, �������!";
			link.l1 = "...";
			link.l1.go = "meeting_7";
		break;
		
		case "meeting_7":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
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
			NextDiag.CurrentNode = "Danielle_officer";
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			AddQuestRecord("BaronReturn", "2");
			Saga_CreateSnakeEye();
			//�������� �������
			pchar.questTemp.Saga.BaronReturn.Indian = "indian_"+(rand(10)+1);
			pchar.questTemp.Saga.BaronReturn.Amulet = "amulet_"+(rand(10)+1);
			pchar.questTemp.Saga.BaronReturn.Obereg = "obereg_"+(rand(10)+1);
			// �� ������� � ���������
			npchar.quest.talk = "dolly";
			pchar.quest.Saga_Dolly.win_condition.l1 = "location";
			pchar.quest.Saga_Dolly.win_condition.l1.location = "Pearl_jungle_03";
			pchar.quest.Saga_Dolly.function = "Saga_DannyTalk";
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			npchar.greeting = "danny_1";
		break;
		
		// � �������� � ��������
		case "Dolly":
			dialog.text = ""+pchar.name+"! ����! � ������ ���� ����� ��������� ��������, ��� �������� �������� ��������� ������. ����� ������� �������� �����. �����!";
			link.l1 = "...";
			link.l1.go = "Dolly_1";
		break;
		
		case "Dolly_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "item", "torch1", "Saga_ShowDolly", -1);
		break;
		
		case "Dolly_2":
			dialog.text = "��! ������: ������ �������� ������. ������ ������ ����������...";
			link.l1 = "����... ���� ������� ������� ����������, �� ��������?";
			link.l1.go = "Dolly_3";
		break;
		
		case "Dolly_3":
			dialog.text = "� �������� ��� �������� ����� - �������� � ����. � ������ ������ ����� ������� ����. ��� ��� ����������. �����, ������, ������� ��� ������!";
			link.l1 = "�����!";
			link.l1.go = "Dolly_4";
		break;
		
		case "Dolly_4":
			chrDisableReloadToLocation = false;//������� �������
			DialogExit();
			LAi_SetOfficerType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			npchar.dialog.currentnode = "Danielle_officer";
		break;
		
		// � �������
		case "SnakeEye":
			dialog.text = "��, ��� �������, "+pchar.name+"? ��� ���� ������� ���� ����������� �������������? �� ���� ���-������ ����� �� ��� �������������?";
			link.l1 = "�� ����� ������������, �����?";
			link.l1.go = "SnakeEye_1";
		break;
		
		case "SnakeEye_1":
			dialog.text = "��... ������ ������ ����-����. ��, ��, ��, �������, �����. �� �� ������ ���� �������� - � ����� �������� �� ������ ����. ���� ���, �� � ��� �����, ������-��. ��? �� ���� ������� ���������� � ���, ��� ���� ����������� ���������?";
			link.l1 = "������� ���������... ��, ������ �������� ����� ����� ������. ���������� �������� ���: ����, ���� �������� �� ��������� �� ���� � �������, ��� �����, ������� �� ������� ������, �������� ����, ���� �� ��� ����, ��� ����� ���������� ������, ��������� ���������� �������� � ������������ � �������.";
			link.l1.go = "SnakeEye_2";
		break;
		
		case "SnakeEye_2":
			dialog.text = "";
			link.l1 = "�� ���� ��� �� ���� ����������? � �� ��� ��� ��������, � ���� � ������� ��� � �������. �� ��������, ��� ��� ������� ����� - � ���� � �����������.";
			link.l1.go = "SnakeEye_3";
		break;
		
		case "SnakeEye_3":
			dialog.text = "������, ����������. � ������ �� ���� ��� ��������. ���������.";
			link.l1 = "�� ������, ��� ����� ������ ��������� ������, �� ������ ��� �� ����� ��������, ��� �� ����������� ��������, �� ���� ����, ��� ��������� - ����� ��� �������� ��� �������� - ������ � �������� ���. ������ ������������ ������, ��� ������, ��� ��������� ��� ����� ������ ��������� ������� � ������ ����� - �����������������.";
			link.l1.go = "SnakeEye_4";
		break;
		
		case "SnakeEye_4":
			dialog.text = "�������, ������� ���� ������... ���� ��� � ������� ��������� � ��������� �����, ����������� ������ ����, ��� ��� ��� �������� ��� ����� �� ������ ����������...";
			link.l1 = "��� �� ������ �������?";
			link.l1.go = "SnakeEye_5";
		break;
		
		case "SnakeEye_5":
			dialog.text = "���, ������, "+pchar.name+", �� ������� ��������. ���, ������������ � ������ ���������. �� ��� ����� ��� ��� �������? � ������, �����������������? �� �� � ����� ������ ��� ���� � ����� ��������, � ������ ������ ����, ����������� � ����... ������-������!";
			link.l1 = "������� ���� ������, ��� ������� ������� � �������. ����� �� �� ��������� ���������� ������� � � ��� ���������� ��� ����������. ��� �����-��, ��������, � ���� � ����� �����������. ��� ��������, �� �����.";
			link.l1.go = "SnakeEye_6";
		break;
		
		case "SnakeEye_6":
			dialog.text = "���� �����... ������ ���? ���� ������� � ���� � �������?";
			link.l1 = "���. ����� ������, ��� ������� �� ������ ���������� ��������, �� � ���������� ��� ����� �����. ��� � ����� - ���������� ��������. ������� ���� ��� ������ �������� ����� ��� ������, � ����� ������� ����������� ������� �����-�� ���������� ������.";
			link.l1.go = "SnakeEye_7";
		break;
		
		case "SnakeEye_7":
			dialog.text = "�� �������� � ���� ��� �����?";
			link.l1 = "�������. �� ��-������, � ���� �������� ����� ��� �����, � ��-������, �� ���������� �� ��� ��� �������.";
			link.l1.go = "SnakeEye_8";
		break;
		
		case "SnakeEye_8":
			dialog.text = "� �����, ��������� ��� ���� �����? ������ ����� � �������� � ��������� ���...";
			link.l1 = "������������ ���. �, �������, ��������, ��� ���� ������ �������� ��������� � ������� ��� ������, �� �� ��������� �� �� �����, � ������ ������ ��������, ��� �� ������� ������. �� ���-�� ��� �������� ��� ��������� �����? �� ������������ � �� �������������?";
			link.l1.go = "SnakeEye_9";
		break;
		
		case "SnakeEye_9":
			dialog.text = "��, ��������. �� ���������� �� �� �������, ������ ��� ������ �� � �������� ����������� �������. �������, �� ����: ��������� �� �����.";
			link.l1 = "���-���. ������� �� ���������� �������, ������� ������ �����, ������� ��� �������� ����� � ������ ����� ���������� � ������. ������, � ����������. ����.";
			link.l1.go = "SnakeEye_10";
		break;
		
		case "SnakeEye_10":
			dialog.text = "��� ��� ������? � ��� �� �?";
			link.l1 = "� �� ���������� �� ���� ������� �� ��������. �����, � ���� �� �����. ����� ����� ��� ��������. ����������, ��� ��� ���� �� ��������. �, � �����-������, ����������, ���� ���� ��������, ���� ����� ���� � ��� ����� ������������� ��������. �����, ������ ��� � � ������ �� �����.";
			link.l1.go = "SnakeEye_11";
		break;
		
		case "SnakeEye_11":
			dialog.text = "�� ����� ��, ��� � �����. ��� ��, �������, ����������... �����, ���� ��-������.";
			link.l1 = "��� � ������, ��� �� � ����� ������������. � ������ ���� - ��� ����� ��������� �������.";
			link.l1.go = "Dolly_4";
		break;
		
		// ����� ������� � ��������
		case "teleport":
			dialog.text = "�� ���? ������� �����?";
			link.l1 = "��. ������� � �����, � �����������. ������ �������� ��������� - ����������� � ������� � �������� � ������������ � ����.";
			link.l1.go = "teleport_1";
		break;
		
		case "teleport_1":
			dialog.text = "���� �������?";
			link.l1 = "��. ��� �������, ��� ����� ����� ��������� ����������� � �������� ��������� �� ����������.";
			link.l1.go = "teleport_2";
		break;
		
		case "teleport_2":
			dialog.text = "��-��... ������� ������, �� �������� �� ������?";
			link.l1 = "�����, �� ��� �� ��������... �������, ������� �� �� ����, ���� �� ��� ����� �����.";
			link.l1.go = "teleport_3";
		break;
		
		case "teleport_3":
			dialog.text = "� ����� � �����.";
			link.l1 = "�� ����� ���������? �� �� ����� ������������...";
			link.l1.go = "teleport_4";
		break;
		
		case "teleport_4":
			dialog.text = "�� �� �����. � ������ ���� ����������. ���� �� ��� ���������, ��� ���� ������� ��������... ��� �� ��������.";
			link.l1 = "������ ����� � �� ��������. �� ������ �� ������� ����������� �� ����, ���� ������ ���-���� '������' ����. �� �������?";
			link.l1.go = "teleport_5";
		break;
		
		case "teleport_5":
			dialog.text = "�����. ������, ��� �� ����� ��������������... �������.";
			link.l1 = "��� � �������. �, �����: ������, �� ����� �� �� � ������, ��� ������������.";
			link.l1.go = "teleport_6";
		break;
		
		case "teleport_6":
			dialog.text = "�� ���� ��� ����� ������, "+pchar.name+". �����, ����� �� ����� �� ����.";
			link.l1 = "�� �����... ��, ����� �������� � ������� ������!";
			link.l1.go = "Dolly_4";
			npchar.quest.talk = "shadowstar";
			pchar.quest.Saga_Dolly1.win_condition.l1 = "location";
			pchar.quest.Saga_Dolly1.win_condition.l1.location = "Pearl_jungle_03";
			pchar.quest.Saga_Dolly1.win_condition.l2 = "Hour";
			pchar.quest.Saga_Dolly1.win_condition.l2.start.hour = 0.00;
			pchar.quest.Saga_Dolly1.win_condition.l2.finish.hour = 1.00;
			pchar.quest.Saga_Dolly1.function = "Saga_DannyTalk";
		break;
		
		// ����� �������������
		case "shadowstar":
			dialog.text = "������, "+pchar.name+"! ������� ����� �������, ��� ���� ��������� ����� �����-�� �������� ����!";
			link.l1 = "������, ����� �� ������. �, ���� ��� �� ������� � �������, �� ���� ������ ��� ������ �� ��������.";
			link.l1.go = "shadowstar_1";
		break;
		
		case "shadowstar_1":
			dialog.text = "�����... �� ������ ����� �� ������! ����������!";
			link.l1 = "�����, ��� ����. ������� ����� � ����� ������ �� ����. �� ����������� � ��������! ���� ���.";
			link.l1.go = "shadowstar_2";
		break;
		
		case "shadowstar_2":
			dialog.text = "�����, "+pchar.name+". ���-�� ���, ��� ���������... ����� ������ � ���� ��������?";
			link.l1 = "��, ��� �����. ��� ����� ������, �����. ��, ������!";
			link.l1.go = "shadowstar_3";
		break;
		
		case "shadowstar_3":
			DialogExit();
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			DoQuestReloadToLocation(pchar.location, pchar.location.group, pchar.location.locator, "");
		break;
		
		// ������ ����� 
		case "arrive":
			dialog.text = "�-�-�?! ���� ������, ��� �� ��������?! ��, ������! � � �� ����� ������ �� ����� ���� �������� - ���� ��� ��� ����� ���� �����! ������ � ���� ����� ����!";
			link.l1 = "(�����) �����, ����! ���������� ������ ��!";
			link.l1.go = "arrive_1";
		break;
		
		case "arrive_1":
			dialog.text = "�?! ���? ��� �� ������ �������?! �����?";
			link.l1 = "(�����) �� ���� �� �� �������! �� �������� �� �����! ��� ��� ����� � ���� ��� ���������!";
			link.l1.go = "arrive_2";
		break;
		
		case "arrive_2":
			dialog.text = "���� ������, ��� ����� ������� ���... "+pchar.name+"?!";
			link.l1 = "(�����) ��-�... �� �������!";
			link.l1.go = "arrive_3";
		break;
		
		case "arrive_3":
			DialogExit();
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			DoQuestCheckDelay("Pearl_TeleportArrive_1", 1.5);
		break;
		
		case "arrive_4":
			dialog.text = "���, ��� �� �� ���� �������! � ���� �� ������ ���� �������� ������!";
			link.l1 = "� �����... �� ��� �� �� ����� �������, �?";
			link.l1.go = "arrive_5";
		break;
		
		case "arrive_5":
			dialog.text = "�� ����� ����... ��, �� ��� ��� ������ ������ �� ����� ����������...";
			link.l1 = "�����, �� ������ ���? � ������� �������, ��� ��?";
			link.l1.go = "arrive_6";
		break;
		
		case "arrive_6":
			dialog.text = "� ��� �� ���! ���, ����� �������, ��� ������ �������� �� ���������. ��, ��� ��� ���� �������! �� ����� ���� ������� ����.";
			link.l1 = "��� �� ���, ������� ������� ����� ���� �����?";
			link.l1.go = "arrive_7";
		break;
		
		case "arrive_7":
			dialog.text = "����� �� �������, � ��� �� ��� ��� ���������� ������? ����� ����, ��� ������ ������� ����, � ���� ���� ���� ������� - ��� �����-������ ��� ���� � ��������. � ���� ��, ������� ���� ������, ��� ������ ����� ��� � ��������\n� ���� � ������� � ��������� �������� � ��������. �� ��� �� � ������-�� �������? �����������! ��� ���� ���? ���� ���� ������?";
			link.l1 = "�����, ��� ����� ������ ������� - ���� ������ � �� �����������... �� ����� ��������� ���� ����, ����� �����: � ����� ���������!";
			link.l1.go = "arrive_8";
		break;
		
		case "arrive_8":
			dialog.text = "����� ������? ��� ��? ��� ��?!";
			link.l1 = "�� ���� ����� - �� ���, �� ����� ����. � ���� �� ���� � ����� ����� ��������, � ������� ������� �� ���� ��� ��������. �� ����� ������ � ����� ������� ��������� ������� �� �������� ������� �������� ��������, ���� ����, ����������, � ���������. ������� ���� �������� ���� �� ������ � �� �����!";
			link.l1.go = "arrive_9";
		break;
		
		case "arrive_9":
			dialog.text = "������ �����... ��� ���� ������ ������? ��� ���� �������?! ������ ����� �������? � ������ ��� �������� ����� � ������� � ������� �� ����� ����������� ����! ���-������ ������...";
			link.l1 = "����! �� ������� ��! ����� �����, �� ������ ��� ����� ���. �� ��� ��������� ���� ������, ������ ��� � ������������� �� ���. � ���� �� ������� ����� ��������, �� ���� ������������ � ���������, �� � �� ������� ��� ����� �������, ���... ������ ���!";
			link.l1.go = "arrive_10";
		break;
		
		case "arrive_10":
			dialog.text = "��� �� �����������? ������, ����� ����, ���� ����� ��� ��������, �, ��������, �������?";
			link.l1 = "���, �������� ��������. ��-������, � ���� ������ - ����� �����, �� �� �������. � ������������ � ���. � ��-������, � ��������� ����������� �� ���� ������ �� �������, � �� ��������� �� ����.";
			link.l1.go = "arrive_11";
		break;
		
		case "arrive_11":
			dialog.text = "�� ������, ��� ���� ������?";
			link.l1 = "�� �������! ��� � �����, ����� ������, ��� � ����� �������. � ���� ������ ���� ������ ���������� ������� � �����, ����� ������ ����� ����, �������� �� �������. ������ �� ������������ �����, � �������, ���� � ��������...";
			link.l1.go = "arrive_12";
		break;
		
		case "arrive_12":
			dialog.text = "� ��� ��� �����? ������ ������ ����������� �����?";
			link.l1 = "�����, ��� ���� ����������� ����������. �������� �������� �������������� - �� ������� ��� �������, ������, �� ����� ����� �� ���� ������ - �� ������ ������� ������� ����� ��������� ����. �� � ���� ���������� �� ���������...";
			link.l1.go = "arrive_13";
		break;
		
		case "arrive_13":
			dialog.text = "";
			link.l1 = "���������� ����� ��������. � ������ ������ �������� - �� ������-����� �� ������, � ������� ������������� ������.";
			link.l1.go = "arrive_14";
		break;
		
		case "arrive_14":
			dialog.text = "�� ������... ������ ����� ���. ������� - ��� ����� ������. ������� ����! ��� ��� ������ �����, ��?";
			link.l1 = "��... ������ ��. � ����� ����, ������ ������� - �������� ������. � ������� �� ����. ��, ����� �������� ��������, ��� ����� ����� ����.";
			link.l1.go = "arrive_15";
		break;
		
		case "arrive_15":
			dialog.text = "(�������� �����) ������ �����! ������� ���� �� ������, ��� ��-������... "+pchar.name+", ����� ������ � �������! � ���� ��� ����� ������� ����������� � ����!";
			link.l1 = "�������, �����. � �� ���� � �������� ���� � ����� ������������. ����!";
			link.l1.go = "Dolly_4";
			AddQuestRecord("BaronReturn", "9");
			LAi_LocationDisableOfficersGen("Pearl_jungle_03", false); // ������� �������� � ���� ���������
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			setCharacterShipLocation(pchar, "Shore9"); // �������
			setWDMPointXZ("Shore9"); // ������� � ����� �������
			bNoEatNoRats  = false; // ��� � ���� ��������
		break;
		
		// � LSC � �������
		case "nathaniel":
			dialog.text = "��, ��������� ����� ��� ��� �� ���������� ������. �� ��� �� ����� ������ �� ��������!";
			link.l1 = "� �� ���� �����������, �����...";
			link.l1.go = "nathaniel_1";
		break;
		
		case "nathaniel_1":
			dialog.text = "���� ���� - �������, � ������ ������ - ������ ������������ �������. �����. �����, ��� ��� ������ ���������?";
			link.l1 = "�� �� ����� �� ��������. �� ���� ����� ��������� ������ ������.";
			link.l1.go = "nathaniel_2";
		break;
		
		case "nathaniel_2":
			dialog.text = "�������. �����������, ��� ��������� �� ����� �������.";
			link.l1 = "�����, �� ������ �������. �� � ����� ��� ������� ����� - ������� ��� �������! � ������� ���� � ����, ���� �� ������ �������, �� ��� ��������� �� ��� ��� �� �������� ��� ������� � ������� � ���� ����������� - ������ �� ��������.";
			link.l1.go = "nathaniel_3";
		break;
		
		case "nathaniel_3":
			dialog.text = "������, ����� �����. � ���� ��������� �� �����.";
			link.l1 = "����, ��� �������� �������� ��������� ����������...";
			link.l1.go = "nathaniel_4";
		break;
		
		case "nathaniel_4":
			dialog.text = "������, � ��� ���-������ ��������.";
			link.l1 = "��� ��� �������... ����� �� ������� ������ ����!";
			link.l1.go = "nathaniel_5";
		break;
		
		case "nathaniel_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.LSC_Danny_Natan.win_condition.l1 = "location";
			pchar.quest.LSC_Danny_Natan.win_condition.l1.location = "FernandaDiffIndoor";
			pchar.quest.LSC_Danny_Natan.function = "LSC_DannyAndNatan";
			AddQuestRecord("LSC", "15");
			// ��������� ����
			if (CheckCharacterItem(pchar, "keys_skel")) // ���� ���
			{
				sld = characterFromId("Ole");
				LAi_SetActorType(sld);
				LAi_ActorDialog(sld, pchar, "", -1, 0);
			}
			else
			{
				if (GetCharacterIndex("Mary") != -1) // ����� ����
				{
					sld = characterFromId("Mary");
					LAi_SetActorType(sld);
					LAi_ActorDialog(sld, pchar, "", -1, 0);
				}
				else // ����� ����������
				{
					chrDisableReloadToLocation = false;
					LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
				}
			}
		break;
		
		case "nathaniel_6":
			dialog.text = "���������... �����! ���� �� ���� ������! ������� ���...";
			link.l1 = "...";
			link.l1.go = "nathaniel_7";
		break;
		
		case "nathaniel_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			SetMusic("music_romantic");
			bDisableCharacterMenu = true;//������� ����������
			locCameraRotateAroundHero(0.0, 2.0, 0.0, 0.005, 0.0, 2.0, 0.0, 1000);
			DoQuestCheckDelay("LSC_DanielleRomantic", 15.0);
		break;
		
		case "nathaniel_8":
			dialog.text = "�������, �� �� ���� �� �� �����... �� ���� �� ���� �����!..(������) �� ������� ���� �� ��������, �������! � ���� �������� ���� - �� ���� � ��� ��������� ������! � �� �����! �����, �����?!";
			link.l1 = "�������... ������. � �� ��� ��������� �����, �� �� ������...";
			link.l1.go = "nathaniel_9";
		break;
		
		case "nathaniel_9":
			sld = characterFromId("Blaze");
			dialog.text = "����, ��� ���! �������, �����... ��� �� � ����� �����! (������ �����) ������, �������, ��� ����� ������... � �����. �� ������� ���� � �������, � �������� �����. "+sld.name+" ������, ��� ����� ���� �������. � ��� ���� �������... ��� ����� ������!";
			link.l1 = "�������, ������� ���... �������! ��, ��� �� ��� - ��� �������� ���� ����������. �� ������, ���� �������. � �������� ����� - ������, � �������� �����.";
			link.l1.go = "nathaniel_10";
		break;
		
		case "nathaniel_10":
			dialog.text = "���������. ����, ��� � ������... ��� �� ���� ����� ��������, ����� ������ �������? �����...";
			link.l1 = "�����...";
			link.l1.go = "nathaniel_11";
		break;
		
		case "nathaniel_11": // ������������ pchar
			DialogExit();
			LAi_SetStayType(pchar);
			DeleteAttribute(pchar, "GenQuest.MusicContinue");
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Danielle");
			sld.dialog.currentnode = "nathaniel_12";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
		break;
		
		case "nathaniel_12":
			dialog.text = ""+pchar.name+", �� ���... ������ ���� �� ��� �����. � ������ ����.";
			link.l1 = "�����! ����� ����� ���� ���������? ��� � �������. ��� �� ��������� ����� ������?";
			link.l1.go = "nathaniel_13";
		break;
		
		case "nathaniel_13":
			dialog.text = "���, �� �������... ������...";
			link.l1 = "����� � ������� �� ������ � ���, ��� ����� �����������. ������. ����� ����� �� ������, ��� ���� � �������. ������ �������-��-��� ������ ��� �������, ������� � ������� ���������� ������!";
			link.l1.go = "nathaniel_14";
		break;
		
		case "nathaniel_14":
			dialog.text = "�������... ������� ����, "+pchar.name+"! � � ����� ����� �����... �����, � ������ ���� �� ��� �������. �� ����������, � ����� ���� ��� ��������� - � ��������� ������. � ����� ��� � ������� � ���� ��� ���. ��� ������ ��������� ��� ���� ���� �� ������� - ���������� � �������� �����. � ����, ��� �� ������� ������.";
			link.l1 = "������, �����. �� ����� ����� �� ����������. �� �������, ��� ���� �� ����� ������?";
			link.l1.go = "nathaniel_15";
		break;
		
		case "nathaniel_15":
			dialog.text = "�������. �� ��������� �� �������. ������ ���� �������� - � �� ������� ����� ���� �������!";
			link.l1 = "�����, ��... �������������!";
			link.l1.go = "nathaniel_16";
		break;
		
		case "nathaniel_16":
			dialog.text = "(�������� �����) ������... ������, "+pchar.name+"... � �� ��������� � ���������, � ����� ����!";
			link.l1 = "...";
			link.l1.go = "nathaniel_17";
		break;
		
		case "nathaniel_17":
			chrDisableReloadToLocation = false;//������� �������
			bDisableCharacterMenu = false;//������� ����������
			EndQuestMovie();
			DialogExit();
			pchar.quest.LSC_NatanPassenger.win_condition.l1 = "ExitFromLocation";
			pchar.quest.LSC_NatanPassenger.win_condition.l1.location = pchar.location;
			pchar.quest.LSC_NatanPassenger.function = "LSC_SetNatanPassenger";
			pchar.quest.Saga_NatanTreatment.win_condition.l1 = "location";
			pchar.quest.Saga_NatanTreatment.win_condition.l1.location = "Miskito_village";
			pchar.quest.Saga_NatanTreatment.function = "Saga_NatanPrepareTreatment";
			pchar.questTemp.Saga.BaronReturn = "shamane";
			AddQuestRecord("BaronReturn", "11");
			// ��������� ���� � ����
			if (GetCharacterIndex("Mary") != -1)
			{
				for (i=0; i<=3; i++)
				{
					LocatorReloadEnterDisable("LostShipsCity_town", "reload6"+i, false);
				}
			}
			else
			{
				bQuestDisableMapEnter = false; //������� �����
				DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			}
		break;
		
		case "treatment":
			dialog.text = "�� ���? ����� ������ �� �������? �����, ��� ��� ���!";
			link.l1 = "�������, ����� �������� � �������� �����. ����. ����� ��������, ����� ����� �� ����� ��� �������, � ��� ����� � ��. �� �������� �������� ��������� �� �����.";
			link.l1.go = "treatment_1";
		break;
		
		case "treatment_1":
			dialog.text = "�� ������, "+pchar.name+", ��� ������ ������ � ��������. � ���� �������� ����������� � ���, ��� ���� ����� ������ ����� ���� � ���������� �����. � ��� ��������� �������� ��� � �������� �����, ������ ��� ���� �� ��� �� ������� - �� �� ������� �����.";
			link.l1 = "��� ����� ������, �����. ������� ���� �� ������� ��� �� ����. � ���� ���.";
			link.l1.go = "treatment_2";
		break;
		
		case "treatment_2":
			dialog.text = "� ���� ��� ����. � �������� � ����� ������� ��� �� ��������� �����, "+pchar.name+", �� �� ����������? ��� ����� ����� �������� �������� � ��������� ����� ��� - ������� ��������. ��� �� ����������� ������ �� ������! �� �������� ��� ����� � �������-��-���! �� ����� '���������', ��� ������!";
			link.l1 = "� ��������. � ��������� ���� ����������� ����������, ��� ���� �� ���, �� ����, �� ���, �� ������ ����� �� �����. ������ ������� ��� ����� �� ��� ������.";
			link.l1.go = "treatment_3";
		break;
		
		case "treatment_3":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie")) sTemp = "����� �������";
			else sTemp = "������� �������";
			dialog.text = "� ���� ���� �����-�� ����, "+pchar.name+"?";
			link.l1 = "���� ���. ���� ������������ � ��� �������� � �������������� � ���. ����� ��������������� - ������ ����� ��������� "+sTemp+" �� ���� ����� ���������� ��������. � ��� ����� ����� ���������� ���������� ���� ��������� �������.";
			link.l1.go = "treatment_4";
		break;
		
		case "treatment_4":
			dialog.text = "������. ������ � ��������. ���������, ��� ���� ������ ���� ������...";
			link.l1 = "�� ���� ����� �������� � ���. �� � � ����� ������, ���������� �� �� � ���, ��� ��... ���� ���� ������!";
			link.l1.go = "treatment_5";
		break;
		
		case "treatment_5":
			dialog.text = "�� ����� ��� �� �������� � ����... �����, "+pchar.name+", ������ ����. � �� ������ ��������� ��������, ������ � ��� �� ������ � ��������� �����. � �� ���� ������.";
			link.l1 = "��� � ������. �����, ��� ����� ������. ������ ����!";
			link.l1.go = "treatment_6";
		break;
		
		case "treatment_6":
			dialog.text = "� ���� ����, "+pchar.name+". ����, ��� ������ �������. ������ � ��������?";
			link.l1 = "� ����, �����!";
			link.l1.go = "Dolly_4";
			AddQuestRecord("BaronReturn", "13");
		break;
		
		case "islatesoro":
			dialog.text = "��? ����� � ���� ����������� ������. � ��� ����?";
			link.l1 = "� ���� ���� �����-������ �������������, ��� ����� ���������� �������? �� ������ ����� ������� ������� ���� - �����, � ���� ���� �����-�� �����, ����...";
			link.l1.go = "islatesoro_1";
		break;
		
		case "islatesoro_1":
			dialog.text = "�� ���� ��� �����. ���� ������ ��� �������� �������. ��� �����-�� ��� �������� �������� � �� �������. ��� ����� ����������� ��������� �������... ����� ��� ��� ������� ������, ������� �� ����� � ������. �����, ���-�� ���������.";
			link.l1 = "�����...";
			link.l1.go = "islatesoro_2";
		break;
		
		case "islatesoro_2":
			RemoveItems(pchar, "letter_chad", 1);
			dialog.text = "���... ����� ����������� ���� ������ � �����-�� ���������... ���� ��� �� � ��� �� �������?";
			link.l1 = "�� � ���� �������, ��� ������ ����� �� ���� ������ ����� �������, ������ ���� �� �����. � ���������... �����... ��� �� ����� ����� � ����... ���� ������, �� ��� �� � ������ �� ���������! ���� ������� ��������� ��������� ���-�� � ���� ������!";
			link.l1.go = "islatesoro_3";
		break;
		
		case "islatesoro_3":
			dialog.text = "����� �� ����� ������ �������, "+pchar.name+"?";
			link.l1 = "��. ������������ � ���� ������. ������� '������' �������� ��� ��� ����� ����� ��� ������ �����.";
			link.l1.go = "islatesoro_4";
		break;
		
		case "islatesoro_4":
			DialogExit();
			AddQuestRecord("BarbTemptation", "18");
			pchar.questTemp.Saga.BarbTemptation = "islatesoro";
			// ������ ���������� �� ����-������
			pchar.quest.Saga_AttackJackman.win_condition.l1 = "location";
			pchar.quest.Saga_AttackJackman.win_condition.l1.location = "Bermudes";
			pchar.quest.Saga_AttackJackman.function = "Saga_CheckJackmanBermudes";
		break;
		
		case "after_boarding":
			dialog.text = "�� �������-�� ���� ������� ����... ���� �� ������� - � ����� �� ������ '����������'! � ���� ����� ������ ������ � ��� �������, ��� ������� ���� ����� ����.";
			link.l1 = "������ �� ����� ����, �����. ���� � ���������.";
			link.l1.go = "after_boarding_1";
		break;
		
		case "after_boarding_1":
			PlaySound("VOICE\Russian\saga\Denny Hawk-03.wav");
			dialog.text = "�� �� �������������, ��� � ����. ��������� ����� ��������� ��� ������� - ����� � ���, ��� �� ����� ���, � �� � ����� ������� ��������, �������� ��� ���.";
			link.l1 = "��� �� ������ ������ ������, �����?";
			link.l1.go = "after_boarding_2";
		break;
		
		case "after_boarding_2":
			dialog.text = "���? ������ ������� � ��������, ������������, ����� ���� �� ������� ������� � ����� � ��������. ������� ��� ��������, ����� ��� ���� ����������� �� '�����������', � ���� ���������� � ������� - ���� �����, ���� ������� ���� ������� ����� ����.";
			link.l1 = "�� ������� � ��� ��������? �����, � �������...";
			link.l1.go = "after_boarding_3";
		break;
		
		case "after_boarding_3":
			dialog.text = ""+pchar.name+", � ���� ���� �������. � ����� ������ � ����� ������: '�� ������ ���� ����'. �������? � ���� ���������� �� ��������� - ���� ��, ���� � ��������, �� ����� ������� ��� ������. �� � � �����-������, ������ ����.";
			link.l1 = "�������� �����, �����! ����� ��������� �����������, �� ����� ������ ������ ���� ���������� ����� � �������-��-���.";
			link.l1.go = "after_boarding_4";
		break;
		
		case "after_boarding_4":
			dialog.text = "���-�� ��� ���... �� ��������� ����� -  �������� ���������. ����� ������ �������-��-��� ����������� �����?";
			link.l1 = "���������� ��� ��������. �� �������� ���� ������. ����������� �������� ���� ������� ���� ����.";
			link.l1.go = "after_boarding_5";
		break;
		
		case "after_boarding_5":
			dialog.text = "������. ������ ��� �� ��������� �������� ����� �������� � ����� ������... "+pchar.name+"! � ���� �� ���� ���� ������������� ���� �� ��, ��� �� ������ ��� ���� � ������. �� ���������� ���� ����� ����, � ������ ��� � ������ ��� ���������� ����. � � ���������� ����� ����� �����.";
			link.l1 = "�����, �����. �� �� ������.";
			link.l1.go = "after_boarding_6";
		break;
		
		case "after_boarding_6":
			dialog.text = "� ����, ����� �� ���� - � �������-��-��� ���� ������ ����� ����. ����� ����� ����������� - ����������� ������� � ���. �� � ���������� ���������, ��� ���� �������������.";
			link.l1 = "�� ��� � �����, �������. �� � � ������������� �������� ���� �����������. �������, ������, ��������, ��� �� � ������� ������ ��� ��� ������...";
			link.l1.go = "after_boarding_7";
		break;
		
		case "after_boarding_7":
			dialog.text = "��� ����� ���� ���������? ��, �� ��������� ��� �� ����...";
			link.l1 = "�����, �����. ���� ��������� ��� ����� ������ �� ����� ��������, � ��� ���� ��������� �������� ������ - ������� � ���������. �� ������� � ��������� ����� ���� ��� �����, �� �� �����: � ������, ��� � �������� � �������� ����� ����� �����, ������� ���� ������������.";
			link.l1.go = "after_boarding_8";
		break;
		
		case "after_boarding_8":
			dialog.text = "�� ����������, ������� �� �������, ��� � ����� ���������?";
			link.l1 = "�������. � ������, ��� ���� ���-�� ���� � ����� ������������, �����... �������� � �������-��-���!";
			link.l1.go = "after_boarding_9";
		break;
		
		case "after_boarding_9":
			DialogExit();
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-10;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			LAi_SetHP(npchar, 280, 280); 
			LAi_SetImmortal(npchar, false); // ���� ���������
			pchar.GenQuest.CannotTakeShip = true; // ������ ���������
			DoQuestFunctionDelay("Saga_CheckJackmanCabinItems", 5.0); // ������ �������� ����� 5 ���
			AddCharacterExpToSkill(pchar, "Leadership", 300);
		break;
		
		// � �������-��-���
		case "marun_town":
			dialog.text = ""+pchar.name+", ����� ���� ���� ������! �� ����� � �������-��-���, � ����� ����� ���� �������� �����. ������, ��� � ������� ���� ����� ����� ����. ������ ����� ��� ����� ��-��������! �������� ���� ������� �� ���� ������������ ������!\n� ���� ������� ���� �������. ���, ������. ���� �������� ����� ������� ���� � ���. � ������ ����� ������� �� ������ ������� ������� ��� ��������������.";
			link.l1 = "�������, �����!";
			link.l1.go = "marun_town_1";
		break;
		
		case "marun_town_1":
			GiveItem2Character(pchar, "totem_12"); 
			GiveItem2Character(pchar, "recipe_totem_12"); 
			Log_Info("�� �������� ��������");
			Log_Info("�� �������� ������ ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� �� ���. � ����� � ���������� � ����� ��� ������� � �������. ��� ��������� ������������ ��������. ������ � �� � ���� ���� ���������������. � �� ���� ������������! � ����, ������� �� ����� ��������, ���� ����� ��� � ������� ��������.";
			link.l1 = "������, ������, �����, �� ��������!";
			link.l1.go = "marun_town_2";
		break;
		
		case "marun_town_2":
			TakeNItems(pchar, "chest", 2); 
			Log_Info("�� �������� ������� � ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� � ������! "+pchar.name+", � ����, ����� �� ����: �� - ��� ������ ����. �� � ������� ������ ����� ���� ������ ���� � �������-��-���! ������ ������!";
			link.l1 = "�������! ��� ���� ����� ����� ������� ������ ���, ��� ��� ����� � �����!";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_3";
		break;
		
		case "marun_town_3":
			dialog.text = "���� ���� ������, "+pchar.name+"! ����, ����? �����, �������?";
			link.l1 = "�������, �����! � ������ ����� ��� ���������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_3";
		break;
		
	// ------------------------------------------- ������� ���� ------------------------------------------------
		case "failcenturion":
			dialog.text = "�� �������-�� �� � ������� ������ ��������� ��������! ���� ��������� ������� ������� ����!.. ����, �������, '����������', �� � ��� ����� ��� � ��� ����� �����������, ����� ���� �������� ������� ��� � ����. ��� ��� � ����� �� �������������.";
			link.l1 = "���� � �������������, � �����. �� ���� �� ���� ��������� ����� ��������! ������ � ���� �������� �� ��� ���� ��� �����, ������� ����� ������� �� ���� ��� ������ ������ ����� ���������� ��������. � ������... ��� �������.";
			link.l1.go = "failcenturion_1";
		break;
		
		case "failcenturion_1":
			dialog.text = "�� �� �������� �� ���! � ����� ������ ������. � ������ ��� ���������� �������... �����. � ���� �� ���� ���� ������������� ���� �� ��, ��� �� ������ ��� ���� � ������. �� ���������� ���� ����� ����. � � ���������� ����� ����� �����\n� ����, ����� �� ���� - � �������-��-��� ���� ������ ����� ����. ����� ����� ����������� - ����������� ������� � ���. �� � ���������� ���������, ��� ���� �������������.";
			link.l1 = "������, �����. ����������� ������� � ��� � �����. �� ��� �������?";
			link.l1.go = "failcenturion_2";
		break;
		
		case "failcenturion_2":
			dialog.text = "��, ���������� � ������� - �������, ������� ���� ��� �������� ������ �� ����. � ����� �� �������� � �������-��-���.";
			link.l1 = "���, � ��� ��� ������ � ����, ��� ���� � ����� ������������... �����, �������!";
			link.l1.go = "failcenturion_3";
		break;
		
		case "failcenturion_3":
			DialogExit();
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
			RemovePassenger(pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "Saga_FailCenturion", 10.0);
			npchar.greeting = "danny_2";
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Danielle_officer":
			dialog.text = "�� ��� ����, �������?";
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "danielle")
			{
				Link.l3 = "�����, � �� ����� � ����� ��������������.!";
				Link.l3.go = "islatesoro";
			}
			Link.l1 = "������ ��� ������!";
            Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Danielle_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ����� ����������?";
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
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}