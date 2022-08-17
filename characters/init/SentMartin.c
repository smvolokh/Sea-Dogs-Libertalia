
int CreateSentMartinCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
	
	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "Marigo_Mayor";
	ch.model	= "huber_27";
	ch.name 	= "Мартин";
    ch.lastname = "Томас";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_townhall";
	ch.greeting = "mayor_1";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.nation = HOLLAND;
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
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "Marigo_Priest";
	ch.model	= "priest_4";
	ch.model.animation = "man"; 
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_church";
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
	ch.id		= "Marigo_waitress";
	ch.model	= "women_13";
	ch.sex = "woman";
	ch.City = "Marigo";
	ch.location	= "Marigo_tavern";
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
	ch.id		= "Marigo_tavernkeeper";
	ch.model	= "barmen_12";
	ch.greeting = "barmen_1";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_Tavern";
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
	ch.id		= "Marigo_trader";
	ch.model	= "trader_12";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_Store";
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
	ch.id		= "Marigo_shipyarder";
	ch.model	= "shipowner_12";
	ch.greeting = "shipyarder_3";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_Shipyard";
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
	ch.id		= "Marigo_usurer";
	ch.model	= "banker_12";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "Marigo_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = HOLLAND;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 7000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "Marigo_PortMan";
	ch.model	= "citiz_8";
	ch.sex = "man";
	ch.City = "Marigo";
	ch.location	= "Marigo_PortOffice";
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
	ch.id		= "Marigo_Hostess";
	ch.name		= "Йоханна"
	ch.lastname = "";
	ch.model	= "maman_1";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "Marigo";
	ch.location	= "Marigo_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_1";
	ch.nation = HOLLAND;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	n = n + 1;

    makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "Marigo_Smuggler";
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

///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Барон
	ch.id		= "Orwel";
	ch.model	= "Orwel";
	ch.name 	= "Жильбера";
	ch.lastname = "Гронье";
	ch.sex = "man";
	ch.City = "SantLous";
	ch.location	= "Settlement_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Mayor\Orwel.c";
	ch.nation = PIRATE;
	ch.greeting = "pirat_common";
	ch.quest.type = "hovernor";
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
	ch.id		= "Fishing_Settlement_Town_waitress";
	ch.model	= "Women_19";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "none";
	ch.location	= "Fishing_Settlement_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "tavern\none_Waitress.c";
	ch.greeting = "Gr_officiant";
	ch.nation = HOLLAND;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "Fishing_Settlement_Town_tavernkeeper";
	ch.model	= "barmen_15";
	ch.name 	= "Снаф";
	ch.lastname = "";
	ch.greeting = "Gr_Snaf";
	ch.sex = "man";
	ch.City = "none";
	ch.location	= "Fishing_Settlement_tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "tavern\none_Tavern.c";
	ch.TavernMan = true;
	ch.nation = HOLLAND;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	
	return n;
}
