// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ��� ����� �� ���������� ������ ������, � �� ��� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_2" && !CheckAttribute(npchar, "quest.patria") && !CheckAttribute(pchar, "questTemp.Patria.Visiter_Late"))
			{
				link.l1 = TimeGreeting()+", ���� ���������. � ������ �� ���������� �������-����������� ������� �� ������. � ��� ������ ������ ��������� �� ��������� ������ ����� �����, ���������� �� ���������� � ����� ��������� ����������� ������� ��� ����������� ����������� ����������� ����-������� �������� ��������. ��������� ����������� ��� ������... ��� ���������� ������� ��� ��������������� �� ���.";
                link.l1.go = "patria_portpax";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("�� ��� ��� �������. ��� ��� ��� �����?", "������� �������� ��� ���-��, ��� �� �� ����������?");
            link.l1 = RandPhraseSimple("������������ ����������...", "��������, ����� �����"+ GetSexPhrase("","�") +" ��� �������...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		// Jason ���
		case "patria_portpax":
			dialog.text = "����� ��� ������� � ����, ������� "+GetFullName(pchar)+"! , � � �������. � ������ ��� ��������� ��� ����, ����� ���������� ����� ����� � ����� ������� ���� ����������� ����������. � ��������� ���, ��� ����� ������������������ ����� ������� ��� �����, � ���� ��������������� ��� �� ����� ����.";
			link.l1 = "����� ���������! ���������, ���� ���������.";
			link.l1.go = "patria_portpax_1";
		break;
		
		case "patria_portpax_1":
			dialog.text = "� ��������� ������ ���� ������� �� ���� �� ������� �� ���� ������������� �������-�����������, ������ ��� ��� �� ����-���������� ������ ������! � ��� ��������, �������, ������� ������ ������� ��� ��������� ����� ��������� � ������� ����������� ��������� � ��������� �� ������ ������� ��� ����� � �����, ������� ���������! ��� ���������� �������, ���� �������� �������� � ���� ������� ������ ��������, ��� � �������� ���������� ������ ��������� �������, � ��� ��� ��������� ��������� ����-�-�����!";
			link.l1 = "�������� ����������, ���� ���������?";
			link.l1.go = "patria_portpax_2";
		break;
		
		case "patria_portpax_2":
			dialog.text = "� �� ���������� ������� �������������, �� ����� ������ ���������� �� ���������� ������ ����� �� ����� ���� ������ �������� �������. ���� ������� ����� ����� ��� �������, � ��� ����� ������ ���������, � ��� ����� ������ ����� ���������. �������� ��� ������� ��� ���� ����������� �� ����� ������������ - �����������!";
			link.l1 = "� ����� � �������� ���� ����� � ����������� ������ ������� �� ������. ������, �� ������ ���������� ����.";
			link.l1.go = "patria_portpax_3";
		break;
		
		case "patria_portpax_3":
			dialog.text = "���������, �������...";
			link.l1 = "";
			link.l1.go = "patria_portpax_4";
		break;
		
		case "patria_portpax_4":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_9";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "governor1");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
			npchar.quest.patria = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

