// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("�������, " + GetAddress_Form(NPChar) + "?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), ""+ GetSexPhrase("��, �� �� ��������� �� �� �� ���, " + GetAddress_Form(NPChar) + "? ","����� �� ��������� ���������? �������, ������ �� �� ����, ��� ��...") +"", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������..."+ GetSexPhrase(" ��� ����� ��������?","") +"",
                          "����� ������� ������ ��������, " + GetAddress_Form(NPChar) + "?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "�� ���, ��� ��, ���������...",
                      "����� ���, ��������, �������...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// ==> ��������� ���� ��������� �������.

            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_toHavana")
            {
    		    dialog.text = "� ��� ������, ������"+ GetSexPhrase("","���") +".";
    			link.l1 = "����� �������, ���� ���� ���� ����� �� ����������, ��� � ���������, �� ��, �������, �� ���������� ��� ������.";
    			link.l1.go = "Gothic_1";
			}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_WaitOneDay")
            {
				if (GetQuestPastDayParam("questTemp") > 0)
				{
    				dialog.text = "��, ��� � �� ������"+ GetSexPhrase("","���") +"! ��� ��� �������.";
    				link.l1 = "���, ����, ��� �� �������� ������...";
    				link.l1.go = "Gothic_4";
				}
				else
				{
    				dialog.text = "������"+ GetSexPhrase("","���") +", � ��� �� ��������� ������ ���������. ���������, ����� ���������, ����� ���...";
    				link.l1 = "������, ��������, ���...";
    				link.l1.go = "exit";
				}
			}
            // <== ��������� ���� ��������� �������.
		break;


//========================== �����. ������ ����� ���� ==================================
 	 	case "Gothic_1":
			dialog.text = "�� ��� ��, �����... "+ GetSexPhrase("������ ������������ ��������� �������� �� � ��� ����������!","����� ������ ������� � ������, �������.") +"";
			link.l1 = "��� �����, ����� �� ������� ��� ������ ����� ���� ������� �� �����, ���� ����������. �� ������ ���, ����� �� ���� �� ����� �� ���� ����� ����!";
			link.l1.go = "Gothic_2";
        break;
 	 	case "Gothic_2":
			dialog.text = "��, � ����� ���� � ��� ����� �������� �����, ����� �� ��� ����? � � ������ ������� ��� ������...";
			link.l1 = "��������, � �����"+ GetSexPhrase("","�") +", �� ��� �� ���������! ��, ����� 500 �����, � ��� ������� �� ��������, ����� ��������� ����� �� ����� ����. �� ��� ������ �� ������ ���� ������� ������ ���������.";
			link.l1.go = "Gothic_3";
			AddMoneyToCharacter(pchar, -500);
        break;
 	 	case "Gothic_3":
			dialog.text = "�������, ������"+ GetSexPhrase("","���") +"! ��� �������� ��������� ����-������. � ������ ����� ����� � ����� ����� ��� ����, ����� ������� � ���� ������� �� �����. �� � ������ ����� ���������� - ��� ������ � ��� � ��� �� ���������...";
			link.l1 = "����� ������, �����. � ��� ����...";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "DOjeronRing");
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_WaitOneDay";
			SaveCurrentQuestDateParam("questTemp");
			AddQuestRecord("GothicLee_TakeAnna", "2");
        break;
 	 	case "Gothic_4":
			dialog.text = "��, ��������.";
			link.l1 = "������. � ������ �������� ���, ��� ��� ���� �������...";
			link.l1.go = "Gothic_5";
        break;
 	 	case "Gothic_5":
			dialog.text = "� ����� ������"+ GetSexPhrase("","���") +" �� ����� ��� ������ ������ �������?\n"+
				          "��, ������"+ GetSexPhrase("","���") +", ����� ���, �� �������� ��� ���� ��� ������! � ���� ����� ��������� ������ �� ����� �������!";
			link.l1 = "�����... ��������, � ����� ���� �������� ������ � �� ��������. �� ���� �� ���� �����, ����� - ����� ������...";
			link.l1.go = "Gothic_6";
        break;
 	 	case "Gothic_6":
			dialog.text = "������, ������"+ GetSexPhrase("","���") +"... � ������ �� ��� ��������. � ������ ���, ������"+ GetSexPhrase("","���") +"? ����� ��� ��� �������, �� ����������, ��� �������.";
			link.l1 = "� ���? ��� ��� �������?";
			link.l1.go = "Gothic_7";
        break;
 	 	case "Gothic_7":
			dialog.text = "������ ����������. ��������� ���������, ��� �� �������� ������� � �������� �� ���.";
			link.l1 = "����� ������� ����!";
			link.l1.go = "Gothic_8";
        break;
 	 	case "Gothic_8":
			dialog.text = "������, ������"+ GetSexPhrase("","���") +", ������ �� ������� ��� ����� ������... ��� ���, ��������.";
			link.l1 = "�������, ������� �������. �� �����, ������ ��� ��� �����, ���� ���� ���-������... � ����� ���� �� ������, ���������. ���� �������?";
			link.l1.go = "Gothic_9";
        break;
 	 	case "Gothic_9":
			dialog.text = "�������, ������"+ GetSexPhrase("","���") +", ��� �� ����� ���������.";
			link.l1 = "�� ��� � ������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -500);
			AddQuestRecord("GothicLee_TakeAnna", "3");
			AddQuestUserData("GothicLee_TakeAnna", "sSex", GetSexPhrase("��","��"));
            ChangeItemDescribe("letter_open", "itmdescr_letter_open_FraLineQ3");
            GiveItem2Character(pchar,"letter_open");
             pchar.questTemp.GothicLee = "GothicLeeTakeAnna_WaitMidnight";
        break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

