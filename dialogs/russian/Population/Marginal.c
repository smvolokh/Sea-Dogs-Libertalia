//Jason ����� ������ ������� ���������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

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
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
			dialog.text = "��� ��� ����?";
			link.l1 = "������.";
			link.l1.go = "exit";
			link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
			link.l2.go = "quests";//(���������� � ���� ������)
			
			if (npchar.quest.meeting == "0")
			{
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && CheckAttribute(npchar, "quest.passenger") && !CheckAttribute(pchar, "GenQuest.Marginpassenger"))//������ ���������
				{
					dialog.text = "�� ��, �����! ��-��, ��. �������-�� �������, � ���� � ���� ���� ����...";
					link.l1 = "� ��� �� ��� �� ����-�� �����, �?";
					link.l1.go = "passenger";
					link.l2 = "����, � �����. ���-������ � ��������� ���...";
					link.l2.go = "exit_quest";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}
				dialog.text = LinkRandPhrase("��, �����, � ������-�� �����. ���� ����?","��� �� ������, ������� ������?","���, ��� ��� �� �� �������� ���������. ��� �� �����?");
				link.l1 = "�����������, "+GetAddress_FormToNPC(NPChar)+". ������ �� �������, � ����, ����� �� ��� ���-��� ���������.";
				link.l1.go = "question";
				link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
				link.l2.go = "quests";//(���������� � ���� ������)
				link.l3 = "�� ������, ���, � ������� ���...";
				link.l3.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

//----------------------------------------������ ���������� ��� ������------------------------------------------
			case "passenger":
				DeleteAttribute(npchar, "talker");
				dialog.text = "��. �� - ������� �������, �� ������, �, ������, � ���� ������� ��������... ��� ������ ����� ����� ����������� ���������� � ����� �� ��������� ����������� ��������?";
				link.l1 = "�� ������� �����, ����� �� ���� ���������� ���� ������ ����������� ����. � � ��� ������ ����?";
				link.l1.go = "passenger_1";
			break;
		
			case "passenger_1":
				dialog.text = "�����, ���, �����. ��� ����� ������� ������, ��� � �������. �� ��� - ������, � � ��� ��������, ����� � �� ����� ������� �������� ���������� �������, �� �������� ����� ������� �������� �����... � ���� �����, � ����. ���������?";
				link.l1 = "�� �����. � �� ��������� ����������� �����. ����������!";
				link.l1.go = "exit_quest";
				link.l2 = "� ������ ��� �����, ��� �� �� �������, �?";
				link.l2.go = "passenger_2";
			break;
		
			case "passenger_2":
				pchar.GenQuest.Marginpassenger.Dublon = 70+drand(5)*10;
				dialog.text = "� �� ����� ���������� ����, ������� ������. � ���� � ���� ������, � ��� �� ����� ��������. �� �����-�� "+sti(pchar.GenQuest.Marginpassenger.Dublon)+" �������� � ����������� ���� ������������� ��������. �� ����������� �� ���� ����������� ������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= sti(pchar.GenQuest.Marginpassenger.Dublon))
				{
					link.l1 = "��������. ���, �����. �� �������� ������ ���������� ��� �����-������ ����� ��� �������...";
					link.l1.go = "passenger_4";
				}
				link.l2 = "� ���� ��� ������ � ����� ������ ���������� ������� �����.";
				link.l2.go = "passenger_3";
				link.l3 = "�� ��������? ������� ����� ���� ������ �� ���������� ���? ��� �� �� ������...";
				link.l3.go = "exit_quest";
			break;
		
			case "passenger_3":
				dialog.text = "���? ������. � ���� � ��������� ����-������, � ��� �������� ����. ��� ������� ��������� - �������, �������� ���� ����� ��������, �� ������� ����, �������, ��-��!";
				link.l1 = "���� ���� �������? �����, ���� ������� - ������� ���� ������...";
				link.l1.go = "passenger_wait";
			break;
			
			case "passenger_wait":
			DialogExit();
				SetFunctionTimerCondition("Marginpassenger_Over", 0, 0, 2, false);
				npchar.dialog.currentnode = "passenger_repeat";
			break;

			case "passenger_repeat":
				dialog.text = "�� ���, ���� ������ ���������?";
				if (GetCharacterItem(pchar, "gold_dublon") >= sti(pchar.GenQuest.Marginpassenger.Dublon))
				{
					link.l1 = "��. ���, �����. �� �������� ������ ���������� ��� �����-������ ����� ��� �������...";
					link.l1.go = "passenger_4";
				}
				link.l2 = "���� ���. �����, �����...";
				link.l2.go = "exit";
				Nextdiag.Tempnode = "passenger_repeat";
			break;
			
			case "passenger_4"://��������� ����������
				pchar.quest.Marginpassenger_Over.over = "yes"; //����� ��������� ������
				RemoveItems(pchar, "gold_dublon", sti(pchar.GenQuest.Marginpassenger.Dublon));
				pchar.GenQuest.Marginpassenger.Name = GetFullName(npchar);
				pchar.GenQuest.Marginpassenger.City = npchar.city;
				pchar.GenQuest.Marginpassenger.Targetcity = SelectAnyColony(npchar.city); 
				pchar.GenQuest.Marginpassenger.Nation = npchar.nation;
				pchar.GenQuest.Marginpassenger.Days = 10+drand(5);
				pchar.GenQuest.Marginpassenger.ShipName = GenerateRandomNameToShip(sti(npchar.nation));
				pchar.GenQuest.Marginpassenger.q2Name = GenerateRandomName(sti(npchar.nation), "man");
				pchar.GenQuest.Marginpassenger.Chance = 0.8+frand(0.4);
				SelectMarginpassengerParameter();
				log_testinfo(pchar.GenQuest.Marginpassenger.Targetcity);
				dialog.text = "�� ����� ����� ����������, ���, �� ���� ����������. ������ ������: ����� "+FindRussianDaysString(sti(pchar.GenQuest.Marginpassenger.Days))+" �� ����� ������� ������ "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")))+" ��� ��������� '"+pchar.GenQuest.Marginpassenger.ShipName+"' � ���������� � ������� "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Targetcity+"Gen")+". �� ����� ����� �������� - "+pchar.GenQuest.Marginpassenger.Text+", ����� - "+pchar.GenQuest.Marginpassenger.q1Name+"\n������� "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")+"Gen"))+" ��������, ��� �������� - ������... ��� ��� ���� �������� ���� � ������� � ��� �� ��������. �������� ��� ���������� - �� ��� � ������ ���� ������ ���������, ��-��... �� � ������ ��� ��������� ������ �������� �����\n��� �� ���������, "+pchar.GenQuest.Marginpassenger.Text1+", ������ ��, ��������, ��������, �� ����� ����� ������ ���� �������� �� ������. ����� ������ ���� ������ � "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Targetcity)+". ��� ������� �������� �� ����� "+pchar.GenQuest.Marginpassenger.q2Name+"\n"+pchar.GenQuest.Marginpassenger.Text2+" � ����� ������ �� �������. ��, � ������� ����� ��������� - ��� ��� ���� ������, ��� �����, � �� ������� ��������� - ������� ����� ��� �����... �� "+sti(pchar.GenQuest.Marginpassenger.Dublon)*4+" �������� ������ ��������� �����. ��� ��������?";
				link.l1 = "��. ������ ���������� �� ������� � ������, ����� �� ������.";
				link.l1.go = "passenger_5";
			break;
		
			case "passenger_5":
				dialog.text = "�����! ����� ���������� �������. �����, ���, ����� ���� � ���� ��������� ����. ��, ���� �� �����: "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")))+" ����� ������������ �� �� �����, � �� ����� �� ���� ����������, ����� - �� ����. ��� ��� ������ � ���. �����, � ������� �� ������!";
				link.l1 = "����������. �������, �� �� �������� ��� �� ���� ����� � ������...";
				link.l1.go = "exit_quest";
				npchar.lifeday = 0;
				ReOpenQuestHeader("Marginpassenger");
				AddQuestRecord("Marginpassenger", "1");
				AddQuestUserData("Marginpassenger", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.City));
				AddQuestUserData("Marginpassenger", "sTargetCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Targetcity));
				AddQuestUserData("Marginpassenger", "sName", pchar.GenQuest.Marginpassenger.Name);
				AddQuestUserData("Marginpassenger", "sName1", pchar.GenQuest.Marginpassenger.q1Name);
				AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
				AddQuestUserData("Marginpassenger", "sDay", FindRussianDaysString(sti(pchar.GenQuest.Marginpassenger.Days)));
				AddQuestUserData("Marginpassenger", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")+"Voc")));
				AddQuestUserData("Marginpassenger", "sShipName", pchar.GenQuest.Marginpassenger.ShipName);
				AddQuestUserData("Marginpassenger", "sText", pchar.GenQuest.Marginpassenger.Text1);
				pchar.GenQuest.Marginpassenger = "begin";
				SetFunctionTimerCondition("Marginpassenger_InWorld", 0, 0, sti(pchar.GenQuest.Marginpassenger.Days), false);
			break;
			
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
		break;
		
		case "question":
			dialog.text = LinkRandPhrase("����� �� ���� ���� �� �����. ����������!","��, �� ������. ��� �� ������?","������� �������� �����? �����, �����, ������.");
			link.l1 = LinkRandPhrase("�� ���������� ��������� ������� ������ ������?","��������, ��� ����������� � ��������� ����� ���������?","��� ����������� �������� �� ����������, �� � �����?");
			link.l1.go = "rumours_marginal";
		break;
		
		case "exit_quest":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

void SelectMarginpassengerParameter()
{
	if (drand(1) == 0)
	{
		pchar.GenQuest.Marginpassenger.q1Name = GenerateRandomName(sti(pchar.GenQuest.Marginpassenger.Nation), "woman");
		pchar.GenQuest.Marginpassenger.model = "women_"+(rand(5)+11);
		pchar.GenQuest.Marginpassenger.sex = "woman";
		pchar.GenQuest.Marginpassenger.ani = "towngirl";
		pchar.GenQuest.Marginpassenger.Text2 = "�� ����� �� ��� ��������, ��� ��������� ������� �� ������� ����������� �����";
		switch (drand(4))
		{
			case 0: 
				pchar.GenQuest.Marginpassenger.Text = "����� �����, ������� ��������";
				pchar.GenQuest.Marginpassenger.Text1 = "� �� ����, ������� ��������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_store";
			break;
			case 1: 
				pchar.GenQuest.Marginpassenger.Text = "����� ��������� �����";
				pchar.GenQuest.Marginpassenger.Text1 = "� �� ����, ��������� �����";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_shipyard";
			break;
			case 2: 
				pchar.GenQuest.Marginpassenger.Text = "����� �����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� �� ����, �����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_tavern";
			break;
			case 3: 
				pchar.GenQuest.Marginpassenger.Text = "����� ����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� �� ����, ����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_bank";
			break;
			case 4: 
				pchar.GenQuest.Marginpassenger.Text = "����� ���������� ��������� ����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� �� ����, ���������� ��������� ����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_portoffice";
			break;
		}
	}
	else
	{
		pchar.GenQuest.Marginpassenger.q1Name = GenerateRandomName(sti(pchar.GenQuest.Marginpassenger.Nation), "man");
		pchar.GenQuest.Marginpassenger.model = "citiz_"+(rand(9)+11);
		pchar.GenQuest.Marginpassenger.sex = "man";
		pchar.GenQuest.Marginpassenger.ani = "man";
		pchar.GenQuest.Marginpassenger.Text2 = "�� ����� ����� ��������� � ������� � ���� �����, ��� ��������� ������� �� �������� ����������� �����";
		switch (drand(4))
		{
			case 0: 
				pchar.GenQuest.Marginpassenger.Text = "������� ����������� �����, ������� ��������";
				pchar.GenQuest.Marginpassenger.Text1 = "� ��� ������������, ������� ��������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_store";
			break;
			case 1: 
				pchar.GenQuest.Marginpassenger.Text = "������� ����������� ��������� �����";
				pchar.GenQuest.Marginpassenger.Text1 = "� ��� ������������, ��������� �����";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_shipyard";
			break;
			case 2: 
				pchar.GenQuest.Marginpassenger.Text = "������� ����������� �����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� ��� ������������, �����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_tavern";
			break;
			case 3: 
				pchar.GenQuest.Marginpassenger.Text = "������� ����������� ����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� ��� ������������, ����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_bank";
			break;
			case 4: 
				pchar.GenQuest.Marginpassenger.Text = "������� ����������� ���������� ��������� ����������";
				pchar.GenQuest.Marginpassenger.Text1 = "� ��� ������������, ���������� ��������� ����������";
				pchar.GenQuest.Marginpassenger.loc = pchar.GenQuest.Marginpassenger.City+"_portoffice";
			break;
		}
	}
	if (sti(pchar.rank) < 4) pchar.GenQuest.Marginpassenger.ShipType = SHIP_BARQUE;
	if (sti(pchar.rank) >= 4 && sti(pchar.rank) < 7) pchar.GenQuest.Marginpassenger.ShipType = SHIP_BARKENTINE + rand(makeint(SHIP_FLEUT - SHIP_BARKENTINE));
	if (sti(pchar.rank) >= 7 && sti(pchar.rank) < 10) pchar.GenQuest.Marginpassenger.ShipType = SHIP_CARAVEL + rand(makeint(SHIP_CARACCA - SHIP_CARAVEL));
	if (sti(pchar.rank) >= 10 && sti(pchar.rank) < 16) pchar.GenQuest.Marginpassenger.ShipType = SHIP_GALEON_L;
	if (sti(pchar.rank) >= 16) pchar.GenQuest.Marginpassenger.ShipType = SHIP_NAVIO + rand(makeint(SHIP_HEAVYGALEON - SHIP_NAVIO));
}
