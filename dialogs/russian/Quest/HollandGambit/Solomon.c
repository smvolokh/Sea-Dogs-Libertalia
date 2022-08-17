// ������� ����� - ������ �����
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
//--------------------------------------�� ���������------------------------------------------------
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbyFather")
				{
					dialog.text = "������� �������, �� ��� �� ������ �� ������� ������� �����?";
					link.l1 = "�������, � ����, ����� �� ����������� ���������, ��� ��� �� ������, �� ������� �� �������� ���� ����������. � ������� � ����� �������. ��� �������� - ����� ��������� - ���� ��� ������ ������� �������� �� ����� ����� �����. � ������ ����� ������ ��� ���, ��� � ����� - ������� �������� �������. �� ��� ����� ������ ��� ����� ������ ��� �������...";
					link.l1.go = "SolomonBonanza";
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "AbbyFindScull" && makeint(Pchar.money) >= 200000)
				{
					dialog.text = "��, ��� ����� ��, ������� �������? ���������� ��� ���-������ �������? ��� ����� ������ ������ ������� ������� ����� ���������?";
					if (CheckCharacterItem(pchar, "SkullAztec"))
					{
						link.l1 = "� ����� ������, ���� ��� ���� ���������� ������� �������. ������� � ����� � ��� ������ � ��������, � ��� ���� �������� � ���� ������. ��� � �����, ��� � ���� ��� ����� ����, ��� ������� �� ��������.";
						link.l1.go = "SolomonBonanza_2";
					}
					link.l2 = "� ����� ������, ���� ��� ���� ���������� ������� �������. ������� � ����� � ��� ������ � ��������. � ��� ������� ������� � ������ �� ���������.";
					link.l2.go = "SolomonBonanza_3";
					link.l3 = "�� ���, ���� ������ �� �������� � �������� �������� ���� �� ����.";
					link.l3.go = "exit";
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "GiveLucasMoney" && GetQuestPastDayParam("questTemp.HWIC.Holl.LucasMoney") > 7)
				{
					dialog.text = "��, ��� ����� ��, ������� �������? ���������� ��� ���-������ �������? ��� ����� ������ ������ ������� ������� ����� ���������?";
					link.l1 = "� ����� ������, ���� ��� ���� ���������� ������� �������. ������� � ����� � ���� ������. ���, ��������, ����������.";
					link.l1.go = "SolomonBonanza_5";
					break;
				}
				dialog.text = "������������, ������� �������. �� ��� �� ������ �� ������� ������� �����?";
				link.l1 = "������ ����. �� ���, ������, ������ ������������� �����.";
				link.l1.go = "exit";
				break;
			}
//----------------------------------------�� ������-----------------------------------------------
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				if (pchar.questTemp.HWIC.Eng == "toAbigile")
				{
					dialog.text = "���� ������, ������� �������. � ����, ��� �� ������ ���������... ��� ���-�� ����? � ���-�� ���� � ����� �����, ��� � ���-�� ����� �� �����?";
					link.l1 = "������ ����. ��� ����� ���������� � ��������.";
					link.l1.go = "Solomon_treasure";
					break;
				}
				dialog.text = "������������, ������� �������. �� ��� �� ������ �� ������� ������� �����?";
				link.l1 = "������ ����. �� ���, ������, ������ ������������� �����.";
				link.l1.go = "exit";
				break;
			}
//-----------------------------------------������ ����-------------------------------------------------
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "toVillemstad")
				{
					dialog.text = "���� ������, ������� �������. � ����, ��� �� ������ ���������... ��� ���-�� ����? � ���-�� ���� � ����� �����, ��� � ���-�� ����� �� �����?";
					link.l1 = "��� ����� ���������� � ��������. � ���� ��� ��� ������.";
					link.l1.go = "Abigile_kidnap";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileNextDayOver")
				{
					dialog.text = "���� ������, ������� �������. ��� ��� �����? ��� ���� ������ ��� ���� ������?";
					link.l1 = "��... ���. � ��� ��������?";
					link.l1.go = "Abigile_GoOver";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistory")
				{
					dialog.text = "���... ������� �������! �� ������, �������, ������ ���� � ���� �������?";
					link.l1 = "��, ������. � �������, ������� �� �������� �� ����� �������, � ������� �� ��, �� �������� ���� �� ������� - �� ��� ��, �� ����� ��.";
					link.l1.go = "Solomon_history";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistoryAfter")
				{
					dialog.text = "������. � ������������� ����� � ���� �����, � ��� ��������. � ���� ���-�� ����� ��� � ����� ������ ������. ����� ���������� '������', �������� �����... �������, ���� ������.";
					link.l1 = "�������! ������� ����, ������ ������� - �������� ����� ��������.";
					link.l1.go = "Solomon_history_3";
					pchar.questTemp.HWIC.Self = "SolomonHistoryEnd";
					break;
				}
				dialog.text = "�� ��� �� ����� ������ �� ������� ������� �����?";
				link.l1 = "������ ����. �� ���, ������, ������ ������������� �����.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "������������, ������� �������. �� ��� �� ������ �� ������� ������� �����?";
			link.l1 = "������ ����. �� ���, ������, ������ ������������� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

//-----------------------------------------------�� ���������-----------------------------------
		case "SolomonBonanza":
			PlaySound("VOICE\Russian\hambit\Solomon Shneur-03.wav");
			dialog.text = "� ��� �� ��-��� ���� ������? ����� � ����� �� ��������, ������� ����� ������, ��� �� ����� ����? ����� � ��� �������� � ��� �������� ��� ���� ����, ��� � ������ ����� ����� ���� ���� ���� ������� � ������������? ��� ��� ��� �������� ��, ��� ����� �������� ����� ������� �����?\n������ ��� ������, �� ������ ���� � ���, �� ������ ���������� ��������. �� ���� ������ ������. ��������� ����. ��� � ��� � ���� ������ �������, ����� �� �� �������� ����� �������. � � ������� ��� ���, ��� ������ ������������ �������. � ���� �������� �������� � ����������� ����� ����... �� ��� ������ �� ��������, �� �������� �� ������������� ��������� ���\n�-�-�, ��� ������� ������. ���� � �� ���! ��� ������ �� ������ ��� �������� ��� �������! ���� � �� �����, ������� �������! ���� � � ������ ����� ���� �� ��������� ��� �����������!";
			link.l1 = "��... �����. ��� � �����, ��������, ��� � ��� ����, � �� ��� �� �������. �������� ����������� ������. �� ��������!";
			link.l1.go = "SolomonBonanza_1";
		break;
		
		case "SolomonBonanza_1":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "AbbySeekIsland";
			pchar.quest.Joakim_meeteng.win_condition.l1 = "location";
			pchar.quest.Joakim_meeteng.win_condition.l1.location = "Villemstad_town";
			pchar.quest.Joakim_meeteng.function = "Create_Joakim";
		break;
		
		case "SolomonBonanza_2"://������ ��
			dialog.text = "�, ������� �������, �������� ��� �������! �� �� ������ ������� ������ - �� ������������ ������ ��� ����� �������! ������ ��������� �� ����� ����� ���������, ��� � ���� �� ������ ����� ��������, ��� ��. ����� � ������� ������� ���������� - �� ������ ��������� �� ���� ��������� �����... � ��� � ���� ����� ������������� - ������� �� ������ ���� ������.";
			link.l1 = "� ��� �� ���. ������� ��� �� �������!";
			link.l1.go = "SolomonBonanza_4";
			RemoveItems(PChar, "SkullAztec", 1);
			AddMoneyToCharacter(pchar, -200000);
			GiveItem2Character(pchar, "amulet_7"); 
			AddDialogExitQuestFunction("DeleteJoakimFromRoom");
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			SetFunctionTimerCondition("Caleuche_StartTotal", 0, 0, 30, false); // ������ �� �������
		break;
		
		case "SolomonBonanza_3":
			dialog.text = "�, ������� �������, �������� ��� �������! �� �� ������ ������� ������ - �� ������������ ������ ��� ����� �������! � �����... �� � ��� � ���! ����� �� ����� ����� ���������, ��� � ���� �� ������ ����� ��������, ��� ��. � ���� ��� ������������� - ������� �� ������ ���� ������.";
			link.l1 = "� ��� �� ���. ������� ��� �� �������!";
			link.l1.go = "SolomonBonanza_4";
			AddMoneyToCharacter(pchar, -200000);
			GiveItem2Character(pchar, "obereg_10");
			pchar.questTemp.HWIC.Holl.ScullnotReturn = "true";//������� ��� ������
			ChangeCharacterComplexReputation(pchar, "nobility", -8);
		break;
		
		case "SolomonBonanza_4":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "AbbyLeavesMarried";//������ ����� �������� � ���
			AddQuestRecord("Holl_Gambit", "1-32");
		break;
		
		case "SolomonBonanza_5":
			dialog.text = "�� �� ���? ��� �� ����� ��������, ������� �������? ��� ������? ��-��, ����� ��� �� ��� ���������...";
			link.l1 = "����������. ��� ���� ������. ��� ����� ����������� ��� � ��������. ������, �������� ������ ������ ���� � �� �����.";
			link.l1.go = "SolomonBonanza_6";
		break;
		
		case "SolomonBonanza_6":
			AddMoneyToCharacter(pchar, -200000);
			GiveItem2Character(pchar, "amulet_7"); 
			dialog.text = "��, �������... ��-��, �������-�������... �� ��� ������ ������ �� ������... �� ����� �������, �� ������ ��, ������� �������? �� ���������, � ����, ��� ������... ������� ��� �������, ��� ������� ��� ����������. � ���� ��� ������������� - ������� ���� ������. � �����, ��������� ���!";
			link.l1 = "�������, �������.";
			link.l1.go = "SolomonBonanza_4";
			pchar.questTemp.HWIC.Holl.LucasMoney = "true";//������� ��� ������
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
		break;

//-------------------------------------------�� ������------------------------------------------------
		
		case "Solomon_treasure":
			dialog.text = "��, � ��� ������! ������ ��������� ��� ���� ����� ��� ����. ���� �� ����, ��� �� ��� ��������! ����� ��� ��������� ������ � ���� �������� ��� ������� ���������!";
			link.l1 = "�� ��� �� �����, ���� ������?!";
			link.l1.go = "Solomon_treasure_1";
		break;
		
		case "Solomon_treasure_1":
			dialog.text = "�������� ����, �������, � �� ������ ���� �������. �������� ��� �������, ������� ��� ��� ������ � ����� �� ����. ������ �����, �������, �� ����� �����, ��� ��, �� ���� �� ��������, ��� �� ����-�� ������ �� ��� ������\n��������, ��� ��� ���-�� ������, �, ���� ��� ��� �������, �� �������� � �����, �� � ����� ��� ��� � ������ ����, � ����� ��� ������ �� ������� ���� ���������. � ������ �� ��� ����, ��� ������� � ��� ����� ������� ���� �� ����� ���������, �������� ���.";
			link.l1 = "��, �������! � ��� ������ ����� ����� �����... ������, ������ ������.";
			link.l1.go = "Solomon_treasure_2";
		break;
		
		case "Solomon_treasure_2":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "2-17");
			pchar.questTemp.HWIC.Eng = "AbigileInChurch";
			sld = characterFromId("Abigile");
			sld.greeting = "abigile_3";
			ChangeCharacterAddressGroup(sld, "Villemstad_church", "goto", "goto1");//��� � �������
		break;
		
//----------------------------------------------������ ����---------------------------------------------	
		
		case "Abigile_kidnap":
			dialog.text = "������? ��, � ��� ������! ������ ��������� ��� ���� ����� ��� ����. ���� �� ����, ��� � �� ���� � ��������!";
			link.l1 = "����������, ��� ��� �����, ��� ��� ����. ��� ����� �������� ��� ������ ��������. �� � ����� ������ �������, ��� ��� �� �����? � ������, ��� ��?";
			link.l1.go = "Abigile_kidnap_1";
		break;
		
		case "Abigile_kidnap_1":
			dialog.text = "��� �? � �� ������ ���� �������... � ��� �� ��� ���-�� �� ���������, ������� �������.";
			link.l1 = "��, ������, � �� �������������, ���� �� �� ����� �������, ��� � ��� ��������... �� ���������� � ������ ����� ������, ��� ���-���� �������� ��������? �������� ��� ���: � ��������, � ������ ������ ��� ����� ������!";
			link.l1.go = "Abigile_kidnap_2";
		break;
		
		case "Abigile_kidnap_2":
			dialog.text = "������� ������ ���. � ������� ��� �����.";
			link.l1 = "�������, �� � ���� ������ ������� ��� �������� ������ �� ����� � ����. ��� ���� � ���� ������� ������ �� ����. ��� ��� � �������� ��������� ������ - ��� � ���� ����� ��������?";
			link.l1.go = "Abigile_kidnap_3";
		break;
		
		case "Abigile_kidnap_3":
			dialog.text = "������� �������, ����� ��� ��������� ������, � ���� �������� ��� ������� ���������, ���� �� ������ ����� ��������...";
			link.l1 = "�, �������! � ���? � ������� �����? �� ������ ������, ������!";
			link.l1.go = "Abigile_kidnap_4";
		break;
		
		case "Abigile_kidnap_4":
			DialogExit();
			sld = characterFromId("Abigile");
			ChangeCharacterAddressGroup(sld, "Villemstad_houseSP2", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Abigile_GoOver":
			dialog.text = "�� �����������? ����� ��������� �� ������������ ��� ������ �������... ��� ������ ����������� � �����... ���������, ����� �����������! ������ ��� � ������� �� �������� �����. ��, ��� �� ������ ������ ������� �����! �������� �������, ������� �������, �������� ��� ���!";
			link.l1 = "��� ��� ��... �� ���������, ������...";
			link.l1.go = "Abigile_GoOver_1";
		break;
		
		case "Abigile_GoOver_1":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-69");
			CloseQuestHeader("Holl_Gambit");
			pchar.questTemp.HWIC.Self = "end";
			pchar.questTemp.HWIC.Detector = "self_fail";
		break;
		
		case "Solomon_history":
			PlaySound("VOICE\Russian\hambit\Solomon Shneur-03.wav");
			dialog.text = "����� ��? ������ ��� ������, �� ������ ���� � ���, �� ������ ���������� ��������. �� ���� ������ ������. ��������� ����. ��� � ��� � ���� ������ �������, ����� �� �� �������� ����� �������. � � ������� ��� ���, ��� ������ ������������ �������...";
			link.l1 = "�������, �������, ����� �� �������, ��� ��������� ��� �����, � ������� ���������� ���� ����, � ��� ����� ��������?";
			link.l1.go = "Solomon_history_1";
		break;
		
		case "Solomon_history_1":
			dialog.text = "��-�... ��, �� ����. � ��, ������� �������, ����� ��� ��� ��� ����?";
			link.l1 = "� ������ ���� ������ ����� ������, �������. � ������ �� ������, �� ���� ���� �� �����������. ����� ����, ��� � ��� �������� ��� ������ ��������, ���� �� �������, � ������ ����... ��������� ���� ���-��, ���� ����������, ������� ��������� ���������� � ������������ �� ���������� �����.";
			link.l1.go = "Solomon_history_2";
		break;
		
		case "Solomon_history_2":
			dialog.text = "��, ���� ���...";
			link.l1 = "";
			link.l1.go = "Solomon_history_3";
			pchar.questTemp.HWIC.Self = "SolomonHistoryNext";
		break;
		
		case "Solomon_history_3":
			DialogExit();
			sld = characterFromId("Abigile");
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Solomon_thanks":
			dialog.text = "������� �������! ��������!";
			link.l1 = "��, �������?";
			link.l1.go = "Solomon_thanks_1";
		break;
		
		case "Solomon_thanks_1":
			dialog.text = "������� �������! � ���� ������������� ��� �� ��, ��� �� ������� ��� ���� � ���� �����. �� ������ ������ ���. �������� �� ��, ��� � ������ ��� � ������ ���, � �� ��, ��� ���������� � ����� ������� ������. �������� ������� �����... �, �������: ����� �����, �� ������ � ����� �� ��������?";
			link.l1 = "���, �������. ����� ����� ������ �� ����. ����� � ����� ��� �������� ��������� ��� � ������������ ��� ����� - ������, ������� ������� ��� �������. �����, �� ���-�� ������� ��������... � ��� ��� ������ ���� ����?";
			link.l1.go = "Solomon_thanks_2";
		break;
		
		case "Solomon_thanks_2":
			dialog.text = "��... �������. ���� ������� ��������. �� � ��� � ���, � ���� ���������! ������� �������! ��� ����� ��������...";
			link.l1 = "��?";
			link.l1.go = "Solomon_thanks_3";
		break;
		
		case "Solomon_thanks_3":
			dialog.text = "��... ���... ��, � ����� ������� ��� ���. �� � ������� ������ � ������ �����������, �� � ������, ������ �������. ����� �� ������� - �� ��������� ���� �����. ��� ���� ��� ��� �������. �����... ��, �� ���������? ��� ����� ������� �������, ������ ���.";
			link.l1 = "��, �������... �� ��� ��� ������. ��, ���� ����� - ������ ���������. �������� ��.";
			link.l1.go = "Solomon_thanks_4";
		break;
		
		case "Solomon_thanks_4":
			dialog.text = "�� ���������, ������� �������! ��������� � �������������!";
			link.l1 = "�� ��������, �������.";
			link.l1.go = "Solomon_thanks_5";
		break;
		
		case "Solomon_thanks_5":
			DialogExit();
			LocatorReloadEnterDisable("Villemstad_houseSp2", "reload1", false);
			AddQuestRecord("Holl_Gambit", "3-65");
			NextDiag.CurrentNode = "First time";
		break;
		
		case "Solomon_poor":
			dialog.text = "�-��... ������, ������� �������, ���������� ������ ����� �������... �������� �������� � ������ - ��� ����� ���� ����?";
			link.l1 = "��� ����, �������. ���������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Solomon_poor";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> ���� ������������ �� ������� ������� � ������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- ���� ������������ �� ������� ������� � ������
	}
}