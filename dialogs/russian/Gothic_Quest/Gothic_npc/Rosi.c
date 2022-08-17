//����, ���� ������ �������
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
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� �� � �������!";
		link.l1.go = "First time_2";
		break;

		case "First time_2":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_HALLO_17_01.wav");
		dialog.text = "��, ���� �����, ��� ����� ����� �� ���������� ������ ������, � ��� �� ������� �����, � ��� �� ����� ������ �����.";
		link.l1 = "...";
		link.l1.go = "First time_3";
		break;

		case "First time_3":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_WAREZ_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ������ ���������� ���.";
		link.l1.go = "Rosi_Trade";
		break;

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "Rosi_Trade":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_WAREZ_17_01.wav");
		dialog.text = "�������.";
		link.l1 = "...";
		link.l1.go = "Rosi_Trade_exit";
		break;

		case "Rosi_Trade_exit":
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LaunchItemsTrade(npchar, 0);
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
