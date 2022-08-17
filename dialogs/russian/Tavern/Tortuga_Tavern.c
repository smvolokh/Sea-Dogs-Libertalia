// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��� �� "+ GetSexPhrase("�������","��������") +" ��� ������� ���� � �� ��...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "�� ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatTortuga") // ������������
            {
                link.l1 = "��������, ��� ��� ����� ������� ��������? �� ������ ��� ��� ������� �� �������.";
                link.l1.go = "Tortuga_ratT_1";
            }
			// ��� �� ��������
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "tortuga")
			{
				link.l1 = "� ��� ���� ����. ��� ��� ��� �����?";
				link.l1.go = "terrapin";
			}
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "tortuga1")
			{
				link.l1 = "� ��� ���� ����. ��� ��� ��� �����?";
				link.l1.go = "terrapin_2";
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga")
			{
				link.l1 = "�����, � ���� ������� � ��������� ����� �� ������� ������ ��� ��������� '�����-���������'? ���� �����, � �������� ���������� �����?";
                link.l1.go = "guardoftruth";
			}

			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Jeweller"))
			{
				link.l1 = "��������, ��� ����� �������� �� ����� ������ ���������. ��� � ���� ��� �����?";
                link.l1.go = "mtraxx_jew";
			}

             //���. �������, �����. ������, ��� ����� �� ����.
            if (pchar.questTemp.GothicLee == "SeekBible_toTavern")
			{
                    link.l1 = "�� �� ������, ��� ��� ����� ����������� ������ �� �����?";
                    link.l1.go = "Gothic_3_1";
				}

        break;
        
		case "Tortuga_ratT_1":
			dialog.text = "������� �������? � ��� ��� �����? � �� ���� �������� � ����� ������.";
			link.l1 = "��, �� ������� ������� '" + pchar.questTemp.Slavetrader.ShipName + "'.";
			link.l1.go = "Tortuga_ratT_2";
        break;
		
		case "Tortuga_ratT_2":
			dialog.text = "�� ���� �� ��������� �������������, "+ GetSexPhrase("�������","���") +". � ������ � ����� ��������� � ��� � ����� �� ����������, � ���������� ����� ����.";
			link.l1 = "�� ������, � ������� � ������ � ��������� ����� �� �����?";
			link.l1.go = "Tortuga_ratT_3";
        break;
		
		case "Tortuga_ratT_3":
			dialog.text = "��, �������"+ GetSexPhrase("","�") +"! ��� �� �������� �����, � �� �������. ��� ������ ������ ���� ����������... ����, ������ � ��� �����-�� �������� �����, ������� ������������ � ���\n����� ������ ������, ��������, � �� ����� ������ ��������, ������ �� ��������� �������. �� ��� � ������� �������� - ���, ��� � �������. �� ������� ��� ����� �� �� ������� - �� � �����, �� �� ����� - �� ������ �������, ��������?";
			link.l1 = "��... �� ��� ��, �������. �������, " + npchar.name + ".";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_8");
			pchar.questTemp.Slavetrader = "wait1";//�������
        break;
		
		// ��� �� ��������
		case "terrapin":
			dialog.text = "��, ����� ���� � �������� �� ������� ���������. ��� ������� ��������� �������� �� ��������� ����������. ��� ������� �� ���� ������� - ��� � ������� �����. �� ������ ����, ������� � ����, �� ����������� ������� ������ � ������ �� ����� �� �����, ���� �� �������� � �������� ����������� ��� � ������� ������. ��� � ���� ������� ����� ����.";
			link.l1 = "�������!  ����� � �����...";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			DialogExit();
			pchar.questTemp.Terrapin = "house";
			sld = characterFromId("Tibo");
			ChangeCharacterAddressGroup(sld, "Tortuga_houseS2", "barmen", "stay");
			LAi_SetOwnerType(sld);
		break;
		
		case "terrapin_2":
			dialog.text = "������� �� ����� ���� ��������� �����, ������ ��� �������� ��������� �� �����������. ���� �������������. � ���� ��� ������? � ��������� ����� �� ��������� ������� � ���� ������� �� ������ �����, ���� � ������ ����� �������. �� ����, ����� ��� ��� �����, ������ ������ �� ���� ������� ����, ��� �������. � ������ ��� ������ �� �������.";
			link.l1 = "�����, � ������ �� � ����";
			link.l1.go = "terrapin_3";
		break;
		
		case "terrapin_3":
			if (stf(environment.time) < 20.0 && stf(environment.time) > 8.0)
			{
				dialog.text = "���. �� ������, ��� ����� ������� �� ������ ������ ������. ������ ����������� �������� ��� � ���� � ��������, �� ��� ���� �� - � �����, ��� �� ���������� �� ���������� ������� � ����.";
				link.l1 = "�������! ����� � ���� �����.";
				link.l1.go = "terrapin_4";
			}
			else
			{
				dialog.text = "��. ���� ������ - ������ ���������.";
				link.l1 = "�������! ����� � �����...";
				link.l1.go = "terrapin_4";
			}
		break;
		
		case "terrapin_4":
			DialogExit();
			pchar.questTemp.Terrapin = "tavern";
			sld = characterFromId("Tibo");
			sld.dialog.currentnode = "tibo_9";
			LAi_SetLoginTime(sld, 20.0, 8.0);
			ChangeCharacterAddressGroup(sld, "Tortuga_tavern_upstairs", "goto", "goto1");
			LocatorReloadEnterDisable("Tortuga_tavern", "reload2_back", false); // ������� �������
			LAi_LocationFightDisable(&Locations[FindLocation("Tortuga_tavern_upstairs")], true);//��������� �������
			LAi_SetStayType(sld);
			// Addon 2016-1 Jason ��������� �������
			if (GetCharacterIndex("Mary") != -1)
			{
				sld = characterFromId("Mary");
				if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && !IsOfficer(sld))
				{
					ChangeCharacterAddressGroup(sld, "none", "", "");
				}
			}
			if (GetCharacterIndex("Helena") != -1)
			{
				sld = characterFromId("Helena");
				if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && !IsOfficer(sld))
				{
					ChangeCharacterAddressGroup(sld, "none", "", "");
				}
			}
		break;
		
		case "guardoftruth":
			dialog.text = "��� �� ��� ��������� ���� ������� - '����� ���������', ��� '����������� ��������', � �� ����, �� � ����� ����� ������������� ��������� ���� ��������� ������, ������ ������. ������ ����� ��� �� �����! ��� �����, ������� ����� �����, ����� ��� ��� ������� ��� � ������� � ��� ���������� ����� ������ - ������ �����, � ����� ����!\n�� ��, ����� �������: �� ��� ������� ���� ���������� ���� �� ����, ����� �� ������ ������, ��� �����. �� � ���� ��� ������������� ��������� ����, ����� ����� �� ��� �����-�� ��������� �����? ������, ������ ������� ������ ���������...";
			link.l1 = "��-��, �� ���� �������, �� ��� �� ������, ��� �����. � ��� ��� ������� ����� ���������� ����? �� ������ �����, �� �������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "� ��� ��� �����. � ��� ����� ��� �� ����� � ���� � �������. �� ��� ����������, ��� ����� ������ ��������� ������ � ���� � ����� ������ ����, ��� ��������. ������� �� ����, ��� ����� ������. �����, �� �������, � ����� - � ��������.";
			link.l1 = "����. �� ��� ��, ������� �� �������, �������!";
			link.l1.go = "guardoftruth_2";			
		break;
		
		case "guardoftruth_2":
			dialog.text = "������ ����������, ����� "+pchar.name+", ����� ���������� ��� ������ �������� ��������, ��������� ���� �� ������! �������� ���!";
			link.l1 = "...";
			link.l1.go = "exit";	
			AddQuestRecord("Guardoftruth", "8");
			pchar.questTemp.Guardoftruth = "tortuga1";
		break;

		// Addon 2016-1 Jason ��������� �������
		case "mtraxx_jew":
            dialog.text = "������, ������ ���������� ��� ���������� � ���������� � ����� ������... ��� ��� ��������� � ��������� �����. ������� �� �������, ��������� ������, �������� � ������� �����, �� ������ � ���� ��� ��� ������, �� ����� ����� � ����� �������. ����������� �������.";
			link.l1 = "�������, �������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_WolfreekJewellerHouse");
		break;

//============================ ���. �������, �����. ������ � ������ �� ����� =======================
  	 	case "Gothic_3_1":
			dialog.text = "�� ������� �� ������ ��� �� �������. ���� ������ ����� �� ���� �� ������. �����, ������, �������� ���������...";
			link.l1 = "� ���� �� ����, ����� �� �� ������?";
			link.l1.go = "Gothic_3_2";
        break;
  	 	case "Gothic_3_2":
			dialog.text = "� ����� ������ ���-�� �� ������� ���������������� �����������.";
			link.l1 = "�������... � � ���� ����� ������?";
			link.l1.go = "Gothic_3_3";
        break;
  	 	case "Gothic_3_3":
			dialog.text = "� ����� ����?";
			link.l1 = "�� ��� ����� ������ �� ����� ������� ����. "+ GetSexPhrase("�����","������") +" ��� � �������-�����, ������ ��� �����. � "+ GetSexPhrase("��� ���������","���� ���������") +", ��� � �����...";
			link.l1.go = "Gothic_3_4";
        break;
   	 	case "Gothic_3_4":
			dialog.text = "�����, ����� ����, ��� ��� ����. ������ �, ��� �� ��������� �� ���� ����� � ��������. �� ���� ����� � ����� ������������ ������ '�������'.";
			link.l1 = "�������. ������� ����, �������.";
			link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_toDeGraf";
            AddQuestRecord("GothicLee_3_SeekBible", "5");
            Pchar.quest.SeekBible_SaveDeGraf.win_condition.l1 = "location";
            Pchar.quest.SeekBible_SaveDeGraf.win_condition.l1.location = "Cuba1";
            Pchar.quest.SeekBible_SaveDeGraf.win_condition = "SeekBible_SaveDeGraf";
        break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

