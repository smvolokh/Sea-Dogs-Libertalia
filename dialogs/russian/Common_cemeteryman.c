// Jason ����� ������ ����������� �������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;	

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Cemetery\" + NPChar.City + "_cemetery.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	
    int iTemp;
	string sTemp;
	bool ok;
    
	switch(Dialog.CurrentNode)
	{
		case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("� ������ ������� �������. ������, � ��� ���� ������� �� ������...", "�� �� �� ����� �� ������� ��� ��������� ������?.. �� ���, �������!!!", "� ���� ������ �� �� �������. ���� ������� ��������� ������ �������� ����� ��� �����!"), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������! ������!!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = PCharRepPhrase(RandPhraseSimple("������, ���� ���� �������...", "���, � �� ������� �� �������� ������ ��������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + "!"), 
					RandPhraseSimple("����������� � ��!", "���, ���� ���� �������� ��������� ������..."));
				link.l1.go = PCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = RandPhraseSimple("������ ����, �������! ���� ����� "+GetFullName(npchar)+", � � - ������������ ����� ��������� ���� �����, ��-��. �������, ��� ��� �����... ����� ����������?", "������������! ��������� � �� ����� ������ ��������... ��������� ������������� - "+GetFullName(npchar)+", � ��� �������� - ��� ��������� ���������� � ���� �����. ������, ��� �� ���� � ���������. ��� ���� �������?");
				link.l1 = "����������, "+npchar.name+"! ��� ��� - "+GetFullName(pchar)+", � � �������. ���, ����� �� �������� � ������ ����. �����, ������� � ���� ������ �����, ��������, ��� �� ������ ����� ����...";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� ������ ��������, ������� "+GetFullName(pchar)+"! ���������, ���������!";
				link.l1 = "�����������, �������! ��� ���� ������. ���� ��� �� ������ �� ����� �������� ������� � �������� � �������� �� ������?";
				link.l1.go = "talk";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "� ���� �� ��� �������-��, �������? ������� ����� ����, � ������� �� ��������. ��! �����-�� � ���� ���� ������ ������ �����, � ������ ��� ��� ������ - ��� ��������. ����������� �� ���������. � ����� ������������� ������ ��������...";
			link.l1 = "� ��� �� ��������, ����� ����������?";
			link.l1.go = "trade_info";
		break;
		
		case "talk":
			dialog.text = "��� ������� ��� �� ��� �� ��� ���?";
			link.l1 = "����� ���������, ��� � ���� ���� ������� � �������.";
			link.l1.go = "trade";
			link.l2 = "� ��� ��� "+ GetSexPhrase("�����","������") +" ��������...";
			link.l2.go = "quests";
			link.l3 = "������ ����������. ������ ����� �������������.";
			link.l3.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "trade_info":
			dialog.text = "� ���� ����� ���������� �������, ������� � ����� ��������� �� ��������� �������� � ������� �������� ������. ����� � ������ �� � ������. �� ��� ������ ����� �����, �� ��� �� �����, ��� ������. ������ � ������ �������� �����. ���, �� ���������, �� ���������� ��� ������-�� ������ �����\n��, � ����� ������ �������� ��� ���� ��� ������...";
			link.l1 = "������? �� ����, �� ������������ ��, ��� ���� ��������?";
			link.l1.go = "trade_info_1";
		break;
		
		case "trade_info_1":
			dialog.text = "�-��-��... ���, ��� ��� ��� ������������� ���������. ����� ��� ����� ���� ������ � �������������� �������, ���� �� ���������?";
			link.l1 = "��... �� ���, �������� ���������?";
			link.l1.go = "trade_info_2";
		break;
		
		case "trade_info_2":
			dialog.text = "�� ������, � ������ ����, ������� �� ��� �� �����. ����� �� ������ ���� ����������. ������ ��� ����-������� � �� �� ����� ����. �������� ��������� �� ������ ���� - '��, "+npchar.name+", �������� � �����'. ��� ������ ����� �������� ������ ��������, � ������ "+npchar.name+" ������� �� ������� ���� ����� �� ������������� ������.";
			link.l1 = "����. ������, ��� ���������, �� ������. �����, ������ ��� ���� ������.";
			link.l1.go = "trade";
			link.l2 = "�������. ��� ���� ����. ������� ���� �������������!";
			link.l2.go = "exit";
		break;
		
		case "trade":
				PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(20) + ".wav");
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
			NextDiag.TempNode = "First time";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Man_FackYou"://������� �� ������� ������� � ������
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
	}
}