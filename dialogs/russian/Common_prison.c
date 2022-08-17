// ��������� ������
void ProcessDialogEvent()
{
	int amount, iGunQty, iGunGoods, iGunPrice, iTemp;
	int iTest;
	ref NPChar, sld, location;
	ref arItem;
	ref rColony;
	aref Link, NextDiag;
	string sTemp;
	float locx, locy, locz;
	bool  ok;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Prison\" + NPChar.City + "_Prison.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	
		case "fight":
			DialogExit();
			PlaySound("Voice\Russian\fight13.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "NoMoreTalkExit":
			LAi_CharacterDisableDialog(npchar);
			DialogExit();
		break;
		//---------------- ��������� ������ ------------------
		case "First_officer":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			    if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -20)
			    {
                dialog.text = "���-���. ��� ��� � ���? ���, "+GetFullName(pchar)+"! ������� ��, ���������, ���������� � �������. � �� ���� ������ ��������� �������. ����� �����! ����� ���, ������!";
                link.l1 = "�� ��... ��� �� ���� ���� ��� �����������������!";
                link.l1.go = "fight"; 
                break;
                }
		dialog.text = RandPhraseSimple("� ��������� ������. ��� ��� ����� �����?", "��� ��� �����? ����� �� ������� � ������?");
			link.l1 = "�� ������ ����������, ���������� �����, ������ ��. ��� � ������"+ GetSexPhrase("","�") +" ���� �� ������.";
			link.l1.go = "exit";
			link.l2 = "���� ���������� �� ����.";
			if (CheckCharacterItem(pchar, "CaptainBook") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakFort"))
			{
				if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
				{
					link.l2.go = "F_ShipLetters_1";
				}
				else
				{
					link.l2.go = "quests";
				}		
			}
			else
			{
				if(CheckAttribute(pchar,"questTemp.ReasonToFast") && !CheckAttribute(pchar,"questTemp.ReasonToFast.SpeakOther") && !CheckAttribute(pchar, "questTemp.ReasonToFast.cantSpeakOther") && (pchar.questTemp.ReasonToFast.city == NPChar.city))
				{
					link.l2.go = "ReasonToFast_Prison1";
				}
				else
				{
					link.l2.go = "quests";
				}	
			}
			if (!sti(pchar.questTemp.jailCanMove))
			{
				link.l4 = "� ���� ������ ������ ������.";
				link.l4.go = "ForGoodMove";		
			}
			if (CheckAttribute(pchar, "questTemp.jailCanMove.City") && npchar.city == pchar.questTemp.jailCanMove.City)
			{
				link.l5 = "����������, �� ���������� ���, �� ����� ������������ ����� ����� ����������� �� ����� " + GetFullName(characterFromId(pchar.questTemp.jailCanMove.prisonerId)) + "?";
				link.l5.go = "KnowAboutPrisoner";	
			}
			
			if(CheckAttribute(pchar,"GenQuest.CaptainComission") && (pchar.GenQuest.CaptainComission.variant == "A2") && (pchar.GenQuest.CaptainComission.City == NPChar.city))
			{
				if(!CheckAttribute(pchar,"GenQuest.CaptainComission.PrisonFree"))
				{
					bool zMsm = (CheckAttribute(pchar,"GenQuest.CaptainComission.GetRumour")) && (!CheckAttribute(pchar,"GenQuest.CaptainComission.SpeakMayor"));
					if(pchar.GenQuest.CaptainComission == "MayorTalkBad" || zMsm) //������� � ������� � ��������� ��� ����� �����, �� �� ������� � �������
					{
						link.l6 = "�� ���� ����� �����, ��� ������ ������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc")) + " " + pchar.GenQuest.CaptainComission.Name + " ���������� � ��� ��� �������. ���� � � ��� ������������?";
						link.l6.go = "CapComission_PrisonBad1";
					}
					if(pchar.GenQuest.CaptainComission == "MayorTalkGood")
					{
						link.l6 = "� " + GetFullName(pchar) + ", �������� �� ����� � �� ��������� ����������� " + XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen") + ". ��� ����� ������������ � ������ ��������� " + pchar.GenQuest.CaptainComission.Name + ".";
						link.l6.go = "CapComission_PrisonGood1";
					}
				}	
			}
			if(CheckAttribute(pchar,"GenQuest.EncGirl"))
			{
				if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
				{
					if(pchar.GenQuest.EncGirl.Father == "fort_keeper"  && npchar.city == pchar.GenQuest.EncGirl.city)
					{
						link.l9 = "� �� ������ ����� ������...";
						link.l9.go = "EncGirl_1";
					}
				}
			}
			//Jason --> ���������� ���������
			if (CheckAttribute(pchar, "questTemp.Shadowtrader.Fort") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_prison")
			{
				link.l10 = "� ������ � ��� �� ������� ������� �������� ��������, ��� ����� "+pchar.questTemp.Shadowtrader.Tradername+". �� ������ �������� ��� ��� ��� ������.";
				link.l10.go = "Shadowtrader_prison";
			}
			
			if (CheckAttribute(pchar, "questTemp.Shadowtrader.SeekTrader") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_prison")
			{
				link.l10 = "��� ����� �. � ���� ���� ������ �������������� ����, ��� "+pchar.questTemp.Shadowtrader.Tradername+" ����.";
				link.l10.go = "Shadowtrader_prison2";
			}
			//Jason <-- ���������� ���������
			
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "begin" && NPChar.location == pchar.GenQuest.Marginpassenger.City + "_prison")
			{
				link.l12 = "� ���� � ��� ����, ������. �����, ��� ��� ������������ �� ����� ������.";
				link.l12.go = "Marginpassenger";
			}
			
			// Warship, 16.05.11. ����� "���������� �� �������".
			if(CheckAttribute(PChar, "GenQuest.JusticeOnSale.PrisonWait") && CheckAttribute(PChar, "GenQuest.JusticeOnSale.CityId") && NPChar.location == PChar.GenQuest.JusticeOnSale.CityId + "_prison")
			{
				link.l13 = "����� ���������� � ���� �� ����� �������� - " + PChar.GenQuest.JusticeOnSale.SmugglerName + ". ���� �� �������� � �� ��� �����������.";
				link.l13.go = "JusticeOnSale_1";
			}

			// �������� ������
			if(pchar.location == "Villemstad_prison" && CheckAttribute(pchar, "questTemp.PrisonEscort_quest") && pchar.questTemp.PrisonEscort_quest == "to_prisone")
			{
				DeleteAttribute(link, "");
				
				dialog.text = "������� ���� ���������, " + GetSexPhrase("������","�������") + "! ��� ���� ������� ��� � ����� ���������. ��� ����! ���� �� �� ����� �� ������ �� ������� �� �����!!!";
				link.l14 = "��, ������ ��! � ���� ��� �������, � � ������" + GetSexPhrase("��","��") + " ������� ���� ����� �� ��������������� �������������, � �������, ��� ���������, �� ���� �� ��������� ���������!!! �������, �������� �������� � � ���� ���� ������" + GetSexPhrase("��","��") + "?";
				link.l14.go = "PrisonEscort_1";
			}
			if(pchar.location == "Villemstad_prison" && CheckAttribute(pchar, "questTemp.PrisonEscort_quest"))
			{
				if(pchar.questTemp.PrisonEscort_quest == "sink_ship" || pchar.questTemp.PrisonEscort_quest == "capture_ship")
				{
					DeleteAttribute(link, "");
					
					dialog.text = "�������, � ��� ���� ��� ���� ����������...";
					link.l1 = "��, ��� ��� � ���� ��� ��� ����.";
					link.l1.go = "PrisonEscort_6a";
				}
			}
			
			NextDiag.TempNode = "First_officer";
		break;

		//Jason --> ����-����� ���������� ���������
		case "Shadowtrader_prison":
			dialog.text = "����� ���� "+pchar.questTemp.Shadowtrader.Tradername+" �� ������ ��������! ������� �������, ��� �� �� ���� ��� �����... (������)";
			link.l1 = "...";
			link.l1.go = "Shadowtrader_prison_1";
			RemoveItems(PChar, "letter_1", 1);
			DeleteAttribute(pchar, "questTemp.Shadowtrader.Fort");
		break;
		
		case "Shadowtrader_prison_1":
			dialog.text = "����� ��� ��������� ������� � �� ������ ������� ��������������! ���. ��������� ���, ��� ����� ������������ ��� ����, ����� � ������ ������ �� ��� � �������� ����������� �����.";
			link.l1 = "��� � ��������?";
			link.l1.go = "Shadowtrader_prison_2";
		break;
		
		case "Shadowtrader_prison_2":
			dialog.text = "��, ������ ���, � ���������� ��������. �� ������, � ��� ����. ������ ������ ���� ������ �� ���� �������� � �� ����.";
			link.l1 = "� �����. ����� �������.";
			link.l1.go = "exit";
			pchar.questTemp.Shadowtrader.Trouble = "true";
			NextDiag.TempNode = "First_officer";
		break;
		
		case "Shadowtrader_prison2":
			dialog.text = "���������, � ����� �� ��� ����� ''������'' �������������� ��� ������� ������?";
			link.l1 = "� ����������� � ���������������� � ������� ������� ����� �� ������������� �������. �� ����� ������ ������� ����� � ��������� ����������, ��� ����, ����� �������� ���� � ���� ��� ���������� ''�����''.";
			link.l1.go = "Shadowtrader_prison2_1";
			DeleteAttribute(pchar, "questTemp.Shadowtrader.SeekTrader");
			pchar.quest.ShadowtraderTimeSmugglers_Over.over = "yes";
			pchar.quest.Shadowtrader_SMG.over = "yes";//����� ��� ����������
			sld = characterFromID("ShadowAgent_1");
			sld.lifeday = 0;
		break;
		
		case "Shadowtrader_prison2_1":
			dialog.text = "���... �������� ������, �������! ������ ����������� ����� �� - ������ �� ������� ������ ��������, ������ �� ������� � ���� ��������. ��������� �� ����������� ����������!";
			link.l1 = "������ ��� ������. ������, ���� �������� ������� �������.";
			link.l1.go = "exit";
			pchar.questTemp.Shadowtrader.End.Fort = "true";
			AddQuestRecord("Shadowtrader", "7");
			SaveCurrentQuestDateParam("pchar.questTemp.Shadowtrader.EndFort");
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 100);//����������
			NextDiag.TempNode = "First_officer";
		break;
		// <-- ����-����� ���������� ���������
		
		// --> Jason ����������
		case "Marginpassenger":
			dialog.text = "��? � ��� �� ����� �� ������ ��� ��������?";
			link.l1 = "�� ��� �� ����� ������� ������� ����� "+pchar.GenQuest.Marginpassenger.Name+" � ��������� ���������� ������ ������: ��������� � ���� � � ���������� ����� �� ����� �������� �� ����� "+pchar.GenQuest.Marginpassenger.q1Name+". ��� "+pchar.GenQuest.Marginpassenger.Text+"...";
			link.l1.go = "Marginpassenger_1";
		break;
		
		case "Marginpassenger_1":
			dialog.text = "��... ����� ���������. �����������!";
			link.l1 = "��� ���� �������� �������� �����, �� ������� "+pchar.GenQuest.Marginpassenger.q1Name+" ��������� ����������� � ����. ��� "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Marginpassenger.ShipType), "Name")))+" ��� ��������� ''"+pchar.GenQuest.Marginpassenger.ShipName+"''. ����� �� ������ � ����� ������ ����� � ��������.";
			link.l1.go = "Marginpassenger_2";
		break;
	
		case "Marginpassenger_2":
			dialog.text = "� �� ��������� ��� ��������� ���������, � ����� ����������� �����?";
			link.l1 = "������ ���. �� ������� ����� ���������� � "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Targetcity)+", � ������ �������� �� ����� "+pchar.GenQuest.Marginpassenger.q2Name+". � �������� ��� �� ��� ����������, ��, �������, ���� � �� ��������� ������������ ���������.";
			link.l1.go = "Marginpassenger_3";
		break;
		
		case "Marginpassenger_3":
			dialog.text = "� �� ������ ������� �� ��� � �������� ��� ����, ���?";
			link.l1 = "������ ���. � ������, ��� �������� ������� �������� ������������ ������� ������ ������, � �� ������� � ��������� ���� ���������� ����.";
			link.l1.go = "Marginpassenger_4";
		break;
		
		case "Marginpassenger_4":
			dialog.text = "�� ����� ��������� �������, ��� ������ �� ���, "+GetAddress_Form(NPChar)+"! ���� �������, "+pchar.GenQuest.Marginpassenger.Name+", ��� ����� � ��� ��� �����������. � ������� �������������, � ���� ���, ��� �� �������, ������������, �� ������ �������� �� ������� �� ���������. ��� ������ ��� ������� ������������ ����� ��������� ���������\n��, � � ����� ��������� � ���������� ������� ������� ���� �, ����������, ������ ������ �����������, ���, �������, ��������� �� ��� ��������� � ���... ��� �� ���������, � ������������� �������. ��������� �� ������, �������!";
			link.l1 = "��... ��, ����������, �� �� ���... ��� ��� ������. �� ��������!";
			link.l1.go = "Marginpassenger_5";
		break;
		
		case "Marginpassenger_5":
			DialogExit();
			NextDiag.CurrentNode = "First_officer";
			AddQuestRecord("Marginpassenger", "20");
			AddQuestUserData("Marginpassenger", "sName", pchar.GenQuest.Marginpassenger.Name);
			CloseQuestHeader("Marginpassenger");
			pchar.quest.Marginpassenger_InWorld.over = "yes"; //����� ������
			DeleteAttribute(Pchar, "GenQuest.Marginpassenger");
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 5);
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			ChangeContrabandRelation(pchar, -25);
			if (GetCharacterIndex("MarginCap") != -1)
			{
				sld = characterFromId("MarginCap");
				sld.lifeday = 0;
				Map_ReleaseQuestEncounter(sld.id);
				Group_DeleteGroup("Sea_MarginCap1");
			}
		break;
		//<-- ����������

		case "EncGirl_1":
			dialog.text = "������ ��� �����������.";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" ���� ��������.";
			link.l1.go = "EncGirl_2";
		break;
		
		case "EncGirl_2":
			dialog.text = "��, �������, ������� ��� �������! ��� ���? �������, �� ����������? �� ����� �����, ��� �������, ���������. ����� � � �� ������� �����? ����� ������ ��������... ����� �������, �������, � ��� ����� �� ������, ��� ���� � ���� ���� �� ����. ���! ��� �� ��-������ ������� - ��� � ����, ���� �...\n����, � ��� �� �� ���� �� ���������, ���� �� � ������ � ��� ����� �� ������� � ����� �������������� ���������... �� �� ��� ����������... ��������� ������, �����... � �������.";
			link.l1 = "�������, �� ���� � ������ ���, �� � �� �� �������"+ GetSexPhrase("��","���") +" �� ��������...";
			link.l1.go = "EncGirl_3";
		break;
		
		case "EncGirl_3":
			dialog.text = "�� ��� �� ���������?.. � ��� ���� ���� ����? ����? ���, ����� ����� - ��������, ����� � ���������\n��... � ������ �������������� ����, ��� � �����, - �������, ����������.";
			link.l1 = "�������. � ������� � ��������. ���-�� ��� ������������, ��� ��� �� ���� �� �����������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("EncGirl_ToLoverParentsExit");
		break;
		
		// ------------------------- ����� ��� ������ -----------------------------
		case "ReasonToFast_Prison1":
			pchar.questTemp.ReasonToFast.SpeakOther = true;
			dialog.text = "� ����������� ������ ���, �������.";
			link.l1 = "� ���� �������� � ���������� ������� ������� ������ ��������� � ������� (�������� �������������� ����).";
			if(makeint(pchar.reputation.nobility) < 41)
			{
				link.l1.go = "ReasonToFast_Prison_BadRep";			
			}
			else
			{
				link.l1.go = "ReasonToFast_Prison_GoodRep";	
			}
		break;
		case "ReasonToFast_Prison_GoodRep":
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_1") 
			{ 
				// �����_�
				dialog.text = "��������� ���, �����"+ GetSexPhrase("�","���") +"! � ���������� ����� ������ ��������� �������.\n������ �� ������� �����������, � ������������� �����, ���, �����...";
				link.l1 = "���� ���������! � �����"+ GetSexPhrase("","�") +" ��� �� ���� �����...";
				link.l1.go = "ReasonToFast_Prison_GoodRep_11";
				
				if(pchar.questTemp.ReasonToFast.chain == "A0") ReasonToFast_RemoveVictim();
				if(pchar.questTemp.ReasonToFast.chain == "A1") pchar.quest.ReasonToFast_ClearLakey.over = "yes";
			}
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_2") 
			{ 
				// �������� �����
				dialog.text = "��������� ���, �����"+ GetSexPhrase("�","���") +"! � ���������� ����� ������ ��������� �������.\n������ ���������! �� ������ ��������� ��� ������� ������� �� ����������� ������. ��� ������, ��� �� �����������, � �� ����� ������ �������!";
				link.l1 = "������ ���"+ GetSexPhrase("","�") +" ��������� ��������������...";
				link.l1.go = "ReasonToFast_Prison_GoodRep_21";			
			}
			if(pchar.questTemp.ReasonToFast == "PatrolDied") 
			{ 
				// ������� �������
				dialog.text = "�����"+ GetSexPhrase("�","���") +"! �� ����� �����������, ��� ���� ������ � ���������� ��� ����� ������� �� ����, �� ��� �������, ��� �� ��������� �����������, ������������ � ���� ��� ����������.";
				link.l1 = "���� ���������! �� � ��������"+ GetSexPhrase("","�") +" ���"+ GetSexPhrase("","�") +" �������� ���� �����...";
				link.l1.go = "ReasonToFast_Prison_GoodRep_31";	
				pchar.questTemp.ReasonToFast.speakAfterPatrolDied = true;	
				pchar.quest.ReasonToFast_SpeakMayor.over = "yes";	
			}
		break;
		
		case "ReasonToFast_Prison_BadRep":
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_1") 
			{ 
				// �����_�
				dialog.text = "�������, �� ���� ���������, �� ��� ���������?!! �� ������ ������ �������� ������������ ��� �������! � �� ���� ����������� ������� ������� ������ ������� � ��������� " + GetName( NAMETYPE_MAIN, pchar.questTemp.ReasonToFast.p3, NAME_GEN) + " � ��� ������ �� ��� ���� ������������! �����, �� ������ ����������, ����� ������� � ������ ���������� ������� ������� ��� ����������� ���� ��������?!!";
				link.l1 = "���� �����! �� ������������� ������ ���� �������������...";
				link.l1.go = "ReasonToFast_Prison_BadRep1";
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_A";
				
				if(pchar.questTemp.ReasonToFast.chain == "A0") ReasonToFast_RemoveVictim();
				if(pchar.questTemp.ReasonToFast.chain == "A1") pchar.quest.ReasonToFast_ClearLakey.over = "yes";
			}
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_2") 
			{ 
				// �������� �����
				dialog.text = "�����-�� ��������� �� ��� �����...\n�� ���� ���� �����������? ���� ������� ������ ���������� - ��������������?";
				link.l1 = "���� �����! �� ������������� ������ ���� �������������...";
				link.l1.go = "ReasonToFast_Prison_BadRep1";
				TakeItemFromCharacter(pchar, "mapQuest");	
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_B";	
			}
			if(pchar.questTemp.ReasonToFast == "PatrolDied") 
			{ 
				// ������� �������
				dialog.text = "������������ ���������� ������ ������ ����������� ������. �� ��� �, �� ������� ����, ����� ����, �� �������� ��� �� ������������� ������ ������";
				link.l1 = "���� ���������! �� ������������� ������ ���� �������������...";
				link.l1.go = "ReasonToFast_Prison_BadRep1";			
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_A";
				pchar.quest.ReasonToFast_SpeakMayor.over = "yes";
			}		
		break;
		
		case "ReasonToFast_Prison_GoodRep_11":
			dialog.text = "��� �� �����, � ����, ����� ���� ����� ���� �������������. ���, �������� �����, ��������� � ����� ������� ���������� �������� ����������. ��������, ��� ���������� �������, �� ������������� ���������� ���������, ���� ��� ������ �����������...";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			AddQuestRecord("ReasonToFast", "15");
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			GiveItem2Character(pchar, "mapQuest"); 
			arItem = ItemsFromID("mapQuest");
			ReasonToFast_GenerateTreasureMap(arItem);
			pchar.questTemp.ReasonToFast.state = "chain_A"; // �����_�, ������� �� �������
			pchar.questTemp.ReasonToFast = "GetMap";			
			ReasonToFast_SetHunterCoastal();
		break;
		case "ReasonToFast_Prison_GoodRep_21":
			dialog.text = "���������� ������. �������� ���� ������ � �������, - ��� �������, ��� � ���� ��� �������! ��.. � �������� ��� ����� ����. ������, - �� ���������� ����� ��������� �������� ���������.";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			AddQuestRecord("ReasonToFast", "14");
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			GiveItem2Character(pchar, pchar.questTemp.ReasonToFast.p6);
			pchar.questTemp.ReasonToFast.state = "chain_B"; // ���� �������� �����
			pchar.questTemp.ReasonToFast = "GetMap";			
			ReasonToFast_SetHunterCoastal();
		break;
		case "ReasonToFast_Prison_GoodRep_31":
			dialog.text = "��, ��������, ��������... ��� ��, � ����� �������, ��� ���� ����������� ������ ����� � �� ���� ���.";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			AddQuestRecord("ReasonToFast", "16");
			CloseQuestHeader("ReasonToFast");
			DeleteAttribute(pchar,"ReasonToFast");			
		break;
		
		case "ReasonToFast_Prison_BadRep1":
			dialog.text = "�� ������ ���� �������! ��� ���� �������� ��� ������ � �����������! ������, ����� "+ GetSexPhrase("����� ''�������������''","��� ''�����������������''") +"!";
			link.l1 = "�� �� ��� !";
			link.l1.go = "fight";
			
			pchar.quest.ReasonToFast_ExitFromTown.win_condition.l1			= "EnterToSea";           	
            pchar.quest.ReasonToFast_ExitFromTown.function    				= "ReasonToFast_ExitFromTownFight";
			pchar.questTemp.ReasonToFast.canSpeakSailor = true;			
			pchar.TownEscape = true;
			Flag_PIRATE();
		break;
		// ------------------------- ����� ��� ������ -----------------------------
		
		// -------------------------- �������� ''������'' ----------------------------
		case "CapComission_PrisonBad1":
			dialog.text = "� �� ������ ���� �� ��� �����������?";
			link.l1 = "� ���� � ���� ��������� �������� ������� ���������.";
			link.l1.go = "CapComission_PrisonBad2";
		break;
		
		case "CapComission_PrisonBad2":
			dialog.text = "�������, � ���� ���� ������ ����������� ����� ��� ������ � ���������� � ���������� ��� �������� ������, ��� ����� �������������� �������� " + pchar.GenQuest.CaptainComission.Name + ".";
			link.l1 = "������� �� ����������! ����������� ��� ���� �������� � ��� ��� ������!";
			link.l1.go = "CapComission_PrisonBad3";
		break;
		
		case "CapComission_PrisonBad3":
			dialog.text = "� ��� �� �����, ����� ����� ������.";
			link.l1 = "�� �� ���! ��� ������� �������� ��� �����.";
			link.l1.go = "fight";
			AddDialogExitQuest("CaptainComission_GenerateCapJail");
		break;
		
		case "CapComission_PrisonGood1":
			dialog.text = "��, �������. � ������� ����������� ����������� ��������� ��� ���������� � ���� �������. ������ ������ � ������������.";
			link.l1 = "��������� ���...";
			link.l1.go = "exit";
			pchar.questTemp.jailCanMove = true;
			AddDialogExitQuest("CaptainComission_GenerateCapJail");
		break;
		
		case "CapComission_PrisonFree1":
			dialog.text = "�-�, �������, � ���� ��� �������� ��������� ����� ������������ ��-��� ������. ��� ����� ��������� �� ��� ���������� �����������.";
			link.l1 = "������, � �������� � ��������� ��������. ����������� ���������� ������������ � �������� � ����� ������� ����� �������. ����� ����������� ������ ���, ��� ������ ���� ����� ������ ���������������� � ������ ��� ���������.";
			link.l1.go = "CapComission_PrisonFree2";
		break;
		
		case "CapComission_PrisonFree2":
			dialog.text = "�� � ��� �� �������� ������ ��� ��� �������������.";
			link.l1 = "����� �� �����������, � ���� ���������� ������. ����� ����, � �������� ������� �������������� �������.";
			link.l1.go = "CapComission_PrisonFree3";
		break;
		
		case "CapComission_PrisonFree3":
			dialog.text = "�-�... �� ������. ������ ������, ��� ��������� �� ���� �������.";
			link.l1 = "����������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First_officer";
			NextDiag.CurrentNode = NextDiag.TempNode; 
			AddDialogExitQuest("OpenTheDoors");
		break;
		// -------------------------- �������� ''������'' ----------------------------
		
		case "F_ShipLetters_1":
			dialog.text = "��������, � ������.";
			link.l1 = "� ���� ���� ������� ���������. �����, �������� �� �� ������������ �������, � ��� ��� ����� ���������.....";
			link.l1.go = "F_ShipLetters_2";
			pchar.questTemp.different.GiveShipLetters.speakFort = true;
		break;
		
		case "F_ShipLetters_2":			
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 0)
			{
				dialog.text = "�����! �� ������� ��������, ����� ����� � �������� ����������.";
				link.l1 = "������� � �� ����....";
				link.l1.go = "exit";
			}
			else
			{
				if(!CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakUsurer_1"))
				{
					dialog.text = "��, �������� �� �������. �������, ������ � " + sti(pchar.questTemp.different.GiveShipLetters.price2) + " ���� �������� ��������� �������� �� ���� ������������, �������.";
					link.l1 = "�������, ���.";
					link.l1.go = "F_ShipLetters_3";	
					link.l2 = "������ �����������! ������ ������ ����....";
					link.l2.go = "F_ShipLetters_4";
				}
				else
				{
					if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 1)
					{
						dialog.text = "��, �� ��� �����������, ��������� ���������! �����, ��������� ����� ���������� �������� ��� "+ sti(pchar.questTemp.different.GiveShipLetters.price4) +" ����, �� ���������� � ������ � ���������� ��������������.";
						link.l1 = "�������, ���.";
						link.l1.go = "F_ShipLetters_3";
						link.l2 = "������ �����������! ������ ������ ����....";
						link.l2.go = "F_ShipLetters_4";
					}
					if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 2)
					{
						dialog.text = "����! ����� �����, ��� �� ������ �� ���. � �����, ��� ������������ ������� ���������� ��������� " + sti(pchar.questTemp.different.GiveShipLetters.price3) + " ����, ����� ���� �������� �������.";
						link.l1 = "�������, ���.";
						link.l1.go = "F_ShipLetters_3";
						link.l2 = "������ �����������! ������ ������ ����....";
						link.l2.go = "F_ShipLetters_4";
					}
				}
			}
		break;
		
		case "F_ShipLetters_3":
			dialog.text = "���! ��� ��� �����, �������.";
			link.l1 = "� ��� �������.";
			link.l1.go = "exit";
		break;
		
		case "F_ShipLetters_4":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 1)
			{
				if(!CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakUsurer_1"))
				{
					addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price2)); 
				}
				else
				{
					addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price4)); 
				}
			}
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 2)
			{
				if(!CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakUsurer_1"))
				{
					addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price2)); 
				}
				else
				{
					addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price3)); 
				}
			}
						
			if((sti(pchar.questTemp.different.GiveShipLetters.variant) == 0) || (sti(pchar.questTemp.different.GiveShipLetters.variant) == 2))
			{	
				ChangeCharacterComplexReputation(pchar,"nobility", -1); 
				OfficersReaction("bad"); 
			}	
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "8");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		
        case "ForGoodMove":
			dialog.text = NPCStringReactionRepeat("�� ����� ��� ���? �������� ���, ��� ��� ������ ���������� ��������, ���� ���� � �������.", "�� ��� ��������� ��� ���� �������.", 
				"����� � ��� ��? ��� ������ �� � ���� �������� �� ����!", "��, �����...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� �� �����, � �����"+ GetSexPhrase("","�") +" �� �������� ������� �� ����� ���������. ��� ����� ���������!", "��, ������ ���. �� � �����"+ GetSexPhrase("","�") +" ��� ���������� �� ��� ����.", 
				"��, ����� � ������ ���...", "������� ���������� �� ����� ������� �� �������� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "ForGoodMove_1";
		break;
		
        case "ForGoodMove_1":
			pchar.questTemp.jailCanMove.money = 20+drand(3)*10;
			if (sti(colonies[FindColony(npchar.city)].jail) && GetCharacterItem(pchar, "gold_dublon") >= sti(pchar.questTemp.jailCanMove.money))
			{
				dialog.text = "�� ��� ��, �� ���� ������� ��� ����������. " + FindRussianDublonString(sti(pchar.questTemp.jailCanMove.money)) + " - � ���� �� �� �������� ������, �� ������ ���������������� ������ �� ��������� � ���� ������������� � ������������.";
				link.l1 = "� ������"+ GetSexPhrase("��","��") +", ��� ���� ������!";
				link.l1.go = "ForGoodMove_agree";
				link.l2 = "�� ������, ������� ������ ��� ����������� �������� �� ���������.";
				link.l2.go = "exit";
			}
			else
			{
				dialog.text = RandPhraseSimple("���, ��� ������������� ��������� �������. ��� ����� ���, ����? �������, � �� ���������� ���� �� ������� ������.", "� �� ���� ��������� ����������� �� ������ ����������� �����. ����� ���, �� ������� ���!");
				link.l1 = "������, ��� �������...";
				link.l1.go = "exit";
			}
		break;
		
        case "ForGoodMove_agree":
            dialog.text = "�� ��� ��, �� ������ ���������� � ������, ��� �������, ��������...";
			link.l1 = "�������, ������.";
			link.l1.go = "exit";
			pchar.questTemp.jailCanMove = true;
			RemoveItems(pchar, "gold_dublon", sti(pchar.questTemp.jailCanMove.money));
			Log_Info("�� ������ " + FindRussianDublonString(sti(pchar.questTemp.jailCanMove.money)) + "!");
		break;
		
        case "KnowAboutPrisoner":
			switch (pchar.questTemp.jailCanMove.ownerPrison)
			{
				case "0": sTemp = "�� ��������."; break;
				case "1": sTemp = "�� ���������� � ���������."; break;
				case "2": sTemp = "�� ��������� � ��������� ���������."; break;
				case "3": sTemp = "�� ������� �� ���������."; break;
				case "4": sTemp = "�� ������ �����."; break;
				case "5": sTemp = "�� ���������."; break;
				case "6": sTemp = "�� �������������� � ����������������."; break;
			}
			dialog.text = sTemp;
			link.l1 = "�������... � ���� ���� ������ �� ���� �����, �����, ��� ��� ���-������ ������������� ��� ����������?";
			link.l1.go = "KnowAboutPrisoner_" + pchar.questTemp.jailCanMove.ownerPrison;
			DeleteAttribute(pchar, "questTemp.jailCanMove.City");
		break;
		
        case "KnowAboutPrisoner_0":
			dialog.text = "���, �������. ����� ���������� ������ ������ � ��. �� �� ������ �������� � �����������!";
			link.l1 = "���, �������...";
			link.l1.go = "notFree_exit";
		break;	
		
		case "KnowAboutPrisoner_1":
			dialog.text = "�� ������? ��� ����� - �� ��������! ���������� ������� ��� ����� ������ �� ����. �������� �� ����.";
			link.l1 = "�����. ��� �����...";
			link.l1.go = "notFree_exit";
		break;
		
        case "KnowAboutPrisoner_2":
			dialog.text = "�� �����. ����� �� ����� �������� ������� ������ ������. ��� ��� ���� � �� �������.";
			link.l1 = "��, ����.";
			link.l1.go = "notFree_exit";
		break;
		
        case "KnowAboutPrisoner_3":
			dialog.text = "���, �������. �� ���, � ��� ������ ������ � ������!";
			link.l1 = "� ���! ������ �������, ���������...";
			link.l1.go = "notFree_exit";
		break;
		
        case "KnowAboutPrisoner_4":
			dialog.text = "�� ���� ����. ���� �������� ����� ����� ������. � ��������� ��� �� ����, �� � ������ ����� �� ����� ������ - ���� �� ����...";
			link.l1 = "��� ������� ��� ���, ���������. � �������, � �������� ��������, �����������.";
			link.l1.go = "KnowAboutPrisoner_free";
		break;
		
        case "KnowAboutPrisoner_5":
			dialog.text = "����������? ������ ��������. � ���� ����� ������, ��������� ����� ������� ������ ����� �� ����� �������� ������.";
			link.l1 = "��� ������� ��� ���, ���������. � �������, � �������� ��������, �����������.";
			link.l1.go = "KnowAboutPrisoner_free";
		break;
		
		case "KnowAboutPrisoner_6":
			dialog.text = "��. � ����� ������ ���� �����. �� ����� �������� ������ ���� � ����� �� ���� ������...";
			link.l1 = "��� ������� ��� ���, ���������. � �������, � �������� ��������, �����������.";
			link.l1.go = "KnowAboutPrisoner_free";
		break;
		
        case "KnowAboutPrisoner_free":
			pchar.questTemp.jailCanMove.ownerPrison.money = 50+drand(10)*10;
			dialog.text = "������, ������������. " + FindRussianDublonString(sti(pchar.questTemp.jailCanMove.ownerPrison.money)) + " �� �����, � ��������� ��� ���� ����� ������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(pchar.questTemp.jailCanMove.ownerPrison.money))
			{
				link.l1 = LinkRandPhrase("��� ��� �������! � ��������!","�� �����, ������!","�������. � ����� �������� �����.");
				link.l1.go = "KnowAboutPrisoner_agree";
			}
			link.l2 = "���, ���������� �����. ��������.";
			link.l2.go = "KnowAboutPrisoner_exit";
		break;
		
        case "KnowAboutPrisoner_agree":
			dialog.text = "���, �� ������ ������ � ��� ������ � �������� ����� ���������.";
			link.l1 = "�������.";
			link.l1.go = "exit";
			pchar.questTemp.jailCanMove = true;
			RemoveItems(pchar, "gold_dublon", sti(pchar.questTemp.jailCanMove.ownerPrison.money));
			Log_Info("�� ������ " + FindRussianDublonString(sti(pchar.questTemp.jailCanMove.ownerPrison.money)) + "!");
			DeleteAttribute(pchar, "questTemp.jailCanMove.ownerPrison");
			sld = characterFromId(pchar.questTemp.jailCanMove.prisonerId)
			LAi_CharacterEnableDialog(sld);
			sld.dialog.currentnode = "ToPrisonHead_canMove";
		break;
		
        case "KnowAboutPrisoner_exit":
			dialog.text = "��, ��������, ������� ����� � �� ���...";
			link.l1 = "� �� ����. � ������"+ GetSexPhrase("","�") +" �������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.jailCanMove.ownerPrison");
			sld = characterFromId(pchar.questTemp.jailCanMove.prisonerId);
			LAi_CharacterEnableDialog(sld);
			sld.dialog.currentnode = "ToPrisonHead_expansive";
		break;
		
        case "notFree_exit":
			sld = characterFromId(pchar.questTemp.jailCanMove.prisonerId);
			LAi_CharacterEnableDialog(sld);
			sld.dialog.currentnode = "ToPrisonHead_notFree";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//---------------- ��������� ------------------
        case "First_protector":
			if (sti(pchar.questTemp.jailCanMove))
			{
				dialog.text = RandPhraseSimple("�� ������ ������, ��������� ��������...", "������� ������ ���������� ������. �� ������ �������� ���������.");
				link.l1 = "��, ��� � �����.";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.jailCanMove.ownerPrison.money");
			}
			else
			{
				dialog.text = RandPhraseSimple("��������� ����� ��� ���������� ���������� ������ ������������� ���������!", "� ���������� ������ ���������� ������. ���� �� ����������� ������ ������ ��� ��� ���������� - ���� �����!");
				link.l1 = RandPhraseSimple("�������", "����") + ", ������.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "First_protector";
		break;
		//---------------- ������� ------------------
        case "First_soldier":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            dialog.text = RandPhraseSimple("� �� �����, �� ���������� ����.", "��������� ����, � �� ���� � ���� �������������.");
			link.l1 = "������, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First_soldier";
		break;
		//---------------- ����������� ------------------
        case "First_prisoner":
 				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			if (GetNationRelation2MainCharacter(sti(npchar.nation)) == RELATION_ENEMY)
			{
				dialog.text = LinkRandPhrase("��-��, �� ���� �� ������!!", "���� ��, "+ GetSexPhrase("��������","�������") +", ����!!!", "��, ������! �� �� �����, ��� ����� ���� ������ ������������!");
				link.l1 = RandPhraseSimple("���!", "����...");
				link.l1.go = "NoMoreTalkExit";
				if (rand(10) > 6 && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && !CheckAttribute(pchar, "GenQuest.PrisonQuestLock") && !CheckAttribute(pchar, "quest.GivePrisonFree") && !CheckAttribute(pchar, "quest.GivePrisonFree_Over") && !CheckAttribute(pchar, "quest.DeliverToBander")) // Addon 2016-1 Jason ��������� �������
				{
					dialog.text = RandPhraseSimple("������, "+ GetSexPhrase("�������","�������") +"!! ������� ����!", "��������, "+ GetSexPhrase("��������","�������") +", ���� ��� ����"+ GetSexPhrase("","�") +", ������ ������.");
					link.l1 = "� ����� ��� �����?";
					link.l1.go = "Prisoner_1"; // �� ����� ������������ ������������
				}
			}
			else
			{
				dialog.text = LinkRandPhrase("���� ����� �� ������, ���� ����...", "����, �����"+ GetSexPhrase("��","��") +" ��... ���� �� �� ��� � ������ �� ��������! ���-��-��...", "� �� � ��� �� �������!");
				link.l1 = RandPhraseSimple("��������!", "��� ��� �� ���� ����...");
				link.l1.go = "NoMoreTalkExit";
				if (rand(10) > 6 && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && !CheckAttribute(pchar, "GenQuest.PrisonQuestLock") && !CheckAttribute(pchar, "quest.GivePrisonFree_Over") && !CheckAttribute(pchar, "quest.GivePrisonFree") && !CheckAttribute(pchar, "quest.DeliverToBander") && !sti(colonies[FindColony(npchar.city)].HeroOwn)) // Addon 2016-1 Jason ��������� �������
				{
					dialog.text = RandPhraseSimple("������, "+ GetSexPhrase("��������","�������") +", �� ������� ���� ���� ������ ��� ������!", "�� ��������, "+ GetSexPhrase("�������","�������") +", ����� ���������.");
					link.l1 = "� ����� ��� �����?";
					if (rand(1))
					{
						link.l1.go = "Prisoner_1"; // �� ����� ������������ ������������
					}
					else
					{
						link.l1.go = "Deliver_1"; // �� ����� �������� ��������
					}
				}
			}
		break;
		// -------------------- ������������ ������������ --------------------
        case "Prisoner_1":
            dialog.text = "����� ��������� ����. �� �� ������, ��� ������ � � ����� ����. ��� �� ��������� ������...";
			link.l1 = "����?!";
			link.l1.go = "Prisoner_2";
			GetChestPlaceName();
			pchar.questTemp.jailCanMove.prisonerId = npchar.id; //�������� Id
			pchar.questTemp.jailCanMove.IsTrue = rand(4); //��� �����
			pchar.questTemp.jailCanMove.Item1 = GenQuestPrison_GenerateArtefact();
			pchar.questTemp.jailCanMove.Item2 = GenQuestPrison_GenerateBlade();
			pchar.questTemp.jailCanMove.Name = GetFullName(npchar); //��� �����
		break;
        case "Prisoner_2":
            dialog.text = "��� ������"+ GetSexPhrase("","�") +". ������ ��� ���������, � � ����� �������������.";
			link.l1 = "��� ���������. ��� �� ����� � ��� ������ ��� ����������?";
			link.l1.go = "Prisoner_3";
		break;
        case "Prisoner_3":
            dialog.text = "���� ����� " + GetFullName(npchar) + ". ���-��� � ���� ���������� � �������� �����. ������ ���� ������ � ������ �� " + XI_ConvertString(pchar.questTemp.jailCanMove.islandId + "Acc") + ". ��� � ����� � ���� ������� ����. �������� ��� � ������� �������!";
			link.l1 = "� ��� ��� � ���� � �����? � ������ ��� �����, ��� ���� ����� - ������?";
			link.l1.go = "Prisoner_4";
		break;
        case "Prisoner_4":
            dialog.text = "������� ����, � ������ ��������� ������! � � ����� � ������� ������ � �������������...";
			link.l1 = "���, ��������. � �� ��������� ��������� ������ ��-�� ������������� �����. ������...";
			link.l1.go = "Prisoner_5";
			if (GetNationRelation2MainCharacter(sti(npchar.nation)) != RELATION_ENEMY)
			{			
				link.l2 = "�������, ����� ��������... ��������� ���������: � ���� �������� ������ � ������ � ������� ���� �� ���� �������. ���� ��� ���������, � ����, ����� �� �� ������� �� ���� �� ��� ���, ���� �� �� ��������� �� ����� �� " + XI_ConvertString(pchar.questTemp.jailCanMove.islandId + "Dat") + ". ����?";
				link.l2.go = "Prisoner_agree"; //������� ������ ����������
				link.l3 = "��, ������, � ���������� ������ ���� - �������� � ����������� ������. ��������, ������� ������ ����� �� ���� ������������.";
				link.l3.go = "ToPrisonHead_agree"; //������ ������ ����������
			}
			else
			{
				link.l2 = "��, ������, ������ ���� � ������ ������. � ����, ����� �� �� ������� �� ���� �� ��� ���, ���� �� �� ��������� �� ����� �� " + XI_ConvertString(pchar.questTemp.jailCanMove.islandId + "Dat") + ". ����?";
				link.l2.go = "Prisoner_agree_3"; //������� ������ ����������, ����� ��������� �����
			}
		break;
        case "Prisoner_5":
            dialog.text = RandPhraseSimple("���� �� �������"+ GetSexPhrase("","�") +", �������!!", "���� ���� ���������, ����...");
			link.l1 = RandPhraseSimple("� ���� ����� ��������. ������...", "������ ����� �� ���� ������...");
			link.l1.go = "NoMoreTalkExit";
		break;
        case "Prisoner_agree":
            dialog.text = "����, ��� �������� �� ����������.";
			link.l1 = "������. � ������ ������ ���� �����, ������ ������, � ����� �����������. �� �����?";
			link.l1.go = "Prisoner_agree_1";
		break;
        case "Prisoner_agree_1":
            dialog.text = "��, "+ GetSexPhrase("��������","�������") +", � �����!";
			link.l1 = "�� ����!";
			link.l1.go = "Prisoner_agree_2";
		break;
        case "Prisoner_agree_2":
			string slai_group = GetNationNameByType(sti(npchar.nation))  + "_citizens";
			LAi_group_AttackGroup(slai_group, LAI_GROUP_PLAYER);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			ReOpenQuestHeader("GivePrisonFree");
			AddQuestRecord("GivePrisonFree", "1");
            AddQuestUserData("GivePrisonFree", "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
            AddQuestUserData("GivePrisonFree", "sIsland", XI_ConvertString(pchar.questTemp.jailCanMove.islandId+"Dat"));
			pchar.quest.GivePrisonFree_Death.win_condition.l1 = "NPC_Death";
			pchar.quest.GivePrisonFree_Death.win_condition.l1.character = npchar.id;
			pchar.quest.GivePrisonFree_Death.win_condition = "GivePrisonFree_Death";
			Pchar.quest.GivePrisonFree.win_condition.l1 = "location";
			Pchar.quest.GivePrisonFree.win_condition.l1.location = pchar.questTemp.jailCanMove.placeId;
			Pchar.quest.GivePrisonFree.win_condition = "GivePrisonFree";			
			DeleteAttribute(npchar, "LifeDay");
			GiveItem2Character(npchar, "unarmed");
			EquipCharacterbyItem(npchar, "unarmed");
			GetCharacterPos(npchar, &locx, &locy, &locz);	
			ChangeCharacterAddressGroup(npchar, npchar.location, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			LAi_SetActorType(npchar);
			LAi_group_Register("DeliveQuest_Prison");
			LAi_group_SetRelation("DeliveQuest_Prison", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, "DeliveQuest_Prison", LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_MoveCharacter(npchar, "DeliveQuest_Prison");
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

        case "Prisoner_agree_3":
            dialog.text = "����, ��� �������� �� ����������.";
			link.l1 = "������. ������ �� ���� ��� ����� �������, ��� ����� ��� ��������� �� ����� �������. �� ��������!";
			link.l1.go = "Prisoner_agree_4";
		break;
        case "Prisoner_agree_4":
			ReOpenQuestHeader("GivePrisonFree");
			AddQuestRecord("GivePrisonFree", "1");
            AddQuestUserData("GivePrisonFree", "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
            AddQuestUserData("GivePrisonFree", "sIsland", XI_ConvertString(pchar.questTemp.jailCanMove.islandId+"Dat"));
			pchar.quest.GivePrisonFree_Death.win_condition.l1 = "NPC_Death";
			pchar.quest.GivePrisonFree_Death.win_condition.l1.character = npchar.id;
			pchar.quest.GivePrisonFree_Death.win_condition = "GivePrisonFree_Death";
			Pchar.quest.GivePrisonFree.win_condition.l1 = "location";
			Pchar.quest.GivePrisonFree.win_condition.l1.location = pchar.questTemp.jailCanMove.placeId;
			Pchar.quest.GivePrisonFree.win_condition = "GivePrisonFree";
			DeleteAttribute(npchar, "LifeDay");
			GiveItem2Character(npchar, "unarmed");
			EquipCharacterbyItem(npchar, "unarmed");
			GetCharacterPos(npchar, &locx, &locy, &locz);	
			ChangeCharacterAddressGroup(npchar, npchar.location, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			LAi_SetActorType(npchar);
			LAi_group_Register("DeliveQuest_Prison");
			LAi_group_SetRelation("DeliveQuest_Prison", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, "DeliveQuest_Prison", LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_MoveCharacter(npchar, "DeliveQuest_Prison");
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

        case "ToPrisonHead_agree":
            dialog.text = "��, ��������. ��-�-�, ���������� ��! ������ �� ����� �������, ����� ���� ���� ���� ����� ��� �� �����...";
			link.l1 = "���, � ��� �����.";
			link.l1.go = "NoMoreTalkExit";
			pchar.questTemp.jailCanMove.City = npchar.City; //�����
			pchar.questTemp.jailCanMove.ownerPrison = rand(6); //�������� ������������
			SetTimerCondition("GivePrisonFree_Over", 0, 0, 2, false);
			AddQuestRecord("GivePrisonFree", "5");
			AddQuestUserData("GivePrisonFree", "sSex", GetSexPhrase("��","���"));
            AddQuestUserData("GivePrisonFree", "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
		break;

        case "ToPrisonHead_canMove":
            dialog.text = "��, ��� �������, "+ GetSexPhrase("��������","�������") +"?";
			link.l1 = "��� �������, � ���� �������� ����.";
			link.l1.go = "ToPrisonHead_canMove_1";
		break;
        case "ToPrisonHead_canMove_1":
            dialog.text = "��, ��� ������ ������ �������! ���� ������, ��� � ���!";
			link.l1 = "�������� �����. � ����, ����� ��� �����, ���� �� �� ��������� �� ����� �� " + XI_ConvertString(pchar.questTemp.jailCanMove.islandId + "Dat") + ", �� �� ������� �� ���� �� �� ���. �� ������ ������. �� ��������?";
			link.l1.go = "ToPrisonHead_canMove_2";
		break;
        case "ToPrisonHead_canMove_2":
            dialog.text = "�������, ��������! �� � �������� ��� �� ����������.";
			link.l1 = "����� �� ��������.";
			link.l1.go = "ToPrisonHead_canMove_exit";
		break;
        case "ToPrisonHead_canMove_exit":
			pchar.quest.GivePrisonFree_Over.over = "yes";
			ReOpenQuestHeader("GivePrisonFree");
			AddQuestRecord("GivePrisonFree", "1");
            AddQuestUserData("GivePrisonFree", "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
            AddQuestUserData("GivePrisonFree", "sIsland", XI_ConvertString(pchar.questTemp.jailCanMove.islandId+"Dat"));
			pchar.quest.GivePrisonFree_Death.win_condition.l1 = "NPC_Death";
			pchar.quest.GivePrisonFree_Death.win_condition.l1.character = npchar.id;
			pchar.quest.GivePrisonFree_Death.win_condition = "GivePrisonFree_Death";
			Pchar.quest.GivePrisonFree.win_condition.l1 = "location";
			Pchar.quest.GivePrisonFree.win_condition.l1.location = pchar.questTemp.jailCanMove.placeId;
			Pchar.quest.GivePrisonFree.win_condition = "GivePrisonFree";			
			DeleteAttribute(npchar, "LifeDay");
			GiveItem2Character(npchar, "unarmed");
			EquipCharacterbyItem(npchar, "unarmed");
			GetCharacterPos(npchar, &locx, &locy, &locz);	
			ChangeCharacterAddressGroup(npchar, npchar.location, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			LAi_SetActorType(npchar);
			LAi_group_Register("DeliveQuest_Prison");
			LAi_group_SetRelation("DeliveQuest_Prison", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			//LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, "DeliveQuest_Prison", LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			LAi_group_MoveCharacter(npchar, "DeliveQuest_Prison");
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

        case "ToPrisonHead_notFree":
			switch (pchar.questTemp.jailCanMove.ownerPrison)
			{
				case "0": sTemp = "��������"; break;
				case "1": sTemp = "���������"; break;
				case "2": sTemp = "������"; break;
				case "3": sTemp = "���������"; break;
			}
            dialog.text = "��, ��� �������, "+ GetSexPhrase("��������","�������") +"?";
			link.l1 = "��� �� ������� ������������ � ����� ������������. ���� �������� � " + sTemp + ", ��� ��� �� � ����� ������� ���� ���� �� �����.";
			link.l1.go = "ToPrisonHead_notFree_1";
			DeleteAttribute(pchar, "questTemp.jailCanMove.ownerPrison");
		break;
		
        case "ToPrisonHead_notFree_1":
            dialog.text = "���� ��������!.. ��� ������!! � ��� ������ ��� ������? � �� ����� ����� ������!";
			link.l1 = "����� ����, ��������, �� � ����� �� ���� ���� ������.";
			link.l1.go = "ToPrisonHead_notFree_2";
			link.l2 = "�������� ���� ���������� ���� �����. � ������ ������ ���� �����, ������ ������, � ����� �����������. �� �����?";
			link.l2.go = "Prisoner_agree_1";
			pchar.quest.GivePrisonFree_Over.over = "yes";
		break;
		
        case "ToPrisonHead_notFree_2":
            dialog.text = RandPhraseSimple("���� �� �������"+ GetSexPhrase("","�") +", �������!!", "���� ���� ���������, ����...");
			link.l1 = "� ���� ����� ��������. ������...";
			link.l1.go = "NoMoreTalkExit";
			AddQuestRecord("GivePrisonFree", "7");
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			DeleteAttribute(pchar, "questTemp.jailCanMove.islandId");	
			DeleteAttribute(pchar, "questTemp.jailCanMove.placeId");
			DeleteAttribute(pchar, "questTemp.jailCanMove.prisonerId");
			DeleteAttribute(pchar, "questTemp.jailCanMove.IsTrue");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Sum");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Name");
		break;

        case "ToPrisonHead_expansive":
			dialog.text = "��, ��� ���������, "+ GetSexPhrase("��������","�������") +"?";
			link.l1 = "����� �� ���� ������������ ������� �����, � ���� ��� ����� �����. � ��������"+ GetSexPhrase("","�") +" ���������� �� ������ ����.";
			link.l1.go = "ToPrisonHead_notFree_2";
			pchar.quest.GivePrisonFree_Over.over = "yes";
		break;
		//==> � �����, ��� ���� ���������
        case "PrisonerInPlace":
			switch (sti(pchar.questTemp.jailCanMove.IsTrue))
			{
				case 0:
					dialog.text = "������, � ��� �������� ���, �� ����� ����� �� �����. ����� ����, ��� ��� �����, ��������, ���-�� �������� ��� �� ���.";
					link.l1 = "��� ����� ����� ����?!";
					link.l1.go = "PrisonerInPlace_1";
				break;
				case 1:
					dialog.text = "� ����� ���! ������������� ������ ���, ��� � �� � �������.";
					link.l1 = "�����������. �� ���, ����� ������?";
					link.l1.go = "Node_1";
				break;
				case 2:
					dialog.text = "�� ��� ��, ��� �����. �������, ������, �� ��� ���, ��� � ���� ����. ��� �������������� - �������� ����.";
					link.l1 = "��, ���� � � ����� ����, �� ����. �� ��� ��, ������� � �� ���.";
					link.l1.go = "Node_2";
				break;
				case 3:
					dialog.text = "�������, ��������, ��� ��� �����... ������, ��� �����.";
					link.l1 = "���? �� ���� �������, �������! � ���� �������"+ GetSexPhrase("","�") +" ��-�� �������, �����"+ GetSexPhrase("��","���") +" �� ���� ������, � ��� ���� ����?! ��� ���� � ��� �� ������!";
					link.l1.go = "Node_3";
				break;
				case 4:
					dialog.text = "���� ������... �� ��� �� ���? �� ����� ����!";
					link.l1 = "�� ����, ��������? ��� ��� ����? ������ �� ������, ��� ��� ���!";
					link.l1.go = "Node_4";
				break;
			}
		break;
			
		case "Node_1":
			dialog.text = "��, �������, ��� ��������������. �������� �������� ����.";
			link.l1 = "�� ��, ������� ��� ����� �������!";
			link.l1.go = "PrisonerInPlace_3";
			Log_Info("�� �������� ���� ���� �����");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "icollection", 1+drand(1));
			TakeNItems(pchar, "chest", 4+drand(4));
			TakeNItems(pchar, "jewelry1", 70+rand(15));
			TakeNItems(pchar, "jewelry2", 50+rand(15));
			TakeNItems(pchar, "jewelry3", 60+rand(15));
			TakeNItems(pchar, "jewelry4", 40+rand(10));
			TakeNItems(pchar, "jewelry5", 10+rand(10));
			TakeNItems(pchar, "jewelry46", 60+rand(20));
			TakeNItems(pchar, "jewelry47", 40+rand(15));
			TakeNItems(pchar, "jewelry40", 60+rand(20));
			AddQuestRecord("GivePrisonFree", "3_1");
			AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			CloseQuestHeader("GivePrisonFree");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item1");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item2");
		break;
			
		case "Node_2":
			dialog.text = "�������, ����� ����� ������� ���� ��� ���� ��������� �������. �������� ��� ����� ����� ����.";
			link.l1 = "��, ���� ���-�� �������� ������ �� ���� ������������! ����� ��� ����.";
			link.l1.go = "PrisonerInPlace_3";
			Log_Info("�� �������� ���� ���� �����");
			PlaySound("interface\important_item.wav");
			sTemp = pchar.questTemp.jailCanMove.Item1;
			TakeNItems(pchar, sTemp, 1);
			TakeNItems(pchar, "jewelry5", 40+rand(10));
			TakeNItems(pchar, "jewelry6", 20+rand(20));
			TakeNItems(pchar, "jewelry17", 80+rand(20));
			TakeNItems(pchar, "jewelry13", 10+rand(10));
			TakeNItems(pchar, "jewelry10", 20+rand(20));
			TakeNItems(pchar, "jewelry12", 50+rand(20));
			TakeNItems(pchar, "jewelry11", rand(2)+1);
			AddQuestRecord("GivePrisonFree", "3_2");
			AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			CloseQuestHeader("GivePrisonFree");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item1");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item2");
		break;
			
		case "Node_3":
			dialog.text = "���������, �������, �� ����������, ����� ��� �������. � ���� �����, ��� � ��. ���� ������� � ������ �� ������, �������. �� ���� ���� ������������ ������ ��������, � ��� �������� ��� ������� � �����\n����� ���, �� � ������� ��� ���� ������� ����. �������� ��, � ��������� ���� � �����. ��������, � ��� �� ��� �� ��� �������� ���� ������ ������.";
			link.l1 = "�����, ��� ����� ����� � ���� ������. ��������� ����, ��� � ��������"+ GetSexPhrase("��","��") +".";
			link.l1.go = "PrisonerInPlace_3";
			Log_Info("�� �������� ����������");
			PlaySound("interface\important_item.wav");
			sTemp = pchar.questTemp.jailCanMove.Item2;
			TakeNItems(pchar, sTemp, 1);
			AddQuestRecord("GivePrisonFree", "3_3");
			AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			CloseQuestHeader("GivePrisonFree");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item1");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item2");
		break;
			
		case "Node_4":
			dialog.text = "���!!! ��� ������������� ���! ��������� �������... �������, ��������, � ������������� �����, ��� �� �����! ��, ������, � ������! �� ���� ������ ������ ��� ��� ���������...";
			link.l1 = "��-��, ������, ������ � ���� ����� ��������� ��������, ��������. �� ���-���� � ���� ��������� ���� ����������.";
			link.l1.go = "Node_4_1";
		break;
			
		case "Node_4_1":
			dialog.text = "� ���� ��� ����� �����. ��������� �����, �������! �� �� ���� ��� ������ ���������, ��� �� ������ �� ��� ������... � �������, ��� ��� �����. ��, ��� �� ������, ��� �� ���.";
			link.l1 = "��� �� ����� �����? ����� ��� ����, ����!";
			link.l1.go = "Node_4_2";
		break;
			
		case "Node_4_2":
			if (CheckCharacterItem(pchar, "map_part1"))
			{
				GiveItem2Character(pchar, "map_part2");
			}
			else
			{
				GiveItem2Character(pchar, "map_part1");
			}
			dialog.text = "���, ������, �������. �������, ��������� ����, ����������... � � � ����� ���� �����, ��� ���� ���. �����, �� ����������� �� ����� ������, ��� ��, � �������� ��� ����. ����� ���.";
			link.l1 = "�� ��... ��������� ���-���� ��� ����� ������. ����� ������ �������� �����. �����, ����������, ����, �� ������������� �����, ��� �����.";
			link.l1.go = "PrisonerInPlace_4";
		break;
			
		case "PrisonerInPlace_1":
			dialog.text = "�� ����� ������, "+ GetSexPhrase("��������","�������") +". ��� � �� ����� � ����� ���������\n�� �����, �� ���, ���� ������, ���������, ����� ���. ��, � ��� ����!\n������, "+ GetSexPhrase("����","�������") +", �������, ��� ����"+ GetSexPhrase("","��") +" ��� �����. � ���� ������� ���� �����!";
			link.l1 = "�� �� ��������! �������, � ��� ���� ��� ������ ����?! ��... � �� ����, ����!";
			link.l1.go = "PrisonerInPlace_2";
			AddQuestRecord("GivePrisonFree", "4");
			AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			CloseQuestHeader("GivePrisonFree");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item1");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item2");
		break;
			
        case "PrisonerInPlace_2":
			LAi_group_Delete("EnemyFight");
			DeleteAttribute(pchar, "questTemp.jailCanMove.islandId");	
			DeleteAttribute(pchar, "questTemp.jailCanMove.placeId");
			DeleteAttribute(pchar, "questTemp.jailCanMove.prisonerId");
			DeleteAttribute(pchar, "questTemp.jailCanMove.IsTrue");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Sum");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Name");
			chrDisableReloadToLocation = false;
			LAi_LocationDisableMonstersGen(pchar.location, false);
			npchar.lifeDay = 0;
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(NPChar, "reload", "reload1_back", "none", "", "", "", -1);
			DialogExit();

            Pchar.quest.DeletePrisonGroup.win_condition.l1 = "ExitFromLocation";
            Pchar.quest.DeletePrisonGroup.win_condition.l1.location = pchar.location;
            Pchar.quest.DeletePrisonGroup.win_condition = "DeletePrisonGroup";
		break;
		
        case "PrisonerInPlace_3":
			dialog.text = "����������, ��������. � ������� ���!";
			link.l1 = "������...";
			link.l1.go = "PrisonerInPlace_2";
		break;
		
        case "PrisonerInPlace_4":
			dialog.text = "������� ���, �������! � ���� �������� �� ��� �� ����� ����� ����!";
			link.l1 = "����� ���� ��������! ��� � �����...";
			link.l1.go = "PrisonerInPlace_2";
			AddQuestRecord("GivePrisonFree", "3_4");
            AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Name);
			AddQuestUserData("GivePrisonFree", "sSex", GetSexPhrase("","�"));
			CloseQuestHeader("GivePrisonFree");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item1");
			DeleteAttribute(pchar, "questTemp.jailCanMove.Item2");
		break;
        
		// -------------------- ������������ ������������ --------------------
		// ------------------------ �������� ������ --------------------------
        case "Deliver_1":
			dialog.text = "���� ������ " + GetFullName(npchar) + ". ���� � ���� � ���� ������� ����, ��-��...";
			link.l1 = "��� �����?";
			link.l1.go = "Deliver_2";
		break;
        case "Deliver_2":
			dialog.text = "����� �������� ������ �� ����. ��������?";
			link.l1 = "� ����� ��� � ����� �����?";
			link.l1.go = "Deliver_3";
		break;
        case "Deliver_3":
			dialog.text = "�� ������ ���� ������, ���� ��... �� ��� ���, ����������?";
			link.l1 = "���, ���� ��� �� ����������.";
			link.l1.go = "Prisoner_5";
			link.l2 = "��, ���� ������ ������ �� ����, �� ��������.";
			link.l2.go = "Deliver_agree";
		break;
        case "Deliver_agree":
			dialog.text = "������. ������ ������ ���� �����������. � ������ ���� ��� ������ ��� �����, ���������� ��� � ����, ����� ��� ���� �� �������. � ����� ���� - �� �����, ���� ����� ��������.";
			link.l1 = "��� ��������?";
			link.l1.go = "Deliver_4";
		break;
        case "Deliver_4":
			dialog.text = "������ ��������. �� ������ ���������, � ���� ��������������... ��� � ������ ����� �������, ��� ���� ���� ��� ��������� �� ��������. ������ ���� � ����, ��� ����� � ��� ��� ��� �������, �� �����. ��� ��� �� ����.";
			link.l1 = "����. ��, ����� ���� ��������.";
			link.l1.go = "Deliver_5";
		break;
        case "Deliver_5":
			pchar.questTemp.jailCanMove.Deliver.locationId = GetBanderLocation(npchar); //Id �������
			if (pchar.questTemp.jailCanMove.Deliver.locationId == "none")
			{
				dialog.text = "��, ���-�� �� ��� �� ���������. � ���������. �����, �������, �� ���� �����!";
				link.l1 = "��� ��� ��! �� �����, ��� ������...";
				link.l1.go = "NoMoreTalkExit";
				DeleteAttribute(pchar, "questTemp.jailCanMove.Deliver");
			}
			else
			{
				dialog.text = "�����. ������� ����, "+ GetSexPhrase("��������","�������") +"!";
				link.l1 = "�� �� �� ���.";
				link.l1.go = "NoMoreTalkExit";
				GiveItem2Character(Pchar, "Malyava");
				pchar.questTemp.jailCanMove.Deliver.Id = npchar.id; //Id ����
				pchar.questTemp.jailCanMove.Deliver.name = GetFullName(npchar); //��� ����
				pchar.questTemp.jailCanMove.Deliver.City = npchar.city; //����� (Id �������)
				pchar.questTemp.jailCanMove.Deliver.good = rand(3); //��������� ��� ���
				pchar.questTemp.jailCanMove.Deliver.price = rand(6)*500+500; //���� ������
				pchar.quest.DeliverToBander.win_condition.l1 = "location";
				pchar.quest.DeliverToBander.win_condition.l1.location = pchar.questTemp.jailCanMove.Deliver.locationId;
				pchar.quest.DeliverToBander.win_condition = "DeliverToBander";
				pchar.quest.DeliverToBander.again = true; 
				SetTimerCondition("DeliverToBander_over", 0, 0, 2, false);
				ReOpenQuestHeader("GivePrisonFree");
				AddQuestRecord("GivePrisonFree", "8");
				AddQuestUserData("GivePrisonFree", "sSex", GetSexPhrase("c�","���"));
				AddQuestUserData("GivePrisonFree", "sCity", XI_ConvertString("Colony"+npchar.city+"Gen"));
				AddQuestUserData("GivePrisonFree", "sName", pchar.questTemp.jailCanMove.Deliver.name);
			}
		break;
		
		// Warship, 16.05.11. ����� "���������� �� �������".
		case "JusticeOnSale_1":
			dialog.text = "��, �� ��� ���� �� ��������� � �����������. � ��� ��� �� ����� ����������, " + GetAddress_Form(NPChar) + "?";
			link.l1 = "��� ����� ��������� ��������� ��� � ���������� ���� ������� ��������.";
			link.l1.go = "JusticeOnSale_2";
			link.l2 = "�� ���� ����� �����, ��� �� ���������.";
			link.l2.go = "JusticeOnSale_3";
			
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale.PrisonWait");
		break;
		
		case "JusticeOnSale_2":
			dialog.text = "��� ���������� ��������� � ����������� �����������, " + GetAddress_Form(NPChar) + ", ���� ��������� ����� �������� ���� �� �������!";
			link.l1 = "��� � ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First_officer";
		break;
		
		case "JusticeOnSale_3":
			dialog.text = "����������, " + GetFullName(PChar) + ", ���� ��� ��� ���� ��� ������� ����� ����������� �����, ����� � ������! ��� �� ������ ���������� ��� ������������?";
			link.l1 = "� ������, ��� ��������� ��������������� � ���� � ��� ���, ����� �� ���? ������ ������� �� �������� ������������� ����������� ��������.";
			link.l1.go = "JusticeOnSale_4";
		break;
		
		case "JusticeOnSale_4":
			dialog.text = "� ��� ��� ���������� � ���������� ������, �� ��� ������ �� ������, ������� " + GetFullName(PChar) + "! ���� ������� ���������� ����� �������, �, ��������, �� ������ � ���������� ��������. � ����� ������ � ����� ��� ���� �� ������������?";
			link.l1 = "��, ����� ���� ��� ����� �������� ������� ����� �����������?";
			link.l1.go = "JusticeOnSale_5_WithoutMoney";
			
			if(sti(PChar.money) >= 5000)
			{
				link.l2 = "����� ��� 5000 ���� � ��� ����� �������� ������� ����� �����������?";
				link.l2.go = "JusticeOnSale_5";
			}
		break;
		
		case "JusticeOnSale_5_WithoutMoney":
			if(GetCharacterSkill(PChar, SKILL_LEADERSHIP) > dRand(100) || sti(PChar.money) < 5000)
			{
				dialog.text = "������, " + GetAddress_Form(NPChar) + ", ��������� ����� ���������� � �������, ���� � �� ���������.";
				link.l1 = "������� ��������� ��������� ����������, �� ��������?";
				link.l1.go = "JusticeOnSale_6";
			}
			else
			{
				dialog.text = "���, " + GetAddress_Form(NPChar) + ", ��� �� ������.";
				link.l1 = "� ����� ������ ����� ��� 5000 ���� ����� ����� ������� �������?";
				link.l1.go = "JusticeOnSale_5";
			}
		break;
		
		case "JusticeOnSale_5":
			dialog.text = "������, " + GetAddress_Form(NPChar) + ", ��������� ����� ���������� � �������, ���� � �� ���������.";
			link.l1 = "������� ��������� ��������� ����������, �� ��������?";
			link.l1.go = "JusticeOnSale_6";
			AddMoneyToCharacter(PChar, -5000);
			PChar.GenQuest.JusticeOnSale.PrisonMoney = true;
		break;
		
		case "JusticeOnSale_6":
			DialogExit();
			sld = GetCharacter(NPC_GenerateCharacter("JusticeOnSale_Smuggler", "mercen_"+(rand(9)+1), "man", "man", sti(PChar.rank)+5, PIRATE, -1, true, "marginal"));
			SetFantomParamFromRank(sld, sti(PChar.rank)+5, true);
			sld.name = PChar.GenQuest.JusticeOnSale.SmugglerName;
			sld.lastName = "";
			sld.dialog.filename = "GenQuests_Dialog.c";
			sld.dialog.currentnode = "First time";
			sld.greeting = "Enc_Raiders"; 
			AddPassenger(PChar, sld, false);
			SetCharacterRemovable(sld, false);
			PChar.GenQuest.JusticeOnSale.SmugglerModel = sld.model;
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale.MayorWait");
			sld = &Locations[FindLocation(PChar.GenQuest.JusticeOnSale.ShoreId)];
			sld.DisableEncounters = true;
			PChar.Quest.JusticeOnSale_ShoreEnterWithSmuggler.win_condition.l1  = "location";
			PChar.Quest.JusticeOnSale_ShoreEnterWithSmuggler.win_condition.l1.location = PChar.GenQuest.JusticeOnSale.ShoreId;
			PChar.Quest.JusticeOnSale_ShoreEnterWithSmuggler.function = "JusticeOnSale_ShoreEnterWithSmuggler";
			Log_Info("������� ��������������� �������� � ��� �� ����");
			PlaySound("interface\notebook.wav");
			LAi_Fade("", "");
			WaitDate("",0,0,0,2,5); // 280313
		break;
	}
}

void GetChestPlaceName()
{
	string islandId;
	int iTemp = rand(3);
	switch (iTemp)
	{
		case 0: 
			pchar.questTemp.jailCanMove.islandId = "Bermudes";
			pchar.questTemp.jailCanMove.placeId = "Bermudes_Cavern";
		break;
		case 1: 
			pchar.questTemp.jailCanMove.islandId = "Caiman";
			pchar.questTemp.jailCanMove.placeId = "Caiman_Grot";
		break;
		case 2: 
			pchar.questTemp.jailCanMove.islandId = "Dominica";
			pchar.questTemp.jailCanMove.placeId = "Dominica_Grot";
		break;
		case 3: 
			pchar.questTemp.jailCanMove.islandId = "Terks";
			pchar.questTemp.jailCanMove.placeId = "Terks_Grot";
		break;
	}
}

string GetBanderLocation(ref npchar)
{
    aref	arCommon, arRld, arRld2;
    int	i, n, Qty, Qty2;
	string LocId; 
	string	storeArray [50];
	int howStore = 0;
    makearef(arRld, Locations[FindLocation(npchar.city + "_town")].reload);
	Qty = GetAttributesNum(arRld);
    if (CheckAttribute(pchar, "GenQuest.SeekSpy.Location")) //���� ���� ����� ���� �� ������ ������
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.GenQuest.SeekSpy.Location)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.GenQuest.SeekSpy.Location)
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	else
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1)
    				{
						storeArray[howStore] = LocId;
						howStore++; 
					}
				}
			}	
		}
	}
	if (howStore == 0) return "none";
	LocId = storeArray[rand(howStore-1)];
	SetOpenDoorCommonLoc(npchar.city, LocId); //��������� �����
	for(n=0; n<MAX_CHARACTERS; n++)
	{
		if (CheckAttribute(&characters[n], "locations") && characters[n].locations == LocId) 
		{			
			characters[n].lifeDay = 0;
		}
	}
	return LocId;
}

string GenQuestPrison_GenerateArtefact() // ���������
{
	string itemID;
	switch(rand(7))
	{
		case 0:
			itemID = "indian_5";
		break;
		case 1:
			itemID = "indian_7"; 
		break;
		case 2:
			itemID = "indian_8"; 
		break;
		case 3:
			itemID = "indian_9"; 
		break;
		case 4:
			itemID = "indian_10"; 
		break;
		case 5:
			itemID = "indian_11"; 
		break;
		case 6:
			itemID = "indian_3"; 
		break;
		case 7:
			itemID = "indian_6"; 
		break;
	}
	return itemID;
}

string GenQuestPrison_GenerateBlade() // ������ � ������
{
	string itemID;
	switch(rand(8))
	{
		case 0:
			itemID = GetGeneratedItem("blade_16");
		break;
		case 1:
			itemID = GetGeneratedItem("blade_15"); 
		break;
		case 2:
			itemID = GetGeneratedItem("blade_13"); 
		break;
		case 3:
			itemID = "cirass2"; 
		break;
		case 4:
			itemID = GetGeneratedItem("blade_10"); 
		break;
		case 5:
			itemID = "spyglass3"; 
		break;
		case 6:
			itemID = "cirass6"; 
		break;
		case 7:
			itemID = "cirass7"; 
		break;
		case 8:
			itemID = "cirass1"; 
		break;	
		
	}
	return itemID;
}