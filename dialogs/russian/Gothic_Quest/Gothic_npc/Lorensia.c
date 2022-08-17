// �������� ������
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
		
		case "After_boarding":
			dialog.text = "��������� �� ������, �������!";
			link.l1 = "��... �� ��� ��������, ��� � ���� ����������� �� ���������!";
			link.l1.go = "After_boarding_1";
		break;
		
		case "After_boarding_1":
			dialog.text = "���� �� ������ ��� �������! ��-�� ��� � ���� ���� �� ������� � ����. ����� �� �� ���� � ������� �� ��������, ������ � ����� �� ���, ������ ��� ������� ����� ���� ��� ����� �������. ����� �� ������, ��� ����� ����� � ������� �������� �� ���� ������������ ������� ���� ����\n��� ��� �� ������� �����, ���! ����� �����������. ���� ����� �������� �����. ���� � ������� ������� �������� �� ����������� ����, ��� ��� �������� �� ��� � �����������.";
			link.l1 = "�� � ���� ����� "+GetFullName(pchar)+". ��� ��� ��������� ���� ���������� ���� �� ����� ���������� �� ������� ������ ������.";
			link.l1.go = "After_boarding_2";
		break;
		
		case "After_boarding_2":
			dialog.text = "��� ���?";
			link.l1 = "������ ���������� �� ����. �������, ����� �� �� �������, �� ���� � ��������. �� ������ ���������� ��� ���� ����������� ���������...";
			link.l1.go = "After_boarding_3";
		break;
		
		case "After_boarding_3":
			dialog.text = "������� �� �����, "+pchar.name+", ��� �� ������ ������ ����� �������� �� ������ � ���� �����. � ������� ������ �� ��� ��� ��������� ���, ����������� �� ������� ����� �������...";
			link.l1 = "��� �������, ��������. � ������� ������ ���� ��� � ����������� �����. ���� ���� �������!";
			link.l1.go = "After_boarding_4";
		break;
		
		case "After_boarding_4":
			DialogExit();
			LAi_SetActorType(npchar);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			npchar.greeting = "helena_2";
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			pchar.questTemp.Saga = "returntoblueveld";
			Island_SetReloadEnableGlobal("Antigua", true);//�� ������ �����
			bQuestDisableMapEnter = false;//������� �����
			AddQuestRecord("Saga", "11");
			pchar.quest.Saga_returnBlueveld.win_condition.l1 = "location";
			pchar.quest.Saga_returnBlueveld.win_condition.l1.location = "Santacatalina_town";
			pchar.quest.Saga_returnBlueveld.function = "Saga_returnBlueveld";
			SetFunctionTimerCondition("Helena_ReturnOver", 0, 0, 45, false);
			sld = characterFromId("gladis");
			sld.greeting = "gladis_3";
		break;
		
		case "Return_blueveld":
			pchar.quest.Helena_ReturnOver.over = "yes";
			dialog.text = "��� ��� �� ����� ������ ��������� ����, ��� �������, �� �������� ��������. �� ����������� ������ ��������� ��� � ��������. ��� ����� ��� ������ �����. ��� ��, ������ �� ����� � ����� �����. � ����, "+pchar.name+", ���� �� ���������, �� �����������, ������� ���� ����� �� �����, ��� � ����!";
			link.l1 = "����� �����������!";
			link.l1.go = "Return_blueveld_1";
		break;
		
		case "Return_blueveld_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "houseSp3", "SantaCatalina_houseSp3_bedroom", "goto", "goto1", "OpenTheDoors", -1);
			AddQuestRecord("Saga", "13");
			LocatorReloadEnterDisable("SantaCatalina_houseS1", "reload2", false); // ������� ������� ��������
			pchar.questTemp.Saga = "svenson";//���� � ��������
			sld = characterFromId("JS_girl");
			sld.dialog.currentnode = "js_girl";
			npchar.dialog.currentnode = "Helena_wait";
			sld = characterFromId("Gladis");
			sld.dialog.currentnode = "Gladis_regard";
			LocatorReloadEnterDisable("SantaCatalina_houseSp3", "reload2", true);//������� ������� ��������
			// ������� ����� �� ������ � ������
			LocatorReloadEnterDisable("SantaCatalina_town", "reload1_back", true);
			LocatorReloadEnterDisable("SantaCatalina_town", "reload2_back", true);
			LocatorReloadEnterDisable("SantaCatalina_town", "gate_back", true);
		break;
		
		case "Helena_wait":
			dialog.text = "� ��� � ��, ��� �������! ��� � ����, "+pchar.name+", ��� �� ����� ������� ���� ���������. � � ������ ������ �� ���������� � �����.";
			link.l1 = "������� ���� �������� �� ��������� �����. � ������ ���-��� ��������, ������ ��� ����� �������� �� ���� �������. � ���� ����������� ����� �� ������������ �� ����� ��� ������ �������������. �������, ���� �������� ����� ��������. ���� ��� � ���.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Helena_wait";
		break;
		
		case "Helena_hire":
			dialog.text = "� ��� � ��, ��� �������! �� ������ ����, � ���� ���� ������� ��� ����!";
			link.l1 = "������� ������, ��� �� ������� �� ��� � �������. � ����� ��� ������ ������� - ������ ��������, ��� �� ����� �������� ��� ����. ����� ���������� � ��� �������, ������ ��������!";
			link.l1.go = "Helena_hire_1";
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_friend"))
			{
				link.l2 = "������� ������, ��� �� ������ ����� �������� �� ���� �������. � ����� ��� ������ ������� - ������ ��������, ��� �� ����� �������� ��� ����. ����� ���������� � ��� �������, ������ ��������!";
			link.l2.go = "Helena_hire_2";
			}
		break;
		
		case "Helena_hire_1":
			DeleteAttribute(pchar, "questTemp.Saga.Helena_friend");
			dialog.text = "����, ��� �������! �� ����, � ������� ������, ���� �� ���� �������� � ������� ���������� �� ��������.";
			link.l1 = "�� ��������, � ��� �� ������� � ���� ������. ����� ����, ���� �������� ��� ���-���...";
			link.l1.go = "Helena_hire_1_1";
		break;
		
		case "Helena_hire_1_1":
			dialog.text = "� ��� �� ���?";
			link.l1 = "�� � ���� ��������� ��������, ��� � ���� ���� ��� ����� �� ������������ ������� ���� ������. ��, ��, ������ ���, ���� �� ������ ������ ������� �����������. � ���� ���� ��������� �����, ������� ������� �������� ���. ���� � ���� ����� ��� �� ��� ������, �� � �������� ��������� ������� ���� ����� ������������ ����������� �������.";
			link.l1.go = "Helena_hire_1_2";
		break;
		
		case "Helena_hire_1_2":
			dialog.text = ""+pchar.name+", �� ��������? ���, �� �������� ��� ������ ��������! ������ � ���� ����� ���� ����� �� ����� ������?";
			link.l1 = "� ��������� ��������, ��������. ����� ���� - ������� ������ ���� �������� ���� �����. � ������ - ������������ � ����!";
			link.l1.go = "Helena_hire_6";
		break;
		
		case "Helena_hire_2":
			dialog.text = "��� �� ������? �������� ����? � ������ ����?";
			link.l1 = "��������, �� - ���� �������� ����, � ������������ ���������� �� ����� ������. ��� ��������� �����, ������� ������� ������� ������ ��� ��� ����, �������� �������������� ����� ���� �� ������ ����-������ � ��������. �� � ���� ����� ��� �� ��� ������, � �� � �������� ��������� ������� ���� ����� ������������ ����������� ������ ����.";
			link.l1.go = "Helena_hire_3";
		break;
		
		case "Helena_hire_3":
			dialog.text = "��... ������ ��� ����! ������� �����-������ ����� �� ������� � ������������ � ���. ��... ������! ����������!";
			link.l1 = "��� �����, ��������?";
			link.l1.go = "Helena_hire_4";
		break;
		
		case "Helena_hire_4":
			dialog.text = "������� ����������� �������... � ������ ������ ��� ������.";
			link.l1 = "����� ��� �����������? � ��� �� ��� ������?";
			link.l1.go = "Helena_hire_5";
		break;
		
		case "Helena_hire_5":
			dialog.text = ""+pchar.name+", ��, ��������, ������� ���� �������, �� � ��� ����� ����� ����. ��������� ��� ����� ������� �� ����� ������� ���: '���� ������ � ����� ����, ��� �� ������� ����� �����, ������ ������ �������� � ������� ��� ������'\n����� � ��������, ��� ��� ������ ����. �� �������� ��, � �� ������ ���� ���� �� �������� ������, �� � ��������� ��������� ��� ��� ������� �����������, � ������� �� ��� ������ ����� �������!";
			link.l1 = "������, ��������... ��� �e, ������ ����� ���� � ���. � ���������� �� ������������ ����, � ������� ����� ������ �� ������ ������. � ����... ������ �������� ����! ��������� � �� ��������� � ��������!";
			link.l1.go = "Helena_hire_6";
		break;
		
		case "Helena_hire_6":
			dialog.text = "����, �������!";
			link.l1 = "...";
			link.l1.go = "Helena_hire_add";
		break;
		
		case "Helena_hire_add":
			LAi_SetImmortal(npchar, false);
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "Saga_HireHelena", -1);
			LocatorReloadEnterDisable("SantaCatalina_town", "reload1_back", false);
			LocatorReloadEnterDisable("SantaCatalina_town", "reload2_back", false);
			LocatorReloadEnterDisable("SantaCatalina_town", "gate_back", false);//������� ������ �� ������
			pchar.questTemp.Saga = "svenson_wait";
			AddQuestRecord("Saga", "24");
			SetFunctionTimerCondition("Saga_BaronsQuestsGo", 0, 0, 2+rand(2), false);
			AddCharacterExpToSkill(pchar, "Leadership", 100);
		break;
		
		//-->  ������������ �� ������� ��������� � ��������� ���������
		case "sea_bomb":
			dialog.text = ""+pchar.name+"! � ���� �������� ���� ����...";
			link.l1 = ""+npchar.name+"? ��� ������-�� ������, � � ����� ���������� �� �������...";
			link.l1.go = "sea_bomb_1";
		break;
		
		case "sea_bomb_1":
			dialog.text = ""+pchar.name+", �� ���� ������ ������� ������, ��� �������� �� - � ������� �� ������ ���� ������, ��� ��� ������� ��� - �� ���� ����� ��, ��� �� �����. �� �� �������� ����!";
			link.l1 = "��? ��� �� ������ �������?";
			link.l1.go = "sea_bomb_2";
		break;
		
		case "sea_bomb_2":
			dialog.text = "������ � ������. ��� ������� ��� �� ������... ������. �� ����� ���� ���������������. ������ ������� ���� ����� ������� ����� � ������� ������, �������� ������ � �������� � ��� ��������\n��� ��������� ��� �������� � �� ��������� ������ ����� ����� � ����� �� ���, ������ ���� � ������ �������. ������� - ������ �������� ������. � ����� �����������, ��� ��������� ������ ������� � �������... ��� �������?";
			link.l1 = "�� �� ���������! ����, ���� ���� ����� ���������... �� ������ ���� ��� �� ����������.";
			link.l1.go = "sea_bomb_3";
		break;
		
		case "sea_bomb_3":
			dialog.text = "�������, "+pchar.name+"? ���� � ����� ��������� ��� ����� ������ ����������, � ��� ���� ����...";
			link.l1 = "������. ��� � �������! ������! �������� ��� ����� � ������� �� ����! � ������! �� � ���� � ��������, "+npchar.name+"... � �� �� ���������.";
			link.l1.go = "sea_bomb_4";
		break;
		
		case "sea_bomb_4":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetOfficerType(npchar);
			npchar.dialog.currentnode = "Lorensia_officer";
			pchar.questTemp.Saga.BarbTemptation.Bomb = "true";
			pchar.questTemp.Saga.BarbTemptation.adviser = "Helena";
		break;
		
		case "fugas":
			dialog.text = "��, �������. � ��� ������ ����?";
			link.l1 = "� ����� ����-������ ����� ������� ��������, �������� ������ '���������'. ��� ����� ������������ ������ ������, ����� ����, � ����� �������� ������ ���� ������ ��������� � ����... � �����, ��� ����� ����� �� �������.";
			link.l1.go = "fugas_1";
		break;
		
		case "fugas_1":
			dialog.text = "�������. � �� ������ �������, ��� ���������� ������� ��� �� ����� �������? � ��� ������� ������, ��� � ���, � ����� ����.";
			link.l1 = "������ ���. � �������� ��� ������� ����� ������ �����, � ��� ������� ������� - �������� ��������. ��������� ��������, ��� ������������� - ������ �������. �������� ������� ������� ���� ����� ���������� �� � ���� ������. ��� � � ����� ������ - ��� �� ����� ���������.";
			link.l1.go = "fugas_2";
		break;
		
		case "fugas_2":
			dialog.text = "�� �� ��������, "+pchar.name+", �� � ��� �� ���� ������ � ���-��� ���������! ��� ���� ��� ���� ��� �� ������ - ������� �����, ��� �� ��� �����, �� ������... ����� ��������� ��������.";
			link.l1 = "��������! � �� ������ ��� ������ - ������ ������ ������, ��� ����� ������������!";
			link.l1.go = "fugas_3";
		break;
		
		case "fugas_3":
			dialog.text = "� ��� �����, "+pchar.name+". ������ �� �����. ��������: ����� ��������� ������ �������� ��-��� ����, �������� ���� �����, ������ ������� � ����������� ����� �������� ������. ����� �������� � ����� ������� � ������ ������� � ����� �������� ����� �� �� ������.";
			link.l1 = "��! �� �������, ��� ���������?";
			link.l1.go = "fugas_4";
		break;
		
		case "fugas_4":
			dialog.text = "� ������ ���? ����� � ��� ����, �� ��� �������� ������ �������� ������� ������. ������� - '���� ��� � ������� �� ������'! ���� ��� ����� ����������, ��� �� ��� - ������� ���������.";
			link.l1 = "������� ���������� � ������� � ��������� ������ ����, ��� ����� ����������... ���� ������, ������ ���������. ��� ����� ����� ��������� ��������� �� ������ �� ��������! ��� ��� ��� � ���� ����� �������.";
			link.l1.go = "fugas_5";
		break;
		
		case "fugas_5":
			dialog.text = "����� �� ���� �������, � ���� ���� � ������ �����. "+pchar.name+", � ��� �������� ������������ - �����������. ��� ������ �� �����������! � ����� ����� ������� �� ��� ��������, ����� �� ������ ��������� ���������� ������.";
			link.l1 = "�� ��� ��, ���������. ������� - ����� ��� �� ������� ������ �������, ��� '������' ��� �� ��� ������������� ������ ��������... ���� ������, ��� ����� ������� - � ��� �����������. ������� �� ����� �������, ��� �����.";
			link.l1.go = "fugas_6";
		break;
		
		case "fugas_6":
			dialog.text = "�������, "+pchar.name+"! ���� �� ��������� - ���� �� �����.";
			link.l1 = "���� �� �����, ��� �����... ������� ������, � � ���!";
			link.l1.go = "fugas_7";
		break;
		
		case "fugas_7":
			DialogExit();
			npchar.dialog.currentnode = "Lorensia_officer";
			pchar.questTemp.Saga.BarbTemptation.Fugas = "true";
			AddQuestRecord("BarbTemptation", "21");
			DeleteAttribute(npchar, "quest.fugas");
		break;
		//<--  ������������ �� ������� ���������
		
	// --> �������� �� ������ ����
		case "result":
			if (!CheckAttribute(pchar, "questTemp.Saga.Helena_friend")) // �� ������
			{
				dialog.text = "�� ���, ��� �������... ������� ����� ��� � ����� ����������. ��� ������ �����������, � ��� ���� ��������� � ���� ������� ����-������. �������, � ����� ����� ��������� ���������� ������ ����. ��������� ���� �� ������.";
				link.l1 = "����, �������, ������������, �� ��� �� ��������. � ���� ������ ���� ���� ��������, ��� ������ �� ���� �����.";
				link.l1.go = "result_1";
			}
			else
			{
				dialog.text = "��� �������, "+pchar.name+"! � ������ ��� ����� ���������� ������ �������, �� ������ �� �������� ���� �������� ���� ������... �������, ����� ����� ���������� �������� ��������� � ������ ������� ���� ����� ����. ��� �� ����� ���������� ������ �����.";
				link.l1 = "��. �� �������, ��������? �������, � ���� �� � ������������� ����� ������!";
				link.l1.go = "result_9";
			}
		break;
		
		case "result_1":
			dialog.text = "�� ����... ��� ��� ������� ������� ������� ������ - ��, ��� � ���������� �� ����� �������. ������ ��� � �� ������� ������������ - � �� ���� ����������� ���� ����� ���������.";
			link.l1 = "��. ������-��...";
			link.l1.go = "result_2";
		break;
		
		case "result_2":
			dialog.text = "� �������, ��� �� ������ �������. ����������, ���� ������ ���� ������� ������������ ����� ������� � ��������. �� ��� ����� ���, ��� � ���� ����, � ������������� ���� � ������ �������. ����, � ���� �� �������� ��� - � ������� ��� � ���� � �����.";
			link.l1 = "�� ���, ������� �� ����� ����� ������? �����, ���� ������� �� ���� ������?";
			link.l1.go = "result_3";
		break;
		
		case "result_3":
			GiveItem2Character(pchar, "chest");
			Log_Info("�� �������� ������ � ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �����, "+pchar.name+". � ���� �������� �� ������ �������. ��������� ����� ����� � ���� ����, �� ������ ����� ������... � ������� ���� ������, � �������, �� �������� ������������ � �������.";
			link.l1 = "�� ��� �� - ��� �������. ����� ���� ����� � ����� ����� �����.";
			if (!CheckAttribute(pchar, "questTemp.Saga.Beltrop_die")) link.l1.go = "result_4";
			else link.l1.go = "result_7";
		break;
		
		case "result_4":
			dialog.text = "�������. �� ��� ��� �� ���. � ����� ������ ����, ���� � ����� ��������� �������. ����������, �� �������� ����� ������ ������ ����������� ��������� �� ��� ����������, � ���� ��� ����� ��������. �� ���� ��������� �����, � � �� ����� �� ������, ����� ��, "+pchar.name+", ������ � ��� �������.";
			link.l1 = "��������, ��������! �� �� ������ � �����!";
			link.l1.go = "result_5";
		break;
		
		case "result_5":
			dialog.text = "�����? � ��-�� ���? � ������ ������� �� ��� ����! � ���, ������ ������� � ������, ������� �������, ��� � ��� ������ ���������� ����������. � ���� �� ���������� ��������� ���� ����� ����, �� � ������ ��� �� �������, ��� �� ����� ��� ���� �������. ����, � ���� ������������.";
			link.l1 = "��� ���? ������-��, �������, ����� ���� � ����������. ���-�� � �� ������� �� ���� ������� �� ������ ����� ���������� ���������, ����� � ���������� ���� �� ��� ��������, ����� ����������� ������� �������� ��� ������!";
			link.l1.go = "result_6";
		break;
		
		case "result_6":
			dialog.text = "������. � ������������. �� ��� ���-���� �������� �� �������� � ����� ��������, ��� ������ �����������, ���� �� ������� ������� ����� ������ ����� ����.";
			link.l1 = "� ������� ����. �� ����� ������� �� ���� �������� ���, ��������... �������. �� ����� ������ �� ���� ������� �� ������ ���� ������, ��� � �� ����� �� �����, �� �������� �������. � ���� ���� �� ���������, ������ ���. � ������ - ������. � �� ������ �� �� ���, � ����� ���� �����.";
			link.l1.go = "result_8";
		break;
		
		case "result_7":
			dialog.text = "�������. ��������, ��� �����-������ ����������, "+pchar.name+"...";
			link.l1 = "� ������ ���? �� ���� ������ ��� ��������� �������� ��� �� ���. ��� � ��������... ����, ��������!";
			link.l1.go = "result_8";
		break;
		
		case "result_8": // �������� ������, �� �� �� ��������
			DialogExit();
			RemovePassenger(pchar, npchar);
			chrDisableReloadToLocation = true;//������� �������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "none", "", "", "OpenTheDoors", 15.0);
			AddQuestRecord("Testament", "11");
			CloseQuestHeader("Testament");
		break;
		
		case "result_9": // ��� ��� - �������� ������, ���� ����� ����� ���� - �������, ����� ������� �����
			dialog.text = "� ��� ��������. "+pchar.name+", ���� �� ���������, � �� � ������ ������ �������� � ���� �� �������. ����� � �����...";
			if (CheckAttribute(pchar, "questTemp.LSC.Mary") && pchar.questTemp.LSC.Mary == "alive")
			{
				link.l1 = "(������� ����) ��������! ��, ������, �� ���������. �� ���������� �� ����� ����� ����, � ������ �� ������������ � �������. � ���� �� ������� - �����, ���������� ������� � ������ �������������. ���� ����� ���������� ���� �����, � �� ��������� �� � ������������.";
				link.l1.go = "result_10";
				link.l2 = "(������� ��������) � ��� ������ ������� �� ����, ��������. �������, � �� ���� ������ ����, ��, ��������, ���� ���� �� ����� ����������� �� ���� ������. ��� �����, ���� �������� ���� ��� ������. � ���� ������� - �����, ���������� ������� � ������ �������������.";
				link.l2.go = "result_15";
			}
			else
			{
				link.l1 = "� ��� ������ ������� �� ����, ��������. �������, � �� ���� ������ ����, ��, ��������, ���� ���� �� ����� ����������� �� ���� ������. ��� �����, ���� �������� ���� ��� ������. � ���� ������� - �����, ���������� ������� � ������ �������������.";
				link.l1.go = "result_15";
			}
		break;
		
		case "result_10":
			dialog.text = ""+pchar.name+"! �� ��� ���. �� ������ �� ������, �����... �����: ��� ���? �� ����� �������� � ������� �������� ��������? ��?";
			link.l1 = "��������! � � ������ ������� ����� � ����! ��� �� ����� �� ���������?!";
			link.l1.go = "result_11";
		break;
		
		case "result_11":
			dialog.text = "� ��� � �����... � ��� �� ��� ���� ��� ���������, �? ��, "+pchar.name+"... ��, ��� �� ��� ����� - �� ��� � ������ ������ ������ �� ��������, ��� ����������� �� ���� ������. � �� ���� ������ ����� ����\n� ����� ������, �������� ������� ���� �� ���, ��� �� ��� ���� ������. �� - ������ �� ����, ���� � ������ �����. �� � ��������-�� �� ���������?";
			link.l1 = "�������... ��������, �� � ����� ��� �� ��� ���������� �� ���� ������. ���� ������� �� ���� ������?";
			link.l1.go = "result_12";
		break;
		
		case "result_12":
			dialog.text = "�� ����. � ����� ���� �������. �� ����� ������ � ���� � ������� �����, ����������� ��� ������� � ���������� �����. � ���� ����� ����� ��� '������'.";
			link.l1 = "����� ���, ��������, ��� �� ��������� �����... �������������. �� ��������� ���� ������ �� �������� ������ �� ����� - �����, � ������ ������� �� ������������ ����������� ��������.";
			link.l1.go = "result_13";
		break;
		
		case "result_13":
			dialog.text = "��� ��������, "+pchar.name+". �����. ����� �� �����, ������������� ���� ����� �������, �� �������... ������� ����, �� ��������. ����������...";
			link.l1 = "��������...";
			link.l1.go = "result_14";
		break;
		
		case "result_14": // ���������� �������
			DialogExit();
			SetMusic("music_romantic");
			SetLaunchFrameFormParam("", "", 0, 12);
			SetLaunchFrameFormPic("loading\inside\kiss.tga");
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 0, 20); //������ �����
			RecalculateJumpTable();
			DoQuestCheckDelay("Saga_HelenaBye", 12.0);
			pchar.questTemp.LSC.Mary = "return"; // � ����
		break;
		
		case "result_15":
			dialog.text = "� ������ �� ����� ������� ���� ������ ����� ���� �������. ������� �� �� ��� ��� ����� �� �����, "+pchar.name+"? � ����� � ����� ���� �� ���� �����!";
			link.l1 = "� ���� ����? ������� �������? ���� ����� ���, ��� �� �������� ���� ������...";
			link.l1.go = "result_16";
		break;
		
		case "result_16":
			dialog.text = "��� ���� - ��� ��� �����! � ������ ���, � ��� �������� ��� ������. ������� ���� � ���� ��� � ���� �� �����. � ���� �����... � �� ���� � ��� ���� ��������.";
			link.l1 = "��������... ������� ��������!..";
			link.l1.go = "result_17";
		break;
		
		case "result_17":
			dialog.text = ""+pchar.name+", � ����� ������ ���� �������: �� - ������, �� - ������������! �� ������� ������ ��� ����, ��� ��� ����� �� ������, ����� ��������� �� ���� �����. � ���� ���� � ����� �����. ������. � ���� �� ����� ��������, � ����� ����� �����... � ����� ����.";
			link.l1 = "�� ����� ������. ������!"; // � ���� �� �� ������ �������� :)
			link.l1.go = "result_18";
		break;
		
		case "result_18":
			dialog.text = ""+pchar.name+", �������... ������ ����! � ��� ����� ����� ����� �������!";
			link.l1 = "��������, ������� ���...";
			link.l1.go = "result_19";
		break;
		
		case "result_19": // ��������-�����
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			StartQuestMovie(true, true, true);
			PlayStereoOGG("music_romantic");
			bDisableCharacterMenu = true;//������� ����������
			InterfaceStates.Buttons.Save.enable = false;//��������� �����������
			locCameraRotateAroundHero(0.0, 2.0, 0.0, 0.01, 0.0, 2.0, 0.0, 580);
			DoQuestCheckDelay("Saga_HelenaRomantic", 20.0);
			pchar.GenQuest.MusicContinue = true;
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			DeleteAttribute(pchar, "questTemp.LSC.MaryWait");
		break;
		
		case "happy":
			dialog.text = ""+pchar.name+"! ��� ���� ������... ������������! � ������ �� ���� �������... ����� ��������� ��� �� ����. � ����� ���� ��� ��������!";
			link.l1 = "������ ��������, ��������!";
			link.l1.go = "happy_1";
		break;
		
		case "happy_1":
			DialogExit();
			LSC_MaryLoveWaitTime();
			SetLaunchFrameFormParam("��������� �����...", "", 0, 4);
			LaunchFrameForm();
			DoQuestCheckDelay("Saga_HelenaRomantic_5", 4.0);
			pchar.questTemp.Saga.Helena_officer = "true"; // ����������, ��� �������� - ���� ��������
		break;
		
	// -------------------------------------------- ������� ���� ------------------------------------
		case "failcenturion":
			dialog.text = "�������! ������� ���������... ��� ������, ��� ����� �� � ���� ������� � ����� ���� ����� ����� � ���������� ���?";
			link.l1 = "��, ��������, ��� ���. �� ������� � ���� ���� - ������ � '�����������' ������� ��������� � ����, ������� ����� �� ��������� ��� ����� ������ ����� ����, � �������� ���� ����� �� ���� ������. ��... ������ � ������� �������� ����� � ��������...";
			link.l1.go = "failcenturion_1";
		break;
		
		case "failcenturion_1":
			dialog.text = ""+pchar.name+", �� ���������. �� ��� �� ������ ��������. � ��-�� ���� ����� �� �������� - � ��������� ������� � ��� ����� �������. ������� ���� �� ���, ��� �� ������ ��� ����!";
			link.l1 = "�� ��� ��������, ������ �������... ��?";
			link.l1.go = "failcenturion_2";
		break;
		
		case "failcenturion_2":
			dialog.text = "��, ��� �������. ��� ������� �������� �� ����� ������ �����, ����������� ��� ������� � ���������� �����. � ���� ����� ����� ��� '������'. �� � ����� ��� �� ��� �������� � ��������, ������? � ����������� �����.";
			link.l1 = "�� ��� ��... �����, ��������!";
			link.l1.go = "failcenturion_3";
		break;
		
		case "failcenturion_3":
			DialogExit();
			RemovePassenger(pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 5.0);
			if (CheckAttribute(pchar, "questTemp.LSC.Mary") && GetCharacterIndex("Mary") != -1 && !CheckAttribute(pchar, "questTemp.LSC.Mary_officer")) // patch-6
			{
				pchar.questTemp.LSC.Mary = "return"; // � ����
			}
		break;
		
		case "late_l1":
			dialog.text = "�� ��� ��, ��� �������... ������, ��� � �� ������� ��� � ����� ����������� ����������. ������. � ����������� �����. �� ������������ � ���� ������ � ����� ���� ����� �����, ��� ��� ���, �����, �� ��� �������� � ����!";
			link.l1 = "�����, ��������. ��� ����, ��� ��� ��� �������� �����. ������.";
			link.l1.go = "failcenturion_3";
		break;
		
		case "late_l2":
			dialog.text = "�������! ������� ���������... ��� ������, ��� ����� �� � ���� ������� � ����� ���� ����� ����� � ���������� ���?";
			link.l1 = "��, ��������, ��� ���. �� ������� � ���� ���� - � ������� ����� ����� �������, � ���� ������ ������ - ���������� �������. � �� ������ ��� ����������� ����������, � ��� �������� ����� ������� ������...";
			link.l1.go = "failcenturion_1";
		break;
		
		case "late_l3":
			dialog.text = ""+pchar.name+", ��� ��� ������ �������?";
			link.l1 = "��! � ������� ����� ����� �������, � ���� ������ ������ - ���������� �������. � �� ������ ��� ����������� ����������, � ��� �������� ����� ������� ������... ���, �� �� ���������.";
			link.l1.go = "failcenturion_1";
		break;
	// <-- ������� ����
		
		// ���� - �������� ����������� �� ������ (������ �����, � ��� �� ������? :)) � ���� �� ������� �����
		case "cabin_sex":
			if (drand(4) == 0) // ����������� ������ 20%
			{
				dialog.text = RandPhraseSimple(""+pchar.name+", � ���� ���-�� ������ ������� ��������. �� ��������, ����������. ����� �� �������...",""+pchar.name+", �������, � ��� ������ �� ��������� ��������� ����. ������ ������, ��� ������� ������ �������. �� ��������. ����� � ������ ���.");
				link.l1 = RandPhraseSimple("�� ������...","�� ��������. ��� �������...");
				link.l1.go = "sex_exit";
			}
			else
			{
				dialog.text = RandPhraseSimple(""+pchar.name+", � � �������� ����������� ���� �����������! ����!",""+pchar.name+", �� ������� �� �� ��������! ����!");
				link.l1 = RandPhraseSimple("�� ��� �������...","�� - ������ ��������, ��������...");
				link.l1.go = "cabin_sex_go";
			}
		break;
		
		case "sex_exit":
			DialogExit();
			npchar.quest.daily_sex = true;
			SetFunctionTimerCondition("Helena_SexReady", 0, 0, 1, false);
		break;
		
		case "cabin_sex_go":
			DialogExit();
			chrDisableReloadToLocation = true;//������� �������
			DoQuestCheckDelay("Helena_LoveSex", 1.0);
			NextDiag.CurrentNode = "sex_after";
		break;
		
		case "sex_after":
			dialog.text = RandPhraseSimple("��� ���� �������, "+pchar.name+"!..","�� ��� ������ �� ������, �������...");
			link.l1 = RandPhraseSimple("� ���, ��� �� �������� ��������...","��� � ����� ����� ������, ��������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "Helena_officer";
			chrDisableReloadToLocation = false;//������� �������
			npchar.quest.daily_sex = true;
			SetFunctionTimerCondition("Helena_SexReady", 0, 0, 1, false);
		break;
		
		case "room_sex":
			if (CheckAttribute(pchar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "tavern")
			{
				dialog.text = ""+pchar.name+", � ������ ����� ����... �� ������ ������� �� ����� - ����� �������� ����� ��������� ����, ���� �� �� ������� ���-������.";
				link.l1 = "�� ��� ������ �����, ��� �������...";
				link.l1.go = "exit";
				break;
			}
			if (drand(4) == 0) // ����������� ������ 20%
			{
				dialog.text = RandPhraseSimple(""+pchar.name+", � ���� ���-�� ������ ������� ��������. �� ��������, ����������. ����� �� �������...",""+pchar.name+", �������, � ��� ������ �� ��������� ��������� ����. ������ ������, ��� ������� ������ �������. �� ��������. ����� � ������ ���.");
				link.l1 = RandPhraseSimple("�� ������...","�� ��������. ��� �������...");
				link.l1.go = "sex_exit";
			}
			else
			{
				dialog.text = RandPhraseSimple(""+pchar.name+", � � �������� �������� ���� �����������! ����!",""+pchar.name+", �� ������� �� �� ��������! ����!");
				link.l1 = RandPhraseSimple("�� ��� �������...","�� - ������ ��������, ��������...");
				link.l1.go = "room_sex_go";
			}
		break;
		
		case "room_sex_go":
			DialogExit();
			if (sti(pchar.money) >= 10) AddMoneyToCharacter(pchar, -10);
			DoQuestReloadToLocation(pchar.location+"_upstairs", "quest", "quest4", "");
			ChangeCharacterAddressGroup(npchar, pchar.location+"_upstairs", "quest", "quest3");
			DoQuestCheckDelay("Helena_LoveSex", 1.5);
			NextDiag.CurrentNode = "sex_after";
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Lorensia_officer":
			ref rLoc = &Locations[FindLocation(pchar.location)];
			dialog.text = LinkRandPhrase("��, "+pchar.name+"?","��, ��� �������?","������ ����, "+pchar.name+"...");
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "��������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			if (CheckAttribute(npchar, "quest.fugas"))
			{
				Link.l3 = "��������, � ���� � ����� ��������������.";
				Link.l3.go = "fugas";
			}
			Link.l1 = "��������, � ���� ��� ���� ���� ������������...";
            Link.l1.go = "stay_follow";
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && pchar.location == Get_My_Cabin() && !CheckAttribute(npchar, "quest.daily_sex"))
			{
				Link.l2 = RandPhraseSimple("��������, �����, ��������� � ����� ������... �� ��������� ���� �����? �� �� ������?","�������, �����, �������� ��������� ��������� ����� ���-�-���? �� �� ������?");
				Link.l2.go = "cabin_sex";
			}
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && rLoc.type == "tavern" && !CheckAttribute(npchar, "quest.daily_sex") && sti(pchar.money) >= 10)
			{
				Link.l2 = RandPhraseSimple("��������, �����, ������ ������� � ��������� ��� ������... �� ��������� ���� �����? �� �� ������?","�������, �����, �������� ��������� ��������� ����� ���-�-���? ������ �������... �� �� ������?");
				Link.l2.go = "room_sex";
			}
			link.l9 = "���� ������, ��������.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Lorensia_officer";
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
            dialog.Text = "����� �������, �������!";
            Link.l1 = "...";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "����� �������, �������!";
            Link.l1 = "...";
            Link.l1.go = "Exit";
        break;
		//<-- ----------------------------------- ���������� ���� ----------------------------------------
		
		// --> ��� �� ��������
		case "terrapin_grot":
			dialog.text = "��� �� ��� ���������! ������ ���� �����... �� �� ��� ����, ��� �������! ������ ������ �� ������ � ������ � ������������������ ������ ��� ��� �� ���������� ������! � ���� ���� ������ �� ���������� �� �����! �� ������� �������� ���� ������ ��������� �� �����, �������... �, ��� �� ��� �� ����? ��� ��� �������?";
			link.l1 = "��� ������ ����, ���� ���������� �����, ��������� '������� ���'. �� ������� �� �� �������.";
			link.l1.go = "terrapin_grot_1";
		break;
		
		case "terrapin_grot_1":
			dialog.text = "��� ���������! ����� ���������� �� ����, ���� ����... � ������ ������� �������� � ������ - ���� ��������� ������.";
			link.l1 = "�� �������, ��������! � ��� �� � ��� ���� �����?.. ������, ������ �� ����!";
			link.l1.go = "terrapin_grot_2";
		break;
		
		case "terrapin_grot_2":
			DialogExit();
			npchar.dialog.currentnode = "Lorensia_officer";
			LAi_SetOfficerType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			Terrapin_GotoShip();
		break;
		// <-- ��� �� ��������
		
		// --> �������
		case "on_coast":
			dialog.text = "�� �������-�� �� �������, ��� �������... ��� �� ���� ����������? �� ����� ������� ����.";
			link.l1 = "��������... �����, ��� ���������? ����, ������ �������������...";
			link.l1.go = "on_coast_1";
		break;
		
		case "on_coast_1":
			dialog.text = "����� �� ����� � ����������� �����, �� ����� �� ���� ��� ��������. � ���� ���� ������ �� ������������! ������ ���������� ���� � �������� �� ��� �������, � �������, ������ ��� ��� ������� �������, ��� �������� �� ������, ������ ����������� � ����� ������� �� �����\n��� ������ ������! �� ������ �������! �� ������ �������� ���� � �������� �� �� �������, �� ������ ���� �� ������: ������� ������� � ��� ���� �������� �������, � ���� ����� � ���� ��� ������������ � �����. � ����� ��� ������� ������ � � ��������� ��� �������� �� ����������\n������� ��� �������, � ���, ��� �����, ��������� �� ����� �� ������. � ������ ���������� ���� ����������� ������ �� ����� � ������ ������. ��� ���� ����� ���� �������, � ����.";
			link.l1 = "�� �������, ��������... ��� �� � ��� ���� �����?";
			link.l1.go = "on_coast_2";
		break;
		
		case "on_coast_2":
			dialog.text = "� �������� ���� � �����, � ����� � �� �����. � �� ��� ������ �������, ������ ������ ���� ������. � ���� �� ��� ��� ���� ������...";
			link.l1 = "�������, ��� �����. � � ����� ����� �����. ������� � ����� ������� ��� ��������?";
			link.l1.go = "on_coast_3";
		break;
		
		case "on_coast_3":
			dialog.text = "�����. � ������� � ���������� ���� ����, ����� � ��� ��������� � ���. �� ������ ������ ������ �����������!";
			link.l1 = "������, ��� �� ����, ��� �������. ���� �������� ���� �� �������� �������...";
			link.l1.go = "on_coast_4";
		break;
		
		case "on_coast_4":
			dialog.text = "�� ����������... ��� ��� '������� ���������', ��? ������ ��� �� ��� ������? � ������ ����� �� ������� �� ������ ��������, � ����� �������� �������� ����� ������?";
			link.l1 = "�� �������� ����� ��� ������, �� ������ �������� � ����� � �������������, ���������� ������. ������� ��� � �� �������� ��� �����. � ��� ������ ������� ������� ������ ������, ��� � ������������ � ����... ���� �����! ������� � �������� ����� ���������! �������� ����������...";
			link.l1.go = "on_coast_5";
		break;
		
		case "on_coast_5":
			dialog.text = "��� �� � ������������� � '������� ����������'. � ������ �� ������� � ����� � �������,  �������� ����� �� ������� ����� �� ���� ��������, � ���� ��������...";
			link.l1 = "������, ��������, �, �������, ����. �� ������ �� ������ ����� � ������� �������. � ������ �� ���������� �������������. ���� ��������� ������� ����� �� ��� ��-�� �������! �������, ����������� ������ ������ ��������� ���, ����� �� ����������� ���������.";
			link.l1.go = "on_coast_6";
		break;
		
		case "on_coast_6":
			dialog.text = "������. �� ���� ����� ������ ���� - ���� ���� �� ��� ��� ������� ������.";
			link.l1 = "�� �� �� �������� ��� ����������, ��� �������? �, ��������: � ����� ����...";
			link.l1.go = "on_coast_7";
		break;
		
		case "on_coast_7":
			chrDisableReloadToLocation = false;//������� �������
			dialog.text = "� ���� ����, �������...";
			link.l1 = "...";
			link.l1.go = "on_coast_8";
		break;
		
		case "on_coast_8":
			DialogExit();
			npchar.dialog.currentnode = "Lorensia_officer";
			LAi_SetOfficerType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			AddQuestRecord("Caleuche", "5");
		break;
		// <-- �������
		
		// �� ��������
		case "tieyasal":
			dialog.text = ""+pchar.name+", � ���-�� ������� ����, ��� ���� ������ ������ �����. ���� ������ - ��� ������. ����� �� ������������?";
			link.l1 = "������, �� ��������, ��� �������... � ����� ���. � ����� ����������� - � ����� ������� �����. ���� ��� ����� �������������.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "� ������ � ����� ������, ��� �������! � ����� - ���� �� ���� �����!";
			link.l1 = "�������, �������...";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "20");
			npchar.quest.Tieyasal = "teleport";
		break;
		
		// �� ���� ������
		case "islatesoro":
			dialog.text = "�, "+pchar.name+"! ���� ���� ������! ������ �������� �� ���� ������?";
			link.l1 = "�� ��� ��� ������ - �� �����. �, �������, �� ����� ���� ���������, ��������...";
			link.l1.go = "islatesoro_1";
		break;
		
		case "islatesoro_1":
			DialogExit();
			NextDiag.CurrentNode = "islatesoro";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}