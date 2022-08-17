// ������ ���������� �����
void ProcessDialogEvent()
{
	int amount, iGunQty, iGunGoods, iGunPrice, iTemp;
	int iTest;
	ref NPChar, sld, location;
	ref arItem;
	ref rColony;
	aref Link, NextDiag;
	string sTemp;
	float locx, locy, locz;
	bool  ok;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
   /*NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Prison\" + NPChar.City + "_Prison.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}*/
    // ����� ������� �� ������� <--

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "NoMoreTalkExit":
			LAi_CharacterDisableDialog(npchar);
			DialogExit();
		break;
		
		case "First time":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			location = &Locations[FindLocation(pchar.location)];
			if (rand(4) == 4 && GetNpcQuestPastDayParam(location, "gun_date") > 365 && !CheckAttribute(pchar, "questTemp.PrisonGun"))
			{
				dialog.text = RandPhraseSimple(RandPhraseSimple("����������, � ���� � ��� ���� ���� ������ ����. �������, ������� ������...","�������, � �� ������������ �� ��� ��������� ������ ���������� �����������?"), RandPhraseSimple("� ��� �������, ��� �� ����� �� ��� ������ � ����� ������ ������ �������.","�������, � ���� � ��� ���� ���� ���������� �����������, ������� ����� ���� �������� ��� ��� �����."));					
				link.l1 = "���������, ��������� ������...";
				link.l1.go = "GiveTaskGun";
				location.quest.PrisonGun = "Target"; 
				SaveCurrentNpcQuestDateParam(location, "gun_date");
				break;
			}
		
			dialog.text = RandPhraseSimple("� ��������� �����. ��� ��� ����� �����?", "��� ��� �����? ����� �� ������� � ����?");
			link.l1 = "�� ������ ����������, ���������� �����, ������ ��. ��� � ������ ���� �� ������.";
			link.l1.go = "exit";
			//Jason --> ����-����� ���������� �����
			if (CheckAttribute(pchar, "questTemp.Wine.bottle") && NPChar.location == pchar.questTemp.Wine.City + "_ammo" && GetQuestPastDayParam("questTemp.Wine_bottle") < 5)
			{
				link.l11 = "� ���� � ��� ����, ������. �����, ��� ��� ������������. ���� �� ����� ������, "+pchar.questTemp.Wine.SName+" ������� ����� ��� �������������� ������ ���� � ������. ���� ���� �������...";
				link.l11.go = "Wine_prison";
			}
			// <-- ����-����� ���������� �����
			// ��������� �����
			if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "fraht" && NPChar.location == "portpax_ammo")
			{
				link.l11 = "������������, ������. � ������ �� ������� ���-���, �� �������� �� ����� ����� ������. � ����� ����� ������� ���� ������ � ���� ��� ���...";
				link.l11.go = "trial";
			}
			NextDiag.TempNode = "First time";
		break;

		// --> ������ ��� �����
		case "GiveTaskGun":
			dialog.Text = LinkRandPhrase("���� � ���, ��� ������ ������ ����� ������� ��������. �����, ������, �������� ������ �� �� ������, �� ��� ���������� ����� - � ������ � ��������������: � ����� ������� ���������� ���������� ������ ��� ����������. ��� � � �������, ��� ����������� ������ � �������������� ���� ������ ����� ���� ����� ����� ������.","��� ����� �������� ��������� ������� �����. ������ �� ��� ��������, ��, ������ ��... � ����� ������� ���������� ���������� ����������� ����������.","��� ������ ����������� �������� ���������� ������ �����, �� � ���� ����� ���� - ����� �� ���� ������� ������������ ����������.");
			Link.l1 = "��, � ����� ��������� - ������, ����������... ����, �������.";
			Link.l1.go = "GiveTaskGun_1";
			pchar.questTemp.PrisonGun = true;
			SaveCurrentQuestDateParam("pchar.questTemp.PrisonGun");
		break;
			
		case "GiveTaskGun_1":
			GetGunType();
			pchar.questTemp.PrisonGun.Sum = makeint(sti(pchar.questTemp.PrisonGun.Price)*sti(pchar.questTemp.PrisonGun.Qty));
			pchar.questTemp.PrisonGun.Luck = rand(4);
			pchar.questTemp.PrisonGun.Id = npchar.location;
			dialog.Text = "��� ���������� "+ pchar.questTemp.PrisonGun.Text +", � ���������� ����� " + sti(pchar.questTemp.PrisonGun.Qty) + " ����. ��������� ����� �������� ���������, �� "+ sti(pchar.questTemp.PrisonGun.Price) +" �� �����. ����� ��� ������ " + FindRussianDublonString(sti(pchar.questTemp.PrisonGun.Sum)) + ". ��� �������?.. ��, ��� ���� - ��� ������ ����� �����, �� �� �����, ��� ����� ����� - ������ ��� � ����.";
			Link.l1 = RandPhraseSimple("���, ������, �� �������������� ���� ���� �����������... ��������.","���������, �������, �� � �� ��������. ��������� �� ��������� ������ �������...");
			Link.l1.go = "exit_gun";
			Link.l2 = RandPhraseSimple("�� �����, ����������� ����������. ��������, ��� �� ��� ������������.","�������, ��������. ��� ��� �� ������, � ������ ��������.");
			Link.l2.go = "GiveTaskGun_2";
		break;
			
		case "exit_gun":
			dialog.Text = "����� ����... ����� ����, �������, � �� ��� �����������. �-�... �������, ���� �������� �� ������ �� ������� �����?";
			Link.l1 = "��� ����������� ���� ��������. ����� �������.";
			Link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
			
		case "GiveTaskGun_2":
			dialog.Text = "��� � �� �����. � ������ � ��� �� �����������, ��, ��� ��, ������������ �� ����������� �� �������. � �������, �� ���������, ��� ���� ����������������?";
			Link.l1 = "�������. �� �������.";
			Link.l1.go = "exit";	
			ReOpenQuestHeader("PrisonGun");
			AddQuestRecord("PrisonGun", "1");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("��","���"));
			AddQuestUserData("PrisonGun", "sName", GetFullName(npchar));
			AddQuestUserData("PrisonGun", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("PrisonGun", "sQty", makeint(pchar.questTemp.PrisonGun.Qty));
			AddQuestUserData("PrisonGun", "sSum", makeint(pchar.questTemp.PrisonGun.Sum));
			AddQuestUserData("PrisonGun", "sText", pchar.questTemp.PrisonGun.Text);
			NextDiag.TempNode = "First time";
		break;	
		
		case "CheckGun":
			if (GetQuestPastDayParam("pchar.questTemp.PrisonGun") < 30)
			{
				dialog.Text = "� �� ������� ��� ������� �� ������, ��� ����� �����!";
				Link.l1 = "��� ����! ��� ��������"+ GetSexPhrase("��","���") +", ��� �������"+ GetSexPhrase("","�") +" ���� �������... ��������, ����� �����, ��� � ��������������.";
				Link.l1.go = "exit";
				NextDiag.TempNode = "First time";
				break;
			}
			if (GetQuestPastDayParam("pchar.questTemp.PrisonGun") > 180)
			{
				dialog.Text = "��... ������, � ������� ���������� ������ '��������' ������ ������, ��� �������. � ��� �������� ������. ��� �� ������, ��� � ���� ����� ��� �����?";
				Link.l1 = "��� ����! ��� �� ��������� ������ � ���� ������?";
				Link.l1.go = "TakeGun_late";
				break;
			}
			iGunGoods = pchar.questTemp.PrisonGun.Goods;
			amount = GetSquadronGoods(Pchar, iGunGoods) - sti(pchar.questTemp.PrisonGun.Qty);
			sTemp = sti(pchar.questTemp.PrisonGun.Qty);
			iTest = FindColony(NPChar.City); // �����
			
			if (iTest != -1)
			{
				rColony = GetColonyByIndex(iTest);
			}
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				dialog.Text = "��, �� ������ ���� ����������?";
				if (amount < 0)
				{
					Link.l1 = "���, ���� ���������. ������ ����� ���������, ��� ��� ������ ��� � ����.";
					Link.l1.go = "exit";
				}
				else
				{
					Link.l1 = "�����. ��� ������ � ����� - "+ sTemp +" ����, ��� � ��������������.";
					Link.l1.go = "TakeGun";
				}
			}
			else 
			{
				dialog.text = "���-�� � �� ���� � ����� ������ �������. ��� �� ����������� ������ ����� ����� �������? �������������� � ����� ������ � �������������.";
				link.l1 = "��� ������� �� ������ ������� �������. ������ ������� ��� � ����.";
				link.l1.go = "exit";
			}
		break;
		
		case "TakeGun":
			if (pchar.questTemp.PrisonGun.Luck == 4)
			{
				dialog.Text = RandPhraseSimple("��� ����� �������, �� � �������� ������������ ��� ������.  ��������� ���������� ��������, � �� �� ������, ��� ��� ���������� � ���� ��������. ���, �� ����� �� ���������, ��������.","�������, ��� ����� ����... � �����, ��� �������� ������ �� ����������, � �, �����������, ��� �������� �� ��������. ���� ������� �������������, ��... ��������, ��� ����� ���, �� � ��� ������ �������.");
				Link.l1 = "��� ����! ��� �� ��������� ������ ������?";
				Link.l1.go = "TakeGun_no";
			}
			else
			{
				dialog.Text = RandPhraseSimple("�������. � ������ �� ������ ��� �������� ����������� �����.","�����������. ������� ������� ����� ����� � ���������.");
				Link.l1 = "�� ������ �����������?";
				Link.l1.go = "TakeGun_1";
			}
		break;
		
		case "TakeGun_no":
			dialog.Text = "�� ����. �������� �� �����, ��������� �����-������ �������� �����, �������... ����� �� �� ����. � � ����� ����� ���, �� ����������������� �� ���� ����.";
			Link.l1 = "��� �� ����! � ���� ������ ��� ����!";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "3");
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		
		case "TakeGun_late":
			dialog.Text = "�� ����. ��� ���� ���������. ��������, ���������, ������� - ��� ��� �����.";
			Link.l1 = "��, ��� ������ ����� ������...";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "4");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("��","���"));
			AddQuestUserData("PrisonGun", "sName", GetFullName(npchar));
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		
		case "TakeGun_1":
			iGunGoods = pchar.questTemp.PrisonGun.Goods;
			amount = sti(pchar.questTemp.PrisonGun.Qty);
			iTemp = sti(pchar.questTemp.PrisonGun.Sum);
			dialog.Text = "�������! ��� ���� ������. ����������, ��������.";
			Link.l1 = "�������������! � ���� ������� ����� ����!";
            Link.l1.go = "TakeGun_2";
			TakeNItems(pchar, "gold_dublon", iTemp);
			Log_Info("�� �������� "+FindRussianDublonString(sti(pchar.questTemp.WPU.Escort.Money))+"");
			PlaySound("interface\important_item.wav");
			RemoveCharacterGoods(Pchar, iGunGoods, amount);
		break;
		
		case "TakeGun_2":
			dialog.Text = "�������. �� ��� ����� �������. �, ����� ���, ����� ��� ������ ��������� ����� ����.";
			Link.l1 = "��, ��� ���� ����� ����������. ����� ��������.";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "2");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("","�"));
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		// <-- ������ ��� �����

		//Jason --> ����-����� ���������� �����
		case "Wine_prison":
			dialog.text = "���?! � ��������� �������� ������� �� ���������� �����! �� ��� ��, �� ���������� �� ���. � ����� �� ��� ��������� 1000 ����, ������� ������ ������� ��� ��� �������������� �� ���� ������������, � �������� �� ��� ��� �� ���������.";
			link.l1 = "���������, " + GetAddress_FormToNPC(NPChar) + ". ��������� �������� ��������� - ��� ����� ����.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 1000);
			ChangeCharacterComplexReputation(pchar,"nobility", -1); 
			DeleteAttribute(pchar, "questTemp.Wine.bottle");
			pchar.quest.Wine_Exchange.over = "yes";//����� ����������
			sld = characterFromId(pchar.questTemp.Wine.id);
			sld.lifeday = 0;
			CloseQuestHeader("Wine");
			NextDiag.TempNode = "First time";
		break;
		// <-- ����-����� ���������� �����
		
		// ��������� �����
		case "trial":
			iTest = FindColony(NPChar.City); // �����
			if (iTest != -1)
			{
				rColony = GetColonyByIndex(iTest);
			}
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				if (GetSquadronGoods(pchar, GOOD_BOMBS) < 1500 || GetSquadronGoods(pchar, GOOD_POWDER) < 1500)
				{
					dialog.text = "��. �� � ��� �� �� ���� ����! ��� ����� ����������?";
					link.l1 = "���� ������! ����� ���� �������� - ��� ��� ���������. � ���������� ������� ������ ���������� � ���� ��� ��� ������, ��� ��������.";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "���, ������, ��� �� - ��� ������? ������. ������� ������� ���������� � ������, � ����� ��� �������� ���������� ��������.";
					link.l1 = "�������.";
					link.l1.go = "trial_1";
				}
			}
			else
			{
				dialog.text = "���-�� � �� ���� � ����� ������ �������. ��� �� ����������� ������ ���� ����� �������? �������������� � ����� ������ � �������������.";
				link.l1 = "��� ������� �� ������ ������� �������. ������ ������� ��� � ����.";
				link.l1.go = "exit";
			}
		break;
		
		case "trial_1":
			pchar.quest.Trial_FrahtFail.over = "yes"; //����� ������
			dialog.text = "���, ���� ���� � ������ � ���������� 1500 ���� �������... ������. ������� ���������� �������� ����, ���� ���� ����� �������� ��������. �������� ������ �� ����� - ���� ����� ����.";
			link.l1 = "�������! ������ ��� ���������� ��������? ����� ������ ������...";
			link.l1.go = "trial_2";
		break;
		
		case "trial_2":
			AddMoneyToCharacter(pchar, 5000);
			RemoveCharacterGoods(pchar, GOOD_BOMBS, 1500);
			RemoveCharacterGoods(pchar, GOOD_POWDER, 1500);
			dialog.text = "��-��, ������ �� �������� ����������. ������ ���� ��������� �����������?";
			link.l1 = "����������, ������.";
			link.l1.go = "trial_3";
		break;
		
		case "trial_3":
			dialog.text = "������, ���. � ������ �����, � ������ - � ������� ��������� ������� ����� �����, ���������� ��� ������� �������, ������ '������������', ��� ������������� �������� �������� ����. �� ������������ ��������� ������� ������, ������� ������ ����� �� ����� ����� ����� ��� ������\n�������� ����������� � ���, ��� �� ����� ������� � �������� �������� ������ ����������� ������ �������, �������� ����� ����������� ������������ ��� ������� ��� - ��� ��������� ����� �������-�������� �����. ��������� ������, � �����, ����������� '������������' � �� ����� ���������� �������, � �� ������� ����\n��� ������ ������ ������� ���� ����� �������� ���������� �� ��������� � ���� �� � ���, � ��� ������ ������������. ���� ������ - ������ ��������, �������� �� '������������' ���������� ������, � �� �������, ��� ����� �������� �����.";
			link.l1 = "�� ����, � ������ ������� �� ���� ������� ������� ������, ����������� � ����� �����, �������� ��� ������ '������������' � �������� ����� �������� �������� ����?";
			link.l1.go = "trial_4";
		break;
		
		case "trial_4":
			dialog.text = "��� �����. �� ��� ��������� ������. �� ������ ������� �� ��� ����?";
			link.l1 = "��� ������ ������?";
			link.l1.go = "trial_5";
			link.l2 = "��� ����, ������, �� � �� ���� � ��� �����������. ����� ���� ��������.";
			link.l2.go = "trial_exit";
		break;
		
		case "trial_exit":
			dialog.text = "��� ���� �����, ���� � ����������� �� ���� ��������. �������� ������ ������� �������, � ������� ����������� �� ��������... � ��� ����� �� ����������, �������.";
			link.l1 = "����� �������.";
			link.l1.go = "trial_exit_1";
		break;
		
		case "trial_exit_1":
			DialogExit();
			AddQuestRecord("Trial", "6");
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
		break;
		
		case "trial_5":
			dialog.text = "������ ����� �� �����������. ������� ���� �������� ��� �� ����������� ����� ������ ������� ��������. ����� ����, � ������, ��� �� ����������� ��� � ���� ����� ��� ����� �����. � ������ ��������, �������.";
			link.l1 = "������. � ������ �� ��� ���������! ��� ������?";
			link.l1.go = "trial_6";
		break;
		
		case "trial_6":
			dialog.text = "� �����������, ����� ������� ���������� ��������� �� �� ��� �������. �������� ������������� � ����, �����. ����� �����!";
			link.l1 = "���������. ��� ��� ����� �� ��������, ��� � �������� �����...";
			link.l1.go = "trial_7";
		break;
		
		case "trial_7":
			DialogExit();
			AddQuestRecord("Trial", "7");
			pchar.questTemp.Trial = "cannon";
			SetFunctionTimerCondition("Trial_CannonFail", 0, 0, 30, false); // ������
			SetCharacterGoods(pchar, GOOD_CANNON_24, GetCargoGoods(pchar, GOOD_CANNON_24)+15);
			EnemyNationHunterOnMap(true);//������ �������������
			pchar.quest.Trial_cannon.win_condition.l1 = "location";
			pchar.quest.Trial_cannon.win_condition.l1.location = "Portobello";
			pchar.quest.Trial_cannon.function = "Trial_CreateFlorianFrigate";
		break;
	}
}

void GetGunType()
{
	int iGunType;
	if(makeint(pchar.rank) < 6) iGunType = rand(1);	//18&&24
	if(makeint(pchar.rank) >= 6 && makeint(pchar.rank) < 15) iGunType = rand(2); //24&&32	
	if(makeint(pchar.rank) >= 15 && makeint(pchar.rank) < 24) iGunType = rand(2)+2; //32&&36&&42
	if(makeint(pchar.rank) >= 24) iGunType = 5-rand(1); //36clv&&42
	int iAdd = makeint(GetSummonSkillFromName(pchar, SKILL_COMMERCE)/20);
	
	switch (iGunType)
	{
		case 0:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_24;     					
			pchar.questTemp.PrisonGun.Price = 28 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*5+25+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "����� 24-�� �������";
		break; 
		case 1:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CULVERINE_18;     					
			pchar.questTemp.PrisonGun.Price = 25 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*5+25+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "���������";
		break; 
		case 2:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_32;     					
			pchar.questTemp.PrisonGun.Price = 32 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*3+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "����� 32-�� �������";
		break; 
		case 3:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_36;     					
			pchar.questTemp.PrisonGun.Price = 36 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*3+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "����� 36-�� �������";
		break;
		case 4:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CULVERINE_36;     					
			pchar.questTemp.PrisonGun.Price = 49 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "������ ���������";
		break; 
		case 5:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_42;     					
			pchar.questTemp.PrisonGun.Price = 40 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)+20+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "����� 42 �������";
		break; 
	}
}