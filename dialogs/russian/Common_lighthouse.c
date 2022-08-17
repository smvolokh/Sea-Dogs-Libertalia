#include "DIALOGS\russian\Rumours\Common_rumours.c" //Jason
// Jason ����� ������ ����������� ������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;	

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Lighthouse\" + NPChar.City + "_Lighthouse.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
    int iTest, iTemp;
	string sTemp;
	bool ok;
    iTest = FindColony(NPChar.City); // �����
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	switch(Dialog.CurrentNode)
	{
		case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("� ������ ������� �������. ������, � ��� ���� ������� �� ������...", "�� �� �� ����� �� ������� ��� ��������� ������?.. �� ���, �������!!!", "� ���� ������ �� �� �������. ���� ������� ��������� ������ �������� ����� ��� �����!"), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������! ������!!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = PCharRepPhrase(RandPhraseSimple("������, ���� ���� �������...", "���, � �� ������� �� �������� ������ ��������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + "!"), 
					RandPhraseSimple("����������� � ��!", "���, ���� ���� �������� ��������� ������..."));
				link.l1.go = PCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = RandPhraseSimple("������ ����, �����! ���� ����� "+GetFullName(npchar)+", � � - ���������� ����� �����. ����� ������ ��� ���� �������?", "������������! ��������� � �� ����� ����� ��� �� ���� �����... ��������� ������������� - "+GetFullName(npchar)+", � ���� ���� - ��� ��� � ��� ������. ��� ���� �������?");
				link.l1 = "����������, "+npchar.name+"! ��� ��� - "+GetFullName(pchar)+", � ������� �������. ����� �� ���� �������� �����, ����� ���������, ���������� - ��� ��� �����...";
				link.l1.go = "Lightman_meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� ������ ��������, ������� "+GetFullName(pchar)+"! ���������, ���������! ��� ������� ��� �� ��� �� ���� ���?";
				link.l1 = "�����������, ������ ������� ����! �� ��� �� ����� �� ����������� �� ����� �����?";
				link.l1.go = "Lightman_talk";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "Lightman_meeting":
			dialog.text = "�� ���, ������ ������ �����. � ���� �����, ��� � ��, ������, ����� ��� �� ������ �� ������ �������... ��! ������ ��� ������ - ���� ����. � ����� ������������� ������ ��������...";
			link.l1 = "� ��� �� ��������, ����� ����������?";
			link.l1.go = "trade_info";
			NextDiag.TempNode = "First time";
		break;
		
		case "Lightman_talk":
			dialog.text = "��� ������� ��� �� ��� �� ��� ���?";
			link.l1 = RandPhraseSimple("�� ����������, ��� ����������� � ����� ������� ��������� �� ��������� �����?","����� �� ��� �� ����... ��� ���������� � ����� �����?");
			link.l1.go = "rumours_lighthouse";
			link.l2 = "����� ���������, ��� � ���� ���� ������� � �������.";
			link.l2.go = "Trade_lighthouse";
			if (CheckAttribute(npchar, "artefact"))
			{
				if (CheckAttribute(npchar, "quest.art"))
				{
					link.l3 = "�� ���, "+npchar.name+", ��� ������ ��� �� ��������?";
					link.l3.go = "Trade_artefact_3";
				}
				else
				{
					link.l3 = ""+npchar.name+", � ���� �������� � ���� ������.";
					link.l3.go = "Trade_artefact_1";
				}
				// �������
				if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "amulet" && !CheckAttribute(npchar, "quest.Caleuche"))
				{
					link.l5 = "��������, "+npchar.name+", � ����, ��� �� ����������� �������� �������� ��� �����. ������, �� ��������� � ��� ������ ������������. ��������, ����������, �� ��� ������ - ��� �� ������ ������� � ���?";
					link.l5.go = "Caleuche";
				}
				if (npchar.id == pchar.questTemp.Caleuche.Amuletmaster && CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "mayak")
				{
					link.l5 = "��������, � ����� � ���� �� ������ ��� �������� ��������.";
					link.l5.go = "Caleuche_9";
				}
			}
			link.l4 = "� ��� ��� "+ GetSexPhrase("�����","������") +" ��������...";
			link.l4.go = "quests";
			link.l9 = "������ �� ������ ��������...";
			link.l9.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "trade_info":
			dialog.text = "����� �� ������� � ���� �� ����������. ����� �������� ���� �������� ��������. ��� ��� � ���� ������ ����� ������ ���������. ����� ������� ������ � ������ ���� ���� - ���� ����������� �� ����� ����� ������ - ��� � ���� ������, ���� ����� ������ - ��������\n������ ����� ���������� ������ �������� ������ � ��������� ��������, �� � ��� ������ �������� �������� �������� �� �������, �� ���� � �������� ���������� ������������ ������� - �� ��� ����� �������� � �������� �������� ������� �����\n������ ��� ��������, ��� � ��� ������ ��... ��, ������� ���, ����� � ������ ������. ������ ���� � ���� �������� ��������� ��������, � ��������� ���������� � ������� � ������� � ��������� �� �������\n� ��� ������ ������ - ���� ���������� ���. ������ �� ��� ������� �����, ��� � ������ �� ��� ���� �� ������ �������, � �������������� �������� ��� ����������� ��������. �� �������� �������� �� ������ � ���������� ������ � ������� �� ������. � ����� ������� ������������� ���� �� ������ �������, ��� ��� ���������.";
			link.l1 = "��������, "+npchar.name+", �� ������, ��� � ���� ���� ������ ������-������, ������� �������� ���� ������������ �������. � ������ �� �������� ���� ���������� ������? � ������ �������.";
			link.l1.go = "Trade_artefact";
		break;
		
		case "Trade_lighthouse":
			PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(20) + ".wav");
			//������ ������� ����������� ������ // Addon-2016 Jason
			npchar.quest.goods = GOOD_COFFEE + drand(sti(GOOD_PAPRIKA - GOOD_COFFEE));
			npchar.quest.goodsqty = 50+drand(100);
			if (sti(npchar.quest.goods) == GOOD_EBONY || sti(npchar.quest.goods) == GOOD_MAHOGANY) npchar.quest.goodsqty = 25+drand(50);
			npchar.quest.goodsprice = makeint(sti(Goods[sti(npchar.quest.goods)].Cost)/4);//���� ������� ������
			npchar.quest.goodscost = sti(npchar.quest.goodsprice)*sti(npchar.quest.goodsqty);//��������� ������
			ok = (!CheckAttribute(npchar, "goods_date")) || (GetNpcQuestPastDayParam(npchar, "goods_date") >= 10)
			if (drand(4) == 1 && makeint(GetCharacterFreeSpace(pchar, sti(npchar.quest.goods))) > sti(npchar.quest.goodsqty) && sti(pchar.money) >= sti(npchar.quest.goodscost) && ok)
			{
				dialog.text = "�������, ��� ������� �� ����� ��������� ��������� ���������� ������ - " + GetGoodsNameAlt(sti(npchar.quest.goods))+ ". ����� ���� ��������� ������� �����, �� " + FindRussianQtyString(sti(npchar.quest.goodsqty)) + " ��� ������� ��������� � �������� ���������. �� ������� �� ������? ������ �����, ����� �� "+FindRussianMoneyString(sti(npchar.quest.goodsprice))+" �� �����.";
				link.l1 = "���, �� �����. ���������, ��� �� ��������� �� �������.";
				link.l1.go = "Trade_lighthouse_double";
				link.l2 = "��... ������� �����������, � ��������. �����, � ��� ����� ���������� ��� � ������� ��� ����. ���, ���������... � ����� ��� �������� "+FindRussianMoneyString(sti(npchar.quest.goodscost))+". �� ���������?";
				link.l2.go = "Trade_goods";
				SaveCurrentNpcQuestDateParam(npchar, "goods_date");
			}
			else
			{
				DialogExit();
				if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
				{
					GiveItemToTrader(npchar);
					SaveCurrentNpcQuestDateParam(npchar, "trade_date");
				}
				LaunchItemsTrade(npchar, 0);
			}
		break;
		
		case "Trade_lighthouse_double":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
		break;
		
		case "Trade_goods":
			AddCharacterGoods(pchar, sti(npchar.quest.goods), sti(npchar.quest.goodsqty));
			AddMoneyToCharacter(pchar, -sti(npchar.quest.goodscost));
			AddMoneyToCharacter(npchar, sti(npchar.quest.goodscost));
			dialog.text = "�� ����� ����������, �������. �������� ������! �� ��� � ������� �� ��������...";
			link.l1 = "��� � ������������. ������ ������ ��������. � ������ ���������, ��� �� ��������� �� �������.";
			link.l1.go = "Trade_lighthouse_double";
		break;
//------------------------------------------------����� ����������------------------------------------------------
		case "Trade_artefact": // Addon-2016 Jason �� �������
			if (CheckAttribute(npchar, "artefact"))
			{
				dialog.text = "��, �� ��� �������, �� ���-����� ������ ��� �������� ���� ������, ��� ���, �����, ����� ��� ������. ����� ������������: ��������� ������ ������� ��� ����� - 100 ��������. ���� ���������...";
				link.l1 = "���� ���� �� ������. � ����� ������� �� ������� �������?";
				link.l1.go = "Trade_artefact_1";
				link.l2 = "�� ��! ���������� �������. ����� � �� ���-������ ���...";
				link.l2.go = "exit_artefact";
			}
			else
			{
				dialog.text = "���, �������. ��� ������ ������� ��������, ��� �� ����� �������� ��� �����? �� � ����� �������� �� ������� ������� �������...";
				link.l1 = "��, ��� ���������, �� ��� - � ���� ���...";
				link.l1.go = "exit_artefact";
			}
		break;
		
		case "exit_artefact":
			if (CheckAttribute(npchar, "artefact")) dialog.text = "��, ��� ������. ��������� - �����������.";
			else dialog.text = "������ ��������, ��� � ���� ���� ������� � �������, �������? ���� ������ ���������� �� ������� - �������� ���, ������, �����, ��� ������������ ��� � ��������.";
			link.l1 = "������ ��� ���� ������.";
			link.l1.go = "Trade_lighthouse";
			link.l2 = RandPhraseSimple("����� ��������, ��� ����������� � ����� ������� ��������� �� ��������� �����?","��������-���������, � ��� � ��������� �� ��� �� ����... ��� ���������� � ����� �����?");
			link.l2.go = "rumours_lighthouse";
			link.l3 = "�� ���, �������, ������, �� � ��� ��� "+ GetSexPhrase("�����","������") +" ��������...";
			link.l3.go = "quests";
			link.l4 = "����� �������, "+npchar.name+"! ������� ���� �������������! ��� �������...";
			link.l4.go = "exit";
		break;
		
		case "Trade_artefact_1":
			dialog.text = "���������.";
			iTemp = 1;
			string sArt;
			if (CheckAttribute(npchar, "artefact.indian")) sArt = "indian_";
			if (CheckAttribute(npchar, "artefact.amulet")) sArt = "amulet_";
			if (CheckAttribute(npchar, "artefact.obereg")) sArt = "obereg_";
			for (i=11; i>=1; i--)
			{
				sTemp = "l"+iTemp;
				link.(sTemp) = XI_ConvertString(sArt+i);
				link.(sTemp).go = sArt+i;
				iTemp++;
			}
			link.l12 = "� ���������, ������ �� ����� ������ ���� �� ����������.";
			link.l12.go = "exit";
		break;
		
		//������ indian
		case "indian_1":
			dialog.text = "����� ����? �������� ������������� ������? ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_1";
		break;
		
		case "indian_2":
			dialog.text = "��������� ������? ������ �������� - ����� ������ � �������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_2";
		break;
		
		case "indian_3":
			dialog.text = "���������� ���? ������ �� ���� �������� ������ ����� ������� �������? ����� ��� ����� ��� ���. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_3";
		break;
		
		case "indian_4":
			dialog.text = "������? ��� �������� �����, ��� �������� ������ ���� ����������� �������! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_4";
		break;
		
		case "indian_5":
			dialog.text = "�������? ��� ������ ��������� ���� ������ ���������� ������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_5";
		break;
		
		case "indian_6":
			dialog.text = "���������� ������? ����� ������� �� ����� ����� ����� ������ ����� � ����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_6";
		break;
		
		case "indian_7":
			dialog.text = "������? ������������ - ��� ������ ���� �����. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_7";
		break;
		
		case "indian_8":
			dialog.text = "����������? ������ ������ ���������� ����� ���������� � �����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_8";
		break;
		
		case "indian_9":
			dialog.text = "�����? �������� ����� - � ����� ��� ���� ����� ����� � ����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_9";
		break;
		
		case "indian_10":
			dialog.text = "���������? ��� ������ �������� �������� ���. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_10";
		break;
		
		case "indian_11":
			dialog.text = "����� ������? ������ � ����� ������������ ������, ��-��! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "indian_11";
		break;
		
		//������ amulet
		case "amulet_1":
			dialog.text = "��� ������? ���� �� ������� ���������� �� ����, ���� ������ ����� ������ �����. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_1";
		break;
		
		case "amulet_2":
			dialog.text = "�����������? ������ ������� �������� ���� ���� ������� � �������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_2";
		break;
		
		case "amulet_3":
			dialog.text = "��������� �����? �� ������� ������� ����������� � ���������� �������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_3";
		break;
		
		case "amulet_4":
			dialog.text = "��� �����? �� ������ ����������� ���� ������ ���������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_4";
		break;
		
		case "amulet_5":
			dialog.text = "�����? � ����� ����� ����� ������ ������ � ���! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_5";
		break;
		
		case "amulet_6":
			dialog.text = "�������? ����� ��������� ���� �������� �������� ����������� �������������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_6";
		break;
		
		case "amulet_7":
			dialog.text = "������ ����? ���� �����, ������������ ������ �����, ���������� ���������! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_7";
		break;
		
		case "amulet_8":
			dialog.text = "�����? � ����� ����� �������� �� ����� ��� ������ ����, ��-��! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_8";
		break;
		
		case "amulet_9":
			dialog.text = "���������? ������� ����� �� ������� �������, ���� � ��� ���� ���� ������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_9";
		break;
		
		case "amulet_10":
			dialog.text = "����������? �� ������ ������� ���� ������� �� ���� � �� ����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_10";
		break;
		
		case "amulet_11":
			dialog.text = "��������? ��������� ���� ���������� ��� ��������, �� �������� �����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "amulet_11";
		break;
		
		//������ obereg
		case "obereg_1":
			dialog.text = "������? ������ ����������� ������� ������� � ���. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_1";
		break;
		
		case "obereg_2":
			dialog.text = "��������? �� ������ ������ ������ �����, ������ ������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_2";
		break;
		
		case "obereg_3":
			dialog.text = "��������? � �� ��� ��� - ������� ���! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_3";
		break;
		
		case "obereg_4":
			dialog.text = "���� �������? ������ ���� �� ����� �������! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_4";
		break;
		
		case "obereg_5":
			dialog.text = "���������� ���������? ��� ��� ������ � ������ ����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_5";
		break;
		
		case "obereg_6":
			dialog.text = "��������� �����? ��� ��������� - ������� ������� ����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_6";
		break;
		
		case "obereg_7":
			dialog.text = "�����? ��� ����� �� ��� ������ �������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_7";
		break;
		
		case "obereg_8":
			dialog.text = "����� ��������? ������ ����� ����, �� ������ ��? ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_8";
		break;
		
		case "obereg_9":
			dialog.text = "��������? ����� ���������� ������ ������� ������� �����! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_9";
		break;
		
		case "obereg_10":
			dialog.text = "������ ��������? �������� �� � ��� ������ ��������! ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_10";
		break;
		
		case "obereg_11":
			dialog.text = "��������? ��������� ����� ���������� ��������. ������...";
			link.l1 = "����� ��� ��������� � ���� �� ����� �������?";
			link.l1.go = "Trade_artefact_2";
			npchar.quest.art = "obereg_11";
		break;
		
		case "Trade_artefact_2":
			dialog.text = "������ ����� ���, �� ������. �����, � ���� ������� ��� ��� ��� ��������. ��� ��� ��� ��� � ����� ������� � ��������.";
			link.l1 = "������! ����������� ����! �������, "+npchar.name+"!";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(npchar, "art_date");
			npchar.quest.artday = rand(20)+50;
			sTemp = "Amulet_"+npchar.location;
			AddQuestRecord(sTemp, "1");
			ReOpenQuestHeader(sTemp);
			AddQuestUserData(sTemp, "sAml", XI_ConvertString(npchar.quest.art)); // dlc
		break;
		
		case "Trade_artefact_3":
			if (CheckAttribute(npchar, "art_date") && GetNpcQuestPastDayParam(npchar, "art_date") >= sti(npchar.quest.artday))
			{
			dialog.text = "��, �� � ����. �� ����������� 100 ��������, �������?"; // Addon-2016 Jason
				if(GetCharacterItem(pchar, "gold_dublon") >= 100)
				{
					link.l1 = "�������! ���, �����, ��� � ��������������.";
					link.l1.go = "Trade_artefact_4";
				}
				else
				{
					link.l1 = "��, ������ �� ������� �����! ������ �������...";
					link.l1.go = "exit";
				}
			}
			else
			{
			dialog.text = "��� ���. ��������� �� ��� ������� � �� ������������ - �������� �����������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			}
		break;
		
		case "Trade_artefact_4":
			RemoveItems(pchar, "gold_dublon", 100); // Addon-2016 Jason
			Log_Info("�� ������ 100 ��������!");
			dialog.text = "���, ��� �����. ���, �������� ��� ������. ����������� �� ��������!";
			link.l1 = "�������, "+npchar.name+"!";
			link.l1.go = "Trade_artefact_5";
		break;
		
		case "Trade_artefact_5":
			DialogExit();
			Log_Info("�� �������� "+XI_ConvertString(npchar.quest.art)+"");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, npchar.quest.art, 1);
			DeleteAttribute(npchar, "quest.art");
			sTemp = "Amulet_"+npchar.location;
			AddQuestRecord(sTemp, "2");
			CloseQuestHeader(sTemp);
		break;
		
		// --> �������
		case "caleuche":
			PlaySound("interface\important_item.wav");
			dialog.text = "���������, ��� ��� � ����.";
			link.l1 = "���, ������ �� ��������� ��������� ������. �� ������ ��� ���� �� ����� ���� ����� - ��� �� �������.";
			link.l1.go = "caleuche_1";
			npchar.quest.caleuche = "true";
		break;
		
		case "caleuche_1":
			if (npchar.id == pchar.questTemp.Caleuche.Amuletmaster)
			{
				dialog.text = "���-���... �� ��� ������, ��� ���������� ��� ����� ���������. ���� ������, ��������, ����� ���� �� ����� ������ ������ �����. ���-�� ���, ������, ����� ������, � �������� ���, ����� �������, ������� ����� ������� �� ���� �������. ���� ����������� �������, ��� ��� �������� �� '������� �������'\n��� �� ������� ������, � ����� �������� ��� �� �������� - � �� �����. �� ���� ���� �����, � ���� ����������� ���������. ���� ��� ���������?";
				link.l1 = "�������!";
				link.l1.go = "caleuche_2";
			}
			else
			{
				dialog.text = "��... ������ � ����� ����� ������ �������� � ����� �����, �� ����� �� ������� ������� �������. ������, �������, ����� ������ �� ���� - ��� �� ����, ��� ��� �� ��������. �� ��, ��� ���� �� ������� - ����. ������ ��� � ����-������ - �����, ���-�� �������� ��������.";
				link.l1 = "����... ���� ���������� ������ - �������, �������.";
				link.l1.go = "exit";
			}
		break;
		
		case "caleuche_2":
			dialog.text = "�� �������� ���� ������� ������� ��������� ����� ���� ������. � ��� ���� ����� �� ����� ������������, ����� ��������� ������. �� �� �� �������, � ��� ��� �� ��� ����, ��� ������� � ���� ������. ��-�� ��������� ������ �������� �� ���� ������� �������� ����. �� ���� ��������� - ������������ ����� �� ����� �����. �����. ���� ��� �����-�� ������� ��� � ������� � ������ �� ������ ����...";
			link.l1 = "������, �� ������ ����� ������� � ����� �� ������?";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "��. ��� ����� ���������� �������... �����, �� ������� ���������� ��������-�����, ������ � ������� ����� � ������� ����� �������, � �������� ������� ������ �� ��������� ���� �� ��������� �������� ���������. �� �� ���� ������-��� �� �������!\n� ����� ������� �������� � ������ ���� �������. � ����� ������� ������� � �������� ��������� �� ������� � �������� ����� ���� ��������. ��� �������, ��� ��� � ��� ��������?";
			link.l1 = "�����������...";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "���-���. �� ���� ��� ���� �� ����� ���� ����, ���� ��� �� ����� ����� ����������� ������ ����� �� ����, ������ �� ������� � �������������� �� ��������. ���� ������ ����� ���� � ����� ������. ���� ������� � ���� - ���� ���� ������� � ����� �� ���, ��� �������� - ����� ���� ����. � ��� ���������� � ���� �� ����� - �� ���� �� ������ � ����� �������������.";
			link.l1 = "� ��� �� ���������� ��� �����?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "������ ������� �� ��� �� ������. ��� � ������, �� ���������� ����� ������-������� �������� � ����� ������������� ������. ������� ��� � ������� ������ - �����, �� ���������� � ������ ���� ������� ������ ��������.";
			link.l1 = "�������! ��� � ������... �����, ��������, � ������ �� ��� ��� ������?";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "��� ���� ��� �������� �� ��� ����������� �������. �� �������, ��� ������� ������ � ��� ��� ���������... � ���� � � ������ � ������ ��� ���������� � ����� ��������, ��� �� ����� ������� - ������, ������ � ��������� ������� �������� ��������� ��� � �� �����. ������, ��� � ���� ������ �� ��� ��������� - ����� ������� ��������� � ������� �����, ������� ��� �������, � ����� ���������� ������� � �����.";
			link.l1 = "����. ����� ��� �������� ������ ����������� � �������� �� ��������. ������� �� ������ � �� ���������� �������!";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "�����, �������, � ���� ��������� � ���� ����������� ��������...";
			link.l1 = "...";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			DialogExit();
			AddQuestRecord("Caleuche", "2");
			pchar.questTemp.Caleuche = "dominica"; 
			Caleuche_CreateShamane();
		break;
		
		case "caleuche_9":
			dialog.text = "��? �� ��� � �������������?";
			link.l1 = "�����. � ������ � ���� ����� ��� ��� �������. �� �� ����� �������, ��� � ������, ��� ���� ����� �������� �������. � ��� ���� ��� ����?";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			dialog.text = "���� - ��� ��� ����, ��� ����� ������ � ������� �������������, �� ������� �������� �������������. � ���� ������ �� ������ � ���� �� �����. � ��� ����� �� �����, �� ����, ��� �� ����������. ��� ��� �� �������� ����� � ������ - �� ��������� ��������� � ������ ������� �� ��������. ��� - ������ �����.";
			link.l1 = "�������. � ������?";
			link.l1.go = "caleuche_11";
		break;
		
		case "caleuche_11":
			dialog.text = "��� ������� � ���� �������. ��� ����� �� �� ����, �� �� �������, � �� �� �� �����, �� �� ������ �����, �� �� ������ ����������. � ���� ������ � �����-�� �������� ������... �-�-�... ��� �� ���������� ��� �������? ���� ������, �����! �� ������ �����-�� ���������. � ������� ���, ��� ��� ��������, � �� ������, ��� ��� �����������-���������, ��������� �������� ����������. ���� ��, ��������...";
			link.l1 = "��� ����� ���������... ��� �������� ������ �� �� �������?";
			link.l1.go = "caleuche_12";
		break;
		
		case "caleuche_12":
			dialog.text = "���, ������� ���� ����, �� �����. �, � ���: ����� �� ������������� ���, �� ������, ��� �� � ���������.";
			link.l1 = "��� ���-��! �����, �������� ��������� ����� �������� �������� ������, ���� ��� �� ����� ���-��� ������... �������, �������, �� ��� ����� �����!";
			link.l1.go = "caleuche_13";
		break;
		
		case "caleuche_13":
			dialog.text = "�� �� ���, ���, ��������� ���, ���������.";
			link.l1 = "������� �����������!";
			link.l1.go = "caleuche_14";
		break;
		
		case "caleuche_14":
			DialogExit();
			AddQuestRecord("Caleuche", "7");
			pchar.questTemp.Caleuche = "hunting"; 
			pchar.questTemp.Caleuche.Belizterms = rand(4)+3;
			pchar.quest.caleuche_prepare_beliz.win_condition.l1 = "location";
			pchar.quest.caleuche_prepare_beliz.win_condition.l1.location = "Beliz";
			pchar.quest.caleuche_prepare_beliz.function = "Caleuche_PrepareBeliz";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Man_FackYou"://������� �� ������� ������� � ������
			dialog.text = LinkRandPhrase("�� �� "+ GetSexPhrase("���, ��������! ������, ����� ���","�������! ������, ����� ��") +"!!!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ����� "+ GetSexPhrase("����","�������") +"!!!", "������! ������!!! ����� "+ GetSexPhrase("����","�������") +"!!!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
	}
}