// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "��������� ����� ���� �����, �������� � ���� � ��������, �� �������� ������ �����-�� ������...", "�� ������� ������ ������. ��� ��������� ����, � �� ������ ��������� �����...",
                          "����� �������? ����� ����� ��������� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "������ ��� �� � ��� ��������"), "��, �����, �������... �������� � ��������...",
                      "�� ��, ������������� � ������ ���...", "��, ����� � ���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicAscold.Fisk") && pchar.questTemp.GothicAscold.Fisk == "ThreeObject" && !CheckAttribute(npchar, "quest.ThreeObject"))
			{
				link.l1 = "����, ���� � ���� ��������� ������. ��� ������� ����� ��������� ����������.";
				link.l1.go = "Gothic_FISK";
			}
			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "����, ������ �� ������ � ������� ������ �� �������, �����, ��� �����?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "� ��� �� ��������� ������, �� �����, �� ������.";
		link.l1 = "��, ����� ��� � �������� ����� ����������, ���������� ��� ������ �������!!!";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "��� �� ������, � �������� ��� �� ��� ������ �������� �������, �� � ����� �� ������� ��� ������, ����� - �� �����?";
		link.l1 = "��, ��� ����� ��� �� ����� ��������. ����� � ���� �����.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;


 		case "Gothic_FISK":
        	                  dialog.text = "� ���� � ����� ����� ���� ����, � ��� ���������� ���.";
    		link.l1 = "�� �� ��������. ��� ���� � ���, ��� � ��� ��� �������� ���������� ������. ��� �������. ��� ���� - �� ���� ������������ ��� �����, ���� �������� �� ��������. � ����� ��������� ����� �� ��� ����, ���� ��� � ��� ����.";
    		link.l1.go = "Gothic_FISK_2";
		break;
 		case "Gothic_FISK_2":
        	                    dialog.text = "�������� ����, � ���� ��������� �����. ������, ��� ������� �� ������������� � ���� �������, �� �� ���������������?";
    		link.l1 = "�� ���, ��� ���� ���-��.";
    		link.l1.go = "Gothic_FISK_3";
		break;
 		case "Gothic_FISK_3":
        	                    dialog.text = "������ �� ������� � ����� ������ ������, �����, ��� �� ���� ����� ������ ���, �� ������� �� ��� �� ��� ��� ����������, �� � ������ ������� ����������.";
    		link.l1 = "������� ������ ����?";
    		link.l1.go = "Gothic_FISK_4";
		break;
 		case "Gothic_FISK_4":
        	                    dialog.text = "��, � ���� ������ �� ��� ������ � �� ���� ��? � ����� ������ ����� �� ����� ������ �����, ����� � � �������� �� ������.";
    		link.l1 = "��� �� �����?";
    		link.l1.go = "Gothic_FISK_5";
		break;
 		case "Gothic_FISK_5":
        	                    dialog.text = "� � ������, ������.";
    		link.l1 = "�����, �����!";
    		link.l1.go = "Gothic_FISK_6";
		break;

		case "Gothic_FISK_6":
	                DialogExit();
		LocatorReloadEnterDisable("Roseau_town", "reload1_back", true);//����� �������
		LocatorReloadEnterDisable("Roseau_town", "gate_back", true);//����� �������
                                       DoQuestFunctionDelay("Roseau_night", 0.1);
		npchar.quest.ThreeObject = "true";
		sld = CharacterFromID("Roseau_tavernkeeper");
		sld.dialog.currentnode = "Gothic_Roseau_tavernkeeper";
 
	                pchar.quest.Roseau_Fisk.win_condition.l1 = "locator";
	                pchar.quest.Roseau_Fisk.win_condition.l1.location = "Roseau_town";		                                   pchar.quest.Roseau_Fisk.win_condition.l1.locator_group = "reload";
	                pchar.quest.Roseau_Fisk.win_condition.l1.locator = "reload6_back";
	                pchar.quest.Roseau_Fisk.function = "Roseau_night_0";
	                break;

	}
	UnloadSegment(NPChar.FileDialog2);
}

