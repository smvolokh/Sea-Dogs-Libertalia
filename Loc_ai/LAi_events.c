//==========================================================================================
//Update events
//==========================================================================================

void LAi_Character_FrameUpdate()
{
	float dltTime = GetEventData();
	//��������� ��������� ����������
	LAi_AllCharactersUpdate(dltTime);
	//�������� ���������� �������
	LAi_QuestDelayProcess(dltTime);
}

void LAi_CharacterUpdate()
{
	//���������
	aref chr = GetEventData();
	float dltTime = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterUpdate") == false) return;
	//������������ ��������������� ���
	string func = chr.chr_ai.type;
	if(func != "")
	{
		func = "LAi_type_" + func + "_CharacterUpdate";
		call func(chr, dltTime);
	}
	//������������ ��������������� ������
	func = chr.chr_ai.tmpl;
	if(func == "") return;
	func = "LAi_tmpl_" + func + "_CharacterUpdate";
	call func(chr, dltTime);
}

//==========================================================================================
//EndTask events
//==========================================================================================

void LAi_CharacterEndTask()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterEndTask") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//���������� ������������ ������
	bool isProcessed = false;
	switch(endTask)
	{
	case "Goto point":
		func = "LAi_tmpl_" + func + "_EndGoToPoint";
		isProcessed = true;
		break;
	case "Runto point":
		func = "LAi_tmpl_" + func + "_EndRunToPoint";
		isProcessed = true;
		break;
	case "Escape":
		func = "LAi_tmpl_" + func + "_EndEscape";
		isProcessed = true;
		break;
	}
	if(isProcessed != false)
	{
		call func(chr);
	}else{
		Trace("LAi_CharacterEndTask -> unknow end task <" + endTask + ">");
	}
}

//==========================================================================================
//TaskFailure events
//==========================================================================================

void LAi_CharacterTaskFailure()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterTaskFailure") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//���������� ��������������� ������
	bool isProcessed = false;
	switch(endTask)
	{
	case "Goto point":
		func = "LAi_tmpl_" + func + "_FailureGoToPoint";
		isProcessed = true;
		break;
	case "Runto point":
		func = "LAi_tmpl_" + func + "_FailureRunToPoint";
		isProcessed = true;
		break;
	case "Follow character":
		func = "LAi_tmpl_" + func + "_FailureFollow";
		isProcessed = true;
		break;
	case "Fight":
		func = "LAi_tmpl_" + func + "_FailureFight";
		isProcessed = true;
		break;
	case "Escape":
		func = "LAi_tmpl_" + func + "_FailureEscape";
		isProcessed = true;
		break;
	}
	if(isProcessed != false)
	{
		call func(chr);
	}else{
		Trace("LAi_CharacterTaskFailure -> unknow failure task <" + endTask + ">");
	}
}

void LAi_CharacterBusyPos()
{
	//���������
	aref chr = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterTaskFailure") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	func = "LAi_tmpl_" + func + "_BusyPos";
	call func(chr, x, y, z);
}


//==========================================================================================
//Follow character's events
//==========================================================================================

void LAi_CharacterFollowGo()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFollowGo") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_FollowGo";
	call func(chr);
}

void LAi_CharacterFollowStay()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFollowStay") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_FollowStay";
	call func(chr);
}

//==========================================================================================
//Fight character's events
//==========================================================================================

void LAi_CharacterFightGo()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFightGo") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_FightGo";
	call func(chr);
}

void LAi_CharacterFightStay()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFightStay") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_FightStay";
	call func(chr);
}

void LAi_CharacterAttack()
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	string attackType = GetEventData();
	bool isBlocked = GetEventData();
	/*if(attack.id == pchar.id)
	{
		pchar.combo.target = sti(enemy.index);
	}   */
	//bool Silence = false;

	if(isBlocked == true)  // to_do
			{
			if (attack.model.animation == "YokoDias" || attack.model.animation == "man" || attack.model.animation == "WomanK2" || attack.model.animation == "woman3_ab" || attack.model.animation == "woman3" || attack.model.animation == "woman_B" || attack.model.animation == "woman_A2" || attack.model.animation == "woman" || attack.model.animation == "towngirl3" || attack.model.animation == "towngirl2" || attack.model.animation == "towngirl" || attack.model.animation == "test" || attack.model.animation == "swim" || attack.model.animation == "skeleton_B" || attack.model.animation == "skeleton" || attack.model.animation == "Rumba" || attack.model.animation == "Orc" || attack.model.animation == "Norman" || attack.model.animation == "mushketer_A1" || attack.model.animation == "mushketer" || attack.model.animation == "Moscovit" || attack.model.animation == "Mirrinda" || attack.model.animation == "Milenace_ab" || attack.model.animation == "Mary" || attack.model.animation == "man3" || attack.model.animation == "man2_ab" || attack.model.animation == "man2" || attack.model.animation == "man1" || attack.model.animation == "man2" || attack.model.animation == "man_old" || attack.model.animation == "man_kvl2" || attack.model.animation == "man_old" || attack.model.animation == "man_C" || attack.model.animation == "man_B" || attack.model.animation == "man_A1" || attack.model.animation == "man_A" || attack.model.animation == "man" || attack.model.animation == "Lucia" || attack.model.animation == "Lorensia" || attack.model.animation == "Lizard" || attack.model.animation == "jessika" || attack.model.animation == "Jess" || attack.model.animation == "Giant" || attack.model.animation == "Danny" || attack.model.animation == "Danielle" || attack.model.animation == "crabSmall" || attack.model.animation == "crabBig" || attack.model.animation == "Chani" || attack.model.animation == "Canib_mush" || attack.model.animation == "crabSmall" || attack.model.animation == "crabBig" || attack.model.animation == "Canib" || attack.model.animation == "Canib_mush" || attack.model.animation == "blaze" || attack.model.animation == "beatrice_ab" || attack.model.animation == "beatrice_2" || attack.model.animation == "Balthrop" || attack.model.animation == "Baker" || attack.model.animation == "Avrora" || attack.model.animation == "armor" || attack.model.animation == "Angellica" || attack.model.animation == "alexander_ab" || attack.model.animation == "BalthropPlayer" || attack.model.animation == "BlazeKCM" || attack.model.animation == "Ciri" || attack.model.animation == "DannyPlayer" || attack.model.animation == "JessikaPlayer" || attack.model.animation == "man_K2" || attack.model.animation == "man_kvl2Player" || attack.model.animation == "man_N" || attack.model.animation == "DannyPlayer" || attack.model.animation == "MaryPlayer" || attack.model.animation == "mushketer_csm" || attack.model.animation == "swimBalthrop" || attack.model.animation == "swimBeatrice" || attack.model.animation == "swimDanielle" || attack.model.animation == "swimJessika" || attack.model.animation == "swimK2man" || attack.model.animation == "swimK3man" || attack.model.animation == "swimK2woman" || attack.model.animation == "Witch")
			{
			int iChance = 0 + GetSummonSkillFromName(attack, SKILL_F_LIGHT)/5 + GetSummonSkillFromName(attack, SKILL_FENCING)/5 + GetSummonSkillFromName(attack, SKILL_F_HEAVY)/5 + GetSummonSkillFromName(attack, SKILL_FORTUNE)/10;
			if (CheckCharacterPerk(attack, "CriticalHit")) iChance = 0 + GetSummonSkillFromName(attack, SKILL_F_LIGHT)/5 + GetSummonSkillFromName(attack, SKILL_FENCING)/5 + GetSummonSkillFromName(attack, SKILL_F_HEAVY)/5 + GetSummonSkillFromName(attack, SKILL_FORTUNE)/10 + 20;
			//if(attack.id == pchar.id) Log_SetStringToLog("���� �������� �����: " + iChance + " ���������");
			if(rand(100) < iChance)
			{
			isBlocked = false;
			if(attack.id == pchar.id) Log_SetStringToLog("�� ������� ����!");
			if(enemy.id == pchar.id) Log_SetStringToLog("��� ���� ������!");
			}
		}
	}
	// �������� ����� (New Abilities 0.4.0) (27.10.17)
	//if(!LAi_grp_alarmactive && sti(attack.index) == GetMainCharacterIndex()) Silence = CharacterSeeMainCharacter(enemy);

	//���������� �����������
	LAi_ApplyCharacterAttackDamage(attack, enemy, attackType, isBlocked);
	
	// ���� ����� �������� ������ ���������
	/*
	if(Silence)
	{
		float radius = 10.0 + (10.0 * (1.0 - makefloat(GetSummonSkillFromName(attack, SKILL_SNEAK)) / 100.0)); // ������ �� ����������
		
		Log_TestInfo("���������� ���������: " + GetSummonSkillFromName(attack, SKILL_SNEAK));
		
		if(IsAnotherCharactersAroundRadius(attack, radius) || !LAi_IsDead(enemy))
		{
			Log_TestInfo("������: " + makeint(radius));
			
			Silence = false;
			//SetNationRelation2MainCharacter(sti(enemy.nation), RELATION_ENEMY);
			Log_Info("���-�� ������� ���������!");
		}
	}
	*/
	//������� ���� �� �����
	//if(!Silence) 
	LAi_group_Attack(attack, enemy);
	//���������� �����������
	LAi_ApplyCharacterAttackDamage(attack, enemy, attackType, isBlocked);
	//������� ���� �����
	LAi_group_UpdateTargets(enemy);
	string func = enemy.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attacked";
	call func(enemy, attack);
	func = "LAi_type_" + enemy.chr_ai.type + "_CharacterUpdate";
	call func(enemy, 0.0001);
	
}

void LAi_CharacterFire()
{
	string sBullet, sGunPowder;
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float kDist = GetEventData();	//0..1
	int isFindedEnemy = GetEventData();

	// CSM --> ������� ����������, ��������� ������� ����� ������� ����� 0.75�
	if (attack.id == pchar.id)
		PostEvent("csmEventSwapWeaponIsFireNowDel", 750);

	//����� ���������
	if(!CheckAttribute(attack, "chr_ai.charge")) attack.chr_ai.charge = "0";
	float charge = stf(attack.chr_ai.charge) - 1.0;
	// boal gun bullet ������� ���� ����� �������� -->
	sBullet = LAi_GetCharacterBulletType(attack);
	TakeItemFromCharacter(attack, sBullet);
	// boal gun bullet ������� ���� ����� �������� <--
	sGunPowder = LAi_GetCharacterGunpowderType(attack);
	if(sGunPowder != "")
	{
		RemoveItems(attack, sGunPowder, 1); // Warship. �������� �����
	}	
	if(charge <= 0.0)
	{
		charge = 0.0;
		attack.chr_ai.chargeprc = "1";
	}
	// boal fix ����� ������� ������� ���������! -->
	attack.chr_ai.chargeprc = "1";
	// boal <--
	attack.chr_ai.charge = charge;

// ������ ����� ���������� 03.04.21. ���� Dolphin, �� ����������� ��������� ����������.
int iChance = makeint(stf(attack.chr_ai.Osechka) - GetSummonSkillFromName(attack, SKILL_PISTOL)/5 - GetSummonSkillFromName(attack, SKILL_FORTUNE)/10;
if(iChance < 1) iChance = 1;
if (CheckCharacterPerk(attack, "Gunman")) iChance = makeint(stf(attack.chr_ai.Osechka) - GetSummonSkillFromName(attack, SKILL_PISTOL)/5 - GetSummonSkillFromName(attack, SKILL_FORTUNE)/10 - 5;
if (CheckCharacterPerk(attack, "GunProfessional")) iChance = makeint(stf(attack.chr_ai.Osechka) - GetSummonSkillFromName(attack, SKILL_PISTOL)/5 - GetSummonSkillFromName(attack, SKILL_FORTUNE)/10 - 15;
if (CheckCharacterPerk(attack, "Sniper")) iChance = makeint(stf(attack.chr_ai.Osechka) - GetSummonSkillFromName(attack, SKILL_PISTOL)/5 - GetSummonSkillFromName(attack, SKILL_FORTUNE)/10 - 25;
if (CheckCharacterPerk(pchar, "HT4")) iChance = 1;
//if(attack.id == pchar.id) Log_SetStringToLog("����������� ������: " + iChance + " ���������");
if(rand(100) < iChance)
   {
   if(attack.id == pchar.id) Log_SetStringToLog("������!");
   return;
   }
// <-
	//���� ������������, �� ������ �� ������
	if(isFindedEnemy == 0)
	{
		//����� ����� ��������� ������� � ������ �������� ��������
		return;
	}
	// ugeen -> ���������� � ������(27.07.10)
		
	string weaponID = GetCharacterEquipByGroup(attack, GUN_ITEM_TYPE);
	aref weapon;
	Items_FindItem(weaponID, &weapon);	
	
	if(CheckAttribute(attack, "chr_ai.misfire") && sti(attack.chr_ai.misfire) > 0 && rand(100) < sti(attack.chr_ai.misfire) && !HasSubStr(weapon.id, "mushket"))
	{
		LAi_Explosion(attack, rand(20));
  		if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
        TakeItemFromCharacter(attack, weaponID);
		Log_SetStringToLog("��������� ��������� �����! " + GetCharacterFullName(attack.id) + " ��������" + GetSexPhrase("", "�") + " �������.");
		return;
	}
	
	if(CheckAttribute(attack, "chr_ai.explosion" ) && sti(attack.chr_ai.explosion) > 0)
	{	
		float x, y, z;						
		GetCharacterPos(enemy, &x, &y, &z);
		CreateParticleSystemX("blood_shoot", x, y, z, x, y, z, 0);	
		PlayStereoSound("Sea Battles\cannon_fire_03.wav");
	}	
	
	if(CheckAttribute(attack, "chr_ai.multidmg") && sti(attack.chr_ai.multidmg) > 0)
	{
		int num = FindNearCharacters(enemy, 2.5, -1.0, -1.0, 0.001, false, true);
		for (int j = 0; j < num; j++)
		{
			int idx = -1;
			if(CheckAttribute(chrFindNearCharacters[j], "index")) idx = sti(chrFindNearCharacters[j].index);	
			if(idx == -1) continue;
			ref findCh;
			findCh = GetCharacter(idx);	
			if(findCh.chr_ai.group != LAI_GROUP_PLAYER)
			{
				LAi_ApplyCharacterFireDamage(attack, &Characters[idx], kDist );
			}	
			
			if(CheckAttribute(attack, "chr_ai.stun" ) && sti(attack.chr_ai.stun) > 0 && !LAi_IsFightMode(enemy) && !IsMainCharacter(enemy))
			{
				if(CheckAttribute(enemy, "cirassId"))
				{
					if(sti(attack.chr_ai.Stun_C) > 0) 
					{
						LAi_Stunned_StunCharacter(enemy, 10, true);
					}
				}
				else
				{
					if(sti(attack.chr_ai.Stun_NC) > 0) 
					{
						LAi_Stunned_StunCharacter(enemy, 10, true);
					}
				}		
			}			
									
			if( CheckAttribute(attack, "chr_ai.selfdmg" ) && sti(attack.chr_ai.selfdmg) > 0 && findCh.id == attack.id && rand(4) == 1)	
			{
				LAi_ApplyCharacterDamage( &Characters[idx], 10 + rand(sti(weapon.dmg_min) - 10), "fire" );
				if(stf(attack.chr_ai.hp) < 1.0) attack.chr_ai.hp = 1 + makeint(rand(10));
			}
		}
	}

	if(CheckAttribute(attack, "chr_ai.stun" ) && sti(attack.chr_ai.stun) > 0 && !LAi_IsFightMode(enemy) && !IsMainCharacter(enemy))
	{
		if(CheckAttribute(enemy, "cirassId"))
		{
			if(sti(attack.chr_ai.Stun_C) > 0) 
			{
				LAi_Stunned_StunCharacter(enemy, 10, true);
			}
		}
		else
		{		
			if(sti(attack.chr_ai.Stun_NC) > 0) 
			{
				LAi_Stunned_StunCharacter(enemy, 10, true);
			}
		}		
	}
	// <-- ugeen
	
	//������� ���� �� �����
	LAi_group_Attack(attack, enemy);
	//���������� �����������
	LAi_ApplyCharacterFireDamage(attack, enemy, kDist);	
	if(CheckAttribute(attack, "chr_ai.multidmg") && sti(attack.chr_ai.multidmg) > 0)
	{
		if(stf(enemy.chr_ai.hp) < 1.0 && enemy.chr_ai.group == LAI_GROUP_PLAYER) enemy.chr_ai.hp = 5;
		LAi_CheckKillCharacter( enemy );	
	}
	
	//���������� ����
	string func = attack.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Fire";
	call func(attack, enemy, kDist, isFindedEnemy != 0);
	//������� ���� �����
	LAi_group_UpdateTargets(enemy);
	func = enemy.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attacked";
	call func(enemy, attack);
	func = "LAi_type_" + enemy.chr_ai.type + "_CharacterUpdate";
	call func(enemy, 0.0001);
}

bool LAi_tmp_return_bool;
bool LAi_CharacterIsFire()
{
	aref chr = GetEventData();
	string func = chr.chr_ai.tmpl;

	// --> CSM
	if (chr.id == pchar.id)
	{
		if (stf(pchar.chr_ai.charge) >= 1.0)
			pchar.CSM.IsFireNow = true; // ��������� �������, ��������� ������� ����� �������
		else
			csmDA(pchar, "CSM.IsFireNow"); // ��������� �� �������, ����� ����� ������� ����� �������
	}
	// <-- CSM

	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_IsFire";
	LAi_tmp_return_bool = call func(chr);
	return LAi_tmp_return_bool;
}

bool LAi_CharacterIsFight()
{
	aref chr = GetEventData();
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_IsFight";
	LAi_tmp_return_bool = call func(chr);
	return LAi_tmp_return_bool;
}

//==========================================================================================
//Escape events
//==========================================================================================

void LAi_CharacterEscapeSlide()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterEscapeSlide") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_EscapeSlide";
	call func(chr);
}

//==========================================================================================
//Collision events
//==========================================================================================

void LAi_CharacterColThreshold()
{
	//���������
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterColThreshold") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_ColThreshold";
	call func(chr);
}

//==========================================================================================
//Animation events
//==========================================================================================

void LAi_Character_EndAction()
{
	//���������
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_Character_EndAction") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//����������
	func = "LAi_tmpl_" + func + "_EndAction";
	call func(chr);
}


//==========================================================================================
//Dead event
//==========================================================================================

void LAi_Character_Dead_Process(aref chr)
{
	DialogExit();
	LAi_CharacterLogoff(chr);
	if(sti(chr.index) != nMainCharacterIndex)
	{
//navy --> ������ ���
		if (CheckAttribute(chr, "PGGAi"))
		{
			PGG_CheckDead(chr);
		}
//navy <--
		//�������, � ����� ������ ���������
		// boal ����� �� �������
        if (MOD_DEAD_CLEAR == "On" && !CheckAttribute(chr, "DontClearDead") && !CheckAttribute(pchar, "CSM.DontClearDead"))
        {
            PostEvent("LAi_event_Character_Dead", MOD_DEAD_CLEAR_TIME * 1000, "i", chr);
        }
        // ������� ������������ � CharacterDeadProcess
        
		//�������������
		LAi_GenerateFantomFromMe(chr);
		//��������� ������
		LAi_group_CheckGroupQuest(chr);
	}
	else
	{
		//����������...
		if(!LAi_IsBoardingProcess())
		{
			if (loadedLocation.type == "town")
				PostEvent("LAi_event_GameOver", 5000, "s", "town");
			else
			{
				if (loadedLocation.type == "underwater")
					PostEvent("LAi_event_GameOver", 5000, "s", "sea");
				else
					PostEvent("LAi_event_GameOver", 5000, "s", "land");
			}
		}
		else
		{
			PostEvent("LAi_event_GameOver", 5000, "s", "boarding");
		}
	}
}

#event_handler("LAi_event_Character_Dead", "LAi_Character_Dead_Event");
void LAi_Character_Dead_Event()
{
	aref chr = GetEventData();
	if (IsEntity(chr))  //fix
	{
		// boal dead can be searched 14.12.2003 -->
		Dead_DelLoginedCharacter(chr); // ����
		// boal dead can be searched 14.12.2003 <--
		CharacterExitFromLocation(chr);
	}
}

#event_handler("LAi_event_GameOver", "LAi_GameOver");
void LAi_GameOver()
{
	string str = GetEventData();
	GameOver(str);
}



//==========================================================================================
//Internal events
//==========================================================================================

//------------------------------------------------------------------------------------------
//��������� �� ��������� ������ ���������
//------------------------------------------------------------------------------------------

void LAi_Character_TemplateComplite(aref chr, string tmplName)
{

	int index = sti(chr.index);
	PostEvent("LAi_event_Character_TemplateComplite", 1, "ls", index, tmplName);

}

#event_handler("LAi_event_Character_TemplateComplite", "LAi_Character_TemplateComplite_Event");
void LAi_Character_TemplateComplite_Event()
{
	int index = GetEventData();
	string tmpl = GetEventData();
	ref chr = &Characters[index];
	// boal fix -->
	string func = "";
	if ( CheckAttribute(chr, "chr_ai.type"))
	{
	    func = chr.chr_ai.type;
	}
	// boal fix <--
	if(func != "")
	{
		func = "LAi_type_" + func + "_TemplateComplite";
		call func(chr, tmpl);
	}
}

//------------------------------------------------------------------------------------------
//������ ��������
//------------------------------------------------------------------------------------------

void LAi_Character_FreeLocator(aref chr, string group, string locator)
{
	int index = sti(chr.index);
	PostEvent("LAi_event_Character_FreePos", 1, "lss", index, group, locator);
}

#event_handler("LAi_event_Character_FreePos", "LAi_Character_FreePos_Event");
void LAi_Character_FreePos_Event()
{
	int index = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			if(idx != index)
			{
				float dist;
				if(GetCharacterDistByLoc(&Characters[idx], group, locator, &dist))
				{
					if(dist < 0.8)
					{
						string func = Characters[idx].chr_ai.tmpl;
						if(func == "") return;
						//����������
						func = "LAi_tmpl_" + func + "_FreePos";
						call func(&Characters[idx], &Characters[index]);
					}
				}
			}
		}
	}
}


//------------------------------------------------------------------------------------------
//������ �� ������
//------------------------------------------------------------------------------------------

void LAi_Character_NeedDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = chr.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_NeedDialog";
			call func(by, chr);
		}
	}
}

//������ �� ������, ���� ���������� true �� � ���� ������ ����� ������ ������
bool LAi_Character_CanDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		bool isDisable = false;
		if(CheckAttribute(chr, "chr_ai.disableDlg"))
		{
			if(sti(chr.chr_ai.disableDlg) != 0) isDisable = true;
		}
		if(isDisable == false)
		{
			string func = by.chr_ai.type;
			if(func != "")
			{
				func = "LAi_type_" + func + "_CanDialog";
				return call func(by, chr);
			}
		}
	}
	return false;
}

//������ ������
void LAi_Character_StartDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = by.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_StartDialog";
			call func(by, chr);
		}
	}
}

//��������� ������
void LAi_Character_EndDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = by.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_EndDialog";
			call func(by, chr);
		}
	}
}
// ��������� �/�������� �� ������ ��������� ����� ���� ������ (�������)
void LAi_CharacterItemAction()
{
	aref chr = GetEventData();
	string sActionName = GetEventData();
	int nItemIndex = GetEventData();

	switch(sActionName)
	{
	case "reset": LAi_UntieItemFromCharacter(chr,nItemIndex); break;
	case "set": LAi_TieItemToCharacter(chr,nItemIndex); break;
	}
}
void LAi_UntieItemFromCharacter(aref chr, int nItemIndex)
{
	if( nItemIndex<0 ) return;
	SendMessage(chr, "lsl", MSG_CHARACTER_EX_MSG, "UntieItem", nItemIndex);
}
void LAi_TieItemToCharacter(aref chr, int nItemIndex)
{
	if( nItemIndex<0 ) return;

	string sModel = "HandsItems\cup";
	string sLocator = "Saber_hand";

	string sitm = "TiedItems.itm"+nItemIndex;
	if( CheckAttribute(chr,sitm) )
	{
		if( CheckAttribute(chr,sitm+".model") ) {
			sModel = chr.(sitm).model;
		}
		if( CheckAttribute(chr,sitm+".locator") ) {
			sLocator = chr.(sitm).locator;
		}
	}

	SendMessage(chr, "lslss", MSG_CHARACTER_EX_MSG, "TieItem", nItemIndex, sModel, sLocator);
}
