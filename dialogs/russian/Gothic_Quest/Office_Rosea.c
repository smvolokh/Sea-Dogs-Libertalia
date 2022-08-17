// ��� ����� �������
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	string sTemp,sTemp1, str, str1;
	int	s1,s2,s3,s4,s5,p1,iColony;
	int i;
                    string attrLoc;
                    attrLoc   = Dialog.CurrentNode;
  
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";

		break;
		
		// ������
		case "W_officer":

				dialog.text = "��, ��� ������ � ����� ���������. ����� ����, ����� ������ ������� ��� ��, ������� ��� �����? ��� ��� ������?";
				link.l1 = "� ����� �� �������� �����. ��������, ����������� ������� � ������...";
				link.l1.go = "W_officer_1";
				link.l2 = "����������! � �������� �������� ����� ���������� ����.";
				link.l2.go = "toHostessSex";
				link.l3 = "� ���������, ��� �������, " + npchar.name + ". ���-������ � ������ ���...";
				link.l3.go = "W_officer_exit";
				break;

		case "exit1":
				dialog.text = "� ������� ���, ����� � ����� ���� � �������, �� �� ������... �� ������� ���� ����.";
				link.l1 = "��, ����...";
				link.l1.go = "W_officer";
				break;				
		
		case "W_officer_1":
			dialog.text = "��� ��� � ����� �������� ������. �� �� ������ �� ������ �����. �� ���������� ����� ������ � ��������� ����������. �������� �� � ����������� �� ������ ����� �� �������.";
			link.l1 = "�������, �������, �� ����� �������...";
			link.l1.go = "W_officer_exit";
		break;
		
		case "W_officer_exit":
			DialogExit();			
			NextDiag.TempNode = "W_officer";
		break;
		

		
		// ������
		case "W_clerk":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "�������! ���� � ���������! �������!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			dialog.text = "���� ��� ���-�� ����� - ���������� � ����� ������.";
			link.l1 = "������, � �����" + GetSexPhrase("","�") + ".";
			link.l1.go = "exit";			
			NextDiag.TempNode = "W_clerk";
		break;
		
		// ������� ����� 
		case "W_headclerk":

			dialog.text = "�� ���-�� ������, " + GetSexPhrase("������","����������") + "?";
			if (!CheckCharacterItem(pchar, "PirTradeLicence"))
			{
				link.l1 = "� ���� ���������� �������� �������� ����������� ����-������� ��������.";
				link.l1.go = "licence";
				link.l2 = "� ���� ���������� � ��� ������� ����������� ������ ��� �������� �����.";
				link.l2.go = "flags";		
			}
			if (!CheckAttribute(npchar, "quest.trade"))
			{
				link.l3 = "� ������, ��� � ��� ����� ���������� ����������� ������� � ������ �������� ����. ��� ���?";
				link.l3.go = "trade";	
			}
			else
			{
				link.l3 = "��� � ��� ������� ������� � �������? ��������, ����������.";
				link.l3.go = "trade_1";	
			}

			//������� ���, ������ �������� -->
			if (pchar.questTemp.LSCC == "toLicencer")
			{
				link.l4 = "� ���� ���� � ��� ������ �� ������ ����������� ����-������� ��������.";
				link.l4.go = "SeekHVIC";
			}
			if (pchar.questTemp.LSCC == "toLicencer_2")
			{
				link.l4 = "��, ����� �������� �� ���� ������� ������. � ����� �� ������ ����������� ����-������� ��������.";
				link.l4.go = "SeekHVIC_3";
			}

			link.l9 = "���, ���� ������.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "W_headclerk";
		break;
		
		// �������� ��������
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� � ������ ������� ��� ������������, ��� �������� ������� ����� ������, ������� � ����������� ������������ ������������ ���������� �� ���� ���� �������� ��������, � ������ - ������� ����������� �������� � ��������� �������� �������� ����� �����\n� ������ ��������� ������ ����� ���� �������� ����� ���������� ������������. ����� �� �������� ���������, ���� �� �����-�� ��������, ������� �����, �������� � �������� � ����������. ��� �������?";
				link.l1 = "����������. � ����� ��� � ��������.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� ����� ���� �� ������ �������� ��������?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;
		
		case "licence_0":
			dialog.text = "�������� ���� ����� ������������������ ����� � ����� ���� ����� �����, ��������� ������������ ���� ������ ��������� � ��������� ���� ������ �������� - ���������. ������ ���� � ��� ���� �������� � ������� � ��� ������, � ���� ������� �� �������� �������, �������� ��� �� �������. ����� ���� - � ��� �� ������ ������. ������ ���\n���� �� ����������� ��������� � ���������� ��� �������� - �� �������� ����� ������ � ���� ������� ������������� ���� - ��� ������� ��� �� �������� �������, ��������� �������� ������ � ������� � ������� ����� ���������� ������� ��������, � ������ ����� �����������\n��, ���� �� �����: �������� ����������� ��������, ������ �� �������� ������������ ������������� �������� ���������... ��, ������, ��������, ��� ���������. �� ����� ���� �� ������ �������� ��������?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
		
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			//npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*1000;
			// ������� � ���������
			if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*3;
        else npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "�����, ����������, �������� �����, �� ���������� � �� �������. � ��� ����� ���������. ��� �� ������� ���� ��� ����� ��������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "����������� ����, �� ������� �� ������ �������� - �������� ����. �� ������� ����� ��� �������� - �� ��������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "������������ ����, �� ������� �� ������ �������� - �������. �� ������� ����� ��� �������� - �� ��� �����������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "�� "+FindRussianDaysString(sti(fQty))+"? ������. ��������� ����� �������� �������� "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
			//if (sti(pchar.money) >= sti(npchar.quest.lcc_summ))
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "��, �������, ����������.";
				link.l1.go = "licence_2";
			}
			link.l2 = "� ���������, � ���� ��� ������ � ����� ������� �����. � ����� � ��� �� ��������� �����.";
			link.l2.go = "exit";
		break;
		
		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			//AddMoneyToCharacter(pchar, -sti(npchar.quest.lcc_summ));
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "���, ���� ������... ������ �������� ������� � ������... ���, ������. �������� ��� ��������.";
			link.l1 = "�������! �� ��������, �����.";
			link.l1.go = "exit";
		break;
		
		case "trade":
			dialog.text = "����� ��� �� ��������. ����� �� ������ ���������� ������������� �������, ����� ��� ����������� ������, ����������, ��������� � �������� ���� ��� ��������� ���������� �� ������� ������� �����. ������ � ������� ��� ������ �� ������, �� ����������� ����� ��� �������� ����� - ���������, ��������� ��. ��� ��� ���� �� ������� ������, ��� ������ - ������� ����� ��������\n����� ������������ � ��� � ������� ���������� ����� ���������� � ��������� �����. ������� ���������� ����������� �� �������?";
			link.l1 = "��, ������ ��� �������.";
			link.l1.go = "trade_1";
			npchar.quest.trade = "true";
		break;
		
		case "trade_1":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 7)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);			
		break;
		
		// ������ ��������
		case "depeshe":
			dialog.text = "��, ��������...(������) ���-���... ������, �������� ���� ����, ��� �� ������� � ������... ��� �������! ��� �� ������� ��� ������?";
			link.l1 = "���������� � ������ ����������� �������. �� ��� ���, ������ �� ��������?";
			link.l1.go = "depeshe_1";
		break;
		
		case "depeshe_1":
			dialog.text = "��. ����� ���������� ����� ��� �� ��������, � ������. ��� � ������� ���������� ����... � ���� ��������� �������, ��� �������� ��� �������� �������� �� ������������ ���� - �������. ��� ���������?";
			link.l1 = "� ������� ������.";
			link.l1.go = "depeshe_dublon";
			link.l2 = "� ���� �������� ��������.";
			link.l2.go = "depeshe_licence";
		break;
		
		case "depeshe_dublon":
			TakeNItems(pchar, "gold_dublon", 700);
			Log_Info("�� �������� 700 ��������");
			dialog.text = "������. ��� ������� ��������. ������ � ��������� ��� �� ��� ������ � ����� ������ �� �����.";
			link.l1 = "����������, ���������. ��� ���� ������.";
			link.l1.go = "depeshe_exit";
		break;
		
		case "depeshe_licence":
			if (CheckCharacterItem(pchar, "FraTradeLicence")) TakeNationLicence(HOLLAND);
			GiveNationLicence(HOLLAND, 180);
			dialog.text = "������. ��� ���� �������� �� �������.";
			link.l1 = "�������! � ��� ���� ������.";
			link.l1.go = "depeshe_exit";
		break;
		
		case "depeshe_exit":
			RemoveItems(pchar, "Cromvel_depeshe", 1);
			pchar.quest.Terrapin_CromvelScuadron.over = "yes"; //����� ����������
			ChangeCharacterNationReputation(pchar, HOLLAND, 15);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			dialog.text = "���������. ���������, ��� �� �������� �������������� � ���������� �� ��������� � ���������. � ������ � ����� �������� ������� ���� � ������ �����������.";
			link.l1 = "�� ��� � ��� ��������� ������, �� � �� ��������. �� ��������!";
			link.l1.go = "exit";
		break;
		
		// ����� ���� ����
		case "HWIC_Boss":
			if (!CheckAttribute(npchar, "quest.silk_info") && sti(pchar.reputation.nobility) > 60)
			{
				dialog.text = "�-�, ������� " + GetFullName(pchar) + "! ����� ������, ��� �� �� ��� �����. � ���� ��� ��� ���� ������� �����������.";
				link.l1 = "����� �������! ����������� ��� ������, ������.";
				link.l1.go = "silk_info";
				break;
			}
			dialog.text = "������������, ������� " + GetFullName(pchar) + "! ��� ���� �������?";
			if(CheckAttribute(npchar, "quest.silk")) // �������� ������
			{
				if (GetDataDay() == 1 || GetDataDay() == 15)
				{
					link.l1 = "� �� ������ ������������ �����...";
					link.l1.go = "trade_silk";
				}
			}
			link.l2 = "������ ����. ���, ������ �� ���� - � ������ ����� ���������������� ���.";
			link.l2.go = "exit";			
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "silk_info":
			dialog.text = "� ������� ������� �������� ����� � ����� ������ �� ����� � ����������� � ��������� �� ������ ������ ������������ �����. �� ������, ��� ��� �� �����? �� ���� ������������� ����� ������ �� ����� ������, ��� ��� ��� ��� ��������� ����� ���������.";
			link.l1 = "��������, ��� ���������� �����������. ������ �������?";
			link.l1.go = "silk_info_1";
		break;
		
		case "silk_info_1":
			dialog.text = "�������� � ���� ���� ���������, �� � ��������� �������. ��� ��� � ���� ��������� �� �������� ������� ������ ������ ��� ������. ��������� ������ ������ - �������� ������� ��������. ������� �������� ���: ������� ������� � ������������ ����� ������ � ���� ������������ ��� ��� �������� �������. ���� �� �� ������� �� ���� � ��� ��� - � ������ ������� ����������.";
			link.l1 = "�� ���� ������� ������������ � �� ����?";
			link.l1.go = "silk_info_2";
		break;
		
		case "silk_info_2":
			dialog.text = "������! ������ - ���������, ������ - ���. ��� ������ ����������� ��������� - �������� ��������. �������, �� ������� ���� ���������� �����������.";
			link.l1 = "������� �� �����������, ������. �����, � ����������� �� ������������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "W_Boss";
			npchar.quest.silk_info = "true";
			npchar.quest.silk = "true";
		break;
		
		// �������� ������
		case "trade_silk":
			dialog.text = "�������, �������. ���� ��� ����������. ������ ��� ��������?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 600)
			{
				link.l1 = "�������! ���, �������� ����� ����� ��������.";
				link.l1.go = "trade_silk_1";
			}
			else
			{
				link.l1 = "��� ��������, ����� ������ �� �������. ������ �������!";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "trade_silk_1":
			RemoveItems(pchar, "gold_dublon", 600);
			Log_Info("�� ������ 600 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "������� ����� � ���� ����, �������. ���� ����� ��������� ������ � ������ �������.";
			link.l1 = "�������!";
			link.l1.go = "trade_silk_2";
		break;
		
		case "trade_silk_2":
			dialog.text = "������� ������� ��� � ���� ��� �� ���� ���. ���������, ���������.";
			link.l1 = "�����������. �� �������!";
			link.l1.go = "exit";
			AddCharacterGoods(pchar, GOOD_SHIPSILK, 30);
			DeleteAttribute(npchar, "quest.silk");
			SetFunctionTimerCondition("Silk_TraderAttrReturn", 0, 0, 1, false); // ������
			AddCharacterExpToSkill(pchar, "Commerce", 150);
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "fight":
			DialogExit();
			sld = characterFromId("W_officer");
			LAi_SetGuardianTypeNoGroup(sld);
			LAi_group_Attack(sld, Pchar);
			for (i=1; i<=6; i++)
			{	
				sld = characterFromId("W_sold_"+i);
				LAi_group_Attack(sld, Pchar);
			}
		break;


		case "toHostessSex":
                                                          DoQuestFunctionDelay("SMALLTALK_1", 2.5);
			dialog.text = "�� ����� ���. ��� ��� �� ���� ����������?";
			link.l1 = "���?! ��... � ��� ���! � ���� ����� �������... �-�-�... ���������... ����� �������. ���.";
			link.l1.go = "toHostessSex_1";
			link.l2 = "� ���� ������ ���� � ������� ����, � ���...";
			link.l2.go = "toHostessSex_2";
			link.l3 = "�����, � ������� ������� �� �� ���� �����...";
			link.l3.go = "toHostessSex_3";
		break;
		case "toHostessSex_1":
			dialog.text = "���� '���������' ��� �� ���������. ������...";
			link.l1 = "��� �� ���?..";
			link.l1.go = "Exit_1";
		break;
		case "toHostessSex_2":
			if (rand(1))
			{
				dialog.text = "��������! ����� ���������������, ������ ���� ��� ��������� ���� ��������?! �������� ������������� �������, � ����� ������!";
				link.l1 = "�! �������. ��� �����! ������, ���� ���� ���...";
				link.l1.go = "SpeakHistory";
			}
			else
			{
				dialog.text = "��������! ����� ���������������, ������ ���� ��� ��������� ���� ��������?! �� ���������� �� ������, ��� �������� �������...";
				link.l1 = "��, ���� ����� ���������� ��� ��� ���������.";
				link.l1.go = "SpeakHistoryTwo";
			}
		break;
		case "toHostessSex_3":
			dialog.text = "��������� � ������� �����-������ �������� � ������. � ��� ���������� �����?! �-��, ���� ���������� ��������� �������?..";
			link.l1 = "� �� ��� ���� �����!";
			link.l1.go = "Exit_1";
		break;
		//�������
		case "SpeakHistory":
			dialog.text = "����������� ������...";
			if (rand(1))
			{
				link.l1 = "���� � ���� ���� �������, ��� ���� ���� �� ����� �����. ������ ���������?";
				link.l1.go = "SpeakHistory_1";
			}
			else
			{
				link.l1 = "���-�� ����� �� ������ ��������, ������� ������, ������ � ����, � ���� ��������� � �����! ������ � �������! ������� ������, ��� � ����! ��-��! � ��� � ���� �� ����� ���� ������� �������, ����� ������, ����������, �� �� ���������� ��������...";
				link.l1.go = "SpeakHistory_2";
			}
		break;
		case "SpeakHistory_1":
			dialog.text = "�-�! �� ���� �������� �����! ��� �� ���� ������� ��������?!";
			link.l1 = "��, ����� �� �������. ������ �� ���-�� � ������ �����, �� �������, � ���� ���������� �����. ������ �� �����������, ���� ���������� �������. ��� ����� �����������, ������ � ����, ��������� ����� ���������� ���� � ����. � ��� � ������� ��������� � ��������, ��� �� ������� ������ ����������: '" + GetAddress_Form(PChar) + ", ����������! �����! �����!!!'. � ��� � �� ������! � ��� ��� ������ � ������� �� ������ ��� �����. �� � ���������! � ���� ��� ������ ����! � ���� ������ ��� ��������������� � ���� ����� �� ����!..";
			link.l1.go = "SpeakHistory_3";
		break;
		case "SpeakHistory_2":
			dialog.text = "������! � ���� ��������! �� ������, �������������� ���! �������� � ���� ����!";
			link.l1 = "��, �� ���?..";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_3":
			dialog.text = "�, ����! � ��� ��?!";
			link.l1 = "� �������, ��� ��� �������� � ���� �����, �������������� � �����, ��� ���� ���� � ������, ��� ������ �������� ���������� �������� �����, �� ������ ������� ����� ��������... �� ������ ���������� ����� ���� �����, � �� ���� ������ ��� ��������� �������� �������...";
			link.l1.go = "SpeakHistory_4";
		break;
		case "SpeakHistory_4":
			dialog.text = "� ��?!..";
			link.l1 = "���, �� �. ����. ��� ������� ����. ������, ��� � �� ������� ������� �� ������, � ����� ��� �����.";
			link.l1.go = "SpeakHistory_5";
		break;
		case "SpeakHistory_5":
			dialog.text = "� �� �� �������! ������?! ���� �� ������� ����� �������?";
			link.l1 = "��, ������� �������! ��� ���� �������� ���� ������ ������ - � ������� ������ ��������!";
			link.l1.go = "SpeakHistory_6";
			link.l2 = "���, �� �������. ��� ��, ����� ����� �������� ����� ���������! � ������ ��-�������...";
			link.l2.go = "SpeakHistory_7";
		break;
		case "SpeakHistory_6":
			dialog.text = "��-��... �� ���������� ����! �������� � ����, ������� � ���� ��� ������ ����?.. � ���� �� ����, �� ����� �� �������, ��� � ���! �� ���� �� �������������...";
			link.l1 = "������!! ����, ������...";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_7":
			dialog.text = "� ��� ��?! ��� �� �� ������?";
			link.l1 = "� ��� ����� �������� �����, � �����������, ��� ������ ������������� �� ���� ��������, ������ �������� �����, �������. � ��� ������ �� ����������, ����� ��� ������ ����� ��� ���� � �������, ��� ����� �������� ������ ������ ��������! � �������������, ����� ������� ������, � ���� �� �������, ���������� ��� �������� ��� �������, ��� � ������� �� �����������! � ���� �������, ����� ����� ���������� �� ����� � ��������� ����������� �� ����, � ��� ��� � ������ � ������ ������ �� ��� ���� � �������... �� ������ � ��� �������, � ���� �������� ��������� ������.";
			link.l1.go = "SpeakHistory_8";
		break;
		case "SpeakHistory_8":
			dialog.text = "�-�! �����!.. ������ ���...";
			link.l1 = "������ ������! ������ � ���� ����� ������, �����!..";
			link.l1.go = "SpeakHistory_9";
			link.l2 = "��������? �����?! ��, �, �������, �����, ��������, �� ������������� ��� ����, � �������, ���� ����� ����� �����������... � �� ���� ���� �����������������.";
			link.l2.go = "SpeakHistory_10";
		break;
		case "SpeakHistory_9":
			dialog.text = "��, ���! ������� �� ������, ��� ����� ���� � �����! �� ���� ��������!";
			link.l1 = "��, ������, �� ��� ��?..";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_10":
			dialog.text = "��, ��� �� ����������! � ���� �� ��������� ������, �������� ������ ��������� �������. ��������, �� ������������� ������� ��������� �... ������������, �� � ��� ���� ����� ��������...  � �����, ��� ���-���� ��������� ���������� �� ���� �����, �������� � ������� ������, ��� ��� ����� �� �����������... � ���, ��������, �� ���� �������� ���-������ ����������...";
			link.l1 = "��, ��� ��� �������!..";
			link.l1.go = "Exit_1";
			pchar.questTemp.different.OfficeSex = "toRoomm";
			AddDialogExitQuestFunction("SexWithOffice_goToRoomm");
			pchar.quest.SmallQuests_free.over = "yes"; 
			SetTimerFunction("SexWithOffice_nulls", 0, 0, 1); //������� ������� �� �����, ���� �� �� ������� � �������
		break;

		case "Office_inSexRoomm":
			dialog.text = "��, ��� � ��...";
			link.l1 = "��� �����, ��� ��������!";
			link.l1.go = "exit";
			pchar.quest.SexWithOffice_nulls.over = "yes"; //����� ������ �� �� ������
			NextDiag.TempNode = "First time";
			AddDialogExitQuestFunction("SexWithOffice_fackk");
			AddCharacterExpToSkill(pchar, "Leadership", 100);
            		AddCharacterExpToSkill(pchar, "Fencing", -50);
            		AddCharacterExpToSkill(pchar, "Pistol", -50);
            		AddCharacterHealth(pchar, 10);
		break;

		case "SpeakHistoryTwo":
			dialog.text = "��������?";
			link.l1 = "��������, ��� ��. ��������, ������������� ����!";
			link.l1.go = "SpeakHistoryTwo_1";
		break;
		case "SpeakHistoryTwo_1":
			dialog.text = "���������, �� ������ �� ����...";
			link.l1 = "� ����� ����! ������ � �����, ��� ��� �����! ��� ������ � ���� ������, ����� �����, �� ������ ����� ����! ����� �������������� ������� � ��� �� ��������! ����� �����, ���� ���!..";
			link.l1.go = "SpeakHistoryTwo_2";
			link.l2 = "� ���� ���������.";
			link.l2.go = "SpeakHistoryTwo_3";
		break;
		case "SpeakHistoryTwo_2":
			dialog.text = "�����, ��� ��� ����� �� ��� ����. �� ������� ���� ����, ���������� �� ���...";
			link.l1 = "������, ��� �� ���?!";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistoryTwo_3":
			dialog.text = "��, ����� � ���� ��������...";
			link.l1 = "� ������� ������ ������, � ������ ������ �����, ���, ���, �� ��� ���� ����� ���������, ����� �������� ��� ��. � ��� ���� � ����...";
			link.l1.go = "SpeakHistoryTwo_4";
		break;
		case "SpeakHistoryTwo_4":
			dialog.text = "������ �� ��� ������������?";
			link.l1 = "��� ���� ���� ����� ������ � ����!";
			link.l1.go = "SpeakHistoryTwo_5";
		break;
		case "SpeakHistoryTwo_5":
			dialog.text = "��� ���� ��?";
			link.l1 = "����� �������� � ����� �������, ��� ��������!";
			link.l1.go = "SpeakHistoryTwo_6";
			link.l2 = "��� ������������ ���� �������, ���� ������ � ������� ��� ������. ��� ��� ���� ������ � �����, � ��� ����� ��������� ��� �������, ������ ���� �����, ������� �������� ������ � � ����� ��������� ������, ������� ����� �� ��������� �������������� �����...";
			link.l2.go = "SpeakHistoryTwo_7";
		break;
		case "SpeakHistoryTwo_6":
			dialog.text = "��������! �� ������� ����. �� ������� ���� ����.";
			link.l1 = "����, �� ����������...";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistoryTwo_7":
			dialog.text = "�-�!.. � �� ��������... � ������!";
			link.l1 = "������? ������! � ������ ������. � ������, ���, �������������. �� ��� ������, ��� ��� ����� ����������� ��� ���� ���� ����� ��������������, ���������� ��������...";
			link.l1.go = "SpeakHistoryTwo_8";
		break;
		case "SpeakHistoryTwo_8":
			dialog.text = "���-�-�?!!";
			link.l1 = "...������� ����.";
			link.l1.go = "SpeakHistoryTwo_9";
		break;
		case "SpeakHistoryTwo_9":
			dialog.text = "�! ���-�� � �� � ��� ��������. ���������, ����� ����.";
			link.l1 = "�� ������ ������, � ���� ����� �� ������ � ����� ������...";
			link.l1.go = "SpeakHistoryTwo_10";
			link.l2 = "��� �� ����� �������� � ���-�� ������? �������, � ���� ����� ������ �����.";
			link.l2.go = "SpeakHistoryTwo_15";
		break;
		case "SpeakHistoryTwo_10":
			dialog.text = "��? � � ��� �� ���? ���� ����� ������������.";
			link.l1 = "� ����� ���������� �����, � � ����� ���������� ��������, � � ���� ������������� �������, ��� ������ � �������, ����� ��������� ���� ����!";
			link.l1.go = "SpeakHistoryTwo_11";
		break;
		case "SpeakHistoryTwo_11":
			dialog.text = "������!..";
			link.l1 = "���� �����... � ��, ��������, ��������� ���� �����, ��... ����� �� ���� ���������� ������, � ����������� ����� � ���, ��� ��� ���. ��, ������, � �������...";
			link.l1.go = "SpeakHistoryTwo_12";
		break;
		case "SpeakHistoryTwo_12":
			dialog.text = "������ � ����... �...";
			link.l1 = "���?";
			link.l1.go = "SpeakHistoryTwo_13";
		break;
		case "SpeakHistoryTwo_13":
			dialog.text = "�������������� ����...";
			link.l1 = "��� � ������?";
			link.l1.go = "SpeakHistoryTwo_14";
		break;
		case "SpeakHistoryTwo_14":
			dialog.text = "���� �����... ����� ������� �����, ����� ������� � ������� ������, ��� ����������, ��� � ���������... ��������.";
			link.l1 = "� ���������� �������������!";
			link.l1.go = "exit";
			pchar.questTemp.different.OfficeSex = "toRoomm";
			AddDialogExitQuestFunction("SexWithOffice_goToRoomm");
			pchar.quest.SmallQuests_free.over = "yes"; 
			SetTimerFunction("SexWithOffice_nulls", 0, 0, 1); //������� ������� �� �����, ���� �� �� ������� � �������
		break;

		case "SpeakHistoryTwo_15":
			dialog.text = "��? � � ������, ��� ��������� ���� �������, � �� ���������� ��������. ������ �����! � ���� ���, � ���������� ������ �� �� ���?!";
			link.l1 = "� �� �� ���� � ����...";
			link.l1.go = "SpeakHistoryTwo_16";
		break;
		case "SpeakHistoryTwo_16":
			dialog.text = "����, ��� �� ����� � ����! �������, � ������� ��������! ��� ���! ����������! �� ��� ��������!";
			link.l1 = "�� �� ��� " + npchar.name + ", � � ������ �� ����!..";
			link.l1.go = "Exit_1";
		break;

		//������� ���
		case "SeekHVIC":
			dialog.text = "��-�, ������... �������, � ��� ��� ��� ���������� �������������� ���� ��������?";
			link.l1 = "� �������� ��� ��� ���� �����, � �������� �������.";
			link.l1.go = "SeekHVIC_1";
		break;
		case "SeekHVIC_1":
			dialog.text = "� � ���� �� �����, ��� � ����, ��� ��� ���������?";
			link.l1 = "�����, ������ ������ ������! �������� �� ���� �������� �� ������ ������?";
			link.l1.go = "SeekHVIC_2";
		break;
		case "SeekHVIC_2":
			dialog.text = "� ������������� �������� �����, � ��������� ����. ������, ��� ��� �����? ���� �� ������ � ��� ����, �� ������ ��� �����.";
			Link.l1.edit = 6;
			link.l1 = "";
			link.l1.go = "SeekHVIC_res";
		break;

		case "SeekHVIC_res":
			attrLoc = GetStrSmallRegister(dialogEditStrings[6]);
			if (findsubstr(attrLoc, "������" , 0) != -1 && findsubstr(attrLoc, "�����" , 0) != -1)
			{

				dialog.text = "��, �����... �� �����, �� ������ ����� ��� � �����������, � ����-�������. � ���� ��� ������� � ����������� ����. ������ �� ��������, ��� ��� � ��� � ���� ��������. ���, �� ������ ������...";
				link.l1 = "��� �������.";
				link.l1.go = "exit";
				LAi_group_Delete("EnemyFight");
				pchar.questTemp.LSCC = "toOliverTrast";
				AddQuestRecord("ISS_PoorsMurder", "10");
				LocatorReloadEnterDisable("Marigo_town", "houseH2", false);

				//����� ������ ������
				ChangeItemName("letter_LSCC_1", "itmname_letter_LSCC_1");
				ChangeItemDescribe("letter_LSCC_1", "itmdescr_letter_LSCC_1");
				sld = ItemsFromID("letter_LSCC_1");
				sld.shown = true;
				sld.startLocation = "Marigo_houseH2";
				sld.startLocator = "item1";
			}
			else
			{
				dialog.text = "������ �� �� ������, ��� ��� ����������!";
				link.l1 = "����, �������� �� ������...";
				link.l1.go = "exit";
				pchar.questTemp.LSCC = "toLicencer_2";
			}
		break;

		case "SeekHVIC_3":
			dialog.text = "��, � ��� �� ����� �� ���� ������?";
			link.l1 = "� ��������"+ GetSexPhrase("","�") +" ��� ������������� ����������� ����-������� ��������!";
			link.l1.go = "SeekHVIC_4";
		break;
		case "SeekHVIC_4":
			dialog.text = "��?! ��, � ��� ��� �����?";
			Link.l1.edit = 6;
			link.l1 = "";
			link.l1.go = "SeekHVIC_res";
		break;

	case "flags":
			dialog.text = "��, ��� �������� �����? ���, ����� �� ����� ����� ��������, ������� �������� � ����������� ������, ������ ������������� ����! ��� ���� ��� ����������?";
			link.l1 = "������.";
			link.l1.go = "England";
			link.l2 = "�������.";
			link.l2.go = "France";
			link.l3 = "���������.";
			link.l3.go = "Holland";
			link.l4 = "�������.";
			link.l4.go = "Spain";
			link.l5 = "� ���������. ����� �������!";
			link.l5.go = "exit";
		break;

case "England":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagEng"))
		{   
dialog.text = "���, �������� ���������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "���, �������� ���������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l1 = "������ ��� ������-��?";
		link.l1.go = "England_1";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";					
			}
		break;

case "England_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "���� ��� �� ���������� �����, �� ���� ����� ��� ��������� ����� ������ �����!";
			link.l1 = "�����-�����, ������� ���� �������.";
			link.l1.go = "England_2";
			link.l2 = "������, � �������� ��� � ��������. ����� �������!";
			link.l2.go = "exit";
			}
link.l2 = "������, � �������� ��� � ��������. ����� �������!";
link.l2.go = "exit";
		break;

	case "England_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("�� �������� �������� ������ ������!");
			SetCharacterPerk(pchar, "FlagEng");
			dialog.text = "���, ���� ������... ��� �������� ����� ������. �������� � �����������.";
			link.l1 = "�������! ����� �������!";
			link.l1.go = "exit";
		break;

case "France":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagFra"))
		{   
dialog.text = "���, �������� ����������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "���, �������� ����������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l1 = "������ ��� ������-��?";
		link.l1.go = "France_1";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";					
			}
		break;

case "France_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "���� ��� �� ���������� �����, �� ���� ����� ��� ��������� ����� ������ �����!";
			link.l1 = "�����-�����, ������� ���� �������.";
			link.l1.go = "France_2";
			link.l2 = "������, � �������� ��� � ��������. ����� �������!";
			link.l2.go = "exit";
			}
link.l2 = "������, � �������� ��� � ��������. ����� �������!";
link.l2.go = "exit";
		break;

	case "France_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("�� �������� �������� ������ �������!");
			SetCharacterPerk(pchar, "FlagFra");
			dialog.text = "���, ���� ������... ��� �������� ����� ������. �������� � �����������.";
			link.l1 = "�������! ����� �������!";
			link.l1.go = "exit";
		break;

case "Holland":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagHol"))
		{   
dialog.text = "���, �������� ����������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "���, �������� ����������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l1 = "������ ��� ������-��?";
		link.l1.go = "Holland_1";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";					
			}
		break;

case "Holland_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "���� ��� �� ���������� �����, �� ���� ����� ��� ��������� ����� ������ �����!";
			link.l1 = "�����-�����, ������� ���� �������.";
			link.l1.go = "Holland_2";
			link.l2 = "������, � �������� ��� � ��������. ����� �������!";
			link.l2.go = "exit";
			}
link.l2 = "������, � �������� ��� � ��������. ����� �������!";
link.l2.go = "exit";
		break;

	case "Holland_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("�� �������� �������� ������ ���������!");
			SetCharacterPerk(pchar, "FlagHol");
			dialog.text = "���, ���� ������... ��� �������� ����� ������. �������� � �����������.";
			link.l1 = "�������! ����� �������!";
			link.l1.go = "exit";
		break;

case "Spain":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagSpa"))
		{   
dialog.text = "���, �������� ��������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "���, �������� ��������� ������ �������� ��� � "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
		link.l1 = "������ ��� ������-��?";
		link.l1.go = "Spain_1";
		link.l2 = "������, � ���������. ����� �������!";
		link.l2.go = "exit";					
			}
		break;

case "Spain_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "���� ��� �� ���������� �����, �� ���� ����� ��� ��������� ����� ������ �����!";
			link.l1 = "�����-�����, ������� ���� �������.";
			link.l1.go = "Spain_2";
			link.l2 = "������, � �������� ��� � ��������. ����� �������!";
			link.l2.go = "exit";
			}
link.l2 = "������, � �������� ��� � ��������. ����� �������!";
link.l2.go = "exit";
		break;

	case "Spain_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("�� �������� �������� ������ �������!");
			SetCharacterPerk(pchar, "FlagSpa");
			dialog.text = "���, ���� ������... ��� �������� ����� ������. �������� � �����������.";
			link.l1 = "�������! ����� �������!";
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_1":
			NextDiag.CurrentNode = "W_officer";
			DialogExit();
		break;
	}
}