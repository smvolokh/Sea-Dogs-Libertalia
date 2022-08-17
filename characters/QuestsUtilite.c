// строковая дата, день_мес
string LastSpeakDate()
{
    return environment.date.day + " " + environment.date.month;
}
// Для диалогов НПС -->
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
// Для ГГ <--
void SaveCurrentQuestDateParam(string _quest)
{ // запись даты получения квеста
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
//Ввел еще одну функцию, т.к. нужны прошедшие минуты.
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
// ************* для неписей.
void SaveCurrentNpcQuestDateParam(ref _character, string _quest)
{ // запись даты получения квеста
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
    else {return 1000;}  // если нет ветки, то это значит черти когда было дело
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


// Поместить непися в компаньоны и тут же отправить его на выход из текущей локации.
void CharacterIntoCompanionAndGoOut(ref _mainCharacter, ref _compCharacter, string _group, string _locator, int _timeToGoOut, bool _compRemove)
{
    if (!bDisableFastReload) //чтобы не снимать запрет, если он установлен другим методом
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

void Character_into_companion()    // относится к методу выше.
{
    ref NPChar = characterFromID(PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Id);
    SetCompanionIndex(pchar, -1, getcharacterIndex(PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Id));
    if (PChar.GenQuest.CallFunctionParam.CharacterIntoCompanion.Remove == false)    {SetCharacterRemovable(npchar, false);}
	//снимать запрет, только если он установлен этим методом
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

// репутация плохого парня с границами
bool isBadReputation(ref _pchar, int _rep)
{
    if (GetCharacterPerkUsing(_pchar, "Trustworthy") || sti(_pchar.reputation.nobility) >= _rep)
    {
        return false;// good guy
    }
    return true;// bad guy
}

// --> ugeen  - генерация карт островов в сундуке каюты во время абордажа   07.07.09
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

//ugeen --> заполнить сундук в трюме квестовым барахлом
void FillQuestHoldBox(ref _location)
{
	_location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // нужно, чтоб не перетерлось
	
	int nShipType = sti(pchar.ship.type);

	if(CheckAttribute(pchar,"GenQuest.CaptainComission.CanFindChest"))
	{
		if(nShipType == sti(pchar.GenQuest.CaptainComission.ShipType) && !CheckAttribute(pchar,"GenQuest.CaptainComission.Treasure"))
		{
			Log_QuestInfo("Устанавливаем сундуки");
			DeleteAttribute(_location, "box1");
			_location.box1.items.chest = 3;
			pchar.GenQuest.CaptainComission.Treasure = true;
		}	
	}
}
// <-- ugeen

// заполнить сундук каюты во время абордажа
void FillAboardCabinBox(ref _location, ref _npchar)
{
    int     iTemp;
    bool    ok;
	float   nLuck;
	int 	iNation;
	int     iRnd; 
	string amap, amulet; // dlc
	
	_location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // нужно, чтоб не перетерлось
	// нужно отметить, что в сундуке сгенерятся рандомные вещи, этот код срабатывает потом и правит токо деньги
	
	ok = true;
	// заготовка под квест

	// маленькая пасхалка от меня -> ugeen  17.06.09
	if (CheckAttribute(_npchar, "Ship.Name") && _npchar.Ship.Name == "Кoлecо Фoртуны" )
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
		
	// Осады  homo 22/10/06	 
	if (findsubstr(_npchar.id, "SiegeCap_" , 0) != -1)
	{
	    aref aData, itm;
	    makearef(aData, NullCharacter.Siege);
	    string sGroup = "Sea_"+NationShortName(sti(aData.nation))+"SiegeCap_1";
	    ref rchar = Group_GetGroupCommander(sGroup);  //поиск текущего командера, он меняется от убиеня
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
			if (drand(4) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты, 20% 250912
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
			if (drand(4) == 2 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
        ok = false;

    }
    //homo <=

	// Jason: укладка важных предметов и просто вкусных пряников в сундуки квестовых кэпов.
	//работорговец, 2 эпизод
	if (_npchar.id == "CaptainSlaveAttack_2" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 20000;
		_location.box1.items.talisman8 = 1;
        ok = false;
	}
	//работорговец, письмо, 4 эпизод
	if (_npchar.id == "CapBrigAttack" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 5500;
		_location.box1.items.letter_1 = 1;
		ChangeItemDescribe("letter_1", "itmdescr_letter_1");
        ok = false;
	}
	//работорговец, линкор
	if (_npchar.id == "GaleonCap" && CheckAttribute(PChar, "questTemp.Slavetrader"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 2350;
		_location.box1.items.jewelry5 = 1000;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
		_location.box2.items.mineral31 = 2; //заговоренная кость
		DeleteAttribute(_location, "box3");
		_location.box3.items.mineral4 = 2;
		_location.box3.items.mineral12 = 10;
		_location.box3.items.mineral14 = 58;
		_location.box3.items.jewelry30 = 1; //золотой нож
		_location.box3.items.mineral1 = 12;
		_location.box3.items.berserker_potion = 1;
        ok = false;
	}
	
	//малява курьер
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
	// ложный след, галеон
	if (_npchar.id == "FalseTraceCap")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 15000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.recipe_totem_01 = 1;
		_location.box1.items.totem_01 = 1;
        ok = false;
	}
	// карибские нравы, Нинья
	if (_npchar.id == "PueblaCap")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 5000;
		_location.box1.items.gold_dublon = 20;
		_location.box1.items.spyglass2 = 1;
		_location.box1.items.mushket3 = 1; // patch-6
		_location.box1.items.newblade9 = 1; // Пират Либерталии
		_location.box1.items.pistol_02 = 1; // Пират Либерталии
		DeleteAttribute(_location, "box2");
		_location.box2.items.recipe_totem_06 = 1;
		_location.box2.items.totem_06 = 1;
        ok = false;
	}
	//Голландский Гамбит
	//серебряный конвой по английскому варианту
	if (_npchar.id == "SilverCap2" && CheckAttribute(PChar, "questTemp.HWIC.Eng"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 2000;
		_location.box1.items.gold_dublon = 80;
		_location.box1.items.clock1 = 1;
		_location.box1.items.mushket3 = 1; // patch-5
        ok = false;
	}
	
	//Мейфенг по английскому варианту
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
	
	//Валькирия без Флитвуда - против всех
	if (_npchar.id == "ValCap" && CheckAttribute(PChar, "questTemp.HWIC.Self"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 200000;//выкуп за Аби
		_location.box1.items.gold_dublon = 175;
		_location.box1.items.obereg_7 = 1;
		_location.box1.items.jewelry8 = 5;
		_location.box1.items.clock1 = 1;
		_location.box1.items.berserker_potion = 1;
        ok = false;
	}
	
	// Пиратская Сага
	// корвет Донована
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
	// полакр Марлин
	if (_npchar.id == "Cap_Marlin" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 12000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.map_terks = 1;
		_location.box1.items.amulet_1 = 1;
		_location.box1.items.recipe_totem_07 = 1;
		_location.box1.items.totem_07 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
	// корвет Бродяги
	if (_npchar.id == "Saga_Vagrant" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 15000;//
		_location.box1.items.gold_dublon = 50;
		_location.box1.items.letter_chad_1 = 1;
		ChangeItemDescribe("letter_chad_1", "itmdescr_letter_vargant");
		if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
        ok = false;
	}
	// Джекман, Центурион
	if (_npchar.id == "Jackman" && CheckAttribute(PChar, "questTemp.Saga"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;//
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.map_half_blaze = 1; // половинка карты
		_location.box1.items.splinter_nh = 1; // осколок календаря
		_location.box1.items.recipe_totem_10 = 1;
		_location.box1.items.map_normal = 1;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты 250912
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 250;
		_location.box2.items.witches_hammer = 1; //молот ведьм
		_location.box2.items.letter_parol = 1; // записка с паролем на рудник
		_location.box2.items.map_bermudas = 1;
		_location.box2.items.map_jam = 1;
		_location.box2.items.obereg_8 = 1;
		_location.box2.items.indian_9 = 1; 
		_location.box2.items.potion7 = 1;
		_location.box2.items.berserker_potion = 3;
        ok = false;
	}
	// Моллиган, Устрица
	if (_npchar.id == "Molligan" && CheckAttribute(PChar, "questTemp.Saga"))
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 5000;
		_location.box1.items.gold_dublon = 100;
		_location.box1.items.jewelry16 = 1;
		_location.box1.items.tailor_tool = 1; // портняжный набор
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
	
	// Суп из черепахи
	// Мартэн, Вольтижер
	if (_npchar.id == "Rober" && CheckAttribute(PChar, "questTemp.Terrapin"))
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 200000;
		_location.box1.items.Cromvel_depeshe = 1;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
	
	// Мартэн, Инфанта
	if (_npchar.id == "RoberCap2")
	{
		DeleteAttribute(_location, "box1");
		_location.box1.money = 12500;
		_location.box1.items.Cromvel_depeshe = 1;
		ritm = ItemsFromID("Cromvel_depeshe");
		ritm.Day = GetAddingDataDay(0,1,1);
		ritm.Month = GetAddingDataMonth(0,1,1);
		ritm.Year = GetAddingDataYear(0,1,1);
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.totem_04 = 1;
		_location.box2.items.recipe_totem_04 = 1; // patch-9
        ok = false;
	}
	
	// эскадра Кромвеля, мановар 141012
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
	
	// Защита Форт де Франса, мановар
	if (_npchar.id == "SPsiege_cap_1")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 2;
		_location.box1.items.map_martiniqua = 1;
		_location.box1.items.mushket3 = 1;
		if (MOD_SKILL_ENEMY_RATE > 7) _location.box1.items.cirass4 = 1; 
		if (MOD_SKILL_ENEMY_RATE < 7) _location.box1.items.cirass3 = 1; 
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.cannabis7 = 1; // мангароса
		_location.box2.items.totem_11 = 1;
		_location.box2.items.recipe_totem_11 = 1; 
        ok = false;
	}
	// Страж Истины
	// ТГ у Сан-Антонио
	if (_npchar.id == "Diegohaleon_cap")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 10000;
		_location.box1.items.Chest = 1;
		_location.box1.items.map_cuba = 1;
		_location.box1.items.blade_17 = 1;
		if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
	// флагман эскадры Диего
	if (_npchar.id == "GOT_catochecap_1")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 3;
		_location.box1.items.icollection = 2;
		_location.box1.items.map_beliz = 1;
		_location.box1.items.cirass7 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.jewelry2 = 100;
		_location.box2.items.cannabis7 = 1; // мангароса
		_location.box2.items.talisman6 = 1;
        ok = false;
	}
	
	// фрегат Патерсона - Фортуна
	if (_npchar.id == "Willy")
	{
        DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.Chest = 5;
		_location.box1.items.map_beliz = 1;
		_location.box1.items.cirass7 = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		DeleteAttribute(_location, "box2");
		_location.box2.items.bussol = 1;
		_location.box2.items.clock2 = 1;
		_location.box2.items.jewelry2 = 100;
		_location.box2.items.cannabis7 = 1; // мангароса
		_location.box2.items.potion7 = 1;
        ok = false;
	}
	
	//Контркурьер, губерский генер
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
	
	//Контрарсенал, губерский генер
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
	
	//Контрпират, губерский генер
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
	
	//Контрпассажир, губерский генер
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
	
	//Калеуче
	if (_npchar.id == "Kaleuche_khaelroacap")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 100000;
		_location.box1.items.blade_28 = 1;
		DeleteAttribute(_location, "box2");
		_location.box2.items.gold_dublon = 5000;
        ok = false;
	}
	
	// Addon-2016 Jason, французские миниквесты (ФМК)
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

	// Addon 2016-1 Jason Пиратская линейка
	// полакр Тореро
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
	// шхуна Кантавро
	if (_npchar.id == "Cabanos")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 550;
		_location.box1.items.gold_dublon = 10;
		_location.box1.items.totem_09 = 1;
		_location.box1.items.jewelry8 = 15;
		_location.box1.items.jewelry41 = 1; // патч 17/1
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.clock1 = 1;
		if (drand(2) == 2) _location.box2.items.cirass3 = 1;
        ok = false;
	}
	// бригантина Утрехт
	if (_npchar.id == "Cap_Utreht")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 7800;
		_location.box1.items.gold_dublon = 30;
		_location.box1.items.indian_11 = 1;
		_location.box1.items.chest_open = 5;
		_location.box1.items.pistol3 = 1; // патч 17/1
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.purse1 = 1;
		if (drand(4) == 1) _location.box2.items.pistol2 = 1;
        ok = false;
	}
	// Розбоом
	if (_npchar.id == "Mtr_PasqCap_2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 5300;
		_location.box1.items.gold_dublon = 10;
		_location.box1.items.obereg_8 = 1;
		_location.box1.items.pistol5 = 1; // патч 17/1
		_location.box1.items.jewelry42 = 1; // патч 17/1
		_location.box1.items.map_Curacao = 1;
		
		DeleteAttribute(_location, "box2");
		_location.box2.items.spyglass2 = 1;
		if (drand(3) == 1) _location.box2.items.blade_16 = 1;
        ok = false;
	}
	// голландец по Игнасио
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
	// Торо де Оро
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

	//ОЗГ, пинас Крысы, драгоценности
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
	// Jason НСО
	// флагман испанской эскадры у Порт Пренса
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
	// ТГ добавочный у Порт Пренса
	if (_npchar.id == "PatriaPP_Seacap_add")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 5000;
		_location.box1.items.mushket2 = 1;
		_location.box1.items.indian_1 = 1;
		
        ok = false;
	}
	// флагман эскадры голландцев у сан-мартина
	if (_npchar.id == "Patria_SanMartinCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 7000;
		_location.box1.items.cannabis7 = 1; // мангароса
		_location.box1.items.indian_10 = 1;
		
        ok = false;
	}
	// флагман эскадры-погони голландцев 
	if (_npchar.id == "Patria_DiplomatCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 13000;
		_location.box1.items.obereg_10 = 1;
		_location.box1.items.harpoon = 100;
		
        ok = false;
	}
	// Олифант 
	if (_npchar.id == "Patria_SiegeCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;
		_location.box1.items.Chest = 3;
		_location.box1.items.map_nevis = 1;
		_location.box1.items.cirass3 = 1;
		_location.box1.items.berserker_potion = 2;
		if (CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
		{
			amap = SelectAdmiralMaps();
			if (amap != "") _location.box1.items.(amap)	= 1;
		}
		
        ok = false;
	}
	// флагман испанцев в осаде
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
	// 1 ост-ндец с рабами
	if (_npchar.id == "PatriaSlaveCap2")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 10000;
		_location.box1.items.obereg_11 = 1;
		_location.box1.items.obereg_6 = 1;
		_location.box1.items.Mineral30 = 50;
		
        ok = false;
	}
	// 2 ост-ндец с рабами
	if (_npchar.id == "PatriaSlaveCap3")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 12000;
		_location.box1.items.obereg_9 = 1;
		_location.box1.items.indian_6 = 1;
		_location.box1.items.Mineral30 = 50;
		
        ok = false;
	}
	// ТГ Стайвесанта Фредерик
	if (_npchar.id == "Patria_CuracaoCap1_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 30000;
		_location.box1.items.Chest = 2;
		_location.box1.items.cannabis7 = 1; // мангароса
		_location.box1.items.recipe_GunEchin = 1;
		_location.box1.items.GunEchin = 100;
		
        ok = false;
	}
	// Jason Долго и счастливо
	if (_npchar.id == "LH_BarbSeaCap_1")
	{
		 DeleteAttribute(_location, "box1");
        _location.box1.money = 50000;
		_location.box1.items.Chest = 5;
		_location.box1.items.map_bermudas = 1;
		if (drand(1) == 0 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
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
		_location.box2.items.cannabis7 = 2; // мангароса
		_location.box2.items.potion7 = 1;
		_location.box2.items.berserker_potion = 1;

        ok = false;
	}	

    // пиратка, квест №7. драгоценности в каюту
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
    // пиратка, квест №7. драгоценности в каюту
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
	//тюремный эскорт
	if (_npchar.id == "PrisonEscort_Captain" && CheckAttribute(PChar, "questTemp.PrisonEscort_quest"))
	{
        DeleteAttribute(_location, "box1");
        _location.box1.items.PrisEscort_book = 1;
        _location.box1.items.ArtRing1 = 1;
        _location.box1.money = 9100;
        _location.box1.items.map_martiniqua = 1;
        ok = false;
	}
	// квест Аскольда.
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
        // трем все в сундуке
        DeleteAttribute(_location, "box1");
        // кладем супер хрень
        _location.box1.items.indian11 = 1;
        _location.box1.money = 66666;
        _location.box1.money = 66;
        _location.box1.items.sculMa3 = 1;
        _location.box1.items.cannabis7 = 1; // мангароса
        ok = false;
	}
}
	
    if (ok) // не квестовый
    {
    	// код для всех
		
    	iTemp = GetCharacterShipClass(_npchar);
		iNation = sti(_npchar.nation);		

		if(iNation == PIRATE)
		{
			nLuck   = GetCharacterSkillToOld(Pchar, SKILL_FORTUNE);			
			if (nLuck > rand(250) && GetCharacterItem(pchar, "map_full") == 0)  // шанс 1/30 
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
		
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "Trade")  // торговец
		{
			_location.box1.money = (10 - iTemp) * 200 + rand(10 - iTemp) * 2000 + rand(10)*50 + rand(6 - iTemp) * 4000;
			if(rand(5) > 2)
			{
				_location.box1.items.gold_dublon = rand(10) + 4;
				if(drand(20) == 15) _location.box1.items.rat_poison = 1;		
			}	
		}
		else // все остальные
		{
			if(rand(3) == 1) _location.box1.items.gunpowder = 5 + rand(10);
			_location.box1.money = (10 - iTemp) * 90 + rand((10 - iTemp) * 2000);
			if(rand(4) == 1)
			{
				_location.box1.items.gold_dublon = rand(5) + 2;			
			}
		}				
		if (2-sti(RealShips[sti(_npchar.ship.type)].Class) > 0) // 1 класс
		{
			if (drand(2) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "war" && 2-sti(RealShips[sti(_npchar.ship.type)].Class) == 0) // военный 2 класс
		{
			if (drand(4) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "war" && 3-sti(RealShips[sti(_npchar.ship.type)].Class) == 0) // военный 3 класс
		{
			if (drand(6) == 1 && CheckAttribute(pchar, "questTemp.AdmiralMap")) // адм.карты
			{
				amap = SelectAdmiralMaps();
				if (amap != "") _location.box1.items.(amap)	= 1;
			}
		}
		if (CheckAttribute(pchar, "questTemp.Persian.skimitar") && drand(20) == 5 && 3-sti(RealShips[sti(_npchar.ship.type)].Class) >= 0) // 3 класс и выше. Килидж - 5% 021012
		{
			_location.box1.items.blade_23 = 1;
		}
		if (CheckAttribute(_npchar, "Ship.Mode") && _npchar.Ship.Mode == "Trade" && drand(20) == 11 && 3-sti(RealShips[sti(_npchar.ship.type)].Class) >= 0) // 3 класс и выше кислота и спирт
		{
			_location.box1.items.mineral28 = rand(2);
			_location.box1.items.mineral29 = rand(2);
		}
		if (CheckAttribute(pchar, "questTemp.Caleuche.SeekAmulet") && drand(3) == 3) // первый амулет на Калеуче
		{
			_location.box1.items.kaleuche_amulet1 = 1;
		}
    }
}

// ugeen --> вычисление ранга квестовых проитвников в зависимости от ранга ГГ и уровня сложности
int SetQuestCharacterRank()
{
	int rank = 25 + makeint(sti(pchar.rank)*(0.1 + MOD_SKILL_ENEMY_RATE));

	return rank;
}
// <-- ugeen

// ==> две функции Эдди для крутизны невероятной.
void FantomMakeCoolSailor(ref _Character, int _ShipType, string _ShipName, int _CannonsType, int _Sailing, int _Accuracy, int _Cannons)
{
    _Character.Ship.Cannons.Type = _CannonsType;
	_Character.skill.Sailing  = GetCoffDiff(_Sailing, SKILL_MAX);
	_Character.skill.Accuracy = GetCoffDiff(_Accuracy, SKILL_MAX);
	_Character.skill.Cannons  = GetCoffDiff(_Cannons, SKILL_MAX);
    _Character.DontRansackCaptain = true; //квестовые не сдаются
    _Character.SinkTenPercent     = false; // не тонуть при 10%, не убегать в бою
    _Character.AboardToFinalDeck  = true; // абордаж всегда
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

    DeleteAttribute(_Character, "ship.sails");// убрать дыры на парусах
    DeleteAttribute(_Character, "ship.blots");
    DeleteAttribute(_Character, "ship.masts");// вернуть сбытые мачты
	DeleteAttribute(_Character, "ship.hulls");// вернуть сбитые элементы корпуса
    DeleteAttribute(_Character, "Killer.status"); // снять аттрибут ''был захвачен на абордаж''
    _Character.questTemp.abordage = 0; //снять аттрибут отказа повторного захвата
   	DeleteAttribute(_Character, "Abordage.Enable"); //снять невозможноть абордажа
}

//Jason, функция уменьшенного кулсейлора + скилл защиты и абордажа
void FantomMakeSmallSailor(ref _Character, int _ShipType, string _ShipName, int _CannonsType, int _Sailing, int _Accuracy, int _Cannons, int _Grappling, int _Defence)
{
    _Character.Ship.Cannons.Type = _CannonsType;
	_Character.skill.Sailing  = GetCoffDiff(_Sailing, SKILL_MAX);
	_Character.skill.Accuracy = GetCoffDiff(_Accuracy, SKILL_MAX);
	_Character.skill.Cannons  = GetCoffDiff(_Cannons, SKILL_MAX);
	_Character.skill.Grappling  = GetCoffDiff(_Grappling, SKILL_MAX);
	_Character.skill.Defence  = GetCoffDiff(_Defence, SKILL_MAX);
	
    _Character.DontRansackCaptain = true; //квестовые не сдаются
    _Character.SinkTenPercent     = false; // не тонуть при 10%, не убегать в бою
    _Character.AboardToFinalDeck  = true; // абордаж всегда
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

    DeleteAttribute(_Character, "ship.sails");// убрать дыры на парусах
    DeleteAttribute(_Character, "ship.blots");
    DeleteAttribute(_Character, "ship.masts");// вернуть сбытые мачты
	DeleteAttribute(_Character, "ship.hulls");// вернуть сбытые элементы корпуса
    DeleteAttribute(_Character, "Killer.status"); // снять аттрибут ''был захвачен на абордаж''
    _Character.questTemp.abordage = 0; //снять аттрибут отказа повторного захвата
   	DeleteAttribute(_Character, "Abordage.Enable"); //снять невозможноть абордажа
}

void FantomMakeCoolFighter(ref _Character, int _Rank, int _Fencing, int _Pistol, string _Blade, string _Gun, string _Bullet, float _AddHP)
{
    _Character.rank = GetCoffDiff(_Rank, 1000);
    _Character.skill.FencingS  = GetCoffDiff(_Fencing, SKILL_MAX);
    _Character.Skill.FencingL  = GetCoffDiff(sti(_Character.skill.FencingL), SKILL_MAX);
    _Character.Skill.FencingH  = GetCoffDiff(sti(_Character.skill.FencingH), SKILL_MAX); 
    _Character.skill.Pistol = GetCoffDiff(_Pistol, SKILL_MAX);
    _Character.skill.Fortune = GetCoffDiff(_Pistol, SKILL_MAX); //zagolski. если умеет хорошо стрелять из пистоля, то умеет и хорошо от него защищаться
	_Character.chr_ai.hp = stf(_Character.chr_ai.hp) + GetCoffDiff(_AddHP, 5000);
	_Character.chr_ai.hp_max = stf(_Character.chr_ai.hp_max) + GetCoffDiff(_AddHP, 5000);
	SetCharacterPerk(_Character, "Energaiser"); // скрытый перк дает 1.5 к приросту энергии, дается ГГ и боссам уровней
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
		if(HasSubStr(_Gun, "mushket")) // у мушкетеров отдельная логика экипировки
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
				AddItems(_Character, sGunpowder, 30 + rand(20)); // Warship. Порох
			}	
			LAi_SetCharacterUseBullet(_Character, _Bullet);
		}
	}

    FaceMaker(_Character);
	CirassMaker(_Character);
    SetNewModelToChar(_Character);  // перерисуем модель на лету
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
// заполнение сундуков и рандитема по квесту
bool SetLocationQuestRandItem(int _index, aref _location, string _locatorName, aref al) // al - ветка локатора из модели, остальное тоже из обратотки локации
{   // метод редактировать не нужно - все задается в квестах
	string  lastSpawnTimeString;
    int     n;
	string  itemId;
	aref checkAref

	/* Пример
 	pchar.GenQuestRandItem.QC_Port = true;
    pchar.GenQuestRandItem.QC_Port.randitem1 = "pistol6";
    // если нужно чтоб было всегда
	pchar.GenQuestRandItem.QC_Port.stay = true; - тереть потом эту ветку самому по квесту
	
    QC_Port - локация где
    randitem1 - локатор
    pistol6 - предмет
    
    если нужно сразу несколько локаторов, то
    pchar.GenQuestRandItem.QC_Port.randitem1 = "pistol6";
    pchar.GenQuestRandItem.QC_Port.randitem2 = "pistol1";
 	*/
	lastSpawnTimeString = _location.id;
    if (CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString) && CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString +"."+_locatorName))
    {
        itemId = pchar.GenQuestRandItem.(lastSpawnTimeString).(_locatorName);
        if (!CheckAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString +".stay"))
        {
			//--> fix eddy. нельзя было положить в несколько локаторов
			DeleteAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString + "." + _locatorName); // если токо один раз
			makearef(checkAref,  pchar.GenQuestRandItem.(lastSpawnTimeString));
			if (GetAttributesNum(checkAref) == 0) DeleteAttribute(pchar , "GenQuestRandItem." + lastSpawnTimeString);
        }
        // только один предмет!!!!!!!!!!!!
        n = SetRandItemShow(_index, al, itemId); // вывести 3д модель в лакацию, если модель вообще есть
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
// загрузить модель
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

// заполнить сундук
bool SetLocationQuestBox(ref _location, string _locatorName)
{   // метод редактировать не нужно - все задается в квестах
    bool    ok = false;
    string  locId;
    aref    arToBox;
    aref    arFromBox;

    /* Пример
 	pchar.GenQuestBox.Havanna_town_04 = true;
    pchar.GenQuestBox.Havanna_town_04.box1.items.jewelry1 = 4;
    pchar.GenQuestBox.Havanna_town_04.box1.items.mineral2 = 10;
    // если нужны деньги, иначе не заполнять
	pchar.GenQuestBox.Havanna_town_04.box1.money          = 100;
    // если нужно чтоб было всегда
	pchar.GenQuestBox.Havanna_town_04.stay = true; - тереть потом эту ветку самому по квесту

    Havanna_town_04 - локация где
    box1 - локатор
    items - список предметов
    
    если нужно сразу несколько локаторов, то
    pchar.GenQuestBox.Havanna_town_04.box2.items.jewelry1 = 34;
 	*/
 	locId  = _location.id;
    if (CheckAttribute(pchar , "GenQuestBox." + locId) && CheckAttribute(pchar , "GenQuestBox." + locId + "." + _locatorName))
    {
        Log_TestInfo("SetLocationQuestBox");

        makearef(arToBox, _location.(_locatorName));
        makearef(arFromBox, pchar.GenQuestBox.(locId).(_locatorName));
        CopyAttributes(arToBox, arFromBox);
        _location.(_locatorName) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()); // таймер, чтоб не затерлись рандомом при выходе из локации
        if (!CheckAttribute(pchar , "GenQuestBox." + locId +".stay"))
        {
			//--> fix eddy. нельзя было положить в несколько локаторов
			DeleteAttribute(pchar , "GenQuestBox." + locId + "." + _locatorName); // если токо один раз
			makearef(arToBox,  pchar.GenQuestBox.(locId));
			if (GetAttributesNum(arToBox) == 0) DeleteAttribute(pchar , "GenQuestBox." + locId);
        }
        return true;
    }
    return false;
}

// ==> Метод открытия\закрытия локаторов релоад. Если _flag=true - закрыть локатор, если _flag=false - открыть.
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

//===>>> Функции по работе с диалоговыми файлами. Эдди. ================================================================
// == _strNormal - обычная строка диалога
// == _strBad1, _strBad2, _strBad3 - строки степени возмущения,  "" и "none" - базовый набор.
// == _kind - вид возмущения: "repeat" - снимается на следующий день при условии, что НПС вконец не разозлился (не задействован анги-файл).
//                            "quest"  - квестовые повторялки, не снимаются на следующий день, но может быть задан срок примирения после перевода на ангри.
//                            "block"  - реакцию НПС на повторные клики без включения ангри, для того, чтобы обозначить интеллект, но не ругаться. Ангри вообще не делать.
//                            "cycle"  - крутим цикл из повторялок, ангри не заряжать. На след. день все снимается.
// == _terms для "repeat" и "quest" - сроки в днях примирения само-собой после задействоания ангри-файла, если == 0, то ругань навсегда (примерение только через подарки).
//    _terms для "block" - сроки возврата в норму в днях, если 0 - навсегда.
// == _character и _Node - npchar и Dialog.CurrentNode
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
    if (_kind == "cycle" || _kind == "repeat") //на след.день все снимается.
    {
        if (GetNpcQuestPastDayParam(_character, strTemp) >= 1)
        {
            _character.quest.repeat.(_Node) = 0;
            _character.quest.repeat.(_Node).ans = 0;
        }
    }
    else
    {
        if (GetNpcQuestPastDayParam(_character, strTemp) >= _terms && _terms!=0 && _kind != "quest") //снятие по "block"
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
                strBack = LinkRandPhrase("Я не хочу говорить об одном и том же по нескольку раз.",
                          "Мы уже говорили об этом.",
                          "Эту тему мы уже обсуждали.");
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
                strBack = LinkRandPhrase("Еще раз повторяю, что я не хочу говорить об одном и том же по десять раз!",
                          "Повторяю, мы уже говорили об этом!",
                          "Я же говорю, мы это уже обсуждали. Проблемы с памятью?");
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
                strBack = LinkRandPhrase("Я не намерен более с вами общаться.",
                          "Не буду с тобой больше разговаривать!",
                          "Ты меня порядком разозлил"+ GetSexPhrase("","а") +", никакого общения более.");
            }
            else
            {
                strBack = _strBad3;
            }
            // ==> Реакция на третье повторение.
            if (_kind == "cycle") //снова на первую строку.
            {
			    _character.quest.repeat.(_Node) = 0;
            }
			else
            {
                if(_kind != "block") //если block, то опять в последнюю строку
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
                strBack = LinkRandPhrase("Хорошо, приятель.",
                          "Как скажешь.",
                          "Не то ляпнул"+ GetSexPhrase("","а") +", извини...");
            }
            else
            {
                strBack = _strBad1;
            }
        break;
        case "2":
            if (_strBad2 == "none" || _strBad2 == "")
            {
                strBack = LinkRandPhrase("Хорошо, хорошо. Только не кипятись.",
                          "Как скажешь, только не надо кричать.",
                          "Извини, что-то я сегодня не в форме... Голова с утра раскалывается...");
            }
            else
            {
                strBack = _strBad2;
            }
        break;
        case "3":
            if (_strBad3 == "none" || _strBad3 == "")
            {
                strBack = LinkRandPhrase("Как знаешь.",
                          "Очень жаль...",
                          "Невелика потеря.");
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

// возможны только две переходные ноды: _GoNode1 и _GoNode2, третья не нужна, т.к. идет сразу в ангри-файл.
// неверно, оставил третью ноду для циклов и прочего.
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

// _Node - имя ноды, идентификатор текущей ангри. Если метод вызывается не в диалоговом файле, то == "none".
void CharacterAddAngry(ref _character, string _Node, string _kind, int _terms)
{
    if (_kind == "repeat" || _kind == "quest")
    {
        DeleteAttribute(_character, "angry");
        _character.angry.kind = _kind;
        _character.angry.name = _Node; //и имя ноды тоже, для расфасовки разных ангри
        if (_terms != 0) // если == 0, то ссора непроходящая с течением времени.
        {
            _character.angry.terms = _terms;
            SaveCurrentNpcQuestDateParam(_character, "angry.terms");
            if (_terms < 10) // размер вознаграждения за примирение, анти с/л
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

//В условиях возможного тотального применения ангри по квестам, нужно подстраховаться.
//Если нода дается НПС в момет, когда у него задействован ангри, то нода будет возвращена после примирения.
//Соотв. менять ноды желательно данным методом.
void QuestSetCurrentNode(string _chID, string _Node)
{
    ref chref = characterFromID(_chID);
    if (CheckAttribute(chref, "angry")) chref.dialog.TempNode = _Node;
    else chref.dialog.currentnode = _Node;
}

// фраза от пола НПС
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
// фраза от пола ГГ
string GetSexPhrase(string StrMan, string StrWoman)
{
    return NPCharSexPhrase(PChar, StrMan, StrWoman);
}

//Jason --> фраза от нации персонажа
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
//<-- фраза от нации персонажа
//<<<=== Функции по работе с диалоговыми файлами. =======================================================================


// Временно сохранить все данные о нашем корабле в памяти
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

// Восстановить данные о нашем старом корабле из памяти
//------------------------------------------------------
bool RestoreTempRemoveParam(ref _refCharacter, string _param)
{
    string sParam = "TmpRemember" + _param;
    
	if( !CheckAttribute(_refCharacter, sParam) ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.(_param));
	aref srcRef; makearef(srcRef, _refCharacter.(sParam));

	DeleteAttribute(_refCharacter, _param);
	//--> eddy. структура быть должна, иначе вылет в винду.
	_refCharacter.(_param) = "";
	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter, sParam);
	return true;
}

// установка отмены боевки в резиденции при захвате города
// ВАЖНО: работает только не в пиратском городе - иначе это просто мятеж и губернатора там нет вообще
void SetCaptureResidenceQuest(string _city, string _method, bool _majorOff)
{
    PChar.GenQuestFort.ResidenceQuest.(_city) = true;
    // убирать ли губернатора из локации вообще, он пропадет, но потом обратно пропишется, чтоб не рушить мир игры.
    PChar.GenQuestFort.ResidenceQuest.(_city).MayorOff = _majorOff;
    if (_method != "")
    {
        PChar.GenQuestFort.ResidenceQuest.(_city).method = _method;
	}
}

// вернем диалог после разговора и спрячем
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
// функции из квест_реакшн
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
	        Ship_FlagRefresh(officer); //флаг на лету
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
{// отсортировать предметы в кармане, сундуке
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

    makearef(arFromChar, NPChar.equip); // экипировка
    int iMax = GetAttributesNum(arFromChar);
    for(i=0; i<iMax; i++)
    {
        curItem = GetAttributeN(arFromChar, i);
        attr = GetAttributeValue(curItem);
        if (attr != "") //патенты клинит
        {
        	NPChar.Items.(attr) = sti(rObj.Items.(attr));
        }
    }
    // неоптимальная сортировка по индексу itm.SortIndex
	// размерность индекса определяется автоматом - длжен быть непрерывен!!, начинается с 1 - целое число
	ok = true;
	iSortIndex = 1;
	while (iSortIndex < 3)// 2 типа
	{
		ok = false;
		for (i=0; i<TOTAL_ITEMS; i++)
		{
			// Warship 11.05.09 fix для новой системы предметов
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
    // все остальные
    for (i=0; i<TOTAL_ITEMS; i++)
	{
		// Warship 11.05.09 fix для новой системы предметов
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
// установка квестовых товаров и цен
void SetQuestGoodsToStore(ref refStore)
{
	string    goodName;
	// пример использования по квест_реакшн
	/*
	pchar.GenQuest.StoreGoods.StoreIdx = Bridgetown_STORE;
	pchar.GenQuest.StoreGoods.NowNeedToBe = true;
	*/
	if (CheckAttribute(pchar, "GenQuest.StoreGoods.StoreIdx") && refStore.index == pchar.GenQuest.StoreGoods.StoreIdx)
	{
        // пример обработки события pchar.GenQuest.StoreGoods.StoreIdx = LaVega_STORE;
		/*if (CheckAttribute(pchar, "GenQuest.StoreGoods.NowNeedToBe")) // состояние говорящие, то нужно делать
		{
		    DeleteAttribute(pchar, "GenQuest.StoreGoods"); // одноразовая операция, трем обе ветки
		    goodName = Goods[GOOD_RUM].Name;
		    refStore.Goods.(goodName).Quantity       = 666;
		    // цена из обратного вычисления 20 в модификатор
			refStore.Goods.(goodName).RndPriceModify = GetStoreGoodsRndPriceModify(refStore, GOOD_RUM, PRICE_TYPE_BUY, pchar, 20);
		}  */
		if (CheckAttribute(pchar, "GenQuest.StoreGoods.Starting")) // заполнение магазина Форт де Франса на старте
		{
		    DeleteAttribute(pchar, "GenQuest.StoreGoods"); // одноразовая операция, трем обе ветки
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
		if (CheckAttribute(pchar, "GenQuest.StoreGoods.Guardoftruth")) // ваниль на Гваделупе
		{
			DeleteAttribute(pchar, "GenQuest.StoreGoods"); // одноразовая операция, трем обе ветки
		    goodName = Goods[GOOD_CINNAMON].Name;
		    refStore.Goods.(goodName).Quantity = 127;
		}		
	}
}

// метод обработки капитана в каюте на абордаже. Ставим проверку на минНР + дилог
// refChar - это фантом, а не реальный кэп, он копия, диалог от настоящего, но ИД и индекс не его, а фантомный, поэтому управляем имено этим актером
// CaptanId - реальный ИД кэпа, запомненный в момент копирования.
void SetQuestAboardCabinDialog(ref refChar)
{
	// пример. тут задаю для теста, все это должно быть на изначальном капитане по квестам
	//refChar.DontClearDead      = true;
	//refChar.SaveItemsForDead   =   true;
	//TakeNItems(refChar, "Chest", 1);
	// пример. <--

	if (CheckAttribute(refChar, "CaptanId"))
	{
        pchar.GenQuest.QuestAboardCabinDialogIdx = refChar.index;
        // как использовать, пример
		/*if (true) // true - для теста, должно быть это CheckAttribute(pchar, "квестовая ветка, если нужно") && refChar.CaptanId == "IdNPC")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
            refChar.Dialog.Filename    = "Capitans_dialog.c";   // это нужно задать на изначальном кэпе в др месте
	    	refChar.Dialog.CurrentNode = "QuestAboardCabinDialog";
	    	// все остальное в диалоге, по образцу
		}*/
		//капитан по квесту мэра на поиск и уничтожение пирата.
		if (refChar.CaptanId == "MQPirate" && CheckAttribute(pchar, "GenQuest.DestroyPirate"))
		{
		    LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.dialog.currentnode = "DestroyPirate_Abordage";
		}
		//засада на ГГ по наводке на купца homo
		if (findsubstr(refChar.CaptanId, "_QuestMerchant" , 0) != -1  && trap)
		{
		    LAi_SetCheckMinHP(refChar, 30, true, "QuestAboardCabinDialog");  // сколько НР мин
		    refChar.dialog.filename = "Capitans_dialog.c";  //fix homo 23/03/07
			refChar.dialog.currentnode = "MerchantTrap_Abordage";
		}
		//квест возврата украденного корабля
		if (findsubstr(refChar.CaptanId, "SeekCap_" , 0) != -1)
		{
		    LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.CurrentNode = "SeekCap"; //даем абордажную ноду
		}
		//поисковый генератор
		if (findsubstr(refChar.CaptanId, "SeekCitizCap_" , 0) != -1)
		{
			if (refChar.quest.SeekCap == "NM_battle")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
				refChar.Dialog.CurrentNode = "NM_battleBoard"; //даем абордажную ноду
			}
			if (refChar.quest.SeekCap == "NM_prisoner")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
				refChar.Dialog.CurrentNode = "NM_prisonerBoard"; //даем абордажную ноду
			}
			if (refChar.quest.SeekCap == "manRapeWife")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
				refChar.Dialog.CurrentNode = "RapeWifeCap_Board"; //даем абордажную ноду
			}
		    if (refChar.quest.SeekCap == "womanRevenge")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
				refChar.Dialog.CurrentNode = "RevengeCap_board"; //даем абордажную ноду
			}
			if (refChar.quest.SeekCap == "womanPirates")
			{
				LAi_SetCheckMinHP(refChar, 5, true, "QuestAboardCabinDialog");  // сколько НР мин
				refChar.Dialog.CurrentNode = "PiratesCap_Board"; //даем абордажную ноду
			}
		}
		//генератор "Продажный патруль" 
		if (refChar.CaptanId == "PirateCapt")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		}
		
		// Warship Генер "Пираты на необитайке"
		if(refChar.CaptanId == "PiratesOnUninhabited_BadPirate")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "PiratesOnUninhabited_46"; //даем абордажную ноду
		}
		
		// Генерратор "Поручение капитана ''Выкуп'' или ''Операция Галеон''"
		if(CheckAttribute(pchar,"GenQuest.CaptainComission") && pchar.GenQuest.CaptainComission == "Begin")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "CaptainComission_1"; //даем абордажную ноду
		}
		
		if(refChar.CaptanId == "ShipWreck_BadPirate")
		{
			LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "GenQuests_Dialog.c";
			refChar.Dialog.CurrentNode = "ShipWreck_50"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Slaveshorecap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "TakeShoreCap"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "RatCaptain")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Rat_talk"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Jafar")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Ja_talk"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Fleetwood")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\Fleetwood.c";
			refChar.Dialog.CurrentNode = "Fleetwood_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "JacobBerg")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\JacobBerg.c";
			refChar.Dialog.CurrentNode = "JacobBerg_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Lucas")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\LucasRodenburg.c";
			refChar.Dialog.CurrentNode = "Lucas_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Knippel")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\Knippel.c";
			refChar.Dialog.CurrentNode = "Knippel_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "CureerCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Cureer_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Longway")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\HollandGambit\Longway.c";
			refChar.Dialog.CurrentNode = "Longway_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "FalseTraceCap")//ложный след
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\LineMiniQuests\FalseTrace.c";
			refChar.Dialog.CurrentNode = "FalseTrace_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Vaskezs_helper")//португалец
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Portugal_dialog.c";
			refChar.Dialog.CurrentNode = "VaskezsHelper_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "ConJuan")//цена чахотки
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\LineMiniQuests\Consumption.c";
			refChar.Dialog.CurrentNode = "Juan_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "MarginCap")//захват пассажиров
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Marginpassenger.c";
			refChar.Dialog.CurrentNode = "MarginCap_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "ContraPassCap")//генер губера - ОЗГ - пассажир
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "MayorQuests_dialog.c";
			refChar.Dialog.CurrentNode = "ContraPass_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Donovan")//Сага, корвет Донована
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Saga\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Donovan_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Jackman")//Сага, Джекман
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Mayor\Jackman.c";
			refChar.Dialog.CurrentNode = "Jackman_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "RoberCap2")//Черепаха, Мартэн
		{
		    LAi_SetCheckMinHP(refChar, 100, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Sharlie\Terrapin.c";
			refChar.Dialog.CurrentNode = "rober_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Kaleuche_khaelroacap")//Калеуче
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Caleuche_dialog.c";
			refChar.Dialog.CurrentNode = "CaleucheCap_3"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "FMQG_Juan" && CheckAttribute(pchar,"questTemp.FMQG") && pchar.questTemp.FMQG != "fail") // Addon-2016 Jason ФМК-Гваделупа
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\LineMiniQuests\FMQ_Guadeloupe.c";
			refChar.Dialog.CurrentNode = "Juan"; //даем абордажную ноду		
		}
		// Addon 2016-1 Jason Пиратская линейка
		if (refChar.CaptanId == "Ignasio" && CheckAttribute(pchar, "questTemp.Mtraxx.Corrida.Logbook"))
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\Roger.c";
			refChar.Dialog.CurrentNode = "ignasio_boarding"; //даем абордажную ноду		
		}
		
		//капитан шхуны Лебедь Отступники веры.(Чарли Вейн.)
		if (refChar.CaptanId == "RobertBlake")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		    refChar.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
		    refChar.Dialog.CurrentNode = "RobertBlake"; //даем абордажную ноду
		}

///////////////////////////////////////////////////////////////////

		//зачарованный город, штурм фрегата с Данькой
		if (refChar.CaptanId == "Avrora")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
                                           DoQuestFunctionDelay("ZOM_ATTACK", 0.3);
		}

		//капитан брига "Черная Горгулья"
		if (refChar.CaptanId == "BlueBirdCapitain" && pchar.questTemp.BlueBird == "toSeaBattle")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		}
		//капитан брига "Черная Горгулья"
		if (refChar.CaptanId == "BlueBirdTrader" && pchar.questTemp.BlueBird == "attackFleut")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		}
		//пиратка, Эдвард Лоу на бриге Морской Волк
		if (refChar.CaptanId == "EdwardLoy" && pchar.questTemp.piratesLine == "KillLoy_SeaWolfBattle")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		}
		//пиратка, квест №7, кэп, продавший Ласточку
		if (refChar.CaptanId == "LeonCapitain" && pchar.questTemp.piratesLine == "Soukins_seekLeon")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
		}
		if (refChar.CaptanId == "Slaveshorecap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "TakeShoreCap"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "RatCaptain")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Rat_talk"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "Jafarry")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
			refChar.Dialog.CurrentNode = "Ja_talk"; //даем абордажную ноду		
		}

		if (refChar.CaptanId == "TerraxCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Terrax_abordage"; //даем абордажную ноду		
		}

		if (refChar.CaptanId == "FiamatarCap")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
			refChar.Dialog.CurrentNode = "Fiamatar_abordage"; //даем абордажную ноду		
		}
		if (refChar.CaptanId == "GhostCapt" && CheckAttribute(pchar,"GenQuest.GhostShip.Prize"))
		{
		    LAi_SetCheckMinHP(refChar, 50, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.CurrentNode = "GhostCapt_LastDialog";
		}
		// Jason Долго и счастливо
		if (refChar.CaptanId == "LH_BarbSeaCap_1")
		{
		    LAi_SetCheckMinHP(refChar, 10, true, "QuestAboardCabinDialog");  // сколько НР мин
			refChar.Dialog.FileName = "Quest\LongHappy.c";
			refChar.Dialog.CurrentNode = "Barbazon_boarding"; //даем абордажную ноду		
		}
	}
}

// ugeen --> ситуации на абордаже в каюте вражеского кэпа (эпидемия или взрыв)
void SetQuestAboardCabinDialogSituation(ref refChar)
{
	LAi_SetFightMode(pchar, false);
	LAi_LockFightMode(pchar, true);
	refChar.Dialog.FileName = "GenQuests_Dialog.c";	
	switch(refChar.situation.type)
	{
		case "pirate": 	// пираты или ДУ	
			refChar.Dialog.CurrentNode = "ShipSituation11";
		break;
		case "hunter": 	// ОЗГ
			refChar.Dialog.CurrentNode = "ShipSituation31";
		break;
		case "war": 	// военные корабли
			refChar.Dialog.CurrentNode = "ShipSituation21";
		break;
		case "trade": 	// торговцы
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
//выход без боевки, но в плен не надо
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
// выход с боевкой
void QuestAboardCabinDialogExitWithBattle(string _questName)
{
    QuestAboardCabinDialogFree(); // важный метод
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	LAi_SetFightMode(pchar, true);
	LAi_SetFightMode(sld, true);
	LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck(LAI_GROUP_BRDENEMY, _questName);
	// SetCharacterTask_Fight(sld, pchar);
}

void QuestAboardCabinDialogExitWithBattleNoParam()// homo тоже самое, только без параметров
{
    QuestAboardCabinDialogExitWithBattle("");
}

void QuestAboardCabinDialogSurrender()
{
 	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	DeleteAttribute(sld, "DontRansackCaptain"); // если было зачем-то
	pchar.GenQuest.QuestAboardCaptanSurrender = true;
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
	//на форме убиваем LAi_SetCurHP(characterFromId(sld.CaptanId), 0.0); 
	//sld.LifeDay = 0;    это не фантом многодневка, а фантом локации, трется он сам при закрузке локации, но не при выгрузке
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
}
//==> квестовое пленение с сохранением индекса пленного.
void QuestAboardCabinDialogQuestSurrender()
{
	ref sld;
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	sld.DontRansackCaptain = true; // чтоб не сдался второй раз
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetImmortal(sld, false);
	//на форме убиваем LAi_SetCurHP(characterFromId(sld.CaptanId), 0.0); 
	//sld.LifeDay = 0;
	pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(sld);
	SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
}

// eddy. лицензии торговых компаний. -->
//дать лицензию
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
		rItem.Validity = FindRussianDaysString(_validity); //строка для дескрайба
		rItem.Validity.QtyDays = _validity; //время действия лицензии в днях для расчетов
	}
}
//забрать лицензию 
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
//проверить наличие лицензии
bool CheckNationLicence(int _nation)
{
	if (_nation != PIRATE) 
	{
		if (CheckCharacterItem(pchar, NationShortName(_nation)+"TradeLicence")) return true; 
	}
	return false;
}
//проверить сроки лицензии, сколько осталось дней. если -1, то просрочена или отсутствует
int GetDaysContinueNationLicence(int _nation)
{
	int iTerms = -1;
	ref rItem;
	if (_nation != PIRATE) 
	{
		if (CheckNationLicence(_nation))
		{
			rItem = ItemsFromID(NationShortName(_nation)+"TradeLicence");
			
			if(!CheckAttribute(rItem, "Validity")) // Warship 10.07.09 fix - Судя по логам, могло не быть
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
//дать наименование лицензии, например ''Лицензия Голландской Вест-Индской компании''
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
// eddy. лицензии торговых компаний. <--

void SelectSlavetraderRendom() // работорговец, выбор города
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

void HollandGambitNpcInit()//оптимизация - создаем всех ключевых персонажей по этому квесту здесь
{
//--------------------------------штаб-квартира ГВИК в Виллемстаде--------------------------------------
	//Лукас Роденбург
	sld = GetCharacter(NPC_GenerateCharacter("Lucas", "Lucas", "man", "man", 30, HOLLAND, -1, false, "quest"));
	sld.name = "Лукас";
	sld.lastname = "Роденбург";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
 	SetRandSPECIAL(sld);
    SetSelfSkill(sld, 80, 80, 80, 80, 80);
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	LocatorReloadEnterDisable("Villemstad_houseS3", "reload2", true);//кабинет закроем до поры
	//офицер-секретарь
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
	
//----------------------------------------Дом Соломона и Абигайль Шнеур-------------------------------------
	//Абигайль
	sld = GetCharacter(NPC_GenerateCharacter("Abigile", "Aby", "woman", "woman_A2", 10, HOLLAND, -1, false, "quest"));
	sld.name = "Абигайль";
	sld.lastname = "Шнеур";
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
	//Соломон
	sld = GetCharacter(NPC_GenerateCharacter("Solomon", "Solomon", "man", "man_B", 10, HOLLAND, -1, false, "quest"));
	sld.name = "Соломон";
	sld.lastname = "Шнеур";
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
	LocatorReloadEnterDisable("Villemstad_town", "houseSP2", true);//дом закроем до поры
	
//-----------------------------------------аптека мистера Мердока-------------------------------------------
	//Джон Мердок
	sld = GetCharacter(NPC_GenerateCharacter("Merdok", "Merdok", "man", "man", 30, ENGLAND, -1, false, "quest"));
	sld.name = "Джон";
	sld.lastname = "Мердок";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
    SetSelfSkill(sld, 80, 80, 80, 80, 80);
	LAi_SetOwnerType(sld);
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	LocatorReloadEnterDisable("SentJons_HouseF3", "reload2", true);//подземелье закроем до поры
	//Джино Гвинейли
	sld = GetCharacter(NPC_GenerateCharacter("Jino", "Gino", "man", "man", 20, ENGLAND, -1, false, "quest"));
	sld.name = "Джино";
	sld.lastname = "Гвинейли";
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
	LocatorReloadEnterDisable("SentJons_HouseF3", "reload4", true);//комнату закроем до поры
	
//------------------------------------хижина Чарли Книппеля-------------------------------------------
	//Чарли Книппель
	sld = GetCharacter(NPC_GenerateCharacter("Knippel", "Kneepel", "man", "man_B", 20, ENGLAND, -1, false, "quest"));
	sld.name = "Чарли";
	sld.lastname = "Книппель";
	sld.greeting = "knippel_1";
	sld.CompanionDisable = true;
	sld.rank = 15;
	LAi_SetHP(sld, 300, 300);
	SetSelfSkill(sld, 35, 40, 55, 60, 50); 	//легк.сред.тяж.пист.удача
	SetShipSkill(sld, 40, 20, 65, 65, 45, 20, 20, 10, 15); 	//хар.торг.метк.оруд.навиг.почин.аборд.защит.скрыт.
	SetSPECIAL(sld, 10, 10, 10, 5, 5, 8, 5); 
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	//сил.воспр.вын.автор.обуч.реакц.удача
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
	
//----------------прочие персонажи - расстановка в зависимости от варианта квеста в разных местах-----------
	//Ричард Флитвуд
	sld = GetCharacter(NPC_GenerateCharacter("Fleetwood", "Fleetwood", "man", "man", 20, ENGLAND, -1, true, "quest"));
	sld.name = "Ричард";
	sld.lastname = "Флитвуд";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
sld.SuperShooter  = true;
 	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//Якоб ван Берг
	sld = GetCharacter(NPC_GenerateCharacter("JacobBerg", "VanBerg", "man", "man", 35, PIRATE, -1, false, "quest"));
	sld.name = "Якоб";
	sld.lastname = "ван Берг";
	sld.greeting = "JacobBerg";
	sld.Dialog.Filename = "Quest\HollandGambit\JacobBerg.c";
	sld.dialog.currentnode = "First time";
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	TakeNItems(sld, "potion2", 2);
	sld.money = 12000;
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	GiveItem2Character(sld, "BackPack3");
	SetRandSPECIAL(sld);
	
	//Лонгвэй
	sld = GetCharacter(NPC_GenerateCharacter("Longway", "Longway", "man", "man", 20, HOLLAND, -1, false, "quest"));
	sld.name = "Лонгвэй";
	sld.lastname = "";
	sld.greeting = "Longway";
    sld.Dialog.Filename = "Quest\HollandGambit\Longway.c";
	sld.dialog.currentnode = "First time";
	sld.CompanionDisable = true;
	sld.rank = 20;
	sld.money = 5000;
	SetSelfSkill(sld, 45, 55, 45, 40, 50); 	//легк.сред.тяж.пист.удача
	SetShipSkill(sld, 50, 20, 25, 25, 60, 20, 20, 50, 15); 	//хар.торг.метк.оруд.навиг.почин.аборд.защит.скрыт.
	SetSPECIAL(sld, 7, 7, 7, 7, 10, 9, 7); 	//сил.воспр.вын.автор.обуч.реакц.удача
	LAi_SetHP(sld, 250, 250);
	sld.MultiFighter = 2.5; // мультифайтер
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
	
	//Жоаким Мерриман
	sld = GetCharacter(NPC_GenerateCharacter("Joakim", "Meriman_1", "man", "man_B", 25, HOLLAND, -1, false, "quest"));
	sld.name = "Жоаким";
	sld.lastname = "Мерриман";
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
	
	//Эркюль Тонзаг
	sld = GetCharacter(NPC_GenerateCharacter("Tonzag", "Tonzag", "man", "man", 30, ENGLAND, -1, false, "quest"));
	sld.name = "Эркюль";
	sld.lastname = "Тонзаг";
	sld.greeting = "tonzag_2";
	sld.Dialog.Filename = "Quest\HollandGambit\Tonzag.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 15;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 3, 10, 4, 6, 10, 5); 	//сил.воспр.вын.автор.обуч.реакц.удача
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

void SharlieNpcInit()//создаем всех ключевых персонажей по квестам Бремя Гасконца, Страж Истины здесь
{
	string sBlade;
	//Мишель де Монпе
	sld = GetCharacter(NPC_GenerateCharacter("Mishelle", "Migel_1", "man", "man", 60, FRANCE, -1, false, "quest"));
	sld.name = "Мишель";
	sld.lastname = "де Монпе";
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
	
	//аббат Бенуа
	sld = GetCharacter(NPC_GenerateCharacter("Benua", "abbat", "man", "man_B", 20, FRANCE, -1, false, "quest"));
	sld.name = "аббат";
	sld.lastname = "Бенуа";
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
	
	//Фадей Московит
	sld = GetCharacter(NPC_GenerateCharacter("Fadey", "moscovit", "man", "moscovit", 30, FRANCE, -1, false, "quest"));
	sld.name = "Фадей";
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
	
	// Диего де Монтойя
	sld = GetCharacter(NPC_GenerateCharacter("Diego", "diego_6", "man", "man_A", 1, SPAIN, -1, false, "quest"));
	sld.name = "Диего";
	sld.lastname = "де Монтойя";
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
	sld.MultiFighter = 3.0; // мультифайтер
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
	
	// Алонсо де Мальдонадо
	sld = GetCharacter(NPC_GenerateCharacter("Maldonado", "Alonso", "man", "man", 1, SPAIN, -1, false, "quest"));
	sld.name = "Алонсо";
	sld.lastname = "де Мальдонадо";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	
	// Вильям Патерсон
	sld = GetCharacter(NPC_GenerateCharacter("Willy", "willy_6", "man", "man_A", 1, ENGLAND, -1, false, "quest"));
	sld.name = "Вильям";
	sld.lastname = "Патерсон";
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
	sld.MultiFighter = 3.0; // мультифайтер
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
	
	// Арчибальд Колхаун
	sld = GetCharacter(NPC_GenerateCharacter("Archy", "archy", "man", "man", 1, ENGLAND, -1, false, "quest"));
	sld.name = "Арчибальд";
	sld.lastname = "Колхаун";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
}

void SagaNpcInit()//создаем всех ключевых персонажей по квесту Пиратская Сага здесь
{
	//Ян Свенсон, Блуфилдс
	sld = GetCharacter(NPC_GenerateCharacter("Svenson", "Svenson", "man", "man", 1, ENGLAND, -1, false, "quest"));
	sld.name = "Ян";
	sld.lastname = "Свенсон";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.cirassId = Items_FindItemIdx("cirass1"); 
	LAi_SetImmortal(sld, true);
	sld.location = "Santacatalina_houseS1_residence";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//жена Яна Свенсона - просто антураж дома
	sld = GetCharacter(NPC_GenerateCharacter("JS_girl", "Svenson_wife", "woman", "towngirl", 10, ENGLAND, -1, false, "quest"));
	sld.name = "Джоанна";
	sld.lastname = "Свенсон";
	sld.greeting = "joanna";
    sld.Dialog.Filename = "Quest\Saga\OtherNPC.c";
	sld.dialog.currentnode = "js_girl";
	LAi_SetImmortal(sld, true);
	sld.location = "Santacatalina_houseS1";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//Натаниэль Хоук
	sld = GetCharacter(NPC_GenerateCharacter("Nathaniel", "Hawk_1", "man", "man_B", 25, PIRATE, -1, false, "quest"));
	SetFantomParamFromRank(sld, 25, true);
	sld.name = "Натаниэль";
	sld.lastname = "Хоук";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.location = "FernandaDiffIndoor";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	LAi_SetGroundSitTypeNoGroup(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	
	//Даниэль Хоук ... Данни, Данни...
	sld = GetCharacter(NPC_GenerateCharacter("Danielle", "Danny", "woman", "danny", 1, ENGLAND, -1, false, "quest"));
	sld.name = "Даниэль";
	sld.lastname = "Хоук";
	sld.greeting = "Danny";
    sld.Dialog.Filename = "Quest\Saga\Danielle.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 22;
	LAi_SetImmortal(sld, true); // временно
	LAi_SetHP(sld, 280, 280); 
	sld.MultiFighter = 2.5; // мультифайтер
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

	//Эдвард Дойли
	sld = GetCharacter(NPC_GenerateCharacter("Doylie", "citiz_6", "man", "man", 35, ENGLAND, -1, false, "quest"));
	sld.name = "Эдвард";
	sld.lastname = "Дойли";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//Лоуренс Белтроп
	sld = GetCharacter(NPC_GenerateCharacter("Beltrop", "Balthrop", "man", "balthrop", 35, PIRATE, -1, false, "quest"));
	sld.name = "Лоуренс";
	sld.lastname = "Белтроп";
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
	
	//Глэдис
	sld = GetCharacter(NPC_GenerateCharacter("Gladis", "Gladys", "woman", "woman", 10, ENGLAND, -1, false, "quest"));
	sld.name = "Глэдис";
	sld.lastname = "Мак Артур";
	sld.greeting = "gladis_1";
    sld.Dialog.Filename = "Quest\Saga\Gladis.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 10;
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	
	//Элиза
	sld = GetCharacter(NPC_GenerateCharacter("Helena", "Eliza_0", "woman", "rumba", 1, ENGLAND, -1, false, "quest"));
	sld.name = "Элиза";
	sld.lastname = "Мак Артур";
	sld.Dialog.Filename = "Quest\Saga\Helena.c";
	sld.dialog.currentnode = "First time";
	sld.greeting = "helena_1";
	sld.HeroModel = "Eliza_0,Eliza_1,Eliza_2,Eliza_3,Eliza_4,protocusto,Eliza_0,Eliza_0";
	sld.rank = 15;
	LAi_SetHP(sld, 220, 220); 
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.SuperShooter  = true;
	sld.MultiFighter = 3.0; // мультифайтер
	sld.MultiShooter = 3.0;
	LAi_SetImmortal(sld, true); // временно
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
	
	//Хосе Диос - картограф
	sld = GetCharacter(NPC_GenerateCharacter("Dios", "Dios", "man", "man_B", 16, SPAIN, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 16, true);
	sld.name = "Хосе";
	sld.lastname = "Диос";
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	
	//Альберт Локсли - адвокат
	sld = GetCharacter(NPC_GenerateCharacter("Loxly", "advocat", "man", "man", 20, ENGLAND, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Альберт";
	sld.lastname = "Локсли";
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

void LSC_NpcInit()// ключевые НПС LSC
{
	//Акула Додсон
	sld = GetCharacter(NPC_GenerateCharacter("Dodson", "Shark", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Стивен";
	sld.lastname = "Додсон";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	sld.location = "SanAugustineResidence";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_SHARK");

	// Чад Каппер
	sld = GetCharacter(NPC_GenerateCharacter("Capper", "Chad", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Чад";
	sld.lastname = "Каппер";
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
	sld.MultiFighter = 2.5; // мультифайтер
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
	
	//Лейтон Декстер
	sld = GetCharacter(NPC_GenerateCharacter("Dexter", "Dexter", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Лейтон";
	sld.lastname = "Декстер";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", 2+makeint(MOD_SKILL_ENEMY_RATE/2));
	sld.location = "SanAugustineResidence";
	sld.location.group = "goto";
	sld.location.locator = "goto11";
	LAi_SetStayType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_SHARK");
	
	// Черный Эдди
	sld = GetCharacter(NPC_GenerateCharacter("Eddy", "Black", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Эдвард";
	sld.lastname = "Блэк";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// колдун ривадос Чимисет
	sld = GetCharacter(NPC_GenerateCharacter("Chimiset", "Chimiset2", "man", "man_A1", 1, PIRATE, -1, false, "quest"));
	sld.name = "Чимисет";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// Зикомо
	sld = GetCharacter(NPC_GenerateCharacter("Zikomo", "Zikomo", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Зикомо";
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_RIVADOS");
	
	// Джузеппе Фацио - посредник
	sld = GetCharacter(NPC_GenerateCharacter("Facio", "Facio", "man", "man_B", 1, PIRATE, -1, false, "quest"));
	sld.name = "Джузеппе";
	sld.lastname = "Фацио";
	sld.greeting = "facio_1";
    sld.Dialog.Filename = "Quest\LSC\Facio.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "diplomat"; //тип нпс
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
	
	// Аксель Йост - торговец
	sld = GetCharacter(NPC_GenerateCharacter("Axel", "Axel", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Аксель";
	sld.lastname = "Йост";
	sld.greeting = "Axel";
    sld.Dialog.Filename = "Quest\LSC\Axel.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "trader"; //тип нпс
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
	
	// Санчо Карпентеро - бармен ...Санчо Панса...
	sld = GetCharacter(NPC_GenerateCharacter("Carpentero", "Carpentero", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Санчо";
	sld.lastname = "Карпентеро";
	sld.greeting = "Carpentero";
    sld.Dialog.Filename = "Quest\LSC\Carpentero.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "barmen"; //тип нпс
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
	
	// брат Юлиан - священник
	sld = GetCharacter(NPC_GenerateCharacter("Julian", "priest_1", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "брат";
	sld.lastname = "Юлиан";
	sld.greeting = "padre_1";
    sld.Dialog.Filename = "Quest\LSC\Julian_priest.c";
	sld.city = "LostShipsCity";
	sld.cityTape = "priest"; //тип нпс
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
	
	// Мэри Каспер ... Мэри... никому теперь не верит Мэри... лучшей подруги и любовницы для ГГ не будет :)
	sld = GetCharacter(NPC_GenerateCharacter("Mary", "Mary", "woman", "mary", 1, PIRATE, -1, false, "quest"));
	sld.name = "Мэри";
	sld.lastname = "Каспер";
	sld.Dialog.Filename = "Quest\LSC\Mary.c";
	sld.dialog.currentnode = "First time";
	sld.greeting = ""; // установим по нужным местам
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
	sld.MultiFighter = 3.5; // мультифайтер
	sld.MultiShooter = 3.5;
	sld.SuperShooter  = true;
	LAi_SetOwnerType(sld);
	
	// Хенрик Ведекер - механик
	sld = GetCharacter(NPC_GenerateCharacter("Mechanic", "Mechanic", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Хенрик";
	sld.lastname = "Ведекер";
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
	
	// Юрген Шмидт - оружейник
	sld = GetCharacter(NPC_GenerateCharacter("Schmidt", "Schmidt", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Юрген";
	sld.lastname = "Шмидт";
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
	
	//Дональд Гринспи - лидер нарвалов
	sld = GetCharacter(NPC_GenerateCharacter("Grinspy", "Donald", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Дональд";
	sld.lastname = "Гринспи";
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
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.SuperShooter  = true;
	LAi_group_MoveCharacter(sld, "LSC_NARVAL");
	
	// Оле Кристиансен - Белый Мальчик ...Оле...оле-оле-оле... :)
	sld = GetCharacter(NPC_GenerateCharacter("Ole", "Ole", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Оле";
	sld.lastname = "Кристиансен";
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
	LAi_SetImmortal(sld, true); // ключевой персонаж
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	
	// Циклоп Марчелло ...Циклопус... или Суслопус :)
	sld = GetCharacter(NPC_GenerateCharacter("Marchello", "Cyclop", "man", "man", 15, PIRATE, -1, false, "quest"));
	sld.name = "Марчелло";
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

void LSC_CreateStateCitizens() // создание горожан-статиков LSC, 20 штук
{
	// ------------------------ внешние горожане ------------------------	
	// внешний горожанин Дугал Эбботт - дворянин
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Dugal", "citiz_3", "man", "man", 25, PIRATE, -1, true, "soldier"));
	SetFantomParamFromRank(sld, 25, true);
	sld.name = "Дугал";
	sld.lastname = "Эбботт";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto02_1"; 
	sld.location.baseShip = "02"; //базовый корабль в ГПК - Каролина
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 2; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Dugal.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "noble_male";
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внешний горожанин Лайонел Маскетт - мещанин
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Lionel", "citiz_11", "man", "man", 20, PIRATE, -1, true, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Лайонел";
	sld.lastname = "Маскетт";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_3"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК - Плуто
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Lionel.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "citizen_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внешний горожанин Гхерад Смиитс - матрос
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Gherad", "citiz_38", "man", "man", 18, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 18, true);
	sld.name = "Гхерад";
	sld.lastname = "Смиитс";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto05_1"; 
	sld.location.baseShip = "05"; //базовый корабль в ГПК - Флерон
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Gherad.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "town_sailor";
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внешний горожанин Ришард Шамбон - контрабандист
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Rishard", "Shambone", "man", "man", 17, PIRATE, -1, false, "marginal"));
	SetFantomParamFromRank(sld, 17, true);
	sld.name = "Ришард";
	sld.lastname = "Шамбон";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto08_1";
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true; 
	sld.location.baseShip = "08"; //базовый корабль в ГПК - Глория
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Rishard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "marginal";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внешний горожанин Альваро Гомец - капитан
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Alvaro", "mercen_23", "man", "man", 28, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 28, true);
	sld.name = "Альваро";
	sld.lastname = "Гомец";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_1"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "09"; //базовый корабль в ГПК - Плуто
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Alvaro.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "captain";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внешний горожанин Виктор Кассель - бандит
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Victor", "mercen_20", "man", "man", 30, PIRATE, -1, true, "marginal"));
	SetFantomParamFromRank(sld, 30, true);
	sld.name = "Виктор";
	sld.lastname = "Кассель";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto11_1"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "11"; //базовый корабль в ГПК - Сан-Августин
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Victor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "town_pirate";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// внешний горожанин Адольф Барбье - авантюрист
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Adolf", "officer_16", "man", "man", 22, PIRATE, -1, true, "marginal"));
	SetFantomParamFromRank(sld, 22, true);
	sld.name = "Адольф";
	sld.lastname = "Барбье";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto05_3"; 
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	sld.location.baseShip = "05"; //базовый корабль в ГПК - Флерон
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Adolf.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "town_pirate";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// внешний горожанин Куранай - индеец
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Curanai", "miskito_4", "man", "man", 18, PIRATE, -1, true, "native"));
	SetFantomParamFromRank(sld, 18, true);
	sld.name = "Куранай";
	sld.lastname = "";
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14_1"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "14"; //базовый корабль в ГПК - Санта-Флорентина
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Curanai.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "indian_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	sld.Merchant.type = "LSC_indian";
	sld.money = 0;
	
	// внешняя горожанка Рамона Лоцано
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Ramona", "women_16", "woman", "towngirl", 14, PIRATE, -1, true, "citizen"));
	SetFantomParamFromRank(sld, 14, true);
	sld.name = "Рамона";
	sld.lastname = "Лоцано";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "LostShipsCity_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15_1"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК - Эва
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Ramona.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ внешние горожане в таверне ------------------------
	// в таверне Оеларт Котеел - канонир (возможный офицер)
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Oelart", "mercen_3", "man", "man", 20, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Оеларт";
	sld.lastname = "Котеел";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit2"; 
	sld.location.baseShip = "02"; //базовый корабль в ГПК - Каролина
	sld.location.baseLocator = "goto02_2";
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5; 
	sld.SuperShooter  = true;
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 6; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Oelart.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "town_sailor";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// в таверне Джаспер Пратт - каторжник
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jasper", "prizon_7", "man", "man_B", 15, PIRATE, -1, true, "slave"));
	SetFantomParamFromRank(sld, 15, true);
	sld.name = "Джаспер";
	sld.lastname = "Пратт";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit3"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК - Плуто
	sld.location.baseLocator = "goto09_2"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jasper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "marginal";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// в таверне Леонард Маскетт - пьяница
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Leonard", "LeoMaskett", "man", "man", 12, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 12, true);
	sld.name = "Леонард";
	sld.lastname = "Маскетт";
	sld.city = "LostShipsCity";
	sld.location = "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit5"; 
	sld.location.baseShip = "05"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto05_2"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 7; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Leonard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "habitue";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// в таверне Джозеф Лодердэйл - английский военный офицер
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Josef", "off_eng_2", "man", "man", 35, PIRATE, -1, true, "soldier"));
	SetFantomParamFromRank(sld, 35, true);
	sld.name = "Джозеф";
	sld.lastname = "Лодердэйл";
	sld.city = "LostShipsCity";
	sld.location = "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit8"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "08"; //базовый корабль в ГПК - Глория
	sld.location.baseLocator = "goto08_3";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Josef.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// в таверне Лоренцо Сольдерра - испанский военный офицер
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Lorenzo", "off_spa_4", "man", "man", 35, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 35, true);
	sld.name = "Лоренцо";
	sld.lastname = "Сольдерра";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit6"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "14"; //базовый корабль в ГПК - Санта-Флорентина
	sld.location.baseLocator = "goto14_2";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Lorenzo.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	// в таверне Жаклин Тьюрам - торговый капитан
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jacklin", "citiz_26", "man", "man", 20, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Жаклин";
	sld.lastname = "Тьюрам";
	sld.city = "LostShipsCity";
	sld.location	= "FleuronTavern";
	sld.location.group = "sit";
	sld.location.locator = "sit7"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "11"; //базовый корабль в ГПК - Сан-Августин
	sld.location.baseLocator = "goto11_2";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jacklin.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "captain";
	LAi_SetSitType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ внешние горожане в церкви -----------------------
	// в церкви Джиллиан Стайнер
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Jillian", "women_15", "woman", "towngirl", 12, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 12, true);
	sld.name = "Джиллиан";
	sld.lastname = "Стайнер";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "GloriaChurch";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "08"; //базовый корабль в ГПК - Глория
	sld.location.baseLocator = "goto08_3"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Jillian.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// в церкви Таннеке Эверс
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Tanneke", "women_13", "woman", "towngirl", 13, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 13, true);
	sld.name = "Таннеке";
	sld.lastname = "Эверс";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "GloriaChurch";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК - Эва
	sld.location.baseLocator = "goto15_3"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Tanneke.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// ------------------------ внутренние горожане ------------------------

	// внутреняя горожанка Орели Бертин
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Oreli", "women_18", "woman", "towngirl", 11, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 11, true);
	sld.name = "Орели";
	sld.lastname = "Бертин";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "PlutoStoreSmall";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК - Плуто
	sld.location.baseLocator = "goto09_0"; 
	sld.location.baseLocation = "PlutoStoreSmall"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 6; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Oreli.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внутрений горожанин Антонио Бетанкур
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Betancur", "Betancur", "man", "man", 20, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Антонио";
	sld.lastname = "Бетанкур";
	sld.rank = 10;
	sld.city = "LostShipsCity";
	sld.location	= "PlutoStoreSmall";
	sld.location.group = "barmen";
	sld.location.locator = "bar1"; 
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
	sld.location.baseShip = "09"; //базовый корабль в ГПК - Плуто
	sld.location.baseLocator = "goto09_4"; 
	sld.location.baseLocation = "PlutoStoreSmall"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Betancur.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "noble_male";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;

	// внутреняя горожанка Сесиль Галард
	sld = GetCharacter(NPC_GenerateCharacter("LSC_Sesil", "women_17", "woman", "towngirl", 10, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "Сесиль";
	sld.lastname = "Галард";
	RemoveAllCharacterItems(sld, true);
	sld.city = "LostShipsCity";
	sld.location	= "AvaShipInside3";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК - Эва
	sld.location.baseLocator = "goto15_0"; 
	sld.location.baseLocation = "AvaShipInside3"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Quest\LSC\Citizen\LSC_Sesil.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_SesilGalard";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "LSC_CitizenConflict");
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
	
	//официантка Наталия Бушелл
	sld = GetCharacter(NPC_GenerateCharacter("Natalie_Waitress", "women_11", "woman", "towngirl", 10, PIRATE, -1, false, "citizen"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "Наталия";
	sld.lastname = "Бушелл";
	RemoveAllCharacterItems(sld, true);
	sld.location	= "FleuronTavern";
	sld.location.group = "waitress";
	sld.location.locator = "barmen";
	sld.dialog.filename   = "Quest\LSC\Natalie_Waitress.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //тип нпс
	sld.greeting = "waitress";
	LAi_SetWaitressType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "LSC_CITIZEN");
	SaveCurrentNpcQuestDateParam(sld, "location");
	sld.LSC_clan = true;
}
/*
void MerchResidenceInit() //Торгаш
{
		ref sld;
		sld = GetCharacter(NPC_GenerateCharacter("MerchCotraband", "pirate_9", "man", "man", 1, PIRATE, -1, false, "quest")); // ид ,модель,
		sld.name = "Таинственный";
		sld.lastname = "Торговец";
		sld.dialog.filename = "Merch_Contr.c";
		LAi_SetImmortal(sld, true);
		sld.greeting = "Voice\Russian\pirat_quest_3.wav";
		sld.money = 50000;
		LAi_SetHP(sld, 200, 200); 
		//LAi_SetHP(sld, 200+MOD_SKILL_ENEMY_RATE*30, 200+MOD_SKILL_ENEMY_RATE*30);
		SetSPECIAL(sld, 9,8,7,5,7,9,10); //сил.воспр.вын.автор.обуч.реакц.удача
		SetSelfSkill(sld, 90,90,80,85,95); //легк.сред.тяж.пист.удача
		SetShipSkill(sld, 26,10,55,51,20,22,33,21,34); //хар.торг.метк.оруд.навиг.почин.аборд.защит.скрыт.
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
			case "А": sResult += "а"; continue; break;
			case "Б": sResult += "б"; continue; break;
			case "В": sResult += "в"; continue; break;
			case "Г": sResult += "г"; continue; break;
			case "Д": sResult += "д"; continue; break;
			case "Е": sResult += "е"; continue; break;
			case "Ё": sResult += "ё"; continue; break;
			case "Ж": sResult += "ж"; continue; break;
			case "З": sResult += "з"; continue; break;
			case "И": sResult += "и"; continue; break;
			case "Й": sResult += "й"; continue; break;
			case "К": sResult += "к"; continue; break;
			case "Л": sResult += "л"; continue; break;
			case "М": sResult += "м"; continue; break;
			case "Н": sResult += "н"; continue; break;
			case "О": sResult += "о"; continue; break;
			case "П": sResult += "п"; continue; break;
			case "Р": sResult += "р"; continue; break;
			case "С": sResult += "с"; continue; break;
			case "Т": sResult += "т"; continue; break;
			case "У": sResult += "у"; continue; break;
			case "Ф": sResult += "ф"; continue; break;
			case "Х": sResult += "х"; continue; break;
			case "Ц": sResult += "ц"; continue; break;
			case "Ч": sResult += "ч"; continue; break;
			case "Ш": sResult += "ш"; continue; break;
			case "Щ": sResult += "щ"; continue; break;
			case "Э": sResult += "э"; continue; break;
			case "Ю": sResult += "ю"; continue; break;
			case "Я": sResult += "я"; continue; break;
			
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
// Перевод всей строки в верхний регистр
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
			case "а": retString += "А"; continue; break;
			case "б": retString += "Б"; continue; break;
			case "в": retString += "В"; continue; break;
			case "г": retString += "Г"; continue; break;
			case "д": retString += "Д"; continue; break;
			case "е": retString += "Е"; continue; break;
			case "ё": retString += "Ё"; continue; break;
			case "ж": retString += "Ж"; continue; break;
			case "з": retString += "З"; continue; break;
			case "и": retString += "И"; continue; break;
			case "й": retString += "Й"; continue; break;
			case "к": retString += "К"; continue; break;
			case "л": retString += "Л"; continue; break;
			case "м": retString += "М"; continue; break;
			case "н": retString += "Н"; continue; break;
			case "о": retString += "О"; continue; break;
			case "п": retString += "П"; continue; break;
			case "р": retString += "Р"; continue; break;
			case "с": retString += "С"; continue; break;
			case "т": retString += "Т"; continue; break;
			case "у": retString += "У"; continue; break;
			case "ф": retString += "Ф"; continue; break;
			case "х": retString += "Х"; continue; break;
			case "ц": retString += "Ц"; continue; break;
			case "ч": retString += "Ч"; continue; break;
			case "ш": retString += "Ш"; continue; break;
			case "щ": retString += "Щ"; continue; break;
			case "э": retString += "Э"; continue; break;
			case "ю": retString += "Ю"; continue; break;
			case "я": retString += "Я"; continue; break;
			
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

// Первый символ в верхний регистр
String UpperFirst(String _text)
{
	String firstSymbol = GetSymbol(_text, 0);
	firstSymbol = ToUpper(firstSymbol);
	
	return firstSymbol + strcut(_text, 1, strlen(_text) - 1);
}

// Первый символ в нижний регистр
String LowerFirst(String _text)
{
	String firstSymbol = GetSymbol(_text, 0);
	firstSymbol = GetStrSmallRegister(firstSymbol);
	
	return firstSymbol + strcut(_text, 1, strlen(_text) - 1);
}
// <--


//домашние энкаунтеры. установка тамера ''покинуть дом''
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

//удаления группы с задержкой
void Delay_DeleteGroup(string GroupName)
{	
	pchar.quest.DeleteGroupOnExitLocation.GroupName = GroupName;
	DoQuestCheckDelay("DeleteGroupOnExitLocation", 2.0);
}

//Перехват всех попыток ГГ залезть в боксы
void QuestCheckTakeBoxes(ref itemsRef) 
{	
//	ref locLoad = &locations[reload_location_index];
	ref locLoad = &LoadedLocation; // Warship fix - косило в каютах
    ref sld;
	int i, num;
	
	String title;
	
	//--> флаг ''в сундуке''
	bMainCharacterInBox = true;
	//<-- флаг ''в сундуке''
	//-------------------- КЛАДЫ ------------>>>>>>>>>>>>>
	if (CheckAttribute(itemsRef, "Treasure"))
	{
		Log_Info("Похоже, что это и есть клад.");
		PlaySound("interface\notebook.wav");
		DeleteAttribute(itemsRef, "Treasure");
		//eddy. для безконфликтности квестов
		locations[FindLocation(pchar.location)].DisableEncounters = false; //энкаутеры открыть
		if(!CheckAttribute(itemsRef, "PiratesOnUninhabitedTreasure"))
		{
			// ситуация
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
				AddQuestUserData(title, "sSex", GetSexPhrase("му","й"));
			}
			else
			{
				AddQuestRecordEx(title, "PiratesOnUninhabited", "9");
				AddQuestUserData(title, "sSex", GetSexPhrase("ел","ла"));
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
	//<<<<<<<<<<---------- КЛАДЫ --------------------------

	//-->> Генератор грабежа жемчуга, у главы поселения 
	if (GetCharacterIndex("HeadMan_1") != -1 && locLoad.id == "DestinyGiftPearlTown1_Townhall")
	{
		if (pchar.questTemp.Sharp.SeekSpy != "begin" && pchar.questTemp.Sharp.SeekSpy != "over")
		{	//если взят квест на поиски крысы Шарпа - закрываем его
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
	//<<-- Генератор грабежа жемчуга, у главы поселения 

}

//===>>> постановка прерываний на жемчужный генератор
void DestinyGiftPearlGen_SetSantaCatalina(string sQuest)
{
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition.l1 = "location";
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition.l1.location = "DestinyGiftPearl_Jungle_01";
	pchar.quest.DestinyGiftPearlGen_checkSantaCatalina.win_condition = "DestinyGiftPearlGen_checkSantaCatalina";
}


//открытие дверей в локации города для коммонов. только на текущие сутки + еще одни, потом снимается само.
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

//для борьбы со взломом через ArtMoney
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

///Jason ---------блок помещения ГГ в тюрьму, пребывания в ней, штрафа и выхода из тюрьмы----------------------
void GoToPrison(string _sCity, int _iStraff, int _iDay)//поместить ГГ в тюрьму, забрать все предметы и положить в сундук, оштрафовать
{
	DoFunctionReloadToLocation(_sCity+"_prison", "goto", "goto9", "");
	//Время отсидки прокрутим ДО изъятия предметов - иначе при смене локи сундук и НПС вычистятся
	WaitDate("", 0, 0, _iDay, 0, 10); //крутим время
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
	sld.name = "Тюремный";
    sld.lastname = "надзиратель";
	sld.Dialog.Filename = "Quest\Jail_dialog.c"; 
	sld.dialog.currentnode = "Jail_officer_take"; 
	sld.greeting = "soldier_arest";
	LAi_SetActorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, _sCity+"_prison", "goto", "goto13");
	DoQuestFunctionDelay("Hide_Interface", 0.8);
	DoQuestFunctionDelay("Jail_officer", 10.0);
}

void Hide_Interface(string qName)//скроем нашу махинацию с датами
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

void InPrison(string qName)//отсидка
{
	SetLaunchFrameFormParam("Прошли долгие дни...", "", 0, 6);
	LaunchFrameForm();
	sld = characterFromId("Jail_officer");
    LAi_SetActorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto13");
	DoQuestFunctionDelay("Jail_officer", 10.0);
}

void GoFromPrison(string qName)//выход из тюрьмы
{
	pchar.questTemp.jailCanMove = true; //разрешить пройти мимо стражи
	DoQuestReloadToLocation(pchar.location, "goto", "goto23", "");
	DeleteAttribute(pchar, "questTemp.JailTemp1");
	DeleteAttribute(pchar, "questTemp.JailTemp2");
	SetFunctionTimerCondition("LockPrisonBox", 0, 0, 1, false);
}

void LockPrisonBox(string qName)// закрыть сундук
{
	ref location = &Locations[FindLocation(pchar.questTemp.Jaillocation)];
	location.box1.QuestClosed = true;
	DeleteAttribute(pchar, "questTemp.Jaillocation");
}
//<-- блок помещения ГГ в тюрьму

string DesIsland()//Jason выбор рандомной необитайки - вынес сюда
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

string FindFriendCityToMC(bool bRand)//Jason выбрать радномный дружественный к ГГ город - вынес сюда
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

string FindEnemyCityToMC(bool bRand)//Jason выбрать радномный враждебный к ГГ город - вынес сюда
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

void SelectLevelWarShipParameter()//Jason автолевеллинг на военные корабли противника
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

void SelectLevelTradeShipParameter()//Jason автолевеллинг на торговые корабли противника
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

int SelectLevelCannonParameter(int iShipType)//Jason автолевеллинг на орудия - иногда надо
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

//Jason --> сделаю функции добавления боевых морских и личных скиллов комплексом - много где надо дать сразу по 4-6, а стопки экспы в функциях мешают
//морские навыки, нужны для экспы после морских боев
void AddComplexSeaExpToScill(int s, int a, int c, int g, int d, int r, int t)
{
	AddCharacterExpToSkill(pchar, "Sailing", s);//навигация
	AddCharacterExpToSkill(pchar, "Accuracy", a);//меткость
	AddCharacterExpToSkill(pchar, "Cannons", c);//орудия
	AddCharacterExpToSkill(pchar, "Grappling", g);//абордаж
	AddCharacterExpToSkill(pchar, "Defence", d);//защита
	AddCharacterExpToSkill(pchar, "Repair", r);//починка
	AddCharacterExpToSkill(pchar, "Commerce", t);//торговля
}

//личные боевые навыки, нужны для экспы после сухопутных боев
void AddComplexSelfExpToScill(int l, int m, int h, int p)
{
	AddCharacterExpToSkill(pchar, "FencingL", l);//легкое оружие
	AddCharacterExpToSkill(pchar, "FencingS", m);//среднее оружие
	AddCharacterExpToSkill(pchar, "FencingH", h);//тяжелое оружие
	AddCharacterExpToSkill(pchar, "Pistol", p); //пистоли
}

int CheckShipTypeInSquadron(int iShipType) //Jason, есть ли такой тип корабля в эскадре и сколько
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

bool LSC_CheckShips() // проверка, можно ли подойти к острову LSC // Addon-2016 Jason
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

void SetPassengerParameter(string _sIndex, bool bEnemy)//Jason, общие параметры пассажиров
{
	if (bEnemy)
	{
		pchar.GenQuest.(_sIndex).City = FindEnemyCityToMC(true);
		pchar.GenQuest.(_sIndex).Enemycity = true;
	}
	else pchar.GenQuest.(_sIndex).City = FindFriendCityToMC(true); //целевой город
	pchar.GenQuest.(_sIndex).StartCity = GetCurrentTown(); //стартовый город
	int DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.(_sIndex).City), GetArealByCityName(pchar.GenQuest.(_sIndex).StartCity));
	if (DaysQty > 16) DaysQty = 16;
	if (DaysQty < 1) DaysQty = 10; // оставлю на всяк пожарный пока
	pchar.GenQuest.(_sIndex).DaysQty = makeint(sti(DaysQty)*(frand(1.5)+1.0)); //дни
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
	if (bEnemy) pchar.GenQuest.(_sIndex).Money = makeint(sti(pchar.GenQuest.(_sIndex).Money)*1.2); //оплата
}

string UpdateLSCClanParol() // Jason: обновление паролей кланов
{
	string sParol;
	switch (rand(29))
	{
		case 0: sParol = "анфитрита"; break;
		case 1: sParol = "фуэрта"; break;
		case 2: sParol = "империал"; break;
		case 3: sParol = "боннета"; break;
		case 4: sParol = "трафальгар"; break;
		case 5: sParol = "глостер"; break;
		case 6: sParol = "грифон"; break;
		case 7: sParol = "лангедок"; break;
		case 8: sParol = "лейден"; break;
		case 9: sParol = "молох"; break;
		case 10: sParol = "кристобаль"; break;
		case 11: sParol = "соберано"; break;
		case 12: sParol = "алькантара"; break;
		case 13: sParol = "вангард"; break;
		case 14: sParol = "торбей"; break;
		case 15: sParol = "рассел"; break;
		case 16: sParol = "барфорд"; break;
		case 17: sParol = "пеликан"; break;
		case 18: sParol = "монтебелло"; break;
		case 19: sParol = "зеландия"; break;
		case 20: sParol = "лимено"; break;
		case 21: sParol = "левиафан"; break;
		case 22: sParol = "феникс"; break;
		case 23: sParol = "нептун"; break;
		case 24: sParol = "бургундия"; break;
		case 25: sParol = "пандора"; break;
		case 26: sParol = "роттердам"; break;
		case 27: sParol = "меермен"; break;
		case 28: sParol = "буцентавре"; break;
		case 29: sParol = "конкорда"; break;
	}
	return sParol;
}

void UltimatePotionEffect() // зелье команчей
{
	RemoveItems(pchar, "Ultimate_potion", 1);
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	DeleteAttribute(pchar, "chr_ai.poison");
	Log_Info("Использовано зелье команчей");
	Log_Info("Вы чувствуете себя полностью излеченным!");
	PlaySound("Ambient\Tavern\glotok_001.wav");
}

// ugeen --> 
//--> расчет аренды склада
int GetStoragePriceExt(ref NPChar, ref chref)
{
/*  --> оставим для хардкорного патча если он будет, не вытирать!!!! 
	float fLeadership = 1.5 - GetSummonSkillFromName(pchar, SKILL_LEADERSHIP)/120.0; // учитываем авторитет
	float fCommerce = 1.5 - GetSummonSkillFromName(pchar, SKILL_COMMERCE)/120.0; // учитываем торговлю
	
	int price = makeint(15000 * MOD_SKILL_ENEMY_RATE * fLeadership * fCommerce * 0.5);
*/
	int price = makeint( 10000 * (5 + MOD_SKILL_ENEMY_RATE) * (3 + GetNationRelation2MainCharacter(sti(NPChar.nation)))/360.0 );
	
	return price;
}
//<-- расчет аренды склада
// --> перемещаем остатки груза со склада на корабль ГГ с перегрузом, пусть сам разбирается что делать со всем этим барахлом
void SetStorageGoodsToShip(ref pStorage)
{
	int iStoreQ;
	for (int i = 0; i< GOODS_QUANTITY; i++)
	{
		iStoreQ = GetStorageGoodsQuantity(pStorage, i); 
		if (iStoreQ == 0) continue;
		SetCharacterGoods(pchar, i, GetCargoGoods(pchar, i) + iStoreQ);// перегруз
	}
}
// зануляем оставленные в ПУ корабли
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

bool Saga_CheckMarlinShip() // проверка полакра марлин - одинаковый юз в 2 местах
{
	if(sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_POLACRE || GetCompanionQuantity(pchar) > 1) return false;
	if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation.Marlin") && pchar.ship.name != "Мapлин") return false;
	if (!CheckAttribute(pchar, "questTemp.Saga.BarbTemptation.Marlin") && pchar.ship.name != "Марлин") return false;
	return true;
}

bool bPincers() // можно ли добывать клешни крабов
{
	ref chr = characterFromId("Carpentero");
	if (CheckAttribute(chr, "quest.crab")) return true;
	return false;
}

// устанавливаем сторожевики на Тортугу, сеттим каждый день 2015
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
		sld.DontHitInStorm = true; // не ломается в шторм
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // запрет абордажа
		sld.AlwaysSandbankManeuver = true;
		sld.MultiFighter = 1.5; // мультифайтер
		sld.MultiShooter = 1.5;
		sld.SuperShooter  = true;
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		Group_AddCharacter("Tortuga_Guard", "TortugaGuardCap_"+i);
	}
	Group_SetGroupCommander("Tortuga_Guard", "TortugaGuardCap_1");
	Group_SetTaskNone("Tortuga_Guard");//нет задачи
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
		sld.DontHitInStorm = true; // не ломается в шторм
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // запрет абордажа
		sld.AlwaysSandbankManeuver = true;
		sld.AlwaysEnemy = true;
		sld.MultiFighter = 1.5; // мультифайтер
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

void Map_NationQuestHunter(int Nation)//квестовый энкаунтер-охотник
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
        sld.mapEnc.Name = "перехватчики";
		sld.hunter = ""+iNation+"";
        Group_AddCharacter(sGroup, sCapId + i);
    }
    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
	Map_CreateCoolWarrior("", sCapId + "1", 45);
}

void FillShorechestBox(string loc, int n, int i) // Jason: заполнение выброшенных на берег сундуков
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

bool CheckIndianGift() // Jason: есть ли подарок для индианки
{
	for (int i=47; i<=50; i++)
    {
		if (CheckCharacterItem(pchar, "jewelry"+i)) return true;
	}
	if (CheckCharacterItem(pchar, "mineral6")) return true;
	
	return false;
}

bool CheckCaribGuns() // Jason: есть ли пистоли для продажи карибам
{
	for (int i=1; i<=6; i++)
    {
		if (GetCharacterFreeItem(pchar, "pistol"+i) > 0) return true;
	}
	return false;
}

void MakeHellFireDamage() // Jason: урон огнем на рифе
{
	LAi_ApplyCharacterDamage(pchar, 45+MOD_SKILL_ENEMY_RATE*3, "other");
	LAi_CheckKillCharacter(pchar);
	PlaySound("People Fight\Death_NPC_08.wav");
}

void MakeHellSplashDamage() // Jason: урон водой на рифе
{
	PlaySound("Sea Battles\bolshoy_vsplesk_001.wav");
	CreateLocationParticles("Splash", "item", "splash"+iGlobalTemp, 0.5, 0, 0, "");
	CreateLocationParticles("blood_big", "item", "splash"+iGlobalTemp, 2.0, 0, 0, "");
	LAi_ApplyCharacterDamage(pchar, 90+MOD_SKILL_ENEMY_RATE*6, "other");
	LAi_CheckKillCharacter(pchar);
	PlaySound("People Fight\Death_NPC_08.wav");
}

bool Tieyasal_CheckTablets() // Jason: есть ли скрижали
{
	for (int i=1; i<=6; i++)
    {
		if (CheckCharacterItem(pchar, "Tablet_"+i)) return true;
	}
	return false;
}

void ShowRipInscription(int i, string locId) // Jason: надписи на надгробиях - пасхалка
{
	if (LAi_grp_playeralarm > 0) return;
	
	if (locId == "Charles_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Аврора Бардот, 1612-1637, подавальщица"); 
				Log_Info("Вы заблевали весь стол, чертов пират!");
			break;
			case 2: 
				Log_Info("Жюль Кувье, 1591-1640, кровельщик"); 
				Log_Info("Кажется, поднимается сильный ветер..."); 
			break;
			case 3: 
				Log_Info("Жерар Лесбро, 1555-1596, алхимик");
				Log_Info("А теперь эту жидкость слегка нагреем...");
			break;
			case 4: 
				Log_Info("Юдифь Бозон, 1589-1618, гувернантка");
				Log_Info("Ну и дура же жена его светлости!"); 
			break;
			case 5: 
				Log_Info("Огюст Пуатье, 1567-1624, оружейник"); 
				Log_Info("Так-так, этот пистоль неисправен. Посмотрим поближе..."); 
			break;
			case 6: 
				Log_Info("Марк Ромари, 1544-1599, ростовщик"); 
				Log_Info("Месье, клянусь, меня и вправду ограбили!"); 
			break;
			case 7: 
				Log_Info("Марсель д'Обе, 1611-1650, грузчик"); 
				Log_Info("Кажется, эти канаты действительно прогнили..."); 
			break;
			case 8: 
				Log_Info("Роз Дюплан, 1621-1649, служанка"); 
				Log_Info("И что хозяин держит в этой шкатулке? Сейчас посмотрим, пока его нет..."); 
			break;
			case 9: 
				Log_Info("Виктор Марьон, 1577-1608, сторож"); 
				Log_Info("Эй, кто там?"); 
			break;
		}
	}
	if (locId == "Havana_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Альваро Лопес, 1587-1633, ловец жемчуга"); 
				Log_Info("В эту лагуну акулы отродясь не заплывали!");
			break;
			case 2: 
				Log_Info("Гаспар Ибаньес, 1599-1640, плотник"); 
				Log_Info("Хуан, кинь мне вон тот большой топор!");
			break;
			case 3: 
				Log_Info("Лоренцо Пердозо, 1581-1630, артиллерист"); 
				Log_Info("Сыпь в жерло больше пороха! Еще больше! Вот так...");
			break;
			case 4: 
				Log_Info("Симон Зоррита, 1602-1645, сыщик"); 
				Log_Info("Комендант, я раскрыл преступление. Убийца - это вы!");
			break;
			case 5: 
				Log_Info("Лолита Чека, 1610-1639, портниха"); 
				Log_Info("Не беспокойся, дорогой, муж еще не скоро вернется из плавания...");
			break;
			case 6: 
				Log_Info("Рикардо Казарес, 1590-1633, охотник"); 
				Log_Info("Я знаю эту змею. Она совершенно безобидна!");
			break;
			case 7: 
				Log_Info("Исидро Давилла, 1588-1624, мельник"); 
				Log_Info("Завтра же с утра меняю треснувшие ступени на этой лестнице..."); 
			break;
			case 8: 
				Log_Info("Теодоро Бельо, 1599-1646, адъютант"); 
				Log_Info("Вы подлец, сударь! Извольте обнажить свою тупую ржавую железяку!"); 
			break;
			case 9: 
				Log_Info("Гельвира Чека, 1605-1648, торговка"); 
				Log_Info("Мои товары обмену и возврату не подлежат!"); 
			break;
		}
	}
	if (locId == "PortRoyal_graveyard")
	{
		switch (i)
		{
		case 1: 
				Log_Info("Якоб Блэк, 1608-1631, рыбак"); 
				Log_Info("Отцовский баркас видал немало штормов. Выдержит и на этот раз...");
			break;
			case 2: 
				Log_Info("Ральф Чаплин, 1602-1649, лесоруб"); 
				Log_Info("Джон, ты надежно закрепил топор на топорище?");
			break;
			case 3: 
				Log_Info("Кермит Филлер, 1615-1653, бармен"); 
				Log_Info("Морган, ром был неразбавленный, мамой клянусь!");
			break;
			case 4: 
				Log_Info("Лаура Харт, 1605-1627, шлюха"); 
				Log_Info("Да как вы смеете! Я проверяюсь у лекаря каждую неделю!");
			break;
			case 5: 
				Log_Info("Саймон Лютер, 1598-1639, лекарь"); 
				Log_Info("Белый порошок, не имеет запаха... горький на вкус...");
			break;
			case 6: 
				Log_Info("Оскар Маркер, 1611-1642, вор"); 
				Log_Info("Так, а вот сюда у собаки цепь не дотягивается...");
			break;
			case 7: 
				Log_Info("Маколм Камли, 1545-1587, актер"); 
				Log_Info("В этой маске с красным носом я просто вылитый комендант форта!"); 
			break;
			case 8: 
				Log_Info("Тобиас Филлер, 1567-1599, зверолов"); 
				Log_Info("Джон, этот ягуар кажется мне совсем ручным, открывай клетку..."); 
			break;
			case 9: 
				Log_Info("Камилла Руттер, 1571-1596, крестьянка"); 
				Log_Info("Что-то наш бычок беспокойный какой-то сегодня..."); 
			break;
		}
	}

	if (locId == "FortFrance_Graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Аврора Бардот, 1612-1637, подавальщица"); 
				Log_Info("Вы заблевали весь стол, чертов пират!");
			break;
			case 2: 
				Log_Info("Жюль Кувье, 1591-1640, кровельщик"); 
				Log_Info("Кажется, поднимается сильный ветер..."); 
			break;
			case 3: 
				Log_Info("Жерар Лесбро, 1555-1596, алхимик");
				Log_Info("А теперь эту жидкость слегка нагреем...");
			break;
			case 4: 
				Log_Info("Юдифь Бозон, 1589-1618, гувернантка");
				Log_Info("Ну и дура же жена его светлости!"); 
			break;
			case 5: 
				Log_Info("Огюст Пуатье, 1567-1624, оружейник"); 
				Log_Info("Так-так, этот пистоль неисправен. Посмотрим поближе..."); 
			break;
			case 6: 
				Log_Info("Рикардо Казарес, 1590-1633, охотник"); 
				Log_Info("Я знаю эту змею. Она совершенно безобидна!");
			break;
			case 7: 
				Log_Info("Исидро Давилла, 1588-1624, мельник"); 
				Log_Info("Завтра же с утра меняю треснувшие ступени на этой лестнице..."); 
			break;
			case 8: 
				Log_Info("Шарль де Мор, 1636-1661, дворянин"); 
				Log_Info("Париж, Париж!"); 
			break;
			case 9: 
				Log_Info("Гельвира Чека, 1605-1648, торговка"); 
				Log_Info("Мои товары обмену и возврату не подлежат!"); 
			break;
		}
	}

	if (locId == "PortPax_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Виктимо Сорн, 1612-1637, сторож"); 
				Log_Info("Только Феникс смог его остановить!");
			break;
			case 2: 
				Log_Info("Серано Укаро, 1591-1640, охраник"); 
				Log_Info("Тот, кто охранял башню..."); 
			break;
			case 3: 
				Log_Info("Генрих Онар, 1555-1596, алхимик");
				Log_Info("Покойся с миром...");
			break;
			case 4: 
				Log_Info("Изольда, 1589-1618, гувернантка");
				Log_Info("Ну и дура же жена его светлости!"); 
			break;
			case 5: 
				Log_Info("Верамин Садеа, 1567-1624, оружейник"); 
				Log_Info("Ему был нужен ад!"); 
			break;
			case 6: 
				Log_Info("Викториус Шаль, 1544-1599, ростовщик"); 
				Log_Info("Месье, клянусь, меня и вправду ограбили!"); 
			break;
			case 7: 
				Log_Info("Теодор, 1611-1650, грузчик"); 
				Log_Info("Его дух будет свободен!"); 
			break;
			case 8: 
				Log_Info("Артаг Амашрог, 1621-1649, дворник"); 
				Log_Info("Опять насрали?"); 
			break;
			case 9: 
				Log_Info("Март Мульго, 1577-1608, моряк"); 
				Log_Info("Поссы на грудь, что б морем пахло?"); 
			break;
		}
	}

	if (locId == "Maracaibo_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Альваро Лопес, 1587-1633, ловец жемчуга"); 
				Log_Info("В эту лагуну акулы отродясь не заплывали!");
			break;
			case 2: 
				Log_Info("Гаспар Ибаньес, 1599-1640, плотник"); 
				Log_Info("Хуан, кинь мне вон тот большой топор!");
			break;
			case 3: 
				Log_Info("Лоренцо Пердозо, 1581-1630, артиллерист"); 
				Log_Info("Сыпь в жерло больше пороха! Еще больше! Вот так...");
			break;
			case 4: 
				Log_Info("Симон Зоррита, 1602-1645, сыщик"); 
				Log_Info("Комендант, я раскрыл преступление. Убийца - это вы!");
			break;
			case 5: 
				Log_Info("Лолита Чека, 1610-1639, портниха"); 
				Log_Info("Не беспокойся, дорогой, муж еще не скоро вернется из плавания...");
			break;
			case 6: 
				Log_Info("Рикардо Казарес, 1590-1633, охотник"); 
				Log_Info("Я знаю эту змею. Она совершенно безобидна!");
			break;
			case 7: 
				Log_Info("Исидро Давилла, 1588-1624, мельник"); 
				Log_Info("Завтра же с утра меняю треснувшие ступени на этой лестнице..."); 
			break;
			case 8: 
				Log_Info("Теодоро Бельо, 1599-1646, адъютант"); 
				Log_Info("Вы подлец, сударь! Извольте обнажить свою тупую ржавую железяку!"); 
			break;
			case 9: 
				Log_Info("Гельвира Чека, 1605-1648, торговка"); 
				Log_Info("Мои товары обмену и возврату не подлежат!"); 
			break;
		}
	}

	if (locId == "Villemstad_graveyard")
	{
		switch (i)
		{
			case 1: 
				Log_Info("Фриц Лоотс, 1587-1631, кок"); 
				Log_Info("Разносолы - для офицеров, а матросня будет жрать то, что дают!");
			break;
			case 2: 
				Log_Info("Руперт Хофмейр, 1601-1649, писарь"); 
				Log_Info("В десятый раз повторяю, вы, тупица! Минхер Герритц не принимет вас сегодня!");
			break;
			case 3: 
				Log_Info("Паул Влекке, 1577-1622, лоцман"); 
				Log_Info("Не переживайте, кэп: я знаю проход через эти рифы как свои пять пальцев!");
			break;
			case 4: 
				Log_Info("Йедам Уустген, 1589-1635, кузнец"); 
				Log_Info("Вам бы не саблю получше, а руки на наковальне подровнять следует!");
			break;
			case 5: 
				Log_Info("Катрина Эрб, 1610-1644, прачка"); 
				Log_Info("Лизбет, да куда ты побежала? Это мирные индейцы, они не трогают белых...");
			break;
			case 6: 
				Log_Info("Петер Коннинк, 1561-1615, мушкетер"); 
				Log_Info("Забью заряд я в дуло туго...");
			break;
			case 7: 
				Log_Info("Танна Грааф, 1588-1607, горничная"); 
				Log_Info("Похоже, кто-то ходит внизу. И кого принесло посреди ночи? Пойду, гляну..."); 
			break;
			case 8: 
				Log_Info("Крелис ван Екк, 1572-1611, боцман"); 
				Log_Info("Всыпать по двадцать ударов плетью! Нет - по тридцать! Каждому!"); 
			break;
			case 9: 
				Log_Info("Якоб де Хаез, 1611-1651, путешественник"); 
				Log_Info("Кайманы не нападают на людей. Только когда очень голодны. А этот явно сыт..."); 
			break;
		}
	}
}

//Jason 240912 ------------------------------- адмиральские карты ----------------------------------------------
string SelectAdmiralMaps() // выбор случайной не повторяющейся
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
				i = 24; // остановка цикла
			}
			sTemp = "";
			i++; // завершение цикла
		}
	}
	return sMap;
}

void GiveAdmiralMapToCharacter(ref chr, int abl) // дать случайную с рандомом
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	if (drand(abl) == 0)
	{
		string amap = SelectAdmiralMaps();
		if (amap != "") GiveItem2Character(chr, amap);
	}
}

void TargetAdmiralMapToCharacter(ref chr, string amap) // дать конкретную, если такой еще нет
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	ref sld = characterFromId("Dios");
	if (!CheckAttribute(sld, "quest.map."+amap))
	{
		GiveItem2Character(chr, amap);
		sld.quest.map.(amap) = true;
	}
}

int CountAdmiralMapFromCharacter() // сосчитать
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

string IdentifyAdmiralMapLast() // идентифицировать последнюю в списке
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
// <-- адмиральские карты

// --> персидские клинки Фадея
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
// <-- персидские клинки Фадея

void CaveEnc_FillSkeleton(ref chr, int i) // лут для скелетов в пещерах
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
// поиск и определение линейных кораблей наций
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
			if (sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LSHIP_ENG && LineShips_FindCompanionShips(SHIP_LSHIP_ENG) && Trafalgar_FindCompanionShip()) return false; // Jason, НСО
			if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LSHIP_ENG || LineShips_FindCompanionShips(SHIP_LSHIP_ENG)) return true;
		break;
		
		case FRANCE:
			if (sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LSHIP_FRA && LineShips_FindCompanionShips(SHIP_LSHIP_FRA) && Ecliaton_FindCompanionShip()) return false; // Jason, НСО
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

bool Ecliaton_FindCompanionShip() // Jason, НСО
{
	for(int i=1; i<COMPANION_MAX; i++)
	{
		int iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			ref sld = GetCharacter(iTemp);
			if(sld.ship.name == "Эклятон" && CheckAttribute(pchar, "questTemp.Patria.Ecliaton")) return true;
		}
	}
	return false;
}

bool Trafalgar_FindCompanionShip() // Jason, НСО
{
	for(int i=1; i<COMPANION_MAX; i++)
	{
		int iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			ref sld = GetCharacter(iTemp);
			if(sld.ship.name == "Трафальгар" && CheckAttribute(pchar, "questTemp.Patria.Trafalgar")) return true;
		}
	}
	return false;
}

bool Companion_CheckShipType(int iShipType) // поиск любого конкретного типа корабля у компаньона и запоминание индекса компаньона для дальнейшего использования
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

bool Caleuche_CheckAmulet() // Калеуче, амулеты
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

// Addon 2016-1 Jason Пиратская линейка
bool Mtraxx_MeridaCheckCarpenter() // проверка наличия плотника и его умений
{
	if (GetSummonSkillFromName(pchar, SKILL_REPAIR) >= 30 && sti(pchar.TmpPerks.BasicBattleState)) return true;
	if (sti(pchar.Fellows.Passengers.carpenter) > 0)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (GetSummonSkillFromName(sld, SKILL_REPAIR) >= 30 && sti(sld.TmpPerks.BasicBattleState)) return true;
	}
	return false;
}

string Mtraxx_RetributionSelectRanditem() // выбор рандитема
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

void MakeIndianPoisonAttack(ref chref, ref _attack) // яд индейцев таино
{
	// исключения
	if (CheckAttribute(chref, "chr_ai.immortal")) return;
	if (CheckAttribute(chref, "monster") || chref.chr_ai.group == LAI_GROUP_MONSTERS || chref.sex == "skeleton") return; // патч 17/1
	if (CheckAttribute(chref, "PoisonResistent"))
	{
		log_info("Яд не подействовал!");
		return;
	}
	if (LAi_GetCharacterHP(chref) < 15) 
	{
		if (CheckAttribute(chref, "chr_ai.immortal")) return;
		bool isSetBalde = (CheckAttribute(chref, "equip.blade") == true);
		LAi_SetImmortal(chref, true);
		//log_info("Персонаж с ID = "+chref.id+" с индексом "+chref.index+" и именем "+GetFullName(chref)+" достиг 15 НР");
		DeleteAttribute(chref, "quest.indianpoisoned");
		LAi_SetImmortal(chref, false);
		LAi_KillCharacter(chref);
	LAi_SetResultOfDeath(_attack, chref, isSetBalde, false);
		return;
	}
	sGlobalTemp = _attack.id; // атакующий один и тот же
	chref.quest.indianpoisoned = true;
	//log_info("Персонаж с ID = "+chref.id+" с индексом "+chref.index+" и именем "+GetFullName(chref)+" отравлен ядом таино");
	if (!CheckAttribute(chref, "quest.indianpoisoned.info"))
	{
		log_info(""+GetFullName(chref)+" отравлен ядом таино");
		chref.quest.indianpoisoned.info = true;
	}
	LAi_ApplyCharacterDamage(chref, 15, "other");
	DoQuestFunctionDelay("MakeIndianPoisonAttackCycle", 0.5);
}

void MakeIndianPoisonAttackCycle(string qName) // к функции выше
{
	DoQuestFunctionDelay("MakeTainoPoisonAttack", 0.5);
}

void MakeTainoPoisonAttack(string qName) // к функции выше
{
	ref chref, _attack;
	_attack = characterFromId(sGlobalTemp);
	for(int i=0; i<MAX_LOCATIONS; i++)
	{	
		chref = &characters[i];
		if (CheckAttribute(chref, "quest.indianpoisoned")) MakeIndianPoisonAttack(chref, _attack);
	}
}


// устанавливаем сторожевики на Гваделупу, сеттим каждый день 2015
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
		sld.DontHitInStorm = true; // не ломается в шторм
		sld.SinkTenPercent = false;
		sld.Abordage.Enable = false; // запрет абордажа
		sld.AlwaysSandbankManeuver = true;
		sld.MultiFighter = 1.5; // мультифайтер
		sld.MultiShooter = 1.5;
		sld.SuperShooter  = true;
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		Group_AddCharacter("Guadeloupe_Lee", "GuadeloupeLeeCap_"+i);
	}
	Group_SetGroupCommander("Guadeloupe_Lee", "GuadeloupeLeeCap_1");
	Group_SetTaskNone("Guadeloupe_Lee");//нет задачи
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



//Иниты Декстера, убийцы в городах
void BerglarsInit()
{
	pchar.questTemp.tugs.berglarState = 1; //счетчик
	//============> наёмник в Сент-Джонсе
	pchar.questTemp.tugs.berglarSentJons = "Town_Dungeon"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarSentJons.hp = 160; //сколько HP
	pchar.questTemp.tugs.berglarSentJons.locator = "reload7"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSentJons", "mercen_16", "man", "man", 22, ENGLAND, -1, false, "quest"));
	sld.name 	= "Карло";
	sld.lastname = "Гамбино";
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
	sld.talker = 7; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//=============> наёмник на Мартинике
	pchar.questTemp.tugs.berglarFortFrance = "FortFrance_Graveyard_Dungeon"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarFortFrance.hp = 228; //сколько HP
	pchar.questTemp.tugs.berglarFortFrance.locator = "reload2"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarFortFrance", "mercen_17", "man", "man", 23, FRANCE, -1, false, "quest"));
	sld.name 	= "Лаки";
	sld.lastname = "Лучано";
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
	sld.talker = 7; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.LifeDay = 3;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//============> наёмник в Мариго 
	pchar.questTemp.tugs.berglarMarigo = "Fishing_Settlement"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarMarigo.hp = 200; //сколько HP
	pchar.questTemp.tugs.berglarMarigo.locator = "gate_back"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarMarigo", "mercen_15", "man", "man", 21, HOLLAND, -1, false, "quest"));
	sld.name 	= "Джузеппе";
	sld.lastname = "Бонанно";
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
	sld.talker = 7; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	//============> наёмник в Шарлотт-Тауне
	pchar.questTemp.tugs.berglarRoseau = "Roseau_TownCave"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarRoseau.hp = 200; //сколько HP
	pchar.questTemp.tugs.berglarRoseau.locator = "basement1_back"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarRoseau", "mercen_14", "man", "man", 27, SPAIN, -1, false, "quest"));
	sld.name 	= "Винсент";
	sld.lastname = "Джиганте";
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
	sld.talker = 8; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//============> наёмник в Сент-Луисе
	pchar.questTemp.tugs.berglarSantLous = "SantLous_Dungeon"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarSantLous.hp = 170; //сколько HP
	pchar.questTemp.tugs.berglarSantLous.locator = "reload2"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSantLous", "mercen_7", "man", "man", 22, SPAIN, -1, false, "quest"));
	sld.name 	= "Джулико";
	sld.lastname = "Бандито";
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
	sld.talker = 7; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//============> наёмник в Санта Каталине
	pchar.questTemp.tugs.berglarSantaCatalina = "SantaCatalina_Graveyard_Dungeon"; //указание где забивать стрелу
	pchar.questTemp.tugs.berglarSantaCatalina.hp = 230; //сколько HP
	pchar.questTemp.tugs.berglarSantaCatalina.locator = "houseSp1"; //выходной локатор
	sld = GetCharacter(NPC_GenerateCharacter("BerglarSantaCatalina", "mercen_9", "man", "man", 25, SPAIN, -1, false, "quest"));
	sld.name 	= "Воро";
	sld.lastname = "Ганстерито";
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
	sld.talker = 7; //начать диалог
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
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	LAi_SetHP(sld, 1.0, 1.0);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("Dexterr", "Assassin2", "man", "man", 30, SPAIN, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "newblade18", "pistol_05", "cartridge", 100);
	sld.name 	= "Лоренцо";
	sld.lastname = "Аудиторе";
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
	sld.MultiFighter = 2.5; // мультифайтер
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

	// Рэндольф (отступники)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesRK", "Apostates_14", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "Рэндольф";
	sld.lastname = "Кэннелл";
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
	sld.HoldEquip = true; 	//не отдавать оружие
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetActorType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "PortAntonio_Bank_residence", "goto", "goto10");

	// Льюис (отступники)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesLA", "Apostates_13", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "Льюис";
	sld.lastname = "Аллард";
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
	sld.HoldEquip = true; 	//не отдавать оружие
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetSitType(sld);
	sld.item_date = "";
	sld.Merchant.type = "company";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "PortAntonio_Bank_residence", "sit", "sit2");

	//Джейкоб (отступники)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesDN", "Apostates_12", "man", "man2", 30, PIRATE, -1, false, "quest"));
	SetFantomParamFromRank(sld, 20, true);
	sld.name = "Джейкоб";
	sld.lastname = "Невил";
	RemoveAllCharacterItems(sld, true);
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "First time3";
	ChangeCharacterAddressGroup(sld, "PortAntonio_bank", "officers", "reload2_1");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);// закроем дверку до первого прихода

	// Ворон
	sld = GetCharacter(NPC_GenerateCharacter("Raven", "Apostates_22", "man", "man2", 30, PIRATE, -1, false, "quest"));
	sld.name = "Ворон";
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
	//sld.HoldEquip = true; 	//не отдавать оружие
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "Providence_Temple", "goto", "goto18");
	LAi_SetGuardianType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
}


void GothicNpcInit()//создаем всех ключевых персонажей по Готике здесь
{
	// Ксардас
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas", "Xsardas", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Ксардас";
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
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	//Стражи Ксардаса
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas_skel", "skel1", "skeleton", "skeleton", 10, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "Страж";
	sld.lastname = "Ксардаса";
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	RemoveAllCharacterItems(sld, true);
	sld.dialog.filename   = "Gothic_Quest\npc\Monster.c";
	sld.dialog.currentnode   = "First time_skel";
	ChangeCharacterAddressGroup(sld, "Xsardas_fort", "soldiers", "protector2");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	//Стражи Ксардаса
	sld = GetCharacter(NPC_GenerateCharacter("Xsardas_skelet", "skel2", "skeleton", "skeleton", 10, PIRATE, -1, false, "soldier"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "Страж";
	sld.lastname = "Ксардаса";
	RemoveAllCharacterItems(sld, true);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.dialog.filename   = "Gothic_Quest\npc\Monster.c";
	sld.dialog.currentnode   = "First time_skel";
	ChangeCharacterAddressGroup(sld, "Xsardas_fort", "soldiers", "protector1");
	GiveItem2Character(sld, "topor_04");
	sld.equip.blade = "topor_04";
	LAi_SetGuardianType(sld);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	
	// Сагитта
	sld = GetCharacter(NPC_GenerateCharacter("Sagitta", "Sagitta", "woman", "woman", 30, PIRATE, -1, false, "quest"));
	sld.name = "Сагитта";
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
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");
	//ChangeCharacterAddressGroup(sld, "Beliz_Cavern", "goto", "goto12");

	// Пират Аллигатор Джек
	sld = GetCharacter(NPC_GenerateCharacter("Alligator", "Alligator_0", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.FaceId = 482;
	sld.HeroModel = "Alligator_0,Alligator_1,Alligator_2,Alligator_3,Alligator_4,protocusto,Alligator_5";
	sld.model.animation = "man";
	sld.nation = PIRATE;
	sld.name = "Джек";
	sld.lastname = "Аллигатор";
	//sld.greeting = "Gr_Alligator";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 10;
	LAi_SetHP(sld, 200, 200);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // мультифайтер
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
	sld.standUp = true; //вставать и нападать на врага
	ChangeCharacterAddressGroup(sld, "Shore89", "goto", "goto1");
	LAi_SetGroundSitTypeNoGroup(sld);
	LAi_SetImmortal(sld, true);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	// Пират Самуил
	sld = GetCharacter(NPC_GenerateCharacter("Samuel", "rivados_4", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Самуил";
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

	// Наёмник Ли Торлоф
	sld = GetCharacter(NPC_GenerateCharacter("TORLOF", "GothicN_2", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Торлоф";
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
	
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_town", "goto", "goto16");
	LAi_SetGuardianType(sld);
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// Наёмник Ли Вольф
	sld = GetCharacter(NPC_GenerateCharacter("WOLF", "GothicN_5", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Вольф";
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
	
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_town", "goto", "goto2");
                   LAi_NoRebirthEnable(sld);
                   LAi_SetWarriorType(sld);
                   LAi_warrior_DialogEnable(sld, true);
                   LAi_SetLoginTime(sld, 0.0, 24.0);
                   sld.protector.CheckAlways = true;
	 LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// Наёмник Ли Ярвис
	sld = GetCharacter(NPC_GenerateCharacter("JARVIS", "GothicN_4", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Ярвис";
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
	
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_Tavern", "sit", "sit2");
	LAi_SetSitType(sld);
     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// Наёмник Ли Бастер
	sld = GetCharacter(NPC_GenerateCharacter("BUSTER", "GothicN_3", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Бастер";
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
	
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SantLous_Port", "sit", "sit1");
	LAi_SetSitType(sld);
                  sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "GOTHIC_CITIZENS");

	// Наёмник Ли
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
	
	sld.standUp = true; //вставать и нападать на врага
	ChangeCharacterAddressGroup(sld, "SantLous_Port", "goto", "ass1");
	LAi_SetGroundSitTypeNoGroup(sld);
                  sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");



	sld = GetCharacter(NPC_GenerateCharacter("Lucia", "Lucia", "woman", "Lucia", 30, PIRATE, -1, false, "quest"));
	sld.name = "Люция";
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
	
	sld.standUp = true; //вставать и нападать на врага
	sld.perks.list.ShipEscape = true;
	sld.perks.list.Ciras = true;
	LAi_SetLoginTime(sld, 12.0, 23.99);
	ChangeCharacterAddressGroup(sld, "SantLous_HouseInsideR4", "sit", "sit1");
	LAi_SetSitType(sld);
                     sld.protector.CheckAlways = true;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	//Аарон Мендес
	sld = GetCharacter(NPC_GenerateCharacter("Chumakeiro", "smuggler_boss", "man", "man", 20, HOLLAND, -1, false, "quest"));
	sld.name = "Аарон Мендес";
	sld.lastname = "Чумакейро";
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

	//Анна Рамирес де Лейва
	sld = GetCharacter(NPC_GenerateCharacter("AnnaDeLeiva", "Catherine", "woman", "woman", 10, SPAIN, -1, false, "quest"));
	sld.name = "Анна Рамирес";
	sld.lastname = "де Лейва";
	sld.greeting = "Gr_Dama";
	sld.rank = 10;
	LAi_SetHP(sld, 150, 150);
	sld.money = 5000;
	LAi_SetImmortal(sld, true);

	//Абуоин
	sld = GetCharacter(NPC_GenerateCharacter("Abuyin", "Abuyin", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "Абуоин";
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


	//Бальтрам
	sld = GetCharacter(NPC_GenerateCharacter("Baltram", "trader_16", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "Бальтрам";
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
    
    // Бывшая Данька. АйДи не меняю, т.к. нужно сменить просто модель и анимацию
	sld = GetCharacter(NPC_GenerateCharacter("Lorensia", "Lorensia11", "woman", "Lorensia", 30, PIRATE, -1, false, "quest"));
	sld.name = "Лоренсия";
	sld.lastname = "Джейнс";
	sld.greeting = "Gr_Lorensia";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.rank = 14;
	sld.greeting = "Gr_YokoDias";
	sld.MultiFighter = 2.0; // мультифайтер
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
	
	sld.standUp = true; //вставать и нападать на врага
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
	sld.name = "Миринда";
	sld.lastname = "Лопес";
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
	sld.MultiFighter = 2.0; // мультифайтер
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
	
	sld.standUp = true; //вставать и нападать на врага
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
	sld.name = "Фения";
	sld.lastname = "Шарден";
	sld.greeting = "Gr_Fenia";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.rank = 12;
	LAi_SetHP(sld, 260, 260);
	sld.money = 5000;
	sld.greeting = "Gr_YokoDias";
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.MultiFighter = 2.0; // мультифайтер
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
	 
	 sld.standUp = true; //вставать и нападать на врага
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
	sld.name = "Бони";
	sld.lastname = "Клайт";
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
	sld.MultiFighter = 2.0; // мультифайтер
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
	 sld.standUp = true; //вставать и нападать на врага
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
	sld.name 	= "Йоко";
	sld.lastname = "Диаз";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_YokoDias";
	sld.rank = 15;
	sld.MultiFighter = 2.0; // мультифайтер
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
	
	sld.standUp = true; //вставать и нападать на врага
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
	sld.name 	= "Анжелика";
	sld.lastname = "Шарп";
	sld.Dialog.Filename = "Enc_OfficerGirl.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_Angellica";
	sld.rank = 17;
	LAi_SetHP(sld, 250, 250);
	sld.money = 3000;
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.MultiFighter = 2.0; // мультифайтер
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
	
	sld.standUp = true; //вставать и нападать на врага
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
	sld.name = "Чани";
	sld.lastname = "";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Chani.c";
	sld.dialog.currentnode   = "First time";
	//sld.greeting = "Gr_Chani";
	sld.loyality = MAX_LOYALITY;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true; 
	sld.rank = 20;
	sld.MultiFighter = 2.0; // мультифайтер
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
    //мушкетер №1 - пират
    sld = GetCharacter(NPC_GenerateCharacter("OfMush1", "quest_mush_2", "man", "mushketer", 15, PIRATE, -1, true, "quest"));
	sld.name = "Николя";
	sld.lastname = "Рималье";
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
	sld.MultiFighter = 2.0; // мультифайтер
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
	locations[FindLocation("SeaShore126")].DisableEncounters = true; //энкаутеры в локации закроем до поры
	
	//мушкетер №2 - саксонец
	sld = GetCharacter(NPC_GenerateCharacter("OfMush2", "quest_mush_1", "man", "mushketer", 18, SPAIN, -1, true, "quest"));
	sld.name = "Магнус";
	sld.lastname = "Коккай";
	sld.greeting = "Gr_Officer";
	sld.rank = 18;
	LAi_SetHP(sld, 210, 210);
	sld.Dialog.Filename = "Enc_OfficerMush.c";
	sld.dialog.currentnode = "Saxon";
	TakeNItems(sld,"potion2", Rand(2)+2);
	GiveItem2Character(sld, "mushket");
	sld.equip.gun = "mushket";
	sld.MultiFighter = 2.0; // мультифайтер
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
	   ////////	   ПГГ	07. 17 - 02.18		//////////							
///// 	by Пират Либерталии & Джаред Старк     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////// Куба //////////////////////////

  /////////////////// Гавана //////////////////////

///////////////////     Эрнан Кортес   //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Cortes", "Cortes", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "Эрнан"; 
sld.lastname = "Кортес";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Святой Сантьяго"; 
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

///////////////////     Хосе Даско     //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Dasko", "Dasko", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "Хосе"; 
sld.lastname = "Даско";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан Кристобаль"; 
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


///////////////////     Рафаэль Лопес  //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Lopez", "Lopez", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "Рафаэль"; 
sld.lastname = "Лопес";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан Рафаэль"; 
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

/////////////////// Гавана //////////////////////


/////////////////// Сантьяго ///////////////////

/////////////////////// Инквизитор /////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Inqusitor", "Inqusitor", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "Инквизитор";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Трибунал"; 
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


///////////////////// Посланник Божий ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Posol", "Posol", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "Посланник"; 
sld.lastname = "Божий"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Голгофа"; 
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

/////////////////////// Странник /////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Strannik", "Strannik", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Странник"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Стервятник"; 
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

/////////////////// Сантьяго ///////////////////


//////////////// Пуэрто Принсипе ///////////////

/////////////////// Моко ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Blackman", "Blackman", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Моко";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Мулунгу"; 
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

/////////////////// Билли Бонс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Skull", "Skull", "man", "man_B", 32, PIRATE, -1, false, "quest"));
sld.name = "Билли";
sld.lastname = "Бонс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Морж"; 
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

/////////////////// Жан Давид ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1_3", "Corsair1_3", "man", "man_B", 5, PIRATE, -1, false, "quest"));
sld.name = "Жан-Давид";
sld.lastname = "Но"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Гончая"; 
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

//////////////// Пуэрто Принсипе ///////////////


///////////////////// Куба //////////////////////////


/////////////////// Тортуга ///////////////////

///////////////////// Пьер Пикардиец ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Beltro", "Beltro", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Пьер"; 
sld.lastname = "Пикардиец"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ле Авонтьюри"; 
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


////////////////////// Кристиан Дюбуа ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Captaine_Chevalle", "Captaine_Chevalle", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Кристиан"; 
sld.lastname = "Дюбуа"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бельфегор"; 
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

////////////////////  Бернар Маринэ  ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("offi_fra", "offi_fra", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "Бернар"; 
sld.lastname = "Маринэ"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бонапарт"; 
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

////////////////////  Жаннета Ламотт  ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Daniell2", "Daniell2", "woman", "WomanK2", 10, PIRATE, -1, false, "quest"));
sld.name = "Жаннета";
sld.lastname = "Ламотт"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Орлеанская Дева"; 
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

/////////////////// Тортуга ///////////////////

/////////////////// Пуэрто-Рико ///////////////////

/////////////////// Сан-Хуан ///////////////////

/////////////////// Леон ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Leon", "Leon", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Леон"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Рассвет"; 
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

/////////////////// Массимо Беларди ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("searcher", "searcher", "man", "man_B", 20, SPAIN, -1, false, "quest"));
sld.name = "Массимо"; 
sld.lastname = "Беларди"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан Марко"; 
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

/////////////////// Хуан Гарсия ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Man3_1", "Man3_1", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Хуан"; 
sld.lastname = "Гарсия"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Лазурный Бриз"; 
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

/////////////////// Сан-Хуан ///////////////////

/////////////////// Вилья Аллегрия ///////////////////

/////////////////// Эмилио Монтенегро ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Chameleon", "Chameleon", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Эмилио"; 
sld.lastname = "Монтенегро"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Удача"; 
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

/////////////////// Рикардо де ла Вега ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("my_gg", "my_gg", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Рикардо"; 
sld.lastname = "де ла Вега"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Буэна Суертэ"; 
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

/////////////////// Жирный Золло ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("fatman", "fatman", "man", "man_B", 5, PIRATE, -1, false, "quest"));
sld.name = "Жирный"; 
sld.lastname = "Золло"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Тюхе"; 
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

/////////////////// Вилья Аллегрия ///////////////////

/////////////////// Пуэрто-Рико ///////////////////

/////////////////// Эспаньола ///////////////////

/////////////////// Ла-Вега ///////////////////

/////////////////// Адриан Патер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sailor13", "Sailor13", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Адриан"; 
sld.lastname = "Патер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Шепот урагана"; 
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

/////////////////// Чарли Красавчик ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat9", "pirat9", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "Чарли"; 
sld.lastname = "Красавчик"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Вендетта"; 
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

/////////////////// Уильям Джексон ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Lou", "Lou", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Уильям"; 
sld.lastname = "Джексон";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Последний Шторм"; 
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

/////////////////// Арабелла Драммонд ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bella", "Bella", "woman", "WomanK2", 25, PIRATE, -1, false, "quest"));
sld.name = "Арабелла";
sld.lastname = "Драммонд"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Лихая Авантюра"; 
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

/////////////////// Ла-Вега ///////////////////

/////////////////// Порт-о-Пренс ///////////////////

/////////////////// Пьер-Шарль Вильнёв ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Vilnev", "Vilnev", "man", "man", 40, FRANCE, -1, false, "quest"));
sld.name = "Пьер-Шарль"; 
sld.lastname = "Вильнёв";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Королевское Солнце"; 
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

/////////////////// Жан-Поль Сюмор ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sumor", "Sumor", "man", "man_B", 30, FRANCE, -1, false, "quest"));
sld.name = "Жан-Поль";
sld.lastname = "Сюмор"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Мартелл"; 
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

///////////////////// Гийом Шампань ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Shampan", "Shampan", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Гийом"; 
sld.lastname = "Шампань"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ля Фортюн"; 
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

/////////////////// Порт-о-Пренс ///////////////////

/////////////////// Санто-Доминго ///////////////////

/////////////////// Санчо Панса ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pansa", "Pansa", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "Санчо";
sld.lastname = "Панса"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Дон Кихот"; 
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

/////////////////// Алонсо Кеханда ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Kihot", "Kihot", "man", "man_B", 25, SPAIN, -1, false, "quest"));
sld.name = "Алонсо";
sld.lastname = "Кеханда"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Последний Рыцарь"; 
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

/////////////// Мигель де Сервантес //////////////

sld = GetCharacter(NPC_GenerateCharacter("Servantes", "Servantes", "man", "man_B", 22, SPAIN, -1, false, "quest"));
sld.name = "Мигель";
sld.lastname = "де Сервантес"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Росинант"; 
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

/////////////////// Санто-Доминго ///////////////////

/////////////////// Ле-Ке ///////////////////

/////////////////// Джим Хокинс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pitt_2", "Pitt_2", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Джим";
sld.lastname = "Хокинс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Русалка"; 
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

/////////////////// Санчос Эстебан ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sancho", "Sancho_1", "man", "man", 18, PIRATE, -1, false, "quest"));
sld.name = "Санчос";
sld.lastname = "Эстебан"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Испанец"; 
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

/////////////////// Питер Блэйк ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("PitBleik", "PitBleik_0", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "Питер";
sld.lastname = "Блэйк"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Европа"; 
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

/////////////////// Ле-Ке ///////////////////

/////////////////// Эспаньола ///////////////////

/////////////////// Мартиника ///////////////////

/////////////////// Форт де Франс ///////////////////

/////////////////// Жак Соловей ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jack", "Jack", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Жак";
sld.lastname = "Соловей"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Жемчуг"; 
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


/////////////////// Андре Варансе ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("will_2", "will_2", "man", "man_B", 9, PIRATE, -1, false, "quest"));
sld.name = "Андре";
sld.lastname = "Варансе"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ночной кошмар"; 
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

/////////////////// Дидье Борегар ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Soldier_Fra6", "Soldier_Fra6", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "Дидье";
sld.lastname = "Борегар"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Афродита"; 
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

/////////////////// Форт де Франс ///////////////////


/////////////////// Ле Франсуа ///////////////////

/////////////////// Джон Сильвер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("corsair3", "corsair3", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Джон";
sld.lastname = "Сильвер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Испаньола"; 
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


/////////////////// Тиг Воробей ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("CaptainTeague", "CaptainTeague", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Тиг";
sld.lastname = "Воробей"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Кодекс"; 
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

/////////////////// Джошами Гиббс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("bocman5", "bocman5", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Джошами";
sld.lastname = "Гиббс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Тортуга"; 
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
SetCharacterGoods(sld, GOOD_RUM, 550); // мистер Гиббс в фильмах очень любил ром:)
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.59); 
LAi_SetHP(sld, 345+MOD_SKILL_ENEMY_RATE*10, 345+MOD_SKILL_ENEMY_RATE*10); 

/////////////////// Энн Бонни ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bonni", "Bonni", "woman", "WomanK2", 10, PIRATE, -1, false, "quest"));
sld.name = "Энн";
sld.lastname = "Бонни"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Эсмеральда"; 
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

/////////////////// Ле Франсуа ///////////////////

/////////////////// Мартиника ///////////////////

/////////////////// Ямайка ///////////////////

/////////////////// Порт Рояль ///////////////////

/////////////////// Уилл Тёрнер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("will", "will", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Уилл"; 
sld.lastname = "Тёрнер";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Элизабет"; 
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


/////////////////// Джеймс Норрингтон ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Norrington", "Norrington_0", "man", "man", 40, ENGLAND, -1, false, "quest"));
sld.name = "Джеймс"; 
sld.lastname = "Норрингтон";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Разящий"; 
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

/////////////////// Оливер Айзман ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("offic_eng", "offic_eng", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Оливер";
sld.lastname = "Айзман"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Перехватчик"; 
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

/////////////////// Грейс О`Мэлли ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Grace", "Grace", "woman", "WomanK2", 15, PIRATE, -1, false, "quest"));
sld.name = "Грейс";
sld.lastname = "О`Мэлли"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Секира"; 
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

/////////////////// Порт Рояль ///////////////////

/////////////////// Саванна-ла-Мар ///////////////////

/////////////////// Гектор Барбосса ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat10", "pirat10", "man", "man_B", 26, PIRATE, -1, false, "quest"));
sld.name = "Гектор";
sld.lastname = "Барбосса"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Месть"; 
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

/////////////////// Элихио ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Lejitos", "Lejitos", "man", "Balthrop", 23, PIRATE, -1, false, "quest"));
sld.name = "Элихио";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ягуар"; 
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


/////////////////// Джон Слэйтер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Johnsltr1", "Johnsltr1", "man", "man", 19, PIRATE, -1, false, "quest"));
sld.name = "Джон";
sld.lastname = "Слэйтер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Гарпия"; 
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

/////////////////// Мэри Рид ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rid", "Rid", "woman", "WomanK2", 18, PIRATE, -1, false, "quest"));
sld.name = "Мэри";
sld.lastname = "Рид"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Хаунд"; 
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

/////////////////// Саванна-ла-Мар ///////////////////

/////////////////// Форт Оранж ///////////////////

/////////////////// Оливер ван Норт  ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Oliver", "Oliver_0", "man", "man", 18, HOLLAND, -1, false, "quest"));
sld.name = "Оливер";
sld.lastname = "ван Норт"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Маврикий"; 
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

/////////////////// Йорис Спилберген ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Yoris", "Yoris_0", "man", "man", 20, HOLLAND, -1, false, "quest"));
sld.name = "Йорис";
sld.lastname = "Спилберген"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Согласие"; 
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

/////////////////// Йохан Даринг ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Yohang", "Yohang", "man", "man", 15, HOLLAND, -1, false, "quest"));
sld.name = "Йохан";
sld.lastname = "Даринг"; 
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
sld.Ship.Name = "Аврора"; 
sld.Ship.Type = GenerateShipExt(SHIP_SLOOP, true, sld); 
sld.Ship.Stopped = true; 
sld.Ship.Mode = "pirate";
sld.MultiFighter = 1.5; // мультифайтер
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

/////////////////// Форт Оранж ///////////////////

/////////////////// Ямайка ///////////////////

/////////////////// Барбадос ///////////////////

/////////////////// Бриджтаун ///////////////////

/////////////////// Шон Леонард ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Offic_Eng_16", "Offic_Eng_16", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Шон";
sld.lastname = "Леонард"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Восхождение"; 
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

/////////////////// Джереми Триппс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jeremy_Tripper", "Jeremy_Tripper", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Джереми";
sld.lastname = "Триппс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Мэйфлауэр"; 
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

/////////////////// Дэвид Ливси ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("fra_lut_18", "fra_lut_18", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Дэвид";
sld.lastname = "Ливси"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Королева"; 
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

/////////////////// Рейчел Уолл ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("BeatriceZ", "BeatriceZ", "woman", "Angellica", 11, PIRATE, -1, false, "quest"));
sld.name = "Рейчел";
sld.lastname = "Уолл"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Пророчество"; 
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

/////////////////// Бриджтаун ///////////////////

/////////////////// Барбадос ///////////////////

/////////////////// Исла-Тесорро ///////////////////

/////////////////// Шарптаун ///////////////////

/////////////////// Уильям Кидд ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("47_Norrington_Pirate", "47_Norrington_Pirate", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Уильям";
sld.lastname = "Кидд"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Приключение"; 
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

/////////////////// Жак де Сор ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sor", "Sor", "man", "man_B", 12, PIRATE, -1, false, "quest"));
sld.name = "Жак";
sld.lastname = "де Сор"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Джокер"; 
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


/////////////////// Рок Бразилец ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Shkiper", "Shkiper", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Рок";
sld.lastname = "Бразилец"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бразильяно"; 
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

/////////////////// Анамария ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Anamaria", "Anamaria", "woman", "YokoDias", 23, PIRATE, -1, false, "quest"));
sld.name = "Анамария";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Свобода"; 
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

/////////////////// Шарптаун ///////////////////

/////////////////// Исла-Тесорро ///////////////////

/////////////////// Сан-Мартин ///////////////////

/////////////////// Филиппсбург ///////////////////

/////////////////// Мартин Ван Вит ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Offic_Hol_16", "Offic_Hol_16", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Мартин";
sld.lastname = "Ван Вит"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Мермин"; 
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


/////////////////// Клаус Штёртебеккер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Buccaneer1", "Buccaneer1", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Клаус";
sld.lastname = "Штертебеккер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ганза"; 
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

/////////////////// Ян Стейс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Steys", "Steys", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Ян"; 
sld.lastname = "Стейс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Штатгальтер"; 
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

/////////////////// Филиппсбург ///////////////////

/////////////////// Деревня Рыбаков ///////////////////

/////////////////// Бобби ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Bobby", "Bobby", "man", "man_B", 1, PIRATE, -1, false, "quest"));
sld.name = "Бобби";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Дохлая Чайка"; 
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

/////////////////// Пип ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pip", "Pip", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Пип";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бешенное Корыто"; 
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


/////////////////// Мужик ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("brodyaga", "brodyaga", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Мужик";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Доска"; 
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

/////////////////// Деревня Рыбаков ///////////////////

/////////////////// Сан-Мартин ///////////////////

/////////////////// Антигуа ///////////////////

/////////////////// Сент-Джонс ///////////////////

//////////////// Малькольм Шервуд/////////////////

sld = GetCharacter(NPC_GenerateCharacter("fawn", "fawn", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Малькольм";
sld.lastname = "Шервуд"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Фортуна"; 
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

//////////////// Алекс Эксквемелин /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Alex_blade", "Alex_blade", "man", "man", 21, PIRATE, -1, false, "quest"));
sld.name = "Алекс";
sld.lastname = "Эксквемелин"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Пеликан"; 
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

//////////////// Горацио Хорнблауэр /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Navy_Off", "Navy_Off", "man", "man_B", 28, PIRATE, -1, false, "quest"));
sld.name = "Горацио";
sld.lastname = "Хорнблауэр"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Отчаянный"; 
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

//////////////// Сейди Фаррелл /////////////////

sld = GetCharacter(NPC_GenerateCharacter("Farell", "Farell", "woman", "WomanK2", 28, PIRATE, -1, false, "quest"));
sld.name = "Сейди";
sld.lastname = "Фаррелл"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Королева Солнца"; 
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

/////////////////// Антигуа ///////////////////

/////////////////// Сент-Джонс ///////////////////

/////////////////// Кюрасао ///////////////////

/////////////////// Виллемстад ///////////////////

/////////////////// Робин Голландец ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("pirat5", "pirat5", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Робин";
sld.lastname = "Голландец"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Батавия"; 
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

/////////////////// Винсент Ван Стаал ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1", "Corsair1", "man", "man_B", 16, PIRATE, -1, false, "quest"));
sld.name = "Винсент";
sld.lastname = "Ван Стаал"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Амстердам"; 
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

/////////////////// Питер Хэйн ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("captain", "PitHeyn", "man", "man", 40, HOLLAND, -1, false, "quest"));
sld.name = "Питер"; 
sld.lastname = "Хэйн";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Республика"; 
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

/////////////////// Штаб-квартира ГВИК ///////////////////

/////////////////// Сяо Фэнь ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("SaoFeng", "SaoFeng", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "Сяо";
sld.lastname = "Фэнь"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Императрица"; 
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

/////////////////// Штаб-квартира ГВИК ///////////////////

/////////////////// Виллемстад ///////////////////

/////////////////// Вестпунт ///////////////////

/////////////////// Израэль Хэндс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("BigPirate", "BigPirate", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "Израэль";
sld.lastname = "Хэндс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Белый Клык"; 
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

/////////////////// Майкл Чард ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Chard", "Chard", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Майкл";
sld.lastname = "Чард"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Судья"; 
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

/////////////////// Джон Истерлинг ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "Isterling", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "Джон"; 
sld.lastname = "Истерлинг";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Добрый День"; 
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

/////////////////// Вестпунт ///////////////////

/////////////////// Кюрасао ///////////////////

/////////////////// Гваделупа ///////////////////

/////////////////// Бас-Тер///////////////////

/////////////// Жан-Жак Гранье //////////////

sld = GetCharacter(NPC_GenerateCharacter("granie", "granie", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "Жан-Жак";
sld.lastname = "Гранье"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бурбон"; 
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


/////////////// Пьер Легран //////////////

sld = GetCharacter(NPC_GenerateCharacter("Chard3c", "Chard3c", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "Пьер"; 
sld.lastname = "Легран"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Либерта";
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

/////////////// Андрэ Ламоро //////////////

sld = GetCharacter(NPC_GenerateCharacter("Francois_L'Ollenais", "Francois_L'Ollenais", "man", "man_B", 22, PIRATE, -1, false, "quest"));
sld.name = "Андрэ";
sld.lastname = "Ламоро"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Дельфин"; 
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

/////////////////// Русский Дом ///////////////////

/////////////////// Александр Дубинин ///////////////////

// по просьбе трудящихся в Бас-Тере у нас русская диаспора:)

sld = GetCharacter(NPC_GenerateCharacter("alexander", "alexander", "man", "Moscovit", 20, PIRATE, -1, false, "quest"));
sld.name = "Александр";
sld.lastname = "Дубинин"; 
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
sld.MultiFighter = 1.5; // мультифайтер
sld.MultiShooter = 1.5;
sld.nation = PIRATE // RUSSIAN блеать! :)
sld.money = 30000; 
sld.location = "BasTer_houseSp1"; 
sld.location.group = "sit"; 
sld.location.locator = "sit2";
sld.greeting = "Rus_Captain"; 
sld.Dialog.Filename = "Population\PGG.c";
sld.standUp = true; //вставать и нападать на врага
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
sld.Ship.Name = "Святой Евстафий"; 
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
SetCharacterGoods(sld, GOOD_WINE, 300); // славяне не прочь бухнуть:)
UpgradeShipParameter(sld, "Capacity");
LAi_SetSitType(sld); 
LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS"); 
LAi_SetLoginTime(sld, 16.00, 23.99);  
LAi_SetHP(sld, 650+MOD_SKILL_ENEMY_RATE*10, 650+MOD_SKILL_ENEMY_RATE*10);

/////////////////// Андрей Воронцов ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Andrey", "Andrey_0", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "Андрей";
sld.lastname = "Воронцов"; 
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
sld.standUp = true; //вставать и нападать на врага
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Меркурий"; 
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

/////////////////// Игорь Куракин ///////////////////
sld = GetCharacter(NPC_GenerateCharacter("Kurakin", "Kurakin", "man", "man", 20, FRANCE, -1, false, "quest"));
sld.name = "Игорь";
sld.lastname = "Куракин"; 
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
sld.MultiFighter = 1.5; // мультифайтер
sld.MultiShooter = 1.5;
sld.Dialog.Filename = "Population\PGG.c";
sld.standUp = true; //вставать и нападать на врага
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
sld.Ship.Name = "Орёл"; 
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

/////////////////// Русский Дом ///////////////////

/////////////////// Сент-Луи ///////////////////

/////////////////// Пабло Мурьетта ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Emilio1", "Emilio1", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Пабло";
sld.lastname = "Мурьетта"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Дублон"; 
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

/////////////////// Томас Печ ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pitt_3", "Pitt_3", "man", "man", 18, PIRATE, -1, false, "quest"));
sld.name = "Томас";
sld.lastname = "Печ"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Софи"; 
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

/////////////////// Тукан Махлак ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("QuestMan1", "QuestMan1", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "Тукан";
sld.lastname = "Махлак"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Генерал Хэммонд"; 
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

/////////////////// Сент-Луи ///////////////////

/////////////////// Гваделупа ///////////////////

/////////////////// Сент-Кристофер ///////////////////

/////////////////// Капстервиль ///////////////////

/////////////////// Франсуа Ле Клер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("LeKlerk", "LeKlerk", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "Франсуа";
sld.lastname = "Ле Клер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Катрин"; 
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

/////////////////// Антуан Ксавье ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Antuan", "Antuan_0", "man", "man", 35, FRANCE, -1, false, "quest"));
sld.name = "Антуан"; 
sld.lastname = "Ксавье";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Версаль"; 
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

/////////////////// Рауль де Бражелон ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "Rabel_Chardon", "man", "man_B", 35, PIRATE, -1, false, "quest"));
sld.name = "Рауль"; 
sld.lastname = "де Бражелон";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Нимфа"; 
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

/////////////////// Капстервиль ///////////////////

/////////////////// Сент-Кристофер ///////////////////

/////////////////// Тринидад и Тобаго ///////////////////

/////////////////// Сан-Хосе ///////////////////

/////////////////// Криштиану Фернандеш ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Corsair1_4", "Corsair1_4", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Криштиану";
sld.lastname = "Фернандеш"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан Габриэл"; 
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

/////////////////// Андрес де Арриола ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Arr_0", "Arr_0", "man", "man_B", 18, PIRATE, -1, false, "quest"));
sld.name = "Андрес";
sld.lastname = "де Арриола"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Новый Свет"; 
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

/////////////////// Хосе Матеос ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Esteban", "Esteban", "man", "man", 12, PIRATE, -1, false, "quest"));
sld.name = "Хосе";
sld.lastname = "Матеос"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Изабелла"; 
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

/////////////////// Тринидад и Тобаго ///////////////////

/////////////////// Сан-Хосе ///////////////////

/////////////////// Доминика ///////////////////

/////////////////// Шарлотт-Таун ///////////////////

/////////////////// Джэк Рэкхэм ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Hornblauer", "Hornblauer", "man", "man", 20, PIRATE, -1, false, "quest"));
sld.name = "Джэк";
sld.lastname = "Рэкхэм"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сокровище"; 
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

/////////////////// Маркус Ульссон ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("killer", "killer", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Маркус";
sld.lastname = "Ульссон"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Хельга"; 
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

/////////////////// Робер Сюркуф ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rober", "Rober_Sur_0", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "Робер";
sld.lastname = "Сюркуф"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Эмили"; 
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

/////////////////// Шарлотт-Таун ///////////////////

/////////////////// Деревня Карибов ///////////////////

///////////////////// Мататопа ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Matatopa", "Matatopa", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Мататопа"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Четыре Медведя"; 
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

/////////////////// Деревня Карибов ///////////////////

/////////////////// Доминика ///////////////////

/////////////////// Юкатан ///////////////////

/////////////////// Белиз ///////////////////

/////////////////// Джеймс Маккарти ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("James2", "James2", "man", "man", 10, PIRATE, -1, false, "quest"));
sld.name = "Джеймс";
sld.lastname = "Маккарти"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Шеппертон"; 
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

/////////////////// Артур Уэсли ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Dragoon_2", "Dragoon_2", "man", "man", 35, PIRATE, -1, false, "quest"));
sld.name = "Артур"; 
sld.lastname = "Уэсли";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Виктория"; 
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

/////////////////// Вудс Роджерс ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Forester", "Forester", "man", "man", 15, PIRATE, -1, false, "quest"));
sld.name = "Вудс";
sld.lastname = "Роджерс"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Герцог"; 
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

/////////////////// Лара Крофт ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("LCroft", "LCroft", "woman", "WomanK2", 16, PIRATE, -1, false, "quest"));
sld.name = "Лара";
sld.lastname = "Крофт"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Глубина"; 
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

/////////////////// Юкатан ///////////////////

/////////////////// Белиз ///////////////////

/////////////////// Западный Мэйн ///////////////////

/////////////////// Блуфилдс ///////////////////

/////////////////// Александр Смолетт ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("spa_lut_18", "spa_lut_18", "man", "man_B", 16, PIRATE, -1, false, "quest"));
sld.name = "Александр";
sld.lastname = "Смолетт"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Рейнджер"; 
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

/////////////////// Лайонел Уофер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Uof_0", "Uof_0", "man", "man", 21, PIRATE, -1, false, "quest"));
sld.name = "Лайонел";
sld.lastname = "Уофер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Эндэвор"; 
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

/////////////////// Френсис Дрейк ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("brtcpt1_18", "brtcpt1_18", "man", "man_B", 32, PIRATE, -1, false, "quest"));
sld.name = "Френсис";
sld.lastname = "Дрейк"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Золотая Лань"; 
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

/////////////////// Блуфилдс ///////////////////

/////////////////// Деревня Мискито ///////////////////

///////////////////     Чингачгук   //////////////////////
sld = GetCharacter(NPC_GenerateCharacter("Chingachguk", "Chingachguk", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Чингачгук"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Большой Змей"; 
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

/////////////////// Деревня Мискито ///////////////////

/////////////////// Деревня Аборигенов ///////////////////

/////////////////// Магуа ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Magua", "Magua", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Магуа"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ироку"; 
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

/////////////////// Деревня Аборигенов ///////////////////

/////////////////// Западный Мэйн ///////////////////

/////////////////// Мэйн ///////////////////

/////////////////// Новая Гранада ///////////////////

/////////////////// Рудник Лос Текес ///////////////////

/////////////////// Эрнесто Гевара ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gevara", "Gevara", "man", "Balthrop", 12, PIRATE, -1, false, "quest"));
sld.name = "Эрнесто";
sld.lastname = "Гевара"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Герилья"; 
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

/////////////////// Йозеф фон Зальтер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("black_reitar", "black_reitar", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "Йозеф";
sld.lastname = "фон Зальтер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Кайзер"; 
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

/////////////////// Хулио Санчес ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Hulio", "Hulio", "man", "man_B_ab", 25, PIRATE, -1, false, "quest"));
sld.name = "Хулио";
sld.lastname = "Санчес"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Идальго"; 
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

/////////////////// Рудник Лос Текес ///////////////////

///////////////////// Кумана ///////////////////////////

////////////////// Альфонсо Диаз ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Alfons", "Alfons", "man", "man_B", 27, PIRATE, -1, false, "quest"));
sld.name = "Альфонсо"; 
sld.lastname = "Диаз";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Андалусия"; 
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

////////////////// Луиджи да Мосто ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Veneto", "Veneto", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Луиджи"; 
sld.lastname = "да Мосто";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Левант"; 
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

////////////////// Диогу Гомеш ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Portugall", "Portugall", "man", "man_B", 10, PIRATE, -1, false, "quest"));
sld.name = "Диогу";
sld.lastname = "Гомеш"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан-Николау"; 
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

///////////////////// Кумана ///////////////////////////

///////////////////// Каракас ///////////////////////////

/////////////////// Хуго де Рекальдо ///////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Rikaldo", "Rikaldo", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Хуго";
sld.lastname = "де Рекальдо"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бискайя"; 
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

/////////////////// Гаспар Коррейра ///////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gasparo", "Gasparo", "man", "man_B", 30, PIRATE, -1, false, "quest"));
sld.name = "Гаспар";
sld.lastname = "Коррейра"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Санта-Лузия"; 
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

/////////////////// Томмазо Морозини /////////////////////////// 

sld = GetCharacter(NPC_GenerateCharacter("Italian", "Italian", "man", "man_B", 18, PIRATE, -1, false, "quest"));
sld.name = "Томмазо";
sld.lastname = "Морозини"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Реал"; 
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

/////////////////// Селеста Кортес /////////////////////////// 

sld = GetCharacter(NPC_GenerateCharacter("Daniell1", "Daniell1", "woman", "WomanK2", 20, PIRATE, -1, false, "quest"));
sld.name = "Селеста";
sld.lastname = "Кортес"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Дева Мария"; 
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

///////////////////// Каракас ///////////////////////////

///////////////////// Маракайбо ///////////////////////////

/////////////////// Витторио Пизани ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Venetian", "Venetian", "man", "man_B", 13, PIRATE, -1, false, "quest"));
sld.name = "Витторио";
sld.lastname = "Пизани"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан-Леандро"; 
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

/////////////////// Бенто де Гоиш ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Goish", "Goish", "man", "man_B", 7, PIRATE, -1, false, "quest"));
sld.name = "Бенто";
sld.lastname = "де Гоиш"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Нептуно"; 
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

/////////////////// Федерико Гравина ///////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gravina", "Gravina", "man", "man_B", 20, PIRATE, -1, false, "quest"));
sld.name = "Федерико";
sld.lastname = "Гравина"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Монарка"; 
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

///////////////////// Маракайбо ///////////////////////////

/////////////////// Деревня Араваков ///////////////////

///////////////////     Джеронимо   //////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Jeronimo", "Jeronimo", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Джеронимо"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Воля Маниту"; 
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

/////////////////// Деревня Араваков ///////////////////

///////////////////// Картахена ///////////////////////////

/////////////////// Адриано Дуодо ////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Genova", "Genova", "man", "man_B", 25, PIRATE, -1, false, "quest"));
sld.name = "Адриано";
sld.lastname = "Дуодо"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан-Агустин"; 
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

/////////////////// Ивенш Ферраш ////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Ferrash", "Ferrash", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Ивенш";
sld.lastname = "Ферраш"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан-Хусто"; 
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

///////////////// Фернандес де Кордоба //////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Kordoba", "Kordoba", "man", "man_B", 15, PIRATE, -1, false, "quest"));
sld.name = "Фернандес";
sld.lastname = "де Кордоба"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сан-Хуан"; 
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

///////////////////// Картахена ///////////////////////////

/////////////////// Новая Гранада ///////////////////

///////////////////// Перешеек ///////////////////////////

/////////////////// Порто-Белло ///////////////////

/////////////// Муцио Аттендоло //////////////

sld = GetCharacter(NPC_GenerateCharacter("Muzio", "Muzio", "man", "man_B", 30, SPAIN, -1, false, "quest"));
sld.name = "Муцио";
sld.lastname = "Аттендоло"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Сфорца"; 
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

/////////////// Фридрих Фрундсберг //////////////

sld = GetCharacter(NPC_GenerateCharacter("Fritz", "Fritz", "man", "man_B", 20, SPAIN, -1, false, "quest"));
sld.name = "Фридрих"; 
sld.lastname = "Фрундсберг"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Гамбург";
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

/////////////////// Агосто де Вальенте ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Agosto", "Agosto", "man", "man_B", 5, SPAIN, -1, false, "quest"));
sld.name = "Агосто";
sld.lastname = "де Вальенте"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ренессанс"; 
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

/////////////////// Порто-Белло ///////////////////

/////////////////// Деревня Индейцев ///////////////////

/////////////////// Бешеный Конь ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("capitan", "CrazyHorse", "man", "man", 25, PIRATE, -1, false, "quest"));
sld.name = "Бешеный"; 
sld.lastname = "Конь";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Лакота"; 
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

/////////////////// Деревня Индейцев ///////////////////

/////////////////// Панама ///////////////////

/////////////////     Франсиско Писарро   ////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Pisarro", "Pisarro", "man", "man_B", 30, SPAIN, -1, false, "quest"));
sld.name = "Франсиско"; 
sld.lastname = "Писарро";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Завоеватель"; 
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

/////////////////// Диего де Альмагро ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Almagro", "Almagro", "man", "man", 30, SPAIN, -1, false, "quest"));
sld.name = "Диего"; 
sld.lastname = "де Альмагро";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Открытие"; 
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

/////////////////// Генрих фон Ридегер ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Gans", "Gans", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "Генрих";
sld.lastname = "фон Ридегер"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Бремен"; 
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

/////////////////// Панама ///////////////////

///////////////////// Перешеек ///////////////////////////

///////////////////// Провиденсия ///////////////////////////

/////////////////// Сан-Андерс ///////////////////

/////////////////// Пилигрим ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Piligrim", "Piligrim", "man", "man_B", 15, SPAIN, -1, false, "quest"));
sld.name = "Пилигрим";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Иерусалим"; 
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

/////////////////// Слуга Господа ///////////////////

sld = GetCharacter(NPC_GenerateCharacter("Sluga", "Sluga", "man", "man_B", 25, SPAIN, -1, false, "quest"));
sld.name = "Слуга";
sld.lastname = "Господа"; 
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Крестоносец"; 
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

/////////////// Легат //////////////

sld = GetCharacter(NPC_GenerateCharacter("Legat", "Legat", "man", "man_B", 22, SPAIN, -1, false, "quest"));
sld.name = "Легат";
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
sld.MultiFighter = 1.5; // мультифайтер
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
sld.Ship.Name = "Ватикан"; 
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

/////////////////// Сан-Андерс ///////////////////

///////////////////// Провиденсия ///////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   ////////	   ПГГ	07. 17 - 02.18		//////////							
///// 	by Пират Либерталии & Джаред Старк     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   //////// Убер-офицеры пасхалки   03.18	//////////							
///// 	by Пират Либерталии     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////// Терминатор //////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Terminatorr", "Terminatorr", "man", "man", 55, PIRATE, -1, false, "quest"));
sld.name = "Терминатор";
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
sld.MultiFighter = 10.0; // мультифайтер
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

////////////////////// Мумия //////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("Mumiya", "Mumiya", "man", "man_B", 55, PIRATE, -1, false, "quest"));
sld.name = "Мумия";
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
sld.MultiFighter = 10.0; // мультифайтер
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

//////////////////// Весёлый Роджер ////////////////////////////

sld = GetCharacter(NPC_GenerateCharacter("JollyRoger", "JollyRoger", "man", "man_B", 55, PIRATE, -1, false, "quest"));
sld.name = "Весёлый";
sld.lastname = "Роджер"; 
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
sld.MultiFighter = 10.0; // мультифайтер
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
sld.Ship.Name = "Дыхание Смерти"; 
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
	   //////// Убер-офицеры пасхалки   03.18	//////////							
///// 	by Пират Либерталии     /////					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//заказчик нищих
sld = GetCharacter(NPC_GenerateCharacter("PoorKillSponsor", "smuggler_boss", "man", "man", 30, PIRATE, -1, false, "quest"));
sld.name = "Оливер";
sld.lastname = "Траст"; 
sld.talker = 8; //начать диалог
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

void LSCCNpcInit()//создаем всех ключевых персонажей по ГПК здесь
{
	//мэр-адмирал
	sld = GetCharacter(NPC_GenerateCharacter("LSCCMayor", "capitan_2", "man", "man", 50, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 50, 90, 90, "blade_31", "pistol4", "bullet", 200);
	sld.name = "Чад";
	sld.lastname = "Каппер";
	sld.city = "LostShipsCityy";
	sld.location = "SanAugustineResidencee";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_0";
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mayor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "mayor"; //тип нпс
	sld.greeting = "Gr_Kapper";
	sld.standUp = true; //вставать и нападать на врага 
	sld.watchBoxes = true;
	sld.standUp.exitDisable = true;   //залочить выход в случае драки
	sld.watchBoxes.exitDisable = true; //залочить выход в случае драки
	//sld.talker = true; //начать диалог
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

	// миллиционер №1
	sld = GetCharacter(NPC_GenerateCharacter("Ment_1", "mercen_13", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_19", "pistol4", "bullet", 100);
	sld.name = "Жан";
	sld.lastname = "Бурди";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto9"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_1"; 
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
	sld.greeting = "pirat_common";
	sld.talker = true; //начать диалог
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 24);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 11);
	TakeNItems(sld, "GunPowder", 14);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location"); 

	// миллиционер №2
	sld = GetCharacter(NPC_GenerateCharacter("Ment_2", "off_fra_4", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_18", "pistol4", "bullet", 100);
	sld.name = "Левис";
	sld.lastname = "Громмер";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_2"; 
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе	
	sld.location.hours = 2; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
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

	// миллиционер №3
	sld = GetCharacter(NPC_GenerateCharacter("Ment_3", "sold_hol_16", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_17", "pistol4", "bullet", 100);
	sld.name = "Фрек";
	sld.lastname = "Херринг";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto11"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_3"; 
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе
	sld.location.hours = 6; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
	sld.greeting = "pirat_common";
	sld.talker = true; //начать диалог
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 19);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 6);
	TakeNItems(sld, "GunPowder", 8);
	sld.watchBoxes = true;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// миллиционер №4
	sld = GetCharacter(NPC_GenerateCharacter("Ment_4", "off_spa_5", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_16", "pistol4", "bullet", 100);
	sld.name = "Рауль";
	sld.lastname = "Круз";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_4";  
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
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

	// миллиционер №5
	sld = GetCharacter(NPC_GenerateCharacter("Ment_5", "mercen_8", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_15", "pistol4", "bullet", 100);
	sld.name = "Жерар";
	sld.lastname = "Форэ";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_5"; 
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
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

	// миллиционер №6
	sld = GetCharacter(NPC_GenerateCharacter("Ment_6", "Dragoon_1", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "topor_04", "pistol4", "bullet", 100);
	sld.name = "Джон";
	sld.lastname = "Уоркман";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "SanAugustineResidencee";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "11"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto11_6"; 
	sld.location.baseShip.going = false; //перемещаться между кораблями в городе	
	sld.location.hours = 7; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mentos.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "ment"; //тип нпс
	sld.talker = true; //начать диалог
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

	// ------------------------ таверна ------------------------ 
	//тавернщик
	sld = GetCharacter(NPC_GenerateCharacter("LSCCBarmen", "barmen_8", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "Хилл";
	sld.lastname = "Брюннер";
	sld.rank = 20;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "barmen";
	sld.location.locator = "stay";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Barmen.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //тип нпс
	sld.greeting = "Gr_Barmen";
	LAi_SetBarmanType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	//официантка
	sld = GetCharacter(NPC_GenerateCharacter("LSCCwaitress", "CitizenWom_1", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Армо";
	sld.lastname = "Дюлин";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "waitress";
	sld.location.locator = "barmen";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Waitress.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "tavern"; //тип нпс
	sld.greeting = "Armo_Dulin";
	LAi_SetWaitressType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ внешние горожане ------------------------	
	// внешний горожанин Педро Хуртадо
	sld = GetCharacter(NPC_GenerateCharacter("PedroHurtado", "usurer_2", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Педро";
	sld.lastname = "Хуртадо";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto06_1"; 
	sld.location.baseShip = "06"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 2; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\PedroHurtado.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внешний горожанин Жиль Бару
	sld = GetCharacter(NPC_GenerateCharacter("ZhilBaru", "trader_16", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Жиль";
	sld.lastname = "Бару";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto07_1"; 
	sld.location.baseShip = "07"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 1; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ZhilBaru.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внешний горожанин Тристан Борчер
	sld = GetCharacter(NPC_GenerateCharacter("TristanBorcher", "shipowner_13", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Тристан";
	sld.lastname = "Борчер";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto09_1"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\TristanBorcher.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внешний горожанин Ройел Хааг
	sld = GetCharacter(NPC_GenerateCharacter("RoyelHaag", "trader_11", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Ройел";
	sld.lastname = "Хааг";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14_1"; 
	sld.location.baseShip = "14"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\RoyelHaag.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внешний горожанин Доминик Легро
	sld = GetCharacter(NPC_GenerateCharacter("DominicLegro", "trader_10", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Доминик";
	sld.lastname = "Легро";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15_1"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\DiminicLegro.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetLSCoutType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внешний горожанин Джорж Стоукс
	sld = GetCharacter(NPC_GenerateCharacter("JorgeStouks", "barmen_5", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Джорж";
	sld.lastname = "Стоукс";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "LostShipsCityy_town";
	sld.location.group = "goto";
	sld.location.locator = "goto08_1"; 
	sld.location.baseShip = "08"; //базовый корабль в ГПК
	sld.location.baseLocator = sld.location.locator; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\JorgeStouks.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_JorgeStouks";
	sld.talker = true; //начать диалог
	LAi_RemoveLoginTime(sld);	
	LAi_SetStayType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");
	ChangeCharacterAddress(sld, "LostShipsCityy_town", "goto11_2");

	// ------------------------ внешние горожане в таверне ------------------------
	// в таверне Генри Фолдер
	sld = GetCharacter(NPC_GenerateCharacter("HenryFolder", "barmen_14", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Генри";
	sld.lastname = "Фолдер";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit2"; 
	sld.location.baseShip = "03"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto03_2"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 6; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\HenryFolder.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Феликс Мендоза
	sld = GetCharacter(NPC_GenerateCharacter("FelixMendoza", "shipowner_1", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Феликс";
	sld.lastname = "Мендоза";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit3"; 
	sld.location.baseShip = "10"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto10_2"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\FelixMendoza.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Роджер Воулер
	sld = GetCharacter(NPC_GenerateCharacter("RodgerWoyler", "usurer_5", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Роджер";
	sld.lastname = "Воулер";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit5"; 
	sld.location.baseShip = "12"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto12_2"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 7; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\RodgerWoyler.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Андрэ Лабор
	sld = GetCharacter(NPC_GenerateCharacter("AndreLabor", "shipowner_15", "man", "man", 15, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 15, 60, 60, "blade_20", "pistol2", "bullet", 10);
	sld.name = "Андрэ";
	sld.lastname = "Лабор";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit9"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto15_2"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\AndreLabor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Master";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Стефан Клейн
	sld = GetCharacter(NPC_GenerateCharacter("StefanKleyn", "shipowner_6", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Стефан";
	sld.lastname = "Клейн";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit8"; 
	sld.location.baseShip = "14"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto14_2";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\StefanKleyn.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Томас Фланн
	sld = GetCharacter(NPC_GenerateCharacter("ThomasFlann", "citiz_1", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Томас";
	sld.lastname = "Фланн";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit6"; 
	sld.location.baseShip = "02"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto02_2";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 3; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ThomasFlann.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	sld.talker = true; //начать диалог
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в таверне Пабло Барадес
	sld = GetCharacter(NPC_GenerateCharacter("PabloBarades", "officer_20", "man", "man", 10, PIRATE, -1, true, "quest"));
	sld.name = "Пабло";
	sld.lastname = "Барадес";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "FleuronTavernn";
	sld.location.group = "sit";
	sld.location.locator = "sit14"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto09_2";  
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\PabloBarades.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ внешние горожане в церкви ------------------------
	// падре
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Priest", "priest_3", "man", "man", 5, PIRATE, -1, false, "quest"));
	sld.name = "падре";
	sld.lastname = "Анхель";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Priest.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "priest"; //тип нпс
	sld.greeting = "Gr_padre";
	LAi_SetPriestType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");		
	
	// в церкви Сандра Гомес
	sld = GetCharacter(NPC_GenerateCharacter("SandraGomes", "girl_4", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Сандра";
	sld.lastname = "Гомес";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 
	sld.location.baseShip = "04"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto04_3"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\SandraGomes.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// в церкви Моника Райт
	sld = GetCharacter(NPC_GenerateCharacter("MonikaRight", "girl_5", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Моника";
	sld.lastname = "Райт";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "GloriaChurchh";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 
	sld.location.baseShip = "08"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto08_3"; 
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\MonikaRight.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizen"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ магазин ------------------------

	// Аксель Йост - торговец
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_trader", "Axel", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld.name = "Аксель";
	sld.lastname = "Йост";
	sld.greeting = "Axel";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Trader.c";
	sld.dialog.currentnode   = "First time";
	sld.city = "LostShipsCityy";
	sld.cityTape = "trader"; //тип нпс
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

	// ------------------------ Тюрьма ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_PrisonerHead", "Hobart", "man", "man", 40, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 40, 87, 87, "blade_29", "pistol4", "bullet", 100);
	sld.name = "Габриэль";
	sld.lastname = "д'Эксмес";
	sld.rank = 40;
	sld.city = "LostShipsCityy";
	sld.location = "TartarusPrisonn";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Prisoner.c";
	sld.dialog.currentnode   = "prisonerHead";
	sld.cityTape = "prisonerHead"; //тип нпс
	sld.greeting = "pirat_common";
	sld.standUp = true; //вставать и нападать на врага 
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 7);
	TakeNItems(sld, "bullet", 6);
	TakeNItems(sld, "cartridge", 8);
	TakeNItems(sld, "GunPowder", 5);
	sld.watchBoxes = true;
	sld.location.days = 2; //передвижения через .. дней
	//sld.talker = true; //начать диалог
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	
	SaveCurrentNpcQuestDateParam(sld, "location");

	// тюремщик №1
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Prisoner1", "SoldierEnglish_1", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_21", "pistol3", "bullet", 100);
	sld.name = "Томас";
	sld.lastname = "Бойл";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "TartarusPrisonn";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Prisoner.c";
	sld.dialog.currentnode   = "Prisoner";
	sld.cityTape = "prisoner"; //тип нпс
	sld.greeting = "pirat_common";
	sld.standUp = true; //вставать и нападать на врага 
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 16);
	TakeNItems(sld, "cartridge", 19);
	TakeNItems(sld, "GunPowder", 24);
	sld.watchBoxes = true;
	sld.location.hours = 4; //передвижения через .. часов
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// ------------------------ Банкир ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Usurer", "trader_9", "man", "man", 30, PIRATE, -1, true, "quest"));
	sld.name = "Августо";
	sld.lastname = "Брамс";
	sld.rank = 30;
	sld.city = "LostShipsCityy";
	sld.location	= "CarolineBankk";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Usurer.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "usurer"; //тип нпс
	sld.greeting = "cit_common";
	LAi_SetImmortal(sld, true);
	LAi_RemoveLoginTime(sld);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	

	// ------------------------ Механик ------------------------
	sld = GetCharacter(NPC_GenerateCharacter("LSCC_Mechanic", "Mechanic", "man", "man", 5, PIRATE, -1, false, "quest"));
	sld.name = "Хенрик";
	sld.lastname = "Ведекер";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Mechanic.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "mechanic"; //тип нпс
	sld.greeting = "Gr_Master";
	LAi_RemoveLoginTime(sld);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");

	// ------------------------ внутренние горожане ------------------------
	// внутреняя горожанка Элис Тейлор
	sld = GetCharacter(NPC_GenerateCharacter("ElisTaylor", "girl_3", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Элис";
	sld.lastname = "Тейлор";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "CeresSmithyy";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "03"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto03_0"; 
	sld.location.baseLocation = "CeresSmithyy"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 4; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ElisTaylor.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внутреняя горожанка Орели Бертин
	sld = GetCharacter(NPC_GenerateCharacter("OreliBertin", "girl_6", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Орели";
	sld.lastname = "Бертин";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "FurieShipInside22";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "06"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto06_0"; 
	sld.location.baseLocation = "FurieShipInside22"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 6; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\OreliBertin.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внутреняя горожанка Леа Тоорс
	sld = GetCharacter(NPC_GenerateCharacter("LeaToors", "girl_7", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Леа";
	sld.lastname = "Тоорс";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "PlutoStoreSmalll";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "09"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto09_0"; 
	sld.location.baseLocation = "PlutoStoreSmalll"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\LeaToors.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внутреняя горожанка Элиза Кальво
	sld = GetCharacter(NPC_GenerateCharacter("ElizaCalvo", "girl_8", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Элиза";
	sld.lastname = "Кальво";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "SantaFlorentinaShipInside44";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "14"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto14_0"; 
	sld.location.baseLocation = "SantaFlorentinaShipInside44"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 7; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\ElizaCalvo.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_Woman_Citizen";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	// внутреняя горожанка Сесиль Галард
	sld = GetCharacter(NPC_GenerateCharacter("SesilGalard", "BaynesWife", "woman", "towngirl", 5, PIRATE, -1, false, "quest"));
	sld.name = "Сесиль";
	sld.lastname = "Галард";
	sld.rank = 5;
	sld.city = "LostShipsCityy";
	sld.location	= "AvaShipInside33";
	sld.location.group = "barmen";
	sld.location.locator = "stay"; 
	sld.location.baseShip = "15"; //базовый корабль в ГПК
	sld.location.baseLocator = "goto15_0"; 
	sld.location.baseLocation = "AvaShipInside33"; //базовая внутреняя локация
	sld.location.baseShip.going = true; //перемещаться между кораблями в городе	
	sld.location.hours = 5; //передвижения через .. часов
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\SesilGalard.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "citizenHome"; //тип нпс
	sld.greeting = "Gr_SesilGalard";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	SaveCurrentNpcQuestDateParam(sld, "location");

	//------------------- Клан Нарвал -------------------
	// нарвал главарь
	sld = GetCharacter(NPC_GenerateCharacter("Narval_head", "capitan_3", "man", "man", 35, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 35, 100, 100, "blade_28", "pistol4", "bullet", 200);
	sld.name = "Томас";
	sld.lastname = "Булл";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto1"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	SaveCurrentNpcQuestDateParam(sld, "location"); //главе клана сделаем перемещения
	// нарвал №1
	sld = GetCharacter(NPC_GenerateCharacter("Narval_1", "officer_18", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 60, 60, "blade_21", "pistol6", "bullet", 10);
	sld.name = "Фриц";
	sld.lastname = "Холт";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 14);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 16);
	TakeNItems(sld, "GunPowder", 24);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №2
	sld = GetCharacter(NPC_GenerateCharacter("Narval_2", "officer_12", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 26, 80, 80, "blade_29", "pistol3", "bullet", 15);
	sld.name = "Роджер";
	sld.lastname = "Адин";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 10);
	TakeNItems(sld, "bullet", 11);
	TakeNItems(sld, "cartridge", 12);
	TakeNItems(sld, "GunPowder", 8);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №3
	sld = GetCharacter(NPC_GenerateCharacter("Narval_3", "trader_2", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 24, 70, 70, "blade_25", "pistol5", "bullet", 10);
	sld.name = "Ник";
	sld.lastname = "Нолти";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №4
	sld = GetCharacter(NPC_GenerateCharacter("Narval_4", "pirate_7", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 85, 85, "blade_30", "pistol6", "bullet", 15);
	sld.name = "Жери";
	sld.lastname = "Гразид";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 16);
	TakeNItems(sld, "bullet", 13);
	TakeNItems(sld, "cartridge", 17);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №5
	sld = GetCharacter(NPC_GenerateCharacter("Narval_5", "pirate_3", "man", "man", 20, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "topor_04", "pistol3", "bullet", 10);
	sld.name = "Милон";
	sld.lastname = "Бержи";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto6"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №6
	sld = GetCharacter(NPC_GenerateCharacter("Narval_6", "pirate_4", "man", "man", 22, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 22, 65, 65, "blade_22", "pistol6", "bullet", 10);
	sld.name = "Милон";
	sld.lastname = "Бержи";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto7"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 15);
	TakeNItems(sld, "bullet", 12);
	TakeNItems(sld, "cartridge", 9);
	TakeNItems(sld, "GunPowder", 17);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");
	// нарвал №7
	sld = GetCharacter(NPC_GenerateCharacter("Narval_7", "officer_14", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 85, 85, "blade_23", "pistol4", "bullet", 15);
	sld.name = "Милон";
	sld.lastname = "Бержи";
	sld.city = "LostShipsCityy";
	sld.location	= "VelascoShipInside11";
	sld.location.group = "goto";
	sld.location.locator = "goto8"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Narval.c";
	sld.dialog.currentnode   = "Narval_warning";
	sld.cityTape = "narval"; //тип нпс
	sld.greeting = "Narval";
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_1");

	//------------------- Клан Каспер -------------------
	// каспер главарь
	sld = GetCharacter(NPC_GenerateCharacter("Casper_head", "shipowner_7", "man", "man", 35, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 35, 100, 100, "blade_28", "pistol5", "bullet", 20);
	sld.name = "Каспер";
	sld.lastname = "Лонгмэн";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto8"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//SaveCurrentNpcQuestDateParam(sld, "location"); //главе клана сделаем перемещения
	//каспер №1
	sld = GetCharacter(NPC_GenerateCharacter("Casper_1", "pirate_9", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "topor_04", "pistol3", "bullet", 10);
	sld.name = "Денис";
	sld.lastname = "Хопфер";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto4"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 25);
	TakeNItems(sld, "cartridge", 20);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №2
	sld = GetCharacter(NPC_GenerateCharacter("Casper_2", "pirate_8", "man", "man", 21, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 21, 80, 80, "blade_26", "pistol6", "bullet", 12);
	sld.name = "Фошер";
	sld.lastname = "Хехт";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto6"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 14);
	TakeNItems(sld, "GunPowder", 11);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №3
	sld = GetCharacter(NPC_GenerateCharacter("Casper_3", "pirate_10", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "blade_24", "pistol4", "bullet", 15);
	sld.name = "Серж";
	sld.lastname = "Шамбон";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto5"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 18);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 14);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №4
	sld = GetCharacter(NPC_GenerateCharacter("Casper_4", "pirate_2", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_23", "pistol3", "bullet", 10);
	sld.name = "Фелипе";
	sld.lastname = "Армас";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto7"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №5
	sld = GetCharacter(NPC_GenerateCharacter("Casper_5", "officer_16", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "topor_04", "pistol3", "bullet", 13);
	sld.name = "Фелипе";
	sld.lastname = "Армас";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto13"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 20);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №6
	sld = GetCharacter(NPC_GenerateCharacter("Casper_6", "officer_1", "man", "man", 29, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 29, 80, 80, "blade_25", "pistol4", "bullet", 10);
	sld.name = "Хуан";
	sld.lastname = "Кобо";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto1" //; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 15);
	TakeNItems(sld, "bullet", 18);
	TakeNItems(sld, "cartridge", 19);
	TakeNItems(sld, "GunPowder", 24);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №7
	sld = GetCharacter(NPC_GenerateCharacter("Casper_7", "officer_2", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_22", "pistol6", "bullet", 15);
	sld.name = "Тагель";
	sld.lastname = "Эдо";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto2"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 12);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 17);
	TakeNItems(sld, "GunPowder", 22);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №8
	sld = GetCharacter(NPC_GenerateCharacter("Casper_8", "officer_17", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_25", "pistol4", "bullet", 15);
	sld.name = "Зенон";
	sld.lastname = "Баррио";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto3"; // 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 18);
	TakeNItems(sld, "GunPowder", 23);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №9
	sld = GetCharacter(NPC_GenerateCharacter("Casper_9", "officer_5", "man", "man", 30, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_26", "pistol6", "bullet", 15);
	sld.name = "Мигель";
	sld.lastname = "Батис";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto10"; //
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 17);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 15);
	TakeNItems(sld, "GunPowder", 19);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №10
	sld = GetCharacter(NPC_GenerateCharacter("Casper_10", "officer_6", "man", "man", 25, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_27", "pistol3", "bullet", 15);
	sld.name = "Мартин";
	sld.lastname = "Камю";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto11"; //	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "grapeshot", 21);
	TakeNItems(sld, "bullet", 17);
	TakeNItems(sld, "cartridge", 18);
	TakeNItems(sld, "GunPowder", 31);
	sld.greeting = "pirat_common";
	LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	//каспер №11
	sld = GetCharacter(NPC_GenerateCharacter("Casper_11", "officer_20", "man", "man", 27, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 27, 80, 80, "blade_28", "pistol4", "bullet", 25);
	sld.name = "Марк";
	sld.lastname = "Бишоп";
	sld.city = "LostShipsCityy";
	sld.location	= "SanGabrielMechanicc";
	sld.location.group = "goto";
	sld.location.locator = "goto12"; 	
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\Casper.c";
	sld.dialog.currentnode   = "First time";
	sld.cityTape = "casper"; //тип нпс
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
// Jason Дороже золота
bool GoldenGirl_CheckGirls() // проверка наличия Элизы или Мэри
{
	if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1) 
	{
		pchar.questTemp.GoldenGirl.Helena = "true";
		log_Testinfo("Героиня - Элиза");
		return true;
	}
	if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1) 
	{
		pchar.questTemp.GoldenGirl.Mary = "true";
		log_Testinfo("Героиня - Мэри");
		return true;
	}
	return false;
}
// Jason Долго и счастливо
bool LongHappy_CheckGirls() // проверка наличия Элизы или Мэри
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

bool LongHappy_CheckCondisiones() // проверка всех условий fix 22-03-20
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














