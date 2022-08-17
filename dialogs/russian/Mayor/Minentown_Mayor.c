void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("�� ������� ������� ����?! ������ ���...", "��� ��� ����������� ���������, ����� �� ��� �������� ����?! ��� �����������...", "�� ��, ��� ������ ��������� �����, ��� "+ GetSexPhrase("�����-�� ����������","�����-�� �����������") +" ������ � ���� ����������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��� ������� ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����","") +"!", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ���� ����������! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� �������, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("�������� ���� ���� �����...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "��� ��� � ���� �����, ��������: ���� ����, � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
			if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
			{
    			dialog.text = "���� � ����������! �������!!";
				link.l1 = "�-���, ������!";
				link.l1.go = "fight"; 
				break;
			}			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = TimeGreeting() + " ������. � - "+GetFullName(npchar)+", ��������� ������� ���-����� ���������� " + NationKingsName(npchar)+". � ������ ������������� �������� ���� ������ ������, " + GetAddress_Form(NPChar) + ".";
				link.l1 = "� ����� �������, � ����� �� ������� ������ ������ �� ���� ���������, ��������, ����������� �����...";
				link.l1.go = "info";
				link.l2 = "� ������ ����� � ���� ������������� � ��� �����.";
				link.l2.go = "exit";
				npchar.quest.meeting = "1";
				break;
			}
			dialog.text = "��� ����� ��, ������? �� ��� ���-�� ������?";
			link.l1 = "�� ���, ������. � ��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "info":
			dialog.text = "������ ���������, ��� �� ����� ����������������. ��� ��, � ����� ��� � ���� ����, ��� ��� ��� ��� ���������\n������ ���-����� ��������� �� ��������� ��������� ������. ����� ������������ ������ ����������� ���������� � ������� ����, � ����� ������� � ���������� ����������. ��� ������� ������ � ������� ����������� ������� � � ���������� ��������� ��� ��������� ������� � ������ ����\n������ ������� ����������, ����� ��������� ������������ �������� �������� ��������� ������. ������ ������������ ������������� ������� �������� ��� ������, � ��� ��� ����������� ��������... ��� ���\n��� �� ����� ������, ������ ������������ ����� ��������� �����. � ��� ���� �������, �������. � ����� �������� �� ������ ���������� ������� � ���������� ������ �� ������� ����. ����� ����, ��� ���������, �� �� �������� � ��������, ������ ������� ��� � ������ ���������� ������� � ����\n�� ������� �������� � �������� �����������, ������ - ������ ����. ��� �� ���������, �� ��������� ��������� � ������� ����� - �� �������� � ���, ����� ���-�� �� ���� �������� ����������� �� ����\n��� ��� ���� �� ������� �������� ��� ����� - �� ����� �� � ��� � ����� �� ���������. �� ����� ������� ��� ����� ����� ���������� ��������������� � �������� ������� ��������, ��� ������ ����� ����� � �����\n�� �������� ��������� �� �������: �� ����������� ���� ��� ������, ��� ����� ����������� ��� ��� �����, ��� ��� ������ � ��� ���, ���� ���� ������-������� ���. �� ��������� ���-������ �������, ��� ������� �� ����� ������ ��������� - ��� �������� � ��� ����������\n��� � �������� � ���. ���������� ��� ��������� ������� � ������� ������� � ��� �� �����. �� ������� ������ ������������� ��������. ����������� �������� ������� - ��� � ����� ������ ��������������� ������������... ������. ����� ����������!";
			link.l1 = "�������!";			
			link.l1.go = "exit";
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
	}
}
