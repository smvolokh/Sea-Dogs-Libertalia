void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	bool bOk;
	int i;

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
		
		//����� ��������� � �������
		case "Storehelper":
			dialog.text = "��� �� ������, �����?";
			link.l1 = "��. ���� ��� �� - ������ �����, ���������?";
			link.l1.go = "Storehelper_1";
		break;
		
		case "Storehelper_1":
			dialog.text = "��, �, � ���-�� ���� ����? �� ������� ��� ���� ���, ������, � �� � ���������� ��������.";
			link.l1 = "� �� ������ � ��� ����� �������. ���� ������ ����� ���� �� ������. �� ���� �������� � ���� �� ������, ���? �� ����������� ��� �...";
			link.l1.go = "Storehelper_2";
		break;
		
		case "Storehelper_2":
			dialog.text = "��! �� ����������� ����! ������ ������! �� �����, ��� � ��� ����� ���� �������� �� ��� ������ �����? �� ��� �� ���� ������� ������ �����! � �������� �� ���� ���� ��� ��� �������, � �� �� ���� �� ����� ���� ��������� ������, ���� ������ ���� �� ��������!\n��� ����� ������ ��� ���� ������ �������, � � ���� ��������. ����� � ���� �� ������� �� ������ �������� � ����� ��������, �-�� ����. � ���� ������ ���� ������ - ������ ������ ���� ��������� ������ � �������� ��������� ����������.";
			link.l1 = "�� ����, �� ��� � ���� �� ������ �� ���������, ��� � �������?";
			link.l1.go = "Storehelper_3";
		break;
		
		case "Storehelper_3":
			dialog.text = "���, ������� ���� ����! � ������� �����, � �� �������, ������-������ ����� � ������� ����������������, � ���� �� ��������� - ����� � ������� ��������. ����� � ��� �� ������ ����� ���������...";
			link.l1 = "��� �������. �������� ��� ����� � �� �����. �����, ������!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_4":
			dialog.text = "������, �������� � �������, �� ������������� ������!";
			link.l1 = "���� ������, �����. ���� ��� �� - ������ �����?";
			link.l1.go = "Storehelper_5";
		break;
		
		case "Storehelper_5":
			dialog.text = "��! ��, �. � � ��� ����-��?";
			link.l1 = "��� ����������� ����� �� ���� �� ������. �� ���� �������� � ����, ���?";
			link.l1.go = "Storehelper_6";
		break;
		
		case "Storehelper_6":
			dialog.text = "��-��! � ����� �� � ��� �����������? �� ����� ��������� ��� ������������� ��������� �� ��������� ��� ������? ��� � ���� �� ���������� ������������ ������� ������� � �������� ����������, �? ��-��-��!";
			link.l1 = "�� ������� ��� ��������� ��� � ��������, ������ �� �� ����������� � ���� � �����...";
			link.l1.go = "Storehelper_7";
		break;
		
		case "Storehelper_7":
			dialog.text = "������ � � ���� �� ���������? �� ������ ��� �� ������ ��������! ������, ����� ���� �� �����! ������ ��� �� ����� ������ �������, � � ������ ����� � ��������� ��������, � ��� ���, ���� ������, ����� ��������!\n����� � ����� � ���� � ���� ������������� ���� � �������, ������� � ��������, � �� ����� � ��������! � ��� �� ����� ������ - ����� ��������� ����� ��� ������. �� ���� ����� � ���� �� ������� �� ������ � ���� �� ������, ������� ������ � ���� ���������, ��-��!";
			link.l1 = "��� �������. �������� ��� ����� � �� �����. �����, ������!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_8":
			dialog.text = "���� �� �� ������ ������� - �� ��� �� �� ���.";
			link.l1 = "������ ����. ��� � �������, �� - ������ �����?";
			link.l1.go = "Storehelper_9";
		break;
		
		case "Storehelper_9":
			dialog.text = "��, ��� �. ��� ������, �����?";
			link.l1 = "��� ����������� ����� �� ���� �� ������. �� �������� � ���� �� ������...";
			link.l1.go = "Storehelper_10";
		break;
		
		case "Storehelper_10":
			dialog.text = "�� � ����� ���� �����������. � ��� ������ �� ������. ��� �� ��� ������� ������ �� ��� ������ ������, �� � ���� � �� ���� �������� ������� � ���� ��� ������. ����� ���������.";
			link.l1 = "��. ��� �� ������������ ���� �� ����, ��� � �������?";
			link.l1.go = "Storehelper_11";
		break;
		
		case "Storehelper_11":
			dialog.text = "�� ��� ��������� ���������, ������. ������ ������, ��� ��� ������ ������������, ���� �� �������. � ��� ������ ������� �����, � ��� ������� ������� �� ����������� - � ������� ����� ������ ��������, � �����������, ���� ���������� ����������� ��������\n� ���� �������� ����� ��������� ������ �������� ��� ������. �� �����, ��� � ���� ��� ��������� - ��� �������� ������� ������ �������� ������� ���� �� ������, � �� ���� ����� �� ������ � ���� �� ������.";
			link.l1 = "��� �������. �������� ��� ����� � �� �����. �����, ������!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_12":
			DialogExit();
			npchar.lifeday = 0;
			AddQuestRecord("SharlieA", "2");
			pchar.questTemp.Sharlie.Storehelper = "return";
			LAi_CharacterDisableDialog(npchar);
			pchar.quest.StorehelperOver.over = "yes"; //����� ������
		break;
		
		case "Newstorehelper_1":
			dialog.text = "������������, �����. �� ���� ���������� ���������� - �� ������, ��� ��� ����������� ��� ������ ��������.";
			link.l1 = "������ ����. � ������ �� ��� ��������?";
			link.l1.go = "Newstorehelper_1_1";
		break;
		
		case "Newstorehelper_2":
			dialog.text = "�����������, ������! ��������� ��� ������� ���������� � ����.";
			link.l1 = "� ������ ��� �����������.";
			link.l1.go = "Newstorehelper_2_1";
		break;
		
		case "Newstorehelper_3":
			dialog.text = "������� ��������, ��������� ��������. ���� ��� �� ���������� �� ������ � �����?";
			link.l1 = "��, �. ��� �� ������ ���������� � ����?";
			link.l1.go = "Newstorehelper_3_1";
		break;
		
		case "Newstorehelper_1_1":
			dialog.text = "������ ��� � ������ � ������ ��������� ����� ����������������. � �������� ��� ������ ������� ����. � � ����� ��� �������� ���������� ��-�� ������� - � ����� �������, ����������, �� ���� ���������� � ����� ��������� ���� � ������. ���, � ���� ������������ �� ������� �����\n(������) � ��� ������, ��� ���� �� �������������� ����, �� � ������� ��� ����� ������� ���� ��� �������� ���� ������� ��������. �� ���?";
			link.l1 = "������. � ������� ��� ������ �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_1_2";
		break;
		
		case "Newstorehelper_2_1":
			dialog.text = "� ��� ������ ���������, ����� ��������� � ����� � ����, ������ ��������� �� �������� �����. ����� ������ �������� � ���� �������. ����� ������ ��� �� �� ����, � � �� � �������� ������ ���� �����������\n(������� �����) � � ����� ��������� � �������� ���� ��� ���� ��������� ������� � �������.";
			link.l1 = "�������. � ������� ��� ���, ��� �� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_2_2";
		break;
		
		case "Newstorehelper_3_1":
			dialog.text = "� ������� �������� �� �������� ������ � ����� ������. ������� ����������� ������� ���� �� ������, � ��� ������� ������� ������� �����, ����� ��������� �������� �� � ������. �� � ����� �� ������� �������, � ����� �� ��������� ����� �� ������ ������ ����\n(��������) �� ��� ����� � �������� � �������� ���� ������� ��� ��� ���� ��� �� �������.";
			link.l1 = "����. � ����� ��� � ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_3_2";
		break;
		
		case "Newstorehelper_1_2":
			dialog.text = "�����, �� ������� ���������� �����. � �� ��������� ��� �������...";
			link.l1 = "� ������ ������� � ���� ������. �����������, �� ������������ � ���� �� �����.";
			link.l1.go = "Newstorehelper_1_3";
			link.l2 = "� ��� �� �����...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_1_2";
		break;
		
		case "Newstorehelper_2_2":
			dialog.text = "� �������, ��� ��� ����� ����� �� ��� �����������. �� � ������ - ������ ������ � �������� �����...";
			link.l1 = "� ������ ������� � ���� ������. �����������, �� ������������ � ���� �� �����.";
			link.l1.go = "Newstorehelper_2_3";
			link.l2 = "� ��� �� �����...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_2_2";
		break;
		
		case "Newstorehelper_3_2":
			dialog.text = "����� �� ������������ � ���� ������. ��� � �� � ���� ��� �� �������...";
			link.l1 = "� ������ ������� � ���� ������. �����������, �� ������������ � ���� �� �����.";
			link.l1.go = "Newstorehelper_3_3";
			link.l2 = "� ��� �� �����...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_3_2";
		break;
		
		case "Newstorehelper_1_3":
			dialog.text = "������ ���� ������! � ���� ����� ��� � ����� � �������.";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 0;
		break;
		
		case "Newstorehelper_2_3":
			dialog.text = "���� ���� �����, ������ ���, �����! � ���� � ����� � �������.";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 1;
		break;
		
		case "Newstorehelper_3_3":
			dialog.text = "������ ���� ������ ������� � ���� � ������ �������, ������!";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 2;
		break;
		
		case "Newstorehelper_exit":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			pchar.questTemp.Sharlie.Storehelper.id = npchar.id;
			DeleteAttribute(npchar, "LifeDay")
			chrDisableReloadToLocation = true;
			for (i=1; i<=3; i++)
			{
				sld = characterFromId("Newstorehelper_"+i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 10.0);
			}
			pchar.quest.storehelper2.win_condition.l1 = "location";
			pchar.quest.storehelper2.win_condition.l1.location = "LeFransua_town";
			pchar.quest.storehelper2.function = "NewstorehelperAdd";
			AddQuestRecord("SharlieA", "4");
			pchar.questTemp.Sharlie.Storehelper = "choise";
			pchar.quest.storehelper.over = "yes"; //����� ����������
		break;
		
		case "Newstorehelper_regard":
			dialog.text = "��, ��� � �������, ��� � ���� ��� ����� ����� ������? �������, �����, ��� ������� ������ ����. ��� ���� ������� ���� � �������������� �������, ��� � � ������. ����, ��� �� ����� ������������, ������� � ����� ���� ��� � �������� ������ ��������������� ��������� �������: �������� �������. � ���� �� ������� �������� ����� ������� �����.";
			link.l1 = "�������������... ������ � ���������� ��� ������ ������������, � ����� ��� - �� � ����� �����.";
			link.l1.go = "Newstorehelper_regard_1";
		break;
		
		case "Newstorehelper_regard_1":
			DialogExit();
			npchar.lifeday = 0;
			switch (sti(pchar.questTemp.Sharlie.Storehelper.Quality))
			{
				case 0:
				AddMoneyToCharacter(pchar, 500);
				TakeNItems(pchar, "gold_dublon", 25);
				GiveItem2Character(pchar, "BackPack1");
				break;
				
				case 1:
				AddMoneyToCharacter(pchar, 500);
				TakeNItems(pchar, "jewelry8", 10);
				TakeNItems(pchar, "jewelry7", 1);
				GiveItem2Character(pchar, "BackPack1");
				break;
				
				case 2:
				AddMoneyToCharacter(pchar, 3000);
				GiveItem2Character(pchar, "BackPack1");
				break;
			}
		break;
		
		//����������� ����
		case "Rum_Cap_Over":
			dialog.text = "�����, � ����� ��� ���������� �������� ��� �������. � �������� ����� � �������� � ������ �� ������!";
			link.l1 = "������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rum_Cap_Over";
			chrDisableReloadToLocation = false;
			npchar.DontDeskTalk = true;
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
		break;
		
		case "Rum_Cap":
			pchar.quest.Sharlie_rum2.over = "yes"; //����� ������
			chrDisableReloadToLocation = false; // patch-4
			dialog.text = "��? �� ��� �����, ��������?";
			link.l1.edit = 1;			
			link.l1 = "";
			link.l1.go = "Rum_Cap_1";
		break;
		
		case "Rum_Cap_1":
			if(GetStrSmallRegister(pchar.questTemp.Sharlie.Rum.Pass) == GetStrSmallRegister(dialogEditStrings[1]))
			{
				dialog.text = "����� ����, �����! ��-��! ����������� �� ����� ����� �������. ��, �� ������ �� �������, ��� � �������?";
				link.l1 = "��. � �� ��� �� ���?";
				link.l1.go = "Rum_Cap_2";
			}
			else
			{
				dialog.text = "��� ������� �������! ������, ������, ��� ����! �� ���� ���!";
				link.l1 = "�-���!";
				link.l1.go = "Rum_Cap_getout";
			}
		break;
		
		case "Rum_Cap_getout":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
			setCharacterShipLocation(pchar, "Shore38"));
			setWDMPointXZ("Shore38");
			DoQuestReloadToLocation("Shore38", "goto", "goto1", "Rum_RemoveBarkas");
		break;
		
		case "Rum_Cap_2":
			dialog.text = "������! ����� ����� �� ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Rum_CarrierEnter");
		break;
		
		case "Rum_Cap_3":
			dialog.text = "��� ����� � ����� �� ����� �������. ���� �� ������� ������ ��������� �� ����������� �� ��. ����������. ��� ���� ���� ��������� �����!";
			link.l1 = "�� ����� ������ �������, �����������! �����!";
			link.l1.go = "Rum_Cap_4";
		break;
		
		case "Rum_Cap_4":
			dialog.text = "� ���� ���� ��, ��������...";
			link.l1 = "...";
			link.l1.go = "Rum_Cap_5";
		break;
		
		case "Rum_Cap_5":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
			npchar.DontDeskTalk = true;
			NextDiag.CurrentNode = "Rum_Cap_Over";
			pchar.quest.Sharlie_rum4.win_condition.l1 = "Ship_location";
			pchar.quest.Sharlie_rum4.win_condition.l1.location = "LeFransua_port";
			pchar.quest.Sharlie_rum4.function = "Rum_RemoveRum";
			AddQuestRecord("SharlieB", "4");
			i = FindIsland("Martinique");
			Islands[i].EffectRadius = 3000;
		break;
		
		case "Rum_Carrier":
			dialog.text = "�� ��� ��������� ���, �����. ��� ��� ������? ����� � ���?";
			link.l1 = "��� ������ ������ ������������. ����� � ����� �� �������.";
			link.l1.go = "Rum_Carrier_1";
		break;
		
		case "Rum_Carrier_1":
			dialog.text = "�������. ������ ��� ���� ������, � �� ������������� � ���� �� ������ � ������� �� ��������.";
			link.l1 = "����� �������, �����������.";
			link.l1.go = "Rum_Carrier_2";
		break;
		
		case "Rum_Carrier_2":
			DialogExit();
			for (i=1; i<=3; i++)
			{
				
				sld = characterFromId("Rum_Carrier2_"+i);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload2_back", "none", "", "", "OpenTheDoors", 10.0);
			}
			pchar.questTemp.Sharlie.Rum = "regard";
			i = FindLocation("Fortfrance_town");
			setCharacterShipLocation(pchar, GetCityFrom_Sea(locations[i].fastreload));
		    setWDMPointXZ(GetCityFrom_Sea(locations[i].fastreload));
		break;
		
		//��������� ������� �� �������
		case "GigoloMan":
			dialog.text = "������ ����, �����! �������, �� �� ������ �� ���� ���������� ��������, ��� ��������� � ����� �������. �, ��� � ����, �� ���������... ������� �� ������, � ������?";
			link.l1 = "������ ���, ������. "+GetFullName(pchar)+", � ����� �������. ��� ��� ������?";
			link.l1.go = "GigoloMan_1";
		break;
		
		case "GigoloMan_1":
			dialog.text = "��������� ������������� - "+GetFullName(npchar)+". ������ �� ������� � ��� ����� ��������� ��� �����. �� ������� �������� � ����. � ���� � ��� ����� �������, ������ ���������� � ����������� ���������\n�� ���� � ������ � ����� ����������� �������������, � �� ������� �� ��������� � ��� � ���. �� � ������, ��� �� ���� �������, ��� �������� ���������.";
			link.l1 = "��������� ���� ����� �������, �����. ���� ��� ����� � ���� ����� - �������, �������� ������.";
			link.l1.go = "GigoloMan_2";
		break;
		
		case "GigoloMan_2":
			dialog.text = "� ��� ������� �� ��� ��� �����, �����. ��� ���. � ����� ���������� ���� �������. ������� ��� ��������� ����� �������, ������, �� ������, ������� ��������� �����������. � ��� ��������� ������ �� ��� �������� �... ��������� ����������� ������� �������� � ��� �������\n������ ��� ��������� � �������� � ������ �� ��������� ��� �������� ��� ���������� �����. ���, ��� �� ����� ����������, ��� ����, � � �� ������ - �� ��������� ����� ����� ������\n������� � � ��������� � ���. �� ����� ������� �����, ��� ����� �� �����, � ������ ��� �� ��� ����, �� ������� ����, ����. �� ���� ����� �������, �����...";
			link.l1 = "� ��� �� � ���� ��� ������, ������?";
			link.l1.go = "GigoloMan_3";
		break;
		
		case "GigoloMan_3":
			dialog.text = "��� ����� ������. ��� � �� ���� ��������� � ������� - ������, ��� ������� ������ ��������� � ����. � ����� ��� ������� � ������� � ������������ � �������� � ���, ����� ��� ������������ ��� ��������� '�� �����', �� ���� ����\n������ �� ����� ��������� - �������� ������ ��� �������������, ������ �����, �������, ������. ����� ��������� ������� � ����� ����. � ��� ��� ����� ����� ���� - ���� � �������� ������ ������ ��������� � ���-��� � ��������� ������ ����, � ��������� �������� ���� � �������� ����������� �� ������������.";
			link.l1 = "�� ���� ������� ����������, �����. � ��� ����� ������� ���� �������.";
			link.l1.go = "GigoloMan_4";
			link.l2 = "������, � ������ ����� ���������� �� ������, ��� ��. ��� ��� ����� ���� ��������, �� ���� ������� � ��������� �� ����. ��������� �����������.";
			link.l2.go = "GigoloMan_exit";
		break;
		
		case "GigoloMan_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
		break;
		
		case "GigoloMan_4":
			dialog.text = "� ����� ���. ������ ��������: �������, ������� ��� �����, ����� ������. � ����� ��� �������� �� �� ��� ����� ����� ��������, �� ������ ����������� ������, ����� ����� �� ������. ����������� � ����� � � ��� ������\n��� ��� ��������� ����� �� ���������� ����������� - ����������� ������� � ������� ������. �� ����� ��� �������. ���, �������� ����� ����� ����. � ��� ��� ������� �������� ���� � �������� ��������. ���� �� ���� �������� ������������ � �������� ���������� ����. �� ��������� - � ��� ���!";
			link.l1 = "������, ������, ������������. � ���� ���� ��������� ����� � ��� �� ������.";
			link.l1.go = "GigoloMan_5";
		break;
		
		case "GigoloMan_5":
			DialogExit();
			AddMoneyToCharacter(pchar, 6000);
			TakeNItems(pchar, "potionwine", 1);
			PlaySound("interface\important_item.wav");
			Log_Info ("�� �������� ������� ����");
			AddQuestRecord("SharlieC", "1");
			AddQuestUserData("SharlieC", "sName", GetFullName(npchar));
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "none", "", "", "", -1);
			LocatorReloadEnterDisable("Fortfrance_town", "houseSp1", true);
			npchar.lifeday = 0;
			pchar.questTemp.Sharlie.Gigolo = "start";
			pchar.questTemp.Sharlie.Gigolo.Rand1 = rand(1);
			pchar.questTemp.Sharlie.Gigolo.Rand2 = rand(1);
		break;
		
		case "GigoloGirl":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "������������, �����. ��� �� �������� ���� �� ����? ��-��, ���� �������, ��� ������� ������� - �� ��������� � ������ ��������, � ������� �� ���� ���������� ��������...";
				link.l1 = "��� �� ������ ���, ������. ���� ����� ����� �������� ���� �� �� ����, � � ���� ������� ������, ������� �� ���� ������ �� ����� ���������� � �������. �� �� �� ������������� - �� ������ �������� �������, ��������, � �� ��� ����������. �����, �� ���������� ��������.";
				link.l1.go = "GigoloGirl_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�����, �������, �� ���������, ��� � �� ���� ������ � ���� �� �����? ������� �������� ����� - �� �������� ���� � ��� ������ �����. ����� ����� � �����-������ �����������, � �� ��������� ���� ������.";
				link.l1 = "������, � �����. ������ �� ����!";
				link.l1.go = "GigoloGirl_2";
			}
		break;
		
		case "GigoloGirl_1":
			dialog.text = "����... �� ��� ����� �����������, �����. � �� � ������������� ������� ��� ���� ������ � ����. �� �� �����. ������?";
			link.l1 = "��. ������ �� ����!";
			link.l1.go = "GigoloGirl_2";
		break;
		
		case "GigoloGirl_2":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.Sharlie_Gigolo.win_condition.l1 = "locator";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.locator_group = "reload";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.locator = "houseSp1";
			pchar.quest.Sharlie_Gigolo.function = "Sharlie_GiveGigoloGirl";
			pchar.quest.Sharlie_Gigolo1.win_condition.l1 = "Timer";
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.hour  = sti(GetTime() + 2);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.function = "Sharlie_GigoloGirlOver";
		break;
		
		case "GigoloGirl_3":
			dialog.text = "������?";
			link.l1 = "��. ������ � ���� ���. ������ �� ����� - ��� ���� ������� �������.";
			link.l1.go = "GigoloGirl_4";
		break;
		
		case "GigoloGirl_4":
			dialog.text = "��... �� � � �� �����. ������ �� ����� ��������. �����, �����, ��������. �����, ���-������ ����� �� �������� ����� ���� �� ����? ������, ��� ����� ������ ���� � ����� �����!";
			link.l1 = "��� ����� ����, ������. ��������, ��� � ����������. ����!";
			link.l1.go = "GigoloGirl_5";
		break;
		
		case "GigoloGirl_5":
			pchar.quest.Sharlie_Gigolo1.over = "yes";
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "none", "", "", "GigoloGirl_Remove", 5.0);
		break;
		
		//������ � ������� ��������
		case "CaptivePirate":
			pchar.quest.Captive_CreatePiratesOver.over = "yes";//����� ������
			dialog.text = "�� ��� �����? ��� ���� ����� ����? � ��, ����������, ����!";
			link.l1 = "���-�� �� �� ������ �������, ������.";
			link.l1.go = "CaptivePirate_1";
		break;
		
		case "CaptivePirate_1":
			dialog.text = "��������, �����, � ���������� �� ������, ��� � �������, �� ��� ������ �� ������ ������, ��� ���� ����� ����� � ���� ��������� - ��� ��������. �, ������� ������, � ��� ������, ���� �� ��� ������ �� ��������� ������. �� �����?";
			link.l1 = "� ������ �� ��������, ����. ��� ������� �������. ��� ����� ���� �������. ������������� ���������� - � �������� ����� ����������� ������. ���� ������ ������ ���������� ������, ��, ��������, ��� �������� ������ ���� ������ �����.";
			link.l1.go = "CaptivePirate_3";
			link.l2 = "�����-�����, �� ��������. � �����.";
			link.l2.go = "CaptivePirate_2";
		break;
		
		case "CaptivePirate_2":
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			DialogExit();
			n = makeint(MOD_SKILL_ENEMY_RATE/2);
			if (n <= 1) n = 2;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("CaptivePirate_"+i);
				LAi_CharacterDisableDialog(sld);
				LAi_SetImmortal(sld, true);
				sld.lifeday = 0;
			}
			sld = characterFromId("CaptiveSpain");
			LAi_SetImmortal(sld, true);
			sld.lifeday = 0;
			pchar.quest.Sharlie_captive1.over = "yes";
			pchar.quest.Sharlie_captive2.over = "yes";//����� ����������
			AddQuestRecord("SharlieD", "5");
			CloseQuestHeader("SharlieD");
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;
		
		case "CaptivePirate_3":
			dialog.text = "���-�? �� �� ��������, ������! �� � ����� ������, �� ������ ������! ������, � ������!";
			link.l1 = "��, ���������, �������...";
			link.l1.go = "CaptivePirate_4";
		break;
		
		case "CaptivePirate_4":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			int n = makeint(MOD_SKILL_ENEMY_RATE/2);
			if (n <= 1) n = 2;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("CaptivePirate_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Captive_PiratesDead");
			AddDialogExitQuest("MainHeroFightModeOn");	
			sld = characterFromId("CaptiveSpain");
			LAi_SetCitizenType(sld);
		break;
		
		//������� �������
		case "CaptiveSpain":
			dialog.text = "�������! �� �������? ����� �� ������� ���� ���������. �� �� �����, ��� � ��� ������ ������!";
			link.l1 = "��������... ����������, � ��...";
			link.l1.go = "CaptiveSpain_1";
		break;
		
		case "CaptiveSpain_1":
			dialog.text = "�� ���������, ����� ������, ��� ����� ������. � ���� ����� � ������ �� ������, ���� �� ������ � ��������� �������... ���������, ����������!";
			link.l1 = "��� ����� ����!";
			link.l1.go = "CaptiveSpain_2";
		break;
		
		case "CaptiveSpain_2":
			DialogExit();
			LAi_SetPlayerType(pchar);
			NextDiag.currentnode = "CaptiveSpain_3";
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(npchar, 10.0, true, "CaptiveSpain_capture");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "CaptiveSpain_3":
			dialog.text = "����... �� �������. � ������, ��������� �������. ����� ������ �� ����, ��� ������ - � � ����� ������.";
			link.l1 = "����� ������ � ��� ������� ��� �������, ������� ��������! ��� �� ����� ���� ������! � � ������ � ���� �� ��������!";
			link.l1.go = "CaptiveSpain_4";
			RemoveCharacterEquip(npchar, BLADE_ITEM_TYPE);
		break;
		
		case "CaptiveSpain_4":
			dialog.text = "��� ��� �� ���� �� ���� �����? ����� �� ����� ���� �������? � ��� ���� �������?";
			link.l1 = "��� ������� ������. � ��������� �������� ��������, ��, ��� ������, ������ �� �����. � ���������� � ��������, �� ������� ������ ������� �����. ��� ����� "+pchar.questTemp.Sharlie.Captive.Name+", �� ��������� � ���� �� �������.";
			link.l1.go = "CaptiveSpain_5";
		break;
		
		case "CaptiveSpain_5":
			dialog.text = ""+pchar.questTemp.Sharlie.Captive.Name+"? � �� ���� ������. ������� ����� ��� ���!";
			link.l1 = "� ��� �� �����, � ����, ����� �������� � �������� ���� �� ���������� ����� ��� ����� �������� �� ����. � ���� ������ ��������� ���� � ����, �, �������, � �� �������! ��� ��� ���� ���� ����� ������, ������ �� ���� ���� ������ �������.";
			link.l1.go = "CaptiveSpain_6";
		break;
		
		case "CaptiveSpain_6":
			dialog.text = "� ���� � ����� ������ ��� ������... ��������, ���� ��������� ����� ��� �� ����� ���������� �����...";
			link.l1 = "�� �������-�� ���� ������� ����������. � ������ �������� �������� - �� ������������ � ���� �� ������. ������� �� ��� ������� � �� ������� ������ - ��� ����� ������!";
			link.l1.go = "CaptiveSpain_7";
		break;
		
		case "CaptiveSpain_7":
			chrDisableReloadToLocation = false;
			DeleteAttribute(pchar, "GenQuest.Notsearchbody"); // 170712
			DialogExit();
			AddQuestRecord("SharlieD", "6");
			LAi_group_Register("TempFriends");
			LAi_group_SetRelation("TempFriends", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_MoveCharacter(npchar, "TempFriends");
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			pchar.quest.Sharlie_captive3.win_condition.l1 = "locator";
			pchar.quest.Sharlie_captive3.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_captive3.win_condition.l1.locator_group = "reload";
			pchar.quest.Sharlie_captive3.win_condition.l1.locator = "reload8_back";
			pchar.quest.Sharlie_captive3.win_condition.l2 = "Night";
			pchar.quest.Sharlie_captive3.win_condition.l3 = "Alarm";
			pchar.quest.Sharlie_captive3.win_condition.l3.value = 0;
			pchar.quest.Sharlie_captive3.win_condition.l3.operation = "=";
			pchar.quest.Sharlie_captive3.function = "CaptiveSpain_reload";//���� �����
			pchar.questTemp.Sharlie = "bankskipercaptive";
		break;
		
		//��������� � ��������� �������
		case "Prosper":
			pchar.quest.Sharlie_RescueDaughter.over = "yes"; //����� ����������
			dialog.text = "��� �� ������, �����? � ���� ���������� ��� ������� �� ���������, ��� ��� ������� �������.";
			link.l1 = "�� - ������� �������, ���?";
			link.l1.go = "Prosper_1";
		break;
		
		case "Prosper_1":
			dialog.text = "��, ��� �. �� ��� �� ��� ���������� ���������. ����������� ��������, ��� �� ����� � ��� ��� �� ���� �����.";
			link.l1 = "��� ��� - "+GetFullName(pchar)+". ���� ������� "+GetFullName(characterFromId("Fortfrance_portman"))+", ��������� �����. �� ������, ��� ��� ������ ��������� ������...";
			link.l1.go = "Prosper_2";
		break;
		
		case "Prosper_2":
			dialog.text = "������� ���� ����, ���� ��� �� ���! ���� ������� ��������� ���� �� �������� ���� �� �����. ��� ���� �������� ���� ��� �� ����� � ������ ������ ����� ����� ����������! �� ������������� ������, ����� ��� ������? ���� ��� ���, �� � ����� � �� ��������!";
			link.l1 = "�������, � ������������� ������, ����� ������. ���������� �� �������, ��� ��������� � ��� ���� �������. ��� �������, ��� � ��� ������� ����...";
			link.l1.go = "Prosper_3";
		break;
		
		case "Prosper_3":
			dialog.text = "��, ��� ���� ������ ������� ��� ��� �����. �� ����� ���� ����� ����� ���� �� �����, ��� ��������� � ���� �����. � ����� ��� �� ���������, � ������ ����. � ���������� � ����, � ��� ��� �������, ��� ��� ���� � �� ��������� ����!\n� ��� ������ ���������� ����� ����������. �� �������� ���� �� ���� ������ ��� ������������� �������. ��� ������ � �������� � �����, � ������. ��� ���������, ��� ������� �� ���������, � ���������� �������� ���� ������ ��������\n�� �� ���-�� ����. � ����� ������� ������� ������ �������� ����� � ������������ ����, ���������, ������� �������� � ����������. � �����������, �� ������� ������� ��, � � ����� �������� �� ��������� ����� � �������� ������. ������� ��� �� �������� � �������, �� ����������� � ���� �������\n� ������: ������������ ������ - �� ��� ����. ����� ����, �� ��������� ������ ������� ��������� ��� ��� �������� - ����� ������ � �������� �����. ���� ��������� � �����, ������ - � �� �������. �� ���� �� ��������.";
			link.l1 = "�� ���� ������� �������� �� ������� ����� � ��������� �����? ����������...";
			link.l1.go = "Prosper_4";
		break;
		
		case "Prosper_4":
			dialog.text = "� ���������� ���������� � ���������� � ��������. � ��� ���� ������������ ����������. � ������ �� ������ ���� ��������� ������. ��� ���, ������� ������ ������ ���. � �������� ��������� �������� � ����� � ������, ����� ����, ��� �����-�� ����� ��������� ������\n���� � ������������ ���������, ����������� � ��������, � ������� �� ������ ������ ������� ����. ��� ���� ������! � ����� �� �����. � � ������ ���������, ����� �� ������� �� �������� ���������� - ���� �������, � ��� ������ ������ �� �� ������.";
			link.l1 = "�� ����� ��� �������� � �������� �������?";
			link.l1.go = "Prosper_5";
		break;
		
		case "Prosper_5":
			dialog.text = "� �� ����. �����, �������� �������, � �� - � �������. � �����, ������ ������ - ��� �� ������.";
			link.l1 = "��� ��� - �������? ����� �����-��... ���� ���-�� ��� � ��� ������...";
			link.l1.go = "Prosper_6";
		break;
		
		case "Prosper_6":
			dialog.text = "�����? ��, ��������� ��� ���� �������, ���� ������ �� �� ��������� �� ������... ��� ���, � ���������� ��������� � ���������� � �������� ������������ ����������� ����������. � ��� �� �������? �� �������. ������, ��� ���� ������� ���������, �� ����� ����������� �� ��������, � ��������� ������, � ����������� �������� �� ��������\n��� �� ��� ���� ���������, ��� ����, ���, ������������� � ����� � ����������������, � ������ '������ ��������, ���������� � ������� �� �������'. � �����, � ������ �� ������� � ����� ����������� ���.";
			link.l1 = "��� �� �������� �����������?";
			link.l1.go = "Prosper_7";
		break;
		
		case "Prosper_7":
			dialog.text = "���������� � ������� � ������ � ������� ��� ��� �������. �������, ������ ��� ����. ��� ������, � ����� ������ - ����� ������� �����, � �������� � ��� �� ���������. � ������� �� ���� ���� �����, �� ��� ������� �� ���\n���� �� ������� �� ����, �� ��� ������ ������� ����������: ������ �� ��� ����� ������� ��� ����������� �����. �������, ����� ��� �� ������ �����, ���� � ���� ������������ ������. �� ������� �� ���� ������� ��� ����?";
			link.l1 = "�������! ��� ���� �����! ����� ����� ���������, ����� ������� ������� ��� ����� �������?";
			link.l1.go = "Prosper_8";
			link.l2 = "��. �� ������, ��� �������, ��� � ������ ���������� ���� �����. �����, ��� �� ����� ������� ����������� ��� ������?";
			link.l2.go = "Prosper_exit";
		break;
		
		case "Prosper_exit":
			dialog.text = "�� �����������? ���! �� � ��� ������ ������ �������! ���������� � �����! ����...";
			link.l1 = "��-��, �������!";
			link.l1.go = "Prosper_exit_1";
		break;
		
		case "Prosper_exit_1":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "gate_back", "none", "", "", "", 10.0);
			CloseQuestHeader("SharlieF");
		break;
		
		case "Prosper_8":
			dialog.text = "� ���, ��� � ���� ������ ������� ���� ���� �������� � ������� �������. ���, �������� ��� ��� ��������. ��� �������� �����, � ����� ��� � ������ ��������. ��� ����� ������� ����������� ��� � ���.";
			link.l1 = "� ��� �� ��?";
			link.l1.go = "Prosper_9";
		break;
		
		case "Prosper_9":
			TakeNItems(pchar, "potion1", 3);
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ����������, � ���� ���� ���. �� ������?";
			link.l1 = "��, �� ����� ������ �������, ��� �� ��� ������. ������!";
			link.l1.go = "Prosper_10";
		break;
		
		case "Prosper_10":
			DialogExit();
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			AddQuestRecord("SharlieF", "3");
			pchar.quest.Sharlie_RescueDaughter1.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter1.win_condition.l1.location = "Martinique_jungle_04";
			pchar.quest.Sharlie_RescueDaughter1.function = "RescueDaughter_NearCave";
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1 = "Timer";
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.hour  = sti(GetTime()+2);
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.Sharlie_RescueDaughter2.function = "RescueDaughter_CaveOver";
			NextDiag.CurrentNode = "Prosper_11";
			pchar.questTemp.Sharlie.RescueDaughter = "true";
		break;
		
		case "Prosper_11":
			dialog.text = "�� ��� ����� �� �����, "+pchar.name+". �� ���� ��������� - ���� � ������. ������ � ���� ���������� ��� ���� ���� - ��� �� ����� �����������.";
			link.l1 = "������ ��� �����������, �������.";
			link.l1.go = "Prosper_12";
		break;
		
		case "Prosper_12":
			dialog.text = "� ������� ��� �������, �� ��� ������� ��������� ����� ������ �����������. ���� ��� �������� �������� � ���������� ������� - � �������� ����� ������, � ����� ������ ���������� ������� � ���������. ������� ����� ������ ����� �������� �� ������ �������� � ����� ��������.";
			link.l1 = "��� �� ������ ���� �������?";
			link.l1.go = "Prosper_13";
		break;
		
		case "Prosper_13":
			dialog.text = "��� ����� ����� ������� �������� ���� ������ �� ����, ����� � ��� �������� ��������. ��������� ������� �������� �� ������������, � ���� ������ �� �����. ���, � ����� � ������ - ��� ��������. ��� ����� ����� �� ��������� �� ��� � ���������� �������\n������� ����-������ �� ���, ����� ��� �� ���� ���������, �������� ���, ����� ���������� ������ �� ���, �������� � �������, �������� �� �������� �� ����. ���� ��� ��� ���������� �� ���� - � �� ���������� �� ������, ��� ���������. �� ���� ��� ����� ���������� �� ���� - �� ���� ���� ����� ��������. �� �����������?";
			link.l1 = "��� �� ������� ������� ������ � ����. ��� ��� ������ ����� �� ������������.";
			link.l1.go = "Prosper_14";
		break;
		
		case "Prosper_14":
			dialog.text = "����� � ���. �������� ������, � �� ����. �������: �� ������ �� ���������� �� �� ��� �� ������� ����������!";
			link.l1 = "� �����. ������ ��� ����� ��� ���������. ������!";
			link.l1.go = "Prosper_15";
		break;
		
		case "Prosper_15":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LocatorReloadEnterDisable("Martinique_jungle_04", "reload2_back", false);
			NextDiag.CurrentNode = "Prosper_16";
		break;
		
		case "Prosper_16":
			dialog.text = "������� ���������, "+pchar.name+"! ��� ����� ����������� ��������� ����������. �������� ����� ������� - ������. � �� ����, ������� �� ���, �� �������, ��� ����-�������. ������ ����������, ����� ����� ��� ����\n� ����� � ���� ������ ��� ������ �����. ��� ���: �� ����� ���� ����� �������, ������� � ����, ����������� ������ �� ��� �����, � ���������� ����������. �������, ��������, ������ � �����. ����������� ����� ��� ��, ��� � � ������ ���: � ������� �� �����, � ����� � ������, � �� ���������� ���������� � �����\n�� ������� �� �������. ��������� �� ��������, �� ���������� ������� ���� - �������, ����� ����� �� ������� �� ���. �� ������ ������ � ��������� ����� ����� ������� ����� - ��� �����, � ��� �� ������ ������� �� ��� ��� �����\n� ���� ����������� ����� � ���� ��������, � �� ����� �����������. ������?";
			link.l1 = "������! �������� � ���� ������������ �������!";
			link.l1.go = "Prosper_17";
		break;
		
		case "Prosper_17":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LocatorReloadEnterDisable("Martinique_CaveEntrance", "reload1_back", false);
			AddComplexSelfExpToScill(20, 20, 20, 20);
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.location = "Martinique_Grot";
			pchar.quest.Sharlie_RescueDaughter2.function = "RescueDaughter_CreateIndiansGrot";
			NextDiag.CurrentNode = "Prosper_18";
		break;
		
		case "Prosper_18":
			dialog.text = "��� ���� ����! ����� ����! �� ������ �������, "+pchar.name+". � � ����� ����� ����. �� �������� ������� � ������� ����. � ��������!";
			link.l1 = "� ���, �������, ��� ��� ����������� ������������. �� ������� ������� ����, ��������� ���� ��������.";
			link.l1.go = "Prosper_19";
		break;
		
		case "Prosper_19":
			DialogExit();
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
			AddComplexSelfExpToScill(30, 30, 30, 30);
		break;
		
		case "Prosper_20":
			dialog.text = "��� ��� �������� �������, "+pchar.name+"! ������� ������ ��� ������ �������� � �����. ����� ���� ������ ��������, � �������� �������� ��� �� ��������, �� � ��� �� ���� ������������� ���, ������� ������� ����� ����������. ��� ������ �� ������ � ���� �� ������ - � � �������� ����� ��� ��. � �� ��������� ������������!";
			link.l1 = "�� ��������, �������. ���� � ������� ��� ����� �� ��-�� �����.";
			link.l1.go = "Prosper_21";
		break;
		
		case "Prosper_21":
			dialog.text = "�� ����������� �������, "+pchar.name+"! � ������ ������� �� ����� ����� ������������� � ���������� �����.";
			link.l1 = "...";
			link.l1.go = "Prosper_22";
		break;
		
		case "Prosper_22":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
			sld = characterFromId("RD_Jilberte");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
		break;
		
		case "Prosper_23":
		SelectPresentAmulet();
		dialog.text = "��� �� � ������. "+pchar.name+", � ��� ��� ��������� ��� �� ������ � ��������� ��� �� ����� ������ ��� ����������, ������� ����� ��������� ��������, ���� �� ������ ��������� ������ ������. ����� �������� ��� ���� ������ - "+pchar.questTemp.SMQ.Text+"";
			link.l1 = "������� ����������. ����� ������������� ��������� ������ ������.";
			link.l1.go = "Prosper_24_1";
			link.l2 = "���������� - ��� ������, �������, �� ������ ��� ������ ������.";
			link.l2.go = "Prosper_24";
			break;

		case "Prosper_24_1":
		TakeNItems(pchar, "Amminition_Tool", 1);
		TakeNItems(pchar, pchar.questTemp.SMQ.Amulet, 1);
			Log_Info("�� �������� ��������� ��������");
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �� ���� ������, ��� ��, � �� ������ �� ��� ������ ���������� �����, � ��� ���� ������ - ��� ��� � ������� ����-��... ��, �����. �����, "+pchar.name+"!";
			link.l1 = "�������. ��������, �������, ����� ��� � ����� ����� ����� �������!";
			link.l1.go = "Prosper_25";
		break;

		case "Prosper_24":
			AddMoneyToCharacter(pchar, 5000);
			TakeNItems(pchar, "gold_dublon", 15);
			TakeNItems(pchar, pchar.questTemp.SMQ.Amulet, 1);
			Log_Info("�� �������� 15 ��������");
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �� ���� ������, ��� ��, � �� ������ �� ��� ������ ���������� �����, � ��� ���� ������ - ��� ��� � ������� ����-��... ��, �����. �����, "+pchar.name+"!";
			link.l1 = "�������. ��������, �������, ����� ��� � ����� ����� ����� �������!";
			link.l1.go = "Prosper_25";
		break;
		
		case "Prosper_25":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload10_back", "none", "", "", "", 10.0);
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload10_back", "none", "", "", "", 10.0);
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterComplexReputation(pchar,"authority", 2);
			AddCharacterExpToSkill(pchar, "Leadership", 120);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 70);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 70);//����������
			AddQuestRecord("SharlieF", "7");
			CloseQuestHeader("SharlieF");
			DeleteAttribute(pchar, "questTemp.SMQ");
			pchar.questTemp.Prosper_fmql = "true"; // Addon-2016 Jason, ����������� ���������� (���)
		break;
		
		case "Selina":
			dialog.text = "��! (������) ��... �� �� �������������, ����� ���� ����� ��������! ���... ��� ������ ��������� ��� ����, ��� ����, ����� ����� � ������! ����� ��� ����� ������... ��� ���... ��� ��������� �����-�� ������ ������, � �����... � �� ���� ����� ��������! � ������ ���� ���� ���������! ��� ���������� ���� ��������... ������!";
			link.l1 = "���������, ������. ��� �������. ������� �������� �� ��������, � ����� ������ �� �������� �����.";
			link.l1.go = "Selina_1";
		break;
		
		case "Selina_1":
			dialog.text = "����� ��� �������� �����. �� ���... �� �� ��� ��� ��� �� ������ � ����. ���������� � ���... � ������� ��������� ����� ������!";
			link.l1 = "������-������. ���, �������, ������ �������. �� ������. � ���� ������������� ����, �� ������ �� ���� ���� � �����... ����� ������, � ������ ������... ��� ���... ���������, � ������ ���.";
			link.l1.go = "Selina_2";
		break;
		
		case "Selina_2":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_2", "", 5.0);
			sld = characterFromId("RD_Prosper");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_1", "", 5.0);
			AddQuestRecord("SharlieF", "5");
			sld = characterFromId("RD_Jilberte");
			LAi_SetStayType(sld);
		break;
		
		case "Selina_3":
			dialog.text = "������ �������� ��� �������! �� ������, ����� ������ ���?";
			link.l1 = "��... ���� ����� ������, ���?";
			link.l1.go = "Selina_4";
		break;
		
		case "Selina_4":
			dialog.text = "��... (������) ��... �� �� �������������, ����� ���� ����� ��������! ���... ��� ������ ��������� ��� ����, ��� ����, ����� ����� � ������! ����� ��� ����� ������... ��� ���... ��� ��������� �����-�� ������ ������, � �����... � �� ���� ����� ��������! � ������ ���� ���� ���������! ��� ���������� ���� ��������... ������!";
			link.l1 = "����, ����, �������... ������, � ������ �������� ����. �� ������ ���� ������ � ����� �����. �� �� ����� � ������� � ����� ������������ �������. �� ����� ���� �����, ����� ������ ����.";
			link.l1.go = "Selina_5";
		break;
		
		case "Selina_5":
			dialog.text = "���?! ��� ����... � ����! �... �...(������)";
			link.l1 = "� �������, ������. ��� ��� ���-�� ����, ��?";
			link.l1.go = "Selina_6";
		break;
		
		case "Selina_6":
			dialog.text = "(������ �����) ��... �������� �����. �� ���... �� �� ��� ��� ��� �� ������ � ����. ���������� � ���... � ������� ��������� ����� ������!";
			link.l1 = "��, �������. �� �� �� ���� ������ ������ �� ��������� �����.";
			link.l1.go = "Selina_7";
		break;
		
		case "Selina_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_2", "", 5.0);
			AddQuestRecord("SharlieF", "6");
			sld = characterFromId("RD_Jilberte");
			LAi_SetStayType(sld);
			AddComplexSelfExpToScill(20, 20, 20, 20);
		break;
		
		case "Selina_8":
			dialog.text = "��� ����... ��� ������ ����! ��, �����, � ���� �� ������������� ��� �� ��������...";
			link.l1 = "� ������ ���, ������, ��� �� � �������� �������� ����. �� ������ ������, ����������� ������ ������ ���� �� ���� ���������.";
			link.l1.go = "Selina_9";
		break;
		
		case "Selina_9":
			dialog.text = "(������) ����������, �����, ��������� ��� �� ������. ����, ����� ���� ������ ������� � ������� ���� ����, ����� ���������� ��-�����������...";
			link.l1 = "�������, ������. �������� �� ����!";
			link.l1.go = "Selina_10";
		break;
		
		case "Selina_10":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			sld = characterFromId("RD_Jilberte");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
		break;
		
		case "Selina_11":
			dialog.text = "������� ���, �����, �� ��, ��� ����� � ���� ������ �����... ������� �� ��, ��� ������ ���� �� ���������� ������. �... �... ���, �������� ���� ������� � ���������. � ����� ��� ���� � ������� ����. � ���� �� ��������� ������������!";
			link.l1 = "������, ������. � ���, ��� ��� ������� ������ ����, � �������� ���������� ���� �� ������ ������ ������ ����.";
			link.l1.go = "Selina_12";
		break;
		
		case "Selina_12":
			TakeNItems(pchar, "gold_dublon", 15);
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ����������� �������, �����. � ������� �� ������ ���. ��������!";
			link.l1 = "������, ������.";
			link.l1.go = "Selina_13";
		break;
		
		case "Selina_13":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload10_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterComplexReputation(pchar,"authority", 1);
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
			AddQuestRecord("SharlieF", "8");
			CloseQuestHeader("SharlieF");
		break;
		
		case "Jilberte":
			PlaySound("Voice\Russian\other\robinzons-08.wav");
			dialog.text = "�������, ������� ��� ������? � ���� �� ����... �� ������ � ����, � ������. ���� �� �� �� ������, ������ �� �� �������� ������ ����������� ������, � ����� ��������� ���� �� �� ���� �� ��������� � ���.";
			link.l1 = "��� ������� - ��� ���, ������������� �������?!";
			link.l1.go = "Jilberte_1";
		break;
		
		case "Jilberte_1":
			dialog.text = "� �� ���, ������������? ������ - ��������� � ���� �� ������. �����, �� ��� ������� ���-������ �� ������� ������. ���� ����������� ������, ��������...";
			link.l1 = "�-�-�... ��� ��, �������. ������ � ������ ������� �� ������, � ���� �� �����������, ��� �� ����� ����� �������� ����� ��������.";
			link.l1.go = "Jilberte_2";
		break;
		
		case "Jilberte_2":
			dialog.text = "�� ������� ���������� ����� ������, � ��� � ����� ������ ���� � ������ �� ���������... ��������� �������, ������, ������ ������. �������� � ��� �������� - � �� ������ ������������. �������, �������� ����, � ��� � �� ������������ ��� �� �������� - � �� ��� ��� � ����\n�� ������ ��� �����, � � ������� �������� ���� �������� ��������������� �� ��� �� ������ �������, �� � ������� �������. ��������� ���� � ������ �� ������. ��� � ����� ������������� ���, ��� �� ���� ������������, �����.";
			link.l1 = "������. �������� ������, � � ��� ��� ������� ���������.";
			link.l1.go = "Jilberte_3";
		break;
		
		case "Jilberte_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_3", "OpenTheDoors", 10.0);
			pchar.quest.Sharlie_RescueDaughter5.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter5.win_condition.l1.location = "Martinique_CaveEntrance";
			pchar.quest.Sharlie_RescueDaughter5.function = "RescueDaughter_GoHome";
		break;
		
		case "Jilberte_4":
			dialog.text = "��������� ��� ��� �������� ��� ���� �������� ������������� �� ��������, �����! ��� � � ������ - ����������� � ��������� ������������� ������������� ������������, � ���������� ���� � ������� ��������.";
			link.l1 = "� ���, ��� ��� ����������� ������, ��������.";
			link.l1.go = "Jilberte_5";
		break;
		
		case "Jilberte_5":
			AddMoneyToCharacter(pchar, 3000);
			TakeNItems(pchar, "gold_dublon", 20);
			Log_Info("�� �������� 20 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ��� �-�� ����� ���, �� �� �������������! ������� ��� ��� � ��������� �����������, �����.";
			link.l1 = "�����, ��������!";
			link.l1.go = "Jilberte_6";
		break;
		
		case "Jilberte_6":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.Sharlie.RescueDaughter");
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

void SelectPresentAmulet()
{
	switch (pchar.HeroParam.HeroType)
	{        
		case "Adventurer":
			pchar.questTemp.SMQ.Amulet = "indian_7";
			pchar.questTemp.SMQ.Text = "�� ���������� ������������ � ��������� ������ �������.";
		break;
		
		case "Merchant":
			pchar.questTemp.SMQ.Amulet = "obereg_8";
			pchar.questTemp.SMQ.Text = "�� ������� ��� � �������� �����.";
		break;
		
		case "Corsair":
			pchar.questTemp.SMQ.Amulet = "indian_4";
			pchar.questTemp.SMQ.Text = "�� �������� ���� ����� ������ ������.";
		break;

		case "SecretAgent":
			pchar.questTemp.SMQ.Amulet = "indian_10";
			pchar.questTemp.SMQ.Text = "�� ������� ���� ������ �����������, ��� ���� ��������� ������������ � ���.";
		break;

		case "Inquisitor":
			pchar.questTemp.SMQ.Amulet = "obereg_11";
			pchar.questTemp.SMQ.Text = "�� �������� ����� ��� ������� ������� ����� � �����.";
		break;
		
		case "Master":
			pchar.questTemp.SMQ.Amulet = "indian_1";
			pchar.questTemp.SMQ.Text = "�� ������ ������������� ������ ������� �������.";
		break;
	}
}