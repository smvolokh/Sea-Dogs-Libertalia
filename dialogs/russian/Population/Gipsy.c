//Jason ����� ������ �������
// ugeen <-- ������� ������� ������� �� ��� ����
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	int poison_price;

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
			dialog.text = "�-�, ��� ����� ��, �����? ��� �� �����?";
			link.l1 = "�� ���, �������, ������.";
			link.l1.go = "exit";
			link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
			link.l2.go = "quests";//(���������� � ���� ������)
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = LinkRandPhrase("�����, �������� �����. ��� ������ ���� ��������.","��, �������, �� �����! ������ ������ ��� ������?","������ ��������, �������, � ����� ���������� �����, � � ������� � ���� �������.");
				link.l1 = "������, ��� ���� ����.";
				link.l1.go = "exit";
				// --> ���������
				if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "gipsy" && !CheckAttribute(npchar, "quest.mangarosa"))
				{
					link.l5 = "��������, ��������, � ����, ��� �� - ������� ��������� �����. ��� ��� ������� �� ����, ��� ��� ������� ���������� ��� ��� ������. ��������.";
					link.l5.go = "mangarosa";
				}
				if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "gipsy_trade" && !CheckAttribute(npchar, "quest.mangarosa"))
				{
					link.l5 = "�����������, � ���� ��� ���� ���-��� ����... ��� ���������. ������ ��������?";
					link.l5.go = "mangarosa_trade1";
				}
				// <-- ���������
				link.l2 = "�� ������ ��� ��������?";
				link.l2.go = "guess";
				link.l3 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
				link.l3.go = "quests";//(���������� � ���� ������)
				npchar.quest.meeting = "1";
			}
			if (!CheckAttribute(npchar, "quest.poison_price") && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && rand(2) == 0)
			{
				link.l4 = "� ���, �����������, �� �������� �� � ���� ������ ����� ��� ����? ������ �� ��� ����� �� �����!";
				link.l4.go = "get_poison_1";
			}
			NextDiag.TempNode = "First time";
		break;

//-------------------------------------------------�������-------------------------------------------------
		case "guess":
			dialog.text = "�������, �����. ��� ��������� ����� � ������ ���� ������ ������ - ������� � ���, ��� ���� ���� �������, ��� ������!";
			link.l1 = "�������, � ���������. ������� ���-��...";
			link.l1.go = "exit";
			link.l2 = "������� ����� �� �������?";
			link.l2.go = "guess_1";
		break;
		
		case "guess_1":
			dialog.text = "�, �����, ��� ������� �������� ���� ���� ������ � ���� �������.";
			link.l1 = "100 ����.";
			link.l1.go = "guess_rate_1";
			link.l2 = "500 ����.";
			link.l2.go = "guess_rate_2";
			link.l3 = "1000 ����.";
			link.l3.go = "guess_rate_3";
			link.l4 = "5000 ����.";
			link.l4.go = "guess_rate_4";
		break;
		
		sTemp = GuessText();
		case "guess_rate_1"://������� ������
			if (sti(pchar.money) >= 100)
			{
				AddMoneyToCharacter(pchar, -100);
				dialog.text = "��, ������� �� ��� ��������� �����, �������! ������ ������: "+sTemp+"";
				link.l1 = LinkRandPhrase("���! ��� ����� �������! ����...","��� ���? ����� � ��������...","�� ��? �� ��������? �� ��� ��, �������...");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "����, ���� � ���������, ���� ����. ����, ���� ����������! ��������� ������ ���� ��� ����� � ������� ���� ���� ����������!";
				link.l1 = "��-��! �� ���, ������, ������, � ����� ���� ���? ����������, ������ ����!";
				link.l1.go = "guess_exit";
			}
		break;
		
		case "guess_rate_2"://������� � ������� ��� ����������
			if (sti(pchar.money) >= 500)
			{
				AddMoneyToCharacter(pchar, -500);
				dialog.text = "��, �������, �������! ������ ������: "+sTemp+"";
				link.l1 = LinkRandPhrase("���! ��� ����� �������! ����...","��� ���? ����� � ��������...","�� ��? �� ��������? �� ��� ��, �������...");
				link.l1.go = "exit";
				if (drand(1) == 0) AddCharacterExpToSkill(pchar, "Fortune", 30+rand(10));//�������
				else AddCharacterExpToSkill(pchar, "Sneak", 30+rand(10));//����������
			}
			else
			{
				dialog.text = "����, ���� � ���������, ���� ����. ����, ���� ����������! ��������� ������ ���� ��� ����� � ������� ���� ���� ����������!";
				link.l1 = "��-��! �� ���, ������, ������, � ����� ���� ���? ����������, ������ ����!";
				link.l1.go = "guess_exit";
			}
		break;
		
		case "guess_rate_3"://�������� + ������� ��� ����������, �������
			if (sti(pchar.money) >= 1000)
			{
				AddMoneyToCharacter(pchar, -1000);
				dialog.text = "��, ������� �� �������, �������! ������ ������: "+sTemp+"";
				link.l1 = LinkRandPhrase("���! ��� ����� �������! ����...","��� ���? ����� � ��������...","�� ��? �� ��������? �� ��� ��, �������...");
				link.l1.go = "exit";
				AddCharacterHealth(pchar, 1);
				AddCharacterExpToSkill(pchar, "Leadership", 20);
				if (drand(1) == 0) AddCharacterExpToSkill(pchar, "Fortune", 50+rand(20));//�������
				else AddCharacterExpToSkill(pchar, "Sneak", 50+rand(20));//����������
			}
			else
			{
				dialog.text = "����, ���� � ���������, ���� ����. ����, ���� ����������! ��������� ������ ���� ��� ����� � ������� ���� ���� ����������!";
				link.l1 = "��-��! �� ���, ������, ������, � ����� ���� ���? ����������, ������ ����!";
				link.l1.go = "guess_exit";
			}
		break;
		
		case "guess_rate_4"://������ � ������, �������+����������, ��������, �������
			if (sti(pchar.money) >= 5000)
			{
				AddMoneyToCharacter(pchar, -5000);
				dialog.text = "��, ������� �� ���� ��������, �������! ������ ������: "+sTemp+"";
				link.l1 = LinkRandPhrase("���! ��� ����� �������! ����...","��� ���? ����� � ��������...","�� ��? �� ��������? �� ��� ��, �������...");
				link.l1.go = "exit";
				AddCharacterHealth(pchar, 2);
				AddCharacterExpToSkill(pchar, "Leadership", 40);
				AddCharacterExpToSkill(pchar, "Fortune", 50+rand(100));//�������
				AddCharacterExpToSkill(pchar, "Sneak", 50+rand(50));//����������
				AddComplexSelfExpToScill(20, 20, 20, 20);
			}
			else
			{
				dialog.text = "����, ���� � ���������, ���� ����. ����, ���� ����������! ��������� ������ ���� ��� ����� � ������� ���� ���� ����������!";
				link.l1 = "��-��! �� ���, ������, ������, � ����� ���� ���? ����������, ������ ����!";
				link.l1.go = "guess_exit";
			}
		break;
		
		case "guess_exit":
			DialogExit();
			AddCharacterHealth(pchar, -10);
			LAi_CharacterDisableDialog(npchar);
		break;
//<-- �������

// --> ������� �������
		case "get_poison_1" :
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\DOPE_" + rand(3) + ".wav");	
			npchar.quest.poison_price = (drand(3) + 1) * 10;
			if(drand(10) == 3)
			{				
				dialog.text = LinkRandPhrase("�� �� ����, ��������! ������ ���� ��� ���� ������ ���� ���������, � ����� ���-�� ������ � ����� ��������. ��� ��� ������ �� ������ �������. ���� �� ������ �� �������, ���� �� ����� ���� ��������. ���������� ��������� ��������.",
				                             "� ������ ��� �����, ���� �� ������� ��������? ����� �������� ���������, � ������� ������� �� ������� ������� � ������� ��������? ",
											 "��������� ���, ��� � ������� ������ ���-�� ������� � ������� �������� ����� � ������� �� �����. � ����� ��� ��� ����� ������� ���� ������������, ���� ����� ������ � ����� ����, ��� ��������. �� ����� �� ��� ����, ��������� ���?");
				link.l1 = "��� ������, ��� �� ��� ��� ��������! �� ��������, ����� ������� �� � ���� ���������. ��� ����� � ���� ������ �������� �������, � ��� ������ ���� ������ �� ��������.";
				link.l1.go = "get_poison_2";
			}
			else
			{
				dialog.text = "���, ���� ������! ��� � ���� ������� ������! ����� ����, ������ ����, � ������ ���.";
				link.l1 = "�� �� �����..";
				link.l1.go = "exit";
			}	
		break;
		
		case "get_poison_2" :
			dialog.text = "�� �����, ������ � ����. ������ �� ������ ������, ��� ��� � ���� ������ �������. � ���� "+sti(npchar.quest.poison_price)+" ��������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.poison_price)) 
			{				
				link.l1 = "����������, �������... �� �� �����, ���� �� �������.";
				link.l1.go = "get_poison_4";
			}
			else
			{
				link.l1 = "�� �� ���! ������� ��� �� ���� ������� ����! �� �� ����� ������ � ���� ���� ��� ������ ���������!";
				link.l1.go = "get_poison_3";
			}
		break;
		
		case "get_poison_3" :
			dialog.text = "��� � ����, � �� ��� ������ �� ���� �� ������� ����������. � ��������� ��� ������ ������.";
			link.l1 = "�� ����� ������, ����� �.";
			link.l1.go = "exit";
		break;
		
		case "get_poison_4" :
			PlaySound("interface\important_item.wav");
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.poison_price));
			TakeNItems(pchar, "rat_poison", 1);
			DialogExit();
		break;
// <-- ������� �������

	// --> ���������
		case "mangarosa":
 	                     PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\DOPE_10.wav");
			dialog.text = LinkRandPhrase("���������, �������, ��� ��� � ���� �� ������... ��... �������, � ����� �� � ����. ��� ����� ���� ���� �������?","������ ��� ��, ������... ��... ��, ��� � ��������� ����� � ���� �� ���, �������, �������.","����� ���������... �! ���������� ���������! ��� ����� ���������� �����! �� �����?")"";
			link.l1 = LinkRandPhrase("����������... �����������, � �� �����-������ ����������� ���������. � ����, ��� ��� �� ������. ��� - ���������...","�� ��� �� ����� ��������! ��� �� ���������, ������ �������� ���������. �� ������� ������ ���� �� ���.","���, ��� ����� ������ ���� � ����� ���� ��������� �� ��� �����...");
			link.l1.go = "mangarosa_1";
		break;
		
		case "mangarosa_1":
			dialog.text = "������-������, ���������. ����, ��� ���� �������� ���-��� �� ���� ��������. ��������� ��������. ����� �� ����.";
			link.l1 = "��, �� ������ ��! � ���� ������, ��� ��� �����������, ��� �� ��� ����� �����������. �� ������ �������� ��� ���? ���� ������� �� �� ������ ���������� ������ �������� �� ���� ������� ����!";
			link.l1.go = "mangarosa_2";
		break;
		
		case "mangarosa_2":
			// ��� �������� �������
			if (sti(pchar.questTemp.Mangarosa.g_count) == 5 || GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) > 10+drand(25)+drand(30))
			{
				dialog.text = "��... ��, �������, �������� ������ �� �����, ���� � ���� �������� ������� � ���. ��� ����� ��� ����������� ������ � ���� ������ ������� �� ������.";
				link.l1 = "� ���� ��������!";
				link.l1.go = "mangarosa_3";
			}
			else
			{
				dialog.text = LinkRandPhrase("������, �����, � ������ ����������, � ��� ���������� ���� ����� - �� ��������. ","������ - �������, � ������� - ���������, �������... ","������� ��, �������, ������, � ��� ������� ������ ����� ��� - �� ������. ")+"�� ������ ��������� ��� ���� ���������? ��������� �������� - ��� ���� ����� �� ���, ������ ���� ����� �� ����.";
				link.l1 = "��, �����... ��, ����. ��������� �������� ���� ����������. �����.";
				link.l1.go = "mangarosa_trade";
				link.l2 = "�����, � �� ���� ��������� ��. � ���� ������, ������ ��� ��� ��� �����. �������� ��������, � � ����� ���� ���� ������� ���������.";
				link.l2.go = "mangarosa_exit";
			}
		break;
		
		case "mangarosa_trade":
			RemoveItems(pchar, "cannabis7", 1);
			TakeNItems(pchar, "gold_dublon", 50);
			PlaySound("interface\important_item.wav");
			dialog.text = "������ ���� ������, �������. ���� ������� ��� ��������� - ������� ���. ������, �������� �� ������ �� ������ ������ - ������� ����� � �������� � ����� �� �����. �� ������ ����� � ��� ��������� ��������� ������.";
			link.l1 = "������. ���� ������� ��� - ����������� �������.";
			link.l1.go = "mangarosa_trade_exit";
		break;
		
		case "mangarosa_trade_exit":
			DialogExit();
			npchar.quest.mangarosa = "true";
			DeleteAttribute(pchar, "questTemp.Mangarosa.g_count");
			pchar.questTemp.Mangarosa = "gipsy_trade";
			AddQuestRecord("Mangarosa", "3");
		break;
		
		case "mangarosa_exit":
			dialog.text = LinkRandPhrase("���, ���� �������! �� ������ ��������� - � �� ����, � ������������ ���� � ������ �� ����.","� �� ����� �������� ���� ������� �����������. �� ������ ��������� - � ���� � �����.","������, ��� �� ��� ����� ����. �� ������ ��������� �� �������� �������� - ���, ������ ��������� �� ���� ����� ����.");
			link.l1 = LinkRandPhrase("�� � ��������! ��������� ���-������ ������ �� �����. �� � ������� ��������� � �������. �����!","��� �� ���������? �� ���������� �� - ��������� ������. �� � � ������ ���������. ������.","��� �� ��� �����������? � ���� ��� ����� ������ �������. ���-������ �� ����� �������� ����������� � ������� ��� ��������� ���������. ����!");
			link.l1.go = "exit";
			npchar.quest.mangarosa = "true";
			pchar.questTemp.Mangarosa.g_count = sti(pchar.questTemp.Mangarosa.g_count)+1;
		break;
		
		case "mangarosa_trade1":
			dialog.text = "�����������, �������! �������! ����� �� ���.";
			link.l1 = "����� ��������� ��������.";
			link.l1.go = "mangarosa_trade1_1";
			link.l2 = "��! �������, � �� ��� �������, ��� ����� �� �������. ����� ������! ������...";
			link.l2.go = "exit";
			npchar.quest.mangarosa = "true";
		break;
		
		case "mangarosa_trade1_1":
			RemoveItems(pchar, "cannabis7", 1);
			TakeNItems(pchar, "gold_dublon", 50);
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �����, �� ������. ������� ���� ������.";
			link.l1 = "������� ���� ���������. ����� ��� - �������!";
			link.l1.go = "exit";
		break;
		
		case "mangarosa_3":
			dialog.text = "�� ���������� ��� �������� ������ ��������, ����� ����������, �������� ������������ �������, � ����� ��������� � ������� � ��������� �����������, �������� ���� ������ � �����. �������� �� �����... ������������ ������. ������ ������ ������� �� ��� ������� ������.";
			link.l1 = "��� ���! � �� ������ ������� ���� �����? � ������ �������...";
			link.l1.go = "mangarosa_4";
		break;
		
		case "mangarosa_4":
			dialog.text = "�������, ������ - �� ����� ��� ����. �� ���������� � ��� ����, ������ ��� ����. �� ���� �� ������ - ����� ��������. �... ������ � �� ���� - ������ ������, � ������, �����... �����, ���� �������?";
			link.l1 = "�� �� ��������.";
			link.l1.go = "mangarosa_5";
			AddQuestRecordInfo("Recipe", "fennisgrasstotal");
			SetAlchemyRecipeKnown("fennisgrasstotal");
		break;
		
		case "mangarosa_5":
			dialog.text = "����� ������ ����. ��������� ����� ������������ � ��� ������ �����, ���� ����� �����������, � ��� ����� ����� ���� �����������. ������� ����� �������� ����������� ������� ���� ���� ��������. ��� ���-�� ���� � �����\n���� �� ������ ��� ���� ��������� - � ����� ����, ��� �� ����� � ��� ������. � ��� ��� ���������� �� ���, ����� ��� � ����� ���������� ��������� ����� �����.";
			link.l1 = "������. ���� �������� � �����������, ��� ����� ���� ��������.";
			link.l1.go = "mangarosa_6";
		break;
		
		case "mangarosa_6":
			RemoveItems(pchar, "cannabis7", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "����� �� ������. ����� ��� ���������, � ������ � ����� �������� �� ����, ���-�� �� ���-������ �����, ��� ������� ������ ����.";
			link.l1 = "��. � �������� �� ������ �������, ��� �� ���?";
			link.l1.go = "mangarosa_7";
		break;
		
		case "mangarosa_7":
			dialog.text = "�� �� �� �����, �������, � � ���. ����� ���������� ���, ��� � �������. �� ��� ������ ������ �� ������. ��� ��� ����� ���� �����-�� ����� - ������ ������ �� �����.";
			link.l1 = "�����, ����� ���-������...";
			link.l1.go = "mangarosa_8";
		break;
		
		case "mangarosa_8":
			dialog.text = "����� ����������� � ��� - ����������� ���� ��� ���� ���������, ����� ��� ���� �� ������ � ����� �������������, �� � �������� �������� �������� - �� ������� �� ��, ��� ��� ����� ����� ���� ���������!";
			link.l1 = "� ���� ���. ������� �� �������!";
			link.l1.go = "mangarosa_9";
		break;
		
		case "mangarosa_9":
			DialogExit();
			npchar.quest.mangarosa = "true";
			DeleteAttribute(pchar, "questTemp.Mangarosa.g_count");
			pchar.questTemp.Mangarosa = "amelia";
			pchar.questTemp.Mangarosa.Tell = "true"; // �������
			AddQuestRecord("Mangarosa", "4");
			// ������� � ������ ������
			sld = GetCharacter(NPC_GenerateCharacter("Amelia", "gipsy_3", "woman", "towngirl", 10, PIRATE, -1, true, "citizen"));
			SetFantomParamFromRank(sld, 10, true);
			sld.name = "������";
			sld.lastname = "";
			sld.dialog.FileName = "Quest\Mangarosa.c";
			sld.dialog.currentnode = "amelia";
			//sld.greeting = "";
			LAi_SetOwnerType(sld);
			LAi_SetImmortal(sld, true);
			ChangeCharacterAddressGroup(sld, "Amelia_house", "barmen", "stay");
		break;
		
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string GuessText()
{
	string sText;
	switch (drand(19))
	{
		case 0: sText = "������ ���� �������, ������ ���������� � ����� ������!" break;
		case 1: sText = "� ���������� ���� ���� ������� �����, �������!" break;
		case 2: sText = "� �������� ���� ������� ������, ������ ���� ���, ������� ��� ���!" break;
		case 3: sText = "����, ���������� ���� ������ ������ ������� �����, ���� � ��������� ��� �� ��������!" break;
		case 4: sText = "�����, ������� ������ � ������, ������� ���� ������. ��� ������ ������ �� ����������!" break;
		case 5: sText = "��������� ������ ������, �� ���-���� ����������� �� ���� � ������� �� ����������� ����, ��� ������ ������..." break;
		case 6: sText = "������ ���� �������, � ����, �� ���� � - �������, �������, ���� � �� �������� ���������, �� ���������� ����������� ���� � �������� ��� ������ ���������������." break;
		case 7: sText = "�� ������� � ������ ������, �������! ����� � �������, ��������." break;
		case 8: sText = "��� ������� ���� � ����� ���������, ������ �� ������ �������� ����� �� ����� �� ��������: ��, ���� �� ��� �������� �����, ���, �������� ���� ������������, � ����� ���������� �� �����������." break;
		case 9: sText = "���� �� ���� ���� ������� ���������� �����: �������� ���� ������ ����, �� ��� �����������, �������!" break;
		case 10: sText = "���� ���������� ������ ������� ���� ������� � ������, ���������� �� ��� ����������: ������ ���� ���� ��������." break;
		case 11: sText = "��� ������ ������� � �� ��� ����� � ��� ���� ���� ����������. ������ ������� ����, ����������, ������� � �������. �� ����� �� ������!" break;
		case 12: sText = "���� ��� ����������� ���� ������ � �� �������� ���������� ����������, ����������� �� ����� � � ����� ����������� ������ ���� ���� �����, �� �������� �!" break;
		case 13: sText = "���� ���������� ������ �� ����� ����� ������������, �� �� �����, ��� ����� �������� ����, ��, ����� ����, ����� �� ������, ������ ������." break;
		case 14: sText = "����� ������ � ��� ����, ������� ����� � ����� ���� � ��� ������� �� �����, � ���� ���������� ����������, ��, ��������, ���������� ��� ���� �������� ���� ��������." break;
		case 15: sText = "������� ���� ������� �������, �������, ������� ��������� ����� ��������� ���� �����, ��� �� ������ ������������ �� ����� ����� �������� ��������!" break;
		case 16: sText = "�� ���� � ���������� ������ ������� ���� ������������ ���������, � ���� ����� �������, ���� ������� �������� ����, ���� �����, ������ �� �������, �������. �����, ���� �� ������, �������� � ���� � ������ ����� ������������. ����, ���� ����� ������ � ����� ��� ����� ���������, �� ������ ����� ��������..." break;
		case 17: sText = "���� ���� � ���� �������, ��� �����, � ���� �����, ��� ������, ��� ����� �� ����� �������. ������� ���� � ������ ����� ���� ����." break;
		case 18: sText = "���� �������� �� ����� ���� �������, �������� ������� �����, � ����� ������� ������ �����." break;
		case 19: sText = "���������� ������ ���������� ���� ���� �� �� ������. ��� ��, ��� ���� ���� � ����, � �� ������ �� �����������." break;
	}
	return sText;
}
