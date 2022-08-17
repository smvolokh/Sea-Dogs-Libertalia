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
				dialog.text = TimeGreeting() + "! ����� ����������, " + GetAddress_Form(NPChar) + "! ���� ����� "+GetFullName(npchar)+" � � ������ � ����� �������.";
				Link.l1 = "���������... � " + GetFullName(pchar) + ". ��� � ���� �������������, "+npchar.name+".";
				Link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� �� ��� ������ ��������, ������� "+GetFullName(pchar)+"! ��� ��� ������, �������! ����, ������� ����������� �������?";
				if (makeint(pchar.money) >= 5)
				{
				link.l1 = "��� ��� ����, "+npchar.name+".";
				link.l1.go = "drink_RUM";
				}
				if (makeint(pchar.money) >= 35)
				{
				link.l2 = "� ���� ���� ������ �� ������?";
				link.l2.go = "drink_STRONGER";
				}
				link.l3 = LinkRandPhrase("�������� ��� ��������� �������?","��� ���������� � ���� �����?","��� ����� ����� �� ����?");
				link.l3.go = "rumours_tavern";
			                     Link.l4 = "��� ����� �������, " + NPChar.name + ".";
			                     Link.l4.go = "crew hire";
				  link.l5 = "���, ������ �� ����, "+npchar.name+". � ������ ����� ������������� � �����.";
				link.l5.go = "exit";

		}

	if (CheckAttribute(npchar, "quest.SAMUEL_100"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 100)
		{
		link.l2 = "��� ��� ������.";
		link.l2.go = "drink_Grog_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_150"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 150)
		{
		link.l2 = "��� ��� ������.";
		link.l2.go = "drink_Rumm_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_250"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 250)
		{
		link.l2 = "��� ��� ������.";
		link.l2.go = "drink_LOUSHAMMER_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_500"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l2 = "��� ��� ������.";
		link.l2.go = "drink_SCHNELLERHERING_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_700"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 700)
		{
		link.l2 = "��� ��� ������.";
		link.l2.go = "drink_LOUSDOUBLEHAMMER_7";
		}	
                       }


			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_HELLO_14_00.wav");
			dialog.text = "�, �������!!!";
			link.l1 = "";
			link.l1.go = "meeting_1";
		break;

		case "meeting_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_HELLO_14_01.wav");
			dialog.text = "� ���, ���� �� ������ - ���� ��� ���� �� ������?";
			link.l1 = "� ����� �������, � ����� �� ������� ������ ������ �� ���� ���������.";
			link.l1.go = "info";
		break;
		
		case "info":
			dialog.text = "� � ��� ��� ��������-��? � ��� ��� ��� � ���� ���� � �� ��: �����, ������� ������ � ����. ��������� ������ ������� �� ��������� �����. ����� � ��� ������ ����� ����� ����-������ ��������� ����������� � ������ ������������ � �����������, ������� ���� ���������� ������� ����\n������� ���� � �����������, �������� ��������, ����� ���: ������� ����� �� ������� ������ ��� ������ ����������� �������!";
			link.l1 = "� ��� ��� ���� ����������!";			
			link.l1.go = "info_1";
		break;

		case "info_1":
			dialog.text = "�������� ���������� �������!";
			link.l1 = "���������� �������!";			
			link.l1.go = "info_2";
		break;

		case "info_2":
			dialog.text = "��, ��������� ������� � ����� - ������� �������. ��, �� ������� �������� �����!";
			link.l1 = "�����? ����� �� �� ��� �������?";			
			link.l1.go = "info_3";
		break;

		case "info_3":
			dialog.text = "����, ����, ����� �� ������� �� ���� ��������. � � ���� ������ ����� �����? �� ���� ��� ������� ���� �������� ���������?";
			link.l1 = "��, ��� �. � ���� ���� ����� - ������! �� ���������� ����������� �������������� ���������? ���� ��� - ������ ������?";			
			link.l1.go = "info_STRONGER_00";
		break;

		case "info_STRONGER_00":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_00.wav");
		dialog.text = "";
		link.l1 = "� ���� ���� - ������ �� ������?";
		link.l1.go = "drink_STRONGER_01";
		break;

		case "drink_STRONGER_01":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_01.wav");
		dialog.text = "� ���� ����������� ����! � � ��� ����� ������������������?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_02";
		break;

		case "drink_STRONGER_02":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_02.wav");
		dialog.text = "������� ������� ������ ���� ������, �������, � ������ ��������� ��� ������ �����!";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_03";
		break;

		case "drink_STRONGER_03":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_03.wav");
		dialog.text = "����� �� ����� �����������, �� � ������� ����� ������ � �� ������ ������?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_04";
		break;

		case "drink_STRONGER_04":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_04.wav");
	                   dialog.text = "��� ��� ����������� ������ - ���� ����������! � ������� ���� ������� - ������� �������.";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_05";
		break;

		case "drink_STRONGER_05":
		PlaySound("interface\important_item.wav");
		dialog.text = "";
		link.l1 = "����������?";
		link.l1.go = "drink_STRONGER_06";
		break;

		case "drink_STRONGER_06":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
		dialog.text = "";
		link.l1 = "���, ����!!!";
		link.l1.go = "drink_STRONGER_07";
		break;

		case "drink_STRONGER_07":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_05.wav");
	                   dialog.text = "";
		link.l1 = "����������!!!";
		link.l1.go = "drink_STRONGER_08";
		break;

		case "drink_STRONGER_08":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_06.wav");
	                   dialog.text = "��, �� - ��� �����!!!";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_09";
		break;

		case "drink_STRONGER_09":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_07.wav");
	                   dialog.text = "� ���� �� ����������� ������� ��������, ���� ���������� - ����������� �������� ���.";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_010";
		break;

		case "drink_STRONGER_010":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_08.wav");
	                   dialog.text = "������ ���?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_011";
		break;

		case "drink_STRONGER_011":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_09.wav");
	                   dialog.text = "��� ���� ��� �����������?";
		link.l1 = "";
		link.l1.go = "exit";
		break;




		case "drink_RUM":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\RUM_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ����!!!";
		link.l1.go = "drink_RUM_1";
		break;

		case "drink_RUM_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_01.wav");
		dialog.text = "�, ��� ��� ������ - �� �����, ��� ������ ������ - ��� ����.";
		link.l1 = "";
		link.l1.go = "drink_RUM_2";
		break;

		case "drink_RUM_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_02.wav");
		dialog.text = "� ���� ����� ���� ��������� ������� ����, � ���� �������� ������ ����� �� ��� �������, �� ��� �������� ����� - ��� ��������!";
		link.l1 = "";
		link.l1.go = "drink_RUM_3";
		break;

		case "drink_RUM_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_03.wav");
		dialog.text = "��� ����...";
		link.l1 = "";
		link.l1.go = "drink_RUM_4";
		break;
		
		case "drink_RUM_4":
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
				link.l1 = RandPhraseSimple(LinkRandPhrase("��, �� ���� �������� � ����������� ������ ���������, �������!","��, �� ���, ��� � ����!","��, �� ������������ �������������� ������ ������!"), LinkRandPhrase("��, �� ����� ������, �� ����� �����, ���� ������ �� ������� � ������!","��, �� ��, ����� ����� ������ ��� �������� �� ���� �����!","��, �� �������, �����, ������� �... ������!"));	
				link.l1.go = "drink_RUM_5";
			}
		break;

		case "drink_RUM_5":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "";
		link.l1 = "����������?";
		link.l1.go = "drink_RUM_6";
		break;
		
		case "drink_RUM_6":
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

		case "drink_STRONGER":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_00.wav");
		dialog.text = "";
		link.l1 = "� ���� ���� �� ���� �� ������!!!";
		link.l1.go = "drink_STRONGER_0";
		break;

		case "drink_STRONGER_0":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_09.wav");
	                   dialog.text = "��� ���� ��� �����������?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_TRADE";
		break;

		case "drink_STRONGER_TRADE":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_TRADE_15_00.wav");
	                   dialog.text = "";
		link.l1 = "� ������ �� ����� ������� �����!";
		link.l1.go = "drink_Grog_1";
		link.l2 = "��� ��� ����!";
		link.l2.go = "drink_Rumm_1";
		link.l3 = "������� ��!";
		link.l3.go = "drink_LOUSHAMMER_1";
		link.l4 = "��� ��� ������� �������!";
		link.l4.go = "drink_SCHNELLERHERING_1";
		link.l5 = "������ ��� ������� �����!";
		link.l5.go = "drink_LOUSDOUBLEHAMMER_1";
		link.l6 = "� ���������, ��� �������!";
		link.l6.go = "exit";
		break;

		case "drink_Grog_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_15_00.wav");
		dialog.text = "";
		link.l1 = "� ������ �� ����� ������� �����!";
		link.l1.go = "drink_Grog_2";
		break;

		case "drink_Grog_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_01.wav");
		dialog.text = "��, ��� ����� �� ����� � ����� ������� �� ������, ��� �������...";
		link.l1 = "";
		link.l1.go = "drink_Grog_2";
		break;

		case "drink_Grog_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_02.wav");
		dialog.text = "������� ���� ��� �����, � ���� ��������� ������� ���� �� ������� ������� ���� ��� ������ �� ��������� - �����!!!";
		link.l1 = "";
		link.l1.go = "drink_Grog_3";
		break;

		case "drink_Grog_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_03.wav");
		dialog.text = "�� ������ �������� ������� ����� - ������� ��������.";
		link.l1 = "";
		link.l1.go = "drink_Grog_4";
		break;

		case "drink_Grog_4":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_04.wav");
		dialog.text = "������ � ���� ����� �� �� ���������, ��������� ������� ������ ��������.";
		link.l1 = "";
		link.l1.go = "drink_Grog_5";
		break;

		case "drink_Grog_5":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_13.wav");
		dialog.text = "";
		link.l1 = "������� �� ������...";
		link.l1.go = "drink_Grog_6";
		break;

		case "drink_Grog_6":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_100.wav");
		dialog.text = "1�� ������� �����.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "��� ��� ������...";
				link.l1.go = "drink_Grog_7";
			}
			else
			{
				link.l1 = "� ���� �� ���������� ������...";
				link.l1.go = "exit_gold_Grog";
			}
		break;

		case "exit_gold_Grog":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "";
		link.l1 = "� ���� �� ���������� ������...";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_100;
		break;

		case "drink_Grog_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "drink_Grog_8";
		break;

		case "drink_Grog_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 100);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_Grog_9";
		break;

		                   case "drink_Grog_9":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Grog", 3);
		                   Log_Info("�� �������� 3 ��������� �����");
		                   PlaySound("interface\important_item.wav");
		                   break;



		case "drink_Rumm_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_15_00.wav");
		dialog.text = "";
		link.l1 = "��� ��� ����!";
		link.l1.go = "drink_Rumm_2";
		break;

		case "drink_Rumm_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_01.wav");
		dialog.text = "A, ��� ��� ������ �� �����, ��� ������ ������ - ��� ����...";
		link.l1 = "";
		link.l1.go = "drink_Rumm_3";
		break;

		case "drink_Rumm_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_02.wav");
		dialog.text = "� ���� ����� ���� ��������� ������� ����, � ���� �������� ������ ����� �� ��� �������, �� ��� �������� ����� - ��� ��������!";
		link.l1 = "";
		link.l1.go = "drink_Rumm_4";
		break;

		case "drink_Rumm_4":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_03.wav");
		dialog.text = "��� ����...";
		link.l1 = "";
		link.l1.go = "drink_Rumm_5";
		break;

		case "drink_Rumm_5":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "�������...";
		link.l1.go = "drink_Rumm_6";
		break;

		case "drink_Rumm_6":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_150.wav");
		dialog.text = "15� ������� �����.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 150)
			{
				link.l1 = "��� ��� ������...";
				link.l1.go = "drink_Rumm_7";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_Rumm";
			}
		break;

		case "exit_gold_Rumm":
 	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_04.wav");
		dialog.text = "� ���� ������������ ������ ��������, ��� ������ �����?";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_150;
		break;

		case "drink_Rumm_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "drink_Rumm_8";
		break;

		case "drink_Rumm_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 150);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_Rumm_9";
		break;

		                   case "drink_Rumm_9":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Rumm", 3);
		                   Log_Info("�� �������� 3 ��������� ����");
		                   PlaySound("interface\important_item.wav");
		                   break;


		case "drink_LOUSHAMMER_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_15_00.wav");
		dialog.text = "";
		link.l1 = "� ���� ������� ��!";
		link.l1.go = "drink_LOUSHAMMER_2";
		break;

		case "drink_LOUSHAMMER_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_TRADE_14_01.wav");
		dialog.text = "� ���� ������� ���� �� ����� ������ ��� �����!!!";
		link.l1 = "";
		link.l1.go = "drink_LOUSHAMMER_3";
		break;

		case "drink_LOUSHAMMER_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "�������...";
		link.l1.go = "drink_LOUSHAMMER_4";
		break;

		case "drink_LOUSHAMMER_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_250.wav");
		dialog.text = "25� ������� �����.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "��� ��� ������...";
				link.l1.go = "drink_LOUSHAMMER_7";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_LOUSHAMMER";
			}
		break;

		case "exit_gold_LOUSHAMMER":
 	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_04.wav");
		dialog.text = "� ���� ������������ ������ ��������, ��� ������ �����?";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_250;
		break;

		case "drink_LOUSHAMMER_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "drink_LOUSHAMMER_8";
		break;

		case "drink_LOUSHAMMER_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 250);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_LOUSHAMMER_9";
		break;

		                   case "drink_LOUSHAMMER_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_14_01.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Loushammer", 3);
		                   Log_Info("�� �������� 3 ��������� ������� ��");
		                   PlaySound("interface\important_item.wav");
		                   break;


		case "drink_SCHNELLERHERING_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_SCHNELLERHERING_15_00.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������� �������!";
		link.l1.go = "drink_SCHNELLERHERING_2";
		break;

		case "drink_SCHNELLERHERING_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_SCHNELLERHERING_14_01.wav");
		dialog.text = "���� �������, �� ����������!!!";
		link.l1 = "";
		link.l1.go = "drink_SCHNELLERHERING_3";
		break;

		case "drink_SCHNELLERHERING_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "�������...";
		link.l1.go = "drink_SCHNELLERHERING_4";
		break;

		case "drink_SCHNELLERHERING_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_500.wav");
		dialog.text = "500 ������� �����.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "��� ��� ������...";
				link.l1.go = "drink_SCHNELLERHERING_7";
			}
			else
			{
				link.l1 = "׸�� ������, ��� ������ - ��!";
				link.l1.go = "exit_gold_SCHNELLERHERING";
			}
		break;

		case "exit_gold_SCHNELLERHERING":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
		dialog.text = "";
		link.l1 = "׸�� ������, ��� ������ - ��!";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_500;
		break;

		case "drink_SCHNELLERHERING_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "drink_SCHNELLERHERING_8";
		break;

		case "drink_SCHNELLERHERING_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 500);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_SCHNELLERHERING_9";
		break;

		                   case "drink_SCHNELLERHERING_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_14_01.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Schnellerhering", 3);
		                   Log_Info("�� �������� 3 ��������� ������� �������");
		                   PlaySound("interface\important_item.wav");
		                   break;



		case "drink_LOUSDOUBLEHAMMER_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_15_00.wav");
		dialog.text = "";
		link.l1 = "������ ��� ������� �����!";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_2";
		break;

		case "drink_LOUSDOUBLEHAMMER_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_14_01.wav");
		dialog.text = "�� ����� �������� �����? ����� ��������, ��� ��� ������ �� ��� ����?";
		link.l1 = "";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_3";
		break;

		case "drink_LOUSDOUBLEHAMMER_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "�������...";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_4";
		break;

		case "drink_LOUSDOUBLEHAMMER_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_700.wav");
		dialog.text = "700 ������� �����.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 700)
			{
				link.l1 = "��� ��� ������...";
				link.l1.go = "drink_LOUSDOUBLEHAMMER_7";
			}
			else
			{
				link.l1 = "׸�� ������, ��� ������ - ��!";
				link.l1.go = "exit_gold_LOUSDOUBLEHAMMER";
			}
		break;

		case "exit_gold_LOUSDOUBLEHAMMER":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
		dialog.text = "";
		link.l1 = "׸�� ������, ��� ������ - ��!";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_700;
		break;

		case "drink_LOUSDOUBLEHAMMER_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_8";
		break;

		case "drink_LOUSDOUBLEHAMMER_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 700);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_9";
		break;

		                   case "drink_LOUSDOUBLEHAMMER_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_14_02.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Lousdoublehammer", 3);
		                   Log_Info("�� �������� 3 ��������� �������� ������� ��");
		                   PlaySound("interface\important_item.wav");
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

		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;



		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou"://������� �� ������� ������� � ������
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
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

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}
