
int CreateCuracaoCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "Villemstad_Mayor";
	ch.model	= "huber_25";
	ch.sex = "man";
	ch.name 	= "Матиас";
    ch.lastname = "Бек";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_3";
	ch.nation = HOLLAND;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol5");
	EquipCharacterbyItem(ch, "pistol5");
	LAi_SetCharacterUseBullet(ch, "bullet");
    TakeNItems(ch, "bullet", 50);
	AddItems(ch, "gunpowder", 50);
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "Villemstad_Priest";
	ch.model	= "priest_4";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_2";
	ch.nation = HOLLAND;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "Villemstad_waitress";
	ch.model	= "women_11";
	ch.sex = "woman";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_tavern";
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
	ch.id		= "Villemstad_tavernkeeper";
	ch.model	= "barmen_12";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_Tavern";
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
	ch.id		= "Villemstad_trader";
	ch.model	= "trader_12";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_Store";
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
	ch.id		= "Villemstad_shipyarder";
	ch.model	= "shipowner_12";
	ch.greeting = "shipyarder_1";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_Shipyard";
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
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "Villemstad_usurer";
	ch.model	= "banker_12";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "Villemstad_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = HOLLAND;
	ch.greeting = "usurer_3";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 11000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "Villemstad_PortMan";
	ch.model	= "citiz_9";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location	= "Villemstad_PortOffice";
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
	
	makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "Villemstad_Smuggler";
	ch.model    = "citiz_28";
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
	ch.id		= "Villemstad_SkladMan";
	ch.model	= "citiz_"+(rand(9)+1);
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location = "Villemstad_Packhouse";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "HouseEnc_dialog.c";
	ch.dialog.currentnode = "SkladMan";
	ch.greeting = "official";
	ch.nation = HOLLAND;
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.Storage 	  = true;
	n = n + 1; 
	
	makeref(ch,Characters[n]);			//Смотритель кладбища
	ch.id		= "Villemstad_Cemeteryman";
	ch.model	= "keeper_7";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "Villemstad";
	ch.location = "Villemstad_KeepersHouse";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Common_cemeteryman.c";
	ch.greeting = "lighthouseman_1";
	ch.Merchant = true;
	ch.Merchant.type = "cemeteryman";
	ch.money = TRADER_MIN_MONEY;
	ch.nation = HOLLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

   //=============== Порт Vestpunt ===============
   //=============== Логово Контрабандистов ===============

	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "Richard_Soukins";
	ch.sex = "man";
	ch.model = "head_pir";
	ch.name = "Ричард";
	ch.lastname = "Соукинс";
	ch.City = "Vestpunt";
	ch.location	= "Vestpunt_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\RichardSoukins.c";
	ch.greeting = "pirat_common";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
	GiveItem2Character(ch, "blade_28");
	ch.equip.blade = "blade_28";
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
	SetCharacterPerk(ch, "BasicDefense");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.99);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "Vestpunt_waitress";
	ch.model	= "Women_22";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "Vestpunt";
	ch.location	= "Vestpunt_tavern";
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

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "Vestpunt_waitress";
	ch.model	= "Women_23";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "Pirates";
	ch.location	= "Vestpunt_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "stay2";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_officiant";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "Vestpunt_tavernkeeper";
	ch.model	= "barmen_1";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.model.animation	= "man";
	ch.City = "Vestpunt";
	ch.location	= "Vestpunt_Tavern";
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
	ch.id		= "Vestpunt_trader";
	ch.model	= "trader_5";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "Vestpunt";
	ch.location	= "Vestpunt_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	
	return n;
}
