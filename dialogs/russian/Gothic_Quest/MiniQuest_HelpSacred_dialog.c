
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	

	switch(Dialog.CurrentNode)
	{

	case "First time":
            	dialog.text = "������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ".";
        	link.l1 = "�����������.";
        	link.l1.go = "1";
		break;


		case "1":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "?", "���������, � ������ ����..."), "� ������ ����, ������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "� � ������ ��� ������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "End";


				if(PChar.HelpSacredInquisition == "1" && PChar.location == "LeFransua_HouseInsideR9")
				{

					link.l2 = "��������, ������ ����?";
					link.l2.go = "HelpSacredInquisition_1";					
	
					break;
				}

				if(PChar.HelpSacredInquisition == "Good" && PChar.location == "LeFransua_HouseInsideR9")
				{
					link.l2 = "����� ��� ���� ����������� ���������, � ������� ���������� ����� � ��, ������ ����.";
					link.l2.go = "HelpSacredInquisition_6";	
				}
				
					break;				

						
		// ������ ������ ���������� -->


		case "HelpSacredInquisition_1":
			dialog.text = "������� ��� ����" + GetSexPhrase("��","��") + ", ����������?";
			link.l1 = "� ��� �� ������� ����� � ���� �������, ����� �� ���� ������ � ����������?.";
			link.l1.go = "HelpSacredInquisition_2";
		break;

		case "HelpSacredInquisition_2":
			dialog.text = "� ��������� ������, � ������� �������� ����� ��� � � ����� �����, ��� �������� � ��� ��� ������. � ��� ����� ���� ���� ������� ��������?";
			link.l1 = "������ ����� �� �����?.";
			link.l1.go = "HelpSacred_3";
		break;

		case "HelpSacred_3":
			dialog.text = "�� ������� �������, ����� ��� ����� � ������ ���������� ����� �������  ������������� ����� � ���, ��� ����� ������� ����� �������� ����� ����?";
			link.l1 = "�������� �� ��� ������ ���� ��� ������ �������?.";
			link.l1.go = "HelpSacred_4";
		break;
		
		case "HelpSacred_4":
			dialog.text = "�� �������� ���� ���������� �� �������, ������ �� ������ ����� � ������� ��� �� �� �����?";
			link.l1 = "��, ����?.";
			link.l1.go = "HelpSacred_5";
		break;

		case "HelpSacred_5":
			dialog.text = "�� ������ ������, �������� ����� ������� � �������� ��� ��� ���� ��� ����� ��������.";
			link.l1 = "�� ������...";
			link.l1.go = "HelpSacredInquisition_3";
		break;
		
		case "HelpSacredInquisition_3":
			dialog.text = "��! ������� � ���������! �� ������� ��� ��� ����� �� ������� ��� �������� �����, ���� �������� ����������. �, ������� ��, �����������.";
			link.l1 = "���. ���� ������������ ���������� ��� �� �� ���.";
			link.l1.go = "HelpSacredInquisition_4";			
			link.l2 = "������. � � ��� ���� ���� �������� �������������, ��� ��� ������? ���, ��� ��� �����?";
			link.l2.go = "HelpSacredInquisition_5";
		break;

		case "HelpSacredInquisition_4":
			PChar.HelpSacredInquisition = "END";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "HelpSacredInquisition_5":
			dialog.text = "���� � � ������ ����, ��� ��� ������. ����� � �������� ����� �������. � ����� ��� ����� ���.";
			link.l1 = "��� �, ������� ������. �� �������, ������ ����.";
			link.l1.go = "End";
			AddDialogExitQuestFunction("HelpSacredInquisitionStart");
		break;

		case "HelpSacredInquisition_6":
			dialog.text = "������ ���������� ���������� ���, ������� " + GetName(PChar, "f") + ".";
			link.l1 = "�������, ������ ����.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("HelpSacredInquisitionEnd");
		break;


 		case "End":
                NextDiag.CurrentNode = "Fifth time";
		DialogExit();
		break;

	case "Fifth time":
            	dialog.text = "������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", ������� " + PChar.name + "! ��� � ��� ���� ����?";
        	link.l1 = "�������. ��������, �� � �����.";
        	link.l1.go = "20";
		break;

		case "20":
            	dialog.text = "�������, �� ���� ��� �����������.";
        	link.l1 = "";
        	link.l1.go = "End";
		break;



		// ������ ������ ���������� <--
	}
}
