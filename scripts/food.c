#define I_MIN_MORALE	10

// boal -->
#define FOOD_BY_CREW       10.0
#define FOOD_BY_SLAVES     20.0
#define FOOD_BY_PASSENGERS 10.0
#define RUM_BY_CREW        60.0
// boal <--

//bool bInterfaceFood = false;
//int iFoodQuantity = 0;

// ������ ����� ���� �� ������� ���� ��� �� ���� ��������
int CalculateFood()
{
	int chrIndex;
	int iCrewQuantity = 0;
	float foodNeeded = 0;
	int iSlavesQuantity = 0;
	int iFoodQuantity = 0;

	for (int i=0; i<COMPANION_MAX; i++)
	{
		chrIndex = GetCompanionIndex(pchar, i);
		if (chrIndex != -1)
		{
            if (!GetRemovable(&characters[chrIndex])) continue;
			if (characters[chrIndex].ship.type != SHIP_NOTUSED)
			{
				iCrewQuantity   += sti(characters[chrIndex].ship.crew.quantity);
				iFoodQuantity   += makeint(GetCargoGoods(&characters[chrIndex], GOOD_FOOD) / isEquippedArtefactUse(&characters[chrIndex], "talisman6", 1.0, 0.75));
				iSlavesQuantity += GetCargoGoods(&characters[chrIndex], GOOD_SLAVES);
			}
		}
	}
	int iPassQuantity = GetPassengersQuantity(pchar);

	foodNeeded = makefloat(iCrewQuantity/FOOD_BY_CREW + iPassQuantity/FOOD_BY_PASSENGERS + iSlavesQuantity/FOOD_BY_SLAVES);

	if (foodNeeded < 1)
	{
		foodNeeded = 1;
	}

	iFoodQuantity = makeint(iFoodQuantity/foodNeeded + 0.2);

	return iFoodQuantity;
}

// ��� �� ����� �������
int CalculateShipFood(ref _chr)
{
	int iCrewQuantity = 0;
	float foodNeeded = 0.0;
	int iSlavesQuantity = 0;
	int iFoodQuantity = 0;
	int iPassQuantity = 0;

	iCrewQuantity   =  sti(_chr.ship.crew.quantity);
	iFoodQuantity   =  GetCargoGoods(_chr, GOOD_FOOD);
	iSlavesQuantity =  GetCargoGoods(_chr, GOOD_SLAVES);
	if (_chr.id == pchar.id) 
	{
		iPassQuantity = GetPassengersQuantity(pchar);
	}

	foodNeeded = isEquippedArtefactUse(_chr, "talisman6", 1.0, 0.75) * makefloat(iCrewQuantity/FOOD_BY_CREW + iPassQuantity/FOOD_BY_PASSENGERS + iSlavesQuantity/FOOD_BY_SLAVES);

	if (foodNeeded < 1.0)
	{
		foodNeeded = 1.0;
	}

	iFoodQuantity = makeint(iFoodQuantity/foodNeeded + 0.2);

	return iFoodQuantity;
}

// Warship 11.07.09 ������ ���-�� ����, �� ������� ������ ���� �� ����� �������
int CalculateShipRum(ref _character)
{
	int crewQuantity 	= GetCrewQuantity(_character);
	int rumQuantity     = GetCargoGoods(_character, GOOD_RUM);	
	float rumNeeded 	= isEquippedArtefactUse(_character, "talisman4", 1.0, 0.2) * makefloat( (crewQuantity + 5.1) / (RUM_BY_CREW - MOD_SKILL_ENEMY_RATE * 2.5)); // ������� ���� �� ����);
	
	if(rumNeeded < 1.0) rumNeeded = 1.0;	
	rumQuantity = makeint(rumQuantity/rumNeeded + 0.2);		
	return rumQuantity;
}

// Ugeen  29.10.10 ������ ����� ���� �� ������� ���� ���� �� ���� ��������
int CalculateRum()
{
	int 	chrIndex;
	int 	iCrewQuantity = 0;
	int 	iRumCount = 0;
	float 	RumNeeded = 0;

	for (int i=0; i<COMPANION_MAX; i++)
	{
		chrIndex = GetCompanionIndex(pchar, i);
		if (chrIndex != -1)
		{
            if (!GetRemovable(&characters[chrIndex])) continue;
			if (characters[chrIndex].ship.type != SHIP_NOTUSED)
			{
				iCrewQuantity   += GetCrewQuantity(&characters[chrIndex]);
				iRumCount       += makeint(GetCargoGoods(&characters[chrIndex], GOOD_RUM) / isEquippedArtefactUse(&characters[chrIndex], "talisman4", 1.0, 0.75));							
			}
		}
	}
	RumNeeded = makefloat(iCrewQuantity/(RUM_BY_CREW - MOD_SKILL_ENEMY_RATE * 2.5));

	if (RumNeeded < 1.0)
	{
		RumNeeded = 1.0;
	}

	return makeint(iRumCount/RumNeeded + 0.2);
}
// boal 21.04.04 ����� �� ������� -->
void DailyRatsEatGoodsUpdate(ref chref)
{
	if(IsCharacterEquippedArtefact(chref, "talisman1")) return; // ��������
	if(IsCharacterEquippedArtefact(chref, "talisman9")) return; // ��������
	if(IsCharacterEquippedArtefact(chref, "DOjeronRing")) return; // ��������
	if(IsCharacterEquippedArtefact(chref, "rat_poison")) return; // ������
	if (IsCharacterPerkOn(chref, "HT2")) return; // ������ ��������
	if(CheckAttribute(pchar, "GenQuest.Ole")) return; // ��� �����������
    int iGoods = GOOD_FOOD + rand(GOOD_OIL - GOOD_FOOD);
	if(iGoods == GOOD_BRICK) return;
    int iQuantity = GetCargoGoods(chref, iGoods);
    int iSeaGoods = LanguageOpenFile("ShipEatGood.txt");
    if (iQuantity > 10 && rand(5) != 2) // ���� �� �����, ���� ���� ������
    {
        float fSkill = GetSummonSkillFromNameToOld(chref, SKILL_REPAIR) + GetSummonSkillFromNameToOld(chref,SKILL_FORTUNE);
        
        iQuantity = 1+ rand(makeint(iQuantity / (10+fSkill)));
        RemoveCharacterGoodsSelf(chref, iGoods, iQuantity);
        //PlaySound("interface\notebook.wav");
        Log_SetStringToLog(RandSwear());
        Log_SetStringToLog("����� �� ������� " +
                           chref.Ship.Name + LinkRandPhrase(" ��������� ", " ��������� ", " ���������� ") +
                           iQuantity + " ��. " + LanguageConvertString(iSeaGoods, "seg_" + Goods[iGoods].Name));

        Statistic_AddValue(pchar, "RatsEatGoods", iQuantity);
                
		if (iQuantity > 400) iQuantity = 400;
		
		AddCharacterExpToSkill(chref, SKILL_REPAIR, iQuantity);
        AddCharacterExpToSkill(chref, SKILL_FORTUNE, iQuantity/10);
    }
    LanguageCloseFile(iSeaGoods);
}

// boal food for crew 20.01.2004 -->
void DailyEatCrewUpdate()   // ���� ����� ��� ��� � 1 ����
{
    ref mainCh = GetMainCharacter();
    int i, cn, crew, morale;
    ref chref;
    int nMoraleDecreaseQ;
    
    // to_do
    // boal 030804 ���������� ����� ������ -->
    //DailyShipyardMoneyUpdate();
    // boal 030804 ���������� ����� ������ <--
	
	// ugeen ���������� ����� ��������� -->
	DailyTradersMoneyUpdate();
	// ugeen ���������� �����  ���������<--
	
    mainCh.questTemp.abordage = 0; // fix ����� �������� ������ ������ �������

    //�������
    //if(IsCharacterPerkOn(mainCh, "CustomsHouse"))
    //{
    //    AddGoverGoods();
    //}

    SetNewDayHealth(); // �������� �� ����
  
	// ���� -->
	//SetPortShoreEnter(mainCh);
    DeleteAttribute(mainCh, "GenQuest.Hunter2Pause");  // boal ����� � ����� ��������� - ���� ���������
    // ���� <--

    //  ��� �� ����� SetAllHabitueToNew(); // ������� ���� ������ � ��������
	if (CheckAttribute(mainCh, "questTemp.ShipCapellan.Yes")) AddCrewMorale(mainCh, 5); //Jason, ������� ������������ ��������� �� ������

	////////////////      ���     /////////////////
	if (bNoEatNoRats) return; // betatest
    if (sti(mainCh.Ship.Type) == SHIP_NOTUSED ) return;

	// �������� ���������� �� ����� 02.02.08 -->
	if (CheckAttribute(pchar, "CrewPayment")) // ����
	{
		ChangeCharacterComplexReputation(pchar,"authority", -0.1);
        cn = makeint(pchar.CrewPayment);
        if (cn > 32000) cn = 32000;
		if (rand(cn) > 1000)
		{
            morale = 5 + CheckOfficersPerk(pchar, "IronWill");   // true = 1
			for (i = 0; i<GetPassengersQuantity(pchar); i++)
			{   // ����� �������� � ���� ���� ����������� ����� �������
				cn = GetPassenger(pchar, i);
				if (cn != -1)
				{
		            chref = &Characters[cn];
					if (CheckAttribute(chref, "loyality") && !CheckAttribute(chref, "OfficerWantToGo.DontGo") && rand(morale) == 2 && !IsEquipCharacterByArtefact(chref, "totem_04"))
					{
		    			chref.loyality = makeint(chref.loyality) - 1;
					}
				}
			}
		}
	}
	// �������� ���������� �� ����� 02.02.08 <--
	
	for(i=0; i<COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mainCh,i);
		if( cn>=0 )
		{
			chref = GetCharacter(cn);

			if (!GetRemovable(chref)) continue;

			// RATS -->
			DailyRatsEatGoodsUpdate(chref);
			// RATS <--
			DailyEatCrewUpdateForShip(chref, false);
			
		}
	}
}

// boal 20.01.2004 <--

// Warship. ����� � ��������� �����
void DailyEatCrewUpdateForShip(ref rChar, bool IsCompanionTraveler) // IsCompanionTraveler - ���� ���� ��� �����������-����������������
{
	int iCrewQty = GetCrewQuantity(rChar);
	int cn, morale, nMoraleDecreaseQ, iDeadCrew;
	if(iCrewQty < 1 && GetCargoGoods(rChar, GOOD_SLAVES) < 1) return;
	if(!CheckAttribute(rChar, "Ship.Crew.Morale"))
	{
		rChar.Ship.Crew.Morale = 50;
	}
	// ������ �������� -->
	if(rand(4) == 2)
	{
		// �������
		cn = iCrewQty / 10;
		if(cn > 30) cn = 30;
		cn = rand(cn)+1;
		if(iCrewQty < cn) cn = iCrewQty;
		if(cn > 0)
		{
			if(GetCargoGoods(rChar, GOOD_MEDICAMENT) < 1)
			{
				if(!IsCompanionTraveler) Log_Info("�� ������� " + rChar.Ship.Name + " �� �������� ������ " + FindRussianSailorString(cn, "No"));
			iCrewQty = iCrewQty - cn;
			Statistic_AddValue(pchar, "Sailors_dead", cn);
			rChar.Ship.Crew.Quantity = iCrewQty;
				// ������ � �����
				morale = sti(rChar.Ship.Crew.Morale);
				
				if(CheckOfficersPerk(rChar, "IronWill")) cn /= 1.5;
				
				AddCrewMorale(rChar, -makeint(cn / 2)); // �� 15 ������� �� ���
				ChangeCharacterComplexReputation(pchar,"authority", -1);
			}
			else
			{
				if(CheckShipSituationDaily_GenQuest(rChar) == 2) cn = cn * 2;
				if(CheckShipSituationDaily_GenQuest(rChar) == 3) cn = cn * 3;
				
				RemoveCharacterGoodsSelf(rChar, GOOD_MEDICAMENT, cn);
				if(GetCargoGoods(rChar, GOOD_MEDICAMENT) < 16)
				{
					if(!IsCompanionTraveler) Log_Info("�� ������� " + rChar.Ship.Name + " �������� ���� ������������");
				}
			}
		}
		// ����
		cn = GetCargoGoods(rChar, GOOD_SLAVES) / 10;
		if(cn > 30) cn = 30;
		cn = rand(cn)+1;
		if(GetCargoGoods(rChar, GOOD_SLAVES) < cn) cn = GetCargoGoods(rChar, GOOD_SLAVES);
		if(cn > 0)
		{
			if(GetCargoGoods(rChar, GOOD_MEDICAMENT) < 1)
			{
				if(!IsCompanionTraveler) Log_Info("�� ������� " + rChar.Ship.Name + " �� �������� ������ " + FindRussianSlavesString(cn, "No"));
				RemoveCharacterGoodsSelf(rChar, GOOD_SLAVES, cn);
			}
			else
			{
				cn /= 3;
				RemoveCharacterGoodsSelf(rChar, GOOD_MEDICAMENT, cn);
			}
		}
		// ��������� ��������
		if(iCrewQty < 1 && GetCargoGoods(rChar, GOOD_SLAVES) < 1) return;
	}
	// ������ �������� <--

	// ������ ����	
	iCrewQty = GetCrewQuantity(rChar);
	float rumNeeded = isEquippedArtefactUse(rChar, "talisman4", 1.0, 0.2) * makefloat( (iCrewQty + 5.1) / (RUM_BY_CREW - MOD_SKILL_ENEMY_RATE * 2.5)); // ������� ���� �� ����);
	
	if(rumNeeded < 1.0) rumNeeded = 1.0;
	iCrewQty = makeint(rumNeeded);
	
	if(iCrewQty > 0)
	{
		if(GetCargoGoods(rChar, GOOD_RUM) >= iCrewQty)
		{
			RemoveCharacterGoodsSelf(rChar, GOOD_RUM, iCrewQty);
			// �������� �� �������
			cn = makeint(GetCargoGoods(rChar, GOOD_RUM) / iCrewQty);
			if (cn < 1)
			{
				if(!IsCompanionTraveler) Log_Info("�� ������� " + rChar.Ship.Name + " ���� ��� �����");
			}
			// �������� ������
			if(CheckShipSituationDaily_GenQuest(rChar) == 1) AddCrewMorale(rChar, 2);
		}
		else
		{
			iCrewQty = GetCargoGoods(rChar, GOOD_RUM);
			RemoveCharacterGoodsSelf(rChar, GOOD_RUM, iCrewQty);
		}
	}
	// ������ ����
	
	iCrewQty = GetCrewQuantity(rChar);
	// ������� ��������� ������� �� ������  � ��������� -->
	if(iCrewQty > GetOptCrewQuantity(rChar) && !IsCharacterEquippedArtefact(rChar, "talisman4"))
	{
		AddCrewMorale(rChar, -(1+rand(3)));
		ChangeCharacterComplexReputation(pchar,"authority", -0.1);
	} 
	// ������� ��������� ������� �� ������ <--
	
	// ������ ����� �� ������
	if(iCrewQty > 0 && CheckAttribute(PChar, "CrewPayment"))
	{
		cn = makeint(PChar.CrewPayment);
		if(cn > 32000) cn = 32000;
		if(rand(cn) > 1000)
		{
			ChangeCharacterComplexReputation(pchar,"authority", -0.2);
			AddCrewMorale(rChar, -1);
			cn = 5 + CheckOfficersPerk(PChar, "IronWill");  // ���� � ��
			if(i > 0 && rand(cn) == 2 && !CheckAttribute(rChar, "OfficerWantToGo.DontGo") && !IsEquipCharacterByArtefact(rChar, "totem_04"))
			{
				rChar.loyality = sti(rChar.loyality) - 1;
			}
		}
	}
	// ������ ��� ����� ����	
	iCrewQty = makeint(isEquippedArtefactUse(rChar, "talisman6", 1.0, 0.75) * (iCrewQty+5.1) / FOOD_BY_CREW + GetPassengersQuantity(rChar) / FOOD_BY_PASSENGERS); // eat ratio
	iCrewQty = iCrewQty + makeint((GetCargoGoods(rChar, GOOD_SLAVES)+6)/ FOOD_BY_SLAVES);  // ���� �����
	if(iCrewQty == 0) iCrewQty = 1;
	if(GetCargoGoods(rChar, GOOD_FOOD) >= iCrewQty)
	{
		RemoveCharacterGoodsSelf(rChar, GOOD_FOOD, iCrewQty);
		// �������� �� �������
		cn = makeint(GetCargoGoods(rChar, GOOD_FOOD) / iCrewQty);
		if (cn < 4)
		{
			if(!IsCompanionTraveler)
			{
				Log_Info("�� ������� " + rChar.Ship.Name + " �������������� �������� �� " + FindRussianDaysString(cn));
				Log_Info("����� ������ ��������� ������!");
				PlaySound("interface\notebook.wav");
			}
		}
		// ��������� ���� �����
		if (sti(rChar.index) == GetMainCharacterIndex() && GetCargoGoods(rChar, GOOD_SLAVES) > (GetCrewQuantity(rChar)*1.5 + sti(rChar.Ship.Crew.Morale)))
		{
			nMoraleDecreaseQ = 12 - GetSummonSkillFromNameToOld(rChar, SKILL_LEADERSHIP);
			if(CheckOfficersPerk(rChar, "IronWill")) nMoraleDecreaseQ /= 2;
			if(rand(2) == 1 && nMoraleDecreaseQ > rand(10))
			{
				if(IsEntity(worldMap) && !CheckAttribute(pchar, "CSM.NoShipMutinies")) // --> CheatSurfMenu by Cheatsurfer
				{
					rChar.GenQuest.SlavesMunity = true;
					Log_Info("���� ������� ���������!");
					MunityOnShip("SlavesMunity");
				}
			}
		}
	}
	else
	{
		iCrewQty = GetCargoGoods(rChar, GOOD_FOOD);
		RemoveCharacterGoodsSelf(rChar, GOOD_FOOD, iCrewQty);
		PlaySound("interface\notebook.wav");
		
		if(!IsCompanionTraveler) Log_Info("�� ������� " + rChar.Ship.Name + " ������� ��������. ������ ������� ������!");
		
		if(sti(rChar.index) == GetMainCharacterIndex())
		{
			AddCharacterHealth(PChar, -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
		}
		
		cn = GetCrewQuantity(rChar);
		if(cn > 1)
		{
		iDeadCrew = makeint(cn/10 +0.5);
		rChar.Ship.Crew.Quantity = cn - iDeadCrew;
		Statistic_AddValue(pchar, "Sailors_dead", iDeadCrew);
		if(!IsCompanionTraveler) Log_Info("������� ������� �� ������");
		}
		cn = GetCargoGoods(rChar, GOOD_SLAVES);
		if(cn > 0)
		{
			RemoveCharacterGoodsSelf(rChar, GOOD_SLAVES, makeint(cn/5 + 0.5));
			if(!IsCompanionTraveler) Log_Info("���� ������� �� ������");
		}
		morale = sti(rChar.Ship.Crew.Morale);
		
		nMoraleDecreaseQ = 12 - GetSummonSkillFromNameToOld(rChar, SKILL_LEADERSHIP);
		if(CheckOfficersPerk(rChar, "IronWill")) nMoraleDecreaseQ /= 2;
		rChar.Ship.Crew.Morale = morale - nMoraleDecreaseQ;
		if(sti(rChar.Ship.Crew.Morale) < MORALE_MIN) rChar.Ship.Crew.Morale = MORALE_MIN;  
	}
	
	if(sti(rChar.index) == GetMainCharacterIndex())
	{
		if(sti(rChar.Ship.Crew.Morale) <= MORALE_MIN || makeint(rChar.reputation.authority) < 5)
		{
			//int locidx = FindLocation(rChar.location); // �� ������������
			if(IsEntity(worldMap) && GetCrewQuantity(rChar) > 0 && !IsCharacterEquippedArtefact(rChar, "totem_02") && !CheckAttribute(pchar, "CSM.NoShipMutinies")) // --> CheatSurfMenu by Cheatsurfer
			{
				Log_Info("���� �� ������� " + rChar.Ship.Name + "!!!! ");
				MunityOnShip("ShipMunity");
			}
		}
	}
	else
	{
		if(GetShipRemovable(rChar) && !CheckAttribute(rChar, "OfficerWantToGo.DontGo") && !IsCompanionTraveler && !IsEquipCharacterByArtefact(rChar, "totem_04")) // ���, ��������� ���� � ����������-��������������� �� �������
		{
			if(sti(rChar.Ship.Crew.Morale) <= MORALE_MIN || sti(rChar.loyality) <= 0) // ������, ��� ���������� ���� � ���� ����
			{
				if(GetCrewQuantity(rChar) > 0 && !IsCharacterEquippedArtefact(rChar, "totem_02"))
				{
					Log_Info("���� �� ������� " + rChar.Ship.Name + "!!!! ");
					Log_SetStringToLog("������� ������� �� �������");
					Statistic_AddValue(PChar, "ShipMunity", 1);
					RemoveCharacterCompanion(PChar, rChar);
					//fix  ���
					if(!CheckAttribute(rChar, "PGGAi"))
					{
						rChar.LifeDay = 0; // ������� ��� ������
					}
					else
					{
						rChar.PGGAi.IsPGG = true;
						rChar.RebirthPhantom = true;
						rChar.PGGAi.location.town = PGG_FindRandomTownByNation(sti(rChar.nation));
						rChar.Dialog.FileName = "PGG_Dialog.c";
						rChar.Dialog.CurrentNode = "Second Time";
						PGG_ChangeRelation2MainCharacter(rChar, -20);
					}
					rChar.location = ""; // �����, �����..� �� � ������� ���������...
					rChar.location.group = "";
					rChar.location.locator = "";
				}
			}
		}
	}
}

void DailyTradersMoneyUpdate()
{
	ref rCharacter;
	
	for(int n = 0; n < MAX_CHARACTERS; n++)
	{
		makeref(rCharacter,Characters[n]);
		if (CheckAttribute(rCharacter, "Merchant.type")) // �������� 
		{
			if(rCharacter.Merchant.type != "jeweller")
			{
				if(sti(rCharacter.money) > TRADER_MAX_MONEY || sti(rCharacter.money) < TRADER_MIN_MONEY) 	
				{
					rCharacter.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
				}
			}
			else
			{
				if(sti(rCharacter.money) > USURER_MAX_MONEY || sti(rCharacter.money) < USURER_MIN_MONEY) 	
				{
					rCharacter.money = USURER_MIN_MONEY + rand(USURER_NORM);
				}
			}	
		}
	}
}

