// �������� �����
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbyInHouse")
				{
					dialog.text = "������������, ������. ���� ��� ������. ��� ������� ��� � ���� �������� ������?";
					link.l1 = "������ ����, ��������. ���� ����� " + GetFullName(pchar) + ". � �������, � ����� �� ����� ���������� ���������� ��������� � ����� � ����������� ����-������� �������� � ���������.";
					link.l1.go = "AbbyAndLucas";
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "AbbyFindScull" && makeint(Pchar.money) >= 200000)
				{
					dialog.text = "�� ����� ������ ����� ����? ��� ������? ��, ��� �� � ���������... ������� ����� � ����� ����, �� ����� � ���� ����������. �������� � ����, ������!";
					link.l1 = "��� ���, �������.";
					link.l1.go = "exit";
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "AbbyLeavesMarried")
				{
					dialog.text = "�� ������ ��� �� ������, �������! ��� �� � ��� ����������! ������ ������ ��� ����� ������� ����� �������������.";
					link.l1 = "��� ��� ������, ��������. � �������, ����� ������ �� ���������� ��� �� ����, ����� ����� ����� �� ����� �������. � �����, �� ������ ������� ���� ��������� ��������� � ��������� ��� � ����� �����.";
					link.l1.go = "AbbyAndLucas_8";
					break;
				}
				dialog.text = "�� ��� ���-�� ������ ��� �������, �������?";
				link.l1 = "���, �������. � ��� �����.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				if (pchar.questTemp.HWIC.Eng == "AbigileInChurch")
				{
					dialog.text = "���� ��� ������, ������. ����� ���� ������� ��� � ������ �������?";
					link.l1 = "������������, ��������. � ������ �� ������� ��������...";
					link.l1.go = "Seek_Island";
					break;
				}
				dialog.text = "�� ��� ���-�� ������ ��� �������, �������?";
				link.l1 = "���, �������. � ��� �����.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "toVillemstad")
				{
					dialog.text = "��� ����� ����������? ��� �� ���? ����, ��� ���?";
					link.l1 = "������������, �������. ��, ��� � �������, � ���� ��������? ����� ��� ��� ������! �������� ��� ��������, �� � ������ �������� ��� ������ ��... �� ��� ���� ��� �� ����� � ������ �������� ���. ������, � ������������� ������ ��� ��� �������� � ���� ������� ��� ���.";
					link.l1.go = "Abigile_kidnapping";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileNextDay")
				{
					dialog.text = "��, ��� � ��, �����. � ������ ��������� �� ����.";
					link.l1 = "������������ � ����!";
					link.l1.go = "Abigile_kidnapping_7";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileInCabin")
				{
					dialog.text = "�� ��� � ����-������, �����? � ����� ����� �������?";
					link.l1 = "��, ����, �� ��� � ����-������. �� ������� � ��������� ��� � ������ - �� ������� ����������� �� �� ����� ������� ��������� ��� ��� ����� ���������� � ���������� ���� � ������� ���������. �� �� ���������������, �� ������ ��������� �� �����, ��� ����� ������.";
					link.l1.go = "Abigile_kidnapping_8";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileLie")
				{
					dialog.text = "�����! ��� � ���� ��� ������! �������, ���� �� ����� �� �������?";
					link.l1 = "���, ��� ������� ����. ������ �������� ��� ����������� � ���������� - �����-�� ������ � ����� ��������� ����, ���-�� ��������� � ��������� ������ ����������. ��� ��, ��������, ������ ����������� � ����� ������?";
					link.l1.go = "Abigile_kidnapping_13";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbiReturnHome")
				{
					dialog.text = "�����! ��� ��! ������� �� ���������!";
					link.l1 = "������������, ������� ����. ��� ��� ������.";
					link.l1.go = "Abigile_return";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbiReturnHomeGo")
				{
					dialog.text = "��, �������-�� � ����! ��� � ���� ����� ������ ����! �����, ������� ��� �������� �� ���, ��� �� ��� ���� �������!";
					link.l1 = "�����, �� �����, ������� ����...";
					link.l1.go = "Abigile_return_6";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistoryNext")
				{
					dialog.text = "�������, ���� �� ���-�� ������� - ����� ���! ����� - ��... ��� ����� ��������. ��������, ����� ����, ����� �� ������ ��� ������!";
					link.l1 = "";
					link.l1.go = "Abigile_return_12";
					pchar.questTemp.HWIC.Self = "SolomonHistoryAfter";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistoryEnd")
				{
					dialog.text = "� ���� �������� �� ���, �����! �������.. �������, ��� �� ������� ���! ��� �� ������� ������!";
					link.l1 = "� ������ ���, ��� ����� � ���� �����, ������� ����.";
					link.l1.go = "Abigile_return_13";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "final" || pchar.questTemp.HWIC.Self == "VanbergDestroyed")
				{
					dialog.text = "��, �����! �� ���������! ��� �������? �� ����� ������?";
					if (makeint(Pchar.money) >= 200000)
					{
						link.l1 = "��, ���. � ������, � ������ ������ ����. � ������, ����� ������� �� ���.";
						link.l1.go = "Abigile_GiveMoney";
					}
					link.l2 = "���, ����. ��� �� ������� ��������� �� �������� �������, �� ������. � ������ ���, ��� ���.";
					link.l2.go = "Abigile_NoMoney";
				break;
				}
				dialog.text = "��, ��� ��, �����! �� ���-�� ������ ��������?";
				link.l1 = "���, ������. � ��� �����.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "������ ����. �� ���-�� ������?";
			link.l1 = "���, �������. ����� ���� ��������. �� ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

//-------------------------------------------------�� ���������-----------------------------------------------
		case "AbbyAndLucas":
			dialog.text = "����� ������� �������������, ������� " + GetFullName(pchar) + ". � ��� ��� �������. ���� ��� �� ��������� ��������� �������-������� � ��������� ��� � ����������. �������, �������, ��� ������... ��� ���� �������� ����������... ������ �������?";
			link.l1 = "������ ���, �������. �� ��� ���� ��������� ��������. �������� ������ - ���������� ������ �� ������ ������, ������������ ����������� ���������... � ���� ����� �������: ����������� �������� '�������-��������', �� ������� � ������������� �������� � ������� �� ����������� ����!";
			link.l1.go = "AbbyAndLucas_1";
		break;
		
		case "AbbyAndLucas_1":
			dialog.text = "��� ������ ��� �������, �������... � ����� ����� ������� ��������, � ������� �� �� ��������, ��� ��...";
			link.l1 = "�������, ��� �������� � ����� ������ ������� ������ ����������� �� ������� �� �������, �� ����� �������, ������ ����������. ������ ��� ����� �� ���� �����. ������� ������� ������� ���� �����, � ����� �������� � '����' ��� � ����� � �������. � ����� ������� ������ ����� ������ - �� �� �������� �������� ��� ���������� ������...";
			link.l1.go = "AbbyAndLucas_2";
		break;
		
		case "AbbyAndLucas_2":
			dialog.text = "����� ������... ������, ��� ���� ��� ����. �� � ������ ������ �������, ��� ������ � ���� ��� �����. ������, ��� ��� ����������� ������� � �� ��������� �������������... ��, ��������, �������. ��� ��� �� ����� ������ ������������� ��������, ��� ��, �� ������� �������?";
			link.l1 = "��������, � ������ � ��� �� ������ ����� ���������� � ����������� �������. ����� ��� ��������� ����.";
			link.l1.go = "AbbyAndLucas_3";
		break;
		
		case "AbbyAndLucas_3":
			dialog.text = "�������, ������. � ��� ������.";
			link.l1 = "��� � ��� ������, � ����� ��������, � ����� ��������� - �� ������ ��� ������ ��������, �� ����� � ������� ����. � ��� ���� ������ �������� ������� �� ���� ��������� ��� ����������� ���� � ������. � ������ ������� ��� ����������� ����� ����� ����� �������. ���� ��� �� ����� �� ���.";
			link.l1.go = "AbbyAndLucas_4";
		break;
		
		case "AbbyAndLucas_4":
			dialog.text = "��, �������! �������, � �������, ������ ������ ��������� ��� �� ������� ������� ��� �����������... ��� ������ ���� ����� ��������� ���������, ��...";
			link.l1 = "�������, � ����, ��� ��� ���-�� ��������. ����� ������� ���������� ��� ����������� � ����������� ������ ����� ���������? �����, � ����� ������� ��� � ��������?";
			link.l1.go = "AbbyAndLucas_5";
		break;
		
		case "AbbyAndLucas_5":
			dialog.text = "�������, � �� ���������� � ����������� ������� ����������. ����� ������ ��� ���� � ����� ���� ������� �����... � ���� �� ����, ��� �� �� ������ ������� ��� ��� ���������������. �� � ����� ���, ������� ����!\n�� ���� �� ���� ������, ����� ������� ������ ����� ��������� ����� ����������... ���� �� �� ���� ����������� �����. � �� ���� ������� ���� �������������� �� ������... ��� ������ ����� ������� ��������, ��� ���� ���������� ������ ������ ������� ���������� � ������ �����. ��, ���� �� ������ ��� ���� ��������, ��� ��� �� ������! �� ������� ��� ��� ������ ����� �����, ����� ��� �� ��������� �������, ���������� ���� ������ � �����!\n�� ��� ������ ���� �� �����, �� ������ �� �����, ��� ���� ����������� ������ �����. ���������� � �����, �������! �����, �� ��������. ���� �� �� ������ ������ ����� ���� ������ � ���� ������!";
			link.l1 = "������, ��������. � �������� � ����� �����. �����, ��� �� ��� ��������. � ������ ���, ��� ����� ������ ��������.";
			link.l1.go = "AbbyAndLucas_6";
		break;
		
		case "AbbyAndLucas_6":
			dialog.text = "�������, ������. � ���� �������� �� ���. �� ������� ��� �������!";
			link.l1 = "�� ��������, ��������. ����� ���� � ������� �������.";
			link.l1.go = "AbbyAndLucas_7";
		break;
		
		case "AbbyAndLucas_7":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "1-27");
			pchar.questTemp.HWIC.Holl = "AbbyFather";
		break;
		
		case "AbbyAndLucas_8":
			dialog.text = "�, ��! ������ ��������� - �������������� �������. � ��� ��������� ��� �������� � ���� ��������� ������� ��� ����� �����.";
			link.l1 = "����� � ������ ���� ������ �����������. ��������� �����������, � ������ ��������� � ��������� � ���������� ���. �, �������: � �������� ����� ��� �������!";
			link.l1.go = "AbbyAndLucas_9";
		break;
		
		case "AbbyAndLucas_9":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "1-33");
			pchar.questTemp.HWIC.Holl = "AbbyAgreeMarried";//������ � ������
		break;
		
//-------------------------------------------------�� ������-----------------------------------------
		case "Seek_Island":
			dialog.text = "�� �������?! ��, ������! � �������, ��� �� ��� �����. ��� ���, ������� ���?! � ��� ��� � �������?";
			link.l1 = "������ ��� � ��� ����� ������. �������� ��������� �������� �� �������, �� �� ���� ���� �� ��������. ������ ���������� ��� ������ � ��� � ������, ��� �� ������� �����������. ��� ������������ ���������, � �� ���� ������ ������ ������.";
			link.l1.go = "Seek_Island_1";
		break;
		
		case "Seek_Island_1":
			dialog.text = "��, ����� �������, ��������� �������, ��� ���� ������ ������� � ���� �� ������ ������ � ��� �� ���� �����. �� �����, ��� ��� ����� ����� ����� ������� ����. � � �������� � �� ����, ��� ��� ������. ���� �� ������ ���� ����� ��� ����������� ������ � ������ � ����� �������� �������... ��������, ��� ���� ���-�� �� ������� ����.";
			link.l1 = "������... � ��� ������ ������� ��������� ��� �� �������. ������, � ����� ���� ������, � ���� ������ �� ���� ��� ����������, � ������� ��� ���, � ����� �� ����������� �� ���� � ����-����� � �������.";
			link.l1.go = "Seek_Island_2";
		break;
		
		case "Seek_Island_2":
			dialog.text = "��, �� ��� �����������! ������� ��� ��������, �������! � ���� �������� �� ���! ��������, � �� ������� ��� �������!";
			link.l1 = "� �� �������� ��� ����� �����, �������. �� ������ �������!";
			link.l1.go = "Seek_Island_3";
		break;
		
		case "Seek_Island_3":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "2-18");
			pchar.questTemp.HWIC.Eng = "SeekIsland";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "Villemstad_houseSp2_bedroom", "goto", "goto1", "", -1);//��� �����
			pchar.questTemp.HWIC_Coordinates = "true"; //������� ��������� �� ����� ������� ����� �����
		break;
		
//--------------------------------------------������ ����------------------------------------------------
		case "Abigile_kidnapping":
			dialog.text = "��... �� �������� ������ �� ����... ��? ��, ����, �� ��� �� �� ����� ���������! ����� ��� ������ ���������! ������, ����� ���, ����� �� ����, � ���� ���������� � ����.";
			link.l1 = "�������, ����������� �������.";
			link.l1.go = "Abigile_kidnapping_1";
		break;
		
		case "Abigile_kidnapping_1":
			DialogExit();
			npchar.greeting = "abigile_3";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "Villemstad_houseSp2_bedroom", "goto", "goto1", "Abigile_Stay", -1);
			NextDiag.CurrentNode = "Abigile_kidnapping_2";
			pchar.questTemp.HWIC.Self = "AbigileTalk";
		break;
		
		case "Abigile_kidnapping_2":
			dialog.text = "�������� ����� ����, ������. �� ������ � ������� �������, ������... �������� �� ���� ���� ��������� ��������� ���.";
			link.l1 = "��� � �������, �������. ��������� ������������ - �����... ��������. � ������ �� ������� ������� ��������, ����� ������� ��� � ����. ���, ����������, �������� ��� ������.";
			link.l1.go = "Abigile_kidnapping_3";
		break;
		
		case "Abigile_kidnapping_3":
			RemoveItems(PChar, "NPC_Letter", 1);
			dialog.text = "��, ������...(������). �, ����! �� �����... ����� �������� ���� ��� ���������� �� ������! ����� ������������! ����� ������! ������, �� - ������ �������! ������ - ��� ��? �� �� �������?";
			link.l1 = "���, �������. �� ������� ���� ��������� ���������, �� ������� ��������� �������. �� ������ �� �������... �� �� ��������.";
			link.l1.go = "Abigile_kidnapping_4";
		break;
		
		case "Abigile_kidnapping_4":
			dialog.text = "��������� ����! �������, �� � ������������? ���� �������?";
			link.l1 = "�� ���������� ���, �������! ������ �� �����, ����� ���� ���� ��� ��� ������ ����� �����-�� ��������. �� ��� ���� �� ��������. � � ��� ������ ������ �������� ��� � ���� � ����-�����, � ����� �� ���� ������� �� ���� � ����� ���������� �������. ����� �� �������� � ������... ��������� ������, �����������... ����.";
			link.l1.go = "Abigile_kidnapping_5";
		break;
		
		case "Abigile_kidnapping_5":
			dialog.text = "����? ��, �� ��...(������). �����, � ������ � ���� �������. ��� ����� ����, ����� ������� ���� ���� � ����������� � �����. ��������� ������, � � ��������� �� ��� �������.";
			link.l1 = "������, ����. � ���� ������. � �� ������������ �� ���� - � ��� ������� ������� ��� �� ����� ������������� � ����.";
			link.l1.go = "Abigile_kidnapping_6";
		break;
		
		case "Abigile_kidnapping_6":
			DialogExit();
			npchar.greeting = "abigile_2";
			NextDiag.CurrentNode = "First time";
			AddQuestRecord("Holl_Gambit", "3-22");
			pchar.quest.Abigile_Kidnap.win_condition.l1 = "Timer";
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.hour  = 7.0;
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l2 = "location";
			pchar.quest.Abigile_Kidnap.win_condition.l2.location = "Villemstad_houseSp2";
			pchar.quest.Abigile_Kidnap.function = "AbigileGoToShip";
			pchar.questTemp.HWIC.Self = "AbigileWaitNextDay";
			SetFunctionTimerCondition("AbigileGoToShipOver", 0, 0, 3, false);//������ 3 ���, ��� �����
		break;
		
		case "Abigile_kidnapping_7":
			DialogExit();
			chrDisableReloadToLocation = true;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "SetAbigileToCabin", -1);//��� � ����� � �� ��������
			AddQuestRecord("Holl_Gambit", "3-23");
			pchar.questTemp.HWIC.Self = "AbigileOnShip";
			pchar.quest.AbigileGoToShipOver.over = "yes";//����� ������
			SetFunctionTimerCondition("RemoveAbigileOver", 0, 0, 30, false);//������ �� 1 �����, ��� �����
			pchar.quest.Abigile_died.win_condition.l1 = "NPC_Death";
			pchar.quest.Abigile_died.win_condition.l1.character = "Abigile";
			pchar.quest.Abigile_died.function = "AbigileDied";//���������� ��� ����� ��������
		break;
		
		case "Abigile_kidnapping_8":
			dialog.text = "��, ��� ����! �� � �����, ��� � ������ � ��������� ��������� ��� ������, ��� ����� ������� ������� �� �����...";
			link.l1 = "�� ����� ��������� �������, ����. ��, � ����� �������� ���� �� ���� ����� ������ � ����� ������ �����, � ��������� ��� ������ � ��� ����� ����� - ��� ��� ��� ����� ������������ ������� ��� � ������ �������.";
			link.l1.go = "Abigile_kidnapping_9";
		break;
		
		case "Abigile_kidnapping_9":
			dialog.text = "�� ����� ����������, �����. ������� ���. � � ������ ������� ���� �������� �� ���� ���������� �����.";
			link.l1 = "�������� �� ����, ������� ����!";
			link.l1.go = "Abigile_kidnapping_10";
		break;
		
		case "Abigile_kidnapping_10":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.questTemp.HWIC.Self = "AbigileInHouse";
		break;
		
		case "Abigile_kidnapping_11":
			dialog.text = "���� �������������, ����. ������� �� ���� ��������������, �����������!";
			link.l1 = "...";
			link.l1.go = "Abigile_kidnapping_12";
		break;
		
		case "Abigile_kidnapping_12":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3", "SentJons_HouseF3_Room2", "barmen", "bar1", "ContinueWithMerdok", -1);
			pchar.questTemp.HWIC.Self = "AbigileInRoom";
			NextDiag.CurrentNode = "First time";
			RemovePassenger(Pchar, npchar);
			pchar.quest.RemoveAbigileOver.over = "yes";//����� ������
			sld = characterFromId("Merdok");
			LAi_SetActorType(sld);//����� ������ ��� � ��� �� ���������
		break;
		
		case "Abigile_kidnapping_13":
			dialog.text = "��, �����, �� ��� ���� �������� � ��������, ��� �� ��� ����� ������ � ���� � �� ��������� ������.";
			link.l1 = "��, �� �����, ��� �� �� ���� ��� �� ��� ��������... ����, ������ - �� ������ �������. �� ����� ���������� ��������. ����� ������ �������, ��������� ������� ���������� ������, ������� ������ ��������� � �������� �������� ������������ ����������� ������ �� ����������.";
			link.l1.go = "Abigile_kidnapping_14"
		break;
		
		case "Abigile_kidnapping_14":
			dialog.text = "�� ��� �� ����� ��������?!";
			link.l1 = "��, ����. ��� ����� � ��� ���� - ������� �������... � ������ �������� ������� � ���, �� � ��������� ����� �� ���� ����� �������, � ��� ����� � �� ����. ��������, �� ��������� ����� ��������� ���������. � ����� ���������, ��� ���������� ����� ������� �� ��������� ��� ���������� � ����.";
			link.l1.go = "Abigile_kidnapping_15";
		break;
		
		case "Abigile_kidnapping_15":
			dialog.text = "�����, �� ���� �������. �� �������, ��� � ��� ��� � �������?";
			link.l1 = "������ ����� ������ ���������. ������ �... ��, ������� �� ������� ��, ��� �� ������ ��������� � ����, ���� ������� - ������ ���� ������ � �� �� ������ �������� �����, ���� ���� ���. ";
			link.l1.go = "Abigile_kidnapping_16";
		break;
		
		case "Abigile_kidnapping_16":
			dialog.text = "��, ������ �����... � ���� ����� �������, ������� �����������. �����, ����������, ��� ����� ������������ � ����-������? � �� ���� �������������� ����� ��������������� �����.";
			link.l1 = "�� ��� �� ����� ��������, ����! �� ����� ������������ ���������� ��� �����, � �� ���� � ����� ��������, ���� � ������ �������� � ����� � ��� ������� ����� ����� � �������!";
			link.l1.go = "Abigile_kidnapping_17";
		break;
		
		case "Abigile_kidnapping_17":
			dialog.text = "�����... � ������������� ������� ����� ���������� �� ���. � ����� ���� ������� �������, �...";
			link.l1 = "����! � ������ �������� � �����-�� ��������� ������. � ������� ���� �� �����, ���� �� ��������� ���������� ���� ������� ������� � ���.";
			link.l1.go = "Abigile_kidnapping_18";
		break;
		
		case "Abigile_kidnapping_18":
			dialog.text = "�������, �����. � ����, ��� �� �����... ������� �������.";
			link.l1 = "��� ��� ����, ����. � ������ ��������� �����������. ��, �� ������ ��� ������ ������ �� ������ - ��� �� ������� ������� � ���� ����?";
			link.l1.go = "Abigile_kidnapping_19";
		break;
		
		case "Abigile_kidnapping_19":
			dialog.text = "��... ���� ����� ������� � ���������� ����������. �� ����� ������ ������������ � ����� �������� � ���������, � ������������ ��������. �� �������� � ����� �������. � ���� � �������... ��, �������, � ����� ������ �� �������.";
			link.l1 = "� �����, �� ����� ��������. ���� ��� ���-�� ����������� - ����� �������� ������ � ����� �������.";
			link.l1.go = "Abigile_kidnapping_20";
		break;
		
		case "Abigile_kidnapping_20":
			DialogExit();
			pchar.questTemp.HWIC.Self = "MeetTonzag";
			pchar.quest.Meet_Tonzag.win_condition.l1 = "location";
			pchar.quest.Meet_Tonzag.win_condition.l1.location = "SentJons_TownCave";
			pchar.quest.Meet_Tonzag.function = "TonzagMeetingInDange";
		break;
		
		case "Abigile_return":
			dialog.text = "�� ���� �������� ����� � �������... �� �����. �� �� ������, ��� � ���, �����?";
			link.l1 = "����, ��������. ��������... ������ ������� ����� � ������ � ����� �� ������ �� ��������. �� ������� �� �� ���������, �� �� �������, �� �� ��� ���-��... � �����, ����� ����, ��� �� �������� � ����, � ��� �� ���� � ����� �� ����.";
			link.l1.go = "Abigile_return_1";
		break;
		
		case "Abigile_return_1":
			dialog.text = "��, � ��� � �����, ��� ��� ���� ��������... ���� ���� ������� ����... �� ������� ����, �� ��� �� ��������, ����� � ����� �� ������ ����������.";
			link.l1 = "��� ��� ��������, ���� ����...";
			link.l1.go = "Abigile_return_2";
		break;
		
		case "Abigile_return_2":
			dialog.text = "�� ���, �����? �� �� � ��� �� ��������.";
			link.l1 = "�� ��, ��� ����� ��� ��������� ���������� �������: ����� ��������� ��������� �� ������� ���������� ���������� � �����������, ����� ��������� � ���������� � ����� ��� ���. � ������ ��� ������ � �������. � ������ ����, ��� �� ������� ����� ��������� �������� ������ �����������, �� � ������ ��� ��� ������� � ����� ��������, �������� ���� �� ����� ������.";
			link.l1.go = "Abigile_return_3";
		break;
		
		case "Abigile_return_3":
			dialog.text = "�, ����! ����� ����! �����, ��� ������? ���, �������, ��� ��� �� ���!";
			link.l1 = "���. ������� ����, ������� ����� ����: � ���������� ������������� ������������ ������ ���� �����������, ��� �����, ���������� ��� ����� �� ���� � ����������, �������� ������� ����������. ��� ����� ����, ��������, ��� ����� �� ����� �������� �� ��������� �� ��� ������ ����������� � ����������� � ���������.";
			link.l1.go = "Abigile_return_4";
		break;
		
		case "Abigile_return_4":
			dialog.text = "��... � ���� ��� ����. � ��������� ����������. �����... ����������... �������� ���� �����, � ����������. � ���� � ����...";
			link.l1 = "�������, ������� ����. � ������ �� ��� � ��� ����� �������. � ���������, � ����-������ ��� ������ ������ ������. �����, �������� ���� ����, ������������ � ������, � �� ���������� � ����.";
			link.l1.go = "Abigile_return_5";
		break;
		
		case "Abigile_return_5":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-57");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload4", false);//������� ������� ���
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			pchar.questTemp.HWIC.Self = "AbiReturnHomeGo";
			pchar.quest.AbiReturn_Home.win_condition.l1 = "location";
			pchar.quest.AbiReturn_Home.win_condition.l1.location = "Villemstad_town";
			pchar.quest.AbiReturn_Home.function = "AbiGoInVillemstad";
		break;
		
		case "Abigile_return_6":
			dialog.text = "���, �����, �����. ���� �� �� �� � ���� - �� ����, ��� �� �� ���� ����. �� ������������ ��������� ����, ���� � ��������� �� ����������.";
			link.l1 = "���... �� �������� ���� � ������, ��������. ��� ��� ��� ������. � ��� ����� ����, ��� ��� ��� �����.";
			link.l1.go = "Abigile_return_7";
		break;
		
		case "Abigile_return_7":
			dialog.text = "������, �����, �� ����� ����������� �� ������� � ������ ��������... ������ ��� ������������ - ������ �������, ������ ��������� - ������� ��� ��������� ����, ������� ������� ����������. � ������ ����� � �����, � �� ��������� ���������� �����\n������, ����� ������� - � ��� ����������� ��� �����. �� �� ���������.";
			link.l1 = "����, ����� ��� ��� ���������� � ���� �� ��� ����. �... ��, ������� ���� ��������� - � ���� ��� ������.";
			link.l1.go = "Abigile_return_8";
		break;
		
		case "Abigile_return_8":
			dialog.text = "������? �� ���, �����?";
			link.l1 = "�� ������� � ���� ������� ������ �������� � ������ ��������. ����� � ����, ��� ��� ���� ������� �� ������� ���� ���������� �� ���� ������������ �������. � ���� ����������� ����� ���.";
			link.l1.go = "Abigile_return_9";
		break;
		
		case "Abigile_return_9":
			dialog.text = "��, �����... �� �, �� ��� ����, �� ������ ���� �������������� ����������, ��� ��������� ���� ����������� ������. �� �� �� ������. � ���� ��� �������� �����, ��� ������ ������ � �� �����.";
			link.l1 = "��������, ������������ ��������� ���� �����-�� �����, ������ �����������. �����, ���-�� �������������� ��������� �� ��� ������? ����� �� ���� ���� ������?";
			link.l1.go = "Abigile_return_10";
		break;
		
		case "Abigile_return_10":
			dialog.text = "������... ������ � ������. ����, �������. ��� �����. ���������! �����, ��� ��� �������. ��������� �� ��������� ������ �� ��������� ����� ������-�� ��������. �� ��� ��������� �� ��� ������� � �������� � ����� ���������. �� ���� ���� ���. ��������, �� �����, ��� ���� ������.";
			link.l1 = "��� ���-��! ��� ��������� ���� �����, � ��� ����� ��������?";
			link.l1.go = "Abigile_return_11";
		break;
		
		case "Abigile_return_11":
			dialog.text = "� �� �����, �����. ����������...";
			link.l1 = "��... ������������ ���������, ���!";
			link.l1.go = "Abigile_return_12";
			pchar.questTemp.HWIC.Self = "SolomonHistory";
		break;
		
		case "Abigile_return_12":
			DialogExit();
			sld = characterFromId("Solomon");
			sld.greeting = "solomon_1";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Abigile_return_13":
			dialog.text = "�� ����� ����� ���, �����. �� - ���� �������� �������. � ���� �������� �� ���. �� ������� ��� �������!";
			link.l1 = "� ��� ����������� � ����. �� ��������, ��������! �� ��������, �������.";
			link.l1.go = "Abigile_return_14";
		break;
		
		case "Abigile_return_14":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "Villemstad_houseSp2_bedroom", "goto", "goto1", "ReturnAbiNormal", -1);
			pchar.questTemp.HWIC.Self = "SeekFleut";
			AddQuestRecord("Holl_Gambit", "3-58");
		break;
		
		case "Abigile_NoMoney":
			dialog.text = "��, ����� �������... �� ��� ���������, ��... ��� ����� ������� ���, �����, �� ��, ��� �� ���� �� ���������� ��� ������. ������, ������ ������.";
			link.l1 = "��������, ��������. �������, � ��� ��� ���������.";
			link.l1.go = "exit";
			npchar.dialog.currentnode = "Abigile_Poor";
		break;
		
		case "Abigile_GiveMoney":
			dialog.text = "���... ��� ������? �� ������������� �������� ��� ���������� ������? �, �����!";
			link.l1 = "��, ������. ��� � ����. � ����� ��� �� ������� ����� ������. ���, ��������. ��� ����.";
			link.l1.go = "Abigile_GiveMoney_1";
		break;
		
		case "Abigile_GiveMoney_1":
			AddMoneyToCharacter(pchar, -200000);
			pchar.quest.MakeAbiPoor.over = "yes"; //����� ����������
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			dialog.text = "��� ��� ��� �����������!? ���!?";
			link.l1 = "�� ����� ������� ��������������, ���. ��� ����� �����, ��� � ���� ��� ��� �������. ������ �� ������� ����� �����, ��� ������ ���������, ����������� � ������ ������������ ���������. �����, ��� ���� ������ ������, ��� ����������� ���� �������.";
			link.l1.go = "Abigile_GiveMoney_2";
		break;
		
		case "Abigile_GiveMoney_2":
			dialog.text = "�����... �� ������� ��� ���� �������, ��� ���� � ��� ����� ������� ����. � ��� ���� ��������, ��� �� ���� � ���� �����. � ��������� �������� �� ��� ���������. �� - ��� �����-���������. ��� ������ ����� ����� ��� �������, ������ �� � ��� ������, ��� ���\n������, ��� �� ������, � ����, ����� �� �����: ����� ����� ���� ������� ��� ��� � ����� ����� ��� � ����. �... ��������� ��� ��� ����������, ������� �����...";
			link.l1 = "��... ��, �������... ���.";
			link.l1.go = "Abigile_GiveMoney_3";
		break;
		
		case "Abigile_GiveMoney_3":
			DialogExit();
			npchar.greeting = "abigile_1";
			PlayStereoOGG("music_romantic");
			SetLaunchFrameFormParam("", "", 0, 7);
			SetLaunchFrameFormPic("loading\inside\kiss.tga");
			LaunchFrameForm();
			DoQuestFunctionDelay("GoFromAbiRoom", 7.0);
			npchar.dialog.currentnode = "Abigile_AllRight";
		break;
		
		case "Abigile_Poor":
			dialog.text = "���� ��� ������, �����. � ��� ��� ��-��������... �������� - ��� ��� ������...";
			link.l1 = "���������, ����. �� ������� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Abigile_Poor";
		break;
		
		case "Abigile_AllRight":
			dialog.text = "�����! ��� ��! � ���� ��� ������! ���������, ���������� � ����.";
			link.l1 = "� ���� ��� ��� ������, ���. � ���, ��� � ��� ��� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Abigile_AllRight";
		break;
		
		//--> ���� ������������ �� ������� ������� � ������
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! � ��� ������� � ��� ��� ����"+ GetSexPhrase("�","��") +", � �� �� ��������� ������ ��������?! ������-�-�!!!";
			link.l1 = "��������, ����...";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- ���� ������������ �� ������� ������� � ������
	}
}