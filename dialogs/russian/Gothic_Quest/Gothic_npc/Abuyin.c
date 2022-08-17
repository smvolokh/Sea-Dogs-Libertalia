// ������ �������������
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
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_HALLO_13_00.wav");
			dialog.text = "����������� ���� ��� ����, ������� �� ��� �������� ������ � ��������� ����� �� ���� ������!";
			link.l1 = "�� ���, ����� ��� �� ������?";
			link.l1.go = "no_guess_exit";
			link.l2 = "�����������, ������! ����� ���������!";
			link.l2.go = "trade";

	if (CheckAttribute(npchar, "quest.AbuyinInfo_25"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_25"))
		{
		link.l2 = "����� ��� �� ������� ��� �����������?";
		link.l2.go = "WEISSAGUNG_1";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 25)
		{
		link.l2 = "������ � ���� 25 ��������. ����� ������������.";
		link.l2.go = "guess_05";
		}
                     }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_100"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_100"))
		{
		link.l2 = "����� ��� �� ������� ��� �����������?";
		link.l2.go = "WEISSAGUNG_2";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 100)
		{
		link.l2 = "� ������ ���� 100 ��������. ����� ������������.";
		link.l2.go = "guess_22";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_250"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_250"))
		{
		link.l2 = "����� ��� �� ������� ��� �����������?";
		link.l2.go = "WEISSAGUNG_3";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 250)
		{
		link.l2 = "� ������ ���� 250 ��������. ����� ������������.";
		link.l2.go = "guess_32";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_500"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_500"))
		{
		link.l2 = "����� ��� �� ������� ��� �����������?";
		link.l2.go = "WEISSAGUNG_4";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l2 = "� ������ ���� 500 ��������. ����� ������������.";
		link.l2.go = "guess_42";
		}
	
          }
}
	if (CheckAttribute(npchar, "quest.AbuyinInfo_1000"))
	{
		if (!CheckAttribute(npchar, "quest.AbuyinInfo_1000"))
		{
		link.l2 = "����� ��� �� ������� ��� �����������?";
		link.l2.go = "WEISSAGUNG_4";
		}
		else
		{
		if (GetCharacterItem(pchar, "gold_dublon") >= 1000)
		{
		link.l2 = "� ������ ���� 1000 ��������. ����� ������������.";
		link.l2.go = "guess_42";
		}
	
          }
}
		link.l15 = "�������, ������. �� ��������.";
		link.l15.go = "exit";

		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
			dialog.text = LinkRandPhrase(GetFullName(pchar) + ", ��� ���� ������! �, ��� ����������� ��������. ����� ���������"+ GetSexPhrase("","�") +" �� ���� ���?",
                                         RandSwear() + " ���� � ����?! ��� ����������� �������� " + GetFullName(pchar) + ". ������ �������� �� �������?",
                                         "���-���, "+ GetFullName(pchar)+ " � ���� � ������. �� ���, ����� �������, "+ GetSexPhrase("����","�������") +"?");
			link.l1 = RandPhraseSimple("������ ��������"+ GetSexPhrase("","�") +" ��������� ����.", "����� ��� �� ������� ��� �����������?");
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";

	break;


/// ********************** ������ �������������  ***********************************
//------------------------------ ������ �������------------------------------------------------

	case "Abuyin":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_HALLO_13_00.wav");
            	dialog.text = "����������� ���� ��� ����, ������� �� ��� �������� ������ � ��������� ����� �� ���� ������! � ��� ���� �����, � " + GetSexPhrase("���","����") + " ����������� ��������?";
        	link.l1 = "";
        	link.l1.go = "Abuyin_1";
	break;

	 case "Abuyin_1":
	 PlaySound("VOICE\Russian\GOTHIC\GG\GG_1.wav");
            	 dialog.text = "";
        	 link.l1 = "�, �������� ����������� � ���!";
        	 link.l1.go = "Abuyin_2";
	  break;

	 case "Abuyin_2":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_DU_15_00.wav");
            	 dialog.text = "";
        	 link.l1 = "��� ��!";
        	 link.l1.go = "Abuyin_3";
	  break;

	case "Abuyin_3":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_DU_13_01.wav");
            	dialog.text = "���� ����� ������.......";
        	link.l1 = "";
        	link.l1.go = "Abuyin_4";
	break;

	case "Abuyin_4":
	PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00.wav");
            	dialog.text = "";
        	link.l1 = "�� ������ ������� �����������?";
        	link.l1.go = "Abuyin_5";
	break;

	case "Abuyin_5":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_01.wav");
            	dialog.text = "�, ��� ����������� ��������, ������ � �� � ����� ���������� ������ �������?";
        	link.l1 = "";
        	link.l1.go = "Abuyin_6";
	break;

	case "Abuyin_6":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_15_03.wav");
            	dialog.text = "";
        	link.l1 = "� ����� ��� �����?";
        	link.l1.go = "Abuyin_7";
	break;

	case "Abuyin_7":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_02.wav");
            	dialog.text = "������ ����� ����� ������ ��� ��������� ����, � ����� ������ ���� ��� ���.";
        	link.l1 = "";
        	link.l1.go = "Abuyin_8";
	break;

	case "Abuyin_8":
	PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_04.wav");
            	dialog.text = "����� ������� ������ ��������� � �� ���������� ���� ����.";
        	link.l1 = "";
        	link.l1.go = "exit";
                   DoQuestFunctionDelay("SMALLTALK_L", 2.5);
	break;

//-------------------------------------------------������������-------------------------------------------------

//-------------------------------------------------1 �����������-------------------------------------------------

		case "WEISSAGUNG_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "guess_00";
		break;

		case "guess_00":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_13_01.wav");
			dialog.text = "��, ����� ���� � ����� � � ���� ������� ����������� ���� � ���� �������� ��������� �����.";
			link.l1 = "�������, � ���������" + GetSexPhrase("","�") + ". ������� ���-��...";
			link.l1.go = "exit";
			link.l2 = "������� ����� �� �������?";
			link.l2.go = "guess_01";
		break;

		case "guess_01":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_02.wav");
			dialog.text = "";
			link.l1 = "�������?";
			link.l1.go = "guess_02";
		break;

		case "guess_02":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_01.wav");
			dialog.text = "� � ����� ������� �� �������� �������������� � ���� ��������!";
			link.l1 = "";
			link.l1.go = "guess_03";
		break;


		case "guess_03":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_03.wav");
			dialog.text = "�� ����� �� 25 ����� � ������ ��������� � �������!";
			if (GetCharacterItem(pchar, "gold_dublon") >= 25)
			{
				link.l1 = "������, ��� ���� 25 ��������... ����� ������������.";
				link.l1.go = "guess_04";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold";
			}
		break;

		case "exit_gold":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_25;
		break;

		case "guess_04":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "��� ��� ������...";
		link.l1.go = "guess_05";
		break;

		case "guess_05":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 25);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_06";
		break;

		case "guess_06":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_WEISSAGUNG_13_04.wav");
			dialog.text = "�� ����� ������� ������ �� �����������, �� ��� � ���� ����� ��� ������� ���� ��������� ��������� �������!";
			link.l1 = "";
			link.l1.go = "guess_07";
		break;

		case "guess_07":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "������� ��� � �������.";
			link.l1.go = "guess_08";
		break;

		case "guess_08":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_13_01.wav");
			dialog.text = "������ � �������� ������ � ������ ����� � ��������� ������, �� �����?";
			link.l1 = "";
			link.l1.go = "guess_09";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_09":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "����� � ����?";
			link.l1.go = "TRANCE_1";
		break;


	
/// ********************** 1 ����������� ***********************************

		case "TRANCE_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_00.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_1";
			
		break;

		case "TRANCE_1_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_01.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_2";
		break;

		case "TRANCE_1_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_02.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_1_3";
		break;

		case "TRANCE_1_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_TRANCE_13_03.wav");
			dialog.text = "��� ��, ��� � ��� �������!";
			link.l1 = "";
			link.l1.go = "guess_exit_1";
		break;


/// ********************** 2 ����������� ***********************************


		case "WEISSAGUNG_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "guess_20";
		break;

		case "guess_20":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_13_02.wav");
			dialog.text = "�, ���� �����, � ����� � ���� 100 ������� � ����� �� ������ � �������� �������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "������, ��� ���� 100 ��������... ����� ������������.";
				link.l1.go = "guess_21";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_100";
			}
		break;

		case "exit_gold_100":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_100;
		break;

		case "guess_21":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "��� ��� ������...";
		link.l1 = "";
		link.l1.go = "guess_22";
		break;

		case "guess_22":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 100);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_23";
		break;

		case "guess_23":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "������� ��� � �������.";
			link.l1.go = "guess_24";
		break;

		case "guess_24":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_13_01.wav");
			dialog.text = "������, � ��� �������� � ������ ����� � ��������� ������, �� �����?";
			link.l1 = "";
			link.l1.go = "guess_25";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_25":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "����� � ����?";
			link.l1.go = "TRANCE_2";
		break;

/// ********************** 2 ����������� ***********************************

		case "TRANCE_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_00.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_1";
			
		break;

		case "TRANCE_2_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_01.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_2";
		break;

		case "TRANCE_2_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_02.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_2_3";
		break;

		case "TRANCE_2_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT2_TRANCE_13_03.wav");
			dialog.text = "��� ��, ��� � ��� �������!";
			link.l1 = "";
			link.l1.go = "guess_exit_2";
		break;


/// ********************** 3 ����������� ***********************************


		case "WEISSAGUNG_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "guess_30";
		break;

		case "guess_30":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_13_02.wav");
			dialog.text = "�, ���� �����, � ����� � ���� 250 ������� � ����� �� ������ � �������� �������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "������, ��� ���� 250 ��������... ����� ������������.";
				link.l1.go = "guess_31";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_250";
			}
		break;

		case "exit_gold_250":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_250;
		break;

		case "guess_31":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "��� ��� ������...";
		link.l1 = "";
		link.l1.go = "guess_32";
		break;

		case "guess_32":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 250);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_33";
		break;

		case "guess_33":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "������� ��� � �������.";
			link.l1.go = "guess_34";
		break;

		case "guess_34":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_13_01.wav");
			dialog.text = "������, � ��� ������ � ������ ����� � ��������� ������, �� �����?";
			link.l1 = "";
			link.l1.go = "guess_35";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_35":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "����� � ����?";
			link.l1.go = "TRANCE_3";
		break;

/// ********************** 3 ����������� ***********************************

		case "TRANCE_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_00.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_1";
			
		break;

		case "TRANCE_3_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_01.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_2";
		break;

		case "TRANCE_3_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_02.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_3_3";
		break;

		case "TRANCE_3_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT3_TRANCE_13_03.wav");
			dialog.text = "��� ��, ��� � ��� �������!";
			link.l1 = "";
			link.l1.go = "guess_exit_3";
		break;


/// ********************** 4 ����������� ***********************************


		case "WEISSAGUNG_4":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "guess_40";
		break;

		case "guess_40":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_13_02.wav");
			dialog.text = "�, ���� �����, � ����� � ���� 500 ������� � ����� �� ������ � �������� �������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "������, ��� ���� 500 ��������... ����� ������������.";
				link.l1.go = "guess_41";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_500";
			}
		break;

		case "exit_gold_500":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_500;
		break;

		case "guess_41":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "��� ��� ������...";
		link.l1 = "";
		link.l1.go = "guess_42";
		break;

		case "guess_42":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 500);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_43";
		break;

		case "guess_43":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "������� ��� � �������.";
			link.l1.go = "guess_44";
		break;

		case "guess_44":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_13_01.wav");
			dialog.text = "������, � ��� ������ � ������ ����� � ��������� ������, �� �����?";
			link.l1 = "";
			link.l1.go = "guess_45";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_45":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "����� � ����?";
			link.l1.go = "TRANCE_4";
		break;

/// ********************** 4 ����������� ***********************************

		case "TRANCE_4":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_00.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_1";
			
		break;

		case "TRANCE_4_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_01.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_2";
		break;

		case "TRANCE_4_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_02.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_4_3";
		break;

		case "TRANCE_4_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT4_TRANCE_13_03.wav");
			dialog.text = "��� ��, ��� � ��� �������!";
			link.l1 = "";
			link.l1.go = "guess_exit_4";
		break;


/// ********************** 5 ����������� ***********************************


		case "WEISSAGUNG_5":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "guess_50";
		break;

		case "guess_50":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_13_02.wav");
			dialog.text = "�, ���� �����, � ����� � ���� 1000 ������� � ����� �� ������ � �������� �������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 1000)
			{
				link.l1 = "������, ��� ���� 1000 ��������... ����� ������������.";
				link.l1.go = "guess_51";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold_1000";
			}
		break;

		case "exit_gold_1000":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.AbuyinInfo_1000;
		break;

		case "guess_51":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "��� ��� ������...";
		link.l1 = "";
		link.l1.go = "guess_52";
		break;

		case "guess_52":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 1000);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "guess_53";
		break;

		case "guess_53":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT_15_00.wav");
			dialog.text = "";
			link.l1 = "������� ��� � �������.";
			link.l1.go = "guess_54";
		break;

		case "guess_54":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_13_01.wav");
			dialog.text = "������, � ��� ������ � ������ ����� � ��������� ������, �� �����?";
			link.l1 = "";
			link.l1.go = "guess_55";
	                                      DoQuestFunctionDelay("Abuyin_house_1", 1.0);
		break;

		case "guess_55":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_36.wav");
			dialog.text = "";
			link.l1 = "����� � ����?";
			link.l1.go = "TRANCE_5";
		break;

/// ********************** 5 ����������� ***********************************

		case "TRANCE_5":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_00.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_1";
			
		break;

		case "TRANCE_5_1":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_01.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_2";
		break;

		case "TRANCE_5_2":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_02.wav");
			dialog.text = "������������� ......";
			link.l1 = "";
			link.l1.go = "TRANCE_5_3";
		break;

		case "TRANCE_5_3":
	                                                PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_ZUKUNFT5_TRANCE_13_03.wav");
			dialog.text = "��� ��, ��� � ��� �������!";
			link.l1 = "";
			link.l1.go = "guess_exit_5";
		break;


/// *********************************************************
		case "guess_exit_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                         DeleteAttribute(npchar, "quest.AbuyinInfo_25");
 
// --> ---����� ���� ����������� ������ ���� ��� �������� -------------------------------

                                                         DoQuestFunctionDelay("GothicTorus_StartRoseauCharlotte", 10.0);

// --> ----------------------------------
		break;



		case "guess_exit_2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                       DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_100");

// --> ---����� ���� ����������� ������ �� �������� -------------------------------

	                   DoQuestCheckDelay("Ascold_begin", 0.3);	

// --> ----------------------------------

		break;

		case "guess_exit_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_250");
		break;

		case "guess_exit_4":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                      DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_500");
		break;

		case "guess_exit_5":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddCharacterHealth(pchar, -10);
	                                       DoQuestFunctionDelay("Abuyin_house_3", 1.0);
                                                          DeleteAttribute(npchar, "quest.AbuyinInfo_1000");
		break;

/// *********************************************************

		case "no_guess_exit":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\B_ABUYIN_WEISSAGUNG_15_00");
			dialog.text = "";
			link.l1 = "�� ������ ������� �����������?";
			link.l1.go = "no_guess_exit_1";
		break;
		case "no_guess_exit_1":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_01.wav");
			dialog.text = "�, ��� ����������� ��������, ������ � �� � ����� ���������� ������ �������?";
			link.l1 = "";
			link.l1.go = "no_guess_exit_2";
		break;
		case "no_guess_exit_2":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_15_03.wav");
			dialog.text = "";
			link.l1 = "� ����� ��� �����?";
			link.l1.go = "no_guess_exit_3";
		break;
		case "no_guess_exit_3":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_02.wav");
			dialog.text = "������ ����� ����� ������ ��� ��������� ����, � ����� ������ ���� ��� ���.";
			link.l1 = "";
			link.l1.go = "no_guess_exit_4";
		break;
		case "no_guess_exit_4":
	                   PlaySound("VOICE\Russian\gotica\Abuyin\DIA_ABUYIN_NOCHMAL_13_04.wav");
			dialog.text = "����� ������� ������ ��������� � �� ���������� ���� ����.";
			link.l1 = "";
			link.l1.go = "no_guess_exit_5";
		break;
		case "no_guess_exit_5":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

/// *********************************************************

		case "trade":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(20) + ".wav");	
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
			NextDiag.TempNode = "First time";
		break;

//----------------------------------------- ����������� ������� -----------------------------------------------

		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


	}
}
