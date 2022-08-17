// ����� �������� - ������ �����������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, iTemp, amount;
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
		//����� �� ������ 2 �������� ����������� - �� ������
		if(CheckAttribute(pchar, "questTemp.HWIC.CanTake") && !CheckAttribute(pchar, "questTemp.HWIC.CanTake.Eng") && !CheckAttribute(npchar, "quest.HWICTake") && !CheckAttribute(pchar, "questTemp.HWIC.Holl") && !CheckAttribute(pchar, "questTemp.HWIC.Self"))
		{
			dialog.text = "������� ���, ������, �������� ��� � �����! ����� �������� ������ ��� ���� �������?";
			link.l1 = "������������. � ��� ����������� ���� �����, ������ ���������������� � ����������...";
			link.l1.go = "exit";
			link.l2 = "����������, �����, ����� �����, ��� �� �����-�� ������� ������� � ���������� ������� ������. � ���� �������� ������� � ��������� �������. � �� ����� ���������� ���� � ���� ����� ��� ������ �� ����� ������. ������ ��������� ������, ��������� �������� ������. �� ����� �� �� �� ���-������ ������������, ��� ����-������ �������������, ��� ��� ���-�� ������ � ���� �������?";
			link.l2.go = "Knippel_check";
			break;
		}
		//�� ���������
		if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
		{
			if (pchar.questTemp.HWIC.Holl == "toKnippel")
			{
				dialog.text = "������� ���, ������, �������� ��� � �����! ����� �������� ������ ��� ���� �������?";
				link.l1 = "������������, �����. � ������, ��� �� ������� � ������� ���������� ������, ��� � ����� � ��� ���������� �� �������...";
				link.l1.go = "Dominica";
				break;
			}
			dialog.text = "�������� ��� � �����! ��� �� ������, ������?";
			link.l1 = "�� ���, ������. � ��� �����.";
			link.l1.go = "exit";
			break;
		}
		//�� ������
		if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
		{
			if (pchar.questTemp.HWIC.Eng == "TakeHollConvoy")
			{
				dialog.text = "������ ����, �������. �� ���� ��� ����� ����� � ��������� ����������� ������...";
				link.l1 = "� ����� ���������� � ���������� ������ �������, �����.";
				link.l1.go = "HollConvoy_Check";
				break;
			}
			if (pchar.questTemp.HWIC.Eng == "Start_main" && GetQuestPastDayParam("questTemp.HWIC.Eng_1") > 0)
			{
				dialog.text = "��� ��� ������, �������! ��� ��������, ������ �������, ����������� ������ ����, ����� ������������� � ����, �� ����� ������� ������������ ����� ���������... �� ������� ���� ��������� ���������, ����� �� ������ ������, �������� ��� � �����!";
				link.l1 = "����������! � ���� ������ ������ �������?";
				link.l1.go = "Fleetwood_house";
				break;
			}
			dialog.text = "� ��� ��� �����-�� �������, �������?";
			link.l1 = "���, ������. � ��� �����.";
			link.l1.go = "exit";
		break;
		}
			dialog.text = "������� ���, ������, �������� ��� � �����! ����� �������� ������ ��� ���� �������?";
			link.l1 = "������������. � ��� ����������� ���� �����, ������ ���������������� � ����������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

//-------------------------------------------�� ���������--------------------------------------------------	
		case "Dominica":
			dialog.text = "���! � ��� �� ����� ������ �����, ��� ����� ��������� �� �����, ������ ���, ������?";
			link.l1 = "���������... � ������� �������, � ����� ���������� ����� � ������� ����� ���������� � �������. ��� ���, � ������� ��������� � ��� ������ ��������� ��������� ������� �������-��������... ����, ����� �� �������, ���� ��� ������ ������ ������!";
			link.l1.go = "Dominica_1";			
		break;
		
		case "Dominica_1":
			dialog.text = "��� ���? ��� ����� ���������, �������� ��� � ���...";
			link.l1 = "���� ������ ������ ��, ��� ��� ����� �������� ��������� ��������� �������� � ���������. � ��������� ���, ����� �������, ��� �������� ��������� �� ���� ���� �����... �� �������������, ����� ��� ������?";
			link.l1.go = "Dominica_2";			
		break;
		
		case "Dominica_2":
			dialog.text = "����������, ���...";
			link.l1 = "���������� ������� - ������ ��� - ������ ���������� �� ���� ����� �� ������. ������, ��� �� ��� �������. ���������� ��������� �������� ������� �������, �� �� ��������� ��� ���� � ����� �����, ��� �������� ������� �� �������� �� ����������. � ��� ������ ������ ���� �� ���������, ���� ��� ������� ���� �������� - ������� � ���� ���������, �������������� ��� � �� ����, � � ������ ��� ����� � �� ����...";
			link.l1.go = "Dominica_3";			
		break;
		
		case "Dominica_3":
			dialog.text = "��� ����, ������. �� ��� �� � ���� ��� ������?";
			link.l1 = "�� �������� � ������� � ������, ��� ���� ������� ����� ����-������, ����� ��� �������, ����� ����� �� ������� ����� �������. � �� ���� ���, ������� � ��������� � ��� - �����, �� �� �������� ��� ��� �������? � ������, ��� ������� ����� ���������� ���-�� � ����� ������� �������� � ��������� ������������ ����� ���������� � ����������.";
			link.l1.go = "Dominica_4";			
		break;
		
		case "Dominica_4":
			dialog.text = "����� ���������� � ����������? �������������, ������ ������ �� ����� �������...";
			link.l1 = "� �������, � ��� ����� ����� ��������� ������� �� ���������� �������� ��� �� �������. �� ��� ��� ������� ����������� ���� ������� - �� �� ������� ����, ��������� ���, ��� ������ ����� '�������� ���������'.";
			link.l1.go = "Dominica_5";			
		break;
		
		case "Dominica_5":
			dialog.text = "�� ������ �������, ������, ��� ������ �� ���. � ������ ��� ���� ���������� ���� �������, �������� ��� � ������! ����� �� ����� ������� ��������� � ����������.";
			link.l1 = "���� �� ����� �� ���� � ���! �������, ��� ��������� ����, �����. ������� �� ������. �� ��������!";
			link.l1.go = "Dominica_6";			
		break;
		
		case "Dominica_6":
			DialogExit();	
			pchar.questTemp.HWIC.Holl = "toDominica";
			AddQuestRecord("Holl_Gambit", "1-17");
			pchar.quest.toDominica.win_condition.l1 = "location";
			pchar.quest.toDominica.win_condition.l1.location = "Dominica";
			pchar.quest.toDominica.function = "PrepareToFleetwoodAttack";
		break;

//----------------------------------------------�� ������--------------------------------------------------	
		case "Knippel_check"://�������� ��������� ������ �� �� ���� �������

			dialog.text = "��... �� ����� ������� ����������, �������, �������� ��� � �����! � �� ������ ���� � �� ����, ���� �������� ��� ����, �����, ��� �������� ����������... �������� ��������� ������ �������� ���. ���� ������ ���� �������� - � ������������ ��� ������ ����� �������� ��������. ������ ��������, ��� ���� �������.";
			link.l1 = "� ���� ��������.";
			link.l1.go = "Knippel_task";
		break;
		
		case "Knippel_task"://������ �������
			dialog.text = "���� ��� ��� �����, �� �����������, ��� �� �������, � ����������, ������ ��� ����� ������� ����������� ����-������� �������� ��������, ����������� ������� ������ �������. � �������� ��������� �������� - ���-����� � ������������ ��� ������, � ���� ��� ��� - ������� ���������. ����������� ���� �������, ��������� ���-����� � ������ ������� � ��������� �� �������. ������ ������ �������, �������� ��� � �������!";
			link.l1 = "������. ��������������� ����������� �� ������ ��������!";
			link.l1.go = "Knippel_task_1";			
		break;
		
		case "Knippel_task_1":
			dialog.text = "������� ���� ��������� �������, �������: ���� �� ������� �� ����-������� ����� ���� ������� ������� ����-���������. � �� ����������� ������ ������ ���. ����� ������ ������������� � ������� - ��� �� ��������, � ����� ��������� ������� �������... ����� �����!";
			link.l1 = "�������! ���� �� ����� ������, ��� ��� �����������. �� �������!";
			link.l1.go = "Knippel_task_2";			
		break;
		
		case "Knippel_task_2":
			DialogExit();
			npchar.quest.HWICTake = "true";
			pchar.questTemp.HWIC.CanTake.Eng = "true";//�������, ��� �������� ��� �������
			HWICSilverConvoyInWorld();
			AddQuestRecord("Holl_Gambit", "2-1");
			ReOpenQuestHeader("Holl_Gambit"); // ������ ����� ����� �� ������
			pchar.questTemp.HWIC.Eng = "begin";
			SetFunctionTimerCondition("HollConvoy_Over", 0, 0, 15, false);
		break;
		
		case "HollConvoy_Check"://�������� ���������
			int iHal = 0;
			for(i = 0; i < COMPANION_MAX; i++)
			{
				iTemp = GetCompanionIndex(PChar, i);
				if(iTemp > 0)
				{
					sld = GetCharacter(iTemp);
					pchar.questTemp.HWIC.Eng.CompanionIndex = sld.Index;
					if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_EASTINDIAMAN) iHal++;
				}
			}//������� ������� �� � �����������
			if (iHal > 0)
			{
				amount = sti(pchar.questTemp.HWIC.Eng.SlvQty) - GetSquadronGoods(pchar, GOOD_SILVER);
				if (amount <= 0)
				{
					dialog.text = "��, ������ �� ����� - ����� �������� ������ ����� � ����� ��� �� ��� ����������... �� ������� ���������� � ����������, �������. �����������! ��� ���� ��������� ����, �������� ��� � �����!";
					link.l1 = "�������! ������� ������� ������� ������ ����� ��������.";
					link.l1.go = "HollConvoy_complete";
				}
				else
				{
					dialog.text = "��, ������ �� ����� - ����� �������� ������ ����� � ����� ��� �� ��� ����������... �������, �� �������� �� ���� ����, �������� ��� � �����! � ���������� ����, ������� ������� ������ ���� ���� �� ���� �������. ��� ������� ���� �� ������ ��������� ����� ������ �������, �� � ����� ���������. ��������� �� �������� �� �� ������. � �� ����� ����� � ���� ��� - �������� ��� ���!";
					link.l1 = "�� � ���� � �����, ���������!";
					link.l1.go = "HollConvoy_fail";
				}
			}
			else
			{
				dialog.text = "���-�� � �� ���� � ��� � ������� ������������ ���-�����. � ���� ������� ���, ��� ��� ���� ����������� �������� ������. �� ��� �������?";
				link.l1 = "��... �� ����� �������� �������� �������? �������, ���� ��� ������ � �������.";
				link.l1.go = "HollConvoy_noShip";
			}
		break;
		
		case "HollConvoy_noShip":
			dialog.text = "�� ������� ����������, ������! � ��������� �����, ��� � ������, � ���� - ���. �� �������� ������� ������ ��������, � � ����� �� ����� ����� � ���� ��� - ����������� ����� �� �����. �������� ��� ��� ����������!";
			link.l1 = "�� � ���� � �����!";
			link.l1.go = "HollConvoy_fail";
		break;
		
		case "HollConvoy_fail":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "2-3");
			CloseQuestHeader("Holl_Gambit");
			DeleteAttribute(pchar, "questTemp.HWIC.Eng");//�������� ��� ����������� ������ � ������������ ��������
			pchar.questTemp.HWIC.Fail2 = "true";
		break;
		
		case "HollConvoy_complete":
			dialog.text = "������� �� ��� ������ - � ���������� ��� � ���� ��������. �����, �� ������ ���������� ������, ��������� ���. � �� ����������� ������� ������������� ������� - �� �� ������ �� � �������� �� ����� ���������. �� �������!";
			link.l1 = "������, �����. � ����� � ��� ������.";
			link.l1.go = "exit";
			npchar.greeting = "knippel_2";
			AddDialogExitQuestFunction("HollConvoy_Remove");
			pchar.questTemp.HWIC.Eng = "Start_main";
			SaveCurrentQuestDateParam("questTemp.HWIC.Eng_1");
			AddQuestRecord("Holl_Gambit", "2-4");
			AddSimpleRumourCity("�������, ��� �� ��������� ����������� �������, ������ �������. ����! �� ��������� � ������ �����, �������!", "SentJons", 10, 3, "");
		break;
		
		case "Fleetwood_house":
			dialog.text = "��� � � ����� ���� ���� �� ������... �����-�� ������� ����� ������ ������� � ����� ������� ��������� �����, � ������ ��� ������ ����� �������� ������, ����� ��� ���� � �����. ������ ����������� ��������� � �������� ����� ������, ��� ��� �� ������ ��� �� ���� �� �������, �� �����������: �������� ������ ����� ��� �������� ������, � �� ���� ���\n������� ��������, �������� ��� � ������, ������� ��� �����, ������ ����������� - ��������, � ������ � ���� ���� ���������. ������������, ��� ������� ��������� ��������� - ��� �� ��� ����������. �� ����� ��� �������? ����� �������� � ������ ����� �� ������� �����������\n������ ������� ����� �����, ����� ����, �� ����� ����� ������� �����, � ������ ����� ������ �� �����...";
			link.l1 = "�-��, ���������� ������ ���������. ����������� �������� � ������?";
			link.l1.go = "Fleetwood_house_1";
		break;
		
		case "Fleetwood_house_1":
			dialog.text = "������� ������� �������� ���� ����� � ��������� �����, �� ������ �� �����, �������� �� � ���! ���� �� ������� ����� �� ������� ������, �� ������ ��� � ������� �� ������. � ������� �������� �����... ��, �������, �������� �� ������������, ������ ������ ��� ������. �� � ���� ����, ��� ��� ������������ � ����. �������� �� ����!";
			link.l1 = "������, �����. ������!";
			link.l1.go = "Fleetwood_house_2";
		break;
		
		case "Fleetwood_house_2":
			chrDisableReloadToLocation = true;//������� �������
			bDisableFastReload = true;//������� ������� �������
			LocatorReloadEnterDisable("SentJons_town", "reload1_back", true);
			LocatorReloadEnterDisable("SentJons_town", "reload2_back", true);
			LocatorReloadEnterDisable("SentJons_town", "gate_back", true);//����� �� ������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "SentJons_town", "reload", "houseH1", "OpenTheDoors", -1);
			pchar.quest.Knippel_Outside.win_condition.l1 = "location";
			pchar.quest.Knippel_Outside.win_condition.l1.location = "SentJons_town";
			pchar.quest.Knippel_Outside.function = "Knippel_GoTown";
			LocatorReloadEnterDisable("SentJons_town", "houseSP3", true);
			sld = characterFromId("Fleetwood");
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld, "SentJons_houseSP3_room", "goto", "goto1");
			pchar.GenQuestBox.SentJons_houseSP3_room = true;
			pchar.GenQuestBox.SentJons_houseSP3_room.box1.money = 110000;
		break;
		
		case "InFleetwoodHouse":
			dialog.text = "������ � ���� � �������, �������. ������������ � ����, �� ��� ����, � � ������ �����.";
			link.l1 = "� �����, �����. ��� ���.";
			link.l1.go = "exit";	
		break;
		
		case "Knippel_ToOfficer":
			dialog.text = "�������, ��� ����� ����... ������ ��� ������� ���������� � � ������������. � � ���� ������ ��� ��������� �� ��� �������. � ��������� ��� ���� ������ � �������� �������. ������ ������ � �� ������ - ����, ��������� ��, �� �������� ������ ��� �� ���������.";
			link.l1 = "����� ���������� � �������, �����!";
			link.l1.go = "Knippel_ToOfficer_1";	
		break;
		
		case "Knippel_ToOfficer_1":
			LocatorReloadEnterDisable("SentJons_town", "reload1_back", false);
			LocatorReloadEnterDisable("SentJons_town", "reload2_back", false);
			LocatorReloadEnterDisable("SentJons_town", "gate_back", false);//������� ��������
			//�������� - � �������
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.HalfImmortal = true;//��������������
			npchar.loyality = 20;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			SetFunctionTimerCondition("GotoBridgetownOver", 0, 0, 30, false);//�� ��� ���� - 1 �����
			AddSimpleRumourCity("�������, �������, ���� ��������������� ��� ������ �������. �� ����� ������������ �������� � ����� ������, ����� � ���...", "SentJons", 10, 3, "");
		break;
		
		case "hired":
			dialog.text = "�� ���-�� ������, �������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "hired";
		break;
		
		case "MC_GoAway":
			PlaySound("VOICE\Russian\hambit\Charlie Knippel-07.wav");
			if (pchar.questTemp.HWIC.Eng == "MirageFail")
			{
				dialog.text = "�� ������ ���� � ������, �������, �������� ��� � �����! ����� ���� ��������� ������������ ������ - ��������� '�����', �� ������� ��� ���� '���������', �� �� � ���� �� ����������\n���� ������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. �� ������� - ��� ������� ������� ���� �������, ��� �� �� ������ ������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.HWIC.Eng == "GotoBridgetown" || pchar.questTemp.HWIC.Eng == "SeekVanBerg")
			{
				dialog.text = "�������, �� ������ ����, �������� ��� � �����! �� ��� �������� ������� ������� ���������� �������� ����� ������ �������, ������ ����, ����� ���� �� �������\n���� ������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. �� ������� - ��� ������� ������� ���� �������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.HWIC.Eng == "VanBergFailInWorld")
			{
				dialog.text = "�������, �� ������ ����, �������� ��� � �����! ��� �� ���� ���� ������� - ����� ������� ���� ����� �� '���������', � �� ����� ��� ��������? �� �������� ������ ������ ���������! ���� ���� ���� � ��������, � ������ �� '���������'! �� ������ � ����� �� ��� ������ �� ���������\n���� ������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. �� ������� - ��� ������� ������� ���� �������.";
				link.l1 = "�� � ���� � ����� � ����� ��������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.HWIC.Eng == "MirageTake")
			{
				dialog.text = "�������, �� ��� ��, �������� ��� � �����, ������, ��� �� ������ ������ ��� ����� �������� �� ����� ������ �����? ��� �� ���� ���� ������� - ��������� '�����' � ������������ ����� �� �������! ������� ����� ��������� ���� ��� ����?\n���� ������� �� ������ ������ ��� �� �����������, �� ������ ������ ���. �� ������� - ��� ������� ������� ���� �������.";
			link.l1 = "�� � ���� � ����� � ����� ��������!";
			link.l1.go = "exit";
			}
			PChar.quest.Munity = "Deads";
			LAi_LocationFightDisable(&Locations[FindLocation("Ship_deck")], false);
			if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_VALCIRIA)//���� ��� �� ���������
			{
				pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
				pchar.Ship.name = "�����";
				SetBaseShipData(pchar);
				SetCrewQuantityOverMax(PChar, 0);
			}
			else
			{
				for(i = 1; i < COMPANION_MAX; i++)
				{
					iTemp = GetCompanionIndex(PChar, i);
					if(iTemp > 0)
					{
						sld = GetCharacter(iTemp);
						if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_VALCIRIA)
						{
							pchar.questTemp.HWIC.Eng.CompanionIndex = sld.Index;
							sld = GetCharacter(sti(pchar.questTemp.HWIC.Eng.CompanionIndex));
							RemoveCharacterCompanion(PChar, sld);
							AddPassenger(PChar, sld, false);
						}
					}
				}
			}
			LAi_CharacterDisableDialog(npchar);
			LAi_SetImmortal(npchar, true);
			ChangeCharacterAddressGroup(npchar, "SentJons_houseH1", "goto", "goto1");//�������� �����
			pchar.questTemp.HWIC.Eng = "end";
			pchar.questTemp.HWIC.Detector = "eng_fail";
			CloseQuestHeader("Holl_Gambit");
		break;
		
		case "OnCuracao":
			pchar.quest.HWICEng_toBarbadosOver.over = "yes";//����� ����������
			dialog.text = "������������, �������. ��� ��� ������!";
			link.l1 = "�����������, �����. ������ � ����? ����� �� ���, � ��� ����� ����������� � ���������� �� ��������. �� ������� �� ����?";
			link.l1.go = "OnCuracao_1";	
		break;
		
		case "OnCuracao_1":
			dialog.text = "�������, ��� ����� ����... ��� ������ ����������� �� �����.";
			link.l1 = "�� ��� � ���? ��� �� �����?!";
			link.l1.go = "OnCuracao_2";	
		break;
		
		case "OnCuracao_2":
			dialog.text = "� ���� ��� ��� ������ �� �������. � ������. �� ������ ������������� �� ��� ���� ��������, � ��� ��� �����. ������ ����� ����. �������� ������ � ������������ �� ������ ������...";
			link.l1 = "�� ��� �� ��� �� ���������� ����� � ��������� ����� ��������? ����� ���������� �������? ����� ���� ���� ������!";
			link.l1.go = "OnCuracao_3";	
		break;
		
		case "OnCuracao_3":
			DialogExit();
			NextDiag.CurrentNode = "OnCuracao_4";
			AddMoneyToCharacter(pchar, 200000);
			LAi_SetCitizenType(npchar);
			npchar.lifeday = 1;//��� ����� ����� �������� �� �����
			pchar.quest.Holland_ShoreAttack.win_condition.l1 = "location";
			pchar.quest.Holland_ShoreAttack.win_condition.l1.location = "Curacao";
			pchar.quest.Holland_ShoreAttack.function = "CreateHollandShorePatrol";//������� � ���������� �����
			LocatorReloadEnterDisable("SentJons_town", "basement1_back", false);//������� ����������
			pchar.questTemp.HWIC.Eng = "MerdokMeeteng";
			AddQuestRecordInfo("LetterFromFleetwood", "1");
			AddQuestRecord("Holl_Gambit", "2-23");
		break;
		
		case "OnCuracao_4":
			dialog.text = "������, �������? ��� ����� ������ �� ������� � �� ��� ��������, �������� ��� �... ��, �����. ��������� ������ � ������, ����� �����, � ��� ������� ��������. �� ������� ������� �������, � ���� ���������� ������� �������. �� �� ��������� ��? ��� ���� ��������� ������, � ���������\n�, �������: ��� �� ����� �������� �������? ��� ����� �� ����: ����� ������, ������ �������� � ������ ���� - ��� ��� ����� ������� ������������?";
			link.l1 = "� ��������, �����. ����� ���������� � �������!";
			link.l1.go = "Knippel_hire";
			link.l2 = "������, � ��� �������, ��� ����� ������ �������. ������ �� ����, ��� � ������������. ������ ����� �������, ������ � ���� ���������.";
			link.l2.go = "Knippel_exit";
		break;
		
		case "Knippel_hire":
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			npchar.quest.OfficerPrice = sti(pchar.rank)*200;
			npchar.OfficerWantToGo.DontGo = true;
			DeleteAttribute(npchar, "CompanionDisable");//������ ����� � � ����������
			DeleteAttribute(npchar, "HalfImmortal");
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			LAi_SetImmortal(npchar, false);
			LAi_SetHP(npchar, 120, 120);
			LAi_SetOfficerType(npchar);
			npchar.greeting = "knippel_hire";
			NextDiag.CurrentNode = "Knippel_officer";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
		break;
		
		case "Knippel_exit":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2", "none", "", "", "", -1);
		break;
		
//------------------------------------------------������ ����-----------------------------------------------
		case "Knippel_abordage":
			dialog.text = "������� �������! ����� �� ����� �� ������ ����������� �����? � ���� � ������ ��� �� ������ �������, �� ������, �������� ��� � �����!";
			link.l1 = "�����������? ��-��! �� ����� ����, '���������'. � �������� ���� ����������, ����� ����� ���� � ����, ������� �����. ����� ���������� � ����. ����������, ���� �� ���, � �����...";
			link.l1.go = "Knippel_abordage_1";	
		break;
		
		case "Knippel_abordage_1":
			AddQuestRecord("Holl_Gambit", "3-20");
            pchar.quest.Knippel_DieHard.over = "yes";
		    DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
            DialogExit();
			LAi_SetPlayerType(pchar);
			pchar.questTemp.HWIC.Self = "KnippelPrisoner";
			npchar.lifeday = 0;
			SetFunctionTimerCondition("RemoveKnippelOver", 0, 0, 1, false);//������ �� ����� �����, ��� �����
		break;
		
		case "Knippel_prisoner":
			PlaySound("VOICE\Russian\hambit\Charlie Knippel-07.wav");
			dialog.text = "�� ����� ������, �������... ������ ��� � ��� �� ��� ���� ������! ���� ��...";
			link.l1 = "������, �����������. ������ ���� ����� ����� � ���� ��������, � �� ������ ������.";
			link.l1.go = "Knippel_prisoner_1";
		break;
		
		case "Knippel_prisoner_1":
			dialog.text = "��� �� ��������, �������? ��� ��� ���� �� ����� ������� � �� ���������� ����������� �������?";
			link.l1 = "��� ��� �� ���� ����, �����. �� ��� ������ �� �����. ������.";
			link.l1.go = "Knippel_prisoner_2";	
		break;
		
		case "Knippel_prisoner_2":
			dialog.text = "�� ������ ���� �����? �� ��� ��... �������� ������ ��������, ��� ��.";
			link.l1 = "������, �����. � ��������� �� ��� ������.";
			link.l1.go = "Knippel_prisoner_3";	
		break;
		
		case "Knippel_prisoner_3":
			DialogExit();
			LAi_SetActorType(pchar);
			sld = characterFromId("KnippelClone");
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "Ground_StandUp", "Kill_Knippel", 3.5);
			pchar.quest.RemoveKnippelOver.over = "yes";//����� ������
		break;
		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Knippel_officer":
			dialog.text = "����������� ������ ���, �������, �������� ��� � ����!";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "�����, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
            Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Knippel_officer";
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
			dialog.text = "� ��������� ���������� � ��� �� ����� �����, "+pchar.name+", �� � �� � ���� �������� ������� ������ ��������. � � ����!";
			link.l1 = "�������, �����! � ���, ��� �� ������ � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� ��������� �����?";
			link.l1 = "������� �����. � ���� �� ������������ � ����.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "22");
			npchar.quest.Tieyasal = "teleport";
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