// ������� ���������� ���������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int iTemp;
	string sTemp;
	
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
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// ����
		case "plantation_slave":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && findsubstr(npchar.id, "Slave_" , 0) != -1)
    		{
				dialog.text = RandPhraseSimple(RandPhraseSimple("� ��� ����� - ������ � ��� ������.", "��� ������ ��� ��� ����!"), RandPhraseSimple("��� ������ ������� ������� ��� ����.", "������������ ��� �� �������� ������ ����� �� ���� �����!"));				
				link.l1 = RandPhraseSimple("����������, ��������.", "��� ���� ����.");
				link.l1.go = "exit";				
    		} 
		break;
		
		// ������ - �������
		case "plantation_soldier":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            dialog.text = RandPhraseSimple(RandPhraseSimple("��� ������� - � ������������ ����������.", "������ �� �������� ����� �� ������ ������ �����������, ��������."), RandPhraseSimple("��� ������ - ������ ���� ������������.", "�� � ������ �� �������... �������, ��� � ������."));
			link.l1 = RandPhraseSimple("�������...", "����...");
			link.l1.go = "exit";
		break;
		// ������ - �������

		case "rudnik_soldier":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            dialog.text = RandPhraseSimple(RandPhraseSimple("��� ������� - � ������������ �������.", "������ �� �������� ����� � ����������� �� ������ ������ �����������, ��������."), RandPhraseSimple("��� ������ - ������ ���� ������������.", "�� � ������ �� �������... �������, ��� � ������."));
			link.l1 = RandPhraseSimple("�������...", "����...");
			link.l1.go = "exit";
		break;
		// ������ - ���������
		case "plantation_protector":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				if (sti(pchar.nation) == PIRATE)
				{
					PlaySound("VOICE\Russian\soldier_arest_1.wav");
    				dialog.text = RandPhraseSimple("������ �� ����� ���������?! �� ����... ������ ���!!", "��� �����!! ����� ���!!!");
					link.l1 = RandPhraseSimple("�����, �� � ���?..", "���, ���������� ��������.");
					link.l1.go = "fight"; 
					break;
				}
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = RandPhraseSimple("��-��, �� ���� �� ������ ��� ������ "+NationNameGenitive(sti(pchar.nation))+"! �����, ��������� ����������, ����� �� ������ ��� ����!", "���-���, ���-�� � ��� ��� "+NationNameAblative(sti(pchar.nation))+" ��������! ��������, ��������? ���� ���� ����������� � ����� �����������!");
				link.l1 = RandPhraseSimple("������ � ���� ���������� � ���� ������.", "�����, ��� � ������� ���� ���� ������.");
				link.l1.go = "fight"; 
			}
			else
			{
				if (GetNationRelation(sti(NPChar.nation), GetBaseHeroNation()) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
				{
					if (sti(pchar.nation) == PIRATE)
					{
						PlaySound("VOICE\Russian\soldier_arest_1.wav");
						dialog.text = RandPhraseSimple("�����?! �� ����... ������ ���!!", "��� �����!! ����� ���!!!");
						link.l1 = RandPhraseSimple("��, �����, �� � ���?..", "���, ���������� ��������...");
						link.l1.go = "fight"; 
						break;
					}
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� �� ����� �����?");
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "� ���� ������ � ������������ ���������� ��� ���������� �������� ������. � ���� ���� �������� ��������.";
						link.l1.go = "Licence";
						link.l2 = "� ���� ������ � ������������ ���������� ��� ���������� �������� ������.";
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) link.l1.go = "PegYou";
						else link.l2.go = "NotPegYou";
					}
					else
					{
						link.l1 = "� ���� ������ � ������������ ���������� ��� ���������� �������� ������.";
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) link.l1.go = "PegYou";
						else link.l1.go = "NotPegYou";
					}
				}
				else
				{
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� �� ����� �����?");
					link.l1 = "� ���� ������ � ������������ ���������� ��� ���������� �������� ������.";
					link.l1.go = "NotPegYou";
				}
			}
		break;
		
		case "Licence":
			iTemp = GetDaysContinueNationLicence(HOLLAND);
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -12)
			{
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = "��������? ������-��... �� �����! � ����� ����! ���� �������� ����� � ������ �������, � �� ���� ������ ������� ������� �������. ����� ���!";
				link.l1 = RandPhraseSimple("����!..", "��, �� ��� ����������...");
				link.l1.go = "fight";	
				break;
			}
			if (iTemp == -1)
			{
				PlaySound("VOICE\Russian\soldier_arest_1.wav");
				dialog.text = "������ ���������... ��! ���� �������� ���������� � ������� ���������������. �������, ���� ����� ���� � �����������, ��������...";
				link.l1 = RandPhraseSimple("��� �� �� ���!", "����� ��������, � �������...");
				link.l1.go = "fight";	
				TakeNationLicence(HOLLAND);
				break;
			}
			dialog.text = "������. ������ ���������. ���� ���� �������� � �� ��������� � �����, � �� �� ���������� ��-�� ����.";
			link.l1 = "�� ����������, ��������.";
			link.l1.go = "plantation_exit";
		break;
		
		case "PegYou":
			PlaySound("VOICE\Russian\soldier_arest_2.wav");
            dialog.text = "�������� ������? ��-��! ���� �� ���������! �� �� ���� �� ���� ����� "+NationNameAblative(sti(GetBaseHeroNation()))+"! ��������, ��������? ���� ���� ������������� � ����� �����������.";
			link.l1 = "���, ��� ���� ���� ������������� � ���� ������.";
			link.l1.go = "fight";
		break;
		
		case "NotPegYou":
            dialog.text = "������. ������ ���������. ���� ���� �������� � �� ��������� � �����, � �� �� ���������� ��-�� ����.";
			link.l1 = "�� ����������, ��������.";
			link.l1.go = "plantation_exit";
		break;
		
		case "plantation_exit":
           DialogExit();
		   NextDiag.CurrentNode = "plantation_repeat";
		break;
		
		case "plantation_repeat":
            dialog.text = "�����, ������� ���, �� ����, ��� �������!";
			link.l1 = "...";
			link.l1.go = "plantation_exit";
		break;
		
		// ����������� � ���������
		case "Plantator":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "plant_2" && GetSquadronGoods(pchar, GOOD_SLAVES) >=50)
			{
				dialog.text = "�� ������ ���� �����, ������?";
				link.l1 = TimeGreeting()+", ������. � ���� � ��� ������� �����������. � ������ ����� ������� ��������� ����, "+FindRussianQtyString(sti(GetSquadronGoods(pchar, GOOD_SLAVES)))+". �� ������� �� �� ���������� �� ������� ����?";
				link.l1.go = "mtraxx";
			}
            dialog.text = "�� ������ ���� �����, ������?";
			link.l1 = "������ ����� �� ������������ ��������� � �������� �� ���� ���������. � ��� �����.";
			link.l1.go = "exit";
		break;
		
		case "plantator_1":
            dialog.text = "�, ��� ����� ��, ������. ��� ���� ����?";
			link.l1 = "�������, ��� �������...";
			link.l1.go = "exit";
		break;
		
		case "mtraxx":
            dialog.text = "�������� ��� ��������, ������, �� � ������ ������ ���� ��������� � ����� �� ���������. ������� ������� ������� �� ������ ��������� ���� ����������� ������������-��������, ������������ �� � ������ �����. ��� ���...";
			link.l1 = "������ �������� �� ����� ���������? ��, ������, � ��� �� ������ ����� ��������?";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "������ � ��� �������, ��� ��� ����� ������� ������. �� � ���-�� �� �����: ��� ������� ������ �� ������ ��������� ��������. � �� �� ������� ��, �� ��� ���������� ��� ���������� ������ ������� ���� �� ������... �� � ���� ��� ��������� ������ ���������.";
			link.l1 = "�������. �������� ���� � ���-�����... ��, ������, �� �� ��������� ��� ������� �������� �� ����� ��������� � ��������� ��? ��������, � �� �������� ���� ��������� �� �������...";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "�� ��������?";
			link.l1 = "��, � �����-�� ������� ��. ���������������� ������ � ���� �� ������, �������, �� �� �������� ������� ������� �� �����������.";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "��� ���������. �� ��� ��, � �� �������� ������ ������ �����������. �������, ��������. ���� ���-�� ��������� - ���������, �������.";
			link.l1 = "�������, ������. �����, �� ��� ��������� ���� ������.";
			link.l1.go = "mtraxx_4";
		break;
		
		case "mtraxx_4":
           DialogExit();
		   NextDiag.CurrentNode = "plantator_1";
		   pchar.questTemp.Mtraxx = "plant_3";
		   AddQuestRecord("Roger_3", "5");
		break;
		
		case "":
            dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
            dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
            dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		
		case "":
            dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
            dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
	}
} 
