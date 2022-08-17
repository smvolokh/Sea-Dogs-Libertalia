#include "DIALOGS\russian\Rumours\Common_rumours.c"
#include "interface\ship.c"
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

	int iTest, iTemp;
	string sTemp;
    iTest = FindColony(NPChar.City); // ����� 
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	bool ok;

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
				dialog.text = TimeGreeting() + "! ����� ����������, " + GetAddress_Form(NPChar) + " � ������� ����� ��������� ��������� ����-���. ���, ������� �... ������� - ��� �� ��������� �����, ��� ����� ��������! ���� ����� "+GetFullName(npchar)+" � � ������ � ����� �������.";
				Link.l1 = "���������... � " + GetFullName(pchar) + ". ��� � ���� �������������, "+npchar.name+".";
				Link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� �� ��� ������ ��������, ������� "+GetFullName(pchar)+"! ���� ��� ������! ������ �� ������� ���?";
				link.l1 = "� ��� ������?";
				link.l1.go = "THEKLA_ARBEIT";

				link.l2 = "� �� ����� ���������. � ���� ���� ��������� �������?";
				link.l2.go = "room";
				link.l3 = LinkRandPhrase("�������� ��� ��������� �������?","��� ���������� � ���� �����?","��� ����� ����� �� ����?");
				link.l3.go = "rumours_tavern";
			                     Link.l4 = "��� ����� �������, " + NPChar.name + ".";
			                     Link.l4.go = "crew hire";
			}
			if(CheckAttribute(pchar, "questTemp.BlueBird") && pchar.questTemp.BlueBird == "SantLous_toTavern" && !CheckAttribute(npchar, "quest.SantLous_toTavern"))
			{
				link.l5 = "Ҹ���, �� ������, ����� � �������� �������� �������� � ���� �������� ����������?";
				link.l5.go = "BlueBird_ret";
			}
				link.l6 = "���, ������ �� ����, "+npchar.name+". � ������ ����� ������������� � �����.";
				link.l6.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_15_00.wav");
		dialog.text = "";
		link.l1 = "��� � ���� ����� ������ ������?";
		link.l1.go = "meeting_1";
		break;

		case "meeting_1":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_17_01.wav");
		dialog.text = "�� ������������, ���� � ����� ��� �� - ��� ����������� - ��� �� ������� ������ ������?";
		link.l1 = "";
		link.l1.go = "meeting_2";
		break;

		case "meeting_2":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_17_02.wav");
			dialog.text = "������� �� ��������� �������������� � ����� ����� �� ��� ��� - �� �����, �� �� ���� �� ������?";
			link.l1 = "� ����� �������, � ����� �� ������� ������ ������ �� ���� ���������.";
			link.l1.go = "info";
		break;
		
		case "info":
			dialog.text = "� � ��� ��� ��������-��? � ��� ��� ��� � ���� ���� � �� ��: �����, ������� ������ � ����. ��������� ������ ������� �� ������ ������� ��������� ��������� �� ����� ����� ����� ��� ���� �����������. ����� � ��� ������ ����� ����� ����-������ ��������� ����������� � ������ ������������ � �����������, ������� ���� ���������� ������� ����\n������� ���� � �����������, �������� ��������, ����� ���: ������� ����� �� ������� ������ ��� ������ ����������� �������\n������ ����� ������ ����� � ������� - ��� ��� �������. ������ ����� ����� ��������� ����� � ����� �� ����� �������� ���!";
			link.l1 = "� ��� ��� ���� ����������!";			
			link.l1.go = "info_1";
		break;

		case "info_1":
			dialog.text = "������� ��� ����, ����� �� �������� ��������� �� ����� �������� ��!";
			link.l1 = "�������� ��!";			
			link.l1.go = "info_2";
		break;

		case "info_2":
			dialog.text = "��, ��� � ��� ������. � ��, ��� ������ �������, ��� ������ ���!";
			link.l1 = "�� ����� ����, � ��� �� ������!";			
			link.l1.go = "info_3";
		break;

		case "info_3":
			dialog.text = "������ ��� �����! �� �� �������...";
			link.l1 = "����. � �� �� �� ����� ��� ���� ������!";			
			link.l1.go = "info_4";
		break;

		case "info_4":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_15_00.wav");
			dialog.text = "";
			link.l1 = "� �������!";
			link.l1.go = "info_5";
		break;

		case "info_5":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_01.wav");
			dialog.text = "� �� ������ ������, � ������ ������ ��� ��� ��������!";
			link.l1 = "...";
			link.l1.go = "info_6";
		break;

		case "info_6":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_02.wav");
			dialog.text = "� ���� ����� �������� - �������.";
			link.l1 = "...";
			link.l1.go = "info_7";
		break;

		case "info_7":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_03.wav");
			dialog.text = "��� ���� ���.";
			link.l1 = "...";
			link.l1.go = "info_8_1";
			if (AddSPECIALValue(pchar, SPECIAL_C, 0) == SPECIAL_MAX)
			{
			    AddSPECIALValue(pchar, SPECIAL_C, 1);
			}
		break;

		case "info_8_1":
			PlaySound("interface\important_item.wav");
			link.l1.go = "info_8_2";
		break;

		case "info_8_2":
			PlaySound("Ambient\Tavern\glotok_001.wav");
			dialog.text = "...";
			link.l1 = "��� ������!";
			link.l1.go = "exit";
			AddDialogExitQuest("Gothic_PlusSkill_Charisma");
		break;

		case "info_8":
			dialog.text = "����� ��, ��� �� ������� �� ���� �����?";
			link.l1 = "...";
			link.l1.go = "info_8_0";
		break;

		case "info_8_0":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_00.wav");
			dialog.text = "...";
			link.l1 = "�� ��� �� ���� ��� ����� ��������?";
			link.l1.go = "info_9";
		break;

		case "info_9":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_01.wav");
			dialog.text = "��� �����������!";
			link.l1 = "...";
			link.l1.go = "info_10";
		break;

		case "info_10":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_02.wav");
			dialog.text = "...";
			link.l1 = "�� �������� ���� ��������� �����?";
			link.l1.go = "info_11";
		break;

		case "info_11":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_03.wav");
			dialog.text = "���...";
			link.l1 = "...";
			link.l1.go = "info_12";
		break;

		case "info_12":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_04.wav");
			dialog.text = "...";
			link.l1 = "� ���� � �������� ������ - �!";
			link.l1.go = "info_13";
		break;

		case "info_13":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_05.wav");
			dialog.text = "��������!";
			link.l1 = "...";
			link.l1.go = "info_14";
		break;

		case "info_14":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_06.wav");
			dialog.text = "���� ���� ��� ����������� �������, ���� �������� ������� ��� ���, ��� �� �������� �.";
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "THEKLA_ARBEIT":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_ARBEIT_17_01.wav");
			dialog.text = "�� ������ �������� ����� �� �����!";
			link.l1 = "�� �� ���� ��������....";
			link.l1.go = "THEKLA_ARBEIT_1";
		break;

		case "THEKLA_ARBEIT_1":
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "exit";

			// ������� ��� �������
			if(CheckAttribute(pchar, "questTemp.GothicThekla") && pchar.questTemp.GothicThekla == "UneasySagitta" && !CheckAttribute(npchar, "quest.UneasySagitta"))
			{
				link.l1 = "� ���� ���� ������ ��� ����?";
				link.l1.go = "UneasySagitta";
			}
			if(CheckAttribute(pchar, "questTemp.GothicThekla") && pchar.questTemp.GothicThekla == "SoupThekla" && !CheckAttribute(npchar, "quest.SoupThekla"))
			{
				link.l1 = "� �������� ������� ��� ������� � ������������ - ���� ����!";
				link.l1.go = "SoupThekla";
			}
			// ������ � ������ ����
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "SagittaAnn" && !CheckAttribute(npchar, "quest.SagittaAnn"))
			{
				link.l1 = "� ���� ���� ������ ��� ����?";
				link.l1.go = "SagittaAnn";
			}

		break;

		case "THEKLA_PERM":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 3)
			{
				dialog.text = "�������, ��-�����, ��� ������� ������������. �� ��� ��� ���� ������ ���������. � ��� ����� � ���� ������ - �� ������� ���� ��� ���������.";
				link.l1 = "��... �������, �� ����� - � ��� ���������� �����. ������� �� ������!";			
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
				
				dialog.text = "����������, �������. ����� �� ���� ���� - ������ ������� �� �������!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("��, �� ���� �������� � ����������� ������ ���������, �������!","��, �� ���, ��� � ����!","��, �� ������������ �������������� ������ ������!"), LinkRandPhrase("��, �� ����� ������, �� ����� �����, ���� ������ ��� �� ������� � ������!","��, �� ��, ����� ����� ������ ��� �������� �� ���� �����!","��, �� �������, �����, ������� �... ������!"));	
				link.l1.go = "THEKLA_PERM_1";
			}
		break;
		
		case "THEKLA_PERM_1":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
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
			if (CheckAttribute(pchar, "GenQuest.SantLousSex"))
			{
				dialog.text = "�����, �� ���� ��� �������� � �������, � �������. �������� ������, ��� ��� ��� ���������.";
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
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
			dialog.text = "��� ��������� ��� � ������ ����. �� ������� �� ������� ������ � �������? ����� ������ ���� �� ��������.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "���, ������� ��� �� ����. ���, ������ ������ �� �������.";
				link.l1.go = "room_day_wait_0";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "������. ����� � �������, � �������. ��� ���� ������.";
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "������, � ���� ��� �����.";
			link.l3.go = "room_exit_1";
		break;

		case "room_day_next":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
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
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "� �� ��� ���� �� �����.";
			link.l3.go = "room_exit_2";
		break;

		case "room_night":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_01.wav");
			dialog.text = "��� ��������� ��� � ������ ����. �� ������� �� ������� ������ � �������? ����� ������ ���� �� ��������.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "���, ������� ��� �� ����. ���, ������ ������ �� �������.";
				link.l1.go = "room_night_wait_0";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "������. ����� � �������, � �������. ��� ���� ������.";
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_night";
				}
			}
			link.l3 = "� �� ���� ��������� ���� ����� �������.";
			link.l3.go = "room_exit_3";
		break;

		case "room_exit_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
                                    Dialog.text = "";
		link.l1 = "������, � ���� ��� �����!"; 
		link.l1.go = "exit";  
		break;

		case "room_exit_2":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_16.wav");
                                    Dialog.text = "";
		link.l1 = "� �� ��� ���� �� �����!"; 
		link.l1.go = "exit";  
		break;

		case "room_exit_3":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_19.wav");
                                    Dialog.text = "";
		link.l1 = "� �� ���� ��������� ���� ����� �������!"; 
		link.l1.go = "exit";  
		break;

		case "room_night_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_15.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "��� ���� ������!"; 
		link.l1.go = "room_night_wait";  
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_11.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "������ - ��� ������!";
		link.l1.go = "room_day_wait";
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

		case "room_girl_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "��� ��� ������!";
		link.l1.go = "room_girl";
		break;
		
		case "room_girl":
			AddMoneyToCharacter(pchar, -1010);
			dialog.text = "������������ �� �������� ������, �����. ������� ����� ����� ���. ��������� ������!";
			link.l1 = "���� ������, ��� ������ - ��...";
			link.l1.go = "room_girl_1";
		break;
		
		case "room_girl_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
			DialogExit();
			pchar.GenQuest.CannotWait = true;
			pchar.GenQuest.SantLousSex = "true";
			LocatorReloadEnterDisable("SantLous_tavern", "reload1_back", true); //������� �������
			LocatorReloadEnterDisable("SantLous_tavern", "reload2_back", false); //������� �������
			bDisableFastReload = true;//������� �������
			sld = GetCharacter(NPC_GenerateCharacter("MineFuckGirl" , "Womens_"+(rand(7)+1), "woman", "towngirl", 1, FRANCE, 1, true, "quest"));));
			sld.dialog.FileName = "Tavern\SantLous_Tavern.c";
			sld.dialog.currentnode = "MineFuckGirl";
			//sld.greeting = "";
			sld.sex = "woman";
			sld.lastname = "";
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld, "SantLous_tavern_upstairs", "goto", "goto1");
		break;
		
		case "MineFuckGirl":
                                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_15.wav");
			dialog.text = "";
			link.l1 = "��� �� ������������� �� �����?";
			link.l1.go = "MineFuckGirl_1";		
		break;

		case "MineFuckGirl_1":
                                   PlaySound("VOICE\Russian\gotica\LUCIA\DIA_ADDON_LUCIA_PALADINE_KILL_16_02.wav");
			dialog.text = "����� ��������� �������� � �����  ��������� �����!";
			link.l1 = "";
			link.l1.go = "MineFuckGirl_2";		
		break;

		case "MineFuckGirl_2":
                                 PlaySound("VOICE\Russian\gotica\LUCIA\DIA_ADDON_LUCIA_PALADINE_KILL_16_03.wav");
			dialog.text = "����� ������ � ����� ������������ ������ �������� ����� ������ ��� ������!";
			link.l1 = "�� ��� ��, �������, ����� ��������� �� ��� �� ��������...";
			link.l1.go = "MineFuckGirl_3";		
		break;

		case "MineFuckGirl_3":
                                   PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "������. �� ��� ��, �������, ����� ��������� �� ��� �� ��������...";
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


		case "crew hire":
			ok = (rColony.from_sea == "Shore31") || (Pchar.location.from_sea == rColony.from_sea);

						
            if (makeint(environment.time) > 22.0 || makeint(environment.time) < 7.0)
			{
				Dialog.text = "������ � ���� � ������� ����� �����, �������� ����� ���������, �� ������ ������� ������, � ��� ������ ���������� ������ �����. ����� ����, �� ������ ����� �������, � ��������� ��?";
				link.l1 = "������. � ���� ���� ��������� �������?";
				link.l1.go = "room";
				link.l2 = "���� �� ���������� ������� �� ������ ������. �� �������.";
				link.l2.go = "exit";
			}
			else
			{
                if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
                {
                    Dialog.text = "� �� �������, � ���� ���-�� ������, ����� �� � ���� �� ������? ����� �������, ��� ������ �� ����.";
					link.l1 = "�������.";
					link.l1.go = "exit";
                }
                else
                {
					if (CheckAttribute(NPChar, "CrewHired.PGGId") && GetNpcQuestPastDayParam(NPChar, "CrewHired") < 3 && GetCrewQuantity(rColony) == 0)
					{
						Dialog.text = "��������, �� ������ ��� ������. ��� ���� � �������� ����� " + GetFullName(CharacterFromID(NPChar.CrewHired.PGGId)) + ".";
						link.l1 = "��, ����!";
						link.l1.go = "exit_crew";
					}
					else
					{						
						if(bPartitionSet)
						{		
							if(GetPartitionAmount("CrewPayment") > 0)
							{
								if(IsEquipCharacterByArtefact(pchar, "totem_07"))
								{
									DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
									NextDiag.CurrentNode =  NextDiag.TempNode;
									DialogExit();
									LaunchHireCrew();							
								}
								else
								{
									dialog.text = "�������, ������������, ��� �� ���������. � ���� ��� �������� ����� � ���� �������.";
									link.l1 = "�������...";
									link.l1.go = "exit";
								}
							}
							else
							{
								DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
								NextDiag.CurrentNode =  NextDiag.TempNode;
								DialogExit();
								LaunchHireCrew();	
							}
						}	
						else
						{
							DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
							NextDiag.CurrentNode =  NextDiag.TempNode;
							DialogExit();
							LaunchHireCrew();							
						}						
					}
				}
			}
		break;

 		case "BlueBird_ret":
        	                  dialog.text = "��, ����� ���� ��������� ����� �������, �������� ����� � ���� ''������� ���'', � ������� �� ��� ��� �������.";
    		link.l1 = "������� �������, ��� ����.";
    		link.l1.go = "BlueBird_ret_1";
		break;

		case "BlueBird_ret_1":
		DialogExit();
		npchar.quest.SantLous_toTavern = "true";
	     DoQuestFunctionDelay("BlueBird_loginFleut", 3.0);
		AddQuestRecord("Xebeca_BlueBird", "10");
		break;

		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;

		// ������� ��� �������
		case "UneasySagitta":
                                       PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_1.wav");
		    dialog.text = "";
		    link.l1 = "� ���� ���� ������ ��� ����?";
                                          link.l1.go = "UneasySagitta_1";
		break;

		case "UneasySagitta_1":
		    dialog.text = "����� �����, ��� ������ ������� " + GetFullName(pchar) + " �������"+ GetSexPhrase("","�") +" ������ ��������� � ������������, � �����"+ GetSexPhrase("","�") +" ��������� ���� ��������� ������ �������� �� - ����� ����...\n��� ����� ������ ������� �������� ��� ��, � �� ��� ��� �������, ��� ���������� �������� ���������� ���������� ��� ������� ������� ������ ������.";
		    link.l1 = "������! � ��� �� �������, � ��� � ������?";
                                          link.l1.go = "UneasySagitta_2";
		break;
		
		case "UneasySagitta_2":
		    dialog.text = "������� - ��������, �� ������ ������, ��� ��� ������, ���� ��� � ����� �� ����� ���������.";
            link.l1 = "������!!!, ���-�� � ���-�� �� ����� �������� �� ����� ������.";
            link.l2 = "��... ������, � �������� ���� ���������� ���������� ��� �������, �� ������ ���� ����.";
            link.l1.go = "Exit1";
            link.l2.go = "UneasySagitta_3";
		break;
		
		case "Exit1":
                                                        PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
			dialog.text = "��, ��� ������. ��� ���� ����������...";
			link.l1 = "...";
			link.l1.go = "exit";			
			npchar.quest.UneasySagitta = "true";
		break;
		
		case "UneasySagitta_3":
		    dialog.text = "����� ������, ���� �� ���� - �� ���� ����.";
                                           link.l1 = "����� ���������� ����������.";
                                           link.l1.go = "Exit2";
		     TakeNItems(pchar, "tailor_tool", 1);
		      Log_Info("�� �������� ���������� ����������");
		      PlaySound("interface\important_item.wav");	
	                  break;

		case "Exit2":
		Nextdiag.CurrentNode = Nextdiag.TempNode;
		DialogExit();
                                       AddDialogExitQuestFunction("GothicSagitta_Start");
		AddQuestRecord("Delivery", "1");
		npchar.quest.UneasySagitta = "true";
		break;

		case "SoupThekla":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_03.wav");
		dialog.text = "��� ���� ���.";
		link.l1 = "";
		link.l1.go = "SoupThekla_1";
		if (AddSPECIALValue(pchar, SPECIAL_I, 0) == SPECIAL_MAX)
		{
		AddSPECIALValue(pchar, SPECIAL_I, 1);
		}
		break;

		case "SoupThekla_1":
		PlaySound("interface\important_item.wav");
		link.l1.go = "SoupThekla_2";
		break;

		case "SoupThekla_2":
		PlaySound("Ambient\Tavern\glotok_001.wav");
		dialog.text = "";
		link.l1 = "��� ������!";
		link.l1.go = "exit";
		npchar.quest.SoupThekla = "true";
		AddDialogExitQuest("Gothic_PlusSkill_Intellect");
		break;

		// ������� ��� ������� <--

		// ������ � ������ ����
		case "SagittaAnn":
                                       PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_1.wav");
		    dialog.text = "";
		    link.l1 = "� ���� ���� ������ ��� ����?";
                                          link.l1.go = "SagittaAnn_1";
		break;

		case "SagittaAnn_1":
		    dialog.text = "�������, �� ������ �� ���������� ���������� ������� - ������ ������-�� ����������� ����������� ��������. � �������, ��� �� ��� �����... �� �� ����� ������ ���, �� ������ ���������������� � �������, ��� ���������� � ���� �� ����? Ÿ ������ ��������� �� ���������, ���� �� �����" + GetSexPhrase("", "�");;
		    link.l1 = "������ � ������� � ���.";
                                          link.l1.go = "SagittaAnn_2";
		break;

		case "SagittaAnn_2":
		Nextdiag.CurrentNode = Nextdiag.TempNode;
		DialogExit();
                                    AddDialogExitQuestFunction("Gothic_SagittaAnn");		
		npchar.quest.SagittaAnn = "true";
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
