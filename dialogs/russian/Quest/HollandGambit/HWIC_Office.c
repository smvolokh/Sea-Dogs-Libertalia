// ��� ����� ����
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

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
		case "HWIC_officer":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "�������! ���� � ���������! � ������!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			if (ChangeCharacterHunterScore(Pchar, "holhunter", 0) > 12)
			{
				dialog.text = "���! �������, � ���� ����... �����! �� �������� ��� ������ �� ���������� ������! ������, �������� ���!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			chrDisableReloadToLocation = true;
			if (CheckAttribute(pchar, "questTemp.HWIC.CanTake") && !CheckAttribute(pchar, "questTemp.HWIC.CanTake.Holl") && !CheckAttribute(pchar, "questTemp.HWIC.Eng") && !CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				dialog.text = "������������. ��� ��� ������?";
				link.l1 = "� ����� �� �������� �����. ��������, ����������� ������� � ������...";
				link.l1.go = "HWIC_officer_3";
				link.l2 = "��� ������ ���������� �������� ���� ������. � ����� �� ������, �������. ���� �������� �� ������.";
				link.l2.go = "HWIC_officer_1";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				dialog.text = "������������. �� ������ ������� �� ������?";
				link.l1 = "��������, �������, � ������ � ����� �� ����. � ��� �����.";
				link.l1.go = "HWIC_officer_exit";
				link.l2 = "� ����� �� �������� �����. ��������, ����������� ������� � ������...";
				link.l2.go = "HWIC_officer_3";
				break;
			}
			dialog.text = "������������. ��� ��� ������?";
			link.l1 = "� ����� �� �������� �����. ��������, ����������� ������� � ������...";
			link.l1.go = "HWIC_officer_3";
			link.l2 = "��� ������ ���������� �������� ���� ������. � ����� �� ������, �������.";
			link.l2.go = "HWIC_officer_2";
		break;
		
		case "HWIC_officer_1":
			dialog.text = "����� ��� ������ � �������, � ������� ����������. ���������.";
			link.l1 = "�������, ��� ���.";
			link.l1.go = "HWIC_officer_exit";
			LocatorReloadEnterDisable("Villemstad_houseS3", "reload2", false);//������� �������
		break;
		
		case "HWIC_officer_2":
			dialog.text = "� ������ ������ �������� �� ��������� � ������� ��������� ���������.";
			link.l1 = "����� ����. �������� �� ������������.";
			link.l1.go = "HWIC_officer_exit";
		break;
		
		case "HWIC_officer_3":
			dialog.text = "��� � ������� ��������. ��� ���� ������ �� ���. �� ���������� ����� ������ � ��������� ����������.";
			link.l1 = "�������, ������...";
			link.l1.go = "HWIC_officer_exit";
		break;
		
		case "HWIC_officer_exit":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload3", "Villemstad_houseS3", "reload", "reload3", "", 5);
			DoQuestCheckDelay("ReturnTalkerToOfficer", 5.0); // 140313
			NextDiag.TempNode = "HWIC_officer";
		break;
		
		// �������
		case "HWIC_soldier":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "�������! ���� � ���������! � ������!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			if (ChangeCharacterHunterScore(Pchar, "holhunter", 0) > 12)
			{
				dialog.text = "���! �������, � ���� ����... �����! �� �������� ��� ������ �� ���������� ������! ������, �������� ���!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			dialog.text = "���������� � ����� �������� ��� � �������� ���������. ��� ������ ��� �������. � �� �����.";
			link.l1 = "������, � �����.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "HWIC_soldier";
		break;
		
		// ������
		case "HWIC_clerk":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "�������! ���� � ���������! �������!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			dialog.text = "���� ��� ���-�� ����� - ���������� � �������� ���������.";
			link.l1 = "������, � �����.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "HWIC_clerk";
		break;
		
		// ������� ����� - ������ �������
		case "HWIC_headclerk":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "�������! ���� � ���������! �������, �������� ���!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			if (ChangeCharacterHunterScore(Pchar, "holhunter", 0) > 12)
			{
				dialog.text = "��. ��� �������, ��� �� ��� ��� � �������... �����! �� ��������� � ������ �� �������������� ������������ ������ ���������! �������, �������� ���!";
				link.l1 = "�-���!";
				link.l1.go = "fight";
				break;
			}
			dialog.text = "�� ���-�� ������, ������?";
			if (!CheckCharacterItem(pchar, "HolTradeLicence"))
			{
				link.l1 = "� ���� ���������� �������� �������� ����� ��������.";
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
			if (CheckCharacterItem(pchar, "Cromvel_depeshe"))
			{
				link.l4 = "� ���� ���� ���� �������� ��������, ������. �������� ��� ������. ��� ���-��� ���������� ��� ���������. ���� �� ��� ������������ - �� � ��� ��� �����, ��� ������� ������ ���������� ����� �������. ��, �������, �� ���������.";
				link.l4.go = "depeshe";	
			}
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche.Garpiya") && pchar.questTemp.Caleuche.Garpiya == "gwik")
			{
				link.l4 = "� ��� �������� ������� �� ����� ���������� �������. � ���� ������ � ��������� '������'. �� ����������, ��� �� ��� ����������� � ���� ���������? � ���� � ���� ������ ����.";
				link.l4.go = "caleuche";	
			}
			link.l9 = "���, ���� ������.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "HWIC_headclerk";
		break;
		
		// �������� ��������
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� � ������ ������� ��� ������������, ��� ���� �������� ������� ����� ������, ������� � ����������� ������������ ������������ ���������� �� ���� ���� �������� ��������, � ������ - ������� ����������� �������� � ��������� �������� �������� ����� �����\n� ������ ��������� ������ ����� ���� �������� ����� ���������� ������������. ����� �� �������� ���������, ���� �� �����-�� ��������, ������� �����, �������� � �������� � ����������. ��� �������?";
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
			npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "������, ����������, �������� �����, �� ���������� � �� �������. � ��� ����� ���������. ��� �� ������� ���� ��� ����� ��������?";
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
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "���, ���� ������... ������ �������� ������� � ������... ���, ������. �������� ��� ��������.";
			link.l1 = "�������! �� ��������, ������.";
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
			if (CheckCharacterItem(pchar, "HolTradeLicence")) TakeNationLicence(HOLLAND);
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
		
		// �������
		case "caleuche":
			dialog.text = "������ ���������� ������� ��������� ���������� ��������� ����� ����-������ � ������������. ��� ��� ����� ��� �� ���� ��������. �� � ��� ���� ������������, ��� ���� �� ������� ������ ���� ���-�� �������� - �������� ���, ��� ������ ������� ��������� ��� ����� ����������. �� ������ ���� �����, ������?";
			link.l1 = "� ���� � ���� ���� ���������� ������� ������� - ������� �������� ������. ������� ������ ������ ������� �������� � ������� �� �������, ��� �����.";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "������������. � ����-����� � ����������� ������ ������� ������� �� �������������, ������, ������ �� ����� ����������� �����, � ����� ������� � ����. ��� ��� ��� ����� ����� ����� ��� ������ � ����.";
			link.l1 = "������� �� ������, ������ �������.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			DialogExit();
			pchar.questTemp.Caleuche.Garpiya = "capitan";
			pchar.questTemp.Garpiya = "to_portroyal";
			AddQuestRecord("Caleuche", "19");
			DoQuestFunctionDelay("Caleuche_CreateGarpiyaInWorld", 1.0);
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
			NextDiag.TempNode = "HWIC_Boss";
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
			NextDiag.TempNode = "HWIC_Boss";
			npchar.quest.silk_info = "true";
			npchar.quest.silk = "true";
			AddQuestRecord("Unique_Goods", "3");
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
			NextDiag.TempNode = "HWIC_Boss";
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
			NextDiag.TempNode = "HWIC_Boss";
		break;

	case "flags":
			dialog.text = "��, ��� �������� �����? �����, ��������. ��� ����� �������� �� ����� ���� ����� ������ �����, ����� ������� ����� ���������������� �������� � ���� ������ �������. ���� ������ ����������� ��� ����������?";
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

		case "fight":
			DialogExit();
			sld = characterFromId("HWIC_officer");
			LAi_SetGuardianTypeNoGroup(sld);
			LAi_group_Attack(sld, Pchar);
			for (i=1; i<=6; i++)
			{	
				sld = characterFromId("HWIC_sold_"+i);
				LAi_group_Attack(sld, Pchar);
			}
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}