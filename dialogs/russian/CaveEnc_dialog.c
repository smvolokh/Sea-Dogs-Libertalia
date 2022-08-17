// �������� ����������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp, sGroup;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	sTemp = "CaveBandos" + locations[FindLocation(npchar.location)].index + "_";
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "CaveBanditosSit":
			if (drand(2) == 1) 
			{
				dialog.text = NPCStringReactionRepeat("��-��, ��� � ��� ���������! ������� ���� ���������� ����, ������. �� ������, ���, ������ �������... �������������� �� ���������, � ��� ������ ���� ��������� - ��� ����������� � ���� ����.", "�����-�����, ����� ������, �� ����� ���. ������ �������, � ������ �� ������, ��-��!", "�� ��� ����, �������. �������, ��������, ��� ����� �� ������? ���� � ����, �� �������!", "�� ���, �� ���� ������. �������� ���������� �� ��� �������� � �������� �����!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("����� �� ������, ��������...", "��, ��������, ������, ������...", "�����, ����, ���� ���� �������...", "��� ��� ������� ��������!", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("exit_talk", "exit", "exit", "fight", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = LinkRandPhrase("��-��, �� ���� ��! ���� ������ ������ �� ���� - ���� �������... ��-��, ������, ����������� ����� ������!","��������, ���� ����� ���� �� ����... �� ��� ������ - �� ����� ����! ��-��, ��������, ����� �� ���� ������!","� ���� ���� ����� ���� �� �����, ��-��... �� ��� ������ - �� �� ���� ������� ���������, ���������, ��� ��������� �� ��������...");
				link.l1 = LinkRandPhrase("������ � ���� ������-�� ���������...","�������, ������ �������� ��� �� ���������, ��� ��������� ������?","�� ��� ��, ������ ����� ��������� � ����� ������� ���� �������������� ���� �����...");
				link.l1.go = "fight";
			}
			NextDiag.TempNode = "CaveBanditosSit";
		break;
		
		case "CaveBanditosStay":
			dialog.text = LinkRandPhrase("��-��, �� ���� ��! ���� ������ ������ �� ���� - ���� �������... ��-��, ������, ����������� ����� ������!","��������, ���� ����� ���� �� ����... �� ��� ������ - �� ����� ����! ��-��, ��������, ����� �� ���� ������!","� ���� ���� ����� ���� �� �����, ��-��... �� ��� ������ - �� �� ���� ������� ���������, ���������, ��� ��������� �� ��������...");
			link.l1 = LinkRandPhrase("������ � ���� ������-�� ���������...","�������, ������ �������� ��� �� ���������, ��� ��������� ������?","�� ��� ��, ������ ����� ��������� � ����� ������� ���� �������������� ���� �����...");
			link.l1.go = "fight";
		break;
		
		case "CaveBanditosTreasure":
			dialog.text = NPCStringReactionRepeat("���������� ������, ��������. ������ ��� �������!", "������, ��-�������� �����: ���� ������. ������� ���...", "��������� ��� ������������: �� ������ - ��������� �� ����.", "�� ��, ��������, �� ��� ����������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� �������� ���, ��� ������, �����?", "� ��� ��� ������ ����������? ������ � ������...", "�� ����� ����...", "��! �� �����, ���������, ��� ������!", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "fight", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "CaveBanditosTreasure";
		break;
		
		case "CaveCaribSit":
			if (drand(2) == 2) 
			{
				dialog.text = NPCStringReactionRepeat("����������� ������� �����. �� ����������, ��� "+npchar.name+" ����. ���� ��������� ��� ����� �������.", "��������� �� ��� ������, ���� � � ��� ������ �� �������!", "����������� �����, ����������� ���!", "���� ����� � ����� ������� � �����, ����� ������!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�� �������, ��������, �������...", "������ �� ���� - ���� � ����.", "������ ������, ��� ������.", "������ � ������ ��� ����� ���� � ������, �������...", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("exit_talk", "exit", "exit", "fight", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = LinkRandPhrase("��������� ����������� ��� ��� ������� �� ��� ������! �-��! ���� �����!","������ ������� ��� ������ � ����� �����. � ��������� ���� ������ �� ������!","������ ����������� ������� ������ ��� ������? ����� �� �� ����� ������ �������!");
				link.l1 = LinkRandPhrase("������ � ���� ������-�� ���������...","������ ����������� ����������� �� ����� ������ ������...","������, ������� ����� ��������� � ����� ������� ���� ���� �����, ����������� ��������...");
				link.l1.go = "fight";
			}
			NextDiag.TempNode = "CaveCaribSit";
		break;
		
		case "CaveCaribStay":
			dialog.text = LinkRandPhrase("������ ����������� ������ ������ ��� ������! �-��! � �������� ���� ������ � �������� ���!","������ ������� ��� ������ � ����� �����. ������, ������ ��������� ����� ���!","������ ����������� ������� ������� ��� ������? ����� �� �� ����� ������ �������!");
			link.l1 = LinkRandPhrase("������ � ���� ������-�� ���������...","������ ����������� ����������� �� ����� ������ ������...","������, ������� ����� ��������� � ����� ������� ���� ���� �����, ����������� ��������...");
			link.l1.go = "fight";
		break;
		
		case "exit_talk":
			DialogExit();
			sGroup = "CaveGroup_" + locations[FindLocation(pchar.location)].index;
			for(i=0; i<4; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_CharacterDisableDialog(sld);
			}
			LAi_CharacterEnableDialog(npchar);
		break;
		
		case "fight":
			DialogExit();
			sGroup = "CaveGroup_" + locations[FindLocation(pchar.location)].index;
			for(i=0; i<4; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_group_MoveCharacter(sld, sGroup);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			LAi_group_SetRelation(sGroup, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(sGroup, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(sGroup, "CaveEnc_RaidersAfrer");
			chrDisableReloadToLocation = true;
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}