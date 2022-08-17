// Warship -->
// ����������� ��������� �������
void SetRandSelfSkill(ref _ch, int _min, int _max)
{
	int iDelta = _max-_min;
	_ch.skill.Leadership 	= _min + rand(iDelta);
	_ch.skill.FencingL 		= _min + rand(iDelta);
	_ch.skill.FencingS 		= _min + rand(iDelta);
	_ch.skill.FencingH 		= _min + rand(iDelta);
	_ch.skill.Pistol 		= _min + rand(iDelta);
	_ch.skill.Fortune 		= _min + rand(iDelta);
	_ch.skill.Sneak 		= _min + rand(iDelta);
}

void SetRandShipSkill(ref _ch, int _min, int _max)
{
	int iDelta = _max-_min;
	_ch.skill.Sailing = _min + rand(iDelta);
	_ch.skill.Commerce = _min + rand(iDelta);
	_ch.skill.Accuracy = _min + rand(iDelta);
	_ch.skill.Cannons = _min + rand(iDelta);
	_ch.skill.Repair = _min + rand(iDelta);
	_ch.skill.Grappling = _min + rand(iDelta);
	_ch.skill.Defence = _min + rand(iDelta);
}

// ���������� ����� ��� �����
void SelAllPerksToChar(ref _ch, bool _isOfficer)
{
	_ch.perks.list.BasicDefense = "1";
	_ch.perks.list.AdvancedDefense = "1";
	_ch.perks.list.ProfessionalDefense = "1";
	_ch.perks.list.CriticalHit = "1";
	_ch.perks.list.SwordplayProfessional = "1";
	_ch.perks.list.Grus = "1";
	_ch.perks.list.Rush = "1";
	_ch.perks.list.Tireless = "1";
	_ch.perks.list.HardHitter = "1";
	_ch.perks.list.BladeDancer = "1";
	_ch.perks.list.Sliding = "1";
	_ch.perks.list.Gunman = "1";
	_ch.perks.list.GunProfessional = "1";
	_ch.perks.list.Sniper = "1";
	_ch.perks.list.IronWill = "1";
	_ch.perks.list.SharedExperience = "1";
	_ch.perks.list.Medic = "1";
	_ch.perks.list.HPPlus = "1";
	_ch.perks.list.EnergyPlus = "1";
	_ch.perks.list.ShipEscape = "1";
	_ch.perks.list.Alchemy = "1";
	
	_ch.perks.list.FlagPir = "1";
	_ch.perks.list.FlagEng = "1";
	_ch.perks.list.FlagFra = "1";
	_ch.perks.list.FlagSpa = "1";
	_ch.perks.list.FlagHol = "1";
	_ch.perks.list.FastReload = "1";
	_ch.perks.list.ImmediateReload = "1";
	_ch.perks.list.HullDamageUp = "1";
	_ch.perks.list.SailsDamageUp = "1";
	_ch.perks.list.CrewDamageUp = "1";
	_ch.perks.list.CriticalShoot = "1";
	_ch.perks.list.LongRangeShoot = "1";
	_ch.perks.list.CannonProfessional = "1";
	_ch.perks.list.LongRangeGrappling = "1";
	_ch.perks.list.MusketsShoot = "1";
	_ch.perks.list.GrapplingProfessional = "1";
	_ch.perks.list.BasicBattleState = "1";
	_ch.perks.list.AdvancedBattleState = "1";
	_ch.perks.list.ShipDefenseProfessional = "1";
	_ch.perks.list.LightRepair = "1";
	_ch.perks.list.InstantRepair = "1";
	_ch.perks.list.ShipSpeedUp = "1";
	_ch.perks.list.ShipTurnRateUp = "1";
	_ch.perks.list.StormProfessional = "1";
	_ch.perks.list.Turn180 = "1";
	_ch.perks.list.SeaDogProfessional = "1";
	_ch.perks.list.SailingProfessional = "1";
	_ch.perks.list.Brander = "1";
	_ch.perks.list.Troopers = "1";
	_ch.perks.list.BasicCommerce = "1";
	_ch.perks.list.AdvancedCommerce = "1";
	_ch.perks.list.ProfessionalCommerce = "1";	
	_ch.perks.list.Carpenter = "1";
	_ch.perks.list.Builder = "1";
	_ch.perks.list.SelfRepair = "1";
	_ch.perks.list.WindCatcher = "1";
	_ch.perks.list.SailsMan = "1";
	_ch.perks.list.Doctor1 = "1";
	_ch.perks.list.Doctor2 = "1";
	_ch.perks.list.Doctor3 = "1";
	
	if(_isOfficer) // � ���� ���� ���. �����
	{
		_ch.perks.list.ByWorker = "1";
		_ch.perks.list.ByWorker2 = "1";
	}
}

// ���������� ����� �������� ������
void SetHalfPerksToChar(ref _ch, bool _isOfficer)
{
	_ch.perks.list.BasicDefense = "1";
	_ch.perks.list.AdvancedDefense = "1";
	_ch.perks.list.CriticalHit = "1";
	_ch.perks.list.ProfessionalDefense = "1";
	_ch.perks.list.Gunman = "1";
	_ch.perks.list.SharedExperience = "1";
	
	_ch.perks.list.FlagPir = "1";
	_ch.perks.list.FlagEng = "1";
	_ch.perks.list.FlagFra = "1";
	_ch.perks.list.FlagSpa = "1";
	_ch.perks.list.FlagHol = "1";
	_ch.perks.list.HullDamageUp = "1";
	_ch.perks.list.SailsDamageUp = "1";
	_ch.perks.list.CrewDamageUp = "1";
	_ch.perks.list.CriticalShoot = "1";
	_ch.perks.list.LongRangeShoot = "1";
	_ch.perks.list.LongRangeGrappling = "1";
	_ch.perks.list.GrapplingProfessional = "1";
	_ch.perks.list.BasicBattleState = "1";
	_ch.perks.list.AdvancedBattleState = "1";
	_ch.perks.list.ShipSpeedUp = "1";
	_ch.perks.list.ShipTurnRateUp = "1";
	_ch.perks.list.StormProfessional = "1";
	_ch.perks.list.Turn180 = "1";
	_ch.perks.list.SailingProfessional = "1";
	_ch.perks.list.WindCatcher = "1";
	_ch.perks.list.SailsMan = "1";
	
	if(_isOfficer) // � ���� ���� ���. �����
	{
		_ch.perks.list.ByWorker = "1";
		_ch.perks.list.ByWorker2 = "1";
	}
}

// �������� ��� �������� (����� ���������) � ���������� ���������
void RemoveAllCharacterItems(ref _ch, bool _removemoney)
{
	// ������ ����� ��� ����������
	if(_ch == GetMainCharacter())
	{
		StoreEquippedMaps(_ch);
		_ch.MapsAtlasCount = 0;
	}	
	RemoveCharacterEquip(_ch, BLADE_ITEM_TYPE);
	RemoveCharacterEquip(_ch, GUN_ITEM_TYPE);
	RemoveCharacterEquip(_ch, SPYGLASS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, PATENT_ITEM_TYPE);
	RemoveCharacterEquip(_ch, CIRASS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, MAPS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, TOOL_ITEM_TYPE);
	RemoveCharacterEquip(_ch, BACKPACK_ITEM_TYPE);
	RemoveCharacterEquip(_ch, TALISMAN_ITEM_TYPE);
	
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT1_TYPE);
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT2_TYPE);
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT3_TYPE);
	
	//������ ��� ��������, ����� ��������� -->
	aref arItems;
	string sName;
	ref rLoc;
	makearef(arItems, _ch.items);
	int	Qty = GetAttributesNum(arItems);
	for (int a=0; a<Qty; a++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, a));
		rLoc = ItemsFromID(sName);
		if (rLoc.ItemType == "QUESTITEMS")
		{
			_ch.questTemp.items.(sName) = _ch.items.(sName);
		}
	}			
	DeleteAttribute(_ch, "items");
	_ch.items = "";
	makearef(arItems, _ch.questTemp.items);
	Qty = GetAttributesNum(arItems);
	for (a=0; a<Qty; a++)
	{		
		sName = GetAttributeName(GetAttributeN(arItems, a));
		TakeNItems(_ch, sName, sti(arItems.(sName)));
	}		
	DeleteAttribute(_ch, "questTemp.items");
	
	_ch.SystemInfo.itemsCRC = CheckItemsCRC(_ch); // ������ ����������� ����������� �����
	
	if(_removemoney)
	{
		_ch.money = 0;
	}
}

// ������ ���� ���������� � ����������� ��
void RemoveAllPassengersAndCompanions()
{
    int iDay = GetPassengersQuantity(pchar);
    int i = 0;
    int n = 0;
	int idx;
	ref ch;
	
 	while (i < iDay)
	{
		i++;
		idx = GetPassenger(pchar, n); // ������ ������ � ������� �� ���������, ���� �� ����
		if (idx == -1) break;
		ch = GetCharacter(idx);
		if (GetRemovable(ch)) // ��������� �� �������
		{
		    ch.LifeDay = 1; // ���� �� ����� �������
		    RemovePassenger(pchar, ch);
			ChangeCharacterAddress(ch,"none","");
		}
		else
		{
		    n++;
		}
	}
    for (i=0; i<COMPANION_MAX; i++)
	{
		idx = GetCompanionIndex(pchar, i);
		if (idx != -1)
		{
            ch = GetCharacter(idx);
			if (GetShipRemovable(ch) && GetRemovable(ch))  // �� ������� ��������� � ���
			{
			    ch.LifeDay = 1; // ���� �� ����� �������
			    RemoveCharacterCompanion(pchar, ch);
			}
		}
	}
}

void CleanAllCabinBoxes()
{
	ref loc;
	int n;
	string sTemp;
	
    if (Pchar.SystemInfo.CabinType != "")
    {
	    loc = &locations[FindLocation(Pchar.SystemInfo.CabinType)]; //"My_Cabin"

	    for (n = 1; n <= 4; n++)
	    {
	        sTemp = "box" + n;
			DeleteAttribute(loc, sTemp + ".items");
		    loc.(sTemp).items = "";
		    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
		    loc.(sTemp).money = 0;
	    }
    }
    loc = &locations[FindLocation("My_Deck")];
    for (n = 1; n <= 4; n++)
    {
        sTemp = "box" + n;
		DeleteAttribute(loc, sTemp + ".items");
	    loc.(sTemp).items = "";
	    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
	    loc.(sTemp).money = 0;
    }
}

// ����� ������ ��������� ��� �������, ������� ������� �� ������ ���� ���������
int RandShipFromShipClass(ref _ch)
{
	int iShipClass = sti(RealShips[sti(_ch.Ship.Type)].Class);
	int iShipType;
	switch(iShipClass)
	{
		case 1:
			iShipType = SHIP_LINESHIP + rand(4);
			break;
			
		case 2:
			iShipType = SHIP_HEAVYGALEON + rand(12);
			break;
		
		case 3:
			iShipType = SHIP_GALEON_L + rand(13);
			break;
			
		case 4:
			iShipType = SHIP_BRIGANTINE + rand(12);
			break;
			
		case 5:
			iShipType = SHIP_GALIOT + rand(11);
			break;
			
		case 6:
			iShipType = SHIP_WAR_TARTANE;
			break;
			
	}
	return iShipType;
}

// ��������, ���� �� � �� ��������
bool IsPCharHaveTreasurer()
{
	ref rOfficer;

	for(int i=0; i<MAX_CHARACTERS; i++)
	{
		rOfficer = &characters[i];
		if(CheckAttribute(rOfficer, "treasurer") && sti(rOfficer.Treasurer) == 1)
		{
			return true; // �������� ����
		}
		
	}
	
	return false;
}

// ����� ������ ������ �� ��������
ref GetPCharTreasurerRef()
{
	if(!IsPCharHaveTreasurer()) return &NullCharacter;
	for(int i=0; i<MAX_CHARACTERS; i++)
	{
		if(CheckAttribute(&characters[i], "treasurer") && sti(characters[i].Treasurer) == 1)
		{
			return &characters[i];
		}
	}
	
	return &NullCharacter;
}

// ����� ������ �������� ��������
string GetAttrValue(ref _rChar, string _sAttr)
{
	string sTemp;
	if(!CheckAttribute(_rChar, _sAttr)) _rChar.(_sAttr) = "";
	
	sTemp = _rChar.(_sAttr);
	return sTemp;
}

// �������� ��������� ������� � ��������� ����� �� �������� �������
string IslandGetLocationFromType(string _island, string _type)
{
	ref rLoc;
	int i, iMaxLoc[MAX_LOCATIONS];
	int iRandLoc = 0;
	for(i=1; i<MAX_LOCATIONS; i++)
	{
		makeref(rLoc, locations[i]);
		if(findsubstr(rLoc.id, _type, 0) != -1 && rLoc.islandId == _island)
		{
			iMaxLoc[iRandLoc] = i;
			iRandLoc++;
		}
	}
	
	if(iRandLoc == 0)
		return "none";
	
	i = iMaxLoc[rand(iRandLoc-1)];
	return locations[i].id;
}

// ������ ���������� -->
void DisableAllExits(bool _truefalse)
{
	chrDisableReloadToLocation = _truefalse;
	bDisableFastReload         = _truefalse;
}
// ������ ���������� <--

// Warship <--

void LockQuestLine(ref refChar) // ����� ��������� �������
{
	refChar.notQuestLine = true;
}

string QuestGetGangLocation(string _areal)	// �������� ������� ��� ��������� ���� � �.�.
{
	int n;
	string island = GetArealByCityName(_areal);
	string LocationId, sAreal;
	int storeArray[MAX_LOCATIONS];
	int howStore = 0;

	for(n=0; n<MAX_LOCATIONS; n++)
	{				
		if(GiveArealByLocation(&locations[n]) == island)
		{			
			//==> �� ������ ������
			if(CheckAttribute(&locations[n], "DisableEncounters") && locations[n].DisableEncounters == true) continue;
			LocationId = locations[n].id;
			if(findsubstr(LocationId, "jungle" , 0) != -1 || findsubstr(LocationId, "Shore" , 0) != -1 || findsubstr(LocationId, "CaveEntrance" , 0) != -1)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	n = storeArray[rand(howStore-1)];
	return locations[n].id;
}

string QuestGetColony(string _city) // �������� ��������� ������� �� ��������� NPChar.city, �� ������ _city
{
    int storeArray[MAX_COLONIES];
    int howStore = 0;
	string sChrId;

	for(int n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetRelation2BaseNation(sti(colonies[n].nation)) != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "VillaAlegria" && colonies[n].id != _city)
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	return colonies[storeArray[rand(howStore-1)]].id;
}

string GetColonyExpect2Colonies(string _city1, string _city2) // �������� ��� �������
{
	int storeArray[MAX_COLONIES];
	int howStore = 0;
	string sChrId;
	ref rColony;

	for(int n=0; n<MAX_COLONIES; n++)
	{
		makeref(rColony, colonies[n]);
		if(!CheckAttribute(rColony, "HasNoFort") && rColony.nation != "none" && sti(rColony.nation) != PIRATE && GetRelation2BaseNation(sti(rColony.nation)) != RELATION_ENEMY && rColony.id != "Panama" && colonies[n].id != "Minentown"&& colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && rColony.id != _city1 && rColony.id != _city2)
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	return colonies[storeArray[rand(howStore-1)]].id;
}

// ������������� �������������� - �� ������� ������� �� �� ��������
void InitAlchemy()
{
	ref item;		
	for(int n = 0; n < ITEMS_QUANTITY; n++)
	{
		item = &Items[n];
		if( CheckAttribute(item,"multiobject") )
		{
			string sGood = item.id;
			pchar.alchemy.(sGood).isKnown = false;
			// Jason: ���������������, �.�. ������ ��������. ����� � ������� �� F22.
			//if (MOD_BETTATESTMODE == "On")		pchar.alchemy.(sGood).isKnown = true;
			//else								pchar.alchemy.(sGood).isKnown = false;
		}
	}
}

// �������� - ����� �� �� ������ �������������
bool isMultiObjectKnown(string itemId)
{
	ref item;		
	for(int n = 0; n < ITEMS_QUANTITY; n++)
	{
		item = &Items[n];
		if( CheckAttribute(item,"multiobject") )
		{
			string sGood = item.id;
			if(sGood == itemId && pchar.alchemy.(sGood).isKnown == true) return true;
		}
	}
	return false;
}

void SetAlchemyRecipeKnown(string Recipe)
{
	pchar.alchemy.(Recipe).isKnown = true;
}

void initStartState2Character(ref ch)
{// ����� ���������� � ������ ����� ����, ��������� �������� ����� ����������, ���� ������ ������ �������� � if
    NullCharacter.Siege = "";
    
	ch.SystemInfo.SaveCount = 0;
    ch.SystemInfo.LoadCount = 0;
    ch.SystemInfo.DeadCount = 0;

    ch.SystemInfo.CabinType          = ""; // boal 28.03.05 ����� ���  My_Cabin_Small
    
    ch.questTemp.Contraband.relation = 60;
	ch.questTemp.Indian.relation = 15; // ���� � ��������, �� 0 �� 100, ���� 60 - ����, ���� 20 - ����
    DeleteAttribute(ch, "quest.meeting");
    ch.ShipInStock = 0; // �������� � �����
	ch.questTemp.abordage = 0;   // ������� �������
	ch.questTemp.donate   = 0; // ������������� ������

	ch.questTemp.friend_in_tavern = ""; // ����������� boal
	ch.questTemp.RelationAgentMet = "0"; // ����������� boal

	ch.questTemp.NationQuest = ""; // ������ ������� �������

	ch.GenQuest.BrothelCount = "0"; // ������� ��������� �������
	//ch.GenQuest.Hunter2Pause   = false; // ������� ����� � ����� �� ���� - �� ������ �����
	ch.I_MAP_SHOW = false;  // boal ����� ������� �� ���������
	ch.CameraHoldPos = false;
	ch.CameraShipNPC = 0;// ����� ���������� ��� ������ 0 - ��
	ch.GenQuestFort.FarLocator = true; // ��� ������� ������� �������� � �����
    
    ch.GenQuest.Find_Merchant.lastspeak_date = "";
    ch.GenQuest.ConvoyPassenger = ""; //��������� ����������� �� ������ �������� ���������

	// ==> ��������� ������ ������� �������
	ch.questTemp.State = "";
	// ==> ���-�� ���� �������� ������ ���������� ������ �������, �������� - ��� ���
	ch.questTemp.Waiting_time = "2";
	// ==> ����� �������� ������, ����������� ����� ������, �.�. ������ ������� �� ������ ������� ��������� � ������.
	ch.questTemp.CurQuestNumber = "2";
	//��������� �������� � ���� ��� ����������� �����, ���, � ����� ��� ���� :)
	InitTravelMap();
	// ==> �������� �� ��������� �������� ����� �������
	pchar.RomanticQuest.HorseCheck = -1;
	// ==> ���������� ���� � ������������� ������
	ch.MapsAtlasCount = 0;
	// ==> ����� ���������� ����� (������� �� �������� ������������ ������ ��)
	ch.Flags.Pirate = 7;
	// ==> ������������
	ch.questTemp.Slavetrader = "canTakeQuest"; //���� �� ������ ����
	// ==> ����� ����������-������������
	SelectSlavetraderRendom(); //��� ��������������� �����
	// ==>  �����
	PoormansInit();
	// ==>  ���-�� ����, ��������� �������
	pchar.questTemp.HorseLoot = 0;
	// ==>  ���-�� ��������� �� �������
	pchar.questTemp.HorseQty = 0;
	// ==>  ��������� ������� ��� �������
	pchar.questTemp.WPU.Fraht.count = 0;
	pchar.questTemp.WPU.Postcureer.count = 0;
	pchar.questTemp.WPU.Escort.count = 0;
	// ==> �������� ���� �� ������ ������
	ch.questTemp.jailCanMove = false;
	// ==> ����� ������ �������, ������ �� ������ �� ��������
	ch.questTemp.different = "free";
	ch.questTemp.WPU = "0";
	//�������� � ����
	ch.CanGenerateShipSituation = true;
	// ==> ��������� ������� (������� ������� ��� ��� - �� ��������� �� ������ ����� ���� ��� ������� �� �������)
	InitAlchemy();
	//==> ����������� ������ - �������� ���������
	HollandGambitNpcInit();
	//==> ����� �������� - �������� ���������
	SharlieNpcInit();
	//==> ��������� ���� - �������� ���������
	SagaNpcInit();
	//==> �������� ��� LSC
	LSC_NpcInit();
	//--> ����-������, ������������������ �� ���������� �����
	pchar.quest.Red_Chieftain.win_condition.l1 = "Rank";
	pchar.quest.Red_Chieftain.win_condition.l1.value = 8; // 280313
	pchar.quest.Red_Chieftain.win_condition.l1.operation = ">=";
	pchar.quest.Red_Chieftain.function = "RedChieftain_Prepare";
	pchar.quest.False_Trace.win_condition.l1 = "Rank";
	pchar.quest.False_Trace.win_condition.l1.value = 15; // may-16
	pchar.quest.False_Trace.win_condition.l1.operation = ">=";
	pchar.quest.False_Trace.function = "FalseTrace_Prepare";
	// --> ���������
	pchar.quest.Mangarosa.win_condition.l1 = "item";
	pchar.quest.Mangarosa.win_condition.l1.item = "cannabis7";
	pchar.quest.Mangarosa.function = "Mangarosa_Start";
	// --> ��������� �������
	pchar.GenQuest.Piratekill = 0;
	// --> �������� ��������� ������ � ������ - ugeen 2016, ����� ��� ������
	pchar.questTemp.TavernVisit.counter = 0;
	pchar.questTemp.ShipyardVisit.counter = 0;

	//==> ������ - �������� ���������
	GothicNpcInit();
	// ==> ������� ���
	OfficerGirlInit();
	// ==> ���������
	OfficerMushketerInit();
	// ==>  ����� � ����� ��������� 
	BerglarsInit();
	// <==
	// ==> ������� ���
	LSCCNpcInit();
	ch.questTemp.LSCC = false;
	ch.questTemp.LSCC.checkBoxes = false; //���� �������� �������� � �������	
	pchar.quest.FirstLoginLostShipsCityy.win_condition.l1 = "location";
	pchar.quest.FirstLoginLostShipsCityy.win_condition.l1.location = "LostShipsCityy_town";
	pchar.quest.FirstLoginLostShipsCityy.function = "FirstLoginLostShipsCityy";

	// ==> ������� ������� homo
	ch.questTemp.GothicMonbar = true;

	// ==> ������� ������������
	ch.questTemp.Tenoc = "begin";
	pchar.quest.Tenoc_startInShore.win_condition.l1 = "location";
	pchar.quest.Tenoc_startInShore.win_condition.l1.location = "Bel_jungle_02";
	pchar.quest.Tenoc_startInShore.function = "Tenoc_startInShore";
	//������������ �����
	LocatorReloadEnterDisable("Shore_ship3", "reload1", true);
	ch.questTemp.MC = "begin"; //���� ������	
	pchar.quest.MC_startInCaracas.win_condition.l1 = "location";
	pchar.quest.MC_startInCaracas.win_condition.l1.location = "Caracas_town";
	pchar.quest.MC_startInCaracas.function = "MC_startInCaracas";
	// ==> ����� ��������� ������ ��������
	ch.questTemp.BlueBird = "begin";
	ch.questTemp.BlueBird.City = "SantLous_town";
	ch.questTemp.BlueBird.count = 0;
	// ==> ����� ��������.
                    //ch.questTemp.Ascold = "canTakeQuest"; // ���������, ���� ����� "", �� ���� �� ���� �����.
	// ==> ����� ������ �������� � �������� �������� �� ��������.
	SelectAscoldRendom();
	SelectAscoldRendom();
	// ==> ��������� ����� �� �������
	ch.questTemp.Sharp = "begin";
	ch.questTemp.Sharp.City = "";
	ch.questTemp.Sharp.count = 0; //������� ���-�� �������
	ch.questTemp.Sharp.brothelChance = 1; //�������, ���� ��������� ����� ����� � �������
	ch.questTemp.Sharp.SeekSpy = "begin"; //��������� ����� �� ������ ����������� �����
	// ==> ��������� �������
	// ������� ���������
	ch.GenQuest.GhostShip.DeadByMe       = 0;
	ch.GenQuest.GhostShip.KillMe         = 0;
	ch.GenQuest.GhostShip.AskAbout       = 0; // � ������� ��� ���� �������� �� ���������
	ch.GenQuest.GhostShip.lastspeak_date = "";
    GhostShipInit();
	// ==> ���������� �� ��� � ���������� ��������
	DestinyGiftPearlGen_SetSantaCatalina("none");

}

//==> eddy. ��������� ��������� '���� �����'.
void QuestActions()
{
	ref sld;
	int i;
	CompanionTravel_ProcessAllTravellers(); // Warship. ��������������� �����������-����������������
	// �������� ������������ ��������
	for (i=0; i<4; i++)
	{
		if (CheckCharacterItem(pchar, NationShortName(i)+"TradeLicence") && GetDaysContinueNationLicence(i) == -1)
		{
			TakeNationLicence(i);
		}		
	}
	//���� ���� ������� ���, �� ������� �������� �������. ���, ����� ����������.
	if (sti(pchar.questTemp.LSCC.checkBoxes))
	{
		LSCC_checkBoxes();
	}

	//************** �����. ��������� ����� ���� ���������� ������ *******************
	if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_WaitMidnight")
	{
	LocatorReloadEnterDisable("Havana_town", "houseS1", false);
                Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition.l1 = "location";
                Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition.l1.location = "Havana_houseS1";
               Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition = "GothicLeeTakeAnna_FightInHouse";
		pchar.questTemp.GothicLee = "GothicLeeTakeAnna_DoorIsOpen";
	}

	//************** ������� ���, ������� � �������� ������� *******************
	if (pchar.questTemp.LSCC == "toWineCellar")
	{
		if (GetHour() < 1)
		{
			pchar.questTemp.LSCC = "toWineCellarGone";
			sld = characterFromId("LSCCBarmen");
			LAi_SetStayTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "FleuronTavernn", "rld", "stay1");
			PChar.quest.LSCC_returnBarmen.win_condition.l1            = "Timer";
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.hour  = 1;
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.function = "LSCC_returnBarmen";
		}
		else pchar.questTemp.LSCC = "toWineCellarLate";
	}
	//************** ������� ���, ������� � �������� ��� ������������� *******************
	if (pchar.questTemp.LSCC == "toInterception")
	{
		if (pchar.location == "FleuronTavernn" && pchar.location.locator == "reload2")
		{
			DoQuestFunctionDelay("LSCC_scriptInterception", 10.0 + frand(20));
		}
		else
		{
			pchar.questTemp.LSCC = "InterceptionLate";
			AddQuestRecord("ISS_MainLine", "19");
		}
	}
	//************** ������� ���, ����� ������� ������� � ������ ���� *******************
	if (CheckAttribute (pchar, "questTemp.LSCC.Armo"))
	{
		//������ ������ �����
		if (sti(pchar.questTemp.LSCC.Armo) == 1 || sti(pchar.questTemp.LSCC.Armo) == 3 || sti(pchar.questTemp.LSCC.Armo) == 5)
		{
			if (pchar.location == "LostShipsCityy_town" && GetHour() < 2)
			{
				LAi_group_Delete("EnemyFight"); 
				sld = characterFromId("Casper_" + pchar.questTemp.LSCC.Armo);
				sld.BreakTmplAndFight = true; //��������� �� �����
				sld.reactionOnFightModeOn = true; //��������� �� ������������ ������
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
				ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "reload", "reload55");
				LAi_ActorGoToLocator(sld, "reload", "reload65", "LSCC_casperIsGone", -1.0);
				pchar.questTemp.LSCC.Armo.casperIdx = sld.index; //�������� ������, ���������� �� ������
				//������ �� ��������, ���� �� ������
				pchar.quest.LSCC_checkCasperDead.win_condition.l1               = "Location_Type";
				pchar.quest.LSCC_checkCasperDead.win_condition.l1.location_type = "LSCC_insidee";
				pchar.quest.LSCC_checkCasperDead.win_condition.l2            = "Timer";
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.hour  = 2;
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.day   = GetAddingDataDay(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.month = GetAddingDataMonth(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.year  = GetAddingDataYear(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.function = "LSCC_checkCasperDead";	
				pchar.quest.LSCC_checkCasperDead.casperIdx = sld.index;
			}
			else
			{
				pchar.questTemp.LSCC.Armo = 11; //�������� �������
			}
		}
	}

	//************** ��������� "��������� �������" *********************************
	if(CheckAttribute(pchar, "questTemp.ReasonToFast"))
	{
		if(pchar.questTemp.ReasonToFast == "SpeakHorse") // �� ������ � �����
		{
			AddQuestRecord("ReasonToFast", "2");	
			AddQuestUserData("ReasonToFast", "sSex", GetSexPhrase("","�"));			
			CloseQuestHeader("ReasonToFast");
			pchar.questTemp.ReasonToFast.end = true;
		}
		if(pchar.questTemp.ReasonToFast == "MeetPatrolFail") // � ����� ������ �� ���� ��� ����� �� �������
		{
			AddQuestRecord("ReasonToFast", "3");		
			AddQuestUserData("ReasonToFast", "sSex", GetSexPhrase("��","���"));		
			CloseQuestHeader("ReasonToFast");
			pchar.questTemp.ReasonToFast.end = true;
		}
		if(CheckAttribute(pchar, "questTemp.ReasonToFast.PatrolLocation"))
		{
			if(CheckAttribute(Locations[FindLocation(pchar.questTemp.ReasonToFast.PatrolLocation)],"DisableEncounters"))
			{
				DeleteAttribute(Locations[FindLocation(pchar.questTemp.ReasonToFast.PatrolLocation)], "DisableEncounters");
			}
		}	
		if(CheckAttribute(pchar, "questTemp.ReasonToFast.end"))
		{
			DeleteAttribute(pchar, "questTemp.ReasonToFast");
		}	
	}
	//************** ��������� "�������� �� ��������� �������" **********************
	if(CheckAttribute(pchar,"GenQuest.ShipSituation.Epidemy"))
	{
		ShipSituation_CheckConsequence(sti(pchar.GenQuest.ShipSituation.Epidemy));
	}
	//************** ������� ���-����� 5 � 20 ����� ������� ������ *******************
	if (GetDataDay() == 5 || GetDataDay() == 20)
	{
		if (CheckAttribute(NullCharacter, "capitainBase"))
		{
			string sName;
			int capIndex, a;
			aref arCapBase, arBase;
    		makearef(arBase, NullCharacter.capitainBase);
    		int	Qty = GetAttributesNum(arBase);
    		for (a=0; a<Qty; a++)
    		{
    			arCapBase = GetAttributeN(arBase, a);
				sName = GetAttributeName(arCapBase); //Id ����
				capIndex = GetCharacterIndex(sName);
    			//---------- ����� ------------
				if (capIndex == -1)
    			{	
					//���������. ���� ����� ��� ������ - ��������� ���
					/*if (CheckActiveQuest(arCapBase.Tilte1))
					{
						CitizCapIsDead_CloseQuest(arCapBase, sName);
					}*/
					DeleteAttribute(arBase, sName);
					Qty --; //��� ���������� ������ ����� ��� �������� ������ � ����
					a--;
				}
				//---------- ��� ------------
				else
				{
					if (GetNpcQuestPastDayParam(arCapBase, "checkTime") >= sti(arCapBase.checkTime))
					{
						//if (characters[capIndex].location == "none" && characters[capIndex].quest == "InMap")
						//{
							Cap_SetMapAgain(&characters[capIndex], arCapBase);
						//}
					}
				}		
    		}
		}
	}
}

//������ ������, ���� ��������� ���� ����� �� �����
void CitizCapIsDead_CloseQuest(aref arCapBase, string capId)
{
	ref sld;
	string sTemp;
	//������� ������������� ������
	sTemp = "SecondTimer_" + capId;
	if (capId == "MushketCap") sTemp = "MushketTimer";
	if (capId == "Danielle")   sTemp = "DanielleTimer";
	pchar.quest.(sTemp).over = "yes";
	//---------- ���-������������ -------------
	int iTemp = GetCharacterIndex(arCapBase.questGiver);
	if (iTemp != -1)
	{
		//������� ���������� �� ������ ������������
		ref npchar = &characters[iTemp];
		if (CheckAttribute(npchar, "quest.PortmansSeekShip") || CheckAttribute(npchar, "quest.PortmansJornal"))
		{
			DeleteAttribute(npchar, "quest.PortmansSeekShip");
			DeleteAttribute(npchar, "quest.PortmansJornal");
			npchar.quest = ""; //����������� ������ ���� ������ ��� ��������
		}
		else
		{
			sTemp = "SCQ_" + iTemp;
			pchar.quest.(sTemp).over = "yes"; 
			characters[iTemp].lifeDay = 0;
		}
	}
	string sTitle1 = arCapBase.Tilte1;
	string sTitle2 = arCapBase.Tilte2;
}

//����������������� �� ����� ������, �� ����������� ����
void Cap_SetMapAgain(ref sld, aref arCapBase) 
{
	//� ������� ������ ����
	string sGroup = "SeekCapShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	switch (arCapBase.quest)
	{
	case "mushket": 
		if (sld.cityShore == sld.quest.targetShore)
		{
			sld.quest.targetShore = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "citizen": 
		if (sld.city == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.city);
		}
		Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "robber": 
		if (sld.city == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.city);
		}
		Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "jornal": 
		if (sld.quest.baseShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.quest.baseShore);
		}
		Map_CreateTrader(sld.quest.baseShore, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "Danielle": 
		if (sld.cityShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "Avrora": 
		if (sld.cityShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break

	}
	//������ ����� �������� �� Id ���� � ���� ���-�����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = iTemp + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

// -- ����� --
void PoormansInit()
{
	ref sld;
	//����� � ����-������
	sld = GetCharacter(NPC_GenerateCharacter("SentJons_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "SentJons";	
	sld.location	= "SentJons_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto15";
	sld.forSit.locator1 = "goto17"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto4";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//����� � ����������
	sld = GetCharacter(NPC_GenerateCharacter("Bridgetown_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "Bridgetown";
	sld.location	= "Bridgetown_town";
	sld.location.group = "goto";
	sld.location.locator = "goto12";
	sld.forStay.locator = "goto12"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto19"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto4";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//����� � ������
	sld = GetCharacter(NPC_GenerateCharacter("Beliz_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "Beliz";
	sld.location	= "Beliz_town";
	sld.location.group = "goto";
	sld.location.locator = "goto9";
	sld.forStay.locator = "goto9"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto7";
	sld.forSit.locator1 = "goto19"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto3";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//����� � ��������
	sld = GetCharacter(NPC_GenerateCharacter("Caracas_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Caracas";
	sld.location	= "Caracas_town";
	sld.location.group = "goto";
	sld.location.locator = "goto20";
	sld.forStay.locator = "goto20"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto1";
	sld.forSit.locator1 = "goto21"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto23";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ���������
	sld = GetCharacter(NPC_GenerateCharacter("Cartahena_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Cartahena";
	sld.location	= "Cartahena_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto18";
	sld.forSit.locator1 = "goto14"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto6";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ������
	sld = GetCharacter(NPC_GenerateCharacter("Cumana_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Cumana";
	sld.location	= "Cumana_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto13";
	sld.forSit.locator1 = "goto15"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");	
	//����� � ���-����, ���������
	
	sld = GetCharacter(NPC_GenerateCharacter("BasTer_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "BasTer";
	sld.location	= "BasTer_town";
	sld.location.group = "goto";
	sld.location.locator = "goto18";
	sld.forStay.locator = "goto18"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto24";
	sld.forSit.locator1 = "goto16"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto17";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	
	//����� � ������
	sld = GetCharacter(NPC_GenerateCharacter("Havana_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Havana";
	sld.location	= "Havana_town";
	sld.location.group = "goto";
	sld.location.locator = "goto12";
	sld.forStay.locator = "goto12"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto22"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto23";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ���� �����
	sld = GetCharacter(NPC_GenerateCharacter("PortRoyal_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "PortRoyal";
	sld.location	= "PortRoyal_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15";
	sld.forStay.locator = "goto15"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto28"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto7";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//����� � ���� �� ������, ���������
	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "goto";
	sld.location.locator = "goto4";
	sld.forStay.locator = "goto4"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto14";
	sld.forSit.locator1 = "goto10"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//����� �� ����-����������
	sld = GetCharacter(NPC_GenerateCharacter("Charles_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "Charles";
	sld.location	= "Charles_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto19";
	sld.forSit.locator1 = "goto13"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//����� � ����� �����
	sld = GetCharacter(NPC_GenerateCharacter("PortoBello_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "PortoBello";
	sld.location	= "PortoBello_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15";
	sld.forStay.locator = "goto15"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto3";
	sld.forSit.locator1 = "goto25"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto12";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ����-�-�����, ���������
	sld = GetCharacter(NPC_GenerateCharacter("PortPax_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "PortPax";
	sld.location	= "PortPax_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14";
	sld.forStay.locator = "goto14"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto25";
	sld.forSit.locator1 = "goto13"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto11";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//����� � ��������
	sld = GetCharacter(NPC_GenerateCharacter("Santiago_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Santiago";
	sld.location	= "Santiago_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto3";
	sld.forSit.locator1 = "goto15"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto28";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ������, ��� ������
	sld = GetCharacter(NPC_GenerateCharacter("Marigo_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, HOLLAND, -1, false, "slave"));
	sld.city = "Marigo";
	sld.location	= "Marigo_town";
	sld.location.group = "goto";
	sld.location.locator = "goto16";
	sld.forStay.locator = "goto16"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto1";
	sld.forSit.locator1 = "goto4"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto9";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	//����� � �������
	sld = GetCharacter(NPC_GenerateCharacter("Tortuga_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "Tortuga";
	sld.location	= "Tortuga_town";
	sld.location.group = "goto";
	sld.location.locator = "goto23";
	sld.forStay.locator = "goto23"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto18"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//����� � ���-����, ��������
	sld = GetCharacter(NPC_GenerateCharacter("PortSpein_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "PortSpein";
	sld.location	= "PortSpein_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto14"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	//����� � ����� �������, ������-����
	sld = GetCharacter(NPC_GenerateCharacter("VillaAlegria_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "VillaAlegria";
	sld.location	= "VillaAlegria_town2";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto14"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//����� � ����-�����
	sld = GetCharacter(NPC_GenerateCharacter("SantLous_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "SantLous";
	sld.location	= "SantLous_town";
	sld.location.group = "goto";
	sld.location.locator = "goto13";
	sld.forStay.locator = "goto13"; //��� ��������� � ������ �������
	sld.forSit.locator0 = "goto17";
	sld.forSit.locator1 = "goto15"; //��� ��������, ��� ��������� � ������ �������
	sld.forSit.locator2 = "goto11";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Gothic_Quest\npc\Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	//���������� ��������
	sld = GetCharacter(NPC_GenerateCharacter("OffMushketer", "MusketeerEnglish_1", "man", "man", 25, ENGLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.location	= "SantLous_PirateHouse";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "OffMushketer";
	SetSelfSkill(sld, 80, 10, 2, 100, 80);
	SetShipSkill(sld, 5, 5, 2, 10, 5, 20, 10, 10, 70);
	SetSPECIAL(sld, 7, 4, 9, 3, 8, 7, 9);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	LAi_SetSitType(sld);
	sld.greeting = "cit_common";
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "HPPlus");
	SetCharacterPerk(sld, "Medic");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	DeleteAttribute(sld, "Items");
	LAi_SetLoginTime(sld, 0.0, 23.99);
	sld.HoldEquip = true; //���������� ������ ��� ������ ����������


	//�������� ������� � ������� ���� �� ������, ���������
	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty1", "Women_24", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit7";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty2", "Women_25", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit10";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty3", "Women_26", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty4", "Women_23", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty5", "Women_21", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit5";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");


}

//���� ����� ������������ �����, ��������� ������� ���������� � ����������
string GetQuestNationsCity(int _nation) 
{
	int n, iRes;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation != "none"  && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].id != "VillaAlegria" && sti(colonies[n].nation) == _nation && GiveArealByLocation(loadedLocation) != colonies[n].island) //�� �� ���� ������
		{
			if (GetCharacterIndex(colonies[n].id + "_tavernkeeper") > 0 && GetCharacterIndex(colonies[n].id + "_usurer") > 0)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	iRes = storeArray[dRand(howStore-1)];
	return colonies[iRes].id;
}

//���� �� ��������� �������, ���� ����� �������
string SelectNotEnemyColony(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (nation != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� �� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

//���� ����� ������������ �������, ���� ����� �������
string SelectAnyColony(string _City)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "SanAndres" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetIslandByCityName(_City) != colonies[n].islandLable) //�� �� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

string SelectAnyColony2(string _City1, string _City2)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "SanAndres" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetIslandByCityName(_City1) != colonies[n].islandLable && GetIslandByCityName(_City2) != colonies[n].islandLable) //�� �� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}



//=============== ������� ���� ====================
string Sharp_choiceAction()
{
	string sBack;
	ref sld;
	//������ ����� � �����, ���� �� ������ ��� ���-��
	Map_ReleaseQuestEncounter("Sharp");
	group_DeleteGroup("Sharp_Group");
	if (rand(3) != 2 && sti(pchar.questTemp.Sharp.count) < 5)
	{	//��� �������, ���������� �� � ������ �����
		string sCity = pchar.questTemp.Sharp.City; //���������� ����, �������� ��� ��
		pchar.questTemp.Sharp.City.rumour = true; //���� ���� ���� � ������
		pchar.questTemp.Sharp.City = GetSharpCity(); //����� ����� 
		sBack = GetSharpRumour_toCityTarget();
		pchar.questTemp.Sharp.count = sti(pchar.questTemp.Sharp.count) + 1; //�������
		AddQuestRecord("SharpPearl", "2");
		AddQuestUserData("SharpPearl", "sOldTarget", XI_ConvertString("Colony" + sCity + "Dat"));
		AddQuestUserData("SharpPearl", "sTarget", XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc"));
		if (GetIslandByCityName(pchar.questTemp.Sharp.City) != pchar.questTemp.Sharp.City)
		{
			AddQuestUserData("SharpPearl", "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(pchar.questTemp.Sharp.City) + "Dat"));
		}
		//��������� ����� ����� �� �����
		sld = characterFromId("Sharp");
		string sGroup = "Sharp_Group";
		Group_FindOrCreateGroup(sGroup);
		Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
		Group_LockTask(sGroup);
		Group_AddCharacter(sGroup, sld.id);
		Group_SetGroupCommander(sGroup, sld.id);
		sld.mapEnc.type = "trade";
		sld.mapEnc.worldMapShip = "quest_ship";
		sld.mapEnc.Name = "���� '����������'";
		string sColony= SelectAnyColony(sCity); //�������, ������ ������ ����
		int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sColony), GetArealByCityName(pchar.questTemp.Sharp.City))+3; //���� ������� ���� � �������
		Map_CreateTrader(sColony, pchar.questTemp.Sharp.City, sld.id, daysQty);
	}
	else
	{
		if (rand(5) < 4)
		{
			sBack = GetSharpRumour_inIsland();
			pchar.questTemp.Sharp.Island = GiveArealByLocation(loadedLocation);
			pchar.questTemp.Sharp.count = 0; //������� ����� ��� ����. ����
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //���� �� �������
			pchar.questTemp.Sharp.price.evil = rand(1); //������ ��� ����, ��� ������
			Pchar.quest.Sharp_loginNearIsland.win_condition.l1 = "location";
			Pchar.quest.Sharp_loginNearIsland.win_condition.l1.location = pchar.questTemp.Sharp.Island;
			Pchar.quest.Sharp_loginNearIsland.function = "Sharp_loginNearIsland";
			AddQuestRecord("SharpPearl", "3");
			SaveCurrentQuestDateParam("questTemp.Sharp");
			Log_QuestInfo("��������� �� ������.");
		}
		else
		{
			sBack = GetSharpRumour_inCity();
			pchar.questTemp.Sharp.count = 0; //������� ����� ��� ����. ����
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //���� �� �������
			pchar.questTemp.Sharp.price.evil = rand(1); //������ ��� ����, ��� ������
			float locx, locy, locz;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			sld = &characters[GetCharacterIndex("Sharp")];
			sld.dialog.currentnode = "CitySharp";
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			ChangeCharacterAddressGroup(sld, pchar.location, "patrol", LAi_FindFarLocator("patrol", locx, locy, locz));
			AddQuestRecord("SharpPearl", "11");
			Log_QuestInfo("��������� �� �����.");
		}
	}
	return sBack;
}

//���� ����� ����� 
string GetSharpCity()
{
	int n, iRes;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	if (GetBaseHeroNation() != PIRATE)
	{
	for(n=0; n<MAX_COLONIES; n++)
	{
	if (colonies[n].nation != "none" && GetRelation2BaseNation(sti(colonies[n].nation)) != RELATION_ENEMY && GiveArealByLocation(loadedLocation) != colonies[n].island && colonies[n].id != "Panama") //�� �� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	}
	else
	{
		for(n=0; n<MAX_COLONIES; n++)
		{
			if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GiveArealByLocation(loadedLocation) != colonies[n].island && colonies[n].id != "Panama") //�� �� ���� ������
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	iRes = storeArray[rand(howStore-1)];
	return colonies[iRes].id;
}
//����� �� ���������
string GetSharpRumour_default()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "������� ���� ��� �����, � ��� �����. �� ������ ��� � ������ ���, � ���� ���� - �� ����."; break;
        case 1: sRumour = "������� ���� ������� � ��� �����. ��� �� ������ � �� ����, � ��� ��� ����� ���."; break;
        case 2:	sRumour = "������� ���������� ���� ���� �� ������ ��������� �� ����..."; break;
    }
	return sRumour;
}
//����� � ������ �����
string GetSharpRumour_toCityTarget()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "������� ���������� ���� ��� � ��� � ������ �, ��� ������, ��������� '����������'... �� ������ ��� ����� ���. �� ������ �� ���� � " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + "."; break;
        case 1: sRumour = "������, ������� ���� ��� � ������ �������. ������� �����, ���� ����������... ������, ������, ��� �� ������� ��� �����. ������� �� ���� � " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + "."; break;
        case 2:	sRumour = "�� ������, ������� ��� ������ ����� ������������ ������� ����. ��, � ������ �������� �������������, ������ ���������� �������� '�� �����' �� ���������. ����... � ������ ��� ��� � ��� � ������. �������, �� ���� � " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + ". ����� �� �������..."; break;
    }
	return sRumour;
}
//����� � ������
string GetSharpRumour_inIsland()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "�� ������, ������� ���� ������ ��� ����� �� ������ �� ����� �����. ���� �� �� ������� � ��� ���� �����, �� ������� �� ��� ����� � �����."; break;
        case 1: sRumour = "������� ����... �� ���, ��� ��� �������. ������, �� ������ ��� ������� ��� �����. ���� �� ������������, �� ������� ��� ������� � ��������� �����."; break;
        case 2:	sRumour = "���������� ���� ��������� � ��� ����� ����� �� ������ ����� � ����."; break;
    }
	return sRumour;
}
//����� � ������
string GetSharpRumour_inCity()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "���� ����� ����� ������� ���� ���������� �� ���� ����� � ����. ����� ����� �� ������, �������, ��� �� � �������..."; break;
        case 1: sRumour = "������ ��� �� ����� �������� ���������� � ��������� ������. ��������, ������ ��, ���..."; break;
        case 2:	sRumour = "������� ���� ������ ������ �� ������. � �� ��� ����, ���� �� �� ������� � ��������� ���..."; break;
    }
	return sRumour;
}

//=============== ���� ������ ��������.  ====================
string BlueBurd_setTradeShip()
{
	pchar.questTemp.BlueBird.Island = GiveArealByLocation(loadedLocation);
	Pchar.quest.BlueBird_loginFleut.win_condition.l1 = "location";
	Pchar.quest.BlueBird_loginFleut.win_condition.l1.location = pchar.questTemp.BlueBird.Island;
	Pchar.quest.BlueBird_loginFleut.function = "BlueBird_loginFleut";
	pchar.questTemp.BlueBird.nation = colonies[FindColony(pchar.questTemp.BlueBird.City)].nation; //����� �������, ������ ��������
	aref aName;
	makearef(aName, pchar.questTemp.BlueBird);
	SetRandomNameToShip(aName);
	AddQuestRecord("Xebeca_BlueBird", "10");
	AddQuestUserData("Xebeca_BlueBird", "sCity", XI_ConvertString("Colony" + pchar.questTemp.BlueBird.City + "Dat"));
	AddQuestUserData("Xebeca_BlueBird", "sShipName", "'" + aName.Ship.Name + "'");
	AddQuestUserData("Xebeca_BlueBird", "sCity_2", XI_ConvertString("Colony" + pchar.questTemp.BlueBird.City + "Gen"));
	AddQuestUserData("Xebeca_BlueBird", "sTradeName", GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")));
	AddQuestUserData("Xebeca_BlueBird", "sIsland", XI_ConvertString(pchar.questTemp.BlueBird.Island + "Gen"));
	SaveCurrentQuestDateParam("questTemp.BlueBird");
	return GetBlueBirdRumour_Ship(); //����� �����
}
//����� �� ������, ������� �� ������� ��������
string GetBlueBirdRumour_Ship()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "�� ������, ������� ��������, " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + ", ����� ���������� ����������� ����� '" + pchar.questTemp.BlueBird.Ship.Name + "' � ������ ���� �� �������. ������� ����� ����� �� �����."; break;
		case 1: sRumour = "��, � ���� � ������ ���������� ������������� ���� �������! " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + " ����� �������� ����������� ����� '" + pchar.questTemp.BlueBird.Ship.Name + "' �� �������, ��� ������ ��� ����� �� ������ �����."; break;
        case 2:	sRumour = "�-��, � " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + " ��� �������� � ��������. ������ ����� ��� �������� ����� ��� ���������� � �����, � ������� ���� ��� ���������� � ���. ����� '" + pchar.questTemp.BlueBird.Ship.Name + "' ���� ����� �� �������, ��� ��!"; break;
    }
	return sRumour;
}

//������ ������� ������� ������. �������� � ����� ����, ������� ������� � ����������� �������
void SetCapitainFromSeaToCity(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InCity"; //���� � ������
	sld.City = sld.quest.targetCity; //�������� �������� ������ ��������
	sld.location	= sld.City + "_PortOffice";
	sld.location.group = "goto";
	sld.location.locator = "goto"+(rand(2)+1);
	LAi_SetCitizenType(sld);

	/*int iColony = FindColony(sld.City);
	string sGroup = "PorpmansShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
	Group_SetTaskNone(sGroup);*/

	//������ ����� ������� ����� ����� � ����
	int Qty = rand(4)+3;
	string name = "Timer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetCapitainFromCityToSea";
	pchar.quest.(name).CapId = sld.id; //� ���������� �������� Id ����
	//������� ���� � ���� ��� �������� ����� �� ����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
	//���� ����, ��� ��� � ������
	AddSimpleRumourCity(LinkRandPhrase("������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ������ � ������. �������, ��� ����� " + GetFullName(sld) + ". �� ������ ������� ���� � ���������� �����.", 
		"�� ������, �������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ������ ����� ������� � ���������� �����.", 
		"���� �� ������ ���������� � ��������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', �� ����� �������� � ���������� �����. " + GetFullName(sld) + " ������ ���..."), sld.City, Qty, 1, "none");
}
//������ ������� ������� ������. ������� � �������� �� ������
void PortmansBook_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;	
		string sTitle = characters[GetCharacterIndex(sld.quest.firstCity + "_PortMan")].id + "PortmansBook_Delivery";
		AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "4");
		AddQuestUserData(sTitle, "sCapName", GetFullName(sld));
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//��������� ����-����. �������� � ����� ����, ������� ������� � ����������� �������
void SetRobberFromMapToSea(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InPort"; //���� ���� ����� � �����
	sld.City = sld.quest.targetCity; //�������� �������� ������ ��������
	int iColony = FindColony(sld.City);
	sld.nation = colonies[iColony].nation; //����� �����, ��� � � ������

	string sGroup = "SeekCapShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
	Group_SetTaskNone(sGroup);

	//������ ����� ������� ����� ����� �� �����
	int Qty = rand(5)+4;
	string name = "SecondTimer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetRobberFromSeaToMap";
	pchar.quest.(name).CapId = sld.id; //� ���������� �������� Id ����
	//������� ���� � ���� ��� �������� ����� �� ����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
	//���� ����, ��� ��� �� �����
	AddSimpleRumourCity(LinkRandPhrase("������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ����� � ����� �� �����. �������, ��� ����� " + GetFullName(sld) + ". �������� ���, ����� � ���, �� ����� �� ������ ������.", 
		"�� ������, �������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ������ ����� ���������, ������ ���� ����� �� ������ � ����. ������� ����� �� �����, �� ������� � ����� �� �������, ������������ ���������� �� �������. � � ������� ���?..", 
		"���� �� ������ ���������� � ��������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', �� �������� � ����. " + GetFullName(sld) + " ����� �� ��� �����... � �����, �� ������ ����� � �����, �� �� ����� �� ������. ��������� ������� ����, ���� � �������� ������ ������������ �� �����."), sld.City, Qty, 1, "none");
}
//��������� ����-����. ������ � �������� �� ������
void PortmansSeekShip_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;	
		ref npchar = &characters[GetCharacterIndex(sld.quest.firstCity + "_PortMan")];
		string sTitle = npchar.id + "Portmans_SeekShip";
		AddQuestRecordEx(sTitle, "Portmans_SeekShip", "3");
		AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName)));
		AddQuestUserData(sTitle, "sShipName", sld.Ship.name);
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		iTemp = RealShips[sti(sld.Ship.Type)].basetype;
		AddQuestUserData(sTitle, "sSexWord", GetShipSexWord(ShipsTypes[iTemp].name, "����", "����"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//������ ����� ����������
void CitizCapFromMapToCity(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InCity"; //���� ���� ����� �� ������
	sld.City = sld.quest.targetCity; //�������� �������� ������ ��������
	int iColony = FindColony(sld.City);
	sld.nation = colonies[iColony].nation; //����� �����, ��� � � ������
	if (rand(1))
	{	//����� � ������
		sld.location	= sld.City + "_town";
		sld.location.group = "goto";
		sld.location.locator = "goto"+(rand(5)+1);
		LAi_SetCitizenType(sld);
		string slai_group = GetNationNameByType(sti(colonies[iColony].nation))  + "_citizens";
		LAi_group_MoveCharacter(sld, slai_group);
		//���� ����, ��� ��� �� �����
		AddSimpleRumourCity(LinkRandPhrase("������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' � ������. �������, ��� ����� " + GetFullName(sld) + ".", 
			"�� ������, �������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ������ ����� ������� � ������.", 
			"���� �� ������ ���������� � ��������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', �� ������� ��� � �� ������. " + GetFullName(sld) + " ����� �� ��� �����..."), sld.City, Qty, 1, "none");
	}
	else
	{	//����� �� ����� � �����
		string sGroup = "SeekCapShip_" + sld.index;
		group_DeleteGroup(sGroup);
		Group_AddCharacter(sGroup, sld.id);			
		Group_SetGroupCommander(sGroup, sld.id);
		Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
		Group_SetTaskNone(sGroup);
		//���� ����, ��� ��� �� �����
		AddSimpleRumourCity(LinkRandPhrase("������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ��������� � ����� �� �����. �������, ��� ����� " + GetFullName(sld) + ".", 
			"�� ������, �������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' ������ ����� ������� � ����� �����. ��� ������� ����� �� �����.", 
			"���� �� ������ ���������� � ��������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', �� ������� ��� ������� � ����� �����. " + GetFullName(sld) + " ����� �� ��� �����..."), sld.City, Qty, 1, "none");
	}
	//������ ����� ������� ����� ����� �� �����
	int Qty = rand(7)+5; //����� ������� ���� ������ �� �����
	string name = "SecondTimer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "CitizCapFromSeaToMap";
	pchar.quest.(name).CapId = sld.id; //� ���������� �������� Id ����
	//������� ���� � ���� ��� �������� ����� �� ����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

//������ ���� �� �������. ������ � �������� �� ������
void CitizSeekCap_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;
		ref npchar = &characters[GetCharacterIndex("QuestCitiz_" + sld.quest.cribCity)];
		string sTitle = sld.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
		AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "3");
		AddQuestUserData(sTitle, "sCapName", GetFullName(sld));
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//������
void SetShowTimer(float time)
{
	pchar.showTimer = time + 0.99;
	pchar.quest.ClearTimer.win_condition.l1 = "ExitFromLocation";
	pchar.quest.ClearTimer.win_condition.l1.location = pchar.location;
	pchar.quest.ClearTimer.function = "ClearTimer";
}

void ClearTimer(string qName)
{
	DeleteAttribute(pchar, "showTimer");
	ClearAllLogStrings();
}

//�������� ��������� ���� �� ������������ ��� ��� ����������� ������
void CopyPassForAztecSkull()
{
	if (CheckCharacterItem(pchar, "SkullAztecs"))
	{	
        //������ ������ ����
		DeleteAttribute(pchar, "AztecSkull");
		pchar.AztecSkull = "";
		//��������� �������� ���� 
		string sTemp,;
		aref	arFromBox, arToBox;
    	makearef(arFromBox, pchar.fellows.passengers.officers);
		makearef(arToBox, pchar.AztecSkull);
		CopyAttributes(arToBox, arFromBox);
	}
}

bool IsAztecSkullOfficer(ref sld)
{
	if (!CheckAttribute(pchar, "AztecSkull.id1")) return false;
	string sTemp;
	aref arOfficer;
    makearef(arOfficer, pchar.AztecSkull);
    for (i=1; i<=3; i++)
    {
		sTemp = "id" + i;
		if (arOfficer.(sTemp) == sld.index)
		{
			return true;
		}
	}
	return false;
}

void SetAztecUsedTotem(ref _location, string _itemId, string _locator)
{
	//-----------------------------------------
	if (_itemId == "Totem_0011")    //������� �����
	{
		DeleteAttribute(_location, "gotoFire"); 
		Log_SetStringToLog("�������� ���� �����");
		pchar.questTemp.Tenoc == "takeFire";
	}
	//-----------------------------------------
	if (_itemId == "Totem_0012") //��������� �������� ������ � ������� ����� (� ��������)
	{
		DeleteAttribute(_location, "private1.closed"); 
		Log_SetStringToLog("������ �������� ������");
	}	
	//-----------------------------------------
	if (_itemId == "Totem_0013") //������� ����� 2�
	{
		_location.lockFire.button02.active = true;
		if (CheckAttribute(_location, "lockFire.button02.active") && CheckAttribute(_location, "lockFire.button03.active"))
		{
			DeleteAttribute(_location, "gotoFire"); 
			Log_SetStringToLog("�������� ���� �����");
			pchar.questTemp.Tenoc == "takeFire";
		}
	}
	if (_itemId == "Totem_0014") //������� ����� 2�
	{
		_location.lockFire.button03.active = true;
		if (CheckAttribute(_location, "lockFire.button02.active") && CheckAttribute(_location, "lockFire.button03.active"))
		{
			DeleteAttribute(_location, "gotoFire"); 
			Log_SetStringToLog("�������� ���� �����");
			pchar.questTemp.Tenoc == "takeFire";
		}
	}
	//-----------------------------------------
	if (_itemId == "Totem_0015") //��������� �������� ������ � ������� �����
	{
		DeleteAttribute(_location, "private2.closed"); 
		Log_SetStringToLog("������ �������� ������");
	}
	//-----------------------------------------
	if (_itemId == "Totem_001" || _itemId == "Totem_002" || _itemId == "Totem_003" || _itemId == "Totem_004" || _itemId == "Totem_005" ||
		_itemId == "Totem_006" || _itemId == "Totem_007" || _itemId == "Totem_008" || _itemId == "Totem_009" || _itemId == "Totem_0010")
	{
		int n;
		int num = 0;
		int locIndex = sti(_location.idxTenoc); //������ ������������
		string sTemp;
		_location.openGreatTemplee = true;
		for (int i=1 ; i<=10; i++)
		{
			sTemp = "idx" + i;
			n = sti(locations[locIndex].temples.(sTemp));
			if (CheckAttribute(locations[n], "openGreatTemplee")) num++;
		}
		if (num >= 10)
		{
			DeleteAttribute(&locations[locIndex], "reload.l32.disable");
			DeleteAttribute(&locations[locIndex], "reload.l33.disable");
			DeleteAttribute(&locations[locIndex], "reload.l34.disable");
			AddQuestRecord("Tenochtitlan", "7");
			pchar.questTemp.Teno = "takeSkull";			
	                                   //������ ������� �����
	                                   sld = ItemsFromID("SkullAztecs");
	                                   sld.shown = true; 
	                                   sld.startLocation = "Templee_great_1";
	                                   sld.startLocator = "item1";
	                                   BackItemDescribe("SkullAztecs");
	                                   BackItemName("SkullAztecs");

		}		
	}
}


//�������� �� ������� ������� � �� � �� ������������� �����
bool CheckMainHeroTotem(string itemName)
{
    if( CheckAttribute(pchar,"Items."+itemName) && sti(pchar.Items.(itemName))>0 )	
	{
		return true;
	}
	else
	{
		for (int i=Totems_start; i<Totems_end; i++)
		{			
			if (Items[i].id == itemName)
			{
				if (CheckAttribute(&Items[i], "shown.used"))
				{
					return true;	
				}
				break;
			}
		}
	}
	return false;	
}


// --> ugeen 20.06.09 - �������� �� ������� ���� � ��
bool CheckMainHeroMap(string itemName)
{
    if( CheckAttribute(pchar,"Items."+itemName) && sti(pchar.Items.(itemName))>0 )	
	{
		return true;
	}
	return false;	
}
// <-- ugeen

// ������������� ������ �������. Warship
void OtherQuestCharactersInit()
{
	ref sld;
	
	// ����� "������ ����� �����"
	sld = GetCharacter(NPC_GenerateCharacter("Andre_Abel" , "Andre_Abel", "man", "man", 10, FRANCE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 10, 30, 35, "blade14", "pistol2", "grapeshot", 10);
	FantomMakeCoolSailor(sld, SHIP_FLEUT, "�����", CANNON_TYPE_CANNON_LBS16, 30, 30, 30);
	sld.name = "�����";
	sld.lastname = "�����";
	sld.SaveItemsForDead = true; // ��������� �� ����� ����
	sld.DontClearDead = true; // �� ������� ���� ����� 200�
	sld.dialog.FileName = "Gothic_Quest\Andre_Abel_Dialog.c";
	sld.greeting = "cit_quest";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);	// �� ���� ������ �����
	SetCharacterGoods(sld, GOOD_SHIPSILK, 700);
	SetCharacterGoods(sld, GOOD_TOBACCO, 500);
	ChangeCharacterAddressGroup(sld, "FortOrange_tavern", "sit", "sit_front4");
}

//�������� ������������� ����
void SetMushketFromMapToSea()
{
	ref sld = characterFromId("MushketCap");
	sld.quest = "InShore"; //���� ���� ����� � �����
	sld.City = sld.quest.targetCity; //�������� �������� ������ ��������
	int iColony = FindColony(sld.City);

	string sGroup = "MushketCapShip";
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+5));
	Group_SetTaskNone(sGroup);
	//������ ����� ������� ����� ����� �� �����
	int Qty = rand(2)+3;
	string name = "MushketTimer";
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetMushketFromSeaToMap";
	//������� ���� � ���� ��� �������� ����� �� ����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

//�������� ������
void SetAvroraFromMapToSea()
{
	ref sld = characterFromId("Avrora");
	sld.quest = "InShore"; //���� ���� ����� � �����
	sld.City = sld.quest.targetCity; //�������� �������� ������ ��������
	int iColony = FindColony(sld.City);

	string sGroup = "AvroraGroup";
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+3));
	Group_SetTaskNone(sGroup);
	//������ ����� ������� ����� ����� �� �����
	int Qty = rand(5)+7;
	string name = "AvroraTimer";
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetAvroraFromSeaToMap";
	//������� ���� � ���� ��� �������� ����� �� ����
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

// Warship 07.07.09 �������� - ���������� "���� ������"
void MaryCelesteInit()
{
	ref character, realShip;
	String capID = "MaryCelesteCapitan";
	String seaGroup = "MaryCelesteGroup";
	int good;
	
	// �����.. � ������� ���� ������ ��� generableGoods[15] = { GOOD_FOOD, GOOD_WEAPON, ... }; - ���� ������
	// ���� ������� �� �������, �� ��� ����
	/*int generableGoods[15] = { GOOD_FOOD, GOOD_WEAPON, GOOD_MAHOGANY, GOOD_MEDICAMENT, GOOD_ROPES,
		GOOD_SANDAL, GOOD_COFFEE, GOOD_CLOTHES, GOOD_EBONY, GOOD_TOBACCO,
		GOOD_CHOCOLATE, GOOD_WINE, GOOD_RUM, GOOD_CINNAMON, GOOD_LEATHER };*/
	
	int generableGoods[15];
	
	generableGoods[0] = GOOD_FOOD;
	generableGoods[1] = GOOD_WEAPON;
	generableGoods[2] = GOOD_MAHOGANY;
	generableGoods[3] = GOOD_MEDICAMENT;
	generableGoods[4] = GOOD_PAPRIKA;
	generableGoods[5] = GOOD_COPRA;
	generableGoods[6] = GOOD_COFFEE;
	generableGoods[7] = GOOD_CLOTHES;
	generableGoods[8] = GOOD_EBONY;
	generableGoods[9] = GOOD_TOBACCO;
	generableGoods[10] = GOOD_CHOCOLATE;
	generableGoods[11] = GOOD_WINE;
	generableGoods[12] = GOOD_RUM;
	generableGoods[13] = GOOD_CINNAMON;
	generableGoods[14] = GOOD_LEATHER;
	
	character = GetCharacter(NPC_GenerateCharacter(capID , "citiz_45", "man", "man", 50, ENGLAND, -1, true, "citizen"));
	FantomMakeCoolSailor(character, SHIP_BRIGANTINE, "���� ������", CANNON_TYPE_CANNON_LBS16, 50, 50, 50);
	character.name = "������� ����";
	character.lastname = "";
	character.mapEnc.type = "trade";
	character.mapEnc.Name = "���������� '���� ������'";
	LAi_SetImmortal(character, true);
	SetCharacterGoods(character, GOOD_RUM, 700);
	Character_SetAbordageEnable(character, false); // ���� ������������
	
	SetCrewQuantityOverMax(character, 0); // ������ ������
	
	realShip = GetRealShip(GetCharacterShipType(character));
	
	PChar.QuestTemp.MaryCeleste = "NotFind";
	PChar.QuestTemp.MaryCeleste.TurnRate = realShip.TurnRate; // ��������, ����� ����������� ��� ����������
	
	realShip.lowpolycrew = 0; // ���� ������ �� ������
	realShip.TurnRate = 1; // ���� �� ����� ������������ ���
	realShip.capacity = 2820;
	
	NullCharacterGoods(character); // ����� ������ � �����
	
	AddCharacterGoodsSimple(character, GOOD_BALLS, 		200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_GRAPES, 	200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_KNIPPELS, 	200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_BOMBS, 		100 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_POWDER, 	500 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_FOOD, 		50  + rand(50));
	AddCharacterGoodsSimple(character, GOOD_WEAPON, 	20  + rand(30));
	AddCharacterGoodsSimple(character, GOOD_MEDICAMENT, 10  + rand(20));
	AddCharacterGoodsSimple(character, GOOD_SAILCLOTH,  50  + rand(50));
	AddCharacterGoodsSimple(character, GOOD_PLANKS,     20  + rand(30));
	
	good = generableGoods[rand(14)];
	// GetCharacterFreeSpace(ref _refCharacter,int _Goods) - ������ ������� ����� �������� ������� ������ � ���� ���������
	AddCharacterGoodsSimple(character, good, GetCharacterFreeSpace(character, good) - 1);
	
	character.AlwaysFriend = true; // ������ �����
	character.ShipEnemyDisable = true; // ���� �� ��������� �� ��������
	character.CanDropSails = false; // ���� �������� ������
	
	Group_FindOrCreateGroup(seaGroup);
	Group_SetTaskAttackInMap(seaGroup, PLAYER_GROUP);
	Group_LockTask(seaGroup);
	Group_AddCharacter(seaGroup, capID);
	Group_SetGroupCommander(seaGroup, capID);
	SetRandGeraldSail(character, ENGLAND);
	
	character.fromCity = SelectAnyColony(""); // �������, �� ����� ������� ������
	character.fromShore = GetIslandRandomShoreId(GetArealByCityName(character.fromCity));
	character.toCity = SelectAnyColony(character.fromCity); // �������, � ����� ������� ������
	character.toShore = GetIslandRandomShoreId(GetArealByCityName(character.toCity));
	
	Map_CreateTrader(character.fromShore, character.toShore, capID, GetMaxDaysFromIsland2Island(GetArealByCityName(character.toCity), GetArealByCityName(character.fromCity)));
	
	//trace("���������� ���� ������ ����� �� " + character.fromCity + " � ����������� � " + character.toShore);
}

/// -------------------------------------------- ��� �������� ���� ! �� �������� !!! --------------------------
void TestShipInCurrentSea()
{
	ref sld;

	int iRank = sti(PChar.rank) + 7;

    Group_FindOrCreateGroup("Pirate_Attack");
	Group_SetType("Pirate_Attack", "war");
	
	sld = GetCharacter(NPC_GenerateCharacter("CaptainAttack_1", "mercen_"+(rand(14)+14), "man", "man", 10, PIRATE, 3, true, "quest"));
	FantomMakeSmallSailor(sld, SHIP_VALCIRIA, "���������", CANNON_TYPE_CANNON_LBS20, 60+rand(10), 55+rand(20), 55+rand(20), 50+rand(15), 55+rand(25));
	FantomMakeCoolFighter(sld, iRank, 60, 60, "blade_14", "pistol3", "grapeshot", 100);

	Group_AddCharacter("Pirate_Attack", "CaptainAttack_1");
		
	sld.SuperShooter  = true;

	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "MusketsShoot");
	
	sld.ship.Crew.Morale = 50 + rand(30);
	ChangeCrewExp(sld, "Sailors", 70 + rand(10));
	ChangeCrewExp(sld, "Cannoners", 70 + rand(10));
	ChangeCrewExp(sld, "Soldiers", 70 + rand(10));
    	
	Group_SetGroupCommander("Pirate_Attack", "CaptainAttack_1");
	Group_SetAddress("Pirate_Attack", "Cuba2", "", "");
	Group_SetTaskAttack("Pirate_Attack", PLAYER_GROUP);
	Group_LockTask("Pirate_Attack");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	
	Sea_LoginGroupCurrentSea("Pirate_Attack");
	log_info("��������� �� ���������!");
	PlaySound("interface\_EvEnemy1.wav");
}


void SelectAscoldRendom()
{
	if (CheckAttribute(&colonies[1], "nation"))
	{
		int n, nation;
		int storeArray[MAX_COLONIES];
		int howStore = 0;
		for(n=0; n<MAX_COLONIES; n++)
		{			
			if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].id != "Minentown")
			{           
				storeArray[howStore] = n;
				howStore++;
			}
		}
		nation = storeArray[rand(howStore-1)];
		pchar.questTemp.Ascold.TraderId = colonies[nation].id + "_trader";
		nation = storeArray[rand(howStore-1)];
		pchar.questTemp.Ascold.MerchantColony = colonies[nation].id; 
		nation = storeArray[rand(howStore-1)];
		while (colonies[nation].id == "Panama")
		{
			nation = storeArray[rand(howStore-1)];
		}
		pchar.questTemp.Ascold.ShipyarderId = colonies[nation].id + "_shipyarder"; 
		pchar.questTemp.Ascold.ShipyarderColony = colonies[nation].id;
		items[GetItemIndex("Azzy_bottle")].useLocation = colonies[nation].id + "_Shipyard";
	}
}


//------------------- ������� ��� ----------------------

ref CheckLSCCCitizen()
{
	ref rCharacter;
	string sTemp, sSeeked;
	sSeeked = GetStrSmallRegister(dialogEditStrings[3]);
	if (sSeeked == "�������" || sSeeked == "�������a")
	{
		return characterFromId("LSCCMayor");
	}
	if (sSeeked == "����������" || sSeeked == "�����������" || sSeeked == "���������"|| sSeeked == "����������" || sSeeked == "������ �������" || sSeeked == "������� �������")
	{
		return characterFromId("LSCCBarmen");
	}
	if (sSeeked == "����������" || sSeeked == "����������")
	{
		return characterFromId("LSCCwaitress");
	}
	if (sSeeked == "��������" || sSeeked == "�������")
	{
		return characterFromId("LSCC_Mechanic");
	}
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(rCharacter, Characters[n]);
		if (CheckAttribute(rCharacter, "city") && rCharacter.city == "LostShipsCityy")
		{
			sTemp = GetStrSmallRegister(rCharacter.name + " " + rCharacter.lastname);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
			{
				return rCharacter;			
			}
			sTemp = GetStrSmallRegister(rCharacter.lastname);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
			{
				return rCharacter;			
			}
			else
			{
				sTemp = GetStrSmallRegister(rCharacter.name);
				if (findsubstr(sSeeked, sTemp , 0) != -1)
				{
					return rCharacter;			
				}
			}
		}
	}
	return &NullCharacter;
}

string WhereLSCCCitizen(ref rCharacter)
{
	string sShip = "none";
	string sTemp;
	if (rCharacter.location	== "LostShipsCityy_town")
	{
		sTemp = rCharacter.location.locator;
		sTemp = strcut(sTemp, 4, 5);
		switch (sTemp)
		{
			case "01": sShip = "�� ��������� '��������', ��� ������"; break;
			case "02": sShip = "�� ������� '��������'"; break;
			case "03": sShip = "�� ������ '����� �����'"; break;
			case "04": sShip = "�� ������� '����������', ��� �������"; break;
			case "05": sShip = "�� ��������� '������', ��� �������"; break;
			case "06": sShip = "�� ������ '�����', � ������� �����"; break;
			case "07": sShip = "�� ������ '�����', � �������� �����"; break;
			case "08": sShip = "�� ������� '������', ��� �������"; break;
			case "09": sShip = "�� ������ '�����'"; break;
			case "10": sShip = "�� ������� '���������'"; break;
			case "11": sShip = "�� ������� '��� ��������', ��� ���������� ��������"; break;
			case "12": sShip = "�� ����� '��� ��������', � ������� �����"; break;
			case "13": sShip = "�� ����� '��� ��������', � �������� �����"; break;
			case "14": sShip = "�� ����� '����� ����������'"; break;
			case "15": sShip = "�� ������� '���'"; break;
			case "16": sShip = "�� ������� '�������'"; break;
		}
	}
	else
	{
		switch (rCharacter.location)
		{
			case "AvaShipInside33": sShip = "� ������� '���'"; break;
			case "CarolineBankk": sShip = "� ������� '��������'"; break;
			case "CeresSmithyy": sShip = "�� ������ '����� �����'"; break;
			case "EsmeraldaStoreBigg": sShip = "� ������� '����������', � ��������"; break;
			case "FenixPlatformm": sShip = "� ��������� '������'"; break;
			case "FernandaDiffIndoorr": sShip = "�� ������ '�������� ���������'"; break;
			case "FleuronTavernn": sShip = "� ��������� '������', � �������"; break;
			case "FurieShipInside22": sShip = "� ������ '�����'"; break;
			case "GloriaChurchh": sShip = "� ������� '������', � ������"; break;
			case "PlutoStoreSmalll": sShip = "�� ����� '�����'"; break;
			case "ProtectorFisherr": sShip = "� ������� '���������'"; break;
			case "SanAugustineResidencee": sShip = "� ������� '��� ��������', � ���������� ��������"; break;
			case "SanGabrielMechanicc": sShip = "� ����� '��� ��������'"; break;
			case "SantaFlorentinaShipInside44": sShip = "� ����� '����� ����������'"; break;
			case "TartarusPrisonn": sShip = "� ��������� '��������', � ������"; break;
			case "VelascoShipInside11": sShip = "� ������� '�������'"; break;
		}
	}
	return sShip;
}

//����������� �� ��������
void LSCC_checkBoxes()
{
	ref loc;
	aref arBox;
	string sName;
	for(int i=0; i<MAX_LOCATIONS; i++)
	{				
		loc = &locations[i];
		if (CheckAttribute(loc, "fastreload") && loc.fastreload == "LostShipsCityy" && loc.id != "FernandaDiffIndoorr")
		{	
			for(int n=1; n<=MAX_HANDLED_BOXES; n++)
			{
				sName = "private" + n;
				if (CheckAttribute(loc, sName) && sName != "private11")
				{					
					makearef(arBox, loc.(sName));
					if (CheckAttribute(arBox, "equip") && rand(1))
					{
						DeleteAttribute(arBox, "items");
						arBox.items = "";
					}
				}
				else break;
			}
		}
	}
}

//������� ���. ��������� ��������� �� ����� �� ����� �����
void LSCC_CheckCasperDistance(ref sld)
{
	if (!CheckAttribute(pchar, "questTemp.LSCC.Armo.Interrapt"))
	{
		sld.quest.checkCasper = true; //��� ��������� � �� warrior
		pchar.quest.LSCC_KillOneCasper.win_condition.l1 = "NPC_Death";
		pchar.quest.LSCC_KillOneCasper.win_condition.l1.character = sld.id;
		pchar.quest.LSCC_KillOneCasper.function= "LSCC_KillOneCasper";
		pchar.quest.LSCC_KillOneCasper.casperIdx = sld.index;
		pchar.questTemp.LSCC.Armo.Interrapt = true; //����� �� �������� ������ ����������
	}
	float dist;
	if (GetCharacterDistByLoc(sld, "goto", "goto12_4", &dist))
	{
		if (dist < 40.0) 
		{
			LSCC_CasperIsHelp();
		}		
	}
}
//���� ������� �� �������
void LSCC_CasperIsHelp()
{
	Log_SetStringToLog("����� ������ ���� �������� �� ����� '��� ��������'.");
	chrDisableReloadToLocation = true;
	pchar.questTemp.LSCC = "toSeekMechanikCasperOff";
	//���� ����� �����, �� ������ ����� ����
	pchar.questTemp.LSCC.Armo = 15; //���������� � ����� ������� �� ����
	pchar.quest.LSCC_KillOneCasper.over = "yes"; 
	pchar.quest.LSCC_checkCasperDead.over = "yes"; 
	//������ � �������
	int iTemp = GetCharacterIndex("Casper_head");
	if (iTemp != -1) ChangeCharacterAddressGroup(&characters[iTemp], "LostShipsCityy_town", "reload", "reload55");
	for (int i=1; i<=11; i++)
	{
		iTemp = GetCharacterIndex("Casper_"+i);
		if (iTemp != -1)
		{
			if (characters[iTemp].location != "LostShipsCityy_town")
			{
				ChangeCharacterAddressGroup(&characters[iTemp], "LostShipsCityy_town", "reload", "reload55");
			}
			else
			{
				if (!LAi_IsDead(&characters[iTemp]))
				{
					LAi_group_MoveCharacter(&characters[iTemp], "PearlGroup_2");
					DeleteAttribute(&characters[iTemp], "quest.checkCasper"); //������ ����� �� �������� ���������� �� ����
				}
			}
		}
	}
	//���������� ������
	sld = GetCharacter(NPC_GenerateCharacter("CasperMush_1", "mush_ctz_11", "man", "mushketer", 30, PIRATE, -1, false, "quest"));
	SetCharacterPerk(sld, "GunMan");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.MusketerDistance = 0;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "quest", "mushketer1");

	sld = GetCharacter(NPC_GenerateCharacter("CasperMush_2", "mush_ctz_12", "man", "mushketer", 30, PIRATE, -1, false, "quest"));
	SetCharacterPerk(sld, "GunMan");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.MusketerDistance = 0;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "quest", "mushketer2");
	//�������������, �� ������ ������
	//LAi_group_SetRelation("PearlGroup_2", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	//LAi_group_FightGroups("PearlGroup_2", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("PearlGroup_2", "OpenTheDoors");
}

//����� �� ���� ���� ������, ����� ��������� �����
void LSCC_rumourElisHusband()
{
	if (!CheckActiveQuest("ISS_ElisHusband"))
	{
		pchar.questTemp.LSCC.ElisHusband = "begin";
		AddQuestRecord("ISS_ElisHusband", "1");
	}
}
//������ �����, ����� ������� ������ � ���������
void LSCC_beginElisHusband()
{	
	// ��� ���� ������
	ref sld = GetCharacter(NPC_GenerateCharacter("MaximTailor", "shipowner_10", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "TartarusPrisonn";
	sld.location.group = "quest";
	sld.location.locator = "prison4";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\MaximTailor.c";
	sld.dialog.currentnode   = "InPrison";
	sld.cityTape = "quest"; //��� ���
	sld.greeting = "pirat_common";
	sld.location.hours = 4; //������������ ����� .. �����
	LAi_SetGroundSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
}

//����� �� �������� ������� ��������
void LSCC_rumourLostDecster()
{
	if (!CheckActiveQuest("LSCC_findDekster"))
		AddQuestRecord("LSCC_findDekster", "1");
}
void LSCC_enterAdmiralBox()
{
	if (!CheckAttribute(pchar, "questTemp.LSCC.private10"))
	{
		if (CheckAttribute(pchar, "questTemp.LSCC.lostDecster"))
		{
			if (pchar.questTemp.LSCC.lostDecster == "seekBox")
			{
				AddQuestRecord("LSCC_findDekster", "6");	
				AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("��","��"));
			}
			else
			{
				iTemp = GetCharacterIndex("LSCC_Prisoner1");
				if (iTemp != 1 && CheckAttribute(&characters[iTemp], "quest.decster"))
				{
					AddQuestRecord("LSCC_findDekster", "7");	
				}
				else
				{
					AddQuestRecord("LSCC_findDekster", "9");
					AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("��","��"));
				}
			}		
		}
		else
		{
			AddQuestRecord("LSCC_findDekster", "8");
			AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("��","��"));
		}
		pchar.questTemp.LSCC.lostDecster = "foundAdmiralBox";
		AddSimpleRumourCityTip("�� �������, ��� ��� ������ ������� �����-�� ������ ��� ���� ����. ������ ������ �� ����� ������, ����...", "LostShipsCityy", 10, 1, "LSCC", "LSCC_rumourAdmiralLostKey");
		pchar.questTemp.LSCC.private10 = true; //����� ������ �� �����������
	}
}
void LSCC_rumourAdmiralLostKey()
{
	//������ ������� ����
	ref sld = ItemsFromID("keyPanama");
	sld.shown = true; 
	sld.startLocation = "LostShipsCityy_town";
	sld.startLocator = "item" + (rand(4)+2);
	ChangeItemName("keyPanama", "itmname_keyPanama_LSCC");
	ChangeItemDescribe("keyPanama", "itmdescr_keyPanama_LSCC");
	SetTimerFunction("LSCC_admiralFoundOwnKey", 0, 0, 2); //������ �� ������ ����� �� ��������
	pchar.questTemp.LSCC.lostDecster = "admiralLostKey";
	AddQuestRecord("LSCC_findDekster", "10");
}




