void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, n, iTemp;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	bool ok;
    int iTest;
    ref rColony;
    string sFrom_sea = "";
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� �� ���� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
		break;
		
		// ����� ������� ������������
		case "Tuttuat":
			dialog.text = "����� ���� ������� ��� ������, ����� �������? ������������ �� ���� ������� ���� ������� �����.";
			if (GetCharacterFreeItem(pchar, "mushket1") || GetCharacterFreeItem(pchar, "mushket2"))
			{
				link.l1 = "����������, ������� ����� ������������. � ������ � ���� �� ������� � �������. ����� � ���� ���� ������ � ��� ���� ������.";
				link.l1.go = "Tuttuat_1";
			}
			else
			{
				link.l1 = "����������, ������� ����� ������������. � ������ � ���� �� ������� � �������.";
				link.l1.go = "Tuttuat_exit";
			}
		break;
		
		case "Tuttuat_exit":
			dialog.text = "������������ �� �������� ����� �������. ����� ���� - ������ ����. ��� ������� � ����������� ������, ������ ������ ���. ������������ �� ������ ����� ����� �������. ���� �������.";
			link.l1 = "��...";
			link.l1.go = "Tuttuat_exit_1";
		break;
		
		case "Tuttuat_exit_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat";
		break;
		
		case "Tuttuat_1":
			if (GetCharacterFreeItem(pchar, "mushket1")) sTemp = "mushket1";
			else sTemp = "mushket2";
			RemoveItems(pchar, sTemp, 1);
			PlaySound("interface\important_item.wav");
			Log_Info("�� ������ "+XI_ConvertString(sTemp)+"");
			dialog.text = "���� �����, ��� �������� ������������, ����� �������. ������������ ��������� ���� ����������. �� ��������. ����� ����� ���� ������ �������� �� ���?";
			link.l1 = "� ������, ��� �� ������ ���� �� ������� ���� �� ���. � ���� ���� ��������� ������, � ���� ������� ������� ������, ��� �� ������� ������ ��� ��������, ��� � ��� ���� ����� ��� ���������.";
			link.l1.go = "Tuttuat_2";
		break;
		
		case "Tuttuat_2":
			dialog.text = "�������� ��� ���� ������.";
			link.l1 = "���, ������, ������� �����.";
			link.l1.go = "Tuttuat_3";
		break;
		
		case "Tuttuat_3":
			PlaySound("interface\important_item.wav");
			dialog.text = "(�������������)... ���� ������� ������� ������, ����� �������. ���� ������ ������������ ������ ��� �����, ������� ������ �����. ��������� ���������� ����������� ��� ���������� ��������� � ������� ����. ���� ��� ���� ������� ������������.";
			link.l1 = "�� ����� ��� ��������, ��� � �������?";
			link.l1.go = "Tuttuat_4";
		break;
		
		case "Tuttuat_4":
			dialog.text = "����� ������� �������� ������������ ���� ������. ��, ��� ������� ����� ��� ��������� ���. �� � ��� ������� ���� �������� �� �������.";
			link.l1 = "�����, �� ����� �� ����... �����, �����, ��� ���� ����� ���� ������? �����, �� �������� � ���, ��� ������� ���� ����?";
			link.l1.go = "Tuttuat_5";
		break;
		
		case "Tuttuat_5":
			dialog.text = "��� ����, ����� �������, ���� ������ ����������. ���� �� ���� ������������ ��� ����. ������ ������� ������ ��� ����� �����, ��� ��������� ������.";
			link.l1 = "��� ���... ����������, � �������� ����� ������ ���� ��������. �� �����, �� ������� ��������� ���� ����� �������, ������� �����? �� ����� �� ������������...";
			link.l1.go = "Tuttuat_6";
		break;
		
		case "Tuttuat_6":
			dialog.text = "���� ���� ��� ��������� ���� ������, ���� �� ������ �������� �� �����. �� ��� ���������� ������, ����� �������.";
			link.l1 = "����� ������?";
			link.l1.go = "Tuttuat_7";
		break;
		
		case "Tuttuat_7":
			dialog.text = "����� �� ��������� ��� ������ ��� ������� ��� ����� ������. ��� �������� ������ ��������, �� ���� ��� ����������� ������, �� ���� ������-������ ��������. ����� � �������� ��� ��� ��� ������, � ��� �� ��� ������������. ��� ���� ���� ����, ������� ���� ������ �������� ��������.";
			link.l1 = "������� �� �����... ��� �� ����?";
			link.l1.go = "Tuttuat_8";
		break;
		
		case "Tuttuat_8":
			dialog.text = "���� ��� ������ � ���� �����. ����� � �������� ��� ��� ��� ������. ��� ���� �� ������. ������ � �����. ���� ����� �� ������ - ��� ����� ���� �� ����. ����, ����� �������. ������������ ����� � ������� ���� ������ ����.";
			link.l1 = "...";
			link.l1.go = "Tuttuat_9";
		break;
		
		case "Tuttuat_9":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_10";
			pchar.questTemp.Caleuche = "ghostship"; 
			AddQuestRecord("Caleuche", "3");
			pchar.quest.Caleuche_ghostship.win_condition.l1 = "location";
			pchar.quest.Caleuche_ghostship.win_condition.l1.location = "Dominica";
			pchar.quest.Caleuche_ghostship.function = "Caleuche_PrepareGhostship";
		break;
		
		case "Tuttuat_10":
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && Caleuche_CheckAmulet())
			{
				dialog.text = "����, ����� �������. ����� ��� ��� ������.";
				link.l1 = "��� �����, ������� �����. ���, ������.";
				link.l1.go = "Tuttuat_33";
			}
			else
			{
				dialog.text = "����, ����� �������. ����� ��� ������.";
				link.l1 = "...";
				link.l1.go = "Tuttuat_10_1";
			}
		break;
		
		case "Tuttuat_10_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_10";
		break;
		
		case "Tuttuat_11":
			dialog.text = "���� ����� �����, ����� �������? ���� ��������� ���, ��� ������������� �������� ����� �������.";
			link.l1 = "����, ������� �����. ���� � ����� � ����, ��� �� ���� ����� �������, ������ ������� ������ ���������! �� ������� ��������. �� ����� � ���� ������, ���� �� ���� ��� ����. � ����� ��� ������� ��� �����.";
			link.l1.go = "Tuttuat_12";
		break;
		
		case "Tuttuat_12":
			dialog.text = "������ �������, ����� �������. ������� ����� ����� �� �����.";
			link.l1 = "�������? ���� �������-������� ������ ���� ������� '������� ������'. �� ���� � �������-��������? � �� ������ ��� �� ���� �� ������? �� ���� �� � ����, ��� ���� �������� ������ �������� �� ��������, �...";
			link.l1.go = "Tuttuat_13";
		break;
		
		case "Tuttuat_13":
			dialog.text = "������������ ������, ����� ������� ���������. ����� ������� ������ �����������.";
			link.l1 = "�����������?";
			link.l1.go = "Tuttuat_14";
		break;
		
		case "Tuttuat_14":
			dialog.text = "��. ����������� � ��������� �������. ������� ���, ���� ��� ������ �������� �� ��� ������� ����, ������� �������� � ���� ��������?";
			link.l1 = "��... ���� �������. �� �������-�� � ���� ��� ���.";
			link.l1.go = "Tuttuat_15";
		break;
		
		case "Tuttuat_15":
			dialog.text = "��� ������� ����, ��� ������� ������ � ������� �������. ��� ���� �������. �� ���� ���� ������ ������� ��, �� ���� �������� ��� ������� ������� ������, ����� ������ ��������, �������� ����� � ���� ����� � ��� �������.";
			link.l1 = "���� ������! � � ������������� ���������� � ���� �������� ���������! �� ��� �� � � ��� ���������, ���� ��� �� �����, �� ���� �� �����?";
			link.l1.go = "Tuttuat_16";
		break;
		
		case "Tuttuat_16":
			dialog.text = "���� ����� ������� ���, ����� �������?";
			link.l1 = "��, ������� �����.";
			link.l1.go = "Tuttuat_17";
		break;
		
		case "Tuttuat_17":
			dialog.text = "����� ��� ���� ���� ��� ������� ����, � ����� ��� ����� ������� ����� ����� ���� �� ������� � ��� '������� ������'. ��� ����������� � ����, ��� ������� ������� �������, ���� ������� ���� ���� ������� ������ - ���� ����-������. ����� ���� ����� ���� � ������, � ���������� ������� �������. ��� ������� �� ��������� ���������� ��������� ������� - ���������� ����� �� ������, ���� ������ � ����������� ����-������\n����� ���� ���������� ���� �������. ��� ������ ��������� ����� ����, ����� ������� ��� ������, �� ���� ���� ������ ������� �� ����, ��� �� ������� � �������� �������. �� ������ ��������� ������� � �������. ��� ����� ����������, �� �� ������ ������ ������� ������� �� �����. ��� ��� � ������� ��� �����-����� ���, �� ��������� ����� ���� - ������. ��� ��������� �������\n�� ���� ����������, ����� ������, �� ��� ���������� ����. ���� �� �������� ���� ��� ���� - ��� �������� �����. ���� ��������� ���� - ��� �����������. ���� �� ������� ������� - ��� ������ ��� ��� ����, ��������� � ����� �����.";
			link.l1 = "������ �����...";
			link.l1.go = "Tuttuat_18";
		break;
		
		case "Tuttuat_18":
			dialog.text = "������� �������� ���� �� ������. �� �������� ��� ������� ������� � ����� ���������� ������. �� ���� �������� ����� � ��������� ����. �� ������ ������� � ������ ��� ������. ��� ������ - �� ������ ����� ���������. �� ��� ��� �� ������� �������.";
			link.l1 = "������? � ��� �����, ����� ����� ���������?";
			link.l1.go = "Tuttuat_19";
		break;
		
		case "Tuttuat_19":
			dialog.text = "���������� �����. �� ���� ������� � ���� �� ������, ���� �����-������. ���� ��������� ����� ����. ���������� ��� ����� ��������, ��� ���� �� ��� ���� �� ��������� �������� �� ������. ��� ������ ������� ���������� ����. ��� ������ ����� ��������� ���� - ���� �� ������ ������ � ������� � �������, � ��� ��� ������� ����, ��� �� ������ ������������ ����� ����������� ����� ��� ����.";
			link.l1 = "��! ��� �����, ��� �� ����� ���������� ����� �����? ������, �� ������� �������: �����������, ����������... �� � ��� ��� ��� ������� - ��� �� �� ����� ������� �� �����!";
			link.l1.go = "Tuttuat_20";
		break;
		
		case "Tuttuat_20":
			dialog.text = "� ��� ��� �����. ������� ��������� ��� ��� �� ����� ���� ������, ����� ������������ �� ��������� ����-������. ������ �� ���� ������, �� �� ����� ����� �������, � �������� ������� ������ � ����� ����� �� �� ������ �������. ����� �� �������� �����. ��� ��������� ���� ������, � ������ ��������� �� ��������� ��\n����� ������ �������, ��� ����� ������� �������, �� ������. �� ���� ��� �������. ��� ���� ������ ��� ������ � ����� �� ������. � ����� ����� ������� ���� ����� ����� �� ����� ������ � �����.";
			if (CheckAttribute(pchar, "questTemp.Caleuche.Skul"))
			{
				link.l1 = "���������� ����� � �������� ������� � ���������? �� � �� ������ ��� � ����� �����, ���� ������! � � ������ ��� ������-�� �����������... ��� ��� ���... ���������, ��� ��... ��, �� ��� � ������� - ����� �� ������! �� ����� ����� �������� ���. ���������, ��� �������� �� ���� ����������� ����!";
				link.l1.go = "Tuttuat_21_1";
			}
			else
			{
				link.l1 = "���������� ����� � �������� ������� � ���������? � ������� ������������, ��� ��� � ��� �������� �����? ��� ����� �� ������ ��������� � ������ ������ � ��� �������� ������� �����!";
				link.l1.go = "Tuttuat_21_2";
			}
		break;
		
		case "Tuttuat_21_1":
			dialog.text = "��� �����, ��� ����� ���� �� ������. ������� ������� ��������� ���. ��������� ����� ��� ��� ����� ����� ������ � �������. ������ �� �� ������ ��� �� ����� ���. ������� ������� �����������, ��� ���� �������� ����-������. ��� �� ������ ����� � ���� �������.";
			link.l1 = "���, �����. ��� � ������ �������?";
			link.l1.go = "Tuttuat_22";
		break;
		
		case "Tuttuat_21_2":
			dialog.text = "����� ������ ���� �����, �� ������. ������� ������� ��������� ���. ��������� ����� ��� ��� ����� ����� ������ � �������. ������ �� �� ������ ��� �� ����� ���. ������� ������� �����������, ��� ���� �������� ����-������. ��� �� ������ ����� � ���� �������.";
			link.l1 = "���, �����. ��� � ������ �������?";
			link.l1.go = "Tuttuat_22";
		break;
		
		case "Tuttuat_22":
			dialog.text = "���� ������ ����� ����� �� ������. ���� ������ ����� ��� ������, ��� ������� �� ��������. ��� ��� ������ �� ������ �������. ������ ���� ���� ���� ������������� ����-������.";
			link.l1 = "������������� �����-�������? ��� �� � ��� ������?";
			link.l1.go = "Tuttuat_23";
		break;
		
		case "Tuttuat_23":
			dialog.text = "����, ���� ���� ������ ������� ���������� �����, ���������� �� ��������� ������ �� ������. �� ���������� ����-������. ��� ������ ���� �� ������ ������ ���� ���. ����-������ ��� ����� ���� �������� ����, � ����� ������ ����� ����� ���������. �� ������ ���� ��� �� ������.";
			link.l1 = "����� ������? �� ��� �� ��� �����...";
			link.l1.go = "Tuttuat_24";
		break;
		
		case "Tuttuat_24":
			dialog.text = "���� ���� ����������, ����� �������? �� ������ - ��� ������, ���������� ����� �� ������ ������ ������ ��� ����� � �������. � ������ ���� ������ ������ ����, �������� ��� �����, ����� ����� �������, �������� ��� ������� � ������� ������, ������� �� � ���� ��������.";
			link.l1 = "� ����� �������� ������� ����� ��� �������?";
			link.l1.go = "Tuttuat_25";
		break;
		
		case "Tuttuat_25":
			dialog.text = "��� ������, ��� �� ������ ������� � ���� ����-������, � ������, ��� ������ ������ ��� � ����� ����. �� ��� ����� ���������. ������ ������� ������ ���������� ��������� ��� �����. �� ������� � ������ ������ � ���� ����-������, ������� � ������ ��� ������.";
			link.l1 = "� ��� �� ��������� ���� ������?";
			link.l1.go = "Tuttuat_26";
		break;
		
		case "Tuttuat_26":
			dialog.text = "������� ���� ����� ����� �� ������ � �������. ����� �� �������� �� ������.";
			link.l1 = "������. �� �� ���� ���������, ��� ������ ���������� �����?";
			link.l1.go = "Tuttuat_27";
		break;
		
		case "Tuttuat_27":
			dialog.text = "��� �� �����. �� �� �����, �� ������. ��� � �������. ������. ����������. �����.";
			link.l1 = "��... �����, ���� ���������.";
			link.l1.go = "Tuttuat_28";
		break;
		
		case "Tuttuat_28":
			dialog.text = "���� ���� ���������, ����� �������. ������� ����������� ��������� ��������. ����� ���� �������� ������, �� ���� ������. ���� ����� - ���� ������ �� ����. ���� �� ���� ���������� - ������ ��� ���� �� ������.";
			link.l1 = "��� ��������� ������� ����� �� �����, ��� �����!.. �� ���� � ��� ������� ���� ��������, ������� � ������ �����.";
			link.l1.go = "Tuttuat_29";
		break;
		
		case "Tuttuat_29":
			dialog.text = "������� ��� ��������� - �� ������ ������ ���������. ������ �������. ���� ������ ���� �� �������, ������� ������ ���� �� �������. ����� ���� ��������. ��� ������ ���� ����� ������ - ����� ����� ��� ���. �� ������ ������ �� �������.";
			link.l1 = "�� ��� � ��� �����. ������, ������� �����. ������� �� �������. ��� ���� ����.";
			link.l1.go = "Tuttuat_31";
		break;
		
		case "Tuttuat_31":
			dialog.text = "��� ����� ��������� ���� ���� � ������, ����� ��� ������ ���� ������ �� �������.";
			link.l1 = "...";
			link.l1.go = "Tuttuat_32";
		break;
		
		case "Tuttuat_32":
			DialogExit();
			LocatorReloadEnterDisable("Shore27", "boat", false);
			npchar.dialog.currentnode = "Tuttuat_10";
			pchar.questTemp.Caleuche = "mayak"; 
			AddQuestRecord("Caleuche", "6");
		break;
		
		case "Tuttuat_33":
			if (CheckCharacterItem(pchar, "kaleuche_amulet2")) RemoveItems(pchar, "kaleuche_amulet2", 1);
			else RemoveItems(pchar, "kaleuche_amulet3", 1);
			Log_Info("�� ������ ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "(�������) ��, ��� ��. ������ ������ �������. ���� �������. ���� ����� ����� ��� ���� ������.";
			link.l1 = "� �����, �����. ����� �� ����� � ����.";
			link.l1.go = "Tuttuat_34";
		break;
		
		case "Tuttuat_34":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_35";
			AddQuestRecord("Caleuche", "22");
			if (!Caleuche_CheckAmulet())
			{
				if (GetCharacterIndex("Map_Caleuche") != -1)
				{
					sld = characterFromId("Map_Caleuche");
					sld.lifeday = 0;
					Map_ReleaseQuestEncounter("Map_Caleuche");
				}
			}
		break;
		
		case "Tuttuat_35":
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && Caleuche_CheckAmulet())
			{
				dialog.text = "����, ����� �������. ����� ��� ���� ������.";
				link.l1 = "�� ��� � ����, ������� �����. ���, ������.";
				link.l1.go = "Tuttuat_36";
			}
			else
			{
				dialog.text = "����, ����� �������. ����� ��� ���� ������.";
				link.l1 = "...";
				link.l1.go = "Tuttuat_35_1";
			}
		break;
		
		case "Tuttuat_35_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_35";
		break;
		
		case "Tuttuat_36":
			if (CheckCharacterItem(pchar, "kaleuche_amulet2")) RemoveItems(pchar, "kaleuche_amulet2", 1);
			else RemoveItems(pchar, "kaleuche_amulet3", 1);
			Log_Info("�� ������ ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "(�������) ��, ��� ��. ������ ������ �������. ���� �������. ���� ����� ��� ������ ������, ����� ������ ����� ��������, ����� �� ������, ������� �����-������.";
			link.l1 = "������, ��� � ������� - ���� �� ���������� �������?";
			link.l1.go = "Tuttuat_37";
		break;
		
		case "Tuttuat_37":
			dialog.text = "���� �������� ���������. ���������� ����� �� ������. ���� ������ ������� ��� ���� �������. ����� ������� ������ ���� ���� ������.";
			link.l1 = "������������, �������� - ��� ��� ������? � ���� ���� ���� �����-�� �������������?";
			link.l1.go = "Tuttuat_38";
		break;
		
		case "Tuttuat_38":
			if (CheckAttribute(pchar, "questTemp.Caleuche.Skul"))
			{
				dialog.text = "���. ���� ������, ��� ���� ��������� ��� ������ ���������� �����. ���� ������. ���� ������ ������.";
				link.l1 = "������, ������� �����. � ������ ���, ��� � ���� �����.";
				link.l1.go = "Tuttuat_39";
			}
			else
			{
				dialog.text = "����� �� ������ ������������ ���� ����� ������. �� ��� ������. ���� ���� ��� �������. ��� �������, ��� ������ ���� � ������ �� ������ ���������. ������ ����� ������ �� ������ ���������, � ���� ���� ������ ���-��.";
				link.l1 = "������, ������� �����. � ������ ���, ��� � ���� �����.";
				link.l1.go = "Tuttuat_39";
			}
		break;
		
		case "Tuttuat_39":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_40";
			AddQuestRecord("Caleuche", "23");
			if (CheckAttribute(pchar, "questTemp.Caleuche.Skul")) sTemp = "����� � ��������� ������� - ������ ��� � ������ ���������� ����� ������� ���������.";
			else sTemp = "������������ �������, ��� ���������� ������� ������������� �����-�� '����� ������' � ����������� ������ �� ����������� ��������. ��� �� ��� ��� ����?";
			AddQuestUserData("Caleuche", "sText", sTemp);
			if (GetCharacterIndex("Map_Caleuche") != -1)
			{
				sld = characterFromId("Map_Caleuche");
				sld.lifeday = 0;
				Map_ReleaseQuestEncounter("Map_Caleuche");
			}
			pchar.questTemp.Caleuche = "skul";
			pchar.quest.Caleuche_villemstad.win_condition.l1 = "location";
			pchar.quest.Caleuche_villemstad.win_condition.l1.location = "Villemstad_town";
			pchar.quest.Caleuche_villemstad.function = "Caleuche_CreateMonk";
		break;
		
		case "Tuttuat_40":
			dialog.text = "����, ����� �������. ����� ���������� ����� �� ������.";
			if (pchar.questTemp.Caleuche == "island")
			{
				link.l1 = "�� � ����, ������� �����. �������.";
				link.l1.go = "Tuttuat_45";
			}
			else
			{
				link.l1 = "...";
				link.l1.go = "Tuttuat_40_1";
			}
		break;
		
		case "Tuttuat_40_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_40";
		break;
		
		case "Tuttuat_41":
			dialog.text = "����, ����� �������. ����� ���������� ����� �� ������.";
			link.l1 = "�����, ��� ��� �� �������� ����� �������. � ����� �������, �� � ����� ��������� ������ �� ����������� � ���� �� ��� ������ � ���������� �������. ��� �� ������ - �� ���� ���� ��������� �������������.";
			link.l1.go = "Tuttuat_42";
		break;
		
		case "Tuttuat_42":
			dialog.text = "����� �����, ����� �������. ������ ���� �� ������ ������ ����, �� ������ �������� �������. ��� �� ������� ���� �������. ���� �������.";
			link.l1 = "...";
			link.l1.go = "Tuttuat_43";
		break;
		
		case "Tuttuat_43":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_44";
		break;
		
		case "Tuttuat_44":
			dialog.text = "���� �������, ����� �������.";
			link.l1 = "...";
			link.l1.go = "Tuttuat_44_1";
		break;
		
		case "Tuttuat_44_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_40";
		break;
		
		case "Tuttuat_45":
			dialog.text = "(�������) ��, ��� ��. ����� ��������. �� � ����� ��������.";
			link.l1 = "��� �����... �� ��� ��� ���������: � ������� � ���������� ������� �� ��������� ����, �� ���� �� ��������, � ������� ���� �� ��������� �������. � ��� ����� �� �����! ����� �� � ��� ���� �������, ���� ������ ������� ��������� ������� ����...";
			link.l1.go = "Tuttuat_46a";
		break;
		
		case "Tuttuat_46a":
			dialog.text = "��� �������� - ������� ������� �����. ������ ���������� � ��� ���. ��������, �� ������ ������� ���������� ����� ���������� ������� ��� ������� �������, ����� �������� ���������. ������� �� ���� ������� ��� ������ ��������� ��� ������� ������ ��� �����, �������� �������� � ������� ���� ��������� �������� �� ������...";
			link.l1 = "���������� - ���� ���������� ����� � ���� �� �����, � ���� �� ������� ���� �������?";
			link.l1.go = "Tuttuat_46b";
		break;
		
		case "Tuttuat_46b":
			dialog.text = "����������, ���, �����������. ���� ��� ��������� ���.";
			link.l1 = "����� ������! ������, � ���� ����� ��� ������������ ������� ��������, � ������� �������� �������, ����� �������� ����� �������� �������� ��������� ����, ����� �������� ������ � ����, �� ��������, ��� �� ���������� ���� ������...";
			link.l1.go = "Tuttuat_46c";
		break;
		
		case "Tuttuat_46c":
			dialog.text = "";
			link.l1 = "...������, � ��������. ���� � ������ ������ ������� ���������� �����?";
			link.l1.go = "Tuttuat_46";
		break;
		
		case "Tuttuat_46":
			dialog.text = "���� ������ ������� ��� � ���� ������� � ��������� ���� ����. ��� ���������� ���� �������, ���� ����� �������, ����� �������?";
			link.l1 = "��� ��� ������ ������� ��� ����� ����, ������������.";
			link.l1.go = "Tuttuat_47";
		break;
		
		case "Tuttuat_47":
			dialog.text = "��� �������� �������� ��� ������, ������� ����� ������� ������-�����, ����� ����������� ���� ��� �� ������� �� ��� �����, ��������� �������-������� ����� � ��������� ��� � ����� ����� � ���� ������ �������. ����� ����������� ��� ������� �����, ����� ��� ���� � ���� �� ������ �����. ��� ����� � ���� ������ ������� ��������� �����, �������� ���, ��������� ������� � ������� ���� �� ������, ����� ����� ������� ������ ��� ������� ������\n����� � ������ ����� �� ���� ��������� �����, �� ����� ����� �� ������ �� ��� �����, �� ������ �����, �� �����. �������� �������, ��� ��� ��� � ���� �� ���� ������, �� ����� ������ �� ����� ������ �������� � ���� � ��������, ��� �� ��� ����� ��� ��� ����� ���� � ��� ������ ����������� �� ������\n���� ������ ������� - ��� ������, ����� �������. ���� �� ������ ���� �� ���� �� ������, ��� �� ���� �� �����, �� ������. ������ ����� �� ������, ��������, �� ��� ��� �������� ��������� �������� ����.";
			link.l1 = "� ��� �� ��������� ���� ������?";
			link.l1.go = "Tuttuat_48";
		break;
		
		case "Tuttuat_48":
			dialog.text = "�� �������� ��� ��������, ��� �� �����, � ���������� �� ������ � ��� ������� �� �����������, ������� ����������� ����� '�����', �� ���� ������� ����, ������� ���� ������ ����� '�����'.";
			link.l1 = "��. �� ����� �� �������� �� ������� � �������? ���� ������, �� ��� �� �������� ������� ����! ��� ��� ������ ��������� ��������, � ������� �� ��� ��� ����� �� ������?";
			link.l1.go = "Tuttuat_49";
		break;
		
		case "Tuttuat_49":
			dialog.text = "��� �� ����� ���� ������ � �������� ���� ������. �� ��� ����� ��� ���� �������. ���� ���� ��� ������� �� �� ���� ������. ����� �������� ��� ���� ����� ��� ������ ����� � �������� ����� �������. ������ � ������� � ������ �� ���������� � ���� �� ������ � ������ ������ ��� ���������� ������ - ������� ��������. � ������ ������ �� ������� ��� ����������� ������� �������\n����������� ��������� ����� � �������� ������� � ������� �������, �������� �� ��� ��� ���������� ������. ��������� ������� �������� � ����������� ������� ������ �������� ���, �� ��� ���������� ������ ������������ ������. ���� ���� ������ ����� ���� ����������� - �� ���������� ����, ��� ������.";
			if (CheckAttribute(pchar, "questTemp.NatanStory")) link.l1 = "��! �������, � ����, ��� ���� �����������... �� ������ ������� �������. ������� ��� ��������?";
			else link.l1 = "��. ��� ������� ��� ��������?";
			link.l1.go = "Tuttuat_50";
		break;
		
		case "Tuttuat_50":
			dialog.text = "��, ���� ��������, �� ��������� �������� �� �� ������, � ��� �������� ���� ������� � ����� ����������� � ���� ������ �����.";
			link.l1 = "���, �����, � �������� �������, �� ��� � ������ ������ � �����? ���� �������� �����? ��� ���������� � �������-��������, ������� ��� ��������? ���� ��� ����� �� ��������, ������� �������� ���� ������ ��������, �� ����� ���� ���� �� �������� - ��� ������, ��� ������ ������.";
			link.l1.go = "Tuttuat_51";
		break;
		
		case "Tuttuat_51":
			dialog.text = "�� ����� ��. ��������, ������� ���� �������� ����� ������ ��� ������ �����, ������� ������ ���, ������� ��������� ��� �� ������. ���� ���� �� ������ ������� �� ����, � ��� ����� ���� ����.";
			link.l1 = "������, � ��� �� ����� ��� ����������� ������ � ���� � ������� ��������?";
			link.l1.go = "Tuttuat_52";
		break;
		
		case "Tuttuat_52":
			dialog.text = "�� ������� ������ ����������� � ���� ��� �������� ���� ������� �����-������, ������� �����-�� ������ ���� � ������� �����. ����������� ������ �������� �� - �� ���� ������� ����. ����� ��� ���������� ������ ���� �������, �� ������ ������������. �� ������� �� ����������� ���� ����� � �����, � ���� �� ��������� ����, �� ����������� ������ ������� ������ � ��������. ������ �� ������ �������� ��� ������ ���� ����������� �����-������.";
			link.l1 = "������ ������������! � ��� �� � ���� ������ ������?";
			link.l1.go = "Tuttuat_53";
		break;
		
		case "Tuttuat_53":
			dialog.text = "��� �������� ����, ����� �������. ��� ���� ���� ��� ������ �������, ������� ���� ��� ��������. ��� ���������� � ���� ������ � �������� ������ ����. ����� ���� ������ ������, ���� ������ ������� � �����-������ ��� � ����� �������, �� ������� ������. ������ �������� ���� � �������� ���� ������ ����, ��������� ������� ���� �������� �� ����.";
			link.l1 = "�� ������, ��� ������� ������� ���?";
			link.l1.go = "Tuttuat_54";
		break;
		
		case "Tuttuat_54":
			dialog.text = "��� �����. ��� �������� � ������. ��� ������� �����. ���� ������ ���. � ���� ���� ��� ������ � �����. ���� - ��������, ������ - ������ ���� ������. ���� ������ ���� ������ �����. ����� - �������� ���. ���� �� ���� �� ���� ���� ������ - ���� ��������� �� ������ ����-�����\n� ���� �������, ��� ��� ������ ��������� �������, �� ������ ������� ��� �����-������, ������� ���� �����. ���� ������ ���������� ����� ���, ����� �� ��������� � �������� �����.";
			link.l1 = "����.";
			link.l1.go = "Tuttuat_55";
		break;
		
		case "Tuttuat_55":
			dialog.text = "���� ����� ������. ��� ���. �� ���� �������, ��� ���� ������ �� ���� �����, � ��������� ����� ���� ����. ���� �������, ��� �������� - ���� �� ������ �������� ���� ������? ������ ������� ����� ��� ����� ����� ���.";
			link.l1 = "�����. ������, � ���� ���� ����? ���� �����?";
			link.l1.go = "Tuttuat_56";
		break;
		
		case "Tuttuat_56":
			dialog.text = "��. ����� ���� ������ � ���� �� ������, ���� ������ ����� ���������, � � ��� - ������� ������ ������. ��� ����� ������ ����� ����. ���� �������� ���������� ����� �� ������ � ��������� ����� � �������. � ����� �� ����� ������� �� ���� - ���� ������ �������� ���, ��� �� ���� ������� �������. � ����� �������� ��� ������, ������� �� ������ � ����, � �������� �������.";
			link.l1 = "������? ��� ���?";
			link.l1.go = "Tuttuat_57";
		break;
		
		case "Tuttuat_57":
			dialog.text = "������ - ��� ������� �����, ������� ���� ��� ������. � ������ � ������, ������ �������� � ��������� ������� ������ ������.";
			link.l1 = "�� ��� ��, ���� ������...";
			link.l1.go = "Tuttuat_58";
		break;
		
		case "Tuttuat_58":
			dialog.text = "���� ���� ���������. ����� �����-������, ���� ����� � ���� ������ ���������.";
			link.l1 = "����� ���������?";
			link.l1.go = "Tuttuat_59";
		break;
		
		case "Tuttuat_59":
			dialog.text = "��� ����� �� �����. ���� ������� ���. ��� ���� ���� �������� �������. ��� �����, ����� �������� ����. � ��������� ���� ������ �������. ���� ��������� ���� ���������, � ���� ������ ������ ������� ���. ��� ������ ���� �� ������ ������� ���� � �����, �� � ������� ���������.";
			link.l1 = "��! ������ �������, �� ��� ��� �� ���������! �� ���� ������ ������� � ������ � ����!";
			link.l1.go = "Tuttuat_60";
		break;
		
		case "Tuttuat_60":
			dialog.text = "�������, ����� ����. ��� ��������� ���� � ������ ���� � ����� ������ �����-������ � �������.";
			link.l1 = "...";
			link.l1.go = "Tuttuat_61";
		break;
		
		case "Tuttuat_61":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_62";
			Log_Info("�� �������� ��� �������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "kaleuche_amulet2");
			GiveItem2Character(pchar, "kaleuche_amulet3");
			// ����������� �������
			ChangeItemDescribe("kaleuche_amulet2", "itmdescr_kaleuche_amulet2_sword");
			ChangeItemDescribe("kaleuche_amulet3", "itmdescr_kaleuche_amulet3_shield");
			sld = ItemsFromID("kaleuche_amulet2");
			sld.picIndex = 13;
			sld.picTexture = "ITEMS_36";
			sld.groupID = TALISMAN_ITEM_TYPE;
			sld.unique = true;	
			sld.ItemType = "ARTEFACT";
			sld = ItemsFromID("kaleuche_amulet3");
			sld.picIndex = 14;
			sld.picTexture = "ITEMS_36";
			sld.groupID = TALISMAN_ITEM_TYPE;
			sld.unique = true;	
			sld.ItemType = "ARTEFACT";
			SetFunctionTimerCondition("Caleuche_TuttuatAmuletOver", 0, 0, 30, false); // ������
			// ������ ��������� ����� ���
			n = FindIsland("KhaelRoa");
			Islands[n].visible = true;
			Island_SetReloadEnableGlobal(Islands[n].id, true);
			Islands[n].reload.l1.radius = 150.0;
			Islands[n].reload.l2.label = "Shore64_1";
			Islands[n].reload.l2.name = "reload_2";
			Islands[n].reload.l2.go = "";
			Islands[n].reload.l2.emerge = "";
			Islands[n].reload.l2.radius = 0.0;
			Islands[n].reload.l2.pic = 0;
			Islands[n].reload.l2.tex = "t1";
			pchar.questTemp.Caleuche = "khaelroa";
			pchar.quest.Caleuche_khaelroa_arrive.win_condition.l1 = "location";
			pchar.quest.Caleuche_khaelroa_arrive.win_condition.l1.location = "KhaelRoa_port";
			pchar.quest.Caleuche_khaelroa_arrive.function = "Caleuche_KhaelRoaArrive";
			AddQuestRecord("Caleuche", "34");
			if (CheckAttribute(pchar, "questTemp.NatanStory"))
			{
				pchar.questTemp.Caleuche.NatanInfo = "true";
				AddQuestUserData("Caleuche", "sText", "�� � ���� ���� �������: ������, ��� ����� �������, ���������� � ����� ��������, �� ��� ����, ��� ��� ������ ���� ��������� ����. �� �������, ��� � �����-����� � ���� ���� ����� ����� �������. ���� ��������� ������.");
			}
			else AddQuestUserData("Caleuche", "sText", "������ �������� ����� �������� ������������, �� ������ ������: ���� ��������� ��������� �����.");
		break;
		
		case "Tuttuat_62":
			if (pchar.questTemp.Caleuche == "regard" && CheckCharacterItem(pchar, "kaleuche_amulet1") && CheckCharacterItem(pchar, "kaleuche_amulet2") && CheckCharacterItem(pchar, "kaleuche_amulet3")) 
			{
				dialog.text = "��� �������� � ����. ���� ���� �� ������ � ���� �� ������. �� ����� ������� � ������?";
				link.l1 = "�� ����, ������� �����. � ����� ������, ������� � ����� � ������� � ��� ���������� �����.";
				link.l1.go = "Tuttuat_63";
			}
			else
			{
				dialog.text = "�������, ����� ����.";
				if (CheckAttribute(pchar, "questTemp.Caleuche.AmuletOver"))
				{
					link.l1 = "������������, ��� ����� ����... � �� ����� ������� ���������� ����� � ����, � ���� ������� �������� ����...";
					link.l1.go = "Tuttuat_82";
				}
				else
				{
					link.l1 = "...";
					link.l1.go = "Tuttuat_62_1";
				}
			}
		break;
		
		case "Tuttuat_62_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_62";
		break;
		
		case "Tuttuat_63":
			pchar.quest.Caleuche_TuttuatAmuletOver.over = "yes"; //����� ������
			if(IsEquipCharacterByArtefact(pchar, "kaleuche_amulet2")) RemoveCharacterEquip(pchar, TALISMAN_ITEM_TYPE);
			if(IsEquipCharacterByArtefact(pchar, "kaleuche_amulet3")) RemoveCharacterEquip(pchar, TALISMAN_ITEM_TYPE);
			dialog.text = "���� ����� ��������� � �������. �� ����� ���� ����� �����?";
			link.l1 = "��. �� ����������� ����� � �������. � ������� � ��� � ��� � ������� ���. ������ ��� ��� ������� � ����. ������ ��.";
			link.l1.go = "Tuttuat_64";
		break;
		
		case "Tuttuat_64":
			RemoveItems(pchar, "kaleuche_amulet1", 1);
			RemoveItems(pchar, "kaleuche_amulet2", 1);
			RemoveItems(pchar, "kaleuche_amulet3", 1);
			Log_Info("�� ������ ��� ��������� �������");
			PlaySound("interface\important_item.wav");
			dialog.text = "���� ������� � ������� ����, �����������. ������������ �� ������ ����� �������. �� ��� ������� ������� � ������ ����. ���� ������� ������� ���� - �������� ���� �� �������. ���� �������� ��� ��� ������. ��� ������������ ����.";
			link.l1 = "�� ������ ���-�� ������ '����, ������� � ����� ��������'?";
			link.l1.go = "Tuttuat_65";
		break;
		
		case "Tuttuat_65":
			dialog.text = "���� �������� ������. � ���� ���� ���� ����. ����� �� ������ �� ����� ������ ��������, ������� ����� ���. ������� �� ���, �����������! �� ��� ������ ����� �������� �����. �� �������� �� '���������'. ���� ������� ��� ����� �����?";
			if (CheckAttribute(pchar, "questTemp.Mangarosa.Tell"))
			{
				link.l1 = "��. � ������ � ����� ��� �����. �� ����� ������������ �������. � ���� �� ���, �������� ������, ���� ����� ������ �� ���...";
				link.l1.go = "Tuttuat_66";
			}
			else
			{
				link.l1 = "���.";
				link.l1.go = "Tuttuat_66_1";
			}
		break;
		
		case "Tuttuat_66":
			dialog.text = "��� ������� ��� �������� � ��� ������. ��� ���� �����. ��� �� ����� ����� ���������. ������ ������� ����� ��� ������, ������ �� ������ ������� ���� �����, ����� �������� �� �������� ����.";
			link.l1 = "��� �� ����?";
			link.l1.go = "Tuttuat_67";
		break;
		
		case "Tuttuat_66_1":
			dialog.text = "���� ����� ����� �� ��� ������, �� ����� ����������� � �� ������. ��� ������-������� ������� ��������, � ������, ��� ������������� ������ ������, � �������� �����. ���� ����� ������ ���� ����� � �� ������� ��� �� � ���. ��� ����� ������ ������� ���� ����� � ������� �� ��� ����.";
			link.l1 = "��� �� ����?";
			link.l1.go = "Tuttuat_67";
		break;
		
		case "Tuttuat_67":
			dialog.text = "��� ����� �������� �� ��������� �����. ����� ������� �����, ����� �� ������, ����� ���, �� ����� ������ �����. ��� ����� ������ ������� �������� �������, ������, �����, ����������, �����, �������� � ���������. ��� ������� ��� ���� ��� �����.";
			link.l1 = "����� ���������!";
			link.l1.go = "Tuttuat_68";
		break;
		
		case "Tuttuat_68":
			dialog.text = "���� - ������� ����, ������� ���� ������ ����� �����, ������� ������� ���� ������� � ��� � ������������ � �����. � ������ ����� ���� ������� ���, ����� ��� ������� ��� ������. �� ���� ������ �������� ��� ��� ����� ���������, ��� ��� � ��� �� ���.";
			link.l1 = "��� ����� ������ ���������?";
			link.l1.go = "Tuttuat_69";
		break;
		
		case "Tuttuat_69":
			dialog.text = "��������� - ������ ����� �� ������. ����� ���, ��� ���� ���� ������. ����������� ���� ������� ���� �����, ������ � ������ ��. ��� ������� ��������. ������ ������� � �����, �������� �����, ��� �� ������ ������ ����. �������� ������������. �� ������ ����� ��� ����� ���� ������� ���������.";
			link.l1 = "������, ������� �����. ��� ������ � ����� ���������� ��������� - � ����� � ����.";
			link.l1.go = "Tuttuat_70";
		break;
		
		case "Tuttuat_70":
			dialog.text = "�������, ����� ����. �������� ���������. ���� �� ��������. ��� ����� - ������ �����. ��� �������� ����, ����� ��� ������ ���� � ������.";
			link.l1 = "�������. �� �������!";
			link.l1.go = "Tuttuat_71";
		break;
		
		case "Tuttuat_71":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_72";
			pchar.questTemp.Caleuche = "mangarosa";
			pchar.questTemp.Caleuche.Mangarosa = 0;
			AddQuestRecord("Caleuche", "41");
		break;
		
		case "Tuttuat_72":
			dialog.text = "���� �������� ���� ������� ��������� ��� �����?";
			if (GetCharacterItem(pchar, "cannabis7") >= 5)
			{
				link.l1 = "��. ��� ���� ��������, ������� ���� �����.";
				link.l1.go = "Tuttuat_73";
			}
			link.l2 = "���� ���, ������� �����. �� � ���� � �������...";
			link.l2.go = "Tuttuat_72_1";
		break;
		
		case "Tuttuat_72_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_72";
		break;
		
		case "Tuttuat_73":
			RemoveItems(pchar, "cannabis7", 5);
			switch (sti(pchar.questTemp.Caleuche.Mangarosa))
			{
				case 0:
					dialog.text = "����� ������. ��������� ������, ����� ������ �������� �� �������. � ������� ��� ���� �����, ������� �������� ���� ������� � ��������.";
					link.l1 = "������, �����. � ����� ������ �������.";
					link.l1.go = "Tuttuat_74";
					pchar.questTemp.Caleuche.Mangarosa = 1;
				break;
				
				case 1:
					dialog.text = "����� ������. ��������� ������, ����� ������ �������� �� �������. � ������� ��� ���� �����, ������� �������� ���� ������������.";
					link.l1 = "������, �����. � ����� ������ �������.";
					link.l1.go = "Tuttuat_74";
					pchar.questTemp.Caleuche.Mangarosa = 2;
				break;
				
				case 2:
					dialog.text = "����� ������. ����� ����� ���� ��������? ����� ����, ��������, ��, �������, �����?";
					link.l1 = "����� ����.";
					link.l1.go = "Tuttuat_77_1";
					link.l2 = "����� ��������.";
					link.l2.go = "Tuttuat_77_2";
					link.l3 = "����� ���.";
					link.l3.go = "Tuttuat_77_3";
					link.l4 = "����� �������.";
					link.l4.go = "Tuttuat_77_4";
					link.l5 = "����� �����.";
					link.l5.go = "Tuttuat_77_5";
				break;
			}
		break;
		
		case "Tuttuat_74":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_75";
			pchar.quest.Caleuche_mangarosa_potion.win_condition.l1 = "Timer";
			pchar.quest.Caleuche_mangarosa_potion.win_condition.l1.date.hour  = 19.0;
			pchar.quest.Caleuche_mangarosa_potion.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Caleuche_mangarosa_potion.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Caleuche_mangarosa_potion.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Caleuche_mangarosa_potion.function = "Caleuche_MangarosaPotion";
		break;
		
		case "Tuttuat_75":
			if (CheckAttribute(pchar, "questTemp.Caleuche.Potion"))
			{
				sTemp = "";
				if (sti(pchar.questTemp.Caleuche.Mangarosa) == 1) sTemp = " �� ������� ���� �������� �������, � ���� ������ ��������� ����� ������ ������� ������.";
				if (sti(pchar.questTemp.Caleuche.Mangarosa) == 2) sTemp = " �� ������� ���� ���������� � ������ �����, � ���� ������ ��������� ����� ������ �����.";
				dialog.text = "����� ������, ����������� ����. ���� ����� ��."+sTemp+"";
				link.l1 = "�������, ������� �����.";
				link.l1.go = "Tuttuat_76";
			}
			else
			{
				dialog.text = "���� ��� ����, ����� �������. ���� ��������� �����. �� ������ ���.";
				link.l1 = "������...";
				link.l1.go = "Tuttuat_75_1";
			}
		break;
		
		case "Tuttuat_75_1":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_75";
		break;
		
		case "Tuttuat_76":
			if (sti(pchar.questTemp.Caleuche.Mangarosa) > 2)
			{
				dialog.text = "��� ������� ���� ��� �����, ��� �������. �� ����� �������. ���� �������?";
				link.l1 = "��, ������� �����. ���� ������� ���� ���������.";
				link.l1.go = "Tuttuat_78";
			}
			else
			{
				dialog.text = "����� ���� ����� ��� ���� ������� ��������� - ��������� ���. ��� ������� ���� ��� ���� �����.";
				link.l1 = "� ����������� ������� ��� �����. �� �������!";
				link.l1.go = "Tuttuat_77";
			}
		break;
		
		case "Tuttuat_77":
			DialogExit();
			npchar.dialog.currentnode = "Tuttuat_72";
			DeleteAttribute(pchar, "questTemp.Caleuche.Potion");
			if (sti(pchar.questTemp.Caleuche.Mangarosa) == 1)
			{
				GiveItem2Character(pchar, "kaleuche_amulet1");
				ChangeItemDescribe("kaleuche_amulet1", "itmdescr_kaleuche_amulet1_potion");
				sld = ItemsFromID("kaleuche_amulet1");
				sld.name = "itmname_kaleuche_amulet1_potion";
				sld.groupID = SPECIAL_ITEM_TYPE;
				sld.picIndex = 15;
				sld.picTexture = "ITEMS_35";
				sld.price = 0;
				sld.Weight = 1.0;
				sld.ItemType = "SUPPORT";
			}
			if (sti(pchar.questTemp.Caleuche.Mangarosa) == 2)
			{
				GiveItem2Character(pchar, "kaleuche_amulet2");
				ChangeItemDescribe("kaleuche_amulet2", "itmdescr_kaleuche_amulet2_potion");
				sld = ItemsFromID("kaleuche_amulet2");
				sld.name = "itmname_kaleuche_amulet2_potion";
				sld.groupID = SPECIAL_ITEM_TYPE;
				sld.picIndex = 15;
				sld.picTexture = "ITEMS_35";
				sld.price = 0;
				sld.Weight = 1.0;
				sld.ItemType = "SUPPORT";
			}
		break;
		
		case "Tuttuat_77_1":
			dialog.text = "��������� ������ ��� ������. ��� ������� �����, ������� ������� ���� �������, � ���� ������ ��������� ����� ������� �����.";
			link.l1 = "������.";
			link.l1.go = "Tuttuat_74";
			pchar.questTemp.Caleuche.Mangarosa = 31;
		break;
		
		case "Tuttuat_77_2":
			dialog.text = "��������� ������ ��� ������. ��� ������� �����, ������� ������� ���� �����, � ���� ������ �������� ����� �� �������� ������.";
			link.l1 = "������.";
			link.l1.go = "Tuttuat_74";
			pchar.questTemp.Caleuche.Mangarosa = 32;
		break;
		
		case "Tuttuat_77_3":
			dialog.text = "��������� ������ ��� ������. ��� ������� �����, ������� ������� ���� �����, � ���� ������ ��������� ����� �� �����.";
			link.l1 = "������.";
			link.l1.go = "Tuttuat_74";
			pchar.questTemp.Caleuche.Mangarosa = 33;
		break;
		
		case "Tuttuat_77_4":
			dialog.text = "��������� ������ ��� ������. ��� ������� �����, ������� ������� ���� ��������, � ���� ������ �������� ���� �����.";
			link.l1 = "������.";
			link.l1.go = "Tuttuat_74";
			pchar.questTemp.Caleuche.Mangarosa = 34;
		break;
		
		case "Tuttuat_77_5":
			dialog.text = "��������� ������ ��� ������. ��� ������� �����, ������� ������� ���� ���������, � ����� ������ ������� ������ ���� �����.";
			link.l1 = "������.";
			link.l1.go = "Tuttuat_74";
			pchar.questTemp.Caleuche.Mangarosa = 35;
		break;
		
		case "Tuttuat_78":
			dialog.text = "��� ���, ��� ���� ������� ��� ���������, ��������� ������� �����.";
			link.l1 = "�����, ������������, � ����� ���� ����� ���� ��� ��� �������? ��� ������ ���������...";
			link.l1.go = "Tuttuat_79";
		break;
		
		case "Tuttuat_79":
			dialog.text = "���� ��� ������� ���� ���� ���� ������. ��� � ������ ���� ������� �� ����, � ��� ��� ������ ������ �������� ������� ����� �������� � ����������� ������� ������ ��� �����, ������� ������� �����.";
			link.l1 = "����. �����, ������� ��� ��� �� �������� �����. �� ������������� ������� �����. � ������ ��� ���� ����. ������, ������������.";
			link.l1.go = "Tuttuat_80";
		break;
		
		case "Tuttuat_80":
			dialog.text = "������, ����� ����. ������ ���� �� ������ ������� � ���. ��� ��������� ��������� �������� ������. �� ������ ���� ���� � ���� ����!";
			link.l1 = "...";
			link.l1.go = "Tuttuat_81";
		break;
		
		case "Tuttuat_81":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			GiveItem2Character(pchar, "kaleuche_amulet3");
			ChangeItemDescribe("kaleuche_amulet3", "itmdescr_kaleuche_amulet3_potion");
			sld = ItemsFromID("kaleuche_amulet3");
			sld.name = "itmname_kaleuche_amulet3_potion";
			sld.groupID = SPECIAL_ITEM_TYPE;
			sld.picIndex = 15;
			sld.picTexture = "ITEMS_35";
			sld.price = 0;
			sld.Weight = 1.0;
			sld.reaction = sti(pchar.questTemp.Caleuche.Mangarosa);
			sld.ItemType = "SUPPORT";
			i = sti(sld.reaction);
			ChangeItemDescribe("kaleuche_amulet3", "itmdescr_kaleuche_amulet"+i+"_potion");
			AddQuestRecord("Caleuche", "42");
			pchar.questTemp.Caleuche = "end";
			CloseQuestHeader("Caleuche");
			DeleteAttribute(pchar, "questTemp.Caleuche.Mangarosa");
			DeleteAttribute(pchar, "questTemp.Caleuche.Potion");
		break;
		
		case "Tuttuat_82":
			Log_Info("�� ������ �������");
			RemoveItems(pchar, "kaleuche_amulet2", 1);
			RemoveItems(pchar, "kaleuche_amulet3", 1);
			dialog.text = "���� �������� ���, �����������. ��� �������� ����� ������ � ���� ������, ����� ���� ���� ��� ������, � �� ��������� ��� ���. ��� �������. ���� �������. ������������ ������ ������ ������� ����.";
			link.l1 = "��� �� �������� �����... ������, �����.";
			link.l1.go = "Tuttuat_83";
		break;
		
		case "Tuttuat_83":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Caleuche", "43");
			pchar.questTemp.Caleuche = "end";
			CloseQuestHeader("Caleuche");
			sld = ItemsFromID("SkullAztec");
			sld.price = 10000;
		break;

		// ������� �������
		case "CaleucheCap":
			PlaySound("Types\skel.wav");
			dialog.text = "����������, �����. �� �� ������� ���� �������. � ��� ��� �������, ������� �� �������� �� ������, ��� �� ������� ������ ������� ���� ����� � ��������� �����. ��� ������ �����, ��� ������ �������� ���.";
			link.l1 = "���� ������! ��� �� ����� ��� ��������? ��������, �����, ������ ��� ��������� ������ ����� ���� � �� ����� �������. ��� �� ����� � ����� ����� �� ��� �����?";
			link.l1.go = "CaleucheCap_1";
		break;
		
		case "CaleucheCap_1":
			PlaySound("Reef\reef_01.wav");
			dialog.text = "� - ��������� �� ������, ������� ������� '������� ������'. ������ �����, �� ������� ��� ��� ������, �������� ���� ��� ��� �������, ��������� '�������� ���������'. �� ��� �� ����� ��������... � ���� ���� ������, ������� � ������ ������. �� ����� ���! � �������� ���! ������� ������ ��������, ���� �� ����, �������-�� �� ����� ����! �������� ������ ����, ��������!";
			link.l1 = "������? ����!..";
			link.l1.go = "CaleucheCap_2";
		break;
		
		case "CaleucheCap_2":
			PlaySound("Types\skel.wav");
			DialogExit();
			npchar.MultiFighter = 4.0;
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			LAi_SetCheckMinHP(pchar, 10, true, "Caleuche_GhostshipGetOut");
		break;
		
		case "CaleucheCap_3":
			dialog.text = "� �� ���� ��������!.. ��� �� ����� � �� ��������� ���� � �� ����� ����������� �����!..";
			link.l1 = "�� ��� ��� �� ��������, ��������� �� ������. � ����� ���� �������. ���������� ����� ��������� � ���� ��������, � ��������� �� ������ �� �������� ��� ����� � ����� ��������. ������ �� �� ������� ����� �������� � �����.";
			link.l1.go = "CaleucheCap_4";
		break;
		
		case "CaleucheCap_4":
			dialog.text = "�����, �� �������� ���� �����������? ���! ��������� �� ������ ������ ������� ���� ������� ����� �����!";
			link.l1 = "��������� ����� '�������� ������' ���������� ���, � ����� ���. � �� �� ������� ������� ���� ����� � ��� ��������, ��� �������� ���� ��� �����.";
			link.l1.go = "CaleucheCap_5";
		break;
		
		case "CaleucheCap_5":
			dialog.text = "�������� ���� ��� ������... � ������ ��� ���� �����... � �� ��� ��� ����� ������ ����, ���������� ��� � ����������� ��� �������. ��� ���� ������ � ������������ ���������, ������� �������� '������� ������' � ��������� �� ������... �������� �� �����, �������! ������ � ��� ����� � ������!";
			link.l1 = "...";
			link.l1.go = "CaleucheCap_6";
		break;
		
		case "CaleucheCap_6":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Caleuche_ChangeShip");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// --> // ��� ������ �� ������
		case "on_coast":
			dialog.text = "�� �������-�� �� ��������, ���... ��� ������������?";
			link.l1 = "���� ������, ��� ���������? ����, ������ �������������...";
			link.l1.go = "on_coast_1";
		break;
		
		case "on_coast_1":
			dialog.text = "����� �� ����� � ����������� �����, �� ������ �� ���� ��� ��������. ������ ���������� ��� � �������� �� ��� �������, � �������, ������ ��� ��������, ��� �������� �� ������, ������ ����������� � ����� ������� �� �����\n��������� ���� � ��� ������ ��������! �� ������ �������� ���� � �������� �� �� �������, �� ������ ���� �� ������: ��������� ������� � ��� ���� �������� �������, � ���� ����� � ���� ��� ������������ � �����. � ����� ��� ������� ������ � � ��� �������� �� ����������\n������� ��� �������, � ���, ��� �����, ��������� ������ �� ������. �� ���������� ��� ���� �� �������� �����, ����� ���� ���-�� ��������� ������. ��, ��! �� ���������� ��� ����������� ������ �� �����. ��� ���� ����� ���� �������, ��?";
			link.l1 = "����� �����. �������, ������, ��� �� ������.";
			link.l1.go = "on_coast_2";
		break;
		
		case "on_coast_2":
			dialog.text = "�� �� ������, ��� �� �������, �� ���. ����� ��������� ��� �� ����� � �������� ��, ��� ��� �������... �� ����� �������, �� �������� � �����...";
			link.l1 = "� � ����� ����� ����. ������� � ����� ����� ��� ��������?";
			link.l1.go = "on_coast_3";
		break;
		
		case "on_coast_3":
			dialog.text = "�����. �� ������� � ���������� ���� ����, ����� � ��� ��������� � ���. �� �����������, ���.";
			link.l1 = "������, ��� �� ����. ���� �������� ���� �� �������� �������...";
			link.l1.go = "on_coast_4";
		break;
		
		case "on_coast_4":
			dialog.text = "�� ����������... ��� ��� '������� ���������', ���? ������ ��� �� ��� ������? � ������ ����� �� ������� �� ������ ��������, � ����� �������� �������� ����� ������?";
			link.l1 = "�� �������� ����� ��� ������, �� ������ �������� � ����� � �������������, ���������� ������. ������� ��� � �� �������� ��� �����. � ��� ������ ������� ������� ������ ������, ��� � ������������ � ����... ���� �����! ������� � �������� ����� ���������! �������� ����������...";
			link.l1.go = "on_coast_5";
		break;
		
		case "on_coast_5":
			dialog.text = "��� �� � ������������� � '������� ����������'. � ������ �� ������� � ����� � �������,  �������� ����� �� ������� ����� �� �������� ��������, � ���� ��������...";
			link.l1 = "�, �������, ����. �� ������ � ����� ����� � ������� �������. � ������ �� ���������� �������������. ���� ��������� ������� ����� �� ��� ��-�� �������! �������, ����������� ������ ������ ��������� ���, ����� �� ����������� ���������.";
			link.l1.go = "on_coast_6";
		break;
		
		case "on_coast_6":
			dialog.text = "������. �� �������� ���� - ���� ���� �� ��� ��� ������� ������.";
			link.l1 = "� ���� ���������. ������. � - ������� �� ��, ��� �� ������� ����!";
			link.l1.go = "on_coast_7";
		break;
		
		case "on_coast_7":
			dialog.text = "��� �� �����, ���! �� �� �� ��� � ����� � ����, � ���� ������ ��������� ������!";
			link.l1 = "...";
			link.l1.go = "on_coast_8";
		break;
		
		case "on_coast_8":
			chrDisableReloadToLocation = false;//������� �������
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			AddQuestRecord("Caleuche", "5");
		break;
		
		// ������ �����
		case "fergus":
			dialog.text = "��! � ��� �� ������ ����������� ���������� ������� ���, ����� ��������� �� ����, ��� ��� ������!";
			link.l1 = "��... �� - ������ �����?";
			link.l1.go = "fergus_1";
		break;
		
		case "fergus_1":
			dialog.text = "���, ���� ����� ������������, � � �������� ����, ���� �� ���������� �� ���������. ��� ��� ����������, � �� �� ��...";
			link.l1 = "...������� � ���, ��������� ���� �������, ���� �������� ����������� �������� � ������� ���� ����, �� ��� ����� �������?";
			link.l1.go = "fergus_2";
		break;
		
		case "fergus_2":
			sld = characterFromId(pchar.questTemp.Caleuche.Amuletmaster);
			dialog.text = "�����... ���� ���� ������, ��� �� �����? ������...";
			link.l1 = "� ��� � ����� ���� ����� ����, ������. �� ������ �������� ����������� �����. ��� ����� "+GetFullName(sld)+". �� � ������� ��� ���� ������� � �������� ���� � ����. � ������ ������� ������������� � ���� �����, ��� ��� ���� ����� �� �������. ��������, � �� ���� ���������. � ���� ������ � ���� ���� ����, � ��� �� ������� ����.";
			link.l1.go = "fergus_3";
		break;
		
		case "fergus_3":
			dialog.text = "��, ��� �� ������ ����� ���������� ��������! ��� �� ���? �� ���� �� ����� �� ����� �����? ������������, �����, ����� �� ����!";
			link.l1 = "������, ������, � ���� ������������� ���� �������. ��������, ��� ����� ��������� ������, ���� �� ���, ������� ��� �������� ������� ����� �� ������ ����� ������ � ��������������. � ������ ������� �� ����, � �� ���������� �� ������� ����.";
			link.l1.go = "fergus_4";
		break;
		
		case "fergus_4":
			dialog.text = "������ ��� - �������? � �� �������, ����� �� �������� �����-���� ����.";
			link.l1 = "�� �������, ������ ��� �� ������ �� �������� � ����. � ���� ���� ��� ����� ������ �� ��������� �������. �� ���� �������� �������-�������.";
			link.l1.go = "fergus_5";
		break;
		
		case "fergus_5":
			dialog.text = "�� ��������, ��������? ��� �� ���� ��� ���������� � �������������� ��������? ������, ���, ���� ����������� ����� ������ ���� �����...";
			link.l1 = "������ ��� �� ������, � �� �� ����� ����� � ��� �� ���� �� �������. �� � ����� ���������� �� ������, ��� �� ���. � ����� ����� ����� ������� � �������.";
			link.l1.go = "fergus_6";
		break;
		
		case "fergus_6":
			dialog.text = "�������?";
			link.l1 = "��, '������� ����������'. �������. ������ ��� ���� ������. �� ��� ����� �� �������� ������, � ����.";
			link.l1.go = "fergus_7";
		break;
		
		case "fergus_7":
			dialog.text = "������ ����� �� ����. ����������� �������� ����������. ��������, �����, � �� ������ �� ���� ��� ����������, �� ��� � ��� ����: ��� � ���� ������ ������ � ��������� ������� �� ���� ������, ���� � �������� � ��������. � ��������� ��� ������ �������, ���� ������ ������ �����. ��� ��� ����� ������ �� ����.";
			link.l1 = "��� �����?";
			link.l1.go = "fergus_8";
		break;
		
		case "fergus_8":
			dialog.text = "�� ���, �������, � �� ��� ������ ����� ���, ���� �� ����, ����� ����� ��������� ��� ������? � ������������ ������ ��������� ����� ����������� � �����, � � ��� ���� ���� ������������ � ������. �� ������ ������, ��� ������� ���������. ������, ��� ������ ��� ������� � �������� ����.";
			link.l1 = "��������� ����� � �������� � ������ �� �������������?";
			link.l1.go = "fergus_9";
		break;
		
		case "fergus_9":
			dialog.text = "������������� �� ���-��, ��� ��� - � �� ����. �� ������� ��� - ��-��, � ���� ������ ������ � ����. ������ �������� ��������, �������, � ���� � ������� � ������� ���� ���������. ���� �� ��� ����-�� ������ ��� �������, �������� �� ����� �� �����.";
			link.l1 = "����. �����, ������� � ����������. �����, ������!";
			link.l1.go = "fergus_10";
		break;
		
		case "fergus_10":
			DialogExit();
			AddQuestRecord("Caleuche", "9");
			pchar.questTemp.Caleuche.Bandos = "start"; 
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
		break;
		
		// ������ � ������
		case "Beliz_townbandos":
			dialog.text = "��! ���� ����? � ������ �� ���. �����, ����������!";
			link.l1 = "� ���� ��� ���������, ������? � ����� ��������, �� ��...";
			link.l1.go = "Beliz_townbandos_1";
		break;
		
		case "Beliz_townbandos_1":
			dialog.text = "�� ���, �� ������? ���������, ��� � ��� �������� ���� �� �����!";
			link.l1 = "���... � �����, �� � ���� ���, ��� ��� �����? �� ������ �� ����������, ��������...";
			link.l1.go = "Beliz_townbandos_2";
		break;
		
		case "Beliz_townbandos_2":
			dialog.text = "����� �����, ��? ��������� ��� �������: ��� �� ��� ���������, ��� � ������ ������ � ���� �������� ������� �������!";
			link.l1 = "������� �������? ��� ���������... � ��� ������ � ������ ��������� � ���, ��� � ����� ����, ���� �����. ������, � ��������. ����� ������� ���� ������, � ����� ������ ������� � �����������. � ��� ��� ������, ��� ��� ������ � ��������... ����-���! ����-���! ����!!";
			link.l1.go = "Beliz_townbandos_3";
		break;
		
		case "Beliz_townbandos_3":
			dialog.text = "�� ��, ������ �������, ������ � ���� �� �������� ������ ������!";
			link.l1 = "���! ��, �����, ��������!";
			link.l1.go = "Beliz_townbandos_4";
		break;
		
		case "Beliz_townbandos_4":
			DialogExit();
			DeleteAttribute(npchar, "CityType");
			DeleteAttribute(npchar, "city"); // ����� �� ���� ���
			LAi_SetImmortal(npchar, false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Caleuche_BelizTownbandosDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
			pchar.quest.Caleuche_letter.win_condition.l1 = "item";
			pchar.quest.Caleuche_letter.win_condition.l1.item = "kaleuche_letter";
			pchar.quest.Caleuche_letter.function = "Caleuche_FindLetter";
		break;
		
		// ������� ������ ��������
		case "Beliz_forestbandos":
			dialog.text = "��, ������! ��-��-��, ����� ���������� � ������ �������... ����, ������ - ����������, �� �� ��� �������� �������������. � ��, �������� ������������ �������!";
			link.l1 = "�� ��������, ��������. � � ���� ������ �� ����.";
			link.l1.go = "Beliz_forestbandos_1";
		break;
		
		case "Beliz_forestbandos_1":
			dialog.text = "�� ����? ��-��-��, ���� ���� - ������ ��� ��� ���� ��������� � ����������, ��� ���!";
			link.l1 = "������ ��� �����������. � ������ ������ �� ������, ������� �� ��������� �����. ��������� �� ������� �� �������, ��� � ������� ��� ����.";
			link.l1.go = "Beliz_forestbandos_2";
		break;
		
		case "Beliz_forestbandos_2":
			dialog.text = "� ��, ������!";
			link.l1 = "�����...";
			link.l1.go = "Beliz_forestbandos_3";
		break;
		
		case "Beliz_forestbandos_3":
			Log_Info("�� ������ �������");
			PlaySound("interface\important_item.wav");
			RemoveItems(pchar, "kaleuche_letter", 1);
			dialog.text = "(������) ��... ������� ��� ���. ����� ����� �� ��� ����� ��������?";
			link.l1 = "������ �� - ������ �������� ������, ��� � � ���������� ��� ��������� ���������. ������� �� �������, ������ - �� ������ ������, ��������, ��������, �������� �������...";
			link.l1.go = "Beliz_forestbandos_4";
		break;
		
		case "Beliz_forestbandos_4":
			dialog.text = "�������� �������? �����, ������, � �������� ����, � ��������, � ����������, � ����� �� ��������. �� � �� �������� ���, ��� �� ������ �������. �� ��� ��� �� ���� ����������\n� ����� �������� ��������� �����, ������� �� ������ � ����� ���������� � ����� ���-����� �������� ���� ������� ���������. ��� �� � ���� �������-�� � �������. ������� � ����. ��������-�� ������ � ������ ����� �������?";
			link.l1 = "� ���� � ���� ������� ��� ����������� �����?";
			link.l1.go = "Beliz_forestbandos_5";
		break;
		
		case "Beliz_forestbandos_5":
			dialog.text = "���� ���� ��������, ���� ��������� �������� � ��� ����������. �� �� �������, ��� ����� ����� - ����� �� ���� ����, � � �������. � � ���� ��� ��� ���� - ������ �� �������. ������! ������� �������! ���������!";
			link.l1 = "...";
			link.l1.go = "Beliz_forestbandos_6";
		break;
		
		case "Beliz_forestbandos_6":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			pchar.GenQuest.CannotWait = true;//������ ��������
			LocatorReloadEnterDisable(pchar.location, "reload2_back", true);
			LocatorReloadEnterDisable(pchar.location, "reload3_back", true);
			for (i=1; i<=6; i++)
			{
				sld = characterFromId("Beliz_forestbandos_"+i);	
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "TMP_FRIEND");
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "Beliz_ExitTown", "goto", "goto"+(rand(1)+1), "", 10.0);
			}
			DoQuestCheckDelay("OpenTheDoors", 12.0);
			pchar.quest.Caleuche_bandosrobb.win_condition.l1 = "location";
			pchar.quest.Caleuche_bandosrobb.win_condition.l1.location = "Beliz_ExitTown";
			pchar.quest.Caleuche_bandosrobb.function = "Caleuche_JungleBandosRobbery";
		break;
		
		case "Beliz_forestbandos_7":
			dialog.text = "� �� �� ����, ��� � ��������. �������! ���� ���� �� ������ ���������. ��� �������������: ��������, ��� �������?";
			link.l1 = "��������.";
			link.l1.go = "Beliz_forestbandos_8_1";
			link.l2 = "�������.";
			link.l2.go = "Beliz_forestbandos_8_2";
		break;
		
		case "Beliz_forestbandos_8_1":
			Log_Info("�� �������� 100 ��������");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "gold_dublon", 100);
			dialog.text = "�������! � ��� ������ ������� �� �������� ������.";
			link.l1 = "�������������! ��� ������ �� ���!";
			link.l1.go = "Beliz_forestbandos_9";
		break;
		
		case "Beliz_forestbandos_8_2":
			Log_Info("�� �������� 30 ������� ����");
			Log_Info("�� �������� 12 ������� ����");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "potionrum", 30);
			TakeNItems(pchar, "potionwine", 12);
			dialog.text = "�������! �� ������ �� ������, ��-��-��! � ��� ������ ������� �� �������� ������.";
			link.l1 = "�������������! ��� ������ �� ���!";
			link.l1.go = "Beliz_forestbandos_9";
		break;
		
		case "Beliz_forestbandos_9":
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "purse2", 1);
			dialog.text = "�� �������� ��� �������� ������. ������ ��� ����� �� ����? ��� ��� �� ��, ����� � ������� �� ��� ��������?";
			link.l1 = "�������!";
			link.l1.go = "Beliz_forestbandos_10";
		break;
		
		case "Beliz_forestbandos_10":
			dialog.text = "����� ������� � ������. ��� �� ���. ������ � ������� ����, ��� �� � ����� �����������, � ����� �� �������� ������. ���� ����� ��� ��� � ����� � ������, � �������� �� ����. ���? ������ ���� �������� - ������� � ���� �����. � ������, �� ������� ��������� � ������ - ����� �������. � ���� ���� �������.";
			link.l1 = "��� �� ���� ���������, � ��� �������, �� ���������. ���� ���, ��� ����. � ����� ��� ��� ��� ���� - � ������ ������ ������!";
			link.l1.go = "Beliz_forestbandos_11";
		break;
		
		case "Beliz_forestbandos_11":
			dialog.text = "������, ��������. � ������ ����������, ���� ������ �� �������. �� � �� ������ ������.";
			link.l1 = "�����, ��������...";
			link.l1.go = "Beliz_forestbandos_12";
		break;
		
		case "Beliz_forestbandos_12":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			LocatorReloadEnterDisable("Beliz_Jungle_01", "reload2_back", false);
			LocatorReloadEnterDisable("Beliz_Jungle_01", "reload3_back", false);
			LocatorReloadEnterDisable("Beliz_CaveEntrance_2", "reload1_back", true); // ��������� ������
			SetFunctionTimerCondition("Caleuche_CaveOpen", 0, 0, 1, false); // ������
			SetFunctionTimerCondition("Caleuche_BelizbandosClear", 0, 0, 4, false); // ������
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			for (i=1; i<=6; i++)
			{
				if (GetCharacterIndex("Beliz_forestbandos_"+i) != -1)
				{
					sld = characterFromId("Beliz_forestbandos_"+i);	
					LAi_SetActorType(sld);
					LAi_group_MoveCharacter(sld, "TMP_FRIEND");
					LAi_ActorRunToLocation(sld, "reload", "reload1_back", "", "", "", "OpenTheDoors", 20.0);
				}
			}
			AddQuestRecord("Caleuche", "13");
			// ������
			ref location = &Locations[FindLocation("Beliz_Jungle_01")];
			DeleteAttribute(location, "fire");
			sld = ItemsFromID("fire");
			sld.shown = false;
			// ������ ����� � ������
			pchar.GenQuestBox.Beliz_Cave_2 = true;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.kaleuche_amulet2 = 1;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.suit4 = 1;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.purse1 = 7; // Addon-2016 Jason
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.purse2 = 3; // Addon-2016 Jason
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.potion2 = 10;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.potionrum = 55;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.indian_3 = 1;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.obereg_4 = 1;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.berserker_potion = 1;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.jewelry2 = 15;
			pchar.GenQuestBox.Beliz_Cave_2.box1.items.jewelry3 = 33;
			// ������ ����
			pchar.questTemp.Caleuche.Bandos = "know";
			SaveCurrentQuestDateParam("questTemp.Caleuche.belizbandos");
		break;
		
		// ������� ������� � ������
		case "Beliz_cavebandos":
			dialog.text = "��, ��, �������! ����� ����� � ����� �������� ���������� � ��������� �� ����? ��� ���� ����� �� �������, ������!";
			link.l1 = "�� ���� �������� ������, �����?!";
			link.l1.go = "Beliz_cavebandos_1";
		break;
		
		case "Beliz_cavebandos_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_group_Delete("EnemyFight");
			DialogExit();
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("Beliz_cavebandos_"+i);	
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			if (MOD_SKILL_ENEMY_RATE > 4)
			{
				sld = GetCharacter(NPC_GenerateCharacter("Beliz_cavebandos_3", "citiz_23", "man", "man", 30, PIRATE, -1, false, "soldier"));
				FantomMakeCoolFighter(sld, 30, 70, 70, "blade_10", "pistol1", "bullet", 150);
				ChangeCharacterAddressGroup(sld, pchar.location, "monsters", "monster16");
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Caleuche_CaveBandosDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		// ������� ������
		case "reginald":
			dialog.text = "�����������, �������! ������ �������� � ���� �� �����?";
			link.l1 = TimeGreeting()+", ������ �������. ���, ��� �������-�� ����� ����.";
			link.l1.go = "reginald_1";
		break;
		
		case "reginald_1":
			dialog.text = "'������ �������', ��-��! ��, �, ����������, ��� ����� ��� ���� ��� �������� ����. ������� ��� ������ �� ��� ������� ��������, ���� ��� �������... �� ������ ������ �������, ����� �������, ������� ���� ����!.. �� ������ ���� ���������?";
			link.l1 = "��� ����� ��������, ���������� �����, ������� ���, ��� � ���� ���� ��������� ��������� ������. ���� �� ��������� ��� � �� ����������, � ��� ��� ����� ���� �����. � ���� ������ ��� � ����.";
			link.l1.go = "reginald_2";
		break;
		
		case "reginald_2":
			dialog.text = "�, �� ������ ���������, � ������� � ���������� � ����� ���������� �������! �� ����, ��������, �� ��� ��� � �� ����������.";
			link.l1 = "������� �� �� ���� ������?";
			link.l1.go = "reginald_3";
		break;
		
		case "reginald_3":
			dialog.text = "���������, ��� ����� ��������... ������ �������. � ���� ��� � ����� ���. ��������� � ��� � �� ����� ��� ����������, � ������� ��� � ������ �� ������ �� �������� � ����� ������� ���������.";
			link.l1 = "����� �������, ������ �� �� ��� ���... �������, �������. ����� ���������� ������ � ������ ��������, � � ����� ������. ��� ������. ��� �� � ����?";
			link.l1.go = "reginald_4";
		break;
		
		case "reginald_4":
			dialog.text = "��� ��� ��� � �� ������. ������ ��� ��������� �� ���������, � ����� �����, � ������ �� �������� �����, ����� �������� ����������, ��� �� ������, �� ���������� � ���� �����. � ����������� �� �������� � � ����� �� ���� - ������, �������, � ���� �������� � �����������, � � ������ ����������� ����� ������������ � ����-������ ������ �� �������, � �������� �� ����� �������� - ����� ���.";
			link.l1 = "� ��� �� ��� �������? ���������, ��� ������������� ����� ����� ���� ������.";
			link.l1.go = "reginald_5";
		break;
		
		case "reginald_5":
			dialog.text = "��... ��, ���� ���� �������. � ��� ���� ���� �� ����� �������, � �� ��� �������� �� ��������. �� �� ������ ������ ��������� ��� �������� ����������� �� ��� �������, ��� ��������� � ���. �� �� ������ �� ���������, �� ��� ��������� - � ���� ������� ����.";
			link.l1 = "�������?";
			link.l1.go = "reginald_6";
		break;
		
		case "reginald_6":
			dialog.text = "������� ������� �����. � ������� � �� �������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "�� �����! ��� ���� ������.";
				link.l1.go = "reginald_10";
			}
			link.l2 = "��. � ���� ������ ��� ������� ��������.";
			link.l2.go = "reginald_7";
		break;
		
		case "reginald_7":
			dialog.text = "����� �������, ����� ��������. ��� ����� ���� ���� ��� - ������, ������� � ������. � ��� ����� ���� ������ ����� ����-��������� � �������.";
			link.l1 = "������. ������������.";
			link.l1.go = "reginald_8";
		break;
		
		case "reginald_8":
			DialogExit();
			NextDiag.CurrentNode = "reginald_9";
			npchar.DeckDialogNode = "reginald_9";
		break;
		
		case "reginald_9":
			dialog.text = "����� ��, �������? ������ ������� �����?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "��. ��� ���� ������.";
				link.l1.go = "reginald_10";
			}
			link.l2 = "���� ���, �� � ������� ��� ����.";
			link.l2.go = "reginald_8";
		break;
		
		case "reginald_10":
			Log_Info("�� ������ 500 ��������");
			PlaySound("interface\important_item.wav");
			RemoveItems(pchar, "gold_dublon", 500);
			dialog.text = "��� � ������! � ��� ���� ����. � � ���� � ���� ����� �������� �������: ����� ����, ��� �������� ��, ��� � �������, ������ ���� � �����. ������� ���-�� ������ ����� ����� ��� ������� � ���� � ����.";
			link.l1 = "������.";
			link.l1.go = "reginald_11";
		break;
		
		case "reginald_11":
			dialog.text = "����� �����, �������! ����������� ����!";
			link.l1 = "� ���� ���� ��, ������ �������.";
			link.l1.go = "reginald_12";
		break;
		
		case "reginald_12":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true;
			DeleteAttribute(pchar, "questTemp.Caleuche.Garpiya");
			DeleteAttribute(pchar, "questTemp.Garpiya");
			GiveItem2Character(pchar, "kaleuche_key"); 
			AddQuestRecord("Caleuche", "20");
			// ������ �� �������
			i = Findlocation("Mayak2");
			Locations[i].models.always.locators = "lighthouse_Blocators";
			locations[i].private1.key = "kaleuche_key";
			locations[i].private1.key.delItem = true;
			locations[i].private1.items.kaleuche_amulet3 = 1;
			locations[i].private1.items.pistol9 = 1;
			locations[i].private1.items.indian_6 = 1;
			locations[i].private1.items.map_barbados = 1;
			locations[i].private1.items.map_part2 = 1;
			locations[i].private1.items.jewelry22 = 5;
			locations[i].private1.items.jewelry17 = 6;
			locations[i].private1.items.jewelry12 = 3;
			locations[i].private1.items.jewelry16 = 2;
			locations[i].private1.items.jewelry20 = 7;
			locations[i].private1.items.jewelry53 = 11;
			locations[i].private1.items.mineral25 = 1;
			locations[i].private1.items.mineral21 = 1;
			locations[i].private1.items.mineral22 = 5;
			locations[i].private1.items.mineral26 = 1;
			locations[i].private1.items.mineral10 = 1;
			locations[i].private1.items.mineral3 = 10;
			pchar.quest.caleuche_amulet3.win_condition.l1 = "item";
			pchar.quest.caleuche_amulet3.win_condition.l1.item = "kaleuche_amulet3";
			pchar.quest.caleuche_amulet3.function = "Caleuche_ThirdAmuletFind";
		break;
		
		// ����� � �����������
		case "monk_caleuche":
			dialog.text = "������������, ������� "+GetFullName(pchar)+". ��� ��� �������������� � �����������.";
			link.l1 = "������ ����, ������ ����. �� �����, ����� �� ���� � ���� �������.";
			link.l1.go = "monk_caleuche_1";
		break;
		
		case "monk_caleuche_1":
			dialog.text = "� ����� � ��� ������� � �������� ����������, ����� ��� ������� ����� �� ����. � �����, ��� ��� � ���� ������� � ������.";
			link.l1 = "����� ���������. � ������ �� ������ �?";
			link.l1.go = "monk_caleuche_2";
		break;
		
		case "monk_caleuche_2":
			if (CheckAttribute(pchar, "questTemp.Caleuche.Skul"))
			{
				dialog.text = "������ ��� �� ����� ������� ��� ���������� ���������� ���������. �� �� ������� ����� � ��������, ������ � ������������. � ��� ��������� �� ��� ��������� � ������� ����������������� �����, �� �������, ��� ����� ����������� �������, ��� ��, ������������ � �������� ������� ��������� �������.";
			}
			else
			{
				dialog.text = "������ ��� �� �� �� ������ � ������ �����������, �� ������� � �������� � �� ������ ������� ��� � �������� ����� �������. � ��������� ������ �� �� ��������� ����������� �� ����, ��� �� ���������� ����, ��������� �� ����� �������� � ��� ��������� �� ��� ��������� � ������� ����������������� �����.";
			}
			link.l1 = "������. ��� �� �������?";
			link.l1.go = "monk_caleuche_3";
		break;
		
		case "monk_caleuche_3":
			sld = characterFromId("Villemstad_Priest");
			dialog.text = "�������� ���������� ����������� ���� ���. ����������� ��� ��������� �� ��� ����� ������� ������� ����� ����� ��������������� ����, �� ��������, � �� ���������. ��� ���, ���������� ����� ������, ���� "+sld.name+", ����� ���\n��� ������ ��������, ����������, ���������� ����������� � ���������� � ������ � �������� �����. �� ������� �� ������������� ������������ � ����� �����. ������� ������ ��������� �� ����� ���������� � �������� � �������� � ����������, ���� ��������� �� ������ ����������, �� ���... ��� ��� �����. �������� - ������ ������\n��� ���. ������ ������� � �����������, �� ����� ��� �� ��������, ��� � ��������. � ������ ��������� ����� �������, ��������� ������� ���������, ��������� �������� �� ����. ������! � �� ������� �� ��� ���\n��� ���� �� ����� �� ������ ����� ���� ������ ������� ������-����� ���� � ��������� �������������� �����. ���� "+sld.name+" ��������� � ����������. ��� �������� ������� �� ������� ������, ��� �������� ��� � ������ �� ����������: �� ������� ����, �� �����������, �� ����-���� ���������������\n�� ���������� �� �����������. ������� ��� � �� ���������, � �� ����� ������� �� ������� ���� ������ ����. ����� ����, ������� ���� �����. � ������ �� ������� �� ������ - ���������, ��� ��� ����� ��� ������, ��� � ��������� ���� ������ ������������ � ���. ������ �� ����� �� �����.";
			link.l1 = "��� � �������, ���� ������� ����� ����������� � ���, ����� ����� � ���� ��� � ����������, ��� ��� ��������?";
			link.l1.go = "monk_caleuche_4";
		break;
		
		case "monk_caleuche_4":
			dialog.text = "������ ���, ����������� ��������. ��������� �� ������� ������ ������. ��������� �������, ��� �� ����� ���� - ���� ������� ������ �� ��������� � ����. ���������� �������������� ���� �� ������. ������� ��������� ��� ��� �����, ��� ��� ��� ������� ����� �����, ��� ������� ���� ��������.";
			link.l1 = "��... ���� �������� �����?";
			link.l1.go = "monk_caleuche_5";
		break;
		
		case "monk_caleuche_5":
			sld = characterFromId("Villemstad_Priest");
			dialog.text = "��, ������. ���� ��� ��� ����. ����� ��� �����. ���� "+sld.name+" ������������ � ����������� ��� �� ������. ��� ������ ��������� ����� � ���� ������� - ���������� ���, ��� �� ��� ����������. ������ ���, ���� �������� ����� ��� ����� �����.";
			link.l1 = "�����. � ������� ��� ���, ��� �� ��� �������.";
			link.l1.go = "monk_caleuche_6";
		break;
		
		case "monk_caleuche_6":
			dialog.text = "�������, �������. �������, �� �� �������� � ���� �������. ���� ����, ���� ������. ������������ ���.";
			link.l1 = "...";
			link.l1.go = "monk_caleuche_7";
		break;
		
		case "monk_caleuche_7":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload7_back", "none", "", "", "", -1);
			AddQuestRecord("Caleuche", "24");
			if (CheckAttribute(pchar, "questTemp.Caleuche.Skul")) sTemp = "�������� ��� ����� ������� �������� ������� ���������, � �������, �� ��� ������, �� ����� �������� �������� ����. ��������� ��� ��������� ����� � ������ ���������, ����� ��� ������� �� ���������� �����, ��� ���������� ���������. ���-�� ��� ������ �� ��������� ���� ����� � ��� ������ ���������.";
			else sTemp = "�������� ��� �������� ����������, � ������� ������ ������� ����� ������ ��������. ���� �� �����, ��� � ���� ��� ����� ����� ������, � ������� ������� ������������. �� ������ ������, �� ����� � ���� �������� �������� ����. ���-�� ��� ������ �� ��������� ���� ����� � ������ ��������� �������.";
			AddQuestUserData("Caleuche", "sText", sTemp);
			i = Findlocation("Villemstad_town");
			DeleteAttribute(&locations[i], "reload.l14.close_for_night");
			pchar.quest.Caleuche_villemstadhouse.win_condition.l1 = "location";
			pchar.quest.Caleuche_villemstadhouse.win_condition.l1.location = "Villemstad_houseSp1_room";
			pchar.quest.Caleuche_villemstadhouse.win_condition.l2 = "Hour";
			pchar.quest.Caleuche_villemstadhouse.win_condition.l2.start.hour = 1.00;
			pchar.quest.Caleuche_villemstadhouse.win_condition.l2.finish.hour = 3.00;
			pchar.quest.Caleuche_villemstadhouse.function = "Caleuche_CreateJoakimSkel";
		break;
		
		// ������� � ������
		case "cavehunter":
			dialog.text = "������, ��������. ����� ���� ���� �� ������, ���� ����� ������.";
			link.l1 = "� ��� ��� �����?";
			link.l1.go = "cavehunter_1";
		break;
		
		case "cavehunter_1":
			dialog.text = "������, ���� ����� �� �����. �� ���, �� ��������� - ���� ������, � � ����� ���������� �� ������, ��� ����� �� ������ �� ���������.";
			link.l1 = "�� ��� ���... �� �� ���� ���������� �������� ������. ������� �� ��������������.";
			link.l1.go = "cavehunter_2";
		break;
		
		case "cavehunter_2":
			dialog.text = "�� �� ���. ������� �� ���� ����� ��������.";
			link.l1 = "...";
			link.l1.go = "cavehunter_3";
		break;
		
		case "cavehunter_3":
			DialogExit();
			npchar.dialog.currentnode = "cavehunter_4";
		break;
		
		case "cavehunter_4":
			dialog.text = "������� �� ���� ����� ��������, ��������.";
			link.l1 = "� �����...";
			link.l1.go = "cavehunter_4_1";
		break;
		
		case "cavehunter_4_1":
			DialogExit();
			npchar.dialog.currentnode = "cavehunter_4";
		break;
		
		case "cavehunter_5":
			sld = characterFromId("Havana_Priest");
			dialog.text = "�� ������, ��� ������ ����� ����?";
			link.l1 = "���������. ���� ������� ���� "+sld.name+", ���������� ������ ������. � ������ ��������, ��� ����� ����������, � ������� ���������� ����.";
			link.l1.go = "cavehunter_6";
		break;
		
		case "cavehunter_6":
			dialog.text = "��� ����� ����������?! �����, � ���� �������� ��������, ��� ������ �� ������� ������ �������, ��� ����� ����������.";
			link.l1 = "��� �� ������� � ���, ��� � ������ �������� ������� ��������?";
			link.l1.go = "cavehunter_7";
		break;
		
		case "cavehunter_7":
			dialog.text = "��, �. � ����� ���� �������� ���� ������.";
			link.l1 = "� ����. � ����� ���������� � ����� ����� �������� � ����������� � ��������� ��. � ������ � ����� ���� � ������ ��� �������, ������� ������ � ������.";
			link.l1.go = "cavehunter_8";
		break;
		
		case "cavehunter_8":
			int icpy = GetOfficersQuantity(pchar);
			switch (icpy)
			{
				case 0:
					dialog.text = "� �� ������� ������� ��� � ��������? �� ��������, ��������. �� ���� �� �������������, ������� �� ���. ������, � � ���������� � ������� ������� ����� ���� �� ������.";
					link.l1 = "�� ����� �������� ���� ������ �������. � �� ����� ������.";
					link.l1.go = "cavehunter_exit";
				break;
				
				case 1:
					dialog.text = "� �� �������� ������� ��� ������? �����, ������ �� �� ��������. �� ���� �� �������������, ������� �� ���. ��� ������������.";
					link.l1 = "�� ��� ����� ������, �������. ������-�� � �������, � �� �������� ������ ���� �������.";
					link.l1.go = "cavehunter_exit";
				break;
				
				case 2:
					dialog.text = "� �� �������� ������� ��� ������? ��������, �� ������� �����, ��� �������� �� �����. �� �����, ��� ��� ����� �� ����������. �� ���� �� �������������, ������� �� ��� � �����.";
					link.l1 = "�� ��� ����� ������, �������. ������-�� � �������, � �� �������� ������ ���� �������.";
					link.l1.go = "cavehunter_exit";
				break;
				
				case 3:
					dialog.text = "� ��, ������, ������ �� ������. �� �� ���� �� �������������, ������� �� ���. � ���� ���� ������ ����� ���� �� �����. � ��� � ����, ���� ������, � ���� ������������ ��� �������� �� ������ �������!";
					link.l1 = "�� ������� ������, �������. � �� �������� �� ����� ������. ������!";
					link.l1.go = "cavehunter_9";
				break;
			}
		break;
		
		case "cavehunter_exit":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
		break;
		
		case "cavehunter_9":
			DialogExit();
			npchar.quest.caleuche = true;
			npchar.dialog.currentnode = "cavehunter_10";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			// ��������� �������� ������
			LocatorReloadEnterDisable("Cuba_Jungle_07", "reload1_back", true);
			LocatorReloadEnterDisable("Cuba_Jungle_07", "reload3_back", true);
		break;
		
		case "cavehunter_10":
			dialog.text = "������! ��������� ��������� �������!";
			link.l1 = "...";
			link.l1.go = "cavehunter_10_1";
		break;
		
		case "cavehunter_10_1":
			DialogExit();
			npchar.dialog.currentnode = "cavehunter_10";
		break;
		
		case "cavehunter_11":
			dialog.text = "��, ��� ��� ����� ����! ������� �� ����� ��������� ���������! ������ ����� ���� ��������... �������� ��� ����, ��� ��� ���������, ����������, ������� ���� ���� ��������. ����� �������, ��� ����� ������ ������� ���� ������� �������� ����������. � �����-������, ������� - ��� �� �� �����.";
			link.l1 = "����������� ��������. ������� �� ������, �������. �� ��������� ������. �����!";
			link.l1.go = "cavehunter_exit";
		break;
		
		// ������ � ������ ��� �������
		case "cryptguard":
			dialog.text = "����! ���� ���� ���������!";
			link.l1 = "�-�... � ��� ��� �����?";
			link.l1.go = "cryptguard_1";
		break;
		
		case "cryptguard_1":
			dialog.text = "����� ��� ��������� ������� ������. ������� � ��� ����� ����� ������ ������ ���� � �������, �������������� ��.";
			link.l1 = "����. ������� ��������?";
			link.l1.go = "cryptguard_2";
		break;
		
		case "cryptguard_2":
			dialog.text = "� �� ����������� �������� �� ����� �������, ������. ��� ����� ����.";
			link.l1 = "������, � �����. ����� �������.";
			link.l1.go = "cryptguard_3";
		break;
		
		case "cryptguard_3":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("Caleuche", "31");
			CloseQuestHeader("Caleuche");
			pchar.questTemp.Caleuche = "end";
		break;
		
		// ��������-�����
		case "Chavinavi":
			PlaySound("VOICE\Russian\TopChavinavi-01.wav");
			dialog.text = "����, �������! �� ���������� � ����� ������ �����, � �� ����� ������� ������, ����� ��������� �����.";
			link.l1 = "��� ��?!";
			link.l1.go = "Chavinavi_1";
		break;
		
		case "Chavinavi_1":
			dialog.text = "� - ����� ��������, ��������� ������ � ����� ��������� ������. �� �� ������, ��� ����� � ����, �� �� ���� ���� ���� ������� ������� � ���� ��������� �����. � ���� ������� � �������� �� ��������� � �����. ����� �� ������ ����, �����������?";
			link.l1 = "� ������ � ���� ���� ������� �������� - ���������� �����. ��������� ��� ����� �� ��� ������� �� ���������� ����� ������ � ������� ��������. � ����������� ����� ��������� � ������� ����� ������ ����.";
			link.l1.go = "Chavinavi_2";
		break;
		
		case "Chavinavi_2":
			dialog.text = "��� ������� ������� ��� ����� �� ����� ���. � �� ���� ����. ��, �����������, ������ � ����� ��������� ��� ����, ����� ���-�� �������, �� ������� - ����� ������.";
			link.l1 = "� �� ���. ������ ���������� �����, � ����� ���������, ���������� �� �������� �������-��������, ������� ������������� ��������� ����, �� � �� ������, ������ ��� �������� � �������� ������� ����� �� ���� �������.";
			link.l1.go = "Chavinavi_3";
		break;
		
		case "Chavinavi_3":
			dialog.text = "������ ���� ������, �����������, ��� ��� ��� ������ ��������� � ����������� ����? ��� ������� ���� �� ����? ����� ��� ��� ������� � �����?";
			link.l1 = "���, �� � ������ ���� �� ��������� ������ �� ����� ������������. ��� �� ���������, ����� - ���� � ������ ��������, � ���� ���� �� ������� - ������������. � ������ ���, ������ ��� �������, ��� �� ������������� ������� � ������ �������. ����� ����, ���� � �����, ����� ������-�������.";
			link.l1.go = "Chavinavi_4";
		break;
		
		case "Chavinavi_4":
			dialog.text = "���� ����� �������� ����, �����������, �� � �� ���� ������������ �������� � ��, ��� �� �� �����. ���� �� ������������� ������ � ���� ����, ����� ������� ���� ��������, �� ���� ����� ��������� ���� ������� ����������� �� ���� �����, ��� ��������, ������� � ����������\n���� ��� ���, �� ���� �� �������� ����� �������� �� ��� ��� �������. � ����� � ������� ���� �����������, � �� ������ ������� ������ ������, �� ����� - �������.";
			link.l1 = "���������!";
			link.l1.go = "question1";
		break;
		
		case "question1":
			PlaySound("VOICE\Russian\TopChavinavi-02.wav");
			dialog.text = "� - ����� ��������, ������-�������. ������ ��� ����� � ��� ���������, ������ �� ���� �������� ������ � ���� ��������� ��������. ����� ��� ���������� ����?";
			link.l1 = "��������������.";
			link.l1.go = "question1_l";
			link.l2 = "���������.";
			link.l2.go = "question1_l";
			link.l3 = "�� ������.";
			link.l3.go = "question1_r";
			link.l4 = "����.";
			link.l4.go = "question1_l";
			link.l5 = "������.";
			link.l5.go = "question1_l";
		break;
		
		case "question1_r":
			dialog.text = "�� ������� ���, �����������, ��� ��� �����, �� ������� ������ �� ������ �� ������� ������ �� ���, ������������ ���, ������ ������� ����� �����...";
			link.l1 = "";
			link.l1.go = "question2";
		break;
		
		case "question1_l":
			dialog.text = "�� ������� ���, �����������, ��� ��� �����, �� ������� ������ �� ������ �� ������� ������ �� ���, ������������ ���, ������ ������� ����� �����...";
			link.l1 = "";
			link.l1.go = "question2";
			pchar.questTemp.Caleuche.QuestionFail = "true";
		break;
		
		case "question2":
			dialog.text = "����� ����� �������� ��������� ���� ����?";
			link.l1 = "����.";
			link.l1.go = "question2_l";
			link.l2 = "�����.";
			link.l2.go = "question2_r";
			link.l3 = "����.";
			link.l3.go = "question2_l";
			link.l4 = "������.";
			link.l4.go = "question2_l";
			link.l5 = "�������.";
			link.l5.go = "question2_l";
		break;
		
		case "question2_r":
			dialog.text = "���� ������ �����������, ��������� �������� � �������� ����� ����, ������� � �������. ����, ����������� ���� ����, ������� �� ���� ����� ����� ������� ����...";
			link.l1 = "";
			link.l1.go = "question3";
		break;
		
		case "question2_l":
			dialog.text = "���� ������ �����������, ��������� �������� � �������� ����� ����, ������� � �������. ����, ����������� ���� ����, ������� �� ���� ����� ����� ������� ����...";
			link.l1 = "";
			link.l1.go = "question3";
			pchar.questTemp.Caleuche.QuestionFail = "true";
		break;
		
		case "question3":
			dialog.text = "��� ���������� ������� ����� ���� ��������������?";
			link.l1 = "��������� �����.";
			link.l1.go = "question3_l";
			link.l2 = "��������� ����.";
			link.l2.go = "question3_l";
			link.l3 = "��� ���������� �����.";
			link.l3.go = "question3_r";
			link.l4 = "��� ���������� �����.";
			link.l4.go = "question3_l";
			link.l5 = "� ������ �� ���� ���������.";
			link.l5.go = "question3_l";
		break;
		
		case "question3_r":
			dialog.text = "������� - �������� ����� � ���������������, ����������� �� ����� �����, �� ����������� ������ � �������� ���� ������. � � ���� ������� ����� � ����� ������� ��� ��������� � ��������� ����� ������ �����, ������ ������� ����. ��� �� ���� ������...";
			link.l1 = "";
			link.l1.go = "question4";
		break;
		
		case "question3_l":
			dialog.text = "������� - �������� ����� � ���������������, ����������� �� ����� �����, �� ����������� ������ � �������� ���� ������. � � ���� ������� ����� � ����� ������� ��� ��������� � ��������� ����� ������ �����, ������ ������� ����. ��� �� ���� ������...";
			link.l1 = "";
			link.l1.go = "question4";
			pchar.questTemp.Caleuche.QuestionFail = "true";
		break;
		
		case "question4":
			dialog.text = "����� �������� ����� ��� �����?";
			link.l1 = "���������.";
			link.l1.go = "question4_l";
			link.l2 = "����.";
			link.l2.go = "question4_l";
			link.l3 = "����.";
			link.l3.go = "question4_l";
			link.l4 = "����.";
			link.l4.go = "question4_l";
			link.l5 = "������.";
			link.l5.go = "question4_r";
		break;
		
		case "question4_r":
			dialog.text = "�� ���� ����������� ������, ��� ������� ����� �������, � ����� �������� ������. � ������ ���� ������� ��� ������ ����������� � ������� ������� ��������. ��������� ����� ������� �� ���������� ��������� ��������� ���, �������� ���� ������� � �������� �����������. ��� ������ ���, ��� ����� ������ ���� �� ����...";
			link.l1 = "";
			link.l1.go = "question5";
		break;
		
		case "question4_l":
			dialog.text = "�� ���� ����������� ������, ��� ������� ����� �������, � ����� �������� ������. � ������ ���� ������� ��� ������ ����������� � ������� ������� ��������. ��������� ����� ������� �� ���������� ��������� ��������� ���, �������� ���� ������� � �������� �����������. ��� ������ ���, ��� ����� ������ ���� �� ����...";
			link.l1 = "";
			link.l1.go = "question5";
			pchar.questTemp.Caleuche.QuestionFail = "true";
		break;
		
		case "question5":
			dialog.text = "��� ��������� ���� ��������� ���?";
			link.l1 = "��� ���������� ������.";
			link.l1.go = "question5_l";
			link.l2 = "��� ��������� �����.";
			link.l2.go = "question5_l";
			link.l3 = "��� ����������� ������.";
			link.l3.go = "question5_l";
			link.l4 = "��� ����������� ������.";
			link.l4.go = "question5_r";
			link.l5 = "��� ���������� ������.";
			link.l5.go = "question5_l";
		break;
		
		case "question5_r":
			if (CheckAttribute(pchar, "questTemp.Caleuche.QuestionFail"))
			{
				PlaySound("VOICE\Russian\hambit\Chavinavy.wav");
				dialog.text = "������������ ������ ��������������� � ���, ��� �� ��� ����, ����� �������, � � ���, ��� �� ������ ���� � ������� �����������. �� ����� ����������� �� ������� ��������� � ���������, ��������� ������ ��������� �����, �� ������������ ��� �� ���� ���� �� ��������! ����������� � ������, �����������!";
				link.l1 = "��, ��� �� ����������� - ���������, ����� �� ��� ������� ����...";
				link.l1.go = "chavinavi_fight";
			}
			else
			{
				dialog.text = "���� ������ � ���� ������ � ���� ����� ������� � ���� ������, �����������. ������ � ���� ����. ������ � ������� ��, ����� ���� ������. ������� ��������� �������� �� ��������� ����� ��������, ���, ��� �����-�� ���� ��� ����������� ������\n� ����� ����������� �� ���. ���� ��������� �� ������ � ���� ������������ �������� �� �������� ����������� ������ �������� ������ ���� �������� �������������.";
				link.l1 = "������� �� �������, ������� �����.";
				link.l1.go = "chavinavi_exit";
			}
		break;
		
		case "question5_l":
			PlaySound("VOICE\Russian\hambit\Chavinavy.wav");
			dialog.text = "������������ ������ ��������������� � ���, ��� �� ��� ����, ����� �������, � � ���, ��� �� ������ ���� � ������� �����������. �� ����� ����������� �� ������� ��������� � ���������, ��������� ������ ��������� �����, �� ������������ ��� �� ���� ���� �� ��������! ����������� � ������, �����������!";
			link.l1 = "��, ��� �� ����������� - ���������, ����� �� ��� ������� ����...";
			link.l1.go = "chavinavi_fight";
		break;
		
		case "chavinavi_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_group_Delete("EnemyFight");
			DialogExit();
			n = 1;
			if (MOD_SKILL_ENEMY_RATE > 2) n = 3;
			if (MOD_SKILL_ENEMY_RATE > 4) n = 5;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("TopChavinavi_"+i);	
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Caleuche_TopChavinaviDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "chavinavi_exit":
			DialogExit();
			sld = ItemsFromID("SkullAztec");
			sld.shown = "0";
			sld.useLocation = "treasure_alcove";
			sld.useLocator = "button01";
			LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
		break;
		
		case "Chavinavi_5":
			PlaySound("VOICE\Russian\Complete.wav");
			dialog.text = "�� ��������, ��� ������, �����������. � ���, ��� �� �� �������� ������, ��� ��� ���� ������. � � ���� ������ �����. ���, ������ ��� ������� - ������ ���� ������-�������. ��� �� ������ ������ � ��� ����� ������� ����� ����!";
			link.l1 = "�� ��! ����� ��������!";
			link.l1.go = "Chavinavi_6";
		break;
		
		case "Chavinavi_6":
			GiveItem2Character(pchar, "KhaelRoa_item");
			Log_Info("�� �������� ����� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� �� ������� �����. ��� ������ �� �������� �� �� ����, �� �������� ���� �����-������. ���� ������ ������, ����������� ����� � ������, ��������� �����������, � � ��� ������� �� ������� ������ ���� ����� ������� ����� ������\n�� ����, ����������� �� ������� � ��� �����, �� ������ �������� �� ���� ��������. ��� ������ �� ����������� ��, ��� ����� ������������ ���� ���� �� ��������� ��������, � ����� - ��������. ������ ��� �������, �����������, � �� �������� ��� ���� �� ��������� ������.";
			link.l1 = "�������! � ��������� �� ���� �����, ����� ������ ����� �������, ��� ������ �� ��� ������ ������.";
			link.l1.go = "Chavinavi_7";
		break;
		
		case "Chavinavi_7":
			dialog.text = "� ������ - ������. �� ������������ ����� ������� �� ������� ��������� �� ����������� ���� ��������� ��������. �����-������ �� ����� �� �������, �� ������ � �����������.";
			link.l1 = "������, �����...";
			link.l1.go = "Chavinavi_8";
		break;
		
		case "Chavinavi_8":
			DialogExit();
			LAi_SetPlayerType(pchar);
			n = 1;
			if (MOD_SKILL_ENEMY_RATE > 2) n = 3;
			if (MOD_SKILL_ENEMY_RATE > 4) n = 5;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("TopChavinavi_"+i);	
				LAi_SetWarriorType(sld);
				LAi_CharacterDisableDialog(sld);
			}
			sld = ItemsFromID("KhaelRoa_item");
			sld.groupID	= ITEM_SLOT_TYPE;
			sld.ItemType = "ARTEFACT";
			sld.Type = ITEM_AMULET;
			sld.time = 2;
			sld.price = 5000;
			sld.Weight = 10.0;
			AddQuestRecord("Caleuche", "38");
			AddCharacterExpToSkill(pchar, "Fortune", 200);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			ChangeCharacterComplexReputation(pchar, "authority", 2);
			ChangeIndianRelation(10.0);
		break;
		
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