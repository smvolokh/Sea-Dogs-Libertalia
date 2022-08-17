// Jason: LSC - поведение горожан-статиков - хождение по городу и заведениям
void CreateLostShipsCity(aref loc)
{	
	int i;
	if (loc.id == "LostShipsCity_town" && isDay())
	{
		ref sld;
		string sTemp, sLocator;
		int locNum, n, Index;
		int qtyTavern = 0; 
		//int qtyResidence = 0;
		int qtyChurch = 0;
		//int qtyPrison = 0;
		int qtyStore = 0;
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (sld.location == "FleuronTavern") qtyTavern++;
			//if (sld.location == "SanAugustineResidence") qtyResidence++;
			if (sld.location == "GloriaChurch") qtyChurch++;
			//if (sld.location == "TartarusPrison") qtyPrison++;
			if (sld.location == "EsmeraldaStoreBig") qtyStore++;
		}
		//размещаем нпс
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "city") && sld.city == "LostShipsCity")
			{
				//////// если внешний горожанин /////////
				if (sld.cityTape == "citizen")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours)) 
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						LAi_SetLoginTime(sld, 6.0, 21.99);
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 19.0 && sld.sex == "man" && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == "LostShipsCity_town") //если горожанин на улице
						{
							if (rand(1))
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(3)+1;
								switch (rand(2))
								{
								case 0: //в церковь
									if (qtyChurch < LSC_MAX_CHURCH)
									{
										sld.location.going = "toChurch"; //флаг генерации в церкви
										qtyChurch++;
									}
									break;
								case 1: //в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
									break;
								case 2: //в магазин
									if (qtyStore < LSC_MAX_STORE)
									{
										sld.location.going = "toStore"; //флаг генерации в магазине	
										qtyStore++;
									}
									break;									
								}
							}
						}
						else
						{	//возвращемся на свой корабль
							//проверим занятость локатора								
							if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
							{	//выберем незанятый 
								sTemp = sld.location.baseLocator;
								sTemp = strcut(sTemp, 4, 5);
								for (n=0; n<=9; n++)
								{											
									sLocator = "goto" + sTemp + "_" + n;
									if (LAi_CheckLocatorFree("goto", sLocator))
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCity_town", "goto", sLocator);
										break;
									}
								}
							}
							else
							{
								LAi_SetLSCoutTypeNoGroup(sld);
								ChangeCharacterAddressGroup(sld, "LostShipsCity_town", "goto", sld.location.baseLocator);
							}
						}
					}
				}
				//////// если домашний горожанин /////////
				if (sld.cityTape == "citizenHome")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours)) 
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						LAi_SetLoginTime(sld, 6.0, 21.99);
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 19.0 && sld.sex == "man" && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == sld.location.baseLocation) //если горожанин у себя дома
						{
							if (rand(1))
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(6)+1;
								switch (rand(3))
								{
								case 0: //в церковь
									if (qtyChurch < LSC_MAX_CHURCH)
									{
										sld.location.going = "toChurch"; //флаг генерации в церкви
										qtyChurch++;
									}
									break;
								case 1: //в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
									break;
								case 2: //в магазин
									if (qtyStore < LSC_MAX_STORE)
									{
										sld.location.going = "toStore"; //флаг генерации в магазине	
										qtyStore++;
									}
									break;	
								case 3: //на улицы
									//проверим занятость локатора								
									if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
									{	//выберем незанятый 
										sTemp = sld.location.baseLocator;
										sTemp = strcut(sTemp, 4, 5);
										for (n=0; n<=9; n++)
										{											
											sLocator = "goto" + sTemp + "_" + n;
											if (LAi_CheckLocatorFree("goto", sLocator))
											{
												LAi_SetLSCoutTypeNoGroup(sld);
												ChangeCharacterAddressGroup(sld, "LostShipsCity_town", "goto", sLocator);
												break;
											}
										}
									}
									else
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCity_town", "goto", sld.location.baseLocator);
									}
									break;	
								}
							}
						}
						else
						{	//возвращемся на свой корабль
							LAi_SetOwnerTypeNoGroup(sld);
							ChangeCharacterAddressGroup(sld, sld.location.baseLocation, "barmen", "stay");
						}
					}
				}
			}
		}
	}
	//------------------- таверна ------------------------
	if (loc.id == "FleuronTavern")
	{
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "location.going") && sld.location.going == "toTavern")
			{
				DeleteAttribute(sld, "location.going");
				LAi_RemoveLoginTime(sld);
				if (sld.sex == "man")
				{
					DeleteAttribute(sld, "nonTable");
					LAi_SetSitTypeNoGroup(sld);
					if (sld.id == "LSCMayor")
						ChangeCharacterAddressGroup(sld, loc.id, "quest", "head_sit");
					else
						PlaceCharacter(sld, "sit", "random_free");
				}
				else
				{
					LAi_SetCitizenTypeNoGroup(sld);
					PlaceCharacter(sld, "goto", "random_free");
				}
			}
		}
	}
	//------------------- церковь ------------------------
	if (loc.id == "GloriaChurch")
	{
		//сам падре
		if (!isDay())
		{
			Index = GetCharacterIndex("Julian");	
			if (Index != -1)
			{
				sld = &characters[Index];
				LAi_SetSitTypeNoGroup(sld);
				PlaceCharacter(sld, "quest", "priest");
			}
		}
		else
		{
			for(i=0; i<MAX_CHARACTERS; i++)
			{
				makeref(sld, characters[i]);
				//падре днем
				if (sld.id == "Julian")
				{
					LAi_SetPriestTypeNoGroup(sld);
					ChangeCharacterAddressGroup(sld, sld.location, "barmen",  "stay");
				}
				//граждане
				if (CheckAttribute(sld, "location.going") && sld.location.going == "toChurch")
				{
					DeleteAttribute(sld, "location.going");
					if (sld.sex == "woman")
					{
						LAi_SetCitizenTypeNoGroup(sld);
						PlaceCharacter(sld, "goto", "random_free");
					}
					else
					{
						sld.nonTable = true;
						LAi_SetSitTypeNoGroup(sld);
						PlaceCharacter(sld, "sit", "random_free");
					}
				}
			}
		}
	}
	//------------------- магазин ------------------------
	if (loc.id == "EsmeraldaStoreBig")
	{
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "location.going") && sld.location.going == "toStore")
			{
				DeleteAttribute(sld, "location.going");
                LAi_SetStayTypeNoGroup(sld);
				PlaceCharacter(sld, "goto", "random_free");
			}
		}
	}
}

void CreatUnderwater(aref loc) // под водой
{
	if (loc.type == "underwater")
	{
		if (CheckAttribute(loc, "type.LSC"))
			{
				if (GetCharacterIndex("Mary") != -1) // ничего умнее этого не удалось придумать patch-10
				{
					sld = characterFromId("Mary");
					LAi_SetActorType(sld);
					LAi_ActorGoToLocation(sld, "reload", "reload1", "CeresSmithy", "goto", "goto11", "LSC_MaryReturnNormal_1", 1.5);
				}
				LocatorReloadEnterDisable("LostShipsCity_town", "reload72", true); //закрываем вход в Феникс
				LocatorReloadEnterDisable("SanGabrielMechanic", "reload3", true); //закрываем выход от Механика
				DeleteAttribute(pchar, "questTemp.LSC.immersion");
				pchar.questTemp.LSC.UW_end = "true"; // сдача костюма
				SetShowTimer(500.0); //таймер на 20 игровых минут
				AddCharacterHealth(pchar, -3); //портим здоровье
			for (int i=1; i<=28; i++)
			{
				if (GetCharacterIndex("Crab_"+i) == -1)
				{
					sld = GetCharacter(NPC_GenerateCharacter("Crab_"+i, "crabBig", "crab", "crabBig", 50+(MOD_SKILL_ENEMY_RATE), PIRATE, -1, false, "quest"));
					sld.name = "Гигантский краб";
					sld.lastname = "";
					GiveItem2Character(sld, "unarmed");
					EquipCharacterbyItem(sld, "unarmed");
					sld.SaveItemsForDead = true;
					if (bPincers()) TakeNItems(sld, "crab_pincers", 2); // клешни
					//if (rand(2) == 1) TakeNItems(sld, "crab_jaw", rand(1)); // жвалы
					int iTemp = 200+MOD_SKILL_ENEMY_RATE*10+sti(pchar.rank)*8;
					LAi_SetHP(sld, iTemp, iTemp);
			sld.MultiFighter = 1.5; // мультифайтер
			sld.MultiShooter = 1.5;
					sld.animal = true;
					SetCharacterPerk(sld, "BasicDefense");
					SetCharacterPerk(sld, "AdvancedDefense");
					SetCharacterPerk(sld, "CriticalHit");
					LAi_SetWarriorType(sld);
					LAi_warrior_SetStay(sld, true);
					LAi_warrior_DialogEnable(sld, false);
					LAi_group_MoveCharacter(sld, LAI_GROUP_MONSTERS);
				}
				PlaceCharacter(sld, "goto", "random_free");
			}
		}
		else
		{
			if (CheckAttribute(loc, "watertemple")) SetShowTimer(80.0); // 010912
			else SetShowTimer(60.0); //таймер
		}
	}
}

void CreatePlantation(aref loc)
{
	if(CheckAttribute(loc,"type") && loc.type == "Plantation")
	{
	    if(LAi_IsCapturedLocation) // fix нефиг грузить, когда город трупов или боевка
		{
			return;
		}
		if (GetNpcQuestPastDayWOInit(loc, "Plantation_date") < 2) return;

		int iColony = -1;
		int iNation = -1;

		string sAreal = GiveArealByLocation(loc);
		if (sAreal == "none") return;
		
		string sCity = GetCityNameByIsland(sAreal);
		if (sCity == "none") return;
		
	    iColony = FindColony(sCity);

		if(iColony == -1)
		{
			return;
		}

		iNation = GetCityNation(sCity);

		if(iNation == -1)
		{
			return;
		}
		
		SaveCurrentNpcQuestDateParam(loc, "Plantation_date");
		ref sld;
		aref st;
		int iCitizensQuantity, iModel, iChar, i, iSex, num, iMassive, iRank, iScl;
		string slai_group, locatorName, sType, sAnime;
	    slai_group = GetNationNameByType(iNation)+"_citizens";
		string model[10];
	    	// ==> рабы
		model[0] = "prizon_1";
		model[1] = "prizon_2";
		model[2] = "prizon_3";
		model[3] = "prizon_4";
		model[4] = "prizon_5";
		model[5] = "prizon_6";
		model[6] = "prizon_7";
		model[7] = "prizon_8";
		model[8] = "prizon_3";
		model[9] = "prizon_4";
		i = 0;
		num = rand(3) + 7; //кол-во
		while(i < num)
		{
			iMassive = rand(9);
			if (model[iMassive] != "")
			{
				sAnime = "man_B"
				if(model[iMassive] == "prison_5") sAnime = "man2";
				sld = GetCharacter(NPC_GenerateCharacter("Slave_"+i, model[iMassive], "man", sAnime, 7, iNation, 2, false, "slave"));

				sld.dialog.filename = "Quest\ForAll_dialog.c";
				sld.dialog.currentnode = "plantation_slave";
				
				sld.greeting = "convict";
				sld.CityType = "citizen";
				sld.plantation = "slave";
				sld.city = Colonies[iColony].id;
				LAi_SetLoginTime(sld, 6.0, 22.99);

				PlaceCharacter(sld, "goto", "random_free");
				LAi_SetCitizenType(sld);
				LAi_group_MoveCharacter(sld, slai_group);
				i++;
				model[iMassive] = "";
			}
		}

		// солдаты -->
		iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE;
		iScl = 30 + 2*sti(pchar.rank);
		if (iRank > 50) iRank = 50;
		if (checkAttribute(loc, "soldiers") && CheckAttribute(loc, "locators.soldiers"))
		{
			for (i=1; i<=3; i++)
			{
				if(iNation == PIRATE)
				{
					sType = "mushketer_" + (rand(4)+1);
				}
				else
				{
					sType = "mush_" + NationShortName(iNation) + "_" + (rand(2)+1);
				}
				sld = GetCharacter(NPC_GenerateCharacter("GenChar_"+i+"_", sType, "man", "mushketer", iRank, iNation, 2, false, "soldier"));
				FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket_01", "cartridge", iScl*2);
				LAi_SetCharacterUseBullet(sld, "cartridge");
				sld.id = "GenChar_"+i+"_" + sld.index;
				sld.City = Colonies[iColony].id;
				sld.CityType = "soldier";
				sld.plantation = "guardian";
				sld.MusketerDistance = 0;
				sld.cirassId = Items_FindItemIdx("cirass2");
				LAi_SetLoginTime(sld, 6.0, 23.0); //а ночью будет беготня от патруля :)
				LAi_SetGuardianType(sld);
				sld.dialog.filename = "Plantation_dialog.c";
				// протекторы
				if (i == 2 || i == 3) 
				{
					sld.protector = true;
					sld.dialog.currentnode = "plantation_protector"; 
				}
				else 
				{
					sld.dialog.currentnode = "plantation_soldier"; 
					sld.greeting = "soldier";
				}
				
				if (sti(Colonies[iColony].HeroOwn) == true)
				{
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
					sld.greeting = "pirat_guard";
				}
				else
				{
					LAi_group_MoveCharacter(sld, slai_group);
				}			
				ChangeCharacterAddressGroup(sld, pchar.location, "soldiers", "soldier"+i);
			}
		}
		// солдаты <--
		// патруль -->
		if (checkAttribute(loc, "soldiers") && CheckAttribute(loc, "locators.patrol"))
		{
			makearef(st, loc.locators.patrol);
			iCitizensQuantity = GetAttributesNum(st);
			if(iCitizensQuantity > 10)
			{
				iCitizensQuantity = 10;
			}
			for (i=0; i<iCitizensQuantity; i++)
			{
	            if(iNation != PIRATE && LAi_IsCapturedLocation == 0)
				{
	                sType = "soldier";
					iChar = NPC_GeneratePhantomCharacter("soldier", iNation, MAN, 2);
				}
				else
				{
	                sType = "pirate";
					iChar = NPC_GeneratePhantomCharacter("pirate", iNation, MAN, 2);
				}
				sld = &characters[iChar];
				SetNPCModelUniq(sld, sType, MAN);
				sld.City = Colonies[iColony].id;
	            sld.CityType = "soldier";
				sld.plantation = "patrol";
	            SetFantomParamFromRank(sld, iRank, true); // бравые орлы
				sld.RebirthPhantom = true;
				LAi_CharacterReincarnation(sld, true, true);
				LAi_SetReincarnationRankStep(sld, MOD_SKILL_ENEMY_RATE+2); //задаем шаг на увеличение ранга фантомам на реинкарнацию
				LAi_SetLoginTime(sld, 0.0, 24.0);
				LAi_SetPatrolType(sld);

	            if (sti(Colonies[iColony].HeroOwn) == true)
				{
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
					sld.greeting = "town_pirate";
				}
				else
				{
					LAi_group_MoveCharacter(sld, slai_group);
					sld.greeting = "soldier";
				}
				PlaceCharacter(sld, "patrol", "random_free");			
	            sld.dialog.filename = "Common_Soldier.c";            
				sld.dialog.currentnode = "first time";
			}
		}
		// патруль <--
		// грузчики -->
		if (CheckAttribute(loc, "carrier") && IsLoginTime())
		{
			int iTemp;
			int iQtyCarrier = rand(2) + 2;
			string locReload[5];
			locReload[0] = "houseSp1";
			locReload[1] = "houseS1";
			locReload[2] = "houseF1";
			locReload[3] = "houseF2";
			locReload[4] = "houseS2";
			string CarrierName[10];
			CarrierName[0] = "GenresBag1";
			CarrierName[1] = "GenresBag2";
			CarrierName[2] = "GenresBarrel1";
			CarrierName[3] = "GenresBarrel2";
			CarrierName[4] = "GenresBarrelTop1";
			CarrierName[5] = "GenresBarrelTop2";
			CarrierName[6] = "GenresBottle1";
			CarrierName[7] = "GenresBottle2";
			CarrierName[8] = "GenresChest1";
			CarrierName[9] = "GenresChest2";
			for (i=iQtyCarrier; i>0; i--)
			{
				//выберем уникальную для этой локации модельку
				iSex = 1;
				while (iSex == 1)
				{
					iTemp = rand(9);
					if (CarrierName[iTemp] != "") iSex = 0;
				}
				sld = GetCharacter(NPC_GenerateCharacter("Carrier", CarrierName[iTemp], "man", "genres", 35, iNation, 2, false, "slave"));
				sld.id = sld.id + "_" + sld.index;
				aref aLocator;
				makearef(aLocator, loc.locators.reload);
				CarrierName[iTemp] = ""; //имя модельки уберем из списка
				LAi_SetImmortal(sld, true);
				iSex = 1;
				while (iSex == 1)
				{
					iTemp = rand(4);
					if (CheckAttribute(aLocator, locReload[iTemp]) && locReload[iTemp] != "")
					{
						sld.firstLoc = locReload[iTemp];
						sld.firstLoc.timer = rand(7) + 3;
						locReload[iTemp] = "";
						iSex = 0;
					}
				}
				sld.plantation = "carrier";
				ChangeCharacterAddressGroup(sld, loc.id, "reload", "gate");
				LAi_SetCarrierType(sld);
				LAi_SetLoginTime(sld, 6.0, 23.0);
				LAi_group_MoveCharacter(sld, slai_group);
			}
		}
		// грузчики <--
	}	
}

void CreateItzaLand(aref loc)
{
	if(CheckAttribute(loc, "ItzaLand") && !bBettaTestMode)
	{
		ref sld;
		aref grp;
		int iMassive, warriorRank, i, num;	
		string model[10];
		string encGroup, str, locator;
		
		encGroup = LAi_FindRandomLocator("encdetector");
		str = "locators." + encGroup;
		makearef(grp, loc.(str));
		num = GetAttributesNum(grp);
		
		if(num == 0 ) return;
		if(num > 10) num = 10;
		
		LAi_group_Delete("tayasal_monsters_group");
		
		model[0] = "Itza_1";
		model[1] = "Itza_2";
		model[2] = "Itza_3";
		model[3] = "Itza_4";
		model[4] = "Itza_5";	
		model[5] = "Itza_6";
		model[6] = "Itza_7";
		model[7] = "Itza_8";
		model[8] = "Itza_4";
		model[9] = "Itza_6";	
		
		i = 0;
		
		chrDisableReloadToLocation = true;
		
		//определим ранг войнов. обработаем от сложности, но не менее 20 уровня
		warriorRank = GetCoffDiff(sti(pchar.rank), 1000) + MOD_SKILL_ENEMY_RATE;
		if (warriorRank < 20) warriorRank = 20;
		
		while(i < num)
		{
			iMassive = rand(9);
			if (model[iMassive] != "")
			{
				sld = GetCharacter(NPC_GenerateCharacter("AztecWarrior" + loc.index + "_" + i, model[iMassive], "man", "man_A1", warriorRank, PIRATE, 0, true, "itza"));
				FantomMakeCoolFighter(sld, warriorRank, 80 + rand(20), 80 + rand(20), LinkRandPhrase("topor_01","blade_01","blade_02"),"","", 50);
		sld.viper = true;
		sld.name = GetRandName(NAMETYPE_AZTEC, NAME_MEXICO);
				sld.lastname = "";
				TakeNItems(sld,"potion2", rand(3)+1);
				SetCharacterPerk(sld, "Energaiser"); 
				
				locator = GetAttributeName(GetAttributeN(grp, i));
				ChangeCharacterAddressGroup(sld, loc.id, encGroup, locator);

PlaySound("People Fight\americas_charge_large.wav");
				
				LAi_SetWarriorType(sld);
				LAi_warrior_SetStay(sld, true);
				LAi_warrior_DialogEnable(sld, false);
				LAi_group_MoveCharacter(sld, "tayasal_monsters_group");
				i++;
				model[iMassive] = "";
			}
		}
		LAi_group_SetRelation("tayasal_monsters_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);	
		LAi_group_FightGroups("tayasal_monsters_group", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("tayasal_monsters_group", "OpenTheDoors");		
	}
}

void CreatTenochtitlann(aref loc)
{	
	if (loc.id == "Tenochtitlan_1")
	{
		int i;
		//проверяем наличие тотемов у ГГ, чтобы купленным дать shown
		if (locations[reload_cur_location_index].id == "Bel_Jungle_03")
		{	//срабатывает только, если заходим из джунглей
			ref itm;
			string sTemp;
			for (i=1; i<=15; i++)
			{
				if (i == 11) continue;
				sTemp = "Totem_" + i;
				if (CheckCharacterItem(pchar, sTemp))
				{
					itm = ItemsFromID(sTemp);
					//если тотем еще не использован, то помечаем на укладку в button
					if (!CheckAttribute(itm, "shown.used"))
					{
						itm.shown = 0; 
					}
				}
			}
		}
		else
		{
			//близнецов расставим иначе
			int iTemp;
			for (i=1; i<=3; i++)
			{
				iTemp = GetCharacterIndex("GothicCitizen_"+i);
				if (iTemp != -1)
				{
					PlaceCharacter(&characters[iTemp], "goto", "random_free");
				}
			}
		}
	}
}

void CreatTenochtitlannInside(aref loc)
{
	if (loc.type == "tenotchitlan_inside")
	{
		ref sld;
		int iMassive, warriorQty, warriorRank, i, n;	
		string model[5];
		string sLocator;
		//----------------- генерим войнов в малых храмах богов -----------------
		if (CheckAttribute(loc, "smallGodTemple"))
		{
			chrDisableReloadToLocation = true;
			//определим кол-во войнов в храме
			warriorQty = sti(MOD_SKILL_ENEMY_RATE /2);
			if (warriorQty < 3) warriorQty = 3;
			//определим ранг войнов. обработаем от сложности, но не менее 15 уровня
			warriorRank = GetCoffDiff(sti(pchar.rank), 1000) + MOD_SKILL_ENEMY_RATE;
			if (warriorRank < 15) warriorRank = 15;
			//инкремент на кол-во посещений
			loc.smallGodTemple = sti(loc.smallGodTemple) + 1;
			warriorRank = warriorRank + sti(loc.smallGodTemple) * 4;
			//генерим ацтеков с неповторяемыми модельками
		    model[0] = "AztecWarrior1";
			model[1] = "AztecWarrior2";
			model[2] = "AztecWarrior3";
			model[3] = "AztecWarrior4";
			model[4] = "AztecWarrior5";
			i = 0;
			while(i < warriorQty)
			{
				iMassive = rand(4);
				if (model[iMassive] != "")
				{
					sld = GetCharacter(NPC_GenerateCharacter("AztecWarr"+loc.index+"_"+i, model[iMassive], "man", "man_A1", warriorRank, PIRATE, 0, true, "ORC"));
					SetFantomParamFromRank(sld, warriorRank, true);					
					while (FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE) != "")
					{
						TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE));
					}
					while (FindCharacterItemByGroup(sld, GUN_ITEM_TYPE) != "")
					{             
						TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, GUN_ITEM_TYPE));
					}
					GiveItem2Character(sld, "topor_01");
					EquipCharacterbyItem(sld, "topor_01");
					SetCharacterPerk(sld, "Energaiser"); 
				sld.viper = true;
		sld.name = GetRandName(NAMETYPE_AZTEC, NAME_MEXICO);
				sld.lastname = "";	
				SetCharacterPerk(chr, "Energaiser"); 
				SetCharacterPerk(chr, "BasicDefense"); 
				SetCharacterPerk(chr, "AdvancedDefense"); 
			SetCharacterPerk(chr, "ProfessionalDefense");
				SetCharacterPerk(chr, "CriticalHit");
				SetCharacterPerk(chr, "Tireless");
				SetCharacterPerk(chr, "Sliding");
				SetCharacterPerk(chr, "Gunman");
				SetCharacterPerk(chr, "GunProfessional"); 
				SetCharacterPerk(chr, "Sniper"); 
				SetCharacterPerk(chr, "HPPlus"); 
				SetCharacterPerk(chr, "EnergyPlus");
			SetCharacterPerk(chr, "SwordplayProfessional");
				SetCharacterPerk(chr, "HardHitter");
				SetCharacterPerk(chr, "BladeDancer");
				SetCharacterPerk(chr, "Grus"); 
				SetCharacterPerk(chr, "CriticalHit");
				if (sti(loc.smallGodTemple) > 1 && MOD_SKILL_ENEMY_RATE > 1)
					{
				SetCharacterPerk(chr, "Energaiser"); 	
				SetCharacterPerk(chr, "Energaiser"); 
				SetCharacterPerk(chr, "BasicDefense"); 
				SetCharacterPerk(chr, "AdvancedDefense"); 
				SetCharacterPerk(chr, "CriticalHit");
				SetCharacterPerk(chr, "Tireless");
				SetCharacterPerk(chr, "Sliding");
				SetCharacterPerk(chr, "Gunman");
				SetCharacterPerk(chr, "GunProfessional"); 
				SetCharacterPerk(chr, "Sniper"); 
				SetCharacterPerk(chr, "HPPlus"); 
				SetCharacterPerk(chr, "EnergyPlus");
			SetCharacterPerk(chr, "ProfessionalDefense");
			SetCharacterPerk(chr, "SwordplayProfessional");
				SetCharacterPerk(chr, "HardHitter");
				SetCharacterPerk(chr, "BladeDancer");
				SetCharacterPerk(chr, "Grus");  
				SetCharacterPerk(chr, "CriticalHit");
			sld.MultiFighter = 1.5; // мультифайтер
			sld.MultiShooter = 1.5;
						TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
					}
					PlaceCharacter(sld, "goto", "random_free");

					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, "tenoc_monsters_group");
					i++;
					model[iMassive] = "";
				}
			}
	PlaySound("People Fight\americas_charge_large.wav");
			LAi_group_SetRelation("tenoc_monsters_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("tenoc_monsters_group", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("tenoc_monsters_group", "OpenTheDoors");
		}
		//----------------- генерим войнов в большом храме -----------------
		if (CheckAttribute(loc, "greatTemplee") && locations[reload_cur_location_index].id == "Tenochtitlan_1")
		{
			LAi_group_Delete("tenoc_monsters_group");
			//определим кол-во войнов в храме
			warriorQty = 4;
			if (MOD_SKILL_ENEMY_RATE > 6) warriorQty = 5;
			if (MOD_SKILL_ENEMY_RATE <= 1) warriorQty = 3;
			//определим ранг войнов. обработаем от сложности, но не менее 20 уровня
			warriorRank = GetCoffDiff(sti(pchar.rank), 1000) + MOD_SKILL_ENEMY_RATE;
			if (warriorRank < 20) warriorRank = 20;
			//генерим ацтеков
			for (n=1; n<=7; n++)
			{
		    	model[0] = "AztecWarrior1";
			model[1] = "AztecWarrior2";
			model[2] = "AztecWarrior3";
			model[3] = "AztecWarrior4";
			model[4] = "AztecWarrior5";	
				i = 0;
				while(i < warriorQty)
				{
					iMassive = rand(4);
					if (model[iMassive] != "")
					{
			sld = GetCharacter(NPC_GenerateCharacter("AztecWarr"+loc.index+"_"+n+""+i, model[iMassive], "man", "man_A1", warriorRank, PIRATE, 0, true, "ORC"));
						SetFantomParamFromRank(sld, 15, true);					
						while (FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE) != "")
						{
							TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE));
						}
						while (FindCharacterItemByGroup(sld, GUN_ITEM_TYPE) != "")
						{             
							TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, GUN_ITEM_TYPE));
						}
						GiveItem2Character(sld, "topor_01");
				EquipCharacterbyItem(sld, "topor_01");
				sld.viper = true;
		sld.name = GetRandName(NAMETYPE_AZTEC, NAME_MEXICO);
				sld.lastname = "";
				SetCharacterPerk(chr, "Energaiser"); 
				SetCharacterPerk(chr, "BasicDefense"); 
				SetCharacterPerk(chr, "AdvancedDefense"); 
				SetCharacterPerk(chr, "CriticalHit");
				SetCharacterPerk(chr, "Tireless");
				SetCharacterPerk(chr, "Sliding");
				SetCharacterPerk(chr, "Gunman");
				SetCharacterPerk(chr, "GunProfessional"); 
				SetCharacterPerk(chr, "Sniper"); 
				SetCharacterPerk(chr, "HPPlus"); 
				SetCharacterPerk(chr, "EnergyPlus");
			SetCharacterPerk(chr, "SwordplayProfessional");
				SetCharacterPerk(chr, "HardHitter");
				SetCharacterPerk(chr, "BladeDancer");
				SetCharacterPerk(chr, "Grus"); 
			SetCharacterPerk(chr, "ProfessionalDefense"); 
				SetCharacterPerk(chr, "CriticalHit");

						if (MOD_SKILL_ENEMY_RATE > 5)
						{
				SetCharacterPerk(chr, "Energaiser"); 
				SetCharacterPerk(chr, "BasicDefense"); 
				SetCharacterPerk(chr, "AdvancedDefense"); 
				SetCharacterPerk(chr, "CriticalHit");
				SetCharacterPerk(chr, "Tireless");
				SetCharacterPerk(chr, "Sliding");
				SetCharacterPerk(chr, "Gunman");
				SetCharacterPerk(chr, "GunProfessional"); 
				SetCharacterPerk(chr, "Sniper"); 
				SetCharacterPerk(chr, "HPPlus"); 
				SetCharacterPerk(chr, "EnergyPlus");
			SetCharacterPerk(chr, "SwordplayProfessional");
				SetCharacterPerk(chr, "HardHitter");
				SetCharacterPerk(chr, "BladeDancer");
				SetCharacterPerk(chr, "Grus"); 
			SetCharacterPerk(chr, "ProfessionalDefense"); 
				SetCharacterPerk(chr, "CriticalHit");
							TakeNItems(sld,"potion2", rand(3)+1);
						}

						sLocator = "monster"+n;
						ChangeCharacterAddressGroup(sld, loc.id, "monsters", sLocator+(i+1));

						LAi_SetWarriorType(sld);
						LAi_warrior_SetStay(sld, true);
						LAi_warrior_DialogEnable(sld, false);
						LAi_group_MoveCharacter(sld, "tenoc_monsters_group");
						i++;
						model[iMassive] = "";
					}
				}
			}
			LAi_group_SetRelation("tenoc_monsters_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		}
	}
}
void CreatDesMoines(aref loc)
{
	ref sld;
	bool bImmortal;
	int i, iMassive;
	string sSex, sNode, sModel;
	string model[10]; 
	if (pchar.questTemp.MC != "Incquisitio")
	{
		if (loc.id == "DesMoines_town")
		{
			if (GetHour() > 6.0 && GetHour() < 21.99)
			{
				model[0] = "citiz_11";
				model[1] = "citiz_3";
				model[2] = "citiz_5";
				model[3] = "citiz_9";
				model[4] = "citiz_11";
				model[5] = "shipowner_1";
				model[6] = "shipowner_12";
				model[7] = "shipowner_2";
				model[8] = "trader_4";
				model[9] = "barmen_6";
				sSex = "man";
				sNode = "DMCitiz";
				sModel = "Torres";
				bImmortal = false;
			}
			else
			{
				if (pchar.questTemp.MC == "over")
				{
					model[0] = "citiz_11";
					model[1] = "citiz_3";
					model[2] = "citiz_5";
					model[3] = "citiz_9";
					model[4] = "citiz_11";
					model[5] = "shipowner_1";
					model[6] = "shipowner_12";
					model[7] = "shipowner_2";
					model[8] = "trader_4";
					model[9] = "barmen_6";
					sSex = "man";
					sNode = "DMCitiz";
					sModel = "Torres";
					bImmortal = false;
				}
				else
				{
					model[0] = "skel1";
					model[1] = "skel2";
					model[2] = "skel3";
					model[3] = "skel4";
					model[4] = "skel1";
					model[5] = "skel2";
					model[6] = "skel3";
					model[7] = "skel4";
					model[8] = "skel1";
					model[9] = "skel2";
					sSex = "skeleton"
					sNode = "DMSkel";
					sModel = "skeletcap";
					bImmortal = true;
				}
			}
			i = 0;
			while(i < 8)
			{
				iMassive = rand(9);
				if (model[iMassive] != "")
				{
					sld = GetCharacter(NPC_GenerateCharacter("MCCitiz_"+i, model[iMassive], sSex, "man", 15, SPAIN, 0, true, "quest"));
					sld.dialog.filename = "Gothic_Quest\MagicCity.c";
					sld.dialog.currentnode = sNode;
					sld.greeting = "cit_common";
					sld.city = "DesMoines";
					LAi_RemoveLoginTime(sld);
					LAi_SetImmortal(sld, bImmortal);
					PlaceCharacter(sld, "goto", "random_free");
					LAi_SetCitizenType(sld);
					LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
					i++;
					model[iMassive] = "";
				}
			}
		}
		if (loc.id == "DesMoines_Townhall")
		{
			if (GetHour() > 6.0 && GetHour() < 21.99 )
			{	
				sSex = "man";
				sNode = "DMCitiz";
				sModel = "Torres";
				bImmortal = false;
			}
			else
			{
				if (pchar.questTemp.MC == "over")
				{
					sSex = "man";
					sNode = "DMCitiz";
					sModel = "Torres";
					bImmortal = false;
				}
				else
				{
					sSex = "skeleton"
					sNode = "DMSkel";
					sModel = "skeletcap";
					bImmortal = true;
				}
			}
			//глава поселения
			sld = GetCharacter(NPC_GenerateCharacter("DesMoinesHead", sModel, sSex, "man", 25, SPAIN, 0, true, "quest"));
			sld.name = "Фернандо";
			sld.lastname = "Торрес";	
			sld.dialog.filename = "Gothic_Quest\MagicCity.c";
			sld.dialog.currentnode = sNode + "Head";
			sld.greeting = "pirat_common";
			sld.city = "DesMoines";
			sld.watchBoxes = true;
			sld.watchBoxes.exitDisable = true; 
			LAi_RemoveLoginTime(sld);
			LAi_SetImmortal(sld, bImmortal);
			ChangeCharacterAddressGroup(sld, "DesMoines_Townhall", "goto", "goto1");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
		}
	}
}

//Город погибших кораблей
void CreateLostShipsCityy(aref loc)
{	
	int i;
	if (loc.id == "LostShipsCityy_town" && isDay())
	{
		ref sld;
		string sTemp, sLocator;
		int locNum, n, Index;
		int qtyTavern = 0; 
		int qtyResidence = 0;
		int qtyChurch = 0;
		int qtyPrison = 0;
		int qtyStore = 0;
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (sld.location == "FleuronTavernn") qtyTavern++;
			if (sld.location == "SanAugustineResidencee") qtyResidence++;
			if (sld.location == "GloriaChurchh") qtyChurch++;
			if (sld.location == "TartarusPrisonn") qtyPrison++;
			if (sld.location == "EsmeraldaStoreBigg") qtyStore++;
		}
		//размещаем нпс
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "city") && sld.city == "LostShipsCityy")
			{
				//////// если это адмирал /////////
				if (sld.cityTape == "mayor")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours))
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 19.0 && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == "SanAugustineResidencee") //если адмирал в резиденции
						{
							if (rand(1))	//вероятность выхода из резиденции
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(5)+1;
								if (rand(1))
								{	//выходим на улицы
									//проверим занятость локатора								
									if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
									{	//выберем незанятый 
										sTemp = sld.location.baseLocator;									
										sTemp = strcut(sTemp, 4, 5);
										for (n=0; n<=9; n++)
										{											
											sLocator = "goto" + sTemp + "_" + n;
											if (LAi_CheckLocatorFree("goto", sLocator))
											{
												LAi_SetLSCoutTypeNoGroup(sld);
												ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sLocator);
												break;
											}
										}
									}
									else
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
									}
								}
								else
								{	//в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
								}
							}
						}
						else
						{	//рулим в резиденцию
							LAi_SetHuberTypeNoGroup(sld); //садим за стол
							ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "sit", "sit1");
						}
					}
				}
				//////// если это менты /////////
				if (sld.cityTape == "ment")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours)) 
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						//if (rand(1)) LAi_SetLoginTime(sld, 6.0, 21.99);
						//else LAi_RemoveLoginTime(sld);
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 20.0 && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == "LostShipsCityy_town") //если мент на улице
						{
							if (rand(1))
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(5)+1;
								switch (rand(2))
								{
								case 0: //в резиденцию к шефу
									if (qtyResidence < LSC_MAX_RESIDENCE)
									{
										qtyResidence++;
										LAi_SetWarriorTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "goto", "goto"+qtyResidence);
									}
									break;
								case 1: //в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
									break;
								case 2: //в тюрьму
									if (qtyPrison < LSC_MAX_PRISON)
									{
										qtyPrison++;
										LAi_SetWarriorTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "TartarusPrisonn", "goto", "goto"+qtyPrison);
									}
									break;									
								}
							}
						}
						else
						{	//возвращемся на варшип
							//проверим занятость локатора								
							if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
							{	//выберем незанятый 
								sTemp = sld.location.baseLocator;									
								sTemp = strcut(sTemp, 4, 5);
								for (n=0; n<=9; n++)
								{											
									sLocator = "goto" + sTemp + "_" + n;
									if (LAi_CheckLocatorFree("goto", sLocator))
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sLocator);
										break;
									}
								}
							}
							else
							{
								LAi_SetLSCoutTypeNoGroup(sld);
								ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
							}
						}
					}
				}
				//////// если внешний горожанин /////////
				if (sld.cityTape == "citizen")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours)) 
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						LAi_SetLoginTime(sld, 6.0, 21.99);
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 19.0 && sld.sex == "man" && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == "LostShipsCityy_town") //если горожанин на улице
						{
							if (rand(1))
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(3)+1;
								switch (rand(2))
								{
								case 0: //в церковь
									if (qtyChurch < LSC_MAX_CHURCH)
									{
										sld.location.going = "toChurch"; //флаг генерации в церкви
										qtyChurch++;
									}
									break;
								case 1: //в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
									break;
								case 2: //в магазин
									if (qtyStore < LSC_MAX_STORE)
									{
										sld.location.going = "toStore"; //флаг генерации в магазине	
										qtyStore++;
									}
									break;									
								}
							}
						}
						else
						{	//возвращемся на свой корабль
							//проверим занятость локатора								
							if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
							{	//выберем незанятый 
								sTemp = sld.location.baseLocator;
								sTemp = strcut(sTemp, 4, 5);
								for (n=0; n<=9; n++)
								{											
									sLocator = "goto" + sTemp + "_" + n;
									if (LAi_CheckLocatorFree("goto", sLocator))
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sLocator);
										break;
									}
								}
							}
							else
							{
								LAi_SetLSCoutTypeNoGroup(sld);
								ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
							}
						}
					}
				}
				//////// если домашний горожанин /////////
				if (sld.cityTape == "citizenHome")
				{
					if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours)) 
					{
						DeleteAttribute(sld, "location.going"); //снимаем флаг
						LAi_SetLoginTime(sld, 6.0, 21.99);
						//--> вечером организовываем толпу в таверне
						if (GetTime() > 19.0 && sld.sex == "man" && rand(1))
						{
							if (qtyTavern < LSC_MAX_TAVERN)
							{
								sld.location.going = "toTavern"; //флаг генерации в таверне
								qtyTavern++;
							}
							continue;
						}
						//<-- вечером организовываем толпу в таверне
						if (sld.location == sld.location.baseLocation) //если горожанин у себя дома
						{
							if (rand(1))
							{
								SaveCurrentNpcQuestDateParam(sld, "location");
								sld.location.hours = rand(6)+1;
								switch (rand(3))
								{
								case 0: //в церковь
									if (qtyChurch < LSC_MAX_CHURCH)
									{
										sld.location.going = "toChurch"; //флаг генерации в церкви
										qtyChurch++;
									}
									break;
								case 1: //в таверну
									if (qtyTavern < LSC_MAX_TAVERN)
									{
										sld.location.going = "toTavern"; //флаг генерации в таверне
										qtyTavern++;
									}
									break;
								case 2: //в магазин
									if (qtyStore < LSC_MAX_STORE)
									{
										sld.location.going = "toStore"; //флаг генерации в магазине	
										qtyStore++;
									}
									break;	
								case 3: //на улицы
									//проверим занятость локатора								
									if (!LAi_CheckLocatorFree("goto", sld.location.baseLocator))
									{	//выберем незанятый 
										sTemp = sld.location.baseLocator;
										sTemp = strcut(sTemp, 4, 5);
										for (n=0; n<=9; n++)
										{											
											sLocator = "goto" + sTemp + "_" + n;
											if (LAi_CheckLocatorFree("goto", sLocator))
											{
												LAi_SetLSCoutTypeNoGroup(sld);
												ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sLocator);
												break;
											}
										}
									}
									else
									{
										LAi_SetLSCoutTypeNoGroup(sld);
										ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
									}
									break;	
								}
							}
						}
						else
						{	//возвращемся на свой корабль
							LAi_SetOwnerTypeNoGroup(sld);
							ChangeCharacterAddressGroup(sld, sld.location.baseLocation, "barmen", "stay");
						}
					}
				}
			}
		}
	}
	//------------------- таверна ------------------------
	if (loc.id == "FleuronTavernn")
	{
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "location.going") && sld.location.going == "toTavern")
			{
				DeleteAttribute(sld, "location.going");
				LAi_RemoveLoginTime(sld);
				if (sld.sex == "man")
				{
					DeleteAttribute(sld, "nonTable");
					LAi_SetSitTypeNoGroup(sld);
					if (sld.id == "LSCCMayor")
						ChangeCharacterAddressGroup(sld, loc.id, "quest", "head_sit");
					else
						PlaceCharacter(sld, "sit", "random_free");
				}
				else
				{
					LAi_SetCitizenTypeNoGroup(sld);
					PlaceCharacter(sld, "goto", "random_free");
				}
			}
		}
	}
	//------------------- церковь ------------------------
	if (loc.id == "GloriaChurchh")
	{
		//сам падре
		if (!isDay())
		{
			Index = GetCharacterIndex("LSCC_Priest");	
			if (Index != -1)
			{
				sld = &characters[Index];
				LAi_SetSitTypeNoGroup(sld);
				PlaceCharacter(sld, "quest", "priest");
			}
		}
		else
		{
			for(i=0; i<MAX_CHARACTERS; i++)
			{
				makeref(sld, characters[i]);
				//падре днем
				if (sld.id == "LSCC_Priest")
				{
					LAi_SetPriestTypeNoGroup(sld);
					ChangeCharacterAddressGroup(sld, sld.location, "barmen",  "stay");
				}
				//граждане
				if (CheckAttribute(sld, "location.going") && sld.location.going == "toChurch")
				{
					DeleteAttribute(sld, "location.going");
					if (sld.sex == "woman")
					{
						LAi_SetCitizenTypeNoGroup(sld);
						PlaceCharacter(sld, "goto", "random_free");
					}
					else
					{
						sld.nonTable = true;
						LAi_SetSitTypeNoGroup(sld);
						PlaceCharacter(sld, "sit", "random_free");
					}
				}
			}
		}
	}
	//------------------- магазин ------------------------
	if (loc.id == "EsmeraldaStoreBigg")
	{
		for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(sld, characters[i]);
			if (CheckAttribute(sld, "location.going") && sld.location.going == "toStore")
			{
				DeleteAttribute(sld, "location.going");
                LAi_SetStayTypeNoGroup(sld);
				PlaceCharacter(sld, "goto", "random_free");
			}
		}
	}
	//------------------- тюрьма ------------------- 
	if (loc.id == "TartarusPrisonn")
	{
		Index = GetCharacterIndex("LSCC_PrisonerHead");
		if (Index != -1)
		{
			sld = &characters[Index];
			if (GetNpcQuestPastDayParam(sld, "location") > sti(sld.location.days))
			{
				SaveCurrentNpcQuestDateParam(sld, "location");
				if (rand(1))	
				{
					LAi_SetHuberTypeNoGroup(sld);
					ChangeCharacterAddressGroup(sld, loc.id, "sit", "sit1");
				}
				else
				{
					LAi_SetWarriorTypeNoGroup(sld);
					PlaceCharacter(sld, "goto", "random_free");
				}
			}
		}
		Index = GetCharacterIndex("LSCC_Prisoner1");
		if (Index != -1)
		{
			sld = &characters[Index];
			if (GetNpcQuestPastTimeParam(sld, "location") > sti(sld.location.hours))
			{
				SaveCurrentNpcQuestDateParam(sld, "location");
				if (rand(1))	
				{
					LAi_SetSitTypeNoGroup(sld);
					ChangeCharacterAddressGroup(sld, loc.id, "sit", "sit2");
				}
				else
				{
					LAi_SetWarriorTypeNoGroup(sld);
					PlaceCharacter(sld, "goto", "random_free");
				}
			}
		}
	}
} 

void CreatUnderwaterr(aref loc)
{
	if (loc.type == "underwater")
	{
		if (CheckAttribute(loc, "type.LSCC"))
			{

				LocatorReloadEnterDisable("LostShipsCityy_town", "reload72", true); //закрываем вход в Феникс
				LocatorReloadEnterDisable("SanGabrielMechanicc", "reload3", true); //закрываем выход от Механика
				DeleteAttribute(pchar, "questTemp.LSCC.immersion");
				pchar.questTemp.LSCC.UW_end = "true"; // сдача костюма
				SetShowTimer(500.0); //таймер на 20 игровых минут
				AddCharacterHealth(pchar, -3); //портим здоровье
			for (int i=1; i<=16; i++)
			{
				if (GetCharacterIndex("Crab_"+i) == -1)
				{
					sld = GetCharacter(NPC_GenerateCharacter("Crab_"+i, "crabBig", "crab", "crabBig", 40+(MOD_SKILL_ENEMY_RATE), PIRATE, -1, false, "quest"));
					GiveItem2Character(sld, "unarmed");
					EquipCharacterbyItem(sld, "unarmed");
					LAi_SetWarriorType(sld);
					LAi_warrior_SetStay(sld, true);
					LAi_warrior_DialogEnable(sld, false);
					LAi_group_MoveCharacter(sld, LAI_GROUP_MONSTERS);
				}
				PlaceCharacter(sld, "goto", "random_free");
			}
		}
		else
		{
			if (CheckAttribute(loc, "watertemple")) SetShowTimer(500.0); // 010912
			else SetShowTimer(160.0); //таймер
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Воздушный шар
/////////////////////////////////////////////////////////////////////////////////////////////
void BalloonInit()
{
	PChar.Balloon.Height = BALLOON_MIN_HEIGHT;
	PChar.Balloon.ShipIdx = 0;
	//bBalloonAction = false;
}

int GetCurBalloonHeight()
{
	if(CheckAttribute(PChar, "Balloon.Height"))
	{
		return sti(PChar.Balloon.Height);
	}

	return BALLOON_MIN_HEIGHT;
}

void SetBalloonNewHeight(int iHeight, ref rCharacter, aref arCharBalloon)
{
	if(iHeight > BALLOON_MAX_HEIGHT) { iHeight = BALLOON_MAX_HEIGHT; }
	if(iHeight < BALLOON_MIN_HEIGHT) { iHeight = BALLOON_MIN_HEIGHT; }
	
	PChar.Balloon.Height = iHeight;
	
	//ref rShip = GetShipByType(SHIP_BALLOON);
	ref rShip = GetRealShip(SHIP_BALLOON);
	rShip.WaterLine = -stf(iHeight);
	
	int iBalloonIdx = sti(PChar.Balloon.ShipIdx);
	rShip = GetRealShip(iBalloonIdx);
	rShip.WaterLine = -stf(iHeight);

                float   fMaxSpeedZ = 0.0;
                float   fWindAgainstSpeed;
	fMaxSpeedZ 			= stf(arCharBalloon.MaxSpeedZ);	
	fWindAgainstSpeed   =  FindShipWindAgainstSpeed(rCharacter);
	arCharBalloon.WindAgainstSpeed = cos(1.0 - fWindAgainstSpeed) * -180.0/PI;

}



