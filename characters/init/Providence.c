
int CreateProvidenceCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
	makeref(ch,Characters[n]);			//губернатор
	ch.id		= "SanAndres_Mayor";
	ch.model	= "Apostates_10";
	ch.model.animation = "man2";
	ch.sex = "man";
	ch.name 	= "Алехандро";
                     ch.lastname = "де ла Круз";
	ch.City = "SanAndres";
	ch.greeting = "mayor_4";
	ch.location = "SanAndres_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.nation = PIRATE;
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
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "SanAndres_Priest";
	ch.model	= "priest_2";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_church";
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

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "SanAndres_waitress";
	ch.model	= "women_16";
	ch.sex = "woman";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_tavern";
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
	ch.id		= "SanAndres_tavernkeeper";
	ch.model	= "barmen_5";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.greeting = "barmen_4";
	ch.nation = PIRATE;
	ch.TavernMan = true;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "SanAndres_trader";
	ch.model	= "Apostates_11";
	ch.model.animation = "man2";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	// настройка магазина -->
	ch.StoreNum   = SanAndres_STORE;
	ch.from_sea   = "SanAndres_town";
	// настройка магазина <--
	n = n + 1;


	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "SanAndres_trader";
	ch.model	= "trader_5";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_Store_port";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	// настройка магазина -->
	//ch.StoreNum   = SanAndres_STORE;
	//ch.from_sea   = "SanAndres_town";
	// настройка магазина <--
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "SanAndres_shipyarder";
	ch.model	= "Apostates_16";
	ch.model.animation = "man2";
	ch.greeting = "shipyarder_1";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_Shipyard";
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "SanAndres_usurer";
	ch.model	= "Apostates_6";
	ch.model.animation = "man2";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "SanAndres_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "usurer_1";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 10000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "SanAndres_PortMan";
	ch.model	= "Apostates_8";
	ch.model.animation = "man2";
	ch.sex = "man";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_PortOffice";
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
	ch.id		= "SanAndres_Hostess";
	ch.name		= "Аришка"
	ch.lastname = "";
	ch.model	= "maman_2";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "SanAndres";
	ch.location	= "SanAndres_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_1";
	ch.nation = PIRATE;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;
		
	return n;
}
