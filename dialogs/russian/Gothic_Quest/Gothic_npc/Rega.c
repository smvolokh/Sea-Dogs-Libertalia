���� ���������� �� ����� ������
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
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����?";
		link.l1.go = "Rega_1";
		break;

		case "Rega_1":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_01.wav");
		dialog.text = "�� �� ������, ��...";
		link.l1 = "...";
		link.l1.go = "Rega_2";
		break;

		case "Rega_2":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_05.wav");
		dialog.text = "�� ���� ����� � �� ��������� �� ���� ���������.";
		link.l1 = "...";
		link.l1.go = "Rega_3";
		break;

		case "Rega_3":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_08.wav");
		dialog.text = "�� � ��������� ����� ����� ����� ����� ������ ����������.";
		link.l1 = "...";
		link.l1.go = "Rega_4";
		break;

		case "Rega_4":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_09.wav");
		dialog.text = "������� �� �����, ������� ������� ���������� ��� ������, � ���� ���� ������ �������.";
		link.l1 = "...";
		link.l1.go = "Rega_5";
		break;

		case "Rega_5":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� ������ ���� �����!";
		link.l1.go = "Rega_6";
		break;

		case "Rega_6":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_17_01.wav");
		dialog.text = "�������, ���� ���� ����� ���-�� �� ����������, �� �������� ����� �������� � ������ ����� �������� ����� �� �����.";
		link.l1 = "...";
		link.l1.go = "Rega_7";
		break;

		case "Rega_7":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_17_02.wav");
		dialog.text = "��� ���, �� ������������ �����������.";
		link.l1 = "...";
		link.l1.go = "Rega_8";
		break;

		case "Rega_8":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_PERMKAP1_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ���...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";
		break;
















		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������		
		case "Woman_FackYou":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_07.wav");
		dialog.text = "����� � ���� ����, ������� ���!";
		link.l1 = "��� ����!";
		link.l1.go = "exit_setOwner";
		LAi_group_Attack(NPChar, Pchar);
		break;

		case "fight":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		LAi_group_Attack(NPChar, Pchar);
		if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
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
