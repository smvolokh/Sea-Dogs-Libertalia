void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;

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
		
		case "RedChieftain":
			dialog.text = "����������� ����, ����� �������. � ������, �� ������� �������� �����. ��� ����� �������, � � ����� ���� ������ �������� ������� ��������. ��� ������ �������� � �����.";
			link.l1 = "������ ����, �����. ����� ���� ������� ���� �� ���?";
			link.l1.go = "RedChieftain_0";
			link.l2 = "��� ���� ����� ���� �� ���� �����, ����������� ��������? ������ � ���� �������, ������ �� ������, � �� �������� ���� ������ ���������.";
			link.l2.go = "RedChieftain_exit";
		break;
		
		case "RedChieftain_exit":
			dialog.text = "��-�! ��-�! ����� ������� �� ������ ����������? � ������ ���������� ���� ���������� �����-����� �����, �� ������ � �������. ������, �����������.";
			link.l1 = "�����, ����� ��� ������...";
			link.l1.go = "RedChieftain_exit_1";
		break;
		
		case "RedChieftain_exit_1":
			DialogExit();
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.RedChieftain");
			chrDisableReloadToLocation = false;
			ChangeIndianRelation(-30.0);
		break;
		
		case "RedChieftain_0":
			dialog.text = "����� ���� ������������, ��� ����. � ���� ����� ��������� ����. � ��� ������� ������ �������-������� ����� ����� �����. ��� ����������� ����� ���� ������ ��� ��� � ���� �� ���� ����� � ������ � ����...";
			link.l1 = "������... �� ������ �������, ��� ����� ������������� ��������� � ������� ����� � �������?";
			if (sti(pchar.Basenation) == SPAIN) link.l1.go = "RedChieftain_2";
			else link.l1.go = "RedChieftain_1";
		break;
		
		case "RedChieftain_1":
			dialog.text = "���, ����� ����. ��� ���� �� ������ ����, � ������. ��� �������. ��� ������ ���� �����, � ����� ��. ������� ��������� ������ �������� �� ���� �� ����, ������ ����, ������� �������� �� ������� �����.";
			link.l1 = "����� �������... ��� ������� ����.";
			link.l1.go = "RedChieftain_3";
			pchar.questTemp.RedChieftain.Spa = "true";
			pchar.questTemp.RedChieftain.AttackNation = SPAIN;
		break;
		
		case "RedChieftain_2":
			dialog.text = "���, ����� ����. ��� ���� �� ������ ����, � ������. ��� ���������. ��� ������ ���� �����, � ����� ��. ��������� ��������� ������ �������� �� ���� �� ����, ������ ����, ������� �������� �� ������� �����.";
			link.l1 = "����� �������... ��� ������� ����.";
			link.l1.go = "RedChieftain_3";
			pchar.questTemp.RedChieftain.Eng = "true";
			pchar.questTemp.RedChieftain.AttackNation = ENGLAND;
		break;
		
		case "RedChieftain_3":
			dialog.text = "�� ������ ���� ������ ������ � �������. ����� �� ������ ������. ����� � �������� - ����� ����� ��� ������. ��� ��� ���� � �� ����� ������ ���� ��� ��������. ������� ������ �����. � ������� ����, ����� ����, �������� ����� � �������� ������ ��� ����� ����.";
			link.l1 = "��. ���� �� �������, ��� �� �� ���� ������. ��� ����� ��������� �����?";
			link.l1.go = "RedChieftain_4";
		break;
		
		case "RedChieftain_4":
			dialog.text = "�������� ������ ��� ��� �� �������. �� ��� �� ������ ���� ��� ����� �����, ������� ���� � ������. ���� ���� �����, ������ ������, ������ ����� �����, ������ �� �����-����� ������.";
			link.l1 = "�, ������ �������. ���, �������, � ����� �� ����� ���� ������. � ���� ������ ��� ����� ����������� - ����� ���� �������������, �������� ���...";
			link.l1.go = "RedChieftain_wait";
			link.l2 = "� ������������� �������� �� ��� ����. ����� �������� � ������������. ��� ���� ����? �� ������, ��� ����� ��...";
			link.l2.go = "RedChieftain_5";
		break;
		
		case "RedChieftain_wait":
			dialog.text = "��-�! � ���� ���������, ����� ����... � ���� � ���� ����� ��� ���� ����, ������ ��������� ��� ���. �� ����� ���� ���.";
			link.l1 = "...";
			link.l1.go = "RedChieftain_wait_1";
		break;
		
		case "RedChieftain_wait_1":
			DialogExit();
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "RedChieftainStay", -1);
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
		break;
		
		case "RedChieftain_wait_2":
			dialog.text = "�� ���������, ����� ����? �� ������ �������� ���� ���� � ������ ������?";
			link.l1 = "��, �, �������, �������� �� ��� ����...";
			link.l1.go = "RedChieftain_wait_4";
			link.l2 = "��� ��� ����� �������������.";
			link.l2.go = "RedChieftain_wait_3";
		break;
		
		case "RedChieftain_wait_3":
			dialog.text = "� ���� ���, ����� ����.";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.Tempnode = "RedChieftain_wait_2";
		break;
		
		case "RedChieftain_wait_4":
			dialog.text = "� ����� ���, ��� �� ����������, ����� ����!";
			link.l1 = "����� �������� � ������������, �������. ��� ���� ����? �� ������, ��� ����� ��...";
			link.l1.go = "RedChieftain_5";
		break;
		
		case "RedChieftain_5":
			if (CheckAttribute(pchar, "questTemp.RedChieftain.Spa"))
			{
				pchar.questTemp.RedChieftain.Island = "Cumana";
				pchar.questTemp.RedChieftain.Shore = "Shore19";
				pchar.questTemp.RedChieftain.Add1 = "���������";
				pchar.questTemp.RedChieftain.Add2 = "� ����� ��������, ��� �������� �� ������";
				dialog.text = "��� ���������� � ������ �� ������ ���� � ����� ��������, ��� ������ ��������� �������� ������. ������ ���� ��� �������� �� ������ � ���� � ������ ����, �������-�������...";
				link.l1 = "�������. ��, �������, �������� �������?";
				link.l1.go = "RedChieftain_6";
			}
			else
			{
				pchar.questTemp.RedChieftain.Island = "SantaCatalina";
				pchar.questTemp.RedChieftain.Shore = "Shore54";
				pchar.questTemp.RedChieftain.Add1 = "����������";
				pchar.questTemp.RedChieftain.Add2 = "� ���� ������, ��� �������� �� ��������";
				dialog.text = "��� ���������� � ������ �� ������ ���� �� ��� ������, ��� ������ ��������� �������� ��������. ������ ���� ��� �������� �� ������ � ���� � ������ ����, �������-�������...";
				link.l1 = "�������. ��, �������, �������� ���������?";
				link.l1.go = "RedChieftain_6";
			}
		break;
		
		case "RedChieftain_6":
			dialog.text = "��, �� �������� ��� ����� ����������� � ���������. ������ �� ������ ���� ��� ������� - ������ �� ���� ������.";
			link.l1 = "����� ��� �������? ������ �� �������? ����� �������? ����� � ��� ������?";
			link.l1.go = "RedChieftain_7";
		break;
		
		case "RedChieftain_7":
			dialog.text = "����� �������, �� ������ � ������. ����� ������� �����-����� �� ��� ����, ����� - ������ �����, ����� �������.";
			link.l1 = "������ �� �����...";
			link.l1.go = "RedChieftain_8";
		break;
		
		case "RedChieftain_8":
			dialog.text = "������� �� �����. ����������� ��� ����� ��������� - ���� ������ �� ��������� ����� - ������� ����� � ������ �� �����, ���� ����� ����� �� ������.";
			link.l1 = "��� �����. ��� �� ����� � ��� �����������?";
			link.l1.go = "RedChieftain_9";
		break;
		
		case "RedChieftain_9":
			dialog.text = "���� ����������� ���� ������� ��������� �����, �� ����� ��������� ����������� ����� ������. � �������� ������. �� ������ �� ���� ��������� �����, ����� ����������� ������ ������� � ������� ������ � ����� � �������...";
			link.l1 = "����. ��� ���� �������� ����� ������� ������ ������... ������ ��� ���� ����������. ��. �� ����� ����� ������ ���� ����... �, �����, ��������� ���-������!";
			link.l1.go = "RedChieftain_10";
		break;
		
		case "RedChieftain_10":
			dialog.text = "�� ������������ � ����, ����� ����? � ��� � ������ �� ������ ����� ����.";
			link.l1 = "��. ���������� �� ���� ����� �������, �����. �� ����� ������ �������!";
			link.l1.go = "RedChieftain_11";
		break;
		
		case "RedChieftain_11":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			pchar.quest.Red_Chieftain_2.win_condition.l1 = "location";
			pchar.quest.Red_Chieftain_2.win_condition.l1.location = pchar.questTemp.RedChieftain.Island;
			pchar.quest.Red_Chieftain_2.function = "RedChieftain_CreateShooner";
			SetFunctionTimerCondition("RedChieftainOver", 0, 0, 30, false);
			AddQuestRecord("RedChieftain", "1");
			AddQuestUserData("RedChieftain", "sText1", pchar.questTemp.RedChieftain.Add1);
			AddQuestUserData("RedChieftain", "sText2", pchar.questTemp.RedChieftain.Add2);
		break;
		
		case "RedChieftain_pearl":
			dialog.text = "��������� ����, ����� ����. �� ������ ��� ��� � ������ � ����� ����. ���� ������ �� ����������� ���, � ������ ����� ���� �������. �� ������ ���� ��� ����� �����, ����� ���� ������.";
			link.l1 = "��, ����� ���������, ��� ��� � ���...";
			link.l1.go = "RedChieftain_pearl_1";
		break;
		
		case "RedChieftain_pearl_1":
			DialogExit();
			pchar.questTemp.RedChieftain.Ind = 1;
			AddDialogExitQuest("RedChieftain_Pearl");
		break;
		
		case "RedChieftain_pearl_give":
			int iSmallPearl = rand(200)+rand(250)+rand(200)+250;
			int iBigPearl = rand(100)+rand(100)+rand(50)+150;
			TakeNItems(pchar, "jewelry52", iBigPearl);
			TakeNItems(pchar, "jewelry53", iSmallPearl);
			PlaySound("interface\important_item.wav");
			Log_SetStringToLog("������ ����� ��� "+iSmallPearl+" ����� � "+iBigPearl+" ������� ��������.");
			ChangeIndianRelation(5.0);
			dialog.text = LinkRandPhrase("� ����������, ��� ����� ����� ��������� ����!","������ ���������� ����, �������� �����������!","������ ��� ����, ����� ����!");
			link.l1 = LinkRandPhrase("���, ��� ����� ������ ���!","�������, ����������� ����!","��, �� � ����� �� ����������!");
			link.l1.go = "exit";
			pchar.questTemp.RedChieftain.Ind = sti(pchar.questTemp.RedChieftain.Ind)+1;
			AddDialogExitQuest("RedChieftain_Pearl");
		break;
		
		case "RedChieftain_final":
			chrDisableReloadToLocation = false;//������� �������
			dialog.text = "������� ��� ��� ���������� ����, ����������� ����! � ���������, ��� ����� ����� ����� ����������� ������� �� ����� ��������. � ������ �� ��������� - ��� ���� � ���� � ������ �������.";
			link.l1 = "���������, �������! �� ��������� ������ � �������!";
			link.l1.go = "RedChieftain_final_1";
		break;
		
		case "RedChieftain_final_1":
			DialogExit();
			RemovePassenger(Pchar, npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			int n = pchar.questTemp.RedChieftain.Tartane;
			for (i=1; i <=n; i++)
			{
				sld = characterFromId("RC_Indian_"+i);
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
			}
			InterfaceStates.Buttons.Save.enable = true;//��������� �����������
			locations[FindLocation(pchar.questTemp.RedChieftain.Shore)].DisableEncounters = false; //��������� �������
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddQuestRecord("RedChieftain", "8");
			CloseQuestHeader("RedChieftain");
			DeleteAttribute(pchar, "questTemp.RedChieftain");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
