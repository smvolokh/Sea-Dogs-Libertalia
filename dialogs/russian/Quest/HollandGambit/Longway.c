// ������ �������, ��������� ����������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "������������, �������. ��� ����� �������. ������� ������������� ���� �������� � ���� ������������. ������� ����� ��������� � ���� ������������. ������ ������� ����������.";
			link.l1 = "�������, ������ �������. ��� ��� ��������������. �����, �� � ���� �����������. ���������� ��� � ���� ������ ������� - ��� ��� ������ ����� ��� �����?";
			link.l1.go = "Longway_neutral";
			link.l2 = "��, �� ���� ��� � ����� ������� �� ������ �������... �� ��������� ���� ��������, ����, �� � �����. �� �����������, � ���� ��������� � ����� ��������, � �� ���� ���������� ��� ����� ������ ����� � ������ ������, ��-�� - �� ��, ���-�����, ������� ����� �����! ������ ���������� ��� � ���� ������ ������� - ��� ��� ������ ����� ��� �����?";
			link.l2.go = "Longway_enemy";
			link.l3 = "������������, ������ �������. ���, �����, �������� - ��, ������� ������������� �����, ���������� � ��� ������������ � �������� �������... ��� �����������. � �����, � ��������� ��� ��-�������� ������� �� �����, ��� ��������� ����� �������, � ���� - ��������� ������. �������, �� �������� ��� �� ����, ��� �������� ����������� ���. ���������� ��� � ���� ������ ������� - ��� ��� ������ ����� ��� �����?";
			link.l3.go = "Longway_friend";	
			NextDiag.TempNode = "First time";
			pchar.questTemp.HWIC.Holl.JacobCity = SelectJacobCity();
		break;
		
//-----------------------------------------------�� ���������-----------------------------------------------
		case "Longway_neutral":
			dialog.text = "� ������, ������� � ���� �����������. ���� ��� ���� ������ ��������� � "+XI_ConvertString("Colony"+pchar.questTemp.HWIC.Holl.JacobCity+"Gen")+". � �������� ��� ������� � ������� �������. ��� ��� � ������� ������.";
			link.l1 = "������������ � ����!";
			link.l1.go = "Longway_JacobGo";	
			pchar.questTemp.HWIC.Holl.LongwayNeutral = "true";//������� ������������ �������
		break;
		
		case "Longway_enemy":
			dialog.text = "������ ������� ���������� - ����� ��� �������... ���� ��� ���� ������ ��������� � "+XI_ConvertString("Colony"+pchar.questTemp.HWIC.Holl.JacobCity+"Gen")+". � �������� ��� ������� � ������� �������. ��� ��� � ������� ������.";
			link.l1 = "������������ � ����!";
			link.l1.go = "Longway_JacobGo";	
			pchar.questTemp.HWIC.Holl.LongwayEnemy = "true";//������� ������������ �������
		break;
		
		case "Longway_friend":
			dialog.text = "������� ������� ��� ����, ��� ��������, �������. � ���� ��� ���� ������ ��������� � "+XI_ConvertString("Colony"+pchar.questTemp.HWIC.Holl.JacobCity+"Dat")+". � �������� ��� ������� � ������� �������. ��� ��� � ������� ������.";
			link.l1 = "������������ � ����!";
			link.l1.go = "Longway_JacobGo";	
			pchar.questTemp.HWIC.Holl.LongwayFriend = "true";//������� ������������ �������
		break;
		
		case "Longway_JacobGo":
			//������� - � �������
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.HalfImmortal = true;//��������������
			npchar.loyality = 18;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2_back", "none", "", "", "", -1);
			AddQuestRecord("Holl_Gambit", "1-8");
			AddQuestUserData("Holl_Gambit", "sCity", XI_ConvertString("Colony"+pchar.questTemp.HWIC.Holl.JacobCity+"Dat"));
			pchar.questTemp.HWIC.Holl = "JacobOnMain";
			SetFunctionTimerCondition("JacobOnMainOver", 0, 0, 15, false);
		break;
		
		case "hired":
			dialog.text = "�� ���-�� ������ �� �������, �������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "hired";
		break;
		
		case "MC_GoAway":
			PlaySound("VOICE\Russian\hambit\Longway-02.wav");
			if (pchar.questTemp.HWIC.Holl == "MirageFail")
			{
				dialog.text = "�� ������ ���� � ������, �������! ����� ���� ��������� ������������ ������ - ��������� '�����', �� ������� ��� ���� '�������'. '�����' ��� ������ �������� ��� ������ ������� - �� �� � ���� �� ����������\n������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. ������� ������ - ������ ��������� ������� ��� �������, ��� �� �� ������ ������ �� ������, ��� �������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
				AddQuestRecord("Holl_Gambit", "1-10");
			}
			if (pchar.questTemp.HWIC.Holl == "JacobOnMain" || pchar.questTemp.HWIC.Holl == "JacobInRoom")
			{
				dialog.text = "�������, �� ������ ����. �� ��� �������� ������� ������� ���������� �������� ����� ������ �������, ������ ����, ����� ���� �� ������� � ������ ��� ������. ���, ����������, ��� ��� � "+XI_ConvertString("Colony"+pchar.questTemp.HWIC.Holl.JacobCity+"Dat")+"\n�� ��������� ������������ �������. ������� ����� �� ������ ��� ������. ������� ������ - ������ ��������� ���� �� ������� ��� ������, ��� �� �� ������ ������ �� ������, ��� �������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
				AddQuestRecord("Holl_Gambit", "1-9");
			}
			if (pchar.questTemp.HWIC.Holl == "lateVillemstad")
			{
				dialog.text = "�������, ������� ����� ������ �� ���� ��� ����? �� ��� �� ������ - ��� '�������' - ���� ������ �����, � ������� - ��� ���������� ������? ��� ���, ��� �� ���. ������� ������������ � ���������� � ������� ���������� ���\n������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. ������� ������ - ������ ��������� ������� ��� �������, ��� �� �� ������ ����������� �� ������, ��� �������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
			}
			PChar.quest.Munity = "Deads";
			LAi_LocationFightDisable(&Locations[FindLocation("Ship_deck")], false);
			if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_MAYFANG)//���� ��� �� �������
			{
			pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
			pchar.Ship.name = "�����";
			SetBaseShipData(pchar);
			SetCrewQuantityOverMax(PChar, 0);
			}
			else
			{
				for(i=1; i < COMPANION_MAX; i++)
				{
					int iTemp = GetCompanionIndex(PChar, i);
					if(iTemp > 0)
					{
						sld = GetCharacter(iTemp);
						if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MAYFANG)
						{
							pchar.questTemp.HWIC.Holl.CompanionIndex = sld.Index;
							sld = GetCharacter(sti(pchar.questTemp.HWIC.Holl.CompanionIndex));
							RemoveCharacterCompanion(PChar, sld);
							AddPassenger(PChar, sld, false);
						}
					}
				}
			}
			LAi_CharacterDisableDialog(npchar);
			LAi_SetImmortal(npchar, true);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//�� �������
			DeleteAttribute(pchar, "questTemp.HWIC.HollEquip");
			pchar.questTemp.HWIC.Holl = "end";
			CloseQuestHeader("Holl_Gambit");
			pchar.questTemp.HWIC.Detector = "holl_fail";
		break;
		
		case "Longway_hire":
			PlaySound("VOICE\Russian\hambit\Longway-03.wav");
			dialog.text = "�������, ������� ������� ������� ����������. ������� ������ ������� � ���� �� ��������. �� ���� ������� � ��������, � �� - ������� �����. ������� ������ ����� � ��� � ������� ��������.";
			link.l1 = "����� ���������� �� ����, �������!";
			link.l1.go = "Longway_hire_1";	
			link.l2 = "���, �������, �������. �� ������� �������. � �� ���� ����������� ���� ����� ����������.";
			link.l2.go = "Longway_exit";	
		break;
		
		case "Longway_exit":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2", "none", "", "", "", 30.0);
			AddQuestRecord("Holl_Gambit", "1-37");
		break;
		
		case "Longway_hire_1"://�������� �������
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "HalfImmortal");
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			npchar.OfficerWantToGo.DontGo = true;
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			DeleteAttribute(npchar, "CompanionDisable");//������ ����� � � ����������
			npchar.Payment = true;
			LAi_SetOfficerType(npchar);
			NextDiag.CurrentNode = "Longway_officer";
			npchar.quest.meeting = true;
			npchar.HoldEquip = true;
			LAi_SetImmortal(npchar, false);
			LAi_SetHP(npchar, 200, 200);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			AddQuestRecord("Holl_Gambit", "1-38");
		break;
		
//---------------------------------------------������ ����-------------------------------------------------
		case "Longway_abordage":
			PlaySound("VOICE\Russian\hambit\Longway-02.wav");
			dialog.text = "���� �����������? �������, � ������� ��� ������ ���, ������� ��������.";
			link.l1 = "������, ������. ������ � ���� ������ �����. � ������� ���� � ����� ������������. ��������, ��-������� - ��� ����� �������� �� ����. � ������ ����� ���������� � ����!";
			link.l1.go = "Longway_abordage_1";			
		break;
		
		case "Longway_abordage_1":
			AddQuestRecord("Holl_Gambit", "3-45");
		    DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
            DialogExit();
			LAi_SetPlayerType(pchar);
			pchar.questTemp.HWIC.Self = "LongwayPrisoner";
			npchar.lifeday = 0;
			SetFunctionTimerCondition("RemoveLongwayOver", 0, 0, 1, false);//������ �� ����� �����, ��� �����
		break;
		
		case "Longway_prisoner":
			dialog.text = "";
			link.l1 = "��, ��� ������ �� ����� ���������� ��������. �������... ��� ����� ����������, ������� �� ������������, � ��, ��� �� �� ������������ - ��� ���� �������� ���. ������ ����������� � ���, �������� �� �� �� ����������� ���... ��� ������������.";
			link.l1.go = "Longway_prisoner_1";			
		break;
		
		case "Longway_prisoner_1":
			dialog.text = "";
			link.l1 = "�������? ������. � ��������� ���� ������. � ������� ���� �����, ������� �� �����-������ ��������� ������, � �� ������ ����������, ���� � � ����� ����� �������� ���� ����� ���������. ��� ��� ��������, � ��� ����, � ��� ����������, ��� ��� ���������� ������������. ��?";
			link.l1.go = "Longway_prisoner_2";			
		break;
		
		case "Longway_prisoner_2":
			dialog.text = "";
			link.l1 = "������, �� ������� ���������. �� ���� �� ��� � ������ ��������. ���� �� �� ������ ����� ���� - ������, �� ��� ����� ���������� ��� ����. ������ - ������ �� ������������ ������. �� ����, ��� ��������� �� ���� ����� �������, �� ��� �������� � ��������... � ����������. �� ����� ����� ��������, ����������� ������� ������ ��� ��������� ��������� � ��������...";
			link.l1.go = "Longway_prisoner_3";			
		break;
		
		case "Longway_prisoner_3":
			dialog.text = "";
			link.l1 = "�� ��� ����������, ��� ����. ��... ��� ������ ���� ������ �� ������� - ������� ������� ����������� ��������� �� ����� ���� ����� �������� ���������� � ������. ��� ��� �������: ��� �� ���������� ��� ��� ������ � ���������� ���, ��� ���� �� ����������, �� ������. �������...";
			link.l1.go = "Longway_prisoner_4";			
		break;
		
		case "Longway_prisoner_4":
			dialog.text = "";
			link.l1 = "� ���� � ����� ������ ��������. �������. ����� ���� ������� �� ����� ������ �������? �� ����� ����? ������, ��������� ������������� ����� ����, ����� �� ����� � ����� ���� ����� �� ����?";
			link.l1.go = "Longway_prisoner_5";			
		break;
		
		case "Longway_prisoner_5":
			dialog.text = "������� ����� ��������. �� ������� ����� ���� ������, ��� �� �������� ���� �����, �������.";
			link.l1 = "��! � ����� �������� �����! � ������ ����, ��� ������ �����.";
			link.l1.go = "Longway_prisoner_6";			
		break;
		
		case "Longway_prisoner_6":
			dialog.text = "��������, �������, �� ����� ������������. �� ������ �������� ���������� � ��� �� ����� �������. ������� ����� ���� ��������� - ���� �� ����-����.";
			link.l1 = "������. ����� �������� ���� �����?";
			link.l1.go = "Longway_prisoner_7";			
		break;
		
		case "Longway_prisoner_7":
			dialog.text = "��������� ��������� ���� ��������� ������, � �������� �������� �������-����. �������� ������� ��� �� ����� � ����� ��� ������. �� ������ ������� ��������� ��� ���, ��� ����� � ������ ����������.";
			link.l1 = "��... ���� �� �������, ��� �� �� � ��� ���������, ����� ������� ��� �������?";
			link.l1.go = "Longway_prisoner_8";			
		break;
		
		case "Longway_prisoner_8":
			dialog.text = "���� �� �� ���� � ����� �������, �� �� ����������� ����� ��� ��, �������. ������ �������� ����� �� ������ �������� �� ���� ���� �����, ���� ������. ������� - �� ����� �������.";
			link.l1 = "�����. ������������. �� ������������: ���������� �� ���� ������ - � ����� ������� ���� �� �����. ��������� �����, ����� ��������� ������������... ������!";
			link.l1.go = "Longway_prisoner_9";
		break;
		
		case "Longway_prisoner_9":
			DialogExit();
			NextDiag.Currentnode = "Longway_prisoner_0";
			npchar.greeting = "longway";
			sld = characterFromId("Sailor_3");
			sld.dialog.currentnode = "Sailor_deck_7";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);	
			pchar.quest.RemoveLongwayOver.over = "yes";//����� ������
			pchar.quest.RemoveLongwayTimer.win_condition.l1 = "Timer";
			pchar.quest.RemoveLongwayTimer.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.RemoveLongwayTimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 10);
			pchar.quest.RemoveLongwayTimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 10);
			pchar.quest.RemoveLongwayTimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 10);
			pchar.quest.RemoveLongwayTimer.function = "RemoveLongwayOver";
			pchar.questTemp.HWIC.Self = "GotoGuadeloupe";
		break;
		
		case "Longway_prisoner_0":
			dialog.text = "�� ��� ������� �� ��������, ���������� �������?";
			link.l1 = "��� ���... ���� ������, ����� ����� �� �����.";
			link.l1.go = "exit";
			NextDiag.Tempnode = "Longway_prisoner_0";
		break;
		
		case "Longway_prisoner_10":
			dialog.text = "�� �������� ���� �����, �������, � ������� ������� ����. �� ������ ������, ����� ������� ������� ������� �� ����������?";
			link.l1 = "��. �� � ������� ���� - � ����� �� ������, ��� ���������� � ���������� ���, ��� ������.";
			link.l1.go = "Longway_prisoner_11";			
		break;
		
		case "Longway_prisoner_11":
			dialog.text = "������� ������ �� ����. �� ��������� ���, � ��� ��������, ���������� ����������, ���������� �������.";
			link.l1 = "������������. ������ � ������ �������, ������� �� �������.";
			link.l1.go = "Longway_prisoner_12";			
		break;
		
		case "Longway_prisoner_12":
			dialog.text = "'�������' ����� �� ����� ���������� � ����� ���� �� �����, � ������� ����-����������. � ��������� ���� ���� � ������� ����� �������, ����������� � ������� �������, ����� ��������� ������� ����� ��� ������������� ������ �����������. � ������ ������� ������� ���������� ���� ������� ������ � ���������.";
			link.l1 = "������... ��������� �������� ���� ����� �����������? ��� �� �����?";
			link.l1.go = "Longway_prisoner_13";			
		break;
		
		case "Longway_prisoner_13":
			dialog.text = "������� ������� ������, ���������� �������. ����� ��� ������ ������� ����������. ������� ��� ���� �� �� ����, �� ������� �� ������ ��������� �������.";
			link.l1 = "���-�� � �������� ��������... ��� �� ���� ������ ���� ������ ������?";
			link.l1.go = "Longway_prisoner_14";			
		break;
		
		case "Longway_prisoner_14":
			dialog.text = "������ ������, ���������� �������. ������� �� ������� ������������ �� ������ � ������� ����������. ���� ���������� - ������ ������ �� �������. � �������� ����� �� ���������� �����: ����������� ���� ��������� � ����� � �����������, ������� �� �������\n������������, ���� �� ������ ������ ����������� - ��� �������� �������� ������ ����������. � ��� ����������� � ���������� � ����� ����������� ��� ���� ������ � ����������� ��������.";
			link.l1 = "��. �������� ����������. � �����-�� ���, �������, ��� ��������� ���������� � ������������ �������� �� ����� ����������� �������� ������ ������ ����������? � ��������� ���� ��� ��������� ����������������� ��� ����� �������...";
			link.l1.go = "Longway_prisoner_15";			
		break;
		
		case "Longway_prisoner_15":
			dialog.text = "��� ������� ����� �� ������ ��� � ���, ���������� �������. ���� ��� �� ��������� ������� �������� � ���� ��� ������ ��� ����������? ������� - � ���� ������.";
			link.l1 = "��� �����... ��, ������, ����� ���� ���������� � ������ �����, ��� ��������� ��� �����������, ��� ����� �� ��������� ���������.";
			link.l1.go = "Longway_prisoner_16";			
		break;
		
		case "Longway_prisoner_16":
			dialog.text = "�� ���-�� ��� ������ ������, �������?";
			link.l1 = "��. ����� ��� �������� ���������� ���������, ����� ������� ����� �����������?";
			link.l1.go = "Longway_prisoner_17";			
		break;
		
		case "Longway_prisoner_17":
			dialog.text = "������ ��������� �������� ��������� ���. �� �������� �� ����� �� ������������, ������� ��� � ��������, ���������� � ��������� ������ � ������� ��������.";
			link.l1 = "����? ����... ��. ���� ��� ����?";
			link.l1.go = "Longway_prisoner_18";			
		break;
		
		case "Longway_prisoner_18":
			dialog.text = "�� ������ �����������. ��. ������� ���� ������ ����� �� ���� �����, ���������� �������. � �� ������ ���, ��� ��� �����. �� ��� ����� �� ��������� �������� ������.";
			link.l1 = "�� ��� ������� ����, ��� ��� ������. ���������� � � ����� ��� ������, � � ��� ��������-���������.";
			link.l1.go = "Longway_prisoner_19";			
		break;
		
		case "Longway_prisoner_19":
			dialog.text = "��� ������ ��������, �������� �������. ������ ������� ����� �������� ������. �����������, ���� � ��� ��� �������� �������.";
			link.l1 = "���������� ����� � ������� ����-����������?";
			link.l1.go = "Longway_prisoner_20";			
		break;
		
		case "Longway_prisoner_20":
			dialog.text = "��, �������. � ������� ������ �� ������� ���������� ��� ����� � ������� ����� �������.";
			link.l1 = "�������! ����� ����������� ������ ������ ���� ��� �� ��������... ������ �������� ���. � ����� ��, ��� �����.";
			link.l1.go = "Longway_prisoner_21";			
		break;
		
		case "Longway_prisoner_21":
			dialog.text = "��������� �����, ���������� �������. ���� �� ������ ������� � ������ ����������� � �� ���� ����������� - � ��� ������ ���� �������, ������� �� ������� � ���� ����������. � ������ - '�������'.";
			link.l1 = "�������. ������� �� ����������.";
			link.l1.go = "Longway_prisoner_22";			
		break;
		
		case "Longway_prisoner_22":
			dialog.text = "� ������ ������� ������. ��������, ���������� �������.";
			link.l1 = "�����, ��� �����������.";
			link.l1.go = "Longway_prisoner_23";			
		break;
		
		case "Longway_prisoner_23":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "ReturnShoreToNormal", -1);
			npchar.lifeday = 0;
			AddQuestRecord("Holl_Gambit", "3-49");
			pchar.questTemp.HWIC.Self = "MeetingStivesant";
			pchar.quest.Seek_Piter.win_condition.l1 = "location";
			pchar.quest.Seek_Piter.win_condition.l1.location = "Nevis";
			pchar.quest.Seek_Piter.function = "CreatePiterHalleon";
			pchar.quest.RemoveLongwayTimer.over = "yes";//����� ����������
			SetFunctionTimerCondition("QuestShipsTerms_Over", 0, 0, 8, false); // ������
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Longway_officer":
			dialog.text = "������� ������� ���, �������.";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "�������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
            Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Longway_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ����� ����������?";
            Link.l1 = "���� �����!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "������ �� ���� � �� ��������!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "����� �������� ��� ���������� ��� ������ �������������� ������.";
					Link.l3.go = "SetGunBullets";
				}	
			}		
		break;
		
		case "SetGunBullets":
			Dialog.Text = "����� ���� ����������:";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
        case "Boal_Stay":
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
        break;
	//<-- ----------------------------------- ���������� ���� ----------------------------------------
	
	// �� ��������
		case "tieyasal":
			dialog.text = "������� ��� �� ���� ��� ��� �����, ������� ������ �� ���� � ������. ������� �� ������� ���� �������.";
			link.l1 = "�������, �������! � ���, ��� �� ������ � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ������������?";
			link.l1 = "������� �����. � ���� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "24");
			npchar.quest.Tieyasal = "teleport";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string SelectJacobCity()
{
	string sTemp;
	switch (drand(4))
	{
		case 0: sTemp = "Cumana" break;
		case 1: sTemp = "Caracas" break;
		case 2: sTemp = "Maracaibo" break;
		case 3: sTemp = "Cartahena" break;
		case 4: sTemp = "Portobello" break;
	}
	return sTemp;
}