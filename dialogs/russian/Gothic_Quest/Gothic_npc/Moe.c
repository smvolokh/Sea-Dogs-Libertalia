// �� - ��������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_AERGER_01_01.wav");
			dialog.text = "�������, � ������ ��������� ��������, ��� ��� ��������� " + GetSexPhrase("������","�����") + "?";
			link.l1 = "���������, � ������� �� � ����������.";
			link.l1.go = "Exit";
			link.l2 = "���� �� " + GetSexPhrase("��������","������") + " ������, ������.";
			link.l2.go = "Moe_16";			
			NextDiag.TempNode = "First time";
		break;

		case "First time2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_KNEIPE_01_01.wav");
			dialog.text = "���������, ���� ��� ������ ��� ������� � �����, ��� ��� ����� ���� ��������� ����� ������ � ������ ��� �������� �� ����� ��������� ����.";
			link.l1 = "���������, � ������ �����" + GetSexPhrase("","�") + " ������ ����!";
			link.l1.go = "Moe_7";
			link.l2 = "����� �������, ��� �� ���� ������ ���������.";
			link.l2.go = "Moe_9";
			link.l3 = "�, ��� ��� �������� �������, � � ������" + GetSexPhrase("","�") + " ��� �� ������ �����������!";
			link.l3.go = "Moe_14";
			link.l4 = "������, ��� �� ��� � ���� ����!";
			link.l4.go = "Moe_15";
			link.l5 = "�������, ��� �� ������ ������ ��� �������� ������� ���� ���� �����...";
			link.l5.go = "Moe_22";
			NextDiag.TempNode = "First time2";
		break;


		case "Moe":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_01_01.wav");
			dialog.text = "���� ������ ����� ������, �����" + GetSexPhrase("","��") + ".";
			link.l1 = "";
			link.l1.go = "Moe_001";
		break;

		case "Moe_001":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ��� �� ������!";
			link.l1.go = "Moe_1";
		break;

		case "Moe_1":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_01_00.wav");
			dialog.text = "��, � �� ���� ����, ���� ���� ����� �����! �� ����� � �����.";
			link.l1 = "";
			link.l1.go = "Moe_002";
		break;

		case "Moe_002":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_15_00.wav");
			dialog.text = "";
			link.l1 = "���, � �� ��� � �����.";
			link.l1.go = "Moe_2";
		break;

		case "Moe_2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_01.wav");
			dialog.text = "� ��� � �������, �� ��� ��� �� �����, �� ����� ������� ����� � ����.";
			link.l1 = "";
			link.l1.go = "Moe_003";
		break;

		case "Moe_003":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_AERGER_15_00.wav");
			dialog.text = "";
			link.l1 = "�� �������� ������� ��� ��������?";
			link.l1.go = "Moe_3";
		break;

		case "Moe_3":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_02.wav");
			dialog.text = "��� ��� �� ����� �������, � ���� ���� ������� ���������� �����������, �� ���� ��� 50 ������� ����� � ������ ���� ������.";
			link.l1 = "50 ����� �� ���� � �����?";
			link.l1.go = "Moe_4";
		break;

		case "Moe_4":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_03.wav");
			dialog.text = "��� ����� �� ��������� ���� � �����.";
			link.l1 = "";
			link.l1.go = "Moe_004";
		break;

		case "Moe_004":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_KNEIPE_15_00.wav");
			dialog.text = "";
			link.l1 = "��, � �� ���� ���� � �����.";
			link.l1.go = "Exit_2";
		break;

		case "Moe_7":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_RUHIG_15_00.wav");
			dialog.text = "��������� � ������ ����� ������ ����!";
			link.l1 = "";
			link.l1.go = "Moe_007";
		break;

		case "Moe_007":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_RUHIG_01_01.wav");
			dialog.text = "������, �� ��� ����� ������ ���� 50 �����, ��� ����� �� ����.";
			link.l1 = "";
			link.l1.go = "Moe_008";
		break;

		case "Moe_008":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_15_00.wav");
			dialog.text = "";
			link.l1 = "������ � �������.";
			link.l1.go = "Moe_009";
		break;

		case "Moe_009":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		                   AddMoneyToCharacter(pchar, -50);
			dialog.text = "";
			link.l1 = "��� �����.";
			link.l1.go = "Moe_8";
		break;

		case "Moe_8":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "������, ����.... �� ������ ����!";
			link.l1 = "";
			link.l1.go = "Exit_3";
		break;

		case "Moe_9":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_15_00.wav");
			dialog.text = "";
			link.l1 = "����� �������, ��� ������ �� ���� ���������!!!";
			link.l1.go = "Moe_0010";
		break;

		case "Moe_0010":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_01.wav");
			dialog.text = "��, ��������� ����� ���, � �� ������ ������ �� ����� �� ������.";
			link.l1 = "�� � ������ ��!";
			link.l1.go = "Moe_10";
		break;

		case "Moe_10":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_02.wav");
			dialog.text = "�� ���������� � �������� �������� �����" + GetSexPhrase("","��") + ", �� ��� �� ��������� �� ��������� �������� ����� � ����� �� ����.";
			link.l1 = "";
			link.l1.go = "Moe_11";
		break;

		case "Moe_11":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_03.wav");
			dialog.text = "��� ������ ������ ����������� � ������� ������, ���������, ����� ���� ������ �� � �.";
			link.l1 = "";
			link.l1.go = "Moe_0012";
		break;

		case "Moe_0012":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_15_02.wav");
			dialog.text = "";
			link.l1 = "�� � ���� ��� � ����� ������� ������?";
			link.l1.go = "Moe_12";
			link.l2 = "������ � �������.";
			link.l2.go = "Moe_009";
		break;


		case "Moe_12":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_03.wav");
			dialog.text = "��� �� �����, ������ ����� ��� ��, ��� � ���� ����.";
			link.l1 = "�� ���� �� �� ��������!";
			link.l1.go = "Moe_0013";
		break;

		case "Moe_0013":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_VERGISSES_15_00.wav");
			dialog.text = "";
			link.l1 = "������ �� ����, �� �� �������� �� �����!";
			link.l1.go = "Moe_13";
		break;

		case "Moe_13":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_VERGISSES_01_01.wav");
			dialog.text = "����� � ������ ��, ��� � ���� ����, � �� ������ ������ �����������" + GetSexPhrase("��","��") + " �� ����� ����� �� ����.";
			link.l1 = "";
			link.l1.go = "Moe_16";
		break;


		case "Moe_14":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_WITZ_15_00.wav");
			dialog.text = "";
			link.l1 = "��, ��� ��� �������� �������, � � �� ������ ��� �� ������ �����������.";
			link.l1.go = "Moe_0014";

		break;

		case "Moe_0014":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_WITZ_01_01.wav");
			dialog.text = "��, ����� ���� ������� ��� ���� " + GetSexPhrase("������","�����") + ", ��� � �������� ���� ������ ��������� �� ��������.";
			link.l1 = "";
			link.l1.go = "Exit_2";
			NextDiag.TempNode = "First time2";
		break;


		case "Moe_15":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_15_00.wav");
			dialog.text = "";
			link.l1 = "������, ��� �� ��� � ���� ����!";
			link.l1.go = "Moe_0016";
		break;

		case "Moe_0016":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "�������, ��� �� ���" + GetSexPhrase("��","��") + " ����" + GetSexPhrase("��","��") + " �� ������ ������ �� ���������� ������ ��������.";
			link.l1 = "";
			link.l1.go = "Moe_16";
		break;


		case "Moe_22":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_PRUEGEL_15_00.wav");
			dialog.text = "";
			link.l1 = "�������, ��� �� ������ ������ ��� �������� ������� ���� ���� �����?";
			link.l1.go = "Moe_0022";
			npchar.quest.Moe_win = 0;
		break;

		case "Moe_0022":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_PRUEGEL_01_01.wav");
			dialog.text = "������ ����������� �����" + GetSexPhrase("","��") + ", ������ ��� �� ��� �� ������" + GetSexPhrase("��","��") + "?";
			link.l1 = "";
			link.l1.go = "Moe_16";
			npchar.quest.Moe_win = 0;
		break;
		
		case "Moe_16": // �����
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ������ �������������
			LAi_SetCheckMinHP(pchar, 1, true, "Moe_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Moe_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");	
	                                      DoQuestFunctionDelay("MOE_CHEERFRIEND", 0.3);
		break;

		case "Moe_17":
	                                      PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_05.wav");
			dialog.text = "����, ������� ������� ��� �� �������!";
			link.l1 = "";
			link.l1.go = "Moe_17_1";
                                                          LAi_LocationDisableOfficersGen("Roseau_town", false);//�������� ���������
		break;

		case "Moe_17_1": // ����� �� � ������� ����
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "������, ����.... �� ������ ����!";
			link.l1 = "";
			link.l1.go = "Moe_17_2";
		break;

		case "Moe_17_2": // ����� �� � ������� ����
	                                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_4.wav");
			dialog.text = "";
			link.l1 = "�������� � ������! ������� �� ��������� ���� ����?";
			link.l1.go = "Exit_1"; // ���� �� �����
		                        sld = characterFromId("Moe");
		                        LAi_SetGroundSitType(sld);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		LocatorReloadEnterDisable("Roseau_town", "reload13", false);//������� �������
		break;
		
		case "Moe_18": // ����� �� �� ������� ��� �������� ����
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "������, ����.... �� ������ ����!";
			link.l1 = "";
			link.l1.go = "Moe_18_1";
		break;

		case "Moe_18_1": // ����� �� �� ������� ��� �������� ����
	                                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_4.wav");
			dialog.text = "";
			link.l1 = "����� � ���� ������! ������� �� ��������� ���� ����?";
			link.l1.go = "Exit_1"; // ���� �� �����
		                        sld = characterFromId("Moe");
		                        LAi_SetGroundSitType(sld);
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		LocatorReloadEnterDisable("Roseau_town", "reload13", false);//������� �������
		break;
		
		case "Moe_19": // ������ ������ ���
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "�������, ����� ����������, � ������� �����������.";
			link.l1 = "�� �� ������, �� � ����....!";
			link.l1.go = "Moe_22";
			link.l2 = "�� ��� ���������!";
			link.l2.go = "Exit_2"; // ���� �� �����

		break;
		
		case "guide_20": // ������ ������ ���
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "�������, ����� ����������, � ������� �����������. ��� �����!";
			link.l1 = "����� ����, ������, � � ������� �������� ���� ����!";
			link.l1.go = "Moe_22";
			link.l2 = "���, � ����, �������, ��������.";
			link.l2.go = "Exit_2"; // ���� �� �����
			
		break;
		
		case "Moe_21": // ������ ������ ���
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
			dialog.text = "�������, ����� ����������, � ������� �����������. ��� �����!";
			link.l1 = "���, � ���� ����������?";
			link.l1.go = "Exit_4"; // ���� �� �����
		break;
				
		case "Exit_1":
		                  sld = characterFromId("Moe");
                                                         LAi_SetActorType(sld);
                                                         LAi_ActorAnimation(sld, "Ground_StandUp", "Moe_Exit_1", 3.5);
			DialogExit();
		break;

		case "Exit_2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_01_01.wav");
			NextDiag.TempNode = "First time2";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_3":
	                                                LocatorReloadEnterDisable("Roseau_town", "reload13", false);
                                                                        AddMoneyToCharacter(pchar, -50);
			NextDiag.TempNode = "First time2";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_4":
  			RemoveAllCharacterItems(PChar, true);
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}