string disease ="";
string disease1 ="";			

string MiscDisease(string s1,string s2,string s3);
{
	string s;
	
	switch(s3)
	{
		case "3":
			s = "�� � ��� ����� ";
			switch(s1)
			{
				case "Chesotka":
					s += "������� � ";
				break;
				case "Lihoradka":
					s += "��������� � ";
				break;
				case "YellowLihoradka":
					s += "������ ��������� � ";
				break;
				case "Dirty":
					s += "������� ������� � ";
				break;
				case "Chill":
					s += "�������� � ";
				break;
				case "Plague":
					s += "���� � ";
				break;
				case "Fester":
					s += "���� � ";
				break;
			}
			switch(s2)
			{
				case "Chesotka":
					s += "�������.";
				break;
				case "Lihoradka":
					s += "���������.";
				break;
				case "YellowLihoradka":
					s += "������ ���������.";
				break;
				case "Dirty":
					s += "������� �������.";
				break;
				case "Chill":
					s += "��������.";
				break;
				case "Plague":
					s += "����.";
				break;
				case "Fester":
					s += "����.";
				break;
			}
			s += " � ���� �����?";
			return s;
		break;
		case "1":
			switch(s1)
			{
				case "Chesotka":
					s = "� �������.";
				break;
				case "Lihoradka":
					s = "� ���������.";
				break;
				case "YellowLihoradka":
					s = "� ������ ���������.";
				break;
				case "Dirty":
					s = "� ������� �������.";
				break;
				case "Chill":
					s = "� ��������.";
				break;
				case "Plague":
					s = "� ����.";
				break;
				case "Fester":
					s = "� ����.";
				break;
			}
			return s;
		break;
		case "1go":
			switch(s1)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
		case "2":
			switch(s2)
			{
				case "Chesotka":
					s = "� �������.";
				break;
				case "Lihoradka":
					s = "� ���������.";
				break;
				case "YellowLihoradka":
					s = "� ������ ���������.";
				break;
				case "Dirty":
					s = "� ������� �������.";
				break;
				case "Chill":
					s = "� ��������.";
				break;
				case "Plague":
					s = "� ����.";
				break;
				case "Fester":
					s = "� ����.";
				break;
			}
			return s;
		break;
		case "2go":
			switch(s2)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
	}

	switch(s3)
	{
		case "4":
			switch(s1)
			{
				case "Chesotka":
					s = "�� ���-�� �������� ��� � �������.";
				break;
				case "Lihoradka":
					s = "�� ���-�� �������� ��� � ���������.";
				break;
				case "YellowLihoradka":
					s = "�� ���-�� �������� ��� � ����� ���������.";
				break;
				case "Dirty":
					s = "�� ���-�� �������� ��� � ������� �������.";
				break;
				case "Chill":
					s = "�� ���-�� �������� ��� � ��������.";
				break;
				case "Plague":
					s = "�� ���-�� �������� ��� � ����.";
				break;
				case "Fester":
					s = "�� ���-�� �������� ��� � ������� ����.";
				break;
			}
			return s;
		break;
		case "4go":
			switch(s1)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
	}
}

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

			if(!CheckAttribute(npchar, "dialog2.Year"))
			{
		dialog.text = NPCharSexPhrase(npchar, "������� ������� "+NPChar.name+" "+NPChar.lastname+", ��... ���-�� � �� ���������� ���.", "� ��� ���� ����� �������������?", "������� ������� "+NPChar.name+" "+NPChar.lastname+", ��... ���-�� � �� ���������� ���.", "� ��� ���� ����� �������������?");
				link.l1 = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". � �������.";
				link.l1.go = "Dialog_1";
			}else{
				if((GetDataYear() > npchar.dialog2.Year) || (GetDataMonth() > npchar.dialog2.Month) || (GetDataDay() > npchar.dialog2.Day))
				{

		dialog.text = NPCharSexPhrase(npchar, "����� ����! ��������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". ��������� ��� �� �����. ������ ��������?", "��, �������, � ��� � �����, ��� �� �������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". ��������� ��� �� �����" + GetSexPhrase("","�") + ". ������ ��������?");
			link.l1 = "�������� ��� ������� � ��������.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "������, ��� � ���� ���� � �������.";
			link.l2.go = "Dialog_trade";

					if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
					{
						link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
						link.l3.go = "Dialog_disease";
					}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
						link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
						link.l3.go = "Dialog_disease";
					}}

					link.l4 = "�� ������� "+NPChar.name+". ��� ���� ����.";
					link.l4.go = "Dialog_exit";

				}else{

		dialog.text = NPCharSexPhrase(npchar, "����� ����! ��������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". ��������� ��� �� �����. ������ ��������?", "��, �������, � ��� � �����, ��� �� �������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". ��������� ��� �� �����" + GetSexPhrase("","�") + ". ������ ��������?");
					link.l1 = "�������� ��� ������� � ��������.";
					link.l1.go = "Dialog_disease_info";
					link.l2 = "������, ��� � ���� ���� � �������.";
					link.l2.go = "Dialog_trade";
					link.l3 = "�� ������� "+NPChar.name+". ��� ���� ����.";
					link.l3.go = "Dialog_exit";

				}
			}

			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "� �� ��������� ������ ��������� �������� � �������, ������ �� ������ �� ����, �����, ��� �����, ����� ����� ����� - ������? ��� �� ���� � ��� ����, ��� ������?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "Killwork" && !CheckAttribute(npchar, "quest.Killwork"))
			{
				link.l1 = "�����������, �� ���������, ��� ���� ����� ���� ���� � ������ �����?";
				link.l1.go = "Killwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlottePRESENT" && !CheckAttribute(npchar, "quest.RoseauCharlottePRESENT"))
			{
				link.l1 = "� �� ������ �...";
				link.l1.go = "RoseauCharlottePRESENT";
			}

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "�� ���� ��� � �������, �� ���� �������� ������ ������.";
		link.l1 = "������������� ������� ������ � ����� ������ �� �����?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "����� �������� � ���� ����� ���.";
		link.l1 = "���� ��������, ��� �������� ��� �� ���� �, ��� ������ � ��� ����!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "��� ������ ��� �����, ����� �����.";
		link.l1 = "�������.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "Killwork":
        	                  dialog.text = "�� ��� ���.";
		link.l1 = "�� ��� ������ � ��� ���� �����, ��� �� ������� �� ������ � �����, �� ������ ���������� � ����� ������� �����������?";
    		link.l1.go = "Killwork_1";
		break;

                                      case "Killwork_1":
		dialog.text = "������ ����� � ������ ������� ����������� �� ���������� ��������.";
		link.l1 = "� ������ ��������������� �� ��������!";
		link.l1.go = "Killwork_2";
  		break;

                                      case "Killwork_2":
		dialog.text = "�� ���, �� ��� ������, ������� ��������, ���������� � ������� ������� �� ����������.";
		link.l1 = "� ���, � ���������? � �� ���������?";
		link.l1.go = "Killwork_3";
  		break;

                                      case "Killwork_3":
		dialog.text = "�� ����������, �� �����.";
		link.l1 = "� ��, ��� ������ ��� �� �����, ������� �� �������.";
		link.l1.go = "Killwork_4";
  		break;

                                      case "Killwork_4":
		dialog.text = "�� ����, � � ������ � �� �� ������, ��� �� � ����������� ������, ����������� � ��.";
		link.l1 = "��� ���������, ����� ���� �������� ���.";
		link.l1.go = "Killwork_5";
		AddDialogExitQuestFunction("Killwork_huber");
  		break;

                                      case "Killwork_5":
		DialogExit();
		pchar.quest.Killworkhour.win_condition.l1 = "locator";
		pchar.quest.Killworkhour.win_condition.l1.location = "Roseau_Town";
		pchar.quest.Killworkhour.win_condition.l1.locator_group = "reload";
		pchar.quest.Killworkhour.win_condition.l1.locator = "reload13";

		pchar.quest.Killworkhour.win_condition.l2 = "HardHour";
		pchar.quest.Killworkhour.win_condition.l2.start.hour = 0;
		pchar.quest.Killworkhour.win_condition.l2.finish.hour = 5;
		pchar.quest.Killworkhour.function = "Killwork_huber_hour";
		npchar.quest.Killwork = "true";
  		break;

                                      case "RoseauCharlottePRESENT":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_15_00.wav");
		dialog.text = "";
		link.l1 = "��� ����� �������....";
		link.l1.go = "PRESENT_1";
  		break;

                                      case "PRESENT_1":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_10_01.wav");
		dialog.text = "�����, �� �����?";
		link.l1 = "";
		link.l1.go = "PRESENT_2";
  		break;

                                      case "PRESENT_2":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_NEIN_15_00.wav");
		dialog.text = "";
		link.l1 = "� ����� - �� ���!!!";
		link.l1.go = "PRESENT_3";
  		break;

                                      case "PRESENT_3":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_NEIN_10_01.wav");
		dialog.text = "����� ����������, � �� ���� ������������� ����������� ����������� ������!";
		link.l1 = "";
		link.l1.go = "PRESENT_4";
  		break;

                                      case "PRESENT_4":
		dialog.text = "";
		link.l1 = "�� �� ��� �����, � �� ������ � ��� ����� �����...";
		link.l1.go = "PRESENT_5";
  		break;

                                      case "PRESENT_5":
		dialog.text = "��, �� � � ����� �� ����, � ���� ���� ���� ������, ����� ���� � �����...";
		link.l1 = "";
		link.l1.go = "PRESENT_6";
  		break;

                                      case "PRESENT_6":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\FELL.wav");
		dialog.text = "";
		link.l1 = "����� ��� ��, ��� � ���� ����.";
		link.l1.go = "PRESENT_7";
  		break;

                                       case "PRESENT_7":
		 TakeNItems(pchar, "mangarosafast", 2);
		 Log_Info("�� �������� �����");
		 TakeNItems(pchar, "mangarosatotal", 2);
		 Log_Info("�� �������� ����� ����");
		 TakeNItems(pchar, "mangarosapower", 2);
		 Log_Info("�� �������� ���� ������");
                                       PlaySound("Ambient\Tavern\naliv_003.wav");
		 DialogExit();
		 NextDiag.CurrentNode = NextDiag.TempNode;
		 npchar.quest.RoseauCharlottePRESENT = "true";
  		 break;

		
		case "Dialog_1":
			dialog.text = "���� ����� "+NPChar.name+" "+NPChar.lastname+". �� ��������� � ����. ��� ����������� - �������� �� ���������� �������� � ������� ����� � �������. ��� ����� � ���� ������� ��� ����������� �����������, ��������� � ��������� �������.";
			link.l1 = "�������� ��� ������� � ��������.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "������, ��� � ���� ���� � �������.";
			link.l2.go = "Dialog_trade";

			if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
			{
				link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
				link.l3.go = "Dialog_disease";
			}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
				link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
				link.l3.go = "Dialog_disease";
			}}
		
			link.l4 = "���� ������� �������������. �� ������� "+NPChar.name+".";
			link.l4.go = "Dialog_exit";
		break;


		case "Dialog_disease_info":
			dialog.text = "�� ��������� ���������� �������������� ����� ������� ��� �������, ����� � ������������ ���������, ��������, ���� � ����������� ������� ���������, ��������� ������� ��������, � ����� �� ����� �������� � ��� ����.";
			link.l1 = "�������� ��� �������.";
			link.l1.go = "Dialog_info_Chesotka";
			link.l2 = "������� ��� � ���������.";
			link.l2.go = "Dialog_info_Lihoradka";
			link.l3 = "�������� ��� ����� ���������.";
			link.l3.go = "Dialog_info_YellowLihoradka";
			link.l4 = "��� ����� ������� �������?";
			link.l4.go = "Dialog_info_Dirty";
			link.l5 = "�������� ��� ��� ��������.";
			link.l5.go = "Dialog_info_Chill";
			link.l6 = "� ���� ������ ������� ������ � ����.";
			link.l6.go = "Dialog_info_Plague";
			link.l7 = "� ��� ������ ���?";
			link.l7.go = "Dialog_info_Fester";
			link.l8 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l8.go = "Dialog_exit";
		break;


		case "Dialog_info_Chesotka":
			dialog.text = "������� - ����������� ���������������� �������, �������� ������������� ������� ���� �� ��������. ��� ������ ����������� � �������� ������� �� ����, ��� ����������� ����� � ����, �� ����� �������� �����. ��� ������� ���������� ����������� ���������, �� ���� �� �������� �� ���������...";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Chesotka_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Chesotka_1":
			dialog.text = "������������ ����������� ��������, �� ������ ������, �������� ���� �� ������ ����. Ÿ ���������� ������� � ���� ���� ��� �� ����, ��� �������, ��� ����� ��������� ���� ������� ���� �� �����, � ����� ������ ������� �������������� ���������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Lihoradka":
			dialog.text = "��������� - ����������� ��������������� �������, ���������� � � ���� ������ ����������� �������, ����� ��������. �������� ������� �� � ���, �� � ����� � ��� ����������� ����� ��� ������������ ������� ������ ����-���� ���� ����� ������ ���������.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Lihoradka_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Lihoradka_1":
			dialog.text = "�������� ����������� �������� �������, �������� ���� ������ ����� ����������� ���� ������� ������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_YellowLihoradka":
			dialog.text = "Ƹ���� ��������� - ����������� ������� �����������. �������� ��������� ���, ���� �� ���� ����, ������������ � �����. ����� �������� �� ����������� � ���������� ������, ����� ������� ������ ��������.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_YellowLihoradka_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_YellowLihoradka_1":
			dialog.text = "����������� ������� ������� ���� �� �������, �� ���� �� �������, ��������� � ������� ���� �������� ������� ���������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Dirty":
			dialog.text = "������� ������� - ��������� ��� ������������ �������� � ������� ������ ���������. ������ ����� ������� ��������� � ������ �������� ������� � �������. ����������� � ��������, ��� �������, ������ � ����������� ���� �� ���������� �����. ����� ������� �������� ���� �����, ������ ��� ����� �����������, �������� � ��������� � ����� ���� �� ������� ������� ����, �� ������������ �������.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Dirty_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Dirty_1":
			dialog.text = "������ �������� ����� ����� � ������� ������ �������� ���� ���� � ����. �������� ������ ������� ������������� ����������� �����, ������� �������� ����������� � ������������� ���� ����������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Chill":
			dialog.text = "�������� - ����������� �������������� �� ���� ��������� ����. ���������� � ����� ��������: �������� �� ��������� ��� �������� � ������ ������. � ��������� �������, ������� �������� �� ������� ������, ��� � ��������� �� ����.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Chill_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Chill_1":
			dialog.text = "��� �������, �� ������-������ ���� ����� �������� ���. ������ �������� �������� � ������� �����, ����������� �������� ������� �������������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Plague":
			dialog.text = "���� - ����������� ������� ����������� �������� � ��������. ������������ �������� ���� ���������� ������ ������ ����. ������ �������� �������� � 6 ���� � ��������� ������� ������� � �������� ������ ������. �� 50 ��� ������� ����� 100 ��������� �������. ������ �������� �������� � 14 ����. ��������� ������������������ ���� ��������� ����� � ������ ��������. ��������������� �������� ���������� �� ������� ��� ����� ���� �  ����� ���������� ����.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Plague_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Plague_1":
			dialog.text = "���� ��������������� ������ �������: �������, ������� �������� �����, ������������, ����������� ��������, �����, �������� ����������� �����. ��� �������, ����� ������ ������� ������. ����������� ��������� ������ �� ���. � ������ ��� ����� �������� ����� ������ ��������� ������ � �������. ������ ���� � ���� � ������ ������� ���� - �������� ������������ ������ � ��������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_exit";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Fester":
			dialog.text = "������ ������� �� ����������� �� �������. ���� ���� ������� �� ����������, ��� �������, ��� ��������� � ����������. ������� �������� �� ������� ���� � ��� �����, ������ ��������, ���� � ���������.";
			link.l1 = "�����������.";
			link.l1.go = "Dialog_info_Fester_1";
			link.l2 = "� ��� �� �����" + GetSexPhrase("","�") + ". ������� ��������� � ���-������ ������.";
			link.l2.go = "Dialog_other";
			link.l3 = "��� ���� ����. ��������, ��� �������� ���.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Fester_1":
			dialog.text = "������� ��� ����� ������� ���������� ���� ����������� �����, ������� ������� ���������. ���� ����������, �� �������� ���������, ������� ������������ �������.";
			link.l1 = "������� ��������� � ���-������ ������.";
			link.l1.go = "Dialog_other";
			link.l2 = "��� ���� ����. ������� �� ��������� �������.";
			link.l2.go = "Dialog_exit";
		break;


		case "Dialog_other":
			dialog.text = "��� �� �� ������ ������?";
			link.l1 = "�������� ��� ������� � ��������.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "������, ��� � ���� ���� � �������.";
			link.l2.go = "Dialog_trade";

			if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
			{
				link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
				link.l3.go = "Dialog_disease";
			}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
				link.l3 = "������, �� ������ ����������, ��� �� ����? � ���� ������� ��������.";
				link.l3.go = "Dialog_disease";
			}}
		
			link.l4 = "���� ������� �������������. �� ������� "+NPChar.name+".";
			link.l4.go = "Dialog_exit";
		break;


		case "Dialog_disease":
			dialog.text = LinkRandPhrase("���������. ����������� ������ � �������. ��� ���������� ������ ��� ��������� � ����������.", "����� ���������, ��� ������ ����������. ������� ��������. ��� ����� ��� ���������.", "�� ��� ������ ������������ �� ���� ����. �������, ��� ��� ����� ���� ���������� � ��������� ��� �������� ���. ������� ��������.");
			link.l1 = "��� �������.";
			link.l1.go = "Dialog_disease_1";
		break;
		case "Dialog_disease_1":
			LAI_Fade("","");
			AddTimeToCurrent(0, 15);

			if(CheckAttribute(pchar, "disease.One") && (pchar.disease.One != "-1"))
			{
				disease = pchar.disease.One;
			}

			if(CheckAttribute(pchar, "disease.Two") && (pchar.disease.Two != "-1"))
			{
				disease1 = pchar.disease.Two;
			}

			if((disease != "") && (disease1 != ""))
			{
				dialog.text = MiscDisease(disease,disease1,"3");
				link.l1 = MiscDisease(disease,disease1,"1");
				link.l1.go = MiscDisease(disease,disease1,"1go");
				link.l2 = MiscDisease(disease,disease1,"2");
				link.l2.go = MiscDisease(disease,disease1,"2go");		
			}else{

			if(disease == ""){disease = disease1;}
			switch (disease)
			{
				case "Chesotka":
					dialog.text = LinkRandPhrase("��������, � ��� �������.", "�� ����. �� ������ ��������.", "�� �������. ���� �� ���������, �� ������ ��������.");
					link.l1 = "��� �� ������?";
					link.l1.go = "Disease_Chesotka";
				break;
				case "Lihoradka":
					dialog.text = "�������, ��� ������?";
					link.l1 = "�� � ����� �������������� ������������.";
					link.l1.go = "Disease_Lihoradka";
				break;
				case "YellowLihoradka":
					dialog.text = "�������, ��� ������?";
					link.l1 = "��, ����� ����� ��� ����� �������������� � ������.";
					link.l1.go = "Disease_YellowLihoradka";
				break;
				case "Dirty":
					dialog.text = "�� ������ ��� ����� ����������, ��� �� �������. �������� ���, �� ������ �������������. � ������ ��� �������� ������� ��������.";
					link.l1 = "�������?";
					link.l1.go = "Disease_Dirty";
				break;
				case "Chill":
					dialog.text = LinkRandPhrase("���� ��� �������� - ���� ������.", "����� �������. ������ ��������.", "������ ����� � ������� ���� � ���� �����. ��� ������� ����������.");
					link.l1 = "� ��� � ����?";
					link.l1.go = "Disease_Chill";
				break;
				case "Plague":
					dialog.text = LinkRandPhrase("��� ���! � ���� ������ �������.", "���. � ��������, ��� �� ���������� �� ��...", "� ���� ��� ��� ������ �������.");
					link.l1 = "� ��� ����?";
					link.l1.go = "Disease_Plague";
				break;
				case "Fester":
					dialog.text = LinkRandPhrase("�������, �� ����� ����� �������! � ��� ������� ������� � ���� � � ���. ������, � ��������� ����� �� ���� �����������.", "� ���� ������� ����... ������� ����� ����������� ������ � ���.", "�� ����. ���� ������ ��� � ������.");
					link.l1 = "� ���������� �����?";
					link.l1.go = "Disease_Fester";
				break;
			}}
		break;


		case "Disease_Chesotka":
			dialog.text = "���. ����� ���. ������� ���������� ��������������� ������� � �� �� ����� ���� �� ������.";
			link.l1 = "�� ������ �������.";
			link.l1.go = "Disease_Chesotka_1";
		break;
		case "Disease_Chesotka_1":
			dialog.text = "� ��, "+GetAddress_Form(NPChar)+" �����, ����������? ��������. � ������� ��� ������� ������ ����. ������ � ������� � ���� � ����� ����������, �� ����� �������, �� ����� ���� ����, �� �������� � ���� ������. � ��� ������.";
			link.l1 = "������� �� ������. �������, � ����� � � ���.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Chesotka"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "������� ���, "+NPChar.name+" "+NPChar.lastname+", �� ������, �� ��� ������ �� �� �������.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_Lihoradka":
			dialog.text = "����� ����?";
			link.l1 = "���.";
			link.l1.go = "Disease_Lihoradka_1";
		break;
		case "Disease_Lihoradka_1":
			dialog.text = "��... � �����, ��� �� ������ ����������. �� ������� ����, ��� �������� ��������� ������ �� ���.";
			link.l1 = "��� �� ��� ������ ������������, ������?";
			link.l1.go = "Disease_Lihoradka_2";
		break;
		case "Disease_Lihoradka_2":
			dialog.text = "��� ������� ������ ���� ������� ������. �� �� �������� ������� � ���������� �� ������, ������� ������� ����������� ����. ������� ������� ��� ����� ���� ����.";
			link.l1 = "������� �� ������. �������, � ����� � � ���.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Lihoradka"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "������� ���, "+NPChar.name+" "+NPChar.lastname+", �� ������, �� ��� ������ �� �� �������.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_YellowLihoradka":
			dialog.text = "���� �����, �����" + GetSexPhrase("���","����") + ". �����, ��� �� �������� ����� ����������.";
			link.l1 = "��� ��� ��������?";
			link.l1.go = "Disease_YellowLihoradka_1";
		break;
		case "Disease_YellowLihoradka_1":
			dialog.text = "����� ���. ���� �� ������� ������� ����, �� ��� ��� ��� �� ����� ����������� ������ ��������.";
			link.l1 = "� �����" + GetSexPhrase("","�") + " �� �� ������... � ����" + GetSexPhrase("��","��") + " ������, ���� ���� ������!";
			link.l1.go = "Disease_YellowLihoradka_2";
		break;
		case "Disease_YellowLihoradka_2":
			dialog.text = "�����������. ��� ����� ������� ��������������. ������� ���������� ����� � ������� - ���, ��� ����� ������ ���. ��������� � ������� ������, ����������� ������ ����� ������ ���, �� ���� ��������� ��������� ������...";
			link.l1 = "�������?";
			link.l1.go = "Disease_YellowLihoradka_3";
		break;










		case "Disease_YellowLihoradka_3_1":
			dialog.text = "�� �������� ����� �� �������?";
			link.l1 = "��� ������.";
			link.l1.go = "Disease_YellowLihoradka_4"; 
		break;










		case "Disease_YellowLihoradka_4_0":
		dialog.text = NPCharSexPhrase(npchar, "��� � ����������� ���� ��������������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?", "��� � ����������� ���� ��������������, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?");
			link.l1 = "������� �����. ������� �� �������. ���� �� �� ��, �� �������� �� ����������� ��� ���� ���� ���������.";
			link.l1.go = "Disease_YellowLihoradka_4_1";			
		break;
		case "Disease_YellowLihoradka_4_1":
			dialog.text = "�� �����. ��� ���� ��� ������. ����� ��� ��������, ����� �� �������.";
			link.l1 = "������� �� ���. ��������.";
			link.l1.go = "Disease_YellowLihoradka_exit";
		break;

		case "Disease_YellowLihoradka_exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();

			npchar.dialog2.Year = GetAddingDataYear(0, 0, 2);
			npchar.dialog2.Month = GetAddingDataMonth(0, 0, 2);
			npchar.dialog2.Day = GetAddingDataDay(0, 0, 2);

			Lai_Fade("ExitFromChurch1","");
		break;

		case "Disease_YellowLihoradka_5":
			dialog.text = "� ��� ��� ������ �����.";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "YellowLihoradka"){disease = disease1;}
				link.l1 = MiscDisease(disease,disease1,"4");
				link.l1.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l2 = "�� ������������. � ����� ������.";
			link.l2.go = "Dialog_exit";
		break;

		case "Disease_Dirty":
			dialog.text = "������. ������� ������� �� ���� ������� ��������� � ������. ����� ������ �������.";
			link.l1 = "��� �� ��� ������?";
			link.l1.go = "Disease_Dirty_1";
		break;
		case "Disease_Dirty_1":
			dialog.text = "� ���� ������� ������ ����, ������� ����� �������� �������� ���� �������.";
			link.l1 = "��������, �� �� ��������?";
			link.l1.go = "Disease_Dirty_2";
		break;
		case "Disease_Dirty_2":
			dialog.text = "������ ��� � ����, ��� ���� ��������� ���� �����. ���� - ������� �����. �������� ���� � ��������� � ������� ���� - ���, ��� ������������� ����� ������ ���. �������� ����� ���������.";
			link.l1 = "������� �� ������. � ���� ������ � ��� ��� ����.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Dirty"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "������� "+NPChar.name+" "+NPChar.lastname+". � ������� ��� ����. ��������.";
			link.l3.go = "Dialog_exit";
		break;


		case "Disease_Chill":
			dialog.text = "��� ������� ��������. ���� ������ �������� ���������� � ������ ������������� � ����� ������, �� ��� ������ ����. �� ����� �������, �� ����� �������� ��� ������ �����.";
			link.l1 = "����� ������... � ���� �� ����� ����� ������� ������ �����������?";
			link.l1.go = "Disease_Chill_1";
		break;
		case "Disease_Chill_1":
			dialog.text = "����������. ��� ������� ��� �������� ��������. � � ������� ��� ����� ��� �� ��� ������ �������.";
			link.l1 = "����� ������. � ���������� ����� � � ���.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Chill"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "��������� �� ������������. �� ������� ����, �� ��� ���� ����. ��������.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_Plague":
			dialog.text = "��... �� �������� ����� - ����� �������� ��������, ������� ��� �����-���� ���������� ������.";
			link.l1 = "����... � �� �� ����? �������, ������, ���� �� ����?";
			link.l1.go = "Disease_Plague_1";
		break;
		case "Disease_Plague_1":
			dialog.text = "�� ����. � ����� ���������� ���-���� ��������������, �� ���� � ��� ����.";
			link.l1 = "�����? ��� ��� ������� �����������?";
			link.l1.go = "Disease_Plague_2";
		break;
		case "Disease_Plague_2":
			dialog.text = "� ���� ������������ � ������� ������ �������. ��������� ��� ����������� ������ �� ���� �������� �� ������ �������������...";
			link.l1 = "�� ������ ����.";
			link.l1.go = "Disease_Plague_3";
		break;
		case "Disease_Plague_3":
			dialog.text = "������, ������. � ���� ���� ������� ��� ��������� ������ ��������. �� ����� �������� ����������� ���� �� ��������, �� ������� ��������� � �� ����������. ������� ������� ������ �� �������. �������� ���� � �������� ����� �����, ��������, �������� ��� ���������, �� � ��� ��� �� ����������.";
			link.l1 = "� ���� ������ ��� ��������.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Plague"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "� �����" + GetSexPhrase("","�") + ", ��������� ���. ��������.";
			link.l3.go = "Dialog_exit";
		break;



		case "Disease_Fester":
			dialog.text = "� ��������� -  � ��� ���������. ����� �� �� ������, ��� ����� ������ ����� ������ ������������? ��� ����� ������ ���� �� ����� ����������... ��� ���������� � ����� ��� ���� ���������.";
			link.l1 = "�� �� �������� ���, ������?";
			link.l1.go = "Disease_Fester_1";
		break;
		case "Disease_Fester_1":
			dialog.text = "������� - ��� ��� ������. ��� ��������� ������ ������� ������ ����, ����������� ��� ��������� ���. �������� ����� �������� ����� � ������� ��� �����. ���� �� ������ ������� �� �����, �� ��� ����� ��� ������� ����� ��������.";
			link.l1 = "� ���� ������ ��� ����.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Fester"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "� �����" + GetSexPhrase("","�") + ", ��������� ���. ��������.";
			link.l3.go = "Dialog_exit";
		break;











		case "Dialog_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Dialog_trade":									
            if (CheckNPCQuestDate(npchar, "Item_date"))
			{
				SetNPCQuestDate(npchar, "Item_date");
				GiveItemToTrader(npchar);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(npchar, 0);
		break;




		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
