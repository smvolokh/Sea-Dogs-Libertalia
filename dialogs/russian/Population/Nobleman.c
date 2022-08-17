//Jason ����� ������ ������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp, iTest;
	string sTemp, sTitle;
	float locx, locy, locz;

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
	
	iTest = FindColony(NPChar.City); // 170712
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
			//--> �������� ��������������� ���������
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
				dialog.text = NPCStringReactionRepeat("��. �� ������ ��� ������ "+NationNameGenitive(sti(pchar.nation))+", ��������. ������ ����� �� ������� �����, � ����� ������? ��������!", 
					"� �� �����, ����� ���� ����������� � ����� � "+NationNameAblative(sti(pchar.nation))+"! ����������, �� �� ����� ������ ������!", 
					"��� ���� ��������� ���� �������� �����. ����� - ����� �� ����.",
					"��, � ���� ������������. ������ �� ����������� �� ���� ��������, �������!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("���� ���, ������� ���������...", 
					"�����-�����, �� ��������. �����.",
					"�� ����, � ��� ����...", 
					"���?!", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "fight", npchar, Dialog.CurrentNode);
			break;
			}
			
			//--> �������� ��������� - ������� ������ �������������
			if (sti(pchar.reputation.nobility) < 10)
			{
				dialog.text = NPCStringReactionRepeat("�� ���� ��! � ��� ������ ������ ��������� ����� ��������� ����������� �� ������ ������? ����������...", 
					"������������, � �� ����� ���� ������������� � ����! ���������...", 
					"��� ���� ��������� ���� �������� �����. ����� - ����� �� ����.",
					"��, � ���� ������������. ������ �� ����������� �� ���� ��������, �������!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��-��, ������, ���������� ������ ��������!", 
					"�� ���� ��������, �������...",
					"�� ����...", 
					"���?!", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "fight", npchar, Dialog.CurrentNode);
			break;
			}
			
			//--> ������ ������ �������
            if(NPChar.quest.meeting == "0")
			{
				// �������� ������� ������� � �����
				bool ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
				if (ok && sti(Pchar.Ship.Type) != SHIP_NOTUSED && CheckAttribute(npchar, "quest.passenger") && !CheckAttribute(pchar, "GenQuest.Noblepassenger") && 4-sti(RealShips[sti(Pchar.Ship.Type)].Class) > 0)//��������-��������
				{
					dialog.text = "�����������, "+GetAddress_Form(NPChar)+". ����, �� ������� ��������� �������. � ���� ����� � ��� �������, ��� ����������� - ��� ��� ������...";
					link.l1 = "������ ���, "+GetAddress_FormToNPC(NPChar)+". � ��� ������ ����?";
					link.l1.go = "passenger";
					link.l2 = "��������, "+GetAddress_FormToNPC(NPChar)+", �� � ����� �����.";
					link.l2.go = "exit";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}
				if (CheckAttribute(npchar, "quest.donation"))//������� ������
				{
					dialog.text = "�-�, ��� ������ ���������� �������� � ����� ����������! �������, �� �� ��� ����� �� ������. ����������, � ���� ��������� ��� � ������, ��� �������� ���������. �������, �� ������� ���� ���������.";
					link.l1 = "������������, ������. � ��� ����������� ������.";
					link.l1.go = "donation";
					npchar.quest.meeting = "1";
					break;
				}
				if (CheckAttribute(npchar, "quest.lombard") && !CheckAttribute(pchar, "GenQuest.Noblelombard"))//�������� ��������
				{
					dialog.text = "������ ����, "+GetAddress_Form(NPChar)+"! ������� ��������� ������������� ����������� �������� �� ������ ������ ������! ��������� ������ ��������� ����� ������ ������������ �������?";
					link.l1 = "�������, ������. ����������� ��� ������.";
					link.l1.go = "lombard";
					npchar.quest.meeting = "1";
					break;
				}
				if (CheckAttribute(npchar, "quest.slaves") && !CheckAttribute(Colonies[FindColony(npchar.city)], "questslaves"))//�������� �����
				{
					dialog.text = "�����������, �������! ��� ��� ������, ������ ��� �� ��������� ���������, ������� � ��������� ������ ��� � ����� �������.";
					link.l1 = "����� ���������. � � ��� �� ����� ����������� ��� ������, "+GetAddress_FormToNPC(NPChar)+"?";
					link.l1.go = "slaves";
					npchar.quest.meeting = "1";
					break;
				}
				dialog.text = RandPhraseSimple("������������, "+GetAddress_Form(NPChar)+". �� ���-�� �� ���� ������?", "��� ��� ������, ������?");
				link.l1 = TimeGreeting()+", "+GetAddress_FormToNPC(NPChar)+". � �� ������� ��� �������, ������ ���� �������� � ���...";
				link.l1.go = "question";
				link.l2 = RandPhraseSimple("��� ����� ���������� � ����� � ����� �������.", "��� ����� ����������.");
				link.l2.go = "quests";//(���������� � ���� ������)
				npchar.quest.meeting = "1";
			}
			else //--> ��������� ���������
			{
				dialog.text = NPCStringReactionRepeat("���? �����? ��� � ���� �� ��� �������. ������� ��� �������� ����-������ �������. ��� ����� ������������, ����������� �� ������. � ��� ���� - ������� ����� � �����������, ���� ����������...", 
				"���, ��� ��� �������� ������������� ��������! �� ���, �� ��������� � ������� ����? �� �������?", 
					"������, � ������� ����������� ��, ��� �� �� ������, � ��������� ������ � ���. ������������: �� ������ �� �����!",
					"���, �� ���. ������ � ������ ����, ������!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������. ����� �������.", 
					"��-��, � �����, ������ ����� �������� ��� ���...",
					"�� ���� ����������� ������...", 
					"���?!", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "fight", npchar, Dialog.CurrentNode);
			}
			NextDiag.TempNode = "First time";
		break;

		case "question":
			dialog.text = LinkRandPhrase("����� ������������.","��, �� ������. ��� �� ������?","������� �������� �����? �����, �����, ������.");
			link.l1 = LinkRandPhrase("�� ���������� ��������� ������� ������ ������?","���������� ����������, ��� ����������� � ��������� ����� ���������?","��� ����������� �������� �� ����������, ������, �� �� � �����?");
			link.l1.go = "rumours_nobleman";
			NextDiag.TempNode = "First time";
		break;

//--------------------------------------------��������-��������---------------------------------------------------
		case "passenger":
			if (drand(19) > 9) SetPassengerParameter("Noblepassenger", false);
			else SetPassengerParameter("Noblepassenger", true);
			dialog.text = "������, ��� ������ ����� ��������� �� ������� " + XI_ConvertString("Colony"+pchar.GenQuest.Noblepassenger.City)+", ��� �� "+XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Noblepassenger.City)+"Dat")+", �� "+FindRussianDaysString(sti(pchar.GenQuest.Noblepassenger.DaysQty))+". ���� ����� �������� ������ ��������, � ������� �� ����������� ����������� � ��� �������. � ����� �������� �� ��� ����������� "+FindRussianMoneyString(sti(pchar.GenQuest.Noblepassenger.Money))+". ��� �������?";
			link.l1 = "��. ��� � ���� �� ����, ��� ��� � ����� ����� ��� �� ���� �� ���� ��������.";
			link.l1.go = "passenger_1";
			link.l2 = "�������, "+GetAddress_FormToNPC(NPChar)+", �� ��� ������ � ������ �������. ����� �� ���� ������.";
			link.l2.go = "passenger_exit";
		break;
		
		case "passenger_exit":
			dialog.text = "����. �� ��� ��, ������� ������� �������. ��������!";
			link.l1 = "����� �������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "GenQuest.Noblepassenger");
		break;
		
		case "passenger_1":
			dialog.text = "����� ������, � �� � ��� ����� �����. ������ �������� �� �������� �� �����.";
			link.l1 = "������������� �� ��� �����, "+GetAddress_FormToNPC(NPChar)+". �� ����� ����������.";
			link.l1.go = "passenger_2";
		break;
		
		case "passenger_2":
			DialogExit();
			pchar.GenQuest.Noblepassenger.id = npchar.id;
			LAi_SetImmortal(npchar, true);
			DeleteAttribute(npchar, "LifeDay");
			LAi_RemoveLoginTime(npchar);
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "1");
			AddQuestUserDataForTitle(sTitle, "sType", "���������");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			sTemp = XI_ConvertString("Colony" +pchar.GenQuest.Noblepassenger.City+"Gen") + ", ��� �� " + XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Noblepassenger.City)+"Dat")+".";
			AddQuestUserDataForTitle(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sDays", FindRussianDaysString(sti(pchar.GenQuest.Noblepassenger.DaysQty)));
            AddQuestUserData(sTitle, "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Noblepassenger.Money)));
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			pchar.quest.Noblepassenger.win_condition.l1 = "location";
			pchar.quest.Noblepassenger.win_condition.l1.location = pchar.GenQuest.Noblepassenger.City+"_town";
			pchar.quest.Noblepassenger.function = "Noblepassenger_complete";
			SetFunctionTimerCondition("Noblepassenger_Over", 0, 0, sti(pchar.GenQuest.Noblepassenger.DaysQty), false);
		break;
		
		case "passenger_3":
			pchar.quest.Noblepassenger_Over.over = "yes"; //����� ������
			dialog.text = "��� �� � �� �����, ������������! ����������� �� ����� ������� ���� ������ � ������ ��������. ���������. ��� ���� ������, ������.";
			link.l1 = "�����, "+GetAddress_FormToNPC(NPChar)+"! ����� �������.";
			link.l1.go = "passenger_4";
		break;
		
		case "passenger_4":
			chrDisableReloadToLocation = false;//������� �������
			DialogExit();
			npchar.lifeday = 0;
			RemovePassenger(Pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Noblepassenger.Money));
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
			OfficersReaction("good");				
			AddCharacterExpToSkill(pchar, "Sailing", 80);
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			if (CheckAttribute(pchar, "GenQuest.Noblepassenger.Enemycity")) AddCharacterExpToSkill(pchar, "Sneak", 50);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "3");
			CloseQuestHeader(sTitle);
			DeleteAttribute(Pchar, "GenQuest.Noblepassenger");
		break;
//<-- ��������-��������

//-------------------------------------------------������ ��������------------------------------------------------
		case "donation":
			sTemp = DonationText();
			dialog.text = "��� ����� ����, ����� ����������... "+sTemp+" ������ ����� ��� ������, ����� ������, ����� - ����������. � �� ������� �� �������� ���� ���������� � ��� � ����� ��������, ���� �� �� ������� ��������.";
			link.l1 = "������� ��������� ����� ��� �����?";
			link.l1.go = "donation_1";
		break;
		
		case "donation_1":
			iTemp = drand(4)+1;
			pchar.GenQuest.Nobledonation.Money = iTemp*1000+rand(iTemp)*150;
			dialog.text = "����� ���������, ����� "+FindRussianMoneyString(sti(pchar.GenQuest.Nobledonation.Money))+". �� ���, ��������?";
			if (sti(pchar.money) >= sti(pchar.GenQuest.Nobledonation.Money))
			{
				link.l1 = "�� ��� �������. ���, �������.";
				link.l1.go = "donation_2";
			}
			link.l2 = "� �� �����, �� � ��� ������ �� ����, ��� �� ���� ������� � �������.";
			link.l2.go = "donation_exit";
		break;
		
		case "donation_exit":
			DialogExit();
			ChangeOfficersLoyality("bad_all", 1);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "GenQuest.Nobledonation");
		break;
		
		case "donation_2":
			AddMoneyToCharacter(pchar, -sti(pchar.GenQuest.Nobledonation.Money));
			dialog.text = "�������� ��������� ���, "+GetAddress_Form(NPChar)+"! �� ���� ������ ������! � ���� ���� ������ � �������������� ������, � � ��� ������ ����������� ������� � ����� ������������. ��� ��� ������� �������!";
			link.l1 = "�� �� �� ���, ������. ������, �� �� �� ���� ����� ��������� ����� ��� ��.";
			link.l1.go = "donation_3";
		break;
		
		case "donation_3":
			DialogExit();
			ChangeOfficersLoyality("good_all", rand(2)+1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), rand(1)+2);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "GenQuest.Nobledonation");
		break;
//<-- ������ ��������

//-------------------------------------------------�������� ��������---------------------------------------------
		case "lombard":
			LombardText();
			dialog.text = "� ���� ��������� ��� � ������. ��� ������� �� ������, � ������������ �������������, �����, �� ���� ��������� �������. ��������� ����� ����� � ���� �������� ������ ����������� � �������, � � ��� �������� �������� � ������ ���������� "+pchar.GenQuest.Noblelombard.Item+"\n�� ����������� �������� ������� - ����� ������ ��������� ����������, �� ��� ������. ������ ����� �������, � � ���� ����� �������� ����������� ������������� ��� � �� ��������� ������ �� �����\n������ �� �������, ��� �� "+pchar.GenQuest.Noblelombard.Item+" �������� ����������, � �� ������� ��� ����, ���� � ���������� �� ������ �������� �� ����� � ��� ����. ������ � ���� ������ ��� ����������� �����, ��� �������� - ���� �������...";
			link.l1 = "� ��� �� � ���� ������ ��� � ���� ��������, "+GetAddress_FormToNPC(NPChar)+"?";
			link.l1.go = "lombard_1";
		break;
		
		case "lombard_1":
			dialog.text = "� ����� ��� - ���������� � ����� �����������. �������� ��� �����, ����������, �����, ��� ���. � ���������, ��� �� � ���� ���������� - � ���� ���� �������� '��������' �� ����� �����. ����� ��� ������ "+pchar.GenQuest.Noblelombard.Text+", � � ������� ��� ���� ������� � ����������� �������. ����� �����!";
			link.l1 = "�� ������, �������� ��� ������, ��� ����� ����.";
			link.l1.go = "lombard_2";
			link.l2 = "� ���������, � ������ ���� �� ����. ��� ��� ����� �� ���� ������, ���!";
			link.l2.go = "lombard_exit";
		break;
		
		case "lombard_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "GenQuest.Noblelombard");
		break;
		
		case "lombard_2":
			dialog.text = "������� �� ���������. � ���� ����� ��� � �������. ��������� ������!";
			link.l1 = "...";
			link.l1.go = "lombard_3";
		break;
		
		case "lombard_3":
			DialogExit();
			pchar.GenQuest.Noblelombard = "true"
			pchar.GenQuest.Noblelombard.Name = GetFullName(npchar);
			pchar.GenQuest.Noblelombard.id = npchar.id;
			pchar.GenQuest.Noblelombard.City = npchar.city;
			pchar.GenQuest.Noblelombard.Money = 20000+drand(60)*500;
			pchar.GenQuest.Noblelombard.Percent = makeint(sti(pchar.GenQuest.Noblelombard.Money)*0.3);
			pchar.GenQuest.Noblelombard.Summ = sti(pchar.GenQuest.Noblelombard.Money)+sti(pchar.GenQuest.Noblelombard.Percent);
			pchar.GenQuest.Noblelombard.Chance = drand(9);
			chrDisableReloadToLocation = true;//������� �������
			LAi_SetActorType(npchar);
			LAi_RemoveLoginTime(npchar);
			DeleteAttribute(npchar, "CityType");//������� ������� �������
			FreeSitLocator(pchar.GenQuest.Noblelombard.City + "_tavern", "sit1");
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", pchar.GenQuest.Noblelombard.City+"_tavern", "sit", "sit1", "Nobleman_lombardTavern", 10);
			SetFunctionTimerCondition("Noblelombard_Over", 0, 0, 1, false); //������ �� ����� �����
			ReOpenQuestHeader("Noblelombard");
			AddQuestRecord("Noblelombard", "1");
			AddQuestUserData("Noblelombard", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Noblelombard.City));
			AddQuestUserData("Noblelombard", "sName", pchar.GenQuest.Noblelombard.Name);
		break;
		
		case "lombard_4":
			if (CheckAttribute(pchar, "GenQuest.Noblelombard.Regard"))
			{
				pchar.quest.Noblelombard_Over.over = "yes"; //����� ������
				dialog.text = "��� �������, "+GetAddress_Form(NPChar)+"? �� ���� � ����������? ������� ���� ����������, ��� ���?";
				if (pchar.GenQuest.Noblelombard == "full") link.l1 = "��, ���. � ������� �������� �� ��� ������ � ��������� ������ ��������. ������ ���� � �������� ���.";
				if (pchar.GenQuest.Noblelombard == "maxpercent") link.l1 = "��, ���. � ������� �������� �� �������� ��� ������, � ������� �� ��������� ���. ��� ��� ������ �������� ����� �����. ������� - �� �����, ��� ����� ��� ������, �������� ����� ��������� �����.";
				if (pchar.GenQuest.Noblelombard == "minpercent") link.l1 = "��, ���. � ������� �������� �� �������� ��� ������. ��������� �������� ��������� ��� ���, ���� �� �������� ������ �����.";
				link.l1.go = "lombard_5";
			break;
			}
			if (pchar.GenQuest.Noblelombard == "fail")
			{
				dialog.text = "��� �������, "+GetAddress_Form(NPChar)+"? �� ���� � ����������? ������� ���� ����������, ��� ���?";
				link.l1 = "��, ���. ���� ������ ������� ������ ����������� �����! �� ������� �� ����� �� ����������, � ��������� ����� � ���� ���. ��� ��� � ����� �� ���� ��� ������, ���!";
				link.l1.go = "lombard_fail";
			}
			else
			{
				dialog.text = "��� �������, "+GetAddress_Form(NPChar)+"? �� ���� � ����������? ������� ���� ����������, ��� ���?";
				link.l1 = "� ��� ������� ��� ����, �����.";
				link.l1.go = "exit";
				NextDiag.TempNode = "lombard_4";
			}
		break;
		
		case "lombard_fail":
			pchar.quest.Noblelombard_Over.over = "yes"; //����� ������
			dialog.text = "��, "+GetAddress_Form(NPChar)+"... ��� �� � ��������� ���������� �������� �������� ���� ��������� ���������-�����������. ������� �� ����, ����� ������ ���������� � ��� ������, �� ����������, ��� �. ������� ��� �� �������, ��� ���� �� �����������...";
			link.l1 = "������� �� ����� �����������. ��, �������, ��� �� �����? ��� ����, ��� ��� �����, "+GetAddress_FormToNPC(NPChar)+". ��������.";
			link.l1.go = "lombard_fail_1";
		break;
		
		case "lombard_fail_1":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Noblelombard", "4");
			AddQuestUserData("Noblelombard", "sName", pchar.GenQuest.Noblelombard.Name);
			CloseQuestHeader("Noblelombard");
			sld = characterFromId(pchar.GenQuest.Noblelombard.City+"_usurer");
			DeleteAttribute(sld, "quest.noblelombard");
			DeleteAttribute(Pchar, "GenQuest.Noblelombard");
		break;
		
		case "lombard_5":
			dialog.text = "����������! �� ���� ������ ������, "+GetAddress_Form(NPChar)+"! ������� ����� �� ������. ������ ���� ������� - ���� ������� ����� ��������������, ��� � � ������ - � ����������� �������. ����� ��� ������ ������� � ������ ���������� - � ������ � ���� ������� �� ���� ��� - � �������� ���� ������.";
			link.l1 = "������, ��� � ��������. ����� �������!";
			link.l1.go = "lombard_6";
		break;
		
		case "lombard_6":
			dialog.text = "��� ��� ������� �������, �������! �����!";
			link.l1 = "...";
			link.l1.go = "lombard_7";
		break;
		
		case "lombard_7":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			ChangeCharacterComplexReputation(pchar, "authority", 2);
			ChangeOfficersLoyality("good_all", 1);
			AddQuestRecord("Noblelombard", "5");
			AddQuestUserData("Noblelombard", "sName", pchar.GenQuest.Noblelombard.Name);
			SetFunctionTimerCondition("Noblelombard_Regard", 0, 0, 90, false); //������
		break;
//<-- �������� ��������

//------------------------------------------�������� ����� ��� �����--------------------------------------------
		case "slaves":
			npchar.quest.slaves.price = 3+drand(1);//���� �� ����� � ��������
			npchar.quest.slaves.qty = 50+drand(5)*10;//����������
			npchar.quest.slaves.money = sti(npchar.quest.slaves.qty)*sti(npchar.quest.slaves.price);
			dialog.text = "��� ��� ������ �� "+LinkRandPhrase("���� ��������","���� �������","���� ���������")+" ��������� ��������� ����. � ������ ������ ��� ����������� ���������� "+sti(npchar.quest.slaves.qty)+" �������. � ���� �������� � ��� ��� ������ �����. ����� � �����, �������, �� "+sti(npchar.quest.slaves.price)+" ������� �� ������\n������ ������ ���, ��� ��� � ������ � ��� ������ �� �����������. ��, �������, ���� �� �� ��������� ��� ������, ��� �� �������. �� ���, �� �����?";
			link.l1 = "�� �����! ���� ���������, �� ��� ���� �����.";
			link.l1.go = "slaves_1";
			link.l2 = "��������, �� ������������� � �� ���������. �� ��� �������.";
			link.l2.go = "exit_slaves";
		break;
		
		case "exit_slaves":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
		break;
		
		case "slaves_1":
			dialog.text = "����� ������. ���� ����� ��� � �������. ����� ���� �� ������� � ��������� ������ ��������� � ����������� �� ���� ���. � ��������� ����� � ��� � ���������, ��� �����.";
			link.l1 = "������. � ����� ��� � ��������. �� �������, "+GetAddress_FormToNPC(NPChar)+".";
			link.l1.go = "slaves_2";
		break;
		
		case "slaves_2":
			DialogExit();
			sGlobalTemp = npchar.id;
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			SaveCurrentNpcQuestDateParam(npchar, "slaves_date");//���������� ����
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", npchar.city+"_church", "sit", "sit"+(1+rand(5)), "Nobleslaves_Place", 10.0);
			chrDisableReloadToLocation = true;//������� �������
			Colonies[FindColony(npchar.city)].questslaves = true;
			sTitle = npchar.city+"Nobleslaves";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "Nobleslaves", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sQty", sti(npchar.quest.slaves.qty));
			AddQuestUserData(sTitle, "sMoney", sti(npchar.quest.slaves.money));
		break;
		
		case "slaves_3":
			if (GetNpcQuestPastDayParam(npchar, "slaves_date") < 180)
			{
				dialog.text = "�� �������� ��� "+sti(npchar.quest.slaves.qty)+" �����, ��� � ��� ������, �������?";
				if (GetSquadronGoods(pchar, GOOD_SLAVES) >= sti(npchar.quest.slaves.qty))
				{
					link.l1 = "��. ��� ������ ��������� � ���� � �����. � ����� �������� �� ���.";
					link.l1.go = "slaves_4";
				}
				else
				{
					link.l1 = "���. � ��� ������� ��� ���� ��������.";
					link.l1.go = "exit";
					NextDiag.TempNode = "slaves_3";
				}
			}
			else
			{
				dialog.text = "�������, ���� �� �� ������ ����� - �� � ��� �������� ����������� ���������� � ���� ������ � ��� �� ��������. �� ����� ����� �� ��� �� �����.";
				link.l1 = "��, ����! �� �� ����� - ������� � � ���� �����. �� ��������!";
				link.l1.go = "slaves_8";
			}
		break;
		
		case "slaves_4":
			dialog.text = "�����������! � ���������� ����������� �������� �� ���� �����.";
			link.l1 = "��� ��� ������ ���� ������?";
			link.l1.go = "slaves_5";
		break;
		
		case "slaves_5":
			dialog.text = "�� ������������, � �� ����� �� ����. ���, ������� ����������� ����� - �� "+sti(npchar.quest.slaves.price)+" ������� �� ����.";
			link.l1 = "���������, ������. � ���� ������� ����� ����!";
			link.l1.go = "slaves_6";
		break;
		
		case "slaves_6":
			RemoveCharacterGoods(pchar, GOOD_SLAVES, sti(npchar.quest.slaves.qty));
			TakeNItems(pchar, "gold_dublon", sti(npchar.quest.slaves.money));
			Log_Info("�� �������� "+FindRussianDublonString(sti(npchar.quest.slaves.money))+"");
			PlaySound("interface\important_item.wav");
			dialog.text = "��� ��... � ������ ����� ���� �������� - ���� ����. ����� �������!";
			link.l1 = "�� ��������, "+GetAddress_FormToNPC(NPChar)+".";
			link.l1.go = "slaves_7";
		break;
		
		case "slaves_7":
			DialogExit();
			npchar.lifeday = 0;
			DeleteAttribute(Colonies[FindColony(npchar.city)], "questslaves");
			LAi_SetActorType(npchar);
			GetCharacterPos(pchar, &locx, &locy, &locz);
         	ChangeCharacterAddressGroup(npchar, npchar.city+"_church", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 10.0);
			AddCharacterExpToSkill(pchar, "Commerce", 150);//��������
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 30);//�������
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
			sTitle = npchar.city+"Nobleslaves";
			AddQuestRecordEx(sTitle, "Nobleslaves", "2");
			CloseQuestHeader(sTitle);
		break;

		case "slaves_8":
			DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
			DeleteAttribute(Colonies[FindColony(npchar.city)], "questslaves");
			sTitle = npchar.city+"Nobleslaves";
			AddQuestRecordEx(sTitle, "Nobleslaves", "3");
			CloseQuestHeader(sTitle);
		break;
//<-- �������� ����� ��� �����

		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_SetHP(NPChar, 400, 400);
			TakeNItems(NPChar, "potion2", 3);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_MoveCharacter(NPChar, "TempFight");
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
			ChangeCharacterNationReputation(pchar, sti(npchar.nation), -3);
		break;
	}
}

string DonationText()
{
	string sText;
	switch (drand(5))
	{
		case 0: sText = "� ����� ���������� � �����, � �� �������� ����� �� ������� ����� ���������. �� ������� ���� ��������?" break;
		case 1: sText = "� ����� ������� ����������� � �����... ������, � ������ ��� ���� �������� �������������. ��� ����� ��������� ��, �� � ����� � ��� � ��� ���������... �� ����� �� �� ��� ������ ��������� ������?" break;
		case 2: sText = "� ��� �� ���� �������� ������ ������ ������, ��� ������ ��������� ������� ����, ����� ������ ����. ��� �� ������� ������ �������. �����, ��������?" break;
		case 3: sText = "� ���� �������������� ��������� � �����, � �� ������ ����� ����� � ���� �������� �� ������� ���������� ������ �����. �� ��������?" break;
		case 4: sText = "���� ������� ����� � ���� ������������ � ��������� ������� � ����� �����... � �����, ��� �� ������� ��������� ��������� �������, ����� ������ ��� ��������." break;
		case 5: sText = "���� ������� ������ �� ����� ���� ������ ������ � ������� �� ��� ����������� �����. � ������ ���, ��� �����, �� �� ������� ������ �������. ��������?" break;
	}
	return sText;
}

void LombardText()
{
	switch (drand(5))
	{
		case 0:
			pchar.GenQuest.Noblelombard.Item = "�������� �������� ���� ������ ������ ����������� �������";
			pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("� ������ ������������� ��� ����������","�������� ��� ������� �� �������� � ������� ������, � ������ �����");
		break;
		case 1: pchar.GenQuest.Noblelombard.Item = "���������� ����� ���� ������ ������ ���������� �������";
				pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("� ������� � ����� ������������ ��������� � ������","�������� ��� ������� �� �������� � ������� �����, � ������ ���������");
		break;
		case 2:
			pchar.GenQuest.Noblelombard.Item = "��������� �������� � ������ ������ ����, ������������ �� ���� � ����";
			pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("�������� ��� ���������� �� ������ ����� � �������� ��������","� ������ ������������� ��� ����������");
		break;
		case 3:
			pchar.GenQuest.Noblelombard.Item = "������� ���� � �������� � ������������, ������� �� ������";
			pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("� ������ ���� ����� � ���������� �� ������������ �����","� ������ ������� �� ���������� ������ ����������");
		break;
		case 4:
			pchar.GenQuest.Noblelombard.Item = "�������� �� ������ � �����������, ������� ������, �������� ���� ����";
			pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("� ������ ������� �� ���������� ������ ����������","�������� ��� ������� �� �������� � ������� ������, � ������ �����");
		break;
		case 5:
			pchar.GenQuest.Noblelombard.Item = "������ �� �������� ����� � �����������, ������� ����� ����";
			pchar.GenQuest.Noblelombard.Text = RandPhraseSimple("�������� ��� ������� �� �������� � ������� �����, � ������ ���������","� ������ ���� ����� � ���������� �� ������������ �����");
		break;
	}
}