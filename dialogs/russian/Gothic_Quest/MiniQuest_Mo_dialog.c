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

		case "Florido_Mo":
			dialog.text = "���� � ������� �������, ����� � ������� - �������!";
			link.l1 = "������� ����, �� �� � ����� ���!";
			link.l1.go = "Florido_Mo_1";
		break;

		case "Florido_Mo_1":
			dialog.text = "� ��� �� �����, ���� ����� ���������-������������� ����� ��� ����� �� ����� ��� ��� ����� � ������� 100 �������� � ������ ������.";
			link.l1 = "�� �����, ��������.";
			link.l1.go = "quest3_2_1";
			link.l2 = "�� � �� �������� ��� �� ����� �����, ���������� ���� �� ��������� � ������� � ������ �� ����!";
			link.l2.go = "quest3_2_2";
		break;

		case "quest3_2_1":
			dialog.text = "�������, ������, �������.";
			link.l1 = "";
			link.l1.go = "quest3_2_1_end";
		break;

		case "quest3_2_1_end":
			AddMoneyToCharacter(pchar, -100);
			LAi_Fade("MiniQuest_Mo_end", "");
			CloseQuestHeader("MiniQuest_Mo"); 			
			DialogExit();
		break;

		case "quest3_2_2":
			dialog.text = "������ �������� �����" + GetSexPhrase("�","���") + " ������ �� � ���� �� ������� �������.";
			link.l1 = "";
			link.l1.go = "quest3_2_2_next";
		break;

		case "quest3_2_2_next":
			NextDiag.CurrentNode = "quest3_2_2_1";
			DoQuestCheckDelay("MiniQuest_Mo_1", 0);
			DialogExit();
		break;

		case "quest3_2_2_1":
			dialog.text = "������! �� ������ ����! � �������� ������! ������ �� ������ ����, � ������ ��� �� ����, ��������� ���� ���� � ��������� �����!";
			link.l1 = "׸�� � �����, �� ���� �� ���� ���� ������, �� ������ ���� � ���� ������ �� �����" + GetSexPhrase("","�") + ". ���������� ������ ���, �������!";
			link.l1.go = "quest3_2_2_5_1";
                AddDialogExitQuestFunction("UneasyDeliveryStart");
		break;

		case "quest3_2_2_5_1":
			dialog.text = "������� ����! ������, �� ���� ������ �� �������!";
			link.l1 = "";
			link.l1.go = "quest3_2_2_5_end";
                                               
		break;

		case "quest3_2_2_5_end":
			DoQuestCheckDelay("MiniQuest_Mo_20_1", 0);			
			DialogExit();
		break;




		
	}
}