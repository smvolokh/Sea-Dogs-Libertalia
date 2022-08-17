// ������ ����������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Waitress.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":

	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(15) + ".wav");
			//--> Jason ���� �������
			if (sti(pchar.rank) > 6 && npchar.location == "PortSpein_tavern" && !CheckAttribute(npchar, "quest.Consumption"))
            {
				dialog.text = "��� ��� ������, ������? ��������, � �������... ��...";
				link.l1 = "��������, ��� �� ������ �� ����� ���������� ������? � ��� - ����� �����? ��� � ����?";
				link.l1.go = "Consumption";
				break;
			}
			//<-- ���� �������
			
			// Addon-2016 Jason, ����������� ���������� (���) ���� �����
			if (npchar.location == "PortPax_tavern" && CheckAttribute(pchar, "questTemp.FMQP") && pchar.questTemp.FMQP == "begin")
            {
				PlaySound("VOICE\Russian\Enc_RapersGirl_1.wav");
				dialog.text = "�����! �����, ��������! �������!";
				link.l1 = "�?.. ���� �������? ���? ��� �� �����, �������?";
				link.l1.go = "FMQP";
				break;
			}
            NextDiag.TempNode = "First time";
			if (CheckAttribute(pchar, "questTemp.different.FackWaitress"))
			{
				if (pchar.questTemp.different == "FackWaitress_toRoom" || pchar.questTemp.different == "FackWaitress_toRoomUp")
				{
					dialog.text = "� �������, ����� �� ���� ���� �������. �� ����� ������� �����, �� ��������� ��������...";
					link.l1 = "������, �� ���� ���� �����������...";
					link.l1.go = "exit";
				}
				if (pchar.questTemp.different == "FackWaitress_noMoney" || pchar.questTemp.different == "FackWaitress_fighted")
				{
					dialog.text = "� ����� ���������, ��� ��� �� ���������� ���� �������, ����� ���. � �� ��������� ��� �� ����� �����...";
					link.l1 = "� ��� ����������, ��� �������� �� ����? " + pchar.questTemp.different.FackWaitress.Name + ", �������...";
					link.l1.go = "Love_IDN";
				}
				if (pchar.questTemp.different == "FackWaitress_facking")
				{					
					dialog.text = "������ ���, �������. ����� ����� - ����������� ���...";
					link.l1 = "�����������!";
					link.l1.go = "exit";
				}
				if (pchar.questTemp.different == "FackWaitress_fackNoMoney")
				{					
					dialog.text = "� ��� �� ����, �� ����������� �� ���...";
					link.l1 = "��� ��� ������?!!";
					link.l1.go = "Love_IDN_1";
				}
				break;
			}
		    switch (Rand(4))
			{
				case 0:
					dialog.text = "������, "+ GetSexPhrase("���������","���������") +", � ������. ������� ���� ��� ������� - �� ������ ������� ���� ��� ���������!";
					link.l1 = "...";
					link.l1.go = "exit";
				break;

				case 1:
					dialog.text = "����������, �������, �� ����������� �������! ����� ��� ��� ������ �������� �������!";
					link.l1 = ""+ GetSexPhrase("���... ����� � �� ���������.","� ���, ������ �� ���������?") +"";
					link.l1.go = "exit";
				break;

				case 2:
					if (drand(1) == 0) // Addon-2016 Jason
					{
						dialog.text = ""+ GetSexPhrase("�, �������! �� ������ �� ������� � ��� ������� �������? � �� ����� ����������, �� ...","��������������, �������. ��������� ������� ������� ����� ������ ����.") +"";
						link.l1 = ""+ GetSexPhrase("���, ������ � �����! ����� � ������ ���!","C������, �������.") +"";
						link.l1.go = "exit";
						bool bOk = (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) || (CheckAttribute(pchar, "questTemp.LSC.Mary_officer")); // 291112
						if (pchar.questTemp.different == "free" && !CheckAttribute(pchar, "questTemp.different.FackWaitress") && PChar.sex != "woman" && pchar.GenQuest.EncGirl != "HorseToTavern" && !bOk && !CheckAttribute(pchar, "questTemp.Sharlie.Lock")) // Addon-2016 Jason
						{
							link.l2 = "� ���������� �������������, ������!";
							link.l2.go = "Love_1";
						}
					}
					else
					{
						dialog.text = "��������������, �������. ������� ����, �������� � ����� � �����. ���������� �������� ����� ����� ������ ����.";
						link.l1 = "C������, �������.";
						link.l1.go = "exit";
					}
				break;

				case 3:
					dialog.text = "���� �� ������ ���-���� �������� - ����������, ����������, � �������. �� ����� �� �������.";
					link.l1 = "������� �� �����.";
					link.l1.go = "exit";
				break;

				case 4:
					dialog.text = "���� �� ������ ��� ������� ��������� � ��������� �������� - ������� ������� �� ����. ������� � ����� ���� ���� �� �������� ��� ���.";
					link.l1 = "���������.";
					link.l1.go = "exit";
				break;
			}			
			link.l9 = "� ���� ������ ���� ���� ��������.";
			link.l9.go = "quests";//(���������� � ���� ������)
		break;
		
        case "Love_1":
			dialog.text = "����� ������ �����������. ����� ������� � ��� � �������. ��� ���� � ��� ����. � ��������� �������� � ���� �������...";
			link.l1 = "��! ��� ������, ��������! ���!";
			link.l1.go = "exit";
			pchar.questTemp.different = "FackWaitress_toRoom";
			SetTimerFunction("WaitressFack_null", 0, 0, 1); //����������� ���������� �� ���������� �� ����. ����
			//����, ��� �������, ���� ������ ������� �� 0. �� �� �������� ������� ��� ������� �� �������
			pchar.questTemp.different.FackWaitress.Kick = dRand(2); // Addon-2016 Jason
			pchar.questTemp.different.FackWaitress.Name = GetFullName(npchar); //�������� ��� ����������
			pchar.questTemp.different.FackWaitress.City = npchar.city;
			//������ ����� ����������
			sld = GetCharacter(NPC_GenerateCharacter("WairessQuest", npchar.model, "woman", npchar.model.animation, 5, sti(npchar.nation), 3, false, "citizen"));
			sld.name = npchar.name;
			sld.lastname = npchar.lastname;
			sld.dialog.Filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "Waitress";	
			Pchar.quest.WaitressFack_inRoom.win_condition.l1 = "location";
			Pchar.quest.WaitressFack_inRoom.win_condition.l1.location = npchar.city + "_tavern_upstairs";
			Pchar.quest.WaitressFack_inRoom.function = "WaitressFack_inRoom";
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
		break;
		
        case "Love_IDN":
			dialog.text = "��� ����� ������ �� ��������, ���������... ��������, � ���� ����� ���.";
			link.l1 = "������...";
			link.l1.go = "exit";
		break;
		
        case "Love_IDN_1":
			dialog.text = "��� ���, ���������� ������. � �� ����, ��� ���� ������! � ������ ���������� �� ��� - ������ ������, � �� ������� �� ��������� � ������!";
			link.l1 = "�����, �� ���� ������... ��� �����.";
			link.l1.go = "Love_IDN_2";
		break;
		
        case "Love_IDN_2":
			dialog.text = "��� ������, ��� ��� �����. ������ ������ ����� � ����������.";
			link.l1 = "�-��, ����������...";
			link.l1.go = "exit";
		break;

		case "without_money":
			NextDiag.TempNode = "first time";
			dialog.text = "�� ��������?";
			link.l1 = "�-�-�.";
			link.l1.go = "without_money_2";
		break;

		case "without_money_2":
			dialog.text = "��� �����? ����� ������?";
			link.l1 = "��� �, ���� ������?";
			link.l1.go = "without_money_3";
		break;

		case "without_money_3":
			dialog.text = "��� �� ������ �� �������? ���� ��, ��� ��� ��������?";
			link.l1 = "���? ��... ��� ������... ��� ������?!";
			link.l1.go = "without_money_4";
		break;

		case "without_money_4":
			dialog.text = "������ ��� �����? ������, ���������� �����, �������� ������� � ����.";
			link.l2 = "�����, ��� �������, �� �������.";
			link.l2.go = "exit";
		break;
		
		//--> Jason ���� �������
		case "Consumption":
			npchar.quest.Consumption = "true";
			dialog.text = "������, ������... �������, �� ��� �����, �� �...(������)";
			link.l1 = "���� �������? ���������, �������, � �������� ��� �� �������. �����, � ����� ���� ������.";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "���-���, ������, ������ ������... �������� ��� ��������������, ������... ��� ���� � ��� �������, ��� �� ����, �� � �� ����! � �� ����, ���� ������, �� ������� �������� � �� � ������� ����. � ���� ����� ������� � ���� ������ �� ��������, � ��� ��� ��� ���� ��������...(������)";
			link.l1 = "���������, ����� ����. ��� ��������� � ����� ������?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "������... �� ������� ���� �����������, �� ����� ���, ������ ��������� ��������, ���� �� �������� ������� �� �������? ��� ���� ������ �������� ��� �� ��������� �������...";
			link.l1 = "� �����-��, ��. �������������� - �� ��� �����, ��� ��� ��������� � ��� �� ������ �������. ��� ������� �� ������� � ������ �����...";
			link.l1.go = "exit";
			link.l2 = "������� ������ ��������, ��� ������������� �������... ��-��. ������ �������� ���, � ��� ����, � ��������, �������, ������.";
			link.l2.go = "Consumption_3_1";
			link.l3 = "���� ���������, ����� �� �� ������, ��� ������� ���� ����������� ������� ���� ������? � �������� ������ ����, ���� ��� ����� � ���� �����, �������.";
			link.l3.go = "Consumption_3_2";
		break;
		
		case "Consumption_3_1":
			if(sti(pchar.reputation.nobility) > 36)
			{
				dialog.text = "��� ��� - �����? ��������, �, ������, ��������, ������ � ���� ���� ��������! ��������, '���������'.";
				link.l1 = "��� ���������, ��������.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�� ��� ��... ��, �� ������� ����, ������ � ����� ��������. ������, ���� �� ������� �������, ��� �������, ��� � ��� ��������� � �� �������� ��, ��� �������, ���� ����� �����...";
				link.l1 = "����� ���������, � ����� ������������� ������� ����� ����... ������ � ����� �������� ��������������� � ������� ������ �����.";
				link.l1.go = "Consumption_4";
				npchar.quest.Consumption.sex = "true";
			}
		break;
		
		case "Consumption_3_2":
			dialog.text = "��, ������ ����, ������? ������� ������ ��� ������ ���?";
			link.l1 = "���� ��� �������, ��� ������� �������� ���� ������� � ������. �� ������������ � � ������ ���� ������. ��� ������ ��������� � �������?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "������, ������. ��� ����, ��... ��, ��� ������ ���������� �����, ��������... �� ���� ������� ����� � �������, ��������, ��-�� ����... ���������� �� ������, � ������� ������� � ������� �������. �����, ��� ��� �������� ����� �������� ������, ������� ���-�� � ����� �������� �������.";
			link.l1 = "����� ������, ���� ���� ���� ������� ���������������, ���?";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			dialog.text = "���, ������, �� �� ������... �� �� ����� ������! �� ��� ��-�� ���� ������! ����� ���, ��... �� �������� ������������� �����, ���� ���������, ���. �� ���� � ������, � �� ����� �� ��� ���� ���� �����. � ����� ��� �������. � ��� �� ������, � ���� ������ ��� ����� �� �����... �� ��� �������, ��� ������� ����.";
			link.l1 = "�������? ��� ������? � ������ �� ����� �� ������? �� ���� � ������?";
			link.l1.go = "Consumption_6";
		break;
		
		case "Consumption_6":
			dialog.text = "��. ���������, ����� � ������ ����� � �������� ������ �� �����, ������, ��� ������� ������ �������. ������������� � �� ����� ���� ���������� ��������, � ����� ��� �� ��� ������ � ���� ������� ����! ���... ��� ���� �� ���� ��������� �� ����, �������, ��� ���������� ����������� ������� ����� � ������ � �����, ����� �� ����� ������, ����� �������� ��������������� �������.";
			link.l1 = "��������? ������ ������ �����������. �� ������ �� ������ � ��� ������, ��� � ��� ���� ����� ������� �������?";
			link.l1.go = "Consumption_7";
		break;
		
		case "Consumption_7":
			dialog.text = "���... ���!(������) � �������, ��� ������ �����, �� � �������, ��� �������������, ���� �� ��... ���������, ������� ��� �������, ������� - ��������� �����. �� ���� � ��� ���-���\n��� ��� ���� �� �������, ����� � ���� ��� ��������, � ��, � ���� ������� ����, ����������� ��������� ��� � ���� ������� ������. � ����, ������ ��� � ������� �� ������� � ��������� ���, ��������!";
			link.l1 = "��... �� �������� ���� ������ ���������� � ���-�� ����� ������������� �� �������. �� ���� ������ �������, �� � �������� ������ ������.";
			link.l1.go = "Consumption_8";
		break;
		
		case "Consumption_8":
			dialog.text = "���� ��� �������� � ������, ��� � ����� ���������! �� ��� �����, ������! � ���� ����� �����!";
			link.l1 = "��, ������! �� ���� �� ������� - ���� �����... ����� ��� ����, ���������, � � ���������� �� ������.";
			link.l1.go = "Consumption_9";
		break;
		
		case "Consumption_9":
			DialogExit();
			npchar.dialog.filename = "Quest\LineMiniQuests\Consumption.c";
			npchar.dialog.currentnode = "First time";
			pchar.questTemp.Consumption = "begin";
			AddQuestRecord("Consumption", "1");
		break;
		//<-- ���� �������
		
		// Addon-2016 Jason, ����������� ���������� (���) ���� �����
		case "FMQP":
			dialog.text = "��� �� �����, �����! �������! �������, � ������� - ��� ������� ������� ������������ �����������! ��������, �������, �� ���� ��� ��� ������!";
			link.l1 = "���� �� �����, ���� ����������! � ������!!";
			link.l1.go = "FMQP_1";
			link.l2 = "��������, ��, �������, ���������� ���� �� ����������. ���� ����-�� ������� - ���� ����� ����������.";
			link.l2.go = "FMQP_exit";
		break;
		
		case "FMQP_exit":
			dialog.text = "�-�-�, ������, �� ������!!";
			link.l1 = "...";
			link.l1.go = "FMQP_exit_1";
		break;
		
		case "FMQP_exit_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			DoQuestReloadToLocation("Portpax_town", "reload", "reload4", "");
			LocatorReloadEnterDisable("Portpax_town", "reload4_back", true);
			SetFunctionTimerCondition("FMQP_Remove", 0, 0, 1, false);
			SetFunctionTimerCondition("FMQT_Activation", 0, 0, 5, false);
		break;
		
		case "FMQP_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 5.0);
			pchar.quest.FMQP_room.win_condition.l1 = "locator";
			pchar.quest.FMQP_room.win_condition.l1.location = "Portpax_tavern";
			pchar.quest.FMQP_room.win_condition.l1.locator_group = "reload";
			pchar.quest.FMQP_room.win_condition.l1.locator = "reload2_back";
			pchar.quest.FMQP_room.function = "FMQP_InRoom";
			SetFunctionTimerCondition("FMQT_Activation", 0, 0, 5, false);
		break;
	}
}