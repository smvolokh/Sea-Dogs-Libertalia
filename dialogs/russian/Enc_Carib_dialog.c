void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, Diag;
	int i, iGun, iMush, qty;
	string sGroup, sLink, sText;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);
	int iTemp = sti(npchar.EncQty);
	string sTemp = "Carib" + locations[FindLocation(npchar.location)].index + "_";

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();			
		break;
		
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			Diag.TempNode = "First time";
		break;

		case "exit_fight":
			sGroup = "CaribGroup_" + locations[FindLocation(npchar.location)].index;
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_group_MoveCharacter(sld, sGroup);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			LAi_group_SetRelation(sGroup, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(sGroup, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(sGroup, "LandEnc_CaribAfrer");
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_peace":
			DialogExit();
			sGroup = "CaribGroup_" + locations[FindLocation(npchar.location)].index;
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_group_MoveCharacter(sld, sGroup);
				LAi_SetImmortal(sld, false);
				LAi_CharacterDisableDialog(sld);
			}	
			ChangeIndianRelation(0.25);
		break;
		
		// ������� ����� - ������
		case "war_indian":
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_type_actor_Reset(sld);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			if (sti(pchar.questTemp.Indian.relation) > 79)
			{
				dialog.text = LinkRandPhrase("�������������� ����, ��� ����! � ������� � ����. ������� �������� �� ��� �����.",""+npchar.name+" �������������� ����, ����������� ����. �� ���� ������ ���� ����� � ���.","������ ����, ������� ����������� ����! "+npchar.name+" ��� ������� � ���� ������. ������� � �����!");
				link.l1 = RandPhraseSimple("������ � ����, ����������� ����! ����� ����� ������ ���� �����!","�����������, ������� ����! �� �� ������� ���� ��������� ���� � ���� �����!");
				link.l1.go = "exit_peace";
				if (CheckCaribGuns())
				{
					npchar.quest.count = 0;
					link.l2 = RandPhraseSimple("� ���� ���� ��, ��� ��������� ����, ����������� ����. ���������?","� ���� ���������� ���� ���-��� ������, ������� ����. ����� ��������?");
					link.l2.go = "war_indian_trade";
				}
			}
			else
			{
				dialog.text = LinkRandPhrase("������, �����������! �� ������ ����� �� ������ ��� �����?","����, ����� �������! �� ���������� ����� ���� ������� � ��� �����!","����������, �������! ���� �� ����� �� ��� �����!");
				link.l1 = RandPhraseSimple("���� �����? � ��, ����� � ������, ����������� ��������!","�� ���� �� - ��������, � �������������! ����� �����!");
				link.l1.go = "war_indian_1";
				link.l2 = RandPhraseSimple("� ������ � �����, ����������� ����. �� � ���� ��� ����������� ��� �� ��-�� ����.","� �� ������� �� ���� �����, ����. � ������ � �����.");
				if (sti(pchar.questTemp.Indian.relation)+(makeint(GetSummonSkillFromName(pchar, SKILL_LEADERSHIP)/3)) > drand(80)) link.l2.go = "war_indian_2_1";
				else link.l2.go = "war_indian_2_2";
				link.l3 = RandPhraseSimple("� ������ ���� �� ������� � ����, � ���������.","� �� ���� � ���������. � � ���� ������.");
				if (sti(pchar.questTemp.Indian.relation)+(makeint(GetSummonSkillFromName(pchar, SKILL_LEADERSHIP)/6)+makeint(GetSummonSkillFromName(pchar, SKILL_FORTUNE)/6)) > drand(90)) link.l3.go = "war_indian_3_1";
				else link.l3.go = "war_indian_3_2";
			}
		break;
		
		case "war_indian_1":
			dialog.text = RandPhraseSimple("�� ��������, ��� �������� �� ���� ����, ����������� ������... � �������� ���� ������ � ��������� �����!","� ��������� ���� ���� ������, ��������� ���! �� �� ������� ������� � ������!");
			link.l1 = RandPhraseSimple("�� ��� �� ��������, ������ ��������? ��, � ������ ������ ���� ����� � �������, �� ������� �� ������...","�� ������ ��� ��������, �����? ������ �� �������� �� ������, � �������� ������ ����� ����...");
			link.l1.go = "exit_fight";
		break;
		
		case "war_indian_2_1":
			dialog.text = RandPhraseSimple("� ������� ���� ����� - �� �������� ������. �� �� �������� ����� ���� ������ ���� �������. ���� � �����, �����������.","����������� ����� ��������� � ��� �� ��� �����, �� � ������ ���� ����� - �� �� �����. ������.");
			link.l1 = RandPhraseSimple("�� �������� ���������, ����. ������.","� ���, ��� �� ������ ���� �����, ����.");
			link.l1.go = "exit_peace";
		break;
		
		case "war_indian_2_2":
			dialog.text = RandPhraseSimple("�� �����, ����������� ������! �� ��������� ���� ������� ������! ������ � ���, �������!","�� ������� ������. ���� ����������� - ������ ����. � ������� ��� � ��������� �����!");
			link.l1 = RandPhraseSimple("�� ��� ���, �� �� ��������, ��������. ����� ���, � ����� �� �����...","�� ��� ��, �� ��� ����������, ����-�����...");
			link.l1.go = "exit_fight";
		break;
		
		case "war_indian_3_1":
			if (CheckCaribGuns())
			{
				npchar.quest.count = 0;
				dialog.text = "���������? ��� ����� ������ �����������. ���������� �������� ������ �����������! �� ���� �� ���� �������� ��� �����! � ���� ���� �������� ������ �� �����?";
				link.l1 = "��. ����. � ��� �� ���� ��� ������?";
				link.l1.go = "war_indian_trade";
				link.l2 = "�� ��, �������! � ����� �� �� ���� �������� ������ ������������ ����������? �� �� ���, �� ������ ����! � ���, ������, � ������ ���� ��������...";
				link.l2.go = "exit_fight";
			}
			else
			{
				dialog.text = "� ���� ��� ��, ��� �� ������, �����������... �� ����� ��� ������� ������!";
				link.l1 = "��, ������, ������...";
				link.l1.go = "exit_fight";
			}
		break;
		
		case "war_indian_3_2":
			dialog.text = RandPhraseSimple("�� �� ��������� � ����������� ���. �� �������� �� � ��� ����!","�� �� ������ ������� ��� ������, �� �� ��������� � �������! �� ������� ������� � �������� ������� ������!");
			link.l1 = RandPhraseSimple("��, �������� �������� ����, �������!","������� ���� �������� ������� � ���� �����, ��������!");
			link.l1.go = "exit_fight";
		break;
		
		case "war_indian_trade":
			iGun = 1;
			dialog.text = "����������, ��� � ���� ����, � �� �������, ��� ���� ���� �� ���.";
			for (i=6; i>=1; i--)
			{
				if (GetCharacterFreeItem(pchar, "pistol"+i) > 0)
				{
					sLink = "l"+iGun;
					link.(sLink) = "���������� "+XI_ConvertString("pistol"+i)+".";
					link.(sLink).go = "gun_"+i;
					iGun++;				
				}
			}
		break;
		
		case "gun_1":
			npchar.quest.gun = "pistol1";
			if (drand(1) == 0)
			{
				npchar.quest.item = "potion"+(rand(2)+2);
				iTotalTemp = drand(1)+1;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ������� ������� �������� �����";
			}
			else
			{
				npchar.quest.item = "jewelry"+(drand(9)+14);
				iTotalTemp = drand(2)+1;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ��� ���� �������� ������";
			}
			dialog.text = "�-��! �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "gun_2":
			npchar.quest.gun = "pistol2";
			if (drand(3) < 2)
			{
				npchar.quest.item = "potion"+(rand(2)+2);
				iTotalTemp = drand(2)+2;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ������� ������� �������� �����";
			}
			else
			{
				npchar.quest.item = "jewelry"+(drand(3)+1);
				iTotalTemp = drand(2)+2;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ��� ���� �������� ������";
			}
			dialog.text = "�-��! ������ ������... �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "gun_3":
			npchar.quest.gun = "pistol3";
			if (drand(5) < 3)
			{
				qty = rand(1)+2;
				npchar.quest.item = "jewelry5"+qty;
				iTotalTemp = drand(6)+qty*15;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ��� ���� �������� ���������";
			}
			else
			{
				npchar.quest.item = "jewelry"+(drand(2)+2);
				iTotalTemp = drand(2)+5;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ��� ���� �������� ������";
			}
			dialog.text = "�-��! ��� ������� ������! ���� ����� �����-����� ������! �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "gun_4":
			npchar.quest.gun = "pistol4";
			if (drand(9) < 8)
			{
				qty = rand(1)+1;
				npchar.quest.item = "jewelry"+(qty+4);
				iTotalTemp = drand(10)+qty*30;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ����� ���� ������, ������� ����������� ������ ������ �����";
			}
			else
			{
				npchar.quest.item = "obereg_"+(drand(10)+1);
				iTotalTemp = 1;
				sText = "��� ���� ������";
			}
			dialog.text = "�-��! �������� ������! �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "gun_5":
			npchar.quest.gun = "pistol5";
			if (drand(7) < 7)
			{
				if (drand(10) < 8)
				{
					npchar.quest.item = "jewelry7";
					iTotalTemp = 2+drand(1);
				}
				else
				{
					npchar.quest.item = "jewelry8";
					iTotalTemp = drand(4)+10;
				}
				qty = drand(1)+1;
				npchar.quest.item = "jewelry"+(qty+6);
				if (qty == 1) iTotalTemp = 2;
				else iTotalTemp = drand(5)+qty*15;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ��� ���� �������� � ������ �������� �����";
			}
			else
			{
				npchar.quest.item = "indian_"+(drand(10)+1);
				iTotalTemp = 1;
				sText = "��� ���� ������";
			}
			dialog.text = "�-��! �������� � ������ ������! �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "gun_6":
			npchar.quest.gun = "pistol6";
			if (drand(9) < 8)
			{
				qty = rand(1)+1;
				npchar.quest.item = "jewelry"+(qty+4);
				iTotalTemp = drand(8)+qty*20;
				sText = ""+FindRussianQtyString(iTotalTemp)+" ����� ���� ������, ������� ����������� ������ ������ �����";
			}
			else
			{
				npchar.quest.item = "amulet_"+(drand(10)+1);
				iTotalTemp = 1;
				sText = "��� ���� ������";
			}
			dialog.text = "�-��! ������� ������! �� ���� ���� �� ���� "+sText+".";
			link.l1 = "�� �����!";
			link.l1.go = "war_indian_trade_agree";
			link.l2 = "���. �� ������.";
			link.l2.go = "war_indian_trade_bad";
		break;
		
		case "war_indian_trade_agree":
			ChangeIndianRelation(0.3);
			npchar.quest.count = sti(npchar.quest.count)+1;
			TakeNItems(pchar, npchar.quest.item, iTotalTemp);
			RemoveItems(pchar, npchar.quest.gun, 1);
			Log_Info("�� ������ "+XI_ConvertString(npchar.quest.gun)+"");
			Log_Info("�� �������� "+XI_ConvertString(npchar.quest.item)+" � ���������� "+FindRussianQtyString(iTotalTemp)+"");
			PlaySound("interface\important_item.wav");
			if (sti(npchar.quest.count) > 3+drand(2));
			{
				dialog.text = "������. ��� ���� �����. ������ �� �� ������. ��������� �����. ��� ����� �������� ������ - ��� ������ �� ��� ������. ������!";
				link.l1 = "������, ����������� ����.";
				link.l1.go = "exit_peace";
			}
			else
			{
				dialog.text = "������. ��� ���� �����. � ���� ���� ��� �������� ������ �� ������?";
				if (CheckCaribGuns())
				{
					link.l1 = "����. ������ ��������?";
					link.l1.go = "war_indian_trade";
				}
				link.l2 = "���� ���. � ��������� ��� ������� ���.";
				link.l2.go = "war_indian_trade_exit";
			}
		break;
		
		case "war_indian_trade_exit":
			dialog.text = "���������. ��� ����� �������� ������ - ��� ������ �� ��� ������. ������!";
			link.l1 = "�� �������, ����...";
			link.l1.go = "exit_peace";
		break;
		
		case "war_indian_trade_bad":
			if (sti(pchar.questTemp.Indian.relation) > 79)
			{
				DialogExit();
				sGroup = "CaribGroup_" + locations[FindLocation(npchar.location)].index;
				for(i = 0; i < iTemp; i++)
				{
					sld = CharacterFromID(sTemp + i);
					LAi_SetWarriorTypeNoGroup(sld);
					LAi_group_MoveCharacter(sld, sGroup);
					LAi_SetImmortal(sld, false);
					LAi_CharacterDisableDialog(sld);
				}	
			}
			else
			{
				dialog.text = "����� �� ������� �� � ������ ���, �������!";
				link.l1 = "��, ��������...";
				link.l1.go = "exit_fight";
			}
		break;
		
		// ������ ����� - �������
		case "peace_indian":
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_type_actor_Reset(sld);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			dialog.text = LinkRandPhrase("����������, ����� �������. ��� ���� ����� � ���� �������?","���� ������� ����� ���������. ��� �� ������ ���?","��� �������� ���� ����, ������� �����������?");
			link.l1 = RandPhraseSimple("� ������ ������� ����, ����������� ����. �������, �� ���� ����� ��� ����� ������ �����?","�����������, ��� ��������! ���� ������� ���� ����. �� � �� ������� � ���������.");
			link.l1.go = "peace_indian_1";
			link.l2 = RandPhraseSimple("� ���� �� ����� ����� ����? ��� ����� ������� � �� ���������!","����� ���� ������, �����������. ��� �� �� ����� � �����.");
			link.l2.go = "peace_indian_2";
		break;
		
		case "peace_indian_1":
			dialog.text = RandPhraseSimple("�� ������ �����. �� �� ���������� ����� �������. ������, �� ���� �������� �� ���� �����!","� ��� ������ ����������� - ���� ������. ������� � ���, ��� ����!");
			link.l1 = RandPhraseSimple("� ���� �����, ��� ������...","������, ����������� ����.");
			link.l1.go = "exit_peace";
		break;
		
		case "peace_indian_2":
			dialog.text = RandPhraseSimple("�� ������ ������ ��������. �� �� �������, ����� ��� ��� �������� �� ��� �����!","�� �� ������� � �����, �� ���� ����� �������� ������ ��� ����� ��� ����� - �� �������� ���, ��� ����� ���� ������!");
			link.l1 = RandPhraseSimple("�� ��� �� ��������, ����������� ��������? ��, � ������ ������ ���� ����� � �������, �� ������� �� ������...","�� ������ ��� ��������, �����? ������ �� �������� �� ������, � �������� ������ ����� ����...");
			link.l1.go = "exit_fight";
		break;
	}
}