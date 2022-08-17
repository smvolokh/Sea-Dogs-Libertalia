// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, "+ GetSexPhrase("��� ���","���� ���") +"?", "���������, � ������ ����..."), "� ������ ����, ������, "+ GetSexPhrase("��� ���","���� ���") +"...", "� � ������ ��� ������ ����, "+ GetSexPhrase("��� ���","���� ���") +": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, "+ GetSexPhrase("��� ���","���� ���") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

		// ���������� ���� ����� ���� -->
	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_ChurchVayne" && !CheckAttribute(npchar, "quest.APS_ChurchVayne"))
	{
		link.l1 = "������ ����, � ���� ���������� � ���� � �������� �����. � ��� ��������� ������ � ��������� �������, ��� ����� ����� �������� - �� �������� �������� ���������� ��� ������ ��� ���� ������: �� ����������� �� ��� �����-���� �������� � ����� ������?";
		link.l1.go = "CharlieVayne_1";
	}
	if (pchar.questTemp.State == "MorrisWillams_ArrestedSeekInfo" || pchar.questTemp.State == "MorrisWillams_ArrestedSeekInfoFather")
            {
                link.l1 = "������ ����, ������� ���, ������� ��������� ��� ����������?";
                link.l1.go = "Step_E6_1";
            }

		break;

		// ����� ���� -->
		case "CharlieVayne_1":
		dialog.text = "���� ����� ����������� ������� ������ ���� ������ � ������. ���, ��� ������� �� ���������� ����������� � ���, � ��� �� ��������. ������, ��� ����, ��� ���� ����������\n�������, ��� ����� ���������� � ����� �������� �'����� - ������ �� ������ ����� � �������� �� ���������� ���������. ������ ��� �� ���� � ���� ��������� ��� - �� �����-�� �� ��� �����������, � � ��� ��� ����������\n�� ����������� ��� � ���, ��� ��� ���������� ���������� � ������. �� ���������, �������, ��� � �� ���� �������� ��� ���������� ����� �����. �� ��� ������ ����� ��� �������, ���� ������  ������. �� ������� ����, ����������� � ��� ����������.";
		link.l1 = "�������. �� ��������, ������ ����.";
		link.l1.go = "exit";
	                     AddQuestRecord("APSH", "2");
	                     npchar.quest.APS_ChurchVayne = "true";
		AddDialogExitQuestFunction("CharlieVayneStart");
		break;
		// <-- ����� ����

                                     case "Step_E6_1":
		dialog.text = "��, �� �������� �������, �� ����� �����.";
		link.l1 = "��� �� �� �������?";
		link.l1.go = "Step_E6_2";
		break;

                                    case "Step_E6_2":
		dialog.text = "��� ������ �������� � ����� �����.\n"+
                          "� �� ����������� ���� ���������� � ����� ����� ���������� �������� ���������. ��� ��������, ��� � ��� ��������� �������� ��� ��� � ���� ���������. ��������, �� ������� �� ���� � ���-�� ������.\n"+
                          "�������� ������� ����������, ��� ������� ��� ������ � ������ ����� � ����������� ���� ��������� � ������� � ������� ����-���� �����.\n"+
                          "� ������ �� � ������ ����� ���������.";
		link.l1 = "�������, ������ ����.";
		link.l1.go = "exit";
		pchar.questTemp.State = "MorrisWillams_ArrestedSeekInfoWomen";
		AddQuestRecord("Eng_Line_6_MorrisWillams", "19");
		AddQuestUserData("Eng_Line_6_MorrisWillams", "sSex", GetSexPhrase("","�"));
            ref sld = GetCharacter(NPC_GenerateCharacter("Gillian Atterbury", "Womenstown_8", "woman", "towngirl2", 5, ENGLAND, 100, false, "quest"));
        	sld.name 	= "��������";
        	sld.lastname = "���������";
        	LAi_SetCitizenType(sld);
            sld.Dialog.Filename = "Gothic_Quest\EngLineNpc_2.c";
            LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
           	ChangeCharacterAddressGroup(sld, "PortRoyal_town", "goto", "goto1");
	LAi_SetFanatic(sld, "PortRoyal_church", "sit", "sit1", 11.0, 14.0);
	break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

