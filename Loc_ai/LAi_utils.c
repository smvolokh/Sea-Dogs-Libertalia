
//��������� ������ �� ���������
bool LAi_CheckCharacter(aref chr, string out)
{
	if(!TestRef(chr))
	{
		Trace("LAi_CheckCharacter -> invalide aref, call from " + out);
		return false;
	}
	if(CheckAttribute(chr, "index") == false)
	{
		Trace(out + " -> invalide character, no field <index>");
		return false;
	}
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		Trace(out + " -> invalide character " + chr.id + ", no field <chr_ai.type>");
		return false;
	}
	if(CheckAttribute(chr, "chr_ai.tmpl") == false)
	{
		Trace(out + " -> invalide character, no field <chr_ai.tmpl>");
		return false;
	}
	return true;
}

//��������� �� �������� � ���������
bool LAi_CharacterCanFrie(aref chr)
{
	if(!CheckAttribute(chr, "chr_ai.chargeprc"))
	{
		chr.chr_ai.chargeprc = "1";
		chr.chr_ai.charge = 0;
		return false;
	}
	//if(stf(chr.chr_ai.chargeprc) == 0) // boal fix can fire any time if have charge
	//{
		if(stf(chr.chr_ai.charge) >= 1.0) return true;
	//}
	return false;
}

//�������� ���������� ������� � ��������� 0..100
float Lai_CharacterGetEnergy(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.energy"))
	{
		return stf(chr.chr_ai.energy);
	}
	return 0.0;
}

//�������� ���������� ������� � ��������� 0..100
void Lai_CharacterChangeEnergy(aref chr, float dlt)
{
	if(CheckAttribute(chr, "chr_ai.energy"))
	{
		float cur = stf(chr.chr_ai.energy);
		cur = cur + dlt;
		if(cur < 0.0) cur = 0.0;
		if(cur > LAi_GetCharacterMaxEnergy(chr)) cur = LAi_GetCharacterMaxEnergy(chr); //boal
		chr.chr_ai.energy = cur;
	}else{
		if(dlt < 0.0) dlt = 0.0;
		if(dlt > LAi_GetCharacterMaxEnergy(chr)) dlt = LAi_GetCharacterMaxEnergy(chr);
		chr.chr_ai.energy = dlt;
	}
}

//����� �� ��������� �������� � �������� �������
bool LAi_LocationCanFight()
{
	if(IsEntity(loadedLocation) != true) return true;
	if(CheckAttribute(loadedLocation, "noFight") != true)  return true;
	if(sti(loadedLocation.noFight) != false) return false;
	return true;
}

//���� ���-�� ��������� � �������� ������ <-- ugeen 
int LAi_GetLocatorNum(string group)
{
	if(IsEntity(loadedLocation) != true) return -1;
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return 0;
	aref grp;
	makearef(grp, loadedLocation.(at));
	return GetAttributesNum(grp);
}

//����� ��������� ������� � �������� ������ ���������
string LAi_FindRandomLocator(string group)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	num = rand(num - 1);
	return GetAttributeName(GetAttributeN(grp, num));
}

//����� ������� ������� � �������� ������ ���������
string LAi_FindFarLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist = -1;
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float dx = x - stf(loc.x);
		float dy = y - stf(loc.y);
		float dz = z - stf(loc.z);
		float d = dx*dx + dy*dy + dz*dz;
		if(j >= 0)
		{
			if(d >= dist)
			{
				dist = d;
				j = i;
			}
		}else{
			j = i;
			dist = d;
		}
	}
	if(j < 0) return "";
	return GetAttributeName(GetAttributeN(grp, j));
}

//����� ������� ��������� ������� � �������� ������ ���������
string LAi_FindFarFreeLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist;
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			float dx = x - lx;
			float dy = y - ly;
			float dz = z - lz;
			float d = dx*dx + dy*dy + dz*dz;
			if(j >= 0)
			{
				if(d > dist)
				{
					dist = d;
					j = i;
				}
			}else{
				j = i;
				dist = d;
			}
		}
	}
	if(j < 0) return "";
	return GetAttributeName(GetAttributeN(grp, j));
}

//����� ��������� ��������� �������
string LAi_FindNearestFreeLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist = 0;
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			float dx = x - lx;
			float dy = y - ly;
			float dz = z - lz;
			float d = dx*dx + dy*dy + dz*dz;
			if(j >= 0)
			{
				if(d < dist)
				{
					dist = d;
					j = i;
				}
			}else{
				j = i;
				dist = d;
			}
		}
	}
	if(j < 0) return "";
	return GetAttributeName(GetAttributeN(grp, j));
}
// boal
string LAi_FindNearestLocator(string group, float x, float y, float z)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int j = -1;
	float dist = -1;
	for(int i = 0; i < num; i++)
	{
		aref loc = GetAttributeN(grp, i);
		float dx = x - stf(loc.x);
		float dy = y - stf(loc.y);
		float dz = z - stf(loc.z);
		float d = dx*dx + dy*dy + dz*dz;
		if(j >= 0)
		{
			if(d < dist)
			{
				dist = d;
				j = i;
			}
		}else{
			j = i;
			dist = d;
		}
	}
	if(j < 0) return "";
	return GetAttributeName(GetAttributeN(grp, j));
}
string LAi_FindNearestFreeLocator2Pchar(string group)
{
	float locx, locy, locz;
    GetCharacterPos(Pchar, &locx, &locy, &locz);
    return LAi_FindNearestFreeLocator(group, locx, locy, locz);
}
//����� ���������� �������� ��������� � �������� �������
int LAi_FindNearestCharacter(aref chr, float radius)
{
	int res = FindNearCharacters(chr, radius, -1.0, -1.0, 0.01, false, true);
	if(res <= 0) return -1;
	return sti(chrFindNearCharacters[0].index);
}

//����� ���������� �������� ��������� � �������� �������
int LAi_FindNearestVisCharacter(aref chr, float radius)
{
	int res = FindNearCharacters(chr, radius, -1.0, -1.0, 0.01, true, true);
	if(res <= 0) return -1;
	return sti(chrFindNearCharacters[0].index);
}

//�������� ������� ����� ��������� � 0..1
float LAi_GetCharacterFightLevel(aref character)
{
	//Fencing skill
	float fgtlevel = 0.0;
	if (CheckAttribute(character,"model.animation") && character.model.animation == "mushketer")
	{
		fgtlevel = GetCharacterSkill(character, LAi_GetMushketFencingType(character));
	}
	else
	{	
		fgtlevel = GetCharacterSkill(character, LAi_GetBladeFencingType(character)); 
	}
	//Level
	fgtlevel = fgtlevel/SKILL_MAX;
	return fgtlevel;
}
// boal skill -->
//�������� ������� pistol ��������� � 0..1
float LAi_GetCharacterGunLevel(aref character)
{
	//pistol skill
	float fgtlevel = 0.0;
	fgtlevel = GetCharacterSkill(character, SKILL_PISTOL);
	fgtlevel = fgtlevel/SKILL_MAX;
	return fgtlevel;
}

float LAi_GetCharacterLuckLevel(aref character)
{
	float fgtlevel = 0.0;
	fgtlevel = GetCharacterSkill(character, SKILL_FORTUNE);
	fgtlevel = fgtlevel/SKILL_MAX;
	return fgtlevel;
}
// boal skill <--

//��������� ����������� � ���������
void LAi_ApplyCharacterDamage(aref chr, int dmg, string DamageType)
{
	float damage    = MakeFloat(dmg);
	bool  bIsOfficer = false;
	//�������� ��������� �����������
	if(CheckAttribute(chr, "chr_ai.type"))
	{
		if(chr.chr_ai.type == LAI_TYPE_OFFICER)
		{
			damage = damage*0.7;
			bIsOfficer = true;
		}
	}
	//�������� ������� ���������
	if(!CheckAttribute(chr, "chr_ai.hp"))     chr.chr_ai.hp     = LAI_DEFAULT_HP;
	if(!CheckAttribute(chr, "chr_ai.hp_max")) chr.chr_ai.hp_max = LAI_DEFAULT_HP_MAX;
	float maxhp = stf(chr.chr_ai.hp_max);
	float hp    = stf(chr.chr_ai.hp);
	//�������������
	if (damage > hp)  damage = hp;
	hp = hp - damage;
	if(hp < 1.0) hp = 0.0;
	chr.chr_ai.hp = hp;
	//�������� �����
	LAi_ProcessCheckMinHP(chr);
	
	bool bloodSize = false;
	if (damage > 30.0) bloodSize = true;
	float fRange = 1.0 + frand(0.6);
	if(CheckAttribute(chr,"model.animation") && chr.sex != "skeleton") // 280712
	{		
		if(DamageType == "fire" || DamageType == "fight")
		{
			LaunchBlood(chr, fRange, bloodSize, DamageType);	
		}	
	}	
	if(CheckAttribute(chr,"model.animation") && chr.model.animation == "giant" && damage > 50.0) // 280712
	{
		LaunchIncasFire(chr, false);
	}	

	if(sti(pchar.index) == sti(chr.index)) 
	{
		// �������� -->
        pchar.Health.Damg      = stf(pchar.Health.Damg) + damage;
	    pchar.Health.weekDamg  = stf(pchar.Health.weekDamg) + damage;
        pchar.Health.TotalDamg = stf(pchar.Health.TotalDamg) + damage;
        // �������� <--
        return;
	}
	if (bIsOfficer)
    {
        chr.Health.TotalDamg = stf(chr.Health.TotalDamg) + damage; // ����������
        return;
    }
	//������� � ��������� �����������
	SendMessage(chr, "lfff", MSG_CHARACTER_VIEWDAMAGE, dmg, MakeFloat(MakeInt(hp)), MakeFloat(MakeInt(maxhp)));
}

//����� ���������, ���� ����������� hp
void LAi_CheckKillCharacter(aref chr)
{
	if(SendMessage(chr, "ls", MSG_CHARACTER_EX_MSG, "IsDead")) return;
	if(!CheckAttribute(chr, "chr_ai.hp")) chr.chr_ai.hp = 0.0;
	//���������
	if(stf(chr.chr_ai.hp) < 1.0)
	{
		//�������, ���� �������
		if(CheckAttribute(chr, "chr_ai.immortal"))
		{
			if(sti(chr.chr_ai.immortal) != 0)
			{
				chr.chr_ai.hp = 1.0;
				return;
			}
		}

		DeleteAttribute(chr, "quest.questflag");

		chr.chr_ai.hp = 0.0;		
		// boal dead can be searched 14.12.2003 -->
		Dead_AddLoginedCharacter(chr); // �������� ��� ������ � ������ ������
		// boal dead can be searched 14.12.2003 <--
		SetCharacterTask_Dead(chr);
		Postevent(EVENT_CHARACTER_DEAD, 1, "a", chr);
		//�������������� ���������
		if(CheckAttribute(chr, "chr_ai.type"))
		{
			string func = chr.chr_ai.type;
			chr.chr_ai.type = "";
			chr.chr_ai.tmpl = "";
			if(func != "")
			{
				func = "LAi_type_" + func + "_Init";
				call func(chr);
			}
			
			if(sti(chr.index) == nMainCharacterIndex)
			{
				//���� ����� ������, �� �������� ���������
				InterfaceStates.Launched = true;
			}
			
		}
		LAi_Character_Dead_Process(chr);
		//Jason: ����������������������� ����������
		if(CheckAttribute(chr, "HalfImmortal"))
		{
				if(!IsOfficer(chr)) return;
				Dead_DelLoginedCharacter(chr);//�� ������������
				ref rOff = GetCharacter(NPC_GenerateCharacter("Clon", "none", chr.sex, chr.model.animation, 1, sti(chr.nation), -1, false, "officer"));
				ChangeAttributesFromCharacter(rOff, chr, true);
				rOff.id = chr.id;
				rOff.HalfImmortal = true;
				int ihpm = sti(rOff.chr.chr_ai.hp_max)-40;
				if (ihpm < 40) ihpm = 40;
				LAi_SetHP(rOff, ihpm, ihpm); // ����� � ��
				LAi_SetCurHPMax(rOff);
				AddPassenger(pchar, rOff, false);
				Log_Info("���������� " + GetFullName(rOff) + " ��� ��������!");
		}
	}
}

//������� ���������� ���������
ref LAi_CreateFantomCharacter(string model, string group, string locator)
{
	return LAi_CreateFantomCharacterEx(model, "man", group, locator);
}

//������� ���������� ���������
ref LAi_CreateFantomCharacterEx(string model, string ani, string group, string locator)
{
	//���� ��������� ����� ��� ���������
	for(int i = 0; i < MAX_CHARS_IN_LOC; i++)
	{
		if(CheckAttribute(&Characters[LOC_FANTOM_CHARACTERS + i], "id") == false) break;
		if(Characters[LOC_FANTOM_CHARACTERS + i].id == "") break;
	}
	if(i >= MAX_CHARS_IN_LOC)
	{
		for(i = 0; i < MAX_CHARS_IN_LOC; i++)
		{
			if(!IsEntity(&Characters[LOC_FANTOM_CHARACTERS + i])) break;
		}
		if(i >= MAX_CHARS_IN_LOC) i = 0;
	}
	ref chr = &Characters[LOC_FANTOM_CHARACTERS + i];

	//��������� ���� ���������
	chr.id = "Location fantom character <" + i + ">";
	chr.index = LOC_FANTOM_CHARACTERS + i;
	//address
	if(IsEntity(loadedLocation) != true)
	{
		chr.location = "none";
	}else{
		chr.location = loadedLocation.id;
	}
	chr.location.group = "";
	chr.location.locator = "";
	chr.location.from_sea = "";
	chr.location.fantom = "1";
	//model
	if(model != "") chr.model = model; else chr.model = "man1";
	chr.model.entity = "NPCharacter";
	chr.model.animation = ani;
	// fix -->
    if (chr.model.animation == "towngirl" || chr.model.animation == "towngirl3" || chr.model.animation == "towngirl2")
    {
       chr.model.height = 1.75;
	   chr.sex = "Woman";
    }
    else
    {
	   chr.model.height = 1.8;
	   chr.sex = "man";
	}
	// fix <--
	chr.FaceId = "0";
	chr.headModel = "h_" + chr.model;
	FaceMaker(chr);
	CirassMaker(chr);
	//game params
 	CalculateAppropriateSkills(chr);
    SetFantomHP(chr);
	chr.money = 100 + rand(500);
	chr.reputation = 10 + rand(70);
	chr.skill.freeskill = 0;
	chr.experience = 0;
	chr.spyglass.itemID = COMMON_SPYGLASS;
	//Quest data
	chr.Dialog.CurrentNode = "First time";
	chr.Dialog.TempNode = chr.Dialog.CurrentNode;
	chr.quest.meeting = "0";
	chr.quest = "True";
	//blade
	//GiveItem2Character(chr, BLADE_SABER); //boal ����� �����!
	//chr.equip.blade = BLADE_SABER;
    //  boal �� ����� ��� - ����� ����� � LAi_NPC_Equip � ������ ��������� � �����  GiveItem2Character(chr, GUN_COMMON);
	//chr.equip.gun = GUN_COMMON;
    TakeNItems(chr,"potion1", Rand(4)+1);
	//nation
	int nat = GetLocationNation(loadedLocation);
	if(nat >= 0)
	{
		chr.nation = nat;
	}else{
		chr.nation = pchar.nation;
	}
	//name
	SetRandomNameToCharacter(chr);
	
	//������� ��������� � �������
	chr.chr_ai.type    = LAI_DEFAULT_TYPE;
	chr.chr_ai.tmpl    = LAI_DEFAULT_TEMPLATE;
	chr.chr_ai.group   = LAI_DEFAULT_GROUP;
	chr.chr_ai.alarmreact = LAI_DEFAULT_ALARMREACT;
	chr.chr_ai.grpalarmr  = LAI_DEFAULT_GRPALARMR;
	//chr.chr_ai.hp      = LAI_DEFAULT_HP;
	//chr.chr_ai.hp_max  = LAI_DEFAULT_HP_MAX;
	chr.chr_ai.charge  = LAI_DEFAULT_CHARGE;
	chr.chr_ai.FencingType  = "FencingS"; //fix
	//chr.chr_ai.energy = LAI_DEFAULT_ENERGY;
	SetEnergyToCharacter(chr); // boal
	if(LAi_numloginedcharacters >= MAX_CHARS_IN_LOC)
	{
		Trace("LAi_CreateFantomCharacter -> many logined characters in location > " + MAX_CHARS_IN_LOC);
		return chr;
	}
	LAi_AddLoginedCharacter(chr);
	// boal del lag Event("Fantom_FillSkills", "a", chr);
	if(!CreateCharacter(chr))
	{
		Trace("LAi_CreateFantomCharacter -> CreateCharacter return false");
		return chr;
	}
	//�������� ��������� �� �������
	if(group == "")
	{
		group = "goto";
		locator = "";
	}
	if(locator == "")
	{
		//�������� ������� �������
		locator = LAi_FindNPCLocator(group);
	}
	chr.location.group = group;
	chr.location.locator = locator;
	if(SendMessage(chr, "lss", MSG_CHARACTER_ENTRY_TO_LOCATION, group, locator) == false)
	{
		Trace("LAi_CreateFantomCharacter -> can't teleportation character to <" + group + "::" + locator + ">");
	}
	return chr;
}
// boal
string LAi_FindNPCLocator(string group)
{
    string  locator = "";
	//�������� ������� �������
	float posX, posY, posZ;
	posX = 0.0; posY = 0.0; posZ = 0.0;
	
	ref  MnChar = GetMainCharacter();

	if(GetCharacterPos(MnChar, &posX, &posY, &posZ))
	{
		// boal -->
		if (sti(MnChar.GenQuestFort.FarLocator) == true)
		{
			locator = LAi_FindFarFreeLocator(group, posX, posY, posZ);
		}
		else
		{
			locator = LAi_FindNearestFreeLocator(group, posX, posY, posZ);  // ���������
            if(locator == "")
			{
				locator = LAi_FindRandomLocator(group);
			}
		}
		if(locator == "")
		{
			locator = LAi_FindFarLocator(group, posX, posY, posZ);
			if(locator == "")
			{
				locator = LAi_FindRandomLocator(group);
			}
		}
	}
	else
	{
		locator = LAi_FindRandomLocator(group);
	}
	return locator;
}

object lai_questdelays;
string LAi_QuestDelay(string quest, float delayTime)
{
	int num = GetAttributesNum(&lai_questdelays);
	string atr = "e";
	for(int i = 0; i < num + 10; i++)
	{
		atr = "e" + i;
		if(!CheckAttribute(&lai_questdelays, atr)) break;
		if (lai_questdelays.(atr).quest == quest) break; // boal ��� ��� ��� �����, ��� ����� ��� �������������
	}
	lai_questdelays.(atr) = delayTime;
	lai_questdelays.(atr).quest = quest;
	
	return atr; //boal
}
//boal -->
void LAi_MethodDelay(string quest, float delayTime)
{
	string atr = LAi_QuestDelay(quest, delayTime);
	lai_questdelays.(atr).method = true;
}
// boal <--
void LAi_QuestDelayProcess(float dltTime)
{
	string atr;
	int num = GetAttributesNum(&lai_questdelays);
	//����������� �������
	for(int i = 0; i < num; i++)
	{
		atr = GetAttributeName(GetAttributeN(&lai_questdelays, i));
		lai_questdelays.(atr) = stf(lai_questdelays.(atr)) - dltTime;
	}
	//��������� ���������� � �������� ���������
	for(i = 0; i < num; i++)
	{
		atr = GetAttributeName(GetAttributeN(&lai_questdelays, i));
		if(atr == "root")
		{
			Trace("LAi_QuestDelayProcess -> invalide attibute field: root!!!");
			continue;
		}
		float time = stf(lai_questdelays.(atr));
		if (time <= 0)
		{
			string quest = lai_questdelays.(atr).quest;
			if (CheckAttribute(&lai_questdelays, atr + ".method"))
			{
                DeleteAttribute(&lai_questdelays, atr);
                call quest();
			}
			else
			{
                DeleteAttribute(&lai_questdelays, atr);
                CompleteQuestName(quest, "");
			}
			i = -1;
			num = GetAttributesNum(&lai_questdelays);
		}
	}
}

void LAi_ChangeReputation(aref chr, int repPoints)
{
	if(chr.reputation != "None")
	{
		if(chr.reputation != "")
		{
			int reput = sti(chr.reputation) + repPoints;
			if(reput < REPUTATION_MIN) reput = REPUTATION_MIN;
			if(reput > REPUTATION_MAX) reput = REPUTATION_MAX;
			chr.reputation = reput;
		}
	}

}

void LAi_CheckCharacterID(aref chr)
{
	SendMessage(chr, "ss", "CheckID", chr.id);
}

void LAi_SetDefaultStayAnimation(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	SetDefaultStayIdle(chr);
	SetDefaultNormWalk(chr);
	SetDefaultFight(chr);
	SetDefaultDead(chr);
	SetDefaultFightDead(chr);
	EndChangeCharacterActions(chr);
	}
}

void LAi_SetDefaultDead(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	SetDefaultDead(chr);
	EndChangeCharacterActions(chr);
	}
}

void LAi_SetAfraidDead(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	SetAfraidDead(chr);
	EndChangeCharacterActions(chr);
	}
}

void LAi_SetDefaultSitAnimation(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	if (CheckAttribute(chr, "nonTable")) SetDefaultSit2Idle(chr);
	else SetDefaultSitIdle(chr);
	SetDefaultSitDead(chr);
	EndChangeCharacterActions(chr);
	}
}

void LAi_SetHuberSitAnimation(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	SetHuberAnimation(chr);	
	SetDefaultSitDead(chr);
	EndChangeCharacterActions(chr);

	}
}

void LAi_SetDefaultLayAnimation(aref chr)
{
	if(IsEntity(chr))
	{
	chr.chr_ai.type.mode = "lay";
	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "Lay_1";
	EndChangeCharacterActions(chr);
	}
}

void LAi_SetDefaultMiningAnimation(aref chr)	 // ��� ������� ����
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	chr.chr_ai.type.mode = "Mining";
	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "ore_go_1";
	EndChangeCharacterActions(chr);

	} 
}

void LAi_SetDefaultStayworkAnimation(aref chr)
{
	if(IsEntity(chr))
	{
	BeginChangeCharacterActions(chr);
	chr.chr_ai.type.mode = "Staywork";
	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "Barman_idle";
	EndChangeCharacterActions(chr);

	} 
}


//������� ����� � �������, ��������� ����� questFadeOut, ������� �� �������, ��������� ����� questFadeIn
object LAi_QuestFader;
void LAi_Fade(string questFadeOut, string questFadeIn)
{
	if(questFadeOut != "") LAi_QuestDelay(questFadeOut, 0.5);
	if(questFadeIn != "") LAi_QuestDelay(questFadeIn, 1.0);
	
	if(IsEntity(&LAi_QuestFader))
	{
		Trace("LAi_Fade -> previous fade operation not ended!");
		return;
	}
	//Fader
	SetEventHandler("FaderEvent_EndFade", "LAi_FadeEndFadeOut", 0);
	SetEventHandler("FaderEvent_EndFadeIn", "LAi_FadeEndFadeIn", 0);
	CreateEntity(&LAi_QuestFader, "fader");
	SendMessage(&LAi_QuestFader, "lfl", FADER_OUT, 0.5, false);
	LAi_QuestFader.oldSaveState = InterfaceStates.Buttons.Save.enable;
	InterfaceStates.Buttons.Save.enable = 0;
}

void LAi_FadeEndFadeOut()
{
	DelEventHandler("FaderEvent_EndFade", "LAi_FadeEndFadeOut");
	SendMessage(&LAi_QuestFader, "lfl", FADER_IN, 0.5, true);
}

void LAi_FadeEndFadeIn()
{
	DelEventHandler("FaderEvent_EndFadeIn", "LAi_FadeEndFadeIn");
	InterfaceStates.Buttons.Save.enable = LAi_QuestFader.oldSaveState;
}

//������� ����� � �������, ����� ��������� ����� �������
void LAi_FadeDelay(float _delayTime, string sPath)
{
    pchar.GenQuest.CallFunctionParam = "FadeDelay";
    DoQuestCheckDelay("CallFunctionParam", _delayTime);
	//Fader
	CreateEntity(&LAi_QuestFader, "fader");
	SendMessage(&LAi_QuestFader, "ls", FADER_PICTURE0, "loading\ImgBack.tga");
	SendMessage(&LAi_QuestFader, "ls", FADER_PICTURE, sPath);
	SendMessage(&LAi_QuestFader, "lfl", FADER_OUT, 0.5, false);
	LAi_QuestFader.oldSaveState = InterfaceStates.Buttons.Save.enable;
	InterfaceStates.Buttons.Save.enable = 0;
}
void FadeDelay()    // ��������� � ������ ����.
{
	LAi_FadeEndFadeIn();
	LAi_FadeEndFadeOut();
}

//���� �� ������ � ���������
bool LAi_IsSetBale(aref chr)
{
	return (SendMessage(chr, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
}

//� ������ ���
bool LAi_IsFightMode(aref chr)
{
	// boal fix -->
	if ((bLandInterfaceStart) && CheckAttribute(chr, "equip.blade"))
    {
        return (SendMessage(&chr, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") != 0);
    }
    return false;
    // boal fix <--
}

//���������� ����� ��� ������������� ���������� � ���������
#event_handler("EventWorldMapInit", "LAi_SetRestoreStates");
#event_handler(EVENT_SEA_LOGIN, "LAi_SetRestoreStates");
void LAi_SetRestoreStates()
{
	LAi_restoreStates = true;
	// boal 04/02/2005 FIX
	QuestsCheck();
}

#event_handler("EventSGMode", "LAi_GetSGMode");
bool globalSGMode = false;
bool LAi_GetSGMode()
{
	return globalSGMode;
}

bool LAi_IsBottleWork(aref chr)
{
	if(CheckAttribute(chr, "chr_ai.hp_bottle"))
	{
		if(stf(chr.chr_ai.hp_bottle) > 0.0) return true;
	}
	return false;
}

//����� � ����� ������
bool LAi_CanNearEnemy(aref chr, float radius)
{
	int num = FindNearCharacters(chr, radius, -1.0, -1.0, 0.001, false, false);
	if(num <= 0) return false;
	for(int i = 0; i < num; i++)
	{
		int idx = sti(chrFindNearCharacters[i].index);
		/*if(characters[idx].id == pchar.id)   // to_do boal
		{
			if(LAi_grp_alarmactive == false)
			{
				return false;
			}
		}	  */
		if(LAi_group_IsEnemy(chr, &Characters[idx])) return true;
	}	
	return false;
}
// boal dead can be searched 14.12.2003 -->
object	Dead_Characters[100];
int     Dead_Char_num = 0;

void Dead_AddLoginedCharacter(aref chr)
{
	float   x, y, z;
	ref     chref, rItem;
	ref     mchr = GetMainCharacter();
	aref    arFromChar;
	aref    arToChar;
	float   nLuck   = GetCharacterSkillToOld(GetMainCharacter(), SKILL_FORTUNE);
    string  itemID;
    int     value, count;
    aref    typeRef;
	string  sBullet, sGunPowder;
	//trace("Dead_AddLoginedCharacter nLuck = " + nLuck);
	
	if(GetCharacterPos(chr, &x, &y, &z) == true && Dead_Char_num < (100))
	{
		Dead_Characters[Dead_Char_num].id = chr.id;
		Dead_Characters[Dead_Char_num].index = chr.index;
		Dead_Characters[Dead_Char_num].name     = chr.name;
		Dead_Characters[Dead_Char_num].lastname = chr.lastname;
		if (CheckAttribute(chr, "faceid")) 
		{
			Dead_Characters[Dead_Char_num].faceid   = chr.faceid;
		}
		chref = &Dead_Characters[Dead_Char_num];
		DeleteAttribute(chref, "items");
		DeleteAttribute(chref, "Money");
		if (IsOfficer(chr) || CheckAttribute(chr, "SaveItemsForDead"))// ��� �������� � ��� ��������� ��� ����
		{
		    chref.Money = chr.Money;
            makearef(arToChar, chref.items);
            makearef(arFromChar, chr.items);
	        CopyAttributes(arToChar, arFromChar);
	        DeleteAttribute(chref,"items.unarmed"); // 18.06.05 ������� ������������ � ����� �������
	        DelBakSkillAttr(mchr); // boal ����������� ������
	        ClearCharacterExpRate(mchr);
	        DeleteAttribute(chr, "SaveItemsForDead");// ������ ���� �� ���� �������� �����
	        //BLI_UpdateOfficers();// fix �������� �� ����, �� ��������� ������
			
			// ������� ��������
			for(value = 0; value < ITEMS_QUANTITY; value++)
			{
				itemID = Items[value].ID;
				
				if(IsGenerableItem(itemID) && CheckCharacterItem(chr, itemID))
				{
					count = GetCharacterItem(chr, itemID);
					RemoveItems(chr, itemID, count); // ��������� �������
					GenerateAndAddItems(chr, itemID, count); // ���� �����������
				}
			}
	    }
	    else
	    {
		    // ������ � �� -->
		    if (CheckAttribute(chr, "GhostShipCrew"))
		    {
           //TakeNItems(chref, "DestinyGiftPearl", Rand(9) + 3);
          // ����� �������� ����� �����, ���� ����� � ��
          TakeNItems(pchar, "DestinyGiftPearl", Rand(9) + 3);
                Log_Info("������� ������ ���������");
		    }
		    else
		    // ������ � �� <--
		    {
    		    if (makeint(nLuck + 0.5) > rand(15))
    			{
    				chref.Money = rand(9) + rand(makeint(nLuck))*5 + rand(makeint(nLuck))*20;
    			}
    		    // ������ ����� � ������� -->
    		    if(CheckAttribute(chr, "equip.blade"))
				{
					if(rand(MOD_SKILL_ENEMY_RATE + 5) == 1 && chr.equip.blade != "unarmed") // 20% for 3+2=5
					{
						rItem = ItemsFromID(chr.equip.blade);
						if(CheckAttribute(rItem,"quality") && sti(rItem.quality) < B_EXCELLENT) // ugeen --> �� ������� ������ ������� ������ �� ���� !!!
						{	// ���� ����� ����������� ������
							if(sti(rItem.quality) == B_POOR)
							{
								AddItems(chref, GetGeneratedItem(chr.equip.blade), 1); 
							}
							if(sti(rItem.quality) == B_ORDINARY && sti(mchr.rank) >= 5)
							{
								AddItems(chref, GetGeneratedItem(chr.equip.blade), 1); 
							}
							if(sti(rItem.quality) == B_GOOD && sti(mchr.rank) >= 15)	
							{
								AddItems(chref, GetGeneratedItem(chr.equip.blade), 1); 
							}
						}	
					}
				}
				if(CheckAttribute(chr, "equip.gun"))
				{
					if(rand(MOD_SKILL_ENEMY_RATE + 10) == 2)
					{
						rItem = ItemsFromID(chr.equip.gun);
						if(CheckAttribute(rItem,"quality") && rItem.quality != "excellent" && rItem.quality != B_UNIQUE) // ugeen --> �� ������� ������ ������� ������ �� ���� !!!
						{
							if(CheckAttribute(rItem,"quality") && rItem.quality == B_GOOD)
							{ // ������ �� ��������, � �� ���� ��������
								if(rand(MOD_SKILL_ENEMY_RATE*5+50) == 50) GiveItem2Character(chref, chr.equip.gun);
							}
							else GiveItem2Character(chref, chr.equip.gun);
						}	
						sBullet = LAi_GetCharacterBulletType(chr);						
						sGunPowder = LAi_GetCharacterGunpowderType(chr);							
						if (chr.model.animation != "mushketer") //� ���������� ���� ������, ������� � ��� �� ����� - ������
						{							
							TakeNItems(chref, sBullet, GetCharacterItem(chr, sBullet));// boal gun bullet													
							if(sGunPowder != "")
							{
								AddItems(chref, sGunPowder, GetCharacterItem(chr, sGunPowder)); // 21.03.09 Warship fix �����
							}	
						}
						else
						{							
							TakeNItems(chref, sBullet, makeint(GetCharacterItem(chr, sBullet)/2));// boal gun bullet											
							if(sGunPowder != "")
							{
								AddItems(chref, sGunPowder, makeint(GetCharacterItem(chr, sGunPowder)/2)); // 21.03.09 Warship fix �����
							}	
						}
					}
				}
    		    // ������ ����� � ������� <--
                //fill box with new items
                int j, howI;
                ref    itm;
                string name = "";
                string  sModel = chr.model;
                howI = 0;
                // �������� ��� -->
                if (chr.sex != "man")
                {
    		        name = "Citizen_f";
    		    }
    		    else
    		    {
                    if (findsubstr(sModel, "off_" , 0) != -1)
					{
	    		        name = "Solder_o";
	    		    }
    		    }
                if (name == "")
                {
                    name = GetCharType(chr);
            	}
            	// �������� ��� <--

                for (j= ItemDeadStartCount; j<ITEMS_QUANTITY; j++) // ����� ��������������!!! 137 - ��� �����  ������ � ����� �����
    			{
					if (howI >= (11 - MOD_SKILL_ENEMY_RATE))
					{
					   break;
					}
					makeref(itm,Items[j]);
					if (CheckAttribute(itm, name))
					{
						makearef(typeRef, itm.(name));
                        //attrName = name+".rare";
                        if (!CheckAttribute(typeRef, "rare") && MOD_BETTATESTMODE == "On") Log_Info("Error: �� ������ RARE ��� �������� = "+itm.id + " ��� = " + name);

                        if ( rand(1000) < (((stf(typeRef.rare) + stf(typeRef.rare)*nLuck / 20.0) / makefloat(MOD_SKILL_ENEMY_RATE))*930.0))
                        {
                            value = sti(typeRef.min);
                            value = value+rand(sti(typeRef.max) - value);
                            itemID = itm.id;
							chref.items.(itemID) = value;
							howI++;
						}
					}
    			}
			}
			// ��������� �� ������
	    }
		Dead_Characters[Dead_Char_num].px = x;
		Dead_Characters[Dead_Char_num].pz = z;
	    Dead_Char_num++;
	}
}
void Dead_DelLoginedCharacter(aref chr)
{
	aref arToChar;
	aref arFromChar;
	ref c1, c2;
    for(int i = 0; i < Dead_Char_num; i++)
	{
		if(CheckAttribute(chr, "index") && Dead_Characters[i].index == chr.index)
		{
            Dead_Characters[i].px = 30000; // ������� -2000 �� 2000
			Dead_Characters[i].pz = 30000;
		}		
	}
	if(Dead_Char_num < 0) Dead_Char_num = 0;
}

int Dead_FindCloseBody()
{
	ref mainChr = GetMainCharacter();
	int dchr_index = -1;
	float x, y, z;
	float x1, y1, z1, rd, min_rd = 100; // 100 - is super max
	GetCharacterPos(mainChr, &x, &y, &z);
	
    for(int i = 0; i < Dead_Char_num; i++)
	{
	    x1 = Dead_Characters[i].px;
		z1 = Dead_Characters[i].pz;
		rd = sqrt(sqr(x1 - x) + sqr(z1 - z))
		if ( rd < 1.8)
		{
		    if (min_rd > rd)
		    {
		        min_rd = rd;
                dchr_index = i;
		    }
		}
	}
	return dchr_index;
}
void Dead_OpenBoxProcedure()
{
	ref chr = GetMainCharacter();
	int dchr_index;
    ref deadCh;
    dchr_index = Dead_FindCloseBody();
    if (dchr_index == -1) return;
	if (CheckAttribute(pchar, "GenQuest.Notsearchbody")) return;//Jason
    
	deadCh = &Dead_Characters[dchr_index];
	
	Dead_LaunchCharacterItemChange(deadCh);
}
void Dead_LaunchCharacterItemChange(ref chref)
{
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		aref charef; makearef(charef,chref);
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,&charef, "666");
	}
}

// boal dead can be searched 14.12.2003 <--

void MakePoisonAttack(aref attack, aref enemy)
{
	if (!CheckAttribute(enemy, "chr_ai.poison"))
	{
		if (enemy.index == GetMainCharacterIndex()) Log_SetStringToLog(XI_ConvertString("You've been poisoned"));
		else Log_SetStringToLog(GetFullName(enemy) + XI_ConvertString("is poisoned"));
		enemy.questTemp.poisonperk = "true";
	}
	//��������� ���������
	float poison = 0.0;
	if(CheckAttribute(enemy, "chr_ai.poison"))
	{
		poison = stf(enemy.chr_ai.poison);
		if(poison < 1.0) poison = 1.0;
	}
	enemy.chr_ai.poison = poison + 100 + rand(300);
	AddCharacterHealth(enemy, -3.0) // ���������� ������ �������� �� 3 ��
}

void MakePoisonAttackCheckSex(aref attacked, aref enemy)
{
	if (IsCharacterEquippedArtefact(attacked, "kaleuche_amulet3")) return; // �������
	if (enemy.sex == "skeleton" || enemy.sex == "crab" || IsCharacterEquippedArtefact(enemy, "indian_10") || CheckAttribute(enemy, "viper"))
	{
		if (rand(1000) < 150) MakePoisonAttack(enemy, attacked);
		else
		{
			if (rand(2) < 2 && CheckAttribute(enemy, "viper")) MakePoisonAttack(enemy, attacked);
		}
	}
}

string LAi_FindFreeRandomLocator(string group)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	int base = rand(num - 1);
	for(int i = 0; i < num; i++)
	{
		int index = base + i;
		if(index >= num)
		{
			index = index - num;
		}
		aref loc = GetAttributeN(grp, index);
		float lx = stf(loc.x);
		float ly = stf(loc.y);
		float lz = stf(loc.z);
		if(CheckLocationPosition(loadedLocation, lx, ly, lz))
		{
			return GetAttributeName(GetAttributeN(grp, index));
		}
	}
	return "";
}

bool LAi_CheckLocatorFree(string _group, string _locator)
{
	if(!IsEntity(loadedLocation)) return false;	
	string at = "locators." + _group + "." + _locator;
	if(!CheckAttribute(loadedLocation, at)) return false;
	aref grp;
	makearef(grp, loadedLocation.(at));
	float lx = stf(grp.x);
	float ly = stf(grp.y);
	float lz = stf(grp.z);
	if(CheckLocationPosition(loadedLocation, lx, ly, lz))
	{
		return true;
	}
	return false;
}

void LaunchBlood(aref chr, float addy, bool isBig, string DamageType)
{
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	if (loadedLocation.type == "underwater")
	{
		y = y + 0.9;
		CreateParticleSystem("bloodUnderwater", x, y, z, 0,1.0,0,0);
	}
	else
	{
		y = y + addy;
		if(isBig == true)
		{
			if(DamageType == "fire")
			{
				if(rand(1) == 0) 	CreateParticleSystem("blood_big", x, y, z, 0,1.0,0,0);
				else				CreateParticleSystem("blood_massshoot", x, y, z, 0,1.0,0,0);
			}
			else	CreateParticleSystem("blood_big", x, y, z, 0,1.0,0,0);
		}
		else
		{
			if(DamageType == "fire")
			{
/*			
				if(rand(1) == 0) 	CreateParticleSystem("blood", x, y, z, 0,1.0,0,0);
				else
				{	
					if(rand(1) == 0) CreateParticleSystem("blood_singleshoot", x, y, z, 0,1.0,0,0);
					else			 CreateParticleSystem("blood_massshoot", x, y, z, 0,1.0,0,0);
				}
*/
				if(rand(1) == 0) 	CreateParticleSystem("blood_fire1", x, y, z, 0,1.0,0,0);
				else
				{	
					if(rand(1) == 0) CreateParticleSystem("blood_fire2", x, y, z, 0,1.0,0,0);
					else			 CreateParticleSystem("blood_fire3", x, y, z, 0,1.0,0,0);
				}				
			}
			else 	CreateParticleSystem("blood", x, y, z, 0,1.0,0,0);
		}
		SendMessage(loadedLocation, "lsfff", MSG_LOCATION_EX_MSG, "AddBlood", x,y,z);
	}
}

void LaunchIncasFire(aref chr, bool isBig) // 280712
{
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	y = y + 0.1;
	if (isBig) CreateParticleSystem("fire_incas_Simple", x, y, z, 0,1.0,0,0);
	else CreateParticleSystem("incas_blood", x, y, z, 0,1.0,0,0);
}

void LaunchBlast(aref chr) // 280812
{
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	y = y + 0.5;
	CreateParticleSystem("blast_inv", x, y, z, 0,1.0,0,0);
}

void LaunchBlastPellet(aref chr) // 
{
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	y = y + 0.5;
	CreateParticleSystem("blast_inv", x, y, z, 0,1.0,0,0);
	y = y + 0.1;
	CreateParticleSystem("blast_inv", x, y, z, 0,1.0,0,0);
	y = y + 0.9;
	CreateParticleSystem("blast_inv", x, y, z, 0,1.0,0,0);
	Play3DSound("pellet", x, y, z);
}

void LaunchBlastGrenade(aref chr) // 
{
	float x, y, z;
	GetCharacterPos(chr, &x, &y, &z);
	y = y + 0.5;
	CreateParticleSystem("blast_inv", x, y, z, 0,1.0,0,0);
	CreateParticleSystem("blast_dirt", x, y, z, 0,1.0,0,0);
	Play3DSound("grenade", x, y, z);
}

void LAi_Explosion(ref chr, int damage)
{
	float x, y, z;						
	GetCharacterPos(chr, &x, &y, &z);
	CreateParticleSystemX("blood_shoot", x, y, z, x, y, z, 0);	
	CreateParticleSystemX("cancloud_fire", x, y, z, x, y, z, 20);
	
	PlayStereoSound("Sea Battles\cannon_fire_03.wav");
	
	int num = FindNearCharacters(chr, 3.0, -1.0, -1.0, 0.001, false, true);

	for(int j = 0; j <= num; j++)	
	{
		int idx = sti(chrFindNearCharacters[j].index);	
		ref findCh;
		findCh = GetCharacter(idx);	
    
		float dist = -1.0;
		if(GetCharacterDistByChr3D(chr, findCh, &dist) && dist < 4)
		{
			LAi_ApplyCharacterDamage(findCh, damage, "fire");		
			if (sti(LAi_GetCharacterHP(findCh)) < damage + 1) 
			{ 
				if(findCh.chr_ai.group != LAI_GROUP_PLAYER)  
				{
					Lai_KillCharacter(findCh);
				} 
				else
				{
					findCh.chr_ai.hp = 10;
				} 
			}
		}
	}	

	LAi_ApplyCharacterDamage(chr, damage, "fire");	
	if (sti(LAi_GetCharacterHP(chr)) < damage + 1) Lai_KillCharacter(chr);
}

void LAi_ClawBeliar(ref chr, ref enemy, int damage) // "������ �������"
{
	float x, y, z;
	int RandomSound = rand(2) // ��������� ����	
	GetCharacterPos(chr, &x, &y, &z);
	CreateParticleSystemX("ShipExplode", x+rand(1), y+rand(1), z+rand(1), x, y, z, 0); // ������� ���������� ������
	
	int num = FindNearCharacters(chr, 3.0, -1.0, -1.0, 0.001, false, true);
	
	// �������� �������
	if(RandomSound == 0) PlaySound("Voice\Russian\gotica\SFX\MFX_FIREBALL_CAST.WAV"); 
	if(RandomSound == 1) PlaySound("Voice\Russian\gotica\SFX\MFX_FIREBALL_CAST.WAV"); 
	if(RandomSound == 2) PlaySound("Voice\Russian\gotica\SFX\MFX_FIREBALL_CAST.WAV");

	//��������� ���������
	float poison = 0.0;
	if(CheckAttribute(enemy, "chr_ai.poison"))
	{
		poison = stf(enemy.chr_ai.poison);
		if(poison < 1.0) poison = 1.0;
	}
	enemy.chr_ai.poison = poison + 30 + rand(20);
 

	if (!CheckAttribute(enemy, "chr_ai.Beliarfire"))
	{

                     Log_SetStringToLog(GetFullName(enemy) + XI_ConvertString("ClawBeliar delivin fire1"));
	}
	
	for(int j = 0; j <= num; j++)	
	{
	int idx = sti(chrFindNearCharacters[j].index);	
	ref findCh;
	findCh = GetCharacter(idx);	
    
	float dist = -1.0;
	if(findCh.chr_ai.group == LAI_GROUP_PLAYER || findCh.chr_ai.immortal == 1)  // �������� ��������� ����������� � ��� �� ������ ������
		{
			damage = 0.0
		} 
		if(!CheckAttribute(findCh, "chr_ai.Beliarfire") || findCh.chr_ai.Beliarfire == 0) LAi_ApplyCharacterDamage(findCh, damage, "fire");	
		LAi_CheckKillCharacter(findCh);
	}
	
	if(enemy.chr_ai.Beliarfire == 1) enemy.chr_ai.Beliarfire = 0;
} 











