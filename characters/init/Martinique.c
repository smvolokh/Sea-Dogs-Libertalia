
int CreateMartiniqueCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

    // FortFrance -->
	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "FortFrance_Mayor";
	ch.model	= "huber_4";
	ch.sex = "man";
	ch.name 	= "Жак Дил";
    ch.lastname = "ду Парке";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_townhall";
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
	ch.id		= "FortFrance_Priest";
	ch.model	= "priest_4";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_1";
	ch.nation = FRANCE;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "FortFrance_waitress";
	ch.model	= "women_15";
	ch.sex = "woman";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_tavern";
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
	ch.id		= "FortFrance_tavernkeeper";
	ch.model	= "barmen_8";
	ch.greeting = "barmen_3";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_Tavern";
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

	makeref(ch,Characters[n]);			//Миксер
	ch.id		= "Myxir";
	ch.model	= "trader_8";
	ch.sex = "man";
	ch.name 	= "Миксер";
    	ch.lastname = "";
	ch.City = "FortFrance";
	ch.location	= "LibraryHouse";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Myxir.c";
	ch.money = 45000;
	ch.rank = 87;
	ch.nation = FRANCE;
	LAi_SetHP(ch, 250, 250);
	SetSelfSkill(ch, 90, 95, 90, 80, 90);
	SetShipSkill(ch, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(ch, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(ch, "BasicDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Tireless");
	SetCharacterPerk(ch, "Gunman");
	SetCharacterPerk(ch, "Doctor1");
	SetCharacterPerk(ch, "Doctor2");
	SetCharacterPerk(ch, "Doctor3");
	GiveItem2Character(ch, "knife_01");
	ch.equip.blade = "knife_01";
	LAi_SetCitizenType(ch);
	ch.standUp = true; //вставать и нападать на врага
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "FortFrance_trader";
	ch.model	= "trader_8";
	ch.greeting = "store_3";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_Store";
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
	ch.id		= "FortFrance_shipyarder";
	ch.model	= "shipowner_8";
	ch.greeting = "shipyarder_3";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_Shipyard";
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
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "FortFrance_usurer";
	ch.model	= "banker_8_2";
	ch.sex = "man";
	ch.name 	= "Жан Пьер";
	ch.lastname = "Моруа";
	ch.City = "FortFrance";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "FortFrance_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = FRANCE;
	ch.greeting = "usurer_4";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 7000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "FortFrance_PortMan";
	ch.model	= "citiz_2";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = FRANCE;
	ch.greeting = "portman_2";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "FortFrance_Hostess";
	ch.name		= "Аврора"
	ch.lastname = "";
	ch.model	= "maman_4";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_3";
	ch.nation = FRANCE;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	n = n + 1;

    makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "FortFrance_Smuggler";
	ch.model    = "citiz_30";
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

	makeref(ch,Characters[n]);			//Смотритель кладбища
	ch.id		= "FortFrance_Cemeteryman";
	ch.model	= "keeper_2";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "FortFrance";
	ch.location = "FortFrance_KeepersHouse";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Common_cemeteryman.c";
	ch.greeting = "lighthouseman_3";
	ch.Merchant = true;
	ch.Merchant.type = "cemeteryman";
	ch.money = TRADER_MIN_MONEY;
	ch.nation = FRANCE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Монашка
	ch.id		= "FortFrance_Priest";
	ch.model	= "Monah_1";
	ch.model.animation = "woman";
	ch.name 	= "Тереза";
	ch.lastname = "";
	ch.sex = "woman";
	ch.City = "FortFrance";
	ch.location	= "FortFrance_church IM";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "Gothic_Quest\Common_church_monahka.c";
	ch.greeting = "";
	ch.nation = FRANCE;
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;
	
///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
    //============== LeFransua ===============

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "LeFransua_Mayor";
	ch.model	= "huber_fra";
	ch.name 	= "Бартоломью Роджерс";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\LeFransua_Mayor.c";
	ch.dialog.currentnode   = "First time";
	ch.nation = PIRATE;
	ch.greeting = "pirat_common";
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol11");	//GUN_COMMON
	EquipCharacterByItem(ch, "pistol11");
	GiveItem2Character(ch, "blade44");	//BLADE_LONG
	EquipCharacterByItem(ch, "blade44");
	GiveItem2Character(ch, "spyglass3");
	EquipCharacterByItem(ch, "spyglass3");
	SetRandSPECIAL(ch);
        SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Барон
	ch.id		= "Barbazon";
	ch.model	= "Barbazon";
	ch.name 	= "Жак";
	ch.lastname = "Барбазон";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_TownhallRoom";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Mayor\Barbazon.c";
	ch.nation = PIRATE;
	ch.greeting = "barbazon_1";
	ch.quest.type = "hovernor";
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG); 
	SetRandSPECIAL(ch);
                       SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "LeFransua_waitress";
	ch.model	= "Women_23";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "FortFrance";
	ch.location	= "LeFransua_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "stay1";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_officiant";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;
	

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "LeFransua_waitress";
	ch.model	= "Women_22";
	ch.model.animation	= "woman";
	ch.sex = "woman";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_Tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_officiant";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "LeFransua_tavernkeeper";
	ch.model	= "Q_Barmen";
	ch.name 	= "Снейкман";
	ch.lastname = "Янг";
	ch.greeting = "Gr_Barmen";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_Tavern";
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
	ch.id		= "LeFransua_trader";
	ch.model	= "trader_13_1";
	ch.greeting = "store_3";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_Store";
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

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "LeFransua_usurer";
	ch.model	= "Diplomat";
	ch.sex = "man";
	ch.FaceId = 1;
	ch.name 	= "Рише";
	ch.lastname = "Поблано";
	ch.City = "LeFransua";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "LeFransua_bank";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "usurer_1";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 10000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "LeFransua_Hostess";
	ch.name		= "Макс"
	ch.lastname = "";
	ch.model	= "Maks";
	ch.model.animation = "towngirl";
	ch.sex = "woman";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "hostess";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "LeFransua_Priest";
	ch.name		= "Ферегуэйро"
	ch.lastname = "";
	ch.model	= "Sekt";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.nation	= PIRATE;
	ch.location	= "LeFransua_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "Gr_Church";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "LeFransua_PortMan";
	ch.model	= "citiz_57";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = PIRATE;
	ch.greeting = "portman_1";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "LeFransua_shipyarder";
	ch.model	= "shipowner_8_1";
	ch.greeting = "shipyarder_2";
	ch.sex = "man";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = PIRATE;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor1");
	SetRandSPECIAL(ch);
                SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// ГОРОДСКИЕ ПЕРСОНАЖИ	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);		// картёжница
	ch.id		= "LeFransua_waitress";
	ch.model	= "Women_21";
	ch.model.animation	= "woman";
	ch.sex = "woman";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit_base4";
	ch.Dialog.Filename = "Gothic_Quest\npc\Woman_Habitue_dialog.c";
	ch.greeting = "Gr_Woman_Habitue";
	ch.nation = PIRATE;
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_1";
	ch.model    = "Womens_10";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_town";
	ch.location.group = "goto";
	ch.location.locator = "goto30";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_2";
	ch.model    = "Womens_11";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_town";
	ch.location.group = "goto";
	ch.location.locator = "goto27";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_3";
	ch.model    = "Womens_12";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_town";
	ch.location.group = "goto";
	ch.location.locator = "goto21";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_4";
	ch.model    = "Womens_13";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_town";
	ch.location.group = "goto";
	ch.location.locator = "goto32";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_5";
	ch.model    = "Womens_18";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_town";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_6";
	ch.model    = "Womens_15";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "LeFransuagirl_7";
	ch.model    = "Womens_17";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "LeFransua";
	ch.location	= "LeFransua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);
	ch.name 	= "'Мокрый' Гаглани";
	ch.lastname = "";
	ch.id		= "Gaglany";
	ch.nation	= PIRATE;
	ch.model	= "pirate_5";
	ch.sex = "man";
	ch.location	= "Shore89";
	ch.location.group = "goto";
	ch.location.locator = "goto21";
	GiveItem2Character(ch, "topor_015");
                   ch.equip.blade = "topor_015";
	ch.Dialog.Filename = "Gothic_Quest\npc\JanTerenb.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "pirate_man";
                   LAi_SetLoginTime(ch, 7.0, 21.0);
	LAi_SetMiningType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	return n;
}

