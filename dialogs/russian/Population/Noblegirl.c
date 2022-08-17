//Jason ����� ������ ��������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Citizen\" + NPChar.City + "_Citizen.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(17) + ".wav");
			//������ �������
            if(NPChar.quest.meeting == "0")
			{
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)//�������� ��������������� ���������
				{
					dialog.text = "��. �� ������ ��� ������ "+NationNameGenitive(sti(pchar.nation))+", �������. � ���� ��� �������� ������� �������� � ������ ���� �������. ������� �����!";
					link.l1 = "���� ���, ���������...";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = RandPhraseSimple("��� �� ������ �� ����, "+GetAddress_Form(NPChar)+"? �� �������� ������� ���������� � ����������� � ������� ����, �� � ��� �� �������� ���.", "��, � ��� �� ����� ���� �� ���� ����� ������ ������� ��������, �?");
					link.l1 = TimeGreeting()+", ��������. � �� ������� ��� �������, ������ ���� ��������...";
					link.l1.go = "question";
					link.l2 = RandPhraseSimple("��� ����� ������, ��� �������� � ����� �������.", "��� ����� ����������.");
					link.l2.go = "quests";//(���������� � ���� ������)
				}
				npchar.quest.meeting = "1";
			}
			else
			{
				//��������� ���������
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
					dialog.text = "� ���, ��������� ���������? � �� �����, ����� ���� ����������� � ����� � "+NationNameAblative(sti(pchar.nation))+"! �������, ��� � ������ ������! ���-�� ����� ����� ���� � ���� ������������.";
					link.l1 = "�����-�����, �� ����������. �����.";
					link.l1.go = "exit";
				}
				else
				{
				dialog.text = NPCStringReactionRepeat("���? �����? ������� ��� �������� ����-������ �������. ��� ����� ������������, ����������� �� ������. � ��� ���� - ������� ����� � �����������, � � ���� ��� �������� �� ������...", 
					"���, ��� ��� �������� ������������� ��������! �� ���, �� ��������� � ������� ����? �� �������� �����������?", 
					"������, � ������� �����������, ��� �� �� ������, � ����������� � ���. ������������: ������ ���������� � ������� ����������� - ������ ����!",
					"���, ��� ���� ����� - � � ������ ����������, ����� � ��������� ��� ���� ������� ����!", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������. ����� �������.", 
					"��-��, � �����, ������ ����� �������� ��� ���...",
					"�� ���� ����������� ������...", 
					"�� �������, ��������, � ��� �����.", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
				}
			}
			NextDiag.TempNode = "First time";
		break;

		//���� ��������� ����� �������� � ����������� �� ������
		case "question":
			dialog.text = LinkRandPhrase("��, ������� ���������, ��� � ����.","��, �� ������. ��� �� ������?","������� �������� �����? �����, �����, ������.");
			link.l1 = LinkRandPhrase("�� ���������� ��������� ������� ������ ������?","���������� ����������, ��� ����������� � ��������� ����� ���������?","��� ����������� �������� �� ����������, ��������, �� �� � �����?");
			link.l1.go = "rumours_noblegirl";
			NextDiag.TempNode = "First time";
		break;

		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
