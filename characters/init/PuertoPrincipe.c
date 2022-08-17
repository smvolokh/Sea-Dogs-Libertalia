
int CreatePuertoPrincipeCharacters(int n)
{
	ref ch;
	
//////////////////////////////////////////////////////////////////////////////
// ОСНОВНЫЕ ПЕРСОНАЖИ
//////////////////////////////////////////////////////////////////////////////

	makeref(ch,Characters[n]);			//Губернатор
	ch.id		= "Marlow";
	ch.sex = "man";
	ch.model = "Marlow";
	ch.name = "Захария";
	ch.lastname = "Марлоу";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\Marlow.c";
	ch.greeting = "marlow";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_27");
	EquipCharacterbyItem(ch, "pistol5"); 
	EquipCharacterbyItem(ch, "blade_27");
	AddItems(ch, "cartridge", 50);
	LAi_SetCharacterUseBullet(ch, "cartridge");	
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
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
	ch.MultiFighter = 2.5; // мультифайтер
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]); //Агент
	ch.id		= "PP_headclerk";
	ch.model	= "Pirate_10";
	ch.name 	= "Круэл";
     ch.lastname = "Делито";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_townhall";
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

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "PuertoPrincipe_waitress";
	ch.model	= "women_9";
	ch.sex = "woman";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Waitress";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Банкир
	ch.id		= "PuertoPrincipe_usurer";
	ch.model	= "bankir1";
	ch.sex = "man";
	ch.name 	= "Ричард";
	ch.lastname = "Гатри";
	ch.City = "PuertoPrincipe";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "PuertoPrincipe_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = PIRATE;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 200000; // *1000 денег
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Начальник порта
	ch.id		= "PuertoPrincipe_PortMan";
	ch.model	= "portman_1";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_PortOffice";
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

	makeref(ch,Characters[n]);			//Хозяйка борделя
	ch.id		= "PuertoPrincipe_Hostess";
	ch.name 	= "Элеонор";
	ch.lastname = "";
	ch.model	= "girl_11";
	ch.model.animation = "towngirl";
	ch.sex = "woman";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_2";
	ch.nation = PIRATE;
	ch.questChurch = ""; //флаг для пожертвований
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "PuertoPrincipe_shipyarder";
	ch.model	= "verfist_1";
	ch.name 	= "Асигм";
    	ch.lastname = "Десигни";
	ch.greeting = "shipyarder_1";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_Shipyard";
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

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "PuertoPrincipe_tavernkeeper";
	ch.model	= "barmen_13";
	ch.greeting = "barmen_2";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_Tavern";
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
	ch.id		= "PuertoPrincipe_trader";
	ch.model	= "trader_13";
	ch.greeting = "store_1";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_Store";
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// девки город Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


     	makeref(ch,Characters[n]); 	//девка 1

	ch.id		= "PuertoPrincipegirl_1";
	ch.model    = "Womens_10";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;
     makeref(ch,Characters[n]); 	//девка 2
	ch.id		= "PuertoPrincipegirl_2";
	ch.model    = "Womens_11";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

      makeref(ch,Characters[n]); 	//девка 3
	ch.id		= "PuertoPrincipegirl_3";
	ch.model    = "Womens_12";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

      makeref(ch,Characters[n]);	//девка 4
	ch.id		= "PuertoPrincipegirl_4";
	ch.model    = "Womens_21";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto15";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

     makeref(ch,Characters[n]); 	//девка 5
	ch.id		= "PuertoPrincipegirl_5";
	ch.model    = "Womens_18";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

     makeref(ch,Characters[n]); 	//девка 6
	ch.id		= "PuertoPrincipegirl_6";
	ch.model    = "Womens_15";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

     makeref(ch,Characters[n]); 	//девка 7
	ch.id		= "PuertoPrincipegirl_7";
	ch.model    = "Womens_17";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_town";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// девки город Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// девки порт Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      makeref(ch,Characters[n]);
	ch.id		= "PuertoPrincipegirlport_3";
	ch.model    = "Womens_1";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;

     makeref(ch,Characters[n]);
	ch.id		= "PuertoPrincipegirlport_4";
	ch.model    = "Womens_2";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
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
	ch.id		= "PuertoPrincipegirlport_5";
	ch.model    = "Womens_3";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
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
	ch.id		= "PuertoPrincipegirlport_6";
	ch.model    = "Womens_4";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
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
	ch.id		= "PuertoPrincipegirlport_7";
	ch.model    = "Womens_20";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
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
	ch.id		= "PuertoPrincipegirlport_8";
	ch.model    = "Womens_6";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
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
	ch.id		= "PuertoPrincipegirlport_9";
	ch.model    = "Womens_7";
	ch.sex      = "woman";
	ch.model.animation	= "towngirl";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_port";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Gothic_Quest\npc\Noblegirl.c";
	ch.dialog.currentnode   = "first time";
	ch.greeting = "SantLous_woman";
	LAi_SetLoginTime(ch, 11.0, 21.99);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// девки порт Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	makeref(ch,Characters[n]);			//Священик
	ch.id		= "PuertoPrincipe_Priest";
	ch.model	= "priest_3";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "PuertoPrincipe";
	ch.location	= "PuertoPrincipe_church";
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

	return n;
}
