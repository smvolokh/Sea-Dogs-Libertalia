// 11.08.05 Boal Модуль для новой РПГ системы S.P.E.C.I.A.L
// метод для совместимости с .ИНИ файлом (секция SKILLCHANGER)

#define MAX_ACHIEVMENTS		73

// порог ранга
int GetCharacterRankRate(ref _refCharacter)
{
    return 35 - GetCharacterSPECIALSimple(_refCharacter, SPECIAL_I);
}
int GetCharacterRankRateCur(ref _refCharacter)
{
    if(!CheckAttribute(_refCharacter, "rank_exp"))
	{
		_refCharacter.rank_exp = 0;
	}
    return sti(_refCharacter.rank_exp);
}
// прирост НР
int GetCharacterAddHPValue(ref _refCharacter)
{
	// --> убрать влияние кирас
	int Ers = GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E);
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "underwater") Ers = Ers+2;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass1") Ers = Ers+1;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass2") Ers = Ers+1;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass4") Ers = Ers+1;
	// <-- убрать влияние кирас

	int ret = makeint(2 + Ers * 0.55 + 0.5);
  //  int ret = makeint(2 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E) * 0.55 + 0.5);

	if (CheckCharacterPerk(_refCharacter, "HPPlus"))
	{
		ret = ret + 1;
		if(CheckAttribute(_refCharacter, "chr_ai.hp_max_back"))
		{
			_refCharacter.chr_ai.hp_max_back = stf(_refCharacter.chr_ai.hp_max_back) + ret;
		}
	}
	else
	{
		if(CheckAttribute(_refCharacter, "chr_ai.hp_max_back"))
		{
			_refCharacter.chr_ai.hp_max_back = stf(_refCharacter.chr_ai.hp_max_back) + ret;
		}
	}
	return ret;
}

int GetCharacterBaseHPValue(ref _refCharacter)
{
	int ret = makeint(30.0 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_S)*GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E)*0.5);
	return ret;
}

float GetCharacterMaxEnergyValue(ref _refCharacter)
{
	// CheatSurfMenu -->
	if (_refCharacter.id == pchar.id && CheckAttribute(pchar, "CSM.EnergyBonus"))
	{
		return 999.0;
	}
	// <--
    float ret = (30.0 + GetCharacterSPECIAL(_refCharacter, SPECIAL_A)*10);
	if (CheckAttribute(_refCharacter, "PerkValue.EnergyPlus"))
	{
  		ret = ret + stf(_refCharacter.PerkValue.EnergyPlus);
	}
if (CheckAttribute(_refCharacter, "questTemp.Gothicfennisgrasstotal"))
	{
		ret = ret + makeint(500 / ret);
	}
	if(IsEquipCharacterByArtefact(_refCharacter, "indian_7"))
	{
		ret = ret + makeint(1500 / ret);
	}
	return ret;
}

float GetCharacterMaxEnergyABSValue(ref _refCharacter)
{
    // проверки перков to_do
	float ret = (30.0 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_A)*10);
	if (CheckAttribute(_refCharacter, "PerkValue.EnergyPlus"))
	{
  		ret = ret + stf(_refCharacter.PerkValue.EnergyPlus);
	}
	return ret;
}

void SetEnergyToCharacter(ref _refCharacter)
{
	_refCharacter.chr_ai.energyMax = GetCharacterMaxEnergyValue(_refCharacter);
	if (!CheckAttribute(_refCharacter, "chr_ai.energy"))
	{
		_refCharacter.chr_ai.energy    = _refCharacter.chr_ai.energyMax;
	}
	else
	{
	    if (sti(_refCharacter.chr_ai.energy) > sti(_refCharacter.chr_ai.energyMax))
	    {
	        _refCharacter.chr_ai.energy    = _refCharacter.chr_ai.energyMax;
	    }
	}
}

int GetCharacterMaxOfficersQty(ref _refCharacter)
{
    return GetCharacterSPECIAL(_refCharacter, SPECIAL_C)*2;
}

int AddCharacterExp(ref _refCharacter,int _exp)
{
	int retVal = false;
	return retVal;
}

int CalculateExperienceFromRank(int _Rank)
{
	if(_Rank<2) return 0;
	int retVal = 100;
	return retVal;
}

int GetFreePoints_SelfRate(ref _chref)
{
    return 40 - GetCharacterSPECIALSimple(_chref, SPECIAL_I);
}

int GetFreePoints_ShipRate(ref _chref)
{
    return 40 - GetCharacterSPECIALSimple(_chref, SPECIAL_I);
}
/////////////////////////////////////////////////////////////////////////

void SetSelfSkill(ref _refCharacter, int _fl, int _f, int _fh, int _p, int _fr)
{
    _refCharacter.Skill.FencingL      = _fl;
    _refCharacter.Skill.FencingS      = _f;
    _refCharacter.Skill.FencingH      = _fh;
    _refCharacter.Skill.Pistol        = _p;
    _refCharacter.Skill.Fortune       = _fr;
//    _refCharacter.Skill.Leadership = _ld;
//    _refCharacter.Skill.Sneak      = _sn;
}

void SetShipSkill(ref _refCharacter, int _ld, int _cr, int _ac, int _cn, int _sl, int _re, int _gr, int _de, int _sn)
{
    _refCharacter.Skill.Leadership = _ld;
    _refCharacter.Skill.Commerce   = _cr;
    _refCharacter.Skill.Accuracy   = _ac;
    _refCharacter.Skill.Cannons    = _cn;
    _refCharacter.Skill.Sailing    = _sl;
    _refCharacter.Skill.Repair     = _re;
    _refCharacter.Skill.Grappling  = _gr;
    _refCharacter.Skill.Defence    = _de;
    _refCharacter.Skill.Sneak      = _sn;
}

void SetSPECIAL(ref _refCharacter, int _s, int _p, int _e, int _c, int _i, int _a, int _l)
{
    _refCharacter.SPECIAL.Strength   = _s;
    _refCharacter.SPECIAL.Perception = _p;
    _refCharacter.SPECIAL.Endurance  = _e;
    _refCharacter.SPECIAL.Charisma   = _c;
    _refCharacter.SPECIAL.Intellect  = _i;
    _refCharacter.SPECIAL.Agility    = _a;
    _refCharacter.SPECIAL.Luck       = _l;
}

void SetRandSPECIAL(ref _refCharacter)
{
    SetSPECIAL(_refCharacter,
               (3 + rand(7)),
               (3 + rand(7)),
               (3 + rand(7)),
               (2 + rand(8)),
               (4 + rand(6)),
               (4 + rand(6)),
               (2 + rand(8)));
}

/// влияет только на СПЕЦИАЛ
int ApplayNavyPenalty(ref _refCharacter, string skillName, int sumSkill)
{
    if (IsCompanion(_refCharacter) && GetRemovable(_refCharacter))//пусть будет для компаньонов тоже sti(_refCharacter.index) == GetMainCharacterIndex()) // только для главного, чтоб не тормозить всю игру
    {
        int sailSkill;
        // общее умение навигации
        sailSkill = GetSummonSkillFromNameSimple(_refCharacter, SKILL_SAILING);
        
        int shipClass = GetCharacterShipClass(_refCharacter);
        int needSkill = GetShipClassNavySkill(shipClass);
		if (CheckAttribute(_refCharacter, "NoNavyPenalty")) needSkill = 1;

        if (sailSkill < needSkill)
        {
			sailSkill = makeint((needSkill - sailSkill)/10.0 + 0.9); // округление до мах всегда
			sumSkill = sumSkill - sailSkill;
	        if (sumSkill < 1) sumSkill = 1;
        }
    }
    return  sumSkill;
}
// пенальти в скилы
int ApplayNavyPenaltyToSkill(ref _refCharacter, string skillName, int sumSkill)
{
    if (IsCompanion(_refCharacter) && GetRemovable(_refCharacter))//пусть будет для компаньонов тоже sti(_refCharacter.index) == GetMainCharacterIndex()) // только для главного, чтоб не тормозить всю игру
    {
        int sailSkill;

        // общее умение навигации
        sailSkill = GetSummonSkillFromNameSimple(_refCharacter, SKILL_SAILING);
        int shipClass = GetCharacterShipClass(_refCharacter);
        int needSkill = GetShipClassNavySkill(shipClass);
		if (CheckAttribute(_refCharacter, "NoNavyPenalty")) needSkill = 1;

        if (sailSkill < needSkill)
        {
			sailSkill = needSkill - sailSkill;
			sumSkill = sumSkill - sailSkill;
	        if (sumSkill < 1) sumSkill = 1;
        }
    }
    return  sumSkill;
}
// с пенальти и вещами +1
int GetCharacterSPECIAL(ref _refCharacter, string skillName)
{
    int skillN;

	skillN = GetCharacterSPECIALSimple(_refCharacter, skillName);

 	skillN = ApplayNavyPenalty(_refCharacter, skillName, skillN);
	
    return skillN;
}

int GetCharacterSPECIALSimple(ref _refCharacter, string skillName)
{
	if (!CheckAttribute(_refCharacter,"SPECIAL."+skillName) )
    {
        return 3;
    }
	int skillN = sti(_refCharacter.SPECIAL.(skillName));
    // Health
    if (sti(_refCharacter.index) == GetMainCharacterIndex() && MOD_SKILL_ENEMY_RATE > 1) // не халява
    {
        skillN = skillN + GetHealthNum(_refCharacter) - 6; // max -5
    }
    
	skillN += ApplySPECIALCirassPenalty(_refCharacter, skillName);
	skillN += ApplySPECIALMangarosaPotion(_refCharacter, skillName); // Jason
	
	if(CheckAttribute(_refCharacter, "GenQuest.EnergyPenalty")) 
	{
		skillN += ApplySPECIALQuestPenalty(_refCharacter, skillName); // Jason
	}
	
	if (skillN <= 1) skillN = 1;
	if( skillN > SPECIAL_MAX ) skillN = SPECIAL_MAX;

	return skillN;
}


void InitRPGType()
{
    NullCharacter.SPECIALType.Strength = true;
    NullCharacter.SPECIALType.Perception = true;
    NullCharacter.SPECIALType.Endurance = true;
    NullCharacter.SPECIALType.Charisma = true;
    NullCharacter.SPECIALType.Intellect = true;
    NullCharacter.SPECIALType.Agility = true;
    NullCharacter.SPECIALType.Luck = true;
    
    NullCharacter.SelfType.Leadership = true;
	NullCharacter.SelfType.FencingL = true;
    NullCharacter.SelfType.FencingS = true;
    NullCharacter.SelfType.FencingH = true;
    NullCharacter.SelfType.Pistol = true;
    NullCharacter.SelfType.Fortune = true;
    NullCharacter.SelfType.Sneak = true;
    // остальные корабельные
    NullCharacter.ShipType.Commerce = true;
    NullCharacter.ShipType.Accuracy = true;
    NullCharacter.ShipType.Cannons = true;
    NullCharacter.ShipType.Sailing = true;
    NullCharacter.ShipType.Repair = true;
    NullCharacter.ShipType.Grappling = true;
    NullCharacter.ShipType.Defence = true;

}

bool isSPECIALTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "SPECIALType." + _param);
}

bool isShipTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "ShipType." + _param);
}
bool isSelfTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "SelfType." + _param);
}

string GetRPGText(string _param)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("RPGDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, _param);
    LanguageCloseFile(idLngFile);

    return totalInfo;
}

string GetSkillNameByIdx(int idx)
{
    string ret = "";
    
    switch (idx)
    {
        case 1:    ret = SKILL_F_LIGHT;   break;
        case 2:    ret = SKILL_FENCING;   break;
        case 3:    ret = SKILL_F_HEAVY;   break;
        case 4:    ret = SKILL_PISTOL;    break;
        case 5:    ret = SKILL_FORTUNE;   break;
        
        case 6:    ret = SKILL_LEADERSHIP; break;
        case 7:    ret = SKILL_COMMERCE;   break;
        case 8:    ret = SKILL_ACCURACY;   break;
        case 9:    ret = SKILL_CANNONS;    break;
        case 10:   ret = SKILL_SAILING;    break;
        case 11:   ret = SKILL_REPAIR;     break;
        case 12:   ret = SKILL_GRAPPLING;  break;
        case 13:   ret = SKILL_DEFENCE;    break;
        case 14:   ret = SKILL_SNEAK;      break;
        
        case 15:   ret = SPECIAL_S;   break;
        case 16:   ret = SPECIAL_P;   break;
        case 17:   ret = SPECIAL_A;   break;
        case 18:   ret = SPECIAL_C;   break;
        case 19:   ret = SPECIAL_I;   break;
        case 20:   ret = SPECIAL_E;   break;
        case 21:   ret = SPECIAL_L;   break;
    }
    return ret;
}
//  _type   ShipType SelfType  SPECIALType
string GetSkillNameByTRIdx(string _type, int idx)
{
    string ret = "";

	switch (_type)
	{
		case "SelfType" :
		    switch (idx)
		    {
                case 1:    ret = SKILL_LEADERSHIP; break;
				case 2:    ret = SKILL_F_LIGHT;   break;
		        case 3:    ret = SKILL_FENCING;   break;
		        case 4:    ret = SKILL_F_HEAVY;   break;
		        case 5:    ret = SKILL_PISTOL;    break;
		        case 6:    ret = SKILL_FORTUNE;   break;
                case 7:    ret = SKILL_SNEAK;      break;
		    }
		break;
		
		case "ShipType" :
		    switch (idx)
		    {
                case 1:    ret = SKILL_SAILING; break;
				case 2:    ret = SKILL_ACCURACY;   break;
		        case 3:    ret = SKILL_CANNONS;   break;
		        case 4:    ret = SKILL_GRAPPLING;   break;
		        case 5:    ret = SKILL_DEFENCE;    break;
		        case 6:    ret = SKILL_REPAIR;   break;
                case 7:    ret = SKILL_COMMERCE;      break;
		    }
		break;
		
		case "SPECIALType" :
		    switch (idx)
		    {
                case 1:   ret = SPECIAL_S;   break;
		        case 2:   ret = SPECIAL_P;   break;
		        case 3:   ret = SPECIAL_A;   break;
		        case 4:   ret = SPECIAL_C;   break;
		        case 5:   ret = SPECIAL_I;   break;
		        case 6:   ret = SPECIAL_E;   break;
		        case 7:   ret = SPECIAL_L;   break;
		    }
		break;
    }
    return ret;
}
// по имени скила вернуть значение
int GetSkillValue(ref _refCharacter, string _type, string _skillName)
{
    if (CheckAttribute(_refCharacter, _type + "." + _skillName))
    {
        return sti(_refCharacter.(_type).(_skillName));
    }
    return 0;
}

float GetSkillValueExp(ref _refCharacter, string _skillName)
{
    string skillName_exp = _skillName + "_exp";
    if (!CheckAttribute(_refCharacter, "Skill."+skillName_exp))
	{
		_refCharacter.Skill.(skillName_exp) = 0;
	}
    return stf(_refCharacter.Skill.(skillName_exp));
}
int AddSPECIALValue(ref _refCharacter, string _skillName, int _add)
{
    string _type = SPECIAL_TYPE;
    
    if (CheckAttribute(_refCharacter, _type + "." + _skillName))
    {
        _refCharacter.(_type).(_skillName) = sti(_refCharacter.(_type).(_skillName)) + _add;
    }
    else
    {
        _refCharacter.(_type).(_skillName) = _add;
    }
    if (sti(_refCharacter.(_type).(_skillName)) < 1) {_refCharacter.(_type).(_skillName) = 1;}
    if (sti(_refCharacter.(_type).(_skillName)) > SPECIAL_MAX) {_refCharacter.(_type).(_skillName) = SPECIAL_MAX;}
    
    return sti(_refCharacter.(_type).(_skillName));
}

int AddCharacterSkill(ref _chref, string _skill, int _addValue)
{
    string  _skill_exp = _skill + "_exp";

    if (_addValue > 0)
	{
	    if ((sti(_chref.skill.(_skill)) + _addValue) > SKILL_MAX)
	    {
	        _addValue = SKILL_MAX - sti(_chref.skill.(_skill));
	    }
	}
    _chref.skill.(_skill) = sti(_chref.skill.(_skill)) + _addValue;

	if (sti(_chref.skill.(_skill)) < 1)
	{
        _chref.skill.(_skill) = 1;
	}
	if (sti(_chref.skill.(_skill)) > SKILL_MAX )
	{
	    _chref.skill.(_skill) = SKILL_MAX;
	}
	_chref.skill.(_skill_exp) = 0;
	if (_addValue >= 0)
	{
	   ApplayNewSkill(_chref, _skill, _addValue);
	}
	return sti(_chref.skill.(_skill));
}

void AddCharacterSkillDontClearExp(ref _chref, string _skill, int _addValue)
{
    /*if (_addValue > 0)
	{
	    if ((sti(_chref.skill.(_skill)) + _addValue) > SKILL_MAX)
	    {
	        _addValue = SKILL_MAX - sti(_chref.skill.(_skill));
	    }
	} */
	_chref.skill.(_skill) = sti(_chref.skill.(_skill)) + _addValue;

	if (sti(_chref.skill.(_skill)) < 1)
	{
        _chref.skill.(_skill) = 1;
	}
	if (sti(_chref.skill.(_skill)) > SKILL_MAX )
	{
	    _chref.skill.(_skill) = SKILL_MAX;
	}
	if (_addValue >= 0)
	{
	   ApplayNewSkill(_chref, _skill, _addValue);
	}
}

void ApplayNewSkill(ref _chref, string _skill, int _addValue)
{
    // трем кэш
    CheckAttribute(_chref, "BakSkill." + _skill);
    
	// boal 05.05.04 разделение по группам -->
    if (isSelfTypeSkill(_skill))
    {
       if(CheckAttribute(_chref,"perks.FreePoints_self_exp"))
       {
           _chref.perks.FreePoints_self_exp = sti(_chref.perks.FreePoints_self_exp) + _addValue;
       }
       else
       {	_chref.perks.FreePoints_self_exp = _addValue;
       }
       if (sti(_chref.perks.FreePoints_self_exp) >= GetFreePoints_SelfRate(_chref))
       {
           _chref.perks.FreePoints_self_exp = 0;
           if(CheckAttribute(_chref,"perks.FreePoints_self"))
           {
               _chref.perks.FreePoints_self = sti(_chref.perks.FreePoints_self) + 1;
           }
           else
           {	_chref.perks.FreePoints_self = 1;
           }
           if (sti(_chref.index) == GetMainCharacterIndex())
           {
               Log_SetStringToLog(XI_ConvertString("Personal abilities") + " + 1");
           }
       }
    }
    else
    {
       if(CheckAttribute(_chref,"perks.FreePoints_ship_exp"))
       {
           _chref.perks.FreePoints_ship_exp = sti(_chref.perks.FreePoints_ship_exp) + _addValue;
       }
       else
       {	_chref.perks.FreePoints_ship_exp = _addValue;
       }
       if (sti(_chref.perks.FreePoints_ship_exp) >= GetFreePoints_ShipRate(_chref))
       {
           _chref.perks.FreePoints_ship_exp = 0;
           if(CheckAttribute(_chref,"perks.FreePoints_ship"))
           {
               _chref.perks.FreePoints_ship = sti(_chref.perks.FreePoints_ship) + 1;
           }
           else
           {	_chref.perks.FreePoints_ship = 1;
           }
           if (sti(_chref.index) == GetMainCharacterIndex())
           {
               Log_SetStringToLog(XI_ConvertString("Ship abilities") + " + 1");
           }
       }
    }
    // boal 05.05.04 разделение по группам <--


    if(!CheckAttribute(_chref, "rank_exp"))
    {
      _chref.rank_exp = 0;
    }
    _chref.rank_exp = sti(_chref.rank_exp) + _addValue;

    if (sti(_chref.rank_exp) >= GetCharacterRankRate(_chref)) // use classic mode - 2 skill = 1 rank
    {
        _chref.rank_exp = 0;
        _chref.rank = sti(_chref.rank) + 1;
        float mhp = LAi_GetCharacterMaxHP(_chref) + GetCharacterAddHPValue(_chref);
        LAi_SetHP(_chref,mhp,mhp);

        if (CheckCharacterPerk(_chref, "EnergyPlus"))
		{
		    if (!CheckAttribute(_chref, "PerkValue.EnergyPlus"))
			{
		  		_chref.PerkValue.EnergyPlus = 0;
			}
			_chref.PerkValue.EnergyPlus = sti(_chref.PerkValue.EnergyPlus) + 1;
			SetEnergyToCharacter(_chref);
		}

        // сообщение в лог
        if(IsOfficer(_chref) || IsCompanion(_chref))
        {
            AddMsgToCharacter(_chref,MSGICON_LEVELUP);
            Log_SetStringToLog(XI_ConvertString("Level Up"));
            PlayStereoSound("interface\new_level.wav");
        }
    }
}
// по специал распередить скилы
void InitStartParam(ref _chref)
{
    int i;
    string  skillName;
    
    ClearCharacterExpRate(_chref);
    
    for (i=1; i<15; i++)
    {
        skillName = GetSkillNameByIdx(i);
        _chref.skill.(skillName) = makeint(MOD_EXP_RATE / GetCharacterExpRate(_chref, skillName) + 0.5);
    }
    LAi_SetHP(_chref, GetCharacterBaseHPValue(_chref), GetCharacterBaseHPValue(_chref));
}
// порог следующего скила (множетель)
float GetCharacterExpRate(ref _chref, string _skill)
{
    string  skill_rate = _skill + "_rate";

    if (!CheckAttribute(_chref, "skill." + skill_rate))
    {
        float  divBy = 1.0;

        switch (_skill)
        {
            case SKILL_F_LIGHT:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.9 + GetCharacterSPECIAL(_chref, SPECIAL_P)*0.1;
            break;
            case SKILL_FENCING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_S)*0.6 + GetCharacterSPECIAL(_chref, SPECIAL_A)*0.4;
            break;
            case SKILL_F_HEAVY:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_S)*0.9 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.1;
            break;
            case SKILL_PISTOL:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.5;
            break;
            case SKILL_FORTUNE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_L);
            break;
            
            case SKILL_LEADERSHIP:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.1 + GetCharacterSPECIAL(_chref, SPECIAL_C)*0.9;
            break;
            case SKILL_COMMERCE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.8 + GetCharacterSPECIAL(_chref, SPECIAL_C)*0.2;
            break;
            case SKILL_ACCURACY:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.8 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.2;
            break;
            case SKILL_CANNONS:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.6 + GetCharacterSPECIAL(_chref, SPECIAL_S)*0.4;
            break;
            case SKILL_SAILING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.2 + GetCharacterSPECIAL(_chref, SPECIAL_I)*0.8;
            break;
            case SKILL_REPAIR:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.2 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.8;
            break;
            case SKILL_GRAPPLING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.7 + GetCharacterSPECIAL(_chref, SPECIAL_I)*0.3;
            break;
            case SKILL_DEFENCE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_C)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.5;
            break;
            case SKILL_SNEAK:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.5;
            break;
        }
        _chref.skill.(skill_rate) = makefloat(MOD_EXP_RATE / divBy);
    }
    return  stf(_chref.skill.(skill_rate));
}

// table service
string GetReputationComplexName(int reputation, string repName)
{	
	switch(repName)
	{
		case "fame" 	:
			if(reputation < 21)  return "REPUTATION_FAME_1";
			if(reputation < 41)  return "REPUTATION_FAME_2";
			if(reputation < 61)  return "REPUTATION_FAME_3";
			if(reputation < 81)  return "REPUTATION_FAME_4";
			return "REPUTATION_FAME_5";
		break;
		
		case "nobility" :
			if(reputation < 6)   return "REPUTATION_NOBILITY_1";
			if(reputation < 16)  return "REPUTATION_NOBILITY_2";
			if(reputation < 31)  return "REPUTATION_NOBILITY_3";
			if(reputation < 48)  return "REPUTATION_NOBILITY_4";
			if(reputation < 53)  return "REPUTATION_NOBILITY_5";
			if(reputation < 71)  return "REPUTATION_NOBILITY_6";
			if(reputation < 86)  return "REPUTATION_NOBILITY_7";
			if(reputation < 96)  return "REPUTATION_NOBILITY_8";
			return "REPUTATION_NOBILITY_9";
		break;
	}
}

string GetFullReputationComplexName(ref chref)
{
	string sReputation, sFame, sNobility;
	
	if(CheckAttribute(chref,"reputation.fame")) 
	{
		sFame = GetReputationComplexName(sti(chref.reputation.fame), "fame");
	}	
	else 
	{
		sFame = "REPUTATION_FAME_1";	
	}	
	
	if(CheckAttribute(chref,"reputation.nobility")) 
	{
		sNobility = GetReputationComplexName(sti(chref.reputation.nobility), "nobility");
	}	
	else
	{
		sNobility = "REPUTATION_NOBILITY_5";	
	}	
	sReputation = XI_ConvertString(sFame) + " " + XI_ConvertString(sNobility);
	
	return sReputation;
}

// table service
string GetReputationName(int reputation)
{
    if(reputation<11)
        return "REPUTATIONT_BAD_4";
    if(reputation<21)
        return "REPUTATIONT_BAD_3";
    if(reputation<31)
        return "REPUTATIONT_BAD_2";
    if(reputation<41)
        return "REPUTATIONT_BAD_1";
    if(reputation<51)
        return "REPUTATIONT_NEUTRAL";
    if(reputation<61)
        return "REPUTATIONT_GOOD_1";
    if(reputation<71)
        return "REPUTATIONT_GOOD_2";
    if(reputation<81)
        return "REPUTATIONT_GOOD_3";
    if(reputation<=90)
        return "REPUTATIONT_GOOD_4";

	return "REPUTATIONT_GOOD_4";
}
// to_do  del
string GetFameName(int fame)
{
   return "TO_DO for del";
}

string GetMoraleName(int morale)
{
	if(morale<10)
		return MoraleTable[MORALET_TREACHEROUS];
	if(morale<20)
		return MoraleTable[MORALET_AWFUL];
	if(morale<30)
		return MoraleTable[MORALET_LOW];
	if(morale<40)
		return MoraleTable[MORALET_POOR];
	if(morale<50)
		return MoraleTable[MORALET_NORMAL];
	if(morale<60)
		return MoraleTable[MORALET_ELATED];
	if(morale<70)
		return MoraleTable[MORALET_GOOD];
	if(morale<80)
		return MoraleTable[MORALET_HIGH];
	if(morale<90)
		return MoraleTable[MORALET_EXCELLENT];
	if(morale<=100)
		return MoraleTable[MORALET_HEROIC];
	return "";
}

string GetLoyalityName(int iLoyality)
{
	if(iLoyality<10)
		return LoyalityTable[MORALET_TREACHEROUS];
	if(iLoyality<20)
		return LoyalityTable[MORALET_AWFUL];
	if(iLoyality<30)
		return LoyalityTable[MORALET_LOW];
	if(iLoyality<40)
		return LoyalityTable[MORALET_POOR];
	if(iLoyality<50)
		return LoyalityTable[MORALET_NORMAL];
	if(iLoyality<60)
		return LoyalityTable[MORALET_ELATED];
	if(iLoyality<70)
		return LoyalityTable[MORALET_GOOD];
	if(iLoyality<80)
		return LoyalityTable[MORALET_HIGH];
	if(iLoyality<90)
		return LoyalityTable[MORALET_EXCELLENT];
	if(iLoyality<=100)
		return LoyalityTable[MORALET_HEROIC];
	return "";
}

// boal 15/01/04 учет вещей выношу в спец метод для простоты работы далее -->
int SetCharacterSkillByItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, int _addValue)
{
	int iRetValue = 0;

	if(_skillName == _itemSkillName && GetCharacterItem(_refCharacter, _item) > 0)
	{
		iRetValue = _addValue;
	}

	return iRetValue;
}

int SetCharacterSkillByEquippedItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, int _addValue)
{
	int iRetValue = 0;
	
	if(_skillName == _itemSkillName && IsEquipCharacterByArtefact(_refCharacter, _item))
	{
		iRetValue = _addValue;
	}
	
	return iRetValue;
}

float AddMultiplySkillByEquippedItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, float _addValue)
{
	float fRetValue = 1.0;
	
	if(_skillName == _itemSkillName && IsEquipCharacterByArtefact(_refCharacter, _item))
	{
		fRetValue = _addValue;
	}
	
	return fRetValue;
}

int ApplySPECIALCirassPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return 0;

	switch(sSuit)
	{	
		case "cirass1"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;			
			if(sSkillName == SPECIAL_A)			iValue = -2;			
		break;
				
		case "cirass2"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
				
		case "cirass3"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "cirass4"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;
		break;
		
		case "cirass6"	:
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "cirass7"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "cirass8"	:
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "suit1"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit2"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit3"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit4"	:
			if(sSkillName == SPECIAL_P)			iValue = -1; // калеуче
		break;
		
		case "underwater"	: //Jason: водолаз
			if(sSkillName == SPECIAL_P)			iValue = -2;
			if(sSkillName == SPECIAL_E)			iValue = -2;
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
	}

	if (iValue < 0 && CheckAttribute(pchar, "CSM.CuirassNoPenalty")) iValue = 0; // --> CheatSurfMenu by Cheatsurfer

	return iValue;
}

int GetCharacterSuitType(ref rChar)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return -1;

	switch(sSuit)
	{	
		// тяжелые доспехи
		case "cirass1"	:
			iValue = 2;
		break;		
		case "cirass2"	:
			iValue = 2;
		break;				
		case "cirass3"	:
			iValue = 2;
		break;				
		case "cirass4"	:
			iValue = 2;
		break;
		
		// легкие доспехи
		case "cirass5"	:
			iValue = 1;
		break;				
		case "cirass6"	:
			iValue = 1;
		break;				
		case "cirass7"	:
			iValue = 1;
		break;				
		case "cirass8"	:
			iValue = 1;
		break;		
		
		// прочее
		case "underwater":
			iValue = 0;
		break;						
		case "suit1":
			iValue = 0;
		break;						
		case "suit2":
			iValue = 0;
		break;						
		case "suit3":
			iValue = 0;
		break;				
	}
		
	return iValue;
}

// Warship 25.10.08 Учет одежды
int SetCharacterSkillBySuit(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return 0;
	
	switch(sSuit)
	{	
		case "cirass1"	:
			if(sSkillName == SKILL_SNEAK)		iValue = -5;
		break;

		case "cirass2"	:
			if(sSkillName == SKILL_SNEAK)		iValue = -10;
		break;

		case "cirass3"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 5;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "cirass4"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 10;
			if(sSkillName == SKILL_SNEAK)		iValue = -20;
		break;
		
		case "cirass6"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -5;
			if(sSkillName == SKILL_SNEAK)		iValue = -5;
		break;
		
		case "cirass7"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -10;
			if(sSkillName == SKILL_SNEAK)		iValue = -10;
		break;
		
		case "cirass8"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -15;
			if(sSkillName == SKILL_SNEAK)		iValue = 15;
		break;
		
		case "suit1"	: // Французский офицерский мундир
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit2"	: // Английский офицерский мундир
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit3"	: // Испанский офицерский мундир
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit4"	: // костюм Лампорта (Калеуче)
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -25;
			if(sSkillName == SKILL_SNEAK)		iValue = 30;
		break;
		
		case "underwater"	: // Jason: водолаз
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -20;
			if(sSkillName == SKILL_SNEAK)		iValue = -100;
			if(sSkillName == SKILL_F_LIGHT)		iValue = -15;
			if(sSkillName == SKILL_FENCING)		iValue = -15;
			if(sSkillName == SKILL_F_HEAVY)		iValue = -15;
			if(sSkillName == SKILL_PISTOL)		iValue = -50;
		break;
	}

	if (iValue < 0 && CheckAttribute(pchar, "CSM.CuirassNoPenalty")) iValue = 0; // --> CheatSurfMenu by Cheatsurfer

	return iValue;
}
// Jason: учет негенерируемых клинков
int SetCharacterSkillByQuestBlade(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sBlade = GetCharacterEquipByGroup(rChar, BLADE_ITEM_TYPE);
	
	switch(sBlade)
	{	
		case "knife_01"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 5;
		break;
		
		case "q_blade_10"	:
			if(sSkillName == SKILL_FENCING)		iValue = 10;
		break;
		
		case "q_blade_13"	:
			if(sSkillName == SKILL_F_HEAVY)		iValue = 10;
		break;
		
			case "q_blade_16"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 10;
		break;
		
			case "q_blade_18"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 12;
		break;
		
			case "q_blade_19"	:
			if(sSkillName == SKILL_FENCING)		iValue = 12;
		break;
		
			case "q_blade_21"	:
			if(sSkillName == SKILL_F_HEAVY)		iValue = 12;
		break;
		
		case "topor_06"	: // Addon 2016-1 Jason Пиратская линейка
			if(sSkillName == SKILL_F_HEAVY)		iValue = 5;
		break;
	}
	
	return iValue;
}

// Jason: спец.атрибут
int SetCharacterSkillByPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	int iPenalty = sti(rChar.GenQuest.BladePenalty);
	
	if(sSkillName == SKILL_F_LIGHT)		iValue = -iPenalty;
	if(sSkillName == SKILL_FENCING)		iValue = -iPenalty;
	if(sSkillName == SKILL_F_HEAVY)		iValue = -iPenalty;
	
	return iValue;
}

// Jason: спец.атрибут
int ApplySPECIALQuestPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	int iPenalty = sti(rChar.GenQuest.EnergyPenalty);
	
	if(sSkillName == SPECIAL_A)			iValue = -iPenalty;
	
	return iValue;
}

// Jason: зелья мангаросы
int ApplySPECIALMangarosaPotion(ref rChar, String sSkillName) // 280313
{
	int iValue = 0;
	if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion"))
	{
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Power"))
		{
			if(sSkillName == SPECIAL_S)			iValue = 2;
			if(sSkillName == SPECIAL_E)			iValue = 2;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Fast"))
		{
			if(sSkillName == SPECIAL_A)			iValue = 2;
			if(sSkillName == SPECIAL_P)			iValue = 2;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Total"))
		{
			if(sSkillName == SPECIAL_S)			iValue = 1;
			if(sSkillName == SPECIAL_E)			iValue = 1;
			if(sSkillName == SPECIAL_A)			iValue = 1;
			if(sSkillName == SPECIAL_P)			iValue = 1;
			if(sSkillName == SPECIAL_C)			iValue = 1;
			if(sSkillName == SPECIAL_L)			iValue = 2;
		}
	}
	return iValue;
}

int SetCharacterSkillByMangarosa(ref rChar, String sSkillName) // 280313
{
	int iValue = 0;
	if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion"))
	{
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Power"))
		{
			if(sSkillName == SKILL_F_HEAVY)		iValue = 15;
			if(sSkillName == SKILL_FENCING)		iValue = 5;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Fast"))
		{
			if(sSkillName == SKILL_F_LIGHT)		iValue = 10;
			if(sSkillName == SKILL_PISTOL)		iValue = 10;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Total"))
		{
			if(sSkillName == SKILL_F_HEAVY)		iValue = 5;
			if(sSkillName == SKILL_F_LIGHT)		iValue = 5;
			if(sSkillName == SKILL_PISTOL)		iValue = 5;
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 5;
			if(sSkillName == SKILL_FORTUNE)		iValue = 5;
		}
	}
	
	return iValue;
}

// Jason: Калеуче - амулеты Туттуатхапака
int SetCharacterSkillByTuttuat(ref rChar, String sSkillName)
{
	int iValue = 0;
	
	if(sSkillName == SKILL_F_LIGHT)		iValue = 25;
	if(sSkillName == SKILL_FENCING)		iValue = 25;
	if(sSkillName == SKILL_F_HEAVY)		iValue = 25;
	if(sSkillName == SKILL_PISTOL)		iValue = 25;
	
	return iValue;
}

// boal 15/01/04 учет вещей выношу в спец метод для простоты работы далее <--
float GetCharacterSkillToOld(ref _refCharacter, string skillName)
{
    return makefloat(GetCharacterSkill(_refCharacter, skillName) / SKILL_TO_OLD);
}
int GetCharacterSkill(ref _refCharacter, string skillName)
{
    int skillN;

    // boal 051104 метод тормозит страшно - проверка +1 вещей, будет опрос раз в 10
    if (CheckAttribute(_refCharacter, "BakSkill." + skillName))
    {
        if (sti(_refCharacter.BakSkillCount.(skillName)) < 20 )
        {
            _refCharacter.BakSkillCount.(skillName) = sti(_refCharacter.BakSkillCount.(skillName)) + 1;
            return sti(_refCharacter.BakSkill.(skillName));
        }
    }

	skillN = GetCharacterSkillSimple(_refCharacter, skillName);


    // 14.03.05 пенальти от класса корабля -->
 	skillN = ApplayNavyPenaltyToSkill(_refCharacter, skillName, skillN);
	// 14.03.05 пенальти от класса корабля <--

	_refCharacter.BakSkill.(skillName)      =  skillN; // значение
    _refCharacter.BakSkillCount.(skillName) = rand(5); // счетчик немного размажем пересчет

    return skillN;
}

int GetCharacterSkillSimple(ref _refCharacter, string skillName)
{
	if( !CheckAttribute(_refCharacter,"Skill."+skillName) ) return 1;
	int skillN = sti(_refCharacter.Skill.(skillName));

	bool   bHero = (sti(_refCharacter.index) == GetMainCharacterIndex());
	
    // boal учет вещей -->
    if (bHero || CheckAttribute(_refCharacter, "Payment")) //IsCompanion(_refCharacter) || IsOfficer(_refCharacter))
    {
        // Health
        if (bHero && MOD_SKILL_ENEMY_RATE > 1) // не халява
        {
            if (isSelfTypeSkill(skillName))
            {
                skillN = skillN + 5*(GetHealthNum(_refCharacter) - 6); // max -5
            }
        }
		
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		"SkullAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	"SkullAztec", 	 10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, 		"KnifeAztec", 	-30);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		  "mineral8",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		 "mineral14",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 			 "Coins",   -50);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	 "mineral30",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	 "mineral31", 	-10);
    	skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE,       "mineral31", 	-10);
		
		skillN += SetCharacterSkillByEquippedItem(_refCharacter, skillName, SKILL_SAILING, "obereg_7", 10);

    	// Тотемы ацтеков
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "Totem_001", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "Totem_002", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "Totem_003", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_ACCURACY, "Totem_004", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "Totem_005", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "Totem_006", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "Totem_007", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "Totem_008", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "Totem_009", 10); 
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "Totem_0010", 10); 
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SAILING, "Totem_0012", 10);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_REPAIR, "Totem_0015", 10);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "SkullAztecs", -20);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "SkullAztecs", 10);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "KnifeAztecs", -30);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "KnifeAztecs", -20);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "KnifeAztecs", -20);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "KnifeAztecs", -20);

    	//itmname_indian001	{Оберег Тлальчитонатиу} (+10 харизма и удача, -20 пистоли/мушкеты).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian001", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian001", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "indian001", -20);

// itmname_indian002	{Пугающая Фигурка} (-10 харизма)
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian002", -10);

	// itmname_indian003	{Нефритовая маска} (+10 торговля).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "indian003", 10);

    	// itmname_indian005	{Маска Маркуханкату} (+10 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian005", 10);

    // itmname_indian006 {Амулет Шиукоатля} (+10 сабли/тесаки)
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "indian006", 10);

// itmname_indian007	{Идол Великой Матери} (+10 везение).
skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "indian007", 10);

   // itmname_indian010	{Оберег Эхекатля} (+20 пистоли/мушкеты, +10 меткость, -20 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "indian010", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian010", -20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_ACCURACY, "indian010", 10);

    	// itmname_indian012	{Кубок-тотем Тепейоллотля} (+10 палаши/топоры).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "indian012", 10);

    	// itmname_indian014	{Чаша Ололиуки} (+20 торговля, -20 харизма).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian014", -20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "indian014", 20);

    	// itmname_indian015	{Золотой диск} (+10 харизма и защита, -10 везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian015", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "indian015", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "indian015", -10);

    	// itmname_indian017	{Тельная ладанка} (+10 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian017", 10);

    	// itmname_indian018	{Идол Атлауа} (+20 навигация, -20 везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SAILING, "indian018", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian018", -20);

    	// itmname_indian019	{Статуэтка Тлалока} (+20 меткость, +10 орудия, -20 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_ACCURACY, "indian019", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_CANNONS, "indian019", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian019", -20);

 		// itmname_indian020	{Церемониальный нож} (+20 харизма и -10 везение)
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian020", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "indian020", -10);

 		// itmname_indian021	{Церемониальный сосуд} (+20 харизма, -10 везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian021", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "indian021", -10);

    	// itmname_indian022	{Статуэтка Пакаля} (+20 защита, +10 всё фехтование, -10 харизма и везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "indian022", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "indian022", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "indian022", -10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "indian022", -10);

		// itmname_Obsession_Coins	{Три монеты} (+10 харизма, +10 везение, +10 торговля).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "Obsession_Coins", 10);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "Obsession_Coins", 10);
		skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "Obsession_Coins", 10);

        // крест Антониу де Соуза +30 везение, +20 харизма, +10 торговля.
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "DeSouzaCross", 30);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "DeSouzaCross", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "DeSouzaCross", 10);

    	//  кольцо Ли (+20 защита, +20 всё фехтование, +20 харизма и везение, +30 торговля).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "DOjeronRing", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "DOjeronRing", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "DOjeronRing", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "DOjeronRing", 20);
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "DOjeronRing", 30);

	//  Ранец (-20 все боевые навыки и скрытность).
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "BackPack4", -20);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "BackPack4", -20);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "BackPack4", -20);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "BackPack4", -20);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "BackPack4", -20);

	//  Сумка (-15 все боевые навыки и скрытность).
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "BackPack3", -15);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "BackPack3", -15);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "BackPack3", -15);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "BackPack3", -15);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "BackPack3", -15);

	//  Вализа (-10 все боевые навыки и скрытность).
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "BackPack2", -10);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "BackPack2", -10);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "BackPack2", -10);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "BackPack2", -10);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "BackPack2", -10);

	//  Мешок (-5 все боевые навыки и скрытность).
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "BackPack1", -5);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "BackPack1", -5);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "BackPack1", -5);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "BackPack1", -5);
	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "BackPack1", -5);

	// itmname_sculMa1 {Белый хрустальный череп} (+30 защита).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "sculMa1", 30);

	// itmname_sculMa2 {Розовый хрустальный череп} (+30 абордаж).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_GRAPPLING, "sculMa2", 30);

	// itmname_sculMa3 {Голубой хрустальный череп} (+30 починка).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_REPAIR, "sculMa3", 30);

		// itmname_jewelry1 {Аметист} (+1 везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "jewelry1", 1);

		// itmname_jewelry2 {Алмаз} (+1 харизма).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, "jewelry2", 1);

		// itmname_jewelry3 {Рубин} (+1 починка).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_REPAIR, "jewelry3", 1);

		// itmname_jewelry4 {Изумруд} (+1 меткость).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_ACCURACY, "jewelry4", 1);

		// itmname_jewelry7 {Голубой янтарь} (+1 торговля).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "jewelry7", 1);

		// itmname_jewelry8 {Янтарь} (+1 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "jewelry8", 1);

		// itmname_jewelry9 {Морион} (+1 орудия).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_CANNONS, "jewelry9", 1);

		// itmname_jewelry14 {Огненный опал} (+1 пистоли/мушкеты).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, "jewelry14", 1);

		// itmname_jewelry15 {Аквамарин} (+1 навигация).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SAILING, "jewelry15", 1);

		// itmname_jewelry16 {Опал} (+1 защита).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_DEFENCE, "jewelry16", 1);

		// itmname_jewelry17 {Гиацинт} (+1 торговля).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_COMMERCE, "jewelry17", 1);

		// itmname_jewelry18 {Хризопраз} (+1 рапиры/шпаги).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, "jewelry18", 1);

		// itmname_jewelry19 {Коралл} (+1 сабли/тесаки).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, "jewelry19", 1);

		// itmname_jewelry20 {Бирюза} (+1 палаши/топоры).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, "jewelry20", 1);

		// itmname_jewelry21 {Лазурит} (+1 скрытность).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_SNEAK, "jewelry21", 1);

		// itmname_jewelry22 {Нефрит} (+1 абордаж).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_GRAPPLING, "jewelry22", 1);

		// itmname_jewelry23 {Хризоберилл} (+1 везение).
    	skillN = skillN + SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, "jewelry23", 1);

		// Warship 25.10.08 Новый учет одежды
		skillN += SetCharacterSkillBySuit(_refCharacter, skillName);
	
		//Jason: учет негенерируемых клинков
		skillN += SetCharacterSkillByQuestBlade(_refCharacter, skillName);
		skillN += SetCharacterSkillByMangarosa(_refCharacter, skillName);
	
		//Jason: учет специальных атрибутов
		if(CheckAttribute(_refCharacter, "GenQuest.BladePenalty")) 
			{
				skillN += SetCharacterSkillByPenalty(_refCharacter, skillName);
			}
		//Jason: Калеуче
		if(IsCharacterEquippedArtefact(_refCharacter, "kaleuche_amulet2"))
		{
			skillN += SetCharacterSkillByTuttuat(_refCharacter, skillName);
		}
		//navy --> действие алкоголя
		if (CheckAttribute(_refCharacter, "chr_ai.drunk.skill." + skillName))
		{
			skillN += sti(_refCharacter.chr_ai.drunk.skill.(skillName));
		}
		//<--
		// ugeen - должно быть в конце, множители к скиллам по наличию артефактов
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,   SKILL_ACCURACY, "indian_9", 1.10));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,      SKILL_SNEAK, "obereg_4", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,    SKILL_FORTUNE, "obereg_5", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName, SKILL_LEADERSHIP, "obereg_6", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,   SKILL_COMMERCE, "obereg_8", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,    SKILL_FORTUNE, "amulet_7", 0.50));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,      SKILL_SNEAK, "amulet_6", 0.50));
		
		if(!IsDay())
		{
			if(IsCharacterEquippedArtefact(_refCharacter, "totem_12") && skillName == SKILL_ACCURACY) 
			{
				skillN = skillN * 2; // получи фашист гранату по ночам !!!!
			}
		}
		if(CheckCharacterPerk(_refCharacter, "Trustworthy") && (CheckCharacterItem(_refCharacter, "newblade11")) && skillName == SKILL_LEADERSHIP)
		{
			skillN = skillN + 15;
		}
		if(CheckCharacterPerk(_refCharacter, "HT2") && (CheckCharacterItem(_refCharacter, "Chest")) && skillName == SKILL_COMMERCE)
		{
			skillN = skillN + 15;
		}
		if(CheckCharacterPerk(_refCharacter, "HT3") && (CheckCharacterItem(_refCharacter, "potionrum")) && skillName == SKILL_FENCING)
		{
			skillN = skillN + 15;
		}
		if(CheckCharacterPerk(_refCharacter, "HT1") && (CheckCharacterItem(_refCharacter, "potionwine")) && skillName == SKILL_F_LIGHT)
		{
			skillN = skillN + 15;
		}
	if(CheckCharacterPerk(_refCharacter, "HT4") && (CheckCharacterItem(_refCharacter, "Amminition_Tool")) && skillName == SKILL_PISTOL)
		{
			skillN = skillN + 15;
		}
	if(CheckCharacterPerk(_refCharacter, "HT5") && (CheckCharacterItem(_refCharacter, "jewelry45")) && skillName == SKILL_F_HEAVY)
		{
			skillN = skillN + 15;
		}

    	// boal учет перегруза 19.01.2004 -->
    	if ( GetItemsWeight(_refCharacter) > GetMaxItemsWeight(_refCharacter) && !IsEquipCharacterByArtefact(_refCharacter, "totem_06"))
    	{
   	        skillN -= 20;
    	}
    	// boal учет перегруза 19.01.2004 <--
	}
	// boal <--
	if (skillN <= 1) skillN = 1;
	if( skillN > SKILL_MAX ) skillN = SKILL_MAX;

	return skillN;
}
// boal 20.03.2004 -->
int GetShipClassNavySkill(int shipClass)
{
    int needSkill = 0;

    switch (shipClass)
    {
            case 1 : needSkill = 95; break;
            case 2 : needSkill = 80; break;
            case 3 : needSkill = 65; break;			
            case 4 : needSkill = 45; break;			
			case 5 : needSkill = 25; break;
            case 6 : needSkill = 1; break;
    }
    return needSkill;
}
// boal 20.03.2004 <--
void DelBakSkillAttr(ref _refCharacter) // boal оптимизация скилов
{
    DeleteAttribute(_refCharacter, "BakSkill");
    DeleteAttribute(_refCharacter, "BakSkillCount");
}
// сброс всех порогов (буфер расчета, пересчитывается от вещей +1)
void ClearCharacterExpRate(ref _chref)
{
    int    i;
    string name;

    for (i=1; i<15; i++)
    {
        name = GetSkillNameByIdx(i);
        DeleteAttribute(_chref, "skill." + name + "_rate");
    }
}
// когда меняется порог кача, нужно сбросить очки, иначе будет по 120%
void RefreshCharacterSkillExpRate(ref _chref)
{
    int    i;
    string name;

    for (i=1; i<15; i++)
    {
        name = GetSkillNameByIdx(i);
        AddCharacterExpToSkill(_chref, name, 0.0);
        ApplayNewSkill(_chref, name, 0); // иначе перки  будут 23/22
    }
}

float GetSummonSkillFromNameToOld(ref _refCharacter, string skillName)
{
    return (GetSummonSkillFromName(_refCharacter, skillName) / SKILL_TO_OLD);
}
int GetSummonSkillFromName(ref _refCharacter, string skillName)
{
    int sumSkill;

    // boal 051104 метод тормозит страшно - проверка +1 вещей, будет опрос раз в 10
    if (CheckAttribute(_refCharacter, "BakSkill." + skillName))
    {
        if (sti(_refCharacter.BakSkillCount.(skillName)) < 25 )
        {
            _refCharacter.BakSkillCount.(skillName) = sti(_refCharacter.BakSkillCount.(skillName)) + 1;
            return sti(_refCharacter.BakSkill.(skillName));
        }
    }

    sumSkill = GetSummonSkillFromNameSimple(_refCharacter, skillName);

    // boal 27.01.2004 пенальти за крутой корабль -->
 	sumSkill = ApplayNavyPenaltyToSkill(_refCharacter, skillName, sumSkill);
    // boal 27.01.2004 <--

    _refCharacter.BakSkill.(skillName)      =  sumSkill; // значение
    _refCharacter.BakSkillCount.(skillName) = rand(5); // счетчик немного размажем пересчет

    return sumSkill;
}

int GetSummonSkillFromNameSimple(ref _refCharacter, string skillName)
{
    int sumSkill = GetCharacterSkillSimple(_refCharacter,skillName);

	if (sti(_refCharacter.index) == sti(pchar.index))
	{
	    int iOfficer = -1;
		int iOffSkill = -1;
		switch (skillName)
		{
			/*case SKILL_LEADERSHIP:
				iOfficer = sti(pchar.Fellows.Passengers.boatswain);
			break;*/

			case SKILL_SAILING:
				iOfficer = sti(pchar.Fellows.Passengers.navigator);
			break;

			case SKILL_CANNONS:
				iOfficer = sti(pchar.Fellows.Passengers.cannoner);
			break;

			case SKILL_ACCURACY:
				iOfficer = sti(pchar.Fellows.Passengers.cannoner);
			break;

			case SKILL_GRAPPLING:
				iOfficer = sti(pchar.Fellows.Passengers.boatswain);
			break;

			case SKILL_DEFENCE:
				iOfficer = sti(pchar.Fellows.Passengers.doctor);
			break;

			case SKILL_REPAIR:
				iOfficer = sti(pchar.Fellows.Passengers.carpenter);
			break;

			case SKILL_COMMERCE:
				iOfficer = sti(pchar.Fellows.Passengers.treasurer);
			break;
		}

		if(iOfficer != -1)
		{
			iOffSkill = GetCharacterSkillSimple(&characters[iOfficer], skillName);
			if (iOffSkill > sumSkill)
			{
				sumSkill = iOffSkill;
			}
		}
	}
	return sumSkill;
}

void AddPartyExp(ref _refCharacter,int _exp)
{
	/*int cn,i;
	ref chref;
	i = GetOfficersQuantity(_refCharacter);
	_exp = (_exp+i)/(i+1);
	for(i=0; i<4; i++)
	{
		cn = GetOfficersIndex(_refCharacter,i);
		if(cn!=-1)
		{	AddCharacterExp(GetCharacter(cn),_exp);
		}
	}*/
}

void AddExpAndShow(ref chref, int _exp)
{
	// boal Log_SetStringToLog("+" + _exp + XI_ConvertString("add experience"));
	//AddCharacterExp(chref, _exp);
}
// boal -->


void AddCharacterExpToSkillSquadron(ref _refCharacter, string _skill, float _addValue)
{
    int cn,i;
	ref chref;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{    // и квестовым тоже
			AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue);
		}
	}
}
void AddCharacterExpToSkill(ref _chref, string _skill, float _addValue)
// _chref - character _skill - name ex -"Fencing"  _skill_exp = "Fencing_exp"   _addValue = 100
{
    string  _skill_exp = _skill + "_exp";
    if (!CheckAttribute(_chref, "skill." + _skill_exp))
    {
        _chref.skill.(_skill_exp) = 0;
    }
	
    if (bExpLogShow && _addValue > 0)
    {
	   if (IsOfficer(_chref))  Log_Info(_chref.id + " take " + FloatToString(_addValue, 2) + " exp to " + _skill);
    }
    // boal 300804 падение экспы -->
    if (_addValue < 0)
    {
        if(CheckAttribute(_chref, "skill." + _skill_exp))
        {
            _chref.skill.(_skill_exp) = sti(_chref.skill.(_skill_exp)) + _addValue;
            if (sti(_chref.skill.(_skill_exp)) < 0)
            {
                _chref.skill.(_skill_exp) = 0;
            }
        }
        return;
    }
    // boal 300804 падение экспы <--
    if (CheckAttribute(_chref, "skill." + _skill) && sti(_chref.skill.(_skill)) < SKILL_MAX)// && sti(_chref.skill.(_skill)) > 0)
    { // if skill = 0 then it is great loser
        _chref.skill.(_skill_exp) = stf(_chref.skill.(_skill_exp)) + _addValue;

        while ( makeint(sti(_chref.skill.(_skill)) * GetCharacterExpRate(_chref, _skill)) <= stf(_chref.skill.(_skill_exp))
                && sti(_chref.skill.(_skill)) < SKILL_MAX )
        {
            _chref.skill.(_skill_exp) = stf(_chref.skill.(_skill_exp)) - makeint(sti(_chref.skill.(_skill)) * GetCharacterExpRate(_chref, _skill));
            /*if (sti(_chref.index) == GetMainCharacterIndex())
            {
               Log_SetStringToLog(XI_ConvertString(_skill)+" UP");
            } */
            AddCharacterSkillDontClearExp(_chref, _skill, 1);
            // оптимизация скилов
            DeleteAttribute(_chref, "BakSkill." + _skill);
            DeleteAttribute(_chref, "BakSkillCount." + _skill);
        }
    }
    /// officers
    if (_addValue > 0 && sti(_chref.index) == GetMainCharacterIndex()) // только для ГГ
    {
		int cn, i, iPas;
		iPas = GetPassengersQuantity(_chref); // оптимиация
		if (CheckCharacterPerk(_chref, "SharedExperience"))
		{
			for(i=0; i<iPas; i++)
			{
				cn = GetPassenger(_chref,i);
				if(cn!=-1)
				{
				   if (isOfficerInShip(GetCharacter(cn), true))
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 2.0);
				   }
				   else
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 10.0);
				   }
				}
			}
	        for(i=1; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(_chref,i);
				if(cn!=-1)
				{
					AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 3.0);
				}
			}
		}
		else
		{
		    for(i=0; i<iPas; i++)
			{
				cn = GetPassenger(_chref,i);
				if(cn!=-1)
				{
				   if (isOfficerInShip(GetCharacter(cn), true))
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 4.0);
				   }
				   else
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 20.0);
				   }
				}
			}
	        for(i=1; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(_chref,i);
				if(cn!=-1)
				{
					AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 6.0);
				}
			}
		}
    }
}

string GetPerkListText(ref _chref, string _type)
{
    int    perksQ,i;
    int    lngFilePerkID = -1;
	string perkName;
	string ret;
	aref   arPerksRoot;

    lngFilePerkID = LanguageOpenFile("AbilityDescribe.txt");
	// Варианты перков, которые можно добавить
	makearef(arPerksRoot, _chref.perks.list);
	perksQ = GetAttributesNum(arPerksRoot);
	ret = "";
	for(i=0; i<perksQ; i++)
	{
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));

        if (CheckAttribute(&ChrPerksList, "list." + perkName) && CheckAttribute(&ChrPerksList, "list." + perkName + ".BaseType"))
        {
            if (ChrPerksList.list.(perkName).BaseType == _type)
            {
                ret += "* " + LanguageConvertString(lngFilePerkID, perkName) + " ";
            }
        }
	}
	LanguageCloseFile(lngFilePerkID);
	return ret;
}
// boal Вес предметов 19.01.2004 -->
float GetItemsWeight(ref _chref)
{
    float   Amount = 0;
    int     j;
    string  itemID;
    ref     itm;

    if (bCabinStarted || bAbordageStarted || !bSeaActive || !CheckAttribute(_chref, "ItemsWeight"))
    {
        for (j=0; j<TOTAL_ITEMS; j++)
    	{
    		makeref(itm,Items[j]);
			
			if(CheckAttribute(itm, "ID"))
			{
				itemID = itm.id;
				if (CheckAttribute(_chref, "items."+itemID) && itemID != "MapsAtlas")      // ugeen - атлас карт не учитываем !!
				{
					Amount += sti(_chref.items.(itemID))*stf(itm.Weight);
				}
			}
        }
        _chref.ItemsWeight = Amount; // оптимицация тормозов в бою на море
    }
    else
    {
        Amount = stf(_chref.ItemsWeight);
    }
    return Amount;
}
int GetMaxItemsWeight(ref _chref)
{
	if (CheckAttribute(_chref, "Skill.FencingS") && !CheckAttribute(_chref, "CSM.CargoTank")) // --> CheatSurfMenu by Cheatsurfer
    {
        int iBonus = 100;
        if (IsCharacterPerkOn(_chref, "Grus")) iBonus = 150;
	// Lugger -->
	        if(CheckAttribute(_chref, "equip.backpack"))
	        {
	        	if(_chref.equip.backpack != "")
	        	{
	        		ref BackPack = ItemsFromID(_chref.equip.backpack);
	        		int iBackPack = sti(BackPack.BackPackWeight);
	        		
	        		iBonus += iBackPack;
	        	}
	        }
		// Lugger <--
         //опасная рекурсия  если писать GetCharacterSPECIAL
        // iBonus = iBonus + CHAR_ITEMS_WEIGHT + GetCharacterSPECIALSimple(_chref, SPECIAL_S)*(GetCharacterSPECIALSimple(_chref, SPECIAL_E) + 12 - MOD_SKILL_ENEMY_RATE);
		// CheatSurfMenu by Cheatsurfer -->
		iBonus = iBonus + iCSMBaseWeight + GetCharacterSPECIALSimple(_chref, SPECIAL_S)*(GetCharacterSPECIALSimple(_chref, SPECIAL_E) + 12 - MOD_SKILL_ENEMY_RATE);
		if(IsEquipCharacterByArtefact(_chref, "obereg_3")) iBonus = makeint(iBonus * 1.15);
		if(IsEquipCharacterByArtefact(_chref, "indian_7")) iBonus = makeint(iBonus * 0.9);
        return  iBonus;
    }
    else
    {
        return 1000000; // сундук или труп не имееют скила и ограничения
    }
}
// boal 19.01.2004 <--

// boal -->
int Statistic_AddValue(ref _chref, string _attrName, int _add) // set and get(_add==0) value
{
    // KillShip_ 1..6
    // AbordShip_ 1..6
    // KillAbordShip_ 1..6
    // Solder_s  Solder_g ( s=sword g=gun)
    // Citizen_s  Citizen_g
    // Monster_s Monster_g
    // Warrior_s  Warrior_g
    // Fort
	
	if(!CheckAttribute(_chref, "index")) return 0;
	
    if (sti(_chref.index) != GetMainCharacterIndex()) return 0; // оптимизация
    
    if( !CheckAttribute(_chref,"Statistic." + _attrName) )
    {
        _chref.Statistic.(_attrName) = 0;
    }
    _chref.Statistic.(_attrName) = sti(_chref.Statistic.(_attrName)) + _add;

    if (sti(_chref.Statistic.(_attrName)) < 0)
    {
        _chref.Statistic.(_attrName) = 0;
    }
    return sti(_chref.Statistic.(_attrName));
}
void Statistic_KillChar(aref _attack, aref _enemy, string _attrName)
{
	if (sti(_attack.index) != GetMainCharacterIndex()) return; // оптимизация
	string  name = GetCharType(_enemy);

	name = name + _attrName;

	Statistic_AddValue(_attack, name, 1);
}

string GetCharType(aref _enemy)  //TO_DO переделать на тип в НПС
{
    string  name  	= "Warrior"; // define
    string  model 	= _enemy.model;
	string  _type;
	int     iNation = sti(_enemy.nation);
	
    switch (_enemy.chr_ai.type)
	{
		case LAI_TYPE_PATROL :
		    name = "Solder";
		break
		case LAI_TYPE_GUARDIAN :
		    name = "Solder";
		break
		case LAI_TYPE_OFFICER :
		    name = "Solder";
		break;
        // Citizen
		case LAI_TYPE_ACTOR :
		    name = "Citizen";
		break;
		case LAI_TYPE_BARMAN :
		    name = "Citizen";
		break;
		case LAI_TYPE_CITIZEN :
		    name = "Citizen";
		break;
		case LAI_TYPE_HUBER :
		    name = "Citizen";
		break;
		case LAI_TYPE_HUBERSTAY :
		    name = "Citizen";
		break;
		case LAI_TYPE_MERCHANT :
		    name = "Citizen";
		break;
		case LAI_TYPE_POOR :
		    name = "Citizen";
		break;
		case LAI_TYPE_PRIEST :
		    name = "Citizen";
		break;
		case LAI_TYPE_SIT :
		    name = "Citizen";
		break;
		case LAI_TYPE_STAY :
		    name = "Citizen";
		break;
		case LAI_TYPE_WAITRESS :
		    name = "Citizen";
		break;
		case LAI_TYPE_OWNER :
		    name = "Citizen";
		break;

		case LAI_TYPE_WARRIOR : // to_do преверить тип
			if (findsubstr(model, "canib_" , 0) != -1 || findsubstr(model, "itza_" , 0) != -1 || findsubstr(model, "miskito_" , 0) != -1)
			{
				name = "Indian";
			}
		    if (model == "mummy" || model == "Skel1" || model == "Skel2" || model == "Skel3" || model == "Skel4" || model == "skeletcap" || model == "VaterSkel_1" || model == "VaterSkel_2" || model == "VaterSkel_3" || model == "VaterSkel_4" || model == "Vaterskeletcap" || model == "Zombie_1" || model == "Zombie_2" || model == "Zombie_3" || model == "Zombie_4" || model == "Zombie_5" || model == "giant")
		    {
		        name = "Monster";
		    }
		    else
		    {
				if (model == "crabBig")
				{
					name = "Crab";
				}
				
				
                if (findsubstr(model, "off_" , 0) != -1)
                {
                    name = "Solder";
                }
                else
                {
                    if (findsubstr(model, "sold_" , 0) != -1)
	                {
	                    name = "Solder";
	                }
                }
				
				if (findsubstr(model, "pirate_" , 0) != -1 || findsubstr(model, "citiz_" , 0) != -1 || findsubstr(model, "mercen_" , 0) != -1 ) // ugeen 2016
				{
				
					if(CheckAttribute(_enemy,"PhantomType")) 
					{
						_type = _enemy.PhantomType;
						if(_type == "marginal" ) 
						{
							name = "marginal";
						}
					}
					else 
					{
						if(iNation == PIRATE)
						{
							name = "Pirate";
						}					
					}
				}					
				
		    }
		break;
	}

	return  name;
}
// boal statistic info 17.12.2003 <--

// boal Блок здоровье ГГ -->
int GetHealthNum(ref ch)
{
    if (!CheckAttribute(ch, "Health"))
	{
        return 0;
	}
    int i;

    i = makeint((stf(ch.Health.HP) + 9) / 10.0); // до целого

    return i;
}

int GetHealthMaxNum(ref ch)
{
    if (!CheckAttribute(ch, "Health"))
	{
        return 0;
	}
    int i;

    i = makeint((stf(ch.Health.maxHP) + 9) / 10.0); // до целого

    return i;
}

string GetHealthName(ref ch)
{
    string name = "";

    switch (GetHealthNum(ch))
    {
        case 1:
            name = "УЖАСНОЕ";
        break;
        case 2:
            name = "ПЛОХОЕ";
        break;
        case 3:
            name = "НЕВАЖНОЕ";
        break;
        case 4:
            name = "СРЕДНЕЕ";
        break;
        case 5:
            name = "ХОРОШЕЕ";
        break;
        case 6:
            name = "ОТЛИЧНОЕ";
        break;
    }
    return name;
}

string GetHealthNameMaxSmall(ref ch)
{
    string name = "";

    switch (GetHealthMaxNum(ch))
    {
        case 1:
            name = "ужасное";
        break;
        case 2:
            name = "плохое";
        break;
        case 3:
            name = "неважное";
        break;
        case 4:
            name = "среднее";
        break;
        case 5:
            name = "хорошее";
        break;
        case 6:
            name = "отличное";
        break;
    }
    return name;
}

void SetNewDayHealth()
{
    ref mainChr = GetMainCharacter();

    float maxhp = stf(mainChr.chr_ai.hp_max);
    float damg  = stf(mainChr.Health.Damg);
    int   add   = 0;

    mainChr.Health.Damg = 0.0;

    if (IsCharacterPerkOn(mainChr, "Medic"))
    {
        add = 1;
    }
	if(IsEquipCharacterByArtefact(mainChr, "amulet_6"))
	{
		add += 1;
	}
    if (damg >= (maxhp / 1.5) )
    {
        if ((damg / maxhp) > add)
        {
            AddCharacterHealth(mainChr, -damg / maxhp + add);
        }
    }
    else
    {
        if (!IsEntity(worldMap)) // не на карте
        {
            AddCharacterHealth(mainChr, 1 + add);
        }
        else
        {
            AddCharacterHealth(mainChr, 0.5 + add / 2.0);
        }
    }
}

void SetNewDayHealthMax()
{
    ref mainChr = GetMainCharacter();

    float maxhp = stf(mainChr.chr_ai.hp_max);
    float damg  = stf(mainChr.Health.weekDamg);

    mainChr.Health.weekDamg = 0.0;

    if (damg > (maxhp * 3.5 * isEquippedAmuletUse(mainChr, "amulet_6", 1.0, 1.15)))
    {
        AddCharacterMaxHealth(mainChr, -1);
    }
}

void AddCharacterHealth(ref mainChr, float add)
{
    float maxhp = stf(mainChr.chr_ai.hp_max);
    int   remHP = GetHealthNum(mainChr);

    mainChr.Health.HP = makefloat(stf(mainChr.Health.HP) + add);

    if (stf(mainChr.Health.HP) < 1)
    {
        mainChr.Health.HP = 1.0;
    }

    if (stf(mainChr.Health.HP) > stf(mainChr.Health.maxHP))
    {
        mainChr.Health.HP = stf(mainChr.Health.maxHP);
    }

    if (GetHealthNum(mainChr) > remHP)
    {
        Log_Info("Здоровье стало лучше");
    }

    if (GetHealthNum(mainChr) < remHP)
    {
        Log_Info("Здоровье стало хуже");
    }
}

void AddCharacterMaxHealth(ref mainChr, float add)
{
    mainChr.Health.maxHP = makefloat(stf(mainChr.Health.maxHP) + add);

    if (stf(mainChr.Health.maxHP) < 1)
    {
        mainChr.Health.maxHP = 1.0;
    }

    if (stf(mainChr.Health.maxHP) > 60)
    {
        mainChr.Health.maxHP = 60.0;
    }

    if (stf(mainChr.Health.HP) > stf(mainChr.Health.maxHP))
    {
        mainChr.Health.HP = stf(mainChr.Health.maxHP);
    }
}
// boal Блок здоровье ГГ <--

// увеличение счетчика награды за голову -->
int ChangeCharacterHunterScore(ref chref, string _huntName, int incr)
{
	int prevVal = -5; // мин набор

	if (_huntName == "pirhunter") return 0;
	if (CheckAttribute(chref, "GenQuest.HunterScore2Pause")) incr = 0;

	if (CheckAttribute(chref, "reputation." + _huntName) )	prevVal = sti(chref.reputation.(_huntName));

	int newVal = prevVal + incr;
	if (newVal < -100)  newVal = -100;
	if (newVal > 100)   newVal = 100;

	chref.reputation.(_huntName) = newVal;

	if( sti(chref.index) != GetMainCharacterIndex() ) return newVal;

	if (newVal >= 10)
	{
	 	if (prevVal < newVal)
		{
			Log_SetStringToLog(XI_ConvertString(_huntName) + " увеличила награду за Вашу голову");
		}

	    if (prevVal > newVal)
		{
	        Log_SetStringToLog(XI_ConvertString(_huntName) + " снизила награду за Вашу голову");
		}
	}
	else
	{
		int iNation = 0;
		switch (_huntName) // код для совместимости со старым
		{
		    case "enghunter":  iNation = ENGLAND; break;
		    case "frahunter":  iNation = FRANCE; break;
		    case "spahunter":  iNation = SPAIN; break;
		    case "holhunter":  iNation = HOLLAND; break;
		}
		string prevName = GetNationReputationName(iNation, -prevVal);
		string newName  = GetNationReputationName(iNation, -newVal);
		if (prevName!=newName)
		{
			string outString = XI_ConvertString("Your reputation with country")+ XI_ConvertString(Nations[iNation].Name + "Gen") +" ";
			if (incr<0)	{outString+=XI_ConvertString("increase");}
			else	{outString+=XI_ConvertString("decrease");}
			outString += " "+XI_ConvertString("to")+" "+newName;
			Log_SetStringToLog(outString);
		}
	}
	return newVal;
}

int ChangeCharacterNationReputation(ref chref, int _Nation, int incr)
{
	return -ChangeCharacterHunterScore(chref, NationShortName(_Nation) + "hunter", -incr); // все наоборот, - это хорошо, + есть НЗГ
}

string GetNationReputation(ref chref, int _Nation)
{
    return GetNationReputationName(_Nation, ChangeCharacterNationReputation(chref, _Nation, 0));
}

string GetNationReputationName(int _Nation, int i)
{
	if (i <= -10)  return "Награда за голову " + (-i*1000);
    if (i < 0 )    return "Враждебная";
    if (i <= 20 )  return "Нейтральная";
    if (i <= 50 )  return "Хорошая";
    if (i <= 80 )  return "Отличная";
    if (i <= 100 ) return "Восхищение";

    return "Отличная";
}
// boal 04.04.04
string NationShortName(int iNation)
{
    switch(iNation)
	{
		case ENGLAND:
            return "eng";
		break;
		case FRANCE:
            return "fra";
		break;
		case SPAIN:
            return "spa";
		break;
		case HOLLAND:
			return "hol";
		break;
		case PIRATE:
			return "pir";
		break;
	}
	return "eng";
}
// увеличение счетчика награды за голову <--


void setWDMPointXZ(string _location)
{
    // координаты на гловал карте -->
    int n;
	string sTemp;

    n = FindIslandBySeaLocation(_location);
	if(n!=-1)
	{
		worldMap.island = Islands[n].id;
		Pchar.curIslandId = worldMap.island; // fix
		sTemp = worldMap.island;
		if (CheckAttribute(&worldMap, "islands." + sTemp))
		{
		    worldMap.zeroX = worldMap.islands.(sTemp).position.x;
			worldMap.zeroZ = worldMap.islands.(sTemp).position.z;
			if (CheckAttribute(&worldMap, "islands." + sTemp + "." + _location))
			{
			    worldMap.playerShipX = worldMap.islands.(sTemp).(_location).position.x;
				worldMap.playerShipZ = worldMap.islands.(sTemp).(_location).position.z;
				//trace(sTemp + "." + _location);
			}
			else
			{// для бухт с незаданными координатами
			    worldMap.playerShipX = worldMap.zeroX;
				worldMap.playerShipZ = worldMap.zeroZ;
			}
		}
	}
	// координаты на гловал карте <--
}


// нужно не перекрывать еще и признаки фантома
void ChangeAttributesFromCharacter(ref CopyChref, ref PastChref, bool _dialogCopy)
{
    aref arToChar;
    aref arFromChar;

    CopyChref.model            = PastChref.model;
    CopyChref.model.animation  = PastChref.model.animation;
    CopyChref.sex              = CopyChref.sex;
    CopyChref.headModel        = PastChref.headModel;
    CopyChref.FaceId           = PastChref.FaceId;
    CopyChref.nation           = PastChref.nation;

	CopyChref.name             = PastChref.name;
    CopyChref.lastname         = PastChref.lastname;

    CopyChref.rank             = PastChref.rank;
    CopyChref.reputation       = makeint(PastChref.reputation);
	
	CopyChref.baseCapIdx       = PastChref.index; //Id оригинального в структуру клона

    if (CheckAttribute(PastChref, "loyality"))
    {
    	CopyChref.loyality         = PastChref.loyality;
	}
	else DeleteAttribute(CopyChref, "loyality");
	if (CheckAttribute(PastChref, "alignment"))
	{
    	CopyChref.alignment        = PastChref.alignment;
    }
    else DeleteAttribute(CopyChref, "alignment");

    CopyChref.Money            = PastChref.Money;

    CopyChref.chr_ai.hp         = makeint(PastChref.chr_ai.hp);
    CopyChref.chr.chr_ai.hp_max = makeint(PastChref.chr_ai.hp_max);

    LAi_SetHP(CopyChref, makeint(PastChref.chr_ai.hp_max), makeint(PastChref.chr_ai.hp_max));
	LAi_SetCurHPMax(CopyChref);
	
	//копируем структуру quest от оригинального кэпа, очень нужно по квестам :)
	if (CheckAttribute(PastChref, "quest"))
    {
	    aref arToCharQuest, arFromCharQuest;
		makearef(arFromCharQuest, PastChref.quest);
		makearef(arToCharQuest, CopyChref.quest);
		DeleteAttribute(arToCharQuest, "");
		CopyAttributes(arToCharQuest, arFromCharQuest);
	}
	
	if (CheckAttribute(PastChref, "quest.officertype"))
    {
        CopyChref.quest.officertype     =   PastChref.quest.officertype;
    }
    else
    {
        DeleteAttribute(CopyChref, "quest.officertype");
    }

    if (CheckAttribute(PastChref, "Payment"))
    {
        CopyChref.Payment     =   PastChref.Payment; // платить ЗП
    }
    else
    {
        DeleteAttribute(CopyChref, "Payment");
    }
    if (CheckAttribute(PastChref, "HoldEquip"))
    {
        CopyChref.HoldEquip   =   PastChref.HoldEquip; // не отдавать саблю и пистоль
    }
	else
    {
        DeleteAttribute(CopyChref, "HoldEquip");
    }
    if (CheckAttribute(PastChref, "SaveItemsForDead"))
    {
        CopyChref.SaveItemsForDead   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "SaveItemsForDead");
    }
    if (CheckAttribute(PastChref, "DontClearDead"))
    {
        CopyChref.DontClearDead   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "DontClearDead");
    }
    if (CheckAttribute(PastChref, "OfficerWantToGo.DontGo"))
    {
        CopyChref.OfficerWantToGo.DontGo   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "OfficerWantToGo.DontGo");
    }
    // skill
    DeleteAttribute(CopyChref, "skill");
    CopyChref.skill = "";

    makearef(arToChar, CopyChref.skill);
    makearef(arFromChar, PastChref.skill);

    CopyAttributes(arToChar,arFromChar);

    // SPECIAL
    DeleteAttribute(CopyChref, "SPECIAL");
    CopyChref.SPECIAL = "";

    makearef(arToChar, CopyChref.SPECIAL);
    makearef(arFromChar, PastChref.SPECIAL);

    CopyAttributes(arToChar,arFromChar);

    // Statistic
    DeleteAttribute(CopyChref, "Statistic");
    CopyChref.Statistic = "";

    makearef(arToChar, CopyChref.Statistic);
    makearef(arFromChar, PastChref.Statistic);

    CopyAttributes(arToChar,arFromChar);

    // perks
    DeleteAttribute(CopyChref, "perks");
    CopyChref.perks = "";

    makearef(arToChar, CopyChref.perks);
    makearef(arFromChar, PastChref.perks);

    CopyAttributes(arToChar,arFromChar);
    // items
    DeleteAttribute(CopyChref, "Items");
    CopyChref.Items = "";

    makearef(arToChar, CopyChref.Items);
    makearef(arFromChar, PastChref.Items);

    CopyAttributes(arToChar,arFromChar);
	
	// equipped items
	DeleteAttribute(CopyChref, "equip_item");
	CopyChref.equip_item = "";
	makearef(arToChar, CopyChref.equip_item);
    makearef(arFromChar, PastChref.equip_item);

    CopyAttributes(arToChar,arFromChar);
	

    if (CheckAttribute(PastChref, "equip.blade"))
    {
		CopyChref.equip.blade =   PastChref.equip.blade;
	}
	if (CheckAttribute(PastChref, "equip.gun"))
    {
		CopyChref.equip.gun   =   PastChref.equip.gun;
	}
	// health
	if (CheckAttribute(PastChref, "Health.TotalDamg"))
    {
		CopyChref.Health.TotalDamg =   PastChref.Health.TotalDamg;
	}
	else
	{
        CopyChref.Health.TotalDamg = 0;
	}
	
	if (CheckAttribute(PastChref, "PerkValue.EnergyPlus"))
	{
		CopyChref.PerkValue.EnergyPlus =   PastChref.PerkValue.EnergyPlus;
	}

	// ugeen --> нужно для генерации различных ситуации в каюте абордированного кэпа
	if (CheckAttribute(PastChref,"Situation")) // если в каюте кэпа возникла ситуация 
	{
		CopyChref.Situation = PastChref.Situation;
		CopyChref.Situation.type = PastChref.Situation.type;
	}
	
	if (CheckAttribute(PastChref,"EncType"))
	{
		CopyChref.EncType = PastChref.EncType;
	}
	
	if (CheckAttribute(PastChref,"RealEncounterType"))
	{
		CopyChref.RealEncounterType = PastChref.RealEncounterType;
	}

	if (CheckAttribute(PastChref,"Ship"))
	{
		makearef(arToChar, CopyChref.Back.Ship);
		makearef(arFromChar, PastChref.Ship);
		CopyAttributes(arToChar, arFromChar);		
	}	
	// <-- ugeen
	
	if (_dialogCopy && CheckAttribute(PastChref, "Dialog.Filename"))
	{
	    CopyChref.Dialog.Filename    = PastChref.Dialog.Filename;
	    CopyChref.Dialog.CurrentNode = PastChref.Dialog.CurrentNode;
	    if (CheckAttribute(PastChref, "greeting")) CopyChref.greeting = PastChref.greeting; //eddy.нет логам!
		else
		{
			DeleteAttribute(CopyChref, "greeting");
		}
	}
	SetEnergyToCharacter(CopyChref);
	//SetNewModelToChar(CopyChref);  // чтоб сабли были правильные
}

int GetCharacterLoyality(ref chr)
{
    if (CheckAttribute(chr, "loyality"))
    {
        if (sti(chr.loyality) > MAX_LOYALITY)
        {
            chr.loyality = MAX_LOYALITY;
        }
        if (sti(chr.loyality) < 0)
        {
            chr.loyality = 0;
        }
        return sti(chr.loyality);
    }
    else
    {
        return  0; // для пленных и гг
    }
}

void CCS_SetNewMainCharacter(ref ch, int num)
{
	if(num < 1) num = 1;
	switch (num)
	{
/*		case 1: //Готфри де Легенд
			ch.FaceId 				= 477;
			ch.HeroModel 			= "Gotfri_8,Gotfri_2,Gotfri_3,Gotfri_4,Gotfri_5,protocusto,Gotfri_6,Gotfri_7,Gotfri_8";
			ch.name 				= "Готфри";
			ch.lastname				= "де Легенд";
			ch.nameGen				= "Готфри";
			ch.lastnameGen			= "де Легенда";
			ch.nameDat				= "Готфри";
			ch.lastnameDat			= "де Легенду";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_1";
			ch.nation				= FRANCE;
			ch.BaseNation			= FRANCE;
			ch.info					= "Безымянный герой, прошлой эпохи, во временном провале появился здесь, на Карибах. " + 
									  "Здесь ему предстоит обрести себя, открыть новые черты характера, столкнуться с ложью, хитростью и коварством, найти свою любовь, познать непознанное и преодолеть все препятствия на пути к поставленной цели. " + NewStr() +
                                      "О личном жизненном опыте безымянного героя нам свидетельствуют его лёгкое отношение к морали и обществу. Он знает цену людским порокам, не ведает горечи поражений " + 
									  "совершенно не кичится ни титулом, ни привилегиями. Сознавая малое соответствие полученного в детстве домашнего образования существующим реалиям, безымянный герой брал индивидуальные уроки. " + NewStr() +
									  "Наиболее увлекательными и полезными для себя занятиями он находил: ";
/*									  
		break;
		case 2: // Диего  де Монтойя
			return;			
/*			
			ch.FaceId 				= 203;
			ch.HeroModel 			= "Diego_1,Diego_1,Diego_1,Diego_1,Diego_1,protocusto,Diego_6";
			ch.name 				= "Диего";
			ch.lastname				= "де Монтойя";
			ch.nameGen				= "Диего";
			ch.lastnameGen			= "де Монтойя";
			ch.nameDat				= "Диего";
			ch.lastnameDat			= "де Монтойя";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_1";
			ch.nation				= SPAIN;
			ch.BaseNation			= SPAIN;
			ch.info					= "Здесь будет описание Главного Героя Диего де Монтойя.";									
*/			
		break;		
		case 3: // Паттерсон
			return;
/*			
			ch.FaceId 				= 202;
			ch.HeroModel 			= "Willy_1,Willy_1,Willy_1,Willy_1,Willy_1,protocusto,Willy_6";
			ch.name 				= "Вильям";
			ch.lastname				= "Патерсон";
			ch.nameGen				= "Вильяма";
			ch.lastnameGen			= "Патерсона";
			ch.nameDat				= "Вильяму";
			ch.lastnameDat			= "Патерсону";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_3";
			ch.nation				= ENGLAND;
			ch.BaseNation			= ENGLAND;
			ch.info 				= "Благородные намерения этого молодого дворянина о честной торговле на благо нации и собственного кошелька разбились о реалии жестокой действительности." + 
			                          " Пришлось обзаводиться каперским патентом и прокладывать себе путь к благосостоянию пушками и клинком, забыв о чванливых манерах Старого Света...";
*/									  
		break;
	}	
	
	ch.model = GetSubStringByNum(ch.HeroModel, 0);
	ch.cirassIDX = 0;
	
	if(ch.sex == "woman")
	{
		ch.model.height = 1.75;
	}
    else
    {
		ch.model.height = 1.8;
	}
}

int CCS_GetNewMainCharacterFace(ref ch)
{
    return sti(ch.FaceId);
}

// boal 091004 много героев  -->
// boal 23.01.2004 выбор персонажа-->
void setNewMainCharacter(ref ch, int num)
{
	string heroModel, heroFaceId;
	int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");

    totalInfo = LanguageConvertString(idLngFile, "heroFace_" + num);
    heroFaceId  = sti(totalInfo);
    ch.FaceId   = heroFaceId;

    totalInfo = LanguageConvertString(idLngFile, "heroModel_" + num);
    ch.HeroModel = totalInfo;
    ch.model	= GetSubStringByNum(ch.HeroModel, 0);
    ch.headModel = "h_" + ch.model;

    totalInfo = LanguageConvertString(idLngFile, "heroName_" + num);
    ch.name 	=  totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "heroLastname_" + num);
    ch.lastname = totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "sex_" + num);
    ch.sex = totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "animation_" + num);
    ch.model.animation = totalInfo;

    if(ch.sex == "woman")
	{
		ch.model.height = 1.75;
	}
    else
    {
		ch.model.height = 1.8;
	}

    LanguageCloseFile(idLngFile);
    // для НПС
    ch.HeroParam.HeroType = GetNewMainCharacterType(num);
    ch.nation             = GetNewMainCharacterNation(num);

}

void initNewMainCharacter_plus() // новая игра плюс
{
	ref ch = GetMainCharacter();
	string sTemp;
	int    iTmp, i;

    //setNewMainCharacter(ch, startHeroType);
    // контроль версий -->
    ch.VersionNumber              = GetVerNum();
    ch.VersionNumberCompatibility = VERSION_NUM;
    // контроль версий <--
    ch.nation     = NullCharacter.HeroParam.nation;
    ch.BaseNation = NullCharacter.HeroParam.nation;
    
    //MOD_EXP_RATE =  10;  задаем в начале игры (выбор, от 5 до 15, 10 - середина по умолчанию)
    //MOD_EXP_RATE =  MOD_EXP_RATE + (MOD_SKILL_ENEMY_RATE)*6; // разные уровни для всех
    MOD_EXP_RATE =  makeint(MOD_EXP_RATE + MOD_SKILL_ENEMY_RATE * MOD_EXP_RATE / 0.2); // разные уровни для всех
    if (MOD_EXP_RATE < 10) MOD_EXP_RATE = 10; // иначе будет развал целостности данных, порог релиховой версии бля всех сложностей.
    
	// куда плывем
	if (sti(ch.nation) != PIRATE)
	{
		ch.HeroParam.ToCityId     = FindAlliedColonyForNation(sti(ch.nation), true);
	}
	else
	{
		ch.HeroParam.ToCityId = FindAlliedColonyForNationExceptColony("Pirates"); //Бермуды не берем, туда еще добираться надо
	}

	// откуда плывем
    ch.HeroParam.FromCityId  = Colonies[FindNonEnemyColonyForAdventure(sti(ch.nation), ch.HeroParam.ToCityId, true)].id;

	// где появимся
	if (sti(ch.nation) != PIRATE)
	{
	                        ch.HeroParam.Location = ch.HeroParam.ToCityId = "Shore89";
		ch.HeroParam.Group    = "reload";
		ch.HeroParam.Locator  = "reload1";
	}
	else
	{
	                        ch.HeroParam.Location = ch.HeroParam.ToCityId = "Shore89";
		ch.HeroParam.Group    = "reload";
		ch.HeroParam.Locator  = "reload1";
	}

	setCharacterShipLocation(ch, ch.HeroParam.Location);
    setWDMPointXZ(ch.HeroParam.Location);  // коорд на карте
    
	// а надо ли нам это ?
	SetTimerCondition("Move_Govenour", 0, 0, 25 + rand(10), true); // to_do перенести в один метод инициации
	
	//Запускаем проверку на падение здоровья раз в 5 дней
    SetTimerCondition("CheckMaxHealthQuest", 0, 0, 5, true);
    
    SetTimerCondition("Nation_Legend", 0, 0, 25 + rand(10), true);

	// Jason: новая усадка генерал-губернаторов. На постоянке - Пуанси, Виндзор, Фокс, де Кордова
	SetGovenoursToResidence();

	ReloadProgressUpdate();

 	SetNationRelations();
 	// от кого драпаем
	ch.HeroParam.EnemyNation  = FindEnemyNation2Nation(sti(ch.nation));
	
    // boal вешаем прерывание на охотников навечно (для моря и земли) -->
    SetTimerCondition("SeaHunterCheck", 0, 0, 6, true);
    SaveCurrentQuestDateParam("Land_HunterTimerEng");
    SaveCurrentQuestDateParam("Land_HunterTimerFra");
    SaveCurrentQuestDateParam("Land_HunterTimerSpa");
    SaveCurrentQuestDateParam("Land_HunterTimerHol");
    // boal вешаем прерывание на охотников навечно (для моря и земли) <--
    LAi_SetHP(ch, LAI_DEFAULT_HP, LAI_DEFAULT_HP);

    ch.HeroParam.HeroType = NullCharacter.HeroParam.HeroType;

	SetSPECIAL(ch, 4,4,4,4,4,4,4); //фикс для любителей стирать тип ГГ в файле - была дыра
	switch (ch.HeroParam.HeroType)
	{
        case "Master":
    	    SetSPECIAL(ch, 10,5,10,6,7,6,6); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break; 

        case "Merchant":
    	    SetSPECIAL(ch, 8,6,5,9,9,3,10); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

	    case "Corsair":
         	SetSPECIAL(ch, 9,8,9,3,6,10,5); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
         	// НЗГ -->
         	i = 0;
         	while (i < 2)// две награды
         	{
	         	iTmp  = rand(MAX_NATIONS-1);
	         	sTemp = "reputation." + NationShortName(iTmp) + "hunter";
	         	if (iTmp != PIRATE && iTmp != sti(ch.nation) && sti(ch.(sTemp)) == -5)
	         	{
					/*if (MOD_BETTATESTMODE == "On")
					{
						ch.(sTemp) = (7 + rand(8));
					}
					else
					{ */
						ch.(sTemp) = (1 + rand(5));
					//}
		    	    i++;
	    	    }
    	    }
         	// НЗГ <--
	    break;

	    case "Adventurer":
    	    SetSPECIAL(ch, 8,10,5,6,8,5,8); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

		case "Inquisitor":
    	    SetSPECIAL(ch, 8,6,7,10,7,6,6); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

	    case "SecretAgent":
    	    SetSPECIAL(ch, 7,7,6,10,6,7,7); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;  

	}
	ch.skill.freeskill   = 0;
	ch.Skill.FreeSPECIAL = 0;
	sGlobalTemp   = "Flag" + NationShortName(sti(ch.nation));
	SetCharacterPerk(ch, sGlobalTemp); // перк флага нации
	SetCharacterPerk(ch, "FlagPir");
	SetCharacterPerk(ch, "Energaiser"); // скрытый перк дает 1.5 к приросту энергии, дается ГГ и боссам уровней
	SetCharacterPerk(ch, "Rush");
	// начальные скилы задать
    //InitStartParam(ch); // Jason - fix
	LAi_SetHP(ch, GetCharacterBaseHPValue(ch), GetCharacterBaseHPValue(ch));
    SetEnergyToCharacter(ch);
    initMainCharacterItem();
	
	ReloadProgressUpdate();	
    DeleteAttribute(ch, "Ship");
    
    	if (sti(ch.nation) != PIRATE)
	{
		pchar.Ship.Type = GenerateShipExt((SHIP_GUNBOAT + rand(2) - 1), 0, pchar);
	SetBaseShipData(pchar);
pchar.Ship.Name = RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple("Быстрый вепрь", "Тигр"), "Неизбежность"), "Антилопа"), "Экстра"), "Молния"), "Дельфин"), "Загадочный"), "Ужасный");
	SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
	}
	else
	{
pchar.Ship.Type = GenerateShipExt(SHIP_PLOT, 0, pchar);
SetBaseShipData(pchar);
pchar.Ship.Name = RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple("Смерч", "Шторм"), "Кракен"), "Морж"), "Ураган"), "Плутон"), "Посейдон"), "Нептун"), "Возмездие");
SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
SetCharacterGoods(pchar, GOOD_SLAVES, 5);
	}
	// коцаем корабль
	pchar.ship.SP = sti(pchar.ship.SP) - 10;
	pchar.ship.HP = sti(pchar.ship.HP) - makeint(sti(pchar.ship.HP)/2);

	//Tutorial - НАЧАЛО ИГРЫ
    if(startHeroType == 228) //21/07/07 homo для Монбара даем другое начало
    {
	Environment.date.month = 4;
                  SetCurrentTime(5, 6);
    	pchar.quest.Tut_start.win_condition.l1          = "location";
    	pchar.quest.Tut_start.win_condition.l1.location = "Dungeon";
    	pchar.quest.Tut_start.function                  = "Monbar_StartGame";
                  DoQuestCheckDelay("Monbar_StartGameVideo", 1.0);
    }
    else
    {
	Environment.date.month = 4;
                  SetCurrentTime(5, 6);
    	pchar.quest.Tut_start.win_condition.l1          = "location";
    	pchar.quest.Tut_start.win_condition.l1.location = "Ship_deck_Low";
    	pchar.quest.Tut_start.function                  = "Tut_StartGame";
ResetSound();
    Pchar.questTemp.GothicMonbar = false;
    }

	// Dolphin Дезертиры
	SaveCurrentQuestDateParam("MainChrDesertirs_timer");	// Таймер обработки дезертиров с корабля ГГ
	// Warship Для разных квестов
	// Важно: функция MaryCelesteInit() должна быть тут, а не в initStartState2Character()
	// т.к. в ней идет выборка колоний, которые в функции initStartState2Character() еще не инитились
	OtherQuestCharactersInit(); // Инициализация прочих квестов
	MaryCelesteInit(); // Warship 07.07.09 Пасхалка "Мэри Селест"
	// Установим начальный дневной рандом
	ch.DayRandom = Random();
}

void initNewMainCharacter()//инициализация главного героя
{
	ref ch = GetMainCharacter();
	string sTemp;
	int    iTmp, i;

    setNewMainCharacter(ch, startHeroType);
    // контроль версий -->
    ch.VersionNumber              = GetVerNum();
    ch.VersionNumberCompatibility = VERSION_NUM;
    // контроль версий <--
    ch.nation     = NullCharacter.HeroParam.nation;
    ch.BaseNation = NullCharacter.HeroParam.nation;
    
    //MOD_EXP_RATE =  10;  задаем в начале игры (выбор, от 5 до 15, 10 - середина по умолчанию)
    //MOD_EXP_RATE =  MOD_EXP_RATE + (MOD_SKILL_ENEMY_RATE)*6; // разные уровни для всех
    MOD_EXP_RATE =  makeint(MOD_EXP_RATE + MOD_SKILL_ENEMY_RATE * MOD_EXP_RATE / 0.2); // разные уровни для всех
    if (MOD_EXP_RATE < 10) MOD_EXP_RATE = 10; // иначе будет развал целостности данных, порог релиховой версии бля всех сложностей.
    
	// куда плывем
	if (sti(ch.nation) != PIRATE)
	{
		ch.HeroParam.ToCityId     = FindAlliedColonyForNation(sti(ch.nation), true);
	}
	else
	{
		ch.HeroParam.ToCityId = FindAlliedColonyForNationExceptColony("Pirates"); //Бермуды не берем, туда еще добираться надо
	}

	// откуда плывем
    ch.HeroParam.FromCityId  = Colonies[FindNonEnemyColonyForAdventure(sti(ch.nation), ch.HeroParam.ToCityId, true)].id;

	// где появимся
	if (sti(ch.nation) != PIRATE)
	{
	                        ch.HeroParam.Location = ch.HeroParam.ToCityId = "Shore89";
		ch.HeroParam.Group    = "reload";
		ch.HeroParam.Locator  = "reload1";
	}
	else
	{
	                        ch.HeroParam.Location = ch.HeroParam.ToCityId = "Shore89";
		ch.HeroParam.Group    = "reload";
		ch.HeroParam.Locator  = "reload1";
	}

	setCharacterShipLocation(ch, ch.HeroParam.Location);
    setWDMPointXZ(ch.HeroParam.Location);  // коорд на карте
    
	// а надо ли нам это ?
	SetTimerCondition("Move_Govenour", 0, 0, 25 + rand(10), true); // to_do перенести в один метод инициации
	
	//Запускаем проверку на падение здоровья раз в 5 дней
    SetTimerCondition("CheckMaxHealthQuest", 0, 0, 5, true);
    
    SetTimerCondition("Nation_Legend", 0, 0, 25 + rand(10), true);

	// Jason: новая усадка генерал-губернаторов. На постоянке - Пуанси, Виндзор, Фокс, де Кордова
	SetGovenoursToResidence();

	ReloadProgressUpdate();

 	SetNationRelations();
 	// от кого драпаем
	ch.HeroParam.EnemyNation  = FindEnemyNation2Nation(sti(ch.nation));
	
    // boal вешаем прерывание на охотников навечно (для моря и земли) -->
    SetTimerCondition("SeaHunterCheck", 0, 0, 6, true);
    SaveCurrentQuestDateParam("Land_HunterTimerEng");
    SaveCurrentQuestDateParam("Land_HunterTimerFra");
    SaveCurrentQuestDateParam("Land_HunterTimerSpa");
    SaveCurrentQuestDateParam("Land_HunterTimerHol");
    // boal вешаем прерывание на охотников навечно (для моря и земли) <--
    LAi_SetHP(ch, LAI_DEFAULT_HP, LAI_DEFAULT_HP);

    ch.HeroParam.HeroType = NullCharacter.HeroParam.HeroType;

	SetSPECIAL(ch, 4,4,4,4,4,4,4); //фикс для любителей стирать тип ГГ в файле - была дыра
	switch (ch.HeroParam.HeroType)
	{
        case "Master":
    	    SetSPECIAL(ch, 10,5,10,6,7,6,6); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break; 

        case "Merchant":
    	    SetSPECIAL(ch, 8,6,5,9,9,3,10); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

	    case "Corsair":
         	SetSPECIAL(ch, 9,8,9,3,6,10,5); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
         	// НЗГ -->
         	i = 0;
         	while (i < 2)// две награды
         	{
	         	iTmp  = rand(MAX_NATIONS-1);
	         	sTemp = "reputation." + NationShortName(iTmp) + "hunter";
	         	if (iTmp != PIRATE && iTmp != sti(ch.nation) && sti(ch.(sTemp)) == -5)
	         	{
					/*if (MOD_BETTATESTMODE == "On")
					{
						ch.(sTemp) = (7 + rand(8));
					}
					else
					{ */
						ch.(sTemp) = (1 + rand(5));
					//}
		    	    i++;
	    	    }
    	    }
         	// НЗГ <--
	    break;

	    case "Adventurer":
    	    SetSPECIAL(ch, 8,10,5,6,8,5,8); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

		case "Inquisitor":
    	    SetSPECIAL(ch, 8,6,7,10,7,6,6); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;

	    case "SecretAgent":
    	    SetSPECIAL(ch, 7,7,6,10,6,7,7); // SPECIAL (Сила, Восприятие, Выносливость, Лидерство, Обучаемость, Реакция, Удача)
	    break;  

	}
	ch.skill.freeskill   = 0;
	ch.Skill.FreeSPECIAL = 0;
	sGlobalTemp   = "Flag" + NationShortName(sti(ch.nation));
	SetCharacterPerk(ch, sGlobalTemp); // перк флага нации
	SetCharacterPerk(ch, "FlagPir");
	SetCharacterPerk(ch, "Energaiser"); // скрытый перк дает 1.5 к приросту энергии, дается ГГ и боссам уровней
	SetCharacterPerk(ch, "Rush");
	// начальные скилы задать
    //InitStartParam(ch); // Jason - fix
	LAi_SetHP(ch, GetCharacterBaseHPValue(ch), GetCharacterBaseHPValue(ch));
    SetEnergyToCharacter(ch);
    initMainCharacterItem();
	
	ReloadProgressUpdate();	
    DeleteAttribute(ch, "Ship");
    
    	if (sti(ch.nation) != PIRATE)
	{
		pchar.Ship.Type = GenerateShipExt((SHIP_GUNBOAT + rand(2) - 1), 0, pchar);
	SetBaseShipData(pchar);
pchar.Ship.Name = RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple("Быстрый вепрь", "Тигр"), "Неизбежность"), "Антилопа"), "Экстра"), "Молния"), "Дельфин"), "Загадочный"), "Ужасный");
	SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
	}
	else
	{
pchar.Ship.Type = GenerateShipExt(SHIP_PLOT, 0, pchar);
SetBaseShipData(pchar);
pchar.Ship.Name = RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple(RandPhraseSimple("Смерч", "Шторм"), "Кракен"), "Морж"), "Ураган"), "Плутон"), "Посейдон"), "Нептун"), "Возмездие");
SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
SetCharacterGoods(pchar, GOOD_SLAVES, 5);
	}
	// коцаем корабль
	pchar.ship.SP = sti(pchar.ship.SP) - 10;
	pchar.ship.HP = sti(pchar.ship.HP) - makeint(sti(pchar.ship.HP)/2);

	//Tutorial - НАЧАЛО ИГРЫ
    if(startHeroType == 228) //21/07/07 homo для Монбара даем другое начало
    {
	Environment.date.month = 4;
                  SetCurrentTime(5, 6);
    	pchar.quest.Tut_start.win_condition.l1          = "location";
    	pchar.quest.Tut_start.win_condition.l1.location = "Dungeon";
    	pchar.quest.Tut_start.function                  = "Monbar_StartGame";
                  DoQuestCheckDelay("Monbar_StartGameVideo", 1.0);
    }
    else
    {
	Environment.date.month = 4;
                  SetCurrentTime(5, 6);
    	pchar.quest.Tut_start.win_condition.l1          = "location";
    	pchar.quest.Tut_start.win_condition.l1.location = "Ship_deck_Low";
    	pchar.quest.Tut_start.function                  = "Tut_StartGame";
ResetSound();
    Pchar.questTemp.GothicMonbar = false;
    }

	// Dolphin Дезертиры
	SaveCurrentQuestDateParam("MainChrDesertirs_timer");	// Таймер обработки дезертиров с корабля ГГ
	// Warship Для разных квестов
	// Важно: функция MaryCelesteInit() должна быть тут, а не в initStartState2Character()
	// т.к. в ней идет выборка колоний, которые в функции initStartState2Character() еще не инитились
	OtherQuestCharactersInit(); // Инициализация прочих квестов
	MaryCelesteInit(); // Warship 07.07.09 Пасхалка "Мэри Селест"
	// Установим начальный дневной рандом
	ch.DayRandom = Random();
}

void initMainCharacterItem()
{
    ref ch = GetMainCharacter();
	String itemID;
	
	switch (ch.HeroParam.HeroType)
	{
        		case "Master":
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
			SetCharacterPerk(ch, "HT4");
			GiveItem2Character(ch, "Map_part1");
			pchar.CSM.NoCannonsBoom = true;
			SetSelfSkill(ch, 5, 5, 5, 15, 20);
			SetShipSkill(ch, 10, 3, 15, 12, 3, 3, 3, 3, 12);
			switch (sti(ch.nation))
			{
			case ENGLAND:
			SetCharacterPerk(ch, "BasicBattleState");
			SetCharacterPerk(ch, "AdvancedBattleState");
			SetCharacterPerk(ch, "ShipDefenseProfessional");
			itemID = GetGeneratedItem("topor_04");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "Spyglass3", 1);			
			EquipCharacterbyItem(ch, "Spyglass3");
			TakenItems(ch, "jewelry3", 1);
			TakenItems(ch, "jewelry4", 1);
			TakenItems(ch, "jewelry9", 1);
			pchar.money = 10000/MOD_SKILL_ENEMY_RATE;
			break;

			case FRANCE:
			SetCharacterPerk(ch, "Carpenter");
			SetCharacterPerk(ch, "HardHitter");
			itemID = GetGeneratedItem("topor_02");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "Spyglass2", 1);
			TakenItems(ch, "jewelry4", 1);
			TakenItems(ch, "jewelry9", 1);		
			EquipCharacterbyItem(ch, "Spyglass2");
			pchar.money = 6000/MOD_SKILL_ENEMY_RATE;
			break;

			case HOLLAND:
			SetCharacterPerk(ch, "Carpenter");
			SetCharacterPerk(ch, "LightRepair");
			itemID = GetGeneratedItem("topor_03");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "Spyglass2", 1);			
			EquipCharacterbyItem(ch, "Spyglass2");
			TakenItems(ch, "jewelry4", 1);
			TakenItems(ch, "jewelry14", 1);		
			pchar.money = 8000/MOD_SKILL_ENEMY_RATE;
			break;

			case PIRATE:
			SetCharacterPerk(ch, "Carpenter");
			itemID = GetGeneratedItem("topor_05");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "Spyglass1", 1);	
			TakenItems(ch, "jewelry9", 1);			
			EquipCharacterbyItem(ch, "Spyglass1");
			pchar.money = 2000/MOD_SKILL_ENEMY_RATE;
			break;

			case SPAIN:
			SetCharacterPerk(ch, "BasicBattleState");
			itemID = GetGeneratedItem("topor_07");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "Spyglass1", 1);	
			TakenItems(ch, "jewelry14", 1);			
			EquipCharacterbyItem(ch, "Spyglass1");
			pchar.money = 4000/MOD_SKILL_ENEMY_RATE;
			break;
			}
	    break;

      		case "Merchant":
			SetCharacterPerk(ch, "HT2");
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
			SetSelfSkill(ch, 4, 15, 4, 5, 8);
			SetShipSkill(ch, 15, 15, 3, 3, 3, 3, 3, 3, 8);
			GiveItem2Character(ch, "Map_part1");
			pchar.CSM.FreeSmuggling = true;
			switch (sti(ch.nation))
			{
			case ENGLAND:
			SetCharacterPerk(ch, "BasicCommerce");
			SetCharacterPerk(ch, "AdvancedCommerce");
			TakenItems(ch, "map_bad", 1);
			itemID = GetGeneratedItem("blade_05");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol1", 1);
			EquipCharacterbyItem(ch, "pistol1");	
			LAi_SetCharacterUseBullet(ch, "bullet");
			AddItems(ch, "bullet", 10);
			AddItems(ch, "gunpowder", 10);
			TakenItems(ch, "jewelry17", 1);
			TakenItems(ch, "jewelry21", 1);
			ch.money = 20000/MOD_SKILL_ENEMY_RATE;
			break;

			case FRANCE:
			SetCharacterPerk(ch, "BasicCommerce");
			SetCharacterPerk(ch, "AdvancedCommerce");
			itemID = GetGeneratedItem("blade_11");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			TakenItems(ch, "map_bad", 1);
			AddItems(ch, "pistol_02", 1);
			EquipCharacterbyItem(ch, "pistol_02");	
			LAi_SetCharacterUseBullet(ch, "bullet");
			AddItems(ch, "bullet", 15);
			AddItems(ch, "gunpowder", 15);
			TakenItems(ch, "jewelry17", 1);
			TakenItems(ch, "jewelry23", 1);
			ch.money = 15000/MOD_SKILL_ENEMY_RATE;
			break;

			case HOLLAND:
			SetCharacterPerk(ch, "BasicCommerce");
			SetCharacterPerk(ch, "AdvancedCommerce");
			SetCharacterPerk(ch, "ProfessionalCommerce");
			TakenItems(ch, "map_normal", 1);
			itemID = GetGeneratedItem("newblade24");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol11", 1);
			EquipCharacterbyItem(ch, "pistol11");	
			LAi_SetCharacterUseBullet(ch, "bullet");
			AddItems(ch, "bullet", 20);
			AddItems(ch, "gunpowder", 20);
			TakenItems(ch, "jewelry17", 1);
			TakenItems(ch, "jewelry21", 1);
			TakenItems(ch, "jewelry23", 1);
			ch.money = 25000/MOD_SKILL_ENEMY_RATE;
			break;

			case PIRATE:
			SetCharacterPerk(ch, "BasicCommerce");
			itemID = GetGeneratedItem("newblade3");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol_01", 1);
			EquipCharacterbyItem(ch, "pistol_01");	
			LAi_SetCharacterUseBullet(ch, "bullet");
			AddItems(ch, "bullet", 10);
			AddItems(ch, "gunpowder", 10);
			TakenItems(ch, "jewelry21", 1);
			ch.money = 5000/MOD_SKILL_ENEMY_RATE;
			break;

			case SPAIN:
			SetCharacterPerk(ch, "BasicCommerce");
			itemID = GetGeneratedItem("newblade4");
            	GiveItem2Character(ch, itemID);
            	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol_01", 1);
			EquipCharacterbyItem(ch, "pistol_01");	
			LAi_SetCharacterUseBullet(ch, "bullet");
			AddItems(ch, "bullet", 5);
			AddItems(ch, "gunpowder", 5);
			TakenItems(ch, "jewelry17", 1);
			ch.money = 10000/MOD_SKILL_ENEMY_RATE;
			break;
			}
	    break;

	    	case "Corsair":
		TakenItems(ch, "jewelry42", 1);
		TakenItems(ch, "jewelry43", 2);
		TakenItems(ch, "jewelry46", 3);
		GiveItem2Character(ch, "Map_part1");
		SetCharacterPerk(ch, "HT3");
		SetCharacterPerk(ch, "SeaWolf");
		SetSelfSkill(ch, 3, 5, 15, 5, 7);
		SetShipSkill(ch, 5, 3, 3, 8, 3, 10, 8, 3, 3);
			switch (sti(ch.nation))
			{
			case ENGLAND:
			SetCharacterPerk(ch, "FastReload");
			SetCharacterPerk(ch, "LongRangeShoot");
			itemID = GetGeneratedItem("newblade19");	           			GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol_03", 1);
			EquipCharacterbyItem(ch, "pistol_03");	
			AddItems(ch, "grapeshot", 10);
			AddItems(ch, "gunpowder", 10);
			TakenItems(ch, "jewelry15", 1);
			TakenItems(ch, "jewelry16", 1);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			ch.money = 4000/MOD_SKILL_ENEMY_RATE;
			break;

			case FRANCE:
			SetCharacterPerk(ch, "CrewDamageUp");
			SetCharacterPerk(ch, "HullDamageUp");
			SetCharacterPerk(ch, "SailsDamageUp");
			itemID = GetGeneratedItem("newblade12");	           			GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol_08", 1);
			EquipCharacterbyItem(ch, "pistol_08");	
			AddItems(ch, "grapeshot", 10);
			AddItems(ch, "gunpowder", 10);
			TakenItems(ch, "jewelry22", 1);
			TakenItems(ch, "jewelry15", 1);
			TakenItems(ch, "jewelry16", 1);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			ch.money = 5000/MOD_SKILL_ENEMY_RATE;
			break;

			case HOLLAND:
			SetCharacterPerk(ch, "Gunman");
			SetCharacterPerk(ch, "GunProfessional");
			itemID = GetGeneratedItem("newblade9");	           			GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol_03", 1);
			EquipCharacterbyItem(ch, "pistol_03");	
			AddItems(ch, "grapeshot", 15);
			AddItems(ch, "gunpowder", 15);
			TakenItems(ch, "jewelry22", 1);
			TakenItems(ch, "jewelry15", 1);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			ch.money = 3000/MOD_SKILL_ENEMY_RATE;
			break;

			case PIRATE:
			SetCharacterPerk(ch, "CriticalHit");
			itemID = GetGeneratedItem("newblade23");	           			GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol3", 1);
			EquipCharacterbyItem(ch, "pistol3");	
			AddItems(ch, "grapeshot", 20);
			AddItems(ch, "gunpowder", 20);
			TakenItems(ch, "jewelry22", 1);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			ch.money = 1000/MOD_SKILL_ENEMY_RATE;
			break;

			case SPAIN:
			SetCharacterPerk(ch, "Medic");
			itemID = GetGeneratedItem("blade_07");	           			GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			AddItems(ch, "pistol3", 1);
			EquipCharacterbyItem(ch, "pistol3");	
			AddItems(ch, "grapeshot", 15);
			AddItems(ch, "gunpowder", 15);
			TakenItems(ch, "jewelry15", 1);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			ch.money = 2000/MOD_SKILL_ENEMY_RATE;
			break;
			}
	    break;

	    case "Adventurer":
           	GiveItem2Character(ch, itemID);
           	EquipCharacterbyItem(ch, itemID);
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
			TakenItems(ch, "map_bad", 1);
			GiveItem2Character(ch, "Map_part1");	
			SetCharacterPerk(ch, "HT1");	
			SetSelfSkill(ch, 15, 5, 3, 5, 10);
			SetShipSkill(ch, 12, 5, 6, 3, 3, 3, 3, 3, 15);
			pchar.CSM.TreasureMapTrader = true;	
			switch (sti(ch.nation))
			{
				case ENGLAND:
				SetCharacterPerk(ch, "BasicDefense");
				itemID = GetGeneratedItem("newblade2");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				AddItems(ch, "cirass5", 1);			
				EquipCharacterbyItem(ch, "cirass5");
				TakenItems(ch, "jewelry19", 1);
				ch.money = 2500/MOD_SKILL_ENEMY_RATE;
				break;

				case FRANCE:
				SetCharacterPerk(ch, "Tireless");
				SetCharacterPerk(ch, "EnergyPlus");
				itemID = GetGeneratedItem("blade_08");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				AddItems(ch, "cirass6", 1);			
				EquipCharacterbyItem(ch, "cirass6");
				TakenItems(ch, "jewelry18", 1);
				TakenItems(ch, "jewelry19", 1);
				ch.money = 4000/MOD_SKILL_ENEMY_RATE;
				break;

				case HOLLAND:
				SetCharacterPerk(ch, "SharedExperience");
				itemID = GetGeneratedItem("blade_03");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				AddItems(ch, "cirass5", 1);			
				EquipCharacterbyItem(ch, "cirass5");
				TakenItems(ch, "jewelry20", 1);
				ch.money = 1000/MOD_SKILL_ENEMY_RATE;
				break;

				case PIRATE:
				SetCharacterPerk(ch, "ShipEscape");
				SetCharacterPerk(ch, "IronWill");
				itemID = GetGeneratedItem("blade_09");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				AddItems(ch, "cirass6", 1);			
				EquipCharacterbyItem(ch, "cirass6");
				TakenItems(ch, "jewelry19", 1);
				TakenItems(ch, "jewelry20", 1);
				ch.money = 5500/MOD_SKILL_ENEMY_RATE;
				break;

				case SPAIN:
				SetCharacterPerk(ch, "BasicDefense");
				SetCharacterPerk(ch, "AdvancedDefense");
				SetCharacterPerk(ch, "CriticalHit");
				itemID = GetGeneratedItem("newblade13");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				AddItems(ch, "cirass7", 1);			
				EquipCharacterbyItem(ch, "cirass7");
				TakenItems(ch, "jewelry18", 1);
				TakenItems(ch, "jewelry19", 1);
				TakenItems(ch, "jewelry20", 1);
				ch.money = 7000/MOD_SKILL_ENEMY_RATE;
				break;
			}
	    break;

	    	case "Inquisitor":
		itemID = GetGeneratedItem("blade48");	           			GiveItem2Character(ch, itemID);
           EquipCharacterbyItem(ch, itemID);
		TakenItems(ch, "amulet_7", 1);
		TakenItems(ch, "amulet_3", 1);
		TakenItems(ch, "amulet_2", 1);
		TakenItems(ch, "amulet_6", 1);
		SetCharacterPerk(ch, "HT5");
		GiveItem2Character(ch, "Map_part1");
		pchar.questTemp.ShipCapellan = "true";
		pchar.questTemp.ShipCapellan.id = chr.id;
		pchar.questTemp.ShipCapellan.Yes = "true";
		pchar.questTemp.Inquisitor.AveMaria = "true"; 
		SetCharacterPerk(ch, "IronWill");
		SetSelfSkill(ch, 3, 5, 15, 7, 7);
		SetShipSkill(ch, 15, 15, 3, 3, 3, 5, 3, 3, 8);
		ch.money = 2500/MOD_SKILL_ENEMY_RATE;
			switch (sti(ch.nation))
			{
				case ENGLAND:
				SetCharacterPerk(ch, "Tireless");
				break;

				case FRANCE:
				SetCharacterPerk(ch, "HPPlus");
				break;

				case HOLLAND:
				SetCharacterPerk(ch, "Gunman");
				break;

				case PIRATE:
				SetCharacterPerk(ch, "EnergyPlus");
				break;

				case SPAIN:
				SetCharacterPerk(ch, "CriticalHit");
				break;
			}
	    break;

	    case "SecretAgent":
			SetCharacterPerk(ch, "Trustworthy");
			SetSelfSkill(ch, 5, 5, 5, 15, 20);
			SetShipSkill(ch, 12, 5, 6, 3, 3, 5, 3, 3, 15);
			switch (sti(ch.nation))
			{
				case ENGLAND:
				itemID = GetGeneratedItem("unarmed");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				GiveItem2Character(ch, "Map_part1");
				SetCharacterPerk(ch, "Trustworthy");
				SetCharacterPerk(ch, "FlagEng");
				SetCharacterPerk(ch, "FlagFra");
				SetCharacterPerk(ch, "FlagHol");
				SetCharacterPerk(ch, "FlagSpa");
				TakenItems(ch, "jewelry1", 1);
				TakenItems(ch, "jewelry21", 1);
				break;
				case FRANCE:
				itemID = GetGeneratedItem("unarmed");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				GiveItem2Character(ch, "Map_part1");
				SetCharacterPerk(ch, "Trustworthy");
				SetCharacterPerk(ch, "FlagEng");
				SetCharacterPerk(ch, "FlagFra");
				SetCharacterPerk(ch, "FlagHol");
				SetCharacterPerk(ch, "FlagSpa");
				TakenItems(ch, "jewelry2", 1);
				break;
				case HOLLAND:
				itemID = GetGeneratedItem("unarmed");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				GiveItem2Character(ch, "Map_part1");
				SetCharacterPerk(ch, "Trustworthy");
				SetCharacterPerk(ch, "FlagEng");
				SetCharacterPerk(ch, "FlagFra");
				SetCharacterPerk(ch, "FlagHol");
				SetCharacterPerk(ch, "FlagSpa");
				TakenItems(ch, "jewelry1", 1);
				break;
				case PIRATE:
				itemID = GetGeneratedItem("unarmed");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				GiveItem2Character(ch, "Map_part1");
				SetCharacterPerk(ch, "Trustworthy");
				SetCharacterPerk(ch, "FlagEng");
				SetCharacterPerk(ch, "FlagFra");
				SetCharacterPerk(ch, "FlagHol");
				SetCharacterPerk(ch, "FlagSpa");
				TakenItems(ch, "jewelry2", 1);
				TakenItems(ch, "jewelry21", 1);
				TakenItems(ch, "jewelry1", 1);
				break;
				case SPAIN:
				itemID = GetGeneratedItem("unarmed");
				GiveItem2Character(Pchar, itemID);
				EquipCharacterbyItem(Pchar, itemID);
				GiveItem2Character(ch, "Map_part1");
				SetCharacterPerk(ch, "Trustworthy");
				SetCharacterPerk(ch, "FlagEng");
				SetCharacterPerk(ch, "FlagFra");
				SetCharacterPerk(ch, "FlagHol");
				SetCharacterPerk(ch, "FlagSpa");
				TakenItems(ch, "jewelry2", 1);
				TakenItems(ch, "jewelry21", 1);
				break;
			}
	    break;
	}
}

int GetNewMainCharacterFace()
{
    return sti(GetNewMainCharacterParam("heroFace_" + startHeroType));
}

string GetNewMainCharacterName()
{
    return GetHeroName(startHeroType);
}

string GetMainCharacterNameGen()  // ==> eddy. родительный падеж полного имени ГГ
{
    return GetHeroNameGen(startHeroType);
}

string GetMainCharacterNameDat()  // ==> eddy. дательный падеж полного имени ГГ
{
    return GetHeroNameDat(startHeroType);
}

string GetHeroName(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroName_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastname_" + _n);

    return totalInfo;
}

string GetHeroNameGen(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroNameGen_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastnameGen_" + _n);

    return totalInfo;
}

string GetHeroNameDat(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroNameDat_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastnameDat_" + _n);

    return totalInfo;
}

int GetNewMainCharacterNation(int _startHeroType)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, "heroNation_" + _startHeroType);
    LanguageCloseFile(idLngFile);

    switch(totalInfo)
	{
		case "Англия":
            return ENGLAND;
		break;
		case "Франция":
            return FRANCE;
		break;
		case "Испания":
            return SPAIN;
		break;
		case "Голландия":
			return HOLLAND;
		break;
		case "Береговое братство":
			return PIRATE;
		break;

		case "ENGLAND":
            return ENGLAND;
		break;
		case "FRANCE":
            return FRANCE;
		break;
		case "SPAIN":
            return SPAIN;
		break;
		case "HOLLAND":
			return HOLLAND;
		break;
		case "PIRATE":
			return PIRATE;
		break;
	}
	return PIRATE;
}

string GetNewMainCharacterType(int _startHeroType)
{
    string ret = GetNewMainCharacterParam("heroType_" + _startHeroType);

    switch (ret) // нужно по английски для квестбука
	{
        case "Торговец":
    	    ret = "Merchant";
	    break;

	    case "Мастер":
    	    ret = "Master";
	    break;

	    case "Корсар":
            ret = "Corsair";
	    break;

	    case "Авантюрист":
            ret = "Adventurer";
	    break;

	    case "Инквизитор":
            ret = "Inquisitor";
	    break;

	    case "Тайный агент":
            ret = "SecretAgent";
	    break;
	}

	return ret;
}

string GetNewMainCharacterParam(string _param)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, _param);
    LanguageCloseFile(idLngFile);

    return totalInfo;
}

// вернуть базовую нацию ГГ или патент
int GetBaseHeroNation()
{
	if (isMainCharacterPatented())
	{
	    return sti(Items[sti(pchar.EquipedPatentId)].Nation);
	}
	return sti(pchar.BaseNation);
}