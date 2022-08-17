void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, arRld, arDis;
	int i, Qty;
	ref rColony;
	
	int iTest;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	iTest = FindColony(NPChar.City);
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "exit_GoOut":
			makearef(arRld, Locations[reload_cur_location_index].reload);
    		Qty = GetAttributesNum(arRld);
			for (i=0; i<Qty; i++)
    		{
    			arDis = GetAttributeN(arRld, i);
    			if (arDis.go == npchar.location)
    			{
					arDis.disable = true; //��������� ���� � ���
					break;
    			}
    		}
			DoQuestFunctionDelay("HouseEnc_TimerGoUot", 10.0);
			pchar.questTemp.HouseEncTimer = pchar.location;
			pchar.questTemp.HouseEncTimer.Id = npchar.id;
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_close":
			makearef(arRld, Locations[reload_cur_location_index].reload);
    		Qty = GetAttributesNum(arRld);
			for (i=0; i<Qty; i++)
    		{
    			arDis = GetAttributeN(arRld, i);
    			if (arDis.go == npchar.location)
    			{
					arDis.disable = true; //��������� ���� � ���
					break;
    			}
    		}
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//--------------------------------- ����� ---------------------------------
		case "HouseMan":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "HouseMan";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("� ������ ������� �������. ������, � ��� ���� ������� �� ������...", "�� �� �� ����� �� ������� ��� ��������� ������?.. �� ���, �������!!!", "� ���� ������ �� �� �������. ���� ������� ��������� ������ �������� ����� ��� �����!"), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������! ������!!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = PCharRepPhrase(RandPhraseSimple("������, ���� ���� �������...", "���, � �� ������� �� �������� ������ ��������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + "!"), 
					RandPhraseSimple("����������� � ��!", "���, ���� ���� �������� ��������� ������..."));
				link.l1.go = PCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				if (CheckAttribute(pchar, "questTemp.HouseEncTimer"))
				{
					dialog.text = "� ���� �����������. � ������ "+ GetSexPhrase("���","����") +" ������, ���������� ��� ���...";
					link.l1 = "���!";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "��� ���� ���� � ���� ����, �������"+ GetSexPhrase("","��") +"?! ��� ���� ������ ������, ����� �� ������� ������!";
					link.l1 = LinkRandPhrase("���, � ����� ���� �����!", "����� ��� ���� ������� ����...", "��, �������.");
					link.l1.go = "exit_GoOut";
				}
			}
			else
			{
				if (IsDay())
				{
					dialog.text = NPCStringReactionRepeat("��� �������������� ��� � ���� ����. �� �� ���� �� ���?", 
						"��� � ���� ��� ������?", 
						"��, ��� � ���� ������� ��� ���?",
						"��������, ���� � ��� �� �����, � ������� ��� ���� �� ����������...", "block", 1, npchar, Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("���, ������ ���������� �����, ���������� � ��������...", 
						"�� ���, ����� ���������...",
						"������...", 
						"������, ��� �������.", npchar, Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("HouseMan_1", "exit_setOwner", "exit_setOwner", "exit_setOwner", npchar, Dialog.CurrentNode);
				}
				else
				{
					dialog.text = NPCStringReactionRepeat("��������, �� �� ������� ��������� � ���� ���� - ���� �� �����. � ����� ��� �������� ��� ���!", 
						"� ��� �������, ��� ����� �������. ����� ��� ����.", 
						"�� ���� ���������� ������, �� � ���������, ����� �� ���������� �������� ��� ���!",
						"���� ������, ��� ��� �����?! ������, ����!!!", "block", 1, npchar, Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("������, � �������...", 
						"��, ������...",
						"�����, �� ��������.", 
						"��������, ����� ����?!", npchar, Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("exit_close", "exit_setOwner", "exit_setOwner", "fight", npchar, Dialog.CurrentNode);
				}
			}
		break;

		case "HouseMan_1":
			dialog.text = "�-�, ��������� ������������� - " + GetFullName(npchar) + ". �� ���� ��� ������, ������ �������������� ��� ������ ������ - �� ������ ����.";
			link.l1 = GetFullName(pchar) + ", � ������ ����������...";
			link.l1.go = "exit_setOwner";
		break;
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		// --------------------------------- ���� ---------------------------------
		case "HouseWoman":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			NextDiag.TempNode = "HouseWoman";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("������������, ��� ����� ����� ������ ��� ���! ��� �� �� �� ����� ����...", "�� �����, ��� ��� ������� �������. � ������, ��� ����� ����� ������ ������ ��� ���!", "��� ��� ����� ����� ����, ��� ���������� ����� ���� ������!"), 
					LinkRandPhrase("��, ����, ���� ��� ����... ��������!!!", "������� ������, ��� �� ����� ����! ������!!", ""+ GetSexPhrase("����� ��������","������ ��������") +"... ����� ������ ��� ��� � ���������, ������ ����� � ���� �����!"));
				link.l1 = PCharRepPhrase(RandPhraseSimple("���, ������� ����...", "���, ����� ���� �� ���������, �����..."), 
					RandPhraseSimple("������ ���� �����, � �� �� ����� ������...", "� �������� ����� ������, ������� ������. � �� ���� ����, �� �� ���� �����..."));
				link.l1.go = "exit_setOwner";
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				if (CheckAttribute(pchar, "questTemp.HouseEncTimer"))
				{
					dialog.text = "� ���� ������������. ��������, ��� ����� ����!";
					link.l1 = "���� ����� - ����...";
					link.l1.go = "exit";
				}
				else
				{					
					dialog.text = "��� ���� ���� � ���� ����, "+ GetSexPhrase("�������","���������") +"?! ���� �� �� ��������� ����� ������ ������, �� � ������ ������!";
					link.l1 = "��� ����...";
					link.l1.go = "exit_GoOut";
				}
			}
			else
			{
				if (IsDay())
				{
					dialog.text = NPCStringReactionRepeat("� ���� ��� ������ � ����� ����. ���� ����� " + GetFullName(npchar) + ". ��� � ���� ��� ������?", 
						"�� ��� �����?", 
						"��, ��������, �� ��� �� �������, ��� �� ��� ���������� � ���?",
						"� ����� ��� �� �������������� ����� ���������������.", "block", 1, npchar, Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat( GetFullName(pchar) + " � ����� �������. � ��� ���"+ GetSexPhrase("��","��") +" ��� ����������� ����, �������������.", 
						"��� �����.",
						"��, ��� �������...", 
						"������.", npchar, Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("HouseWoman_1", "exit_setOwner", "exit_setOwner", "exit_setOwner", npchar, Dialog.CurrentNode);
				}
				else
				{
					dialog.text = NPCStringReactionRepeat("��, �������, ��� �� ��� �� ���������� � ��� � ����� �����! ����� �������� ����... ����� ��� ����, ��������� � ��� ������.", 
						"������ ��, ����� ���! "+ GetSexPhrase("� �������� �������!","") +"", 
						"� ��������� ��� ������ ����� ��� �������� ��� ���!",
						"�� ��� �� ��� ��������?!!", "block", 1, npchar, Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("�� �������, � ������ ������� ��� �� ������.", 
						"������, �� ���� �����������...",
						"�����.", 
						"� ��� ����?", npchar, Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("exit_close", "exit_setOwner", "exit_setOwner", "HouseWoman_2", npchar, Dialog.CurrentNode);
				}
			}
		break;

		case "HouseWoman_1":
			dialog.text = "������, ������ ���� ������. ������ ����� ��� �� ������������"+ GetSexPhrase(" � ����, ��� ��� � �������...",", � ���� ����� ����� ���.") +"";
			link.l1 = "�-�, ��, �������...";
			link.l1.go = "exit_setOwner";
		break;
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! � ��� ������� � ��� ��� ����"+ GetSexPhrase("�","��") +", � �� �� ��������� ������ ��������?! ������-�-�!!!";
			link.l1 = "��������, ����...";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;
		case "HouseWoman_2":
			dialog.text = "������� � ���� ������� ��-�������� �������� �� ����! ��, ������... ��������! ������!!!";
			link.l1 = "�������� ����, � ��� �����?!";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break; 
		//--------------------------------- �������� ---------------------------------		
		case "SkladMan":
			NextDiag.TempNode = "SkladMan1";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("� ������ ������� �������. ������, � ��� ���� ������� �� ������...", "�� �� �� ����� �� ������� ��� ��������� ������?.. �� ���, �������!!!", "� ���� ������ �� �� �������. ���� ������� ��������� ������ �������� ����� ��� �����!"), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������! ������!!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("������, ���� ���� �������...", "���, � �� ������� �� �������� ������ ��������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + "!"), 
					RandPhraseSimple("����������� � ��!", "���, ���� ���� �������� ��������� ������..."));
				link.l1.go = NPCharRepPhrase("exit_setOwner", "fight");
				break;
			}
				dialog.text = NPCStringReactionRepeat("���������� ���! ���� ����� " + GetFullName(npchar) + ". � ����� ������� ����, ��� ��� �� ������� ���������� ���-�� � �����...", 
				"���� ���� ��������. � �����, ��� � ������ �� �����.", 
				"���� �� �� ������ � ������� - ��� � �������, ������ ���������� �����. ������ ��� ������...",
				RandPhraseSimple("��, ����� ��� ��������!", "��, ���� ������, ��� �� ��������?.."), "block", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, �� ���������.", 
				"�������!",
				"�������...", 
				"��, �������� � ���� ���������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "exit", npchar, Dialog.CurrentNode);				
		break;
		
		case "SkladMan1":
			NextDiag.TempNode = "SkladMan1";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("� ������ ������� �������. ������, � ��� ���� ������� �� ������...", "�� �� �� ����� �� ������� ��� ��������� ������?.. �� ���, �������!!!", "� ���� ������ �� �� �������. ���� ������� ��������� ������ �������� ����� ��� �����!"), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������! ������!!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("������, ���� ���� �������...", "���, � �� ������� �� �������� ������ ��������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + "!"), 
					RandPhraseSimple("����������� � ��!", "���, ���� ���� �������� ��������� ������..."));
				link.l1.go = NPCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			dialog.text = NPCStringReactionRepeat("� ����� ������� ����, ��� ��� �� ������� ���������� ���-�� � �����...", 
				"���� ���� ��������. � �����, ��� � ������ �� �����.", 
				"���� �� �� ������ � ������� - ��� � �������, ������ ���������� �����. ������ ��� ������...",
				RandPhraseSimple("��, ����� ��� ��������!", "��, ���� ������, ��� �� ��������?.."), "block", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, �� ���������.", 
				"�������!",
				"�������...", 
				"��, �������� � ���� ���������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "exit", npchar, Dialog.CurrentNode);				
			//���������� ����� ����� �� ������ ������������� ��������
			if (CheckAttribute(pchar, "questTemp.different.ShipyardsMap") && pchar.questTemp.different.ShipyardsMap == "toTarget" && npchar.city == pchar.questTemp.different.ShipyardsMap.city && locations[reload_cur_location_index].type == "shipyard")
			{
				link.l2 = "��������, ��������, ���� ���������� � ����� ����������.";
				link.l2.go = "ShipyardsMap_1";
				pchar.questTemp.different.ShipyardsMap = "toResult";					
			}
			// ugeen --> ����� ������� ��� ��				
			if(CheckAttribute(NPChar,"Storage"))
			{
				if(!CheckAttribute(NPChar, "Storage.Speak"))
				{
					dialog.text = "� ���� � ��� ���� ���� ���������� �����������. ��������, ��� ��� ������������.";
					link.l7 = "��� ���? �� ��� �, ��������� ���� ���������� �����������.";
					link.l7.go = "storage_rent";
				}
				else
				{
					if(CheckAttribute(NPChar,"Storage.Activate"))
					{
						link.l7 = "��������� ���� � �������. � ���� ��������� �� ��������� ������ ������.";
						link.l7.go = "storage_0";
						link.l8 = "� �����"+ GetSexPhrase("","�") +" ���������� �������. �� ��� ������ ��� ����������.";
						link.l8.go = "storage_04";
					}
					else
					{
						if(!CheckAttribute(NPChar,"Storage.NoActivate"))
						{
							link.l7 = "��������, �� ���-�� � ������ ���������. ����� ��� �� ������?";
							link.l7.go = "storage_01";
						}						
					}
				}		
			// <-- ugeen
			}		
		break;
		
		//--------------------------------- ������ ������ ---------------------------------
		case "storage_rent":
			NPChar.Storage.Speak = true;
			dialog.text = "� ��� ���� �������, ��������� ��� �����. �� ������ ���������� �� ��������� �����? ����������� ����������� ���������...";
			link.l1 = "���������, ��������? ���������... � ������� ��? � ������� ��������� �� ������?";
			link.l1.go = "storage_rent1";
		break;
		
		case "storage_rent1":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "�� ���������� ���������� ���� ��� ������������ �������� - ����������� 50000 �. �� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + " � ����� � ����� ���������� ����������� ����� �������. "+
				"��� �������� ������ �� ������, ������ �� ����������� � ������ � ���������. �� ���, �������?.. ��, � ������������������, �������� ����, ����������.";
			link.l1 = "�������. ���� � ��� ���������?";	
			link.l1.go = "storage_rent2";
			link.l2 = "������� ������ �������. ���, ������, ���� �� ������ � ����� ����� ������.";
			link.l2.go = "storage_rent3";		
		break;
		
		case "storage_rent2":
			dialog.text = "�������-�������. ������ ��-�... ������ �� ����� ������� �����.";
			if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
			{
				link.l1 = "���� ��... �������������. ������� ���� ������ - � ������� ���� �����.";
				link.l1.go = "storage_11";
			}
			else
			{	
				link.l1 = "���� ��... �������������. ������ ������ �������.";
				link.l1.go = "exit";
			}	
		break;
		
		case "storage_rent3":
			dialog.text = "��, ��� ������. ���� ��������� - �����������. ������ ������, ��� ����� ��������� ����� ��������� �� �����. ��� �� �� ��������.";
			link.l1 = "�� ����������. ���� ����������� - ������.";
			link.l1.go = "exit";
		break;
		
		case "storage_0":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar, "Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 
			{
				dialog.text = "� ��� �� ������ ��� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + ".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
				{
					link.l1 = "������, ������ ������ ������.";
					link.l1.go = "storage_3";
				}
				else
				{
					link.l1 = "� ����� �������.";
					link.l1.go = "exit";
				}
			}		
			else
			{
				dialog.text = "���������.";
				link.l1 = "�������.";
				link.l1.go = "storage_2";
			}
			link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			link.l2.go = "exit"; 						
		break;
		
		case "storage_01":
			dialog.text = "���, "+ GetSexPhrase("���������","���") +", ����� - ��� ����������. � ��� ����, ��� �� �� �������� ����� �����������.";
			link.l1 = "��� ������. � ��� �������.";
			link.l1.go = "storage_1";
			link.l2 = "�� ���, � ������ ��� ��������"+ GetSexPhrase("","�") +". ����� ����� � �����������...";
			link.l2.go = "exit";
		break;
		
		case "storage_1":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "��� �� ������� - ������ �� ����� �����.";
			if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
			{
				link.l1 = "����� - �������.";
				link.l1.go = "storage_11";
			}
			else
			{
				link.l1 = "��� ����. ������ ������ �������.";
				link.l1.go = "exit";
			}
		break;
		
		case "storage_11":
			AddMoneyToCharacter(pchar, -makeint(NPChar.MoneyForStorage)); 
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			NPChar.Storage.Activate = true;
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
				
		case "storage_2":			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
		
		case "storage_3":			
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar);
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;		

		case "storage_04":
			dialog.text = "������� ������������? ��-��-��, ����� ������������ �����, ����� �������� �������. ������ - ������ ����� �� ������� ��� �� ��������� �������� �����.";
			link.l1 = "� �� ������"+ GetSexPhrase("","�") +" - ����������. ��� �� ����������� ��� ������� �� �������� �������? ������ ������ ������� ����������.";
			link.l1.go = "storage_4";
			link.l2 = "����� �� ���������, ��������? �����, ������� ���� �� �����. �� ���� ������, ����"+ GetSexPhrase("��","��") +" �������... �����������, ����� ������.";
			link.l2.go = "exit";
		break;
		
		case "storage_4":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar,"Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 			
			{
				dialog.text = "� ��� �� ������ ��� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + ".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))			
				{
					link.l1 = "������.";
					link.l1.go = "storage_5";
				}
			}
			else
			{
				dialog.text = "��������� ���� ����� � � ������ �����.";
				link.l1 = "������.";
				link.l1.go = "storage_6";
			}
		break;
		
		case "storage_5":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.Storage.NoActivate = true;
			DeleteAttribute(NPChar,"Storage.Activate");
			DialogExit();
		break;
		
		case "storage_6":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			DeleteAttribute(NPChar,"Storage.Activate");
			NPChar.Storage.NoActivate = true;
			DialogExit();
		break;		

		//--------------------------------- ������ ������ ---------------------------------
		
		case "ShipyardsMap_1":
			dialog.text = "��! ��, ����� ���������.";
			link.l1 = "��� ����� ������� �� ����� �����, ����� ������ ���.";
			link.l1.go = "ShipyardsMap_2";
		break;
		case "ShipyardsMap_2":
			if (sti(pchar.questTemp.different.ShipyardsMap.skladFight))
			{
				dialog.text = "��� ��� ��! ��, ������, ��� ��� �����������!!!";
				link.l1 = "����� ���?! � ���������� "+ GetSexPhrase("�����","������") +"!..";
				link.l1.go = "fight";
				AddCharacterExpToSkill(pchar, "FencingL", 5);
				AddCharacterExpToSkill(pchar, "FencingS", 5);
				AddCharacterExpToSkill(pchar, "FencingH", 5);
				ChangeCharacterComplexReputation(pchar,"nobility", -1);
			}
			else
			{
				dialog.text = "��! ��, �� ����� "+ GetSexPhrase("��������. ������","�������. ������") +" �� ����� ����� � ����� ��������!";
				link.l1 = "��� �� �� ����� ����, � �� �����. ���� � �� �����...";
				link.l1.go = "ShipyardsMap_3";
				AddCharacterExpToSkill(pchar, "Fortune", 10);
			}
		break;
		case "ShipyardsMap_3":
			dialog.text = "����� ���� ���?";
			link.l1 = "���� ��������, ����. � "+ GetSexPhrase("�����","������") +" ���������...";
			link.l1.go = "ShipyardsMap_4";
		break;
		case "ShipyardsMap_4":
			dialog.text = "��, ��� ����������... � �����, ���! ���� " + FindRussianMoneyString(sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000) + ", � ��������� ����� ������� ����� ����� � ���� ��������� ��������.";
			link.l1 = "��� ������� ������ ��� ����. ��������...";
			link.l1.go = "exit";
			if (sti(pchar.money) >= (sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000))
			{
				link.l2 = "������, � "+ GetSexPhrase("��������","��������") +". ������� ������ � �����, ��� ������������.";
				link.l2.go = "ShipyardsMap_5";
			}
		break;
		case "ShipyardsMap_5":
			dialog.text = "�� ��������, ��� ������.";
			link.l1 = "������, ����...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000);
			AddQuestRecord("ShipyardsMap", "5");
			AddQuestUserData("ShipyardsMap", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			//������� close_for_night
			string  sName;
			int location_index = FindLocation(npchar.city + "_town");
    		makearef(arRld, Locations[location_index].reload);
    		Qty = GetAttributesNum(arRld);
    		for (int a=0; a<Qty; a++)
    		{
    			arDis = GetAttributeN(arRld, a);
				sName = arDis.go;
    			if (findsubstr(sName, "_shipyard" , 0) != -1)
    			{
					DeleteAttribute(arDis, "close_for_night");
					break;
    			}
    		}
			LocatorReloadEnterDisable(npchar.city + "_shipyard", "reload2", true);
			//������ ������ �� ������� close_for_night
			SetTimerFunction("ShipyardsMap_returnCFN", 0, 0, 2);
		break;

	}
}
