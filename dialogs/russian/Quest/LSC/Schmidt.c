// ����� ����� - ���������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp, iRem;
	DeleteAttribute(&Dialog,"Links");
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	string NodeName = Dialog.CurrentNode;
	string NodePrevName = "";
	if (CheckAttribute(NextDiag, "PrevNode")) NodePrevName = NextDiag.PrevNode;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = "����������, ���������, �� ����� ���� ��� ����������, �? ���� �� � ���� � ����� - ��� ������ ������ � ���� ����������. �������!";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) // ���� ������ ��������
				{
					dialog.text = "�, "+GetFullName(pchar)+"! ��������, �������� � ����� �����. �������, ��� �� ����� ������ �������� � ����� �����������. ������� ����� ������ ������, ��� � ��� ������ �����.";
					link.l1 = "�������, ��� ��� ���. � ���� ������������ �� ���� ������?";
					link.l1.go = "friend";
				}
				else
				{
					dialog.text = "��? ���� ���� ����?";
					link.l1 = TimeGreeting()+". ���� ����� "+GetFullName(pchar)+". � ������ ���������� � ������. � ��� ������� �� ���?";
				link.l1.go = "meeting";
				}
				npchar.quest.meeting = "1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) // ���� ������ ��������
				{
					dialog.text = "�, "+GetFullName(pchar)+"! ��������, �������� � ����� �����. �������, ��� �� ����� ������ �������� � ����� �����������. ������� ����� ������ ������, ��� � ��� ������ �����.";
					link.l1 = "�������, ��� ��� ���. ������ � ���� ������������ �� ���� ������?";
					link.l1.go = "friend";
				}
				else
				{
					dialog.text = "�, "+GetFullName(pchar)+"! ����� ��������� ����������? ��, ��� � ��� ��������� - ��� � ���� �� ��� �� �������, �� �������.";
					link.l1 = "������, �� ���� ��� ���������.";
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // ������ �������
			dialog.text = "�����! �� ���� ��������� �� ���, ������. � ����� �����, ������ � ��������� ��������, � ����������� ��� ���� �������. �� ����� ������� ������� ������, ��� �������� �������� ��������� ���������, ��� ������� ����� ����� � ���� - ����� �����, �������� � ��������������. ������� � �� �����, ����� ���� ��������� �� ������.";
			link.l1 = "�� ������� ������? � �������� � ��� ���-������ �����?";
			link.l1.go = "meeting_1";
		break;
		
		case "meeting_1":
			dialog.text = "���. � ����� ������ ������ ��� ������ ����� ������. ��� ��� �������, � � �� ���� �� �������� �� �� ���. ��� ��� �� �������������, ������. �������� � ���� ������, ���, ��� �������, ��������� ����� ��������� - ����� � ���������, ���������.";
			link.l1 = "�����. ����� � �����. ��������, ��� �����������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "friend":
			dialog.text = "������. ���� �������� - ��� ����, ��� ��� ������ ����������� ���� ���������.";
			link.l1 = "� �� ����� ���������� ������ ��� �����.";
			link.l1.go = "blade";
			if (CheckAttribute(npchar, "quest.narval_blade") && pchar.questTemp.LSC.Mary == "alive")
			{
				link.l2 = "� ������, �� ���������� ��� ��������� ����� ������ ������ ������. � ����� ���� ����� - ������������ ������. � ��� �� � ��� �������� ���� ����� ��?";
				link.l2.go = "narval";
			}
			link.l3 = "���� ������� ��������� ���, ������ � ������ �� ��������. ������� - � ����������� �������!.";
			link.l3.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		
		case "Jurgen":
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "��, "+GetFullName(pchar)+"! ��� �� �� ������? ��� ��� ��! �� ����� �� �������?";
				link.l1 = "�� ����������, �����. �����! � ������ � �� ��������� - ��� �� ��� ������������� ������� ����...";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				NextDiag.TempNode = "Jurgen";
				break;
			}
			dialog.text = "�, "+GetFullName(pchar)+"! �� ������ ���� ����������?";
			if (CheckAttribute(npchar, "quest.narval_blade") && npchar.quest.narval_blade == "ferrum")
			{
				if (GetCharacterItem(pchar, "jewelry11") >= 3)
				{
					link.l4 = "� ������ ��� ����� ������� ������, ��� �� � �������. ������� - ��� ���?";
					link.l4.go = "narval_7";
				}
				if (CheckCharacterItem(pchar, "meteorite"))
				{
					link.l5 = "������� ����, �����. � ����� ���������� ������ ������ �� ���, �� �� ����� ������� ������, ��� �� �������� - � ��� �� ������ ���� ������.";
					link.l5.go = "narval_7_1";
				}
			}
			if (CheckAttribute(pchar, "quest.narval_dla_charla") && !CheckAttribute(pchar, "quest.bestnarval") && !CheckAttribute(npchar, "quest.klinok_best_narval") && !CheckAttribute(npchar, "quest.narval_zakaz_gotov"))
			{
			link.l10 = "�����, � �� �� ���� ��������� � ��������� ��� '������'. � ������� ����� � ����. ������ 7000 �������� ����� ����������, ����� �� ������ ��� ���� �������? ";
			link.l10.go = "blade_best_narval";
			}
			if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && CheckAttribute(npchar, "quest.klinok_best") && !CheckAttribute(npchar, "quest.klinok_best_next"))
			{
             	link.l1 = "� ���� ����� �������� ������ �� 5000 ��������.";
				link.l1.go = "blade_bext";
            }
            if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && CheckAttribute(npchar, "quest.klinok_best_next_two") && !CheckAttribute(npchar, "quest.klinok_best_next"))		
            {
             	link.l1 = "� ���� ����� �������� ������ �� 5000 ��������.";
				link.l1.go = "blade_bext";
            }			
			if (!CheckAttribute(npchar, "quest.blade_done") && !CheckAttribute(npchar, "quest.klinok_best")) // ����� �� ����������
			{
				link.l1 = "� �� ����� ���������� ������ ��� �����.";
				if (!CheckAttribute(npchar, "quest.blade_rules") && !CheckAttribute(npchar, "quest.blade_ruless")) link.l1.go = "blade";
				else link.l1.go = "blade_4";
			}
			/*if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && !CheckAttribute(npchar, "quest.blade_done"))
			{
            link.l1 = "� �� ����� ���������� ������ �� 1000 ��������.";	
             link.l1.go = "blade_4";
			}	*/		 
			if (CheckAttribute(npchar, "quest.blade_payseekss"))
			{	
			    link.l1 = "� ������ ��� �������� � ���� ������ �� �������� ������.";
				link.l1.go = "blade_30";
	        }
             if (CheckAttribute(npchar, "quest.blade_payseekssnarval"))//&& CheckAttribute(npchar, "quest.narval_zakaz_gotov")) //��
			{	
			    link.l1 = "� ������ ��� �������� � ���� ������ �� '������'.";   
				link.l1.go = "blade_300";
	        }			
			if (CheckAttribute(npchar, "quest.blade_payseek"))
			{
				link.l1 = "� ������ ��� �������� � ���� ������ �� ������.";
				link.l1.go = "blade_3";
			}
			if (CheckAttribute(npchar, "quest.narval_blade") && pchar.questTemp.LSC.Mary == "alive" && npchar.quest.narval_blade == "begin" && pchar.questTemp.LSC != "return") // patch-9
			{
				link.l2 = "� ������, �� ���������� ��� ��������� ����� ������ ������ ������. � ����� ���� ����� - ������������ ������. � ��� �� � ��� �������� ���� ����� ��?";
				link.l2.go = "narval";
			}
			if (CheckAttribute(npchar, "blade_date") && GetNpcQuestPastDayParam(npchar, "blade_date") >= 5)
			{
				link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
				link.l1.go = "blade_done_2";
			}
			if (CheckAttribute(npchar, "palash_date_1") && GetNpcQuestPastDayParam(npchar, "palash_date_1") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "P_1";	
            }
             if (CheckAttribute(npchar, "palash_date_2") && GetNpcQuestPastDayParam(npchar, "palash_date_2") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "P_2";	
            }
              if (CheckAttribute(npchar, "palash_date_3") && GetNpcQuestPastDayParam(npchar, "palash_date_3") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "P_3";	
            }
              if (CheckAttribute(npchar, "palash_date_4") && GetNpcQuestPastDayParam(npchar, "palash_date_4") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "P_4";	
            }
            if (CheckAttribute(npchar, "sabla_date_1") && GetNpcQuestPastDayParam(npchar, "sabla_date_1") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_1";	
            }
             if (CheckAttribute(npchar, "sabla_date_2") && GetNpcQuestPastDayParam(npchar, "sabla_date_2") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_2";	
            }
             if (CheckAttribute(npchar, "sabla_date_3") && GetNpcQuestPastDayParam(npchar, "sabla_date_3") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_3";	
            }
             if (CheckAttribute(npchar, "sabla_date_4") && GetNpcQuestPastDayParam(npchar, "sabla_date_4") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_4";	
            }
             if (CheckAttribute(npchar, "sabla_date_5") && GetNpcQuestPastDayParam(npchar, "sabla_date_5") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_5";	
            }
             if (CheckAttribute(npchar, "sabla_date_6") && GetNpcQuestPastDayParam(npchar, "sabla_date_6") >= 2)
			{
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "S_6";	
            }
             if (CheckAttribute(npchar, "rapira_date_1") && GetNpcQuestPastDayParam(npchar, "rapira_date_1") >=2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_1";	
            }
            if (CheckAttribute(npchar, "rapira_date_2") && GetNpcQuestPastDayParam(npchar, "rapira_date_2") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_2";	
            }
            if (CheckAttribute(npchar, "rapira_date_3") && GetNpcQuestPastDayParam(npchar, "rapira_date_3") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_3";	
            }
             if (CheckAttribute(npchar, "rapira_date_4") && GetNpcQuestPastDayParam(npchar, "rapira_date_4") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_4";	
            }
             if (CheckAttribute(npchar, "rapira_date_5") && GetNpcQuestPastDayParam(npchar, "rapira_date_5") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_5";	
            }
			if (CheckAttribute(npchar, "rapira_date_6") && GetNpcQuestPastDayParam(npchar, "rapira_date_6") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_6";	
            }
			if (CheckAttribute(npchar, "rapira_date_7") && GetNpcQuestPastDayParam(npchar, "rapira_date_7") >= 2)
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_7";	
            }
			if (CheckAttribute(npchar, "rapira_date_8") && GetNpcQuestPastDayParam(npchar, "rapira_date_8") >= 2) // ������ 
            {
                link.l1 = "� ������ �� ����� �������. �� ��� ������ ���� �����, ��� � �������?";
			    link.l1.go = "R_8";	//������
            }
            if (CheckAttribute(npchar, "narval_best_date_1") && GetNpcQuestPastDayParam(npchar, "narval_best_date_1") >= 3)
            {
               link.l1 = "� ������ �� ����� '��������'. �� ��� ������ ���� �����, ��� � �������?";
			   link.l1.go = "N_1";		
            }
             if (CheckAttribute(npchar, "narval_best_date_2") && GetNpcQuestPastDayParam(npchar, "narval_best_date_2") >= 3)
            {
               link.l1 = "� ������ �� ����� '��������'. �� ��� ������ ���� �����, ��� � �������?";
			   link.l1.go = "N_2";
            }
             if (CheckAttribute(npchar, "narval_best_date_3") && GetNpcQuestPastDayParam(npchar, "narval_best_date_3") >= 3)
            {
               link.l1 = "� ������ �� ����� '��������'. �� ��� ������ ���� �����, ��� � �������?";
			   link.l1.go = "N_3";
            }						
			link.l3 = "�� ���, ������, ������ ����� �������������.";
			link.l3.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_300":
			dialog.text = "����� ��� ������ �� '������'!";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "���, ����������. � ���� ���� � ����� "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pays_narval";
			}
			link.l2 = "��. � ���� ������ �� � ����� ���, � ���������. �� � ����������� �������, � �� �������� � ����� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
			npchar.quest.blade_payseekssnarval = "true";
		break;
		case "blade_best_narval":
		dialog.text = "�� �������... 7000 ��������??! ���������, �� ����� ������ � ����� ������ ��� ���� ��������! ������ ���, ��� ����� ����� ������ '������'! � ���� ��� ������� �� ��� �� ������ ������� ������ ��� ����, ��� ���� ������ �������� ����� ���� ������ � ��������. �� �� 7000 �������� � ���� ������ �� ����� ���! ������, �� ��������? ";
		link.l1 = "��, � ��������!";
		link.l1.go = "blade_300";
		NextDiag.TempNode = "Jurgen";	
		npchar.quest.blade_dublon = 7000;
		npchar.quest.narval_zakaz_gotov = "true";	// ����� �� ���� �������� � ������ ��������� ��� ������.
			
		break;
		case "blade_pays_narval": // ������
			 npchar.quest.klinok_best_narval = "true"; // ������ �� ���� �������� � ������ ��������� ��� ������ 
          
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // ������ �����
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // ���������� �������
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("�� ������ "+sti(npchar.quest.blade_pay)+" ��������");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "�������. ������, ����� �� �������� ��� ������ � ���������, � ���� ���������� � ����.";
				link.l1 = "� ���� ������ �����?";
				link.l1.go = "narval_za_7000";
			}
			else
			{
				dialog.text = "������. � �������� � ��� �������. ��� �������� �������� ��� "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "��� ������ ������ ��� �������� - ���������� ������� ���.";
				link.l1.go = "exit";
                npchar.quest.blade_payseekssnarval = "true";				
			}
		break;
		case "N_1":
		    dialog.text = "��. ��� '������' �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� 7000 ��������!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 2.0;
			sld.Weight = 3.5;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_1");
			pchar.quest.bestnarval = "true";
			Log_Info("�� �������� �� ������ '������'!");
		break;
		case "N_2":
		    dialog.text = "��. ��� '������' �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� 7000 ��������!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 1.9;
			sld.Weight = 3.4;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_2");
			pchar.quest.bestnarval = "true";
			Log_Info("�� �������� �� ������ '������'!");
		break;
		case "N_3":
		    dialog.text = "��. ��� '������' �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� 7000 ��������!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 1.8;
			sld.Weight = 3.3;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_3");
			pchar.quest.bestnarval = "true";
			Log_Info("�� �������� �� ������ '������'!");
		break;
		case "R_1":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;
			sld.Weight = 2.4;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next"); //npchar.quest.klinok_best_next = "true";
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_2": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // ��������������
			sld.Weight = 2.0;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_2");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_3": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.5;  // ��������������
			sld.Weight = 2.2;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_3");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_4": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // ��������������
			sld.Weight = 2.3;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_4");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_5": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;  // ��������������
			sld.Weight = 2.1;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_5");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_6": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.5;  // ��������������
			sld.Weight = 2.5;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_6");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_7": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // ��������������
			sld.Weight = 2.6;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_7");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "R_8": //������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;  // ��������������
			sld.Weight = 2.7;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_8");//������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_1":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.3;
			sld.Weight = 3.3;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_2":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.6;
			sld.Weight = 3.0;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_2");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_3":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.4;
			sld.Weight = 3.2;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_3");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_4":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.5;
			sld.Weight = 3.1;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_4");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_5":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.1;
			sld.Weight = 3.0;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_5");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "S_6":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.5;
			sld.Weight = 3.4;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_6");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "P_1":
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.5;
			sld.Weight = 4.0;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next");  // ��������� �������� . ��� ��������� ������ - �������� . ������� ����� ,����� �������
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "P_2":                                                 // ������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 2.0;                                     //�����
			sld.Weight = 3.5;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_2"); 
            DeleteAttribute(npchar, "quest.klinok_best_next");			//��������
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "P_3":                                                 // ������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.8;                                     //����� 110/3.7/1.8
			sld.Weight = 3.7;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_3");            //������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "P_4":                                                 // ������
		    dialog.text = "��. ��� ������ �����. ����������, �������� � �������� �� ��������. ��� ������ �� �������� ��� � ����, ����� �������, ��� �� ����� ����������� �� ���� �����!";
			link.l1 = "�����, �� ���� ���������!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.7;                                     //����� 
			sld.Weight = 3.8;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_4");            //������
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("�� �������� �� ������ ���� ������!");
		break;
		case "narval_za_7000":
		DeleteAttribute(npchar, "quest.blade_payseekssnarval");  // �������� ������� - � ������ ������ �� ������.
		dialog.text = "����, ����� ������� ��� '�������' �����, ��� � ������?";
         link.l1 = "� ���� '������' � ���������������� 120 / 3.5 / 2.0";
         link.l1.go = "best_narval_1";
         link.l2 = "� ���� '������' � ���������������� 120 / 3.4 / 1.9";
         link.l2.go = "best_narval_2";
         link.l3 = "� ���� '������' � ���������������� 120 / 3.3 / 1.8 ";
         link.l3.go = "best_narval_3";
        break;	
        
        case "best_narval_1":
	    	Log_Info("�� �������� '������' � ������ �� 7000 ��������");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "best_narval_2":
	    	Log_Info("�� �������� '������' � ������ �� 7000 ��������");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "best_narval_3":
	    	Log_Info("�� �������� '������' � ������ �� 7000 ��������");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
       		
		// --> ����� �������
		case "blade":
			dialog.text = "������. �� � ���� ���� ������������ ���������� � ������, ��� ��� ���������� �������, � ����� ������� - ����������, ��� ���.";
			link.l1 = "� ��� ����������� ������.";
			link.l1.go = "blade_1";
		break;
		
		case "blade_1":
			dialog.text = "� ���� ��� �������� ������� ������ �� 1000 ��������. ����� ����� �������������� ������, ������� �� ���������. �� ����� ����� - �� 1000 ��� ���� �����.  �� ���� ��� ����������, ��������, ������ � ���������������� �� �����. ����� 5000 ��������. � ����� ����� ����� �������� ������������, � ������� ��������, �� �� �������. ������ ������. ��� ���������?";
			link.l1 = "����� ������ ������ �� 1000 ��������.";
			link.l1.go = "blade_2";
			link.l3 = "� ���� �������� �������� ������ �� 5000 ��������!";
			link.l3.go = "blade_bext";
			npchar.quest.klinok_pervii_zakaz = "true";
			
		break;
		case "blade_bext":
		dialog.text = "����� ������. �������� ����� �������. ���� ������������ ����� ���� ����. �� ��������?";
		link.l1 = "��, � ��������!";
		link.l1.go = "blade_30";
		NextDiag.TempNode = "Jurgen";	
		npchar.quest.blade_dublon = 5000;
			
		break;
		
			
			
		case "blade_2":
			dialog.text = "������������, ������ ��� ������ �� 1000 ��������. ������� ��������, �������, �� ��������. �� ������ ����� �������!";
			link.l1 = "����� � ������ �����.";
			link.l1.go = "blade_3";
			link.l2 = "��. �������, ��� ����� ���������� ��������, ������ ��� �������� �� �����. �������� � ����� ��������� �����!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
			npchar.quest.blade_rules = "true";
			npchar.quest.blade_dublon = 1000;
			AddQuestRecord("LSC", "17");
		break;
		
		case "blade_3":
			dialog.text = "����� ������. ����� ������� ���� �������.";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "���, ����������. � ���� ���� � ����� "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pay";
			}
			link.l2 = "��. � ���� ������ �� � ����� ���, � ���������. �� � ����������� �������, � �� �������� � ����� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_30":
			dialog.text = "����� ������. ����� ������� ���� �������.";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "���, ����������. � ���� ���� � ����� "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pays";
			}
			link.l2 = "��. � ���� ������ �� � ����� ���, � ���������. �� � ����������� �������, � �� �������� � ����� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_4":
			dialog.text = "�� ���-���� ������� ���� �����? ������ ��������?";
			link.l1 = "��. � ��������� �����������.";
			link.l1.go = "blade_3";
		break;
		case "blade_pays": // ������
		     npchar.quest.klinok_best = "true"; // ����� �� �������� ���������� ��� � ���� �� �� � �� � � 
			 npchar.quest.klinok_best_next = "true"; // ��� ��������� ����� �������� �� 5000� 
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // ������ �����
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // ���������� �������
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("�� ������ "+sti(npchar.quest.blade_pay)+" ��������");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "�������. ������, ����� �� �������� ��� ������ � ���������, � ���� ���������� � ����.";
				link.l1 = "� ���� ������ �����?";
				link.l1.go = "blade_dones";
			}
			else
			{
				dialog.text = "������. � �������� � ��� �������. ��� �������� �������� ��� "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "��� ������ ������ ��� �������� - ���������� ������� ���.";
				link.l1.go = "exit";
				npchar.quest.blade_payseekss = "true";
				
			}
		break;
		
		case "blade_dones":
		DeleteAttribute(npchar, "quest.blade_payseekss");
		dialog.text = "����, ����� ������ ���������? �����, �����, ��� ������?";
		link.l1 = "������� �����, ����� ������ ������ ������ �������!";
		link.l1.go = "best_palash";
		link.l2 = "������� �����, ���� �������� ���� �� ���� ��������!";
		link.l2.go = "best_sabla";
		link.l3 = "������� ������, ��������� ����� � ���� ����� ����� ��!";
		link.l3.go = "best_rapira";
		
		break;
		case "best_palash":
		dialog.text = "����� �������������� ������ ���������? ����� / ��� / ������ ? ";
		link.l1 = "������� ����� � ����������������  110 / 4.0 / 1.5";
		link.l1.go = "palash_1";
		link.l2 = "������� ����� � ����������������  110 / 3.5 / 2.0";
		link.l2.go = "palash_2";
		link.l3 = "������� ����� � ����������������  110 / 3.7 / 1.8";
		link.l3.go = "palash_3";
		link.l4 = "������� ����� � ����������������  110 / 3.8 / 1.7";
		link.l4.go = "palash_4";
		
		break;
		case "best_rapira":
		dialog.text = "����� �������������� ������ ���������? ����� / ��� / ������ ? ";
		link.l1 = "������� ������ � ����������������  70 / 2.4 / 0.4";
		link.l1.go = "rapira_1";
		link.l2 = "������� ������ � ����������������  70 / 2.0 / 0.3";
		link.l2.go = "rapira_2";
		link.l3 = "������� ������ � ����������������  70 / 2.2 / 0.5";
		link.l3.go = "rapira_3";
		link.l4 = "������� ������ � ����������������  70 / 2.3 / 0.3";
		link.l4.go = "rapira_4";
		link.l5 = "������� ������ � ����������������  70 / 2.1 / 0.4";
		link.l5.go = "rapira_5";
		link.l6 = "������� ������ � ����������������  70 / 2.5 / 0.5";
		link.l6.go = "rapira_6";
		link.l7 = "������� ������ � ����������������  70 / 2.6 / 0.3";
		link.l7.go = "rapira_7";
		link.l8 = "������� ������ � ����������������  70 / 2.7 / 0.4";
		link.l8.go = "rapira_8";
         		
         		
		break;
		
		case "best_sabla":
		dialog.text = "����� �������������� ����� ���������? ����� / ��� / ������ ? ";
		link.l1 = "������� ����� � ����������������  90 / 3.3 / 1.3";
		link.l1.go = "sabla_1";
		link.l2 = "������� ����� � ����������������  90 / 3.0 / 1.6";
		link.l2.go = "sabla_2";
		link.l3 = "������� ����� � ����������������  90 / 3.2 / 1.4";
		link.l3.go = "sabla_3";
		link.l4 = "������� ����� � ����������������  90 / 3.1 / 1.5";
		link.l4.go = "sabla_4";
        link.l5 = "������� ����� � ����������������  90 / 3.0 / 1.1";
		link.l5.go = "sabla_5";
        link.l6 = "������� ����� � ����������������  90 / 3.4 / 1.5";
		link.l6.go = "sabla_6";			
			
		break;
		case "rapira_1":
		Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_2":
		Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_3":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_4":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_4");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_5":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_5");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_6":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_6");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_7":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_7");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_8":  //������
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_8");//������
			NextDiag.CurrentNode = "Jurgen";
		break;
		
		case "sabla_1":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_2":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_3":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_4":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_4");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_5":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_5");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_6":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_6");
			NextDiag.CurrentNode = "Jurgen";
		break;
		
		
		case "palash_1":
		    Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "palash_2":
			Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_2");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		case "palash_3":
			Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_3");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		case "palash_4":
			Log_Info("�� �������� ������ � ������ �� 5000 ��������!");
		    dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_4");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		
		
		case "blade_pay": // ������
		    npchar.quest.klinok_best_next_two = "true";
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // ������ �����
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // ���������� �������
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("�� ������ "+sti(npchar.quest.blade_pay)+" ��������");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "�������. ������, ����� �� �������� ��� ������ � ���������, � ���� ���������� � ����.";
				link.l1 = "� ���� ������ �����?";
				link.l1.go = "blade_done";
			}
			else
			{
				dialog.text = "������. � �������� � ��� �������. ��� �������� �������� ��� "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "��� ������ ������ ��� �������� - ���������� ������� ���.";
				link.l1.go = "exit";
				npchar.quest.blade_payseek = "true";
			}
		break;
		
		case "blade_done":
			DeleteAttribute(npchar, "quest.blade_payseek");
			dialog.text = "�������! ����� ������ ��� �� ���� - ������, ����� ��� ������?";
			link.l1 = "������. ����� ������� ������ ������.";
			link.l1.go = "rapier";
			link.l2 = "�����. ��� ����������� ������� � ���� ����� ������.";
			link.l2.go = "sabre";
			link.l3 = "������� ��, ������! ������ ��� ������, ��� ���������!";
			link.l3.go = "palash";
		break;
		
		case "rapier":
			npchar.quest.blade_done = SelectJurgenBladeDone("rapier");
			dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			link.l1.go = "blade_done_1";
		break;
		
		case "sabre":
			npchar.quest.blade_done = SelectJurgenBladeDone("sabre");
			dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			link.l1.go = "blade_done_1";
		break;
		
		case "palash":
			npchar.quest.blade_done = SelectJurgenBladeDone("palash");
			dialog.text = "��� �������. �� ������� ��������� ����� ���� ����, �� ������.";
			link.l1 = "�������! ���� � ��������� �����. �� ��������, �����.";
			link.l1.go = "blade_done_1";
		break;
		
		case "blade_done_1":
			DialogExit();
			SaveCurrentNpcQuestDateParam(npchar, "blade_date");
			NextDiag.CurrentNode = "Jurgen";
			AddQuestRecord("LSC", "18");
		break;
		
		case "blade_done_2":
			dialog.text = "��. ��� ������ �����. ������� ��������� ���� ��� �� ���. ������ ��� � ������. �� � ����� ��� �� ����������...����� ������, ����� �� �������� �� 1000 ��������..���.";
			link.l1 = "��...�� ��� � ��������. �����, ������� � �� ���, �����.";
			link.l1.go = "blade_done_3";
		break;
		
		case "blade_done_3":
			DialogExit();
			NextDiag.CurrentNode = "Jurgen";
			GiveItem2Character(pchar, npchar.quest.blade_done);
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "blade_date");
		break;
		
		// ����� ������ ������ ��� ����
		case "narval":
			dialog.text = "���, �������, �� ��� � ��� �������� �������� �� ���� ��������. ��-������, ����� ����� � �������� ������ ������ ��� ����� ����� ������, � �� - �� ��� �������. � ��-������, � ���� ��� ��������� ��� ��� ������������.";
			link.l1 = "� ��� �� ������ ������ ��� ���� �����? � ������, ��� ��� ��������� �� ���...";
			link.l1.go = "narval_1";
		break;
		
		case "narval_1":
			dialog.text = "������ ���. ����� ����� ������ ���������� �� ����� ����������. ������ ��� ��� ������� - ��� ��������. �� ������ ������������� ���������� - �� ������� ������, � ������ �� ���� �� �������. ��� ��� ���� �� �� �����-�� ������� ������� ��� ������ - ����� ���� �� ������ ������. �� ����� �� �������� - �� �� ������...";
			link.l1 = "��. � ��, ��� � �� ������ - ��� ����� ��������� �������������� ��������?";
			link.l1.go = "narval_2";
		break;
		
		case "narval_2":
			dialog.text = "��. ������������� ��� ��� ��� �������, ���� ������, �� ����� ����� � ���� ������ ������ ��� �������.";
			link.l1 = "���... �����, �����, ��� ������������. �� � ���� �������� ������ �����. � ���� �� � �������� ���� ������ � ������� ��� ����� ����� ������?";
			link.l1.go = "narval_3";
		break;
		
		case "narval_3":
			dialog.text = "��. ��, ���� �� ��������� ��� ������ ��� ������������, �� ��������, ��. ��� ����� �� ����� ������������� ��������... � ��� ���� �� ������ ������� ���� �����?";
			link.l1 = "��� ������� ����. ��� �� ����� ������, � ������ ����������� ����� ������� ����� ������������� �������.";
			link.l1.go = "narval_4";
		break;
		
		case "narval_4":
			dialog.text = "��! � ��� �� ���������� � ���. ������... �� ��� ��, � ��������. ���� ����� ������ � �������� �� ������ �������, � ������... ������ ������ - � � ������ �����. �� ������ � ������... �, �������, ������ �� ����. ����� ��� ����� ������� �� ������ �� ���, �� � �� ����.";
			link.l1 = "�������! ������� ��� ����� ������ ��� ��� ������������?";
			link.l1.go = "narval_5";
		break;
		
		case "narval_5":
			dialog.text = "�����, ������� �������� �� ���, ���� ��� �������� ����������� ������� - �� ����� � ���������. ��� ����� ��� �����.";
			link.l1 = "������. � ���������� ������ ��. ����� � �������� � ������ ���������.";
			link.l1.go = "narval_6";
		break;
		
		case "narval_6":
			DialogExit();
			npchar.quest.narval_blade = "ferrum";
			NextDiag.CurrentNode = "Jurgen";
			// ������ ���������� ����� ��������� �� ���
			sld = ItemsFromID("meteorite");
			sld.shown = true;
			sld.startLocation = "underwater";
			sld.startLocator = "item"+(rand(7)+1);
			Log_TestInfo("�������� � ��������" + sld.startLocator);
			pchar.quest.LSC_narval_ferrum.win_condition.l1 = "item";
			pchar.quest.LSC_narval_ferrum.win_condition.l1.item = "meteorite";
			pchar.quest.LSC_narval_ferrum.function = "LSC_NarvalFerrum";
			AddQuestRecord("LSC", "19");
		break;
		
		case "narval_7":
			RemoveItems(pchar, "jewelry11", 3);
			PlaySound("interface\important_item.wav");
			dialog.text = "��-��, ��������... ��, ����� - ���! ��� ���� ������ - �������� ����� ��������� ����� �� ���?";
			link.l1 = "��, ��� �������... �� ���� ���� ���� ����� ���� �����������, �� ��� ��?";
			link.l1.go = "narval_8";
			pchar.quest.LSC_narval_ferrum.over = "yes"; //����� ����������
		break;
		
		case "narval_7_1":
			RemoveItems(pchar, "meteorite", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "��-��, ��������... ���! ��, ��� �� ����� ������ ������, �� ����� �������� ������ � ��� �� �����. ��� ������ � ������ ������ ��� ������������ ������. ��� ����, ��������, ������ - ����� ���?";
			link.l1 = "��, ��� �������... �� ���� ���� ���� ����� ���� �����������, �� ��� ��?";
			link.l1.go = "narval_8";
		break;
		
		case "narval_8":
			dialog.text = "�� ��������� ��� ��� ������ � ������, "+pchar.name+"... �� ��� ��, �������. ������ ������ ����� � ��� ����������� ��� ����� ���������� ��������. ������ ������ ��� ��� - � ������� ��� ������ ������ � ������� �������\n��������� ����������� �� ��� ������ � ����. ������ �� �������� �� ������ ������� - ������� �������. ��� ����� ����������, ��� �������.";
			link.l1 = "������, �����. ������������. ����� - �� �����������!";
			link.l1.go = "narval_9";
		break;
		
		case "narval_9":
			DialogExit();
			npchar.quest.narval_blade = "work";
			NextDiag.CurrentNode = "narval_10";
			SetFunctionTimerCondition("LSC_NarvalBladeForMary", 0, 0, 2, false); // ������
			AddQuestRecord("LSC", "21");
		break;
		
		case "narval_10":
			dialog.text = ""+pchar.name+", �� ���������� ����. �� �� ������, ����� ����� ��� ����� �������?";
			link.l1 = "��, �������. � ��� �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "narval_10";
		break;
		
//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
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
string SelectJurgenBladeDone(string _sType)
{
	string sBlade;
	switch (_sType)
	{
		case "rapier":			
			if (sti(pchar.rank) > 21) sBlade = "q_blade_16"; 
			else sBlade = "q_blade_16";
		   
		break;
		
		case "sabre":
			if (sti(pchar.rank) > 21) sBlade = "q_blade_10"; 
			else sBlade = "q_blade_10";
		break;
		
		case "palash":
			if (sti(pchar.rank) > 21) sBlade = "q_blade_13"; 
			else sBlade = "q_blade_13";			
		break;
	}
	return sBlade;
}