// ������� �������, ������ � ������ �������� ���
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ���-��������
		case "itza_ctz":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = LinkRandPhrase("��� ���� �����������... ������� ���� ���� ��� �������� ���� ������...","����������� �����, ��� ������ � ��������, �� �� ���� �� ����� ��� �����!","� �������, �����������: �� ��� �� ���� � ������ ����... ������, ���� ��� ����, ����� �� ������� ���� ������.");
			link.l1 = LinkRandPhrase("��-��, ���������...","�� ����� ����, ����������� ����. � �� ����� ������.","���-���. ����� ����� �������� ������.");
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz";
		break;
		
		case "itza_ctz_1":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = LinkRandPhrase("������������ ���� �� ��� � �����, ������� ������!","������� ������ � ������� ��������� ������� ��� ���� �����������. ������ �� ���� ���� � ������� ����!","�� �������� ������� � ������� ����� ��������� � ������ ���� �������!");
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz_1";
		break;
		
		// ������ - ����� ���
		case "urakan":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "�� ���� ������� ����, �����������. �� �������� ���� ����� �����, �� ������� � �������.";
			link.l1 = "�������, ����������� ����. � �� ������� ��������� ������ ������ �������� ���� � ������ ����������, ��� ����-�� ���. ���� ����� �� ������ �������� ����, � ��� ������� � ���.";
			link.l1.go = "urakan_1";
		break;
		
		case "urakan_1":
			dialog.text = "��, �� ������� ����, �����������. �� �� �� ������� ����� ������ ���� ��� �� ��������. ������ �� ������� ���������� �����. ������ �� ����� ��� ������� ����� � ���������?";
			link.l1 = "�������� �������... ��� �� �� ����� - �� ����, ��������, ����� ������, � �� ��� ����� ������?";
			link.l1.go = "urakan_2";
		break;
		
		case "urakan_2":
			dialog.text = "���� ���� ������� ������, �����������. � ���� ������, � � �������...";
			link.l1 = "������ �� ��������� ��� ������, ����� ��������� �� ���... ������.";
			link.l1.go = "urakan_3";
		break;
		
		case "urakan_3":
			dialog.text = "�, ����! ���� � ����������� ���� ���� �����, ������, ����� ������... �� � ���� ���, � ��� ������� ���������. �� �������� �������� ���� � ����, ��� ������ �� ��������� � ��������. �� �����, ��� �� ������.";
			link.l1 = "���������?! �� ���, � ��������?";
			link.l1.go = "urakan_4";
		break;
		
		case "urakan_4":
			dialog.text = "��, ����� ����. ������������� ������ �������. ����� �� ����������� ����� ���� ���� ������, ������� ����� ����.";
			link.l1 = "���� ������! ������, �� ��� �����... (������� �����) ������, � ���� ���. � ����, ��� ��� �� �������� ����� �� �� ������� ������ �� ������ ��������� � ����� ����������. � ����, ��� �� �� ������ �������, ������� ����� � ����� ���������� ����������...";
			link.l1.go = "urakan_5";
		break;
		
		case "urakan_5":
			dialog.text = "";
			link.l1 = "� ���� � ����� ������ ��������� � ��������, ������� ����� ������... �� ���� �� ��� ����������, � �� ����?";
			link.l1.go = "urakan_6";
		break;
		
		case "urakan_6":
			dialog.text = "������ ���� ��� ��� ������� ������� ���������, ����� ����. �� ������ ��������� ����� ���������. �� ����� ���� ��� ����� �����. �� ������� ������, �� ��� ����� �������. ���� � �������� ����, ������ ������ � ���� ���. �� �� ��������� ���� ���� �� ��������.";
			link.l1 = "������� �� �� ���������, ��� ��� ������ ��������� ����� ����� ����� ������, �� ���, � �� ����� - ����������� ������������? � ����� ������, ��� ����� ���� - �� ������������ � ������ ������, ������ ����... �����, ������� ������. � �����, �������, ��� ������...";
			link.l1.go = "urakan_7";
		break;
		
		case "urakan_7":
			dialog.text = "�������, ����������� ����. �� ����� ��������� � ������� ���� ������� ���. ���� �� ����� �����, ���� �� ������� ������� ��������. ����� � ������ ����� ���� � ������� ���������.";
			link.l1 = "������. � ����� � ����������, ��� ����, ��� ��� �� �������� ���� �������. �� � ���� �����������.";
			link.l1.go = "urakan_8";
		break;
		
		case "urakan_8":
			DialogExit();
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(npchar);
			LAi_warrior_SetStay(npchar, true);
			LAi_warrior_DialogEnable(npchar, true);
			NextDiag.CurrentNode = "urakan_9";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			AddQuestRecord("Tieyasal", "25");
			pchar.quest.Tieyasal_Templegreat.win_condition.l1 = "location";
			pchar.quest.Tieyasal_Templegreat.win_condition.l1.location = "Temple_great";
			pchar.quest.Tieyasal_Templegreat.function = "Tieyasal_InGreatTemple";
			// ����� �� ���
			AddComplexSelfExpToScill(300, 300, 300, 300);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			AddCharacterExpToSkill(pchar, "Fortune", 300);
		break;
		
		case "urakan_9":
			dialog.text = "����, ����� ����. ��������� ����� ����.";
			link.l1 = "���-���...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_9";
		break;
		
		case "urakan_10":
			PlaySound("VOICE\Russian\Complete.wav");
			dialog.text = "����������! ��� ������ � �������, ��� �� ��������� � ���������, � ����� ������: �� - ��� ������, � �� ������ ��������, ���� ������ ����� ��� �� ������ �� �������� ��� ���� � ���������. ��� ����, ������� ���� �����, ������ ����� ��� �� ������ �� ����� ����� ������� ������ ����\n�, ����� ������, �������� ����� ��� ����� ���. �� ���� ����������� �� �������� ��������. � � ��� ����� ���������� ������ � ����� ������ ��� �� ������-������ ��� ������. � �� ������ ��������� ������ ���� ��� ����.";
			link.l1 = "� ���� ���, ������. � � ������� ���� �� �����.";
			link.l1.go = "urakan_11";
		break;
		
		case "urakan_11":
			dialog.text = "�� ���� ������� ������ �� �������� �����. �������� ������, ��� ����� �� ������, ��� ���� ��.";
			link.l1 = "������� ���, �����. �������� ���������� ���������� ��������� ����, �� ����� ���� ����� ������ ������ ������ - ������� ����� � �������. ��� �������������� ���� �� ������� ������ ���� ����������. �� �������� ���?";
			link.l1.go = "urakan_12";
		break;
		
		case "urakan_12":
			dialog.text = "��� ������ ������ ����, � ������?";
			link.l1 = "�� �������� ����� �� �� ������� ������ �� ������ ��������� � ����� ����������. ������, �� ����, ��� � �� ������� ���������� ����� ������. ���� ������� ���� �� ����?";
			link.l1.go = "urakan_13";
		break;
		
		case "urakan_13":
			dialog.text = "���� �� ��������. � ��� ������� �������� � ����� ������ � ��������. �� ������ ���� ������� ������. �����, ������ ������ ������?";
			link.l1 = "��� ������ �� �������?";
			link.l1.go = "urakan_14";
		break;
		
		case "urakan_14":
			dialog.text = "� ������� ��� ��������. �������� �������: '����� ������ ������ �������� �����, � ����� ����� ��� � �����������, ������� ����� ���� �� ���� � ���������� ����� ����� ��������� �� ������ ������. � ���������� ����� ������ ����� ����� �� ��������� ���.'";
			link.l1 = "������ ������ - ��� �� ����� ����� �����, ��� ������� ���������? ��� � ���������� � �����������?";
			link.l1.go = "urakan_15";
		break;
		
		case "urakan_15":
			dialog.text = "��.";
			link.l1 = "���-���... �����. ������ ���, ��� ��������� ����� �������.";
			link.l1.go = "urakan_16";
		break;
		
		case "urakan_16":
			dialog.text = "��� ���������� ���� ����������. �� ����� ���� �������. �� �������� � �������� ������ ��� ����. ����� �� ��������� ����� ���� ���������, �� ��������: '������ ��������� � �������, ���� ��������� � �������, ����� ���������� � �������, ����� � ��� ������� ���� ����, �� ������ ���� ���� ������. ���� ����� - ������ ����.'";
			link.l1 = "�������... �������� � ����� �����������...";
			link.l1.go = "urakan_17";
		break;
		
		case "urakan_17":
			dialog.text = "� ���� ���, �����, � ������ ������. ���� � ���� ���� ������� - ������ ��.";
			link.l1 = "���� ��������� ������� - ����������� ��������.";
			link.l1.go = "urakan_18";
		break;
		
		case "urakan_18":
			DialogExit();
			NextDiag.CurrentNode = "urakan_adv";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1 = "location";
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1.location = "Tenochtitlan";
			pchar.quest.Tieyasal_UrakanTemple.function = "Tieyasal_UrakanInTemple";
			AddQuestRecord("Tieyasal", "26");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "quest", "urakan", "", -1);
			// ����� �� ���
			AddComplexSelfExpToScill(1000, 1000, 1000, 1000);
			AddCharacterExpToSkill(pchar, "Leadership", 3000);
			AddCharacterExpToSkill(pchar, "Fortune", 1500);
		break;
		
		case "urakan_adv":
			dialog.text = "������ ���� ���-�� ������ ������� ������ ����� ��� ��������?";
			if (Tieyasal_CheckTablets() && !CheckAttribute(npchar, "quest.tablets"))
			{
				link.l1 = "������� ��� �� ��� ��������, ������� ��� ������� ��������. ���� �� �����, ������ � �� ����, ��� ����� ��������� � ������ ����, � ��� ���� �� ������� �������...";
				link.l1.go = "tablets";
			}
			if (CheckAttribute(npchar, "quest.treasureentrance"))
			{
				link.l1 = "� ����� �� ������� �������� ����� ��� ���� ����, �� �� ������. ��� ��� ������� ����? ��������, ��� ����� ��, ��� � ���.";
				link.l1.go = "treasure";
			}
			link.l9 = "���� �����, ������. ���������� ���...";
			link.l9.go = "exit";
			NextDiag.TempNode = "urakan_adv";
		break;
		
		case "tablets":
			dialog.text = "��� �������� �������� ����. � ��� ���� ���� �� ��������� ������ ����, � �� ����� �������� ���. ������� ��������� �������� ������������ ��� �������� ��� �������� ������ ������� ��������, �������� � �������� �����, � ���� ��� ���������� ���������� �������\n��� ��������, ���� �� ��������� � ������������ ����� - ��� ������ ��� ����. �� �, ��� � �� - ����, � �� ����, � �� �����, ��� ��������� �� ���������. �����, ������ ������ ��������� ���?";
			link.l1 = "����������� ���������...";
			link.l1.go = "exit";
			npchar.quest.tablets = "true";
			NextDiag.TempNode = "urakan_adv";
			AddQuestRecord("Tieyasal", "31");
		break;
		
		case "treasure":
			dialog.text = "��� ����� � ������������ ��������. ��� ������ ��������� ������� ���. ����� ���� ��������� � ��������� ������ ��� ����, ����� �� ����� ������� ������������ ��� ��, ���� �.";
			link.l1 = "����� ������� ���� ���� ������� ���� ����?";
			link.l1.go = "treasure_1";
		break;
		
		case "treasure_1":
			dialog.text = "��� ���� ��������: '� ����� ��������� ���� ��� �������. � ��������� �������� ������ ���� ���, ��� ����� �� ��� ��� �������.' ��� ��� �������� - � �� �����. �����, ������ ������ ���������?";
			link.l1 = "��������� � ���...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_adv";
			DeleteAttribute(npchar, "quest.treasureentrance");
			AddQuestRecord("Tieyasal", "32");
		break;
		
		case "urakan_19":
			PlaySound("VOICE\Russian\Complete.wav");
			dialog.text = "�� ������� ���, � ������� ������! ����� ��� ������ ������������. �, ������, ��� ������, �������� ����, ��� � �� ��������� ��������� ��� �����, � ���� ������ �������� �������� �� ����� ��������� ������ �����������.";
			link.l1 = "������ � ��� ����, �����. �� ��� ��, ����� �����������: �������� ����� ���������� ����������. ����� �� �� ������ ����������� ��������� �� �������.";
			link.l1.go = "urakan_20";
		break;
		
		case "urakan_20":
			PlaySound("interface\abordage_wining.wav");
			dialog.text = "����� ������� ������! ��� � ��� ��������� ������� ������� ����� ������ �������� ���� �����. �� �������� �� ��� ������� ��� ���� �������. ��� ����� � ����� ����� � ��������! ����� ������! �����!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Tieyasal_Win_IndianBead");
		break;
		
		// ����� - ���� ���
		case "kanek":
			dialog.text = "�� ������ ����� �������� ����, �����������. ��� ������� ���������, ����������� � ������������ �����. ���� ����� ������� � �����, ����� �������. �� ������ ����� �����, ����� ������� ����. �� ���������� ���� ������ � �� ��������� ����� ������ ��� ���. �������� ������ ����. �, ���� �����, �������� �������� ������!";
			link.l1 = "��� ��� ��...";
			link.l1.go = "kanek_1";
		break;
		
		case "kanek_1":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_3";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.7);
		break;
		
		case "kanek_2":
			dialog.text = "������, �� ������, ��� ������ ��� ����������. ���������� ���������!";
			link.l1 = "����� ����� ����� ��������� �������, ���, ������� ��������, ����� ��������� � ������� � ��������� �� ��� �������, ����...";
			link.l1.go = "kanek_3";
		break;
		
		case "kanek_3":
			dialog.text = "���?! ��������, ���!";
			link.l1 = "���� ������� - �������� ���������� � ������� ����. � ���� � ��� ���������� ������ ������! �����, ����� ����, �� ��� �� ��� ������������� ����. �� ���������� � ������� �����, ����! � ���� �� ��������� ������ ����������, �� ��� ����� ������ ���� ����� ������!";
			link.l1.go = "kanek_4";
		break;
		
		case "kanek_4":
			dialog.text = "�� � ����� ���, ������?";
			link.l1 = "������ ���� �, ��������� � ����� ��������, ������ ������ ������� ������� ���� ����� �� ��������� ����������. ����� �� ���� ��� ������ ��������, �� ���� �� ���� �� ��������. �� �� ��� ���� ����� � �� ����� ����� ����� ������� � ��������, ������ ���� �����������. ���� �� ����� �������� ����������, �� � ��� �������� ��� ������ ������!";
			link.l1.go = "kanek_5";
		break;
		
		case "kanek_5":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_win_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}