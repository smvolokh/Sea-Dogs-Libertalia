// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ��� ����� �� ���������� ������ ������, � �� ��� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "� �� ��������� ������ ��������� �������� � �������, ������ �� ������� �� ����, ����� ��� ������, ����� ����� ����� - ������?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JACKSettlement" && !CheckAttribute(npchar, "quest.JACKSettlement"))
			{
				link.l1 = "� ������ ������ ����������, ���������� � ������ ����������?";
				link.l1.go = "JACKSettlement";
			}			
		break;

			// ���� ��� �������-����
 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "��� ����� �� ������ ������� � ������� � ���� ������ �������� � ��������� ����� � �� ��� ����� ������, � ��� ������� ������� �� ������!!!";
		link.l1 = "��, � ������ ���� ����������� � ���� ����?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "� �� ������! �������� ��� �������!!!";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "JACKSettlement":
        	                  dialog.text = "�, ������ ������! ����� ���� ������ ����� ����� �� ���� �� �������� � ����� �����.\n�� �� �����, � �� �������, ��� ���� ��� ������ ������ ���� ���������... �� ������ ���� ��� ������ ���������� ����.\n� �� ������� �� ����. ��� �� �����?";
		link.l1 = "��, � �� ���� � ����� ����������!";
    		link.l1.go = "JACKSettlement_1";
		break;

 		case "JACKSettlement_1":
        	                  dialog.text = "���������� �����... ������, ���� ��� ��� ������? � ��� ������ ������� �� ����������� ������! �� ����������� ���������� �� ���������� ������ - ����� ������ ����. ������� �� ����� ������� � ��� ������� � �������� ������, ������������ � ���� �� ������ �������, �������� ������ � �������� �����. ����� �������� ���� ����, �� � �����, ������� ������ � �������.";
		link.l1 = "��, �� �� ��� �������� � �������� �������!";
    		link.l1.go = "JACKSettlement_2";
		break;

 		case "JACKSettlement_2":
        	                  dialog.text = "�������? � ����� �������! �� ������, ����� ���������� ����� �� ���� ������ �����, �� ������ ����������, ����� �������� ����������, �� ������ � ������ ������...\n� ��� �� �������� �����, �� ������ ������������� ������ ������ �� ������... �� ������ ���������� ������, �������� ������ ������� ����� �� ��������� ������...\n��������� � ����� ������ ������� � ���� �������� ��������� �� �������, ������� �����������, �� ���� �� ������ ����! ���, �������... ����� �� ������������, �� ����� ����� �����, � ������ ���������! ���� �� �������, ����������, ������� ��� ���������... ���� ������� � ������ � ���������� ��� ��� ���� �������������� � �������!\n�� ������ ���� �������, ������ � ������� - ���� ����!!! ���� ���� ��, ���������� ���������� ����� ����������� ��������, ������ �� ����-�� ���? ���� ���� ������ ������� �����, � ���� ��� ��� �� ������ ����������� �� ����, �� �������� � � ��� ���� ���� ���������. � �Ѩ ���� ������! ���� �����, �������, ������... � ����� ��� ��...";
		link.l1 = "��� ��� ��, � � � �� ����� �� ����! ��, � ������?";
    		link.l1.go = "JACKSettlement_4";
		break;

 		case "JACKSettlement_4":
        	                  dialog.text = "��, � ������, ������ �� �����, ������, ������ � ������ ����� � ���� �������� �� �������� ���������...\n������� ��� ������! ������� �������, � ������ ����� - �� ����! �� ����� �� �������� � �������� �������... ���� - ����� �������, ���� � ���������� �������, ���� ���������� �����, �� ���� ���� ����������� �������, ������� ��������� ���� �� ������� �����.\n�-��, ��� �������, ���� �� � ������� ������ ������ ����, �� � ���� ������ ��� �� ��� - ������ �� ���!!!";
		link.l1 = "�������, ��� �� ������!";
    		link.l1.go = "JACKSettlement_5";
		break;

 		case "JACKSettlement_5":
        	                  dialog.text = "��... �� ��� ����� ����... � ������ � ������ � �������, ��� ����� ��������, �� ����� ��� ���� ����� ����� � �����, ����� ����� � ��� �� ������ - �� ������ �������.\n�� ��� ���� �� ������, � � �� ����� ������� �������� ���������.";
		link.l1 = "� ��� �� ������� �������?";
    		link.l1.go = "JACKSettlement_6";
		break;

                                      case "JACKSettlement_6":
		dialog.text = "������, � ����� � ���� ��� ���������� � ����. � ��� ����� ������� ������ � ������� � ������ ������, � ��� ������, �������, �� ��� ����, ������ �� ������ ����� ������ ���������.";
		link.l1 = "��, ��� ��� �����! ����� ���������� ��������.";
		link.l1.go = "JACKSettlement_exit";
  		break;

                                      case "JACKSettlement_exit":
		DialogExit();
		AddDialogExitQuestFunction("JACK_SettlementOver_Mayor");
  		break;

                                      case "JACKSettlement_7":
		dialog.text = "��, ���� �� �� ������ ����, ���� ��� ��� �����? �� �� ����� ����� ������, ��, ��, ���� �� �����, � ����� ����� ���������� ������� - ��������, ��� �� �������, ���� ���� ������, ���� ������� ���������. ������, ������ ������� ��������� ������.";
		link.l1 = "��...";
		link.l1.go = "JACKSettlement_8";
  		break;

                                      case "JACKSettlement_8":
		DialogExit();
                                       sld = CharacterFromID("Roseau_Mayor");
                                       LAi_SetActorType(sld);
                                       LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 4.0);
		npchar.quest.JACKSettlement = "true";
		pchar.questTemp.JACKSettlement = sti(pchar.questTemp.JACKSettlement)+1;
		if (sti(pchar.questTemp.JACKSettlement) == 2) 
		{
		AddDialogExitQuestFunction("JACK_SettlementOver");
		}
  		break;
		

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

