// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("���������, ���� �� ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��������, ��� �������, ����� ���� �������� ���-��. �� �������� ����!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason --> ����������
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "Findcloves" && !CheckAttribute(npchar, "quest.Portugal"))
			{
   				link.l1 = "����������, ��� ����� ������� ������. ��������, ����� ��������� ���� �� ������ ����������. � ��� ���� ���-�� ��������?";
				link.l1.go = "Portugal_cloves";
			}
			//<-- ����������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "maarten")
			{
				link.l1 = "� ��� �� ��� ����� �������� ���� ��� ������ �� ������� ��� ��������� '��������������'. ������������?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		//Jason --> ����������
		case "Portugal_cloves":
			dialog.text = "���������� ������? ���� �����, ����� � ���� ������ �������� - �����, �����, �������� ������� � ������. ����� 20 000 ���� - ������ ����� ���������, ������� � ����� ������������ ������� ���, ��� ��� �� ������� ����� �� �����.";
			if (sti(pchar.money) >= 20000)
			{
				link.l1 = "�������! ����� �� ����.";
				link.l1.go = "Portugal_cloves_1";
			}
			link.l2 = "��... ������ � ���� ��� ������ �����.";
			link.l2.go = "Portugal_cloves_nomoney";
		break;
		
		case "Portugal_cloves_nomoney":
			dialog.text = "����� ��������, ����� ������ �����.";
			link.l1 = "������. � ����� �������!";
			link.l1.go = "exit";
		break;
		
		case "Portugal_cloves_1":
			AddMoneyToCharacter(pchar, -20000);
			GiveItem2Character(pchar, "suit_1");
			Log_Info("�� �������� ������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "����������, ��������.";
			link.l1 = "�������!";
			link.l1.go = "exit";
			npchar.quest.Portugal = "true";
			sld = characterFromId("PortugalDoctor");
			sld.dialog.currentnode = "Portugal_doctor_4";
		break;
		//<-- ����������
		case "guardoftruth":
			dialog.text = "�� ��. ������ � ����, �������� �����, � � ��� �����������, ��� ��������. � ���?";
			link.l1 = "������� ����� �������, ��� �����, ��� ��������� ��������. ��� � ��� � ����������. �� ����������, ��� �� ����� ������? �����, �� ������������ ��� ��������� �����, ��� �� ��������, ���� ���������� �����������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "�� ��, �� ������. ������ � ��� �� ���������, �� � �� ��� �� ������. ������ ������� �� ������� ����� �� �������. �� � �� ����� � ���� ������������ - ������, ������� � ���� ������ �� ��� ����� ������? � �����, ���������� �� � ����, � ������ ������ ������� �� ����.";
			link.l1 = "����. ��, ������� � �� ����. ����� �������!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			DialogExit();
			AddQuestRecord("Guardoftruth", "11");
			pchar.questTemp.Guardoftruth = "maarten1";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

