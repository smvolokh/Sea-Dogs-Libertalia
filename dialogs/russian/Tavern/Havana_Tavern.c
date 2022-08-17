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

			if (pchar.questTemp.GothicLee == "RockBras_toSeekPlace")
			{
				dialog.text = "��������� ���� �������, "+ GetSexPhrase("������","���������") +".";
				link.l1 = "� "+ GetSexPhrase("������","�������") +", ������� �� ������ ��������� �����, ���� ������ ������!";
				link.l1.go = "Gothic_5_1";
				break;
			}	

            if (pchar.questTemp.Ascold == "ToHavanna") // ����� ��������
            {
    			Link.l1 = "������, � ������ ������� ���������� ��������. ��� �����, ��� ����... � ���� �� ���?";
    			Link.l1.go = "Step_A1";
            }
			if (CheckAttribute(pchar, "questTemp.Slavetrader") && pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "��������, �� ��������� �� � ��� � ������ ������� �������? � ���� ������ '" + pchar.questTemp.Slavetrader.ShipName+ "', ���� ���... ";
                link.l1.go = "Havana_ratT_1";
            }
			if (CheckAttribute(npchar, "quest.batabano"))
            {
                link.l1 = "�����, ��������, ��� ��� ����� ���� ����� �� �������? � �������? �� ��� ������ �� ����?";
                link.l1.go = "guardoftruth";
            }
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "��������, � ��� � ����� �� �������� ������� �� ����� ������ ��������? ��������� ������, ����������, ����� ��� � ����������, � ������������� ��������?";
				link.l1.go = "caleuche";
			}
		break;


//******************** ���.�������, �����. �������� ����� ******************

 	 	case "Gothic_5_1":
			dialog.text = NPCStringReactionRepeat("��, �����, ���� ����. ����������� �����, ����� � ���, "+ GetSexPhrase("������","���������") +".", "�� ��� ���������� ���� � �����.", 
				          "����� � �����?", "�� ������� ����� �� ���� �������, ������� � ������ ���������...", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� ����� - �� �����... � ��� � ��� �������? ������ ������� ��� ��.", ""+ GetSexPhrase("���������","����������") +"? �� ��, ��������...", "��, �����, "+ GetSexPhrase("���������","����������") +", ������...", "����� � � ������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("Gothic_5_2", "none", "none", "none", npchar, Dialog.CurrentNode);
        break;
 	 	case "Gothic_5_2":
			dialog.text = "��� ��, "+ GetSexPhrase("������","���������") +". �������� � �������� ���� ��������. � ����� ��� ������ ������ �����...";
			link.l1 = "� ������ �����-�� �� �����?";
			link.l1.go = "Gothic_5_3";
        break;
 	 	case "Gothic_5_3":
			dialog.text = "���, "+ GetSexPhrase("������","���������") +", ��� �� �� �����������. �� ������ ���� - ������������ ������! ����������...";
			link.l1 = "�-�-�, ���� �����. �� ��� ��, ������� ����, ����.";
			link.l1.go = "exit";
        break;

//******************** ����� ��������, ������ � ��������� � �������� ������ ******************
		case "Step_A1":
			dialog.text = "���, �� ��. ���� ����������, ��� � ��� ��� �� ��������� �����. � ��� ���� � ���, ��� ������ ��������� ��������� ������� �������...";
			Link.l1 = "����� �������?";
			Link.l1.go = "Step_A2";
		break;

		case "Step_A2":
			dialog.text = "�� �������, ��������� ������ ��������. ��� �������-���������� ��� ����� �� ������ ������ ���� ������� ���������� ���������. ������� ������ �������: �������, �������, ��������� ������ ������ - ����!";
			Link.l1 = "��� ���� ��! � ���-�� �����? ������ ������� ��� ������������ � ������, � ������ ��� �� �����?";
			Link.l1.go = "Step_A3";
		break;

		case "Step_A3":
			dialog.text = "��� �� ��� �������, ��� ���� �������, ��� �����? ���� ���, ������ �� ������...";
			Link.l1 = "������ �������� � ��� �����. � ���� ����� ���� �������?";
			Link.l1.go = "Step_A4";
		break;

		case "Step_A4":
			dialog.text = "�� ������, �� �� �������������, ��������-���� � ��� � ������, � �� ��� "+ GetSexPhrase("�����","�����") +"? � ����� ���� �����, ���� ����� �������?";
			Link.l1 = "�� �������, ������ ��� "+ GetSexPhrase("�������","��������") +"... ������ �� ������ �����, �� "+ GetSexPhrase("�����","������") +" ������ �������.";
			Link.l1.go = "Step_A5";
		break;

		case "Step_A5":
			dialog.text = "��� � �����, ��� �� "+ GetSexPhrase("�����","������") +". �� ������, ��� ���� �� ��� ���� �� ������ - ��������� ��������� �� ��������.";
			Link.l1 = "�����... ��� � ��� ������ "+ GetSexPhrase("������","�������") +"? �����, �������...";
			Link.l1.go = "exit";
			pchar.questTemp.Ascold = "SeekInformatorHavanna";
			AddQuestRecord("Ascold", "6");
            ref sld = GetCharacter(NPC_GenerateCharacter("FernandoGonsales", "off_spa_6", "man", "man", 28, SPAIN, -1, true, "soldier"));
            FantomMakeCoolFighter(sld, 28, 90, 70, BLADE_LONG, "pistol3", "bullet", 10);
            LAi_SetStayType(sld);
           	sld.name 	= "��������";
			sld.lastname 	= "��������";
			sld.Dialog.Filename = "Gothic_Quest\AscoldNpc.c";
			ChangeCharacterAddressGroup(sld, "Santiago_houseSp2", "goto", "goto2");
            LAi_LocationFightDisable(&Locations[FindLocation("Santiago_houseSp2")], true);
		break;

		case "Havana_ratT_1":
			dialog.text = "�-�, ���� ������� ���? ��, ������� �� �� ���, ��������������. ����� ���� �� �������: �� ����� �� ����� � ������ ���� ����� �� ������. ������� ����������� �� ��������� �������. �� ���-�� ��� � ���� �� ��������, � �� ������� �����.";
			Link.l1 = "� ���� �� �������, �� � �����? � �� ��� ��� � ������ ����� ����� ������, �� ��� ����� ����� �� ����������.";
			Link.l1.go = "Havana_ratT_2";
		break;
		
		case "Havana_ratT_2":
			dialog.text = "� ����� �� ����? �� ������� ������ - ����� �������� ��� ����, ��� ������ ������������ ���������� - �� ����� ���������. ����� ������ � ������������� ������� ����������. �� �� ���� �� �� ��� ���������?";
			Link.l1 = "�������, �� ��� �� ��� �� ��������� �����! � ���, �����"+ GetSexPhrase("","�") +" �� �����"+ GetSexPhrase("���","��") +" ������? �� ��� ��������, � ����� �������� ��� �������, ������� ��� ������ � ������ ��������, �� � �� ���� ��� ��� ��������� - ����� ��� �� ����.";
			Link.l1.go = "Havana_ratT_3";
		break;
		
		case "Havana_ratT_3":
			dialog.text = "�� ����? ��-��-��! �� ������ �� ���� �� ��� ������� �� ������ � �������� �� ���� ����� ����� ���������� ����������... ��, �� �� ������ ������, ������, �� ����� � ������� ��������. � �� ��������...";
			Link.l1 = "�����. ��������, ������� ������� �� ������ ��� ����������. ��� ������, ������� ������ ������� �� �������� �������. ��� ���� �� ����������?";
			Link.l1.go = "Havana_ratT_4";
		break;
		
		case "Havana_ratT_4":
			dialog.text = "��, ����� ���� ��� ��� ���� � ��� �� ����� �������, �� ������, ��� � ������������, ����� �����������������, ��������. �� ������� �� ����������... ���-�� �� ��� ��� ��������� ���� ��������, �� � ��� � �� ����� ������.";
			Link.l1 = "�� �������, ������? �������! �������, ���� ��� � ��� ������. ������� ����, " + npchar.name + ", �� ��� ������� �����. �����.";
			Link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_7");
			pchar.questTemp.Slavetrader = "FindRatTortuga";
			pchar.quest.Slavetrader_findTortugaRat.win_condition.l1 = "location";
            pchar.quest.Slavetrader_findTortugaRat.win_condition.l1.location = "Tortuga_HouseHut";
            pchar.quest.Slavetrader_findTortugaRat.win_condition = "Slavetrader_findTortugaRat";
		break;

		case "guardoftruth":
			dialog.text = "��... � � ���� �� ��� �������� ���������������� ����� �����, �?";
			link.l1 = "��, ��� � ������� - �������� �� �����. � ����� �������� ��� ��� �������, ����������� ������������. ������... ������ ���������? � ���� ��� ����� ������� ������.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "�-�, ��� �� ��������� �� ��� �������������� ���� ��������? �������, ��� ������ ����. ��� ����� �� ������� ����� � ������� ������� �� ���� ��� ��� ��� �����, ������ ������ �������� � ���� �� ���������� �������. ���� �� �������� ������� ��������� ����� �� ���� ���-�� � ����� ����������� ����, ��� �� ������� ����� � ������ ��������� ��� �������, ��� ������ �������\n��� ��� ������� ���������� � ����� �� ��� - ��� ������ ���� � �������, � ��� ��� �����. �� �����, ��� ��� ������ ��� ������ �������� ��������.";
			link.l1 = "�������, ��������! �� ��� ����� �����!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "�� �� �� ���, �����������. ������ ��� ������ �������-��������.";
			link.l1 = "...";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			DialogExit();
			DeleteAttribute(npchar, "quest.batabano");
			AddQuestRecord("Guardoftruth", "47");
			pchar.quest.GuardOT_Batabano.win_condition.l1 = "location";
			pchar.quest.GuardOT_Batabano.win_condition.l1.location = "Shore13";
			pchar.quest.GuardOT_Batabano.function = "GuardOT_SanAntonioPrepare";
		break;
		
		// �������
		case "caleuche":
			dialog.text = "���� ��� �����, �������. �����, � ��������, �� ��� ������ � � ��� ������ �� ����. �� ������.";
			link.l1 = "����. ����. ���� ������ ������...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
