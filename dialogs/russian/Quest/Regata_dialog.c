void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, n, iTemp;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	bool ok;
    int iTest;
    ref rColony;
    string sFrom_sea = "";
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "exit";
		break;
		
		//��������
		case "Regata_Cureer":
			dialog.text = "������ ����. �� - ������� " + GetFullName(pchar) + "?";
			link.l1 = "��, ��� �. � � ��� ����?";
			link.l1.go = "Regata_Cureer_1";
		break;
		
		case "Regata_Cureer_1":
			dialog.text = "� ���� ��� ��� ������ �� ����������� ������, ���� ������� �����.";
			link.l1 = "���! �� ������... � ��� �� ���������� ����� �� ����?";
			link.l1.go = "Regata_Cureer_2";
		break;
		
		case "Regata_Cureer_2":
			dialog.text = "�������� ������, ���. �� ������� - ��� ���������� ������� ������� � ������, ������ �� �����, �� ����������. ����� � ����� ������������ � �������� ������������ � ���� �� �������� ��� ��������.";
			link.l1 = "�����������! �� ��� ��... ������ � �������.";
			link.l1.go = "Regata_Cureer_3";
			GiveItem2Character(pchar, "letter_open");
			ChangeItemDescribe("letter_open", "itmdescr_letter_open_Regata");
			AddQuestRecordInfo("RegataLetter", "1");
		break;
		
		case "Regata_Cureer_3":
			if (Pchar.BaseNation == SPAIN || Pchar.BaseNation == HOLLAND)
			{
				dialog.text = "����� � ������ ���������� ��� ����������������� ���� � ���� ����-����� ��� �������� �� ������. ��� ����� � ����������� ������ ��� �������� ������ �� 30 ����. �� ���� ��� ������ ���������. �� ��������, �������!";
				link.l1 = "�������, �������� - ��� ������ ������. �� ��������!";
				link.l1.go = "Cureer_exit";
				GiveNationLicence(HOLLAND, 30);
			}
			else
			{
				dialog.text = "������. �� ���� ��� ������ ���������. �� ��������, �������!";
				link.l1 = "�� ��������!";
				link.l1.go = "Cureer_exit";
			}
		break;
		
		case "Cureer_exit":
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			pchar.questTemp.Regata.ToPortRoyal = "true";
			SetFunctionTimerCondition("RegataToPortRoyalTimeOver", 0, 0, 31, false);
		break;
		
		//������������� ������
		case "Regata_Head":
			if (CheckAttribute(pchar, "questTemp.Regata.Begin"))
			{
				dialog.text = "������ ����. �� ���������� � ������, ��� � �������?";
				link.l1 = "������ ���, ���. ��� ��� - " + GetFullName(pchar) + ". � ������� �����������.";
				link.l1.go = "Regata_Head_1";
			}
			else
			{
				dialog.text = "�� ���-�� ������, ���?";
				link.l1 = "�� ���, ������. � ��� �����.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Regata_Head";
			}
		break;
		
		case "Regata_Head_1":
			iTest = FindColony("PortRoyal"); 
			if (iTest != -1)
			{
				rColony = GetColonyByIndex(iTest);
			}
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
			{
				dialog.text = "��� �������������, ������� " + GetFullName(pchar) + ". ����, ���������. ������ ������� ��� ������ ���� ���� �������� �� ������, ���? ������ �������� ������ �� �������� ���� '������' � ������ ���� � �������. �� ��������� ��� ����������?";
				if ((GetCompanionQuantity(pchar) > 1) || sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LUGGER)
				{
					link.l1 = "��� �� ����� ������ ����������� ������������. ������ �� ������ ��� � ������� � ���.";
					link.l1.go = "exit";
					NextDiag.TempNode = "Regata_Head_repeat";
				}
				else
				{
					link.l1 = "��, ��� �����.";
					link.l1.go = "Regata_Head_2";
				}
			}
			else
			{
				dialog.text = "�� ������� �� ������ - � ������� ��� ���? � �� ������� ������� �������� � ����� ����� �� ��������� ����������.";
				link.l1 = "����� ��������, ���. � ���������� ������� ���� ������� � ����.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Regata_Head_repeat";
			}
		break;
		
		case "Regata_Head_repeat":
			if (CheckAttribute(pchar, "questTemp.Regata.Begin"))
			{
				iTest = FindColony("PortRoyal"); 
				if (iTest != -1)
				{
					rColony = GetColonyByIndex(iTest);
				}
				ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
				if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
				{
					dialog.text = "�, ��� ����� ��. ��, �� ��� ������� ��� ���������� �������?";
					if ((GetCompanionQuantity(pchar) > 1) || sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LUGGER)
					{
						link.l1 = "��� �� �����. ������ �� ������ ��� � ������� � ���.";
						link.l1.go = "exit";
						NextDiag.TempNode = "Regata_Head_repeat";
					}
					else
					{
						link.l1 = "��, ��� �����.";
						link.l1.go = "Regata_Head_2";
					}
				}
				else
				{
					dialog.text = "�������, ���� � �� ����� ���� ����� �� �����, ��� ������������� �� � ���. �� ��� ������ �������, ��� ��� ��� ��� ���������?";
					link.l1 = "����� ��������, ���. � ���������� ������� ���� ������� � ����.";
					link.l1.go = "exit";
					NextDiag.TempNode = "Regata_Head_repeat";
				}
			}
			else
			{
				dialog.text = "�� ���-�� ������, ���?";
				link.l1 = "�� ���, ������. � ��� �����.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Regata_Head";
			}
		break;
		
		case "Regata_Head_2":
			dialog.text = "�������. ������ �����. ��� ���������� ��� �������?";
			link.l1 = "'"+pchar.Ship.Name+"'.";
			link.l1.go = "Regata_Head_3";
		break;
		
		case "Regata_Head_3":
			dialog.text = "��������� ������ ������������ ����������� ��������, � ����� �������� ����������� ������, �� ����� ������ ��� ������ ������� ��������. �� ���������, ��� �������� ���� ����������.";
			link.l1 = "������ ��� ������� - ������ �������, �������.";
			link.l1.go = "Regata_Head_4";
		break;
		
		case "Regata_Head_4":
			dialog.text = "����� ������ ������� ��� �������. ����, ��� ������ ������ ����� ������ ��� '�a���-K��ep���'. ������������� � ���������� ����� �������� ������ �������.";
			link.l1 = "� ��� �����, ���, ������.";
			link.l1.go = "Regata_Head_5";
			pchar.Ship.Name = "�a���-K��ep���";
		break;
		
		case "Regata_Head_5":
			dialog.text = "������ ������� ��������� � ������. �������� �����������, ��� � ��� ��������. ����� � ��� ��� ������ � ���������, ����� �� �� ������. ����\n������ ��������, ���������� � ����-����� � ������������� � ����-�����. �� ���� ��� ������� ���� ���������\n������: ����-����� - �����, ��� �� �������� �����\n������: ����� - ����-�-�����, ��� �� ���������\n������: ����-�-����� - ����-�����, ��� �� �������\n���������: ����-����� - ���������, ��� �� ���������\n�����, ����� ��������������� - ��������� - ����-�����\n� ������� ��������?";
			link.l1 = "������, ���.";
			link.l1.go = "Regata_Head_6";
		break;
		
		case "Regata_Head_6":
			dialog.text = "������������. � ������ �� ��������� ���� ������������� ������� - �����, ����-�-�����, ����-����� � ���������, �� ������ ���������� � �������� ���������� - ���������� ������ �������� ������������ ������. ���� �� �� ���������� ���� �� � ����� �� �������, ��� �������� ������������������ - ��� ����������������\n���� �� ��������� ����� - �� ������������, �� ����� ������ ����� ����������� �������������� ��������� � �������� ����������� - ������ ��������� � ��������� � ����� - ��� �������.";
			link.l1 = "��� ���� �������.";
			link.l1.go = "Regata_Head_7";
		break;
		
		case "Regata_Head_7":
			dialog.text = "������ ������� � ��������� ������� � ������� ���������. ��� ����� ����������� � ������ ������������� ������, ������.";
			link.l1 = "����. ��� ������������ ����������, � ������ �������?";
			link.l1.go = "Regata_Head_8";
		break;
		
		case "Regata_Head_8":
			dialog.text = "���������� � ������ ������ ���� - �������, ��� ������� �������� � ����-����� ������. ������� ������ ��������. ���������� �������� ������� �������� ����� - 250 000 ����. ����� ��� ����� ������ �������� ������ ������.";
			link.l1 = "�� ����, ����������� �� ��������� ������?";
			link.l1.go = "Regata_Head_9";
		break;
		
		case "Regata_Head_9":
			dialog.text = "���������� �����. �������: ������ �������, � �� ����� ������� ������ ���������� ������� ������ ������ �� ���������� ������. ��� ���, �� ���� ������ ������� ������... �� ���� ������, ��������. ������ ��� �������� ��� ������. � ������ ����� ������ �������� ���� ����������, � � ��� ����� �������������� ������. ������ �������� �\n������ ������ ������ �� ���� ������ � ������?";
			link.l1 = "��! �������, ����. ������� ����� �������?";
			link.l1.go = "Regata_rate";
			link.l2 = "� �������. �����, � ��������.";
			link.l2.go = "Regata_Head_10";
		break;
		
		case "Regata_Head_10":
			if (CheckAttribute(pchar, "questTemp.Regata.Begin"))
			{
				dialog.text = "�������. �� ������ ������ �� ������ ������ �� ��� � ������� ������.";
				link.l1 = "������. ����� ����� ������?";
				link.l1.go = "Regata_Head_11";
				DeleteAttribute(pchar, "questTemp.Regata.Rate");
				pchar.questTemp.Regata.Ratenext = "true";
			}
			else
			{
				dialog.text = "�������. �� ������ ������ �� ������ ������ �� ��� � ������� ������.";
				link.l1 = "������.";
				link.l1.go = "exit";
			}
		break;
		
		case "Regata_Head_11":
			CreateRegataAdversaries();
			dialog.text = "����� 3 ���, � 12 �����. �� ������ ���� �� �����. � ��� ����� ���� �����������\n"+pchar.questTemp.Regata.AdversaryName.a+", �� ������� '"+pchar.questTemp.Regata.AdversaryShipName.a+"'\n"+pchar.questTemp.Regata.AdversaryName.b+", �� ������� '"+pchar.questTemp.Regata.AdversaryShipName.b+"'\n"+pchar.questTemp.Regata.AdversaryName.c+", �� ������� '"+pchar.questTemp.Regata.AdversaryShipName.c+"'\n"+pchar.questTemp.Regata.AdversaryName.d+", �� ������� '"+pchar.questTemp.Regata.AdversaryShipName.d+"'\n"+pchar.questTemp.Regata.AdversaryName.e+", �� ������� '"+pchar.questTemp.Regata.AdversaryShipName.e+"'\n��� ������ ������� ��������. ���, ����� � ���. �������� ��� ������, � ��� �������� ��� �������, ����� �� �� ������ ����. � ������ - �� ������� �� ������!";
			link.l1 = "�� ��������, ���.";
			if (Pchar.BaseNation == SPAIN || Pchar.BaseNation == HOLLAND) link.l1.go = "Regata_Head_13";
			else link.l1.go = "Regata_Head_12";
		break;
		
		case "Regata_Head_12":
			DialogExit();
			pchar.quest.RegataToPortRoyalTimeOver.over = "yes";//����� ������
			SetFunctionTimerCondition("Regata_SetTime", 0, 0, 3, false);
			pchar.quest.Regata_Lost.win_condition.l1 = "Timer";
			pchar.quest.Regata_Lost.win_condition.l1.date.hour  = 13.0;
			pchar.quest.Regata_Lost.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 3);
			pchar.quest.Regata_Lost.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			pchar.quest.Regata_Lost.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 3);
			pchar.quest.Regata_Lost.function = "Regata_Lost";
			pchar.quest.Regata_Start.win_condition.l1 = "Timer";
			pchar.quest.Regata_Start.win_condition.l1.date.hour  = 12.0;
			pchar.quest.Regata_Start.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 3);
			pchar.quest.Regata_Start.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			pchar.quest.Regata_Start.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 3);
			pchar.quest.Regata_Start.win_condition.l2 = "locator";
			pchar.quest.Regata_Start.win_condition.l2.location = "Portroyal_town";
			pchar.quest.Regata_Start.win_condition.l2.locator_group = "reload";
			pchar.quest.Regata_Start.win_condition.l2.locator = "reload1_back";
			pchar.quest.Regata_Start.function = "Regata_Start";
			AddQuestRecordInfo("RegataRules", "1");
			NextDiag.CurrentNode = "Regata_Prepare";
			DeleteAttribute(pchar, "questTemp.Regata.Begin");
			pchar.questTemp.Regata.Prepare = "true";
		break;
		
		case "Regata_Head_13":
			dialog.text = "���������! ��� ���������� ��������� ���������� � ����������� ������ � ����� ��� �������� ������ �� 30 ���� - ������ �� ��������� ������ ������. ����������, ��������.";
			link.l1 = "�������!";
			link.l1.go = "Regata_Head_12";
			GiveNationLicence(HOLLAND, 30);
		break;
		
		case "Regata_rate":
			dialog.text = "������� �� ������ ���������?";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "Regata_rate_1";
			link.l2 = "�������, ��� ��� ���� ��������.";
			link.l2.go = "Regata_Head_10";
		break;
		
		case "Regata_rate_1":
			int iQty = sti(dialogEditStrings[4]);
			pchar.questTemp.Regata.Rate = sti(iQty);
			if (iQty < 10000)
			{
				dialog.text = "���, �� �������. �� ��� �� ����������? � ���� �� ���� �������� � ����� ��������� ������.";
				link.l1 = "����� ��������... ������� ����������� ������ ������.";
				link.l1.go = "Regata_rate";
				break;
			}
			if (iQty > 100000)
			{
				dialog.text = "���, ������� �� ��������� ��� ��������� ����� ������. ��������� �� ������ �� �������� ��������.";
				link.l1 = "����... ������� ����������� �����.";
				link.l1.go = "Regata_rate";
				break;
			}
			dialog.text = ""+iQty+"? ������� ������. � ����� �� �������. ���� ������, ���?";
			if (makeint(Pchar.money) >= sti(pchar.questTemp.Regata.Rate))
			{
				link.l1 = "����������, ��������.";
				link.l1.go = "Regata_rate_2";
			}
			link.l2 = "� ���� ������ ������������ �����. � ����� ����� � ������ ������. � ��� �������, �����, ������� �����.";
			link.l2.go = "Regata_Head_10";
		break;
		
		case "Regata_rate_2":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Regata.Rate));
			pchar.questTemp.Regata.Advantage = sti(pchar.questTemp.Regata.Rate)*(1.5+frand(1.5)); // dlc
			dialog.text = "�������! ������ ��� ����� ������ ������ - � ������� ���. ��� ������ ����� ���� ������ - � ����������� �� ����, ������� ����� �������� �� ���.";
			if (!CheckAttribute(pchar, "questTemp.Regata.Ratenext"))
			{
				link.l1 = "�������. ����� ����� ������?";
				link.l1.go = "Regata_Head_11";
			}
			else
			{
				link.l1 = "�������. ��� ������. �� ��������!";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Regata.Ratenext");
				NextDiag.TempNode = "Regata_Prepare";
			}
		break;
		
		case "Regata_Prepare":
			dialog.text = "�, ��� ����� ��, ������� " + GetFullName(pchar) + "? �� ������ ������� ����������?";
			if (!CheckAttribute(pchar, "questTemp.Regata.Rate"))
			{
				link.l1 = "� ���� ������� ������ �� ���� ������.";
				link.l1.go = "Regata_rate";
			}
			link.l2 = "�� ���, ������ ����������, ������ ����� ���������������� ���.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Regata_Prepare";
		break;
		
		//����� ������
		case "Regata_CitMan":
			dialog.text = RandPhraseSimple(LinkRandPhrase("�������, �� ������ ��� ���������� � ������? ��� ��� � ��� �����: ������ ���������. ��������� ����� ������������ ��� ���������� �������...","�������, � �������� �� ���. �� ����������� ����!","�������, � ������ ���������� ������ ������ ����� ���������� ������ � ��� ���-������. ��� ����� ����������� ��������. ������ ��� � ����."), LinkRandPhrase("����������� ��������, �������!","�������, ���������� ������������: � ��������� �������� ��������� ��������� ����� ����� �� ������� ���������� ������.","� ������, ��� � ������� ���������� ������ ������ �������� ���������� ��������� ������ ���� '������'. ��������������� ���, ��� ��� - ����, �������, ����."));
			link.l1 = "��-��, �������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_CitMan";
		break;
		
		case "Regata_CitWom":
			dialog.text = LinkRandPhrase("�������, �� � ����� ��������� �� ��� ������ �����. �� ��������� ���!","�������! ����� ��� �����!","��, �� ����� ��������, � ����� ������������, �������...");
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_CitWom";
		break;
		
		case "Regata_CitHorse":
			dialog.text = LinkRandPhrase("���, �������! ������ �������� �� ��������! � ���� ���, ����� ���������!","��-�-�, �����, ������� �������! ����� �������, ��� ������ ���� ���������� ������ �� ������ ���������... ���������� ��������, �� ����� �������!","����� ���������, ���������, �� ������ ��������� � ��� - �������� �� ������� �������!");
			link.l1 = "������, ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_CitHorse";
		break;
		
		case "Regata_Prepare_1":
			if (sti(environment.time) < 12.0)
			{
				dialog.text = "�������, ������ �������� � 12 �����. ������ ���� �������� - �� ������� ������������� �����. ��������� � ������� - ���� ��������� ���� �������� � ����� �������.";
				link.l1 = "� � ��� ������� ��������� ������������, ���! ��� ������...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "��� � ��, �������. ��������� ����� �� ����� � �������� ���������� ������ ������.";
				link.l1 = "� � ��� ������� ��������� ������������, ���! ��� ������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Regata_Prepare_1";
		break;
		
		case "Regata_Start":
			dialog.text = "����, �����������, �� ��� ���������. � �������� �������� ������ ��������. ������� �� ������. ��������� ���, ��� ������� �������� � ����-����� ������. ���� � �������, �������� ����� �������� ��������� �����!\n�����������! �� ������? �� �����! ��������! ����!!";
			link.l1 = "...";
			link.l1.go = "Regata_Start_1";
		break;
		
		case "Regata_Start_1":
			DialogExit();
			PlaySound("people fight\mushketshot.wav");
			log_info("������ ����������! �� �������! ���� - �� �����!");
			for (i=1; i <=5; i++)
			{
				sld = characterFromId("Regata_Cap_F"+i);
				LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
			}
			Island_SetReloadEnableGlobal("Jamaica", false);//�� ������ ������
			SetFunctionTimerCondition("ReturnJamaicaNorm", 0, 0, 1, false);//������ �� ������� �����
			LocatorReloadEnterDisable("Portroyal_town", "reload1_back", false);//������� ����� � ����
			DeleteAttribute(pchar, "questTemp.Regata.Prepare");
			pchar.questTemp.Regata.Go = "true";
			pchar.questTemp.Regata.Town = "Beliz";
			pchar.quest.Regata_PU.win_condition.l1 = "locator";
			pchar.quest.Regata_PU.win_condition.l1.location = "Beliz_town";
			pchar.quest.Regata_PU.win_condition.l1.locator_group = "reload";
			pchar.quest.Regata_PU.win_condition.l1.locator = "reload10_back";
			pchar.quest.Regata_PU.win_condition.l2 = "Night";
			pchar.quest.Regata_PU.function = "RegataPU_Open";//���� � �� �����
			//��������
			pchar.quest.Regata_ShYarder.win_condition.l1 = "location";
			pchar.quest.Regata_ShYarder.win_condition.l1.location = "Beliz_town";
			pchar.quest.Regata_ShYarder.function = "RegataShipyarder";
			sld = characterFromId("Beliz_shipyarder");
			LAi_RemoveLoginTime(sld);
		break;
		//����� ������
		
		//������� � ��������
		case "Regata_Shipyarder":
			dialog.text = "������������, �������! ��� ��� ��������, �� ���������� ������� � ��������� ������...";
			link.l1 = "��, ��� ���. ������� �� ����������, � ������, ���������� ������� �����.";
			link.l1.go = "Regata_Shipyarder_1";
		break;
		
		case "Regata_Shipyarder_1":
			dialog.text = "��� �����, �� �����, �������. � ���� ��� ��� ���� �����������, ��������� � ������� � ����� ��������.";
			link.l1 = "���! ���������. ������ ��� �����������, ������.";
			link.l1.go = "Regata_Shipyarder_2";
		break;
		
		case "Regata_Shipyarder_2":
			dialog.text = "������ ���������� �� ��������, ���. � � ���� ��� ��� ���� �������� ������� �� ������ �� ������ ������ �������� ��������. ��� ������ �������� ��������� ����� �������� ����� �������� � ����� ������������ ����� ������ ����������� �� �������\n� ����� ��� �� �������, ���� ��, �������, ������� ������.";
			link.l1 = "������� �� ������ �� ��� ������?";
			link.l1.go = "Regata_Shipyarder_3";
		break;
		
		case "Regata_Shipyarder_3":
			dialog.text = "����� ���� 15 000 ����. �����������, ��� ��������� ���� ��� ����� ����, �� ��� � ����� ��������.";
			if (makeint(Pchar.money) >= 15000)
			{
				link.l1 = "��������! � ������� � ��� ����� ������ �� ���� ������. ��� ������. ������ ������� ��������� �� �� ��� �������, ���� � ��� ���������� � �������� ����������.";
				link.l1.go = "Regata_Shipyarder_4";
			}
			link.l2 = "��� � ���� ����� �����. ��� ��� ������ ���� ������ �� ���������.";
			link.l2.go = "Regata_Shipyarder_exit";
		break;
		
		case "Regata_Shipyarder_4":
			AddMoneyToCharacter(pchar, -15000);
			dialog.text = "����� �������, ���! �� �� ��������� � ����� ������������. ����� ����, ��� ������ ��������� � ������������� ������� ���� - ��� ������ ����� ���������� ����� �������.";
			link.l1 = "��� � ������! ��, � �����������, � �� ��������� ��������.";
			link.l1.go = "Shipyarder_exit";
			for (i=1; i <=5; i++)
			{
				if (i==1) sTemp = "a";
				if (i==2) sTemp = "b";
				if (i==3) sTemp = "c";
				if (i==4) sTemp = "d";
				if (i==5) sTemp = "e";
				pchar.questTemp.Regata.AdversarySecondTransition.Time.(sTemp) = sti(pchar.questTemp.Regata.AdversarySecondTransition.Time.(sTemp))+12;//������� 12 ����� � ����
				log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversarySecondTransition.Time.(sTemp)));
			}
			RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails = 3;
			SetSailsColor(Pchar, 5);
		break;
		
		case "Regata_Shipyarder_exit":
			dialog.text = "����, ����� ����. ��, ������ - �����. �� ��������, �������.";
			link.l1 = "����� �������!";
			link.l1.go = "Shipyarder_exit";
			pchar.questTemp.Regata.AdversarySecondTransition.Time.d = sti(pchar.questTemp.Regata.AdversarySecondTransition.Time.d)-16;//��������� �������� ������� 16 �����
			log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversarySecondTransition.Time.e));
		break;
		
		case "Shipyarder_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload5_back", "Beliz_Shipyard", "sit", "sit1", "ReturnRegataSYNorm", 5);
		break;
		//������� � ��������
		
		//�������� � �������
		case "Regata_Contra":
			dialog.text = "������������, ������� " + GetFullName(pchar) + ". � ��� � ��� ���� ��������... ������, ������� �����������.";
			link.l1 = "��. ���������, � ������ �� ���� ������?";
			link.l1.go = "Regata_Contra_1";
		break;
		
		case "Regata_Contra_1":
			dialog.text = "�������, �� ��� �� ����� ��������. ���� ������, �� �� �������� - ��� ��� �� ����� ���!";
			link.l1 = "�������. ��, ������������, ��� ��� � ���.";
			link.l1.go = "Regata_Contra_2";
		break;
		
		case "Regata_Contra_2":
			if (sti(pchar.questTemp.Regata.Index != 1))
			{
				sTemp = pchar.questTemp.Regata.ContraIndex;
				dialog.text = "��� ��������, ��� ����� ���� ��������� ��� ���� �������� ������ - "+pchar.questTemp.Regata.AdversaryName.(sTemp)+" �� ������� "+pchar.questTemp.Regata.AdversaryShipName.(sTemp)+". �� ����� �� ����� ������ �������, � ����� ����� ��������� ���� ����� ������.";
			}
			else
			{
				dialog.text = "��� ��������, ��� �� ���� ��������� �� ����� ���� ��� ���� �������� ������ - "+pchar.questTemp.Regata.AdversaryName.b+" �� ������� "+pchar.questTemp.Regata.AdversaryShipName.b+". �� � ���� �� ��� ������ � ����.";
			}
			link.l1 = "�� ������ �����������.";
			link.l1.go = "Regata_Contra_3";
		break;
		
		case "Regata_Contra_3":
			if (sti(pchar.questTemp.Regata.Index != 1)) sTemp = "� �� ��� �������� �������� ��� � ������� ��� �����";
			else sTemp = "� �� ��� �������� ������ ������ ������";
			dialog.text = "����������. ������ � ���� ����. �� ���������� ��� ������ �� ���������� ������. ���� � �������� ������, �� ����� �� ������ ������� � ���������� �� ���� �� ������ ������ ������ ������. ����� ������� ������ ����� ������� ���� ���\n����� �������� ����������. ���� �� � ���� �����������, �� ����������� ����� ������� � ������, � ��� ����������� ������� ��������� ������ ������ ��������� � ������ ������. �� �������� ����� �� �������, "+sTemp+".";
			link.l1 = "������� �� ������ �� ��� ������?";
			link.l1.go = "Regata_Contra_4";
			link.l2 = "���. � �� ������� ��������� ��� ������ �������� ������. �� �� �� ���� ���� �������. ����� �������, �����������.";
			link.l2.go = "Regata_Contra_exit";
		break;
		
		case "Regata_Contra_exit":
			dialog.text = "��, �������, ��� ������. ��������.";
			link.l1 = "�� ��������� ��� ��� �������. ���� ��������� �� ���� ��������!";
			link.l1.go = "Contra_exit";
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
		break;
		
		case "Regata_Contra_4":
			if (sti(pchar.questTemp.Regata.Index != 1)) iTemp = 50000;
			else iTemp = 30000;
			dialog.text = "�� ����� �������. ����� "+iTemp+" ����. � ��� �������� �������� ��� ������� ��� ��� ����� �����... ��������, ��-��!";
			if (makeint(Pchar.money) >= iTemp)
			{
				link.l1 = "���! �� �������� ����, �����������! � ����� ��������� ���. �� ����� ��������, ��� �� �������� ������? � ��� ��� ������� �� �����������, ����� � ��� ��������� ����?";
				link.l1.go = "Regata_Contra_5";
			}
			link.l2 = "��� � ���� ����� �����. ��� ��� ������� ����� ��������������� �� ��������.";
			link.l2.go = "Regata_Contra_exit";
		break;
		
		case "Regata_Contra_5":
			dialog.text = "�������, �� ��������������, � �� �����-������ �������. �� - ���� �������... � ����� ����. ��� �� ������� ������ �������� �� ������������ � �� ������, ��� �� �� ����������? ��� ��� �����. ������ ���� �������.";
			link.l1 = "������, ��� ���� ������.";
			link.l1.go = "Regata_Contra_6";
		break;
		
		case "Regata_Contra_6":
			ChangeCharacterComplexReputation(pchar, "nobility", -3);
			dialog.text = "�� ���������� �������� ���� �������, �������. ��, � �� ������ ����� ������, � ��� �������� ��� �� ����� ������ ������� ��������� ��������. �����!";
			link.l1 = "� ��� ���� ��...";
			link.l1.go = "Contra_exit";
			if (sti(pchar.questTemp.Regata.Index != 1))
			{
				AddMoneyToCharacter(pchar, -50000);
				sTemp = pchar.questTemp.Regata.ContraIndex;
				pchar.questTemp.Regata.AdversaryThirdTransition.Time.(sTemp) = sti(pchar.questTemp.Regata.AdversaryThirdTransition.Time.(sTemp))+48;//�������� �� 48 �����
				log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversaryThirdTransition.Time.(sTemp)));
			}
			else
			{
				AddMoneyToCharacter(pchar, -30000);
				pchar.questTemp.Regata.AdversaryThirdTransition.Time.b = sti(pchar.questTemp.Regata.AdversaryThirdTransition.Time.b)+36;//�������� �� 36 �����
				log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversaryThirdTransition.Time.b));
			}
		break;
		
		case "Contra_exit":
			DialogExit();
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("RegataContra_"+i);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "quest", "quest2", "none", "", "", "", 10.0);
			}
		break;
		//�������� � �������
		
		//�����
		case "Regata_Padre":
			pchar.questTemp.Regata.BranderName = GenerateRandomNameToShip(ENGLAND);
			dialog.text = "����������, ��� ���. � ������ ���������������� ����, � ����� �������� ��������: �� ������� �� ��, ��� ������ ����� ������ � ������� ������, ������ ��������� ����� � ���������� ����� ����� ������?";
			link.l1 = "�����, ���� ������ ������������� �� ���� ����� ����, � �� �� �����������. � ���� ����������� ����� �����������, ��� ��� �� ���������� ������, ��� ��� ������� ��������� � ������ - ������, ��� ����� ��������...";
			link.l1.go = "Regata_Padre_exit";
			link.l2 = "�������, ������ ����. ����� ����� ������������� ����� �����������?";
			link.l2.go = "Regata_Padre_1";
		break;
		
		case "Regata_Padre_1":
			dialog.text = "������� ��������� ���� ���� ������� � ���� �����������, ��� ���. ��� ������ ����� ��� ���� ��������� �������� �����.";
			Link.l1.edit = 4;			
			link.l1 = "";
			link.l1.go = "Regata_Padre_2";
		break;
		
		case "Regata_Padre_2":
			iTemp = sti(dialogEditStrings[4]);
			if (iTemp <= 0 || sti(pchar.money) < iTemp)
			{
				dialog.text = "�������� ��� ���������, ��� ���. ��� �� ������ - �� ������� � ���� � � ���, ��� ���� �������� ��������� ����� ����������... �, ��������, ����� �����.";
				link.l1 = "� �� �������� � ������������, ������ ����. �� ��������.";
				link.l1.go = "Padre_exit";
				ChangeCharacterComplexReputation(pchar, "nobility", -3);
				break;
			}
			if (iTemp > 0 && iTemp <= 1000)//������ �� ������
			{
				dialog.text = "�� ���� ������ ������� ��������� ���� �� ���� �������� ���.";
				link.l1 = "�� �� ���, ������ ����.";
				link.l1.go = "Padre_exit";
				AddMoneyToCharacter(pchar, -iTemp);
			}
			if (iTemp > 1000 && iTemp <= 5000)//1 ��������� - ��������
			{
				dialog.text = "�� ���� ������ ������� ��������� ���� �� ���� ���. � � ������������� � ���� ������������ ����, ��� ���: ��������� ���� ������� ������ ���� ��������. ���� ��������� � ����!";
				link.l1 = "�����, ������ ���� ��������� ���������� ���-�� ��������... ������ ������� ��� �� ���� ������������ � ���� ������.";
				link.l1.go = "Padre_exit";
				AddMoneyToCharacter(pchar, -iTemp);
			}
			if (iTemp > 5000 && iTemp <= 10000)//2 ��������� - ������
			{
				dialog.text = "�� ���� ������ ������� ��������� ���� �� ���� ���. � � ������������� � ���� ������������ ����, ��� ���: ��������� ���� ������� ������ ���� ��������. � ������, ��� ��� ������� �������������� �������������� �������� ���� ������� ��� ������ �� ������ �����\n��� ��� ��������� ����� � ��������� ���� ���������. ���� ���������, ��� ���, ��� ��������� ���� �� ������ - ������� ������� ���������. ������ � ���� ��������������!";
				link.l1 = "�������, ������ ����. � ���� ����������.";
				link.l1.go = "Padre_exit";
				AddMoneyToCharacter(pchar, -iTemp);
			}
			if (iTemp > 10000)//3 ��������� - ��������� ���������
			{
				dialog.text = "�� ����� ����, ��� ���. ����������, ���������� ������ ������� ������, �� ��������� ��� ������� ��� �����, ������� �� ����� ������������ ���� ����� ������. � ������ ������ 10 000 ����\n� � ������������� � ���� ������������ ����, ��� ���: ��������� ���� ������� ������ ���� ��������. � ������, ��� ��� ������� �������������� �������������� �������� ���� ������� ��� ������ �� ������ �����\n��� ��������� ������, ��� ��������� '"+pchar.questTemp.Regata.BranderName+"', � ������������ ��������� ����, ��� ���������� ������, ����� �� �� �����, ��� � ����. ���� ���������, ��� ���, ��� ��������� ���� �� ������ - ������� ������� ���������\n�������� �� - � ������� �������� ���� ���� ����. ������ � ���� ��������������! � ���� �������� �� ����, ��� ���.";
				link.l1 = "�������, ������ ����. � ���� ����������. ���� ��� �������� ��������� - � �������� �� �������� � ��!";
				link.l1.go = "Padre_exit";
				AddMoneyToCharacter(pchar, -10000);
				ChangeCharacterComplexReputation(pchar, "nobility", 2);
			}
		break;
		
		case "Regata_Padre_exit":
			dialog.text = "�� ��������, ��� ���. ���� - ��� ����. ���� �� �� ������� ������������ �� ����� ������ - �� ��� ���� ������� � ���� �����. ������ � �����, ��� ���.";
			link.l1 = "����� �������, ������ ����.";
			link.l1.go = "Padre_exit";
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
		break;
		
		case "Padre_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload7_back", "SentJons_church", "barmen", "stay", "ReturnRegataPadreNorm", 5);
		break;
		
		case "Regata_Spyglass":
			dialog.text = "������������, �������! ���� ����� " + npchar.name + ", � � �� ������...";
			link.l1 = "...���������� ��� ���-���... ���������, �������?";
			link.l1.go = "Regata_Spyglass_1";
		break;
		
		case "Regata_Spyglass_1":
			dialog.text = "�� ������� ��, �������! � ���� �� �����������? �� - ����� ������, ���������� � ������ - �������, ��� ����� ��� ���-������ �������, ����������� � ������� ����.";
			link.l1 = "�����, ���������, ���������. ��� ��� � ����?";
			link.l1.go = "Regata_Spyglass_2";
		break;
		
		case "Regata_Spyglass_2":
			if(drand(11) > 10)//�������� �����
			{
				pchar.questTemp.Regata.Spy = "spyglass4";
				sTemp = "�������� ��������� �����";
				pchar.questTemp.Regata.SpyPrice = 20000;
				pchar.questTemp.Regata.SpyIndex = 12;//������� - 12 �����
			}
			else
			{
				if(drand(11) < 6)//������� �����
				{
					pchar.questTemp.Regata.Spy = "spyglass2";
					sTemp = "������� ��������� �����";
					pchar.questTemp.Regata.SpyPrice = 1800;
					pchar.questTemp.Regata.SpyIndex = 4;//������� - 4 ����
				}
				else//������� ����� - ��� ����������
				{
					pchar.questTemp.Regata.Spy = "spyglass3";
					sTemp = "������� ��������� �����";
					pchar.questTemp.Regata.SpyPrice = 10000;
					pchar.questTemp.Regata.SpyIndex = 8;//������� - 8 �����
				}
			}
			dialog.text = "���, ����������. ��� ��� ��������� �� ����, �� ���� ��� �������, ��� � ��. ��� ��� �� �����, � ��� ����� �����������. � ����� � �� ��� ����� ���� "+FindRussianMoneyString(sti(pchar.questTemp.Regata.SpyPrice))+".";
			if (sti(pchar.money) >= sti(pchar.questTemp.Regata.SpyPrice))
			{
				link.l1 = "���-���... "+sTemp+"! ����� ���������. �������, � ����� �� � ���. � ��� �����, � �� ���� �������� �����. �� ������ �� ��� "+FindRussianMoneyString(sti(pchar.questTemp.Regata.SpyPrice))+"? ����������, ��������.";
				link.l1.go = "Regata_Spyglass_3";
			}
			link.l2 = "��... "+sTemp+"? ���, �������, ��������, �� ��� ��� ���� �� �����. � ���� ��� ���� ��������� �����, � ������ ��������. ��� ���... ���!";
			link.l2.go = "Regata_Spyglass_exit";
		break;
		
		case "Regata_Spyglass_3":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Regata.SpyPrice));
			GiveItem2Character(pchar, pchar.questTemp.Regata.Spy);
			dialog.text = "��������� ���, �������. �������, ��� ���� ��� ������ ��������. ����, ��� ��� ��������� ��� ��������. ����� � ������!";
			link.l1 = "�������, " + npchar.name + "! �� ��������.";
			link.l1.go = "Spyglass_exit";
			for (i=1; i <=5; i++)
			{
				if (i==1) sTemp = "a";
				if (i==2) sTemp = "b";
				if (i==3) sTemp = "c";
				if (i==4) sTemp = "d";
				if (i==5) sTemp = "e";
				pchar.questTemp.Regata.AdversaryFourthTransition.Time.(sTemp) = sti(pchar.questTemp.Regata.AdversaryFourthTransition.Time.(sTemp))+sti(pchar.questTemp.Regata.SpyIndex);//����� ����� - ������� �����
				log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversaryFourthTransition.Time.(sTemp)));
			}
		break;
		
		case "Regata_Spyglass_exit":
			dialog.text = "����, ����� ����, �������. � � ���������, ��� ��� ��� ����������. ��, �������� ������� �� ����-������ ���. �� ��������!";
			link.l1 = "�� ��������, " + npchar.name + ".";
			link.l1.go = "Spyglass_exit";
			pchar.questTemp.Regata.AdversaryFourthTransition.Time.c = sti(pchar.questTemp.Regata.AdversaryFourthTransition.Time.c)-sti(pchar.questTemp.Regata.SpyIndex);//������ �������� ������� �����
		break;
		
		case "Spyglass_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 10);
			bDisableFastReload = false;
			chrDisableReloadToLocation = false;
		break;
		
		case "Regata_SiegeOfficer":
			dialog.text = "������������, �������. �� ���� �������� ���������� ������? ���?";
			link.l1 = "��. � � ��� ����, ������?";
			link.l1.go = "Regata_SiegeOfficer_1";
		break;
		
		case "Regata_SiegeOfficer_1":
			dialog.text = "��, ��������, � �����, ��� ���� ������� ������� �������. ������ �� ����� ������� � ���� ����� �� ���������� ��� ����������. �� �������� � ���������� ������� ��� �����, ����� ������ - ���� ����� �������, � �� ������ - ����������������.";
			link.l1 = "��... �������, � ���������� � ��� ��������� ����������, ���� � �� �������, ����� � ���� ����� ��������� � ������� ���������.";
			link.l1.go = "Regata_SiegeOfficer_2";
		break;
		
		case "Regata_SiegeOfficer_2":
			dialog.text = "����� ������, �������. ������� �� ����� ������ ������� � ������� � ����������. �������� �� ����.";
			link.l1 = "��, �������, ������. ������������.";
			link.l1.go = "Regata_SiegeOfficer_3";
		break;
		
		case "Regata_SiegeOfficer_3":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "Bridgetown_townhall", "goto", "governor1", "RegataSiegeHover", -1);
		break;
		
		case "Regata_SiegeOfficer_4":
			dialog.text = "���! � ����� ������������ ����������� ��������� ��� �� �������. �� ������������?";
			link.l1 = "��, �������. ��������� ����������. ����������� ����� � �������.";
			link.l1.go = "Regata_SiegeOfficer_5";
		break;
		
		case "Regata_SiegeOfficer_5":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "RegataSiegeOpen", -1);
			for (i=1; i <=9; i++)
			{
				sld = characterFromId("RegataBridgWom_"+i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "quest", "quest1", "none", "", "", "", 30);
			}
		break;
		
		case "Regata_SiegeOfficer_6":
			dialog.text = "��������... ��������, ��� ���� ���� - ������ �������, � ��� ����������� ������� - ���������������� �����. �������, �������� ��� ������� ������ �� ������ - �� ���������, ��� ��� �� ������������ ��������� �����.";
			link.l1 = "������. ������� ������������ � ����!";
			link.l1.go = "Regata_SiegeOfficer_7";
		break;
		
		case "Regata_SiegeOfficer_7":
			DialogExit();
			sld = characterFromId("SiegeOfficer");
			LAi_ActorFollowEverywhere(sld, "", -1);
			pchar.quest.Regata_Siege3.win_condition.l1 = "location";
			pchar.quest.Regata_Siege3.win_condition.l1.location = "Barbados_cave";
			pchar.quest.Regata_Siege3.function = "RegataBarbadosCave";
		break;
		
		case "Regata_SiegeOfficer_8":
			dialog.text = "������� ��� �������� �� ������, �������! ���� �� �� ��, � �� ���� ������... �� ��������� ����� - �������� �� ���������, ����������� ������ ������� ������, �������� ��������� ��������. � ��� ������� �� ������... ���� ����������� ������������� ���  - ���� �� ���������� � ������.";
			link.l1 = "����� ���������. ��� �� �����������?";
			link.l1.go = "Regata_skiper";
		break;
		
		case "Regata_Hovernor":
			dialog.text = "������������, ������� " + GetFullName(pchar) + ". ����� ������, ��� �� ������. ������ ������ ����� ���� ������.";
			link.l1 = "���, ���� ���� ���� ��� �������� �� ���� ������� ��������� ������� �������, �� � �� �����������, � ��� ����� ���������� ��� ������. � �������� ��������, � �� �������� ��������...";
			link.l1.go = "Regata_Hovernor_1";
		break;
		
		case "Regata_Hovernor_1":
			dialog.text = "���������� ����, �������, � �� ��� �������. �� ������ � ����� ������� ���������. ����� � ���� �������� ��������� �������, � ���-��� ������ �������� ��� � ������. ����� ����, ������� �������� �� ����� ��������� ����������� �� ���������� ����� ������� � ����������� ������ �� ������ � �������, ������, ��� ����, ����� ��������� ��� � ���� ������ - � ���� � ����\n�������� ����� ��������� � ������� � ����, � ������ � ������ ������������ - �� �� ����� ����� ������� � ����... ��� ������� ���������, ��������� ������ ������, ������������, � ��� ������ � �������� �������, �� � ��� � ������ �� ������ �������\n� ���������� �������� ����� ��� ��� �������� ���������. �� �������������, ��� � ���� �����, ���� �� �� ������ �������� ������� � ������� �������� �����? �����, �������� ������������ ��� �� �����.";
			link.l1 = "���, ��� ��� �������, �� ��� � ���� ��� ������? ���� �� ������ �� ����? ����� � ������� � ��� � ��������� ��������� ��� ��������� �� ����� �������� � ��������� ���������?";
			link.l1.go = "Regata_Hovernor_2";
		break;
		
		case "Regata_Hovernor_2":
			switch (sti(Pchar.BaseNation))
			{
				case ENGLAND: sTemp = "�� �� ����������, �������� ������ ���������� ������ �������, ��� ����� - ������!" break;
				case FRANCE: sTemp = "�� �� �������, �� ���� - ��� �������, �������� ������ ���������� ������ �������, ��� ����� - ������!" break;
				case SPAIN: sTemp = "� ����, �� �������, � ��� � ���� - ���� ����������������, �� �� ���������� � ��������� ������ ��� ���������� ������. �� � ����� �� �������� ���������� ������� ������ ������� ���������, ������ ������? �������� ��!" break;
				case HOLLAND: sTemp = "� ����, �� ���������, � ���� ������ ��������, �� �� ���������� � ��������� ������ ��� ���������� ������. �� � ����� �� �������� ���������� ������� ������ ������� ���������, ������ ������? �������� ��!" break;
			}
			dialog.text = "�� ��, �� ������. � ����� ��� ������ �� �����: �������� �� ����� ������� �� ������ ������ � �����. �� �������, �������� ��� �������. ��������� �� �� ��� ��������, ������ � ����������� �������, � �� �������� �� � ����� ������� � ������ � ������\n������, ��� ������� �� ������ �� �����������. � ���� ���������� ��� �������� - ���, ��� �������, ���� ��������� ��������� ��������. � ���� ���� ������� �� ���. ��� ����������� ����� ���� ����, ��� ��� ����������� � ����� ������ �������, ����� � � ������� ���������� - �� ������� �� �����. �������� ������� �� ������ ������� ��� ������, �� � �� ������ ����� ������\n��� ������ ������ �������. "+sTemp+"";
			link.l1 = "���, ��������, �� ��� ������� ����������, � �� �������� ������ ���������� ����������, ���� � ��� �����. ����� ��������� ����, ���� ������� �����, �������� ��� ������� ������ � ������ ��������� �� ���. ��������, �� � ����� �� ���� ��� ������.";
			link.l1.go = "Regata_Hovernor_exit";
			link.l2 = "�������, ���. � ������ ���. ����� ������ ������ ��������� ���� ��� �������.";
			link.l2.go = "Regata_Hovernor_3";
		break;
		
		case "Regata_Hovernor_3":
			dialog.text = "� ���, ��� �� �����������. �� ��������� ������. ��������� ������� �������� ��������� ���������� �� ��� �������. � �� ������� ��� ���!";
			link.l1 = "�������, ���. �� ����� ������ ����������� �����!";
			link.l1.go = "Regata_Hovernor_4";
		break;
		
		case "Regata_Hovernor_wait":
			dialog.text = "������������, �������! ����� �� ����.";
			link.l1 = "��� ��������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_Hovernor_wait";
		break;
		
		case "Regata_Hovernor_exit":
			dialog.text = "� ������ �������... �� �� ������ ���� ����������? �� ��� ��, ��� ���� �����. � �� ���� ������ �� ��� ���������. ���� �� ������� ���������, � �� �� ��������� ����������� ���� ����� ���� �������� ����� ������, ��... �� ���������� ��� ���������� �������-����������� ���������� ������� ��� �������� ������\n� �������� �� ���� ������� � �����������. ��������, � �� ��������� ������� ��� ����� ����� � ���� ��������� ����!";
			link.l1 = "��������, ���.";
			link.l1.go = "Hovernor_exit";
		break;
		
		case "Hovernor_exit":
			DialogExit();
			pchar.questTemp.Regata.AdversaryFifthTransition.Time.e = sti(pchar.questTemp.Regata.AdversaryFifthTransition.Time.e)-36;//����� ��������� ������� 36 �����
			ChangeCharacterComplexReputation(pchar, "nobility", -8);
			ChangeCharacterNationReputation(pchar, ENGLAND, -5);
			//������� ������ � �����
			npchar.Dialog.Filename = "Common_Mayor.c";
			npchar.dialog.currentnode = "First time";
			//������� ����������
			sld = characterFromId("SiegeOfficer");
			sld.lifeday = 0;
			//��������� ������ � ����� � ����
			bDisableFastReload = false;
			LocatorReloadEnterDisable("Bridgetown_town", "reload1_back", false);
			LocatorReloadEnterDisable("Bridgetown_town", "reload2_back", false);
			LocatorReloadEnterDisable("Bridgetown_town", "gate1_back", false);
			LocatorReloadEnterDisable("Bridgetown_town", "gate_back", false);
			LocatorReloadEnterDisable("Bridgetown_Exittown", "reload3", false);
			//������ � �����
			n = FindIsland("Barbados");	
			DeleteAttribute(Islands[n], "DontSetShipInPort");
			//����� ������ ����� 5 ����
			SetFunctionTimerCondition("RegataSiegeDelete", 0, 0, 5, false);
			for (i=1; i <=9; i++)//����� �������
			{
				sld = characterFromId("RegataBridgWom_"+i);
				sld.lifeday = 0; // patch-7
				LAi_CharacterDisableDialog(sld);
			}
		break;
		
		case "Regata_Hovernor_4":
			DialogExit();
			NextDiag.CurrentNode = "Regata_Hovernor_wait";
			sld = characterFromId("SiegeOfficer");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "Bridgetown_town", "goto", "goto4", "", 10);
			pchar.quest.Regata_evacuation.win_condition.l1 = "location";
			pchar.quest.Regata_evacuation.win_condition.l1.location = "Bridgetown_town";
			pchar.quest.Regata_evacuation.function = "RegataSiegeEvacuation";
		break;
		
		case "Regata_BridgWom":
			dialog.text = "������� ���������! �������, �������� ��� ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_BridgWom";
		break;
		
		case "Regata_BridgWom_1":
			dialog.text = "��������� ������� �����... ����� ������. �� ��� �������� ��������. �������, �� ��������� ��� � ������? ������ ��������, � ������ �� ���� � ���� �����������.";
			link.l1 = "�������. �������� �� ����!";
			link.l1.go = "Regata_BridgWom_2";
		break;
		
		case "Regata_BridgWom_2":
			DialogExit();
			for (i=1; i <=9; i++)
			{
				sld = characterFromId("RegataBridgWom_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", -1);
			}
			pchar.quest.Regata_Siege3.win_condition.l1 = "location";
			pchar.quest.Regata_Siege3.win_condition.l1.location = "Barbados_cave";
			pchar.quest.Regata_Siege3.function = "RegataBarbadosCave";
		break;
		
		case "Regata_BridgWom_3":
			dialog.text = "��� �� � �� �����... ������� ��� ��������, �������! �� ������ ������ ���� ���! � ��� �������� �� ������... ���� ����������� ������������� ���  - ���� �� ���������� � ������?";
			link.l1 = "��, ��������. � ��� ��� �� �����������?";
			link.l1.go = "Regata_skiper";
		break;
		
		case "Regata_skiper":
			pchar.questTemp.Regata.Name = GetFullName(npchar);
			dialog.text = "��� ���� ����� � ����-�����? ����� �������� ���� - ����� �������. ��������� � ���������. ��� ������� �������� �� ����� ����� �������� - �� ������ ����� � ������� ������. �� ��� ���� ���� ������� ����� ���� ����� ���������� � ������� � �������� ��� ������� ���������� �����\n�� ���������� �� ���� �����, ����� ����������� ��� ��� ������. ����� ����� �� ������ ����� ������� � ������. �������, ��� ��� �������"+ NPCharSexPhrase(NPChar, "","�") +" " + GetFullName(npchar) + " - �� ��� �� �������. �������� ��� ����� � ����-����� - �� ��� ����� ���� ���������.";
			link.l1 = "����� ������! �������� ������ ��� � ������ ����������. ��, � �� ������ - ��������. ��� ���� ������������ � �������� ����.";
			link.l1.go = "Regata_skiper_1";
		break;
		
		case "Regata_skiper_1":
			dialog.text = "�� ��������, �������! ����� ���!";
			link.l1 = "�����, ��� ����������...";
			link.l1.go = "Regata_skiper_2";
		break;
		
		case "Regata_skiper_2":
			DialogExit();
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterNationReputation(pchar, ENGLAND, 10);
			LAi_SetStayType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0; // patch-8
			for (i=1; i <=9; i++)
			{
				sld = characterFromId("RegataBridgWom_"+i);
				LAi_SetStayType(sld);
				LAi_CharacterDisableDialog(sld);
				sld.lifeday = 0; // patch-8
			}
			//������� ������ � �����
			sld = characterFromId("Bridgetown_Mayor");
			sld.Dialog.Filename = "Common_Mayor.c";
			sld.dialog.currentnode = "First time";
			//��������� ������ � ����� � ����
			LocatorReloadEnterDisable("Shore4", "boat", false);
			LocatorReloadEnterDisable("Bridgetown_town", "gate1_back", false);
			LocatorReloadEnterDisable("Bridgetown_town", "gate_back", false);
			LocatorReloadEnterDisable("Bridgetown_Exittown", "reload3", false);
			LocatorReloadEnterDisable("Barbados_cave", "reload1", false);
			bQuestDisableMapEnter = false;
			//����� ������ ����� 5 ����
			SetFunctionTimerCondition("RegataSiegeDelete", 0, 0, 5, false);
			RegataSiegeSkiper();//�������� ����� � �������
		break;
		
		case "Regata_SiegeSkiper":
			dialog.text = "������������. �� ���-�� ������?";
			link.l1 = "��� ����� ����� ��������, ���������?";
			link.l1.go = "Regata_SiegeSkiper_1";
		break;
		
		case "Regata_SiegeSkiper_1":
			dialog.text = "��, ��� ���. ��� ���� �������?";
			link.l1 = "��� ��������, ��� �� ������� ������� � ������ ������ ���� ����� ���������� � �������. ����� ��� ��������, ��� ��� ����� � ����-�����. � - �������� ������, ��� ��������� ��������� ������� ��� ��� �� ����-�����, � � ���� ��������� ��� ����� � ��� ������� � �������� �������� � ������� �� ���� �������.";
			link.l1.go = "Regata_SiegeSkiper_2";
		break;
		
		case "Regata_SiegeSkiper_2":
			dialog.text = "����� ���������... � ������ �� ��������, ��� � ����� �� ��� �������?";
			link.l1 = "��, ������ ��� � ����� ��� �� �������� �� ����� "+pchar.questTemp.Regata.Name+", � ���������, ��� �� ��� �� ��������. � ������ ��� �, ���-�����, ������ ������ ������ ��������� � ���� ������� ������...";
			link.l1.go = "Regata_SiegeSkiper_3";
		break;
		
		case "Regata_SiegeSkiper_3"://� ��� - ��� �� ������
			if(drand(2) != 2)
			{
				dialog.text = "�� "+pchar.questTemp.Regata.Name+"? ���, �������, �� ���������. ������, �������, � ������ ��������� ��� ���������� ���� �� ���������� �� ����-�����. �� ������������� ����� ������?";
				link.l1 = "��, �������. ����� ������ � ��������.";
				link.l1.go = "Regata_SiegeSkiper_4";
			}
			else
			{
				dialog.text = "�� "+pchar.questTemp.Regata.Name+"? ��, ����� �������. ��, �������, � ��������� � �� ���� �������� ��� ����� � ��� ������� �����. ��� ������, ��������� ��� ������������ ������, �� ������ ��� ��������\n� �� ����, ����� ����� ���� ��������� � ���� �� ������, ���, ����� ������ �� ������ ����� �������� ������ � ���������. � ������� � ���� �������� ��� �����. �� ����������, �������.";
				link.l1 = "��� ���� ������������� �������? �� � �� ����� ����� �������...";
				link.l1.go = "Regata_SiegeSkiper_6";
			}
		break;
		
		case "Regata_SiegeSkiper_4":
			dialog.text = "����� �� ����� ������ �������. � ������� �� ���� ���� � ���������� �� ��� �������.";
			link.l1 = "������� �������� ��� �� ����� � �������� �� '�����-��������'. �������, �����!";
			link.l1.go = "SiegeSkiper_hire";
		break;
		
		case "Regata_SiegeSkiper_6":
			dialog.text = "�������, ������ - ��� �����, � ����� ��������� ����� ������ - ��� �����. � ������ � ���� �� �������. � ��������� - �� ������ ���� ������ ��� ����� ������ - ��� �������� ������� '�����' � '����'. ��� ��� ������������� ������� � ������ ��� � �� �������.";
			link.l1 = "��� ��... ����� ����. ��������, �����.";
			link.l1.go = "SiegeSkiper_exit";
		break;
		
		case "SiegeSkiper_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
		break;
		
		case "SiegeSkiper_hire":
			chrDisableReloadToLocation = true;//������� �������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 10.0);
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.loyality = 25;
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			//������������� ����� ������ ��������
			for (i=1; i <=5; i++)
			{
				if (i==1) sTemp = "a";
				if (i==2) sTemp = "b";
				if (i==3) sTemp = "c";
				if (i==4) sTemp = "d";
				if (i==5) sTemp = "e";
				pchar.questTemp.Regata.AdversaryFifthTransition.Time.(sTemp) = sti(pchar.questTemp.Regata.AdversaryFifthTransition.Time.(sTemp))+18+(rand(18));//������� �� 1.5 �����
				log_testinfo(FindRussianDaysString(pchar.questTemp.Regata.AdversaryFourthTransition.Time.(sTemp)));
			}
			SetFunctionTimerCondition("SiegeSkiperOver", 0, 0, 15, false);//����� �� �������� �������
			DialogExit();
		break;
		
		case "Regata_Finish":
		iTest = FindColony("Portroyal"); 
		if (iTest != -1)
		{
			rColony = GetColonyByIndex(iTest);
			sFrom_sea = rColony.from_sea;
		}
		ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
		{
			//������� �������
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			if (CheckAttribute(pchar, "questTemp.Regata.Breach") || !CheckAttribute(pchar, "questTemp.Regata.Bridgetown") || GetCompanionQuantity(pchar) > 1 || sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LUGGER || pchar.Ship.Name != "�a���-K��ep���")
			{
				dialog.text = "�� �������� ������� ������, �� ����� ��������� �����. ��� ��������� �����������������. ��� ������ ������ ��� �������, �������.";
				link.l1 = "��... ����! �����, ������ �� ��������� - �� ��������� ���������. ��������!";
				link.l1.go = "exit";
				npchar.lifeday = 1;
				DeleteAttribute(pchar, "questTemp.Regata");
			}
			else
			{
				n=1;
				for (i=1; i <=5; i++)
				{
					if (i==1) sTemp = "a";
					if (i==2) sTemp = "b";
					if (i==3) sTemp = "c";
					if (i==4) sTemp = "d";
					if (i==5) sTemp = "e";
					if (pchar.questTemp.Regata.AdversaryFifthTransition.Time.(sTemp) < sti(pchar.questTemp.Regata.FifthTransitionTime)) n++;
					pchar.questTemp.Regata.Result = n;//����� � ������
				}
				if (n==1)
				{
					dialog.text = "������� "+GetFullName(pchar)+", ���������� ��� � �������! �� ��������� �� ������ "+sti(pchar.questTemp.Regata.FifthTransitionTime)+" �����, ������� ������ ���� �����������. ��� �������� ���������!";
					link.l1 = "������� �� ������� �����, ���!";
					link.l1.go = "First_result";
				}
				else
				{
					if (n==6)
					{
						dialog.text = "�������, ��� - �� ��� ��������� ��������� - �� ��������� �� ������ "+sti(pchar.questTemp.Regata.FifthTransitionTime)+" �����. �� �����������, � ��� ���� ������������� ������� ����������.";
						link.l1 = "� �� ���������, ���. � ���, ��� ���������� � ������ � ��������� ���� ����.";
						link.l1.go = "Other_result";
					}
					else
					{
						dialog.text = "�������, �� ������ "+n+" �����. ���������� � �������� ������������ ��������, �� �������� ��������� ����� - "+sti(pchar.questTemp.Regata.FifthTransitionTime)+" �����. � ���� �� � �� ��������, � ��� ����� ���������� ���!";
						link.l1 = "� �� ���������, ���. � ���, ��� ������� �������� ��������� � ���� ������� ��������������.";
						link.l1.go = "Other_result";
					}
				}
			}
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex("SiegeSkiper");
			sld = &Characters[sti(Pchar.questTemp.FiringOfficerIDX)];
			CheckForReleaseOfficer(sti(Pchar.questTemp.FiringOfficerIDX));
			RemovePassenger(Pchar, sld);
			DeleteAttribute(sld, "Payment");
			DeleteAttribute(Pchar, "questTemp.FiringOfficerIDX");//������� �� ��������
			log_info("����� �������� ����� �� �����");
			pchar.quest.SiegeSkiperOver.over = "yes"; //����� ������
		}
		else
		{
			dialog.text = "���, ��������� �������� - ��� ��� �������? � ���-�� ��� �� ��������...";
			link.l1 = "����� ��������, ���. � ���������� ������� ���� ������� � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_Finish";
		}
		break;
		
		case "First_result":
			if (CheckAttribute(pchar, "questTemp.Regata.Rate")) sTemp = "����� ������� �� ��� � ������� - � ����� ������� �� ����� ������.";
			else sTemp = "� ���� �� �� ������� ������ �� ���� ������, ��� � ��� ��������� - �������� �� ��� � �������.";
			dialog.text = "������ ������� � �������-����������� - �� ������ ��� ����� �� ������ - ���������� ������ � ������� 250 000 ���� � ������ �������. "+sTemp+" �� ��������� ����� - �������� ��������, ���� ���������� �� �������� �� ������� � ������� ������, ��� ���������� � ��������� �����.";
			link.l1 = "� ��� �����, ���. ���� ������ �� ������!";
			link.l1.go = "First_result_1";
		break;
		
		case "First_result_1":
			DialogExit();
			//npchar.lifeday = 7;
			npchar.dialog.currentnode = "Other_result_repeat";
			pchar.questTemp.Regata.Win = "true";
			pchar.quest.Regata_Final.win_condition.l1 = "Timer";
			pchar.quest.Regata_Final.win_condition.l1.date.hour  = 6.0;
			pchar.quest.Regata_Final.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Regata_Final.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Regata_Final.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Regata_Final.function = "RegataFinal";
			SetFunctionTimerCondition("RegataFinalOver", 0, 0, 8, false);//������ �� ������� - ����� 8 ���� ����������� ��� �������������
			// �����
			AddSimpleRumour("�, ��� ��� �� - ����������� �������, ���������� �������� ������! ����� ������� ��� ������!", ENGLAND, 60, 10);
			AddSimpleRumour("��, �� ��� �� �� ��� ����, ��� ���������� ����� � ����, ���������� ������� ���������, ���������� �������� ������! ��� ��� ��������...", ENGLAND, 60, 10);
			AddSimpleRumour("�, ��� ������� �������������, ������ ����� � ����, ���������� �������� ������ ������ ��� ����� ����� �������! �� ���� ���, �������!", ENGLAND, 60, 10);
			AddSimpleRumour("�, �� ��� ��������������� ���������� � ��������� ����� ��������, ���������, ��������� �� ��� ��� �������� ��������� ���� ��� ��������� �����, ����������� �������� ������! ��� ��������, �������!", ENGLAND, 60, 10);
			AddSimpleRumour("�, ��� ��� �� - ����������� �������, ���������� �������� ������! ����� ������� ��� ������!", FRANCE, 60, 10);
			AddSimpleRumour("��, �� ��� �� �� ��� ����, ��� ���������� ����� � ����, ���������� ������� ���������, ���������� �������� ������! ��� ��� ��������...", FRANCE, 60, 10);
			AddSimpleRumour("�, ��� ������� �������������, ������ ����� � ����, ���������� �������� ������ ������ ��� ����� ����� �������! �� ���� ���, �������!", FRANCE, 60, 10);
			AddSimpleRumour("�, �� ��� ��������������� ���������� � ��������� ����� ��������, ���������, ��������� �� ��� ��� �������� ��������� ���� ��� ��������� �����, ����������� �������� ������! ��� ��������, �������!", FRANCE, 60, 10);
			// �����
			AddComplexSeaExpToScill(2000, 300, 300, 0, 500, 500, 0);
			AddCharacterExpToSkill(pchar, "Leadership", 2000);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			ChangeCharacterComplexReputation(pchar, "fame", 15);
			ChangeOfficersLoyality("good_all", 3);
		break;
		
		case "Other_result":
			dialog.text = "������� ������� ���� ��������� �����. ����� ���, �������!";
			link.l1 = "��������, ���.";
			link.l1.go = "Other_result_1";
		break;
		
		case "Other_result_1":
			DialogExit();
			npchar.dialog.currentnode = "Other_result_repeat";
			SetFunctionTimerCondition("RegataFinalOver", 0, 0, 1, false);
			// �����
			AddComplexSeaExpToScill(500, 100, 100, 0, 100, 100, 0);
			AddCharacterExpToSkill(pchar, "Leadership", 200);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 100);//����������
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;
		
		case "Other_result_repeat":
			dialog.text = "�� ���-�� ��� ������, �������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Other_result_repeat";
		break;
		
		case "Give_advantage":
			dialog.text = "�-�, ��� � ��, ��������� "+GetFullName(pchar)+". ��� ��� ������. �� ������ �� ����� ���������? �� �����������.";
			link.l1 = "������� ��� �������! ����� �� ������ ����� ��������������� �����?";
			link.l1.go = "Give_advantage_1";
		break;
		
		case "Give_advantage_1":
			dialog.text = "� ������ ��������� ������, ��� ������� ���������� "+FindRussianMoneyString(makeint(pchar.questTemp.Regata.Advantage))+". ����������, ��������. ���������� ��� ��� � �������!";
			link.l1 = "�������!";
			link.l1.go = "Give_advantage_2";
		break;
		
		case "Give_advantage_2":
			AddMoneyToCharacter(pchar, makeint(pchar.questTemp.Regata.Advantage));
			dialog.text = "����������, ���� ������������ ����� ������� ����-����� �������. �����, �� ������ ������� ��� ��������... ������, ������ � ����� ��������, ���. ��� ��� ��������� � ����� �����, ���� ��� ��� �����!";
			link.l1 = "���������� ���� �� ��������, ���... ���������, ������ ��� - ��������� ����� �� ����� �����. �� ��������! ��� ��� � ���� �������������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "Other_result_repeat";
		break;
		
		case "Regata_CitMan_1":
			if (CheckAttribute(pchar, "questTemp.Regata"))
			{
				if (CheckAttribute(pchar, "questTemp.Regata.Result"))
				{
					if (sti(pchar.questTemp.Regata.Result) == 1)
					{
						dialog.text = "���������� � �������, �������! ������������ ���������!";
						link.l1 = "�������!";
						link.l1.go = "exit";
					}
					else
					{
						dialog.text = "�� ���������������, �������. �������� � ������ - ������, � ���� ������ ������� � ��� �������� ��� �����!";
						link.l1 = "�� ����������� �� ����. � ������� ����� �����������.";
						link.l1.go = "exit";
					}
				}
				else
				{
					dialog.text = "� ���������, �������! ������ ��� ���� ��������� � ���� ����������.";
					link.l1 = "�������. ��� � ����!";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��, �������, ��� �� �� ��� ��������, �� �� ����� ��������� �����!";
				link.l1 = "�� ��, ������ �� �������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Regata_CitMan_1";
		break;
		
		case "Regata_CitWom_1":
			if (CheckAttribute(pchar, "questTemp.Regata"))
			{
				if (CheckAttribute(pchar, "questTemp.Regata.Result"))
				{
					if (sti(pchar.questTemp.Regata.Result) == 1)
					{
						dialog.text = "���������� � �������, �������! ������������ ���������!";
						link.l1 = "�������!";
						link.l1.go = "exit";
					}
					else
					{
						dialog.text = "�� ���������������, �������. �������� � ������ - ������, � ���� ������ ������� � ��� �������� ��� �����!";
						link.l1 = "�� ����������� �� ����. � ������� ����� �����������.";
						link.l1.go = "exit";
					}
				}
				else
				{
					dialog.text = "� ���������, �������! ������ ��� ���� ��������� � ���� ����������.";
					link.l1 = "�������. ��� � ����!";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��, �������, ��� �� �� ��� ��������, �� �� ����� ��������� �����!";
				link.l1 = "�� ��, ������ �� �������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Regata_CitWom_1";
		break;
		
		case "Regata_CitHorse_1":
			if (CheckAttribute(pchar, "questTemp.Regata"))
			{
				if (CheckAttribute(pchar, "questTemp.Regata.Result"))
				{
					if (sti(pchar.questTemp.Regata.Result) == 1)
					{
						dialog.text = "���������� � �������, �������! ������������ ���������!";
						link.l1 = "�������!";
						link.l1.go = "exit";
					}
					else
					{
						dialog.text = "�� ���������������, �������. �������� � ������ - ������, � ���� ������ ������� � ��� �������� ��� �����!";
						link.l1 = "�� ����������� �� ����. � ������� ����� �����������.";
						link.l1.go = "exit";
					}
				}
				else
				{
					dialog.text = "� ���������, �������! ������ ��� ���� ��������� � ���� ����������.";
					link.l1 = "�������. ��� � ����!";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��, �������, ��� �� �� ��� ��������, �� �� ����� ��������� �����!";
				link.l1 = "�� ��, ������ �� �������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Regata_CitHorse_1";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

void CreateRegataAdversaries()
{
	string sTemp;
	for (int i=0; i<=4; i++)
	{
	if (i==0) sTemp = "a";
	if (i==1) sTemp = "b";
	if (i==2) sTemp = "c";
	if (i==3) sTemp = "d";
	if (i==4) sTemp = "e";
	pchar.questTemp.Regata.AdversaryName.(sTemp) = GenerateRandomName_Generator(i, "man");
	pchar.questTemp.Regata.AdversaryShipName.(sTemp) = GenerateRandomNameToShip(ENGLAND);
	pchar.questTemp.Regata.AdversarySpeed.(sTemp) = 0.4+frand(0.9);
	log_testinfo(FindRussianDaysString(stf(pchar.questTemp.Regata.AdversarySpeed.(sTemp))));
	}
}