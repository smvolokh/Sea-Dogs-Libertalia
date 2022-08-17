/*

	��������� ���� ����� attackType:
	"fast" ������� �����
	"force" �������
	"round" ��������
	"break" ����������� ����
	"feint" ����� ����� �����


*/

//--------------------------------------------------------------------------------
//Blade parameters
//--------------------------------------------------------------------------------

//��������� ����������� ��� ��������� ��� ����� �������
float LAi_CalcDamageForBlade(aref attack, aref enemy, string attackType, bool isBlocked)
{
	ref rItm; // ������ ����������
	
	float aSkill = LAi_GetCharacterFightLevel(attack);
	float eSkill = LAi_GetCharacterFightLevel(enemy);
	
	rItm = ItemsFromID(GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE));
	
	float bladeDmg = 0.1 * stf(rItm.Attack) + 0.4 * stf(rItm.Attack) * aSkill + stf(rItm.Attack) * fRandSmall(aSkill); 

	if(aSkill < eSkill)
	{
		bladeDmg = bladeDmg * (1.0 + 0.7 * (aSkill - eSkill));
	}
	
	// Warship 27.08.09 ��� ������� �����������
	// ���� ������� ������ ������� (���������� ��������), �� ������ ����� ��� ����� ������
	if(sti(enemy.Rank) > 50)
	{
		bladeDmg = bladeDmg * 45 / sti(enemy.Rank);
	}
	if(CheckAttribute(loadedLocation, "CabinType") && sti(enemy.index) == GetMainCharacterIndex())
	{
		bladeDmg = bladeDmg * (1.0 + stf(attack.rank)/100);
	}
	//���������� � ����������� �� �����
	float kAttackDmg = LAi_GetDamageAttackType(attack, enemy, attackType, rItm, isBlocked);
		
	if(kAttackDmg > 0)  // ����������� boal
	{
		//�������������� ������
		float dmg = bladeDmg * kAttackDmg;

		if(MOD_SKILL_ENEMY_RATE < 5 && sti(enemy.index) == GetMainCharacterIndex())	
		{
			dmg = dmg * (4.0 + MOD_SKILL_ENEMY_RATE) / 10.0;
		}				
		return dmg;
	}
	
	return 0.0;
}

// Ugeen --> ������ ��������� ����������� ��� ������ ����� �����
float LAi_GetDamageAttackType(aref attack, aref enemy, string attackType, ref aBlade, bool isBlocked)
{
	float kAttackDmg = 1.0;
	float bWght  = stf(aBlade.Weight);  // ���
	float bLngth = stf(aBlade.lenght);  // �����
	float bCurv  = stf(aBlade.curve);   // ��������
	float bBlnce = stf(aBlade.Balance); // ������
	string sFencingType = aBlade.FencingType;

	switch(attackType)
	{
		case "fast": 
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 0.0; }
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg =  0.6 * bLngth * bCurv * (0.9 + ( bWght - 2.0)/5.0) * (0.85 + bBlnce/6.67);
					if(CheckCharacterPerk(attack, "HardHitter") && CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 		
					}					
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg =  bLngth * bCurv * (0.85 + (bWght - 2.4)/4.0) * (0.85 + bBlnce/6.67);
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = 0.9 * bLngth * bCurv * (0.85 + (bWght - 3.0)/5.0) * (0.85 + bBlnce/6.67); 
					if(CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}
			}
		break;
		
		case "force": 
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 0.0; }
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg = bLngth/bCurv * (0.9 + (bWght - 2.0)/5.0) * (1.22 - bBlnce * 0.22);
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg = 0.6 * bLngth/bCurv * (0.85 + (bWght - 2.4)/4.0) * (1.22 - bBlnce * 0.22);
					if(CheckCharacterPerk(attack, "HardHitter") && CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = 0.5 * bLngth/bCurv * (0.85 + (bWght - 3.0)/5.0) * (1.22 - bBlnce * 0.22);
					if(CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}				
			}
		break;

		case "round": 
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 0.0; } // --> CheatSurfMenu
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg =  0.6 * bLngth * bCurv * (0.9 + (bWght - 2.0)/5.0);
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg = 0.9 * bLngth * bCurv * (0.85 + (bWght - 2.4)/4.0);
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = 0.7 * bLngth * bCurv * (0.85 + (bWght - 3.0)/5.0);
					if(CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}				
			}
			if(CheckCharacterPerk(attack, "BladeDancer"))
			{
				kAttackDmg = kAttackDmg * 1.3;
			}
		break;
		
		case "break": 
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 1.0; }
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg = 0.7/bLngth * bCurv * (0.9 + (bWght - 2.0)/5.0) * (0.85 + bBlnce/6.67);
					if(CheckCharacterPerk(attack, "HardHitter") && CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg = 0.8/bLngth * bCurv * (0.85 + (bWght - 2.4)/4.0) * (0.85 + bBlnce/6.67);
					if(CheckCharacterPerk(attack, "HardHitter") && CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = bCurv/bLngth * (0.85 + (bWght - 3.0)/5.0) * (0.85 + bBlnce/6.67);
					if(CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}	
				if(CheckCharacterPerk(attack, "HardHitter"))
				{
					kAttackDmg = kAttackDmg * 2.0;
				}	
				if(IsEquipCharacterByArtefact(attack, "indian_4"))
				{
					kAttackDmg = kAttackDmg * 1.25;
				}
				if(IsEquipCharacterByArtefact(enemy, "amulet_4"))
				{
					kAttackDmg = kAttackDmg * 0.85;
				}
				if(IsEquipCharacterByArtefact(enemy, "amulet_3"))
				{
					kAttackDmg = kAttackDmg * 0.90;
				}
				if(IsEquipCharacterByArtefact(attack, "indian_3"))
				{
					kAttackDmg = kAttackDmg * 1.10;
				}
			}
		break;
		
		case "feintc":  // ���� ����� �������� ���� //��������� ����������� �����
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 0.0; } // --> CheatSurfMenu
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg = 0.9/bLngth/bCurv * (0.9 + (bWght - 2.0)/5.0) * (1.22 - bBlnce * 0.22);
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg = 0.4/bLngth/bCurv * (0.85 + (bWght - 2.4)/4.0) * (1.22 - bBlnce * 0.22);
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = 0.4/bLngth/bCurv * (0.85 + (bWght - 3.0)/5.0) * (1.22 - bBlnce * 0.22); 
					if(CheckAttribute(enemy, "chr_ai.energy") && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}							
			}
		break;
	
		case "feint": 
			if(isBlocked && !CheckAttribute(attack, "animal")) { kAttackDmg = 0.0; } // --> CheatSurfMenu
			else
			{
				if(sFencingType == "FencingL")
				{
					kAttackDmg = 0.9/bLngth/bCurv * (0.9 + (bWght - 2.0)/5.0) * (1.22 - bBlnce * 0.22);
				}
				if(sFencingType == "FencingS")
				{
					kAttackDmg = 0.4/bLngth/bCurv * (0.85 + (bWght - 2.4)/4.0) * (1.22 - bBlnce * 0.22);
				}
				if(sFencingType == "FencingH")
				{
					kAttackDmg = 0.4/bLngth/bCurv * (0.85 + (bWght - 3.0)/5.0) * (1.22 - bBlnce * 0.22); 
					if(CheckAttribute(enemy, "chr_ai.energy" ) && !CheckCharacterPerk(enemy, "HT1"))  
					{			
						enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); 
					}
				}				
			}
		break;
	}	
	
	if( !CheckCharacterPerk(enemy, "HT1"))
	{
		enemy.chr_ai.energy = stf(enemy.chr_ai.energy) * isEquippedArtefactUse(attack, "totem_11", 1.0, 0.9); // ������ �������
	}	
	
	return kAttackDmg;
}
// Ugeen <-- ������ ��������� ����������� ��� ������ ����� �����

//��������� ����������� ��� ��������� ��� ����� �������� (������� ��� ����)
float LAi_CalcDamageForMushket(aref attack, aref enemy, string attackType, bool isBlocked)
{
	float min = 10.0;
	float max = 10.0;
			
	LAi_MushketSetDamageMaxMin(attack, ItemsFromID(GetCharacterEquipByGroup(attack, GUN_ITEM_TYPE)), attackType);
		
	if(CheckAttribute(attack, "chr_ai.dmgbldmin"))
	{
		min = stf(attack.chr_ai.dmgbldmin);
	}
	
	if(CheckAttribute(attack, "chr_ai.dmgbldmax"))
	{
		max = stf(attack.chr_ai.dmgbldmax);
	}
	
	float bladeDmg = min + (max - min)*frandSmall(LAi_GetCharacterFightLevel(attack));
	//���������� � ����������� �� ������
	float aSkill = LAi_GetCharacterFightLevel(attack);
	float eSkill = LAi_GetCharacterFightLevel(enemy);
	
    if(aSkill < eSkill)
	{
		bladeDmg = bladeDmg * (1.0 + 0.7 * (aSkill - eSkill));
	}
	
	// Warship 27.08.09 ��� ������� �����������
	// ���� ������� ������ ������� (���������� ��������), �� ������ ����� ��� ����� ������
	if(sti(enemy.Rank) > 50)
	{
		bladeDmg = bladeDmg * 45 / sti(enemy.Rank);
	}
	
	if(CheckAttribute(loadedLocation, "CabinType") && sti(enemy.index) == GetMainCharacterIndex())
	{
		bladeDmg = bladeDmg * (1.0 + stf(attack.rank)/100);
	}
	
	//���������� � ����������� �� �����
	float kAttackDmg = 1.0;
	
	// TO_DO ����������� �� ����� ����������
	switch(attackType)
	{
		case "fast": // ��� ���������  - �������
			if(isBlocked)
			{
				kAttackDmg = 0.0;
			}
			else
			{
				kAttackDmg = 0.7;
			}
			break;
		case "force": // ��� ���������  - �����
			if(isBlocked)
			{
				kAttackDmg = 0.0;
			}
			else
			{
				kAttackDmg = 1.0;
			}
			break;
		case "round": // ��� ���������  - �������
			if(isBlocked)
			{
				kAttackDmg = 0.0;
			}
			else
			{
				kAttackDmg = 0.6;
			}
			if(CheckCharacterPerk(attack, "BladeDancer"))
			{
				kAttackDmg = kAttackDmg * 1.3;
			}
			break;
		case "break": // ��� ���������  - �������
			if(isBlocked)
			{
				kAttackDmg = 1.0;
			}
			else
			{
				kAttackDmg = 3.0 * isEquippedAmuletUse(attack, "indian_4", 1.0, 1.25);
			}
		break;
		
		case "feintc":  // ���� ����� �������� ���� //��������� ����������� �����
			if(isBlocked)
			{
				kAttackDmg = 0.0;
			}
			else
			{
				kAttackDmg = 0.8;
			}
		break;
		
		case "feint": // ��� ���������  - �������
			if(isBlocked)
			{
				kAttackDmg = 0.0;
			}
			else
			{
				kAttackDmg = 0.5;
			}
		break;
	}
	
	if(kAttackDmg > 0)  // ����������� boal
	{
		//�������������� ������
		float dmg = bladeDmg * kAttackDmg;
		
		if(CheckCharacterPerk(attack, "HardHitter") && !CheckCharacterPerk(enemy, "HT1"))  
		{
			if(CheckAttribute(enemy, "chr_ai.energy"))
			{
				enemy.chr_ai.energy = (stf(enemy.chr_ai.energy) * 0.9); //fix
			}
		}
		
		if(!CheckCharacterPerk(enemy, "HT1"))
		{
			enemy.chr_ai.energy = stf(enemy.chr_ai.energy) * isEquippedArtefactUse(attack, "totem_11", 1.0, 0.9); // ������ �������
		}	
		
		if(MOD_SKILL_ENEMY_RATE < 5 && sti(enemy.index) == GetMainCharacterIndex())	
		{
			dmg = dmg * (4.0 + MOD_SKILL_ENEMY_RATE) / 10.0;
		}				
		return dmg;
	}
	
	return 0.0;
}


//��������� ���������� ���� ��� ����� ������
float LAi_CalcExperienceForBlade(aref attack, aref enemy, string attackType, bool isBlocked, float dmg)
{
	//��������� ��������� ����
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));

	switch(attackType)
	{
		case "break":
			if(isBlocked)
			{
				dmg = dmg*1.1;
			}else{
				dmg = dmg*1.2;
			}
		break;
		case "feint":
			dmg = dmg*1.5;
		break;
		case "feintc":
			dmg = dmg*1.5;
		break;
	}
	if (stf(enemy.chr_ai.hp) < dmg)
	{
       dmg = stf(enemy.chr_ai.hp);
	}
	return dmg;
}

//�������, ����������� ��� ������� ��������
float LAi_CalcUseEnergyForBlade(aref character, string actionType)
{
	float energy = 0.0;
	
	switch(actionType)
	{
		case "fast":
			energy = 10.0;
		break;
		case "force":
			energy = 7.0;
		break;
		case "round":
			energy = 18.0;
		break;
		case "break":
			energy = 14.0;
		break;
		case "hit_parry":  // boal fix ��� ������� ������ �� ���������, � ��������� � �������� fgt_hit_parry
			energy = 20.0;
			if(CheckAttribute(character, "animal")) energy = 0.0;
		break;
		case "feintc":
			energy = 7.0; // ������ ��� ������ �����
		break;
	}

	// CheatSurfMenu by Cheatsurfer -->
	if (CheckAttribute(pchar, "CSM.NoEnergyDrain"))
	{
		int iona = GetOfficersIndex(pchar, 1);
		int ionb = GetOfficersIndex(pchar, 2);
		int ionc = GetOfficersIndex(pchar, 3);
		if (character.index == GetMainCharacterIndex() || character.index == iona || character.index == ionb || character.index == ionc)
		{
			if (character.index >= 0) energy = 0.0;
		}
	}
	// CheatSurfMenu by Cheatsurfer <--

	if(energy > 0)  // �����������
	{
		float fSkill = LAi_GetCharacterFightLevel(character);  
		fSkill = (1.0 - (0.3 * fSkill));
		if (CheckAttribute(character,"model.animation") && character.model.animation == "mushketer")
		{	
			ref rItm = ItemsFromID(GetCharacterEquipByGroup(character, GUN_ITEM_TYPE));		
			LAi_MushketSetDamageMaxMin(character, rItm, actionType);	
			if(CheckAttribute(rItm,"Weight"))
			{
				LAi_MushketEnergyType(character, GetEnergyMushketDrain(character, stf(rItm.Weight), LAi_GetMushketFencingType(character) ) );  
			}	
			energy = energy * fSkill * LAi_GetMushketEnergyType(character);  
		}
		else
		{			
			energy = energy * fSkill * LAi_GetBladeEnergyType(character);  
		}	
	}
	
	return energy;
}

float Lai_UpdateEnergyPerDltTime(aref chr, float curEnergy, float dltTime)
{
	float fMultiplier = 1.6666667;

	if(CheckCharacterPerk(chr, "Energaiser")) // ������� ���� ������ � ��
	{
		fMultiplier = fMultiplier * 1.5;
	}
	if(CheckCharacterPerk(chr, "Tireless")) 
	{
		fMultiplier = fMultiplier * 1.15;
	}
	if(CheckCharacterPerk(chr, "HT3")) 
	{
		fMultiplier = fMultiplier * 1.50;
	}	
	float fEnergy;
	fEnergy = curEnergy + dltTime * fMultiplier; 

	return fEnergy;
}

bool CharacterSeeMainCharacter(aref chr)
{
	bool CantSee = true;
	
	int num = FindNearCharacters(chr, 30.0, -1.0, 180.0, 0.1, true, true);
	if(num > 0)
	{
		for(int i = 0; i < num; i++)
		{
			if(GetMainCharacterIndex() == sti(chrFindNearCharacters[i].index))
			{
				CantSee = false;
			}
		}
	}
	
	return CantSee;
}

bool IsAnotherCharactersAroundRadius(aref chr, float radius)
{
	bool characters = false;
	int num = FindNearCharacters(chr, radius, -1.0, -1.0, 0.001, false, true);
	
	if(num > 0) characters = true;
	return characters;
}

//--------------------------------------------------------------------------------
//Gun parameters
//--------------------------------------------------------------------------------

//��������� ����������� ���������
float LAi_GunCalcProbability(aref attack, aref enemy, float kDist)
{
	//���� ������, �� ������ �����
	if(kDist >= 0.9) return 1.0;
	//��������� ����������� �� ����� �������
	float pmin = 0.3;
 	if(CheckAttribute(attack, "chr_ai.accuracy")) // boal ��� �������� ������ ���������, � �� ����!
	{
		pmin = stf(attack.chr_ai.accuracy);
	}
 	//�������� ������� �� �����
	// boal -->
	float aSkill = LAi_GetCharacterGunLevel(attack);
	// boal <--

	pmin = pmin + 0.3*aSkill;

	//����������� ��������� � ������� �������
	float p = pmin + (1.0 - pmin)*(kDist/0.9);
 	//������ �������
	if(IsCharacterPerkOn(attack, "GunProfessional"))
	{
		p = p + 0.25;
	}
	else
	{
		if(IsCharacterPerkOn(attack, "Gunman"))
		{
			p = p + 0.1;
		}
	}
	if(!IsDay() && IsEquipCharacterByArtefact(attack, "totem_12")) p = p * 2;
	
	if(IsEquipCharacterByArtefact(attack, "indian_2")) p = p * 1.15;
	if(IsEquipCharacterByArtefact(enemy,  "indian_1")) p = p * 1.10;
	if(IsEquipCharacterByArtefact(attack, "amulet_1")) p = p * 0.90;
	if(IsEquipCharacterByArtefact(enemy,  "amulet_2")) p = p * 0.85;
	
	// ���� ����� ������ 1 - ����� 100% �����
	return p;
}

//�������� ����������� �� ���������
float LAi_GunCalcDamage(aref attack, aref enemy)
{
	//����������� �����������
	float min = 10.0;
	float max = 10.0;
	
	//string sGun = GetCharacterEquipByGroup(attack, GUN_ITEM_TYPE);
	//ref rItm = ItemsFromID(sGun);
	string sBullet = LAi_GetCharacterBulletType(attack);
	
	if(sBullet == "powder_pellet") LaunchBlastPellet(enemy);
	if(sBullet == "grenade") LaunchBlastGrenade(enemy);
	
	if(CheckAttribute(enemy, "cirassId"))
	{
		min = stf(attack.chr_ai.DmgMin_C);
		max = stf(attack.chr_ai.DmgMax_C);
		
		if(stf(attack.chr_ai.EnergyP_C) > 0.0 )
		{
			if(sBullet != "powder_pellet")	Lai_CharacterChangeEnergy(enemy, -stf(attack.chr_ai.EnergyP_C));
			else
			{
				if(enemy.chr_ai.group != LAI_GROUP_PLAYER) Lai_CharacterChangeEnergy(enemy, -stf(attack.chr_ai.EnergyP_C));
			}
		}	
	}
	else
	{
		min = stf(attack.chr_ai.DmgMin_NC);
		max = stf(attack.chr_ai.DmgMax_NC);
		
		if(stf(attack.chr_ai.EnergyP_NC) > 0.0)
		{
			if(sBullet != "powder_pellet") Lai_CharacterChangeEnergy(enemy, -stf(attack.chr_ai.EnergyP_NC));
			else
			{
				if(enemy.chr_ai.group != LAI_GROUP_PLAYER) Lai_CharacterChangeEnergy(enemy, -stf(attack.chr_ai.EnergyP_C));
			}
		}	
	}

	if (IsCharacterPerkOn(attack, "HT4") && enemy.chr_ai.group != LAI_GROUP_PLAYER) 
	{
		Lai_CharacterChangeEnergy(enemy, -(rand(20) + 20));
	}	
	
	//��������� �����
	float aSkill = LAi_GetCharacterGunLevel(attack);
	float eSkill = LAi_GetCharacterLuckLevel(enemy); // good luck
	
	float dmg = min + (max - min)*frandSmall(aSkill);

	if (MOD_SKILL_ENEMY_RATE < 5 && sti(enemy.index) == GetMainCharacterIndex())	
	{
		dmg = dmg * (4.0 + MOD_SKILL_ENEMY_RATE) / 10.0;
	}
	
	if(IsEquipCharacterByArtefact(attack, "indian_1")) dmg += 15;
	if(IsEquipCharacterByArtefact(enemy,  "indian_2")) dmg *= 1.1;
	if(IsEquipCharacterByArtefact(enemy,  "amulet_1")) dmg -= 15;
	if(IsEquipCharacterByArtefact(attack, "amulet_2")) dmg *= 0.9;
	if(IsEquipCharacterByArtefact(attack, "KhaelRoa_item")) dmg = dmg*10; // �������
		
	if (CheckAttribute(attack, "MultiShooter")) // ����������� // Addon-2016 Jason
	{
		dmg = dmg*stf(attack.MultiShooter);
	}
		
	// ������ �������� ��������� - ����� ������ �� �������� � �������� 210712
	if (enemy.chr_ai.group == "KSOCHITAM_MONSTERS")
	{
		dmg = dmg/6;
	}
	if (CheckAttribute(enemy, "monster"))
	{
	dmg = dmg/4;
	}
	if (CheckAttribute(enemy, "GuardMask"))
	{
		dmg = 0;
		if (attack.id == "Blaze") log_info("���� ���� ��������� ������ ������!");
	}
	// �������
	bool bTutt = (IsCharacterEquippedArtefact(pchar, "kaleuche_amulet2")) || (IsCharacterEquippedArtefact(pchar, "kaleuche_amulet3"))
	if (CheckAttribute(enemy, "KhaelRoaMonster") && !bTutt)
	{
		dmg = 0.0;
		if (attack.id == "Blaze") log_info("���� ���� �� ������� ����� ��������!");
	}
	if (CheckAttribute(attack, "KhaelRoaMonster") && !bTutt) 
	{
		dmg = dmg*5;
	}
		
	return dmg;
}

//��������� ���������� ���� ��� ��������� �� ���������
float LAi_GunCalcExperience(aref attack, aref enemy, float dmg)
{
    //��������� ��������� ����
	float ra = 1.0;
	float re = 1.0;
	if(CheckAttribute(attack, "rank"))
	{
		ra = stf(attack.rank);
	}
	if(CheckAttribute(enemy, "rank"))
	{
		re = stf(enemy.rank);
	}
	if(ra < 1.0) ra = 1.0;
	if(re < 1.0) re = 1.0;
	dmg = dmg*((1.0 + re*0.5)/(1.0 + ra*0.5));
	if (stf(enemy.chr_ai.hp) < dmg)
	{
       dmg = stf(enemy.chr_ai.hp);
	}
    return dmg;
}

//��������� ������� �������� ����������� ���������
float LAi_GunReloadSpeed(aref chr)
{
	//������� ������� ��������� �������� �������
	float charge_dlt = LAI_DEFAULT_DLTCHRG;
	if(CheckAttribute(chr, "chr_ai.charge_dlt"))
	{
		charge_dlt = stf(chr.chr_ai.charge_dlt);
	}
	//������������ ������
	// boal -->
	float skill = LAi_GetCharacterGunLevel(chr);
	// boal <--

	charge_dlt = charge_dlt*(1.0 + 0.3*skill);//boal
	//����� �������
	if (CheckAttribute(chr, "MultiShooter")) charge_dlt = charge_dlt*2.00; // may-16
	if(IsCharacterPerkOn(chr, "Sniper")) charge_dlt = charge_dlt*1.35;	// ���������!!
	if(IsCharacterPerkOn(chr, "HT4")) charge_dlt = charge_dlt*1.45;	// ���������!!
	if(IsCharacterPerkOn(chr, "GunProfessional"))
	{
		charge_dlt = charge_dlt*1.25;
	}else{
		if(IsCharacterPerkOn(chr, "Gunman"))
		{
			charge_dlt = charge_dlt*1.1;
		}
	}
	return charge_dlt;
}


//--------------------------------------------------------------------------------
//Calculate total
//--------------------------------------------------------------------------------

//���������� ����������� ��� ����� �����
void LAi_ApplyCharacterAttackDamage(aref attack, aref enemy, string attackType, bool isBlocked, bool Silence)
{
	//���� �����������, �� ��������� ���
	if(CheckAttribute(enemy, "chr_ai.immortal"))
	{
		if(sti(enemy.chr_ai.immortal) != 0)
		{
			return;
		}
	}
	//��������� �����������
	float dmg;
	if (attack.model.animation == "mushketer")
	{
		dmg = LAi_CalcDamageForMushket(attack, enemy, attackType, isBlocked);
	}
	else
	{
		dmg = LAi_CalcDamageForBlade(attack, enemy, attackType, isBlocked);
	}
	float critical 	= 0.0;
	float chance 	= 1.0;
	
	if(IsEquipCharacterByArtefact(attack, "indian_3")) chance = 1.15;
	if(IsEquipCharacterByArtefact(enemy,  "indian_4")) chance = 1.10;
	if(IsEquipCharacterByArtefact(enemy,  "amulet_3")) chance = 0.85;
	if(IsEquipCharacterByArtefact(attack, "amulet_4")) chance = 0.90;
	// ��� ��� ���� ������� � ����
	// ����������� ������� �� 50% ������ �����
	float poisondmg1 = 1.0;
	if(LAi_IsPoison(attack))
	{
		poisondmg1 = 0.5;
	}
	
	// � �������� �� 50% ������
	float poisondmg2 = 1.0;
	if(LAi_IsPoison(enemy))
	{
		poisondmg2 = 1.5;
	}
	
	// Rasteador: ���������� ������ �������
	// ������ ---->
	
	// ������ ����������� ����������� HP � MaxHP
	int attackcheckhp = (LAi_GetCharacterHP(attack)/LAi_GetCharacterMaxHP(attack))*100;
	int enemycheckhp = (LAi_GetCharacterHP(enemy)/LAi_GetCharacterMaxHP(enemy))*100;
	
	// ����������� ���������
	float hpdamageA = 1.0;
	float hpdamageE = 1.0;
	
	float strdmg = 1.0;

	if(attackcheckhp >= 70) 
	{
		hpdamageA = 1.0; // ���� �� ������ 70% - ������� ������ ����
	}
	else
	{
		if(attackcheckhp < 70 && attackcheckhp >= 50) 
		{
			hpdamageA = 0.8; // ���� �� ������ 50%, �� ������ 70% - ������� �� 20% ������ �����
		}
		else
		{
			if(attackcheckhp < 50 && attackcheckhp >= 20)
			{
				hpdamageA = 0.6; // ���� �� ������ 20%, �� ������ 50% - ������� �� 40% ������ �����
			}
			else
			{
				if(attackcheckhp < 20) 
				{
					hpdamageA = 0.4; // ���� �� ������ 20% - ������� �� 60% ������ �����
				}
			}			
		}
	}
	
	if(enemycheckhp >= 70) 
	{
		hpdamageE = 1.0; // ���� �� ������ 70% - �������� ������� ����
	}
	else
	{
		if(attackcheckhp < 70 &&enemycheckhp >= 50) 
		{
			hpdamageE = 1.1; // ���� �� ������ 50%, �� ������ 70% - �������� �� 10% ������ �����
		}
		else
		{
			if(attackcheckhp < 50 && enemycheckhp >= 20) 
			{
				hpdamageE = 1.3; // ���� �� ������ 20%, �� ������ 50% - �������� �� 30% ������ �����
			}
			else
			{
				if(enemycheckhp < 20) 
				{
					hpdamageE = 1.5; // ���� �� ������ 20% - �������� �� 50% ������ �����
				}
			}
		}
	}
	
	// ����� <----

	dmg = dmg*poisondmg1*poisondmg2*hpdamageA*hpdamageE*strdmg; // ��� ��� ������ �����
	//����� ����� ������

	// ��� 1.2.3
	if(IsCharacterPerkOn(attack, "SwordplayProfessional"))
	{
		if(rand(100) <= makeint(15 * chance)) // ������ 100. ���� 15
		{
			critical = 1.0;
			//Log_Info("������� ����������� ����!");
		}
	}else
	{
		if(IsCharacterPerkOn(attack, "CriticalHit"))
		{
			if(rand(100) <= makeint(5 * chance)) // ������ 100 ,���� 5
			{
				critical = 1.0;
				//Log_Info("������� ����������� ����!");
			}
		}
	}

	float kDmg = 1.0;
	if(IsCharacterPerkOn(attack, "Rush"))
	{
		kDmg = 4.0;
	}
	float kDmgRush = 1.0;
	if(IsCharacterPerkOn(enemy, "Rush"))
	{
		kDmgRush = 0.5;
	}
	if(IsCharacterPerkOn(attack, "Sliding"))
	{
		kDmg = 2.0;
	}
	float kDmgSliding = 1.0;
	if(IsCharacterPerkOn(enemy, "Sliding"))
	{
		kDmgSliding = 0.75;
	}
	dmg = dmg*kDmg*kDmgRush*kDmgSliding;
	// ����� ���������� 09.03.20 ������ ����� ������ ������� �������, ������ - ��������� ������� (������ � ��������� ��������). ������� ������� .monster ������ ���, ���� ������ �� monsters
		bool bMonster = (CheckAttribute(enemy, "monster")) || (enemy.chr_ai.group == LAI_GROUP_MONSTERS)
		if (GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "knife_01" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_32" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade48" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "newblade29" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_33" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_36" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade300" && bMonster)
	{
	dmg = dmg*3;
	else dmg = dmg/3;
	}
	// ����� ���������� 09.03.20 ������ �������� ��������� - ����� ������ ������� �������, ������ - ��������� ������� (������ � ��������� ��������)
	if (enemy.chr_ai.group == "KSOCHITAM_MONSTERS")
	{
		if (GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "knife_01" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_32" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade48" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "newblade29" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_33" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_36" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade300") dmg = dmg*4;
	else dmg = dmg/4;
	}
	if (CheckAttribute(attack, "MultiFighter")) // ������������
	{
		dmg = dmg*stf(attack.MultiFighter);
	}
	if (CheckAttribute(enemy, "GuardMask") && GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) != "knife_01")
	{
		dmg = 0.0;
		if (attack.id == "Blaze") log_info("���� ������ ��������� ������ ������!");
	}
	// �������
	bool bTutt = (IsCharacterEquippedArtefact(pchar, "kaleuche_amulet2")) || (IsCharacterEquippedArtefact(pchar, "kaleuche_amulet3"))
	if (CheckAttribute(enemy, "KhaelRoaMonster") && !bTutt)
	{
		dmg = 0.0;
		if (attack.id == "Blaze") log_info("���� ������ �� ������� ����� ��������!");
	}
	if (CheckAttribute(attack, "KhaelRoaMonster") && !bTutt) 
	{
		dmg = dmg*5;
	}
	//����� ����� ������
	bool noExp = false;
	if(CheckAttribute(attack, "chr_ai.group") && CheckAttribute(enemy, "chr_ai.group"))
	{
		if(attack.chr_ai.group == enemy.chr_ai.group)
		{
			dmg = 0.0;
			critical = 0.0;
			noExp = true;
		}
		//Jason: ����������� ������ TMP_FRIEND: ��������� ������������� ������, �������� ��������� �� ������, ����� ������ LAI_GROUP_PLAYER, ���� ���� �������� �� � ���-�� �������� �� ������ ������
		if(enemy.chr_ai.group == LAI_GROUP_PLAYER && attack.chr_ai.group == "Tmp_friend")
		{
				dmg = 0.0;
				critical = 0.0;
				noExp = true;
		}
		if(attack.chr_ai.group == LAI_GROUP_PLAYER && enemy.chr_ai.group == "TMP_FRIEND")
		{
				dmg = 0.0;
				critical = 0.0;
				noExp = true;
		}
	}
	//Jason: ����� ����� ���� � ����� �� ��������� �������� �����
	if(CheckAttribute(attack, "LSC_clan") && CheckAttribute(enemy, "LSC_clan"))
	{
		dmg = 0.0;
		critical = 0.0;
		noExp = true;
	}
	if(isBlocked == true)// ����
	{  
	  if (MOD_SKILL_ENEMY_RATE <= 2)  // ��
	  {	 
	    if(rand(100) < 51)
	    {	  
		critical = 0;
		//Log_Info("���� ������������ ����������� ����");
	    }
	  }	
	  if (MOD_SKILL_ENEMY_RATE <= 4) // ��
	  {	 
	    if(rand(100) < 41)
	    {	  
		critical = 0;
		//Log_Info("���� ������������ ����������� ����");
	    }
	  } 	
      if (MOD_SKILL_ENEMY_RATE <= 6) // ��
	  {	 
	    if(rand(100) < 31)
	    {	  
		critical = 0;
		//Log_Info("���� ������������ ����������� ����");
	    }		
      }	
      if (MOD_SKILL_ENEMY_RATE > 7) // �� � �� 
	  {	 
	    if(rand(100) < 16)
	    {	  
		critical = 0;
		//Log_Info("���� ������������ ����������� ����");
	    }		
      }			  
	}
	
	if (CheckAttribute(enemy, "cirassId") && critical > 0.0 && CheckAttribute(&Items[sti(enemy.cirassId)],"critical"))
	{	
	 if(makeint(stf(Items[sti(enemy.cirassId)].critical) * 1001) > rand(1000))
     {			
	     critical = 0.0;
		//Log_Info("����������� ���� ������������ ��������");
	 }
	}
	if(critical > 0.0)
	{
        AddCharacterExpToSkill(attack, SKILL_FORTUNE, 5);
		critical += GetCharacterSPECIALSimple(attack, SPECIAL_L)*0.05;
		if(sti(attack.index) == GetMainCharacterIndex())
		{
			Log_SetStringToLog(XI_ConvertString("Critical Hit"));
			//Log_TestInfo(" " + critical + " �����");
		}
	}
	kDmg = 1.0;
	if(IsCharacterPerkOn(enemy, "BasicDefense")) kDmg = 0.9;
	if(IsCharacterPerkOn(enemy, "AdvancedDefense")) kDmg = 0.8;
	if(IsCharacterPerkOn(enemy, "ProfessionalDefense")) kDmg = 0.7;
	if(IsCharacterPerkOn(enemy, "SwordplayProfessional")) kDmg = 0.6;

	// ��� 1.2.3
	dmg = dmg*kDmg;
	dmg = dmg *(1 + critical);//dmg + critical;
	if(CheckAttribute(enemy, "cirassId"))
	{
		dmg = dmg * (1.0 - stf(Items[sti(enemy.cirassId)].B_CirassLevel));
		
		if(CheckCharacterPerk(enemy, "HT3") && GetCharacterSuitType(enemy) == 2)
		{
			dmg = dmg * 0.80;
		}
		if(CheckCharacterPerk(enemy, "HT1") && GetCharacterSuitType(enemy) == 1 )
		{
			dmg = dmg * 0.65;	
		}
	}	
	// �������
	if(IsCharacterEquippedArtefact(enemy, "kaleuche_amulet3"))
	{
		dmg = dmg * 0.75;
	}
	if(dmg > 0.0)
	{
		//������� �����������
		LAi_ApplyCharacterDamage(enemy, MakeInt(dmg + 0.5), "fight");

	                   if(IsEquipCharacterByItem(attack, "blade301")) // ������ �������
	                  {
	                   //LAi_ClawBeliar(attack, 10+rand(15), "fire");
                                      LAi_ClawBeliar(attack, enemy, 10+rand(15));
	                   enemy.chr_ai.Beliarfire = 1;
	                   }
		if(Silence)
		{
		float silencemodificator = 5.0 + (10.0 * (makefloat(GetSummonSkillFromName(attack, SKILL_SNEAK)) / 100.0));
			
			dmg = dmg * silencemodificator;
			AddCharacterExpToSkill(attack, SKILL_SNEAK, makeint(stf(enemy.rank)*2.5));
			Log_Info("�������� �����!");
		}
		//�������� �� ������
		LAi_CheckKillCharacter(enemy);
		//�������� �� ����������
		if(!IsCharacterEquippedArtefact(enemy, "talisman8")) MakePoisonAttackCheckSex(enemy, attack);
		// �� ����� // Addon 2016-1 Jason ��������� �������
		if(IsCharacterEquippedArtefact(attack, "indian_poison") && !CheckAttribute(pchar, "IsMushketer")) MakeIndianPoisonAttack(enemy, attack);
	}
	//���� �� ������ � ����
	bool isSetBalde = (CheckAttribute(enemy, "equip.blade") == true);//(SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//��������� �����
	float exp = LAi_CalcExperienceForBlade(attack, enemy, attackType, isBlocked, dmg);
	if(LAi_IsDead(enemy))
	{
		// boal  check skill -->
		float ra = 1.0;
	    float re = 1.0;
	    if(CheckAttribute(attack, "rank"))
	    {
	       ra = stf(attack.rank);
	    }
	    if(CheckAttribute(enemy, "rank"))
	    {
	       re = stf(enemy.rank);
	    }
		if (attack.model.animation == "mushketer")
		{
			if (CheckAttribute(enemy, "City")) AddCharacterExpToSkill(attack, LAi_GetMushketFencingType(attack), makefloat((10.0 + ((1 + re) / (1+ra))*6.5)/20));	
			else AddCharacterExpToSkill(attack, LAi_GetMushketFencingType(attack), makefloat(10.0 + ((1 + re) / (1+ra))*6.5));			
		}
		else
		{
			if (CheckAttribute(enemy, "City")) AddCharacterExpToSkill(attack, LAi_GetBladeFencingType(attack), makefloat((10.0 + ((1 + re) / (1+ra))*6.5)/20));
			else AddCharacterExpToSkill(attack, LAi_GetBladeFencingType(attack), makefloat(10.0 + ((1 + re) / (1+ra))*6.5));	
		}	
        AddCharacterExpToSkill(attack, SKILL_DEFENCE, 1);
        AddCharacterExpToSkill(attack, SKILL_FORTUNE, 1);
        AddCharacterExpToSkill(attack, SKILL_LEADERSHIP, 1);
        // boal <--
        // boal statistic info 17.12.2003 -->
        Statistic_KillChar(attack, enemy, "_s");
        // boal statistic info 17.12.2003 <--
       	LAi_SetResultOfDeath(attack, enemy, isSetBalde, Silence);

//������� ������������ ������� ����� ���������� 30.07.20. ���� �� �������: New abilities, �� ����������� ��������� ����������.
		if (GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "knife_01" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_32" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade48" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "newblade29" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_33" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade_36" || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) == "blade300" && enemy.sex == "skeleton")
		{
		int healthup = 50 + rand(150);
		float healthhp = healthup + LAi_GetCharacterHP(attack);
	if(attack.id == pchar.id) Log_SetStringToLog("������������ ������ ������������ ��� " + healthup + " ��������");
			LAi_SetHP(attack, healthhp, LAi_GetCharacterMaxHP(attack));
		}
	}
	if(!isSetBalde)
	{
		exp = 0.0;
	}
	
	if (!noExp)
    {
        //AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5));
		if (attack.model.animation == "mushketer")
		{
			if (CheckAttribute(enemy, "City")) AddCharacterExpToSkill(attack, LAi_GetMushketFencingType(attack), Makefloat(exp*0.02));
			else AddCharacterExpToSkill(attack, LAi_GetMushketFencingType(attack), Makefloat(exp*0.2));
		}
		else
		{
			if (CheckAttribute(enemy, "City")) AddCharacterExpToSkill(attack, LAi_GetBladeFencingType(attack), Makefloat(exp*0.02));
			else AddCharacterExpToSkill(attack, LAi_GetBladeFencingType(attack), Makefloat(exp*0.2));
		}	
    }
	
}
//boal 19.09.05 -->
void LAi_SetResultOfDeath(ref attack, ref enemy, bool isSetBalde, bool Silence)
{
    if (sti(attack.index) == GetMainCharacterIndex() && !Silence)
    {
		if (CheckCharacterItem(pchar, "HolTradeLicence") && CheckAttribute(enemy, "City") && sti(enemy.nation) == HOLLAND) // Jason: ������� ��������
		{
			TakeNationLicence(HOLLAND);
			log_info("�������� �������� ������������!");
		}
		if (CheckAttribute(enemy, "City") && sti(enemy.nation) == PIRATE) 
		{
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+1;
			log_testinfo("��������� � ������� ���������� � ����� "+sti(pchar.GenQuest.Piratekill)+"");
		}
		if (CheckAttribute(enemy, "LSC_clan")) // Jason: ����� ������
		{
			DoQuestCheckDelay(enemy.chr_ai.group+"Conflict", 0.5);
		}
		if (findsubstr(enemy.model, "canib" , 0) != -1) // Jason: ��������� ��������
		{
			ChangeIndianRelation(-0.5);
		}
		if (findsubstr(enemy.model, "miskito" , 0) != -1)
		{
			ChangeIndianRelation(-1.0);
		}
		if (findsubstr(enemy.model, "squaw" , 0) != -1)
		{
			ChangeIndianRelation(-2.5);
		}
		if (GetRelation2BaseNation(sti(enemy.nation)) == RELATION_ENEMY)
		{
			if (!isSetBalde)
			{
				LAi_ChangeReputation(attack, -1);   // to_do
			if (CheckAttribute(enemy, "City"))
			{
				ChangeCharacterHunterScore(attack, NationShortName(sti(enemy.nation)) + "hunter", 2);
			}
		}
		}
		else
		{
			if (CheckAttribute(enemy, "City"))
			{
				ChangeCharacterHunterScore(attack, NationShortName(sti(enemy.nation)) + "hunter", 3);
			}
		}
		// ����� ����� �� �������� � ������ boal 19.09.05
  		if (CheckAttribute(enemy, "City"))
		{
			// ����� �������� �� ����� � ������
			if (GetSummonSkillFromName(attack, SKILL_SNEAK) < rand(140)) // ����������
			{
			    SetNationRelation2MainCharacter(sti(enemy.nation), RELATION_ENEMY);
		    }
		}
	}
}
// boal <--

//���������� ����������� ��� ���������
void LAi_ApplyCharacterFireDamage(aref attack, aref enemy, float kDist)
{
	Lai_CharacterChangeEnergy(attack, -4); // ���� ������� �� ������� boal 20/06/06
	//���� �����������, �� ��������� ���
	if(CheckAttribute(enemy, "chr_ai.immortal"))
	{
		if(sti(enemy.chr_ai.immortal) != 0)
		{
			return;
		}
	}
	//����������� ���������
	float p = LAi_GunCalcProbability(attack, enemy, kDist);
	//���� ������������, �� ������
	if(rand(10000) > p*10000) return;	  
	// boal 23.05.2004 <--
	//��������� �����������
	float damage = LAi_GunCalcDamage(attack, enemy);

	//������ ����� ������
	bool noExp = false;
	if(CheckAttribute(attack, "chr_ai.group"))
	{
		if(CheckAttribute(enemy, "chr_ai.group"))
		{
			if(attack.chr_ai.group == enemy.chr_ai.group)
			{
				damage = 0.0;
				noExp = true;
			}
			//Jason: ����������� ������ TMP_FRIEND: ��������� ������������� ������, �������� ��������� �� ������, ����� ������ LAI_GROUP_PLAYER, ���� ���� �������� �� � ���-�� �������� �� ������ ������
			if(enemy.chr_ai.group == LAI_GROUP_PLAYER && attack.chr_ai.group == "TMP_FRIEND")
			{
					damage = 0.0;
					noExp = true;
			}
			if(attack.chr_ai.group == LAI_GROUP_PLAYER && enemy.chr_ai.group == "TMP_FRIEND")
			{
					damage = 0.0;
					noExp = true;
			}
		}
	}
	//Jason: ����� ����� ���� � ����� �� ��������� �������� �����
	if(CheckAttribute(attack, "LSC_clan") && CheckAttribute(enemy, "LSC_clan"))
	{
		damage = 0.0;
		noExp = true;
	}
	if(CheckAttribute(enemy, "cirassId"))
	{
		damage = damage * (1.0 - stf(Items[sti(enemy.cirassId)].G_CirassLevel));
		if(CheckCharacterPerk(enemy, "HT3") && GetCharacterSuitType(enemy) == 2 )
		{
			damage = damage * 0.80;
		}
		if(CheckCharacterPerk(enemy, "HT1") && GetCharacterSuitType(enemy) == 1 )
		{
			damage = damage * 0.65;	
		}		
	}
	// �������
	if(IsCharacterEquippedArtefact(enemy, "kaleuche_amulet3"))
	{
		damage = damage * 0.75;
	}
	if(damage > 0.0)
		{
		if(CheckCharacterPerk(attack, "Sniper"))
		{
		int iRand = rand(100);
		if(iRand < 20)
		{
		damage = damage * 3.0;
   		if(attack.id == pchar.id) Log_Info("������� �������!");
	}
}
	LAi_ApplyCharacterDamage(enemy, MakeInt(damage + 0.5), "fire");	
		
		//�������� �� ������
		LAi_CheckKillCharacter(enemy);
		// �� ����� // Addon 2016-1 Jason ��������� �������
		if(IsCharacterEquippedArtefact(attack, "indian_poison")) MakeIndianPoisonAttack(enemy, attack);
	}
	//���� �� ������ � ����
	bool isSetBalde = (CheckAttribute(enemy, "equip.blade") == true);//(SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
	//��������� ����
	float exp = LAi_GunCalcExperience(attack, enemy, damage);
	
	if(LAi_IsDead(enemy))
	{
		// boal skill -->
		float ra = 1.0;
	    float re = 1.0;
	    if(CheckAttribute(attack, "rank"))
	    {
	       ra = stf(attack.rank);
	    }
	    if(CheckAttribute(enemy, "rank"))
	    {
	       re = stf(enemy.rank);
	    }
        if (CheckAttribute(enemy, "City"))
		{
			AddCharacterExpToSkill(attack, SKILL_PISTOL, makefloat((15.0 + ((1 + re) / (1+ra))*12.0)/20));
		}
		else
		{
			AddCharacterExpToSkill(attack, SKILL_PISTOL, makefloat(15.0 + ((1 + re) / (1+ra))*12.0));
			AddCharacterExpToSkill(attack, SKILL_DEFENCE, 1);
			AddCharacterExpToSkill(attack, SKILL_FORTUNE, 2);
			AddCharacterExpToSkill(attack, SKILL_LEADERSHIP, 1);
		}
		// boal skill <--
		// boal statistic info 17.12.2003 -->
        Statistic_KillChar(attack, enemy, "_g");
        // boal statistic info 17.12.2003 <--        
        //�������� �� ��������
  	LAi_SetResultOfDeath(attack, enemy, isSetBalde, false);

	}
	if(!isSetBalde)
	{
		exp = 0.0;
	}
	if(!noExp)
    {
       if (CheckAttribute(enemy, "City")) AddCharacterExpToSkill(attack, SKILL_PISTOL, Makefloat(exp*0.1));
        else AddCharacterExpToSkill(attack, SKILL_PISTOL, Makefloat(exp*0.85));
    }
}

float LAi_NPC_GetAttackPreferenceWeight(aref chr, string attackType, float fOff, float fOn)
{
	if(LAi_GetBladeFencingType(chr) == attackType) return fOn; 
	return fOff;
}

//--------------------------------------------------------------------------------
//��������� NPC
//--------------------------------------------------------------------------------

float npc_return_tmp;
bool npc_return_tmpb;

//�����
//�������� ���������� ����������� ����� � �������  p > 0
#event_handler("NPC_Event_GetAttackActive","LAi_NPC_GetAttackActive");
float LAi_NPC_GetAttackActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	npc_return_tmp = 0.3 + level*0.7;
	npc_return_tmp = npc_return_tmp + 0.1;
	return npc_return_tmp;
}

//��� ������ ����� "fast", 0 - ������� �� ��������
#event_handler("NPC_Event_GetAttackWeightFast","LAi_NPC_GetAttackWeightFast");
float LAi_NPC_GetAttackWeightFast()
{
	aref chr = GetEventData();
	npc_return_tmp = 20.0 * LAi_NPC_GetAttackPreferenceWeight(chr, "FencingL", 1.0, 3.0);
	npc_return_tmp = npc_return_tmp * LAi_NPC_GetAttackPreferenceWeight(chr, "FencingH", 1.0, 0.5);
	npc_return_tmp = npc_return_tmp * (0.8 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//��� ������ ����� "force", 0 - ������� �� ��������
#event_handler("NPC_Event_GetAttackWeightForce","LAi_NPC_GetAttackWeightForce");
float LAi_NPC_GetAttackWeightForce()
{
	aref chr = GetEventData();
	npc_return_tmp = 50.0 * LAi_NPC_GetAttackPreferenceWeight(chr, "FencingS", 1.0, 3.0);
	npc_return_tmp = npc_return_tmp * (0.8 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//��� ������ ����� "round", 0 - ������� �� ��������, ���� ������ <3 �� ���� �� ����������
#event_handler("NPC_Event_GetAttackWeightRound","LAi_NPC_GetAttackWeightRound");
float LAi_NPC_GetAttackWeightRound()
{
	aref chr = GetEventData();
	npc_return_tmp = 20.0;
	npc_return_tmp = npc_return_tmp * (0.8 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//��� ������ ����� "break", 0 - ������� �� ��������
#event_handler("NPC_Event_GetAttackWeightBreak","LAi_NPC_GetAttackWeightBreak");
float LAi_NPC_GetAttackWeightBreak()
{
	aref chr = GetEventData();
	npc_return_tmp = 20.0 * LAi_NPC_GetAttackPreferenceWeight(chr, "FencingH", 1.0, 3.0);
	npc_return_tmp = npc_return_tmp * LAi_NPC_GetAttackPreferenceWeight(chr, "FencingL", 1.0, 0.5);
	npc_return_tmp = npc_return_tmp * (0.6 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//��� ������ ����� "feint", 0 - ������� �� ��������
#event_handler("NPC_Event_GetAttackWeightFeint","LAi_NPC_GetAttackWeightFeint");
float LAi_NPC_GetAttackWeightFeint()
{
	aref chr = GetEventData();
	npc_return_tmp = 10.0; //30 boal fix
	npc_return_tmp = npc_return_tmp * (0.6 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//���������� ������
//����������� ������� ��������� - ����� � ����� ������������ �������� 2 ���� � �������
#event_handler("NPC_Event_GetDefenceActive","LAi_NPC_GetAttackDefence");
float LAi_NPC_GetAttackDefence()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterFightLevel(chr);
	//npc_return_tmp = 0.05 + level*0.4;
	npc_return_tmp = 0.3 + level*0.35;
	/*if (!iArcadeFencingAI)	// to_do
	{
		npc_return_tmp = npc_return_tmp + 0.2;
	}*/
	return npc_return_tmp;
}

// boal 20.01.08 ������� - �������, ��� ������ ��� ����, ����� ��� � ��� � �������������. ��� ��� ���������� � 0-1 �� ���� ����� �����, �� ���� ���������� ��������� �� ��������� ��� ����� ������������ ����� �� ������ �������, � �� ��������� ����
// ������ ���� ������ - ��� ����� � ������ (���� + ����)
//��� ������ �����, 0 - ������� �� ��������
#event_handler("NPC_Event_GetDefenceWeightBlock","LAi_NPC_GetDefenceWeightBlock");
float LAi_NPC_GetDefenceWeightBlock()
{
	aref chr = GetEventData();
	npc_return_tmp = 80.0;
	npc_return_tmp = npc_return_tmp * (0.5 + (0.05 * MOD_SKILL_ENEMY_RATE));   // boal
	return npc_return_tmp;
}

//��� ������  ������������, 0 - ������� �� ��������
//����� � ����� ������������ �������� 2 ���� � �������
#event_handler("NPC_Event_GetDefenceWeightParry","LAi_NPC_GetDefenceWeightParry");
float LAi_NPC_GetDefenceWeightParry()
{
	aref chr = GetEventData();
	npc_return_tmp = 20.0; // 40 boal
	npc_return_tmp = npc_return_tmp * (0.6 + (0.1 * MOD_SKILL_ENEMY_RATE));
	return npc_return_tmp;
}

//�������� �� ������
#event_handler("NPC_Event_EnableRecoil","LAi_NPC_EnableRecoil");
bool LAi_NPC_EnableRecoil()
{
	aref chr = GetEventData();
	npc_return_tmpb = true;
	return npc_return_tmpb;
}


//��������� ��������
//����������� ������� ���������� - ����� � ����� ������������ �������� 2 ���� � �������
#event_handler("NPC_Event_GetFireActive","LAi_NPC_GetFireActive");
float LAi_NPC_GetFireActive()
{
	aref chr = GetEventData();
	float level = LAi_GetCharacterGunLevel(chr);
	npc_return_tmp = 0.001 + level*0.06;
	// boal ���� ������� ����� �� ���� ������� -->
	if (chr.chr_ai.group == LAI_GROUP_PLAYER)
	{
        npc_return_tmp = 0.38 + npc_return_tmp;
	}
	else
	{
	// boal ���� ������� ����� �� ���� ������� <--
		if (CheckAttribute(chr, "SuperShooter"))
		{
			npc_return_tmp = npc_return_tmp + 0.4 * MOD_SKILL_ENEMY_RATE / 10.0;
		}
		else
		{
			npc_return_tmp = npc_return_tmp + 0.1 * MOD_SKILL_ENEMY_RATE / 10.0;
		}
	}
	//if (npc_return_tmp > 0.5) npc_return_tmp = 0.5;
	
	return npc_return_tmp;
}

//�������� �� �������
#event_handler("NPC_Event_EnableFire","LAi_NPC_EnableFire");
bool LAi_NPC_EnableFire()
{
	aref chr = GetEventData();
	return   true;
	/*float level = LAi_GetCharacterGunLevel(chr);
	npc_return_tmpb = false;
	if(!iArcadeFencingAI)
	{
		level = level + 0.02;
	}
	else
	{
		level = level - 0.01;
	}
	if(level > 0.1) npc_return_tmpb = true;
	return npc_return_tmpb;    */
}

//�������� �� ��������� ��������� ���� ����� ������� - ������������ ���������
#event_handler("NPC_Event_AdaptiveTargetSelect","LAi_NPC_AdaptiveTargetSelect");
bool LAi_NPC_AdaptiveTargetSelect()
{
	aref chr = GetEventData();
	if(chr.chr_ai.type == LAI_TYPE_ACTOR)
	{
		npc_return_tmpb = false;
	}else{
		npc_return_tmpb = true;
	}
	return npc_return_tmpb;
}

//�������� �� ���� ����� �����
#event_handler("NPC_Event_EnableStun","LAi_NPC_EnableStun");
bool LAi_NPC_EnableStun()
{
	aref chr = GetEventData();
	if(CheckCharacterPerk(chr, "SwordplayProfessional"))
	{
		if(rand(100) < 60) npc_return_tmpb = false;
		else npc_return_tmpb = true;
	}
	else 
	{
	if(CheckCharacterPerk(chr, "ProfessionalDefense"))
		{
			if(rand(100) < 45) npc_return_tmpb = false;
			else npc_return_tmpb = true;
		}
		else
		{	
		if(CheckCharacterPerk(chr, "AdvancedDefense"))
		{
			if(rand(100) < 30) npc_return_tmpb = false;
			else npc_return_tmpb = true;
		}
		else
		{	
			if(CheckCharacterPerk(chr, "BasicDefense"))
			{
				if(rand(100) < 20) npc_return_tmpb = false;
				else npc_return_tmpb = true;
			}
			else
			{
				if(rand(100) < 10) npc_return_tmpb = false;
				npc_return_tmpb = true;
				}
			}
		}	
	}	
	return npc_return_tmpb;
}

//--------------------------------------------------------------------------------
//Work
//--------------------------------------------------------------------------------

#event_handler("Location_CharacterSGFire","LAi_Location_CharacterSGFire");
void LAi_Location_CharacterSGFire()
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float kDmg = GetEventData();
	if(LAi_IsDead(enemy)) return;
	//������� ���� �� �����
	LAi_group_Attack(attack, enemy);
	//AddCharacterExp(attack, 100*kDmg);
	//������� �����������
	LAi_ApplyCharacterDamage(enemy, MakeInt((5 + rand(5))*kDmg),"fire");
	//�������� �� ������
	LAi_CheckKillCharacter(enemy);
}

#event_handler("ChrAttackAction", "LAi_ChrAttackAction");
bool LAi_ChrAttackAction()
{
	aref attack = GetEventData();
	string attackType = GetEventData();
	float curEnergy = Lai_CharacterGetEnergy(attack);
	float needEnergy = LAi_CalcUseEnergyForBlade(attack, attackType);
	if(curEnergy >= needEnergy)
	{
		npc_return_tmpb = true;
	}
	else
	{
		npc_return_tmpb = false;
	}
	return npc_return_tmpb;
}

#event_handler("ChrFgtActApply", "LAi_ChrFightActionApply");
void LAi_ChrFightActionApply()
{
	aref attack = GetEventData();
	string attackType = GetEventData();
	float needEnergy = LAi_CalcUseEnergyForBlade(attack, attackType);
	Lai_CharacterChangeEnergy(attack, -needEnergy);
}

//�������� ������������� ������������� �������
#event_handler("NPC_Event_GetActionEnergy","LAi_NPC_GetActionEnergy");
float LAi_NPC_GetActionEnergy()
{
	aref chr = GetEventData();
	string act = GetEventData();
	npc_return_tmp = LAi_CalcUseEnergyForBlade(chr, act) / LAi_GetCharacterMaxEnergy(chr);  // boal
	return npc_return_tmp;
}

//���������� ������� ����������� ������ �������������� �������� �����
#event_handler("NpcEvtHP", "LAi_NPC_EvtGetHP");
float LAi_NPC_EvtGetHP()
{
	aref chr = GetEventData();
	npc_return_tmp = LAi_GetCharacterRelHP(chr);
	return npc_return_tmp;
}

//���������� ������� ����������� ������ �������������� �������� �������
#event_handler("NpcEvtEny", "LAi_NPC_EvtGetEny");
float LAi_NPC_EvtGetEny()
{
	aref chr = GetEventData();
	npc_return_tmp = LAi_GetCharacterRelEnergy(chr);
	return npc_return_tmp;
}