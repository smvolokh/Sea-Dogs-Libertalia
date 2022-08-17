// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "������, � ���� ��������� ��������� ����. � ����, ��� �� ��� ����� ����������� ����� �� ����� ��� ����� ������ ��� ��� ���������� ������: ������� ���������� � ������� ������. � ���� �� ��������.";
                link.l1.go = "guardoftruth";
			}
			if (CheckAttribute(npchar, "quest.GOT_chest") && CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "� ������ ��� �������� � ���������.";
                link.l1.go = "guardoftruth_3";
			}

			//�������, ����� �5
			if (pchar.questTemp.piratesLine == "PL5Hunter_toVillemstad")
            {
				link.l1 = "������, ����� �������� � ����-������ �� ����?!";
				link.l1.go = "Step_P5_1";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "��� ��, ��� �� - ����� ��! �������������, ����� ������������, � ������� - ������� ��������. �� �� ��������, �������: � ���� �� ���. � ��� ������ ��.";
			link.l1 = "����������! � ���� �� ����� ����������� ��������� ������? ������, � ���� �� �� �������? � ���� ���������� ����������...";
			link.l1.go = "guardoftruth_1";
			npchar.quest.utensil = "true";
		break;
		
		case "guardoftruth_1":
			dialog.text = "���������, � ����� �� ��� �������� ��� ����� ����� ��������?";
			if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "self_win")
			{
				link.l1 = "����� ����, ������, ��� � ����� ������� ���� ����������� ������� ���� � ���� ���������� �� �������� �������� ��� ��� � ����?";
				link.l1.go = "guardoftruth_2_1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "holl_win")
				{
					link.l1 = "����� ����, ������ ��� � �� �������� ����� � ����������� ����-������� �������� � ������ ������� ������ ���� ��� ���������� ����������� ���������� �� ����������?";
					link.l1.go = "guardoftruth_2_2";
				}	
				else
				{
					link.l1 = "����� ����, ������, ��� � �� ��� �������?";
					link.l1.go = "guardoftruth_2_3";
					npchar.quest.GOT_chest = "true";
				}
			}
		break;
		
		case "guardoftruth_2_1":
			dialog.text = "��, ����� - ���� �� �� "+GetFullName(pchar)+", ���� ������ �����������, ���������� ���������� ������� ������ ����������... ��� �� � ��� �������� ��� �� ����? �������, � �������� ���.";
			link.l1 = "����� � ����������� ������.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_2":
			dialog.text = "��, �� ��, �� �� "+GetFullName(pchar)+", ������� ���������� ���������� '�������-��������'. ��� �� � ��� �������� ��� �� ����? �������, � �������� ���.";
			link.l1 = "����� � ����������� ������.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_3":
			dialog.text = "�� ��� ��, �� ��������, ������� ������ ������� ��������, �, �������, �������� ��� � ���, ��� �������� ��� � ��������.";
			if (CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "����������, �������. �� ������ ������ ��� ������...";
				link.l1.go = "guardoftruth_3";
			}
			else
			{
				link.l1 = "������, � ������� ��� ��, ��� �� �������. �� ������ ������ ��� ������...";
				link.l1.go = "exit";
			}
		break;
		
		case "guardoftruth_3":
			RemoveItems(pchar, "chest", 1);
			Log_Info("�� ������ ������ � ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "���������. � ����� ������ � ����� ���������� � ���� �����������.";
			link.l1 = "� ����������� ������.";
			link.l1.go = "guardoftruth_4";
			DeleteAttribute(npchar, "quest.GOT_chest");
		break;
		
		case "guardoftruth_4":
			dialog.text = "������� ������ ����� ������� �� ����� ������ �����, ����� ��������� ��� ����� ������. ����� ��� ����� ������� ������������ ��������� ���� - ��� �� �������, �� �� ������-�� ������ �� ��� � ����������� �������... ������, � ����� ����� �� ��� ������ �� �����������.";
			link.l1 = "��� ��� ������?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "������ ��� ���� �������� ������ ��������� ���������� ��������� ������� ������� �� ����� ����� ����� � ���� ���������� �����. �� ������ ��� ���? ";
			link.l1 = "��� ��! �������� '������� ���' � ����-������ �� �������...";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "��, ����� �� ���������, ������ �� � ���� ������ ������� �� ������ ������� �������. ��������� �������� ��� ����� �� ���� �������� �������� � �������� � ����-�����, ��� ���, ��������, ������� ������� �� ���������� ��������.";
			link.l1 = "����. � ����������?";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "���������� ��������� ������ ������� ������� ������� �� ������ �� ������. ����� ������� �������, ������������ ������ �������� �� ���������, ����������� ������. ��� � ������� - ��� ������ �������� ��� � ��� ������.";
			link.l1 = "������� ������� �� ������? � ����� ����� �� � ������, ���?";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			dialog.text = "����������. ��� ���� �������, ��� �� ����������� ������������ �����.";
			link.l1 = "�������. �������, "+npchar.name+", �� ��� ����� �������!";
			link.l1.go = "guardoftruth_9";
		break;
		
		case "guardoftruth_9":
			dialog.text = "������ ����������, ������. �������� ���!";
			link.l1 = "������� ��� ��������, � ���������� ������� � ������� ���������... ��-��!";
			link.l1.go = "guardoftruth_10";
		break;
		
		case "guardoftruth_10":
			DialogExit();
			AddQuestRecord("Guardoftruth", "23");
			pchar.questTemp.Guardoftruth.Usurer = "true";
		break;

//********************** ��������� �������, ����� �5 ��� ************************
		case "Step_P5_1":
			dialog.text = "���. �� ����.\n��, ��, ��� ���������� ������������� ������, ��� �������� ���, "+ GetSexPhrase("���� ���� � ��� ����������","���� ���� � ��� ����������. ���� �� � �������") +". ��� � ������ ����� ��� �� �������������.";
			link.l1 = "���� ������?! ��� ��� ��� ��������. �� ��� � ������? ��� ��� ����� ��������?";
			link.l1.go = "Step_P5_2";
		break;	
		case "Step_P5_2":
			dialog.text = "������� �� ����. �� ������� �������, �����, ��� �����������������. � ������ ����, ��� �� ��� � �����������, ��� ���� ��, ����� ��� ���� ������ �� ��������. �� �� "+ GetSexPhrase("��������","������������") +" �����, ������ ��������, ��� ������ ��� ���� ���, ��� ��� ������ ����� - � ��������!";
			link.l1 = "��! �� �������, ��� �� ����������... �� �� ����� ������ ������ �� ����������, ���� �� ��� ��������? ����� ����-�� ������?..";
			link.l1.go = "Step_P5_3";
		break;
		case "Step_P5_3":
			pchar.questTemp.piratesLine.Q5.city_1 = GetQuestNationsCity(ENGLAND); 
			dialog.text = "������, ��� ������ � ���������� ����������. ����� � " + XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_1 + "Dat") + " ��� ����, �� ����� �� �����.";
			link.l1 = "� �������, ��� ������� �� ������. �� ������� ����!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_5_Hunter", "2");
			AddQuestUserData("Pir_Line_5_Hunter", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_1));
			AddQuestUserData("Pir_Line_5_Hunter", "sIsland", XI_ConvertString(GetIslandByCityName(pchar.questTemp.piratesLine.Q5.city_1) + "Dat"));
			pchar.questTemp.piratesLine = "PL5Hunter_toFirst";
		break;		

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}