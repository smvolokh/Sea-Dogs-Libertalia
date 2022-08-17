void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "FalseTrace":
			dialog.text = "������ ����, �������... ���... ���! ��������� �������... ��������� ������������� - ���� ������. � ������� �������, � �� ����� ������ �����������, ��� ��� ������� ����� � ���� ����. �� ������ ������� ����������? ��������� ��� ��������� ������, � ������� �� � ��� ���, �� �� ��� ���� �������� �� ������.";
			link.l1 = "���! ������� ����������? ����� ���������. � ����� ��� ���������, ����.";
			link.l1.go = "FalseTrace_1";
			link.l2 = "������ ���, ���������, �� ������� ��������, �� �� ��� �� �������� �������. ��� ��� ������� ��� � � ���� ����� �� ����.";
			link.l2.go = "FalseTrace_exit";
		break;
		
		case "FalseTrace_exit":
			dialog.text = "�������? ��-��! ������ � �������� �� ��� ���������� - ������������� ����, �������. �������, ���� � ����. �� �������� ���������� ����������� ����� � ������ ����������. � ����� ����� �������, ����� ������������...";
			link.l1 = "���, �������� �������, ������. ����� �������!";
			link.l1.go = "FalseTrace_exit_1";
		break;
		
		case "FalseTrace_exit_1":
			DialogExit();
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.FalseTrace");
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
		break;
		
		case "FalseTrace_1":
			//�������� ������� �����
			switch (drand(2))
			{
				case 0: 
					pchar.questTemp.FalseTrace.DayQty = 18;
					pchar.questTemp.FalseTrace.TargetCity = "Beliz";
					pchar.questTemp.FalseTrace.TargetShore = "Shore8";
				break;
				case 1: 
					pchar.questTemp.FalseTrace.DayQty = 22;
					pchar.questTemp.FalseTrace.TargetCity = "Marigo";
					pchar.questTemp.FalseTrace.TargetShore = "Shore41";
				break;
				case 2: 
					pchar.questTemp.FalseTrace.DayQty = 20;
					pchar.questTemp.FalseTrace.TargetCity = "Santodomingo";
					pchar.questTemp.FalseTrace.TargetShore = "Mayak8";
				break;
			}
			pchar.questTemp.FalseTrace.ShipName = GenerateRandomNameToShip(sti(npchar.nation));
			pchar.questTemp.FalseTrace.Mation = sti(npchar.nation);
			dialog.text = "���! ������� ����� ���� � ������ �������� ���������, �������... ���� ���� ������: ��������� �� ���� �� ������ ����� ������ ����� ������ � ��������� ������ �������. ������� ������ ����, ��� ��������� - ����� ��� ��������, ��-��\n��������� ��� - ������ ����. � ������� ���, ������ � ���� ���� �������, �� ��� ������������, � ������� ���� ����. �� ������.";
			link.l1 = "� ��, �������, ������ �������� � ��������� ����� ������?";
			link.l1.go = "FalseTrace_2";
		break;
		
		case "FalseTrace_2":
			dialog.text = "� ���, ����� �� ������� ������, ���? ���. � ��������� �� ���� ����� �������� � �� ������ ������ ������ ������. ������������ �� ����� ��� � ����� � �� ����� - � ����� ��������� ���� � ���������� ������� ��������, ��������, �������\n������ ������� ������ � �������� ��� �� ��������. ��� ��� ������� � ���� ��� ��������� ����... ���... ���! � ����� ����, ��� �������� ������, �� �������� ��� ��� ���� ��������.";
			link.l1 = "� �� ����� ����� ������ �� �����������?";
			link.l1.go = "FalseTrace_3";
		break;
		
		case "FalseTrace_3":
			dialog.text = "� �� ������, ���. ��� ���� �������� �������, ������� ������ � ���� ����� ������� �������, ��� �������� 200 ��� �������. �� ���� ���������, �� ������� ����� �� ������ ���� ����� ��� �������, ��� ��� ��� ���������� ������� �����. �����������, ��� �����������.";
			link.l1 = "������� ����� ������ �� ������� ����������? �� � � ������� � ������� ����� �� ������ ���� ����� �������� �������. ���, ���������, ��� � ���� �� �� ����!";
			link.l1.go = "FalseTrace_4";
			link.l2 = "��. �������, ���������. � �������� ���� �����������, ����. ����� ���������� �� ����. ������ ����������: ������, ����, �����, �������� �������?";
			link.l2.go = "FalseTrace_5";
		break;
		
		case "FalseTrace_4":
			dialog.text = "�� � ������ �� ��, �������! ��, ��� �� ������ - ��� ������ ������ �� ��������. ��������!";
			link.l1 = "����������� ����! ������� ������� �������� ��� ����� ��������!";
			link.l1.go = "FalseTrace_exit_1";
		break;
		
		case "FalseTrace_5":
			dialog.text = "������ ���������� '"+pchar.questTemp.FalseTrace.ShipName+"', ������� �� ��������� � ������������ � ������� "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.TargetCity)+". ������� � ��� �������, �� ������ ����-���� ������. ���� �� ������ �� ��� ��� - ������, ���������.";
			link.l1 = "����� �� ����� ������ �� ������! � ����!";
			link.l1.go = "FalseTrace_6";
		break;
		
		case "FalseTrace_6":
			DialogExit();
			NextDiag.CurrentNode = "FalseTrace_officer";
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			AddPassenger(pchar, npchar, false);
			//LAi_ActorFollowEverywhere(npchar, "", -1);
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			AddQuestRecord("FalseTrace", "1");
			AddQuestUserData("FalseTrace", "sCity1", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.StartCity+"Gen"));
			AddQuestUserData("FalseTrace", "sCity2", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.TargetCity));
			AddQuestUserData("FalseTrace", "sShip", pchar.questTemp.FalseTrace.ShipName);
			//��������� ������ �� ��������� ����������
			pchar.quest.False_Trace_2.win_condition.l1 = "Timer";
			pchar.quest.False_Trace_2.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.False_Trace_2.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2);
			pchar.quest.False_Trace_2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			pchar.quest.False_Trace_2.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2);
			pchar.quest.False_Trace_2.function = "CreateFalseTraceGaleonOnMap";
			SetFunctionTimerCondition("FalseTraceGaleonOver", 0, 0, sti(pchar.questTemp.FalseTrace.DayQty)+2, false);//������
		break;
		
		case "FalseTrace_officer":
			dialog.text = "�� ���-�� ������, ���?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "FalseTrace_officer";
		break;
		
		case "FalseTrace_7":
			chrDisableReloadToLocation = true;
			dialog.text = "�� ���� ������ ������, ���?";
			link.l1 = "�����, ��� ���� ��� �� ���� ��������������... ��� �������, ���� ������?! ��� �������?! � ���� ���������! ������� ������� ������, ��� ��� ������ �������� ������� �����! �� ������� ����!";
			link.l1.go = "FalseTrace_8";
		break;
		
		case "FalseTrace_8":
			dialog.text = "�������, ����� ���, �����������. � ��� ������ ���������� ��� ���������.";
			link.l1 = "��, ��! � ��� �������! �� �� ��� ��� �� ���������� �� ���-��� ���� ������, ��� � �� ���� ������ ������� ������ ��������� �������� - �� ��� ���������� �� ���� �� ����� �� ���� ��������, ����, ��� � ���� � ������ ��� �������� �������. ��� ��� �� ������ �����������.";
			link.l1.go = "FalseTrace_9";
		break;
		
		case "FalseTrace_9":
			dialog.text = "� ������ ��� � ���� �������, ���. ��, � ������������� ������� ���. �� � ��������� ������ � �� ������� �� ���� ������� ��� ������� ��, ��� ��� �����, � ������ - ���������... ���... ���! ��������� ���� ��������� ������\n�� ������, ��� � ����� � �� ��������, � ������ ���������� �� ���� ������. ������ � ���� ������� - ����� ��� ��� ���� �����. �� ����� �� ������� �������? � �����, ��� ���� ������� �������� �� �� ���� �����...";
			link.l1 = "��... ��� ���� ���, ����� ���� ��� �����? � �� �� ���� �������� ���� �������� ������� �������� � �������� ���� ������?!";
			link.l1.go = "FalseTrace_10";
		break;
		
		case "FalseTrace_10":
			dialog.text = "��� ��� ����. �������� ������. ��� ������� �� ���� ��� ������ ����� � ���� ������������. � �������� ��� ������, ����� ��������� ��, � �����. ��� ������������ ������ � "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.TargetCity)+". ����� �������� ������ ������������ � ������� ��������, � ������������ � ������ ����������� ����� ��� ������ ���� � �����������\n���� �� � ������ ��� ������, �� �� ������� ��� � �����, ������������ � ���� - ����� ��� ���� �� ���� �������� �������? � ���������� ������ � ���� ������� ������, � ���� ��� ����, ��� �� �����������.";
			link.l1 = "���! ������, ���� ������� �� ���? ����� ���������...";
			link.l1.go = "FalseTrace_11";
		break;
		
		case "FalseTrace_11":
			dialog.text = "��� ��� �������� ����, � � ����� ��, � �����, ����� ����, �� ����� ����� ���� � ���! ���� �������� ������� �� ����� �� ���, ����� �������� ������ ��� ��������� � ������, ���� � ��� �� ���... � �������. � �� ����� �� ������ ���� ������? �������� ���, ��������, � ������� � ��� � ����.";
			link.l1 = "�����, ������� ���. ��� ������������� ��� �������� ���� �� ����� �������� �����, ������������ �� ����� ����� ����. �� �� �������� ��� ��� ���-�� � ����������� ���� �������? ��� ������ �� �����������?";
			link.l1.go = "FalseTrace_12";
		break;
		
		case "FalseTrace_12":
			if (pchar.basenation == SPAIN || pchar.basenation == HOLLAND)
			{
				pchar.questTemp.FalseTrace.QuestCity = "Portobello";
				pchar.questTemp.FalseTrace.QuestShore = "Shore48";
			}
			else
			{
				pchar.questTemp.FalseTrace.QuestCity = "SantaCatalina";
				pchar.questTemp.FalseTrace.QuestShore = "Shore54";
			}
			dialog.text = "�� �� ����������, �������. ������ �� ������. ����� � ���� ���, �� ���� �� �������� ���� � ��������� � "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity)+", � ������ ��� �� ���� ��� ���������� ����������� ����������, ��� ����� ��� ��������� ����� ��������� ����������.";
			link.l1 = "����� ���������. � ������ �� ��� �� ������ ��� ��� '����������� ����������' ����� ������?";
			link.l1.go = "FalseTrace_13";
		break;
		
		case "FalseTrace_13":
			dialog.text = "������ ��� � �� ��� �� ����������. ��������� ��������� ��������. ���� ���������� �����, �� ����� ����� ����� - �� ������� � �����? - �� ���� �� ������ � ���� �������� ���������� � ������� �� ��������� � ����� ����������, ����� ���������� �������� ������� �������\n� ������� ����� ��� ������ ���� ��������� �����, ����� �� ����� ������������ � �������, �� �� ������������ �������� ����� �� ����������, � ����� ����� ����� �������� ������ ����������� � ��������, ��� ����� - �� ����, ���� �����, �� ��������, ����� ��������� ������������\n�����������, ������ �� ����� ������� �� ������� � ������� � �����-������ ����� � �������� ��������� ������. � ���� � ������ ���� ��� �������. �� ����� ����� ���� � ������ "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity)+". ��� ������ �� ������ ����� � �����, �� � ������� ���, � ����� ����� ����� ����� ������� ������������ �����\n�� ������� ����, ��� ����� �������� ��� �������� � �������� ���� ������. � ��� ��������� ������� ���, �� �������� ��������������, ��������� ����� ��� ���� ���, � ���� �� ����� ���� �� ����.";
			link.l1 = "���-�� ���� ������� ���������� ��������� '�������� � ��������'. ���� ��� �� ���� ��� ��������. ��� ��������, ��� �� � ������ �� �����?";
			link.l1.go = "FalseTrace_14";
		break;
		
		case "FalseTrace_14":
			dialog.text = "� ��� ��� ������� �����. ������ � ���� ��� ������� ��������. �� �� ������ ��� ������, �������.. ���... ���! ��������� �������...";
			link.l1 = "�����. ������, � ������� ��� ���, ��� �� ��� ������.";
			link.l1.go = "FalseTrace_15";
		break;
		
		case "FalseTrace_15":
			dialog.text = "�� �����������, �������. ����� ����� � �����-������ �������� �� ����� ������, ��� �� ���������. �� ���� ��������, � ��� �� ������ ���� ������, ����� ��������� �� "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity+"Gen")+".";
			link.l1 = "� ���� ���. � ������ ����������� � ������ � ��������. �� �������� �� �����, � �����, ��� ��� � ����� ����� ����� ������ ���������. ��, � ���� ������ �� ����������.";
			link.l1.go = "FalseTrace_16";
		break;
		
		case "FalseTrace_16":
			DialogExit();
			LAi_SetActorType(npchar);
			pchar.questTemp.FalseTrace = "TalkCabinWoman";
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "TalkSelf_Quest", 3.0);
			SetFunctionTimerCondition("FalseTraceSollyOver", 0, 0, 15, false);//������
			AddQuestRecord("FalseTrace", "5");
			AddQuestUserData("FalseTrace", "sCity", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity));
		break;
		
		case "FalseTrace_17":
			dialog.text = "��������, �������?";
			link.l1 = "��. ���� ������, � ������� ���� � ������ ��� �����. �� ������� ����, � � ���� ��� ������� ������, ��� ����������� ���� � ����� �������.";
			link.l1.go = "FalseTrace_18";
		break;
		
		case "FalseTrace_18":
			dialog.text = "��� ���? � ����������, ��� �� ��� ��������, ���. �������� ����� ����, ��� ������, ��� �� ����� � ����, ���������� � ���� ������� ����������� ����� ���. ������ ������ �� ��� �������, ���, ���?";
			link.l1 = "�� ���� ����. �� ����������� ����, ��������� � ��������� �������� �������� ��� �����-�� ���������! ������, ����� ���!";
			link.l1.go = "FalseTrace_19";
		break;
		
		case "FalseTrace_19":
			dialog.text = "���! �� ��� ������, �������... ������ � ���� ���� ��� �� ����� ������ ���� �����. �� �� ��������, ��� � ����� �����? ������ �� ����� ������ - �� � �. ��������-�� ���, �� ��� �� ��������!";
			link.l1 = "�� ��� ���? ��, �������, ���!";
			link.l1.go = "FalseTrace_20";
		break;
		
		case "FalseTrace_20":
			DialogExit();
			NextDiag.currentnode = "FalseTrace_21";
			chrDisableReloadToLocation = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(npchar, 10.0, true, "FalseTrace_capture");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "FalseTrace_21":
			dialog.text = "";
			link.l1 = "���-�� �����... ����� ������, ��������! ������! ������ �� ������� ������� � ������� � ����!";
			link.l1.go = "FalseTrace_22";
		break;
		
		case "FalseTrace_22":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			bQuestDisableMapEnter = false;
			RemovePassenger(Pchar, npchar);
			pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(npchar);
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
			Pchar.questTemp.FalseTrace.PrisonerAdamIDX = sti(pchar.GenQuest.LastQuestPrisonerIdx);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			LAi_SetPlayerType(pchar);
			RemoveCharacterEquip(npchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(npchar, GUN_ITEM_TYPE);
			RemoveCharacterEquip(npchar, CIRASS_ITEM_TYPE);
			sld = &Characters[sti(Pchar.questTemp.FalseTrace.PrisonerIDX)];
			ReleasePrisoner(sld); //���������� ��������
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
			DeleteAttribute(sld, "LifeDay") //���������� ��������
			GiveItem2Character(sld, "blade_10");
			EquipCharacterbyItem(sld, "blade_10");
			GiveItem2Character(sld, "pistol1");
			EquipCharacterbyItem(sld, "pistol1");//������� �� ��� - ��� ���� ��� ��������
			DeleteAttribute(pchar, "GenQuest.DontSetCabinOfficer");
			AddComplexSelfExpToScill(40, 40, 40, 40);
			AddQuestRecord("FalseTrace", "11");
			AddQuestUserData("FalseTrace", "sShore", XI_ConvertString(pchar.questTemp.FalseTrace.TargetShore+"Gen"));
			pchar.questTemp.FalseTrace = "AdamPrisoner";
		break;
		
		case "FalseTrace_23":
			pchar.quest.FalseTraceSollyOver.over = "yes"; //����� ������
			dialog.text = "��������� ���, ���, ��� ������� ��� ������� ��� ����! ���� ������ � ��� � �����, � �� ����� �� �������, ��-��, �������... ���! ��������� �������... ������ � ����� �����. ��� ������� ��� ��� ������� ���. ����� ������� ������������ ������ � ����� ������ ���-����-����-����� ��� ������� ����� �����������, � ��� ���������� �� �������� � ��������\n��� ������� ������������ - � ��� � ������ �� ������ ���� ����, �� �������� ����� ��������. �������� � ����� ����� �� ������� - ������� ����� ��������� ������, � ��� ������ ������ �� �������. �� ������� ��� ����� �� ����� - � �����, ��� �� ���� ���������� � ��������\n� ������ ��� ���� ����������. ������� ��� ��� � - �����, ���!";
			link.l1 = "� ���� �����, ����. �� ������ ����!";
			link.l1.go = "FalseTrace_Remove_exit";
			SetFunctionTimerCondition("FalseTraceBonanzaOver", 0, 0, 5, false);//������
			pchar.quest.False_Trace_4.win_condition.l1 = "location";
			pchar.quest.False_Trace_4.win_condition.l1.location = "Shore55";
			pchar.quest.False_Trace_4.function = "FalseTrace_SollyBonanza";
			ChangeCharacterComplexReputation(pchar, "nobility", -2);
			AddQuestRecord("FalseTrace", "14");
			AddQuestUserData("FalseTrace", "sCity", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity));
		break;
		
		case "FalseTrace_24":
			pchar.quest.FalseTraceSollyOver.over = "yes"; //����� ������
			dialog.text = "���! �������, ������ ����� �� ���������� � ���� �����? � �� ������ ��� - ��� ������� ���� ���� � ����� "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity+"Gen")+"! ��� �� ������ ������ �� ������ ������ ����� �������?";
			link.l1 = "�� ������, ����. ������� �� �����, ��� � ������ ����� ���������� � �� ������ ���? �� ���� �� ������ �������? �� ���� ��� � �������� ������ � ����� �����.";
			link.l1.go = "FalseTrace_25";
		break;
		
		case "FalseTrace_25":
			dialog.text = "���-�?! ���! ����� ��� ������ � ���� �����? �� ��� ��������, ����� �����?";
			link.l1 = "�� ����� ��������� ������� � �������� ������ ������ � ���� ��� ��������. � �������, ��� ������ ���, ���� ��� ������. ���� ����, ��� � �����, ������ ����� ������. ������� ��� �������� ����. ���. ��� ������ �� ����� ������, � ���� �����.";
			link.l1.go = "FalseTrace_26";
		break;
		
		case "FalseTrace_26":
			dialog.text = "���� �� ����! ��������... ��� ���� ��������� �����! �� �������� � ��� �� ����... � ��� �� ��� ��������� ������������ � �����, ��, ����? � ��� ��� �� �����, ���� ��������� ����, ������� � �� �����, ��� �������, ����� ������� � ���� ������������!";
			link.l1 = "�� ���� ������� ����, ��������. ���� ����������� ��� ��������. ������ � �������� ���� � ��, ��� ���� ����� �����!";
			link.l1.go = "FalseTrace_27";
		break;
		
		case "FalseTrace_27":
			dialog.text = "�� ��� ��, ���������, ��� �� ������, ������ �������!";
			link.l1 = "...";
			link.l1.go = "FalseTrace_28";
		break;
		
		case "FalseTrace_28":
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "FalseTrace_AdamDead");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "FalseTrace_abordage":
			dialog.text = "����! ������ ����� �� ����� �� ��� �������, ��������? ������ � ���� �� ������...";
			link.l1 = "�� ����������� �������, �������. ��� ����� �������� � �����, ������� �� ������. ��-�� ��� � �����.";
			link.l1.go = "FalseTrace_abordage_1";
		break;
		
		case "FalseTrace_abordage_1":
			dialog.text = "�����? ��-��! ����� ���� �� ������ ����� �������? � ���� ������ �����!";
			link.l1 = "��� �� ������, �������? � ��, �������!";
			link.l1.go = "FalseTrace_abordage_2";
		break;
		
		case "FalseTrace_abordage_2":
			dialog.text = "�������� - � ���� ��� �������� �����. ���� ������ - ������� �������� �����, � ��� ������������ � "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.TargetCity)+" �� ��������������� ��� ������ � �� ��������� ������.";
			link.l1 = "�� ���-�� �������, �������. � ���� ������ ���� ���� ������ ����� �������! � � ��������� ��� ���������, ����� ����, ��� �� �������� ���� ��������...";
			link.l1.go = "FalseTrace_abordage_3";
		break;
		
		case "FalseTrace_abordage_3":
			dialog.text = "� �� ����, ��� ������ ���� � �������, �� ��� ��� ������ ����... � �������� ������� � ������. ��� ��� �����. ������ ������ ���� �������� ����� - ��� �����.";
			link.l1 = "��������? �� �� ���! ��� ��������� �� � ����! �������� ���� �������� � ���������, ��� � ������� ����, ��� ����!";
			link.l1.go = "FalseTrace_abordage_4";
			link.l2 = "����� ������, ��� �� ������� ������������. �����, � ����� �������� �� ���� �����... ��, ������, �������� ��������� �������� � ����!";
			link.l2.go = "FalseTrace_abordage_5";
		break;
		
		case "FalseTrace_abordage_4":
			DialogExit();
			pchar.questTemp.FalseTrace.KillCaptain = "true";//������� ������
			Lai_SetPlayerType(pchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "FalseTrace_AfterFight");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.FalseTrace.CapName = GetFullName(npchar);
			ChangeCharacterComplexReputation(pchar, "nobility", -3);
		break;
		
		case "FalseTrace_abordage_5":
			DialogExit();
			pchar.questTemp.FalseTrace.CapPrisoner = "true";//������� ������
			Lai_SetPlayerType(pchar);
			DeleteAttribute(npchar, "DontRansackCaptain");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "FalseTrace_AfterFight", 3.0);
			pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(npchar);
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
			pchar.questTemp.FalseTrace.CapName = GetFullName(npchar);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
		break;
		
		case "FalseTrace_wife":
			dialog.text = "�� ����� ���, �������! ��������! �������! ���������� "+pchar.questTemp.FalseTrace.CapName+"!";
			link.l1 = "��� ��� ��� �� ����? ������ �� �������, �������?";
			link.l1.go = "FalseTrace_wife_1";
		break;
		
		case "FalseTrace_wife_1":
			dialog.text = "������ ��� � ��� �� ���� ������! ������ ��...";
			link.l1 = "� �� ����, �������! �� ��������� ������, ������� ����� ������ ����� � ���������, ����� � ����� �������� ���� ������ �� ����� ���������!";
			link.l1.go = "FalseTrace_wife_2";
		break;
		
		case "FalseTrace_wife_2":
			dialog.text = "��... �� �� �������� ������� ���� �� �������!";
			link.l1 = "�� ��� � ���� ��������� �� ���� �����. ������ ������� ���� �� ����, � ��� ���� �������� �����... ��? ���� ������? ����� ���� �� ��� �������! �� �����, � ����� ���� � �� ��� � ��� �� �����, ���� ������ ����� ���� ����...";
			link.l1.go = "FalseTrace_wife_3";
		break;
		
		case "FalseTrace_wife_3":
			DialogExit();
			pchar.quest.False_Trace_AfterBattle.over = "yes";
			pchar.quest.FalseTraceGaleonOver.over = "yes";
			if (CheckAttribute(pchar, "questTemp.FalseTrace.CapPrisoner")) AddQuestRecord("FalseTrace", "");
			else AddQuestRecord("FalseTrace", "");
			sld = characterFromId("Mugger");
			DeleteAttribute(sld, "HalfImmortal");
			RemovePassenger(Pchar, sld);
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			DoQuestCheckDelay("LAi_ReloadBoarding", 4.0);
			bQuestDisableMapEnter = true;
			pchar.questTemp.FalseTrace = "TalkCabin";
			AddQuestRecord("FalseTrace", "4");
		break;
		
		case "FalseTrace_wife_4":
			dialog.text = "��.. ��... ��� �� �������� � ���?";
			link.l1 = "��� ��� ��� �� ����? ������ �� �������, �������?";
			link.l1.go = "FalseTrace_wife_5";
		break;
		
		case "FalseTrace_wife_5":
			dialog.text = "������ "+pchar.questTemp.FalseTrace.CapName+"! �������� ��� - �� �������� ����� ���?! ��...";
			link.l1 = "��������, �������, ���� �� � ����� ��� ����� - � ��� �� ��� ������. � ��� �� ���� ������� � �����, �����, �����, � ��� ������ ��� ���� �� �����... ������ ����� ��������. � ���� � ����� ������� ������ �� ��� �������, � �� �����, � ����� �� ��� � ��� �� �����, ���� ������ ����� ���� ����...";
			link.l1.go = "FalseTrace_wife_3";
		break;
		
		case "FalseTrace_wife_6":
			if (CheckAttribute(pchar, "questTemp.FalseTrace.KillCaptain"))
			{
				dialog.text = "��� ��� �� ���� ��� �����? ������� ������, ��� �� �������? �� ������� ��� �����, � �...";
				link.l1 = "�����, �������. ����� ������ ���� ������� �� ����������. � ������ ���� ��������� ��������, ��������� ���������� �� ������ � ������ ������ ����, � ������ �������.";
				link.l1.go = "FalseTrace_wife_7";
			}
			else
			{
				dialog.text = "��� �� �� ���� ������? ��� "+pchar.questTemp.FalseTrace.CapName+"? �����? ��� ����� �����?";
				link.l1 = "���, �������, ����� ��������� ���� ����� ������������� ��������, � �� ��� ���� ���� ������ ����. ��������� ���� ����, ������� ����, ����������, ����� ���������.";
				link.l1.go = "FalseTrace_wife_20";
			}
		break;
		
		case "FalseTrace_wife_7":
			dialog.text = "������� ���? �� ������ �������, ��� � ������� � ���, ��� �� ������ �� ���� ����� � ����� �����... �������? ������ "+pchar.questTemp.FalseTrace.CapName+", ��� �� ��� ������? �� ������������, �� �� ��� �������� �����...";
			link.l1 = "���, �� ����� �� ����? ��� ���, ����� ��������� � ��������� �� ������?";
			link.l1.go = "FalseTrace_wife_8";
		break;
		
		case "FalseTrace_wife_8"://���� ����������� - �����
			dialog.text = "";
			link.l1 = "�������? ������������. �������� �� ���� �������! � �������� ��������� �� ��� �����, ������ ��� � ���� ���� ��������, ��� ��� ����� �������� ���� �������. � �������� ��� � ������� �� ����� �������.";
			link.l1.go = "FalseTrace_wife_9";
		break;
		
		case "FalseTrace_wife_9":
			dialog.text = "��! ���?! ����? ��� ��? ������� �����?";
			link.l1 = "����, ��� ��� ���� �������... ��������. ��� ������, � ��� ��� ��� ���� ����. ��� � �������, ���� ������ - ������������� ���� ���?";
			link.l1.go = "FalseTrace_wife_10";
		break;
		
		case "FalseTrace_wife_10":
			dialog.text = "��. � ������������� ���� ����� �������. � ������ ��������, ��� � ���� �������� ��� ��������� ��������... ��� ��� �� ��� �����, ����� ��������� ����?";
			link.l1 = "� �����, ���������� ������ ���. ���� ������ ��� � ����� �������, ����� � �������� ������ '"+pchar.questTemp.FalseTrace.ShipName+"', � ��������� ����� ������� ����. �������� ���� ����� �� ��� ��� ������ ����� � ����� ��������...";
			link.l1.go = "FalseTrace_wife_11";
		break;
		
		case "FalseTrace_wife_11":
			dialog.text = "�... ��� �� �� �����? ��� �� ��� ������?";
			link.l1 = "�� �����, ����� ��� �������� ���� ��������� � ����. � �������� ����������� �� ��, ��� ���� ���� � �����������, �� ��������� ���� ����������� � ������ ������ �����. ��� ������ ����� ��������� ��� ����� � "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity)+".";
			link.l1.go = "FalseTrace_wife_12";
		break;
		
		case "FalseTrace_wife_12":
			dialog.text = "���...(������) � �� ���� ������������ � ����� ��������! � ��������� ������� ���, ����� ������� �� ���� � ������� �����, �� �� ��� ����� ���� �����... �������! ������! ��� ���������!";
			link.l1 = "����, ��������, ���������... �� ���� ���-���� ���� ���. � �� ������, ��� ����� ����.";
			link.l1.go = "FalseTrace_wife_13";
		break;
		
		case "FalseTrace_wife_13":
			dialog.text = "(������ �����) ��� ���? � �� ������, ��� ��, ��� ���? �� ������ �����������, ���������, � ����� - ����� �������� ������ "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.StartCity+"Gen")+"! �� ������ � ������ ��������, � � ��� ���� - �� ������ ��� ������... ���������!";
			link.l1 = "��������, �� ������� �� �� ������ ����� �����, ����� �������� �� ���� �����?";
			link.l1.go = "FalseTrace_wife_14";
		break;
		
		case "FalseTrace_wife_14":
			dialog.text = "�������� �� ��� ������. � ��� ������� �������� ��� ����� ����� �����������... �� ����� ��� ����������. � � �� ���� ��� ������ ���� ������, �� ��, ��� ���� � ���, ��������� - �� ����! �������� ����� ����, ��� �� ����������� ��������� �� ������!";
			link.l1 = "��... � ��� �� �� ������ ��������� � ����� ������, ����� �������?";
			link.l1.go = "FalseTrace_wife_15";
		break;
		
		case "FalseTrace_wife_15"://���� ����������� - �����
			if (CheckAttribute(pchar, "questTemp.FalseTrace.KillCaptain"))
			{
				dialog.text = "��� ������? � � ��� ����, ��� ������. ��, ��������� ���������� ������� ����� ����, ����� ���� �� ����, ����� �� � ��� �� ��������� ��������... ������������� ��������, ������� ������ �� ��� ���������... �������� ���� ����, �������. ������ �����. ������ ����� � ���� �� ������. � ���� ������, ��� ����� ������� ��� �������, � ���� ������� �� ��� ����\n� ����� �� �������� ���, � �������� ���, ��� �� ������ ���� ���������, ���������� ���������� � ���������. �� �� �����, ��� ��� �������� ��� ������, ��-��! ������ ������� ����������� �� ���, � ���� �� ��������...";
				link.l1 = "���! � �� ��������, ��������, ��� � ��������!";
				link.l1.go = "FalseTrace_wife_16";
			}
			else
			{
				dialog.text = ""+pchar.questTemp.FalseTrace.CapName+"... ������� �������. �� ������� ���. ���������� � ���, ����� ���! �� ���-������ ��������� ��� �� ���� ����� � �������! �� ���������! �... � �� ���� ��������� � �����, ��� ���� ������ "+pchar.questTemp.FalseTrace.CapName+" - ���! ������ ���, �� ��������� ���� �����, ����� ��������!";
				link.l1 = "��. ���������, � ��� �� ����� ��� ���������� ��� �������? ����� �� ���� � ���� �������� � � �������, � ��������� ������ ����� ��� ���� ����������...";
				link.l1.go = "FalseTrace_wife_21";
			}
		break;
		
		case "FalseTrace_wife_16":
			dialog.text = "�� ��� �������� � ����������, �������. ������������� � "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity)+", ��� ��� ���� � ������, �� ���������� �� � �����, � � ��������� �����. ��� �� ������ ������ �� �����, � �� ���������� ��������\n� � ����� �� �������� ��� � �������. �������, ��� �� ���, � ��������� ����� ������������� ����������. �� ������ ������, �������� ��� � ��� ������ ���������, ��� ����� � ��� ����������� ����������� ������ �����. ������� �� ��� ������? �� ������� ��� ��� ��, ��� ������� � ������ ���, ��� ��������� ���� ��� ���� ���������� �����\n��� �������, �������?";
			link.l1 = "�� ��... ������� �������: ��� � ���� - ���� ������. ������ � �� ����, ��������, � ����, ��� �� ��� ����� - ����� ����... ���� ���� ��� ����� ��� ������, ���� ������ ��� ��������, ����� �� ����� � ��������� ��� �����, ������ � �������, � ��������� � �����-�� ��������... ������! ������ ��!";
			link.l1.go = "FalseTrace_wife_17";
			link.l2 = "�������� ���������, ������� �������� ���� �������� � ������������ � ����� �����. ��� � ��������, ��������, ��� ����� ��� ��� ����. �� ���� �� ���� �������� - �������, ��� ������ ���� ���� � ������, � ����� ���� ���� ����� � ���. � ������ ������. ������! ������ ��!";
			link.l2.go = "FalseTrace_wife_19";
		break;
		
		case "FalseTrace_wife_17":
			dialog.text = "�� �� ���� ���������... �������, ��� �...";
			link.l1 = "������! ���������� � ��� ������ � ���� �� �������� �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity+"Gen")+"!";
			link.l1.go = "FalseTrace_wife_18";
		break;
		
		case "FalseTrace_wife_18":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			AddQuestRecord("FalseTrace", "6");
			AddQuestUserData("FalseTrace", "sCity", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity));
			AddDialogExitQuestFunction("SetCheckForSolly");
			chrDisableReloadToLocation = false;
			bQuestDisableMapEnter = false;
			DeleteAttribute(pchar, "GenQuest.DontSetCabinOfficer");
		break;
		
		case "FalseTrace_wife_19":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			AddQuestRecord("FalseTrace", "7");
			AddQuestUserData("FalseTrace", "sCity", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity));
			AddDialogExitQuestFunction("SetCheckForKillAdam");
			chrDisableReloadToLocation = false;
			bQuestDisableMapEnter = false;
			DeleteAttribute(pchar, "GenQuest.DontSetCabinOfficer");
		break;
		
		case "FalseTrace_wife_20":
			dialog.text = "����� ��� ����? ��� �� �������� ������� � ����? ����� �� ��������� ���� �����?";
			link.l1 = "�� ���� ��� � ����� ������ ����� �������, ��� ��� ��������� ������� �������� ���� ��� ������?!";
			link.l1.go = "FalseTrace_wife_8";
		break;
		
		case "FalseTrace_wife_21":
			dialog.text = "������ ������ �����? �� ������ �����, ����� ���������? �� �� ������� ���, ��� ������� � ���� ��������, ��� ��������� ���� ��� ���� ���������� �����! �� ������ �� ���� �� ��������, � ���� ��� �� ����� �������! ���������� � ����� ���������!\n"+pchar.questTemp.FalseTrace.CapName+" - ��������� ����������, �� �� ������ � �� ������� �����!";
			link.l1 = "�� ������� �� ����, �������. ��� �� � ��� �������� � ����� ���������. �� ���� � ������ �����, � �� ����� - ������ �����. � ���� ���� ���� ������� - ������ ���� �� ���� �����, � �� ��������, ��� �������� �� ����... ������! ������ ��!";
			link.l1.go = "FalseTrace_wife_23";
			link.l2 = "������� ������, � ����� � ���� ����� ��� �������... ��������, ����� ���� ���������� � ����� �����. �����. �������� � � ����� ���������, ���������, ��� �� ������ �������. � �� ������ ����... ������! ������ ��!";
			link.l2.go = "FalseTrace_wife_24";
		break;
		
		case "FalseTrace_wife_23":
			dialog.text = "�� ��������, ������������ �������! �������, ��� �...";
			link.l1 = "������! ���������� � ��� ������ � ���� �� �������� �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.QuestCity+"Gen")+"!";
			link.l1.go = "FalseTrace_wife_18";
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], true);
		break;
		
		case "FalseTrace_wife_24":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			AddQuestRecord("FalseTrace", "8");
			chrDisableReloadToLocation = false;
			pchar.questTemp.FalseTrace.Prisoner = "true";
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], true);
		break;
		
		case "FalseTrace_wife_25":
			dialog.text = "�� ��� � ��... ���������� "+pchar.questTemp.FalseTrace.CapName+" �������, � � �������-�� ���� �������� ��������� � ������� ���� ������...";
			link.l1 = "� �������� ���� ����� ������, ��������. ������ ���� �������.";
			link.l1.go = "FalseTrace_wife_26";
		break;
		
		case "FalseTrace_wife_26":
			dialog.text = "�������, �������. ��� ���, ����� ����, ��� ������, ��� �� ������, ��� ��������. �������� �������, �� �� ������ ���� ������������ ���������. �� ����������� ������, � ������� �������� � �����������. ������� �� ��� ����� ����� - � ������� ��� ������� �� ����.";
			link.l1 = "����� ���������... � ��� �� ���?";
			link.l1.go = "FalseTrace_wife_27";
		break;
		
		case "FalseTrace_wife_27":
			dialog.text = "�� ��������� �������� � ������� ���������. �� �����.";
			link.l1 = "���� ����-�-������! �� ��������� �� �������!";
			link.l1.go = "FalseTrace_wife_28";
		break;
		
		case "FalseTrace_wife_28":
			dialog.text = "��������, ���. ��� �� ������� ����� ����� ����... ���� �������. � ������ ���. ��������, �������.";
			link.l1 = "�������... ������, ��������, ���� �������, �� ��, ��� �������� ���� ���. �������, ������ ��������� ����� ��������� ���� �� ������� �������� ���� ���������. � �������� �������...";
			link.l1.go = "FalseTrace_wife_29";
		break;
		
		case "FalseTrace_wife_29":
			dialog.text = "��� �� ����� ���� ���������, �������. �� �������, ��� � ��� �������, � ���������� ��� ���, ��� �� ������. ��������, � �������� ���� ������� � ���� �����...";
			link.l1 = "������, ��������.";
			link.l1.go = "FalseTrace_wife_30";
		break;
		
		case "FalseTrace_wife_30":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15);
			LAi_LocationDisableOfficersGen(pchar.questTemp.FalseTrace.QuestShore, false);//�������� �������
			LAi_LocationDisableOfficersGen("Mayak7", true);//�������� �� �������
			locations[FindLocation("Mayak7")].DisableEncounters = true;//���������� �������
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			pchar.quest.False_Trace_7.win_condition.l1 = "location";
			pchar.quest.False_Trace_7.win_condition.l1.location = "Mayak7";
			pchar.quest.False_Trace_7.function = "FalseTrace_AdamTreasure";
			AddQuestRecord("FalseTrace", "23");
		break;
		
		case "FalseTrace_wife_31":
			dialog.text = "������� �������! �� ���������� ����� ���� ��������! ����������!";
			link.l1 = "�� ������� ������ ��������, �, ��������? ������� �� ������ ����� ������� ����!";
			link.l1.go = "FalseTrace_wife_32";
		break;
		
		case "FalseTrace_wife_32":
			dialog.text = "�� ����� ����� �������. ������� �� �������, ��� � ����� ��������� ��� ����� ����� �������� ������ �� ���� �����?! � �� ������, ��� ������ ����� ���� �������������? ���! �� ��� �� ���� ��� ������ ������. � ������� ����� ������� - �� �������� ��� � ���� ������ �� ���!\n� ������ ������� �� ����, ��� ������.";
			link.l1 = "� ������� ����, �������, ��� �� ����������� ����� �������, ���� �������� ����? �������� ������! ������� �� ������ ����������. ��� ��� �������� ����������...";
			link.l1.go = "FalseTrace_wife_33";
			link.l2 = "��� ���� ����, ��������. ����� ����� �� ������ ���� �� �����. � ������������ ���� ����� ������ - �� ���������� �� ���� ��������. �����, ������� ������ ������ ������ ���� � �������� �� ���������. � ��� ��� ���� �����...";
			link.l2.go = "FalseTrace_wife_35";
		break;
		
		case "FalseTrace_wife_33":
			dialog.text = "��� ��� ����� ��������, ������! ������! ������ ��...";
			link.l1 = "�������, ������...";
			link.l1.go = "FalseTrace_wife_34";
		break;
		
		case "FalseTrace_wife_34":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_ActorAnimation(pchar, "shot", "FalseTrace_CaterinaKilled", 1.0);
		break;
		
		case "FalseTrace_wife_35":
			dialog.text = "�� ���� ��� �������! ���� ��� ������� �������� � �����! ����� ���...";
			link.l1 = "������, ��������.";
			link.l1.go = "FalseTrace_wife_36";
		break;
		
		case "FalseTrace_wife_36":
			DialogExit();
			sld = characterFromID("FalseTraceWife"); 
			sld.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "goto", "goto33", "none", "", "", "", -1);
			LAi_SetPlayerType(pchar);
			chrDisableReloadToLocation = false;
			LAi_LocationDisableOfficersGen("Mayak7", false);//�������� �������
			locations[FindLocation("Mayak7")].DisableEncounters = false;//���������� �������
			AddQuestRecord("FalseTrace", "25");
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			OfficersReaction("good");
		break;
		
		case "FalseTrace_Bandits":
			dialog.text = "�-�, ��� � ������ ������ �����! �������� ���� ����� - ���� ��� ������ ���������� ������ ���������!";
			link.l1 = "���? ��������?! ��� �� �����?";
			link.l1.go = "FalseTrace_Bandits_1";
		break;
		
		case "FalseTrace_Bandits_1":
			dialog.text = "��? �� ������ ����� �������, �������� �� ����. �� ��� ������ ������ ��������. ������ ��� ����� ������� �, "+GetFullName(npchar)+", � � ������� ���� �� �������� ����� ������� ����� � ��������, � �� �������, ������� �� ������ ��� ��� �����.";
			link.l1 = "�������? ��� �� ������? ����� �������?";
			link.l1.go = "FalseTrace_Bandits_2";
		break;
		
		case "FalseTrace_Bandits_2":
			dialog.text = "����� ����, ��� �� ����������� � ������, ��������� ���� ������ � �����, �� ����� � �������� ����� �� ��� ���� ��������, ��� ���� ������ ���� ����������, � ����� ������ ���������� ������� �� ��������� ������ �� ������ ������\n�� ��� �������� ����, � ������ � ��� �� �������, ����������� ��������, ��� ��������� �� ������ �������� �������������. �� ��� ������� ���� ������� �����, ������ ������ ���������. � ��� �� ������, ��������!";
			link.l1 = "��-��! ����� ��������... ������, ��, � ������������� ���� �����, �� ������ ��� �� ������� ��� ����������� ���� - ��� ���� ����� �� ������ �� ���������. � �� ��� ��� � ���������� ���, ��� ��������� ������...";
			link.l1.go = "FalseTrace_Bandits_3";
		break;
		
		case "FalseTrace_Bandits_3":
			dialog.text = "�� ��������� �� ������ �����, �������! � ����� �� ����� ��� ������ � ���? ����� ��� ������� ��� ������� ���� �� �� ������� �����, ���� �� �� ����� ����? �� �� ����� ������, �� ����� ���� ������! ��������� ����� �� ������ ����!\n�� �������, ��� �� ����� � ������, � ��� ��� �� �����, ��� ���� ����� "+GetFullName(npchar)+", � ��, ��� ������ ���� ��������� ���, ����!";
			link.l1 = "�������... ������, ��� ���� ����� ������� ����������� �� ���� ��������... � ���, �����������!";
			link.l1.go = "FalseTrace_Bandits_4";
		break;
		
		case "FalseTrace_Bandits_4":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			DialogExit();
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("Adam_bandit_"+i);	
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "FalseTrace_BanditsAfterFight");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "FalseTrace_Remove1":
			dialog.text = "�� � ������� �� ��, �������! ��������� ������, ������ �������... ��� � �������� � ����. ��������!";
			link.l1 = "������, ����.";
			link.l1.go = "FalseTrace_Remove2";
		break;
		
		case "FalseTrace_Remove2":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 15);
		break;
		
		case "FalseTrace_Remove_exit":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "FalseTraceWife_Remove", 15);
		break;
		
		case "FalseTrace_Remove2":
			dialog.text = "� �� ������������ ���, ������� - � ������ ��� ������! ������ ����� ����� ��� ����� ���� ������. � �� �������, ��� �� ����� �������. ��������!";
			link.l1 = "�� ��, ������� � � ���� �����. ������, �������, ������ �� ���������� - �� ��������� ���� �������.";
			link.l1.go = "FalseTrace_Remove_exit";
		break;
		
		case "FalseTrace_Solly":
			dialog.text = "���! �� �������-��, ��� ������ �����, ���� ������� ��������, ���������... ������... � ��� �����? ���-�� �� �����...";
			link.l1 = "����� �� �����. � �� ����... ��� ��� �� ��� ���� �������� ������, ��� ���������� ����� �� ���� ������.";
			link.l1.go = "FalseTrace_Solly_1";
		break;
		
		case "FalseTrace_Solly_1":
			dialog.text = "����! ��, ��� �� ��� ���������, ��� ����! ������, �� ������! � ���!";
			link.l1 = "��� ������ ��� ����� �����, ������!";
			link.l1.go = "FalseTrace_Solly_2";
			AddDialogExitQuestFunction("FalseTrace_SollyBonanzaAdd");
		break;
		
		case "FalseTrace_Solly_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			DialogExit();
			for (i=1; i<=6; i++)
			{
				sld = characterFromId("FTEnemy_crew_"+i);	
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "FalseTrace_SollyAfterFight");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "FalseTrace_GoldShip":
			dialog.text = "�� ��� �������, ��� �� ��������������, �������. �������, ��� �������� � ����� ���������. ������ ����� �� ������������ - � ������� ��� � �������� ���� � �� ������� �� ��������.";
			link.l1 = "���� ���� ���� �������. ��� ��� ������ ������ �������� � ����� �������?";
			link.l1.go = "FalseTrace_GoldShip_1";
		break;
		
		case "FalseTrace_GoldShip_1":
			if (sti(pchar.basenation == HOLLAND) || sti(pchar.basenation == SPAIN))
			{
				pchar.questTemp.FalseTrace.ShipNation = ENGLAND;
				pchar.questTemp.FalseTrace.ShipCity = "PortRoyal";
			}
			else
			{
				pchar.questTemp.FalseTrace.ShipNation = SPAIN;
				pchar.questTemp.FalseTrace.ShipCity = "Maracaibo";
			}
			dialog.text = "��-��, �������. ���, �������� ������� �� ������������ �����... ���... ����� ����������-������������ ���� �� "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.ShipCity+"Gen")+" ������ ������� ������ � ������ ������� ����������� ���� � ���������� � ������. ��� ����� �������� ����� �������������, �����, ������ ��� ������\n��� ��� ������������� ��� ������� - ������ �������, �� ��������. ���� ������, �� ���������� - � �����, ��� ���� �� �������� ��� �������������... �� ��� ������ ��� ����� ��������� �� "+XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.ShipCity+"Gen")+" � �������� ������\n������� - ���� ���� - ������� ������ � ����� �������� �������������. ��� ������� � ��... ��������� - � ����� �����.";
			link.l1 = "�������... �� ��� ��, "+pchar.questTemp.FalseTrace.CapName+", ��������. ��������, � ������ �������� ��� ����� � ������� � ���������? �������, � ��� ��� ����� ������. ����, ��� �� ������������� � ���� ��� ����� ��������� ���������������.";
			link.l1.go = "FalseTrace_GoldShip_2";
		break;
		
		case "FalseTrace_GoldShip_2":
			dialog.text = "�������, �������. ��� � ��� ������� - �� �� ������ ������� ������������. �������, �� ������ ������ ��� ����, ��� ������� �������� �������� ������� ������ ������, ������ ����������. ��������� ���� ������ �� ����� ����� ������� - �� ��� ������ �������� ������� �����.";
			link.l1 = "� ������� ��� ������ �������. ��, � ������ - ��������!";
			link.l1.go = "FalseTrace_GoldShip_3";
		break;
		
		case "FalseTrace_GoldShip_3":
			DialogExit();
			locations[FindLocation(pchar.questTemp.FalseTrace.TargetShore)].DisableEncounters = false; //��������� �������
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "FalseTraceDouble_Remove", -1);
			pchar.quest.False_Trace_6.win_condition.l1 = "Timer";
			pchar.quest.False_Trace_6.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.False_Trace_6.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 14);
			pchar.quest.False_Trace_6.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
			pchar.quest.False_Trace_6.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 14);
			pchar.quest.False_Trace_6.function = "CreateFalseTraceGoldShipOnMap";
			AddQuestRecord("FalseTrace", "19");
			AddQuestUserData("FalseTrace", "sCity", XI_ConvertString("Colony"+pchar.questTemp.FalseTrace.ShipCity+"Gen"));
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
