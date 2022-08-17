// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������, " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, ����, ���� ��������
			if (CheckAttribute(PChar, "questTemp.Saga.Shadows") && pchar.questTemp.Saga.Shadows == "sentjons")
			{
				link.l1 = "� ���������� �������� �������, ������� ������. �� ������, ��� �� ��, � ��� ��� ��� �����?";
				link.l1.go = "baker";
			}
			//Jason, ��� �� ��������
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "� ��� ��������� ������. �� �������� � ��������, ��������?";
				link.l1.go = "terrapin";
			}
			// ����� ������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok")
			{
				link.l1 = "��������, �� ��������� �� � ��� � ������ ������-�������, ������? �� ���������, ��� ��������, ����� ����� ��������. �� ������ � �����?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//����, ���� ��������
		case "baker":
			dialog.text = "��� ������� ���� ���������� ���������� �����! ��� ��, ���������. ��� ������ � ������ ��� ������ ���. ����� ����, ��� ������� �����, ��� �� ������������ ��������� ���� ����� ���, �� � ������ ������ �� �������� ���� ������ � ��-��.";
			link.l1 = "���� ��-��?";
			link.l1.go = "baker_1";
		break;
		
		case "baker_1":
			dialog.text = "� ��� � ��� �����. ������������ �� ������ ���������� ����� ����������� ������. ������ ��� ����� ��� ������� ���������, � ������� �������� �� ����� ����� �� �����.";
			link.l1 = "��� ��� ����� ��������?";
			link.l1.go = "baker_2";
		break;
		
		case "baker_2":
			dialog.text = "� ���� ��� ������? �� ��� ��������� ������� �� ����������� � ���� � �����. ��� ������ ���������� '�������� �����'. ����� ������� - ����� � ��������...";
			link.l1 = "������� �� ������, �������!";
			link.l1.go = "baker_3";
		break;
		
		case "baker_3":
			DialogExit();
			AddQuestRecord("Shadows", "2");
			pchar.questTemp.Saga.Shadows = "baldmaggy";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1 = "location";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1.location = "Antigua";
			pchar.quest.Saga_ShadowsMaggy.function = "Saga_SetBaldMaggy";
		break;
		
		//��� �� ��������
		case "terrapin":
			dialog.text = "��������� ������? �� �� ������, ������. ���������� ������� � ���-�� �� ��������, � ������ ������� - ��������, ������������, ������ - ��� ��� ����� ���������. ��� ������ ���� �����, ����� ����������?";
			link.l1 = "� ���� ���� �������� ������ �����. �������, ������ ���������.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "���. �� �������� ������ ������. ������, ��������...";
			link.l1 = "�����, �� ��� - � ���� ���...";
			link.l1.go = "exit";
			npchar.quest.terrapin = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "���, �� ������. �� � ��� ����� ���� ������� � ������, �������� ���� ������. �������� � ���� ������� - �� ����� ������ ��������.";
			link.l1 = "��� �������, �� ��� ������� ��� ��������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "������� ������. � ��� ���� ��� ������ ����� - ���� ������ �� ����� �� ��������, ���������� � ���������, ������ � ��������. � ���� ������� ������� �������, ��������... ��� ����� � ������.";
			link.l1 = "��, �������������������� �������...";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "��������, ��� � ���. �� ��� ��� � ��� ����� ���� - ����� � ���� �� ������ ����� ���-��. ���� ��������� ����������. ���� ����� ���� �����, �� ����� ���� ��������� ����, ��� �� ���������� ��������� ��� �������, ����� ������� ��������� ����, � �� ����� �� ������ ����. ��� � ���������� �, ��� ��������� ���� ������� � ������� ��������� ����� �� �������.";
			link.l1 = "��. ���������� ����������. �������, �������!";
			link.l1.go = "exit";
			pchar.questTemp.Guardoftruth = "merdok1";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}