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

			//������������
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "������"+ GetSexPhrase("","�") +", � ��� �� ������� �������� ���� ���������... ����, �����, ��������.";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//����������
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "������, ��� ������� ������� - ���� ���������� - �������-���� ������� � ���� ����������! �� � ��� � ������? � ����� ��������� ��� �����, �� � �����? � �� ������ ����������, � ���� � ���� ��������� ���� �����...";
                link.l1.go = "Portugal";
            }
	                                      // ==> ������ � ����� ����
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "Smithy_DouwesenTavern" && !CheckAttribute(npchar, "quest.Smithy_DouwesenTavern"))
			{
				dialog.text = "� ������ ����.";
				link.l1 = "��� ����� ����� �������� ������, ��� � ���� � �����?";
				link.l1.go = "Smithy";
			}

			// ������� �����
			if(CheckAttribute(pchar, "questTemp.vento") && pchar.questTemp.vento == "start")
			{
				link.l2 = "�� �������� �� ������� �������, ������� ������� ������� � �������?";
				link.l2.go = "OfficerVinsentVento_1";
			}
			
			if(CheckAttribute(pchar, "questTemp.vento") && pchar.questTemp.vento == "Have_documents" && !CheckAttribute(NPChar, "OfficerVinsentVento"))
			{
				link.l2 = "������, � �� �� ������, ��� �� ������� ��� ������� ������?";
				link.l2.go = "OfficerVinsentVento_4";
			}


			// ==> ��������� ���� ��������� �������.
			switch(pchar.questTemp.State)
			{
			case "Intelligence_Curacao_tavern":
				link.l1 = "��������, ��� ����� ������ ���-���...";
				link.l1.go = "Step_E4_1";
				break;
			case "Intelligence_Curacao_dWant_pay_tavern":
				dialog.text = "������" + GetSexPhrase("","�") + "?";
				link.l1 = "������" + GetSexPhrase("","�") + ". ����� ���� ������.";
				link.l1.go = "E4_OK_pay";
				link.l2 = "������ ����� �� ��� �����?! ��� ������� �����!";
				link.l2.go = "E4_dWant_pay";
				break;
			case "Intelligence_Curacao_NoMoney_tavern":
				dialog.text = "��������" + GetSexPhrase("","�") + " �������?";
				link.l1 = "��, ����� ��, ��������" + GetSexPhrase("","�") + ".";
				link.l1.go = "E4_OK_pay";
				break;
			case "Inquisition_toCuracao":
				dialog.text = "� ������ ����.";
				link.l1 = "���� ���������� ����: ����� �������, ����� ����� �� ��������, � ���� ����� �� �������. ��� �� ������ ������� ��� ���?";
				link.l1.go = "Step_S2_1";
				break;
			case "Inquisition_afterFrancisco":
				dialog.text = "� ������ ����.";
				link.l1 = "���� ���������� ����: ����� �������, ����� ����� �� ��������, � ���� ����� �� �������. ��� �� ������ ������� ��� ���?";
				link.l1.go = "Step_S2_1";
				break;
			case "Fr2Letter_SeekProblems":
				dialog.text = "����������� ������ " + GetSexPhrase("�������� ������������ �����","������� �����������") + "!";
				link.l1 = "� ���� ������, ������ ����� �������-���������� ��������� ������� �� ������� ������������ ������� �������. ��� � ��� ���, ������� ������, ����������?";
				link.l1.go = "Step_F2_1";
				break;
			}
			if (pchar.questTemp.LSCC == "toVillemstadTavern")
			{
				dialog.text = "� ������ ����.";
				link.l1 = "��������, ��� ��� ���� ������ �������� � �������.";
				link.l1.go = "MasterKeys";
			}
			if (pchar.questTemp.LSCC == "toMasterKeysNoMoney")
			{
				dialog.text = "����������� ������ ����.";
				link.l1 = "������, ��� ����� ������ ������, �� �� ����� ���?";
				link.l1.go = "MasterKeysNM";
			}
			if (pchar.questTemp.LSCC == "toTalkStuvesant")
			{
				dialog.text = "����������� ������.";
				link.l1 = "��������, �� �� ���� ������ ������� - ������ ����? �������, ��� �� ��� � ��� � ������ ��������� �����.";
				link.l1.go = "TizerFind";
			}

			if(PChar.SmallMongrel == "5")
			{
				link.l1 = "������, �� ��������� �� � ������������ ������� ��������� �������?";
				link.l1.go = "SmallMongrel_1";
			}
            // <== ��������� ���� ��������� �������.

			//���, �����
			if (pchar.questTemp.Headhunter == "hunt_halen")
			{
				link.l1 = "��������, �� �� ������, ��� ����� ������� ��� ������?";
				link.l1.go = "Halen_tavern_1";
			}
			if (pchar.questTemp.Headhunter == "halen_still")
			{
				link.l1 = "��� � ���� ����� ��������?! ���� ������ ��� �������� ����� ����� � �������!";
				link.l1.go = "Halen_tavern_1_1";
			}
			if (pchar.questTemp.Headhunter == "halen_wait")
			{
				link.l1 = "�� ���, ������ ��� ����� �� ����������?";
				link.l1.go = "Halen_tavern_6_6";
			}
			//���, �����
 		break;

//********************** ������ � ����� ���� **********************
 		case "Smithy":
    		dialog.text = "�������� ������?";
    		link.l1 = "��.";
    		link.l1.go = "Smithy_1";
 		break;

 		case "Smithy_1":
    		dialog.text = "�� ������ � �����!";
    		link.l1 = "�����, ������!";
    		link.l1.go = "exit";
		npchar.quest.Smithy_DouwesenTavern = "true";
 		break;


//*************************** ����� �4 ��������, �������� � ������� ***************************
 		case "Step_E4_1":
    		dialog.text = "��� ����� - ������. ���������.";
    		link.l1 = "� ���� ��������� ���-����� �������, ���������, �����... ����� �����, ������ ����. � �����, ��� ����� ������� �� ����� �����������.";
    		link.l1.go = "Step_E4_2";
 		break;
 		case "Step_E4_2":
    		dialog.text = "��, 1000 ����� � �� ������� ��� ���.";
    		link.l1 = "� �� ������� �� ����� ������� �� ��� �����?";
    		link.l1.go = "E4_dWant_pay";
    		link.l2 = "����� ���� ������.";
    		link.l2.go = "E4_OK_pay";
 		break;
 		case "E4_dWant_pay":
    		dialog.text = "���, ������� ����. �� ������ ������� - �������� � ������ ����� ������. ��� ����� �������.";
    		link.l1 = "��� �, �������� ������ ������. �������� ������ � ������ �����.";
    		link.l1.go = "exit";
    		pchar.questTemp.State = "Intelligence_Curacao_dWant_pay_tavern";
 		break;
 		case "E4_OK_pay":
            if (sti(pchar.money) >= 1000)
            {
        		dialog.text = "����� �������� ����� ����� ����� �� ��������. �� ���������, ������ ���� � ���� �����������, ������� ������������ ����� �������� �������������� ������, ����� � �������� ������� �� ������������� � �������������.\n"+
                         "�� ���� ��� ��� ��������� - ���� ��� ����, �� ���� ������� ������� �� �����, �� ����� ���� ����������� � ������. ������ ���� ������ � �����, �� ���� �� ������ ��� ����� ���� � ����, �� ������ ������ � ������ ��������� �����.\n"+
                         "�� ��� ������� ��� �� ���� �������� ������ � �� ���� ������������, � ��� ��� �������.";
        		link.l1 = "� ��� �� �������-����������?";
        		link.l1.go = "Step_E4_3";
            }
            else
            {
        		dialog.text = "���, " + GetSexPhrase("������","���������") + ", ����� ���? ��� � �� ��� ������ ��������? �������, ����� �����.";
        		link.l1 = "��, �� ������ �� ������, ����� � ������� ������ ���...";
        		link.l1.go = "exit";
        		pchar.questTemp.State = "Intelligence_Curacao_NoMoney_tavern";
        		//ChangeCharacterReputation(pchar, -1); TO_DO eddy
            }
 		break;
 		case "Step_E4_3":
    		dialog.text = "��� �������-����������, �� ����� ������, �������� ������ � ������������� ������. ����� - �������� ����� � ��� ����.";
    		link.l1 = "��� ���� �� � �������� ������, �� ��� ������ � ��� �����������!";
    		link.l1.go = "Step_E4_4";
 		break;
 		case "Step_E4_4":
    		dialog.text = "������ �� ������. �������� �� � ���� ���� �������, �������, �� �� ����� ��������, �� � ������� �� �����. ��� ��� ��� �����, ���� �� ������� ��������� � ����.";
    		link.l1 = "��� �, �������.";
    		link.l1.go = "exit";
    		pchar.questTemp.State = "Intelligence_Curacao_toYozef";
    		AddMoneyToCharacter(pchar, -1000);
    		AddQuestRecord("Eng_Line_4_Intelligence_Curacao", "2");
 		break;
//*************************** ����� �2 �������, ������� ���������� ***************************
 		case "Step_S2_1":
    		dialog.text =  NPCStringReactionRepeat("����� ������� - ������� �������, ������� ������, ����� �������, ������ ��� ������� �� �������. ���� ����� �� ������� - ��������� ����� �������, ��� �������� ������� ������. � ��� ����� ����� �� �������� - ���������, �� ��� ������� �� ���� ������������ �����, ������� �� �������.",
            "�� ��� ���� �� ��� ��������...", "����� �������� ����?", "��, �� ������� �����, �?...", "block", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("����� ������ �� �����!", "��, �����", "���, ������...", "������...", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_S2_2", "none", "none", "none", npchar, Dialog.CurrentNode);
 		break;
 		case "Step_S2_2":
    		dialog.text = "����� � �� ��� ������, �� �� ���������� ����� ������.";
    		link.l1 = "�������, �������, �� ��� ����� �����.";
    		link.l1.go = "exit";
 		break;
//*************************** ����� �2 ��.�������, �������� ������ ���������� ***************************
 		case "Step_F2_1":
    		dialog.text =  NPCStringReactionRepeat("� �������������. ����� ��, �� ����� ������ �� ������� ��� ������������ ����� �������� �������� � �� ��� �������. �� ��� ��� - � �������� ������ �������-�����������. ��� �� � ������� �� ���� ����������� ������!",
            "�� ��� ���� �� ��� ��������...", "����� �������� ����?", "��, �� ������� �����, �?...", "block", 0, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat("� ���, � ������" + GetSexPhrase("��","���") + " ���" + GetSexPhrase("��","��") + " ������������" + GetSexPhrase("��","��") + " �� ����?", "��, �����.", "���, ������...", "������...", npchar, Dialog.CurrentNode);
    		link.l1.go = DialogGoNodeRepeat("Step_F2_2", "none", "none", "none", npchar, Dialog.CurrentNode);
 		break;
 		case "Step_F2_2":
    		dialog.text = "�� ��, ������ �����, ������ ��� ������� ���� ������������. ����������� � ����� �������� ����.\n"+
				          "���, ������, ��������, �� ��� �������� � ����, ������ �� ����, ����� ����. ��� �� ����? ������� �� ����, � ������ �������� ����� �� �� ��� - � ������ ���������� ������ ���������. ���������� � ����, ���� ������!";
    		link.l1 = "�������, �������, �� ��� ����� �����.";
    		link.l1.go = "exit";
 		break;
//*************************** ���, ������ ������ ***************************
		case "MasterKeys":
			dialog.text = "�-�, �� ��� ���� � ������� ������ ����.";
			link.l1 = "��� �� ������ ������?";
			link.l1.go = "MasterKeys_1";
		break;
		case "MasterKeys_1":
			dialog.text = "��� �������� ����� ������� �� ��, ��� �� �� ������� � ����� ����� ������ � �������.";
			link.l1 = "��, � ��� ������� ������?";
			link.l1.go = "MasterKeys_2";
		break;
		case "MasterKeys_2":
			dialog.text = "���. ��� �� �����, ������ �� ���� �� ������� ��������.";
			link.l1 = "�����" + GetSexPhrase("","�") + ", �������.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toMasterKeys";
		break;

		case "MasterKeysNM":
			dialog.text = "�� ��� �� ��, �� ����� ������� ����� ������ �� ���� �� ��������.";
			link.l1 = "�-�-�, �������...";
			link.l1.go = "exit";
			if (!LAi_CheckLocatorFree("sit", "sit1"))
			{
				FreeSitLocator("Villemstad_tavern", "sit1");
			}
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("GiveKeyMan")], "Villemstad_tavern", "sit", "sit1");
		break;
		//���� ������
		case "TizerFind":
			dialog.text = NPCStringReactionRepeat("��� �� �����, ��� ���� ����� ����! ������� ��� ��������...", 
				"������, � ���� ��� ����������� �� ����.", 
				"�� ��� �������� �� ����.",
                "����� ��������, �� �� ����� ������� ������������� � ���� ������ ��� �������.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� ������?", 
				"�-�, ��, � �����.",
                "��, �������.", 
				"�������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("TizerFind_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "TizerFind_1":
			dialog.text = "��, ���������, �� ������� ����������� �������� � ����� ������������. ������ ��� ����� ����� - ����������� � �������� ����� ������ � ���� �� �����!";
			link.l1 = "��� ������, ������, �����������?";
			link.l1.go = "TizerFind_2";
		break;
		case "TizerFind_2":
			dialog.text = "� ��� ������ ����! � �����, � ��� ���� ������. ���, ������, ������: '�� �� ���� �� �����?' - � ����� �������� ���������� ������. � �� ���������� �� ��� ��� ����! ���� ����� �� ���.";
			link.l1 = "����?";
			link.l1.go = "TizerFind_3";
		break;
		case "TizerFind_3":
			dialog.text = "�� ����, ������ �� ������. ������ � ���� ���� � ��� � ���� � ������� �� ������ - � ���. ���� ������ ������� - ������ ��� �������, ��� �������, �������, �� ����. �� ����, ����� ��� ���...";
			link.l1 = "���, �� �����.";
			link.l1.go = "TizerFind_4";
		break;
		case "TizerFind_4":
			dialog.text = "����, ������� ��� �������, ���� � �������. ������, ������ ���� � ����������� �������� ��������������. ��� ����� ��� �� �����, �� ��� ����� ��� ������� ������. �������� �� ������� �������������� ���� ��� ������� �����.";
			link.l1 = "��, � ��� �������-��?";
			link.l1.go = "TizerFind_5";
		break;
		case "TizerFind_5":
			dialog.text = "��� ���� ���-�� ����� ������, ��������� �� ��������! ��� ���� ��� ����� ����� �������, � ��� ����� ����� �����. ��, ��� �� �����, � �����. ������.";
			link.l1 = "� �������-���������� ��� ��� � ����� ���������?";
			link.l1.go = "TizerFind_6";
		break;
		case "TizerFind_6":
			dialog.text = "�� ������, ����� �����. ����� �����������, ��� ��� ������ � �������, � ��� ������ ����� �� ����� �� �������, � ������ ����.";
			link.l1 = "����. ������, �������, ��� ���� ����� � ����������� ����-������� ���������, �...";
			link.l1.go = "TizerFind_7";
		break;
		case "TizerFind_7":
			dialog.text = "�-�-�!! ����, ��������" + GetSexPhrase("","����") + ". �� ���� ������ ������ ������� �������� �� �������. � ���������� ���� �� ���������� - ��������� ������������� �� ����� ���������!";
			link.l1 = "� � ��� ���� ��?";
			link.l1.go = "TizerFind_8";
		break;
		case "TizerFind_8":
			dialog.text = "��� �������� ������ �� �����, ��������" + GetSexPhrase("","����") + ". � �� �� ������, ��� ������� �� � �������� ����������� � ������ � ��������� ������. ����� ��� ���� ������������, �� �� ��� ����...";
			link.l1 = "����!.. � ��� �� �� ����� �����?";
			link.l1.go = "TizerFind_9";
		break;
		case "TizerFind_9":
			dialog.text = "� ����� ��� ����?";
			link.l1 = "���� ���������� ���� ������ � �������� ����������.";
			link.l1.go = "TizerFind_10";
		break;
		case "TizerFind_10":
			dialog.text = "������, " + GetSexPhrase("��������","��������") + ", �������� ��� ���� ���� ������ ��� ������� �����, ��� ��. ������������, ��� ��� ������� ����������� ��, �� � �� ������ ���� ������!..";
			link.l1 = "��� ������! ��������� �������.";
			link.l1.go = "TizerFind_11";
		break;
		case "TizerFind_11":
			dialog.text = "���. ��� ���� ����� - �� ������� ������ � ���� ����, ����� ��� �������� ������ � ����� �����. �����" + GetSexPhrase("","�") + "?";
			link.l1 = "�����" + GetSexPhrase("","�") + "... ��, �������, ������� ���� �� ����� ��������� ���������. ����� ���� ���������.";
			link.l1.go = "TizerFind_12";
		break;
		case "TizerFind_12":
			dialog.text = "�� �� �� ���. � � ��� ��� ���������.";
			link.l1 = "���� ������.";
			link.l1.go = "exit";
			AddQuestRecord("ISS_PoorsMurder", "8");
		break;

//---------------------------------------------------------------------------------------------------------------
		// ������� �����
		case "OfficerVinsentVento_1":
			dialog.text = "��, ����������� ������, ������� � ���� ���� �������� ����������� ����, � ��� ���������?";
			link.l1 = "� �� �������� �� ������� ��������, �� �������� �� ��� ������ ����?";
			link.l1.go = "OfficerVinsentVento_2";
		break;
		
		case "OfficerVinsentVento_2":
			dialog.text = "������ �������... ���, ����� �� ���� �����... ���� ��������, ����� �� �� ��� ����� ������� ���... �����, ����������� ������ �����!";
			link.l1 = "� ��� ����� ���� ���?";
			link.l1.go = "OfficerVinsentVento_3";
		break;
		
		case "OfficerVinsentVento_3":
			dialog.text = "��� - ������ � ������������ ������� ������� �'�������, ������ �� ������� ��� ����� �������� �����.";
			link.l1 = "������� �� ����������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("OfficerVinsentVento_bill");
		break;
		
		case "OfficerVinsentVento_4":
			dialog.text = "������? ������ ��, ����. ���� ������� ������� ������� ������� ������� ���� ������� - ���������� ������ �����������! ���� ����� ���������� � ���� ��������. ��� ��� ��������� ����� ������ �����.";
			link.l1 = "�������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes");
			NPChar.OfficerVinsentVento = 1;
		break;

		// ��������� ������� -->
		case "SmallMongrel_1":
			dialog.text = "��, ��� � ��� ��� ���� ������ � ���������� �����������! ������ ��������?";
			link.l1 = "� ������������� ��������.";
			link.l1.go = "SmallMongrel_2";
		break;
		
		case "SmallMongrel_2":
			dialog.text = "��, ��������. ��� ���-������ �����, ���� ����� �������� ����� �������� ��������� ����������, �������� �������������� � ������ �����������. ��������� �����, ������� �����, �������� ������� �� ��� ��������� ��������, �� ������, ��� �� ����� �����?";
			link.l1 = "���?";
			link.l1.go = "SmallMongrel_3";
		break;
		
		case "SmallMongrel_3":
			dialog.text = "�������� ����� �� ���� �� ������ � ����������! �� ������ �����������, �������, ��������� ������� ������ � ������ ����������� ��� ��������� ������� ����, �� ��� ���� ������� ���� ����, � ����. � ���� ����� ������� ��������� �����������, �������� �� ������ �������� ����.";
			link.l1 = "...(���������)... �����, �������, ���� ��������, " + GetName(NPChar, "n") + ".";
			link.l1.go = "SmallMongrel_4";
		break;
		
		case "SmallMongrel_4":
			dialog.text = "���, �������, �������� ���� ������ �����. ��� ������� ��� ������� ��������, ���������� ������������� � ������ ��� ����� ��� ��� ����������� � ��������� �������.";
			link.l1 = "� ��� ������ � �����������-�� ����?";
			link.l1.go = "SmallMongrel_5";
		break;
		
		case "SmallMongrel_5":
			dialog.text = "������, ������, �������. � ���������� ������� ������ � ������� ���������. �� �� ��������, ��� ��� �������, ������� ������ �� ���� ����������.";
			link.l1 = "��-�... ̸����� �������?";
			link.l1.go = "SmallMongrel_6";
		break;
		
		case "SmallMongrel_6":
			dialog.text = "...(��������)... ������ �� ������?!";
			link.l1 = "�������" + GetSexPhrase("��","���") + ". ���������, ��� ���� ������?";
			link.l1.go = "SmallMongrel_7";
		break;
		
		case "SmallMongrel_7":
			dialog.text = "������ ���� ������ �������, � ������� ���� ���������� ������. ����� ������ ��������� ��. ������� �������.";
			link.l1 = "�� ��, � ��� �����?";
			link.l1.go = "SmallMongrel_8";
		break;
		
		case "SmallMongrel_8":
			dialog.text = "������ �������� �� ������, ������� ������� � �������, � �� ����� � ������ ������������ �����. �� �� ���� ���������� ������� �� �����������. ����� ��� ������� �� �������. ��� - ���������. ������� ����� ����, ��� ������ ����������� ���� ��� �� ������, �� �������� ���������� ����������� �������.";
			link.l1 = "׸��, ��� ��� �������, � ���� �������������, ��� ��� �������� �������?";
			link.l1.go = "SmallMongrel_9";
		break;
		
		case "SmallMongrel_9":
			string sPortMan = GetName(&Characters[GetCharacterIndex("Villemstad_PortMan")], "f");
			dialog.text = "�� ����, �������, �� ���� ����� �������� ����������� �������� �����������. ��� ��� " + sPortMan + ".";
			link.l1 = "������� �� ����������� �������, " + GetName(NPChar, "n") + ".";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SmallMongrelToCuracaoPortMan");
		break;
		// ��������� ������� <--


		//������������
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "�� ��, ������ ������� �� ������... ������ ������ ����� ����������� � �����. ��� ��������� ������ �����, � ������ ����� ����� ���� ���������. ��������� ��������, ��� ��� �� ����� ������ - ���� ������� ���������. � ��� �������� � ������� ����� ���� ����������� - ������� � ������...";
			link.l1 = "���������! �������� ���������, ��� ���?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "������� � ������ - ��� ���� � ��������� ��������, ��, � ���, ������� ������ ������. ������ � ��� ����. � ����� ������� �� ������ ��� ������� ���������, �������, � ������� ���� �� ������. � �����, ����� ���������� ����� �������. ��� ����� �� ����������� �������, �� � ������ ���� �� � �������� - ������ ��� ����� �����������\n� ���� �������, ��� ������� � ���� � ������ ��� �����-�� �� �� ������, �� �� �������... ������ ��, ��� ���, ������� ������ ������, �� � ����� ����� ���������. ��� � ������ �� �� ���������\n����� ������ �� ������ � �������� ���� ���������� � ���������. ������ ������� �� ������ ������� - ��� � ��� ���� ��������. ����� ����� ���� ������ �� �������� ���������, ��������, � �������� ��� ����� �� �����. ����� ���� � ������� � ������� ��� �����...";
			link.l1 = "��� ��� �������! ����� ����� ��� ������! � ������ �� ��� ��� ������?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "�����, "+ GetSexPhrase("������","�������") +", ������� ����� ��������. ��� ����������� �����, ���������� ������ �������...";
			link.l1 = "� ��� ��� �����������? ����� ���� ����������?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "����� ���! ���� �� ��������� ������������, ����� � ���� � ������� �� �����. ����� ������ ������� ������� � ������� ������, �������� ��� ������ - ������ ���.";
			link.l1 = "�� �� �������! ������ ������� - � ��� ��� � ���� ������!";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "������, "+ GetSexPhrase("������","�������") +"! � ���� ��� � ������!";
			link.l1 = "�� ��� � ��� ������, " + npchar.name + "? �� ������� ���-��...";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "��-��... ����� �� ������ - ������ ��� � �������. ���� � ���, ��� �� ��������� ���� ����� ��������� �� ������� �������� ������ ����. �� ���� ��� ���� �� ����� ���� ����, ���� ��� �� ���� ��� ������� � ��� ������! ������� � ��� �� �� �������.";
			link.l1 = "�����, ������� �� ���������� �������, " + npchar.name + ". ���� �� �����������, ��� ����� ����� ����������� � ��������.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "��, ������ �����... �����, ��� �� ��� ������ �������� �����. ������������ �� ��� ���, " + pchar.name + ", �� ���������, � � ��� ��� ������� ����������.";
			link.l1 = "�������! ��, ��� ����.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "��, �������� ����� ������, �� �����. � �� ������ ���� ����������� ���? ��� ��������� �� ������, ������, ������� ����. �� ���� ������� �� �����, ��� ���������� � ���� � ������. �������, ������ - ����� ������� ����� � ��� ����� ���������!";
			link.l1 = "� ���� ��� � �������� � ���� �������?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "�������, ����� ������� �� ����� ������������, �� �����... �� �������� ����-��. � ������ �� �������� ���� �������� - � � ����� �������� ����� �����. �������, �� �� ��� ����� �������� ����� �������� � ���-�� ������. ������, ������ ������, ��� �� ���� ����� ������� ����� ��������, �� �� ��� ��� �� ��������� �� ��������.";
			link.l1 = "��� ����� ��������� ��� �����, �� �� ������?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "����� ����� �� �����. ����� - ��� ������ ��������, ��� �����, ��� � ������� ��� ��������� �������. ���������� ������ � ������ ��� �������� �������. ������� � ��� �������� ��� � ��� ������� - � ��� ��� ��� ������������ - �� ��� ������ ���������� � �����������. ��, ��� ��� � ���������� �� ��������� � ������ ���������, ��-��...";
			link.l1 = "������ �� � ������! �����, ���� ������� �� ���������. �� ���� ���������� ��� �������������. �����, "+npchar.name+"!";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;

		//���, �����
		case "Halen_tavern_1":
			dialog.text = "���, ��� ������ ����� ���. �� ���� � ��������, �� �������� �� ��� �� ����. ������ ������������ � ����. ����� �� �������� - � ��� ������.";
			link.l1 = "�������. ��� ����� ��� ���������. ��, ����� � ����� ������� � ����?";
			link.l1.go = "Halen_tavern_2";
		break;
		
		case "Halen_tavern_2":
			dialog.text = "��, �������. C ��� 100 �������.";
			link.l1 = "������. �������� ���� �������.";
			link.l1.go = "exit";
			pchar.questTemp.Headhunter = "halen_room";
			LocatorReloadEnterDisable("Villemstad_tavern", "reload2_back", false);
            AddMoneyToCharacter(pchar, -100);
			Pchar.quest.Headhunter_inRoom.win_condition.l1 = "location";
			Pchar.quest.Headhunter_inRoom.win_condition.l1.location = "Villemstad_tavern_upstairs";
			Pchar.quest.Headhunter_inRoom.function = "RatHunters_inRoom";
			AddQuestRecord("Headhunt", "27");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","�"));
			pchar.quest.Headhunter_HalenOver.over = "yes";
		break;
		
		case "Halen_tavern_1_1":
			dialog.text = "�� ��� �� ����� ��������? � ������� ���������� ������� ����������!";
			link.l1 = "����. � ����������� ���� ���� - � ���������"+ GetSexPhrase("","�") +" ���� ���� �����.";
			link.l1.go = "Halen_tavern_2_2";
		break;
		
		case "Halen_tavern_2_2":
			dialog.text = "���� ��������� ����������! ����� ������! � ��� � ���� �������...";
			link.l1 = "���������. ����� ������ ���: �������� ������ ����� ����� ������ ����, �� �������� ������� ����, ����� �� ��������� ��������� ������ ���������... �� �����, ��� ��� ������� �� �������, ��� ��� ����� ������ � �� ������. �� �����, ��� ��� ��������? ��� ����, � ������, ���� ������� ��������.";
			link.l1.go = "Halen_tavern_4_4";
		break;
		
		case "Halen_tavern_4_4":
			dialog.text = "���... �� �����. �������... �� ��� �� ��� �� ���������!";
			link.l1 = "�� ����������� ������� ���������? �� �����, ��������? �������, ������� ������ � � �� ������"+ GetSexPhrase("","�") +"... � �� ����� �� � ������� � ����? � �� �...";
			link.l1.go = "Halen_tavern_5_5";
		break;
		
		case "Halen_tavern_5_5":
			dialog.text = "��� ��, "+ GetSexPhrase("����������� ��������","����������� �������") +"! ��� ��� �������� �����, ������� �� ����� �� ���� �� ����...";
			link.l1 = "������-������, � ���� ����. ������ �� ����������, �� ������?";
			link.l1.go = "Halen_tavern_6_6";
		break;
		
		case "Halen_tavern_6_6":
			if (makeint(environment.time) > 18.0 || makeint(environment.time) < 6.0)
			{
				dialog.text = "���, �� ���������. ��������� ������ ����� - ��������, � ���� ����� �������.";
				link.l1 = "������.";
				link.l1.go = "exit";
				pchar.questTemp.Headhunter = "halen_wait";
				break;
			}
			dialog.text = "�� ��� ��� �������! ������ ������� ��� ������ ������ ����� � ����� �����.";
			link.l1 = "�������! ������, ������ ��� � ������?";
			link.l1.go = "Halen_tavern_7_7";
		break;
		
		case "Halen_tavern_7_7":
			dialog.text = "��, �� ���������� � ������� � �������-����������� ����� �� ��������. �����, ���� ������������ - ��������� ��� � ����������. ��� ������� ��� �� �������.";
			link.l1 = "�����"+ GetSexPhrase("","�") +". ��� ����. ������� ����!";
			link.l1.go = "Halen_tavern_8_8";
		break;
		
		case "Halen_tavern_8_8":
			AddQuestRecord("Headhunt", "29");
			pchar.questTemp.Headhunter = "halen_town";
			CreateHalen();
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

