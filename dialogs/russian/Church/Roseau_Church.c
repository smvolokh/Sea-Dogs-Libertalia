// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "?", "���������, � ������ ����..."), "� ������ ����, ������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "� � ������ ��� ������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "����� � �� ��������� ������ ��������� �������� � �������, ������ �� ������� �� ���� ������� ����?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
		break;

			// ���� ��� �������-����

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "���, ��� ���!!!";
		link.l1 = "� �� ������ ��������� �� �������?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "� ���� � ���� � ���� �����! ���� �� ����� ����� �������!!!";
		link.l1 = "����� ��� �� ������ ������ ��� ��������� ����� ������ ����?";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "� �� ���� �����, � ����� ���� ������� ��� ���, �� ������, ��� ���������� ���������, ��� �� ��� ��� �� ��� �� ����.";
		link.l1 = "�������, ��� ����.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}