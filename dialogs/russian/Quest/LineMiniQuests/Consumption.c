// ������� �� ������ ���� �������
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (pchar.questTemp.Consumption == "final")
			{
				dialog.text = "�������! �� �������� � ����, � �������! ��� ���������, �� ���-�� ������? ����� ���, �������, �� ������!";
				if (CheckAttribute(pchar, "questTemp.Consumption.TakeMoney"))
				{//���� ������
					link.l1 = "���, ���������, ��� ��� ���� �� ������� ��� ��������� �����������. ��� ����� ����, �� ������� ������������� ���� � ��������� ����� � ������ � ���� ��� ��������. ���������.";
					link.l1.go = "Waitress";
				}
				else
				{//���� �����
					if (CheckAttribute(pchar, "questTemp.Consumption.KillJuan"))
					{
						link.l1 = "�� ���� �����, ������ ����� �������� � ��������� �������� ������� ��� ����, ������������ �� �������� �������. �� � ������ ��� �����, � ������ �� �������� �� ��� �������, � ��� ���� ������� ������ �� ����� � ��������� ����� � � ���� �� ����� �� ��� ����� ������, ��� ���������� �������.";
						link.l1.go = "Waitress_2";
					}
					else
					{//�������� �����
						link.l1 = "�� ���� �����, ������ ����� �������� � ��������� �������� ������� ��� ����, ������������ �� �������� �������. �� � ������ ��� �����, �, ���� �� ������� ���������� ������ ��������, ��� ���� ������. ������� ������ �� ����� � ��������� ����� � � ���� �� ����� �� ��� ����� ������, ��� ���������� �������.";
						link.l1.go = "Waitress_2";
					}
					sld = characterFromId("ConAndjelo");
					sld.lifeday = 0;
					RemovePassenger(Pchar, sld);
				}
			}
			else
			{
				dialog.text = "��� ������� ������ ���-������ � ������ �������, �������?";
				link.l1 = "���� ���. ��, �����, ������� ����� �����. ���.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "Servant":
			dialog.text = "������ ����, ������. �� �� ������ ����?";
			link.l1 = "� ������ ������ ������� ����������, �� ������ ������ �� ��� ����� � ����.";
			link.l1.go = "Servant_1";
		break;
		
		case "Servant_1":
			dialog.text = "����� ��� ������� ������ ��� � �����.";
			link.l1 = "��� ������� ������� �����, � �� ��� ���������� ���� � ����. ��������, � ������ ������ ������, �� � ���� ��������� ���������� �����. ��������, ��� ����� �����!";
			link.l1.go = "Servant_2";
		break;
		
		case "Servant_2":
			if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < 20)
			{
				dialog.text = "������ ������ ������������� ���� ��� ���� ������ �����, ��������� ��������� ����������... � ������, � ����� �� ����, �������, ��� ��� �������...";
				link.l1 = "��, � ��� ��?";
				link.l1.go = "Servant_3";
			}
			else
			{
				dialog.text = "�����, � ��� ����, � ������ ��� ������, ���� ������ ��������� �������� � ���������� ���� �����. �� ������ � �� ��� ��� � � ��� ���� �� �����.";
				link.l1 = "�������� ������� ������...";
				link.l1.go = "Servant_4";
			}
		break;
		
		case "Servant_3":
			dialog.text = "�� ������� �� ���� ����� ������� ���������� � ����������� ������. �� ��, ��������, ��������� ����... �����, ����!";
			link.l1 = "���������!";
			link.l1.go = "Servant_fight";
		break;
		
		case "Servant_4":
			DialogExit();
			NextDiag.CurrentNode = "Servant_repeat";
			LAi_SetOwnerType(npchar);
			chrDisableReloadToLocation = false;
		break;
		
		case "Servant_repeat":
			dialog.text = "��, ��� ��� ���? ��� �� ������ ������ ���� ������ ���?";
			link.l1 = "���, �������, � ���-���� ������� ����������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Servant_repeat";
		break;
		
		case "Servant_fight":
			int iRank = sti(pchar.rank)+5;
			int iScl = 15 + 2*sti(pchar.rank);
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			chrDisableReloadToLocation = true;
			for (i=9; i<=11; i++)
			{	
				sld = GetCharacter(NPC_GenerateCharacter("Conservant_"+i, "citiz_"+i, "man", "man", iRank, SPAIN, -1, true, "quest"));
				FantomMakeCoolFighter(sld, iRank, iScl, iScl, "blade_10", "pistol1", "bullet", iScl*2);
				DeleteAttribute(sld, "SaveItemsForDead");
				DeleteAttribute(sld, "DontClearDead");
				LAi_SetWarriorType(sld);
				ChangeCharacterAddressGroup(sld, "PortSpein_houseF2", "goto", "goto5");
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Consumption_AfterHouseFight");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		//������� ������� � ������
		case "Man_FackYou":
			dialog.text = "�� ��, ������! � ���� �����, �����? ������, ����, �� ������!";
			link.l1 = "�-���, ������!";
			link.l1.go = "Servant_fight";
		break;
		
		case "Sergio":
			dialog.text = "����� ��������, ���� � � ���� ����������?";
			link.l1 = "����������, � ������� �����. ��� �� ������?";
			link.l1.go = "Sergio_1";
		break;
		
		case "Sergio_1":
			dialog.text = "� ������, ��� �� ������������� � �������� �� ����� ����, � �������� � ����� ������...";
			link.l1 = "���... � � ���� ��� ��?";
			link.l1.go = "Sergio_2";
		break;
		
		case "Sergio_2":
			dialog.text = "����! ����������� � �� ���������� �����! �� �� ����� �������! � �� ����, ��� ��� �� ���� �� ����� �������, �� ����� ���� �������� �����. � �� ���� ������ �������!";
			link.l1 = "�������? � ���? ��� ���-�� �������� � �������?";
			link.l1.go = "Sergio_3";
		break;
		
		case "Sergio_3":
			dialog.text = "��� �������� ������, ���� �� ���, � � ��� ��� ��������, �� �� �����. ���������� �������: ����� �����, �, ��� ��������, ���� �������� �������� ����. ���������� �� ���������� ��������, � � ��� �������. ������ ����� � ���������� ���������, ���� �� �� �� �����������! ���� �� ��� ����� �� �������... � ������ ��� ����. �������, ����� ������ - �� ���������� ��������.";
			link.l1 = "������, � ���� ���, ��! ��������...";
			link.l1.go = "Sergio_4";
		break;
		
		case "Sergio_4":
			DialogExit();
			AddQuestRecord("Consumption", "8");
			LAi_ActorRunToLocation(npchar, "reload", "gate_back", "none", "", "", "OpenTheDoors", -1);
			pchar.quest.Consumption3.win_condition.l1 = "location";
			pchar.quest.Consumption3.win_condition.l1.location = "PortSpein_Exittown";
			pchar.quest.Consumption3.win_condition.l2 = "Hour";
			pchar.quest.Consumption3.win_condition.l2.start.hour = 0;
			pchar.quest.Consumption3.win_condition.l2.finish.hour = 3;
			pchar.quest.Consumption3.function = "Consumption_MeetSergio";
			pchar.quest.Consumption4.win_condition.l1 = "Timer";
			pchar.quest.Consumption4.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.Consumption4.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Consumption4.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Consumption4.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Consumption4.function = "Consumption_FailSergio";
			locations[FindLocation("PortSpein_Exittown")].DisableEncounters = true; //��������� �������
			LAi_LocationDisableOfficersGen("PortSpein_Exittown", true);//�������� �� �������
		break;
		
		case "Sergio_5":
			dialog.text = "����� ����, �� ������... �� �������� �� ����� ������?";
			link.l1 = "� ������ ���? ���-�� �� ��� �������������, � ��� �� ������ ������� ����������, ��� ��� ����� ���������� � ����... ��� ��� �������� � �����?";
			link.l1.go = "Sergio_6";
		break;
		
		case "Sergio_6":
			dialog.text = "��� ��� - ������ ������. � �������� ����������� ��������� � ����� ����� �...";
			link.l1 = "������! �� ��� �������?";
			link.l1.go = "Sergio_7";
		break;
		
		case "Sergio_7":
			dialog.text = "���?! ���?";
			link.l1 = "������� ������, �� ����� �� ����... �� ���� � ����� ������, �������?";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Consumption_CreateBandits");
		break;
		
		case "Bandit":
			dialog.text = "�������, ���! �����, �����, ���� ���������, � � ������� ����!";
			link.l1 = "...";
			link.l1.go = "Bandit_1";
		break;
		
		case "Bandit_1":
			DialogExit();
			sld = characterFromId("Sergio");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			for (i=1; i<=3; i++)
			{	
				sld = characterFromId("Conbandit_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Conbandit_AfterFight");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Sergio_8":
			dialog.text = "������� ������, ��� ���������! �� �� ������ � ��� �������� ����� � ���� ����!";
			link.l1 = "��, ��� ������������� ������� ���������. ���� � �� �� � ����... �� ��� �� ������������? �� - �������� ����?";
			link.l1.go = "Sergio_9";
		break;
		
		case "Sergio_9":
			dialog.text = "��. � �������� ����������� ��������� ����� � ������ �������� � ���������, � ����� ���� ������������ �����. ������ �� � ���� ��, ��� �������� � ������ �����, ��� ��� �� �� �� ����!";
			link.l1 = "� �� ������, ���� ��������� �����������, �����, ������� �� �������, ���� ��� � �������, ����� �� �����?";
			link.l1.go = "Sergio_10";
		break;
		
		case "Sergio_10":
			dialog.text = "��� ��� ���������. ��-��, ��� ��������� � �� ������� ��... ������ �������, ��� ����, ������ ����� �����, �� ����� ����. �������� ���, ���� ����� �� ����� ������ � ��������, �������� �� ��������� ��������. � �����, ��� '������������� ������� �� �������' �� ����� �����������...";
			link.l1 = "������, ���� - ��� ��� �� �������! ��� �� ������ � ���?";
			link.l1.go = "Sergio_11";
		break;
		
		case "Sergio_11":
			dialog.text = "�������. � ������ ����� �� ��������� � �������, ���������� � ������������� ��������, � ��� ��� ��������� ���������� �� ����� ����� ������ �������. ��� �� � ������� �������� '�������'. �� ��� � ������, ���� ������, �� ����\n��������� ���� ��� � ����� � ������������ ���������� �� ���� ���� ����������� ���� �� ����. ����� �������� �� ���������� ����.";
			link.l1 = "'�������'... � ��� ���� ��� �������� � �������! ��� ������ ������ ��� �������... � ������ ��������� �������� ��� ���, ��� � �������!";
			link.l1.go = "Sergio_12";
		break;
		
		case "Sergio_12":
			dialog.text = "� ��� �������, ��� ����� ���-�� �� ��������� ����������� � �����, ��� �� �� ������ �� ���� �������, � ����? ���� ���, �� ��� ����� ������� � ����������� ���� ��������� � ���� ������. � ��� �������� ������ � ������ ��� ���� �������, �, ������� ��, ���� �������� � ����� ������ �� �������!";
			link.l1 = "�� ��������� ���? �� ������ �������...";
			link.l1.go = "Sergio_13";
		break;
		
		case "Sergio_13":
			dialog.text = "��, � �������� ��� ��� �������, ��� ����� ��� ��������� �������! ������ � � ������ � ���, ����� ���������� ���. ������, ��� ���� ������ ������, �������� ����������� �� ����?";
			link.l1 = "�������, ��� ��������, ��� ��� ������ �������, ��? ���� � ��� ����������. �������, �� ������ ����� ������ �� ��������� �������?";
			link.l1.go = "Sergio_14";
		break;
		
		case "Sergio_14":
			dialog.text = "� ��� �������? � ���� ��� ������� �������������, � ��� ��������, ��� ����� �������� ������ � ���� ��������, � '������� ������� �� �������', ����� ������������, ��� ��� �� �������, ����� ���� ������� �� �������� �������\n�� ����������� ������ ��� ����, � ��� ������� ������� ����� ������� ����������. �� �� ������ ���������� ��� ���� �� �� �����, ��������� �����!";
			link.l1 = "��� � �������, ��� ������ �� �����, ���� �� ����, ��? ��� ��� ��� �����?";
			link.l1.go = "Sergio_15";
		break;
		
		case "Sergio_15":
			dialog.text = "�� ������ ����� �� ��������� ���-�� �������� ������ �����������... � �� ������� ��� ���� ����������! �� ������ ��� ��� �������. � �� ���� ������ ��� ������� �����, �� ����������� ������ ���������� �� ��� ������, ��� �� ������ �������. �������, ������� ������������ ����������, � �� ������ ���� ������ � ��� �������� ������� �������, ��� ��������� ������ � �������.";
			if (!CheckCharacterItem(pchar, "letter_consumption"))
			{
				link.l1 = "��������� ���, ������, �� ��������� ������, � ��������� �� �����. � ���������� �������� � ����� � ����� ��� ������� �����, � �� �������������, ���� ��� �� ��������� � �����.";
				link.l1.go = "Sergio_16";
			}
			else
			{
				link.l1 = "��� ��, ��� ���, ��� ��� ����� �����. ���� ���������� ��������� � ������, ����� �� �������� ������ ������� �� ����� ������ �����. � �� ���� ������� ��� ���.";
				link.l1.go = "Sergio_17";
			}
		break;
		
		case "Sergio_16":
			dialog.text = "����� ���, �������! �� ���� �� ������������ � �������, ����� ��� ������������, ���� �� �����. ����� �����!";
			link.l1 = "��� �������� ����� �������� ��������� �� ������ � ���������, ��� �� �������� ��� ������� ����� �� ������, � ������� ����� �� ��� � �������!";
			link.l1.go = "Sergio_19";
		break;
		
		case "Sergio_17":
			RemoveItems(PChar, "letter_consumption", 1);
			Log_Info("�� ������ ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� ���? ��� ��� ���������� � ���������� '�'? ����������! ������ � ��� ���?";
			link.l1 = "����� ��� �� ���� �� �����, ��, � �����, �� ������� ������ ��������� ����������.";
			link.l1.go = "Sergio_18";
		break;
		
		case "Sergio_18":
			dialog.text = "�����, ������� ����� �������! ��������� ������� �� �������� ��� �� ����� ������! �� ������-�� � �� ���� ����������!";
			link.l1 = "�����, ���� ��������� ������ ����������� ���������� � �� ������, ��� � �������, � ��� �����. ����� - ������ �����������? ����� ����������� ��������... � ������ ��� ���� � �� ����� ���������� ������� �����.";
			link.l1.go = "Sergio_19";
		break;
		
		case "Sergio_19":
			DialogExit();
			AddQuestRecord("Consumption", "11");
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "OpenTheDoors", -1);
			pchar.quest.Consumption5.win_condition.l1 = "location";
			pchar.quest.Consumption5.win_condition.l1.location = "Trinidad";
			pchar.quest.Consumption5.function = "Consumption_CreateJuan";
			pchar.quest.Consumption6.win_condition.l1 = "HardHour";
			pchar.quest.Consumption6.win_condition.l1.hour = 13;
			pchar.quest.Consumption6.function = "Consumption_FailJuan";
			// ������ ������ ��� ���� � ����� ��������� �������
			SetFunctionTimerCondition("Oil_PrepareSergio", 0, 0, 20, false); // ������
		break;
		
		// ��������� �������� �������
		case "Sergio_20":
			dialog.text = "�, ����� �������! ������ "+GetFullName(pchar)+"! ��� ��� ������!";
			link.l1 = "������ ������! ��� �� �� ������? ��� ���� ����? ��� �������� �������� ���������?";
			link.l1.go = "Sergio_21";
		break;
		
		case "Sergio_21":
			dialog.text = "��� ���� - �������, � ��� �������� ��������� ������ ������ ���������� ���������� �� ������ ���-����� - ��� ��� ������� ��������� � ������ �������� ������� ������.";
			link.l1 = "�� ������? �� ����� ����! ��� �� �� ������ ������ ��������� ����������.";
			link.l1.go = "Sergio_22";
		break;
		
		case "Sergio_22":
			dialog.text = "��, ��������, �������... �� ������ ��������� � ���������� - ������ �� ������ � ���������, ���� ����������� ���� �� ������. �� ���� ���-���� ��������� �� ����� �������, � �� ������.";
			link.l1 = "��, ���� ���. ���� � ������... ��������� ��������.";
			link.l1.go = "Sergio_23";
		break;
		
		case "Sergio_23":
			dialog.text = "� ����, ��... �������, �� ����� ������ �� ���� �������, �� ���� �� �����������. ������, � ��� ������ ���������, ��� ��� ������� ������ � ����, ����� �������� �� ����. � ���� � ��� ���� ����.";
			link.l1 = "���� ���? ����������� ������.";
			link.l1.go = "Sergio_24";
		break;
		
		case "Sergio_24":
			dialog.text = "�������, �� ���������� ��� ������� ���������, �������� ����� ��������. ����� ���������� �������� ����� ��, ��� �� - �������, � � ��� ���� ���� �������. � ��������� ��������� �������� ����������.";
			link.l1 = "����� ���������! � ����� ��?";
			link.l1.go = "Sergio_25";
		break;
		
		case "Sergio_25":
			dialog.text = "�� ���� ����� ���������� � ������ �����, �� �����, � ������ ����������. �� ��� ��������� ����, ��� ��� ��� � �������. ��������� �� ���� ���-���� ������� ��� ������ - � ���� ��� �����. ����������� ������ ��� ��������������!";
			link.l1 = "������, ������ ������. � ����������� �����!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Oil_SergioRuntoMayak");
		break;
		
		case "Sergio_26":
			chrDisableReloadToLocation = true;//������� �������
			pchar.quest.Oil_SetSergioToMayakOver.over = "yes"; //����� ����������
			dialog.text = "��� ��� ����������, ������. ��������� ��� �������� ��� ���� ����.";
			link.l1 = "����������� ��� ������.";
			link.l1.go = "Sergio_27";
		break;
		
		case "Sergio_27":
			dialog.text = "��� ��� ��� ��������, � �������� �������� ������ � ���������� �����. ������ ���? ������ ��� � ������� � ������ ������� �����������. ��� �� ����� ����������� ��������� ���, �� �������� �� �������� �� ����������, �� ������� ��� ���� ��������� ����� �� ���� � �������, ��� ��� ���������� ��� ������ ��������, � ������������ ���������� � �������� �� ������� �������� ������ ������������� ��������� ����\n����� � �������� ���� ����� �� ������ ������� ���� � ����� ���������� ��� ������ ���������� �����. �� ������ ������ ��� ������������� ���� �������� ������ ��������� ������ ����������� ��������. �� ������ ���� ����� ��� ���� ����������� ��������� �������� ����� - ��� �������� �������� ��������. ��� ������ �� ������� � ���������� � ������\n����� �����, ��� �� ���������, ��� ����� ����� � ��� �������� �������������� �������. ��� �������������, �������, �� ������������ �� �������, �� ��� �� ����� ���������� � ��������� ����� ������� ���� ��������� ��� ������� ����� ������������� �� ����� ���������� �����\n���� � ���, ��� ��� ������ ��� �� ����� �������� �������� ���������, � ������� ����� �� ������� ��������� � ������� ���-�� ��� � �� ����. ��� � � ���� ���������� ��� ����������� ����� � ����. ��� ����� ������ �����, � ��� ������ �������� �������.";
			link.l1 = "������ ������� ������ ��������?";
			link.l1.go = "Sergio_28";
		break;
		
		case "Sergio_28":
			dialog.text = "� ������� ������ � ���� ����������� ��������� ����� ��� ��� � ��������� ������ � 60 �����. � �������� - ������ ������� � ����� ������� �� �����, �� �������� ���������� �������. ������� �����������, ��� ������� ������ ����� ������ � ���� ������������ ����, �� ����, � ���� �� ������ ���������� ����� - �� ����������. ��������� ����� ����� ���� - ������ ������� ��������\n������ �� ��� ������ ����������� �����, ����� ��� � ���������. ���� �� �� ������ ������ ����� - �� � ������� ������������ ����� ������ �����������, ���� ���� �����������. �� ����, ����� ��� �� ���������, ������ ���� ������ �������. �� �����?";
			link.l1 = "�������� �����������. �������, ������������!";
			link.l1.go = "Sergio_29";
		break;
		
		case "Sergio_29":
			dialog.text = "������������. ����� ������� ������ ����� � ���� ��������� �� ����� ������ ������-����������� ��������� ����������, ������, ��� �� ����� ���������.";
			link.l1 = "������. ��� � ��������.";
			link.l1.go = "Sergio_30";
		break;
		
		case "Sergio_30":
			dialog.text = "� ���, ��� �� ������������. � ������ - �� �������, �������!";
			link.l1 = "����� � ����� �������� ����, ������.";
			link.l1.go = "Sergio_31";
		break;
		
		case "Sergio_31":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 5);
			pchar.questTemp.OilTrade = "true";
			pchar.quest.Oil_fail.win_condition.l1 = "NPC_Death";
			pchar.quest.Oil_fail.win_condition.l1.character = "Sergio";
			pchar.quest.Oil_fail.function = "Oil_TradeFail";
			AddQuestRecord("Unique_Goods", "4");
		break;
		
		case "oil_trade":
			dialog.text = "�����������, ������ �������! �� ������ �� ����� ������� ����, ��� � �������?";
			link.l1 = "��� �����, ������ ������. �� ������?";
			link.l1.go = "oil_trade_1";
			link.l2 = "������ ������, ��� ���� �� �� ��������. ��������, ������� �����.";
			link.l2.go = "oil_trade_exit";
		break;
		
		case "oil_trade_exit":
			DialogExit();
			NextDiag.CurrentNode = "oil_trade";
		break;
		
		case "oil_trade_1":
			dialog.text = "��. ����� ����� �������� ��� ���?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 600)
			{
				link.l1 = "����������. ���, �������� ���� ������.";
				link.l1.go = "oil_trade_2";
			}
			else
			{
				link.l1 = "��� ��������, ����� ������ �� �������. ������ �������!";
				link.l1.go = "oil_trade_exit";
			}
		break;
		
		case "oil_trade_2":
			chrDisableReloadToLocation = true;//������� �������
			RemoveItems(pchar, "gold_dublon", 600);
			Log_Info("�� ������ 600 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "������� ����� � ���� ����, �������. ��� ���� ������� ��������� ����� �� ��� �������.";
			link.l1 = "�������!";
			link.l1.go = "oil_trade_3";
		break;
		
		case "oil_trade_3":
			dialog.text = "������� �������� � ����. ���� ������� ������ ��� ������ - ��� ��� ����� �����.";
			link.l1 = "������, ������. �� �������.";
			link.l1.go = "oil_trade_4";
		break;
		
		case "oil_trade_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 5);
			AddCharacterGoods(pchar, GOOD_OIL, 60);
			AddCharacterExpToSkill(pchar, "Commerce", 200);
		break;
	// <-- ��������� ����
		
		case "Juan_abordage":
			dialog.text = "��� ��, ���� ���� ����!?";
			link.l1 = "��� ��� � "+GetFullName(pchar)+", � ���� ���� �����, �������, � �������, �� ����������!";
			link.l1.go = "Juan_abordage_1";
		break;
		
		case "Juan_abordage_1":
			if (CheckAttribute(pchar, "questTemp.Consumption.House"))
			{
				dialog.text = "���� ������� ������ ������� �� ������ � ��������� ���� � �����-������ ��� �����, ��� ����� �������� ����? ����� ������� ������, � �� ������� ��������, � � �������� �� ���� � �� ���� ������ ��� ����� ������. ���� ���� ����� ������ � ����! ������� ����������� ��������, � �� �������� ��� ���, � � � ����?";
				link.l1 = "������? � � ������ ������ �������� � ��� ���� �� ���� �����, ����. ���������� ����� �������� ��� �� � ���� �� ���� �������.";
				link.l1.go = "Juan_abordage_2";
				link.l2 = "����� ������� ��������? �� �� �������� ���� ����, ������� - �����, � ���� ���������� ���-�� ����� ������� ����� ������... ���������� ������ �� ������ �������� � ������ �� ���� ������ � �����...";
				link.l2.go = "Juan_abordage_3";
			}
			else
			{
				dialog.text = "������� ������ ������� �� ������, ��� ��� � ���� ����� �������� ��������, ��� �������?";
				link.l1 = "����� ��������, ������� - � ����!";
				link.l1.go = "Juan_abordage_5";
			}
		break;
		
		case "Juan_abordage_2":
			dialog.text = "� ���� ����� �� ������������... ��!";
			link.l1 = "�� ������ ���������� �� �� �����, ��� ��� �� ����� �� �������, �� ��������������. �� ����, �������, � ������ ������.";
			link.l1.go = "Juan_abordage_5";
		break;
		
		case "Juan_abordage_3":
			dialog.text = "� � ���� ���� ������, ��������... �����, ��� ���, ��� � ���� ���� � ��������� ����� �� �����, ���� ���������, ��?";
			link.l1 = "�� ���� ����� � �� �� ��� � ����������� ����, ��� ��� ��� ����� �������� ��� ������. ������ � ������.";
			link.l1.go = "Juan_abordage_4";
			TakeNItems(pchar, "gold_dublon", 1000);
			Log_Info("�� �������� 1000 ��������");
			PlaySound("interface\important_item.wav");
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			OfficersReaction("bad");
			pchar.questTemp.Consumption.TakeMoney = "true"; //������� ��� �������
		break;
		
		case "Juan_abordage_4":
			DialogExit();
			chrDisableReloadToLocation = true;
			sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
			Lai_SetPlayerType(pchar);
			LAi_RemoveCheckMinHP(sld);
			LAi_SetImmortal(sld, true);
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "ConJuan_AfterFight_1", 10.0);
		break;
		
		case "Juan_abordage_5":
			dialog.text = "���� ������, �� �� ������� ������ ���� � ���������� ����, ���� ���, �? ���� ����� � ����� ����...";
			link.l1 = "���������! ���� �������� �����... ���� � �����, �������� � �� ���� �������� ���� ��� ������!";
			link.l1.go = "Juan_abordage_4";
			link.l2 = "� � ��� �� ��������...";
			link.l2.go = "Juan_abordage_6";
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			OfficersReaction("good");
			sld = GetCharacter(NPC_GenerateCharacter("ConAndjelo", "citiz_9", "man", "man", 5, SPAIN, -1, true, "quest"));
			sld.name = "�������";
			sld.lastname = "";
			AddPassenger(pchar, sld, false);
			SetCharacterRemovable(sld, false);
		break;
		
		case "Juan_abordage_6":
			//LAi_SetCurHPMax(NPChar);
			//LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle("ConJuan_AfterFight_2"); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.Consumption.KillJuan = "true"; //������� ��� �������
		break;
		
		case "Waitress":
			dialog.text = "��... � ���� ��� ����... ����� ������!";
			link.l1 = "� ������ �� ���� ������� - ���! ��� ����. ��������!";
			link.l1.go = "Waitress_1";
		break;
		
		case "Waitress_1":
			DialogExit();
			AddQuestRecord("Consumption", "16");
			Consumption_Close();
		break;
		
		case "Waitress_2":
			dialog.text = "����������! ��... �� ��� ������ ������? �� �����������, ��� ��� ��� �����������!";
			if (CheckAttribute(npchar, "quest.Consumption.sex"))
			{
				link.l1 = "��������, � ��, ��� ���, �����������. �� � ��� ����� ������� ���������, ���� �� �����.";
				link.l1.go = "Waitress_3";
			}
			link.l2 = "� ������ ��, ��� ����������� ��� ���� - ������ � �����.";
			link.l2.go = "Waitress_5";
			if (CheckAttribute(pchar, "questTemp.Consumption.KillJuan")) AddQuestRecord("Consumption", "18");
			else AddQuestRecord("Consumption", "17");
		break;
		
		case "Waitress_3":
			dialog.text = "�... � ����! ��, �� �����. ���� ����, ��� � � �������... ������������ � ������� � � ��� �� ��� ����� �������.";
			link.l1 = "����� ��������!";
			link.l1.go = "Waitress_4";
		break;
		
		case "Waitress_4"://������������� �������
			DialogExit();
			LocatorReloadEnterDisable("PortSpein_tavern", "reload1_back", true); //������� �������
			LocatorReloadEnterDisable("PortSpein_tavern", "reload2_back", false); //������� �������
			bDisableFastReload = true;//������� �������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2_back", "PortSpein_tavern_upstairs", "goto", "goto3", "ConsumptionSexWaitress", -1);
			pchar.questTemp.Consumption.Sex = "true";
		break;
		
		case "Waitress_sex":
			dialog.text = "";
			link.l1 = "�� ���, �������, ����� �����������! ���� � ���� ������� ������������� ���������� ����...";
			link.l1.go = "Waitress_sex_1";
		break;
		
		case "Waitress_sex_1":
			DialogExit();
			DoQuestCheckDelay("PlaySex_1", 0.1);
		break;
		
		case "Waitress_5":
			if (CheckAttribute(pchar, "questTemp.Consumption.KillJuan"))
			{
				dialog.text = "�� ��������� ������! ���������! ���, �� ������� �� �����������, �� � ����, ����� �� ����� �� � � ������� ��� ������ �� ����� �� �������, �� ������ ��� ��� �� �����! �� ��������� ������������ � ������� ��!";
				link.l1 = "��� ��, � ���� ������� ���� �����, ��������� � ��� ���� ����������, ����� �������� �� �������, � �� �� ����. � �������� ��� ���. �������� � ����� ��� � �������.";
				link.l1.go = "Waitress_6";
				AddMoneyToCharacter(pchar, 5000);
			}
			else
			{
				dialog.text = "�� ��������� ������! ���������! � �������� ����! � ���� ������� ��� ������-������!";
				link.l1 = "��� ��, � � ���� ������� ���� ����� ��������� � ��� ���� ����������, ����� �������� �� �������, � �� �� ����. ����� ��� ����� � ������. ��������!";
				link.l1.go = "Waitress_6";
			}
		break;
		
		case "Waitress_6":
			DialogExit();
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			Consumption_Close();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}