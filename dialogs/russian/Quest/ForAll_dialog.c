void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sGem, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "CitizenNotBlade":
			if(LoadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "��������� �� ���������, "+ GetSexPhrase("��������","�������") +", ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� "+ GetSexPhrase("�������","������ ���") +" ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����"+ GetSexPhrase("","�") +".", "������.");
			}
			
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//--------------------------- ����� ���������� --------------------------------
		//���������
		case "WaitressBerglar":
			dialog.text = "�����, ��������, ����������� �������.";
			link.l1 = "����?!";
			link.l1.go = "WaitressBerglar_1";
		break;
		case "WaitressBerglar_1":
			dialog.text = "����! ����� �������, ��� ����������. �� ����� � �����...";
			link.l1 = "��� ��� ��������!! � " + pchar.questTemp.different.FackWaitress.Name + " � ����� � ���� ��������, ��� ��?";
			link.l1.go = "WaitressBerglar_2";
		break;
		case "WaitressBerglar_2":
			dialog.text = "� ����, � ����... ����������� �������, �� �� ������ ����!";
			link.l1 = "����� � ���! �� ���� ������� � ��� ���� ������ ������...";
			link.l1.go = "WaitressBerglar_fight";
			link.l2 = "�������, ��������! �� ��� ��� ��� ������ � ��� �� ������...";
			link.l2.go = "WaitressBerglar_take";
		break;
		case "WaitressBerglar_take":
			dialog.text = "�������, �� ������, ��� �� ������? ��, ������ �������. � ����� - �� ����� �� ��������, ����� �� ���� ���������� � ���� ��������. ������ ������ �����!";
			link.l1 = "��� �����!..";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("WaitressFack_outRoom");
		break;
		case "WaitressBerglar_fight":
			dialog.text = "��, ��� ������...";
			link.l1 = "����, ����, ��������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("WaitressFack_fight");
		break;
		//����������
		case "Waitress":
			dialog.text = "� ��� � �! �� ����������, ���������?";
			link.l1 = "�� �����...";
			link.l1.go = "Waitress_1";
		break;
		case "Waitress_1":
			dialog.text = "��, ����� �� ����� ������ �������!";
			link.l1 = "��, ��������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("WaitressFack_fack");
		break;
		
		//--------------------------- ������� ����, ����������� ������� ������ --------------------------------
		//�������� � ������
		case "PortmansCap":
			dialog.text = "������������. ���� ����� " + GetFullName(npchar) + ". � ������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Acc")) + " '" + npchar.Ship.name + "'."; 
			link.l1 = "�������! �������-�� � ���� ���"+ GetSexPhrase("��","��") +"...";
			link.l1.go = "PortmansCap_1";
		break;
		case "PortmansCap_1":
			dialog.text = "���"+ GetSexPhrase("��","��") +"?!";
			link.l1 = "���. � �����, � ������"+ GetSexPhrase("","��") +" ���� ���� ������� ������. ������� �� ����� � ���������� ����� " + XI_ConvertString("Colony" + npchar.quest.firstCity + "Gen") + ".";
			link.l1.go = "PortmansCap_2";
		break;
		case "PortmansCap_2":
			dialog.text = "������, ��� ��� ��� � ��� ''������''! �� ��, ��� ������� ���� ���� �� ������� � ����� �� �������...";
			link.l1 = "��, ��� ������, ��� ������ ���������. ������� ���� ������ � ����� ��������� � ���� �������� �� �����.";
			link.l1.go = "PortmansCap_3";
		break;
		case "PortmansCap_3":
			if (sti(npchar.quest.stepsQty) == 1)
			{
				dialog.text = "����� ������ � ��� �� �����, ��� ��� ���������, ������� ������� �������� �� ����, ��� ���� ���� ���������. " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ������� ���� ������ ��������������.";
				link.l1 = "��, �������. ������� ���� ������.";
				link.l1.go = "PortmansCap_4";
			}
			else
			{
				if (sti(npchar.quest.stepsQty) < 5)
				{
					npchar.quest.money = makeint(sti(npchar.quest.money) / sti(npchar.quest.stepsQty)); //��������� ��������������
					dialog.text = "��, �� ������, � ��� ����� ����� ������. ��� �� �����, ������ ������ ��� ����� ���, ���������� ��� ��������� � �����. ��� ��� � ���� ������� ��� �� " + FindRussianMoneyString(sti(npchar.quest.money)) + ". � ������� ���� ������ ��������������.";
					link.l1 = "�� ��� ��, ������������. ������� ���� ������!";
					link.l1.go = "PortmansCap_4";
				}
				else
				{
					dialog.text = "��� � ����� ����� ������ ���. � ��� ������ ������� �� ������ ������� ����, ��� ��� ����� � �����. ��� ��� ��� ������ ������ ������ �������� �� �����. � ������ ��������� �� ���� � �� ����.";
					link.l1 = "������ ������? ��� �, ��� �� ����� �����"+ GetSexPhrase("��","���") +"?";
					link.l1.go = "PortmansCap_5";
				}
			}
		break;
		case "PortmansCap_4":
			dialog.text = "������� ����. ��, ����� ��������, "+ GetSexPhrase("��������","�������") +".";
			link.l1 = "� ���� ���� ��...";
			link.l1.go = "exit";
			sTemp = "Timer_" + npchar.id;
			pchar.quest.(sTemp).over = "yes"; //������� ������ �� ����� � ����
			npchar.LifeDay = 2; // ����� ���� ���� ������� ����
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");			
			group_DeleteGroup("PorpmansShip_" + npchar.index); //������ ������, �� ������ ������
			sld = characterFromId(npchar.quest.firstCity + "_PortMan");
			sTitle = sld.id + "PortmansBook_Delivery";
			AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "3");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.City + "Dat"));
			AddQuestUserData(sTitle, "sCity2", XI_ConvertString("Colony" + sld.city + "Gen"));
			CloseQuestHeader(sTitle);
			sGem = pchar.questTemp.PortmansJornal.gem;
			TakeNItems(pchar, sGem, 12+drand(10));
			DeleteAttribute(pchar, "questTemp.PortmansJornal.gem");
			DeleteAttribute(sld, "quest.PortmansJornal");
			sld.quest = ""; //����������� ������ ���� ������ ��� ��������
        	AddCharacterExpToSkill(pchar, "Repair", makeint(400/sti(npchar.quest.stepsQty)));
    		AddMoneyToCharacter(pchar, sti(npchar.quest.money));
    		ChangeCharacterComplexReputation(pchar,"nobility", 2);
			TakeItemFromCharacter(pchar, "PortmansBook");
			NextDiag.TempNode = "PortmansCap_inDeck_over";
		break;
		case "PortmansCap_5":
			dialog.text = "��, ���� �� ����"+ GetSexPhrase("��","���") +" ��������, �� ���� ���� �����������.";
			link.l1 = "��, ���� �����... �� �����, ������� ���� ������ ������ ���.";
			link.l1.go = "exit";
			sTemp = "Timer_" + npchar.id;
			pchar.quest.(sTemp).over = "yes"; //������� ������ �� ����� � ����
			npchar.LifeDay = 2; // ����� ���� ���� ������� ����
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");			
			group_DeleteGroup("PorpmansShip_" + npchar.index); //������ ������, �� ������ ������
			sld = characterFromId(npchar.quest.firstCity + "_PortMan");
			sTitle = sld.id + "PortmansBook_Delivery";
			AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "3");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.City + "Dat"));
			AddQuestUserData(sTitle, "sCity2", XI_ConvertString("Colony" + sld.city + "Gen"));
			CloseQuestHeader(sTitle);
			DeleteAttribute(sld, "quest.PortmansJornal");
			sld.quest = ""; //����������� ������ ���� ������ ��� ��������
        	AddCharacterExpToSkill(pchar, "Repair", makeint(200/sti(npchar.quest.stepsQty)));
			TakeItemFromCharacter(pchar, "PortmansBook");
			NextDiag.TempNode = "PortmansCap_inDeck_over";
		break;
		//������ � ����
		case "PortmansCap_inDeck":
			if (isBadReputation(pchar, 20))
			{
				dialog.text = "����������� ���� �� ������ ����� �����. ������ ������, � ��, ����, ��������� - �����, ��� ��� ���������� ���� ������ ����� ����������� �� ����...";
				link.l1 = "�� ���, ��������, ������� � ����"+ GetSexPhrase("��","��") +". � ����������"+ GetSexPhrase("","�") +" ����, ����� ������.";
			}
			else
			{
				dialog.text = "����������� ���� �� ���� ������! ��� �� �����"+ GetSexPhrase("","�") +"?";
				link.l1 = "����������"+ GetSexPhrase("","�") +" ����, ��������. ��� ������"+ GetSexPhrase("","�") +"...";
			}
			link.l1.go = "PortmansCap_inDeck_1";
		break;
		case "PortmansCap_inDeck_1":
			dialog.text = "����������"+ GetSexPhrase("","�") +"? � �����?";
			link.l1 = "�� ����� ���� ������� ������ � ���������� ����� " + XI_ConvertString("Colony" + npchar.quest.firstCity + "Gen") + ". ������ � ����! ������� � ����������"+ GetSexPhrase("","�") +", ����� ������.";
			link.l1.go = "PortmansCap_inDeck_2";
		break;
		case "PortmansCap_inDeck_2":
			if (sti(npchar.quest.stepsQty) == 1)
			{
				dialog.text = "����, ���, ������, ��� ��� � ��� �������!.. ��� ������ ������, "+ GetSexPhrase("�������, ","") +"��� ����. � �� � ���� ������������ ������� �� �������... ������� ���� �������.";
				link.l1 = "��� ������ ��������������?";
				link.l1.go = "PortmansCap_inDeck_3";
			}
			else
			{
				if (sti(npchar.quest.stepsQty) < 5)
				{
					npchar.quest.money = makeint(sti(npchar.quest.money) / sti(npchar.quest.stepsQty)); //��������� ��������������
					dialog.text = "����, ���, ������, ��� ��� � ��� �������!.. ������� ����, �������, �� ���� � ���, ��� �� ����� ���� �����"+ GetSexPhrase("","�") +", � � ��� ����� �����. ������, ��������� ���-��� ��� ������ �����, ������� � ������ ������ � ����. �� ����� ��������� �� ����...";
					link.l1 = "� ������� ������?";
					link.l1.go = "PortmansCap_inDeck_3";
				}
				else
				{
					dialog.text = "����, ���, ������, ��� ��� � ��� �������!.. ������� ����, �������, �� ���� � ���, ��� �� ����� ���� �����"+ GetSexPhrase("","�") +", � � ��� ����� �����. ������ ������ ������� �� ������, ��� ��� ��� �� �� �����.";
					link.l1 = "���, ������ ���� ������ ������ �� �����? ������?";
					link.l1.go = "PortmansCap_inDeck_5";
				}
			}
		break;
		case "PortmansCap_inDeck_3":
			dialog.text = "� ����� ��������� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ���� �������� ������� ����� ������ ��������������. ��� ���, ��� � ���� ���� ���������.";
			link.l1 = "��, ������. ��� ���� ������.";
			link.l1.go = "PortmansCap_inDeck_4";
		break;
		case "PortmansCap_inDeck_4":
			dialog.text = "������� ��� ���. ������, "+ GetSexPhrase("�������, ","") +"� ���� ������"+ GetSexPhrase("","�") +".";
			link.l1 = "� ���� ��������.";
			link.l1.go = "exit";
			npchar.LifeDay = 30; // ����� ������ ���� ������� ����
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");	
			npchar.quest = "over"; //���� ���� ����� ��������. �������� �������� �� ���������� � ��������
			sld = characterFromId(npchar.quest.firstCity + "_PortMan");
			sTitle = sld.id + "PortmansBook_Delivery";
			AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "2");
			AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + npchar.quest.targetCity + "Acc"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + sld.city + "Gen"));
			CloseQuestHeader(sTitle);
			sGem = pchar.questTemp.PortmansJornal.gem;
			TakeNItems(pchar, sGem, 12+drand(10));
			DeleteAttribute(pchar, "questTemp.PortmansJornal.gem");
			DeleteAttribute(sld, "quest.PortmansJornal");
			sld.quest = ""; //����������� ������ ���� ������ ��� ��������
        	AddCharacterExpToSkill(pchar, "Sailing", makeint(200/sti(npchar.quest.stepsQty)));
    		AddMoneyToCharacter(pchar, sti(npchar.quest.money));
    		ChangeCharacterComplexReputation(pchar,"nobility", 5);
			TakeItemFromCharacter(pchar, "PortmansBook");
			npchar.DeckDialogNode = "PortmansCap_inDeck_over";
			NextDiag.TempNode = "PortmansCap_inDeck_over";
		break;
		case "PortmansCap_inDeck_5":
			dialog.text = "���������"+ GetSexPhrase(", �������","") +". �� ������� ����� ���� �����"+ GetSexPhrase("","�") +", ����� ���� ������������.";
			link.l1 = "���, ����� ���� �� ������ �������, ����� � � �� �� �����"+ GetSexPhrase("��","���") +" ��� �����. �� �� �����, ������� ���� ������ �����, ��� �� ���� �� �����.";
			link.l1.go = "exit";
			npchar.LifeDay = 30; // ����� ������ ���� ������� ����
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");	
			npchar.quest = "over"; //���� ���� ����� ��������. �������� �������� �� ���������� � ��������
			sld = characterFromId(npchar.quest.firstCity + "_PortMan");
			sTitle = sld.id + "PortmansBook_Delivery";
			AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "2");
			AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + npchar.quest.targetCity + "Acc"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + sld.city + "Gen"));
			CloseQuestHeader(sTitle);
			DeleteAttribute(sld, "quest.PortmansJornal");
			sld.quest = ""; //����������� ������ ���� ������ ��� ��������
        	AddCharacterExpToSkill(pchar, "Sailing", makeint(100/sti(npchar.quest.stepsQty)));
			TakeItemFromCharacter(pchar, "PortmansBook");
			npchar.DeckDialogNode = "PortmansCap_inDeck_over";
			NextDiag.TempNode = "PortmansCap_inDeck_over";
		break;
		case "PortmansCap_inDeck_over":
			dialog.text = "�����, ��� ������ ���.";
			link.l1 = "��, ��� �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PortmansCap_inDeck_over";
		break;
		//--------------------------- ������ ����������� ������� --------------------------------
		case "SeekCap_inDeck":
			dialog.text = "�����������. ��� ���� ����� � ���� �� �������?";
			link.l1 = "�� ���, ��������� ���������� �����"+ GetSexPhrase("","�") +". �����, ��� ��������� � ����...";
			link.l1.go = "SeekCap_inDeck_1";
		break;
		case "SeekCap_inDeck_1":
			dialog.text = "������ �� ���������, � �������� � ���� ���. � ������, ������ ������, ���� ����������� � ���� �� ������ ������������. �������, ���� ���������?";
			link.l1 = "�� ���� �� �����... �� �����, �����, �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "SeekCap_inDeck_over";
			sld = characterFromId(npchar.quest.cribCity + "_PortMan");
			sTitle = sld.id + "Portmans_SeekShip";
			AddQuestRecordEx(sTitle, "Portmans_SeekShip", "4");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.quest.cribCity + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName)));
		break;
		case "SeekCap_inDeck_over":
			dialog.text = "������ ��, ��� ���� ��� ������ ������!";
			link.l1 = "�������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "SeekCap_inDeck_over";
		break;
		//�������
		case "SeekCap":
			dialog.text = "����� �� �����"+ GetSexPhrase("","�") +" �� ���?!!";
			link.l1 = "� ����"+ GetSexPhrase("��","��") +" ������� ������� ��� ���������.";
			link.l1.go = "SeekCap_1";
		break;
		case "SeekCap_1":
			dialog.text = "������ ���������?! � � ���� ��������!";
			link.l1 = "���, ��� �� ���. ��� ������� �������� - � � ���"+ GetSexPhrase("","�") +" �� ����, �� � ����, ��� ������� ������� �� ������� ������ �� ������. � ����"+ GetSexPhrase("��","��") +" ��� ������� �� �����.";
			link.l1.go = "SeekCap_2";
		break;
		case "SeekCap_2":
			dialog.text = "������! ��, ��� ���� ��� �� ��� ��������. � ���-���� ��������� ��������� ���� �� ��� ����...";
			link.l1 = "��, ���������...";
			link.l1.go = "SeekCap_3";
		break;
		case "SeekCap_3":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogExitWithBattle(""); 
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------��������� ��������� �������--------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		case "SCQ_exit":
			DialogExit();
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "SCQ_exit_clear":
			sld = characterFromId(npchar.quest.SeekCap.capId); //�������	
			sld.lifeDay = 0;
			Map_ReleaseQuestEncounter(sld.id);
			string sGroup = "SeekCapShip_" + sld.index;
			group_DeleteGroup(sGroup);
			sTemp = "SCQ_" + sld.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ������������
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
            DialogExit();
		break;
		
//--------------------------------------------��������� ������ ������---------------------------------------------
		
		case "SCQ_Nobleman":
			dialog.text = "������������, "+GetAddress_Form(NPChar)+". ��� � ����, �� ������� ������������ �������. ���� ����� "+GetFullName(npchar)+", � � ���� ���������� ��� ���� ����.";
			link.l1 = RandPhraseSimple("����� ���� ��������, �� � ����� �����.", "��������, �� � ������ ������ � ���� ��� ����������� ��� ���������.");
			link.l1.go = "SCQ_exit";
			link.l2 = "����������� ��� ������, ������.";
			link.l2.go = "SCQ_Nobleman_1";
		break;

		case "SCQ_Nobleman_1":
			switch (sti(npchar.quest.SeekCap.numQuest))
			{
				case 0: //������� �
					if (sti(pchar.reputation.nobility) < 35)
					{
						dialog.text = "���� ��� � ���. "+SelectNB_battleText()+"\n� ���� ��� �� �������, �� ����������� ��������� ��� � �������� ���� ��� �� ����������, � � ����� ������� ��, �������, �� ������������. ��, ��������, ��� �������������, ��� � ���� ��� ����������?";
						link.l1 = LinkRandPhrase("��������, ����� ����� �������� � ��������� ��� � ���?","��������, ��������� ������� � �������� � ���?","�����, ���� ������ � ������� � �������� � ��� ����� ��������?");
						link.l1.go = "SCQ_NM_battle";
					}
					else //������� �
					{
						SelectNB_prisonerText(npchar);
						dialog.text = "���� ��� � ���. "+npchar.quest.text+"\n� ���� ��� �� �������, �� ����������� ��������� ��� � �������� ���� ��� �� ����������, � � ����� ������� ��, �������, �� ������������. ��, ��������, ��� �������������, ��� � ���� ��� ����������?";
						link.l1 = LinkRandPhrase("��������, ����� ����� �������� � ��������� ��� � ���?","��������, ��������� ������� � �������� � ���?","�����, ���� ������ � ������� � �������� � ��� ����� ��������?");
						link.l1.go = "SCQ_NM_prisoner"
					}
		break;
				
				case 1: //������� �
					SelectNB_peaceText(npchar);
					dialog.text = "���� ��� � ���. �����������, "+npchar.quest.text+", ������ ������ � ����� ������� �����, �� ������� �������. � ���� �� �����, ��� � ���� ���� �� �������!\n� �� ����� ����� � ��� ����������, �� � ���� ��� �� �������, �� ����������� ��������� ��� � �������� ���� ��� �� ����������...";
					link.l1 = "� ��� �������, ��� �� ������, ����� � �������� ����� �������� � ������� ��� � ���?";
					link.l1.go = "SCQ_NM_peace";
				break;
			}
		break;
		
		case "SCQ_NM_battle": //������� �
			dialog.text = "�� ������ ���. �����, �� �� ��� ���������� �� �����. ������ ������ ��� � ���� ���. ������� ������ � ��� ������� ��������, ����������, �������� ������ - ��� ��������� ��� �����, ���� �� ��� ������� ��������� ���������� ��� ����� ������������. ������� ����� ������.";
			link.l1 = "��! ��, ��� ����� ��������. �������� ��� ��� ����� �������� � ������, �� ������� �� �����.";
			link.l1.go = "SCQ_NM_battle_1";
		break;
		
		case "SCQ_NM_battle_1":
			npchar.quest.SeekCap = "NM_battle"; //������ ���� �� �����
			SetSeekCapCitizenParam(npchar, rand(HOLLAND)); //����� ����� ����� �������
			dialog.text = "�������� ����� " + npchar.quest.SeekCap.capName + ". ����� �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Voc")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'. ������� ��� ������� � ����� ������ "+XI_ConvertString("Colony"+npchar.quest.Qcity)+". � ������� ��� �� ��� ������ "+FindRussianMoneyString(sti(npchar.quest.money))+" � ������� ��������.";
			link.l1 = "�������� ����� � �� �����. � ���� ����� ����������� �������� �� ��������. ��� ��� ��� ������ ������� ������ ������� - ��� �����.";
			link.l1.go = "SCQ_NM_battle_2";
			link.l2 = "����� ������������ ��� ����, ����� � ������� ����� �����.";
			link.l2.go = "SCQ_exit_clear";
		break;
		
		case "SCQ_NM_battle_2":
			dialog.text = "� ���, ��� �� ����� ����� ����. ���� ����� ������ �����������.";
			link.l1 = "��� ��� ����� ����� ����� �����? ������� ������� �����������, ����� � �� ������ ���� ����� ��� � �� ���� �������.";
			link.l1.go = "SCQ_NM_battle_3";
		break;
		
		case "SCQ_NM_battle_3":
			dialog.text = "������ ���� � ���� �� �������� ������. ��� ��� �� ������� ���� ����� � ����� ���� � ������ �� ������ ���� � ����� ������.";
			link.l1 = "������, ������������! �����, ��������� �� �������� ���� ����� �����.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "talker");
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetLoginTime(npchar, 8.0, 10.0);
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_NM_result";
			sTitle = npchar.city + "SCQ_NM_battle";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_NM_battle", "1");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sQCity", XI_ConvertString("Colony"+npchar.quest.Qcity));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Voc")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
		break;
		
		case "SCQ_NM_prisoner": //������� �
			dialog.text = "������ ���. ����� � �������� ��� �� ���, � ����� �� ���� ����� �� ���� � ��� ������ - � ��� ����� ���� �� ��������. ������� ����� ������.";
			link.l1 = "��, ���� �� �������� �������, �� ������� �� ������, ��� �������� ����� �������, �, �������, ��� ����� ������ ������� - �� � ���� ����������� ��������� ���.";
			link.l1.go = "SCQ_NM_prisoner_1";
		break;
		
		case "SCQ_NM_prisoner_1":
			npchar.quest.SeekCap = "NM_prisoner"; //������ ���� �� �����
			SetSeekCapCitizenParam(npchar, rand(HOLLAND)); //����� ����� ����� �������
			makearef(forName, npchar.quest.SeekCap);
			forName.nation = sti(npchar.nation);
			forName.sex = "man";
			forName.name = GenerateRandomName(sti(npchar.nation), "man");
			dialog.text = "������� ����� "+npchar.quest.SeekCap.name+". ������ �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName+"Voc")) + " � ��������� '" + npchar.quest.SeekCap.shipName + "', ��� ������� �������� �� ����� " + npchar.quest.SeekCap.capName + ". �� ��� ����� ���� ������� ������ � ����� ������ "+XI_ConvertString("Colony"+npchar.quest.Qcity)+". � ������� ��� �� ��� ������ "+FindRussianMoneyString(sti(npchar.quest.money))+" � ������� ��������.";
			link.l1 = "�������� ����� � �� �����. � ���� ����� ����������� �������� �� ��������. ��� ��� ��� ������ ������� ������ ������� - ��� �����.";
			link.l1.go = "SCQ_NM_prisoner_2";
			link.l2 = "����� ������������ ��� ����, ����� � ������� ����� �����.";
			link.l2.go = "SCQ_exit_clear";
		break;
		
		case "SCQ_NM_prisoner_2":
			dialog.text = "� ���, ��� �� ����� ����� ����. ���� ����� ������ �����������.";
			link.l1 = "��� ��� ����� ����� ����� �����? ������� ������� �����������, ����� � �� ������ ���� ����� ��� � �� ���� �������.";
			link.l1.go = "SCQ_NM_prisoner_3";
		break;
		
		case "SCQ_NM_prisoner_3":
			dialog.text = "������ ���� � ���� �� �������� ������. ��� ��� �� ������� ���� ����� � ����� ���� � ������ �� ������ ���� � ����� ������.";
			link.l1 = "������, ������������! �����, ��������� �� �������� ���� ����� �����.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "talker");
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetLoginTime(npchar, 8.0, 10.0);
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_NM_result";
			sTitle = npchar.city + "SCQ_NM_prisoner";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_NM_prisoner", "1");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sQCity", XI_ConvertString("Colony"+npchar.quest.Qcity));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Voc")));
			AddQuestUserData(sTitle, "sName1", npchar.quest.SeekCap.name);
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
		break;
		
		case "SCQ_NM_peace": //������� �
			dialog.text = "������! ������� ��� � ��������, ��� � ���� � ���� ������. ����� �� ��� ������ ����������� �������� ����. ��� ��� ����� �������! ���� �� �������� ��� - � �� ���������� �� ��������� �������.";
			link.l1 = "�� ��� ��... ���� ����������. �������� ��� ��� ����� �������� � �������, �� ������� �� ������.";
			link.l1.go = "SCQ_NM_peace_1";
		break;
		
		case "SCQ_NM_peace_1":
			npchar.quest.SeekCap = "NM_peace"; //������ ���� �� �����
			SetSeekCapCitizenParam(npchar, sti(npchar.nation)); //����� = ����� ������������
			dialog.text = "�������� ����� " + npchar.quest.SeekCap.capName + ". ������ �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Voc")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'. ������� ��� ������ � ����� ������ "+XI_ConvertString("Colony"+npchar.quest.Qcity)+". � ������� ��� �� ��� ������ "+FindRussianMoneyString(sti(npchar.quest.money))+" � ������� ��������.";
			link.l1 = "����� ������! �����, ��� ����� ��������� ������ ����� ���������� ������.";
			link.l1.go = "SCQ_NM_peace_2";
			link.l2 = "����� ������������ ��� ����, ����� � ������� ����� �����.";
			link.l2.go = "SCQ_exit_clear";
		break;
		
		case "SCQ_NM_peace_2":
			dialog.text = "� ���, ��� �� ����� ����� ����. ���� ����� ������ �����������.";
			link.l1 = "��� ��� ����� ����� ����� �����? ������� ������� �����������, ����� � �� ������ ���� ����� ��� � �� ���� �������.";
			link.l1.go = "SCQ_NM_peace_3";
		break;
		
		case "SCQ_NM_peace_3":
			dialog.text = "������ ���� � ���� �� �������� ������. ��� ��� �� ������� ���� ����� � ����� ���� � ����� �� ������ ������ � ����� ������.";
			link.l1 = "������, ������������! �����, ��������� �� �������� ���� ����� �����.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "LifeDay");
			DeleteAttribute(npchar, "talker");
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetLoginTime(npchar, 18.0, 20.0);
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_NM_result";
			sTitle = npchar.city + "SCQ_NM_peace";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_NM_peace", "1");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sQCity", XI_ConvertString("Colony"+npchar.quest.Qcity));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Voc")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
		break;
		
		//--> �������� �� ����, ������� �
		case "NM_battleCap":
			dialog.text = "��? ��� ��� ������, ������?";
			link.l1 = "��� ����� ������� "+GetFullName(npchar)+", �� ��� ��?";
			link.l1.go = "NM_battleCap_1";
		break;
		
		case "NM_battleCap_1":
			dialog.text = "��. � � ��� ����-��?";
			link.l1 = "���� ����� ������������ ���� �������, "+GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)])+". �� ������������, �?";
			link.l1.go = "NM_battleCap_2";
			link.l2 = "� ������, � ��� � ����� ����� �������� ������, � � ��������� ��� ��������. �� ���������?";
			link.l2.go = "NM_battleCap_4";
		break;
		
		case "NM_battleCap_2":
			dialog.text = "������� ����� ��� ���. ��������, �� ���-�� ��������, ������. ��������� ��� ������!";
			link.l1 = "��. �� �����, ��������...";
			link.l1.go = "NM_battleCap_exit";
			link.l2 = "��? ��, ���� �� ����� ������ ������ ���� ���. � �� ����� ������ ������� ��� ����...";
			link.l2.go = "NM_battleCap_3";
		break;
		
		case "NM_battleCap_3":
			dialog.text = "����� ��� ����? ��� �� � ���?";
			link.l1 = "���� �����!";
			link.l1.go = "NM_battleCap_fight";
		break;
		
		case "NM_battleCap_4":
			dialog.text = "�� ��������. ������� ������� � �� ������. ��������� ��� ������!";
			link.l1 = "��. �� �����, ��������...";
			link.l1.go = "NM_battleCap_exit";
		break;
		
		case "NM_battleCap_exit":
			DialogExit();
			NextDiag.TempNode = "NM_battleDeck_exit";
			npchar.DeckDialogNode = "NM_battleDeck_exit";
		break;
		
		case "NM_battleCap_fight":
			NextDiag.TempNode = "NM_battleDeck_exit";
			npchar.DeckDialogNode = "NM_battleDeck_exit";
			LAi_group_Attack(NPChar, Pchar);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		//--> �������� �� ���� � ������ ����������, ������� �
		case "NM_prisonerCap":
			dialog.text = "��? ��� ��� ������, ������?";
			link.l1 = "��� ����� ������� "+GetFullName(npchar)+", �� ��� ��?";
			link.l1.go = "NM_prisonerCap_1";
		break;
		
		case "NM_prisonerCap_1":
			sld = &characters[GetCharacterIndex("QuestCitiz_" + npchar.quest.cribCity)];//������������
			dialog.text = "��. � � ��� ����-��?";
			link.l1 = "� ��� � ������� ������ ������� �� ����� "+sld.quest.SeekCap.name+"?";
			link.l1.go = "NM_prisonerCap_2";
		break;
		 
		case "NM_prisonerCap_2":
			sld = &characters[GetCharacterIndex("QuestCitiz_" + npchar.quest.cribCity)];//������������
			dialog.text = "�����. ��� ���� �� ���� ��������. ��� �� �������, �������, � ���� ��� ��� ���������?";
			link.l1 = "�������. � ���������� ����� �������� �� ��������� ������� "+XI_ConvertString("Colony"+sld.city+"Gen")+". �� "+sld.quest.text1+", � � ����������� ���������� ��� � ��������� � ����� "+XI_ConvertString("Colony"+sld.city)+". � ����� ��� ������� ��� � ���� ����������.";
			link.l1.go = "NM_prisonerCap_3";
		break;
		
		case "NM_prisonerCap_3":
			if(sti(npchar.reputation.nobility) > 41)
			{
				dialog.text = "�� ��� �� ����� ��������! � ���� ������� ������ � ���� � �������? ��� ��� ��! � ���������� ����������� ��������� ��� �� ���� �����.";
				link.l1 = "�� ���������� ���� ��������� ��������, "+GetAddress_FormToNPC(NPChar)+". � ������ ����� � ������ ����� � �� ���� ��� �������.";
				link.l1.go = "NM_prisonerCap_good";
			}
			else
			{
				dialog.text = "�� �������? ������, ������, ��� ������� �� ��� �������. ��� ���� �� ��������. � �� ������ - ��� �����? � ����� ����������� �� ��� ��� ��������? � �� ��������� �������� ����� �������� �� ���, �� ���� �� �� �� ����. � ����� � ����� ��������� � ������������ �� �����. ����� �������!";
				link.l1 = "��. ��� �� ���... ����� ���!";
				link.l1.go = "NM_prisonerCap_bad";
			}
		break;
		
		case "NM_prisonerCap_good":
			dialog.text = "������. ��� � ��������.";
			link.l1 = "����� � ����������� �� ���� �������.";
			link.l1.go = "NM_prisonerCap_good_1";
		break;
		
		case "NM_prisonerCap_good_1":
			DialogExit();
			NextDiag.CurrentNode = "NM_prisonerDeck_exit";
			npchar.DeckDialogNode = "NM_prisonerDeck_exit";
			npchar.quest.release = "true";
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			ref chr = GetCharacter(NPC_GenerateCharacter(npchar.quest.SeekCap + "_" + npchar.quest.cribCity, "citiz_"+(rand(9)+21), "man", "man", 5, sti(npchar.nation), -1, false, "citizen"));
			chr.name = sld.quest.SeekCap.name;
			chr.lastname = "";
			//pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(chr);
			//SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
			AddPassenger(pchar, chr, false);//�������� ���������
			SetCharacterRemovable(chr, false);
			log_info(sld.quest.SeekCap.name+" ������� �� ��� ������� ��� ������");
			PlaySound("interface\notebook.wav");
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).win_condition.l1 = "MapEnter";
			pchar.quest.(sTemp).function = "SCQ_seekCapIsDeath";
			//DoQuestFunctionDelay("SCQ_seekCapIsDeath", 0.5); // 170712
			AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
		break;
		
		case "NM_prisonerCap_bad":
			DialogExit();
			NextDiag.CurrentNode = "NM_prisonerDeck_exit";
			npchar.DeckDialogNode = "NM_prisonerDeck_exit";
			npchar.quest.mustboarding = "true";
			sld = &characters[GetCharacterIndex("QuestCitiz_" + npchar.quest.cribCity)];//������������
			sTitle = sld.City + "SCQ_" + sld.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + sld.quest.SeekCap, "6");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
		break;
		
		case "NM_prisonerDeck_exit":
			dialog.text = "�� ���� ��� ��� ������ �� ������� � ���� ��������, ���, �������?";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "NM_prisonerDeck_exit";
		break;
		
		//--> �������� �� ���� � ������ ����������, ������� C
		case "NM_peaceCap":
			dialog.text = "������ ����. ��� ��� ������, ������?";
			link.l1 = "��� ����� ������� "+GetFullName(npchar)+", �� ��� ��?";
			link.l1.go = "NM_peaceCap_1";
		break;
		
		case "NM_peaceCap_1":
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);//������������
			dialog.text = "������ ���. � ��� �� ��� �����-�� ����?";
			link.l1 = "��. ��� ����������� ������� �� ����� "+GetFullName(sld)+". �� ������, ��� "+sld.quest.text1+". �� ����� �����, ����� �� ��� ����� ������� ������� ��� �����. �� ����� � "+XI_ConvertString("Colony"+npchar.quest.cribCity+"Dat")+".";
			link.l1.go = "NM_peaceCap_2";
		break;
		 
		case "NM_peaceCap_2":
			dialog.text = "��! ��� ���, �� ���� ������� � ����� ����? ����� ��� ������������� ����� ����c���� ���... ��� ������ �� ������� ������ � ���������� � "+XI_ConvertString("Colony"+npchar.quest.cribCity)+". ������� �� ����������, ������!";
			link.l1 = "�� �� ���. ��� ��� ����� ����� �������� ����� ������. �����, "+GetAddress_FormToNPC(NPChar)+"!";
			link.l1.go = "NM_peaceCap_3";
		break;
		
		case "NM_peaceCap_3":
			DialogExit();
			NextDiag.CurrentNode = "NM_peaceCap_exit";
			npchar.DeckDialogNode = "NM_peaceCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.quest.cribCity+"Acc"));
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);//������������
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			//������� ������ � ���� �����
			makearef(forName, NullCharacter.capitainBase);
			DeleteAttribute(forName, npchar.id);
		break;
		
		case "NM_peaceCap_exit":
			dialog.text = "��� ��� � ���� �������������, "+GetAddress_Form(NPChar)+"!";
			link.l1 = "� ����, �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "NM_peaceCap_exit";
		break;
		
		//--> ������� �� ������, ������� �
		case "NM_battleDeck":
			dialog.text = "�����������, "+GetAddress_Form(NPChar)+". ��� ������ ������ ������?";
			link.l1 = "� ������, � ��� � ����� ����� �������� ������, � � ��������� ��� ��������. �� ���������?";
			link.l1.go = "NM_battleDeck_1";
		break;
		
		case "NM_battleDeck_1":
			dialog.text = "�� ��������. ������� ������� � �� ������. � ������, ��� ����� ������� ��� �������� ��������. �����, ��� ����� �������� ��� �����!";
			link.l1 = "������-������, � ������ �������. ����� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "NM_battleDeck_exit";
			npchar.DeckDialogNode = "NM_battleDeck_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		
		case "NM_battleDeck_exit":
			dialog.text = "�� ����������� �� ������������, ������! �������, �� � ���� ��� ��� ��������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "NM_battleDeck_exit";
		break;
		
		 //--> �������, ������� �
		case "NM_battleBoard":
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "����! ����� �� ����� �� ��� �������, �������?";
			link.l1 = "� ������, ����� �������� ���� ������ �� ������ "+XI_ConvertString("Colony"+npchar.quest.cribCity)+", �� �������� �� ����� "+GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)])+". �������, ������-�� ���� �� �������?";
			link.l1.go = "NM_battleBoard_1";
		break;
		
		case "NM_battleBoard_1":
			dialog.text = "����������! ������, ��� ������ ������...";
			link.l1 = "��� �����! �������� �����!";
			link.l1.go = "NM_battleBoard_2";
		break;
		
		case "NM_battleBoard_2":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		 //--> �������, ������� �
		case "NM_prisonerBoard":
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];//������������
			dialog.text = "����! ����� �� ����� �� ��� �������, �������?";
			if (CheckAttribute(npchar, "quest.mustboarding"))
			{
				link.l1 = "� ���, �� �������������? � �� ��-�������� ������ ���� ������ ��� ������ �������-�������. ������ � ��� ��� ������, ��� ������ ��������!";
				link.l1.go = "NM_prisonerBoard_1";
			}
			else
			{
				link.l1 = "� ���� �� ������� � ������� ������ ������� �� ����� "+sld.quest.SeekCap.name+". ��� ����� ������ ������� ������ ������ "+XI_ConvertString("Colony"+npchar.quest.cribCity)+". �� ����� ������� � ������� �� ��� �����.";
				link.l1.go = "NM_prisonerBoard_1";
			}
		break;
		
		case "NM_prisonerBoard_1":
			dialog.text = "� �� ������ ���� ����� ������� ����� �� ���� �����? ��������! � ���� ��� �������� ����... � �������� ����!";
			link.l1 = "��-��, ��������...";
			link.l1.go = "NM_prisonerBoard_2";
		break;
		
		case "NM_prisonerBoard_2":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			pchar.GenQuest.mustboarding = "true";//������ ���� ���� ��� ���������� ������
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "CitizSeekCap_GivePrisoner");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.CitizSeekCap.label = npchar.quest.SeekCap; //���� ������ ��� ���
			pchar.GenQuest.CitizSeekCap.nation = npchar.nation;	//����� ��� ���
			pchar.GenQuest.CitizSeekCap.sex = "man";
			pchar.GenQuest.CitizSeekCap.ani = "man";
			pchar.GenQuest.CitizSeekCap.model = "citiz_"+(rand(9)+21); //������ ��� ���
			pchar.GenQuest.CitizSeekCap.PrisonerCity = npchar.quest.cribCity; //�������� ����� ��� ���
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			pchar.GenQuest.CitizSeekCap.PrisonerName = sld.quest.SeekCap.name; //��� � ������� ��� ���
			pchar.GenQuest.CitizSeekCap.PrisonerLastname = "";
			AddComplexSeaExpToScill(50, 50, 50, 50, 50, 50, 0);
		break;
		
		//--> ���������� ������� ������
		case "SCQ_NM_result":
			dialog.text = "��, ��� �������, �������? ���� �����-������ ���������� �� ����� ����?";
			link.l1 = "���� ���. �� � ������� ��� ����.";
			link.l1.go = "exit";
			switch (npchar.quest.SeekCap)
			{
				case "NM_battleover"://����� ������, ������� �
					dialog.text = "��, ��� �������, �������? ���� �����-������ ���������� �� ����� ����?";
					link.l1 = "����. �, �����, ��� ��� ����������. " + npchar.quest.SeekCap.capName + " �����, � ��� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName)) + " �� ���.";
					link.l1.go = "SCQ_NM_result_A1";
				break;
				
				case "NM_prisonerover"://����� ������, ������� B
					dialog.text = "��, ��� �������, �������? ���� �����-������ ���������� �� ����� ����?";
					link.l1 = "����. �, �����, ��� ��� ����������. "+npchar.quest.SeekCap.Name+" ����� � ����� ����� ������� ��� �������.";
					link.l1.go = "SCQ_NM_result_B1";
				break;
				
				case "NM_peaceover"://����� ������, ������� C
					dialog.text = "�-�, ��� � ��. ��� ��� ������. � ��� ����, ��� �� ��������� ��� ���������!";
					link.l1 = "��� ���� ����� ��� �����?";
					link.l1.go = "SCQ_NM_result_C1";
				break;
			}
		break;
		
		case "SCQ_NM_result_A1":
			dialog.text = "�������! � ����� �����, ��� �� ��� ����� ���������� � ����� ����. ���, ������� ���� ������. �� ��� ������ ����������.";
			link.l1 = "���������. ���� � ��� �������� ��� ������� - �����������.";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			TakeNItems(pchar, "gold_dublon", sti(npchar.quest.dublon));
			Log_Info("�� �������� "+FindRussianDublonString(sti(npchar.quest.dublon))+"");
			PlaySound("interface\important_item.wav");
			sTitle = npchar.city + "SCQ_NM_battle";
			CloseQuestHeader(sTitle);
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			OfficersReaction("bad");
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSeaExpToScill(100, 50, 50, 50, 50, 50, 0);
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
		break;
		
		case "SCQ_NM_result_B1":
			dialog.text = "�������! � ���������� ����������� �������� ����� ����� � ������ �����, ����� ������� ���. ������-�� �� ��� ������ �� �����! ���, ������� ���� ������. �� ��� ������ ����������.";
			link.l1 = "���������. ���� � ��� �������� ��� ������� - �����������.";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			TakeNItems(pchar, "gold_dublon", sti(npchar.quest.dublon));
			Log_Info("�� �������� "+FindRussianDublonString(sti(npchar.quest.dublon))+"");
			PlaySound("interface\important_item.wav");
			sTitle = npchar.city + "SCQ_NM_prisoner";
			CloseQuestHeader(sTitle);
			sld = characterFromId("NM_prisoner_" + npchar.City);
			RemovePassenger(pchar, sld); // 170712
			//ReleasePrisoner(sld);
			sld.lifeday = 0;
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Leadership", 150);//���������
		break;
		
		case "SCQ_NM_result_C1":
			dialog.text = "��, �� ��� �����, � ��������� ��� ������� � ����. ���, ������� ���� ������. �� ��� ������ ����������.";
			link.l1 = "���������. ����� �������, ������!";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			sld = characterFromId(npchar.quest.SeekCap.capId);
			sld.lifeday = 0;
			Map_ReleaseQuestEncounter(sld.id);
			sGroup = "SeekCapShip_" + sld.index;
			group_DeleteGroup(sGroup);
			sTemp = "SecondTimer_" + sld.id;
			pchar.quest.(sTemp).over = "yes"; //������� ��������� ������ �� ����� � ����
			sTemp = "SCQ_" + sld.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����
			TakeNItems(pchar, "gold_dublon", sti(npchar.quest.dublon));
			Log_Info("�� �������� "+FindRussianDublonString(sti(npchar.quest.dublon))+"");
			PlaySound("interface\important_item.wav");
			sTitle = npchar.city + "SCQ_NM_peace";
			CloseQuestHeader(sTitle);
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			OfficersReaction("good");
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Leadership", 200);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
		break;
//<-- ��������� ������ ������

		//========= ������ ������� ===========
		case "SCQ_man":
			dialog.text = LinkRandPhrase("������������, �������. ���� ������� ��� ������ ���.", 
				"�������! �� ������� ��� ������? ���� � ���, ��� � �������� � ������.", 
				"�������, � ����� ��� � ������!");
			link.l1 = RandPhraseSimple("� �����"+ GetSexPhrase("","�") +", �� �������!", "� ������ ������ � ���� ��� ������� ��� �����������.");
			link.l1.go = "SCQ_exit";
			link.l2 = RandPhraseSimple("��� � ��� ���������?", "��������� ���� ��������. ��������, � ����� ������.");
			link.l2.go = "SCQ_man_1";
		break;
		case "SCQ_exit":
			//����� ���� ����, ��� ��������� ������������ ��� ���������
			sld = &locations[FindLocation(npchar.location)];
			if (sti(sld.questSeekCap) > 0) sld.questSeekCap = sti(sld.questSeekCap)-1;
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
            DialogExit();
		break;
		case "SCQ_exit_clear":
			//����� ���� ����, ��� ��������� ������������ ��� ���������
			sld = &locations[FindLocation(npchar.location)];
			if (sti(sld.questSeekCap) > 0) sld.questSeekCap = sti(sld.questSeekCap)-1;
			sld = characterFromId(npchar.quest.SeekCap.capId); //�������	
			sld.lifeDay = 0;
			Map_ReleaseQuestEncounter(sld.id);
			sGroup = "SeekCapShip_" + sld.index;
			group_DeleteGroup(sGroup);
			sTemp = "SCQ_" + sld.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ������������
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
            DialogExit();
		break;
		//�������� �����
		case "SCQ_man_1":
			switch (npchar.quest.SeekCap.numQuest)
			{
				case "0":
					dialog.text = "��� ����� ���� ������� ������ ��������� ���� " + XI_ConvertString("Colony" + SelectNotEnemyColony(NPChar) + "Acc") + ". �� �� ����� ��� ������� � ��� ������ � ����, � ����� ������ � �������. �� ���� ��������� � �������� � �������� ������, ��������� ��� ��������� �� ����� ����� � ������... � �����, � ���� ��������� ����� '�����', ��� � ��� ���.";
					link.l1 = "� ������? ������ �������, ��� �� �������.";
					link.l1.go = "SCQ_Slave";
				break;
				case "1":
					dialog.text = "���� � ���, ��� � ���� �������� ����. ���� �������, ����� �� ������, ���������� ��� �� ���, ��� ������ ���. ���� ���� ����� ���� �� �������� �� ����, ��������� �� ��� ��������. � ������� �������� ��������� ������ � ���� �������� - ��������������. � ��� ���������, ����������...";
					link.l1 = "���� ���������?";
					link.l1.go = "SCQ_RapeWife";
				break;
				case "2":
					dialog.text = "�� ������, � ��� ������ �������, � ������� ��� ���� ����� �� ����������� ���� �� ������� ����� � ������� ����� �����. ��� ���������, ��� � ������ �� �������� ���� �����. �� ������� � �����, ��� ��� ������ ���� �������� ���������! � ������� ��� �����, �� ��� � ���� ���������� �� ����.";
					link.l1 = "������? ��������� ���������, ������� ����, ����� ��������� ��� ���� ������.";
					link.l1.go = "SCQ_Friend";
				break;
			}
		break;
		// ����� ������� ����, �������� �������-��� ���� � ����
		case "SCQ_Slave":
			dialog.text = "� ����, ����� �� ����� ��� � ��������� �� ��� ����. � ��������� ���� ���������, ��� ������ ������ �� ����...";
			link.l1 = "�������... �����, ��� ����� ��� ������ ��� ������. �������� ��� ��� �������� � �������, �� ������� �� �����.";
			link.l1.go = "SCQ_Slave_1";
			link.l2 = "��������, ���� ��� �� ����������.";
			link.l2.go = "SCQ_exit";
		break;
		case "SCQ_Slave_1":
			npchar.quest.SeekCap = "manSlave"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, PIRATE);
			dialog.text = "�������� ����� " + npchar.quest.SeekCap.capName + ". ����� �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'. � ������� ��� �� ��� ������ " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ��� ���� ������ �������������.";
			link.l1 = "����. �� ��� ��, � ���� ��������"+ GetSexPhrase("��","���") +" ��� ������������� �� ���������� ����. ���� ������� ����� ����, �� ��� ������...";
			link.l1.go = "SCQ_Slave_2";
			link.l2 = "�� ����� ������ � � ������� �� ����������. ��� ������ � ������ �����.";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_Slave_2":
			dialog.text = "���-�, ��� ��, ��� � ��� ������ ��������!.. �-�, ��� � ������ ����! ���� �� ����������...";
			link.l1 = "�����, ��������. ��� ������� ������ - ����� ���� �����, � ������.";
			link.l1.go = "SCQ_Slave_3";
		break;
		case "SCQ_Slave_3":
			dialog.text = "������, � ���� ����� ��� � ������� ������. ����� � ����������� � ����.";
			link.l1 = "������.";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_manResult";
			sTitle = npchar.city + "SCQ_manSlave";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_manSlave", "1");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sName2", GetFullName(npchar));
		break;
		//����� ������� ���� � ��������
		case "SCQ_RapeWife":
			dialog.text = "��� ������������� ����������� ������� � ��������� �����������. ���� �������� ������� ��� ���� � ���� �� �� ����� ������� � ����. � ����� ��� ����� ����� �������!";
			link.l1 = "��, �� � ����� ��� ��������� � ���������?";
			link.l1.go = "SCQ_RapeWife_1";
		break;
		case "SCQ_RapeWife_1":
			npchar.quest.SeekCap = "manRapeWife"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, PIRATE);
			makearef(forName, npchar.quest.SeekCap);
			forName.nation = npchar.nation;
			forName.sex = "woman";
			SetRandomNameToCharacter(forName); //npchar.quest.SeekCap.name - ��� ���� ��������
			forName.lastname = npchar.lastname; //������� ��� � � ���� ����
			dialog.text = "� �������, �� � �������� ����� ���, ��� � ���� ����! ���� �� ���������� ��� ���� � ��������� �� �� ���, �� � ������� ��� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ����� ��� ���� ������ �������������.";
			link.l1 = "��, �� ��� ��, � �����"+ GetSexPhrase("","�") +" �������� ���� �����. ��� ����� ����� �������������� ����, ����� � ���� �������? ��, � ��� ����� ���� ����?";
			link.l1.go = "SCQ_RapeWife_2";
			link.l2 = "���, ��������, �� ����� ������ � �� �������� �� ��� ����. �������...";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_RapeWife_2":
			dialog.text = "�� ����� " + npchar.quest.SeekCap.name + ". ��������-�������� ����� " + npchar.quest.SeekCap.capName + ", ������� �� �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'.";
			link.l1 = "������� ��������� �������� ����������������� ��������, ��������. � �������� - �����...";
			link.l1.go = "SCQ_RapeWife_3";
		break;
		case "SCQ_RapeWife_3":
			dialog.text = "��-��, �������, ��������! � ���� �� �����, ��� ��� ���� ���������...";
			link.l1 = "�� ��� ���������, �� �����������. � �����, ������ �������� ���� � ������������ �������.";
			link.l1.go = "SCQ_RapeWife_4";
		break;
		case "SCQ_RapeWife_4":
			dialog.text = "������� ��� ��������! � ���� ����� ��� � ������� ������. ������ � ������ ��� - �������. � ����� �������� �� ����...";
			link.l1 = "������ ���, ��� �����. �����.";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_manResult";
			sTitle = npchar.city + "SCQ_manRapeWife";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_manRapeWife", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sName2", npchar.quest.SeekCap.name + " " + npchar.quest.SeekCap.lastname);
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","���"));
		break;
		//������ �������
		case "SCQ_Friend":
			dialog.text = "���� � ���, ��� ��� ������ ��� � �� ��������� ����� �������������. ��� ��� - ��� ��� �������. ������� ��� ����� ������ ��� ��������, �� ��������� � ��������. � � �� ���� ��������� ���� ������� ����� �� ����������� �����������, � �������� ������������ ���� �� �����.";
			link.l1 = "���� � ��� ��� �����, �� � ����� �� ����� ��� ������...";
			link.l1.go = "SCQ_Friend_1";
		break;
		case "SCQ_Friend_1":
			npchar.quest.SeekCap = "manFriend"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, sti(npchar.nation));
			dialog.text = "� ���� ��������� ��� �� ������ " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ����� ��� ���� ������ �������������. ��� ���, ��� � ���� ���� ��������� �� ������ ������.";
			link.l1 = "����� ���� ����������, � �����"+ GetSexPhrase("","�") +" ������� �� ��� ����. ��, ������, ������ ����� �� ��� ����������, ����� ��� �� �������� ������ � �������, ����� �� ����� ������.";
			link.l1.go = "SCQ_Friend_2";
			link.l2 = "��� ������� ���� ��� ����. ��� ��� ������� ����-������ ������� ��� ����� ����.";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_Friend_2":
			dialog.text = "���, �, �������, �������� �����. ����������, ������� ��������� ������, � � ���� ����� ������ �� ������� �����. � ����� � ���� ���� ������.";
			link.l1 = "�������. �� ��� ��, ������ ���������� ���, ��� ��� ���� � ����� � ���� �������.";
			link.l1.go = "SCQ_Friend_3";
		break;
		case "SCQ_Friend_3":
			dialog.text = "��� ����� " + npchar.quest.SeekCap.capName + ". ��������� ��� ��������, �� ����� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Gen")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'.";
			link.l1 = "����. �� ��� ��, ��� ������ ������� ������ �������, �� ����������� �������� ���, ��� �� ��� �����.";
			link.l1.go = "SCQ_Friend_4";
		break;
		case "SCQ_Friend_4":
			dialog.text = "������� ���. � ���� ����� ������ �������� � ������� ������. �������, ��� ������ ��� ����� ����� ������ ����� ����, ��� ������ ����� ���������.";
			link.l1 = "�������. ��, ����� ��������, �������� ���������� �������.";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_manResult";
			sTitle = npchar.city + "SCQ_manFriend";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_manFriend", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","��"));
			AddQuestUserData(sTitle, "sSex1", GetSexPhrase("","�"));
		break;

		// --- ���������� ������� ������� ---
		case "SCQ_manResult":
			dialog.text = "������������, �������. ���� �����-������ ���������� �� ����� ����?";
			link.l1 = "�������, ��� ��� � ����?..";
			link.l1.go = "SCQ_manResult_exit";
			switch (npchar.quest.SeekCap)
			{
				case "manSlaveover":
					dialog.text = "�� ������ ���� �����������, ��� � �������-�� �������. ��� ���?";
					link.l1 = "������. " + npchar.quest.SeekCap.capName + " �����, � ��� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName)) + " �� ���.";
					link.l1.go = "SCQR_manSlave";
				break;
				case "manRapeWifeover":
					dialog.text = "�� ��������� ��� ����! ��� ������?!";
					link.l1 = "������. ��� � ���� �� ������� � �������� ���������. ������ �� ��������, ���� " + npchar.quest.SeekCap.name + " " + npchar.quest.SeekCap.lastname + " � ���� ���� ����...";
					link.l1.go = "SCQR_manRapeWife";
				break;
				case "manFriendover":
					dialog.text = "������������, �������. �� ����� ����� �������?";
					link.l1 = "���"+ GetSexPhrase("��","��") +" � ���������"+ GetSexPhrase("","�") +", ��� �� ��� ����� �����. ��� ��� ��� ����� ������.";
					link.l1.go = "SCQR_manFriend";
				break;
			}
		break;
		case "SCQ_manResult_exit":
			switch (npchar.quest.SeekCap)
			{
				case "manSlave":
					dialog.text = "���, �� ������, ��� � ����� ��� ��������� �������� �� ����� " + npchar.quest.SeekCap.capName + " �� ���, ����������� ���� � �������?!";
					link.l1 = "�� ������ � �� �����"+ GetSexPhrase("","�") +". ��������� ����, ���.";
					link.l1.go = "exit";
				break;
				case "manRapeWife":
					dialog.text = "���� �� ����! �� ������, ��� ������� ��� ��������� � ���������� ��� ����? �� ������� ����� �� ����� " + npchar.quest.SeekCap.capName + "!";
					link.l1 = "�� �����"+ GetSexPhrase("","�") +" � � ����� ����. ������ ������� ���� �� �������� ����������. ��� ��� �� ��� ������, ���...";
					link.l1.go = "exit";
				break;
				case "manFriend":
					dialog.text = "���������... �� ���, ������ � ����� �������� ����� ����� �������, ��������� �������� �� ����� " + npchar.quest.SeekCap.capName + "?";
					link.l1 = "�� �����"+ GetSexPhrase("","�") +", �� ���� �� ���"+ GetSexPhrase("��","��") +". ���...";
					link.l1.go = "exit";
				break;
			}
		break;

		case "SCQR_manSlave":
			dialog.text = "�����������, � � ��� �� ��������! ����, ��� �� � ��������������, ��� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � �������������. ������� �� ����.";
			link.l1 = "��, �� �� �� ���...";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 10+drand(8));
			sTitle = npchar.city + "SCQ_manSlave";
			CloseQuestHeader(sTitle);
		break;
		case "SCQR_manRapeWife":
			dialog.text = "���� ���, �� ��������� ������� ���� � �����! �������� �������� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � �������������. � ������, ��� �� ����� �������� �� ��� �� ����� �����!";
			link.l1 = "��������, � �� ������.";
			link.l1.go = "SCQ_exit";
			sld = characterFromId("manRapeWife_" + npchar.City);
			RemovePassenger(pchar, sld);
			sld.lifeDay = 0;
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 12+drand(8));
			sTitle = npchar.city + "SCQ_manRapeWife";
			CloseQuestHeader(sTitle);
		break;
		case "SCQR_manFriend":
			dialog.text = "�������!.. ��� ��, ��� � ��� ������ - " + FindRussianMoneyString(sti(npchar.quest.money)) + " � �������������. � ������� ���, �������.";
			link.l1 = "�� �� ���, �������. ������...";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 8+drand(8));
			sTitle = npchar.city + "SCQ_manFriend";
			CloseQuestHeader(sTitle);
		break;
		//========= ������ ��� ===========
		case "SCQ_woman":
			dialog.text = LinkRandPhrase("������������, �������. � ������ ��������� ��� �� ����� ���������.", 
				"�������! �������� �������, ������ ��� �����...", 
				"�������, �� �������� "+ GetSexPhrase("����","���") +" � ������.");
			link.l1 = RandPhraseSimple("� �����"+ GetSexPhrase("","�") +", ���������, �� �������!", "����� ��������, " + GetAddress_FormToNPC(NPChar) + ", �� � ������ ������ � �� ���� �������...");
			link.l1.go = "SCQ_exit";
			link.l2 = RandPhraseSimple("��� � ��� ���������, " + GetAddress_FormToNPC(NPChar) + "?", "��������� ���� ��������, " + GetAddress_FormToNPC(NPChar) + ". � ���������� ��� ������.");
			link.l2.go = "SCQ_woman_1";
		break;
		//�������� �����
		case "SCQ_woman_1":
			switch (npchar.quest.SeekCap.numQuest)
			{
				case "0":
					dialog.text = "��� ��� ���������� ���������� - ���������� ����� ��������� �� ���� ������. ��� ���, �� ���� � ���� ��� ������ ���� ������� �����, � �� ��� ��� �� ��������!";
					link.l1 = "�� �������, � ��� ���-�� ���������?";
					link.l1.go = "SCQ_Hasband";
				break;
				case "1":
					dialog.text = ""+ GetSexPhrase("�������, ��� ������ � �� ��� � ���� ������� ��������, ��������� ����������","�������, � ���� �� ������� � �������� �������, ������ ������ �� ���� ��������") +"...";
					link.l1 = "��� �� � ����, " + GetAddress_FormToNPC(NPChar) + "?";
					link.l1.go = "SCQ_Revenge";
				break;
				case "2":
					dialog.text = "�������, �������� ���, ������� ���! ��� ��� ����� � �������! �� ������ ������ ���?";
					link.l1 = "���������, ���-�� � �� ����� �������, ��� � ���� �����...";
					link.l1.go = "SCQ_Pirates";
				break;
			}
		break;
		
		//������ ����������� ����-��������
		case "SCQ_Hasband":
			dialog.text = "�� ����, �� ����� �������, ��� �� ������ ����� �� ������. ���� ��� �� ��������� ��������, ����� ����, ��� � ��������!";
			link.l1 = "� ���� ������ ����������, ������ ����� ���������...";
			link.l1.go = "SCQ_Hasband_1";
		break;
		case "SCQ_Hasband_1":
			npchar.quest.SeekCap = "womanHasband"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, sti(npchar.nation));
			dialog.text = "���! �� ���������, � ��� � ������. �� ���� �� "+ GetSexPhrase("������� ������","������� ������") +", ������� � � ������ ��������� ��� � ���, ����� �� ����� ����� ����. �� ��� � ������ ��������� ��� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ����� ���� �������������.";
			link.l1 = "������. ���� � ������� ������ ���� � ���� ��� ���-������ ���, �� ������ ��� � ����� ������������. � ������� ���, ��� ����� ������ ������� � ��� � ���� �� �������.";
			link.l1.go = "SCQ_Hasband_2";
			link.l2 = "����� ������ ���� �� ����������. � ���������, � ��������"+ GetSexPhrase("","�") +" ����������...";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_Hasband_2":
			dialog.text = "��� ����� " + npchar.quest.SeekCap.capName + ". � �������� �� �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'.";
			link.l1 = "�������. �� ��� ��, ������ ��������. � ������������ ���������� ��������������� � �����, ����� � �� �����"+ GetSexPhrase("","�") +" ��� �� ������...";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_womanResult";
			sTitle = npchar.city + "SCQ_womanHasband";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_womanHasband", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
		break;
		//����� ����������� �������
		case "SCQ_Revenge":
			dialog.text = ""+ GetSexPhrase("��� � � ����, ��������, ��� � ���� ������ ��� �� ������� ����������, ��� �������... ","� ����, ����� �� ������� ���. �������, ��� �� ���� �������, ��� �������. ") +"��� �������� ������� ���� �������, � �����, ����� �� ����.";
			link.l1 = "�-��-��! ��� ��� ��! � ��� �� �� ��� ������, ���� ����������?";
			link.l1.go = "SCQ_Revenge_1";
		break;
		case "SCQ_Revenge_1":
			dialog.text = "���� �������� ������� ����. �� ����� ���, ��� � ��� ��������, ���� �������� �� ����. � ���������, ��� ��� ����� ���-��� �� ����� ����! � ����� ���� ���������� ������� ������, ����� ���������, ��� ������ ������ �� �� ���� � ����...";
			link.l1 = "��, � �����, � ����?..";
			link.l1.go = "SCQ_Revenge_2";
		break;
		case "SCQ_Revenge_2":
			dialog.text = "� ���, ��-������, ����?! �� ���� �������� ���������� �� ������ ��������?";
			link.l1 = "�� ���, ��� ��...";
			link.l1.go = "SCQ_Revenge_3";
		break;
		case "SCQ_Revenge_3":
			dialog.text = "�� ������ �������������� ����, ���� ��������! ������� ��� ����� �� �����!..";
			link.l1 = "��... "+ GetSexPhrase("�","��, ������� �� ��� ��������. ��,") +" �����, �� ��������? ��, ������� ����-������, � ��� ���������...";
			link.l1.go = "SCQ_Revenge_4";
		break;
		case "SCQ_Revenge_4":
			dialog.text = "���������?! "+ GetSexPhrase("�� �� �������� �����-��, � �� �����","������, �� ������� �� ������ � ����� ��������! �� ��, ��� �� �������... � � ����� ���� ������ �������...") +"!";
			link.l1 = ""+ GetSexPhrase("�� ��� ��! ","") +"� ������ ���� �����, ��������� ���� ��������� ��������.";
			link.l1.go = "SCQ_Revenge_5";
		break;
		case "SCQ_Revenge_5":
			dialog.text = "���� ������, "+ GetSexPhrase("�� ������ �� ������, ��� ����� ����� ����������� �������","�� �� �������, � ������ ��������, ������ ��� - ���� �����������! � ���� ���������") +"!..";
			link.l1 = ""+ GetSexPhrase("��� �����, ���-�� �� ��������","��, ������, ��������� ������ �������� � ���") +"...";
			link.l1.go = "SCQ_Revenge_6";
		break;
		case "SCQ_Revenge_6":
			dialog.text = ""+ GetSexPhrase("��������, ��� ��� �������. ����������� � ��������� � ����� ��������� ������� - ��� �����, ������ � ����! ��� ������, ���������� �������� �� ����","� ��� � �� �����. � ��� ������, ��� ����� �������� ��� ����") +"!\n��� ��� � ����, ����� �� ����� ��� �����. � ����� ������� �� ������ ������, ��� ��� ��� �����������...";
			link.l1 = "��, ���� �� ���� ��� �������... � ������� �� ������ �� ��� ���������?";
			link.l1.go = "SCQ_Revenge_7";
		break;
		case "SCQ_Revenge_7":
			npchar.quest.SeekCap = "womanRevenge"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, PIRATE);
			dialog.text = "���, ��� � ���� ����. � ����� ��� ��� ������������� � " + FindRussianMoneyString(sti(npchar.quest.money)) + "! �������?";
			link.l1 = "�� ��� ��, ��� ��� ���������. ���������� ���, ��� ��� �������, ��������� ������ ������� �� ��������?";
			link.l1.go = "SCQ_Revenge_8";
			link.l2 = ""+ GetSexPhrase("�������, � ������� ������� ������������. ","") +"��������, ��� ����...";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_Revenge_8":
			dialog.text = "����� ������� ����� " + npchar.quest.SeekCap.capName + ", �� �������� ��������� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Acc")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'.";
			link.l1 = "��������, ��� ��� ����� ������ � ����������, " + GetAddress_FormToNPC(NPChar) + ". � ������ ����� ���� � ������� ������. �������, ������ ��� ���� ������� ��������...";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_womanResult";
			sTitle = npchar.city + "SCQ_womanRevenge";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_womanRevenge", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipTypeName2", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Gen")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sName2", GetFullName(npchar));
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sTitle, "sSex1", GetSexPhrase("��","��"));
			AddQuestUserData(sTitle, "sSex2", GetSexPhrase("","�"));
		break;
		//��� ������� ����� � ���� � �������
		case "SCQ_Pirates":
			dialog.text = "������ � ��� �������. ���� � ���, ��� ���, ���������� ������� �������, ��� �������� ��������! ��� ������� ����, ������ �� ������...";
			link.l1 = "������, ������� ������ ������� �������������. ���� �� ��� �������, ������ �� �� �������.";
			link.l1.go = "SCQ_Pirates_1";
		break;
		case "SCQ_Pirates_1":
			dialog.text = "����� ����, �� ��� ��� ��� ���������� �� ��� ���. �� ��� ������� ���������� �� ���� �������. ��� ���, ����� ������ ���� �����, ��� �������� �������, ��� �� �������� �����. ������ ��� ��������, � ���� �� ������� � ����.";
			link.l1 = "� ������ �� ������?";
			link.l1.go = "SCQ_Pirates_2";
		break;
		case "SCQ_Pirates_2":
			dialog.text = "���� ������� ��������� ��� ������, ��� �� �����, ��� � ��� ��� � �������. ��� ������ � �����, �� ��� ������ ���������.";
			link.l1 = "� ��� �� �������� ������? ��� ����� ������������ �� �����. ���� ��� ������ ������ ��� ��������.";
			link.l1.go = "SCQ_Pirates_3";
		break;
		case "SCQ_Pirates_3":
			dialog.text = "�� ���� ���� �����? ��-��, � ����... ������ ���, �������� ���, ������� ����� ����! � ������ �� ������ ��������� ������� � ������ ��� ��������. ��� ���� ����� ���������� ������ ����� ���!";
			link.l1 = "�� ��� ��� � ������, ��� ��� �������. ��� �������� - �������� ���� ������������ ������� ����. �� � �� ���� � ������� ��� �� �������� ����.";
			link.l1.go = "SCQ_Pirates_4";
		break;
		case "SCQ_Pirates_4":
			dialog.text = "�� �� �� ������ ����������! � ���� ��, ����� �� ������ ����. ��� ��� ������ �� �����, �� �������� ����������� �� ������� �����, ��� ��� ������ �� ������� �� ���� ����� ���������� - ����� �� ���� ����� ������. ���� �� ���������� ���, �� � ����� ��� ���, ��� � ���� ����!";
			link.l1 = "� ��� � ��� ����?";
			link.l1.go = "SCQ_Pirates_5";
		break;
		case "SCQ_Pirates_5":
			npchar.quest.SeekCap = "womanPirates"; //������ ���� �������� �� �����
			SetSeekCapCitizenParam(npchar, PIRATE);
			dialog.text = "�������, " + FindRussianMoneyString(sti(npchar.quest.money)) + " � ��� ��� �������������... �� � ���� �������� �� ���� ���� �� ����� �����!";
			link.l1 = "�� ��, ������������� �������... �� �� �����, � �����"+ GetSexPhrase("","�") +" ������ ��� ��� ������.";
			link.l1.go = "SCQ_Pirates_6";
			link.l2 = "�������, �� ��� ������� ���� ��� ����, ����� � �����"+ GetSexPhrase("","�") +" �� ������ �������, ����� ���������� ��������.";
			link.l2.go = "SCQ_exit_clear";
		break;
		case "SCQ_Pirates_6":
			dialog.text = "������� ���, �������!!";
			link.l1 = "���� ��� ���������, ����� � ������ �����������, � ���� �� �����. ����������-�� �����, ��� ����� ������ ���� � ���, ��� �� ������ �� ���� �������.";
			link.l1.go = "SCQ_Pirates_7";
		break;
		case "SCQ_Pirates_7":
			makearef(forName, npchar.quest.SeekCap);
			forName.nation = npchar.nation;
			forName.sex = "man";
			SetRandomNameToCharacter(forName); //npchar.quest.SeekCap.name - ��� ���� ��������
			forName.lastname = npchar.lastname; //������� ��� � � ���� ����
			dialog.text = "���� ����� " + GetFullName(forName) + ". �������� ������� ����� " + npchar.quest.SeekCap.capName + ", �� ���������� �� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")) + " � ������ '" + npchar.quest.SeekCap.shipName + "'.";
			link.l1 = "����. �� ��� ��, ������ �������� � ���������, ��� ��� ������� � ��������. ������������ ���������� � ������, ����� � ���"+ GetSexPhrase("","��") +" ��� ��� ������ �����.";
			link.l1.go = "exit";
			//==> ������ ������������ � �������
			pchar.quest.SeekShip_Stay.win_condition.l1 = "ExitFromLocation";
			npchar.location = npchar.city + "_church";
			npchar.location.locator = "goto2";			
            pchar.quest.SeekShip_Stay.win_condition.l1.location = pchar.location;
			pchar.quest.SeekShip_Stay.function = "SeekShip_Stay";
			pchar.quest.SeekShip_Stay.Idx = npchar.index;
			NextDiag.TempNode = "SCQ_womanResult";
			sTitle = npchar.city + "SCQ_womanPirates";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "SCQ_womanPirates", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Dat")));
			AddQuestUserData(sTitle, "sShipTypeName2", GetStrSmallRegister(XI_ConvertString(npchar.quest.SeekCap.shipTapeName + "Gen")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.SeekCap.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.SeekCap.capName);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sName2", GetFullName(forName));
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sTitle, "sSex1", GetSexPhrase("","�"));
		break;
		// --- ���������� ������� ������� ---
		case "SCQ_womanResult":
			dialog.text = "��, �������, � ��� ���� ��� ������! ���������� ��� �������, ��� �� ������ �� ����� ����?";
			link.l1 = "��, ���������, " + GetAddress_FormToNPC(NPChar) + ", � ����� ���� ���� ����?";
			link.l1.go = "SCQ_womanResult_exit";
			switch (npchar.quest.SeekCap)
			{
				case "womanHasbandover":
					dialog.text = "��, �������, � �������� ������ �� ����! � ��� �� �����, ��� �� ����� ���.";
					link.l1 = "��, ��� �����, " + GetAddress_FormToNPC(NPChar) + ". ��� ���, " + npchar.quest.SeekCap.capName + ", ��� � ������. �� ������ �����������...";
					link.l1.go = "SCQR_womanHasband";
				break;
				case "womanRevengeover":
					dialog.text = "��� �������, �������? �� ������� ��, � ��� � ��� �������? ������� " + npchar.quest.SeekCap.capName + " �����?";
					link.l1 = "��, �� �����, " + GetAddress_FormToNPC(NPChar) + ". ����� ������� �� �����, ��� ���� �������� ��� ������. ���������, ��� �� ������ � ���� ����� - ���� ���.";
					link.l1.go = "SCQR_womanRevenge";
				break;
				case "womanPiratesover":
					dialog.text = "�� ���-���� ���������� ����� ����! ������ ���, ������� ���, ��� ���?!!";
					link.l1 = "��, ������ �� ��������� � ���� �� �������. ������ ��� ��������, ���� " + npchar.quest.SeekCap.name + " " + npchar.quest.SeekCap.lastname + " � ���� ��� ���...";
					link.l1.go = "SCQR_womanPirates";
				break;
			}
		break;
		case "SCQ_womanResult_exit":
			switch (npchar.quest.SeekCap)
			{
				case "womanHasband":
					dialog.text = "�� ���, ������, ��� ������� ��� ����� ����� ����? ��� ����� " + npchar.quest.SeekCap.capName + "!";
					link.l1 = "�-�, ��, �������... ������ � �� �����"+ GetSexPhrase("","�") +", ������ � ���� ��� � �� �����"+ GetSexPhrase("","�") +" ��� ���������.";
					link.l1.go = "exit";
				break;
				case "womanRevenge":
					dialog.text = "� ���-�� �� ������! �� ������, ��� ������ ��������� �� ��� ���� ����� ��������, �������� �� ����� " + npchar.quest.SeekCap.capName + "?!";
					link.l1 = "�� ��� ��, " + GetAddress_FormToNPC(NPChar) + ", �� � ���� ����. ��� ����� � ������, ��������...";
					link.l1.go = "exit";
				break;
				case "womanPirates":
					dialog.text = "�������, �������, �� ������, ��� ������� ��������� ����� ���� �� �����?!";
					link.l1 = "� ������ �� �����"+ GetSexPhrase("","�") +", ������� ��� ����. �����, " + GetAddress_FormToNPC(NPChar) + " " + npchar.lastname + ".";
					link.l1.go = "exit";
				break;
			}
		break;

		case "SCQR_womanHasband":
			dialog.text = "���� ���, ��� � ��� ����������! ��, ������, ��� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + ". � ��� ��� �������!";
			link.l1 = "��, �� �� �� ���...";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 8+drand(8));
			sTitle = npchar.city + "SCQ_womanHasband";
			CloseQuestHeader(sTitle);
		break;
		case "SCQR_womanRevenge":
			dialog.text = "�������! �� ��� ��, ��� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + " � �������������. ��������.";
			link.l1 = "��������...";
			link.l1.go = "SCQ_exit";
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 10+drand(8));
			TakeNItems(pchar, "jewelry47", rand(3));
			TakeNItems(pchar, "jewelry43", rand(3));
			TakeNItems(pchar, "jewelry41", rand(3));
			TakeNItems(pchar, "jewelry48", rand(3));
			TakeNItems(pchar, "jewelry51", rand(3));
			TakeNItems(pchar, "jewelry46", rand(3));
			TakeNItems(pchar, "jewelry49", rand(3));
			TakeNItems(pchar, "jewelry40", rand(3));
			sTitle = npchar.city + "SCQ_womanRevenge";
			CloseQuestHeader(sTitle);
		break;
		case "SCQR_womanPirates":
			dialog.text = "�������, ��� ��!!! �������, �������, ��� �� � ��� ����������! ��� ���� " + FindRussianMoneyString(sti(npchar.quest.money)) + ". � ���� �������� �� ��� ������ ����, ���� ����!";
			link.l1 = "��� �������, ��������...";
			link.l1.go = "SCQ_exit";
			sld = characterFromId("womanPirates_" + npchar.City);
			RemovePassenger(pchar, sld);
			sld.lifeDay = 0;
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����������-������������
			AddMoneyToCharacter(pchar, sti(npchar.quest.money));
			TakeNItems(pchar, npchar.quest.gem, 12+drand(8));
			sTitle = npchar.city + "SCQ_womanPirates";
			CloseQuestHeader(sTitle);
		break;
		//========= ������������� �������-������������ ===========
		case "CitizCap": //������� �� ����
			switch (npchar.quest.SeekCap)
			{
				case "manSlave":
					dialog.text = "����������� �������. ��� �� �����"+ GetSexPhrase(", �������","�, �������") +"?";
					link.l1 = "���� ����� " + GetFullName(npchar) + ", �� ��� ��?";
					link.l1.go = "CCmanSlave";
				break;
			}
		break;
		case "CCmanSlave":
			dialog.text = "��, ��� �����!";
			link.l1 = "����� ���� �� �������. � ������ ������ ���� ���� ���, � �� ���������� ��������� ����� ��������. " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + ". �� ������������?";
			link.l1.go = "CCmanSlave_1";
		break;
		case "CCmanSlave_1":
			dialog.text = "��, ����������...";
			link.l1 = "��� ���, �� ����� �� ���� ������, ��������. ��� ��� ������ ����� ������������ �� ��, ��� �� ������ ���������� �������� � �������.";
			link.l1.go = "CCmanSlave_2";
		break;
		case "CCmanSlave_2":
			dialog.text = "������������?! ��� �� � ���?";
			link.l1 = "� ���, ��� � �������� ���� ����� �����.";
			link.l1.go = "CCmanSlave_3";
		break;
		case "CCmanSlave_3":
			dialog.text = "�� �������, "+ GetSexPhrase("�������","�������") +", ���� ���� �� ����������! ��� �� ���������� ��������� �����������. ��� ����� ����� - �� ���������� ���������!";
			link.l1 = "��, �� ���� ����� ������������. ��� ��� �������� �������� �� ���������!";
			link.l1.go = "CCmanSlave_4";
		break;
		case "CCmanSlave_4":
			dialog.text = "��! �� ��� ��, ������, ��� ����!";
			link.l1 = "�����-�����...";
			link.l1.go = "CCmanSlave_fight";
		break;
		case "CCmanSlave_fight":
			NextDiag.TempNode = "CitizCap_inDeck_exit";
			npchar.DeckDialogNode = "CitizCap_inDeck_exit";
			LAi_group_Attack(NPChar, Pchar);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "CitizCap_inDeck": //������� �� ������
			dialog.text = "��� ���� ����� � ���� �� ������?";
			link.l1 = "���� �������� ����, �� ����������� �� �� ������� ����������?";
			link.l1.go = "CitizCap_inDeck_1";
		break;
		case "CitizCap_inDeck_1":
			dialog.text = "� ���� ����� ����?";
			link.l1 = "�� ������ ��� ���������...";
			link.l1.go = "CitizCap_inDeck_2";
		break;
		case "CitizCap_inDeck_2":
			dialog.text = "������ ���... ������, ��������-�� �� ������, ���� ��� ���� ����� �����������. �� ��������� �� ���!";
			link.l1 = "�����, �����, �� ��������. ��� �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "CitizCap_inDeck_exit";
			npchar.DeckDialogNode = "CitizCap_inDeck_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		case "CitizCap_inDeck_exit":
			dialog.text = "���������� ���, �� ���������!";
			link.l1 = "�� � �� ���������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CitizCap_inDeck_exit";
		break;
		//========= ������������� ���, ���������� ����� ���� ===========
		case "RapeWifeCap":  //������� �� ����
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "����������� �������! �� ���-�� �����"+ GetSexPhrase(", �������","�, �������") +",?";
			link.l1 = "� �����"+ GetSexPhrase("","�") +" ������, �� �� �� ������ �� " + XI_ConvertString("Colony" + npchar.quest.cribCity + "Gen") + " �������, �� ����� " + GetFullName(sld) + "?";
			link.l1.go = "RapeWifeCap_1";
		break;
		case "RapeWifeCap_1":
			dialog.text = "���, ��� � ����, ��� � ���� � �����! ������, ��������!.. � ����� �� �����������?";
			link.l1 = "��������, ��� ���� �������. �� ������� �������� �������!";
			link.l1.go = "RapeWifeCap_2";
		break;
		case "RapeWifeCap_2":
			dialog.text = "�� � ��� � ����? ��� ��� ��������, � ���� � ������. � � �� ������� ������-�� ��������� ����������� � ���� ��������� ������ ������, ��� �� �� ���, ������ ��!..";
			link.l1 = "������� ���� ��������, ��� ��������� �������� ����� ��� ������� �� ��������.";
			link.l1.go = "RapeWifeCap_3";
		break;
		case "RapeWifeCap_3":
			dialog.text = "�� ���, ������ ��� ��� ������ �������"+ GetSexPhrase("","�") +"? ��������� �������� � ����� ���� �������� ��������� �� �����, ��� ��� ���� ��������� �� � ���� �� ��������. ��� ���, � �����!";
			link.l1 = "�� ��������, � ������ �������������"+ GetSexPhrase("��","���") +"... ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "RapeWifeCap_exit";
			npchar.DeckDialogNode = "RapeWifeCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		case "RapeWifeCap_exit":
			dialog.text = "���������� ��� � ��������. ������ �� ����� ��� ���������!";
			link.l1 = "�����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "RapeWifeCap_exit";
		break;
		case "RapeWifeCap_inDeck":  //������� �� ������
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "��� �������������� ������� � ���� �� ������! ��� �� �����"+ GetSexPhrase("","�") +" �������� �� ����, "+ GetSexPhrase("�������","�������") +"?";
			link.l1 = "� �����"+ GetSexPhrase("","�") +" ������, �� �� �� ������ �� " + XI_ConvertString("Colony" + npchar.quest.cribCity + "Gen") + " �������, �� ����� " + GetFullName(sld) + "?";
			link.l1.go = "RapeWifeCap_1";
		break;
		case "RapeWifeCap_inDeck_1":
			dialog.text = "���, ��� � ����, ��� � ���� � �����! ������, ��������!.. � ����� �� �����������?";
			link.l1 = "��������, ��� ���� �������. �� ������� �������� �������!";
			link.l1.go = "RapeWifeCap_inDeck_2";
		break;
		case "RapeWifeCap_inDeck_2":
			dialog.text = "�� � ��� � ����? ��� ��� ��������, � ���� � ������. � � �� ������� ������-�� ��������� ����������� � ���� ��������� ������ ������, ��� �� �� ���, ������ ��!..";
			link.l1 = "������� ���� ��������, ��� ��������� �������� ����� ��� ������� �� ��������.";
			link.l1.go = "RapeWifeCap_inDeck_3";
		break;
		case "RapeWifeCap_inDeck_3":
			dialog.text = "�� ���, ������ ��� ��� ������ �������"+ GetSexPhrase("","�") +"? ��������� �������� � ����� ���� �������� ��������� �� �����, ��� ��� ���� ��������� �� � ���� �� ��������. ��� ���, � �����!";
			link.l1 = "�� ��������, � ������ �������������"+ GetSexPhrase("��","���") +"... � �����, �����, ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "RapeWifeCap_exit";
			npchar.DeckDialogNode = "RapeWifeCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		case "RapeWifeCap_Board": //�������
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "��� ���� �����, �������?!!";
			link.l1 = "� ����"+ GetSexPhrase("��","��") +" �� ��������, ��� �� ����� � ����. ������� " + XI_ConvertString("Colony"+npchar.quest.cribCity) + "! �� ����� " + sld.quest.SeekCap.name + " " + sld.quest.SeekCap.lastname + ".";
			link.l1.go = "RapeWifeCap_Board_1";
		break;
		case "RapeWifeCap_Board_1":
			dialog.text = "������!! ���� �� ������ �� ��� ����� ����!";
			link.l1 = "��, �����!! ���� ��� � ���� � �������! � ���� ������ ������...";
			link.l1.go = "RapeWifeCap_Board_2";
		break;
		case "RapeWifeCap_Board_2":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree(); // ������ �����
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "CitizSeekCap_afterCabinFight");
			pchar.GenQuest.CitizSeekCap.label = npchar.quest.SeekCap; //���� ������ ��� ���
			pchar.GenQuest.CitizSeekCap.nation = npchar.nation;	//����� ��� ���
			pchar.GenQuest.CitizSeekCap.sex = "woman";
			pchar.GenQuest.CitizSeekCap.ani = "towngirl";
			pchar.GenQuest.CitizSeekCap.model = "women_"+(drand(3)+7); //������ ��� ���
			pchar.GenQuest.CitizSeekCap.WifeCity = npchar.quest.cribCity; //�������� ����� ��� ���
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			pchar.GenQuest.CitizSeekCap.WifeName = sld.quest.SeekCap.name; //��� � ������� ��� ���
			pchar.GenQuest.CitizSeekCap.WifeLastname = sld.quest.SeekCap.lastname;
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//========= ���������� ���� ===========
		case "manRapeWife_Board":
			dialog.text = "��� ��?";
			link.l1 = "������������. � ����"+ GetSexPhrase("��","��") +" �� ���� �� ��������� ������ ����. ������, ����� �� ��������, ��� ����� ������� ��� � ����.";
			link.l1.go = "manRapeWife_Board_1";
		break;
		case "manRapeWife_Board_1":
			dialog.text = "������� ��� �� ���?! ��� ������?!";
			link.l1 = "��������� ������, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "manRapeWife_Board_2";
		break;
		case "manRapeWife_Board_2":
			dialog.text = "����� ������� �����������!!! � ������, ������� ������� ����� ������!";
			link.l1 = "������, " + GetAddress_FormToNPC(NPChar) + ", ���������� � ����������� �����, � ����.";
			link.l1.go = "exit";
			//������ ���� �� �����
			npchar.location = "none";
			npchar.location.locator = "";
			LAi_SetPlayerType(pchar);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "6");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.quest.cribCity+"Acc"));
		break;
		//========= ������������� ������-�������� ��� ===========
		case "FriendCap": //������� �� ����
			dialog.text = "������������! ��� �������������� ������� �� ����...";
			link.l1 = TimeGreeting() + " � � ���"+ GetSexPhrase("��","��") +" ��� �� ����.";
			link.l1.go = "FriendCap_1";
		break;
		case "FriendCap_1":
			dialog.text = "������ ��� �����������.";
			link.l1 = "���� � ���, ��� ��� ���� ��� ������, � ������� �� ����������� ���� �� ������� �����. " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + ", �������� ���?";
			link.l1.go = "FriendCap_2";
		break;
		case "FriendCap_2":
			dialog.text = "��, ��� ��! � ��� �� �����?";
			link.l1 = "� " + XI_ConvertString("Colony"+npchar.quest.cribCity+"Dat") + ". � ���������"+ GetSexPhrase("","�") +" ��� ����������� �� ����, �� �� ���������. ������ ��� ������� � ����.";
			link.l1.go = "FriendCap_3";
		break;
		case "FriendCap_3":
			dialog.text = "�������, � ��� ������. ������� ��� �������!.. �� ������, �� ������ ���� � ������ ��, ��� �� �����!";
			link.l1 = "��� � ����. �� � ������� ����"+ GetSexPhrase("��","��") +", ��� ��� ���� �� � ��� �����������. ����� ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "FriendCap_exit";
			npchar.DeckDialogNode = "FriendCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.quest.cribCity+"Acc"));
			sTemp = "SecondTimer_" + npchar.id;
			pchar.quest.(sTemp).over = "yes"; //������� ������������� ������ �� ����� � ����
			npchar.lifeDay = 0;
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			//������� ������ � ���� �����
			makearef(forName, NullCharacter.capitainBase);
			DeleteAttribute(forName, npchar.id);
		break;
		case "FriendCap_exit":
			dialog.text = "��� ���������, ��� �������? ��������, � ������� ���������...";
			link.l1 = "��� � �������, ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "FriendCap_exit";
		break;
		case "FriendCap_inDeck": //������� �� ������
			dialog.text = TimeGreeting() + ". ��� ��� ����� �� ����? � ����� ���� �������� �������, �...";
			link.l1 = "� ����, ��������. �� ��������� ���, �������, ��� ������ ��� ��������. � � ���� �� ����.";
			link.l1.go = "FriendCap_inDeck_1";
		break;
		case "FriendCap_inDeck_1":
			dialog.text = "�� ������ ����?";
			link.l1 = "���� ���� ���� ������ " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + ". ������ ������?";
			link.l1.go = "FriendCap_inDeck_2";
		break;
		case "FriendCap_inDeck_2":
			dialog.text = "�-�-�, ������� ���-����! ����� ������... �� ���� �������� �� ������ �����, �, ������ ��, ������� ����� �������, ��� �� �����.";
			link.l1 = "��� � ����. �� ���� ���� ������ �� ��������. ���� ������� �������� ���� ���������, ��� � � ������"+ GetSexPhrase("","�") +". ���� ������, ������, ����� � �������� � " + XI_ConvertString("Colony"+npchar.quest.cribCity+"Dat") + ".";
			link.l1.go = "FriendCap_inDeck_3";
		break;
		case "FriendCap_inDeck_3":
			dialog.text = "��� ��� ��!.. �� - "+ GetSexPhrase("����������� �������","����������� �������") +". ������� ���!";
			link.l1 = "�� �� ���. ������ � ���� ������, ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "FriendCap_exit";
			npchar.DeckDialogNode = "FriendCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.quest.cribCity+"Acc"));
			npchar.quest = "outMap"; //������� �� ������ ����� - � ��������
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			//������� ������ � ���� �����
			makearef(forName, NullCharacter.capitainBase);
			DeleteAttribute(forName, npchar.id);
		break;
		//========= ������������� ���-�������� ===========
		case "HasbandCap": //������� �� ����
			dialog.text = "������������. �� ���-�� ������?";
			link.l1 = "��� ����� " + GetFullName(npchar) + ", �� ��� ��?";
			link.l1.go = "HasbandCap_1";
		break;
		case "HasbandCap_1":
			dialog.text = "��, ��� �.";
			link.l1 = "���, �������, ������ �����, �� ���� ���� ������� ���� ��������, ��� ����� �� ��� ���������.";
			link.l1.go = "HasbandCap_2";
		break;
		case "HasbandCap_2":
			dialog.text = "��! ��, ��� �������... ������-�� � ��������� ���������� � �������, ��� ��� �� �� ��� ������. �������� ����������� ������� ���� �� �������, � �� ���� �������� ��������� ������ ������ ������, ��� ��� ���� ���������.";
			link.l1 = "��� �������, �� �� ����� ���� �� �������� ��, ��� � ���� ��� � �������.";
			link.l1.go = "HasbandCap_3";
		break;
		case "HasbandCap_3":
			dialog.text = "��, �� �����. ���������� �� ������!.. ������� ��� �������� �� ������� � ����� �������� �����!";
			link.l1 = "�� �� ���, �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "HasbandCap_inDeck_exit";
			npchar.DeckDialogNode = "HasbandCap_inDeck_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			sTemp = "SecondTimer_" + npchar.id;
			pchar.quest.(sTemp).over = "yes"; //������� ������������� ������ �� ����� � ����
			npchar.lifeDay = 0;
			sTemp = "SCQ_" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� ������ ����
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			//������� ������ � ���� �����
			makearef(forName, NullCharacter.capitainBase);
			DeleteAttribute(forName, npchar.id);
		break;
		case "HasbandCap_inDeck": //������� �� ������
			dialog.text = "������������. ���� ������ �� ����� ������ ��� � ���� �� �������?";
			link.l1 = "��� ����� " + GetFullName(npchar) + ", �� ��� ��?";
			link.l1.go = "HasbandCap_inDeck_1";
		break;
		case "HasbandCap_inDeck_1":
			dialog.text = "��, ��� �.";
			link.l1 = "���, �������, ������ �����, �� ���� ���� ������� ���� ��������, ��� ����� �� ��� ���������.";
			link.l1.go = "HasbandCap_inDeck_2";
		break;
		case "HasbandCap_inDeck_2":
			dialog.text = "��, ����! � �, ������ ������, ��������� - �����, ��� ��� ���������� ������� �� ������� - ���������� ���� ������ �� ���� ��������. ��, ������, ��� ������...\n�� ������, � ��������� ���������� � �������, ��� ��� �� �� ��� ������. �������� ����������� ������� ���� �� �������, � �� ���� �������� ��������� ������ ������ ������, ��� ��� ���� ���������.";			
			link.l1 = "��� �������, �� �� ����� ���� �� �������� ��, ��� � ���� ��� � �������.";
			link.l1.go = "HasbandCap_inDeck_3";
		break;
		case "HasbandCap_inDeck_3":
			dialog.text = "��, �� �����. � ��� ����������� ������ � ������ �� ����� �� ���������... ������� ��� �������� �� ������� � ����� �������� �����!";
			link.l1 = "�� �� ���, �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "HasbandCap_inDeck_exit";
			npchar.DeckDialogNode = "HasbandCap_inDeck_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			npchar.quest = "outMap"; //������� �� ������ ����� - � ��������
			sld = characterFromId("QuestCitiz_" + npchar.quest.cribCity);
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			//������� ������ � ���� �����
			makearef(forName, NullCharacter.capitainBase);
			DeleteAttribute(forName, npchar.id);
		break;
		case "HasbandCap_inDeck_exit":
			dialog.text = "��� ��� ������� ��� �������������...";
			link.l1 = "�� �� �����, ��� � �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "HasbandCap_inDeck_exit";
		break;
		//========= ������������� �������-�������� ===========
		case "RevengeCap": //������� �� ����
			dialog.text = "��� ������ ��� � ���� ���������, �������. ��� ���-�� ����� �� ����?";
			link.l1 = ""+ GetSexPhrase("������, �������... ���, ���� �� ����, ��� ��� �������!","��, �����.") +"";
			link.l1.go = "RevengeCap_1";
		break;
		case "RevengeCap_1":
			dialog.text = ""+ GetSexPhrase("��������, ��� ����.","���������, � ��� ��?") +"";
			link.l1 = ""+ GetSexPhrase("��, ��� � ��������... � �����, �","�") +" ���� � ��� ������. �� ������� � ����� �� ����� " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + "?";
			link.l1.go = "RevengeCap_2";
		break;
		case "RevengeCap_2":
			dialog.text = "���, �� ��, ������. ���� ��������� �������� � ���. �������� ����, ���� ��� �������...";
			link.l1 = "��... ��� ���, ��� �������� ���� ������ ���� ����� ���"+ GetSexPhrase(", �������. ��� ���-��..","") +".";
			link.l1.go = "RevengeCap_3";
		break;
		case "RevengeCap_3":
			dialog.text = "��, ��� ��� ������ ������...";
			link.l1 = ""+ GetSexPhrase("���� �� �� ���� ��� �������... �������, �� �� ����","������ �������� � ���� ���. �� ����") +" ������ ��������� �������. � � �������"+ GetSexPhrase("","�") +" �� ��������.";
			link.l1.go = "RevengeCap_4";
		break;
		case "RevengeCap_4":
			dialog.text = "��-��!.. �� �� ������, �������?";
			link.l1 = ""+ GetSexPhrase("���, ���� ���...","���� �� ������!") +"";
			link.l1.go = "RevengeCap_5";
		break;
		case "RevengeCap_5":
			dialog.text = ""+ GetSexPhrase("�� ����� �� ��� ����, �����?! �� � ���������-�� ��������� �� ������. ���, ����������� �� ���������� � �������� �����","���� ������! ���� �������� ����� ������ ������! ��� �� ��� �� ���� ����� ��������?") +"!";
			link.l1 = ""+ GetSexPhrase("��� ���?!","�� ����������� �� � ����� ��������� �����, ��� ��� ������ ���������� ����, ��� ��� ������ ���������.") +"";
			link.l1.go = "RevengeCap_6";
		break;
		case "RevengeCap_6":
			dialog.text = ""+ GetSexPhrase("�� � ��� �� �����, ����� � ���� �������? ���� ��� ������, ����-�� �� ���������...","������� ������������, ��?!") +"";
			link.l1 = ""+ GetSexPhrase("","������, �������, � ��� ����. ") +"�������� ���� ������!";
			link.l1.go = "RevengeCap_7";
		break;
		case "RevengeCap_7":
			NextDiag.TempNode = "RevengeCapCap_exit";
			npchar.DeckDialogNode = "RevengeCapCap_exit";
			npchar.quest.SeekCap = "womanRevengeFight"; //���� ������ ��� ������ � ���������� �� ��������
			LAi_group_Attack(NPChar, Pchar);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		case "RevengeCapCap_exit":
			dialog.text = "� ����� � ���� ��� ��� ��������. "+ GetSexPhrase("����� ���, ��������","��������, ������") +"...";
			link.l1 = ""+ GetSexPhrase("��������","������") +"?! �� �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "RevengeCapCap_exit";
		break;
		case "RevengeCap_inDeck": //������� �� ������
			dialog.text = "��� ������ ��� � ���� �� ������, �������. ����� ����������?";
			link.l1 = "� ���� � ��� ������. �� ������� � ����� �� ����� " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + "?";
			link.l1.go = "RevengeCap_inDeck_1";
		break;
		case "RevengeCap_inDeck_1":
			dialog.text = "���, �� ��, ������. ���� ��������� �������� � ���. �������� ����, ���� ��� �������...";
			link.l1 = "���, ��� ��� ��� �������� ���� ������ ���� ����� ���"+ GetSexPhrase(", �������. ��� ���-��..","") +".";
			link.l1.go = "RevengeCap_inDeck_2";
		break;
		case "RevengeCap_inDeck_2":
			dialog.text = "��-��... �������, �� ������� ����. ���� � ��� ������ ��� �� ��� ���, �� ��������.";
			link.l1 = "�� ��� ��, ��������. �� ������ � ���� ��, ��� � ��� ������"+ GetSexPhrase("","�") +".";
			link.l1.go = "RevengeCap_inDeck_3";
		break;
		case "RevengeCap_inDeck_3":
			dialog.text = "�����������, �������, ��� �� �����?!";
			link.l1 = "����� ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "RevengeCapCap_inDeck_exit";
			npchar.DeckDialogNode = "RevengeCapCap_inDeck_exit";
			npchar.quest.SeekCap = "womanRevengeFight"; //���� ������ ��� ������ � ���������� �� ��������
		break;
		case "RevengeCapCap_inDeck_exit":
			dialog.text = "� ������ �� ���� �������� �� ��� ����, �������. ��� ������.";
			link.l1 = "��, ��� ������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "RevengeCapCap_exit";
		break;
		case "RevengeCap_board": //�������
			dialog.text = "��� ����������, ���� ������?! ����� �� ������ �� ��� �������?!";
			link.l1 = "�� ��������� "+ GetSexPhrase("����� ����,","�������") +" �� ����� " + GetFullName(&characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)]) + ". ��� ����� ��� �������?";
			link.l1.go = "RevengeCap_board_1";
		break;
		case "RevengeCap_board_1":
			dialog.text = "������!!! �������� �� ����..."+ GetSexPhrase(""," ���� ������� ����� ������ ������!") +"";
			link.l1 = ""+ GetSexPhrase("� ��������.","������ ���� ����� �������� �� ���� ������ �������!") +"";
			link.l1.go = "RevengeCap_board_2";
		break;
		case "RevengeCap_board_2":
			dialog.text = "�� ��� ��, � ��� ������ ������� �� �������. �� �������� �������, �� �������� ��� ���. "+ GetSexPhrase("�� ���������� ","� �������� ") +"���� ����� � ���� ���-���� ��������� �� ��� ����!";
			link.l1 = "����������, ��� � ��� ���� �������?..";
			link.l1.go = "RevengeCap_board_3";
		break;
		case "RevengeCap_board_3":
			LAi_SetCurHPMax(npchar);
			//==> ���� ������ ������ � ������������� ����
			characters[sti(npchar.baseCapIdx)].quest.SeekCap = "womanRevengeFight"; 
			QuestAboardCabinDialogFree(); // ������ �����
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//========= ���������� ���� �� ��������� ��������� =========
		case "PiratesCap_inDeck": //������� �� ������
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "��� ������ ��� � ���� �� ������. � ���-�� ���� ������ ���?";
			link.l1 = "��������, ��. � ��� ��������, �� ����� " + sld.quest.SeekCap.name + " " + sld.quest.SeekCap.lastname + ".";
			link.l1.go = "PiratesCap_1";
		break;
		case "PiratesCap_inDeck_1":
			dialog.text = "���� ������� - ��� �������, � � �������� �������� �� ���� ������� �����.";
			link.l1 = "� ���� ��� ��������.";
			link.l1.go = "PiratesCap_inDeck_2";
		break;
		case "PiratesCap_inDeck_2":
			dialog.text = "�������, �� ��� ����������. ���� ��� ���, �� � ����� ��� �������� ��� �������.";
			link.l1 = "������, �������, ��� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PiratesCapCap_exit";
			npchar.DeckDialogNode = "PiratesCapCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		case "PiratesCapCap_exit":
			dialog.text = "�� ��� �������� � ���� ��������. ������ �� ����������.";
			link.l1 = "�������...";
			link.l1.go = "exit";
		break;
		case "PiratesCap": //������� �� ����
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "�����������, �������. � ���-�� ���� ��� ������?";
			link.l1 = "��������, ��. � ��� ��������, �� ����� " + sld.quest.SeekCap.name + " " + sld.quest.SeekCap.lastname + ".";
			link.l1.go = "PiratesCap_1";
		break;
		case "PiratesCap_1":
			dialog.text = "���� ������� - ��� �������, � � �������� �������� �� ���� ������� �����.";
			link.l1 = "� ���� ��� ��������.";
			link.l1.go = "PiratesCap_2";
		break;
		case "PiratesCap_2":
			dialog.text = "�������, �� ��� ����������.";
			link.l1 = "����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PiratesCapCap_exit";
			npchar.DeckDialogNode = "PiratesCapCap_exit";
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "5");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(npchar.Ship.Type)].BaseName + "Gen")));
		break;
		case "PiratesCap_Board": //�������
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			dialog.text = "������! ������ �����?!!";
			link.l1 = "��� ����� ���� �������, �� ����� " + sld.quest.SeekCap.name + " " + sld.quest.SeekCap.lastname + ".";
			link.l1.go = "PiratesCap_Board_1";
		break;
		case "PiratesCap_Board_1":
			dialog.text = "��! �� �� ���, ������ ����� ��� ����...";
			link.l1 = "��� ��� ����� ������.";
			link.l1.go = "PiratesCap_Board_2";
		break;
		case "PiratesCap_Board_2":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree(); // ������ �����
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "CitizSeekCap_afterCabinFight");
			pchar.GenQuest.CitizSeekCap.label = npchar.quest.SeekCap; //���� ������ ��� ���
			pchar.GenQuest.CitizSeekCap.nation = npchar.nation;	//����� ��� ���
			pchar.GenQuest.CitizSeekCap.model = "citiz_"+(rand(9)+11); //������ ��� ���
			pchar.GenQuest.CitizSeekCap.sex = "man";
			pchar.GenQuest.CitizSeekCap.ani = "man";
			pchar.GenQuest.CitizSeekCap.WifeCity = npchar.quest.cribCity; //�������� ����� ��� ���
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			pchar.GenQuest.CitizSeekCap.WifeName = sld.quest.SeekCap.name; //��� � ������� ��� ���
			pchar.GenQuest.CitizSeekCap.WifeLastname = sld.quest.SeekCap.lastname;
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//========= ������� ��� ===========
		case "womanPirates_Board":
			dialog.text = "��� ��?";
			link.l1 = "� ������� " + GetFullName(pchar) + ". �� �� ����������, � ����"+ GetSexPhrase("��","��") +" �� ���� ��� ����, ����� ������� � ����.";
			link.l1.go = "womanPirates_Board_1";
		break;
		case "womanPirates_Board_1":
			dialog.text = "���� ������, ������� ��� �� ���?!";
			link.l1 = "������ ���, ��� �� ���... �� ��� ��, ���� �������, ������ ������ ������.";
			link.l1.go = "exit";
			//������ ���� �� �����
			npchar.location = "none";
			npchar.location.locator = "";
			LAi_SetPlayerType(pchar);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sld = &characters[GetCharacterIndex("QuestCitiz_"+npchar.quest.cribCity)];
			sld.quest.SeekCap = sld.quest.SeekCap + "over"; //��������� ���� ����� �� '��������'
			sTitle = npchar.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
			AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "6");
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony"+npchar.quest.cribCity+"Acc"));
		break;
		
		case "plantation_slave":
			if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && findsubstr(npchar.id, "Slave_" , 0) != -1)
    		{
				dialog.text = RandPhraseSimple(RandPhraseSimple("� ��� ����� - ������ � ��� ������.", "��� ������ ��� ��� ����!"), RandPhraseSimple("��� ������ ������� ������� ��� ����.", "������������ ��� �� �������� ������ ����� �� ���� �����!"));				
				link.l1 = RandPhraseSimple("����������, ��������.", "��� ���� ����.");
				link.l1.go = "exit";				
    		} 
		break;
		
		//=====================================================================================================================================
		// Warship, 25.05.11. && Jason 10.02.12 ����� ����������� "���� �����" -->
		//=====================================================================================================================================
		case "AffairOfHonor_1":
			LAi_CharacterDisableDialog(NPChar);
			
			if(LoadedLocation.type == "tavern")
			{
				// "����� �������".
				if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.CoatHonor"))
				{
					dialog.text = "�, �������, ������� �� ����, � ������!";
					link.l1 = "� �������������.";
					link.l1.go = "AffairOfHonor_CoatHonor_1";
					PChar.QuestTemp.AffairOfHonor.CoatHonor = true;
					break;
				}
			}
			else
			{
				if(NPChar.sex == "man")
				{
					// "��������� �����".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.HonorSlave"))
					{
						dialog.text = "������������, �������. �� ���� �������, �, ���� �� ��������, �������� ���� �������?\n��, ��, ���-�� �� ��������� �������� ��� ������������ ������, � ������� �� ����� ���������� ����, �������, � ���� ��, ������� ������ ������ �������... � ��� ��-�� ����� ����������� ��������, ����������� ���� �� �������������� ����� ������� ���� ����!";
						link.l1 = "��, � � ������ - �������, � ��� ����� �� ��� �������� ����, �� ��� ��� ������? �����������!";
						link.l1.go = "AffairOfHonor_HonorSlave_1";
						PChar.QuestTemp.AffairOfHonor.HonorSlave = true;
						break;
					}
					
					// "�������� � �����".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.BeautifulPirate"))
					{
						dialog.text = "������������, �������. ��������� ���������������� � ��, ��������, �� �����? ���� ���, ������� ��, ���! �� �� �����. ������ - ��� ������ ��������, � ��� ������� ����� ����, � �����...";
						link.l1 = "��� ������ ��� ������ ������� ������?";
						link.l1.go = "AffairOfHonor_BeautifulPirate_1";
						PChar.QuestTemp.AffairOfHonor.BeautifulPirate = true;
						break;
					}
					
					// "���������� �����".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.Jackanapes"))
					{
						//if(NPChar.city == "PortRoyal" || NPChar.city == "Havana" || NPChar.city == "Villemstad" || NPChar.city == "FortFrance")
						//{
						// Jason: ��� �� ������ �������? ���� - �������? ����� ������, ����� ����� ����� �� ������� - ��������� ������ ���������� �������. ������. ��������� ������������ ����� �������.
							dialog.text = "��, ��! �� � ��, �������, ��� ��� ������� �������? ������ ������� �� ������� ����� ������� ������ � ������� ��� ������? ���, �� ���������, ��� �� ������! � � ��� ���������! ������!.. ��������� ���!";
							link.l1 = "������, �, �����, �� ����� ���� ��� �������. ��������.";
							link.l1.go = "AffairOfHonor_Exit";
							link.l2 = "������, �������! ����� �� �������� �� ������� ����, ���� ��� �������.";
							link.l2.go = "AffairOfHonor_Jackanapes_1";
							PChar.QuestTemp.AffairOfHonor.Jackanapes = true;
							break;
						//}
					}
					
					// "����� � ����".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.WolvesAndSheeps"))
					{
						dialog.text = "������������, �������. � ���� � ��� �������, � ���������� ������� �� �� ������� ��� ��������, ���� �� ������� �������\n����, ����� � ����: �������� � ����� ���� � ��� � ������� ����������� �����-�� ��������. ��, ����������� � �����, ������ �������� ���� �������� �� ���� ����� ��� �� �� ���� ������� � �������! � ������ ��� � ������!";
						link.l1 = "���� �� �� ���� ���������� ��������, �� ������ ��������� ��� ���� �� � ���������, ������ ���� � ������������� ���������. ����� �� ���?";
						link.l1.go = "AffairOfHonor_WolvesAndSheeps_1";
						PChar.QuestTemp.AffairOfHonor.WolvesAndSheeps = true;
						break;
					}
					
					// "��������� �����������".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.CowardFencer"))
					{
						dialog.text = "�������, ��������, ����� ���. ��, ���� �� ����� ��������, ������� ����� ��� � ������������ �� ���� ��������� ��������� �������� ������, ������� � � ��������� ������� ��� ��������� ���� ���������, ������� �� � ��������� ��������� ���.";
						link.l1 = "������ �������. � ��� �� ����� �� ��� ����������� ����������?";
						link.l1.go = "AffairOfHonor_CowardFencer_1";
						PChar.QuestTemp.AffairOfHonor.CowardFencer = true;
						break;
					}
					
					// "����� ���".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.GodJudgement"))
					{
						dialog.text = "��������, ����� ���! ������... �� ����������� �� �� ������ ���, �����������, � ����� ����, ������� ������� ������������� ������ ������� �������� �������, ��� ��?\n���� � ���, ��� � ��������� ��-�� ������� ��������� ��������� �� ����� �������, �������, � ����� ������, ������������� � ������ � ����������������. ��, ��, � ����� � � ��������, ������ � ���, ����� ������ � ���� �������� ��������� �� ������� �����?\n��� �����-�� ��� ����� �� �� ���� ������� �� ������� ������ �������, � ������ ���������� �� ��� ������������, ������� � ���!..";
						link.l1 = "��� ��� �� ����� �������� ����. ��������.";
						link.l1.go = "exit";
						link.l2 = "���������, � ���� ������� ������� ������?";
						link.l2.go = "AffairOfHonor_GodJudgement_1";
						PChar.QuestTemp.AffairOfHonor.GodJudgement = true;
						break;
					}
				}
				else
				{
					// "���������� �������".
					if(!CheckAttribute(PChar, "QuestTemp.AffairOfHonor.Cavalier"))
					{
						dialog.text = "�������, �������, ����� � �������� ����� �������� �������!";
						link.l1 = "� ���� ��� �� ��� �������, ��������. ����� ����-������ ���...";
						link.l1.go = "AffairOfHonor_Exit";
						link.l2 = "��� ���������, �������? �� �� ����� �� ���! �����������!";
						link.l2.go = "AffairOfHonor_Cavalier_1";
						PChar.QuestTemp.AffairOfHonor.Cavalier = true;
						break;
					}
				}
			}
			
			dialog.text = "����� ���. � ������ �� ������ ��� �������? �������� �� ���� Warship'�, �� ��� ��������.";
			link.l1 = RandSwear();
			link.l1.go = "exit";
		break;
		
		case "AffairOfHonor_Exit":
			ChangeCharacterComplexReputation(PChar, "nobility", -2);
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
		
		case "AffairOfHonor_Cavalier_1":
			dialog.text = "�������, ���� ��� �������� ����� ���������� ���� �� �������� ������ ��������� � ���������������� �������� � �������������. ������� �� ��, ����� ������������ ����� �� ��������������, ������� �������� ���� � ������ �������!\n� ���������, � ���� ��� �������� � ������, ��������� �������� ��� ������� ���! � � ��������! �, ����, � ��� � ��! �������� ���!";
			link.l1 = "�� ��������, � �� ��� ���� � �����!";
			link.l1.go = "exit";
			int Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+12;
			int Scl = 30+2*sti(pchar.rank);
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_Cavalier_Man", GetRandQuestSoldierModel(sti(NPChar.nation)), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			// Jason: ������� ��� �� ����� - ������ ����������
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_12","blade_14"), RandPhraseSimple("pistol6","pistol5"), "bullet", Scl*3);
			float Mft = MOD_SKILL_ENEMY_RATE/20;
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			ChangeCharacterAddressGroup(sld, PChar.location, "goto", FindNearestFreeLocator("goto"));
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, PChar, "", -1, 5);
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "AffairOfHonor_Cavalier_2";
			PChar.QuestTemp.AffairOfHonor.Cavalier.Started = true;
			DisableAllExits(true);
		break;
		
		case "AffairOfHonor_Cavalier_2":
			dialog.text = "�, ��� � ��, ��������! ���, ��������� ���������, ��� � �������? ����� �� �� �����������, �������? ��������, �������... �������� �������� � �������, ��� ��� ����� �����...";
			link.l1 = "������, ���������� ����������� ����, ����� � �������� ��� ��� �������!";
			link.l1.go = "AffairOfHonor_Cavalier_2a";
		break;
		
		case "AffairOfHonor_Cavalier_2a":
			dialog.text = "��... ��� ��� ��� � ���? �-�, ����������� ����� �������� ������� �������, ���? � ��� �� ��������, �������... ���?";
			link.l1 = "��� ���� - ��� �������! � ��� ��� � ���� �������� ���� ��������� �� ����!";
			link.l1.go = "AffairOfHonor_Cavalier_3";
		break;
		
		case "AffairOfHonor_Cavalier_3":
			dialog.text = "���?! �� ����������� ������� ���� �� ����� ��-�� ����...";
			link.l1 = "��������! ��� ��� ����� ��� ���� � �����. � �� �������� ���������� � ����� �����!";
			link.l1.go = "AffairOfHonor_Cavalier_4";
		break;
		
		case "AffairOfHonor_Cavalier_4":
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			DisableAllExits(false);
			LAi_ActorGoToLocation(NPChar, "reload", FindNearestFreeLocator("reload"), "none", "", "", "", 3.0);
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft", 0, 0, 0, GetHour() + 3, false);
			// Jason: �������� �� 2 ���� ��� ��������������
			SetFunctionTimerConditionParam("AffairOfHonor_LighthouseGotoMeeting", 0, 0, 0, GetHour()+2, false);
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "1");
		break;
		
		case "AffairOfHonor_Cavalier_5":
			dialog.text = "��, � ��� ����, ������! �� ���� �� �������������, ��� � ��� ����������! �� ������ ��� �������! ";
			link.l1 = "� ���, ��� �������� ����� � ���� ��� ������. ������ ���������!";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(PChar, "nobility", 7);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			ChangeOfficersLoyality("good_all", 1);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 300);
			AddCharacterExpToSkill(pchar, "Fortune", 100);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_Cavalier_6":
			dialog.text = "��, �� ������ �� ����� ���������, �������� ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_HonorSlave_1":
			sTemp = "";
			if (FindLocation(NPChar.city + "_brothel") != -1) sTemp = "��� ������� ";
			dialog.text = "��, "+GetAddress_Form(NPChar)+"... �� ���� ���������, �� ��������, �� ���� ��� ���� ����� ������� � ���� �����?\n��� � � �������, ��� ��� - �� �� �������, � ��� �������� ������ �� �������� ��� ��������� �������. ��, ���� �� ����� �� ���� �������� ���� � ����� �����\n�� �� �� ��� �� ������� ���� ����� � ������ �������, ���������? � � ��������, ���� ��� ��� ������������ ��� � ���������, ������� � ����� ��� � �������� �������, ���������� ����� ����� ���� ������, ��� �������� ����, � � �� �������� � �����, �� ��������!\n�� ������� �������� � ������� "+sTemp+"� ���, ��� � �������� ��������� ����� ����� �������, ��� ��... ������ ���...";
			link.l1 = "��������, ��� ���������� ��� ���� �� �� ���, �� �� ������ ����. ����� ������!";
			link.l1.go = "exit";
			link.l2 = "��. ��� ������ ���! ������, ���������, ��� �� ����� ������...";
			link.l2.go = "AffairOfHonor_HonorSlave_1a";
		break;
		
		case "AffairOfHonor_HonorSlave_1a":
			dialog.text = "�� ������ �������� ��� � ����� ������� ����? �, "+GetAddress_Form(NPChar)+"! � ���� �������� �� ��� � ���� �����!";
			link.l1 = "�����, ��� ��� �� ��������...  �����!";
			link.l1.go = "AffairOfHonor_HonorSlave_2";
		break;
		
		case "AffairOfHonor_HonorSlave_2":
			DialogExit();
			Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+8;
			Scl = 30+2*sti(pchar.rank);
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_HonorSlave_Man", "citiz_" + (rand(9) + 41), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			// Jason: ������� ��� �� ����� - ������ ����������
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_04","blade_06"), RandPhraseSimple("pistol1","pistol5"), "bullet", Scl*3);
			Mft = MOD_SKILL_ENEMY_RATE/20;
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			if(rand(1) == 0 || FindLocation(NPChar.city + "_brothel") == -1)
			{
				FreeSitLocator(NPChar.city + "_tavern", "sit_front1");
				ChangeCharacterAddressGroup(sld, NPChar.city + "_tavern", "sit", "sit_front1");
				LAi_SetSitType(sld);
			}
			else
			{
				ChangeCharacterAddressGroup(sld, NPChar.city + "_brothel", "goto", "goto3");
				LAi_SetCitizenType(sld);
			}
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "AffairOfHonor_HonorSlave_3";
			SetFunctionTimerCondition("AffairOfHonor_TimeIsLeft", 0, 0, 1, false);
			PChar.QuestTemp.AffairOfHonor.HonorSlave.Started = true;
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "3");
		break;
		
		case "AffairOfHonor_HonorSlave_3":
			dialog.text = "��� ��� ������, ���� ������? � �������, � �� ���� ����� ��� ������. ��� ����� ��������� ���� � ��������� ����, ��� ��� �������� ���� � �����, ������!";
			link.l1 = "��� �� �����, �������� �������� ���� ����� �� ������ ������.";
			link.l1.go = "AffairOfHonor_HonorSlave_3a";
		break;
		
		case "AffairOfHonor_HonorSlave_3a":
			dialog.text = "���?! �� ��� �� �����, ����� ��������� ���, ��� ������?!";
			link.l1 = "�� ����� ����, �? � ��� � ���� - ���!.. � � ������, ��� ����� ��������, ��� ��, ���� ���������� ���������� ���� ����� ����� ������������!";
			link.l1.go = "AffairOfHonor_HonorSlave_3b";
		break;
		
		case "AffairOfHonor_HonorSlave_3b":
			dialog.text = "�?! �����, �� ��, ������, ���� � �������! � ���� ������� ����! �� � �� ������� ������� ��������! ��� ���� ��������� ���� ������ ���� ������ �����! ���������� ��������, ������� ��������, � � ��� � ����, ������ ���� ������� �����!";
			link.l1 = "���������� ����� ���������� ������, � �� ����� �������� ��������!";
			link.l1.go = "AffairOfHonor_HonorSlave_4";
		break;
		
		case "AffairOfHonor_HonorSlave_4":
			dialog.text = "�� ��� ���! �� �����������, ���� ���������?";
			link.l1 = "� ������ ��� ����� ���� � ������, ��������! ��� ���� �� ����� ����� ��� ����, � �� ������ ���������� � ����� ������ �������, ������� �������� � ���� �� �����!";
			link.l1.go = "AffairOfHonor_HonorSlave_5";
		break;
		
		case "AffairOfHonor_HonorSlave_5":
			dialog.text = "��! � ���� ���!";
			link.l1 = "�� ������ �������!";
			link.l1.go = "AffairOfHonor_HonorSlave_6";
		break;
		
		case "AffairOfHonor_HonorSlave_6":
			DialogExit();
			LAi_CharacterDisableDialog(NPChar);
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			// Jason: �������� �� 2 ���� ��� ��������������
			SetFunctionTimerConditionParam("AffairOfHonor_LighthouseGotoMeeting", 0, 0, 0, GetHour()+2, false);
			AddQuestRecord("AffairOfHonor", "3_1");
		break;
		
		case "AffairOfHonor_HonorSlave_7":
			dialog.text = "�, ��� ��! ���� �� ����, �� � ���� ������������, ���...";
			link.l1 = "��, � ���, � ��� ��� ������ ����� ����� ������ �� �������.";
			link.l1.go = "AffairOfHonor_HonorSlave_8";
		break;
		
		case "AffairOfHonor_HonorSlave_8":
			dialog.text = "����� ������� ������� ����! �����, ������� �������!\n�������, ���� ���������� �������� ��� ��� �� ������. ���, �������� ��� ������ ������ � ����������� �������������� �� ����� ������ ���������!";
			link.l1 = "�������!";
			link.l1.go = "exit";
			iTemp = 50+drand(5)*10;
			TakeNItems(pchar, "gold_dublon", iTemp);
			Log_Info("�� �������� "+FindRussianDublonString(iTemp)+"");
			PlaySound("interface\important_item.wav");
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_HonorSlave_9":
			dialog.text = "�����, ������ �����!";
			link.l1 = "...";
			link.l1.go = "exit";
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_BeautifulPirate_1":
			dialog.text = "���? ����� ������� � ������, �� ��� ���� ������ ������� ������� ������. ��� ������������ � �������\n� ��� �� ������, �� � ��������� ����� ��������� ����������� � ���� ������� ���� ����� �������� ����. �� ������� �����! ��� ����� ����� �� ����� ��� ��� � ������, �� ������. � ���� ����, ��� ��� ��� ������ �� ����, ��������� � ����������� � ������ ��������� �������, ��� ��������� �������� ���, ��� ������ ��� � ������ ������� ���, ��� �� �������� ������� �� � ������ ���� ����� ���� �� ����� �������, ���� ��� ��������� ��������� ��� ���������� �����������!\n� �� ����, ��� ������! ������� ����������� ������ �����-�� ��� ��������, � ��, ������ ���������, ������ ����� ������. �������� ��� ��������� ������� �� �����, ����� ���!";
			link.l1 = "� ���� ��� ������� ����������� ������ �� ��������. ���������� � ����������, ��� ��� ������.";
			link.l1.go = "exit";
			link.l2 = "��... ������� �����? ������, � ���������, � ��� ��� ����.";
			link.l2.go = "AffairOfHonor_BeautifulPirate_1a";
		break;
		
		case "AffairOfHonor_BeautifulPirate_1a":
			dialog.text = "��, �������, �������! � ������, ��� �� ��� ���������, ��� ����� ������! �������� ���, ����� �� ������ �� ���� ������ ��� � ��������! �� ��������, �� �� ��������� � �����!";
			link.l1 = "�����-�����... ��� ��� ��������� ���� ��������. �����!";
			link.l1.go = "AffairOfHonor_BeautifulPirate_1_1";
		break;
		
		case "AffairOfHonor_BeautifulPirate_1_1":
			DialogExit();
			NextDiag.CurrentNode = "AffairOfHonor_BeautifulPirate_r";
			npchar.lifeday = 3;
			Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+12;
			Scl = 25+3*sti(pchar.rank);
			Mft = MOD_SKILL_ENEMY_RATE/15;
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_BeautifulPirate_Man", "mercen_" + (rand(9)+1), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			// Jason: ������� ��� �� ����� - ������ ����������
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_10","blade_13"), RandPhraseSimple("pistol6","pistol4"), "bullet", Scl*3);
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			FreeSitLocator(NPChar.city + "_tavern", "sit_front1");
			ChangeCharacterAddressGroup(sld, NPChar.city + "_tavern", "sit", "sit_front1");
			LAi_SetSitType(sld);
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "AffairOfHonor_BeautifulPirate_2";
			SetFunctionTimerCondition("AffairOfHonor_TimeIsLeft", 0, 0, 1, false);
			PChar.QuestTemp.AffairOfHonor.BeautifulPirate.Started = true;
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "5");
		break;
		
		case "AffairOfHonor_BeautifulPirate_r":
			dialog.text = "�� ���? �� ��� �������� � ���� �������? �� ������� ��� � �����?";
			link.l1 = "�����. � ������� ��� ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AffairOfHonor_BeautifulPirate_r";
		break;
		
		case "AffairOfHonor_BeautifulPirate_2":
			dialog.text = "��� ����? �� ������, � �����������!";
			link.l1 = "���-���... ������, ��� � ���� ���������� ������ ������, ���������� �������, ����� ������� ����������� ��������, ��� � �������? � �� �������, ��������, � �����, �� �����, �� ��� �� ������ � ����������, ��� ����� � �������?";
			link.l1.go = "AffairOfHonor_BeautifulPirate_2a";
			DeleteQuestCondition("AffairOfHonor_TimeIsLeft");
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft2", 0, 0, 0, GetHour() + 3, false);
		break;
		
		case "AffairOfHonor_BeautifulPirate_2a":
			dialog.text = "�-��-��! �� ��, � ��������, �����! �����, ��������, � ������� ������, ��� ��� ������ ����. �����-��, ���� ��� ���� ���� ���!";
			link.l1 = "�� ��� �� ��������!.. �������� ��� ����� ������������: �� ����� �� ��� �� �����, ��� � �� ������?";
			link.l1.go = "AffairOfHonor_BeautifulPirate_3";
		break;
		
		case "AffairOfHonor_BeautifulPirate_3":
			dialog.text = "��� ���, �����?! ���� ������ � ������� ���������? ������, ��� �� ��� ����� �����������, � ���������� � ����� � ��� ������ ���� �����, � ����� ������� ���� � ������� ��� ������� ������� ���������!";
			link.l1 = "���������, �� ���������� �� ����� � �����!";
			link.l1.go = "AffairOfHonor_BeautifulPirate_4";
		break;
		
		case "AffairOfHonor_BeautifulPirate_4":
			DialogExit();
			LAi_CharacterDisableDialog(NPChar);
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			SetFunctionLocationCondition("AffairOfHonor_LighthouseLocEnter", PChar.QuestTemp.AffairOfHonor.LighthouseId, false);
		break;
		
		case "AffairOfHonor_BeautifulPirate_5":
			dialog.text = "�� ���? �� ��� �������� � ���� �������? �� ������� ��� � �����? ������ �������, ��� �� ���� �� ������� � �� ��������...";
			link.l1 = "���������. �� �������� ������ �����, �� ��� ��������� ��������� �������������. ����� ������ ������ ������ �� ��������.";
			link.l1.go = "AffairOfHonor_BeautifulPirate_6";
		break;
		
		case "AffairOfHonor_BeautifulPirate_6":
			dialog.text = "��?.. �� ����� ��������� ��������? ������� ��������, �������! � ���... ��� ���� �������?";
			link.l1 = "��... � ���� �� �������. �� ����� ����� � ���� � ������ �� ��������.";
			link.l1.go = "AffairOfHonor_BeautifulPirate_7";
		break;
		
		case "AffairOfHonor_BeautifulPirate_7":
			dialog.text = "�� ������� �������� ������ ���� ������� ������� ����� �������! ���, �������� �������������� �� ���� ������. ��� ��������, �� ����� ���� �� �������� ������ � �������� ���� ���� ��������, � ��, ��������, ������!";
			link.l1 = "�������������! ����� ��� � ����� ������. ����� �� �������� ����� ����� �� ���������� ��������. ��������!";
			link.l1.go = "exit";
			iTemp = 50+drand(5)*10;
			AddMoneyToCharacter(pchar, iTemp*100);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_Jackanapes_1":
			dialog.text = "�������? � ��� �� �� ���������� ��� ��������?";
			link.l1 = "������ - ������������ ��������, ���������� ��� ������ �������, ��� ��.";
			link.l1.go = "AffairOfHonor_Jackanapes_1_1";
		break;
		
		case "AffairOfHonor_Jackanapes_1_1":
			dialog.text = "���������! � ��� ��� ����� ��� ���� � �����, ��� � ��� �������� ����� �����������.";
			link.l1 = "�������! � ���� ����������.";
			link.l1.go = "AffairOfHonor_Jackanapes_1_2";
		break;
		
		case "AffairOfHonor_Jackanapes_1_2":
			DialogExit();
			PChar.QuestTemp.AffairOfHonor.Jackanapes.Started = true;
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			NPChar.id = "AffairOfHonor_Jackanapes_Man";
			LAi_SetImmortal(NPChar, true); // ��� ������.
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft", 0, 0, 0, GetHour() + 3, false);
			// Jason: �������� �� 2 ���� ��� ��������������
			SetFunctionTimerConditionParam("AffairOfHonor_LighthouseGotoMeeting", 0, 0, 0, GetHour()+2, false);
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "7");
		break;
		
		case "AffairOfHonor_Jackanapes_2":
			dialog.text = "����� � ������, ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_1":
			dialog.text = "�������, �� �� ��� �����, ���� �������. ���, ��� ������ ���� ���, �������� ����� �� ����� �� ��� ����, ���������� � ��������� �� ��������� ������! ��� �� ������, ��� ������� ����������...";
			link.l1 = "��... ���� ���� ������� ��� � ������ ����, ����� ���������� � ������, ����� �� ����� ���� ������.";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_2";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_2":
			dialog.text = "��? � ��� �� ������� �� ��, ��� ����� ��� �������, ��� ���, �� ��������� ���� ������ � ��� � ������� ��������� ��� �������? � ��� ������� �������� ������ ������ ���������? ��� ��� ��� � ��� �����: �����-�� � ���� ��� ���� ���������, �� �������� ��� �� �����. � ���� �� ������ � ��������� ����.";
			link.l1 = "���������? ���, � �� ����� ��������� ����. ��� ����.";
			link.l1.go = "exit";
			link.l2 = "�������, � ��� � ��������... �� ����� �������� �������� ��� �������.";
			link.l2.go = "AffairOfHonor_WolvesAndSheeps_3";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_3":
			dialog.text = "�������, � � ��������� ���� ������ ������� ����� �����, ������� � ������������� �������� ����, ��� ������ ������� ����� ��������� �� ������ ���� � ��������� �� ��� ��� ���������. � ���� ����� ��� � ������, ����� ������ ��� ���� ��������������, ����� �� ��������� ��� �������.";
			link.l1 = "� ������ ���, ���� ���� ����� �������� �������.";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_4";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_4":
			DialogExit();
			PChar.QuestTemp.AffairOfHonor.WolvesAndSheeps.Started = true;
			npchar.lifeday = 3;
			// Jason: ������� ��� �� ����� - ������ ����������
			Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+10;
			Scl = 30+2*sti(pchar.rank);
			Mft = MOD_SKILL_ENEMY_RATE/20;
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_WolvesAndSheeps_Man", "citiz_" + (rand(9)+1), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_08","blade_09"), RandPhraseSimple("pistol1","pistol5"), "bullet", Scl*3);
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			sld.skill.Fortune = 1;
			sld.Default = NPChar.city + "_tavern";
			sld.Default.group = "sit";
			sld.Default.ToLocator = "sit_front1";
			LAi_SetSitType(sld);
			ChangeCharacterAddressGroup(sld, NPChar.city + "_tavern", "sit", "sit_base1");
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "AffairOfHonor_WolvesAndSheeps_5";
			SetFunctionTimerCondition("AffairOfHonor_TimeIsLeft", 0, 0, 1, false);
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "9");
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_5":
			dialog.text = "��� ��������, ������! � ��� ����� ����� ����������� �������� �, ��������... �����? �� ������� �� ��������� ��� ������?";
			link.l1 = "��������! ������� ������. ��� ������� ��� 50 �����?";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_6";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_6":
			if(sti(PChar.money) < 200)
			{
				dialog.text = "�� ������? � ���� ���� ����� ���!";
				link.l1 = "� �������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "AffairOfHonor_WolvesAndSheeps_5";
			}
			else
			{
				dialog.text = "� ��� ��� ����� ����������� �������, � �� � ����� �������� �������� � ���� ��� ��������, ��� �������� �����.";
				link.l1 = "�� ��� ��, ����� ��������.";
				link.l1.go = "exit";
				PChar.QuestTemp.friend_in_tavern = NPChar.id;
				AddDialogExitQuest("alc");
				DeleteQuestCondition("AffairOfHonor_TimeIsLeft");
				SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft2", 0, 0, 0, GetHour() + 3, false);
				NextDiag.TempNode = "AffairOfHonor_WolvesAndSheeps_7";
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			}
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_7":
			dialog.text = "����, ������ �� 50 �����.";
			link.l1 = "...";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_8";
			PChar.GenQuest.Cards.npcharIdx = NPChar.index;
			PChar.GenQuest.Cards.iRate = 50;
            PChar.GenQuest.Cards.SitType = true;
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_8":
			NextDiag.TempNode = "AffairOfHonor_WolvesAndSheeps_9";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchCardsGame();
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_9":
			dialog.text = "���������, ��� ���?.. �� ����� ����! ������, �� � �����! ������� ��� �������� ���������� ���� ������!";
			link.l1 = "��� ������ ��������� ���������� ����� ������ ��������������, "+GetAddress_FormToNPC(NPChar)+"! ��� �� �� ���������� ��� ����� � ������, ��� �������� �������� �� �������, ��� � �������� � �� �����!";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_10";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_10":
			dialog.text = "��, ��� �� ���? ������ � �����! �������, ����� ��� ����, � �����!";
			link.l1 = "������!";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_11";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_11":
			AddDialogExitQuest("exit_sit");
			DialogExit();
			LAi_CharacterDisableDialog(NPChar);
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			// Jason: �������� �� 2 ���� ��� ��������������
			SetFunctionTimerConditionParam("AffairOfHonor_LighthouseGotoMeeting", 0, 0, 0, GetHour()+2, false);
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_12":
			dialog.text = "����� �������, �������?";
			link.l1 = "�� ��������� ����� � � ���� ������� ��������� � ���������, ����� ���� � ������� ��������� �� �����.";
			link.l1.go = "AffairOfHonor_WolvesAndSheeps_13";
		break;
		
		case "AffairOfHonor_WolvesAndSheeps_13":
			dialog.text = "��� ������, ������, � ����! ������� ��� �� ���� � ���� ������! ��� ���� �������, �������.";
			link.l1 = "��������� ���.";
			link.l1.go = "exit";
			iTemp = 50+drand(5)*10;
			AddMoneyToCharacter(pchar, iTemp*100);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(PChar, "nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 200);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_CowardFencer_1":
			dialog.text = "� ��� ������� ���, ��� ������ ���� � ������� �������� ����� ������� ����������? ���? ��� ���, � �������� ����������� ������� �������� ������� ��� ��� ����������, � � ����� ������ ��� �����, ����� ��� �������� ������ ����� ���������, ���� ������ � �� ���������� ��������� ��� �� ��������\n� ��� ��� ����������� ������ �� ���������, �� ��� ���������, ��� � �������� �������� ��������� ������������ � ���� ������-�� ������������ ���� ����������, � ����������, � ����� �������� ���� ���������������� �������, ������� ��� ������� ��� ������.";
			link.l1 = "��� � ����������, ��� ��� ���� ������. ����� ��������.";
			link.l1.go = "exit";
			link.l2 = "� ��� �� ����� ����� ���������� �� ��������, � ��� �� ����?";
			link.l2.go = "AffairOfHonor_CowardFencer_1_1";
		break;
		
		case "AffairOfHonor_CowardFencer_1_1":
			dialog.text = "� �����, ��� ���������� ��� � �������, � � �������� ��� �� �����? ������ �����, ��������, ��� ���� �����... �� ����� ����� � �������� �� ���������� � ��� �� ���� �������� � ����� �� �������. � ��� � � ����� ������� ��� ��� ������ ��������, ��������� ��� �� ����������� ��������, � ��� ����� � ��� ��������� ��������� �����������\n��� ����� ����� ��� �����, � ��� �������� �������� �, �����, ���� �� � �����. ����� ���, ��������, � � ����� ��� ��� ���� ����������, ����� ��� � ������� �������� �������� �����!";
			link.l1 = "������, ������, � ������... ������� ������ ��������...";
			link.l1.go = "AffairOfHonor_CowardFencer_1_2";
		break;
		
		case "AffairOfHonor_CowardFencer_1_2":
			DialogExit();
			npchar.lifeday = 3;
			// Jason: ������� ��� �� ����� - ������ ����������
			Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+15;
			Scl = 30+3*sti(pchar.rank);
			Mft = MOD_SKILL_ENEMY_RATE/15;
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_CowardFencer_Man", "mercen_"+(rand(7)+23), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_06","blade_10"), RandPhraseSimple("pistol4","pistol6"), "bullet", Scl*3+70);
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			LAi_SetCitizenType(sld);
			ChangeCharacterAddressGroup(sld, NPChar.city + "_store", "goto", "goto3");
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "AffairOfHonor_CowardFencer_2";
			SetFunctionTimerCondition("AffairOfHonor_TimeIsLeft", 0, 0, 1, false);
			PChar.QuestTemp.AffairOfHonor.CowardFencer.Started = true;
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "11");
		break;
		
		case "AffairOfHonor_CowardFencer_2":
			dialog.text = "��� ������? �� ������, ��� � �����?!";
			link.l1 = "��� ��� �� �� ����� ����� ����� ���������� �������� � ����������� ���������������?";
			link.l1.go = "AffairOfHonor_CowardFencer_3";
			DeleteQuestCondition("AffairOfHonor_TimeIsLeft");
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft2", 0, 0, 0, GetHour() + 3, false);
		break;
		
		case "AffairOfHonor_CowardFencer_3":
			dialog.text = "��! ��� ���� ��������? ������� ������ ��������� ���, ��� ��������� �������� ������. ������� ���������, � ������� �� ��������� ������, � ��������� � ������� ��������, ������� ���� �� ����� �����, ��������� ������� � ����� � ���, �� �����, �� ��������� ��� ����, � ���� ��� � ���������� � �� ������� ��� �������� ����.";
			link.l1 = "������������! � ���� ��� ����� � �����������.";
			link.l1.go = "AffairOfHonor_CowardFencer_4";
		break;
		
		case "AffairOfHonor_CowardFencer_4":
			DialogExit();
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			SetFunctionLocationCondition("AffairOfHonor_LighthouseLocEnter", PChar.QuestTemp.AffairOfHonor.LighthouseId, false);
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_CowardFencer_4_1":
			dialog.text = "�� �� ����������� ���� ������� �����...";
			link.l1 = "��� ����, �� ����.";
			link.l1.go = "exit";
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		case "AffairOfHonor_CowardFencer_5":
			dialog.text = "����� �������, �������?";
			link.l1 = "������� �����. ������� ����� ������ ����?";
			link.l1.go = "AffairOfHonor_CowardFencer_6";
		break;
		
		case "AffairOfHonor_CowardFencer_6":
			dialog.text = "�, �������, � ��� �������� ����������! �������� ���� �������, � � ������� � ����������� � ��������!";
			link.l1 = "��������... �������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(PChar, "nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 1);
			AddComplexSelfExpToScill(60, 60, 60, 60);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 200);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(NPChar);
			GiveItem2Character(pchar, "chest"); 
			Log_Info("�� �������� ������ � ���������");
			PlaySound("interface\important_item.wav");
		break;
		
		case "AffairOfHonor_CoatHonor_1":
			LAi_CharacterEnableDialog(NPChar);
			NextDiag.TempNode = "AffairOfHonor_CoatHonor_2";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			PChar.QuestTemp.friend_in_tavern = npchar.id;
			AddDialogExitQuest("alc");
		break;
		
		case "AffairOfHonor_CoatHonor_2":
			dialog.text = "��� �� �����?";
			link.l1 = "�������.";
			link.l1.go = "AffairOfHonor_CoatHonor_2_1";
		break;
		
		case "AffairOfHonor_CoatHonor_2_1":
			dialog.text = "� ���!..";
			link.l1 = "��������! �� ���� �� �� ��� ����������?";
			link.l1.go = "AffairOfHonor_CoatHonor_2_2";
		break;
		
		case "AffairOfHonor_CoatHonor_2_2":
			dialog.text = "� ����� �������! ������!";
			link.l1 = "������, �� ����� �� ��� ���-���� ���������� ��� � ���� ���������?";
			link.l1.go = "AffairOfHonor_CoatHonor_2_3";
		break;
		
		case "AffairOfHonor_CoatHonor_2_3":
			dialog.text = "��� ������ ���������? ����� ��������, ���� � ��� ���� ��������! ����� ���� ���� � ��� ������ �� ��������, ������ ��� ���� �����... ��, �����! � ����� ����� ���. ����� ���� � ����... ���� ������, �������� ��� ������, ��� �����, ������ � ��� ����� �� ��� ������!\n�������, ���� �� � �� ����� ����� �������, �� �� �������� �� � ����� � ������ ������ ����� ���������, �� �, �������, ����� ������. �� ��� ������? � �������, � ������, � ����! ��� �����...";
			link.l1 = "��, �����. �� ������ �� ��������� ������ ����� ���� �����, ����, �������, ���������� � �����. ��������.";
			link.l1.go = "AffairOfHonor_CoatHonor_Exit";
			link.l2 = "�� ����� ����� ���������� ����������. ��������� ���� �����-���� �����!";
			link.l2.go = "AffairOfHonor_CoatHonor_2_4";
		break;
		
		case "AffairOfHonor_CoatHonor_2_4":
			dialog.text = "�����? �������������, ������� ������� ��� � ������ �������, ��� ������� ������, �� ���������, ���� ���� �������� ��� ������? ��� �� ��� �����������?";
			link.l1 = "�� ��, �� ������. � ��� ������ � �������� ������� ���, ��� ��� ��������� �� ������ ������� ��� ����� � �����, ������������ ��� �����. ��� ��� ������ ���?";
			link.l1.go = "AffairOfHonor_CoatHonor_2_5";
		break;
		
		case "AffairOfHonor_CoatHonor_2_5":
			dialog.text = "�� ��������? �� �������� ���! �, ������� ������, � � ����� �� ��������!\n� ����� ��� ����� � ������. ��� ����� ��� ���������, � ������� ������������ ������� ��� ������� ���������, �� �� ����� ��� ����������, � ���������...";
			link.l1 = "����� ����������. ����� ���� �����. �����, ��������� � �����... ������ ������.";
			link.l1.go = "AffairOfHonor_CoatHonor_3";
		break;
		
		case "AffairOfHonor_CoatHonor_Exit":
			DialogExit();
			AddDialogExitQuest("exit_sit");
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "AffairOfHonor_CoatHonor_3":
			AddDialogExitQuest("exit_sit");
			NextDiag.CurrentNode = "AffairOfHonor_CoatHonor_Next";
			DialogExit();
			SetFunctionTimerCondition("AffairOfHonor_TimeIsLeft", 0, 0, 2, false);
			PChar.QuestTemp.AffairOfHonor.CoatHonor.Started = true;
			PChar.QuestTemp.AffairOfHonor.CoatHonor.CityId = NPChar.city;
			PChar.QuestTemp.AffairOfHonor.CoatHonor.NeedGenerateDuelMan = true;
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "13");
			npchar.lifeday = 2;
		break;
		
		case "AffairOfHonor_CoatHonor_Next":
			dialog.text = "����� ����� �� ��� ������, ������? ������, ���... �� �����?";
			link.l1 = "���� �������. �����. ��� ����� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AffairOfHonor_CoatHonor_Next";
		break;
		
		case "AffairOfHonor_CoatHonor_Final":
			dialog.text = "����� ����� �� ��� ������, ������? ������, ���... �� �����?";
			link.l1 = "�� �����������. ��� ��������� ��������� ������ ������ �� ������ ��������� �����... ������ ����� ��������. ��, �������, �� ��������� �� ������������ ����� � ����� �� ������ ���������� � ����������� ������?";
			link.l1.go = "AffairOfHonor_CoatHonor_Final_1";
		break;
		
		case "AffairOfHonor_CoatHonor_Final_1":
			dialog.text = "�� �� ������? �... � ��� ������ �����������, "+GetAddress_Form(NPChar)+"! ���, �������� ��, ��� � ���� ����. ��� ��� ���������, ����� �� �� ���������� �����!\n����, ��������? ��, ���� ������, �� �����! ����� ������ �� ����������.";
			link.l1 = "��� � ������. ��������, ������...";
			link.l1.go = "AffairOfHonor_CoatHonor_Final_2";
		break;
		
		case "AffairOfHonor_CoatHonor_Final_2":
			DialogExit();
			npchar.lifeday = 0;
			NextDiag.CurrentNode = "AffairOfHonor_CoatHonor_End";
			TakeNItems(pchar, "purse3", 1); 
			Log_Info("�� �������� ������ ��������");
			PlaySound("interface\important_item.wav");
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
		break;
		
		case "AffairOfHonor_CoatHonor_End":
			dialog.text = "��� ��� ������� �������, "+GetAddress_Form(NPChar)+", �� ���� ������!";
			link.l1 = "������ ����������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "AffairOfHonor_CoatHonor_End";
		break;
		
		case "AffairOfHonor_CoatHonor_4":
			dialog.text = "��, ������ �����?! ��� �� ������� � ������ ���� ����? ���������� ������ ����������, ����� � �������� ��� �����!";
			link.l1 = "� ���� ���, ��� ��� ����������, � �� ������� �������� ����� ��� � ����� ���������! �����? �� ��� ��, ����������!";
			link.l1.go = "AffairOfHonor_CoatHonor_5";
		break;
		
		case "AffairOfHonor_CoatHonor_5":
			dialog.text = "��� ��� ��������! ����������! ������, �� �����������! ���������� �������� ���� ���, ���, �������, ��� �������� ������ �������� � ���, ��� �������� �� ���� ����!";
			link.l1 = "������� ������! ��� �� ��� �� �������� �������� �� ����, "+GetAddress_FormToNPC(NPChar)+"! ";
			link.l1.go = "AffairOfHonor_CoatHonor_6";
		break;
		
		case "AffairOfHonor_CoatHonor_6":
			dialog.text = "��, ���? ����������! �����, � ���� ����, ���� ������ ����� ��������� ������� ���������, ����� ��� ������� � �����, ��� ������ �������� ����� ��������� ����, ��� ����� ����� �� �����, � �� ����� ������� �� ������� ��������� ����� �����!\n� ������� ��� �� �����, "+GetAddress_Form(NPChar)+" ������! �� �������� �� ���� ��������! ����, ����� ��� ���� ��� �������?";
			link.l1 = "������, "+GetAddress_FormToNPC(NPChar)+" ��������.";
			link.l1.go = "AffairOfHonor_CoatHonor_7";
		break;
		
		case "AffairOfHonor_CoatHonor_7":
			dialog.text = "����� ����������� ������� � ��������� �����. � ��� ���� ��� ������� ������� - ��� ��� ������� �������� � ������ ���������� ��������.";
			link.l1 = "�� ���? �����, ����� �����. �������� �� �����!";
			link.l1.go = "AffairOfHonor_CoatHonor_8";
		break;
		
		case "AffairOfHonor_CoatHonor_8":
			DialogExit();
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			// Jason: �������� �� 2 ���� ��� ��������������
			SetFunctionTimerConditionParam("AffairOfHonor_LighthouseGotoMeeting", 0, 0, 0, GetHour()+2, false);
			DeleteQuestCondition("AffairOfHonor_TimeIsLeft");
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft2", 0, 0, 0, GetHour() + 3, false);
			NextDiag.CurrentNode = "AffairOfHonor_CoatHonor_9";
			LAi_SetWarriorType(npchar); // 140313
		break;
		
		case "AffairOfHonor_CoatHonor_9":
			dialog.text = "���������� ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "AffairOfHonor_CoatHonor_9";
		break;
		
		case "AffairOfHonor_GodJudgement_1":
			dialog.text = "�� ������ � ���� �����������? ��! '����� ���' - ��� ��� ��� ������ ���������� � ����� �� ��� ������! �����! ��� ��� ��� ��������? �, ����� ����������� ���������, � �����-������ ��������-��������� ����� ������\n����� �� ��� �����? ��� ��������! � ��, ����������, ������������ � ����� ������ ����. ������� � � ����� ��� ��������� ���� �������������� �� ����������� �����. �������� � � � ����� �� ��������.";
			link.l1 = "����� ������ ���������� ��������?";
			link.l1.go = "AffairOfHonor_GodJudgement_1_1";
		break;
		
		case "AffairOfHonor_GodJudgement_1_1":
			dialog.text = "������� �� �������� � �����. ��� �� �������� ���?";
			link.l1 = "������, ��� � ���� - ������. ����� ���� � ������!";
			link.l1.go = "AffairOfHonor_GodJudgement_1_2";
		break;
		
		case "AffairOfHonor_GodJudgement_1_2":
			DialogExit();
			PChar.QuestTemp.AffairOfHonor.GodJudgement.Started = true;
			PChar.QuestTemp.AffairOfHonor.GodJudgement.CanSpeakPriest = true;
			PChar.QuestTemp.AffairOfHonor.GodJudgement.CityId = NPChar.city;
			Locations[FindLocation(PChar.QuestTemp.AffairOfHonor.LighthouseId)].DisableEncounters = true;
			LAi_LocationDisableOfficersGen(PChar.QuestTemp.AffairOfHonor.LighthouseId, true);
			SetFunctionTimerConditionParam("AffairOfHonor_TimeIsLeft", 0, 0, 0, GetHour() + 3, false);
			SetFunctionLocationCondition("AffairOfHonor_LighthouseLocEnter", PChar.QuestTemp.AffairOfHonor.LighthouseId, false);
			npchar.lifeday = 3;
			// Jason: ������� ��� �� ����� - ������ ����������
			Rank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+12;
			Scl = 30+2*sti(pchar.rank);
			Mft = MOD_SKILL_ENEMY_RATE/20;
			sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_GodJudgement_Man", "pirate_"+(rand(9)+1), "man", "man", Rank, sti(NPChar.nation), -1, true, "soldier"));
			FantomMakeCoolFighter(sld, Rank, Scl, Scl, RandPhraseSimple("blade_05","blade_07"), RandPhraseSimple("pistol1","pistol5"), "bullet", Scl*3);
			sld.MultiFighter = 1.5; // ������������
			sld.MultiShooter = 1.5;
			LAi_SetImmortal(sld, true); // ��� ������.
			sld.dialog.filename = "Quest\ForAll_dialog.c";
			ReOpenQuestHeader("AffairOfHonor");
			AddQuestRecord("AffairOfHonor", "15");
		break;
		
		case "AffairOfHonor_GodJudgement_2":
			dialog.text = "�������������, ��� ��� ������? ��... ��������, �� ��������?";
			link.l1 = "��� ����� ������� �����, ��� �� ����� ����� ���� �������� ������. ��������, ���� ��� ����� ����� ���������������� �, �� ������ ������, ��������� ������ ������ ������������� ����������, �� ��� � ����������� �����������. ��, � �������, � ���������� ������� ������ �������.";
			link.l1.go = "AffairOfHonor_GodJudgement_3";
		break;
		
		case "AffairOfHonor_GodJudgement_3":
			dialog.text = "��� ��� ����� �������� ��� �����! ������-��, � �������, � ����������� �� ����� ������ �������� ��� � ������� ����� ��� ������ ����� �������! ������� ���! ��� ���� �������, � � ������� � ����������.";
			link.l1 = "��������.";
			link.l1.go = "exit";
			npchar.lifeday = 0;
			TakeNItems(pchar, "purse3", 1); 
			TakeNItems(pchar, "purse"+(drand(2)+1), 1); 
			Log_Info("�� �������� ��� ������ � ���������");
			PlaySound("interface\important_item.wav");
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(PChar, "nobility", 3);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 2);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			LAi_CharacterDisableDialog(NPChar);
		break;
		
		// ������� �� ��� -->
		case "AffairOfHonor_BeforeFight_1":
			dialog.text = "���� ��� ����� ����� ������, ������ ���, �����, ����� �������� ������ � ��� ������.";
			link.l1 = "�� �� �����, � ������ ������� �������������.";
			link.l1.go = "AffairOfHonor_BeforeFight_2";
			
			switch(AffairOfHonor_GetCurQuest())
			{
				case "Cavalier":
					dialog.text = "� ��� � ��, ���������. ��� ��� ������ � ����������. ���������?";
					link.l1 = "� � ����� �������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2";
				break;
				
				case "HonorSlave":
					dialog.text = "��� � �����. �� ������?";
					link.l1 = "��, ����� ��������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2";
				break;
				
				case "BeautifulPirate":
					dialog.text = "��, �������-��! � �� �����, ��� ��� ������ � ����� ����... ������� �������� ��������, ���� � ������� ���� ��������� �������� � ���!";
					link.l1 = "������, ��� ������ �� ����������� �� ��, �� ������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2"
				break;
				
				case "Jackanapes":
					dialog.text = "�� ���-���� ������? ��� �����! ������!";
					link.l1 = "����� �� �� �� ��� �������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2"
				break;
				
				case "WolvesAndSheeps":
					dialog.text = "������, ��� ��� ����������. � ������ � ������������� � ������!";
					link.l1 = "������� � ��� ��� �������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2"
				break;
				
				case "CowardFencer":
					dialog.text = "�� ��� �� � ������. ����� ������, ������!";
					link.l1 = "��������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2"
				break;
				
				case "CoatHonor":
					dialog.text = "�������, ��� �� �����... ������, � �������!";
					link.l1 = "�����������!";
					link.l1.go = "AffairOfHonor_BeforeFight_2"
				break;
				
				case "GodJudgement":
					dialog.text = "� ��� ��� ���? ���-��, ��������, �� �� ������� ����� �� �������� ����������...";
					link.l1 = "��� � ���� ��� �������� ������� �� �����?!";
					link.l1.go = "AffairOfHonor_BeforeFight_2_1"
				break;
			}
		break;
		
		case "AffairOfHonor_BeforeFight_2_1":
			dialog.text = "��! �����! ������, �� ����� �� ������ ����... �����, ������� ��� � ���������� �� ��������� ��������. ������!";
			link.l1 = "������? �� ������...";
			link.l1.go = "AffairOfHonor_BeforeFight_2";
		break;
		
		case "AffairOfHonor_BeforeFight_2":
			LAi_LocationFightDisable(LoadedLocation, false);
			AddDialogExitQuest("MainHeroFightModeOn");
			PChar.Quest.AffairOfHonor_KillChar.win_condition.l1 = "NPC_Death";
			PChar.Quest.AffairOfHonor_KillChar.win_condition.l1.character = "AffairOfHonor_" + AffairOfHonor_GetCurQuest() + "_Man";
			PChar.Quest.AffairOfHonor_KillChar.function = "AffairOfHonor_KillChar";
			if(dRand(1) == 0 && AffairOfHonor_GetCurQuest() != "CowardFencer" && AffairOfHonor_GetCurQuest() != "CoatHonor")
			{
				PChar.QuestTemp.AffairOfHonor.FightWithHelpers = true;
				Log_TestInfo("���������� ����� ���������");
			}
			// � ������ "����� ���" ������ ��������.
			if(AffairOfHonor_GetCurQuest() == "GodJudgement")
			{
				Log_TestInfo("���������� ������");
				sld = CharacterFromID("AffairOfHonor_Helper_1");
				LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
				LAi_SetImmortal(sld, false);
				sld = CharacterFromID("AffairOfHonor_Helper_2");
				LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
				LAi_SetImmortal(sld, false);
				iTemp = dRand(3);
				if(AffairOfHonor_GetCurQuest() == "GodJudgement")
				{
					for(i = 0; i < iTemp; i++)
					{
						sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_GodJudgement_Man_" + i, "pirate_" + (rand(9) + 1), "man", "man", sti(PChar.rank) + rand(5), sti(sld.nation), -1, true, "soldier"));
						SetFantomParamFromRank(sld, sti(PChar.rank) + rand(5), true);
						ChangeCharacterAddressGroup(sld, PChar.location, "smugglers", "smuggler0" + (i + 1));
						LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
					}
				}
			}
			LAi_Group_MoveCharacter(NPChar, "AffairOfHonor_Enemies");
			LAi_Group_SetRelation("AffairOfHonor_Enemies", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_Group_FightGroups("AffairOfHonor_Enemies", LAI_GROUP_PLAYER, true);
			
			DialogExit();
		break;
		// <-- ������� �� ���.
		
		// ������� ����� ��� -->
		case "AffairOfHonor_AfterFight_1":
			if(CheckAttribute(PChar, "QuestTemp.AffairOfHonor.FightWithHelpers"))
			{
				dialog.text = "������� �� ������, ��� �������� ������ ����� � �������� ��������� �����? � ������!";
				link.l1 = "����� � ��������� ������� �� ������ ������ �����������!";
				link.l1.go = "AffairOfHonor_AfterFight_FightWithHelpers";
				break;
			}
			if(AffairOfHonor_GetCurQuest() == "CoatHonor")
			{
				dialog.text = "�������, ����� �������������, �� ��������. �� ��������� ���� ��� ������ ����� � ��������� ��� ����� ������ �� ������ � �� ������������� ����� ��������� �����...";
				link.l1 = "� � ���, ����������, ����?";
				link.l1.go = "AffairOfHonor_AfterFight_2_1";
			}
			else
			{
				dialog.text = "��� ���� �� �����, � ������ ��������� ��� ������� ������ �������� � ���� �����.";
				link.l1 = "�������, � ��� �� ����������.";
				link.l1.go = "AffairOfHonor_AfterFight_2";
			}
		break;
		
		case "AffairOfHonor_AfterFight_2_1":
			dialog.text = "� ���� � ���, ��� ��, ���� ���� �� ����, ����� ��������� ����������. � ���� ������ ���� ������ ���������, � ������ �������� ���� ��� ������ ������, ���������, ������, ��� ����� � �� ������� ������ ������ �������.";
			link.l1 = "������� �� �����, � ���������� �� ������������. ��������.";
			link.l1.go = "AffairOfHonor_AfterFight_2";
		break;
		
		case "AffairOfHonor_AfterFight_2":
			DialogExit();
			LAi_ActorGoToLocation(NPChar, "reload", FindNearestFreeLocator("reload"), "none", "", "", "", 3.0);
			LAi_ActorGoToLocation(CharacterFromID("AffairOfHonor_Helper_2"), "reload", FindNearestFreeLocator("reload"), "none", "", "", "", 3.0);
			if(AffairOfHonor_GetCurQuest() == "CoatHonor")
			{
				ChangeCharacterComplexReputation(PChar, "nobility", 5);
			}
		break;
		
		case "AffairOfHonor_AfterFight_FightWithHelpers":
			iTemp = dRand(3);
			AddDialogExitQuest("MainHeroFightModeOn");
			sld = CharacterFromID("AffairOfHonor_Helper_1");
			LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
			LAi_SetImmortal(sld, false);
			sld = CharacterFromID("AffairOfHonor_Helper_2");
			LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
			LAi_SetImmortal(sld, false);
			if(AffairOfHonor_GetCurQuest() == "GodJudgement")
			{
				for(i = 0; i < iTemp; i++)
				{
					sld = GetCharacter(NPC_GenerateCharacter("AffairOfHonor_GodJudgement_Man_" + i, "pirate_" + (rand(9) + 1), "man", "man", sti(PChar.rank) + rand(5), sti(sld.nation), -1, true, "soldier"));
					SetFantomParamFromRank(sld, sti(PChar.rank) + rand(5), true);
					ChangeCharacterAddressGroup(sld, PChar.location, "smugglers", "smuggler0" + (i + 1));
					LAi_Group_MoveCharacter(sld, "AffairOfHonor_Enemies");
				}
			}
			LAi_Group_SetRelation("AffairOfHonor_Enemies", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_Group_FightGroups("AffairOfHonor_Enemies", LAI_GROUP_PLAYER, true);
			
			DialogExit();
		break;
		// <-- ������� ����� ���.
		//=====================================================================================================================================
		// <-- ����� ����������� "���� �����".
		//=====================================================================================================================================
	}
}

void SetSeekCapCitizenParam(ref npchar, int iNation)
{
	//������� �����
	int Rank = sti(pchar.rank)+5;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("SeekCitizCap_"+npchar.index, "", "man", "man", Rank, iNation, -1, true, "soldier"));
	switch (npchar.quest.SeekCap)
	{
		case "NM_battle": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "trade";
			SetCaptanModelByEncType(sld, "trade");
			sld.dialog.currentnode = "NM_battleCap";
			sld.DeckDialogNode = "NM_battleDeck";
			npchar.quest.money = (6-sti(RealShips[sti(sld.Ship.Type)].Class))*8000+sti(pchar.rank)*500;
			npchar.quest.dublon = makeint(sti(npchar.quest.money)/100);
		break;
		
		case "NM_prisoner": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "trade";
			SetCaptanModelByEncType(sld, "trade");
			sld.dialog.currentnode = "NM_prisonerCap";
			sld.DeckDialogNode = "NM_prisonerCap";
			npchar.quest.money = (6-sti(RealShips[sti(sld.Ship.Type)].Class))*10000+sti(pchar.rank)*600;
			npchar.quest.dublon = makeint(sti(npchar.quest.money)/100);
		break;
		
		case "NM_peace": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "war";
			SetCaptanModelByEncType(sld, "war");
			sld.dialog.currentnode = "NM_peaceCap";
			sld.DeckDialogNode = "NM_peaceCap";
			npchar.quest.money = (6-sti(RealShips[sti(sld.Ship.Type)].Class))*6000+sti(pchar.rank)*400;
			npchar.quest.dublon = makeint(sti(npchar.quest.money)/100);
		break;
	
		case "manSlave": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			SetCaptanModelByEncType(sld, "pirate");
			sld.dialog.currentnode = "CitizCap";
			sld.DeckDialogNode = "CitizCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
		
		case "manRapeWife": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			SetCaptanModelByEncType(sld, "pirate");
			sld.dialog.currentnode = "RapeWifeCap";
			sld.DeckDialogNode = "RapeWifeCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
		
		case "manFriend": 
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			SetCaptanModelByEncType(sld, "trade");
			sld.dialog.currentnode = "FriendCap";
			sld.DeckDialogNode = "FriendCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
		
		case "womanHasband": 
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			SetCaptanModelByEncType(sld, "trade");
			sld.dialog.currentnode = "HasbandCap";
			sld.DeckDialogNode = "HasbandCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
		
		case "womanRevenge": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			SetCaptanModelByEncType(sld, "pirate");
			sld.dialog.currentnode = "RevengeCap";
			sld.DeckDialogNode = "RevengeCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
		
		case "womanPirates": 
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			SetCaptanModelByEncType(sld, "pirate");
			sld.dialog.currentnode = "PiratesCap";
			sld.DeckDialogNode = "PiratesCap_inDeck";
			npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500);
		break;
	}
	sld.dialog.filename = "Quest\ForAll_dialog.c";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	sld.DontRansackCaptain = true; //�� ���������
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	//� ������� ������ ����
	string sGroup = "SeekCapShip_" + sld.index;
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	//���������� ������ � ��������� �������� � ����
	npchar.quest.SeekCap.capId = sld.id //Id �������� ����
	npchar.quest.SeekCap.capName = GetFullName(sld); //��� �������� ����
	npchar.quest.SeekCap.shipName = sld.Ship.name; //��� ����������� �������
	npchar.quest.SeekCap.shipTapeName = RealShips[sti(sld.Ship.Type)].BaseName; //�������� ����������� �������
	//npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1)*1000)+(sti(pchar.rank)*500); //��������������
	sld.quest = "InMap"; //������ ���� �������� ����
	sld.quest.SeekCap = npchar.quest.SeekCap; //������� ���� ���� ������
	sld.quest.nation = iNation; //�������� ������� ����� ����
	sld.city = SelectAnyColony(npchar.city); //��������� �������, ������ ���-��� ������
	sld.quest.targetCity = SelectAnyColony2(npchar.city, sld.city); //��������� �������, ���� �� ������
	//Log_TestInfo("������������� ��� " + sld.id + " ����� ��: " + sld.city + " � ���������� �: " + sld.quest.targetCity);
	sld.quest.cribCity = npchar.city; //�����, ��� ��������� ������������
	npchar.quest.Qcity = sld.city;
	//==> �� �����
	sld.mapEnc.type = "trade";
	//����� ���� ��������� �� �����
	switch (npchar.quest.SeekCap)
	{
		case "NM_battle":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "NM_prisoner":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "NM_peace":	 sld.mapEnc.worldMapShip = "ranger";	  break;
		case "manSlave":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manRapeWife":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manFriend":	 sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanHasband": sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanRevenge": sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "womanPirates": sld.mapEnc.worldMapShip = "Galleon_red"; break;
	}
	sld.mapEnc.Name = XI_ConvertString(npchar.quest.SeekCap.shipTapeName) + " '" + npchar.quest.SeekCap.shipName + "'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //���� ������� ���� � �������
	Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, daysQty);
	//���������� �� ������ ����
	string sTemp = "SCQ_" + sld.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = sld.id;
	pchar.quest.(sTemp).function = "SCQ_seekCapIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	//���������� �� ������ ������������
	sTemp = "SCQ_" + npchar.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = npchar.id;
	pchar.quest.(sTemp).function = "SCQ_CitizenIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	pchar.quest.(sTemp).CitizenId = npchar.id;
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "citizen"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = npchar.id; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = sld.quest.cribCity + "SCQ_" + npchar.quest.SeekCap; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "SCQ_" + npchar.quest.SeekCap; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

string SelectNB_battleText()
{
	string sText;
	switch (drand(5))
	{
		case 0: sText = "���� �������� ��������� ��� ������, ���������������� �� ����������, � �����, �����������, ����������� ������. � �� ��� �������� ��� ������ ������������� � ������ ������� �� �����. ������ �� ������� � ������ � ���� �� ����� �������" break;
		case 1: sText = "���� ���������� ������� �������� ��� � ����� ������� ����� �����, �, �� ����� ��������, ������� �������� ���� �� ����� �������" break;
		case 2: sText = "���� ���������� ���� � ���� ������ � ����, ����� ����� �� � ��� ���������� ����� - � ������ ��������� ����������. ������ �� ���������� �� ����� ������� �������� ���" break;
		case 3: sText = "���� ������� ������� ��������� ��� ���, ��������� ���� ����� ������������. ������ ����� ��� ������, � �������� ������ � ���� �� ����� �������" break;
		case 4: sText = "�, �� ����������, ����� ���������� ����������. �� �������� ������� ��������, ����� ������� � ������� �������� ����" break;
		case 5: sText = "��� ������ �������� ������ �� ������� ���� �������� � ��������������� � �������. ������ � �����, ������ � ��� ������ ��������� ������ �� ������� �������" break;
	}
	return sText;
}

void SelectNB_prisonerText(ref npchar)
{
	switch (drand(5))
	{
		case 0:
			npchar.quest.text = "���� �������� ��������� ��� ������, ���������������� �� ����������, � �����, �����������, ����������� ������. � �� ��� �������� ��� ������ ������������� � ������ ������� �� �����. ������ �� ��������� ���������� ����������� ��������� �� ���� ����� � ���� � ����";
			npchar.quest.text1 = "���������� �������, � ����� �������� ������ �� �����";
		break;
		case 1:
			npchar.quest.text = "���� ���������� ������� �������� ��� � ����� ������� ����� �����, �, �� ����� ��������, ������ �� ���� � ����, �������� �� ������ � ������ �������� ���������";
			npchar.quest.text1 = "������ ���������� � ����� � �� ������ �������� ����";
		break;
		case 2:
			npchar.quest.text = "���� ���������� ���� � ���� ������ � ����, ����� ����� �� � ��� ���������� ����� - � ������ ��������� ����������. ������ �� ������ �� ����� ������� ��������� � ���������� �� ����";
			npchar.quest.text1 = "����������������, ����������� ������������";
		break;
		case 3:
			npchar.quest.text = "���� ������� ������� ��������� ��� ���, ��������� ���� ����� ������������. ������ ����� ��� ������, � �������� ������ � ���� �� ����� �������, ����������� �� ��������� �������� �����";
			npchar.quest.text1 = "��������� � ��������, ���������� ��������� ������ ��� ������ �� ������ �������";
		break;
		case 4:
			npchar.quest.text = "�, �� ����������, ����� ���������� ����������. �� �������� ������� �������� � ������ �� ����� �������, ��������� ����������������";
			npchar.quest.text1 = "���������� � �������� � ���������� ����� �����";
		break;
		case 5:
			npchar.quest.text = "��� ������ �������� ������ �� ������� ���� �������� � ��������������� � �������. ��� ���������, �� �������� �������� � ���������� ���� �� ���� �������";
			npchar.quest.text1 = "��������� ���, �� �������� ������ ������. �� ����� ������������� � ������ ������������";
		break;
	}
}

void SelectNB_peaceText(ref npchar)
{
	switch (drand(5))
	{
		case 0: 
			npchar.quest.text = "��� ��������� ��������, � ������� �� ���� ����� ������ � ������ �����";
			npchar.quest.text1 = "�� - ��� ������ ����";
		break;
		case 1:
			npchar.quest.text = "�������, ���������� ���������� ��� � ������� ������� ����";
			npchar.quest.text1 = "�� ���� ��� � ������� �� ����";
		break;
		case 2:
			npchar.quest.text = "��� ������� ����, ���������� ������ ���� ��� � ������";
			npchar.quest.text1 = "�� - ��� ������� ����";
		break;
		case 3:
			npchar.quest.text = "�������, ��������� ��� ��������� ��� ����� � ������ ����� ��������� ���������� ������";
			npchar.quest.text1 = "�� ������� ��� �����-�� ������";
		break;
		case 4:
			npchar.quest.text = "��� ���� ������, � ������� � ��� ������ ������ � ������ �����";
			npchar.quest.text1 = "�� - ��� ��� ������";
		break;
		case 5:
			npchar.quest.text = "��� ����, � ������� �� ������ ������� � ����� ����� � ������ �����";
			npchar.quest.text1 = "�� ������� � ����� �����";
		break;
	}
}