
int CreatePuertoRicoCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id = "SanJuan_Mayor";
	ch.model	= "huber_17";
	ch.sex = "man";
	ch.name 	= "Диего";
    ch.lastname = "де Агуильера-и-Гамбоа";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_1";
	ch.nation = SPAIN;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id = "SanJuan_Priest";
	ch.model	= "priest_4";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_2";
	ch.nation = SPAIN;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id = "SanJuan_waitress";
	ch.model	= "women_15";
	ch.sex = "woman";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = SPAIN;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id = "SanJuan_tavernkeeper";
	ch.model	= "barmen_4";
	ch.greeting = "barmen_1";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = SPAIN;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);			//Торговец
	ch.id = "SanJuan_trader";
	ch.model	= "trader_4";
	ch.greeting = "store_3";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = SPAIN;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id = "SanJuan_shipyarder";
	ch.model	= "shipowner_4";
	ch.greeting = "shipyarder_2";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = SPAIN;
	ch.quest.shiping = "0";
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor_02");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "topor_02"); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "SanJuan_usurer";
	ch.model	= "banker_4";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "SanJuan_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = SPAIN;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 9000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "SanJuan_PortMan";
	ch.model	= "citiz_3";
	ch.sex = "man";
	ch.City = "SanJuan";
	ch.location	= "SanJuan_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = SPAIN;
	ch.greeting = "portman_3";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

    makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "SanJuan_Smuggler";
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


    //============== VillaAlegria ===============

	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id = "VillaAlegria_Mayor";
	ch.model	= "Gaskon";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.greeting = "mayor_4";
	ch.nation = SPAIN;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	SetRandSPECIAL(ch);
                SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Священик
	ch.id = "VillaAlegria_Priest";
	ch.model	= "priest_4";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_church";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "Gr_Church";
	ch.nation = SPAIN;
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Монашка
	ch.id		= "VillaAlegria_Priest";
	ch.model	= "Monah_1";
	ch.model.animation = "woman";
	ch.sex = "woman";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Gothic_Quest\Common_church_monahka.c";
	ch.greeting = "";
	ch.nation = SPAIN;
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id = "VillaAlegria_waitress";
	ch.model	= "Women_19";
	ch.sex = "woman";
	ch.model.animation	= "woman";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_officiant";
	ch.nation = SPAIN;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id = "VillaAlegria_waitress";
	ch.model	= "Women_13";
	ch.sex = "woman";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "stay2";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Gr_waitress";
	ch.nation = SPAIN;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id = "VillaAlegria_tavernkeeper";
	ch.model	= "barmen_2";
	ch.greeting = "barmen_1";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = SPAIN;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id = "VillaAlegria_trader";
	ch.model	= "Storeman_6";
	ch.model.animation	= "man_B";
	ch.greeting = "tra_common_4";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.greeting = "store_1";
	ch.nation = SPAIN;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id = "VillaAlegria_shipyarder";
	ch.model	= "shipowner_12_1";
	ch.greeting = "shipyarder_1";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = SPAIN;
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
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "Spain_bankir";
	ch.name = "Эдуардо";
	ch.lastname = "Давиньо";
	ch.model	= "banker_9_1";
	ch.sex = "man";
	ch.FaceId = 1;
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = SPAIN;
	ch.greeting = "Gr_bankeer";
	ch.Merchant.type = "jeweller"; 
	ch.UsurerDeposit = 10000; // *1000 денег
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);			//Историк
	ch.id		= "Historic";
	ch.name = "Хосе";
	ch.lastname = "де Акоста";
	ch.model	= "Historic";
	ch.sex = "man";
	ch.model.animation = "man2"; 
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_HouseF5";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Historic.c";
	ch.nation = SPAIN;
	ch.greeting = "Historic";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	SetSelfSkill(ch, 90, 95, 90, 80, 90);
	SetShipSkill(ch, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(ch, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(ch, "Energaiser"); 
	SetCharacterPerk(ch, "BasicDefense"); 
	SetCharacterPerk(ch, "AdvancedDefense"); 
	SetCharacterPerk(ch, "ProfessionalDefense"); 
	SetCharacterPerk(ch, "Tireless"); 
	SetCharacterPerk(ch, "CriticalHit"); 
	SetCharacterPerk(ch, "Sliding"); 
	SetCharacterPerk(ch, "SwordplayProfessional"); 
	SetCharacterPerk(ch, "BladeDancer"); 
	SetCharacterPerk(ch, "Gunman"); 
	SetCharacterPerk(ch, "GunProfessional"); 
	SetCharacterPerk(ch, "IronWill"); 
	SetCharacterPerk(ch, "Doctor1");
	SetCharacterPerk(ch, "Doctor2");
	SetCharacterPerk(ch, "Doctor3");
	GiveItem2Character(ch, "blade_17");
	ch.equip.blade = "blade_17";
	LAi_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetCitizenType(ch);
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;



	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "VillaAlegria_PortMan";
	ch.model	= "citiz_59";
	ch.sex = "man";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = SPAIN;
	ch.greeting = "Gr_poorman";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "VillaAlegria_Hostess";
	ch.name		= "Анна"
	ch.lastname = "";
	ch.model	= "Maman_7";
	ch.model.animation	= "towngirl3";
	ch.sex = "woman";
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "hostess";
	ch.nation = SPAIN;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	n = n + 1;

                makeref(ch,Characters[n]);
	ch.name 	= "Контрабандист";
	ch.lastname = "";
	ch.id		= "VillaAlegria_Smuggler";
	ch.model    = "pirate_1";
	ch.sex      = "man";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	ch.equip.blade = BLADE_SABER;
	// посадим в генераторе
	ch.Dialog.Filename = "Gothic_Quest\Smuggler_VillaAlegria_Agent_dialog.c";
	LAi_SetSitType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "smuggler";
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////
	// Инквизиция	///////////////////////////////////////////////////////////////////////////////
	makeref(ch,Characters[n]);			//
	ch.id		= "Incquisitor";
	ch.model	= "priest_spa";
	ch.model.animation	= "man2";
	ch.sex = "man";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Incquistors.c";
	ch.greeting = "Gr_Incquisitor";
	ch.nation = SPAIN;
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//
	ch.id		= "Incquisitor";
	ch.model	= "priest_sp1";
	ch.model.animation	= "man2";
	ch.sex = "man";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "Incquistors.c";
	ch.greeting = "Gr_Incquisitor";
	ch.nation = SPAIN;
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//
	ch.id		= "Incquisitor";
	ch.model	= "priest_sp2";
	ch.model.animation	= "man2";
	ch.sex = "man";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Incquistors.c";
	ch.greeting = "Gr_Incquisitor";
	ch.nation = SPAIN;
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//
	ch.id		= "Incquisitor";
	ch.model	= "priest_sp3";
	ch.model.animation	= "man2";
	ch.sex = "man";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Incquistors.c";
	ch.greeting = "Gr_Incquisitor";
	ch.nation = SPAIN;
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	n = n + 1;

     makeref(ch,Characters[n]);
	ch.id		= "IncqGuard";
	ch.model    = "Paladin_5";
	ch.sex      = "man";
	ch.model.animation = "man2"; 
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "Common_Soldier.c";
	ch.dialog.currentnode = "first time";
	ch.greeting = "protector";
	ch.nation = SPAIN;
	SetSelfSkill(ch, 100, 100, 100, 100, 100);
	SetCharacterPerk(ch, "Energaiser"); 
	SetCharacterPerk(ch, "BasicDefense"); 
	SetCharacterPerk(ch, "AdvancedDefense"); 
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Tireless");
	SetCharacterPerk(ch, "Sliding");
	SetCharacterPerk(ch, "Gunman");
	SetCharacterPerk(ch, "GunProfessional"); 
	SetCharacterPerk(ch, "HPPlus"); 
	SetCharacterPerk(ch, "EnergyPlus");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "HardHitter");
	SetCharacterPerk(ch, "BladeDancer");
	SetCharacterPerk(ch, "Grus"); 
	SetCharacterPerk(ch, "AdvancedDefense"); 
	SetCharacterPerk(ch, "CriticalHit");
	GiveItem2Character(ch, "pistol11");
	ch.equip.gun = "pistol11";
	ch.SuperShooter  = true;
	LAi_SetImmortal(ch, true);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	GiveItem2Character(ch, "newblade15"); 
	ch.equip.blade = "newblade15";
	LAi_SetGuardianType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	n = n + 1;

     makeref(ch,Characters[n]);
	ch.id		= "IncqGuard_1";
	ch.model    = "Paladin_2";
	ch.sex      = "man";
	ch.model.animation = "man2"; 
	ch.City = "VillaAlegria";
	ch.location	= "VillaAlegria_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto19";
	ch.Dialog.Filename = "Common_Soldier.c";
	ch.dialog.currentnode = "first time";
	ch.greeting = "protector";
	ch.nation = SPAIN;
	SetSelfSkill(ch, 100, 100, 100, 100, 100);
	SetCharacterPerk(ch, "Energaiser"); 
	SetCharacterPerk(ch, "BasicDefense"); 
	SetCharacterPerk(ch, "AdvancedDefense"); 
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Tireless");
	SetCharacterPerk(ch, "Sliding");
	SetCharacterPerk(ch, "Gunman");
	SetCharacterPerk(ch, "GunProfessional"); 
	SetCharacterPerk(ch, "HPPlus"); 
	SetCharacterPerk(ch, "EnergyPlus");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "ProfessionalDefense");
	SetCharacterPerk(ch, "HardHitter");
	SetCharacterPerk(ch, "BladeDancer");
	SetCharacterPerk(ch, "Grus"); 
	SetCharacterPerk(ch, "AdvancedDefense"); 
	SetCharacterPerk(ch, "CriticalHit");
	GiveItem2Character(ch, "pistol11");
	ch.equip.gun = "pistol11";
	ch.SuperShooter  = true;
	LAi_SetImmortal(ch, true);
	ch.MultiFighter = 1.5; // мультифайтер
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	GiveItem2Character(ch, "newblade15"); 
	ch.equip.blade = "newblade15";
	LAi_SetGuardianType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	n = n + 1;

	return n;
}
