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
//---------------------------------------------------------------------------------------------------------------------------
//	����� ����
//---------------------------------------------------------------------------------------------------------------------------
		
		// ����
		case "Anri_1":
			dialog.text = "��, " + GetSexPhrase("������","���������") + ", � ����, �� ���" + GetSexPhrase("��","��") + " ���" + GetSexPhrase("��","��") + ". ���� ���������� ���� ���� ������, ��� �������?";
			link.l1 = "������� ��������, � �����, �����, ��� � �����.";
			link.l1.go = "Anri_2";
		break;
		
        case "Anri_2":
            dialog.text = "��, ��� � ��� ����: � ��������, ��� ���������� ������� ��������� ���-��� ��������� � ���� ���������� �����, ��������?";
            link.l1 = "�� ��� ��, ������, ����� � �����" + GetSexPhrase("","�") + " �� ����� ����������� ���������?! ��, �� ���, ��� ����.";
            link.l2 = "�������, ������ ���������. ���������.";
            link.l1.go = "Anri_3";
            link.l2.go = "Anri_4";
        break;

        case "Anri_3":
            dialog.text = "����! �� ���, �������, ������ � ���� ��� � ������?!";
            link.l1 = "...";
            link.l1.go = "Exit";
            AddDialogExitQuest("AnriDeKozen_First_meet");
            NextDiag.TempNode = "arest_1";
        break;

        case "arest_1":
            dialog.text = "�����, �������! �� ����� ���� ��������! � ���������.";
            link.l1 = "���?! �� � ���� � ������� ������! � ��� ��� ������, ����� �� ��������� �� ��� ��� ������� ����!";
            link.l1.go = "Exit";
            NextDiag.TempNode = "arest_2";
        break;
        
        case "arest_2":
            dialog.text = "" + GetSexPhrase("�����","�����") + "! ������ ���� ������!!!";
            link.l1 = "...";
            link.l1.go = "Exit";
            NextDiag.TempNode = "arest_3";
        break;
        
        case "arest_3":
            dialog.text = "���������! ������ ���� � ���! �� ���� ����" + GetSexPhrase("","�") + "!!! �� � ��� �������� �� ����, ������� ��� �����!";
            link.l1 = "...";
            link.l1.go = "Exit";
        break;
		// �����������
        case "Anri_4":
            dialog.text = "� ���-��� ����� ������� ��������, �� ��... ������, ��� ���� �� ���������� ��������, � ��� ����� ��������, ������ �������.";
            link.l1 = "�����" + GetSexPhrase("","�") + ", ����� � � ���� ���.";
            link.l1.go = "Exit";
            NextDiag.TempNode = "Anri_work_1";
			AddDialogExitQuest("Anri_accept_first_propose");
        break;
        
        case "Anri_work_1":
            dialog.text = "�, ��� ��. ����� ��������.";
            link.l1 = "� �����" + GetSexPhrase("","�") + ". ������.";
            link.l1.go = "Exit";
            AddDialogExitQuest("Anri_razboi_2");
        break;
        
        case "Anri_wounded":
            dialog.text = "���������! ���� ����� � ������ ����� �������! ��� ������! � �����! ������ ��� ���������, ���� ��� ������ ������� �������.";
            link.l1 = "��, �� ���. ��� ��� ��� ����� ��������. ��� �� �������� ������ �������, ��� ��� ������. �� ������� �����.";
            link.l1.go = "Anri_wounded_1";
        break;
        
        case "Anri_wounded_1":
            dialog.text = "������ ���� � ���! �� � ��� �������� �� ����, ������� ��� �����!";
            link.l1 = "...";
            link.l1.go = "Exit";
            AddDialogExitQuest("Anri_razboi_6");
        break;
		
		// ������� � �������
        case "In_House_1":
               dialog.text = "������! " + pchar.name + ", ��� ��?! ��� �� ����� �������?! ��� �� ���� ������?!";
               link.l1 = "��, ����, ��� ������ �. � ���� ���� ������� ������������� �� ��� ���������... ��� �, ������ �������� ��������� ��, ��� ������ ��������.";
               link.l1.go = "In_House_2";
        break;
        
        case "In_House_2":
               dialog.text = "��... " + pchar.name + ", � �� �� �������" + GetSexPhrase("","�") + " � ���, ��� � ����� ����� ���� �� ������ ��������� ����������� �������? �� �� � ���� ������� �� �������, ���� �������!";
               link.l1 = "� ��� �������!!! � � �� �� ����� �������� ���������" + GetSexPhrase("��","���") + ". �� ���-������ ���������.";
               link.l1.go = "In_House_3";
        break;
        
        case "In_House_3":
               dialog.text = "���, ������ �� ��������" + GetSexPhrase("","�") + " ����������... � ��������� ���� ������ - �� ��� �����, � � ������ ���, ����� ����������� ������ ����� � ���� ��� ���������. ���" + GetSexPhrase("","�") + " �������, ���� �� ���� ������, ���� �� �� ��� �� ��������, �� ��� � ��� ������ ����� �� ����� ���������. ��� �������?";
               link.l1 = "� ���� ����� �� ������ ������. � ��� �� ������ ��� �������� � ��������?";
               link.l1.go = "In_House_4";
        break;
        
        case "In_House_4":
               dialog.text = "� ������ ���� ������, ��������� ������� ����������� ����� ����������� �������, � ���� ������ ��� ���������. �� ������ ��� � ��� ���� �����, �� ����" + GetSexPhrase("��","��") + " �������� �� ��� ��������, ������� ��� ��� ����� ������������ ������������� ���� �� ������ �����.";
               link.l1 = "� ������ ��������� ��� ����� ��������? ��� � ���� ��� �����?";
               link.l1.go = "In_house_5";
        break;
        
        case "In_house_5":
               dialog.text = "����� ��� ����� ���. �� ����� ��������� �� ������ ����������� ����� ���������� � ����������.";
               link.l1 = "������, � ����� ����� ��������. ������ �� ������� �������� �����-������ �����! � ��������� ��� � �� ����� � ����� �������� � ����������, � ��������� �� �����.";
               link.l1.go = "Exit";
               AddDialogExitQuest("J_Jozeph_Clain");
               NextDiag.TempNode = "Jozeph";
        break;
        
        case "Jozeph":
               dialog.text = "����� ��� ��� �� � ����, " +pchar.name+ "?";
               link.l1 = "���, ���� � ��� �� �����" + GetSexPhrase("","�") + "...";
               link.l1.go = "Exit";
               NextDiag.TempNode = "Jozeph";
        break;

        case "Jozeph_1":
               dialog.text = "����������� ����, " + pchar.name + ". ���� ���� ��� ������� �� ��� �����. ��, ��� ������, �������� � ����� ���������� - � ���� � ����� ���� ��������. ��� ��� ������ � ��������� ����� ���� �������� �����������, ��� ���������" + GetSexPhrase("��","��") + " � �������������" + GetSexPhrase("�","��") + ", � ���� �������, ��� ���" + GetSexPhrase("���","�") + " ���������" + GetSexPhrase("��","��") + "! ����� ����������� ����� ������� ��������� �� �������� ��������� ������ �� ����-�-�����.";
               link.l1 = "������! ��� � �� ���������" + GetSexPhrase("","�") + " ���� �����!!!";
               link.l1.go = "Jozeph_2";
        break;
        
        case "Jozeph_2":
               dialog.text = pchar.name + ", �� ���� ������� ���� - '���� ��', '�� �'... � ���� ��� ����, �� ��� �������" + GetSexPhrase("","�") + ", � ���� ���� ���� - � ��� �� �����!";
               link.l1 = "...";
               link.l1.go = "Exit";
               AddDialogExitQuest("J_Final_in_room_1_2");
        break;

		// ������ � �������
		case "AnriSld":
			dialog.text = "���-���, ��� ��� ����� ����������?! �������� ��-�������!";
			link.l1 = "���� �������� �� ���� �����!";
			link.l1.go = "Exit";
			NextDiag.TempNode = "AnriSld2";
		break;
		
		case "AnriSld2":
		    dialog.text = "���, � ��� � ����� ����� �����������!";
		    link.l1 = "...";
		    link.l1.go = "Exit";
		    NextDiag.TempNode = "AnriSld3";
        break;
            
        case "AnriSld3":
            dialog.text = "����� ����� �������. � �� �������� ��� �� ��������� ��������. � ����� ���� �� ��������?";
            link.l1 = "���� ������� - ����������. �� �������� ������ �����������, � ������ - ����� ��������� ���� �������������� ����� �� ������ � ��� ���������� �����.";
            link.l1.go = "Exit";
            NextDiag.TempNode = "AnriSld4";
        break;
            
        case "AnriSld4":
            dialog.text = "��������� �� ���������� � ������ �����������. ��� ���� �������. ��������.";
            link.l1 = "...";
			link.l1.go = "Exit";
            AddMoneyToCharacter(pchar, 500);
			ChangeCharacterReputation(pchar, 1);
            SetQuestHeader("AnriDeKozen");
			AddQuestRecord("AnriDeKozen", "arest");
			CloseQuestHeader("AnriDeKozen");
        break;
		
		// �������� �����������
		case "Anri_bariga":
			dialog.text = "� ����! ��� ��� �� ����? ���������� ����������� � ����� ������������!!! � ������ �������.";
			link.l1 = "���, ������ ������ ����� �����!";
			link.l1.go = "Exit";
		break;
		
//-------------------------------------------------------------------------------------------------------------------------------------------------------------		
		
		case "AlvaroPinto":
			dialog.text = "������ ������! ��� ���� �� ���� ����?!";
			link.l1 = "� ������ ���� ����� �� ���������, ���� ��������.";
			link.l1.go = "AlvaroPinto_1";
		break;
		
		case "AlvaroPinto_1":
		        dialog.text = "�� �� ����������-�������? ������ ��� ��� 15 000 �����?";
		        link.l1 = "���� ������! � �� ������������ ��������! ������� �� ���� ������� �����?! ���� � ������ �����?";
		        link.l1.go = "AlvaroPinto_2";
		break;
		
		case "AlvaroPinto_2":
		        dialog.text = "��, �� � ������ ��, ��������. ��, ���! ��������� ���� �����!";
		        link.l1 = "...";
		        link.l1.go = "Exit";
		        NextDiag.TempNode = "AlvaroPinto_3";
		        AddDialogExitQuest("SaveErnandes_ErnandesWait");
		break;
		
		case "AlvaroPinto_3":
		        dialog.text = "��� ��� ��������. ���� � ������ ���� �������?";
                        if(sti(pchar.money)>=15000)
                        {
                            link.l1 = "�����, ���������� ������ �� ����!";
		            link.l1.go = "AlvaroPinto_4";
                        }
                        link.l2 = "�� ��� ������! ������� � ������ ���� �����. � ������!";
                        link.l2.go = "Exit";
		break;
		
		case "AlvaroPinto_4":
                        if(rand(100)+sti(pchar.skill.sneak)/10 > 50)
                        {
                            dialog.text = "���, ������ ����. �� ��� �� �������, ������� �����.";
		            link.l1 = "...";
		            link.l1.go = "Exit";
		            AddDialogExitQuest("SaveErnandes_ErnandesWelcomeABoard");
                        }
                        else
                        {
                            dialog.text = "";
                            link.l1 = "";
                            link.l1.go = "";
                        }
		break;

// ������ � ������� �����
                case "AlvaroPinto_Bocman":
                        dialog.text = "� �� ���� ����� �����, ��������?";
                        link.l1 = "�����-�� ��� ��� ���, �� ������� ������ �� ������ � ����� �� ����� ������� �����?";
                        link.l1.go = "AlvaroPinto_Bocman1";
                break;
                
                case "AlvaroPinto_Bocman1":
                        dialog.text = "� ��� ��� � ��� �������? � ������ �� ��� ����� '�����������', ��� ��� ��������� �� ����� � �����. �� ��� ������ ��� ������ ������. � � ������� ��� � ������, �������� ���-����� ���� � �������, ������ ���, ����� �� ���� ������ ������ � �������.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "";
                        AddDialogExitQuest("SaveErnandes_Self_Dialog_ToTheShip");
                break;
                
                case "AlvaroPinto_Sailor":
                        dialog.text = ""+GetCharacterFullName("AlvaroPinto_Bocman")+" ������� �� ��� ���� ������� - �� � ��� �������.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "AlvaroPinto_Sailor";
                break;

// ����� �� ������� ������� ����� -->
                case "AlvaroPinto_Sailor1":
                        dialog.text = "������ ������� �� ������ �� ����� �������?";
                        link.l1 = "� ���� ������������ � ����� ���������.";
                        link.l1.go = "AlvaroPinto_Sailor2";
                break;
                
                case "AlvaroPinto_Sailor2":
                        dialog.text = "����� �� ��� �����������?";
                        link.l1 = "��� ������ �� ������� ����� ������� ��������, ���� �� � ���� � �������, ��� ����� �� �������� �� ���! � ������ �������� ������ ��������� � �� ������� ������� ����� �� ��������� � ��������!";
                        link.l1.go = "AlvaroPinto_Sailor3";
                break;
                
                case "AlvaroPinto_Sailor3":
                        dialog.text = "��! ����! ������ ��������. ��� �����-�� ������ ����� � ��� ��������.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        AddDialogExitQuest("SaveErnandes_WaitAlvaro");
                break;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ����� ���� -->
                case "Magis_Fuks":
                        dialog.text = "��������, �� �������� �� ������� �� ����� � ������ ����� '�����������', ������� ������ ����� � �����?";
                        link.l1 = "��� ����, �� �� ��������, ��������. ����� ����, ����������, � ���� � �� ��������, ���� � ����� ���� �������� ��������.";
                        link.l1.go = "Magis_Fuks_1";
                break;
                
                case "Magis_Fuks_1":
                        dialog.text = "��� ����. ������ �����, �� �����, �������. ����� � � ���� �� ������, ���� ��� ������ ��������������? �������� ����� ������������ �������� � ���������, ��� ����� ���� ���� ��� ������ ��� �� ������ � ����...";
                        link.l1 = "��� � ����� ����� � ��������.";
                        link.l2 = "��, ������� ����� �����! ��������� �����������������, � �� ��� ������ ��� ������� ��� �������? ���� � ����� ����� ����� � ����������.";
                        
                        link.l1.go = "Magis_Fuks_Exit_Noquest";
                        link.l2.go = "Magis_Fuks_2";
                break;
                
                case "Magis_Fuks_Exit_Noquest":
                        AddDialogExitQuest("Magis_Fuks_Quest_Decline");
                        NextDiag.CurrentNode = "Magis_Fuks_NoQuest_NextTime";
                        DialogExit();
                break;
                
                case "Magis_Fuks_NoQuest_NextTime":
                        dialog.text = "����� ����, ��� ����� ������� ��� �� �������� ��� � ������...";
                        link.l1 = "������, ����� �� ������� ������� ���� ��������.";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_NoQuest_NextTime";
                break;
                
                case "Magis_Fuks_2":
                        dialog.text = "� ��� �� � ����, ��� �� ����� ���������� �������� � ������� ��� ������ ������. ��� ���� � ������� ���� ��������� �������� �� ���������, ��������� �� ����� �����. ���� ��� ��������� ����� ���� �� �� ����� �����, � ��� �������� ������ �����������. �������� � ����������, ����������� � ������ �������� ��� ������, ����� ��������, � ��� ���������� � ����������. � ��� �� ���� - ��� ����� ���� ��� �����.";
                        link.l1 = "��� � ��� �� ���������� ����? � �������, ������, �����, �������������� ���� ��� �������� �����, ������� �� ���� �������?";
                        link.l1.go = "Magis_Fuks_3";
                break;

                case "Magis_Fuks_3":
                        dialog.text = "� ����, ��� ��� �������? � ��� ���������� �� �� �����. ������� ����� ���� �� ������ ���� �������. ���������� �������, � ���� ��� �������� �����. �� ����������� �� �� �������� ��� ���� ������ ���� ����������� �������� � ���������� �� �������� � ���� ����������?";
                        link.l1 = "��, � �� ���� ���������, ���� ��� ��� ����� ������, ��������?";
                        link.l1.go = "Magis_Fuks_4";
                break;
                
                case "Magis_Fuks_4":
                        dialog.text = "����������, � ������, ��� �� ���� ������ ����� ����� ��� �������������. ��� ������ 5 000 �������?";
                        link.l1 = "��, ��������... ��� � ������� - ��������� ���� ������. ������ � ������ ������ ���� ����������� � ���������� ����� �������������� �� ����������� � ��� �����, � � �� ���� ��� ������. ����� ����� � ������� ��������.";
                        link.l1.go = "Magis_Fuks_Exit_Noquest";
                        link.l2 = "��� ��, �� 5 000 � �������� ������� �� ����� � ������� �� ������ ���������� �����.";
                        link.l2.go = "Magis_Fuks_5";
                break;
                
                case "Magis_Fuks_5":
                        dialog.text = "��� � �������, � ���, ��� �� ������ ������������ � ����. � ������ � ����. ����, ����� ���� ������� ������ � ������� ������ ������ ��� ����������� � ����� ���� �� ����� � ������ ����������� ����� ����. �������� �� ���� ������� �� ����� � ����� ���, �� ������� �������, �� ���� ������ ������...";
                        link.l1 = "� ������ �� ��� �������, ��� ����� ���� �� ����� ������� ��� ������ ������ � �������� � ������ ��� ��������?";
                        link.l1.go = "Magis_Fuks_6";
                break;
                
                case "Magis_Fuks_6":
                        dialog.text = "���������� ���������, �� ������� � ��������� �������, � �������� � ���� ������ ������ ���. � ���� �� ����� ����� ��� �����, ������� ����� ����� ��������� � ����� ���������. ���� � ���, � ��� ��������, � ������ ��� � �������, � �� ������� ��������� ��� - ��������� ���, ��� � ������ �� �������� ������������ �����������, � ����� ��������� ��� � ���������� ����� ��������� ����� ��������������. ��������, � ����� �����!";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_AcceptQuest_NextTime";
                        AddDialogExitQuest("Magis_Fuks_AcceptQuest");
                break;
                
                case "Magis_Fuks_AcceptQuest_NextTime":
                        dialog.text = "��� ������� ��������� ������ �����? ��� � ���? ��� ��� ������ � ��� �����?";
                        link.l1 = "���, � ��������� ��� ���� �� ������� ������ ������...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_AcceptQuest_NextTime";
                break;

// ����� ���� -->
				case "Klodt_Vian":
					dialog.text = "�����, ��, ����, � ����� �������.";
					link.l1 = "�� �������-��!";
					link.l1.go = "Exit";
					NextDiag.TempNode = "Klodt_Vian_0";
					AddDialogExitQuest("Magis_Fuks_alc");
				break;
				
                case "Klodt_Vian_0":
                    dialog.text = "�-�-����-�-�-���� ��, ��, ����-�-�-����� ���... ���... ������, ��� - �-�-��� ��� �������, ��, ������-�-��, �� �������?";
                    link.l1 = "� ����, ���� ������� � �������� �� ������ ����. �������-�� �����������������, ����� �� ����������� ��������� ������� �������� � ��������� ���� �� �������?  ������ ������, ���  ���� ���� ����� ��������� ���� - ���� ����� ������ ���������� ���������, � ����� ������ ��� ������.";
                    link.l1.go = "Klodt_Vian_1";
                break;

                case "Klodt_Vian_1":
                        dialog.text = "������ �������! ��, � ��-�-���� ������ �� �-�-�������, �? ��, �� � ������� ��, ��, ����������? � ��-�-�-���� ��� ���� �� ����, ��, ����� � ���-�-���� �� ������ � �����?";
                        link.l1 = "���� ������� ������� �� ����� ����� ����. ��, ������ ��, �������� � ����� �������. ��, ��� � ���� ��� �������������?! ��� �� ���� �������. � �������, �� ��� � ����� �����-�� ��������?";
                        link.l1.go = "Klodt_Vian_2";
                break;
                
                case "Klodt_Vian_2":
                        dialog.text = "������... ������... �����, ��, ������, ���? ��, ��... ������... ��, ��-��, ��-��, ���-���... ��... ������ �, ��,  ��-�-�-������ ��������...";
                        link.l1 = "��?! � ���!";
                        link.l1.go = "Klodt_Vian_3";
                break;

                case "Klodt_Vian_3":
                        dialog.text = "�-�-�-����? �� ��, ��... �-�-�������... � ����, ��, �� � ������� ������� � ������, ��, ���������� ���� ������... ���, ��, ���� ������, ��. ������-�-�-����, ��� ����� ����, ��.";
                        link.l1 = "�����, �� �����.";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Klodt_Vian_4";
                        AddDialogExitQuest("Magis_Fuks_exit_sit");
                break;
                
                case "Klodt_Vian_4":
                        dialog.text = "��� ���� ����-�-�����, ��, � � �������� � �����!";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Klodt_Vian_4";
                break;
                
// ������� ������ -->
                case "Semuel_Kartos":
                    dialog.text = "� ���� ���, ��, ���������� ��-�-������������.";
                    link.l1 = "���� � ���� ����. ��� "+GetFullName(CharacterFromID("Pirates_tavernkeeper"))+" ���� �� � ��� �� �������? �� �������� ����� ����� 3000 ��������...";
                    link.l1.go = "Semuel_Kartos_1";
                break;
                
                case "Semuel_Kartos_1":
                    dialog.text = "�-�-�, ����, ��, ������... � ���? ��, �� ��-�-�����, ����-�-�� � ����� ������?! � ���� ��, ��, ���!";
                    link.l1 = "����� ����, ��������, � ����� ������ ��� ��������� ���������� ���� ������.";
                    link.l2 = "����� �� ��� ���� ��� ���, ���������� ���������? ������ �������, ����� � ����, �������� ������ ����������, ��-������ ����� �������.";
                        
                    link.l1.go = "Semuel_Kartos_Kill";
                    link.l2.go = "Semuel_Kartos_2";
                break;
                
                case "Semuel_Kartos_2":
                    dialog.text = "�������� �� ����, ��, ��-�-�����... ������ � ����, ��, ������? ��� ����� 3000? � ���� � �����-�� ���, ��, �������� �� ���������� '�������� �����', �-�-�, ��, ���� ��... �� ��� ������ ������, ��, � ����� �������� ������ � � ��������� ��������. ����� ��� ������� �������� �� �������, ��... ����� �, ��, ������... ����� � ���... ����� �, ��, � ����� �... ������ �� �����...";
                    link.l1 = "�� ��, �������... �����, ����� ����� ����������, ����� ���-�� ������ ����� ���� ����� - � �� ����� ���� ������������� �� ����.";
                    link.l1.go = "Semuel_Kartos_No_Kill";
                break;
                
                case "Semuel_Kartos_No_Kill":
                    AddDialogExitQuest("Debt_Qust_No_Kill");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Payment":
                    dialog.text = "�-�-�, ��, ����� ��...";
                    link.l1 = "� �������� �� ���� ����, ������ �� ������ �� ������.";
                    link.l1.go = "Semuel_Kartos_Payment_1";
                break;
                
                case "Semuel_Kartos_Payment_1":
                    dialog.text = "��, ���?! ��?!! �� �������� ��� ����?!! ���� � �� ����, ��, ��� �������... � ����, ��, ���������� � ����...";
                    link.l1 = "��� �� ����� ������. ������ ��� �� �������. �����.";
                    link.l1.go = "Semuel_Kartos_Exit_No";
                    if (FindFreeRandomOfficer() > 0)
					{
						link.l2 = "��... ������� � ������ ����, ������ ��� �����-�� ���� ���������� �� ���-�� ����� ������.";
						link.l2.go = "Semuel_Kartos_Exit_Yes";
					}
                break;
                
                case "Semuel_Kartos_Exit_No":
                    AddDialogExitQuest("DebtQuest_NoKill_NO");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Exit_Yes":
                    AddDialogExitQuest("DebtQuest_NoKill_YES");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Kill":
                    AddDialogExitQuest("DebtQuest_Kill");
                    dialogExit();
                break;
				
//////////////////////////////////////
//	�������� ������
//////////////////////////////////////
		case "PrisonEscort_Officer":
			dialog.text = "���������� ������ ������! �������� � ����!";
			link.l1 = "��� ���������?!";
			link.l1.go = "PrisonEscort_Officer_1";
		break;
		
		case "PrisonEscort_Officer_1":
			dialog.text = "�������� ���������! ����� ������ � ��������� �� ����! �����, � ������� ����������� ���� �� �����!";
			link.l1 = "...";
			link.l1.go = "PrisonEscort_Officer_2";
		break;

		case "PrisonEscort_Officer_2":
			dialog.text = "�������� ���������! ����� ������ � ��������� �� ����! �����, � ������� ����������� ���� �� �����!";
			link.l1 = "...";
			link.l1.go = "Exit";
			DoQuestCheckDelay("PrisonEscort_ToPrison", 1.0);
		break;

// �������� ������ (������ ����)		
		case "PrisonEscort_EmilioMovo":
	                                                PlaySound("VOICE\Russian\gotica\MATTEO\DIA_MATTEO_HALLO_09_00.wav");
			dialog.text = "��� ���� ������!";
			link.l1 = "���� �������� ���-���� � ���������� �� ����������� �������, ����������� ����� � �����������?";
			link.l1.go = "PrisonEscort_EmilioMovo_1";
		break;
		
		case "PrisonEscort_EmilioMovo_1":
			dialog.text = "���������� ������... � ��� ���� � ����?";
			link.l1 = "��� �� ������ �� ���� ������.";
			link.l1.go = "PrisonEscort_EmilioMovo_2";
		break;
		
		case "PrisonEscort_EmilioMovo_2":
	                                                PlaySound("VOICE\Russian\gotica\MATTEO\DIA_MATTEO_PRICEOFHELP_09_01.wav");
			dialog.text = "100 ������� �����!";
			link.l1 = "����! ���������� ��� ��� ������.";
			link.l1.go = "PrisonEscort_EmilioMovo_3";
		break;
		
		case "PrisonEscort_EmilioMovo_3":
			dialog.text = "� ������� �� ��������� ���������, � ������ ���������� ����������� � ��� ��������.\n��� ���, ������� � ���� ����� �������� ������ '�������' � �������� ������ ��������� � ������� ����.\n������ � ������ �������� ��� � ��������� �� 10 ���� �� ��, ����� �� ��������� ���� �� ������ �� �����.\n�� ��������� ��, ��� �� ��� �����������, �� �� ��������� ��� ��� �� 5 ����, �� �� ����� �� ������� ������� ��������� ���� �� ������.\n�� ����� �������� � ������ ������� ��������� ����� ��������� - ��� ��������� �������� ������ �, ���� �� �����, �� ������� ���� ���� � �����������.";
			link.l1 = "� ��� ����� �������� ���� ������ � ���� ��� �����������, �� ������?";
			link.l1.go = "PrisonEscort_EmilioMovo_4";
		break;
		
		case "PrisonEscort_EmilioMovo_4":
			dialog.text = "��� ����� �������� - �� ����, � ���� ����� �� �����. ������ � �� ����� �������� �������� 100 ��������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "�� ��� ������� �����. ����� ���� �������.";
				link.l1.go = "Exit";
			}
			link.l2 = "������, �� � ���� ������ ������������ ���������� ��������� � � �� ���� ���� ���� ��������� ������.";
			link.l2.go = "PrisonEscort_EmilioMovo_5";
			
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_7";
			AddDialogExitQuest("PrisonEscort_ToSea");
		break;
		
		case "PrisonEscort_EmilioMovo_5":
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
			NextDiag.CurrentNode = "PrisonEscort_EmilioMovo_6";
			pchar.questTemp.PrisonEscort_quest = "Emilio_Movo_No_Money";
pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
			DialogExit();
		break;
		
		case "PrisonEscort_EmilioMovo_6":
			dialog.text = "� �� ���� �������� � ����� ���������, ��� ��.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_6";
		break;
		
		case "PrisonEscort_EmilioMovo_7":
			dialog.text = "� ��������� ��� ��� ��� ����. ������, ������� �� �������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_7";
		break;
		
		case "PrisonEscort_EmilioMovo_8":
			dialog.text = "������, ��� ���� �������! �� ������ ��� 100 �������� � �� ��������!";
			link.l1 = "�-��...";
			link.l1.go = "PrisonEscort_EmilioMovo_9";
		break;

		case "PrisonEscort_EmilioMovo_9":
	                                                PlaySound("VOICE\Russian\gotica\DIRTYPIRATE_man\SVM_7_ADDON_DIRTYPIRATE.wav");
			dialog.text = "���� ���������� �����!!!";
			link.l1 = "";
			link.l1.go = "Exit";
		break;
/*                
// ������������� � ������ "������������ ����" -->
                case "ExclusiveVineQuest_Smuggler":
                    dialog.text = "���� ���� ����� ����, ��������?";
                    link.l1 = "��, ��������, ������ ������.";
                    link.l1.go = "Exit";
                    link.l2 = "� �� ����� �� ����� "+GetCharacterFullName("Bridgetown_tavernkeeper")+", �� ���� �� ������� ��� ��� ���?";
                    link.l2.go = "ExclusiveVineQuest_Smuggler_1";
                        NextDiag.TempNode = "ExclusiveVineQuest_Smuggler";
                break;
                
                case "ExclusiveVineQuest_Smuggler_1":
                    dialog.text = "������ ��, �������. � ����������� ����� �� �����, �� ��� ���� ���� �� ������ ���������. ����������, ���� ���!";
                    link.l1 = "� ����, �� ������� � ������ ���� � ����� ������� �����!";
                    link.l1.go = "ExclusiveVineQuest_Smuggler_fight";
                    link.l2 = "� ���, � ������� ������������ ����� �������. �����, ���� ���.";
                    link.l2.go = "Exit";
                        NextDiag.TempNode = "ExclusiveVineQuest_Smuggler";
                break;
                
                case "ExclusiveVineQuest_Smuggler_fight":
                        AddDialogExitQuest("ExclusiveVineQuest_fight_vs_smuggler");
                    dialogExit();
                break;
                
                case "ExclusiveVineQuest_Smuggler_2":
                    dialog.text = "�������, ����������! � ����� ��� ��������� ����! � ���� �� ��������� ��� �����, �� ������� ��� ������ 1000 ��������. ����������, �� ��������!";
                    link.l1 = "1000 �������� ��������? ���� - ���� ��������� ����� � ����� �� 1000 ������� �����!";
                    link.l1.go = "ExclusiveVineQuest_Exit_NoKill";
                    link.l2 = "�� �� ���, ����� ������ ��� �� ������ ������� ���� ������� �����!";
                    link.l2.go = "ExclusiveVineQuest_Exit_Kill";
                break;
                
                case "ExclusiveVineQuest_Exit_NoKill":
                        NextDiag.CurrentNode = "ExclusiveVineQuest_NoKill";
                        AddDialogExitQuest("ExclusiveVineQuest_go_away_1");
                    dialogExit();
                break;
                
                case "ExclusiveVineQuest_NoKill":
                    dialog.text = "��������� ���, �������, ��� �������� ���� � �����!";
                    link.l1 = "...";
                    link.l1.go = "Exit";
                        NextDiag.CurrentNode = "ExclusiveVineQuest_NoKill";
                break;
                
                case "ExclusiveVineQuest_Exit_Kill":
                        AddDialogExitQuest("ExclusiveVineQuest_go_away_2");
                    dialogExit();
                break;
                
// ������� -->
                case "TailorQuest_HugoGreen":
                    dialog.text = "� �� ����, � ����, ����������� �� ����������� �����?";
                    link.l1 = "�� ������� ���, ����� ��� �����?";
                    link.l1.go = "TailorQuest_HugoGreen_1";
                break;
                
                case "TailorQuest_HugoGreen_1":
                    dialog.text = "��� �� �����?! ������� �� �� ���, ������� ������� ������� ������� ���������� ���������� � ����� ��������������� ������ �����. ";
                    link.l1 = "���� ���� �� ����������.";
                    link.l1.go = "TailorQuest_HugoGreen_2";
                break;
                
                case "TailorQuest_HugoGreen_2":
                    dialog.text = "���� �����, ���������� ������ ��� �� ����� ���������� ���.";
                    link.l1 = "��������. � ��� �� ��� ���������, ���������?";
                    link.l1.go = "TailorQuest_HugoGreen_3";
                break;
                
                case "TailorQuest_HugoGreen_3":
                    dialog.text = "���� � ���, ��� ��� ������� ������ ���������� � ����� ����� ������ ����� ������...";
                    link.l1 = "���������, � � ��� �� ���������� ����?";
                    link.l1.go = "TailorQuest_HugoGreen_4";
                break;
                
                case "TailorQuest_HugoGreen_4":
                    dialog.text = "� ���� � ���, ��� � ����� ������ ��������� ������������ �������. ��� ���, ��� ������� � ����� ���� � ������ - ������ ������ � ������� �� ���. � ��� ��� ������� ������� � ������� �� � ���, ��� ����� ������? �������. ����� ����, ��-�� ���, ������� �� ���� ���������� � ����� � ����������� ����������, � ���� ��� ������� ������ � �������� ��� �����. �������� �������� �� �����. �� � ��� - ���� ��������.";
                    link.l1 = "��� � ����� �����, �������. ��� �������� �������. ������.";
                    link.l1.go = "Exit_TailorQuest_HugoGreen";
                    link.l2 = "�������, � �� ��� ��� ������ � ����, ���� �� ������� �� ����������.";
                    link.l2.go = "TailorQuest_HugoGreen_5";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                break;
                
                case "TailorQuest_HugoGreen_5":
                    dialog.text = "�, ��������� ���, �� ����� �����! ����������, � �� ���� � ��������...  ��� ������ ���-���� �������� - ��������, ����������. � ���� ����� ��� �����.";
                    link.l1 = "�� �������";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_start");
                break;
                
                case "TailorQuest_HugoGreen_SeconTime":
                    dialog.text = "� ����� ��������������� � ��������� - ���� �������!";
                    link.l1 = "�� ���� ��� ���������.";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                break;
                
                case "TailorQuest_HugoGreen_Finish":
                    dialog.text = "� � ��� ��� ��������. ��, ��� ��� ������� ������� ������� �������?";
                    link.l1 = "��. ��, � ��������, ��. ��� ����.";
                    link.l2 = "��. ��, � ��������, ��. ��� �����.";
                    link.l3 = "��. ��, � ��������, ��. ��� �����.";
                    link.l4 = "��. ��, � ��������, ��. ��� ���������.";
                        
                    link.l1.go = "TailorQuest_HugoGreen_6";
                    link.l2.go = "TailorQuest_HugoGreen_6";
                    link.l3.go = "TailorQuest_HugoGreen_6";
                    link.l4.go = "TailorQuest_HugoGreen_7";
                break;
                
                case "TailorQuest_HugoGreen_6":
                    dialog.text = "�������? �������, �� �����, � ������ �� � ���? ��� �, ��������� ��� �� ������ � ���� ���������� ��� ������ ������. ��������.";
                    link.l1 = "...";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_Finish_1");
                break;
                
                case "TailorQuest_HugoGreen_7":
                    dialog.text = "��, � ������ ������ ��?";
                    link.l1 = "��, ���� � ���, ��� ��������� ������ ������� � ���� ������, � ��������� ��� ��������� ���� �������, �� �� ���������� �� ����� ������� ������ ����� - �� ���� ���������...";
                    link.l1.go = "TailorQuest_HugoGreen_8";
                break;
                
                case "TailorQuest_HugoGreen_8":
                    dialog.text = "� ���� �� ����� � ������ � ������ �� ���� �� �������?! �������������, ���� ����� �� ����� � ����������! ��� �� ��� ��������  - � ��������� �� ������! ���������, ��������� ��� ��������. ��� ��� ��������� ������� �� ������. �������� �������, ���� �����, ��� ��������.";
                    link.l1 = "����� ��������.";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_Finish_2");
                break;
                
                case "Exit_TailorQuest_HugoGreen":
                        AddDialogExitQuest("TailorQuest_END");
                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                break;


//////////////////////////////		
// ������ ������� �����		
//////////////////////////////

// ������� �����
		case "OfficerVinsentVento_Vento":
			dialog.text = "�� ���-�� ������?";
			link.l1 = "���� ������ � ��� ����� � ������ ����������� � ��������� �����?";
			link.l1.go = "OfficerVinsentVento_Vento_1";
		break;
		
		case "OfficerVinsentVento_Vento_1":
			dialog.text = "�������� ���� � �����, ����� ���.";
			link.l1 = "��� �������, ������.";
			link.l1.go = "Exit";
			link.l2 = "� ����� ����� �� ��������, ������? � ��� ����� �������, ��� �� ������ ������� ������ ����������...";
			link.l2.go = "OfficerVinsentVento_Vento_2";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_1";
		break;
		
		case "OfficerVinsentVento_Vento_2":
			// if(GetReputationFromNation2Character(pchar, HOLLAND) < 60)
			// {
				// dialog.text = "� ���������� ������ ���������?! �������� ���� � �����!!!";
				// link.l1 = "...";
				// link.l1.go = "Exit";
				// NextDiag.TempNode = "OfficerVinsentVento_Vento_1";
			// }
			// else
			// {
				// dialog.text = "������� �� �������, ��� � ������ ���, �� ������ ������, ���� �������?! � ������� ���-��� � ����� �� ���� �����...";
				// link.l1 = "��� ���? � ��� �� �� ������ ��������?";
				// link.l1.go = "OfficerVinsentVento_Vento_3";
			// }
		break;
		
		case "OfficerVinsentVento_Vento_3":
			dialog.text = "����� � ����� ������� �����������.";
			link.l1 = "�, �������, ���� ���������, �� ����� � ����������� - ��� �� ������� ������. �� ���, �� ������? ������ ��� ������ � �������������� �������� �� ����� � �����������!";
			link.l1.go = "OfficerVinsentVento_Vento_4";
		break;
		
		case "OfficerVinsentVento_Vento_4":
			dialog.text = "�� ���� �! ��, ���� ������, ��� �� ����!";
			link.l1 = "��� ��, ����� ��� ������� �������.";
			link.l1.go = "OfficerVinsentVento_Vento_ExitNoQuest";
			link.l2 = "���� �� ����������, ��� �� ����� � ��� �� ��������, � ������ ��� - ������-�� ��� �� ����� ������.";
			link.l2.go = "OfficerVinsentVento_Vento_5";
		break;
		
		case "OfficerVinsentVento_Vento_5":
			dialog.text = "������? ���� ������, ������, ��� ������ ������� �� ��������... ���������, � ��� ����������� �������� �����. ��� �����, ���������� �� ������, �������� ��������. �� ����� ������� ��� ��������� ����� �������� �����, � ���, ����� �� �����, ��� ��������� ����� �������, ������������ ������ ����������, �� ������� � �����������.";
			link.l1 = "...";
			link.l1.go = "OfficerVinsentVento_Vento_6";
		break;
		
		case "OfficerVinsentVento_Vento_6":
			dialog.text = "����� � �� ����� � ���������� � ����������. ���� �� ����� �����, �� � � ����� ��������� � �������, ���������� ���� �����������, � �� ������ �� ���� ���� � ����� ������. ��, ������, ����� � �� ������� � ���������� � ����������. ����� ����� ������ ����� ���������, ����� ��� ��������� ���� � �������, ������ ����� � ������� - ������ � ����������� ���!!!";
			link.l1 = "���... ����� �� ����� ����� �����?";
			link.l1.go = "OfficerVinsentVento_Vento_7";
		break;
		
		case "OfficerVinsentVento_Vento_7":
			dialog.text = "�� ��� ��! � ����� �����, ��� ������� ��� � �����, ������� ���! ������ ���� �� ��������� �������� ��� �������! ��� ������?!";
			link.l1 = "������, � ��� �� ������-�������� ������. ������ ���� ������ � ������� � ������ ������� �����������!";
			link.l1.go = "OfficerVinsentVento_Vento_ExitNoQuest";
			link.l2 = "������� ���� � �����, ���� �� ����������� ������! �����, ��� �� � ����, �������� �������� ���-������.";
			link.l2.go = "OfficerVinsentVento_Vento_ExitYesQuest";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_8";
		break;
		
		case "OfficerVinsentVento_Vento_8":
			dialog.text = "�� ������ ���� ���-������ � ��������� ����������?";
			
			link.l1 = "���� ���, �� � ������� ��� ���� ��������.";
			link.l1.go = "Exit";
			
			if(pchar.OfficerVinsentVento_quest == "Bill")
			{
				link.l2 = "��. ����� ��� ����� ������ �� ���� �� �������.";
				link.l2.go = "OfficerVinsentVento_Vento_9";
			}
			if(CheckCharacterItem(pchar, "OfficerVinsentVento_Documents") || CheckCharacterItem(pchar, "OfficerVinsentVento_DocumentsCopy"))
			{
				link.l2 = "��, ��� ������� ����� ���� �������. �� ����� � ��� ���� ������, ��, ������ ���, �� ��� ������� ����.";
				link.l2.go = "OfficerVinsentVento_Vento_14";
			}
			
			NextDiag.TempNode = "OfficerVinsentVento_Vento_8";
		break;
		
		case "OfficerVinsentVento_Vento_9":
			dialog.text = "��� ����� ���� ���? � ������ ��� ��?";
			link.l1 = "��� - ��� ������ ������������ ������� ������� ��������, �� ���� ��� ����� � ������� ������, ��? �� ��� ��� �� ����������, ��� � ����?!";
			link.l1.go = "OfficerVinsentVento_Vento_10";
		break;
		
		case "OfficerVinsentVento_Vento_10":
			dialog.text = "���� ������, ��! ��� ������ ����� ���� �����! ���� �� ����������, ����������!";
			link.l1 = "�������� ������ � ������, �������� ���� � ��� ����.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_11";
			AddDialogExitQuest("OfficerVinsentVento_ToBillHouseVsOfficer");
		break;
				
		case "OfficerVinsentVento_Vento_11":
			dialog.text = "�� ����������� � ����� ��������� ����������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_12";
		break;
		
		case "OfficerVinsentVento_Vento_12":
			dialog.text = "�������� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_13";
		break;
		
		case "OfficerVinsentVento_Vento_13":
			dialog.text = "�� ��� �� ������� �����! ������! �� ��� ��� ���-�� ������! ��� ������ ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_14";
		break;
		
		case "OfficerVinsentVento_Vento_14":
			dialog.text = "�������, �� ������� ��� ���������� ������. � �� ���� ������������� ��� ��������, �� �������� ��� ��������, ���� �� � �� �� �������, �� �������� ��������.";
			link.l1 = "�������, �� � �� ���� ������� �� ��� ���� �������, �� � ����-�� ���� ����������.";
			link.l1.go = "OfficerVinsentVento_Vento_15";
			link.l2 = "������� �� �������, � ����� ���, � ��������� ��� ������ ������������ � ����������-�� �����������.";
			link.l2.go = "OfficerVinsentVento_Vento_16";
			AddDialogExitQuest("OfficerVinsentVento_Complette1");
		break;
		
		case "OfficerVinsentVento_Vento_15":
			pchar.OfficerVinsentVento_quest = "no_gun";
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_16":
		                 pchar.OfficerVinsentVento_quest = "gun";
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_ExitYesQuest":
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("OfficerVinsentVento_Start");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_ExitNoQuest":
			AddDialogExitQuest("OfficerVinsentVento_NoQuest");
			DialogExit();
		break;

// ���
		case "OfficerVinsentVento_Bill":
			dialog.text = "���� ���� ����� ����?";
			link.l1 = "������, ������ �����.";
			link.l1.go = "Exit";
			link.l2 = "���� � �� ��������, ���?";
			link.l2.go = "OfficerVinsentVento_Bill1_1";
			NextDiag.TempNode = "OfficerVinsentVento_Bill";
		break;
		
		case "OfficerVinsentVento_Bill1_1":
			dialog.text = "��������, � ��� ���� �� ���� ����?";
			link.l1 = "������ �� ������ � ������� �������� �����?";
			link.l1.go = "OfficerVinsentVento_Bill1_2";
		break;
		
		case "OfficerVinsentVento_Bill1_2":
			dialog.text = "����� �������? �� ��� �����?";
			link.l1 = "� ������� "+GetCharacterFullName(pchar.id)+"! � ���� �� �� ������ ��� ������� ��-��������, ��� �������� ������� �� �����.";
			link.l1.go = "OfficerVinsentVento_Bill1_3";
		break;
		
		case "OfficerVinsentVento_Bill1_3":
			dialog.text = "�������� ������, ���� ���!";
			link.l1 = "������� � ���� �� �����, �� ����� ������� ���� ���������, �� �� ��� ��������� � ���, ��� �� ������� ������ ������ ��-��������.";
			link.l1.go = "OfficerVinsentVento_Bill_ExitNoDocuments";
			link.l2 = "���? �� ��� ���������?! ��! ����� ����� ��� �������� � ����� ������� ��� ��� ��� �� �����������!";
			link.l2.go = "OfficerVinsentVento_Bill_FightVsBill";
		break;
		
		case "OfficerVinsentVento_Bill_ExitNoDocuments":
			NextDiag.CurrentNode = "OfficerVinsentVento_Bill1_4";
			AddDialogExitQuest("OfficerVinsentVento_FormBillWithoutDocuments");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Bill_FightVsBill":
			NextDiag.CurrentNode = "OfficerVinsentVento_Bill1_5";
			AddDialogExitQuest("OfficerVinsentVento_FightVsBill");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Bill1_5":
			dialog.text = "������, �� ���� �����! ����� ��� ��������� �������, ���� ����!";
			link.l1 = "�� ���, ��� �� � �����, ���� ������-�� ������ ����?";
			link.l1.go = "Exit";
		break;
		
		case "OfficerVinsentVento_Bill1_4":
			dialog.text = "���� ������� �������, �������, ��� �� ��� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill1_4";
		break;
		
		case "OfficerVinsentVento_Bill2":
			dialog.text = "������ ������! ��� �� ������ � ���� � ����?";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill2_1";
		break;

		case "OfficerVinsentVento_Bill2_1":
			dialog.text = "����� ����������? � ������ �� ����! � ������ �� ����! ��� � ���� ������� ����������!!!";
			link.l1 = "���� ������ � ������� �������. �� ����� ����� �� ��������, ����� ����� � ���� ������� ������. �������, �� �� ������� ����������, ��� ��� ������ �����������?";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill2_2";
		break;
		
		case "OfficerVinsentVento_Bill2_2":
			dialog.text = "��� �� ���� ����������?!";
			link.l1 = "����� ��� ��� ����������� ��� ����. ���� ��������� � ����������, �� ��� ����� ������� ��� ��, � ��� ������ ���� ��������� ��������!";
			link.l1.go = "OfficerVinsentVento_Bill2_3";
		break;
		
		case "OfficerVinsentVento_Bill2_3":
			dialog.text = "��������?! � ����������� ������! ������ � �������� ���������, ��� �� ������ �������� � ��������! �� ���...";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// ������
		case "OfficerVinsentVento_Soldier":
			dialog.text = "������, ����������, �����-�� ������...";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// ������ ��������
		case "OfficerVinsentVento_KarlosVelaskes":
			dialog.text = "�� ������ �������� � ���� �������?";
			link.l1 = "�� ������, ��� �����, ����� �� ������� ����� ����� �����, � ������ ��������.";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_1";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_1":
			dialog.text = "��-��, ��-��, ��� ��� � ���... ��, �������� ���������, �� ������ ��� ������ �� ������� �����-�� ����������...";
			link.l1 = "� �� ������ ������, ��������� � ���, ��������� ���� �� ������ ��������. � ������, ���� �� �� ����� ����� �����.";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_2";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_2":
			dialog.text = "�����-�����, �� �����, ������� ���, �� � �� ���� ������� - ������, �������, �������, ��� ��� ������ ��������������� �������. ����������-�� � �������, �� ������ ��� ����� ��� ������.";
			link.l1 = "� ������� �� ������?";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_3";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_3":
			dialog.text = "1000 �������� �� ������ ����, ����� 4000 ��������.";
			if(sti(pchar.money) >= 5000)
			{
				link.l1 = "� ������� ���� ������ ��� 1000 �������� �� ���� �������� � �� ���������.";
				link.l1.go = "OfficerVinsentVento_KarlosVelaskes_5";
			}
			link.l2 = "��, �����, ��� �� ����� �����, ������ � ������ ��� ��� ��������, ���� �����, ��� �� ����������� ����-�� - ��-��� ����� �������!";
			link.l2.go = "OfficerVinsentVento_KarlosVelaskes_Exit";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_Exit":
			NextDiag.CurrentNode = "OfficerVinsentVento_KarlosVelaskes_4";
			DialogExit();
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes_NO");
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_4":
			dialog.text = "�������, ������� � ���-���� ������� ��� �������.";
			link.l1 = "���, �� ������.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_4";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_5":
			dialog.text = "��� ��, � ���� ������� ����� ����, ��� ���������. ����� 24 ���� ����� ����� ������. ���� ��������� �� ���� �������, ��� �� �� �������� �� �� ���������!";
			link.l1 = "���������... �� ������.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_6";
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes_YES");
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_6":
			dialog.text = "��� ����� � ���������.";
			link.l1 = "���� ��������! �� �� � ������ �� ��������!!! ������� ����, � ����� - ������ �� �����.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_4";
		break;
/////////////////////////////////////////
// ������ �������� ��� �������� �������
/////////////////////////////////////////		
		
// ����� � ������� �������
		case "FindShipCuracaoTrader_pirate":
			dialog.text = "���� � ���� �� ��� ���� - ������, ���� ��� - ����������, �� ����� ��� ��������.";
			link.l1 = "� �� �������� �� ����� "+GetCharacterFullName("LaVega_Hovernor")+". �� ����������� ���������� � ����, ������, ��� �� ������ ��� ������� �����, ������� ��� ����� �������.";
			link.l1.go = "FindShipCuracaoTrader_pirate_1";
		break;
		
		case "FindShipCuracaoTrader_pirate_1":
			dialog.text = "��� ������ ����... ����� ���������� ������, ��������� � ����� ������ ����������.";
			link.l1 = "����.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "FindShipCuracaoTrader_pirate_2";
			AddDialogExitQuest("FindShipCuracaoTrader_ToTortugaTavernRoom");
		break;
		
		case "FindShipCuracaoTrader_pirate_2":
			dialog.text = "�����, ����������, ��� ��� � ����.";
			link.l1 = "��� ����� ������ ������, ��� ����� ������ � ��� ����� �������.";
			link.l1.go = "FindShipCuracaoTrader_pirate_3";
		break;
		
		case "FindShipCuracaoTrader_pirate_3":
			dialog.text = "��-��-��-��, ������, �� �� ���� ����� �� ������! �������-�� ��� ������� ������� ��� ������� ������ � � ��� � �������� �������� ������! ����� ��� ������ ���� �� ������� � �� �������� ���� �����.";
			link.l1 = "� ���� � ����������� � ����� ��������� �����? ������� ������� ������� � ������, � ��� ������� ����� ��� ������...";
			link.l1.go = "FindShipCuracaoTrader_pirate_4";
		break;
		
		case "FindShipCuracaoTrader_pirate_4":
			dialog.text = "���, � ��� ���� ������, � �� ��� ��������.";
			link.l1 = "�����, ���-����, �����������? ��� � ����� � ��� � �������� ����...";
			link.l1.go = "FindShipCuracaoTrader_pirate_5";
		break;
		
		case "FindShipCuracaoTrader_pirate_5":
			dialog.text = "������, ��� ��� ����, ���-�� �� ��� �� ���������. ���� ���������� ��� ������ ��� ���� �����, �� ��� � �� �������, � �� ��������� ���-�� ������! � �� �����, ���� ����� ����� ��� ��� �������?!";
			link.l1 = "��, ��� �������! ��-��-��-��!!! �����, ����� ������ ����� ��������� ������ � �������!";
			link.l1.go = "Exit";
			AddDialogExitQuest("FindShipCuracaoTrader_FightInTavernRoom");
		break;
		
// ������� �� ������
		case "FindShipCuracaoTrader_Ernesto":
			dialog.text = "������������, ����� �� ����, � ������!";
			link.l1 = "� �� � �������������, �� � ���� � ���� ���� ���� ���������� ������.";
			link.l1.go = "FindShipCuracaoTrader_Ernesto1";
		break;
		
		case "FindShipCuracaoTrader_Ernesto1":
			dialog.text = "� ���� ����������� � ����, ��-��-��-��.";
			link.l1 = "��� ���, "+GetCharacterFullName(pchar.id)+". ���� ����� "+GetCharacterFullName("Curacao_trader")+" - �������� ������ '��������', ����� � ���� ����. �� ����� ���, ��� �� ��������, � ���� �����, ��� �������!";
			link.l1.go = "FindShipCuracaoTrader_Ernesto2";
		break;
		
		case "FindShipCuracaoTrader_Ernesto2":
			dialog.text = "�� ������ ���� �������, ��� ����� �����!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("FindShipCuracaoTrader_PrepareFightVsErnesto");
		break;

///////////////////////////////
// ������ ����� ��� �����
///////////////////////////////
		case "DesertirMarko_PiratInTavern":
			dialog.text = "���� � ������, ������!";
			link.l1 = "�������, ��������!";
			link.l1.go = "DesertirMarko_PiratInTavern1";
		break;
		
		case "DesertirMarko_PiratInTavern1":
			dialog.text = "��� �������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_FightInTavern");
		break;

// ������ � �������
		case "DesertirMarko_SoldierInTavern":
			dialog.text = "��� ���� �������? ��-�-��, ��� ��� � ���, ����? �� ����������, ��������� � ����.";
			link.l1 = "������!";
			link.l1.go = "Exit";
		break;

// ��������������� ������
		case "DesertirMarko_DeserteerSailor":
			dialog.text = "������, ����� ���� ��������, � ��� ��� ������ �� ��.";
			link.l1 = "���-�� �� �� ����� �� ������...";
			link.l1.go = "DesertirMarko_DeserteerSailor_1";
		break;
		
		case "DesertirMarko_DeserteerSailor_1":
			dialog.text = "�� �����, � ������ �� ����� '����'. ��� ������� ������ ����������� ������, �� ����� ������ ���. ������ �� ������� ����� ������� �������� �������� �� �� ���� � �� �������������, ����� ��� ������� ������ ����� �����, � ��-����.";
			link.l1 = "������� �� ����� ��� ����� ��� ����� ���������?";
			link.l1.go = "DesertirMarko_DeserteerSailor_2";
		break;
		
		case "DesertirMarko_DeserteerSailor_2":
			dialog.text = "��, ������ ��, � ������ ��� �������� ��� ���?";
			link.l1 = "��, ������, ���� � ��������� ���������� ���������� �������! ������� ��������, ����� � ����� ������ ������� ��������, ��� � ���� ��� ����� � ��� ���� ��������! ����� ���, ���� ������ ��������� ����� ��� �����?";
			link.l1.go = "DesertirMarko_DeserteerSailor_3";
		break;
		
		case "DesertirMarko_DeserteerSailor_3":
			dialog.text = "� ������, �� ����� ����������� �� �������.";
			link.l1 = "��� ��, ������� ����. ����� 5 �������� � ������� �����.";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_ToTortuga");
			NextDiag.TempNode = "DesertirMarko_DeserteerSailor_4";
		break;
		
		case "DesertirMarko_DeserteerSailor_4":
			dialog.text = "� ������� ���������� ���, �������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "DesertirMarko_DeserteerSailor_4";
		break;

// ������ �� ������
		case "DesertirMarko_PirateOfficer":
			dialog.text = "�������, ��� ������� ������ ������?";
			link.l1 = "��� ��� "+GetCharacterFullName(pchar.id)+", � ��, ���� �� ��������, ������� ��� �����?";
			link.l1.go = "DesertirMarko_PirateOfficer_1";
		break;
		
		case "DesertirMarko_PirateOfficer_1":
			dialog.text = "���, ��� "+pchar.name+", � ��������� �� ����������. ���� ����� "+GetCharacterFullName(NPChar.id)+", � ������ �������� ��������.";
			link.l1 = "� ����� ������ ������ ������ ��������, � ���� � ���� �������� ����.";
			link.l1.go = "DesertirMarko_PirateOfficer_2";
		break;
		
		case "DesertirMarko_PirateOfficer_2":
			dialog.text = "�������, �� �����, ������� �������, � ��������� �� ����. ������� ��� ����� ����� �� ������ �������, ��������� '�����'. �� �������� ����� ��� �����, ��� �� � ��������� ��� ��� ������ ������.";
			link.l1 = "� ���� ���������� ��� �������?";
			link.l1.go = "DesertirMarko_PirateOfficer_3";
		break;
		
		case "DesertirMarko_PirateOfficer_3":
			dialog.text = "� ��� ��� ��� �� ���� ����. �� ��� �������, �� ������� � ���� ������ �������� - � �������, � ������ �������� �������� �������. ��� ���� � ��� �� ����� �����, � ��� ����� ����������� �� ����� ����� �� �������� � ��� ���������.";
			link.l1 = "���, ��� ������� ���������� � �����! ��, ���� ������� � ���, ��� ��������� �� ���� ������� - ���������. � ���� ��������� - ��������� ������ �������� ����� � ������. �� ��� ����, �� ��� ��� ������ �������, ���������� �� ������, ������� ���� �� ���. ��, ������! �� �������!!!";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_BoardingShooner");
		break;

// ����� ��� �����
		case "DesertirMarko_MarkoVanKleve":
			dialog.text = "��� ���� ����� ����? ��������, ��� ��� �������.";
			link.l1 = "� ������� "+GetCharacterFullName(pchar.id)+", ���� ������ �� ���� "+GetCharacterFullName("StMartin_prisonkeeper")+". � ������ ��������� ���� � ������ ������.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_1";
		break;
		
		case "DesertirMarko_MarkoVanKleve_1":
			dialog.text = "� �� �����, ��� � ������ ��� ��� ��� ������ � ����� � �����?";
			link.l1 = "� � ���� ��� ������, ���� �� �� ����������� ���, �� ����������� ����� �� ����� �������� � ������ ����������.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_2";
		break;
		
		case "DesertirMarko_MarkoVanKleve_2":
			dialog.text = "��! ��� ������ ������ � ���� �� ������ ��� �� �����!";
			link.l1 = "� � ��� ���� ��� �� �����. ������, ���� ���� ���� ������, ����� �� ���� ������� �� ������ ���������, ��-��-��-��. ��� ��� �� ���� �������, ������ ������ � ������ �� ����.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_3";
		break;
		
		case "DesertirMarko_MarkoVanKleve_3":
			dialog.text = "� ���� ����!!!";
			link.l1 = "� ��� ��� ���� ��...";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_FightVsMarko");
		break;

// ��������� ���������
		case "DesertirMarko_TavernOvner":
			dialog.text = "��� ����� �� ���?! � ����!!! �� ����� ����� ��������!!!";
			link.l1 = "�� �� ��� ��, ��� ����!";
			link.l1.go = "DesertirMarko_TavernOvner_1";
		break;
		
		case "DesertirMarko_TavernOvner_1":
			dialog.text = "������ ���, �������� ����, �� ��������! � ������ �� ����� �� �����, �������!";
			link.l1 = "���������, �� ���� � ���� �������, � ������� �� ����-�� ��� ���, ��� �������. ����� �������, ��� �� ������ �������� ���� �� �����... ������-��... ��� ���? �� �� �� ���!!!";
			link.l1.go = "DesertirMarko_TavernOvner_2";
		break;
		
		case "DesertirMarko_TavernOvner_2":
			dialog.text = "�����, �����...";
			link.l1 = "���, �����, ����� ����� �� ����� � �������, � � ����� ��� ������� �� ������ ������ � ������ ��� ������.";
			link.l1.go = "DesertirMarko_TavernOvner_3";
		break;
		
		case "DesertirMarko_TavernOvner_3":
			dialog.text = "��-��, �������, �����.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// ������ �� ��������
		case "AntiChurch_MIB":
			dialog.text = "��� � ���������, ��� � ����. � ��, ������� �� ������ � ������� ����-����� � ������ ������ �������. ����� � ��� ���� �������� ������.";
			link.l1 = "��, ������!";
			link.l1.go = "Exit";
			NextDiag.TempNode = "AntiChurch_MIB_PortRoyal";
		break;
		
		case "AntiChurch_MIB_PortRoyal":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
// ������ � ������� �� ��������
		case "Monk_in_Bermudes_tavern":
			dialog.text = "��� ��� ��, �������������, ����� ���� �������� ��������� ������ �������?!";
			link.l1 = "��, ��� �, � ������ ����� ������������� - ����������� ����� �� ���!";
			link.l1.go = "Monk_in_Bermudes_tavern_fight";
			link.l2 = "�? � ����� �����?! � ����� �� ������! � ������, � ����� ��������...";
			link.l2.go = "Monk_in_Bermudes_tavern_1";
		break;
		
		case "Monk_in_Bermudes_tavern_fight":
			AddDialogExitQuest("ChurchQuest_ENDGAME_in_BermudesTavern");
			DialogExit();
		break;
		
		case "Monk_in_Bermudes_tavern_1":
			dialog.text = "�������� ��������? ���������� ��������� � ����� ������� ������. � ���� ��� ����� ����������� ���������� � ����� ������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_to_Santiago");
		break;

// ����� � ������ �������� 		
		case "Monk_in_Santiago":
			dialog.text = "�� ���, ��������� ����, ����������� ������������ � ����� ������ ��� ����������? ������, ��� ������� ����������� ���� �������� �����.";
			link.l1 = "� �� �������, � ��� ��? ��� �����-�� ������� ������! ����� ���� ��������� ������, � ��������������� ���������!";
			link.l1.go = "Monk_in_Santiago_1";
		break;
		
		case "Monk_in_Santiago_1":
			dialog.text = "� ����, ��� ��� ����� �� ������� �� ����. � �� � ������������� ��� ������ ��������� �� � ��������� �������, �� ������ ���� �������. � ����� ����� ����� ������������ ��� ������������ - ������� ������, � �� ������ � �������.";
			link.l1 = "� �� ���� �������� �������� ������.";
			link.l1.go = "Monk_in_Santiago_2";
		break;
		
		case "Monk_in_Santiago_2":
			dialog.text = "�� �� ������ �������� ������� ������... ��-��-��-��! ������, � ���� ����� ����������� � ��� �������������, � ���� �����������, ����� �� ����� ������ ���� '��������� �����'.";
			link.l1 = "���������, �� �� ��� ��� �����?!";
			link.l1.go = "Monk_in_Santiago_3";
		break;
		
		case "Monk_in_Santiago_3":
			dialog.text = "������- ������,  ������ �������, �������� ������ ��� ���� � ���� �������� ���� ����, ����������.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// �������� � ������ ��������
		case "Man_in_SantiagoPrison":
			dialog.text = "��, �� ������ ���� ����������, ��� ������ ����� ���� � ����� �������.";
			link.l1 = "� ��� �� ����� � ��� ��� �� ���� �����?";
			link.l1.go = "Man_in_SantiagoPrison_1";
		break;
		
		case "Man_in_SantiagoPrison_1":
			dialog.text = "�� ������ ��� �� ����� �� ����. ������ ������, ��� ���� ����������, � ������ ��� ���� ������.";
			link.l1 = "��� �� ������? �� ���� �������� �������.";
			link.l1.go = "Man_in_SantiagoPrison_2";
		break;
		
		case "Man_in_SantiagoPrison_2":
			dialog.text = "���� �� ���� �����. �� ��� ������ ������, � �� �� �������� �����. �����, ���������, ����� ���������� �� ����� �������� ������.";
			link.l1 = "����� �������? � ���� ��� �� ������, �� �������...";
			link.l1.go = "Man_in_SantiagoPrison_3";
		break;
		
		case "Man_in_SantiagoPrison_3":
			dialog.text = "��� ���� ����, ���� ����� �� �����, ��� �������� ����������.";
			link.l1 = "�����, �������.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Man_in_SantiagoPrison_4";
		break;
		
		case "Man_in_SantiagoPrison_4":
			dialog.text = "�� ���, ����, ��� ����������.";
			link.l1 = "��, �������, ���� ���������, ����� ���� ��� ��� ��������.";
			link.l1.go = "Man_in_SantiagoPrison_5";
		break;
		
		case "Man_in_SantiagoPrison_5":
			dialog.text = "����� �� ������ ���� �������� ���� ������� ������������� � ��������� ����������.";
			link.l1 = "��, ����� �� ������, � �� ���, ���� �� ������?";
			link.l1.go = "Man_in_SantiagoPrison_6";
		break;
		
		case "Man_in_SantiagoPrison_6":
			dialog.text = "�� ������, �� ��� ����� ��� ���������. �������, ��� ������ ������? ��� � ��� � ���� � ����-�����, ��� � ������� ���������� � ��������, �� ���� ������ ��� ��� ������. \n������, ������ ��� ������������ � ���� �� �����, �� ������ ������� ��� ���� ����.";
			link.l1 = "�������, ��� �� ���� ���������?";
			link.l1.go = "Man_in_SantiagoPrison_7";
		break;
		
		case "Man_in_SantiagoPrison_7":
			dialog.text = "���� ���� ���������� �� �����-�������. ���, � ����� �� �����, ���� ����� ����� ����� ����� ������.";
			link.l1 = "��� ��� �� �������?";
			link.l1.go = "Man_in_SantiagoPrison_8";
		break;
		
		case "Man_in_SantiagoPrison_8":
			dialog.text = "�, ��� �������� �������. �� ������ ����� ����� ������� ���������� �������� �� ����� �� ��������� �������� �����. \n���������� �� ���������� �����, ��������� � ���� � ���� ������. ������� ��� ������� ���� ������. � �����������, �� ����������� ������� ��������� ����������. \n� ���, ������ ���, ��� � ���� ����, ��������� ��� ���� ������ � ����� ���������� '���������', ��, ���� �������� ���������, ������ � ����� ���� � ���� ������� � ��������.";
			link.l1 = "������, � ������ ��� � �����-�������, ���� ��� ��� �� �����������, ��� ���� ������ ���������...";
			link.l1.go = "Man_in_SantiagoPrison_9";
		break;
		
		case "Man_in_SantiagoPrison_9":
			dialog.text = "�� ���� �� ������������. � ����� ���� ��������, ������� ���� ������� � ������� � �����������, ����� ������� � ���� ��������� - ������ �������� ��� ��� ��������.";
			link.l1 = "��� ��� ��, ����� �� ������.";
			link.l1.go = "Man_in_SantiagoPrison_10";
		break;
		
		case "Man_in_SantiagoPrison_10":
			dialog.text = "���� �� ������? ��� � ��� �������  �������� ���� �������� ���������? ��-��. ����� ����, �������.";
			link.l1 = "�� ������� � ������� �� ������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_Santiago_shore");
		break;

// ������ � ���� ���-�����		
		case "ChurchQuest_SpOfficerInStJuan":
			dialog.text = "������ ����������� ���-����, �� ����������, ������. �� ��������� ���������� ������ ���������� ����, � ��� ��������� ���������� ������������ �� ����.";
			link.l1 = "��� �������, � �� � ��� �� �������, ������������ ���� ����.";
			link.l1.go = "ChurchQuest_SpOfficerInStJuan_END_GAME";
			link.l2 = "� ������ ���� �������� ��� ��������� ������ ���������� ����, ���� �� �� �������� ���� � �����, ������ ������. �����, ��� �������� �������� �� ����������...";
			link.l2.go = "ChurchQuest_SpOfficerInStJuan_1";
		break;
		
		case "ChurchQuest_SpOfficerInStJuan_END_GAME":
			AddDialogExitQuest("ChurchQuest_MIB_in_SanJuanHouse_ENDGAME");
			DialogExit();
		break;
		
		case "ChurchQuest_SpOfficerInStJuan_1":
			dialog.text = "�� ��, ��������. �� ��� �, �� ������ ��� ��� ����� �� ����, �����!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_in_SanJuanHouse_man");
		break;
		
// ����� ������
		case "ChurchQuest_SezarCarmin":
			dialog.text = "��� �� �����, � ��� ��� �� ���� ����? � ������� ������ ������ � � ���� ��� ������ �������.";
			link.l1 = "�� ��������� �� ���. � �� ��������� ���� �������, ��� ����� ����� ������.";
			link.l1.go = "ChurchQuest_SezarCarmin_1";
		break;
		
		case "ChurchQuest_SezarCarmin_1":
			dialog.text = "�� ��� ������ �, �� � ��� �� ����, ������, ��� ��?";
			link.l1 = "���� � �� ���� ���� �����, � �������� ��������� �������, ����� ��������, � �������, �� ������.";
			link.l1.go = "ChurchQuest_SezarCarmin_2";
		break;
		
		case "ChurchQuest_SezarCarmin_2":
			dialog.text = "�, �������-��! � ��� � ������� ������ ������� ��������� ������. ������, ����� ���, ��������� ���� � ����!";
			link.l1 = "�����, ������� ����� �� ���, ������� ���������. �� ������ ���������� �� ������?";
			link.l1.go = "ChurchQuest_SezarCarmin_3";
		break;
		
		case "ChurchQuest_SezarCarmin_3":
			dialog.text = "������? ������, ������ �������, � ������ �����.";
			link.l1 = "����� ������, ����� ����������� �� �����.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_from_StJuan");
		break;
		
		case "ChurchQuest_SezarCarmin_4":
			dialog.text = "��������, �������, � ���������� �� ���� ������������.";
			link.l1 = "� � ���, ���������� ������, ��������?";
			link.l1.go = "ChurchQuest_SezarCarmin_5";
		break;
		
		case "ChurchQuest_SezarCarmin_5":
			dialog.text = "���� ������ ������� ���������� �������� ����, ������, ��������� ���, ��� ����� ����� ������ ��������� �������. ������, ���������.";
			link.l1 = "���� ���, ���������.";
			link.l1.go = "Exit";
		break;
		
		case "ChurchQuest_SezarCarmin_6":
			dialog.text = "�, ������! �������-�� � ���� ����� ���!!!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_7";
		break;
		
		case "ChurchQuest_SezarCarmin_7":
			dialog.text = "���� � ���� ����������, ������. ��������� ��� ���� ������ ������ ��������� ����������, ���� ���� ������� ��� � ���� ����. ����� ��������� ����� ���� ���������, ����� �� ��� �� ��������. \n������� ����� ��������� ��������� � ������ �������� ����� ��, ��� ��������� � ���� ����� ������. � ��������� ������, ��� ��� �� �������� ��� ���� ����������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_8";
		break;
		
		case "ChurchQuest_SezarCarmin_8":
			dialog.text = "�������, ������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_9";
		break;

// ������� �������		
		case "Florido_Elkano":
			dialog.text = "...";
			link.l1 = "��� ��� ��� �������� �������� � �������� ������... ������ �� ����������� �� ����, � ����� ����� ���������� ��������� ����.";
			link.l1.go = "Florido_Elkano_1";
		break;
		
		case "Florido_Elkano_1":
			dialog.text = "������ �� � ���� ����������� � ��������! � ����� ����!!! ��� �� ������� �� ���� � ��������� � ���-�����.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Florido_Elkano_2";
		break;
		
		case "Florido_Elkano_2":
			dialog.text = "���, � ������, ���� �����, ���� �� ������?";
			link.l1 = "��� ����� �� ���� ������ �� ����, � ��� ����, ��� ������� �� ����� �������, ����� ������ � ����� ����������.";
			link.l1.go = "Exit";
		break;
		
		case "Florido_Elkano_3":
			dialog.text = "�� �����, ��� �� ����� ���������, �������.";
			link.l1 = "�� � � �� ����� ���� ��������� � ������ �������, �������.";
			link.l1.go = "Florido_Elkano_4";
		break;
		
		case "Florido_Elkano_4":
			dialog.text = "������ ����� ��������� ���� �������, �������, �� ��������� ����� �������?";
			link.l1 = "�� ���� �� ���������, ����� �� ���� ����� ������������, ����� � ����� ������� ���� ��� �� ����.";
			link.l1.go = "Florido_Elkano_5";
		break;
		
		case "Florido_Elkano_5":
			dialog.text = "��, ���� �� ��� ����� ��� ������ �� �����.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// ������� � ����� ������
		case "Animist_in_Beliz_bank":
			dialog.text = "�, �������, ��, �������, ������� �������!";
			link.l1 = "��, ����, ��� ������� �������! ��� �� � ���� ��������, ���� �� ����� ��� ������ ��������� �� ���� ���. ���� ��� ���������...";
			link.l1.go = "Animist_in_Beliz_bank_1";
		break;
		
		case "Animist_in_Beliz_bank_1":
			dialog.text = "������, �������, �� �� �������, �����, ��� ������ � ��� ��������� ����������.";
			link.l1 = "�����. ��� ������ � ���� ������� �����?";
			link.l1.go = "Animist_in_Beliz_bank_2";
		break;
		
		case "Animist_in_Beliz_bank_2":
			dialog.text = "�������, �� �������� �������, �� ��� �������� � ����, ���� �� ���� ������ ������� � �������.";
			link.l1 = "������, ������ ��� ��� ����� ������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_in_Beliz_bank_night_dialog_all_go_away");
		break;
		
//--------------------------------------------------------------------------------------------------------------------		
// ������ ���
		case "JoueBean_Joue_1":
			// dialog.text = "� ����, �� ���-���� ����� ����! �����, � ��� �� �����. ���� ����� �������, �� ��� ����� ���� ��������...";
			// link.l1 = "���?! "+FindRussianGreeting(pchar, 0, false)+", ��� � ���� ���������?";
			// link.l1.go = "JoueBean_Joue_2";
		break;

		case "JoueBean_Joue_2":
			dialog.text = "�� ���� ������ ����, � ��� �����. ��, � ����... � ������� ����!!!";
			link.l1 = "������, �� ����� �� ������? � ��� �� ��������? � ���� �� ����, � ����� �� �����.";
			link.l1.go = "JoueBean_Joue_3";
		break;
		
		case "JoueBean_Joue_3":
			dialog.text = "��� �� �� �� ����?! ��� �� ���� ��������� ����� �������� �� ����� ������ ���, � ������ ���������� ���������� ��������� ��� � ���������� ����������?";
			link.l1 = "�-�-�... ��� ��� ��� � ���� ���������. �...";
			link.l2 = "���, ����� ��� ������ �� ����������. � ������� �������, � ���������� ������ ����� ��������...";
			link.l1.go = "JoueBean_Joue_Exit1";
			link.l2.go = "JoueBean_Joue_4";
		break;
		
		case "JoueBean_Joue_Exit1":
			AddDialogExitQuest("JoeBean_RunAway");
			DialogExit();
		break;
		
		case "JoueBean_Joue_4":
			dialog.text = "�! ������� �����! ����� ����, � � ��� �����������. ��� �� �������, ��? � ��� �� �� ������ � ������?";
			link.l1 = "�-�-�... � ����� ����� ���� ����... � ������ �������, ��� �� �����, � ������ �����, ��� � ������ �� �����-�� �������?";
			link.l1.go = "JoueBean_Joue_5";
		break;
		
		case "JoueBean_Joue_5":
			dialog.text = "���� ����� ������ ���. ���� ������� ������������, �� ��� �� ���! ������ ������, ������, ��� � ������ �����. �� ��� � ��� ���� �������?! � ���� ���� ������������ ���� ���...";
			link.l1 = "�������, ������. � ��� �� �� ��� ������? �� �������, ��� ���� ������?";
			link.l1.go = "JoueBean_Joue_6";
		break;
		
		case "JoueBean_Joue_6":
			dialog.text = "� ����� �� ������, � �������� � ������. ����� ������� �����, ��� � ��������. ��� ������ ���������� �������. ��� ����� ������ � �������, � ������ �������. � ���������� ��� ������ ������, ���� ��� ����� �������. \n���, �� �� �������?! �������� ��� �������� ������, ������ ���!!!";
			link.l1 = "� ������ ���, ����� � ���� ���� �����������. �� ��������, � ���� ���� �������� � ������. ������ �� ����, ������, ���� ���� ������ �����!";
			link.l1.go = "JoueBean_Joue_Exit2";
			link.l2 = "��, � ������ ����. � �� ����� ���������. ������ ���� ����������� � ������ ���� �����������, ����� ��� ����� ������.";
			link.l2.go = "JoueBean_Joue_7";
		break;
		
		case "JoueBean_Joue_Exit2":
			AddDialogExitQuest("JoeBean_toHovernor");
			DialogExit();
		break;
		
		case "JoueBean_Joue_7":
			dialog.text = "������. ������ ��� ������, ������ ���� �������� ������!";
			link.l1 = "����� ������ ����. � ����� � �����, � ������� ��� � ��������� �����. ����� � ����� ���� �� �����. �� ������ ������ � �������. ��� �����? ���� �����, ������ �� ������ � ��� ����. � ��������� ������� ������� �� ����� � �� ��������� � �������.";
			link.l1.go = "JoueBean_Joue_8";
		break;
		
		case "JoueBean_Joue_8":
			dialog.text = "� ���, �� ���������, �� �����... � ���, �� ���������, �� �����...";
			link.l1 = "�������, ���.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "JoueBean_Joue_9";
			AddDialogExitQuest("JoeBean_help");
		break;
		
		case "JoueBean_Joue_9":
			if(pchar.location.from_sea == "Bridgetown_Shore2")
			{
				dialog.text = "��� �����? �, ��� ��, �������.";
				link.l1 = "�����? �� ������ �� ������ �� �������.";
				link.l1.go = "Exit";
				AddDialogExitQuest("JoeBean_help_go");
			}
			else
			{
				dialog.text = "� ���, �� ���������, �� �����... � ���, �� ���������, �� �����...";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "JoueBean_Joue_9";
			}
		break;
		
		case "JoueBean_Joue_10":
			dialog.text = "...";
			link.l1 = "�� ��� ��, ���? ��� ������?";
			link.l1.go = "JoueBean_Joue_11";
		break;
		
		case "JoueBean_Joue_11":
			dialog.text = "�? ���? ���?";
			link.l1 = "�� �� ������, ���� � ���� �������� ���� ���?";
			link.l1.go = "JoueBean_Joue_12";
		break;
		
		case "JoueBean_Joue_12":
			dialog.text = "�? ���, �� ������. � ����� ��� �������, � ��� �����. � �� ����� �������...";
			link.l1 = "���� �������. ��� ���� �� ������ �����������? � ���������� ���� ������...";
			link.l1.go = "JoueBean_Joue_13";
		break;
		
		case "JoueBean_Joue_13":
			dialog.text = "��� �����. �����, ����� ��������� � ����� �� ��������� �������. ��� ��������� ���� ����� �� ��������. � ���� ��, ��� ���� ��� � �����-�����, �� �� ����, ������� ��� ��������� ����������. ���� �� � �������� ���...";
			link.l1 = "� ��� ���� �������. � ������ �� ������, ����� ��������� ��� �������, �� �������!";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_to_ship");
		break;
		
		case "JoueBean_Joue_14":
			dialog.text = "��� �� � ��� ��� �����! �� ������� ��� ������� �� ��������, ������� ������ ���� ��������! ������ ��� ���� ����������� � ����������, ���� ���� ������� ���������, � ��� �������� ������ ������� ���.";
			link.l1 = "� ��� ������ �������? �� ���� �� �����, ��� � ������ ��� �������� ������? �� ����� ����� � � ��������� ��������� ��� �� ��� ������.";
			link.l1.go = "JoueBean_Joue_15";
		break;
		
		case "JoueBean_Joue_15":
			dialog.text = "�������, �������! �� ������� ������� ��� ����. ��������� ������ � �������, �������, ������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "JoueBean_Joue_16";
		break;
				
		case "JoueBean_Joue_16":
			dialog.text = "��, �������! � �����-�� ������������! ��������, ������. �� ��� ��� �������, ��� �������. � ������� ���, ����� ����� ������. �� ��� �����-�� ���������� �� ������!";
			link.l1 = "������ �� ������ ���. ��� ��� ��� ������ �������?";
			link.l1.go = "JoueBean_Joue_17";
		break;
				
		case "JoueBean_Joue_17":
			dialog.text = "���� ���� ������ 500 ��������. �� ������ ������ � �� ���� ���� ��� ������.";
			link.l1 = "��... ����� ����. �������� �������, �� ���� ���-��.";
			link.l1.go = "JoueBean_Joue_18";
		break;
				
		case "JoueBean_Joue_18":
			dialog.text = "� ��� � ������ ����������. ��������, �� ��� ���� ���������� ��� � ��� ������. ��� �� ����.";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_in_PortoBello_tavern2");
		break;
				
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		
		
//--------------------------------------------------------------------------------------------------------------------		
// ������ � ��������
		case "JoueBean_EngOff_1":
			dialog.text = "������! �� ����������� ������ ��������. �������, �� �� �������� ������ ���������������?";
			link.l1 = "���, ������ ������. ��� �� ��������� ��������.";
			link.l1.go = "JoueBean_EngOff_2";
		break;
		
		case "JoueBean_EngOff_2":
			dialog.text = "� ��� ���? ���, ����� � ����? ����� ����������...";
			link.l1 = "�, ��� ���... ���... �����, �����.";
			link.l1.go = "JoueBean_EngOff_3_1";
			link.l2 = "������ ������! ���������� �������!!!";
			link.l2.go = "JoueBean_EngOff_3_2";
			if(sti(pchar.money)>=4000)
			{
				link.l3 = "��� ��� 1000 ��������, �� ���������, � �� �������� ��������.";
				link.l3.go = "JoueBean_EngOff_3_3";
			}
		break;
		
		case "JoueBean_EngOff_3_1":
			dialog.text = "�����? �����? �, �����, � �� ����� ��������. �������, �� ��� ����� �������.";
			link.l1 = "�� �� ���, ������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_patrol_away");
		break;
		
		case "JoueBean_EngOff_3_2":
			AddDialogExitQuest("JoeBean_Barbados_patrol_fight");
			DialogExit();
		break;
		
		case "JoueBean_EngOff_3_3":
			dialog.text = "������ �� �������, ���.";
			link.l1 = "�� �������? �� ��������?! �, �����, ���������, ��� ���� ������, � ������, ��������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_patrol_away");
			AddMoneyToCharacter(pchar, -4000);
		break;
		
//--------------------------------------------------------------------------------------------------------------------		

//--------------------------------------------------------------------------------------------------------------------
// ������� � ������� �����-�����

		case "JoeBean_straight_man":
			dialog.text = "�� ��� �����? ��� �� ��� �����?!";
			link.l1 = "�� ���� ���? �� ���?!";
			link.l1.go = "JoeBean_straight_man_1";
		break;
		
		case "JoeBean_straight_man_1":
			dialog.text = "��� ��? ������� �� ��������, ��� � ������ ���� �����!";
			link.l1 = "� ������� "+pchar.lastname+". � ����� ����������� ������ ��������� ����...";
			link.l1.go = "JoeBean_straight_man_2";
		break;
		
		case "JoeBean_straight_man_2":
			dialog.text = "�� ������ ��� ������?!";
			link.l1 = "��, ������ ���. ��������� ������ ��� ��������. ��� �������� ��� � ���, ��� �� �� �������� - � ����� �����...";
			link.l1.go = "JoeBean_straight_man_3";
		break;
		
		case "JoeBean_straight_man_3":
			dialog.text = "��-��-��-��! ������ �� �������. ����, ��� �� ��� ������, ������ ���, �� ����� ���� �� ���, �� ���� ���� ������. ��� ��������� ��� ����� ������� ������. \n�� ��������� �����, ������� ����� ��� ������� � ����������. ��� �������� ����� �� � ����� �����, � ��� � ��� ������, �������! ���� ������� ���� ���� - ��� ���������� ������� � ������� � ��� ���� ��������� ����� ���. \n� ������ ��� ���� ���� � �� ������� ����, � ��� �� �� �� ����, �������� �� ����, �� ������� ����, �����. �������, �� ���������, � ��� �?";
			link.l1 = "�������, ��-�-�.. �� �� ������ ������ �����!!!";
			link.l1.go = "JoeBean_straight_man_fight";
			link.l2 = "��, � ��� �����.";
			link.l2.go = "JoeBean_straight_man_nofight";
		break;
		
		case "JoeBean_straight_man_fight":
			AddDialogExitQuest("JoeBean_in_PortoBello_in_tavern_room_fight");
			DialogExit();
		break;
		
		case "JoeBean_straight_man_nofight":
			dialog.text = "��� � ����������. � ������, ��� ���� ����.";
			link.l1 = "...";
			link.l1.go = "JoeBean_straight_man_nofight_exit"
		break;
		
		case "JoeBean_straight_man_nofight_exit":
			AddDialogExitQuest("JoeBean_in_PortoBello_in_tavern_room_nofight");
			DialogExit();
		break;

// ���������� �� �����
		case "Bartolomie_first_meet":
			if(sti(pchar.rank)<5)
			{
				dialog.text = "��� ����� �������� �� ������ ����, �� ��, ������, ��� ���� �� ���������!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Bartolomie_first_meet";
			}
			else
			{
				dialog.text = "��� ���������, ����? �� ������� ������ ��������� ����?";
				link.l1 = "� �������������, � ����� ��� ���������, ��� � ����� ������ ����� ���� ������!";
				link.l1.go = "Bartolomie_drink";
				link.l2 = "���, ������� ���.";
				link.l2.go = "Exit";
				NextDiag.TempNode = "Bartolomie_first_meet";
			}
		break;
		
		case "Bartolomie_drink":
			AddDialogExitQuest("TwoBrothers_Bartolomie_Start");
			NextDiag.CurrentNode = "Bartolomie_after_drink";
			DialogExit();
		break;
		
		case "Bartolomie_after_drink":
			dialog.text = "... ������, ������ �� ����� ��������. � ��, � ������, �������� ������, ������ ������, �� � ����, �����, ���� �� �����, ��-��-��-��! \n������, � ��� �� �������� �� ��, ����� ���������� ����-������ ��������?";
			link.l1 = "���������, �� �� ������� �� ����, ������� ����� ���� �������� ��� ����, ��-��-��-��! �� ���������� ��, ���� �. �����, ����������, ��� � ���� ��� �� ����, � ��� ����� �����.";
			link.l1.go = "Bartolomie_after_drink_2";
		break;
		
		case "Bartolomie_after_drink_2":
			dialog.text = "�� ����-�� ��������! ��� ������ ������� ������ ������� � ������� � ���������� ���������, � �� ���-������, � � ����-��-������!";
			link.l1 = "��, ������� ���������, �� ���� � � ����� �� ���������, ��� �� ����� ������� - � ������ �� �������� �����, ��-��-��-��!";
			link.l1.go = "Bartolomie_after_drink_3";
		break;
		
		case "Bartolomie_after_drink_3":
			dialog.text = "�� �� ����! �������� �������, � ����� �������! �� ���� � ������� � ��� ����� ���������, �� � ������ ���� ��� � ������� �������� �� �����! ������� � ��� ����, �� ��� ���� ���� ��������...";
			link.l1 = "�-�-�, ����, �� �� �� �� ������, � ������������� �� ���������, ��-��-��-��!";
			link.l1.go = "Bartolomie_after_drink_4";
		break;
		
		case "Bartolomie_after_drink_4":
			dialog.text = "������ �����! ������ ������� � ������ ���� ������ ������, ������ �� ���� ���� ���� ������ ���������! \n� � ��� ���� ��� ����� ������� ������, ��� � ���������� ����, �� ���� � ���, ��� ���� � ���� ������� ����, ������, �������, �� ��������� ��������� ������, �������� ���������� ����� ���� �� ������ � �� ������ ��� �. \n��� ���, ����������, �� ��� �� ���� ��������� - ��� ����� ��� � �������� �� ���, ����� �� ����� ������� ��� ������������. \n�� ��� �������� ������ � ������� ���� 3000 ��������. ��, ��� �������?";
			link.l1 = "��, �� �� �� ������, � �� ��������� �������� ��������� �������������. ������� �� �������, ��� ����, �����!";
			link.l1.go = "Bartolomie_after_drink_exit";			
			link.l2 = "������� �� ��������, 3000 ��������? �� ��� �, �������� �������� ������ ������.";
			link.l2.go = "Bartolomie_after_drink_take_quest";
			link.l3 = "���-�� 3000 ��������, ����� 5000 � � ���������� �� ������ ����������!";
			link.l3.go = "Bartolomie_after_drink_more_money";
			
		break;
		
		case "Bartolomie_after_drink_exit":
			LAi_SetPlayerType(pchar);
			NextDiag.CurrentNode = "Bartolomie_after_drink2";
			DialogExit();
		break;
		
		case "Bartolomie_after_drink2":
			dialog.text = "��� � ����� ������ �� � ��� �������������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_after_drink2";
		break;
		
		case "Bartolomie_after_drink_more_money":
			dialog.text = "�� ����� ��! �� 5000 � ���� ������ ����� ��������� ����������! ��, ��� ������ ���� �� ���� ��������, ����������, �� ��������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_after_drink2";
			LAi_SetPlayerType(pchar);
		break;
		
		case "Bartolomie_after_drink_take_quest":
			dialog.text = "��� � ������. ������ � ������� �� ����, ��� �� ����� ���������, ��, ���� �������� ������ �������, ��� ��������� �����-������ ����������.";
			link.l1 = "�����, ���-������ ��������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_start_find");
			NextDiag.TempNode = "Bartolomie_second_meet";
		break;
		
		case "Bartolomie_second_meet":
			dialog.text = "��, ���������, ��� ������? ������ � �� ���� � ����� �������?";
			link.l1 = "� ���� �� ����� ���...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_second_meet";
		break;
		
		case "Bartolomie_second_meet_real":
			dialog.text = "��, ���������, ��� ������? ������ � �� ���� � ����� �������?";
			link.l1 = "� ����� ���, �� ��, �����������, ������ �� ���� � ������ ������ ����. ��� ������� ���� ��� ����, ��� ���� ����� ������ ����. � ������� � ����� ������ ������������ ����, �� �� ������� ��������� ���� ������� � �������� �����������.";
			link.l1.go = "Bartolomie_second_meet_real_1";
		break;
		
		case "Bartolomie_second_meet_real_1":
			dialog.text = "� ��� � ����, ��� ���� ������ ���������, ��� ������� ��� ���� �����. � ���� ����� ������ ���, � ������ ��� �� ����������, ��� ��� ����� ��, �������� ������ �������� �������� ����� ��������� - � ������ � ���� � �����. ��� �� ������?";
			link.l1 = "� ����� ��� �� ��������, �� ����� ���������� ������ ��������� �� ���������� �� ���������.";
			link.l1.go = "Bartolomie_second_meet_real_2";
		break;
		
		case "Bartolomie_second_meet_real_2":
			dialog.text = "�����, � ����� ������ � ��� ���������� � ����. ������ ���� � ���� ����� �� ��������� � ��� �������� ���� 3000 ��������, ���� 2000 ������, �� �����������.";
			link.l1 = "����� ��� '����� �����'?";
			link.l1.go = "Bartolomie_second_meet_real_3";
		break;
		
		case "Bartolomie_second_meet_real_3":
			dialog.text = "�� � ��� ����� ���� �������� ����������, � ����� - ��� �����������. ����� �� ��������� ������, ���� � ����� � ������ ��������, � ��� ����� �������� �������� �� � ����. \n��, ����������, ���� ����� �������? � ����� - �� ������, �� ��������� ������.";
			link.l1 = "�����, �� ���� ������ � ���� �������� ��� ������ �� �������� � ���������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_Martinique");
			NextDiag.TempNode = "Bartolomie_second_meet_real_4";
		break;
		
		case "Bartolomie_second_meet_real_4":
			dialog.text = "�������, ��� ������ � ����� ��� ������ ����, ����� ����������� �� �������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_second_meet_real_4";
		break;
		
		case "Bartolomie_in_Martinique_tavern":
			dialog.text = "�, ��� ��. � ��� ����������� ������� ���������, ������ ������ ����� ��������� ������ �� ���� ������, ������ �� ������ ������ ������. ���� �� �� ������, ����� ���������� � �������.";
			link.l1 = "���� ��� ������� ������� ���� �������� � ������. � ���� �������� ���� ������, � �� ��� ��� ���������� � ���.";
			link.l1.go = "Bartolomie_in_Martinique_tavern_1";
		break;
		
		case "Bartolomie_in_Martinique_tavern_1":
			dialog.text = "�� �� ������� �� ���, �������� �� ���� ������. �����, ����, �� ��������!";
			link.l1 = "��, ������...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_in_Martinique_church";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_Martinique_church");
		break;
		
		case "Bartolomie_in_Martinique_church":
			dialog.text = "��, �� �� ����� ����� ������������?! �� � ���� ���� ���� � ���� �� ����������, � ��������� �� �����. ������ ������! ��� �� ��� ��� ���������?";
			link.l1 = "�� ����, ��� ���� ��������. ����� ��� ��� ������ ����� � ������, � �� ����� ������ ���������� ���.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "��... ���� �����, ���� ������ ������� ��� ��� ��� ��������?";
			link.l2.go = "Bartolomie_in_Martinique_church_1";
		break;
		
		case "Bartolomie_in_Martinique_church_closequest":
			dialog.text = "�� ��� �� �������, ������-������... ��� � ���� �����, ������ ��� - �����, ������� ����� �������, � ������ ������, ��������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_church_closequest");
		break;
		
		case "Bartolomie_in_Martinique_church_1":
			dialog.text = "������� ����! ���� �������� ���������� ����� �� �����, �������� ��������� � ��� �����! ���� �� �������� ��� �������� � ����������, � � ����� 5000 ������� ��� 10000 �������� �� ���������� ������ ������ �����.";
			link.l1 = "������ ��������, �� � � ���� ���� ���. ������� ��� ��� 5000 �������� � ����������.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "���� ������ ����� �� ������, �������� � �������� �� ��� ����, ��� ��� - �� �����, �� � ���� ������ � ���� 5000 ��������, ������� �� ��� � ��� ������.";
			link.l2.go = "Bartolomie_in_Martinique_church_3";
		break;
		
		case "Bartolomie_in_Martinique_church_3":
			dialog.text = "������ ����� ����� � ���� ���, �� ��� ������ ������ � ������ ����� ������, � ������ ���, - ���������� ��� � ������, � ����� ������� ����, ������� ����� �������! ���� �� �����������, � ����� ��������� ���� ����� ������, ��� ������! �������, ��� �� ����� �� ����, � 30000 ��������! \n������, ������ ������ � ����� ����. ���� ��� ���, �� ��� ���� - ��� �������� ����! ��� ��� ��������� �������� �� ��������, ����� ����.";
			link.l1 = "��� ������ � �� ��� ���� �� ��������.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "�����, ������ ��������, �� ���� �� ������������� �� ����, ����� �� ����!";
			link.l2.go = "Bartolomie_in_Martinique_church_4";
		break;
		
		case "Bartolomie_in_Martinique_church_4":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_to_house");
			DialogExit();
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead":
			dialog.text = "��! � �� ������ �� ������! � � ���� �� ������. ������� � ����� ������������ ��� ���� � �����, ������ ������� � �������, � � ����� �����������.";
			link.l1 = "�������, �� ������.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_in_Martinique_after_gastondead_nextday";
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead_nextday":
			dialog.text = "�, ��� ��, ���������. ��� ������, ���.";
			link.l1 = "� ���� ������� �������� ���� ������?";
			link.l1.go = "Bartolomie_in_Martinique_after_gastondead_nextday_fight";
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead_nextday_fight":
			DoQuestCheckDelay("TwoBrothers_Bartolomie_in_Martinique_jungle_band", 0.1);
			dialog.text = "� ������ ����� ������, � ����� ������ ��� ������, � ����� ������ ����� ������. ������ ������ ������ ������� � ���� ���������� ��������, � �� ���� ��� �� ���� �������� ����. ����� - ��� ������ ��� ����� ����� ����, ��-��-��-��! \n�� ����������� ���� �� ������, ������� ����� � ��������! ������ �������� ���������� �������������, ����� ��������� �� ��������� ����� ���, � ������ � ����� ������. �� ��� ����� ������� ��������� � � ����� ����� � �����. ����� ���������� ����, ��� �������� �������� ����� �, ����� ���� ������, �� ������ ��� ������������� �����. \n� �� ��� �������� ����� ����� ������� ��, ��� ������ ��, �� �� �������� �� �������, � ��� ���� - ���, ��-��-��-��! ��� � ����� ���� ���� �������, ����� �������� � ��, ��� ���������� �� ����� ������� � ������ ��� ������ 30 ������ ������-�� ����������. ������, ������� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_jungle_band_fight");
		break;
		
		case "Bartolomie_in_Martinique_fight":
			dialog.text = "� ������ ����� ������, � ����� ������ ��� ������, � ����� ������ ����� ������. ������ ������ ������ ������� � ���� ���������� ��������, � �� ���� ��� �� ���� �������� ����. ����� - ��� ������ ��� ����� ����� ����, ��-��-��-��! \n�� ����������� ���� �� ������, ������� ����� � ��������! ������ �������� ���������� �������������, ����� ��������� �� ��������� ����� ���, � ������ � ����� ������. �� ��� ����� ������� ��������� � � ����� ����� � �����. ����� ���������� ����, ��� �������� �������� ����� �, ����� ���� ������, �� ������ ��� ������������� �����. \n��� �������, ���� ������ � ��� ����, ������� ������ �� ��� ������? ������ ����� �� ������, � ������ ���� - ���. � ���� ������ ������ ��� ���������� ��� ����. ���� ��� �� �� �������� ���� ������. ������, ������� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_house_band_fight");
		break;
		
		case "Bartolomie2_first_meet":
			dialog.text = "�� ����� ��� ����������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie2_first_meet";
		break;
		
		case "Bartolomie2_first_meet_after_church":
			dialog.text = "������, ��������, ����� �� �������� ����������!";
			link.l1 = "����������? �� �� �� ����� ��?";
			link.l1.go = "Bartolomie2_first_meet_after_church_1";
		break;
		
		case "Bartolomie2_first_meet_after_church_1":
			dialog.text = "��! ������... �� ���� ��� ������ ������ �����!";
			link.l1 = "��� �� ����, �� � ����� ���� �� ������� ������. ���� ����, ������, ����������� ����.";
			link.l1.go = "Bartolomie2_first_meet_after_church_2";
		break;
		
		case "Bartolomie2_first_meet_after_church_2":
			dialog.text = "������, ��������? ���������, ��� ������������ ����� �������, � ������ �� �� ��������� �� ������� � ������ ������?";
			link.l1 = "��, ��������, �� � �����, �� ��� ���� ����...";
			link.l1.go = "Bartolomie2_first_meet_after_church_3";
		break;
		
		case "Bartolomie2_first_meet_after_church_3":
			dialog.text = "����?! ��-��-��-��, ��� ��� �������! ������� � ����� ������� ��� ��� � ������������ � �������! ���� ������ ������� ���� �� ���������� � ������! �����, ��������� � ���. \n�������  �� �������, �� ���� � ����� � ��� ���������, ��� ��� ����������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie2_meet_in_church";
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie");
		break;
		
		case "Bartolomie2_meet_in_church":
			dialog.text = "��, �� �� ����� ����� ������������?! �� � ���� ���� ���� � ���� �� ����������, � ��������� �� �����. ������ ������! ��� �� ��� ��� ���������?";
			link.l1 = "�� ����, ��� ���� ��������, �� ����� ������ ���������� ���.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "��... ���� �����, ���� ������ ������� ��� ��� ��� ��������?";
			link.l2.go = "Bartolomie2_meet_in_church_2";
		break;
		
		case "Bartolomie2_meet_in_church_2":
			dialog.text = "������� ����! ���� �������� ���������� ����� �� �����, �������� ��������� � ��� �����! ���� �� �������� ��� �������� � ����������, � ������� ���� 15000 �� ���������� ������ ������ �����.";
			link.l1 = "������ ��������, �� � � ���� ���� ���.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "���� ������ ����� �� ������, �������� � �������� �� ��� ����, ��� ��� - �� �����, �� � ���� ������ � ���� 5000 ��������.";
			link.l2.go = "Bartolomie2_meet_in_church_3";
		break;
		
		case "Bartolomie2_meet_in_church_3":
			dialog.text = "������ ����� ����� � ���� ���, �� ��� ������ ������ � ������ ����� ������, � ������ ���, - ���������� ��� � ������, � ����� ������� ����, ������� ����� �������! \n���� �� �����������, � ����� ��������� ���� ����� ������, ��� ������! �������, ��� �� ����� �� ����, � 30000 ��������! ������, ������ ������ � ����� ����. ���� ��� ���, �� ��� ���� - ��� �������� ����!";
			link.l1 = "��� ������ � �� ��� ���� �� ��������.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "�����, ������ ��������, ����� �������� ������ �����...";
			link.l2.go = "Bartolomie2_meet_in_church_exit_quest";
		break;
		
		case "Bartolomie2_meet_in_church_exit_quest":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_curch_quest");
			NextDiag.CurrentNode = "Bartolomie2_meet_in_house";
			DialogExit();
		break;
		
		case "Bartolomie2_meet_in_church_exit_noquest":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_curch_close_quest");
			DialogExit();
		break;
		
		case "Bartolomie2_meet_in_house":
			dialog.text = "��! � �� ������ �� ������! � � ���� �� ������.";
			link.l1 = "� ���� �������� ���� ������?";
			link.l1.go = "Bartolomie2_meet_in_house_2";
		break;
		
		case "Bartolomie2_meet_in_house_2":
			dialog.text = "� ������ ����� ������, � ����� ������ ��� ������, � ����� ������ ����� ������. ������ ������ ������ ������� � ���� ���������� ��������, � �� ���� ��� �� ���� �������� ����. \n����� - ��� ������ ��� ����� ����� ����, ��-��-��-��! �� ����������� ���� �� ������, ������� ����� � ��������! ������ �������� ���������� �������������, ����� ��������� �� ��������� ����� ���, � ������ � ����� ������. \n�� ��� ����� ������� ��������� � � ����� ����� � �����. ����� ���������� ����, ��� �������� �������� ����� �, ����� ���� ������, �� ������ ��� ������������� �����. \n� �� ��� �������� ����� ����� ������� ��, ��� ������ ��, �� �� �������� �� �������, � ��� ���� - ���, ��-��-��-��! ��� � ����� ���� ���� �������, ����� �������� � ��, ��� ���������� �� ����� ������� � ������ ��� ������ 30 ������ ������-�� ����������. ������, ������� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
		case "Bartolomie2_meet_in_house_3":
			dialog.text = "� ������ ����� ������, � ����� ������ ��� ������, � ����� ������ ����� ������. ������ ������ ������ ������� � ���� ���������� ��������, � �� ���� ��� �� ���� �������� ����. \n����� - ��� ������ ��� ����� ����� ����, ��-��-��-��! �� ����������� ���� �� ������, ������� ����� � ��������! ������ �������� ���������� �������������, ����� ��������� �� ��������� ����� ���, � ������ � ����� ������. �� ��� ����� ������� ��������� � � ����� ����� � �����. ����� ���������� ����, ��� �������� �������� ����� �, ����� ���� ������, �� ������ ��� ������������� �����. \n��� �������, ���� ������ � ��� ����, ������� ������ �� ��� ������? ������ ����� �� ������, � ������ ���� - ���. � ���� ������ ������ ��� ���������� ��� ����. ���� ��� �� �� �������� ���� ������. ������, ������� ���!";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// ������ �� �����
		case "Gaston_first_meet":
			if(sti(pchar.rank)<5)
			{
				dialog.text = "� ��� ��� �� ����� ������� - ������, �����������, ����� �� ��, ��� ����� � ����� �������� ��������!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Gaston_first_meet";
			}
			else
			{
				dialog.text = "� �� ����� ��� ����� ����� � ������, ���� ���������� ��, ��� ����� ��� ���� �����, �� ��������� � ��������� ����� ���������� ���� ���������!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Gaston2_2_meet";
			}
		break;
		
		// ������ ����� ������� �� ������� ������
		case "Gaston_first_meet_after_meet_with_Bartolomie":
			dialog.text = "��, ����, �� ���-�� ������?";
			link.l1 = "� ����� �� ��������� ������ �������� �����, ����������...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_1";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_1":
			dialog.text = "�! � ����� ������ � �������� ��� ��� ������, ����! ������, � ��� ����� �� ����� ������ �����, ��� ������� �� ���� ����������. �� � ������� �� ���� ��� �� ���������, ����� ��� ����������� �� ������, � ��� ��������� �� � ��������, ��� ������� �� ��� ���������... ��� �� �����������! \n��� ���� � ����������, ��� ��� �� ����, ������ � ������ � �����? ���� ������ �� ��������, � � ��� ����, ������ �����-��������, �� �����, ��� ���� � ��� �����������... \n��... ���-�� � ����������� ������, ��� �� ��������, ��� �������� ��� ����� ��� ���-�� ��������?";
			link.l1 = "���� ���� ����� �������� � ����� ������� ���� ������ ��������� ����...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_2";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_2":
			dialog.text = "���?! ���, ���������?!! ����� ����!!! ��� ����� ��� ���������? ������ �� ����? ������ ���, �� �������!";
			link.l1 = "���� �� �����, ���� �� �� �����, �� ������������ ��������� ���� ��� ����� � �� ����, ��� ��� �� ��� ������� �������� ���� �� �����...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_3";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_3":
			dialog.text = "����� ������! ����� ������!!! ����, ������� ���� ���� �� �����, � � ���� �� ���������� � ���! � ������� ���� ����� �� �����! \n��������, � ������ �� � ����� �������������, ������� ���������� ������ � ��������� ��������, � ������ ��� ���� ������ ������� �� ����� �����...";
			link.l1 = "��, ��...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_wait_one_day");
			NextDiag.TempNode = "Gaston_after_bad_news";
		break;
		
		case "Gaston_after_bad_news":
			dialog.text = "��������, �� ��� ������ �� �� ���...";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston_after_bad_news";
		break;
		
		case "Gaston_tomorrow":
			dialog.text = "�, ��� �� �����. � ��� ���������� � ����� ������, ������� ������� �������� ��� � ����. ����� �� ���-�� �������� � ����������...";
			link.l1 = "��, �� �������� ����� ���� � �������� � ���� � ����-�-�����, ����� �� ����� �������� ������ ������� ������ ���� �� ���������.";
			link.l1.go = "Gaston_tomorrow_1";
		break;
		
		case "Gaston_tomorrow_1":
			dialog.text = "������� ����, ��� �� ���������� � ����� �������� ����?! ������� � �����! �� ���� �� ����� ���� � ����!!! ��� ��� � ���������! � � ���������� ����������� �����. ���� �� �� �����, ��� � ���� ������ � ������������ ��������� ���� ����� ��������� ��������.";
			link.l1 = "��� �, ����� ��������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_PortPrince");
			NextDiag.TempNode = "Gaston_second_meet_after_meet_with_Bartolomie";
		break;
		
		case "Gaston_second_meet_after_meet_with_Bartolomie":
			dialog.text = "�, ��� ��... �� ������ ���� � �����������, ����� �� �����. ������� �� ��� �� ������ ��� ���� �� ��� ������, � ���� ����� �� ����� - ���������� �� ��� �������, ������� ������ �� ������. ����� � ���� ���, � ������� �� ����. � �� ��� �������� �� ������� ����, �� ���� �� ���� ���������, � ������� ��� 5000 �������� ����� ������.";
			link.l1 = "��� � ���� ������ ��� �����, � ������� ��� - ��������, ��� ��� �����-��, ������.";
			link.l1.go = "Gaston_second_meet_kill";
			link.l2 = "�������� �� �������! �����, � ����-�� � �� �������... � �����, ����� ���� ������ � ����������, � ������ ��������!";
			link.l2.go = "Gaston_second_meet_nokill";
		break;
		
		case "Gaston_second_meet_kill":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_kill_Gaston");
			DialogExit();
		break;
		
		case "Gaston_second_meet_nokill":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_house_not_kill");
			DialogExit();
		break;
		
		case "Gaston2_2_meet":
			dialog.text = "����� �� ��, ���������, ��� �������� ����� ���� ���� � ��������! ��� �� �������� ��� �����?";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_3_meet";
		break;
		
		case "Gaston2_3_meet":
			dialog.text = "�, ��� ��, ���� "+pchar.name+". ��� ��� ������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_4_meet";
		break;
		
		case "Gaston2_4_meet":
			dialog.text = "���-�� ��������� ����� � ���� �� ���� ����������, �����-�� ������ ������������ �� ���� ��� �����!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_5_meet";
		break;
		
		case "Gaston2_5_meet":
			dialog.text = "�! ����"+pchar.name+", ����� ��! ����� �����! � ��� ��� ��� ��������. � ���� ���� ���� - ����������, � ��� ����� �� �����, � ��������� ����� ���� ��������� �����-�� ���������� ��������, ��� ����� ���-�� ��������� � ����� �������. \n��� � � ����� ���������� � ����, ��������� ���, �� � ����� ��������, ���� �� ������, ��� �� ����, ��� ��������� ���-�� �������� �����. ���� �� ��������� ���� � ����-��-�����, � ������� ��� 3000 ��������.";
			link.l1 = "� ������������� ����� �� ����, �� � ���� ��� �����, ��� ��� ������.";
			link.l1.go = "Exit";
			link.l2 = "� ������ �� � ���? ����� ���������� �� ����!";
			link.l2.go = "Gaston2_exit_accept_quest";
			NextDiag.TempNode = "Gaston2_5_meet";
		break;
		
		case "Gaston2_exit_accept_quest":
			NextDiag.CurrentNode = "Gaston2_second_meet";
			AddDialogExitQuest("TwoBrothers_Gaston_begin");
			DialogExit();
		break;
		
		case "Gaston2_second_meet":
			dialog.text = "� ��� ���, ��� �� ����������� ��� ������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_second_meet";
		break;
		
		case "Gaston2_second_meet_Martinique":
			dialog.text = "���� "+pchar.name+", �� �� �������������, ����� ���� �������� �� ������! ��� ������������ ���� �� ��������! ����, ��� ������� ���� ������ � ��� ����, � � ���� �� ����� � ��� �����������! � ������� ���� ����� �� �����, �������!";
			link.l1 = "����� ��� ��������������.";
			link.l1.go = "Gaston2_second_meet_Martinique_1";
		break;
		
		case "Gaston2_second_meet_Martinique_1":
			AddMoneyToCharacter(pchar, 3000);
			AddPartyExp(pchar, 100);
			
			dialog.text = "�� ��, ���� �� �����, ��� ���� ������. �� �� ��������, �� � ���� �������� � ���� ��� ������� �� ������ ��������! ������ � ���� ������� ������ ����. �������� ��� �������� ���, ������ ���, � � ������� ��� ��� 3000!";
			link.l1 = "���, � ���� ����� ��� �������. ������.";
			link.l1.go = "Gaston2_second_meet_Martinique_no_quest";
			link.l2 = "� ������ ����. ��� �� ����� ����?";
			link.l2.go = "Gaston2_second_meet_Martinique_2";
		break;
		
		case "Gaston2_second_meet_Martinique_no_quest":
			NextDiag.CurrentNode = "Gaston2_third_meet_Martinique_no_quest";
			AdddialogExitQuest("TwoBrothers_Gaston_on_Martinique_no_quest");
			DialogExit();
		break;
		
		case "Gaston2_third_meet_Martinique_no_quest":
			dialog.text = "�������� ���� �� ����� � ���� �����...";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_third_meet_Martinique_no_quest";
		break;
		
		case "Gaston2_second_meet_Martinique_2":
			dialog.text = "������� �� ����, ��, ���� �������� ������ �����, ���� � ������������ �������, ��� �� ������, ������� ��� � ������, ���� � ����������� ������, ������� � ���� ���.";
			link.l1 = "�������... ��� �, �������� ��� ��������.";
			link.l1.go = "Gaston2_second_meet_Martinique_3";
		break;
		
		case "Gaston2_second_meet_Martinique_3":
			dialog.text = "����� ���, �������, � � ����� � �������, �������� �� ������ ���� ����.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_meet_Martinique_church";
			AddDialogExitQuest("TwoBrothers_Gaston_to_PortPrenc");
		break;
		
		case "Gaston2_meet_Martinique_church":
			dialog.text = "�, ��� ��, �������, ��� ���� �������, �������, ��� ��������� �����. ��� ����, ����� �������.";
			link.l1 = "��, � �����-��, �� �� ���.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_after_meet_Martinique_church";
		break;
		
		case "Gaston2_after_meet_Martinique_church":
			dialog.text = "�, ��� ��... �� ������ ���� � �����������, ����� �� �����. ������� �� ��� �� ������ ��� ���� �� ��� ������, � ���� ����� �� ����� - ���������� �� ��� �������, ������� ������ �� ������. ����� � ���� ���, � ������� �� ����. \n� �� ��� �������� �� ������� ����, �� ���� �� ���� ���������, � ������� ��� 5000 �������� ����� ������.";
			link.l1 = "��� � ���� ������ ��� �����, � ������� ��� - ��������, ��� ��� �����-��, ������.";
			link.l1.go = "Gaston2_after_meet_Martinique_church_kill";
			link.l2 = "�������� �� �������! �����, � ����-�� � �� �������... � �����, ����� ���� ������ � ����������, � ������ ��������!";
			link.l2.go = "Gaston2_after_meet_Martinique_church_no_kill";
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill":
			NextDiag.CurrentNode = "Gaston2_after_meet_Martinique_church_no_kill_1";
			AddDialogExitQuest("TwoBrothers_Gaston_in_Martinique_no_kill_Gaston");
			DialogExit();
		break;
		
		case "Gaston2_after_meet_Martinique_church_kill":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_house");
			DialogExit();
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill_1":
			dialog.text = "� ������ �������, ��� ��� �������� ������� ������� �� ���� ����, �� � ���, ��� �� �������� ��� �����. ��, ����������, ����������... � ����, ��� �� ����� ������, �� � � �������� �� ���, ��� � ������, ��� �� ������ �������, ��� �������, ��� ������� ������...";
			link.l1 = "��, �������� ���-�� ����������. ��, ��� �� ��� �� ����, � ��� ����. �������, ��� ����� �������������, �� ��� �� ������� ������� �������� �����.";
			link.l1.go = "Gaston2_after_meet_Martinique_church_no_kill_2";
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill_2":
			dialog.text = "�� ��, �������� ��... ��, ����� ����, ��� �� �������� ������ ������ ���������. ����������� �������� ����� ����� ������������� ����������� �������. ���� "+pchar.lastname+" � ������ ���� ��� ������ ��� � ���� � ������. ���� ��� �����-������ ����������� ����� ��� ������� - �� �����������, ��������.";
			link.l1 = "��� �, ��� ������� �������, �������, �� � ���������� �� �������������� ����� ���������������.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_sleep";
		break;
		
		case "Gaston2_sleep":
			dialog.text = "�! ���� "+pchar.lastname+"! ��� ������ ������ ������?";
			link.l1 = "� �� ����� ������������ � ���� �� ��������� �����.";
			link.l1.go = "Gaston2_sleep_1";
			link.l2 = "�� ������ ��� ����, ����� - ��� �����.";
			link.l2.go = "Exit";
			NextDiag.TempNode = "Gaston2_sleep";
		break;
		
		case "Gaston2_sleep_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			dialogExit();
			//LaunchSleep();
		break;
		
		// ������� ����������
		case "two_brothers_man":
			dialog.text = "������, �� ������������� ����� ������? ��� ���, �� ���� ���� �� �������. ��� � ������� �����, ����� ������� � ���� ����������� �������, �� ���������� �������� ���� ���������� ���� ����.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
//	-----------------------------------------------------------------------------------------------------------------------
//	��������� �����
		case "TohmasPetit_1":
			dialog.text = "������������, ���������. � ���� �� ��� ������, �� � ��������� ��� ������� ����...";
			link.l1 = "��, �� �� ������, � ������ ������� �� ����� ����.";
			link.l1.go = "TohmasPetit_2";
		break;
		
		case "TohmasPetit_2":
			dialog.text = "��� ������ ����� ������ ������ ��������, ��� ��!";
			link.l1 = "��� ���������, ��������?";
			link.l1.go = "TohmasPetit_3";
		break;
		
		case "TohmasPetit_3":
			dialog.text = "� � �������� ����� � ��������� �����, �� ����� �� ��� ������ �������! � ��� ���� ����, � ��� �������� ��� � ����. ��������, ������ ���! � ���� ����� ������� ��������, � ��� ������� �����������, �� ������������.";
			link.l1 = "������, ��� � ������� ���� ����������!";
			link.l1.go = "TohmasPetit_4";
			link.l2 = "�������� ������� ���� � ����? �� � ���� ������ ����� � ����� �� ����, ����� ���.";
			link.l2.go = "TohmasPetit_5";
		break;
		
		case "TohmasPetit_5":
			NextDiag.CurrentNode = "TohmasPetit_6";
			AddDialogExitQuest("TomasQuest_no");
			DialogExit();
		break;
		
		case "TohmasPetit_6":
			dialog.text = "�, ��� ��, ��� �������!";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "TohmasPetit_6";
		break;
		
		case "TohmasPetit_4":
			NextDiag.CurrentNode = "TohmasPetit_7";
			AddDialogExitQuest("TomasQuest_yes");
			DialogExit();
		break;
		
		//	�������
		case "TohmasPetitBandit_1":
			dialog.text = "� ��� ��� �� ����� ��� � ���?";
			link.l1 = "��������� ������� �, ��������, �� ���������� � �����.";
			link.l1.go = "TohmasPetitBandit_2";
		break;
		
		case "TohmasPetitBandit_2":
			dialog.text = "��������, ���� ����� ��� ��������. ������� ������� ����������� � ������ ����� ���.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			AddDialogExitQuest("TomasQuest_fight");
		break;
		
		//	�����
		case "TohmasPetitGirl_1":
			dialog.text	= "������� ���, ������ �������...";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "TohmasPetitGirl_2";
		break;
		
		case "TohmasPetitGirl_2":
			dialog.text = "���� ������� ������� ��� � ����� ���� ��������, ����� �� ��������� ���� �����, � ��������� � ��� ������, �� �� ���� �� ����.";
			link.l1 = "������ �������?! ��, ���, � ��� �����?! �� ���� �� �� � ��...";
			link.l1.go = "Exit";
		break;
		
		//	������
		case "TohmasPetitSoldier_1":
			dialog.text = "���, ��� ����� ����������?";
			link.l1 = "�� ���, ��� �������...";
			link.l1.go = "Exit":
			
			NextDiag.TempNode = "TohmasPetitSoldier_2";
		break;
		
		case "TohmasPetitSoldier_2":
			dialog.text = "�������� � ������ �� ����, � ��� ����������.";
			link.l1 = "���, ��� ��� �� � ���, � ������ ����? ��-��, �����, �������-�� ���������, �� ������ ����� �� �������!";
			link.l1.go = "TohmasPetitSoldier_fight";
			link.l2 = "�����, �����, ����.";
			link.l2.go = "TohmasPetitSoldier_prison";
		break;
		
		case "TohmasPetitSoldier_fight":
			DialogExit();
			AddDialogExitQuest("TomasQuest_soldiers_fight");
		break;
		
		case "TohmasPetitSoldier_prison":
			DialogExit();
			AddDialogExitQuest("TohmasPetitSoldier_go_prison");
		break;
		
		//	������
		case "TohmasPetitOfficer_1":
			dialog.text = "�������, �� ������ � ����� ���������� ���������, ��� � �� ����� ����� ����� �� �������������� ��� �� ������� ����������.";
			link.l1 = "���, ��� ��� �����?";
			link.l1.go = "TohmasPetitOfficer_2";
		break;
		
		case "TohmasPetitOfficer_2":
			dialog.text = "�� ����, ������, ����� �������� ������� �������, � ������� ��������� �������, �� � ���� '������' ��� ����. �������, �� ���������, � ��� �?";
			link.l1 = "� ����� ����� ���� ����?";
			link.l1.go = "TohmasPetitOfficer_3";
		break;
		
		case "TohmasPetitOfficer_3":
			dialog.text = "��, ������, 10000 ��������.";
			if(sti(pchar.money)>=10000)
			{
				link.l1 = "������, ������ � ���� ���. � ����� ���������.";
				link.l1.go = "TohmasPetitOfficer_money";
			}
			link.l2 = "� ���� ��� ����� �����.";
			link.l2.go = "TohmasPetitOfficer_executon";
			
		break;
		
		case "TohmasPetitOfficer_money":
			DialogExit();
			AddDialogExitQuest("TohmasPetitSoldier_free");
		break;
		
		case "TohmasPetitOfficer_executon":
			dialog.text = "��, ��� ������. ������� ������� ������ ���������, � ������ �� �������� ���� �����������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			AddDialogExitQuest("TohmasPetitSoldier_execution");
		break;
*/		
		case "Exit":
			if (CheckAttribute(NextDiag,"TempNode")) NextDiag.CurrentNode = NextDiag.TempNode; //[ds] changed
			DialogExit();
		break;
	}
}