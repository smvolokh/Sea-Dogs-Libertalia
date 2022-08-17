��������� ������ �� ����� ������
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
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����?";
		link.l1.go = "Balthasar_1";
		break;

		case "Balthasar_1":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_01.wav");
		dialog.text = "�, ����� ���� �� �����, ������� ���� ������ ������ ������� ������� ��� �������.";
		link.l1 = "...";
		link.l1.go = "Balthasar_2";
		break;

		case "Balthasar_2":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "� �� ������...";
		link.l1.go = "Balthasar_3";
		break;

		case "Balthasar_3":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_03.wav");
		dialog.text = "�, �������, �� � ���� ��� �� ��� �����, ��� ������, ���������, � � ��� ����� ��� ��� ���� ������.";
		link.l1 = "...";
		link.l1.go = "Balthasar_4";
		break;

		case "Balthasar_4":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_04.wav");
		dialog.text = "�� �� ����� �� ������, ��� ���� ������� ������������ ������, ������!";
		link.l1 = "...";
		link.l1.go = "Balthasar_5";
		break;

		case "Balthasar_5":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_15_00.wav");
		dialog.text = "...";
		link.l1 = "�, ��� �� �������� � ��������?";
		link.l1.go = "Balthasar_6";
		break;

		case "Balthasar_6":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_01.wav");
		dialog.text = "����� � ���� ����� �������� ���� ������ � �������� � ������� � ����� ���� ���� �� ������ ��������� ������ ����.";
		link.l1 = "...";
		link.l1.go = "Balthasar_7";
		break;

		case "Balthasar_7":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_02.wav");
		dialog.text = "���� ���� �� ���������, �� ������� ������ ��������� ������������� ���������� ������ ��� ��� ��� �������� ����� ����� ���� ���� ���.";
		link.l1 = "...";
		link.l1.go = "Balthasar_8";
		break;

		case "Balthasar_8":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_03.wav");
		dialog.text = "�� �������, ��� ����� ������ ������� ���� ����� ����� ���� �� ��� ���������.";
		link.l1 = "...";
		link.l1.go = "Balthasar_9";
		break;

		case "Balthasar_9":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_04.wav");
		dialog.text = "�� ����� ������ �������� ��� �������� ���� ���� �� ���, ������� � ������ �� ���� �� �����.";
		link.l1 = "...";
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
