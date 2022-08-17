// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
                                          dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
		link.l1 = RandPhraseSimple("� ���������...", "������ ��� �� � ��� ��������");
		link.l1.go = "exit";

	                     // ���������� ���� ���� �������
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_MaryCelesteChurch" && !CheckAttribute(npchar, "quest.APS_MaryCelesteChurch"))
		{
		link.l1 = "�����, � �� ����� ������ � ������ �������� ���������� ����� � ��� ������� ���� �����, ���� ��� �������� �� ����� �������� ����� ������. ��� ��������� � ����� ������!";
		link.l1.go = "MaryCelesteChurch";
		}
		break;

		case "MaryCelesteChurch":
		dialog.text = "������ �� ������������� ����� ������.";
		link.l1 = "� ������� � � ����� �����������, ������ � ������ � ��������� �� ����� ����� �����, ��� �, � ���������� �����������, ����� ��� ������������.";
		link.l1.go = "MaryCelesteChurch_1";
		break;

		case "MaryCelesteChurch_1":
		dialog.text = "������������ ����� ��� �� � ���. ���������, ���� � ������� ���� �����, ��� ��������� ����� ��� �����, � ��� ����, ��� � ����� ��� ������� ������, ��� ��������� ���������� � ������������. ��� ���������� ���� ������� � ����������, � ������� ������ ��� ���� �����, ����������� ��� �������� ������. ��� ���� ������� �������� � ����, ��� ���� �������� � ������ ����.";
		link.l1 = "�������, �� ��� ��� ������, ��� ���������!";
		link.l1.go = "MaryCelesteChurch_2";
		break;

		case "MaryCelesteChurch_2":
		dialog.text = "����������� � ������.";
		link.l1 = "������ �� �������, ��� �����������, ������� �� ���� ���?";
		link.l1.go = "MaryCelesteChurch_3";
		break;

		case "MaryCelesteChurch_3":
		dialog.text = "����������� �������, ����� � ������ ��� �� ������ �� ���� ����� 40 ��� �� �����, � �� ����� 2 ����. � ������� ���� ��� ������� ����� �� ���� ������, ������� � ��������� �� �������, ����� ��� ������ ����.";
		link.l1 = "� ���� �� ����?";
		link.l1.go = "MaryCelesteChurch_4";
		break;

		case "MaryCelesteChurch_4":
		dialog.text = "��, �� � ��� �� �� ������, ��� � � ���������. �� ���� ��� ��� ����� ��������� ��� 25 ������ �������, ������ ��� ��� ��� ����� ��������� ��� ��� 60 ���, � ����� ��� ���� � �� �����. ������� � �������� ��� ����������, ��� �� � ����� ������ ���� �����, �� ���, �� � ���� �����, � ������ ��, ��� ���.";
		link.l1 = "����� � ���� ���������, � ���� ������ ��������, � � ����, ���� � ��� ������ �� ����������, ����� �������� ��������� � �������� � ����� ��������� ��������?";
		link.l1.go = "MaryCelesteChurch_5";
		break;

		case "MaryCelesteChurch_5":
		dialog.text = "���� �� ����, ���� �� � ��� ��������. ���� � � ���� ������ ���. ���� �� �������� ������ � ���� ��������, ��� ���� �� �������, ����� ��� � ���������� �������� �� �������� � ��������� �������. ��� � ���� �� ������...";
		link.l1 = "���������, �����...";
		link.l1.go = "MaryCelesteChurch_6";
		break;

		case "MaryCelesteChurch_6":
		dialog.text = "������, ��������, ��� ������ ��������� � ������, ������� ���������, �� ������ ������ � ���������� � ���.";
		link.l1 = "�������, �����.";
		link.l1.go = "MaryCelesteChurch_7";
		break;

		case "MaryCelesteChurch_7":
		dialog.text = "�� ������� ���� ������� - ��� ���.";
		link.l1 = "...";
		link.l1.go = "exit";
	                     npchar.quest.APS_MaryCelesteChurch = "true";
		AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_2");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

