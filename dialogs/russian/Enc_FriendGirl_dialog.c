void ProcessDialogEvent()
{	
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iRank, iMassive;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{		
		case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "First time":
			dialog.text = LinkRandPhrase("�������, ��� ������, ��� � ��� ���������!",
				"�������-�� ���� ���-�� �������� �����!!",
				"���� ���, ��� � ���� ��� ������!");
			Link.l1 = LinkRandPhrase("��� ���������, ������?",
				"����� ��������, ��������?",
				"�� ���� ��� �����������, ��� ������ ��� �������� ���������. ��������-�� ��� ����������, ��� ��� � ���� ���������?");
			Link.l1.go = "Step_1";			
		break;
		case "Step_1":
			dialog.text = LinkRandPhrase("��� ������� - ����� �����������, ��� ������� � ����������� �������!",
				"��� ������� ������� � ����������� �������, � ��� ��������� ����� �� ���!",
				"��� ������� ������� � ����������� �������!");
			Link.l1 = "������ ����� ��� ������� ����?!";
			Link.l1.go = "Step_2";			
		break;
		case "Step_2":
			dialog.text = "��, ��� ������ �� ������! ��� �������� ���-��, ��� ��� ����� ���� ����������, � ������� ����� �������� ������, ��� � �������. �� � �� ����� ����, � ���� �� �����...";
			Link.l1 = "� ��� ���������, ������ ���� ��� ������.";
			Link.l1.go = "Step_3";			
		break;		
		case "Step_3":
			dialog.text = "��� �� ��� ������ ������? ����� ���, ���� ����� �������, �������� ��!";
			Link.l1 = "������, � ��������� � ����. � �� ��� �����, ������ ��� ������������� �����.";
			Link.l1.go = "Step_agree";
			Link.l2 = "��� ���� ��������, ��� �� ��� ���� ���. ������...";
			Link.l2.go = "Step_disAgree";
		break;

		case "Step_agree":
			pchar.quest.Enc_FriendGirl_after.over = "yes";
			if (rand(1))
			{ //���������
				LAi_LocationDisableMonGenTimer(pchar.GenQuest.EncGirlF.locationId, 1); //�������� �� �������� 1 ����
				LAi_LocationDisableOffGenTimer(pchar.GenQuest.EncGirlF.locationId, 1); //�������� �� ������� 1 ����
				LocatorReloadEnterDisable(pchar.GenQuest.EncGirlF.locationId, "reload2", true);
				pchar.GenQuest.OpenTheRopeExit = pchar.GenQuest.EncGirlF.locationId; //���� ��� �������� �������
				string model[10];
				model[0] = "citiz_41";
				model[1] = "citiz_42";
				model[2] = "citiz_43";
				model[3] = "citiz_44";
				model[4] = "citiz_45";
				model[5] = "citiz_46";
				model[6] = "citiz_47";
				model[7] = "citiz_48";
				model[8] = "citiz_49";
				model[9] = "citiz_50";
				i = 0;
				while(i < 3)
				{
					iMassive = rand(9);
					if (model[iMassive] != "")
					{
						iRank = sti(pchar.rank) - rand(5) + rand(5);
						if (iRank < 1) iRank = 1; 
						sld = GetCharacter(NPC_GenerateCharacter("CaveGandMan" + i, model[iMassive], "man", "man", iRank, PIRATE, 1, true, "marginal"));
						SetFantomParamFromRank(sld, iRank, true);
						sld.SaveItemsForDead = true;
						sld.DontClearDead = true; 
						sld.money = iRank*200+1000+rand(500);
						LAi_SetWarriorType(sld);
						LAi_warrior_SetStay(sld, true);
						LAi_group_MoveCharacter(sld, LAI_GROUP_MONSTERS);
						ChangeCharacterAddressGroup(sld, pchar.GenQuest.EncGirlF.locationId, "quest", "quest" + i);
						i++;
						model[iMassive] = "";	
					}
				}
			}
			else
			{ //� ������ ����� 
				sld = GetCharacter(NPC_GenerateCharacter("UndergroundGirl", "women_"+(rand(5)+11), "woman", "towngirl", 5, PIRATE, 1, false, "citizen"));
				sld.dialog.filename = "Enc_FriendGirl_dialog.c";
				int iTemp = rand(1);
				sld.dialog.currentnode = "Underground1";//+ iTemp; //����� ������ ��������� �����: 0-��������, 1-���� ������
				sld.greeting = "Enc_RapersGirl_" + (iTemp+1); //�����. �������
				LAi_SetStayType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				ChangeCharacterAddressGroup(sld, pchar.GenQuest.EncGirlF.locationId, "monsters", "monster"+(rand(9)+1));
			}
			LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Step_disAgree":
			ChangeCharacterComplexReputation(pchar,"nobility", -3);
			LAi_SetCitizenTypeNoGroup(npchar);
			pchar.quest.Enc_FriendGirl_after.over = "yes";
			NextDiag.CurrentNode = "FackYou";
			DialogExit();
		break;			
		case "FackYou":
            NextDiag.TempNode = "FackYou";
            dialog.text = "�� ���� ������������� � "+ GetSexPhrase("����� ��������� ��������","����� ��������� ������") +". ���������� ������!";
			Link.l1 = "���, ������...";
			Link.l1.go = "exit";
		break;

		case "Underground0": //����� ������� �����������
            dialog.text = "���� ���, ��� � ���� ��� ������!!";
			Link.l1 = "��� ���������, ���������?";
			Link.l1.go = "Underground0_1";
		break;
		case "Underground0_1": 
            dialog.text = "� ����������� �����! �������, ��� �� ��� ���� �������!!!";
			Link.l1 = "��, ������-�� ��� � �������. ��� �� ����, � ������ ����. ��� ��������� �� ����������� - ������ �����, � ����� ������ � ���� �� "+ GetSexPhrase("�����","������") +"!";
			Link.l1.go = "Underground0_2";
		break;
		case "Underground0_2": 
            dialog.text = "��� �������, " + GetAddress_Form(NPChar) + ".";
			Link.l1 = "������.";
			Link.l1.go = "exit";
			npchar.LifeDay = 0;
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			ChangeCharacterComplexReputation(pchar,"nobility", 4);
		break;

		case "Underground1": //������ �������
            dialog.text = "���� ��, ��� ����-�� ���� ���� �� ����� ����������!";
			Link.l1 = "���������, �� ��� ��� �������?";
			Link.l1.go = "Underground1_1";
		break;
		case "Underground1_1": 
            dialog.text = "�� ���� ����!";
			Link.l1 = "���, ����� �� ������� ����...";
			Link.l1.go = "Underground1_2";
		break;
		case "Underground1_2": 
            dialog.text = "�� ��� ��������... "+ GetSexPhrase("���","���") +" �� �� ������ ����� �������, �� ���� ��� ���� ���.";
			Link.l1 = "���, � ��� �� ���� ����, ����������, �� ��� ������ ������� ���� ������ ������� �������...";
			Link.l1.go = "Underground1_3";
		break;
		case "Underground1_3": 
            dialog.text = "��� ���� ������! ���� �� ������ ���������� ������, � ������, ��� � ����� ��.";
			Link.l1 = "�� ��, �� ���� �� ����� ��. ���� � ����!";
			Link.l1.go = "Underground1_4";
		break;
		case "Underground1_4": 
            dialog.text = "������� � ���������! �� � ������, ���������� � ���� � ������.";
			Link.l1 = "�� �����, ��� ���� ��� ������ �� �����...";
			Link.l1.go = "Underground1_5";
		break;
		case "Underground1_5": 
            dialog.text = "�� �����!";
			Link.l1 = "����� ������ � ���� �������.";
			Link.l1.go = "exit";
			NextDiag.TempNode = "Underground1_again";
		break;
		case "Underground1_again": 
            dialog.text = "����� ��? ����������, ������"+ GetSexPhrase("","�") +" ���...";
			Link.l1 = "��...";
			Link.l1.go = "exit";
			NextDiag.TempNode = "Underground1_again";
		break;

	}
}
