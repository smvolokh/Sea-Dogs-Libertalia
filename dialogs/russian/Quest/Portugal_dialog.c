void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
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
		dialog.text = "����� ���. �������� �� ���� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
		link.l1 = "����������� ������!";
		link.l1.go = "exit";
		break;
		
		case "Avendel_tavern":
			pchar.quest.Portugal_BeginOver.over = "yes";
			dialog.text = "�, ��� ���� ������� �����! � ������ ����� �������� ��������, ��� ������������ ���� �� ��� �������, ��! �������� ������?";
			link.l1 = "��� ������ � ������ � � ����� �����,  ������� ��������... ��, ���������. ��� ������� ���� ��������� � �������, ����� � ������ ��� ��������� ����� ���������� � ������.";
			link.l1.go = "Avendel_tavern_1";
		break;
		
		case "Avendel_tavern_1":
			dialog.text = "������ ��� �... ��, ���������! �������, ��� �� ����� ��� �� ���� ���������? �� �������? ��� ��� � ������� � �������� ���� � ��������, �� ����� �� ������������ �����?";
			link.l1 = "����������. ��� ��� � �������. �������, �� ���� ��� ������ ���������, ����� �������, ������ �������.";
			link.l1.go = "Avendel_tavern_2";
		break;
		
		case "Avendel_tavern_2":
			dialog.text = "��������! ���������, � ����� ���! �� ��������� ������� ���������. � ��� ��������� �������� ������ ����� � � ������ �� ����, � ������ ������� ������ �������� �������� ��� �� ������ ������ � ����. ���������� ��� ������.. ��, �����������! ���� �� �������� �� ���� ���� ����, � ������ ��� � ����\n���� ���� ����... ���������� ����, ���� ��� ������ �� ��� �����! ������� ����� ��������� ���������� � ��������, �������, ��� ��� ���!\n����� ���� ��������� ����, ����� ���� ������ ����� �����, � �� ������� ���������� �������, ��� ������ ������� ��� ������� ������, ���� �� �������, �����, � �������� ������� ��������! ��� �������? �� ��� � � ���, ��� ������... ��!";
			link.l1 = "���������, ������� ������� ����... ������� � � �� ����� ��������� ����� ��� ��. ����� ������, ��� ������ �������� �������� ��������. ��������!";
			link.l1.go = "Avendel_tavern_3";
			link.l2 = "����������? � � ������ �������� ����� ���������� �������, ���� �������������� ��������?";
			link.l2.go = "Avendel_tavern_4";
		break;
		
		case "Avendel_tavern_3":
			DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.questTemp.Portugal = "end";
		break;
		
		case "Avendel_tavern_4":
			dialog.text = "���������� ����, �������! ��, ���� ��� ���������� �� ���� �����, ���� ���! � ������ ������! ������ ���� � ���� ���, �� ��������� ��� ��������� ������� ���� ����� ���������, ��� �������� �� �����! �� ���� �� ���� ����� � ���� ��� ������ ����� ���������� �����, �������� ��� �������! �� ��? �� ������ �� �������!";
			link.l1 = "�� ���� ������� ����� ���������. ��������.";
			link.l1.go = "Avendel_tavern_3";
			link.l2 = "�����, �����... � ������ �������� � ���� ����. �� ������ � ����, ����� � �������, �� �� ������� ���� ��� ������ ��������� �� ���, ������� �� ����.";
			link.l2.go = "Avendel_tavern_5";
		break;
		
		case "Avendel_tavern_5":
			dialog.text = "�� ���� ����� � � � ��� ��� �������. � �� ��������, �������! �� �����������! �������������, ��� ������ ���� ��������� ���� ����� ������, � �� ��� ����... ��! ���������! �� �� ���������� �� ������!";
			link.l1 = "������, � ����� ����, �� ������, ����� �������, ����� ���� '�����������' � ������ ���� ���������.";
			link.l1.go = "Avendel_tavern_6";
		break;
		
		case "Avendel_tavern_6":
			DialogExit();
			pchar.questTemp.Portugal = "HostressMoney";
			Nextdiag.Currentnode = "Avendel_repeat";
		break;
		
		case "Avendel_repeat":
			dialog.text = "�������, ������������� �������� - ��� �� �������� �������� ��� ���� ����.";
			link.l1 = "��-��, ������ ����� ���� ���� � �����.";
			link.l1.go = "exit";
			Nextdiag.TempNode = "Avendel_repeat";
		break;
		
		case "Avendel_tavern_7":
			pchar.quest.Portugal_BeginOver.over = "yes";
			dialog.text = "�� ���������, �������! ���� � ��������� ������, � ��� ��� ������! ��� ��� ����?";
			link.l1 = "���� �������, ������ ���� �����, �����. ���������� ���� �������, � ����������, ����� ��� ��������� ���� ������� ��������!";
			link.l1.go = "Avendel_tavern_8";
		break;
		
		case "Avendel_tavern_8":
			dialog.text = "�� ������������, �������! �� ������, ��� � ������� �� ��������? ������, � ��� ��. ��� ������ �� �����. ��������, ��� ������, �� ����� ��� ����������, �� ��� ������� �����������, ��� �. � �� ��������� ���� � ������� ��� � ������� �����������, ������� �������� ������� � ���� ������...";
			link.l1 = "� ����� ����������� �������, � ��� ����������. � ����, �����, �� ����������� ��� ��������.";
			link.l1.go = "Avendel_tavern_9";
		break;
		
		case "Avendel_tavern_9":
			dialog.text = "��-��, �������... "+GetFullName(pchar)+", ���������? ������, � ���� ���-��� � ��� ����������. ��, ����������� ���, ���� ��� �����. ������� ����� ��� - ���������� ����������?";
			link.l1 = "���� ����������? �������, ��� � ��� �� ������, ����� �� � �����! �����, ������ � ��������, ��������� ��� ��������, � ������ �� � ����� �������?";
			link.l1.go = "Avendel_tavern_10";
		break;
		
		case "Avendel_tavern_10":
			dialog.text = "����� ������������ ������� ������! � ���������� ��� ��������� ������� ���� - ����������� �������� ���� �� ��� ������ �������� ����. �� � �� �������� � ������� ���. � �� ��� ����� �������� ������� �����, ������, � �������� ����, ��� ���������� ������, ����� ��� �������, �������� � ��� ������ � ����� �����!";
			link.l1 = "��������� � ����, ��� �� ���-�� ������. � ����� ������, ����� ��� �� ����� ���� �����? ��������� ��������, ��� �� ������ ���� �� ���!";
			link.l1.go = "Avendel_tavern_11";
		break;
		
		case "Avendel_tavern_11":
			dialog.text = "� �� ����� �������, � �� �����! ������, ������� ������ � ����� ��� �����, �������� ������� � �� ������� ��� ��������, ����� ������������ ������ �� ����� ������� ��� �� ��������� �����. ��� ���, ������� ��� ������ ���� ��� ����, �...";
			link.l1 = "�����, ��� �������� �� ������! � ������ ����, ��� �� ���� �������� ���� ������, �� ������ � ������! ������� � ������ ���� ������ ����� ������� ���, ��� ������� �������� �� �������!";
			link.l1.go = "Avendel_tavern_12";
		break;
		
		case "Avendel_tavern_12":
			dialog.text = "�� �������� ��, �������! ����������: ����� ���� �������, � ����� ���� �������, � ����� �� � ��� � '����������' - ���������� ������� �����������! � ���� �� ��� ������� ���-�� � �������� ��������! ���������, " + pchar.name + ", ���������� �����, � �����������! ����� � ��� ��� �����, � �� �����, ��� ��������, ��� ����� �� ��������� ������!\n���� �� ����������, ����� ��� �������, ������ ���� ��� �������, �� ���� � ���� ��� ���� �� ������! � �� ���� ������, � ����� ������� � ��������� ����� �������! �������� ���� ���������� ��������, � �� ������, ��� �� ��������! ������� ��� � ������ �������!\n� ��� ������ �����������, ������������ ��������, ������� � ��� � �������!";
			link.l1 = "���, �����, � ���� �������� ��������. ���� ���� �� ����, � �� ���� � ���� �����������. ������.";
			link.l1.go = "Avendel_tavern_3";
			link.l2 = "� ��� ��� ��� ���������. �� ������, ��� �� ��������? ���� ��� �������, ���� ������� ����� � ������� ������!";
			link.l2.go = "Avendel_tavern_13";
		break;
		
		case "Avendel_tavern_13":
			dialog.text = "���, �������, � �������� ������� �� ����� ��������. ���� �� ���������� ��� ���� �������... ��-�! �� � ������ �� ������� �� ������ �������� ����� � ��������� �����, � ������! ���������, ����������� ������� ��� ��� ���������! ����� ������������ ���� �������� ��� � �����, ����� ���� �������!";
			link.l1 = "���������� ���������... �������, �� ���� ��-�� ����� ������ �������, ���������. � ����������� �� ������ ����������, ���� ������ � ������� ������, ������ �� ������� ��� ������.";
			link.l1.go = "Avendel_tavern_14";
		break;
		
		case "Avendel_tavern_14":
			DialogExit();
			SetFunctionTimerCondition("Portugal_DoctorOver", 0, 0, 2, false);
			pchar.quest.Portugal_Guard.win_condition.l1 = "location";
			pchar.quest.Portugal_Guard.win_condition.l1.location = "Marigo_houseF1";
			pchar.quest.Portugal_Guard.function = "CreatePortugalGuard";
			AddQuestRecord("Portugal", "1");
			NextDiag.Currentnode = "Avendel_tavern_repeat";
		break;
		
		case "Avendel_tavern_repeat":
			dialog.text = "��-��, �������, ������ ����� ��� � ������������ � ���... ������ ������ ������?";
			link.l1 = "�����, ���� ��� ���... ��������.";
			link.l1.go = "exit";
			Nextdiag.TempNode = "Avendel_tavern_repeat";
		break;
		
		case "Portugal_guard":
			dialog.text = "��, ������, ������ �������. �����, ���������� ������, ����!";
			link.l1 = "��. � ��� ��� �������, ��� � ��� ��� ����� ����, ���� ����...";
			link.l1.go = "Portugal_guard_1";
		break;
		
		case "Portugal_guard_1":
			dialog.text = "��, ��� �� ��� �������� - ��������� �� ����...";
			link.l1 = "...";
			link.l1.go = "Portugal_guard_2";
		break;
		
		case "Portugal_guard_2":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			for (i=1; i<=3; i++)
			{
			sld = characterFromId("PortugalGuard_"+i);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.quest.Portugal_Doctor.win_condition.l1 = "location";
			pchar.quest.Portugal_Doctor.win_condition.l1.location = "Marigo_RoomHouseF1";
			pchar.quest.Portugal_Doctor.function = "CreatePortugalDoctor";
		break;
		
		case "Bart_lay":
			dialog.text = "����� � �����, ������� ����... ������ ��������... ��-��-��, ��� ��������!";
			link.l1 = "�������...";
			link.l1.go = "exit";
			Nextdiag.TempNode = "Bart_lay";
		break;
		
		case "Portugal_doctor":
			pchar.quest.Portugal_DoctorOver.over = "yes";
			dialog.text = "�������, ��� ��? �������, ���� ����, ������! ����� �� ������� �������!";
			link.l1 = "���� ��� '�������' ���� ������ �����, ��� �� ������ �� ��� �����, ������. � ������!";
			link.l1.go = "Portugal_doctor_1";
		break;
		
		case "Portugal_doctor_1":
			dialog.text = "�� ��� �������, � �� ����� ���� ������, �� �� ��� ����������! ������� �� ������? ����� ���, ������� ���� �����!";
			link.l1 = "� ��� � ���, ���� ������?";
			link.l1.go = "Portugal_doctor_2";
		break;
		
		case "Portugal_doctor_2":
			dialog.text = "�������, ��� ��������� �������, �������� � ������ �������, ��������� �����-�� ����... �� ��� ����� � �����, �� ����� �� ���������, �� ��������... � �� ����, ��� ���������� ���� ����, �������, ��� ���� �� ����� � � ���������� ������! �� � ����� ��� ��� ����, ������� �� ��!";
			link.l1 = "��� �� ����� ����� ����������� �� ���� �����, ������. ��� ������ ���������� �� ����� �� ������ ������, � ��� ���� � �����������. �������, �� ����� ���. �� �����������, ���� � �� �������, ���.";
			link.l1.go = "Portugal_doctor_3";
		break;
		
		case "Portugal_doctor_3":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetStayType(npchar);
			Nextdiag.Currentnode = "Doctor_repeat";
			pchar.quest.Avendel_House.win_condition.l1 = "location";
			pchar.quest.Avendel_House.win_condition.l1.location = "Marigo_houseF1";
			pchar.quest.Avendel_House.function = "AvendelInHouse";
		break;
		
		case "Doctor_repeat":
			dialog.text = "� ������ �� ����, �� ������������. ������� ��� ������� ������ ��� ������� � �������� � ���� ��������.";
			link.l1 = "�������, � ��� ���.";
			link.l1.go = "exit";
			Nextdiag.TempNode = "Doctor_repeat";
		break;
		
		case "Avendel_house":
			dialog.text = "� ��� ����������, �������! �� ����� ��� � � �� �������, �� �����������! ��� ����� ������ ������?";
			link.l1 = "�������, ��� ���, �����. � ����� ������, ������� ���������� - ��� ��� �� ���. �������, ��� ������� ���������� � ����������� � �������� ������ ������ ��������������.";
			link.l1.go = "Avendel_house_1";
		break;
		
		case "Avendel_house_1":
			dialog.text = "���-���, �������, ������ �� � ������������� ������! �������� ���, ���� �������� ������� ������ �������� �, � ������ ������, ������� ��� �������� ����! ��� ��������� �� ��� ������ � ���� �� ������ �������� �������������� ������, �� ����� ����� ���� ����� �� �������! ����� � ��������� �� �������, ��� ���������� ����� �� ����� ���������� ������� ��� �������� ��������� � � ��� � ���� ������ ������, ��� ���������!";
			link.l1 = "��� ��, ���� �� ��� � ���� ������...";
			link.l1.go = "Avendel_house_2";
		break;
		
		case "Avendel_house_2":
			dialog.text = "������, �������, �������� ������������ �������, ������! �� �������: ���� ���������� ����� ��� ���� � ������, �� � �������� ���������, ���� ��� ������, ���������� �� �����. ��� ���� ������, ��� ��������� ������� ����������� �� ���� �����.";
			link.l1 = "������... �� �������� ��, �� ������ � ���������� �������������� �� ��� �������. ���� �����������?";
			link.l1.go = "Avendel_house_3";
		break;
		
		case "Avendel_house_3":
			dialog.text = "��, ���� ���� �������� � ���������� ��� � �� ���-������ �����������, � ��������� ����� ������ �����, ��� ������������ ������� ���� �������! ����� � �� ���������� ������������� ������, ��������!";
			link.l1 = "�� ������, �� ������� ����� � ���� ���� ��� ���. �������� ��������� �����-������ ��������� ������ ��� ������ ���������. � �� ���� ����� - ������������ �� ������ � �����.";
			link.l1.go = "Avendel_house_4";
		break;
		
		case "Avendel_house_4":
			DialogExit();
			AddQuestRecord("Portugal", "3");
			LAi_ActorRunToLocation(npchar, "reload", "houseF1", "Marigo_houseF1", "goto", "goto2", "", -1);
			pchar.quest.Portugal_Cloves.win_condition.l1 = "Timer";
			pchar.quest.Portugal_Cloves.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.Portugal_Cloves.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Portugal_Cloves.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Portugal_Cloves.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Portugal_Cloves.function = "PortugalClovesOver";//1 �����
			pchar.questTemp.Portugal = "Findcloves";
			LAi_SetStayType(npchar);
			npchar.dialog.currentnode = "Avendel_house_guard";
		break;
		
		case "Avendel_house_guard":
			dialog.text = "�� ������������, �������, ���������� ��� �������� �������, ��-��...";
			link.l1 = "�������� �� � ��� ������...";
			link.l1.go = "exit";
			Nextdiag.TempNode = "Avendel_house_guard";
		break;
		
		case "Portugal_doctor_4":
			dialog.text = "� �� ���� ������, ������. ��� ���? �� �������, ��� ��� ��������, ��� ������ �� �������� � ��� ��� ��������� �������, ��� ������ �� ��� ������ �� ��� ���?";
			link.l1 = "�� � �� �����, ������ ��� �����. � ��������� �������� ������ ������, � ��� ����� ������� �������� �� ������� � ����� ���������. � ������ ����� ���������... ��������. ��� ������� ������ ����� ����� ����� � ����� ����, � ����� ��� �� ����.";
			link.l1.go = "Portugal_doctor_5";
		break;
		
		case "Portugal_doctor_5":
			dialog.text = "�������, ����������, � �� ���� ���������� � ��� ���������� � ���� ��������� ��� �� �����-�� �����. �� ����� �� �������� � ��������, ��� ����� � ����� � ��� ��������, �� ����� � ��� ������ ������������, � ����������� ����� ����� ��� � ��������� ���! � ��� ��� ��������, ����� � ������, �� �����...";
			link.l1 = "���, ���, �� ������������� � ����. ��-������, � �� ����� � ��������, � ��-������, ������� �� ������ �������� � ��������� ����������� �����������, ���� ����� �� �������?";
			link.l1.go = "Portugal_doctor_6";
		break;
		
		case "Portugal_doctor_6":
			dialog.text = "��... �� �����, �������. ��, ������ � ���� ����� ������� ������, � ����� �����, ��� �� ��������� � ���� ����, � �������� ���������� �� ���������� ������. �, �� ������ ����������� ���� �����������, �� � ����� ��������� ��� ����� ������! ��� �� �����, ����� ���������� - �� �� �������� ����� � ����, �� ����� ������ ���������, � ��� ���� �� ����� ���� ����!\n����� � � ������ ����. ";
			link.l1 = "�� ��� ��� �� ������� ���� ����� �� �������. ��, �������, � ���� ��� ������! � ����-������, �� �������, � ���� ���� ����... ��, ��������, �� ����������� � ��������, �, ���� ��� � ������ ������ ���, �� ��� ��. ���� �� ����� � ������ ��������� ���� ������, ��� ���������� ������ �����. ����������� ���, �� ������������ ����������, � ������ �������� ���������� ������!";
			link.l1.go = "Portugal_doctor_7";
		break;
		
		case "Portugal_doctor_7":
			DialogExit();
			AddQuestRecord("Portugal", "5");
			pchar.quest.Portugal_Cloves.over = "yes";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sld = characterFromId("Avendel");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", -1);
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
			RemoveItems(PChar, "suit_1", 1);
			sld = characterFromId("Portugal");
			sld.model = "Port_B"; //������ ������
			ChangeCharacterAddressGroup(sld, "My_Deck", "goto", "goto6");
			SetFunctionTimerCondition("Portugal_ToAntiguaOver", 0, 0, 4, false);
			pchar.questTemp.Portugal = "ToAntigua";
			//�������� ��� ������ ������� ������� �����, ����� ������
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload4", false);
		break;
		
		case "Avendel_goodbye":
			dialog.text = "����, ��� ��� �����, �������. �� � �� ���������, � �� ������ ��� ������������� ���������. ��������.";
			link.l1 = "������, �����.";
			link.l1.go = "Avendel_goodbye_1";
		break;
		
		case "Avendel_goodbye_1":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
		break;
		
		case "Portugal_doctor_9":
			dialog.text = "...";
			link.l1 = "���, ���������� ����������� �������� � ��������� �� �����. ������ ��� ������� �� ����. ������������!";
			link.l1.go = "Portugal_doctor_10";
		break;
		
		case "Portugal_doctor_10":
			dialog.text = "��� ����, ������.";
			link.l1 = "...";
			link.l1.go = "Portugal_doctor_11";
		break;
		
		case "Portugal_doctor_11":
			DialogExit();
			AddQuestRecord("Portugal", "7");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Portugal");
			ChangeCharacterAddressGroup(sld, "SentJons_HouseF3_Room2", "quest", "quest1");
			sld = characterFromId("Jino");
			ChangeCharacterAddressGroup(sld, "SentJons_HouseF3_Room2", "goto", "goto3");
			pchar.quest.Portugal_ToAntiguaOver.over = "yes";//����� ������
			pchar.questTemp.Portugal = "TreatmentStart";
			pchar.quest.Portugal_Ill.win_condition.l1 = "Timer";
			pchar.quest.Portugal_Ill.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.Portugal_Ill.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 4);
			pchar.quest.Portugal_Ill.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 4);
			pchar.quest.Portugal_Ill.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 4);
			pchar.quest.Portugal_Ill.function = "Portugal_ToAntiguaOver";//�� ������ ����� 4 ��� - ����������� �����
		break;
		
		case "Avendel_Room":
			dialog.text = "� ���� ���� ��� �������� ��������� ���������� ����������! ���� ���������� ��� ������ ���� ����, ����� ����� ����������� � ��� ����� ������ ������� ��������� � ���������� �� ���� �������� ������!\n� ��� ����� ������ ��� �� ������ ����� �������� ���������� ����������!";
			link.l1 = "�����, ������ ��� ���� ���� �����. � �������� ����� �� �����, ������������ �� �����, �� ��� ���� ������ ������ ����� �� ��������. ����� �� ��� � ���, � ���������� �� ��� ��������������, �����, ����� ������ ���� �����-������ �������� - � ������, ��� �������.";
			link.l1.go = "Avendel_Room_1";
		break;
		
		case "Avendel_Room_1":
			dialog.text = "�� ����� ������������, �������! � ���� �������� ������� �� ������ ��������� � ������ ��� �� ������, ���� ���� ��������� ����������! � ������, �� ����� ������� ��������!";
			link.l1 = "������ ����, ����� ��������. ���� ������, ��� ����.";
			link.l1.go = "exit";
			chrDisableReloadToLocation = false;
		break;
		
		case "Avendel_Room_2":
			dialog.text = "������, �������? �������! ����� ����! ������� ���� ���� ��� �� ����� ������� �����... �����-�� �������������� ������. ��� �� ������ �� ����� �����������, �� ���� ���-�� ���������� � ���� ���� ���������, �������!";
			link.l1 = "������, ������� �� ��������������, �����. ������������ �� �������.";
			link.l1.go = "Avendel_Room_3";
		break;
		
		case "Avendel_Room_3":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			//������ �����������
			sld = characterFromId("Portugal");
			ChangeCharacterAddressGroup(sld, "SentJons_HouseF3", "goto", "goto1");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
		break;
		
		case "Portugal_hunter":
			dialog.text = "�������, ��� ����� �� ����� ���� �������! � ��� ��� �� ����? ����� ��� ���������� ���������� ����������� ��������� �����, ��, � ����� ���� ��� ���� � ��� ��! �������� � ��������, ���, �� ��� ������� � ����� �� ����������.";
			link.l1 = "��� �� �����, ���� ������! ����� � ������, ��� ������������ ���� ����� ������!";
			link.l1.go = "Portugal_hunter_1";
		break;
		
		case "Portugal_hunter_1":
			dialog.text = "����� �������, �������-�� �����! �������� ����, ����� � �� ���� ����� ��� ������ � ��� ��������! �� ����������� ����������� ����� �������, � ��� �� � ��� � �����, � �� ������� ��� ����������, � ���������, ���� ���! �� �� ������, ��� �� ������ � �������, ��-��!";
			link.l1 = "�� ��� ��� �������! �����������, ������� ���������!";
			link.l1.go = "Portugal_hunter_2";
		break;
		
		case "Portugal_hunter_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
		DialogExit();
		sld = characterFromId("Portugal");
		LAi_group_Register("Bart_Portugal");
		LAi_group_SetRelation("Bart_Portugal", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_MoveCharacter(sld, "Bart_Portugal");
		for (i=1; i<=5; i++)
		{
		sld = characterFromId("PortugalHunter_"+i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		}
		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("EnemyFight", "PortugalHunterDied");
		AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Avendel_street":
			sld = characterFromId("Portugal");
			if (LAi_GetCharacterHP(sld) > 0)
			{
				dialog.text = "��� � ����, ��� ���-�� ��� �� �����! � ���� �� ��, �������! ��, ��� ���� � � ��� �����, ������ ��� �� ����������, ����� ����������� � �������� �������! ����� ������� ��������� � �������!";
				link.l1 = "����� ���������, �����, � � ���, ��� � �� ����, ���� �� ������� �� ����� ����� �� �������� ������� ����.";
				link.l1.go = "Avendel_street_1";
			}
			else
			{
				dialog.text = "����, ��� ��� �����, �������. �� � �� ���������, � �� ������ ��� ������������� ���������. ��������.";
				link.l1 = "������, �����.";
				link.l1.go = "Avendel_goodbye_1";
				sld = characterFromId("PortugalDoctor");
				RemovePassenger(Pchar, sld);
				sld.lifeday = 0;
				RemovePassenger(Pchar, npchar);
				AddQuestRecord("Portugal", "35");
				CloseQuestHeader("Portugal");
				pchar.questTemp.Portugal = "end";
			}
		break;
		
		case "Avendel_street_1":
			dialog.text = "�... � ��������� ���, �������! �� ������� �����������, �� ����� ���-������ ����� �� � ������ ������� �����?";
			link.l1 = "����� ������� �� � �� �������� � ����� ����? ���, ������ ������� � �� �������! ����� �� ����!";
			link.l1.go = "Avendel_street_2";
		break;
		
		case "Avendel_street_2":
			DialogExit();
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 10);
			AddQuestRecord("Portugal", "8");
			pchar.quest.Portugal_seahunter.win_condition.l1 = "location";
			pchar.quest.Portugal_seahunter.win_condition.l1.location = "Antigua";
			pchar.quest.Portugal_seahunter.function = "PortugalSeaHunter";
			pchar.quest.Portugal_martinique.win_condition.l1 = "location";
			pchar.quest.Portugal_martinique.win_condition.l1.location = "FortFrance_town";
			pchar.quest.Portugal_martinique.function = "PortugalOnMartinique";
		break;
		
		case "Portugal_doctor_12":
			dialog.text = "�������, ���������� ������ ����, ��� ����� ���������!";
			link.l1 = "����� �� ���� � �������, �� ������������, ������ ��� �����, ���� ����������� ����� ��������. � ����� ������� � �������, ��� ������� ������� ��� ���� ����, � �� ��������� ����.";
			link.l1.go = "Portugal_doctor_13";
		break;
		
		case "Portugal_doctor_13":
			DialogExit();
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 5);
		break;
		
		case "Portugal_doctor_14":
			dialog.text = "������ �������, � ��������� �� ������������, ��� ������ ����� ������ �����.";
			link.l1 = "�����, � ��� ��������, ��� � �������, ���. ��������� � �� ������� ��� ��� ������� � ���� �������, ��� � ������� ��������? �� ��� ������, �� ��� �����! ����� ��������, � ��������� � ������, � ��... ��, ��������, ������, ��������... ����� �������.";
			link.l1.go = "Portugal_doctor_15";
		break;
		
		case "Portugal_doctor_15":
			DialogExit();
			AddQuestRecord("Portugal", "15");
			pchar.quest.Portugal_patrol.win_condition.l1 = "location";
			pchar.quest.Portugal_patrol.win_condition.l1.location = "FortFrance_town";
			pchar.quest.Portugal_patrol.function = "CreateFrancePatrol";
		break;
		
		case "Portugal_patrol":
			dialog.text = "�����, ��� �� ������� "+GetFullName(pchar)+", ��� ������� ������� ������ � ������?";
			link.l1 = "�� �� ��������, ��� ���� ���� �������?";
			link.l1.go = "Portugal_patrol_1";
		break;
		
		case "Portugal_patrol_1":
			dialog.text = "��� ������ ������ ������ ��� ��������� ��� ��� �� �����, ���������� ����� �������. ���� �� ������ �������������!";
			link.l1 = "������, ����, � ������ ��� ������������������ ������� ��.";
			link.l1.go = "Portugal_patrol_2";
		break;
		
		case "Portugal_patrol_2":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			pchar.questTemp.Portugal = "MartiniqueGovernor";
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			AddQuestRecord("Portugal", "9");
		break;
		
		case "Avendel_seapatrol":
			dialog.text = "��� �� � �� ���������, �������! ���� ������� ��� �� �� ������...";
			link.l1 = "���� ���������� ������� �� �����������, �������. �����, ��� ����� ����� ��������� �� �������, ��� ��� �������� ���� � ��� �������� ��������� ����.";
			link.l1.go = "Avendel_seapatrol_1";
		break;
		
		case "Avendel_seapatrol_1":
			dialog.text = "���������? �����? �������� ���� �������� � ������?";
			link.l1 = "���, ���. �� �����, ��� ���, ������� ������, ��� ���-�� ����� ������� � �������� ������ �� �������, � ������ �� ������ ������ ��������. ����� ������� ������ ������� �����... ���������������� � ���������. � ��� ��������� ����������, �������� ���� ������� ������� ����� ��������.";
			link.l1.go = "Avendel_seapatrol_2";
		break;
		
		case "Avendel_seapatrol_2":
			dialog.text = "�����? ���������? ��� ���� ����� ���� '���������'? ��� ���-������ �� ������ ������ ���������, ��� �����!";
			link.l1 = "� �����, ��� ������� ��������� ������. ��� ��� �����, �����, ���� ���� ������� �� ���� ����, �� ����� � ��� ������� �������, � �������� ������� ���������� �����, �� ��� � �� �������� ������, ��� ��� ������ �� ������� ��������� ����� �����. � ���� ������� ������ � �� ���� �� �������� ����������� ����� � ������� ��������� ����.";
			link.l1.go = "Avendel_seapatrol_3";
		break;
		
		case "Avendel_seapatrol_3":
			dialog.text = "���������, ������� � ������� �� ��������� ���... ����������� ����� ��� ���������, ���� � ������, ��������, ��������� ��� ������? ������ ������� �����������, �� �������� ����� ���������������!";
			link.l1 = "������ �������, ����� �������! ������� ����� �, � ����� ���� �. ��� ��� ������ ������ ��, ��� ���� ��������. ����������� � ������� � �� ������� ���� � ������� � �����������, ���� � �� ������� �� �����.";
			link.l1.go = "Avendel_seapatrol_4";
		break;
		
		case "Avendel_seapatrol_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 10.0);
			chrDisableReloadToLocation = false;//������� �������
			LocatorReloadEnterDisable("Fortfrance_town", "reload4_back", true);//������� �������
		break;
		
		case "Avendel_seapatrol_5":
			dialog.text = "�� ���������, ������� � �������-��! � ��� ������ ������� � ���������� ������, � � ��� � ���!";
			link.l1 = "��� ������?! ���� �� �������, �������!";
			link.l1.go = "Avendel_seapatrol_6";
		break;
		
		case "Avendel_seapatrol_6":
			dialog.text = "����� ������ �� ������ � �� ����� ��-�� �������� ���� ��� �������� � '���������'. � ����� ����� ����������� � ��� ��������� � ������� � �... � ������. ��������, �� ���������� � ���������� ���� ����� � ���� � ��� �������, ���� �� ����� ������!";
			link.l1 = "���������! ��������, ���� ��� ��������� � �������?";
			link.l1.go = "Avendel_seapatrol_7";
		break;
		
		case "Avendel_seapatrol_7":
			dialog.text = "������ �� � � ������ �� ����� � ������ ������� ����� ���� ������ ����� � ��� �����, ������������� �� ������� � ����� ������� � ����� � �������� ����� ������ �����... � �� � ���� �����! ��� ��������� ��������� ������� � � � �� ����, ��� ������ ��� �������� � ����-��...";
			link.l1 = "��, �������� ���� ������������� �� ��������... �����, ��� ���� ��� ���� ���� � �� ������������ �� ������. � ������� ����� ������ ����� ����� �������, �, ��� ����� ������� �� ����� ��� ��������������! � ��� ��� ���� ����� ����������� �� ����������� - ������ � �������, ����� ���-�� ����� ������, ��� ���� �����. ���, ���������!";
			link.l1.go = "Avendel_seapatrol_8";
		break;
		
		case "Avendel_seapatrol_8":
			DialogExit();
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			chrDisableReloadToLocation = false;
			LAi_ActorFollowEverywhere(npchar, "", -1);
			SetFunctionTimerCondition("MartiniquePortugalOver", 0, 0, 2, false); //������
			sld = characterFromId("PortugalDoctor");
			sld.lifeday = 0;//������� �������
			RemovePassenger(Pchar, sld);	
			sld = characterFromId("Portugal");
			ChangeCharacterAddressGroup(sld, "none", "", "");//����������� �������
			LocatorReloadEnterDisable("Fortfrance_tavern", "reload2_back", true);//������� �������
			AddQuestRecord("Portugal", "12");
		break;
		
		case "Avendel_seapatrol_9":
			dialog.text = "�������, ������� � �� �� ������ ����������� ��� � ������ �����, � ������� � ��� �������. � �������� ��������� � ������� ������, �������� ��� � ������ �� �������� � ���-�� � �� ����� ��������!";
			link.l1 = "���������, �����. � ������, ���������� ��� �� �������, �� ������� ����, ���� ���� ��� � ���������. � �, �������, ���� ����, ��� ��� ������! �� ��������� �� � �� ����� ������� � ��� ������ �� ����������! ���� �� �������� � ������ �� ����, ��� �� ��� ��������.";
			link.l1.go = "Avendel_seapatrol_10";
		break;
		
		case "Avendel_seapatrol_10":
			DialogExit();
			bDisableFastReload = false;//������� ������� �������
			pchar.questTemp.Portugal = "PortugalLeFransua";//� �� �������
			AddQuestRecord("Portugal", "13");
			LAi_LocationDisableOfficersGen("LeFransua_tavern", true);//�������� �� �������
		break;
		
		case "LeFransua_pirate":
			dialog.text = "����� �������� �������, �������... ������-��, � �� ��� �� �� ��������� ������, �� �����������? �����, ����� �� ���, � ����� - ��� ������...";
			link.l1 = "�� ����� ����������, ������!";
			link.l1.go = "LeFransua_pirate_1";
		break;
		
		case "LeFransua_pirate_1":
			DialogExit();
			pchar.quest.MartiniquePortugalOver.over = "yes"; //����� ������
			chrDisableReloadToLocation = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			for (i=1; i<=3; i++)
			{
			sld = characterFromId("LeFransuaPirate_"+i);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LeFransuaAfterFight");
			AddDialogExitQuest("MainHeroFightModeOn");
                                                          DoQuestFunctionDelay("CHEERFRIEND", 0.5);
		break;
		
		case "FranzGarke":
			dialog.text = "...��, ������ ������, ��� ��� ����������, ������� ��� �����, �����, ���! ��, ��� ����� ����, ��� � ���� ������ ����� � ������� �� ��� ������ �������... � �� ��� ��� �����? ������ ����, �� � ��� �� ���� ������� ������ ���������! �������� ������...";
			link.l1 = "�������, � ��� �������, �������?";
			link.l1.go = "FranzGarke_1";
		break;
		
		case "FranzGarke_1":
			DialogExit();
			chrDisableReloadToLocation = true;
			sld = characterFromId("FranzGarke");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LeFransua_PortugalTalk");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Portugal_LFTalk":
			dialog.text = "�� ��� ������ �������... �������, ������ ��� � ������ ���, ��� ����� �� ����� ���?";
			link.l1 = "�� �� ������. ��� ��� - " + GetFullName(pchar) + ", � ��, ����������, ��� ��� ��� �������. ��� ��� �� ������� ������ �������� � ��� ����.";
			link.l1.go = "Portugal_LFTalk_1";
		break;
		
		case "Portugal_LFTalk_1":
			dialog.text = "��������, �������... � ������� ����� ����� �������, � ��� �� ����� ��� ������ ����. ���� �� ������ ��� ����� � ����� ������� �����.";
			link.l1 = "� �� �� ����� �� ������ � ������� ������������, ��? ������, ������ ������ �� �������� � ������ ������ �����������, � ���� �� ����!";
			link.l1.go = "Portugal_LFTalk_2";
			link.l2 = "�� ������� �� ��, ��� � � ������ ��� ���� ������ � ��������� ������?! ������ ������� ������.";
			link.l2.go = "Portugal_LFTalk_4";
			pchar.quest.Portugal_LeFransua.win_condition.l1 = "location";
			pchar.quest.Portugal_LeFransua.win_condition.l1.location = "LeFransua_town";
			pchar.quest.Portugal_LeFransua.function = "CreateVaskezsPirates";
			bDisableFastReload = true;//������� �������
		break;
		
		case "Portugal_LFTalk_2":
			dialog.text = "�� �����������, �������, � ������ ������, ��� ������ � ���� ������� �����.";
			link.l1 = "������� ������. �����, ������ ������ �����.";
			link.l1.go = "Portugal_LFTalk_3";
		break;
		
		case "Portugal_LFTalk_3":
			DialogExit();
			GiveItem2Character(npchar, "blade_17");
			EquipCharacterbyItem(npchar, "blade_17");
			GiveItem2Character(npchar, "pistol6");
			EquipCharacterbyItem(npchar, "pistol6");
			TakeNItems(npchar, "bullet", 50);
			AddItems(npchar, "gunpowder", 50);
			TakeNItems(npchar, "potion2", 3);
			LAi_SetCharacterUseBullet(npchar, "bullet");
			pchar.questTemp.Portugal.Condition1 = "true";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
		break;
		
		case "Portugal_LFTalk_4":
			dialog.text = "���, ����� � ��� ������, ����� �� �����������...";
			link.l1 = "�� �� � ��� �� �����, ��� ��� ��������� ������� � ������!";
			link.l1.go = "Portugal_LFTalk_5";
		break;
		
		case "Portugal_LFTalk_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
		break;
		
		case "Vaskezs_pirate":
			PlaySound("VOICE\Russian\EvilPirates01.wav");
			dialog.text = "�-���! ��� ���! ����� ��!";
			link.l1 = "...";
			link.l1.go = "Vaskezs_pirate_1";
		break;
		
		case "Vaskezs_pirate_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			DialogExit();
			if (CheckAttribute(pchar, "questTemp.Portugal.Condition1"))
			{
				sld = characterFromId("Portugal");
				LAi_SetImmortal(sld, false);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			for (i=1; i<=9; i++)
			{
				sld = characterFromId("VaskezsPirate_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "VaskezsPiratesDied");
			AddDialogExitQuest("MainHeroFightModeOn");
                                                      DoQuestFunctionDelay("CHEERFRIEND", 0.5);
		break;
		
		case "Avendel_LeFransua":
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;//������� �������
			sld = characterFromId("Portugal");
			if (LAi_GetCharacterHP(sld) > 0)
			{
				dialog.text = "�������� ������! �� ������� ����������� ��� � ��� ��� � ������� - ������! �������� ��� ��� ����� �� ��������� �� ����������?";
				link.l1 = "� �� ������, � ������. � ��� ��� ��, �����?";
				link.l1.go = "Avendel_LeFransua_1";
			}
			else
			{
				dialog.text = "����, ��� ��� �����, �������. �� � �� ���������, � �� ������ ��� ������������� ���������. ��������.";
				link.l1 = "������, �����.";
				link.l1.go = "Avendel_goodbye_1";
				RemovePassenger(Pchar, npchar);
				CloseQuestHeader("Portugal");
				pchar.questTemp.Portugal = "end";
			}
		break;
		
		case "Avendel_LeFransua_1":
			dialog.text = "�... ����������� ���������� �����... ��� ���������, � �����.";
			link.l1 = "��, ��� ��� �� � ����� ��������... ��� �������, ���� �������� ��������� ��� ��� ������������� � �� ������, ��� ������� ��� ��������? �� ���������� ������ �����!";
			link.l1.go = "Avendel_LeFransua_2";
		break;
		
		case "Avendel_LeFransua_2":
			dialog.text = "�� ����������, �������... ��, �������� � ���������. �� ���� � ����� ��� ��� ������! ��������� � � ��� ������ � ����! �������... ���� � ���� ���� ������������ �����������, � �������� �� ����� �� ����� �������.";
			link.l1 = "���������! ������ �� ��� � ����������? ���, ���� ��� � ���� ������� � ���� ���� �����������! ���� ������ �� ������� � ������� ���� �� ������. �� ������ �� ��� � ������, ��� ��� �������� ����� �� � ���.";
			link.l1.go = "Avendel_LeFransua_3";
		break;
		
		case "Avendel_LeFransua_3":
			dialog.text = "�������, �� ���� ���������������... ������ � � �������� �� ��������... ����� �����! ������ ���������!!";
			link.l1 = "�� ��������� ��� ��������! �������� � ���� �����! ��� �� ����� � ������� ����, �������� ������, ����� ���� ������ �� ����!";
			link.l1.go = "Avendel_LeFransua_4";
		break;
		
		case "Avendel_LeFransua_4":
			dialog.text = ""+pchar.name+", �� �� �������� ��� ��������� ���������?";
			link.l1 = "������� � ���������, �����... �� ���� ����� ������, ��� ��� ������. � ����������: ������ ������ � �� ���� ������ � �������� ��������, ��� ���� �� ����.";
			link.l1.go = "Avendel_LeFransua_5";
		break;
		
		case "Avendel_LeFransua_5":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Portugal");
			sld.dialog.currentnode = "Portugal_LeFransua";
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Portugal_LeFransua":
			dialog.text = "����������� �������, �������? ��� � �����, ��... ������ ��� �� �������, � �� '����������' ����� ����� � ����� � ������ ��� �������� ����� ������ ������� ������, ��� ������� �� ���� ��� ���� �� ���� ���.";
			link.l1 = "��� ��, ������ �������� ����� ��� ����������������. �������, ���� ����������, � ������������ �������� ������� � �� ��������� � ����� ��� ������ �����������.";
			link.l1.go = "Portugal_LeFransua_1";
		break;
		
		case "Portugal_LeFransua_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.Portugal_LeFransua1.win_condition.l1 = "location";
			pchar.quest.Portugal_LeFransua1.win_condition.l1.location = "Martinique";
			pchar.quest.Portugal_LeFransua1.function = "CreateVaskezsFrigate";
		break;
		
		case "VaskezsHelper_abordage":
			dialog.text = "��, ���� �� �����, ����� ���� �������!";
			link.l1 = "��� ������� ������? ������, � � ������� ���� �����.";
			link.l1.go = "VaskezsHelper_abordage_1";
		break;
		
		case "VaskezsHelper_abordage_1":
			dialog.text = "�������� � ������� �� ������ ���������!";
			link.l1 = "����� ���, ������...";
			link.l1.go = "VaskezsHelper_abordage_2";
		break;
		
		case "VaskezsHelper_abordage_2":
			DialogExit();
			QuestAboardCabinDialogExitWithBattle(""); 	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Portugal_treasure":
			bQuestDisableMapEnter = false;
			if (CheckAttribute(pchar, "questTemp.Portugal.Condition1") && CheckAttribute(pchar, "questTemp.Portugal.Condition2"))
			{
				dialog.text = "� ��� � ��� ��������� ����, �������-�� �� ����� ������������! ����������, ������� � ������� ����������� ���, � ����� �������� '���������' - ��� �� ������� �� �����! ������, �� ������� ������� � ��������� ����� �� ��� �������� ���� �����... ��������, � ������ ������� ��� �������?";
				link.l1 = "�������, ����� �������� �� ��������, ��� ��� ��� ���� ����������� � �����������.";
				link.l1.go = "Portugal_treasure_6";
			}
			else
			{
				dialog.text = "� ��� � ��� ��������� ����, �������-�� �� ����� ������������! ����������, ������� � ������� ����������� ��� ���� �� ����, ���� �� ���� ������ ��������� �����-������ ���������� �����, ��! ������, �� ������� ������� � ��������� �����, �� ��� �������� ���� �����, ��������, � ������ ������� ��� �������?";
				link.l1 = "�������, ����� �������� �� ��������, ��� ��� ��� ���� ����������� � �����������.";
				link.l1.go = "Portugal_treasure_1";
			}
		break;
		
		case "Portugal_treasure_1":
			dialog.text = "�����������! �� ����� ��� ������ ������ � �������, ��� �������� ����� ���������� ����������� ��������, ��������� ��� � ���� ���, ��������� ��� � ������� � �����, � ������ �������� ��������� �� ������? � ������ �������... � ��� ������� ������� ��� ����� ����� ������, ��-��.";
			link.l1 = "�����, ��������� � ������������? ����������, �� ���� ���� ������������? � ������ ���� � ������������ ����� � ��������� ������ � ���������� ��������� ����� ������������ �����!";
			link.l1.go = "Portugal_treasure_2_1";
			link.l2 = "������... ������, ��� ��������. ��, ��� �� �����, � ���-�� �� ����. ��� ����� ��������� � ���� �������, ����������...";
			link.l2.go = "Portugal_treasure_2_2";
		break;
		
		case "Portugal_treasure_2_1":
			dialog.text = "�� ��, ���������, �������! ����� ��������� �� ��� �� �� ��������� �����, ��� ������ �� ��� � ������ ��������, ��������� �� ������������ ��������� � ������ ��� ����� � ���, ��� ��� ����������! �� ��������� �������� �������, ��� �� ����, ������ ��� � ��� ��� �� ����.";
			link.l1 = "� ��� ��� ��� ��� ������. �������, �������� ��� ��������. ���� ������������ � ����������.";
			link.l1.go = "Portugal_treasure_3";
		break;
		
		case "Portugal_treasure_2_2":
			dialog.text = "������, ������������ ��� ������ ����������� � ���� ���... ����, ��� ��� ������ �������� ��������, ��, �������?";
			link.l1 = "������� ������� ����� �� ���������� � ������, ����������. � ������ ����... �� ��������� ������, ������ �������� � ����� � ������ �� �����. � �������: ���� �����-������ ������ ����, � �� � ����� ��� ���������� - � ������� ������� ��� ���������.";
			link.l1.go = "Portugal_treasure_4";
		break;
		
		case "Portugal_treasure_3":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);//������ �������
			pchar.questTemp.Portugal.Villemstad = "true";//����� �����������
			AddQuestRecord("Portugal", "21");
		break;
		
		case "Portugal_treasure_4":
			dialog.text = "��� ���! ��� ��� �� ����, �������! �� ��������� ������ � ���� ������� ����? ��, ������ � ������������� ���� ��������� ��������, ���� ��������������� � �������� ����� ���������?";
			link.l1 = "�� ������� � �� ��� ��� �������. �� ������� ������. ������.";
			link.l1.go = "Portugal_treasure_5";
		break;
		
		case "Portugal_treasure_5":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);//������ �������
			pchar.quest.Remove_Portugal.win_condition.l1 = "Location_Type";
			pchar.quest.Remove_Portugal.win_condition.l1.location_type = "town";
			pchar.quest.Remove_Portugal.function = "RemovePortugal";
			AddQuestRecord("Portugal", "20");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-10;
		break;
		
		case "Portugal_treasure_6":
			dialog.text = "��� ������ ���... ��������. �� ��� ��, ������ ��������. �� ������ ����������, ��� � �����, �������. �� ��� ��������, ����� � ����� �� �������, � � �� ���� ��� �� �������. �� � ������� ��� �������� ���� ������� ������ ���, �����, �� ������� ���� �����, ��? �����, ��� �� �������, ���� � �������� ���-��� ������? ��� �������, ������, �?";
			link.l1 = "������ �� �����, ����������. �� ����� � �������, � � �����������, �� �������� �� ���� ������������.";
			link.l1.go = "Portugal_treasure_2_1";
			link.l2 = "������? � ��� �� ������ ���������� ���?";
			link.l2.go = "Portugal_treasure_7";
			link.l3 = "�� ����� ��� ���� ������... ������ ���������� � ���� ���� � ������ �� �����. � ���� ������� ���������� ����.";
			link.l3.go = "Portugal_treasure_4";
		break;
		
		case "Portugal_treasure_7":
			dialog.text = "������, ����� ������� �������� ���� �����, ����� � � �� ����� ��������� ��� ������, ��� ����� ����������� ����� ���������������. � ���������� ����������� �� ����� �������������. ���������� � � �� ����� �� �����... ������� � ���� �� ����� ���� ����� ����������� ��������. ��� ������� �� ����������, �� � ������ ���� ���� ���� � �����\n���� ������� ��� �������� �� �� �����, �� � ����������� ����� � ��������� ������ �������� �������� � ���������� ������. ��� ��� ���������� �������, ������������ � ������ ������� ������� � �������� ���-�� � ������ �� ���������... � �������� ���� ��������� ������ � ������ � ����� ���������!";
			link.l1 = "�������� ����... ������ � �������, ������ � �������� ����� � ���� �������, �� � ��� ���� �������?";
			link.l1.go = "Portugal_treasure_8";
		break;
		
		case "Portugal_treasure_8":
			dialog.text = "������ � ��� �������, � ����� ����� ��� ����� ������� ������� � ������, � � ����� ��������������� �������� ��� ������. � ����� ����� �� ���, � ���� ������. ��������� ������ �������� ���� �������� �� ����� ��������, � '���������' �������� ������� � ���� �������� �� ��������� �������� �� ������ ����������. ���, ���� ��� ������ ������ ��� ���������� ����� � ������ ���� � �����, � ��������� ���������\n��������� ������� � ���� ���������, ������� �� �� ����� ���� ������ ������, �������� ��������������. � ���������� ������� � ������ �� ����� � ������ ��� ������ �������� � ��������� �� �������� �� ����� ������ � � ���... ������-������ ������� �����! ������, ����� ��������� � ��� ������...";
			link.l1 = "� ��� �� ����������?";
			link.l1.go = "Portugal_treasure_9";
		break;
		
		case "Portugal_treasure_9":
			dialog.text = "�� ����������� ���! �� ���� �������� �������� ��������� ����� ����� ������� �������� � �� �� �������� �����������, �� �� ����� ��� � �� ����. ��� ������ �� ���, ����� � �������� �� ���������. �������� ������ ����������, ��������� �� ����������� ������� � ���-�� ���� � ��������. �����, �������� � � ��� ��� ��� �����\n����� ���� � ���� � ���������, �, ����������, ������� � �����, � �������� ���-�� ��� �����. ����� � ������ ��������, ��� � ��������� �� ��������, �� �� ����� ���, � �������� ��� ��� �������� ������� � ������ ������ ����� �� �� ���������. ��� �������� � �������� ���� � ��������� ���� � ������� ������� � ������-�� ����� �������, ����� ����� ���������\n��� � � ����� � ���� ���������� � ����������� - ��� ������ ���� �������� ���� � ��������, ����� �������� ��� � ������� �������, � ����� � �������� �� ���� ������... �� ����� ���������� �������� �� �������� ��-��� ������ ���� ��������, ��-��...";
			link.l1 = "�� ���� �������, ��� � �� ������� � �� ������� �������� ����� �����. ���� � � ���� ��� ��� �������?";
			link.l1.go = "Portugal_treasure_10";
		break;
		
		case "Portugal_treasure_10":
			dialog.text = "��� ������� - �� ����, ��������, ��� �����, ��� ��� ������ �� ����� �����... �� ���������� � ������, ��-��! � � ���� ������� ��� ����� � ��������, ��� ��� ��������� � � ������, ������ ���, ����� ����� �� ���� �������. ";
			link.l1 = "���, ���������� � ���� ������������� ���������� ���� ������������ ������� � ����� �������. ���������� � �������� ��������� � ��� ��� ���� ����. ������� ������.";
			link.l1.go = "Portugal_treasure_2_1";
			link.l2 = "� � ������ ��������, ��� ��� ����� ������������� ����, � ����� ���, ��� �� �������? ������� � ��� � �����... ������� ��� ������� ��������, ����� �����������, ���� ��� �� � ����������. � �������� ���� �������, ����������.";
			link.l2.go = "Portugal_treasure_11";
		break;
		
		case "Portugal_treasure_11":
			dialog.text = "�������� ��� �������� ��������������. ��, ������ �� �����, ������� ������ ����� ���������� ����������� � ��������� �� ������� ����, ��! ���� � �������� �� ��� ������, ��� ���� �� � �������, �� ��� ����� � � ����������� ��� �������... �� ���, ��-��\n�������� ���� - �����, � ����� � ������� � �������� �������� �� ���������. ������� ������� �������� ������ - ��� ���� ��� �����. � ��� ������ � � ������� ��������. ��� ��� �� �������� ��������� ������. ������� �����...";
			link.l1 = "������, � �������, � �� ������ ����� ������ ����� ������ � ����������� ����� � ����� �����. ������.";
			link.l1.go = "Portugal_treasure_12";
		break;
		
		case "Portugal_treasure_12":
			dialog.text = "� ��� ����, ����������, �������. �������, ��� ��� ��� ����� ���� ����������� �������, �� ��� ������� ��������� �� ������ ��. ������� ���� �� ���� �� ����� '����������' ����� �� ��� ��������� �� ������ ���? �������� ��� ������� �����... ������������� ������, ���� �� ������� ��� � ����� ��� � ����� � ������.";
			link.l1 = "������� �� �������������� ����������, � ������ � �������� ��� �� �������� ��� �������... �� ������� ������.";
			link.l1.go = "Portugal_treasure_13";
		break;
		
		case "Portugal_treasure_13":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", 2.0);
			AddQuestRecord("Portugal", "23");
			pchar.quest.Portugal_Terks.win_condition.l1 = "location";
			pchar.quest.Portugal_Terks.win_condition.l1.location = "Terks_Jungle_01";
			pchar.quest.Portugal_Terks.function = "CreateHollIndBattle";
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
		break;
		
		case "Avendel_Marigo":
			pchar.quest.SetAvendelMarigoOver.over = "yes"; //����� ������
			dialog.text = "�, ���� � ����! ������� "+pchar.name+" ����������� ��������! �� ������� ���������� ��������?";
			link.l1 = "������, �� ������ ��, ��� � ��� ���� ������. ��, �������� ����� �� ��������� � ���������... �����������, ��.";
			link.l1.go = "Avendel_Marigo_1";
		break;
		
		case "Avendel_Marigo_1":
			dialog.text = "������, �������! ��� ���� � �� ����. � ����� ������, � ������������� ��� ��� �����. ������, �� �� �������������, ��� ������ ����� � �����������!";
			link.l1 = "������ �� ������ ��� ���...";
			link.l1.go = "Avendel_Marigo_2";
		break;
		
		case "Avendel_Marigo_2":
			dialog.text = "���-���, �������, ��� �� ����������, ��! � �� ��� �����-������ ����������� �������. ��� ������� ������������! ��� ������� ������... �������� ��� ����������� ��������! �� ������ � ����������� ��� ��������� ����.";
			link.l1 = "������? � �����������? ���, ��� ���-��� ���������. �����, �������� ��� ����������� � ���, ���� ������, ��� ����������?";
			link.l1.go = "Avendel_Marigo_3";
		break;
		
		case "Avendel_Marigo_3":
			pchar.questTemp.Portugal.AvMoney = 10000;
			dialog.text = "��, ���� � �����... ��, ��������� ����� � ���� �������, � ����� �� ����. ��������, ���� ����� � ���������� ����� ������ ��������� ����?";
			link.l1 = "�����, �� ���������� � ��������, �� �������� �� ���������! ����������, ��� � ���� ��� � ��� 5 000 ����, � ��, ������ �� ������ ������.";
			link.l1.go = "Avendel_Marigo_4_1";
			if (sti(pchar.money) >= 10000)
			{
			link.l2 = "������-�� � �� �������. ���, ����� 10 000 ����, � ����� �� ����� ���������� ������ ���� �����!";
			link.l2.go = "Avendel_Marigo_4_2";
			}
			link.l3 = "� ���� ���� ����������� �������. ��� ������ ����� � ���� �������? ��� �������, � ���� ������ � �������, ��� ��� ���� ������� ������� �� ���� ������� ����� -  ��� �� ���������� �������� �����������.";
			link.l3.go = "Avendel_Marigo_4_3";
		break;
		
		case "Avendel_Marigo_4_1":
			pchar.questTemp.Portugal.AvMoney = 15000;
			dialog.text = "���, �������, ��� �� ������! �� ���� ���������, ������� ��� � ���� ��������� ������������ � ��� ��� �������� ��� ���� ����� � ����, � �� ���������. 15 000 � �� ������ ������!";
			if (sti(pchar.money) >= 15000)
			{
			link.l1 = "���� � �����, �����!";
			link.l1.go = "Avendel_Marigo_4_2";
			}
			link.l2 = "�� ��, � ��� �������, ��� �������� - �� �����. �� ������� �� ����� ���� �����, �?";
			link.l2.go = "Avendel_Marigo_wait";
		break;
		
		case "Avendel_Marigo_4_2":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Portugal.AvMoney));
			dialog.text = "��� ��� ���� �� ���, �������! ��������: ������ ���� �� ���� �� ����� ����� ����, � ����������, ������ ��� �������� ������ ������ �� ������, � �� ������������ � ������������ �����, ��� ��� ����� ����, �� �������� ���� �������, � �� ���� �� �����. ���� � ��� ����� ��������, �, ����� �� �������, ���� ������������ �� ���� ��������... ������ ���������� ����� � ��� �������.";
			link.l1 = "�����, �� ����! ��� �� ������ � �����������?";
			link.l1.go = "Avendel_Marigo_5";
		break;
		
		case "Avendel_Marigo_5":
			dialog.text = "������� �� ����, ��, ����� ��� �������� ���� �������� ����� �� ���� ���� ����, � ����� ������� ������� �����, �������� � ������, ����� ������� � ����� � ������ � ������� ������ � ���� ����� ������� � �������� � ������...";
			link.l1 = "��� ��� ��� ���� ��������! �������... �� ����������, �����, ����������� ������.";
			link.l1.go = "Avendel_Marigo_6";
		break;
		
		case "Avendel_Marigo_6":
			dialog.text = "��, ��� ���, � � ������ � ���� �������, � ������ � ��� ���� ����� ��� ����� ��� ����� ������� ������ � ����������� ������, ����� ����. ����� �� ������� ���� ��� � ������ � ������ � �������� ����-������ ������. � �� ������� � �� �� �������� �������, �� �� ������, ��-��. �� ��� ������� ��� ������ � ���������� ������, ���� �������, �������.";
			if (CheckAttribute(pchar, "questTemp.Portugal.AvOfficer"))
			{
				link.l1 = "�������� �� ����. ��, �� ������������ � �������? �������� ���������, ��� ��� ����������� �� ����� � ��� ����� �����������. �������� ����������� ������ �������������� �����������.";
				link.l1.go = "Avendel_hire";
			}
			else
			{
				link.l1 = "��� �, �������. �� ��� ������������� �����, �����. ��� ���� ���, ��������� ���� ��� �� ��������.";
				link.l1.go = "Avendel_Marigo_del";
			}
			AddDialogExitQuestFunction("InMarigoResidence");
		break;
		
		case "Avendel_Marigo_4_3":
			dialog.text = "��� ��� ����, �������! ��� ��� � ����? �� ���������� ���� �� � ���� ���������� ����, � ������ ��� ����� �����������?";
			if (sti(pchar.money) >= 10000)
			{
			link.l1 = "������, � �������� ����������. ���, ������ 10 000 ����, � ���������� ���, ��� ������ ��� �������, � �����.";
			link.l1.go = "Avendel_Marigo_4_2";
			}
			link.l2 = "��������, ��� ����� ���������� �� ��� ������. ���� �� ����, �����, ����������, �� �� ������ ��� � �������. � �������� ���� �����������, ��� �������?";
			link.l2.go = "Avendel_Marigo_7";
		break;
		
		case "Avendel_Marigo_7":
			pchar.questTemp.Portugal.AvMoney = 20000;
			pchar.questTemp.Portugal.AvOfficer = "true";
			dialog.text = "��� ��� �������... ���������, ��, �� ������, ��� ������ ���� ����, �������. ������� � �� ���������� �� ������� �����? �� ���� �������� ��� ������ ������� �������� �� ����� ����� �������� � ��� ��� ���� ������ ���� � �������, ������� � ������� ������. ������� ����� � ��� ������!";
			link.l1 = "�� ��������� �������, �����. ������ � ���� ��� ������ �����, � ������� �����. ������ �� �����.";
			link.l1.go = "Avendel_Marigo_wait";
			if (sti(pchar.money) >= 20000)
			{
			link.l2 = "�������, �� ���������� ��� ��������, � �����-�� �������, ��! ����� ���� ����!";
			link.l2.go = "Avendel_Marigo_4_2";
			}
		break;
		
		case "Avendel_Marigo_wait":
			dialog.text = "��, ��� ������, �������. � ���� ����� � ���� ������ �� �����. ��������� - �������������.";
			link.l1 = "������, �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Avendel_Marigo_repeat";
		break;
		
		case "Avendel_Marigo_repeat":
			dialog.text = "�� ����������, �������? ����� � ��� ���� ������.";
			if (sti(pchar.money) >= sti(pchar.questTemp.Portugal.AvMoney))
			{
				link.l1 = "����� ���� ������, ��������!";
				link.l1.go = "Avendel_Marigo_4_2";
			}
			link.l2 = "��� � ���� ���� ����� �����.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Avendel_Marigo_repeat";
		break;
		
		case "Avendel_Marigo_del":
			DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Avendel_hire":
			DialogExit();
			LAi_SetImmortal(npchar, false); // patch-8
			SetCharacterRemovable(npchar, true);
			npchar.quest.OfficerPrice = sti(pchar.rank)*1000;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.loyality = 25;
			npchar.dialog.FileName = "Enc_Officer_dialog.c";
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Servant":
			pchar.quest.InMarigoResidenceOver.over = "yes"; //����� ������
			dialog.text = "�����������, �������, �� ���-�� ������?";
			link.l1 = "���-���, � ������ ���, ���� ����������� ������ �����. ��� ���������... ��. �����, ������� ������, ��� ��� ������������������ ��������� ���������� ������� ������� �������?";
			link.l1.go = "Servant_1";
		break;
		
		case "Servant_1":
			dialog.text = "��� ��, ������! ���� ������� ������ �������, �� ������-�� �� ��� ������. �������� � ��� ������� ������ �����, ���� ����� ������ �����������... �� ����. �� ���������� ��� ��� ������� ��������� ����... ��� ��� ����, ������! ���� ����� � ������������ ������� ����� � ��������!";
			link.l1 = "������������� ������! ��� �� �� ������ ��� ����������, ��� �������� ������� ������ ����� ��������� ��� �� �������� � ����������� �� ����!";
			link.l1.go = "Servant_2";
		break;
		
		case "Servant_2":
			dialog.text = "�� ���� �� � ��� ��� ����, �� ����� ��� �� ������� � ��� �������� ���� ���������, ����� ��� ��������� ������� ��������� �� ������ �����...";
			link.l1 = "���������? �� ��� �� ����� �� ����������� �����?";
			link.l1.go = "Servant_3";
		break;
		
		case "Servant_3":
			dialog.text = "���... ���� ���. ���� ���� �����, �����, ��� ��������� �� ������� ���� � ��������� �������� � ����������. ������, ���-�� ������ ����� �������� ������� � ������� - �� �����, ��� ������� ��� ���� ��������\n� ��� ����� �����, ��� ������� ��� ������� �������� � ���������� �����������, ������ ���������! ������, ������ �������� ����� �������� �� ��������, � ��������� ������ ���������. �������, ����� ����� ����� ���, ������ �� ���� � � ���� ��� ������?";
			link.l1 = "�����������?! ���... �������, ��� ����... �������, ������ ����� ��� ����������� � ��� ���� ����.";
			link.l1.go = "Servant_4";
		break;
		
		case "Servant_4":
			DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("Portugal", "31");
			pchar.questTemp.Portugal = "SeekPortVillemstad";
			pchar.questTemp.Portugal = "PortugalInPrison";
			SetFunctionTimerCondition("InMarigoResidenceOver", 0, 0, 30, false);
			colonies[FindColony("Villemstad")].jail = 0;
			sld = characterFromId("Portugal");
			sld.model = "Port_A"; //������ ������
			sld.dialog.currentnode = "Portugal_free";
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld, "Villemstad_prison", "goto", "goto9");
			sld = GetCharacter(NPC_GenerateCharacter("PortHolOfficer", "off_hol_4", "man", "man", 35, HOLLAND, 30, true, "soldier"));
			FantomMakeCoolFighter(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+10, 100, 100, "blade_19", "pistol3", "grapeshot", 100);
			SetCharacterPerk(sld, "SwordplayProfessional");
			LAi_CharacterDisableDialog(sld);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
			ChangeCharacterAddressGroup(sld, "Villemstad_prison", "goto", "goto23");
			LAi_LocationDisableOfficersGen("Villemstad_prison", true);//�������� �� �������
		break;
		
		case "Vaskez":
			dialog.text = "������ ��� �����... �����!";
			link.l1 = "...";
			link.l1.go = "Vaskez_1";
		break;
		
		case "Vaskez_1":
			DialogExit();
			LAi_ActorAnimation(npchar, "shot", "VaskezFight", 2.0);
		break;
		
		case "Portugal_free":
			if (LAi_group_GetTarget(pchar) <= 0)
			{
				dialog.text = "��� �� ���� � ������������� �� ������ �������, �������! ���-�� �� ������ �� ��������� ����� � �����, ���, ��������, �?";
				link.l1 = "�� �������, ���������� � ��� ������ �� �����������, ��� �� ������������ ����������� � ���� ������. � ������� ����� ����������� ���� �� ��������, ����� ��������� ���� ��� �������� ��������� ����� ����� ������ �����������!";
				link.l1.go = "Portugal_free_1";
			}
			else
			{
				dialog.text = "����������, �������! ��, ����, �� ���� ������ ����!";
				link.l1 = "...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Portugal_free";
			}
		break;
		
		case "Portugal_free_1":
			dialog.text = "������ ������������ ������ �� ������ �� ������, ��? ��... ���������, �����!";
			link.l1 = "���������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("CreateErnandoVaskez");
			NextDiag.TempNode = "Portugal_free";
		break;
		
		case "Portugal_free_2":
			dialog.text = "� � ������������, ��� ���� ������ ��� �������� ������!";
			link.l1 = "�� ���� �� ���������� ���� �� �����! ��� �� ��������?";
			link.l1.go = "Portugal_free_3";
		break;
		
		case "Portugal_free_3":
			dialog.text = "� �����, �� ��������� ������ ������� � ������� ���� ���-��... � ���� ������ ���� ����� � ����� ����. ��� ��, �������, ������ �� ������� �����...";
			link.l1 = "�� ��! �����, ��������, ���� ���� �� �������� ���� ��������. ������ � ������ ���� �����...";
			link.l1.go = "Portugal_free_4";
		break;
		
		case "Portugal_free_4":
			DialogExit();
			InterfaceStates.Buttons.Save.enable = true;//��������� �����������
			chrDisableReloadToLocation = false;
			DoQuestReloadToLocation("Villemstad_Exittown", "rld", "loc17", "PortugalFree");
		break;
		
		case "Portugal_free_5":
			dialog.text = "������, �������, ������ ������... ��������� ��� ������ ����� ���������� ������ � ����������, � ��� ���, ��� �� ���� ������ ��������� ������� ���������� �������. �������, �� ���� ��� �� ������� ���� �� ��������.";
			link.l1 = "������ ���, ����������. � �� ����������� ������, ������... �������� ���, ��� ������ ������.";
			link.l1.go = "Portugal_free_6";
		break;
		
		case "Portugal_free_6":
			dialog.text = "��, � ��� �������� ��������! ��, � ��� �� ��������� � ���, ��������... ��� ������������, ��� ��� ������� ������ � ������... ��� ��������. �� ������ �������� ��� ����� � ����. �� �������� �����, ��� ��� �� ��� ����� ����������.";
			link.l1 = "������ �� ��� �����, ���� �� ������ ����������� � ���� ����������?";
			link.l1.go = "Portugal_free_7";
		break;
		
		case "Portugal_free_7":
			dialog.text = "��! � ���� ���, �? �, �������� � ������ �� �� ��������... ������, �������, ����� �� ������ �������� ���. � ��������� ��� ���!";
			link.l1 = "��, ������, ����������. � ���������� �� �������� ���� ��� �� ��������! ���� �� �� �������� � ���� ����������, ��-��!";
			link.l1.go = "Portugal_free_8";
		break;
		
		case "Portugal_free_8":
			TakeNItems(pchar, "talisman2", 1);
			Log_Info("�� �������� ��������");
			PlaySound("interface\important_item.wav");
			DialogExit();
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			LAi_LocationDisableOfficersGen("Villemstad_prison", false);//�������� �������
			AddQuestRecord("Portugal", "34");
			CloseQuestHeader("Portugal");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-15;
			pchar.questTemp.Portugal = "end";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}