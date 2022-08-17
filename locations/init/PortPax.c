
int LocationInitPortPax(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "PortPax";
	
	locations[n].townsack = "PortPax";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	
	locations[n].filespath.models = "locations\Town_PortPax\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 5; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "PortPax";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "PortPax_signsA";
	locations[n].models.always.seabed = "PortPax_sb";
	locations[n].models.always.locators = "PortPax_locators";
	locations[n].models.always.grassPatch = "PortPax_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;
	//Fontain
	locations[n].models.always.Waterfall1 = "fontain1";
	locations[n].models.always.Waterfall1.uvslide.v0 = 0.5;
    locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall1.level = 50;
	
	locations[n].models.always.Waterfall2 = "fontain2";
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.2;
    locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall2.level = 49;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.1;
	
	locations[n].models.always.L2 = "Barracks_Door2";
    locations[n].models.always.L3 = "Barracks_Fonar2";
    locations[n].models.always.L2.tech = "DLightModel";
    locations[n].models.always.L3.tech = "DLightModel";

	//Day
	locations[n].models.day.fonar = "PortPax_fd";
	locations[n].models.day.charactersPatch = "PortPax_patch_day";
	locations[n].models.day.rinok = "PortPax_rinok";
	//Night
	locations[n].models.night.fonar = "PortPax_fn";
	locations[n].models.night.charactersPatch = "PortPax_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксациљ на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola2";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortPax_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortPax_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "PortPax_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "PortPax_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "PortPax_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "PortPax_Bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "PortPax_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "PortPax_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "PortPax_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации.

    // --> Комоны, загрушки. Номера с начинаютсљ с 20.
	// Посылка для Сагитты
	locations[n].reload.l20.name = "houseSp3";
	locations[n].reload.l20.go = "HouseAkil";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House Akil";

	locations[n].reload.l21.name = "houseSp2";
	locations[n].reload.l21.go = "CommonStoneHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseF3";
	locations[n].reload.l22.go = "CommonRoom_MH2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseS6";
	locations[n].reload.l23.go = "CommonFlamHouse";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseF4";
	locations[n].reload.l24.go = "CommonRoom_MH";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";
	
	locations[n].reload.l25.name = "houseS5";
	locations[n].reload.l25.go = "CommonStoneHouse";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";
	
	locations[n].reload.l26.name = "houseSp1";
	locations[n].reload.l26.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";
	
	locations[n].reload.l27.name = "houseF2";
	locations[n].reload.l27.go = "CommonRoom_MH";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

	locations[n].reload.l28.name = "houseS4";
	locations[n].reload.l28.go = "CommonCobHouse";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";
	
	locations[n].reload.l29.name = "houseS3";
	locations[n].reload.l29.go = "CommonPirateHouse";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";
	
	locations[n].reload.l30.name = "houseS1";
	locations[n].reload.l30.go = "CommonFlamHouse";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";

	locations[n].reload.l31.name = "houseF1";
	locations[n].reload.l31.go = "CommonRoom_MH9";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

	locations[n].reload.l32.name = "houseS2";
	locations[n].reload.l32.go = "CommonPirateHouse";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

	locations[n].reload.l33.name = "houseH1";
	locations[n].reload.l33.go = "CommonRoom_MH3";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";

	locations[n].reload.l34.name = "houseH2";
	locations[n].reload.l34.go = "CommonRoom_MH5";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";

	locations[n].reload.l35.name = "houseF5";
	locations[n].reload.l35.go = "CommonStoneHouse";
	locations[n].reload.l35.emerge = "reload1";
	locations[n].reload.l35.autoreload = "0";
	locations[n].reload.l35.label = "House";
	
	locations[n].reload.l36.name = "houseSp4";
	locations[n].reload.l36.go = "CommonFlamHouse";
	locations[n].reload.l36.emerge = "reload1";
	locations[n].reload.l36.autoreload = "0";
	locations[n].reload.l36.label = "House";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_tavern";
	locations[n].id.label = "Tavern21";
	locations[n].filespath.models = "locations\inside\tavern01\";
	locations[n].image = "loading\inside\tavern_2fr.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].models.always.tavern = "Tavern01";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "Tavern01_locators";
	locations[n].models.always.window = "tavern01_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.window.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "tavern01_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortPax_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но свљзку сделаем длљ квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortPax";
 	locations[n].islandId = "Hispaniola";
	//Models
	//Always
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
	locations[n].reload.l1.go = "PortPax_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store03\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].models.always.locators = "Store03_locators";
	locations[n].models.always.store = "Store03";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store03_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store03_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//locations[n].models.back = "back\redms_";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.camdetector.camera1 = 5;
    ////////////////////////==> комната в магазине
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank.tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortPax";
 	locations[n].islandId = "Hispaniola";
	//Models
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
	locations[n].reload.l1.go = "PortPax_town";
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
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].models.always.locators = "Shipyard01_locators";
	locations[n].models.always.shipyard = "Shipyard01";
	locations[n].models.always.shipyard.level = 65538;
	locations[n].models.always.window = "shipyard01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Shipyard01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Shipyard01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortPax_town";
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
	locations[n].id = "PortPax_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence04";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PortPax";
 	locations[n].islandId = "Hispaniola";
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
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
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
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortPax";
 	locations[n].islandId = "Hispaniola";
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
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "PortPax_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "PortPax";
    locations[n].parent_colony = "PortPax";
 	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
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
	Locations[n].reload.l1.go = "PortPax_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// дом Акила	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseAkil";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House Akil";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortPax";
	//Models
	//Always
	locations[n].models.always.tavern = "StoneHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "StoneHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
    locations[n].models.day.locators = "StoneHouse_lPrivate"; // homo for CapBloodLine
    locations[n].models.night.locators = "StoneHouse_lPrivateN";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "StoneHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "StoneHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "houseSp3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH5";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "PortPax_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	//Sound
	locations[n].type = "exittown";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
                         //Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitT";
	Locations[n].models.always.townExit = "townExitT";
	Locations[n].models.always.townWalls = "townExitT_stucco";
	
	Locations[n].models.always.locators = "townExitT_locators";
		
	Locations[n].models.always.grassPatch = "townExitT_grass";
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
	locations[n].models.day.charactersPatch = "townExitT_patch";
	locations[n].models.day.fonars = "townExitT_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitT_patch";
	locations[n].models.night.fonars = "townExitT_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "PortPax";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_06";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Hispaniola_Jungle_07";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_Jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle2.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungles\Jungle10";
	Locations[n].models.always.locators = "jungle10_locators";
	Locations[n].models.always.jungle = "Jungle10";
	Locations[n].models.always.grassPatch = "jungle10_grass";
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
	Locations[n].models.day.charactersPatch = "jungle10_patch";
	//Night
	Locations[n].models.night.charactersPatch = "jungle10_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortPax_ExitTown";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_08";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "PortPax_Fort";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "PortPax Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Hispaniola_Jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle2.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].mining3.key = "minepick";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungles\Jungle13";
	Locations[n].models.always.locators = "Jungle13_locators";
	Locations[n].models.always.jungle = "Jungle13";
	Locations[n].models.always.grassPatch = "JUNGLE13_grass";
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
	Locations[n].models.day.charactersPatch = "Jungle13_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle13_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_07";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Abaku_Jungle_03";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore96";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore96";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Hispaniola_CaveEntrance_2";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].ZombieLand = true;
	locations[n].DisableEncounters = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Hispaniola_Cave_2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Grot";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Abaku_jungle_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_Cave_2";
	locations[n].id.label = "Grot";
     locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto2";
	locations[n].models.always.grotto2 = "grotto2";
	locations[n].models.always.grotto2.sea_reflection = 1;
	locations[n].models.always.grotto2alpha = "grotto2_alpha";
	Locations[n].models.always.grotto2alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto2alpha.level = 65532;	
	locations[n].models.always.locators = "grotto2_locators";	

	//locations[n].locators_radius.item.duhi1 = 0.0;
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
	locations[n].reload.l1.go = "Hispaniola_CaveEntrance_2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Маяк Порт-о-Принса	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Mayak7";
	locations[n].id.label = "Mayak7";
	locations[n].worldmap = "Mayak7";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "mayak";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.go = "PortPax_Graveyard";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 12.0;

	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "Mayak7_Lighthouseroom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.label = "room";
	locations[n].locators_radius.reload.reload2 = 1.0;
	n = n + 1;
	
	////////////////////////////////////////////////////////////////////////////////
	//////////комната на маяке
	////////////////////////////////////////////////////////////////////////////////
	
	locations[n].id = "Mayak7_Lighthouseroom";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Portpax";
	locations[n].islandId = "Hispaniola2";
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
	locations[n].reload.l1.go = "Mayak7";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mayak7";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// городское кладбище	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_Graveyard";
	locations[n].id.label = "Graveyard";
	locations[n].image = "loading\Cemetery_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	//Sound
	locations[n].type = "crypt";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Graveyard";
	Locations[n].models.always.Graveyard = "Churchyard";		
	Locations[n].models.always.grassPatch = "Churchyard_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "Churchyard_plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "Churchyard_plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "Churchyard_plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "Churchyard_patch";
	Locations[n].models.day.locators = "Churchyard_ld";	
	//Night
	locations[n].models.night.charactersPatch = "Churchyard_patch";	
	Locations[n].models.night.locators = "Churchyard_ln";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Mayak7";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Mayak7";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PortPax_KeepersHouse";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "House";
	
	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "PortPax_CryptBig1";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Сhapel";
	
	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "Common_Crypt";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Crypt";
	n = n + 1;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// домик смотрителя
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_KeepersHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\SmallHouse_inside\";
	locations[n].models.always.SmallHouse = "SmallHouse_inside";
	//locations[n].models.always.SmallHouse.level = 65538;
	Locations[n].models.always.windows = "SmallHouse_inside_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	locations[n].models.always.windows.level = 65539;

	locations[n].models.always.back = "..\inside_back2";
	//Day
	locations[n].models.day.charactersPatch = "SmallHouse_inside_patch";
	locations[n].models.day.locators = "SmallHouse_inside_ld";
	//Night
	locations[n].models.night.charactersPatch = "SmallHouse_inside_patch";
	locations[n].models.night.locators = "SmallHouse_inside_ln";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortPax_Graveyard";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	n = n + 1;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 1
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_CryptBig1";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_2_1_inside\";
	locations[n].models.always.cryptbig = "crypt_2_1_inside";
	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "crypt_2_1_inside_patch";
	locations[n].models.day.locators = "crypt_2_1_inside_ld";
	//Night
	locations[n].models.night.charactersPatch = "crypt_2_1_inside_patch";
	locations[n].models.night.locators = "crypt_2_1_inside_ln";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortPax_Graveyard";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortPax_CryptBig2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Crypt";
	n = n + 1;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 2
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortPax_CryptBig2";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_2_2_inside\";
	locations[n].models.always.cryptbig = "crypt_2_2_inside";
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.locators = "crypt_2_2_inside_locators";
	//Day
	locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortPax_CryptBig1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Crypt";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Гонаив	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore34";
	locations[n].id.label = "Shore34";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore34";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore07";
	Locations[n].models.always.shore07 = "shore07";
	locations[n].models.always.shore07.sea_reflection = 1;
	Locations[n].models.always.shore07seabed = "shore07_sb";
	Locations[n].models.always.locators = "shore07_locators";
		
	Locations[n].models.always.grassPatch = "shore07_grass";
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
	locations[n].models.day.charactersPatch = "shore07_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore07_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_06";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс Звезды	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore99";
	locations[n].id.label = "Shore99";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore99";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore07";
	Locations[n].models.always.shore07 = "shore07";
	locations[n].models.always.shore07.sea_reflection = 1;
	Locations[n].models.always.shore07seabed = "shore07_sb";
	Locations[n].models.always.locators = "shore07_locators";
		
	Locations[n].models.always.grassPatch = "shore07_grass";
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
	locations[n].models.day.charactersPatch = "shore07_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore07_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс Дам-Мари	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore96";
	locations[n].id.label = "Shore96";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore96";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore06";
	Locations[n].models.always.shore06 = "shore06";
	locations[n].models.always.shore06.sea_reflection = 1;
	Locations[n].models.always.shore06seabed = "shore06_sb";
	Locations[n].models.always.locators = "shore06_locators";
		
	Locations[n].models.always.grassPatch = "shore06_grass";
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
	locations[n].models.day.charactersPatch = "shore06_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore06_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_08";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_Jungle_06";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle4";
	Locations[n].models.always.jungle = "jungle4";	
	Locations[n].models.always.locators = "jungle4_locators";		
	Locations[n].models.always.grassPatch = "jungle4_grass";
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
	locations[n].models.day.charactersPatch = "jungle4_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle4_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortPax_ExitTown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore34";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore34";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Hispaniola_Jungle_05";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс абаку
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore97";
	locations[n].id.label = "Shore97";
	locations[n].worldmap = "Shore97";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].questflower = 1;
	//Sound
	locations[n].type = "seashore";
 	locations[n].islandId = "Hispaniola";
	locations[n].DisableEncounters = true;
	locations[n].VaterSkelLand = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore04";
	Locations[n].models.always.shore04 = "shore04";
	locations[n].models.always.shore04.sea_reflection = 1;
	Locations[n].models.always.shore04seabed = "shore04_sb";
	Locations[n].models.always.locators = "shore04_locators";
		
	Locations[n].models.always.grassPatch = "shore04_grass";
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
	locations[n].models.day.charactersPatch = "shore04_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore04_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Abaku_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 1;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Abaku_Dungeon";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Dungeon";
    locations[n].locators_radius.reload.reload2_back = 1.5;

	locations[n].reload.l3.name = "boat";
	locations[n].reload.l3.go = "Hispaniola2";
	locations[n].reload.l3.emerge = "reload_6";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Sea";
	locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Abaku_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].DisableEncounters = true;
	locations[n].ZombieLand = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle4";
	Locations[n].models.always.jungle = "jungle4";	
	Locations[n].models.always.locators = "jungle4_locators";		
	Locations[n].models.always.grassPatch = "jungle4_grass";
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
	locations[n].models.day.charactersPatch = "jungle4_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle4_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore97";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore97";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Abaku_Ruins";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "AbakuRuins";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Abaku_jungle_02";
	locations[n].reload.l3.emerge = "reload2_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Abaku_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].ZombieLand = true;
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Abaku_jungle_01";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_11";
	locations[n].reload.l2.emerge = "reload3_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload3_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Abaku_jungle_03";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Abaku_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].ZombieLand = true;
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Hispaniola_CaveEntrance_2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_08";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Abaku_jungle_02";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Руины в джунглях	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Abaku_Ruins";
	locations[n].id.label = "AbakuRuins";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
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
	locations[n].reload.l1.go = "Abaku_jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Abaku_Ruins_Cave";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "AbakuRuinsCave";
	locations[n].locators_radius.reload.reload2 = 1.3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Шахта 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Abaku_Ruins_Cave";
	Locations[n].id.label = "AbakuRuinsCave";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Hispaniola";
	locations[n].ZombieLand = true;
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Hispaniola";
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
	locations[n].reload.l1.go = "Abaku_Ruins";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "AbakuRuins";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////мыс Беама	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore98";
	locations[n].id.label = "Shore98";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore98";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].deadlocked = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\GothicFort2";
	Locations[n].models.always.GothicFort2 = "GothicFort2";
	locations[n].models.always.GothicFort2.sea_reflection = 1;	
	//locations[n].models.always.GothicFort2.level = 65538;
	Locations[n].models.always.GothicFort2rock = "GothicFort2_terra";
	Locations[n].models.always.GothicFort2seabed = "GothicFort2_sb";
	Locations[n].models.always.locators = "GothicFort2_locators";
	//Locations[n].models.always.locators = "GothicFort2_locators_add";
	Locations[n].models.always.grassPatch = "GothicFort2_grass";
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

	Locations[n].models.always.l5 = "GothicFort2_trees";
	Locations[n].models.always.l5.tech = "DLightModel";

	//костёр
	locations[n].models.always.Bfire = "Bfire1";
	Locations[n].models.always.Bfire.locator.group = "Upgrades";
	Locations[n].models.always.Bfire.locator.name = "Bfire";
	Locations[n].models.always.Bfire.tech = "DLightModel";

	//Day
	locations[n].models.day.charactersPatch = "GothicFort2_path";
	//locations[n].models.day.charactersPatch = "GothicFort2_path2";
	Locations[n].models.day.fonar = "GothicFort2_fd";	
	//Night
	locations[n].models.night.charactersPatch = "GothicFort2_path";
	//locations[n].models.night.charactersPatch = "GothicFort2_path2";
	Locations[n].models.night.fonar= "GothicFort2_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
                        //Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_10";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "Shore98";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Xsardasfort";

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Xsardas_Dungeon";
	locations[n].reload.l4.emerge = "reload1_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Xsardasfort";

	locations[n].reload.l5.name = "reload3";
	locations[n].reload.l5.go = "Shore98";
	locations[n].reload.l5.emerge = "reload2";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shore98";


	locations[n].private1.items.gold = 3000;
	locations[n].private1.items.mineral30 = 1;
	locations[n].private1.items.gold_dublon = 25;
	locations[n].private1.items.pistol1 = 1;
	locations[n].private1.items.indian_1 = 1;
	locations[n].private1.items.bullet = 10;
	locations[n].private2.items.grapeshot = 14;
	locations[n].private2.items.spyglass1 = 1;
	locations[n].private2.items.slave_01 = 1;
	locations[n].private3.items.grapeshot = 14;
	locations[n].private3.items.potion1 = 1;
	locations[n].private3.items.cartridge = 7;
	locations[n].private4.items.potion2 = 1;
	locations[n].private4.items.GunPowder = 47;
	locations[n].private1.items.indian_2 = 1;
	locations[n].private5.items.potion1 = 1;
	locations[n].private5.items.GunPowder = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_Jungle_10";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].DisableEncounters = true;
	locations[n].fennisgrass = 1;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungles\Jungle14";
	Locations[n].models.always.locators = "Jungle14_locators";
	Locations[n].models.always.jungle = "Jungle14";
	Locations[n].models.always.grassPatch = "JUNGLE14_grass";
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
	Locations[n].models.day.charactersPatch = "Jungle14_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle14_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore98";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore98";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_11";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Xsardas_fort";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                   locations[n].id = "Hispaniola_Jungle_11";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].DisableEncounters = true;
	locations[n].fennisgrass = 1;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungles\Jungle15";
	Locations[n].models.always.locators = "jungle15_locators";
	Locations[n].models.always.jungle = "Jungle15";
	Locations[n].models.always.grassPatch = "jungle15_grass";
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
	Locations[n].models.day.charactersPatch = "jungle15_patch";
	//Night
	Locations[n].models.night.charactersPatch = "jungle15_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_10";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Hispaniola_jungleHouse";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Abaku_jungle_02";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// домик в джунглях	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_jungleHouse";
	locations[n].id.label = "jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].ZombieLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\ArchyHouse";
                   Locations[n].models.always.house = "RHouse";
                   Locations[n].models.always.grassPatch = "rhouse_g";
                   Locations[n].models.always.l1 = "rhouse_b01";
                   Locations[n].models.always.l1.level = 9;
                   Locations[n].models.always.l1.tech = "LocationModelBlend";
                   Locations[n].models.always.l2 = "rhouse_b02";
                   Locations[n].models.always.l2.level = 8;
                   Locations[n].models.always.l2.tech = "LocationModelBlend";
                   Locations[n].models.always.l3 = "rhouse_b03";
                   Locations[n].models.always.l3.level = 7;
                   Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "rhouse_b04";
                   Locations[n].models.always.l3.level = 7;
                   Locations[n].models.always.l4.tech = "LocationModelBlend";
	Locations[n].models.always.locators = "rhouse_l";
	
	Locations[n].models.always.grassPatch = "rhouse_g";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
                   //Day
                   Locations[n].models.day.charactersPatch = "rhouse_p";
                  //Night
                   Locations[n].models.night.charactersPatch = "rhouse_p";
                   //Environment
                   Locations[n].environment.weather = "true";
                   Locations[n].environment.sea = "false";	
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Hispaniola_House";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	locations[n].locators_radius.reload.reload2 = 1.3;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Hispaniola_Jungle_11";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Hispaniola_House";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "House";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut5";
	locations[n].models.always.locators = "Hut5_locators";
	locations[n].models.always.tavern = "Hut5";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut5_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut5_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut5_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_jungleHouse";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "jungle";
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// башня Ксардаса	////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Xsardas_fort";
	locations[n].id.label = "XsardasFort";
	Locations[n].image = "loading\Xsardas_fort.tga";
	locations[n].townsack = "Jungle";
	//Sound
	locations[n].type = "Xsardas";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Fort_inside\FortV";
	Locations[n].models.always.fortV = "fortV";	
	locations[n].models.always.fortV.level = 65538;
	Locations[n].models.always.fortVrock = "fortV_rock";
	Locations[n].models.always.fortVseabed = "fortV_sb";
	Locations[n].models.always.locators = "fortV_locators";
	Locations[n].models.always.grassPatch = "fortV_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.tech = "LocationModelBlend";	
	locations[n].models.always.l1.level = 9;
	//Day
	locations[n].models.day.charactersPatch = "fortV_patch";
	Locations[n].models.day.fortVFonarsDay = "fortV_fd";
	//Night
	locations[n].models.night.charactersPatch = "fortV_patch";
	Locations[n].models.night.fortVBigNight= "fortV_fn";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
                        //Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola_Jungle_10";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Xsardas_Dungeon";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// логово Ксардоса	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Xsardas_Dungeon";
	locations[n].id.label = "Dungeon_Xsardas";
	locations[n].image = "loading\inside\Dungeon_Xsardas.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Xsardas";
	locations[n].islandId = "Hispaniola";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].fennisgrass = 1;
	locations[n].locators_radius.item.item6 = 1.3;
	locations[n].locators_radius.item.item7 = 0.8;
	locations[n].locators_radius.item.bottle = 1.1;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Animists_cave\";
	locations[n].models.always.CryptDungeon = "Animists_cave";
	locations[n].models.always.locators = "Animists_cave_locators";
	locations[n].models.always.CryptDungeon.sea_reflection = 1;
	//Day
	locations[n].models.day.charactersPatch = "Animists_cave_patch";
	//Night
	locations[n].models.night.charactersPatch = "Animists_cave_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Xsardas_fort";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Порт Ле-Ке
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "LeKe_town";
	locations[n].id.label = "Street";
	locations[n].image = "loading\towns\pearl5.tga";
	locations[n].worldmap = "LeKe_town";
	//Town sack
	locations[n].townsack = "LeKe";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_LeKe";
	Locations[n].models.always.l1.foam = "1";
	locations[n].models.always.town = "LeKe";
	locations[n].models.always.port.sea_reflection = 1;
	locations[n].models.always.seabed = "LeKe_sb";
	Locations[n].models.always.locators = "LeKe_locators";

	locations[n].models.always.l2 = "flagpole";
	locations[n].models.always.l3 = "flagpole2";
	locations[n].models.always.l4 = "short_ladder";
	
	//Day
	locations[n].models.day.fonar = "LeKe_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
	//Locations[n].models.day.locators = "LeKe_locators_day";
	//Night
	locations[n].models.night.fonar = "LeKe_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";
	//Locations[n].models.night.locators = "LeKe_locators_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].models.always.l5 = "chimney_45";
	Locations[n].models.always.l5.locator.group = "randitem";
	Locations[n].models.always.l5.locator.name = "randitem1";
	Locations[n].models.always.l5.tech = "DLightModel";

	locations[n].models.always.l6 = "chimney_45";
	Locations[n].models.always.l6.locator.group = "randitem";
	Locations[n].models.always.l6.locator.name = "randitem2";
	Locations[n].models.always.l6.tech = "DLightModel";

	locations[n].models.always.l7 = "chimney_45";
	Locations[n].models.always.l7.locator.group = "randitem";
	Locations[n].models.always.l7.locator.name = "randitem3";
	Locations[n].models.always.l7.tech = "DLightModel";

	locations[n].models.always.l8 = "chimney_45";
	Locations[n].models.always.l8.locator.group = "randitem";
	Locations[n].models.always.l8.locator.name = "randitem4";
	Locations[n].models.always.l8.tech = "DLightModel";

	locations[n].models.always.l9 = "chimney_45";
	Locations[n].models.always.l9.locator.group = "randitem";
	Locations[n].models.always.l9.locator.name = "randitem5";
	Locations[n].models.always.l9.tech = "DLightModel";

	locations[n].models.always.l10 = "chimney_45";
	Locations[n].models.always.l10.locator.group = "randitem";
	Locations[n].models.always.l10.locator.name = "randitem6";
	Locations[n].models.always.l10.tech = "DLightModel";

	locations[n].models.always.l11 = "chimney_45";
	Locations[n].models.always.l11.locator.group = "randitem";
	Locations[n].models.always.l11.locator.name = "randitem7";
	Locations[n].models.always.l11.tech = "DLightModel";

	locations[n].models.always.l12 = "chimney_45";
	Locations[n].models.always.l12.locator.group = "randitem";
	Locations[n].models.always.l12.locator.name = "randitem8";
	Locations[n].models.always.l12.tech = "DLightModel";

	locations[n].models.always.l13 = "chimney_pot";
	Locations[n].models.always.l13.locator.group = "randitem";
	Locations[n].models.always.l13.locator.name = "randitem9";
	Locations[n].models.always.l13.tech = "DLightModel";

	locations[n].models.always.l14 = "chimney_pot";
	Locations[n].models.always.l14.locator.group = "randitem";
	Locations[n].models.always.l14.locator.name = "randitem10";
	Locations[n].models.always.l14.tech = "DLightModel";

	locations[n].models.always.l15 = "chimney_pot";
	Locations[n].models.always.l15.locator.group = "randitem";
	Locations[n].models.always.l15.locator.name = "randitem11";
	Locations[n].models.always.l15.tech = "DLightModel";

	locations[n].models.always.l16 = "chimney_pot";
	Locations[n].models.always.l16.locator.group = "randitem";
	Locations[n].models.always.l16.locator.name = "randitem12";
	Locations[n].models.always.l16.tech = "DLightModel";

	locations[n].models.always.l17 = "chimney_pot";
	Locations[n].models.always.l17.locator.group = "randitem";
	Locations[n].models.always.l17.locator.name = "randitem15";
	Locations[n].models.always.l17.tech = "DLightModel";

	locations[n].models.always.l18 = "chimney_pot";
	Locations[n].models.always.l18.locator.group = "randitem";
	Locations[n].models.always.l18.locator.name = "randitem16";
	Locations[n].models.always.l18.tech = "DLightModel";

	locations[n].models.always.l19 = "chimney_pot";
	Locations[n].models.always.l19.locator.group = "randitem";
	Locations[n].models.always.l19.locator.name = "randitem17";
	Locations[n].models.always.l19.tech = "DLightModel";

	locations[n].models.always.l20 = "chimney_pot";
	Locations[n].models.always.l20.locator.group = "randitem";
	Locations[n].models.always.l20.locator.name = "randitem18";
	Locations[n].models.always.l20.tech = "DLightModel";

	locations[n].models.always.l21 = "chimney_45_night";
	Locations[n].models.always.l21.locator.group = "randitem";
	Locations[n].models.always.l21.locator.name = "randitem101";
	Locations[n].models.always.l21.tech = "DLightModel";

	locations[n].models.always.l22 = "chimney_45_night";
	Locations[n].models.always.l22.locator.group = "randitem";
	Locations[n].models.always.l22.locator.name = "randitem102";
	Locations[n].models.always.l22.tech = "DLightModel";

	locations[n].models.always.l23 = "chimney_45_night";
	Locations[n].models.always.l23.locator.group = "randitem";
	Locations[n].models.always.l23.locator.name = "randitem103";
	Locations[n].models.always.l23.tech = "DLightModel";

	locations[n].models.always.l24 = "chimney_45_night";
	Locations[n].models.always.l24.locator.group = "randitem";
	Locations[n].models.always.l24.locator.name = "randitem104";
	Locations[n].models.always.l24.tech = "DLightModel";

	locations[n].models.always.l25 = "chimney_45_night";
	Locations[n].models.always.l25.locator.group = "randitem";
	Locations[n].models.always.l25.locator.name = "randitem105";
	Locations[n].models.always.l25.tech = "DLightModel";

	locations[n].models.always.l26 = "chimney_45_night";
	Locations[n].models.always.l26.locator.group = "randitem";
	Locations[n].models.always.l26.locator.name = "randitem106";
	Locations[n].models.always.l26.tech = "DLightModel";

	locations[n].models.always.l27 = "chimney_45_night";
	Locations[n].models.always.l27.locator.group = "randitem";
	Locations[n].models.always.l27.locator.name = "randitem107";
	Locations[n].models.always.l27.tech = "DLightModel";

	locations[n].models.always.l28 = "chimney_45_night";
	Locations[n].models.always.l28.locator.group = "randitem";
	Locations[n].models.always.l28.locator.name = "randitem108";
	Locations[n].models.always.l28.tech = "DLightModel";

	locations[n].models.always.l29 = "chimney_pot_night";
	Locations[n].models.always.l29.locator.group = "randitem";
	Locations[n].models.always.l29.locator.name = "randitem109";
	Locations[n].models.always.l29.tech = "DLightModel";

	locations[n].models.always.l30 = "chimney_pot_night";
	Locations[n].models.always.l30.locator.group = "randitem";
	Locations[n].models.always.l30.locator.name = "randitem110";
	Locations[n].models.always.l30.tech = "DLightModel";

	locations[n].models.always.l31 = "chimney_pot_night";
	Locations[n].models.always.l31.locator.group = "randitem";
	Locations[n].models.always.l31.locator.name = "randitem111";
	Locations[n].models.always.l31.tech = "DLightModel";

	locations[n].models.always.l32 = "chimney_pot_night";
	Locations[n].models.always.l32.locator.group = "randitem";
	Locations[n].models.always.l32.locator.name = "randitem112";
	Locations[n].models.always.l32.tech = "DLightModel";

	locations[n].models.always.l33 = "chimney_45_night";
	Locations[n].models.always.l33.locator.group = "randitem";
	Locations[n].models.always.l33.locator.name = "randitem113";
	Locations[n].models.always.l33.tech = "DLightModel";

	locations[n].models.always.l34 = "chimney_45_night";
	Locations[n].models.always.l34.locator.group = "randitem";
	Locations[n].models.always.l34.locator.name = "randitem114";
	Locations[n].models.always.l34.tech = "DLightModel";

	locations[n].models.always.l35 = "chimney_pot_night";
	Locations[n].models.always.l35.locator.group = "randitem";
	Locations[n].models.always.l35.locator.name = "randitem115";
	Locations[n].models.always.l35.tech = "DLightModel";

	locations[n].models.always.l36 = "chimney_pot_night";
	Locations[n].models.always.l36.locator.group = "randitem";
	Locations[n].models.always.l36.locator.name = "rnditem116";
	Locations[n].models.always.l36.tech = "DLightModel";

	locations[n].models.always.l37 = "ship_building";
	Locations[n].models.always.l37.locator.group = "randitem";
	Locations[n].models.always.l37.locator.name = "randitem85";
	Locations[n].models.always.l37.tech = "DLightModel";

	locations[n].models.always.l38 = "cannon1";
	Locations[n].models.always.l38.locator.group = "randitem";
	Locations[n].models.always.l38.locator.name = "randitem36";
	Locations[n].models.always.l38.tech = "DLightModel";

	locations[n].models.always.l39 = "cannon1";
	Locations[n].models.always.l39.locator.group = "randitem";
	Locations[n].models.always.l39.locator.name = "randitem37";
	Locations[n].models.always.l39.tech = "DLightModel";

	locations[n].models.always.l40 = "cannon1";
	Locations[n].models.always.l40.locator.group = "randitem";
	Locations[n].models.always.l40.locator.name = "randitem43";
	Locations[n].models.always.l40.tech = "DLightModel";

	locations[n].models.always.l41 = "cannon1";
	Locations[n].models.always.l41.locator.group = "randitem";
	Locations[n].models.always.l41.locator.name = "randitem44";
	Locations[n].models.always.l41.tech = "DLightModel";

	locations[n].models.always.l42 = "anvil";
	Locations[n].models.always.l42.locator.group = "randitem";
	Locations[n].models.always.l42.locator.name = "randitem57";
	Locations[n].models.always.l42.tech = "DLightModel";
	Locations[n].locators_radius.randitem.randitem42 = 0.01;

	locations[n].models.always.l43 = "anchor_item";
	Locations[n].models.always.l43.locator.group = "randitem";
	Locations[n].models.always.l43.locator.name = "randitem97";
	Locations[n].models.always.l43.tech = "DLightModel";

	locations[n].models.always.l44 = "boat2_C";
	Locations[n].models.always.l44.locator.group = "randitem";
	Locations[n].models.always.l44.locator.name = "randitem86";
	Locations[n].models.always.l44.tech = "DLightModel";

	locations[n].models.always.l45 = "well";
	Locations[n].models.always.l45.locator.group = "randitem";
	Locations[n].models.always.l45.locator.name = "randitem87";
	Locations[n].models.always.l45.tech = "DLightModel";

	locations[n].models.always.l46 = "wagon";
	Locations[n].models.always.l46.locator.group = "randitem";
	Locations[n].models.always.l46.locator.name = "randitem88";
	Locations[n].models.always.l46.tech = "DLightModel";

	locations[n].models.always.l47 = "anchor_big";
	Locations[n].models.always.l47.locator.group = "randitem";
	Locations[n].models.always.l47.locator.name = "randitem89";
	Locations[n].models.always.l47.tech = "DLightModel";

	locations[n].models.always.l48 = "shipwreck";
	Locations[n].models.always.l48.locator.group = "randitem";
	Locations[n].models.always.l48.locator.name = "randitem90";
	Locations[n].models.always.l48.tech = "DLightModel";

	locations[n].models.always.l49 = "boat2_C";
	Locations[n].models.always.l49.locator.group = "randitem";
	Locations[n].models.always.l49.locator.name = "randitem94";
	Locations[n].models.always.l49.tech = "DLightModel";

	locations[n].models.always.l50 = "boat2_B";
	Locations[n].models.always.l50.locator.group = "randitem";
	Locations[n].models.always.l50.locator.name = "randitem95";
	Locations[n].models.always.l50.tech = "DLightModel";

	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Hispaniola2";
	locations[n].reload.l1.emerge = "reload_8";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Hispaniola2";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "LeKe_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload_jail";
	locations[n].reload.l4.go = "LeKe_tavern";
	locations[n].reload.l4.emerge = "reload1_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "LeKe_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l51.name = "reload51_back";
	locations[n].reload.l51.go = "LeKe_shipyard";
	locations[n].reload.l51.emerge = "reload2";
	locations[n].reload.l51.autoreload = "0";
	locations[n].reload.l51.label = "Shipyard";
	locations[n].reload.l51.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "LeKe_PortOffice";
	locations[n].reload.l6.emerge = "reload1_back";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "PortOffice";
	locations[n].reload.l6.close_for_night = 1;
	
	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "LeKe_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "LeKe_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "LeKe_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

 	locations[n].reload.l91.name = "reload13";
	locations[n].reload.l91.go = "LeKe_SecBrRoom";
	locations[n].reload.l91.emerge = "reload2";
	locations[n].reload.l91.autoreload = "0";
	locations[n].reload.l91.label = "Brothel";

	Locations[n].reload.l10.name = "reload10_back";
	Locations[n].reload.l10.go = "LeKe_store";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "store";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.jail.name = "gate_back";
	locations[n].reload.jail.go = "LeKe_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

	locations[n].reload.angar.name = "reload_angar";
	locations[n].reload.angar.go = "LeKe_angar";
	locations[n].reload.angar.emerge = "reload1_back";
	locations[n].reload.angar.autoreload = "0";
	locations[n].reload.angar.label = "packhouse";

	Locations[n].reload.l11.name = "houseS5";
	Locations[n].reload.l11.go = "CommonResidence_5";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Room";

     // --> Комоны, загрушки. Номера с начинаются с 12.

	locations[n].reload.l12.name = "houseH1";
	locations[n].reload.l12.go = "CommonPirateHouse";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";

	locations[n].reload.l13.name = "houseH2";
	locations[n].reload.l13.go = "CommonRoom_MH5";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "Room";

	Locations[n].reload.l14.name = "houseH3";
	Locations[n].reload.l14.go = "CommonRoom_MH3";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "House";

	Locations[n].reload.l15.name = "houseH4";
	Locations[n].reload.l15.go = "CommonPirateHouse";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "House";

	Locations[n].reload.l16.name = "houseF2";
	Locations[n].reload.l16.go = "CommonStoneHouse";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "House";

	Locations[n].reload.l17.name = "houseF3";
	Locations[n].reload.l17.go = "CommonRoom_MH2";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "House";

	Locations[n].reload.l18.name = "houseF4";
	Locations[n].reload.l18.go = "CommonCobHouse";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "House";

	Locations[n].reload.l19.name = "houseF5";
	Locations[n].reload.l19.go = "CommonDoubleflourHouse_1";
	Locations[n].reload.l19.emerge = "reload1";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "House";

	Locations[n].reload.l20.name = "houseS2";
	Locations[n].reload.l20.go = "CommonFlamHouse";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "House";

	Locations[n].reload.l21.name = "houseSp2";
	Locations[n].reload.l21.go = "CommonHut";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "House";

	Locations[n].reload.l22.name = "houseSp3";
	Locations[n].reload.l22.go = "CommonRoom_MH10";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "House";

	Locations[n].reload.l23.name = "houseS1";
	Locations[n].reload.l23.go = "CommonRoom_MH2";
	Locations[n].reload.l23.emerge = "reload1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "basement1";
	locations[n].reload.l24.go = "Abaku_Dungeon";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "Dungeon";

	Locations[n].reload.l25.name = "houseS3";
	Locations[n].reload.l25.go = "CommonStoneHouse";
	Locations[n].reload.l25.emerge = "reload1";
	Locations[n].reload.l25.autoreload = "0";
	Locations[n].reload.l25.label = "House";

	Locations[n].reload.l26.name = "houseF1";
	Locations[n].reload.l26.go = "CommonResidence_5";
	Locations[n].reload.l26.emerge = "reload1";
	Locations[n].reload.l26.autoreload = "0";
	Locations[n].reload.l26.label = "House";

	Locations[n].reload.l27.name = "houseS6";
	Locations[n].reload.l27.go = "CommonResidence_1";
	Locations[n].reload.l27.emerge = "reload1";
	Locations[n].reload.l27.autoreload = "0";
	Locations[n].reload.l27.label = "House";

	Locations[n].reload.l28.name = "houseF6";
	Locations[n].reload.l28.go = "CommonHut";
	Locations[n].reload.l28.emerge = "reload1";
	Locations[n].reload.l28.autoreload = "0";
	Locations[n].reload.l28.label = "House";

	Locations[n].reload.l29.name = "houseF7";
	Locations[n].reload.l29.go = "CommonRoom_MH";
	Locations[n].reload.l29.emerge = "reload1";
	Locations[n].reload.l29.autoreload = "0";
	Locations[n].reload.l29.label = "House";

	Locations[n].reload.l30.name = "reload4_back";
	Locations[n].reload.l30.go = "CommonFlamHouse";
	Locations[n].reload.l30.emerge = "reload1";
	Locations[n].reload.l30.autoreload = "0";
	Locations[n].reload.l30.label = "House";

	Locations[n].reload.l31.name = "houseH7";
	Locations[n].reload.l31.go = "CommonRoom_MH2";
	Locations[n].reload.l31.emerge = "reload1";
	Locations[n].reload.l31.autoreload = "0";
	Locations[n].reload.l31.label = "House";

	Locations[n].reload.l32.name = "houseH6";
	Locations[n].reload.l32.go = "CommonPirateresidence";
	Locations[n].reload.l32.emerge = "reload1";
	Locations[n].reload.l32.autoreload = "0";
	Locations[n].reload.l32.label = "House";

	Locations[n].reload.l33.name = "reload71_back";
	Locations[n].reload.l33.go = "CommonRoom_MH";
	Locations[n].reload.l33.emerge = "reload1";
	Locations[n].reload.l33.autoreload = "0";
	Locations[n].reload.l33.label = "Townhall";

	Locations[n].reload.l34.name = "houseF10";
	Locations[n].reload.l34.go = "CommonDoubleflourRoom";
	Locations[n].reload.l34.emerge = "reload1";
	Locations[n].reload.l34.autoreload = "0";
	Locations[n].reload.l34.label = "Room";

	Locations[n].reload.l35.name = "houseF12";
	Locations[n].reload.l35.go = "CommonStoneHouse";
	Locations[n].reload.l35.emerge = "reload1";
	Locations[n].reload.l35.autoreload = "0";
	Locations[n].reload.l35.label = "House";

	Locations[n].reload.l36.name = "houseS4";
	Locations[n].reload.l36.go = "CommonRoom_MH";
	Locations[n].reload.l36.emerge = "reload1";
	Locations[n].reload.l36.autoreload = "0";
	Locations[n].reload.l36.label = "Room";

	Locations[n].reload.l37.name = "houseF11";
	Locations[n].reload.l37.go = "CommonDoubleflourHouse_1";
	Locations[n].reload.l37.emerge = "reload1";
	Locations[n].reload.l37.autoreload = "0";
	Locations[n].reload.l37.label = "House";

	Locations[n].reload.l38.name = "houseF8";
	Locations[n].reload.l38.go = "CommonFlamHouse";
	Locations[n].reload.l38.emerge = "reload1";
	Locations[n].reload.l38.autoreload = "0";
	Locations[n].reload.l38.label = "House";

	Locations[n].reload.l39.name = "houseF9";
	Locations[n].reload.l39.go = "CommonCobHouse";
	Locations[n].reload.l39.emerge = "reload1";
	Locations[n].reload.l39.autoreload = "0";
	Locations[n].reload.l39.label = "House";

	Locations[n].reload.l40.name = "reload12";
	Locations[n].reload.l40.go = "CommonResidence_BackHall";
	Locations[n].reload.l40.emerge = "reload1";
	Locations[n].reload.l40.autoreload = "0";
	Locations[n].reload.l40.label = "Townhall";

	Locations[n].reload.l41.name = "houseF13";
	Locations[n].reload.l41.go = "CommonResidence_2";
	Locations[n].reload.l41.emerge = "reload1";
	Locations[n].reload.l41.autoreload = "0";
	Locations[n].reload.l41.label = "Townhall";

	Locations[n].reload.l42.name = "houseSp1";
	Locations[n].reload.l42.go = "CommonRoom_MH5";
	Locations[n].reload.l42.emerge = "reload1";
	Locations[n].reload.l42.autoreload = "0";
	Locations[n].reload.l42.label = "House";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	locations[n].soldiers = true;
	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "LeKe";
 	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence06";
	locations[n].models.always.locators = "Residence06_locators";
	locations[n].models.always.l1 = "Residence06";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence06_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence06_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence06_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeKe_town";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_tavern";
	locations[n].id.label = "Tavern39";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\tavern08\";
	locations[n].models.always.tavern = "tavern08";
	Locations[n].models.always.tavern.tech = "DLightModel";		
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern08_locators";
	Locations[n].models.always.locators.tech = "DLightModel";	
	locations[n].models.always.window = "tavern08_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "tavern08_patch";
	//Night
	Locations[n].models.night.fonar = "tavern08_fn";
	locations[n].models.night.charactersPatch = "tavern08_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "LeKe_town";
	locations[n].reload.l1.emerge = "reload_jail"; 
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "LeKe_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Комната в таверне наверху	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
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
	locations[n].reload.l1.go = "LeKe_tavern";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern1";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Магазин
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeKe_store";
	locations[n].id.label = "Store";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Store07\";
	locations[n].models.always.locators = "Store07_locators";
	locations[n].models.always.store = "Store07";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store07_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store07_patch";
	Locations[n].models.day.fonar = "Store07_fd";
	//Night
	locations[n].models.night.charactersPatch = "Store07_patch";
	Locations[n].models.night.fonar = "Store07_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeKe_town";
	Locations[n].reload.l1.emerge = "reload10_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "CommonPackhouse_1";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Packhouse";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_bank";
	locations[n].id.label = "Usurer House";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Bank02\";
	locations[n].models.always.locators = "Bank02_locators";
	locations[n].models.always.store = "Bank02";
	locations[n].models.always.window = "Bank02_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "Bank02_patch";
	//Night
	locations[n].models.night.charactersPatch = "Bank02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "LeKe_town";
	locations[n].reload.l1.emerge = "reload8_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Верфь
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeKe_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeKe";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\shipyard";
	Locations[n].models.always.locators = "Shipyard_locators";
	Locations[n].models.always.shipyard = "Shipyard";
	Locations[n].models.always.window = "Shipyard_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Shipyard_patch";
	Locations[n].models.day.fd = "Shipyard_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Shipyard_patch";
	Locations[n].models.night.fn = "Shipyard_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeKe_town";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "LeKe_town";
	locations[n].reload.l2.emerge = "reload51_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church_1.tga";
	//Town sack
	locations[n].townsack = "Jungle";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchInside3";
	locations[n].models.always.churchInside3 = "churchInside3";
	locations[n].models.always.churchInside3.level = 65538;	
	locations[n].models.always.locators = "churchInside3_locators";
	
	Locations[n].models.always.churchInside3windows = "churchInside3_windows";
	Locations[n].models.always.churchInside3windows.tech = "LocationWindows";
	locations[n].models.always.churchInside3windows.level = 65539;	
	
	locations[n].models.always.backgroundInsides = "backgroundInsides";
	locations[n].models.always.backgroundInsides.level = 65529;	
	//Day
	locations[n].models.day.charactersPatch = "churchInside3_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInside3_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeKe_town";
	locations[n].reload.l1.emerge = "reload7_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Портовое управление
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeKe_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Shipyard04\";
	locations[n].models.always.locators = "Shipyard04_locators";
	locations[n].models.always.shipyard = "Shipyard04";
	locations[n].models.always.shipyard.level = 65538;
	locations[n].models.always.window = "shipyard04_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Shipyard04_patch";
	//Night
	locations[n].models.night.charactersPatch = "Shipyard04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeKe_town";
	Locations[n].reload.l1.emerge = "reload6_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "LeKe_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeKe";
 	locations[n].islandId = "Hispaniola";
	locations[n].brothel = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "brothel_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "Brothel_patch";
	//Night
	locations[n].models.night.charactersPatch = "Brothel_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeKe_Town";
	Locations[n].reload.l1.emerge = "reload9_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "LeKe_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "LeKe_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].models.always.locators = "Brothel_room_locators";
	locations[n].models.always.store = "Brothel_room";
	locations[n].models.always.window = "Brothel_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "Brothel_room_patch";
	//Night
	locations[n].models.night.charactersPatch = "Brothel_room_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "LeKe_Brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	locations[n].brothel = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouse03\";
	locations[n].models.always.house = "BigHouse03";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouse03_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouse03_patch";
	locations[n].models.day.locators = "BigHouse03_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse03_patch";
	locations[n].models.night.locators = "BigHouse03_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeKe_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "LeKe_town";
	locations[n].reload.l2.emerge = "reload13";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	////////////////////// prison ////////////////////////////
	Locations[n].id = "LeKe_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "LeKe";
     locations[n].parent_colony = "LeKe";
 	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
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
	Locations[n].reload.l1.go = "LeKe_town";
	Locations[n].reload.l1.emerge = "gate_back";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье Ле-Ке
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Abaku_Dungeon";
	locations[n].id.label = "AbakuDungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeKe";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonVault1";
	locations[n].models.always.DungeonVault1 = "DungeonVault1";
	locations[n].models.always.InquisitionDungeonVault1Fonars = "DungeonVault1_fonars";
	locations[n].models.always.locators = "DungeonVault1_locators";	

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "DungeonVault1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault1_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeKe_town";
	locations[n].reload.l1.emerge = "basement1";
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore97";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore97";
	locations[n].locators_radius.reload.reload2_back = 1.5;
	n = n + 1;
	////////////////////// angar ////////////////////////////
	Locations[n].id = "LeKe_angar";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	locations[n].townsack = "LeKe";
                    locations[n].parent_colony = "LeKe";
 	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Angar";
	locations[n].models.always.angar = "angar";
	locations[n].models.always.locators = "angar_locators";

	//locations[n].models.always.throne = "throne";
	//Locations[n].models.always.throne.locator.group = "Upgrades";
	//Locations[n].models.always.throne.locator.name = "throne";
	
	//Day
	locations[n].models.day.charactersPatch = "angar_patch";
	//Night
	locations[n].models.night.charactersPatch = "angar_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
                 //Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeKe_town";
	Locations[n].reload.l1.emerge = "reload_angar";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "street";	

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "LeKe_packhouse_228";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "packhouse";	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// подсобка СКЛАДА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeKe_packhouse_228";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	locations[n].id.label = "packhouse";
	locations[n].MustSetReloadBack = true;
	Locations[n].townsack = "LeKe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeKe";
	locations[n].islandId = "Hispaniola";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeKe_angar";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "packhouse";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;
	return n;
}

