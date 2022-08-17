#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06

	switch(Dialog.CurrentNode)
	{
		case "First time":
			// --> �������
			if (CheckAttribute(pchar, "questTemp.Caleuche.SeekAmulet") && drand(1) == 0 && sti(Pchar.money) >= 2000) 
			{
				dialog.text = "����������, ��������, �� ������� ���������� ���� �������� ������? �������� ������, ����� �����-�� ���� ����� ����...";
				link.l1 = "��. ������, ������ ��� '������', � ������ ��������� ��� ��������?";
				link.l1.go = "caleuche";
				break;
			}
			// <-- �������
			if (npchar.quest.meeting == "0")
			{
				dialog.text = LinkRandPhrase("������������. ���� ����� " + GetFullName(npchar) + ". �� �����, ��� ��� ���� �� ������� �� ���� �������������, ��, ��������, �� ��������� ��� ���...", 
					"����������� ���, " + GetAddress_Form(NPChar) +  ". ���� ����� " + GetFullName(npchar) + ".", 
					"��� ��� - " + GetFullName(npchar) + ", " + GetAddress_Form(NPChar) + ". ��� � ���� �������������.");
				link.l1 = RandPhraseSimple("�����������.", "������������.");
				link.l1.go = "First time";
				// ��������� �����
				if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy_drink" && pchar.location == "portobello_town")
				{
					link.l2 = "��������, �� ������ �� ������ ������ ��������� ���������� ����-������ ����� ����, �?";
					link.l2.go = "trial";
				}
				npchar.quest.meeting = "1";
			}			
			else
			{
				dialog.text = NPCStringReactionRepeat("��, ��� ������, �� ���� ���������...", 
					"���� ��������� ��������...", 
					"�������� �� ��� ��������� �� ������!",
					"����� ��?..", "block", 1, npchar, Dialog.CurrentNode);

				link.l1 = HeroStringReactionRepeat("����. ��, ������ ���������.", 
					"��� � �������. �� ��� ������ �� ������������, ����...",
					"����� ���� ����� �� ��������� ����� �����, � ���-�� ������ ��� �����.", 
					"���. ������� "+ GetSexPhrase("������","�������") +"?", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "pester", npchar, Dialog.CurrentNode);
				link.l2 = RandPhraseSimple("��� ���� �����?", "���� �� ������?");
				link.l2.go = "Whants";
				// ��������� �����
				if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy_drink" && pchar.location == "portobello_town")
				{
					link.l2 = "��������, �� ������ �� ������ ������ ��������� ���������� ����-������ ����� ����, �?";
					link.l2.go = "trial";
				}
				link.l3 = LinkRandPhrase("���-������ ���������� ��� ����������?", 
					"��� ������ � ������?", "��, � ������������� "+ GetSexPhrase("��������","���������") +" �� ��������� �������...");
				link.l3.go = "rumours_poor";

				// --------------- ������� ��� ---------------
				if (pchar.questTemp.LSCC == "SignOnPoorMurder" || pchar.questTemp.LSCC == "PoorIsGood")
				{
						link.l4 = "������, � ���� � ���� ���� ���� ������. ����� ��������, �� ������ ������...";
						link.l4.go = "GoodTalk_1"; 
				}

				//����� ������ � ������� �����������
				if (pchar.questTemp.LSCC == "CanFoundStuvesantKey" && !CheckAttribute(npchar, "quest.CanFoundStuvesantKey"))
				{
					link.l5 = "��������, ��� �������, ��� � "+ GetSexPhrase("�����","�����") +" � ���������� ���� ����� ������ ����������!";
					link.l5.go = "FoundLetter";
				}

				//����� � ���, ��� ����� ������� ������ �� �����
				if (pchar.questTemp.LSCC == "readyGoLSCC" && !CheckAttribute(npchar, "quest.readyGoLSCC"))
				{
					link.l5 = "�� ������, ��� ������� ��������� ���� ������!";
					link.l5.go = "GoLSCC";
				}

			}
			NextDiag.TempNode = "First time";
		break;

		case "pester":
			dialog.text = RandPhraseSimple("�� ���, ������ ����� "+ GetSexPhrase("������","�������") +"? � �� ����� �����, ��� �� "+ GetSexPhrase("���","����") +" ������...", 
				"�� "+ GetSexPhrase("������","�������") +", �� �������� "+ GetSexPhrase("������","�������") +". � ���� � �����, �� ���� �������.");
			link.l1 = "���, ����...";
			link.l1.go = "exit";
		break;
		//������
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//���������
		case "Whants":
			if (!CheckAttribute(npchar, "wants_date") || GetNpcQuestPastDayParam(npchar, "wants_date") >= 1 || bBettaTestMode)
    		{
				dialog.text = PCharRepPhrase("��, " + GetAddress_Form(NPChar) +  ", � ��� ����� ��������� �����. �� � ���� � �����, ���� � �����, ��� ��. � ����� ���� ��� ����� �� ��� � �����, ���������.",
					"����� ���, " + GetAddress_Form(NPChar) +  "! �� �������� ��������� ����������� ��������, ������� �� ����������...");
				link.l1 = RandPhraseSimple("������ ���� �� ���.", "����������.");
				link.l1.go = "exit";
				Link.l2 = "������. � ������� ���� ����� �����?";
				Link.l2.go = "Whants_1";
			}
			else
			{
				dialog.text = PCharRepPhrase("�� ����? ������.", "������ �� �����, " + GetAddress_Form(NPChar) + ", �������.");
				link.l1 = RandPhraseSimple("��, �� �����.", "����� ������ ������� ����, ��������.");
				link.l1.go = "exit";
			}
		break;
		case "Whants_1":
			dialog.text = "� �� ����� �������� �� ��������, " + GetAddress_Form(NPChar) + ". ������� ��� �������� ���� ������� � ����������...";
			Link.l1.edit = 2;			
			link.l1 = "";
			link.l1.go = "Whants_2";
		break;
		case "Whants_2":
			SaveCurrentNpcQuestDateParam(npchar, "wants_date");
			int iTemp = sti(dialogEditStrings[2]);
			if (iTemp <= 0 || sti(pchar.money) < iTemp)
			{
				dialog.text = "������ �������� ���� �������� ������...";
				link.l1 = "��-��-��, � �� ��� �����, ��������, � ���� ����� ���?!";
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", -2);
				break;
			}
			if (iTemp > 0 && iTemp <= 100)
			{
				dialog.text = "������� �� " + FindRussianMoneyString(iTemp) + ", " + GetAddress_Form(NPChar) + ". � ����� ����� �� ��� ������...";
				link.l1 = "�����, ��� ����������, �������.";
				link.l1.go = "exit";
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 100 && iTemp <= 500)
			{
				dialog.text = "������� ���, " + GetAddress_Form(NPChar) + ". ���� ����� ��� ������ �� ������!";
				link.l1 = ""+ GetSexPhrase("��� ���","���� ����") +" ������.";
				link.l1.go = "exit";
				OfficersReaction("good");
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 500 && iTemp <= 1000)
			{
				dialog.text = "��������� ���, " + GetAddress_Form(NPChar) + ". � ���� �������� � ����� �������!";
				link.l1 = "��, ��� �� �����������...";
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", sti(iTemp/2000+0.5));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 1000 && iTemp <= 5000)
			{
				dialog.text = "������� ���, ���������"+ GetSexPhrase("��","��") +" " + GetAddress_Form(NPChar) + ". �� ������ ��� �������...";
				link.l1 = "��, ��������������� ������� ��� �� �������� �� �����!";
				link.l1.go = "exit";
				ChangeCharacterNationReputation(pchar, sti(NPChar.nation), sti(iTemp/10000+0.5));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 5000 && iTemp <= 10000)
			{
				dialog.text = "������� ���, "+ GetSexPhrase("�����������","�����������") +" " + GetAddress_Form(NPChar) + ". ����� ��� �����!";
				link.l1 = "�������, ��������.";
				link.l1.go = "exit";
				AddCharacterExpToSkill(pchar, "Leadership", sti(iTemp/5000));
				AddCharacterExpToSkill(pchar, "Fortune", sti(iTemp/5000));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 10000)
			{
				dialog.text = "����������, " + GetAddress_Form(NPChar) + ", �� � ����� ���? �� ������� ��� " + FindRussianMoneyString(iTemp) + "! � �� ������ ����� ������, ��������, ����� �����-�� ������... �������!";
				link.l1 = "��, ��� ������...";
				link.l1.go = "exit";
			}
		break;
		
		case "trial":
			dialog.text = "�����������, ������! �������, ����. � ��� ��� ����� ���� ����� �������? �� �� �� ������ ��� ������ ��� ������.";
			link.l1 = "�������, �� ������ ���. ������ �����������. � �������� ��������� ������ �����������. ��� ��������� �������, ��� ���-�� �� ����� ��������� ����������� ����� ��� �������, '����������', �� �����. �������� ��� ���������� ���������� ����� �������� ������ ������������ ������...";
			link.l1.go = "trial_1";
		break;
		
		case "trial_1":
			dialog.text = "";
			link.l1 = "���������� �������� ��� ��������� ��� ������, ������ ����������� � �� �������������. ����� ������, ��� � ������ ���������� ������. ����������� � ����, ������, ����������� � ������� - ������ ����� '����������' �� ��� ��� �� ������ � ������ � ����...";
			link.l1.go = "trial_2";
		break;
		
		case "trial_2":
			dialog.text = "";
			link.l1 = "���� ����� �� � ��� �� ����������, �����, ��� � �������� �����������, � ��� ����� ����� ������ �� ������ - ����� ������, �� ���� � �������. ���� ������� ���-������ ��������� �������� - �������� ��� ������ ����. ����� �� ���� '������' ������� �� ��������.";
			link.l1.go = "trial_3";
		break;
		
		case "trial_3":
			dialog.text = "��� ������ ����? ����������� ��������...";
			link.l1 = "�� ���, ����������? ���� ������� ��� ����, �� ���� ���� �������� ����� ���� �� ����� - �������� ��� ��� ������. �����?";
			link.l1.go = "trial_4";
		break;
		
		case "trial_4":
			dialog.text = "������, ������. ������, ���, �� ������� - � ���� ���� ��������� ��������, ������� ������ �������� �� ����� �����. ��, � ���� �����-�� � ���� ��� �������. ��� �����, � ������� ��� �����...";
			link.l1 = "���������� ���� ������� �����. ����������� ������� ������� ����� ����������� �� �����. ������ ������.";
			link.l1.go = "trial_5";
		break;
		
		case "trial_5":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload5_back", "none", "", "", "OpenTheDoors", 10.0);
			LAi_RemoveLoginTime(npchar);
			pchar.questTemp.Trial = "spy_poorman";
			pchar.quest.trial_spy_poorman.win_condition.l1 = "Timer";
			pchar.quest.trial_spy_poorman.win_condition.l1.date.hour  = 23.00;
			pchar.quest.trial_spy_poorman.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.trial_spy_poorman.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.trial_spy_poorman.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.trial_spy_poorman.function = "Trial_SetPoormanInPort";
			SetTimerCondition("Trial_ReturnPoormanNorm", 0, 0, 1, false);
			AddQuestRecord("Trial", "15");
		break;
		
		case "trial_6":
			dialog.text = "������ �����, ��������...";
			link.l1 = "�� ���, ����� ���-������?";
			link.l1.go = "trial_7";
		break;
		
		case "trial_7":
			dialog.text = "�����, ������, �����. ������, �� ������ �������, ��� ��� ������� � ������ �������... �� ������ ��������? ���� ����� ����?";
			if (sti(pchar.money) >= 5000)
			{
				link.l1 = "�� ���������. ��� ���� ������. �����������.";
				link.l1.go = "trial_8";
			}
			else
			{
				link.l1 = "������� ����������, ����� ������. �����, �� ���� �����!";
				link.l1.go = "trial_fail";
			}
		break;
		
		case "trial_fail":
			dialog.text = "�� ��������� ���� ������, ������! �� ������ ������� ������ - ��������� ��� ����. � ���� �� ������ ��������� �� ���� �������� - ������ ������!";
			link.l1 = "...";
			link.l1.go = "trial_fail_1";
		break;
		
		case "trial_fail_1":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 10.0);
			pchar.questTemp.Trial = "spy_fail";
			AddQuestRecord("Trial", "16");
			sld = characterFromId("Florian");
			sld.DeckDialogNode = "florian_failspy_5";
		break;
		
		case "trial_8":
			AddMoneyToCharacter(pchar, -5000);
			dialog.text = "���� ������� ���. '����������' � ������ � ���� ��� ����� ������, �� �� ��������� �� ������ ��� ��������, ������ �� ������� ������ �����������. ��, ��� ��� ��� �������. � �������� ������ ������ ������ ������ ������, ������� �� ����� ����� � ���� ����� �� ������\n��� ���� ������� ������-�� ���������-������ �� ���������. ���� � ���, ��� �� '����������' �������������, �� ������ ��������, ����� ������. ��� � ����, ���� '�����' �������� ����� ��� '����������'\n�� ���� ��� �������� ��� �������� �������, ��� ��� ���� '�����' �� �������� ����� ��� ��� - '����������' ���������� � ���� � ���...";
			link.l1 = "�� ��? � ��� �� ���� ����� ������? ���?";
			link.l1.go = "trial_9";
		break;
		
		case "trial_9":
			dialog.text = "�� ���� �� �������� '����������', ������ �������... �� ����� �� ����� ������� �� �����, �� � ��� �������� ���������� ��������...";
			link.l1 = "��� ����. ����� � � ������. ���������� �����, ��� ���� ��������! � ������ ������� ����������� ������, � ������ ���������-���������� ����� ������ ��� ���� ������ ��� ���������! ��, � ������� �� ���� ������ �������! � ������ '����������', �� ��, ��� ��������� ���������� �� �����!";
			link.l1.go = "trial_10";
		break;
		
		case "trial_10":
			dialog.text = "�?.. ��� �� ���, ��� �����? �� ����� �����?.. � �� � ��� �� �������! �� ���� ��������� ����!";
			link.l1 = "�� ��-�� ������ �� ����������. ������ �� �����, ��� ������ '����������' �������� ��������� ����� ����� ����������, ���� ���������! ���, �� ������ ����. ��������� �� ������! ������, ����� ���� ������.";
			link.l1.go = "trial_11";
		break;
		
		case "trial_11":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 10.0);
			pchar.questTemp.Trial = "spy_win";
			AddQuestRecord("Trial", "17");
			sld = characterFromId("Florian");
			sld.DeckDialogNode = "florian_12";
		break;
		
		// --> �������
		case "Caleuche":
			dialog.text = "���������, ������ ��������... � �� ������� ������� � ����� � ������-�� ���������, ����� - ������������ �������� ������, �� ��������: � ����� ��� �� ��������, � �������� ���������� �����������. � ��� �� - �����, �������, ������� ������ - �������, ��� ��� � ����������� ��\n�� ��� ��� ��� ���� ����� - ����� ������, � ��� - ����� ����� � ������ ���� �� �����. ���������, ��������...";
			link.l1 = "�����, ���������...";
			link.l1.go = "Caleuche_1";
		break;
		
		case "Caleuche_1":
			Log_Info("�� �������� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "���...";
			link.l1 = "���-���... �������� ������, ��������. ���� �������� �� ��������� ���������. ������, � ������� ��. ��� ��� �������.";
			link.l1.go = "Caleuche_2";
		break;
		
		case "Caleuche_2":
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = "�������, ���������� ��������! �������, ��� ���� �������� ��� �����! �� ������ ��� �������!";
			link.l1 = "� ���� ���������, ��������. �� ������ ������ ��� ������ �� ���� ��� � ������.";
			link.l1.go = "Caleuche_3";
		break;
		
		case "Caleuche_3":
			DialogExit();
			GiveItem2Character(pchar, "kaleuche_amulet1"); 
		break;
		// <-- �������


		//������� ���, ��������� �� ����� � ������ ����� ������

		case "GoodTalk_1":
			dialog.text = "�-��, �-��... ����?!!";
			link.l1 = "��-�-�, ��� ���� �������... � �����, ���� ��� ����, ������� �� ��� ����� � �����.";
			link.l1.go = "GoodTalk_1_1";
		break;
		case "GoodTalk_1_1":
			dialog.text = "� ���� �� ����, ��� � �������... "+ GetSexPhrase("���","����") +", ��������, ���������, ��� �� ���� ���������, ��������� � ��� �����������������.";
			link.l1 = "���������, ����� ������ ����� ������?";
			link.l1.go = "GoodTalk_1_2";
		break;
		case "GoodTalk_1_2":
			dialog.text = "������?! ��-�-��, ��� ���� ��. ��������, ��� �� �������� ���� �� ������? ���� ��� ������.";
			link.l1 = "���, � ��������� ������, ��� ������. � �����, �� �� ������, ��� ����� ���� ���� �������������, � ��� �������.";
			link.l1.go = "GoodTalk_1_3";
		break;
		case "GoodTalk_1_3":
			dialog.text = "�� ����, �������! �� �� � ���� "+ GetSexPhrase("�������","��������") +".";
			link.l1 = ""+ GetSexPhrase("�������","��������") +" � ����� �������������, ��� �������. ���� ����������, ��� �� ���� �����... �� �����, ���� ���������, ����.";
			link.l1.go = "GoodTalk_1_4";
		break;
		case "GoodTalk_1_4":
			dialog.text = "������ �������.";
			link.l1 = "��. � ������ ����.";
			link.l1.go = "PoorHeadMan_1";
		break; 
		//�������� �������
		case "PoorHeadMan_1":
			dialog.text = "�� ��� ��, ��� ������. ��������� � ���� ������, �� ��������� ������ � �����, ������� �� ������� ��������. ������ ��������� ������, ��� ��� ������ ��� �������. ��� ���������?";
			link.l1 = "�� ��. ������� ������, ��� �� �������, � ������ ������.";
			link.l1.go = "PoorHeadMan_2";
		break;
		case "PoorHeadMan_2":
			dialog.text = "��, ��� ������������ ������... � ��� ����� ���� ��������, ��� ������� � ����� �� ����?";
			link.l1 = "������ �����.";
			link.l1.go = "PoorHeadMan_3";
		break;
		case "PoorHeadMan_3":
			dialog.text = "��� ��� ��� ���������... � �����, ���� � ���� ���� �����������.";
			link.l1 = "�������.";
			link.l1.go = "PoorHeadMan_4";
		break;
		case "PoorHeadMan_4":
			dialog.text = "���� ���� ������� � �����������, �� �������, �������, �� ����� ������, ����� ��������� �������� � ���, ��� ��������� � �����. � �����, � ��� ��� ���� ������� �� ���������, ������� ����� ������������ � ����������, �� �������. ����� ��� ����� ���.\n"+
				"��� ���, ������ �� ��� ����� ������, � �� ���������� ����� ������� ������� �� ����� ����������� ������� ����. � ��� ��� �������� � ������ �������� �� � ��������� � ������, �� � �����������... � ����� ������� ��� �� �����������, � ������ � ��� ������ �� ��������.";
			link.l1 = "��, � ����� ��� ��������� ����� � ����� ����?";
			link.l1.go = "PoorHeadMan_5";
		break;
		case "PoorHeadMan_5":
			dialog.text = "������ ������. ������ �� ��������, ��� � ���� � �������, ���� �� ������, � �������� ���-��� � ����. �� ���� ���� ��� �����, �� ��� - ����� ������� ��������� ����� � ����� ���� �� ������!\n"+
				"�� �������� � ������ �������������� � ����������� ����-������� ���������, � ��� ����� ���� ������ - �����������.";
			link.l1 = "�� � ���?";
			link.l1.go = "PoorHeadMan_6";
		break;
		case "PoorHeadMan_6":
			dialog.text = "� ��, ��� ����� ��� ���� - ������ ����. �� �������, �� ����������� � ������? ������ ���������, ������ �� �������� ������������� ��� �������� ������ ����� ���� �� � �������� ��������. ����� ����� ����� ���� �������, ��� ��� ����� ���������\n"+
				"�� ������ �� ������ ������ ��� ����� ������ ����� � ��������� ��� ����� �������, ����������� � ����� ������� �� ������ ����. � ������, ���� �� �����, ����� �� ����� ������ �����, ������� ��� � �� �������� ����� ��������.";
			link.l1 = "��, ������ ��� ��� ��������� ���������...";
			link.l1.go = "PoorHeadMan_7";
		break;
		case "PoorHeadMan_7":
			dialog.text = "��������, �� ��� ���, ��� � ���� � ���� ������������. ������ ������������� �����, ����� �� ������� � �����������, � �� ����. ��� ��� ���� �� ������ ���-�� ������ �� ���� ����, ��, ��� �������, ������ ����� � ���������� �����������.";
			link.l1 = "� ��� � ����"+ GetSexPhrase("��","��") +" ��� ������ �� ������ ������?";
			link.l1.go = "PoorHeadMan_8";
		break;
		case "PoorHeadMan_8":
			dialog.text = "������, "+ GetSexPhrase("���� ���","������") +", ������� ���������. ���, ��� � ���� ��� ���������, ������������� ��������. ��� �������, ��� �� ������������ ����� ������ ����� ���-�� ������� ����� �������, ������ ������� ��������� ���� �� �� �� ����.";
			link.l1 = "��, � ���� ��� �����. ���-�� ����� ���������, �������� ������ ������� � ����� ��������.";
			link.l1.go = "PoorHeadMan_9";
		break;
		case "PoorHeadMan_9":
			dialog.text = "��, � ������ ���, ��� �����. ������� �� ��, ��� "+ GetSexPhrase("��������","���������") +". ���� ������� ���-������ ������� �������� - ����� ��������� �� ���, ����� ������... � ������� �� ��, ��� �� "+ GetSexPhrase("��������","���������") +" ��� �����.";
			link.l1 = "�� �� �� ���. ���� ������� �� ����������.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toVillemstadResidence";
			AddQuestRecord("ISS_PoorsMurder", "4");
			//��������� ����������, ����� �������� �������, ��� ������ ������
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1 = "locator";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.location = "Villemstad_TownhallRoom";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.locator_group = "box";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.locator = "private2";
			pchar.quest.LSCC_enterStuvesantBox.function = "LSCC_enterStuvesantBox";
		break;
		//����� � �������� ����� ���������� ������
		case "FoundLetter":
			dialog.text = "��, �����, ���������, ��� ��� � ����...";
			link.l1 = "��� ������, ������� � ��������"+ GetSexPhrase("","�") +" � ���������� ����. ��� ��������� ����� ��� � ����������� ����-������� ���������. �� ���� ���� �������, ��� ������� ����������� ����� ������ ������ �������� ��������.";
			link.l1.go = "FoundLetter_1";
		break;
		case "FoundLetter_1":
			dialog.text = "���, ����...";
			link.l1 = "��� �����-�� ������ �����������. � �������� �������. � ��� ��� ������-�� �� �������� ���������. ��������-�� ���, ��������, � ��� ��� ����.";
			link.l1.go = "FoundLetter_2";
			TakeItemFromCharacter(pchar, "letter_LSCC");
		break;
		case "FoundLetter_2":
			dialog.text = "��, ���� �� ����, ��� �������... �������, ��� ����������� ������ - ��� ���������� ������ ��������������, ����� ���������� ����� �����.";
			link.l1 = "����?";
			link.l1.go = "FoundLetter_3";
		break;
		case "FoundLetter_3":
			dialog.text = "��, �������, ��������� ���, ���� ������������ - �������� ������, ���������� �����. � ���� ��� �� ��������, �� �����, �� �����, �� ������� ������ �� ���-�� ������� � �������. ����������� ����� ����� � ������������� ��� ����������� ������� ��������������, �������� ��� ���� ������� �� �����.";
			link.l1 = "�������� ��������� �� ���� �������. ���, ��� ������ � � ��� ������� � ���.";
			link.l1.go = "FoundLetter_4";
		break;
		case "FoundLetter_4":
			dialog.text = "�������, ��� ���-�� � ������ ���� ������, �� �� ���������� �������������. ��� ���, �� ���� ������� ����� ����� � ��������������, ����� ��� ���������������� �������� ��������. ���-�� � � ��� ���� ����, �� ����� ��� ��������������...";
			link.l1 = "��, � ���� � ������ �������, ��� ���� ������ ����������! ��� �����: '����������, ��� ����� �� ������� ����� ��� ����� �������� �����...'";
			link.l1.go = "FoundLetter_5";
		break;
		case "FoundLetter_5":
			dialog.text = "��, �� ����...";
			link.l1 = "� � ���� ������ �����-�� �����? � ���� ��� ��������?";
			link.l1.go = "FoundLetter_6";
		break;
		case "FoundLetter_6":
			dialog.text = "��� � ������ ���� � ��������. �� ������� �� � ���� ��� - ������� ��������� ���������������. ��� ��� ���� �������� - �� ���� � �������, � �� ��� ���� ����� ��� ����... � �����, �� ���������, ��� ��� �� ���� ������� ��������� �������, ��� � �������� ������.";
			link.l1 = "��, � ����������� ����-������� �������� ��������, ��� �� ����� �� � ������... � ��� ������ ���� �����, ��������?";
			link.l1.go = "FoundLetter_7";
		break;
		case "FoundLetter_7":
			dialog.text = "������. �� ��� ��������� �� ������. ����� ��� �����.";
			link.l1 = "��, ��������, �������, ��� � ����������� � ���� �������� ��������. �� ������ ��� ��������, ����� ��...";
			link.l1.go = "FoundLetter_8";
		break;
		case "FoundLetter_8":
			dialog.text = "��-��, ������ ���. ����� ����, ��� �� ������� �� ����� ����.";
			link.l1 = "���� �� �����, ��� ����� ���� ����� ���� �� �������...";
			link.l1.go = "FoundLetter_9";
		break;
		case "FoundLetter_9":
			dialog.text = "�� ��� ��, ����� ���� � ���� ����! ������� �� ������, "+ GetSexPhrase("�������","" + pchar.name + "") +".";
			link.l1 = "���� ������, ��������.";
			link.l1.go = "exit";
		                   npchar.quest.CanFoundStuvesantKey = "true";
			pchar.questTemp.LSCC = "toTalkStuvesant";
			pchar.questTemp.LSCC.poorName = GetFullName(npchar));
			AddQuestRecord("ISS_PoorsMurder", "7");
			AddQuestUserData("ISS_PoorsMurder", "sName", pchar.questTemp.LSCC.poorName);

		break;
		//����� � �������� ����� ������ ������� ������
		case "GoLSCC":
			dialog.text = NPCStringReactionRepeat("�������! ��, ��������, � ��� ��� ����?", 
				"�� ��� �������� �� ��� ����.", 
				"��, ���������� ���...",
                "��������, ������ ����������� - ��� ��� ������.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, �� "+ GetSexPhrase("�������� ����","��������� �����") +" � �������������, ������� "+ GetSexPhrase("��������","���������") +" � ����� ������ ������ �������. ��� ���� ������������� � ������ ���� � ��� �������.", 
				"��, �����.",
                "�����!", 
				"��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("GoLSCC_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "GoLSCC_1":
			dialog.text = "������, ����������!";
			link.l1 = "� ���� �� ���� ����� ��������. �� �����, ��� ������ ������, � ������� �� ��� ����� ����������� - �� �������. ��� ������, � � ������� ����������� ����!";
			link.l1.go = "GoLSCC_2";
		break;
		case "GoLSCC_2":
			dialog.text = "�������� �� ����!..";
			link.l1 = "���� � ����� ������ ������� - ����� ��� �����.";
			link.l1.go = "GoLSCC_3";
		break;
		case "GoLSCC_3":
			dialog.text = "�-�, ����! ����...";
			link.l1 = "� ���� ������� � �� �����"+ GetSexPhrase("","�") +" ������ ������, �� ��� ����� �������, ��� ��� ��� �� �������. ������������� ����.";
			link.l1.go = "GoLSCC_4";
		break;
		case "GoLSCC_4":
			dialog.text = "������, �� ����������� ����� ���� ������? ����� � ����� ���� ���� ������.";
			link.l1 = "��� �� ����?";
			link.l1.go = "GoLSCC_5";
		break;
		case "GoLSCC_5":
			dialog.text = "����� � �� ����. ����� ����� ��� ��� �� �������� �� ����, ��� ���������� �� �������. �������, ��� ���� ����������, � ��� ��� �������� - ������� �� ����.";
			link.l1 = "���������� ����! ���������...";
			link.l1.go = "GoLSCC_6";
		break;
		case "GoLSCC_6":
			dialog.text = "�� ��� ������ � ������ ������ ���� ���� ����, ��� ������� ����� ������. ��� ����� �������, ��� ���� ���� ������ ������ �������� ������ ���������� �������. ��� ��� �������� - ������� �� ����, �� � ������������� �������� �������.";
	link.l1 = "�������, �������. � ������.";
	link.l1.go = "exit";
                   npchar.quest.readyGoLSCC = "true";
	ChangeItemName("keyQuestLSCC", "itmname_keyQuestLSCC_Tizer");
	ChangeItemDescribe("keyQuestLSCC", "itmdescr_keyQuestLSCC_Tizer");
	sld = ItemsFromID("keyQuestLSCC");
	DeleteAttribute(sld, "shown");
	GiveItem2Character(pchar, "keyQuestLSCC");
                   CloseQuestHeader("ISS_PoorsMurder");

	sld = CharacterFromID("Abuyin");//��� ���� ������ 1 ������������
	sld.dialog.currentnode = "WEISSAGUNG_2";
		
		break;
	}
}