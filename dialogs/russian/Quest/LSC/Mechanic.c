// ������ �������. �� �� �������.
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "������ ����, ������. � ��� ������ �� �����. ������� �� �������, ��� ������ ������� �������� �� ��� �����?";
				link.l1 = TimeGreeting()+". ���� ����� "+GetFullName(pchar)+". � ������������� ������� ���, ���, ����, ���������� � ������...";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				if (pchar.questTemp.LSC == "platinum_wait")
				{
					dialog.text = "����������, "+pchar.name+", ���� �� ������ ��������� ����, � ������� �� ������� ������ �������.";
					link.l1 = "��-��, � �����. �������� �� ������������!";
					link.l1.go = "exit";
					break;
				}
				// ����������� �������� ���������
				if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
				{
					dialog.text = "��! ��� ��� ����! ���������� �������� � ���� �����! ��-��, �������������, ��� ��� ������� ���������� ����� ����? ���� ��� ��� ������ � ������ ����������, ���� �� �� � �����...";
					link.l1 = "� �������� - � ��� �� ��� ���� �� ���������. � ���� ���� ����� ����� - � ����������� � ������ ����������, ������� ����� �� ���, � ���������������� �� ��������, ����� � ������� �������...";
					link.l1.go = "return";
					break;
				}
				
				dialog.text = "�, "+GetFullName(pchar)+"! "+TimeGreeting()+"!";
				// ��������� �����
				if(pchar.questTemp.LSC == "mechanic")
				{
					link.l4 = "������, � ������ � ��� �� ����. ����� ������� ����. ��� ��� ���-��� ��������� � ��� ��� �����������, ��� ��� ��� ��� ��������, ����� �������.";
					link.l4.go = "mechanic_1";
				}
				if(pchar.questTemp.LSC == "platinum" && GetCharacterItem(pchar, "jewelry10") >= 11)
				{
					link.l4 = "������, � ������ ����������� ���������� '����������'. �������, ������� �� �������: ���� ��� � ��� ������. ���, �������.";
					link.l4.go = "mechanic_15";
				}
				if(pchar.questTemp.LSC == "underwater_check")
				{
					link.l4 = "��� ����� �, ������. ��� ��� ��� ������? ������� ��������?";
					link.l4.go = "mechanic_20";
				}
				if(pchar.questTemp.LSC == "platinum_add_wait" && GetCharacterItem(pchar, "jewelry10") >= sti(pchar.questTemp.LSC.PtAddQty))
				{
					link.l4 = "� ���� ���� ������ � ��� ����������, ������� �� �������. ��������.";
					link.l4.go = "mechanic_23";
				}
				if(pchar.questTemp.LSC == "underwater_prepare")
				{
					link.l4 = "������������, ������. �� ���, ������ ����� ��� ����������?";
					link.l4.go = "immersion";
				}
				if(pchar.questTemp.LSC == "underwater_natan" && CheckAttribute(pchar, "questTemp.LSC.NatanTalk"))
				{
					link.l4 = "��, � ����� ���� �������� � ����� � ����������. ����� �� ��������?";
					link.l4.go = "immersion_1";
				}
				if(CheckAttribute(pchar, "questTemp.LSC.UW_ready"))
				{
					link.l5 = "������������, ������. �� ���, ������ ����� ��� ����������?";
					link.l5.go = "immersion_next";
				}
				if(CheckAttribute(pchar, "questTemp.LSC.UW_end") && CheckCharacterItem(pchar, "underwater"))
				{
					link.l5 = "� ���� ������� ��� ������.";
					link.l5.go = "immersion_next_2";
				}
				// ��������� �����				
				link.l1 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
				link.l1.go = "rumours_LSC";
				link.l3 = "�� ������ ����� ������, ��� � ��� ����.";
				link.l3.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // ������ �������
			dialog.text = "�� � � - ������ �������. ������, ����������� ������� ������� ����� ���� ��� ��������, ���, �������, ��������� ������������� ������.";
			if(pchar.questTemp.LSC == "mechanic")
			{
				link.l1 = "�� - ������ �������? ����� ���! ������ ��� ������ ��� � � ���.";
				link.l1.go = "mechanic";
			}
			else
			{
				link.l1 = "��, ��������, ������ �� ��� ����?";
				link.l1.go = "meeting_1";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting_1":
			dialog.text = "�, ��, � ���� �������� ������ � ������ ����� ��� ������. ��� ����������� ��������� �� �������� �� ������ �������� �������� �������� ������ ������������ ��������, ������� ��� ����� ���������� � �������� ������� �� ��������������\n� ������, ��� ������� - ������������ � ������� ������������. ��� ��� ��������, ���� �� ����� ������� ��� ���������� ������� - ������������ �������� ��� � ���� ����������� ���������.";
			link.l1 = "�������. � �� ���� ��� �������� ��� ����, ������ �������, ������ ���. ����� ��� ����������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "mechanic":
			dialog.text = "����� ����? � �����, ��������� ��������?";
			link.l1 = "��� ��������� ��� ��� ��� �����������, ���, ��� ��� ��� ��������, ����� �������.";
			link.l1.go = "mechanic_1";
		break;
		
		case "mechanic_1":
			dialog.text = "�, ���� �������� �������! ��-��, ���� ���. ��� �� �� ����� ��� ��� ���� ���������?";
			link.l1 = "������� ���� ����������, ���� ��� ��������� ����� ��... ��� �� ������. ��� ������ ���, ��� �� ������� �������, ��� ���������� �� ���, ��� ����. ������ �� �������� ����������, ���� ��� ������ ��� �������.";
			link.l1.go = "mechanic_2";
		break;
		
		case "mechanic_2":
			dialog.text = "�������? ��� ������ �� �������. � ��� ����� �� ���, � �� ���. ������, ��� ����� �� ���������, ��� �� ��������� ���� ���������� ������ �� ����� ���������� ��������� ������ ���� �������, � �, ��������� ��, ������, � �� ����, � ��������� � ����� ��������� ��� �� �� �����\n����� ����, �� ��� ����� ���������� ��� ��� ��������, �� ��������, �� � ����� ���� ���������� - �������� ������ ������� ���������� �� ������ ��������, ����������� �������� � �������� ������, ������ �� ���, �������� ������� �������\n������ ���� ���������� ����������� ���������� �����, � �� ��������� ���� ������� �� ��� ������ ����� �� �����������, ��� ��� ������ ����� �� �����...";
			link.l1 = "� ��� ���� ������, � ������� ����� ���������� �� ���? � �� ���������?";
			link.l1.go = "mechanic_3";
		break;
		
		case "mechanic_3":
			dialog.text = "�� ������ � ��� ��� � �������, ������� �������. � ��� ������� � ������ ���� ������ �� ������� ��������, ����������� ����������� ������������ �������, � ���������� ���� ��� ����� ��������� ����������������, � ������������� ������������ ������, � ����� ������������ ��������� �����, ������� �� ���������� ��������� � ������� � ��� �����\n� ������ ������ ������������� ����������� � �����������, ������������� � ������������� �� ������ ������������ � �������, � ����� ��� �������� ����� ��� ������������ ��� �������� �� ���. ����� ����, � ������ ������� ������ ������� �������� ������� - ����� �� ��� ��������� ������������ �� ���\n��� ����������� ����� �������� ������� ����������� �������, ����������� ������ ��������, ����������� ��������� ����� ��������� ��� �����. ���� ����������, ��� ��������.";
			link.l1 = "��� ������������. �� �� �������, ��� ��� ������ ������� ����� �� �����?";
			link.l1.go = "mechanic_4";
		break;
		
		case "mechanic_4":
			dialog.text = "� ����������� ���������, ��� ������������� ���. ��������� ����� ������� ��� �������� ��������� � �������� ���������� ����������� ��� ������ ����������� ������������� �������. ������ ������� ���� ������� �� ����� ����������� ����������� - �� ��� ���������� ��� ����������� ���������� ���������, � ������ ������� ���� �������������\n������, ��� � ������� ��� ������� � ����� �� ���������. ���� ���������� �� ������ �����������, ���� ��� ���������� �������, � ������� ���� � ������ ������� ���� ������ ����.";
			link.l1 = "�� ��... �� �� �� ������ �������� ������! ��������� ����� ������ ������ ������������...";
			link.l1.go = "mechanic_5";
		break;
		
		case "mechanic_5":
			dialog.text = "��� ����? ����� ����� ��� ��� ����� �����������? �� ������, ����� ��� ������� ������ - ������� ������ �� ������ �����������, �� ���, ����� �� ��������� �����������? �� ��� ������ ��� ������ ���� ���������� ��������.";
			link.l1 = "��� ���, �� ��-�� ����� ������ ��������� ���� ������������ �������� �� ������?";
			link.l1.go = "mechanic_6";
		break;
		
		case "mechanic_6":
			dialog.text = "���, �������. � ��� ��������, ��� ���� �������. ����� ���������� ����������� �������� �� �������, ������� �� ����������� ��� ������������ ���� � ����. � ����� ������ ����...";
			link.l1 = "��� � ��� �� ��������?";
			link.l1.go = "mechanic_7";
		break;
		
		case "mechanic_7":
			dialog.text = "�������� � ���, ��� ���� ������ ����� �����. � ���� ���� ����� ���� �����, ����, ����������, ������������. ����� ��� ��� ������� ������, � �� � ���������� ����� ������ ��� ���������� ������.";
			link.l1 = "� ��� ��� �� ������ �����?";
			link.l1.go = "mechanic_8";
		break;
		
		case "mechanic_8":
			dialog.text = "�-�, ��� ���������� ������, ������� ��������������� ������. ��� ������� ��������� � ����������� ������������ �� ��������� �������� �� ���� ������� ������������ - �� ����, �� ����, �� �����-���� ������ �������� �� ����� ��� ���������\n��������, �� ��������� ���� ������. �� �����, � ����� �� �������, ������� ������� �������� ��� '�����������'. ���! �� �� � ����� ��� ������ ������� �� ����� ���������! �� ��� ������� - ������! �����-������ ���� ������ ���, ��, �����, ����� ��� �� ������.";
			link.l1 = "����������, � ������ �� �������� ���� ������ �����-�� ������, ��� �� ��� �����? ��� ���� ������������ ��� ������������ ������� ������? � �� ������ ������, ����� ������ ������� ��� �����������.";
			link.l1.go = "mechanic_9";
		break;
		
		case "mechanic_9":
			dialog.text = "� ��� ������ � ����� ��, ������� �������. ��� �� ����� �� ��������. �� � ���������, ���� ����������� �� �������. ��, ��� �� ������ �������, ���� ������, ��� ������ ��� � ������. �� ������ ������� ������ ������, ����� ��������� ������ ������� - ��������� ����� �������\n���, �� '����������' - ������������ ��������� ��������. � ���� ������ ������ ������ �� ����, ���� ���� �� ���� ������������ ���������� ����� ���. �� ����� ����� ������� ��� �� ������� ����������� - �� ����� ����������� � �������� ����� ������� ��������.";
			link.l1 = "��. � ���� � ������ ��� ����� ����������� ���������� ����������, �� ������ ��� ������ ��� ������ ��� ����?";
			link.l1.go = "mechanic_10";
		break;
		
		case "mechanic_10":
			dialog.text = "�� ��� �� ������! �������, ���. ��� �����, � ��� �������: ��� � ��� ���� �� ������ ��-�� ������, � ������ �������� � ��������� ����� ���� �� �����������.";
			link.l1 = "����� �������� ��� ����� ����� �������, ����� � ��� ������, � ��� ���� ����.";
			link.l1.go = "mechanic_11";
		break;
		
		case "mechanic_11":
			dialog.text = "��� �� �������� �� �������? �����������. ���, �������� ���� ����� ��� ������� ��� ���������. ����� ����� ���������� ���� � ����������. �������� ��� �� ������ ������ ��������, �� �� ������ �����������, ��� � ����. �� ������� ����������� ������ ���� ���� �� ��������� ����������. � ���� ������ ����.";
			link.l1 = "������. � ���������� ��������� � �������. �����-������ �������������, ��� ��� ����� ����� � ���������� ������������, � ��� ����?";
			link.l1.go = "mechanic_12";
		break;
		
		case "mechanic_12":
			GiveItem2Character(pchar, "jewelry10");
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� �������");
			dialog.text = "���, ���. ���� �� � ���� - �� ���� ������ ��� �� �� �������������. �� ����� ��� �� ���: ������� �� �������� ����� ������� - � �� ��� �� �����, ��������������, ���� ���������� ��� ������, ��� ������� �������� � ��� ������� ����� � �������.";
			link.l1 = "� ������ ���� ����� � ��������, ������. �������, ��� �������.";
			link.l1.go = "mechanic_13";
		break;
		
		case "mechanic_13":
			dialog.text = "�������� ��� ������ ����� ������. ��� �������, ����������� ��� ������� �������. ����� �����!";
			link.l1 = "�������. �� �������, �������!";
			link.l1.go = "mechanic_14";
		break;
		
		case "mechanic_14":
			DialogExit();
			pchar.questTemp.LSC = "platinum";
			AddQuestRecord("LSC", "7");
			if (GetSummonSkillFromName(pchar, SKILL_FORTUNE) >= 65 || rand(2) == 1) pchar.questTemp.LSC.PtAddQty = 0;
			else pchar.questTemp.LSC.PtAddQty = rand(4);
		break;
		
		case "mechanic_15":
			RemoveItems(pchar, "jewelry10", 11);
			dialog.text = "���-���, ��������... �����������! �������� ������, ������� �������! ��� ���� ������?";
			link.l1 = "��, ��� �������...";
			link.l1.go = "mechanic_16";
		break;
		
		case "mechanic_16":
			dialog.text = "�� ��� ��, ������ � ���� ���������� � ������� �������. �� ���� ����������� ���� � ������ ���� � ����� ������. ���� ��� �� �������� ������� �� ���, � ��������� �������?";
			link.l1 = "������ ���. ����� ���� ����������� ��������� �������.";
			link.l1.go = "mechanic_17";
		break;
		
		case "mechanic_17":
			dialog.text = "��� ����� ������, ������ ��� � ���� ����� ��� ��� ���������, ����� �� ���������� ���� ����������. �� �� ���� �����. ��������� ����� ���� ���� - � �������, � ����� ������� � ��� ��������� � ��������.";
			link.l1 = "������. ����� ��� �����!";
			link.l1.go = "mechanic_18";
		break;
		
		case "mechanic_18":
			dialog.text = "�����, ����������, ����� ������, �� ������ ������� - ��� ������ ����� ������ � ����������� ����. ����� ����, ��� ������� ����� ����� �������� � ����������� ����� � ������� - ����� �� ����� ������ ������� ������� �������� ���������� �����.";
			link.l1 = "����� �� ���� ��� ������. ���������� ����� ���� ����. �� ��������!";
			link.l1.go = "mechanic_19";
		break;
		
		case "mechanic_19":
			DialogExit();
			pchar.questTemp.LSC = "platinum_wait";
			AddQuestRecord("LSC", "8");
			SetFunctionTimerCondition("LSC_PrepareUnderwater_Check", 0, 0, 5, false); // ������
			AddCharacterExpToSkill(pchar, "Fortune", 300);
		break;
		
		case "mechanic_20":
			if (sti(pchar.questTemp.LSC.PtAddQty) == 0)
			{
				dialog.text = "��. �� � ������� ������������ ����������� - ����������� ���� ������� ��� ��� ������� ��� ���������� ������. ������ ������� � ������. ��� �������� ������ �������� ���, �� � ������, ��� ��� ����� � �������. ��������� ������ ����� � ������ ���� - � �������� ���������� ������� ��������, � �� ������� ������� ����������� ���� �������.";
				link.l1 = "�����������! ���, �� �������. ����� �� ������, ������!";
				link.l1.go = "mechanic_24";
				DeleteAttribute(pchar, "questTemp.LSC.PtAddQty");
				AddCharacterExpToSkill(pchar, "Fortune", 100);
			}
			else
			{
				dialog.text = "� �������� ��� ��������, "+pchar.name+". ��� � � �����������, ������� ��������� ������������. � �������� - ��� ���������� ������� ��� ����� ��� ����� ������� � ���������� "+FindRussianQtyString(sti(pchar.questTemp.LSC.PtAddQty))+". � � ����� �������� ������� ��� � ������.";
				link.l1 = "�� ��� ��, � ������ ������ �������� �������. ������, � �������� ������� ����������� ���������.";
				link.l1.go = "mechanic_21";
			}
		break;
		
		case "mechanic_21":
			dialog.text = "� ���� ��� �����. ������ �������, ����� ���������� ��� ����� ������. ��� ������ �� ��������� - � ��������� �� ����� ������� ������.";
			link.l1 = "�������, ��� ��� ���... �� �������!";
			link.l1.go = "mechanic_22";
		break;
		
		case "mechanic_22":
			DialogExit();
			pchar.questTemp.LSC = "platinum_add_wait";
			AddQuestRecord("LSC", "9");
			AddQuestUserData("LSC", "sQty", FindRussianQtyString(sti(pchar.questTemp.LSC.PtAddQty)));
		break;
		
		case "mechanic_23":
			RemoveItems(pchar, "jewelry10", sti(pchar.questTemp.LSC.PtAddQty));
			dialog.text = "������������! ������ ������ ����� ������������. ��������� ����������� ������� � ������ ���� - � ����� ������� � ��� ������ ������, �������, �������� ���������� ��������, � �� ������� ������� ����������� ���� �������.";
			link.l1 = "�����������! ���, �� �������. ����� �� �����������, ������!";
			link.l1.go = "mechanic_24";
		break;
		
		case "mechanic_24":
			DialogExit();
			if (CheckAttribute(pchar, "questTemp.LSC.PtAddQty"))
			{
				iTemp = 2;
				sTemp = "�����������";
				DeleteAttribute(pchar, "pchar.questTemp.LSC.PtAddQty");
			}
			else
			{
				iTemp = 1;
				sTemp = "������";
			}
			if (!CheckAttribute(pchar, "questTemp.LSC.NatanTalk")) string sText = "�� ������ ��� ����������� ����������, � ������ ����������� ����� ��������� ����� � ���������� � ���."; //�� ���� ��������� � �������
			else sText = "";
			AddQuestRecord("LSC", "10");
			AddQuestUserData("LSC", "sText1", sTemp);
			AddQuestUserData("LSC", "sText2", sText);
			pchar.quest.LSC_prepunderwater.win_condition.l1 = "Timer";
			pchar.quest.LSC_prepunderwater.win_condition.l1.date.hour  = 10;
			pchar.quest.LSC_prepunderwater.win_condition.l1.date.day   = GetAddingDataDay(0, 0, iTemp);
			pchar.quest.LSC_prepunderwater.win_condition.l1.date.month = GetAddingDataMonth(0, 0, iTemp);
			pchar.quest.LSC_prepunderwater.win_condition.l1.date.year  = GetAddingDataYear(0, 0, iTemp);
			pchar.quest.LSC_prepunderwater.function = "LSC_PrepareUnderwater";
			pchar.questTemp.LSC = "wait";
		break;
		
		case "immersion":
			dialog.text = "��, ������ �����, �������� � ��������� ��������. ������ ���������� � ����������.";
			if (!CheckAttribute(pchar, "questTemp.LSC.NatanTalk")) // �� ���� ��������� � �������
			{
				link.l1 = "����� ������. �� ������ � ���� �� ���� ����������� ��� ���� - ��� ����� ������ ���� ��������, ���������... ��-�-�... � ����� ���� ��������, ������� ������. ���-�� ����� �� ���� ��� �����. ������ �� ����� ���������?";
				link.l1.go = "natan";
			}
			else
			{
				link.l1 = "�������! ����� �� ��������? ����� ������?";
				link.l1.go = "immersion_1";
			}
		break;
		
		case "natan":
			dialog.text = "�������. ����� �����, ������� �����������. �� �� �� ������ ������ ������ ����� �������?";
			link.l1 = "����������. ��������, � ����� ��� ���� �������. ��� ������ ������� ���� � ��� - ����� �� ����� � ���.";
			link.l1.go = "natan_1";
		break;
		
		case "natan_1":
			dialog.text = "�� ����������. ���������, ��� ������ ������ ���������� �� ���.";
			link.l1 = "�������!";
			link.l1.go = "exit";
			pchar.questTemp.LSC = "underwater_natan";
		break;
		
		case "immersion_1":
			dialog.text = "�� ���� � ����� ������. �� ������� � �������� ��� ��������� ������, ��� ����������. ����� ����������� � ��������� '������' - ������ ���� ����� �������� ������� '���-��������'. �� ��������� ����������� �������, ��� ������ ������� �� ���������� �� ���. � �� �� ������� �� ����������� ������� - ������� ���� �������� �� ������� �� ������� - ������ ����� �����\n��� ��� ���������, ��� ��������� ���� ������� ��� ����� � �� �����������. �����. ������� � ����������� ���������� �� 20 ����� ���������� ��� �����. ���� �� ������������ ���� ������, � ��� ���� ���������� ��� �����, �� �������� �����������. ��� ��� ������� �� ��������\n�� �������� ������ �� ����� �������, ����� � ��� ������ ����� �� ������� ������� ��������� � ��� �����, � ���� ��� ����� ����������� � ������ ���������� � ������� ������� - ��� �������, ��� �������\n���������� �����������, ��� ����� ����� ���������� ������. ���� �� ��������� � ��� ������� ������ - ��� ������� ���. �� ����� ��������� ���������� - ���� ��� ������� �����, ��� �������� ������������, � ������ ��� ����� � ��� ����� �� ���������.";
			link.l1 = "� ������� � ���-������ ���������. ������ ���������� ����� - � ������� �� �����, ��������� ������� � ������� � �� �������� � �������. ����� ����� ����������?";
			link.l1.go = "immersion_2";
		break;
		
		case "immersion_2":
			dialog.text = "���������� ������ ����� ������, �� ������ � ������� ����� �����, � ���� ���� �� ������ ������, ������ ��� � ��� �� �������, ��� �� ��� ����������� ����� � ��������� ����.";
			link.l1 = "�������.";
			link.l1.go = "immersion_4";
		break;
		
		case "immersion_4":
			dialog.text = "�� ��� � ��� ����������. ������ �������� � ��������� �� ���������, ����� ���������� ������� ��� � ��������� ���, � �������� ��� �������� �����. ��! � ���� ������ ������ ���������� � ��� ������ ������ �� �������: ���� ���������������� ���������� ��� ����� � ������� ������ �������� ��������� ������� ����������� �� ��������.";
			link.l1 = "��, ����� ������ ������ ���� � ���� ��� ���� ����� � �� ����.";
			link.l1.go = "immersion_5";
		break;
		
		case "immersion_5":
			dialog.text = "� ���, ��� �� ��� ������� � ��������. ������ ��������, � ����� ���!";
			link.l1 = "�������!";
			link.l1.go = "immersion_6";
		break;
		
		case "immersion_6":
			DialogExit();
			pchar.questTemp.LSC = "first_immersion"; // ���� �� ������ ����������
			pchar.questTemp.LSC.immersion = "true"; // ���������� ��������
			pchar.quest.LSC_takeUnderwater.win_condition.l1 = "locator";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.location = "FenixPlatform";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.locator_group = "item";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.locator = "armor";
			pchar.quest.LSC_takeUnderwater.function = "LSC_takeUnderwater"; // ������ �������
			pchar.quest.LSC_UnderwaterDolly.win_condition.l1 = "locator";
			pchar.quest.LSC_UnderwaterDolly.win_condition.l1.location = "Underwater";
			pchar.quest.LSC_UnderwaterDolly.win_condition.l1.locator_group = "quest";
			pchar.quest.LSC_UnderwaterDolly.win_condition.l1.locator = "dolly";
			pchar.quest.LSC_UnderwaterDolly.function = "LSC_FindUnderwaterDolly"; // ����� ������
			NextDiag.CurrentNode = "after_first_immersion"; // ���� ����� ������� ����������
			AddQuestRecord("LSC", "11");
		break;
		
		case "after_first_immersion":
			if (CheckAttribute(pchar, "questTemp.LSC.immersion"))
			{
				dialog.text = "��, � ������ �� ��� �����? ������ ��� ��� ��������.";
				link.l1 = "��-��, � ���.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "��, ��� ������ ������ ����������?";
				if (CheckAttribute(pchar, "questTemp.LSC.FindDolly"))
				{
					link.l1 = "��� ��� ������ �����, � ������� ������������. � ����� � ���������� ������� �������� ������, � �������, ��� � ������ �� ���������, ������� ����� ��������� ����������������. �������, ������, �� �� ������ ����-������, ��� ��� �� ����������� ����������, ��� ���� ������ ����������?";
					link.l1.go = "af_immersion_1";
				}
				else
				{
					link.l1 = "���������. � ���� ��� ����������! � ��� ���� ����� ���������, ���� � ������� ���������.";
					link.l1.go = "af_immersion_2";
				}
			}
			NextDiag.TempNode = "after_first_immersion";
		break;
		
		case "af_immersion_1":
			dialog.text = "���������������� ����� ��������? ��, ����� ��� ������ ������ � ������� ���������. �� � ��� ������������� ���������, ������� �� �������. �� ����� �� ������ '�����'. ���� ��� �� �� ����� - �� �� ����� �����.";
			link.l1 = "�������! ���� ����� ����������� ������� ��� �����.";
			link.l1.go = "af_immersion_2";
			pchar.questTemp.LSC.Betancur = "true";
			AddQuestRecord("LSC", "14");
		break;
		
		case "af_immersion_2":
			dialog.text = "�������� ������ � ����. ���� �� �������� ��� ��� ���������� �� ��� - ��������� ������ ��� � ����� ���� �����, � �������� ���������� ��������.";
			if (CheckCharacterItem(pchar, "underwater"))
			{
				link.l1 = "�������. ��� ��� ������. �������!";
				link.l1.go = "af_immersion_3";
			}
			else
			{
				link.l1 = "�������. ������ �������!";
				link.l1.go = "af_immersion_wait";
			}
		break;
		
		case "af_immersion_wait":
			dialog.text = "��, �� �������� ��� ����������?";
			if (CheckCharacterItem(pchar, "underwater"))
			{
				link.l1 = "�������. ��� ��� ������. �������!";
				link.l1.go = "af_immersion_3";
			}
			else
			{
				link.l1 = "��� ����!";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "af_immersion_wait";
		break;
		
		case "af_immersion_3":
			DialogExit();
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			LocatorReloadEnterDisable("SanGabrielMechanic", "reload3", false);
			SetFunctionTimerCondition("LSC_ReadyUnderwater", 0, 0, 1, false);
			NextDiag.CurrentNode = "First time";
			// ���� ����� ����-������� � �����������
			sld = characterFromId("Carpentero");
			sld.quest.crab = "begin";
			if (GetCharacterIndex("LSC_Jacklin") != -1)
			{
				sld = characterFromId("LSC_Jacklin");
				sld.quest.crab = "true";
			}
		break;
		
		// ���� ����������, �� ����. �������
		case "immersion_next":
			if (CheckAttribute(npchar, "quest.guarantee")) // ������� �����
			{
				dialog.text = "��, �������. ������ �������� � ��������� ��������, ����� �� ��������� '������' ��� ������. ����������� ����� - 500 ����� ����?";
				if (sti(pchar.money) >= 500000)
				{
					link.l1 = "��, �������. ���, ��������.";
					link.l1.go = "immersion_next_pay";
				}
				else
				{
					link.l1 = "��! ������ �����! ������ �������...";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��, �������. ������ �������� � ��������� ��������, ����� �� ��������� '������' ��� ������.";
				link.l1 = "����� � ����������� ��� ����. �������!";
				link.l1.go = "immersion_next_1";
			}
		break;
		
		case "immersion_next_1":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.LSC.UW_ready"); 
			LocatorReloadEnterDisable("LostShipsCity_town", "reload72", false); //��������� ���� � ������
			pchar.questTemp.LSC.immersion = "true"; // ���������� ��������
			pchar.quest.LSC_takeUnderwater.win_condition.l1 = "locator";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.location = "FenixPlatform";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.locator_group = "item";
			pchar.quest.LSC_takeUnderwater.win_condition.l1.locator = "armor";
			pchar.quest.LSC_takeUnderwater.function = "LSC_takeUnderwater"; // ������ �������
		break;
		
		case "immersion_next_2":
			dialog.text = "������. ���� ������� ��� ���������� ��� ���� - ��������� ������ ��� �����. � ���������� ������ � ������.";
			link.l1 = "�������, �������!";
			link.l1.go = "immersion_next_3";
		break;
		
		case "immersion_next_3":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.LSC.UW_end"); 
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			if (CheckAttribute(npchar, "quest.guarantee")) AddMoneyToCharacter(pchar, 500000); // ������� ������
			LocatorReloadEnterDisable("SanGabrielMechanic", "reload3", false);
			SetFunctionTimerCondition("LSC_ReadyUnderwater", 0, 0, 1, false);
		break;
		
		case "immersion_next_pay":
			AddMoneyToCharacter(pchar, -500000);
			dialog.text = "����� ������� ��� �������� - �������� ���� ������ �����. ��� ��-��������.";
			link.l1 = "�������, �������! ��, � � ����������� ��� ����.";
			link.l1.go = "immersion_next_1";
		break;
		// ���� ����������
		
	//--------------------------------------�������� �� ������---------------------------------------------
		case "return":
			dialog.text = "���������! � ����� ������? �-�, �������, � �������. ��� �� ������ ��� ��������, ������� �����-�� ������� ������ � �������� '���-��������'? ��� ���, ��� ������ ������� - ������������� ������?";
			link.l1 = "������! � ������� ��� �� ������. �� ���������� � ���� ��� ��� ����� ��������, � ��� ��������� ������ ������������ �� �� ������ � ������� �� �����.";
			link.l1.go = "return_1";
		break;
		
		case "return_1":
			dialog.text = "����-����. �������� ��� ��������, ���� �� ������ ����������� ����. ������ ��������� � ������������.. ���! �� ��� �� �������?";
			link.l1 = "�� ����� ������ �������� � �� ������� ��� ���� ������. � ������������� �� ���.";
			link.l1.go = "return_2";
		break;
		
		case "return_2":
			dialog.text = "������. ��, � �������� �� �� ����� ����� ������������, �������, �� ��������?";
			if(CheckCharacterItem(pchar, "underwater"))
			{
				link.l1 = "���, �������. ��, ����� �������, ���� ���� �� �������. � ������ ��� ���.";
				link.l1.go = "return_4";
			}
			else
			{
				link.l1 = "���, �������. ��, ����� �������, ���� ���� �� �������. �� ������ � ���� ��� � ����� ���.";
				link.l1.go = "return_3";
			}
		break;
		
		case "return_3":
			dialog.text = "�� ��� ��������� ��� ���, ���� ������! ���� �� ������� ��� �������� - ����������� ��������� �� �����, ��� � ������!";
			link.l1 = "�� �� ���������� �� ���, �������. ����� � ��� ��������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "return_underwater";
		break;
		
		case "return_underwater":
			if(CheckCharacterItem(pchar, "underwater"))
			{
				dialog.text = "�, �� ���-���� �������� ��� ��� ��������! �������-�������, � �� � ��� ����� ���� �����������.";
				link.l1 = "��� �� ����������. � �� ������ - �����, ������ - �����.";
				link.l1.go = "return_4";
			}
			else
			{
				dialog.text = "���� �� ������� ��� ��� �������� - ���� �� ��������� �� ���.";
				link.l1 = "������-������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "return_underwater";
		break;
		
		case "return_4":
			DeleteAttribute(pchar, "questTemp.LSC.UW_end"); 
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			SetFunctionTimerCondition("LSC_ReadyUnderwater", 0, 0, 1, false);
			dialog.text = "����� ������. � ��� ������� ���������� �� ������������ ������, �� ��� ���������� �� �� ���, �� ������... � ����� ���, ��� �� �������� ��������������� � ��������� ��������� ��� ��������� � �������. � � ���� ������ ��� �������.";
			link.l1 = "�� ��� ��� - ��������?";
			link.l1.go = "return_5";
		break;
		
		case "return_5":
			dialog.text = "�� �������! �� �� ������� ��� �������� ��������, ����� �� ������� ��� ��� ������ ������, ������� ���, ������ � ����� � ������� ���. � �����, � ���� ��� ��� ���� ����� ��������� ������������. ��������� ��� ������������. � �� ������� �� ������� ���������� ����� ����� �������� �����.";
			link.l1 = "�� ����� �� ��� ������� ����� ���� ����� �� ��������! ������� - ����� ������������! ������� �������, ������, �, �����, ������... � �� �������� ����� �������.";
			link.l1.go = "return_6";
		break;
		
		case "return_6":
			GiveItem2Character(pchar, "mechanic_tool");
			Log_Info("�� �������� ��������� ����������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� ����� �����, ��������� ��� ���. ������-������! ��� ��� ����������. � ��� �������� ������ � ��� ���� �������� ������ ��� ����� � ����������� ����, ��� �� ����� ������� � ������ ������� �� ���������� ����� ������ ������.";
			link.l1 = "���! �� ��� ��, � ������� - ����������������...";
			link.l1.go = "return_7";
		break;
		
		case "return_7":
			dialog.text = "�������. � �� ����� �� � ��� ������� �������? ����� ��� ����������� �������� ��� ������������.";
			link.l1 = "������, ������. � ��������. ������ ������, � �����, �� ��� ��� ������ ������ �� ������.";
			link.l1.go = "return_8";
		break;
		
		case "return_8":
			dialog.text = "������. ����������� � ����� - � ����������� �� ��������.";
			link.l1 = "������������! ����� � ����� ��� ������ ����� ��� ��� ����������, ������� � ����������� ���?";
			link.l1.go = "return_9";
		break;
		
		case "return_9":
			dialog.text = "������ ���.";
			link.l1 = "�������! ��� ��������, ������!";
			link.l1.go = "return_10";
		break;
		
		case "return_10":
			DialogExit();
			AddQuestRecord("LSC", "26");
			npchar.quest.return_isl = "true";
			npchar.quest.guarantee = "true"; // ����� �� ��������
			NextDiag.CurrentNode = "First time";
		break;
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