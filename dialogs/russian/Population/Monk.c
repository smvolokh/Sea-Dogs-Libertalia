//Jason ����� ������ ������� �������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp, iTest;
	string sTemp, sTitle;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Citizen\" + NPChar.City + "_Citizen.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	iTest = FindColony(NPChar.City);
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                       PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
			//--> ������ ������ �������
			if (npchar.quest.meeting == "0")
			{
				if (CheckAttribute(npchar, "quest.donation"))//�������������
				{
					dialog.text = "������ ����, ��� ���. � ����� ���� ������� ������� � ������������ ��������� ���������� ����� �� ������ ����.";
					link.l1 = "��, ���� ������ ���� - �� �������, ���������� ����. ������� ���� �������� ��������. � ��� �� ���� ����� - � ���� ������?";
					link.l1.go = "donation";
					link.l2 = "�������, �� ������������ � �������� � ������ ������ ��� ���������� �� � ����.";
					link.l2.go = "exit";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}
				bool ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
				if (ok && sti(Pchar.Ship.Type) != SHIP_NOTUSED && CheckAttribute(npchar, "quest.passenger") && !CheckAttribute(pchar, "GenQuest.Monkpassenger") && 6-sti(RealShips[sti(Pchar.Ship.Type)].Class) > 0 && 6-sti(RealShips[sti(Pchar.Ship.Type)].Class) < 3)//�����-��������
				{
					dialog.text = "������ ����, ��� ���. � �� ����� ��������� ���� �� ����� ������. �� ���������� ������, �������.";
					link.l1 = "������ ���, ������ ����. � ��� ������ ����?";
					link.l1.go = "passenger";
					link.l2 = "��������, �����, �� � ����� �����.";
					link.l2.go = "exit";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && CheckAttribute(npchar, "quest.capellan") && !CheckAttribute(pchar, "questTemp.ShipCapellan"))//����������� ��������
				{
					dialog.text = "����������� ����, ��� ���. ��� � ����, �� - �������. ������� � ���� � ���� ���� �����������.";
					link.l1 = "������ ��� �����������, ������ ����.";
					link.l1.go = "capellan";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}
				dialog.text = PCharRepPhrase(LinkRandPhrase("�����������, ��� ���. ����� ����� ������� ���� �� ���?","����������, ��� ���. ���� �� ������� ��������� � ������ ����� - �������� � ���������� ������.","������ ����, ��� ���. ������ ���� ���� � �������, ���� ��� �� ������� ������."),LinkRandPhrase("�����������, ��� ���. ����� ����� ������� ���� �� ���?","����������, ��� ���, �� ����� ������������� ���� ����!","������ ����, ��� ���. �� ��������� �� ���� ��������� ��������!"));
				link.l1 = LinkRandPhrase("� ��� ������� ���, ������ ����. ��� ���� ����?","������������, ������ ����. ��� ���� � �������?","��� ���� ����, ������ ����?");
				link.l1.go = "check";//�� ��������� ������ �������
				link.l2 = RandPhraseSimple("� ���� ���� ������ � ���.", "��� ����� ����������.");
				link.l2.go = "quests";//(���������� � ���� ������)
				if (GetSquadronGoods(pchar, GOOD_SLAVES) > 0 && sti(pchar.money) >= GetSquadronGoods(pchar, GOOD_SLAVES)*10)
				{
					link.l3 = "������ ����, � ���� �� ����� ��������� ����. ��� ���������� � ������� ��������� � ����������. � �� ����� ��������� ��� ��������� ����������, ���������� ��������, � � ����� ������ �� �� ������� �� ����� ����� ������.";
					link.l3.go = "slaves";
				}
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && sti(pchar.reputation.nobility) > 41 && !CheckAttribute(pchar, "GenQuest.Shipshine") && 6-sti(RealShips[sti(Pchar.Ship.Type)].Class) > 0)
				{
					link.l4 = "������ ����, � �� ����� ��������� ��� �������� ��� �������. ������� ��� ����� ��� ������?";
					link.l4.go = "shipshine";
				}
				link.l10 = LinkRandPhrase("��������, ������ ����, ��� ���� ����.","�������� �� ������������, ������ ����.","��� ����� ������������ �� �������, ������ ����. �� ��������!");
				link.l10.go = "exit";
				npchar.quest.meeting = "1";
			}
			else
			{
				//--> ������ ������ �������
				dialog.text = LinkRandPhrase("��� ����� ��, ��� ���? ��� �� �����?","�� ���-�� ��� ����� ������� ���, ��� ���?","��� ����� ������ ����, ��� ���.");
				link.l1 = LinkRandPhrase("����� ��������, ������ ����, ��� ���� ����?","����� ��������, ������ ����, ��� ���� � �������?","��� ���� ����, ������ ����?");
				link.l1.go = "check";//�� ��������� ������ �������
				link.l2 = RandPhraseSimple("� ���� ���� ������ � ���.", "��� ����� ����������.");
				link.l2.go = "quests";//(���������� � ���� ������)
				if (GetSquadronGoods(pchar, GOOD_SLAVES) > 0 && sti(pchar.money) >= GetSquadronGoods(pchar, GOOD_SLAVES)*10 && !CheckAttribute(npchar, "quest.slaves"))
					{
						link.l3 = "������ ����, � ���� �� ����� ��������� ����. ��� ���������� � ������� ��������� � ����������. � �� ����� ��������� ��� ��������� ����������, ���������� ��������, � � ����� ������ �� �� ������� �� ����� ����� ������.";
						link.l3.go = "slaves";
					}
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && sti(pchar.reputation.nobility) > 41 && !CheckAttribute(pchar, "GenQuest.Shipshine") && 6-sti(RealShips[sti(Pchar.Ship.Type)].Class) > 0)
				{
					link.l4 = "������ ����, � �� ����� ��������� ��� �������� ��� �������. ������� ��� ����� ��� ������?";
					link.l4.go = "shipshine";
				}
				link.l10 = LinkRandPhrase("��������, ������ ����, ��� ���� ����.","�������� �� ������������, ������ ����.","��� ����� ������������ �� �������, ������ ����. �� ��������!");
				link.l10.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "check":
			if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && rand(8) < 3 && !CheckAttribute(npchar, "quest.monkletter") && !CheckAttribute(pchar, "GenQuest.Monkletter") && !CheckAttribute(npchar, "quest.passenger")) //��������� ������
			{
				pchar.GenQuest.Monkletter.City = FindFriendCityToMC(false);
				pchar.GenQuest.Monkletter.StartCity = npchar.city;//����� ������������
				dialog.text = "� ���� ��� ��� ���� ������� � ����, ��� ���. ��� ���������� �� ����������� ������� �������� ������ ��� ���������� ������ "+XI_ConvertString("Colony"+pchar.GenQuest.Monkletter.City+"Gen")+". �� ������� �� � �� ������� �������������? ����� ��������� ��������� �� ��� ������...";
				link.l1 = "� ��� ����� ����� ������ ���, ������ ����. ������� ���� ������, � ������� �� � ������� "+XI_ConvertString("Colony"+pchar.GenQuest.Monkletter.City+"Gen")+".";
				link.l1.go = "Monkletter";
				link.l2 = "� �� � ���, ������ ����, �� ��� ������ � ������ �������.";
				link.l2.go = "exit_monkletter";
				npchar.quest.monkletter = "true";
				break;
			}
			if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && rand(8) > 5 && sti(pchar.rank < 11) && !CheckAttribute(npchar, "quest.churchbooks") && !CheckAttribute(pchar, "GenQuest.Churchbooks") && !CheckAttribute(npchar, "quest.passenger")) //�������� ������������
			{
				pchar.GenQuest.Churchbooks.StartCity = npchar.city;//����� ������������
				pchar.GenQuest.Churchbooks.Nation = npchar.nation;
				dialog.text = "��� ���, �� ����������� �� ��� ������ � ����� ��������� ����? � ����� ������ ������������� ������������, ������� �� ������������ ������� ����� ���������� �� �� �������\n�� ��� �� �� �� ����������� � ��������� ������� "+NationNameGenitive(sti(npchar.nation))+", ����� � ���������� �������� ������ ��������� �������� ������������� � �������� � ��� ������? � ���� �������� - ������ ��� �� �����: ������������ ��� �� ������.";
				link.l1 = "� ������������� ������ ����� ������. ������������ ����� �������� � ������ ����������?";
				link.l1.go = "Churchbooks";
				link.l2 = "� �� � ���, ������ ����, �� � ���� ������������� ������ ��� ����� �����������.";
				link.l2.go = "exit_churchbooks";
				npchar.quest.churchbooks = "true";
				break;
			}
			
			dialog.text = RandPhraseSimple("��� ������, ��� ���. ������� �� ������������ � ����� ������.", "� ����� ������� ��� ��������, ��� ���. ��������� �� ����������� ������ � ������������ ������.");
			link.l1 = "����� � ����� �� ����� �����, ������ ����.";
			link.l1.go = "exit";
		break;
		
//-------------------------------------------------�������������------------------------------------------------
		case "donation":
			sTemp = DonationType();
			dialog.text = "�������, ��� ���. "+sTemp+"";
			link.l1 = "����� ������������� ����� ��������� �����������?";
			link.l1.go = "donation_1";
		break;
		
		case "donation_1":
			dialog.text = "������� �������� ���� ���� ������ � ���� ������ �������, ��� ���. � ���� ��� ������ ����.";
			link.l1 = "100 ����.";
			link.l1.go = "donation_rate_1";
			link.l2 = "1000 ����.";
			link.l2.go = "donation_rate_2";
			link.l3 = "5000 ����.";
			link.l3.go = "donation_rate_3";
			link.l4 = "10000 ����.";
			link.l4.go = "donation_rate_4";
		break;
		
		case "donation_rate_1"://������� ������
			if (sti(pchar.money) >= 100)
			{
				AddMoneyToCharacter(pchar, -100);
				dialog.text = "��������� ����, ��� ���, �� ���� ������. ��� ������ �� ������ ����!";
				link.l1 = "�� �� �� ���, ������ ����.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "���� �������� ���� ����, ����������! �������� ��� ���������� ������ ������ - ������������!";
				link.l1 = "��-��! � �� ����� ���������. ����������!";
				link.l1.go = "donation_exit";
			}
		break;
		
		case "donation_rate_2":
			if (sti(pchar.money) >= 1000)
			{
				AddMoneyToCharacter(pchar, -1000);
				dialog.text = "��������� ����, ��� ���. ��� ����� ����� ������� � ���� ������ ����������. ������������ ����!";
				link.l1 = "������� � ����� �������� ����, ������ ����!";
				link.l1.go = "exit";
				AddCharacterHealth(pchar, 5);
				AddCharacterExpToSkill(pchar, "Leadership", 20);
				AddCrewMorale(pchar, 2);
			}
			else
			{
				dialog.text = "���� �������� ���� ����, ����������! �������� ��� ���������� ������ ������ - ������������!";
				link.l1 = "��-��! � �� ����� ���������. ����������!";
				link.l1.go = "donation_exit";
			}
		break;
		
		case "donation_rate_3":
			if (sti(pchar.money) >= 5000)
			{
				AddMoneyToCharacter(pchar, -5000);
				dialog.text = "� ���� �� ��� ��������, ��� �� ������ ����� ����, ��� ���. ������������ ���� � � �������������� �������� ���� ������.";
				link.l1 = "��� �� ���� ����� �� ����������� ����. ������� ���, ������ ����!";
				link.l1.go = "exit";
				AddCharacterHealth(pchar, 5);
				AddCharacterExpToSkill(pchar, "Leadership", 40);
				AddCrewMorale(pchar, 3);
				ChangeCharacterComplexReputation(pchar, "nobility", 1);
				ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 1);
			}
			else
			{
				dialog.text = "���� �������� ���� ����, ����������! �������� ��� ���������� ������ ������ - ������������!";
				link.l1 = "��-��! � �� ����� ���������. ����������!";
				link.l1.go = "donation_exit";
			}
		break;
		
		case "donation_rate_4":
			if (sti(pchar.money) >= 10000)
			{
				AddMoneyToCharacter(pchar, -10000);
				dialog.text = "� �� ���������, ��� ���? �� ������������� ��������� ������ �����? ������������ ���� � � �������������� �������� ����� ������ ���������� - �������� ����� � ������ ����!";
				link.l1 = "�� ��� ������ �� ����� �������� ������ ������. � ���� ��������� ���� ��������� ����� �����, � � � �������� ������� �� ���. �������, ������ ����!";
				link.l1.go = "exit";
				AddCharacterHealth(pchar, 10);
				AddCharacterExpToSkill(pchar, "Leadership", 60);
				AddCrewMorale(pchar, 5);
				ChangeCharacterComplexReputation(pchar, "nobility", 1);
				ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
				ChangeCrewExp(pchar, "Sailors", 5);
				ChangeCrewExp(pchar, "Cannoners", 5);
				ChangeCrewExp(pchar, "Soldiers", 5);
			}
			else
			{
				dialog.text = "���� �������� ���� ����, ����������! �������� ��� ���������� ������ ������ - ������������!";
				link.l1 = "��-��! � �� ����� ���������. ����������!";
				link.l1.go = "donation_exit";
			}
		break;
		
		case "donation_exit":
			DialogExit();
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
			AddCharacterHealth(pchar, -5);
			LAi_CharacterDisableDialog(npchar);
		break;
		
//-------------------------------------------��������� �����---------------------------------------------------
		case "slaves":
			dialog.text = "�������, ��� ���. ��� ���� - �������� �����������. � ������� ���� �������.";
			link.l1 = "���������, ������ ����. � ��������� �� ����� ������ �� ������ ���������� ����� �� ������� ����������� � ������������ ������.";
			link.l1.go = "slaves_1";
		break;
		
		case "slaves_1":
			AddMoneyToCharacter(pchar, -GetSquadronGoods(pchar, GOOD_SLAVES)*10);
			dialog.text = "����� ������, ��� ���, ��� �� �� ��������� � ��������� ������������� ������������ ������������� ������������. ���� ������ ������ �� ������ ����. ������ ������ �� ���� �������?";
			link.l1 = "��, �����. �������� �� ����!";
			link.l1.go = "slaves_2";
		break;
		
		case "slaves_2":
			npchar.quest.slaves = "true";
			DialogExit();
			SetLaunchFrameFormParam("������ ��� ����"+ NewStr() +"���� �������� �� �������", "Monk_RemoveSlaves", 0, 4);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 10); //������ �����
			RecalculateJumpTable();
		break;
//<-- ��������� �����

//----------------------------------------------�������� �������------------------------------------------------
		case "shipshine":
			//����� �������� ������
			iTemp = 6;
			for (i=0; i<COMPANION_MAX; i++)
			{
				int iIdx = GetCompanionIndex(GetMainCharacter(), i);
				if (iIdx >= 0)
				{
					sld = GetCharacter(iIdx);
					if (GetCharacterShipClass(sld) < iTemp) iTemp = GetCharacterShipClass(sld);
				}
			}
			switch (GetCompanionQuantity(pchar))
			{
				case 1: 
					sTemp = "� ���� � ������� ���� �������, "+iTemp+" ������.";
					pchar.GenQuest.Shipshine.Money = 5000*(6-iTemp);
				break;
				case 2:
					sTemp = "� ���� � ������� ��� �������, ���������� - "+iTemp+" ������.";
					pchar.GenQuest.Shipshine.Money = makeint(1.8*(5000*(6-iTemp)));
				break;
				case 3:
					sTemp = "� ���� � ������� ��� �������, ���������� - "+iTemp+" ������.";
					pchar.GenQuest.Shipshine.Money = makeint(2.6*(5000*(6-iTemp)));
				break;
				case 4:
					sTemp = "� ���� � ������� ������ �������, ���������� - "+iTemp+" ������.";
					pchar.GenQuest.Shipshine.Money = makeint(3.4*(5000*(6-iTemp)));
				break;
				case 5:
					sTemp = "� ���� � ������� ���� ��������, ���������� - "+iTemp+" ������.";
					pchar.GenQuest.Shipshine.Money = makeint(4.2*(5000*(6-iTemp)));
				break;
			}
			dialog.text = "��� ����� �������� �� ����, ������� � ���� �������� � �������, � ��������� ��� ������.";
			link.l1 = ""+sTemp+"";
			link.l1.go = "shipshine_1";
		break;
		
		case "shipshine_1":
			dialog.text = "��� ��������� ���� � "+FindRussianMoneyString(sti(pchar.GenQuest.Shipshine.Money))+", ��� ���.";
			if (sti(pchar.money) >= sti(pchar.GenQuest.Shipshine.Money))
			{
				link.l1 = "� ����� ��������� ��� �����, �����. ��� ������.";
				link.l1.go = "shipshine_2";
			}
			link.l2 = "� ���������, � ���� ��� ����� �����.";
			link.l2.go = "shipshine_exit";
		break;
		
		case "shipshine_2":
			AddMoneyToCharacter(pchar, -sti(pchar.GenQuest.Shipshine.Money));
			dialog.text = "������, ��� ���. ����� �� ����� ������� � ���������� � ����.";
			link.l1 = "�������� �� ����, ������ ����...";
			link.l1.go = "shipshine_3";
		break;
		
		case "shipshine_3":
			DialogExit();
			SetLaunchFrameFormParam("������ ��������� �����"+ NewStr() +"����� �������� ���������", "Monk_Shipshine", 0, 4);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, GetCompanionQuantity(pchar), 10); //������ �����
			RecalculateJumpTable();
		break;
		
		case "shipshine_exit":
			DialogExit();
			DeleteAttribute(Pchar, "GenQuest.Shipshine");
		break;
//<-- �������� �������

//------------------------------------------����������� ��������-----------------------------------------------
		case "capellan":
			dialog.text = "� - ����������� �������� �� ������. � �������� ����� ������ � �������� �� ������������ �����������. ������ � ��� ������ ��������, � �������� � �� ������� �� �����. �� ������� ��������� ���� � �������?";
			link.l1 = "����������� ���������? �������, �����, � ����� ������� �� ������ ��������� �� �������?";
			link.l1.go = "capellan_1";
			pchar.questTemp.ShipCapellan = "true";
		break;
		
		case "capellan_1":
			dialog.text = "��� ���, ��� �� ������. � ������ ������� �� ���� � ���� �������, ������������ ����� �������� ����� ����, ��� ����� ������ �� �������� ���� � ����. ���� ������� ����� ��������� ����������� � ��������������, � ������ � ������ ����� ������� ���, ��� ���������� ���������� ��������\n��� ���� �� � ����� �������: ������������ ������� � ������� ���������� ����� ����, ����� � ����� � ����, ��� ��� ����� ��������. � ��.";
			if (sti(pchar.money) >= 50000)
			{
				link.l1 = "����� ���������... �� ����� - ������� ������� ������ ���������� �� ������ � ������� ���������� �����, �� ����� � �� �� ����������� �����. ����� ���������� �� ����, �����!";
				link.l1.go = "capellan_2";
			}
			link.l2 = "���, �����. � ���������, � ���� ������������ �������, ����� �������� ���� ������.";
			link.l2.go = "capellan_exit";
		break;
		
		case "capellan_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "capellan_2":
			AddMoneyToCharacter(pchar, -50000);
			chrDisableReloadToLocation = true;//������� �������
			dialog.text = "��������� �� �������, ��� ���. �� ������� �������� ���� ������. �� ���� ����� ������������ ����: � ����� ������ ��������� ���������, �������, �������� �� ��� �����. �� � ������� �� ����� ������������� �� ����� ���������� �����!\n���� �� ����� ������ ������� �� ��������� �������� ������� � ������� ���������� ��� ��������� ������ - � ���������� ������ ���� ������� � ������ �� �����.";
			link.l1 = "� ���� ���, ������ ����, � ���������� �� ������������ ���. � ������ ������ ����� ������������ �� ��� �����!";
			link.l1.go = "capellan_3";
		break;
		
		case "capellan_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "My_Campus", "rld", "loc1", "Monk_Capellan", -1);
			pchar.questTemp.ShipCapellan.id = npchar.id;
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "CityType");//������� ������� �������
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			pchar.questTemp.ShipCapellan.Yes = "true";//�������� � �������
			ChangeCharacterComplexReputation(pchar, "authority", 5);
			npchar.reputation = 60;
		break;
		
		case "capellan_4":
			dialog.text = "�� ���-�� �����, ��� ���?";
			link.l1 = "���, ������, ������ ����.";
			link.l1.go = "exit";
			link.l2 = "�����, � �� ����� ��������� ��� � ��������� ����� ����� �� �����. ��������� ��� �� ��������� ������� ����� �������.";
			link.l2.go = "capellan_5";
			NextDiag.TempNode = "capellan_4";
		break;
		
		case "capellan_5":
			dialog.text = "������, ��� ���. ��� ������� - �� ����� ������� �� ����� ��������� �������, ����� �������� �������. � ����� � ������ �� ���������.";
			link.l1 = "������� �� ���������, ������ ����.";
			link.l1.go = "capellan_6";
		break;
		
		case "capellan_6":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			ShipCapellan_Remove();
		break;
		
		case "capellan_7":
			dialog.text = "� ��� ������������, �������: ������ ������������� - ���� ���� �� ����� �� ����� �����. � ������ �� ����� � ����� �� �����.";
			link.l1 = "��...";
			link.l1.go = "exit";
			NextDiag.TempNode = "capellan_7";
		break;
//<-- ��������
	
//--------------------------------------------�����-��������---------------------------------------------------
		case "passenger":
			if (drand(19) < 15) SetPassengerParameter("Monkpassenger", false);
			else SetPassengerParameter("Monkpassenger", true);
			dialog.text = "��� ���, ��� ������ ����� ��������� �� ������� " + XI_ConvertString("Colony"+pchar.GenQuest.Monkpassenger.City)+", ��� �� "+XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Monkpassenger.City)+"Dat")+", �� "+FindRussianDaysString(sti(pchar.GenQuest.Monkpassenger.DaysQty))+". �� ��� � ������� ���� "+FindRussianMoneyString(sti(pchar.GenQuest.Monkpassenger.Money))+". ��� �������?";
			link.l1 = "� ��������, ������ ����.";
			link.l1.go = "passenger_1";
			link.l2 = "�������, ������ ����, �� ��� ������ � ������ �������. ����� �� ���� ������.";
			link.l2.go = "passenger_exit";
			npchar.quest.passenger = true;
		break;
		
		case "passenger_exit":
			dialog.text = "�� ��� ���� �����, ��� ���. ������� ������� �������. ������ � �����!";
			link.l1 = "�� ��������, �����.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "GenQuest.Monkpassenger");
		break;
		
		case "passenger_1":
			dialog.text = "��������� ����. ������ �������� �� �������� �� �����.";
			link.l1 = "������������� �� ��� �����, ������ ����. �� ����� ������������.";
			link.l1.go = "passenger_2";
		break;
		
		case "passenger_2":
			DialogExit();
			pchar.GenQuest.Monkpassenger.id = npchar.id;
			DeleteAttribute(npchar, "LifeDay");
			LAi_RemoveLoginTime(npchar);
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "1");
			AddQuestUserDataForTitle(sTitle, "sType", "������");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			sTemp = XI_ConvertString("Colony" +pchar.GenQuest.Monkpassenger.City+"Gen") + ", ��� �� " + XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Monkpassenger.City)+"Dat")+".";
			AddQuestUserDataForTitle(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sDays", FindRussianDaysString(sti(pchar.GenQuest.Monkpassenger.DaysQty)));
            AddQuestUserData(sTitle, "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Monkpassenger.Money)));
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			pchar.quest.Monkpassenger.win_condition.l1 = "location";
			pchar.quest.Monkpassenger.win_condition.l1.location = pchar.GenQuest.Monkpassenger.City+"_town";
			pchar.quest.Monkpassenger.function = "Monkpassenger_complete";
			SetFunctionTimerCondition("Monkpassenger_Over", 0, 0, sti(pchar.GenQuest.Monkpassenger.DaysQty), false);
		break;
		
		case "passenger_3":
			pchar.quest.Monkpassenger_Over.over = "yes"; //����� ������
			dialog.text = "�������������, ��� ���. �� �������� ���� �������������, ������ ��� ������� ��������� ����. ����� ������, ��� � � ������.";
			link.l1 = "�������. �����, ������ ����!";
			link.l1.go = "passenger_4";
		break;
		
		case "passenger_4":
			DialogExit();
			npchar.lifeday = 0;
			RemovePassenger(Pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Monkpassenger.Money));
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
			OfficersReaction("good");				
			AddCharacterExpToSkill(pchar, "Sailing", 80);
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			if (CheckAttribute(pchar, "GenQuest.Monkpassenger.Enemycity")) AddCharacterExpToSkill(pchar, "Sneak", 50);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "3");
			CloseQuestHeader(sTitle);
			DeleteAttribute(Pchar, "GenQuest.Monkpassenger");
		break;
//<-- �����-��������
		
//---------------------------------------------��������� ������-------------------------------------------------
		case "exit_monkletter":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Monkletter");
		break;
		
		case "Monkletter":
			dialog.text = "���. ����� ���� �����, ��� ���. ����� - ���� ����� �������� ��� � ������� ���� ������, ���������� ����� ����. ������, � �� ������ ���� ������� � ����� �����������!";
			link.l1 = "� �� �������, ������ ����. �� ��������!";
			link.l1.go = "Monkletter_1";
		break;
		
		case "Monkletter_1":
			DialogExit();
			GiveItem2Character(pchar, "letter_church");
			ReOpenQuestHeader("Monkletter");
			AddQuestRecord("Monkletter", "1");
			AddQuestUserData("Monkletter", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Monkletter.City+"Gen"));
			AddQuestUserData("Monkletter", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Monkletter.StartCity));
			SetFunctionTimerCondition("Monkletter_Over", 0, 0, 15, false);
			OfficersReaction("good");
		break;
//<-- ��������� ������
		
//-------------------------------------------��������� ������������---------------------------------------------
		case "exit_churchbooks":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Churchbooks");
		break;

		case "Churchbooks":
			dialog.text = "��. �� ������� �������� �� � ����� ������� "+NationNameGenitive(sti(npchar.nation))+". ���������� ������������ ����� ������ ������� ����, � �������. �� ������� ���� ������� � ����!";
			link.l1 = "�������. ����� ������������ ����� � ���.";
			link.l1.go = "Churchbooks_1";
		break;
		
		case "Churchbooks_1":
			DialogExit();
			ReOpenQuestHeader("Churchbooks");
			AddQuestRecord("Churchbooks", "1");
			AddQuestUserData("Churchbooks", "sNation", NationNameGenitive(sti(pchar.GenQuest.Churchbooks.Nation)));
			AddQuestUserData("Churchbooks", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Churchbooks.StartCity));
			SetFunctionTimerCondition("Churchbooks_Over", 0, 0, 30, false);
			pchar.GenQuest.Churchbooks = "go";
			switch (rand(4))
			{
				case 0: pchar.GenQuest.Churchbooks.Item = "amulet_2"; break;
				case 1: pchar.GenQuest.Churchbooks.Item = "amulet_3"; break;
				case 2: pchar.GenQuest.Churchbooks.Item = "amulet_6"; break;
				case 3: pchar.GenQuest.Churchbooks.Item = "amulet_7"; break;
				case 4: pchar.GenQuest.Churchbooks.Item = "amulet_10"; break;
			}
			OfficersReaction("good");
		break;
//<-- ��������� ������������
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string DonationType()
{
	string sText;
	switch (drand(9))
	{
		case 0: sText = "� ������� ������ �� ��������� "+LinkRandPhrase("�������","����������","��������")+". ������� ������ ������ ���� � ��������, � � �������� ���������� � ������������� ����� ����� ���." break;
		case 1: sText = "� ������� ������������� ��� ����� ������. �� � ������� ������ ���� ����� �������� ���� �����, �� ������ ������ ��������� ������ ���� ������� ����." break;
		case 2: sText = "� ������� ������ �� ������� �������� ��� ������ ������ ����� � ��������. �����������, ��� ������ �� ��� ��� �������� ����� ��������� ���." break;
		case 3: sText = "� ������� �������� �� ����� ������ ��� ����� ������ - ����������� �� ������ ��� ���������� ������ � ����������. ������ � ������ - ���� ������� ��������� �����������." break;
		case 4: sText = "� ������� ������ �� ������ ����� ������ - ������ ��������� ���� � ��������� �����, � ��������� ������ ��������� � �������. ������ � ������ - ���� ������� ��������� �����������." break;
		case 5: sText = "� ������� �������� ��������, ����� �������� ���� �������� ���������, ������� ������ ��������� ����� ����� ������ �������������� ��������� �� ���������� ������. �������� ������ � ��� ������ ���� - ���� ������� ��������� �����������." break;
		case 6: sText = "� ������� ������ �� ����� ��������� ��� ����� ������. ������ � ��� ������, � ���� ������������ ��������. � ������� �� ���� ������." break;
		case 7: sText = "� ����� �������� ������ ����� ������� ������� � �������� �������. �� ��������� ��������� � ������������ ��������. �������� ��, ��� ��, ��� ����� ������, ������ �������� ��������� ������� ��������." break;
		case 8: sText = "� ������� ������� ������ �� ���������� � ������ ��� ��������� ������� ����� �������, � ������� ���� ������� - �� ������ �������. �������� ��." break;
		case 9: sText = "� ����������� ������ � ������������� ����� � ����� ������� � �������� �������, ����� ���� ��������� �����, � ������� �������� �� ����������� ����������. �������� �� � �� ������� ����!" break;
	}
	return sText;
}