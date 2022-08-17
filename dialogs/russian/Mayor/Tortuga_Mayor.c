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
			// Addon-2016 Jason, ����������� ���������� (���) �������
			if (CheckAttribute(pchar, "questTemp.FMQT") && pchar.questTemp.FMQT == "huber")
			{
				link.l1 = "����� ����������, � ���� ��� ��� ���������� ��������. ���� ������: ���� ���� ����� ��� ��������. ��� �������� ��������� ���� �� ����� ������ �� ����� ��������. ������ ����� ������ ��� �� ���� ��������.";
                link.l1.go = "FMQT";
			}
			// Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_2" && !CheckAttribute(npchar, "quest.patria") && !CheckAttribute(pchar, "questTemp.Patria.Visiter_Late"))
			{
				link.l1 = TimeGreeting()+", ���� ���������. � ������ �� ���������� �������-����������� ������� �� ������. � ��� ������ ������ ��������� �� ������� ������ ����� �����, ���������� �� ���������� � ����� ��������� ����������� ������� ��� ����������� ����������� ����������� ����-������� �������� ��������. ��������� ����������� ��� ������... ��� ���������� ������� ��� ��������������� �� ���.";
                link.l1.go = "patria_tortuga";
			}
		break;
		
		case "FMQT":
			dialog.text = "���-�-�? �����? �����! ���� ��� ��� �� �������, � ���������� �� ����. ������� �������� � ������. � �� ��� ��� ��� �������? ���!";
			link.l1 = "� �����, ���...";
			if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) > 25) link.l1.go = "FMQT_2";
			else link.l1.go = "FMQT_1";
		break;
		
		case "FMQT_1":
			AddMoneyToCharacter(pchar, 1000);
			dialog.text = "���� ��� ����� ���� � �� ��! �����, ��� ��, ��� ����� � ���� � �����! � ������ ����������!";
			link.l1 = "�������, ���� �������. ����������.";
			link.l1.go = "FMQT_3";
		break;
		
		case "FMQT_2":
			AddMoneyToCharacter(pchar, 1000);
			GiveItem2Character(pchar, "pistol6");
			GiveItem2Character(pchar, "purse1");
			Log_Info("�� �������� ������������ �������� � ������ ��������");
			dialog.text = "���� ��� ����� ���� � �� ��! �����, ��� ��, ��� ����� � ���� � �����!.. ����, �����, �� ����� �� �� ���� ������� � �����������, �������� ����� ��� ������. ����� ��� ������... � ������ ����������!";
			link.l1 = "�������, ���� �������. ����������.";
			link.l1.go = "FMQT_3";
		break;
		
		case "FMQT_3":
			DialogExit();
			pchar.quest.FMQT_late1.over = "yes";
			ChangeCharacterNationReputation(pchar, FRANCE, 5);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			pchar.questTemp.FMQT = "end";
			FMQ_Count();
			AddQuestRecord("FMQ_Tortuga", "7");
			CloseQuestHeader("FMQ_Tortuga");
			FMQT_ClearChest();
		break;
		
		// Jason ���
		case "patria_tortuga":
			dialog.text = "������, ������� "+GetFullName(pchar)+". ������ � ���� ������� ����� ������ ��������������� ��� ��������� ����� � ���������� � ���������� ��� ����������.";
			link.l1 = "";
			link.l1.go = "patria_tortuga_1";
		break;
		
		case "patria_tortuga_1":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_5";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "governor1");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
			npchar.quest.patria = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

