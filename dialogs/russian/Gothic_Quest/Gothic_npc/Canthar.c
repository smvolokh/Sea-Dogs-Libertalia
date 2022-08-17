// ������ ������ ��������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	
	switch(Dialog.CurrentNode)
	{

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_TRADE_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ ��� ���� ������.";
		link.l1.go = "Canthar_Trade_1";
		break;

		case "Canthar_Trade_1":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_TRADE_09_01.wav");
		dialog.text = "�������.";
		link.l1 = "...";
		link.l1.go = "Canthar_Trade_exit";

	                 if(CheckAttribute(pchar, "questTemp.GothicCanthar") && pchar.questTemp.GothicCanthar == "griddle" && !CheckAttribute(npchar, "quest.griddle"))
		{
		link.l1 = "� ���� ���� � ������� ����������?";
		link.l1.go = "Canthar_griddle";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicCanthar") && pchar.questTemp.GothicCanthar == "Canthar_20" && !CheckAttribute(npchar, "quest.Canthar_20"))
	       {
		if (GetCharacterItem(pchar, "gold_dublon") >= 20)
		{
		link.l1 = "����� ���� ����������.";
		link.l1.go = "Canthar_griddle_1";
		}
                              }

		break;

		case "Canthar_Trade_exit":
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LaunchItemsTrade(npchar, 0);
		break;


		case "Canthar_hallo":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_00.wav");
		dialog.text = "���������� ��� � ��� �����!";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_1";			
		break;

		case "Canthar_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_01.wav");
		dialog.text = "�� ���� ���� � �����, � �� ����?";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_2";			
		break;

		case "Canthar_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "����� ����.";
		link.l1.go = "Canthar_hallo_3";			
		break;

		case "Canthar_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_03.wav");
		dialog.text = "��...�� ����� �� �������, ��� ������� ������������ � �����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_4";			
		break;

		case "Canthar_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_04.wav");
		dialog.text = "�������� �� ���� ������ ��������� �� �������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_5";			
		break;

		case "Canthar_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_HALLO_09_05.wav");
		dialog.text = "���� �� ������� �� ���� �� ������, �� ��� ������� � ���� ���� ���������� ����������� ��� ����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_6";			
		break;

		case "Canthar_hallo_6":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_PAYPRICEINCITY_15_02.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������?";
		link.l1.go = "Canthar_hallo_7";			
		break;

		case "Canthar_hallo_7":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_01.wav");
		dialog.text = "���� �� ���� ��� �� ���������, ������ ������� �� ������ ���� � �����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_8";			
		break;

		case "Canthar_hallo_8":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_02.wav");
		dialog.text = "���� �� ������ �������� ��� �� ����������� �� �������� � ����� ��� �������� �� ����, ��� ������� �� ������ ���� � �����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_9";			
		break;

		case "Canthar_hallo_9":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_03.wav");
		dialog.text = "� ���� ������ ������� ���� � �����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_10";			
		break;

		case "Canthar_hallo_10":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_04.wav");
		dialog.text = "� ���� ���� ��� ���� ������ ������ � ����������� ������� � �������� �����������, �������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_11";			
		break;

		case "Canthar_hallo_11":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_05.wav");
		dialog.text = "� ���� ��������� � ������� �� ������� �������� ����� � ����� � ������� ������� ���������� ����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_12";			
		break;

		case "Canthar_hallo_12":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_09_06.wav");
		dialog.text = "���� ��� ���������?";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_13";			
		break;

		case "Canthar_hallo_13":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_HOWYOUIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� �� ������� � �����!";
		link.l1.go = "Canthar_hallo_14";			
		break;

		case "Canthar_hallo_14":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_HOWYOUIN_09_01.wav");
		dialog.text = "������ ����� ����, � �� ������ �����, ��� ������� �������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_15";			
		break;

		case "Canthar_hallo_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������ �� ���� �������.";
		link.l1.go = "Canthar_hallo_16";			
		break;

		case "Canthar_hallo_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_01.wav");
		dialog.text = "� ����, ��� �� ������ � ����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_17";			
		break;

		case "Canthar_hallo_17":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_02.wav");
		dialog.text = "��������, �� �������� �� ���� ������� ����� ������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_18";			
		break;

		case "Canthar_hallo_18":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_15_03.wav");
		dialog.text = "...";
		link.l1 = "������ ���!";
		link.l1.go = "Canthar_hallo_19";			
		break;

		case "Canthar_hallo_19":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_04.wav");
		dialog.text = "��.. ��, ���� � ���� ������� � ������, �� ������ ������ ������� ��� ������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_20";			
		break;

		case "Canthar_hallo_20":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_PRICE_09_05.wav");
		dialog.text = "��, ��� ������������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_21";			
		break;

		case "Canthar_hallo_21":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_STRINGS_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ������ �� ������!";
		link.l1.go = "Canthar_hallo_22";			
		break;

		case "Canthar_hallo_22":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_STRINGS_09_01.wav");
		dialog.text = "���, �������� �������, �� ������ ������� ��� ������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_23";			
		break;

		case "Canthar_hallo_23":
		dialog.text = "...";
		link.l1 = "���, ������ ��� ������ ����.";
		link.l1.go = "Canthar_hallo_NO_15";
		link.l2 = "�������, ����� ���� ��� ������.";
		link.l2.go = "Canthar_hallo_OK_15";			
		break;
	
		case "Canthar_hallo_NO_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_15_00.wav");
		dialog.text = "...";
		link.l1 = "���, ������ ��� ������ ����.";
		link.l1.go = "Canthar_hallo_NO_16";			
		break;

		case "Canthar_hallo_NO_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_09_01.wav");
		dialog.text = "��, ������ �, �� �� ������ ����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_NO_17";			
		break;

		case "Canthar_hallo_NO_17":
                                         //pchar.questTemp.GothicCanthar = "griddle";
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_NO_09_02.wav");
		dialog.text = "�����, ���� �����, ��� - ������ ���, ����� �������� ���� ��� ������?";
		link.l1 = "...";
		link.l1.go = "First time";			
		break;				
	
		case "Canthar_hallo_OK_15":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_15_00.wav");
		dialog.text = "...";
		link.l1 = "�������, ����� ���� ��� ������.";
		link.l1.go = "Canthar_hallo_OK_16";			
		break;

		case "Canthar_hallo_OK_16":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_01.wav");
		dialog.text = "�����, �� ��������� � ��� ���������, ��� ����� ������.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_OK_17";			
		break;

		case "Canthar_hallo_OK_17":
		GiveItem2Character(pchar, "VerifyPaper");
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_02.wav");
		dialog.text = "� ��� ����, �� �� � �� ����� �������� ��� �����.";
		link.l1 = "...";
		link.l1.go = "Canthar_hallo_OK_18";			
		break;

		case "Canthar_hallo_OK_18":
	                     PlaySound("VOICE\Russian\gotica\CANTHAR\DIA_CANTHAR_WHATOFFER_OK_09_03.wav");
		dialog.text = "� �������� � ���� ����� ������� ������� � ������ ������ ��� ���� ��� � ��� �� �����, �� ������ ���.";
		link.l1 = "...";
		link.l1.go = "exit";			
		break;					



       		case "Canthar_griddle":
		dialog.text = "��, � ���� ����� ���� ���� � ���������� � ��� �����.";
		link.l1 = "������ ����.";
		link.l1.go = "Canthar_griddle_1";
		break;

       		case "Canthar_griddle_1":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_9_GOLD_20.wav");
		dialog.text = "20 ������� �����.";
		if (GetCharacterItem(pchar, "gold_dublon") >= 20)
		{
		link.l1 = "������, ��� ���� 20 ��������... ����� ���� ����������.";
		link.l1.go = "guess_04";
		}
		else
		{
		link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
		link.l1.go = "exit_gold_1";
		}
		break;

		case "exit_gold_1":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� ������������ ������...";
		link.l1 = "...";
		link.l1.go = "exit_no_gold_20";
		break;

		case "Exit_no_gold_20":
		npchar.quest.griddle = "true";
                                          pchar.questTemp.GothicCanthar = "Canthar_20";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;  

		case "guess_04":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "...";
		link.l1 = "��� ��� ������...";
		link.l1.go = "guess_05";
		break;

		case "guess_05":
		GiveItem2Character(pchar, "griddle");
		Log_Info("�� �������� ����������");
		PlaySound("interface\important_item.wav");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 20);
		dialog.text = "...";
		link.l1 = "...";
		link.l1.go = "exit_5";
		break;

		case "Exit_5":
		npchar.quest.Canthar_20 = "true";
		npchar.quest.griddle = "true";
                                          pchar.questTemp.GothicHilda_griddle.over = "griddle";	
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		SetFunctionTimerCondition("Hilda_griddle_Remove", 0, 0, 1, false);
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
				dialog.text = NPCharSexPhrase(NPChar, "���������� �� ���������, ��������, ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� ������� ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����.", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- ����������� �������	

	}
}
