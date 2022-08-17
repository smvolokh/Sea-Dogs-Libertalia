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
		PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
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
			dialog.text = "���� ������� ���. '����������' � ������ � ���� ��� ����� ������, �� �� ��������� �� ������ ��� ��������, ������ �� ������� ������ �����������. ��, ��� ��� ��� �������. � �������� ������ ������ ������ ������ ������, ������� �� ����� ����� � ���� ����� �� ������\n��� ���� ������� �����-�� ���������-������ �� ���������. ���� � ���, ��� �� '����������' �������������, �� ������ ��������, ����� ������. ��� � ����, ���� '�����' �������� ����� ��� '����������'\n�� ���� ��� �������� ��� �������� �������, ��� ��� ���� '�����' �� �������� ����� ��� ��� - '����������' ���������� � ���� � ���...";
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
	}
}