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
			dialog.text = "�����������, ������� " + Pchar.name + " " + Pchar.lastname + ". ����� ��� ������?";
			if(CheckCharacterItem(PChar, "RandomChest"))  
			{
				link.l1 = "��.";
				link.l1.go = "Unlock";
			}
			
			if(PChar.FindAndDestroy == "6")
			{
				link.l2 = "��������, � ���� � ���� ���� ���������� �������. ���, �������� ����������� �� ���� ����. ��� �� ������ � �� �������?";
				link.l2.go = "FindAndDestroy_1";
			}
			
			link.l3 = "����� ���� ���������. ������, ��� ���� ����.";
			link.l3.go = "exit_q";
			
			NextDiag.TempNode = "First time";
		break;


		case "armourer":
			dialog.text = "� ���� ���.";
			link.l1 = "����� ��������, �� �����" + GetSexPhrase("","�") + "?";
			link.l1.go = "1";
		                        DoQuestCheckDelay("PrisonEscort_begin", 3.0);                                                                        
                                                                        
		break;


		case "1":
			dialog.text = "� ��������� ��� ������. ������� ������ � �������. �� ���� ������ ��������, ����� ����� � ������� ������� - �������� �� ����� ��������� ������.";
			link.l1 = "�� �� ����� �� � ���������?";
			link.l1.go = "armourer_2_1";
		break;

		case "armourer_2_1":
			dialog.text = "� ���� ��������, ��� �������� ����-�� �������������, ������ ���� ���. �� ���� �� ��������, � ����� ��� �� �����.";
			link.l1 = "�, ������ �������, ��� ������ �� ���������?";
			link.l1.go = "armourer_2";
		break;

		case "armourer_2":
			dialog.text = "��, ���� �����, ���� �� ����� ������ ������� ������� �������� �����. ������, ��� ����� ������ ���������.";
			link.l1 = "� �� �� �������" + GetSexPhrase("��","���") + " �� ����� �������� ����������.";
			link.l1.go = "armourer_3";
		break;

		case "armourer_3":
			dialog.text = "�������� ���� ��������. ������ � �������� ������� �� ��� � �� ���� ����� ������. �� ��� � ��� �������� ����-�� �������������. ������ �������� ��������� � �������� �����, � ���...������� �������. �� ������� ���, ����� �� ���� � �����-������ ��������.";
			link.l1 = "����-������ �� ����� ���������� ����� ��� ���������� ����. ��� ��� ���?";
			link.l1.go = "armourer_4";
		break;
		
		case "armourer_4":
			dialog.text = "��� ����� ����. � ��� ������ ��� �� ������� �������. �� �� ������! ���� ��������, ��� ��� ��������. ����� ��� �������� ���� ������� ��� ��� � �������, �� ����� � ��� ���� �������� � �� ������ ��� �������������. �� � ������� ��������... � ������ ������� �����. � �� ���� �� ��� ���������� �������� ���������...";
			link.l1 = "������� ������� �� ������! ���� ������ ������� ��� ��� ����, � ��� �� ���� �� ��� ��������.";
			link.l1.go = "armourer_5";
		break;

		case "armourer_5":
			dialog.text = "��������� � ���� �� ����������.";
			link.l1 = "���� �� �������� ������, �� ����������� ������ ������ ����! ��� ����� ������, ���� ������ ������� ���������� ������?";
			link.l1.go = "armourer_6";
		break;
		
		case "armourer_6":
			dialog.text = "�� ����" + GetSexPhrase("","�") + "! � ������ ����������� ������ ��� ���� � ������� �� ����� ���������� �������-����������!";
			link.l1 = "��� ������ ������ �� ��� �����.";
			link.l1.go = "armourer_7";
		break;

		case "armourer_7":
			dialog.text = "� ������ ���� � ������. � �� ��� ���� " + GetSexPhrase("�������","��������") + " " + GetSexPhrase("��������","��������") + ", ���� ����� ��������. ���� ������, ������� ����, � ����� ��������� �� ���� �����. ��� �������?";
			link.l1 = "� �� �����, ����� ������ ����� � ������� ��� ����.";
			link.l1.go = "armourer_7_1";
		break;

		case "armourer_7_1":
			dialog.text = "�������! ���������� � ��� ������� ����������� ����.";
			link.l1 = "...";
			link.l1.go = "armourer_7_1_q";
		break;

		case "armourer_7_1_q":
			NextDiag.CurrentNode = "armourer_7_1_r";
			AddQuestRecord("armourer_quest", "1");
			DoQuestCheckDelay("armourer_Jack_1", 0);
			pchar.questTemp.armourer = "Jack_1";
			DialogExit();	
		break;

		case "armourer_7_1_r":
			dialog.text = "���" + GetSexPhrase("��","��") + " �����?";
			link.l1 = "��� ���.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "armourer_7_1_r";
		break;

		case "armourer_7_2":
			dialog.text = "��� �, ����� ��������� �����. ��� ������� � ���� �������� ����.";
			link.l1 = "�� �������.";
			link.l1.go = "armourer_7_2_q";
		break;

		case "armourer_7_2_q":
			NextDiag.CurrentNode = "armourer_7_2_r";
			AddQuestRecord("armourer_quest", "3");
			CloseQuestHeader("armourer_quest");
			DoQuestCheckDelay("armourer_wait_start", 0);
			DialogExit();	
		break;
		
		case "armourer_7_2_r":
			dialog.text = "�����������, ������� " + Pchar.name + " " + Pchar.lastname + "!";
			link.l1 = "� ��� ������� �������.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "armourer_7_1_r";
		break;

		case "Jack":
			dialog.text = "��� ������� �� ������ ��������� ������.";
			link.l1 = "����� �� �� ������ ������ ������ ������?";
			link.l1.go = "Jack_1";
		break;
		
		case "Jack_1":
			dialog.text = "�, ����! � �� � ��������, ���� �� �� ���� ��������� ����������. ���������, � ����� ��������, ��� ��� �� ���� ����...� ��� � ���� �� ��� �������.";
			link.l1 = "������ �� ������ ��� ���� ����� ������, � �� ��� �� �������?";
			link.l1.go = "Jack_2";
		break;
		
		case "Jack_2":
			dialog.text = "�� ���� �������� ������! � �� ������� � ������ ���� ���� �������� �����. ������� � �����, ��� ������ ������ �������� ��� ������, ������� ������������� ��� ������...���� ����� ����������� - ��� �� ��� ����, � ��� ������� ������� ���, � ���� � ������ �����, ������� ������ ������ ���� �������, �� ��� ������ �������� ������ ����� � ������ ����� � �������� � ������ � �� ������ ���.";
			link.l1 = "�-��...";
			link.l1.go = "Jack_3";
		break;
		
		case "Jack_3":
			dialog.text = "������, ������ ���� ������. � ����������� � ������, ��� ���� �������� �� ����� �����.";
			link.l1 = "���������.";
			link.l1.go = "Jack_3_q";
		break;
		
		case "Jack_3_q":
			NextDiag.CurrentNode = "Jack_r";
			pchar.questTemp.armourer = "Jack_2";
			DialogExit();	
		break;
		
		case "Jack_r":
			dialog.text = "׸�� ������! ����� ��������, � � �������, ����� ��������� ����������.";
			link.l1 = "�����, ����� ���������.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "Jack_r";
		break;
		
		case "Jack_4":
			dialog.text = "��, ��� ����? �� ����... � ��������?";
			link.l1 = "���� ������� �������. ���������� �������� ����.";
			link.l1.go = "Jack_5";
		break;
		
		case "Jack_5":
			dialog.text = "�������! ������� ����" + GetSexPhrase("��","��") + " " + GetSexPhrase("������","�������") + "! ���! ���� ��� ������� ������ ������-�� ������� � ����� �����, ��� ��������, ������ ��� �� ������ ��������� ��� ������� �������, ��. ��� ����! ������� ��� ���!";
			link.l1 = "�����...��� ��������?";
			link.l1.go = "Jack_5_q";
		break;
		
		case "Jack_5_q":
			NextDiag.CurrentNode = "Jack_r";
			AddQuestRecord("armourer_quest", "2");
			CloseQuestHeader("armourer_quest");
			GiveItem2Character(pchar, "suit9");
			DoQuestCheckDelay("armourer_Jack_3_1", 0);
			DialogExit();	
		break;
		
		case "Jack_work":
			dialog.text = "�� � ����! �� ������ ����� ��� � ���� �������, ������� ������� ����� ����� � ����� ������!";
			link.l1 = "��� ���� ����?";
			link.l1.go = "Jack_work_1";
		break;
		
		case "Jack_work_1":
			dialog.text = "� ������! � ����� ����� " + GetSexPhrase("������","�������") + ", ���� ����������� ��� ������, ������, ������.";
			link.l1 = "���������, ��� ����� ���� � ��� �� ��� ��������?";
			link.l1.go = "Jack_work_2";
		break;
		
		case "Jack_work_2":
			dialog.text = "��� �������... ��, �� ��������� � ����� ������ ���������� � ������?";
			link.l1 = "��, ��, �� �� �� ������ ���!";
			link.l1.go = "Jack_work_21";
		break;

		case "Jack_work_21":
			dialog.text = "�� �� ���� ��� ������?";
			link.l1 = "�����, �����!";
			link.l1.go = "First time";
		break;

		case "armourer_7_1_1":
			dialog.text = "�, ��� ��� ������������! ��� ���������� ��������, ��������� ���. ������, ��� ���� ���?";
			link.l1 = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+".";
			link.l1.go = "armourer_7_1_2";
		break;
		
		case "armourer_7_1_2":
			dialog.text = "�� �������?";
			link.l1 = "��, ������� ����� '" + pchar.ship.name + "'.";
			link.l1.go = "armourer_7_2_2";
		break;
				
		case "armourer_7_2_2":
			dialog.text = "� ��� �� ����. ׸���� ����! � ����, ��� �� ����������! �� ������, ������! ����� ��� ��� � ���� � ��� ����� ������ ��������.";
			link.l1 = "������ �� �������� ���� �������?";
			link.l1.go = "armourer_7_2_3";
		break;


		case "armourer_7_2_3":
			dialog.text = "������ �� � ���! ��� � ��������������.";
			link.l1 = "�������!";
			link.l1.go = "armourer_7_2_4";
		break;

		case "armourer_7_2_4":
			dialog.text = "���� ������������ ������ ��� ����, ���������� ������.";
			link.l1 = "��� �� ������!";
			link.l1.go = "armourer_7_2_5";
		break;

		case "armourer_7_2_5":
			dialog.text = "������ �������� ��������, �� � ��� ����� ������ ������" + GetSexPhrase("","�") + ".";
			link.l1 = "��, ������� ��������" + GetSexPhrase("","�") + "!";
			link.l1.go = "armourer_7_2_6";
		break;

		case "armourer_7_2_6":
			dialog.text = "�� � ��� ���� �� �����������.";
			link.l1 = "������ ���������, ��� ��������, � ��� ��� ����� ���������!";
			link.l1.go = "armourer_7_2_7";
		break;

		case "armourer_7_2_7":
			dialog.text = "��, ����� ����, ���� �������� ��������, �� ��� ��������, � ��������� �� �����, ��������� �� ����� ������, � �� ������ � ���� ����� �� �����.";
			link.l1 = "� ������� ���� ���� ������!";
			link.l1.go = "armourer_7_2_8";
		break;

		case "armourer_7_2_8":
			dialog.text = "300 �����.";
			link.l1 = "���, �� ���������!";
			link.l1.go = "armourer_7_2_9";
		break;

		case "armourer_7_2_9":
			dialog.text = "����� ���������, ����� ������ � ���� ��������� ������ �� ������� ��������, ������� ����� ��������, � ����� ���������� ��������� ������ ���������� ����� ������.";
			link.l1 = "�������!";
			link.l1.go = "armourer_7_3_0";
		break;

		case "armourer_7_3_0":
			dialog.text = "���, ���, ����� ��������� �����?";
			link.l1 = "�������. � �������� �������. ������ �������!";
			link.l1.go = "armourer_start";
			link.l2 = "�������, ��������!";
			link.l2.go = "exit_q";
		break;

		case "armourer_start":
			dialog.text = "����� �������, � �������, � �� ������� �������?";
			link.l1 = "��, � �� �����" + GetSexPhrase("","�") + " �� ��������!";
			link.l1.go = "armourer_7_3_1";
		break;

		case "armourer_7_3_1":
			dialog.text = "�� �� ����� ������" + GetSexPhrase("","�") + ", � ����� �����, ������� ������� ��� �������� ���� ������?";
			link.l1 = "�������!";
			link.l1.go = "armourer_7_3_2";
			link.l2 = "��������!";
			link.l2.go = "armourer_7_3_3";
		break;

		case "armourer_7_3_2":
			dialog.text = "�����?";
			link.l1 = "����������, ��� �� ������!";
			link.l1.go = "Exit";
			GiveItem2Character(pchar, "blade37");
		break;

		case "armourer_7_3_3":
			dialog.text = "�����?";
			link.l1 = "����������, ��� �� ������!";
			link.l1.go = "Exit";
			GiveItem2Character(pchar, "blade39");
		break;










		//-----------------------------------------------------------------------------------------
		// ����� � ���������� -->
		//-----------------------------------------------------------------------------------------
		case "FindAndDestroy_1":	
			dialog.text = "...(���-�� ��������)... �-�... ������� ������... ��� ������������� �����... ������ ������������... ��� ������������� ���������... ��, ����� ����������, � ������� ������ ���� � ����� �����.";
			link.l1 = "�� ���� ��, ����� ����, �� ������?";
			link.l1.go = "FindAndDestroy_2";
		break;
		
		case "FindAndDestroy_2":	
			dialog.text = "����, ��� �� �����. ���� ���� �������� ����� �� ��������� ��������, ������� �������������� �� �������� ����� ��� �����.";
			link.l1 = "������ � ����?";
			link.l1.go = "FindAndDestroy_3";
		break;
		
		case "FindAndDestroy_3":	
			dialog.text = "� ������ ����������� ��������� �������������� �����, �������. ������ ������, � ���� �����, ���� ���� ����������. �� �������� ������ ����� ������� � ������������������� ������� � ������ �������. � ����� ������ ������ ����� ������ �� ����������� ������ ���������.";
			link.l1 = "����������� �������! �����! ������, � �� �� ������, ��� �� ��������� ���������� ���� ����� �������?";
			link.l1.go = "FindAndDestroy_4";
		break;
		
		case "FindAndDestroy_4":	
			dialog.text = "�-�... ���� ���� ����������� ������. �������, �� ���������.";
			link.l1 = "������� ����! ��� � ���� ������� ��� ���� �� ��������� ������?";
			link.l1.go = "FindAndDestroy_5";
		break;
		
		case "FindAndDestroy_5":	
			dialog.text = "����� ��� ������ ��� ���� ����, ����� �� ������, ���������� ��� ����...";
			link.l1 = "�������. ����������� ����� ���� ���, �� �� ������. � �����, ������.";
			link.l1.go = "exit_q";
			AddDialogExitQuestFunction("FindAndDestroyFindMines");
		break;
		//-----------------------------------------------------------------------------------------
		// ����� � ���������� <--
		//-----------------------------------------------------------------------------------------


		case "armourer_amulet":	
			dialog.text = "� ����� ����, �������, ��� ���� ���� �������.";
			link.l1 = "����������� ����, �� ���� � �� ����. �� ���� �� ������ ������ �� ������?";
			link.l1.go = "armourer_amulet_1";
		break;		
		case "armourer_amulet_1":	
			dialog.text = "�� �����!";
			link.l1 = "����� ������, � ���� ��� ���� ���� �����, ��� ����� ������?";
			link.l1.go = "armourer_amulet_2";
		break;		
		case "armourer_amulet_2":	
			dialog.text = "��� �� �� �� �������, ������� ������ �������� �� ������, � ��� ��� �� ����������� �� ������� ����.";
			link.l1 = "�� ���, ��� ����� ���������� ������, ��� �� ���� ����������?";
			link.l1.go = "armourer_amulet_3";
		break;		
		case "armourer_amulet_3":	
			dialog.text = "����� ������ ����, ���� ����������.";
			link.l1 = "��� �����?";
			link.l1.go = "armourer_amulet_4";
		break;
		case "armourer_amulet_4":
	                                               TakeNItems(PChar, "MoonStone", -1);
	                                               TakeNItems(PChar, "DisappearPeople_Coin", -1);	
			dialog.text = "������� �� ����, �������.";
			link.l1 = "����� ������ �� ������� � ������� ����� ������?";
			link.l1.go = "armourer_amulet_5";
		break;
		case "armourer_amulet_5":	
			dialog.text = "������� ����� ���� ������, ��� � ��������� �� ������.";
			link.l1 = "������, �� �������.";
			link.l1.go = "Exit";
	                                                SetTimerFunction("armourer_amulet_1", 0, 0, 10);
		break;

		case "armourer_amulet_6":	
			dialog.text = "� ��� � ��, ��� ����� �����, � ���� 4000 ����.";
			link.l1 = "��� �������.";
			if (sti(pchar.money) >= 4000) link.l1.go = "amulet_1";
			else link.l1.go = "armourer_amulet_7";
		break;

		case "armourer_amulet_7":
			dialog.text = "��... �� ��� �� ������? " + GetSexPhrase("������� �������","������� �������") + ", � ��� ������������ ������� �����, ������� � �� �������.";
			link.l1 = "��������. �, ������, �����" + GetSexPhrase("","�") + " ������ � ����������� �������. ������ ������� � �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "armourer_amulet_repeat";		
		break;
		
		case "armourer_amulet_repeat":
			dialog.text = "�� �������� ������, " + PChar.name + "?";
			if (sti(pchar.money) >= 4000)
			{
				link.l1 = "�������! �������, ��� ����� � ������ ������� ��� ��������.";
				link.l1.go = "amulet_1";
			}
			else
			{
				link.l1 = "���� ��� ���...";
				link.l1.go = "exit";
				NextDiag.TempNode = "armourer_amulet_repeat";
			}		
		break;
		
		case "amulet_1":
			AddMoneyToCharacter(pchar, -4000);
			dialog.text = "������������! " + PChar.name + "!";
			link.l1 = "���������� ������?";
			link.l1.go = "armourer_amulet_8";			
		break;

		case "armourer_amulet_8":
	                                               TakeNItems(PChar, "ArtRing5", 1);	
			dialog.text = "����������� ���?";
			link.l1 = "����������";
			link.l1.go = "Exit";
	                                                sld = characterFromId("Myxir");//���� ������� 
	                                                sld.dialog.currentnode = "Myxir_100";
		break;



		case "exit_q":
			DialogExit();
		break;

 		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;		

 


	}
}