// ������� ��� �����
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sLoc;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;
    
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
            dialog.text = NPCStringReactionRepeat("� ���� �� ��� ����? ���? ����� "+ GetSexPhrase("��������� ������!","������� �� ��������� ����.") +"",
	                         "�, �������, ���� ���������...", "���� � ��������� � ����, �� �� ����������� ��������� ����!",
	                         "��, �� �� �� � ���� "+ GetSexPhrase("�������, �������","�����, ������") +"...", "repeat", 30, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��� �����.",
	                                               "��, " + npchar.name + ", ���������� ����.",
	                                               "������, " + npchar.name + "...",
	                                               "��, ��...", npchar, Dialog.CurrentNode);
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ����� ����!");
			link.l1 = "��-��-��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ��������� ����� 30 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "���� �� ����� ��������� ����, ������� ���.";
        			link.l1 = "� �����"+ GetSexPhrase("","�") +", �������, ������ �� ����.";
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
            DoReloadCharacterToLocation("Vestpunt_town","reload","reload6");
		break;
		// <<<<<<<<<<<<============= ���� ��� angry =============================
	}
}

