// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������, " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";			
			if (pchar.questTemp.Slavetrader == "FindRatPortobello")
            {
                link.l1 = "��������, �� ����� �� �� ������ �� ����� ������� �������? �� ������� ��� � ����� ������.";
                link.l1.go = "Portobello_rat_1";
            }			
			// ��������� �����
			if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy" && !CheckAttribute(npchar, "quest.trial"))
            {
                link.l1 = "��������, �� ����������, ��� ����� �������� �� ����� ����� �������? �� ����� ��� � ��� ���������...";
                link.l1.go = "trial";
            }			
			if (CheckAttribute(pchar, "questTemp.mushkett2x2_stid") && !CheckCharacterItem(pchar, "mushkett2x2"))
			{
				link.l1 = "������, �������, �� �� ������, ��� ��� ����� �������� ������� - �������� ����� '������'?";
				if (GetQuestPastDayParam("questTemp.mushkett2x2_stid") < 21)
				{
					link.l1.go = "Mushket_stid";
				}
				else
				{
					link.l1.go = "Mushket_late";
				}
			}

			// Addon-2016 Jason ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_portobello" && !CheckAttribute(npchar, "quest.FMQG"))
            {
                link.l1 = "��������, � ��� �������� �� ����� ������� ������, �� ������ � �����? �� ������� ������ � �����-�����. �������� ����� ��������, ��������, � ������ ��������. �����, ������� � ����...";
                link.l1.go = "FMQG";
            }
		break;
		
		case "Portobello_rat_1":
			dialog.text = NPCStringReactionRepeat("���, �� ����. � ������� �� �� �������, �� � � ������ � ��� �� �����.", "�� ��� "+ GetSexPhrase("���������","����������") +" �� ����, � ���� �������.", "� �� ������ ����, �� ��� "+ GetSexPhrase("���������","����������") +" �� ���� ��������.", "��������, ������ � �� �����! ������ ��� �� ����� �������?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� ��� ��, ����� ������.", "��, �� ��...", "��, �����, "+ GetSexPhrase("���������","����������") +"...", "������, " + npchar.name + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;		

		case "trial":
			dialog.text = "������ ����� �������? �, ���� ����������� ��������� ����� �������� � ����� ������, �������� � ��������� ���� ����! �������� �������, � ������ ��������, ������� �������� ��� � ����... ������ ������! ��� �� ������ ����� �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			npchar.quest.trial = true;
			AddDialogExitQuestFunction("Trial_TavernEnterSoldiers");
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;

		case "Mushket_stid":
			dialog.text = "��� ��� ��!.. A�-��-��! ����� ��� ���� ����������� ��� ������ ����, ���������� ��������� ������� ������?!";
			link.l1 = "�����... � ���� � ���� ����.";
			link.l1.go = "Mushket_stid_1";
			DeleteAttribute(pchar, "questTemp.Mushkett2x2_stid");
			break;
			
		case "Mushket_stid_1":
			dialog.text = "�� �������?! ����������, � ���� ���� � ���� '����', ����� ��� ����� �����. �� �� � ��� ��� �� ����� - ����-��������, ���� ����������. ������ �������������� ��� ������, ������ ��� ����� ��������� ����������. � ����� �� �� ������� - � ������ ��� ��������� ����. ���� ������ �� ���� ��������... � ����, �������� �� ����� �� ��� ���� ������?";
			link.l1 = "�� ���... ���� � ���� ������, ������� ��� �� �����������, �������� ����...";
			link.l1.go = "Mushket_stid_2";
		break;

		case "Mushket_stid_2":
			dialog.text = "��-��! �� ������� ���� ��� ����������� ����� �� ����������� - ����� ��������, ��� ������, ��� ������ ��� �������. ���� ��� - '������' ����������� ��� ������� - ������ � ����� �� ���� ������, �� ����� ��������.\n������, � �� �� �������� �� ��� �� ���� �������"+ GetSexPhrase("","�") +", �? � �� � ��� ����� - ��� �� '����' � ���� � ����! ������ ���� - ������ ����� �������� ������� ���� �� ���, ������, ��� �� �������� ������. ����� �� � ���� ������ - ������� ��������, ����� �������.";
			link.l1 = "�� �� ����� ��� ��� ����! �� ������ ������ ������� - ��� ��� �����?";
			link.l1.go = "Mushket_stid_3";
		break;		
			
		case "Mushket_stid_3":
			dialog.text = "�� �����-��������, �������� �� ������, ������� ����� �� ������� � �������, �������� ��������, ��� ��� �������� ��� ��������... �� �� ��� �� � ����������� �����, ���� �� �� ����, ���� �� �������! ��� ��� ������ ������, "+ GetSexPhrase("��������","�������") +"!";
			link.l1 = "��-��, �������! � ������� �� ������ �� ��� ����������?";
			link.l1.go = "Mushket_stid_4";
		break;	
			
		case "Mushket_stid_4":
			dialog.text = "��� ����� �������, ��������! ��� ����� ������� - � ����� ������.";
			if(makeint(Pchar.money) >= 100000)
			{
				link.l1 = "�������?? �� �� ���, ������ - ������� ����� ������ �� ��� �����?!";
				link.l1.go = "Mushket_stid_nopay";
				link.l2 = "��� �������, �������. ����� ���� ����.";
				link.l2.go = "Mushket_stid_paymoney";
			}
			link.l3 = "��������, �� � ���� ��� ����� �����!";
			link.l3.go = "Mushket_stid_nomoney";
		break;	
			
		case "Mushket_stid_nopay":
			dialog.text = "�� ������ ���� ����������� - ��� ���� ����� ������� ������. � ���� ����� ��� '������' ������ ������������ ������ �� ������ ����� ������� - ���� ������� ������ ��� ���������� ��������... ���� ������� ��������� ������ - ��� ����������� ���� ������. �, ���� �� ������� - ���������� ������ �� � ����, ��-��-��...";
			link.l1 = "�����, ���� � �����. �����.";
			link.l1.go = "Mushket_stid_paymoney";
			link.l2 = "�� ������. ��������� ��� ������ - ���"+ GetSexPhrase("","�") +" �����.";
			link.l2.go = "Mushket_stid_goaway";
		break;	
			
		case "Mushket_stid_nomoney":
			dialog.text = "�� ��� � - ����� �� ������ ���� ������� '������'. �������, ���� ���� ������ ��������� �������������� ���-�� ����������. � �����, ��� �� ������������, ������ ��� - �� ������� � ����� �����, � ������ � ������... ��� ���, �������� - �������, ���� ������ �������� � ���. � � ���� �� ��������.";
			link.l1 = "�� ���, ������, �������. �� �������� ���� �������� ���������. ��� ���������� ������� ����, � �� ��������� - ���� �����...";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "5");
			DeleteAttribute(pchar, "pchar.questTemp.Mushkett2x2.Shore");
		break;	
			
		case "Mushket_stid_goaway":
			dialog.text = "��� ������. ������ - �����. ������� �������!";
			link.l1 = "������, �������.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "6");
			AddQuestUserData("SeekDoubleMushket", "sSex", GetSexPhrase("��","���"));
			DeleteAttribute(pchar, "pchar.questTemp.Mushkett2x2.Shore");
		break;	
			
		case "Mushket_stid_paymoney":
			AddMoneyToCharacter(Pchar, -100000);
			dialog.text = "�-�, � ���� ������"+ GetSexPhrase("�� ������ ��������","��� ������ ������������") +"! � ���� ���� ���������� - �� ���������� �� �! ��, �� ����� - ���� �� �������� ���� ������������ ������... ������ ������: ��������� �� ���� � ���� ���� ������ � ���������������� � ������ ��������, ������ �� ������ ����� ���������� �� ������ �����, ��� � ���� �������, �������� ��������� � ��������� �������.\n����� �� ��� �� ����� - ������� ������� � �����, ��� ��� ����������. ������� ��� �� �� �������, �� ����������� �� ������ ����"+ GetSexPhrase("��","��") +". ������, ���� ������ ������ ������� �����, ��-��... ���� ���, �� �������� ����� ������ ����"+ GetSexPhrase("��","�") +". � � ��� ���� ���� ������, � ���� ����� ������, �� �� ��� ���� �������� �� �����������.";
			link.l1 = "�������, ���! ���������� ����������.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "4");
			SetMushketCapitainInWorld();
		break;
		
		case "Mushket_late":
			dialog.text = "A�-��-��! ����� ��� ���� ����������� ��� ������ ����, ���������� ��������� ������� ������?!";
			link.l1 = "�����... � ���� � ���� ����.";
			link.l1.go = "Mushket_late_1";
			DeleteAttribute(pchar, "questTemp.Mushkett2x2_stid");
		break;
			
		case "Mushket_late_1":
			dialog.text = "�� ��� � ���� �������... �� ������ ����, "+ GetSexPhrase("��������","�������") +". ����� �� �� ��� ������� �������� - � �� ��������� � ����� �����������, � ����� ����� ����� �������� �������.\n�� ������ ������ - �� ���� ������, � ���� - �� �����. ��� ��� ��� ������ ���"+ GetSexPhrase("","�") +"... �� ����� ����������. �� ����� ���� ��� ������.";
			link.l1 = "��� ������! �����, ��� ��� - ������.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "7");
			AddQuestUserData("SeekDoubleMushket", "sSex", GetSexPhrase("��","���"));
		break;

		// Addon-2016 Jason ���-���������
		case "FMQG":
			dialog.text = "������ �� ������ �� ���� ���������, ��������.";
			link.l1 = "�� �������� ���� ������� �� �������. ����� ������ �� ����������?";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			dialog.text = "���. ��� ���� ��� � ����� �� �������� ������ - ��� �� ����� � ����������� � ������� � ������� � �������� ��������. � ���� � ���������� � ����� ��������.";
			link.l1 = "�������, ��� � ������. ������� �� �����!";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			DialogExit();
			AddQuestRecord("FMQ_Guadeloupe", "9");
			npchar.quest.FMQG = true;
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}


void SetMushketCapitainInWorld()
{
	//������� �����
	int Rank = sti(pchar.rank) + 15;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("MushketCap", "officer_13", "man", "man", Rank, PIRATE, -1, true, "quest"));
	sld.name = "�������";
	sld.lastname = "������";
	sld.model = "officer_13"; 
	sld.model.animation = "man"; 
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	FantomMakeSmallSailor(sld, SHIP_BrigArrow, "������", CANNON_TYPE_CULVERINE_LBS18, 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50));
	FantomMakeCoolFighter(sld, 50+rand(50), 50+rand(50), 50+rand(50), "topor_04", "pistol_06", "cartridge", 50);
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 3;
	sld.Ship.Mode = "pirate";	
	DeleteAttribute(sld, "SinkTenPercent");
	sld.AlwaysSandbankManeuver = true;
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.SuperShooter = true;
	sld.DontClearDead = true;
	sld.AlwaysEnemy = true;
	sld.SuperShooter  = true;
	sld.Abordage.Enable = true;
	sld.Ship.Stopped = true; 
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
      TakeNItems(sld, "bullet", 50);
	TakeNItems(sld, "cartridge", 50);
	TakeNItems(sld, "grapeshot", 50);
	TakeNItems(sld, "GunPowder", 100);
	sld.AlwaysSandbankManeuver = true;
	sld.equip.gun = "pistol_06";
	GiveItem2Character(sld, "spyglass3");
	EquipCharacterbyItem(sld, "spyglass3");
	sld.ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
	LAi_SetCharacterUseBullet(sld, "cartridge");
	sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
	SetCrewQuantityFull(sld);
	sld.DontRansackCaptain = true; //�� ���������
	sld.WatchFort = true; //������ �����
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterGoods(sld, GOOD_BALLS, 500);
	SetCharacterGoods(sld, GOOD_GRAPES, 500);
	SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
	SetCharacterGoods(sld, GOOD_BOMBS, 500);
	SetCharacterGoods(sld, GOOD_FOOD, 300); 
	SetCharacterGoods(sld, GOOD_POWDER, 2500);
	SetCharacterGoods(sld, GOOD_WEAPON, 300);
	SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
	SetCharacterGoods(sld, GOOD_RUM, 150); 
	SetCharacterGoods(sld, GOOD_PLANKS, 50);
	SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
	SetCharacterGoods(sld, GOOD_SILVER, 500);
	SetCharacterGoods(sld, GOOD_GOLD, 250);
	UpgradeShipParameter(sld, "Capacity");
	//� ������� ������ ����
	string sGroup = "MushketCapShip";
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	sld.quest = "InMap"; //������ ���� �������� ����
	sld.city = "Shore47"; //��������� �������, �� ����� ������� � �������� ������
	sld.cityShore = GetIslandRandomShoreId(GetArealByCityName(sld.city));
	sld.quest.targetCity = SelectAnyColony(sld.city); //��������� �������, � ����� ������� �� ������
	sld.quest.targetShore = "Shore126";
	pchar.questTemp.Mushkett2x2.Shore = GetIslandRandomShoreId(GetArealByCityName(sld.quest.targetCity));
	Log_TestInfo("��� � �������� ����� ��: " + sld.city + " � ���������� �: " + sld.quest.targetShore);
	//==> �� �����
	sld.mapEnc.type = "trade";
	//����� ���� ��������� �� �����
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "���� '������'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+15; //���� ������� ���� � �������
	Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, daysQty);
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "mushkett2x2"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = "none"; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = "SeekDoubleMushket"; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "SeekDoubleMushket"; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}


















