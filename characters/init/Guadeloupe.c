
int CreateGuadeloupeCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "BasTer_Mayor";
	ch.model	= "huber_5";
	ch.sex = "man";
	ch.name 	= "Клод Франсуа";
    ch.lastname = "де Лион";
	ch.City = "BasTer";
	ch.location	= "BasTer_townhall";
	ch.greeting = "mayor_4";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.nation = FRANCE;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "BasTer_Priest";
	ch.model	= "priest_1";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location	= "BasTer_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_2";
	ch.nation = FRANCE;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "BasTer_waitress";
	ch.model	= "women_12";
	ch.sex = "woman";
	ch.City = "BasTer";
	ch.location	= "BasTer_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = FRANCE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "BasTer_tavernkeeper";
	ch.model	= "barmen_7";
	ch.greeting = "barmen_3";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location	= "BasTer_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = FRANCE;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "BasTer_trader";
	ch.model	= "trader_7";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location	= "BasTer_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = FRANCE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "BasTer_shipyarder";
	ch.model	= "shipowner_7";
	ch.greeting = "shipyarder_2";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location	= "BasTer_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = FRANCE;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor_02");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "topor_02"); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "BasTer_usurer";
	ch.model	= "banker_7";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "BasTer_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = FRANCE;
	ch.greeting = "usurer_4";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 10000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "BasTer_PortMan";
	ch.model	= "citiz_4";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location	= "BasTer_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = FRANCE;
	ch.greeting = "portman_3";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

                   makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "BasTer_Smuggler";
	ch.model    = "citiz_29";
	ch.sex      = "man";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	EquipCharacterbyItem(ch, BLADE_SABER);
	// посадим в генераторе
	ch.Dialog.Filename = "Smuggler Agent_dialog.c";
	LAi_SetSitType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "smuggler";
	n = n + 1;

	makeref(ch,Characters[n]);			//Смотритель маяка
	ch.id		= "BasTer_Lightman";
	ch.model	= "keeper_7";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "BasTer";
	ch.location = "Mayak4_Lighthouseroom";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Common_lighthouse.c";
	ch.greeting = "lighthouseman_3";
	ch.Merchant = true;
	ch.Merchant.type = "lightman";
	ch.artefact.indian = true;
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	ch.nation = FRANCE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	//////////////////=====>>>> Магический квест Аскольда.
                        makeref(ch,Characters[n]);		// Аскольд
	ch.name 	= "Аскольд";
	ch.lastname = "";
	ch.id		= "Ascold";
	ch.model	= "Corsair1_2";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.location	= "BasTer_houseSp1";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.Dialog.Filename = "Gothic_Quest\Ascold.c";
	ch.nation = PIRATE;
                        ch.rank 	= 38;
	ch.reputation = "15";
                        SetSelfSkill(ch, 90, 90, 90, 70, 90);
                        SetShipSkill(ch, 20, 90, 10, 10, 10, 20, 10, 10, 50);
                        LAi_NoRebirthDisable(ch);  // воскресть при убиении
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Ascold";
	n = n+1;

	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Барон
	ch.id		= "LEE";
	ch.sex = "man";
	ch.model = "Lee";
	ch.name = "Генерал Ли";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "SantLous";
	ch.location	= "SantLous_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\LEE.c";
	ch.greeting = "_Gr_LEE";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
	GiveItem2Character(ch, "blade_23");
	ch.equip.blade = "blade_23";
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	ch.money = "2377";
	ch.rank = 45;
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
	ch.nation = PIRATE;
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "SantLous_trader";
	ch.model	= "trader_14";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "SantLous";
	ch.location	= "SantLous_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	ch.Merchant = true;
	ch.Merchant.type = "SantLous";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "BasTer_waitress";
	ch.model	= "Women_21";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "SantLous";
	ch.location	= "SantLous_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "tavern\SantLous_Waitress.c";
	ch.greeting = "Gr_officiant";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "SantLous_tavernkeeper";
	ch.model	= "Thekla_Wom_1";
	ch.model.animation = "towngirl";
	ch.name 	= "Тёкла";
	ch.lastname = "";
	ch.greeting = "Gr_Thekla";
	ch.sex = "woman";
	ch.City = "Sant_Lous";
	ch.location	= "SantLous_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "tavern\SantLous_Tavern.c";
	ch.TavernMan = true;
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Заведующий  складом 
	ch.id		= "SantLous_SkladMan";
	ch.model	= "citiz_"+(rand(9)+1);
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Sant_Lous";
	ch.location = "SantLous_Packhouse";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "HouseEnc_dialog.c";
	ch.dialog.currentnode = "SkladMan";
	ch.greeting = "official";
	ch.nation = PIRATE;
	LAi_SetHuberType(ch);	
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.Storage 	  = true;
	n = n + 1; 

	makeref(ch,Characters[n]);			//Торговка
	ch.id		= "SantLous_ItemTrader";
	ch.model	= "gipsy_4";
	ch.greeting = "gipsy";
	ch.sex = "woman";
	ch.City = "SantLous";
	ch.location	= "SantLous_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Common_ItemTrader.c";
	ch.dialog.currentnode   = "first time";
	LAi_SetLoginTime(ch, 9.0, 20.99);
	LAi_SetMerchantType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

      makeref(ch,Characters[n]);
	ch.id		= "SantLous_citizen";
	ch.model    = "Sailhard";
	ch.greeting = "Diplomat";
	ch.model.animation = "man2";
	ch.sex      = "man";
	ch.name 	= "Роберто";
	ch.lastname = "Сайлхард";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.nation = PIRATE;
	ch.location	= "SantLous_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.CityType = "citizen";
	GiveItem2Character(ch, "pistol_04");
	ch.equip.gun = "pistol_04";
	GiveItem2Character(ch, "newblade20");
	ch.equip.blade = "newblade20";
	// посадим в генераторе
	ch.Dialog.Filename = "Gothic_Quest\npc\RelationAgent_dialog.c";
	LAi_SetSitType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	n = n + 1;


	///////////////////////////////////////////////////////////////////////////////
	// ГОРОДСКИЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
	return n;
}
