#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06

	string NodeName = Dialog.CurrentNode;
	string NodePrevName = "";
	if (CheckAttribute(NextDiag, "PrevNode")) NodePrevName = NextDiag.PrevNode;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			NextDiag.TempNode = "First time";			
			if (npchar.quest.meeting == "0")
			{
				npchar.quest.meeting = "1";
				if (CheckAttribute(loadedLocation, "storm"))
				{
					dialog.text = "��� ������������ ������������"+ GetSexPhrase("��","�") +", ������ ��� ��� �����. � " + GetFullName(npchar) + ", ���� ��� ����� ����� ����������.";
					link.l1 = "��, ����������, " + npchar.name + ". ��� ��� " + GetFullName(pchar) + ", ����� �������. � ��� ������ '�������'?";
					link.l1.go = "FS_1";
				}
				else
				{
					dialog.text = "��� ������������ ������������"+ GetSexPhrase("��","�") +". � " + GetFullName(npchar) + ", ���� ��� ����� ����� ����������.";
					link.l1 = "��, ����������, " + npchar.name + ". ��� ��� " + GetFullName(pchar) + ", ����� �������.";
					link.l1.go = "FT_1";
				}
			}
			else
			{
				//����� ������� ��������� ���� ���������. ���� ������
				if (!CheckActiveQuest("TakeVineToPrisoner") && !CheckAttribute(pchar, "questTemp.LSCC.LegroHelp"))
				{
					dialog.text = "��, "+ GetSexPhrase("��������","�������") +", � ���� � ���� ���� ����.";
					link.l1 = "����������.";
					link.l1.go = "GiveVineBottle";
					break;
				}				
				dialog.text = "��� �� ������, "+ GetSexPhrase("���","����") +"?";
				link.l1 = "������, � ��� ������ ��������. �� ������, ��� �� ������?";
				link.l1.go = "SeekCitizen";
				link.l2 = "���� ������ ���� ������.";
				link.l2.go = "int_quests";
				link.l3 = LinkRandPhrase("���-������ ���������� ��� ����������?", 
					"��� ������ � ������?", "��, � ������������� ��������"+ GetSexPhrase("","�") +" �� ��������� �������...");
				link.l3.go = "rumours_LSCC";
				//����� �������� ���� ���������. ����� ��������� � ������
				if (CheckAttribute(pchar, "questTemp.LSCC.LegroHelp") && pchar.questTemp.LSCC.LegroHelp == "toFackDominic")
				{
					link.l7 = "������, �������"+ GetSexPhrase("","�") +" � �� ���� ������� ���� ������ �����.";
					link.l7.go = "FackDominic";
				}
				if (CheckAttribute(pchar, "questTemp.LSCC.LegroHelp") && pchar.questTemp.LSCC.LegroHelp == "toArmoDominic")
				{
					link.l7 = "�������, � �� ��������� �� �� � ���� ����� �� ����?";
					link.l7.go = "ArmoDominic";
				}
				if (CheckAttribute(pchar, "questTemp.LSCC.LegroHelp") && pchar.questTemp.LSCC.LegroHelp == "toKeyDominic")
				{
					link.l7 = "�� ��� ��, � ��� ������"+ GetSexPhrase("","�") +" � ������� ������.";
					link.l7.go = "KeyDominic";
				}
				//����� ������� �� ��������� ���
				if (pchar.questTemp.LSCC == "toSeekGoods")
				{
					link.l8 = "������, � ��� ��������� ������.";
					link.l8.go = "SeekGoods";
				}
				//������ ������� �� ��������� ���
				if (pchar.questTemp.LSCC == "toSeekPeopleInCrew")
				{
					link.l8 = "������, � ������� �������, ����� ���� ������. ��������� ���� ���� �� ����.";
					link.l8.go = "SeekCrew";
				}
				link.l10 = "������...";
				link.l10.go = "exit";
			}
		break;
		case "FS_1":
			dialog.text = "����� �������, � ��� ��������� ��������� �� ����.";
			link.l1 = "�������. ��, �� ���� � �� �����!";
			link.l1.go = "FS_2";
		break;
		case "FS_2":
			dialog.text = "��� �����, �� � - ���������� ��������. ���� � ���, ��� ��� ������� �������� � ����� ��� ������!";
			link.l1 = "���, ��� ��� ��! ��������, ����������.";
			link.l1.go = "FT_3";
		break;
		case "FT_1":
			dialog.text = "��� �, ����� �������.";
			link.l1 = "� ������ ���� �������� ����������?";
			link.l1.go = "FT_2";
		break;
		case "FT_2":
			dialog.text = "���� ������ ����� ��� ����������. � ������ ����� ���������������, ��� � ����������� �������, �� ��� �������� ���� ���������...";
			link.l1 = "� ��� �� ���������� ���� � ����� ��������?";
			link.l1.go = "FT_3";
		break;
		case "FT_3":
			dialog.text = "��, ��� ���� ������ ����������� ��������, ���� ������! � ��� ������ ������� ������, � ����� ������� �����, ����� ���� ����� ���-�� ����� ������ ��������� � ��������� ������.\n"+
				"���, �� ������ ���������! ������� �� ��������� ������ ����������� � ����� ���������� ��������, � � ���� �� �������! ����� ����, � ��������� ���������� �� ����� � ������ ������ ����������, � � ����� ������ ����� �� � ������� ������ � ��� ��� ���� �������������, ������, ������ ���������...";
			link.l1 = "������� �� ����������� ��� ���?";
			link.l1.go = "FT_4";
		break;
		case "FT_4":
			dialog.text = "������� � �� �������� ��������������� ������ ��������, �� � ������ ������ ����� ��������. � ����������� ������� � �������� ��� �������� �������, � � ����� ������� ����, ��� �������. ����, �� ����� ��� ��� ������� ��� ���������� ����� - ������ ���������...";
			link.l1 = "��... ������, � ��� ��� �� ���� �� ����������? ����� ��������� ������...";
			link.l1.go = "FT_5";
		break;
		case "FT_5":
			dialog.text = "�� �����, "+ GetSexPhrase("��������","�������") +", �� �� ������. ��� ������� - ��� ������ ���, ����� ��������. � ���������.";
			link.l1 = "�� ��, ��� �����. � ��� �� ����� �����������?";
			link.l1.go = "FT_6";
		break;
		case "FT_6":
			dialog.text = "�� �����! ���� ����� ���, � ������ ��� � ������ ��� �� �������. � ������ ���� ����������� ����... � ��� ��� ��������, ���� ������!";
			link.l1 = "��� �, ��� ���� �������. ������� �� ������... ������, � �����, ����������� � ���������� ��� � �����?";
			link.l1.go = "FT_7";
		break;
		case "FT_7":
			dialog.text = "������, "+ GetSexPhrase("�������","" + pchar.name + "") +", ����� ����������. ���� ������ ���������, ��� ��� ���� ���-���� ������� ����� �������� � �����... ��� ���.";
			link.l1 = "�������... �� ��� �, ������� � �� ����.";
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//����������� �� � ��������
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
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� ���"+ GetSexPhrase("","����") +"!!! ��������� ������ ������!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ��"+ GetSexPhrase("","�") +" �������"+ GetSexPhrase("","�") +" �����!", "�������! ������!!! ����� �"+ GetSexPhrase("��","��") +", ��"+ GetSexPhrase("","�") +" �������"+ GetSexPhrase("","�") +" �����!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ ��������?! ������ �������� � ������� ������ ����, ��� ������ ������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//��������� �� ����������� ������
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("������, �� �� ����� ������. � �� ���������� �������...", "������, � ��� ��� �� ������� ��������� �����������. ����� ������.", "������, ��� ��, ��� ��� ���������, ������� ���, ������ ������? ����� ������, �� � ���� ��� "+ GetSexPhrase("���������� �������","�������") +"...");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "���������� �� ���������, "+ GetSexPhrase("��������","�������") +", ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� "+ GetSexPhrase("�������","��� ������") +" ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����"+ GetSexPhrase("","�") +".", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;

		//���� ��������
		case "SeekCitizen":
			dialog.text = "� ���� �� �����?";
			Link.l1.edit = 3;
			Link.l1 = "";
			Link.l1.go = "SeekCitizen_Choice_1";
		break;
		case "SeekCitizen_Choice_1":
			sld = CheckLSCCCitizen();
			if (sld.id == "none")
			{
				dialog.text = "� �� �������, � ��� �� ��������. ��� ����� ����� ��� � ������� ����� ��������.";
				Link.l1 = "�������. ������� � ��� �������� �������.";
				Link.l1.go = "SeekCitizen_Choice_2";				
				Link.l2 = "�������, � ����� ���"+ GetSexPhrase("","�") +" �����.";
				Link.l2.go = "exit";	
			}
			else
			{
				if (sld.id == npchar.id)
				{
					dialog.text = "��� ��� �� �!";
					link.l1 = "���� ��, ����� �� ��� ���"+ GetSexPhrase("��","��") +"!";
					link.l1.go = "exit";
					break;
				}				
				if (sld.sex == "man")
				{
					dialog.text = GetFullName(sld) + ", �� � ��� ��������?";
					Link.l1 = "��-��, �����, ��� ��.";
					Link.l1.go = "SeekCitizen_agree";				
					Link.l2 = "���, �� � ���. ������� ��� ��� ������.";
					Link.l2.go = "SeekCitizen_Choice_2";
				}
				else
				{
					dialog.text = GetFullName(sld) + ", �� � ��� ��������?";
					Link.l1 = "���, ������ � ���.";
					Link.l1.go = "SeekCitizen_agree";				
					Link.l2 = "���, �� � ���. ����������, ������� � ��� ��� �������� �������.";
					Link.l2.go = "SeekCitizen_Choice_2";
				}
				Link.l3 = "������, �� ���� � ������ �� � ��� ����������. �� ��������.";
				Link.l3.go = "exit";
				npchar.quest.seekIdx = sld.index;
			}
		break;
        case "SeekCitizen_Choice_2":
			dialog.text = "����� �������� ��� ��� ��� � �������.";
			Link.l1.edit = 3;
			Link.l1 = "";
			Link.l1.go = "SeekCitizen_Choice_1";
		break;

		case "SeekCitizen_agree":
			sld = &characters[sti(npchar.quest.seekIdx)];
			npchar.quest.seekIdx.where = WhereLSCCCitizen(sld);
			if (npchar.quest.seekIdx.where == "none")
			{
				if (sld.sex == "man")
				{
					dialog.text = LinkRandPhrase("�� ����, ����� ��� �� �����.", "���� ��� �����, ��� ��...", "�� ����� ��� ��� ��������, ��� ��� �� �����.");
					link.l1 = RandPhraseSimple("�������.", "����...");
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = LinkRandPhrase("�� ����� �� ��� �������� �����, �������.", "������� �� ����, ��� ��� ������.", "��, � �� ����, ��� ��� ����� ������ ����.");
					link.l1 = RandPhraseSimple("����.", "����...");
					link.l1.go = "exit";
				}
			}
			else
			{
				if (sld.sex == "man")
				{
					if (sld.location == "LostShipsCityy_town")  
					{						
						string Str1 = npchar.location.locator;
						string Str2 = sld.location.locator;
						if (npchar.location == sld.location && strcut(Str1, 0, 5) == strcut(Str2, 0, 5))
						{
							dialog.text = LinkRandPhrase("�� �����, �� ���� �������. ����� ������������.", "��, ��� �� �����, �� ���� �������!", "�� �� ���� �������, �������, ��� �� ��� �� ������� ���.");
						}
						else
						{
							dialog.text = LinkRandPhrase("� ����� ��� ������ ������� " + npchar.quest.seekIdx.where + ".", "������� �������� ��� " + npchar.quest.seekIdx.where + ". ��� ��� ����� ��� ���.", "��������� � ����, ������ �� ��������� " + npchar.quest.seekIdx.where + ".");
						}
					}
					else
					{
						if (npchar.location == sld.location)
						{
							dialog.text = LinkRandPhrase("��� �� �����, " + npchar.quest.seekIdx.where + ". �������� ������������.", "��� ���� �� �����, ����� ���!", "���� �� ��������? �� �� ����� ���������.");
						}
						else
						{
							dialog.text = LinkRandPhrase("� ����� ��� ������ ������� " + npchar.quest.seekIdx.where + ".", "������� �������� ��� " + npchar.quest.seekIdx.where + ". ��� ��� ����� ��� ���.", "��������� � ����, ������ �� ��������� " + npchar.quest.seekIdx.where + ".");
						}
					}
					link.l1 = RandPhraseSimple("���, �������. ������� ���.", "������� ���!");
					link.l1.go = "exit";
				}
				else
				{
					if (sld.location == "LostShipsCityy_town")  
					{						
						string Str3 = npchar.location.locator;
						string Str4 = sld.location.locator;
						if (npchar.location == sld.location && strcut(Str3, 0, 5) == strcut(Str4, 0, 5))
						{
							dialog.text = LinkRandPhrase("��� �����, �� ���� �������. ����� ������������.", "��, ��� ��� �����, �� ���� �������!", "��� �� ���� �������, �������, ��� �� ��� �� ������� ��.");
						}
						else
						{
							dialog.text = LinkRandPhrase("� ����� �� ������ ������� " + npchar.quest.seekIdx.where + ".", "������� �������� �� " + npchar.quest.seekIdx.where + ". �� ���� ����������.", "��������� � ����, ������ ��� ��������� " + npchar.quest.seekIdx.where + ".");
						}
					}
					else
					{
						if (npchar.location == sld.location)
						{
							dialog.text = LinkRandPhrase("��� ��� �����, " + npchar.quest.seekIdx.where + ". �������� ������������.", "��� ���� ��� �����, ����� ���!", "���� �� ��������? ��� �� ���-�� ����� �����.");
						}
						else
						{
							dialog.text = LinkRandPhrase("� ����� �� ������ ������� " + npchar.quest.seekIdx.where + ".", "������� �������� �� " + npchar.quest.seekIdx.where + ". �� ���� ���������� � ���.", "��������� � ����, ������ ��� ��������� " + npchar.quest.seekIdx.where + ".");
						}
					}
					link.l1 = RandPhraseSimple("���, �������. ������� ���, "+GetAddress_FormToNPC(NPChar)+".", "������� ���!");
					link.l1.go = "exit";
				}
			}
		break;
		//�������
		case "int_quests":
			dialog.text = "����������� ���� ������, "+ GetSexPhrase("�������","" + pchar.name + "") +".";
			if (!CheckAttribute(NextDiag, NodeName+".l4"))
			{
				link.l4 = "� ��� �������, ��� ������ ����� - ���� ���������.";
				link.l4.go = "ansewer_4";
			}
			if (!CheckAttribute(NextDiag, NodeName+".l1"))
			{
				link.l1 = "� ����� �����?..";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(NextDiag, NodeName+".l2"))
			{
				link.l2 = "��� � ������ �������� ������ ��������? ������� ���� ����� ��������� ���������������, ��� �� ���������� ���� � �� ������� ���� �����?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(NextDiag, NodeName+".l3"))
			{
				link.l3 = "���� ���� ��������� ������... ����-������?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(NextDiag, NodeName+".l5") && pchar.questTemp.LSCC == "toSeekOldCitizen")
			{
				link.l5 = "������, � �� ����� ����� �����������?";
				link.l5.go = "ansewer_5";
			}
			link.l10 = "��� ��������. ������, ��������...";
			link.l10.go = "exit";
		break;
		case "ansewer_4":
			dialog.text = "�� � �� �� ������. ������, ��� �� ����� - ��� ����� ��! ��� �������, ��������... �����������, � �����.";
			link.l1 = "�������.";
			link.l1.go = "int_quests";
			NextDiag.(NodePrevName).l4 = true;
		break;
		case "ansewer_1":
			dialog.text = "����� ��� ��, ��� �� ��������� �������. �����... ������ ���������.";
			link.l1 = "� ����.";
			link.l1.go = "int_quests";
			NextDiag.(NodePrevName).l1 = true;
		break;
		case "ansewer_2":
			dialog.text = "������ ������, �������. ��� �� ����� �������� ����� ���� ������ �����������. ������ �����������, ��� ��������� ����� � ��� - � ��� ����.";
			link.l1 = "�������... � ���, ������������� � ����� ����� ������?";
			link.l1.go = "ansewer_2_1";
			NextDiag.(NodePrevName).l2 = true;
		break;
		case "ansewer_2_1":
			dialog.text = "������...";
			link.l1 = "����. �� � ��������� ����� ��� ����������� ���� � ������?";
			link.l1.go = "ansewer_2_2";
		break;
		case "ansewer_2_2":
			dialog.text = "�������. ������, ���-��� �������� ��� �����, ������ �� �����... � �����, �� ������ - �� ���.";
			link.l1 = "���, �������...";
			link.l1.go = "int_quests";
		break;
		case "ansewer_3":
			dialog.text = "�������"+ GetSexPhrase(", ��������","") +"! �������� � �����������!";
			link.l1 = "���������.";
			link.l1.go = "int_quests";
			NextDiag.(NodePrevName).l3 = true;
		break;
		case "ansewer_5":
			dialog.text = "��, ��� ��� �������. ��� ��������� � ��� ����� - ��������...";
			link.l1 = "��� �� ��� ��� ����� ������?";
			link.l1.go = "ansewer_5_1";
			NextDiag.(NodePrevName).l5 = true;
		break;
		case "ansewer_5_1":
			dialog.text = "���, ������. ��� ��� � ������� ���������.";
			link.l1 = "�������. ���� ������� ��� ��� �����?";
			link.l1.go = "ansewer_5_2";
		break;
		case "ansewer_5_2":
			dialog.text = "���. ���� �����, ������� ��� ����������. ��� �� ������� � ���� - � ���� ��� ���� � ������������. ��, ����...";
			link.l1 = "�����, ���� ������.";
			link.l1.go = "int_quests";
		break;
		//����� ������� �� ��������� ���
		case "SeekGoods":
			dialog.text = NPCStringReactionRepeat("��� �� ������?", 
				"�� ��� ���������"+ GetSexPhrase("","�") +" �� ����.", 
				"��� ���������"+ GetSexPhrase("","�") +"...",
                "�� ��� ���������"+ GetSexPhrase("","�") +" ���� �� ���� �������. ������ � �� ����!", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� ����� ����, �����, ��������, ��������, ���������, �����, ������...", 
				"��... ������, �����������"+ GetSexPhrase("","�") +".",
                "�-�, �� ��.", 
				"�����"+ GetSexPhrase("","�") +", �����"+ GetSexPhrase("","�") +"...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("SeekGoods_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "SeekGoods_1":
			dialog.text = "��, ���� ����� ��������� � ������ �����. � ��� ������ ����� ����� ����������. ��������� ���������� ��������� � ������ ������� ����. � ��� ������ � ����� - ��� ���� ��������...";
			link.l1 = "��� ������?";
			link.l1.go = "SeekGoods_2";
		break;
		case "SeekGoods_2":
			dialog.text = "��, �� �� ���� �������� �������� ������ � �����. ��� ��� ��� ������ � ����.";
			link.l1 = "�����"+ GetSexPhrase("","�") +", �������.";
			link.l1.go = "exit";
		break;
		//���� �������
		case "SeekCrew":
			dialog.text = "�-��.. ��������"+ GetSexPhrase("","�") +", ������...";
			link.l1 = "�������. �� �������� ������� ������. ���� �� ��������, �� ����� ����� ������ ����������� �� ��� ��������� ���.";
			link.l1.go = "SeekCrew_1";
		break;
		case "SeekCrew_1":
			dialog.text = "����������?";
			link.l1 = "��. �� ����� ����������� �����, �������, ������ �����, ��������� ������. ����� ����������.";
			link.l1.go = "SeekCrew_2";
		break;
		case "SeekCrew_2":
			dialog.text = "���, ����� ��� �������! � ��������.";
			link.l1 = "�������. ������ ����������� �� '��� ��������', ��� ������� ���������� ��������� �� ��������� ���.";
			link.l1.go = "SeekCrew_3";
		break;
		case "SeekCrew_3":
			dialog.text = "������. ������� ������ ������� �������.";
			link.l1 = "�� ���������.";
			link.l1.go = "SeekCrew_all";
		break;
		//������� ������� ���� ���������
		case "GiveVineBottle":
			dialog.text = "� ���� ���� ����, ����� ����, ��������. ������ ����� ����� �� ���� �������� '���������', ��� ����� ��� �� ��������.\n���� ������� ��� ��������.";
			link.l1 = "�����������. ��� � ���� ������?";
			link.l1.go = "GiveVineBottle_1";
		break;
		case "GiveVineBottle_1":
			dialog.text = "������, ��������� ���-������ ��������� ���� � ������ ��� �� ����. ��� ����� ����� �������!";
			link.l1 = "��������, ��, �����, �� ��������? � ���, ��-������, "+ GetSexPhrase("�������","�������") +" �� ����������?";
			link.l1.go = "GiveVineBottle_not";
			link.l2 = "�����, ������.";
			link.l2.go = "GiveVineBottle_2";
		break;
		case "GiveVineBottle_not":
			dialog.text = "�� �� �������� �� ���. �� ������ - �� ����...";
			link.l1 = "� ������ �� ���� �� ��� � ������ ���������� �������������!";
			link.l1.go = "exit";
			pchar.questTemp.LSCC.LegroHelp = "over";
			CloseQuestHeader("TakeVineToPrisoner");
		break;
		case "GiveVineBottle_2":
			dialog.text = "��, ������� ����, "+ GetSexPhrase("�������","" + pchar.name + "") +". �����-�� ��� ����������!..";
			link.l1 = "�������.";			
			link.l1.go = "exit";
			pchar.questTemp.LSCC.LegroHelp = "toTomasBoil";
			AddQuestRecord("TakeVineToPrisoner", "1");
		break;
		
		case "FackDominic":
			dialog.text = "�������! �����������, ��� �� ��� ���...";
			link.l1 = "���� �� ��� ���, � ��� ���� ������ ��������, ��� ������� �� ���� ���. ���� �������.";
			link.l1.go = "FackDominic_1";
		break;
		case "FackDominic_1":
			dialog.text = "���? �� ���?!!";
			link.l1 = "������� �� ����. �� �� ����� ��� �� ����.";
			link.l1.go = "FackDominic_2";
		break;
		case "FackDominic_2":
			dialog.text = "��� ��� ��!\n������, ����� � ���� ��� ���, ����� ����. �����, ��� ���������-��!";
			link.l1 = "��� ����� � ������.";
			link.l1.go = "FackDominic_3";
		break;
		case "FackDominic_3":
			dialog.text = "����, � �����. �����, �� ������� ��� �����������, � ����� ����������� �����. �����, ������, � ��� ����, ����� ���� �����!";
			link.l1 = "�����, ��� �� � ����, ������.";
			link.l1.go = "FackDominic_4";
			link.l2 = "����� � ���! � ���� ���, "+ GetSexPhrase("�������","�������") +" �� ����������?";
			link.l2.go = "GiveVineBottle_not";
		break;
		case "FackDominic_4":
			dialog.text = "������� ����, "+ GetSexPhrase("�������","" + pchar.name + "") +"! � �������, ��� ���������� �� �����������, � ��� ��� ����.";
			link.l1 = "� ���� ����.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC.LegroHelp = "toSecondToPrison";
			AddQuestRecord("TakeVineToPrisoner", "3");
		break;

		case "ArmoDominic":
			dialog.text = "��, ������������ � � ��� ������. �� � ����� ������ � ���� ���� �� �����! ��� ����� � �� ����, ��� ��� �������.";
			link.l1 = "� ��� ��� �������?";
			link.l1.go = "ArmoDominic_1";
		break;
		case "ArmoDominic_1":
			dialog.text = "������ �����, �����������. � �� �� ����� �����, ����� ��� ����� � ����� ������� ����� � ��� ��������!";
			link.l1 = "�������, ��� ���. ��� ��� �� ����� �������...";
			link.l1.go = "ArmoDominic_2";
		break;
		case "ArmoDominic_2":
			dialog.text = ""+ GetSexPhrase("�������","" + pchar.name + "") +", ����� ��� ��� ���� ������.";
			link.l1 = "�����?..";
			link.l1.go = "ArmoDominic_3";
		break;
		case "ArmoDominic_3":
			dialog.text = "��, �� ��... ����� ��� ��� � ������, ����� ���, ��� ���� ����������.";
			link.l1 = "������, � ��� ��� ��� �������?";
			link.l1.go = "ArmoDominic_4";
		break;
		case "ArmoDominic_4":
			dialog.text = "�� ��� ������ � �������! ����� � � ���� ������������, ��� ��� ��� ��������� ������.";
			link.l1 = "�-��... �� �����, ��� �� ����, ���������� ������� ������ � ����� ������������.";
			link.l1.go = "ArmoDominic_5";
		break;
		case "ArmoDominic_5":
			dialog.text = "������� ����"+ GetSexPhrase(", ��������","") +"!";
			link.l1 = "�� �� �� ���.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC.LegroHelp = "to3ToPrison";
			AddQuestRecord("TakeVineToPrisoner", "5");
		break;

		case "KeyDominic":
			dialog.text = "�������! ��� �� ������?";
			link.l1 = "�� ���������� ����� ����� �� ���� ����������� ���������.";
			link.l1.go = "KeyDominic_1";
		break;
		case "KeyDominic_1":
			dialog.text = "��� �����, ����� �����\n"+ GetSexPhrase("�������","" + pchar.name + "") +", � ���� ���������� ����������!";
			link.l1 = "������, � ������ �� ����������� ������������� �������������� �� ���-������ ����� ���������?";
			link.l1.go = "KeyDominic_2";
		break;
		case "KeyDominic_2":
			dialog.text = "���� �� ����, ��� � ���� ���� ����\n�, ��� ���! � ��� ���� ���� �� ��������. �����, �� ���� ����������.";
			link.l1 = "�������, ��� ���.";
			link.l1.go = "KeyDominic_3";
		break;
		case "KeyDominic_3":
			dialog.text = "��, ��� � �������! ��� ��� ��������� ����.";
			link.l1 = "�� �� ���, ���� ��...";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "key1");
			pchar.questTemp.LSCC.LegroHelp = "over";
			AddQuestRecord("TakeVineToPrisoner", "7");
			AddQuestUserData("TakeVineToPrisoner", "sSex", GetSexPhrase("", "�"));
			CloseQuestHeader("TakeVineToPrisoner");
		break;
	}
	NextDiag.PrevNode = NodeName;
}