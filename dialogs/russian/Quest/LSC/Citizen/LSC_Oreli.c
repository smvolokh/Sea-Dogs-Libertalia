// ����� ������ - ������ ����������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "GenQuest.CitizenConflict") && sti(pchar.GenQuest.CitizenConflict) > 3)
			{
				dialog.text = "� �� ����� � ����� ��������. �� ��������� ��� ������� �� ������ �������, ������������ �� �� �����. ����� �����!";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "������������, ������. ��� �������?";
				link.l1 = TimeGreeting()+". ���� ����� "+GetFullName(pchar)+", � ����� �������, ���, ���������� � ����������� �������.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�, "+GetFullName(pchar)+"! "+TimeGreeting()+"! �� ���-�� ������?";
				link.l1 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
				link.l1.go = "rumours_LSC";
				link.l2 = "� ���� ������ ��� ���� �������� �� �������.";
				link.l2.go = "int_quests"; //�������������� ����
				link.l5 = "�� ������ ����� ������ ��� � ��� ����. ��� ��������!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // ������ �������
			dialog.text = "����. � ���� ����� ����� ������. ����� ������ ��� ���� �������?";
			link.l1 = "������ ��� - ���������� ���������� �� ��������� ������ ��������������.";
			link.l1.go = "meeting_1";
		break;
		
		case "meeting_1":
			dialog.text = "������, �� ���� �� ��� �������, ��� ���������� ���� �� ����������� ����... �� ��� ��, ������ � ��� ����� ���������� �������, ����� � ������������ �� ������, � �������� �� ������ ��� '���������������'.";
			link.l1 = "� ���, ����� �� ��������������� ��������, ��� ����� ������?";
			link.l1.go = "meeting_2";
		break;
		
		case "meeting_2":
			dialog.text = "���, ��� ��... ��� � �������. ��� ������ ������-�� �� ��������� ������� ������� �� ���� �� ��������������, ������� ������ ���� ���������� ��� ����. � ����� ����� ���������� ������������ ������� �� ����� ����� �������, �� ������-�� ������ ��������� �� ������, ����� �� ��� ��� �� ������ ������ ��� �����\n�� ���� �� ����� ���������� ��� ������, ��� �����, � �� �� �� ������� ���� ���� ������ �� �����. � � ��������� - ��� ������, ��� ������...";
			link.l1 = "�������. �����, ��� ����������. ��� ����������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
//--------------------------------------- ���� �������� � ������� ---------------------------------------------
		case "int_quests":
			dialog.text = "������ ���.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "�� ����� ������ �����?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "��� ����������� ���� �� �������?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "��� �� ���������� � ������?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "������ ��� ������� �� ����������?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "��� ��������. ��������...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "�����. ��� ���� � ���� ��������. ��������, ���-�� ����� ����������... ���, ��������, ������������... ��� ��� ��������? � ������� ������ ���?";
			link.l1 = "�������... �� ���� �� - ��������?";
			link.l1.go = "ansewer_1_1";
		break;
		
		case "ansewer_1_1":
			dialog.text = "������������. � ��� ����� �� �������, ����� � ���� ��������� ��������� ���������, � ����� ��������� � ����� ��������� �� �������� ������ �� ������� ����� ������ �� ������ �������� � ������ �� �� ��������. �� ��� � - ��� ����� �����, �� �������� ������, ����� ����� �������, ��������� �������� �����. ��� ��� - ���� �� ���������, � �������� ������.";
			link.l1 = "���������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "�� ��� ��� ���������. ��������, ���������� ����. ���������� ������ ����������� ����� �������. ������� � �������, � �������, � �������. ������, ����� ������ ������� ��������, � ��� ��� ������.";
			link.l1 = "����...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "� ��� ����� ���������� � ���� �����������? ������� �� ��� ��������, � ���. � ���� �� �������� ������� ��� ���� �����-�� ����, �� ���� ����, ��� ����� ��� ������� ������� � �������� ������, �� �� ���� ��������� ������� ������, ����� �����, ������� �� ����������\n��� ��� � ����� �� ����� ����������� �������, ��� � �� ������ ������ ��� �����. ����� ��� ������������� ������� ������������ ���������, � ��� - ������, � �� ����. �������, ��� ��� ���� ���������� ���������� �����������!";
			link.l1 = "������ �����-��...";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "���� �� ������� ����, ��� ��� ���������� ��� ������� �� ���� �� ��������, ��� ������ �� ������� ������� �� ������. ������ - ��������: ����������� ������� ���������, � �� �������� ������� �������������\n�� ��� ����� ���� �� ������� ����� �� �� ����� ������� � �� ������� ������ �� ����� ���������, ���� ����� ����� �������. ��� ��� ��� ���������� �������� � ��������� �� '��������'. �� ��� ������� ��� ������ - ������ ���� ����, ���� �����, ���� �� ������ �� ������. �� ������� ������ ������ ��������� �������...";
			link.l1 = "�������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
		break;
// <-- ���� �������� � �������
		
//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//��������� �� ����������� ������
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("������, �� �� ����� ������. � �� ���������� �������...", "������, � ��� ��� �� ������� ��������� �����������. ����� ������.", "������, ��� ��, ��� �'��������, ������� ���, ������ ������? ����� ������, �� � ���� ��� ���������� �������...");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "��������� �� ���������, ��������, ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� ������� ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����.", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- ����������� �������
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}