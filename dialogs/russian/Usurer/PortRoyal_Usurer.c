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

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Usurer" && !CheckAttribute(npchar, "quest.RevengeCorsair_Usurer"))
			{
				link.l1 = "� ������, ��� ��� ���� ��� ��������? � ���� ������ ��� � ����� ��� ��� ��� ������, ���� �� ��� ���������� �� ���� ����������� ��������.";
				link.l1.go = "RevengeCorsair_Usurer";
			}

		break;


		//********************* ����� ������� *********************

   		case "RevengeCorsair_Usurer":
			dialog.text = "� ���� ��� ������������, ����� ���������, ���������������. ���� �� ����� � ���� ���� �������� �� ������ � �������, ������ ��������, ���� ���� ������ ��� ���, � ��� ������� � �� ���� �� �����. � ���� ������ ������ �������, ����� ��� ����� �������, � ��� ������� �������...";
			link.l1 = "�������, � ������� ���� ��������!";
			link.l1.go = "RevengeCorsair_Usurer_1";
		break;

   		case "RevengeCorsair_Usurer_1":
			dialog.text = "�������� ��������� ����, ��� ������ ��������, ������ �������� - ���, ������� ���������...";
			link.l1 = "���!";
			link.l1.go = "RevengeCorsair_Usurer_2";
		break;

   		case "RevengeCorsair_Usurer_2":
			dialog.text = "��� �� ����������, �� ����� ��������������...";
			link.l1 = "...";
			link.l1.go = "RevengeCorsair_Usurer_3";
		break;

   		case "RevengeCorsair_Usurer_3":
 	                                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_2.wav");
			dialog.text = "...";
			link.l1 = "�, ��, � �����!";
			link.l1.go = "RevengeCorsair_Usurer_4";
		break;

   		case "RevengeCorsair_Usurer_4":
			dialog.text = "��� ���, ����� ���, ��� ����� ������� ����������...";
			link.l1 = "����, ����, � �� �����, ��� ����!";
			link.l1.go = "RevengeCorsair_Usurer_5";
		break;

   		case "RevengeCorsair_Usurer_5":
 	                 PlaySound("VOICE\Russian\GOTHIC\GG\HOLDEINGOLD_2.wav");
		dialog.text = "��, ����� ���...������� ���� ��������!";
		link.l1 = "� ��������, ��� ����� �������.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Usurer = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_4");
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

