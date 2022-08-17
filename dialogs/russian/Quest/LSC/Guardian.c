// ������ �����������, ������ � ���������� ������ LSC
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���� ���� ��� ����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
//------------------------------------- ����� ������ �������� --------------------------------------------
		// ���� �������� �� ������ �� ���-��������
		case "Narval_warning":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
				break;
			}
			ref location = &Locations[FindLocation(pchar.location)];
			if (!CheckAttribute(location, "nrv_parolinfo"))
			{
				if (!CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
				{
					dialog.text = "����, ��������! ������ - ���������� ��������, ���� ����������� ���� ��������. ������ ���� ����� ������ �� �����������. �� ������ ������ ��� �������?";
					link.l1 = "��.";
					link.l1.go = "Narval_warning_yes";
					link.l2 = "���.";
					link.l2.go = "Narval_warning_no";
				}
				else // ���� ���� ��������
				{
					dialog.text = "�-�, ��� �� "+GetFullName(pchar)+"! ������, �������, ��� ������������ � ����. ������ ��������� �� '���-��������' � '����� �����' ��������. ����� ����������!";
					link.l1 = "�������, ��������!";
					link.l1.go = "exit";
				}
				location.nrv_parolinfo = "true";
			}
			else
			{
				if (!CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
				{
					dialog.text = "�������, �� �� ����� ������, ��������...";
					link.l1 = "�� ���������...";
					link.l1.go = "exit";
				}
				else // ���� ���� ��������
				{
					dialog.text = TimeGreeting()+", "+pchar.name+"! ��� ���� ����?";
					link.l1 = "�������, ������!";
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "Narval_warning_repeat";
			DeleteAttribute(npchar, "protector.CheckAlways");
		break;
		
		case "Narval_warning_yes":
			dialog.text = "����� ��� � ����� ��� ��� ���� �������� ����� �����. � ������, �� ������� ��� �������� - ���� ������ � ��������� ���� ���� �����. ��� ��� ���� �� ������ ��������� ������� - ����� ���������� � ����� �����. � ���� �����������.";
			link.l1 = "������, �������. � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Narval_warning_repeat";
		break;
		
		case "Narval_warning_no":
			dialog.text = "����� ���� ������ ��� ������, ���� ��, �������, �� ����� ����� �������� ������ ����� � ������. ��� �� ������, �? �������� ���� ����? �������, ���� ��� �� ����������. ������ ���� ����, ��� ���� �������������, � �� �����������. �� ���� �� ������������� �� ������ ������ - ����� �� ��� �� �������.";
			link.l1 = "������, �������. � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Narval_warning_repeat";
		break;
		
		case "Narval_warning_repeat":
			if (!CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
			{
				dialog.text = "��, ���� ���� ���? ��� ��� ���� �� '���-��������', ��� ���������� ������!";
				link.l1 = "...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "������, "+pchar.name+", �� � �� �����. �� �������� ����. ������!";
				link.l1 = "...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Narval_warning_repeat";
		break;
		
		case "Narval_parol":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
			{
				dialog.text = "������, "+pchar.name+", �� � �� �����. �� �������� ����. ������!";
				link.l1 = "...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Narval_parol";
				break;
			}
			dialog.text = "������! �� �� �� �����!";
			link.l1 = "��� ����.";	
			link.l1.go = "check_parol";
		break;
		
		case "check_parol":
			dialog.text = "������ ������, � ��������� ��� �����, ����� � ������ ���������.";
			link.l1.edit = 3;
			link.l1 = "";	
			link.l1.go = "check_parol_1";
		break;
		
		case "check_parol_1":
			sTemp = GetStrSmallRegister(dialogEditStrings[3]);
			if (sTemp == sNrvParol && CheckAttribute(pchar, "questTemp.LSC.NParol_bye"))
			{
				dialog.text = "������. ������ ���������.";
				link.l1 = "�������, ��������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Narval_parol_repeat";
				LAi_SetGuardianType(NPChar);
				LAi_group_MoveCharacter(NPChar, "LSC_NARVAL");
				pchar.questTemp.LSC.parol_nrv = "true";
			}
			else
			{
				dialog.text = "��... ������! � ��� ��������� �����!";
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
			}
		break;
		
		case "check_parol_fight":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			LAi_group_MoveCharacter(NPChar, "LSC_NARVAL");
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "Narval_parol_repeat":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
				break;
			}
			dialog.text = "����� �������, �� ����������! ������ ��� ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Narval_parol_repeat";
		break;
		
		// � ����������
		case "Narval_residence":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
			{
				dialog.text = TimeGreeting()+", "+pchar.name+"! ���� �� � ����� - ������, ����� �������.";
				link.l1 = "������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Narval_residence";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			if (!CheckAttribute(pchar, "questTemp.LSC.nrv_friend") && CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = "������� � ���������� ���������� ������ ��� ������. ������ ������ ����� - ���� � ���� �� �������!";
				if (CheckAttribute(pchar, "questTemp.LSC.Donald_enter"))
				{
					link.l1 = "� ���-���� ��� �������� ���� �������. � ��� ������� ������������, ������. � � ����������� ������� �� ��������. ��� ��� �������� ��� ������� �����!";
					link.l1.go = "negotiations";
				}
				else
				{
				link.l1 = "�� �� �����-�� � ��������...";
				link.l1.go = "exit";
				}
				NextDiag.TempNode = "Narval_residence";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			dialog.text = "�� � �����? ��, ��, �������, ���� ������.";
			link.l1 = "�������, ��� ��������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Narval_residence";
			DeleteAttribute(npchar, "protector.CheckAlways");
		break;
		
		case "Narval_soldier":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
				link.l1 = "�-���!";
				link.l1.go = "check_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) 
			{
				dialog.text = TimeGreeting()+", "+pchar.name+"! ��� ���� ����?";
				link.l1 = "�������, �������...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "��������, ��������, � �� � ���������� ��� � ����� �����������. ������� ���� ����...";
				link.l1 = "�����.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Narval_soldier";
		break;
		
		case "negotiations":
			dialog.text = "�����-�����... ���� ����������? ��� �� � ������, ��� � ����� �� ��������. �����, ��� ������ �����...";
			link.l1 = "�� ���� ��� ������, �������? ���, �������!";
			link.l1.go = "negotiations_1";
		break;
		
		case "negotiations_1":
			DialogExit();
			NextDiag.CurrentNode = "negotiations_2";
			LocatorReloadEnterDisable("LostShipsCity_town", "reload48", false); // ������� ���� � �������� �������
		break;
		
		case "negotiations_2":
			dialog.text = "�������, �������, ���� ���������...";
			link.l1 = "�� �������?";
			link.l1.go = "exit";
			NextDiag.TempNode = "negotiations_2";
		break;
		
//------------------------------------- ����� ������ ������� --------------------------------------------
		// ���� ������� �� ������ �� ����� � �������
		case "Rivados_warning":
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				dialog.text = LinkRandPhrase("������! ���������! ����� ����������� ��������! � ������!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� �����!");
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
				break;
			}
			location = &Locations[FindLocation(pchar.location)];
			if (!CheckAttribute(location, "rvd_parolinfo"))
			{
				if (!CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
				{
					dialog.text = "���������� ����! ���������� �� ���� ������ ����������� ����� �������, ���� ����������� ����� ���� ���� ��������� ��� �����������. �� ������ ������?";
					link.l1 = "��.";
					link.l1.go = "Rivados_warning_yes";
					link.l2 = "���.";
					link.l2.go = "Rivados_warning_no";
				}
				else // ���� ���� �������
				{
					dialog.text = "�������, ��� ��� "+GetFullName(pchar)+"! ����� ���� ��� ������! ��� ������������, ��� �� ������ �������� ��������� �� ���� �������. ������ ����!";
					link.l1 = "�������, �������!";
					link.l1.go = "exit";
				}
				location.rvd_parolinfo = "true";
			}
			else
			{
				if (!CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
				{
					dialog.text = "�������, �� ������ ������� ������, ��������...";
					link.l1 = "�� ���������...";
					link.l1.go = "exit";
				}
				else // ���� ���� �������
				{
					dialog.text = TimeGreeting()+", "+pchar.name+"! ��� ���� ����?";
					link.l1 = "�������, ������!";
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "Rivados_warning_repeat";
			DeleteAttribute(npchar, "protector.CheckAlways");
		break;
		
		case "Rivados_warning_yes":
			dialog.text = "����� ������ ���������. ��� ��� ������ ������� ���������, ����� �� ������ ������. ��� ��� ���� �� ������ �������� - ����� ����� �������-���������. � ���� �����������.";
			link.l1 = "������, ��������. � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rivados_warning_repeat";
		break;
		
		case "Rivados_warning_no":
			dialog.text = "��-��! �� ��� ����� �������, ��� ����� ������ �������, ��� ������������� ������ � ���, �� ���� ������. ��� �� ������? ���� ������. � ����� ����, ����� �������������, � �� ����������. �� ���� �� ������������� �� ������ ������ - ����� ��������!";
			link.l1 = "������, ��������. � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rivados_warning_repeat";
		break;
		
		case "Rivados_warning_repeat":
			if (!CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = "��, ���� ���� ����? ��� ��� ������, ��� ���������� ������!";
				link.l1 = "...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "��������, "+pchar.name+", �� � �� �����. ���� ����� ���������, ���� � ����� ����� �������.";
				link.l1 = "...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Rivados_warning_repeat";
			DeleteAttribute(npchar, "protector.CheckAlways");
		break;
		
		case "Rivados_parol":
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				dialog.text = LinkRandPhrase("������! ���������! ����� ����������� ��������! � ������!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� �����!");
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = "������, "+pchar.name+", �� � �� �����. ���� ����� ���������, ���� � ����� ����� �������.";
				link.l1 = "...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Rivados_parol";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			dialog.text = "���� ��� ������! �� �� �� �������!";
			link.l1 = "� ���� ������ ������.";	
			link.l1.go = "Rcheck_parol";
		break;
		
		case "Rcheck_parol":
			dialog.text = "����� ������ ������, � ������ ���� � �����.";
			link.l1.edit = 3;
			link.l1 = "";	
			link.l1.go = "Rcheck_parol_1";
		break;
		
		case "Rcheck_parol_1":
			sTemp = GetStrSmallRegister(dialogEditStrings[3]);
			if (sTemp == sRvdParol && CheckAttribute(pchar, "questTemp.LSC.RParol_bye"))
			{
				dialog.text = "��� �����. ������ ���������.";
				link.l1 = "�������, ��������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Rivados_parol_repeat";
				LAi_SetGuardianType(NPChar);
				LAi_group_MoveCharacter(NPChar, "LSC_RIVADOS");
				pchar.questTemp.LSC.parol_rvd = "true";
			}
			else
			{
				dialog.text = "��-��! �� � ��� ���������� ����� ���������! ������� ���!";
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
			}
		break;
		
		case "Rcheck_parol_fight":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			LAi_group_MoveCharacter(NPChar, "LSC_RIVADOS");
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "Rivados_parol_repeat":
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				dialog.text = LinkRandPhrase("������! ���������! ����� ����������� ��������! � ������!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� �����!");
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
				break;
			}
			dialog.text = "�� ���� �����, �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rivados_parol_repeat";
		break;
		
		// � ����������
		case "Rivados_residence":
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				dialog.text = LinkRandPhrase("������! ���������! ����� ����������� ��������! � ������!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� �����!");
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = TimeGreeting()+", "+pchar.name+"! ���� �� � ���� � �������� - ��������, ����� �������. ��� ����� ���� ��� ������.";
				link.l1 = "������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Rivados_residence";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend") && !CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = "������� �������� ������ ������ � ����� ����! ��� ��� ������ ������. �����!";
				link.l1 = "�� �� �����-�� � ��������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Rivados_residence";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			if (GetCharacterIndex("Chimiset") == -1) // ������� ����
			{
				dialog.text = "���� ������ ������ � ����� ����! ��� ��� ������ ������. ��������!";
				link.l1 = "�� �� �����-�� � ��������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Rivados_residence";
				DeleteAttribute(npchar, "protector.CheckAlways");
				break;
			}
			dialog.text = "�� � ����? �� �����, �������, �� ������ ��� ���� �������.";
			link.l1 = "�������, ��� ��������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rivados_residence";
			DeleteAttribute(npchar, "protector.CheckAlways");
		break;
		
		case "Rivados_soldier":
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				dialog.text = LinkRandPhrase("������! ���������! ����� ����������� ��������! � ������!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� �����!");
				link.l1 = "�-���!";
				link.l1.go = "Rcheck_parol_fight";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) 
			{
				dialog.text = TimeGreeting()+", "+pchar.name+"! ��� ���������?";
				link.l1 = "�������, ������...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "��������, ����, � ���� ��� �������� ������� � ����� �������. �� ���� ���, ��� ������.";
				link.l1 = "�����.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Rivados_soldier";
		break;
//------------------------------------- ����� ������ ������� --------------------------------------------	
		// � ������
		case "Shark_storage":
			if (CheckAttribute(pchar, "GenQuest.SharkConflict"))
			{
				dialog.text = LinkRandPhrase("���������! ����� ������� ���� � �������! � ���!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� ����� ������ �����!");
				link.l1 = "�-���!";
				link.l1.go = "shark_guard_fight";
				break;
			}
			dialog.text = "����! ���� ���� ��������!";
			link.l1 = "������, ��� �������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Shark_storage";
		break;
		
		// � ����������
		case "Shark_residence":
			if (CheckAttribute(pchar, "GenQuest.SharkConflict"))
			{
				dialog.text = LinkRandPhrase("���������! ����� ������� ���� � �������! � ���!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� ����� ������ �����!");
				link.l1 = "�-���!";
				link.l1.go = "shark_guard_fight";
				break;
			}
			if (stf(environment.time) >= 6.00 && stf(environment.time) < 21.00)
			{
				if (pchar.questTemp.LSC == "begin" || pchar.questTemp.LSC == "mary") // ���� ������
				{
					dialog.text = "����! �� �� �� ����� �����... ����� �������� ���� �������, ��� �� ������ ��� ��������?";
					link.l1 = "�����?! ������ ������-�����?";
					link.l1.go = "first_talk_day";
				}
				else
				{
				dialog.text = "���� �� � �������� - �������, �� ������ ����.";
				link.l1 = "�������!";
				link.l1.go = "exit";
			}
			}
			else
			{
				if (pchar.questTemp.LSC == "begin" || pchar.questTemp.LSC == "mary") // ���� ������
				{
					dialog.text = "���� ��������? �� ������ - ���� �� �����! ��� �� �������, ��� ������� ������� � �����, ����� ���� ����� ����������������? ������� �����.";
					link.l1 = "������, ��� �������. � ��� ������������-�� �����?";
					link.l1.go = "first_talk_night";
				}
			else
			{
				dialog.text = "��� ������, ������� ������ �� ���������. ������� ������.";
				link.l1 = "������...";
				link.l1.go = "exit";
			}
			}
			NextDiag.TempNode = "Shark_residence";
		break;
		
		case "Shark_soldier":
			if (CheckAttribute(pchar, "GenQuest.SharkConflict"))
			{
				dialog.text = LinkRandPhrase("���������! ����� ������� ���� � �������! � ���!","���� �� ����������! � ���!","�� ��, ������� �������! ������ �� ���� ������� ����� ������ �����!");
				link.l1 = "�-���!";
				link.l1.go = "shark_guard_fight";
				break;
			}
			dialog.text = "������� ����� ���������, ���� ������, ��� � ������ �� �����. �������.";
			link.l1 = "�����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Shark_soldier";
		break;
		
		case "first_talk_night":
			dialog.text = NPCStringReactionRepeat("�� ���, � ���� ��������, ��� �������? �������������� ����� � ����� �� �������� �����, ������ ����� ����� ��� ������� - ������� ��� ���� ������� ������, ��� �������� ���� � �������. ��� � ��� ���� �� ����.", 
				"�� ���, �����������? � �� ������ ��� ���� ��������. ����������!", 
				"��� ��������, ������ ����...",
				"����� ���!!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������, ������. ���� ��� �� � ����������...", 
				"������, �����...",
				"�� �� ������ �!", 
				"���?!", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		case "first_talk_day":
			dialog.text = "�� ����� ������� �����, ������. ������ ����� �� ���� ������� �����, ��� ���� ����� - ��� �������. � ���� � ���� ����?";
			link.l1 = "��, ���� ������! � ���� � ���� ����, � ����� �������.";
			link.l1.go = "first_talk_day_1";
		break;
		
		case "first_talk_day_1":
			dialog.text = "� ����� �� ����� ���� � ����?";
			link.l1 = "�� ���� � ����� ����� �����. � �������� �� ���� ��� ��������, ������ ������?";
			link.l1.go = "first_talk_day_2";
		break;
		
		case "first_talk_day_2":
			dialog.text = "������� �������? ��! �� ��� ����� �������� �����... ������, ������, �� ���������. ��� �������, ����� ���� ����������� ����, ��� ����������, ���� � �� �����������. ����� ��� ������ �� ������� � ���� ���� ������, ��� ��� � ������ �������� ������.";
			link.l1 = "������. ���, �������� �� ��� ������, ��� �� ������� �������, ���������� ����� �����.";
			link.l1.go = "first_talk_day_3";
		break;
		
		case "first_talk_day_3":
			PlaySound("interface\important_item.wav");
			dialog.text = "(�������������)... ������. �����, ����� ��� ����� ���������. �������.";
			link.l1 = "�� �������? ����� ������, ���� ���� ��� �� ���������.";
			if (pchar.questTemp.LSC == "mary") link.l1.go = "first_talk_day_5";
			else link.l1.go = "first_talk_day_4";
		break;
		
		case "first_talk_day_4":
			PlaySound("interface\important_item.wav");
			npchar.dialog.currentnode = "First time";
			DialogExit();
			LSC_OpenSanAvgustinDoors(); // ��������� ���-��������
			LocatorReloadEnterDisable("LostShipsCity_town", "reload2", true); //��������� �������� �� ������� ����
			pchar.quest.LSC_entry_pantry.over = "yes"; //����� ���������� �� �����
			pchar.quest.LSC_findMary.over = "yes"; //����� ���������� �� ����
			pchar.questTemp.LSC = "entrance"; //������ ����
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance";
			// ��������� ���� � ����
			LocatorReloadEnterDisable("LostShipsCity_town", "reload60", true);
			LocatorReloadEnterDisable("LostShipsCity_town", "reload61", true);
		break;
		
		case "first_talk_day_5":
			PlaySound("interface\important_item.wav");
			npchar.dialog.currentnode = "First time";
			DialogExit();
			LSC_OpenSanAvgustinDoors(); // ��������� ���-��������
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance";
		break;
		
		case "shark_guard_fight":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			LAi_group_MoveCharacter(NPChar, "LSC_SHARK");
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}