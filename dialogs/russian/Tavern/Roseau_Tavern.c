// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��� �� ������� ��� ������� ���� � �� ��...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, �����" + GetSexPhrase("","�") + " ���-��...",
                      "�� ��, ������������� � ������ ���...", "�� ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// ==> ��������� ���� ��������� �������.
            if (pchar.questTemp.GothicLee == "SeekBible_toBermudes") 
			{				
                link.l1 = HeroStringReactionRepeat("��������, � ��� ������, ������� �������� ����� ������ �����-�� ��������. �� ������ �� ���� ����?",
                "� ��� ������ "+ GetSexPhrase("�����","������") +" ��������... ��� ��������, ������.", "�� ��, �����...", "�-�-�, ����������� ���, ������...", npchar, Dialog.CurrentNode);
                link.l1.go = DialogGoNodeRepeat("Gothic_3_1", "", "", "", npchar, Dialog.CurrentNode);
                                                             }

			if (pchar.questTemp.piratesLine == "KillLoy_toBermudes")
			{
				link.l1 = "�����, ��������, �� ��������� ������ ���?";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain" || pchar.questTemp.piratesLine == "KillLoy_2toTavernAgain")
			{
				link.l1 = "� ��� ������� ���.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine == "PL5Hunter_toBermudes")
			{
				link.l1 = "� ���� � �������, ���� ������ �� �������?";
				link.l1.go = "StepPL5Berm_1";
			}

			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "� �� ��������� ������ ��������� �������� � �������, ������ �� ������ �� ����, �����, ��� �����, ����� ����� ����� - ������?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

			if(CheckAttribute(pchar, "questTemp.GothicAscold.Fisk") && pchar.questTemp.GothicAscold.Fisk == "ThreeObject" && !CheckAttribute(npchar, "quest.ThreeObject"))
			{
				link.l1 = "������ ��� ����� ���������� �� ��������� ����������. ��������� � ���� ��� ��� �� ����� �� ��������� � ���������, �������� ��� - ������ � ������� � ����?";
				link.l1.go = "GothicKardif_ThreeObject";
			}

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Dominica" && !CheckAttribute(npchar, "quest.RevengeCorsair_Dominica"))
			{
				link.l1 = "������, � ������, ��� ��� ������ ����� ������������ ��� ������ ������, �� ���������� ��� �� �����������?";
				link.l1.go = "RevengeCorsair_Dominica";
			}

			                    // ��������� -->
			/*
			if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "Obsession" && !CheckAttribute(npchar, "quest.Obsession"))
			                   {
			dialog.text = "���� �� ������ ���� - ������ ������ - ���������?";
			Link.l1 = "������� ��������� ������������ ����.";
			Link.l1.go = "Obsession";
				break;
			                  }
			*/
			                    //<-- ���������

            // <== ��������� ���� ��������� �������.

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "������, ������ ����, ��� �� ������� �����, ��� ��� � �� �����, ��� - �� ��� ��� - �� ��� ������ �� �� ��� ������! ��, ����� ���� �������, ������ �����, ���� ������ ������ ���� ������!!!";
		link.l1 = "������ ���� ����� ������, � ������?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Ÿ �������? �� �� ������ �� ��� ���� - ����� � ��������.";
		link.l1 = "�������. ������ �� �������� �� �����, �� ������? ����, ��� �������� - ��� �����!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "����������. ����� �� ��� ����� ��������� �� ���.";
		link.l1 = "������.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "NoKillwork":
        	                  dialog.text = "...";
		link.l1 = "������ ��� ����� �������.";
    		link.l1.go = "NoKillwork_1";
		break;

 		case "NoKillwork_1":
        	                  dialog.text = "������� ��������, ���������.";
		link.l1 = "���������?";
    		link.l1.go = "NoKillwork_2";
		break;

		case "NoKillwork_2":
		                   DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
	                                      LocatorReloadEnterDisable("Roseau_tavern", "reload2_back", false);
		break;

		//�������, ����� �3, ������ ���
		case "PL_Q3_1":
			dialog.text = "���������. ��� �����, ����-�� ���������. �� � ������ ��������, �� � �������... �������, �� ������������� ����� ������.";
			link.l1 = "���������.";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "9");
			pchar.questTemp.piratesLine = "KillLoy_toAlexus";			
		break;

		case "PL_Q3_2":
			dialog.text = "��� �� ��� ��� ���� ����������.";
			link.l1 = "�����, �� ���� ��������?";
			link.l1.go = "PL_Q3_3";
		break;
		case "PL_Q3_3":
			dialog.text = "��, ���� ��� ����������, �� ��� ��� ����� �����������, � ����� ������ ������������. ���, ������, ������� ����� �����, �� � ��� ������������.";
			link.l1 = "������� �����?! �������, ��� ���-���.";
			link.l1.go = "exit";
			pchar.questTemp.piratesLine = "KillLoy_toGoogly";
		break;
		//�������, ����� �5, ���
		case "StepPL5Berm_1":
			dialog.text = "�� ���, ������ ��� � �������. �������, ��� ����� ���� ����, � ����. ";
			link.l1 = "� ��� �� ���� ���� ���� �������?";
			link.l1.go = "StepPL5Berm_2";
		break;
		case "StepPL5Berm_2":
			dialog.text = "���, � ����������� ���� � �������� ������� �� �����. ��� ������� �� �������, ������ ������ ���. ��� � �������...";
			link.l1 = "�������, �� ��� ������� �����!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_5_Hunter", "10");
			pchar.questTemp.piratesLine = "PL5Hunter_toOrryHouse";
		break;

		//���. �������, �����
 		case "Gothic_3_1":
    		dialog.text = "���, �� ������.";
    		link.l1 = "����� ������� ���������, ��� � ����-��� �� ����������.";
    		link.l1.go = "Gothic_3_2";
 		break;
 		case "Gothic_3_2":
    		dialog.text = "������ �� ���� �� ����, � ���� � ������� ������ �� ����.";
    		link.l1 = "������� �� ������.";
    		link.l1.go = "exit";
 		break;


		//�������, ����� ���� 3 ����������

 		case "GothicKardif_ThreeObject":
        	                  dialog.text = "� ��� �����?";
    		link.l1 = "����� ��������� �������, �������������� ����� � �������������� ���.";
    		link.l1.go = "GothicKardif_ThreeObject_1";
		break;
 		case "GothicKardif_ThreeObject_1":
        	                    dialog.text = "��, ������, ��� ������ � �����? �� �������� � � ��������� �� �������� ���������...";
    		link.l1 = "�����, �������...";
    		link.l1.go = "GothicKardif_ThreeObject_exit";
		break;
		case "GothicKardif_ThreeObject_exit":
	                   DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ThreeObject = "true";
	                   break;



 		case "Gothic_Roseau_tavernkeeper":
    		dialog.text =  "��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?";
    		link.l1 = "������ ��� ����� ������� �� ����.";
    		link.l1.go = "Gothic_Roseau_tavernkeeper_1";
 		break;

 		case "Gothic_Roseau_tavernkeeper_1":
 	                               PlaySound("VOICE\Russian\gotica\GG\ROOM_01.wav");
			dialog.text = "��� ��������� ��� � 5 ����.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "����. ��� ���� ������.";
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase("�� ������ ����������� �����? ��� ��, �� ����� ���� � ����� ������ � ����� ����.",
            "���, ������, ����� �������, ��� ��� �� �������, �� ��� ����� ��������. � ��������� � ����� ����.");
			link.l2.go = "hall_night_wait";
 		break;

		case "room_night_wait":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddMoneyToCharacter(pchar, -5);
		AddDialogExitQuest("sleep_in_tavern");
		TavernWaitDate("wait_night");
		break;

		case "hall_night_wait":
                                        PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
			if (cRand(3) == 1)
            {
                Dialog.text = "��������, �������"+ GetSexPhrase("��","��") +"! ������ ��� � ����� ���� ����������� �� ���������.";
				link.l1 = "�����, �����... ��� �����.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_night");
			}
		break;

		//********************* ����� ������� *********************

   		case "RevengeCorsair_Dominica":
			dialog.text = "��� ���, ����� ������ ������ ��� � ��� ��������� ���� �����, ����� � ������� ������������ ����� �������, ���� ���� �� ����, �� �� ��� ��� ����� ����� - ���� �� ���� �������. �������� � �������.";
			link.l1 = "�������, �������.";
			link.l1.go = "RevengeCorsair_Dominica_1";
		break;

   		case "RevengeCorsair_Dominica_1":
		dialog.text = "� ����� �������� ��� � ���� �� �����...";
		link.l1 = "�� ������� � ����, ��� ����, ��� ����.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Dominica = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_9");
		break;

		//********************* ��������� *********************
		case "Obsession":
                                    PlaySound("VOICE\Russian\gotica\KARDIF\DIA_KARDIF_HI_14_01.wav");
		dialog.text = "���� �� ������ ���� - ������ ������ - ���������?";
		link.l1 = "...";
                                    link.l1.go = "Obsession_1";
		break;

		case "Obsession_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_2.wav");
		dialog.text = "...";
		link.l1 = "��� ��������� �� ��������� �����!";
                                    link.l1.go = "Obsession_2";
		break;

		case "Obsession_2":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_19.wav");
		dialog.text = "...";
		link.l1 = "����� ����������!";
                                    link.l1.go = "Obsession_3";
		break;

		case "Obsession_3":
		dialog.text = "�� ��������� ��������� �������� ������� ���������, ����� ������� �������� �������� � ����, ����� ���� ��� ������� ��� � �������, �� ��� ���� ��� ����� � ����, ������ ��� � ���� ���������, �� ������, ����� � ���������.\n������� ������� ������ ��� ���, �� ���� ��������� � ���� � ���������, ��� � ��� ���������.\n��� ��������� �� �����, ����� ������ � ��������� �������� ������� �� ����� '��������� ������'. �� ������ �� �������� �� ������� ����� ����������� �������� ����, ������� ��� ������ ����� ����� ��������� ������ ����������, ������������ �����, �� ���������� ����� ����� �� ����� ����� � ������� � ������ � ���� ������ ����.\n���� �� �� ����� �������, ����� �� �� �������� �����!";
		 link.l1 = "� ���, ��� ������� �� �����...";
                                     link.l1.go = "Obsession_4";
		 break;

		case "Obsession_4":
		dialog.text = "� ���� ������������ ���� �����, ������� ������������� ����� ��������� ����� ����� � ����� � ���������, � ��� ������� �������� �� ������� � �������, �������� ��� ������ ����� ����!";
		 link.l1 = "������...�� ��� � ��� �� ���������.";
                                     link.l1.go = "Obsession_5";
		 break;

		case "Obsession_5":
		dialog.text = "������� �������� ���� � ���� � ���� �����, ����, ����. � ����� �� ����������� ��, ��� � �����?";
		 link.l1 = "��� ����� ���� ������, ������� �� ������ � ����, ������ ����, ��� ���� � ����, �� ����������? ��� ����� � ��� �����, ������ ����� � ������ �������, ��� �� �������, ��������� ������. �������� ���� ����� �������, ��� � �������� ����� ��� �� ���� ������. �����, ���������...";
                                     link.l1.go = "exit";
		npchar.quest.Obsession = "true";
                                    AddDialogExitQuestFunction("GothicObsessioninStart");
		 break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
