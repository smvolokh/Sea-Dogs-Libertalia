
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
			if(PChar.Gothic_Delivery.CancelMoneyForBobMcCain == true)
			{
				dialog.text = "��, ���?";			
				if(sti(PChar.money) >= 5000)
				{
					link.l1 = "��� ���� ������";
					link.l1.go = "8";
				}
				else
				{
					link.l1 = "� ���� ���� ��� ������ �����.";
					link.l1.go = "11";
				}
				
				link.l2 = "���� ������.";
				link.l2.go = "11";
				break;
			}
		
			dialog.text = "���, ������, ����� �� ����!";
			link.l1 = "��� �������. �� � ����� �.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "1":
 	                                      PlaySound("VOICE\Russian\Gr_Tavern_Mate_3.wav");
			dialog.text = "��, ���, ������ �� ������?";
			link.l1 = "";
			link.l1.go = "1_2";
		break;

		case "1_2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_6.wav");
			dialog.text = "";
			link.l1 = "���, ���.";
			link.l1.go = "1_3";
		break;
		
		case "1_3":
 	                                      PlaySound("VOICE\Russian\Gr_Tavern_Mate_15.wav");
			dialog.text = "������ �� ��� ��� � ����. � � �� �� ���� ����� �����. �������, ����������� �������� ������" + GetSexPhrase("��","���") + ". �� ���, �����, ���������?";
			link.l1 = "";
			link.l1.go = "1_4";
		break;

		case "1_4":
  	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithMcCain");
		break;
		
		case "4":
			dialog.text = "���, ������ ����!";
			link.l1 = "��, ������, ����������, ��� ��� � ����.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "�� ��������, ���, �����-�� ������� ���-��� �������. ���������� �� ����������, ���" + GetSexPhrase("","�") + " ���������, ��� ��� ������� �������. ���� ����� ������� ����, � � ����� ����, ��� ������ �����.";
			link.l1 = "������ ���� ��������, ��� � ��� ���?";
			link.l1.go = "6";
		break;
		
		case "6":
			dialog.text = "������, ��� �� ������" + GetSexPhrase("��","���") + " � ����� � �����������.";
			link.l1 = "����� ������� ���, � ���� �������, �� ������ ���� ���� ���������� ����� �������.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "���, ���, ��� ���� �� ������. ������� �� ��������� � ��� ������ ���� �����, � ������ ����� � ���� �� �����. �����, ��� �����, ��� ����������.";
			
			if(sti(PChar.money) >= 5000)
			{
				link.l1 = "�� ������, ��� ������. ������ ������, ��� ����!!!";
				link.l1.go = "8";
			}
			else
			{
				link.l1 = "� �������, ����� � ���� ����� ������.";
				link.l1.go = "11";
			}
			
			link.l2 = "���� �������, �������� � ���� �� �������.";
			link.l2.go = "11";
		break;
		
		case "8":
			AddMoneyToCharacter(PChar, -5000);
			PChar.Gothic_Delivery.CancelMoneyForBobMcCain = false;
			dialog.text = "������ ���, ���, ������ �����������, ������ ��� ��������� �� �����. ����� � ������� ��� ������ �� ��������� ���� � ������ �������� ��� �������. ���� �� ��� � ��� ��� ����, �������� �� �����. \n ��� ��� ��� ����, ��� ������������� � ������, ��������� ��� ������� ������� � ����� �������.";
			link.l1 = "� ������ �� ������, ��� ���� �� ��� ��� ����.";
			link.l1.go = "9";
		break;
		
		case "9":
			dialog.text = "�� ���� ���������� � ���� �� �����, ��� ����. ���, ��� ���� ������" + GetSexPhrase("","�") + ", ��� ��� ��� ���� �� �����.";
			link.l1 = "�����, ����. �� ���� �� ��� ������, � ������� ��� ������ �� �����, ����� �...";
			link.l1.go = "10";
		break;
		
		case "10":
			dialog.text = "�� ���������� �������, ���. ���� ������" + GetSexPhrase("","�") + ", ��� ������.";
			link.l1 = "�� ������, ���� �������� ����, ����� � �������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithMcCainEnd");
		break;
		
		case "11":
			ChangeCharacterAddressGroup(PChar, "Pirates_tavern", "goto", "goto2");
			LAi_SetPlayerType(PChar);
			LAi_SetSitType(CharacterFromID("Bob McCain"));
			PChar.Gothic_Delivery.CancelMoneyForBobMcCain = true;
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
