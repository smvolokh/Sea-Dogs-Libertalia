// ������ ������ � ������������ ���
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	bool bOk;
	int i, n, iTemp;

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
		
		// --> ������ �� �������� � ���� �� ������
		case "Startsailor":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "��, ��� ����, ������ ��� ������� ������ � ������� ��� � ��� �� ����!";
			link.l1 = "��� ���������...";
			link.l1.go = "Startsailor_1";			
		break;
		
		case "Startsailor_1":
			dialog.text = "��, �����, ����� ���, � ���� � ��� ���� �� ��� ����� ������������ ���������. �� ������ �� ������, ����� ����� ��� ����� ���������� �����, � ��� ����� ���������. ��, ������� ����� �� ���.";
			link.l1 = "�� ��, ���� ���� ��� �������. ����� ��� ��������������!";
			link.l1.go = "Startsailor_2";			
		break;
		
		case "Startsailor_2":
			dialog.text = "� ���� �� ������ �������, � ���� �������� ��� ���������, ����� ���� �� ������� ��� ����� � �������� ��� ������, ������ � �������� � ������, ��� �������?";
			link.l1 = "� ������ �� ���� ������...";
			link.l1.go = "Startsailor_3";			
		break;
		case "Startsailor_3":
			dialog.text = "� ������ ������� � ������, ��� ���������, ��� �������?";
			link.l1 = "� ������? � �� ���?...";
			link.l1.go = "Startsailor_3_1";			
		break;
		
		case "Startsailor_3_1":
			dialog.text = "��, ��� � ���� ��������. ��� ���, ��, �� ������... ������ ���������, �����. ����� � ��������� ����� �� ����� ���, ��� ������ ������� ����� ��������. ������� �����, ������ ��, �����������. �������, ��� ������ ������� �����-�� ��������� ����. � �� ��� ��� �� ������� �����-�� ������� � ��������� ������ ������� ���������. �� �� ����� ����� ���������� ������ ����� ����������.";
			link.l1 = "�������� ����? ��� �� �����!";
			link.l1.go = "Startsailor_4";			
		break;
		
		case "Startsailor_4":
			dialog.text = "�����, ��� �� �����, � ����� �����. �� � ��� ����� �������� �������. ������� � ��������, ���������, ������ � ����, ������� � ���������...";
			link.l1 = "��, ��������... �������-�� �����. ���� ������������ �������, ������� � �������� - ��� ���� � �������, ���������... �����, ����� ������?";
			link.l1.go = "Startsailor_5";			
		break;
		
		case "Startsailor_5":
			dialog.text = "������ ������ ���� � ������, ���� ��������� � ������� ��� ����� ����� �� ���!";
			link.l1 = "";
			link.l1.go = "Startsailor_6";			
		break;
		
		case "Startsailor_6":
		DialogExit();
		NextDiag.TempNode = "First time";
		AddDialogExitQuestFunction("Monbar_StartGame_3");
		break;
		// <-- ������ �� �������� � ���� �� ������
		
		// --> ����� � ����������
		case "Sharlie_arest":
			dialog.text = "���������� ������ ������, �����, � �������� �� ����!";
			link.l1 = "��� ��� ����...";
			link.l1.go = "Sharlie_arest_1";			
		break;
		
		case "Sharlie_arest_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			DoFunctionReloadToLocation("FortFrance_prison", "goto", "goto9", "");
			WaitDate("", 0, 0, 2, 0, 10); //������ �����
			RecalculateJumpTable();
			RemoveAllCharacterItems(PChar, true);
			sld = characterFromId("Puancie");
			sld.dialog.currentnode = "Puancie_Jail"; 
			LAi_SetActorTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "FortFrance_prison", "goto", "goto13");
			DoQuestFunctionDelay("Puancie_InJail", 10.0);
		break;
		// ����� � ����������
		
		// --> ������ ����
		case "Maltie_officer":
			ref location = &Locations[FindLocation(pchar.location)];
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "begin")
			{
				dialog.text = "��� ��� ������, ����� "+ GetFullName(Pchar)+". �� ������ ������� ����������?";
				link.l1 = TimeGreeting()+", ������. � ���� ���������� � ���� �����, ������ �� �����. ������ ������������. ��� �������� �� ������� ������ ������ � ��� ������ �����.";
				link.l1.go = "spanish";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "think")
			{
				dialog.text = "��, ��� ������ ������? ����� ������ ������?";
				link.l1 = "��������� �����, ��� � ������� ����� ������� � ���� �� �������. ��� ������ ���������, � �� ������ ���� ��������� �� ����-��������� ��� ���������� ��������������.";
				link.l1.go = "spanish_10";
				break;
			}
			if (!CheckAttribute(location, "first_meeting"))
			{
				dialog.text = "�����, ��� �� ������ ����? �� ������ ���� �� �����?";
				link.l1 = "� ������, ����� ������� ������ �����, ������ �� �����.";
				link.l1.go = "Maltie_officer_1";
				location.first_meeting = true;
			}
			else
			{
				dialog.text = "�����, � ����� ��� �� ��������, ��� �� ���������� �� ������� �������. ��� ��� ������ ���� �������������� �������.";
				link.l1 = "��, �������, ������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Maltie_officer";
			}
		break;
		
		case "Maltie_officer_1":
			dialog.text = "������ �� ����� ��������� ��� ������� � ����� �� �����, �������� �� ������� ������� ������� ������� �� ������. ���������� �� ������ ����, ��� ������� ��������. �����, �� �����������.";
			link.l1 = "�������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "Maltie_officer";
		break;
		// ������ ����
		
		// --> ������� ����
		case "Maltie_soldier":
			dialog.text = "������������, �����. � ���-������ ���� ������ ���?";
			link.l1 = "���������, ������. ���, ������ �� ��� ����� �� ������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Maltie_soldier";
		break;
		// --> ������� ����
		
		// --> ��������-���������
		case "Sharlie_maltie":
			dialog.text = "� �����, �����. ��� ��� �� ����� ������ �� �����? � �� - ��� ����?";
			link.l1 = "��, ��� ���. ��� ����� ������ ������� ������! � ���� ������� ������������, ��������� � ����.";
			link.l1.go = "Sharlie_maltie_1";			
		break;
		
		case "Sharlie_maltie_1":
			dialog.text = "� ���������, ��, �����. ������ ��������� � ��������� � ����� ������. ������ � ��� ��������� ��� ������ ����� � �������� ����� ������� �� ������, �������-������������ ����������� ������� ����������. �� ��� ���� ��������� ��������� ����\n��� ���� - ������� ��������������, ������������� � ������, �������� ������ ������, � ��� - �����! �������� ����� ��, ��� ��, ��� ������, ��������� ������ �������� �� ��� ������� �������� � ��������, ��� �� ������������! �� ������ ���, ����� ��������� ��� ������, ��... ������ ���� ������.";
			link.l1 = "��� � ��� �� ��� ��������? �� �������� ������������?";
			link.l1.go = "Sharlie_maltie_1_1";			
		break;
		
		case "Sharlie_maltie_1_1":
			dialog.text = "�����! ������ ���� �����! ��� �������� ������ � �������� � ���������� ��������������� �����. ��� ������ ����! �� ��� ������� � ���, ��� ��� �����-�� ������� ������������ ����. ������ ���������� � ��������� ���������, ���������� �������, �, ������, ����� ������, ��� �������� ���� �����\n��� ���-�� ���. �� ������� ������! � ��� ����� �� �����. ��� �������, � �� �������, ������ ������ � ������� �������! �� �������� ����.";
			link.l1 = "������. ��� ��������� ������?";
			link.l1.go = "Sharlie_maltie_1_2";
		break;
		
		case "Sharlie_maltie_1_2":
			dialog.text = "��� �� ����� ��������� ����, ���, � ������. �������� �� ����, � ��� �������!";
			link.l1 = "...";
			link.l1.go = "Sharlie_maltie_2";
		break;
		
		case "Sharlie_maltie_2":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "FortFrance_town", "reload", "reload7_back", "Maltie_GoTown", -1);
		break;
		
		case "Sharlie_maltie_3":
			dialog.text = "��� �� � ������. ��� ���� ���� - ������ ����������� �������. �������� ��������� �����. �������� ���� �������� � ������� ��� ������ � ���������� �� �������� ����. ��� �� ������� ������� � ������������� ��������. � ����� �� ��� � ���������� ��� ���������� ����\n��������, "+pchar.name+", � �������� ������ ������! �� �� � ��� �� �������, ����� ��� ������ ����������� ��� ��� ��������...";
			link.l1 = "� ����� � ������ � ��� �����, ����� ������ ������ �����. �������, ��� �������� ���� ���-�� �������.";
			link.l1.go = "Sharlie_maltie_4";
		break;
		
		case "Sharlie_maltie_4":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			npchar.lifeday = 0;
			LAi_ActorGoToLocator(npchar, "goto", "goto1", "none", -1);
		break;
		// ��������-���������
		
		// --> ���� ��������
		case "Sharlie_sailor":
			dialog.text = "������� ��������, �����. �� ���-�� ������?";
			link.l1 = "��. � ���� ���� � ������������� �������, �� ��� �������. ������ ����������� ��� ���������� � ����� �� ��� ���� - �� � ���� ��������, �����, ��� ���� ������� � ������-�� ����� � ��� ����� ������...";
			link.l1.go = "Sharlie_sailor_1";
		break;
		
		case "Sharlie_sailor_1":
			dialog.text = "��, ��� ������������� ���. ������ ������ ��� �� ������? ��� � ��� �� �������?";
			link.l1 = "������� ��� �������, "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(RealShips[sti(pchar.ship.type)].basetype), "Name")))+". � ��� �� ��� �����?";
			link.l1.go = "Sharlie_sailor_2";
		break;
		
		case "Sharlie_sailor_2":
			dialog.text = "��, ������, �����, �� �����-�� ������� ������� �� ������� ��� �������, �� � "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(RealShips[sti(pchar.ship.type)].basetype), "Name")))+" ��� ����������. �� ����� ���� ������������, �������, ��� �� ������ �� ������ ������ ��� ������. ����������� �� �� ������� �����, ���������...";
			link.l1 = "� ������� ��� �������?";
			link.l1.go = "Sharlie_sailor_3";
		break;
		
		case "Sharlie_sailor_3":
			dialog.text = "��� �������� ���� �������. ������ �� �������, �� ����� ����������, �� � ������ �������� ���� ����������� �� ���. � � �������� ���������, � � ������ �������, ���� ����� ������, � �� ����� ���������, ���� �����������.";
			link.l1 = "������. ������� �� ������?";
			link.l1.go = "Sharlie_sailor_4";
		break;
		
		case "Sharlie_sailor_4":
			dialog.text = "����� - �� 200 ���� �� �����, �� � ����� - ��� �� ���� ��������. �� ������� �� ��������, �� ��� �� ������������.";
			if (sti(Pchar.money) >= 5000)
			{
				link.l1 = "�� ��� ��, ����� - �� �����! ��� ���� ������.";
				link.l1.go = "Sharlie_sailor_5";
			}
			link.l2 = "� ���������, � ���� ��� ���� ����� �����.";
			link.l2.go = "Sharlie_sailor_nomoney";
		break;
		
		case "Sharlie_sailor_5":
			if (GetSquadronGoods(pchar, GOOD_FOOD) < 20 || GetSquadronGoods(pchar, GOOD_MEDICAMENT) < 30)
			{
				dialog.text = "� ������ �������������� � ��� ���� � �����, �������? � ���������? ���? ��, ����� ������� �������� ���� �� �����-�� ������� - ����� � �������������.";
				link.l1 = "��. �� ����. ������, � ��� � ������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Sharlie_sailor_again";
			}
			else
			{
				AddMoneyToCharacter(pchar, -5000);
				dialog.text = "�������, �������! � ���������� ������� ����� � �� ������ �� ���������� �� ��� �������.";
				link.l1 = "�����������. �������� ����� � ������ � ����.";
				link.l1.go = "Sharlie_sailor_6";
			}
		break;
		
		case "Sharlie_sailor_6":
			DialogExit();
			LAi_SetStayType(npchar);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(npchar, "Fortfrance_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "", "", "", "", 5);
			npchar.lifeday = 0;
			SetCrewQuantityOverMax(PChar, 25);
			pchar.Ship.Crew.Morale = 50;
			pchar.Ship.Crew.Exp.Sailors = 50;
			pchar.Ship.Crew.Exp.Cannoners = 50;
			pchar.Ship.Crew.Exp.Soldiers = 50;
			AddQuestRecord("Sharlie", "7");
			pchar.questTemp.Sharlie = "skiper";
			DeleteAttribute(pchar, "GenQuest.CannotWait");//������� ������, ���� �� ��� ���� ������
		break;
		
		case "Sharlie_sailor_nomoney":
			dialog.text = "��, ����� ��� �������� - �������������. �����, �� ������� ����� ���� �����, � ������� - ���� ������� �������� �� ����� ���, ������ �� �����������. ����� � ������ ��������� ���� ������, ��-��!";
			link.l1 = "������. � ���������� ��������� ��� ����� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Sharlie_sailor_again";
		break;
		
		case "Sharlie_sailor_again":
			dialog.text = "�� ���, �������, �� ������ ������ ���� � ���� ��������� �� ���� �����? ��� �� �������� ����� ����� � ����! �� � � �������� ��� �������� ����� ������...";
			if (sti(Pchar.money) < 8000)
			{
				link.l1 = "��� ����, � ��� ���������������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Sharlie_sailor_again";
			}
			else
			{
				link.l1 = "��. �������� ��� �����. ������ �� � ���� �� ������.";
				link.l1.go = "Sharlie_sailor_5";
			}
		break;
		// ���� ��������
		
		// �������� �� ��������
		case "skipertalker":
			dialog.text = LinkRandPhrase("�����������, �������! ��� ��� ������?","������������, ������. ��� ���� ���� ��� �������?","������� ���, ���������. �� ���-�� ������?");
			link.l1 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ���������� � ����� � ���� �������.");
			link.l1.go = "skipertalker_1";
			link.l2 = "������ ����� �������������. �����!";
			link.l2.go = "exit";
			NextDiag.TempNode = "skipertalker";
		break;
		
		case "skipertalker_1":
			dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = "����������, "+GetAddress_FormToNPC(NPChar)+", ��� ����� ����... � ��� �������� �� ���� ������� - �����, ������ ����������� �������� � ����� ������?";
			link.l1.go = "skipertalker_2";
		break;
		
		case "skipertalker_2":
			dialog.text = "�������? ��... ���� ��� �����... ��� ������ �������� - � ������ �� ������. �� ����� ��� ��������, ��������, ��� ����� � ��������, ��������.";
			link.l1 = "�� �����? ��... ��� ��� �����, �� ����������?";
			link.l1.go = "skipertalker_3";
		break;
		
		case "skipertalker_3":
			dialog.text = "��������� ��������� ��� �����. �������� � ���������� � ������. �� ������ �� �����, ��� ��� �������� ��� ������, ����� ��� �� ��������� �� ���� ����, ��-��!";
			link.l1 = "��������, � �������. ��������� �� ����������, �� ��� ����� �������!";
			link.l1.go = "exit";
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			pchar.questTemp.Sharlie = "jailskiper";
			AddQuestRecord("Sharlie", "8");
		break;
		
		// --> �������
		case "Folke":
			dialog.text = "��� ������ ������ ��������, �����?";
			link.l1 = "�����������, ���������. ��� ����� ������ - � ���� ���� �������, �� ��� ��������, � �� ��� ����� �����. ������� � � ������� ���� �� �������� ���...";
			link.l1.go = "Folke_1";
		break;
		
		case "Folke_1":
			dialog.text = "�� ������ �������, ��� �������� ���� ������, ����� ����� � ���� �� ������?";
			link.l1 = "������ ���. �����, �� ������ ����������� ����������� �� ���� ������. � �����... �������, ��� � ���������.";
			link.l1.go = "Folke_2";
		break;
		
		case "Folke_2":
			dialog.text = "��������� ���, �����. ��� ��������� ���������� ��� ��������. � � ������������� ����� ��������� �� ������ �������. ��, ����, ����...";
			link.l1 = "� ���, ��� �� ������ ���� �����, ���������. ��, ���: � ���� ���� ��� �����-�� �������� � ������� ����, ����� ��� ���������� ��������?";
			link.l1.go = "Folke_3";
		break;
		
		case "Folke_3":
			dialog.text = "����� ���������, ���. ����� � ������ ��������� � ����������� �����, � �������� �������� ������ � �������� ������������ ��. ��� ��� � ��� ���� ������ ����� �� ��������� ������. � ��� ����������� c ������� ��� ����������� ���������� ������ - ��� ������ �� ���.";
			link.l1 = "�������. ������ ������ �� ���� �� �������, ���������� ������� ������, ��� �� ���. � ����� � ���� ��� ����� ������ ����������� �� ���������.";
			link.l1.go = "Folke_4";
		break;
		
		case "Folke_4":
			dialog.text = "��������, ���!";
			link.l1 = "...";
			link.l1.go = "Folke_5";
		break;
		
		case "Folke_5":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			AddQuestRecord("Sharlie", "10");
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.Sharlie_skiper.win_condition.l1 = "location";
			pchar.quest.Sharlie_skiper.win_condition.l1.location = "My_Cabin_Small";
			pchar.quest.Sharlie_skiper.function = "Sharlie_SkiperTalk";
			//���������� �� ������ ������� - �������������� �����
			pchar.quest.Sharlie_seabattle.win_condition.l1 = "location";
			pchar.quest.Sharlie_seabattle.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_seabattle.function = "SharlieSeabattle_agent";
		break;
		
		case "Folke_6":
			pchar.GenQuest.StoreGoods.StoreIdx = Fortfrance_STORE;
			pchar.GenQuest.StoreGoods.Starting = true; // ��������� ������� 250912
			dialog.text = "�������� ��������� ����, �������! ������ � ������ ��������� �������. �� ����� ����� ��� ������ �� �� ��� �� ��������� ������������, �� ���� ����� ��� ��������� ����.";
			link.l1 = "����� ������. �� ������� ����, ������ �� ������� �����... �����-������ ������ ����� ��� ��� ����������� � ���� �����, ���������?";
			link.l1.go = "Folke_8";
		break;
		
		case "Folke_7":
			dialog.text = "�� ��, ���� ���� ������������ ���������, �������. ��� �������� �� ��������� �� � �������� �����, �� �� �������� � ���-��� ����� ����� ��������� ��� �� ������.";
			link.l1 = "� ���� �� ���� ������ - �� ����� ���������� ������ ��� ��������. �� ��� � ������� ��������� �����, � ������ ��, ��������� ��, ������� � ��� ���... �����-������ ������ ����� ��� ��� ����������� � ���� �����, ���������?";
			link.l1.go = "Folke_8";
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_BALLS) >= 80) && (GetSquadronGoods(pchar, GOOD_GRAPES) >= 80) && (GetSquadronGoods(pchar, GOOD_KNIPPELS) >= 80) && (GetSquadronGoods(pchar, GOOD_BOMBS) >= 80) && (GetSquadronGoods(pchar, GOOD_POWDER) >= 180);
		case "Folke_8":
			if (bOk)
			{
				dialog.text = "��, ������������ �� ��������� ����������, �������. ����� �������� ��� ������ ������, ������ �� ��������� ������������ ��������� ���.";
				link.l1 = "�������, ��� �� ���� ����� ����������. ��� �����-�� ���������?";
				link.l1.go = "Folke_10";
			}
			else
			{
				dialog.text = "� �������� ����, �������. � ��� ������������ �����������. ����� ��� ������� �� ��� ���� ����, ��������� � ����, � ����� ��� ������ ������� � ������ �� ������ ���������. �������� ����������� �������, ������� - ��� ��� �� ����� ������ ������, ���� ������ ���� ����� � ������ ��������� ������� ��� ��������.";
				link.l1 = "������. � �������� ������ ������. ����������� �� �����.";
				link.l1.go = "Folke_9";
			}
		break;
		
		case "Folke_9":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_1";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "12");
		break;
		
		case "Folke_goods_1":
			dialog.text = "�� ��������� ������� ��������, �������?";
			if (bOk)
			{
				link.l1 = "��, ��������. ��� �����-�� ���������?";
				link.l1.go = "Folke_10";
			}
			else
			{
				link.l1 = "���, � ��� ���� ���������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_1";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_WEAPON) >= 50);
		case "Folke_10":
			if (bOk)
			{
				dialog.text = "������ ��� ������� �� �������� ����������, � ��������� ������� - �� ��� ��� ���������� - �� ������ �� ������ �������. �� ��������� ��������� ��� ����������, ������ ��� ���������� ������ - ��� ������� ������\n� ����� ������� ������ � �������, ��� ��������� ����� ����� ������ ������� ������ � ��������, ������� �� � ����������.";
				link.l1 = "�������. ����, �� ��� ���-�� ������ �������?";
				link.l1.go = "Folke_11";
			}
			else
			{
				dialog.text = "� ��� �������� ������ ��� ��������. �� ��� ��� ���������� - ��� ��, ������ ������ �������? ���������� ������ - ��� ������� ������. ��� � �����, � ��� ����� ������� �������\n����� ������ ������ �������, � ����� � �������, ���������� ���������, ��� ��������� ����� ����� ������ ������� ������ � ��������, ������� �� � ����������.";
				link.l1 = "��� � ��������. ����� �������.";
				link.l1.go = "Folke_10_1";
			}
		break;
		
		case "Folke_10_1":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_2";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "13");
		break;
		
		case "Folke_goods_2":
			dialog.text = "�� ��������� ������� ������, �������?";
			if (bOk)
			{
				link.l1 = "������ � �����. ����, �� ��� ���-�� ������ �������?";
				link.l1.go = "Folke_11";
			}
			else
			{
				link.l1 = "���, � ��� ���� ���������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_2";
			}
		break;
		
		bOk = (GetSquadronGoods(pchar, GOOD_FOOD) >= 100) && (GetSquadronGoods(pchar, GOOD_RUM) >= 10);
		case "Folke_11":
			if (bOk)
			{
				dialog.text = "��������, ������ ������. �������� � ��� ����������, � ���� ��� ������� �� ���� ������������ - ����� ������, ��� ��� ��� ������� ��������� �� ���� ������, ��� ������ ������ ���� ����� �����. ������� ����� � ������� ���������, �������� ���������� ������ ����...";
				link.l1 = "��, ��� � �����, �� ����� ����� ������������ � ����?";
				link.l1.go = "Folke_12";
			}
			else
			{
				dialog.text = "��. ��� �������� ��������� � ����. ���� �� ������� ���� ��������� - ��� �����. ������� �� ������, �� ������� ��������� ���� - ����� ��� ����� ����� �������� ��� �����. � ���� ���������� ��� - ���� ����: �������� ���� ���������\n���������� ���� �� �� ��� ��������, �������, �� ���������� ������� ��� �� ������� ��������� - ��� ������� ��������� �� ���� ������, ��� ������ ������ ���� ����� �����. ������� ����� � ������� ���������, �������� ���������� ������ ����\n��� ��� �������� ����������� ����������, ���� �� ��� ����� ��������� � ������ �������� ����.";
				link.l1 = "�������, �� ����. ����� ����� � �����.";
				link.l1.go = "Folke_11_1";
			}
		break;
		
		case "Folke_11_1":
			DialogExit();
			NextDiag.CurrentNode = "Folke_goods_3";
			LAi_SetStayType(npchar);
			AddQuestRecord("Sharlie", "14");
		break;
		
		case "Folke_goods_3":
			dialog.text = "�� ��������� ������� �������� � ����, �������?";
			if (bOk)
			{
				link.l1 = "��. ������ �� ����� ����� ������������ � ����?";
				link.l1.go = "Folke_12";
			}
			else
			{
				link.l1 = "���, � ��� ���� ���������.";
				link.l1.go = "exit";
				NextDiag.TempNode = "Folke_goods_3";
			}
		break;
		
		case "Folke_12":
			dialog.text = "��, ���. ����� ��������� ����� � ����� ���� �� �����, � ���������, ��� �� � ������.";
			link.l1 = "�� ����� �������! � ����!";
			link.l1.go = "Folke_13";
		break;
		
		case "Folke_13":
			dialog.text = "����� � ����������� �� ���� ����� �� ������. ������������ ����������, �������!";
			link.l1 = "...";
			link.l1.go = "Folke_14";
		break;
		
		case "Folke_14":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			chrDisableReloadToLocation = true;
			LAi_SetActorType(npchar);
			AddQuestRecord("Sharlie", "15");
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			npchar.quest.OfficerPrice = 20;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(npchar.id);
			npchar.loyality = 30;
			npchar.greeting = "Gr_Officer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			npchar.quest.meeting = true;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			pchar.questTemp.Sharlie = "seabattle";//� �� �������
			DeleteAttribute(pchar, "NoNavyPenalty"); // �������� �� �������� ���������
		break;
		// �������
		
		// --> �����-��������
		case "Seabattle_pirate":
			dialog.text = "����� ��������, ���� ��� �� - "+GetFullName(pchar)+"?";
			link.l1 = "������ ���. ��� ������ ������ ��������, ������?";
			link.l1.go = "Seabattle_pirate_1";
		break;
		
		case "Seabattle_pirate_1":
			dialog.text = "��������� ������������� - "+GetFullName(npchar)+". ���� ������ � ��� �������� ���. ��, ������ ��� ����� - ��� ������ ������� � �� �������. ��������� ��� ��������, �� ����������� �� ���������, � �� ����� ���������� ��� ������� �������������.";
			link.l1 = "��... �������! ���������, � ������ �� �������� ��� ��� ���������� � ���� ������?";
			link.l1.go = "Seabattle_pirate_2";
		break;
		
		case "Seabattle_pirate_2":
			dialog.text = "�������, ��� �� ������. ��� ������� � ����� ���� �� ����� ������ - ������������, ��� ��� ��� ��� ��� ���� ����������� ��� ��������: � ��� ��, � ���� �����. � ����� ����� ����� ���������� �����������. ��� ��� ��������� ��������� ��� �����������?";
			link.l1 = "�������. � ������� �� ����� ����������.";
			link.l1.go = "Seabattle_pirate_3";
		break;
		
		case "Seabattle_pirate_3":
			dialog.text = "��� ��� ��������! ����� ����� ������� ������. ��� ���, ���� ����� ������ ��������� �� ��������� ��������� ����� ���� ������ �������� ����, ������ ��������. ���� ������ ������� ��� ����� �� �������\n�� ��� ��������� ������ �� �������� ����� ������ ����� ���� - ��� ����� ������, � ������ ��������, ����� ������, ������ � ����� ������� ���. ������������ - ����� �������� ����������� �� ������ ���� ���������.";
			link.l1 = "������ ����� ����? �� ������� �� � ��������! ��� ����� ���������� ��������?";
			link.l1.go = "Seabattle_pirate_4";
		break;
		
		case "Seabattle_pirate_4":
			dialog.text = "������������� �� ������� � ���� �� ������� � ���������� � �����. �� ��� ��� ���������� - ��� ����� ����� ������ ��������� ������� � ������. �� ���������, ���: �������� �������� ��� ������ ����, ���� ��� ������� ��������� ���...";
			link.l1 = "�� ����������, ������. ��������, ��� �� ���� ���������. ��� ������ � ���� ����� � ������ � ���� - ����� ���������� � �� �������.";
			link.l1.go = "Seabattle_pirate_5";
		break;
		
		case "Seabattle_pirate_5":
			dialog.text = "��� � ������! ����� � ����� �� ����� �������. �������, ���!";
			link.l1 = "�� �� �� ���...";
			link.l1.go = "Seabattle_pirate_6";
		break;
		
		case "Seabattle_pirate_6":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "gate_back", "none", "", "", "Seabattle_pirate_open", -1);
			AddQuestRecord("Sharlie", "11");
		break;
		// �����-��������
		
		// ������ �����������
		case "griffondor_officer":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "exit";
		break;
		
		// �������� ���������� ���� �� ������ ���� �� ������
		case "rosetti":
			PlaySound("VOICE\Russian\EvilPirates01.wav");
			dialog.text = "�������, ���������� ���� ��������� � � ������ ������ ����������! ���� ����� ����������!";
			link.l1 = "";
			link.l1.go = "rosetti_1";
		break;
		
		case "rosetti_1":
			DialogExit();
			bDisableCharacterMenu = true;//������� ����������
			ChangeShowIntarface();
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("DefendSP_soldier_0"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Blaze");
			sld.dialog.filename = "MainHero_dialog.c";
			sld.dialog.currentnode = "SP_defend";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.5);
		break;
		
		case "rosetti_2":
			PlaySound("interface\abordage_wining.wav");
			dialog.text = "����, �������! ����, ��������! ���������! ���, ���, ���! ������, �� ���������!";
			link.l1 = "";
			link.l1.go = "rosetti_3";
		break;
		
		case "rosetti_3":
			DialogExit();
			PlaySound("interface\abordage_wining.wav");
			bDisableCharacterMenu = false;//������� ����������
			ChangeShowIntarface();
			for (i=0; i<=12; i++)
			{
				sld = CharacterFromID("DefendSP_soldier_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", -1);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			// ���������� �� ������� ����� ������� �� ������
			pchar.quest.DefendSP_jungle1.win_condition.l1 = "location";
			pchar.quest.DefendSP_jungle1.win_condition.l1.location = "Martinique_jungle_01";
			pchar.quest.DefendSP_jungle1.function = "DefendSP_SpainPatrol";
		break;
		
		case "spain_patrol":
			dialog.text = "��������! � ���! �������, ����� � ������! ������� �������!";
			link.l1 = "...";
			link.l1.go = "spain_patrol_1";
		break;
		
		case "spain_patrol_1":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			for (i=1; i<=4; i++)
			{
				sld = CharacterFromID("DefendSP_spapatrol_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
				LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
				LAi_group_SetCheck("EnemyFight", "DefendSP_SpaPatrolDie");
				AddDialogExitQuest("MainHeroFightModeOn");
			}
			sld = CharacterFromID("DefendSP_spapatrol_5");
			LAi_ActorRunToLocation(sld, "reload", "reload2_back", "none", "", "", "DefendSP_GateAlarm", -1);
		break;
		
		// ����� ������
		case "spanish":
			dialog.text = "�� ���������, ��� � �� ���� ���������� �������� ����������?";
			link.l1 = "� �� ���������, ��� ������ ��������� ���� ������������� ������ ���� �� ����� �� ��� �������� ��������� �� ���������? ��� ���� �������, ������� ������ ������. ��� ���������. �, ��� ������������� ��������� ������� �� ������, ������ ����������� � ����!";
			link.l1.go = "spanish_1";
		break;
		
		case "spanish_1":
			dialog.text = "������-������, �����. � ������ �� ��� ���� �������. ������ �� ����������. �����������.";
			link.l1 = "��� �������������� ���������� ������ ��� ������?";
			link.l1.go = "spanish_2";
		break;
		
		case "spanish_2":
			dialog.text = "������ �� ����� ��� ���������� ����� ����������� ��������� �������, ����� ������� ������������ ������������ �� �������.";
			link.l1 = "��� ��� ��� ��������. ��� ���?";
			link.l1.go = "spanish_3";
		break;
		
		case "spanish_3":
			dialog.text = "����� �� ������� ������� �������� ������ ��������, � ������ - ������ ���������� ������� � ����� ������ ������. ��� ���� ������ ��� �����-�� ������� ������� ��������� ��������� � ������ ����� ����� ��� ����� ������ ������� '����������'. ������ ����� � ���������� ����������, � ��������� ����� � ��� �� ���� �� �����, �� ����\n������ ���-�� � ���� ����� �� ���, ��������� ���������� ���������� '����������' �� ��������, � ��� ������ ��� ��������� ��������, ����������� ������� �� ����� � ����� �� �����, ����������� � ���� �����. ������, �������� �����������\n�������� �� - �� �����, ��� �� �����, ������, ��� ������ ��� �������, ������ ������� �� ������ ���������� ���������� ��������� ������ ������, ������� � �������� � ���������� �������� ������� ������ � �������� ��� ������\n�������, �� �� �������� ���� ����������: ������ - ���������� ������, ��� ��� ������ ���� ��������, ����� ������ ����� ��������� ����� ��� � �������. ���� �����, ��� ����� �� ������ �������� ��� �� ����?";
			link.l1 = "��������. ��� ���, ��� ��� ��������?";
			link.l1.go = "spanish_4";
		break;
		
		case "spanish_4":
			dialog.text = "� ���������, �������� � ���������� ��� ������. ����������� ���� ��������, ���������� ����� ������, ���� �������� ������ ��� ������ � ������� �� ������. ��, ������� � ������� ������, ������ ��������� �������.";
			link.l1 = "��� ������� ��� ������� ������, ������, �� ��� ��� �������� ���� �����������? ���� � ������?";
			link.l1.go = "spanish_5";
		break;
		
		case "spanish_5":
			dialog.text = "�������. ��������� ������� ������ �� ����� ���� ����� � ��� ������ ��������, ������� �� ��������� ���� �������� �������� �������. ��� ��������� �� ����� ��� ������ ��������� �������������� �������� ������ '������������' ��� �������� ��������� ������, ������� �������� ��������. ���� ��� ����� �������������� ������� ������ � �������. � ��� �� ��� ���� ��� ���������.";
			link.l1 = "����. � ��� ���� �����-�� �������������, ������ ������ ��� ������ ������� �� ���� �� �����?";
			link.l1.go = "spanish_6";
		break;
		
		case "spanish_6":
			dialog.text = "� ����������, ��� ������� ��� ������ - � ������������� ��������� � �������� �� ������. ��� ����, ��������, ���������, ��� ������������� �� ������� ������� ����������� � ����� ������������, ������� ������ ������������ ����. � ������ ���, ����� - ����� ����� �� �������� ��� �������!\n������� ����������� � ��������� ������� �� ����� ������, � ��� ��� ������ �� �������, ������� �� �� ������������� � ���������� ��������, �������� � ��������, ������� � ������, ������� � �����-�� ����������� ��������!\n��, ���� ���: �������� ��� �������������, � ��� �������� ��������� ���� ����� � �� ����. �� ������ ���� �����, �����?";
			link.l1 = "����������, ������. �� ������������ �� ���� � ������ ������. �������, � ��������� �������� �� ���� �� ����� �� ����� ���� �������������� �������� ���������� ������ ������ ��������� ��������? ��, ��� �� ������ � ��������, � ������� �� ���������? �� ������ ����� ��������� ��������� �� ����� ����...";
			link.l1.go = "spanish_7";
		break;
		
		case "spanish_7":
			dialog.text = "������ ��. � ����� ���� �� ��������� ������ ���� ���� ��������, �� � ��� ���� �������� ������ �������� ���� ��������� � ��������� ���������������. �� �� ������ ���� �������� �� ���� � �������� ���������� �������, ������� � ������ ������ ���������� � ����� ���������. �� ��� ��������� ���\n����� ���� �� ����� - ������� ������������� �����, �������������� ��������� �������, ������� ������� ��-��������-�-����, � ����� ������ ������ � ���������� ������������ ��������� ���������� �������, � ����� ����� ����������� ����� ����������.";
			link.l1 = "� ��������� � ����� �������. ��� ��� ��� �����?";
			link.l1.go = "spanish_8";
		break;
		
		case "spanish_8":
			dialog.text = "�����, � ������, ��� ���������� ��� ����.";
			link.l1 = "������. � �������, ����� ���� ��� ������� �������. ��������, � ���� �������� ��� �������.";
			link.l1.go = "spanish_9";
		break;
		
		case "spanish_9":
			DialogExit();
			NextDiag.CurrentNode = "Maltie_officer";
			AddQuestRecord("Guardoftruth", "2");
			pchar.questTemp.Guardoftruth = "prisoner";
			sld = characterFromId("spa_baseprisoner");
			LAi_CharacterEnableDialog(sld);
			chrDisableReloadToLocation = true;//������� �������
		break;
		
		case "spanish_10":
			dialog.text = "��� ��� �������! �� � �� ���� ��������� ��������, �� ���������� � ������ �� ���� �� �����...";
			link.l1 = "������, ��� ������ ���������. ��������� �� ���� �� ����� ���� ��������� �� ��� �������. ���� ������ ������� ����� ���� ������. �� ������ ����������� � ���� ������������. ��� �� �������� ��� ����� �������, ��� ��� ����������� ���������� � �� ������?";
			link.l1.go = "spanish_11";
		break;
		
		case "spanish_11":
			dialog.text = "�����, ��������� ���, ��� �� �� ��� ����� ���. ��� ����� � ��������� ������� �������� �������� �� ������� ���� �� �����... �� ������ ��� ���� ������ ���������������!";
			link.l1 = "����������. ����� ������� �� ������ �� ����� ������� ���� �������� �. ������������� ������ �� �������� ������� � ��������� � ���� � ���� ������.";
			link.l1.go = "spanish_12";
		break;
		
		case "spanish_12":
			dialog.text = "����� �������, �������.";
			link.l1 = "� ���, ������: ��� '������ ������' � ���-������ ������� ���?";
			link.l1.go = "spanish_13";
		break;
		
		case "spanish_13":
			dialog.text = "���. ������� �����. � ���?";
			link.l1 = "����� ���? �� ���� �� �� ����� ����, �� � �������������� ������, �� ������ � ���� �� ����� �� �� ��������� �������� � ����� ������?";
			link.l1.go = "spanish_14";
		break;
		
		case "spanish_14":
			dialog.text = "���, �� ��������. � ���, ������ ��, �� ������ ��������.";
			link.l1 = "����. �������, ����� � ��������� �������. ���� �� ������� ������... �����, � ��� ��� �������� � ������� ��������, � �� ��� �������� ����������� ��� � ��������. �: �������, ������! �� ��� ����� �������.";
			link.l1.go = "spanish_15";
		break;
		
		case "spanish_15":
			dialog.text = "�� �� �� ���... ��� �� �������, �����: ��� �� ������ ��� ����?";
			link.l1 = "� �� � ��� ����� ����� ����� �� ���� ������. � �����... ���� ��� ������. �����!";
			link.l1.go = "spanish_16";
		break;
		
		case "spanish_16":
			DialogExit();
			NextDiag.CurrentNode = "Maltie_officer";
			AddQuestRecord("Guardoftruth", "3");
			pchar.questTemp.Guardoftruth = "toship";
			sld = characterFromId("spa_baseprisoner");
			sld.dialog.currentnode = "spa_prisoner_28";
			LAi_CharacterEnableDialog(sld);
		break;
		
		// �����-��������� �� ��������
		case "monk_vinsento":
			dialog.text = TimeGreeting()+"! �� � ���� ������� "+GetFullName(pchar)+"?";
			link.l1 = "��, ��� �. ��� ��� ������?";
			link.l1.go = "monk_vinsento_1";
		break;
		
		case "monk_vinsento_1":
			dialog.text = "� � ��� �� ���� ��������. � ���� ��� ���...";
			link.l1 = "�� ���� ��������? �����, � ��� ��������������� � ���� ���� ��������. ����� ����, ��� �� �������� �� ���� ������ ����� �� �������, ������ �� ����������. ������ �� �����������, ��� ��� � ���������.";
			link.l1.go = "monk_vinsento_2";
		break;
		
		case "monk_vinsento_2":
			dialog.text = "��������, �������. ���� �������� ������ �� ��� ����� �������, � ����������� ���� �� ����. ������, ��� �������������� �� ������ ��� ���. ����������, �������� ��� ������. ��� �����, ����� �����.";
			link.l1 = "�� ������ ��� ���? ��. �����, �� ����� ������ �� ����������� ��� ���� � ���� �� ����������? �� ������� ��� ���-��.";
			link.l1.go = "monk_vinsento_3";
		break;
		
		case "monk_vinsento_3":
			dialog.text = "�������� ������, �������. �������� ���, � ������� ����. ������ �������, ��� ������ ����� ������������� ���� ������ � ����� �����, � ���������� � ����� �� ���� ������������. �� ��������� ��� �������, � �� �������� �� ���� ����� �� ���� ��������!";
			link.l1 = "�����, ������� ���� ������.";
			link.l1.go = "monk_vinsento_4";
		break;
		
		case "monk_vinsento_4":
			GiveItem2Character(pchar, "specialletter"); 
			ChangeItemDescribe("specialletter", "itmdescr_specialletter_vinsento");
			sld = ItemsFromID("specialletter");
			sld.text = "Letter_Vincento_last";
			dialog.text = "�������. �������, �� ������� ���������� �������.";
			link.l1 = "...";
			link.l1.go = "monk_vinsento_5";
		break;
		
		case "monk_vinsento_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 30.0);
			ReOpenQuestHeader("Sharlie"); // patch-8
			AddQuestRecord("Sharlie", "40");
			CloseQuestHeader("Ksochitam");
		break;
		
		// ����� ������
		case "adrian":
			dialog.text = "�����������, ��� ���. �� ����������� ������� ���� ����...";
			link.l1 = "������������, ���� ������. ��� �������������� ������ ���, ��� �� ������ �������� ���� ��������� � �����������...";
			link.l1.go = "adrian_1";
		break;
		
		case "adrian_1":
			dialog.text = "��, �������. ��� ��, ��� � ������ �� �������� ���������� ��� ����. ����� ���������� ������� � �������� ������. � ���� ������, ���������� �������� ���������, ���������� ������ ��������. ��� �� ����, ��� ���.";
			link.l1 = "�������!";
			link.l1.go = "adrian_2";
		break;
		
		case "adrian_2":
			for(i=2; i<=10; i++)
			{
				if (i == 4 || i == 5 || i == 8 || i == 9) continue;
				TakeNItems(pchar, "amulet_"+i, 2);
			}
			TakeNItems(pchar, "potion2", 20);
			TakeNItems(pchar, "potion4", 10);
			TakeNItems(pchar, "potion7", 3);
			TakeNItems(pchar, "berserker_potion", 3);
			dialog.text = "���� ���� ��� ����������� �������� ����� - �� ������ ���������� �� � ����, �� ������ �������� ������� ���� � ����. � ���� �� �������� �� ���� ����������.";
			link.l1 = "������, ���� ������. � ���� ���.";
			link.l1.go = "exit";
			link.l2 = "�������. � ����� ������ ���� ���������� ��������� �� ���.";
			link.l2.go = "potion";
			NextDiag.TempNode = "adrian_3";
		break;
		
		case "adrian_3":
			dialog.text = "�� ����������� ���� �������, ��� ���. ��� �� �����?";
			link.l1 = "� ���� ������ ��������� �������� ���������.";
			link.l1.go = "potion";
			link.l2 = "���� ������, ��������� � ������. ������ �������� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "adrian_3";
		break;
		
		case "potion":
			dialog.text = "�������, ��� ���. ����� ��������� �� ������� ����������?";
			if (!CheckAttribute(npchar, "potion1_date") || GetNpcQuestPastDayParam(npchar, "potion1_date") >= 1)
			{
				link.l1 = "������� �������� ��������.";
				link.l1.go = "potion1";
			}
			if (!CheckAttribute(npchar, "potion2_date") || GetNpcQuestPastDayParam(npchar, "potion2_date") >= 1)
			{
				link.l2 = "�������� �������.";
				link.l2.go = "potion2";
			}
			if (!CheckAttribute(npchar, "potion3_date") || GetNpcQuestPastDayParam(npchar, "potion3_date") >= 1)
			{
				link.l3 = "�����������.";
				link.l3.go = "potion3";
			}
			if (!CheckAttribute(npchar, "potion4_date") || GetNpcQuestPastDayParam(npchar, "potion4_date") >= 1)
			{
				link.l4 = "�������� ��������.";
				link.l4.go = "potion4";
			}
			link.l5 = "��������, ���� ������, � ���������.";
			link.l5.go = "exit";
		break;
		
		case "potion1":
			npchar.quest.price = 90;
			npchar.quest.type = 1;
			dialog.text = "�������� ��������? � ���� 90 ����, ��� ���.";
			if (sti(Pchar.money) >= 90)
			{
				link.l1 = "����������, ���� ������. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion2":
			npchar.quest.price = 500;
			npchar.quest.type = 2;
			dialog.text = "�������� �������? � ���� 500 ����, ��� ���.";
			if (sti(Pchar.money) >= 500)
			{
				link.l1 = "����������, ���� ������. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion3":
			npchar.quest.price = 200;
			npchar.quest.type = 3;
			dialog.text = "�����������? � ���� 200 ����, ��� ���.";
			if (sti(Pchar.money) >= 200)
			{
				link.l1 = "����������, ���� ������. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion4":
			npchar.quest.price = 900;
			npchar.quest.type = 4;
			dialog.text = "��������? � ���� 900 ����, ��� ���.";
			if (sti(Pchar.money) >= 900)
			{
				link.l1 = "����������, ���� ������. ��� ������.";
				link.l1.go = "potion_pay";
			}
			else
			{
				link.l1 = "� ���������, � ���� ������������ �������... � ������� �����.";
				link.l1.go = "exit";
			}
		break;
		
		case "potion_pay":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.price));
			iTemp = sti(npchar.quest.type);
			GiveItem2Character(pchar, "potion"+iTemp);
			PlaySound("interface\important_item.wav");
			dialog.text = "����������. ����� ���� ���������. �� ������ ���� �������!";
			link.l1 = "�������, ���� ������.";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(npchar, "potion"+iTemp+"_date");
			NextDiag.TempNode = "adrian_3";
		break;
		
		// �������� ������
		case "Dichoso_agent":
			dialog.text = "������� "+GetFullName(pchar)+"?";
			link.l1 = "��, ��� �. ��� ������?";
			link.l1.go = "Dichoso_agent_1";
		break;
		
		case "Dichoso_agent_1":
			dialog.text = "� ���� � ��� ��������� �� �������� ������ ������. �� ������, ��� �� ������ ���.";
			link.l1 = "����� ����� ����� �� ����������, � ������� � ��� - �� �����, ����������.";
			link.l1.go = "Dichoso_agent_2";
		break;
		
		case "Dichoso_agent_2":
			dialog.text = "������� ������ ����� � ���� ����������. � ���� ����������� � ��� ����� ���������� ������ � ����� ����� � ���������� ������ ��������. ��� �� ������ - ��� ����, ����������� �� ��� ������, ����� �������� ���������.";
			link.l1 = "����� ��� � ������?";
			link.l1.go = "Dichoso_agent_3";
		break;
		
		case "Dichoso_agent_3":
			dialog.text = "������! ������� ������ ����� ����� ��� �� ������� ����-���������. ���� �������� �������� ���� � ����, ������ ���������� �������� ������� � ������� ������ �������� �����������.";
			link.l1 = "��...";
			link.l1.go = "Dichoso_agent_4";
		break;
		
		case "Dichoso_agent_4":
			dialog.text = "������ �����������, ��� �� ������ ���������� � ����������� ���� ��������, ��� ����������� ������ ����� ����������� ���������� �� �� ����. � ����� �������� ��������, ��� ��, ��� �� ����� �� ����� �������, ���� ����� ������ ����, ��� ���� � ��������.";
			link.l1 = "���� ���! ����� ��� ����� ���������. �� ������ �� ������� ������ �� ������ �� ��� ���, � ������� ������ ����?";
			link.l1.go = "Dichoso_agent_5";
		break;
		
		case "Dichoso_agent_5":
			dialog.text = "��� ������ ���������� ��� �� ����-������, ����� �����, � ������ ����� �� ����-���������, � ������� ����� ��� ���. ���� �� �� ������ ������ ������� �� ������, � �� ����? � � ������ ��� ������� ���, �� ������, ���� �� ��������� � ��������.";
			link.l1 = "����� ��� ����. �� ��� ��, �� ���� ������ ������� � ����������� � �����������.";
			link.l1.go = "Dichoso_agent_6";
		break;
		
		case "Dichoso_agent_6":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "Tieyasal_PrepareDichosoTrap", -1);
		break;
		
		// ����� ������
		case "Dichoso_crypt_agent":
			dialog.text = "��, ������� �� � ����� �����������, ������� "+GetFullName(pchar)+"...";
			if (CheckAttribute(pchar, "questTemp.Tieyasal.MigelKnow")) 
			{
				link.l1 = "��� ������ ������? � �� ������� �����. � ��������� ����, ��� �� ���� �� ����� ����. �����, ��� � �� ����.";
				link.l1.go = "Dichoso_crypt_agent_2";
			}
			else
			{
				link.l1 = "�������, ������ ���� ������ ������ ����������� ��������?";
				link.l1.go = "Dichoso_crypt_agent_1";
			}
		break;
		
		case "Dichoso_crypt_agent_1":
			dialog.text = "��������� ���������, �������. �� ��� ����� ����� �� ����� ���� �����, ����� �� ���?";
			if (CheckAttribute(pchar, "questTemp.Ksochitam.SQCapBookRead")) // ������ ������ �����-��������
			{
				link.l1 = "��� ������ � �� ����, ��������, � �������, ��� �� �����. ������� �� �� ������. � ����� ������ � ������� ������� �������� '�����-��������', � ����� ������������ � ��� ���������. ���-�� �� ����� �� �� ����. ���� ���������� ����� �� ���� ���.";
				link.l1.go = "Dichoso_crypt_agent_2";
			}
			else
			{
				link.l1 = "������ ���. ��� � �������, ���� ������ � ��������?";
				link.l1.go = "Dichoso_crypt_agent_7";
			}
		break;
		
		case "Dichoso_crypt_agent_2":
			dialog.text = "��. �� ��� ��, �� ���� ������ ������ � ������. ������ ������������, ��� �� ��������� ��������������� �������...";
			link.l1 = "��� ������?";
			link.l1.go = "Dichoso_crypt_agent_3";
		break;
		
		case "Dichoso_crypt_agent_3":
			dialog.text = "��� ��� ���. � ����������� ��������� ���� � ������������ �� ��� �����.";
			link.l1 = "� ���� ��� ������� ������������� � ������. ��� ����� �����. ��� ��� ��?";
			link.l1.go = "Dichoso_crypt_agent_4";
		break;
		
		case "Dichoso_crypt_agent_4":
			dialog.text = "�� �� ����� ����� � ����� �������������, �������. � �����-��, ���� ���������� ���� �� ��� �������������������.";
			link.l1 = "�������. ����������� �������-������. � ������?";
			link.l1.go = "Dichoso_crypt_agent_5";
		break;
		
		case "Dichoso_crypt_agent_5":
			dialog.text = "� �����, ��������. �� ��� ��� ��������� ������ ���� ������, � � ��� ��� ����. ����� ����, � ������ ���� � ������� �� ��������� �������. ����� ����� ���� �������. ��� ��� ������� ���� � �����������, �� �� � ��� �����. ������� ������� �������� ���������� ������������, ��?";
			link.l1 = "� ������ ������� �� ������ ����� ��� ������, ������. ����� ��� ���� � ����� �������� �� ������ � �������.";
			link.l1.go = "Dichoso_crypt_agent_6";
		break;
		
		case "Dichoso_crypt_agent_6":
			dialog.text = "��� �������� ���� ������� �����. � ���� �� ����� �� ������. ��� �� ������ - ������ �����... � ������, ��� �� ������: �������� ���� �� ��� ���� ����������� ������ � �������������. ������, � ���!";
			link.l1 = "������ �������� ��� �������, �� ���� �������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Tieyasal_StartCryptBattle");
		break;
		
		case "Dichoso_crypt_agent_7":
			dialog.text = "����� ������� ���� �������? �������. �� �� �����, ��� ��� ������� ����.";
			link.l1 = "����� � ��� �� �������� �� ���� ����������?";
			link.l1.go = "Dichoso_crypt_agent_8";
		break;
		
		case "Dichoso_crypt_agent_8":
			dialog.text = "� � � �� ��������� � ����� ��������� ������ ���������. �� �����, � ����� ��� ����������.";
			link.l1 = "�������. ����������� �������-������. � ������?";
			link.l1.go = "Dichoso_crypt_agent_5";
		break;
		
		// �������� ������������
		case "newcastle_officer":
			dialog.text = "���� ����� ����������, �������!";
			link.l1 = "����������� ����� ������� � ������� �������� ����-����������. �� ���� �������� �� ��������, ��������� ������� � �������� � ����� � ������� �� ������������. � ������ ��������� - ��������.";
			link.l1.go = "newcastle_officer_1";
		break;
		
		case "newcastle_officer_0":
			dialog.text = "���� ����� ����������, �������!";
			link.l1 = "����������� ����� ������� � ������� �������� ����-����������. �� ���� �������� �� ��������, ��������� ������� � �������� �� ��� ������� ����� - ��������� ���������� � ������� �� ������������. ���� ��������� ������� ������. ��� ������ ������� ���������� - ���������� ��������.";
			link.l1.go = "newcastle_officer_1";
		break;
		
		case "newcastle_officer_1":
			dialog.text = "����, �������!";
			link.l1 = "������. ������!";
			link.l1.go = "newcastle_officer_2";
		break;
		
		case "newcastle_officer_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			locations[FindLocation("Charles_exittown")].DisableEncounters = true; //��������� �������
			locations[FindLocation("Charles_CaveEntrance")].DisableEncounters = true; //��������� �������
			for(i=2; i<=4; i++)
			{
				locations[FindLocation("Charles_Jungle_0"+i)].DisableEncounters = true; //��������� �������
			}
			LocatorReloadEnterDisable("Shore42", "boat", true);
			for(i=1; i<=iTotalTemp; i++)
			{
				sld = characterFromID("Tieyasal_Oursoldier_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", -1);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			// �� ������� ����� ���������
			pchar.quest.Tieyasal_newcastle.win_condition.l1 = "location";
			pchar.quest.Tieyasal_newcastle.win_condition.l1.location = "Charles_exittown";
			pchar.quest.Tieyasal_newcastle.function = "Tieyasal_NewcastleGoJungle";
			// �� ������
			pchar.quest.Tieyasal_graveyard.win_condition.l1 = "location";
			pchar.quest.Tieyasal_graveyard.win_condition.l1.location = "Charles_CryptBig2";
			pchar.quest.Tieyasal_graveyard.function = "Tieyasal_InGraveyardCrypt";
		break;
		
		case "Europe":
			PlaySound("VOICE\Russian\military01.wav");
			dialog.text = "������� ������! �� ��������� ����������, � ���� ������ ���������� ������ ���������. � ����� ������������ ���� ������ - ������� ��� � �������� ����, ��� ��� ���������! ������ �� ������������, �� ���������� �� ����� ������!";
			link.l1 = "����, ���!";
			link.l1.go = "Europe_1";
		break;
		
		case "Europe_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "Europe_SharlieFinal_1", 5);
		break;
		
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			if (npchar.id == "GigoloMan") NextDiag.TempNode = "GigoloMan";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}