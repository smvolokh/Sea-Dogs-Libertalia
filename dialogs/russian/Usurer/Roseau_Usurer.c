// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "� �� ��������� ������ ��������� �������� � �������, ������ �� ������ �� ����, �����, ��� �����, ����� ����� ����� - ������?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlottePRESENT" && !CheckAttribute(npchar, "quest.RoseauCharlottePRESENT"))
			{
				link.l1 = "� �� ������ ��������������...";
				link.l1.go = "RoseauCharlottePRESENT";
			}
		break;

			// ���� ��� �������-����
 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "���, �� ����� ������, �� ��� ������� � ������!!!";
		link.l1 = "��, ����� ���� ������������?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "���.";
		link.l1 = "����, ��� ��������� �������� ���� ���, ���� ������!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "������.";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

                                      case "RoseauCharlottePRESENT":
		dialog.text = "��, ����� ��� �������, �������� ��������?";
		link.l1 = "";
		link.l1.go = "PRESENT_1";
  		break;

                                      case "PRESENT_1":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_1.wav");
		dialog.text = "";
		link.l1 = "��!";
		link.l1.go = "PRESENT_2";
  		break;

                                       case "PRESENT_2":
		 TakeNItems(pchar, "gold_dublon", 300);
		 Log_Info("�� �������� 300 ��������");
                                     PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		 DialogExit();
		 NextDiag.CurrentNode = NextDiag.TempNode;
		 npchar.quest.RoseauCharlottePRESENT = "true";
  		 break;





	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}