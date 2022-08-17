// ���� ����� - ���������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp;

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
				dialog.text = "� �� ����� � ����� ��������. �� ��������� ��� ������� �� ������ �������, ������������ �� �� �����. ����� �����, ���������!";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "�� �������, ������ ���� �� �������� ���� �������� ��������? ������������ ���� ��������, � ��� �������� ��� �������. ����� � ������ - ��� � ��� �����.";
				link.l1 = "� ���������� � ���� ��������, ���� �����.";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "����� ���������� � ������ ������� ������ �������, ��� ���. ���� �� ������� ���������� ��� �������� ������ - ����� ������ ������� ��� ����. �, ���� �����, ��� �������, ��� �������� ���� ��� ����, ����� �������� ���� ���� � ������� ������.";
				link.l1 = TimeGreeting()+". ���� ����� "+GetFullName(pchar)+". ������� �������������, ���� �����.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�, "+GetFullName(pchar)+"! "+TimeGreeting()+"! �� ���-�� �����?";
				link.l1 = "� ���� ������ ��� ���� �������� �� �������.";
				link.l1.go = "int_quests"; //�������������� ����
				link.l2 = "���� �� � ���������� � ��� �������� �����?";
				link.l2.go = "potion";
				link.l3 = "� ��� ��� �� ������� ���������� ���������, ���� �����?";
				link.l3.go = "amulet";
				link.l5 = "������ ����� �������� ������� � ������, ��� � ��� ����. ��� ��������!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // ������ �������
			dialog.text = "�������, �� ������� �������� ���� ������� ���� �� �������. �� ������� � ����, ��� ���. ����� � ���� ��������� �� ������ ���� ��������, �� � �������� ��������� - �� ����� ������� � �������� ���� �� ������ �������, �� � ������.";
			link.l1 = "� ���� ������ ��� ���� �������� �� �������.";
			link.l1.go = "int_quests"; //�������������� ����
			link.l2 = "���� �� � ���������� � ��� �����-������ �������� �����?";
			link.l2.go = "potion";
			link.l3 = "� ��� ��� �� ������� ���������� ���������, ���� �����?";
			link.l3.go = "amulet";
			link.l4 = "��� ����, ���� �����. ��� ��������!";
			link.l4.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "potion":
			dialog.text = "�������, ��� ���. ����� ����� �� ������� ����������?";
			if (!CheckAttribute(npchar, "potion1_date") || GetNpcQuestPastDayParam(npchar, "potion1_date") >= 1)
			{
				link.l1 = "������� �������� ��������.";
				link.l1.go = "potion1";
			}
			if (!CheckAttribute(npchar, "potion2_date") || GetNpcQuestPastDayParam(npchar, "potion2_date") >= 1)
			{
				link.l2 = "�������� �������.";
				link.l2.go = "potion2";
			}
			if (!CheckAttribute(npchar, "potion3_date") || GetNpcQuestPastDayParam(npchar, "potion3_date") >= 1)
			{
				link.l3 = "�����������.";
				link.l3.go = "potion3";
			}
			if (!CheckAttribute(npchar, "potion4_date") || GetNpcQuestPastDayParam(npchar, "potion4_date") >= 1)
			{
				link.l4 = "�������� ��������.";
				link.l4.go = "potion4";
			}
			link.l5 = "��������, ���� �����, � ���������.";
			link.l5.go = "exit";
		break;
		
		case "potion1":
			npchar.quest.price = 90;
			npchar.quest.type = 1;
			dialog.text = "�������� ��������? � ���� 90 ����, ��� ���.";
			if (sti(Pchar.money) >= 90)
			{
				link.l1 = "����������, ���� �����. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion2":
			npchar.quest.price = 500;
			npchar.quest.type = 2;
			dialog.text = "�������� �������? � ���� 500 ����, ��� ���.";
			if (sti(Pchar.money) >= 500)
			{
				link.l1 = "����������, ���� �����. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion3":
			npchar.quest.price = 200;
			npchar.quest.type = 3;
			dialog.text = "�����������? � ���� 200 ����, ��� ���.";
			if (sti(Pchar.money) >= 200)
			{
				link.l1 = "����������, ���� �����. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion4":
			npchar.quest.price = 900;
			npchar.quest.type = 4;
			dialog.text = "��������? � ���� 900 ����, ��� ���.";
			if (sti(Pchar.money) >= 900)
			{
				link.l1 = "����������, ���� �����. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion_pay":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.price));
			iTemp = sti(npchar.quest.type);
			GiveItem2Character(pchar, "potion"+iTemp);
			PlaySound("interface\important_item.wav");
			dialog.text = "����������. ����� ���� ���������. �� ������ ���� �������!";
			link.l1 = "�������, ���� �����.";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(npchar, "potion"+iTemp+"_date");
		break;
		
		case "amulet":
			bool bOK = (!CheckAttribute(npchar, "amulet_date")) || (GetNpcQuestPastDayParam(npchar, "amulet_date") >= 3)
			if (bOk && GetSummonSkillFromName(pchar, SKILL_FORTUNE) > (10+drand(110)))
			{
				npchar.quest.amulet = SelectLSCChurchAmulet();
				dialog.text = "��, � ���� ������ ���������� �������, ��������� �������� ���� �� ������� ��� �������. ��������� ��������� ��� ���� - ������ ������� ��������. ������� ���� ���������� ���� "+XI_ConvertString(npchar.quest.amulet)+".";
				if (GetCharacterItem(pchar, "gold_dublon") >= 10)
				{
					link.l1 = "��, � ���� ������ ���� ������. ��� ������.";
					link.l1.go = "amulet_pay";
					link.l2 = "� ���� ��� ���� ����� ������, ���� �����. � �������, ���� � ��� �������� ���-�� ���.";
			link.l2.go = "exit";
					SaveCurrentNpcQuestDateParam(npchar, "amulet_date");
				}
				else
				{
					link.l1 = "� ���������, � ���� ������������ �������... ��������, �����.";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "���, ��� ���, � ���������, ������ ������ ���. ����� � ������ ����, ��������, � ���� ���-������ ��������.";
				link.l1 = "������, ���� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "amulet_pay":
			RemoveItems(pchar, "gold_dublon", 10);
			GiveItem2Character(pchar, npchar.quest.amulet);
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�������, ��� ���. ���� ������ ������ �� ������ ����. ������ ���� �������, � �� ������ ���� �������!";
			link.l1 = "� ��� �������, ���� �����.";
			link.l1.go = "exit";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
//--------------------------------------- ���� �������� � ������� ---------------------------------------------
		case "int_quests":
			dialog.text = "����������� ���� ������.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "��� �� ������ �� ������, ���� �����?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "� ����� ������� � ����� �������?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "� ����, ����� ���, ����� ����� ���-������ ����������?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "��� �� ��������, ������� �� �������� �����������, ��������, �� ����� �������� ������?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "��� ��������. ��������...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "��� ��, ��� � ������ ������, ��� ���. �����, �� ������� � ���� �� ������ � ����� �������, �������� �� ����� ������. �������� ������� ������ � ������� � �����, � ������ ����� �� ����� ���, ��������� �� ���� �������� ������� ����� ������ ����.";
			link.l1 = "�������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "������, ��� �������� ��. ����������� �� ����� ������ ������������ ������� ����������, � ������� - ������ ��������� ����. � �������� ����� ��� ���������� ��������� ������, ��������� ��������� ���� ����������� ����. ����� ������� ���� ������� ������, ����� ������ ���, �������� ����� ��� ���� �� ���� ������� ������������� ���� ��������� ����������.";
			link.l1 = "����...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "� ����� ����������, ��������� ������� �� '�������', �� ������� ���, ����� � ������ �������, � ������ ����� �� '����������' - ������� ����������� ������������� �������. ����� ����������� �� ������, ��� ��� - ���� ����� ������� �� �������� �������� �������� ������ ������ ����, ������� ������ �������.";
			link.l1 = "�������!";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "��� � ����� ������� ������, ��� ���. �� ������ � ���� � ������� �� ����. �� ��� ��� ��������� ���������� �������� ��� �������� - ������ ����� ������ ������ �������, �� �� ��� ����� ��� ������� ���� � ��������.";
			link.l1 = "���������. �� ���� ���������.";
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

string SelectLSCChurchAmulet();
{
	string sAmulet;
	switch (drand(3))
	{
		case 0: sAmulet = "amulet_2"; break;
		case 1: sAmulet = "amulet_3"; break;
		case 2: sAmulet = "amulet_6"; break;
		case 3: sAmulet = "amulet_7"; break;
	}
	return sAmulet;
}