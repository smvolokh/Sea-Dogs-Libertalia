// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ����� ������ �� ���������� ������ ������, � �� �� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Baster_church") && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "� ���� � ��� ���������� ����. ������� ������� ���-���� ����� ������� ���� �������� ������������� - ������� ����� � ���������. ���� � ���, ��� ���� ����� ��� ������� �� ������� ��������, ������ ��� ��������� ��� ���� ��������� ������...";
                link.l1.go = "guardoftruth";
			}
			// Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_9_continue" && !CheckAttribute(npchar, "quest.frigate"))
			{
				link.l1 = "� ������ �� ������� �������-����������� ������� �� ������ ����� ������� ������������ ��� ���������� ���� ��������.";
                link.l1.go = "patria";
			}
			if (CheckAttribute(npchar, "quest.frigate.wait") && GetCompanionQuantity(pchar) < 8)
			{
				link.l1 = "� ����� ������� � ������� ������.";
                link.l1.go = "patria_2";
			}
			// Jason ������ ������
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "baster")
			{
				link.l1 = "��� ��������� � ��� ������� � ����� ���������...";
                link.l1.go = "baster_goldengirl";
			}
		break;
		//************************** ��������� ������ ************************
		case "Cupture_after":
            dialog.text = RandPhraseSimple("�� ��� ��� �������. ��� ��� ��� �����?", "������� �������� ��� ���-��, ��� �� �� ����������?");
            link.l1 = RandPhraseSimple("������������ ����������...", "��������, ����� �����"+ GetSexPhrase("","�") +" ��� �������...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		case "guardoftruth":
			dialog.text = "��. ����� ���������. �� ������ �� �� ��������, ��� �������� �������� ������ ���� ���������?";
			link.l1 = "���� �� � ��������, �����. ������� �� ����� ����� �� ������������� ��������. � ����� ������� ������ ��������� ����, ������� ������ ��������� �����������������, � � ��������� ������� �������� ��������� ������������...";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "";
			link.l1 = "� ����� ��� �������� �������������� � ��������� ������� ���� ������� ����� ���� �������, �������� �� �����������.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "� � ����� ��� ��� �� ����� ����� ���������� � ��������������� ��������, �, ���� "+pchar.lastname+"? ������� ��� �� ������, � � �� ������ ������� ��������� �������� �� ������� ���� � ���� �������. ������� ����� - � �����. ��� ��������� �������� ��������� � ������� � �������� �� �����, ��� ���...";
			link.l1 = "����� �� ������ ��� ������?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "���� �����������, ���� "+pchar.lastname+": � �� ������ �������. � �� ��������� ����� � ���� ���������� ���������.";
			link.l1 = "����. �������� �� ������������, �����...";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			DialogExit();
			npchar.quest.utensil = "true";
			AddQuestRecord("Guardoftruth", "28");
		break;

		//����� ��������, ����� � ������� �����
        case "Ascold_MummyAttack": 
 	PlaySound("VOICE\Russian\GOTHIC\RENGARU_04.wav");
 	PlaySound("VOICE\Russian\gotica\SFX\ZOMBIE_01.wav");
			dialog.text = "�-�-�-�!!!";
			Link.l1 = "";
			Link.l1.go = "Step_Asc_01";
			AfterTownBattle();
        break;

		
		// Jason ���
		case "patria":
			if (GetCompanionQuantity(pchar) > 7)
			{
				dialog.text = "������� �����, �� � ��� ��� ����� ��� ����. ��������� ���� ������� � �������������, � � ����� ������� ��� ������.";
				link.l1 = "������.";
				link.l1.go = "patria_1";
			}
			else
			{
				dialog.text = "��, �������, ������� ����� � ������ � ����. ������� ���������� � ����� ��������� ��� ���� ������������.";
				link.l1 = "����� �� ������������ � ����. �� ��������, ���� ���������.";
				link.l1.go = "patria_3";
			}
		break;
		
		case "patria_1":
			DialogExit();
			npchar.quest.frigate.wait = "true";
		break;
		
		case "patria_2":
			DeleteAttribute(npchar, "quest.frigate.wait");
			dialog.text = "�������. ����������. ������� ���������� � ����� ��������� ��� ���� ������������.";
			link.l1 = "����� �� ������������ � ����. �� ��������, ���� ���������.";
			link.l1.go = "patria_3";
		break;
		
		case "patria_3":
			DialogExit();
			npchar.quest.frigate = "true";
			Patria_BastionFrigateGlp(); // ������������ ������
		break;

		// Jason ������ ������
		case "baster_goldengirl":
			dialog.text = "�, ������� "+GetFullName(pchar)+", � ���� �� �������! ��-��, ��� ������ ���� ����� ������ � ���� ���������� � ������ ����������, ��� ������ �� ������� � �����. ����� ���, ��������� � ����� ��������, � � ������� ����� �������� ���������. ������, � ��� �� �������������?";
			link.l1 = "������ � �����. �� ��������, � � ��� ����� ��������� �����. �������, ���� �� ���� ����� ��� �������.";
			link.l1.go = "baster_goldengirl_1";
		break;
		
		case "baster_goldengirl_1":
			dialog.text = "�� ����������! ������� - �� ��� ���� ������������ � ��������� �� �������� �������������, ��� � ��� ��������. �������� ����� � �� ����� �������� �������, �� �� ���� � ����������, ��������, ����� ���� ������� ���������, ��� � ��.";
			link.l1 = "�� ������� ��� ����� ����������, ���� ���������. � ������ ����������, � ������ � ��������.";
			link.l1.go = "baster_goldengirl_2";
		break;
		
		case "baster_goldengirl_2":
			dialog.text = "�������, ��������������, ������ ��� ����. ��������, �������� ������� ���������. � ������� ������ �������.";
			link.l1 = "���������, ���� ���������, ��� �������. � ������ ������� ������ ������... �����.";
			link.l1.go = "baster_goldengirl_3";
		break;
		
		case "baster_goldengirl_3":
			DialogExit();
			pchar.questTemp.GoldenGirl = "baster1";
			DoQuestReloadToLocation("CommonResidence_3", "reload", "reload1", "GoldenGirl_AngerranInResidence");
		break;

        case "Step_Asc_01": 
 	PlaySound("VOICE\Russian\gotica\SFX\SWD_FART4.wav");
 	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN02.wav");
	dialog.text = "�-�-�-�!";
	Link.l1 = "������ �����, �����. � ����� �� ���� � �� ������� ���� �����.";
	Link.l1.go = "Step_Asc1";
	AfterTownBattle();
        break;

        case "Step_Asc1":
 	PlaySound("VOICE\Russian\gotica\SFX\SWD_FART5.wav");
 	PlaySound("VOICE\Russian\gotica\SFX\ZOMBIE_01.wav");
            dialog.text = "����� �������! �-�-�-�!";
            Link.l1 = "������ ����, ���������� ��������. � ����, ��� � ���� ���� ������ ��������: ��� ����������� ������ ��������� ������� ����� � �������� ��������� �������, ������� �� ����������. ����� ��� ��� �������� � �� �������� �� ������.";
            Link.l1.go = "Step_Asc2";
        break;
        case "Step_Asc2":
 	PlaySound("VOICE\Russian\gotica\SFX\SWD_FART3.wav");
 	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN01.wav");
            dialog.text = "��� � ����� ����� �� ����, � ����� �� �������� ������. ��� ����, ������ ��� ��������...";
	Link.l1 = "��� �� �� ��� ��������, ��������, ������ ����� ��� ����������� ������...";
	Link.l1.go = "exit";
	NextDiag.TempNode = "Cupture_after";
	Locations[FindLocation(pchar.location)].box1.items.sculMa1 = 1;
            Locations[FindLocation(pchar.location)].box1.items.sculMa2 = 1;
            Locations[FindLocation(pchar.location)].box1.items.sculMa3 = 1;
            Locations[FindLocation(pchar.location)].box1.items.indian022 = 1;
            pchar.questTemp.Ascold = "Ascold_MummyFoundItems"; 
            chrDisableReloadToLocation = false;
            SetReturn_Gover_Dialog_Exit(NPChar);
        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

