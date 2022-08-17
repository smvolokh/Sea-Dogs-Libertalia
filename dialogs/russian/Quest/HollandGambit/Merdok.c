// ���� ������, �� �� ����� ��� ������, �������� ����������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;
	int iTemp;
	bool bOk;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
		if (!CheckAttribute(pchar, "questTemp.HWIC.Self") && LAi_grp_playeralarm > 0)
		{
			dialog.text = "�� �����, ������, ��� �� ������� ������� ����� ��� �����. �� ���� �������� ��������. ��� �� �� ������...";
			link.l1 = "�� ���������, ����� � � ���� ������ �� ����.";
			link.l1.go = "exit";
			break;
		}
		// ������� ������������� ������, ���� �������� ������
		if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && !CheckAttribute(npchar, "quest.alchemy"))
		{
			bOk = (findsubstr(pchar.questTemp.HWIC.Detector, "_fail" , 0) != -1) || (pchar.questTemp.HWIC.Detector == "eng_win_half");
			if (bOk)
			{
				dialog.text = "�����������, �������. �� ������������ �� ��� ���� �������� �����������?";
				link.l1 = "� ������ ��� ��������������, ��� ��� ������������ - ��� �� �����������?";
				link.l1.go = "alchemy";
				break;
			}
		}
		// ����� ������
		if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok1")
		{
			dialog.text = "������ ����. ��� ������ ��� � ���� ������. � ���� ���� ��������� �� ����������� ������ � �������. ��� ��� ����������?";
			link.l1 = "��������, ����, ��� ����� �����, ��� � ���� �� ������ ����� ����� ���-��...";
			link.l1.go = "guardoftruth";
			break;
		}
//-----------------------------------------�� ���������------------------------------------------------
		if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
		{
			if (pchar.location.from_sea == "SentJons_town" && pchar.questTemp.HWIC.Holl == "toAntigua")
			{
				dialog.text = "������ ����. ��� ������ ��� � ���� ������. � ���� ���� ��������� �� ����������� ������ � �������. ��� ��� ����������?";
				link.l1 = "������������, ������ ������. � ������ �� ������ ����������. �� ������������ ���� � ��� �� ������� � ������� ��������.";
				link.l1.go = "Knippel_exit";
				break;
			}
			if (pchar.questTemp.HWIC.Holl == "toAntigua")
			{
				dialog.text = "������ ����. �� ������ ������� �� ������? �������� �� �����, ��� ������� �� ������?";
				link.l1 = "������������, ������ ������. � ������ �� ������ ����������. �� ������������ ���� � ��� �� ������� � ������� ��������.";
				link.l1.go = "Knippel";
				break;
			}
			if (pchar.questTemp.HWIC.Holl == "KillMerdok")
			{
				dialog.text = "���, ��� � �������� ������� ����������... ������, �������! ����! � ���!";
				link.l1 = "�-�-��!";
				link.l1.go = "Merdok_fight";
				break;
			}
			dialog.text = "������ ����. ��� ������ ��� � ���� ������. � ���� ���� ��������� �� ����������� ������ � �������. ��� ��� ����������?";
			link.l1 = "���� ��� ������, �������. �� ��������� � ���� �� � �������.";
			link.l1.go = "exit";
			break;
		}
//----------------------------------------------�� ������---------------------------------------------------
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "MerdokMeeteng")
			{
			dialog.text = "������, �������� �����. �� �� ��������� ���� ��� ������ � �� ���������� �������. �� ���� � ����� �����, ��� ���� ����� �� ������� �������� ���-�� ������. �� �� �������� �� �� ������?";
			link.l1 = "���������� � ��, ����� ��� ������. � ������ �������� ���� ������ �� ������ �������. ����, ���� ������� ��� ���.";
			link.l1.go = "Merdok_talk";
			break;
			}
//--------------------------------------------������ ����--------------------------------------------------
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "HuntFleetwood")
				{
					dialog.text = "�, ��� � ��... �� ���, ���������� � �������?";
					link.l1 = "��. �� ������������ � ������ � ������ ����������. ����, � ������� ������ ������, � � ���� � ���� ���� ��������� �������� � ������� ��������.";
					link.l1.go = "About_Fleetwood";
					break;
				}
				if (GetQuestPastDayParam("questTemp.Wait_Fleetwood") > 6 && pchar.questTemp.HWIC.Self == "WaitFleetwood")
				{
					dialog.text = "�����������! ��� ���� ������, " + pchar.name + "!";
					link.l1 = "����������, ����. �� ����� ���-������ � ��������?";
					link.l1.go = "About_Fleetwood_9";
					pchar.quest.Wait_FleetwoodOver.over = "yes"; //����� ������
					break;
				}
				if (pchar.questTemp.HWIC.Self == "HWICSelf_fail")
				{
					dialog.text = "�, ��� � ��. � ����� ���� ������ ������? � �����, ������ �������� � ���� �� �����. ����� �������� ������� � ����������, ������ ������ ���� ������� �������, � ��� �� ��� �� ���� �������� � ������� �������� � ������. ��� ���.. �� ���� ���� ��� �� ���������.";
					link.l1 = "����. ��, ������� � ������� ������ � ������ ��� ������� �������. �����, �����.";
					link.l1.go = "About_Fleetwood_17";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileOnShip")
				{
					dialog.text = "� ������������, " + pchar.name + "! ��� ����������? � �������� ������� �������� ���, ����� �������� ���� ��� �� �������� � �������...";
					link.l1 = "� �� ��������. �� ��, �� ��� ����������.";
					link.l1.go = "Abigile";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileInHouse")
				{
					dialog.text = "�-�, ����� � ��� �����! ����������, �����! ������ ����, ����!";
					link.l1 = "������ ����, ����! ������� ���� ����������� ���� ������� ������, ������� ������� - �������������� �������� �����.";
					link.l1.go = "Abigile_7_1";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileInRoom")
				{
					dialog.text = "������ ������... ��� �� ������� ������ ������?";
					link.l1 = "������? � �� ��������, �� �������, � ���������, ���. ������ � ������� �������� �������� �� ��� ����, ���� �� ����������, �� ���� �����, � ��������� ����, ������� �������.";
					link.l1.go = "Abigile_9";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "LetterToFleetwood")
				{
					dialog.text = "��, �������? ���-�� �����... �-��... ��, �� ����������� ������ ���, �������! '���� ��������� �� ������ �� ���� ����� �������, ��� � ����� �� ��� ������ - ����� ���� �� �������� � ������� ����� � ��� ����� �������. ���� �� ��������� �������� � ������� ������ - �� � ������ �������� ������ � ������ ����.' ��-��-��! � ���� ����������� ������!";
					link.l1 = "� ������, ����. � �� ���� �� ������� ������� � ����� ������... ����� ��� ������ �������� �� ������������ �� ���������, �� �� �����.";
					link.l1.go = "Abigile_15";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "FleetwoodAgree")
				{
					dialog.text = "��, ��� ��� ������? ���� �� ������� ������, ��� ���� �� �������!";
					link.l1 = "��. ������� ������� ����� � ������ ��� �������. ������� ������������. ������ ���� �� �����.";
					link.l1.go = "Abigile_23";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "FleetwoodDied")
				{
					dialog.text = "�-�, � ������������, ��� ����! ��, ��� ����������?";
					link.l1 = "������� �����. ��� ������ �� ����� - �� ������ �� ������, � � ����������� ������ � �����. ������, �� ���� �������� �� ����� ���... �� � ����� ����! �� � ���, � �� �������� ��������� � ���� �����.";
					link.l1.go = "Abigile_27";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "MeetTonzag")
				{
					dialog.text = "" + pchar.name + ", � ���� � ���� ��������� �����������. ����, � ������� � ������ ����, ����� ����� �������, ��, ���� ��� �� ���������� � ���������, ������, ��� �� � ���� ����������. � ���� ������������� ������ � ��������� ���� �����.";
					link.l1 = "�� �����, � �������, ����. ���������.";
					link.l1.go = "Lucas";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SeekAbiIsland")
				{
					dialog.text = "� ������������, " + pchar.name + "! ��������� ���� ���������?";
					link.l1 = "������ �� ������ ����� ��������, ����. ����� ���� ����� �� ��������. �� ��������� � ������� � ������, � � ��������� ����� ��� �������� � ����������, ��� ����� ������ �� ������� ������� ������, ��������� �� �������� � �� ������ �����.";
					link.l1.go = "Lucas_10";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "VanbergDestroyed")
				{
					dialog.text = "��� ���� ������, " + pchar.name + "! �� ��� - ��� ������� ����. ���� �������?";
					link.l1 = "��. � ��� ������ ���������. ��� �� � ������ - �� �������� ���� � ����� � ����� ������������ ������. � � ��� ���������, ������, ��� ���� ����� � ����� �������.";
					link.l1.go = "Final";
					break;
				}
			dialog.text = "�� ���-�� ��� ����� ��������?";
			link.l1 = "���, ����, ������. � ��� �����.";
			link.l1.go = "exit";
			break;
			}
			dialog.text = "������ ����. ��� ������ ��� � ���� ������. � ���� ���� ��������� �� ����������� ������ � �������. ��� ��� ����������?";
			link.l1 = "���� ��� ������, �������. �� ��������� � ���� �� � �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

//--------------------------------------------�� ���������-----------------------------------------------------
		case "Knippel_exit":
			dialog.text = "� �� ������� � ��� �� ��������, ���. ����� ����� ���������? � �� ������� � �����������, ��, ��������, ���-�� ��������.";
			link.l1 = "�� ��� ��! ������ ��������� �������� ���� � ���...";
			link.l1.go = "Knippel_exit_1";
		break;
		
		case "Knippel_exit_1":
			dialog.text = "� ��� ��� ��� ������ - � �� ���� �������� ������� ����������. � ���� ��� � ������� ��� �������� ����������. ���� � ��� �� - �������� ��� ��� � �� ������� ��� ��������.";
			link.l1 = "�� ����...";
			link.l1.go = "exit";
		break;

		case "Knippel":
			dialog.text = "���-���... �� �� ������� ����������? ������. � ��� ������.";
			link.l1 = "��� ���������� ������������ ������� � ��������� ���������... � ��������� �����. � ������������� � ����� ��� ����� ��� ���������� '�����', ������� ��� ����� ������� ��������, � ��� �������� ��... ��������� ������� �� ��� ��������, ��� '�����' � ��������� ����� ����� � ������� ��������.";
			link.l1.go = "Knippel_1";
		break;
		
		case "Knippel_1":
			dialog.text = "���� ����� ��� ���� �������? ����������... ��� � �������, ������ ��� ����� �������, ������� ���� �� �������� ������� ��������, ��� '�����' ���������� � ������� ��������, ��� ���� ��, ��-��, ������� �� ���� ������� �� ������, �� ������������ ��������...";
			link.l1 = "������ ���. ������ ��������� ������������ �� ����� ������� ���������� ������ � ���.";
			link.l1.go = "Knippel_2";
		break;
		
		case "Knippel_2":
			dialog.text = "� ����� ������ ��� ����� ����� ��������. ��� ������� ���� ������� �������� � ��� �������. ���������� � ���, � � ��������� ��������� ��, ��� ������ ������� �� �������. ������ ������ ��������� - �������� ���� � ������� �� ������, �� ������ �� �����\n����� ��� �� ������� � ��������� ������, ������ ������� �� �������� ������, �������� �� ����. �� ������ ���� ���.";
			link.l1 = "� �� �����. �������, ������ ������. �� ��������!";
			link.l1.go = "Knippel_3";
		break;
		
		case "Knippel_3":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "toKnippel";
			AddQuestRecord("Holl_Gambit", "1-16");
		break;
		
		case "Merdok_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			sld = characterFromId("Tonzag");
			PlaySound("VOICE\Russian\hambit\Ercule Tongzag-04.wav");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			//� ��� � ������ �����������
			sld = characterFromId("Longway");
			LAi_SetWarriorType(sld);
			FantomMakeCoolFighter(sld, 18, 40, 40, "blade_08", "pistol1", "bullet", 70);
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl.LongwayEnemy"))//����
			{
				ChangeCharacterAddressGroup(sld, "SentJons_TownCave", "monsters", "monster8");
				LAi_group_MoveCharacter(sld, "EnemyFight");
				PlaySound("VOICE\Russian\hambit\Longway-02.wav");
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl.LongwayFriend"))//����
			{
				LAi_warrior_DialogEnable(sld, true);
				sld.Dialog.Filename = "Quest\HollandGambit\Longway.c";
				sld.dialog.currentnode = "Longway_hire";
				ChangeCharacterAddressGroup(sld, "SentJons_TownCave", "monsters", "monster8");
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				PlaySound("VOICE\Russian\hambit\Longway-02.wav");
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl.LongwayNeutral")) sld.lifeday = 0;//������� - ������ ���
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "Merdok_AfterBattle");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
//-------------------------------------------------�� ������-----------------------------------------------------
		case "Merdok_talk":
			dialog.text = "��� ���? � � �������, ��� ������� ������ ��� ����� � ���.";
			link.l1 = "��������. � ����� ��� ������ � ������� ������� ����� �� �������. �� �� ����� �������� ���� ������ � ������, ��� � ��� � ��������� ��� ���� ����� ����. � ������ �������� ���������, ������� �� ����������, ���� �� �� ��������� ������� ��������. ������ �������, ��� � ���� ���� ������ ��� ������ ������, ������� ����� �� �������� ��� � �������.";
			link.l1.go = "Merdok_talk_1";			
		break;
		
		case "Merdok_talk_1":
			dialog.text = "�� ����. ��� ��� �����, ������� �� ���� ���������� �����. ������, ������ ��-�� ���� �� ��� �����. ���� � ���, ��� ��� ������� ������ �������� � ������ ���������� ��������. ���� �������� �� ������, � ������� ���� ����� ����������� � ������� � ��������� ������, ������� ������� �������, ��� ������� ����� ���������. ������ ����� �� ����� � ��� ����� ������ ������, ������� ����� �� ��� � ���� ������.";
			link.l1 = "����� ��� ���� ����� � � ���������� � ����� �������.";
			link.l1.go = "Merdok_talk_2";			
		break;
		
		case "Merdok_talk_2":
			dialog.text = "� ��� ��� ��� ������ ������, ��� �� � ����. ������ ��� �����, ��� �� �� ������������ � ������?";
			link.l1 = "���� �������� �������� ��� �� �����, ��� �������.";
			link.l1.go = "Merdok_talk_3";			
		break;
		
		case "Merdok_talk_3":
			PlaySound("VOICE\Russian\hambit\John Mardock-07.wav");
			dialog.text = "�������� � ������������� ����� ����, �� �� �������� ����� ������! �������, ����!";
			link.l1 = "��, � ������ ���� ���...";
			link.l1.go = "Merdok_fightEng";			
		break;
		
		case "Merdok_fightEng":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");	
			sld = characterFromId("Longway");
			FantomMakeCoolFighter(sld, 20, 50, 50, "blade_08", "pistol1", "bullet", 80);
			LAi_SetWarriorType(sld);
			ChangeCharacterAddressGroup(sld, "SentJons_TownCave", "monsters", "monster8");
			PlaySound("VOICE\Russian\hambit\Longway-02.wav");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "Merdok_AfterBattleEng");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
//----------------------------------------������ ����-------------------------------------------------------
		case "MC_InHouse":
			PlaySound("VOICE\Russian\hambit\John Mardock-02.wav");
			dialog.text = "��, ������� �� ������ �� ����. � ��� �����, ��� ������� �� ����������.";
			link.l1 = "���... ������ ����. ��� ��? �, ����������, ��� �? � ��� ���� �����?";
			link.l1.go = "MC_InHouse_1";	
		break;
		
		case "MC_InHouse_1":
			dialog.text = "����-����, �� ���� �������� ������� �������� �����, ��� ������ �����������. ���� ����� ���� ������, � �������� ������ ����-�����. �� �������� �������� � ������ � ������� ��������. ���� �������, ������� ��� �������... � �������� ��� ����, � ��� ������, ������, ��, � � ������� ���� ���� ������ ����������.";
			link.l1 = "������? ��� ���? ��� �� ��� �� �������, ��� ������ ��� �� ������ �� �����?";
			link.l1.go = "MC_InHouse_2";			
		break;
		
		case "MC_InHouse_2":
			dialog.text = "��, ������ ��. ������, �� ������ ������������ � ����. ��� ����� ����� ���������� � ��� � ������, ������ ����� ����� ��������� ���, ������� ���������� �� ������ �� ������ ����� ����� ����. ������ �������� �� ����� ��� ������������ - ���-��� �� ������� �������� �������� ��� � ������ ��������.";
			link.l1 = "�������... � ��� ��� �������?";
			link.l1.go = "MC_InHouse_3";			
		break;
		
		case "MC_InHouse_3":
			if (pchar.Ship.Type == SHIP_NOTUSED)
			{
				dialog.text = "��� ������� ��� ���������, � ������� �����������, ��� ����. ���.";
				link.l1 = "��, ��� ������...";
			}
			else
			{
				dialog.text = "����� � �����, ��� � �����.";
				link.l1 = "��� ������. � �� � �������������...";
			}
			link.l1.go = "MC_InHouse_4";			
		break;
		
		case "MC_InHouse_4":
			dialog.text = "��� ���� ���������� � �������. ����� �������� ����� ���������� � �����. �� ��� � ��� ��������. � ���� - ���������, � ��� ���� ��������� � ������.";
			link.l1 = "������, ����. �... ������� �� ������ � �� �������!";
			link.l1.go = "MC_InHouse_5";
		break;
		
		case "MC_InHouse_5":
			NextDiag.CurrentNode = "First time";
			DialogExit();
			npchar.greeting = "merdok_2";
			AddQuestRecord("Holl_Gambit", "3-12");
			pchar.questTemp.HWIC.Self = "MainBegin";//����� ���� ������
			sld = characterFromId("Bridgetown_tavernkeeper");
			sld.model = "barmen_3";
			sld.greeting = "barmen_1";
			sld.name = "�����";
			sld.lastname = "�������";//���������� ������� ����������
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload1", true);//������� ����� �� ������ ����� �����
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload2", false);//������� ���������� �� ����
			LocatorReloadEnterDisable("SentJons_TownCave", "reload1_back", false);//������� ��� �� ����������
			pchar.quest.Tonzag_Meeting.win_condition.l1 = "location";
			pchar.quest.Tonzag_Meeting.win_condition.l1.location = "SentJons_town";
			pchar.quest.Tonzag_Meeting.win_condition.l2 = "Night";
			pchar.quest.Tonzag_Meeting.function = "TonzagMeeting";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "SentJons_HouseF3", "goto", "goto1", "MC_TakeCloves", -1);	
		break;
		
		case "About_Fleetwood":
			dialog.text = "� ��������? ��� �� ������ � ��� ������?";
			link.l1 = "���. ��������� ���, ��� ���� ��������. ������� ���, ��� ��� ���� �� ������, ��� ���� ������ ������ �� �������. � ���� � ����� �������, � �������� �� ������� ������.";
			link.l1.go = "About_Fleetwood_1";
		break;
		
		case "About_Fleetwood_1":
			dialog.text = "��� � ���� ������� � ��������... ������� ����, ������� �����. ����� � ����� ������������ ���� �� ����� '���������' - �������� �����, ���� �������� - � �������� �������� ��������. �������� � ���������� � ����� � � ����������� ����-������� ��������� � ���������. ������� ��������� ���������� ����������� �������� ��������. ���������� ������� ��������� �� ��� ������ ������ ��������� ����.";
			link.l1 = "��... ��������� �������� ��� ������� ����������� ������������ �����...";
			link.l1.go = "About_Fleetwood_2";
		break;
		
		case "About_Fleetwood_2":
			dialog.text = "��, ��� ���. �� ����� �� �����. ������ ���������� �� �������� ��� �������� � �������������, �� ��������� �������� ��� ������. � ���� ���� ��������� ��������, ��� �� ���-�� ������ � ���������� ������� ���������, � � ����� �������� ����� �����.";
			link.l1 = "��������� ��������... ��� ��? ������ ������� ��� ������-�� ��� ����������, �����... ��� ���... �������, ��� ����?";
			link.l1.go = "About_Fleetwood_3";
		break;
		
		case "About_Fleetwood_3":
			dialog.text = "��������? ��, ���� �����. ����� ��������, ��������� ������� �����, ������ � ���������� ����� ���������. � ��������� ����� ����� ����� ����� �� ������. ����� � ��� �������� � ����-������, ��� ��� ���� � ��� ��������� � �� ������� ������������� ��� � ������� - ���� ��������� � ������.";
			link.l1 = "�������. ���-������ ��� ���������� ��� �������� ����������?";
			link.l1.go = "About_Fleetwood_4";
		break;
		
		case "About_Fleetwood_4":
			dialog.text = "����� ����� �������� ��������� ������� �� ����������� �� ����������� ���. ������ ����� ��� � ������ � ��� �������... ��, � ��� � ��� ������ ��������� - �����, ������. ����� ���� � ���������� ����.";
			link.l1 = "��������, ����, �����, � ���� ���� �����-�� �����������, ������ �����...";
			link.l1.go = "About_Fleetwood_5";
		break;
		
		case "About_Fleetwood_5":
			dialog.text = "��� �� ������ � ����?";
			link.l1 = "��, �����, �� ����� ������ � �����, ��� �������� ������, ��� �� �������� �����. �� �����?";
			link.l1.go = "About_Fleetwood_6";
		break;
		
		case "About_Fleetwood_6":
			dialog.text = "������. � ��� �������� ����� ����������, ��� �� ���������� - ����� �� ��� �� �������.";
			link.l1 = "�������. �� �����, ���-�� ��������� ���-���� ����? ������ �� ���� � � ���� �������� �����!";
			link.l1.go = "About_Fleetwood_7";
		break;
		
		case "About_Fleetwood_7":
			dialog.text = "�� ����... ��������, ����� ������� ���: ������� ���� ����� ��������, � � �� ��� ����� �������� ������� �����-������ ����������, ���������� ��������. ������������?";
			link.l1 = "������������. ������� ����, ����! ���� ����� ������.";
			link.l1.go = "About_Fleetwood_8";
		break;
		
		case "About_Fleetwood_8":
			DialogExit();
			pchar.questTemp.HWIC.Self = "WaitFleetwood";
			SaveCurrentQuestDateParam("questTemp.Wait_Fleetwood");
			SetFunctionTimerCondition("Wait_FleetwoodOver", 0, 0, 12, false);//����� �� ���������
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload1", false);//������� ����� �� ������
	                                LocatorReloadEnterDisable("SentJons_town", "HouseF3", false);//������ �������
			AddQuestRecord("Holl_Gambit", "3-14");
		break;
		
		case "About_Fleetwood_9":
			dialog.text = "��, �� � ���������, �������, �� � ������ �� ���� ��� ����������.";
			link.l1 = "�����������! � ���� ��������! ��� ���� ����� ������ ������, ���� �� ��� �������� ��������.";
			link.l1.go = "About_Fleetwood_10";
		break;
		
		case "About_Fleetwood_10":
			dialog.text = "�� ��� ����� ������ ���� � ������������ ������� ���� ��������� �������� - ���� � ����, ������� � ����������. �������, �� ������� ��� ��������������, ��� �������� ����� �������. �������, � ������ ���� ������������, ����� �� �� �������. � ����� ������� ������ ��� ��������� �������. � ������ �� �������� � ���������� ������ ������� ��� ����� ��������...";
			link.l1 = "��... � ����� ��� �����?";
			link.l1.go = "About_Fleetwood_11";
		break;
		
		case "About_Fleetwood_11":
			dialog.text = "��� ������� ������, ��� ����� ������� ������ �������� �� ������� �� ����������� ����� ������... ������� �� ����� �������� �����. ��-��, �� �����, � �������. ������, �� ����� ����������� �� ����������� ������ ������ �������� � ���, ��� �������� �� ��� � ����� ������ ������ ������ ��������\n��� ���. �� ����, ��� ���� ���� ����� ���������� ��� ����������, �� ������ ��� ����� ���.";
			link.l1 = "��... ����, �� ��� �� ������ �������! ��-��-��! ������, ��� ����� �������... �� ��� ��! ������� � ��������� ���� ������. �������! ����, ����� �������� ������������ �� �������?";
			link.l1.go = "About_Fleetwood_12";
		break;
		
		case "About_Fleetwood_12":
			dialog.text = "�� ��� ����������. �����.";
			link.l1 = "����! ����� � ���� �������?";
			link.l1.go = "About_Fleetwood_13";
		break;
		
		case "About_Fleetwood_13":
			dialog.text = "� ����, ��� �� ��� ��������. ���������� ������������ ����� ������. �������� - '�������'.";
			link.l1 = "'�������'? � � ����� ��� ��� ���������� ������� �������� ������ �������? ����, � �����!";
			link.l1.go = "About_Fleetwood_14";
		break;
		
		case "About_Fleetwood_14":
			dialog.text = "�� ������ �����������... �� ��������� �������� - '����� ����', �� �� ���� ���� ��� ����� '�������'. � ������� ��, ����� ���� ��� ����������� ������.";
			link.l1 = "�� ������ ��� ���������� ������, ����. � ����������� � ����. ����� �������, �... ��� ����������� ���� ������� �� ������ �����, ��� �� ���� �����.";
			link.l1.go = "About_Fleetwood_15";
		break;
		
		case "About_Fleetwood_15":
			dialog.text = "��� �� �������?";
			link.l1 = "� �������, � ��� �������. ������� ��� �����, ����! ����.";
			link.l1.go = "About_Fleetwood_16";
		break;
		
		case "About_Fleetwood_16":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-16");
			pchar.questTemp.HWIC.Self = "HuntKnippel";
			SetFunctionTimerCondition("HuntKnippelOver", 0, 0, 10, false);
			pchar.quest.Hunt_Knippel.win_condition.l1 = "location";
			pchar.quest.Hunt_Knippel.win_condition.l1.location = "Curacao";
			pchar.quest.Hunt_Knippel.function = "CreateKnippelShip";
			LocatorReloadEnterDisable("SentJons_town", "houseH1", true);//������� ������ �����
		break;
		
		case "About_Fleetwood_17":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-15");
			pchar.questTemp.HWIC.Self = "end";
			pchar.questTemp.HWIC.Detector = "self_fail";
			CloseQuestHeader("Holl_Gambit");
		break;
		
		case "Abigile":
			dialog.text = "��� ���? � ������ ����� �����������?";
			link.l1 = "������ ��� ����� �� ���, ������ ���. � ����������� '�������', � �������� ��������������� �������� � ��������. �������, �������������� �������� � ������������... ��� ��� ��������� ������, ������� ��������� ��� ������ ���� �� �������� � ��������� � ��������, ��, ��� ��������, �������� ������ ������� �������...";
			link.l1.go = "Abigile_1";
		break;
		
		case "Abigile_1":
			dialog.text = "���... ����. �� ������ ������� ���...";
			link.l1 = "��. � ������ �� �� �������. ������ ��� � ���� �� �������. ������ � ���� ���� �������� ��� � ���� ������ ��������! �� �� ������ ������ ���� ���...";
			link.l1.go = "Abigile_2";
		break;
		
		case "Abigile_2":
			dialog.text = "�� ������? �����, ��� �� ��� �������, ��� �� �������?";
			link.l1 = "������. �� ������ ��� ����� ����, ��� ������ �������� ���������� �� ����� � �������� ��-�� �����. ��� ���, �� ����� ��������� �� ������� - ����������� ���, ����� ���� - ����� 200 000 ����! �����, ����� �� ������� �� ����� ����� ����� �����?";
			link.l1.go = "Abigile_3";
		break;
		
		case "Abigile_3":
			dialog.text = "���! � ����� ����� �� ��������. " + pchar.name + ", �� ��������� ���� �����. ����� ���� ���������� ����?";
			link.l1 = "� ������� �������� ���� � �� �������� �� � ���� �������. �� � �����, ��� ������ ���� � �������� � ��� �� ��������, ��� ��� �������� �������� ��������� � ���. ��� �� �� ��� ��� ������, ��� � ����� ��������...";
			link.l1.go = "Abigile_4";
		break;
		
		case "Abigile_4":
			dialog.text = "�������. ������, �� ����� ��������� �������� � ���� ����? ��...";
			link.l1 = "����, ��� ����������� ��������. � ��� ������, ��� � ����-������ ��� ����� � ����� �� �����. ��� ���� ������� �� �������, ���� ���. ����� � ��� ��� �� �����. �� � ������, ��� ���������. � �� ������� � ������ ��������, � ����� ��� ����� ��� �� �����.";
			link.l1.go = "Abigile_5";
		break;
		
		case "Abigile_5":
			dialog.text = "�������, �� �� ����������� ����� ��������� � ��� ��� ��, ��� � ���������?";
			link.l1 = "���, �������. � ���� � ���� �����, �� � ��������� ��������� �� ����. �� � � ����������� ����. ���� ����� ����� ���� ��������, ����� ��� ����������, � ������ �� � ���������� � ����.";
			link.l1.go = "Abigile_6";
		break;
		
		case "Abigile_6":
			dialog.text = "�-�... ������, ��� �������� �� ��� �������������?";
			link.l1 = "����, � �� ���������. ���� �� ������������� ������ - ������, ��� ��������� � ���� �� �������. �� ������ ����� � ����� ������������ �������� ������ �� ��� ������� � ������� � ���� � ������, � ��� ����� ������ ������ �� �������.";
			link.l1.go = "Abigile_7";
		break;
		
		case "Abigile_7":
			dialog.text = "�� ���, ����� �� ������. �������, �������. ������ ���� �������� ������ �������� - � ������ ������. ������� ��, � ���������� �������.";
			link.l1 = "�������, ����. � ����, ��� �� ���� ����� ������������.";
			link.l1.go = "exit";
			pchar.questTemp.HWIC.Self = "AbigileInCabin";
			DoQuestCheckDelay("SetAbigileToCabin", 1.0); // fix 180812
			AddQuestRecord("Holl_Gambit", "3-24");
			//�������� �������
			sld = ItemsFromID("lcheer");
			sld.shown = true;
			sld.startLocation = "SentJons_HouseF3";
			sld.startLocator = "goto2";
		break;
		
		case "Abigile_7_1":
			dialog.text = "�! ����� �������. ��� �������������� ����� ������������ �... ����� ���������� �����. ����, ����������, ������������ �� ������ ���� � ������� - ��� ��� ��� ��� ������ ���� � ���������� �������. ������, �� ������ ���������� ��������� ����� ������� �����������.";
			link.l1 = "��. ��������, �������, ������ ����� �������� �� �����������.";
			link.l1.go = "Abigile_8";
		break;
		
		case "Abigile_8":
			DialogExit();
			sld = characterFromId("Abigile");
			sld.dialog.currentnode = "Abigile_kidnapping_11";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Abigile_9":
			dialog.text = "� ���� ��� ���� ����?";
			link.l1 = "����. ����� �������� ���������� ������ ������� � ����������� ������ �� ��������. ��������� ������� ���-������ �� ����������� �������, ��������, �� ������. � ���� �� ������ - ���, ������ ��� ��� ������� �� ������.";
			link.l1.go = "Abigile_10";
		break;
		
		case "Abigile_10":
			dialog.text = "� � ���� ����� ��������� � ����������� ��������?";
			link.l1 = "��� ����������. � �� �� ��������� ������ ���� �������� � ����������� �� �� ������. ��� ����� ��� �������. �� ������� �� ��������� ���������� ������, � �� ������ � ���� ����������� �� �����.";
			link.l1.go = "Abigile_11";
		break;
		
		case "Abigile_11":
			dialog.text = "�������. ��� ����� ���������� ������? ��� ����� ������� ������.";
			link.l1 = "�����-������ ����������� �������. ��������, ������� �� �������. �� ���� ����� �� ������� ��� � �� ����� �������. � ���� ������ ����� ��� � ������ �����, ��... ������� �������. ������ ������ �� ������ ������� �������� �������� � �����-������ �� ��������� ���. ����������, �������.";
			link.l1.go = "Abigile_12";
		break;
		
		case "Abigile_12":
			dialog.text = "" + pchar.name + "...";
			link.l1 = "����, �� ����������. � ������, �� ����� ���� �� ������. � �����, ���� ����� ������ ���������, � ������ � �������� ����� ������. � ���� ���� ������ � �������?";
			link.l1.go = "Abigile_13";
		break;
		
		case "Abigile_13":
			dialog.text = "����. � ������� ���� ����. ���������� ����� ���������. ������ ����� �� �������� ����� � �������, ����������� �����. �� ����� ��� �������.";
			link.l1 = "�������! ����� ���������� �������������� - ���� �������� ������� �������� �������...";
			link.l1.go = "Abigile_14";
		break;
		
		case "Abigile_14":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto2", "MC_writeLetter", -1);
		break;
		
		case "Abigile_15":
			dialog.text = "����� �� ������� ������ ������? �� � ������ ������ ������� �� ���������?";
			link.l1 = "�������. ������ ������ �� �����, � �� ����� ���� ����� ���������� ������ �� ���������. ���� ���� ��. �� ����o� ������, � �� ��� �������. � �� �� ����� ��������� ���� ���� ����� �������. ��, ���� ��������� ������ �������. �����... ��� ��� ���?";
			link.l1.go = "Abigile_20";
		break;
		
		case "Abigile_20":
			dialog.text = "���� �������� ��� �����. ������ �� � ������� ������� ������. ���� ��������!";
			link.l1 = "��� ����� ������. ��� ����.";
			link.l1.go = "Abigile_22";
		break;
		
		case "Abigile_22":
			DialogExit();
			LAi_SetOwnerType(npchar);
			pchar.questTemp.HWIC.Self = "LetterToDrunkardGo";
			AddDialogExitQuestFunction("CreateDrunckardInTavern");
			AddQuestRecord("Holl_Gambit", "3-25");
		break;
		
		case "Abigile_23":
			dialog.text = "��, � �� ��� �� ������. ������� ����� � ������. � ���� �� �� ������� ������������ � �������� �����. ������ ������� �� ����� �� �����.";
			link.l1 = "� � � �� ��� ������ ����� � �����... �����, ����, ��� ���� ����������� � ����. ������, �� �������, ��� � ������ ������� ����� ������� ��������?";
			link.l1.go = "Abigile_24";
		break;
		
		case "Abigile_24":
			dialog.text = "� ���� ������ ���� �� ����, ����� � �����-���� �����. � ����� � ������, ������ ���.";
			link.l1 = "��� � ������... ����� ������� �������. ��, � �������� �����!";
			link.l1.go = "Abigile_26";
		break;
		
		case "Abigile_26":
			DialogExit();
			pchar.questTemp.HWIC.Self = "FleetwoodToIsland";
			pchar.quest.Fleetwood_meetingShore.win_condition.l1 = "location";
			pchar.quest.Fleetwood_meetingShore.win_condition.l1.location = "Shore56";
			pchar.quest.Fleetwood_meetingShore.function = "InTerksShore";
			AddQuestRecord("Holl_Gambit", "3-28");
		break;
		
		case "Abigile_27":
			int iVal = 0;
			for(i = 0; i < COMPANION_MAX; i++)
			{
				iTemp = GetCompanionIndex(PChar, i);
				if(iTemp > 0)
				{
				sld = GetCharacter(iTemp);
				if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_VALCIRIA) iVal = 1;
				}
			}//���������� ������� ������� ��������� � �������.
			if (iVal != 0)
			{
				dialog.text = "� ���� ��� ����! ������������ ����������, �������� ������� � ���������� ����������! ����������, " + pchar.name + "! �� ��� � ��� ���� ���� ��������!";
				link.l1 = "�������! � ��� ������? � �� ����� ��� �������. �� ����� ����� ��������� ������� �� ������, ��� � ���� ����� ��� ����� ����.";
				link.l1.go = "Abigile_28";
			}
			else
			{
				dialog.text = "�������� ������! ������������ ����������, �������� ������� � ���������� ����������!  ����������, " + pchar.name + "!";
				link.l1 = "�������! � ��� ������? � �� ����� ��� �������. �� ����� ����� ��������� ������� �� ������, ��� � ���� ����� ��� ����� ����.";
				link.l1.go = "Abigile_28";
			}
		break;
		
		case "Abigile_28":
			dialog.text = "� ��� ������ � ���� �� ���. �� ������ ������ ����� ����������. � ���� ����� ����������� � ��������. ���, ������, ��� �������� ������������ �� ������ ���������� �������.";
			link.l1 = "������. �����, ���� �� �� � ����� ���������?";
			link.l1.go = "Abigile_29";
		break;
		
		case "Abigile_29":
			dialog.text = "������... � ���� ����� � ���� ��������. �� ������� ����� ������ ������, � �� ������� ��������. ����� �� ���-������, ��� �� ������. ����� ������� � ����������. ������������?";
			link.l1 = "������������, ����.";
			link.l1.go = "Abigile_30";
		break;
		
		case "Abigile_30":
			DialogExit();
			npchar.greeting = "merdok_4";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "SentJons_TownCave", "item", "berglar1", "", -1);
			pchar.questTemp.HWIC.Self = "AbigileLie";
			sld = characterFromId("Abigile");
			LAi_SetCitizenType(sld);
			AddQuestRecord("Holl_Gambit", "3-34");
		break;
		
		case "Lucas":
			dialog.text = "�� ��� ������ ������ ����� �������� �����. ��� �� ��� �����, � �� ������� ��������. ��� ��������� ��� - ����� ��� ������, � �� ��������� ������� � ������� ������� �� ������ ���������� ����������� ����-������� �������� ��������, � ��� ������ ����� �� ����-��������� ������ ����������.";
			link.l1 = "��� ���! ���������...";
			link.l1.go = "Lucas_1";
		break;
		
		case "Lucas_1":
			dialog.text = "������ ������� ��� ������������. ����� �����, ��� � ��� ������ �� �����, �, ����� ���� - ������ ��� ����. �� ����� ����� �� ����, ������ � ���������, � ���� ����������� ���� �� ��������� ��������, ��������� ��� �����\n� �����, ��� �� ��� ��� ��� ������ ������, ��� � ���� ���� �����, ���������� ��� �������� � ���������� ������������ ������, � ���������, � �������-��������, ������� � ���������������� ������� ��������� ������� ��� ������������� �������������� �������� ����� ��� �����, �������� ����������� ���������� ��� ����������� ���������� �������� ��������. �� ������ �� ���� �����\n������ ��� ���� ������ �� ��� �����, �� ������� ����� ���� �������� � �� ����. �������� ���� �� ������� ������ - � ��� ���������... �������, �����, ��� ��� ����� ������� � ���� ���� - �� ���� ��������� �� ������ �������, �� � ��� ���������...";
			link.l1 = "��� ��� � ����� ���� ������ ����������� ������ ��������!";
			link.l1.go = "Lucas_2";
		break;
		
		case "Lucas_2":
			dialog.text = "��. ������ ������� � ��������� ���� ���� �� �������� �������� � ���������� - ��������, ��� ����� ��� ��������� ������ ������ ����������, ���� � �� ���� �� ��������� � ��� ���� - ��� ������� �������, � � �� ����� �� ������ �� ������. ���� �����, ��� � ������ ����� �������� � ������� ����� ��� ����� ������ �� ��� �����\n� �����, � ��������� ����... ���� ����� ���� ��������� �� ���� ������� ������ ������ ���������� � ��������� ��� ��� ��� ���� �����. ������� ����� ���������������.";
			link.l1 = "��... �� �����, ��� ��� ����� ������� �������, ��� � ���������.";
			link.l1.go = "Lucas_3";
		break;
		
		case "Lucas_3":
			dialog.text = "�������. �������, ��� ��� �����, ��� ��������� � ���������� �� ���� ����� � ����. ��������� - ����-�������� ��������, ���������� ��������� �������, �� � ��� �� - ����� ����������� �������, ������ ���� ����� �����������. ���� ��� ���� - ��� ����� ����� - ���� �� ��� �������, ���������� ���. ����� ��������� ��������� � �����������, ��� ������� ���������� ��������, � ��� ������ �� ���� ���������� ��������, � �������� ���� ��� �������� �������������\n��� ��� ��� ����� ����� ��������� ����.";
			link.l1 = "������� ���� ���� ��� �� - �������� ����� �� ������ �� �������� �����... � ���� ��� ����� ����. ��� ��� �� ������ ���������� � ������?";
			link.l1.go = "Lucas_4";
		break;
		
		case "Lucas_4":
			dialog.text = "� ��������, � ��� ��� ���������. ����� �������, � ���� ���� ������ ������������ ����� ��� ��������� '�������', ������� - ��������� ��� ������ ������� - ���������� ���� � ����������� ���������. ���� ���������� ���������� ��������� - � ������� ������ ���������� ���.";
			link.l1 = "������ �� ��� �� ������ ����� �� ����� ������ - ���� �����. ��� �� ��� ������ �������, �� ������� ����� ��������, ������, ���� ������������� ����������, ������������ � ���, �� ������ �� ������... ����, ����� ������������� ����������? �� �� ��������?";
			link.l1.go = "Lucas_5";
		break;
		
		case "Lucas_5":
			dialog.text = "����� ����������. � ����� �� ���� �����. �� ��� ���-�� ��������?";
			link.l1 = "��. ����, ��� �� ��� ������� ��������, �� ������ ���-��� �����.";
			link.l1.go = "Lucas_6";
		break;
		
		case "Lucas_6":
			dialog.text = "��� ������? ���������.";
			link.l1 = "��� ����� ����������� ������� ��������. ���������� ���������, ���� �������. ������ ���-������ ������� �� ����� ������?";
			link.l1.go = "Lucas_7";
		break;
		
		case "Lucas_7":
			dialog.text = "��... �������� ����������� � �� ����������. ���� �������! � ����� ����, ��� ��� � ����� ���� ������� ����� �������� ��������� ���������� ������� ����� ������������ � ������������, � �������. �� ��� ����������� ������� ��������������� ��������. ��� ������ ����������, ���������� '����'\n������ ��� ������� �� ����������� ���-�� � ��� ��� ������� ������, ��������, ���� �������, ��� ������.";
			link.l1 = "�������! ������, ��� ����� ������������ � ������� ����-���������� - ������� ���� �� ������� �������� ������ ���...";
			link.l1.go = "Lucas_8";
		break;
		
		case "Lucas_8":
			dialog.text = "�����, " + pchar.name + ". �� ���� ������������� ���� � ������� ������ �����. ���� ����� ������ �����������!";
			link.l1 = "��� ����� ������, ����. ������ �������, �� �������� �� �������!";
			link.l1.go = "Lucas_9";
		break;
		
		case "Lucas_9":
			DialogExit();
			RemoveItems(PChar, "MC_Letter", 1);
			GiveItem2Character(pchar, "MC_Letter");
			ChangeItemDescribe("MC_Letter", "itmdescr_MC_Letter2");
			AddQuestRecordInfo("LetterToLucas", "1");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "SentJons_HouseF3", "goto", "goto1", "MC_TakeCloves", -1);
			pchar.questTemp.HWIC.Self = "LetterToLucas";
			sld = characterFromId("Tonzag");
			sld.dialog.currentnode = "Tonzag_hired";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			AddQuestRecord("Holl_Gambit", "3-36");
			//��������� ������ �� ��������� ����������
			pchar.quest.HWIC_Cureer.win_condition.l1 = "Timer";
			pchar.quest.HWIC_Cureer.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.HWIC_Cureer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.HWIC_Cureer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.HWIC_Cureer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.HWIC_Cureer.function = "CreateHWICCureerOnMap";
			SetFunctionTimerCondition("HWICCureerOnMapOver", 0, 0, 16, false);//������
		break;
		
		case "Lucas_10":
			dialog.text = "����������! ���� �� ����! ��� ��� ���������?";
			link.l1 = "� �������� ������� �� ����� �������� �������� ������ ������, � ������� ������, ��� �������� ����� ������ �������� �� ����-������, � ����� �������������� ������������ ���������� ������ �������� ��� ����������, ��� � ����������. � ������, ��� �� ������ ����� �� ����, �� ����� �����.";
			link.l1.go = "Lucas_11";
		break;
		
		case "Lucas_11":
			dialog.text = "";
			link.l1 = "����� ������� ������� ���� � ������ � ����� � �����������, ������� ��� �� �������, � ��� ����� ����� �����������. �������� ���������� ��, ������ �����, ������������. ����� �� �������� ������ ������� ������� �� '�������' �������� ������� ������ ��������� ��������, ������ �����������!";
			link.l1.go = "Lucas_12";
		break;
		
		case "Lucas_12":
			dialog.text = "��������� - ����������� � �������� �������. �� � ���� �� �����������, ��� �� �������� ����� �� ����� ���������...";
			link.l1 = "� �������� '�������', ������� ��������. �� ��� ����������. � ����� �����������, ����������� ��� � �������� ����������, � ������ � ��� ���������� � ����������. ��� ���������� �������� ���� � ��������� ������. ������ �� � ������.";
			link.l1.go = "Lucas_13";
		break;
		
		case "Lucas_13":
			dialog.text = "���! �������, �� ������ ������... ���� ����� ������ ������� � ������� ����� � � �������� - � ���� ���� ��� ����� ����� ������������! ��, � ��� �� ������ � ��������?";
			link.l1 = "��������. �� ����� ��� ���������, � � �� �������� ��� �����.";
			link.l1.go = "Lucas_14";
		break;
		
		case "Lucas_14":
			dialog.text = "��� ������. ������� - �������� ������, � ������� �� ������ ������� �������. �� ��� ��, " + pchar.name + ", �� ������� ���������. � ���������� ���� �������, �� ��� ����������� ��������� �����. � ����...";
			link.l1 = "����, ����, ������, ���� ����� ����� � ����� ����. �������, � ����� � ���������, �������, ��� �� ���� ����� ����� ���� ��� ����. ��������� ��� ���������?";
			link.l1.go = "Lucas_15";
		break;
		
		case "Lucas_15":
			dialog.text = "���� ��� ����? �������, ��� ����� � ����� ��������. ��� ���� - ����������� �����, ������� ����� � ����. ���������������� �������, ����� �������. ������ �� ��������� ������� �������� �� ������� ����������\n���� ����� �������� ��� ����� ���� - ������� ��������� � ���������� �������. �� � ��� ����� ��������� ���� ����������������.";
			link.l1 = "��� ��� ����� ����� ��� �����?";
			link.l1.go = "Lucas_16";
		break;
		
		case "Lucas_16":
			dialog.text = "�� ����. ������ ����� - �����. � ��� ��������������� ����� ������ ��� �������� - ����� � �������. �� � ������, �� � ������� �� ��� �� ��������. ������ ���� ������ - �� ����� ��������� � ����� ������. ��, ���� � �������� ����� ��������\n� �������� ������ � �������� �� ������� ���������. ���� � ��� ������ - ������ ����� ����������. ���� ����� ������ ������ ������� - ����� ����� ����� ������.";
			link.l1 = "�� ���������, ����. ����� ������ ��������� - � � �� ���-������ ��������� � � ���. ��� ��������?";
			link.l1.go = "Lucas_17";
		break;
		
		case "Lucas_17":
			dialog.text = "��� ���� � �������. ��� ���� ��. ��� � ��������� ����� ������... ����������.";
			link.l1 = "�-��. �������������. �����, ������ ����� ������� �� �����, � ����.";
			link.l1.go = "Lucas_18";
		break;
		
		case "Lucas_18":
			dialog.text = "��� ����� ������ ���� ������. �����, ��� ����� ���� ������� ����, ����� �� ������ �� �����.";
			link.l1 = "�� ��������� �� ���?";
			link.l1.go = "Lucas_19";
		break;
		
		case "Lucas_19":
			dialog.text = "���� �������, �� � ���... �����������. � �� �����, ��� ��� ���� � ����, � ����� ����, ��� ������� �� ������, � ����� ����� �� ���� ��������.";
			link.l1 = "�������. �����, ����, � ����� � ������� �� ��������. � ����� ���� ���� �� ����������.";
			link.l1.go = "Lucas_20";
		break;
		
		case "Lucas_20":
			DialogExit();
			sld = characterFromId("Abigile");
			ChangeCharacterAddressGroup(sld, "SentJons_church", "goto", "goto1");//��� - � �������
			AddQuestRecord("Holl_Gambit", "3-56");
			pchar.questTemp.HWIC.Self = "AbiReturnHome";
			LocatorReloadEnterDisable("SentJons_town", "HouseF3", true);//������� ������
		break;
		
		case "Final":
			dialog.text = "��, �� ������ ���! ����������!";
			link.l1 = "�������. ��� ��� ������, ����, �� ������ ���� ��������.";
			link.l1.go = "Final_1";
		break;
		
		case "Final_1":
			dialog.text = "��... �������, ���� ����������� � ����� ������������� ������ � ���������. ������ ������ ����� ���������� � ����� ������� �� ����������� ������.";
			link.l1 = "�� ��� ��, � �� ������.";
			link.l1.go = "Final_2";
		break;
		
		case "Final_2":
			dialog.text = "� ��������� ������ � ����� ��������. � �������� ������������� �� ������, ���������� - �� �������� �� ����������, � ����� ���� ���� ���, ��� ������, � ���� �����������. ������ ��� ����. ����� �����.";
			link.l1 = "��� ��� �������! � ��� - � ���� ����� ������ ���. � ����� ������ ��������...";
			link.l1.go = "Final_3";
		break;
		
		case "Final_3":
			GiveItem2Character(pchar, "Drugstore_keys");//����
			dialog.text = "����� ����� ��� �������� ����� ����� - 100 000 ���� � ��� ���� ������. �� ����� � ������� ������ ��� �����-�� - ����� �������� � ����.";
			link.l1 = "�� ��������!";
			link.l1.go = "Final_4";
			LocatorReloadEnterDisable("SentJons_town", "HouseF3", false);//������� ������
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload3", false); // ������� �������
			pchar.quest.Jino_Door.win_condition.l1 = "locator";
			pchar.quest.Jino_Door.win_condition.l1.location = "SentJons_HouseF3";
			pchar.quest.Jino_Door.win_condition.l1.locator_group = "reload";
			pchar.quest.Jino_Door.win_condition.l1.locator = "reload4";
			pchar.quest.Jino_Door.function = "OpenRoomDoor";//�� ������� ������� �����
		break;
		
		case "Final_4":
			AddMoneyToCharacter(pchar, 100000);
			GiveItem2Character(pchar, "mushket2");
			dialog.text = "� ������� ������� �� ������� ������ ������� �������� ��������. �� - ������ ��������� �� ����, ���� � ����. ������ �� ������ ��������, ������� ��������� ���� �� ���� ��������� �� ��������� ����. ���������� � ��� ���������� - ��� ������ ������������ ���� ������� � ������.";
			link.l1 = "������. � ���������� � ���.";
			link.l1.go = "Final_5";
		break;
		
		case "Final_5":
			dialog.text = "��, � ������ �� ������ ����������. � ����� � ��������, ������ ���� ����, � ������ ���� ��� �� ����� ����� - � �������� � �������. � ���, ��� �������� ����, � ���, ��� � ���� ���� �� �������� �� ���� �������, � �� �� ������� ���� ������.";
			link.l1 = "� ���� ��� ���������� � �����, ����. �����, ��� ����������...";
			link.l1.go = "Final_6";
		break;
		
		case "Final_6":
			dialog.text = "��� ���� ��. ��, � ����� ����������. ������, " + pchar.name + "!";
			link.l1 = "������, ����. ����� ����!";
			link.l1.go = "Final_7";
		break;
		
		case "Final_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "", -1);
			npchar.lifeday = 0;
			pchar.questTemp.HWIC.Self = "final";
			AddQuestRecord("Holl_Gambit", "3-64");
			CloseQuestHeader("Holl_Gambit");
			pchar.questTemp.HWIC.Detector = "self_win";
		break;
		
		// ����� ������
		case "guardoftruth":
			dialog.text = "��, ������, �� �������� �� ���� �������� ����������! ������ ��� ���. ��� ��� ����������� - �������� ���������...";
			link.l1 = "����, ����� ��� �����. ��� ����� �������� ���� � ���-������ �������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "���...";
			link.l1 = "���! �� ������ ����, ��� � ����... ������, ��� � ���� �� ����� � ���� ������� ���� �����!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "������, � ��� ��� ������ - ��� ������ ���...";
			link.l1 = "������� ��� ���������, ����. � �� ������ ������ ������� ������ ��������, � ��� ���� ��� ������ ���� �������� �� �������� - ���  ���������� �� ����. � ���� ���������� ��� ���������� ��������� ����� ����� �� �������...";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "��� �� �� ���� ������?";
			link.l1 = "������ ����������. �� ������� ������ ������ ��� ���� �����������. ������, ��� �� ����� ��� ���������� � �� ������ ������ �������.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "����� - ������������� ������. �� ���� �� ����� � ���, ��� �� ���� ��������� ���� ���� ��������. � ����� - � ������ �������� � ����� �� ���. ";
			link.l1 = "� ��������. ���� ����?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "������ ������. ����� �������. �������, �� �������� �����.";
			link.l1 = "���� ������ - ������.";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			DialogExit();
			pchar.questTemp.Guardoftruth = "jino1";
			AddQuestRecord("Guardoftruth", "36");
			LocatorReloadEnterDisable(pchar.location, "reload4", false);
		break;
		
		// ������������ �����
		case "alchemy":
			dialog.text = "�������, �� ������ �� �� ���� ������� ����������� � ��������� �������? ��� ��� ����� ����� � ����� ����������.";
			link.l1 = "��������, �� ��� ���� ������������ ��������� ����, � ������ ������� � ����� �����, � �� ����� � ����������.";
			link.l1.go = "alchemy_exit";
			link.l2 = "��. ��� ������� ��� ������ - �� ����� ���������� ��������� ������ ���-���� ������������ ������. �������, ����. � ��� ��� ����� �����?";
			link.l2.go = "alchemy_1";
			npchar.quest.alchemy = true;
		break;
		
		case "alchemy_exit":
			dialog.text = "��� �������. ���� �� ����������...";
			link.l1 = "...";
			link.l1.go = "exit";
		break;
		
		case "alchemy_1":
			dialog.text = "��� ����� ��� ����� ��������� ��������� ����� ������ ������. �� � ��� ������ �� ��������� ��� ������������� ������. ���, ���������� � ���� �������. � ��� ���� ���, ��� ����� ����������� �������� - ��������, �����, �������, ���������� ���, �������, ���������� ������, ������� � ������...";
			link.l1 = "����� ���������! � ��� �� ����� � ��� ������� ����������?";
			link.l1.go = "alchemy_2";
		break;
		
		case "alchemy_2":
			dialog.text = "��, ���������� ������ � ������ � ��� �� ���������, �� ������� ����������� �������� �������� � �������� �� ������ ����� � ������ �������� �������� �� ����� �������.";
			link.l1 = "��������?";
			link.l1.go = "alchemy_3";
		break;
		
		case "alchemy_3":
			dialog.text = "�� ��. ��� ����, ����� ����������� ����������� ����� ��� �������, �� ������ ����� ��� ������. ������� �� ������ ������ � ��������� ������� � ���������, ��� ����� ���-���� ���. �����, ������ ������, �� ������ ������� ��� ������ ����������� � ��������� �������� � ������� ������������������, ��� ������� � �������\n���� �� ����������� ����������� ����� - ��� ����������� ������ �������, ����� ��������� ���� ��������������. ��� ���������� ����������� �������, ��� ������ ������� ������� - �������, ��� �������� ��������� - �����, ��� ��������� � ������������ - ���������� ���\n����� ��� ��������� ����������� ������ � ������ ��� ����������� ������� �����������, �� ��� �������� �� ������� ���������� � ���������� �� ���������� ����. ����� ��� ����� ������������ ������ - ��� ���������� ������� �� ����� ������� ���������� - �� ������� ������ � ���� ���\n��� ��� ���� ��� ����� ��������� ����� �����, ������ ���� �� ����� - ����������. � �����, ���� ���������, �������� - � ��� ���������. ���������� - ��� ��� ������� �����, ���������������� ��������, ������� �����, ��������, � ����� ������ ����� ��������.";
			link.l1 = "����� �������! ������� �� ������ �� ���� �����?";
			link.l1.go = "alchemy_4";
		break;
		
		case "alchemy_4":
			dialog.text = "�������� ����� ����. ��� ����� ������� �����, � �� ������ ��������.";
			link.l1 = "�� �� ���, ��������? ������� �� ���������� ������� �� ���� �������? ��� ��, �������.";
			link.l1.go = "alchemy_exit";
			if (sti(pchar.money) >= 20000)
			{
				link.l2 = "� ��������. �����, ����� ��������� ����������� ������� ���-������ ������ ������.";
				link.l2.go = "alchemy_5";
			}
		break;
		
		case "alchemy_5":
			AddMoneyToCharacter(pchar, -20000);
			Log_Info("�� �������� ����� ��������");
			GiveItem2Character(pchar, "alchemy_tool");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �� ��������� � �������. ������ ��� ��� ���������� �����. �����������, ������� �������� ������ ������ ����� � ������ ����������, � �� ������ �� ������ ���������, ������ �� ����� �����. ����� ����, ������-�� ����� ������ �� ��.";
			link.l1 = "����� �������. �����, � ���� �� ���������!";
			link.l1.go = "alchemy_6";
		break;
		
		case "alchemy_6":
			DialogExit();
			PlaySound("interface\notebook.wav");
			Log_Info("��� �������� ����������� ����� � �������� �� ������ ������� ������� '�������'!");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> ���� ������������ �� ������� ������� � ������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- ���� ������������ �� ������� ������� � ������
	}
}