// ����� - ������ �� �������

#define MAX_RUMOURS_ABOUT_OWNERS 7

void ProcessCommonDialogRumors(ref NPChar, aref Link, aref NextDiag);
{
    string strum;
    string srum;
	switch(Dialog.CurrentNode)
	{
/////////////////////////////////////////////////---����� �������---////////////////////////////////////////////
		case "rumours_towngirl":
    PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");		
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("towngirl", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        string posrep1, posrep2, answ1, answ2, answ3, answ4;
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��������, ��� ��� ���������.");
            posrep2 = " � � ���, �������, ���� �����-������ �������� ��� ����� �������?";
            answ1 = RandPhraseSimple(RandSwear() + "���������� ���� �� �������������, "+GetFullName(NPChar)+".",
                                 "����� �������� ��� ���...");
            answ2 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����. ��� ����, �� ������� �������� � ���� ���. ","� ������� �����, ��� ��� ���-������ � ������ ���.");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("� ���������, ������ � ������ �� ����, ��������� ��� ����.","�� ������� ���� ������ �����������, ����� ���� ��������, �� ���� ���� ����."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
                                            answ2,
                                            answ3,
                                            answ4,
                                            npchar, Dialog.CurrentNode);
		link.l1.go = "new question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";
	break;

/////////////////////////////////////////////////---����� �����---////////////////////////////////////////////
	case "rumours_townman":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("townman", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��������, ��� ��� ���������.");
            posrep2 = " � � ���, �������, ���� �����-������ �������� ��� ����� �������?";
            answ1 = RandPhraseSimple(RandSwear() + "���������� ���� �� �������������, "+GetFullName(NPChar)+".",
"����� �������� ��� ���...");
            answ2 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����. ��� ����, �� ������� �������� � ���� ���. ","� ������� �����, ��� ��� ���-������ � ������ ���.");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("� ���������, ������ � ������ �� ����, ��������� ��� ����.","�� ������� ���� ������ �����������, ����� ���� ��������, �� ���� ���� ����."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "new question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";

//��������� ��������� �����
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.Sharp.City == npchar.city && sti(pchar.questTemp.Sharp.City.rumour))
		{
			pchar.questTemp.Sharp.City.rumour = false; //���� ���
			Dialog.Text = Sharp_choiceAction();
			link.l1 = "��, �������... ��� ��� ������?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
									"����� ��������.");
			link.l2.go = "exit";
			
		}
	break;
	
	///////////////////////////////////---����� ������ ���������---////////////////////////////////////////////
	case "rumours_marginal":	
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("townman", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��������, ��� ��� ���������.");
            posrep2 = " � � ���, �������, ���� �����-������ �������� ��� ����� �������?";
            answ1 = RandPhraseSimple(RandSwear() + "���������� ���� �� �������������, "+GetFullName(NPChar)+".",
"����� �������� ��� ���...");
            answ2 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����. ��� ����, �� ������� �������� � ���� ���. ","� ������� �����, ��� ��� ���-������ � ������ ���.");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("� ���������, ������ � ������ �� ����, ��������� ��� ����.","�� ������� ���� ������ �����������, ����� ���� ��������, �� ���� ���� ����."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";
	break;
	
/////////////////////////////////////////////////---����� ������---////////////////////////////////////////////
	case "rumours_nobleman":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
        srum = SelectRumourEx("nobleman", NPChar);
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��� ���.");
            posrep2 = " ��, � ��� ��. ��� ������ ������ �������� � ����������.";
            answ1 = RandPhraseSimple("���������� ���� �� �������������, ������! �� �����, ��������� ��� ������...",
"��������� ��� ������...");
            answ2 = RandPhraseSimple("��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ���� ������, ����������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����! ����� ��� ��������...","��������� ���, ������. �� �����, �� ��� ������...");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("�, �������, ������� ��������� - � ���� ��.","�� ������� ���� ������ �����������, �������. �����, ��������� �����, �������!"),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";
	break;
	
/////////////////////////////////////////////////---����� ��������---////////////////////////////////////////////
	case "rumours_noblegirl":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");		
        srum = SelectRumourEx("noblegirl", NPChar);
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��������, ��� ��� ���������.");
            posrep2 = " ��, � ��� ��. ��� ������ ������ �������� � ����������.";
            answ1 = RandPhraseSimple("���������� ���� �� �������������, ��������! �� �����, ��������� ��� ������...", "��������� ��� ������...");
            answ2 = RandPhraseSimple("��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ���� ������, ����������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����! ����� ��� ��������...","��������� ���, ��������. �� �����, �� ��� ������...");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("�, �������, ������� ���������� - � ���� ��.","�� ������� ���� ������ �����������, �������. �����, ��������� �����, �������!"),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";
	break;
	
	///////////////////////////////////////////---����� ��������---////////////////////////////////////////////
	case "rumours_sailor":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2) srum = SelectRumourEx("sailor", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", " ��������, ��� ��� ���������.");
            posrep2 = " � � ���, �������, ���� �����-������ �������� ��� ����� �������?";
            answ1 = RandPhraseSimple(RandSwear() + "���������� ���� �� �������������, "+GetFullName(NPChar)+".",
"����� �������� ��� ���...");
            answ2 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����. ��� ����, �� ������� �������� � ���� ���. ","� ������� �����, ��� ��� ���-������ � ������ ���.");
            answ4 = "";
        }
        else
        {
            posrep1 = " � ��� ������ ����� ���-���� ����������. �� ���� �� ���������� ���-�� ���������, �� ��� �� ���� ������ � �������.";
            posrep2 = " ��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ��������-�� ��� �����...",RandSwear() + "�� ������ �� ������! �����, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("��������, �� ������, �����, ����� ��� �����...","��, �� ������ �� ��� �����"+NPCharSexPhrase(NPChar, "","��")+", ��, �����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("� ���������, ������ � ������ �� ����, ��������� ��� ����.","�� ������� ���� ������ �����������, ����� ���� ��������, �� ���� ���� ����."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";
	break;
///////////////////////////////////////////---����� ��� ---////////////////////////////////////////////
	case "rumours_pgg":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2) srum = SelectRumourEx("PGGG", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" ����� ��� ����...", "��������, ��� ��� ���������.");
            posrep2 = "����� �� ���������� ���-������ ����������, �������?";
            answ1 = RandPhraseSimple(RandSwear() + "���������� ���� �� �������������, "+GetFullName(NPChar)+".",
"����� ���������� ��� ���...");
            answ2 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...","��� ������.");
            answ3 = RandPhraseSimple("���� ������ �� ��������� �� �����. �� �����, ��� ���� ���������� ���-�� ���, ����� �� ��� ��������������, �������.","� ������� �����, ��� ��� ���-������ � ������ ���.");
            answ4 = "";
        }
        else
        {
            posrep1 = "��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            posrep2 = "��� ��� �������� �������. �� ����� " + GetAddress_Form(NPChar) + " ������� ���-�� �����?";
            answ1 = RandPhraseSimple("����� ���������� ��� �����...",RandSwear() + "��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
            answ2 = RandPhraseSimple("������� ��� �����...","�����, �� ������ ���-�� ���?");
            answ3 = RandPhraseSimple("�� �����, ��� ���� ���-�� ���, ����� �� ��� ��������������.","� � ������������� ���-������ ��������, �� ���-������ � ������ ���.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("� ���������, ������ � ������ �� ����, ��������� ��� ���������.","�� ������� ���� ������ �����������, ����� ���� ��������. ������� ������ ����."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.","����� ��������.");
		link.l2.go = "exit";

	//��������� ��������� �����
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.Sharp.City == npchar.city && sti(pchar.questTemp.Sharp.City.rumour))
		{
			pchar.questTemp.Sharp.City.rumour = false; //���� ���
			Dialog.Text = Sharp_choiceAction();
			link.l1 = "��, �������... ��� ��� ������?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
									"����� ��������.");
			link.l2.go = "exit";
			
		}
	break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "rumours_habitue":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
		Dialog.Text = LinkRandPhrase("��... �-��! ","��, ����� ���! ","�-��... ")+SelectRumourEx("habitue", NPChar);
		link.l1 = RandPhraseSimple(RandSwear() + "�� ��� ���� ������ ��� ��������...",
                                 "������. ����� ��� �� �����.");
		link.l1.go = "sit_3";
		link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
                                 "��, ���������� ���. �����, ��� ��� ����, ������ ��������.");
		link.l2.go = "exit_sit";

		if (pchar.questTemp.piratesLine == "PL5Hunter_toFirst" && npchar.location == pchar.questTemp.piratesLine.Q5.city_1 + "_tavern")
		{
			dialog.text = "�������������, ���� ������ �� ������, �����, ��������� ���� ������ � �� �������� � ����� ��� � �����! ��, �������, ������ ����� ������?! � ����� ������� - ���������. �� ���������, � � ��� ���� �������! �! ������?! �, �� ��������, ������ �� ������, � �� ��� ��� �����. ����� ����! �����, �� ������ ���?..";
			link.l1 = "��, ��� �����...";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "3");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_1 + "Gen"));
			pchar.questTemp.piratesLine = "PL5Hunter_toFirstUsurer";
		}
		if (pchar.questTemp.piratesLine == "PL5Hunter_toSecond" && npchar.location == pchar.questTemp.piratesLine.Q5.city_2 + "_tavern")
		{
			dialog.text = "������ �� ���, ���� ���� �����, �����, ��� ���� ��� �� ������. ����� ���, ��� ��� ������... ���� ������. ���������, ��� �� ����� �������� ����������, ��-��-��. ��� ��� � ����, ��������� ����������, ����� �� ������� � ������, � ��������� �������� � ��������-�� �����...";
			link.l1 = "�� ��, ��� ���������� - ����� �������.";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "5");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_2 + "Gen"));
			pchar.questTemp.piratesLine = "PL5Hunter_toSecondUsurer";
		}
		if (pchar.questTemp.piratesLine == "PL5Hunter_toThird" && npchar.location == pchar.questTemp.piratesLine.Q5.city_3 + "_tavern")
		{
			dialog.text = "��� ��� ����� ��� ����� ����� ����! ���� ������ ������ ��������. ������, ���� �������, ������ ��������� �����. ����, ����! � ���� ������. ���� ��������, ���. �� ���� - ����� ����������, ���� � ������� ������� ��������. ������!";
			link.l1 = "� ���! �����...";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "7");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_3 + "Gen"));
			pchar.questTemp.piratesLine = "PPL5Hunter_toThirdUsurer";
		}

		//���, �����
		if (pchar.questTemp.Headhunter == "Rat_Tavern" && npchar.location == pchar.questTemp.Headhunter.Ratrumcity + "_tavern")
        {
			dialog.text = "(����) ������� ���������, ������� ���������, ���� �� ��������� �����... ��, ����"+ GetSexPhrase("�","���") +", ������!";
            link.l1 = "��������, ��� ��������, ��� ��� ������� � ������ �����, '��������' ����������, �������� ������ �� �����...";
            link.l1.go = "Rat_Tavern_1";
        }
		//<--���, �����

		//����� �������
		if (CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Tavern" && npchar.location == "LaVega_tavern")
        {
			dialog.text = "(����) ������� ���������, ������� ���������, ���� �� ��������� �����... ��, ����"+ GetSexPhrase("�","���") +", ������!";
            link.l1 = "��������, ��������! ��, � ��� ��� � ����, ��� ����������� �����, ������, ����������� � �� ������ �����?";
            link.l1.go = "RevengeCorsair_Tavern_1";
        }
		//<--����� �������

		if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskAlcash") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	    {
			dialog.text = "��, " + GetAddress_Form(pchar) + " ��� �� ����� ����� �����... ������ ������� � �������� �� ��������!";
			link.l1 = "� ��� ��� ��, ��������?";
			link.l1.go = "Alcogol_GenQuest_Church_2_1";
		}

		//-->������������
		if (pchar.questTemp.Slavetrader == "FindRatJamaica_H" && npchar.location == "FortOrange_tavern")
        {
			dialog.text = "(����) ������� ��� �����-������ ����������� ���. �� ������ - ������� � ���-������� ����, ������� �����-��, � �������� �����. ������ ����� ��-�����, � ������ - ������... ��� �����, ����"+ GetSexPhrase("�","���") +", �����������. ��� ��� ���, � ����?";
            link.l1 = "�� � ���� ��� ��� ��, ��� � ������ - ���� � ������. �� ��� ����� �����, �� ������ ��, ���� ���� ��� ��������, ������� ��� ������� ������ �������? ������� ������� ��� �����.";
            link.l1.go = "Jamaica_ratH_1";
        }
		if (pchar.questTemp.Slavetrader == "EscapeSlaveVillemstad_H" && npchar.location == "Villemstad_tavern")
        {
			dialog.text = "(����) � ���-�����-���� ����� �� ���� �����-���� ���, � ��-� ���-� ������ ������ � �����-�� �����... ��, �������, ����"+ GetSexPhrase("�","���") +"! � ������ ����� �� �����, ������� ��� ������� �� � ����.";
            link.l1 = "��������, ��������! ��, � ��� ��� � ����, ��� ����������� �����?";
            link.l1.go = "EscapeSlave_Villemstad_H1";
        }
		//<--������������
				
		//����������� ������, ������ ����
		if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "LetterToLucasSent" && npchar.location == "Villemstad_tavern")
        {
			dialog.text = "��, ����, ����... ��� �� � ����� ���� �� ����� �����!";
            link.l1 = "�� ��� � ��� ��������, �������? ���� �� ��� �������� �� �������.";
            link.l1.go = "Lucas_Tavern";
        }
		//����������� ������
		
		//--> ����� ���������
		if (CheckAttribute(pchar, "GenQuest.FindFugitive") && sti(NPChar.nation) == PIRATE && !CheckAttribute(npchar, "quest.fugitive"))
        {
			dialog.text = LinkRandPhrase("����� ����, ��������, ����� ����� ��� ������! ��-��!","���������� ������ ������ - � �������� ��������� ������! ��-��!","��� � ��� ������� ��� - �������, �� �������! ��-��!");
            link.l1 = "������, ������, �������... �����-�� ���, ��������, �� ��������� �� � ����� ������� ������� �� ����� "+pchar.GenQuest.FindFugitive.Name+"? �� - ��� ������ ����������. ������ ���� �������, ��� �� �������� ���� ����� ������ ����...";
            link.l1.go = "FindFugitiveHb";
        }
		//<-- ����� ���������
		
		// ��������� �����
		if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy" && npchar.location == "Portobello_tavern")
		{
			dialog.text = "� ����� ��� � ��� �������? �-��! � ����� ������ �� ������? �������� ���� ������ ������������ ������. ��������� ������������, ������, ��... ��! - � ����� ����������� �� ���������!";
            link.l1 = "�� ��! � ��� �� ���� ���������� ��� �����������?";
            link.l1.go = "trial_spy";
		}
		if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskAlcash") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	    {
			dialog.text = "��, " + GetAddress_Form(pchar) + " ��� �� ����� ����� �����... ������ ������� � �������� �� ��������!";
			link.l1 = "� ��� ��� ��, ��������?";
			link.l1.go = "Alcogol_GenQuest_Church_2_1";
		}
		//����� ����� ������ ��������
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.BlueBird.City == npchar.city && pchar.questTemp.BlueBird == "returnMoney")
		{
			Dialog.Text = BlueBurd_setTradeShip();
			link.l1 = "���, �������... ��� ��� ������ � ������?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
									"����� ��������.");
			link.l2.go = "exit";			
		}
	break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "rumours_trader":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
            if (!CheckAttribute(NPChar, "quest.repeat.rumours_trader") || NPChar.quest.repeat.rumours_trader!= 3 )
            strum = SelectRumourEx("trader", NPChar);
            else strum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
			Dialog.Text =  NPCStringReactionRepeat(strum, strum+" ��. ������ ������ �� ��������.",
                strum+" � ������ ��� ����� ��������� � �����.",RandPhraseSimple("� ���� ��� ������, ��� � ���� ��� ������� �� ������ ��������!","� ������� ������� � ��� ������� ��������� ������ �������!"),"block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(pcharrepphrase(RandSwear() + "��� ����� ���������! �� ����� � ����","���������, ����� ��� ��� ����� ����."), pcharrepphrase(""+ GetSexPhrase("���� � ����","������� ���� ����") +"! ������� �����. �� � ���� ���� ��� ������.","��� �� ����� ������ ������ ����������� ����� � �������� � �����."),
pcharrepphrase(RandSwear() +" ��� ���� ������, � � ����.","�� �����, ����� - ������."),pcharrepphrase("������ � �������, ��� � ����� ������. �����, �� ��������.","����� �������� ����. �������� � ����."),npchar, Dialog.CurrentNode);
			link.l1.go = "business";
			link.l2 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,pcharrepphrase("����, ������ ��������.",
"����� �������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"."),pcharrepphrase("��������! ������ �� �����. � ��� �����.","������� ���� ��� ������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"! �� ��������!")),NPCharRepPhrase(npchar,pcharrepphrase("������ ��������!","�� ��������, ��������."),pcharrepphrase("��! �� ��� ��� �������? ���? ���!?! �� �����, ����� ����� �������.","����� ���� ��������, � ���� ������� ���� � ������.")),NPCharRepPhrase(npchar,pcharrepphrase("���! ��� ��������!","��� ���� ����. ��������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!"),pcharrepphrase("� �� ���� ��� ��������! ������� ��� ��� � ����� �������!","�������, ����� ���������, ��� ���� �� �������. ��������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),NPCharRepPhrase(npchar,pcharrepphrase("��� � �����, �������? ��� �� � - " +GetFullName(pchar)+ "! ��������, � ����� �����.","�����, ���� ������ ��������� ��� ������, ��� � ��� ��� ����� ����."),pcharrepphrase("������ ���� �������, ��������! � ��� �����.","���"+ GetSexPhrase("","�") +" ���"+ GetSexPhrase("","�") +" ��� ������, " + GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),npchar, Dialog.CurrentNode);
			link.l2.go = "Exit";
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_capitan":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			Dialog.Text = SelectRumourEx("capitan", NPChar);
			Link.l1 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...",
                                     "��� ������.");
			Link.l1.go = "quests";
			Link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
                                     "����� ��������.");
			Link.l2.go = "exit";
			NextDiag.TempNode = "quests";
            NPChar.talk_date =  lastspeakdate();
		break;
		
		 case "rumours_landcaptain":
			Dialog.Text = SelectRumourEx("landcaptain", NPChar);
			Link.l1 = RandPhraseSimple(RandSwear() + "��� ����� ���������! ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...",
                                     "��� ������.");
			Link.l1.go = "question";
			Link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
                                     "����� ��������.");
			Link.l2.go = "exit";
			NextDiag.TempNode = "question";
            NPChar.talk_date =  lastspeakdate();
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "rumours_tavern":  // homo 03/08/06
	                PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_" + rand(22) + ".wav");

                 Dialog.Text = NPCStringReactionRepeat(LinkRandPhrase("�������� ����� �����. �� �������� 1000 ���� � �������� ���, ��� ����.",
                "���-�� � �����������. ��, ��������, 1000 ����� ������� ��� ������.",
                "� ����� ���������� ���, ��� ����. �� �� ��������� - 1000 ����, �� ������� � �� ��������."),
                "������ ��� ������ ��������. � ������ ����� ���� ��������, �� ���� �� ����.",
                "", "", "block", 1, npchar, Dialog.CurrentNode);
             
    			link.l1 = HeroStringReactionRepeat(RandPhraseSimple(RandSwear() + "������� �� ������ ��������? ��� ��, ����� ����-������ �������.",
                                         "�� ����� ������ � ���"+ GetSexPhrase("","�") +" ��� �����."), "����� ��������� � ���-������ ������.", "����� ��������� � ���-������ ������.", "����� ��������� � ���-������ ������.", npchar, Dialog.CurrentNode);
                link.l1.go = HeroStringReactionRepeat("rumours_tavern_no", "first time", "first time", "first time", npchar, Dialog.CurrentNode);//"rumours_tavern_no";
                NextDiag.CurrentNode = NextDiag.TempNode;
    			if (makeint(pchar.money) >= 1000 )
    			{
    				link.l2 = HeroStringReactionRepeat(RandPhraseSimple("�� �� ��������, ���� � ������ ������������� ������ ��������.", "� �������, �� ������ ��� �������, ��� �� ��� ���������� ������������� ���-�� ������."),
                     "", "", "" , npchar, Dialog.CurrentNode);
    				link.l2.go = HeroStringReactionRepeat("rumours_tavern_yes", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
    			}
    			else
    			{
                    link.l2 =  HeroStringReactionRepeat("� ���� ��� ����� �����.", "", "", "", npchar, Dialog.CurrentNode);
    				link.l2.go = HeroStringReactionRepeat("rumours_tavern_no", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
    			}

		break;
		
		// ������� ����� �������
		case "rumours_tavern_yes":

			//------------- ��������� ����� ���������� --------->>>>>>>>

		//����� ����� ������ ��������
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.BlueBird.City == npchar.city && pchar.questTemp.BlueBird == "returnMoney")
		{
			Dialog.Text = BlueBurd_setTradeShip();
			link.l1 = "���, �������... ��� ��� ������ � ������?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
									"����� ��������.");
			link.l2.go = "exit";
			//����� ���� � ������ ������
			//pchar.questTemp.BlueBird.City = GetSharpCity();
			break;
		}

			//�������, ����� �3
			if (pchar.questTemp.piratesLine == "KillLoy_toCumana")
			{
				Dialog.Text =  "� ��������� ����� ����� ����� ��������� �������, ������, ��� �������, ��������� ������ ���������� ������� � �����, ��������� �������, � �����. �� ���� 5-�� ������. ������������ � ��������� � ����� ������ ������-�� �����... ��� ��� ������ ���������!";
				link.l1 = "�� ���� 5-�� ������, ��������? ����� ���������... � ������ ������ ��������������� �� ������?";
				link.l1.go = "rumours_tavern";
				AddQuestRecord("Pir_Line_3_KillLoy", "14");		
				AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","�"));		
				pchar.questTemp.piratesLine = "KillLoy_toCumana_2";
				break;
			}
			//���, ����� �� �������
			if (pchar.questTemp.Headhunter == "Rat_tortuga" && npchar.location == "Tortuga_tavern")
			{
				Dialog.Text =  "�������, ������� � ����������� ������ '��������' �������� �����-�� ������ � ������������ � ���������� ��������� �� ����. ��� ��� ������� ����� ������ ��� ������� �������������� � ������� � � ���� � �������. ����� ����, �������� �������, ������� ��... � ��� ������� ������ � ���� �������� - ������, ��� �����, �� ������� ��������. ������ �����...";
				link.l1 = "����� ���������... � ������ ������ ��������������� �� ������?";
				link.l1.go = "rumours_tavern";
				pchar.quest.Headhunter_PinasseTortugaOver.over = "yes";
				AddQuestRecord("Headhunt", "17");
				CreateRatOfficer();	
				pchar.questTemp.Headhunter = "Rat_officer";
				FreeSitLocator("Tortuga_tavern", "sit1");
				SetFunctionTimerCondition("Headhunter_RatOfficerOver", 0, 0, 3, false);//������
				break;
			}
			//���, ����� �� �������
			//<<<<<-------- ��������� ����� ���������� -----------------


			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation"))
			{
				bool bOk = (pchar.questTemp.Saga.BarbTemptation == "silk") || (pchar.questTemp.Saga.BarbTemptation == "give_silk");
				if (bOk && npchar.location == "Marigo_tavern" && !CheckAttribute(npchar, "quest.barbtemptation"))
				{
					AddMoneyToCharacter(pchar, -1000);
					Dialog.Text =  "������� ��� ������� ������� ���������� ������ ������������ �������������� ������, � ������ ��� ���� � ����. ������ ���� ������ ����� �������� � ���������� ����. ��������� ������, ��� �� ������� ��� �� ���� ���� �����������, � �������� ������� ���. � ��� ������ ������ - ��� � ����� �����������...";
					link.l1 = "����� ���������... ������, �� �������� ���� ������ - �����. � ������ ������ ��������������� �� ������?";
					link.l1.go = "rumours_tavern";
					Saga_CreateMorelle(); //������ ������
					npchar.quest.barbtemptation = "true";
					pchar.questTemp.Saga.BarbTemptation.Prison = "true";
					break;
				}
			}
			// Addon-2016 Jason ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_portobello" && npchar.location == "portobello_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "������� � �������������� ������ ������ �������� ���. �������� ��� ������ �� ������, ������� ���� ��� ���������. � ������� �������� �� ����� � ���� � ���������, ������ ��� ������� �������, ������� �� ���� ������� ������������ ����������. ���� ������� ��� �� ��������, ���, �������, � ��������: ���������� �����, ���� ����, ������� �� ������ � ��������� �������� � ��������� ����������� ������ '�����'. � ����� ���� ��������� ��������� ��� ��������. ������ �������� ��������, �� ����� ��� ��� ����. ���-��!";
				link.l1 = "����� ���������... ������, �� �������� ���� ������ - �����. � ������ ������ ��������������� �� ������?";
				link.l1.go = "rumours_tavern";
				pchar.questTemp.FMQG = "headhunter_juan";
				AddQuestRecord("FMQ_Guadeloupe", "10");
				pchar.quest.FMQG_Juanship.win_condition.l1 = "location";
				pchar.quest.FMQG_Juanship.win_condition.l1.location = "PortoBello";
				pchar.quest.FMQG_Juanship.function = "FMQG_CreateJuanship";
				break;
			}	
			// Addon-2016 Jason ���-����-���������
			if (CheckAttribute(pchar, "questTemp.FMQN") && pchar.questTemp.FMQN == "town" && npchar.location == "Marigo_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "��� ��������� ������ �������������� � �������� � ������ � ������. ������ ����, ��� ��������� ���������� ���������� � ���������� � �������� �� ������ ������� ��������.";
				link.l1 = "�� ��? ������� ��������� ������� �� �����?.. � ��� ��� �� ������� - �� ������?";
				link.l1.go = "FMQN_r";
				break;
			}

			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_3" && npchar.location == "Havana_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "� ��� ��� �� ���� ���� ����� ����������� ���. ������ � ������� ����� �������� � ������� � ���� � �������, � ����� ���� ���� �� ���������� �������� ���������, � �� ����, ����������� ���� ����, ����� � ������� ���������� ������. � ��� ��� ����������� ��� ������ ����������� ��������� ������! ����� ������ ���� �� ������� - ������ ���� �������. ������� ����� �������������� � �������� � ������ �������, ���� ���� ������� ������ ���� ����������\n�� ������� ����������� - � ��� �� �� ������? - ������� � ����������� �����. �������� ���� �� ��������, �� �� ����� ��������� � �������� �� ����� �������. ��������� � �������� ������ ������ ��� ����, �� ������������ - ��������� ���������, ��������� � ��� ��������� ���� ����� �� ������ � ������ ��� ����� ���������� �������. ������� �������� ��������\n������������, ��� �������� ���������� ������� ���� �� ����� � ������ ����� � ����, � ����� ��� �������� �� � ������ ����� ������, �� ������� �����, ������� ��������, �������� ��������� �����: �����, ��� �������� ��� ������, �� ���������� ��������� ������� � �������� �� �����. ������ ������� � ������, ��� ��� ����� �����, � �������� ��� ��� ������ �������. � ����� ���, �������, ��������� � �������, ����� ������ ��������� ����.";
				link.l1 = "��� �� ������? ������� ������� ��������? ��... ����������� �������!.. ������, �� �������� ���� ������ - �����. � ������ ������ ��������������� �� ������?";
				link.l1.go = "rumours_tavern";
				Mtraxx_CreateOfficer(); // ������ �������-�������
				pchar.questTemp.Mtraxx = "jewelry_4";
				pchar.GenQuest.PrisonQuestLock = "true";
				AddQuestRecord("Roger_1", "7");
				break;
			}	
			
            string RumText = SelectRumourEx("tavern", NPChar); //fix
           
		    if(!RumourHasInformation(RumText))
            {
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; //fix
                link.l1 = RandPhraseSimple("� �� ����� ������� �� ������ �������, ������.", "���� �������� �� ����� � �������� ����� - �� ������ �� ��������.");

			    link.l1.go = "Exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
            }
            else
            {
                AddMoneyToCharacter(pchar, -1000);
                Dialog.Text = RumText;
    			link.l1 = RandPhraseSimple("���������, ��� ���� ������. � ������ ������ �� ����������?", "������, �� �������� ���� ������ - �����. ���� ���-������ ���?");
    			link.l1.go = "rumours_tavern";
    			NextDiag.CurrentNode = NextDiag.TempNode;    
            }
		break;

		case "rumours_tavern_no":
			Dialog.Text = "������� ���� ���������, ��� ����� ������� �����.";
            link.l1 = "����� ��������� � ���-������ ������.";
			link.l1.go = "first time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			link.l2 = LinkRandPhrase("�������, ����"+ GetSexPhrase("��","��") +" �����������.",
                                     "����� ��������","�� ��������.");
			link.l2.go = "Exit";
		break;	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_poor":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			if (!CheckAttribute(NPChar, "quest.repeat.rumours_poor") || NPChar.quest.repeat.rumours_poor <= 1)
			{
				Dialog.Text = SelectRumourEx("poor", NPChar);
				Link.l1 = RandPhraseSimple(RandSwear() + "��, ��� ���������. ������� ��� ������...",
										"��, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
				Link.l1.go = "rumours_poor_2";
				Link.l2 = RandPhraseSimple("��, ������, ������.",
										"����� ��������, ��������.");
				Link.l2.go = "exit";
				NPChar.quest.repeat.rumours_poor = sti(NPChar.quest.repeat.rumours_poor) + 1;
			}
			else 
			{
				Dialog.Text = RandPhraseSimple("�� � ��� ��������, ��� ��� ��������, ��� ����.", 
					"������ � ������ �� ������, ��������...");
				Link.l1 = RandPhraseSimple("�������. �� ��� ��, ����� ��������.",
										"����. ��, �����, ��������...");
				Link.l1.go = "exit";			
			}
            NPChar.talk_date = lastspeakdate();
		break;
        case "rumours_poor_2":
			if (NPChar.quest.repeat.rumours_poor <= 1)
			{
				Dialog.Text = SelectRumourEx("poor", NPChar);
				Link.l1 = RandPhraseSimple(RandSwear() + "��, ��� ���������. ������� ��� ������...",
										"��, ��� ��� ��� �����"+ GetSexPhrase("","�") +" ��������...");
				Link.l1.go = "rumours_poor";
				Link.l2 = RandPhraseSimple("��, ������, ������.",
										"����� ��������, ��������.");
				Link.l2.go = "exit";
				NPChar.quest.repeat.rumours_poor = sti(NPChar.quest.repeat.rumours_poor) + 1;
			}
			else 
			{
				Dialog.Text = RandPhraseSimple("�� � ��� ��������, ��� ��� ��������, ��� ����.", 
					"������ � ������ �� ������, ��������...");
				Link.l1 = RandPhraseSimple("�������. �� ��� ��, ����� ��������.",
										"����. ��, �����, ��������...");
				Link.l1.go = "exit";			
			}
			NPChar.talk_date = lastspeakdate();
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_LSC":
			if (CheckNPCQuestDate(NPChar, "quest.repeat.rumours"))
			{
				Dialog.Text = SelectRumourExSpecial("LSC", NPChar);
				Link.l1 = RandPhraseSimple("�������...",
										"����...");
				Link.l1.go = "exit";
				SetNPCQuestDate(NPChar, "quest.repeat.rumours");
			}
			else  
			{
				Dialog.Text = NPCharSexPhrase(npchar, RandPhraseSimple("�� � ��� ��������, ��� ��� ��������, ��� ����.", "������ � ������ �� ������, ����� ��������..."), 
					RandPhraseSimple("��������, �� � ��� ��� ��� ���������.", "������ � ������ �� �������, ��������..."));
				Link.l1 = RandPhraseSimple("� �����"+ GetSexPhrase("","�") +".", "��, ����� ��������.");
				Link.l1.go = "exit";			
			}
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_LSCC":
 	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			if (CheckNPCQuestDate(NPChar, "quest.repeat.rumours"))
			{
				Dialog.Text = SelectRumourExSpecial("LSCC", NPChar);
				Link.l1 = RandPhraseSimple("�������...",
										"����...");
				Link.l1.go = "exit";
				SetNPCQuestDate(NPChar, "quest.repeat.rumours");
			}
			else  
			{
				Dialog.Text = NPCharSexPhrase(npchar, RandPhraseSimple("�� � ��� ��������, ��� ��� ��������, ��� ����.", "������ � ������ �� ������, ����� ��������..."), 
					RandPhraseSimple("��������, �� � ��� ��� ��� ���������.", "������ � ������ �� �������, ��������..."));
				Link.l1 = RandPhraseSimple("� �����"+ GetSexPhrase("","�") +".", "��, ����� ��������.");
				Link.l1.go = "exit";			
			}
		break;
		
//Jason -------------����� ����������� ������, ��������� �������, �� ���������, �� 1 �� �� ����--------------------
		case "rumours_lighthouse": 
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			Dialog.Text = NPCStringReactionRepeat(RandPhraseSimple("�� �������! � ������ ��� ���������. ������, ����� ������ ������ ������ ��� ������...", "� ���� ����� ����, ����� �� ��� ������� �������. ��� ��� ������������� ����� ���� � ���-������ ��� ���� ������ - �������."), "������ ���������, �������? ��, ����� ��� ��� �������...", "���������� ��� �� ��� - ������������ ������� ����. ��� �������� ��� ������ ����� ������...", "� ���������, � ��������� ���, ��� ����. ������ ��� ������ ��������.", "block", 1, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("��, ����� �������� ����� �����������. �, ������ ��, ���� ������� ���������...", "�����������! ��� ������� ����������� - ��� ������� �����, ��� ���� �������?"), "��������?", "�����������! ��, ����������, ��� ��� ������?", "�� � �����, �� � ��� ������� ���������." , npchar, Dialog.CurrentNode);
    		link.l1.go = HeroStringReactionRepeat("rumours_lighthouse_yes", "rumours_lighthouse_void", "rumours_lighthouse_void", "exit", npchar, Dialog.CurrentNode);
		break;
		
		case "rumours_lighthouse_yes":
            RumText = SelectRumourEx("tavern", NPChar);
		    if(!RumourHasInformation(RumText))
            {
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)];
                link.l1 = RandPhraseSimple("���������! ���-������ ��� ������?", "����� ���������! ������ ������ �� ����������?");

			    link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("���������! ������ �������...", "������� �� ����������!");
			    link.l2.go = "exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
            }
            else
            {
                Dialog.Text = RumText;
    			link.l1 = RandPhraseSimple("���������! ������ ������������... ���-������ ��� ������?", "����� ���������! � ������ ������ �� ����������?");
    			link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("���������! ������ �������...", "������� �� ���������� �������!");
			    link.l2.go = "exit";
    			NextDiag.CurrentNode = NextDiag.TempNode;    
            }
		break;
		
		case "rumours_lighthouse_void":
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)];
                link.l1 = RandPhraseSimple("���������! ���-������ ��� ������?", "����� ���������! ������ ������ �� ����������?");

			    link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("���������! ������ �������...", "������� �� ���������� �������!");
			    link.l2.go = "exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
		break;
//Jason ------------------------------------�������� ��������� 2 ������-------------------------------------------
		case "Postcureer_LevelUp_ForAll":
			//�������� ���������
			if (!CheckCharacterItem(pchar, pchar.questTemp.WPU.Current.Item))
			{
				dialog.text = "�� ��� �� �����? � ��� ��� ���?";
	        	link.l1 = "�-�... � ������ ��� ��� ��� ���������. �� � ���� ��� ��������... ���� ������� - ������. � �� ���� ������������� ���������� � ����� �� �����. ";
	        	link.l1.go = "Postcureer_LevelUp_complete_fail";
				break;
			}
			
			if (sti(pchar.questTemp.WPU.Postcureer.AgentChance) == 4)//�������� �����
			{
				dialog.text = "��. ���������, �� ���� ����� ��� ���������! � ��� ���������� ����� ����. ������ ���������� ��������...";
	        	link.l1 = "" + GetAddress_FormToNPC(NPChar) + ", � ������ ��� ����� � ��� ����, � ������� ������� ��� � �������� ����������  " +XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+ ", � �� ���� �� ��������� �������...";
	        	link.l1.go = "Postcureer_LevelUp_complete_Agentfail";
				break;
			}
			
			if (pchar.questTemp.WPU.Postcureer == "late")//��������
			{
				int iTime = makeint(GetQuestPastDayParam("questTemp.Postcureer.Late"))+1;
				pchar.questTemp.WPU.Postcureer.Money = makeint(sti(pchar.questTemp.WPU.Postcureer.Money)/(sti(iTime)+1));//������ ������� ������
				dialog.text = "� ���� ���. �� �� �������� �� " + FindRussianDaysString(iTime)+ "! ����������, ������������ � ���� ���������, ��� ����������� �������� ���� ������������... �� ������ �� ��� ���-���� ���� - ������� � ������� ��� �� ������, ����, �������, ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ". ����������, �������� ���� ������ � ��������.";
	        	link.l1 = "������� � �� ����.";
	        	link.l1.go = "Postcureer_LevelUp_complete";
				pchar.quest.PostcureerTime_FullOver.over = "yes";//����� ������ ������
				pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-1;//���������� ���� �� �����������
				AddQuestRecord("Postcureer", "8");
				AddQuestUserData("Postcureer", "sDay", FindRussianDaysString(iTime));
				AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)));
				break;
			}
			
			if (pchar.questTemp.WPU.Postcureer == "lost")//�������� ������
			{
				dialog.text = "��� ��� ��! � � ��� ��� �� ����, ��� � ���� ��������������� � ��� ����� ������ - ������ ��, ��������� �� ������ ����������� �����. ������� ���� �����. ���� �� ��� ��� � �� ����� - ��������� ������ ���������, ����������, ������������ ���, ��� ��� ���� �� ���������� - �� ���-���� ����� �� ����� � ����\n��� �� ���������, ������ �� �������� �� �����. ������������, ��� � ������ - ����� ����, ����� ������������ ���� ������ ���.";
	        	link.l1 = "������� � �� ����. �������� �� ���������, ��� ������������� ����, ��� ��� �����. ����� �������.";
	        	link.l1.go = "Postcureer_LevelUp_complete_bad";
				break;
			}
			dialog.text = "� ���� ���. �� ������� ������� - ����������, ������� �� ��������, ����� ����� ������. ��������, ����������, ���� ������ �� ����� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ". ��������� �� �������������.";
        	link.l1 = "� ��� �������. �� ��������!";
        	link.l1.go = "Postcureer_LevelUp_complete";
			pchar.quest.PostcureerTime_Over.over = "yes";//����� ������
			AddQuestRecord("Postcureer", "10");
		break;
		
		case "Postcureer_LevelUp_complete":
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Postcureer.Money));
			CloseQuestHeader("Postcureer");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
			AddCharacterExpToSkill(pchar, "Sailing", 120);//���������
			AddCharacterExpToSkill(pchar, "Sneak", 120);//����������
			AddCharacterExpToSkill(pchar, "Leadership", 150);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 150);//�������
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), 2);
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
		
		case "Postcureer_LevelUp_complete_bad":
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddQuestRecord("Postcureer", "9");
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", 10);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), 33);
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
			DialogExit();
		break;
		
		case "Postcureer_LevelUp_complete_fail":
			dialog.text = "��, � ��� � ����, ��� �� ���� ��������... ���� ���� �������� ������ �������� ����������� �����, � �� ���������� �� ����������� ���������... �����, " + GetAddress_Form(NPChar) + ", ���� �� ��� ������ - �� ���� ���-���� �� ������. ��������.";
			link.l1 = "�� ��������, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			if (pchar.questTemp.WPU.Postcureer == "begin") pchar.quest.PostcureerTime_Over.over = "yes";//����� ������
			if (pchar.questTemp.WPU.Postcureer == "late") pchar.quest.PostcureerTime_FullOver.over = "yes";//����� ������ ������
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), -2);
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-3;//������� �������
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
		break;
		
		case "Postcureer_LevelUp_complete_Agentfail":
			dialog.text = "������, � ����� ���� ���������� ����� " +XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+ ", ��� ���������� �������. �� � �� � ���� ��� ���� ��������� ��� ��������. " + GetAddress_Form(NPChar) + ", �� - ��������! � �� ������� ������ ������� ���. ����������!";
			link.l1 = "���-�...";
			link.l1.go = "Postcureer_LevelUp_complete_Agentfail_1";
		break;
		
		case "Postcureer_LevelUp_complete_Agentfail_1":
			if (pchar.questTemp.WPU.Postcureer == "begin") pchar.quest.PostcureerTime_Over.over = "yes";//����� ������
			if (pchar.questTemp.WPU.Postcureer == "late") pchar.quest.PostcureerTime_FullOver.over = "yes";//����� ������ ������
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddQuestRecord("Postcureer", "17");
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), -2);
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-3;//������� �������
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.AgentChance");
			pchar.questTemp.WPU.Postcureer = "complete";
			DialogExit();
		break;
		
// <--�������� ��������� 2 ������

//Jason --> ---------------------------------��������� ����������� ���--------------------------------------------
		case "Device_Common":
			dialog.text = "�� ��� - ���������-����������, ������, �����, ��� ���������. � ���� ����� - ������� �� ����, ��� ������� ���� �� ��� ������-�������. ���� ����-��, � ���� - ��� ��� �����.";
			link.l1 = "��� �����-�� ���������� - ��� �����, ��� ������. �������! ������ ��� ������!";
			link.l1.go = "Device_Common_1";
		break;
		
		case "Device_Common_1":
			string sNation = pchar.GenQuest.Device.Shipyarder.Nation;
			sld = GetCharacter(NPC_GenerateCharacter("Device_poorman", "panhandler_"+(rand(5)+1), "man", "man", sti(pchar.rank)+5, sNation, 20, true, "quest"));
			SetFantomParamFromRank(sld, sti(pchar.rank)+5, true);         
			GiveItem2Character(sld, "slave_02");
			EquipCharacterbyItem(sld, "slave_02");
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, sNation+"_CITIZENS");
			sld.Dialog.Filename = "Quest\Other_Quests_NPC.c"; 
			sld.dialog.currentnode = "Device_poorman"; 
			sld.greeting = "Gr_poorman";
			switch (sti(pchar.GenQuest.Device.Shipyarder.Chance2))
			{
				case 0://� ������
					sld = characterFromId("Device_poorman");
					GetCharacterPos(pchar, &locx, &locy, &locz);
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.City +"_town", "goto", LAi_FindFarLocator("goto", locx, locy, locz));
				break;
				case 1://�� ��������
					sld = characterFromId("Device_poorman");
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.City + "_ExitTown", "goto", "goto1");
				break;
				case 2://� �����
					sld = characterFromId("Device_poorman");
					pchar.GenQuest.Device.Shipyarder.Shore = SelectQuestShoreLocation();
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Shore, "goto", "goto1");
				break;
				case 3://� ����
					sld = characterFromId("Device_poorman");
					pchar.GenQuest.Device.Shipyarder.Location = GetDeviceLocation(npchar); //���������� �������
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Location, "goto", "goto1");
					if (pchar.GenQuest.Device.Shipyarder.Location == "none" || CheckAttribute(pchar, "GenQuest.SeekSpy.Location"))//���� ����� ���� ��� ���� ����� ������
					{
						pchar.GenQuest.Device.Shipyarder.Shore = SelectQuestShoreLocation();
						ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Shore, "goto", "goto1");
					}
				break;
			}
			pchar.GenQuest.Device.Shipyarder = "inSeek";
			DialogExit();
			AddQuestRecord("Device", "9");
		break;
		//<-- ��������� ����������� ���
		
		// Addon-2016 Jason ���-����-���������
		case "FMQN_r":
			Dialog.Text =  "�� �� ��� ����� � ������� ����-�������� ��������� ���������� �������, � �� ��� ���� ��������� ������������������ �������. �� ������ ��������� � ����������, �� �������� ��������� � ������. ������������, ��� ������� ������ � ���� ����� � ����� �� ������� ��������� ����������, ��� ��������� ������������ �������� ������������ ������ � ������������ ����� �����������. ���� ���� � ��� ����� ���. ��� � ������ ��� ������ ���������. ���� ���� �������� ����� ������ ����� - ���, ��� ���� ����, ��������� � �������. ���-��!";
			link.l1 = "����� ���������... ������, �� �������� ���� ������ - �����. � ������ ������ ��������������� �� ������?";
			link.l1.go = "rumours_tavern";
			pchar.questTemp.FMQN = "governor";
			pchar.quest.FMQN_governor.win_condition.l1 = "location";
			pchar.quest.FMQN_governor.win_condition.l1.location = "Marigo_town";
			pchar.quest.FMQN_governor.function = "FMQN_ToGovernor";
			if (Whr_IsDay()) AddDialogExitQuest("FMQN_GetRumoursDay");
			else AddDialogExitQuest("FMQN_GetRumoursNight");
		break;
		
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		������ ����, ������������� �� ���������� �����
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "IntelligenceForAll":
            Dialog.Text = RandPhraseSimple("�� ��� ��, ����� ������. � ���� ����� ��� ��� �����, ������� ��� �������� ��������� ���������� ���� ����� � ����. �������� ��������.\n�� ��������� �� ��� ������ � �� ������������� �� ����, ��� ����� ���� ��������������. ���������� ������������...", 
				"��, ���������. � ������ ��� �����, � �������, ��� �� ������ ���� ��������� ���������� ���� ���� ����� � ����.\n������ �������� � �� ��������� �� ��� ����� - ��� ������.");
            link.l1 = RandPhraseSimple("� �����"+ GetSexPhrase("","�") +". ��������...", "�������� � �����.");
			link.l1.go = "exit";
			pchar.GenQuest.Intelligence = "Execute";
			GiveItem2Character(pchar, "sicretLetter");
			AddCharacterExpToSkill(pchar, "Sneak", 200);
			ref rItem = ItemsFromID("sicretLetter");
			rItem.City = XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.Intelligence.MayorId)].city+"Gen")); 
			rItem.Mayor = GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)); 
			AddQuestRecord("MayorsQuestsList", "7");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.Intelligence.MayorId)].city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Dat"));
			AddQuestUserData("MayorsQuestsList", "sWho", GetWorkTypeOfMan(&characters[GetCharacterIndex(pchar.GenQuest.Intelligence.SpyId)], "Gen"));
			AddQuestUserData("MayorsQuestsList", "SpyName", GetFullName(&characters[GetCharacterIndex(pchar.GenQuest.Intelligence.SpyId)]));			
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		����� ���������, ��������� ������
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "AscoldTrader": //��������� ������ ������
            dialog.Text = "��������, �� ��������"+ GetSexPhrase("","�") +" ��� ������� �����, ������� � ������ ���� ���������?";
            if (GetQuestPastDayParam("questTemp.Ascold") > 3)
			{
				Link.l1 = "���, ���� �� ��������"+ GetSexPhrase("","�") +"... ��������, � ��������� �� ������ ��, �������, ����, �� ���-�� ��� ������...";
            	Link.l1.go = "AscoldTrader_6";
			}
			else
			{
				Link.l1 = "���, ���� �� ��������"+ GetSexPhrase("","�") +"... �� � �������� ������.";
            	Link.l1.go = "quests";
			}
		break;
        case "AscoldTrader_WasSeek":
            dialog.Text = "��������, �� ��������"+ GetSexPhrase("","�") +" ��� ������� �����, ������� � ������ ���� ���������?";
            Link.l2 = "��, ���"+ GetSexPhrase("��","��") +". � ������� �� ��� �� ���� ���������?";
            Link.l2.go = "AscoldTrader_1";
        break;		
		case "AscoldTrader_1":
        	dialog.text = "� - ���������. �� � ����, ��� ����� � ���� ���.";
    		link.l1 = "��, � �����������"+ GetSexPhrase("","�") +" �� ��������� ����� ����� ������.";
    		link.l1.go = "AscoldTrader_2";
		break;
 		case "AscoldTrader_2":
        	dialog.text = "�������, �� �� ���������� � �������. ������ �����������.\n"+
                          "�� ��������� � ������ ��� ��� ����� ���� �������� ��� - �������.";
            if (Characters[GetCharacterIndex("Ascold")].quest.meeting == "0")
            {
                link.l1 = "������� �������� - ���� ���...";
                link.l1.go = "AscoldTrader_4";
            }
            else
            {
                link.l1 = "���� � ���, �������� ����������. ������, ����� ��������...";
                link.l1.go = "AscoldTrader_3";
            }
		break;
 		case "AscoldTrader_3":
        	dialog.text = "� ��� ���������? �������"+ GetSexPhrase("","�") +" �� ���� ��� ������ ����?";
    		link.l1 = "�� ��, �� ������ �������� ���� �� �����, ��� "+ GetSexPhrase("���������","��������") +"!";
    		link.l1.go = "AscoldTrader_4";
		break;
 		case "AscoldTrader_4":
        	dialog.text = "������� ������� ��������, �� ������� �� �������, �������. �� ������ - ��������, ���� ����� �����, ������� ����� �� ������ ������� �����, ��� ������� ��� ����, � ������ ���� ���� �� �������. ������ � �������� �������, � ���� � ����� ������ �� �������� ����������� ��������.\n"+
                          "��� � ����� �� �������� �����, � ����� �� ����, ��� � �� ����, ��� �� ����������.\n"+
                          "�� ��� �� ��������, ��� ��� � ���� � ��� �������� ����.\n"+
                          "��� ��� ������� � ����, �������������, �������, ��� �� ���� - � ��� ����� � �������. ����� �� � ���� ��� �����, ��� ��� ��� ��� �����.";
    		link.l1 = "� ���� � ����� ����� �����?";
    		link.l1.go = "AscoldTrader_5";
		break;
 		case "AscoldTrader_5":
        	dialog.text = "�� ���� �� ���������, � ������ ������ ����� ������������ �� ����� � ��� ������� ��������.";
    		link.l1 = "�������. ��� �, �������, ������� � ������ �������� ��� ������.";
    		link.l1.go = "exit";
    	    pchar.questTemp.Ascold = "GoToAscold";
    	    QuestSetCurrentNode("Ascold", "HaveRecomendation");
            AddQuestRecord("Ascold", "2");
		break;
 		case "AscoldTrader_6":
        	dialog.text = "������, � ����������� ��������?";
    		link.l1 = "�����, ��������...";
    		link.l1.go = "AscoldTrader_7";
		break;
 		case "AscoldTrader_7":
        	dialog.text = "�� � ��� �� �����"+ GetSexPhrase("","�") +"?.. ��� ��� � ���� �����, "+ GetSexPhrase("��������","�������") +": ������� ���� � ���. �� � ����, �������, �� � ����-�� ����� �� �������. ������� �� ���� ����������� � ���� - � � ����� ��������� ������.";
    		link.l1 = "���, �� ��� ��, ������� �� ������.";
    		link.l1.go = "quests";
			SaveCurrentQuestDateParam("questTemp.Ascold");
		break;

        //==> ����� ������ ��� ������ �����, ����� ����.
		case "AzzyTryTalk":
			dialog.Text = NPCStringReactionRepeat("����� ��������� �� ���� ��������. �-�-�, ���. �� �������� �� ���, ��� ������ ������� ��������� ����������, �� ����� ��� ����������. ������� ���� ������� ��� ���� � �������, ��� ����������, ��� � ��� ������.", "none", "none", "none", "block", 0, npchar, Dialog.CurrentNode);
  			Link.l1 = HeroStringReactionRepeat("������� �� ������ �����.", "none", "none", "none", npchar, Dialog.CurrentNode);
			Link.l1.go = "Exit";
		break;

		case "AggryHelp":
			dialog.Text = NPCStringReactionRepeat("��� ��� �� ����� ����� ����������: �������� �����, ������� �� �������, ������� ��� ����� � ������. ���� � �������� ���"+ GetSexPhrase("","�") +", � ����� ��� �� ����.", "none", "none", "none", "block", 0, npchar, Dialog.CurrentNode);
			Link.l10 = HeroStringReactionRepeat("�������, " + npchar.name + ".", "none", "none", "none", npchar, Dialog.CurrentNode);
			Link.l10.go = "exit";
			items[GetItemIndex("Azzy_bottle")].shown = 0; //���� ����������� ������� �����

		break;

		//==> ����� ������ ��� ������, ����� ����.
        case "GiveLamp":
			dialog.text = "�� ��������� ��������"+ GetSexPhrase(", ��� ���","�, ���� ���") +". ����������, ��� ��� ������, �� �� ����� �����, ��� ������ ������� ����� ����� �������� ������.\n"+
                          "� �� ���� ����������, ��� �� ��� ����"+ GetSexPhrase("","�") +". ������ ��������� ������ ���� ����� ����! ��� � �����.";
			link.l1 = "�������, ������ ����.";
			link.l1.go = "exit";
            ChangeCharacterReputation(pchar, 100);
            TakeItemFromCharacter(pchar, "Azzy_bottle");
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		������� ������� �������� �������� ISS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "ISS_deposit":
			dialog.text = NPCStringReactionRepeat("���������� �����. ���� ������� �������� �� ������ �������� ����� ������ ����� ��������� ���� �������������.", 
				"� ��� ������� ���, " + GetAddress_Form(NPChar) + ", ��� ������� � ����. � ��� ������������� �� ��� ������.", 
				"��� �� ����� ������������. ������� ��������� � ����, � ��� ������ ������������� �� ��� ������.",
				"��, ��� �������, �� ��������� ����������� ���� ���������. ��� ��������� ����������, ������� � ���� ������ ��������� ����� ���������. ������� �� ���� ��� ��������� � ����, �������� �� ��� ������� ����� ������������� �� ������.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������. �� ��� ��, ���������. � �����"+ GetSexPhrase("","�") +" ��, ��� �����"+ GetSexPhrase("","�") +".", 
				"���, �������...",
				"� � �� ���������� �����.", 
				"�������... ������� ���, " + GetAddress_Form(NPChar) + ".", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		case "ISS_takeDeposit":
			dialog.text = "��-��, � ������� ���������� �������� ��� ���������� ��������. �������� ��������, " + GetAddress_Form(NPChar) + ".";
			link.l1 = "��-��, ����� ������...";
			link.l1.go = "ISS_takeDeposit_1";
			AddMoneyToCharacter(pchar, 1000000);
			CloseQuestHeader("ISS_PoorsMurder");
		break;
		case "ISS_takeDeposit_1":
			dialog.text = "���� �����, �� ������ ������� ��� ������ � ����? � ������ � ����� �������, ��� ���������...";
			link.l1 = "� �����"+ GetSexPhrase("","�") +" ���, �������. � �������.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "over"; //����� ������� ���
			CloseQuestHeader("ISS_PoorsMurder");
		break;
		//�������� ����������, ������� ������
		case "MechanicIsPrison_man":
			dialog.text = "�-�, �� ��� � ��, �������...";
			link.l1 = "� ��� ����? ������ �� ��� �� �� ��������� ���?... � ��� �������?";
			link.l1.go = "MechanicIsPrison_man_1";
		break;
		case "MechanicIsPrison_man_1":
			dialog.text = "��� �� ������ � �� ����. ����� � ����"+ NPCharSexPhrase(NPChar, "��","��") +" �� '��� ��������', ��� ��� ��� �������� �����������. ���� �� �����, �� ���������, � ������� ��� ��� ������ �������.";
			link.l1 = "��������!!! ��� �� ������ ������?";
			link.l1.go = "MechanicIsPrison_man_2";
		break;
		case "MechanicIsPrison_man_2":
			dialog.text = "� ��� �������� ��� �� ��������?";
			link.l1 = "������� ��� �����. �� ��������� ��� �� ������� ������, � ��� ���������� ��� ��� ������� �� ������.";
			link.l1.go = "MechanicIsPrison_man_3";
		break;
		case "MechanicIsPrison_man_3":
			dialog.text = "����� ����� ���� � ���������� � �������, �������� ��������. �, � ���������, ��� � ���� ���� - ������� ������� �� ���� ���� ����� ����� �����...";
			link.l1 = "���, ��� � �������... ������������� �� ��������� ���, � ����� ������� � ���������. ��������� ����� �������, ���� �� �����, ��� ���.";
			link.l1.go = "MechanicIsPrison_man_4";
		break;
		case "MechanicIsPrison_man_4":
			dialog.text = "��� �������, �������.";
			link.l1 = "�� ��������� ��� ��� ����. ��� ����� ������.";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.questTemp.LSCC = "MechanicIsArrest_toResidence";
			SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
			bDisableFastReload = true; 
			AddQuestRecord("ISS_MainLine", "64");
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1 = "location";
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1.location = "SanAugustineResidencee";
			pchar.quest.LSCC_fightEnterResidence.function = "LSCC_fightEnterResidence";
		break;
		//�������� ����������, ������� ����
		case "MechanicIsPrison_woman":
			dialog.text = "�-�, �� ��� � ��, �������...";
			link.l1 = "� ��� ����? ������ �� ��� �� �� ��������� ����?... � ��� �������?";
			link.l1.go = "MechanicIsPrison_man_1";
		break;
		case "MechanicIsPrison_woman_1":
			dialog.text = "��� �� ������ � �� ����. ����� � ������ �� '��� ��������', ��� ��� ��� �������� �����������. ���� �� �����, �� ���������, � ������� ��� ��� ������ �������.";
			link.l1 = "��������!!! ��� �� ������ ������?";
			link.l1.go = "MechanicIsPrison_woman_2";
		break;
		case "MechanicIsPrison_woman_2":
			dialog.text = "� ��� �������� ��� �� ��������?";
			link.l1 = "������� ��� �����. �� ������ �� ������� ������, � ��� ���������� ��� ��� ������� �� ������.";
			link.l1.go = "MechanicIsPrison_man_3";
		break;
		case "MMechanicIsPrison_woman_3":
			dialog.text = "����� ����� ���� � ���������� � �������, �������� ��������. �, ��� �������, ������ � ���� ���� ��� �� �����, � ���������.";
			link.l1 = "��� �����... ������������� �� ��������� ���, � ����� ������� � ���������. ��������� ����� �������, ���� �� �����, ��� ���.";
			link.l1.go = "MechanicIsPrison_man_4";
		break;
		case "MechanicIsPrison_woman_4":
			dialog.text = "��� �������, �������.";
			link.l1 = "�� ��������� ��� ��� ����. ��� ����� ������.";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.questTemp.LSCC = "MechanicIsArrest_toResidence";
			SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
			bDisableFastReload = true; 
			AddQuestRecord("ISS_MainLine", "64");
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1 = "location";
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1.location = "SanAugustineResidencee";
			pchar.quest.LSCC_fightEnterResidence.function = "LSCC_fightEnterResidence";
		break;
		case "SeekCrew_all":
			pchar.questTemp.LSCC.crew = sti(pchar.questTemp.LSCC.crew) + 1;
			chrDisableReloadToLocation = true;
			float   locx, locy, locz;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			if (sti(pchar.questTemp.LSCC.crew) >= 15)
			{
				DeleteAttribute(pchar, "questTemp.LSCC.crew");
				pchar.questTemp.LSCC = "MechanicIsArrest";
				pchar.questTemp.LSCC.lastManId = npchar.index; //���� ������� ������
				NextDiag.TempNode = "MechanicIsPrison_" + npchar.sex;
				AddQuestRecord("ISS_MainLine", "63");
				AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","�"));
				AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("��","��"));
				if (npchar.location.group == "sit")
				{
					ChangeCharacterAddressGroup(npchar, npchar.location, "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
				}
				npchar.cityTape = "quest";  //����� �� ������������
				DeleteAttribute(npchar, "location.going"); //����� ����� �� �����������
				LAi_SetActorType(npchar);
				LAi_ActorRunToLocation(NPChar, "reload", LAi_FindNearestLocator("reload", locx, locy, locz), "none", "", "", "OpenTheDoors", 10.0);
				pchar.quest.LSCC_afterArestMachanic.win_condition.l1 = "ExitFromLocation";
				pchar.quest.LSCC_afterArestMachanic.win_condition.l1.location = pchar.location;
				pchar.quest.LSCC_afterArestMachanic.function = "LSCC_afterArestMachanic";
			}
			else
			{
				AddQuestRecord("ISS_MainLine", "62");
				AddQuestUserData("ISS_MainLine", "sName", GetFullName(npchar));
				AddQuestUserData("ISS_MainLine", "Sex", NPCharSexPhrase(npchar, "����������", "�����������"));
				AddQuestUserData("ISS_MainLine", "iCrew", FindRussianPeoplesString(15-sti(pchar.questTemp.LSCC.crew), "Acc"));
				npchar.lifeDay = 0;
				if (npchar.location.group == "sit")
				{
					ChangeCharacterAddressGroup(npchar, npchar.location, "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
				}
				LAi_SetActorType(npchar);
				LAi_ActorRunToLocation(NPChar, "reload", LAi_FindNearestLocator("reload", locx, locy, locz), "none", "", "", "OpenTheDoors", 10.0);			
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();		
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		������ ����� ���� ���, ������� ������� � �������
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "fight_owner";
		break;
		case "fight_owner":
			LAi_SetOwnerTypeNoGroup(NPChar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

string sRumourAboutOwners_CityRumour(string sCity, string sOwnerType) // ����� ���� ������������� �� �������
{
	string sRetRumour = "����� ���. �������� � ��� ��, ��� Warship'�.";
	// ���� - PChar.QuestTemp.RumoursAboutOwners.(sOwner) - ��� ��������, ����� ������ �����. ����� ����� ����� ��� �������
	switch(sCity)
	{
		case "Tortuga":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 0;
		break;
		
		case "PortRoyal":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 1;
		break;

		case "PortAntonio":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 1;
		break;

		case "FortOrange":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 2;
		break;
		
		case "Beliz":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 3;
		break;
		
		case "PortoBello":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 4;
		break;
		
		case "Cartahena":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 5;
		break;
		
		case "Maracaibo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 6;
		break;
		
		case "Caracas":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 7;
		break;
		
		case "Cumana":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 8;
		break;
		
		case "SantaCatalina":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 9;
		break;
		
		case "SanJuan":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 10;
		break;
		
		case "Marigo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 11;
		break;
		
		case "Charles":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 12;
		break;
		
		case "SentJons":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 13;
		break;
		
		case "FortFrance":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 14;
		break;
		
		case "BasTer":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 15;
		break;
		
		case "Bridgetown":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 16;
		break;
		
		case "PortSpein":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 17;
		break;
		
		case "Havana":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 18;
		break;
		
		case "Villemstad":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 19;
		break;
		
		case "Santiago":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 20;
		break;
		
		case "PortPax":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 21;
		break;
		
		case "SantoDomingo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 22;
		break;

		case "VillaAlegria":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 10;
		break;

	case "Leke":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 21;
		break;
	}
	
	return sRetRumour;
}

string sRumourAboutOwners_Init(string sOwnerType, int iRumourNum) // ���� ������ �������. ����� ������ ��� ����� ����
{
	PlaySound("VOICE\Russian\GOTHIC\GG_PEOPLE\GG_PEOPLE_" + rand(5) + ".wav");	
	string STR_MAYOR[MAX_RUMOURS_ABOUT_OWNERS]; // �����������
	STR_MAYOR[0] = "�, �������� ���������� - ������������� �������. �� ����� ��������� ����� �������� - � ������� �� ��������� � ��� �� ���� �� ������� �������� ���������\n������������ ��� ���������� - ��... ���... ������ ��������. ����, ��������, ��� �������� �����������.";
	STR_MAYOR[1] = "�, �������� ���������� - ������������� �������. �� ����� ��������� ����� �������� - � ������� �� ��������� � ��� �� ���� �� ������� �������� ���������\n������������ ��� ���������� - ��... ���... ������ ��������. ����, ��������, ��� �������� �����������.";
	STR_MAYOR[2] = "���, �������� ���������� � ��� �������... �� ����������������. ��� �� ������� ��������� � ���� - � � ����� ��������� ��������� �� ��������� ��������� ������... � �������� �� ������ ����� ����� ���� �� ��������.";
	STR_MAYOR[3] = "��... �� ������� ���� � ��� ������������. �� �������� ����� � ������� ����� ����������� - ��� ��� ���� ������� ����������.";
	STR_MAYOR[4] = "��� ���������� ��� ������������ �����. �������, �� - ��������� ������� ��� ���������� �����, ������������ �� ����� ���� ��������, ����� ��������� �������� ���� ���. �������� �� ��� ���� ������ �������, � ������ ��������������� ��������� �� �����.";
	STR_MAYOR[5] = "��... �� ������� ���� � ��� ������������. �� �������� ����� � ������� ����� ����������� - ��� ��� ���� ������� ����������.";
	STR_MAYOR[6] = "�-�... ������... ������ ������� ������� ��� ���� �� ����.";
	
	string STR_TAVERNKEEPER[MAX_RUMOURS_ABOUT_OWNERS]; // ����������
	STR_TAVERNKEEPER[0] = "��, � �� �� ������� ���� ��������� ����� ��������. �� ������� ���� �����������, �� ��� �������, ��� ��� ����� ���������� ������� � ����� �������\n�������, ��� �� �������� � ���������������� � �������� - � � ������� � ���� ��� ����� ������ ����� ���������!";
	STR_TAVERNKEEPER[1] = "�� ��� � ��� ����� �������! ��������, �� � ���� �� ����������. � ���� �� ����� �� �����, ������ ��������� �������� � ��������� ������������! ����, ������, �� ������ � ����� ���� ��������.";
	STR_TAVERNKEEPER[2] = "�������� �������� ���. � ���� � ������� ������ ������� ��������, �� � �������� ����� � ������� ��� � �������. � ����� ������� - �� ������ �� �������� � ������� � �� ��������� ������ ������ ����� �������� ��������������� �������.";
	STR_TAVERNKEEPER[3] = "������������ �������. ��� ���� �� ������� ���������, � ������������� ���� ��� ������ ����������. ������ �������, ��� ��� �������� ��������� ���, ��� ���������� � ����� ������. ���� ���� ���������.";
	STR_TAVERNKEEPER[4] = "�� ����, ���� �� ��� � ��� �������. ������� ��� �������. �������� �������, ��������������, � ����� ���� �������� ������ �������.";
	STR_TAVERNKEEPER[5] = "�������, �� ���� ����� ����������. � ������ �������, � ������, ��� �� �� ����� ��������� ����� � ������ ���������� ����� ���� ����. �� � ������� ��������� ����� �� ����������.";
	STR_TAVERNKEEPER[6] = "������� ��������� ��� �� ����. ��� ���� �������� ������� �� ��� ������ ������, �� ��������� ������� ������ � ������ ����������. ����� ���� ���������� ����, �������� ����� ����� �������, � ������ � ��� ���������� ��� ���.";
	
	string STR_SHIPYARDER[MAX_RUMOURS_ABOUT_OWNERS]; // ��������
	STR_SHIPYARDER[0] = "������� �� ������ ��������... � ��� � ��������, � ��� ������ ���-���� ������� - �� ����� ���� � ��������. ��������, �������� �������.";
	STR_SHIPYARDER[1] = "������� �� ������ ��������... � ��� � ��������, � ��� ������ ���-���� ������� - �� ����� ���� � ��������. ��������, �������� �������.";
	STR_SHIPYARDER[2] = "�������� �������, �� �������, ��� �� ������� �����. ��������� ���������� ���� ����������. ������� ��� ����� � ���� ��������. ������, �� ������ �� ���, ������� �� ������������.";
	STR_SHIPYARDER[3] = "�� ����� ������������ �������. �������, ��� �� ������ ��������������� � ������, ����� � ���������. � � ����� ������ �������� ����� - ����� �� ����������, � ����������� ����������\n�������, ��� �� �� ������� � ���� ����� �� ������ �����������, � ��� �������� ������ � �������.";
	STR_SHIPYARDER[4] = "��, ���� ������ ��� ������ �� �������. �� ��������� ������ � ��������� ��������, � ������, ����� ��� ���������� ���-������, ����� ��������� ��� �������.";
	STR_SHIPYARDER[5] = "�������� ������. ������ ����� ������, �������� �� ����. ���� �������, ��� � ������� ��� ��������� ���������� �� ������ ����� ���� ��������.";
	STR_SHIPYARDER[6] = "�� ��� �������� � ����� �������, ���� �� ���������, ��� � ���� ������ � ���������������. ����� ����, ��� ��� ��� ������������ �� ������ ����� ������� ���� ��������� ��� ������������ �����, ��� �������� ��� �����������, � ������ �� - ������������ ���� ������ ��������.";
	
	string STR_TRADER[MAX_RUMOURS_ABOUT_OWNERS]; // �����������
	STR_TRADER[0] = "������ �������� ������� � ��� ������� �� ����. ��������������� ������, �������� ���������� ����� ������. ������� �� ������, ����� ���-������ ����� ��� ��� ��� �� ���� ������.";
	STR_TRADER[1] = "�� ������� ��������� ������ �����������, � ��� ���� ��� �������� �����. �� ���� �� ���� ����� ������. ��, ��� ���� �� � ��� ��������� ��� ������� �� ���.";
	STR_TRADER[2] = "���� ������� ���������� ����������� ��������� � ����� ������. ����� � ���� ������ ��������, � � �� �������� ������, ����� �� ����-������ ��������.";
	STR_TRADER[3] = "��������� �� �����. �������-�������, � ����� ��������. �� ����� ������� ���, �� ������. � ��� �� ������ ����� �� �������.";
	STR_TRADER[4] = "��������� �� �������, ����. �������, �� ��� ���������� �������� ������, �� ������� ��� � ����� ��������� �������. �� ����, ��� ������ �������� �������, ������� �� �������, �� ��� ������� �� ��� ������ ���������.";
	STR_TRADER[5] = "�! ��� ������� �������, � �� �� ��������� ��� ����� � ��� ������� ���\n�� ������ �������� ������� ������ ������ � ���������! � ������, ������� ��������� � ���� � �������� ������ ������� ��������.";
	STR_TRADER[6] = "�� ����� � ��� ������ ������ � �� �����. �� ������� ���� �����������, � ����� ������ ���� ����. ������� ����� ������, ����������� �� �����.";
	
	string sTempMayor = STR_MAYOR[iRumourNum];
	string sTempTavernkeper = STR_TAVERNKEEPER[iRumourNum];
	string sTempShipyarder = STR_SHIPYARDER[iRumourNum];
	string sTempTrader = STR_TRADER[iRumourNum];
	
	if(sOwnerType == "Mayor") return sTempMayor;
	if(sOwnerType == "TavernKeeper") return sTempTavernkeper;
	if(sOwnerType == "ShipYarder") return sTempShipyarder;
	if(sOwnerType == "Trader") return sTempTrader;
}

string GetDeviceLocation(ref npchar)
{
    aref	arCommon, arRld, arRld2;
    int	i, n, Qty, Qty2;
	string LocId; 
	string	storeArray [50];
	int howStore = 0;
    makearef(arRld, Locations[FindLocation(npchar.city + "_town")].reload);
	Qty = GetAttributesNum(arRld);
    if (CheckAttribute(pchar, "questTemp.jailCanMove.Deliver.locationId") || CheckAttribute(pchar, "GenQuest.SeekSpy.Location")) //���� ���� ����� �� �������� ������ ��� ������
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId && LocId != pchar.GenQuest.SeekSpy.Location)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId && LocId != pchar.GenQuest.SeekSpy.Location && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	else
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	if (howStore == 0) return "none";
	LocId = storeArray[dRand(howStore-1)];
	SetOpenDoorCommonLoc(npchar.city, LocId); //��������� �����
	for(n=0; n<MAX_CHARACTERS; n++)
	{
		if (CheckAttribute(&characters[n], "locations") && characters[n].locations == LocId) 
		{			
			characters[n].lifeDay = 0;
		}
	}
	return LocId;
}