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
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ��� � ����. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
		break;
		
		//�������� �� ������
		case "MarginCap":
			dialog.text = "������������, �������. �� ���-�� �� ���� ������, ��� ������� ��� ������ � ����� �����?";
			link.l1 = "��. ������ ���, "+GetAddress_FormToNPC(NPChar)+". � ��� �� ����� � ���������� ��������� ������������ ���� �������, � ������ - "+pchar.GenQuest.Marginpassenger.q1Name+". � ����, ����� ��� �������� ���� ���� ����������. ���� �� �� ������ ������ ����� ���������, �� �� �������� ���������� �, ��������, ����� ������� �� ��������.";
			link.l1.go = "MarginCap_1";
		break;
	
		case "MarginCap_1":
			dialog.text = "��� ���? � ���� � ���� ��������� ������ ����� ������ �������?";
			link.l1 = "����� ��� �������� ���������� ��� ����������� ��������� ������� ���� �����, ������� ���������� ��� ��� � ���� �������. �� ����� �������� ������, "+GetAddress_FormToNPC(NPChar)+".";
			link.l1.go = "MarginCap_2";
		break;
		
		case "MarginCap_2":
			int MCparam = (6-sti(RealShips[sti(pchar.ship.type)].Class))*100+sti(pchar.ship.Crew.Morale)+sti(pchar.Ship.Crew.Exp.Sailors)+sti(pchar.Ship.Crew.Exp.Cannoners)+sti(pchar.Ship.Crew.Exp.Soldiers);
			int NPCparam = (6-sti(RealShips[sti(npchar.ship.type)].Class))*100+sti(npchar.ship.Crew.Morale)+sti(npchar.Ship.Crew.Exp.Sailors)+sti(npchar.Ship.Crew.Exp.Cannoners)+sti(npchar.Ship.Crew.Exp.Soldiers);
			if (MCparam > NPCparam)//������ ���
			{
				dialog.text = "�������, � ���� ��� ������. ������ ����� ������� ������ ������ ������ ��������. �� ��� ��� ��� ������ � ��� �� ������, ������ ��� � ����! � ��� ��� �� �������!";
				link.l1 = "�� ����������, ���� ������... ��������� ���� ����� ������ ���������!";
				link.l1.go = "MarginCap_3";
			}
			else
			{
				dialog.text = "��������� �� �� �� ���� ������, ������, ���� � ��� ��� ��������. ������ ��� ���� ������. ������ �������� ��������� ��� ����� - �������� ��������� �����. ������������, ���� � ������������ �� ����� �� ����!";
				link.l1 = "��, � ��� �����������. � ������ ��� ������������� ���� �� ���� �������. �� ������ �������, "+GetAddress_FormToNPC(NPChar)+"!";
				link.l1.go = "MarginCap_4";
			}
		break;
	
		case "MarginCap_3":
			DialogExit();
			npchar.Dialog.CurrentNode = "MarginCap_repeat";
			//������ ���������
			sld = GetCharacter(NPC_GenerateCharacter("MarginPass", pchar.GenQuest.Marginpassenger.model, pchar.GenQuest.Marginpassenger.sex, pchar.GenQuest.Marginpassenger.ani, 2, sti(pchar.GenQuest.Marginpassenger.Nation), -1, true, "quest"));
			sld.Dialog.Filename = "Quest\Marginpassenger.c";
			sld.Dialog.currentnode = "MarginPass";
			sld.name = pchar.GenQuest.Marginpassenger.q1Name;
			sld.lastname = "";
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			Map_ReleaseQuestEncounter(npchar.id);
			npchar.Abordage.Enable = false; // ������ ��������
			npchar.ShipEnemyDisable = true;
			npchar.AlwaysFriend = true;
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), -1);
		break;
		
		case "MarginCap_4":
			DialogExit();
			NextDiag.CurrentNode = "MarginCap_repeat";
			pchar.GenQuest.Marginpassenger.Mustboarding = "true";
			AddQuestRecord("Marginpassenger", "5");
			AddQuestUserData("Marginpassenger", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")+"Acc")));
			AddQuestUserData("Marginpassenger", "sShipName", pchar.GenQuest.Marginpassenger.ShipName);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), -1);
		break;
		
		case "MarginCap_repeat":
			dialog.text = "�� ��� ��� ��������, �� ��� ��? ���������� � ����� �����!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "MarginCap_repeat";
		break;
		
		case "MarginCap_abordage":
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger.Mustboarding"))
			{
				dialog.text = "����, ��������! ������ ���� � ��� �� ���� ���������!";
				link.l1 = "� �� ��������� ���� ������ ������ �����... �� �� �������. ������ ����� �� ����!";
				link.l1.go = "MarginCap_abordage_1";
			}
			else
			{
				dialog.text = "����, ��������! ����� �� ����� �� ������ �����? � ��� ��� �� ������, �� ������ �������!";
				link.l1 = "���� � ���� �� ����� ���� ������ �������... "+pchar.GenQuest.Marginpassenger.q1Name+". ��� ����� ���� ��������.";
				link.l1.go = "MarginCap_abordage_2";
			}
		break;
		
		case "MarginCap_abordage_1":
			dialog.text = "��... ������� �������!";
			link.l1 = "������ ������� ����, ������...";
			link.l1.go = "MarginCap_abordage_3";
		break;
		
		case "MarginCap_abordage_2":
			dialog.text = "� ������ ���� ����� �� ������ ����� �� ���� �����? ������� ������� �����! �� ��, ������� �������!";
			link.l1 = "������ ������� ����, ������...";
			link.l1.go = "MarginCap_abordage_3";
		break;
		
		case "MarginCap_abordage_3":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Marginpassenger_GivePrisoner");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "MarginNeed":
			dialog.text = "��� ��� ������, "+GetAddress_Form(NPChar)+"?";
			link.l1 = "�� - "+pchar.GenQuest.Marginpassenger.q2Name+"?";
			link.l1.go = "MarginNeed_1";
		break;
		
		case "MarginNeed_1":
			dialog.text = "��, ��� �. �� ���, ������ ������ ��������? ����� ��� ������� �����...";
			link.l1 = "���������, ������. � ���� �������� ���������... ����� ����. ��� ������� ����� �� ����� "+pchar.GenQuest.Marginpassenger.q1Name+"?";
			link.l1.go = "MarginNeed_2";
		break;
		
		case "MarginNeed_2":
			switch (pchar.GenQuest.Marginpassenger.sex)
			{
				case "woman":
					dialog.text = "��, � ���� ��� �������... ��� ��! � � ��� ����?";
					link.l1 = "��� ������ � ���� ���������� �������: �������, �� ������� ��� ��������������, ��������� ������. ����� ����������� ������ � ����������� ������� ���� ������� � ��������� ��������. ��� ������� ��� ���� ��� - ��� � � ������ � ���.";
					link.l1.go = "MarginNeed_woman";
				break;
				case "man":
					dialog.text = "��, � ������ ���� ����� ��������. � � ��� ����?";
					link.l1 = "�� ����� � ���� ���������� �������: �������, �� ������� �� �������������, ��������� ������. ����� ����������� ������ � ����������� ������� ���� ������� � ��������� ��������. �� ������ ��� ���� ��� - ��� � � ������ � ���.";
					link.l1.go = "MarginNeed_man";
				break;
			}
		break;
		
		case "MarginNeed_woman":
			dialog.text = "����� ����! ��� ��� ������? � ������ �� �� ������� �� � �����?";
			link.l1 = "��� � ������������. ��� �������� ������ ������� ������� - ��� ������� �������. � ��� �� ������� �� ����� ���, �� �������� ��, ��� ��... ��� ��� ��� �������������, �� � ��� �� �������� ��� ����������� ���. �� �������� ��������������, �������.";
			link.l1.go = "MarginNeed_woman_1";
		break;
		
		case "MarginNeed_woman_1":
			dialog.text = "���... ���-�� � �� �������...";
			link.l1 = "�� ��� ��� �����������? �� ������� ��� ������, � ������� ��� �������, � �� ��� ����������� ��� �������� � ����� �����... �� ���� ������ �� ��� ��������, ���? � � ������ �� ��� ������ �������, ��������������� � ����� � ��������.";
			link.l1.go = "MarginNeed_money";
		break;
		
		case "MarginNeed_man":
			dialog.text = "����� ����! ��� �� ������? � ������ ��� ��� ������ � ����?";
			link.l1 = "�� � ������������. ��� �������� ������ ������� ������� - ��� ������� �������. � ��� �� ������� ��� ����� ���, �� �������� ��, ��� ��... ��� � ��� ���� ������������ �������� � ��������� ��� �����, � ��� �� �������� ��� ����������� ���. �� �������� ��������������, �������.";
			link.l1.go = "MarginNeed_man_1";
		break;
		
		case "MarginNeed_man_1":
			dialog.text = "���... ���-�� � �� �������...";
			link.l1 = "�� ��� ��� �����������? �� ������� ��� ������, � ������� ��� ������ ���������, � �� ��� ����������� ��� �������� � ����� �����. ��� ���� ���-��� ��������... � � ������ �� ��� ������ �������, ��������������� � ����� � ��������.";
			link.l1.go = "MarginNeed_money";
		break;
		
		case "MarginNeed_money":
			dialog.text = "���-���... � ������� �� �� �� ��� ������?";
			link.l1 = "����� ��������� - ��� ����� �������, � �� ����.";
			link.l1.go = "MarginNeed_money_1";
		break;
		
		case "MarginNeed_money_1":
			dialog.text = "������-������... ��� ������� �������� �� ������?";
			Link.l1.edit = 1;			
			link.l1 = "";
			link.l1.go = "MarginNeed_money_2";
		break;
		
		case "MarginNeed_money_2":
		iTemp = sti(dialogEditStrings[1]);
		int iSum = makeint(sti(pchar.GenQuest.Marginpassenger.Dublon)*5*stf(pchar.GenQuest.Marginpassenger.Chance));
		if (iTemp <= 0)
		{
			dialog.text = "����� ������! ������, ����� �������, ��� ��� �������� ��� ������. ��������!";
			link.l1 = "��...";
			link.l1.go = "MarginNeed_exit";
			break;
		}
		if (iTemp > 0 && iTemp <= iSum)
		{
			if (drand(2) > 1) // Addon-2016 Jason ��������� ������� ��������
			{
				dialog.text = "������, � ��������. � ���� ���� � ����� ��������� �����. ��� "+pchar.GenQuest.Marginpassenger.q1Name+"?";
				link.l1 = "������ ����, ��� �� �����. ��� ��� �����, ���������� ���������.";
				link.l1.go = "MarginNeed_dublon";
			}
			else
			{
				dialog.text = "� ���������, � ���� ��� ������ ���������� ��������. ���� ��� �� �������?";
				link.l1 = "��. �����, �������, �������, ��, �����, ������ ����� ������� � ����... ������� ����.";
				link.l1.go = "MarginNeed_peso";
				link.l2 = "���. ��� ����� ������ �������.";
				link.l2.go = "MarginNeed_dublon_exit";
			}
			break;
		}
		if (iTemp > iSum && iTemp < 1000)
		{
			dialog.text = "� ���������, ����� ����� � ���� ���. ��� ��� ��� ���� ����� ������� � �� ����� ����� �� ���� �����������. ��������!";
			link.l1 = "��...";
			link.l1.go = "MarginNeed_exit";
			break;
		}
		if (iTemp > 1000 && iTemp < 3000)
		{
			dialog.text = "������, �� ������� ���� �����? �� ������ �������������, ����� ��� ������? ���������� � �����!";
			link.l1 = "��...";
			link.l1.go = "MarginNeed_exit";
			break;
		}
			dialog.text = "�-��... ������, ��� ����� ���������� � ������, � ����������. � ��� ����������� ���, ���... �������, ��� � ����� ������ ��������� ����������������� ������. � ��� ��� ������� � ����. ��������!";
			link.l1 = "��...";
			link.l1.go = "MarginNeed_exit";
		break;
		
		case "MarginNeed_dublon":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			sld = characterFromId("MarginPass");
			RemovePassenger(Pchar, sld);
			sld.lifeday = 0;
			iTemp = sti(dialogEditStrings[1]);
			TakeNItems(pchar, "gold_dublon", iTemp);
			AddQuestRecord("Marginpassenger", "9");
			AddQuestUserData("Marginpassenger", "sSum", iTemp);
			CloseQuestHeader("Marginpassenger");
			DeleteAttribute(Pchar, "GenQuest.Marginpassenger");
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		break;
		
		case "MarginNeed_peso":
			dialog.text = "��� ����� � ��������� �� ����, ������� �� ������... ��� "+pchar.GenQuest.Marginpassenger.q1Name+"?";
			link.l1 = "������ ����, ��� �� �����. ��� ��� �����, ���������� ���������.";
			link.l1.go = "MarginNeed_peso_1";
		break;
		
		case "MarginNeed_peso_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			sld = characterFromId("MarginPass");
			RemovePassenger(Pchar, sld);
			sld.lifeday = 0;
			iTemp = sti(dialogEditStrings[1])*100;
			AddMoneyToCharacter(pchar, iTemp);
			AddQuestRecord("Marginpassenger", "10");
			AddQuestUserData("Marginpassenger", "sSum", FindRussianMoneyString(iTemp));
			CloseQuestHeader("Marginpassenger");
			DeleteAttribute(Pchar, "GenQuest.Marginpassenger");
			AddCharacterExpToSkill(pchar, "Fortune", 80);//�������
		break;
		
		case "MarginNeed_dublon_exit":
			dialog.text = "����� � ��� ���� ����� ������� �� ����� ����� �� ���� �����������. ��������!";
			link.l1 = "��...";
			link.l1.go = "MarginNeed_exit";
		break;
		
		case "MarginNeed_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Marginpassenger", "11");
			AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
			AddQuestUserData("Marginpassenger", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.City));
			pchar.GenQuest.Marginpassenger = "cabin";
		break;
		
		case "MarginPass":
			dialog.text = "���?.. ��� ����� ����������?!";
			link.l1 = "��� ����� ������, "+NPCharSexPhrase(NPChar, "��������","�������")+". �� ������������� �� ��� ������� � �������� ��������� ���������... � �������. �������������� �� �����, ������ ��� � ��������� ������ � �������� ���� � ����.";
			link.l1.go = "MarginPass_1";
		break;
		
		case "MarginPass_1":
			dialog.text = "�� ���� �� ������ �������, ��� � - "+NPCharSexPhrase(NPChar, "��� �������","���� ��������")+"?";
			link.l1 = "� ���, ������. �� "+NPCharSexPhrase(NPChar, "�������, � ������� �����. ����� �������...","��������, � ������� ������. ����� �������...")+"";
			link.l1.go = "MarginPass_2";
		break;
		
		case "MarginPass_2":
			dialog.text = "��... �� ��������� �� ���� ��������!";
			link.l1 = "�� ����� �� ����"+NPCharSexPhrase(NPChar, ", ��������","�, ��������")+". ������� ���� �� �, ������� ����� ���. � ������ �������� ���������� - ���� ���� � �����!";
			link.l1.go = "MarginPass_3";
		break;
		
		case "MarginPass_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "", "", "none", "", "", "", 1.0);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			pchar.quest.Marginpassenger_InWorldOver.over = "yes"; //����� ����������
			pchar.quest.Marginpassenger_Sink.over = "yes"; //����� ����������
			pchar.GenQuest.Marginpassenger = "take";
			if (rand(2) == 1) pchar.GenQuest.Marginpassenger.lose = "true";
			else Marginpassenger_CreateNeedman();
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger.Boarding")) AddQuestRecord("Marginpassenger", "6");
			else AddQuestRecord("Marginpassenger", "4");
			AddQuestUserData("Marginpassenger", "sName1", pchar.GenQuest.Marginpassenger.q1Name);
			AddQuestUserData("Marginpassenger", "sShipName", pchar.GenQuest.Marginpassenger.ShipName);
			AddQuestUserData("Marginpassenger", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")+"Acc")));
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}