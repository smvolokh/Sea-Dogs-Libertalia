// ������� ���������� ���������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp, i, n;
	string sTemp;
	bool bOk;
	
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
			dialog.text = RandPhraseSimple(RandPhraseSimple("� ��� ����� - ������ � ��� ������.", "��� ������ ��� ��� ����!"), RandPhraseSimple("��� ������ ������� ������� ��� ����.", "������������ ��� �� �������� ������ ����� �� ���� �����!"));				
			link.l1 = RandPhraseSimple("����������, ��������.", "��� ���� ����.");
			link.l1.go = "exit";				
		break;
		
		// ����-������ �� ��������� �������
		case "pirate_slave":
			dialog.text = RandPhraseSimple(RandPhraseSimple("������, ������� �� ����!", "������."), RandPhraseSimple("��� ���� �� ���� �����?!", "������ � �����!"));				
			link.l1 = RandPhraseSimple("��...", "��-��...");
			link.l1.go = "exit";				
		break;
		
		// ������ - �������
		case "plantation_soldier":
            dialog.text = RandPhraseSimple(RandPhraseSimple("��� ������� - � ������������ ����������.", "������ �� �������� ����� �� ������ ������ �����������, ��������."), RandPhraseSimple("��� ������ - ������ ���� ������������.", "�� � ������ �� �������... �������, ��� � ������."));
			link.l1 = RandPhraseSimple("�������...", "����...");
			link.l1.go = "exit";
		break;
	// ������ - �������
		case "rudnik_soldier":
            dialog.text = RandPhraseSimple(RandPhraseSimple("��� ������� - � ������������ �������. �� � ���� � ��������, ������� ���������� �������� �� �����.", "������ �� �������� ����� � ����������� �� ������ ������ �����������, ��������."), RandPhraseSimple("��� ������ - ������ ���� ������������.", "�� � ������ �� �������... �������, ��� � ������."));
			link.l1 = RandPhraseSimple("�������...", "����...");
			link.l1.go = "exit";
		break;
			// ������ - ���������
			case "plantation_protector":
              if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				if (sti(pchar.nation) == PIRATE)
				{
					PlaySound("VOICE\Russian\soldier_arest_1.wav");
    				dialog.text = RandPhraseSimple("������ �� ����� ���������?! �� ����... ������ ���!!", "��� �����!! ����� ���!!!");
					link.l1 = RandPhraseSimple("�����, �� � ���?..", "���, ���������� ��������.");
					link.l1.go = "fight"; 
Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = RandPhraseSimple("��-��, �� ���� �� ������ ��� ������ "+NationNameGenitive(sti(pchar.nation))+"! �����, ��������� ����������, ����� �� ������ ��� ����!", "���-���, ���-�� � ��� ��� "+NationNameAblative(sti(pchar.nation))+" ��������! ��������, ��������? ���� ���� ����������� � ����� �����������!");
				link.l1 = RandPhraseSimple("������ � ���� ���������� � ���� ������.", "�����, ��� � ������� ���� ���� ������.");
			link.l1.go = "fight"; 
Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
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
Link.l2 = "���������, �� �������, ����� �����������?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� �� ����� �����?");
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "� ���� ������ � ������������ ���������� ��� ���������� �������� ������. � ���� ���� �������� ��������.";
						link.l1.go = "Licence";
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
		// ������ - ���������
		case "Rudnik_protector":
              if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				if (sti(pchar.nation) == PIRATE)
				{
					PlaySound("VOICE\Russian\soldier_arest_1.wav");
    				dialog.text = RandPhraseSimple("������ �� ����� �������?! �� ����... ������ ���!!", "��� �����!! ����� ���!!!");
					link.l1 = RandPhraseSimple("�����, �� � ���?..", "���, ���������� ��������.");
					link.l1.go = "fight"; 
Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
				PlaySound("VOICE\Russian\soldier_arest_2.wav");
				dialog.text = RandPhraseSimple("��-��, �� ���� �� ������ ��� ������ "+NationNameGenitive(sti(pchar.nation))+"! �����, ��������� ����������, ����� �� ������ ��� ����!", "���-���, ���-�� � ��� ��� "+NationNameAblative(sti(pchar.nation))+" ��������! ��������, ��������? ���� ���� ����������� � ����� �����������!");
				link.l1 = RandPhraseSimple("������ � ���� ���������� � ���� ������.", "�����, ��� � ������� ���� ���� ������.");
			link.l1.go = "fight"; 
Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
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
Link.l2 = "���������, �� �������, ����� �����������?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
				}
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� �� ����� �����?");
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "� ���� ������ � ������������ �������� ��� ���������� �������� ������. � ���� ���� �������� ��������.";
						link.l1.go = "Licence";
					}
					else
					{
						link.l1 = "� ���� ������ � ������������ �������� ��� ���������� �������� ������.";
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) link.l1.go = "PegYou";
						else link.l1.go = "NotPegYou";
					}
				}
				else
				{
					PlaySound("VOICE\Russian\soldier_arest_4.wav");
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� �� ����� �����?");
					link.l1 = "� ���� ������ � ������������ �������� ��� ���������� �������� ������.";
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
Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;
			}
			if (iTemp == -1)
			{
				PlaySound("VOICE\Russian\soldier_arest_1.wav");
				dialog.text = "������ ���������... ��! ���� �������� ���������� � ������� ���������������. �������, ���� ����� ���� � �����������, ��������...";
				link.l1 = RandPhraseSimple("��� �� �� ���!", "����� ��������, � �������...");
				link.l1.go = "fight"; 
			TakeNationLicence(HOLLAND);
		Link.l2 = "���������, �� �������, ����� �����������?";
		if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
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
Link.l2 = "���������, �� �������, ����� �����������?";
if(makeint(Pchar.rank) >= 1 && GetSummonSkillFromNameToOld(Pchar, SKILL_COMMERCE) >= 1)
			{
			Link.l2.go = "GiveMeSomeMoney";
			}
			else
			{
			Link.l2.go = "TryingToGiveBribe";
			}
			if (CheckCharacterPerk(pchar, "Trustworthy"))
			{   
			link.l2 = RandPhraseSimple ("������, ������� �� ����. ����� � ����� �� �����������?", "������ �������� ������������... �������� ���������� �� ���� � �����������!");
			link.l2.go = "NotPegYou2";
			}
			break;

		case "NotPegYou":
            dialog.text = "������. ������ ���������. ���� ���� �������� � �� ��������� � �����, � �� �� ���������� ��-�� ����.";
			link.l1 = "�� ����������, ��������.";
			link.l1.go = "plantation_exit";
		break;

	case "NotPegYou2":
			dialog.text = RandPhraseSimple("�����. ��� � �������, �� ������ ����, " + GetAddress_Form(pchar) + ".", "���-�� � ������� �������� � �������... ��� � �������, " + GetAddress_Form(pchar) + ", ����� ��������.");
			link.l1 = "���-��!";
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
		
		// ����������� � ��������� // Addon 2016-1 Jason
		case "Plantator":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "plant_2" && GetSquadronGoods(pchar, GOOD_SLAVES) >= 50)
			{
				dialog.text = "�� ������ ���� �����, ������?";
				link.l1 = TimeGreeting()+", ������. � ���� � ��� ������� �����������. � ������ ����� ������� ��������� ����, "+FindRussianQtyString(sti(GetSquadronGoods(pchar, GOOD_SLAVES)))+". �� ������� �� �� ���������� �� ������� ����?";
				link.l1.go = "mtraxx";
				break;
			}
            dialog.text = "�� ������ ���� �����, ������?";
			link.l1 = "������ ����� �� ������������ ��������� � �������� �� ���� ���������. � ��� �����.";
			link.l1.go = "plantator_x";
		break;
		
		case "plantator_x":
           DialogExit();
		   npchar.dialog.currentnode = "plantator";
		break;
		
		case "plantator_1":
			bOk = GetSquadronGoods(pchar, GOOD_COFFEE) >= 500 || GetSquadronGoods(pchar, GOOD_CINNAMON) >= 500 || GetSquadronGoods(pchar, GOOD_COPRA) >= 500;
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "plant_6" && bOk)
			{
				dialog.text = "�, ��� ����� ��, ������. ��� ���� ����?";
				link.l1 = "� � ��� � ������� ������������. � ��� �� ��������� ���������� ����� � �����. � ���� ���������� ���� ���������, �� �� �� ������, � � ����� �� ��� ������. �����, �����������?";
				link.l1.go = "mtraxx_5";
				break;
			}
            dialog.text = "�, ��� ����� ��, ������. ��� ���� ����?";
			link.l1 = "�������, ��� �������...";
			link.l1.go = "plantator_1x";
		break;
		
		case "plantator_1x":
           DialogExit();
		   npchar.dialog.currentnode = "plantator_1";
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
		   Mtraxx_PlantSetMaxRocur();
		break;
		
		case "mtraxx_5":
            dialog.text = "������ �� � ���? ����� ������ �� ����������� �� �����?";
			if (GetSquadronGoods(pchar, GOOD_COFFEE) >= 500)
			{
				link.l1 = "������� ������ ����.";
				link.l1.go = "mtraxx_coffee";
			}
			if (GetSquadronGoods(pchar, GOOD_CINNAMON) >= 500)
			{
				link.l2 = "������� ������ ������.";
				link.l2.go = "mtraxx_cinnamon";
			}
			if (GetSquadronGoods(pchar, GOOD_COPRA) >= 500)
			{
				link.l3 = "������� ������ �����.";
				link.l3.go = "mtraxx_copra";
			}
			if (GetSquadronGoods(pchar, GOOD_TEA) >= 500)
			{
				link.l4 = "������� ������ ���.";
				link.l4.go = "mtraxx_tea";
			}
		break;
		
		case "mtraxx_coffee":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 16;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 100;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 100;
            dialog.text = "������� ������ ����? ���-���... ������� ��������... (�������) � ����� �������� ��� ���� �� "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" ������ ������ � "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ������ �����. ��������?";
			link.l1 = "�-�-�... � ����������� ������� �� �������... �� �����. � ��������!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_cinnamon":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 24;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 106;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 106;
            dialog.text = "������� ������ ������? ���-���... ������� ��������... (�������) � ����� �������� ���� ������ �� "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" ������ ������ � "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ������ �����. ��������?";
			link.l1 = "�-�-�... � ����������� ������� �� �������... �� �����. � ��������!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_copra":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 25;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 100;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 100;
            dialog.text = "������� ������ �����? ���-���... ������� ��������... (�������) � ����� �������� ���� ����� �� "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" ������ ������ � "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ������ �����. ��������?";
			link.l1 = "�-�-�... � ����������� ������� �� �������... �� �����. � ��������!";
			link.l1.go = "mtraxx_6";
		break;

		case "mtraxx_tea":
			i = drand(3)+1;
			n = 5 - i;
			pchar.questTemp.Mtraxx.PlantGood.Cargo = 26;
			pchar.questTemp.Mtraxx.PlantGood.Sugar = i * 110;
			pchar.questTemp.Mtraxx.PlantGood.Cocoa = n * 110;
            dialog.text = "������� ������ ���? ���-���... ������� ��������... (�������) � ����� �������� ��� ��� �� "+sti(pchar.questTemp.Mtraxx.PlantGood.Sugar)+" ������ ������ � "+sti(pchar.questTemp.Mtraxx.PlantGood.Cocoa)+" ������ �����. ��������?";
			link.l1 = "�-�-�... � ����������� ������� �� �������... �� �����. � ��������!";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_6":
            dialog.text = "����� ������! ��� ��� ����� ��� �������� ������! ����� ���������� �����?";
			link.l1 = "��� ���� ����������� �����. �� � ���, ��������, ����. ������ ������ � ������ ���� ������ - ��� ��� � ������ ������ ��� ���� ��������� ��� �� ��������� ��� �����.";
			link.l1.go = "mtraxx_7";
		break;
		
		
		case "mtraxx_7":
            dialog.text = "������������. ����� �� ������, ������!";
			link.l1 = "�� ������...";
			link.l1.go = "mtraxx_8";
		break;
		
		case "mtraxx_8":
            DialogExit();
			NextDiag.CurrentNode = "plantator_1";
			AddQuestRecord("Roger_3", "10");
			Mtraxx_PlantSetMaxRocur_1();
			pchar.questTemp.Mtraxx = "plant_7";
			pchar.GenQuest.CannotWait = true;//������ ��������
			pchar.quest.mtraxx_plant_goods.win_condition.l1 = "ExitFromLocation";
			pchar.quest.mtraxx_plant_goods.win_condition.l1.location = pchar.location;
			pchar.quest.mtraxx_plant_goods.function = "Mtraxx_PlantFindRocurDay";
		break;
		
		case "mtraxx_9":
            dialog.text = "�� ���, ������, �� � ���������. ���� ��� ����������� ��� �����, ��� ����� - ��� ���. �� �������, �� ����� - ������ ����������!";
			link.l1 = "���� ������� � ���� ������� �������� ���������� ������� - �� � ���� ��� ����������. � ������ ��������� ����������� - ��� ����.";
			link.l1.go = "mtraxx_10";
		break;
		
		
		case "mtraxx_10":
            dialog.text = "����� �������, ������!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_PlantAfterTrading");
		break;

	//��������� �� ����������� ������
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "���� ���������� ����� ��������? ����� � ����������! ������ ����� ������...", "����� ����� �������? ����� ���� �������� ������!");
				link.l1 = RandPhraseSimple("�����"+ GetSexPhrase("","�") +".", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;

		//��������� �� ����������� ������
		case "SoldierNotBlade":
			dialog.text = LinkRandPhrase("���� �� ������� ������������?! ���������� ������� ������!", "���������� ��� ���������� ������ ������!", "��, " + GetAddress_Form(NPChar) + ", �� ������� �����! ������� ������.");
			link.l1 = LinkRandPhrase("������, ������...", "��� "+ GetSexPhrase("�����","������") +".", "��� �������...");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("����� � ���!", "������ ���� ��� � ����!", "�����, ����� ����� �����.");
			link.l2.go = "fight";
			npchar.greeting = "soldier_common";
			NextDiag.TempNode = "First Time";
		break;

//============================== ������ =========================

	case "GiveMeSomeMoney":	
			dialog.snd = "Voice\COGU\COGU005";		
			dialog.text = "��� �����, �������, ����� � ����������...";
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000) 
			{ 
				Link.l1 = "�������, "+sti(NPChar.rank)*1000+" ���� �������?"; 
				Link.l1.go = "Bribe"; 
			} 
			Link.l2 = "��, �� ��������� � ��� � ����� ������������... ������, ������ �������, �������!"; 
			Link.l2.go = "fight"; 
		break;

		case "TryingToGiveBribe":
			dialog.snd = "Voice\COGU\COGU006";
			dialog.text = "����������� ������? ��� ��, ��� ����� ������� ������! �������� ��������� �� ����!";
			Link.l1 = "���������! ���� ��� ��������������, ������, �� ������ � � ���� �� �����!";
			Link.l1.go = "fight";
		break;

case "Bribe": 
			dialog.text = "������, �������."; 
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000))); 
			Link.l1 = "������������."; 
			Link.l1.go = "Bribe_1"; 
		break; 
case "Bribe_1": 
dialog.text = "��������� � ����� � �� ����������� ��� �� �����!"; 
			Link.l1 = "����������."; 
AddCharacterExpToSkill(PChar, "Leadership", 500); 
AddCharacterExpToSkill(PChar, "Sneak", 500); 
AddCharacterExpToSkill(PChar, "Commerce", 500); 
AddCharacterExpToSkill(PChar, "Fortune", 500); 
PlaySound("_CheatSurfMenu_\Gold.wav");
			Link.l1.go = "plantation_exit"; 
		break; 
	}
} 
