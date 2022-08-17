// ���������� ���������
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "ShadowGuarder":
			dialog.text = "���� ���� ����?";
			link.l1 = "�� - "+pchar.questTemp.Shadowtrader.Guardername+"? ���� ������� ������ �������� ��������. �� ���� ��� ��������, � �������, ����� �� ���������� ���������� � ����.";
			link.l1.go = "ShadowGuarder_1";
		break;
	
		case "ShadowGuarder_1":
			dialog.text = "�-�, � �-�� ��� ����� ���! ��� �� �������, ��� �� ������ � �������! ������, � ��� ���.";
			link.l1 = "��� � ������!";
			link.l1.go = "ShadowGuarder_2";
		break;
	
		case "ShadowGuarder_2":
			DialogExit();
			sld = characterFromId("ShadowGuarder");	
			LAi_SetStayType(sld);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.questTemp.Shadowtrader.City + "_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1_back", pchar.questTemp.Shadowtrader.City +"_store", "goto", "goto2", "", -1);
			pchar.questTemp.Shadowtrader = "begin";
		break;
	
		case "ShadowAgent":
			dialog.text = "������ ����, �������. ������ �� �������� ��������, ��-��? �������� �� ����!";
			link.l1 = "������.";
			link.l1.go = "ShadowAgent_1";
		break;
	
		case "ShadowAgent_1":
			DeleteAttribute(pchar, "questTemp.Shadowtrader.SeekTrader");
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "quest", "quest2", "CommonFlamHouse", "barmen", "stay", "Shadow_inRoom", 40);
		break;
	
		case "ShadowTrader":
			dialog.text = "������ ����, ��������. ������� ������������� � ����� ��������, ��-��. ������������: ���� ����� " + GetFullName(npchar) + ". � ���� ����� ������� ������ � ���� ������, ���� �������.";
			link.l1 = "�� ��� �� � �����������... " + npchar.name + ". �������, � ���� ���������: � �������� ���� �� ��� ��������, � ����� ������� ���� ������� �������. �� ����� ����� �� �������� ����� ������ �������� � ���� ������. ��� �����, �� ������ �������� ����� �������... ����� �����.";
			link.l1.go = "ShadowTrader_1";
			link.l2 = "���, ��� �� � �������, �������! ����� ���� �� ��������, ��� ������������ ������������ ��� ������ ������� � ��������� ����� �������� ��������� �������������? " + GetFullName(npchar) + ", ������ ������ �� ��������� � ������ ������������ � ������, � ����� �������� �����������! �� ������ ����� ������, ��� ��� ��� ���������, ���������!";
			link.l2.go = "ShadowTrader_2";
		break;
	
		case "ShadowTrader_1":
			dialog.text = "��� ���? �� ������... ���� �� ��� �������? ��� �� ��������! � ���� �����������, ��� ��� �����! ������� ����� �����... � ��, ������, � ������ ���!";
			link.l1 = "���������, �������!";
			link.l1.go = "ShadowTrader_fight";
			NextDiag.currentnode = "ShadowTrader_6";
		break;
	
	case "ShadowTrader_2":
		dialog.text = "��... ������, ����������! ������� �����������. �� �� �������� �������! � ������� ��� 5 000 ����, � �� ������ ��� ���� ����� ������ ����. ������ ���� ��������... ��� ���� ��� �����, ��? ����� ��� �? � ������� �� ������ ����� � ����� ������ �� ������. � ������� ����� � ���. �� �����, ������?";
		link.l1 = "�� ��� ��, �������, �����, ��� �� ����� ������������ ����� � ���� ������ ����� �������?";
		link.l1.go = "ShadowTrader_3";
		break;
	
	case "ShadowTrader_3":
		dialog.text = "������-������, ������, �������� ���, ��� � ���� ���� - 10 000 ����. � ���� ��� ������, �������!";
		link.l1 = "��... ���� � ���� �������, ��, �������, ��� ���� ������ ����������... �, �����! ���������� �������� ����� �������, ����� �����������... ����� ���� ������ � ����������, � ����� � ���� ������ � ���� ������ ������ �� �����!";
		link.l1.go = "ShadowTrader_4";
		break;
		
	case "ShadowTrader_4":
			dialog.text = "�������, �������, �������� ������! ��� ���� ������, � ���� �� ������ ����� �� �������. ������!";
			link.l1 = "����� ��������, ��� ��� ���-���� �������� ���������� ����!";
			link.l1.go = "ShadowTrader_escape";
		break;
	
		case "ShadowTrader_fight":
			LAi_SetPlayerType(pchar);
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("ShadowAgent_"+i);	
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
				sld.nation = PIRATE;
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "ShadowTrader_afterfight");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
	
		case "ShadowTrader_escape"://��������
			AddMoneyToCharacter(pchar, 10000);
			LAi_SetPlayerType(pchar);
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("ShadowAgent_"+i);	
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload3", "none", "", "", "", 7.0);
			}
			sld = characterFromID("ShadowTrader"); 
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload3", "none", "", "", "", 7.0);
			DialogExit();
			DoQuestFunctionDelay("ShadowTrader_final", 9.0);
			pchar.questTemp.Shadowtrader.End.Escape = "true";
			AddQuestRecord("Shadowtrader", "8");
			AddCharacterExpToSkill(pchar, "Leadership", 200);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 250);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
		break;
	
		case "ShadowTrader_6":
			dialog.text = "��! ������, �� ������ ����! � ����� ���� ��, ��� � ���� ����!";
			link.l1 = "���, ��� � ���� ����, ����� ������������ ��������. ��� �� � ������� �����, ��� � ������ ����� ����� ������������� ���� ������������� ������ � ���� �� �������?";
			link.l1.go = "ShadowTrader_7";
		break;
	
		case "ShadowTrader_7":
			dialog.text = "�... � ����� ���� ��� ��� ������ � ������ ����! ������ ������� ����! � ������� �� ������ ���� ����� � ������ ����� �� ��������!";
			link.l1 = "�����. ����������� �������, � ����� ���������. � ������ �������� ����� ���������� ���� ������������ � ���� ������ - ������ ��� �� ������.";
			link.l1.go = "ShadowTrader_free";
			link.l2 = "���, ��������. ���� �� ���������� �� ����. � ������ ��������� ����� �������� ������ ����� �������� - ������ � �������!";
			link.l2.go = "ShadowTrader_killed";
		break;
		
		case "ShadowTrader_free"://���������
			AddMoneyToCharacter(pchar, 20550);
			TakeNItems(pchar, "jewelry1", rand(5));
			TakeNItems(pchar, "jewelry2", rand(20));
			TakeNItems(pchar, "jewelry5", rand(20));
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ��������");
			LAi_SetPlayerType(pchar);
			sld = characterFromID("ShadowTrader"); 
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload3", "none", "", "", "", 5.0);
			DialogExit();
			DoQuestFunctionDelay("ShadowTrader_final", 7.0);
			pchar.questTemp.Shadowtrader.End.Free = "true";
			AddQuestRecord("Shadowtrader", "9");
			ChangeCharacterComplexReputation(pchar,"nobility", 5); 
			AddComplexSelfExpToScill(70, 70, 70, 70);
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		break;
	
		case "ShadowTrader_killed":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			LAi_SetActorType(pchar);
			LAi_ActorAnimation(pchar, "Shot", "ShadowTrader_killed_end", 1.3);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}