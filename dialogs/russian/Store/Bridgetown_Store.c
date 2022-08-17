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
			//����������� ������
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoBridgetown" && !CheckAttribute(npchar, "quest.HWICTalked"))
            {
                link.l1 = "��������, ��� ��� �� ���� �������, ��� � ������ ����� ���������� ���� �� ������� ������ � �����. � ��� ��� ��������� �������� ������, ����� ����� ���������, ��-��... ���� � ���� ���������� ������� ������ ���� �������. � ���� ������������ �� ������?";
                link.l1.go = "StoreDone";
            }
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "barbados1")
			{
				link.l1 = "� ���� ������� ������� ������� ������ '��������������' ��� ������������� �������� ��� �����. �����, �� ������� � ��� �������, ��� ������ ��� �����������? �� ����������?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "StoreDone":
			dialog.text = "��, ������, ���� ������ ����� ������������� ������� - �������, �����������.";
			link.l1 = "���������! �������, �� ����� �� ��� �� ���� ������ ��������� � ������� ����� ����� - � ������� � ����� ���� �������, � �� � ��� ����, ���� � � ���� � ���� ����� ��� ������, ��������� ��������. � ��� �����!";
			link.l1.go = "exit";	
			npchar.quest.HWICTalked = "true";
			pchar.questTemp.HWIC.Eng.BridgeCounter = sti(pchar.questTemp.HWIC.Eng.BridgeCounter)+1;
			AddQuestRecord("Holl_Gambit", "2-11");
			if (sti(pchar.questTemp.HWIC.Eng.BridgeCounter) == 7) 
			{
				AddQuestRecord("Holl_Gambit", "2-6");
				pchar.questTemp.HWIC.Eng = "SeekVanBerg";
				pchar.quest.GotoBridgetownOver.over = "yes";//����� ������
				pchar.quest.VanBergAttack_Check.win_condition.l1 = "MapEnter";
				pchar.quest.VanBergAttack_Check.function = "VanBergAttackCheck";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "��! � ����� ����� ������! �� ������� ������, ��� �� ��������� � ��������� ����� ������ ��������� ����������� � ������, ������ ��� ����� ���� �������� ������� �������� �������, �������������� � ����������, � ����� ����� �������� ��������\n� �������� ������ ����� ����������, � ��� �� ������ �� �������� ��������, ������ ����� ������� � ����� ������ ��������. �� ������ ����� � ����, ������, ���� � ������ ����������� ���������� ������, ����� ��������� ��� �����\n��, ������, ������ � ��� ������������� ��� ���� ����������. ��� ���, �����, ����, �� � ������ �� ����� ������� � ���, ���� �� ��� �������.";
			link.l1 = "������, �� ������ ����� ���� �� ���������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "������ �����. ��� ����� ����� '������' �� ����� �� ������� ����������, � ������� ������ �� ������ ������ � ������. ���� �� �� ������ ����� - �� ��������� � ���-���� �� ��� ���, ���� ��� �� �������� ����� �� ������, ���� ���� �� ������ ����������, ��� ��� ������.";
			link.l1 = "����. �������, �� ��� ����� �������!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			DialogExit();
			AddQuestRecord("Guardoftruth", "14");
			pchar.questTemp.Guardoftruth = "guadeloupe";
			pchar.quest.GuardOT_guadeloupe.win_condition.l1 = "location";
			pchar.quest.GuardOT_guadeloupe.win_condition.l1.location = "guadeloupe";
			pchar.quest.GuardOT_guadeloupe.function = "GuardOT_CreateTwoShips";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

