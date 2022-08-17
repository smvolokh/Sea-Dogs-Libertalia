// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������, " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";						
			//Jason, ����� ��������
			if (CheckAttribute(PChar, "questTemp.Sharlie.Storehelper") && pchar.questTemp.Sharlie.Storehelper == "hire" && !CheckAttribute(npchar, "quest.storehelper"))
			{
				link.l1 = "��������, " + npchar.name + ", � � ���� �� ������ ���������� ����. ��� ����� ����� ��������, ������� ����� �� ����� � ��������� ����� �� ������ � �������� ��������� �������� � ������� ���� �� ������. ��������� �������, � ����� ��� ������� ����������. �� ������ ������������, � ���� ����������?";
				link.l1.go = "storehelper";
			}
			if (CheckAttribute(PChar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "seabattle" && !CheckAttribute(npchar, "quest.seabattle") && pchar.location.from_sea == "LeFransua_port")
			{
				link.l1 = "� �� ������ �������� � �����, ������� �� ����������� ��������� �� ��� ������� ��� �������� �� ���������...";
				link.l1.go = "seabattle";
			}
			//����� ��������
			//Jason, ����������
			if (CheckAttribute(PChar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalLeFransua" && !CheckAttribute(npchar, "quest.portugal") && Pchar.location.from_sea == "LeFransua_port")
			{
				link.l1 = "������, " + npchar.name + ", � ��� ������ ������ �����. �� ������ ��� �������� ����, � ��� �������������. ��������, ��� �������� ������...";
				link.l1.go = "Portugal";
			}
			//����������

	                                      //������ � ����� ����
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "Smithy_LeFransuaTavern" && !CheckAttribute(npchar, "quest.Smithy_LeFransuaTavern"))
			{
                                                             link.l1 = "� ��� ����� �������� ����. �� ������ ������ ���? ��� ������ ���� ���-�� �����, � ������?";
                                                            link.l1.go = "Smithy_1";
			}
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "Smithy_LeFransuaTavern_Sec" && !CheckAttribute(npchar, "quest.Smithy_LeFransuaTavern_Sec"))
			{
                                                            link.l1 = "��� ����� ���������� � ����� �������� ����!";
                                                            link.l1.go = "Smithy_2";
			}

			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "Smithy_LeFransuaTavern_Sec2" && !CheckAttribute(npchar, "quest.Smithy_LeFransuaTavern_Sec2"))
			{
                                                            link.l1 = "�������� �� ��� ������ ������ ���������!";
                                                            link.l1.go = "Smithy_Sec1";
			}
	                                      //������ � ����� ����

                                                            //��������� ������� ���
			if (pchar.questTemp.piratesLine == "BlackLabel_toLaVega")
			{
				link.l1 = "��������, ��������, �� ��������� �� � ��� � ��������� ������ ���?";
				link.l1.go = "PL_Q2_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toSeek")
			{
				link.l1 = "�������, � ����� � ����... �����, � ���� ��������� ������ ���? ��� �� ������ �����...";
				link.l1.go = "PL_Q3_1";
			}

			// �������� ������
			if (pchar.questTemp.PrisonEscort_quest == "start_search")
			{
				link.l1 = "������ �� ������ � ������, ������������ �������� �� ����������� �������, ������� ��������� ����� � �����������?";
				link.l1.go = "PrisonEscort";
				

			}

			if(PChar.SmallMongrel == "7" && PChar.SmallMongrel.LeFransuaTavern == false)
			{
				link.l1 = "��������, ��� ������ ���� ��������� ��������, �� �� �������� �� � ���� ����� ����������?";
				link.l1.go = "SmallMongrel_1";
			}

			//-->���
			if (pchar.questTemp.Headhunter == "vector_barmen" && Pchar.BaseNation == PIRATE)
			{
				link.l1 = "������ ����. ���� ������� ��� ����, �� ���������������. �� ������, ��� �� ����� �������� ��� ���������� ������-�� �������.";
				link.l1.go = "Barmen_check";
				break;
			}
			
			if (npchar.city == "LeFransua" && Pchar.BaseNation == PIRATE && pchar.questTemp.Headhunter == "barmen_wait")
			{
				link.l1 = "������ ����, " + npchar.name + ". ��� ����� �. ��� �� ������� �� ������ ������ �������?";
				link.l1.go = "Barmen_check";
				break;
			}
			if (pchar.questTemp.Headhunter == "hunt_carlos_yes")
			{
				link.l1 = "������ ����, " + npchar.name + ". � ���� ������� �������. ������ ������ ���������.";
				link.l1.go = "Endtaskhunt_1";
			}
			if(pchar.questTemp.Headhunter == "next_task_2" && GetQuestPastDayParam("pchar.questTemp.Headhunter_next_task_2") > 9)
			{
				link.l1 = "������ ����, " + npchar.name + ". � ����"+ GetSexPhrase("��","��") +", ��� �� � ��������������. ��������� �����-������ �������� ����������?";
				link.l1.go = "Givetaskhunt_2";
			}			
			if (pchar.questTemp.Headhunter == "hunt_houm_yes")
			{
				link.l1 = "������ ����, " + npchar.name + ". ��� ������� ��������� ��������� ����� �� ���� �����, ���� ��� ���� � ��������.";
				link.l1.go = "Endtaskhunt_2";
			}
			if(pchar.questTemp.Headhunter == "next_task_3" && GetQuestPastDayParam("pchar.questTemp.Headhunter_next_task_3") > 14)
			{
				link.l1 = "������������, " + npchar.name + ". �������, � �������?";
				link.l1.go = "Givetaskhunt_3";
			}
			if (pchar.questTemp.Headhunter == "hunt_rat_yes1")
			{
				link.l1 = "� ������"+ GetSexPhrase("","�") +" � �������� ���������, " + npchar.name + ". ��� ������� �������� �����. � �����������"+ GetSexPhrase("","�") +" ��� �������, � ������ ��� ��������"+ GetSexPhrase("","�") +" � ���� ������.";
				link.l1.go = "Endtaskhunt_3";
			}
			if (pchar.questTemp.Headhunter == "hunt_rat_yes2")
			{
				link.l1 = "� ������"+ GetSexPhrase("","�") +" � �������� ���������, " + npchar.name + ". ��� ������� �������� �����. � ��������"+ GetSexPhrase("","�") +" ��� � ���� ������ ������ � ��� ��������.";
				link.l1.go = "Endtaskhunt_3";
			}
			if(pchar.questTemp.Headhunter == "next_task_4" && GetQuestPastDayParam("pchar.questTemp.Headhunter_next_task_4") > 17)
			{
				link.l1 = "����������� ���, " + npchar.name + ". ��� � �. ����� �������?";
				link.l1.go = "Givetaskhunt_4";
			}
			if (pchar.questTemp.Headhunter == "hunt_halen_yes")
			{
				link.l1 = "������ ���  ����� ������ �� ����� ��������� ����� ������� �� �������, " + npchar.name + ".";
				link.l1.go = "Endtaskhunt_4";
			}
			if(pchar.questTemp.Headhunter == "hunt_ja_yes")
			{
				link.l1 = "������ ����, " + npchar.name + ". ������� �� ������������� ������. � ������ ������ ��������� ��������.";
				link.l1.go = "Endtaskhunt_5";
			}
		break;
//--------------------------------------------------------------------------------------------------------------		
		case "storehelper":
			dialog.text = "��... ���� ��� � ��� ��������� �������, �������� ������� ��������� ������ �� ����� ���������� �����. � ���� ������ ����, �� ����� ������: �� ���������.";
			link.l1 = "���! � ������� �� �� ������?";
			link.l1.go = "storehelper_1";
			npchar.quest.storehelper = "true";
		break;
		
		case "storehelper_1":
			dialog.text = "������ ����. � ���� ������ ������ �� �������� ������ - ����� ��� �������� �������� ����� � ���� � �������, � �� ����. ������� ���������� � ���� � �������, ��� ����������� ������ ������.";
			if (sti(Pchar.money) >= 1000)
			{
				link.l1 = "��-�... �����, ����� ���� ������!";
				link.l1.go = "storehelper_2";
			}
			link.l2 = "��� ����, �� � ���� ��� ����� �����!";
			link.l2.go = "storehelper_exit";
		break;
		
		case "storehelper_2":
			AddMoneyToCharacter(pchar, -1000);
			dialog.text = "�� ��������� ���, ��������. �������� ���� ����� �������� ���� �� ��������� - � �����, ��� ������ ������ ����� �����, ��-��... ������ ������� ����������� �� ���������. ������ � ��� ������� ����� ��� - � ����� ������� � ��� �������� ������ ���� �����.";
			link.l1 = "������. � ������� ����� ���, " + npchar.name + ".";
			link.l1.go = "storehelper_3";
		break;
		
		case "storehelper_3":
			DialogExit();
			pchar.quest.storehelper1.win_condition.l1 = "Timer";
			pchar.quest.storehelper1.win_condition.l1.date.hour  = sti(GetTime() + 1);
			pchar.quest.storehelper1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.storehelper1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.storehelper1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.storehelper1.win_condition.l2 = "location";
			pchar.quest.storehelper1.win_condition.l2.location = "lefransua_tavern";
			pchar.quest.storehelper1.function = "Storehelper_hire";
		break;
		
		case "storehelper_exit":
			dialog.text = "��� ���� ����, ��������, ��� � ���� �� ���. �� �� ������� ����� ���� �� ��������, ��� ���������. ��� ���...";
			link.l1 = "�������. �� ����� ������������� ���. �����, �����...";
			link.l1.go = "exit";
			pchar.quest.storehelper.over = "yes";
			DeleteAttribute(pchar, "questTemp.Sharlie.Storehelper");
			CloseQuestHeader("SharlieA");
		break;
		
		case "seabattle":
			dialog.text = "�� ��� ������ � ���, ��������? � ����� ���� �� ��������?";
			link.l1 = "���� ������� � ���� ������� �� ����� ������ ������. �� ������, ��� ���� ����� ������� ��� ��������� ������ ���� �� ���������, �� ������ ����� ����. � ��� ���� ����� ������ ��� ������� ��� ���� ������...";
			link.l1.go = "seabattle_1";
			npchar.quest.seabattle = "true";
		break;
		
		case "seabattle_1":
			dialog.text = "��������, �������, � �� ������ �����, � �� �������� � ����� �������, � �������� ������� ������� ����� �� ����.";
			link.l1 = "��� ��� �����! ��� ������, ���� ������ ��� ����� �� �� ����... �� � ���� ����� ��� ��� �������?";
			link.l1.go = "seabattle_2";
		break;
		
		case "seabattle_2":
			dialog.text = "���! ��, ��� ��� �����-�� ������, ��� ������ �����, ���...";
			link.l1 = "��� ''���''?";
			link.l1.go = "seabattle_3";
		break;
		
		case "seabattle_3":
			dialog.text = "� ��� �� �������������? ����-�� ������������ �������� ���� � �� �������, � ��� ��� ��� ���� - �� ����. �� ����� ����� � �� ������ �������� �������� ������, �������� ��� ��������� ������������. ��� ���� ����� ������, ��������...";
			link.l1 = "�������, �� ����. ��� ���� ����� ������� ����� �� �����������. �����, �������� ������ ������. �����, �������!";
			link.l1.go = "seabattle_4";
		break;
		
		case "seabattle_4":
			DialogExit();
			AddQuestRecord("Sharlie", "16");
			pchar.quest.seabattle.win_condition.l1 = "location";
			pchar.quest.seabattle.win_condition.l1.location = "Martinique";
			pchar.quest.seabattle.function = "SharlieSeabattle_ship";
		break;
		
		case "Portugal":
			dialog.text = "��, ������� ��� ����, �������. ��� ����� �������, � ���� ������� �������. � ������ ��� �����, ��-��... ��� �����, � ��� � ��������!";
			link.l1 = "...";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			DialogExit();
			AddDialogExitQuestFunction("Portugal_enterPirates");
			npchar.quest.portugal = "true";
		break;


//-------------------------------------------------------------------------------------------------------------

		// �������� ������
		case "PrisonEscort":
			dialog.text = "� �� ���� ������ �� ����, �� ������, ��� ����� ���� �������� � ����������� �����������...";
			link.l1 = "��� �� �����? ��� �� ������?";
			link.l1.go = "PrisonEscort_1";
		break;
		
		case "PrisonEscort_1":
			dialog.text = "������� �� ����, � �� ������ �� ������" + GetSexPhrase("��","��") + " ������� ����� �������?";
			link.l1 = "������ ��, ������ �����������?";
			link.l1.go = "PrisonEscort_2";			
		break;

		case "PrisonEscort_2":
			dialog.text = "�������� ����������! � ��� �� ����� � ������� ���� ���������� ������ ���������� � ������� ������ ���� �� ������, ��� �������, ��� � �� ����?";
			link.l1 = "���� � ���� ������, ���� �� ��������. ������, ������ � ����� ������?";
			link.l1.go = "Barmen_check";
			
			pchar.questTemp.PrisonEscort_quest.LeFransua = 1;
			
			AddDialogExitQuest("PrisonEscort_EmilioMovo");
		break;


//-------------------------------------------------------------------------------------------------------------

		case "Barmen_check":

			dialog.text = "������ � �� ������! ��� ����� ������ ���"+ GetSexPhrase("��","��") +" �������, ��� ��. ��������� ��� ���������� ���� ��������, � ����� ��� �������� ��������������� � �������.";
			link.l1 = "������ ��� �����������, "+ npchar.name +".";
			link.l1.go = "barmen_history";
		break;
		
		case "barmen_history":
			dialog.text = "� �����, ������� ������. ��� ��� ��������, ��������, ������ ��������� ��������� � ���������� ����� ������ �����. � �� ���� ���������� ������ ������, � ������-�������� - ������� ������, � �������-��-��� - ���� �������, � � ��� - ���������� ������� � ��� ������ ���� ��� ��������. ������ ����� ��������� �������� � ������� � ��������� �������� � �������� ���� ����� ��� �����\n������ �� ����� ���� ������ � ���� �����. ������ ����� � ���������� ������������� � ����� ���������. ����� ����������� ��������� � ����������� ������ ��������������� ��������� � �������� �� ������� � ����� �����.  ��� �� ������ ���������� ������� � ����������, ������� � ��� ����, �� � ���������� �����... ��������� �����, ��������� �� ���� �������!\n� ���, ��������� �������, ������ �� ����� ��������... ���������, �������? � ��� �����, ���������� �������, �� �� �� ����� �����, �� �� ������������ �� ������ - ��� ������\n���� ���� ���������� �������� - ��� �������� �� ����������� ������, �� �� ���������� ������� ��������. ����� ����, �� ������� ���������� ������������ ����� � ���, ��� ��� �������� ���������� ���� ��������� ���������� � ����� ���������� ��������\n������� �� ���������� ������, ����� ��� ����������, ������� ������ ������ � ������� ������ ��������, � �������� ������ �� �� �������, ����� ������� ������ ������! ����� �������, �� ��� �������� ������ �� ����������� ����� ������� �����������\n����� ����, ���������� ��������� ���� �������, ��� ��� ������������ ���� ������, ������ ��� � �������� ������� �� ���������. ��������� ����� �������� ������ ��������, � ������ - ����������.";
			link.l1 = "��... � ������ �� ���� ��������� �����, � ������� �� ��������, �� ��������� ���������� � ��������, ����� �� ����� �� �������� ����� ���������� �������� � ��� ���������, ��� ����� ��������?";
			link.l1.go = "barmen_history_1";
		break;
		
		case "barmen_history_1":
			dialog.text = "��, �����"+ GetSexPhrase("�","���") +", ���� �� ��� ���� ��� ������. �������� ������ ��� �������� ����, ��� �������� � ����� ����� ������� ���������. ��� �������� �������� �������� � �� ���, �� ���������� � ��������\n�������, ������������ ��������� ��������� ����, ������ ����������� ��������������. ��� ���� ��������, ������, �� �������� ����������� � ��������� ��������, � ������ ��� �������� ���������.";
			link.l1 = "� ��� �������, �� ��� ��������� ��������������� � ���������� ���� ���� � ����������� ��������?";
			link.l1.go = "barmen_history_2";
		break;
		
		case "barmen_history_2":
			dialog.text = "��, ������ ���. ��������� ����� ������� ������������, � �������� � ������������ ���������� ��� ��� ������� �����������, ���� ������ �������� ��������� �� �� �� �����. ��������� � ���������� �� ������ ��� �����\n������ �� ���� � � ��� ����������� ��������. �� ������ ��������� � ��� ����? ������ ����� ������, � ��� ����������.";
			link.l1 = "�� ���� ��� � �����"+ GetSexPhrase("","a") +", ��� �������� ������ ���-�� ����� �������� �� ��������?";
			link.l1.go = "barmen_history_3";
		break;

		case "barmen_history_3":
			dialog.text = "������ ���. �� ���� �� ������� ���� �����? ��������, ���� ��� ����� ����� ������ ��������, � �� ������ �������.";
			link.l1 = "����� ������ ������ ��������������, ������ ��� � ��� ���� ��������?";
			link.l1.go = "barmen_history_4";
		break;
		
		case "barmen_history_4":
			dialog.text = "����������. ��������� � ��������� ����, � ������� � ��� ����� ����� �����������, ���������� � ������� ����, ��� �������� � �������� � ����������� ���� ���������, ����� ����� � ������� ��� ����� ���� � ������������ �������� ������ � ����������, � ������� ������ �����, ������, ������������ ��������� �����, ���������� ������ � ��������. ��� �������?";
			link.l1 = "��, �������������� ��������. �������, � ������ �� ��� ����.";
			link.l1.go = "barmen_history_5";
			link.l2 = "� �����-��? �� ������, ����� � �� ��� ����� � ������ ���������� ������������"+ GetSexPhrase("","a") +" �����, ��������� ��� ���� ����� ���������? ����� ������ � ������ �����.";
			link.l2.go = "exit_quest";
		break;
		
		case "exit_quest":
			dialog.text = "����. ������, � � ��� ������. ����� ������� �� ���� ���������.";
			link.l1 = "����� �������.";
			link.l1.go = "exit";
                                                                        AddQuestRecord("PrisonEscort1", "2");
			pchar.questTemp.Headhunter = "end_quest";
			CloseQuestHeader("Headhunt");
		break;
		
		case "barmen_history_5":
			dialog.text = "�����������! � ����� ���, ��� �� �����������. ����� ����������� �������������� �� ��� ������, ��� �������� �������� ��� ����� �������������� �� ������� �� ����������� �� ������ �����, ����� ���� �� �������� �������������� ���� ��������� �������\n������� ����� ���������� ������, �� � ������� �� ��� � ����� ������ ���� �� ������� ����������. ������ �� ������ ����������� �� �� ������.";
			link.l1 = "��, ������� �������� � ����. ���������� �����������, ��� �� ������ �� ���� �����? �����, ����� ����� ������?";
			link.l1.go = "barmen_history_6";
		break;
		
		case "barmen_history_6":
			dialog.text = "�������. ���������� � ����, ���� ��������� �������, ����� ������ ������ � ������, ������ � ��� ����� ������������� ��������� ���������� � ����� ����������. ����� ��� �������� ������� �� ������ �������� �������� � ��������������� �������� � ��������� �� �������\n��� �� ������ �������� � ��������� ��������, �� � ����� �������� ��������, ������������ ������ ������� ��������� � ����� ������ ����. �� ����� �� ����� ����� ������ ��� �� �������� ������ ������. ����� �����, ��� ������ �� �������� ��������� ��������� ������� ''����� �������� ����'', ���� ��������� ���������, ��� � ���� �� ����� ��������� �����. � � ���� ��� ��������� ��������, ��� ��� ������ ���.";
			link.l1 = "�������, ������ ����� ����� �������...";
			link.l1.go = "barmen_history_7";
		break;
		
		case "barmen_history_7":
			dialog.text = "��. ���� �� ���� �� ��� ������ � ���� � ������ ���� ���� ������� � ������� ��������� ��������� �����������, � ���� �� ��� � ��� ��� ��� ���� ������ �� ������ � � ����� �������� ��������, ������������ � �������, � ����� � ����� ���������� �������. ��, ���������, �� ����� �������� ����������\n��� ��������� ������������ �� �������, ��� ��� ��������� �� �� ����� ������� �������. �� � ���� ������� ����� ������� � ����� ����, � ��� ������ - ��� � ���� ����� ������ ��������� �������, ��-��... ��� ��� � ����� ��� � ��� ��� ������.";
			link.l1 = "��� ��, ���� ��� ��� ����. ������ � ������ �� �������� ����� ����� ���� ''��������� �����'', �� ��� ������� ������ ���� ���� ����� ����������.";
			link.l1.go = "Givetaskhunt_1";
		break;
		
		case "Givetaskhunt_1":
			SelectCarlosCity();			
			dialog.text = "��, ����� ���������. ������, ���� ��� ���������� ��������� � ������ ������, �� �������, �, ��������� ��� ��������, ���������� � ���������� �������� ��� ���� �������. ����� ��������� ���� ������� ������ ������� �����: �� ����� ������� ����� ����� �������� ��� � �������, ��� � ������� - ������ ��, ������ ����, �������� ������������ ������� �� ����� � �����. �� ���� ��������, ������������� ��� �������, ����� � ���������, � ���, � �����, ����� ��������� ������\n����� ����������� � ��� - ������������ ��������� ��� ���, ����� ��� ��������� ��� ����� - �� ���� �� ������ ������� � ��������, �� ��� ��? ���� �������� ����� ����� ������ ������ �� ��� ������ � �� �������� �� ��� ��������, ��������� � ��������� ������� �����, � �� ����������� ����� ��������� � �������� ���, ����� ��� �� ������\n������� �� ������� ������, �� ������� � ��� �� �� �� �����������, �� ����� �� ���� ������� ����, ��� �������, � �� ��������.";
			link.l1 = "�� ��� ��, ����� �� ���� ������ �������. ���������� � ����!";
			link.l1.go = "Givetaskhunt_1_1";
			pchar.questTemp.Headhunter = "hunt_carlos";
			pchar.questTemp.Headhunter.Chance = rand(1);				break;

		case "Givetaskhunt_1_1":
			dialog.text = "����� ��� �����. � ���: �� ������ �������, ���������� � ���� �����, ����������� ������ �� ���. ��������� ����... ������� �� � ���� ��������, ������ �� ��������� ���� ����� � �����, �� ������ �������������� �������������.";
			link.l1 = "� ��� �����"+ GetSexPhrase("","�") +". �� �������, " + npchar.name + "!";
			link.l1.go = "exit";
                                                                        AddQuestRecord("Headhunt", "1");
			AddQuestUserData("Headhunt", "sCity", pchar.questTemp.Headhunter.Cityname);
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","�"));
		break;
		
		case "Endtaskhunt_1":
			dialog.text = "�����������! ����� ��������� �� ���� ����� ����� ������. �� ����� ����������� ����������� �� ���� �����. �������� ���� ����� ��������� � ���� ������ � �������. ��������� ���� ����� ������ - � ���� ������ ����� ��������� ����������, ������� ������ ������ ��� � ������ ���������� �������.";
			link.l1 = "������� �� ������! � �� ������� ����� ������ ����.";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "next_task_2";
			SaveCurrentQuestDateParam("pchar.questTemp.Headhunter_next_task_2");
			AddMoneyToCharacter(pchar, 5000);
			TakeNItems(pchar, "chest", 1);
			Log_Info("�� �������� ��������� ������");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
			AddQuestRecord("Headhunt", "3");
		break;
		
		case "Givetaskhunt_2":
			if (CheckCharacterItem(Pchar, "patent_eng") || CheckCharacterItem(Pchar, "patent_fra") || CheckCharacterItem(Pchar, "patent_spa") || CheckCharacterItem(Pchar, "patent_hol"))
			{
				dialog.text = "�� ����� �� ������������ � ���������� �������� - ������ �� ������������� �����. � �� ���� ��� ���������, ��������.";
				link.l1 = "��, ����!";
				link.l1.go = "exit";
				CloseQuestHeader("Headhunt");
				pchar.questTemp.Headhunter = "end_quest";
				break;
			}
			pchar.questTemp.Headhunter.Chance = rand(4);
			pchar.questTemp.Headhunter.Chance1 = rand(1);
			SelectHoumCity();
			dialog.text = "��. ��� � ��� ������� - �� ������ ������� ����� ������ ���, ��� ������. ������� ��� ������� ������ ���-��� � ��������� �����. ��� ������ ���, ������, �������� � ������������. �������, �� �� ����� ������� ������ ������� ������� ������ ����� ������... ��-�-�\n��� ���. ������� �� ����� �� ����������� �������� �������, ������������ �������. ����� ������ ���������� ������������� ������� � ���  �������� ���. � ������ �� ���������� �� ���������� � ���������� ��������\n������, ���, ������� �� ���� � ����������� � ������ ��� ��� ����� � ''������� ������''. ��� �������� ����������� �������� � � ������, ���������� ��� ����� ������\n�������, ���� ��� ����� ���� ����� ��� ������� � �������� �� ����������� �������, ��� ��� ������ ����� ��� ���������� � ������ ������.";
			link.l1 = "������ ����. �������� �����!";
			link.l1.go = "Givetaskhunt_2_1";
		break;
		
		case "Givetaskhunt_2_1":
			pchar.questTemp.Headhunter = "Houm";
			AddQuestRecord("Headhunt", "4");
			//Log_Info("���� � ��������� � "+pchar.questTemp.Headhunter.Cityname+"");
			DialogExit();
		break;
		
		
		case "Endtaskhunt_2":
			dialog.text = "�����������. � ���, ��� �� ������ � ���. ��� ���� �������. ��������� �� ��� �������� ����� ��� - �� � ��������� ������ �������� ���������� �� �������� �������.";
			link.l1 = "������. ���� ����� ��� ������.";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "next_task_3";
			SaveCurrentQuestDateParam("pchar.questTemp.Headhunter_next_task_3");
			AddMoneyToCharacter(pchar, 10000);
			TakeNItems(pchar, "chest", 2);
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
			AddQuestRecord("Headhunt", "9");
		break;
		
		case "Givetaskhunt_3":
			dialog.text = "��� ��� ������, " + pchar.name + ". ��������� ���� ������� ��� �� �����. ������, ����� �������� ����������� ������ ���������, ������ ������.";
			link.l1 = "��, � �� �� ������"+ GetSexPhrase("","�") +", ��� ���������� ��� ''����'' ���� ������ �� ������ ��������... ������ ��� �����������.";
			link.l1.go = "Givetaskhunt_3_1";
		break;
		
		case "Givetaskhunt_3_1":
			if (CheckCharacterItem(Pchar, "patent_eng") || CheckCharacterItem(Pchar, "patent_fra") || CheckCharacterItem(Pchar, "patent_spa") || CheckCharacterItem(Pchar, "patent_hol"))
			{
				dialog.text = "�� ����� �� ������������ � ���������� �������� - ������ �� ������������� �����. � �� ���� ��� ���������, ��������.";
				link.l1 = "��, ����!";
				link.l1.go = "exit";
				CloseQuestHeader("Headhunt");
				pchar.questTemp.Headhunter = "end_quest";
				break;
			}
			dialog.text = "��������� ������ - ������ ����, ����� ���������, ��� �����. ������� ���, �� ������� ��� - ���������� ��������, �� �� ��� ������� ��� �� ���� ������� ��������� ��������. ��� ������ ��������, � ����� �� �������� ������ �����, ��� ���� ����� ''�����'' �� ��� ��������. ������ ����� � ������ ��������� �����, � ����� ��������\n���� ������� ���������� �������, �� �� �������� ������ ��� ������� ����� � ����� ����������� - ���������, ��������. ����� �������� ����� ���������� ����� � �������� ��������� ��������, ����� ���� ���, ��� ��� �� ���, � ����� ����� ������ �������... ���������, ���� � �����? ������, ��� ����� ���������� �� �� ���������.";
			link.l1 = "���-������ � ��������������� �����... ����� �������� ������?";
			link.l1.go = "Givetaskhunt_3_2";
		break;
		
		case "Givetaskhunt_3_2":
			dialog.text = "� ���������, �������. � ���� �� ���� �������, �� ����� ������� �� ����� - ����� ��������� ������ ��������, ������� �����. � ���� ���� ������� ����� �� ������� ����� ��������� ��� ��������� �����, � � ������������ �������, ��� �� �������, ��������� ����� � �����, ����� ��� ��������� ����������� � ���������������� ��������� �������� ���������������\n������ ���: ����������, �� �������, ���������, ��� �� �����, � ���-����, �� ������� �������� � ������.";
			link.l1 = "��� ���-��! �����, ��� ���� ������������ � ����.";
			link.l1.go = "Givetaskhunt_3_3";
		break;
		
		case "Givetaskhunt_3_3":
			dialog.text = "�������� ���� ������ - �� ������� ��� ������� ������������� �� ��������� �������. � ������� ��� � ���.\n��, � ������, ��� �� ������, � ���� ���� ��� ��������� �������. ������ - ������ ������, ���������� ������ ���, �� ��� � ��� �� ��������. ������������ ����� ������� ���, ����� ���������� ���\n ���� �� �������� ��������, ������ ����� ������ ���� �������� ������������ ����������, ���� ���� �� ��� ����� ����� ��� ������� �������� � ��������. �������� ��� ���, ��� ��� ���������, � �����, ����� �� ����� ������, ��� �������\n�� ��������� ��� ����: �����, ���� ��������� � ���� � ����� ���� ���������� ������. ���, ��������, � ���, �������. ������� �����.";
			link.l1 = "������� �� �����������. ����� ���� � �������� ���������.";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "Rat";
			pchar.questTemp.Headhunter.count = 0;
			pchar.questTemp.Headhunter.countC = 0;
			pchar.questTemp.Headhunter.countV = 0;
			pchar.questTemp.Headhunter.countP = 0;
			AddQuestRecord("Headhunt", "11");
			TakeNItems(pchar, "suit4", 1);
			Log_Info("�� �������� ������ ��������");
			PlaySound("interface\important_item.wav");
		break;
		
		case "Endtaskhunt_3":
			dialog.text = "�������� ������, " + pchar.name + ". � �������� �������� ����. �� �� ������ ������ �������, �� � ������ �����. �������� ����� - ��� �����, ��� ��������� ������. � ��� �� �����, �� � ��� ����������. ��� ���� ������ � ��������� �������\n�������� ����� ���� ����������-�������� - �����, � ����� ������� ����� ������� ��� ���������� �������� � ��������������� ���������� �������.";
			link.l1 = "�������! ���� � ��������� �����. �����!";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "next_task_4";
			SaveCurrentQuestDateParam("pchar.questTemp.Headhunter_next_task_4");
			AddMoneyToCharacter(pchar, 20000);
			TakeNItems(pchar, "chest", 2);
			TakeNItems(pchar, "amulet_"+(rand(9)+1), 1);
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
			AddQuestRecord("Headhunt", "25");
		break;
		
		case "Givetaskhunt_4":
			if (CheckCharacterItem(Pchar, "patent_eng") || CheckCharacterItem(Pchar, "patent_fra") || CheckCharacterItem(Pchar, "patent_spa") || CheckCharacterItem(Pchar, "patent_hol"))
			{
				dialog.text = "�� ����� �� ������������ � ���������� �������� - ������ �� ������������� �����. � �� ���� ��� ���������, ��������.";
				link.l1 = "��, ����!";
				link.l1.go = "exit";
				CloseQuestHeader("Headhunt");
				pchar.questTemp.Headhunter = "end_quest";
				break;
			}
			dialog.text = "������� ����. �� ���� ���, ������, ���������� ������ ������. �� ��������, ��� � ��������� ����� ����� ��������� ���� ����� - ��������� ������ ��� �����. � ������� ������ �� ������ ������� �� ���������� ���������� ����� � ����������. ��� ����� ������������ �� �������...";
			link.l1 = "�� ��� ��, �� �������� ������� ����� �� ������� �� ����������, ��� � ������� ���. ��� ������.";
			link.l1.go = "Givetaskhunt_4_1";
		break;
		
		case "Givetaskhunt_4_1":
			dialog.text = "���������, �������, ��� ��� �� ���. ������ ��� ����� - �� ������ �����, � ����� �� ������ ���������, ����� ����, �� ���� � ������ ������� ����. �� ��������� ��������� ��������� � ������������� �� ����� � ����� ������ ��������. ��� ������ ����������� � ��������, ������ ��� ���� ������ ���������. �� �����, ��� �� ��������� �� �����-���� ������\n��������, � ������ ������ �������� ����������� ������ ������ �����. �� ������ ��������� - ���� �������� �� ������ � ��������, ��� �������� ��������� �� ���� ���������� �����������.";
			link.l1 = "������, � ���� ���. �� �������, " + npchar.name + ".";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "hunt_halen";
			AddQuestRecord("Headhunt", "26");
			SetFunctionTimerCondition("Headhunter_HalenOver", 0, 0, 10, false);
		break;
		
		case "Endtaskhunt_4":
			dialog.text = "� ���. ���� ������, ��� � ���, ��� �� ����������� ������ ���. �� �������� ����������� �������, " + pchar.name + ". ��� ���� ������� - ������ � �������. �...";
			link.l1 = "���������, " + npchar.name + ". � ��� ��������� ��������. ������, � ���� ��������� ��������. ���� ������ � ����. ׸���� ������ �����-�� ������� ����� � ���, ��� ���������� ��� �����. � ����������� ���� �������� ����� ����������� �� �������.";
			link.l1.go = "Endtaskhunt_4_1";
			AddMoneyToCharacter(pchar, 25000);
			TakeNItems(pchar, "chest", 2);
			TakeNItems(pchar, "obereg_"+(rand(9)+1), 1);
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
		break;
		
		case "Endtaskhunt_4_1":
			dialog.text = "�������, �������... ������� �� �������? �� ���, ����� ��� �����. ���... ������ - ���� �� �������? ��� �� ������, ��� �� ������� ������ ��? ��� ��� ���������?";
			link.l1 = "���... ����� ���, ��� ������� �� ����, ��� �������� ��� ������... �� ׸���� ������. ���������? ��� � ������, � ������ � � �������� �� �����������.";
			link.l1.go = "Endtaskhunt_4_2";
		break;
		
		case "Endtaskhunt_4_2":
			dialog.text = "��. ��� ��� ����. ��� ������� ��������. � �-�� ��� ����� ��������...";
			link.l1 = "" + npchar.name + ", �����������. ���� ��� ������ ������ �� ������ �� ��� ����, � � ������ ���� �� ���� ��������. ��, ��� �� ��� ���� - ��������, ��� � � ����� �������, � ��� ����� ''��������� �����'', � ������� �� ��������, ��� ���� ����������.";
			link.l1.go = "Endtaskhunt_4_3";
		break;
		
		case "Endtaskhunt_4_3":
			dialog.text = "��� ���������.";
			link.l1 = "��� ��������. �� ���������, ��� ����� �� ���� ����. ���� ���������� �������� ����������� ����. ���� ����������� � ���� ����� � ������ ������� �� �������, �� ������� ������ ������ ��� ������, ����� ���� ����� ������ ���������� � ����������. ��� ������ ���������� ����� �� ������ ������!";
			link.l1.go = "Endtaskhunt_4_4";
		break;
		
		case "Endtaskhunt_4_4":
			dialog.text = "� ���������� ���������� ������������ ������� ���� ���������� � ��� �����-������, ������ ���� �������. ������ ���������� ������� �� �������, �� ��������� ��� ��� ������ �� �������� ������ �������, � ������� �������. �����������, ��� ������ �� ��������� ������ ���\n��� ���, ��� ��� ��������. ��������, ��� �������� ������ ������ �� ������ ����������, ����� ��� �������. ������ ������ - ��� ������: ��������.";
			link.l1 = "���������� ����������. ���������� ����������� � ������. � ���, " + npchar.name + ", � ��������� ���� ������ ����������, ������ ��������� �� ���� ����� � ����, � �� �������� �� ��������� ������. ��� �� ����� �� �������� �������� ������ ������������... �� ��������� ������.";
			link.l1.go = "Givetaskhunt_5";
		break;
		
		case "Givetaskhunt_5":
			dialog.text = "������� �� ������... �������� ����� �������������. ���������� ����������. ������������ �� ��������, � ��� ������� - ������������. ������� �� ���������� �� ����� ���������������� ����������. ���������� ��������� � ���� ������� � ���� ��� ��������. ������ ��������� - �� ����� ���������� ��� � ������, ������ ��� �� ������� �������� ������.";
			link.l1 = "� �� ����� ������� ������... ����� ����� ����������� � �������� ����, " + npchar.name + "!";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "hunt_miko";
			AddQuestRecord("Headhunt", "33");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("��","��"));
			CreateMiko();
		break;
		
		case "Endtaskhunt_5":
			dialog.text = "��-�... �������-�� ����� ��������� ������ ������. " + pchar.name + ", �, �� � ��� ������ �� ������� ������� �� ������� ����, ��� �� ��� ��� �������. ������ - ��� ������ ����� ����� ����. ������� ��� ������ � ���� �������� ��������, ��� � ��������������\n��� ��� �������� �������. �� ���� �� �������������, ��� ��� ��� �������. �������� �� ��� ���� - ��� ��� ������ � ���� ����� ����� ������ ���.";
			link.l1 = "����� ��� ���, " + npchar.name + ", � ������ ���� �������! � ������ ��������"+ GetSexPhrase("","�") +" ������� ������ ��������... � �� �������� �������, ��� ��� ����� ����������. �� � ������, �������, ����.";
	                                              	if (sti(Pchar.sex))
		                       {
                                                                        Pchar.sex = "man";
			link.l1.go = "Endtaskhunt_5_1";
			AddMoneyToCharacter(pchar, 100000);
			TakeNItems(pchar, "blade_28", 1);
			TakeNItems(pchar, "pistol11", 1);
			TakeNItems(pchar, "spyglass5", 1);
			TakeNItems(pchar, "cirass3", 1);
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+20;
			TakeNItems(pchar, "talisman9", 1);
	                                               }
	                                               else 
	                                               {
	                                               Pchar.sex = "woman";
			link.l1.go = "Endtaskhunt_5_1";
			AddMoneyToCharacter(pchar, 100000);
			TakeNItems(pchar, "blade_28", 1);
			TakeNItems(pchar, "pistol11", 1);
			TakeNItems(pchar, "spyglass5", 1);
			TakeNItems(pchar, "cirass3", 1);
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+20;
			TakeNItems(pchar, "talisman9", 1);
	                                               }		
		break;
		
		case "Endtaskhunt_5_1":
			dialog.text = "����� ���, " + pchar.name + ". ����� ����� ��� ��� ����� ������ ��������! �������, �� �� �������� ������� �������, � ������ ����������� ���� ������.";
			link.l1 = "����������, " + npchar.name + "! �� ��� �� ��� ��������. �� �������!";
			link.l1.go = "exit";
			AddQuestRecord("Headhunt", "39");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","�"));
			CloseQuestHeader("Headhunt");
			pchar.questTemp.Headhunter = "end_quest_full";
		break;
		//<--���

		//�������, ����� �2, ������ ����� ��� ���
		case "PL_Q2_1":
			dialog.text = NPCStringReactionRepeat("��� �� �� ���������? ����� ���� ���������.", 
				"� ��� �������, ��� ���������.", 
				"���������, ���������...",
                ""+ GetSexPhrase("������","�������") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("� ��� ��� ��� �����, �� ����������?", 
				"��-��, � "+ GetSexPhrase("�����","������") +"...",
                ""+ GetSexPhrase("�����","������") +"...", 
				"...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("PL_Q2_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
		break;
		case "PL_Q2_2":
			dialog.text = "������ � �� ����������? ��������, "+ GetSexPhrase("�������� ��������","����� �������� �������") +" � ���������� �������.\n��� ��� ����� ������ ������. ���� ����� ����� �� �������, ��������� �������. ��� �������� ���������� � ���� ��� ������� ���.";
			link.l1 = "������� ����, ��������!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_2_BlackLabel", "2");
		break;
		//�������, ����� �3, ������ ���
		case "PL_Q3_1":
			dialog.text = NPCStringReactionRepeat("�-�-�, "+ GetSexPhrase("������� ��, ��������","�������� ��, �������") +". �� ���� �� ������, ������ ����.", 
				"��� ������� ����, ��� ��� ���� �� ������.", 
				"���� ��, ����...",
                "��, � �� ���� �� �� "+ GetSexPhrase("�����������","�����������") +"!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("���� ����?", 
				"��, � �����.",
                "��, "+ GetSexPhrase("�����������","������������") +"...", 
				""+ GetSexPhrase("�����","������") +", �����...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("PL_Q3_2", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "PL_Q3_2":
			dialog.text = "�� ��� � ��� �����?  ��� ������ ��������� � ����... �������, ���� �������-�� �� ������, � ��� ������. ������, �������, ��� ���� ������� ��������� ����. ������, ��������� ������. �� ������, �������-�� � ��� ���������...";
			link.l1 = "�� ������ �� �� ����� ��������. �� ����� �����, ��� ��� ��� ������ ������?";
			link.l1.go = "PL_Q3_3";
		break;
		case "PL_Q3_3":
			dialog.text = "��, �� ����... �������, �� ������� ����� ��������. �� ����� ���������, �����, ��� ���� �����, �����, ��� ���� �����. � �-�� �� ����, �� ���� �� ��� �� ��������-�� �� �����. � ������� ������� ���...";
			link.l1 = "�������... ������� ����, �������.";
			link.l1.go = "exit";
		break;

	                                      //������ � ����� ����

        	                      case "Smithy_1":
			dialog.text = "� ����� ��� ���, �������?";
			link.l1 = "��, ������ ��... � ������, ��� ��� ��������� ������ � ���� ����� ��������. � ��������� �������� �������, � ��� ����� ������, �� �... ��������, �� ����� �� ������ ���� �����.";
			link.l1.go = "Smithy_2";
		    break;

        	                     case "Smithy_2":
		  if (pchar.questTemp.GothicSmithy == "Smithy_LeFransuaTavern")
			{
			dialog.text = "��, ���-�� �� ��� �� ���������, �������, � ��, ��� �� ���������� - ��� ���� �� ��������. ��... � �����, ��, ������ �����, ������ � ���� ������ ���� �����. ��� ������ 10 000 ���� �� ���������� � �����?";
			}
		   if (pchar.questTemp.GothicSmithy == "Smithy_LeFransuaTavern_Sec")
			{
			dialog.text = "������� �� ����������, ���, 10 000 ���� �� ���������� � ����� � �����!";
			}
	                      if(sti(pchar.money) >= 10000)
			{
			link.l1 = "�� ��� �, ���, ���������� �� ���������.";
			link.l1.go = "Smithy_3";
			}
			link.l2 = "׸�� ������ ��� ������ - ��. ����� ����� ������ ��� ��� �� ����������? ���� � ��� ���-������ ����-������ �������� �� ������?";
			link.l2.go = "Smithy_4";
			link.l3 = "� �� ��� ���� � �����!";
			link.l3.go = "Smithy_5";
		break;

        	                   case "Smithy_3":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		                   AddMoneyToCharacter(pchar, -10000);
			dialog.text = "";
			link.l1 = "��� ��� ������...";
			link.l1.go = "Smithy_3_1";
		break;

        	                   case "Smithy_3_1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			dialog.text = "�������. ��� ������, �������, �� � ���� ���������� ������ ���� �����. ������ ��������. ������ ���� �������� �������� � ��������� ����� ������, ��� � - ���� ��� ��� ����������, � �, ������ �����, �� ��������! ��� ���, ��� �� �� �� ��������, ����������� ��� ����� �� ������. ����� ���, �������.";
		                  link.l1 = "�������, � ��� - �� � �� ������� �� ����. ��������.";
			link.l1.go = "Smithy_exit";
		break;

                                                         case "Smithy_exit":
		                   DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.Smithy_LeFransuaTavern = "true";
		                   npchar.quest.Smithy_LeFransuaTavern_Sec = "true";	                            		AddDialogExitQuestFunction("Gothic_Smithy_pirat_house");
		                   break;

        	                   case "Smithy_4":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
			pchar.questTemp.GothicSmithy = "Smithy_LeFransuaTavern_Sec";
			dialog.text = "��-��-��, �������-�������, �������. ��� �� ��� ���-������ �������� �� �������.";
			link.l1 = "";
			link.l1.go = "exit";
		break;

        	                  case "Smithy_5":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_16.wav");
			pchar.questTemp.GothicSmithy = "Smithy_LeFransuaTavern_Sec";
			dialog.text = "�� ������, ��� �� ������, � ���������� ������ �� � ����. ���������, ����� �����������.";
			link.l1 = "";
			link.l1.go = "exit";
		break;

        	                      case "Smithy_Sec1":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_9.wav");
			dialog.text = "...";
			link.l1 = "�� ���� ������� �������� - ���... ���������, ���� ����� � ������ �� ��� �� ����������. ������� �� ������ ���� - �����?";
			link.l1.go = "Smithy_Sec2";
		    break;

        	                      case "Smithy_Sec2":
			dialog.text = "�, �, ���, ���... �, ���, �, � �� ������?";
			link.l1 = "����, ����, ������ - �� ������, ������ - �� ������?";
			link.l1.go = "Smithy_Sec3";
		    break;

        	                      case "Smithy_Sec3":
			dialog.text = "�������, ������� ���� � �������, ����� ����...";
			link.l1 = "������, � ��� � ������ ����!!!";
			link.l1.go = "Smithy_Sec4";
		    break;

        	                      case "Smithy_Sec4":
			dialog.text = "����� � ���� ����� ������� ������ ������ ����� � �� ��� ������� ������� � ����� ������� � �������� �� ����, �� ������������� ���� ��������, ����� ������, ��� ����� �������������� ������ �����, ����� � �� �����������. � ��� � ������, � ���� ������ ������.";
			link.l1 = "����� ������ ����! ��� ��, ��� � ����� ������, �� ��, ����� � ������ �� ���� ��������� ����������, �� ���� � ���� ������ ����� ���� - �!!!";
			link.l1.go = "Smithy_Sec5";
		    break;

        	                      case "Smithy_Sec5":
			dialog.text = "";
			link.l1 = "�������� �� �����, ��� ���� �� �����? �� ������ �� ������� ��� �������...";
			link.l1.go = "Smithy_Sec6";
		    break;

        	                      case "Smithy_Sec6":
			dialog.text = "��, ��, �������... ��� ���� ������...";
			link.l1 = "";
			link.l1.go = "Smithy_Sec7";
		    break;

        	                      case "Smithy_Sec7":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "������...�������� ��������?";
			link.l1.go = "Smithy_Sec_exit";
		    break;

                                                         case "Smithy_Sec_exit":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                                         AddMoneyToCharacter(pchar, 100000);
		                   DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.Smithy_LeFransuaTavern_Sec2 = "true";	                            		AddDialogExitQuestFunction("Gothic_LeFransuaTavern_2");
		                   break;



	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

