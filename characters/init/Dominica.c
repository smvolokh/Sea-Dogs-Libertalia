
int CreateDominicaCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "Roseau_Mayor";
	ch.model	= "Admiral";
	ch.name 	= "куратор Аршамбо";
	ch.lastname = "де Ансильон";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_4";
	ch.nation = FRANCE;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol5");	//GUN_COMMON
	EquipCharacterByItem(ch, "pistol5");
	GiveItem2Character(ch, "blade_17");	//BLADE_LONG
	EquipCharacterByItem(ch, "blade_17");
	SetRandSPECIAL(ch);
     SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);	//Торус Шардонэ
	ch.id		= "Torus";	
	ch.name 	= "Торус";
	ch.lastname = "Шардонэ";
	ch.model	= "Torus";
                     ch.rank     = 35;
	ch.sex = "man";
                    ch.model.animation = "man"; 
	ch.City = "Roseau";
	ch.location	= "Roseau_Roomtownhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\Torus.c";
	ch.greeting = "Gr_Torus";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	SetFantomParamFromRank(ch, ch.Rank, true);
	SetRandSPECIAL(ch);
                SetSelfSkill(ch, 90, 90, 90, 60, 70);	
	GiveItem2Character(ch, "pistol11");	//GUN_COMMON
	EquipCharacterByItem(ch, "pistol11");
	GiveItem2Character(ch, "blade42");	//BLADE_LONG
	EquipCharacterByItem(ch, "blade42");
	GiveItem2Character(ch, "spyglass3");
	EquipCharacterByItem(ch, "spyglass3");
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "Roseau_waitress";
	ch.model	= "Women_21";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_tavern";
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
	ch.id		= "Roseau_waitress";
	ch.model	= "Women_20";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_officiant";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "Roseau_tavernkeeper";
	ch.name 	= "Кардиф";
	ch.lastname = "";
	ch.model	= "rivados_3";
	ch.greeting = "Gr_Kardif";
	ch.sex = "man";
	ch.model.animation	= "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_Tavern";
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

	makeref(ch,Characters[n]);			//Заведующий  складом в таверне
	ch.id		= "Roseau_SkladMan";
	ch.model	= "citiz_"+(rand(9)+1);
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location = "Roseau_sklad";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "HouseEnc_dialog.c";
	ch.dialog.currentnode = "SkladMan";
	ch.greeting = "Gr_Sklad";
	ch.nation = PIRATE;
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.Storage 	  = true;
	n = n + 1; 

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "Roseau_trader";
	ch.model	= "trader_6";
	ch.greeting = "Gr_FISK";
	ch.name 	= "Фиск";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_Store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;


	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "Roseau_bankir";
	ch.model	= "banker_8_1";
	ch.name 	= "Маттео";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_bank";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "Gr_Matteo";
	ch.quest.shiping = "0";
	ch.money = "10000000";
	ch.Merchant.type = "jeweller"; 
	ch.UsurerDeposit = 10000; // *1000 денег
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "Roseau_PortMan";
	ch.model	= "citiz_53";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = PIRATE;
	ch.greeting = "Gr_poorman";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id		= "Roseau_Priest";
	ch.model	= "priest_3";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.nation	= PIRATE;
	ch.location	= "Roseau_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "Gr_Church";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "Roseau_Hostess";
	ch.name		= "Сьюзан"
	ch.lastname = "";
	ch.model	= "lady02";
	ch.sex = "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "hostess";
	ch.nation = PIRATE;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;


	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "Roseau_shipyarder";
	ch.model	= "shipowner_12_1";
	ch.name 	= "Скип";
	ch.lastname = "";
	ch.sex = "man";
	ch.greeting = "Gr_SKIP";
	ch.City = "Roseau";
	ch.location	= "Roseau_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = PIRATE;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor1");
                SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 2.0; // мультифайтер
	ch.MultiShooter = 2.0;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Доктор алхимик
	ch.id		= "Constantino";
	ch.model	= "Constantino";
	ch.name 	= "Константино";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Constantino_House";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Gothic_Quest\Gothic_npc\Constantino.c";
	ch.nation = PIRATE;
	ch.greeting = "Gr_Constantino";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Смотритель маяка
	ch.id		= "Roseau_Lightman";
	ch.name 	= "Джек";
	ch.lastname = "";
	ch.model	= "keeper_8";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location = "Roseau_port";
	ch.location.group = "quest";
	ch.location.locator = "quest1";
	ch.Dialog.Filename = "Gothic_Quest\Gothic_npc\Jack.c";
	ch.dialog.currentnode = "First time";
	ch.greeting = "";
	ch.Merchant = true;
	ch.Merchant.type = "lightman";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	ch.nation = PIRATE;
	LAi_SetOwnerType(ch);
	LAi_SetLoginTime(ch, 10.0, 18.99);
                   LAi_ActorTurnToLocator(ch, "box", "box1");
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	///////////////////////////////////////////////////////////////////////////////
	// ГОРОДСКИЕ ПЕРСОНАЖИ	///////////////////////////////////////////////////////////////////////////////


                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_1";
	ch.model    = "gipsy_1";
	ch.sex      = "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.Merchant.type = "indian"; 
	ch.Dialog.Filename = "Common_ItemTrader.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "gipsy";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetMerchantType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_2";
	ch.model    = "gipsy_2";
	ch.sex      = "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "merchant";
	ch.location.locator = "mrtActive2";
	ch.Merchant.type = "indian"; 
	ch.Dialog.Filename = "Common_ItemTrader.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "gipsy";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetMerchantType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_3";
	ch.model    = "Womens_1";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
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
	ch.id		= "Roseaugirl_4";
	ch.model    = "Womens_2";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
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
	ch.id		= "Roseaugirl_5";
	ch.model    = "Womens_3";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
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
	ch.id		= "Roseaugirl_6";
	ch.model    = "Womens_4";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_7";
	ch.model    = "Womens_5";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "goto";
	ch.location.locator = "goto41";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_8";
	ch.model    = "Womens_6";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "goto";
	ch.location.locator = "goto24";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_9";
	ch.model    = "Womens_7";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_port";
	ch.location.group = "goto";
	ch.location.locator = "goto18";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_10";
	ch.model    = "Womens_8";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_port";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.id		= "Roseaugirl_11";
	ch.model    = "Womens_1";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "Roseau";
	ch.location	= "Roseau_port";
	ch.location.group = "goto";
	ch.location.locator = "goto27";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	///////////////////////////////////////////////////////////////////////////////
	// ПЕРСОНАЖИ В ОФИСЕ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);		
	ch.id		= "W_headclerk";
	ch.model	= "Pirate_9";
	ch.name 	= "Раймондэ";
     ch.lastname = "Оберто";
	ch.sex = "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_Roomtownhall";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Gothic_Quest\Office_Rosea.c";
	ch.dialog.currentnode = "W_headclerk";
	ch.nation = PIRATE;
	ch.greeting = "official";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 11.0, 15.99);
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	ch.Merchant.type = "company";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	n = n + 1;

     makeref(ch,Characters[n]);
	ch.id		= "W_officer";
	ch.model    = "Women_6";
	ch.sex      = "woman";
	ch.model.animation = "woman";
	ch.City = "Roseau";
	ch.location	= "Roseau_bank";
	ch.location.group = "goto"; 
	ch.location.locator = "goto10";
	ch.Dialog.Filename = "Gothic_Quest\Office_Rosea.c";
	ch.dialog.currentnode = "W_officer";
	ch.greeting = "noble_female";
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");	
	LAi_SetImmortal(ch, true);	
	LAi_SetOwnerType(ch);
	ch.talker = 10;
	n = n + 1;

	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Мо вышибала
	ch.id		= "Moe";
	ch.name 	= "Мо";
                        ch.lastname = "";
	ch.model	= "citiz_27";
	ch.sex = "man";
	ch.model.animation	= "man";
	ch.City = "Roseau";
	ch.location	= "Roseau_town";
	ch.location.group = "quest";
	ch.location.locator = "quest1";
	ch.Dialog.Filename = "Gothic_Quest\Gothic_npc\Moe.c";
	ch.dialog.currentnode = "Moe";
	ch.greeting = "";
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	SetSelfSkill(ch, 50, 80, 80, 70, 70);
	SetCharacterPerk(ch, "BasicDefense");
	LAi_SetHP(ch, 800.0, 800.0);
	ch.nation = PIRATE;
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetImmortal(ch, true);
	LAi_SetStayType(ch);
	LAi_RemoveLoginTime(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.talker = 20;
	n = n + 1;


	return n;
}
