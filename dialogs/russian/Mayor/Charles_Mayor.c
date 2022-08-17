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
			//--> ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "saga" && !CheckAttribute(npchar, "quest.saga"))
			{
				link.l1 = "� ���� ����������� � ������� �� ������, �� ������ ����� ������ �� �����.";
                link.l1.go = "puancie";
			}
			//<-- ����� ��������
		break;
		
		case "puancie":
			dialog.text = "�-�, ��, � � ����� ����� ����... � ��� ���� � ����� ��������� �����?";
			if (sti(pchar.money) >= 1000000)
			{
				link.l1 = "�������! � ��� �� �����?";
				link.l1.go = "puancie_1";
			}
			else
			{
				link.l1 = "���, ����� ����� � ���� ���� ���.";
				link.l1.go = "puancie_exit";
			}
		break;
		
		case "puancie_exit":
			dialog.text = "����� ���������, ����� ��� � ��� �����, � �� ���������� ������� �� ��������.";
			link.l1 = "...";
			link.l1.go = "exit";
		break;
		
		case "puancie_1":
			dialog.text = "� ����� ������ ��������� � ����� ������. ������� ������ ���.";
			link.l1 = "�������!";
			link.l1.go = "puancie_2";
		break;
		
		case "puancie_2":
			DialogExit();
			npchar.quest.saga = "true";
			bDisableFastReload = true;//������� �������
			LocatorReloadEnterDisable("Charles_townhall", "reload1_back", true);//����� �� �����
			LocatorReloadEnterDisable("Charles_townhall", "reload3", false);//������� ���� � ������
			ref sld = characterFromId("Puancie");
			ChangeCharacterAddressGroup(sld, "Charles_Roomtownhall", "sit", "sit1");
			LAi_SetHuberType(sld);
			sld.dialog.currentnode = "saga";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

