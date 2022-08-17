// ������� ���������� �� ��������� ������� // Addon 2016-1 Jason ��������� �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp, attrL;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	attrL = Dialog.CurrentNode;
	
	if(HasSubStr(attrL, "ShipStockManBack_"))
 	{
        i = findsubstr(attrL, "_" , 0);
	 	NPChar.ShipToStoreIdx = strcut(attrL, i+1, strlen(attrL)-1); // ����� � �����
 	    Dialog.CurrentNode = "ShipStockManBack";
 	}

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
        case "First time":
			dialog.text = "��� ���� ����?";
			link.l1 = "�������, � �����...";
			link.l1.go = "exit";
		break;
		
		// ���� �������
		case "Mtr_officer":
			if (pchar.questTemp.Mtraxx != "fail" && pchar.questTemp.Mtraxx == "jewelry_5")
			{
				pchar.quest.Mtraxx_JewelryHavanaOver.over = "yes"; //����� ������
				dialog.text = "��������, ��� �� �����?!";
				link.l1 = "������������, ��� ����. �� �� �������, �� ���� �������� ���������� ������� �� ������, ���? �������� ��� ����� ����, ��� � ��������� ���� �������� ������ ��� � ����� ��������� ��������...";
				link.l1.go = "Mtr_officer_1";
			}
			else
			{
				dialog.text = "��� ���� ����?";
				link.l1 = "�������, � �����...";
				link.l1.go = "exit";
			}
		break;
		
		case "Mtr_officer_1":
            dialog.text = "������? ���? ��� �� ���� �� ������! � �� ����� ������� � ���, ������, �������� ����� ������� �������, �� ���������?";
			link.l1 = "����������. ��� ����� ����� ����� ������ ������� ��������, ������� ���������, � ��� ����� �������... � ���������� � ��� ��������� �����. ����� � �� ��������, ���� ������� �� ��� ����� �� �������� ���������...";
			link.l1.go = "Mtr_officer_2";
		break;
		
		case "Mtr_officer_2":
            dialog.text = "��-��-��! ������� �� � ����� �������, ����� �� ��������� ���� ��������� ����! ������� ������, ���� � ���?";
			link.l1 = "�� ����������� ���������, ������.";
			link.l1.go = "Mtr_officer_3";
		break;
		
		case "Mtr_officer_3":
            dialog.text = "����� �� ����� ������ �������. � � ������������� �������� ��� ��������� ���, ���� �� ������� ������ �������� ���� ������. ��� ��������, �� ��� ���� ��������� ����?";
			link.l1 = "� ����� ������ - ��.";
			link.l1.go = "Mtr_officer_4";
		break;
		
		case "Mtr_officer_4":
            dialog.text = "� ��� ���� � �������, ����� �������� ��� ���. �������� ���������, ������� ��� ����... � � ������ �� �����. ��� ����� �� ���������, ����� ������� � ����� '��������'. � ��� ����� ���� ������ ������� ������� � ���� - �������� � ��������� ���� ������ �������� � ������ �������, ��... ��������� ��� ������� ��������� ������� ���� �� �������. �� �������, �� ������ ��� ������, ��� �� ����� ����������? ��-��, �� ����  �������� ������ ��������� �� ������������� �������� �������\n��� � �����������, ��� ������ ��� ����� ������� ������, ��� ���� �� �����. ��� � �������� ������, ��� ��� ������. ��� �� ��� ���������� �������� ����, �� ��... ��, ������� �������! �������, ��������. �� ��������, �� ���������, �� ����������, ��� �� ������, �� �������� ���, ��� � ��� ��������. ���� �� ���� ����������� �� ����� ������� �� ������� �� ��� ���� �����... � �����, ����� �� ��� �� ����� ������ ��� �����������\n���������� � �����������. ������������� ���� ������, �������, ��� �� ������ ������� � ������ - � ���������. ������, ��� ���� ���?";
			link.l1 = ""+GetFullName(pchar)+".";
			link.l1.go = "Mtr_officer_5";
		break;
		
		case "Mtr_officer_5":
            dialog.text = ""+GetFullName(pchar)+", ������������. ����� � ���� ����� �� ������, �������� ������. �� �� �������. � �������, ��� � ��� � ������������ ����� ��� ���, ��� ����� ��������� � ������ �� '��������' ����� ������������. ��������, � ���� � ���� �� ������� - �� �������� ��� ����������� ���������� ��� ����, ����� ��������� ������� ���������.";
			link.l1 = "��� ��� �� ����� � �����������, ��� ����. �����, � ������� ��� ������ ��� ���������� ����� ����� ����.";
			link.l1.go = "Mtr_officer_6";
		break;
		
		case "Mtr_officer_6":
            DialogExit();
			pchar.questTemp.Mtraxx = "jewelry_6";
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("Roger_1", "8");
			SetFunctionTimerCondition("Mtraxx_TimeclearPrison", 0, 0, 4, false); // ������
		break;
		
		case "Mtr_officer_7":
			pchar.quest.Mtraxx_TimeclearPrison.over = "yes"; //����� ������
            dialog.text = "����, �������� �� ����� ������ ��������������� ������, � � �������� � ����� ����������. ���������, ������, �� ��������� ���� ����� ������, ������ ���� �� ����.";
			link.l1 = "� ���� ��������!";
			link.l1.go = "Mtr_officer_8";
		break;
		
		case "Mtr_officer_8":
            dialog.text = "����� ��������. �� ����� ������ �������� �������������� �� ����������� �� �������� ��-�� ������ � ���������� �� ���� � ��������� ������� ��������� �����, �������� �� ������ ��������, ��� ���������� ������ ����. �� ����� ��������� ����� �� � ����� ��������� ������� �������� ������. ������ � �������� ���������� ���� � ������ � ������, ��� ��� ����� ��������� ����� ���� ����� ��������. �������� ���� � ���, ��� �� �� ����� ����� �������������, � ����� ������ ��-��� ���� ���� ��� ������ ��������-����������� � ����������� �������������� � ���� ����� - ��� ������������ ������ �� ����������\n��� �� � ������ ��������� �����. � ������ ������� ����� ���� ��������, � ������� ������� ����� ������ � ��������� �������, ����� �� ����� ������� ����������� �� �����������. ������ �� ������ - �������� ��� ��������� �� ���� � ����� � ����. ����� ��� ����� � ������� � ������ ��������, � �� ������� �������: �� ���� ���������, � ��� �� ������ ������. �������, �� ��������� ������� ��������� �� ������, �������� ���� ������, � ��� ������ ��������� ����� ������. ������ ���������: ��� ������ ��� ������ ������� ��� � �������, ��� � ������� ����. ����� �����, ������.";
			link.l1 = "� ��� ���� ��, ��� ����. ��������!";
			link.l1.go = "Mtr_officer_9";
		break;
		
		case "Mtr_officer_9":
            DialogExit();
			pchar.questTemp.Mtraxx = "jewelry_10";
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Roger_1", "12");
			SetFunctionTimerCondition("Mtraxx_TimeclearGulf", 0, 0, 30, false); // ������
			pchar.quest.mtr_jewelry_gulf.win_condition.l1 = "location";
			pchar.quest.mtr_jewelry_gulf.win_condition.l1.location = "Santacatalina";
			pchar.quest.mtr_jewelry_gulf.function = "Mtraxx_JewelryGulf";
			DeleteAttribute(pchar, "GenQuest.PrisonQuestLock");
		break;
		
		// ������� ������
		case "Mtr_rosario":
            dialog.text = "��� ��� ������, ������?";
			link.l1 = "� � ��� �� ������ ���� �������. �� � ��� ������ ��������, � � ��� ������ �������, �����, � ����� ��������� ������ �������� ����... ��� ��������� ��� ����� �� ������ �������� ���� � ���, ������ ��� �� ��� �������� ������� ���-�� ��� ������������ ������ �����...";
			link.l1.go = "Mtr_rosario_1";
		break;
		
		case "Mtr_rosario_1":
            dialog.text = "��... ������, ��� ���� ��� ���������... ����������, �� � ��� ������ ����� ���� �������! � ��������� ����� ��� ��������� �� �����, � ��� ��� � ���...";
			link.l1 = "�������, ��� ��� ����� ������? ������ ������������ ������� ����� ����� �������� ��������!";
			link.l1.go = "Mtr_rosario_2";
		break;
		
		case "Mtr_rosario_2":
            dialog.text = "� ���� �������� ����! ������ ������ ����������� ���� ���������� ������, �� � �� �� ����� �... �� �����. � ���� ������ � ��������, � ������� ���� �� ���� ������ ���� ��������� ���������. � ���������� ��� �������� ���� ������ � ���������������� ������� ���������� �������, � �� ���������� ����� ��������� ��... ����� � ������� ������� ������� ��������. �� ������� �� ������ '���������' ����� ������� � ���� �����������. � ����������� ���������, ����� ������ � �� ����������. ��� ������� ����� ����� �������� - ������ ��������� ��������.";
			link.l1 = "�� ����, ���� � ����� ������ ��� ��� ������ ��������� ��������, �� ��� ���� ������ �� �������?";
			link.l1.go = "Mtr_rosario_3";
		break;
		
		case "Mtr_rosario_3":
            dialog.text = "��. ������ �������� ��������, ��� ������� ���� ����� � ���, ��� ���� ������������� ��� ��������� �����, � ��������������� ����� ������������ �� ������ ����� ������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "� ���� ���� ����������� ����� ����� ������. ���, ��������, � ����� ���� ������� ������� ���������.";
				link.l1.go = "Mtr_rosario_4";
			}
			link.l2 = "� ���������� �� ������ ��� ����� �������.";
			link.l2.go = "Mtr_rosario_5";
		break;
		
		case "Mtr_rosario_4":
			RemoveItems(pchar, "gold_dublon", 250);
			Log_Info("�� ������ 250 ��������");
			PlaySound("interface\important_item.wav");
            dialog.text = "�� ���� ����� ����! ������, ��� ������� ���� ����������!";
			link.l1 = "����� ���� ������ �� �������?";
			link.l1.go = "Mtr_rosario_8";
		break;
		
		case "Mtr_rosario_5":
            dialog.text = "����� ��� ������� ���, ������. �� ��������� ���� ���� � �������� ��������.";
			link.l1 = "�� �������!";
			link.l1.go = "Mtr_rosario_6";
		break;
		
		case "Mtr_rosario_6":
            DialogExit();
			AddQuestRecord("Roger_1", "10");
			npchar.dialog.currentnode = "Mtr_rosario_7";
		break;
		
		case "Mtr_rosario_7":
            dialog.text = "�� �������� ������ �� ���� ����?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "��, ��� ��� � ��������� ����� ��������. ����� ���� ������� ������� ���������.";
				link.l1.go = "Mtr_rosario_4";
			}
			link.l2 = "� ��� ������� ��� ����.";
			link.l2.go = "Mtr_rosario_7_1";
		break;
		
		case "Mtr_rosario_7_1":
            DialogExit();
			npchar.dialog.currentnode = "Mtr_rosario_7";
		break;
		
		case "Mtr_rosario_8":
            dialog.text = "������� ������� � ������ ������ �������-����������, � �����, ��� ������ � ������� � ������ ��� �������� ������ �� ������������ ������ �����. �������, �� ��������� ��� ������ ������ ������� ����� ������������� ���?";
			link.l1 = "�����������, ��� �������. � ������ ��� ���� ����. ��������!";
			link.l1.go = "Mtr_rosario_9";
		break;
		
		case "Mtr_rosario_9":
            DialogExit();
			AddQuestRecord("Roger_1", "11");
			npchar.lifeday = 1;
			npchar.dialog.currentnode = "Mtr_rosario_10";
			pchar.quest.mtr_prisoner.win_condition.l1 = "Timer";
			pchar.quest.mtr_prisoner.win_condition.l1.date.hour  = 12;
			pchar.quest.mtr_prisoner.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.mtr_prisoner.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.mtr_prisoner.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.mtr_prisoner.function = "Mtraxx_PrisonerFree";
		break;
		
		case "Mtr_rosario_10":
            dialog.text = "����� ��� ���� ����� ��������!";
			link.l1 = "...";
			link.l1.go = "exit";
			npchar.dialog.currentnode = "Mtr_rosario_10";
		break;
		
		// ����� �������
		case "Jeffry":
			pchar.quest.Mtraxx_SilkCPVOver.over = "yes"; //����� ����������
            dialog.text = "��, ������ ������� ���� ������������ �������� �� ������ ����� �����? � ������ �� ���� � �����!";
			link.l1 = "�� ����, �������. � �� ������� �� ������ ������������ �����.";
			link.l1.go = "Jeffry_1";
		break;
		
		case "Jeffry_1":
            dialog.text = "�-�, �� ��� ������ ����. ��� �� ��� �������? � ��� ������� � ����������������, ��� ���������� �������� ���� �� �����...";
			link.l1 = "� ������� �� ��� ����������, ������� �����������������?";
			link.l1.go = "Jeffry_2";
		break;
		
		case "Jeffry_2":
            dialog.text = "�� ������ ������ ���� �� �����. ��-�����, ������������� ����.";
			link.l1 = "������ ����� �������� �� ����� �� ������ ���� �������� �������. ��, ������ ��������. � �������� ���� �������� ����� ������ ����������.";
			link.l1.go = "Jeffry_3";
		break;
		
		case "Jeffry_3":
            dialog.text = "��-��-��, �� � ������� �� ����, ������! � ������� ���� �� ����! ��, �����, ���... � ��������, ��� ��� � ���� ������.";
			link.l1 = "���� �����, ��� ��������� ��������� �� �������? �������, � ����� ��� ���� ������? ����� �� ����� ���-������, ��������� �� ����...";
			link.l1.go = "Jeffry_4";
		break;
		
		case "Jeffry_4":
            dialog.text = "�����-�����, �� ��������, ��������... �� �� ������� � �������� �������, �� � �� �� ���� �� ��� ���������. �� ������ ��� �� � ���� ������? ����� � ������� �� �������, �� ������� �� �������� - �������� ������ ���������������. ���� � ��� ��, �? ��� �������.";
			link.l1 = "��, �� � � ����� ��������� �� ���� ������ � �����... �����. ������ ��� ��� ��� ������ �� ����� ����������� ����������. �������� ���� �� ����������� ���-�� �������. � ���� �������� ���������� � ��������� ����� �� ����� � �������� ������������ � �������� �����.";
			link.l1.go = "Jeffry_5";
		break;
		
		case "Jeffry_5":
            dialog.text = "��� ������?! ������� ���� ����! �������, ��� � ���. '�����' � ��������� ��������� � ������� �����, � �� ����� ���� ���� ������� �� ������. ��, ��, ���������, ����� �����������, ������� ������ ������� �������� � �����������! �� � ����, �������, ����� � ����� ����������� �������. ���� �� ��� �� ������� ����� ������, �������� ������� ���� ������� �� ���� ��������� ���� - �� ������, ��� ���� ������.";
			link.l1 = "������! ��� ��� ���� ����� �����. ���� �� ���������� ����� �����.";
			link.l1.go = "Jeffry_6";
		break;
		
		case "Jeffry_6":
            dialog.text = "��� �������. � ������ �� ���� �������� �������.";
			link.l1 = "������. ��� ��������!";
			link.l1.go = "Jeffry_7";
		break;
		
		case "Jeffry_7":
            DialogExit();
			AddQuestRecord("Roger_2", "3");
			npchar.DeckDialogNode = "Jeffry_8";
			npchar.dialog.currentnode = "Jeffry_8";
			pchar.questTemp.Mtraxx = "silk_2";
			AddCharacterGoods(pchar, GOOD_SHIPSILK, 1);
			SetFunctionTimerCondition("Mtraxx_SilkTimeOver", 0, 0, 121, false); // ������
		break;
		
		case "Jeffry_8":
            dialog.text = "���� ���-�� ��� �� ���� �����, ������?";
			link.l1 = "���� ������, ��������...";
			link.l1.go = "Jeffry_8_1";
		break;
		
		case "Jeffry_8_1":
            DialogExit();
			npchar.DeckDialogNode = "Jeffry_8";
			npchar.dialog.currentnode = "Jeffry_8";
		break;
		
		case "Jeffry_9":
			pchar.quest.Mtraxx_SilkTimeOver.over = "yes";
            dialog.text = "��, ��� ������, ��������?";
			link.l1 = "�������, �������. � ����� ���������� �� ����. ���� - 25 �������� �� �����. ��� ��� ������ ����� �������.";
			link.l1.go = "Jeffry_10";
		break;
		
		case "Jeffry_10":
            dialog.text = "������� ���� ����! �� �� � ������ �����! � ��� ���� ��� �������, �?";
			link.l1 = "������ �������, �������. ������ ������ � ���������: ���� ���� ������� ����� ��������� 10 � 15 ������ � ������, �� ��� ������. �� ����� ���� ����� ����� �� ������ ���� ����������. ������ - '�������� �����'. ��� ��������? �������.";
			link.l1.go = "Jeffry_11";
		break;
		
		case "Jeffry_11":
            dialog.text = "����� 10 � 15 �������, �����, ������, ��� ������, ������ - '�������� �����'... ���� ������� ��������, ����� �������, �� � ��� �� ����� ���� ��������, ��-��!";
			link.l1 = "��� ������� � ����� � ���� ����?";
			link.l1.go = "Jeffry_12";
		break;
		
		case "Jeffry_12":
            dialog.text = "���� � ������.";
			link.l1 = "�������. ������ � ����. �� ������� ����!";
			link.l1.go = "Jeffry_13";
		break;
		
		case "Jeffry_13":
            dialog.text = "�� ������, ��������, ��� ����� �������, ��� ����.";
			link.l1 = "�����, �������. �����, ��� ��������.";
			link.l1.go = "Jeffry_14";
		break;
		
		case "Jeffry_14":
            DialogExit();
            AddQuestRecord("Roger_2", "22");
			pchar.questTemp.Mtraxx = "silk_14"; // � �������
			sld = characterFromId("Terrax");
			sld.dialog.currentnode = "mtraxx_12";
			pchar.quest.mtraxx_hide_jeffry.win_condition.l1 = "MapEnter";
			pchar.quest.mtraxx_hide_jeffry.function = "Mtraxx_SilkHideJeffry";
		break;
		
		case "Jeffry_15":
            dialog.text = "��, ���� � ����! �� ��� �� ������� "+pchar.name+" ����� ����������� ��������! �������-�������!";
			link.l1 = "��, ����� �������! ������, ��������. "+pchar.name+" �����? ���!..";
			link.l1.go = "Jeffry_15x";
		break;
		
		case "Jeffry_15x":
            dialog.text = "���, ������� ������� ���� ������ ���? ��� ���� ������ ������ � �� ����.";
			link.l1 = "��, "+pchar.name+" - �������, � ������ '�����'?";
			link.l1.go = "Jeffry_15y";
		break;
		
		case "Jeffry_15y":
            dialog.text = "�� ������� ������������ � ����, ��� ����. �������������� ���� ��� ������, ��� �����, ��-��-��!.. ��� ���������? � �������� �������? ��������� � ���� � ����� �������������� ��������?";
			link.l1 = "�� ���� � ���� ��� ��� ���-������ ����� � ���� ��������!..";
			link.l1.go = "Jeffry_16";
		break;
		
		case "Jeffry_16":
            dialog.text = "���! � ��� ���� ������� ������ �� ������? ������ �������� �� ���� ����? ��� ��� �� �����, ��-��-��!";
			link.l1 = "����! � �� ��� ������� ������� ��� ����� ����������� ������� � ������ �������, ����� � ������ ���� ��������, ����� ��� ������� ���� � ����� ���������, ����� �� �������� �����, � ���� ����� �������� �������� ��� �� ��� ��������� ���� ���� �� ������� ������. ��� ��������� ���� �� ����� ������� ������, �������!";
			link.l1.go = "Jeffry_17";
		break;
		
		case "Jeffry_17":
            dialog.text = "������, � ����� ����, ��������? �� �� ���� �����. ������ � ������� ����� �������. ���� �� ��� ������ ��������, ������ � ������ �� �����������. � �� ��� '������' �� ������, ���� ���� ����� ������. �� � ������ ����� ����. ��� �� � ��������� ���, ��� �� ����� ������������ ��� '��������'.";
			link.l1 = "�������, ����, ��� ����� ������� ����� �� ������ ����, ��� � �� ���� ����� ��������!.. ������, �� ���� ��� ������ ���������� ������ ����. � ��� ����� ��� �� ������� - �� �������� ������� ������.";
			link.l1.go = "Jeffry_18";
		break;
		
		case "Jeffry_18":
            dialog.text = "��-��-��! �����, �� ���... �� ��������. ������������� - ���� �������, � ���� �� ��������� ��� ��������� - �������� �� ������� ���� ����������. �����, ��� ���� ������ �������� ���� � ������, ���?";
			link.l1 = "��. �� ��...";
			link.l1.go = "Jeffry_19";
		break;
		
		case "Jeffry_19":
            dialog.text = "��� ���... (������� �����) ������������, ��� ������� ������� � ��������. ������? ������ ������ ������ ��� ��� ������ ����� �� ������� �� ������� ���� ������� �������. �� � ���� ����� �� �������.";
			link.l1 = "� ���� ���. �������, ��� �����������, �������. ���� � �����!";
			link.l1.go = "Jeffry_20";
		break;
		
		case "Jeffry_20":
            dialog.text = "� ���� ��������� �����, ��������.";
			link.l1 = "...";
			link.l1.go = "Jeffry_21";
		break;
		
		case "Jeffry_21":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 15.0);
			AddQuestRecord("Roger_4", "10");
			CloseQuestHeader("Roger_4");
			QuestSetCurrentNode("Terrax", "mtraxx_34"); // �����-������
			bDisableFastReload = false;
			pchar.questTemp.Mtraxx.CharleePrince = "true"; // ������� - �� ��������� �����
		break;
		
		case "Jeffry_22":
            dialog.text = "��, �����! � �-�� ����������: ��� ��� � �������� ��������� �������! ������� ����� ������� �� �������� - ����� ����� ���������� � ����� ����.";
			link.l1 = "�������?! � �� ���? �� ���? ���� ����� ����� ��������?";
			link.l1.go = "Jeffry_23";
		break;
		
		case "Jeffry_23":
            dialog.text = "��������, � �� ����� ������, ��� ����� ��������, ������ �� �����. ��� �������� ������� ������ ���������������, ��� �������� ����������� ������ � ���� ����������. ���, � ����������, ������ ���� ������, ��� �� ������ ������.";
			link.l1 = "��� ������ �������?";
			link.l1.go = "Jeffry_24";
		break;
		
		case "Jeffry_24":
            dialog.text = "�� �������� �����-��. �� ������� ��� �� ������� ����� ����. ��� �������� ������ ���������� ��������, ���������� - �� � � ����� ���������.";
			link.l1 = "����� ���� �� ������� ���������?";
			link.l1.go = "Jeffry_25";
		break;
		
		case "Jeffry_25":
            dialog.text = "���. �� ���������. �����, �� ��� ��� ������������?";
			link.l1 = "�� �������� ��� ��� ���. �� ���� � � �������� ����������. ������� ���� ������� ��� �������? �� ����...";
			link.l1.go = "Jeffry_26";
		break;
		
		case "Jeffry_26":
            dialog.text = "��� ����� �������?";
			link.l1 = "�����, ��������� ��� �� ������ �������� �����, ������� ����! �� �������!";
			link.l1.go = "Jeffry_27";
		break;
		
		case "Jeffry_27":
            dialog.text = "���... �����, �� �� ����� �� ������. ����� ��������� ������.";
			link.l1 = "� ��� �� ������? ����� ���... ��� ������, ������ ����, � ����������, � ������� �� �������� ��������. ���������� ��������. �� ��� �� ���, �����! ����� ����� ���� ��� ���!";
			link.l1.go = "Jeffry_28";
		break;
		
		case "Jeffry_28":
            dialog.text = "�����? ��� ��� ��! � ��� ��?";
			link.l1 = "�����... �����. � �������� ��� � ��������. �� ������ ��������: ����� ������� - '��� ���, ��� ���, ������ �� ���', � ����� ��������� �� ����� � ����� �� ���� �� ������ ����������. �������� ����������...";
			link.l1.go = "Jeffry_29";
		break;
		
		case "Jeffry_29":
            dialog.text = "��... ����� ����� �� ����� � ��������, � ���, ������, ������ ���� ������ � ����� �������...";
			link.l1 = "������... �������, �� ��� �� ����� �������, ��� �� �� ���������! �� ��� ���� ������ � ��� ����������! ��� ���� �������� �������! �� ��������, ��� ������ ���? ����������?";
			link.l1.go = "Jeffry_30";
		break;
		
		case "Jeffry_30":
            dialog.text = "�� ��������� �����?";
			link.l1 = "��. ������������ �������. ��������� �������� �������� � �������� �������� � ��������.";
			link.l1.go = "Jeffry_31";
		break;
		
		case "Jeffry_31":
            dialog.text = "�� ��� � ��� �� ��������, �����? ��� ���� �� �� �� ���� - ��� �� ������ ��������. �����, ���������, ��� ������. ���������, ��� ��� �� �������.";
			link.l1 = "�����... ����.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionWithJeffry");
		break;
		
		case "Jeffry_32":
            dialog.text = "��, ���� �� ��� ����������! ����� ���� ������! ���� �� ���� ������ ������ ��������... ��� ������� �������, �����! ��� ������� - ������� �����?";
			link.l1 = "�����. ������ �� ������, ����� ������� �������. �� ��� ����� ����� ����������� � ��������������, � ����� �� ����� ������ �� �������. ����� ������������.";
			link.l1.go = "Jeffry_33";
		break;
		
		case "Jeffry_33":
            dialog.text = "��, ������� �������, ������ ������ �� �� ��������. �� ����, ��������: ����� ���� �� �������������. ���! ������������!";
			link.l1 = "...";
			link.l1.go = "Jeffry_34";
		break;
		
		case "Jeffry_34":
            DialogExit();
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Mtraxx_RetributionJeffryMushketer", 0.1);
		break;
		
		case "Jeffry_35":
            dialog.text = RandSwear()+"��� ���� ��� ���������� ������!..";
			link.l1 = "�� ��, ���!..";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionJeffryFight");
		break;
		
		// ����� �������
		case "Billy":
			pchar.quest.Mtraxx_BillySeaTimeOver.over = "yes"; //����� ������
			PlaySound("VOICE\Russian\citizen\Moryaki v Gorode-10.wav");
            dialog.text = "������� ���� �����, ���� �� '������� ����' ����� ��������� �� ��������� ���... � ���� �� ������ - �����! ����� ����� ������� ����, ��������, �� ��� ����������� ������� �������?";
			link.l1 = "�����������! ��� ���� ������ ������� �����?";
			link.l1.go = "Billy_1";
		break;
		
		case "Billy_1":
            dialog.text = "� ���, �� ������ ������ ���� ����������, ���? ��, � � ���� ����� �������, � �����-�� ��� ����� ����� ������ ���������� � ��������� �������� ����� ���� � �����. ��, ��� ���� �������!.. � ������ ������ ����� �������� ���� ��� � ������� ������ �������� ������� �� ����� ����������� �������...";
			link.l1 = "� � ���� �� ����, �����. ��� �������, ��� �� ������ ���, ��� �������� � ��������� ������. ��� ���?";
			link.l1.go = "Billy_2";
		break;
		
		case "Billy_2":
            dialog.text = "��, ��� ������� - ������, ��� ��� � ����... �� �� �� ���� ����� �� ������ - ����������, ����� ������?";
			link.l1 = "������. � ����-������ ���� ����������� ��� ������. �� ���������� ���������� ����� �� �������� � ��� � ���������, ��� ���� �������� ������ ����� - ����������� ����. ��� ��� ��������� �������� ���� ���������� � ����-������ ����������, �� ����� ���� ������������ ����������. ��� � � ���� ��������� - ��� � ��� ��� �������� ����?";
			link.l1.go = "Billy_3";
		break;
		
		case "Billy_3":
            dialog.text = "��-��, ��� ��� ��� ���! ��������� �� ���������� �����, �����?";
			link.l1 = "����������! ���, � ������� � �������� ��������. � ���� ��� ��� ��� ������, ��� ������ ������ �������������� � ����� �����-������� �����, � ������ ������� ������ ����� ���� � ����������� ������...";
			link.l1.go = "Billy_4";
		break;
		
		case "Billy_4":
            dialog.text = "�, ��� �� ��������� �� ��������� �������! ��� ������ ����... ���� �� �� �����, �������. �������, ������ ������ �� ������� ��� ����������� ��� ���: ������� ������ - ������ ������. ���� ������ ������� ��, ��� ��� �������� '������� ����' ������ �����������... ������ ����� ����� ������ ������� � �� ������ � ����������� ���� ��� ������ �����\n������� ���, �����, �� ����-������ ����� ������. � ��� � ���� �������� ����� ���� ������ ������������ ����� - ����� ������� �� ���� �������� ����� � ������ ��������� � ����� ���������� ��������, ��-��. � ������ � ������� ���� ��� ����������� ����, ��� ������� �������� ����. ����� �����!";
			link.l1 = "���� ����� ����� ������? ����� � ��� ���� ������ ����� �������� � ��� ��� ������. ��� � ������...";
			link.l1.go = "Billy_5";
		break;
		
		case "Billy_5":
            dialog.text = "�-�, ���, ������� ����� ���� � ����-������ �������. ���� ������� ������ ��� ������, � ��� ������ �� ������� �������� �� �������� �� ����� ��� �� �������� ���� ����� �����. ��� ���, �����, ��� �� ���� ��������� ������ � ����� ����-������. � ���� �� ������! ����� ���� � ���� ��� ���, ������ �����������. ���� �� ������� ����������� �� �������� - � ���������.";
			link.l1 = "������, �����. ����� ���� � ����� ������, � ���� �� �����. � ����� �������.";
			link.l1.go = "Billy_6";
		break;
		
		case "Billy_6":
            dialog.text = "����� ����� ����� ���� �� �������, ���. �� ������� ��������!";
			link.l1 = "...";
			link.l1.go = "Billy_7";
		break;
		
		case "Billy_7":
            DialogExit();
			AddQuestRecord("Roger_2", "8");
			npchar.dialog.currentnode = "Billy_8";
			pchar.questTemp.Mtraxx = "silk_7";
			SetFunctionTimerCondition("Mtraxx_BillyTimeOver", 0, 0, 3, false); // ������
			pchar.quest.mtr_billy_coast.win_condition.l1 = "ExitFromLocation";
			pchar.quest.mtr_billy_coast.win_condition.l1.location = pchar.location;
			pchar.quest.mtr_billy_coast.function = "Mtraxx_BillyOnCoast";
			locations[FindLocation("shore35")].DisableEncounters = true; //��������� �������
			npchar.DontDeskTalk = true;
		break;
		
		case "Billy_8":
            dialog.text = "���? �� ��� ������� ��� ������?";
			link.l1 = "������ ��, �����...";
			link.l1.go = "exit";
		break;
		
		case "Billy_9":
			PlaySound("VOICE\Russian\citizen\Moryaki v Gorode-07.wav");
            dialog.text = "�� ���, ���, ��� ��� ��� ����� ������ � �������� �������?";
			if(Companion_CheckShipType(SHIP_TARTANE) && GetSquadronGoods(pchar, GOOD_SHIPSILK) > 0)
			{
				link.l1 = "���� ����� ��������, �������. ������ � �����, ����� ����� � ��� �����. ������ ������ ���� ������ ��������.";
				link.l1.go = "Billy_11";
			}
			else
			{
				link.l1 = "� ��� ������� ��� ����. ���.";
				link.l1.go = "Billy_10";
			}
		break;
		
		case "Billy_10":
			DialogExit();
			npchar.dialog.currentnode = "Billy_9";
		break;
		
		case "Billy_11":
			pchar.quest.Mtraxx_BillyTimeOver.over = "yes"; //����� ����������
            dialog.text = "������� ������, ��� ������ ������� �� ��������� ��� ���� � ����� ������� �����! ���, �� ������ ������ �� ���� � � ��������� �����������...";
			link.l1 = "��� ��� ����. ��� ��� ��� �� ������ ����������� �����?";
			link.l1.go = "Billy_12";
		break;
		
		case "Billy_12":
            dialog.text = "����, � ��� �� ��������� ����� �� ��� ����� '������� ����'! �� �� �����... ������ �����������, �����\n� �������� ������� ������, ����� ��� ��������-������������, �����, � ����� �������� ��������� ���� � �� �� ���������� ��� ���������� ������. �� �� ���� ��� ���� �� ����� ����, ���� ��� ���������� �����! ��� ����� ��� '������', � ��������� � ���-�������, ��� ��������� ����������� ������ �������. ��� �� ��� ���������, ���, ��� ���������\n�� ������ �� ��������� ���� � �� �� ������ ����� �� ����� �� ������� �������� �������� �������� �� ����-������. ��� ��-�� ������� � ���������� � �������� ����. ��� ����� ���� - ������� ������ ������� ��������� �� ���������� �� ������� �� ������.";
			link.l1 = "� ��� - ��� ������ ����� � ����������?";
			link.l1.go = "Billy_13";
		break;
		
		case "Billy_13":
            dialog.text = "��, �����, �� �������� ��� �� ���� �� ����, ����� ���������� �� ������ �� ��� �������. ��� ��� ���� �� ������ ������������ � �������� ���������� � '�������', ��� � ���������� �� ������ - ������� �� � ����� �������� � �������� �� ����������� ������� ������ �� ����� - �� ����������, ������� �������� ������� ����� ������ �������.";
			link.l1 = "���! ������, ��� ������ ���� ��������� �� ���. �����, �����, �� ������, �� �������� ������� �� ����� ����� �����, ����� �������� ����������� - � ����� ����������.";
			link.l1.go = "Billy_14";
		break;
		
		case "Billy_14":
            dialog.text = "��, ������ ����� ��� �� ����� � �����, ������ ��� ���� � �������! � ������ �����, ���. ������ ������!";
			link.l1 = "���� ���� ��, �����!";
			link.l1.go = "Billy_15";
		break;
		
		case "Billy_15":
            DialogExit();
			npchar.lifeday = 0;
			pchar.questTemp.Mtraxx = "silk_8";
			chrDisableReloadToLocation = true;//������� �������
			locations[FindLocation("shore35")].DisableEncounters = false; //��������� �������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "sea", "none", "", "", "OpenTheDoors", 20.0);
			AddDialogExitQuestFunction("Mtraxx_BillyTakeShip");
			AddQuestRecord("Roger_2", "9");
			// ������ ���������� �� 10-15 �����
			int month = 0;
			pchar.questTemp.Mtraxx.month = 0;
			if (GetDataDay() > 12)
			{
				month = 1;
				pchar.questTemp.Mtraxx.month = 1;
			}
			int hour = 1+rand(2);
			int day = 13+rand(2);
			pchar.quest.mtr_silk_smuggler.win_condition.l1 = "Timer";
			pchar.quest.mtr_silk_smuggler.win_condition.l1.date.hour  = hour;
			pchar.quest.mtr_silk_smuggler.win_condition.l1.date.day   = day;
			pchar.quest.mtr_silk_smuggler.win_condition.l1.date.month = GetAddingDataMonth(0, month, 0);
			pchar.quest.mtr_silk_smuggler.win_condition.l1.date.year  = GetAddingDataYear(0, month, 0);
			pchar.quest.mtr_silk_smuggler.win_condition.l2 = "location";
			pchar.quest.mtr_silk_smuggler.win_condition.l2.location = "Jamaica";
			pchar.quest.mtr_silk_smuggler.function = "Mtraxx_SilkCreateSmuggler";
			// ������
			pchar.quest.mtr_silk_smuggler_over.win_condition.l1 = "Timer";
			pchar.quest.mtr_silk_smuggler_over.win_condition.l1.date.hour  = hour+2;
			pchar.quest.mtr_silk_smuggler_over.win_condition.l1.date.day   = day;
			pchar.quest.mtr_silk_smuggler_over.win_condition.l1.date.month = GetAddingDataMonth(0, month, 0);
			pchar.quest.mtr_silk_smuggler_over.win_condition.l1.date.year  = GetAddingDataYear(0, month, 0);
			pchar.quest.mtr_silk_smuggler_over.function = "Mtraxx_SilkSmugglerOver";
		break;
		
		// ���������� � ����� ����-�����
		case "Mtr_acceptor_fight":
            LAi_group_Delete("EnemyFight");
			DialogExit();
			chrDisableReloadToLocation = true;
			LAi_LocationFightDisable(&Locations[FindLocation("shore36")], false);
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("Mtr_acceptor_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Mtraxx_SilkWrongTalk");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Mtr_acceptor":
            dialog.text = "��, �����, �� ���� ������ ��� ������ �� ������, ���?";
			link.l1 = "��. �� ��. � � ��� ���������� ����?";
			link.l1.go = "Mtr_acceptor_1";
		break;
		
		case "Mtr_acceptor_1":
            dialog.text = "� ���� ������ ����� ��������, �� � ���� ��������� ���� ������ �� ����������, ���� � ��������� �����. ��� ��� �����������, �� �����?";
			link.l1 = "� ��� ��, �����. �����-�� ���������� ��������� � ���������� ���������� ��������. �� ��� �� ����������, ��� ��������� ���������� �� ��� �������, ���������� �� ������ ����.";
			link.l1.go = "Mtr_acceptor_2";
		break;
		
		case "Mtr_acceptor_2":
            dialog.text = "� � ���� �� �����, ��� ��� ���������? �� ���� �� ���, ���� �� � ������� ���, �������, �� ������ ������������ � ����-������ �� ����� ����������...";
			link.l1 = "�� ����-�� ��� ����������, �� ��� �� ����� ���������� ����� � ��������� '������'? ��������� ��� ����, ��������, � ������ ����� ��������������. ������, ������� �� ��� ��������, ������ ����� � ����� �� ��� �����, ��� ����������.";
			link.l1.go = "Mtr_acceptor_3";
		break;
		
		case "Mtr_acceptor_3":
            dialog.text = "��� ���������!.. ���...";
			link.l1 = "������, ��� ������� ���� ������ ����������...";
			link.l1.go = "Mtr_acceptor_4_1";
			link.l2 = "�� ���� ��� ���������� �����?";
			link.l2.go = "Mtr_acceptor_7";
		break;
		
		case "Mtr_acceptor_4_1":
            dialog.text = "� ���� ��� �� ����, ��������?";
			link.l1 = "����� ����. � ���� ����. �� ���������� � ����� ����-������, � ����� ����� � ���� ����������.";
			link.l1.go = "Mtr_acceptor_wrong";
			link.l2 = "� ���� �� ���������� ��� ��������.";
			link.l2.go = "Mtr_acceptor_4_2";
		break;
		
		case "Mtr_acceptor_wrong":
            dialog.text = "����! ������, ��� ���������� �������! ����� ��� � �����!";
			link.l1 = "�������!! �� �� ���...";
			link.l1.go = "Mtr_acceptor_fight";
		break;
		
		case "Mtr_acceptor_4_2":
            dialog.text = "�������, '������� ����'? �� ��� ������������ � ����������, � �� ��...";
			link.l1 = "�� ������ ���� ���. �� ���� � � ����� ���� �����, ��� �� �������. �� ���� ����� ���������, ��� ��?";
			link.l1.go = "Mtr_acceptor_4_3";
			link.l2 = "� �� �� ���? �� ���� ����� �������?";
			link.l2.go = "Mtr_acceptor_6";
		break;
		
		case "Mtr_acceptor_4_3":
            dialog.text = "� ���� ���� � ���, �� ���� ����� ����?";
			if (GetSquadronGoods(pchar, GOOD_SHIPSILK) >= 20)
			{
				link.l1 = "�� ���-�� ������� ���� ���. ���� ��� ����� ����� ����� ��������, � �� ���.";
				link.l1.go = "Mtr_acceptor_4_4";
			}
			link.l2 = "����� ������. � ����, ��� ���� � ����� ����������. ����������� ����. �� ���� �� ������ ���� ������, � ������?";
			link.l2.go = "Mtr_acceptor_wrong";
		break;
		
		case "Mtr_acceptor_4_4":
            dialog.text = "���... ������ ��� - ����� ��������?";
			link.l1 = "�� ������ ��� ������ ����� ����� � ��� �������� �� ���������. ������� ���� ���������� ������ ����������, ��������. ��� ���-��. �� ���� �����, � ���� � ���� ����� - ��� ��� ������� �������. � ������� ��������� �� ���� ��������� ���������.";
			link.l1.go = "Mtr_acceptor_4_5";
		break;
		
		case "Mtr_acceptor_4_5":
            dialog.text = "����� ���������, � ����� �������?";
			link.l1 = "�� ������ ��, ��� �� �������� �� ����� ������, ����� ������� ����. ���-�� �������, � ��� ��������� ���� ����������� ������, ��� �... ���, ������. � ��� ������, � ������ ����� � ����� � ���������� � �������. ��� �� ������� �� ������, ��� �������, ��� ���������, ��-��-��! �����, ��������, �����, ���� � ����.";
			link.l1.go = "Mtr_acceptor_4_6";
		break;
		
		case "Mtr_acceptor_4_6":
            dialog.text = "����!";
			link.l1 = "�������! ���� ���� ���?";
			link.l1.go = "Mtr_acceptor_4_7";
		break;
		
		case "Mtr_acceptor_4_7":
            dialog.text = "������� �� ������ ����� � ����?";
			link.l1 = "� ���� ����� ����? ��� ��� ����! ��� �� ������ ��������������, �? ����� � ����...";
			link.l1.go = "Mtr_acceptor_4_8";
		break;
		
		case "Mtr_acceptor_4_8":
            dialog.text = "�� �� �������� �� �� �����, �������. �� ������ �, � ����� ��... ���� ���� ��� �����, ��, ��� ����, �� �������. � ����� ��� � ����, �� ��� ������� �����.";
			link.l1 = "��� ���? �������... � ����� ������?";
			link.l1.go = "Mtr_acceptor_4_9";
		break;
		
		case "Mtr_acceptor_4_9":
			i = GetSquadronGoods(pchar, GOOD_SHIPSILK);
            dialog.text = "�� ��� � ��������� ������ �� �����. ��� ����� ������� ����, ����� ���� ������ �� ����.";
			link.l1 = "������, �����-����� ����������� �� ��� ������! � ������ "+FindRussianQtyString(i)+". ������ �� �����, � � ����� ������ ������ ��� �� �����.";
			if (i > 80) link.l1.go = "Mtr_acceptor_4_11";
			else link.l1.go = "Mtr_acceptor_4_10";
		break;
		
		case "Mtr_acceptor_4_10":
            dialog.text = "�� �����!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_CargoSilk");
			AddCharacterExpToSkill(pchar, "Fortune", 300);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
		break;
		
		case "Mtr_acceptor_4_11":
            dialog.text = "��... ������ ������ ��� �������� ����������� ������� - �� ����� �� ��� ��������� � ���� ������� �����... ������, �� ��� ��������� ������ ����, ���... �� ��� ����! ������, ����� ��� � �����!";
			link.l1 = "�������!";
			link.l1.go = "Mtr_acceptor_fight";
		break;
		
		case "Mtr_acceptor_5":
            dialog.text = "";
			link.l1 = "������� ������, �������! �� ��� �� ����� ������? ��������� ��������? �� � ��� � ���!";
			link.l1.go = "Mtr_acceptor_5_1";
		break;
		
		case "Mtr_acceptor_5_1":
            dialog.text = "���, ��� ��... ��� ��� ��� ���������� ���������. ��� �� ������ ���� ����� �����? ��� ����� ��� �� �������, � ��� �������� �� ��������� ����� ������ ��� ���������. ��...";
			link.l1 = "��... ��������, � ���� � ���� ������ ����.";
			link.l1.go = "Mtr_acceptor_5_2";
		break;
		
		case "Mtr_acceptor_5_2":
            dialog.text = "�� ��?! � ��� ��? ������ ������ ��� ������ ����� �� ����� ������� �����?";
			link.l1 = "�, ��������, ���, � ��� ������ ������ - ��. ������ ��� ������?";
			link.l1.go = "Mtr_acceptor_5_3";
		break;
		
		case "Mtr_acceptor_5_3":
            dialog.text = "���! �� ��� - �����?";
			link.l1 = "���, � ������ ���� � ��� ���-����� �������. � ����� ����, ��� ������ ��������� '��������' ������ ������������ ����� � ������� ��, �� ����� �� �� 2500 ����. � ���� �� ��� ������ ������� ��� �� ����, � ���������, �� 25 ������� �� ����� - �� ���� ������� ������, �� ����������.";
			link.l1.go = "Mtr_acceptor_5_4";
		break;
		
		case "Mtr_acceptor_5_4":
            dialog.text = "����� ���������... ������ ������, ��������?.. ���������?..";
			link.l1 = "�� �� ����� ��, ��������, ����� ���� �������, � ���� ����� ��������? ������ �� ������. � ���� �� ������� ��������� � ����������. �� ��� ���, ��������� �� ���� �������� ����� ��������? � ��� ����� ���� �������� � �� ����.";
			link.l1.go = "Mtr_acceptor_5_5";
		break;
		
		case "Mtr_acceptor_5_5":
            dialog.text = "������. ����� ��������� � ��� ������������. ������� �����: ������ ����� � ��� �������, ��������� ����... ���, ����� � ����� ����-�����, ��� ����������, ������ ����� ����� 10 � 15 ������, �����. ������ - '�������� �����'.";
			link.l1 = "��������, ��������. �� � ������� �� ���� �������! ������ ��� �� ������ ���������� ����������� �������, � �� ���� ���������! ��-��-��! �����, ��� ����. ��� � ��������� ������ �������� �� �������. ������ �����!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_CargoSilkWin");
		break;
		
		case "Mtr_acceptor_6":
            dialog.text = "����� ����, ��� �� ���� ������ ����������, ����� ����� ��� �� �����������.";
			link.l1 = "������� �� ���� �������, �������? �����, ��� ���� ������ ���� ����������. ������ ���� �� ��������.";
			link.l1.go = "Mtr_acceptor_6_1";
			if (GetSquadronGoods(pchar, GOOD_SHIPSILK) >= 20)
			{
				link.l2 = "��, �������, ������ �� ���������, ��� ���� ������!";
				link.l2.go = "Mtr_acceptor_6_2";
			}
		break;
		
		case "Mtr_acceptor_6_1":
            dialog.text = "�������? ���� ������, ��� �� ���������? ���! �-���, ������, ��� ���������� �������! ����� ��� � �����!";
			link.l1 = "�������!";
			link.l1.go = "Mtr_acceptor_fight";
		break;
		
		case "Mtr_acceptor_6_2":
            dialog.text = "�������, ����� �����, �� �� ���� ������. ����������!";
			link.l1 = "� ��� �� ��� �����? ����� ���������? ������� - ���, ���, ���� ��� ����� �������� �����.";
			link.l1.go = "Mtr_acceptor_4_4";
		break;
		
		case "Mtr_acceptor_7":
            dialog.text = "� ���� �� ����? ������ ��������� �����, ��� ��� ������ �������...";
			link.l1 = "�������. �� ���� �� ���-���� ����� ������ ��� ����������, ������ ���� �����. �� ������ ���. ������� �� ������ ����������. � ����� � ����� �������� ���.";
			link.l1.go = "Mtr_acceptor_7_1";
		break;
		
		case "Mtr_acceptor_7_1":
            dialog.text = "�� ��� �� �������, ��� �������? �� ������ �� ����, �...";
			link.l1 = "��������, �� ���-�� ��� �����. � �� ������� �� ������, ��� �� ���� ���� ���������, �� � ��� �� �����. ������ ����������� - ���� ���� �� ��������. ������ ����������� ����. �����, ��������.";
			link.l1.go = "Mtr_acceptor_7_2";
		break;
		
		case "Mtr_acceptor_7_2":
            dialog.text = "������... �� ������, ��� '������' ��������?";
			link.l1 = "�� ��� ���. �� ������� ����, �������� �� ������ ���� ����� - �� ������� ���� ���������� ������������ �����, �� ������ �� ����� ������� ����. ������ �� ��� � �������. ������ ��� ���� ��������� ������.";
			link.l1.go = "Mtr_acceptor_7_3";
		break;
		
		case "Mtr_acceptor_7_3":
            dialog.text = "��� ��������... � ��� �� ��� ������ ��� ����� ������? �������!..";
			link.l1 = "��� ���� ���� ����������� �����?";
			link.l1.go = "Mtr_acceptor_7_4";
		break;
		
		case "Mtr_acceptor_7_4":
            dialog.text = "� ���, � ���� �� ���� �� �������?";
			link.l1 = "� ���� ���, �� � ���� ��������, ������� ���� ���������� �� ���� �����. ����������� ����������. �� � �� �������, �������.";
			link.l1.go = "Mtr_acceptor_7_5";
		break;
		
		case "Mtr_acceptor_7_5":
            dialog.text = "��� �� �������?";
			link.l1 = "������ ������, ����� �� ����. �� ��������� '��������' ������ ������������ ����� � ������� ��. �����, � ���� �������, ���� ���� ��� �������.";
			link.l1.go = "Mtr_acceptor_7_6";
		break;
		
		case "Mtr_acceptor_7_6":
            dialog.text = "��� �� �����?";
			link.l1 = "� ���� ����� ����? � � ���� ���� �� ����, � �� �� ���� � ���. ������ - ����� ���� � ��������, ���� �� �� �������. ��� - ��������� ����������.";
			link.l1.go = "Mtr_acceptor_7_7";
		break;
		
		case "Mtr_acceptor_7_7":
            dialog.text = "������-������, �� ��������. ����, �������. ������ ���� ����� �� ����� ������?";
			link.l1 = "���� �� ���������� ������� ���� �� �����, � ������ � ������� ����������� ����� �� ���������� � ����. ��� ������� �� ����� �������?";
			link.l1.go = "Mtr_acceptor_7_8";
		break;
		
		case "Mtr_acceptor_7_8":
            dialog.text = "�������� ���� �������� ������� �� �����. ������ ����� �� ��������, ���� ������.";
			link.l1 = "�������� ���� �������? ��. �������. �������, ������� �������� ������������� �� ������ ����������. �� �����, � ���������� � ���. �� ���� �� ���� ������� � ����� - ����� �� ����.";
			link.l1.go = "Mtr_acceptor_7_9";
		break;
		
		case "Mtr_acceptor_7_9":
            dialog.text = "�� ���������, �� ���� �������. ������� ������ �����: ������ ����� � ��� �������, ��������� ����... ���, ����� � ����� ����-����� - ��� ����������, ������ ����� ����� 10 � 15 ������, �����. ������ - '�������� �����'.";
			link.l1 = "������. ��� � ��������� ������ ������ ������.";
			link.l1.go = "Mtr_acceptor_7_10";
		break;
		
		case "Mtr_acceptor_7_10":
            dialog.text = "������� �������, ��� � ������ ��� ����� �������� ������ - � ���� ������ �� ��� ������ ��������.";
			link.l1 = "�������. � ������ ����� � �����, ��������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_CargoSilkWin");
			AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
		break;
		
		// ����� �����
		case "Pelly":
            dialog.text = "������ ������� �� ����� ���� ��������, ��������?";
			link.l1 = "�������, �����. � �� ������� �������. ��� ���� ����� � ���������.";
			link.l1.go = "Pelly_1";
		break;
		
		case "Pelly_1":
            dialog.text = "�-�, �� �������-��. ������, ��� �� - ��� ���� �� ��� ��������. ������. ��� ����� ����� ������ ��������?";
			link.l1 = "������� "+GetFullName(pchar)+".";
			link.l1.go = "Pelly_2";
		break;
		
		case "Pelly_2":
            dialog.text = "����� ����� ��������, ������� "+GetFullName(pchar)+"?";
			link.l1 = "������������ � ����� ���������. ���� �������. � ����� � ���� � ��������, �� �� �� �������, � ����� ����� ����� � ����� ����� � ����� �������. ����� ���������� ��������� ����������, �� ������ ��������� ��������� ������ � ���. ����� ���� - � ��� � ���� �����, �� ���� ��� �� ����. ���� ��������.";
			link.l1.go = "Pelly_3";
		break;
		
		case "Pelly_3":
            dialog.text = "����, ���!";
			link.l1 = "������� ������� ���� ����������� �� ���� � ����� �������?";
			link.l1.go = "Pelly_4";
		break;
		
		case "Pelly_4":
            dialog.text = "�-�-�... ������, �������. ���� ������, ���� �����, ���� �� ����� �������� ����� �� ����.";
			link.l1 = "������. ����� �� ����� ������ �������. ���������� � ����� �������.";
			link.l1.go = "Pelly_5";
		break;
		
		case "Pelly_5":
            dialog.text = "��� �����, �������!";
			link.l1 = "...";
			link.l1.go = "Pelly_6";
		break;
		
		case "Pelly_6":
            DialogExit();
			AddQuestRecord("Roger_3", "3");
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true;
			Mtraxx_PlantContinue();
		break;
		
		case "Pelly_7":
            dialog.text = "����� ����� ��������, �������?";
			link.l1 = "���� �������. � ������� ��� ����� �����.";
			link.l1.go = "Pelly_wait";
			if (pchar.questTemp.Mtraxx == "plant_3")
			{
				link.l1 = "��������� �� ������ ������� ������. � ���� �� ����� �������� ������ ��� ����� ���������.";
				link.l1.go = "Pelly_8";
			}
			if (pchar.questTemp.Mtraxx == "plant_8" && pchar.location.from_sea == "Shore37")
			{
				link.l1 = "���������� ������, ������� ��������� �����. ��������� � ��� ���� - �������� ��������� �� ��� ����.";
				link.l1.go = "Pelly_11";
			}
		break;
		
		case "Pelly_wait":
             DialogExit();
			 npchar.dialog.currentnode = "Pelly_7";
		break;
		
		case "Pelly_8":
            dialog.text = "��! �� ������� ���� �� ���������, ��, �������? ���� � ������! ��� � ���������� ����������!..";
			link.l1 = "������ �� �����, �����.";
			link.l1.go = "Pelly_9";
		break;
		
		case "Pelly_9":
            dialog.text = "����� �������, �������!";
			link.l1 = "...";
			link.l1.go = "Pelly_10";
		break;
		
		case "Pelly_10":
            DialogExit();
			npchar.dialog.currentnode = "Pelly_7";
			pchar.questTemp.Mtraxx = "plant_4";
			pchar.questTemp.Mtraxx.Chest = "true";
			// ���������� ������ � ���� � ������ ��������
			int n = Findlocation("Shore37");
			Locations[n].models.always.locators = "shore03_q_locators";
			locations[n].models.always.chest = "chest_quest";
			Locations[n].models.always.chest.locator.group = "box";
			Locations[n].models.always.chest.locator.name = "private1";
			Locations[n].models.always.chest.tech = "DLightModel";
			DoQuestReloadToLocation("Shore37", "goto", "goto5", "Mtraxx_PlantChestReady");
		break;
		
		case "Pelly_11":
            dialog.text = "����� �������, �������!..";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PlantPrepareMarch");
		break;
		
		case "Pelly_12":
            dialog.text = "������ � ��� ������, �������.";
			link.l1 = "����� ������!";
			link.l1.go = "Pelly_13";
		break;
		
		case "Pelly_13":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			chrDisableReloadToLocation = false;
		break;
		
		case "Pelly_14":
            dialog.text = "�������, �������, ������ �������, �������� �� ������ ���� ��������, ����... ���... ���� ���.";
			link.l1 = "�� � �����... ��� ��� ��������� - ����� ��������� ����� ����, ��� �� ����, ��� ��������� �� ��������� �������� ��������� ��������...";
			link.l1.go = "Pelly_15";
		break;
		
		case "Pelly_15":
            dialog.text = "�������, ������, ��������, ���������... �� �� �� ����� � ���� �����, � �� �� ����� ��� - �������. ����� ����������. ��, � � ���������. � �� ��������� �����...";
			link.l1 = "�� ��...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PlantFailFinal");
		break;
		
		case "Pelly_16":
            dialog.text = "�������, ������ �������. � ������� ����� �� ��� �������� ��������� �������. ������� �� ������.";
			link.l1 = "������� ��?";
			link.l1.go = "Pelly_17";
		break;
		
		case "Pelly_17":
            dialog.text = "��� �����. ����� �����. ���� - �����...";
			link.l1 = "��� �� ��� ���������. ���, �� ����������� �� ���� � ������. �����, ��������� ��������� ���� � �� ���� ������� ����� ������ - �������, �� �������� �������. � � ����� ����� �� �������� - ������� �� �� ���. �������� � �� ���� � �������.";
			link.l1.go = "Pelly_18";
		break;
		
		case "Pelly_18":
            dialog.text = "��...";
			link.l1 = "���������! �����, �� ���� ������ ��������� ������� ����� ��������. ��� �� ����!";
			link.l1.go = "Pelly_19";
		break;
		
		case "Pelly_19":
            dialog.text = "����, �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PlantSeaEscape");
		break;
		
		case "Pelly_20":
            dialog.text = "�������, ����� ����� ������������?";
			link.l1 = "���������� � ���. � ����� ������ �� ����� �������!";
			link.l1.go = "Pelly_21";
		break;
		
		case "Pelly_21":
            dialog.text = "��� �����, ������� - �� ������ �������!";
			link.l1 = "...";
			link.l1.go = "Pelly_22";
		break;
		
		case "Pelly_22":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			chrDisableReloadToLocation = false;
		break;
		
		case "Pelly_23":
            dialog.text = "��! �������, �����. ������ ������� �� �������?";
			link.l1 = "����� ��������� ������ ��� �������, ������� ���� ����. ��������, ���, ������ �����, ������� ����� � ���� ����, �� ������� ����?";
			link.l1.go = "Pelly_24";
		break;
		
		case "Pelly_24":
            dialog.text = "������ ����������? � ��� �� ������ ����������� ����� �������. � � ������ ������� ���������� ������ �� ������������. ����� ���������� �����? ������, �������� �� ���� ��������...";
			link.l1 = "��� ����, ���������� - ��������� ������ � ��������� �� ��������? � ����� �������?";
			link.l1.go = "Pelly_25";
		break;
		
		case "Pelly_25":
            dialog.text = "��������, �� ����-�� �������. ������ ��������������� �� ���������� - ��� ���� "+GetFullName(characterFromId("Tortuga_usurer"))+" �����. ���������� ������� �������� - ������, ���������, �������, ������, ������� � ���������� ������... ������, �� �������� ����, � �� ������ ��������� ��������. ��� ��������� ���� � ���� �������.";
			link.l1 = "��� ��� ��� ���... � ��� �������, ��� ���-����� ���� � ���� ���� �� ������� ������, ����� ��������� ����...";
			link.l1.go = "Pelly_26";
		break;
		
		case "Pelly_26":
            dialog.text = "��-��! ������ ���, ��� ���� ��� ������! ���� � ����� ��� � ��������� �����. ������ ������� ������������, � ������� � ��� ���� - ������ ���� ������ � ���������. �� � ��� ��� ��� � ����� �������� - ����� ��� �������� � ������ ��������?";
			link.l1 = "��� ����. �������, �����, ����� � ����!";
			link.l1.go = "Pelly_27";
		break;
		
		case "Pelly_27":
            dialog.text = "� ���� ���� ��, �����.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_WolfreekReadLogbookThird");
		break;
		
		case "Pelly_28":
            dialog.text = "������� ���� ������, �����. ��������� � ������ � ��� ��������. ������ �������, ��� ��������? ��-��-��?!";
			link.l1 = "�������, ������ �������, � ������� - �������... � ��������� ������������� ��� ��������� ���� �������.";
			link.l1.go = "Pelly_29";
		break;
		
		case "Pelly_29":
            DialogExit();
			sld = CharacterFromID("Mtr_CartahenaMayorClone");
			sld.dialog.currentnode = "CartahenaMayor_8";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "Pelly_30":
            dialog.text = "���� ������! ������ ������� �� ��� ��������, �����?";
			link.l1 = "�����?! ��� �� �� ������! �� ������?";
			link.l1.go = "Pelly_31";
		break;
		
		case "Pelly_31":
            dialog.text = "���, ��� �� ������?! �����, ����� �� �������! ������ ������ ���� �� ���������� ���������, ���? �������, �� ����� �...";
			link.l1 = "������? ���... � ����� ����� � ����� ����� - �� ��� � ������ ����. ���� ���, ��������, ������� �������� ����� - ��� ������ ������! �� ������� �� ��������, ��?.. ���, ����, ��� ������� �� �������� - ��� ����� ����� ������!";
			link.l1.go = "Pelly_32";
		break;
		
		case "Pelly_32":
            dialog.text = "��, ���� ������, ����� ����� ����� ������, �� ��� ���! �� ����, � �� �������! � ������ ��� ����� - ��� ��� � �����������! � �������, ������ � ��� ���� �����! �� ���� ����!";
			link.l1 = "��������, �����, �� ���� ���������? ����� �� ��� ���� - ��� ����� �� ������ ��������, � ������ ����� - ������. ��� ����� ������!";
			link.l1.go = "Pelly_33";
		break;
		
		case "Pelly_33":
            dialog.text = "���� ������ ��������� ������ ����, �����! �� � ���� ��� �� ����������� - � �� ������� �� �������. ������ �� � ���� ���! ��������� ����������� ��� �� ����� �������!";
			link.l1 = "���� ���� ����, ���, �� ��� �� ���� �����? ������� �� �����������? ���� �������� ����� ������ - �������� �����. ������� ������, � ���� ������� �� ������ ����� �����.";
			link.l1.go = "Pelly_34";
		break;
		
		case "Pelly_34":
            dialog.text = "�� ������ ���� ����������, �����? ��� �� �� ���! � �� ����� ���� �� ������, �� ������ �����! �� �������!\n�-�, � �������, ��� �� �������! ������� ���� ����, ���� ��� �� �������!!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionPellyFight");
		break;
		
		// ��� �����
		case "rocur":
            dialog.text = "��� ���� ���� �� ����?";
			link.l1 = "��������, � ��� ���� ������. ��� �������� �� ��?";
			link.l1.go = "rocur_1";
		break;
		
		case "rocur_1":
            dialog.text = "�������� �. � ��� ���� ���� � ���-�� �� ����������.";
			link.l1 = "�������, ���. � �� ������� �������. ��� �������� �������� ���� ������.";
			link.l1.go = "rocur_2";
		break;
		
		case "rocur_2":
            dialog.text = "������? �-�-�... ������, �������, �� ����. �� �� ���� �������� ����� ������ - ������������ ����, ������... ��, ����, ���� � ��������, ��� ��� ������� ���� � ����� ���� � ����� �� �������. ��� � ���������. ���, ��� ����...";
			link.l1 = "...";
			link.l1.go = "rocur_3";
		break;
		
		case "rocur_3":
            DialogExit();
			AddQuestRecord("Roger_3", "6");
			LAi_CharacterDisableDialog(npchar);
			Mtraxx_PlantMakeMaxRocurClone();
		break;
		
		case "rocur_4":
            dialog.text = "�� ���, ��� ����� �������� ����������... ��� ���� ���, ��������?";
			link.l1 = "������� "+GetFullName(pchar)+". ������ �����������, ��� �� ������ � ��� ���������. ������ ����� ��� �����.";
			link.l1.go = "rocur_5";
		break;
		
		case "rocur_5":
            dialog.text = "�� ������ �� ��� � ������� ����������� ����� ����... ��������� �� ������ ������� ������ - ����������� ��������� ��������. � ���� ����������, � ���� - ������. �������� ������� �������� ��������, ��������� �����. ���� ��� ��� ���������. ����� � �����, ������ ������ ������ - ��� ������ �� �������� - ��������� ������� ������ �� ����� �������\n��������� ��������� ������ � - �������, �, �������, ���� - ���� �� ����������� ���������� ������ �������� �������. ������� �� ���� �������� � ������, �������. ����� �� ������� ���, ���� �� ����� - ������� � ���� � ������� ����, �� ���������, ��� ����. ��� � ��� �������.";
			link.l1 = "����. ��� �������� - ������� �������� ����������� �� ���?";
			link.l1.go = "rocur_6";
		break;
		
		case "rocur_6":
            dialog.text = "� ��� ��� �����. ������� �������� �������� �� ����� ��������, ����� ��������� ����� �������� ��������. ������... ��� � ������, �������� ���.";
			link.l1 = "��. ��������. � ��������� ������ �� ������ ��������? ��� �� �����?";
			link.l1.go = "rocur_7";
		break;
		
		case "rocur_7":
            dialog.text = "������ �� ��������. ������������ ��� ������� �����, ����� �� ������ ������. ������ ����, �������������. ��������� ������ �� ��� ��������� - ��� � ������ � ����� �������. ����� �������, ����� ������, � ������� �����, � ������ - ������ ����������, ����� �������� ����� �����������.";
			link.l1 = "������� �����? �� ������ ������? �������?";
			link.l1.go = "rocur_8";
		break;
		
		case "rocur_8":
            dialog.text = "���������� ��, �� �������. � ��� �� ����, ��� � ���������� ��������? ����� ������ ����� � ������� �����������, ������ ��.";
			link.l1 = "�������. �����, ����� ����� ������, ��� ���� ��������� ������. � ������ �����-������ ����������� �����?";
			link.l1.go = "rocur_9";
		break;
		
		case "rocur_9":
            dialog.text = "������ ������ �� ������������?";
			link.l1 = "��� �������, ���������� ����� � ���� ������ �����. ��� ����� � ����� ���������, ����� ����� ��������� � ����� ������� � ������ ������.";
			link.l1.go = "rocur_10";
		break;
		
		case "rocur_10":
            dialog.text = "��...";
			link.l1 = "� �� ������, ��� ������ ������� ���� �������� �������?";
			link.l1.go = "rocur_11";
		break;
		
		case "rocur_11":
            dialog.text = "� ������ ������ �� ������. � �������, ��� ������ �� ����� ��� ����.";
			link.l1 = "��� ������ - �� �����. ��, ���� ����?";
			link.l1.go = "rocur_12";
		break;
		
		case "rocur_12":
            dialog.text = "������� ������ ������ ��� - ��������� ����� ������ ����������, � �� ��������� �� �� - ����� ������������ �������. ���������� �� �� ���� �� ������� - ����� ��������, � ���� � ���������������� ��������. ��� �� ������������ � �������� ���������.";
			link.l1 = "� �� � ���� ������ ������� �� ��������? ������� ���������� � �����.";
			link.l1.go = "rocur_13";
		break;
		
		case "rocur_13":
            dialog.text = "���? ������ ������? ��� ������� ������?";
			link.l1 = "� ���� �� ���� ������ - ������� ��?";
			link.l1.go = "rocur_14";
		break;
		
		case "rocur_14":
            dialog.text = "�����������! �������! ��� ������ ��� ��� �����, ��� ������? �� ��������� ������� �������� - ���� �������� ����� �����������, � ���� ������, ��� �� ������ ���� ������ ������ � ��������... ������ �� ����.";
			link.l1 = "� ���-���� � ���� ������������� ������ ���� �������. ��� �������� ������ �� ��������� - ��� ���������. ������� �����, ��������� ������� �����, ����� ���������?";
			link.l1.go = "rocur_15";
		break;
		
		case "rocur_15":
            dialog.text = "������� �������� �����.";
			link.l1 = "������, ���� �������� ������... � �������� �� ���� �� ��������.";
			link.l1.go = "rocur_16";
		break;
		
		case "rocur_16":
            dialog.text = "���, �� ��� ������ ��������?";
			link.l1 = "����� ���. � �� ����� ���� ������ �������. ��� ��� �� ������?";
			link.l1.go = "rocur_17";
		break;
		
		case "rocur_17":
            dialog.text = "�����... ����� ���������� ���� ��. ������ ����� ������� - �� ������� ��� ����� � ���������� ���������� �������� ��������. ������� - ������� ��������. ���� ������� ��������� ������ ��� ��� - ���� �� ������������: ������� ���� ������ ����� �������� �� �����. ����, �����. ����� �������� �� ���-��� ����� �� ����� ����������...";
			link.l1 = "����. ����� � ������ ����� ������ ����� �� �������� ��������, � ��� � ��������� �������� ����������. ��� ������ ��� ����������� - ��� �����.";
			link.l1.go = "rocur_18";
		break;
		
		case "rocur_18":
            dialog.text = "������ �� ������� �� �������, ����. � �� ��� ��� ���� ���������� �� ����������� ������. � ��� ������ ������� ����� ����, ��� �������: ���� �� ��������� - ������.";
			link.l1 = "������, ��������. ���������, � ���������� �� ����������. �����.";
			link.l1.go = "rocur_19";
		break;
		
		case "rocur_19":
            DialogExit();
			AddQuestRecord("Roger_3", "7");
			npchar.dialog.currentnode = "rocur_wait";
			pchar.questTemp.Mtraxx = "plant_3";
			pchar.quest.Mtraxx_PlantPrepareTimeOver.over = "yes"; //����� ������
			SetFunctionTimerCondition("Mtraxx_SeekWeaponOver", 0, 0, 300, false); // ������
		break;
		
		case "rocur_wait":
            dialog.text = "����� �������, ��������? ������ ������?";
			if (pchar.questTemp.Mtraxx == "plant_5")
			{
				link.l1 = "��. ������ � ������� ����� � ����� �������. �������� ����� ������ �������� ��� �� ���������.";
				link.l1.go = "rocur_20";
			}
			else
			{
				link.l1 = "� ������� ��� ����. ���.";
				link.l1.go = "rocur_wait_1";
			}
		break;
		
		case "rocur_wait_1":
            DialogExit();
			npchar.dialog.currentnode = "rocur_wait";
		break;
		
		case "rocur_20":
            dialog.text = "����� ������, ���. � � ��� ������� � ���, ��� ����� ����������� �������� ������ ����.";
			link.l1 = "���, ��� �� �� ����� ����� �����. ����������.";
			link.l1.go = "rocur_21";
		break;
		
		case "rocur_21":
            dialog.text = "�� ���� ��������� ���������� ����� �� ��������� ���������, � ����� ���������� �����-����. ������� ����� ������� �� �������� ����� �������� �����, �� ����������� ��������� ��� ��������� �������� ������ � �������� ���������� - ��� ��������. �������� ������������ ���������� ��� ���������, �� �� �� ������, � � ����� �� ������ �����, ������ ������� � ������� ����� ���������� � ������: ����, ������, �����, ���. �������� ���, ����� ��� ���� ������� ��� �������, �� �� �������������� - ����� �������� ����������\n��� � �����-���� ������, ����� �������, �� � ��������� ������. ����� �������� � ������, ����� �����, ������� ������� ���� ���� �� ���������, ���� ��������� �������� �� ���� �� �����. ����� '� ��������' ����� ������� �������� ������ � �������� ���, ����� ���� ����� ��������� �� �� �����������\n�� � ������ ����� �� ��������� ������� ���������� � ���, � ����� ������� ���������� �������. ��� ��������� ����� �����, �������.";
			link.l1 = "� ���� ������� ������ �����, ��������! �������� ����. ��� � ����� �����������.";
			link.l1.go = "rocur_22";
		break;
		
		case "rocur_22":
            dialog.text = "� ���: ��������� ������ ���� ��� ������: ��� ������ ������ �������, ��� ������ ������ ����� ������� ��� ������������, � ��� ��� �� � ����, ��� �� ���������.";
			link.l1 = "��������. ������ �����-�� ���� ���. ����, ������, �����, ��� ��������?";
			link.l1.go = "rocur_23";
		break;
		
		case "rocur_23":
            dialog.text = "��. �� ��� ����������� ������ ����������, ��� �� ������ ��� ����. � ���� ��, ��� ������������ � �������� �������� �� �����.";
			link.l1 = "������������. ��� ���� ������ � ����������� - ��� �����.";
			link.l1.go = "rocur_24";
		break;
		
		case "rocur_24":
            DialogExit();
			AddQuestRecord("Roger_3", "9");
			npchar.dialog.currentnode = "rocur_wait_2";
			pchar.questTemp.Mtraxx = "plant_6";
		break;
		
		case "rocur_wait_2":
            dialog.text = "������, �������, ����� ������...";
			link.l1 = "";
			link.l1.go = "rocur_wait_3";
		break;
		
		case "rocur_wait_3":
            DialogExit();
			npchar.dialog.currentnode = "rocur_wait_2";
		break;
		
		case "rocur_25":
            dialog.text = "";
			link.l1 = "(����������) ������ ���������. ����� ����� �� ��������� ������ �������. �� ������ ������ �������� ����� W, �� ��������� - ���� ������ �������. ������ �����. ������� ����� ���������, � ��� ����.";
			link.l1.go = "rocur_25x";
		break;
		
		case "rocur_25x":
            dialog.text = "�� ������ �� ������ �������...";
			link.l1 = "";
			link.l1.go = "rocur_26";
		break;
		
		case "rocur_26":
            DialogExit();
			LAi_CharacterDisableDialog(npchar);
			DoQuestFunctionDelay("Mtraxx_PlantWaitDay", 3.0);
		break;
		
		case "rocur_27":
            dialog.text = "�������-�� � ����� ���� ����! ��� � ����� ��� ��� �������� � ��� ������. �������� ������, �������! � ����� ����� � �����.";
			link.l1 = "�������� ���-������... �������� � ������ � ����������!";
			link.l1.go = "rocur_28";
		break;
		
		case "rocur_28":
            DialogExit();
			sld = characterFromId("Pelly");
			sld.Dialog.currentnode = "Pelly_16";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "rocur_29":
            dialog.text = "�����������, "+pchar.name+". ��� ���� ������ �����, � ��� ����, ��� �� ���������� � ����� ������. ���� ��������� ���������, �� � ������, ��� �� ���������.";
			link.l1 = "������, ���. ����������� ������ ����, ��� �� �����?";
			link.l1.go = "rocur_30";
		break;
		
		case "rocur_30":
            dialog.text = "������ ��� � �����, ������ �������� � ����. ���� � ��� � ������� �� ��������� ���������, � �� ������ ���� ����� ��� ������� �������, �� � ������ ��� ������ ���������. ������� ����� ���������, �������� ����� �����-������ ����... ��� ���, �� ���-������ �� ����� ���������, ����� ��������, ����������� ��� ������ ������, � ����� ���� ������������� ��������� ��������� ��������� � ��������� ���������: ��������-��-���-����������-��-������. ����� ����� ��� ������ ������\n��������� ������� ����� ��� - �������, ��� �����������? ������ ���� ������ ����� ������� ��������� ����� �� ���������. �� ������������� ��������� � �����, ��� ������ ������ ����� '����������� ����' - ������� ������� � �����-������� ����������� ������. ��� ������ ������ �������� � �����. ����� ��������� ���������� � �������� ����� - ������� � ������ �������������\n����� � �����, ��� ��������� ������ �� ��������� �������� � ����� ������� �������-����������� - �����, �������, ������. ������ ��� ������� ���� ��� ������ ��� ����� ������� ������, ������� ��� ���� ��������� ������ ������, ��� ��� ������� ������� ��������� ������������ �����.";
			link.l1 = "�� ������ �������� ���� �������?";
			link.l1.go = "rocur_31";
		break;
		
		case "rocur_31":
            dialog.text = "������. ���������� ����� �������� � ��� ��������� � ��������� ���������� - ������ ������ ��� ������ ��������. � ���� ��, �������� ����� �� ����, ��� ���� �� ������������, ��� �� ��� ����� ������� ���-��, ����� ������� � ������� � ������.";
			link.l1 = "��������� �� ������, ��� � ���� ��������� ������������� ������� ������� �����?";
			link.l1.go = "rocur_32";
		break;
		
		case "rocur_32":
            dialog.text = "���� ��� ����� �������� ���������, � ���������� �� ���� ������� �������� ��� �������� � ���� ��������� ������ ������ � �������� � ��������� �� ��� ���, ���� �� ��������� ���� ���� ���� � �������.";
			link.l1 = "����... ��� ������ � ������ - ���� ��������?";
			link.l1.go = "rocur_33";
		break;
		
		case "rocur_33":
            dialog.text = "������ ���� ����� ������� ���, �������, ����������, �� �� ������ ���������� �� ��������. ��������� �� ����� ����������� ����� ���������, ������ ��������� ������� � ������ � ��� ����, ��� ����� ������.";
			link.l1 = "...";
			link.l1.go = "rocur_34";
		break;
		
		case "rocur_34":
            DialogExit();
			sld = characterFromId("Terrax");
			sld.Dialog.currentnode = "mtraxx_38";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "rocur_35":
            dialog.text = "�������, �� ������, �������, �� ������ ����� �� �� ��� ��� �� � ������? �? �� �������� �� ���� ����� ����! �� � ���������� ������������ ������, �� ��� ��� ����. �������, ��� ������. � �� ��������� ������������ ������ ������ - � �������� � ���������. ���, ����� 50 000 ���� �� ���� ������ � ��������� - � ������� � ������. � ������ ������ - ����, � ��� � ���� ������� ������.";
			link.l1 = "��...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_MeridaTimeOverFail");
		break;
		
		case "rocur_36":
            dialog.text = "��� �� � �� �����. ������ ���� ����� ����� �������. ������ � ����, ��� ������ ������� �������� � ������ ����������, �������� ���������.";
			link.l1 = "��� � ��������. ���, ��� ������ �������� ��� ������������?";
			link.l1.go = "rocur_37";
		break;
		
		case "rocur_37":
            DialogExit();
			sld = characterFromId("Lepricon");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "rocur_38":
            dialog.text = "� ���������� ������ ���������. ������ �� ���� �� ���������� � ��������� ��������������. ������, � �����!";
			link.l1 = "� �����!!";
			link.l1.go = "rocur_39";
		break;
		
		case "rocur_39":
            DialogExit();
			chrDisableReloadToLocation = false;
			LocatorReloadEnterDisable("Merida_ExitTown", "reload1_back", true);
			pchar.quest.mtraxx_merida_town.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_town.win_condition.l1.location = "Merida_Town";
			pchar.quest.mtraxx_merida_town.function = "Mtraxx_MeridaTown";
			Mtraxx_MeridaCheckOurWarriors();
			AddQuestRecord("Roger_5", "16");
		break;
		
		case "rocur_40":
            dialog.text = "���! ������ �������� ������������� �� ��������. ������ ���� ������������ � ������������ ����� ���������. �������, �� �������� �����������, � ��� �� �������� ��������� � ������� �����.";
			link.l1 = "����!.. ��������! �� ����!";
			link.l1.go = "rocur_41";
		break;
		
		case "rocur_41":
            DialogExit();
			chrDisableReloadToLocation = false;
			LocatorReloadEnterDisable("Merida_Town", "gate_back", true);
			pchar.quest.mtraxx_merida_townhall.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_townhall.win_condition.l1.location = "Merida_townhall";
			pchar.quest.mtraxx_merida_townhall.function = "Mtraxx_MeridaTownhall";
			sld = characterFromId("Mrt_Rocur");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			sld = characterFromId("Lepricon");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			AddQuestRecord("Roger_5", "17");
		break;
		
		case "rocur_42":
            dialog.text = ""+pchar.name+", ��� �������. ��� ����� ����� ��������� � ������. ��� � � ������.";
			link.l1 = "������� ��� � ������ ������. ���� ������������ � �������� ����.";
			link.l1.go = "rocur_43";
		break;
		
		case "rocur_43":
            DialogExit();
			chrDisableReloadToLocation = false;
			pchar.questTemp.Mtraxx = "merida_success";
			AddQuestRecord("Roger_5", "12");
			pchar.quest.mtraxx_merida_exit.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_exit.win_condition.l1.location = "Merida_Town";
			pchar.quest.mtraxx_merida_exit.function = "Mtraxx_MeridaExit";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
		break;
		
		case "rocur_44":
            dialog.text = "������� ���������, "+pchar.name+"! ������ ����� ������ �������. � ��� ��� ���������. � ������� ���� ����� ��� ������ ��������: 1050 ���� ���������, 732 ����� ������ � 189 ���� �������� ������. ���� ����������� ������ �����: 350 ���������, 244 ����� � 63 �������� �����. �����, ��� ���� ����.";
			link.l1 = "�������!";
			link.l1.go = "rocur_45";
		break;
		
		case "rocur_45":
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "jewelry4", 350);
			TakeNItems(pchar, "jewelry16", 244);
			TakeNItems(pchar, "jewelry14", 63);
            dialog.text = "������ ��������� � ���� ����� ����� ����� �� ������������ �� ������� � ���������. � �������, ��� �� ������� �� ��� ����������. ����� ����� ����������� �� �������� ������������? � ���� ������� ������� �� ���� ����.";
			link.l1 = "�����, ��� ����� �� ����� ���� ����� ������ ����������. ���� ���� ����� ������ - ����� �������� � ��������� �������, ������� �������...";
			link.l1.go = "rocur_46";
		break;
		
		case "rocur_46":
                                                         LocatorReloadEnterDisable("Shore106", "boat", false);
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "jewelry4", 116);
			TakeNItems(pchar, "jewelry16", 81);
			TakeNItems(pchar, "jewelry14", 21);
            dialog.text = "�������, �������. � �����, ��� �� ��������� �� ������ ��������... ������ ��� � ������ ����� ����� ������. ���, ����� �����.";
			link.l1 = "������� ��� �����, ���! ������ ������������ �����, �� ���������, � �������.";
			link.l1.go = "rocur_47";
		break;
		
		case "rocur_47":
                                                         DialogExit();
			chrDisableReloadToLocation = false;
			pchar.questTemp.Mtraxx = "merida_gohome";
			AddQuestRecord("Roger_5", "18");
			sld = characterFromId("Mrt_Rocur");
			LAi_SetWarriorType(sld);
			LAi_CharacterDisableDialog(sld); // �����-������
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
			sld = characterFromId("Lepricon");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
			sld = characterFromId("Terrax");
			sld.dialog.currentnode = "mtraxx_40";
			pchar.quest.mtraxx_merida_lavega.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_lavega.win_condition.l1.location = "Hispaniola1";
			pchar.quest.mtraxx_merida_lavega.function = "Mtraxx_IgnasioKitty";
			// ������ �� ������� ����� 40 ����
			SetFunctionTimerCondition("Mtraxx_MeridaReturnLate", 0, 0, 40, false);
			DeleteAttribute(pchar, "GenQuest.HunterLongPause");
		break;
		
		case "rocur_48":
            dialog.text = "�, ����� �������! ��� ���� ������, "+pchar.name+". ��� ����?";
			link.l1 = "���� ���� �������. ������ ��� �������� ������� � ������ ��������� ������� ������ ������ - ������� ��� ��������� � ������� ���������. � ������ ��� �� ���������, �������� ������... ������ ���������. � �� � �������?";
			link.l1.go = "rocur_49";
		break;
		
		case "rocur_49":
            dialog.text = "��. ���� ������������ � ��� ������ �������� ������. ������ �������� ���� � ����, � �������� ��������� ����� �����������-�����������, � �� �������� �� ������ �����-�� ����� � ��� ���� �������� ����������, ��� ��� ������� �����. � �� ���������� ������ � ������ ��������, �� ������ ������ �� ������� ���... ��� ������ ������ ����� ������ �� ����� '�������'...";
			link.l1 = "��-��... ������ ������ ������ �� ������. �������� � ��� � ����.";
			link.l1.go = "rocur_50";
		break;
		
		case "rocur_50":
            dialog.text = "�� ��������?";
			link.l1 = "����� ���, �� � ���� ����� �� �������, ������? �� ��� ����� ������ ����� � ����, � ������ �������. �� ����������� �� �������. � �� ���� ������ ���� ����������, � ������������, ��� ��� ������ �� �������������� - ����� ����� ���� � ��������. ��� ��� ������� ���� ������ �� ����, ���� �� ������ ������ ��������� �������. �� �� ������ � �� ���������, ���� ��� ����� ������� ������.";
			link.l1.go = "rocur_51";
		break;
		
		case "rocur_51":
            dialog.text = "��� ��� ��� ���... ��� ������ - �� ���� ������� �� ��� ������?";
			link.l1 = "�� ��. � �������� ����� ���������� ��������� ��� �����, �� ����� ����� �����������, ���������. � �������� ����� �� ��������� - ���� ������.";
			link.l1.go = "rocur_52";
		break;
		
		case "rocur_52":
            dialog.text = "� ���� �� �������������� ����������� ��������� ���, ����� ����� �� ����� - �� �� ����� �� ���?";
			link.l1 = "��! �������. ������ �� �����������, ���. �������� �� ����� ������ - ���� �� ������� �� ����� � ����������. �� ������, ��� ��, ��� ��� ������?";
			link.l1.go = "rocur_53";
		break;
		
		case "rocur_53":
            dialog.text = "�� ������ �� ���������? ����� ����� ������ � �� ����?";
			link.l1 = "������ ��� ��� �����.";
			link.l1.go = "rocur_54";
		break;
		
		case "rocur_54":
            dialog.text = "���������� ���������� �� ��� ������. � ��� ������� �������... ������� ����� ����� ������������ ���� � ����� ������, ��� �� ����� ������. � ���� ����� ���� ���. ������ �� ����� � �� ����, ��� �����.";
			link.l1 = "������, �� ��� ���-�� �������, ��-��. ������. � ����������.";
			link.l1.go = "rocur_55";
		break;
		
		case "rocur_55":
            dialog.text = "����������. �� �������!";
			link.l1 = "...";
			link.l1.go = "rocur_56";
		break;
		
		case "rocur_56":
            DialogExit();
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload3", "none", "", "", "", 10.0);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			ReOpenQuestHeader("Roger_4");
			AddQuestRecord("Roger_4", "11");
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l1 = "Timer";
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l1.date.hour  = 1.0;
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 14);
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 14);
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l2 = "location";
			pchar.quest.mtraxx_pasq_gonaiv.win_condition.l2.location = "Shore34";
			pchar.quest.mtraxx_pasq_gonaiv.function = "Mtraxx_PasqualeJanGonaiv";
			SetFunctionTimerCondition("Mtraxx_PasqualeJanTimer", 0, 0, 14, false); // ������ ������� 3
			SetFunctionTimerCondition("Mtraxx_PasqualeJanTimeOver", 0, 0, 22, false);
			pchar.questTemp.Mtraxx.Pasquale.Grabbing = "true";
		break;
		
		case "rocur_57":
			if (pchar.location.from_sea != "Shore34")
			{
				dialog.text = RandSwear()+"��� ���� �������? �� ������ �� �� ���� ����, ��� ��, �������? � �� ������ - �� ��������� � ������ �������. ��, ������ ������ ��� ����. ����!..";
				link.l1 = "��...";
				link.l1.go = "rocur_58";
			}
			if (GetOfficersQuantity(pchar) > 0)
			{
				dialog.text = "��� � ��, "+pchar.name+". �������, ��� ������. ������ �� ������� ����� ����� - ����� �������� � ����� �� ����. ������ ��� ��� �� �����.";
				link.l1 = "������, ������ ������� �� ����.";
				link.l1.go = "rocur_59";
			}
			else
			{
				dialog.text = "��� � ��, "+pchar.name+". �������, ��� ������. � ���� ���� ����������� ��� ����. ����� ���������?";
				link.l1 = "�������!";
				link.l1.go = "rocur_61";
			}
		break;
		
		case "rocur_58":
            DialogExit();
			Group_DelCharacter("RocurSeaGroup", "Mrt_Rocur");
			Group_DeleteGroup("RocurSeaGroup");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "sea", "none", "", "", "OpenTheDoors", 10.0);
			AddQuestRecord("Roger_4", "14");
			CloseQuestHeader("Roger_4");
		break;
		
		case "rocur_59":
            DialogExit();
			LAi_SetStayType(npchar);
			npchar.dialog.currentnode = "rocur_60";
		break;
		
		case "rocur_60":
            if (GetOfficersQuantity(pchar) > 0)
			{
				dialog.text = "������ �� - ������� ����� ����� ��������! �� ����� ��� ���...";
				link.l1 = "��-��, � �����.";
				link.l1.go = "rocur_59";
			}
			else
			{
				dialog.text = "�������. ������ ����� �� ���������, ��� ��� ����������. � ���� ���� ����������� ��� ����. ����� ���������?";
				link.l1 = "�������!";
				link.l1.go = "rocur_61";
			}
		break;
		
		case "rocur_61":
            dialog.text = "�� ������ ������ ������� �� ����?";
			link.l1 = "��... ���������. � ���?";
			link.l1.go = "rocur_62";
		break;
		
		case "rocur_62":
            dialog.text = "������� �������� �� ����������� ��� ������ �� ��������? �� ���� ����� �������, ��������� - ������ '��������� �������'.";
			link.l1 = "��� ������� ��� ����� ��� ������? ����. � ��� � ���� �����?";
			link.l1.go = "rocur_63";
		break;
		
		case "rocur_63":
            dialog.text = "�� ����� �������� - ���� ��� ��� ����� ������. ���� �� ��� � ������ �� ���������, � �� ���� ������� ��� ���� �������� ������. ������ � ������� ��� ���. � ��������� ����� ��� � ���� ����. ����������, ��� ���������... � ��������.";
			link.l1 = "���������...";
			link.l1.go = "rocur_64";
		break;
		
		case "rocur_64":
            dialog.text = "� ����� ������� ������ ���������� �����-�� �������, ����� � ������� � ������� ��������� � ���� ���. ����� �������� ����� � �� ����. �� � ������ ���� ��� � ���� ������������ ����, ���� �� ���-���.";
			link.l1 = "���� �������������?";
			link.l1.go = "rocur_65";
		break;
		
		case "rocur_65":
            dialog.text = "� ��� ��� ������? ���� ��� - ���� �������� ������ � �� ����. � ��������� � ����. ������� ������� �������, �� � ���������� �������, �������, �������... �����, ��������� ����� ��� ������� ����� ���� � ���.";
			link.l1 = "���-���... ������ ���������� ����? � ��� �� �������� �����? � �����: ��� �������, ������� ������ - ���� ������� ��������, � �� ����� �������...";
			link.l1.go = "rocur_66";
		break;
		
		case "rocur_66":
            dialog.text = ""+pchar.name+", �� ���� �� ������ �������? ������ � ������ ��� �����: � ��� ������ ����������� �� ������� �������� ���� ������ ������ ������ ������ �������� ��������, � �� ������� ���� ������ ������� �� ���� ����. �������� � �������� �������, ������ ��� ��� ��������.";
			link.l1 = "���! � ���� �� �� �� ��� ��� ��� ���� �� ���������, � ����� �������� ��� ���� �� ���� �� ����?";
			link.l1.go = "rocur_67";
		break;
		
		case "rocur_67":
            dialog.text = "������ ����� ����������. ���� ������ ������, � ��� - �����. � ������ ����� ������ ������, ��� ���.";
			link.l1 = "�� ��, ����� �������� ������, ����� �� ������ ����, ��� � ����, ��-��-��!.. � ��� �� ������? �������������, ��� �����, ���� �� ��������, ����� �� ����� �������� � �������� ��������...";
			link.l1.go = "rocur_68";
		break;
		
		case "rocur_68":
            dialog.text = "�� ��������. �� ����� ������ ������ ��������� � ����� ����������. ���� �� ����� ����� � ����� ���, �� �� �������� ������ ������������ � ���� �����. �� ���, �� ����� ����� � �� ���� ��������� �����? ������ � �������� ����� �� ����������, ��� �������� � ����� ����: �� ��� � ������ �� ���������, � � ���� �� �� ���� ������ �����.";
			link.l1 = "� ������������� �������� �� ����� ���� �������� �������. �� �����, ���: �� ���, ������� �� ����� ����� ������� � ������� �� ���� ������?";
			link.l1.go = "rocur_69";
		break;
		
		case "rocur_69":
            dialog.text = "� ������, ��� ����� ������ ����, ������� �� ������ ������, �� �������� ���� ����. ����, �� ����?";
			link.l1 = "��!";
			link.l1.go = "rocur_70";
		break;
		
		case "rocur_70":
            dialog.text = "�������, � �� ������ � ����. ������ ���� ��������, � ����� � �������� �������� � �� ����.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNight");
		break;
		
		case "rocur_71":
            dialog.text = "���� ���������. �� �������� �� ������ ������� ���� � �������� �� ����.";
			link.l1 = "������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNightMarch");
		break;
		
		case "rocur_72":
            dialog.text = "�-�-�... ������ ���������, �����, � ���� ��������. ������ �� ���� � �� ����.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNightToHouse");
		break;
		
		case "rocur_73":
            dialog.text = "������ - ������� ����� ������ �������. ����������. ������� ��� ��� ������ � �����, ����� ���������� ������ � ����� �������, � � ���������� ������� ���: ��� �������� ��������, ��� ������ ������ ���� ����� �����. ����� ����� � ��� ������ ���������, �� ������� � ����� � �� ����.";
			link.l1 = "������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNightInHouse");
		break;
		
		case "rocur_74":
            dialog.text = ""+pchar.name+", ��, ��� ��� � ����? ���� ��� ����������?";
			link.l1 = "��� ���� � ��������. ������� �������, ����� �������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeJanSeeGirl");
		break;
		
		case "rocur_75":
            dialog.text = "���������! ��� ��� � ���� ����� ������ ������ ���� �� ���� �����! ��� �� ������ ����� ���������, �� � �������.";
			link.l1 = "������, �� ����� ������ ��� ���������.";
			link.l1.go = "rocur_76";
		break;
		
		case "rocur_76":
            dialog.text = "����� ����. ������ ����� �� ��� ������ - ����� ������, ��� �� �������� '��������'... �� ������� ���. �������� �� �����.";
			link.l1 = "�� ��?";
			link.l1.go = "rocur_77";
		break;
		
		case "rocur_77":
            dialog.text = "��� ������ ���� ���������� � ������� ���� ���. ��� ��� ������� �������, � ��� ����� ������ - ��� ���������. � ��� � ����� ��� ������ - ��� ������ ���������.";
			link.l1 = "��...";
			link.l1.go = "rocur_78";
		break;
		
		case "rocur_78":
            dialog.text = "�������� ��� ����� ����� - ��� ������ �������. ��� ���������?";
			link.l1 = "";
			link.l1.go = "rocur_79";
		break;
		
		case "rocur_79":
            DialogExit();
			sld = characterFromId("Mirabella");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "rocur_80":
            dialog.text = "���� �� ����� ������ ���� ���������. ������ �� ������ ����� ����� ��� ����. �� ������ �������� ������ �����?";
			link.l1 = "���, �� ����. �� � ������� ������ ���� �� ���� - ��� ��� ����������. � ������ �� ������.";
			link.l1.go = "rocur_81";
		break;
		
		case "rocur_81":
            dialog.text = "������ ������ �� �� �������? �� �����! ��� ������ ��� ������ ������� ������, � ������ - ��� ������. ����� ��� ���� �������?";
			link.l1 = "��. ��������, �� ����, ���. ������ �� � ����� ������� ������.";
			link.l1.go = "rocur_82";
			link.l2 = "�� ��������� � ����� �� ������� �������. ���� � ���� ���� ��������, ������ ��� ������� �� ������, � ��� ����������� �� � ���. �� � ����� ����� ������� ��� ��������... ����� � ���� ��������� ����������, ��-��.";
			link.l2.go = "rocur_84";
		break;
		
		case "rocur_82":
            DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto6", "", 5);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "goto", "goto7", "Mtraxx_PasqualeJanKillGirl", 5);
		break;
		
		case "rocur_83":
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
            dialog.text = "��� � ���, ������ ��� ��� ����� ������ ������� �� ������...";
			link.l1 = "���...";
			link.l1.go = "rocur_86";
		break;
		
		case "rocur_84":
            DialogExit();
			sld = characterFromId("Mirabella");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "rocur_85":
            dialog.text = "������ ��, "+pchar.name+". � ����� ���� � ���� ������ �����������? �����, ���� ����. ����� �� ���, ����� ��� �� ��������, ����� �������� �����.";
			link.l1 = "������� - ������� ������.";
			link.l1.go = "rocur_86";
		break;
		
		case "rocur_86":
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Pasquale.Grabbing.Chest")) sTemp = "�������. ������ � ���������, ������ �������, ����� ��������� �� ������� � �����.";
			else sTemp = "������ ������ �������.";
            dialog.text = "��� ���� ������� �����?";
			link.l1 = sTemp;
			link.l1.go = "rocur_87";
		break;
		
		case "rocur_87":
			Log_Info("�� �������� ��� ��������� ��������");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "icollection", 2);
            dialog.text = "� ���� ���� �������. �����, ��� ���� ����. ��� ����� ��� ������� �� ������� �� ������... �������� � ���� ����������� ������.";
			link.l1 = "�������! �� �������, ���!";
			link.l1.go = "rocur_88";
		break;
		
		case "rocur_88":
            dialog.text = "� ������ ����������� ������. ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNightOutHouse");
		break;
		
		case "rocur_89":
            dialog.text = "�����������. ��� ������ ��� ���� � ����. ������ - �����, � ����� ������.";
			link.l1 = "����!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeNightGulf");
		break;
		
		case "rocur_90":
            dialog.text = "��, "+pchar.name+", ������ ����� ��� � ����� �����������. �� ������, ����������� �� ��� �����, �� ����: � ��� ��� ������ ����������.";
			link.l1 = "��� �� ��� �������� � �� ����.";
			link.l1.go = "rocur_91";
		break;
		
		case "rocur_91":
            dialog.text = "���. � ������ �� ��������� �������� � ��������. ������� � ������ ���� ��������� ������.";
			link.l1 = "���... ����� �� ���. �� �� ���� �������� ������� � ���������. � ������ ������������ �������� ������, ����� ���? � ��� � ������� ��� ��������� ������, ��� ����������� �� ����� ������ ������.";
			link.l1.go = "rocur_92";
		break;
		
		case "rocur_92":
            dialog.text = "����� ����������, � ���� ����� �������� �����������, ����� ����� ���� ����?";
			link.l1 = "��... ��������� � �� ���������� �������, �� � ����� ������� ��������. � ��� ������� �� ��������, �������. �� ��������� ���� �����, � ������.";
			link.l1.go = "rocur_93";
		break;
		
		case "rocur_93":
            dialog.text = "� ������ ���� ���� �������?";
			link.l1 = "������ ����� ������. ������ ��������� �����, �� � ��� �������� ��� �����...";
			link.l1.go = "rocur_94";
		break;
		
		case "rocur_94":
            dialog.text = "� ����� ���� ��� ������� � ���� ����? ��� ������ ������ ���, ���������������?";
			link.l1 = "��... ��� ��� ������ ������ ������...";
			link.l1.go = "rocur_95";
		break;
		
		case "rocur_95":
            dialog.text = "� �� ���� ��� ������� �����������, ��� � �������. ���?";
			link.l1 = "��... �� ���� ��� ������� � �� ���� �� ����� � �������� ���������...";
			link.l1.go = "rocur_96";
		break;
		
		case "rocur_96":
            dialog.text = ""+pchar.name+", ������� �� �� ������, ��� ������ ������� ������� �� ���� ������ ������? �������, ���� �� �� ��� ��� ����� ���� ������ ������, �� �� ���� ������ ������� ����? ������� ������, �� ������� ��������� ���, � ����� �� ����� - �������� ����. � ��, ������ ���� �� ����� � �� ���� � �������� ��� �� ����� ������������� �������, ������� �������� �������� ���� � ������ ��������. � �� ����� ������, �������� �������� � ���� � �������� ������ � ����. �� ������ �������� � ���, "+pchar.name+"\n����� �� ������ � ����� �� ������ - �������, ������ ��� ��� � ������ ���� �������� ��������� ������, ��� ���� ������ ������ ��� ��� ���������? ���� ������������ �� ����, ����� �� �� � ��������� �� �������� �������� � �� ������ �������. �� ������� ������ �����, ������ ������ �� �����. ����, ������� ������ � ��������� ��������, �� ������ ���, ��� ��� ������ ����� �������, �����, ���������� � ������ ���������, ������� ������ �����, � ��, �� ��� ��� ����� ������ �� ������� - �������� ���� �� ���\n�������, ����� ������� �� �������, � ������ ������ � ��������, ������� ������ ������ �� ���� �� ������ ���. � ���� �� ��������. � ������ �� ������ �� �������, �� ����, �� ����-���� ���. � ���� ���� �������� ������ � �������� �������. ������ � ���� �������� ���. ����������� �� ������ � ���� ��������������� � ��������� ����������� �������.";
			link.l1 = "�����, ��� ������ ������� �� �� ������ ����... �� � ����� ���� �����, ���! �������, � ���� ��� ��������� �� ������.";
			link.l1.go = "rocur_97";
		break;
		
		case "rocur_97":
            dialog.text = "���������. ���� � ���� ����� ����� � ������� �������� ��� ����� �������. ������� �� ������� - �� ������ ����� ��� ����. �����, ����. ��������� �����!";
			link.l1 = "������ ������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PasqualeAddComplete");
		break;
		
		case "rocur_98":
            dialog.text = ""+pchar.name+", �� ����������, ������ �� ��� ����� ������� �� ��������? ������ ������ ���������... ������ ��� ����. ��!.. ���, �����, ��������...";
			link.l1 = "���...";
			link.l1.go = "rocur_99";
		break;
		
		case "rocur_99":
            DialogExit();
		    LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 10.0);
			sld.lifeday = 0;
			Group_DeleteGroup("RocurSeaGroup");
			AddQuestRecord("Roger_4", "18");
			CloseQuestHeader("Roger_4");
		break;
		
		// ��� ��������
		case "lepricon":
            dialog.text = "�����������, ������� "+GetFullName(pchar)+". ��� �������� � ����� �������! ������ ������, ��� �� ������������ � ������� ������ �����.";
			link.l1 = "������ ���. ��������� � ������, �� ������������ � ���� ����������.";
			link.l1.go = "lepricon_1";
		break;
		
		case "lepricon_1":
            dialog.text = "������� ������ ���� ������� ��������� ���� �������, ���. ��� �� ���� � ������ - ������, ��� ���� ����, ���������� � ������������. ������ � ����� �������, ������� ����� �� ��������������, �� ����� ��� � �������. ��������� ����� ������ �������� � ������� �� �������� ��������, ����� ��� ����������, ���� ���� � �� ����� �� ���� ��������. ��� ��� ����������� ���������, �������� - �������� ��� ��������� ������, ��� ��� �������, ��� ��� ����������� ������ �����\n��� �� ������ ������ ������������ ��������� �� ������ ������, ����� �������� � ���������. ��� ���������� �������������� ������ �� ������ ������� � ������������: ����� ������������ ����������, ��������, ��������, �����������, �������� � ������� ���� ���������: ������� ������ ���������� ��������� �� ����� �� ���������� �������� � �������� �������� ��������.";
			link.l1 = "������, ���. � ����� ���� ����� � ��������. ����� ���������� �� ����.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_MeridaSail");
		break;
		
		case "lepricon_2":
            dialog.text = "��� ������ ��������� - ����� ����������� � �����. ���������� ��� ������� - ����� ������ ������� �� ��������. �� � �����, ��� ������������� - ����� � ���� ����-������ �������� ����� � ������ � �� ��������� �����������. � ��� � ����, ��������� ��������� - ���������, ���� ����� ��� ������������ - ������.";
			link.l1 = "������������! ���, ��� - �� ����!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_MeridaSeekVillage");
		break;
		
		case "lepricon_3":
            dialog.text = "���� �������, �������?";
			link.l1 = "���� ���, ���...";
			link.l1.go = "lepricon_3x";
			if (pchar.questTemp.Mtraxx == "merida_advice")
			{
				link.l1 = "��! � ������� � ������, ������ ��� �������, ����� �� ������ ����� �����������. ����� ��� ���� ��, ��� ����� ������ � ������, �� ���� �� �����: ��� ��������. ������ �����-�� �������� � ����. ������, ��� ����� ����� '������' � ��� �������� ��������. ����������� ����������, ��� ���� �� ������ �� ������, � ���������� ���. � ��� ��� ��� ������ ������, �?!";
				link.l1.go = "lepricon_4";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Merida.Potion") && GetCharacterItem(pchar, "potion3") >= 12)
			{
				link.l2 = "� ������ ������� � ������������.";
				if (GetCharacterItem(pchar, "potion3") > 42) link.l2.go = "lepricon_7";
				else link.l2.go = "lepricon_6";
			}
		break;
		
		case "lepricon_3x":
           DialogExit();
		   npchar.dialog.currentnode = "lepricon_3";
		break;
		
		case "lepricon_4":
            dialog.text = "��. ���, �������� ����� ����������� ���������. ����� �������� ����� ������� ����������, ����� �� �� ������ ����� ����������... ������ ���? �������� �������� �����: �������� � ���������. ���� �� ������� � ��������� ��� ����� - �������, ����� ��� �������� ������ ��� �������. ������ �� ���� ��� � �������� �� ��, ��� �� ������ ������� ��� � ������. �������, ����������� � �������� ��������. �� ������� �� ��������.";
			link.l1 = "���! ��������, ������, �� ������, ��� �� ����� ���-�� ������...";
			link.l1.go = "lepricon_5";
		break;
		
		case "lepricon_5":
            dialog.text = "� ���, ���: �� ���� �����, � ���� �� ����� ����������� � ��������� ������������ ���������. ������� � ������ ������ ����� ����������� ��������� ���� ������ ����, ������� �������� �� ����� ������� � ������ ��������� ����. ��� ��� ���� �� ������, ����� ���� ���� ��������� ��� ���� ���� �� ������ ���, ���������� ����������� �������, ��������� �������� �����������\n� � ��� ���� ������ ����� � ����� �� ��������� ����� - ����� � ������ �������. � ��� ���� ������, ��� ������ � �����... ������� ��� ������� � ������������, � � ������ �� � ��� ������ �����������. �� ����� ����� �� ������, ������� ����� ��� - �� ������ ������, � ����� ������, � �� ����, ��� �� ����� �� ���� �������: ����� ������� �������� �����. ��� ���� � ����� �������� �������� �������� - ���, ��� ����������� ������������.";
			link.l1 = "������. ����������� �����.";
			link.l1.go = "lepricon_5x";
		break;
		
		case "lepricon_5x":
           DialogExit();
		   npchar.dialog.currentnode = "lepricon_3";
		   pchar.questTemp.Mtraxx = "merida_hayamee";
		   pchar.questTemp.Mtraxx.Merida.Women = "true";
		   pchar.questTemp.Mtraxx.Merida.Potion = "true";
		   AddQuestRecord("Roger_5", "8");
		   sld = characterFromId("Hayamee");
		   LAi_CharacterEnableDialog(sld);
		  // LocatorReloadEnterDisable("Shore106", "boat", false); 
		   bQuestDisableMapEnter = false;
		   DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");// �������� � ����
		   SetFunctionTimerCondition("Mtraxx_MeridaPotionLate", 0, 0, 300, false); // ������, ����� �� ����� �����
		break;
		
		case "lepricon_6":
			i = GetCharacterItem(pchar, "potion3");
			RemoveItems(pchar, "potion3", i);
			pchar.questTemp.Mtraxx.Merida.Antidote = i;
            dialog.text = "����� ������. ����� �� ���, ��������� - ��� ������.";
			link.l1 = "�����...";
			link.l1.go = "lepricon_8";
		break;
		
		case "lepricon_7":
			RemoveItems(pchar, "potion3", 42);
			pchar.questTemp.Mtraxx.Merida.Antidote = 42;
            dialog.text = "��� � ��������� ������ ����� ����������. ��������� ������ ���� - ����������.";
			link.l1 = "������...";
			link.l1.go = "lepricon_8";
		break;
		
		case "lepricon_8":
            DialogExit();
		    npchar.dialog.currentnode = "lepricon_3";
			DeleteAttribute(pchar, "questTemp.Mtraxx.Merida.Potion");
		break;
		
		case "lepricon_9":
            dialog.text = "���, ���� ������� - ������ � ������ - �� ���������, ���� �� ���������� �������� �� ����������� �������, � ������� ����-�� � �������� ������� ���� ������ � ������� �����. ���, � ����� �������� � ���� �� �� ������ �� ��������� � ����� ���. � �����, ������, �������, �� ������ ��� ����� ����������� ��� ����. ����� ��������� ����������. �� ������ �� � ����.";
			link.l1 = "�� � ��� � ����!";
			link.l1.go = "exit";
			AddQuestRecord("Roger_5", "19");
			AddDialogExitQuestFunction("Mtraxx_MeridaHayameeFail");
		break;
		
		case "lepricon_10":
            dialog.text = "���, �� ������ - ��� �����������? �� ������� ������� �������� ��������! ���, � ����� �������� � ���� �� �� ������ �� ��������� � ����� ���. � �����, ������, �������, �� ������ ��� ����� ����������� ��� ����. ����� ��������� ����������. �� ������ �� � ����.";
			link.l1 = "�� � ��� � ����!";
			link.l1.go = "exit";
			AddQuestRecord("Roger_5", "20");
			AddDialogExitQuestFunction("Mtraxx_MeridaHayameeFail");
		break;
		
		case "lepricon_11":
            dialog.text = "���, �� �� ������ ���� �� ���� ����� ����� � ����? ��������� �����, ����������, � �����-������! �� ������� ������� �������� ��������! ���, � ����� �������� � ���� �� �� ������ �� ��������� � ����� ���. � �����, ������, �������, �� ������ ��� ����� ����������� ��� ����. ����� ��������� ����������. �� ������ �� � ����.";
			link.l1 = "�� � ��� � ����!";
			link.l1.go = "exit";
			AddQuestRecord("Roger_5", "20");
			AddDialogExitQuestFunction("Mtraxx_MeridaHayameeFail");
		break;
		
		case "lepricon_12":
            dialog.text = "�������, �� ������, �������, �� ��� ��� ����� ���� ���� ���� � �� ����, ���, �������, � ����. ��, ������, ������ ����� � ���� �������������, ��� � � ���, ��� ������ ���� ����. � �����, � ����� �� ����� � ��� �������� �� ���������, � �� ��������� ������ ������ ������ - � �������� � ���������. ������ - ����, � ��� � ���� ������� ������.";
			link.l1 = "��...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_MeridaReturnFail");
		break;
		
		case "lepricon_13":
            dialog.text = "����, ��� � ������� - ����������� ������������. �� ������ �������� ������, �� ��� ��, "+pchar.name+" �����?";
			link.l1 = "��������? � ��... �������, � �� ������ �������. ��, ������ �� ������ ������� ����� � ����� ��������� �� ������ ���������� �������� � ������ �� ����.";
			link.l1.go = "lepricon_14";
		break;
		
		case "lepricon_14":
            dialog.text = "��, ����, ���� ������ ���������, �����. ��������� �� �������. ������, ���� �� ����� ���������\n��� ��� �� ��� ������ ������ �������? � �������� ����: �� ����� ���� ����������� ������ � ��������, ���������� ����� ������ �������, � ������� ��� �����, ��� '������' ��� ��������, ��� � ��������� �� ��������. ���������� �������� ������ �����, �� ���������� �� ��������� ���� � �������� ���� � ���������� � ����� �������, ���� ������� �� �����, �� ���������� ��� ����� � ����� ��������\n������� �������: ���� ������, �� ����� �������, �� �����. � �������� ���� ����� �� ����� � �� ������.";
			link.l1 = "�� ���� ������ �� ����������, ����?";
			link.l1.go = "lepricon_15";
		break;
		
		case "lepricon_15":
            dialog.text = "������ ������. � ��� �, ��-������, ����� ��� ������ �� ������ ��������� ����� ���� ��������? �� � �������� ������ ���: ���� ���� ������ ��������� ������, � ������ ��������... ��� ������, ������ ���������: ����������� �������, �� ��������� ���� ����� � ������, � � ����� ������� ����� ���� ���������, ������� � �������...";
			link.l1 = "���������? ���-�� �� '����������' ������ ������ �������, ������� �������! ��� ��, ���� �� ������ �� �����?!";
			link.l1.go = "lepricon_16";
		break;
		
		case "lepricon_16":
            dialog.text = "� ������� �� ���, �� ���� ������ �� ����������������. � �� �����. � ���� ���� ��� ������� - ����� ��������� ����, � ����������� ����� ��������. � �������� � ����� ������ ����� �����: � �������, ������� �� ��������� �������� � ����� �����. ������� �������, ������� ��, ����������� ���������, ������ ����, ��������� ���� ������ ������ � ��������� � �������, � � ������� ��� �� ��� � ��� �����\n�� � �� �����, ���� � ���������� �������� � � ��� ���� ������ �� ���� �������� - �� ��� ��� �����.";
			link.l1 = "�� � ����� ����� ������ ���� ����, ��������. ������ ������ �����, ���������� ���� ����� �����. ����� ��� ���� ��� ������ ����?";
			link.l1.go = "lepricon_17";
		break;
		
		case "lepricon_17":
            dialog.text = "���� � ����� �����������, �����: �� ������� ��� �� ��������. ������ ��� �� ��������. �� ������ ������, ����������� ����, �������� ���� � ������ ������, ������������ ��� ������� ������� ��������� ������� ���������� ��� � ������������ ���� ������� �������\n����� ����, � ���� ����� ������� �������. ������� �� �������, ��� ����� ���������� ����� ������� � ��������� ������� ���� ���� ����� ���������� ��������? ������ ����� ����� �� ����������, ��� �� ���.";
			link.l1 = "������ �������! ����� ��������, ��� �� ��� �����! ������ �������!";
			link.l1.go = "lepricon_18";
		break;
		
		case "lepricon_18":
            dialog.text = "�������, �� ��� ���������. ������ ���� ����������� ��� �������. ����� � ��� ���� ��� ���������.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionLepriconFight");
		break;
		
		// ������ - ��������� � ������
		case "tagofa":
            dialog.text = "������ ������������ ����, ��� ����. �� ������, ����� � ������� ���� ���� � ���������� ��������� � �����?";
			link.l1 = "������ ���. ������, �� ������ ������ ��� ����, � ������� �� ����� �������������...";
			link.l1.go = "tagofa_1";
		break;
		
		case "tagofa_1":
            dialog.text = "������ ����� ����������� ����� ���� � �������... ������� ����� ������ ��� ��������� ������ �� ����. ��� ����������� �����. � ��� ��� ����?";
			link.l1 = "� � ���? �� �� ����� �� �����, ��� �����...";
			link.l1.go = "tagofa_2";
		break;
		
		case "tagofa_2":
            dialog.text = "���� ������� ���������, ����� ����, � ��, ��� ���� - ����� ������ ��� ����� ����. ����� ������� �����. �����, ��� �� ����� ��������. � �������, ����� ���� ����������� ��� ���� ����.";
			link.l1 = "���... ��� ����������� ����� ������. ������� �� ������� ���.";
			link.l1.go = "tagofa_3";
		break;
		
		case "tagofa_3":
            dialog.text = "��� �������� ��. ��, �����, ������ �� ������ ���� �������� ������� �������������, ��� ��� ����� ���������� ��������� �����.";
			link.l1 = "���, ������, �� ����. ������, ������� ��� � ���� ���� - �������, ��� ��������?";
			link.l1.go = "tagofa_4";
		break;
		
		case "tagofa_4":
            dialog.text = "��������. ������ �� ����.";
			link.l1 = "...";
			link.l1.go = "tagofa_5";
		break;
		
		case "tagofa_5":
           DialogExit();
		   npchar.dialog.currentnode = "tagofa_6";
		   LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "Mtraxx_MeridaGotoRiver", 5.0);
		break;
		
		case "tagofa_6":
            dialog.text = "��� ����. ������ �� ������ ���� ����. �������� �����, � �� ����� ����������.";
			link.l1 = "����, ������. � �����, ����� ��� ����� ������.";
			link.l1.go = "tagofa_7";
		break;
		
		case "tagofa_7":
            DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.dialog.currentnode = "tagofa_8";
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			pchar.questTemp.Mtraxx = "merida_boats";
			pchar.questTemp.Mtraxx.Boats = "true";
			chrDisableReloadToLocation = false;
			DoQuestCheckDelay("TalkSelf_Quest", 2.0);
			// ��������� - ������
			sld = characterFromId("Lepricon");
			sld.dialog.currentnode = "lepricon_3";
			LAi_SetWarriorType(sld);
			LAi_warrior_DialogEnable(sld, true);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			SetFunctionTimerCondition("Mtraxx_MeridaBoatLate", 0, 0, 10, false); // ������, ����� �� ����� �����
		break;
		
		case "tagofa_8":
            dialog.text = "����� ������, ����� �����?";
			link.l1 = "��. ��� ���� ������ � ��� ����������� � ����� ������ � ��������.";
			link.l1.go = "tagofa_9";
		break;
		
		case "tagofa_9":
            dialog.text = "����� ������. ������ ������ �� ���� � ������ �����. ������ ������� ����.";
			link.l1 = "";
			link.l1.go = "tagofa_10";
		break;
		
		case "tagofa_10":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2", "none", "", "", "Mtraxx_MeridaRiverTrip", -1);
			chrDisableReloadToLocation = true;
		break;
		
		case "tagofa_11":
            dialog.text = "������ ���� �������. �� ���������� ��������� �������� ������. ������ ����� ��� ����� - ����� ��� ����� ��������� �� ���. �� ����������. �� �������� �� ���� ���, � ������� �������� ������� ������, �� ��� ���� �� ��������. ���� ���� �����������.";
			link.l1 = "�� ���������. �� ������ ���� ��������, ���� ��� ������ ��������� �������� ���� ������������ ����������.";
			link.l1.go = "tagofa_12";
		break;
		
		case "tagofa_12":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			pchar.quest.mtraxx_merida_warning.win_condition.l1 = "locator";
			pchar.quest.mtraxx_merida_warning.win_condition.l1.location = "Serpentine2";
			pchar.quest.mtraxx_merida_warning.win_condition.l1.locator_group = "quest";
			pchar.quest.mtraxx_merida_warning.win_condition.l1.locator = "detector1";
			pchar.quest.mtraxx_merida_warning.function = "Mtraxx_MeridaWarning";
			chrDisableReloadToLocation = false;
		break;
		
		case "tagofa_13":
            dialog.text = "";
			link.l1 = "��! ������! �������� ���� - ��� ��� ����� ����� ������� ������? �����-�� ��������� ���������.";
			link.l1.go = "tagofa_14";
		break;
		
		case "tagofa_14":
            DialogExit();
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			ChangeCharacterAddressGroup(npchar, "Serpentine2", "goto", "goto5");
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Mtraxx_MeridaWarning", -1);
		break;
		
		case "tagofa_15":
            dialog.text = "��� ���� �������� ������. ��������������. ��������� - �� ������ ������. ������� ��� ��� ��������.";
			link.l1 = "� ��� �����, ���� �� ������? ������� �� ���?";
			link.l1.go = "tagofa_16";
		break;
		
		case "tagofa_16":
            dialog.text = "��, ����� �����. �������. ����� ��������� ��� �� �������� - ������, �� ������ ���������. �� ���� ���������.";
			link.l1 = "������� �� ���� ����. �� ���� ������. � ���� ������� - ������� �� �����. ����-��! ������ ��� �������! ������������� � ���! ����������� �������� �� ��������!";
			link.l1.go = "tagofa_17";
		break;
		
		case "tagofa_17":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			pchar.quest.mtraxx_merida_capong.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_capong.win_condition.l1.location = "Merida_jungle_01";
			pchar.quest.mtraxx_merida_capong.function = "Mtraxx_MeridaPrepareCapongAttack";
		break;
		
		case "tagofa_18":
                                       LocatorReloadEnterDisable("Merida_jungle_01", "reload1_back", false);
                                       LocatorReloadEnterDisable("Merida_jungle_01", "reload2_back", false);
            dialog.text = "����� ����� � ��� ���� ��������� ��������. �� � ������ ������� �����. ��������� ����� ��� ������. �� ��� ������� ������ ����� ������� � ������. ������ �� ������� �������. �������� ������ - � �� �� �����. ������ � �������� �� ������. � ���� ����� ��� � ��������.";
			link.l1 = "������. �������!";
			link.l1.go = "tagofa_19";
		break;
		
		case "tagofa_19":
                                       DialogExit();
	                    chrDisableReloadToLocation = false;
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			pchar.quest.mtraxx_merida_exittown.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_exittown.win_condition.l1.location = "Merida_ExitTown";
			pchar.quest.mtraxx_merida_exittown.function = "Mtraxx_MeridaExitTown";
			Mtraxx_MeridaCheckOurWarriors();
			AddQuestRecord("Roger_5", "15");
		break;
		
		case "tagofa_20":
            dialog.text = "��� �� � ��������� �����, ����� �����. ������ �������� ���� ��������.";
			link.l1 = "�������������, ������. �� ������� ��������� � ������������ �������.";
			link.l1.go = "tagofa_21";
		break;
		
		case "tagofa_21":
            dialog.text = "������ ���� ����. ������ ����� ���� ����. ������, ��� ����.";
			link.l1 = "�����, ��� ����. ������ �������!";
			link.l1.go = "tagofa_22";
		break;
		
		case "tagofa_22":
            DialogExit();
			chrDisableReloadToLocation = false;
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			pchar.quest.mtraxx_merida_final.win_condition.l1 = "location";
			pchar.quest.mtraxx_merida_final.win_condition.l1.location = "Shore106";
			pchar.quest.mtraxx_merida_final.function = "Mtraxx_MeridaFinal";
			ChangeIndianRelation(7.0);
		break;
		
		// �������� � ������
		case "merida_guard":
            dialog.text = "��! ��� �� ����� � ��� ��� ����� �����?";
			link.l1 = "��� ����� ������� � ������ � ������������ � ����� ������������, ��� ��� ��� � ��� ������ ����...";
			link.l1.go = "merida_guard_1";
		break;
		
		case "merida_guard_1":
            dialog.text = "�� �� ������� ������� � ������. ������� ������!";
			link.l1 = "��������, �� �� ��� ���� ���� ����� ������ ������� �� ���� ����� �������� ����� � ����������� ����� ����� �������, ����� ������ ������������ � ����. ��������: � ���� �������� � ����� ����������� ���������! � �����, ��������, ��� ������� ��������� � �������.";
			link.l1.go = "merida_guard_2";
		break;
		
		case "merida_guard_2":
            dialog.text = "�� ��������� ���, ������?";
			link.l1 = "��� �� ���������? ��, �������. ���� �� �� ������� ��, �� ��� ������, ������ �����, �� ������� ��� �����.";
			link.l1.go = "merida_guard_3";
		break;
		
		case "merida_guard_3":
            dialog.text = "���� ������� �� ����� � ������, ��������� �����! �������, ���� � �����!";
			link.l1 = "...";
			link.l1.go = "merida_guard_4";
		break;
		
		case "merida_guard_4":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2", "none", "", "", "", 10.0);
			DoQuestFunctionDelay("Mtraxx_MeridaHouseGuards", 5.0);
		break;
		
		// ��� ������
		case "merida_head":
            dialog.text = "��������� �������!..";
			link.l1 = "������� ��� ��������, ������. �� ����� ���������� ������ ������ �����, �� ��� ��������� ������ �������� ������ ������� ��������... ��� ��� ��� ��, ��� ��������� �� ������ ������, � ������������ ������� ������ ��� ����.";
			link.l1.go = "merida_head_1";
		break;
		
		case "merida_head_1":
            dialog.text = "��� ��� �����, �������? ��� ����� ���, ���� ����� ����� �� �����������, �� �� �������-�����������, �� �� ����������. � ��� ��� �� ������, �� �������, �� ������ �������.";
			link.l1 = "����� ��� �� �� ���������� ��������� ���� ����� �������, ���� �����������? �� � ���� ������ �� ���������� ����������� ����� ���������.";
			link.l1.go = "merida_head_2";
		break;
		
		case "merida_head_2":
            dialog.text = "��� ������ ������ ��������� ����� ��� � �����, ����� �������� ��� �����.";
			link.l1 = "�� ��? �������, �������� �������������������. � ����, ��� �� ����� � ��������� ����� ������� ��������� � ������. �� �������������, ���������. �� ������. � ��� �������� ���������� � ���� ������ ���������.";
			link.l1.go = "merida_head_3";
		break;
		
		case "merida_head_3":
            dialog.text = "��������? �����? ��� �� �����, ��� ������ ���������! �������� �������� ������ �� ����� ������, � �����...";
			link.l1 = "������ �����, ��������� ������! ��, �������, ��� �� �����, � ��� ������ ����. ��� �� ������� ��� �����, ��� ��� �������� ������� ����������� � ���� ����� � �����, � ���������� � ����� ������� ��������� ��������� �� ������ �������. � � ����� ����� �������� ������: �������� ���� ��������� ������, ������ ������ ����� ��������... � ��� ����� �������� ����������� �����.";
			link.l1.go = "merida_head_4";
		break;
		
		case "merida_head_4":
            dialog.text = "";
			link.l1 = "���������? ��-�� ��. ��? ��� �����?";
			link.l1.go = "merida_head_5";
		break;
		
		case "merida_head_5":
            dialog.text = "��� ��������� - ���, ��� ���� � ������� ������. �� �������� �� �� ���� ���, ����� ����� � �����, ��������� �� �������...";
			link.l1 = "�? �� ��������� ���� �����������? ���� �����. � ������ ������������ - �� ����� �� ������, �� �� �������. �� ����.";
			link.l1.go = "merida_head_6";
		break;
		
		case "merida_head_6":
            dialog.text = "��� ��� ��� ������ �� ������, ������� �������, ��� ��� ����� � �������� ���, ��������...";
			link.l1 = "��� ���� ����������� - � � �������� ������ �������� �� ��������.";
			link.l1.go = "merida_head_7";
		break;
		
		case "merida_head_7":
            dialog.text = "� ����� ��� �����, ���� �� ����������� �� ������� ����� � ��� �����, ���� �� ��� �� �����.";
			link.l1 = "� ��� ������ ���� - ���� �� ���������� ���� �����. ���� ���������, � �� ������ ������.";
			link.l1.go = "merida_head_8";
		break;
		
		case "merida_head_8":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "goto", "goto2", "Mtraxx_MeridaOpenChest", -1);
		break;
		
		case "merida_head_9":
            dialog.text = "��������� ���� �������� ������ � �������, ��� �� ������� ����� ����� �� ������.";
			link.l1 = "�� ��������? �������� ���� ��� ����������, ���� ����� � ������ �� ������... ���, ���, ��������, ��� ��� � ������� � ����.";
			link.l1.go = "merida_head_10";
		break;
		
		case "merida_head_10":
            DialogExit();
			sld = characterFromId("Mrt_Rocur");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "goto", "goto2", "Mtraxx_MeridaGiveJewelry", -1);
		break;
		
		case "merida_head_sleep":
            dialog.text = "�� ������ ����� �������� �����, ����� ����, ��� �������� �����. ����� �� �������, � ���� ������� �������� ���� ����. �� ���� � ������� �����. �������, ��� ����� ���, ������� ���� ����, ����� ����� �� ������.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep2");
		break;
		
		// ������� ������ �����
		case "kittycap":
            dialog.text = TimeGreeting()+", ���������. ��� ������ ������ ������?";
			link.l1 = "� �� �������. ��� ��������� ������� ���� ����� �� ����������. �� �����?";
			link.l1.go = "kittycap_1";
		break;
		
		case "kittycap_1":
            dialog.text = "�� �������-��! ��, ��� ������� ������ ���������� ����� � ����.";
			link.l1 = "�������. ����� ������. �� ������������!";
			link.l1.go = "kittycap_2";
		break;
		
		case "kittycap_2":
		    DialogExit();
            LAi_CharacterDisableDialog(npchar);
			Group_DelCharacter("Mtr_Kitty", "Mtr_KittyCap");
			SetCharacterRemovable(npchar, false);
			npchar.CompanionEnemyEnable = false; //������ ������
			LAi_SetImmortal(npchar, false);
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.loyality = MAX_LOYALITY;
		    pchar.quest.mtraxx_ignasio_sail.win_condition.l1 = "location";
			pchar.quest.mtraxx_ignasio_sail.win_condition.l1.location = "Bridgetown_town";
			pchar.quest.mtraxx_ignasio_sail.function = "Mtraxx_IgnasioArrive";
			SetFunctionTimerCondition("Mtraxx_IgnasioTimeOver", 0, 0, 30, false);
			pchar.quest.mtraxx_ignasio_sinkkitty.win_condition.l1 = "NPC_Death";
			pchar.quest.mtraxx_ignasio_sinkkitty.win_condition.l1.character = "Mtr_KittyCap";
			pchar.quest.mtraxx_ignasio_sinkkitty.function = "Mtraxx_IgnasioKittySink";
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
		break;
		
		case "kittycap_3":
            dialog.text = "������� �� ������, �������! ��� ����� ������� � ���������� ����, ��� �� ������ �����.";
			link.l1 = "�� �� ���, ��������. ��� ����� �������� ��������. �����!";
			link.l1.go = "kittycap_4";
		break;
		
		case "kittycap_4":
            DialogExit();
			npchar.lifeday = 0;
			RemoveCharacterCompanion(pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 30.0);
			Mtraxx_IgnasioCreateMarko();
			AddCharacterExpToSkill(pchar, "Sailing", 200);
		break;
		
		// ������� �����
		case "ignasio":
            dialog.text = "����������� ������� ��������! ��������� ������������� - ����� �� ������ ������ ������� �����, �������� � ������� ������� '������'.";
			link.l1 = TimeGreeting()+", ���������. ������� "+GetFullName(pchar)+" � ����� �������. ��� ���� ���� �������?";
			link.l1.go = "ignasio_1";
		break;
		
		case "ignasio_1":
            dialog.text = "�, � ��� ����� �����, ����� "+GetFullName(pchar)+". ����� � �����... ������������ � ������������ �� ��� ���������� �� ���� � ����� ������ ������ ����������. � � �����, ��� ��� �� �������������� ��� �����������.";
			link.l1 = "����� �����������?";
			link.l1.go = "ignasio_2";
		break;
		
		case "ignasio_2":
            dialog.text = "������� ������ � �������, � �� ������� ���� � ��� ��� ��������. �������� ���-�� ������� �����...";
			link.l1 = "������... ������!";
			link.l1.go = "ignasio_3";
		break;
		
		case "ignasio_3":
            DialogExit();
			FreeSitLocator("Bridgetown_tavern", "sit_front1");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "Bridgetown_tavern", "sit", "sit_front1", "Mtraxx_IgnasioInTavern", -1);
		break;
		
		case "ignasio_4":
			LAi_SetSitType(pchar);
            dialog.text = "�� ��������, �������?";
			link.l1 = "��� ����������!";
			link.l1.go = "ignasio_5";
		break;
		
		case "ignasio_5":
			LAi_Fade("", "");
            dialog.text = "���, � ����� � ������ �� ���������� ��� �����...";
			link.l1 = "� �� ������ ������ ����, ��-��. � ��� �� ������ ����������, ������?";
			link.l1.go = "ignasio_6";
		break;
		
		case "ignasio_6":
            dialog.text = "��� �������� ���� �������������, �����. �������, �� � ����� � �������������� ����� ������� � ����������, ������� �������� �������� ������?";
			link.l1 = "��� ��� � �����. ���� ������������ �������������� � ���.";
			link.l1.go = "ignasio_7";
		break;
		
		case "ignasio_7":
            dialog.text = "����� ��������� ����� �� ��������. ������� ���������� �������, � ������� ��������������� ������� � ���� �����. �� �� - ��������� ���� �� ���� � ��� �� ���-����, ��� ��� � ��� ����� ��������� �� ����... �� ����, ��� ������ ���� ��� �����, ������ ���� ����� ������ ��������...";
			link.l1 = "�����. � �������� � �� ����, �� �������.";
			link.l1.go = "ignasio_8";
		break;
		
		case "ignasio_8":
            dialog.text = "�������, �� ��� ���� �����! ����, � ����: ����� ������� � ���������� ��������� ���� ��������� ����������� ��������, �� ������������ �� ������. � �������� ���, � �� ������ - ������ � ��������, ���� ���������� �������� ����������� ������� � �������� ��� ���������� ������� ���� � ���������� �������. ������, ��������� �������, ��� ��� ���� �������� �������� ������ ��, ������ ��� �� ���, ��-��\n���� ���� ����� ��� ����� ����� �������, ������� ������������ ��������� �������. ��������� �������� ��������������� �� ���� ���� ����. ������� ������� ����-�����, ��� ��� �������� ��� �������. �� ��� ���� ������� � ���, ��� ����� �������� ���� ������� ��������� ������� ��������, ������� �������! ��������� ������ �������� ��������, ����� ������� ��������� �� ����, �������, ��� � ������������...";
			link.l1 = "� ��� �������� ���������� �� � ����, ���?";
			link.l1.go = "ignasio_9";
		break;
		
		case "ignasio_9":
            dialog.text = "� �����, �������. ������ ��� ���� ������� �� �� �����, � ��� �� ���� � ���� - ������ ����. �� ���, ��������? ������� � ���� ��������, ������� �� ����� ����, �� � ��� � �� ������ ��� �� �������. ���� ����������� ����... ������� ��������.";
			link.l1 = "������� � ��� �������?";
			link.l1.go = "ignasio_10";
		break;
		
		case "ignasio_10":
            dialog.text = "����������, ���� �� ������ ������ ��� ������� � ���������� � ���� ����������.";
			link.l1 = "����� ���������� ������������ � �������, ������� ������� �����, � ��������� ������. ����� ������ �������������� �������?";
			link.l1.go = "ignasio_11";
		break;
		
		case "ignasio_11":
            dialog.text = "12 �������� 40 ����� �������� ������, 64 ������� 11 ����� �������� �������. ���������?";
			if (CheckAttribute(pchar, "questTemp.HWIC.Isladecoche")) link.l1 = "���! ������... ��, ��������.";
			else link.l1 = "��, ��������.";
			link.l1.go = "ignasio_12";
		break;
		
		case "ignasio_12":
            dialog.text = "� ����������� �� ���� '������'. ��� ���, �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioAddMarko");
		break;
		
		case "ignasio_13":
            dialog.text = "������ ���� �������, ��, �������? ��, ������ ����� ��������: ����� �������. �������� ��� � ���� �����, �������� - ���.";
			link.l1 = "�������...";
			link.l1.go = "ignasio_14";
		break;
		
		case "ignasio_14":
			LAi_Fade("", "");
			WaitDate("", 0, 0, 0, 3, 10); 
			pchar.questTemp.Mtraxx.Silver = GetSquadronGoods(pchar, GOOD_SILVER)-sti(pchar.questTemp.Mtraxx.Silver);
			pchar.questTemp.Mtraxx.Mahogany = GetSquadronGoods(pchar, GOOD_MAHOGANY)-sti(pchar.questTemp.Mtraxx.Mahogany);
			if (sti(pchar.questTemp.Mtraxx.Silver) < 100)
			{
				dialog.text = "�������, ��������: ��� ���? ��� ���� �������? �� ������� ���� �����?";
				if (sti(pchar.questTemp.Mtraxx.Mahogany) < 200) 
				{
					link.l1 = "�-�-�-�...";
					link.l1.go = "ignasio_15_1";
				}
				else
				{
					link.l1 = "� �������� �����-�� ������ �����, �� ���� �������� ������ ������� ���������. ������� ���.";
					link.l1.go = "ignasio_15_11";
				}
				break;
			}
			if (sti(pchar.questTemp.Mtraxx.Silver) < 300 && sti(pchar.questTemp.Mtraxx.Silver) > 100)
			{
				dialog.text = "���... �������� ���-��. � �����, ����� ������...";
				link.l1 = "�� �� ������� ����������.";
				link.l1.go = "ignasio_15_2";
				break;
			}
			if (sti(pchar.questTemp.Mtraxx.Silver) < 700 && sti(pchar.questTemp.Mtraxx.Silver) > 300)
			{
				dialog.text = "�������, �������... ���� � �����, ��� �������� ������ �����.";
				link.l1 = "�� �� ������� ����������.";
				link.l1.go = "ignasio_15_3";
				break;
			}
            dialog.text = "������� ������, �����. ������ ��� ��������� ������ �������������...";
			link.l1 = "�� ���� � ���� �� �����������, �������.";
			link.l1.go = "ignasio_15_4";
		break;
		
		case "ignasio_15_1":
			dialog.text = "������, � ��� ��������� �������� � �������. ��� � � ���� ��������. ������! ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioEscape");
		break;
		
		case "ignasio_15_11":
			RemoveCharacterGoods(pchar, GOOD_MAHOGANY, makeint(sti(pchar.questTemp.Mtraxx.Mahogany)/2));
			dialog.text = "� ������ ������ � �� ��������. � �������� ���� ���� ������ ����... ������! � ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioEscape");
		break;
		
		case "ignasio_15_2":
			RemoveCharacterGoods(pchar, GOOD_SILVER, makeint(sti(pchar.questTemp.Mtraxx.Silver)/2));
			RemoveCharacterGoods(pchar, GOOD_MAHOGANY, makeint(sti(pchar.questTemp.Mtraxx.Mahogany)/2));
            dialog.text = "�����, ��� ������, �� ������. ����������.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioEscape");
		break;
		
		case "ignasio_15_3":
            RemoveCharacterGoods(pchar, GOOD_SILVER, makeint(sti(pchar.questTemp.Mtraxx.Silver)/2));
			RemoveCharacterGoods(pchar, GOOD_MAHOGANY, makeint(sti(pchar.questTemp.Mtraxx.Mahogany)/2));
            dialog.text = "�����, ��� ������, �� ������. ����������. � ����� ������, ������ ���� ��������, ��-��.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioEscape");
		break;
		
		case "ignasio_15_4":
			RemoveCharacterGoods(pchar, GOOD_SILVER, makeint(sti(pchar.questTemp.Mtraxx.Silver)/2));
			RemoveCharacterGoods(pchar, GOOD_MAHOGANY, makeint(sti(pchar.questTemp.Mtraxx.Mahogany)/2));
            dialog.text = "������������ � ��� ���������� ����������. ��������, �� � ��������� ��� �������, �������!";
			link.l1 = "��� ������� ������ ������ - �� �������� ������� ����, ��-��...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioEscape");
		break;
		
		case "ignasio_boarding":
            dialog.text = "�������, ��� �� ��������� �������, ��, �������?";
			link.l1 = "�� �� �����, ����� ����� �� ��������. �� ����� ������ �������, �� ��������. ����� - �� ���������. �� � �� ����� ����� ���� ������, ���������� �� ����� ������� �� ���������, ���� �������� �����... �� ��������, �������, � � ��������� ��������� ���� �� ���� ���. �� �� ������ ��������� ���� ������...";
			link.l1.go = "ignasio_boarding_1";
		break;
		
		case "ignasio_boarding_1":
            dialog.text = "���� ��������� - ��� �� ����� ����������� ����?";
			link.l1 = "����������. �������� ���� � ����, � ����� ���������� � ����������� ����� �������� � ������...";
			link.l1.go = "ignasio_boarding_2";
		break;
		
		case "ignasio_boarding_2":
            dialog.text = RandSwear()+" ����� � �� ������... ���� �� ������: �������� ����� ������, �� ���� ���� �������� �������, � ����� ��� �� ����� �����... � ��� �������� ������������� � ����, ��� ��� ������ - ���� ����� �� �����. � � �����.";
			link.l1 = "������������� ��������?";
			link.l1.go = "ignasio_boarding_3";
		break;
		
		case "ignasio_boarding_3":
            dialog.text = "����������� ������� � ���. ���������!";
			link.l1 = "...";
			link.l1.go = "ignasio_boarding_4";
		break;
		
		case "ignasio_boarding_4":
            DialogExit();
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "spy_sailor":
            dialog.text = "�������! �������! �������, �� ����, ������! ����� �� ��� �������� ������ ��������� �������!";
			link.l1 = RandSwear()+"����� ��������� �������... ��� ����� ��� ��, ��� � �������. ������� �������� � ��� �� �������, �� ���������� � �����?";
			link.l1.go = "spy_sailor_1";
		break;
		
		case "spy_sailor_1":
            dialog.text = "��, �������. ��� �������. ������� - ������� ������, ��������� ��� - ������ � ������.";
			link.l1 = "��� �� ����! �����, ��� ������ ��������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_IgnasioOurEscape");
		break;
		
		// �����-����� � ����� �����-�����
		case "grot_canib":
            dialog.text = "����! ��������� ������� ������� � ��� ���! ����� ���! ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_WolfreekGrotFight");
		break;
		
		// ������ � ������ ������
		case "cave_bandit":
            dialog.text = "��! ��� �� ��� ��������? �-�, ����� ����� ���������� ����� �������? ��, �����, ������ �� ���� �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_WolfreekCaveFight");
		break;
		
		case "carpenter":
            dialog.text = "��! � �� ������ ����! ��� ������� �������� �� ����� - ���� ������, "+RandSwear()+"";
			link.l1 = "�� �����. �� ������ ���� ����� ��������� �� �� �������, ��������, � ���� ������ ������������ ������ - �� ��� ���������. ��� ��� ����� ����� ���������.";
			link.l1.go = "carpenter_1";
		break;
		
		case "carpenter_1":
            dialog.text = "�� �������, ��� ��? �������!";
			link.l1 = "� ������� "+GetFullName(pchar)+". � ��, ��������, ��������� ����� ������ ������, ���� �� � ��������?";
			link.l1.go = "carpenter_2";
		break;
		
		case "carpenter_2":
            dialog.text = "��� ���� ����� ����, ������� "+GetFullName(pchar)+"?! �� ������ � ����� �� ����������!";
			link.l1 = "��� ���� ���? � ���� �����, � ��� ������������.";
			link.l1.go = "carpenter_3";
		break;
		
		case "carpenter_3":
            dialog.text = "������ ������ ��� ���.";
			link.l1 = "����, ������ ������, �� �� � ����� ������������. ��� � ���� ������ ��������. � ������� ������ ���� ���. ���������� ������� ���� '�����' � ������� ���������, � ��� ������� ��������...";
			link.l1.go = "carpenter_4";
		break;
		
		case "carpenter_4":
            dialog.text = RandSwear()+" ��������... ����, ������ ��� �����, ��� �� �� �����?";
			link.l1 = "� ���� ������� ������ ������ ������� ��������! �� �������� ���-����� ������� �� ����� ������ '�����'. ��������� ������� � � ����� ���� ������ � ���... ����.";
			link.l1.go = "carpenter_5";
		break;
		
		case "carpenter_5":
            dialog.text = "���! �� �� ������� �� ������: ����� �� ���� �������, �� ������ �� ��������� ������?";
			link.l1 = "����� �� ����, ��������. ����� �����, ��� � ������ ������ ���������� ������� ����������, ��������� �� ���� ��������� �����. �� ��� ���������� ������� ������ �� �����, ������ - ��������� � ������ �����. � ������, ��� ��� ���, � ����� �������. ��������� ��� ��� �� ����� - ��� ����� ���������� ������� �����...";
			link.l1.go = "carpenter_6";
		break;
		
		case "carpenter_6":
            dialog.text = "��! ��������, � ���� ������: �� �, �� ���-���� �� �������, ������� �� ����� �������� ������. �� �����, �� ���-���� ���. � ���������� �� ���� � ��������� ���� ������ ��� �����.";
			link.l1 = "������, �������� �� �������� � ����� �������. ������� - ��������. ��� �� ������� ���� �����, ��� ��� �������� �����? � ��� ��� ������, ������, ���� ����������� - � �������� ���� ���� ������ � �������, � �� ������ ��������� ��������� ���� �����.";
			link.l1.go = "carpenter_7";
		break;
		
		case "carpenter_7":
            dialog.text = "������ ��� �������, �� �������� � ����� � �� ������ ����� �����, � ����� � ����!";
			link.l1 = "� �����? � ��� ��� ������ ��������, ����� �� ���� �� ������. ���� ���� � ���� - �� ������ ����������� ����� � ������ ����� ��������� �����... �����, ����� ����, �� ����� �� ���� �������!";
			link.l1.go = "carpenter_8";
		break;
		
		case "carpenter_8":
            dialog.text = "� ���� ���� �����������?";
			link.l1 = "��, ����. ������ �� �����, ������, � ������� ����� �����. � ������� ����, ��� ������ �� ��� �� ����. ������ - ��������� ��� �������, �� ������ - ���� ������� � ������� � �������� � ���������� �����.";
			link.l1.go = "carpenter_9";
		break;
		
		case "carpenter_9":
            dialog.text = "��������� ����� ����� ������ ������!";
			link.l1 = "�������! ��� �����, ��� �� � ���� �� ��� �� ������ � ������.";
			link.l1.go = "carpenter_10";
		break;
		
		case "carpenter_10":
            DialogExit();
			npchar.dialog.currentnode = "carpenter_11";
			LAi_SetActorType(npchar);
			LAi_ActorDialog(npchar, pchar, "", -1, 0);
			for (i=1; i<=2; i++) // 
			{
				sld = CharacterFromID("Islamona_fort_pirate_"+i);
				LAi_SetActorType(sld);
				LAi_ActorDialog(sld, pchar, "", -1, 0);
			}
		break;
		
		case "carpenter_11":
            dialog.text = "�������, �������, �� �������� ���� ��������.";
			link.l1 = "� ������ ����� �����. ������� ��� ��������?";
			link.l1.go = "carpenter_12";
		break;
		
		case "carpenter_12":
            dialog.text = "��� ����� �����. ����. ��������� ������� � ��������, ����� ������ ��������� ���. � ������� ��, �� ��� �� ���������...";
			link.l1 = "����...";
			link.l1.go = "carpenter_13";
		break;
		
		case "carpenter_13":
            dialog.text = "�������� ������� � �����. �� ��� ������ ��������� �� ��������. '�����' ����� ������ ���� ���������. �� �����������... ������ �����.";
			link.l1 = "����������� ����, ��� � ������� �������� �������� ������ ��������. ��� �� ��� ������� ��?";
			link.l1.go = "carpenter_14";
		break;
		
		case "carpenter_14":
            dialog.text = "��� � ��� ������ - ����� �� ����� ��� ��������. ���� ��� ����: �������� �� ��������� ������, ��� ������ ������� � ������ � ������, � �������� ������� ������, � ���� ���� ������ �������� ���. ����� �� �� ������� ���������� �� ���... ���� ����������, �� ������ �� �����. �������, � �� ����, ��� �� ������ ���� ���������. ������ �������� ���� �������.";
			link.l1 = "��� � � ��������� �������. ��� ��� ���������?";
			link.l1.go = "carpenter_15";
		break;
		
		case "carpenter_15":
            dialog.text = "�� ���������� �����. ������������ ����������� �������� ���.";
			link.l1 = "������. ��� �� ��� ���������?";
			link.l1.go = "carpenter_16";
		break;
		
		case "carpenter_16":
            dialog.text = "� �������, � ��� ���� - ��� ���������. �� ���������� � ������������� '�����' ����� �������. �� ������ ����������� � ����� �������.";
			link.l1 = "�������. �� ������� �� ������, ����������� ������� �����. � ������ �������� ��� ����� � �������, ������, � ������ �� ������� �� �������. � ��������� � �������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_WolfreekInFort");
		break;
		
		case "carpenter_17":
            dialog.text = "����� �����-�� �������, ���?";
			if (CheckAttribute(pchar, "questTemp.Mtraxx.WolfreekGord"))
			{
				link.l1 = "��. ��������� ������ �������� �������. ������� �� �� ��������. �� ���� �� �����������!";
				link.l1.go = "carpenter_18";
				break;
			}
			link.l2 = "������, �� � ���� ���� ����� ��������������� ��� �����?";
			link.l2.go = "repair";
			link.l3 = "������, � ���� �������� �� ������� ���� �� ����� ��������.";
			if (CheckAttribute(npchar, "portman.info")) link.l3.go = "shipstock";
			else link.l3.go = "shipstock_info";
			if (sti(npchar.portman > 0))
			{
				link.l4 = "������, � ���� ������� ���� ������� �������.";
				link.l4.go = "shipstockreturn";
			}
			if (!CheckAttribute(npchar, "storadge"))
			{
				link.l5 = "��������, ��� �� ����� ������-������ ������� ����, ������� ����� ���� �� ����������� ��� ����� �������?";
				link.l5.go = "storadge";
			}
			if (CheckAttribute(npchar, "storadge"))
			{
				link.l5 = "������, � ���� ������ �� �����. ���� ��� ������� - ������ �����.";
				link.l5.go = "storadge_3";
			}
			link.l99 = "���� ������...";
			link.l99.go = "carpenter_exit";
		break;
		
		case "carpenter_exit":
            DialogExit();
			npchar.dialog.currentnode = "carpenter_17";
		break;
		
		case "carpenter_18":
            dialog.text = "����������, ���. ��� ������ ������ ������? ������ ������?";
			link.l1 = "�� ����� �����, �� �������, ���?";
			link.l1.go = "carpenter_19";
		break;
		
		case "carpenter_19":
            dialog.text = "�����. ���, ��� ������ ���� ������ � ���� �������, ��� �������� �������� ���� ���������� ��� ����������� ��������.";
			link.l1 = "� �����, ��� ������ ��������� ����� ������������� ������ ����. ������ ���� ������� ����� ���, ��� ������ - ������ ������. ���� ������, ���� �������� ���� � ����� ����� �����. ������ ������������� ���. ��������, ���, ��������� - �����.";
			link.l1.go = "carpenter_20";
		break;
		
		case "carpenter_20":
            dialog.text = "��� ���� �� ������ ������������, �������. � ��� ������ ������ � ����� �� ������, �� ���� �������.";
			link.l1 = "��� � ������. ������, ��� ���������� ������?";
			link.l1.go = "carpenter_21";
		break;
		
		case "carpenter_21":
            dialog.text = "���� ����, ���.";
			link.l1 = "���� ����... ������ ��������, �� �������� ����� ��� ��������� ������... �� ��� �����. � ���� - ��� ���� ��� �����, ��� � ������, ������ � ������ ���������.";
			link.l1.go = "carpenter_22";
		break;
		
		case "carpenter_22":
            dialog.text = "������������. ������ ������ ����, �������.";
			link.l1 = "���� �����. �����, ������, �����, ��� ���� � �� ����.";
			link.l1.go = "carpenter_exit";
			npchar.portman = 0;
			AddDialogExitQuestFunction("Mtraxx_WolfreekComplete");
		break;
		
		case "repair":
			if (CheckSelfRepairConditions())
			{
				dialog.text = "�������, ���!.. ����� ������ ����� � ��������, � ������ �� �������. ������ � �����, ��� ��������, � ������� �������� ����������� ���������.";
				link.l1 = "������, ���. � �� ���� �� ��������.";
			link.l1.go = "repair_1";
			}
			else
			{
				dialog.text = "���, ��, �������, �����, �� ��-����� ���� �� ��������� ������.";
				link.l1 = "� ������ ���������������...";
				link.l1.go = "carpenter_exit";
			}
		break;
		
		case "repair_1":
            DialogExit();
			npchar.dialog.currentnode = "carpenter_17";
			chrDisableReloadToLocation = true;
			DoQuestReloadToLocation(Pchar.location.from_sea, "reload", "sea", "Mtraxx_WolfreekRepairShore");
		break;
		
		case "shipstock_info":
			npchar.portman.info = "true";
            dialog.text = "��� ����� �������, ���. �� ���� ��������� �����������: �� ���� ���� ����� ��� �����, ��� ����� ��������� ������� �� ������� ����� �������������� �����. ��� ��� ������� �������� ������ ��� ���� �������� ������������. �� ���� ���� ������� ����� �������������� � ������� � �����������. ������: �� ����� �� ������ ���� ������, ����� ���������� �������: ��� ������ �������, � ��������� ����� ����� ��������, ��� �� ��� ���������, ������. � ������: �� �� ������ ��������� �� �������� ������� ������� ������: ����� ��� ����� ������� ����.";
			link.l1 = "��� ����. � ����� �������� ���� �����.";
			link.l1.go = "shipstock";
			link.l2 = "� ��� �����, �����, ���������� ����� ��� ���������� �� �����.";
			link.l2.go = "carpenter_exit";
		break;
		
		case "shipstock":
			if (sti(npchar.portman) == 50) // krizis 50 �������� - ���... �� ����� ��� ��� ��� ������������� :D �����, ������� � 999 ���������, �� ������������ ������� ������� ������� �D
			{
				dialog.text = "���, �� ������� ��� ����� ��������� ����� ��������. �������! ������ ��� �����."; // // krizis ������ ��� 50 ��������(�������� ��� 2 �������. ������� � ���� ������)
				link.l1 = "�� ��, �����, � � �����.";
				link.l1.go = "carpenter_exit";
				break;
			}
			if (GetCompanionQuantity(pchar) < 2)
			{
				dialog.text = "���, ��� � ���� ����� ���� ������� � �������.";
				link.l1 = "���... �������, ���� ���� ������ ����...";
				link.l1.go = "carpenter_exit";
				break;
			}
            dialog.text = "����� ������ ������� �� ������ ��������?";
			for(i=1; i<COMPANION_MAX; i++)
			{
				int cn = GetCompanionIndex(PChar, i);
				if( cn > 0 )
				{
					ref chref = GetCharacter(cn);
					if (!GetRemovable(chref)) continue;

					attrL = "l"+i;
					Link.(attrL) = XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " '" + chref.Ship.Name + "'.";
					Link.(attrL).go = "ShipStockMan_" + i;
				}
			}
			Link.l9 = "����, � ���������.";
			Link.l9.go = "carpenter_exit";
		break;
		
		case "ShipStockMan_1":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 1);
			dialog.text = "���������, ��� ��� �� �������...";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "carpenter_exit";
		break;

		case "ShipStockMan_2":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 2);
			dialog.text = "���������, ��� ��� �� �������...";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "carpenter_exit";
		break;

		case "ShipStockMan_3":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 3);
			dialog.text = "���������, ��� ��� �� �������...";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "carpenter_exit";
		break;
		
		case "ShipStockMan_4":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 4);
			dialog.text = "���������, ��� ��� �� �������...";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "carpenter_exit";
		break;
		
		case "ShipStock_2":
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
			/*if (sti(RealShips[sti(chref.Ship.Type)].Class) < 2) // krizis �� ����� ��� �������� ��� �����, ������ - ��� �����
			{
				dialog.text = "���, � ��� ������� - ������� ������� ������ �� ���� ������� ��������� ������. ������� ������.";
				Link.l1 = "��, ��, �����, � � �����.";
				Link.l1.go = "carpenter_exit";
				break;
			}*/
			/*if (sti(chref.Ship.Crew.Quantity) > 0) // krizis ������� �� ���� ������? 50 ��������? �� �����, �� ����� ���������. �������(�����) ������ ���������� �� ������
			{
				dialog.text = "���, �� ������� ������ ���� ������ ���� ��������� ������ � ������ ������. �������� ������� �� �������.";
				Link.l1 = "��, ��, �����, ������ �������!";
				Link.l1.go = "carpenter_exit";
				break;
			}*/
			dialog.Text = "����, ��� ���� ��������� �� �������� "+XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName+"Acc")+" ��� ��������� '"+chref.Ship.Name+"'. � ��� ��������� �����?";
			Link.l1 = "��.";
			Link.l1.go = "ShipStock_3";
			Link.l2 = "���, � ���������.";
			Link.l2.go = "carpenter_exit";
		break;
		
		case "ShipStock_3":
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
            chref.ShipInStockMan = NPChar.id;
			chref.ShipInStockMan.MoneyForShip = 0;
            chref.ShipInStockMan.AltDate = GetQuestBookDataDigit();
            SaveCurrentNpcQuestDateParam(chref, "ShipInStockMan.Date");
            RemoveCharacterCompanion(pchar, chref);
            chref.location = "";
            chref.location.group = "";
            chref.location.locator = "";
            npchar.portman = sti(npchar.portman)+1;
            pchar.ShipInStock = sti(pchar.ShipInStock)+1;
			dialog.text = "������, ������� ��� � ���������� �� ������ �����. ��������, ����� �����������.";
			Link.l1 = "�������!";
			Link.l1.go = "carpenter_exit";
		break;
		
		case "shipstockreturn":
            if (GetCompanionQuantity(pchar) < COMPANION_MAX)
			{
				dialog.text = "����� ������ ������� ������ ��������, ���?";
				cn = 1;
				for (i=1; i<MAX_CHARACTERS; i++)
				{
					makeref(chref, Characters[i]);
					if (CheckAttribute(chref, "ShipInStockMan"))
					{
						if (chref.ShipInStockMan == NPChar.id)
						{
							attrL = "l"+cn;
							Link.(attrL)    = XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " '" + chref.Ship.Name + "'.";
							Link.(attrL).go = "ShipStockManBack_" + i;
							cn++;
						}
					}
				}
				link.l9 = "���, � ���������. ����� ����� �� ������ ������.";
				link.l9.go = "carpenter_exit";
			}
			else
			{
				dialog.text = "���, ���� ������� ���� �� ������� ��� ���� �����.";
				link.l1 = "��. �� ����.";
				link.l1.go = "carpenter_exit";
			}
		break;
		
		 case "ShipStockManBack":
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
			dialog.Text = "���������?";
			link.l1 = "��.";
			link.l1.go = "ShipStockManBack2";
			link.l2 = "���, �, �������, ��������� - ���� ����� ������.";
			link.l2.go = "carpenter_exit";
		break;
		
		case "ShipStockManBack2":
			DialogExit();
			npchar.dialog.currentnode = "carpenter_17";
			chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
			DeleteAttribute(chref, "ShipInStockMan");
			SetCompanionIndex(pchar, -1, sti(NPChar.ShipToStoreIdx));
			npchar.portman = sti(npchar.portman)-1;
            pchar.ShipInStock = sti(pchar.ShipInStock)-1;
		break;
		
		case "storadge":
            dialog.text = "��� ������ ��� ��������� ��� ������ ����, ���, �� ��� ��� � �� �����. ������� ����������� �����, ����� ��� �������� �������. ��� ������ ����� ����� �� ��������. �������� �������� ��� � ��� ����� ��� ���� ������: ��������� �� ��������, ����� �� ������, ��� �������, ����� �� ���������� ��������� ������� � ������������ ��������. �������� ��������: �� �����, �� ����� - �������, � ������ ���������� �� �����\n��������� ��������, � ����������� �����, � �� ���� �� ���� ��������� ���� �� ��������. ������ ����� ������. ���������, ���� ���� ��� �����, ���� ������ � ������ ������� ����� ���������, ���� �� ������� ����������. ���� �� ����� � ����, � ������. ������ ��������?";
			link.l1 = "�������! �, ������: ��� � ��� � ������� �� �������? �� ������� ��� ����� � ���� �����?";
			link.l1.go = "storadge_1";
		break;
		
		case "storadge_1":
            dialog.text = "����� ����� ��� ������������: ������ � �������� ���� �����. ������, ��� ����� ��� ��� �� �� �������: ������ ��� ������ ��������, ��� ������ � ����� - ����, ���������, ����� � ������, �� ����� � ���� ����� ��������. ��� ��� ������ �� ����������� ����� �� ������������. �� ��������� � ������ �� �����.";
			link.l1 = "�������! � ���� �� ������������. ���� ����� � ���� - ��� ����� ��������. ��, � ������ ��������� ���� �������� �����.";
			link.l1.go = "storadge_2";
		break;
		
		case "storadge_2":
			DialogExit();
			npchar.dialog.currentnode = "carpenter_17";
			npchar.city = "islamona";
			npchar.Storage.Activate = true;
			SaveCurrentNpcQuestDateParam(npchar, "Storage.Date");
			npchar.MoneyForStorage = 0;
			npchar.storadge = true;
			LaunchStorage(29);
		break;
		
		case "storadge_3":
            dialog.text = "�������, ���. �����, ������� ����.";
			link.l1 = "...";
			link.l1.go = "storadge_4";
		break;
		
		case "storadge_4":
            DialogExit();
			npchar.dialog.currentnode = "carpenter_17";
			LaunchStorage(29);
		break;
		
		// ��������
		case "mirabelle":
			PlaySound("VOICE\Russian\Girl_Q.wav");
            dialog.text = "��...";
			link.l1 = "��� ��� �����... �����!.. �� ������ ����� �������?";
			link.l1.go = "mirabelle_1";
		break;
		
		case "mirabelle_1":
			PlaySound("VOICE\Russian\Girl_Q.wav");
            dialog.text = "��...";
			link.l1 = "...";
			link.l1.go = "mirabelle_2";
		break;
		
		case "mirabelle_2":
            DialogExit();
			npchar.dialog.currentnode = "mirabelle_3";
			sld = characterFromId("Mrt_Rocur");
			sld.dialog.currentnode = "rocur_74";
			ChangeCharacterAddressGroup(sld, "LaVega_TwoFloorHouse", "goto", "goto8");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.5);
		break;
		
		case "mirabelle_3":
			PlaySound("VOICE\Russian\other\RapersGirl-01.wav");
            dialog.text = "������! ������ "+pchar.name+", �� �������� ����, �����! � ������ �� ����� �������! � �������� ����� �����! ������ ���, � ���� �������!";
			link.l1 = "...";
			link.l1.go = "mirabelle_4";
		break;
		
		case "mirabelle_4":
			DialogExit();
            npchar.dialog.currentnode = "mirabelle_5";
			sld = characterFromId("Mrt_Rocur");
			sld.dialog.currentnode = "rocur_80";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "mirabelle_5":
            dialog.text = "";
			link.l1 = "��, �����! �������? ������� �� ����, ��� ���� ������� ������ ������� ����.";
			link.l1.go = "mirabelle_6";
		break;
		
		case "mirabelle_6":
            dialog.text = "�����, ������, �����, ���� ������� �����!";
			link.l1 = "��� � ������. ��� ����� �� �����: ���� ������� ������� � ����� �� ������ ������� - � ��� ����� ���� ����. ��� ���� ���?";
			link.l1.go = "mirabelle_7";
		break;
		
		case "mirabelle_7":
            dialog.text = "��������...";
			link.l1 = "������ ����� ���� ���������, ��������, ��� ���������� ��� ���� ������. �� �� ��� �� ����, � ���� ����.";
			link.l1.go = "mirabelle_8";
		break;
		
		case "mirabelle_8":
            dialog.text = "�������, ������...";
			link.l1 = "...";
			link.l1.go = "mirabelle_9";
		break;
		
		case "mirabelle_9":
            DialogExit();
            npchar.dialog.currentnode = "mirabelle_10";
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			sld = characterFromId("Mrt_Rocur");
			sld.dialog.currentnode = "rocur_85";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
			pchar.questTemp.Mtraxx.Mirabella = "true";
		break;
		
		case "mirabelle_10":
			PlaySound("VOICE\Russian\Girl_Q.wav");
            dialog.text = "������?..";
			link.l1 = "�� ���� �������, �������, �����. ������ �� ������ �� �������, ��� �� ����������� ��� �����. �� �����, �� � ���� - � �����. �� ������� ������, ����� �� ������� � ������� �� ���� �������.";
			link.l1.go = "mirabelle_11";
		break;
		
		case "mirabelle_11":
            dialog.text = "� �� �����, ������! � � ������� �� �� ����� � �������, � �������� ���! ��������!..";
			link.l1 = "���! � ��� �� ���� �� ������ ������?";
			link.l1.go = "mirabelle_12";
		break;
		
		case "mirabelle_12":
            dialog.text = "����� ����... �������� ���, ��������!..";
			link.l1 = "����. ����� �������� �� �����, ������ ���� � ��������� ����. � ���� �� ������� ���� ������� - ���� �� ������. ��������� ����� ��������� �����, ��-��. � ������ ������ � ������... ��������.";
			link.l1.go = "mirabelle_13";
		break;
		
		case "mirabelle_13":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "sea", "none", "", "", "OpenTheDoors", 20.0);
			pchar.quest.mtraxx_pasq_mirabella.win_condition.l1 = "location";
			pchar.quest.mtraxx_pasq_mirabella.win_condition.l1.location = "Shore75";
			pchar.quest.mtraxx_pasq_mirabella.function = "Mtraxx_PasqualeMirabella";
			pchar.quest.mtraxx_pasq_mirabella1.win_condition.l1 = "location";
			pchar.quest.mtraxx_pasq_mirabella1.win_condition.l1.location = "Shore77";
			pchar.quest.mtraxx_pasq_mirabella1.function = "Mtraxx_PasqualeMirabella";
			AddPassenger(pchar, npchar, false);//�������� ���������
			SetCharacterRemovable(npchar, false);
			SetFunctionTimerCondition("Mtraxx_MirabellaSailOver", 0, 0, 30, false); // ����� �� ������� �� ���� ����
		break;
		
		case "mirabelle_14":
            dialog.text = "�� ������, ������?";
			link.l1 = "��, �������. ��� ��� ������� � ��� ���, ����? ��� � ������. �� ���� ������� ����� �� �����, ����� ����, � ����� ��� ������, ����� ���� �����. ��� � ����� ���������� ���� �� ����� - ����� ���, ��� ��� ������ ����� ���� � ������������� �� ���� �����. � ������, ����� ��� �� �������, ����� ��� ���� ����� � �������, �� �� ����� ���� ������� � ��� ���������. ������ ������ � ��������, �� ������ - ������� ������, ��� ����� ��� ������� ������ ���� ������.";
			link.l1.go = "mirabelle_15";
		break;
		
		case "mirabelle_15":
            dialog.text = "��� ������ �������, ������ "+pchar.name+". � ���� ������ ���, � � ������ �� �����. ����� ��� ����� � ������� ��������...";
			link.l1 = "� ����� ���� ��� � ��������, ���� �� ����: �� ����� ���, ������� � ������ � �����������, ��� �� ������� ����� ��������� � ������� � ������. ����� �����, ��� ������ ���� ����������.";
			link.l1.go = "mirabelle_16";
		break;
		
		case "mirabelle_16":
            dialog.text = "�� ���� ������ ����, ������...";
			link.l1 = "�� ������ ����� �������. ��� �� ����.";
			link.l1.go = "mirabelle_17";
		break;
		
		case "mirabelle_17":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.mtraxx_islamona_mirabella1.win_condition.l1 = "location";
			pchar.quest.mtraxx_islamona_mirabella1.win_condition.l1.location = "IslaMona_TwoFloorRoom";
			pchar.quest.mtraxx_islamona_mirabella1.function = "Mtraxx_PasqualeMirabellaRoom";
		break;
		
		case "mirabelle_18":
            dialog.text = "";
			link.l1 = "���. � ������� ���� ���� ���. ������ �� ����, ��� ���, � ������� �� ���� � �������. ���� ��� ����������, �������?";
			link.l1.go = "mirabelle_19";
		break;
		
		case "mirabelle_19":
            dialog.text = "��, ������. � ��� �������� ���. ������ ������ �������� �� ��� � ���� ����������.";
			link.l1 = "���, ��� �� ��������� ����� �����������. �������, �� �������������. ���� �� ������� - ��������� �� ����. ������ ������� �������� � �� ������� ���� �������� - ���� � ����� ������, ������. "+pchar.name+" ����� ���� �� ����� �� �������!";
			link.l1.go = "mirabelle_20";
		break;
		
		case "mirabelle_20":
            dialog.text = "�������, ������ "+pchar.name+". �������, ��� �� ��������� ������... �������� ����� ����. �� ��� ����� �� ���...";
			link.l1 = "���, � �� ��������, ������... � �������� � ���� ������ �����. �������, ��� ��������� ���� �� �����... ��, ������ ������ ������ ��������, ��� �� ������. ����������� � ����� �� ���� ����� ����� ������� �����.";
			link.l1.go = "mirabelle_21";
		break;
		
		case "mirabelle_21":
            DialogExit();
			pchar.GenQuest.FrameLockEsc = true;
			bDisableCharacterMenu = true;
			ResetSound();
			WaitDate("", 0, 0, 0, 2, 30);
			SetLaunchFrameFormParam("", "", 0, 12);
			SetLaunchFrameFormPic("loading\inside\censored1.tga");
			PlayStereoSound("sex\sex10.wav");
			LaunchFrameForm();
			AddCharacterHealth(pchar, 5);
			LAi_SetCurHPMax(pchar);
			DoQuestFunctionDelay("Mtraxx_PasqualeMirabellaSex", 12.0);
			ChangeCharacterAddressGroup(pchar, "IslaMona_TwoFloorRoom", "goto", "goto2");
			ChangeCharacterAddressGroup(npchar, "IslaMona_TwoFloorRoom", "goto", "goto4");
		break;
		
		case "mirabelle_22":
            dialog.text = "������ "+pchar.name+", �� ����� �����... �� ��������� ����������� ����������. ��������, ������� �������� �� ������...";
			link.l1 = "�� ����� ���, ��������� ������, � �� ����� �� �������. ���, �� �� � ������ ������, ��������! ������ ����, ���� ��������, ��-��...";
			link.l1.go = "mirabelle_23";
		break;
		
		case "mirabelle_23":
            dialog.text = "��� �� �����. �� �� ����� ���� ����������. ������ �����-�� ������������� ������. �-�-�... �� ��� ��� �����������. � ���� �����, ����� �� �������� ���� �����.";
			link.l1 = "���, ����������... ���������� �����, ��-��! ���, �������, ����, ��������� �����.";
			link.l1.go = "mirabelle_24";
		break;
		
		case "mirabelle_24":
            dialog.text = "�� ��������, ������.";
			link.l1 = "...";
			link.l1.go = "mirabelle_25";
		break;
		
		case "mirabelle_25":
            DialogExit();
			npchar.InOurHouse = true;
		    npchar.dialog.currentnode = "mirabelle_26";
		    chrDisableReloadToLocation = false;
			pchar.quest.mtraxx_mirabella_setlife.win_condition.l1 = "MapEnter";
			pchar.quest.mtraxx_mirabella_setlife.function = "Mtraxx_MirabellaSetLife";
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
		break;
		
		case "mirabelle_26":
            dialog.text = TimeGreeting()+", ������ "+pchar.name+"! ����� ���� ��� ������. ��� ���� ����?";
			link.l1 = RandSwear()+""+LinkRandPhrase("����� ������ ���������� � �������� ���� �����, ��-��!","���������� ������� �� ������ ��������! ��-��-��, � ������� ����!","��� ��������� ���� �� ��������� ����� - ��� �������� � ������ �������!")+" � "+pchar.name+" ������ ��� �������, ������.";
			link.l1.go = "mirabelle_26x";
			if (!CheckAttribute(npchar, "sex_date") || GetNpcQuestPastDayParam(npchar, "sex_date") >= 1)
			{
				link.l2 = "�������, ��� ������ ����, ����� ���������� ������ ��������?";
				link.l2.go = "mirabelle_sex";
			}
		break;
		
		case "mirabelle_26x":
            DialogExit();
		    npchar.dialog.currentnode = "mirabelle_26";
		break;
		
		case "mirabelle_sex":
            dialog.text = "��� ��� - ��� ��� ������, ������!";
			link.l1 = RandPhraseSimple("����� � �����!","�� �������!");
			link.l1.go = "mirabelle_sex_1";
		break;
		
		case "mirabelle_sex_1":
            DialogExit();
			LAi_SetActorType(npchar);
		    npchar.dialog.currentnode = "mirabelle_27";
			if (pchar.location == "IslaMona_TwoFloorRoom") DoQuestFunctionDelay("Mtraxx_MirabellaSex", 1.5);
			else DoQuestReloadToLocation("IslaMona_TwoFloorRoom", "goto", "goto2", "Mtraxx_MirabellaSex");
		break;
		
		case "mirabelle_27":
            dialog.text = "�-�-�... ������, �� ������ ��� � ���������! �������, �� ���� �������� ��������? � ���������.";
			link.l1 = "�� ���� �� ������, ������...";
			link.l1.go = "mirabelle_28";
		break;
		
		case "mirabelle_28":
            DialogExit();
		    npchar.dialog.currentnode = "mirabelle_26";
			LAi_SetStayType(npchar);
			SaveCurrentNpcQuestDateParam(npchar, "sex_date");
		break;
		
		case "mirabelle_sleep":
            dialog.text = "��� ��������, ��������! ������ "+pchar.name+" ������� � ������! �� ������ ������������ ���� �������! ���� ���, ������ "+pchar.name+"?";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep6_1");
		break;
		
		case "mirabelle_29":
            dialog.text = TimeGreeting()+", ������ "+pchar.name+"! ����� ���� ��� ������. ��� ���� ����? ������ �� ����� ��������?";
			link.l1 = "������, ��������. ������ �� ������, ��� ��������?";
			link.l1.go = "mirabelle_30";
		break;
		
		case "mirabelle_30":
            dialog.text = "�� � �� ����. �� �� �����, ��� ������. ������, � ��� ���������? � ������� �� ���. ��������!";
			link.l1 = "������. � ���� � ����� ����������.";
			link.l1.go = "mirabelle_31";
		break;
		
		case "mirabelle_31":
            dialog.text = "������, ������, ��� �������. � ��� ������.";
			link.l1 = "��������, ��� �� ������ � �������? �� �����, ������ ���, ��� ����, � ������ ������� ���� �� ������. ��� ������ ����� ����� ���� �������.";
			link.l1.go = "mirabelle_32";
		break;
		
		case "mirabelle_32":
            dialog.text = "��, ������! ��� ������� �������� � ������������. �������� � �� ������-����, ��� ���� ��� ����� ����������, � ���� - ��������. ���� ������ � ������� �� ������. � ������� �������� � �������� ��������, � ����� ����� �������� �������� - ��������� ��������: ������ � ������ �� �������� ���� �������������� - � ���� ������� �� ���� ����� ���������, � ��� ��� ��������. �������, ����� ����������, � ��������, ��� ��� ������\n����� ��� �������� ���, ���� ������� ������, ��������� � ���� ���-���� � ������� � ������. ��� � ������� �������: ���� ������ ����������� � ����������� ������, ����� ��� ����� ����� �� ������ � ��������� �� �������, ����� ������� � ���������� �� ����-������� � ������� � ������� ����� ������� �� ������ ������� ��������\n��� � ����, ��������, ���, ��� ������. � �����, � ���� ���������� ����, ������� ������ � ��� ������� ������, ����� � �����.";
			link.l1 = "�������� ������...";
			link.l1.go = "mirabelle_33";
		break;
		
		case "mirabelle_33":
            dialog.text = "��-��, ��� ����� ������ ��������. �� �� ����, ��� � ��� ��� ������������, �� ����� �� ��������� ������ ������� ���� � ����� �������, ����� � �� ���� � ����� ���� � ���� ����� �������� � �������� � ��������. ��� ���� ����� ������ ��� � ���� �����, �������� ���� ������ � ������. ������ �������� �� ��� ����� ������ ����, ���� �� ����������� � ����, �� ��� ��� ������, � ����� ������� �����������, ����� � ���� � ����� �������� ������ ��������. ������ "+pchar.name+", ����� � �� ���� ��� ��� ������������?\n������� � ��� ���� - �� ����, � ���� ��� ��� � ������ ����� ������������. � ����� ������� ����� ������ ��, ������, � ������� ���� ������. ��� ����� �������, ��� �� ��������� ����� ������.";
			link.l1 = "������? ��������, � ���� ������ �� �� �����: ����� ���� �� ������ � ����� � ����...";
			link.l1.go = "mirabelle_34";
		break;
		
		case "mirabelle_34":
            dialog.text = "���, ������, ��� �� ���. ����� � �������? � ���� ������ ������ ����. �� ����� ������� ����� ������� � ��������. � ������ �� ���� ����� �����? � �������� ������ �����. � ��, ������, �� ������, � �� ��� ������-�����. � ������ ���� ��� ������, �� ����� ������� � ��������. � ����������...";
			link.l1 = "��������, ������, � ������ ���� � ����� �����? ����� ��� �� ������ �����. ���� ���� ���������? ������� ����� �������.";
			link.l1.go = "mirabelle_35";
		break;
		
		case "mirabelle_35":
            dialog.text = "������, �� ������ ���� ��������? ����� ���, �� ����!";
			link.l1 = "���... � �����, �� ������ ��������� � ������� �����...";
			link.l1.go = "mirabelle_36";
		break;
		
		case "mirabelle_36":
            dialog.text = "��, ������ "+pchar.name+", � ��� ���� ��� ����? ����� � ���-�� ������� ����� ����������? ������ ������ �����-������, ����� �������, ��� ���� ����. � �� � ����� - ����� � ������� ��������. �� ������ ����. � �� ���� ������� ������, ��� ����� � ������� �� ���� ��� ������ � �����, ��� �����! ������ � ��� ����� - ������� ������, ������ �� ���� � �� �������. ��� ������ � ����. �� ������� ��, ������, ��������� ������ �� �����, � � ������ �����. ����� ���, ������, � ���� ��� ������, ��� �������, ������ ��������� ��� �������� � ���!";
			link.l1 = "������, ��������, ��� ���� ��� �������� ����� - ���������. ������ ����, ��� �� �� ��������, � ������ ������ ��������� ���� ������� ���� ������.";
			link.l1.go = "mirabelle_37";
		break;
		
		case "mirabelle_37":
            dialog.text = "������� ����� ������, �������! � ������� �� ����� ������� ��� �� ���� - � ���� �������� ��������� ����� ������� � ����� ���������, ��-��... �� ����� ������ � ����� �������� �������! �� ����� �����, �� ���������, ��� ������, � ��� ��� ���� ���, �� ����� �������.";
			link.l1 = "������ �� ����� �� �����, �� �����������, ��������. ������, ��� ��� ���� � ����� ������. ��� �����! � ��������� ��� � ������ �� �����, �� ����� � ������, � ������ �� �������� � ��? ����������, ��...";
			link.l1.go = "mirabelle_38";
		break;
		
		case "mirabelle_38":
            dialog.text = "���� �������, �������� �� ����, �� � ������� ����� � �� ��� ��������� ������� � ��������, ������� � ��������. �� ������ ������ ������ ������� � �������, ��� ���������� ����?.. ��, ������, ������, � ��� ��� ������� ����� ������� ������� � ������, � ����? ������ ��� ���. � ������ �������� �� �� ����! �� ����� ��� ����� ��������, ��� ������ � �����. � ����������� �� ���.";
			link.l1 = "������� �������, � ��� �� �������, � ��� ��� ��������?";
			link.l1.go = "mirabelle_38_1";
		break;

		case "mirabelle_38_1":

			dialog.text = "�������� � ����� - �� ����� � �� ����� ��� ��� ������ ����������� �� �������.";

                        if (!CheckAttribute(npchar, "quest.Panama_toReady") && CheckAttribute(pchar, "questTemp.piratesLine.Detector")) // ����� �� ������ �������, �� ��� �����
			{
				link.l1 = "�� ������ ������... ������ � ���� �����-���� ������.";
				link.l1.go = "mirabelle_39_0";
			}
			else
			{
				link.l1 = "���������� � �����, �� ������ ������, ������, ������, �������... ������ � ���� ����������.";
				link.l1.go = "mirabelle_39_0";
			}

		break;


		case "mirabelle_39_0":
                        DialogExit();
			LAi_SetActorType(npchar);
		        npchar.dialog.currentnode = "mirabelle_40";
			if (pchar.location == "IslaMona_TwoFloorRoom") DoQuestFunctionDelay("Mtraxx_MirabellaSex", 1.5);
			else DoQuestReloadToLocation("IslaMona_TwoFloorRoom", "goto", "goto2", "Mtraxx_MirabellaSex");

		        AddDialogExitQuestFunction("Gothic_RevengeCorsair");
		break;
		
		case "mirabelle_39":
                        DialogExit();
			LAi_SetActorType(npchar);
		        npchar.dialog.currentnode = "mirabelle_40";
			if (pchar.location == "IslaMona_TwoFloorRoom") DoQuestFunctionDelay("Mtraxx_MirabellaSex", 1.5);
			else DoQuestReloadToLocation("IslaMona_TwoFloorRoom", "goto", "goto2", "Mtraxx_MirabellaSex");
		break;
		
		case "mirabelle_40":
            dialog.text = "��, ������ "+pchar.name+", �� ����� ������ �������. �� ����� �����, �-�-�... �� �������� ��������, ��� ������� �������?";
			link.l1 = "��� ���� ������ ������������, ��������.";
			link.l1.go = "mirabelle_41";
		break;
		
		case "mirabelle_41":
                                    DialogExit();
		npchar.dialog.currentnode = "mirabelle_42";
		LAi_SetStayType(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "sex_date");
		break;
		
		case "mirabelle_42":
			bool bMary = GetCharacterIndex("Mary") != -1 && CheckAttribute(pchar, "questTemp.LSC.Mary_officer");
			bool bHelena = GetCharacterIndex("Helena") != -1 && CheckAttribute(pchar, "questTemp.Saga.Helena_officer");
            dialog.text = TimeGreeting()+", ������ "+pchar.name+"! ��� ������, ��� �� ��������! ����� ���� ��� ������! ��� ���� ����?";
			link.l1 = ""+LinkRandPhrase("� � ��� ���� ������, �������.","������, ��������. ��, ��� ������ - ������ � �������, ������� ����������.","����������, ���������. ������� ���������!")+" � ���� ��� ���� �������. �������, ��� � ���� ���� ��� ������.";
			link.l1.go = "mirabelle_42x";
			if (!bMary && !bHelena) // ������� 3
			{
			if (!CheckAttribute(npchar, "sex_date") || GetNpcQuestPastDayParam(npchar, "sex_date") >= 1)
			{
				link.l2 = "��������, � ��� ����� ����������� �� ���� � ����� ������. ��������� ������� �������� �����?";
				link.l2.go = "mirabelle_43";
			}
			}
		break;
		
		case "mirabelle_42x":
            DialogExit();
		    npchar.dialog.currentnode = "mirabelle_42";
		break;
		
		case "mirabelle_43":
            dialog.text = "��, ��� ����� �������, � ���� ������� �� ��� � �� ����� ������� ��������! �������� ��, � ��� ��� � ����������!";
			link.l1 = "...";
			link.l1.go = "mirabelle_39";
		break;
		
		// ���������� ���������
		case "CartahenaMayor":
            dialog.text = "��������� �������! ������, ��� ����� ��� ������ � �����-�����. ����� ���� �������� ���� �������, �...";
			link.l1 = TimeGreeting()+", ���� ���������. ��� ������ ��� � ������ �������. �������, ��� ��� ��� ��������� ����� �� �������� � ����� ����, ��� �� ������� ������. �� ������� � �� �� ����� ����� �� ����������� - �����, ��� �� ��� ���, ����� �� �� ����������, � ����� �����, ��� �� ���������, ������������ ��� ����, ����� ����������� ���� ������ ��������� �� ������. ��� ��� ������� �������� � �����.";
			link.l1.go = "CartahenaMayor_1";
		break;
		
		case "CartahenaMayor_1":
            dialog.text = "�� ��� ������� � �����! ���������� � ����, ��� ������ �� ������ � � ����� ���� ����������!";
			link.l1 = "��, ���� ���������, ��� ��� ������� �� ���������� � ���, ��� ��������, ���� �� ��������� ������������. �������, �� ���������, � ��� ������ ����...";
			link.l1.go = "CartahenaMayor_2";
		break;
		
		case "CartahenaMayor_2":
            dialog.text = "� ����, �� ��� �������� ����������� ������ � ����� "+pchar.name+" �����! � ����, ��� �� ���������! ������ ����� - �� ������ ������� ������� ���� ����������� ������ �� ���������! �����? �������?";
			link.l1 = "�, �� ������� ��� �����, ������� ����������! � ����� ����������� ������ ��������� ����� ����.";
			link.l1.go = "CartahenaMayor_3";
		break;
		
		case "CartahenaMayor_3":
            dialog.text = "������ ��������� �����?! ���� �������� �� ����� �������! ��� ������!!";
			link.l1 = "�������, ��� ������. � ��� �� ���? ��������� ����� ������, ����������� � ������ ����������� ������� �����, � �������� ���� ���� � ������� � ������� ������. �����... ��� �������� ���������� � �����, ������� �������� ��� �� �� �����.";
			link.l1.go = "CartahenaMayor_4";
		break;
		
		case "CartahenaMayor_4":
            dialog.text = "��������� �����! ��������! �������������!";
			link.l1 = "�� ���� �������������� ������������ � ���������� ����� �� ������� ����� ����.";
			link.l1.go = "CartahenaMayor_5";
		break;
		
		case "CartahenaMayor_5":
            dialog.text = "������ ���� � ���, ������� ������!..";
			link.l1 = "������ ��������� ����� ����. ������� ����������, ��� ���-���� ��������� ����?";
			link.l1.go = "CartahenaMayor_6";
		break;
		
		case "CartahenaMayor_6":
            dialog.text = "� ������ ��� ����� �����!";
			link.l1 = "�� �����. ����� ������ �� ����� ����. � ��� �������� ��������� � �������, �� �����, �� ��� ���� ����� ������� ����� �������, ������� � ���� ���� � ���������� ��������� ������ � ������ ��������� ����� ����.";
			link.l1.go = "CartahenaMayor_7";
		break;
		
		case "CartahenaMayor_7":
            dialog.text = "��� ��� ������ ����, "+pchar.name+" �����: ��� � ��������� ����� �����!";
			link.l1 = "��... ��� �������� ��������. �����! ����� ����� ����� ������ �������������� ����������� � ������� ���� ����, ���� �������. ��� ����������!.. � �� � ���� ���� ��������, ���� ���������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_CartahenaInResidence");
		break;
		
		case "CartahenaMayor_8":
            dialog.text = "";
			link.l1 = "��, ������ �������! �� ��� �� �������� ������ ������ ������ ������� �������� ������� � ���������? �, ���-�� �� ����������! ��� �����? ����������� ����?";
			link.l1.go = "CartahenaMayor_9";
		break;
		
		case "CartahenaMayor_9":
            dialog.text = "";
			link.l1 = "��� � �������, ��� ��� ���� - ���� ������� � ����, ������� ����������? ������ �������, ���� �� �����, ��������� ��� ��������, ��� �� ��� ��������� ���������, ������� �� �� �� ������... � ��� ����� ����� ��������� ����������� ������ ����� �������� ��� ������ ������� �����. ��� ��� ������������, ������. �� ���? ���� �������� ������, ��� ���?";
			link.l1.go = "CartahenaMayor_10";
		break;
		
		case "CartahenaMayor_10":
            dialog.text = "���... ��� ����������� �����...";
			link.l1 = "���! ��� ��� �� ����������?! � ��� ��� � ��� �������� � �������, �? ��, ��� ��� ��������� ������������ � ������ ����� ������������� - ���� �� ��������� �� �������, � ��� ���� ����� �� ����� ������� - ����������? ����������� �� ���� �������, canalla? � ������ ����, ��� �������� "+pchar.name+" ������!";
			link.l1.go = "CartahenaMayor_10x";
		break;
		
		case "CartahenaMayor_10x":
            dialog.text = "";
			link.l1 = "���� �������� ����� - ������ ��������� �����, � ����� �� ���� ������. ��� ���� �����. � �� ���� ������������ �����, �������� ���������-������ ���� � �������� ���� ����� ������... � ����������, maldit�, � �� �� � ������� ��������� �������� � ����� ��������, � ����� ���� �������� �������� ��� � ��. ������!!";
			link.l1.go = "CartahenaMayor_11";
		break;
		
		case "CartahenaMayor_11":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "Mtraxx_CartahenaResidenceWait", 5.0);
		break;
		
		case "CartahenaMayor_12":
			AddMoneyToCharacter(pchar, 350000);
            dialog.text = "������ ���� �������� ������, "+pchar.name+" �����, � ������ �������� �� ������ �� �������. ����� ��� ������� ��������� ������� � �������...";
			link.l1 = "�� ������� �����? ������ ������������! �� �� �������� �� ����� ���, ������� ����������. � �� ���� ��� �� � ������� ������, ��� ��� ����� ����� ������ ��� ���� ��������, ������� ���� ��� ����� � ��� � ������� ������������ �������� ������...";
			link.l1.go = "CartahenaMayor_13";
		break;
		
		case "CartahenaMayor_13":
            dialog.text = "��... ��!..";
			link.l1 = "��, ����� �� �� �������, ���� ���������. ��� � �������� ������... �����! �� ����!..";
			link.l1.go = "CartahenaMayor_14";
		break;
		
		case "CartahenaMayor_14":
            DialogExit();
			AddQuestRecord("Roger_9", "7");
			AddDialogExitQuestFunction("Mtraxx_CartahenaToFort");
		break;
		
		// �������
		case "camilla":
			PlaySound("VOICE\Russian\hambit\Girls_3.wav");
            dialog.text = "��, �� ��� �� ��� "+pchar.name+" �����, ���������� �����, ����� ���������� ������ �����!";
			link.l1 = RandSwear()+"���, ���� �� �����, ��� � ����� ��������� �� �������. ��� ���� ���, �������?";
			link.l1.go = "camilla_1";
		break;
		
		case "camilla_1":
            dialog.text = "���� ����� �������.";
			link.l1 = "�������... ������ � ���� �������, ��� � ������. ��� ����� ��� ����!..";
			link.l1.go = "camilla_2";
		break;
		
		case "camilla_2":
			PlaySound("ambient\tavern\orijka_003.wav");
            dialog.text = "";
			link.l1 = "... ���!.. ������, ��������, ����� ������� ������� �����. ��� ���... �� ������ ��� ������� �� ���, ��� � ���� �����-�� ����?";
			link.l1.go = "camilla_3";
		break;
		
		case "camilla_3":
            dialog.text = "�����, ������ ���, � �����, � �� ������. �����, � ����, � �����, � ���...";
			link.l1 = "� ���� ������ ������ �������. �����-�� �� ����������, ������...";
			link.l1.go = "camilla_4";
		break;
		
		case "camilla_4":
            dialog.text = "� ������ ������� ������ ���� �������.";
			link.l1 = "�������, �� ������, ����� � ��� ������� ��������. ���? � ������ ����������� ������� �������, ������� ������! �����, ������ � �������, ��������, ������ ���� - � ����� ���� ����� ������ ���������!";
			link.l1.go = "camilla_5";
		break;
		
		case "camilla_5":
            dialog.text = "�-�-�... ��� �������� ������ �����. ������ ���� ���� �����, ����� ������� ������, � �� �����. ����� �������, ��� � ������, � ���������.";
			link.l1 = RandSwear()+"������ ��������! ������ �� ����!";
			link.l1.go = "camilla_6";
		break;
		
		case "camilla_6":
            DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.mtraxx_retribution_tavern.win_condition.l1 = "locator";
			pchar.quest.mtraxx_retribution_tavern.win_condition.l1.location = "Tortuga_town";
			pchar.quest.mtraxx_retribution_tavern.win_condition.l1.locator_group = "reload";
			pchar.quest.mtraxx_retribution_tavern.win_condition.l1.locator = "reload4_back";
			pchar.quest.mtraxx_retribution_tavern.function = "Mtraxx_RetributionToTavern";
		break;
		
		case "camilla_7":
			PlaySound("VOICE\Russian\hambit\Gr_officiant_1.wav");
            dialog.text = "��... �������, ��������� ����!";
			link.l1 = "�������, ���������!..";
			link.l1.go = "camilla_8";
		break;
		
		case "camilla_8":
			LAi_Fade("", "");
			PlaySound("ambient\tavern\krujki_005.wav");
			PlaySound("ambient\tavern\naliv_003.wav");
			PlaySound("ambient\tavern\glotok_001.wav");
			WaitDate("", 0, 0, 0, 1, 5);
            dialog.text = "�-�-�... �������� ������ - � ���� ������� ������ � ����� "+pchar.name+" �������, ��� �������� ����...";
			link.l1 = "�� ���������� �������� ����� ��������, ������! "+pchar.name+" ����� ���� � ������ � ������, ������� ��� �� �������. �� ���� �� ������ ��� ��������, ���?";
			link.l1.go = "camilla_9";
		break;
		
		case "camilla_9":
            dialog.text = "��-��-��... �� � ���� ������, �������. � ���� �������� ������ ���������...";
			link.l1 = "����� �� ����� ������ �������, ��������?..";
			link.l1.go = "camilla_10";
		break;
		
		case "camilla_10":
            dialog.text = "������ ������ ��������� ������!..";
			link.l1 = "...";
			link.l1.go = "camilla_11";
		break;
		
		case "camilla_11":
            DialogExit();
			pchar.GenQuest.FrameLockEsc = true;
			bDisableCharacterMenu = true;
			ResetSound();
			WaitDate("", 0, 0, 0, 2, 30);
			SetLaunchFrameFormParam("", "", 0, 5.1);
			SetLaunchFrameFormPic("loading\inside\censored1.tga");
			PlayStereoSound("sex\sex2.wav");
			LaunchFrameForm();
			AddCharacterHealth(pchar, 3);
			LAi_SetCurHPMax(pchar);
			DoQuestCheckDelay("Mtraxx_RetributionRoomSex", 5.1);
		break;
		
		case "camilla_12":
            dialog.text = "�-�-�...";
			link.l1 = "�� �������� ��������, ��� ��������?";
			link.l1.go = "camilla_13";
		break;
		
		case "camilla_13":
            dialog.text = "��� ��!.. ����, �������, ���� �����������.";
			link.l1 = "���! � ���� ���� ���� ����� �� ������ ����������!";
			link.l1.go = "camilla_14";
		break;
		
		case "camilla_14":
            dialog.text = "�����, � ���� � ���� ����� �������. ���������?";
			link.l1 = "�� ���� ���� � ����, ��-��! ����������, ��� ��� � ����?";
			link.l1.go = "camilla_15";
		break;
		
		case "camilla_15":
            dialog.text = "��� ����� � �� ����, � �������. ���� � ��� ����������, � �� ��������� � ���. ����� ���� � ����.";
			link.l1 = "� ���! � ����� ��������� ������� ����������� ����� ����� � ������� ������?";
			link.l1.go = "camilla_16";
		break;
		
		case "camilla_16":
            dialog.text = "����� � ������� ������ ������ ���������� �����. ����� ������ ���� � ������� � ��� �������� ������� ���� �������. � ������ ����� �� ������ � ����.";
			link.l1 = "�� ��?! ��������� - ���? ���� ������� �� ���������� ��������? ��-��!";
			link.l1.go = "camilla_17";
		break;
		
		case "camilla_17":
            dialog.text = "������� �������� � ������ - ��� �� ����� ������ ������ ����� ����, �����, � � ���� ��� �����. ������ �������� � ������� ����������. ����������, ��������� �������, �� ������������ ������. � ���� ���� ���-���... ���� � ������� ����� ������� �� �����, � ��� ������ - ������. � � ������ � ����� ���� ��������� ������� � ���� ��������.";
			link.l1 = "����� ���������! �������� ��� - ���� � ��� ������ ����.";
			link.l1.go = "camilla_18";
		break;
		
		case "camilla_18":
            dialog.text = "��...";
			link.l1 = "�� �� ��������� ��. �, ������, ������ ���� �������, � �������� �� ���� ����� ������ �� ����� ����������, ���������� �������� �� ����-�� �� �������. ���� ���� �������, ���� �� ����������� ������ ������ - � ��� ����� � ���� ��������. ��?";
			link.l1.go = "camilla_19";
		break;
		
		case "camilla_19":
            dialog.text = "�����. � �������� ����, �� ������ � ����� ������! � ���������� �� �������� �����, ����� � ������ ������. ��������, �����?";
			link.l1 = "�������, ��������. "+pchar.name+" ����� �� ���������� ����� ���������, ��-��! �����, � ������.";
			link.l1.go = "camilla_20";
		break;
		
		case "camilla_20":
            dialog.text = "��� ���� ��� �������� �������� �����. ������� �� �����-�� ������� �����, ��� � �������� ����� ���� ������ ��������� ������� ��������-����������������. ��� ��������� ���� ��������� �������� ��� ����� ������� �������������� � ��������, � ���� ��������� ������ �� ���� �������, � �����, ������� � ���� - �������� ���������. ������ � ������ ���-���� ������� ���� ������ ����� ������. ���� ���������� ����\n������ � ����� ����� �������� � ����������� �� ������ ����� ������� � ������� ��������� �������, � � ��� - ������, ������� � �������������� ���������� �������� ��� �����. ����� ������. ���� �������� �� ����� � ����� �����, ����� ������� ����� � ������� ���������, ������, � ������ �����, ������� �� ��������� - ������, ������� ��������, ���������������� ����������� ��������, ���������� ������� � ����� �����. ���� � ������ �������� �� ����� ��������� ������\n��� ���������� ����� � ������� ����� ������, ������� ������� ���������� ����, ��... ������� ����� � ����� �������������. ��� ������ ������� (�����������), � ���� ��������� �� �����, ��� ��� ����� � ������ ������. �� ����� ��������� �����, �� ������ ������� - ������ ������� ��������� ���, �� � ��������� ������� ��������� ��������. ���� �������� �����, ��� ������ � ����� ������� ������ � ����� �� ���\n������: ���, ������� ����� - ����� ���� ������ ���������� ����, � ������ ���� ��������. ��� ������, ��������, �� ������� ����... �����-�� � ����, �� ���� �������: ��� ���� ������� �� ���������, � ����� ������ ������ ���� ���-�� �����. �� � ���� ������, ���� ������� ������ �����, � ������� �� ������� ����� � ���� ��������� ����� - ����� ������ ��������. ���! ����� ���� ��� ���� ������ ����� ������� �������� � �������� �������������. ������� � � ��������� � �������.";
			link.l1 = "������� �� ������ �� ��� �����?";
			link.l1.go = "camilla_21";
		break;
		
		case "camilla_21":
            dialog.text = "��� ����� ��������. ��� ����� ����, ������� ��� ������ - ��� ������ ��������� ����. ������ ����������, � �������. � ���� ����� ���� �� �����.";
			link.l1 = "���! � ���� ��� ��� �������?";
			link.l1.go = "camilla_22";
		break;
		
		case "camilla_22":
            dialog.text = "� ������ �� ����������? �������� ������ �������? �������, ����� ���� � ������, ��� �� ���� �����. ��� �� �������� ����? �� ����������...";
			link.l1 = "��� ��� �����? �������� ��?";
			link.l1.go = "camilla_23";
		break;
		
		case "camilla_23":
            dialog.text = "����� �������� � ����� ��������� � ������, � ������ � �� ������ � ����� �� ������ ��������.";
			link.l1 = "������! � ����� � ���� ��� ����� - ���������� � �������� � ������� ����� ���������� �� ���� � �����.";
			link.l1.go = "camilla_24";
		break;
		
		case "camilla_24":
            dialog.text = "�� ������ ��? ������, �����? ��� � ����, ��� �� ���� ����� � �� ����! ������ - � ����� �������. ����, ������, ����, �� �������� ������.";
			link.l1 = "����� ������� ������� ���� ������� ������. ���� ���� �������� �������?";
			link.l1.go = "camilla_25";
		break;
		
		case "camilla_25":
            dialog.text = "����� �����������: �� ������� ����� ���� � ����� ���� � ������ ���� �� ���� ��� � ����� ������. ��� ����� ������� ����� � ���� ����������� ���� ���������. ��� � �������� ������.";
			link.l1 = "�� ��� ����� ����������? ��-��! �� �� �����, �������: �� ������ � ����. ���� �����-�� ������ ������� �������� "+pchar.name+" ����� �� ������ ��������� �� ������.";
			link.l1.go = "camilla_26";
		break;
		
		case "camilla_26":
            dialog.text = "��� � ������. ���, ��� ����, �����, � ������� �� ��������� ����������� �����! ��� ������, ��� � ���� ���������!";
			link.l1 = "����� ��������, �������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionOutRoom");
		break;
		
		case "camilla_27":
			PlaySound("VOICE\Russian\hambit\Girls_3.wav");
            dialog.text = "��? �� ������ ������, �������?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 200)
			{
				link.l1 = "��. ����� ���� ������ � ����� ��� �����.";
				link.l1.go = "camilla_28";
			}
			else
			{
				link.l1 = "� ��� ��� ��� �� ������� �� ����.";
				link.l1.go = "camilla_27x";
			}
		break;
		
		case "camilla_27x":
            DialogExit();
			npchar.dialog.currentnode = "camilla_27";
		break;
		
		case "camilla_28":
			RemoveItems(pchar, "gold_dublon", 200);
			Log_Info("�� ������ 200 ��������");
			GiveItem2Character(pchar, "mapEnrico"); 
            dialog.text = "�������, �����... ���, ����. ������� ������� ����� ���� - ����� ������.";
			link.l1 = "������, �������. ��� ������ ����, ����� ����� � ������ ���� �������� ������? ��� � ������� ���...";
			link.l1.go = "camilla_29";
		break;
		
		case "camilla_29":
            dialog.text = "� �� � ��������, �����, �� ������ � ��������� � �������� � ������ ���������, � ��� �������� ������ ����������� �� ���� ���������. ����� � ��������� ���.";
			link.l1 = "��, �� �������������� ����, ��������. �����! ��� ���� ������� ������ �����: ���� � ����. ���� ��������� �� ����� ������ ������� ��������� ��� �������, �������, � ����� ����� ����� '���������'.";
			link.l1.go = "camilla_30";
		break;
		
		case "camilla_30":
            dialog.text = "�� ��� ����, �������. ����������� ��������!";
			link.l1 = "��-��-��!";
			link.l1.go = "camilla_31";
		break;
		
		case "camilla_31":
            DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("Roger_10", "2");
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
			pchar.quest.mtraxx_retribution_carataska.win_condition.l1 = "location";
			pchar.quest.mtraxx_retribution_carataska.win_condition.l1.location = "shore10";
			pchar.quest.mtraxx_retribution_carataska.function = "Mtraxx_RetributionCarataska";
			pchar.questTemp.Mtraxx.Retribution = "carataska";
		break;
		
		case "camilla_sleep":
            dialog.text = "���� �������� ����� ����� ���� � �������. ����� ������ ������ � ��������� �� ��������, ��������, �� ����� �����, � ������� �� ������ �� ����\n�������, ���� ������ � ������ �������� ����� ��� �� �������, ��� ���� ������� ������� ���������, ����� ���� ������ ��������� �� ������ � � �����. �� ������ ������ � ���, "+pchar.name+" �����.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep4");
		break;
		
		// ��� ������ - �������� ��������
		case "enrico":
			PlaySound("VOICE\Russian\OliverTrast01.wav");
            dialog.text = "���� ��� ���������� ��� ������� ������������, ������ ��������� �� ���, ��� �������� ���� ����� ����� � �����!\n�������� ����� ������� � ��������������. � ����� �������� ���� ��������� ���...";
			link.l1 = "����!.. �� ��� �����?!";
			link.l1.go = "enrico_1";
		break;
		
		case "enrico_1":
            dialog.text = "� - ��� ������. ���������� ������� ����� ���� ����, ����������� - ���, ����������� - �����. �� � ����������� ���� �������� �� ������ ��������� - �����. � ����� ������� ���������, ����������� ���� � ��������� ������� �����, ���, �� ������� ������ ������ �����������\n������� ��������� ��� ��� �������� �������� ������� �������: ����� �������, ������� �����, ����� ���������� � "+pchar.name+" �������, ��������� �������� ����� � ��������� ������� ��������� � ������. ���������, ����� ������� - ��� ���������, �������� ����������� ������ � �� ������...";
			link.l1 = "���?!!";
			link.l1.go = "enrico_2";
		break;
		
		case "enrico_2":
            dialog.text = "�� �� �����, "+pchar.name+" �����, ���� � ����������� ��������. � �����, �� ��� ��� �����. ��� ������ ���� ������������ ����, ��������� � �����, ��������� ����������� ��������� ����������������, � ������� ��� ����, � ��� ����������, ��� ��, ����������� ��������������� ���������� ����� ����������� ����� - ���������, ��������, ��������� � ���������������� - ���������� ���� �������. �������� - ������������ ���������!";
			link.l1 = "�������... � ������ ��� ������, ��� � ���� ������ ���-�� �� �����!";
			link.l1.go = "enrico_3";
		break;
		
		case "enrico_3":
            dialog.text = "������� �� ����� ������� ���� ��������� ������ � ��������� � ����� � ��������, ���������� ����� �����, ���� �� ������ ��, "+pchar.name+" �����, ������ � ����� ����� �����������. ���� ������ ����� ���� ������� ���� ����������, � ��� ��������� ������� ��� ���������, ���� �� ��������� �������� ����� ������� ����. �� ��������� ������� ����. ����� ������� ����������, ������� ����� ���� �� ��, ����� ��������� ������� � ��������, �������� � ������ �� �����. � ����� � ����������� ����, ��� ��� ����������� ��� ����\n�������� ����� ��������� ���� ������� � ������, ������ � ��������. ���� �������� ������ �������� ������� ������� � ��������� �����, �������� ������������ �� ������ ������. ������ ��� ���� � ���������... �� ������ �� �����, ������! �������� � ���! �������� � ��, ������� �������� ����� ������, �����, ������� �� ������� �������, �������� ����������. ������� ������, �����, �������� ���� �������� ����� ��� ����������\n������� ����������� ����� ������! �������, ��� �� ������ ���������� ����� ������ ����, � ��� ����� ������ �����!";
			link.l1 = "� �� ����� ������ �����! ����� � ����� �� ����������, ���� ��� ������. � �� ������� �������...";
			link.l1.go = "enrico_4";
		break;
		
		case "enrico_4":
            dialog.text = "�� ������ ��������������� �� ��� �������� ����� �������. �� ��� �� �������� � �������. �������� ����� �� ����� ���, ��� ���������� �������, � ��� ������ ���� � ��!";
			link.l1 = "������ ��-�� ���� �������! ��? ������� �� ����! �� �� � ����� ������?";
			link.l1.go = "enrico_5";
		break;
		
		case "enrico_5":
            dialog.text = "���, "+pchar.name+" �����. �� �� ������ �� ���� ������ - ��� ����������... � ����� ��� �� ����� ����, �� ������� ������ - ������� ������ ��������� ��� ������ �������� �������. �� ���������� �����, � ���� ����������� � ������, ��������. �����, ����� ������� �� ���� �����, ������� � ������� ���������� ������� �������. ������ �����, ����� ������� ���� �, ���� ����� �������, � ����� ����, ��� ��������� �� ������� �������� ��������. � ������ ������� ������ ���\n����� ���� ����, ��� ��� ��������� �� �����, ���� ����� �� ����� ����. � ���� ����� ����� ������� �������� ��� ������ ����������. ����������, ����, � ������ � ����� ����������, ���� �����, �� ���������� � ��� ���, ������� �������� �����, ����� ��� ��� ������ ��� ������� � ���\n�� � ���������� ������ ����, ��� ��������� ����� - �� ���������. ��� ���������. ������ - ������������ ������, � ������� ����� �������� ������ ��������, ����������� �������. �� ���������� ���� ����� ������ �� ��������, �����. ��������� ������� ��� �������! � ������ - ������. ������, "+pchar.name+" �����, �� ���� ������� ����, ���� ��� �� �����, ��� ��� ������...";
			link.l1 = "����!..";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionEnricoGo");
		break;
		
		case "mishelle_sleep":
            dialog.text = "�������� ���, ���� - ��� �� ����������� � ������ �������? ����� � ������� ���� ������������� � ��������, � �� ���� � ���� ���� ������, ������� ������ ����������, ���������� ��� ���������. ���� ����� ����� ����� �������� � ����������!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep5");
		break;
		
		case "mishelle_sleep_1":
            dialog.text = "����! ����!\n�� ������� ����, ����?\n�� ����� �� ���� ������ ���� ������. ����� ����� �������. ���� ����� ������ ������ �� ����\n��� ��� �� ����������. �� ����������!..";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep7");
		break;
		
		case "terrax_sleep":
            dialog.text = "��-��-��, ������, ������ ���������! �� ���� ����� ��������? ����, ������, ���, ������� - ���� ���� �� �������? �������, ��� � ������ ���� � ���� ������ �������? ��� ��� ����� ����, �� �������� ������ ����� � ������� ������� �������� �����. �� �������� ��� ��� �������! �� ���� ��������� �������, "+pchar.name+" �����! ��-��-��-��!";
			link.l1 = "";
			link.l1.go = "terrax_sleep_1";
		break;
		
		case "terrax_sleep_1":
            dialog.text = "��������� �������! ��-��-��-��!!";
			link.l1 = "";
			link.l1.go = "terrax_sleep_2";
		break;
		
		case "terrax_sleep_2":
			Mtraxx_RetributionSleepSkeletons();
            dialog.text = "��-��-��-��-��-��!!!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Mtraxx_RetributionSleep6");
		break;
	}
} 
