
int CreateJamaicaCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "PortRoyal_Mayor";
	ch.model	= "huber_9";
	ch.sex = "man";
	ch.name 	= "Эдвард";
    ch.lastname = "Дойли";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_2";
	ch.nation = ENGLAND;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "PortRoyal_Priest";
	ch.model	= "priest_1";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_2";
	ch.nation = ENGLAND;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "PortRoyal_waitress";
	ch.model	= "women_14";
	ch.sex = "woman";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = ENGLAND;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "PortRoyal_tavernkeeper";
	ch.model	= "barmen_9";
	ch.greeting = "barmen_1";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = ENGLAND;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "PortRoyal_trader";
	ch.model	= "trader_9";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = ENGLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "PortRoyal_shipyarder";
	ch.model	= "shipowner_9_1";
	ch.name 	= "Олдживли";
    ch.lastname = "Морис";
	ch.greeting = "shipyarder_1";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = ENGLAND;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor_02");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "topor_02");
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "PortRoyal_usurer";
	ch.model	= "banker_9_1";
	ch.sex = "man";
	ch.name 	= "Мортимер";
	ch.lastname = "Хоуп";
	ch.City = "PortRoyal";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "PortRoyal_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = ENGLAND;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 9000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "PortRoyal_PortMan";
	ch.model	= "citiz_10";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = ENGLAND;
	ch.greeting = "portman_5";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "PortRoyal_Hostess";
	ch.name		= "Ида"
	ch.lastname = "";
	ch.model	= "maman_3";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "PortRoyal";
	ch.location	= "PortRoyal_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_2";
	ch.nation = ENGLAND;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	n = n + 1;

    makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "PortRoyal_Smuggler";
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
	
	makeref(ch,Characters[n]);			//Заведующий  складом на верфи
	ch.id		= "PortRoyal_SkladMan";
	ch.model	= "citiz_"+(rand(9)+1);
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location = "PortRoyal_Packhouse";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "HouseEnc_dialog.c";
	ch.dialog.currentnode = "SkladMan";
	ch.greeting = "official";
	ch.nation = ENGLAND;
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.Storage 	  = true;
	n = n + 1; 
	
	makeref(ch,Characters[n]);			//Смотритель кладбища
	ch.id		= "PortRoyal_Cemeteryman";
	ch.model	= "keeper_6";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "PortRoyal";
	ch.location = "PortRoyal_KeepersHouse";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Common_cemeteryman.c";
	ch.greeting = "lighthouseman_2";
	ch.Merchant = true;
	ch.Merchant.type = "cemeteryman";
	ch.money = TRADER_MIN_MONEY;
	ch.nation = ENGLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;
	
   //=============== Саванна-ла-Мар =============== // 170712

    makeref(ch,Characters[n]);			//Глава пиратов
	ch.id		= "Jackman";
	ch.name 	= "Якоб";
	ch.lastname = "Джекман";
	ch.rank = 30;
	ch.model	= "Jeckman";
	ch.sex = "man";
	ch.model.animation = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\Jackman.c";
	ch.greeting = "jackman";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	ch.reputation = "35";
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 70, 90);
    SetShipSkill(ch, 90, 80, 70, 10, 10, 20, 10, 10, 50);
	LAi_SetHP(ch, 200.0, 200.0);
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG);
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
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
	LAi_SetHuberType(ch);
    LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.MultiFighter = 3.0; // мультифайтер
	ch.MultiShooter = 3.0;
	ch.SuperShooter  = true;
	LAi_SetImmortal(ch, true);
	ch.watchBoxes = true;
	ch.standUp = true;
	n = n + 1;
   
	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "FortOrange_waitress";
	ch.model	= "women_9";
	ch.sex = "woman";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "FortOrange_tavernkeeper";
	ch.model	= "barmen_14";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "FortOrange_trader";
	ch.model	= "trader_14";
	ch.greeting = "store_3";
	ch.sex = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "FortOrange_Hostess";
	ch.name		= "Маргарита"
	ch.lastname = "";
	ch.model	= "maman_2";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_1";
	ch.nation = PIRATE;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "FortOrange_shipyarder";
	ch.name		= "Диззи"
	ch.lastname = "О'Абандонед";
	ch.model	= "verfist_2";
	ch.greeting = "shipyarder_2";
	ch.sex = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = PIRATE;
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
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "FortOrange_usurer";
	ch.model	= "bankir2";
	ch.sex = "man";
	ch.name 	= "Колм";
	ch.lastname = "Чамберс";
	ch.City = "FortOrange";
	ch.FaceId = 1;
	ch.Merchant.type = "jeweller"; 
	ch.location	= "FortOrange_Bank";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 200000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "FortOrange_Priest";
	ch.name		= "Джеймс"
	ch.lastname = "Блейкер";
	ch.model	= "pop_1";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_2";
	ch.nation = PIRATE;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "FortOrange_PortMan";
	ch.model	= "portman_2";
	ch.sex = "man";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = PIRATE;
	ch.greeting = "portman_5";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// ГОРОДСКИЕ ПЕРСОНАЖИ	///////////////////////////////////////////////////////////////////////////////

                  makeref(ch,Characters[n]);		//Гэри Хомс
	ch.id		= "HaryHooms";
	ch.name 	= "Гэри";
	ch.lastname = "Хомс";
	ch.rank = 30;
	ch.model	= "Homs";
	ch.sex = "man";
	ch.model.animation = "man";
	ch.City = "FortOrange";
	ch.location	= "House_HaryHooms";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Gothic_Quest\GothicLine\Smithy_HaryHooms.c";
	ch.greeting = "First time";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
     LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetImmortal(ch, true);
	ch.watchBoxes = true;
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_1";
	ch.model    = "Womens_1";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto19";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_2";
	ch.model    = "Womens_2";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_3";
	ch.model    = "Womens_3";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_4";
	ch.model    = "Womens_4";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_5";
	ch.model    = "Womens_5";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_6";
	ch.model    = "Womens_6";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "FortOrangegirl_7";
	ch.model    = "Womens_7";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "FortOrange";
	ch.location	= "FortOrange_town";
	ch.location.group = "reload";
	ch.location.locator = "reload15";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ Форт Оранж
	///////////////////////////////////////////////////////////////////////////////
	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "PortAntonio_mayor";
	ch.model	= "Huber_Hol_Fort";
	ch.sex = "man";
	ch.model.animation = "man_B"; 
	ch.name 	= "Баудевейн";
    ch.lastname = "Хендрикс";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_2";
	ch.nation = HOLLAND;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol9");
	EquipCharacterbyItem(ch, "pistol9");
	GiveItem2Character(ch, "blade_13"); 
	ch.equip.blade = "blade_13"; 
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_SetCharacterUseBullet(ch, "bullet");
    TakeNItems(ch, "bullet", 50);
	AddItems(ch, "gunpowder", 50);
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 90, 90);
SetCharacterPerk(ch, "Energaiser"); 
SetCharacterPerk(ch, "BasicDefense"); 
SetCharacterPerk(ch, "AdvancedDefense"); 
SetCharacterPerk(ch, "CriticalHit");
SetCharacterPerk(ch, "Tireless");
SetCharacterPerk(ch, "Sliding");
SetCharacterPerk(ch, "Gunman");
SetCharacterPerk(ch, "GunProfessional"); 
SetCharacterPerk(ch, "Sniper"); 
SetCharacterPerk(ch, "HPPlus"); 
SetCharacterPerk(ch, "EnergyPlus");
SetCharacterPerk(ch, "SwordplayProfessional");
SetCharacterPerk(ch, "ProfessionalDefense");
SetCharacterPerk(ch, "HardHitter");
SetCharacterPerk(ch, "BladeDancer");
SetCharacterPerk(ch, "Grus"); 
SetCharacterPerk(ch, "AdvancedDefense"); 
SetCharacterPerk(ch, "CriticalHit");
SetCharacterPerk(ch, "IronWill");
SetCharacterPerk(ch, "ShipEscape");
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "PortAntonio_Priest";
	ch.model	= "priest_3";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_1";
	ch.nation = HOLLAND;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "PortAntonio_waitress";
	ch.model	= "women_12";
	ch.sex = "woman";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = HOLLAND;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "PortAntonio_tavernkeeper";
	ch.model	= "barmen_3";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = HOLLAND;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "PortAntonio_trader";
	ch.model	= "trader_1";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = HOLLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "PortAntonio_shipyarder";
	ch.model	= "shipowner_6";
	ch.greeting = "shipyarder_2";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = HOLLAND;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor_02");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "topor_02"); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "PortAntonio_usurer";
	ch.model	= "banker_2";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "PortAntonio_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = HOLLAND;
	ch.greeting = "usurer_4";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 5000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "PortAntonio_PortMan";
	ch.model	= "citiz_4";
	ch.sex = "man";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = HOLLAND;
	ch.greeting = "portman_2";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "PortAntonio_Hostess";
	ch.name		= "Кэрис"
	ch.lastname = "";
	ch.model	= "women_3";
	ch.model.animation = "towngirl";
	ch.sex = "woman";
	ch.City = "PortAntonio";
	ch.location	= "PortAntonio_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_1";
	ch.nation = HOLLAND;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	n = n + 1;
	return n;
}