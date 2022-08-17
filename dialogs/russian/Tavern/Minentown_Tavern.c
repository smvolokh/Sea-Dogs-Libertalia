#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	bool bLock = (CheckAttribute(pchar, "GenQuest.BrothelLock")) && (GetCharacterIndex("Mary") != -1);
	bool bLock1 = (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) && (IsOfficer(characterFromId("Helena")));

	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,
					LinkRandPhrase("� ������ ������� �������, ���� ����� ����! �� ����� ����� � �� �� ���� ����� �������������.", "��� ��������� ������ ����� �� ������ � ������� ����. � �� ����� � ������������� � ����� �� ����!", "����, "+ GetSexPhrase("��������","�������") +", ���� ������� �� ������� �� ���� ������..."),
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����!","") +"", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ����� ����! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� �������, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."),
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "���, " + GetWorkTypeOfMan(npchar, "") + ", � ��� ���� �� - ������� ������! ��� ��� � ���� �����, ��������: ���� ���� � ������ ����..."));
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = TimeGreeting() + "! ����� ����������, " + GetAddress_Form(NPChar) + " � ������� ������� ���-�����. ���, ������� �... ������� - ��� �� ��������� �����! ���� ����� "+GetFullName(npchar)+" � � ������ � ����� �������.";
				Link.l1 = "���������... � " + GetFullName(pchar) + ". ��� � ���� �������������, "+npchar.name+".";
				Link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� �� ��� ������ ��������, ������� "+GetFullName(pchar)+"! ��� ��� ������, �������! ����, �������?";
				if (makeint(pchar.money) >= 5)
				{
					link.l1 = "����� ��� ����, "+npchar.name+".";
					link.l1.go = "drink";
				}
				link.l2 = "� �� ����� ���������. � ���� ���� ��������� �������?";
				link.l2.go = "room";
				link.l3 = LinkRandPhrase("�������� ��� ��������� �������?","��� ���������� � ���� �����?","��� ����� ����� �� ����?");
				link.l3.go = "rumours_tavern";
				link.l4 = "���, ������ �� ����, "+npchar.name+". � ������ ����� ������������� � �����.";
				link.l4.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "�, � �-�� ��� ���! ����� ���� �������� � ����� �������. ������� � ����� ��� ����, ���������...";
			link.l1 = "� ����� �������, � ����� �� ������� ������ ������ �� ���� ���������.";
			link.l1.go = "info";
			if (makeint(pchar.money) >= 5)
			{
				link.l2 = "����� ��� ����, "+npchar.name+".";
				link.l2.go = "drink";
			}
			link.l3 = "� �� ����� ���������. � ���� ���� ��������� �������?";
			link.l3.go = "room";
		break;
		
		case "info":
			dialog.text = "� � ��� ��� ��������-��? � ��� ��� ��� � ���� ���� � �� ��: �����, ������� ������ � ����. ��������� ������ ������� �� ������ � ��������. ����� � ��� ������ ����� ����� ����-������ ��������� ����������� � ������ ������������ � �����������, ������� ���� ���������� ������� ����\n������� ���� � �����������, �������� ��������, ����� ���: ������� ����� �� ������� ������ ��� ������ ����������� �������. ��� ��������� - �������� �������, ������� �� ������ �������� � ����������� �����������, �� � ������-�� �������\n������ �� ������������ - ���, ������ �����-��, �� ��� ���� ����������, ��� �������� �������� ��� ��������� ����������. ��� ��� ����������� ��������� � ��� �������\n����� ��������� � ������� ������, � ���. ���� ������ - ������ �������� � ��, �� ������ �� ���������� ���������� ������, ����� ��������� � ������������, �, ���� ��� �����, ���������� ���-������ �������\n������ ����� ������ ����� � ������ - ��� ��� �������. ������ ����� ����� ��������� ����� � ����� �� ����� �������� ���!";
			link.l1 = "��������� �� ����������!";			
			link.l1.go = "exit";
		break;
		
		case "drink":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 3)
			{
				dialog.text = "�������, ��-�����, ��� ������� ������������. �� ��� ��� ���� ������ ���������. � ��� ����� � ���� ������ - �� ������� ���� ��� ���������.";
				link.l1 = "��... �������, �� ���� - � ��� ���������� �����. ������� �� ������!";			
				link.l1.go = "exit";
			}
			else
			{
				AddMoneyToCharacter(pchar, -5);
				if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
				{
					if (CheckAttribute(pchar, "questTemp.Rum"))
					{
						pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
					}
					else pchar.questTemp.Rum = 1;
				}
				else 
				{
					if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
				}				
				WaitDate("",0,0,0, 0, 30);
				
				dialog.text = "����������, �������. ����� �� ���� ���� - ����� ����� ������� ������� ��������� ����!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("��, �� ���� �������� � ����������� ������ ���������, �������!","��, �� ���, ��� � ����!","��, �� ������������ �������������� ������ ������!"), LinkRandPhrase("��, �� ����� ������, �� ����� �����, ���� ��� �� ������ ������� � ������!","��, �� ��, ����� ����� ������ ��� �������� �� ���� �����!","��, �� �������, �����, ������� �... ������!"));		
				link.l1.go = "drink_1";
			}
		break;
		
		case "drink_1":
			DialogExit();
			LAi_Fade("", "");
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;
		
		case "room":
			if (CheckAttribute(pchar, "GenQuest.MinentownSex"))
			{
				dialog.text = "������, �� ���� ��� �������� � �������, � �������. �������� ������, ��� ��� ��� ���������.";
				link.l1 = "������.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "����. �� ����� ���� �� ���������� ������������?";
			if(!isDay())
			{
				link.l1 = "�� ����.";
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = "�� ����.";
				link.l1.go = "room_night";
				link.l2 = "�� ���������� ����.";
				link.l2.go = "room_day_next";
			}
		break;

		case "room_day":
			dialog.text = "��� ��������� ��� � ������ ����. �� ������� �� ������� ������ � �������? ����� ������ ���� �� ��������.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "���, ������� ��� �� ����. ���, ������ ������ �� �������.";
				link.l1.go = "room_day_wait";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "������. ����� � �������, � �������. ��� ���� ������.";
					link.l2.go = "room_girl";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "���, �� ���� ������� ��� �� �� �������.";
			link.l3.go = "exit";
		break;

		case "room_day_next":
			dialog.text = "��� ��������� ��� � ������ ����. �� ������� �� ������� ������ � �������? ����� ������ ���� �� ��������.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "���, ������� ��� �� ����. ���, ������ ������ �� �������.";
				link.l1.go = "room_day_wait_next";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "������. ����� � �������, � �������. ��� ���� ������.";
					link.l2.go = "room_girl";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "���, �� ���� ������� ��� �� �� �������.";
			link.l3.go = "exit";
		break;

		case "room_night":
			dialog.text = "��� ��������� ��� � ������ ����. �� ������� �� ������� ������ � �������? ����� ������ ���� �� ��������.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "���, ������� ��� �� ����. ���, ������ ������ �� �������.";
				link.l1.go = "room_night_wait";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "������. ����� � �������, � �������. ��� ���� ������.";
					link.l2.go = "room_girl";
					sTotalTemp = "wait_night";
				}
			}
			link.l3 = "���, �� ���� ������� ��� �� �� �������.";
			link.l3.go = "exit";
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_day");
		break;

		case "room_day_wait_next":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -20);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_day");
		break;
		
		case "room_girl":
			AddMoneyToCharacter(pchar, -1010);
			dialog.text = "������������ �� �������� ������, ������. ������� ����� ����� ���. ��������� ������!";
			link.l1 = "�������, ��������...";
			link.l1.go = "room_girl_1";
		break;
		
		case "room_girl_1":
			DialogExit();
			pchar.GenQuest.CannotWait = true;
			pchar.GenQuest.MinentownSex = "true";
			LocatorReloadEnterDisable("Minentown_tavern", "reload1_back", true); //������� �������
			LocatorReloadEnterDisable("Minentown_tavern", "reload2_back", false); //������� �������
			bDisableFastReload = true;//������� �������
			sld = GetCharacter(NPC_GenerateCharacter("MineFuckGirl" , "squaw_"+(rand(2)+1), "woman", "woman_B", 1, SPAIN, 1, true, "quest"));
			sld.dialog.FileName = "Tavern\Minentown_Tavern.c";
			sld.dialog.currentnode = "MineFuckGirl";
			//sld.greeting = "";
			sld.name = GetIndianName(WOMAN);
			sld.lastname = "";
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld, "Minentown_tavern_upstairs", "goto", "goto1");
		break;
		
		case "MineFuckGirl":
			dialog.text = "���� ��� ������, ����� ������. � �� �������� �� "+npchar.name+" ���, "+npchar.name+" ����� ������ ��� �� ���� ����� ����� �� �������. ��, ������ ����� �����������... �������, �� �������� �������.";
			link.l1 = "�� ��� ��, �������, ����� ���������...";
			link.l1.go = "MineFuckGirl_sex";
		break;
		
		case "MineFuckGirl_sex":
			DialogExit();
			DoQuestCheckDelay("PlaySex_1", 0.1);
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
	}
}
