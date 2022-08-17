// ���� �������� �� ����� �������
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

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ����� - ������ ���������� �������?";
		link.l1.go = "First time1";
		break;

		case "First time1":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_05_01.wav");
		dialog.text = "� ���� ����������, ��� ����� ����, ��� ���, �� ���� ����, ��� ��� �����.";
		link.l1 = "...";
		link.l1.go = "First time2";
		break;

		case "First time2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_05_02.wav");
		dialog.text = "� ��� ��� � ����, ���� �� � ����� �������� ������.";
		link.l1 = "...";
		link.l1.go = "exit";

		break;

		case "Vino_hallo":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ��� ������?";
		link.l1.go = "Vino_hallo_1";			
		break;

		case "Vino_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_05_01.wav");
		dialog.text = "��� �� ��� � ������, ������ �����, ����� ����, � ���� ��� ������ �� ������ �� ������ ������ ���� � ������ ���� ����� �� ���.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_2";			
		break;

		case "Vino_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_05_02.wav");
		dialog.text = "����������� �������� ������ ���� �����, �� � ����� ���������� � ���, ��� ��� �������� ���� ������� � ������ ���� ���� ���� ������� �� ���.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_3";			
		break;

		case "Vino_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� � ��� - ������ ������, � ��� ������.";
		link.l1.go = "Vino_hallo_4";			
		break;

		case "Vino_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_01.wav");
		dialog.text = "�, �� ������, ��� - ������ ������ � ������� �������!";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_5";			
		break;

		case "Vino_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_02.wav");
		dialog.text = "...";
		link.l1 = "�, ��� ��� ������ ����� - ��.";
		link.l1.go = "Vino_hallo_6";			
		break;

		case "Vino_hallo_6":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_03.wav");
		dialog.text = "��, � ����� ������ �� � ���� ���������, �������.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_7";			
		break;

		case "Vino_hallo_7":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_04.wav");
		dialog.text = "�� ���� �� ������ �������� �� ������� � �������� �������� ��������, � ���� ������ ������������ ���� �� ������ ����� � ���� ���� ����� �����.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_8";			
		break;

		case "Vino_hallo_8":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_05.wav");
		dialog.text = "...";
		link.l1 = "�� ��������� ������ � ���� ������ ������ �������, ���� � ���� �������� �� �����.";
		link.l1.go = "Vino_hallo_9";			
		break;

		case "Vino_hallo_9":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_06.wav");
		dialog.text = "��, � ���� ��� ��� ���� ������� ������, �� �� ������ �������� ��� � ������, ��� - ������ ������.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_10";			
		break;

		case "Vino_hallo_10":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_07.wav");
		dialog.text = "������� ��� ������� ���� � � ����� �������, ��� �� ����� ����� ���.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_exit";			
		break;

		case "Vino_hallo_11":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_08.wav");
		dialog.text = "�� �� �� ������ ����� �� ����, �������.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_exit";			
		break;

		case "Vino_hallo_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicVino_seekwork");
		break;

		case "Vino_bringwine":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ��� ����.";
		link.l1.go = "Vino_bringwine_1";			
		break;

		case "Vino_bringwine_1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "Grog", -1);
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_05_01.wav");
		dialog.text = "� ������� �� ���� ���������� ��� �� ���� ��� ������, ���� ��� �������...";
		link.l1 = "...";
		link.l1.go = "Vino_bringwine_2";			
		break;

		case "Vino_bringwine_2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_05_03.wav");
		dialog.text = "������ ������� ������ ������� � ����.";
		link.l1 = "...";
		link.l1.go = "exit";
                                         pchar.questTemp.GothicVino = "Vino.Fail";			
		break;











//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//��������� �� ����������� ������
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("������, �� �� ����� ������. � �� ���������� �������...", "������, � ��� ��� �� ������� ��������� �����������. ����� ������.", "������, ��� ��, ��� �'��������, ������� ���, ������ ������? ����� ������, �� � ���� ��� ���������� �������...");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "���������� �� ���������, ��������, ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� ������� ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����.", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- ����������� �������	

	}
}
