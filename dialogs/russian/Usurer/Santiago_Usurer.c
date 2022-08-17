// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//����������� ������, ���������
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripBegin")
			{
				link.l1 = "������, � ������� " + GetFullName(pchar) + ", � �������� ����� �� ��������� ������ ����������. � ���� ��� ��� ����� �� ����.";
				link.l1.go = "SantiagoTripBank";	
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripReturn")
			{
				link.l1 = "� ������ �� ������� ������� ������ ����������.";
				link.l1.go = "SantiagoTripBank_3";	
			}
			//����������� ������, ���������
		break;
		
		case "SantiagoTripBank":
			if (GetCharacterItem(pchar, "Chest") >= 5)
			{
			dialog.text = "�������� ������... �����! ��, ������� ��� ����, �e����.";
			link.l1 = "����� ������ ���������  ������ �������� ��� ���...";
			link.l1.go = "SantiagoTripBank_1";
			RemoveItems(PChar, "NPC_Letter", 1);
			RemoveItems(PChar, "Chest", 5);
			}
			else
			{
			dialog.text = "��������� ��� ��������, ����� ������ ������ ���� ���� ��� ���-���, �������. ��� ��� ��... ���? �� ������, � ��� � ������?";
			link.l1 = "�������! ������� ��� �������� ������� � ���� �� �������. ������ � ������� �� ���������.";
			link.l1.go = "exit";
			}
		break;
		
		case "SantiagoTripBank_1":
			dialog.text = "��-�... ���������. ������ ��, ������ ��, '��������'. ���-���. �������, ��������� �e����� ���������� ������ �����������, ��� ������ �������. ������, ��� ����������� ����� ��� ��������� ������ � ��� �� ��������� ����� �� ��� ������ ����, � ������� ������? ����������� � �������, ��������� �� ������... � ��� � �������� ���� �� ��� ����������.";
			link.l1 = "������, � ����� ������ ����. �� �������, �e����.";
			link.l1.go = "SantiagoTripBank_2";
		break;
		
		case "SantiagoTripBank_2":
			DialogExit();
			pchar.quest.SantiagoTripOver.over = "yes"; //����� ������
			bDisableFastReload = true;
			pchar.quest.Santiago_Trip.win_condition.l1 = "location";
			pchar.quest.Santiago_Trip.win_condition.l1.location = "Santiago_town";
			pchar.quest.Santiago_Trip.function = "SantiagoTrip_Attack";
			pchar.questTemp.HWIC.Holl = "SantiagoTripAttack";
			LAi_LocationDisableOfficersGen("Santiago_town", true);//�������� �� ������� // 291112
		break;
		
		case "SantiagoTripBank_3":
			dialog.text = "��, �������... ��, � �����, �� ����� �������� � ��� ���������� �����������. ������ ��������� ��� �� ������ - '���� ������� ������ �������'. ��� ����� ������, � �� �� ����� ����� ������� ���������, � ���� ����������� ��������� � ������� �����. � �������� ����� ������� ����������� � ������ ����.";
			link.l1 = "������, � �������, �e����. ���-������ ���?";
			link.l1.go = "SantiagoTripBank_4";
		break;
		
		case "SantiagoTripBank_4":
			dialog.text = "��, �������. ��������� ���� - ��� ���� ����� ���������. �, �������, ��������� ��� ��������� ��������� ������� ������. ��������� ��� �����, ������� " + GetFullName(pchar) + ".";
			link.l1 = "� �����. ��������, ������ "+npchar.name+".";
			link.l1.go = "SantiagoTripBank_5";
		break;
		
		case "SantiagoTripBank_5":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "SantiagoTripFinal";
			LAi_LocationDisableOfficersGen("Santiago_town", false);//�������� ������� // 291112
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

