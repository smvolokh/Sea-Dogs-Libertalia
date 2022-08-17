// ������ �������� - ������������� ��������� �����
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
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbySeekIsland" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "������ ����! ���� ����� ������ ��������. � �� - ������� " + GetFullName(pchar) + "?";
					link.l1 = "���������� �����. ������ ��� �������� ��� ���? �� �����, ����� � �����-���� ���������� � ����.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					dialog.text = "��� ��� ������, �������. ���� �� ����� ��������� ������, �� ������ ���������� ����? ����� �� ������ � ���?";
					link.l1 = "��, ������ ��������. ������ ��� �������� � ����. �����, ��� ������ �� - �� ���� ��� � ���� ���������� � �����-�� ������� �����.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "�� ���-�� ��� ������ ��� �������, �������?";
				link.l1 = "���, ������ ��������. � ��� �����.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "JoakimMeeting" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "������ ����! ���� ����� ������ ��������. � �� - ������� " + GetFullName(pchar) + "?";
					link.l1 = "���������� �����. ������ ��� �������� ��� ���? �� �����, ����� � �����-���� ���������� � ����.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					dialog.text = "��� ��� ������, �������. ���� �� ����� ��������� ������, �� ������ ���������� ����? ����� �� ������ � ���?";
					link.l1 = "��, ������ ��������. ������ ��� �������� � ����. �����, ��� ������ �� - �� ���� ��� � ���� ���������� � �����-�� ������� �����.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "�� ���-�� ��� ������ ��� �������, �������?";
				link.l1 = "���, ������ ��������. � ��� �����.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "������ ����. �� ���-�� ������ �� ����?";
			link.l1 = "���. ����� ���� ��������, � ��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Landlady"://������� ����
			dialog.text = "���� �� � ������� �������, �� ������������ �� ������ ����. �� � ����.";
			link.l1 = "������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady";
		break;
		
		case "Landlady_1"://������� ����
			dialog.text = "���� �� � ������� �������, �� ��� ���. ����, � ����� �������� - �� ������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_1";
		break;
		
		case "Landlady_2"://������� ����
			dialog.text = "���� �� � ������� �������, �� ��� ���. �� ������ ����� �� �����.";
			link.l1 = "�������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_2";
		break;
		
		case "JoakimSeekSkull":
			PlaySound("VOICE\Russian\hambit\Joakim Merriman-01.wav");
			dialog.text = "� ������ ����� � ��� �������, �������. ���������, � ������, ��������� ��������� ��������� �������� � ������, � � �� ����� ���������� ��� ���� ���������� �������� ��� ��� ����. �� �������� �� � ���������� ������ �� ��� � ��� � � ����� ��������� ���������� �������� ������ ����� �����������?";
			link.l1 = "������� �� ����������� �� �������� ������� �����������. ������� ������� � ����������.";
			link.l1.go = "JoakimSeekSkull_1";
		break;
		
		case "JoakimSeekSkull_1":
			dialog.text = "���������. ��� ��� ������ �������� ������. �������� �� ����!";
			link.l1 = "...";
			link.l1.go = "JoakimSeekSkull_2";
		break;
		
		case "JoakimSeekSkull_2":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "Villemstad_houseSp1_room", "goto", "goto1", "JoakimInRoom", -1);
		break;
		
		case "JoakimSeekSkull_3":
			PlaySound("VOICE\Russian\hambit\Joakim Merriman-01.wav");
			dialog.text = "�� ���, ����� �� ����� �������� ����������. �� ���� ������ � ������ � ����� ������, �������� ������. � ��� ��� �������� ����, � - �� �������, ������� - �������� ��������� ���������� ������ ��������� � ���������. ���� ������ ���� ����������� ��������������, � � �������� ���� �������� ������������ � ��������� �� �� �����.";
			link.l1 = "��. � ��� �� ������ ����������� ���� � ����� ������ � ���� ������ ������?";
			link.l1.go = "JoakimSeekSkull_4";
		break;
		
		case "JoakimSeekSkull_4":
			dialog.text = "������� - ��� �����, � ��������� ���������� �� ��� � �����. � ���� � ��� ������������... �������, ��� � ��� �� �����! �� ��������� �� ���� ��� ����� �����������. �� ����� � ����. ������ ��������� �������� ��� � ����� ������, ������� �������� ������ � ��� �������� �� ����������� �������. �� ������� ��� � ���?";
			link.l1 = "��, ���� �����. �� ������ �������, � ������ �� �����, ��� ��� �� �����, ������ ����... � ���� ������ ��������� �����������, ��� ������ �������� ������� �� � ����.";
			link.l1.go = "JoakimSeekSkull_5";
		break;
		
		case "JoakimSeekSkull_5":
			dialog.text = "���, �������, ������� ��������� ��������, ������ ���������... ���������. ����� ������������� ����������. ��� ������� ��������, ���������� ����������� ������� �������� � ���� ����� ������� �����. ���������� ����� �� ������! � ��� ��� ��� ����� ���, � ������� ��������� ������� ���� ���������� ���, ������ ������� �������\n�� ������������� �� ������ �������, ��� ������� ������� ���� �������� �������. ��� �� ������ ���� � �����. ��������� ��� ��� ����, � � ������� ��� ����������� ����.";
			link.l1 = "�����������?! �� ������! � � ����� �� �������� �����, ������� ����� ���� �����!";
			link.l1.go = "JoakimSeekSkull_6";
		break;
		
		case "JoakimSeekSkull_6":
			dialog.text = "�� ������� ��� �� ��������� � ����� �����, �������... �� ��� ���? ��� ����������� ��� ��������������? �� ��� - ���������� �����, � ��� - ������� �����. �� �����?";
			link.l1 = "���, ����� ����� ���� ���������! �������, �� �����!";
			link.l1.go = "JoakimSeekSkull_7";
		break;
		
		case "JoakimSeekSkull_7":
			dialog.text = "�������, �������. ������� ����� ���� � ���������, ���������� ���� ��������� ������. �� ������� ����� ���� � ���� ����. ����� ��� ����� � �������!";
			link.l1 = "�������, ������ ��������. � �� �������� ��� ����� �����.";
			link.l1.go = "exit";
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			AddDialogExitQuestFunction("CheckIslandCoordinates");//��� ���-�� �� � ��������, ���� �� � ��� ���������� �������, � ����� ����� �������� �� ����������.
		break;
		
		case "JoakimFindSkull":
			PlaySound("VOICE\Russian\hambit\Joakim Merriman-02.wav");
			dialog.text = "�, ��! �� ������������� ����� ������ ������� ����... �� �������� ����, ����� ��� �� ���� ��������� - � ���� ����� �� ����������.";
			link.l1 = "���, ����������, �������. �������, � �� ������?";
			link.l1.go = "JoakimFindSkull_1";
		break;
		
		case "JoakimFindSkull_1":
			RemoveItems(PChar, "SkullAztec", 1);
			dialog.text = "��, ����������! ��, ��� ��. �����������, �������, ������ �����������! �������-�� �� � ����! � ������� ��� ���� ����� �������!";
			link.l1 = "��� ������ ��������� �����, ������ ��������?";
			link.l1.go = "JoakimFindSkull_2";
		break;
		
		case "JoakimFindSkull_2":
			AddMoneyToCharacter(pchar, 500000);
			dialog.text = "�, ��, �������! ��� ���� �����������. �������, �� �� ������ ����������.";
			link.l1 = "���������... ���� � �� ������� � �� ���������� ����, ��� ��� ��������� ������ ����� ������ ����� ���������.";
			link.l1.go = "JoakimFindSkull_3";
		break;
		
		case "JoakimFindSkull_3":
			dialog.text = "��������� ������? ��... ���... �������, ��� ������ �� ������������ ������� ������� �� ������� � ��������� ����� ���������. �� � ������ ������, � ���� ������ ��� ������� �� ������, ��������� ��� ������� ���\n������� ���, �������, ��� ��� �� ����������� ������. � ������ �� ������ � ���� ����������. ��� ����� ������������ � ������.";
			link.l1 = "����� �������, ������ ��������. �����, ��� ��������...";
			link.l1.go = "JoakimFindSkull_4";
		break;
		
		case "JoakimFindSkull_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Landlady");
			sld.Dialog.Filename = "Quest\HollandGambit\Joakim.c";
			sld.dialog.currentnode = "Landlady_2";
			SetFunctionTimerCondition("Caleuche_StartTotal", 0, 0, 30, false); // ������ �� �������
		break;
		
		case "JoakimSeekSkull_8":
			PlaySound("VOICE\Russian\hambit\Joakim Merriman-01.wav");
			dialog.text = "�� ���, ����� �� ����� �������� ����������. �������, ��� ��� ��������, �� ������ ������� � �������� �����, ������� ����� ������ ��������. ��� ������ �� ����� �������, ��� � �������, � ������ �������������... �� ��� �������.";
			link.l1 = "��. � ���� �� �������, ������... ��������?";
			link.l1.go = "JoakimSeekSkull_9";
		break;
		
		case "JoakimSeekSkull_9":
			dialog.text = "��� �� ������� � ���������, �� ��������� ������� � � ��� �������� � ��������������� � �� ���������� ����������, ���������� �� �� ����� ����������� ������� - �� ��������� � ����� ������������ ����� �����������...";
			link.l1 = "��, ��������, � ������������� ������� ������ �� ����. ����� ������� ��� ������� ����� ���� �������������? ��� ��������� ����������� ������� ����� ������� �����.";
			link.l1.go = "JoakimSeekSkull_10";
		break;
		
		case "JoakimSeekSkull_10":
			dialog.text = "��� ������� �� ����������? ������, ��� ���������� ���������� ����������� ���... �������, � ��� � ���. �������� ��������������� � ���� ����� �����������, ��� �������\n� ������� � ��������� � ������� ��� �������� �� ������. � �� �� �������������, ������ �� ���� ��� ���������, ����� � �����, ��� ���� ������ ����� �������� ���������� ����������� ��������� - ����������� ������ �� ������, ������� � ���������� ��� ����� ���! ���� �������� �� ��� ������ ������� ��� ������ �� ������ ������� ������������ �� �������, ��������������� �������� �� ������ ���� � ��������� �� �����\n��� ����� ���� ��������. ��������� ��� ���, � � ������� ��� �� ���� ����������� ����.";
			link.l1 = "�����������?! �� ������! � � ����� �� �������� �����, ������� ����� ���� �����!";
			link.l1.go = "JoakimSeekSkull_11";
		break;
		
		case "JoakimSeekSkull_11":
			dialog.text = "�� ������� ��� �� ��������� � ����� �����... �� ��� ���? ��� ����������� ��� ��������������? �� ��� - ���������� �����, � ��� - ������� �����. ����� ����, ������� ����� ��������, �� ������� ������� �������� � ��� ������. ���� �� ������ �������, ��� ������ ���� ������� ������� ����� ����... �� �����, �������?";
			link.l1 = "���, ����� ����� ���� ���������! �������, �� �����! ��� ������ ��� ��������� ���� ������, ���� �� ��������, ��� ������� �� �����, ��� �� ���������?";
			link.l1.go = "JoakimSeekSkull_12";
		break;
		
		case "JoakimSeekSkull_12":
			dialog.text = "���������� � ��������. �����, ��� ���-�� ������. ����������� � ���������. ���������, ���� �� � ����, ��� ����� ���� ������, � �� �� ��������� � ��� �� �������, � ���-������ ��������� �� ������������ ������.";
			link.l1 = "��� �������. ����� �������� �� ������ ������. �������, ��� ��� ��������, ��� ����� ���� ������... ��� ������ - ���� ������.";
			link.l1.go = "JoakimSeekSkull_13";
		break;
		
		case "JoakimSeekSkull_13":
			dialog.text = "������ ���. � ���, ��� �� ���� ����� ������, �������. ����� ��� ����� � �������. �� ������ ������� ����� ���� �����, � ���� ����.";
			link.l1 = "���������� �� ��������� ��� ����� �����, ������ ��������. �� ��������!";
			link.l1.go = "JoakimSeekSkull_14";
		break;
		
		case "JoakimSeekSkull_14":
			DialogExit();
			pchar.questTemp.HWIC.Self = "SeekAbiIsland";
			AddQuestRecord("Holl_Gambit", "3-55");
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload3", true);//������� ������� ���
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			NextDiag.CurrentNode = "First time";
		break;
		
		// �������
		case "caleuche":
			PlaySound("VOICE\Russian\LSC\Chymiset-03.wav");
			dialog.text = "������ ������ ������ ���������� �����! �� ������ ������� ��� ���� - ������ ��� ��������! � � ���� ����� � ����� ����������� � ��� ������!";
			link.l1 = "��� �� ������, ��������, ���� �� ���� ������? ����� ���� ��� ����� �� �����? �� ���, ����� ��������� ������ ����� ����?";
			link.l1.go = "caleuche_1";
			CreateLocationParticles("large_smoke", "goto", "goto37", 0.5, 0, 0, "");
		break;
		
		case "caleuche_1":
			dialog.text = "�����, ������! ���� ���� �������� ��������� ������ ��� ����! ��� ����� ���� ���������� ��� ������ ������ � ���������� ����������. ��� ��������� ����� ������ � ������� ��������� � �������� �������. � ����� ����� ������, ��� ������ �������� � �������� ��������!\n�� ���� �� ������ �� ����� �������, ������� �����������, ������������ ���� ������! �� ������� � ������ ������ - ��� �������, � �� �� ������� ������ �����!";
			link.l1 = "��� �� ��� ���������!";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			PlaySound("Types\warrior04.wav");
			dialog.text = "��-��-��-��, �� ��������� ��������� ������ ���� � ���� ����?! ��� �������� �� �� ����, ��� � ���� �� ����� ����, � ���������, �����!";
			link.l1 = "...";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			npchar.model = "Meriman_2";
			Characters_RefreshModel(npchar);
			PlaySound("Ambient\Teno_inside\teleporter.wav");
			dialog.text = "";
			link.l1 = "�-�-�!! �, ����!!!";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			PlaySound("VOICE\Russian\hambit\Joakim Merriman-04.wav");
			dialog.text = "������ �� �����, �������, ��� ����� �����?! ��� �� ������ ����������������� ���! � �����, ������ � ����� ���� ������!!";
			link.l1 = "������ ����!! ��, �������, ��������� ������! � ����� ���� ���� ������� ���������!!";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto37", "none", "", "", "Caleuche_MerrimanTeleport", -1);
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "goto", "goto37");
			pchar.questTemp.Caleuche.Merriman_hide = "true";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> ���� ������������ �� ������� ������� � ������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- ���� ������������ �� ������� ������� � ������
	}
}