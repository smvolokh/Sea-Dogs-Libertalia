// ��������� ����, ����_���
string LastSpeakDate()
{
    return environment.date.day + " " + environment.date.month;
}
// ��� �������� ��� -->
string GetNPCQuestDate(ref npchar, string _type)
{
    if (!CheckAttribute(npchar, "QuestDate." + _type))
    {
        npchar.QuestDate.(_type) = "";
    }
    return npchar.QuestDate.(_type);
}
void SetNPCQuestDate(ref npchar, string _type)
{
    npchar.QuestDate.(_type) = LastSpeakDate();
}
bool CheckNPCQuestDate(ref npchar, string _type)
{
    if (GetNPCQuestDate(npchar, _type) != LastSpeakDate())
    {
        return true;
    }
    return false;
}
// ��� �� <--
void SaveCurrentQuestDateParam(string _quest)
{ // ������ ���� ��������� ������
    aref  arQ;
    makearef(arQ, PChar.(_quest));
    
    arQ.control_day = GetDataDay();
    arQ.control_month = GetDataMonth();
    arQ.control_year = GetDataYear();
    arQ.control_time = GetTime();
}
int GetQuestPastMonthParam(string _quest)
{
    aref  arQ;
    makearef(arQ, PChar.(_quest));

    return GetPastTime("month", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time),GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
}
int GetQuestPastDayParam(string _quest)
{
    aref  arQ;
    makearef(arQ, PChar.(_quest));
    if (CheckAttribute(PChar, _quest + ".control_year"))
    {
    	return GetPastTime("day", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time),GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
	} 
	return 0;   	
}
int GetQuestPastTimeParam(string _quest)
{
    aref  arQ;
    makearef(arQ, PChar.(_quest));
    if (CheckAttribute(PChar, _quest + ".control_year"))
    {
    	return GetPastTime("hour", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
	}  
	return 0;
}
//navy -->
//���� ��� ���� �������, �.�. ����� ��������� ������.
int GetQuestPastMinutesParam(string _quest)
{
    aref  arQ;
    makearef(arQ, PChar.(_quest));
    if (CheckAttribute(PChar, _quest + ".control_year"))
    {
    	return GetPastTime("minute", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
	}
	return 0;
}
//navy <--

// eddy
// ************* ��� �������.
void SaveCurrentNpcQuestDateParam(ref _character, string _quest)
{ // ������ ���� ��������� ������
    aref  arQ;
    makearef(arQ, _character.(_quest));

    arQ.control_day = GetDataDay();
    arQ.control_month = GetDataMonth();
    arQ.control_year = GetDataYear();
    arQ.control_time = GetTime();
}

int GetNpcQuestPastDayParam(ref _character, string _quest)
{
    aref  arQ;
    makearef(arQ, _character.(_quest));
    if (CheckAttribute(_character, _quest + ".control_year"))
    {
        return GetPastTime("day", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), 0,GetDataYear(), GetDataMonth(), GetDataDay(), 0);
    }
    else {return 0;}
}

int GetNpcQuestPastDayWOInit(ref _character, string _quest)
{
    aref  arQ;
    makearef(arQ, _character.(_quest));
    if (CheckAttribute(_character, _quest + ".control_year"))
    {
        return GetPastTime("day", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), 0,GetDataYear(), GetDataMonth(), GetDataDay(), 0);
    }
    else {return 1000;}  // ���� ��� �����, �� ��� ������ ����� ����� ���� ����
}

int GetNpcQuestPastTimeParam(ref _character, string _quest)
{
    aref  arQ;
    makearef(arQ, _character.(_quest));
    if (CheckAttribute(_character, _quest + ".control_year"))
    {
    	return GetPastTime("hour", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), sti(arQ.control_time), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
	}
	return 0;
}
int GetNpcQuestPastMinutesParam(ref _character, string _quest)
{
    aref  arQ;
    makearef(arQ, _character.(_quest));
    if (CheckAttribute(_character, _quest + ".control_year"))
    {
    	return GetPastTime("minute", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), stf(arQ.control_time), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
	}
	return 0;
}

int GetNpcQuestPastMonthParam(ref _character, string _quest)
{
    aref  arQ;
    makearef(arQ, _character.(_quest));
    if (CheckAttribute(_character, _quest + ".control_year"))
    {
        return GetPastTime("month", sti(arQ.control_year), sti(arQ.control_month), sti(arQ.control_day), 0,GetDataYear(), GetDataMonth(), GetDataDay(), 0);
    }
    else {return 0;}
}
// *************


// ��������� ������ � ���������� � ��� �� ��������� ��� �� ����� �� ������� �������.
void CharacterIntoCompanionAndGoOut(ref _mainCharacter, ref _compCharacter, string _group, string _locator, int _timeToGoOut, bool _compRemove)
{
    if (!bDisableFastReload) //����� �� ������� ������, ���� �� ���������� ������ �������
	{
		bDisableFastReload = true;
		_mainCharacter.GenQuest.CallFunctionParam.CharacterIntoCompanion.FastReload = true;
	}
	if (_group == "")    {_group = "reload";}
    if (_locator == "")
    {
    	float locx, locy, locz;
        GetCharacterPos(_compCharacter, &locx, &locy, &locz);
        _locator = LAi_FindNearestFreeLocator(_group, locx, locy, locz);
    }
    LAi_ActorGoToLocation(_compCharacter, _group, _locator, "none", "", "", "", _timeToGoOut);
    _mainCharacter.GenQuest.CallFunctionParam = "Character_into_companion";
    _mainCharacter.GenQuest.CallFunctionParam.CharacterIntoCompanion.Id = _compCharacter.id;
    _mainCharacter.GenQuest.CallFunctionParam.CharacterIntoCompanion.Remove = _compRemove;
    DoQuestCheckDelay("CallFunctionParam", _timeToGoOut);
}

void Character_into_companion()    // ��������� � ������ ����.
{
    ref NPChar = characterFromID(PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Id);
    SetCompanionIndex(pchar, -1, getcharacterIndex(PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Id));
    if (PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Remove == false)    {SetCharacterRemovable(npchar, false);}
	//������� ������, ������ ���� �� ���������� ���� �������
	if (CheckAttribute(PChar, "GenQuest.CallFunctionParam.CharacterIntoCompanion.FastReload")) bDisableFastReload = false;
}

string GetBookData(int day, int mn, int year)
{
	string result = "";

	if (day < 10)
	{
	    result = result + "0";
	}
	result = result + day + ".";
	if (mn < 10)
	{
	    result = result + "0";
	}
	result = result + mn + "." + year;

    return result;
}

// ��������� ������� ����� � ���������
bool isBadReputation(ref _pchar, int _rep)
{
    if (GetCharacterPerkUsing(_pchar, "Trustworthy") || sti(_pchar.reputation.nobility) >= _rep)
    {
        return false;// good guy
    }
    return true;// bad guy
}

// --> ugeen  - ��������� ���� �������� � ������� ����� �� ����� ��������   07.07.09
void FillCabinBoxMap(ref _location, int _probability)
{
	int 	i;
	string  itemID, groupID;
    ref     itm;
	
	for (i=0; i<ITEMS_QUANTITY; i++)
	{	
		makeref(itm,Items[i]);
		if(CheckAttribute(itm, "ID") && CheckAttribute(itm, "groupID"))
		{
			itemID = itm.id;
			groupID = itm.groupID;
			if(groupID == MAPS_ITEM_TYPE && itm.mapType == "")
			{
				if(rand(_probability) == 1) 
				{
					_location.box1.items.(itemID) = 1;
					return;
				}
			}
		}		
	}
}
//<-- ugeen

//ugeen --> ��������� ������ � ����� ��������� ��������
void FillQuestHoldBox(ref _location)
{
	_location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // �����, ���� �� �����������
	
	int nShipType = sti(pchar.ship.type);

	if(CheckAttribute(pchar,"GenQuest.CaptainComission.CanFindChest"))
	{
		if(nShipType == sti(pchar.GenQuest.CaptainComission.ShipType) && !CheckAttribute(pchar,"GenQuest.CaptainComission.Treasure"))
		{
			Log_QuestInfo("������������� �������");
			DeleteAttribute(_location, "box1");
			_location.box1.items.chest = 3;
			pchar.GenQuest.CaptainComission.Treasure = true;
		}	
	}
}
// <-- ugeen

// ��������� ������ ����� �� ����� ��������
void FillAboardCabinBox(ref _location, ref _npchar)
{
    int     iTemp;
    bool    ok;
	float   nLuck;
	int 	iNation;
	int     iRnd; 
	string amap, amulet; // dlc
	
	_location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // �����, ���� �� �����������
	// ����� ��������, ��� � ������� ���������� ��������� ����, ���� ��� ����������� ����� � ������ ���� ������
	
	ok = true;
	// ��������� ��� �����

	// ��������� �������� �� ���� -> ugeen  17.06.09
	if (CheckAttribute(_npchar, "Ship.Name") && _npchar.Ship.Name == "�o�ec� �o�����" )
	{
		DeleteAttribute(_location, "box1");
		if(drand(100) > 85)
		{		
			if(rand(1) == 0) { _location.box1.items.jewelry1 = rand(1500) + 461; }
			if(rand(1) == 0) { _location.box1.items.jewelry2 = rand(800) + 1214; }
			if(rand(1) == 0) { _location.box1.items.jewelry3 = rand(2210) + 750; }
			if(rand(1) == 0) { _location.box1.items.jewelry4 = rand(3450) + 280; }
			if(rand(1) == 0) { _location.box1.items.jewelry5 = rand(2471) + 370; }
			iRnd = drand(4);
			switch (iRnd)
			{
				case 0:
					_location.box1.items.amulet_6 = 1; 
				break;
				case 1:
					_location.box1.items.amulet_9 = 1; 
				break;
				case 2:
					_location.box1.items.obereg_3 = 1; 
				break;
				case 3:
					_location.box1.items.amulet_8 = 1; 
				break;
				case 4:
					_location.box1.items.indian_5 = 1; 
				break;
			}			
		}
		else
		{
			if(rand(1) == 0) { _location.box1.items.mineral4 = rand(118) + 85; }
			_location.box1.items.mineral5 = rand(78) + 115;
			if(rand(1) == 0) { _location.box1.items.mineral8 = rand(86) + 44; }
			_location.box1.items.mineral11 = rand(146) + 131;
		}		
		_location.box1.money = 12560 + rand(1000);
		ok = false;
	}
		
	// �����  homo 22/10/06	 
	if (findsubstr(_npchar.id, "SiegeCap_" , 0) != -1)
	{
	    aref aData, itm;
	    makearef(aData, NullCharacter.Siege);
	    string sGroup = "Sea_"+NationShortName(sti(aData.nation))+"SiegeCap_1";
	    ref rchar = Group_GetGroupCommander(sGroup);  //����� �������� ���������, �� �������� �� ������
	    Log_TestInfo( _npchar.id +" == "+ rchar.id);
		if (_npchar.id == rchar.id && CheckAttribute(aData, "loot"))
		{
	        DeleteAttribute(_location, "box1");
	        _location.box1.money = sti(aData.loot);
	        _location.box1.items.potionrum = 3;
	        _location.box1.items.potionwine = 1;
	        string idmap = "map_"+aData.island;
            if (Items_FindItem(idmap, &itm) != -1)
            {
                _location.box1.items.(idmap) = 1;
            }
			if (drand(4) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����, 20% 250912
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}

	        ok = false;
		}
	}
	//homo =>
    if (findsubstr(_npchar.id, "_QuestMerchant" , 0) != -1)
    {
        if (trap)
        {
            DeleteAttribute(_location, "box1");
            _location.box1.money = (cRand(30)+1) * 40;
            _location.box1.items.blade_13 = 1;
			if (drand(4) == 2 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
            ok = false;
        }
    }
    
    if (_npchar.id == "Head_of_Gold_Squadron" )
    {
        DeleteAttribute(_location, "box2");
        _location.box2.money = 2212;
        _location.box2.items.map_normal = 1;
		
		if(drand(100) > 75)
		{		
			if(rand(1) == 0) { _location.box1.items.jewelry1 = rand(1200) + 122; }
			if(rand(1) == 0) { _location.box1.items.jewelry2 = rand(461)  + 225; }
			if(rand(1) == 0) { _location.box1.items.jewelry3 = rand(515)  + 750; }
			if(rand(1) == 0) { _location.box1.items.jewelry4 = rand(346)  + 311; }
			if(rand(1) == 0) { _location.box1.items.jewelry5 = rand(678)  + 420; }
		}	
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
        ok = false;

    }
    //homo <=

	// Jason: ������� ������ ��������� � ������ ������� �������� � ������� ��������� �����.
	//������������, 2 ������
	if (_npchar.id == "CaptainSlaveAttack_2" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 20000;
		_location.box1.items.talisman8 = 1;
        ok = false;
	}
	//������������, ������, 4 ������
	if (_npchar.id == "CapBrigAttack" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 5500;
		_location.box1.items.letter_1 = 1;
		ChangeItemDescribe("letter_1", "itmdescr_letter_1");
        ok = false;
	}
	//������������, ������
	if (_npchar.id == "GaleonCap" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 2350;
		_location.box1.items.jewelry5 = 1000;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.obereg_6 = 1;
		_location.box2.items.mineral2 = 28;
		_location.box2.items.mineral11 = 34;
		_location.box2.items.mineral18 = 3;
		_location.box2.items.mineral20 = 31;
		_location.box2.items.potion7 = 1;
		_location.box2.items.mineral31 = 2; //������������ �����
		DeleteAttribute(_location, "box3");
		_location.box3.items.mineral4 = 2;
		_location.box3.items.mineral12 = 10;
		_location.box3.items.mineral14 = 58;
		_location.box3.items.jewelry30 = 1; //������� ���
		_location.box3.items.mineral1 = 12;
		_location.box3.items.berserker_potion = 1;
        ok = false;
	}
	
	//������ ������
	if (_npchar.id == "CureerAttack")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 1000;
        _location.box1.items.jewelry1 = 50+rand(200);
        _location.box1.items.jewelry2 = 50+rand(100);
        _location.box1.items.jewelry3 = 50+rand(100);
        _location.box1.items.jewelry4 = 50+rand(100);
        _location.box1.items.jewelry5 = 50+rand(80);
        _location.box1.items.jewelry40 = 50+rand(100);
		_location.box1.items.jewelry41 = 50+rand(160);
        _location.box1.items.jewelry47 = 50+rand(150);
		_location.box1.items.jewelry48 = rand(40);
		_location.box1.items.jewelry46 = rand(200);
		DeleteAttribute(_location, "box2");
		iRnd = rand(5);
			switch (iRnd)
			{
				case 0:
					_location.box2.items.cirass2 = 1; 
				break;
				case 1:
					_location.box2.items.spyglass3 = 1; 
				break;
				case 2:
					_location.box2.items.pistol5 = 1; 
				break;
				case 3:
					_location.box2.items.blade_10 = 1; 
				break;
				case 4:
					_location.box2.items.blade_15 = 1; 
				break;
				case 5:
					_location.box2.items.pistol4 = 1; 
				break;
			}			
        ok = false;
	}
	// ������ ����, ������
	if (_npchar.id == "FalseTraceCap")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 15000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.recipe_totem_01 = 1;
		_location.box1.items.totem_01 = 1;
        ok = false;
	}
	// ��������� �����, �����
	if (_npchar.id == "PueblaCap")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 5000;
		_location.box1.items.gold_dublon = 20;
		_location.box1.items.spyglass2 = 1;
		_location.box1.items.mushket3 = 1; // patch-6
		_location.box1.items.newblade9 = 1; // ����� ����������
		_location.box1.items.pistol_02 = 1; // ����� ����������
		DeleteAttribute(_location, "box2");
		_location.box2.items.recipe_totem_06 = 1;
		_location.box2.items.totem_06 = 1;
        ok = false;
	}
	//����������� ������
	//���������� ������ �� ����������� ��������
	if (_npchar.id == "SilverCap2" && CheckAttribute(PChar, "questTemp.HWIC.Eng"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 2000;
		_location.box1.items.gold_dublon = 80;
		_location.box1.items.clock1 = 1;
		_location.box1.items.mushket3 = 1; // patch-5
        ok = false;
	}
	
	//������� �� ����������� ��������
	if (_npchar.id == "Lucas" && CheckAttribute(PChar, "questTemp.HWIC.Eng"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 20000;
		_location.box1.items.pistol4 = 1;
		_location.box1.items.obereg_7 = 1;
		_location.box1.items.obereg_5 = 1;
		_location.box1.items.jewelry8 = 5;
		_location.box1.items.jewelry7 = 2;
		_location.box1.items.jewelry11 = 1;
		_location.box1.items.gold_dublon = 145;
		_location.box1.items.potion7 = 1;
        ok = false;
	}
	
	//��������� ��� �������� - ������ ����
	if (_npchar.id == "ValCap" && CheckAttribute(PChar, "questTemp.HWIC.Self"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 200000;//����� �� ���
		_location.box1.items.gold_dublon = 175;
		_location.box1.items.obereg_7 = 1;
		_location.box1.items.jewelry8 = 5;
		_location.box1.items.clock1 = 1;
		_location.box1.items.berserker_potion = 1;
        ok = false;
	}
	
	// ��������� ����
	// ������ ��������
	if (_npchar.id == "Donovan" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 25000;//
		_location.box1.items.gold_dublon = 250;
		_location.box1.items.cirass7 = 1;
		DeleteAttribute(_location, "box2");
		_location.box2.items.recipe_totem_03 = 1;
		_location.box2.items.totem_03 = 1;
		_location.box2.items.indian_7 = 1;
        ok = false;
	}
	// ������ ������
	if (_npchar.id == "Cap_Marlin" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 12000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.map_terks = 1;
		_location.box1.items.amulet_1 = 1;
		_location.box1.items.recipe_totem_07 = 1;
		_location.box1.items.totem_07 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.jewelry17 = 20;
		_location.box2.items.jewelry18 = 15;
		_location.box2.items.jewelry1 = 10;
        ok = false;
	}
	// ������ �������
	if (_npchar.id == "Saga_Vagrant" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 15000;//
		_location.box1.items.gold_dublon = 50;
		_location.box1.items.letter_chad_1 = 1;
		ChangeItemDescribe("letter_chad_1", "itmdescr_letter_vargant");
		if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
        ok = false;
	}
	// �������, ���������
	if (_npchar.id == "Jackman" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;//
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.map_half_blaze = 1; // ��������� �����
		_location.box1.items.splinter_nh = 1; // ������� ���������
		_location.box1.items.recipe_totem_10 = 1;
		_location.box1.items.map_normal = 1;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.����� 250912
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 250;
		_location.box2.items.witches_hammer = 1; //����� �����
		_location.box2.items.letter_parol = 1; // ������� � ������� �� ������
		_location.box2.items.map_bermudas = 1;
		_location.box2.items.map_jam = 1;
		_location.box2.items.obereg_8 = 1;
		_location.box2.items.indian_9 = 1; 
		_location.box2.items.potion7 = 1;
		_location.box2.items.berserker_potion = 3;
        ok = false;
	}
	// ��������, �������
	if (_npchar.id == "Molligan" && CheckAttribute(PChar, "questTemp.Saga"))
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 5000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.jewelry16 = 1;
		_location.box1.items.tailor_tool = 1; // ���������� �����
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 50;
		_location.box2.items.letter_parol = 1;
		ChangeItemDescribe("letter_parol", "itmdescr_letter_ouster");
		_location.box2.items.indian_5 = 1;
		_location.box2.items.mineral14 = 1;
		_location.box2.items.mineral31 = 1;
        ok = false;
	}
	
	// ��� �� ��������
	// ������, ���������
	if (_npchar.id == "Rober" && CheckAttribute(PChar, "questTemp.Terrapin"))
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 200000;
		_location.box1.items.Cromvel_depeshe = 1;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		ref ritm = ItemsFromID("Cromvel_depeshe");
		ritm.Day = GetAddingDataDay(0,2,1);
		ritm.Month = GetAddingDataMonth(0,2,1);
		ritm.Year = GetAddingDataYear(0,2,1);
		DeleteAttribute(_location, "box2");
		_location.box2.items.totem_04 = 1;
		_location.box2.items.recipe_totem_04 = 1; // patch-9
        ok = false;
	}
	
	// ������, �������
	if (_npchar.id == "RoberCap2")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 12500;
		_location.box1.items.Cromvel_depeshe = 1;
		ritm = ItemsFromID("Cromvel_depeshe");
		ritm.Day = GetAddingDataDay(0,1,1);
		ritm.Month = GetAddingDataMonth(0,1,1);
		ritm.Year = GetAddingDataYear(0,1,1);
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.totem_04 = 1;
		_location.box2.items.recipe_totem_04 = 1; // patch-9
        ok = false;
	}
	
	// ������� ��������, ������� 141012
	if (_npchar.id == "Cromvel_cap_1")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 30000;
		_location.box1.gold_dublon = 200;
		_location.box1.map_normal = 1;
		_location.box1.pistol8 = 1;
		_location.box1.harpoon = 5;
		_location.box1.GunEchin = 10;
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
        ok = false;
	}
	
	// ������ ���� �� ������, �������
	if (_npchar.id == "SPsiege_cap_1")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 2;
		_location.box1.items.map_martiniqua = 1;
		_location.box1.items.mushket3 = 1;
		if (MOD_SKILL_ENEMY_RATE > 7) _location.box1.items.cirass4 = 1; 
		if (MOD_SKILL_ENEMY_RATE < 7) _location.box1.items.cirass3 = 1; 
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.cannabis7 = 1; // ���������
		_location.box2.items.totem_11 = 1;
		_location.box2.items.recipe_totem_11 = 1; 
        ok = false;
	}
	// ����� ������
	// �� � ���-�������
	if (_npchar.id == "Diegohaleon_cap")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 10000;
		_location.box1.items.Chest = 1;
		_location.box1.items.map_cuba = 1;
		_location.box1.items.blade_17 = 1;
		if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.jewelry6 = 200;
		_location.box2.items.jewelry10 = 4;
		_location.box2.items.berserker_potion = 1;
        ok = false;
	}
	// ������� ������� �����
	if (_npchar.id == "GOT_catochecap_1")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 3;
		_location.box1.items.icollection = 2;
		_location.box1.items.map_beliz = 1;
		_location.box1.items.cirass7 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.jewelry2 = 100;
		_location.box2.items.cannabis7 = 1; // ���������
		_location.box2.items.talisman6 = 1;
        ok = false;
	}
	
	// ������ ��������� - �������
	if (_npchar.id == "Willy")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 5;
		_location.box1.items.map_beliz = 1;
		_location.box1.items.cirass7 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.jewelry2 = 100;
		_location.box2.items.cannabis7 = 1; // ���������
		_location.box2.items.potion7 = 1;
        ok = false;
	}
	
	//�����������, ��������� �����
	if (_npchar.id == "ContraCureerCap" && CheckAttribute(PChar, "GenQuest.TakePostcureer"))
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = rand(10000);
		_location.box1.items.gold_dublon = rand(50);
		_location.box1.items.chest = drand(2);
		amulet = SelectRandomArtefact(3);
		_location.box1.items.(amulet) = 1;
		_location.box1.items.ContraPostLetters = 1;
        ok = false;
	}
	
	//������������, ��������� �����
	if (_npchar.id == "ContraCureerCap" && CheckAttribute(PChar, "GenQuest.TakeArsenalship"))
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = rand(10000);
		_location.box1.items.gold_dublon = rand(50);
		amulet = SelectRandomArtefact(1);
		_location.box1.items.(amulet) = 1;
		switch (drand(6))
		{
			case 0: _location.box1.items.pistol3 = 1; break;
			case 1: _location.box1.items.pistol5 = 1; break;
			case 2: _location.box1.items.cirass1 = 1; break;
			case 3: _location.box1.items.cirass2 = 1; break;
			case 4: _location.box1.items.cirass6 = 1; break;
			case 5: _location.box1.items.mushket1 = 1; break;
			case 6: _location.box1.items.mushket3 = 1; break;
		}
        ok = false;
	}
	
	//����������, ��������� �����
	if (_npchar.id == "ContraCureerCap" && CheckAttribute(PChar, "GenQuest.TakePirateship"))
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = rand(15000);
		_location.box1.items.gold_dublon = rand(100);
		_location.box1.items.icollection = drand(3);
		amulet = SelectRandomArtefact(2);
		_location.box1.items.(amulet) = 1;
		if (drand(4) == 1) _location.box1.items.mushket3 = 1;
		if (drand(4) == 3) _location.box1.items.mushket1 = 1;
        ok = false;
	}
	
	//�������������, ��������� �����
	if (_npchar.id == "ContraPassCap" && CheckAttribute(PChar, "GenQuest.TakePassenger"))
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = rand(5000);
		_location.box1.items.gold_dublon = rand(30);
		if (drand(3) == 0) _location.box1.items.mushket1 = 1;
		amulet = SelectRandomArtefact(1);
		_location.box1.items.(amulet) = 1;
		amulet = SelectRandomArtefact(2);
		_location.box1.items.(amulet) = 1;
		amulet = SelectRandomArtefact(3);
		_location.box1.items.(amulet) = 1;
        ok = false;
	}
	
	//�������
	if (_npchar.id == "Kaleuche_khaelroacap")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.blade_28 = 1;
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 5000;
        ok = false;
	}
	
	// Addon-2016 Jason, ����������� ���������� (���)
	if (_npchar.id == "OilCap2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 4500;
		_location.box1.items.obereg_8 = 1;
		_location.box1.items.obereg_1 = 1;
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 15;
        ok = false;
	}
	if (_npchar.id == "FMQN_shorecap")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 2450;
		_location.box1.items.indian_6 = 1;
		_location.box1.items.amulet_5 = 1;
        ok = false;
	}
	if (_npchar.id == "FMQP_Follower")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 1800;
		_location.box1.items.gold_dublon = 20;
		_location.box1.items.indian_9 = 1;
		_location.box1.items.amulet_11 = 1;
		_location.box1.items.obereg_2 = 1;
        ok = false;
	}

	// Addon 2016-1 Jason ��������� �������
	// ������ ������
	if (_npchar.id == "Ignasio" && CheckAttribute(PChar, "questTemp.Mtraxx.Corrida.Logbook"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 25600;//
		_location.box1.items.gold_dublon = 155;
		_location.box1.items.map_normal = 1;
		_location.box1.items.map_part1 = 1;
		_location.box1.items.wolfreeks_book = 1;
        ok = false;
	}
	// ����� ��������
	if (_npchar.id == "Cabanos")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 550;
		_location.box1.items.gold_dublon = 10;
		_location.box1.items.totem_09 = 1;
		_location.box1.items.jewelry8 = 15;
		_location.box1.items.jewelry41 = 1; // ���� 17/1
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.clock1 = 1;
		if (drand(2) == 2) _location.box2.items.cirass3 = 1;
        ok = false;
	}
	// ���������� ������
	if (_npchar.id == "Cap_Utreht")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 7800;
		_location.box1.items.gold_dublon = 30;
		_location.box1.items.indian_11 = 1;
		_location.box1.items.chest_open = 5;
		_location.box1.items.pistol3 = 1; // ���� 17/1
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.purse1 = 1;
		if (drand(4) == 1) _location.box2.items.pistol2 = 1;
        ok = false;
	}
	// �������
	if (_npchar.id == "Mtr_PasqCap_2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 5300;
		_location.box1.items.gold_dublon = 10;
		_location.box1.items.obereg_8 = 1;
		_location.box1.items.pistol5 = 1; // ���� 17/1
		_location.box1.items.jewelry42 = 1; // ���� 17/1
		_location.box1.items.map_Curacao = 1;
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.spyglass2 = 1;
		if (drand(3) == 1) _location.box2.items.blade_16 = 1;
        ok = false;
	}
	// ��������� �� �������
	if (_npchar.id == "Mtr_IgnasioSeaCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 10800;
		_location.box1.items.gold_dublon = 40;
		_location.box1.items.obereg_1 = 1;
		_location.box1.items.clock2 = 1;
		_location.box1.items.rat_poison = 1;
		
        ok = false;
	}
	// ���� �� ���
	if (_npchar.id == "Mtr_GoldCap_2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 15000;
		_location.box1.items.chest = 1;
		_location.box1.items.obereg_10 = 1;
		_location.box1.items.amulet_8 = 1;
		if (drand(3) == 3) _location.box1.items.spyglass4 = 1;
		
        ok = false;
	}

	//���, ����� �����, �������������
	if (_npchar.id == "RatCaptain" && CheckAttribute(PChar, "questTemp.Headhunter"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 21500;
		_location.box1.items.icollection = rand(2);
		_location.box1.items.jewelry1 = 20+rand(20);
        _location.box1.items.jewelry2 = 20+rand(20);
        _location.box1.items.jewelry3 = 30+rand(20);
        _location.box1.items.jewelry4 = 10+rand(10);
        _location.box1.items.jewelry6 = rand(50);
        _location.box1.items.jewelry7 = rand(100);
		_location.box1.items.jewelry10 = rand(50);
        _location.box1.items.jewelry14 = rand(50);
		_location.box1.items.jewelry15 = rand(10);
		_location.box1.items.jewelry18 = rand(100);
        ok = false;
	}
	// Jason ���
	// ������� ��������� ������� � ���� ������
	if (_npchar.id == "PatriaPP_Seacap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 20000;
		_location.box1.items.gold_dublon = 200;
		_location.box1.items.obereg_9 = 1;
		_location.box1.items.amulet_7 = 1;
		_location.box1.items.indian_7 = 1;
		
        ok = false;
	}
	// �� ���������� � ���� ������
	if (_npchar.id == "PatriaPP_Seacap_add")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 5000;
		_location.box1.items.mushket2 = 1;
		_location.box1.items.indian_1 = 1;
		
        ok = false;
	}
	// ������� ������� ���������� � ���-�������
	if (_npchar.id == "Patria_SanMartinCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 7000;
		_location.box1.items.cannabis7 = 1; // ���������
		_location.box1.items.indian_10 = 1;
		
        ok = false;
	}
	// ������� �������-������ ���������� 
	if (_npchar.id == "Patria_DiplomatCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 13000;
		_location.box1.items.obereg_10 = 1;
		_location.box1.items.harpoon = 100;
		
        ok = false;
	}
	// ������� 
	if (_npchar.id == "Patria_SiegeCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;
		_location.box1.items.Chest = 3;
		_location.box1.items.map_nevis = 1;
		_location.box1.items.cirass3 = 1;
		_location.box1.items.berserker_potion = 2;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		
        ok = false;
	}
	// ������� �������� � �����
	if (_npchar.id == "Patria_SiegeCap_4")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 25000;
		_location.box1.items.Chest = 1;
		_location.box1.items.obereg_7 = 1;
		_location.box1.items.clock2 = 1;
		_location.box1.items.totem_05 = 1;
		
        ok = false;
	}
	// 1 ���-���� � ������
	if (_npchar.id == "PatriaSlaveCap2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 10000;
		_location.box1.items.obereg_11 = 1;
		_location.box1.items.obereg_6 = 1;
		_location.box1.items.Mineral30 = 50;
		
        ok = false;
	}
	// 2 ���-���� � ������
	if (_npchar.id == "PatriaSlaveCap3")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 12000;
		_location.box1.items.obereg_9 = 1;
		_location.box1.items.indian_6 = 1;
		_location.box1.items.Mineral30 = 50;
		
        ok = false;
	}
	// �� ����������� ��������
	if (_npchar.id == "Patria_CuracaoCap1_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 30000;
		_location.box1.items.Chest = 2;
		_location.box1.items.cannabis7 = 1; // ���������
		_location.box1.items.recipe_GunEchin = 1;
		_location.box1.items.GunEchin = 100;
		
        ok = false;
	}
	// Jason ����� � ���������
	if (_npchar.id == "LH_BarbSeaCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;
		_location.box1.items.Chest = 5;
		_location.box1.items.map_bermudas = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.jewelry1 = 30;
		_location.box2.items.jewelry2 = 50;
		_location.box2.items.jewelry3 = 60;
		_location.box2.items.jewelry4 = 40;
		_location.box2.items.cannabis7 = 2; // ���������
		_location.box2.items.potion7 = 1;
		_location.box2.items.berserker_potion = 1;

        ok = false;
	}	

    // �������, ����� �7. ������������� � �����
	if (_npchar.id == "QuestCap_PL7")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 3983;
        _location.box1.items.jewelry1 = 763;
        _location.box1.items.jewelry2 = 562;
        _location.box1.items.jewelry3 = 1771;
        _location.box1.items.jewelry4 = 678;
        _location.box1.items.jewelry5 = 178;
        _location.box2.items.jewelry6 = 236;
        _location.box2.items.jewelry7 = 321;
         _location.box2.items.jewelry8= 241;
         _location.box2.items.jewelry9= 171;
         _location.box2.items.jewelry10= 58;
         _location.box3.items.jewelry10= 8;
         _location.box3.items.jewelry14 = 121;
         _location.box3.items.jewelry15 = 45;
         _location.box3.items.jewelry16 = 15;
         _location.box3.items.jewelry17 = 21;
          _location.box4.items.jewelry18 = 311;
          _location.box4.items.jewelry20 = 111;
          _location.box4.items.jewelry21 = 14;
          _location.box4.items.jewelry22 = 36;
          _location.box4.items.jewelry23 = 43;
        ok = false;
	}
    // �������, ����� �7. ������������� � �����
	if (_npchar.id == "MushketCap")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 1030;
        _location.box1.items.gold_dublon = 517;
        _location.box1.items.Mushkett2x2 = 1;
	   _location.box1.items.BackPack3 = 1;
        _location.box1.items.(amulet) = 1;
        _location.box2.items.clock2 = 1;
        _location.box2.items.Mushket1 = 1;
        _location.box1.items.map_dominica = 1;
        _location.box1.items.map_cayman = 1;
        _location.box1.items.map_terks = 1;
        ok = false;
	}
	//�������� ������
	if (_npchar.id == "PrisonEscort_Captain" && CheckAttribute(PChar, "questTemp.PrisonEscort_quest"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.items.PrisEscort_book = 1;
        _location.box1.items.ArtRing1 = 1;
        _location.box1.money = 9100;
        _location.box1.items.map_martiniqua = 1;
        ok = false;
	}
	// ����� ��������.
	if (CheckAttribute(PChar, "questTemp.Ascold.Ship"))
	{
        if (_npchar.id == pchar.questTemp.Ascold.Ship)
        {
            DeleteAttribute(_location, "box1");
        _location.box1.money = 40000;
        _location.box1.items.gold_dublon = rand(30);
        _location.box1.items.sculMa3 = 1;
        _location.box1.items.ShipsJournal_Ascold = 1;
        _location.box1.items.indian010 = 1;
        _location.box1.items.indian011 = 1;
        _location.box1.items.indian012 = 1;
        _location.box1.items.indian013 = 1;
        _location.box1.items.indian014 = 1;
        _location.box1.items.indian015 = 1;
        _location.box1.items.indian016 = 1;
        _location.box1.items.indian017 = 1;
            ok = false;
        }
	if (_npchar.id == "GhostCapt" && CheckAttribute(pchar , "GenQuest.GhostShip.LastBattle"))
	{
        // ���� ��� � �������
        DeleteAttribute(_location, "box1");
        // ������ ����� �����
        _location.box1.items.indian11 = 1;
        _location.box1.money = 66666;
        _location.box1.money = 66;
        _location.box1.items.sculMa3 = 1;
        _location.box1.items.cannabis7 = 1; // ���������
        ok = false;
	}
}
	
    if (ok) // �� ���������
    {
    	// ��� ��� ����
		
    	iTemp = GetCharacterShipClass(_npchar);
		iNation = sti(_npchar.nation);		

		if(iNation == PIRATE)
		{
			nLuck   = GetCharacterSkillToOld(Pchar, SKILL_FORTUNE);			
			if (nLuck > rand(250) && GetCharacterItem(pchar, "map_full") == 0)  // ���� 1/30 
			{
				if (GetCharacterItem(pchar, "map_part1") == 0)
				{
					_location.box1.items.map_part1 = 1;
				}
				else
				{
					if (GetCharacterItem(pchar, "map_part2") == 0)
					{
						_location.box1.items.map_part2 = 1;
					}
				}
			}
			FillCabinBoxMap(_location, 200 - (7 - iTemp) * 5); 
			if(rand(10) == 5) _location.box1.items.Chest_open = 1;
		}
		else
		{
			FillCabinBoxMap(_location, 250 - (7 - iTemp) * 5);
		}
		
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "Trade")  // ��������
		{
			_location.box1.money = (10 - iTemp) * 200 + rand(10 - iTemp) * 2000 + rand(10)*50 + rand(6 - iTemp) * 4000;
			if(rand(5) > 2)
			{
				_location.box1.items.gold_dublon = rand(10) + 4;
				if(drand(20) == 15) _location.box1.items.rat_poison = 1;		
			}	
		}
		else // ��� ���������
		{
			if(rand(3) == 1) _location.box1.items.gunpowder = 5 + rand(10);
			_location.box1.money = (10 - iTemp) * 90 + rand((10 - iTemp) * 2000);
			if(rand(4) == 1)
			{
				_location.box1.items.gold_dublon = rand(5) + 2;			
			}
		}				
		if (2-sti(RealShips[sti(_npchar.ship.type)].Class) > 0) // 1 �����
		{
			if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "war" && 2-sti(RealShips[sti(_npchar.ship.type)].Class) == 0) // ������� 2 �����
		{
			if (drand(4) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "war" && 3-sti(RealShips[sti(_npchar.ship.type)].Class) == 0) // ������� 3 �����
		{
			if (drand(6) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // ���.�����
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(pchar, "questTemp.Persian.skimitar") && drand(20) == 5 && 3-sti(RealShips[sti(_npchar.ship.type)].Class) >= 0) // 3 ����� � ����. ������ - 5% 021012
		{
			_location.box1.items.blade_23 = 1;
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "Trade" && drand(20) == 11 && 3-sti(RealShips[sti(_npchar.ship.type)].Class) >= 0) // 3 ����� � ���� ������� � �����
		{
			_location.box1.items.mineral28 = rand(2);
			_location.box1.items.mineral29 = rand(2);
		}
		if (CheckAttribute(pchar, "questTemp.Caleuche.SeekAmulet") && drand(3) == 3) // ������ ������ �� �������
		{
			_location.box1.items.kaleuche_amulet1 = 1;
		}
    }
}

// ugeen --> ���������� ����� ��������� ����������� � ����������� �� ����� �� � ������ ���������
int SetQuestCharacterRank()
{
	int rank = 25 + makeint(sti(pchar.rank)*(0.1 + MOD_SKILL_ENEMY_RATE));

	return rank;
}
// <-- ugeen

// ==> ��� ������� ���� ��� �������� �����������.
void FantomMakeCoolSailor(ref _Character, int _ShipType, string _ShipName, int _CannonsType, int _Sailing, int _Accuracy, int _Cannons)
{
    _Character.Ship.Cannons.Type = _CannonsType;
	_Character.skill.Sailing  = GetCoffDiff(_Sailing, SKILL_MAX);
	_Character.skill.Accuracy = GetCoffDiff(_Accuracy, SKILL_MAX);
	_Character.skill.Cannons  = GetCoffDiff(_Cannons, SKILL_MAX);
    _Character.DontRansackCaptain = true; //��������� �� �������
    _Character.SinkTenPercent     = false; // �� ������ ��� 10%, �� ������� � ���
    _Character.AboardToFinalDeck  = true; // ������� ������
	_Character.DontClearDead      = true;
	_Character.SaveItemsForDead   = true;
	_Character.AlwaysSandbankManeuver = true;

    _Character.Ship.Type = GenerateShipExt(_ShipType, true, _Character);
    if (_ShipName == "none" || _ShipName == "") {SetRandomNameToShip(_Character)}
    else {_Character.Ship.Name = _ShipName}

    SetBaseShipData(_Character);
    SetCrewQuantityFull(_Character);
    Fantom_SetBalls(_Character, "pirate");

	SetCharacterPerk(_Character, "FastReload");
	SetCharacterPerk(_Character, "HullDamageUp");
	SetCharacterPerk(_Character, "SailsDamageUp");
	SetCharacterPerk(_Character, "CrewDamageUp");
	SetCharacterPerk(_Character, "CriticalShoot");
	SetCharacterPerk(_Character, "LongRangeShoot");
	SetCharacterPerk(_Character, "CannonProfessional");
	SetCharacterPerk(_Character, "ShipDefenseProfessional");
	SetCharacterPerk(_Character, "ShipSpeedUp");
	SetCharacterPerk(_Character, "ShipTurnRateUp");

    DeleteAttribute(_Character, "ship.sails");// ������ ���� �� �������
    DeleteAttribute(_Character, "ship.blots");
    DeleteAttribute(_Character, "ship.masts");// ������� ������ �����
	DeleteAttribute(_Character, "ship.hulls");// ������� ������ �������� �������
    DeleteAttribute(_Character, "Killer.status"); // ����� �������� ''��� �������� �� �������''
    _Character.questTemp.abordage = 0; //����� �������� ������ ���������� �������
   	DeleteAttribute(_Character, "Abordage.Enable"); //����� ������������ ��������
}

//Jason, ������� ������������ ���������� + ����� ������ � ��������
void FantomMakeSmallSailor(ref _Character, int _ShipType, string _ShipName, int _CannonsType, int _Sailing, int _Accuracy, int _Cannons, int _Grappling, int _Defence)
{
    _Character.Ship.Cannons.Type = _CannonsType;
	_Character.skill.Sailing  = GetCoffDiff(_Sailing, SKILL_MAX);
	_Character.skill.Accuracy = GetCoffDiff(_Accuracy, SKILL_MAX);
	_Character.skill.Cannons  = GetCoffDiff(_Cannons, SKILL_MAX);
	_Character.skill.Grappling  = GetCoffDiff(_Grappling, SKILL_MAX);
	_Character.skill.Defence  = GetCoffDiff(_Defence, SKILL_MAX);
	
    _Character.DontRansackCaptain = true; //��������� �� �������
    _Character.SinkTenPercent     = false; // �� ������ ��� 10%, �� ������� � ���
    _Character.AboardToFinalDeck  = true; // ������� ������
	_Character.AlwaysSandbankManeuver = true;

    _Character.Ship.Type = GenerateShipExt(_ShipType, true, _Character);
    if (_ShipName == "none" || _ShipName == "") {SetRandomNameToShip(_Character)}
    else {_Character.Ship.Name = _ShipName}

    SetBaseShipData(_Character);
    SetCrewQuantityFull(_Character);
    Fantom_SetBalls(_Character, "pirate");

	SetCharacterPerk(_Character, "HullDamageUp");
	SetCharacterPerk(_Character, "SailsDamageUp");
	SetCharacterPerk(_Character, "CrewDamageUp");
	SetCharacterPerk(_Character, "AdvancedBattleState");
	SetCharacterPerk(_Character, "ShipSpeedUp");
	SetCharacterPerk(_Character, "ShipTurnRateUp");
	SetCharacterPerk(_Character, "Doctor1");
	SetCharacterPerk(_Character, "LongRangeGrappling");

    DeleteAttribute(_Character, "ship.sails");// ������ ���� �� �������
    DeleteAttribute(_Character, "ship.blots");
    DeleteAttribute(_Character, "ship.masts");// ������� ������ �����
	DeleteAttribute(_Character, "ship.hulls");// ������� ������ �������� �������
    DeleteAttribute(_Character, "Killer.status"); // ����� �������� ''��� �������� �� �������''
    _Character.questTemp.abordage = 0; //����� �������� ������ ���������� �������
   	DeleteAttribute(_Character, "Abordage.Enable"); //����� ������������ ��������
}

void FantomMakeCoolFighter(ref _Character, int _Rank, int _Fencing, int _Pistol, string _Blade, string _Gun, string _Bullet, float _AddHP)
{
    _Character.rank = GetCoffDiff(_Rank, 1000);
    _Character.skill.FencingS  = GetCoffDiff(_Fencing, SKILL_MAX);
    _Character.Skill.FencingL  = GetCoffDiff(sti(_Character.skill.FencingL), SKILL_MAX);
    _Character.Skill.FencingH  = GetCoffDiff(sti(_Character.skill.FencingH), SKILL_MAX); 
    _Character.skill.Pistol = GetCoffDiff(_Pistol, SKILL_MAX);
    _Character.skill.Fortune = GetCoffDiff(_Pistol, SKILL_MAX); //zagolski. ���� ����� ������ �������� �� �������, �� ����� � ������ �� ���� ����������
	_Character.chr_ai.hp = stf(_Character.chr_ai.hp) + GetCoffDiff(_AddHP, 5000);
	_Character.chr_ai.hp_max = stf(_Character.chr_ai.hp_max) + GetCoffDiff(_AddHP, 5000);
	SetCharacterPerk(_Character, "Energaiser"); // ������� ���� ���� 1.5 � �������� �������, ������ �� � ������ �������
	SetCharacterPerk(_Character, "AdvancedDefense");
	SetCharacterPerk(_Character, "CriticalHit");
	SetCharacterPerk(_Character, "Sliding");
	SetCharacterPerk(_Character, "HardHitter");
	DeleteAttribute(_Character, "Items");
	_Character.SuperShooter  = true;
	_Blade = GetGeneratedItem(_Blade);
    GiveItem2Character(_Character, _Blade);
    EquipCharacterbyItem(_Character, _Blade);
    TakeNItems(_Character,"potion1", rand(MOD_SKILL_ENEMY_RATE/2)+1);
    if (MOD_SKILL_ENEMY_RATE > 4) TakeNItems(_Character,"potion2", rand(2)+1);
	TakeNItems(_Character,"potion3", 2);
    if (_Gun != "")
	{
		if(HasSubStr(_Gun, "mushket")) // � ���������� ��������� ������ ����������
		{
			_Character.MushketType = _Gun;
			_Character.MushketBulletType = _Bullet;
			LAi_NPC_MushketerEquip(_Character);
		}
		else
		{
			GiveItem2Character(_Character, _Gun);
			EquipCharacterbyItem(_Character, _Gun);
			LAi_SetCharacterBulletType(_Character, _Bullet);
			string sGunpowder = LAi_GetCharacterGunpowderType(_Character);
			if(sGunPowder != "")
			{
				AddItems(_Character, sGunpowder, 30 + rand(20)); // Warship. �����
			}	
			LAi_SetCharacterUseBullet(_Character, _Bullet);
		}
	}

    FaceMaker(_Character);
	CirassMaker(_Character);
    SetNewModelToChar(_Character);  // ���������� ������ �� ����
}

int GetCoffDiff(float _num, int _maxRange)
{
	switch (MOD_SKILL_ENEMY_RATE)
	{
		case  1: _num *= 0.5;  break;
		case  2: _num *= 0.6; break;
		case  3: _num *= 0.7; break;
		case  4: _num *= 0.8;  break;
		case  5: _num *= 0.9; break;
		case  6: _num *= 1;    break;
		case  7: _num *= 1.1;  break;
		case  8: _num *= 1.2;  break;
		case  9: _num *= 1.3;  break;
		case 10: _num *= 1.5;  break;
	}
	_num += 0.5;
	if (_num > _maxRange) return _maxRange;
	else return sti(_num);
}
// ���������� �������� � ��������� �� ������
bool SetLocationQuestRandItem(int _index, aref _location, string _locatorName, aref al) // al - ����� �������� �� ������, ��������� ���� �� ��������� �������
{   // ����� ������������� �� ����� - ��� �������� � �������
	string  lastSpawnTimeString;
    int     n;
	string  itemId;
	aref checkAref

	/* ������
 	pchar.GenQuestRandItem.QC_Port = true;
    pchar.GenQuestRandItem.QC_Port.randitem1 = "pistol6";
    // ���� ����� ���� ���� ������
	pchar.GenQuestRandItem.QC_Port.stay = true; - ������ ����� ��� ����� ������ �� ������
	
    QC_Port - ������� ���
    randitem1 - �������
    pistol6 - �������
    
    ���� ����� ����� ��������� ���������, ��
    pchar.GenQuestRandItem.QC_Port.randitem1 = "pistol6";
    pchar.GenQuestRandItem.QC_Port.randitem2 = "pistol1";
 	*/
	lastSpawnTimeString = _location.id;
    if (CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString) && CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString +"."+_locatorName))
    {
        itemId = pchar.GenQuestRandItem.(lastSpawnTimeString).(_locatorName);
        if (!CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString +".stay"))
        {
			//--> fix eddy. ������ ���� �������� � ��������� ���������
			DeleteAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString + "." + _locatorName); // ���� ���� ���� ���
			makearef(checkAref,  pchar.GenQuestRandItem.(lastSpawnTimeString));
			if (GetAttributesNum(checkAref) == 0) DeleteAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString);
        }
        // ������ ���� �������!!!!!!!!!!!!
        n = SetRandItemShow(_index, al, itemId); // ������� 3� ������ � �������, ���� ������ ������ ����
		if (n != -1)
		{
            Log_TestInfo("SetLocationQuestRandItem");
            lastSpawnTimeString = "LastSpawnTime"+_index;
		    _location.(lastSpawnTimeString) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
            lastSpawnTimeString = "RandItemType"+_index;
        	_location.(lastSpawnTimeString) = n;
            return true;
        }
    }
    
    return false;
}
// ��������� ������
int SetRandItemShow(int _index, aref al, string _itemId)
{
    int     n;
    aref    randItem;
    
    n = Items_FindItem(_itemId, &randItem);
	if (n != -1)
	{
        if (!CheckAttribute(randItem, "model") || randItem.model == "")
    	{
    		Trace("SetRandItemShow: no model for item "+randItem.id);
    		return -1;
    	}
	    Items_LoadModel(&randItemModels[_index],  randItem);
    	SendMessage(&randItemModels[_index], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));

        return n;
    }
    return n;
}

// ��������� ������
bool SetLocationQuestBox(ref _location, string _locatorName)
{   // ����� ������������� �� ����� - ��� �������� � �������
    bool    ok = false;
    string  locId;
    aref    arToBox;
    aref    arFromBox;

    /* ������
 	pchar.GenQuestBox.Havanna_town_04 = true;
    pchar.GenQuestBox.Havanna_town_04.box1.items.jewelry1 = 4;
    pchar.GenQuestBox.Havanna_town_04.box1.items.mineral2 = 10;
    // ���� ����� ������, ����� �� ���������
	pchar.GenQuestBox.Havanna_town_04.box1.money          = 100;
    // ���� ����� ���� ���� ������
	pchar.GenQuestBox.Havanna_town_04.stay = true; - ������ ����� ��� ����� ������ �� ������

    Havanna_town_04 - ������� ���
    box1 - �������
    items - ������ ���������
    
    ���� ����� ����� ��������� ���������, ��
    pchar.GenQuestBox.Havanna_town_04.box2.items.jewelry1 = 34;
 	*/
 	locId  = _location.id;
    if (CheckAttribute(pchar , "GenQuestBox." + locId) && CheckAttribute(pchar , "GenQuestBox." + locId + "." + _locatorName))
    {
        Log_TestInfo("SetLocationQuestBox");

        makearef(arToBox, _location.(_locatorName));
        makearef(arFromBox, pchar.GenQuestBox.(locId).(_locatorName));
        CopyAttributes(arToBox, arFromBox);
        _location.(_locatorName) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // ������, ���� �� ��������� �������� ��� ������ �� �������
        if (!CheckAttribute(pchar , "GenQuestBox." + locId +".stay"))
        {
			//--> fix eddy. ������ ���� �������� � ��������� ���������
			DeleteAttribute(pchar , "GenQuestBox." + locId + "." + _locatorName); // ���� ���� ���� ���
			makearef(arToBox,  pchar.GenQuestBox.(locId));
			if (GetAttributesNum(arToBox) == 0) DeleteAttribute(pchar , "GenQuestBox." + locId);
        }
        return true;
    }
    return false;
}

// ==> ����� ��������\�������� ��������� ������. ���� _flag=true - ������� �������, ���� _flag=false - �������.
void LocatorReloadEnterDisable(string _locationID, string _locator, bool _flag)
{
    aref arDis, arRld;
	makearef(arRld, Locations[FindLocation(_locationID)].reload);
	int	Qty = GetAttributesNum(arRld);
	for (int i=0; i<Qty; i++)
	{
		arDis = GetAttributeN(arRld, i);
        if (arDis.name == _locator)
        {
    		if (_flag) arDis.disable = 1;
    		else DeleteAttribute(arDis, "disable");
            break;
        }
	}
}

//===>>> ������� �� ������ � ����������� �������. ����. ================================================================
// == _strNormal - ������� ������ �������
// == _strBad1, _strBad2, _strBad3 - ������ ������� ����������,  "" � "none" - ������� �����.
// == _kind - ��� ����������: "repeat" - ��������� �� ��������� ���� ��� �������, ��� ��� ������ �� ���������� (�� ������������ ����-����).
//                            "quest"  - ��������� ����������, �� ��������� �� ��������� ����, �� ����� ���� ����� ���� ���������� ����� �������� �� �����.
//                            "block"  - ������� ��� �� ��������� ����� ��� ��������� �����, ��� ����, ����� ���������� ���������, �� �� ��������. ����� ������ �� ������.
//                            "cycle"  - ������ ���� �� ����������, ����� �� ��������. �� ����. ���� ��� ���������.
// == _terms ��� "repeat" � "quest" - ����� � ���� ���������� ����-����� ����� ������������� �����-�����, ���� == 0, �� ������ �������� (���������� ������ ����� �������).
//    _terms ��� "block" - ����� �������� � ����� � ����, ���� 0 - ��������.
// == _character � _Node - npchar � Dialog.CurrentNode
string NPCStringReactionRepeat(string _strNormal, string _strBad1, string _strBad2, string _strBad3, string _kind, int _terms, ref _character, string _Node)
{
    _Node = stripblank(_Node); //fix spaces
	string strBack;
    string strTemp = "quest.repeat." + _Node;
    if (!CheckAttribute(_character , strTemp))
    {
        _character.quest.repeat.(_Node) = 0;
        _character.quest.repeat.(_Node).ans = 0;
    }
    if (_kind == "cycle" || _kind == "repeat") //�� ����.���� ��� ���������.
    {
        if (GetNpcQuestPastDayParam(_character, strTemp) >= 1)
        {
            _character.quest.repeat.(_Node) = 0;
            _character.quest.repeat.(_Node).ans = 0;
        }
    }
    else
    {
        if (GetNpcQuestPastDayParam(_character, strTemp) >= _terms && _terms!=0 && _kind != "quest") //������ �� "block"
        {
            _character.quest.repeat.(_Node) = 0;
            _character.quest.repeat.(_Node).ans = 0;
        }
    }
    switch(_character.quest.repeat.(_Node))
	{
        case "0":
            strBack = _strNormal;
            _character.quest.repeat.(_Node) = 1;
            _character.quest.repeat.(_Node).ans = 0;
            SaveCurrentNpcQuestDateParam(_character, strTemp);
        break;
        case "1":
            if (_strBad1 == "none" || _strBad1 == "")
            {
                strBack = LinkRandPhrase("� �� ���� �������� �� ����� � ��� �� �� ��������� ���.",
                          "�� ��� �������� �� ����.",
                          "��� ���� �� ��� ���������.");
            }
            else
            {
                strBack = _strBad1;
            }
            _character.quest.repeat.(_Node) = 2;
            _character.quest.repeat.(_Node).ans = 1;
        break;
        case "2":
            if (_strBad2 == "none" || _strBad2 == "")
            {
                strBack = LinkRandPhrase("��� ��� ��������, ��� � �� ���� �������� �� ����� � ��� �� �� ������ ���!",
                          "��������, �� ��� �������� �� ����!",
                          "� �� ������, �� ��� ��� ���������. �������� � �������?");
            }
            else
            {
                strBack = _strBad2;
            }
            _character.quest.repeat.(_Node) = 3;
            _character.quest.repeat.(_Node).ans = 2;
        break;
        case "3":
            if (_strBad3 == "none" || _strBad3 == "")
            {
                strBack = LinkRandPhrase("� �� ������� ����� � ���� ��������.",
                          "�� ���� � ����� ������ �������������!",
                          "�� ���� �������� ��������"+ GetSexPhrase("","�") +", �������� ������� �����.");
            }
            else
            {
                strBack = _strBad3;
            }
            // ==> ������� �� ������ ����������.
            if (_kind == "cycle") //����� �� ������ ������.
            {
			    _character.quest.repeat.(_Node) = 0;
            }
			else
            {
                if(_kind != "block") //���� block, �� ����� � ��������� ������
                {
                    _character.quest.repeat.(_Node) = 4;
                    CharacterAddAngry(_character, _Node, _kind, _terms);
    			}
            }
            _character.quest.repeat.(_Node).ans = 3;
        break;
        case "4":
            strBack = "NPCStringReactionRepeat error!!!"
        break;
	}
    return strBack;
}

string HeroStringReactionRepeat(string _strNormal, string _strBad1, string _strBad2, string _strBad3, ref _character, string _Node)
{
    _Node = stripblank(_Node); //fix spaces
	string strBack;
    int Temp = sti(_character.quest.repeat.(_Node).ans);
    switch(Temp)
	{
        case "0":
            strBack = _strNormal;
        break;
        case "1":
            if (_strBad1 == "none" || _strBad1 == "")
            {
                strBack = LinkRandPhrase("������, ��������.",
                          "��� �������.",
                          "�� �� ������"+ GetSexPhrase("","�") +", ������...");
            }
            else
            {
                strBack = _strBad1;
            }
        break;
        case "2":
            if (_strBad2 == "none" || _strBad2 == "")
            {
                strBack = LinkRandPhrase("������, ������. ������ �� ��������.",
                          "��� �������, ������ �� ���� �������.",
                          "������, ���-�� � ������� �� � �����... ������ � ���� �������������...");
            }
            else
            {
                strBack = _strBad2;
            }
        break;
        case "3":
            if (_strBad3 == "none" || _strBad3 == "")
            {
                strBack = LinkRandPhrase("��� ������.",
                          "����� ����...",
                          "�������� ������.");
            }
            else
            {
                strBack = _strBad3;
            }
        break;
        case "4":
            strBack = "HeroStringReactionRepeat error!!!"
        break;
	}
    return strBack;
}

// �������� ������ ��� ���������� ����: _GoNode1 � _GoNode2, ������ �� �����, �.�. ���� ����� � �����-����.
// �������, ������� ������ ���� ��� ������ � �������.
string DialogGoNodeRepeat(string _NormalNode, string _GoNode1, string _GoNode2, string _GoNode3, ref _character, string _Node)
{
    _Node = stripblank(_Node); //fix spaces
	string strBack, Temp;
    Temp = sti(_character.quest.repeat.(_Node).ans);
    switch(Temp)
	{
        case "0":
            strBack = _NormalNode;
        break;
        case "1":
            if (_GoNode1 == "none" || _GoNode1 == "")
            {
                strBack = "exit";
            }
            else
            {
                strBack = _GoNode1;
            }
        break;
        case "2":
            if (_GoNode2 == "none" || _GoNode2 == "")
            {
                strBack = "exit";
            }
            else
            {
                strBack = _GoNode2;
            }
        break;
        case "3":
            if (_GoNode3 == "none" || _GoNode3 == "")
            {
                strBack = "exit";
            }
            else
            {
                strBack = _GoNode3;
            }
        break;
        case "4":
            strBack = "exit"
            Log_SetStringToLog("DialogGoNodeRepeat#4 error!!!");
        break;
    }
    return strBack;
}

// _Node - ��� ����, ������������� ������� �����. ���� ����� ���������� �� � ���������� �����, �� == "none".
void CharacterAddAngry(ref _character, string _Node, string _kind, int _terms)
{
    if (_kind == "repeat" || _kind == "quest")
    {
        DeleteAttribute(_character, "angry");
        _character.angry.kind = _kind;
        _character.angry.name = _Node; //� ��� ���� ����, ��� ���������� ������ �����
        if (_terms != 0) // ���� == 0, �� ����� ������������ � �������� �������.
        {
            _character.angry.terms = _terms;
            SaveCurrentNpcQuestDateParam(_character, "angry.terms");
            if (_terms < 10) // ������ �������������� �� ����������, ���� �/�
            {
                _character.angry.QtyMoney = (rand(10)+1) * 500;
            }
            else
            {
                _character.angry.QtyMoney = (rand(10)+1) * 5000;
            }
        }
        else
        {
            _character.angry.QtyMoney = (rand(10)+1) * 10000;
        }
    }
    else {Log_Info("CharacterAddAngry error!!!");}
}

void CharacterDelAngry(ref _character)
{
    DeleteAttribute(_character, "angry");
    DeleteAttribute(_character, "quest.repeat");
}

//� �������� ���������� ���������� ���������� ����� �� �������, ����� ���������������.
//���� ���� ������ ��� � �����, ����� � ���� ������������ �����, �� ���� ����� ���������� ����� ����������.
//�����. ������ ���� ���������� ������ �������.
void QuestSetCurrentNode(string _chID, string _Node)
{
    ref chref = characterFromID(_chID);
    if (CheckAttribute(chref, "angry")) chref.dialog.TempNode = _Node;
    else chref.dialog.currentnode = _Node;
}

// ����� �� ���� ���
string NPCharSexPhrase(ref _character, string StrMan, string StrWoman)
{
	string strBack;
    if (_character.sex == "woman")
    {
        strBack = StrWoman;
    }
    else
    {
        strBack = StrMan;
    }
    return strBack;
}
// ����� �� ���� ��
string GetSexPhrase(string StrMan, string StrWoman)
{
    return NPCharSexPhrase(PChar, StrMan, StrWoman);
}

//Jason --> ����� �� ����� ���������
string GetNatPhrase(ref _character, string StrEng, string StrFra, string StrSpa, string StrHol)
{
	string strBack;
    if (_character.nation == ENGLAND || _character.nation == PIRATE)
    {
        strBack = StrEng;
    }
    else
	{
		if (_character.nation == FRANCE)
		{
        strBack = StrFra;
		}
		else
		{
			if (_character.nation == SPAIN)
			{
			strBack = StrSpa;
			}
			else
			{
			strBack = StrHol;
			}
		}
	}
    return strBack;
}
//<-- ����� �� ����� ���������
//<<<=== ������� �� ������ � ����������� �������. =======================================================================


// �������� ��������� ��� ������ � ����� ������� � ������
//--------------------------------------------------------
bool SetTempRemoveParam(ref _refCharacter, string _param)
{
    string sParam = "TmpRemember" + _param;
    
	if( CheckAttribute(_refCharacter, sParam) ) return false;
	if( !CheckAttribute(_refCharacter, _param) ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.(sParam));
	aref srcRef; makearef(srcRef, _refCharacter.(_param));

	CopyAttributes(dstRef,srcRef);
	return true;
}

// ������������ ������ � ����� ������ ������� �� ������
//------------------------------------------------------
bool RestoreTempRemoveParam(ref _refCharacter, string _param)
{
    string sParam = "TmpRemember" + _param;
    
	if( !CheckAttribute(_refCharacter, sParam) ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.(_param));
	aref srcRef; makearef(srcRef, _refCharacter.(sParam));

	DeleteAttribute(_refCharacter, _param);
	//--> eddy. ��������� ���� ������, ����� ����� � �����.
	_refCharacter.(_param) = "";
	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter, sParam);
	return true;
}

// ��������� ������ ������ � ���������� ��� ������� ������
// �����: �������� ������ �� � ��������� ������ - ����� ��� ������ ����� � ����������� ��� ��� ������
void SetCaptureResidenceQuest(string _city, string _method, bool _majorOff)
{
    PChar.GenQuestFort.ResidenceQuest.(_city) = true;
    // ������� �� ����������� �� ������� ������, �� ��������, �� ����� ������� ����������, ���� �� ������ ��� ����.
    PChar.GenQuestFort.ResidenceQuest.(_city).MayorOff = _majorOff;
    if (_method != "")
    {
        PChar.GenQuestFort.ResidenceQuest.(_city).method = _method;
	}
}

// ������ ������ ����� ��������� � �������
void  SetReturn_Gover_Dialog_Exit(ref NPChar)
{
	LAi_LoginInCaptureTown(NPChar, false);

	PChar.GenQuest.GoverIdx = NPChar.index;
	Pchar.quest.Return_Gover_Dialog_Exit.win_condition.l1          = "ExitFromLocation";
    Pchar.quest.Return_Gover_Dialog_Exit.win_condition.l1.location = Pchar.location;
    Pchar.quest.Return_Gover_Dialog_Exit.win_condition             = "Return_Gover_Dialog_Exit";
}

void SetNewModelToChar(ref chref)
{
    float liveTime = 0.1;
	int colors = argb(64, 64, 64, 64);
	int colore = argb(0, 32, 32, 32);

    if (IsEntity(chref))
    {
    	if(CheckAttribute(chref, "model"))
        {
            SendMessage(chref, "lss",   MSG_CHARACTER_SETMODEL, chref.model, chref.model.animation);
        }
        if(CheckAttribute(chref, "equip.gun"))
        {
            SendMessage(chref, "ls",    MSG_CHARACTER_SETGUN,   chref.equip.gun);
        }
        if(CheckAttribute(chref, "equip.blade"))
        {
			ref rItem = ItemsFromID(chref.equip.blade);
            //SendMessage(chref, "lsfll", MSG_CHARACTER_SETBLADE, chref.equip.blade, liveTime, colors, colore);
            //SendMessage(chref, "llsfll", MSG_CHARACTER_SETBLADE, 0, chref.equip.blade, liveTime, colors, colore);
			SendMessage(chref, "llsfll", MSG_CHARACTER_SETBLADE, 0, rItem.model, liveTime, colors, colore);
        }
    }
}
// ������� �� �����_������
void SetNationToOfficers(int _nat)
{
    int j, cn;
    ref officer;

    for(j=1; j<COMPANION_MAX; j++)
    {
        cn = GetCompanionIndex(GetMainCharacter(),j);
        if( cn>0 )
        {
	        officer = GetCharacter(cn);
	        if (!GetRemovable(officer)) continue;
	        officer.nation = _nat;
	        Ship_FlagRefresh(officer); //���� �� ����
	    }
	}
}

bool IsOfficerCompanion(ref _refCharacter)
{
	int findIdx = sti(_refCharacter.index);
	ref mc = GetMainCharacter();
	int ci, cn;
	ref npc;
	for(int i=1; i<COMPANION_MAX; i++)
	{
		ci = GetCompanionIndex(mc,i);
		npc = GetCharacter(ci);
		for(int j=1; j<4; j++)
		{
			if(GetOfficersIndex(npc,j)==findIdx) return true;
		}
	}
	return false;
}
///////////////////////////////////////////////////////////////////
void SortItems(ref NPChar)
{// ������������� �������� � �������, �������
    aref   arToChar;
    aref   arFromChar;
    object objChar;
    int    i;
    aref   curItem;
	string attr;
	ref    itm;
	ref    rObj;
	int    iSortIndex;
	bool   ok;

    objChar.Items = "";
    rObj = &objChar;

    makearef(arToChar,   rObj.Items);
    makearef(arFromChar, NPChar.Items);

    CopyAttributes(arToChar, arFromChar);

    DeleteAttribute(NPChar, "Items");
    NPChar.Items = "";

    makearef(arFromChar, NPChar.equip); // ����������
    int iMax = GetAttributesNum(arFromChar);
    for(i=0; i<iMax; i++)
    {
        curItem = GetAttributeN(arFromChar, i);
        attr = GetAttributeValue(curItem);
        if (attr != "") //������� ������
        {
        	NPChar.Items.(attr) = sti(rObj.Items.(attr));
        }
    }
    // ������������� ���������� �� ������� itm.SortIndex
	// ����������� ������� ������������ ��������� - ����� ���� ����������!!, ���������� � 1 - ����� �����
	ok = true;
	iSortIndex = 1;
	while (iSortIndex < 3)// 2 ����
	{
		ok = false;
		for (i=0; i<TOTAL_ITEMS; i++)
		{
			// Warship 11.05.09 fix ��� ����� ������� ���������
			if(!CheckAttribute(&Items[i], "ID"))
			{
				continue;
			}
			
			makeref(itm, Items[i]);
			attr = itm.id;
			if (CheckAttribute(rObj, "items."+attr) && CheckAttribute(itm, "SortIndex") && sti(itm.SortIndex) == iSortIndex)
			{
                NPChar.Items.(attr) = sti(rObj.Items.(attr));
	   			ok = true;
	      	}
	    }
	    iSortIndex++;
    }
    // ��� ���������
    for (i=0; i<TOTAL_ITEMS; i++)
	{
		// Warship 11.05.09 fix ��� ����� ������� ���������
		if(!CheckAttribute(&Items[i], "ID"))
		{
			continue;
		}
		
		makeref(itm, Items[i]);
		attr = itm.id;
		if (CheckAttribute(rObj, "items."+attr) && !CheckAttribute(itm, "SortIndex"))
		{
   			NPChar.Items.(attr) = sti(rObj.Items.(attr));
   			ok = true;
      	}
    }
}
// ��������� ��������� ������� � ���
void SetQuestGoodsToStore(ref refStore)
{
	string    goodName;
	// ������ ������������� �� �����_������
	/*
	pchar.GenQuest.StoreGoods.StoreIdx = Bridgetown_STORE;
	pchar.GenQuest.StoreGoods.NowNeedToBe = true;
	*/
	if (CheckAttribute(pchar, "GenQuest.StoreGoods.StoreIdx") && refStore.index == pchar.GenQuest.StoreGoods.StoreIdx)
	{
        // ������ ��������� ������� pchar.GenQuest.StoreGoods.StoreIdx = LaVega_STORE;
		/*if (CheckAttribute(pchar, "GenQuest.StoreGoods.NowNeedToBe")) // ��������� ���������, �� ����� ������
		{
		    DeleteAttribute(pchar, "GenQuest.StoreGoods"); // ����������� ��������, ���� ��� �����
		    goodName = Goods[GOOD_RUM].Name;
		    refStore.Goods.(goodName).Quantity       = 666;
		    // ���� �� ��������� ���������� 20 � �����������
			refStore.Goods.(goodName).RndPriceModify = GetStoreGoodsRndPriceModify(refStore, GOOD_RUM, PRICE_TYPE_BUY, pchar, 20);
		}  */
		if (CheckAttribute(pchar, "GenQuest.StoreGoods.Starting")) // ���������� �������� ���� �� ������ �� ������
		{
		    DeleteAttribute(pchar, "GenQuest.StoreGoods"); // ����������� ��������, ���� ��� �����
		    goodName = Goods[GOOD_BALLS].Name;
		    refStore.Goods.(goodName).Quantity = 300;
			goodName = Goods[GOOD_GRAPES].Name;
			refStore.Goods.(goodName).Quantity = 300;
			goodName = Goods[GOOD_KNIPPELS].Name;
			refStore.Goods.(goodName).Quantity = 300;
			goodName = Goods[GOOD_BOMBS].Name;
			refStore.Goods.(goodName).Quantity = 300;
			goodName = Goods[GOOD_FOOD].Name;
			refStore.Goods.(goodName).Quantity = 500;
			goodName = Goods[GOOD_MEDICAMENT].Name;
			refStore.Goods.(goodName).Quantity = 150;
			goodName = Goods[GOOD_WEAPON].Name;
			refStore.Goods.(goodName).Quantity = 100;
			goodName = Goods[GOOD_RUM].Name;
			refStore.Goods.(goodName).Quantity = 100;
		} 
		if (CheckAttribute(pchar, "GenQuest.StoreGoods.Guardoftruth")) // ������ �� ���������
		{
			DeleteAttribute(pchar, "GenQuest.StoreGoods"); // ����������� ��������, ���� ��� �����
		    goodName = Goods[GOOD_CINNAMON].Name;
		    refStore.Goods.(goodName).Quantity = 127;
		}		
	}
}

// ����� ��������� �������� � ����� �� ��������. ������ �������� �� ����� + �����
// refChar - ��� ������, � �� �������� ���, �� �����, ������ �� ����������, �� �� � ������ �� ���, � ���������, ������� ��������� ����� ���� �������
// CaptanId - �������� �� ����, ����������� � ������ �����������.
void SetQuestAboardCabinDialog(ref refChar)
{
	// ������. ��� ����� ��� �����, ��� ��� ������ ���� �� ����������� �������� �� �������
	//refChar.DontClearDead      = true;
	//refChar.SaveItemsForDead   =   true;
	//TakeNItems(refChar, "Chest", 1);
	// ������. <--

	if (CheckAttribute(refChar, "CaptanId"))
	{
        pchar.GenQuest.QuestAboardCabinDialogIdx = refChar.index;
        // ��� ������������, ������
		/*if (true) // true - ��� �����, ������ ���� ��� CheckAttribute(pchar, "��������� �����, ���� �����") && refChar.CaptanId == "IdNPC")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
            refChar.Dialog.Filename    = "Capitans_dialog.c";   // ��� ����� ������ �� ����������� ���� � �� �����
	    	refChar.Dialog.CurrentNode = "QuestAboardCabinDialog";
	    	// ��� ��������� � �������, �� �������
		}*/
		//������� �� ������ ���� �� ����� � ����������� ������.
		if (refChar.CaptanId == "MQPirate" && CheckAttribute(pchar, "GenQuest.DestroyPirate"))
		{
		    LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.dialog.currentnode = "DestroyPirate_Abordage";
		}
		//������ �� �� �� ������� �� ����� homo
		if (findsubstr(refChar.CaptanId, "_QuestMerchant" , 0) != -1  && trap)
		{
		    LAi_SetCheckMinHP(refChar, 30, true, "QuestAboardCabinDialog");  // ������� �� ���
		    refChar.dialog.filename = "Capitans_dialog.c";  //fix homo 23/03/07
			refChar.dialog.currentnode = "MerchantTrap_Abordage";
		}
		//����� �������� ����������� �������
		if (findsubstr(refChar.CaptanId, "SeekCap_" , 0) != -1)
		{
		    LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.CurrentNode = "SeekCap"; //���� ���������� ����
		}
		//��������� ���������
		if (findsubstr(refChar.CaptanId, "SeekCitizCap_" , 0) != -1)
		{
			if (refChar.quest.SeekCap == "NM_battle")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
				refChar.Dialog.CurrentNode = "NM_battleBoard"; //���� ���������� ����
			}
			if (refChar.quest.SeekCap == "NM_prisoner")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
				refChar.Dialog.CurrentNode = "NM_prisonerBoard"; //���� ���������� ����
			}
			if (refChar.quest.SeekCap == "manRapeWife")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
				refChar.Dialog.CurrentNode = "RapeWifeCap_Board"; //���� ���������� ����
			}
		    if (refChar.quest.SeekCap == "womanRevenge")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
				refChar.Dialog.CurrentNode = "RevengeCap_board"; //���� ���������� ����
			}
			if (refChar.quest.SeekCap == "womanPirates")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // ������� �� ���
				refChar.Dialog.CurrentNode = "PiratesCap_Board"; //���� ���������� ����
			}
		}
		//��������� "��������� �������" 
		if (refChar.CaptanId == "PirateCapt")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		}
		
		// Warship ����� "������ �� ����������"
		if(refChar.CaptanId == "PiratesOnUninhabited_BadPirate")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "PiratesOnUninhabited_46"; //���� ���������� ����
		}
		
		// ���������� "��������� �������� ''�����'' ��� ''�������� ������''"
		if(CheckAttribute(pchar,"GenQuest.CaptainComission") && pchar.GenQuest.CaptainComission == "Begin")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "CaptainComission_1"; //���� ���������� ����
		}
		
		if(refChar.CaptanId == "ShipWreck_BadPirate")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "ShipWreck_50"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Slaveshorecap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "TakeShoreCap"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "RatCaptain")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Rat_talk"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Jafar")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Ja_talk"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Fleetwood")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\Fleetwood.c";
			refChar.Dialog.CurrentNode = "Fleetwood_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "JacobBerg")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\JacobBerg.c";
			refChar.Dialog.CurrentNode = "JacobBerg_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Lucas")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\LucasRodenburg.c";
			refChar.Dialog.CurrentNode = "Lucas_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Knippel")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\Knippel.c";
			refChar.Dialog.CurrentNode = "Knippel_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "CureerCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Cureer_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Longway")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\HollandGambit\Longway.c";
			refChar.Dialog.CurrentNode = "Longway_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "FalseTraceCap")//������ ����
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\LineMiniQuests\FalseTrace.c";
			refChar.Dialog.CurrentNode = "FalseTrace_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Vaskezs_helper")//����������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Portugal_dialog.c";
			refChar.Dialog.CurrentNode = "VaskezsHelper_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "ConJuan")//���� �������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\LineMiniQuests\Consumption.c";
			refChar.Dialog.CurrentNode = "Juan_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "MarginCap")//������ ����������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Marginpassenger.c";
			refChar.Dialog.CurrentNode = "MarginCap_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "ContraPassCap")//����� ������ - ��� - ��������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "MayorQuests_dialog.c";
			refChar.Dialog.CurrentNode = "ContraPass_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Donovan")//����, ������ ��������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Saga\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Donovan_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Jackman")//����, �������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Mayor\Jackman.c";
			refChar.Dialog.CurrentNode = "Jackman_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "RoberCap2")//��������, ������
		{
		    LAi_SetCheckMinHP(refChar, 100, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Sharlie\Terrapin.c";
			refChar.Dialog.CurrentNode = "rober_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Kaleuche_khaelroacap")//�������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Caleuche_dialog.c";
			refChar.Dialog.CurrentNode = "CaleucheCap_3"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "FMQG_Juan" && CheckAttribute(pchar,"questTemp.FMQG") && pchar.questTemp.FMQG != "fail") // Addon-2016 Jason ���-���������
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\LineMiniQuests\FMQ_Guadeloupe.c";
			refChar.Dialog.CurrentNode = "Juan"; //���� ���������� ����		
		}
		// Addon 2016-1 Jason ��������� �������
		if (refChar.CaptanId == "Ignasio" && CheckAttribute(pchar, "questTemp.Mtraxx.Corrida.Logbook"))
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\Roger.c";
			refChar.Dialog.CurrentNode = "ignasio_boarding"; //���� ���������� ����		
		}
		
		//������� ����� ������ ���������� ����.(����� ����.)
		if (refChar.CaptanId == "RobertBlake")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		    refChar.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
		    refChar.Dialog.CurrentNode = "RobertBlake"; //���� ���������� ����
		}

///////////////////////////////////////////////////////////////////

		//������������ �����, ����� ������� � �������
		if (refChar.CaptanId == "Avrora")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
                                           DoQuestFunctionDelay("ZOM_ATTACK", 0.3);
		}

		//������� ����� "������ ��������"
		if (refChar.CaptanId == "BlueBirdCapitain" && pchar.questTemp.BlueBird == "toSeaBattle")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		}
		//������� ����� "������ ��������"
		if (refChar.CaptanId == "BlueBirdTrader" && pchar.questTemp.BlueBird == "attackFleut")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		}
		//�������, ������ ��� �� ����� ������� ����
		if (refChar.CaptanId == "EdwardLoy" && pchar.questTemp.piratesLine == "KillLoy_SeaWolfBattle")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		}
		//�������, ����� �7, ���, ��������� ��������
		if (refChar.CaptanId == "LeonCapitain" && pchar.questTemp.piratesLine == "Soukins_seekLeon")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
		}
		if (refChar.CaptanId == "Slaveshorecap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "TakeShoreCap"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "RatCaptain")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Rat_talk"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "Jafarry")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Ja_talk"; //���� ���������� ����		
		}

		if (refChar.CaptanId == "TerraxCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Terrax_abordage"; //���� ���������� ����		
		}

		if (refChar.CaptanId == "FiamatarCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Fiamatar_abordage"; //���� ���������� ����		
		}
		if (refChar.CaptanId == "GhostCapt" && CheckAttribute(pchar,"GenQuest.GhostShip.Prize"))
		{
		    LAi_SetCheckMinHP(refChar, 50, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.CurrentNode = "GhostCapt_LastDialog";
		}
		// Jason ����� � ���������
		if (refChar.CaptanId == "LH_BarbSeaCap_1")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // ������� �� ���
			refChar.Dialog.FileName = "Quest\LongHappy.c";
			refChar.Dialog.CurrentNode = "Barbazon_boarding"; //���� ���������� ����		
		}
	}
}

// ugeen --> �������� �� �������� � ����� ���������� ���� (�������� ��� �����)
void SetQuestAboardCabinDialogSituation(ref refChar)
{
	LAi_SetFightMode(pchar, false);
	LAi_LockFightMode(pchar, true);
	refChar.Dialog.FileName = "GenQuests_Dialog.c";	
	switch(refChar.situation.type)
	{
		case "pirate": 	// ������ ��� ��	
			refChar.Dialog.CurrentNode = "ShipSituation11";
		break;
		case "hunter": 	// ���
			refChar.Dialog.CurrentNode = "ShipSituation31";
		break;
		case "war": 	// ������� �������
			refChar.Dialog.CurrentNode = "ShipSituation21";
		break;
		case "trade": 	// ��������
			refChar.Dialog.CurrentNode = "ShipEpidemy1";
		break;		
	}
	LAi_SetActorType(refChar);
	LAi_ActorDialog(refChar, pchar, "", -1, 0); 
}
// <-- ugeen

void QuestAboardCabinDialogFree()
{
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
    LAi_SetWarriorType(sld);
    LAi_group_MoveCharacter(sld, LAI_GROUP_BRDENEMY);
}
//����� ��� ������, �� � ���� �� ����
void QuestAboardCabinDialogNotBattle()
{
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
    LAi_SetWarriorType(sld);
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
}
// ����� � �������
void QuestAboardCabinDialogExitWithBattle(string _questName)
{
    QuestAboardCabinDialogFree(); // ������ �����
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	LAi_SetFightMode(pchar, true);
	LAi_SetFightMode(sld, true);
	LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck(LAI_GROUP_BRDENEMY, _questName);
	// SetCharacterTask_Fight(sld, pchar);
}

void QuestAboardCabinDialogExitWithBattleNoParam()// homo ���� �����, ������ ��� ����������
{
    QuestAboardCabinDialogExitWithBattle("");
}

void QuestAboardCabinDialogSurrender()
{
 	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	DeleteAttribute(sld, "DontRansackCaptain"); // ���� ���� �����-��
	pchar.GenQuest.QuestAboardCaptanSurrender = true;
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
	//�� ����� ������� LAi_SetCurHP(characterFromId(sld.CaptanId), 0.0); 
	//sld.LifeDay = 0;    ��� �� ������ �����������, � ������ �������, ������ �� ��� ��� �������� �������, �� �� ��� ��������
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
}
//==> ��������� �������� � ����������� ������� ��������.
void QuestAboardCabinDialogQuestSurrender()
{
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	sld.DontRansackCaptain = true; // ���� �� ������ ������ ���
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
	//�� ����� ������� LAi_SetCurHP(characterFromId(sld.CaptanId), 0.0); 
	//sld.LifeDay = 0;
	pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(sld);
	SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
}

// eddy. �������� �������� ��������. -->
//���� ��������
void GiveNationLicence(int _nation, int _validity)
{
	string sTemp; 
	ref rItem;
	for(int i=0; i<4; i++)
	{
		if (CheckNationLicence(i) && GetDaysContinueNationLicence(i) == -1) TakeNationLicence(i);
	}
	if (_nation != PIRATE) 
	{
		if (CheckNationLicence(_nation)) TakeNationLicence(_nation);
		sTemp = NationShortName(_nation)+"TradeLicence";
		GiveItem2Character(pchar, sTemp);
		rItem = ItemsFromID(sTemp);
		SaveCurrentNpcQuestDateParam(rItem, "Action_date");
		rItem.Action_date = GetCurrentDate(); 
		rItem.Validity = FindRussianDaysString(_validity); //������ ��� ���������
		rItem.Validity.QtyDays = _validity; //����� �������� �������� � ���� ��� ��������
	}
}
//������� �������� 
void TakeNationLicence(int _nation)
{
	string sTemp; 
	if (_nation != PIRATE && CheckNationLicence(_nation)) 
	{
		sTemp = NationShortName(_nation)+"TradeLicence";
		TakeItemFromCharacter(pchar, sTemp);
		DeleteAttribute(ItemsFromID(sTemp), "Action_date");
		DeleteAttribute(ItemsFromID(sTemp), "Validity");
	}
}
//��������� ������� ��������
bool CheckNationLicence(int _nation)
{
	if (_nation != PIRATE) 
	{
		if (CheckCharacterItem(pchar, NationShortName(_nation)+"TradeLicence")) return true; 
	}
	return false;
}
//��������� ����� ��������, ������� �������� ����. ���� -1, �� ���������� ��� �����������
int GetDaysContinueNationLicence(int _nation)
{
	int iTerms = -1;
	ref rItem;
	if (_nation != PIRATE) 
	{
		if (CheckNationLicence(_nation))
		{
			rItem = ItemsFromID(NationShortName(_nation)+"TradeLicence");
			
			if(!CheckAttribute(rItem, "Validity")) // Warship 10.07.09 fix - ���� �� �����, ����� �� ����
			{
				return -1;
			}
			
			int Validity = sti(rItem.Validity.QtyDays);
			iTerms = GetNpcQuestPastDayParam(rItem, "Action_date");
			if (iTerms > Validity) iTerms = -1;
			else iTerms = Validity - iTerms;
		}
	}
	return iTerms;
}
//���� ������������ ��������, �������� ''�������� ����������� ����-������� ��������''
string GetRusNameNationLicence(int _nation)
{
	string sTemp, itmTitle;
	int lngFileID;
	if (_nation != PIRATE) 
	{
		if (CheckNationLicence(_nation))
		{
			sTemp = NationShortName(_nation)+"TradeLicence";
			lngFileID = LanguageOpenFile("ItemsDescribe.txt");
			itmTitle = LanguageConvertString(lngFileID, Items[GetItemIndex(sTemp)].name);
		}
	}
	return itmTitle;
}
// eddy. �������� �������� ��������. <--

void SelectSlavetraderRendom() // ������������, ����� ������
{
	if (CheckAttribute(&colonies[1], "nation"))
	{
		int n, nation;
		int storeArray[MAX_COLONIES];
		int howStore = 0;
		for(n=0; n<MAX_COLONIES; n++)
		{			
			if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && colonies[n].id != "FortOrange" && colonies[n].id != "Havana" && colonies[n].id != "Santiago" && colonies[n].id != "Portroyal" && colonies[n].id != "Villemstad" && colonies[n].id != "Charles" && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "SanAndres" && colonies[n].id != "VillaAlegria" && colonies[n].id != "PortAntonio")
			{           
				storeArray[howStore] = n;
				howStore++;
			}
		}
		nation = storeArray[rand(howStore-1)];
		pchar.questTemp.Slavetrader.UsurerId = colonies[nation].id + "_usurer";
	}
}

void HollandGambitNpcInit()//����������� - ������� ���� �������� ���������� �� ����� ������ �����
{
//--------------------------------����-�������� ���� � �����������--------------------------------------
	//����� ���������
	sld = GetCharacter(NPC_GenerateCharacter("Lucas", "Lucas", "man", "man", 30, HOLLAND, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "���������";
	sld.greeting = "rodenburg_1";
	sld.rank = 30;
	LAi_SetHP(sld, 350, 350);
	sld.Dialog.Filename = "Quest\HollandGambit\LucasRodenburg.c";
	sld.dialog.currentnode = "First time";
	GiveItem2Character(sld, "blade_17");
	sld.equip.blade = "blade_13";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld,"potion2", 5);
	LAi_SetCharacterUseBullet(sld, "bullet");
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.location = "Villemstad_houseS3_residence";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.money = 20000;
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
 	SetRandSPECIAL(sld);
    SetSelfSkill(sld, 80, 80, 80, 80, 80);
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	LocatorReloadEnterDisable("Villemstad_houseS3", "reload2", true);//������� ������� �� ����
	//������-���������
	sld = GetCharacter(NPC_GenerateCharacter("HWIC_officer", "off_hol_6", "man", "man", 25, HOLLAND, -1, false, "soldier"));
	FantomMakeCoolFighter(sld, 35, 90, 90, "blade_07", "pistol2", "grapeshot", 200);
	sld.greeting = "patrol";
	sld.Dialog.Filename = "Quest\HollandGambit\HWIC_Office.c";
	sld.dialog.currentnode = "HWIC_officer";
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld,"potion2", 3);
	LAi_SetImmortal(sld, true);
	sld.location = "Villemstad_houseS3";
	sld.location.group = "reload";
	sld.location.locator = "reload3";
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	pchar.quest.HWIC_officer.win_condition.l1 = "location";
	pchar.quest.HWIC_officer.win_condition.l1.location = "Villemstad_houseS3";
	pchar.quest.HWIC_officer.function = "HWICofficerTalk";
	
//----------------------------------------��� �������� � �������� �����-------------------------------------
	//��������
	sld = GetCharacter(NPC_GenerateCharacter("Abigile", "Aby", "woman", "woman_A2", 10, HOLLAND, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "�����";
	sld.greeting = "abigile_1";
	sld.rank = 5;
	SetSelfSkill(sld, 5, 5, 5, 5, 5);
	SetShipSkill(sld, 5, 5, 5, 5, 5, 5, 5, 5, 5);
	sld.Dialog.Filename = "Quest\HollandGambit\Abigile.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "Villemstad_houseSp2_bedroom";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.money = 0;
	LAi_SetOwnerType(sld);
 	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	//�������
	sld = GetCharacter(NPC_GenerateCharacter("Solomon", "Solomon", "man", "man_B", 10, HOLLAND, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�����";
	sld.greeting = "solomon_1";
	sld.rank = 10;
	sld.Dialog.Filename = "Quest\HollandGambit\Solomon.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "Villemstad_houseSp2";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.money = 1000;
	LAi_SetOwnerType(sld);
 	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	LocatorReloadEnterDisable("Villemstad_town", "houseSP2", true);//��� ������� �� ����
	
//-----------------------------------------������ ������� �������-------------------------------------------
	//���� ������
	sld = GetCharacter(NPC_GenerateCharacter("Merdok", "Merdok", "man", "man", 30, ENGLAND, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "������";
	sld.greeting = "merdok_1";
	sld.rank = 30;
	LAi_SetHP(sld, 350, 350);
	sld.Dialog.Filename = "Quest\HollandGambit\Merdok.c";
	sld.dialog.currentnode = "First time";
	sld.location = "SentJons_HouseF3";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.Merchant = true;
	sld.Merchant.type = "potion";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	SetRandSPECIAL(sld);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
    SetSelfSkill(sld, 80, 80, 80, 80, 80);
	LAi_SetOwnerType(sld);
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	LocatorReloadEnterDisable("SentJons_HouseF3", "reload2", true);//���������� ������� �� ����
	//����� ��������
	sld = GetCharacter(NPC_GenerateCharacter("Jino", "Gino", "man", "man", 20, ENGLAND, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "��������";
	sld.greeting = "Jino";
	sld.rank = 20;
	LAi_SetHP(sld, 150, 150);
	sld.Dialog.Filename = "Quest\HollandGambit\Jino.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "SentJons_HouseF3_Room";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.money = 5000;
	LAi_SetCitizenType(sld);
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	LocatorReloadEnterDisable("SentJons_HouseF3", "reload4", true);//������� ������� �� ����
	
//------------------------------------������ ����� ��������-------------------------------------------
	//����� ��������
	sld = GetCharacter(NPC_GenerateCharacter("Knippel", "Kneepel", "man", "man_B", 20, ENGLAND, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "��������";
	sld.greeting = "knippel_1";
	sld.CompanionDisable = true;
	sld.rank = 15;
	LAi_SetHP(sld, 300, 300);
	SetSelfSkill(sld, 35, 40, 55, 60, 50); 	//����.����.���.����.�����
	SetShipSkill(sld, 40, 20, 65, 65, 45, 20, 20, 10, 15); 	//���.����.����.����.�����.�����.�����.�����.�����.
	SetSPECIAL(sld, 10, 10, 10, 5, 5, 8, 5); 
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	//���.�����.���.�����.����.�����.�����
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunmanProfessional");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "ByWorker");
	sld.Dialog.Filename = "Quest\HollandGambit\Knippel.c";
	sld.dialog.currentnode = "First time";
	GiveItem2Character(sld, "newblade16");
	sld.equip.blade = "newblade16";
	GiveItem2Character(sld, "pistol_03");
	EquipCharacterbyItem(sld, "pistol_03");
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld,"potion2", 3);
	LAi_SetCharacterUseBullet(sld, "bullet");
	sld.location = "SentJons_houseH1";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.money = 1000;
	LAi_SetOwnerType(sld);
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
//----------------������ ��������� - ����������� � ����������� �� �������� ������ � ������ ������-----------
	//������ �������
	sld = GetCharacter(NPC_GenerateCharacter("Fleetwood", "Fleetwood", "man", "man", 20, ENGLAND, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.greeting = "fleetwood_1";
	sld.rank = 30;
	LAi_SetHP(sld, 300, 300);
	SetSelfSkill(sld, 80, 80, 80, 80, 80);
	SetShipSkill(sld, 50, 20, 70, 75, 80, 60, 70, 80, 50);
	SetRandSPECIAL(sld);
	sld.Dialog.Filename = "Quest\HollandGambit\Fleetwood.c";
	sld.dialog.currentnode = "First time";
	GiveItem2Character(sld, "newblade21");
	sld.equip.blade = "newblade21";
	GiveItem2Character(sld, "pistol_04");
	EquipCharacterbyItem(sld, "pistol_04");
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	LAi_SetCharacterUseBullet(sld, "grapeshot");
	sld.money = 20000;
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
sld.SuperShooter  = true;
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//���� ��� ����
	sld = GetCharacter(NPC_GenerateCharacter("JacobBerg", "VanBerg", "man", "man", 35, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "��� ����";
	sld.greeting = "JacobBerg";
	sld.Dialog.Filename = "Quest\HollandGambit\JacobBerg.c";
	sld.dialog.currentnode = "First time";
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	TakeNItems(sld, "potion2", 2);
	sld.money = 12000;
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	GiveItem2Character(sld, "BackPack3");
	SetRandSPECIAL(sld);
	
	//�������
	sld = GetCharacter(NPC_GenerateCharacter("Longway", "Longway", "man", "man", 20, HOLLAND, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "";
	sld.greeting = "Longway";
    sld.Dialog.Filename = "Quest\HollandGambit\Longway.c";
	sld.dialog.currentnode = "First time";
	sld.CompanionDisable = true;
	sld.rank = 20;
	sld.money = 5000;
	SetSelfSkill(sld, 45, 55, 45, 40, 50); 	//����.����.���.����.�����
	SetShipSkill(sld, 50, 20, 25, 25, 60, 20, 20, 50, 15); 	//���.����.����.����.�����.�����.�����.�����.�����.
	SetSPECIAL(sld, 7, 7, 7, 7, 10, 9, 7); 	//���.�����.���.�����.����.�����.�����
	LAi_SetHP(sld, 250, 250);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "ByWorker");
	sld.equip.blade = "blade50";
	GiveItem2Character(sld, "pistol_08");
	EquipCharacterbyItem(sld, "pistol_08");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 1);
	
	//������ ��������
	sld = GetCharacter(NPC_GenerateCharacter("Joakim", "Meriman_1", "man", "man_B", 25, HOLLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "��������";
	sld.greeting = "Joakim";
    sld.Dialog.Filename = "Quest\HollandGambit\Joakim.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25;
	GiveItem2Character(sld, "blade_09");
	sld.equip.blade = "blade_09";
	GiveItem2Character(sld, "pistol3");
	EquipCharacterbyItem(sld, "pistol3");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	LAi_SetImmortal(sld, true);
	
	//������ ������
	sld = GetCharacter(NPC_GenerateCharacter("Tonzag", "Tonzag", "man", "man", 30, ENGLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.greeting = "tonzag_2";
	sld.Dialog.Filename = "Quest\HollandGambit\Tonzag.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 15;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 3, 10, 4, 6, 10, 5); 	//���.�����.���.�����.����.�����.�����
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "ByWorker");
	GiveItem2Character(sld, "newblade14");
	sld.equip.blade = "newblade14";
	GiveItem2Character(sld, "pistol_03");
	EquipCharacterbyItem(sld, "pistol_03");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
}

void SharlieNpcInit()//������� ���� �������� ���������� �� ������� ����� ��������, ����� ������ �����
{
	string sBlade;
	//������ �� �����
	sld = GetCharacter(NPC_GenerateCharacter("Mishelle", "Migel_1", "man", "man", 60, FRANCE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�� �����";
	sld.greeting = "Mishelle_1";
    sld.Dialog.Filename = "Quest\Sharlie\Mishelle.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 60;
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
    SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100);
	LAi_SetHP(sld, 700, 700);
	GiveItem2Character(sld, "unarmed");
	sld.equip.blade = "unarmed";
	sld.equip.gun = "";
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	
	//����� �����
	sld = GetCharacter(NPC_GenerateCharacter("Benua", "abbat", "man", "man_B", 20, FRANCE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "�����";
	sld.greeting = "Gr_Church";
    sld.Dialog.Filename = "Quest\Sharlie\Benua.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25;
	GiveItem2Character(sld, "unarmed");
	sld.equip.blade = "unarmed";
	sld.equip.gun = "";
	LAi_SetImmortal(sld, true);
	LAi_SetStayType(sld);
	sld.location = "FortFrance_church";
	sld.location.group = "reload";
	sld.location.locator = "reload2_back";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	
	//����� ��������
	sld = GetCharacter(NPC_GenerateCharacter("Fadey", "moscovit", "man", "moscovit", 30, FRANCE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "";
	sld.greeting = "fadey";
	sld.location = "BasTer_houseSp1";
	sld.location.group = "sit";
	sld.location.locator = "sit3";
	sld.Dialog.Filename = "Quest\Sharlie\Fadey.c";
	sld.dialog.currentnode = "First time";
    SetSelfSkill(sld, 90, 90, 90, 70, 90);
    SetShipSkill(sld, 20, 90, 10, 10, 10, 20, 10, 10, 50);
	LAi_SetSitType(sld);
	LAi_SetHP(sld, 350.0, 350.0);
	LAi_SetImmortal(sld, true);
	GiveItem2Character(sld, "unarmed");
	sld.equip.blade = "unarmed";
	sld.equip.gun = "";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	
	// ����� �� �������
	sld = GetCharacter(NPC_GenerateCharacter("Diego", "diego_6", "man", "man_A", 1, SPAIN, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "�� �������";
	sld.greeting = "";
	sld.FaceId = 203;
    sld.Dialog.Filename = "Quest\Sharlie\Diego.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25+MOD_SKILL_ENEMY_RATE;
	LAi_SetHP(sld, 230+MOD_SKILL_ENEMY_RATE*35, 230+MOD_SKILL_ENEMY_RATE*35); 
	SetSelfSkill(sld, 90, 90, 90, 90, 90);
	SetShipSkill(sld, 90, 90, 90, 90, 90, 90, 90, 90, 90);
	SetSPECIAL(sld, 7, 5, 10, 5, 6, 10, 5);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	sBlade = GetBestGeneratedItem("blade_20");
	GiveItem2Character(sld, sBlade);
	sld.equip.blade = sBlade;
	sld.MultiFighter = 3.0; // ������������
	sld.MultiShooter = 3.0;
	sld.SuperShooter  = true;
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	
	// ������ �� ����������
	sld = GetCharacter(NPC_GenerateCharacter("Maldonado", "Alonso", "man", "man", 1, SPAIN, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�� ����������";
	sld.greeting = "alonso";
    sld.Dialog.Filename = "Quest\Sharlie\Maldonado.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 20+MOD_SKILL_ENEMY_RATE;
	LAi_SetHP(sld, 130+MOD_SKILL_ENEMY_RATE*35, 130+MOD_SKILL_ENEMY_RATE*35); 
	SetSelfSkill(sld, 90, 60, 60, 70, 90);
	SetShipSkill(sld, 70, 70, 70, 70, 70, 70, 70, 70, 70);
	SetSPECIAL(sld, 7, 5, 9, 7, 6, 8, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_26");
	sld.equip.blade = "blade_26";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	
	// ������ ��������
	sld = GetCharacter(NPC_GenerateCharacter("Willy", "willy_6", "man", "man_A", 1, ENGLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "��������";
	sld.greeting = "";
    sld.Dialog.Filename = "Quest\Sharlie\Willy.c";
	sld.dialog.currentnode = "First time";
	sld.FaceId = 202;
	sld.rank = 25+MOD_SKILL_ENEMY_RATE;
	LAi_SetHP(sld, 230+MOD_SKILL_ENEMY_RATE*35, 230+MOD_SKILL_ENEMY_RATE*35); 
	SetSelfSkill(sld, 100, 100, 100, 100, 90);
	SetShipSkill(sld, 90, 90, 90, 90, 90, 90, 90, 90, 90);
	SetSPECIAL(sld, 9, 3, 8, 6, 4, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	sBlade = GetBestGeneratedItem("blade_21");
	GiveItem2Character(sld, sBlade);
	sld.equip.blade = sBlade;
	sld.MultiFighter = 3.0; // ������������
	sld.MultiShooter = 3.0;
	sld.SuperShooter  = true;
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	// ��������� �������
	sld = GetCharacter(NPC_GenerateCharacter("Archy", "archy", "man", "man", 1, ENGLAND, -1, false, "quest"));
	sld.name = "���������";
	sld.lastname = "�������";
	sld.greeting = "Archy";
    sld.Dialog.Filename = "Quest\Sharlie\Archy.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 15+MOD_SKILL_ENEMY_RATE; 
	LAi_SetHP(sld, 150+MOD_SKILL_ENEMY_RATE*30, 150+MOD_SKILL_ENEMY_RATE*30); 
	SetSelfSkill(sld, 90, 60, 60, 70, 90);
	SetShipSkill(sld, 70, 70, 70, 70, 70, 70, 70, 70, 70);
	SetSPECIAL(sld, 7, 5, 9, 7, 6, 8, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_18");
	sld.equip.blade = "blade_18";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
}

void SagaNpcInit()//������� ���� �������� ���������� �� ������ ��������� ���� �����
{
	//�� �������, ��������
	sld = GetCharacter(NPC_GenerateCharacter("Svenson", "Svenson", "man", "man", 1, ENGLAND, -1, false, "quest"));
	sld.name = "��";
	sld.lastname = "�������";
	sld.greeting = "svenson_1";
    sld.Dialog.Filename = "Quest\Saga\Svenson.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 35;
	LAi_SetHP(sld, 600, 600); 
	SetSelfSkill(sld, 100, 100, 100, 100, 90);
	SetShipSkill(sld, 80, 85, 75, 80, 100, 65, 90, 60, 80);
	SetSPECIAL(sld, 8, 4, 10, 5, 5, 10, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_21");
	sld.equip.blade = "blade_21";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 10);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_SetImmortal(sld, true);
	sld.location = "Santacatalina_houseS1_residence";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//���� ��� �������� - ������ ������� ����
	sld = GetCharacter(NPC_GenerateCharacter("JS_girl", "Svenson_wife", "woman", "towngirl", 10, ENGLAND, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�������";
	sld.greeting = "joanna";
    sld.Dialog.Filename = "Quest\Saga\OtherNPC.c";
	sld.dialog.currentnode = "js_girl";
	LAi_SetImmortal(sld, true);
	sld.location = "Santacatalina_houseS1";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//��������� ����
	sld = GetCharacter(NPC_GenerateCharacter("Nathaniel", "Hawk_1", "man", "man_B", 25, PIRATE, -1, false, "quest"));
	SetFantomParamFromRank(sld, 25, true);
	sld.name = "���������";
	sld.lastname = "����";
	sld.greeting = "Nathaniel";
    sld.Dialog.Filename = "Quest\Saga\Nathaniel.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25;
	GiveItem2Character(sld, "blade_11");
	sld.equip.blade = "blade_11";
	GiveItem2Character(sld, "pistol1");
	EquipCharacterbyItem(sld, "pistol1");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.location = "FernandaDiffIndoor";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	LAi_SetGroundSitTypeNoGroup(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	
	//������� ���� ... �����, �����...
	sld = GetCharacter(NPC_GenerateCharacter("Danielle", "Danny", "woman", "danny", 1, ENGLAND, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "����";
	sld.greeting = "Danny";
    sld.Dialog.Filename = "Quest\Saga\Danielle.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 22;
	LAi_SetImmortal(sld, true); // ��������
	LAi_SetHP(sld, 280, 280); 
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 70, 85, 60, 55, 60);
	SetShipSkill(sld, 50, 38, 41, 39, 85, 33, 44, 62, 63);
	SetSPECIAL(sld, 6, 7, 9, 4, 5, 9, 7);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "Doctor1");
	GiveItem2Character(sld, "blade_10");
	sld.equip.blade = "blade_10";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	TakeNItems(sld, "potion3", 2);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");

	//������ �����
	sld = GetCharacter(NPC_GenerateCharacter("Doylie", "citiz_6", "man", "man", 35, ENGLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�����";
	//sld.greeting = "";
    sld.Dialog.Filename = "Quest\Saga\Doylie.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 35;
	GiveItem2Character(sld, "blade_17");
	sld.equip.blade = "blade_17";
	GiveItem2Character(sld, "pistol7");
	EquipCharacterbyItem(sld, "pistol7");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//������� �������
	sld = GetCharacter(NPC_GenerateCharacter("Beltrop", "Balthrop", "man", "balthrop", 35, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�������";
	sld.greeting = "Beltrop";
    sld.Dialog.Filename = "Quest\Saga\Beltrop.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 35;
	GiveItem2Character(sld, "blade_16");
	sld.equip.blade = "blade_16";
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	
	//������
	sld = GetCharacter(NPC_GenerateCharacter("Gladis", "Gladys", "woman", "woman", 10, ENGLAND, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "��� �����";
	sld.greeting = "gladis_1";
    sld.Dialog.Filename = "Quest\Saga\Gladis.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 10;
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//�����
	sld = GetCharacter(NPC_GenerateCharacter("Helena", "Eliza_0", "woman", "rumba", 1, ENGLAND, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "��� �����";
	sld.Dialog.Filename = "Quest\Saga\Helena.c";
	sld.dialog.currentnode = "First time";
	sld.greeting = "helena_1";
	sld.HeroModel = "Eliza_0,Eliza_1,Eliza_2,Eliza_3,Eliza_4,protocusto,Eliza_0,Eliza_0";
	sld.rank = 15;
	LAi_SetHP(sld, 220, 220); 
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.SuperShooter  = true;
	sld.MultiFighter = 3.0; // ������������
	sld.MultiShooter = 3.0;
	LAi_SetImmortal(sld, true); // ��������
	SetSelfSkill(sld, 70, 50, 5, 60, 20);
	SetShipSkill(sld, 40, 30, 55, 55, 95, 50, 20, 50, 30);
	SetSPECIAL(sld, 5, 6, 6, 6, 10, 10, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "ShipEscape");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//���� ���� - ���������
	sld = GetCharacter(NPC_GenerateCharacter("Dios", "Dios", "man", "man_B", 16, SPAIN, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 16, true);
	sld.name = "����";
	sld.lastname = "����";
	sld.greeting = "Dios";
    sld.Dialog.Filename = "Quest\Saga\Dios.c";
	sld.dialog.currentnode = "First time";
	LAi_SetImmortal(sld, true);
	GiveItem2Character(sld, "blade_08");
	sld.equip.blade = "blade_08";
	sld.location = "Santodomingo_houseSp2";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	LAi_SetOwnerType(sld);
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	
	//������� ������ - �������
	sld = GetCharacter(NPC_GenerateCharacter("Loxly", "advocat", "man", "man", 20, ENGLAND, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "�������";
	sld.lastname = "������";
	sld.greeting = "Loxly";
    sld.Dialog.Filename = "Quest\Saga\Loxly.c";
	sld.dialog.currentnode = "First time";
	LAi_SetImmortal(sld, true);
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.location = "PortRoyal_houseSp4";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
}

void LSC_NpcInit()// �������� ��� LSC
{
	//����� ������
	sld = GetCharacter(NPC_GenerateCharacter("Dodson", "Shark", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.greeting = "dodson_1";
    sld.Dialog.Filename = "Quest\LSC\Dodson.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 35;
	LAi_SetHP(sld, 480, 480); 
	SetSelfSkill(sld, 80, 100, 100, 90, 70);
	SetShipSkill(sld, 90, 80, 90, 85, 95, 60, 100, 50, 60);
	SetSPECIAL(sld, 9, 5, 10, 5, 5, 10, 4);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	GiveItem2Character(sld, "blade_31");
	sld.equip.blade = "blade_31";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.location = "SanAugustineResidence";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_SHARK");

	// ��� ������
	sld = GetCharacter(NPC_GenerateCharacter("Capper", "Chad", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "���";
	sld.lastname = "������";
	sld.greeting = "Capper";
    sld.Dialog.Filename = "Quest\LSC\Capper.c";
	sld.rank = 30;
	LAi_SetHP(sld, 150+MOD_SKILL_ENEMY_RATE*30, 150+MOD_SKILL_ENEMY_RATE*30); 
	SetSelfSkill(sld, 70, 80, 90, 90, 70);
	SetShipSkill(sld, 40, 40, 60, 60, 80, 40, 100, 20, 20);
	SetSPECIAL(sld, 9, 5, 9, 4, 4, 10, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	GiveItem2Character(sld, "newblade20");
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.equip.blade = "newblade20";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.location = "TartarusPrison";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	
	//������ �������
	sld = GetCharacter(NPC_GenerateCharacter("Dexter", "Dexter", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.greeting = "dexter_1";
    sld.Dialog.Filename = "Quest\LSC\Dexter.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 28;
	LAi_SetHP(sld, 380, 380); 
	SetSelfSkill(sld, 70, 70, 60, 70, 60);
	SetShipSkill(sld, 80, 90, 40, 45, 85, 75, 40, 30, 70);
	SetSPECIAL(sld, 7, 4, 8, 9, 9, 8, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	GiveItem2Character(sld, "blade_10");
	sld.equip.blade = "blade_10";
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", 2+makeint(MOD_SKILL_ENEMY_RATE/2));
	sld.location = "SanAugustineResidence";
	sld.location.group = "goto";
	sld.location.locator = "goto11";
	LAi_SetStayType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_SHARK");
	
	// ������ ����
	sld = GetCharacter(NPC_GenerateCharacter("Eddy", "Black", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "����";
	sld.greeting = "eddy_1";
    sld.Dialog.Filename = "Quest\LSC\Eddy_Rivados.c";
	sld.rank = 28;
	LAi_SetHP(sld, 350, 350); 
	SetSelfSkill(sld, 60, 75, 60, 70, 60);
	SetShipSkill(sld, 80, 40, 90, 85, 30, 30, 50, 20, 50);
	SetSPECIAL(sld, 9, 5, 9, 4, 4, 10, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	GiveItem2Character(sld, "blade_16");
	sld.equip.blade = "blade_16";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.location = "ProtectorFisher";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	LAi_SetStayType(sld);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// ������ ������� �������
	sld = GetCharacter(NPC_GenerateCharacter("Chimiset", "Chimiset2", "man", "man_A1", 1, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "";
	sld.greeting = "Chimiset";
    sld.Dialog.Filename = "Quest\LSC\Chimiset.c";
	sld.rank = 17;
	LAi_SetHP(sld, 160, 160); 
	SetSelfSkill(sld, 50, 55, 50, 40, 30);
	SetShipSkill(sld, 50, 10, 10, 10, 10, 10, 10, 90, 10);
	SetSPECIAL(sld, 9, 5, 9, 4, 4, 10, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Doctor3");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// ������
	sld = GetCharacter(NPC_GenerateCharacter("Zikomo", "Zikomo", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "";
	sld.greeting = "Zikomo";
    sld.Dialog.Filename = "Quest\LSC\Zikomo.c";
	sld.rank = 24;
	LAi_SetHP(sld, 280, 280); 
	SetSelfSkill(sld, 30, 55, 80, 50, 50);
	SetShipSkill(sld, 40, 20, 10, 15, 10, 10, 10, 10, 70);
	SetSPECIAL(sld, 7, 3, 10, 4, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	GiveItem2Character(sld, "topor_01");
	sld.equip.blade = "topor_01";
	GiveItem2Character(sld, "pistol1");
	EquipCharacterbyItem(sld, "pistol1");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.location = "ProtectorFisher";
	sld.location.group = "goto";
	sld.location.locator = "goto4";
	LAi_SetStayType(sld);
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// �������� ����� - ���������
	sld = GetCharacter(NPC_GenerateCharacter("Facio", "Facio", "man", "man_B", 1, PIRATE, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "�����";
	sld.greeting = "facio_1";
    sld.Dialog.Filename = "Quest\LSC\Facio.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "diplomat"; //��� ���
	sld.rank = 15;
	LAi_SetHP(sld, 120, 120); 
	SetSelfSkill(sld, 40, 25, 10, 30, 80);
	SetShipSkill(sld, 80, 90, 10, 10, 10, 10, 10, 10, 10);
	SetSPECIAL(sld, 5, 4, 6, 9, 9, 6, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_15");
	sld.equip.blade = "blade_15";
	GiveItem2Character(sld, "pistol5");
	EquipCharacterbyItem(sld, "pistol5");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	sld.location = "CarolineBank";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	
	// ������ ���� - ��������
	sld = GetCharacter(NPC_GenerateCharacter("Axel", "Axel", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "����";
	sld.greeting = "Axel";
    sld.Dialog.Filename = "Quest\LSC\Axel.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "trader"; //��� ���
	sld.rank = 19;
	LAi_SetHP(sld, 150, 150); 
	SetSelfSkill(sld, 55, 35, 10, 35, 90);
	SetShipSkill(sld, 80, 100, 10, 10, 10, 10, 10, 10, 10);
	SetSPECIAL(sld, 4, 4, 5, 10, 10, 7, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_15");
	sld.equip.blade = "blade_15";
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	sld.location = "EsmeraldaStoreBig";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.Merchant = true;
	sld.Merchant.type = "LSC_trader";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "LSC_NARVAL");
	
	// ����� ���������� - ������ ...����� �����...
	sld = GetCharacter(NPC_GenerateCharacter("Carpentero", "Carpentero", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "����������";
	sld.greeting = "Carpentero";
    sld.Dialog.Filename = "Quest\LSC\Carpentero.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "barmen"; //��� ���
	sld.rank = 18;
	LAi_SetHP(sld, 140, 140); 
	SetSelfSkill(sld, 25, 25, 20, 25, 60);
	SetShipSkill(sld, 80, 90, 15, 5, 5, 5, 10, 10, 30);
	SetSPECIAL(sld, 6, 6, 5, 8, 8, 7, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.location = "FleuronTavern";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	LAi_SetBarmanType(sld);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	
	// ���� ����� - ���������
	sld = GetCharacter(NPC_GenerateCharacter("Julian", "priest_1", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "�����";
	sld.greeting = "padre_1";
    sld.Dialog.Filename = "Quest\LSC\Julian_priest.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "priest"; //��� ���
	sld.rank = 12;
	LAi_SetHP(sld, 110, 110); 
	SetSelfSkill(sld, 15, 25, 10, 15, 50);
	SetShipSkill(sld, 80, 90, 15, 5, 5, 5, 10, 10, 30);
	SetSPECIAL(sld, 6, 6, 6, 6, 8, 8, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.location = "GloriaChurch";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.cityTape = "priest";
	LAi_SetPriestType(sld);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	
	// ���� ������ ... ����... ������ ������ �� ����� ����... ������ ������� � ��������� ��� �� �� ����� :)
	sld = GetCharacter(NPC_GenerateCharacter("Mary", "Mary", "woman", "mary", 1, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "������";
	sld.Dialog.Filename = "Quest\LSC\Mary.c";
	sld.dialog.currentnode = "First time";
	sld.greeting = ""; // ��������� �� ������ ������
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true; 
	sld.rank = 20;
	LAi_SetHP(sld, 250, 250); 
	SetSelfSkill(sld, 95, 50, 50, 90, 50);
	SetShipSkill(sld, 90, 25, 5, 5, 5, 5, 5, 15, 30);
	SetSPECIAL(sld, 6, 6, 8, 3, 9, 10, 4);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "Doctor1");
	GiveItem2Character(sld, "blade_17");
	sld.equip.blade = "blade_17";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	GiveItem2Character(sld, "cirass6");
	EquipCharacterbyItem(sld, "cirass6");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.location = "CeresSmithy";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.MultiFighter = 3.5; // ������������
	sld.MultiShooter = 3.5;
	sld.SuperShooter  = true;
	LAi_SetOwnerType(sld);
	
	// ������ ������� - �������
	sld = GetCharacter(NPC_GenerateCharacter("Mechanic", "Mechanic", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.greeting = "Mechanic";
    sld.Dialog.Filename = "Quest\LSC\Mechanic.c";
	sld.rank = 25;
	LAi_SetHP(sld, 180, 180); 
	SetSelfSkill(sld, 30, 25, 20, 30, 80);
	SetShipSkill(sld, 80, 10, 10, 10, 10, 10, 10, 10, 10);
	SetSPECIAL(sld, 5, 4, 6, 10, 10, 6, 8);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.location = "SanGabrielMechanic";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "LSC_NARVAL");
	
	// ����� ����� - ���������
	sld = GetCharacter(NPC_GenerateCharacter("Schmidt", "Schmidt", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "�����";
	sld.greeting = "Schmidt";
    sld.Dialog.Filename = "Quest\LSC\Schmidt.c";
	sld.rank = 28;
	LAi_SetHP(sld, 250, 250); 
	SetSelfSkill(sld, 10, 35, 70, 90, 70);
	SetShipSkill(sld, 50, 10, 10, 10, 10, 10, 10, 10, 10);
	SetSPECIAL(sld, 10, 4, 10, 3, 10, 8, 4);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	sld.location = "CeresSmithy";
	sld.location.group = "quest";
	sld.location.locator = "quest1";
	LAi_SetStayType(sld);
	LAi_group_MoveCharacter(sld, "LSC_NARVAL");
	
	//������� ������� - ����� ��������
	sld = GetCharacter(NPC_GenerateCharacter("Grinspy", "Donald", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�������";
	sld.greeting = "Grinspy";
    sld.Dialog.Filename = "Quest\LSC\Grinspy_Narval.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25;
	LAi_SetHP(sld, 280, 280); 
	SetSelfSkill(sld, 50, 60, 85, 75, 65);
	SetShipSkill(sld, 60, 70, 45, 55, 80, 75, 20, 20, 50);
	SetSPECIAL(sld, 8, 3, 8, 8, 5, 8, 5);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "LongRangeGrappling");
	GiveItem2Character(sld, "blade_31");
	sld.equip.blade = "blade_31";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.location = "EsmeraldaStoreBig";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_NARVAL");
	
	// ��� ����������� - ����� ������� ...���...���-���-���... :)
	sld = GetCharacter(NPC_GenerateCharacter("Ole", "Ole", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "���";
	sld.lastname = "�����������";
	sld.greeting = "Ole";
    sld.Dialog.Filename = "Quest\LSC\Ole.c";
	sld.rank = 10;
	LAi_SetHP(sld, 90, 90); 
	SetSelfSkill(sld, 10, 15, 10, 15, 90);
	SetShipSkill(sld, 10, 5, 5, 5, 5, 5, 10, 10, 90);
	SetSPECIAL(sld, 4, 10, 3, 3, 5, 8, 10);
	SetCharacterPerk(sld, "BasicDefense");
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	LAi_SetImmortal(sld, true); // �������� ��������
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	
	// ������ �������� ...��������... ��� �������� :)
	sld = GetCharacter(NPC_GenerateCharacter("Marchello", "Cyclop", "man", "man", 15, PIRATE, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "";
	sld.greeting = "Marchello";
    sld.Dialog.Filename = "Quest\LSC\OtherNPC.c";
	sld.dialog.currentnode = "First time";
	GiveItem2Character(sld, "blade_21");
	sld.equip.blade = "blade_21";
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	LAi_SetCharacterUseBullet(sld, "bullet");
    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 3);
}

void LSC_CreateStateCitizens() // �������� �������-�������� LSC, 20 ����
{
	// ------------------------ ������� �������� ------------------------	
	// ������� ��������� ����� ������ - ��������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Dugal", "citiz_3", "man", "man", 25, PIRATE, -1, true, "soldier"));
	SetFantomParamFromRank(sld, 25, true);
	sld.name = "�����";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto02_1"; 
	sld.location.baseShip = "02"; //������� ������� � ��� - ��������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 2; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Dugal.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "noble_male";
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ������� ��������� ������� ������� - �������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Lionel", "citiz_11", "man", "man", 20, PIRATE, -1, true, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "�������";
	sld.lastname = "�������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_3"; 
	sld.location.baseShip = "09"; //������� ������� � ��� - �����
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Lionel.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "citizen_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ������� ��������� ������ ������ - ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Gherad", "citiz_38", "man", "man", 18, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 18, true);
	sld.name = "������";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto05_1"; 
	sld.location.baseShip = "05"; //������� ������� � ��� - ������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Gherad.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "town_sailor";
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ������� ��������� ������ ������ - �������������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Rishard", "Shambone", "man", "man", 17, PIRATE, -1, false, "marginal"));
	SetFantomParamFromRank(sld, 17, true);
	sld.name = "������";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto08_1";
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true; 
	sld.location.baseShip = "08"; //������� ������� � ��� - ������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Rishard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "marginal";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ������� ��������� ������� ����� - �������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Alvaro", "mercen_23", "man", "man", 28, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 28, true);
	sld.name = "�������";
	sld.lastname = "�����";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_1"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "09"; //������� ������� � ��� - �����
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Alvaro.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "captain";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ������� ��������� ������ ������� - ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Victor", "mercen_20", "man", "man", 30, PIRATE, -1, true, "marginal"));
	SetFantomParamFromRank(sld, 30, true);
	sld.name = "������";
	sld.lastname = "�������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto11_1"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "11"; //������� ������� � ��� - ���-��������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Victor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "town_pirate";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// ������� ��������� ������ ������ - ����������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Adolf", "officer_16", "man", "man", 22, PIRATE, -1, true, "marginal"));
	SetFantomParamFromRank(sld, 22, true);
	sld.name = "������";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto05_3"; 
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	sld.location.baseShip = "05"; //������� ������� � ��� - ������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Adolf.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "town_pirate";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// ������� ��������� ������� - ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Curanai", "miskito_4", "man", "man", 18, PIRATE, -1, true, "native"));
	SetFantomParamFromRank(sld, 18, true);
	sld.name = "�������";
	sld.lastname = "";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14_1"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "14"; //������� ������� � ��� - �����-����������
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Curanai.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "indian_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	sld.Merchant.type = "LSC_indian";
	sld.money = 0;
	
	// ������� ��������� ������ ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Ramona", "women_16", "woman", "towngirl", 14, PIRATE, -1, true, "citizen"));
	SetFantomParamFromRank(sld, 14, true);
	sld.name = "������";
	sld.lastname = "������";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15_1"; 
	sld.location.baseShip = "15"; //������� ������� � ��� - ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Ramona.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ ������� �������� � ������� ------------------------
	// � ������� ������ ������ - ������� (��������� ������)
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Oelart", "mercen_3", "man", "man", 20, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "������";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit2"; 
	sld.location.baseShip = "02"; //������� ������� � ��� - ��������
	sld.location.baseLocator = "goto02_2";
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5; 
	sld.SuperShooter  = true;
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 6; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Oelart.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "town_sailor";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// � ������� ������� ����� - ���������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jasper", "prizon_7", "man", "man_B", 15, PIRATE, -1, true, "slave"));
	SetFantomParamFromRank(sld, 15, true);
	sld.name = "�������";
	sld.lastname = "�����";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit3"; 
	sld.location.baseShip = "09"; //������� ������� � ��� - �����
	sld.location.baseLocator = "goto09_2"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jasper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "marginal";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// � ������� ������� ������� - �������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Leonard", "LeoMaskett", "man", "man", 12, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 12, true);
	sld.name = "�������";
	sld.lastname = "�������";
	sld.city = "LostShipsCity";
	sld.location = "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit5"; 
	sld.location.baseShip = "05"; //������� ������� � ���
	sld.location.baseLocator = "goto05_2"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 7; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Leonard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "habitue";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// � ������� ������ ��������� - ���������� ������� ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Josef", "off_eng_2", "man", "man", 35, PIRATE, -1, true, "soldier"));
	SetFantomParamFromRank(sld, 35, true);
	sld.name = "������";
	sld.lastname = "���������";
	sld.city = "LostShipsCity";
	sld.location = "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit8"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "08"; //������� ������� � ��� - ������
	sld.location.baseLocator = "goto08_3";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Josef.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// � ������� ������� ��������� - ��������� ������� ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Lorenzo", "off_spa_4", "man", "man", 35, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 35, true);
	sld.name = "�������";
	sld.lastname = "���������";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit6"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "14"; //������� ������� � ��� - �����-����������
	sld.location.baseLocator = "goto14_2";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Lorenzo.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// � ������� ������ ������ - �������� �������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jacklin", "citiz_26", "man", "man", 20, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "������";
	sld.lastname = "������";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit7"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "11"; //������� ������� � ��� - ���-��������
	sld.location.baseLocator = "goto11_2";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jacklin.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ ������� �������� � ������ -----------------------
	// � ������ �������� �������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jillian", "women_15", "woman", "towngirl", 12, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 12, true);
	sld.name = "��������";
	sld.lastname = "�������";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "GloriaChurch";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "08"; //������� ������� � ��� - ������
	sld.location.baseLocator = "goto08_3"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jillian.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// � ������ ������� �����
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Tanneke", "women_13", "woman", "towngirl", 13, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 13, true);
	sld.name = "�������";
	sld.lastname = "�����";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "GloriaChurch";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 
	sld.location.baseShip = "15"; //������� ������� � ��� - ���
	sld.location.baseLocator = "goto15_3"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Tanneke.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ ���������� �������� ------------------------

	// ��������� ��������� ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Oreli", "women_18", "woman", "towngirl", 11, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 11, true);
	sld.name = "�����";
	sld.lastname = "������";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "PlutoStoreSmall";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "09"; //������� ������� � ��� - �����
	sld.location.baseLocator = "goto09_0"; 
	sld.location.baseLocation = "PlutoStoreSmall"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 6; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Oreli.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ��������� ��������� ������� ��������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Betancur", "Betancur", "man", "man", 20, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "�������";
	sld.lastname = "��������";
	sld.rank = 10;
	sld.city = "LostShipsCity";
	sld.location	= "PlutoStoreSmall";
	sld.location.group = "barmen";
	sld.location.locator = "bar1"; 
	sld.MultiFighter = 1.5; // ������������
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "09"; //������� ������� � ��� - �����
	sld.location.baseLocator = "goto09_4"; 
	sld.location.baseLocation = "PlutoStoreSmall"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Betancur.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "noble_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ��������� ��������� ������ ������
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Sesil", "women_17", "woman", "towngirl", 10, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "������";
	sld.lastname = "������";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "AvaShipInside3";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "15"; //������� ������� � ��� - ���
	sld.location.baseLocator = "goto15_0"; 
	sld.location.baseLocation = "AvaShipInside3"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Sesil.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_SesilGalard";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	//���������� ������� ������
	sld = GetCharacter(NPC_GenerateCharacter("Natalie_Waitress", "women_11", "woman", "towngirl", 10, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "�������";
	sld.lastname = "������";
	RemoveAllCharacterItems(sld, true);
	sld.location	= "FleuronTavern";
	sld.location.group = "waitress";
	sld.location.locator = "barmen";
	sld.dialog.filename   = "Quest\LSC\Natalie_Waitress.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //��� ���
	sld.greeting = "waitress";
	LAi_SetWaitressType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
}
/*
void MerchResidenceInit() //������
{
		ref sld;
		sld = GetCharacter(NPC_GenerateCharacter("MerchCotraband", "pirate_9", "man", "man", 1, PIRATE, -1, false, "quest")); // �� ,������,
		sld.name = "������������";
		sld.lastname = "��������";
		sld.dialog.filename = "Merch_Contr.c";
		LAi_SetImmortal(sld, true);
		sld.greeting = "Voice\Russian\pirat_quest_3.wav";
		sld.money = 50000;
		LAi_SetHP(sld, 200, 200); 
		//LAi_SetHP(sld, 200+MOD_SKILL_ENEMY_RATE*30, 200+MOD_SKILL_ENEMY_RATE*30);
		SetSPECIAL(sld, 9,8,7,5,7,9,10); //���.�����.���.�����.����.�����.�����
		SetSelfSkill(sld, 90,90,80,85,95); //����.����.���.����.�����
		SetShipSkill(sld, 26,10,55,51,20,22,33,21,34); //���.����.����.����.�����.�����.�����.�����.�����.
		LAi_SetHuberType(sld);
		
		SetCharacterPerk(sld, "Energaiser");
		SetCharacterPerk(sld, "AdvancedDefense");
		SetCharacterPerk(sld, "Gunman");
		SetCharacterPerk(sld, "GunProfessional");
		SetCharacterPerk(sld, "ShipSpeedUp");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "StormProfessional");
		SetCharacterPerk(sld, "WindCatcher");
		SetCharacterPerk(sld, "SailsMan");
		
		GiveItem2Character(sld, "blade_12");
		sld.equip.blade = "blade_12";
		TakeNItems(sld,"potion2", 1);
		GiveItem2Character(sld, "pistol7");
		EquipCharacterbyItem(sld, "pistol7");
			
	//	LAi_SetCharacterUseBullet(sld, "bullet");
		FreeSitLocator(pchar.questTemp.Shadowtrader.City + "CommonResidence_2", "sit_front1");
		ChangeCharacterAddressGroup(sld, pchar.questTemp.Shadowtrader.City + "CommonResidence_2", "sit", "sit_front1");
		sld.location = "CommonResidence_2";
		sld.location.group = "sit";
		sld.location.locator = "sit1";
		pchar.quest.merch ="true";
}
*/
string GetStrSmallRegister(string sBase)
{
	string sResult, Simbol;
	sResult = "";
	int qty = strlen(sBase);
	for (int i=0; i<qty; i++)
	{
		Simbol = GetSymbol(sBase, i);
		switch (Simbol)
		{
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			case "�": sResult += "�"; continue; break;
			
			case "A": sResult += "a"; continue; break;
			case "B": sResult += "b"; continue; break;
			case "C": sResult += "c"; continue; break;
			case "D": sResult += "d"; continue; break;
			case "E": sResult += "e"; continue; break;
			case "F": sResult += "f"; continue; break;
			case "G": sResult += "g"; continue; break;
			case "H": sResult += "h"; continue; break;
			case "I": sResult += "i"; continue; break;
			case "J": sResult += "j"; continue; break;
			case "K": sResult += "k"; continue; break;
			case "L": sResult += "l"; continue; break;
			case "M": sResult += "m"; continue; break;
			case "N": sResult += "n"; continue; break;
			case "O": sResult += "o"; continue; break;
			case "P": sResult += "p"; continue; break;
			case "Q": sResult += "q"; continue; break;
			case "R": sResult += "r"; continue; break;
			case "S": sResult += "s"; continue; break;
			case "T": sResult += "t"; continue; break;
			case "U": sResult += "u"; continue; break;
			case "V": sResult += "v"; continue; break;
			case "W": sResult += "w"; continue; break;
			case "X": sResult += "x"; continue; break;
			case "Y": sResult += "y"; continue; break;
			case "Z": sResult += "z"; continue; break;
		}
		sResult += Simbol;
	}
	return sResult;
}

// Warship 15.08.09 -->
// ������� ���� ������ � ������� �������
String ToUpper(String _text)
{
	String retString, symbol;
	retString = "";
	int length = strlen(_text);
	
	for(int i = 0; i < length; i++)
	{
		symbol = GetSymbol(_text, i);
		
		switch(symbol)
		{
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			case "�": retString += "�"; continue; break;
			
			case "a": retString += "A"; continue; break;
			case "b": retString += "B"; continue; break;
			case "c": retString += "C"; continue; break;
			case "d": retString += "D"; continue; break;
			case "e": retString += "E"; continue; break;
			case "f": retString += "F"; continue; break;
			case "g": retString += "G"; continue; break;
			case "h": retString += "H"; continue; break;
			case "i": retString += "I"; continue; break;
			case "j": retString += "J"; continue; break;
			case "k": retString += "K"; continue; break;
			case "l": retString += "L"; continue; break;
			case "m": retString += "M"; continue; break;
			case "n": retString += "N"; continue; break;
			case "o": retString += "O"; continue; break;
			case "p": retString += "P"; continue; break;
			case "q": retString += "Q"; continue; break;
			case "r": retString += "R"; continue; break;
			case "s": retString += "S"; continue; break;
			case "t": retString += "T"; continue; break;
			case "u": retString += "U"; continue; break;
			case "v": retString += "V"; continue; break;
			case "w": retString += "W"; continue; break;
			case "x": retString += "X"; continue; break;
			case "y": retString += "Y"; continue; break;
			case "z": retString += "Z"; continue; break;
		}
		
		retString += symbol;
	}
	
	return retString;
}

// ������ ������ � ������� �������
String UpperFirst(String _text)
{
	String firstSymbol = GetSymbol(_text, 0);
	firstSymbol = ToUpper(firstSymbol);
	
	return firstSymbol + strcut(_text, 1, strlen(_text) - 1);
}

// ������ ������ � ������ �������
String LowerFirst(String _text)
{
	String firstSymbol = GetSymbol(_text, 0);
	firstSymbol = GetStrSmallRegister(firstSymbol);
	
	return firstSymbol + strcut(_text, 1, strlen(_text) - 1);
}
// <--


//�������� ����������. ��������� ������ ''�������� ���''
void HouseEnc_TimerGoUot(string qName)
{
	if (CheckAttribute(pchar, "questTemp.HouseEncTimer"))
	{
		if (pchar.location == pchar.questTemp.HouseEncTimer && !actLoadFlag && !LAi_grp_alarmactive)
		{
			LAi_group_Attack(characterFromId(pchar.questTemp.HouseEncTimer.Id), Pchar);
		}
		DeleteAttribute(pchar, "questTemp.HouseEncTimer");
	}
}

//�������� ������ � ���������
void Delay_DeleteGroup(string GroupName)
{	
	pchar.quest.DeleteGroupOnExitLocation.GroupName = GroupName;
	DoQuestCheckDelay("DeleteGroupOnExitLocation", 2.0);
}

//�������� ���� ������� �� ������� � �����
void QuestCheckTakeBoxes(ref itemsRef) 
{	
//	ref locLoad = &locations[reload_location_index];
	ref locLoad = &LoadedLocation; // Warship fix - ������ � ������
    ref sld;
	int i, num;
	
	String title;
	
	//--> ���� ''� �������''
	bMainCharacterInBox = true;
	//<-- ���� ''� �������''
	//-------------------- ����� ------------>>>>>>>>>>>>>
	if (CheckAttribute(itemsRef, "Treasure"))
	{
		Log_Info("������, ��� ��� � ���� ����.");
		PlaySound("interface\notebook.wav");
		DeleteAttribute(itemsRef, "Treasure");
		//eddy. ��� ���������������� �������
		locations[FindLocation(pchar.location)].DisableEncounters = false; //��������� �������
		if(!CheckAttribute(itemsRef, "PiratesOnUninhabitedTreasure"))
		{
			// ��������
			switch (sti(pchar.GenQuest.Treasure.Vario))
			{
				case 0: 
					Treasure_SetCaribWarrior(); 
				break;
				
				case 1:
					Treasure_SetBandosWarrior();
				break;
				
				case 2:  
					pchar.quest.Treasure_evilcaptain.win_condition.l1 = "ExitFromLocation";
					pchar.quest.Treasure_evilcaptain.win_condition.l1.location = pchar.location;
					pchar.quest.Treasure_evilcaptain.function = "Treasure_SetCaptainWarrior";
				break;
				
				case 3:
					pchar.quest.Treasure_evilsoldier.win_condition.l1 = "ExitFromLocation";
					pchar.quest.Treasure_evilsoldier.win_condition.l1.location = pchar.location;
					pchar.quest.Treasure_evilsoldier.function = "Treasure_SetOfficerWarrior";
				break;
			}
		}
		else
		{
			title = "PiratesOnUninhabited" + PChar.GenQuest.PiratesOnUninhabited.StartShore;
			
			if(CheckAttribute(PChar, "GenQuest.PiratesOnUninhabited.UseMainPiratename"))
			{
				AddQuestRecordEx(title, "PiratesOnUninhabited", "10");
				AddQuestUserData(title, "sSex", GetSexPhrase("��","�"));
			}
			else
			{
				AddQuestRecordEx(title, "PiratesOnUninhabited", "9");
				AddQuestUserData(title, "sSex", GetSexPhrase("��","��"));
				AddQuestUserData(title, "shore", XI_ConvertString(PChar.location + "Dat"));
			}
			
			CloseQuestHeader(title);
			
			PChar.Quest.PiratesOnUninhabited_ShoreTreasureLose.over = "yes";
			
			DeleteAttribute(itemsRef, "PiratesOnUninhabitedTreasure");
			DeleteAttribute(PChar, "GenQuest.PiratesOnUninhabited");
		}
		
		if(CheckAttribute(itemsRef, "Hold_GenQuest_Treasure"))
		{
			if(sti(pchar.GenQuest.Hold_GenQuest.Treasure) == 0)
			{
				AddQuestRecord("HoldQuest", "18");
				AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.Name);
			}
			else
			{
				AddQuestRecord("HoldQuest", "17");
				AddQuestUserData("HoldQuest", "sCapName", pchar.GenQuest.Hold_GenQuest.CapName);
			}
			CloseQuestHeader("HoldQuest");
			DeleteAttribute(itemsRef, "Hold_GenQuest_Treasure");
			DeleteAttribute(pchar,"GenQuest.Hold_GenQuest");
		}
	}
	//<<<<<<<<<<---------- ����� --------------------------

	//-->> ��������� ������� �������, � ����� ��������� 
	if (GetCharacterIndex("HeadMan_1") != -1 && locLoad.id == "DestinyGiftPearlTown1_Townhall")
	{
		if (pchar.questTemp.Sharp.SeekSpy != "begin" && pchar.questTemp.Sharp.SeekSpy != "over")
		{	//���� ���� ����� �� ������ ����� ����� - ��������� ���
	pchar.questTemp.Sharp.SeekSpy = "over";
	CloseQuestHeader("SharpPearl_SeekSpy");
	}
	int iPearNation = sti(colonies[FindColony("SantaCatalina")].nation);
 SetNationRelation2MainCharacter(iPearNation, RELATION_ENEMY);
ChangeCharacterComplexReputation(pchar, "nobility", -30);
ChangeCharacterComplexReputation(pchar, "authority", 30);
ChangeCharacterNationReputation(pchar, iPearNation, -200);
LAi_group_Attack(characterFromId("HeadMan_1"), Pchar);
chrDisableReloadToLocation = true;
		pchar.quest.DestinyGiftPearlGen_HeadMan_1_death.win_condition.l1 = "NPC_Death";
		pchar.quest.DestinyGiftPearlGen_HeadMan_1_death.win_condition.l1.character = "HeadMan_1";
		pchar.quest.DestinyGiftPearlGen_HeadMan_1_death.win_condition = "OpenTheDoors";
		return;
	}
	//<<-- ��������� ������� �������, � ����� ��������� 

}

//===>>> ���������� ���������� �� ��������� ���������
void DestinyGiftPearlGen_SetSantaCatalina(string sQuest)
{
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition.l1 = "location";
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition.l1.location = "DestinyGiftPearl_Jungle_01";
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition = "DestinyGiftPearlGen_checkSantaCatalina";
}


//�������� ������ � ������� ������ ��� ��������. ������ �� ������� ����� + ��� ����, ����� ��������� ����.
void SetOpenDoorCommonLoc(string City, string locationId)
{
	aref arRld, arDis, arRld2, arDis2;
	string LocId;
	makearef(arRld, locations[FindLocation(City + "_town")].reload);
    int Qty2, n, i;
	int Qty = GetAttributesNum(arRld);
	for (i=0; i<Qty; i++)
    {
    	arDis = GetAttributeN(arRld, i);
		LocId = arDis.go;
    	if (LocId == locationId)
    	{
			arDis.disable = false;
			arDis.canEnter = true;
			return;
    	}
		if (arDis.label != "Sea")
		{	
			makearef(arRld2, Locations[FindLocation(LocId)].reload);
			Qty2 = GetAttributesNum(arRld2);
			for (n=0; n<Qty2; n++)
			{
    			arDis2 = GetAttributeN(arRld2, n);
				LocId = arDis2.go;
				if (LocId == locationId)
    			{
					arDis.disable = false;
					arDis.canEnter = true;
					return;					
				}
			}
		}
    }
}

//��� ������ �� ������� ����� ArtMoney
int CheckItemsCRC(ref rChar)
{
	aref arItems;
	string sName;
	ref rItm;
	int BaseCRC = 0;
	int Qty, ItmQty;
	
	makearef(arItems, rChar.items);
	Qty = GetAttributesNum(arItems);
	for (int a = 0; a < Qty; a++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, a));		
		rItm = ItemsFromID(sName);
		if(rItm.id != "Gold")
		{
			ItmQty = sti(arItems.(sName));
			if(!CheckAttribute(rChar,"BaseCRC")) 
			{
				rChar.BaseCRC = 1 + rand(5);		
			}	
			BaseCRC += (sti(rItm.index) + sti(rChar.BaseCRC)) * ItmQty);	
		}			
	}
	return BaseCRC;
}

int AddItemToCRC(ref rChar, string itemName, int n)
{
	int BaseCRC = 0;	
	ref rItm = ItemsFromID(itemName);
	if(rItm.id != "Gold")
	{
		if(!CheckAttribute(rChar,"BaseCRC")) 
		{
			rChar.BaseCRC = 1 + rand(5);		
		}
		BaseCRC = (sti(rItm.index) + sti(rChar.BaseCRC)) * n);
	}		
	return BaseCRC;
}

///Jason ---------���� ��������� �� � ������, ���������� � ���, ������ � ������ �� ������----------------------
void GoToPrison(string _sCity, int _iStraff, int _iDay)//��������� �� � ������, ������� ��� �������� � �������� � ������, �����������
{
	DoFunctionReloadToLocation(_sCity+"_prison", "goto", "goto9", "");
	//����� ������� ��������� �� ������� ��������� - ����� ��� ����� ���� ������ � ��� ����������
	WaitDate("", 0, 0, _iDay, 0, 10); //������ �����
	RecalculateJumpTable();

	ref location = &Locations[FindLocation(_sCity+"_prison")];
	
	aref arItems, boxItems;
	ref rItem, sld;
	string sName;
	makearef(arItems, PChar.items);
	makearef(boxItems, location.box1.items);
	int iItemsNum = GetAttributesNum(arItems);
	for(int i=0; i<iItemsNum; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		rItem = ItemsFromID(sName);
		if (rItem.ItemType != "QUESTITEMS")
		{
			boxItems.(sName) = PChar.items.(sName);
		}
	}
	DeleteAttribute(location, "box1.QuestClosed");
	location.box1.money = sti(PChar.money)-_iStraff;	
	location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
	RemoveAllCharacterItems(PChar, true);
	
	pchar.questTemp.Jaillocation = _sCity+"_prison";
	pchar.questTemp.JailTemp1 = _iStraff;
	pchar.questTemp.JailTemp2 = _iDay;
	
	sld = characterFromId(_sCity+"_trader");
	int iNation = sld.nation;
	sld = GetCharacter(NPC_GenerateCharacter("Jail_officer", "off_" + NationShortName(iNation) + "_" + (rand(1) + 1), "man", "man", 20, iNation, -1, true, "soldier"));
	SetFantomParamFromRank(sld, 20, true); 
	sld.name = "��������";
    sld.lastname = "�����������";
	sld.Dialog.Filename = "Quest\Jail_dialog.c"; 
	sld.dialog.currentnode = "Jail_officer_take"; 
	sld.greeting = "soldier_arest";
	LAi_SetActorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, _sCity+"_prison", "goto", "goto13");
	DoQuestFunctionDelay("Hide_Interface", 0.8);
	DoQuestFunctionDelay("Jail_officer", 10.0);
}

void Hide_Interface(string qName)//������ ���� ��������� � ������
{
	ChangeShowIntarface();
}

void Jail_officer(string qName)
{
    sld = characterFromID("Jail_officer");
    LAi_SetActorTypeNoGroup(sld);
    LAi_ActorGoToLocator(sld, "goto", "goto23", "", -1);
	DoQuestFunctionDelay("Jail_officer_talk", 3.0);
}

void Jail_officer_talk(string qName)
{
    sld = characterFromID("Jail_officer");
    LAi_SetActorTypeNoGroup(sld);
    LAi_ActorDialog(sld, pchar, "", 0, 0);
}

void InPrison(string qName)//�������
{
	SetLaunchFrameFormParam("������ ������ ���...", "", 0, 6);
	LaunchFrameForm();
	sld = characterFromId("Jail_officer");
    LAi_SetActorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto13");
	DoQuestFunctionDelay("Jail_officer", 10.0);
}

void GoFromPrison(string qName)//����� �� ������
{
	pchar.questTemp.jailCanMove = true; //��������� ������ ���� ������
	DoQuestReloadToLocation(pchar.location, "goto", "goto23", "");
	DeleteAttribute(pchar, "questTemp.JailTemp1");
	DeleteAttribute(pchar, "questTemp.JailTemp2");
	SetFunctionTimerCondition("LockPrisonBox", 0, 0, 1, false);
}

void LockPrisonBox(string qName)// ������� ������
{
	ref location = &Locations[FindLocation(pchar.questTemp.Jaillocation)];
	location.box1.QuestClosed = true;
	DeleteAttribute(pchar, "questTemp.Jaillocation");
}
//<-- ���� ��������� �� � ������

string DesIsland()//Jason ����� ��������� ���������� - ����� ����
{
	string sIsland;
	switch (rand(2))
	{
		case 0:
			sIsland = "Terks";
			break;
		case 1:
			sIsland = "Caiman";
			break;
		case 2:
			sIsland = "Dominica";
			break;
	}
	return sIsland;
}

string FindFriendCityToMC(bool bRand)//Jason ������� ��������� ������������� � �� ����� - ����� ����
{
	int n, m, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(pchar.nation), sti(colonies[n].nation));
		m = GetCharacterCurrentIsland(pchar);
		if (m < 0)
		{
			if (nation != RELATION_ENEMY && nation != PIRATE && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].nation != "none")
			{ // may-16
				storeArray[howStore] = n;
				howStore++;
			}
		}
		else
		{
			if (nation != RELATION_ENEMY && nation != PIRATE && colonies[n].id != "Panama" && colonies[n].id != "Minentown"  && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].nation != "none" && Islands[m].id != colonies[n].island)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	if (bRand) nation = storeArray[Rand(howStore-1)];
	else nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

string FindEnemyCityToMC(bool bRand)//Jason ������� ��������� ���������� � �� ����� - ����� ����
{
	int n, m, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(pchar.nation), sti(colonies[n].nation));
		m = GetCharacterCurrentIsland(pchar);
		if (m < 0)
		{
		if (nation == RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].nation != "none" && colonies[n].nation != PIRATE)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
		else
		{
		if (nation == RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].nation != "none" && Islands[m].id != colonies[n].island && colonies[n].nation != PIRATE)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	if (bRand) nation = storeArray[Rand(howStore-1)];
	else nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

void SelectLevelWarShipParameter()//Jason ������������� �� ������� ������� ����������
{
	int iShipRank;
	if(sti(pchar.rank) >= 30) iShipRank = 5;
	if(sti(pchar.rank) >= 24 && sti(pchar.rank) < 30) iShipRank = 4;	
	if(sti(pchar.rank) >= 19 && sti(pchar.rank) < 24) iShipRank = 3;	
	if(sti(pchar.rank) >= 14 && sti(pchar.rank) < 19) iShipRank = 2;
	if(sti(pchar.rank) >= 7 && sti(pchar.rank) < 14) iShipRank = 1;	
	if(sti(pchar.rank) < 7) iShipRank = 0;
	switch (iShipRank)
	{
		case 0:  
			iGlobalTemp = SHIP_CAREERLUGGER + rand(makeint(SHIP_SLOOP - SHIP_CAREERLUGGER));     					
			iTotalTemp = CANNON_TYPE_CANNON_LBS6;
			sTotalTemp = "blade_12";
		break; 	
		case 1:  
			iGlobalTemp = SHIP_BRIGANTINE + rand(makeint(SHIP_SCHOONER_W - SHIP_BRIGANTINE));					
			iTotalTemp = CANNON_TYPE_CANNON_LBS12;
			sTotalTemp = "blade_14";
		break; 		
		case 2:  
			iGlobalTemp = SHIP_GALEON_L + rand(makeint(SHIP_POLACRE - SHIP_GALEON_L));			
			iTotalTemp = CANNON_TYPE_CANNON_LBS16;
			sTotalTemp = "blade_13";
		break; 
		case 3: 
			iGlobalTemp = SHIP_GALEON_L + rand(makeint(SHIP_POLACRE - SHIP_GALEON_L));			
			iTotalTemp = CANNON_TYPE_CULVERINE_LBS18;
			sTotalTemp = "blade_13";
		break; 
		case 4: 
			iGlobalTemp = SHIP_HEAVYGALEON + rand(makeint(SHIP_FRIGATE_H - SHIP_HEAVYGALEON));         			
			iTotalTemp = CANNON_TYPE_CANNON_LBS24;
			sTotalTemp = "blade_15";
		break; 
		case 5: 
			iGlobalTemp = SHIP_HEAVYGALEON + rand(makeint(SHIP_LINESHIP - SHIP_HEAVYGALEON));  						
			iTotalTemp = CANNON_TYPE_CANNON_LBS32;
			sTotalTemp = "blade_19";
		break;  				
	}
}

void SelectLevelTradeShipParameter()//Jason ������������� �� �������� ������� ����������
{
	int iShipRank;
	if(sti(pchar.rank) >= 30) iShipRank = 5;
	if(sti(pchar.rank) >= 23 && sti(pchar.rank) < 30) iShipRank = 4;	
	if(sti(pchar.rank) >= 17 && sti(pchar.rank) < 23) iShipRank = 3;	
	if(sti(pchar.rank) >= 11 && sti(pchar.rank) < 17) iShipRank = 2;
	if(sti(pchar.rank) >= 5 && sti(pchar.rank) < 11) iShipRank = 1;	
	if(sti(pchar.rank) < 5) iShipRank = 0;
	switch (iShipRank)
	{
		case 0:  
			iGlobalTemp = SHIP_BARQUE;     					
			iTotalTemp = CANNON_TYPE_CANNON_LBS3;
			sTotalTemp = "blade_03";
		break; 	
		case 1:  
			iGlobalTemp = SHIP_BARQUE + rand(makeint(SHIP_BARKENTINE - SHIP_BARQUE));					
			iTotalTemp = CANNON_TYPE_CANNON_LBS6;
			sTotalTemp = "blade_05";
		break; 		
		case 2:  
			iGlobalTemp = SHIP_SHNYAVA + rand(makeint(SHIP_FLEUT - SHIP_SHNYAVA));			
			iTotalTemp = CANNON_TYPE_CANNON_LBS12;
			sTotalTemp = "blade_07";
		break; 
		case 3: 
			iGlobalTemp = SHIP_CARAVEL + rand(makeint(SHIP_CARACCA - SHIP_CARAVEL));		
			iTotalTemp = CANNON_TYPE_CANNON_LBS16;
			sTotalTemp = "blade_10";
		break; 
		case 4: 
			iGlobalTemp = SHIP_NAVIO + rand(makeint(SHIP_EASTINDIAMAN - SHIP_NAVIO));         			
			iTotalTemp = CANNON_TYPE_CANNON_LBS20;
			sTotalTemp = "blade_06";
		break; 
		case 5: 
			iGlobalTemp = SHIP_NAVIO + rand(makeint(SHIP_EASTINDIAMAN - SHIP_NAVIO));         			
			iTotalTemp = CANNON_TYPE_CANNON_LBS24;
			sTotalTemp = "blade_13";
		break;  				
	}
}

int SelectLevelCannonParameter(int iShipType)//Jason ������������� �� ������ - ������ ����
{
	int iCannon = CANNON_TYPE_CANNON_LBS12;
	if (rand(1) == 1) iCannon = CANNON_TYPE_CANNON_LBS16;
	
	if (iShipType < SHIP_BRIGANTINE) iCannon = CANNON_TYPE_CANNON_LBS6;
	
	if (iShipType > SHIP_SCHOONER_W && iShipType < SHIP_HEAVYGALEON)
	{
		if (rand(1) == 1) iCannon = CANNON_TYPE_CANNON_LBS20;
		else iCannon = CANNON_TYPE_CULVERINE_LBS18;
	}
	
	if (iShipType == SHIP_FRIGATE) iCannon = CANNON_TYPE_CANNON_LBS24;
	
	if (iShipType == SHIP_HEAVYGALEON || iShipType == SHIP_FRIGATE_H)
	{
		if (rand(1) == 1) iCannon = CANNON_TYPE_CANNON_LBS24;
		else iCannon = CANNON_TYPE_CANNON_LBS32;
	}
	
	if (iShipType >= SHIP_LINESHIP) iCannon = CANNON_TYPE_CANNON_LBS32;
	
	return iCannon;
}

//Jason --> ������ ������� ���������� ������ ������� � ������ ������� ���������� - ����� ��� ���� ���� ����� �� 4-6, � ������ ����� � �������� ������
//������� ������, ����� ��� ����� ����� ������� ����
void AddComplexSeaExpToScill(int s, int a, int c, int g, int d, int r, int t)
{
	AddCharacterExpToSkill(pchar, "Sailing", s);//���������
	AddCharacterExpToSkill(pchar, "Accuracy", a);//��������
	AddCharacterExpToSkill(pchar, "Cannons", c);//������
	AddCharacterExpToSkill(pchar, "Grappling", g);//�������
	AddCharacterExpToSkill(pchar, "Defence", d);//������
	AddCharacterExpToSkill(pchar, "Repair", r);//�������
	AddCharacterExpToSkill(pchar, "Commerce", t);//��������
}

//������ ������ ������, ����� ��� ����� ����� ���������� ����
void AddComplexSelfExpToScill(int l, int m, int h, int p)
{
	AddCharacterExpToSkill(pchar, "FencingL", l);//������ ������
	AddCharacterExpToSkill(pchar, "FencingS", m);//������� ������
	AddCharacterExpToSkill(pchar, "FencingH", h);//������� ������
	AddCharacterExpToSkill(pchar, "Pistol", p); //�������
}

int CheckShipTypeInSquadron(int iShipType) //Jason, ���� �� ����� ��� ������� � ������� � �������
{
	ref sld;
	int iTemp;
	int iShip = 0;
	for(int i = 0; i < COMPANION_MAX; i++)
	{
		iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			sld = GetCharacter(iTemp);
			if(sti(RealShips[sti(sld.ship.type)].basetype) == iShipType) iShip++;
		}
	}
	return iShip;
}

bool LSC_CheckShips() // ��������, ����� �� ������� � ������� LSC // Addon-2016 Jason
{
	if (CheckAttribute(pchar, "CSM.LSCFreeArrival")) return true; // --> CheatSurfMenu by Cheatsurfer
	ref sld;
	int iTemp;
	if(4-sti(RealShips[sti(pchar.Ship.Type)].Class) > 0 || sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_FLEUT) return false;
	for(int i = 0; i < COMPANION_MAX; i++)
	{
		iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			sld = GetCharacter(iTemp);
			if(4-sti(RealShips[sti(sld.Ship.Type)].Class) > 0 || sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_FLEUT) return false;
		}
	}
	return true;
}

void SetPassengerParameter(string _sIndex, bool bEnemy)//Jason, ����� ��������� ����������
{
	if (bEnemy)
	{
		pchar.GenQuest.(_sIndex).City = FindEnemyCityToMC(true);
		pchar.GenQuest.(_sIndex).Enemycity = true;
	}
	else pchar.GenQuest.(_sIndex).City = FindFriendCityToMC(true); //������� �����
	pchar.GenQuest.(_sIndex).StartCity = GetCurrentTown(); //��������� �����
	int DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.(_sIndex).City), GetArealByCityName(pchar.GenQuest.(_sIndex).StartCity));
	if (DaysQty > 16) DaysQty = 16;
	if (DaysQty < 1) DaysQty = 10; // ������� �� ���� �������� ����
	pchar.GenQuest.(_sIndex).DaysQty = makeint(sti(DaysQty)*(frand(1.5)+1.0)); //���
	float fShipIdx;
	switch(6-sti(RealShips[sti(Pchar.Ship.Type)].Class))
	{
		case 0: fShipIdx = 1.0; break;
		case 1: fShipIdx = 1.2;	break;
		case 2: fShipIdx = 1.5; break;
		case 3: fShipIdx = 2.2; break;
		case 4: fShipIdx = 3.0; break;
		case 5:	fShipIdx = 4.5; break;
	}
	pchar.GenQuest.(_sIndex).Money = (sti(DaysQty)*500*stf(fShipIdx)+rand(100))*sti(DaysQty)/sti(pchar.GenQuest.(_sIndex).DaysQty);
	if (bEnemy) pchar.GenQuest.(_sIndex).Money = makeint(sti(pchar.GenQuest.(_sIndex).Money)*1.2); //������
}

string UpdateLSCClanParol() // Jason: ���������� ������� ������
{
	string sParol;
	switch (rand(29))
	{
		case 0: sParol = "���������"; break;
		case 1: sParol = "������"; break;
		case 2: sParol = "��������"; break;
		case 3: sParol = "�������"; break;
		case 4: sParol = "����������"; break;
		case 5: sParol = "�������"; break;
		case 6: sParol = "������"; break;
		case 7: sParol = "��������"; break;
		case 8: sParol = "������"; break;
		case 9: sParol = "�����"; break;
		case 10: sParol = "����������"; break;
		case 11: sParol = "��������"; break;
		case 12: sParol = "����������"; break;
		case 13: sParol = "�������"; break;
		case 14: sParol = "������"; break;
		case 15: sParol = "������"; break;
		case 16: sParol = "�������"; break;
		case 17: sParol = "�������"; break;
		case 18: sParol = "����������"; break;
		case 19: sParol = "��������"; break;
		case 20: sParol = "������"; break;
		case 21: sParol = "��������"; break;
		case 22: sParol = "������"; break;
		case 23: sParol = "������"; break;
		case 24: sParol = "���������"; break;
		case 25: sParol = "�������"; break;
		case 26: sParol = "���������"; break;
		case 27: sParol = "�������"; break;
		case 28: sParol = "����������"; break;
		case 29: sParol = "��������"; break;
	}
	return sParol;
}

void UltimatePotionEffect() // ����� ��������
{
	RemoveItems(pchar, "Ultimate_potion", 1);
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	DeleteAttribute(pchar, "chr_ai.poison");
	Log_Info("������������ ����� ��������");
	Log_Info("�� ���������� ���� ��������� ����������!");
	PlaySound("Ambient\Tavern\glotok_001.wav");
}

// ugeen --> 
//--> ������ ������ ������
int GetStoragePriceExt(ref NPChar, ref chref)
{
/*  --> ������� ��� ����������� ����� ���� �� �����, �� ��������!!!! 
	float fLeadership = 1.5 - GetSummonSkillFromName(pchar, SKILL_LEADERSHIP)/120.0; // ��������� ���������
	float fCommerce = 1.5 - GetSummonSkillFromName(pchar, SKILL_COMMERCE)/120.0; // ��������� ��������
	
	int price = makeint(15000 * MOD_SKILL_ENEMY_RATE * fLeadership * fCommerce * 0.5);
*/
	int price = makeint( 10000 * (5 + MOD_SKILL_ENEMY_RATE) * (3 + GetNationRelation2MainCharacter(sti(NPChar.nation)))/360.0 );
	
	return price;
}
//<-- ������ ������ ������
// --> ���������� ������� ����� �� ������ �� ������� �� � ����������, ����� ��� ����������� ��� ������ �� ���� ���� ��������
void SetStorageGoodsToShip(ref pStorage)
{
	int iStoreQ;
	for (int i = 0; i< GOODS_QUANTITY; i++)
	{
		iStoreQ = GetStorageGoodsQuantity(pStorage, i); 
		if (iStoreQ == 0) continue;
		SetCharacterGoods(pchar, i, GetCargoGoods(pchar, i) + iStoreQ);// ��������
	}
}
// �������� ����������� � �� �������
void SetNull2ShipInStockMan(string _city)
{
	if (!bCSMDeleteShipsInStock) return; // --> CheatSurfMenu by Cheatsurfer
	int i;
	ref chref, sld;
	int iTest = FindColony(_city);
	if(iTest == -1) return;
	
	ref rColony = GetColonyByIndex(iTest);
	
	for (i=1; i<MAX_CHARACTERS; i++)
	{
		makeref(chref, Characters[i]);
		if (CheckAttribute(chref, "ShipInStockMan"))
    	{
            if(chref.ShipInStockMan == (rColony.id + "_PortMan"))
		    {
				sld = CharacterFromId(rColony.id + "_PortMan");  
				DeleteAttribute(chref, "ShipInStockMan");
				chref.lifeDay = 0;
				pchar.ShipInStock = sti(pchar.ShipInStock) - 1; 
				sld.Portman    = sti(sld.Portman) - 1; 
			}
		}	
	}	
}
// <-- ugeen

bool Saga_CheckMarlinShip() // �������� ������� ������ - ���������� �� � 2 ������
{
	if(sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_POLACRE || GetCompanionQuantity(pchar) > 1) return false;
	if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation.Marlin") && pchar.ship.name != "�ap���") return false;
	if (!CheckAttribute(pchar, "questTemp.Saga.BarbTemptation.Marlin") && pchar.ship.name != "������") return false;
	return true;
}

bool bPincers() // ����� �� �������� ������ ������
{
	ref chr = characterFromId("Carpentero");
	if (CheckAttribute(chr, "quest.crab")) return true;
	return false;
}

// ������������� ����������� �� �������, ������ ������ ���� 2015
void Tortuga_SetShipGuard()
{
	if (CheckAttribute(pchar, "questTemp.Sharlie.DelTerGuard")) return;
	if (pchar.location == "Tortuga" && bSeaActive) return;
	int iShipType;
	int iCannonType;
	int i;
	Group_FindOrCreateGroup("Tortuga_Guard");
	for (i=1; i<=3; i++)
	{       
		switch (i)
		{
			case 1: 
				iShipType = SHIP_LINESHIP;
				iCannonType = CANNON_TYPE_CANNON_LBS32;
			break;
			case 2: 
				iShipType = SHIP_FRIGATE_H;
				iCannonType = CANNON_TYPE_CANNON_LBS32;
			break;
			case 3: 
				iShipType = SHIP_SURPRISE;
				iCannonType = CANNON_TYPE_CANNON_LBS24;
			break;
		}
		sld = GetCharacter(NPC_GenerateCharacter("TortugaGuardCap_"+i, "citiz_"+(rand(9)+51), "man", "man", 45, FRANCE, -1, true, "soldier"));	
		FantomMakeCoolFighter(sld, 45, 110, 100, "blade_19", "pistol5", "bullet", 200);
		FantomMakeCoolSailor(sld, iShipType, "", iCannonType, 110, 110, 110);
		SelAllPerksToChar(sld, false);
		sld.Ship.Mode = "mercenary";
		sld.DontRansackCaptain = true;
		sld.AnalizeShips = true;
		sld.DontHitInStorm = true; // �� �������� � �����
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // ������ ��������
		sld.AlwaysSandbankManeuver = true;
		sld.MultiFighter = 1.5; // ������������
		sld.MultiShooter = 1.5;
		sld.SuperShooter  = true;
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		Group_AddCharacter("Tortuga_Guard", "TortugaGuardCap_"+i);
	}
	Group_SetGroupCommander("Tortuga_Guard", "TortugaGuardCap_1");
	Group_SetTaskNone("Tortuga_Guard");//��� ������
	Group_SetAddress("Tortuga_Guard", "Tortuga", "IslandShips1", "ship_1");
	Group_LockTask("Tortuga_Guard");
}

void Tortuga_DeleteShipGuard()
{
	if (pchar.location == "Tortuga" && bSeaActive) return;
	Group_DeleteGroup("Tortuga_Guard");
	for (int i=1; i<=3; i++)
	{  
		if (GetCharacterIndex("TortugaGuardCap_"+i) != -1)
		{
			sld = characterFromId("TortugaGuardCap_"+i);
			sld.lifeday = 0;
		}
	}
}

void Tortuga_ShipGuardAttack() // 2015
{
	int i;
	for (i=1; i<=3; i++)
	{       
		sld = characterFromId("TortugaGuardCap_"+i);
		sld.AlwaysEnemy = true;
		Ship_SetTaskAttack(SECONDARY_TASK, sti(sld.index), sti(pchar.index));
		SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	}
	RefreshBattleInterface();
	UpdateRelations();
	DoQuestFunctionDelay("Tortuga_BranderGo", 4.0);
}

void Tortuga_BranderGo(string qName) // 2015
{
	Group_FindOrCreateGroup("Tortuga_GuardAdd");
	int iShipType, iCannonType;
	for (int i=1; i<=4; i++)
	{       
		switch (i)
		{
			case 1: 
				iShipType = SHIP_LINESHIP;
				iCannonType = CANNON_TYPE_CANNON_LBS32;
			break;
			case 2: 
				iShipType = SHIP_FRIGATE_H;
				iCannonType = CANNON_TYPE_CANNON_LBS24;
			break;
			case 3: 
				iShipType = SHIP_SURPRISE;
				iCannonType = CANNON_TYPE_CANNON_LBS24;
			break;
			case 4: 
				iShipType = SHIP_CORVETTE;
				iCannonType = CANNON_TYPE_CULVERINE_LBS18;
			break;
		}
		sld = GetCharacter(NPC_GenerateCharacter("TortugaGuardCapAdd_"+i, "citiz_"+(rand(9)+51), "man", "man", 45, FRANCE, 1, true, "soldier"));	
		FantomMakeCoolFighter(sld, 45, 110, 100, "blade_19", "pistol5", "bullet", 200);
		FantomMakeCoolSailor(sld, iShipType, "", iCannonType, 110, 110, 110);
		SelAllPerksToChar(sld, false);
		sld.Ship.Mode = "mercenary";
		sld.DontRansackCaptain = true;
		sld.AnalizeShips = true;
		sld.DontHitInStorm = true; // �� �������� � �����
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // ������ ��������
		sld.AlwaysSandbankManeuver = true;
		sld.AlwaysEnemy = true;
		sld.MultiFighter = 1.5; // ������������
		sld.MultiShooter = 1.5;
		sld.SuperShooter  = true;
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		Group_AddCharacter("Tortuga_GuardAdd", "TortugaGuardCapAdd_"+i);
	}
	Group_SetGroupCommander("Tortuga_GuardAdd", "TortugaGuardCapAdd_1");
	Sea_LoginGroupCurrentSea("Tortuga_GuardAdd");
	Group_SetTaskAttack("Tortuga_GuardAdd", PLAYER_GROUP);
    Group_LockTask("Tortuga_GuardAdd");
}

void Map_NationQuestHunter(int Nation)//��������� ���������-�������
{
    ref  sld;
	int iRank = sti(PChar.rank)+MOD_SKILL_ENEMY_RATE+5;
	if (iRank > 42) iRank = 42;
    string sCapId = "FollowerQuest0";
    string sGroup = "Sea_" + sCapId + "1";
	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	int iNation = sti(Nation);
    for (int i = 1; i <= GetCompanionQuantity(pchar)+1; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_"+NationShortName(iNation)+"_"+(rand(1)+1), "man", "man", iRank, iNation, 45, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld);
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
		sld.WatchFort = true;
		sld.Coastal_Captain = true;
        sld.mapEnc.type = "war";
		sld.mapEnc.worldMapShip = "Galleon_red";
        sld.mapEnc.Name = "������������";
		sld.hunter = ""+iNation+"";
        Group_AddCharacter(sGroup, sCapId + i);
    }
    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
	Map_CreateCoolWarrior("", sCapId + "1", 45);
}

void FillShorechestBox(string loc, int n, int i) // Jason: ���������� ����������� �� ����� ��������
{

	pchar.GenQuestBox.(loc) = true;
	string boxx = "box"+n;
	string sgem1 = "jewelry"+(drand(3)+1);
	string sgem2 = "jewelry"+(drand(9)+14);
	string sring = "jewelry"+(drand(11)+40);
	string smin1 = "mineral"+(drand(12)+1);
	string smin2 = "mineral"+(drand(14)+12);
	string sind = "indian_"+(drand(10)+1);
	string saml = "amulet_"+(drand(10)+1);
	string sobr = "obereg_"+(drand(10)+1);
	string srec = "recipe_totem_0"+(drand(8)+1);
	string srecd = "recipe_totem_"+(drand(3)+10);
	switch (i)
	{
		// good
		case 0:
			if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).money = drand(7000);
	        }
			if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.gold_dublon = 30+drand(100);
	        }
		    if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sgem1) = 2+drand(10);
	        }
	        else
	        {
	            pchar.GenQuestBox.(loc).(boxx).items.(sgem2) = 5+drand(20);
	        }
	        if (drand(10) > 6)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry8 = drand(12);
	        }
	        if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sring) = 1+drand(9);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.potion3 = 5+drand(15);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.potion1 = 5+drand(25);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(smin1) = 1+drand(6);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(smin2) = 1+drand(7);
	        }
	        if (drand(30) == 5)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sind) = 1;
	        }
	        if (drand(30) == 15)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(saml) = 1;
	        }
			if (drand(30) == 25)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sobr) = 1;
	        }
	        if (drand(9) == 3)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.cirass6 = 1;
	        }
	    break;
	    // best
	    case 1:
			if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).money = drand(15000);
	        }
            if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.chest = 1+drand(3);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.icollection = 1;
	        }
	        if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sgem1) = 20+drand(40);
	        }
	        if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry53 = 15+drand(100);
	        }
	        if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry52 = 15+drand(100);
	        }
	        if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry8 = 5+drand(30);
	        }
			if (drand(3) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry9 = drand(2);
	        }
	        if (drand(4) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.cirass7 = 1;
	        }
			if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sring) = 10+drand(25);
	        }
			if (drand(5) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.rat_poison = 1;
			}
			if (drand(5) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.(srec) = 1;
			}
			if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.potion2 = 5+drand(15);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.potion4 = 5+drand(15);
	        }
	    break;
	    // bad
	    case 2:
			if (rand(1) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).money = drand(1000);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.slave_01 = drand(5);
	        }
	        else
	        {
                pchar.GenQuestBox.(loc).(boxx).items.blade_05 = drand(5);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.blade_07 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.slave_02 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sgem2) = 1+drand(2);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.mineral30 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.mineral31 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.mineral35 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.mineral14 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.mineral8 = 1;
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.potion5 = 1+drand(20);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry51 = +drand(10);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry49 = drand(5);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry48 = drand(11);
	        }
	        if (rand(2) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry9 = 1;
	        }
	        if (drand(9) == 1)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.cirass1 = 1;
	        }
			 if (drand(100) == 30)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sind) = 1;
	        }
			if (drand(100) == 60)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(saml) = 1;
	        }
			if (drand(100) == 90)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.(sobr) = 1;
	        }
	        if (drand(9) == 5)
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.cirass6 = 1;
	        }
	    break;
		// gold
		case 3:
	        if (drand(1) == 1 && GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 10+drand(50)+drand(50))
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry5 = 500+drand(500);
	        }
			else
			{
				pchar.GenQuestBox.(loc).(boxx).items.potionwine = 60+drand(40);
				if (drand(12) == 10)
				{
					pchar.GenQuestBox.(loc).(boxx).items.(srecd) = 1;
				}
				if (drand(10) == 6)
				{
					pchar.GenQuestBox.(loc).(boxx).items.(srec) = 1;
				}
			}
	    break;
		// silver
		case 4:
	        if (drand(1) == 0 && GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 10+drand(50)+drand(50))
	        {
            	pchar.GenQuestBox.(loc).(boxx).items.jewelry6 = 1000+drand(1000);
	        }
			else
			{
				pchar.GenQuestBox.(loc).(boxx).items.potionrum = 60+drand(40);
				if (drand(12) == 10)
				{
					pchar.GenQuestBox.(loc).(boxx).items.(srecd) = 1;
				}
				if (drand(10) == 6)
				{
					pchar.GenQuestBox.(loc).(boxx).items.(srec) = 1;
				}
			}
	    break;
		// warrior
		case 5:
			if (rand(1) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.GunPowder = 50+drand(50);
			}
			if (rand(1) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.bullet = 50+drand(50);
			}
			if (rand(1) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.grapeshot = 50+drand(50);
			}
			if (rand(2) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.cartridge = 25+drand(25);
			}
			if (rand(3) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.astrolab = 1;
			}
			if (rand(3) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.compass1 = 1;
			}
			if (rand(3) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.clock1 = 1;
			}
			if (drand(5) == 2)
			{
				pchar.GenQuestBox.(loc).(boxx).items.pistol3 = 1;
			}
			else
			{
				pchar.GenQuestBox.(loc).(boxx).items.pistol1 = 2;
			}
			if (drand(20) == 5)
			{
				pchar.GenQuestBox.(loc).(boxx).items.pistol6 = 1;
			}
			if (drand(10) == 1)
			{
				pchar.GenQuestBox.(loc).(boxx).items.(srec) = 1;
			}
	    break;
	}
}

bool CheckIndianGift() // Jason: ���� �� ������� ��� ��������
{
	for (int i=47; i<=50; i++)
    {
		if (CheckCharacterItem(pchar, "jewelry"+i)) return true;
	}
	if (CheckCharacterItem(pchar, "mineral6")) return true;
	
	return false;
}

bool CheckCaribGuns() // Jason: ���� �� ������� ��� ������� �������
{
	for (int i=1; i<=6; i++)
    {
		if (GetCharacterFreeItem(pchar, "pistol"+i) > 0) return true;
	}
	return false;
}

void MakeHellFireDamage() // Jason: ���� ����� �� ����
{
	LAi_ApplyCharacterDamage(pchar, 45+MOD_SKILL_ENEMY_RATE*3, "other");
	LAi_CheckKillCharacter(pchar);
	PlaySound("People Fight\Death_NPC_08.wav");
}

void MakeHellSplashDamage() // Jason: ���� ����� �� ����
{
	PlaySound("Sea Battles\bolshoy_vsplesk_001.wav");
	CreateLocationParticles("Splash", "item", "splash"+iGlobalTemp, 0.5, 0, 0, "");
	CreateLocationParticles("blood_big", "item", "splash"+iGlobalTemp, 2.0, 0, 0, "");
	LAi_ApplyCharacterDamage(pchar, 90+MOD_SKILL_ENEMY_RATE*6, "other");
	LAi_CheckKillCharacter(pchar);
	PlaySound("People Fight\Death_NPC_08.wav");
}

bool Tieyasal_CheckTablets() // Jason: ���� �� ��������
{
	for (int i=1; i<=6; i++)
    {
		if (CheckCharacterItem(pchar, "Tablet_"+i)) return true;
	}
	return false;
}

void ShowRipInscription(int i, string locId) // Jason: ������� �� ���������� - ��������
{
	if (LAi_grp_playeralarm > 0) return;
	
	if (locId == "Charles_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("������ ������, 1612-1637, ������������"); 
				Log_Info("�� ��������� ���� ����, ������ �����!");
			break;
			case 2: 
				Log_Info("���� �����, 1591-1640, ����������"); 
				Log_Info("�������, ����������� ������� �����..."); 
			break;
			case 3: 
				Log_Info("����� ������, 1555-1596, �������");
				Log_Info("� ������ ��� �������� ������ �������...");
			break;
			case 4: 
				Log_Info("����� �����, 1589-1618, �����������");
				Log_Info("�� � ���� �� ���� ��� ���������!"); 
			break;
			case 5: 
				Log_Info("����� ������, 1567-1624, ���������"); 
				Log_Info("���-���, ���� ������� ����������. ��������� �������..."); 
			break;
			case 6: 
				Log_Info("���� ������, 1544-1599, ���������"); 
				Log_Info("�����, �������, ���� � ������� ��������!"); 
			break;
			case 7: 
				Log_Info("������� �'���, 1611-1650, �������"); 
				Log_Info("�������, ��� ������ ������������� ��������..."); 
			break;
			case 8: 
				Log_Info("��� ������, 1621-1649, ��������"); 
				Log_Info("� ��� ������ ������ � ���� ��������? ������ ���������, ���� ��� ���..."); 
			break;
			case 9: 
				Log_Info("������ ������, 1577-1608, ������"); 
				Log_Info("��, ��� ���?"); 
			break;
		}
	}
	if (locId == "Havana_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("������� �����, 1587-1633, ����� �������"); 
				Log_Info("� ��� ������ ����� �������� �� ���������!");
			break;
			case 2: 
				Log_Info("������ �������, 1599-1640, �������"); 
				Log_Info("����, ���� ��� ��� ��� ������� �����!");
			break;
			case 3: 
				Log_Info("������� �������, 1581-1630, �����������"); 
				Log_Info("���� � ����� ������ ������! ��� ������! ��� ���...");
			break;
			case 4: 
				Log_Info("����� �������, 1602-1645, �����"); 
				Log_Info("���������, � ������� ������������. ������ - ��� ��!");
			break;
			case 5: 
				Log_Info("������ ����, 1610-1639, ��������"); 
				Log_Info("�� ����������, �������, ��� ��� �� ����� �������� �� ��������...");
			break;
			case 6: 
				Log_Info("������� �������, 1590-1633, �������"); 
				Log_Info("� ���� ��� ����. ��� ���������� ���������!");
			break;
			case 7: 
				Log_Info("������ �������, 1588-1624, �������"); 
				Log_Info("������ �� � ���� ����� ���������� ������� �� ���� ��������..."); 
			break;
			case 8: 
				Log_Info("������� �����, 1599-1646, ��������"); 
				Log_Info("�� ������, ������! �������� �������� ���� ����� ������ ��������!"); 
			break;
			case 9: 
				Log_Info("�������� ����, 1605-1648, ��������"); 
				Log_Info("��� ������ ������ � �������� �� ��������!"); 
			break;
		}
	}
	if (locId == "PortRoyal_graveyard")
	{
		switch (i)
		{
		case 1: 
				Log_Info("���� ����, 1608-1631, �����"); 
				Log_Info("��������� ������ ����� ������ �������. �������� � �� ���� ���...");
			break;
			case 2: 
				Log_Info("����� ������, 1602-1649, �������"); 
				Log_Info("����, �� ������� �������� ����� �� ��������?");
			break;
			case 3: 
				Log_Info("������ ������, 1615-1653, ������"); 
				Log_Info("������, ��� ��� ��������������, ����� �������!");
			break;
			case 4: 
				Log_Info("����� ����, 1605-1627, �����"); 
				Log_Info("�� ��� �� ������! � ���������� � ������ ������ ������!");
			break;
			case 5: 
				Log_Info("������ �����, 1598-1639, ������"); 
				Log_Info("����� �������, �� ����� ������... ������� �� ����...");
			break;
			case 6: 
				Log_Info("����� ������, 1611-1642, ���"); 
				Log_Info("���, � ��� ���� � ������ ���� �� ������������...");
			break;
			case 7: 
				Log_Info("������ �����, 1545-1587, �����"); 
				Log_Info("� ���� ����� � ������� ����� � ������ ������� ��������� �����!"); 
			break;
			case 8: 
				Log_Info("������ ������, 1567-1599, ��������"); 
				Log_Info("����, ���� ����� ������� ��� ������ ������, �������� ������..."); 
			break;
			case 9: 
				Log_Info("������� ������, 1571-1596, ����������"); 
				Log_Info("���-�� ��� ����� ����������� �����-�� �������..."); 
			break;
		}
	}

	if (locId == "FortFrance_Graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("������ ������, 1612-1637, ������������"); 
				Log_Info("�� ��������� ���� ����, ������ �����!");
			break;
			case 2: 
				Log_Info("���� �����, 1591-1640, ����������"); 
				Log_Info("�������, ����������� ������� �����..."); 
			break;
			case 3: 
				Log_Info("����� ������, 1555-1596, �������");
				Log_Info("� ������ ��� �������� ������ �������...");
			break;
			case 4: 
				Log_Info("����� �����, 1589-1618, �����������");
				Log_Info("�� � ���� �� ���� ��� ���������!"); 
			break;
			case 5: 
				Log_Info("����� ������, 1567-1624, ���������"); 
				Log_Info("���-���, ���� ������� ����������. ��������� �������..."); 
			break;
			case 6: 
				Log_Info("������� �������, 1590-1633, �������"); 
				Log_Info("� ���� ��� ����. ��� ���������� ���������!");
			break;
			case 7: 
				Log_Info("������ �������, 1588-1624, �������"); 
				Log_Info("������ �� � ���� ����� ���������� ������� �� ���� ��������..."); 
			break;
			case 8: 
				Log_Info("����� �� ���, 1636-1661, ��������"); 
				Log_Info("�����, �����!"); 
			break;
			case 9: 
				Log_Info("�������� ����, 1605-1648, ��������"); 
				Log_Info("��� ������ ������ � �������� �� ��������!"); 
			break;
		}
	}

	if (locId == "PortPax_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("������� ����, 1612-1637, ������"); 
				Log_Info("������ ������ ���� ��� ����������!");
			break;
			case 2: 
				Log_Info("������ �����, 1591-1640, �������"); 
				Log_Info("���, ��� ������� �����..."); 
			break;
			case 3: 
				Log_Info("������ ����, 1555-1596, �������");
				Log_Info("������� � �����...");
			break;
			case 4: 
				Log_Info("�������, 1589-1618, �����������");
				Log_Info("�� � ���� �� ���� ��� ���������!"); 
			break;
			case 5: 
				Log_Info("������� �����, 1567-1624, ���������"); 
				Log_Info("��� ��� ����� ��!"); 
			break;
			case 6: 
				Log_Info("��������� ����, 1544-1599, ���������"); 
				Log_Info("�����, �������, ���� � ������� ��������!"); 
			break;
			case 7: 
				Log_Info("������, 1611-1650, �������"); 
				Log_Info("��� ��� ����� ��������!"); 
			break;
			case 8: 
				Log_Info("����� �������, 1621-1649, �������"); 
				Log_Info("����� �������?"); 
			break;
			case 9: 
				Log_Info("���� ������, 1577-1608, �����"); 
				Log_Info("����� �� �����, ��� � ����� �����?"); 
			break;
		}
	}

	if (locId == "Maracaibo_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("������� �����, 1587-1633, ����� �������"); 
				Log_Info("� ��� ������ ����� �������� �� ���������!");
			break;
			case 2: 
				Log_Info("������ �������, 1599-1640, �������"); 
				Log_Info("����, ���� ��� ��� ��� ������� �����!");
			break;
			case 3: 
				Log_Info("������� �������, 1581-1630, �����������"); 
				Log_Info("���� � ����� ������ ������! ��� ������! ��� ���...");
			break;
			case 4: 
				Log_Info("����� �������, 1602-1645, �����"); 
				Log_Info("���������, � ������� ������������. ������ - ��� ��!");
			break;
			case 5: 
				Log_Info("������ ����, 1610-1639, ��������"); 
				Log_Info("�� ����������, �������, ��� ��� �� ����� �������� �� ��������...");
			break;
			case 6: 
				Log_Info("������� �������, 1590-1633, �������"); 
				Log_Info("� ���� ��� ����. ��� ���������� ���������!");
			break;
			case 7: 
				Log_Info("������ �������, 1588-1624, �������"); 
				Log_Info("������ �� � ���� ����� ���������� ������� �� ���� ��������..."); 
			break;
			case 8: 
				Log_Info("������� �����, 1599-1646, ��������"); 
				Log_Info("�� ������, ������! �������� �������� ���� ����� ������ ��������!"); 
			break;
			case 9: 
				Log_Info("�������� ����, 1605-1648, ��������"); 
				Log_Info("��� ������ ������ � �������� �� ��������!"); 
			break;
		}
	}

	if (locId == "Villemstad_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("���� �����, 1587-1631, ���"); 
				Log_Info("��������� - ��� ��������, � �������� ����� ����� ��, ��� ����!");
			break;
			case 2: 
				Log_Info("������ �������, 1601-1649, ������"); 
				Log_Info("� ������� ��� ��������, ��, ������! ������ ������� �� �������� ��� �������!");
			break;
			case 3: 
				Log_Info("���� ������, 1577-1622, ������"); 
				Log_Info("�� �����������, ���: � ���� ������ ����� ��� ���� ��� ���� ���� �������!");
			break;
			case 4: 
				Log_Info("����� �������, 1589-1635, ������"); 
				Log_Info("��� �� �� ����� �������, � ���� �� ���������� ���������� �������!");
			break;
			case 5: 
				Log_Info("������� ���, 1610-1644, ������"); 
				Log_Info("������, �� ���� �� ��������? ��� ������ �������, ��� �� ������� �����...");
			break;
			case 6: 
				Log_Info("����� �������, 1561-1615, ��������"); 
				Log_Info("����� ����� � � ���� ����...");
			break;
			case 7: 
				Log_Info("����� �����, 1588-1607, ���������"); 
				Log_Info("������, ���-�� ����� �����. � ���� �������� ������� ����? �����, �����..."); 
			break;
			case 8: 
				Log_Info("������ ��� ���, 1572-1611, ������"); 
				Log_Info("������� �� �������� ������ ������! ��� - �� ��������! �������!"); 
			break;
			case 9: 
				Log_Info("���� �� ����, 1611-1651, ��������������"); 
				Log_Info("������� �� �������� �� �����. ������ ����� ����� �������. � ���� ���� ���..."); 
			break;
		}
	}
}

//Jason 240912 ------------------------------- ������������ ����� ----------------------------------------------
string SelectAdmiralMaps() // ����� ��������� �� �������������
{	
	string sMap = "";
	ref sld = characterFromId("Dios");
	string map[24];
	map[0] = "A_map_bermudas";
	map[1] = "A_map_jam";
	map[2] = "A_map_cayman";
	map[3] = "A_map_barbados";
	map[4] = "A_map_tortuga";
	map[5] = "A_map_curacao";
	map[6] = "A_map_martiniqua";
	map[7] = "A_map_dominica";
	map[8] = "A_map_trinidad";
	map[9] = "A_map_puerto";
	map[10] = "A_map_cuba";
	map[11] = "A_map_hisp";
	map[12] = "A_map_nevis";
	map[13] = "A_map_beliz";
	map[14] = "A_map_guad";
	map[15] = "A_map_santa";
	map[16] = "A_map_antigua";
	map[17] = "A_map_terks";
	map[18] = "A_map_sm";
	map[19] = "A_map_maine_1";
	map[20] = "A_map_maine_2";
	map[21] = "A_map_panama";
	map[22] = "A_map_cumana";
	map[23] = "A_map_perl";
	
	int i = 0;
	while(i < 23)
	{
		int n = rand(23);
		string sTemp = map[n];
		if (sTemp != "")
		{
			if (!CheckAttribute(sld, "quest.map."+sTemp))
			{
				sld.quest.map.(sTemp) = true;
				sMap = sTemp;
				i = 24; // ��������� �����
			}
			sTemp = "";
			i++; // ���������� �����
		}
	}
	return sMap;
}

void GiveAdmiralMapToCharacter(ref chr, int abl) // ���� ��������� � ��������
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	if (drand(abl) == 0)
	{
		string amap = SelectAdmiralMaps();
		if (amap != "") GiveItem2Character(chr, amap);
	}
}

void TargetAdmiralMapToCharacter(ref chr, string amap) // ���� ����������, ���� ����� ��� ���
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	ref sld = characterFromId("Dios");
	if (!CheckAttribute(sld, "quest.map."+amap))
	{
		GiveItem2Character(chr, amap);
		sld.quest.map.(amap) = true;
	}
}

int CountAdmiralMapFromCharacter() // ���������
{
	aref arItems;
	int amap = 0;
	string sName;
	makearef(arItems, pchar.items);
	int n = GetAttributesNum(arItems);
	for(int i=0; i<n; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		if (findsubstr(sName, "A_map_", 0) != -1) amap++;
	}
	return amap;
}

string IdentifyAdmiralMapLast() // ���������������� ��������� � ������
{
	aref arItems;
	string sName;
	string sMap = "";
	makearef(arItems, pchar.items);
	int n = GetAttributesNum(arItems);
	for(int i=0; i<n; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		if (findsubstr(sName, "A_map_", 0) != -1) sMap = sName;
	}
	return sMap;
}
// <-- ������������ �����

// --> ���������� ������ �����
int CheckNCountPersian() // patch-7
{
	int blade = 0;
	
	if (GetCharacterFreeGenerableItem(pchar, "blade_22") > 0) blade++;
	if (GetCharacterFreeGenerableItem(pchar, "blade_23") > 0) blade++;
	if (GetCharacterFreeGenerableItem(pchar, "blade_24") > 0) blade++;
	
	return blade;
}

string CheckNIdentifyPersian()
{
	ref rItem;
	aref arItems;
	string sName;
	string sBlade = "";
	makearef(arItems, pchar.items);
	int n = GetAttributesNum(arItems);
	for(int i=0; i<n; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		rItem = ItemsFromID(sName);
		if (CheckAttribute(rItem, "target") && rItem.target == TGT_PERSIAN) sBlade = sName;
	}
	return sBlade;
}
// <-- ���������� ������ �����

void CaveEnc_FillSkeleton(ref chr, int i) // ��� ��� �������� � �������
{
	switch (i)
	{
		case 0:
			if (drand(7) == 0) TakeNItems(chr, "gold_dublon", drand(50));// Addon-2016 Jason
			if (drand(7) == 1) TakeNItems(chr, "chest", drand(1));
			if (drand(7) == 2) TakeNItems(chr, "purse"+(drand(2)+1), 1);
			if (drand(7) > 2) TakeNItems(chr, "mineral"+(drand(12)+1), drand(5));
		break;
	
		case 1:
			if (drand(6) == 0) TakeNItems(chr, "indian_"+(drand(10)+1), 1);
			if (drand(6) == 1) TakeNItems(chr, "blade_0"+(drand(2)+7), 1);
			if (drand(6) == 2) TakeNItems(chr, "pistol1", 1);
			if (drand(6) > 2) TakeNItems(chr, "mineral"+(drand(13)+13), drand(2));
		break;
		
		case 2:
			if (drand(5) == 0) TakeNItems(chr, "amulet_"+(drand(10)+1), 1);
			if (drand(5) == 1) TakeNItems(chr, "jewelry"+(drand(5)+1), drand(20));
			if (drand(5) > 1) TakeNItems(chr, "mineral"+(drand(25)+1), drand(3));
		break;
		
		case 3:
			if (drand(8) == 0) TakeNItems(chr, "obereg_"+(drand(10)+1), 1);
			if (drand(8) == 1) TakeNItems(chr, "jewelry8", drand(10));
			if (drand(8) == 2) TakeNItems(chr, "jewelry7", drand(2));
			if (drand(8) == 3) TakeNItems(chr, "jewelry11", drand(5));
			if (drand(8) == 4) TakeNItems(chr, "jewelry"+(drand(10)+41), drand(6));
			if (drand(8) == 5) TakeNItems(chr, "jewelry"+(drand(11)+12), drand(6));
			if (drand(8) > 5) TakeNItems(chr, "mineral"+(drand(20)+1), drand(4));
		break;
	}
}
// ����� � ����������� �������� �������� �����
bool LineShips_FindCompanionShips(int Type)
{
	if (CheckAttribute(pchar, "CSM.NoCheckAndIdentifyShips")) return false; // --> CheatSurfMenu by Cheatsurfer
	for(int i=1; i<COMPANION_MAX; i++)
	{
		int iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			ref sld = GetCharacter(iTemp);
			if(sti(RealShips[sti(sld.ship.type)].basetype) == Type) return true;
		}
	}
	return false;
}

bool LineShips_CheckAndIdentify(int Nation)
{
	if (CheckAttribute(pchar, "CSM.NoCheckAndIdentifyShips")) return false; // --> CheatSurfMenu by Cheatsurfer
	switch (Nation)
	{
		case ENGLAND:
			if (sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LSHIP_ENG && LineShips_FindCompanionShips(SHIP_LSHIP_ENG) && Trafalgar_FindCompanionShip()) return false; // Jason, ���
			if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LSHIP_ENG || LineShips_FindCompanionShips(SHIP_LSHIP_ENG)) return true;
		break;
		
		case FRANCE:
			if (sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LSHIP_FRA && LineShips_FindCompanionShips(SHIP_LSHIP_FRA) && Ecliaton_FindCompanionShip()) return false; // Jason, ���
			if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LSHIP_FRA || LineShips_FindCompanionShips(SHIP_LSHIP_FRA)) return true;
		break;
		
		case SPAIN:
			if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LSHIP_SPA || LineShips_FindCompanionShips(SHIP_LSHIP_SPA)) return true;
		break;
		
		case HOLLAND:
			if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LSHIP_HOL || LineShips_FindCompanionShips(SHIP_LSHIP_HOL)) return true;
		break;
	}
	return false;
}

bool Ecliaton_FindCompanionShip() // Jason, ���
{
	for(int i=1; i<COMPANION_MAX; i++)
	{
		int iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			ref sld = GetCharacter(iTemp);
			if(sld.ship.name == "�������" && CheckAttribute(pchar, "questTemp.Patria.Ecliaton")) return true;
		}
	}
	return false;
}

bool Trafalgar_FindCompanionShip() // Jason, ���
{
	for(int i=1; i<COMPANION_MAX; i++)
	{
		int iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			ref sld = GetCharacter(iTemp);
			if(sld.ship.name == "����������" && CheckAttribute(pchar, "questTemp.Patria.Trafalgar")) return true;
		}
	}
	return false;
}

bool Companion_CheckShipType(int iShipType) // ����� ������ ����������� ���� ������� � ���������� � ����������� ������� ���������� ��� ����������� �������������
{
	int cn;
	ref sld;
	for (int i=1; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(pchar, i);
		if(cn != -1)
		{
			sld = &characters[cn];
			if (RealShips[sti(sld.Ship.Type)].basetype == iShipType)
			{
				pchar.GenQuest.CompanionId = sld.id;
				return true;
			}
		}
	}
	return false;
}

bool CheckTotalDepositsSum(ref _chref, int Sum)
{
	aref 		quests;
	aref 		quest;
	int  		nQuestsNum;
	int  		n;
	string 		sQuestName;
	int			TotalSum = 0;
		
	if (CheckAttribute(_chref, "Quest.Deposits")) 
    {
    	makearef(quests,Characters[GetMainCharacterIndex()].Quest.Deposits);
    	nQuestsNum = GetAttributesNum(quests);

    	for(n = 0; n < nQuestsNum; n++)
    	{
    		quest = GetAttributeN(quests,n);
    		sQuestName = GetAttributeName(quest);
						
    		if (CheckAttribute(_chref, "Quest.Deposits."+sQuestName+".Sum"))
    		{
				if(HasSubStr(sQuestName, "_type1"))
				{
					TotalSum += sti(_chref.Quest.Deposits.(sQuestName).Sum);
				}
							
			}			
        }
    }
	else return false;
	
	if(TotalSum >= Sum) return true;
	
	return false;
}

bool Caleuche_CheckAmulet() // �������, �������
{
	int aml = 0;
	if (CheckCharacterItem(pchar, "kaleuche_amulet2")) aml++;
	if (CheckCharacterItem(pchar, "kaleuche_amulet3")) aml++;
	
	if (aml > 0) return true;
	
	return false;
}

void Capture_VillemstadCapture() // 280313
{
	ref sld;
	sld = GetCharacter(NPC_GenerateCharacter("Villemstad_mayorr", "off_hol_6", "man", "man", 40, HOLLAND, 2, true, "officer"));
	SetFantomParamFromRank(sld, 40, true);
	sld.dialog.FileName = "Common_Mayor.c";
	sld.dialog.currentnode = "CAPTURE_Main";
	sld.city = "Villemstad";
	sld.quest.type = "hovernor";
	//sld.greeting = "";
	LAi_SetStayType(sld);
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, true);
	ChangeCharacterAddressGroup(sld, "Villemstad_townhall", "goto", "governor1");
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
}

string SelectRandomArtefact(int kind) // dlc
{
	string prefix, suffix, amulet;
	suffix = "_"+(drand(10)+1);
	switch (kind)
	{
		case 1: prefix = "indian"; break;
		case 2: prefix = "amulet"; break;
		case 3: prefix = "obereg"; break;
	}
	amulet = prefix+suffix;
	return amulet;
}

// Addon 2016-1 Jason ��������� �������
bool Mtraxx_MeridaCheckCarpenter() // �������� ������� �������� � ��� ������
{
	if (GetSummonSkillFromName(pchar, SKILL_REPAIR) >= 30 && sti(pchar.TmpPerks.BasicBattleState)) return true;
	if (sti(pchar.Fellows.Passengers.carpenter) > 0)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (GetSummonSkillFromName(sld, SKILL_REPAIR) >= 30 && sti(sld.TmpPerks.BasicBattleState)) return true;
	}
	return false;
}

string Mtraxx_RetributionSelectRanditem() // ����� ���������
{
	string sItem;
	int iChance = rand(9);
	
	switch (iChance)
	{
		case 0: sItem = "potion1"; break;
		case 1: sItem = "potion1"; break;
		case 2: sItem = "potion2"; break;
		case 3: sItem = "potion3"; break;
		case 4: sItem = "potion3"; break;
		case 5: sItem = "potion4"; break;
		case 6: sItem = "potionrum"; break;
		case 7: sItem = "potionrum"; break;
		case 8: sItem = "potionwine"; break;
		case 9: 
			if (rand(1) == 0) sItem = "potion2"; 
			else sItem = "berserker_potion"; 
		break;
	}
	return sItem;
}

void MakeIndianPoisonAttack(ref chref, ref _attack) // �� �������� �����
{
	// ����������
	if (CheckAttribute(chref, "chr_ai.immortal")) return;
	if (CheckAttribute(chref, "monster") || chref.chr_ai.group == LAI_GROUP_MONSTERS || chref.sex == "skeleton") return; // ���� 17/1
	if (CheckAttribute(chref, "PoisonResistent"))
	{
		log_info("�� �� ������������!");
		return;
	}
	if (LAi_GetCharacterHP(chref) < 15) 
	{
		if (CheckAttribute(chref, "chr_ai.immortal")) return;
		bool isSetBalde = (CheckAttribute(chref, "equip.blade") == true);
		LAi_SetImmortal(chref, true);
		//log_info("�������� � ID = "+chref.id+" � �������� "+chref.index+" � ������ "+GetFullName(chref)+" ������ 15 ��");
		DeleteAttribute(chref, "quest.indianpoisoned");
		LAi_SetImmortal(chref, false);
		LAi_KillCharacter(chref);
	LAi_SetResultOfDeath(_attack, chref, isSetBalde, false);
		return;
	}
	sGlobalTemp = _attack.id; // ��������� ���� � ��� ��
	chref.quest.indianpoisoned = true;
	//log_info("�������� � ID = "+chref.id+" � �������� "+chref.index+" � ������ "+GetFullName(chref)+" �������� ���� �����");
	if (!CheckAttribute(chref, "quest.indianpoisoned.info"))
	{
		log_info(""+GetFullName(chref)+" �������� ���� �����");
		chref.quest.indianpoisoned.info = true;
	}
	LAi_ApplyCharacterDamage(chref, 15, "other");
	DoQuestFunctionDelay("MakeIndianPoisonAttackCycle", 0.5);
}

void MakeIndianPoisonAttackCycle(string qName) // � ������� ����
{
	DoQuestFunctionDelay("MakeTainoPoisonAttack", 0.5);
}

void MakeTainoPoisonAttack(string qName) // � ������� ����
{
	ref chref, _attack;
	_attack = characterFromId(sGlobalTemp);
	for(int i=0; i<MAX_LOCATIONS; i++)
	{	
		chref = &characters[i];
		if (CheckAttribute(chref, "quest.indianpoisoned")) MakeIndianPoisonAttack(chref, _attack);
	}
}


// ������������� ����������� �� ���������, ������ ������ ���� 2015
void Guadeloupe_SetShipLee()
{
	if (CheckAttribute(pchar, "questTemp.GothicLee.DelShipLee")) return;
	if (pchar.location == "Guadeloupe" && bSeaActive) return;
	int iShipType;
	int iCannonType;
	int i;
	Group_FindOrCreateGroup("Guadeloupe_Lee");
	for (i=1; i<=2; i++)
	{       
		switch (i)
		{
			case 1: 
				iShipType = SHIP_SURPRISE;
				iCannonType = CANNON_TYPE_CANNON_LBS32;
			break;
			case 2: 
				iShipType = SHIP_LUGGERR;
				iCannonType = CANNON_TYPE_CANNON_LBS12;                                                                       break;
		}
		sld = GetCharacter(NPC_GenerateCharacter("GuadeloupeLeeCap_"+i, "citiz_"+(rand(9)+51), "man", "man", 45, FRANCE, -1, true, "soldier"));	
		FantomMakeCoolFighter(sld, 45, 110, 100, "blade_19", "pistol5", "bullet", 200);
		FantomMakeCoolSailor(sld, iShipType, "", iCannonType, 110, 110, 110);
		SelAllPerksToChar(sld, false);
		sld.Ship.Mode = "mercenary";
		sld.DontRansackCaptain = true;
		sld.AnalizeShips = true;
		sld.DontHitInStorm = true; // �� �������� � �����
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // ������ ��������
		sld.AlwaysSandbankManeuver = true;
		sld.MultiFighter = 1.5; // ������������
		sld.MultiShooter = 1.5;
		sld.SuperShooter  = true;
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		Group_AddCharacter("Guadeloupe_Lee", "GuadeloupeLeeCap_"+i);
	}
	Group_SetGroupCommander("Guadeloupe_Lee", "GuadeloupeLeeCap_1");
	Group_SetTaskNone("Guadeloupe_Lee");//��� ������
                   Group_SetAddress("Guadeloupe_Lee", "Guadeloupe", "IslandShips1", "SantLous_Port");
	Group_LockTask("Guadeloupe_Lee");
}

void Guadeloupe_DeleteShipLee()
{
	if (pchar.location == "Guadeloupe" && bSeaActive) return;
	Group_DeleteGroup("Guadeloupe_Lee");
	for (int i=1; i<=3; i++)
	{  
		if (GetCharacterIndex("GuadeloupeLeeCap_"+i) != -1)
		{
			sld = characterFromId("GuadeloupeLeeCap_"+i);
			sld.lifeday = 0;
		}
	}
}



//����� ��������, ������ � �������
void BerglarsInit()
{
	pchar.questTemp.tugs.berglarState = 1; //�������
	//============> ������ � ����-������
	pchar.questTemp.tugs.berglarSentJons = "Town_Dungeon"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarSentJons.hp = 160; //������� HP
	pchar.questTemp.tugs.berglarSentJons.locator = "reload7"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSentJons", "mercen_16", "man", "man", 22, ENGLAND, -1, false, "quest"));
	sld.name 	= "�����";
	sld.lastname = "�������";
	sld.rank = 31;
	sld.city = "SentJons";
	sld.location	= "SentJons_town";
	sld.location.group = "goto";
	sld.location.locator = "goto4";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "pistol_06");
	GiveItem2Character(sld, GetGeneratedItem("newblade12"));
	TakeNItems(sld, "jewelry1", 30+rand(10));
	LAi_SetCharacterUseBullet(sld, "cartridge");
     TakeNItems(sld, "grapeshot", 24);
	TakeNItems(sld, "bullet", 26);
	TakeNItems(sld, "cartridge", 22);
	TakeNItems(sld, "GunPowder", 31);
	sld.money = 10460;
	sld.talker = 7; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//=============> ������ �� ���������
	pchar.questTemp.tugs.berglarFortFrance = "FortFrance_Graveyard_Dungeon"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarFortFrance.hp = 228; //������� HP
	pchar.questTemp.tugs.berglarFortFrance.locator = "reload2"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarFortFrance", "mercen_17", "man", "man", 23, FRANCE, -1, false, "quest"));
	sld.name 	= "����";
	sld.lastname = "������";
	sld.rank = 29;
	sld.city = "FortFrance";
	sld.location	= "Martinique_House";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "pistol02");
	GiveItem2Character(sld, GetGeneratedItem("newblade13"));
	LAi_SetCharacterUseBullet(sld, "grapeshot");
     TakeNItems(sld, "grapeshot", 36);
	TakeNItems(sld, "bullet", 27);
	TakeNItems(sld, "cartridge", 33);
	TakeNItems(sld, "GunPowder", 48);
	TakeNItems(sld, "jewelry2", 25+rand(10));
	sld.money = 12670;
	sld.talker = 7; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.LifeDay = 3;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//============> ������ � ������ 
	pchar.questTemp.tugs.berglarMarigo = "Fishing_Settlement"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarMarigo.hp = 200; //������� HP
	pchar.questTemp.tugs.berglarMarigo.locator = "gate_back"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarMarigo", "mercen_15", "man", "man", 21, HOLLAND, -1, false, "quest"));
	sld.name 	= "��������";
	sld.lastname = "�������";
	sld.rank = 38;
	sld.city = "Marigo";
	sld.location	= "Marigo_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "pistol11");
	GiveItem2Character(sld, GetGeneratedItem("newblade14"));
	TakeNItems(sld, "jewelry3", 25+rand(10));
	LAi_SetCharacterUseBullet(sld, "cartridge");
     TakeNItems(sld, "grapeshot", 26);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 24);
	TakeNItems(sld, "GunPowder", 26);
	sld.money = 15480;
	sld.talker = 7; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	//============> ������ � �������-�����
	pchar.questTemp.tugs.berglarRoseau = "Roseau_TownCave"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarRoseau.hp = 200; //������� HP
	pchar.questTemp.tugs.berglarRoseau.locator = "basement1_back"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarRoseau", "mercen_14", "man", "man", 27, SPAIN, -1, false, "quest"));
	sld.name 	= "�������";
	sld.lastname = "��������";
	sld.rank = 27;
	sld.city = "Roseau";
	sld.location	= "Roseau_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "pistol6");
	GiveItem2Character(sld, GetGeneratedItem("newblade15"));
	TakeNItems(sld, "jewelry2", 30+rand(5));
	LAi_SetCharacterUseBullet(sld, "cartridge");
                TakeNItems(sld, "grapeshot", 40);
	TakeNItems(sld, "bullet", 25);
	TakeNItems(sld, "cartridge", 39);
	TakeNItems(sld, "GunPowder", 34);
	sld.money = 15180;
	sld.talker = 8; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//============> ������ � ����-�����
	pchar.questTemp.tugs.berglarSantLous = "SantLous_Dungeon"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarSantLous.hp = 170; //������� HP
	pchar.questTemp.tugs.berglarSantLous.locator = "reload2"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSantLous", "mercen_7", "man", "man", 22, SPAIN, -1, false, "quest"));
	sld.name 	= "�������";
	sld.lastname = "�������";
	sld.rank = 26;
	sld.city = "SantLous";
	sld.location	= "SantLous_town";
	sld.location.group = "goto";
	sld.location.locator = "goto8";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "pistol2");
	GiveItem2Character(sld, GetGeneratedItem("blade38"));
	TakeNItems(sld, "jewelry1", 40+rand(10));
	LAi_SetCharacterUseBullet(sld, "grapeshot");
     TakeNItems(sld, "grapeshot", 42);
	TakeNItems(sld, "bullet", 27);
	TakeNItems(sld, "cartridge", 34);
	TakeNItems(sld, "GunPowder", 53);
	sld.money = 15980;
	sld.talker = 7; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//============> ������ � ����� ��������
	pchar.questTemp.tugs.berglarSantaCatalina = "SantaCatalina_Graveyard_Dungeon"; //�������� ��� �������� ������
	pchar.questTemp.tugs.berglarSantaCatalina.hp = 230; //������� HP
	pchar.questTemp.tugs.berglarSantaCatalina.locator = "houseSp1"; //�������� �������
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSantaCatalina", "mercen_9", "man", "man", 25, SPAIN, -1, false, "quest"));
	sld.name 	= "����";
	sld.lastname = "����������";
	sld.rank = 28;
	sld.city = "SantaCatalina";
	sld.location	= "SantaCatalina_town";
	sld.location.group = "goto";
	sld.location.locator = "goto3";
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.greeting = "pirat_quest";
	GiveItem2Character(sld, "key1");
	GiveItem2Character(sld, "pistol_08");
	GiveItem2Character(sld, GetGeneratedItem("newblade25"));
	TakeNItems(sld, "jewelry3", 25+rand(10));
	LAi_SetCharacterUseBullet(sld, "grapeshot");
     TakeNItems(sld, "grapeshot", 44);
	TakeNItems(sld, "bullet", 23);
	TakeNItems(sld, "cartridge", 38);
	TakeNItems(sld, "GunPowder", 56);
	sld.money = 16450;
	sld.talker = 7; //������ ������
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "cirass7"); 
	EquipCharacterbyItem(sld, "cirass7"); 
	sld.SuperShooter  = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Dexterr", "Assassin2", "man", "man", 30, SPAIN, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "newblade18", "pistol_05", "cartridge", 100);
	sld.name 	= "�������";
	sld.lastname = "��������";
	sld.model = "Assassin"; 
	sld.model.animation = "man"; 
	sld.rank = 60;
	sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	sld.dialog.currentnode = "Final_fight";
	sld.city = "VillaAlegria";
	sld.location	= "church IM";
	sld.location.group = "Quest";
	sld.location.locator = "LLquest1";
	sld.greeting = "";
	sld.money = 30670;
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetCharacterPerk(sld, "CriticalHit");
	sld.SuperShooter  = true;
	LAi_SetImmortal(sld, false);
	sld.SaveItemsForDead  = true; 
	sld.DontClearDead = true;
	sld.MultiFighter = 2.5; // ������������
	sld.MultiShooter = 2.5;
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper"); 
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	GiveItem2Character(sld, "key2");
	GiveItem2Character(sld, "cirass8"); 
	EquipCharacterbyItem(sld, "cirass8"); 
	TakeNItems(sld, "jewelry1", 20+rand(5));
	TakeNItems(sld, "jewelry2", 14+rand(5));
	TakeNItems(sld, "jewelry3", 18+rand(5));
	TakeNItems(sld, "jewelry4", 16+rand(5));
	GiveItem2Character(sld, "icollection");
	GiveItem2Character(sld, "spyglass7");
	GiveItem2Character(sld, "BackPack4");
	LAi_SetCharacterUseBullet(sld, "cartridge");
	TakeNItems(sld, "cartridge", 53);

	// �������� (����������)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesRK", "Apostates_14", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "�������";
	sld.greeting = "";
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 21;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "topor_08");
	sld.equip.blade = "topor_08";
	TakeNItems(sld, "potion2", 2);
	LAi_SetImmortal(sld, true);
	sld.HoldEquip = true; 	//�� �������� ������
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetActorType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "PortAntonio_Bank_residence", "goto", "goto10");

	// ����� (����������)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesLA", "Apostates_13", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.greeting = "";
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "First time2";
	sld.rank = 11;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade41");
	sld.equip.blade = "blade41";
	TakeNItems(sld, "potion2", 2);
	sld.HoldEquip = true; 	//�� �������� ������
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetSitType(sld);
	sld.item_date = "";
	sld.Merchant.type = "company";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "PortAntonio_Bank_residence", "sit", "sit2");

	//������� (����������)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesDN", "Apostates_12", "man", "man2", 30, PIRATE, -1, false, "quest"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "�������";
	sld.lastname = "�����";
	RemoveAllCharacterItems(sld, true);
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "First time3";
	ChangeCharacterAddressGroup(sld, "PortAntonio_bank", "officers", "reload2_1");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);// ������� ������ �� ������� �������

	// �����
	sld = GetCharacter(NPC_GenerateCharacter("Raven", "Apostates_22", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "";
	sld.greeting = "";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Raven.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 40;
	LAi_SetHP(sld, 1000, 1000);
	sld.money = 100000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetShipSkill(sld, 90, 90, 90, 90, 90, 90, 90, 90, 90);
	SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade301");
	sld.equip.blade = "blade301";
	TakeNItems(sld, "potion2", 2);
	//sld.HoldEquip = true; 	//�� �������� ������
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "Providence_Temple", "goto", "goto18");
	LAi_SetGuardianType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
}


void GothicNpcInit()//������� ���� �������� ���������� �� ������ �����
{
	// �������
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas", "Xsardas", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "";
	//sld.greeting = "Gr_Xsardas";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Xsardas.c";
	sld.dialog.currentnode   = "First time";
	LAi_SetHP(sld, 250, 250);
	sld.money = 45000;
	sld.rank = 87;
	LAi_SetHP(sld, 160, 160); 
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Doctor3");
	sld.location = "Xsardas_Dungeon";
	sld.location.group = "quest";
	sld.location.locator = "quest2";
	LAi_SetPriestType(sld);
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	//������ ��������
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas_skel", "skel1", "skeleton", "skeleton", 10, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "�����";
	sld.lastname = "��������";
	sld.monster = true; // ������� ������
	sld.sex = "Skeleton"; 
	sld.viper = true;
	RemoveAllCharacterItems(sld, true);
	sld.dialog.filename   = "Gothic_Quest\npc\Monster.c";
	sld.dialog.currentnode   = "First time_skel";
	ChangeCharacterAddressGroup(sld, "Xsardas_fort", "soldiers", "protector2");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	//������ ��������
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas_skelet", "skel2", "skeleton", "skeleton", 10, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "�����";
	sld.lastname = "��������";
	RemoveAllCharacterItems(sld, true);
	sld.monster = true; // ������� ������
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.dialog.filename   = "Gothic_Quest\npc\Monster.c";
	sld.dialog.currentnode   = "First time_skel";
	ChangeCharacterAddressGroup(sld, "Xsardas_fort", "soldiers", "protector1");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	
	// �������
	sld = GetCharacter(NPC_GenerateCharacter("Sagitta", "Sagitta", "woman", "woman", 30, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "";
	//sld.greeting = "Gr_Sagitta";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Sagitta.c";
	sld.dialog.currentnode   = "First time";
	LAi_SetHP(sld, 250, 250);
	sld.money = 45000;
	sld.rank = 87;
	LAi_SetHP(sld, 160, 160); 
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Doctor3");
	GiveItem2Character(sld, "knife_01");
	sld.equip.blade = "knife_01";
	LAi_SetCitizenType(sld);
	LAi_RemoveLoginTime(sld);
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");
	//ChangeCharacterAddressGroup(sld, "Beliz_Cavern", "goto", "goto12");

	// ����� ��������� ����
	sld = GetCharacter(NPC_GenerateCharacter("Alligator", "Alligator_0", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.FaceId = 482;
	sld.HeroModel = "Alligator_0,Alligator_1,Alligator_2,Alligator_3,Alligator_4,protocusto,Alligator_5";
	sld.model.animation = "man";
	sld.nation = PIRATE;
	sld.name = "����";
	sld.lastname = "���������";
	//sld.greeting = "Gr_Alligator";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 10;
	LAi_SetHP(sld, 200, 200);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 45, 45, 50, 45, 35);
	SetShipSkill(sld, 35, 5, 5, 5, 5, 5, 55, 5, 55);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "IronWill");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "Gunman");
	GiveItem2Character(sld, "blade300");
	sld.equip.blade = "blade300";
	GiveItem2Character(sld, "Map_part2");
	TakeNItems(sld, "potion2", 2);
	sld.standUp = true; //�������� � �������� �� �����
	ChangeCharacterAddressGroup(sld, "Shore89", "goto", "goto1");
	LAi_SetGroundSitTypeNoGroup(sld);
	LAi_SetImmortal(sld, true);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	// ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("Samuel", "rivados_4", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "";
	sld.greeting = "Gr_Samuel";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Samuel.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 41;
	LAi_SetHP(sld, 850, 850);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade50");
	sld.equip.blade = "blade50";
	TakeNItems(sld, "potion2", 2);
	
	sld.location	= "House_Samuel";
	sld.location.group = "barmen";
	sld.location.locator = "bar1";
	sld.money = 5000;
	sld.nation = PIRATE;
	LAi_SetBarmanType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// ������ �� ������
	sld = GetCharacter(NPC_GenerateCharacter("TORLOF", "GothicN_2", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "";
	sld.greeting = "Gr_Torlof";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Torlof.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 11;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade42");
	sld.equip.blade = "blade42";
	TakeNItems(sld, "potion2", 2);
	
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_town", "goto", "goto16");
	LAi_SetGuardianType(sld);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// ������ �� �����
	sld = GetCharacter(NPC_GenerateCharacter("WOLF", "GothicN_5", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "";
	sld.greeting = "Gr_Wolf";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Wolf.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 11;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade43");
	sld.equip.blade = "blade43";
	TakeNItems(sld, "potion2", 2);
	
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_town", "goto", "goto2");
                   LAi_NoRebirthEnable(sld);
                   LAi_SetWarriorType(sld);
                   LAi_warrior_DialogEnable(sld, true);
                   LAi_SetLoginTime(sld, 0.0, 24.0);
                   sld.protector.CheckAlways = true;
	 LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// ������ �� �����
	sld = GetCharacter(NPC_GenerateCharacter("JARVIS", "GothicN_4", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "";
	sld.greeting = "Gr_Jarvis";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Jarvis.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 11;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade44");
	sld.equip.blade = "blade44";
	TakeNItems(sld, "potion2", 2);
	
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_Tavern", "sit", "sit2");
	LAi_SetSitType(sld);
     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// ������ �� ������
	sld = GetCharacter(NPC_GenerateCharacter("BUSTER", "GothicN_3", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "";
	sld.greeting = "Gr_Buster";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Buster.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 21;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "topor_08");
	sld.equip.blade = "topor_08";
	TakeNItems(sld, "potion2", 2);
	
	sld.standUp = true; //�������� � �������� �� �����
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_Port", "sit", "sit1");
	LAi_SetSitType(sld);
                  sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// ������ ��
	sld = GetCharacter(NPC_GenerateCharacter("GothicN_01", "GothicN_1", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.greeting = "SantLous_man";
	sld.Dialog.Filename = "Gothic_Quest\npc\Captain.c";
	sld.rank = 14;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	GiveItem2Character(sld, "topor_07");
	sld.equip.blade = "topor_07";
	TakeNItems(sld, "potion2", 2);
	
	sld.standUp = true; //�������� � �������� �� �����
	ChangeCharacterAddressGroup(sld, "SantLous_Port", "goto", "ass1");
	LAi_SetGroundSitTypeNoGroup(sld);
                  sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");



	sld = GetCharacter(NPC_GenerateCharacter("Lucia", "Lucia", "woman", "Lucia", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "";
	sld.greeting = "Gr_Lucia";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Marlin.c";
	sld.dialog.currentnode   = "First time";
	sld.rank = 12;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	LAi_NPC_EquipPerk(sld, "fantom");
	sld.perks.list.BasicDefense = true;
                     sld.perks.list.AdvancedDefense = true;
	sld.loyality = MAX_LOYALITY;
	sld.Payment = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade39");
	sld.equip.blade = "blade39";
	GiveItem2Character(sld, "pistol2");
	EquipCharacterbyItem(sld, "pistol2");
	LAi_SetCharacterUseBullet(sld, "bullet");
                    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	
	sld.standUp = true; //�������� � �������� �� �����
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	LAi_SetLoginTime(sld, 12.0, 23.99);
	ChangeCharacterAddressGroup(sld, "SantLous_HouseInsideR4", "sit", "sit1");
	LAi_SetSitType(sld);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	//����� ������
	sld = GetCharacter(NPC_GenerateCharacter("Chumakeiro", "smuggler_boss", "man", "man", 20, HOLLAND, -1, false, "quest"));
	sld.name = "����� ������";
	sld.lastname = "���������";
	sld.greeting = "Gr_OliverTrast";
	sld.rank = 20;
	LAi_SetHP(sld, 150, 150);
	sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_1.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "";
	sld.location.group = "";
	sld.location.locator = "";
	sld.money = 5000;
	LAi_SetImmortal(sld, true);

	//���� ������� �� �����
	sld = GetCharacter(NPC_GenerateCharacter("AnnaDeLeiva", "Catherine", "woman", "woman", 10, SPAIN, -1, false, "quest"));
	sld.name = "���� �������";
	sld.lastname = "�� �����";
	sld.greeting = "Gr_Dama";
	sld.rank = 10;
	LAi_SetHP(sld, 150, 150);
	sld.money = 5000;
	LAi_SetImmortal(sld, true);

	//������
	sld = GetCharacter(NPC_GenerateCharacter("Abuyin", "Abuyin", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "";
	sld.greeting = "";
	sld.rank = 20;
	LAi_SetHP(sld, 150, 150);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Abuyin.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "LeFransua_HouseInsideR1";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.money = 5000;
	sld.nation = PIRATE;
	LAi_SetBarmanType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);


	//��������
	sld = GetCharacter(NPC_GenerateCharacter("Baltram", "trader_16", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "";
	sld.greeting = "Gr_Baltram";
	sld.rank = 20;
	LAi_SetHP(sld, 150, 150);
	sld.Dialog.Filename = "Gothic_Quest\GothicLine\Baltram.c";
	sld.dialog.currentnode = "First time";
	sld.location	= "HouseBaltram";
	sld.location.group = "goto";
	sld.location.locator = "goto3";
	sld.money = 5000;
	sld.nation = PIRATE;
	LAi_SetImmortal(sld, true);
                   LAi_NoRebirthEnable(sld);
                   LAi_SetWarriorType(sld);
                   LAi_warrior_DialogEnable(sld, true);
                   LAi_SetLoginTime(sld, 0.0, 24.0);
                   SetFantomHP(sld);
                   sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");


}

void OfficerGirlInit()
{
    ref sld;
    
    // ������ ������. ���� �� �����, �.�. ����� ������� ������ ������ � ��������
	sld = GetCharacter(NPC_GenerateCharacter("Lorensia", "Lorensia11", "woman", "Lorensia", 30, PIRATE, -1, false, "quest"));
	sld.name = "��������";
	sld.lastname = "������";
	sld.greeting = "Gr_Lorensia";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.rank = 14;
	sld.greeting = "Gr_YokoDias";
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade37");
	sld.equip.blade = "blade37";
	GiveItem2Character(sld, "pistol2");
	EquipCharacterbyItem(sld, "pistol2");
	LAi_SetCharacterUseBullet(sld, "bullet");
                    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	
	sld.standUp = true; //�������� � �������� �� �����
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	ChangeCharacterAddressGroup(sld, "Roseau_bank", "goto", "goto6");
                     LAi_NoRebirthEnable(sld);
                     LAi_warrior_DialogEnable(sld, true);
                     LAi_SetLoginTime(sld, 17.0, 22.0);
                     SetFantomHP(sld);
                     sld.protector.CheckAlways = true;
				LAi_SetOwnerTypeNoGroup(sld);

	sld = GetCharacter(NPC_GenerateCharacter("Mirrinda", "Mirrinda", "woman", "Mirrinda", 30, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�����";
	sld.greeting = "Gr_Mirrinda";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_Angellica";
	sld.rank = 12;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 32, 15, 21, 23, 12);
	SetShipSkill(sld, 21, 10, 15, 17, 19, 12, 17, 26, 30);
	SetSPECIAL(sld, 8, 10, 9, 10, 7, 10, 9);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade44");
	sld.equip.blade = "blade44";
	GiveItem2Character(sld, "pistol2");
	EquipCharacterbyItem(sld, "pistol2");
	LAi_SetCharacterUseBullet(sld, "bullet");
                    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	
	sld.standUp = true; //�������� � �������� �� �����
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	ChangeCharacterAddressGroup(sld, "LeFransua_HouseHut7", "sit", "sit1");
                     LAi_NoRebirthEnable(sld);
                     LAi_warrior_DialogEnable(sld, true);
                     LAi_SetLoginTime(sld, 20.0, 23.59);
                     SetFantomHP(sld);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Fenia", "Fenia", "woman", "WomanK2", 30, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.greeting = "Gr_Fenia";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.rank = 12;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	sld.greeting = "Gr_YokoDias";
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 28, 12, 27, 29, 18);
	SetShipSkill(sld, 22, 14, 19, 16, 12, 11, 10, 27, 31);
	SetSPECIAL(sld, 7, 10, 9, 9, 8, 10, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade40");
	sld.equip.blade = "blade40";
	GiveItem2Character(sld, "pistol2");
	EquipCharacterbyItem(sld, "pistol2");
	LAi_SetCharacterUseBullet(sld, "bullet");
                  TakeNItems(sld, "bullet", 50);
	 AddItems(sld, "gunpowder", 50);
	 TakeNItems(sld, "potion2", 5);
	 
	 sld.standUp = true; //�������� � �������� �� �����
	 sld.perks.list.ShipEscape = true;
	 sld.perks.list.Ciras = true;
	 ChangeCharacterAddressGroup(sld, "FortOrange_town", "goto", "goto10");
                   LAi_NoRebirthEnable(sld);
                   LAi_SetWarriorType(sld);
                   LAi_warrior_DialogEnable(sld, true);
                   LAi_SetLoginTime(sld, 0.0, 24.0);
                   SetFantomHP(sld);
                   sld.protector.CheckAlways = true;
	 LAi_SetCharacterUseBullet(sld, "grapeshot");
	 LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Bony", "Bony", "woman", "jessika", 30, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "�����";
	sld.greeting = "Gr_Bony";
	sld.greeting = "Gr_Angellica";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.FaceId = 703;
	sld.rank = 10;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 30, 15, 30, 30, 20);
	SetShipSkill(sld, 25, 15, 20, 20, 15, 15, 10, 30, 30);
	SetSPECIAL(sld, 7, 10, 9, 9, 8, 10, 6);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	 SetCharacterPerk(sld, "ByWorker");
	 SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	 SetCharacterPerk(sld, "Gunman");
	 SetCharacterPerk(sld, "Tireless");
	 SetCharacterPerk(sld, "Doctor1");
	 SetCharacterPerk(sld, "Doctor2");
	 SetCharacterPerk(sld, "GrapplingProfessional");
	 GiveItem2Character(sld, "blade40");
	 sld.equip.blade = "blade40";
	 GiveItem2Character(sld, "pistol_08");
	 EquipCharacterbyItem(sld, "pistol_08");
	 LAi_SetCharacterUseBullet(sld, "grapeshot");
      TakeNItems(sld, "grapeshot", 50);
	 AddItems(sld, "gunpowder", 50);
	 TakeNItems(sld, "potion2", 5);
	 sld.standUp = true; //�������� � �������� �� �����
	 sld.perks.list.ShipEscape = true;
	 sld.perks.list.Ciras = true;
	 ChangeCharacterAddressGroup(sld, "LeKe_town", "goto", "goto10");
                      LAi_NoRebirthEnable(sld);
                      LAi_SetWarriorType(sld);
                      LAi_warrior_DialogEnable(sld, true);
                      LAi_SetLoginTime(sld, 0.0, 24.0);
                      SetFantomHP(sld);
                      sld.protector.CheckAlways = true;
	 LAi_SetCharacterUseBullet(sld, "grapeshot");
	 LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Daniel", "YokoDias", "woman", "YokoDias", 15, PIRATE, -1, false, "quest"));
	sld.name 	= "����";
	sld.lastname = "����";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_YokoDias";
	sld.rank = 15;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 250, 250);
	sld.money = 3000;
	sld.SuperShooter  = true;
	sld.HeroModel = "YokoDias,YokoDias_1,YokoDias_2,YokoDias_3,YokoDias_4,protocusto,YokoDias_8,YokoDias";
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.loyality = MAX_LOYALITY;
	SetSelfSkill(sld, 41, 54, 57, 63, 54);
	SetShipSkill(sld, 52, 25, 24, 28, 20, 39, 71, 20, 74);
	SetSPECIAL(sld, 10, 7, 10, 7, 9, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade38");
	sld.equip.blade = "blade38";
	GiveItem2Character(sld, "pistol3");
	EquipCharacterbyItem(sld, "pistol3");
	LAi_SetCharacterUseBullet(sld, "bullet");
                     TakeNItems(sld, "bullet", 50);
                     TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	
	sld.standUp = true; //�������� � �������� �� �����
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	ChangeCharacterAddressGroup(sld, "Pirates_town", "goto", "goto20");
                     LAi_NoRebirthEnable(sld);
                     LAi_SetWarriorType(sld);
                     LAi_warrior_DialogEnable(sld, true);
                     LAi_SetLoginTime(sld, 0.0, 24.0);
                     SetFantomHP(sld);
                     sld.protector.CheckAlways = true;
	LAi_SetCharacterUseBullet(sld, "grapeshot");
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
    	
	sld = GetCharacter(NPC_GenerateCharacter("Beatrice", "Angellica", "woman", "Angellica", 15, PIRATE, -1, false, "quest"));
	sld.name 	= "��������";
	sld.lastname = "����";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_Angellica";
	sld.rank = 17;
	LAi_SetHP(sld, 250, 250);
	sld.money = 3000;
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 40, 60, 55, 60, 50);
	SetShipSkill(sld, 50, 25, 25, 20, 20, 30, 70, 20, 70);
	SetSPECIAL(sld, 10, 7, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "GrapplingProfessional");
	GiveItem2Character(sld, "blade39");
	sld.equip.blade = "blade39";
	GiveItem2Character(sld, "pistol3");
	EquipCharacterbyItem(sld, "pistol3");
	LAi_SetCharacterUseBullet(sld, "bullet");
                     TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	
	sld.standUp = true; //�������� � �������� �� �����
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	ChangeCharacterAddressGroup(sld, "Vestpunt_town", "goto", "goto6");
                     LAi_NoRebirthEnable(sld);
                     LAi_SetWarriorType(sld);
                     LAi_warrior_DialogEnable(sld, true);
                     LAi_SetLoginTime(sld, 0.0, 24.0);
                     SetFantomHP(sld);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Chani", "Chani", "woman", "Chani", 1, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Chani.c";
	sld.dialog.currentnode   = "First time";
	//sld.greeting = "Gr_Chani";
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true; 
	sld.rank = 20;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	LAi_SetHP(sld, 250, 250); 
	SetSelfSkill(sld, 95, 50, 50, 90, 50);
	SetShipSkill(sld, 90, 25, 5, 5, 5, 5, 5, 15, 30);
	SetSPECIAL(sld, 6, 6, 8, 3, 9, 10, 4);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Doctor3");
	GiveItem2Character(sld, "indian_1");
	sld.equip.blade = "indian_1";
	TakeNItems(sld, "potion2", 5);
	ChangeCharacterAddressGroup(sld, "Indian_town", "goto", "goto8");
                     LAi_NoRebirthEnable(sld);
                     LAi_SetWarriorType(sld);
                     LAi_warrior_DialogEnable(sld, true);
                     LAi_SetLoginTime(sld, 0.0, 24.0);
                     SetFantomHP(sld);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

}

void OfficerMushketerInit()
{
    ref sld;
    //�������� �1 - �����
    sld = GetCharacter(NPC_GenerateCharacter("OfMush1", "quest_mush_2", "man", "mushketer", 15, PIRATE, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.greeting = "Gr_Officer";
	sld.rank = 15;
	LAi_SetHP(sld, 180, 180);
	sld.Dialog.Filename = "Enc_OfficerMush.c";
	sld.dialog.currentnode = "Lostpirate";
	TakeNItems(sld,"potion2", Rand(2)+2);
	GiveItem2Character(sld, "mushket");
	sld.equip.gun = "mushket";
    TakeNItems(sld,"bullet", 100);
	AddItems(sld, "GunPowder", 100);
    sld.Payment = true;
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	sld.location	= "Shore126";
	sld.location.group = "goto";
	sld.location.locator = "goto7";
	sld.money = 0;
	sld.SuperShooter  = true;
 	SetSPECIAL(sld, 6, 9, 8, 3, 6, 9, 9);
	SetSelfSkill(sld, 60, 3, 3, 100, 80);
	SetShipSkill(sld, 40, 7, 25, 15, 8, 10, 5, 10, 25);
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "HPPlus");
                     LAi_SetWarriorType(sld);
	LAi_warrior_DialogEnable(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	locations[FindLocation("SeaShore126")].DisableEncounters = true; //��������� � ������� ������� �� ����
	
	//�������� �2 - ��������
	sld = GetCharacter(NPC_GenerateCharacter("OfMush2", "quest_mush_1", "man", "mushketer", 18, SPAIN, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.greeting = "Gr_Officer";
	sld.rank = 18;
	LAi_SetHP(sld, 210, 210);
	sld.Dialog.Filename = "Enc_OfficerMush.c";
	sld.dialog.currentnode = "Saxon";
	TakeNItems(sld,"potion2", Rand(2)+2);
	GiveItem2Character(sld, "mushket");
	sld.equip.gun = "mushket";
	sld.MultiFighter = 2.0; // ������������
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	GiveItem2Character(sld, "cirass2");
	EquipCharacterbyItem(sld, "cirass2");
                  TakeNItems(sld,"bullet", 100);
	AddItems(sld, "GunPowder", 100);
                 sld.Payment = true;
	sld.location	= "VillaAlegria_town2";
	sld.location.group = "goto";
	sld.location.locator = "goto10";
	sld.money = 0;
	sld.SuperShooter  = true;
 	SetSPECIAL(sld, 7, 9, 7, 4, 3, 10, 8);
	SetSelfSkill(sld, 70, 10, 10, 100, 70);
	SetShipSkill(sld, 30, 9, 8, 8, 15, 20, 18, 5, 30);
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "IronWill");
                  LAi_SetWarriorType(sld);
                  LAi_warrior_DialogEnable(sld, true);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   ////////	   ���	07. 17 - 02.18		//////////							
///// 	by ����� ���������� & ������ �����     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////// ���� //////////////////////////

  /////////////////// ������ //////////////////////

///////////////////     ����� ������   //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Cortes", "Cortes", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "������";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.model = "Cortes"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Cortes";
sld.FaceId = 832;
sld.reputation = "15";
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "10000000000000";
sld.location = "Havana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 7, 9, 8, 9, 7, 6, 10);
SetSelfSkill(sld, 80, 50, 90, 70, 100);
SetShipSkill(sld, 100, 30, 70, 70, 95, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2");
SetCharacterPerk(sld, "Doctor3");
GiveItem2Character(sld, "pistol5");
GiveItem2Character(sld, "mushket2");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "topor_09");
sld.equip.blade = "topor_09";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ ��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLELINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.SuperShooter  = true;
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2200);
SetCharacterGoods(sld, GOOD_GRAPES, 1800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1300);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_POWDER, 6500);
SetCharacterGoods(sld, GOOD_WEAPON, 900);
SetCharacterGoods(sld, GOOD_FOOD, 1500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 900);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_FRUITS, 230);
SetCharacterGoods(sld, GOOD_TOBACCO, 130);
SetCharacterGoods(sld, GOOD_CLOTHES, 180);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.0, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

///////////////////     ���� �����     //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Dasko", "Dasko", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "�����";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Dasko"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Dasko";
sld.FaceId = 805;
sld.reputation = "65";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "50000";
sld.location = "Havana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 7, 6, 4, 5, 8, 3);
SetSelfSkill(sld, 50, 60, 75, 55, 35);
SetShipSkill(sld, 55, 45, 40, 35, 65, 45, 75, 50, 40);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair"); 
GiveItem2Character(sld, "blade_14"); 
sld.equip.blade = "blade_14"; 	
GiveItem2Character(sld, "pistol1"); 
EquipCharacterbyItem(sld, "pistol1");
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5); 
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "��� ����������"; 
sld.Ship.Mode = "pirate";
sld.Ship.Type = GenerateShipExt(SHIP_GALEON_L, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 700);
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_FOOD, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_PLANKS, 150);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 120);
SetCharacterGoods(sld, GOOD_FRUITS, 250);
SetCharacterGoods(sld, GOOD_TOBACCO, 100);
SetCharacterGoods(sld, GOOD_CLOTHES, 150);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.0, 7.59); 
LAi_SetHP(sld, 400+MOD_SKILL_ENEMY_RATE*10, 400+MOD_SKILL_ENEMY_RATE*10); 


///////////////////     ������� �����  //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Lopez", "Lopez", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "�������"; 
sld.lastname = "�����";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Lopez"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Lopez";
sld.FaceId = 907;
sld.reputation = "55";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "75000";
sld.location = "Havana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 6, 7, 9, 5, 7, 4, 8);
SetSelfSkill(sld, 60, 85, 50, 65, 55);
SetShipSkill(sld, 75, 25, 80, 80, 80, 50, 40, 60, 65);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade41");
sld.equip.blade = "blade41";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��� �������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CARACCA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 700);
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_FOOD, 1100);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 165);
SetCharacterGoods(sld, GOOD_PLANKS, 145);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 115);
SetCharacterGoods(sld, GOOD_FRUITS, 200);
SetCharacterGoods(sld, GOOD_TOBACCO, 100);
SetCharacterGoods(sld, GOOD_CLOTHES, 150);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.0, 23.59); 
LAi_SetHP(sld, 380+MOD_SKILL_ENEMY_RATE*10, 380+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ //////////////////////


/////////////////// �������� ///////////////////

/////////////////////// ���������� /////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Inqusitor", "Inqusitor", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "����������";
sld.lastname = ""; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Inqusitor"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Inqusitor";
sld.FaceId = 897;
sld.reputation = "1";      
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "15000";     
sld.location = "Santiago_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 5, 8, 5, 8, 8, 6); 
SetSelfSkill(sld, 30, 30, 55, 40, 25); 
SetShipSkill(sld, 50, 35, 40, 40, 65, 30, 20, 40, 10); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_36"); 
sld.equip.blade = "blade_36"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SMALLGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 800);
SetCharacterGoods(sld, GOOD_GRAPES, 220);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 600);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 1000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 700);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 00.0, 7.59); 
LAi_SetHP(sld, 500+MOD_SKILL_ENEMY_RATE*10, 500+MOD_SKILL_ENEMY_RATE*10); 


///////////////////// ��������� ����� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Posol", "Posol", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "���������"; 
sld.lastname = "�����"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Posol"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Posol";
sld.FaceId = 943;
sld.reputation = "90";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "15000";
sld.location = "Santiago_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 10, 4, 6, 10, 3); 
SetSelfSkill(sld, 40, 50, 90, 60, 80); 
SetShipSkill(sld, 40, 65, 50, 45, 65, 55, 30, 30, 45); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_32");
sld.equip.blade = "blade_32";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 800);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 900); 
SetCharacterGoods(sld, GOOD_POWDER, 1100);
SetCharacterGoods(sld, GOOD_WEAPON, 220);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 600);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

/////////////////////// �������� /////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Strannik", "Strannik", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "��������"; 
sld.lastname = ""; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Strannik"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Strannik";
sld.FaceId = 944;
sld.reputation = "70"; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "25000";
sld.location = "Santiago_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 5, 7, 10, 3, 7, 10, 5); 
SetSelfSkill(sld, 45, 65, 100, 60, 90); 
SetShipSkill(sld, 80, 40, 80, 80, 80, 35, 40, 45, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "topor_09");
sld.equip.blade = "topor_09";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3"); 
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SPAFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500); 
SetCharacterGoods(sld, GOOD_GRAPES, 1500); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500); 
SetCharacterGoods(sld, GOOD_BOMBS, 150); 
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 5000); 
SetCharacterGoods(sld, GOOD_WEAPON, 700); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700); 
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_GOLD, 500);   
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// �������� ///////////////////


//////////////// ������ �������� ///////////////

/////////////////// ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Blackman", "Blackman", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = ""; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Blackman"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Blackman";
sld.FaceId = 887;
sld.reputation = "1";     
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "30000"; 
sld.SuperShooter  = true;  
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;  
sld.location = "PuertoPrincipe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 6, 9, 6, 7, 8, 5); 
SetSelfSkill(sld, 20, 60, 45, 45, 40); 
SetShipSkill(sld, 70, 35, 80, 80, 65, 35, 50, 55, 30); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_30"); 
sld.equip.blade = "blade_30"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARXEBEC, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 700);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 900);
SetCharacterGoods(sld, GOOD_FOOD, 2000); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SLAVES, 300);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 80);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Skull", "Skull", "man", "man_B", 32, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Skull"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Skull";
sld.FaceId = 885;
sld.reputation = 90;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "30000"; 
sld.SuperShooter  = true;
sld.location = "PuertoPrincipe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 7, 9, 3, 9, 7, 8); 
SetSelfSkill(sld, 90, 90, 90, 90, 40); 
SetShipSkill(sld, 75, 30, 40, 50, 80, 40, 100, 45, 85); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Turn180");  
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade53"); 
sld.equip.blade = "blade53"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
TakeNItems(sld, "potionrum", 100);
GiveItem2Character(sld, "Map_part1");
GiveItem2Character(sld, "Map_part2");
sld.Abordage.Enable = true;
sld.Ship.Name = "����"; 
sld.Ship.Type = GenerateShipExt(SHIP_RAIDER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 95;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 6000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 6900);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_PLANKS, 120);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_FRUITS, 200);
SetCharacterGoods(sld, GOOD_TOBACCO, 100);
UpgradeShipParameter(sld, "SpeedRate");
UpgradeShipParameter(sld, "TurnRate");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 395+MOD_SKILL_ENEMY_RATE*10, 395+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ��� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1_3", "Corsair1_3", "man", "man_B", 5, PIRATE, -1, false, "quest"));
sld.name = "���-�����";
sld.lastname = "��"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Corsair1_3"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Corsair1_3";
sld.FaceId = 878;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PuertoPrincipe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 9, 7, 7, 10, 9, 10); 
SetSelfSkill(sld, 15, 10, 20, 20, 20); 
SetShipSkill(sld, 20, 20, 20, 20, 35, 25, 25, 25, 15); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_KETCH, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 67;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 200); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 50);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 330+MOD_SKILL_ENEMY_RATE*10, 330+MOD_SKILL_ENEMY_RATE*10);  

//////////////// ������ �������� ///////////////


///////////////////// ���� //////////////////////////


/////////////////// ������� ///////////////////

///////////////////// ���� ��������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Beltro", "Beltro", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "���������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Beltro"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Beltro";
sld.FaceId = 886;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "15000";
sld.location = "Tortuga_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 9, 9, 3, 6, 6, 6); 
SetSelfSkill(sld, 45, 10, 10, 25, 20); 
SetShipSkill(sld, 50, 20, 35, 30, 25, 15, 30, 20, 45); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot");
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_08");
sld.equip.blade = "blade_08";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Mode = "mercenary";
sld.Ship.Name = "�� ���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_GALIOT, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS8;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 75;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 25;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 400); 
SetCharacterGoods(sld, GOOD_GRAPES, 300); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 200); 
SetCharacterGoods(sld, GOOD_BOMBS, 200); 
SetCharacterGoods(sld, GOOD_FOOD, 235); 
SetCharacterGoods(sld, GOOD_POWDER, 1500); 
SetCharacterGoods(sld, GOOD_WEAPON, 150); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200); 
SetCharacterGoods(sld, GOOD_RUM, 40); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 275+MOD_SKILL_ENEMY_RATE*10, 275+MOD_SKILL_ENEMY_RATE*10); 


////////////////////// �������� ����� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Captaine_Chevalle", "Captaine_Chevalle", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "��������"; 
sld.lastname = "�����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Captaine_Chevalle"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Captaine_Chevalle";
sld.FaceId = 880;
sld.reputation = 35;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "20000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Tortuga_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 6, 8, 6, 8, 9, 4); 
SetSelfSkill(sld, 70, 10, 15, 15, 45); 
SetShipSkill(sld, 10, 25, 20, 30, 45, 50, 35, 20, 70); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair")
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Builder"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_16");
sld.equip.blade = "blade_16";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGQUEEN, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 65;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 700); 
SetCharacterGoods(sld, GOOD_GRAPES, 440); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 520); 
SetCharacterGoods(sld, GOOD_BOMBS, 600); 
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 2500); 
SetCharacterGoods(sld, GOOD_WEAPON, 310); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 450); 
SetCharacterGoods(sld, GOOD_RUM, 150); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 375+MOD_SKILL_ENEMY_RATE*10, 375+MOD_SKILL_ENEMY_RATE*10); 

////////////////////  ������ ������  ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("offi_fra", "offi_fra", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "������"; 
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.model = "offi_fra"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "offi_fra";
sld.FaceId = 901;
sld.reputation = 50; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "50000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Tortuga_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 5, 6, 3, 8, 7, 4); 
SetSelfSkill(sld, 50, 100, 50, 95, 65); 
SetShipSkill(sld, 90, 70, 100, 100, 100, 60, 70, 75, 50); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "CannonProfessional"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "Turn180"); 
SetCharacterPerk(sld, "SailingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "IronWill"); 
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_30");
sld.equip.blade = "blade_30";
GiveItem2Character(sld, "BackPack4");
EquipCharacterbyItem(sld, "BackPack4"); 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LINESHIP, true, sld); 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 35;
SetCharacterGoods(sld, GOOD_BALLS, 2000); 
SetCharacterGoods(sld, GOOD_GRAPES, 1500); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200); 
SetCharacterGoods(sld, GOOD_BOMBS, 900); 
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 6500); 
SetCharacterGoods(sld, GOOD_WEAPON, 1000); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 800); 
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_FRUITS, 300);
SetCharacterGoods(sld, GOOD_TOBACCO, 300);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10); 

////////////////////  ������� ������  ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Daniell2", "Daniell2", "woman", "WomanK2", 10, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Daniell2"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Daniell2";
sld.FaceId = 754;
sld.reputation = 100;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 15000; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Tortuga_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front3";
sld.greeting = "Woman_Captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 9, 7, 7, 5, 7, 8, 7); 
SetSelfSkill(sld, 50, 15, 15, 50, 20); 
SetShipSkill(sld, 50, 15, 20, 20, 25, 30, 25, 40, 70); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "InstantRepair"); 
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_16"); 
sld.equip.blade = "blade_16"; 
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_CAREERLUGGER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 70); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 225+MOD_SKILL_ENEMY_RATE*10, 225+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ///////////////////

/////////////////// ������-���� ///////////////////

/////////////////// ���-���� ///////////////////

/////////////////// ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Leon", "Leon", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = ""; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Leon"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Leon";
sld.FaceId = 902;
sld.reputation = "75"; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "15000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SanJuan_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 7, 8, 5, 10, 8, 7); 
SetSelfSkill(sld, 40, 5, 10, 10, 25); 
SetShipSkill(sld, 25, 50, 15, 10, 30, 15, 10, 10, 20); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Medic"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_03");
sld.equip.blade = "blade_03";
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_GAFELSLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 65;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 55;
sld.Ship.Crew.Exp.Soldiers = 85;
SetCharacterGoods(sld, GOOD_BALLS, 600); 
SetCharacterGoods(sld, GOOD_GRAPES, 500); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 400); 
SetCharacterGoods(sld, GOOD_BOMBS, 300); 
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 2500); 
SetCharacterGoods(sld, GOOD_WEAPON, 200); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 100); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 225+MOD_SKILL_ENEMY_RATE*10, 225+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("searcher", "searcher", "man", "man_B", 20, SPAIN, -1, false, "quest"));
sld.name = "�������"; 
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "searcher"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "searcher";
sld.FaceId = 900;
sld.reputation = "40"; 
sld.alignment = "bad"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "28000";
sld.SuperShooter  = true;
sld.location = "SanJuan_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 10, 6, 3, 7, 3); 
SetSelfSkill(sld, 20, 15, 70, 45, 15); 
SetShipSkill(sld, 15, 85, 25, 30, 65, 35, 60, 65, 25); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ProfessionalCommerce"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "MusketsShoot"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_06");
sld.equip.blade = "blade_06";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��� �����"; 
sld.Ship.Type = GenerateShipExt(SHIP_TRADEPINNACE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 40;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 30;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 1500); 
SetCharacterGoods(sld, GOOD_GRAPES, 1200); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000); 
SetCharacterGoods(sld, GOOD_BOMBS, 800); 
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 4500); 
SetCharacterGoods(sld, GOOD_WEAPON, 300); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_TOBACCO, 1500);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 240+MOD_SKILL_ENEMY_RATE*10, 240+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ���� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Man3_1", "Man3_1", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Man3_1"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Man3_1";
sld.FaceId = 884;
sld.reputation = "1"; 
sld.alignment = "bad"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "25000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SanJuan_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 10, 7, 5, 7, 10, 8); 
SetSelfSkill(sld, 60, 20, 10, 15, 30); 
SetShipSkill(sld, 45, 60, 15, 20, 45, 65, 35, 30, 50); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_27");
sld.equip.blade = "blade_27";
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_CARAVEL, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1200); 
SetCharacterGoods(sld, GOOD_GRAPES, 1000); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 800); 
SetCharacterGoods(sld, GOOD_BOMBS, 500); 
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 4000); 
SetCharacterGoods(sld, GOOD_WEAPON, 300); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 250); 
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_FRUITS, 300);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ���-���� ///////////////////

/////////////////// ����� �������� ///////////////////

/////////////////// ������ ���������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Chameleon", "Chameleon", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "����������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Chameleon"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Chameleon";
sld.FaceId = 890;
sld.reputation = "100"; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "30000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "VillaAlegria_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 6, 7, 7, 10); 
SetSelfSkill(sld, 40, 60, 80, 70, 80); 
SetShipSkill(sld, 75, 50, 55, 55, 80, 45, 85, 95, 35); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Medic"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_24");
sld.equip.blade = "blade_24";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 1000); 
SetCharacterGoods(sld, GOOD_GRAPES, 1000); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000); 
SetCharacterGoods(sld, GOOD_BOMBS, 1000); 
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 4500); 
SetCharacterGoods(sld, GOOD_WEAPON, 500); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 250);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_ROPES, 200);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 400+MOD_SKILL_ENEMY_RATE*10, 400+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� �� �� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("my_gg", "my_gg", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "�������"; 
sld.lastname = "�� �� ����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "my_gg"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "my_gg";
sld.FaceId = 904;
sld.reputation = "30"; 
sld.alignment = "bad"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "15000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "VillaAlegria_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 7, 3, 5, 8, 7); 
SetSelfSkill(sld, 50, 10, 15, 30, 70); 
SetShipSkill(sld, 20, 25, 10, 20, 30, 40, 20, 20, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "blade_26");
sld.equip.blade = "blade_26";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2"); 
LAi_SetCharacterUseBullet(sld, "Bullet");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5"); 
TakeNItems(sld, "Bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LATINA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1000); 
SetCharacterGoods(sld, GOOD_GRAPES, 800); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 600); 
SetCharacterGoods(sld, GOOD_BOMBS, 1000); 
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 3500); 
SetCharacterGoods(sld, GOOD_WEAPON, 400); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400); 
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_PLANKS, 80);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 80);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 330+MOD_SKILL_ENEMY_RATE*10, 330+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("fatman", "fatman", "man", "man_B", 5, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "�����"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "fatman"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "fatman";
sld.FaceId = 908;
sld.reputation = "50"; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "1000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "VillaAlegria_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 3, 3, 3, 10, 10, 3); 
SetSelfSkill(sld, 3, 15, 5, 2, 1); 
SetShipSkill(sld, 2, 90, 4, 3, 30, 10, 5, 7, 12); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ProfessionalCommerce"); 
GiveItem2Character(sld, "blade_11");
sld.equip.blade = "blade_11";
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1"); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BARQUE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 10;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 10;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_BALLS, 10); 
SetCharacterGoods(sld, GOOD_GRAPES, 10); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 10); 
SetCharacterGoods(sld, GOOD_BOMBS, 10); 
SetCharacterGoods(sld, GOOD_FOOD, 150); 
SetCharacterGoods(sld, GOOD_POWDER, 100); 
SetCharacterGoods(sld, GOOD_WEAPON, 100); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 100);
SetCharacterGoods(sld, GOOD_BRICK, 1500); 
SetCharacterGoods(sld, GOOD_RUM, 10);
SetCharacterGoods(sld, GOOD_PLANKS, 3);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 5);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 550+MOD_SKILL_ENEMY_RATE*10, 550+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ����� �������� ///////////////////

/////////////////// ������-���� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ��-���� ///////////////////

/////////////////// ������ ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sailor13", "Sailor13", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "�����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Sailor13"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Sailor13";
sld.FaceId = 903;
sld.reputation = "45"; 
sld.alignment = "bad"; 
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "50000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LaVega_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 5, 9, 5, 10, 6, 4); 
SetSelfSkill(sld, 20, 25, 85, 60, 25); 
SetShipSkill(sld, 70, 45, 60, 75, 60, 35, 35, 35, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicCommerce"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "topor_04");
sld.equip.blade = "topor_04";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����� �������"; 
sld.Ship.Type = GenerateShipExt(SHIP_GAFELSCHOONER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 75;
SetCharacterGoods(sld, GOOD_BALLS, 900); 
SetCharacterGoods(sld, GOOD_GRAPES, 550); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 400); 
SetCharacterGoods(sld, GOOD_BOMBS, 600); 
SetCharacterGoods(sld, GOOD_FOOD, 900); 
SetCharacterGoods(sld, GOOD_POWDER, 2800); 
SetCharacterGoods(sld, GOOD_WEAPON, 400); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_PLANKS, 120);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 395+MOD_SKILL_ENEMY_RATE*10, 395+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ����� ��������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat9", "pirat9", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "���������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "pirat9"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "pirat9";
sld.FaceId = 889;
sld.reputation = 70; 
sld.alignment = "good"; 
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "100000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LaVega_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 7, 3, 7, 6, 5); 
SetSelfSkill(sld, 20, 75, 10, 50, 60); 
SetShipSkill(sld, 75, 60, 60, 50, 80, 20, 55, 50, 30); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_19");
sld.equip.blade = "blade_19";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3"); 
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1200);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 600);
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_FRUITS, 100);
SetCharacterGoods(sld, GOOD_SUGAR, 300);
SetCharacterGoods(sld, GOOD_TOBACCO, 300);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 400+MOD_SKILL_ENEMY_RATE*10, 400+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ ������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Lou", "Lou", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "�������";
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Lou"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Lou";
sld.FaceId = 802;
sld.reputation = 15;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "50000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LaVega_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 6, 6, 6, 6, 6, 6);
SetSelfSkill(sld, 70, 40, 45, 50, 70);
SetShipSkill(sld, 70, 60, 70, 60, 65, 60, 70, 65, 80);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense"); 
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_14");
sld.equip.blade = "blade_14";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");  
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 3);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������� �����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEXEBEC, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 200);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 450);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 340);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 375+MOD_SKILL_ENEMY_RATE*10, 375+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// �������� �������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bella", "Bella", "woman", "WomanK2", 25, PIRATE, -1, false, "quest"));
sld.name = "��������";
sld.lastname = "��������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Bella"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Bella";
sld.FaceId = 757;
sld.reputation = 1;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LaVega_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front3";
sld.greeting = "Woman_Captain"; 
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 9, 9, 6, 9, 8, 6); 
SetSelfSkill(sld, 50, 80, 40, 70, 30); 
SetShipSkill(sld, 70, 20, 40, 40, 80, 20, 70, 50, 70); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_20"); 
sld.equip.blade = "blade_20";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");    
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����� ��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 6500);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_SLAVES, 300); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 380+MOD_SKILL_ENEMY_RATE*10, 380+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ��-���� ///////////////////

/////////////////// ����-�-����� ///////////////////

/////////////////// ����-����� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Vilnev", "Vilnev", "man", "man", 40, FRANCE, -1, false, "quest"));
sld.name = "����-�����"; 
sld.lastname = "������";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.model = "Vilnev"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Vilnev";
sld.FaceId = 934;
sld.reputation = "100";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "300000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortPax_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 8, 8, 8, 7, 10, 7);
SetSelfSkill(sld, 95, 85, 95, 80, 95);
SetShipSkill(sld, 95, 95, 95, 95, 100, 95, 100, 95, 95);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_36");
sld.equip.blade = "blade_36";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 15);
sld.Abordage.Enable = true;
sld.Ship.Name = "����������� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLELINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 3000);
SetCharacterGoods(sld, GOOD_GRAPES, 2500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 10000);
SetCharacterGoods(sld, GOOD_WEAPON, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 2500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_GOLD, 300);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.0, 7.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���-���� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sumor", "Sumor", "man", "man_B", 30, FRANCE, -1, false, "quest"));
sld.name = "���-����";
sld.lastname = "�����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Sumor"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Sumor";
sld.FaceId = 935;
sld.reputation = 50;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 25000; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortPax_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 6, 5, 9, 4, 3, 7); 
SetSelfSkill(sld, 70, 85, 60, 70, 65); 
SetShipSkill(sld, 70, 80, 65, 75, 80, 45, 60, 40, 80); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_20"); 
sld.equip.blade = "blade_20"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 6000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_FRUITS, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.0, 15.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);   

///////////////////// ����� ������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Shampan", "Shampan", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Shampan"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Shampan";
sld.FaceId = 936;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "15000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortPax_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 4, 5, 3, 6, 8, 4); 
SetSelfSkill(sld, 55, 30, 30, 35, 30); 
SetShipSkill(sld, 50, 30, 45, 40, 45, 15, 30, 50, 45); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_03");
sld.equip.blade = "blade_03";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 75;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 25;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 1000); 
SetCharacterGoods(sld, GOOD_GRAPES, 800); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 600); 
SetCharacterGoods(sld, GOOD_BOMBS, 400); 
SetCharacterGoods(sld, GOOD_FOOD, 505); 
SetCharacterGoods(sld, GOOD_POWDER, 2500); 
SetCharacterGoods(sld, GOOD_WEAPON, 300); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 135); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 220+MOD_SKILL_ENEMY_RATE*10, 220+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����-�-����� ///////////////////

/////////////////// �����-������� ///////////////////

/////////////////// ����� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pansa", "Pansa", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�����"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Pansa"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Pansa";
sld.FaceId = 940;
sld.reputation = "60";     
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "30000";  
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;  
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantoDomingo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 5, 8, 4, 9, 7); 
SetSelfSkill(sld, 60, 20, 35, 55, 50); 
SetShipSkill(sld, 60, 55, 60, 60, 65, 55, 50, 30, 55); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "ImmediateReload"); 
SetCharacterPerk(sld, "HullDamageUp");  
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_08"); 
sld.equip.blade = "blade_08"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��� �����"; 
sld.Ship.Type = GenerateShipExt(SHIP_SPAGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 700);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 900);
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_SHIPSILK, 150);
SetCharacterGoods(sld, GOOD_ROPES, 200);
SetCharacterGoods(sld, GOOD_OIL, 100);
SetCharacterGoods(sld, GOOD_SANDAL, 50);
SetCharacterGoods(sld, GOOD_RUM, 200);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 300+MOD_SKILL_ENEMY_RATE*10, 300+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Kihot", "Kihot", "man", "man_B", 25, SPAIN, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Kihot"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Kihot";
sld.FaceId = 941;
sld.reputation = 100;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "30000"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantoDomingo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 10, 7, 5, 6, 8, 10); 
SetSelfSkill(sld, 1, 100, 2, 100, 100); 
SetShipSkill(sld, 100, 20, 50, 50, 80, 40, 80, 45, 1); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Turn180");  
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "InstantRepair"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade41"); 
sld.equip.blade = "blade41"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARMEDFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 95;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 2500);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 9000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_IVORY, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////// ������ �� ��������� //////////////

sld = GetCharacter(NPC_GenerateCharacter("Servantes", "Servantes", "man", "man_B", 22, SPAIN, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�� ���������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Servantes"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Servantes";
sld.FaceId = 939;
sld.reputation = 75;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 100000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantoDomingo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 6, 9, 5, 8, 4, 10); 
SetSelfSkill(sld, 80, 30, 20, 80, 30); 
SetShipSkill(sld, 45, 35, 30, 35, 65, 40, 50, 60, 30); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_26"); 
sld.equip.blade = "blade_26"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARMEDXEBEC, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 250); 
SetCharacterGoods(sld, GOOD_CHOCOLATE, 300); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// �����-������� ///////////////////

/////////////////// ��-�� ///////////////////

/////////////////// ���� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pitt_2", "Pitt_2", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Pitt_2,Pitt_2_1,Pitt_2_2,Pitt_2_3,Pitt_2_4,protocusto,Pitt_2,Pitt_2";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Pitt_2";
sld.FaceId = 851;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "LeKe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit12";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 8, 10, 5, 8, 9, 6); 
SetSelfSkill(sld, 10, 15, 25, 20, 30); 
SetShipSkill(sld, 25, 20, 40, 45, 25, 30, 20, 25, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Gunman");
GiveItem2Character(sld, "pistol11");
GiveItem2Character(sld, "mushket3");
sld.equip.gun = "pistol11";
GiveItem2Character(sld, "newblade11"); 
sld.equip.blade = "newblade11"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CONTRABAND, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 150);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 100); 
SetCharacterGoods(sld, GOOD_ROPES, 300); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld);
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.99); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sancho", "Sancho_1", "man", "man", 18, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Sancho_1,Sancho_2,Sancho_3,Sancho_4,Sancho_5,protocusto,Sancho_1,Sancho_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Sancho";
sld.FaceId = 88;
sld.reputation = 25;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LeKe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit12";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 7, 8, 7, 8, 4, 4); 
SetSelfSkill(sld, 30, 65, 35, 50, 35); 
SetShipSkill(sld, 60, 45, 30, 35, 45, 60, 55, 35, 60); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "ProfessionalDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "IronWill");
GiveItem2Character(sld, "mushket1"); 
GiveItem2Character(sld, "pistol_02");
sld.equip.gun = "pistol_02";
GiveItem2Character(sld, "newblade7"); 
sld.equip.blade = "newblade7"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 45;
sld.Ship.Crew.Exp.Sailors = 65;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 525);
SetCharacterGoods(sld, GOOD_BOMBS, 690);
SetCharacterGoods(sld, GOOD_FOOD, 380); 
SetCharacterGoods(sld, GOOD_POWDER, 590);
SetCharacterGoods(sld, GOOD_WEAPON, 350);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 230);
SetCharacterGoods(sld, GOOD_RUM, 70); 
SetCharacterGoods(sld, GOOD_DYES, 180);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.99); 
UpgradeShipParameter(sld, "MaxCrew");
LAi_SetHP(sld, 335+MOD_SKILL_ENEMY_RATE*10, 335+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ����� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("PitBleik", "PitBleik_0", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "PitBleik_0,PitBleik_1,PitBleik_2,PitBleik_3,PitBleik_4,protocusto,PitBleik_0,PitBleik_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "PitBleik";
sld.FaceId = 966;
sld.reputation = 55;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LeKe_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit12";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 6, 6, 6, 9, 9, 10); 
SetSelfSkill(sld, 85, 55, 55, 85, 60); 
SetShipSkill(sld, 80, 70, 60, 50, 80, 50, 50, 60, 80); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol11");
sld.equip.gun = "pistol11";
GiveItem2Character(sld, "newblade20"); 
sld.equip.blade = "newblade20";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");    
LAi_SetCharacterUseBullet(sld, "Bullet"); 
TakeNItems(sld, "Bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "mushket2"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 95;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 980);
SetCharacterGoods(sld, GOOD_GRAPES, 790);
SetCharacterGoods(sld, GOOD_KNIPPELS, 340);
SetCharacterGoods(sld, GOOD_BOMBS, 320);
SetCharacterGoods(sld, GOOD_FOOD, 930); 
SetCharacterGoods(sld, GOOD_POWDER, 4300);
SetCharacterGoods(sld, GOOD_WEAPON, 560);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 570);
SetCharacterGoods(sld, GOOD_RUM, 120); 
SetCharacterGoods(sld, GOOD_SILK, 600); 
LAi_SetSitType(sld); 
UpgradeShipParameter(sld, "MaxCrew");
UpgradeShipParameter(sld, "WindAgainstSpeed");
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.99); 
LAi_SetHP(sld, 290+MOD_SKILL_ENEMY_RATE*10, 290+MOD_SKILL_ENEMY_RATE*10);

/////////////////// ��-�� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ���� �� ����� ///////////////////

/////////////////// ��� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jack", "Jack", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE; 
sld.model = "Jack"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Jack";
sld.FaceId = 867;
sld.reputation = 30;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "15000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "FortFrance_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 10, 9, 8, 8, 7, 10); 
SetSelfSkill(sld, 15, 30, 15, 100, 90); 
SetShipSkill(sld, 80, 25, 30, 30, 45, 20, 25, 25, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_05");
sld.equip.blade = "blade_05";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEBRIG, true, sld); 
sld.Ship.Stopped = true;
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 30;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 300);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 380+MOD_SKILL_ENEMY_RATE*10, 380+MOD_SKILL_ENEMY_RATE*10); 


/////////////////// ����� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("will_2", "will_2", "man", "man_B", 9, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "will_2"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "will_2";
sld.FaceId = 874;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "15000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "FortFrance_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 9, 9, 3, 7, 6, 8); 
SetSelfSkill(sld, 10, 30, 10, 15, 30); 
SetShipSkill(sld, 30, 15, 10, 10, 30, 15, 30, 35, 10); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_04"); 
sld.equip.blade = "blade_04"; 
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTSLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 35;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 50);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 220+MOD_SKILL_ENEMY_RATE*10, 220+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Soldier_Fra6", "Soldier_Fra6", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Soldier_Fra6"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Soldier_Fra6";
sld.FaceId = 909;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "15000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "FortFrance_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 8, 8, 4, 10, 9, 9); 
SetSelfSkill(sld, 5, 15, 30, 35, 15); 
SetShipSkill(sld, 25, 35, 20, 20, 30, 20, 30, 35, 20); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_07"); 
sld.equip.blade = "blade_07"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARSLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 250); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 180);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� �� ����� ///////////////////


/////////////////// �� ������� ///////////////////

/////////////////// ���� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("corsair3", "corsair3", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "�������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "corsair3"; 
sld.model.animation = "Norman"; 
sld.sex = "man";
sld.id = "corsair3";
sld.FaceId = 868;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "20000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.location = "LeFransua_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 8, 10, 9, 6, 6); 
SetSelfSkill(sld, 90, 80, 90, 90, 90); 
SetShipSkill(sld, 85, 90, 45, 45, 80, 45, 95, 65, 80); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ShipEscape");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "blade_24"); 
sld.equip.blade = "blade_24"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_PRIVATEER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 3000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 2000); 
SetCharacterGoods(sld, GOOD_POWDER, 8500);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 500);
SetCharacterGoods(sld, GOOD_SILVER, 1000);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  


/////////////////// ��� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("CaptainTeague", "CaptainTeague", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "�������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "CaptainTeague"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "CaptainTeague";
sld.FaceId = 865;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "15000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "LeFransua_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 10, 6, 10, 7, 7, 9); 
SetSelfSkill(sld, 70, 55, 55, 60, 80); 
SetShipSkill(sld, 100, 45, 40, 40, 65, 40, 50, 55, 20); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "Grus");
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_22"); 
sld.equip.blade = "blade_22";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_POLACRE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 5500);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_TOBACCO, 200);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 360+MOD_SKILL_ENEMY_RATE*10, 360+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("bocman5", "bocman5", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "bocman5"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "bocman5";
sld.FaceId = 864;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "15000"; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "LeFransua_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 6, 8, 7, 8, 5, 5); 
SetSelfSkill(sld, 20, 40, 20, 50, 35); 
SetShipSkill(sld, 40, 35, 30, 30, 55, 45, 80, 80, 70); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "Grus");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "BasicBattleState");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "topor_06"); 
sld.equip.blade = "topor_06"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SCHOONER_W, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 550); // ������ ����� � ������� ����� ����� ���:)
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 345+MOD_SKILL_ENEMY_RATE*10, 345+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ��� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bonni", "Bonni", "woman", "WomanK2", 10, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "�����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Bonni"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Bonni";
sld.FaceId = 750;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "LeFransua_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "Woman_Captain"; 
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 9, 9, 6, 8, 7, 7); 
SetSelfSkill(sld, 50, 15, 20, 40, 15); 
SetShipSkill(sld, 30, 35, 20, 25, 25, 20, 50, 45, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "BasicBattleState");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_08"); 
sld.equip.blade = "blade_08"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LUGGER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2500);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 50); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �� ������� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ������ ///////////////////

/////////////////// ���� ����� ///////////////////

/////////////////// ���� Ҹ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("will", "will", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "Ҹ����";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "will"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "will";
sld.FaceId = 861;
sld.reputation = "100";
sld.alignment = "GOOD";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = "100000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortRoyal_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 7, 9, 7, 6, 10);
SetSelfSkill(sld, 100, 80, 70, 80, 100);
SetShipSkill(sld, 65, 40, 50, 70, 65, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");  
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); ; 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_18");
sld.equip.blade = "blade_18";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 600);
SetCharacterGoods(sld, GOOD_KNIPPELS, 650);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_FOOD, 800);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 370+MOD_SKILL_ENEMY_RATE*10, 370+MOD_SKILL_ENEMY_RATE*10); 


/////////////////// ������ ���������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Norrington", "Norrington_0", "man", "man", 40, ENGLAND, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "����������";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Norrington_0,Norrington_1,Norrington_2,Norrington_3,Norrington_4,protocusto,Norrington_6,Norrington_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Norrington";
sld.FaceId = 977;
sld.reputation = "100";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = "300000";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortRoyal_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 9, 7, 8, 10, 10, 8);
SetSelfSkill(sld, 60, 100, 70, 70, 90);
SetShipSkill(sld, 100, 100, 70, 75, 95, 70, 70, 80, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2"); 
SetCharacterPerk(sld, "Doctor3");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_29");
sld.equip.blade = "blade_29";
GiveItem2Character(sld, "spyglass5"); 
EquipCharacterbyItem(sld, "spyglass5");
GiveItem2Character(sld, "cirass8"); 
EquipCharacterbyItem(sld, "cirass8"); 
GiveItem2Character(sld, "grape_mushket");  
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100);
AddItems(sld, "grenade", 50); 
AddItems(sld, "powder_pellet", 50);  
GiveItem2Character(sld, "BackPack4");
EquipCharacterbyItem(sld, "BackPack4"); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTLINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 85;
sld.Ship.Crew.Exp.Sailors = 85;
sld.Ship.Crew.Exp.Cannoners = 35;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 1400);
SetCharacterGoods(sld, GOOD_GRAPES, 1400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 1300);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_TEA, 700);
UpgradeShipParameter(sld, "SpeedRate");
UpgradeShipParameter(sld, "TurnRate");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.0, 15.99); 
LAi_SetHP(sld, 430+MOD_SKILL_ENEMY_RATE*10, 430+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("offic_eng", "offic_eng", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "offic_eng"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "offic_eng";
sld.FaceId = 899;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortRoyal_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 9, 9, 3, 7, 7, 3); 
SetSelfSkill(sld, 10, 30, 15, 15, 15); 
SetShipSkill(sld, 40, 25, 15, 15, 25, 20, 25, 20, 20); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_12"); 
sld.equip.blade = "blade_12"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CUTTER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 200); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 80);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� �`����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Grace", "Grace", "woman", "WomanK2", 15, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�`�����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Grace"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Grace";
sld.FaceId = 756;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 18000; 
sld.location = "PortRoyal_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit9";
sld.greeting = "Woman_Captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 7, 9, 7, 9, 9, 8); 
SetSelfSkill(sld, 15, 20, 40, 20, 30); 
SetShipSkill(sld, 35, 20, 40, 30, 45, 20, 55, 45, 55); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_13"); 
sld.equip.blade = "blade_13"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTSCHOONER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 800);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_SHIPSILK, 100);
SetCharacterGoods(sld, GOOD_ROPES, 150);
SetCharacterGoods(sld, GOOD_SANDAL, 20);
SetCharacterGoods(sld, GOOD_OIL, 80); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ����� ///////////////////

/////////////////// �������-��-��� ///////////////////

/////////////////// ������ �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat10", "pirat10", "man", "man_B", 26, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "pirat10"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "pirat10";
sld.FaceId = 862;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "FortOrange_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 7, 10, 9, 7, 7, 9); 
SetSelfSkill(sld, 70, 80, 90, 80, 70); 
SetShipSkill(sld, 90, 50, 95, 95, 100, 70, 95, 85, 70); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_21"); 
sld.equip.blade = "blade_21";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARSHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_FOOD, 2000); 
SetCharacterGoods(sld, GOOD_POWDER, 9000);
SetCharacterGoods(sld, GOOD_WEAPON, 1500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 500); 
SetCharacterGoods(sld, GOOD_PLANKS, 70);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 70);
SetCharacterGoods(sld, GOOD_SILVER, 700);
SetCharacterGoods(sld, GOOD_GOLD, 700);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Lejitos", "Lejitos", "man", "Balthrop", 23, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = ""; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Lejitos"; 
sld.model.animation = "Balthrop"; 
sld.sex = "man";
sld.id = "Lejitos";
sld.FaceId = 858;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 22000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "FortOrange_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 7, 8, 6, 7, 5); 
SetSelfSkill(sld, 40, 80, 40, 70, 45); 
SetShipSkill(sld, 55, 55, 30, 35, 45, 30, 40, 45, 55); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_10"); 
sld.equip.blade = "blade_10"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 150); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 


/////////////////// ���� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Johnsltr1", "Johnsltr1", "man", "man", 19, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Johnsltr1"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Johnsltr1";
sld.FaceId = 854;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "FortOrange_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 8, 7, 5, 7, 4); 
SetSelfSkill(sld, 10, 10, 25, 20, 15); 
SetShipSkill(sld, 20, 20, 35, 40, 45, 20, 25, 25, 65); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");   
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Grus");
SetCharacterPerk(sld, "Medic"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "WindCatcher");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "topor_04"); 
sld.equip.blade = "topor_04"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SCHOONER_W, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_SLAVES, 100); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 235+MOD_SKILL_ENEMY_RATE*10, 235+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ��� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rid", "Rid", "woman", "WomanK2", 18, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "���"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Rid"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Rid";
sld.FaceId = 751;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "FortOrange_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base3";
sld.greeting = "Woman_Captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 9, 5, 9, 6, 9, 8, 5); 
SetSelfSkill(sld, 10, 15, 35, 45, 25); 
SetShipSkill(sld, 45, 25, 50, 55, 45, 20, 25, 15, 65); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");  
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");  
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_13"); 
sld.equip.blade = "blade_13"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_FASTBRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 150); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 295+MOD_SKILL_ENEMY_RATE*10, 295+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������-��-��� ///////////////////

/////////////////// ���� ����� ///////////////////

/////////////////// ������ ��� ����  ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Oliver", "Oliver_0", "man", "man", 18, HOLLAND, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��� ����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Oliver_0,Oliver_1,Oliver_2,Oliver_3,Oliver_4,protocusto,Oliver_6,Oliver_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Oliver";
sld.FaceId = 914;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortAntonio_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 5, 6, 10, 9, 9, 5, 10); 
SetSelfSkill(sld, 55, 70, 60, 40, 65); 
SetShipSkill(sld, 50, 50, 60, 60, 65, 50, 55, 60, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
GiveItem2Character(sld, "mushket3"); 
GiveItem2Character(sld, "pistol_03");
sld.equip.gun = "pistol_03";
GiveItem2Character(sld, "newblade6"); 
sld.equip.blade = "newblade6"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_MERCHANTSHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 45;
sld.Ship.Crew.Exp.Sailors = 15;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 45;
SetCharacterGoods(sld, GOOD_BALLS, 320);
SetCharacterGoods(sld, GOOD_GRAPES, 430);
SetCharacterGoods(sld, GOOD_KNIPPELS, 275);
SetCharacterGoods(sld, GOOD_BOMBS, 170);
SetCharacterGoods(sld, GOOD_FOOD, 450); 
SetCharacterGoods(sld, GOOD_POWDER, 760);
SetCharacterGoods(sld, GOOD_WEAPON, 250);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 370);
SetCharacterGoods(sld, GOOD_RUM, 120); 
SetCharacterGoods(sld, GOOD_HEMP, 2000);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.99); 
UpgradeShipParameter(sld, "MaxCrew");
LAi_SetHP(sld, 255+MOD_SKILL_ENEMY_RATE*10, 255+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ���������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Yoris", "Yoris_0", "man", "man", 20, HOLLAND, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "����������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Yoris_0,Yoris_1,Yoris_2,Yoris_3,Yoris_4,protocusto,Yoris_0,Yoris_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Yoris";
sld.FaceId = 972;
sld.reputation = 50;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 25000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortAntonio_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 9, 7, 8, 10); 
SetSelfSkill(sld, 70, 50, 60, 60, 65); 
SetShipSkill(sld, 60, 40, 65, 40, 65, 80, 40, 40, 60); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "newblade13"); 
sld.equip.blade = "newblade13";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
GiveItem2Character(sld, "mushket2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SMALLEASTINDIAMAN, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 15;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 55;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 940);
SetCharacterGoods(sld, GOOD_GRAPES, 870);
SetCharacterGoods(sld, GOOD_KNIPPELS, 970);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 430); 
SetCharacterGoods(sld, GOOD_POWDER, 770);
SetCharacterGoods(sld, GOOD_WEAPON, 365);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 430);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_PLANKS, 65);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 20);
SetCharacterGoods(sld, GOOD_PAPER, 1000);
LAi_SetSitType(sld); 
UpgradeShipParameter(sld, "Capacity");
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.99); 
LAi_SetHP(sld, 380+MOD_SKILL_ENEMY_RATE*10, 380+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ����� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Yohang", "Yohang", "man", "man", 15, HOLLAND, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Yohang"; 
sld.HeroModel = "Yohang,Yohang_1,Yohang_2,Yohang_3,Yohang_4,protocusto,Yohang,Yohang";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Yohang";
sld.FaceId = 830;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = HOLLAND;
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortAntonio_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.MultiShooter = 2.0;
SetSPECIAL(sld, 7, 8, 8, 7, 8, 9, 9); 
SetSelfSkill(sld, 15, 10, 35, 40, 20); 
SetShipSkill(sld, 30, 50, 20, 25, 25, 30, 20, 20, 15); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
GiveItem2Character(sld, "pistol8");
GiveItem2Character(sld, "mushket3");
sld.equip.gun = "pistol8";
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 100);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 1200);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 100); 
SetCharacterGoods(sld, GOOD_OIL, 150);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.99); 
LAi_SetHP(sld, 260+MOD_SKILL_ENEMY_RATE*10, 260+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ����� ///////////////////

/////////////////// ������ ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ��� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Offic_Eng_16", "Offic_Eng_16", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "�������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Offic_Eng_16"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Offic_Eng_16";
sld.FaceId = 893;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 30000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Bridgetown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 4, 7, 8, 8); 
SetSelfSkill(sld, 55, 95, 30, 70, 45); 
SetShipSkill(sld, 70, 40, 55, 60, 80, 60, 50, 50, 45); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_30");
sld.equip.blade = "blade_30";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 3000); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_SLAVES, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 350);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld);
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.99); 
LAi_SetHP(sld, 340+MOD_SKILL_ENEMY_RATE*10, 340+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jeremy_Tripper", "Jeremy_Tripper", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Jeremy_Tripper"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Jeremy_Tripper";
sld.FaceId = 892;
sld.reputation = 10;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Bridgetown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 10, 10, 8, 8, 9, 4); 
SetSelfSkill(sld, 45, 10, 10, 20, 70); 
SetShipSkill(sld, 35, 10, 20, 25, 50, 45, 20, 35, 20); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_03");
sld.equip.blade = "blade_03";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARBRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 150);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.99); 
LAi_SetHP(sld, 240+MOD_SKILL_ENEMY_RATE*10, 240+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("fra_lut_18", "fra_lut_18", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�����"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "fra_lut_18"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "fra_lut_18";
sld.FaceId = 896;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 27000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Bridgetown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 10, 7, 7, 10, 8, 8); 
SetSelfSkill(sld, 55, 25, 20, 40, 55); 
SetShipSkill(sld, 70, 30, 50, 55, 65, 30, 40, 100, 35); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2"); 
SetCharacterPerk(sld, "Doctor3");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_27");
sld.equip.blade = "blade_27";
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
GiveItem2Character(sld, "spyglass5"); 
EquipCharacterbyItem(sld, "spyglass5");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_HEAVYCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 45;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 550);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 300);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 425+MOD_SKILL_ENEMY_RATE*10, 425+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("BeatriceZ", "BeatriceZ", "woman", "Angellica", 11, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "BeatriceZ"; 
sld.model.animation = "Angellica"; 
sld.sex = "woman";
sld.id = "BeatriceZ";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.FaceId = 759;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 15000; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Bridgetown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base1";
sld.greeting = "Woman_Captain"; 
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 9, 9, 9, 7, 6, 7, 7); 
SetSelfSkill(sld, 20, 20, 20, 20, 30); 
SetShipSkill(sld, 20, 25, 15, 25, 25, 30, 30, 25, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicBattleState"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06";
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_YACHT, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 2500);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 70); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 240+MOD_SKILL_ENEMY_RATE*10, 240+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ��������� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ����-������� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ������ ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("47_Norrington_Pirate", "47_Norrington_Pirate", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "47_Norrington_Pirate"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "47_Norrington_Pirate";
sld.FaceId = 869;
sld.reputation = 55;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Pirates_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 7, 10, 8, 8, 7, 8); 
SetSelfSkill(sld, 20, 15, 20, 15, 30); 
SetShipSkill(sld, 20, 10, 20, 30, 30, 20, 25, 25, 30); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_13"); 
sld.equip.blade = "blade_13"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CHALOUPE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 300);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 210+MOD_SKILL_ENEMY_RATE*10, 210+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ��� �� ��� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sor", "Sor", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "�� ���"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Sor"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Offic_fra";
sld.FaceId = 910;
sld.reputation = 95;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Pirates_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 3, 3, 3, 3); 
SetSelfSkill(sld, 30, 15, 20, 20, 35); 
SetShipSkill(sld, 20, 30, 20, 25, 30, 30, 30, 30, 20); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_09"); 
sld.equip.blade = "blade_09"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SNAUW, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 1200);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 80);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 225+MOD_SKILL_ENEMY_RATE*10, 225+MOD_SKILL_ENEMY_RATE*10);  


/////////////////// ��� �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Shkiper", "Shkiper", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "��������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Shkiper"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Shkiper";
sld.FaceId = 866;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Pirates_tavern"; 
sld.location.group = "sit";
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 10, 9, 4, 7, 8, 3); 
SetSelfSkill(sld, 35, 45, 40, 55, 90); 
SetShipSkill(sld, 40, 55, 40, 45, 65, 40, 60, 50, 50); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_23"); 
sld.equip.blade = "blade_23"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEXEBEC, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 600);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 350);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 350);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_MAHOGANY, 300);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Anamaria", "Anamaria", "woman", "YokoDias", 23, PIRATE, -1, false, "quest"));
sld.name = "��������";
sld.lastname = ""; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel =  "Anamaria,Anamaria_1,Anamaria_2,Anamaria_3,Anamaria_4,protocusto,Anamaria,Anamaria"; 
sld.model.animation = "YokoDias"; 
sld.sex = "woman";
sld.id = "Anamaria";
sld.FaceId = 753;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Pirates_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "Woman_Captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 8, 7, 5, 7, 9, 9); 
SetSelfSkill(sld, 30, 50, 40, 30, 25); 
SetShipSkill(sld, 40, 20, 40, 45, 45, 40, 30, 30, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Doctor1");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_05"); 
sld.equip.blade = "blade_05"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLEBRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 6500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 150); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 23.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������� ///////////////////

/////////////////// ����-������� ///////////////////

/////////////////// ���-������ ///////////////////

/////////////////// ����������� ///////////////////

/////////////////// ������ ��� ��� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Offic_Hol_16", "Offic_Hol_16", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��� ���"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "Offic_Hol_16"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Offic_Hol_16";
sld.FaceId = 894;
sld.reputation = 90;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 16000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Marigo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 3, 3, 8, 3); 
SetSelfSkill(sld, 20, 15, 25, 15, 35); 
SetShipSkill(sld, 30, 20, 50, 50, 35, 20, 30, 35, 55); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "Gunman");
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06"; 
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_GUNBOAT, true, sld);  
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS8;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 78;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 65;
SetCharacterGoods(sld, GOOD_BALLS, 200);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_FOOD, 200); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 100);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 100);
SetCharacterGoods(sld, GOOD_RUM, 10);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10);  


/////////////////// ����� ����������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Buccaneer1", "Buccaneer1", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Buccaneer1"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Buccaneer1";
sld.FaceId = 891;
sld.reputation = 32;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Marigo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 8, 8, 9, 5, 10, 10); 
SetSelfSkill(sld, 50, 20, 10, 30, 20); 
SetShipSkill(sld, 60, 50, 30, 30, 30, 65, 20, 25, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "BasicBattleState");  
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_09"); 
sld.equip.blade = "blade_09"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_TRADESLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 200);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_FOOD, 250); 
SetCharacterGoods(sld, GOOD_POWDER, 1000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 150);
SetCharacterGoods(sld, GOOD_RUM, 35);
SetCharacterGoods(sld, GOOD_SALT, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 240+MOD_SKILL_ENEMY_RATE*10, 240+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// �� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Steys", "Steys", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "��"; 
sld.lastname = "�����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Hero1,Hero1_Cirass,Hero1_Cirass1,Hero1_Cirass2,Hero1_Cirass3,protocusto,Hero8,Hero1";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Steys";
sld.FaceId = 798;
sld.reputation = 45; 
sld.alignment = "bad"; 
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = "25000";
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Marigo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 5, 9, 5, 10, 6, 4); 
SetSelfSkill(sld, 15, 20, 65, 70, 35); 
SetShipSkill(sld, 70, 55, 60, 75, 45, 45, 35, 55, 35); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicCommerce"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "topor_03");
sld.equip.blade = "topor_03";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "mushket1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_TRADEFLEUT, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 900); 
SetCharacterGoods(sld, GOOD_GRAPES, 550); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 400); 
SetCharacterGoods(sld, GOOD_BOMBS, 600); 
SetCharacterGoods(sld, GOOD_FOOD, 900); 
SetCharacterGoods(sld, GOOD_POWDER, 2500); 
SetCharacterGoods(sld, GOOD_WEAPON, 350); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_SUGAR, 500);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 320+MOD_SKILL_ENEMY_RATE*10, 320+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����������� ///////////////////

/////////////////// ������� ������� ///////////////////

/////////////////// ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bobby", "Bobby", "man", "man_B", 1, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = ""; 
sld.rank = 1; 
sld.model = "Bobby"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Bobby";
sld.FaceId = 915;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 1; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Fishing_Settlement_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "Reebok_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 3, 3, 3, 3, 3, 3, 3); 
SetSelfSkill(sld, 1, 1, 1, 1, 1); 
SetShipSkill(sld, 1, 1, 1, 1, 1, 1, 1, 1, 1); 
SetCharacterPerk(sld, "Energaiser"); 
GiveItem2Character(sld, "slave_01"); 
sld.equip.blade = "slave_01"; 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ �����"; 
sld.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, sld); 
sld.Ship.Stopped = true;
sld.Ship.Mode = "trade";
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 10;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_FOOD, 100);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 50);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 300+MOD_SKILL_ENEMY_RATE*10, 300+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ��� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pip", "Pip", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = ""; 
sld.rank = 2; 
sld.model = "Pip"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Pip";
sld.FaceId = 916;
sld.reputation = 30;
sld.alignment = "bad";
sld.SuperShooter  = true;
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 100;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Fishing_Settlement_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "Reebok_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 4, 4, 4, 4, 4, 4, 4); 
SetSelfSkill(sld, 2, 2, 2, 2, 2); 
SetShipSkill(sld, 2, 2, 2, 2, 2, 2, 2, 2, 2); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "Grus"); 
GiveItem2Character(sld, "slave_02"); 
sld.equip.blade = "slave_02"; 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Mode = "trade";
sld.Ship.Name = "�������� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WAR_TARTANE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 100); 
SetCharacterGoods(sld, GOOD_GRAPES, 80); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 60); 
SetCharacterGoods(sld, GOOD_BOMBS, 40); 
SetCharacterGoods(sld, GOOD_FOOD, 350); 
SetCharacterGoods(sld, GOOD_POWDER, 300); 
SetCharacterGoods(sld, GOOD_WEAPON, 60); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 50); 
SetCharacterGoods(sld, GOOD_RUM, 20); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 140+MOD_SKILL_ENEMY_RATE*10, 140+MOD_SKILL_ENEMY_RATE*10);  


/////////////////// ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("brodyaga", "brodyaga", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = ""; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "brodyaga"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "brodyaga";
sld.FaceId = 917;
sld.reputation = 50;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 1; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Fishing_Settlement_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit1";
sld.greeting = "Reebok_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 1, 1, 100, 1, 1); 
SetShipSkill(sld, 1, 1, 1, 1, 1, 1, 1, 1, 100); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
GiveItem2Character(sld, "unarmed"); 
sld.equip.blade = "unarmed"; 
TakeNItems(sld, "icollection", 2);
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Mode = "trade";
sld.Ship.Type = GenerateShipExt(SHIP_PLOT, true, sld); 
sld.Ship.Stopped = true;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCharacterGoods(sld, GOOD_BALLS, 20); 
SetCharacterGoods(sld, GOOD_GRAPES, 20); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 20); 
SetCharacterGoods(sld, GOOD_BOMBS, 20); 
SetCharacterGoods(sld, GOOD_FOOD, 50); 
SetCharacterGoods(sld, GOOD_POWDER, 100); 
SetCharacterGoods(sld, GOOD_WEAPON, 20); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 20); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ������� ///////////////////

/////////////////// ���-������ ///////////////////

/////////////////// ������� ///////////////////

/////////////////// ����-����� ///////////////////

//////////////// ��������� ������/////////////////

sld = GetCharacter(NPC_GenerateCharacter("fawn", "fawn", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "���������";
sld.lastname = "������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "fawn"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "fawn";
sld.FaceId = 876;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 18000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SentJons_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 9, 9, 7, 8, 9, 7); 
SetSelfSkill(sld, 20, 20, 50, 35, 20); 
SetShipSkill(sld, 30, 50, 30, 25, 50, 30, 35, 30, 30); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "WindCatcher");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_14"); 
sld.equip.blade = "blade_14"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BARKENTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 400);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_SUGAR, 600);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

//////////////// ����� ����������� /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Alex_blade", "Alex_blade", "man", "man", 21, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�����������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Alex_blade,Alex_blade_1,Alex_blade_2,Alex_blade_3,Alex_blade_4,protocusto,Alex_blade,Alex_blade";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Alex_blade";
sld.FaceId = 801;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 18000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SentJons_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 10, 6, 7, 8, 8); 
SetSelfSkill(sld, 30, 70, 30, 80, 60); 
SetShipSkill(sld, 35, 30, 40, 45, 50, 30, 65, 60, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_10"); 
sld.equip.blade = "blade_10"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "mushket1");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FASTSCHOONER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 400);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  

//////////////// ������� ���������� /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Navy_Off", "Navy_Off", "man", "man_B", 28, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "����������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Navy_Off"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Navy_Off";
sld.FaceId = 948;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SentJons_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 4, 9, 9, 7, 10, 6, 10); 
SetSelfSkill(sld, 100, 10, 10, 80, 70); 
SetShipSkill(sld, 75, 10, 20, 20, 100, 45, 20, 35, 20); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_25");
sld.equip.blade = "blade_25";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_ENGFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_TEA, 500);
UpgradeShipParameter(sld, "SpeedRate");
UpgradeShipParameter(sld, "TurnRate");
UpgradeShipParameter(sld, "Capacity");
UpgradeShipParameter(sld, "WindAgainstSpeed");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

//////////////// ����� ������� /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Farell", "Farell", "woman", "WomanK2", 28, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Farell"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Farell";
sld.FaceId = 755;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SentJons_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front3";
sld.greeting = "Woman_Captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 9, 7, 7, 9, 9, 5); 
SetSelfSkill(sld, 40, 70, 80, 90, 55); 
SetShipSkill(sld, 75, 45, 60, 65, 80, 45, 55, 60, 60); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_21"); 
sld.equip.blade = "blade_21"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARMEDCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_WINE, 200);
SetCharacterGoods(sld, GOOD_ALE, 200);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_SILK, 700);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ///////////////////

/////////////////// ����-����� ///////////////////

/////////////////// ������� ///////////////////

/////////////////// ���������� ///////////////////

/////////////////// ����� ��������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat5", "pirat5", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "���������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "pirat5"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "pirat5";
sld.FaceId = 888;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Villemstad_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 6, 7, 9, 6, 9, 7, 9); 
SetSelfSkill(sld, 40, 20, 20, 25, 30); 
SetShipSkill(sld, 30, 45, 25, 30, 45, 20, 30, 30, 10); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_18"); 
sld.equip.blade = "blade_18"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BARKENTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 30;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 100);
SetCharacterGoods(sld, GOOD_KNIPPELS, 100);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_FOOD, 300); 
SetCharacterGoods(sld, GOOD_POWDER, 1000);
SetCharacterGoods(sld, GOOD_WEAPON, 250);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 120);
SetCharacterGoods(sld, GOOD_PAPRIKA , 750);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ��� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1", "Corsair1", "man", "man_B", 16, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "��� �����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Corsair1"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Corsair1";
sld.FaceId = 912;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Villemstad_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 8, 5, 8, 9, 4); 
SetSelfSkill(sld, 15, 45, 20, 25, 55); 
SetShipSkill(sld, 35, 25, 30, 25, 45, 25, 40, 50, 50); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "newblade3"); 
sld.equip.blade = "newblade3"; 
LAi_SetCharacterUseBullet(sld, "grapeshot");
TakeNItems(sld, "grapeshot", 50);
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SHNYAVA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 1100);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 120);
SetCharacterGoods(sld, GOOD_COPRA, 550);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("captain", "PitHeyn", "man", "man", 40, HOLLAND, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "����";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "PitHeyn,PitHeyn_1,PitHeyn_2,PitHeyn_3,PitHeyn_4,protocusto,PitHeyn_8,PitHeyn_6";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "PitHeyn";
sld.FaceId = 911;
sld.reputation = "100";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = "200000";
sld.location = "Villemstad_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 9, 9, 9, 9, 7, 10, 4);
SetSelfSkill(sld, 85, 95, 95, 80, 95);
SetShipSkill(sld, 95, 95, 95, 95, 100, 95, 100, 95, 95);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_19"); 
sld.equip.blade = "blade_19"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
GiveItem2Character(sld, "mushket2");
GiveItem2Character(sld, "BackPack4");
EquipCharacterbyItem(sld, "BackPack4"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 15);
sld.Abordage.Enable = true;
sld.Ship.Name = "����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLELINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_POWDER, 5500);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_FOOD, 2500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 4000);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_EBONY, 650);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����-�������� ���� ///////////////////

/////////////////// ��� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("SaoFeng", "SaoFeng", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "���";
sld.lastname = "����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "SaoFeng"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "SaoFeng";
sld.FaceId = 863;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = HOLLAND
sld.money = 25000; 
sld.location = "Villemstad_houseS3"; 
sld.location.group = "goto"; 
sld.location.locator = "goto3";
sld.greeting = "China_Captain"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Other_PGG.c";
SetSPECIAL(sld, 7, 7, 9, 8, 7, 9, 7); 
SetSelfSkill(sld, 60, 75, 50, 40, 55); 
SetShipSkill(sld, 60, 70, 55, 55, 65, 35, 30, 30, 60); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_28"); 
sld.equip.blade = "blade_28"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LUGGERQUEST, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 1200);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 700);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_SUGAR, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetCitizenType(sld);
LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 6.00, 20.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����-�������� ���� ///////////////////

/////////////////// ���������� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ������� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("BigPirate", "BigPirate", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�����"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "BigPirate"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "BigPirate";
sld.FaceId = 828;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Vestpunt_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit6";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 10, 9, 7, 7, 7, 7); 
SetSelfSkill(sld, 20, 10, 5, 10, 25); 
SetShipSkill(sld, 15, 15, 20, 25, 25, 20, 15, 15, 15); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_15"); 
sld.equip.blade = "blade_15"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BOTIK, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 100);
SetCharacterGoods(sld, GOOD_GRAPES, 100);
SetCharacterGoods(sld, GOOD_KNIPPELS, 100);
SetCharacterGoods(sld, GOOD_BOMBS, 100);
SetCharacterGoods(sld, GOOD_FOOD, 150); 
SetCharacterGoods(sld, GOOD_POWDER, 750);
SetCharacterGoods(sld, GOOD_WEAPON, 120);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 50);
SetCharacterGoods(sld, GOOD_RUM, 15); 
SetCharacterGoods(sld, GOOD_SILVER, 100); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 240+MOD_SKILL_ENEMY_RATE*10, 240+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Chard", "Chard", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "����"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Chard,Chard_1,Chard_2,Chard_3,Chard_4,protocusto,Chard,Chard";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Chard";
sld.FaceId = 829;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Vestpunt_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit6";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 9, 3, 3, 9, 3); 
SetSelfSkill(sld, 40, 40, 65, 30, 15); 
SetShipSkill(sld, 10, 25, 50, 55, 45, 30, 25, 25, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "mushket3");
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 350);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 250);
SetCharacterGoods(sld, GOOD_RUM, 200); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 270+MOD_SKILL_ENEMY_RATE*10, 270+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ��������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "Isterling", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "���������";
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Isterling,Isterling_1,Isterling_2,Isterling_3,Isterling_4,protocusto,Isterling,Isterling";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Isterling";
sld.FaceId = 831;
sld.reputation = "97";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "300000";
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Vestpunt_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit6";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 7, 9, 7, 6, 10);
SetSelfSkill(sld, 50, 50, 50, 60, 100);
SetShipSkill(sld, 65, 40, 50, 70, 80, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");  
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); ; 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol1");
GiveItem2Character(sld, "mushket5");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_18");
sld.equip.blade = "blade_18";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARMEDCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1600);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1650);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 7500);
SetCharacterGoods(sld, GOOD_WEAPON, 640);
SetCharacterGoods(sld, GOOD_FOOD, 2000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// �������� ///////////////////

/////////////////// ������� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ���-���///////////////////

/////////////// ���-��� ������ //////////////

sld = GetCharacter(NPC_GenerateCharacter("granie", "granie", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "���-���";
sld.lastname = "������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "granie"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "granie";
sld.FaceId = 841;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "BasTer_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 7, 9, 6, 8, 7, 7); 
SetSelfSkill(sld, 30, 70, 25, 50, 60); 
SetShipSkill(sld, 40, 55, 80, 80, 80, 45, 75, 65, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_19"); 
sld.equip.blade = "blade_19"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_PATROLFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 365+MOD_SKILL_ENEMY_RATE*10, 365+MOD_SKILL_ENEMY_RATE*10);  


/////////////// ���� ������ //////////////

sld = GetCharacter(NPC_GenerateCharacter("Chard3c", "Chard3c", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "����"; 
sld.lastname = "������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Chard3c"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Chard3c";
sld.FaceId = 847;
sld.reputation = 10;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "BasTer_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 8, 4, 6, 7, 5); 
SetSelfSkill(sld, 15, 40, 25, 25, 20); 
SetShipSkill(sld, 40, 50, 50, 55, 65, 30, 25, 70, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_10"); 
sld.equip.blade = "blade_10"; 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
sld.Abordage.Enable = true;
sld.Ship.Name = "�������";
sld.Ship.Type = GenerateShipExt(SHIP_GALEON_L, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 70);
SetCharacterGoods(sld, GOOD_TOBACCO, 250); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

/////////////// ����� ������ //////////////

sld = GetCharacter(NPC_GenerateCharacter("Francois_L'Ollenais", "Francois_L'Ollenais", "man", "man_B", 22, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Francois_L'Ollenais"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Francois_L'Ollenais";
sld.FaceId = 853;
sld.reputation = 75;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "BasTer_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 10, 9, 3, 8, 7, 3); 
SetSelfSkill(sld, 55, 40, 70, 75, 45); 
SetShipSkill(sld, 75, 40, 40, 45, 65, 55, 65, 45, 75); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_13"); 
sld.equip.blade = "blade_13"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FRENCHCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_CHOCOLATE, 500); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ��� ///////////////////

/////////////////// ��������� ������� ///////////////////

// �� ������� ���������� � ���-���� � ��� ������� ��������:)

sld = GetCharacter(NPC_GenerateCharacter("alexander", "alexander", "man", "Moscovit", 20, PIRATE, -1, false, "quest"));
sld.name = "���������";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "alexander"; 
sld.model.animation = "Moscovit"; 
sld.sex = "man";
sld.id = "alexander";
sld.FaceId = 857;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.nation = PIRATE // RUSSIAN ������! :)
sld.money = 30000; 
sld.location = "BasTer_houseSp1"; 
sld.location.group = "sit"; 
sld.location.locator = "sit2";
sld.greeting = "Rus_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.standUp = true; //�������� � �������� �� �����
SetSPECIAL(sld, 10, 5, 10, 6, 9, 7, 7); 
SetSelfSkill(sld, 1, 10, 100, 50, 45); 
SetShipSkill(sld, 35, 70, 30, 30, 45, 50, 30, 35, 40); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "topor_04"); 
sld.equip.blade = "topor_04"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ ��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_TRADEBRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 600);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 2500);
SetCharacterGoods(sld, GOOD_WEAPON, 350);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_ALE, 300);
SetCharacterGoods(sld, GOOD_WINE, 300); // ������� �� ����� �������:)
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.99);  
LAi_SetHP(sld, 650+MOD_SKILL_ENEMY_RATE*10, 650+MOD_SKILL_ENEMY_RATE*10);

/////////////////// ������ �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Andrey", "Andrey_0", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Andrey_0,Andrey_1,Andrey_2,Andrey_3,Andrey_4,protocusto,Andrey_0,Andrey_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Andrey";
sld.FaceId = 968;
sld.reputation = 30;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE 
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.standUp = true; //�������� � �������� �� �����
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "BasTer_houseSp1"; 
sld.location.group = "sit"; 
sld.location.locator = "sit2";
sld.greeting = "Rus_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
SetSPECIAL(sld, 6, 8, 7, 3, 8, 9, 5); 
SetSelfSkill(sld, 55, 60, 20, 75, 20); 
SetShipSkill(sld, 15, 20, 35, 30, 45, 60, 45, 40, 40); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_12"); 
sld.equip.blade = "blade_12"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2");  
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6");
GiveItem2Character(sld, "mushket1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 650);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.99); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������� ///////////////////
sld = GetCharacter(NPC_GenerateCharacter("Kurakin", "Kurakin", "man", "man", 20, FRANCE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Kurakin"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Kurakin";
sld.FaceId = 969;
sld.reputation = 100;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 25000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "BasTer_houseSp1"; 
sld.location.group = "sit"; 
sld.location.locator = "sit2";
sld.greeting = "Rus_Captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
sld.standUp = true; //�������� � �������� �� �����
SetSPECIAL(sld, 9, 5, 9, 7, 10, 6, 8); 
SetSelfSkill(sld, 10, 10, 45, 40, 20); 
SetShipSkill(sld, 35, 25, 20, 25, 45, 30, 50, 60, 30); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunmanProfessional");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "mushket_8"); 
GiveItem2Character(sld, "pistol_03");
sld.equip.gun = "pistol_03";
GiveItem2Character(sld, "newblade12"); 
sld.equip.blade = "newblade12";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���"; 
sld.Ship.Type = GenerateShipExt(SHIP_TRADESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 85;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 800);
SetCharacterGoods(sld, GOOD_GRAPES, 730);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 740);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 760);
SetCharacterGoods(sld, GOOD_WEAPON, 360);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 640);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_SALT, 600);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.99); 
LAi_SetHP(sld, 410+MOD_SKILL_ENEMY_RATE*10, 410+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ��� ///////////////////

/////////////////// ����-��� ///////////////////

/////////////////// ����� �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Emilio1", "Emilio1", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "��������"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "Emilio1"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Emilio1";
sld.FaceId = 840;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SantLous_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 5, 7, 6, 5, 9, 9, 9); 
SetSelfSkill(sld, 70, 5, 5, 20, 35); 
SetShipSkill(sld, 60, 45, 20, 25, 25, 40, 25, 25, 15); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_17"); 
sld.equip.blade = "blade_17"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "mushket1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WAR_TARTANE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 150);
SetCharacterGoods(sld, GOOD_GRAPES, 150);
SetCharacterGoods(sld, GOOD_KNIPPELS, 150);
SetCharacterGoods(sld, GOOD_BOMBS, 150);
SetCharacterGoods(sld, GOOD_FOOD, 100); 
SetCharacterGoods(sld, GOOD_POWDER, 700);
SetCharacterGoods(sld, GOOD_WEAPON, 70);
SetCharacterGoods(sld, GOOD_RUM, 15); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 70);
SetCharacterGoods(sld, GOOD_OIL, 50); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 310+MOD_SKILL_ENEMY_RATE*10, 310+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ��� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pitt_3", "Pitt_3", "man", "man", 18, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "���"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Pitt_3"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Pitt_3";
sld.FaceId = 848;
sld.reputation = 10;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantLous_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 9, 9, 7, 5, 8, 6); 
SetSelfSkill(sld, 40, 50, 30, 60, 15); 
SetShipSkill(sld, 20, 25, 30, 35, 45, 20, 20, 15, 45); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "mushket1"); 
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_12"); 
sld.equip.blade = "blade_12"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARMEDBRIG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 30;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 150);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 250);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 150);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_FRUITS, 230);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 440+MOD_SKILL_ENEMY_RATE*10, 440+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("QuestMan1", "QuestMan1", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "QuestMan1"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "QuestMan1";
sld.FaceId = 852;
sld.reputation = 40;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantLous_Tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front1";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 7, 7, 8, 8, 7, 3); 
SetSelfSkill(sld, 10, 10, 35, 15, 1); 
SetShipSkill(sld, 30, 45, 20, 20, 20, 20, 25, 25, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "BasicBattleState");
GiveItem2Character(sld, "topor_01"); 
sld.equip.blade = "topor_01"; 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������� �������"; 
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1");  
sld.Ship.Type = GenerateShipExt(SHIP_PLOT, true, sld); 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 100);
SetCharacterGoods(sld, GOOD_GRAPES, 100);
SetCharacterGoods(sld, GOOD_KNIPPELS, 100);
SetCharacterGoods(sld, GOOD_BOMBS, 100);
SetCharacterGoods(sld, GOOD_FOOD, 100); 
SetCharacterGoods(sld, GOOD_POWDER, 500);
SetCharacterGoods(sld, GOOD_WEAPON, 50);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 50);
SetCharacterGoods(sld, GOOD_RUM, 10); 
SetCharacterGoods(sld, GOOD_ROPES, 30); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 430+MOD_SKILL_ENEMY_RATE*10, 430+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����-��� ///////////////////

/////////////////// ��������� ///////////////////

/////////////////// ����-��������� ///////////////////

/////////////////// ����������� ///////////////////

/////////////////// ������� �� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("LeKlerk", "LeKlerk", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�� ����"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "LeKlerk"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "LeKlerk";
sld.FaceId = 913;
sld.reputation = 90;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = 20000;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Charles_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 9, 9, 9, 5, 6, 7, 6); 
SetSelfSkill(sld, 40, 50, 70, 70, 55); 
SetShipSkill(sld, 50, 30, 70, 75, 80, 40, 50, 60, 40); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_14"); 
sld.equip.blade = "blade_14";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "mushket1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_POLACRE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 200); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 370+MOD_SKILL_ENEMY_RATE*10, 370+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Antuan", "Antuan_0", "man", "man", 35, FRANCE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "������";
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.HeroModel = "Antuan_0,Antuan_1,Antuan_2,Antuan_3,Antuan_4,protocusto,Antuan_0,Antuan_8"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Antuan";
sld.FaceId = 967;
sld.reputation = "15";
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = FRANCE
sld.money = "50000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Charles_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
SetSPECIAL(sld, 6, 6, 6, 6, 6, 6, 6);
SetSelfSkill(sld, 60, 30, 35, 40, 60);
SetShipSkill(sld, 65, 30, 15, 15, 65, 20, 15, 15, 80);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "BasicCommerce");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_15");
sld.equip.blade = "blade_15";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
GiveItem2Character(sld, "mushket3");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 3);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FRENCHCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 300);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_SLAVES, 100);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� �� �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "Rabel_Chardon", "man", "man_B", 35, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "�� ��������";
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Rabel_Chardon"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Rabel_Chardon";
sld.FaceId = 895;
sld.reputation = "70";
sld.alignment = "GOOD";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "300000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Charles_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 7, 9, 7, 6, 10);
SetSelfSkill(sld, 50, 50, 50, 60, 100);
SetShipSkill(sld, 65, 40, 50, 70, 45, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");  
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); ; 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_18");
sld.equip.blade = "blade_18";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 250);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_COTTON, 500);
LAi_SetSitType(sld);
UpgradeShipParameter(sld, "Capacity");
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ����������� ///////////////////

/////////////////// ����-��������� ///////////////////

/////////////////// �������� � ������ ///////////////////

/////////////////// ���-���� ///////////////////

/////////////////// ��������� ��������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1_4", "Corsair1_4", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "���������";
sld.lastname = "���������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Corsair1_4"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Corsair1_4";
sld.FaceId = 875;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortSpein_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 10, 9, 4, 9, 9, 9); 
SetSelfSkill(sld, 35, 80, 30, 60, 80); 
SetShipSkill(sld, 15, 80, 65, 60, 65, 30, 40, 50, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_12"); 
sld.equip.blade = "blade_12"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��� �������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CARAVEL, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1200);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 600);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 350);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_MAHOGANY, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 290+MOD_SKILL_ENEMY_RATE*10, 290+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ �� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Arr_0", "Arr_0", "man", "man_B", 18, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�� �������"; 
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Arr_0,Arr_1,Arr_2,Arr_3,Arr_4,protocusto,Arr_8,Arr_6";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Arr_0";
sld.FaceId = 838;
sld.reputation = 90;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortSpein_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 5, 9, 5, 10, 9, 9, 9); 
SetSelfSkill(sld, 80, 60, 40, 40, 70); 
SetShipSkill(sld, 70, 50, 70, 70, 95, 55, 50, 55, 40); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_26"); 
sld.equip.blade = "blade_26"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass8"); 
EquipCharacterbyItem(sld, "cirass8"); 
GiveItem2Character(sld, "mushket6");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARLINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 6000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_GOLD, 500);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 270+MOD_SKILL_ENEMY_RATE*10, 270+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Esteban", "Esteban", "man", "man", 12, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Esteban"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Esteban";
sld.FaceId = 837;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortSpein_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 8, 7, 8, 9, 9); 
SetSelfSkill(sld, 40, 15, 10, 50, 30); 
SetShipSkill(sld, 10, 45, 10, 10, 35, 25, 15, 20, 40); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_09"); 
sld.equip.blade = "blade_09";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BARQUE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS8;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 40;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 400);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 1200);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_COFFEE, 300); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 260+MOD_SKILL_ENEMY_RATE*10, 260+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������� � ������ ///////////////////

/////////////////// ���-���� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// �������-���� ///////////////////

/////////////////// ���� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Hornblauer", "Hornblauer", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Hornblauer,Hornblauer_1,Hornblauer_2,Hornblauer_3,Hornblauer_4,protocusto,Hornblauer,Hornblauer";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Hornblauer";
sld.FaceId = 420;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 25000; 
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Roseau_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit9";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 9, 7, 8, 9, 6, 8); 
SetSelfSkill(sld, 30, 75, 20, 50, 55); 
SetShipSkill(sld, 75, 80, 40, 45, 65, 70, 45, 45, 65); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_20"); 
sld.equip.blade = "blade_20";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "mushket2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLECORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 900);
SetCharacterGoods(sld, GOOD_GRAPES, 900);
SetCharacterGoods(sld, GOOD_KNIPPELS, 900);
SetCharacterGoods(sld, GOOD_BOMBS, 900);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_PLANKS, 120);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 120);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.99); 
LAi_SetHP(sld, 430+MOD_SKILL_ENEMY_RATE*10, 430+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("killer", "killer", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "killer"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "killer";
sld.FaceId = 870;
sld.reputation = 35;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 20000; 
sld.SuperShooter  = true;
sld.location = "Roseau_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit9";
sld.greeting = "captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 9, 4, 8, 8, 5); 
SetSelfSkill(sld, 30, 15, 10, 20, 25); 
SetShipSkill(sld, 10, 25, 20, 25, 25, 40, 30, 25, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_15"); 
sld.equip.blade = "blade_15";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol")
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LIGHTSLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 700);
SetCharacterGoods(sld, GOOD_KNIPPELS, 700);
SetCharacterGoods(sld, GOOD_BOMBS, 700);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 120);
SetCharacterGoods(sld, GOOD_SHIPSILK, 200);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.99); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������ ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rober", "Rober_Sur_0", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.HeroModel = "Rober_Sur_0,Rober_Sur_1,Rober_Sur_2,Rober_Sur_3,Rober_Sur_4,protocusto,Rober_Sur_6,Rober_Sur_8";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Rober";
sld.FaceId = 964;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = 15000; 
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.location = "Roseau_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit9";
sld.greeting = "captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 8, 6, 7, 8, 8, 6); 
SetSelfSkill(sld, 85, 55, 75, 65, 80); 
SetShipSkill(sld, 80, 65, 70, 70, 80, 65, 60, 85, 65); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol_08");
sld.equip.gun = "pistol_08";
GiveItem2Character(sld, "newblade13"); 
sld.equip.blade = "newblade13";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");    
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "mushket_8"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_CORSAIRFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 900);
SetCharacterGoods(sld, GOOD_GRAPES, 850);
SetCharacterGoods(sld, GOOD_KNIPPELS, 650);
SetCharacterGoods(sld, GOOD_BOMBS, 950);
SetCharacterGoods(sld, GOOD_FOOD, 950); 
SetCharacterGoods(sld, GOOD_POWDER, 1300);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 430);
SetCharacterGoods(sld, GOOD_RUM, 160); 
SetCharacterGoods(sld, GOOD_TEA, 125); 
LAi_SetSitType(sld); 
UpgradeShipParameter(sld, "MaxCrew");
UpgradeShipParameter(sld, "WindAgainstSpeed");
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.99); 
LAi_SetHP(sld, 290+MOD_SKILL_ENEMY_RATE*10, 290+MOD_SKILL_ENEMY_RATE*10);

/////////////////// �������-���� ///////////////////

/////////////////// ������� ������� ///////////////////

///////////////////// �������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Matatopa", "Matatopa", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "��������"; 
sld.lastname = ""; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Matatopa"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Matatopa";
sld.FaceId = 793;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "15000";
sld.location = "Indian_town"; 
sld.location.group = "goto"; 
sld.location.locator = "goto5";
sld.greeting = "Indian_Captain"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Indian_PGG.c";
SetSPECIAL(sld, 7, 9, 4, 6, 4, 10, 7); 
SetSelfSkill(sld, 15, 10, 50, 25, 30); 
SetShipSkill(sld, 20, 10, 45, 45, 25, 15, 20, 20, 55); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");  
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot");
GiveItem2Character(sld, "topor_01");
sld.equip.blade = "topor_01";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass3");
EquipCharacterbyItem(sld, "cirass3"); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������ �������"; 
sld.Ship.Type = GenerateShipExt(SHIP_GALIOT, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS8;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 500); 
SetCharacterGoods(sld, GOOD_GRAPES, 500); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 500); 
SetCharacterGoods(sld, GOOD_BOMBS, 500); 
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3500); 
SetCharacterGoods(sld, GOOD_WEAPON, 500); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500); 
SetCharacterGoods(sld, GOOD_RUM, 50); 
SetCharacterGoods(sld, GOOD_FRUITS, 100);
SetCharacterGoods(sld, GOOD_TOBACCO, 100);
SetCharacterGoods(sld, GOOD_COTTON, 100);
UpgradeShipParameter(sld, "Capacity");
GiveItem2Character(sld, "indian017"); 
GiveItem2Character(sld, "indian020"); 
GiveItem2Character(sld, "indian012");
LAi_SetCitizenType(sld);
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 6.0, 20.59); 
LAi_SetHP(sld, 370+MOD_SKILL_ENEMY_RATE*10, 370+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ������� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ������ ///////////////////

/////////////////// ����� ///////////////////

/////////////////// ������ �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("James2", "James2", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��������"; 
sld.rank = 1+MOD_SKILL_ENEMY_RATE; 
sld.model = "James2"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "James2";
sld.FaceId = 835;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Beliz_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SuperShooter  = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 8, 9, 7, 6, 8, 8, 5); 
SetSelfSkill(sld, 15, 35, 10, 20, 55); 
SetShipSkill(sld, 30, 45, 10, 15, 25, 10, 25, 25, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "WindCatcher");
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "blade_04"); 
sld.equip.blade = "blade_04"; 
GiveItem2Character(sld, "mushket1");
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass5"); 
EquipCharacterbyItem(sld, "cirass5"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_DOGGER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 10;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_BALLS, 100);
SetCharacterGoods(sld, GOOD_GRAPES, 100);
SetCharacterGoods(sld, GOOD_KNIPPELS, 100);
SetCharacterGoods(sld, GOOD_BOMBS, 100);
SetCharacterGoods(sld, GOOD_FOOD, 400); 
SetCharacterGoods(sld, GOOD_POWDER, 500);
SetCharacterGoods(sld, GOOD_WEAPON, 50);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 50);
SetCharacterGoods(sld, GOOD_SLAVES, 200);
SetCharacterGoods(sld, GOOD_RUM, 10); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Dragoon_2", "Dragoon_2", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "�����";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.model = "Dragoon_2"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Dragoon_2";
sld.FaceId = 836;
sld.reputation = "80";
sld.alignment = "GOOD";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = "300000";
sld.location = "Beliz_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 6, 9, 7, 9, 7, 6, 10);
SetSelfSkill(sld, 100, 60, 60, 70, 100);
SetShipSkill(sld, 75, 50, 60, 80, 95, 60, 90, 65, 80);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");  
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); ; 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_25");
sld.equip.blade = "blade_25";
GiveItem2Character(sld, "spyglass5"); 
EquipCharacterbyItem(sld, "spyglass5");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "mushket3");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 7000);
SetCharacterGoods(sld, GOOD_WEAPON, 800);
SetCharacterGoods(sld, GOOD_FOOD, 2200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_SANDAL, 300);
SetCharacterGoods(sld, GOOD_RUM, 300);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Forester", "Forester", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Forester"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Forester";
sld.FaceId = 824;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 20000; 
sld.location = "Beliz_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 7, 7, 8, 7, 9, 5); 
SetSelfSkill(sld, 40, 25, 15, 30, 20); 
SetShipSkill(sld, 10, 55, 20, 25, 60, 25, 30, 30, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "blade_16");
GiveItem2Character(sld, "BackPack2");
EquipCharacterbyItem(sld, "BackPack2");  
sld.equip.blade = "blade_16"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_CORSAIRCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 30;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 700);
SetCharacterGoods(sld, GOOD_KNIPPELS, 700);
SetCharacterGoods(sld, GOOD_BOMBS, 700);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 3500);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 150); 
SetCharacterGoods(sld, GOOD_SUGAR, 300);
SetCharacterGoods(sld, GOOD_TOBACCO, 250);
SetCharacterGoods(sld, GOOD_WINE, 100); 
LAi_SetSitType(sld); 
UpgradeShipParameter(sld, "Capacity");
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ���� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("LCroft", "LCroft", "woman", "WomanK2", 16, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "�����"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "LCroft"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "LCroft";
sld.FaceId = 758;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 15000; 
sld.location = "Beliz_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit2";
sld.greeting = "Woman_Captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 8, 7, 9, 7, 9, 9, 8); 
SetSelfSkill(sld, 40, 40, 40, 40, 60); 
SetShipSkill(sld, 70, 35, 30, 35, 65, 30, 25, 25, 85); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_05"); 
sld.equip.blade = "blade_05";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_XebekVML, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_SANDAL, 100);  
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ///////////////////

/////////////////// ����� ///////////////////

/////////////////// �������� ���� ///////////////////

/////////////////// �������� ///////////////////

/////////////////// ��������� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("spa_lut_18", "spa_lut_18", "man", "man_B", 16, PIRATE, -1, false, "quest"));
sld.name = "���������";
sld.lastname = "�������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "spa_lut_18"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "spa_lut_18";
sld.FaceId = 882;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.location = "SantaCatalina_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 9, 9, 8, 8, 9, 7); 
SetSelfSkill(sld, 25, 15, 45, 30, 30); 
SetShipSkill(sld, 30, 20, 30, 35, 45, 40, 45, 35, 55); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "SailsDamageUp");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_07"); 
sld.equip.blade = "blade_07";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARSCHOONER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 1200);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 600);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 320);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 120); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Uof_0", "Uof_0", "man", "man", 21, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Uof_0";
sld.HeroModel = "Uof_0,Uof_1,Uof_2,Uof_3,Uof_4,protocusto,Uof_8,Uof_6";
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Uof_0";
sld.FaceId = 855;
sld.reputation = 90;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 21000; 
sld.location = "SantaCatalina_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.CanTakeMushket = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
SetSPECIAL(sld, 6, 9, 9, 7, 8, 8, 6); 
SetSelfSkill(sld, 25, 15, 15, 15, 10); 
SetShipSkill(sld, 30, 65, 30, 35, 80, 30, 20, 20, 20); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_08"); 
sld.equip.blade = "blade_08";
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass6"); 
EquipCharacterbyItem(sld, "cirass6"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "mushket1");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_EASTINDIAMAN, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 600);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_SUGAR, 2000);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("brtcpt1_18", "brtcpt1_18", "man", "man_B", 32, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "brtcpt1_18"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "brtcpt1_18";
sld.FaceId = 879;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = ENGLAND
sld.money = 22000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SantaCatalina_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 10, 7, 9, 8, 10); 
SetSelfSkill(sld, 70, 20, 10, 70, 25); 
SetShipSkill(sld, 90, 40, 70, 75, 95, 85, 30, 25, 30); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_27"); 
sld.equip.blade = "blade_27";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_LINEFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1200);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 2000); 
SetCharacterGoods(sld, GOOD_POWDER, 6000);
SetCharacterGoods(sld, GOOD_WEAPON, 800);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 800);
SetCharacterGoods(sld, GOOD_RUM, 400);
SetCharacterGoods(sld, GOOD_GOLD, 500);
SetCharacterGoods(sld, GOOD_SILVER, 1000);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld);
LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������� ///////////////////

/////////////////// ������� ������� ///////////////////

///////////////////     ���������   //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Chingachguk", "Chingachguk", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "���������"; 
sld.lastname = "";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Chingachguk"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Chingachguk";
sld.FaceId = 790;
sld.reputation = "100";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "50000";
sld.location = "Miskito_village"; 
sld.location.group = "goto"; 
sld.location.locator = "goto5";
sld.greeting = "Indian_Captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Indian_PGG.c";
SetSPECIAL(sld, 9, 8, 10, 5, 4, 3, 7);
SetSelfSkill(sld, 40, 90, 50, 50, 35);
SetShipSkill(sld, 90, 70, 40, 35, 65, 25, 45, 90, 90);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "HPPlus");  
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "blade_02"); 
sld.equip.blade = "blade_02"; 	
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass2");
EquipCharacterbyItem(sld, "cirass2"); 
GiveItem2Character(sld, "indian018"); 
GiveItem2Character(sld, "indian006"); 
GiveItem2Character(sld, "indian014");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "potion2", 5); 
sld.Abordage.Enable = true;
sld.Ship.Name = "������� ����"; 
sld.Ship.Type = GenerateShipExt(SHIP_PINNACE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 5;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_POWDER, 7500);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 150);
SetCharacterGoods(sld, GOOD_SANDAL, 350);
UpgradeShipParameter(sld, "Capacity");
LAi_SetCitizenType(sld);
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 6.0, 20.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ������� ///////////////////

/////////////////// ������� ���������� ///////////////////

/////////////////// ����� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Magua", "Magua", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Magua"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Magua";
sld.FaceId = 794;
sld.reputation = "20";
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "10000";
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Bravo_village"; 
sld.location.group = "goto"; 
sld.location.locator = "goto5";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Indian_PGG.c";
SetSPECIAL(sld, 10, 5, 10, 9, 8, 10, 7); 
SetSelfSkill(sld, 60, 100, 70, 90, 80);
SetShipSkill(sld, 90, 80, 90, 30, 65, 10, 80, 60, 60);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce");
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "blade_12");
sld.equip.blade = "blade_12";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");  
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_FASTCORVETTE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 10;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_FOOD, 3500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_SLAVES, 1000);
LAi_SetCitizenType(sld);
GiveItem2Character(sld, "indian012");
GiveItem2Character(sld, "indian018");
GiveItem2Character(sld, "indian021"); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 6.0, 20.59); 
LAi_SetHP(sld, 420+MOD_SKILL_ENEMY_RATE*10, 420+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ���������� ///////////////////

/////////////////// �������� ���� ///////////////////

/////////////////// ���� ///////////////////

/////////////////// ����� ������� ///////////////////

/////////////////// ������ ��� ����� ///////////////////

/////////////////// ������� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gevara", "Gevara", "man", "Balthrop", 12, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Gevara"; 
sld.model.animation = "Balthrop";
sld.sex = "man";
sld.id = "Gevara";
sld.FaceId = 859;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Minentown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 10, 9, 5, 6, 7, 8); 
SetSelfSkill(sld, 25, 15, 65, 35, 15); 
SetShipSkill(sld, 70, 25, 20, 20, 45, 70, 45, 50, 25); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "BasicCommerce");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_14"); 
sld.equip.blade = "blade_14"; 
GiveItem2Character(sld, "cirass4"); 
EquipCharacterbyItem(sld, "cirass4");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_PATROLSCHOONER, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_GOLD, 100);
SetCharacterGoods(sld, GOOD_SILVER, 200); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ��� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("black_reitar", "black_reitar", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "��� �������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "black_reitar"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "black_reitar";
sld.FaceId = 842;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Minentown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 9, 8, 4, 10, 8, 3); 
SetSelfSkill(sld, 60, 60, 80, 75, 45); 
SetShipSkill(sld, 50, 65, 75, 70, 95, 60, 75, 80, 65); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "newblade9"); 
sld.equip.blade = "newblade9"; 
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2");
GiveItem2Character(sld, "spyglass2"); 
GiveItem2Character(sld, "BackPack3");
EquipCharacterbyItem(sld, "BackPack3"); 
EquipCharacterbyItem(sld, "spyglass2"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BATTLESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 500);
SetCharacterGoods(sld, GOOD_GOLD, 200);
SetCharacterGoods(sld, GOOD_SILVER, 500); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Hulio", "Hulio", "man", "man_B_ab", 25, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Hulio"; 
sld.model.animation = "man_B_ab"; 
sld.sex = "man";
sld.id = "Hulio";
sld.FaceId = 918;
sld.reputation = 10;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Minentown_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base4";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 8, 9, 7, 6, 5, 7);
SetSelfSkill(sld, 75, 20, 25, 60, 20);
SetShipSkill(sld, 45, 55, 30, 25, 85, 35, 50, 60, 40);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "SailingProfessional");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_15"); 
sld.equip.blade = "blade_15"; 
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_HEAVYGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 3500);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
SetCharacterGoods(sld, GOOD_GOLD, 400);
SetCharacterGoods(sld, GOOD_SILVER, 800); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ��� ����� ///////////////////

///////////////////// ������ ///////////////////////////

////////////////// �������� ���� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Alfons", "Alfons", "man", "man_B", 27, PIRATE, -1, false, "quest"));
sld.name = "��������"; 
sld.lastname = "����";
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Alfons"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Alfons";
sld.FaceId = 919;
sld.reputation = "80";
sld.alignment = "GOOD";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "100000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Cumana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 9, 7, 9, 7, 6, 10);
SetSelfSkill(sld, 70, 50, 55, 60, 100);
SetShipSkill(sld, 65, 40, 50, 50, 65, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce");  
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); ; 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_17");
sld.equip.blade = "blade_17";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_PINNACE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 60;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2500);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 2500);
SetCharacterGoods(sld, GOOD_POWDER, 7500);
SetCharacterGoods(sld, GOOD_WEAPON, 800);
SetCharacterGoods(sld, GOOD_FOOD, 2000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 290);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

////////////////// ������ �� ����� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Veneto", "Veneto", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "������"; 
sld.lastname = "�� �����";
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Veneto"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Veneto";
sld.FaceId = 920;
sld.reputation = "35";
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "50000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Cumana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 3, 5, 3, 8, 8, 9);
SetSelfSkill(sld, 30, 60, 15, 50, 40);
SetShipSkill(sld, 45, 60, 30, 45, 45, 40, 30, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit");  
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");  
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_11");
sld.equip.blade = "blade_11";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");  
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 3);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SHNYAVA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 200);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 200);
SetCharacterGoods(sld, GOOD_POWDER, 1000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_FOOD, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_CHOCOLATE, 1000);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

////////////////// ����� ����� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Portugall", "Portugall", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�����"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Portugall"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Portugall";
sld.FaceId = 921;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Cumana_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 8, 5, 3, 3, 10); 
SetSelfSkill(sld, 20, 15, 40, 10, 30); 
SetShipSkill(sld, 35, 25, 15, 25, 30, 20, 40, 35, 10); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_13");
sld.equip.blade = "blade_13";
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2");   
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���-�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_REDONDA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 400);
SetCharacterGoods(sld, GOOD_GRAPES, 400);
SetCharacterGoods(sld, GOOD_KNIPPELS, 400);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 200);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 100); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 15.00, 23.59); 
LAi_SetHP(sld, 325+MOD_SKILL_ENEMY_RATE*10, 325+MOD_SKILL_ENEMY_RATE*10);  

///////////////////// ������ ///////////////////////////

///////////////////// ������� ///////////////////////////

/////////////////// ���� �� �������� ///////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rikaldo", "Rikaldo", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "����";
sld.lastname = "�� ��������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Rikaldo"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Rikaldo";
sld.FaceId = 922;
sld.reputation = 80;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 26000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Caracas_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 9, 9, 7, 8, 6, 10); 
SetSelfSkill(sld, 30, 70, 30, 55, 90); 
SetShipSkill(sld, 70, 35, 45, 50, 70, 40, 80, 35, 75); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Medic"); 
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");  
GiveItem2Character(sld, "blade_12"); 
sld.equip.blade = "blade_12"; 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SCHOONER_W, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 1200);
SetCharacterGoods(sld, GOOD_GRAPES, 700);
SetCharacterGoods(sld, GOOD_KNIPPELS, 700);
SetCharacterGoods(sld, GOOD_BOMBS, 1200);
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 4000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200); 
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ �������� ///////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gasparo", "Gasparo", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Gasparo"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Gasparo";
sld.FaceId = 923;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.CoolBrander = true;
sld.location = "Caracas_tavern";  
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 9, 10, 8, 8, 10, 7); 
SetSelfSkill(sld, 50, 50, 50, 50, 40); 
SetShipSkill(sld, 40, 25, 70, 70, 90, 40, 75, 80, 35); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "EnergyPlus"); 
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Grus");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "BasicBattleState");
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_21"); 
sld.equip.blade = "blade_21"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");  
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����-�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_CARAVEL, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_PAPRIKA, 1500);
UpgradeShipParameter(sld, "Capacity"); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 300+MOD_SKILL_ENEMY_RATE*10, 300+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� �������� /////////////////////////// 

sld = GetCharacter(NPC_GenerateCharacter("Italian", "Italian", "man", "man_B", 18, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "��������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Italian"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Italian";
sld.FaceId = 924;
sld.reputation = 40;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Caracas_tavern";  
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 6, 10, 7, 5, 7, 10, 8);
SetSelfSkill(sld, 60, 40, 25, 35, 30);
SetShipSkill(sld, 45, 60, 55, 60, 80, 65, 55, 45, 50); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
GiveItem2Character(sld, "pistol2");
sld.equip.gun = "pistol2";
GiveItem2Character(sld, "blade_16"); 
sld.equip.blade = "blade_16"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "����"; 
sld.Ship.Type = GenerateShipExt(SHIP_ARABELLASHIPG, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 9000);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_COTTON, 2000);
UpgradeShipParameter(sld, "Capacity"); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 290+MOD_SKILL_ENEMY_RATE*10, 290+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� ������ /////////////////////////// 

sld = GetCharacter(NPC_GenerateCharacter("Daniell1", "Daniell1", "woman", "WomanK2", 20, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Daniell1"; 
sld.model.animation = "WomanK2"; 
sld.sex = "woman";
sld.id = "Daniell1";
sld.FaceId = 752;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 18000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Caracas_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "Woman_Captain"; 
sld.Dialog.Filename = "Population\Baba_PGG.c";
SetSPECIAL(sld, 9, 7, 7, 7, 9, 6, 5); 
SetSelfSkill(sld, 15, 40, 15, 40, 35); 
SetShipSkill(sld, 50, 25, 20, 25, 45, 50, 40, 35, 65); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_11"); 
sld.equip.blade = "blade_11"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���� �����"; 
sld.Ship.Type = GenerateShipExt(SHIP_POLACCA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 70;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 800);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 800);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 3800);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 100); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

///////////////////// ������� ///////////////////////////

///////////////////// ��������� ///////////////////////////

/////////////////// �������� ������ ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Venetian", "Venetian", "man", "man_B", 13, PIRATE, -1, false, "quest"));
sld.name = "��������";
sld.lastname = "������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Venetian"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Venetian";
sld.FaceId = 925;
sld.reputation = 60;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Maracaibo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 3, 7, 7, 5, 9, 9, 10); 
SetSelfSkill(sld, 10, 15, 35, 10, 15); 
SetShipSkill(sld, 35, 15, 20, 10, 30, 40, 5, 20, 30); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_06"); 
sld.equip.blade = "blade_06"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���-�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BARQUE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 10;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 350); 
SetCharacterGoods(sld, GOOD_POWDER, 1000);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 50);
SetCharacterGoods(sld, GOOD_ROPES, 350);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 225+MOD_SKILL_ENEMY_RATE*10, 225+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� �� ���� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Goish", "Goish", "man", "man_B", 7, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�� ����"; 
sld.rank = 7; 
sld.model = "Goish"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Goish";
sld.FaceId = 926;
sld.reputation = 50;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Maracaibo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 7, 10, 10, 7, 8, 7); 
SetSelfSkill(sld, 15, 5, 10, 15, 10); 
SetShipSkill(sld, 15, 20, 10, 20, 25, 40, 30, 20, 15); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "ShipSpeedUp");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_08"); 
sld.equip.blade = "blade_08"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Mode = "trade";
sld.Ship.Type = GenerateShipExt(SHIP_BARQUE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 30;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 20;
SetCharacterGoods(sld, GOOD_BALLS, 100);
SetCharacterGoods(sld, GOOD_GRAPES, 100);
SetCharacterGoods(sld, GOOD_KNIPPELS, 100);
SetCharacterGoods(sld, GOOD_BOMBS, 100);
SetCharacterGoods(sld, GOOD_FOOD, 700); 
SetCharacterGoods(sld, GOOD_POWDER, 400);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_RUM, 100);
SetCharacterGoods(sld, GOOD_SHIPSILK	, 400);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �������� ������� ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gravina", "Gravina", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "��������";
sld.lastname = "�������"; 
sld.rank = 30+MOD_SKILL_ENEMY_RATE;  
sld.model = "Gravina"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Gravina";
sld.FaceId = 927;
sld.reputation = 100;      
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "30000"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;   
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Maracaibo_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 5, 7, 8, 10, 6, 9, 9); 
SetSelfSkill(sld, 40, 90, 70, 55, 65); 
SetShipSkill(sld, 55, 90, 95, 100, 95, 70, 65, 45, 50); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade_05"); 
sld.equip.blade = "blade_05";
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_WARLINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 60;
sld.Ship.Crew.Exp.Cannoners = 80;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_FOOD, 1200); 
SetCharacterGoods(sld, GOOD_POWDER, 8500);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 400);
SetCharacterGoods(sld, GOOD_SHIPSILK, 120);
SetCharacterGoods(sld, GOOD_ROPES, 120);
SetCharacterGoods(sld, GOOD_SANDAL, 120);
SetCharacterGoods(sld, GOOD_OIL, 120);
LAi_SetSitType(sld);
UpgradeShipParameter(sld, "Capacity"); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 300+MOD_SKILL_ENEMY_RATE*10, 300+MOD_SKILL_ENEMY_RATE*10);  

///////////////////// ��������� ///////////////////////////

/////////////////// ������� �������� ///////////////////

///////////////////     ���������   //////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jeronimo", "Jeronimo", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "���������"; 
sld.lastname = "";
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Jeronimo"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Jeronimo";
sld.FaceId = 791;
sld.reputation = "50";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "50000";
sld.location = "Locono_village"; 
sld.location.group = "goto"; 
sld.location.locator = "goto5";
sld.greeting = "Indian_Captain";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Indian_PGG.c";
sld.money = "15000";
sld.SuperShooter  = true;
SetSPECIAL(sld, 7, 3, 5, 7, 9, 4, 10); 
SetSelfSkill(sld, 80, 40, 30, 35, 70); 
SetShipSkill(sld, 55, 20, 50, 50, 45, 90, 40, 20, 70); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "ShipDefenseProfessional");
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CriticalHit");
GiveItem2Character(sld, "blade_01");
sld.equip.blade = "blade_01";
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
GiveItem2Character(sld, "indian019"); 
GiveItem2Character(sld, "indian022"); 
GiveItem2Character(sld, "indian021");
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 10;
sld.Ship.Crew.Exp.Cannoners = 5;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 1000); 
SetCharacterGoods(sld, GOOD_GRAPES, 1000); 
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000); 
SetCharacterGoods(sld, GOOD_BOMBS, 1000); 
SetCharacterGoods(sld, GOOD_FOOD, 800); 
SetCharacterGoods(sld, GOOD_POWDER, 6000); 
SetCharacterGoods(sld, GOOD_WEAPON, 1000); 
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000); 
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_LEATHER, 500);
SetCharacterGoods(sld, GOOD_CLOTHES, 500);
SetCharacterGoods(sld, GOOD_RUM, 150); 
LAi_SetCitizenType(sld);
UpgradeShipParameter(sld, "Capacity");
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 6.0, 20.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������� �������� ///////////////////

///////////////////// ��������� ///////////////////////////

/////////////////// ������� ����� ////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Genova", "Genova", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "�������";
sld.lastname = "�����"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "Genova"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Genova";
sld.FaceId = 928;
sld.reputation = 30;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "30000"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Cartahena_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 5, 6, 4, 9, 10, 3, 8); 
SetSelfSkill(sld, 80, 15, 50, 70, 65); 
SetShipSkill(sld, 30, 70, 60, 20, 80, 45, 65, 15, 35); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Turn180");  
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "InstantRepair"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "BasicBattleState"); 
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ProfessionalCommerce"); 
GiveItem2Character(sld, "pistol4");
sld.equip.gun = "pistol4";
GiveItem2Character(sld, "blade_18"); 
sld.equip.blade = "blade_18"; 
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���-�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_NAVIO, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 40;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 40;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 5500); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 600);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_SLAVES, 3000);
UpgradeShipParameter(sld, "Capacity"); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ����� ������ ////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Ferrash", "Ferrash", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Ferrash"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Ferrash";
sld.FaceId = 929;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Cartahena_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 6, 5, 7, 8, 7, 10);
SetSelfSkill(sld, 70, 15, 15, 70, 40); 
SetShipSkill(sld, 40, 25, 70, 75, 65, 30, 65, 65, 70); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_09"); 
sld.equip.blade = "blade_09";
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3");
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���-�����"; 
sld.Ship.Type = GenerateShipExt(SHIP_XEBEKVML, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 700);
SetCharacterGoods(sld, GOOD_GRAPES, 900);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 600); 
SetCharacterGoods(sld, GOOD_POWDER, 2000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 400);
SetCharacterGoods(sld, GOOD_RUM, 120);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 30);
SetCharacterGoods(sld, GOOD_PLANKS, 30);  
SetCharacterGoods(sld, GOOD_SILVER, 400);  
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 320+MOD_SKILL_ENEMY_RATE*10, 320+MOD_SKILL_ENEMY_RATE*10);  

///////////////// ��������� �� ������� //////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Kordoba", "Kordoba", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "���������";
sld.lastname = "�� �������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Kordoba"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Kordoba";
sld.FaceId = 930;
sld.reputation = 50;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Cartahena_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 6, 5, 4, 3, 10, 9); 
SetSelfSkill(sld, 50, 5, 35, 50, 25); 
SetShipSkill(sld, 25, 10, 25, 25, 45, 45, 30, 30, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_15"); 
sld.equip.blade = "blade_15";
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");  
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���-����"; 
sld.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 40;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*10, 250+MOD_SKILL_ENEMY_RATE*10); 

///////////////////// ��������� ///////////////////////////

/////////////////// ����� ������� ///////////////////

///////////////////// �������� ///////////////////////////

/////////////////// �����-����� ///////////////////

/////////////// ����� ��������� //////////////

sld = GetCharacter(NPC_GenerateCharacter("Muzio", "Muzio", "man", "man_B", 30, SPAIN, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "���������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Muzio"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Muzio";
sld.FaceId = 937;
sld.reputation = 30;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 25000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "PortoBello_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 8, 6, 6, 9, 5, 8, 8); 
SetSelfSkill(sld, 60, 80, 95, 80, 50); 
SetShipSkill(sld, 70, 65, 90, 90, 80, 75, 75, 85, 75); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "ByWorker"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_13"); 
sld.equip.blade = "blade_13"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FRIGATE_H, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "mercenary";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 800);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 4500);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 220);
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_IVORY, 200);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 00.00, 7.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////// ������� ���������� //////////////

sld = GetCharacter(NPC_GenerateCharacter("Fritz", "Fritz", "man", "man_B", 20, SPAIN, -1, false, "quest"));
sld.name = "�������"; 
sld.lastname = "����������"; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE; 
sld.model = "Fritz"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Fritz";
sld.FaceId = 938;
sld.reputation = 50;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 20000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortoBello_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 8, 7, 5, 10, 4, 7); 
SetSelfSkill(sld, 10, 5, 50, 25, 20); 
SetShipSkill(sld, 15, 30, 40, 35, 65, 50, 30, 35, 30); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
GiveItem2Character(sld, "pistol3");
sld.equip.gun = "pistol3";
GiveItem2Character(sld, "blade_07"); 
sld.equip.blade = "blade_07"; 
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass2"); 
EquipCharacterbyItem(sld, "cirass2"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "�������";
sld.Ship.Type = GenerateShipExt(SHIP_PINNACE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 20;
sld.Ship.Crew.Exp.Sailors = 90;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 600);
SetCharacterGoods(sld, GOOD_BOMBS, 400);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 3000);
SetCharacterGoods(sld, GOOD_WEAPON, 400);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 70);
SetCharacterGoods(sld, GOOD_SLAVES, 500); 
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 280+MOD_SKILL_ENEMY_RATE*10, 280+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ �� �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Agosto", "Agosto", "man", "man_B", 5, SPAIN, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�� ��������"; 
sld.rank = 5+MOD_SKILL_ENEMY_RATE; 
sld.model = "Agosto"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Agosto";
sld.FaceId = 942;
sld.reputation = 70;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortoBello_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 9, 7, 7, 10, 9, 10); 
SetSelfSkill(sld, 100, 1, 1, 1, 15); 
SetShipSkill(sld, 15, 15, 15, 15, 25, 20, 20, 20, 10); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
GiveItem2Character(sld, "blade_09"); 
sld.equip.blade = "blade_09"; 
GiveItem2Character(sld, "BackPack1");
EquipCharacterbyItem(sld, "BackPack1"); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_LATINA, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "trade";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 67;
sld.Ship.Crew.Exp.Sailors = 80;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 60;
SetCharacterGoods(sld, GOOD_BALLS, 300);
SetCharacterGoods(sld, GOOD_GRAPES, 200);
SetCharacterGoods(sld, GOOD_KNIPPELS, 200);
SetCharacterGoods(sld, GOOD_BOMBS, 300);
SetCharacterGoods(sld, GOOD_FOOD, 200); 
SetCharacterGoods(sld, GOOD_POWDER, 1500);
SetCharacterGoods(sld, GOOD_WEAPON, 150);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 200);
SetCharacterGoods(sld, GOOD_RUM, 50);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 225+MOD_SKILL_ENEMY_RATE*10, 225+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// �����-����� ///////////////////

/////////////////// ������� �������� ///////////////////

/////////////////// ������� ���� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "CrazyHorse", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "�������"; 
sld.lastname = "����";
sld.rank = 25+MOD_SKILL_ENEMY_RATE; 
sld.model = "CrazyHorse"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "CrazyHorse";
sld.FaceId = 792;
sld.reputation = "1";
sld.alignment = "BAD";
sld.loyality = 25;
sld.nation = PIRATE
sld.money = "250000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "PortoBello_Indian_town"; 
sld.location.group = "goto"; 
sld.location.locator = "goto5";
sld.greeting = "Indian_Captain";
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Indian_PGG.c";
SetSPECIAL(sld, 9, 7, 6, 10, 9, 6, 10);
SetSelfSkill(sld, 70, 85, 75, 85, 65);
SetShipSkill(sld, 100, 80, 70, 60, 90, 65, 85, 95, 90);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter"); 
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "blade_19");
sld.equip.blade = "blade_19";
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass4"); 
EquipCharacterbyItem(sld, "cirass4"); 
GiveItem2Character(sld, "sculMa1"); 
GiveItem2Character(sld, "sculMa2"); 
GiveItem2Character(sld, "sculMa3");  
LAi_SetCharacterUseBullet(sld, "bullet");
TakeNItems(sld, "potion2", 10);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_PATROLFRIGATE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 20;
sld.Ship.Crew.Exp.Soldiers = 90;
SetCharacterGoods(sld, GOOD_BALLS, 1500);
SetCharacterGoods(sld, GOOD_GRAPES, 1500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 7500);
SetCharacterGoods(sld, GOOD_WEAPON, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 2000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 900);
SetCharacterGoods(sld, GOOD_RUM, 250);
SetCharacterGoods(sld, GOOD_OIL, 1000);
LAi_SetCitizenType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 6.00, 20.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������� �������� ///////////////////

/////////////////// ������ ///////////////////

/////////////////     ��������� �������   ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pisarro", "Pisarro", "man", "man_B", 30, SPAIN, -1, false, "quest"));
sld.name = "���������"; 
sld.lastname = "�������";
sld.rank = 30+MOD_SKILL_ENEMY_RATE; 
sld.model = "Pisarro"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Pisarro";
sld.FaceId = 931;
sld.reputation = "1";
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "100000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Panama_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Panama_PGG.c";
SetSPECIAL(sld, 6, 8, 7, 8, 6, 5, 9);
SetSelfSkill(sld, 80, 50, 90, 70, 100);
SetShipSkill(sld, 100, 30, 70, 70, 95, 50, 80, 55, 70);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "Doctor1"); 
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
GiveItem2Character(sld, "blade300");
sld.equip.blade = "blade300";
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
GiveItem2Character(sld, "cirass4"); 
EquipCharacterbyItem(sld, "cirass4");  
GiveItem2Character(sld, "BackPack4");
EquipCharacterbyItem(sld, "BackPack4"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_HEAVYLINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 60;
sld.Ship.Crew.Exp.Sailors = 30;
sld.Ship.Crew.Exp.Cannoners = 40;
sld.Ship.Crew.Exp.Soldiers = 70;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 1800);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_POWDER, 6500);
SetCharacterGoods(sld, GOOD_WEAPON, 900);
SetCharacterGoods(sld, GOOD_FOOD, 1500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 900);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_PLANKS, 100);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
SetCharacterGoods(sld, GOOD_GOLD, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.0, 7.59); 
LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ����� �� �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Almagro", "Almagro", "man", "man", 30, SPAIN, -1, false, "quest"));
sld.name = "�����"; 
sld.lastname = "�� ��������";
sld.rank = 30+MOD_SKILL_ENEMY_RATE;  
sld.model = "Almagro"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Almagro";
sld.FaceId = 932;
sld.reputation = "80";
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "300000";
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Panama_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\Panama_PGG.c";
SetSPECIAL(sld, 7, 8, 6, 5, 9, 10, 4);
SetSelfSkill(sld, 60, 75, 75, 65, 75);
SetShipSkill(sld, 75, 75, 75, 75, 95, 75, 85, 75, 75);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter"); 
GiveItem2Character(sld, "pistol1");
sld.equip.gun = "pistol1";
GiveItem2Character(sld, "blade_29");
sld.equip.blade = "blade_29";
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
GiveItem2Character(sld, "bussol"); 
EquipCharacterbyItem(sld, "bussol"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 100); 
AddItems(sld, "gunpowder", 100); 
TakeNItems(sld, "potion2", 15);
sld.Abordage.Enable = true;
sld.Ship.Name = "��������"; 
sld.Ship.Type = GenerateShipExt(SHIP_HEAVYLINESHIP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 80;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 2500);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
SetCharacterGoods(sld, GOOD_BOMBS, 1500);
SetCharacterGoods(sld, GOOD_POWDER, 8000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 2000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 350);
SetCharacterGoods(sld, GOOD_PLANKS, 50);
SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
SetCharacterGoods(sld, GOOD_SILVER, 100);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.0, 15.59); 
LAi_SetHP(sld, 390+MOD_SKILL_ENEMY_RATE*10, 390+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// ������ ��� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gans", "Gans", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "������";
sld.lastname = "��� �������"; 
sld.rank = 13+MOD_SKILL_ENEMY_RATE;  
sld.model = "Gans"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Gans";
sld.FaceId = 933;
sld.reputation = 50;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 15000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "Panama_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_base2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\Panama_PGG.c";
SetSPECIAL(sld, 7, 8, 5, 8, 4, 6, 3); 
SetSelfSkill(sld, 30, 30, 45, 35, 35); 
SetShipSkill(sld, 60, 35, 35, 35, 55, 40, 45, 40, 40); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "blade_17"); 
sld.equip.blade = "blade_17"; 
GiveItem2Character(sld, "spyglass1"); 
EquipCharacterbyItem(sld, "spyglass1");
GiveItem2Character(sld, "cirass3"); 
EquipCharacterbyItem(sld, "cirass3"); 
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FLEUT, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 50;
sld.Ship.Crew.Exp.Cannoners = 50;
sld.Ship.Crew.Exp.Soldiers = 50;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 500);
SetCharacterGoods(sld, GOOD_FOOD, 500); 
SetCharacterGoods(sld, GOOD_POWDER, 2500);
SetCharacterGoods(sld, GOOD_WEAPON, 300);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
SetCharacterGoods(sld, GOOD_TOBACCO, 500);
SetCharacterGoods(sld, GOOD_RUM, 50);
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);  

/////////////////// ������ ///////////////////

///////////////////// �������� ///////////////////////////

///////////////////// ����������� ///////////////////////////

/////////////////// ���-������ ///////////////////

/////////////////// �������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Piligrim", "Piligrim", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "��������";
sld.lastname = ""; 
sld.rank = 20+MOD_SKILL_ENEMY_RATE;  
sld.model = "Piligrim"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Piligrim";
sld.FaceId = 898;
sld.reputation = "80";     
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "300000";  
sld.SuperShooter  = true;
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;  
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5; 
sld.location = "SanAndres_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 10, 6, 7, 9, 3, 5, 8); 
SetSelfSkill(sld, 50, 50, 50, 50, 100); 
SetShipSkill(sld, 60, 55, 60, 60, 65, 55, 50, 100, 100); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "ImmediateReload"); 
SetCharacterPerk(sld, "HullDamageUp");  
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2"); 
GiveItem2Character(sld, "pistol9");
sld.equip.gun = "pistol9";
GiveItem2Character(sld, "blade_14"); 
sld.equip.blade = "blade_14"; 
GiveItem2Character(sld, "spyglass2"); 
EquipCharacterbyItem(sld, "spyglass2");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "���������"; 
sld.Ship.Type = GenerateShipExt(SHIP_POLACRE, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "war";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 20;
sld.Ship.Crew.Exp.Cannoners = 30;
sld.Ship.Crew.Exp.Soldiers = 10;
SetCharacterGoods(sld, GOOD_BALLS, 1000);
SetCharacterGoods(sld, GOOD_GRAPES, 1000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 1000);
SetCharacterGoods(sld, GOOD_BOMBS, 1000);
SetCharacterGoods(sld, GOOD_FOOD, 1000); 
SetCharacterGoods(sld, GOOD_POWDER, 10000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 500);
SetCharacterGoods(sld, GOOD_RUM, 200);
SetCharacterGoods(sld, GOOD_CHOCOLATE, 250);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 7.59); 
LAi_SetHP(sld, 550.0, 550.0); 

/////////////////// ����� ������� ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sluga", "Sluga", "man", "man_B", 25, SPAIN, -1, false, "quest"));
sld.name = "�����";
sld.lastname = "�������"; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE;  
sld.model = "Sluga"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Sluga";
sld.FaceId = 945;
sld.reputation = 100;
sld.alignment = "good";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = "50000"; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "SanAndres_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 7, 8, 6, 5, 3, 9, 10); 
SetSelfSkill(sld, 80, 50, 20, 30, 10); 
SetShipSkill(sld, 80, 30, 40, 40, 80, 40, 70, 55, 10); 
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "HPPlus");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicBattleState");  
GiveItem2Character(sld, "pistol8");
sld.equip.gun = "pistol8";
GiveItem2Character(sld, "blade_17"); 
sld.equip.blade = "blade_17"; 
GiveItem2Character(sld, "spyglass3"); 
EquipCharacterbyItem(sld, "spyglass3");
GiveItem2Character(sld, "cirass1"); 
EquipCharacterbyItem(sld, "cirass1");
LAi_SetCharacterUseBullet(sld, "grapeshot"); 
TakeNItems(sld, "grapeshot", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�����������"; 
sld.Ship.Type = GenerateShipExt(SHIP_HEAVYGALEON, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 90;
sld.Ship.Crew.Exp.Sailors = 95;
sld.Ship.Crew.Exp.Cannoners = 70;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 2000);
SetCharacterGoods(sld, GOOD_GRAPES, 2000);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2000);
SetCharacterGoods(sld, GOOD_BOMBS, 2000);
SetCharacterGoods(sld, GOOD_FOOD, 2000); 
SetCharacterGoods(sld, GOOD_POWDER, 9000);
SetCharacterGoods(sld, GOOD_WEAPON, 1000);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_SILVER, 1000);
SetCharacterGoods(sld, GOOD_GOLD, 500);
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 8.00, 15.59); 
LAi_SetHP(sld, 500.0, 500.0); 

/////////////// ����� //////////////

sld = GetCharacter(NPC_GenerateCharacter("Legat", "Legat", "man", "man_B", 22, SPAIN, -1, false, "quest"));
sld.name = "�����";
sld.lastname = ""; 
sld.rank = 25+MOD_SKILL_ENEMY_RATE;  
sld.model = "Legat"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Legat";
sld.FaceId = 905;
sld.reputation = 20;
sld.alignment = "bad";
sld.loyality = 25;
sld.nation = SPAIN
sld.money = 100000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.MultiFighter = 1.5; // ������������
sld.MultiShooter = 1.5;
sld.location = "SanAndres_tavern"; 
sld.location.group = "sit"; 
sld.location.locator = "sit_front2";
sld.greeting = "captain"; 
sld.Dialog.Filename = "Population\PGG.c";
SetSPECIAL(sld, 9, 10, 6, 3, 5, 8, 7); 
SetSelfSkill(sld, 20, 20, 90, 70, 30); 
SetShipSkill(sld, 50, 35, 30, 35, 80, 40, 50, 100, 20); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2");
GiveItem2Character(sld, "pistol6");
sld.equip.gun = "pistol6";
GiveItem2Character(sld, "blade_21"); 
sld.equip.blade = "blade_21"; 
GiveItem2Character(sld, "spyglass4"); 
EquipCharacterbyItem(sld, "spyglass4");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7");
LAi_SetCharacterUseBullet(sld, "bullet"); 
TakeNItems(sld, "bullet", 50); 
AddItems(sld, "gunpowder", 50); 
TakeNItems(sld, "potion2", 5);
sld.Abordage.Enable = true;
sld.Ship.Name = "�������"; 
sld.Ship.Type = GenerateShipExt(SHIP_FRIGATE_H, true, sld); 
sld.Ship.Stopped = true; 
sld.GenQuest.CrewGuardMode  = true;
sld.Ship.Mode = "guard";
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 50;
sld.Ship.Crew.Exp.Sailors = 70;
sld.Ship.Crew.Exp.Cannoners = 90;
sld.Ship.Crew.Exp.Soldiers = 80;
SetCharacterGoods(sld, GOOD_BALLS, 500);
SetCharacterGoods(sld, GOOD_GRAPES, 500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
SetCharacterGoods(sld, GOOD_BOMBS, 3000);
SetCharacterGoods(sld, GOOD_FOOD, 1500); 
SetCharacterGoods(sld, GOOD_POWDER, 5000);
SetCharacterGoods(sld, GOOD_WEAPON, 700);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
SetCharacterGoods(sld, GOOD_RUM, 250);  
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 350.0, 350.0);

/////////////////// ���-������ ///////////////////

///////////////////// ����������� ///////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   ////////	   ���	07. 17 - 02.18		//////////							
///// 	by ����� ���������� & ������ �����     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   //////// ����-������� ��������   03.18	//////////							
///// 	by ����� ����������     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////// ���������� //////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Terminatorr", "Terminatorr", "man", "man", 55, PIRATE, -1, false, "quest"));
sld.name = "����������";
sld.lastname = ""; 
sld.rank = 45; 
sld.model = "Terminator"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "Terminatorr";
sld.FaceId = 795;
sld.reputation = 100;
sld.alignment = "good";
sld.loyality = 100;
sld.nation = PIRATE
sld.money = 1; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Dominica_Dungeon"; 
sld.location.group = "quest"; 
sld.location.locator = "pelly";
sld.greeting = "captain"; 
sld.MultiFighter = 10.0; // ������������
sld.MultiShooter = 10.0;
sld.Dialog.Filename = "Population\Uber.c";
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 100, 100, 100, 100, 100); 
SetShipSkill(sld, 100, 1, 1, 1, 1, 1, 1, 1, 100); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ShipEscape");
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "ByWorker2");
GiveItem2Character(sld, "pistol10");
sld.equip.gun = "pistol10";
GiveItem2Character(sld, "unarmed"); 
sld.equip.blade = "unarmed"; 
LAi_SetCharacterUseBullet(sld, "shotgun_cartridge"); 
TakeNItems(sld, "GunCap_colt", 1000); 
AddItems(sld, "shotgun_cartridge", 1000); 
TakeNItems(sld, "potion2", 10);
sld.Abordage.Enable = true;
LAi_SetStayType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 0.59); 
LAi_SetHP(sld, 10000.0, 10000.0);

////////////////////// ����� //////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Mumiya", "Mumiya", "man", "man_B", 55, PIRATE, -1, false, "quest"));
sld.name = "�����";
sld.lastname = ""; 
sld.rank = 45; 
sld.model = "Mumiya"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "Mumiya";
sld.FaceId = 796;
sld.reputation = 1;
sld.alignment = "bad";
sld.loyality = 100;
sld.nation = PIRATE
sld.money = 1; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "Temple"; 
sld.location.group = "goto"; 
sld.location.locator = "goto15";
sld.greeting = "captain"; 
sld.MultiFighter = 10.0; // ������������
sld.MultiShooter = 10.0;
sld.Dialog.Filename = "Population\Uber.c";
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 100, 100, 100, 100, 100); 
SetShipSkill(sld, 100, 1, 1, 1, 1, 1, 1, 1, 100); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ShipEscape");
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "ByWorker2");
GiveItem2Character(sld, "topor_01"); 
sld.equip.blade = "topor_01"; 
LAi_SetCharacterUseBullet(sld, "Bullet"); 
TakeNItems(sld, "potion2", 15);
TakeNItems(sld, "berserker_potion", 15);
TakeNItems(sld, "Ultimate_potion", 15);
TakeNItems(sld, "potion6", 15);
TakeNItems(sld, "potion7", 15);
TakeNItems(sld, "mangarosapower", 15);
TakeNItems(sld, "mangarosafast", 15);
TakeNItems(sld, "mangarosatotal", 15);
sld.Abordage.Enable = true;
LAi_SetStayType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 0.59); 
LAi_SetHP(sld, 10000.0, 10000.0);

//////////////////// ������ ������ ////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("JollyRoger", "JollyRoger", "man", "man_B", 55, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "������"; 
sld.rank = 45; 
sld.model = "JollyRoger"; 
sld.model.animation = "man_B"; 
sld.sex = "man";
sld.id = "JollyRoger";
sld.FaceId = 797;
sld.reputation = 50;
sld.alignment = "bad";
sld.loyality = 100;
sld.nation = PIRATE
sld.money = 100000000; 
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.DontRansackCaptain = true;
sld.AlwaysSandbankManeuver = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.location = "LeFransua_Cavern"; 
sld.location.group = "monsters"; 
sld.location.locator = "monster3";
sld.greeting = "captain"; 
sld.MultiFighter = 10.0; // ������������
sld.MultiShooter = 10.0;
sld.Dialog.Filename = "Population\Roger.c";
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 100, 100, 100, 100, 100); 
SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100); SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "IronWill");
SetCharacterPerk(sld, "ShipEscape");
SetCharacterPerk(sld, "ByWorker");
SetCharacterPerk(sld, "ByWorker2");
SetCharacterPerk(sld, "Brander"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "LongRangeGrappling"); 
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "MusketsShoot");
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "AdvancedCommerce");
SetCharacterPerk(sld, "ProfessionalCommerce"); 
SetCharacterPerk(sld, "FastReload"); 
SetCharacterPerk(sld, "ImmediateReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "LongRangeShoot"); 
SetCharacterPerk(sld, "CannonProfessional");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Builder");
SetCharacterPerk(sld, "BasicBattleState");
SetCharacterPerk(sld, "AdvancedBattleState"); 
SetCharacterPerk(sld, "InstantRepair");
SetCharacterPerk(sld, "SelfRepair");
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterPerk(sld, "Doctor1");
SetCharacterPerk(sld, "Doctor2"); 
SetCharacterPerk(sld, "Doctor3");
GiveItem2Character(sld, "pistol7");
sld.equip.gun = "pistol7";
GiveItem2Character(sld, "blade300");
sld.equip.blade = "blade300";
GiveItem2Character(sld, "spyglass5"); 
EquipCharacterbyItem(sld, "spyglass5");
GiveItem2Character(sld, "cirass4"); 
EquipCharacterbyItem(sld, "cirass4"); 
GiveItem2Character(sld, "sextant2"); 
EquipCharacterbyItem(sld, "sextant2");
GiveItem2Character(sld, "DeSouzaCross");  
LAi_SetCharacterUseBullet(sld, "shotgun_cartridge"); 
TakeNItems(sld, "GunCap_colt", 500); 
AddItems(sld, "shotgun_cartridge", 500); 
TakeNItems(sld, "potion2", 15);
TakeNItems(sld, "berserker_potion", 15);
TakeNItems(sld, "mangarosapower", 15);
TakeNItems(sld, "mangarosafast", 15);
TakeNItems(sld, "mangarosatotal", 15);
TakeNItems(sld, "potion7", 15);
GiveItem2Character(sld, "sculMa1"); 
GiveItem2Character(sld, "sculMa2"); 
GiveItem2Character(sld, "sculMa3"); 
GiveItem2Character(sld, "indian017"); 
GiveItem2Character(sld, "indian020"); 
GiveItem2Character(sld, "indian012");
GiveItem2Character(sld, "indian019"); 
GiveItem2Character(sld, "indian022"); 
GiveItem2Character(sld, "indian021"); 
GiveItem2Character(sld, "indian018"); 
GiveItem2Character(sld, "indian006"); 
GiveItem2Character(sld, "indian014");
GiveItem2Character(sld, "indian005");
GiveItem2Character(sld, "Totem_002");
GiveItem2Character(sld, "Map_Best"); 
GiveItem2Character(sld, "map_bermudas"); 
GiveItem2Character(sld, "map_jam"); 
GiveItem2Character(sld, "map_cayman"); 
GiveItem2Character(sld, "map_barbados"); 
GiveItem2Character(sld, "map_tortuga");
GiveItem2Character(sld, "map_curacao"); 
GiveItem2Character(sld, "map_martiniqua"); 
GiveItem2Character(sld, "map_dominica"); 
GiveItem2Character(sld, "map_trinidad"); 
GiveItem2Character(sld, "map_puerto"); 
GiveItem2Character(sld, "map_cuba");
GiveItem2Character(sld, "map_hisp");
GiveItem2Character(sld, "map_nevis");
GiveItem2Character(sld, "map_beliz"); 
GiveItem2Character(sld, "map_guad"); 
GiveItem2Character(sld, "map_santa"); 
GiveItem2Character(sld, "map_antigua"); 
GiveItem2Character(sld, "map_terks"); 
GiveItem2Character(sld, "map_sm");
GiveItem2Character(sld, "map_maine_1"); 
GiveItem2Character(sld, "map_maine_2"); 
GiveItem2Character(sld, "map_panama"); 
GiveItem2Character(sld, "map_cumana"); 
sld.Abordage.Enable = true;
sld.Ship.Name = "������� ������"; 
sld.Ship.Type = GenerateShipExt(SHIP_SOLEYPIR, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
SetCrewQuantityFull(sld);
sld.ship.Crew.Morale = 100;
sld.Ship.Crew.Exp.Sailors = 100;
sld.Ship.Crew.Exp.Cannoners = 100;
sld.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(sld, GOOD_BALLS, 2500);
SetCharacterGoods(sld, GOOD_GRAPES, 2500);
SetCharacterGoods(sld, GOOD_KNIPPELS, 2500);
SetCharacterGoods(sld, GOOD_BOMBS, 2500);
SetCharacterGoods(sld, GOOD_POWDER, 15000);
SetCharacterGoods(sld, GOOD_WEAPON, 1500);
SetCharacterGoods(sld, GOOD_FOOD, 3500);
SetCharacterGoods(sld, GOOD_MEDICAMENT, 1500);
SetCharacterGoods(sld, GOOD_RUM, 300);
SetCharacterGoods(sld, GOOD_GOLD, 1000);
UpgradeShipParameter(sld, "Capacity");
sld.Abordage.Enable = true;
LAi_SetStayType(sld);  
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 0.00, 0.59); 
LAi_SetHP(sld, 10000.0, 10000.0);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   //////// ����-������� ��������   03.18	//////////							
///// 	by ����� ����������     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//�������� �����
sld = GetCharacter(NPC_GenerateCharacter("PoorKillSponsor", "smuggler_boss", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "������";
sld.lastname = "�����"; 
sld.talker = 8; //������ ������
sld.rank = 30; 
sld.model = "smuggler_boss"; 
sld.model.animation = "man"; 
sld.sex = "man";
sld.id = "PoorKillSponsor";
sld.FaceId = 507;
sld.reputation = 1;
sld.alignment = "bad";
sld.nation = HOLLAND
sld.SaveItemsForDead  = true; 
sld.DontClearDead = true;
sld.SuperShooter  = true;
sld.greeting = "Gr_OliverTrast";
sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
sld.dialog.currentnode = "Begin_PoorKill";
LAi_SetImmortal(sld, true);
LAi_SetHP(sld, 100.0, 100.0);
}

void LSCCNpcInit()//������� ���� �������� ���������� �� ��� �����
{
	//���-�������
	sld = GetCharacter(NPC_GenerateCharacter("LSCCMayor", "capitan_2", "man", "man", 50, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 50, 90, 90, "blade_31", "pistol4", "bullet", 200);
	sld.name = "���";
	sld.lastname = "������";
	sld.city = "LostShipsCityy";
	sld.location = "SanAugustineResidencee";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_0";
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mayor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "mayor"; //��� ���
	sld.greeting = "Gr_Kapper";
	sld.standUp = true; //�������� � �������� �� ����� 
	sld.watchBoxes = true;
	sld.standUp.exitDisable = true;   //�������� ����� � ������ �����
	sld.watchBoxes.exitDisable = true; //�������� ����� � ������ �����
	//sld.talker = true; //������ ������
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 14);
	TakeNItems(sld, "bullet", 23);
	TakeNItems(sld, "cartridge", 18);
	TakeNItems(sld, "GunPowder", 16);
	sld.money = 16450;
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ����������� �1
	sld = GetCharacter(NPC_GenerateCharacter("Ment_1", "mercen_13", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_19", "pistol4", "bullet", 100);
	sld.name = "���";
	sld.lastname = "�����";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto9"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_1"; 
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.greeting = "pirat_common";
	sld.talker = true; //������ ������
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 24);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 11);
	TakeNItems(sld, "GunPowder", 14);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location"); 

	// ����������� �2
	sld = GetCharacter(NPC_GenerateCharacter("Ment_2", "off_fra_4", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_18", "pistol4", "bullet", 100);
	sld.name = "�����";
	sld.lastname = "�������";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_2"; 
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������	
	sld.location.hours = 2; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.greeting = "pirat_common";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 10);
	TakeNItems(sld, "bullet", 5);
	TakeNItems(sld, "cartridge", 8);
	TakeNItems(sld, "GunPowder", 12);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ����������� �3
	sld = GetCharacter(NPC_GenerateCharacter("Ment_3", "sold_hol_16", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_17", "pistol4", "bullet", 100);
	sld.name = "����";
	sld.lastname = "�������";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto11"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_3"; 
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������
	sld.location.hours = 6; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.greeting = "pirat_common";
	sld.talker = true; //������ ������
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 19);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 6);
	TakeNItems(sld, "GunPowder", 8);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ����������� �4
	sld = GetCharacter(NPC_GenerateCharacter("Ment_4", "off_spa_5", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_16", "pistol4", "bullet", 100);
	sld.name = "�����";
	sld.lastname = "����";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_4";  
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.greeting = "pirat_common";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	sld.watchBoxes = true;
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ����������� �5
	sld = GetCharacter(NPC_GenerateCharacter("Ment_5", "mercen_8", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_15", "pistol4", "bullet", 100);
	sld.name = "�����";
	sld.lastname = "����";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_5"; 
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.greeting = "pirat_common";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 13);
	TakeNItems(sld, "bullet", 11);
	TakeNItems(sld, "cartridge", 7);
	TakeNItems(sld, "GunPowder", 12);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ����������� �6
	sld = GetCharacter(NPC_GenerateCharacter("Ment_6", "Dragoon_1", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "topor_04", "pistol4", "bullet", 100);
	sld.name = "����";
	sld.lastname = "�������";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "11"; //������� ������� � ���
	sld.location.baseLocator = "goto11_6"; 
	sld.location.baseShip.going = false; //������������ ����� ��������� � ������	
	sld.location.hours = 7; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //��� ���
	sld.talker = true; //������ ������
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 16);
	TakeNItems(sld, "cartridge", 12);
	TakeNItems(sld, "GunPowder", 11);
	sld.watchBoxes = true;
	sld.greeting = "pirat_common";
	SetSPECIAL(sld, 10, 4, 9, 6, 8, 9, 7);
	SetSelfSkill(sld, 100, 100, 100, 30, 90);
	SetShipSkill(sld, 10, 10, 5, 20, 20, 30, 10, 10, 60);
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Ciras");
	SetCharacterPerk(sld, "Grus");
	SetCharacterPerk(sld, "Rush");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ ������� ------------------------ 
	//���������
	sld = GetCharacter(NPC_GenerateCharacter("LSCCBarmen", "barmen_8", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "�������";
	sld.rank = 20;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Barmen.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //��� ���
	sld.greeting = "Gr_Barmen";
	LAi_SetBarmanType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	//����������
	sld = GetCharacter(NPC_GenerateCharacter("LSCCwaitress", "CitizenWom_1", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "�����";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "waitress";
	sld.location.locator = "barmen";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Waitress.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //��� ���
	sld.greeting = "Armo_Dulin";
	LAi_SetWaitressType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ ������� �������� ------------------------	
	// ������� ��������� ����� �������
	sld = GetCharacter(NPC_GenerateCharacter("PedroHurtado", "usurer_2", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "�����";
	sld.lastname = "�������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto06_1"; 
	sld.location.baseShip = "06"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 2; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\PedroHurtado.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ������� ��������� ���� ����
	sld = GetCharacter(NPC_GenerateCharacter("ZhilBaru", "trader_16", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "����";
	sld.lastname = "����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto07_1"; 
	sld.location.baseShip = "07"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 1; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ZhilBaru.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ������� ��������� ������� ������
	sld = GetCharacter(NPC_GenerateCharacter("TristanBorcher", "shipowner_13", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_1"; 
	sld.location.baseShip = "09"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\TristanBorcher.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ������� ��������� ����� ����
	sld = GetCharacter(NPC_GenerateCharacter("RoyelHaag", "trader_11", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14_1"; 
	sld.location.baseShip = "14"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\RoyelHaag.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ������� ��������� ������� �����
	sld = GetCharacter(NPC_GenerateCharacter("DominicLegro", "trader_10", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "�������";
	sld.lastname = "�����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15_1"; 
	sld.location.baseShip = "15"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\DiminicLegro.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ������� ��������� ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("JorgeStouks", "barmen_5", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto08_1"; 
	sld.location.baseShip = "08"; //������� ������� � ���
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\JorgeStouks.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_JorgeStouks";
	sld.talker = true; //������ ������
	LAi_RemoveLoginTime(sld);	
	LAi_SetStayType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");
	ChangeCharacterAddress(sld, "LostShipsCityy_town", "goto11_2");

	// ------------------------ ������� �������� � ������� ------------------------
	// � ������� ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("HenryFolder", "barmen_14", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit2"; 
	sld.location.baseShip = "03"; //������� ������� � ���
	sld.location.baseLocator = "goto03_2"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 6; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\HenryFolder.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ������ �������
	sld = GetCharacter(NPC_GenerateCharacter("FelixMendoza", "shipowner_1", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit3"; 
	sld.location.baseShip = "10"; //������� ������� � ���
	sld.location.baseLocator = "goto10_2"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\FelixMendoza.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ������ ������
	sld = GetCharacter(NPC_GenerateCharacter("RodgerWoyler", "usurer_5", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit5"; 
	sld.location.baseShip = "12"; //������� ������� � ���
	sld.location.baseLocator = "goto12_2"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 7; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\RodgerWoyler.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ����� �����
	sld = GetCharacter(NPC_GenerateCharacter("AndreLabor", "shipowner_15", "man", "man", 15, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 15, 60, 60, "blade_20", "pistol2", "bullet", 10);
	sld.name = "�����";
	sld.lastname = "�����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit9"; 
	sld.location.baseShip = "15"; //������� ������� � ���
	sld.location.baseLocator = "goto15_2"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\AndreLabor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Master";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ������ �����
	sld = GetCharacter(NPC_GenerateCharacter("StefanKleyn", "shipowner_6", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "������";
	sld.lastname = "�����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit8"; 
	sld.location.baseShip = "14"; //������� ������� � ���
	sld.location.baseLocator = "goto14_2";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\StefanKleyn.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ����� �����
	sld = GetCharacter(NPC_GenerateCharacter("ThomasFlann", "citiz_1", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "�����";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit6"; 
	sld.location.baseShip = "02"; //������� ������� � ���
	sld.location.baseLocator = "goto02_2";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 3; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ThomasFlann.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	sld.talker = true; //������ ������
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������� ����� �������
	sld = GetCharacter(NPC_GenerateCharacter("PabloBarades", "officer_20", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "�����";
	sld.lastname = "�������";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit14"; 
	sld.location.baseShip = "09"; //������� ������� � ���
	sld.location.baseLocator = "goto09_2";  
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\PabloBarades.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ ������� �������� � ������ ------------------------
	// �����
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Priest", "priest_3", "man", "man", 5, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Priest.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "priest"; //��� ���
	sld.greeting = "Gr_padre";
	LAi_SetPriestType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");		
	
	// � ������ ������ �����
	sld = GetCharacter(NPC_GenerateCharacter("SandraGomes", "girl_4", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�����";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "04"; //������� ������� � ���
	sld.location.baseLocator = "goto04_3"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\SandraGomes.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// � ������ ������ ����
	sld = GetCharacter(NPC_GenerateCharacter("MonikaRight", "girl_5", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "����";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 
	sld.location.baseShip = "08"; //������� ������� � ���
	sld.location.baseLocator = "goto08_3"; 
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\MonikaRight.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ ������� ------------------------

	// ������ ���� - ��������
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_trader", "Axel", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "����";
	sld.greeting = "Axel";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Trader.c";
	sld.dialog.currentnode   = "First time";
	sld.city = "LostShipsCityy";
	sld.cityTape = "trader"; //��� ���
	sld.rank = 19;
	LAi_SetHP(sld, 150, 150); 
	SetSelfSkill(sld, 55, 35, 10, 35, 90);
	SetShipSkill(sld, 80, 100, 10, 10, 10, 10, 10, 10, 10);
	SetSPECIAL(sld, 4, 4, 5, 10, 10, 7, 6);
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GiveItem2Character(sld, "blade_15");
	sld.equip.blade = "blade_15";
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	LAi_SetCharacterUseBullet(sld, "bullet");
                     TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	sld.location = "EsmeraldaStoreBigg";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.Merchant = true;
	sld.Merchant.type = "LSC_trader";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	LAi_SetOwnerType(sld);

	// ------------------------ ������ ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_PrisonerHead", "Hobart", "man", "man", 40, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 40, 87, 87, "blade_29", "pistol4", "bullet", 100);
	sld.name = "��������";
	sld.lastname = "�'������";
	sld.rank = 40;
	sld.city = "LostShipsCityy";
	sld.location = "TartarusPrisonn";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Prisoner.c";
	sld.dialog.currentnode   = "prisonerHead";
	sld.cityTape = "prisonerHead"; //��� ���
	sld.greeting = "pirat_common";
	sld.standUp = true; //�������� � �������� �� ����� 
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 7);
	TakeNItems(sld, "bullet", 6);
	TakeNItems(sld, "cartridge", 8);
	TakeNItems(sld, "GunPowder", 5);
	sld.watchBoxes = true;
	sld.location.days = 2; //������������ ����� .. ����
	//sld.talker = true; //������ ������
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	
	SaveCurrentNpcQuestDateParam(sld, "location");

	// �������� �1
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Prisoner1", "SoldierEnglish_1", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_21", "pistol3", "bullet", 100);
	sld.name = "�����";
	sld.lastname = "����";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "TartarusPrisonn";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Prisoner.c";
	sld.dialog.currentnode   = "Prisoner";
	sld.cityTape = "prisoner"; //��� ���
	sld.greeting = "pirat_common";
	sld.standUp = true; //�������� � �������� �� ����� 
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 16);
	TakeNItems(sld, "cartridge", 19);
	TakeNItems(sld, "GunPowder", 24);
	sld.watchBoxes = true;
	sld.location.hours = 4; //������������ ����� .. �����
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ ������ ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Usurer", "trader_9", "man", "man", 30, PIRATE, -1, true, "quest"));
	sld.name = "�������";
	sld.lastname = "�����";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "CarolineBankk";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Usurer.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "usurer"; //��� ���
	sld.greeting = "cit_common";
	LAi_SetImmortal(sld, true);
	LAi_RemoveLoginTime(sld);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	

	// ------------------------ ������� ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Mechanic", "Mechanic", "man", "man", 5, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "�������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mechanic.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "mechanic"; //��� ���
	sld.greeting = "Gr_Master";
	LAi_RemoveLoginTime(sld);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");

	// ------------------------ ���������� �������� ------------------------
	// ��������� ��������� ���� ������
	sld = GetCharacter(NPC_GenerateCharacter("ElisTaylor", "girl_3", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "����";
	sld.lastname = "������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "CeresSmithyy";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "03"; //������� ������� � ���
	sld.location.baseLocator = "goto03_0"; 
	sld.location.baseLocation = "CeresSmithyy"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 4; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ElisTaylor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ��������� ��������� ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("OreliBertin", "girl_6", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "FurieShipInside22";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "06"; //������� ������� � ���
	sld.location.baseLocator = "goto06_0"; 
	sld.location.baseLocation = "FurieShipInside22"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 6; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\OreliBertin.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ��������� ��������� ��� �����
	sld = GetCharacter(NPC_GenerateCharacter("LeaToors", "girl_7", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "���";
	sld.lastname = "�����";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "PlutoStoreSmalll";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "09"; //������� ������� � ���
	sld.location.baseLocator = "goto09_0"; 
	sld.location.baseLocation = "PlutoStoreSmalll"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\LeaToors.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ��������� ��������� ����� ������
	sld = GetCharacter(NPC_GenerateCharacter("ElizaCalvo", "girl_8", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "�����";
	sld.lastname = "������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "SantaFlorentinaShipInside44";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "14"; //������� ������� � ���
	sld.location.baseLocator = "goto14_0"; 
	sld.location.baseLocation = "SantaFlorentinaShipInside44"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 7; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ElizaCalvo.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ��������� ��������� ������ ������
	sld = GetCharacter(NPC_GenerateCharacter("SesilGalard", "BaynesWife", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "������";
	sld.lastname = "������";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "AvaShipInside33";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "15"; //������� ������� � ���
	sld.location.baseLocator = "goto15_0"; 
	sld.location.baseLocation = "AvaShipInside33"; //������� ��������� �������
	sld.location.baseShip.going = true; //������������ ����� ��������� � ������	
	sld.location.hours = 5; //������������ ����� .. �����
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\SesilGalard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //��� ���
	sld.greeting = "Gr_SesilGalard";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	//------------------- ���� ������ -------------------
	// ������ �������
	sld = GetCharacter(NPC_GenerateCharacter("Narval_head", "capitan_3", "man", "man", 35, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 35, 100, 100, "blade_28", "pistol4", "bullet", 200);
	sld.name = "�����";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	SaveCurrentNpcQuestDateParam(sld, "location"); //����� ����� ������� �����������
	// ������ �1
	sld = GetCharacter(NPC_GenerateCharacter("Narval_1", "officer_18", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 60, 60, "blade_21", "pistol6", "bullet", 10);
	sld.name = "����";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 14);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 16);
	TakeNItems(sld, "GunPowder", 24);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �2
	sld = GetCharacter(NPC_GenerateCharacter("Narval_2", "officer_12", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 26, 80, 80, "blade_29", "pistol3", "bullet", 15);
	sld.name = "������";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 10);
	TakeNItems(sld, "bullet", 11);
	TakeNItems(sld, "cartridge", 12);
	TakeNItems(sld, "GunPowder", 8);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �3
	sld = GetCharacter(NPC_GenerateCharacter("Narval_3", "trader_2", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 24, 70, 70, "blade_25", "pistol5", "bullet", 10);
	sld.name = "���";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �4
	sld = GetCharacter(NPC_GenerateCharacter("Narval_4", "pirate_7", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 85, 85, "blade_30", "pistol6", "bullet", 15);
	sld.name = "����";
	sld.lastname = "������";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 16);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 17);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �5
	sld = GetCharacter(NPC_GenerateCharacter("Narval_5", "pirate_3", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "topor_04", "pistol3", "bullet", 10);
	sld.name = "�����";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto6"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �6
	sld = GetCharacter(NPC_GenerateCharacter("Narval_6", "pirate_4", "man", "man", 22, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 22, 65, 65, "blade_22", "pistol6", "bullet", 10);
	sld.name = "�����";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto7"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 15);
	TakeNItems(sld, "bullet", 12);
	TakeNItems(sld, "cartridge", 9);
	TakeNItems(sld, "GunPowder", 17);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// ������ �7
	sld = GetCharacter(NPC_GenerateCharacter("Narval_7", "officer_14", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 85, 85, "blade_23", "pistol4", "bullet", 15);
	sld.name = "�����";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto8"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //��� ���
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");

	//------------------- ���� ������ -------------------
	// ������ �������
	sld = GetCharacter(NPC_GenerateCharacter("Casper_head", "shipowner_7", "man", "man", 35, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 35, 100, 100, "blade_28", "pistol5", "bullet", 20);
	sld.name = "������";
	sld.lastname = "�������";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto8"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//SaveCurrentNpcQuestDateParam(sld, "location"); //����� ����� ������� �����������
	//������ �1
	sld = GetCharacter(NPC_GenerateCharacter("Casper_1", "pirate_9", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "topor_04", "pistol3", "bullet", 10);
	sld.name = "�����";
	sld.lastname = "������";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 25);
	TakeNItems(sld, "cartridge", 20);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �2
	sld = GetCharacter(NPC_GenerateCharacter("Casper_2", "pirate_8", "man", "man", 21, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 21, 80, 80, "blade_26", "pistol6", "bullet", 12);
	sld.name = "�����";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto6"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 14);
	TakeNItems(sld, "GunPowder", 11);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �3
	sld = GetCharacter(NPC_GenerateCharacter("Casper_3", "pirate_10", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "blade_24", "pistol4", "bullet", 15);
	sld.name = "����";
	sld.lastname = "������";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 18);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 14);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �4
	sld = GetCharacter(NPC_GenerateCharacter("Casper_4", "pirate_2", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_23", "pistol3", "bullet", 10);
	sld.name = "������";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto7"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �5
	sld = GetCharacter(NPC_GenerateCharacter("Casper_5", "officer_16", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "topor_04", "pistol3", "bullet", 13);
	sld.name = "������";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto13"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 20);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �6
	sld = GetCharacter(NPC_GenerateCharacter("Casper_6", "officer_1", "man", "man", 29, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 29, 80, 80, "blade_25", "pistol4", "bullet", 10);
	sld.name = "����";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto1" //; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 15);
	TakeNItems(sld, "bullet", 18);
	TakeNItems(sld, "cartridge", 19);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �7
	sld = GetCharacter(NPC_GenerateCharacter("Casper_7", "officer_2", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_22", "pistol6", "bullet", 15);
	sld.name = "������";
	sld.lastname = "���";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 12);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 17);
	TakeNItems(sld, "GunPowder", 22);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �8
	sld = GetCharacter(NPC_GenerateCharacter("Casper_8", "officer_17", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_25", "pistol4", "bullet", 15);
	sld.name = "�����";
	sld.lastname = "������";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; // 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 18);
	TakeNItems(sld, "GunPowder", 23);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �9
	sld = GetCharacter(NPC_GenerateCharacter("Casper_9", "officer_5", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_26", "pistol6", "bullet", 15);
	sld.name = "������";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto10"; //
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 15);
	TakeNItems(sld, "GunPowder", 19);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �10
	sld = GetCharacter(NPC_GenerateCharacter("Casper_10", "officer_6", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_27", "pistol3", "bullet", 15);
	sld.name = "������";
	sld.lastname = "����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto11"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 17);
	TakeNItems(sld, "cartridge", 18);
	TakeNItems(sld, "GunPowder", 31);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//������ �11
	sld = GetCharacter(NPC_GenerateCharacter("Casper_11", "officer_20", "man", "man", 27, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "blade_28", "pistol4", "bullet", 25);
	sld.name = "����";
	sld.lastname = "�����";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto12"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //��� ���
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 22);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 20);
	TakeNItems(sld, "GunPowder", 27);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
}
// Jason ������ ������
bool GoldenGirl_CheckGirls() // �������� ������� ����� ��� ����
{
	if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1) 
	{
		pchar.questTemp.GoldenGirl.Helena = "true";
		log_Testinfo("������� - �����");
		return true;
	}
	if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1) 
	{
		pchar.questTemp.GoldenGirl.Mary = "true";
		log_Testinfo("������� - ����");
		return true;
	}
	return false;
}
// Jason ����� � ���������
bool LongHappy_CheckGirls() // �������� ������� ����� ��� ����
{
	if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1) 
	{
		return true;
	}
	if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1) 
	{
		return true;
	}
	return false;
}

bool LongHappy_CheckCondisiones() // �������� ���� ������� fix 22-03-20
{
	if (!CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) return false;
	
	if (!GoldenGirl_CheckGirls()) return false;
	
	if (!CheckAttribute(pchar, "questTemp.GoldenGirl")) return false;
	
	if (CheckAttribute(pchar, "questTemp.GoldenGirl")) 
	{
		if (!LongHappy_CheckGoldenGirl()) return false;
	}
	if (CheckAttribute(pchar, "questTemp.Patria"))
	{
		if (!LongHappy_CheckPatria()) return false;
	}
	return true;
}

bool LongHappy_CheckGoldenGirl() // fix 22-03-20
{
	if (pchar.questTemp.GoldenGirl == "end") return true;
	if (pchar.questTemp.GoldenGirl == "cards_fail") return true;
	if (pchar.questTemp.GoldenGirl == "start_fail") return true;
	return false;
}

bool LongHappy_CheckPatria() // fix 22-03-20
{
	if (pchar.questTemp.Patria == "end") return true;
	if (pchar.questTemp.Patria == "fail") return true;
	return false;
}

bool LongHappy_CheckShore() // 
{
	ref chr;
	if (CheckAttribute(pchar, "questTemp.LongHappy") && !CheckAttribute(pchar, "questTemp.LongHappy.Offer") && LongHappy_CheckGirls())
	{
		if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) chr = characterFromId("Helena");
		else chr = characterFromId("Mary");
		
		if (IsOfficer(chr) && pchar.location == pchar.questTemp.LongHappy.Shore && GetCharacterItem(pchar, "potionwine") >= 2) return true;
	}
	return false;
}

bool LongHappy_CheckGoods() // 
{
	if (CheckAttribute(pchar, "questTemp.LongHappy.SmallMarry"))
	{
		if (GetSquadronGoods(pchar, GOOD_RUM) >= 50 && GetSquadronGoods(pchar, GOOD_WINE) >= 20 && sti(Pchar.money) >= 300000) return true;
	}
	else
	{
		if (GetSquadronGoods(pchar, GOOD_RUM) >= 100 && GetSquadronGoods(pchar, GOOD_WINE) >= 50 && sti(Pchar.money) >= 500000) return true;
	}
	return false;
}

bool LongHappy_CheckSaga() // 
{
	if (CheckAttribute(pchar, "questTemp.Saga.Late")) return false;
	if (CheckAttribute(pchar, "questTemp.Saga.CenturionSink")) return false;
	return true;
}

bool LongHappy_CheckTavernGoods() // 
{
	if (GetSquadronGoods(pchar, GOOD_RUM) >= sti(pchar.questTemp.LongHappy.MarryRum) && sti(Pchar.money) >= sti(pchar.questTemp.LongHappy.MarryMoney)) return true;
	return false;
}














