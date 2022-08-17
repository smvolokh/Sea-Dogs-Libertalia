// ������ ��������, ����� ���������� � ������������ �����, ���������� �������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
    
// ============================================================================
// ============================= ���� angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //������� ������� ������������
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //���� ����������� ������� �����. � npchar.angry.name ������� �������!!!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= ���� angry ===================================
// ============================================================================
	switch(Dialog.CurrentNode)
	{
		case "First time":
            NextDiag.TempNode = "First time";
            if (CheckAttribute(npchar, "Sp5LaVegaAttackDone"))
            {
            	if (NPChar.quest.meeting == "0")
				{
					dialog.Text = TimeGreeting() + "! � "+ GetFullName(NPChar) + ", ����� ��������� � ���� ����. � ���������, �������� � ������� ������� ����� �������� ������, �� ������ �� ��� ��� ��������� ������� ������ �� �����.";
					Link.l1 = "���"+ GetSexPhrase("","�") +" ����������. � ������� " + GetFullName(Pchar) + ". ��� ��� ����.";
					Link.l1.go = "exit";
					NPChar.quest.meeting = "1";
				}
				else
				{
					dialog.Text = TimeGreeting() + ". � �����, ����� ����� ���, ����� �������������� ���������� ������� �������, ���� ������� ������ �������� �������.";
					Link.l1 = "�� ���� ������.";
					Link.l1.go = "exit";
				}
            }
            else
            {
				dialog.text = NPCStringReactionRepeat("� ���� �� ��� ����? ���? ����� "+ GetSexPhrase("��������� ������!","������� �� ��������� ����.") +"",
	                         "�, �������, ���� ���������...", "���� � ��������� � ����, �� �� ����������� ��������� ����!",
	                         "��, �� �� �� � ���� "+ GetSexPhrase("�������, ��� ���","�����, ������") +"...", "repeat", 30, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��� �����.",
	                                               "��, " + npchar.name + ", ���������� ����.",
	                                               "������, " + npchar.name + "...",
	                                               "��, ��...", npchar, Dialog.CurrentNode);
				link.l1.go = "exit";
			}


					if (npchar.city == sti(pchar.HeroParam.Location))
					{
						if(!CheckAttribute(PChar, "questTemp.pirateStartQuest"))
						{
							link.l2 = "����� ����� ��������� ��� ���� ��������?";
							link.l2.go = "pirateStartQuest";
						}
						else
						{
							if(pchar.questTemp.pirateStartQuest == "3" && !CheckAttribute(PChar, "questTemp.pirateStartQuest.many"))
							{
								link.l2 = "� ���"+ GetSexPhrase("��","��") +" �� ����, �� ��� ����� ������ - 30 000 ����, ����� �������� ����� �� ����.";
								link.l2.go = "pirateStartQuest_many";	
							}
							if(pchar.questTemp.pirateStartQuest == "3" && GetCharacterItem(pchar, "letter_open") > 0)
							{
								link.l2 = "��������, ��� �� ������ � ���"+ GetSexPhrase("��","��") +" �� ����� ������ �� ���������������.";
								link.l2.go = "pirateStartQuest_info_1";	
							}
							if(pchar.questTemp.pirateStartQuest == "5")
							{
								link.l2 = "���� �������. ������ ���� ������ �� ����� �������� ���������� � �������� �������.";
								link.l2.go = "pirateStartQuest_final";	
							}
						}
					}
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		//zagolski. ��������� ����� �� ������ ===================================
		case "pirateStartQuest":
			dialog.text = "��... ���������, ��������? � ��� ���� ����� ������, ��� �� �� ��� �������"+ GetSexPhrase("��","���") +". ��� ��� ��� ����� ������� �� �������. ���������� ���-��� ��������� � �������� ���������, � ���� ����� ��� �����, ��� �����������. ����� ����� �� ������, �� ���-��� ���������.";
			link.l1 = "��� � ������. � ��� �� ����?";
			link.l1.go = "pirateStartQuest_1";
			link.l2 = "������, �� ������� � ��������� �� ����. ������...";
			link.l2.go = "exit";
			pchar.questTemp.pirateStartQuest = "0";
		break;
		case "pirateStartQuest_1":
			dialog.text = "� ���� � ��������� - � ����� ����� ���������� � � ��������� ����� '�������' � �������� 200 �����, ����� ������� �� ������ ���������� �� ��������� ���������. ��� � ����� ��������� �����, � �������� ����������, � ��� ����� ��� ��������, ��� ��� ����� ������ � ��������� �������. ��!.. ������� � ���� �� ��������. � ������� ��������� ���������� ������� ������� � ������, ��� ����� ��� ���������� � ������ ����� - ���� � ������, �� ��� ������ � �����.";
			link.l1 = "� ���? � ����"+ GetSexPhrase("��","��") +" � ��������� ��� ��������� 200 �����, ���� �� �� ������� �������? � ��� ��� �� �������?";
			link.l1.go = "pirateStartQuest_2";
		break;
		case "pirateStartQuest_2":
			dialog.text = "���, �������. ����� � ����� �� ������? ������� � �� ����� � ����� ������. �� ��� ����� ��������������, ��� ����, ������� ��� ����������� - ��� � ���� ��� ������. � �� ������ ������� ���, ��� ��������� ��� ����� ������, � �������� ���� 10 000 ����. ��������� ��� ������. �� ���, ��������?";
			link.l1 = "������! � ��� ��� ����� ����? ���� �����-�� �����������?";
			link.l1.go = "pirateStartQuest_3";
			link.l2 = "���. ������ ��������� ����, ��������� ��� � ����� �� 10 000 - ������, �� ��������.";
			link.l2.go = "exit";
		break;
		case "pirateStartQuest_3":
			dialog.text = "���� �� � ���� ��� ���� �����, � �������� �� � ��� ����� �����. ��� �� ��� � ���� ������ ��������� �� �����. �� ���� ������ ���������� ������ - ��� ��� ������ � ����� '�������' � � ���� ���������? �� ����� ��� ������ � ��� ��������. ��������?";
			link.l1 = "��, ���� ���-�� �������������� ����������.";
			link.l1.go = "pirateStartQuest_4";

			pchar.questTemp.pirateStartQuest = "1";
			pchar.questTemp.pirateStartQuest.City = npchar.city;
			pchar.questTemp.pirateStartQuest.Areal = GetArealByCityName(pchar.questTemp.pirateStartQuest.City);
			pchar.questTemp.pirateStartQuest.Name = GetFullName(npchar);

			AddQuestRecord("pSQ", "1");
			AddQuestUserData("pSQ", "sCity", XI_ConvertString("Colony" + pchar.questTemp.pirateStartQuest.City + "Gen"));
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);
		break;
		case "pirateStartQuest_4":
			dialog.text = "���! ��� ��� � ���. ������� ���� ��������� ����������� � ������� ����� - � ���� ���� �� �������. ��� ����� ����������, � ������ - ��� ������ �� �������. ������ �� ���������, ������ ����� �� ���� �� ���� ������� ����� �� ������? ���� � �� ������, ��� ������� ���������� - ����������� ���� �������. � ��� ����� ����� �� �������...";
			link.l1 = "�������... ������, ����� ����������� ���� � �� ��������� �����. ����������� �� ������.";
			link.l1.go = "exit";
		break;

		case "pirateStartQuest_many":
			dialog.text = "�������� �����, ��������? ��� ������� �����... ���� ���� ������ 5000 ����, ������ � ���� ������ ���. �� ���� ��������� ������� � ���� - ����� � ������ �� ��������� ������! �� ���� ����� ����� �� �������.";
			link.l1 = "����� ���� �����...";
			link.l1.go = "pirateStartQuest_many_1";
		break;
		case "pirateStartQuest_many_1":
			dialog.text = "���, �����. ��� ���������� ������.";
			link.l1 = "��� ����� � �������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 5000);
			pchar.questTemp.pirateStartQuest.many = "";
		break;

		//------------------------------------
		case "pirateStartQuest_info_1":
			dialog.text = "��! �������� �������! � ��� ������, ��� �� � ���� ����������. �� ��� ������ ������ ���������� ����������.";
			link.l1 = "� ������ ���� ��������"+ GetSexPhrase("","�") +". ���� �������� ���� ������ �����.";
			link.l1.go = "pirateStartQuest_info_2";
			TakeItemFromCharacter(pchar, "letter_open");
		break;
		case "pirateStartQuest_info_2":
			dialog.text = "�������, ��� ��������� �������. �� �� �� �����, � ���� �������� ���� ��� ���� ����\n������� - ��� ������� �� ������� ������� ����, ������� ����� �� ������� '�������'. � ������, ��� ������ ���� � ���� ����������, ���� �� � �� �����. ��� ������� ������ � ��������� �������, ���� ������ - ��������� ����� � �������� �������. � ������ ��� �� ���� �� ������"+ GetSexPhrase("","�") +", ������� � ������ ���� �������� ��� ���� ����. ������� 15 000 ����. ������"+ GetSexPhrase("��","��") +"?";
			link.l1 = "������! ������, ��� ��������� ������ ���� ��� ��������.";
			link.l1.go = "pirateStartQuest_info_3";
			link.l2 = "������ ���, ������� ��� � ��� �����������... �� � �������. ������, �� � ���.";
			link.l2.go = "pirateStartQuest_info_noex";
			AddMoneyToCharacter(pchar, 10000);
		break;
		case "pirateStartQuest_info_noex":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
		break;
		case "pirateStartQuest_info_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "4";

			AddQuestRecord("pSQ", "7");
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);

			pchar.quest.zpq_seaBattle.win_condition.l1 = "location";
			pchar.quest.zpq_seaBattle.win_condition.l1.location = pchar.questTemp.pirateStartQuest.Areal;
			pchar.quest.zpq_seaBattle.function = "pirateStartQuest_seaBattle";
		break;

		case "pirateStartQuest_final":
			dialog.text = "�����-�����. ��� ���� ��������� ��� � ��� �������� ���, ��� �� ������� �������"+ GetSexPhrase("��","���") +". �� ��� �, ���� ���� �� �������� ������"+ GetSexPhrase("","�") +", ��� ��������� ������� � 15 000 ����. � ������� ����, ������� �� ��� �����"+ GetSexPhrase("","��") +".";
			link.l1 = "��� � �������, ���"+ GetSexPhrase(" ���","� ����") +" ������! � ������ ���� ���� ����, � � ��� ����� ��������"+ GetSexPhrase("��","���") +". �� �������!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 15000);
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
			group_DeleteGroup("pirateStartQuest_Smuggler_group");
		break;
				
 		case "No_Mansfield_first_time":
			dialog.text = "������ ����, ���� ����� ������� ���. ����� ������ ��������� � ������ ������ ����������.";
			link.l1 = "����� �������, �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "No_Mansfield";
  		break;
 		case "No_Mansfield":
			dialog.text = "��� ������ ������� � ����� �������������. ����� �����.";
			link.l1 = "� ��� �����.";
			link.l1.go = "exit";
  		break;
		

// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ����� ����!");
			link.l1 = "��-��-��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ���������� ����� 30 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "���� �� ����� ��������� ����, ������� ���.";
        			link.l1 = "� �����"+ GetSexPhrase("","�") +", ������, ������ �� ����.";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("LaVega_town","reload","reload6");
		break;
// <<<<<<<<<<<<============= ���� ��� angry =============================
	}
}
