
int LocationInitMaracaibo(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Maracaibo";
	
	locations[n].townsack = "Maracaibo";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
	
	locations[n].filespath.models = "locations\Town_Maracaibo\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 4; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "Maracaibo";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Maracaibo_signsA";
	Locations[n].models.always.seabed = "Maracaibo_sb";
	locations[n].models.always.locators = "Maracaibo_locators";
	locations[n].models.always.grassPatch = "Maracaibo_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;
		
	//Fontain
	Locations[n].models.always.Waterfall1 = "fontain1";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.5;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;
	
	Locations[n].models.always.Waterfall2 = "fontain2";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.2;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 49;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.26;
	
	locations[n].models.always.L2 = "Barracks_Door3";
    locations[n].models.always.L2.tech = "DLightModel";

	//Day
	locations[n].models.day.fonar = "Maracaibo_fd";
	locations[n].models.day.charactersPatch = "Maracaibo_patch_day";
	locations[n].models.day.rinok = "Maracaibo_rinok";
	//Night
	locations[n].models.night.fonar = "Maracaibo_fn";
	locations[n].models.night.charactersPatch = "Maracaibo_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Maracaibo_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	Locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Maracaibo_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Maracaibo_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	Locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Maracaibo_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	Locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Maracaibo_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//Locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Maracaibo_Bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	Locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "Maracaibo_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "Maracaibo_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "Maracaibo_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseSp3";
	locations[n].reload.l20.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

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
	locations[n].reload.l27.go = "CommonRoom_MH3";
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
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_tavern";
	locations[n].id.label = "Tavern23";
	locations[n].filespath.models = "locations\inside\tavern01\";
	locations[n].image = "loading\inside\tavern4.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].models.always.tavern = "tavern01";
	locations[n].models.always.locators = "tavern01_locators";
	locations[n].models.always.window = "tavern01_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
 	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "tavern01_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store03\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_town";
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
	locations[n].id = "Maracaibo_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_town";
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
	locations[n].id = "Maracaibo_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_town";
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
	locations[n].id = "Maracaibo_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence06";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Maracaibo_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Maracaibo_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "Maracaibo_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "Maracaibo";
    locations[n].parent_colony = "Maracaibo";
 	locations[n].fastreload = "Maracaibo";
	locations[n].islandId = "Mein";
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
	Locations[n].reload.l1.go = "Maracaibo_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;


 	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Выход в джунгли Маракайбо	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	//Sound
	locations[n].type = "exittown";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitW";
	Locations[n].models.always.townExit = "townExitW";
	Locations[n].models.always.townWalls = "townExitW_stone";
	
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
	locations[n].reload.l1.go = "Maracaibo_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Maracaibo";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_jungle_01";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Maracaibo_Plantation";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Plantation";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "Maracaibo_Fort";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "1";
	locations[n].reload.l4.label = "Maracaibo Fort";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Плантация Маракайбо	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\Plantation_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Maracaibo";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Maracaibo_ExitTown";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2;

	//дома
	locations[n].reload.l3.name = "houseSp1";
	locations[n].reload.l3.go = "Maracaibo_Plantation_Sp1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = false;
	locations[n].reload.l3.label = "house";

	locations[n].reload.l4.name = "houseS1";
	locations[n].reload.l4.go = "Maracaibo_Plantation_S1";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = false;
	locations[n].reload.l4.label = "house";

	locations[n].reload.l5.name = "houseS2";
	locations[n].reload.l5.go = "Maracaibo_Plantation_S2";
	locations[n].reload.l5.emerge = "reload2";
	locations[n].reload.l5.autoreload = false;
	locations[n].reload.l5.label = "house";

	locations[n].reload.l6.name = "houseF1";
	locations[n].reload.l6.go = "Maracaibo_Plantation_F1";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = false;
	locations[n].reload.l6.label = "house";

	locations[n].reload.l7.name = "houseF2";
	locations[n].reload.l7.go = "Maracaibo_Plantation_F2";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = false;
	locations[n].reload.l7.label = "house";

                   locations[n].locators_radius.quest.detector1 = 5.0; //homo
	locations[n].locators_radius.quest.detector3 = 5.0;
    n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////// дом управляющего
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation_Sp1";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.tavern = "StoneHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "StoneHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "StoneHouse_locators";
	locations[n].models.night.locators = "StoneHouse_Nlocators";

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
	locations[n].reload.l1.go = "Maracaibo_Plantation";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation_S1";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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

	locations[n].models.always.back = "..\inside_back2";
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
	locations[n].reload.l1.go = "Maracaibo_Plantation";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation_S2";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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

	locations[n].models.always.back = "..\inside_back2";
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
	locations[n].reload.l1.go = "Maracaibo_Plantation";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation_F1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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

	locations[n].models.always.back = "..\inside_back2";
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
	locations[n].reload.l1.go = "Maracaibo_Plantation";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Plantation_F2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Maracaibo_Plantation";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Maracaibo_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_CaveEntrance";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_ExitTown";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Вход в пещеру	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Maracaibo_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Пещера	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].id.label = "Cave";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernMedium2";
	locations[n].models.always.cavernMedium2 = "cavernMedium2";
	locations[n].models.always.lamps = "cavernMedium2_lamps";	
	locations[n].models.always.locators = "cavernMedium2_locators";	

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "cavernMedium2_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03	
*/	
	//Day
	locations[n].models.day.charactersPatch = "cavernMedium2_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernMedium2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Maracaibo_CaveEntrance_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].locators_radius.reload.reload2 = 2.0;
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Гуахира	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore37";
	locations[n].id.label = "Shore37";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore37";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].Chestgennot = true; // не генерить сундуки
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
	locations[n].reload.l1.go = "Maracaibo_jungle_02";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Maracaibo";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                        locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Shore37";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore37";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_jungle_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Maracaibo_CaveEntrance_02";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     locations[n].id = "Maracaibo_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].ZombieLand = true;
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle1\";
	Locations[n].models.always.jungle = "jungle1";
	Locations[n].models.always.locators = "jungle1_locators";		
	Locations[n].models.always.grassPatch = "jungle1_grass";
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
	locations[n].models.day.charactersPatch = "jungle1_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle1_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_jungle_02";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore15";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_Ruins";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Руины в джунглях	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Ruins";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Ruins\";
	Locations[n].models.always.ruins1 = "ruins1";
	Locations[n].models.always.locators = "ruins1_locators";
		
	Locations[n].models.always.grassPatch = "ruins1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	locations[n].models.always.ruins1_blockade = "ruins1_blockade";
	Locations[n].models.always.ruins1_blockade.locator.group = "Upgrades";
	Locations[n].models.always.ruins1_blockade.locator.name = "ruins1_blockade";

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
	locations[n].reload.l1.go = "Maracaibo_jungle_03";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Вход в пещеру	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_CaveEntrance_02";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Maracaibo_Cave";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта с останками корабля (с заглушкой джунглей)	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore_ship3";
	locations[n].id.label = "Shore_ship3";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore_ship3";
	locations[n].Chestgennot = true; // не генерить сундуки
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\ShoreShip1";
	Locations[n].models.always.shore = "shoreShip1";
	locations[n].models.always.shore.sea_reflection = 1;
	Locations[n].models.always.shoreShip1seabed = "shoreShip1_sb";
	Locations[n].models.always.locators = "shoreShip1_lcommon";	//заглушечный файл локаторов		
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
	locations[n].models.day.charactersPatch = "shoreShip1_patch";
	//Night
	locations[n].models.night.charactersPatch = "shoreShip1_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "DesMoines_Jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].reload.l1.disable = 0;  //закроем, но связка пусть будет для квестов.
	locations[n].locators_radius.reload.reload1 = 4.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Maracaibo";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                        locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Shore_ship3";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore_ship3";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Maracaibo_graveyard";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "DesMoines_town";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Village";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Дес-Мойнес. Зачарованный городок рыбаков.	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Locations[n].id = "DesMoines_town";
	locations[n].id.label = "DesMoines";
	locations[n].image = "loading\inside\Town_0.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
Locations[n].filespath.models = "locations\Gothic\pirateFort";
	Locations[n].models.always.pirateFort = "pirateFort";	
	Locations[n].models.always.locators = "pirateFort_locators";		
	Locations[n].models.always.grassPatch = "pirateFort_grass";
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

	locations[n].models.always.church = "church1";
	Locations[n].models.always.church.locator.group = "quest";
	Locations[n].models.always.church.locator.name = "quest1";
	Locations[n].models.always.church.tech = "DLightModel";
	
	//Day
	locations[n].models.day.charactersPatch = "pirateFort_patch";
	locations[n].models.day.fonars = "pirateFort_fd";
	//Night
	locations[n].models.night.charactersPatch = "pirateFort_patch";
	locations[n].models.night.fonars = "pirateFort_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "DesMoines_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "CommonHut";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "house";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "CommonRoom_MH";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "house";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "CommonHut";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "house";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "CommonHut";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.label = "house";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "DesMoines_Townhall";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.label = "house";

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "church_riuns";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "churchriuns";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "church_riuns";
	locations[n].id.label = "churchriuns";
	locations[n].image = "loading\outside\ChurchRuin.tga";
	//Sound
	locations[n].type = "church";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchRuin\";
	Locations[n].models.always.l1 = "churchRuin";
	Locations[n].models.always.locators = "churchRuin_qlocators";
	Locations[n].models.always.window = "churchRuin_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	locations[n].models.always.back = "..\inside_back";
		
	Locations[n].models.always.churchRuin_vlight1 = "churchRuin_vlight";
                   Locations[n].models.always.churchRuin_vlight1.uvslide.u0 = 0.3;
	Locations[n].models.always.churchRuin_vlight1.tech = "LocationWaterFall";
	Locations[n].models.always.churchRuin_vlight1.level = 50;

	//Day
	locations[n].models.day.fonar = "churchRuin_fd";
	Locations[n].models.day.charactersPatch = "churchRuin_patch";
	//Night
	locations[n].models.night.fonar = "churchRuin_fn";
	Locations[n].models.night.charactersPatch = "churchRuin_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "DesMoines_town";
	Locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "DesMoines";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "DesMoines_Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "crypt";
	locations[n].locators_radius.Quest.LLquest6 = 3.0;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "DesMoines_Graveyard_crypt2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "crypt";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_inside\";
	locations[n].models.always.cryptbig = "crypt_inside";
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.locators = "crypt_inside_locators";
	//Day
	locations[n].models.day.charactersPatch = "crypt_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "church_riuns";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "churchriuns";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 2
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Graveyard_crypt2";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "church_riuns";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "churchriuns";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Резиденция	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Townhall";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	locations[n].townsack = "DesMoines_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "DesMoines_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//кладбище
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Maracaibo_graveyard";
	locations[n].id.label = "Graveyard";
	Locations[n].image = "loading\Cemetery_1.tga";
	//Sound
	locations[n].type = "crypt";
 	locations[n].islandId = "Mein";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Graveyard";
	Locations[n].models.always.town = "Churchyard";
	Locations[n].models.always.grassPatch = "Churchyard_grass";
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
	Locations[n].models.day.fonar = "Churchyard_ld";
	Locations[n].models.day.charactersPatch = "Churchyard_patch";

	//Night
	Locations[n].models.night.fonar = "Churchyard_ln";
	Locations[n].models.night.charactersPatch = "Churchyard_patch";
  
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "DesMoines_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "DesMoines_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l3.name = "reload6";
	Locations[n].reload.l3.go = "Maracaibo_Chapel";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Maracaibo_church IM";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reload4";
	Locations[n].reload.l5.go = "Maracaibo_CryptBig1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "Maracaibo_KeepersHouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	n = n + 1; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Вход в склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_CryptBig1";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Maracaibo";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Maracaibo_graveyard";//Mosh
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Muelle church";
	Locations[n].items.randitem1 = "blade12";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Maracaibo_CryptBig2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload2_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_CryptBig2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_0.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_inside";
	locations[n].models.always.housecrypt_inside = "crypt_inside";
	locations[n].models.always.locators = "crypt_inside_locators";
	//Day
	locations[n].models.day.charactersPatch = "crypt_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Maracaibo_CryptBig1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	n = n + 1;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Колокольня
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Chapel";
	locations[n].label = "Kolokol house";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	Locations[n].townsack = "Maracaibo";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Maracaibo";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_Graveyard";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Maracaibo_church IM";
	locations[n].id.label = "Muelle church";
	locations[n].image = "loading\inside\church.tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchRuin\";
	Locations[n].models.always.l1 = "churchRuin";
	Locations[n].models.always.locators = "churchRuin_qlocators";
	Locations[n].models.always.window = "churchRuin_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	locations[n].models.always.back = "..\inside_back";
		
	Locations[n].models.always.churchRuin_vlight1 = "churchRuin_vlight";
                   Locations[n].models.always.churchRuin_vlight1.uvslide.u0 = 0.3;
	Locations[n].models.always.churchRuin_vlight1.tech = "LocationWaterFall";
	Locations[n].models.always.churchRuin_vlight1.level = 50;

	//Day
	locations[n].models.day.fonar = "churchRuin_fd";
	Locations[n].models.day.charactersPatch = "churchRuin_patch";
	//Night
	locations[n].models.night.fonar = "churchRuin_fn";
	Locations[n].models.night.charactersPatch = "churchRuin_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Maracaibo_graveyard";
	Locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Muelle church";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Maracaibo_Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Mines";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Maracaibo";
 	locations[n].islandId = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_2_2_inside";
	locations[n].models.always.housecrypt_2_2_inside = "crypt_2_2_inside";
	locations[n].models.always.locators = "crypt_2_2_inside_locators";
	//Day
	locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Maracaibo_church IM";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Maracaibo_Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	Locations[n].box3.items.blade37 = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Maracaibo_Graveyard_crypt";
	Locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// домик смотрителя
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Maracaibo_KeepersHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Maracaibo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].islandId = "Maracaibo";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Maracaibo_graveyard";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Churchh";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_03";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Maracaibo_graveyard";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "DesMoines_Jungle_06";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     locations[n].id = "DesMoines_Jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_04";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "DesMoines_Jungle_03";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_05";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Maracaibo_jungle_05";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Бухта Каухорито	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore106";
	locations[n].id.label = "Shore106";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore106";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore09";
	Locations[n].models.always.shore09 = "shore09";
	locations[n].models.always.shore09.sea_reflection = 1;
	Locations[n].models.always.shore09seabed = "shore09_sb";
	Locations[n].models.always.locators = "shore09_locators";
		
	Locations[n].models.always.grassPatch = "shore09_grass";
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
	locations[n].models.day.charactersPatch = "shore09_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore09_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_jungle_04";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Maracaibo";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;


	// Addon 2016-1 Jason Пиратская линейка
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли развилка 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                  Locations[n].id = "Maracaibo_jungle_04";
	locations[n].id.label = "jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle5";
	Locations[n].models.always.jungle = "jungle5";	
	Locations[n].models.always.locators = "jungle5_locators";		
	Locations[n].models.always.grassPatch = "jungle5_grass";
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
	locations[n].models.day.charactersPatch = "jungle5_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle5_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore106";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "shore";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Locono_village";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Maracaibo_jungle_05";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	
	Locations[n].DisableEncounters = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Деревня индейцев араваков
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Locono_village";
	locations[n].id.label = "Village";
	locations[n].image = "loading\Village_" + rand(1) + ".tga";
	locations[n].pearlVillage = 3;
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\IndianVillage";
	Locations[n].models.always.village = "village";	
	Locations[n].models.always.locators = "village_locators";
	Locations[n].models.always.grassPatch = "village_grass";
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
	locations[n].models.day.charactersPatch = "village_patch";
	//Night
	locations[n].models.night.charactersPatch = "village_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Maracaibo_jungle_04";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Locono_shack1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "shack";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Locono_shack2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "shack";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Locono_shack3";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "shack";
	Locations[n].reload.l4.autoreload = "0";

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №1 - большая 
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Locono_shack1";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Locono_village";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_1_inside";
	locations[n].models.always.Hut_1_inside = "Hut_1_inside";
	locations[n].models.always.Hut_1_inside.level = 65538;
	Locations[n].models.always.locators = "Hut_1_inside_locators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_1_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_1_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Locono_village";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Village";
	LAi_LocationFightDisable(&locations[n], true);
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №2 
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Locono_shack2";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Locono_village";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_2_inside";
	locations[n].models.always.Hut_2_inside = "Hut_2_inside";
	locations[n].models.always.Hut_2_inside.level = 65538;
	Locations[n].models.always.Hut_2_insiderand = "Hut_2_inside_rand_1";
	locations[n].models.always.Hut_2_back = "Hut_2_back";
	locations[n].models.always.Hut_2_back.level = 65538; 
	locations[n].models.always.back = "..\inside_back2";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_2_inside_patch";
	locations[n].models.day.locators = "Hut_2_inside_locators";
	//Night
	locations[n].models.night.charactersPatch = "Hut_2_inside_patch";
	locations[n].models.night.locators = "Hut_2_inside_locators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Locono_village";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Village";
	LAi_LocationFightDisable(&locations[n], true);
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №3
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Locono_shack3";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Locono_village";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_2_inside";
	locations[n].models.always.Hut_2_inside = "Hut_2_inside";
	locations[n].models.always.Hut_2_inside.level = 65538;
	Locations[n].models.always.Hut_2_insiderand = "Hut_2_inside_rand_2";
	locations[n].models.always.Hut_2_back = "Hut_2_back";
	locations[n].models.always.Hut_2_back.level = 65538; 
	locations[n].models.always.back = "..\inside_back2";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "Hut_2_inside_locators";
	locations[n].models.day.charactersPatch = "Hut_2_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_2_inside_patch";
	locations[n].models.night.locators = "Hut_2_inside_locators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Locono_village";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Village";
	LAi_LocationFightDisable(&locations[n], true);
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли к реке
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 locations[n].id = "Maracaibo_jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	Locations[n].DisableEncounters = true;
	locations[n].islandIdAreal = "Maracaibo";
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
	locations[n].reload.l1.go = "Maracaibo_river";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "River";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_04";
	locations[n].reload.l2.emerge = "reload3_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Maracaibo_jungle_04";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Берег реки - путь на Мериду
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Locations[n].id = "Maracaibo_river";
	locations[n].id.label = "River";
	Locations[n].image = "loading\River_Bank.tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore14";
	Locations[n].models.always.shore = "shore14";	
	Locations[n].models.always.seabed = "Shore14_Sb";
	locations[n].models.always.shore.sea_reflection = 1;
	Locations[n].models.always.locators = "Shore14_l";		
	Locations[n].models.always.grassPatch = "Shore14_g";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "Shore14_p";
	//Night
	locations[n].models.night.charactersPatch = "Shore14_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Maracaibo_jungle_05";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Берег реки серпантин - путь на Мериду
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Locations[n].id = "Serpentine1";
	locations[n].id.label = "River";
	Locations[n].image = "loading\River_Bank.tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Serpentine";
	Locations[n].models.always.Serpentine = "pass1";
	locations[n].models.always.Serpentine.sea_reflection = 1;
	Locations[n].models.always.seabed = "pass1_sb";
	Locations[n].models.always.locators = "pass1_locators";		
	Locations[n].models.always.grassPatch = "pass1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "pass1_patch";
	//Night
	locations[n].models.night.charactersPatch = "pass1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Serpentine_cave";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.label = "cave";
	Locations[n].reload.l1.autoreload = 1;
	locations[n].locators_radius.reload.reload1_back = 2.0;
	locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Сквозная пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	locations[n].id = "Serpentine_cave";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
 	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernLow1";
	locations[n].models.always.cavernLow1 = "cavernLow1";
		
	locations[n].models.always.cavernLow1Lamps = "cavernLow1_lamps";
	locations[n].models.always.cavernLow1Crystals = "cavernLow1_crystals";
	locations[n].models.always.cavernLow1Crystals.tech = "EnvironmentShader";
	locations[n].models.always.cavernLow1Crystals.reflection = 0.25;
	
	locations[n].models.always.Waterfall = "water";
	locations[n].models.always.Waterfall.uvslide.v0 = 0.0;
	locations[n].models.always.Waterfall.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall.level = 51;

	locations[n].models.always.Cfall = "cfall";
	locations[n].models.always.Cfall.uvslide.v0 = 0.3;
    locations[n].models.always.Cfall.uvslide.v1 = 0.0;
	locations[n].models.always.Cfall.tech = "LocationWaterFall";
	locations[n].models.always.Cfall.level = 50;
	
	locations[n].models.always.locators = "cavernLow1_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
	
	//Day
	locations[n].models.day.charactersPatch = "cavernLow1_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernLow1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Serpentine1";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Serpentine2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 2;
	
	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Cерпантин - путь на Мериду
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                  Locations[n].id = "Serpentine2";
	locations[n].id.label = "jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Serpentine";
	Locations[n].models.always.Serpentine = "pass2";
	locations[n].models.always.Serpentine.sea_reflection = 1;
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.locators = "pass2_locators";		
	Locations[n].models.always.grassPatch = "pass2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "pass2_patch";
	//Night
	locations[n].models.night.charactersPatch = "pass2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Serpentine_cave";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "cave";
	Locations[n].reload.l1.autoreload = 1;
	locations[n].locators_radius.reload.reload1_back = 2.0;
	
	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Merida_jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "jungle";
	Locations[n].reload.l2.autoreload = 1;
	locations[n].locators_radius.reload.reload2_back = 2.0;
	locations[n].locators_radius.quest.detector1 = 3.0;

	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли - путь на Мериду
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 Locations[n].id = "Merida_jungle_01";
	locations[n].id.label = "jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle11";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Serpentine2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Merida_ExitTown";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "ExitTown";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	
	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход к Мериде
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Merida_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitM";
	Locations[n].models.always.townExit = "douexit";
	Locations[n].models.always.dno = "DouExit_dno";
	Locations[n].models.always.rfl = "DouExit_rfl";
	Locations[n].models.always.wfl = "DouExit_wfl";
	Locations[n].models.always.wfl.uvslide.u0 = 0.6;
    Locations[n].models.always.wfl.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl.tech = "LocationWaterFall";
	Locations[n].models.always.wfl.level = 48;
	Locations[n].models.always.wfl1 = "DouExit_wfl1";
	Locations[n].models.always.wfl1.uvslide.u0 = 0.6;
    Locations[n].models.always.wfl1.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl1.tech = "LocationWaterFall";
	Locations[n].models.always.wfl1.level = 47;
	Locations[n].models.always.wfl2 = "DouExit_wfl2";
	Locations[n].models.always.wfl2.uvslide.u0 = 0.6;
    Locations[n].models.always.wfl2.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl2.tech = "LocationWaterFall";
	Locations[n].models.always.wfl2.level = 46;
	Locations[n].models.always.water = "DouExit_wtr";
	Locations[n].models.always.water.reflection = 0.6;
	Locations[n].models.always.water.tech = "EnvironmentShader";
	Locations[n].models.always.reflect = "reflect";
	Locations[n].models.always.Waterfall = "Waterfall";
	Locations[n].models.always.Waterfall.uvslide.u0 = 0.6;
    Locations[n].models.always.Waterfall.uvslide.u1 = 0.01;
	Locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall.level = 50;
	Locations[n].models.always.Waterfall2 = "Waterfall2";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.01;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 49;
	Locations[n].models.always.locators = "DouExit_l";	
	Locations[n].models.always.grassPatch = "DouExit_g";
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
	locations[n].models.day.charactersPatch = "DouExit_p";
	locations[n].models.day.fonars = "DouExit_fd";
	//Night
	locations[n].models.night.charactersPatch = "DouExit_p";
	locations[n].models.night.fonars = "DouExit_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";	
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Merida_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Merida";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Merida_jungle_01";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	
	Locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Мерида
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Merida_town";
	locations[n].id.label = "Street";
	locations[n].image = "loading\Town.tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	//Models
	//Always
	locations[n].filespath.models = "locations\Merida";
	Locations[n].models.always.town = "Doutown";
	
	Locations[n].models.always.locators = "Doutown_l";
		
	Locations[n].models.always.grassPatch = "Doutown_g";
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
	locations[n].models.day.charactersPatch = "Doutown_p";
	locations[n].models.day.fonars = "Doutown_fd";
	//Night
	locations[n].models.night.charactersPatch = "Doutown_p";
	locations[n].models.night.fonars = "Doutown_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";	
	//Reload map
	locations[n].reload.l1.name = "gate_back";
	locations[n].reload.l1.go = "Merida_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "jungle";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "Merida_townhall";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "townhall";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция Мериды
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Merida_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	Locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence07";
	locations[n].models.always.locators = "Res07_locators";
	locations[n].models.always.l1 = "Res07";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "Res07_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Res07_patch";
	//Night
	locations[n].models.night.charactersPatch = "Res07_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Merida_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	LAi_LocationFightDisable(&locations[n], true);
	locations[n].DisableOfficers = "1";
	locations[n].box1.QuestClosed = true;
	
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Эль Мембрильо	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore107";
	locations[n].id.label = "Shore107";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore107";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Maracaibo";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     locations[n].id = "DesMoines_Jungle_06";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_02";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_07";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_Jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
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
	locations[n].reload.l1.go = "DesMoines_Jungle_06";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_08"; 
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "DesMoines_Jungle_001";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_07";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_09";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_09";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_08";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_10";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_10";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_09";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_11";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_11";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle3";
	Locations[n].models.always.jungle = "jungle3";	
	Locations[n].models.always.locators = "jungle3_locators";
	Locations[n].models.always.lcommon = "Jungle3_lcommon";
	Locations[n].models.always.locators = "Jungle3_mine_locators";
	Locations[n].models.always.locators = "Jungle3_Dollylocators";			
	Locations[n].models.always.grassPatch = "jungle3_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

 	Locations[n].models.always.dooropen = "Jungle3_wall";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
				
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
	locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle3_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_13";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_10";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "DesMoines_Jungle_001";
	locations[n].reload.l3.emerge = "reload2_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_001";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_07";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_002";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_002";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_001";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_003";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_003";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Maracaibo";
	locations[n].islandId = "Mein";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_002";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_005"; 
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_005";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_003";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_006";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_006";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_005";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore131";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore131";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Бухта 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore131";
	locations[n].id.label = "Shore131";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore131";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Maracaibo";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore13";
	Locations[n].models.always.shore13 = "shore13";
	locations[n].models.always.shore13.sea_reflection = 1;
	Locations[n].models.always.shore13seabed = "shore13_seabed";
	Locations[n].models.always.locators = "shore13_locators";
		
	Locations[n].models.always.grassPatch = "shore13_grass";
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
	locations[n].models.day.charactersPatch = "shore13_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore13_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_006";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;
 			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_13";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_11";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_14";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_14";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle11\";
	Locations[n].models.always.jungle = "jungle11";	
	Locations[n].models.always.locators = "jungle11_locators";		
	Locations[n].models.always.grassPatch = "jungle11_grass";
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
	locations[n].models.day.charactersPatch = "jungle11_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle11_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_13";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_Jungle_15";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "DesMoines_Jungle_15";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].IrokuLand = true;
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
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
	locations[n].models.day.charactersPatch = "jungle8_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle8_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "DesMoines_Jungle_14";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shore110";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore110";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Бухта 'Рио-дель-Ача'	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore110";
	locations[n].id.label = "Shore110";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore110";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Maracaibo";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore03";
	Locations[n].models.always.shore03 = "shore03";
	locations[n].models.always.shore03.sea_reflection = 1;
	Locations[n].models.always.shore03seabed = "shore03_sb";
	Locations[n].models.always.locators = "shore03_locators";
	Locations[n].models.always.smg = "smg";
	Locations[n].models.always.smg.tech = "DLightModel";
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
	locations[n].reload.l1.go = "DesMoines_Jungle_15";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;		


	return n;
}

