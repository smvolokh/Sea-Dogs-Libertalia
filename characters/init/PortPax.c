int CreatePortPaxCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "PortPax_Mayor";
	ch.model	= "huber_8";
	ch.sex = "man";
	ch.name 	= "Жереми Дешамп";
    ch.lastname = "дю Мюссак";
	ch.City = "PortPax";
	ch.location	= "PortPax_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_3";
	ch.nation = FRANCE;
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
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "PortPax_Priest";
	ch.model	= "priest_3";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location	= "PortPax_church";
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
	ch.id		= "PortPax_waitress";
	ch.model	= "women_15";
	ch.sex = "woman";
	ch.City = "PortPax";
	ch.location	= "PortPax_tavern";
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
	ch.id		= "PortPax_tavernkeeper";
	ch.model	= "barmen_7";
	ch.greeting = "barmen_3";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location	= "PortPax_Tavern";
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
	ch.id		= "PortPax_trader";
	ch.model	= "trader_7";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location	= "PortPax_Store";
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
	ch.id		= "PortPax_shipyarder";
	ch.model	= "shipowner_7";
	ch.greeting = "shipyarder_3";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location	= "PortPax_Shipyard";
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
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "PortPax_usurer";
	ch.model	= "banker_7";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "PortPax_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = FRANCE;
	ch.greeting = "usurer_4";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 8000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;
	
	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "PortPax_PortMan";
	ch.model	= "citiz_1";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location	= "PortPax_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = FRANCE;
	ch.greeting = "portman_1";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;
	
	makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "PortPax_Smuggler";
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
	ch.id		= "PortPax_Lightman";
	ch.model	= "keeper_4";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "PortPax";
	ch.location = "Mayak7_Lighthouseroom";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Common_lighthouse.c";
	ch.greeting = "lighthouseman_1";
	ch.Merchant = true;
	ch.Merchant.type = "lightman";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	ch.nation = FRANCE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
    //============== LeKe ===============

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "LeKe_Mayor";
	ch.model	= "Duge";
	ch.name 	= "Рене";
	ch.lastname = "Дюгэ-Труэн";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location	= "LeKe_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\LeKe_Mayor.c";
	ch.dialog.currentnode   = "SharpPearl";
	ch.nation = PIRATE;
	ch.greeting = "pirat_common";
	ch.quest.type = "hovernor";
	ch.model.animation = "Norman"; 
	GiveItem2Character(ch, "pistol5");	//GUN_COMMON
	EquipCharacterByItem(ch, "pistol5");
	GiveItem2Character(ch, "newblade17");	//BLADE_LONG
	EquipCharacterByItem(ch, "newblade17");
	GiveItem2Character(ch, "spyglass4");
	EquipCharacterByItem(ch, "spyglass4");
	SetRandSPECIAL(ch);
     SetSelfSkill(ch, 90, 90, 90, 90, 90);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]); //Агент
	ch.id		= "LK_headclerk";
	ch.model	= "Pirate_2";
	ch.name 	= "Брайан";
     ch.lastname = "О'Коннор";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location	= "LeKe_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Gothic_Quest\Office_Rosea.c";
	ch.dialog.currentnode = "W_headclerk";
	ch.nation = PIRATE;
	ch.greeting = "official";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	ch.Merchant.type = "company";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.name		= "Венсан";
	ch.lastname = "Оже";
	ch.id		= "LeKe_trader";
	ch.model	= "trad_17";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location	= "LeKe_Store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	// настройка магазина -->
	ch.StoreNum   = LeKe_STORE;
	ch.from_sea   = "LeKe_town";
	// настройка магазина <--
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "LeKe_shipyarder";
	ch.model	= "shipowner_15";
	ch.greeting = "shipyarder_1";
	ch.name = "Андрэ";
	ch.lastname = "Лабор";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location	= "LeKe_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
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
	ch.MultiFighter = 2.0; // мультифайтер
	ch.MultiShooter = 2.0;
	ch.SuperShooter  = true;
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "LeKe_PortMan";
	ch.model	= "citiz_56";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location	= "LeKe_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = PIRATE;
	ch.greeting = "portman_2";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "LeKe_Hostess";
	ch.name		= "Армо"
	ch.lastname = "Дюлин";
	ch.model	= "CitizenWom_1";
	ch.model.animation = "towngirl";
	ch.sex = "woman";
	ch.City = "LeKe";
	ch.location	= "LeKe_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "hostess";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "LeKe_tavernkeeper";
	ch.name 	= "Доминик";
	ch.lastname = "Торетто";
	ch.model	= "Dominik";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.model.animation	= "man2";
	ch.City = "LeKe";
	ch.location	= "LeKe_Tavern";
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

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "LeKe_waitress";
	ch.model	= "horse01";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "LeKe";
	ch.location	= "LeKe_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_waitress";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "LeKe_waitress";
	ch.model	= "horse08";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "LeKe";
	ch.location	= "LeKe_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_waitress";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "LeKe_usurer";
	ch.model	= "usurer_9";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.FaceId = 1;
	ch.Merchant.type = "jeweller"; 
	ch.location	= "LeKe_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 10000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "LeKe_Priest";
	ch.name		= "Мефисто";
	ch.lastname = "";
	ch.model	= "Sekt_1";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.nation	= PIRATE;
	ch.location	= "LeKe_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "Gr_Church";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);	//Заведующий  складом 	
	ch.id		= "LeKe_SkladMan";
	ch.model	= "pirate_6";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "LeKe";
	ch.location = "LeKe_packhouse_228";
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

	return n;
}
