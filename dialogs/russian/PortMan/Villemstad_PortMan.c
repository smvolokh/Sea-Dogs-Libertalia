// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����������, ���� �� �� �� ����� �����, �� �� ����� ���� ��������� ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "��������, �� �������� ���� ���� ������ �� ����������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//������������
			if (pchar.questTemp.Slavetrader == "EscapeSlaveVillemstad_P")
            {
    			link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ������ �� ������ �����, ���������� � ���� ����� ��������� �����.";
    			link.l1.go = "EscapeSlave_Villemstad_P1";
            }
			//����������� ������, ������ ����
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "SeekFleut")
            {
    			link.l1 = "� �� ����� ����� �������� �� ����� ���� ������. � ���� ����� ��� ��������� '������'. � ���������� ����� ����, ��� �� ������������ ������ � �����������, ��� ���, �����, ������ ��� ��� ��� ����� �� ��������.";
    			link.l1.go = "SeekTradeFleut";
            }
			//���, �����
			if (pchar.questTemp.Headhunter == "Rat" && pchar.questTemp.Headhunter.countV == 0)
			{
				link.l1 = "������"+ GetSexPhrase("","�") +", �������, �� ������ �� ������ �����, ������� �������� �����. �� ������ ���������� �� ���� �����������?";
				link.l1.go = "Rat_portmanV";
			}
		break;

		//������������
		case "EscapeSlave_Villemstad_P1":
				dialog.text = "��... � � ����� ����� ����� ��� ��� ��������������?";
				link.l1 = "� �������� �� ��������� ������� ����, �����������. ���� ��������� ��������, ��� � ������������ ������� ��������� ������ ����. ������� � ����� ��� ������� ��� ��� ��������� ���������� � ��������.";
				link.l1.go = "EscapeSlave_Villemstad_P2";
		break;
		
		case "EscapeSlave_Villemstad_P2":
				dialog.text = "�������. ��, � ���������, � ���� ��� ���� ��� ������. ���� � ������ " + pchar.questTemp.Slavetrader.ShipName + ", ������ �����, ����� ������ �� ����� � �� ������. ��������� ����� ���������\n������ ������� �� ������� ������ ������ �� ���, ����������, ������ ��� ������� ������ �� ����. ����� ��� �����������, ��� ������� ��������� �����, ���������� � �������...";
				link.l1 = "�� ��, ������������� ���������� �������. �� ������� � �� ����. �� ��������.";
				link.l1.go = "exit";
				AddQuestRecord("Slavetrader", "22_3");
				AddQuestUserData("Slavetrader", "sShipName", pchar.questTemp.Slavetrader.ShipName);
				pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_H";
		break;				
		//����������� ������
		case "SeekTradeFleut":
			dialog.text = "���� ������? �� ������� �� � ��� ����! �� ��������� ���������� ����� ����� ������������, ���-���� �� ��������� � �������. ������� �� ����� �� ��������. �����, ��� �� ��� ��� �������.";
			link.l1 = "�������!";
			link.l1.go = "SeekTradeFleut_1";
		break;
		
		case "SeekTradeFleut_1":
			DialogExit();
			pchar.questTemp.HWIC.Self = "FleutOnTrinidad";
			AddQuestRecord("Holl_Gambit", "3-59");
			pchar.quest.Seek_Fleut.win_condition.l1 = "location";
			pchar.quest.Seek_Fleut.win_condition.l1.location = "Trinidad";
			pchar.quest.Seek_Fleut.function = "CreateTradeFleut";
		break;

		//���, �����
		case "Rat_portmanV":
			dialog.text = "��, ���� ������ �����, ��� ����� ����, ������� ������ '����� ����' ����� �� ������, �, ��� �������, �� ������ � ��������� �����. ������ ��� ����� �� �����, � ������ ��� ��� ���������?";
			link.l1 = "���, ������ ���, ������� �������. ������� ������������ �� ����������?";
			link.l1.go = "Rat_portmanV_1";
		break;
		
		case "Rat_portmanV_1":
			dialog.text = "��� � ���� ����������, �������� �������... ��, ��� ����� ������ � ������� ������ '����� ����' ������ � ������ ������� ������ �� �����, ����� �������� ������. ���... � ���� ���������� �� ������. ����� �� � ���.";
			link.l1 = "�������, � ����� ������� ����� �� ������ � ��� �� ����, ��� ���� ����� ����� �������?";
			link.l1.go = "Rat_portmanV_2";
		break;
		
		case "Rat_portmanV_2":
			dialog.text = "������� ���������. � ��� ���� �������� ���� �������: ����� '��������', ������ '����������' � ������ '�������'.";
			link.l1 = "�������!";
			link.l1.go = "CheckV";
			pchar.questTemp.Headhunter.count = sti(pchar.questTemp.Headhunter.count) + 1;
			pchar.questTemp.Headhunter.countV = 1;
		break;
		
		case "CheckV":
			if(pchar.questTemp.Headhunter.count == 3)
			{
				pchar.questTemp.Headhunter = "Rat_Tavern";
				pchar.questTemp.Headhunter.Ratrumcity = npchar.city;
				AddQuestRecord("Headhunt", "13");
			}
			else
			{
				AddQuestRecord("Headhunt", "12_3");
			}
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

