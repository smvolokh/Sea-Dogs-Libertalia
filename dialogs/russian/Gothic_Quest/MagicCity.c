void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	int iTemp;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_orient":			
			for (i=1; i<=12; i++)
			{
				sld = characterFromId("CaracasCit_"+i);
                LAi_ActorStay(sld);
			}
			LAi_ActorTurnByLocator(npchar, npchar.location.group, npchar.location.locator);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
            LAi_group_Attack(NPChar, Pchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//��������� �� ����������� ������
		case "CitizenNotBlade":
			dialog.text = "� ���-������� �� ����� ������ � ���������� �������.";
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "DesMoinesCitizen";
		break;

		//��������� �������� � ��������
		case "CaracasMan":
			dialog.text = "��, "+ GetSexPhrase("�����","�������") +", ���� ������ �������������? ����"+ GetSexPhrase("��","��") +" �� ������!";
			link.l1 = "�����, � ����������, ���� �� ����������, � ���.";
			link.l1.go = "CaracasMan_1";
		break;
		case "CaracasMan_1":
			dialog.text = "�� ���, � �������, ��������� �����. ���, ����� ��� - ��! - �� �������� ���������, ��-��!";
			link.l1 = "�� �� ����, ��������! ���-�� ��������!";
			link.l1.go = "CaracasMan_2";
		break;
		case "CaracasMan_2":
			dialog.text = "����� ��� �����, ���� ���! � �����, ��� ��� ��������� � �� ����! � �� ������ ����, ��� ��, �������� ����������?";
			link.l1 = "���������, ��������? ��, � ���� �� ����� ��� ������? �� ������ ���!";
			link.l1.go = "CaracasMan_3";
		break;
		case "CaracasMan_3":
			dialog.text = "��� ������ �������, �������, �������! ��� ������ �� ������� - ��! - �����, ����� ������!";
			link.l1 = "�, �� ��� � ������ ���� ��������� ���������! ��-��, ���������� ����, ��������, ��� ��� �� ���������. � ���� ��� �� ���� ������� � ��� ������!";
			link.l1.go = "exit_orient";
			DeleteAttribute(&locations[reload_location_index], "reload.l41.disable");
		break;
		//��������� � ��������
		case "CaracasWervolf":
	                PlaySound("VOICE\Russian\GOTHIC\JOE_03.wav");
			dialog.text = "��� �� � ��� ��� �����?";
			link.l1 = "� ������� " + GetFullName(pchar) + ". � ��� �� ���? ���, �� �����, ��������� ����������� ����� ���������� � ��� � �����, � ���� �� �����, ����� ����������� ������� � ���������.";
			link.l1.go = "CaracasWervolf_1";
		break;
		case "CaracasWervolf_1":
	                PlaySound("VOICE\Russian\GOTHIC\JOE_05.wav");
			dialog.text = "��� ���������� ����� ����! �� ����� ���, � ���������! � ����� �� ���������, �� ��������� ���������, ������� ���������� �� ���� ������� ������ ������. �������! �� ������ ��� ������. ��� ���������� ��������������!";
			link.l1 = "�� �� ������, ��������. � �� ���������.";
			link.l1.go = "CaracasWervolf_2";
		break;
		case "CaracasWervolf_2":
			dialog.text = "�� �� ���� ������ �������� ���� ����������?";
			link.l1 = ""+ GetSexPhrase("� ������� ������� ���, ��� ������ � �������� ���� �� �����, �������, ��� ��������.","������.") +" ����� �����, ������������ ������������!";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			pchar.questTemp.MC = "toCaracasPadre";
			iTemp = FindLocation("Caracas_tavern");
			DeleteAttribute(&locations[iTemp], "reload.l1.disable");
			DeleteAttribute(&locations[iTemp], "reload.l4.disable");
			LocatorReloadEnterDisable("Caracas_town", "reload7_back", false);
			locations[iTemp].reload.l2.disable = true;
			for (i=1; i<=12; i++)
			{
				sld = characterFromId("CaracasCit_"+i);
				sld.dialog.currentnode = "CaracasMan2";  
				LAi_SetActorTypeNoGroup(sld);
				LAi_ActorWaitDialog(sld, pchar);
			}
		break;
		//�������� �������� �� ������ �� �������
		case "CaracasMan2":
			dialog.text = "��, ���? ��������� �� ������?";
			link.l1 = "��� ���, ��������� �� �� �� �����! ��� ��� �������� ��������!";
			link.l1.go = "exit_orient";
		break;
		//������ ���-������� � �����
		case "ShoreGuard":
 	                PlaySound("VOICE\Russian\GOTHIC\SVM_6.wav");
			dialog.text = "��, ��! ����� ������ �� �����. �������� � ���� �����, �������-���������!";
			link.l1 = "�����, ����� ���������� ����������� ������ ������ ���� ��������� ����������?";
			link.l1.go = "ShoreGuard_1";
		break;
		case "ShoreGuard_1":
 	                PlaySound("VOICE\Russian\GOTHIC\SVM_4.wav");
			dialog.text = "��, �� ������� �����. ��� �� �� "+ GetSexPhrase("��� �� �������������, �������","���� �� �������������, �������") +"! �� ��������� ����� ������ - ��������!";
			link.l1 = "� ��� ����� ��� ��������� ������ ���, ��� � ����?";
			link.l1.go = "ShoreGuard_2";
		break;
		case "ShoreGuard_2":
 	                PlaySound("VOICE\Russian\GOTHIC\SVM_5.wav");
			dialog.text = "� ����� ���� �� ����� �����. ��� ����� ����� ��� �����!";
			link.l1 = "��� �, �������, ��� ����� �����?";
			link.l1.go = "ShoreGuard_3";
		break;
		case "ShoreGuard_3":
	                PlaySound("VOICE\Russian\GOTHIC\SVM_7.wav");
			LocatorReloadEnterDisable("Shore_ship3", "reload1", false);
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");
			AddQuestRecord("MagicCity", "3");
			DialogExit();
		break;
		//������ ���-������� �������
		case "DMCitiz":
	                PlaySound("VOICE\Russian\GOTHIC\VLK_00.wav");
			NextDiag.TempNode = "DMCitiz";
			dialog.text = LinkRandPhrase("��� ��� ����� � ��� � ������?", "����� � ����� ������ ���������� ����� �����. � �� ��� ������?", "�� ������ ��, ��� �� ���� ��� ��������������. ��� ��� ����� � ���-�������?");
			link.l1 = "����������, ��� ������...";
			link.l1.go = "DesMoinesCitizen_1";
			if (pchar.questTemp.MC == "toByeBye")
			{
				dialog.text = LinkRandPhrase("���� �� �������"+ GetSexPhrase("","�") +"! �����, ���� ��� ������ ��� �������...", "�����, ���� ������, ����"+ GetSexPhrase("","���") +" ��������"+ GetSexPhrase("��","��") +"...", "���� ������! � ����� � ���� ����� ������ �� �����...");
				link.l1 = "�����������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSister" || pchar.questTemp.MC == "toSeekSkull" || pchar.questTemp.MC == "toSeekQueen")
			{
				dialog.text = LinkRandPhrase("�������, ��� �� ����������� ������ ���. ����� ���, �������...", "�� ����������� ��� �������, "+ GetSexPhrase("������ �������","���������") +"!", "��� � �����, ����� � ��� ��� ����������!");
				link.l1 = "�����������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "over")
			{
				dialog.text = ""+ GetSexPhrase("������, �� ��� ���������","���������, �� ���� �������������") +"! �� ������ ��� �������!";
				link.l1 = "�������. ������"+ GetSexPhrase("","�") +", ������"+ GetSexPhrase("","�") +"...";
				link.l1.go = "exit";
			}
		break;
		case "DesMoinesCitizen_1":
	                PlaySound("VOICE\Russian\GOTHIC\GEPPERT_01.wav");
			dialog.text = "��� � �������.";
			link.l1 = "��-�, �����������!";
			link.l1.go = "DesMoinesCitizen_2";
		break;
		case "DesMoinesCitizen_2":
			dialog.text = "�� ������� ��� ������������� � ���. ��� ������� �� ����� ������������...";
			link.l1 = "��... ��, ��� ��� ���������.";
			link.l1.go = "exit";
		break;
		//������ ���-������� �������
		case "DMSkel":
	                PlaySound("VOICE\Russian\GOTHIC\SFX\ZOM_WARN02.wav");
			NextDiag.TempNode = "DMSkel";
			dialog.text = LinkRandPhrase("��������� ���� �� ���!", "��� ����� �������!", "������, ��� � ���� ����������? ����� ������� ���������!");
			link.l1 = "�� ��...";
			link.l1.go = "DesMoinesSkel_1";
			if (pchar.questTemp.MC == "toByeBye")
			{
	                PlaySound("VOICE\Russian\GOTHIC\SFX\ZOM_WARN01.wav");
				dialog.text = LinkRandPhrase("���� �� �������"+ GetSexPhrase("","�") +"! �����, ���� ��� ������ ��� �������...", "�����, ���� ������, ����"+ GetSexPhrase("","���") +" ��������"+ GetSexPhrase("��","��") +"...", "���� ������! � ����� � ���� ����� ������ �� �����...");
				link.l1 = "�����������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSister" || pchar.questTemp.MC == "toSeekSkull" || pchar.questTemp.MC == "toSeekQueen")
			{
	                PlaySound("VOICE\Russian\GOTHIC\SFX\ZOM_WARN02.wav");
				dialog.text = LinkRandPhrase("�������, ��� �� ����������� ������ ���. ����� ���, �������...", "�� ����������� ��� �������, "+ GetSexPhrase("������ �������","���������") +"!", "��� � �����, ����� � ��� ��� ����������!");
				link.l1 = "�����������!";
				link.l1.go = "exit";
			}
		break;
		case "DesMoinesSkel_1":
	                PlaySound("VOICE\Russian\GOTHIC\SFX\ZOMBIE_01.wav");
			dialog.text = "��� �� �� ������� ���� ���� ������, �� �������� � ������ �����, �������� �������. ����������� ������������ � ���.";
			link.l1 = "������.";
			link.l1.go = "exit";
			LocatorReloadEnterDisable("DesMoines_town", "reload1_back", true);
		break;
		//����� ������� �������
		case "DMCitizHead":
			NextDiag.TempNode = "DMCitizHead";
			dialog.text = "������������. ����� ���������� � ��� � ���-������?";
			link.l1 = "�� ���, ����������, ��� � ����... �������, � ��� ��� ��������� � ������?";
			link.l1.go = "DMCitizHead_1";
			if (pchar.questTemp.MC == "toByeBye")
			{
				dialog.text = "�������! � �� ���� ����� � ���� ����.";
				link.l1 = "��... �� � ���.";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSister")
			{
				dialog.text = ""+ GetSexPhrase("������ �������","���������") +", ��� ������ ������� ���-�� ����� - ����� ����� ���������� ����. �� ����, �� - ���� ��������� ������� �� ���������� �����.";
				link.l1 = "������� ��� ������ ��� ������ ����� �������� ���������. ���������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSkull")
			{
				dialog.text = "������������, �������! ��� �������?";
				link.l1 = "� ���"+ GetSexPhrase("��","��") +" �������� �������.";
				link.l1.go = "FoundLiz";
			}
			if (pchar.questTemp.MC == "toSeekQueen")
			{
				dialog.text = "������������, �������! ��� �������?";
				link.l1 = "� �������"+ GetSexPhrase("��","���") +" �� ������ ������� '������ ���������'. ������, ��� ��� ��������� ��� � ������ ������������.";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "over")
			{
				dialog.text = "��� �� ����� ���������? � �����-�� ������ � ��� ��� ���������������!";
				link.l1 = "��. � ���"+ GetSexPhrase("��","��") +" ������ '������ ���������' � ��� ������"+ GetSexPhrase("","�") +". ���"+ GetSexPhrase("","�") +", ��� �����"+ GetSexPhrase("","�") +" ��� ������.";
				link.l1.go = "DMHeadOver";
			}
			if (CheckAttribute(pchar, "questTemp.MC.DesMoines"))
			{
				dialog.text = "������"+ GetSexPhrase("","���") +", ���"+ GetSexPhrase("","�") +" ���������"+ GetSexPhrase("","����") +"! �� ���-�� ������?";
				link.l1 = "�� ���, ������ ����������...";
				link.l1.go = "exit";
			}
		break;
		case "DMCitizHead_1":
			dialog.text = "��� ������. � ������ �� �����������?";
			link.l1 = "�� ������, ����� � �������"+ GetSexPhrase("��","���") +" �� ���� ����������� ������, �� �� ���� ������ �����-�� ����. ���������� ��������� ������.";
			link.l1.go = "DMCitizHead_2";
		break;
		case "DMCitizHead_2":
			dialog.text = "������ �� ���� ��� ������� �� ����� ������. � �� � �����, ��� ��� ���.";
			link.l1 = "�������... ���, �� ��������, � ���-������� ��� ��������.";
			link.l1.go = "DMCitizHead_3";
		break;
		case "DMCitizHead_3":
			dialog.text = "���������� ���������.";
			link.l1 = "��, �������. ��������...";
			link.l1.go = "exit";
		break;

		case "FoundLiz":
			dialog.text = NPCStringReactionRepeat("�������! � ��� �� ��������?", 
				"�� ��� �������� �� ����, �������.", 
				"�������, �� ��� �������� �� ����.",
                "�������, �� ������� �����?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������� �� �����, ��� � ������ ���� �������� ��� ���������. �� �� ����� ��������, ��� ��� �����.", 
				"��, � �����.",
                "��, �������...", 
				"� ���"+ GetSexPhrase("��","��") +", ���������"+ GetSexPhrase("��","��") +". ��� �����, ���� ���� � �� �� ���������� - ����� �������� ����! �������� ������, ��� ��� ����-������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("FoundLiz_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "FoundLiz_1":
			dialog.text = "�������, �������! ������� ��������� ��������� ����������! ������� ������, ��� ��� �������?";
			link.l1 = "��� ������ ����������� ������ �������. ����� ��������� ���, � �������� ������, ��� ������ ������.";
			link.l1.go = "FoundLiz_2";
		break;
		case "FoundLiz_2":
			dialog.text = "�������, ����� ���, �������� ���, ��� � ����� �����.";
			link.l1 = "� � �����.";
			link.l1.go = "exit";
		break;

		case "DMHeadOver":
			dialog.text = "������� ��� �����������! �� ���� ����� ������� � ������������� ��������� ��c � ���, ��� �� ����������� ��� ������� �� �����.";
			link.l1 = "��� �� �������?";
			link.l1.go = "DMHeadOver_1";
		break;
		case "DMHeadOver_1":
			dialog.text = "�������� ����� ����! ����� ���� ��� ��� ��� �������, �� ��� ����� �� ��������� ����� ������� �������, ��� ��� ��� ���, ��� � ��� ����.";
			link.l1 = "�� �����, �������� ��� ������ ����. ��� ��� ������ ������.";
			link.l1.go = "DMHeadOver_2";
			link.l2 = "� �������� ���� ������.";
			link.l2.go = "DMHeadOver_3";
		break;
		case "DMHeadOver_2":
			dialog.text = "������� ��� ���. ������ ������, �� ������...";
			link.l1 = "�� �� �� ���. ������ ���������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar, "nobility",20);
			AddQuestRecord("MagicCity", "9");
			CloseQuestHeader("MagicCity");
			pchar.questTemp.MC.DesMoines = true;
		break;
		case "DMHeadOver_3":
			dialog.text = "�������! �� ��� ��, ����� ��� �������, ������"+ GetSexPhrase("","���") +".";
			link.l1 = "� ��� ����� ����������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 20000);
			AddQuestRecord("MagicCity", "9");
			CloseQuestHeader("MagicCity");
			pchar.questTemp.MC.DesMoines = true;
		break;

		//����� ������� ������
		case "DMSkelHead":
			NextDiag.TempNode = "DMSkelHead";
			dialog.text = "� ��� �����, ����� ������� ���� ����� ������ ��������, � �� �������� �������!";
			link.l1 = "������ �����, ����������� � ��� ��� ��������! ���� ���� ������, ��� ����� ��������?";
			link.l1.go = "DMSkelHead_1";
			if (pchar.questTemp.MC == "toByeBye")
			{
				dialog.text = "�������! � �� ���� ����� � ���� ����.";
				link.l1 = "��... �� � ���.";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSister")
			{
				dialog.text = ""+ GetSexPhrase("������ �������","���������") +", ��� ������ ������� ���-�� ����� - ����� ����� ���������� ����. �� ����, �� - ���� ��������� ������� �� ���������� �����.";
				link.l1 = "������� ��� ������ ��� ������ ����� �������� ���������. ���������!";
				link.l1.go = "exit";
			}
			if (pchar.questTemp.MC == "toSeekSkull")
			{
				dialog.text = "������������, �������! ��� �������?";
				link.l1 = "� ���"+ GetSexPhrase("��","��") +" �������� �������.";
				link.l1.go = "FoundLiz";
			}
			if (pchar.questTemp.MC == "toSeekQueen")
			{
				dialog.text = "������������, �������! ��� �������?";
				link.l1 = "� �������"+ GetSexPhrase("��","���") +" �� ������ ������� '������ ���������'. ������, ��� ��� ��������� ��� � ������ ������������.";
				link.l1.go = "exit";
			}
		break;
		case "DMSkelHead_1":
			dialog.text = "��������, ���� �� ����� �������! ��� ����� �� � ���� �������� ������ �� ������.";
			link.l1 = "� �� �� ��������, ��� ��� ������ ���� ��������. �������������.";
			link.l1.go = "DMSkelHead_2";
		break;
		case "DMSkelHead_2":
			dialog.text = "���-�� �������� � ������ ���� ��������� ������ '������ ���������'. ������ ����� ����� ��������������� �������. �������������� ����� �����...\n"+
				"������� ������ �����, � ����� � ��� ����� ����� ����� �����-�� �����. ����� ������� ����� ��������, � ��������� � ��������� �� ������� � ���� ����. � ��� ���� ��� � ��������.";
			link.l1 = "�� ��� ��������? �������� �� ������!";
			link.l1.go = "DMSkelHead_3";
		break;
		case "DMSkelHead_3":
			dialog.text = "�� ��� ��, ��� ������. ���� ��� ����, ��� ����, � ��� ������ ����� - ����� ��� ��������. ����������, ��� ��� ��-�� ������� ����, ���� ��� ��������! � ���� ��� ���� �� ����� ��������� �������������, �� ��� ����� - ����, ��� � ��� ���������, � ���� ���������� ���� �� ������ ���������. �� �������...";
			link.l1 = "�-��, ��������� �������...";
			link.l1.go = "DMSkelHead_4";
		break;
		case "DMSkelHead_4":
			dialog.text = "����, �������, �� ������ ���� ����� � ���� ����. �� ���������, ��� ������ ��� �������� ��������� �� � ����?";
			link.l1 = "� ������?";
			link.l1.go = "DMSkelHead_5";
		break;
		case "DMSkelHead_5":
			dialog.text = "� ��� ������, ��� ���-������ ��� �������� �� �����������. ������� ������ �� �����.";
			link.l1 = "� ��� ����� �� ������ ���������� �����.";
			link.l1.go = "DMSkelHead_6";
		break;
		case "DMSkelHead_6":
			dialog.text = "��� ���� ������ �� ������� ������ �� ���� ����������� ������. �� �� ��� ����� ���������� � ���. ��� ��� ������� ������ �� ����.";
			link.l1 = "� �� ������� �������� �������� ���� �����. �������"+ GetSexPhrase("��","���") +" ���� - ������� � ������...";
			link.l1.go = "DMSkelHead_7";
		break;
		case "DMSkelHead_7":
			dialog.text = "�������, ��� ���\n�������, ������ ��� ������� ����� �� �����. ��� ����� ����� ��������� ����� �� �������, � ���� �������, ������� ���������� � ������ ������... � ����� ������ ������ ����� �� ����� �������. �������, �����, ���-�� �� ���������...";
			link.l1 = "����, �� �����. �����, � ����� ���-�� ������?";
			link.l1.go = "DMSkelHead_8";		
			link.l2 = "�� ��������� �����, �������� ���. ����� ��� ���� �� ��� � ������ ���������? �������� ����!";
			link.l2.go = "DMSkelHead_bye";
			LocatorReloadEnterDisable("DesMoines_town", "reload1_back", false); //��������� �� ������
		break;

		case "DMSkelHead_bye":
			dialog.text = "� ��� ���� ��, ������������"+ GetSexPhrase("��","��") +" �������.";
			link.l1 = "����. �� ��������...";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar, "nobility", -20);
			AddQuestRecord("MagicCity", "4");
			AddQuestUserData("MagicCity", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("MagicCity", "sSex1", GetSexPhrase("��","��"));
			pchar.questTemp.MC = "toByeBye"; //���� ������	
		break;

		case "DMSkelHead_8":
			dialog.text = "����� ��������� - ��� ���� �����. ���� � ���, ��� �� ���� �� �����, � ��� ����.";
			link.l1 = "�����... ����� ���������� ��������� ���� ������, �� ������� ���� ������? ������, ��� ��� ������������ �������.";
			link.l1.go = "DMSkelHead_9";
		break;
		case "DMSkelHead_9":
			dialog.text = "�� ������, ������� � ��� � ����� ��������� �������, �������� �������, �������, �� �����. ��� ���, ��� ���� ������� ������ ������� �� ���������, �������� � ��� � ��������� ������ ���������� �� �� ���.";
			link.l1 = "� ���?";
			link.l1.go = "DMSkelHead_10";
		break;
		case "DMSkelHead_10":
			dialog.text = "��� �������� � ������������ ��������, ��� ��������� ��� ����� ����� �������. � ��������� � ���, ����� �� ��� �����, �� ��� ��������� ������� ��� ���! ������ �� �������.";
			link.l1 = "� �� �� ���������?";
			link.l1.go = "DMSkelHead_11";
		break;
		case "DMSkelHead_11":
			dialog.text = "��������. ��� ���� �� ������ ��� � ���� ���������� ������.\n��� ���, � ���� � ��� �����������. ��� ������ �������� ������� � ������ � ��� ���������, ��� ������ � ����������� � �����, ��� ���� �������� ������� ���-�� ��������.";
			link.l1 = "��� ����������?";
			link.l1.go = "DMSkelHead_12";
		break;
		case "DMSkelHead_12":
			dialog.text = "��, ������ ������� ��� ������ �� ����������� ����-����������. � �������, ��� ��� ����, �������� �� �� ��� ������ �������. ���� ���� ���������� �� �����, ��� ��� �����.\n������ � ����� ��� ����� �� � �������� ���, ��� �� �������� �� ���� ��������� ������� � ������� '������ ���������'.";
			link.l1 = "������, � ��� � ��������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			AddQuestRecord("MagicCity", "5");
			AddQuestUserData("MagicCity", "sSex", GetSexPhrase("��","���"));
			pchar.questTemp.MC = "toSeekSister"; //���� ������	
			LocatorReloadEnterDisable("Charles_town", "housePirate", false);
			//������ ��� �������
			sld = GetCharacter(NPC_GenerateCharacter("LizSheppard", "BaynesDaughter", "woman", "towngirl", 10, ENGLAND, -1, false, "quest"));
			sld.name = "��������";
			sld.lastname = "�������";		
			sld.dialog.filename = "Gothic_Quest\MagicCity.c";
			sld.dialog.currentnode = "LizBegin"; 
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");	
			ChangeCharacterAddressGroup(sld, "Charles_PirateHouse", "goto", "goto1");
		break;
		//�������� �������
		case "LizBegin":
			dialog.text = "������������, �������. ��� ������� ������������ ������ ��� � ���� ����?";
			link.l1 = "������������, ��������. ���� ����� " + GetFullName(pchar) + ". � ����"+ GetSexPhrase("��","��") +" ������������ � ���� �� �����... ����� ��������� ����.";
			link.l1.go = "LizBegin_1";
		break;
		case "LizBegin_1":
			dialog.text = "������ ��� �����������, �������.";
			link.l1 = "��������� ����� ����� �� �������� ��������� ��������� ��������� - ���-������. ����� ����� ���������� ������, �������� ������, � ������� ��, �������, �������, �������� ���� ��������� ���. ��� � � ������������� � ������"+ GetSexPhrase("","�") +".";
			link.l1.go = "LizBegin_2";
		break;
		case "LizBegin_2":
			dialog.text = "�� ���� �������, �������. �����������.";
			link.l1 = "�������� ������ ��� � ������.";
			link.l1.go = "LizBegin_3";
		break;
		case "LizBegin_3":
			dialog.text = "��� � ���� ������?";
			link.l1 = "�������� ��� ��������� ������ '������ ���������.";
			link.l1.go = "LizBegin_4";
		break;
		case "LizBegin_4":
			dialog.text = "����� ��� ����� ���� ������?";
			link.l1 = "���� � ���, ���� ����, ��� ������ ������ ��������� � ���� ��������... ������������� ��������� ��������, ���������� �����.";
			link.l1.go = "LizBegin_5";
		break;
		case "LizBegin_5":
			dialog.text = "��������� �������� � ������� ���-�������?!";
			link.l1 = "��, ��� ���. ��� �� ������ � ���������?";
			link.l1.go = "LizBegin_6";
		break;
		case "LizBegin_6":
			dialog.text = "������� ����! ���� � ���, ��� ������� ������� '������ ���������' - ����� ������� ��� �������. ��������� ����� � ������ ��� � ���������, ��� ������� ��������� ���� ������ � �������� ����������� ����.";
			link.l1 = "����������?";
			link.l1.go = "LizBegin_7";
		break;
		case "LizBegin_7":
			dialog.text = "�������. ���� � ���, ��� � ���� ���������� ����� ������� ��������. ��� ����, ������� ��������, ��� ����� �� ��������� ���������� �������� ����� � ����� �� ��������� �������!";
			link.l1 = "�-�, ��� ����� ��������, ����...";
			link.l1.go = "LizBegin_8";
		break;
		case "LizBegin_8":
			dialog.text = "��� ���, �� ���� ������� ������, � ���������� �� ������� � ������. �������, �� ������, ��� ���?";
			link.l1 = "��� ��!";
			link.l1.go = "LizBegin_9";
		break;
		case "LizBegin_9":
			dialog.text = "��, ��� ������ ������ � �����-��������, ������� � �������� ������ ������� �����. �� ��� �� �� �����, � ������ ������� ����� ������!..";
			link.l1 = "� ���� ��� �����"+ GetSexPhrase("","�") +", ��������. ������� � ��������������� ������������ ������� - ������� ������������. ��� ��� �� ������ ��� ������� � ��������?";
			link.l1.go = "LizBegin_10";
		break;
		case "LizBegin_10":
			dialog.text = "����� ��� ������� ������ ��������� ��� ������� �� ����� ��������������.";
			link.l1 = "�-��... ��, � ��� ������ ������?";
			link.l1.go = "LizBegin_11";
		break;
		case "LizBegin_11":
			dialog.text = "����� ��������� ���������� �����, �������� ����� ����. ������ � ��� ������� ����� ����� ���������.";
			link.l1 = "� ��� �� �������, ��� �� ���������?";
			link.l1.go = "LizBegin_12";
		break;
		case "LizBegin_12":
			dialog.text = "� ���������� ������ �������.";
			link.l1 = "��������, ��� ��� �� ��������� �� ���� ����������� ������? ������ ��� ��������� ���� �� ������� ���-�������?";
			link.l1.go = "LizBegin_13";
		break;
		case "LizBegin_13":
			dialog.text = "� �� ����\n������� �����, ������ ���� �����, � ��������, ��� � ��� ���-�� �����. � ���������� ���� � ������� ��������� ������. ��� ���� ������\n� ���������. ������ ���� ��������� � ������. ������ ����� � ������, ��� ��� ��� ������� '������ ���������'. � � ��������� ���!";
			link.l1 = "������, ����, �� - ������� ������� ������������. ����������� �������� �� ����� ����� �������� �� ������ ������ �� ������.";
			link.l1.go = "LizBegin_14";
		break;
		case "LizBegin_14":
			dialog.text = "��� �� �����, � ���������� �������� ��� ��������. ����� � ������ ������, ��� ����� � ���������, ��������� �������� '������ ���������' � �������� ���!";
			link.l1 = "���� ������, ��� ����������! ������� �������, ��� � ���� ���� ����� ������ �������.";
			link.l1.go = "LizBegin_15";
		break;
		case "LizBegin_15":
			dialog.text = "�������, � ����� ��� ���� ����� ��������"+ GetSexPhrase("��","��") +" � ����������. �� ���������, ��� ���� ����� ����� ����!\n������, ����� ����� ����, ��� �� ����������� �� ���� ��� �� �����, � ���� ������� ��� ��������� ���������� ����� ���� �������. ��� ��� �� ��� ����, ��� �� ���������.";
			if (CheckCharacterItem(pchar, "SkullAztecs"))
			{
				link.l1 = "���� ����� ��� � ����, ��������.";
				link.l1.go = "LizBegin_haveSkull";
			}
			else
			{
				link.l1 = "�� ��� ��, ���� ����, � �����"+ GetSexPhrase("","�") +" ���� ��������, ���� �� � ������ � ����� ����. ������, �� ��������, ��� ���� ����� ��������� � ��������� ������?";
				link.l1.go = "LizBegin_seekSkull";
			}
		break;
		
		case "LizBegin_SeekSkull":
			dialog.text = "������ ���. � ����������� ������� ������� ������������.";
			link.l1 = "�������. ���� ��� �������� ��������� ���� �����, �� � ������ ����� ���������� ����, � �����������.";
			link.l1.go = "LizBegin_16";
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
		break;
		case "LizBegin_16":
			dialog.text = "������, �������, � ���� ��� �����. ������� ���.";
			link.l1 = "�� �� �� ���...";
			link.l1.go = "exit";
			AddQuestRecord("MagicCity", "6");
			AddQuestUserData("MagicCity", "sSex", GetSexPhrase("��","��"));
			AddQuestUserData("MagicCity", "sSex1", GetSexPhrase("��","���"));
			pchar.questTemp.MC = "toSeekSkull"; //���� ������	
			NextDiag.TempNode = "LizCheckSkull";
		break;

		case "LizBegin_haveSkull":
			dialog.text = "��� ��� ������� ��� ���������?!";
			link.l1 = "��� ������ �������... ���������� ���, ��� ������ ������.";
			link.l1.go = "LizCheckSkull_1";
		break;
		//�������� ������
		case "LizCheckSkull":
			dialog.text = "�� �������� ���������� �����, �������?";
			if (CheckCharacterItem(pchar, "SkullAztecs"))
			{
				link.l1 = "�� � ����, ��������.";
				link.l1.go = "LizCheckSkull_Ok";
			}
			else
			{
				link.l1 = "��� ���. �� � ��������� ���� �����.";
				link.l1.go = "exit";
			}
		break;
		case "LizCheckSkull_Ok":
			dialog.text = "��� ���-���� ������� ��������� ���!";
			link.l1 = "��� ���� �������, ����� � ���... ��� ������ ������, ����?";
			link.l1.go = "LizCheckSkull_1";
		break;
		case "LizCheckSkull_1":
			dialog.text = "������ � ��� ���� ���������� ��� ������ ���������. ��� ����� �������� ������ '������ ���������' �, ����������, ����� ��������� � ��������.";
			link.l1 = "��������� ��� �������, ��� �����, ��� ��� ��� ���������� �����, ������ ����� ������, ��� ����� �������� ������ ��������� �����. � ��� ������ - �� ��������...";
			link.l1.go = "LizCheckSkull_2";
		break;
		case "LizCheckSkull_2":
			dialog.text = "�������, ��� ����� ������ ��������� ����� � ����� � �������� '������ ���������'. � ���� ������ ��������� ������ ��������� ���� �� ����.";
			link.l1 = "����� ����... � ��� ������ ���� ������?";
			link.l1.go = "LizCheckSkull_3";
		break;
		case "LizCheckSkull_3":
			dialog.text = "�� ����. ������ �����, ������� �������� �� ���� ����� �� �������. �������� ������������ ������, ���� ������ �� �� ����������.";
			link.l1 = "����. �� ��� ��, ������� ��������.";
			link.l1.go = "exit";
			SetAvroraInWorld();
			AddQuestRecord("MagicCity", "7");
			pchar.questTemp.MC = "toSeekQueen"; //���� ������	
			NextDiag.TempNode = "LizSeekQueen";
		break;
		case "LizSeekQueen":
			if (pchar.questTemp.MC == "over")
			{
				dialog.text = "�� ���-���� ����� ���������!";
				link.l1 = "��, ��� ��� �������.";
				link.l1.go = "LizOver";
			}
			else
			{
				dialog.text = "�������, �� ����� ������ '������ ���������'?";
				link.l1 = "��� ���... ���������, ��� ������ ���� ������?";
				link.l1.go = "LizCheckSkull_3";
			}
		break;

		case "LizOver":
			dialog.text = "�������, ��� � ���� �� ������!";
			link.l1 = "������, ��������, � ������ �� �� ������� ��� �����, ��� ������� ��� ������� - ���� ������?";
			link.l1.go = "LizOver_1";
		break;
		case "LizOver_1":
			dialog.text = "���, �� ������ ������...";
			link.l1 = "�������. �� - ���� ������ ����, ��� �������... ������, ������ ��������� �� ��� �� ������ ��������.";
			link.l1.go = "LizOver_2";
		break;
		case "LizOver_2":
			dialog.text = "����� ������. � �����, ��� �� ������� � ��� ������������, � �� ��� ������ ���� ������� ���� �������� � ���������� �����.";
			link.l1 = "��, � ����������.";
			link.l1.go = "exit";
			npchar.lifeDay = 30;
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");	
			NextDiag.TempNode = "LizOver_end";
		break;
		case "LizOver_end":
			dialog.text = "�� ���-�� ������, �������?";
			link.l1 = "�� ���, ������ ����������...";
			link.l1.go = "exit";
		break;
		//������ �� ��������
		case "DanAbordage":
			dialog.text = "������ ���� ���� �����!";
			link.l1 = "��, ����, ��� �� ����?! ������� ���������, ��� �� ���������� �� ����, ��� ����������� �����?!";
			link.l1.go = "DanAbordage_1";
		break;
		case "DanAbordage_1":
			dialog.text = "��� �� � ��� �������������. �� �����"+ GetSexPhrase("","�") +" �� ��� ������!";
			link.l1 = "��� ����� ���� ������� � ����������� �����, ����� �������� � ���� �� ����!.. ���������, ����� ���� ������ ���?";
			link.l1.go = "DanAbordage_2";
		break;
		case "DanAbordage_2":
			dialog.text = "��� ��� ���� ���.";
			link.l1 = "��� �� � ���� ������� ������ �������� �������... � �-�� �����"+ GetSexPhrase("","�") +", ��� ��� ������� � �������!";
			link.l1.go = "DanAbordage_3";
		break;
		case "DanAbordage_3":
			dialog.text = "�� ������ ��� ������ ��������?";
			link.l1 = "������ �� �� ��������� � �������� ������ �����. � ��, ��� � �������, �� ������� ������ ������ �������?";
			link.l1.go = "DanAbordage_4";
		break;
		case "DanAbordage_4":
			dialog.text = "�����! ��������� ��� ��������, ��� �� ���"+ GetSexPhrase("��","��") +"?";
			link.l1 = "���� ����� ������� " + GetFullName(pchar) + ". � ��������"+ GetSexPhrase("","�") +" ��� ������ ��� ����, ����� ����� ���������. ���������� ���, ��� ����������, ��� �� ��� ���� ��������� ���������� ���� �������.";
			link.l1.go = "DanAbordage_5";
		break;
		case "DanAbordage_5":
			dialog.text = "��� ��� ��� ��� ���! � � �� ��� ��� � �� �����, ��� ��� �� ������.\n���� ���� �� ���� ����������� ������, � ������ ���������, � ���-�������. ��, ��������, ������, ��� � ���� �������� ��������. �������� �� ��, ��� ������� ��������, � ������, ����� ������� ����, �������� ���� ����� ���� ��������� '������ ���������'.\n"+
				"���-�� ��� �� ����-������ � ������ �������, �� ����� ���� ������. ��� ���� �������, ������ ������� ���� ��� �� �������. � ������� �������� �� ������� ������-�� �������� �������. � ���������, � ������ �� ����, ����� �� ��� ��������� � ���������. ������� ����� ������� ���, � ������ ������� ����. ����������� �� ��� ���, ��� ������ - ����� ��� �������� ������.\n"+
				"�������, ��� ������ ���������� � ��������� �� �����. � ���-�������, �� ����� ���������� ������, � �������, ��� ��� �� ������� ������� �� ����� ����������, ��� � �������� ���. � �����, �������� ���������. �� ���� ������� ������ �������� �������� � ��������� ������� � �����. ��������, ��� �������� ���� ��������.\n"+
				"������ ������ ������������� �����. ��� ������ ������ �� ������ �������� � �����, ������ �� �������� ��������� ������� ������ � ������, �������� �������� �������, � �������� ������� �������, ��� � � ��� ������� ������ ��������, ��������� ������� ׸���� ��������� ������� ������. ����� ������ �������.";
			link.l1 = "����� �������������� ����������� ��������.";
			link.l1.go = "DanAbordage_6";
		break;
		case "DanAbordage_6":
			dialog.text = "��� ������, ��� ������ ����������. �� � ����� �������� �� ����� ���� � ����. �� � ����� ������ �� ���� ������� ���� ���� ����������. �������, � ������� ������ ������� � ���� � ����. � ������ �������� ������ ��, ��� ��� ��������������.";
			link.l1 = "� ����� �� ������, ��� ��������� - �� �����...";
			link.l1.go = "DanAbordage_7";
		break;
		case "DanAbordage_7":
			dialog.text = "� �� �� ����. ���� ����������� ��� � �������, ��� �� �����-�� ��� ������� � �� ����� ����������� � ��������� �������, � �� ��-�� ���������� ������ �������. ��������� �� �� ��������� ������������� � ����� ����� ̸�����. �� � ���� ��������� � ������, ��� ���� ������ ����������� ��� �������� ������. ����������� ���� ��� ����, ����� ������ ����� �����! ";
			link.l1 = "�����������. ������, ��������� ���� �� ������ �� ���, �� � �� ������� ���-�������.";
			link.l1.go = "DanAbordage_8";
		break;
		case "DanAbordage_8":
			dialog.text = "��� ������!";
			link.l1 = "��� �������, ������, ��� �������� ������ ��� � �������, ��� �������� � ��� �����. � ��� ������ �����������.";
			link.l1.go = "DanAbordage_10";
		break;
		case "DanAbordage_10":
			dialog.text = "������� ��������! �� ��, ���� ����� ��� �������� �� ������\n��� ���, �������, ���� �� ������ ������� ���������, �� ������� ���!";
			link.l1 = "������, ��� ���� ��� �������. ��� ����� ���� ��������� ���������� ����� �������������� ������� � �������� ������� '������ ���������', ��� � ������"+ GetSexPhrase("","�") +".";
			link.l1.go = "DanAbordage_11";
		break;
		case "DanAbordage_11":
	PlaySound("VOICE\Russian\GOTHIC\GG\OPENADANOSTEMPLE.wav");
			dialog.text = "��������� �����? � ������ �� ����� ��������?";
			link.l1 = "�����, ��� ���. ��� ���������.";
			link.l1.go = "DanAbordage_12";
		break;
		case "DanAbordage_12":
			dialog.text = "�������, ��� � ���� ������������� ��� �� ��������� ������?";
			link.l1 = "����������� ������... ����, ������, � ���� ���� � ��� ������� ����������� - ����� �� ��� ��������. � "+ GetSexPhrase("�����","����� �� �������-������") +", ��� � ��. �������, �� �����������.";
			link.l1.go = "DanAbordage_13";
		break;
		case "DanAbordage_13":
			dialog.text = "�� ��� ��, ������ ���? � ��������.";
			link.l1 = "�������!";
			link.l1.go = "DanAbordage_14";
		break;
		case "DanAbordage_14":
			//������ ���� ���-�����  -->
			DeleteAttribute(NullCharacter, "capitainBase.Avrora");
			//<-- ������ ���� ���-�����
			AddQuestRecord("MagicCity", "8");
			pchar.questTemp.MC = "over"; //���� ������
			sld = GetCharacter(NPC_GenerateCharacter("AvroraOff", "Avrora_1", "woman", "Avrora", 30, PIRATE, -1, true, "quest"));
			sld.name = "������";
			sld.lastname = "�������";
			sld.greeting = "Gr_Avrora";
			sld.Dialog.Filename = "Enc_OfficerGirl.c";
			sld.quest.meeting = true;
			sld.rank = 35;
			sld.MultiFighter = 2.0; // ������������
			sld.MultiShooter = 2.0;
			sld.monster = false; // ������� ������
			sld.sex = "woman"; 
			sld.viper = false;
			SetSelfSkill(sld, 90, 55, 1, 50, 75);
			SetShipSkill(sld, 95, 10, 80, 85, 80, 20, 65, 55, 73);
			SetSPECIAL(sld, 6, 9, 9, 10, 8, 8, 10);
			SetCharacterPerk(sld, "Energaiser"); // ������� ���� ���� 1.5 � �������� �������, ������ �� � ������ �������
	           SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2"); 
			GiveItem2Character(sld, "pistol9");
			sld.equip.gun = "pistol9";
			GiveItem2Character(sld, "blade_19");
			sld.equip.blade = "blade_19";
			GiveItem2Character(sld, "spyglass3"); 
			EquipCharacterbyItem(sld, "spyglass3");
			GiveItem2Character(sld, "cirass6"); 
			EquipCharacterbyItem(sld, "cirass6"); 
			GiveItem2Character(sld, "bussol"); 
			EquipCharacterbyItem(sld, "bussol");
			sld.SuperShooter  = true;
			LAi_SetCharacterUseBullet(sld, "bullet"); 
			TakeNItems(sld, "bullet", 50); 
			AddItems(sld, "gunpowder", 50); 
			sld.quest.OfficerPrice = sti(pchar.rank)*500;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(sld.id);
			sld.OfficerWantToGo.DontGo = true; //�� �������� ����
			sld.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			QuestAboardCabinDialogNotBattle(); 
            DialogExit();
		break;	
	}
}

void SetAvroraInWorld()
{
	//������� �����
	ref sld = GetCharacter(NPC_GenerateCharacter("Avrora", "Avrora_2", "woman", "Avrora", 45, PIRATE, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.dialog.filename   = "Gothic_Quest\MagicCity.c";
	sld.dialog.currentnode   = "DanAbordage";
	sld.greeting = "";
	sld.GenQuest.CrewSkelMode = true; //������� - ������� 
	sld.Ship.Mode = "Skel";
	FantomMakeCoolSailor(sld, SHIP_FRIGATE_QUEST, "������ ���������", CANNON_TYPE_CANNON_LBS32, 90, 90, 90);
	SetShipSailsFromFile(sld, "ships/parus_pearl.tga");
	SetSailsColor(sld, 8);//������ ������ �����	

	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	sld.DontRansackCaptain = true; //�� ���������
	sld.monster = true; // ������� ������
	sld.sex = "Skeleton"; 
	sld.viper = true;
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "ProfessionalDefense"); 
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ShipEscape");
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "ByWorker2");
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2");
SetCharacterPerk(sld, "Doctor3"); 
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_POWDER, 10000);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_FOOD, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_GOLD, 1500);
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "blade_19");
sld.equip.blade = "blade_19";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50);
sld.SuperShooter  = true;
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 
sld.MultiFighter = 2.5; // ������������
sld.MultiShooter = 2.5;
	//� ������� ������ ����
	string sGroup = "AvroraGroup";
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	sld.quest = "InMap"; //������ ���� �������� ����
	sld.city = "Maracaibo"; //��������� �������, �� ����� ������� � �������� ������
	sld.cityShore = GetIslandRandomShoreId(GetArealByCityName(sld.city));
	sld.quest.targetCity = SelectAnyColony(sld.city); //��������� �������, � ����� ������� �� ������
	sld.quest.targetShore = "Shore131";
	Log_TestInfo("������ Queen ����� ��: " + sld.city + " � ���������� �: " + sld.quest.targetShore);
	//==> �� �����
	sld.mapEnc.type = "trade";
	//����� ���� ��������� �� �����
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "������ '������ ���������'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //���� ������� ���� � �������
	Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, daysQty);
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "Avrora"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = "none"; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = "MagicCity"; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "MagicCity"; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

