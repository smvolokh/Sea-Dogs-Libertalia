// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("���������, ���� �� ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��������, ��� �������, ����� ���� �������� ���-��. �� �������� ����!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

    		//����� ������ ��������, ��������� ������
			if (pchar.questTemp.BlueBird == "begin")
			{
				dialog.text = RandPhraseSimple("�������, ����� ���, �������� ���!!!", "�������, � ����� � ��� ������ �� ����� ���� ���������!");
				link.l1 = "��� ���������? ��� � ���� ��� ������?"; 
				link.l1.go = "RBlueBird";
				break;
			}		

		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		����� ��������� ������ ��������
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "RBlueBird":
			dialog.text = "��, �������, �� ���������, � ��������� ��� �����. ��, �������� ���������� ����, �� ����� ���������. � �� ���� �������� ��������� '������ ��������'...";
			link.l1 = "'������ ��������'?";
			link.l1.go = "RBlueBird_1";
		break;
		case "RBlueBird_1":
			dialog.text = "��, ���� �������� ����, ���� �� ���� � ���� ����������. ������ ������ ������� ���������. ������� ��������, ��������� �������� ���������, �� �������.";
			link.l1 = "� ������ �� �������, ��� �������� ����������? ���� ������ ��� ����� ��������� ���� � ����� ����������.";
			link.l1.go = "RBlueBird_2";
		break;
		case "RBlueBird_2":
			dialog.text = "���������, �����. �� ��� ���� � ���, ��� ������ ��� ����� �������� ���������� ����������. ����� ����� ����� ���� ���� ��� �����, ����� �������� ������ � ������ ����� � ����� ����. ��� ��� - ��������!\n� ����� �� �������� ������ � ������������ - ��� ��� �� �� ��������, ���� ���� � ������� ���������.";
			link.l1 = "�������. � ��� ��� ���� ������� ����� �� ������� ����...";
			link.l1.go = "RBlueBird_3";
		break;
		case "RBlueBird_3":
			dialog.text = "������ ���. ��� ����� ��� �������� �������� ����������� �������, ���� �� ����, ��� '������ ��������'!";
			link.l1 = "�-��, �������� ��� ���... ��, ��� ��� �� �� ������ �� ����?";
			link.l1.go = "RBlueBird_4";
		break;
		case "RBlueBird_4":
			dialog.text = "�� �����, ����� �� ���������� ��� ���������� ��������, ���� �� ��������!!!";
			link.l1 = "� ��� � ���� � ����� �����?";
			link.l1.go = "RBlueBird_5";
		break;
		case "RBlueBird_5":
			dialog.text = "� ������ �� ���� ������ ��������� ������ ��� ��� �� ��� ������. ��������� ����� �������� � ���� ��� ������ �������. ������ ���� ������ ����� �� ���!";
			link.l1 = "�� ����� ������, ��������, � � ������� �� ��������. ��� ������!";
			link.l1.go = "RBlueBird_close";
			link.l2 = "��, ��� ������ ���� ����������. � �����"+ GetSexPhrase("","�") +" ������� �� ��� ����. ������ ����� ����������?";
			link.l2.go = "RBlueBird_6";
		break;
		case "RBlueBird_6":
			dialog.text = "�� �� ���������� �� �������. � ��������� �������, ��� ������� ��� ����� �������, ���� ������! ������� �� ������, �� ��� ���������� ������� ����� � ����� ����, ������ ������ ��������. ��������������...";
			link.l1 = "��� ���? �� ������ ��������� �� ���� ����������?";
			link.l1.go = "RBlueBird_7";
		break;
		case "RBlueBird_7":
			dialog.text = "��, ��������� �� � ������ ���-����, ����� �� �������� ���� ����� ����� ����� �������. ������ �� �����, ��� ������ � ������� ������ �� �������, �� ������ �� �����. ���� ��� �����, ��� ��� ���������� � ���� ������� ������������...";
			link.l1 = "��-�-�-��, ��������, ��� ��� ���-��. � ������ �������� ��� ������� ������.";
			link.l1.go = "RBlueBird_8";
		break;
		case "RBlueBird_8":
			dialog.text = "����������� ������, " + GetAddress_Form(NPChar) + "." ;
			link.l1 = "��� ������ ����� ����� � ����, ������ �������, ��� ������, �� ������ �� ������, ��� � ����"+ GetSexPhrase("��","���") +" �� ��� ����. � ������. �� ������, ��� �������� ���� ������� ����� ��� ��������. ��� ������ '�����'?";
			link.l1.go = "RBlueBird_9";
		break;
		case "RBlueBird_9":
			dialog.text = "� ������ �������� ������� �����. �� �� �����������, �� ���� �� ������� �� ���� ����. �� - ���� ������������ ������� ����������� �����, ��� ��� ���� ��� ������. ���� �� �� �� ����������� ��� � ������� ������ - ���� ����� ������ �� �����. �� ��� ������ �� ��������� � �������� ���� ����� � ����!";
			link.l1 = "�������. ����� ������! � ��� �� ��� �����?";
			link.l1.go = "RBlueBird_10";
		break;
		case "RBlueBird_10":
			dialog.text = "������� ������. �� �������� ����� �� ����-������ � ��������� ���������. ��� �� �������� �� ����?";
			link.l1 = "�� ���������� ��� ������� � ��������?";
			link.l1.go = "RBlueBird_11";
		break;
		case "RBlueBird_11":
			dialog.text = "����������!";
			link.l1 = "����� ������. � ������� ������ � ����� ���, ������� ������ ���������.";
			link.l1.go = "RBlueBird_12";
		break;
		case "RBlueBird_12":
			dialog.text = "��, ������ �� ������, �� ��� ����! �� ��� ��, �����������. ����� �������, ��� ��� ����� ��������� ���, ��� �� �������.";
			link.l1 = "�����, ������ �� �����������!";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "toBermudes";
			pchar.questTemp.BlueBird.traiderId = npchar.id; //�������� Id ��������
			SetQuestHeader("Xebeca_BlueBird");
			AddQuestRecord("Xebeca_BlueBird", "1");
			AddQuestUserData("Xebeca_BlueBird", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("Xebeca_BlueBird", "sName", GetFullName(npchar));
		break;

		case "RBlueBird_close":
			dialog.text = "�� ��� ��, ����� ����. �������, �� ������ '������' � ������ �����...";
			link.l1 = "��...";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "over";
		break;
		case "RBlueBirdWon":
			dialog.text = "���������� �������, ����� � ���! �������-�� �� ������ �������� ��������� ��-����������... �� ������ �������� ������ ����� ������?";
			link.l1 = "��, ����������...";
			link.l1.go = "RBlueBirdWon_1";
			int chComp;                                                             
			for (int i=0; i<=COMPANION_MAX; i++)	
        	{
                chComp = GetCompanionIndex(pchar, i);
                if(chComp != -1 && RealShips[sti(characters[chComp].ship.type)].Name == "VALCIRIA_QUEST1")
        		{	
					dialog.text = "��, ���������... ��������� ��� ��������, �� ������ ���������� ����, �� �� �������� ���! ������ �� ��������� � ����� ��������.";
					link.l1 = "��, ��� ���. �� � � ��� ��������?";
					link.l1.go = "RBlueBirdWon_10";
					break;
                }
            }
			break;

		case "RBlueBirdWon_1":
			dialog.text = "��� �������, �������� ��������. ������ � ��������. ����� ���� ������� ������ ���������� �����.";
			link.l1 = "�������, �� � �������. ����� ����� ����������... ������, � �� �� ������ ������, ��� ����� �� ���� ����?";
			link.l1.go = "RBlueBirdWon_2";
			TakeNItems(pchar, "chest", 4);
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+10;
		break;

		case "RBlueBirdWon_2":
			dialog.text = "��, ����� ����� ��������� ������...";
			link.l1 = "��� ����� '������' �������� � ��������� ���� - ������� ������.";
			link.l1.go = "RBlueBirdWon_3";
		break;
		case "RBlueBirdWon_3":
			dialog.text = "�� ����� ����!..";
			link.l1 = "�����. �������������, � ���������, � ���� ���, �� �� ������ � ����, ��� ������� ��� ���� �� ������.";
			link.l1.go = "RBlueBirdWon_4";
		break;
		case "RBlueBirdWon_4":
			dialog.text = "��, ��� ��� ����� ���������... �� ��� ��, ������� ��� �� ������ � �� ����������.";
			link.l1 = "�� �� �� ���, ��� ���� ��������. ��������.";
			link.l1.go = "exit";
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.questTemp.BlueBird = "over";
		break;

		case "RBlueBirdWon_10":
			dialog.text = "�������� � ���, ��� ���� ��������� ������� ������ � ��� � �����. � ��, ������, ���� �����! � ��� ��� �������� ������� ��������� ����� ��� ��, ��� ��� ����� ���������� ������?";
			link.l1 = "��, ������, �������, ����������... ������, � ��������"+ GetSexPhrase("","�") +" ������!";
			link.l1.go = "RBlueBirdWon_11";
		break;
		case "RBlueBirdWon_11":
			dialog.text = "���, �� �� �� ���������. �� �������������� � ���������� '������ ��������', � �� �� ��������.";
			link.l1 = "��, ��� ������ ���! �� ��� ��, � ��� �����"+ GetSexPhrase("","�") +"... ����� ����������, ����������� ��� ��������� ������ ����� ��������.";
			link.l1.go = "RBlueBirdWon_12";
		break;
		case "RBlueBirdWon_12":
			dialog.text = "������� �������������! ��������, � ������ ������� ���� ����� '��' � '��'.";
			link.l1 = "�����������. �� � �� ��������...";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "9");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Xebeca_BlueBird", "sSex1", GetSexPhrase("������ ������","������ ����"));
			pchar.questTemp.BlueBird = "returnMoney";
			pchar.questTemp.BlueBird = "SantLous_toTavern";
		break;

		case "RBlueBirdDieHard":
			dialog.text = "����� � ����� ����. �� ��� ��, �� �� ����"+ GetSexPhrase("��","��") +", ��� ������� �� ��� ����, � � ���� ������ �� �������. �����, �������� ��� � ����� ���������...";
			link.l1 = "�������, ��� ������ � ����� �� ��������...";
			link.l1.go = "RBlueBirdDieHard_1";
		break;
		case "RBlueBirdDieHard_1":
			dialog.text = "��� �� �����. ��� ����� ��� � �����, � ������ ��������, ��� ������ ������ ��� ����� ��������. �� ���, �� ����� �����, � ����� � �����\n���, ���-�� ���� �� ������ ��������.";
			link.l1 = "������... �� ��� ��, ��������.";
			link.l1.go = "exit";
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.questTemp.BlueBird = "over";
		break;

		case "RBlueBird_retMoney_1":
			dialog.text = "�� ��, ������"+ GetSexPhrase("��","��") +"!";
			link.l1 = "� �� ��� �� ������"+ GetSexPhrase("","�") +", ���� �� �� �� ������ ����������!";
			link.l1.go = "RBlueBird_retMoney_2";
		break;
		case "RBlueBird_retMoney_2":
			dialog.text = "�-�-���, ����! ������, ������ �"+ GetSexPhrase("��","�") +"!! ������ ���� �� ����, ������"+ GetSexPhrase("��","��") +"...";
			link.l1 = "��, � ������ ����� ���. ����� �� ������ ��� ������, �������. ����� ���� ������ ��� ������...";
			link.l1.go = "RBlueBird_retMoney_3";
		break;

		case "RBlueBird_retMoney_3":
			dialog.text = "���� �� �������"+ GetSexPhrase("","�") +", ������"+ GetSexPhrase("��","��") +"! ��� � �����, ��� �������� � �����!";
			link.l1 = "���� ���, �� ���� ��������, ����� ���� ��������� ��������.";
			link.l1.go = "RBlueBird_retMoney_4";
		break;
		case "RBlueBird_retMoney_4":
			dialog.text = "������ ��������, ������ � ����? � ��� �������������� �������������! ��� �� ��� ��������, �� ������� ����!";
			link.l1 = "��� ���, �� ���� ��� �������, ��� ������� ���������� �� ��������� �������. � ����� �� ������� ����� �������������? � �����, � �����"+ GetSexPhrase("","�") +" �������� � ���� ������ �� ��������� �����...";
			link.l1.go = "RBlueBird_retMoney_5";
		break;
		case "RBlueBird_retMoney_5":
			dialog.text = "�� ������, ���� ��� ����� �� ��� ���. ��� �� �������� ������� ������, � �� �� - ��� ���� �������!";
			link.l1 = "���! ��, ��������, ������� ������� ������ ������� � ���������. ���� � ���� ������. ���-�� ������� �� ��������, � ����� ������ ����� ��������.";
			link.l1.go = "RBlueBird_retMoney_6";
		break;
		case "RBlueBird_retMoney_6":
			dialog.text = "��� ��� ����� �������? � ��� � ���� ���� ������ ��������������.";
			link.l1 = "��, ��� � ������� ���������. ����� � ���, ��� �� ���������� �� ����������� ������ ���� �� �����, � ������� ���. � � �����, ��� ������� ����������� � ������� ������� ����� �������.";
			link.l1.go = "RBlueBird_retMoney_7";
		break;
		case "RBlueBird_retMoney_7":
			dialog.text = "����� �������?";
			link.l1 = "������� ����� ���������������. ��� ������ '������ ��������' - � �����"+ GetSexPhrase("","�") +" ��� ��������. ���� �� �� ������ ��� ��� ������, �� � ��� � ������� �� �� ������"+ GetSexPhrase("","�") +". ��� ��� ��� ���� �������� �� ����� ��������, ��� �������...";
			link.l1.go = "RBlueBird_retMoney_8";
		break;
		case "RBlueBird_retMoney_8":
			dialog.text = "�� �����, ��������� ���� 50 ����� � ���������� ������!";
			link.l1 = "�� ��� ������, ��� ���. ��� ���� � ���, ��� � �����"+ GetSexPhrase("","��") +" �������������� ���������� ��������, ������� ��������� ���. �� ������ ��� � ��������� ������. ������� ����� �������.";
			link.l1.go = "RBlueBird_retMoney_9";
		break;
		case "RBlueBird_retMoney_9":
			dialog.text = "� ��� ��� �� ����� �����? �������� ��.";
			link.l1 = "��������� �� � ������ ����. 200 �����, � � ������� ��� � �����. ����� - ������. � ����� ����. ������� ���� �����, � ����� ���...";
			link.l1.go = "RBlueBird_retMoney_10";
		break;
		case "RBlueBird_retMoney_10":
			dialog.text = "�� �� - ������"+ GetSexPhrase("","���") +"!!";
			link.l1 = "� �����, ����� ��"+ GetSexPhrase("�� ������","�� ���������") +"...";
			link.l1.go = "RBlueBird_retMoney_11";
		break;
		case "RBlueBird_retMoney_11":
			dialog.text = "������. ��� ���� ������ - ������������ ��������. ����� ���� ������ ������� �����. � ������ ��������! � ������ ��� � �����!";
			link.l1 = "�������������. ������, ����� �� ������������ �� ����, '������ ��������' ��� ����� �� ��������. ��������, ����� � ����� ������������...";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.BlueBird");
			pchar.questTemp.BlueBird = "over"; //��������� �����
			TakeNItems(pchar, "chest", 14);
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Xebeca_BlueBird", "14");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Xebeca_BlueBird", "sSex1", GetSexPhrase("��","���"));
			CloseQuestHeader("Xebeca_BlueBird");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
		break;


	}
	UnloadSegment(NPChar.FileDialog2);
}

