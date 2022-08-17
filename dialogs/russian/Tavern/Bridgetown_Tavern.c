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
			//����������� ������ /�� ������/
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoBridgetown" && !CheckAttribute(npchar, "quest.HWICTalked"))
            {
                link.l1 = "� ���� ������. ����� ��� ������ ������� ����, ������� � ���� ����.";
                link.l1.go = "TavernDone";
            }
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "toBarbados")
            {
                link.l1 = "��������, � ��� �������� ������?";
                link.l1.go = "Tonzag_Letter";
            }
			//����������� ������ /������ ����/
			if (!CheckAttribute(npchar, "quest.HWICTake") && CheckAttribute(pchar, "questTemp.HWIC.CanTake") && !CheckAttribute(pchar, "questTemp.HWIC.CanTake.Self") && !CheckAttribute(pchar, "questTemp.HWIC.Eng") && !CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
                link.l1 = "��� �� � ���� �����-������ ������? ���, �����, ���-������ �����������?";
                link.l1.go = "Tonzag_check";
            }
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "FernandoDie")
			{
                link.l1 = "� �������� ������. �������� �������� �����.";
                link.l1.go = "Task_check";
            }
			// ����� ������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "��������, �� ��������� �� � ��� � ������ ������-�������, ������? �� ���������, ��� ��������, ����� ����� ��������. �� ������ � �����?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//����������� ������ /�� ������/
		case "TavernDone":
			dialog.text = "������� - �� ����������, ����� ������ ��� ��� �������� �����! � ��� �������� �����, ��� ������ ����� ��������� �����?";
			link.l1 = "����� �������, � ��������. � ���� ����� � �������� - ������� ��������� ���� ����� ���� ���������� ��� ��� ���� - � ��� ����� �� ���������, �������� � ����������� - �� ������� ��� ��������� ������ '������� ������'. ��� ��� ����� ��� ���� ����� � �����. ������ ����� � �������� - ���� ������ �� ��������, ��-��...";
			link.l1.go = "TavernDone_1";
		break;
		
		case "TavernDone_1":
			dialog.text = "��� ���? ��, �� ������� ������ �� ���� � ������! ��������, ������ '�����' �� �������� ������, ��-��?! �������...";
			link.l1 = "�����... ����� ����� �����, ��� ��������.";
			link.l1.go = "exit";	
			npchar.quest.HWICTalked = "true";
			pchar.questTemp.HWIC.Eng.BridgeCounter = sti(pchar.questTemp.HWIC.Eng.BridgeCounter)+1;
			AddQuestRecord("Holl_Gambit", "2-12");
			if (sti(pchar.questTemp.HWIC.Eng.BridgeCounter) == 7) 
			{
				AddQuestRecord("Holl_Gambit", "2-6");
				pchar.questTemp.HWIC.Eng = "SeekVanBerg";
				pchar.quest.GotoBridgetownOver.over = "yes";//����� ������
				pchar.quest.VanBergAttack_Check.win_condition.l1 = "MapEnter";
				pchar.quest.VanBergAttack_Check.function = "VanBergAttackCheck";
			}
		break;
		
		case "Tonzag_Letter":
			dialog.text = "������ ����� �� ������ ����� ���� ���� ����� ����, ��� �� �������� ��� ����, ���������� �� ���� �������� ��-�����-���. ��� ����� ������ ����������, ��������� ������� ��������� � ����� ���������� ������. ��� ���-�� ������ � ����������� ����-��. ������ ��� ����� �� �����. � ���, ������, �� ������� ������. ������ �������� �����, ���� �� ��������� �� ��������� ������ ����\n������, ������� ��� ������: �����-�� ���������� �������� � �������, �� �� �������, �� �� ����������. ��� ��� �� ���� ����. �� ���� ����� ������� � ����� �� ����� ������. ���� � ��� ���-�� �����... ������� �� �������.";
			link.l1 = "����� ���� ������... �������!";
			link.l1.go = "Tonzag_Letter_1";
		break;
		
		case "Tonzag_Letter_1":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "2-22");
			AddQuestRecordInfo("LetterFromGaston", "1");
			pchar.questTemp.HWIC.Eng = "toCuracao";
			LocatorReloadEnterDisable("SentJons_town", "houseSP3", true);//������� ��� ��������
			LocatorReloadEnterDisable("SentJons_town", "HouseF3", true);//������� ������
			LocatorReloadEnterDisable("SentJons_town", "basement1_back", true);//������� ����������
			pchar.quest.Knippel_Shore.win_condition.l1 = "location";
			pchar.quest.Knippel_Shore.win_condition.l1.location = "Shore24";
			pchar.quest.Knippel_Shore.function = "KnippelOnCuracao";
		break;
		
		//����������� ������ /������ ����/
		case "Tonzag_check"://�������� ��������� ������ �� �� ���� �������

			PlaySound("VOICE\Russian\hambit\Ercule Tongzag-02.wav");
			dialog.text = "��... ������-�� �� �������, � ���� ��� ��� ���� ���� ����, ������� ������� ����������������� ����������. ���� ������ ���� �������� - ���������� ��� � ����� ������������ ������. ������ ��������, ��� �� ��� ���������.";
			link.l1 = "� ���� ��������.";
			link.l1.go = "Tonzag_task";
		break;
		
		case "Tonzag_task":
			pchar.questTemp.HWIC.Self.SpainCity = FindSpainCity();
			log_Testinfo(pchar.questTemp.HWIC.Self.SpainCity);
			dialog.text = "�� ������ ������ �� �������� ���� �������, � ������� ��������� ����������� �����... ����� � ������. ������ ����� ����� ������ �� ����� - ����������� ��������� ����� ������, ����� ���� ������� ����. ��������� �� ���� ����� ��������\n� �������� �������������� �� ������ �������� ��� ����� � ��������� �������� � ��������� ���. ����� ����, ��������� ��� ���, ��� ������� ��� ���, ��� ����. �� ������ ������� �� ��� ������?";
			link.l1 = "���� ������ ����� ���������, �� ������� ��������.";
			link.l1.go = "Tonzag_task_1";
			link.l2 = "�������� ������� �������? �� �� �� ���!";
			link.l2.go = "Tonzag_exit";
			npchar.quest.HWICTake = "true";
			pchar.questTemp.HWIC.CanTake.Self = "true";//�������, ��� ������ ���� ��� �������
		break;
		
		case "Tonzag_exit":
			dialog.text = "����� ������������, � �������� � ����� ���������.";
			link.l1 = "��������� ����������.";
			link.l1.go = "exit";	
			DeleteAttribute(pchar, "questTemp.HWIC.Self");//����� � ���� ������ ���������
			pchar.questTemp.HWIC.Fail3 = "true";
		break;
		
		case "Tonzag_task_1":
			dialog.text = "������� ���������� � ������� 30 000 ���� - � ������� �� �� ����������. ����� ����, ������ ������� ���� � ����� ��� ������, ����� �������. ������ �����������: ������ ������� ����� ��� �������� ��������. ��� �������: �� ��� 35 ���, �������, �������, ��������� ��� �������. ������� ����� � ������� ������������\n��� ��� ����� - ������� ����� �� ����, �� ���������� ��������, ��� �� ������ � ����� �� ��������� ��������� ���������� � �� ���������� ������ ����������� ��� ��� ������. �������� ��� ��������� ������, ����������� ����� - ���-������ ����������� ��� �����\n� ���: � ���������� ����, � ������ ������ �� ������� �� ����������, ��� ��� �� ��������� ���-���� �� ���� ������. ������� ����?";
			link.l1 = "�������� ���. ����������� � ����!";
			link.l1.go = "Tonzag_task_2";	
		break;
		
		case "Tonzag_task_2":
			DialogExit();
			pchar.questTemp.HWIC.Self = "start";
			SetFunctionTimerCondition("TargetFernandoOver", 0, 0, 60, false); //������
			AddQuestRecord("Holl_Gambit", "3-1");
			ReOpenQuestHeader("Holl_Gambit"); // ������ . ����� ����� �� ������					
			Log_TestInfo(""+XI_ConvertString("Colony"+pchar.questTemp.HWIC.Self.SpainCity)+"");
		break;
		
		case "Task_check":
			dialog.text = "����� � �������� � ����? ������.";
			if (CheckCharacterItem(pchar, "Finger"))
			{
				link.l1 = "��, �������. ��� ��.";
				link.l1.go = "Task_check_1";	
			}
			else
			{
				link.l1 = "���. �������� ������ ������ �� ����� ��������, � ����� ������ ������ � ��������.";
				link.l1.go = "Task_fail";	
			}
		break;
		
		case "Task_fail":
			dialog.text = "����� � ������� ��� ������������ �������� ���������. ��� ������������� ������ �������. ��� �����, �� ������ �� �������� �� ����� �� ������ ����������� �������? �� ��������? ���. � �����, � ������� �� �� ���������, ��� ��� �� ���� ���� �������������� ��������. ����� �������.";
			link.l1 = "�� � �� ��� ���������! �, ��� � �����... �� ���������� � ������ ������� �������. �����.";
			link.l1.go = "exit";
			pchar.questTemp.HWIC.Fail3 = "true";
			AddQuestRecord("Holl_Gambit", "3-8");
			CloseQuestHeader("Holl_Gambit");
			DeleteAttribute(pchar, "questTemp.HWIC.Self");//�������� ��� ����������� ������ � ������������ ��������
		break;
		
		case "Task_check_1":
			RemoveItems(PChar, "Finger", 1);
			dialog.text = "�����������! ����� � �������� ����. ������ �� ����������� ��� ��������. ����� ���������, ��� �� ������.";
			link.l1 = "����������, ������...";
			link.l1.go = "Task_check_2";	
		break;
		
		case "Task_check_2":
			if (CheckCharacterItem(pchar, "jewelry7") && CheckCharacterItem(pchar, "totem_05") && CheckCharacterItem(pchar, "amulet_1"))
			{
				dialog.text = "���, ��, ��� ��� �����. �������! �� ������� �������� ������. � ������� �����.";
				link.l1 = "�������! ������� ������� ������ �������.";
				link.l1.go = "Task_complete";	
			}
			else
			{
				dialog.text = "��... � �� ���� ������������ - � ����, � ��� �������� ������� �� ����������. � � �� ���� ����� ����, ��� ��� ����. �� ����������� ��� ����? ��� �������? �������. � ����� �� ����� ����� � ����� ����. ����������.";
				link.l1 = "�� � ��� � �����...";
				link.l1.go = "exit";
				pchar.questTemp.HWIC.Fail3 = "true";
				AddQuestRecord("Holl_Gambit", "3-9");
				CloseQuestHeader("Holl_Gambit");
				DeleteAttribute(pchar, "questTemp.HWIC.Self");//�������� ��� ����������� ������ � ������������ ��������
			}
		break;
		
		case "Task_complete":
			RemoveItems(PChar, "jewelry7", 1);
			RemoveItems(PChar, "totem_05", 1);
			RemoveItems(PChar, "amulet_1", 1);
			AddMoneyToCharacter(pchar, 30000);
			dialog.text = "��� ���� ��������������, ��� � ���� ������� - �������� �����. � � ���� ����� ���� ��� ���� ���������, ����� ������������� �������, ��������� �� ������������ ������, �� � ������ ����� ��������������� - 40 000 ����.";
			link.l1 = "������ �����������. ��� ��������� ������?";
			link.l1.go = "Fleetwood_house";	
		break;
		
		//2 �������
		case "Fleetwood_house":
			PlaySound("VOICE\Russian\hambit\Ercule Tongzag-05.wav");
			dialog.text = "� ���� ��� ��������� ����� �� �� ���������, � �� �����. ���� ����� ���������� � ��� ����������� ��������, ������� ��������, ������������ �� �������, � �������� ��� ������� ������. ��� ���� ���������� �������, �� � ��� ������ �� ����� �������� ������� � ��� ������\n���� �����: ����� ����� 10 ���� ���������� ����-������ ���� � ���� �� ������ ������ ����, ���� ����� ��������� � ������� �������. ���� ����� ���������� � ��� �����, ����� ����� � ����� ������ - ����� �� ����� ��������� ������ �����������. ������ ����� ����� ���� ������ - ����� ������� ��� ����, �� � ������ �������. ��������� ������������. ������ ������� ������ � ������������ ������� �� ������ �����\n������ ���� ���� - � ������� ���� �� �������� �������� ����� ����.";
			link.l1 = "��... ���������. ������ �����, ����� ����������� � ����!";
			link.l1.go = "Fleetwood_house_1";	
		break;
		
		case "Fleetwood_house_1":
			GiveItem2Character(pchar, "key3");
			dialog.text = "���� ���������. �� ����� � ��� ������ ��������� ���� ����, ����� ���� � ������ ������ ������ ������ ����������, � � ������ - ��������� �� ��������. ������� ���� � �����.";
			link.l1 = "����� ����� ������ ����, � ���� �� ���� ����.";
			link.l1.go = "Fleetwood_house_2";	
		break;
		
		case "Fleetwood_house_2":
			dialog.text = "������. ������ �����������. �����!";
			link.l1 = "�������, ������.";
			link.l1.go = "Fleetwood_house_3";
		break;
		
		case "Fleetwood_house_3":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-10");
			pchar.questTemp.HWIC.Self = "theft";
			DeleteAttribute(pchar, "questTemp.HWIC.CanTake");//���� �������� ����� ����������
			LocatorReloadEnterDisable("SentJons_houseSP3", "reload2", true);//������� �������
			pchar.GenQuestBox.SentJons_houseSP3_room = true;
			pchar.GenQuestBox.SentJons_houseSP3_room.box1.items.FleetwoodJournal = 1;//������� � ����� ��
			pchar.GenQuestBox.SentJons_houseSP3_room.box1.items.sand_clock = 1;//� �������� ����
			AddDialogExitQuestFunction("CreateFleetwoodSoldiers");//4 ������ � ����
			SetFunctionTimerCondition("FleetwoodJournalOver", 0, 0, 11, false);//������
			pchar.quest.Fleetwood_Journal.win_condition.l1 = "Timer";
			pchar.quest.Fleetwood_Journal.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.Fleetwood_Journal.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 9);
			pchar.quest.Fleetwood_Journal.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 9);
			pchar.quest.Fleetwood_Journal.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 9);
			pchar.quest.Fleetwood_Journal.win_condition.l2 = "Hour";
			pchar.quest.Fleetwood_Journal.win_condition.l2.start.hour = 0;
			pchar.quest.Fleetwood_Journal.win_condition.l2.finish.hour = 3;
			pchar.quest.Fleetwood_Journal.win_condition.l3 = "locator";
			pchar.quest.Fleetwood_Journal.win_condition.l3.location = "SentJons_town";
			pchar.quest.Fleetwood_Journal.win_condition.l3.locator_group = "reload";
			pchar.quest.Fleetwood_Journal.win_condition.l3.locator = "houseSP3";//�������� ���������� �����
			pchar.quest.Fleetwood_Journal.function = "FleetwoodHouseEnter";
			pchar.quest.Fleetwood_Soldier.win_condition.l1 = "location";
			pchar.quest.Fleetwood_Soldier.win_condition.l1.location = "SentJons_houseSP3";
			pchar.quest.Fleetwood_Soldier.function = "Fleetwood_Soldier";//���� �������� ������ ���������
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("���, �� ������. ���� � ��� ��������, � ������ - �� �� ������ � ����� ������.","������� ����� ������ ��� �����. ���, ����� � ��� �������� �� ��������.","�� � ��� � ����� ������� ��������� ���. ������ ����, �� �� ������ � ����� ������ ������.");
			link.l1 = "����. ����. ���� ������ ������!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

string FindSpainCity()//Jason ������� ��������� ��������� ����� - ����� ��������
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation == SPAIN && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].id != "NewProvidence" && colonies[n].nation != "none")
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}