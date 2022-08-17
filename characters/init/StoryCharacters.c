int CreateStoryCharacters(int n)
{
   /* ref ch;
    ///////////////////////////////////
    makeref(ch,Characters[n]);		// ГУБЕРНАТОР Англия
	ch.name 	= "граф Джеймс";
	ch.lastname = "Карлайл";
	ch.id		= "eng_guber";
	ch.model	= "Modyford";
	ch.model.animation	= "man";
	ch.sex = "man";
	ch.location	= "PortRoyal_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = ENGLAND;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Испания
	ch.name 	= "дон Энрике";
	//ch.middlename = "";
	ch.lastname = "Суарец де Нибла";
	ch.id		= "spa_guber";
	ch.model	= "Gaskon";
	ch.model.animation	= "man";
	ch.sex = "man";
	ch.location	= "Muelle_Residence";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = SPAIN;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Франция
	ch.name 	= "шевалье Филлип Лонвийе";
	ch.lastname = "де Пуанси";
	ch.id		= "fra_guber";
	ch.model	= "dOgeron";
	ch.sex = "man";
	ch.location	= "Tortuga_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = FRANCE;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Голландия
	ch.name 	= "Матиас";
	ch.lastname = "Бек";
	ch.id		= "holl_guber";
	ch.model	= "huber_25";
	ch.sex = "man";
	ch.location	= "Villemstad_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = HOLLAND;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.notMoveAble = true; //не переезжать
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;*/

//============== Генри Морган! Всем трепетать. =================

    ref ch;

                   makeref(ch,Characters[n]);
	ch.name 	= "Генри";
	ch.lastname = "Морган";
	ch.id		= "Henry Morgan";
	ch.model	= "Morgan";
	ch.model.animation = "man"; 
	ch.sex = "man";
	ch.location	= "PortRoyal_houseS1";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Gothic_Quest\Morgan.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "blade_25");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "blade_25"); 
	// ==> Кораблик Моргану делаем с хорошими пушками
	ch.Abordage.Enable = false; // НЕЛЬЗЯ!
	ch.Ship.Name = "Ужасающий";
	ch.Ship.Type = GenerateShipExt(SHIP_LINESHIP, true, ch);
	ch.Ship.Stopped = true;
   	ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS48;
                   SetCrewQuantityFull(ch);
                   Fantom_SetBalls(ch, "pirate");    
                   ch.rank = 45;
                   SetRandSPECIAL(ch);
                   SetSelfSkill(ch, 90, 90, 90, 60, 70);
                   SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	ch.money = "50000";
	SetCharacterPerk(ch, "FastReload");
	SetCharacterPerk(ch, "HullDamageUp");
	SetCharacterPerk(ch, "SailsDamageUp");
	SetCharacterPerk(ch, "CrewDamageUp");
	SetCharacterPerk(ch, "CriticalShoot");
	SetCharacterPerk(ch, "LongRangeShoot");
	SetCharacterPerk(ch, "CannonProfessional");
	SetCharacterPerk(ch, "ShipDefenseProfessional");
	SetCharacterPerk(ch, "ShipSpeedUp");
	SetCharacterPerk(ch, "ShipTurnRateUp");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
	LAi_NoRebirthDisable(ch);
	LAi_RebirthOldName(ch);
	LAi_SetHuberType(ch);
	ch.standUp = true; //вставать и нападать на врага
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetImmortal(ch, true);
	ch.MultiFighter = 3.0; // мультифайтер
	ch.MultiShooter = 3.0;
	ch.SuperShooter  = true;
	LAi_SetHP(ch, 230.0, 230.0);
	ch.greeting = "Gr_Morgan";
	n = n + 1;

//============== Секретать Моргана, можно расслабиться. =================
	makeref(ch,Characters[n]);
	ch.name 	= "Оливер";
	ch.lastname = "Грин";
	ch.id		= "Oliver_Green";
	ch.model	= "Helper";
	ch.sex = "man";
                   ch.model.animation = "man";
	ch.location	= "PortRoyal_houseS1";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Gothic_Quest\OliverGreen.c";
                   SetRandSPECIAL(ch);
                   SetSelfSkill(ch, 90, 90, 90, 60, 70);
                   SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	ch.greeting = "Gr_OliverGreen";
	ch.nation = PIRATE;
	ch.rank 	= 20;
	LAi_NoRebirthDisable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	//ch.standUp = true; //вставать и нападать на врага
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	n=n+1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Франция
	ch.name 	= "лорд Андре";
	ch.lastname = "";
	ch.id		= "SantoDomingo_Mayor";
	ch.model	= "dOgeron";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.nation = FRANCE;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	n = n + 1;

//============== Капитан Шарп =================
                     makeref(ch,Characters[n]);
	ch.name 	= "Бартоломью";
	ch.lastname = "Шарп";
	ch.id		= "Sharp";
	ch.model	= "Sharp";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	ch.Dialog.CurrentNode = "CitySharp"; //нода суша
	ch.DeckDialogNode = "DeckSharp"; //нода палуба
	ch.nation = PIRATE;
	GiveItem2Character(ch, GUN_COMMON);
	ch.equip.gun = GUN_COMMON;
	GiveItem2Character(ch, "blade_25");
	ch.equip.blade = "blade_25";
	// ==> Кораблик 
	ch.Ship.Name = "Шарпоносец";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.Ship.Type = GenerateShipExt(SHIP_VALCIRIA, true, ch);
	ch.Ship.Stopped = true;
   	ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.Ship.Mode = "mercenary";
	SetCrewQuantityFull(ch);
                     Fantom_SetBalls(ch, "pirate");
	SetRandGeraldSail(ch, sti(ch.Nation));
                    ch.rank = 20;
                    SetRandSPECIAL(ch);
                    SetSelfSkill(ch, 60, 60, 60, 60, 60);
                    SetShipSkill(ch, 70, 70, 70, 70, 60, 60, 30, 60, 50);
	ch.money = "1120";
	ch.AlwaysSandbankManeuver = true;
	ch.BreakTmplAndFight = true; //актеру. если атакован, то прервать темплейт и стать warrior
	SetCharacterPerk(ch, "FastReload");
	SetCharacterPerk(ch, "HullDamageUp");
	SetCharacterPerk(ch, "SailsDamageUp");
	SetCharacterPerk(ch, "CrewDamageUp");
	SetCharacterPerk(ch, "CriticalShoot");
	SetCharacterPerk(ch, "LongRangeShoot");
	SetCharacterPerk(ch, "CannonProfessional");
	SetCharacterPerk(ch, "ShipDefenseProfessional");
	SetCharacterPerk(ch, "ShipSpeedUp");
	SetCharacterPerk(ch, "ShipTurnRateUp");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.greeting = "Gr_MiddPirate";
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER_OWN);
	n = n + 1;

//============== просто персонажи =================


	makeref(ch,Characters[n]);	
	ch.id		= "LostShipsCityy_tavernkeeper";
	ch.model	= "";
	ch.sex = "man";
	n = n + 1;

	makeref(ch,Characters[n]);	
	ch.id		= "error_tavernkeeper";
	ch.model	= "";
	ch.sex = "man";
	n = n + 1;

	makeref(ch,Characters[n]);	
	ch.id		= "FMQL_Johnny";
	ch.model	= "";
	ch.sex = "man";
	n = n + 1;

	makeref(ch,Characters[n]);	
	ch.id		= "fra_guber";
	ch.model	= "";
	ch.sex = "man";
	n = n + 1;
   	
	return n;
}