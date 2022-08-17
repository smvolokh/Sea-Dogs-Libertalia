
int LocationInitGuadeloupe(int n)
{	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Guadeloupe";
	locations[n].filespath.models = "locations\Town_Guadeloupe\Town\";
	
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 3; 
	//Town sack
	locations[n].townsack = "BasTer";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "Guadeloupe";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Guadeloupe_signsA";
	locations[n].models.always.seabed = "Guadeloupe_sb";
	locations[n].models.always.grassPatch = "Guadeloupe_grass";
	locations[n].models.always.locators = "Guadeloupe_locators";

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.3;

	//Day
	locations[n].models.day.fonar = "Guadeloupe_fd";
	locations[n].models.day.rinok = "Guadeloupe_rinok";
	locations[n].models.day.charactersPatch = "Guadeloupe_patch_day";
	//Night
	locations[n].models.night.fonar = "Guadeloupe_fn";
	locations[n].models.night.charactersPatch = "Guadeloupe_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "BasTer_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "BasTer_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "BasTer_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "BasTer_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "BasTer_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l71.name = "reload71_back";
	locations[n].reload.l71.go = "BasTer_church";
	locations[n].reload.l71.emerge = "reload2";
	locations[n].reload.l71.autoreload = "0";
	locations[n].reload.l71.label = "Church";
	//locations[n].reload.l71.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "BasTer_Bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "BasTer_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "BasTer_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "BasTer_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации.
	locations[n].reload.l11.name = "houseF1";
	locations[n].reload.l11.go = "BasTer_houseF1";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Olone House";

	locations[n].reload.l12.name = "houseSp1";
	locations[n].reload.l12.go = "BasTer_houseSp1";
	locations[n].reload.l12.emerge = "reload1_back";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "Ascold House";

    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseS2";
	locations[n].reload.l20.go = "CommonCobHouse";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseH2";
	locations[n].reload.l21.go = "CommonRoom_MH3";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l23.name = "houseS3";
	locations[n].reload.l23.go = "CommonPirateHouse";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseS1";
	locations[n].reload.l24.go = "CommonStoneHouse";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseSp2";
	locations[n].reload.l25.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseH1";
	locations[n].reload.l26.go = "CommonRoom_MH4";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";	
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_tavern";
	locations[n].id.label = "Tavern7";
	locations[n].filespath.models = "locations\inside\Tavern04\";
	locations[n].image = "loading\inside\tavern_2fr.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.tavern = "tavern04";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern04_locators";
	locations[n].models.always.window = "tavern04_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Tavern04_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "BasTer_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].models.always.locators = "Tavern_room_locators";
	locations[n].models.always.tavern = "Tavern_room";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "tavern_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Tavern_room_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern_room_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store02\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "BasTer";
 	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.locators = "Store02_locators";
	locations[n].models.always.store = "Store02";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store02_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store02_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
    ////////////////////////==> комната в магазине
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard02\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.locators = "Shipyard02_locators";
	locations[n].models.always.shipyard = "Shipyard02";
	locations[n].models.always.shipyard.level = 65538;
	locations[n].models.always.window = "shipyard02_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Shipyard02_patch";
	//Night
	locations[n].models.night.charactersPatch = "Shipyard02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence04";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.locators = "Residence04_locators";
	locations[n].models.always.l1 = "Residence04";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence04_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence04_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Always
	locations[n].models.always.locators = "Bank01_locators";
	locations[n].models.always.store = "Bank01";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Bank01_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Bank01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Bank01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload8";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_5";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].models.always.locators = "Church01_locators";
	locations[n].models.always.tavern = "Church01";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Church01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Church01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Church01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "BasTer_town";
	locations[n].reload.l2.emerge = "reload71";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\PortOffice";
	locations[n].models.always.housePortOffice = "PortOffice";
	locations[n].models.always.housePortOffice.level = 65538;
	locations[n].models.always.locators = "PortOffice_locators";

	Locations[n].models.always.PortOffice = "PortOffice_windows";
	Locations[n].models.always.PortOffice.tech = "LocationWindows";
	locations[n].models.always.PortOffice.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "PortOffice_patch";
	//Night
	locations[n].models.night.charactersPatch = "PortOffice_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Франсуа Олоне
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_houseF1";
	locations[n].id.label = "Olone House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse02";
	locations[n].models.always.mediumhouse02 = "mediumhouse02";
	locations[n].models.always.mediumhouse02.level = 65538;
	locations[n].models.day.locators = "mediumhouse02_locators";
	locations[n].models.night.locators = "mediumhouse02_Nlocators";

	Locations[n].models.always.mediumhouse02windows = "mediumhouse02_windows";
	Locations[n].models.always.mediumhouse02windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse02windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.always.mediumhouse02rand= "mediumhouse02_rand";
	locations[n].models.day.charactersPatch = "mediumhouse02_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
    //Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Аскольда
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_houseSp1"; 
	locations[n].id.label = "Ascold House";
	locations[n].image = "loading\inside\largehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	locations[n].locators_radius.item.bottle1 = 1.1;
	locations[n].locators_radius.item.bottle2 = 1.1;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\PortOffice2";
	locations[n].models.always.housePortOffice2 = "PortOffice2";
	locations[n].models.always.housePortOffice2.level = 65538;
	locations[n].models.always.locators = "PortOffice2_locators";

	Locations[n].models.always.PortOffice2 = "PortOffice2_windows";
	Locations[n].models.always.PortOffice2.tech = "LocationWindows";
	locations[n].models.always.PortOffice2.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "PortOffice2_patch";
	//Night
	locations[n].models.night.charactersPatch = "PortOffice2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "street";
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "BasTer_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "BasTer";
    locations[n].parent_colony = "BasTer";
 	locations[n].fastreload = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "jail";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\prison1";
	locations[n].models.always.prison1 = "prison1";
	locations[n].models.always.lamps = "prison1_lamps";
	locations[n].models.always.locators = "prison1_locators";	
	locations[n].models.always.chest = "chest1";
	//Day
	locations[n].models.day.charactersPatch = "prison1_patch";
	//Night
	locations[n].models.night.charactersPatch = "prison1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
    //Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BasTer_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	//Sound
	locations[n].type = "exittown";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitW";
	Locations[n].models.always.townExit = "townExitW";
	Locations[n].models.always.townWalls = "townExitW_stucco";
	
	Locations[n].models.always.locators = "townExitW_locators";
		
	Locations[n].models.always.grassPatch = "townExitW_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "townExitW_patch";
	locations[n].models.day.fonars = "townExitW_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitW_patch";
	locations[n].models.night.fonars = "townExitW_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "BasTer_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "BasTer";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_01";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Guadeloupe_jungle_03";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Guadeloupe_jungle_03";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "BasTer_Fort";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "1";
	locations[n].reload.l4.label = "BasTer Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle2";
	Locations[n].models.always.jungle = "jungle2";	
	Locations[n].models.always.locators = "jungle2_locators";		
	Locations[n].models.always.grassPatch = "jungle2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle2_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle2_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "BasTer_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_MinesEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore29";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в рудники
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_MinesEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\CaveEnt1";
	Locations[n].models.always.caveEnt1 = "caveEnt1";	
	Locations[n].models.always.locators = "caveEnt1_locators";		
	Locations[n].models.always.grassPatch = "caveEnt1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "caveEnt1_patch";
	//Night
	locations[n].models.night.charactersPatch = "caveEnt1_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_Mines";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mines Sagitta";
	locations[n].reload.l1.disable = 0;
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_03";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера Сагитты	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_Mines";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].id.label = "Mines Sagitta";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Guadeloupe";
	locations[n].mining2.key = "minepick";
	locations[n].mining3.key = "minepick";
	locations[n].mining4.key = "minepick";
	locations[n].mining1.key = "minepick";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	//Models	
	//Always
	Locations[n].filespath.models = "Locations\Gothic\Colony\MINE2";
	Locations[n].models.always.locators = "mine_l";
	Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "mine_p";
	//Night
	Locations[n].models.night.charactersPatch = "mine_p";

	//Environment	
	Locations[n].models.always.Chest = "Chest";
	Locations[n].models.always.Chest.locator.group = "item";
	Locations[n].models.always.Chest.locator.name = "chest";

	Locations[n].models.always.Dig1 = "Pick";
	Locations[n].models.always.Dig1.locator.group = "item";
	Locations[n].models.always.Dig1.locator.name = "dig1";

	Locations[n].locators_radius.item.dig1 = 2.0;
	Locations[n].locators_radius.item.dig1_0 = 1.0;
	Locations[n].locators_radius.item.dig1_1 = 1.0;
	Locations[n].locators_radius.item.dig1_2 = 1.0;
	
	locations[n].locators_radius.box.box1 = 1.5;
	Locations[n].locators_radius.goto.goto8 = 3;
	
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_MinesEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "torture_room";
	Locations[n].reload.l2.emerge = "Reload1_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Prison";
	Locations[n].locators_radius.reload.reload2_back = 2;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "torture_room";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Guadeloupe";
	locations[n].fastreload = "Guadeloupe";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\torture_room";
	locations[n].models.always.tavern = "torture_room";
                locations[n].models.day.locators = "torture_room_locators"; 
	//Day
	locations[n].models.day.charactersPatch = "torture_room_patch";
	locations[n].models.day.fonar = "torture_room_fn";
	//Night
	locations[n].models.night.charactersPatch = "torture_room_patch";
	locations[n].models.night.fonar = "torture_room_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1_back";
	Locations[n].reload.l1.go = "Guadeloupe_Mines";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";	
	Locations[n].reload.l1.label = "cave";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// пляж Капстер	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore29";
	locations[n].id.label = "Shore29";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore29";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Guadeloupe";
	locations[n].fennisgrass = 1;
	locations[n].mining1.key = "minepick";
	locations[n].mining2.key = "minepick";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore15";
	Locations[n].models.always.shore15 = "shore15";
	locations[n].models.always.shore15.sea_reflection = 1;
	Locations[n].models.always.shore15seabed = "shore15_sb";
	Locations[n].models.always.locators = "shore15_locators";
		
	Locations[n].models.always.grassPatch = "shore15_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "shore15_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore15_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_03";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle7";
	Locations[n].models.always.jungle = "jungle7";	
	Locations[n].models.always.locators = "jungle7_locators";		
	Locations[n].models.always.grassPatch = "jungle7_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle7_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle7_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_05";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "BasTer_ExitTown";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "ExitTown";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle6";
	Locations[n].models.always.jungle = "jungle6";	
	Locations[n].models.always.locators = "jungle6_locators";		
	Locations[n].models.always.grassPatch = "jungle6_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle6_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle6_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_01";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Mayak4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Mayak4";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Villa_Exit";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из имения
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Villa_Exit";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungles\TownExitG";
	Locations[n].models.always.jungle = "TownExitG";
	Locations[n].models.always.locators = "TownExitG_locators";
	Locations[n].models.always.grassPatch = "TownExitG_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "TownExitG_patch";
	Locations[n].models.day.fonar = "TownExitG_fd";
	//Night
	Locations[n].models.night.charactersPatch = "TownExitG_patch";
	Locations[n].models.night.fonar = "TownExitG_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Guadeloupe_jungle_05";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Villa";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Estate";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Guadeloupe_jungle_house";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "0";
	Locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом охраны	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Guadeloupe_jungle_house";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "BasTer";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Mein";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_3_inside";
	locations[n].models.always.locators = "Hut_3_inside_locators";
	locations[n].models.always.tavern = "Hut_3_inside";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut_3_inside_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_3_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_3_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Villa_Exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Имение Губернатора
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Villa";
	locations[n].id.label = "Villa";
	locations[n].filespath.models = "locations\Estate";
	locations[n].image = "loading\inside\BigHouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "Villa";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.estate = "estate";
	
	locations[n].models.always.windows = "estate_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";	
	Locations[n].models.always.windows.level = 66532;	
	//VolumeLight	
	Locations[n].models.always.vlight = "estate_vlight";
	Locations[n].models.always.vlight.uvslide.v0 = 0.05;
                Locations[n].models.always.vlight.uvslide.v1 = 0.0;
	Locations[n].models.always.vlight.tech = "LocationWaterFall";
	Locations[n].models.always.vlight.level = 99950;
	
	locations[n].models.always.locators = "estate_locators";
	locations[n].models.always.grassPatch = "estate_grass";
	//Day
	locations[n].models.day.charactersPatch = "estate_patch";
	locations[n].models.day.fonar = "estate_fd";
	//Night
	locations[n].models.night.charactersPatch = "estate_patch";
	locations[n].models.night.fonar = "estate_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villa_Exit";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "EstatetBadRoom1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Bedroom";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "EstatetBadRoom2";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Bedroom";
	locations[n].locators_radius.item.item1 = 1.0;

	locations[n].reload.l4.name = "reload5";
	locations[n].reload.l4.go = "EstatetOffice";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Cabinet";
	locations[n].locators_radius.item.item1 = 1.0;

	locations[n].reload.l5.name = "reload6";
	locations[n].reload.l5.go = "EstatetOffice1";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Cabinet";
	locations[n].locators_radius.item.item1 = 1.0;

	locations[n].reload.l6.name = "reload4";
	locations[n].reload.l6.go = "EstatetOffice2";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Cabinet";
	locations[n].locators_radius.item.item1 = 1.0;
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);	
	//homo
	locations[n].private1.key = "key3";     //сундук на балконе
	locations[n].private1.key.delItem = true; //eddy. нужно забрать ключ, иначе в ГПК у геймера будет суперлафа
	locations[n].private1.items.blade2 = 1;
	locations[n].private1.items.pistol1 = 1;
	locations[n].private1.items.bullet = 10;
	locations[n].private1.items.GunPowder = 10; // Warship fix 19.03.09 добавим порох
	n = n + 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Спальня #1 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "EstatetBadRoom1";
	locations[n].id.label = "Bedroom";
	locations[n].filespath.models = "locations\EstateRooms\EstateBadRoom1";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";

	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.estateBadRoom = "estateBadRoom1";	
	locations[n].models.always.windows = "estateBadRoom1_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66532;	
	//VolumeLight	
	Locations[n].models.always.vlight = "estateBadRoom1_vlight";
	Locations[n].models.always.vlight.uvslide.v0 = 0.05;
                Locations[n].models.always.vlight.uvslide.v1 = 0.0;
	Locations[n].models.always.vlight.tech = "LocationWaterFall";
	Locations[n].models.always.vlight.level = 99950;
	
	locations[n].models.always.locators = "estateBadRoom1_locators";
	locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	locations[n].models.day.charactersPatch = "estateBadRoom1_patch";
	locations[n].models.day.fonar = "estateRooms_fd";
	//Night
	locations[n].models.night.charactersPatch = "estateBadRoom1_patch";
	locations[n].models.night.fonar = "estateRooms_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villa";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Villa";
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Спальня #2 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "EstatetBadRoom2";
	locations[n].id.label = "Bedroom";
	locations[n].filespath.models = "locations\EstateRooms\EstateBadRoom2";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";

	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.estateBadRoom = "estateBadRoom2";
	locations[n].models.always.windows = "estateBadRoom2_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66532;
	//VolumeLight	
	Locations[n].models.always.vlight = "estateBadRoom2_vlight";
	Locations[n].models.always.vlight.uvslide.v0 = 0.05;
   	Locations[n].models.always.vlight.uvslide.v1 = 0.0;
	Locations[n].models.always.vlight.tech = "LocationWaterFall";
	Locations[n].models.always.vlight.level = 99950;
	
	locations[n].models.always.locators = "estateBadRoom2_locators";
	locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	locations[n].models.day.charactersPatch = "estateBadRoom2_patch";
	locations[n].models.day.fonar = "estateRooms_fd";
	//Night
	locations[n].models.night.charactersPatch = "estateBadRoom2_patch";
	locations[n].models.night.fonar = "estateRooms_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villa";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Villa";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Кабинет #1 

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//				приемная генерал-губернатора Франции - де Пуанси
///////////////////////////////////////////////////////////////////////////////////////////////////////////	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "EstatetOffice";
	locations[n].id.label = "Cabinet";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\EstateRooms\EstateOffice";
	locations[n].models.always.EstateOffice = "estateOffice";
	locations[n].models.always.windows = "estateOffice_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66532;
	//VolumeLight	
	Locations[n].models.always.vlight = "estateOffice_vlight";
	Locations[n].models.always.vlight.uvslide.v0 = 0.05;
   	Locations[n].models.always.vlight.uvslide.v1 = 0.0;
	Locations[n].models.always.vlight.tech = "LocationWaterFall";
	Locations[n].models.always.vlight.level = 99950;
	
	locations[n].models.always.locators = "estateOffice_locators";
	locations[n].models.always.grassPatch = "estateOffice_grass";
	//Day
	locations[n].models.day.charactersPatch = "estateOffice_patch";
	locations[n].models.day.fonar = "estateOffice_fd";
	//Night
	locations[n].models.night.charactersPatch = "estateOffice_patch";
	locations[n].models.night.fonar = "estateOffice_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villa";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Villa";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Кабинет #2 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "EstatetOffice1"; 
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\SmallResidence";
	locations[n].models.always.locators = "SmallResidence_locators";
	locations[n].models.always.house = "SmallResidence";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "SmallResidence_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "SmallResidence_patch";
	//Night
	locations[n].models.night.charactersPatch = "SmallResidence_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villa";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Villa";
                n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// // Спальня #2 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "EstatetOffice2"; 
	locations[n].id.label = "Bedroom";
	locations[n].filespath.models = "locations\EstateRooms\EstateBadRoom2";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";

	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.estateBadRoom = "estateBadRoom2";
	locations[n].models.always.windows = "estateBadRoom2_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66532;
	//VolumeLight	
	Locations[n].models.always.vlight = "estateBadRoom2_vlight";
	Locations[n].models.always.vlight.uvslide.v0 = 0.05;
   	Locations[n].models.always.vlight.uvslide.v1 = 0.0;
	Locations[n].models.always.vlight.tech = "LocationWaterFall";
	Locations[n].models.always.vlight.level = 99950;
	
	locations[n].models.always.locators = "estateBadRoom2_locators";
	locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	locations[n].models.day.charactersPatch = "estateBadRoom2_patch";
	locations[n].models.day.fonar = "estateRooms_fd";
	//Night
	locations[n].models.night.charactersPatch = "estateBadRoom2_patch";
	locations[n].models.night.fonar = "estateRooms_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Villa";
	Locations[n].reload.l1.emerge = "Reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Villa";
	n = n + 1;	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Маяк Гваделупы	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Mayak4";
	locations[n].id.label = "Mayak4";
	locations[n].worldmap = "Mayak4";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "mayak";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Lighthouse";
	Locations[n].models.always.lighthouse = "lighthouse";
	locations[n].models.always.lighthouse.sea_reflection = 1;
	Locations[n].models.always.lighthouseSeabed = "lighthouse_sb";
	Locations[n].models.always.locators = "lighthouse_locators";
	
	Locations[n].models.always.dooropen = "lighthouse_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouse_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouse_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouse_winday";
	locations[n].models.day.fonar = "lighthouse_fd";
	locations[n].models.day.charactersPatch = "lighthouse_patch";
	Locations[n].models.day.jumpPatch = "lighthouse_jamp";
	
	locations[n].models.day.glassinday = "lighthouse_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouse_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;	
	//Night
	locations[n].models.night.volumeLight= "lighthouse_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouse_fn";
	locations[n].models.night.winnight = "lighthouse_winnight";
	locations[n].models.night.winnight.tech = "LighthouseLight";
	locations[n].models.night.winnight.level = 66529;
	locations[n].models.night.charactersPatch = "lighthouse_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse_fonaronnight";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_05";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 12.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Mayak4_Lighthouseroom";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.label = "house";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ДОМ МАЯКА
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Mayak4_Lighthouseroom";
	locations[n].id.label = "Mayak_house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "mayak";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Guadeloupe";
	locations[n].islandIdAreal = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse10";
	locations[n].models.always.house = "mediumhouse10";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "mediumhouse10_locators";
	locations[n].models.night.locators = "mediumhouse10_Nlocators";

	Locations[n].models.always.mediumhouse10windows = "mediumhouse10_windows";
	Locations[n].models.always.mediumhouse10windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse10windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse10rand= "mediumhouse10_rand";
	locations[n].models.day.charactersPatch = "mediumhouse10_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse10_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Mayak4";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mayak4";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle6";
	Locations[n].models.always.jungle = "jungle6";	
	Locations[n].models.always.locators = "jungle6_locators";		
	Locations[n].models.always.grassPatch = "jungle6_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle6_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle6_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore28";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Passage";
    locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Guadeloupe_CaveEntrance";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Cave entrance";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\CaveEnt2";
	Locations[n].models.always.caveEnt2 = "caveEnt2";	
	Locations[n].models.always.locators = "caveEnt2_locators";		
	Locations[n].models.always.grassPatch = "caveEnt2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "caveEnt2_patch";
	//Night
	locations[n].models.night.charactersPatch = "caveEnt2_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].id.label = "Cave";
	locations[n].VaterSkelLand = true;
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Guadeloupe";
	//Models	
	//Always
	locations[n].filespath.models = "locations\inside\cavernBig1";
	locations[n].models.always.cavernBig1 = "cavernBig1";
	locations[n].models.always.lamps = "cavernBig1_lamps";
	locations[n].models.always.rays = "cavernBig1_rays";	
	locations[n].models.always.locators = "cavernBig1_locators";

	//Locations[n].models.always.StoneMap = "StoneMap";
	//Locations[n].models.always.StoneMap.locator.group = "item";
	//Locations[n].models.always.StoneMap.locator.name = "item1";

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "cavernBig1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	

	//Day
	locations[n].models.day.charactersPatch = "cavernBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernBig1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].locators_radius.item.button02 = 2.0;

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Бухта Морн л'О, мост Аззи
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore28";
	locations[n].id.label = "Shore28";
	locations[n].image = "loading\outside\bridge.tga";	
	locations[n].Chestgennot = true; // не генерить сундуки
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\passage";
	Locations[n].models.always.passage = "passage";
	locations[n].models.always.passage.sea_reflection = 1;
	Locations[n].models.always.seabed = "passage_sb";		
	Locations[n].models.always.grassPatch = "passage_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.locators = "passage_locators";	
	//Day
	locations[n].models.day.charactersPatch = "passage_patch";
	//Night
	locations[n].models.night.charactersPatch = "passage_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Shore80";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore80";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Гран Бур	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore30";
	locations[n].id.label = "Shore30";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore30";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	locations[n].mining5.key = "minepick";
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "x_seashore";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Grotto";
	locations[n].models.always.town = "Grotto";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.seabed = "Grotto_sb";
	locations[n].models.always.grassPatch = "Grotto_grass";
	locations[n].models.always.locators = "Grotto_locators";

	locations[n].models.always.l2 = "Gold";
	locations[n].models.always.l2.tech = "EnvironmentShader";
	locations[n].models.always.l2.reflection = 1;

	locations[n].models.always.Waterfall1 = "water";
	locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
	locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall1.level = 50;

	locations[n].models.always.Waterfall2 = "cfall";
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
	locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall2.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "Grotto_patch_day";
	//Night
	locations[n].models.night.charactersPatch = "Grotto_patch_day";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "boat";
	locations[n].reload.l1.go = "Guadeloupe";
	locations[n].reload.l1.emerge = "reload_5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 3.0;
                   locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Strange_Grotto";
	locations[n].reload.l2.emerge = "reload4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ТАЙНЫЙ ГРОТ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Strange_Grotto";
	locations[n].id.label = "Grotto Strange";
    	locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\cavernBig1";
	locations[n].models.always.cavernBig1 = "cavernBig1";
	locations[n].models.always.lamps = "cavernBig1_lamps";	
	locations[n].models.always.locators = "cavernBig1_locators";

	Locations[n].models.always.StoneMap = "StoneMap";
	Locations[n].models.always.StoneMap.locator.group = "item";
	Locations[n].models.always.StoneMap.locator.name = "item1";

	//Day
	locations[n].models.day.charactersPatch = "cavernBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernBig1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload3_back";
	locations[n].reload.l1.go = "";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 2;
	
	locations[n].reload.l2.name = "reload4";
	locations[n].reload.l2.go = "Shore30";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Shore30";
	n = n + 1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Cент-Луи порт	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_Port";
	locations[n].id.label = "SantLous Port";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "SantLous Port";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "Port";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	Locations[n].filespath.models = "locations\SantLous\Port";	
	Locations[n].models.always.qcport = "qcport";
	locations[n].models.always.qcport.sea_reflection = 1;
	Locations[n].models.always.shore01seabed = "qcport_sb";
	Locations[n].models.always.locators = "QCport_l";

	Locations[n].models.always.grassPatch = "QCport_g";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	Locations[n].models.day.charactersPatch = "QCport_p";
	Locations[n].models.day.jumpPatch = "QCport_j";
	//Night
	Locations[n].models.night.charactersPatch = "QCport_p";
	locations[n].models.night.jumpPatch = "QCport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "SantLous_ExitTown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Выход из города Сент-Луи	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 locations[n].id = "SantLous_ExitTown";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Town sack
	Locations[n].townsack = "SantLous";
 	//Sound
	locations[n].type = "Port";
	locations[n].islandId = "Guadeloupe";
	locations[n].fastreload = "SantLous";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle3";
	Locations[n].models.always.jungle = "jungle3";	
	Locations[n].models.always.locators = "jungle3_locators";		
	Locations[n].models.always.grassPatch = "jungle3_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "Jungle3_wall";
	Locations[n].models.always.l4.tech = "DLightModel";	
	//Day
	locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle3_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_07";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 3.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "SantLous_town";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Street";
                        locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "SantLous_Port";
	locations[n].reload.l3.emerge = "reload2_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "SantLous Port";
	locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Деревня Сент-Луи
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_town";
	locations[n].id.label = "SantLous";
	Locations[n].image = "loading\towns\pearl4.tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Town sack
	locations[n].townsack = "SantLous";
	//Sound
	locations[n].type = "Port";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\SantLous\town";
	Locations[n].models.always.QCtown = "QCtown";	
	Locations[n].models.always.locators = "QCtown_l";		
	Locations[n].models.always.grassPatch = "QCtown_g";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "QCtown_p";
	locations[n].models.day.fonars = "QCtown_fd";
	//Night
	locations[n].models.night.charactersPatch = "QCtown_p";
	locations[n].models.night.fonars = "QCtown_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "SantLous_ExitTown";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 0;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l2.name = "Reload10";
	Locations[n].reload.l2.go = "SantLous_townhall";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Residence";
	

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "SantLous_Tavern";
	Locations[n].reload.l3.emerge = "Reload1_back";
	Locations[n].reload.l3.label = "Tavern";

	Locations[n].reload.l4.name = "Reload5";
	Locations[n].reload.l4.go = "SantLous_store";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "Store";
	Locations[n].reload.l4.close_for_night = 1;

	Locations[n].reload.l5.name = "Reload3";
	Locations[n].reload.l5.go = "SantLous_House3";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.label = "House";

	Locations[n].reload.l6.name = "Reload4";
	Locations[n].reload.l6.go = "SantLous_HouseInsideR4";
	Locations[n].reload.l6.emerge = "Reload1";
	Locations[n].reload.l6.label = "House_Lucia";
	Locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "Reload7";
	Locations[n].reload.l7.go = "CommonRoom_MH2";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "Reload12";
	Locations[n].reload.l8.go = "CommonRoom_MH2";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House";
	Locations[n].reload.l8.close_for_night = 1;

	Locations[n].reload.l9.name = "Reload8";
	Locations[n].reload.l9.go = "SantLous_PirateHouse";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House";
	Locations[n].reload.l9.close_for_night = 1;

	Locations[n].reload.l10.name = "reload2";
	Locations[n].reload.l10.go = "SantLous_HouseHut";
	Locations[n].reload.l10.emerge = "reload2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House";

	Locations[n].reload.l11.name = "reload9";
	Locations[n].reload.l11.go = "SantLous_HouseHut_1";
	Locations[n].reload.l11.emerge = "reload1_back";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "House";

	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                  Старая таверна	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "SantLous_Tavern";
	locations[n].id.label = "Tavern36";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\tavern09\";
	locations[n].models.always.tavern = "tavern09";
	Locations[n].models.always.tavern.tech = "DLightModel";	
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern09_locators";
	Locations[n].models.always.locators.tech = "DLightModel";	
	locations[n].models.always.window = "tavern09_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.fonar = "tavern09_fd";
	locations[n].models.day.charactersPatch = "tavern09_patch";
	//Night
	Locations[n].models.night.fonar = "tavern09_fn";
	locations[n].models.night.charactersPatch = "tavern09_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SantLous_town";
	locations[n].reload.l1.emerge = "Reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "SantLous_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но свљзку сделаем длљ квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);

    ////////////////////////==> подсобка таверны
	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "SantLous_Packhouse";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Room";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Комната в таверне 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].models.always.locators = "Tavern_room_locators";
	locations[n].models.always.tavern = "Tavern_room";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "tavern_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Tavern_room_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern_room_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SantLous_Tavern";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Склад	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_Packhouse";
	locations[n].id.label = "tavern_room";
	locations[n].image = "loading\inside\sklad.tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad03";
	locations[n].models.always.locators = "sklad03_locators";
	locations[n].models.always.modelSklad = "sklad03";
	locations[n].models.always.modelSklad.level = 65538;
	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "sklad03_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad03_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "SantLous_Tavern";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern36";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Дом главы	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_townhall";
	locations[n].id.label = "Residence";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence05";
	locations[n].models.always.locators = "Residence05_locators";
	locations[n].models.always.l1 = "Residence05";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence05_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "residence05_patch";
	//Night
	locations[n].models.night.charactersPatch = "residence05_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "SantLous_town";
	Locations[n].reload.l1.emerge = "Reload10";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "SantLous_townhall_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Резеденция 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_townhall_room"; 
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Port";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\murdoch_room";
	locations[n].models.always.murdoch_room = "murdoch_room";
	locations[n].models.always.murdoch_room.level = 65538;
	locations[n].models.day.locators = "murdoch_room_locators";
	locations[n].models.night.locators = "murdoch_room_Nlocators";

	Locations[n].models.always.murdoch_room_windows = "murdoch_room_windows";
	Locations[n].models.always.murdoch_room_windows.tech = "LocationWindows";
	locations[n].models.always.murdoch_room_windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;

	locations[n].models.always.well_small1 = "murdoch_room_bed0";
	Locations[n].models.always.well_small1.locator.group = "reload";
	Locations[n].models.always.well_small1.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small1.tech = "DLightModel";

	locations[n].models.always.well_small2 = "murdoch_room_bed1";
	Locations[n].models.always.well_small2.locator.group = "reload";
	Locations[n].models.always.well_small2.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small2.tech = "DLightModel";

	locations[n].models.always.well_small3 = "murdoch_room_bed2";
	Locations[n].models.always.well_small3.locator.group = "reload";
	Locations[n].models.always.well_small3.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small3.tech = "DLightModel";

	locations[n].models.always.well_small4 = "murdoch_room_bed3";
	Locations[n].models.always.well_small4.locator.group = "reload";
	Locations[n].models.always.well_small4.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small4.tech = "DLightModel";
	//Day
	Locations[n].models.day.largehouse01rand= "murdoch_room_rand";
	locations[n].models.day.charactersPatch = "murdoch_room_patch";
	//Night
	locations[n].models.night.charactersPatch = "murdoch_room_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SantLous_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "residence";
	LAi_LocationFightDisable(&locations[n], true);
                n = n + 1;	


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Магазин	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_store";
	locations[n].id.label = "Store";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\StoreSmall\";
	locations[n].models.always.locators = "StoreSmall_locators";
	locations[n].models.always.store = "StoreSmall";
	locations[n].models.always.window = "StoreSmall_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "StoreSmall_patch";
	//Night
	locations[n].models.night.charactersPatch = "StoreSmall_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "SantLous_town";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.label = "Street";

    ////////////////////////==> комната в магазине
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH10";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Дом	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_HouseInsideR4";
	locations[n].id.label = "House_Lucia";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "SantLous";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\pirateresidence";
	locations[n].models.always.house = "ResP";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "ResP_w";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "ResP_l";
	locations[n].models.day.charactersPatch = "ResP_p";
	//Night
	locations[n].models.night.locators = "ResP_l_n";
	locations[n].models.night.charactersPatch = "ResP_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "SantLous_town";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Дом	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "SantLous_PirateHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "SantLous";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Pirate_House";
	locations[n].models.always.house = "PirH";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "PirH_w";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "PirH_l";
	locations[n].models.day.charactersPatch = "PirH_p";
	//Night
	locations[n].models.night.locators = "PirH_l_n";
	locations[n].models.night.charactersPatch = "PirH_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "SantLous_town";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Хибара	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "SantLous_HouseHut_1";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut4";
	locations[n].models.always.locators = "Hut4_locators";
	locations[n].models.always.tavern = "Hut4";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut4_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut4_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut4_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "SantLous_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_House3";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse03";
	locations[n].models.always.mediumhouse03 = "mediumhouse03";
	locations[n].models.always.mediumhouse03.level = 65538;
	locations[n].models.day.locators = "mediumhouse03_locators";
	locations[n].models.night.locators = "mediumhouse03_Nlocators";

	Locations[n].models.always.mediumhouse03windows = "mediumhouse03_windows";
	Locations[n].models.always.mediumhouse03windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse03windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse03rand= "mediumhouse03_rand";
	locations[n].models.day.charactersPatch = "mediumhouse03_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse03_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SantLous_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Изба рыбака	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_HouseHut";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "SantLous";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].models.always.locators = "Hut_locators";
	locations[n].models.always.tavern = "Hut";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "SantLous_town";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "SantLous_Dungeon";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Dungeon";
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Podval
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "SantLous_Dungeon";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "SantLous";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "SantLous";
	locations[n].fastreload = "Guadeloupe";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1 = "DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1Stuff = "DungeonDuffer1_stuff";
	locations[n].models.always.locators = "DungeonDuffer1_locators";

	//locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "DungeonDuffer1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
	//Day
	locations[n].models.day.charactersPatch = "DungeonDuffer1_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonDuffer1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "SantLous_HouseHut";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	locations[n].locators_radius.item.berglar1 = 6.0;
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	LAi_LocationFightDisable(&Locations[n], false);
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "Port";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle10";
	Locations[n].models.always.jungle = "jungle10";	
	Locations[n].models.always.locators = "jungle10_locators";		
	Locations[n].models.always.grassPatch = "jungle10_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle10_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle10_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SantLous_ExitTown";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_08";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "BasTer_Plantation";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].MonkeyLand = true;
	//Sound
	locations[n].type = "Port";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle6";
	Locations[n].models.always.jungle = "jungle6";	
	Locations[n].models.always.locators = "jungle6_locators";		
	Locations[n].models.always.grassPatch = "jungle6_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle6_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle6_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_07";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore31";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore31";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "SantLous_CaveEntrase2";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_CaveEntrase2";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].MonkeyLand = true;
	//Sound
	locations[n].type = "Port";
	locations[n].islandId = "Guadeloupe";
	locations[n].DisableEncounters = true;
	locations[n].onUninhabitedIsland = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\CaveEnt1";
	Locations[n].models.always.caveEnt1 = "caveEnt1";	
	Locations[n].models.always.locators = "caveEnt1_locators";		
	Locations[n].models.always.grassPatch = "caveEnt1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "caveEnt1_patch";
	//Night
	locations[n].models.night.charactersPatch = "caveEnt1_patch";	
	//Environment	
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SantLous_Grot";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_08";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SantLous_Grot";
	locations[n].id.label = "Grot";
     locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Cave";
	locations[n].islandId = "Guadeloupe";
	locations[n].onUninhabitedIsland = true;
	locations[n].mining2.key = "minepick";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto2";
	locations[n].models.always.grotto2 = "grotto2";
	locations[n].models.always.grotto2.sea_reflection = 1;
	locations[n].models.always.grotto2alpha = "grotto2_alpha";
	Locations[n].models.always.grotto2alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto2alpha.level = 65532;	
	locations[n].models.always.locators = "grotto2_locators";	

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "grotto2_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
	//Day
	locations[n].models.day.charactersPatch = "grotto2_patch";
	//Night
	locations[n].models.night.charactersPatch = "grotto2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SantLous_CaveEntrase2";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Плантация Гваделупа	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTer_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\Plantation_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	locations[n].citizens = true;    
	locations[n].soldiers = true;    
	locations[n].carrier = true;
	//Sound
	locations[n].type = "Plantation";
	//Models
	//Always
	locations[n].filespath.models = "locations\BarbadosPlantation";
	locations[n].models.always.BarbadosPlantation = "BarbadosPlantation";	
	locations[n].models.always.reflect = "BarbadosPlantation_reflect";
	Locations[n].models.always.reflect.sea_reflection = 1;	
	locations[n].models.always.gate = "BarbadosPlantation_gateopen";	
	locations[n].models.always.locators = "BarbadosPlantation_locators";
	locations[n].models.always.locators = "BarbadosPlantation_locators_alt";		
	locations[n].models.always.grassPatch = "BarbadosPlantation_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.Waterfall = "waterfall";
	Locations[n].models.always.Waterfall.uvslide.v0 = 0.3;
                        Locations[n].models.always.Waterfall.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall.level = 99949;

	Locations[n].models.always.dooropen = "BarbadosPlantation_wall";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	locations[n].models.always.plan1 = "plan1";
	locations[n].models.always.plan1.level = 9;	
	locations[n].models.always.plan2 = "plan2";
	locations[n].models.always.plan2.level = 8;	
	locations[n].models.always.plan3 = "plan3";
	locations[n].models.always.plan3.level = 7;	
	locations[n].models.always.plan4 = "plan4";
	locations[n].models.always.plan4.level = 6;
	//Day
	locations[n].models.day.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.day.fonar = "BarbadosPlantation_fd";
	//Night
	locations[n].models.night.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.night.fonar = "BarbadosPlantation_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_07";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	//дома
	locations[n].reload.l2.name = "houseSp1";
	locations[n].reload.l2.go = "HouseGarrisOMayli";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = false;
	locations[n].reload.l2.label = "House_GarrisOMayli";

	locations[n].reload.l3.name = "houseS1";
	locations[n].reload.l3.go = "BasTerPlantation_S1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = false;
	locations[n].reload.l3.label = "house";

	locations[n].reload.l4.name = "houseS2";
	locations[n].reload.l4.go = "BasTerPlantation_S2";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = false;
	locations[n].reload.l4.label = "house";

	locations[n].reload.l5.name = "houseF1";
	locations[n].reload.l5.go = "BasTerPlantation_F1";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = false;
	locations[n].reload.l5.label = "house";

	locations[n].reload.l6.name = "houseF2";
	locations[n].reload.l6.go = "BasTerPlantation_F2";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = false;
	locations[n].reload.l6.label = "house";

    locations[n].locators_radius.quest.detector1 = 5.0; //homo
    n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseGarrisOMayli";
	locations[n].id.label = "House_GarrisOMayli";
	locations[n].image = "loading\inside\stonehouse_1.tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\pirateresidence";
	locations[n].models.always.house = "ResP";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "ResP_w";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "ResP_l";
	locations[n].models.day.charactersPatch = "ResP_p";
	//Night
	locations[n].models.night.locators = "ResP_l_n";
	locations[n].models.night.charactersPatch = "ResP_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_Plantation";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTerPlantation_S1";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.locators = "Hut_locators";
	locations[n].models.always.tavern = "Hut";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_Plantation";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTerPlantation_S2";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.locators = "Hut_locators";
	locations[n].models.always.tavern = "Hut";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "BasTer_Plantation";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTerPlantation_F1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse05";
	locations[n].models.always.mediumhouse05 = "mediumhouse05";
	locations[n].models.always.mediumhouse05.level = 65538;
	locations[n].models.day.locators = "mediumhouse05_locators";
	locations[n].models.night.locators = "mediumhouse05_Nlocators";

	Locations[n].models.always.mediumhouse05windows = "mediumhouse05_windows";
	Locations[n].models.always.mediumhouse05windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse05windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse05rand= "mediumhouse05_rand";
	locations[n].models.day.charactersPatch = "mediumhouse05_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse05_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_Plantation";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "BasTerPlantation_F2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "BasTer";
	locations[n].islandId = "Guadeloupe";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse09";
	locations[n].models.always.house = "mediumhouse09";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "mediumhouse09_locators";
	locations[n].models.night.locators = "mediumhouse09_Nlocators";

	Locations[n].models.always.mediumhouse09windows = "mediumhouse09_windows";
	Locations[n].models.always.mediumhouse09windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse09windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse09rand= "mediumhouse09_rand";
	locations[n].models.day.charactersPatch = "mediumhouse09_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse09_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BasTer_Plantation";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// мыс Недоступный	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore31";
	locations[n].id.label = "Shore31";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore31";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Guadeloupe";
	locations[n].deadlocked = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore03";
	Locations[n].models.always.shore03 = "shore03";
	locations[n].models.always.shore03.sea_reflection = 1;
	Locations[n].models.always.shore03seabed = "shore03_sb";
	Locations[n].models.always.locators = "shore03_locators";
		
	Locations[n].models.always.grassPatch = "shore03_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "shore03_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore03_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_08";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Новая	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore83";
	locations[n].id.label = "Shore83";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore83";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore01";
	Locations[n].models.always.shore01 = "shore01";
	locations[n].models.always.shore01.sea_reflection = 1;
	Locations[n].models.always.shore01seabed = "shore01_sb";
	Locations[n].models.always.locators = "shore01_locators";

	Locations[n].models.always.grassPatch = "shore01_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "shore01_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore01_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_010";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_jungle_010";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].ORCLand = true;
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle2";
	Locations[n].models.always.jungle = "jungle2";	
	Locations[n].models.always.locators = "jungle2_locators";		
	Locations[n].models.always.grassPatch = "jungle2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle2_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle2_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Shore83";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Guadeloupe_CaveEntrance3";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload3_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Guadeloupe_Ruins";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Руины в джунглях	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_Ruins";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Ruins\";
	Locations[n].models.always.ruins1 = "ruins1";
	Locations[n].models.always.locators = "ruins1_locators";
		
	Locations[n].models.always.grassPatch = "ruins1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	locations[n].models.day.charactersPatch = "ruins1_patch";
	//Night
	locations[n].models.night.charactersPatch = "ruins1_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_jungle_010";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_Ruins_Cave";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].locators_radius.reload.reload2 = 1.3;

	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в шахту
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Guadeloupe_CaveEntrance3";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].ORCLand = true;
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\CaveEnt2";
	Locations[n].models.always.caveEnt2 = "caveEnt2";	
	Locations[n].models.always.locators = "caveEnt2_locators";		
	Locations[n].models.always.grassPatch = "caveEnt2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "caveEnt2_patch";
	//Night
	locations[n].models.night.charactersPatch = "caveEnt2_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Guadeloupe_Dungeon3";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Guadeloupe_jungle_010";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Шахта 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Guadeloupe_Dungeon3";
	Locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Guadeloupe";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "Guadeloupe";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\DungeonOld3";
	Locations[n].models.always.tavern.tech = "DLightModel";		
	Locations[n].models.always.locators = "DungeonOld3_locators";
	Locations[n].models.always.locators.tech = "DLightModel";
	locations[n].models.always.window.tech = "LocationWindows";			
	Locations[n].models.always.DungeonOld3 = "DungeonOld3";
	locations[n].models.always.DungeonOld3.level = 65538;

	locations[n].models.always.hatch = "hatch";
	Locations[n].models.always.hatch.locator.group = "Upgrades";
	Locations[n].models.always.hatch.locator.name = "hatch";
	//Day
	Locations[n].models.day.charactersPatch = "DungeonOld3_patch";
	//Night
	Locations[n].models.night.charactersPatch = "DungeonOld3_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Guadeloupe_CaveEntrance3";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;	

///////////////////////////////////////////////////////////////////////////////////////////////////// бухта Калуакаэра (Остров Красивых Вод)	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore80";
	locations[n].id.label = "Shore80";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore80";
	//Sound
	locations[n].type = "xx_seashore";
	locations[n].islandId = "Guadeloupe";
	locations[n].fennisgrass = 1;
	locations[n].questflower = 1;
	locations[n].mining1.key = "minepick";
	locations[n].mining2.key = "minepick";
	locations[n].mining3.key = "minepick";
	locations[n].mining4.key = "minepick";
	locations[n].DisableEncounters = true;
	locations[n].deadlocked = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore16";
	Locations[n].models.always.shore16 = "shore16";
	locations[n].models.always.shore16.sea_reflection = 1;
	//Locations[n].models.always.shore16seabed = "shore16_sb";
	Locations[n].models.always.locators = "shore16_locators";
	Locations[n].models.always.l1 = "trees";
	Locations[n].models.always.l2= "wood_step1";
	Locations[n].models.always.l3= "wood_step2";
	Locations[n].models.always.l4= "wood_step3";

	locations[n].models.always.L5 = "Bfire";
	Locations[n].models.always.L5.locator.group = "goto";
	Locations[n].models.always.L5.locator.name = "fire1";
	Locations[n].models.always.L5.tech = "DLightModel";
	locations[n].models.always.L6 = "Bfire";
	Locations[n].models.always.L6.locator.group = "goto";
	Locations[n].models.always.L6.locator.name = "fire2";
	Locations[n].models.always.L6.tech = "DLightModel";
	locations[n].models.always.L7 = "Bfire";
	Locations[n].models.always.L7.locator.group = "goto";
	Locations[n].models.always.L7.locator.name = "fire3";
	Locations[n].models.always.L7.tech = "DLightModel";
	locations[n].models.always.L8 = "Bfire";
	Locations[n].models.always.L8.locator.group = "goto";
	Locations[n].models.always.L8.locator.name = "fire4";
	Locations[n].models.always.L8.tech = "DLightModel";
	locations[n].models.always.L9 = "Bfire";
	Locations[n].models.always.L9.locator.group = "goto";
	Locations[n].models.always.L9.locator.name = "fire5";
	Locations[n].models.always.L9.tech = "DLightModel";
		
	Locations[n].models.always.grassPatch = "shore16_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	//Day
	locations[n].models.day.charactersPatch = "shore16_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore16_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Guadeloupe";
	locations[n].reload.l2.emerge = "reload_9";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore28";
	locations[n].reload.l3.emerge = "reload2_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore28";

                     locations[n].locators_radius.quest.quest15 = 35.0;
	n = n + 1;
	
	return n;
}
