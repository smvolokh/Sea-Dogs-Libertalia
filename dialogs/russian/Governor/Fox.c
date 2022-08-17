// ��������� ���� - ������ �������� ������� ������ '������� ����'.
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
			if (CheckAttribute(pchar, "questTemp.Terrapin_KathyReward"))
			{
				dialog.text = "��� �� ������, ������? ��... ��������! �������, � �������: �� ��� ����� �������, ������� ������� ��� ���� �� ��� ����������� ���������� �������� ���������!";
				link.l1 = "����, ������ ��� �� ���������� ��� ���...";
				link.l1.go = "terrapin";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Usurer") && !CheckAttribute(npchar, "quest.utensil"))
			{
				dialog.text = "��� �� ������, ������?";
				link.l1 = "������ ����, ���������. � � ��� �� ��������� ���������� ����. ������� ���� �����?";
				link.l1.go = "guardoftruth";
				break;
			}
			// Addon-2016 Jason, ����������� ���������� (���) ����-���������
			if (CheckAttribute(pchar, "questTemp.FMQN") && pchar.questTemp.FMQN == "eng_reward")
			{
				dialog.text = "��� � �������, �� - ��� ����� �������, ������� ����� ���� ����� ��������� ������� �� ����-��������? "+TimeGreeting()+"!";
				link.l1 = TimeGreeting()+", ���������. ��, ��� ������ �.";
				link.l1.go = "FMQN";
				break;
			}
			dialog.text = "��� ��� ������, ������?";
			link.l1 = "������. � ��� �����.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guardoftruth":
			dialog.text = "������������, ��� � ��� ���, ��� �� ������...";
			link.l1 = "������� �� ��������� ����� ������������ ������, ����� �������, � ��������� �������� � ����-�����...";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "��������? � ���! ������� ����������� ������� �� ����� ���������� ���� �������� �������. � �������� ���������� ������, ������ ������� ����, ��������� � ��������� ���������� ���������. � ������ �������� � ��� �������� �� �������� - ���� ����-����� �������� �� ���, ��� �� ��������� �� �����!";
			link.l1 = "����. ������, ������������ � ���� ���������� ��� �� ��������... ���������, ���� �����, �� ������� ��� ������? � ����� ������ ���� ����, ������� ��� �� ������������: ������� ������. �� �� �������� ��� ��� ������?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "� ����� ����� �� ���� �� ����� ����, �������������� ���. ��� ��� ���� ������ � ��������������� �����������! �� ���������� ������ �������: ���, �� ��������. � ��� ����� ������ ������ �� ��������� ��������? �� ������� �� ��������, ��� � ������� ��� ��������?";
			link.l1 = "� ��� �� ������. ����� ������ ����� ��� ������ � ���������� � �����������, ������� ����, � ���� �������, ������ ������ �����. ���� ��������, �������. �����, ����� ������ ��������� �� ���, ��� ������ �� ���������...";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "�� ����� ����, ����� �� ��������� ����� ����� � ������� ��������, � ���� ���� ������ �����, � � �������� - ������� � ���� �� ������ ��������. � ������ ����. ������� ���������, � �� ��� ����� �������� ������. � �� ����� ������� �������� �� ����� ������������ ������ ����\n� ���� ���� �������������, ��� ��������� ������ ������ ���� ���������� ���-�� �� ��������. �� ���� ���������� �� ����� � ������� ���� �� ������������, �� ������ �� �����. ������������� �� �������, � ����� ������������ ������ �� �� ����� - ��� ����� �������.";
			link.l1 = "��. ������, ������ ��� ��������� ������ ������ � ������ ������������ ���-�� �� ��������... ��������. �� �� ����������� ������ ����� ������?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "����������, �� �� ������ ������� ��� � ����. ������ ����, ������ ������, ��� ������ �� ����������. ����� ������ �������� �� �������� - � ��� �������.";
			link.l1 = "�������. ������� �� ������� � �� ��, ��� ������� �����! �� ��������...";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			DialogExit();
			npchar.quest.utensil = "true";
			AddQuestRecord("Guardoftruth", "24");
			Island_SetReloadEnableGlobal("Dominica", true);//patch-7
			// ��������� ������
			pchar.GenQuestBox.Shore27 = true;
			pchar.GenQuestBox.Shore27.box1.money = 30000;
			pchar.GenQuestBox.Shore27.box1.items.gold_dublon = 100;
			pchar.GenQuestBox.Shore27.box1.items.chest = 1;
			pchar.GenQuestBox.Shore27.box1.items.icollection = 1;
			pchar.GenQuestBox.Shore27.box1.items.jewelry40 = 15;
			pchar.GenQuestBox.Shore27.box1.items.jewelry41 = 22;
			pchar.GenQuestBox.Shore27.box1.items.jewelry42 = 8;
			pchar.GenQuestBox.Shore27.box1.items.jewelry43 = 20;
			pchar.GenQuestBox.Shore27.box1.items.jewelry44 = 33;
			pchar.GenQuestBox.Shore27.box1.items.jewelry45 = 16;
			pchar.GenQuestBox.Shore27.box1.items.jewelry46 = 58;
			pchar.GenQuestBox.Shore27.box1.items.jewelry35 = 1; // ������
			pchar.quest.GuardOT_finddominicachest.win_condition.l1 = "item";
			pchar.quest.GuardOT_finddominicachest.win_condition.l1.item = "jewelry35";
			pchar.quest.GuardOT_finddominicachest.function = "GuardOT_DominicaChest";
		break;
		
		case "terrapin":
			dialog.text = "� �� ���� ���, �������! �� ��������� ��������, ������� ������ ���� ������� �� �������. � ������������� ��� ������ �����������, � ��� ������, � ��� ����. ������ ������ ��� ���� ��� ������ �� �����...";
			link.l1 = "� ���, ��� ��� ����������� ������. �������, �� ������ �������� ���� ������ � ��������.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "���� ��, ��� ����� ��� ���� ����� ����������� ����������, ��� ��, ���������� ������ ���� �������� ���������� ���������� ��� ���������� �������, � �� �������� ��������� ����� � ����, ������� ������������ ���������� � ���� ��������� � ����� ��������!";
			link.l1 = "������� ����, ��� � ��������, ���� ����� ����� ���������, ���������...";
			link.l1.go = "terrapin_2";
		break;
		
		case "terrapin_2":
			dialog.text = "� �� ��� ��������! ��� ���� �������, �������. ����������, ����� ���� ������ - ��������, �� �������� ���� ������� �� �������� � �����, ������� ������! �� ��������� ������, ������� � ������� � ���� ��� ��� ��� �� �� ���� ����������. ���, ����������\n��� ����������, ������������ �������� ��������, ��������� ��� �������� ����� �����. ��� ����� �������� ������������ ��������, ������� �������������� ������� ���� ����� ������� ������. ����� �� �������� ��������, � ������� ����������� ��������� ������������ ����� � �������. �������, �� ���.";
			link.l1 = "�������������, �������� ������� ��� �������!";
			link.l1.go = "terrapin_3";
		break;
		
		case "terrapin_3":
			Log_Info("�� �������� ����������");
			Log_Info("�� �������� 10 �����");
			Log_Info("�� �������� 10 ������ �������");
			Log_Info("�� �������� ���������� �� ������������ ��������� ������");
			Log_Info("�� �������� ���������� �� ������������ ������� ������");
			GiveItem2Character(pchar, "pistol8");
			TakeNItems(pchar, "harpoon", 10);
			TakeNItems(pchar, "GunEchin", 10);
			GiveItem2Character(pchar, "recipe_harpoon"); 
			GiveItem2Character(pchar, "recipe_GunEchin"); 
			PlaySound("interface\important_item.wav");
			dialog.text = "����� � ���� � �������� ��������� �������� ����������� � ��������� �� ������������ ������� � ����. ������, ����� �� �� ������ ����������� ��� ���� �� ������ �������!";
			link.l1 = "�������, ���������. �� ������ �������� � �� ��������, �� � ���� ������, �� ����, ����� �� �����: � ���������� ������ �� ��� ����������� �� �������� �� ����������� �� �� ����� ������. � ������ �� ��� �������� ����������� ������� �� ����������� ���� ��������.";
			link.l1.go = "terrapin_4";
		break;
		
		case "terrapin_4":
			dialog.text = "� ����, �������. � ��� ������ ��� ����� �������. ����� ���� ������ ��������� ����, � �� ��� �� ���-�� ������ ���������� ������������� �����������. ��� ��� ������� ������������� �� ��� � �� ���� �� �� ����������.";
			link.l1 = "� ��� ������� �� ��� �������, ���������. ��������� ������ ��� ������ � ��������� ������ ������ ������ ��������� ������ ����.";
			link.l1.go = "terrapin_5";
		break;
		
		case "terrapin_5":
			dialog.text = "����������� �������, �������! ����� �������!";
			link.l1 = "�� ��������, ���������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Terrapin_KathyReward");
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "fame", 5);
			ChangeCharacterNationReputation(pchar, ENGLAND, 20);
		break;
		
		// Addon-2016 Jason, ����������� ���������� (���) ����-���������
		case "FMQN":
			dialog.text = "� �������� ������. ���� �������� ������� ������ ������, � �� ������ �������� �������. ����� �������, ��� ���������� �������� ����� ���� ��������� �� ������������� ������, � ������� ������ - �� ����������� ���������� �������. ��� ���� ������ � ��������� ���������� ������ ����. ��������!";
			link.l1 = "�������, ���.";
			link.l1.go = "FMQN_1";
		break;
		
		case "FMQN_1":
			dialog.text = "���� �����, �������� �������� ��� ������ ����� � �������� ���������� ����������, ������� � ��� �����. ������� ��� ���� ������������� �� ��, ��� �� ������� ���� ����� � ������� ��!";
			link.l1 = "������ ���, ���������...";
			link.l1.go = "FMQN_2";
		break;
		
		case "FMQN_2":
			dialog.text = "� ������ ����� ���� �������� - ���� ����. ��������� �����, �������.";
			link.l1 = "�� ��������, ���.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_EnglandComplete");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}