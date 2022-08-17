
int LocationInitBeliz(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Beliz";
	locations[n].filespath.models = "locations\Town_Beliz\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Town sack
	locations[n].townsack = "Beliz";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "Beliz";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Beliz_signsA";
	locations[n].models.always.seabed = "Beliz_sb";
	locations[n].models.always.locators = "Beliz_locators";
	locations[n].models.always.grassPatch = "Beliz_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.3;

	//Day
	locations[n].models.day.fonar = "Beliz_fd";
	locations[n].models.day.charactersPatch = "Beliz_patch_day";
	locations[n].models.day.rinok = "Beliz_rinok";
	//Night
	locations[n].models.night.fonar = "Beliz_fn";
	locations[n].models.night.charactersPatch = "Beliz_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Beliz_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.lR1.name = "reloadR1";
	locations[n].reload.lR1.go = "Beliz_TownhallRoom";
	locations[n].reload.lR1.emerge = "reload3";
	locations[n].reload.lR1.autoreload = "0";
	locations[n].reload.lR1.label = "Residence";
	locations[n].reload.lR1.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Beliz_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Beliz_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Beliz_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Beliz_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Beliz_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "Beliz_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "Beliz_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "Beliz_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации.
	
	locations[n].reload.l12.name = "houseH1";
	locations[n].reload.l12.go = "House_Smithy";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House Smithy";
	
    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseF2";
	locations[n].reload.l20.go = "CommonRoom_MH4";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseSp2";
	locations[n].reload.l21.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
	
	locations[n].reload.l22.name = "houseSp21";
	locations[n].reload.l22.go = "CommonRoom_MH3";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";
	
	locations[n].reload.l23.name = "houseS5";
	locations[n].reload.l23.go = "CommonFlamHouse";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";
	
	locations[n].reload.l24.name = "houseF1";
	locations[n].reload.l24.go = "CommonRoom_MH2";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseSp1";
	locations[n].reload.l25.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";
	
	locations[n].reload.l26.name = "houseS3";
	locations[n].reload.l26.go = "CommonPirateHouse";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";
	
	locations[n].reload.l27.name = "houseS2";
	locations[n].reload.l27.go = "CommonCobHouse";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";
	
	locations[n].reload.l28.name = "houseS1";
	locations[n].reload.l28.go = "CommonFlamHouse";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";
	
	locations[n].reload.l29.name = "houseSp4";
	locations[n].reload.l29.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";
	
	locations[n].reload.l30.name = "houseSp3";
	locations[n].reload.l30.go = "CommonStoneHouse";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";
	/*
	locations[n].reload.l31.name = "houseH1";
	locations[n].reload.l31.go = "CommonRoom_MH7";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";
	*/
	
	locations[n].reload.l32.name = "houseF3";
	locations[n].reload.l32.go = "CommonRoom_MH";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

	locations[n].reload.l33.name = "houseF4";
	locations[n].reload.l33.go = "CommonPirateHouse";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";
	
	locations[n].reload.l34.name = "houseS4";
	locations[n].reload.l34.go = "CommonStoneHouse";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";
	n = n + 1;

  	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_tavern";
	locations[n].id.label = "Tavern34";
	locations[n].filespath.models = "locations\inside\Tavern01\";
	Locations[n].image = "loading\inside\tavern_eng.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
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
	locations[n].models.day.charactersPatch = "Tavern01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store01\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].models.always.locators = "Store01_locators";
	locations[n].models.always.store = "Store01";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz_town";
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
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_town";
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
	locations[n].id = "Beliz_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard02\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Beliz_town";
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
	locations[n].id = "Beliz_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence01";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.locators = "Residence01_locators";
	locations[n].models.always.l1 = "Residence01";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "CommonResidence_4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l3.name = "reload2"; //кабинет налево от входа
	locations[n].reload.l3.go = "Beliz_TownhallRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "TownhallRoom";
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_TownhallRoom"; //кабинет со спальней и выходом в город сбоку
	locations[n].id.label = "TownhallRoom";
	locations[n].image = "loading\inside\BigHouseBack_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouseBack";
	locations[n].models.always.house = "BigHouseBack";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouseBack_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouseBack_patch";
	locations[n].models.day.locators = "BigHouseBack_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouseBack_patch";
	locations[n].models.night.locators = "BigHouseBack_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Beliz_townhall";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonBedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "BedRoom";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Beliz_town";
	locations[n].reload.l3.emerge = "reloadR1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Street";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "Beliz_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "Beliz";
    locations[n].parent_colony = "Beliz";
 	locations[n].fastreload = "Beliz";
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
	Locations[n].reload.l1.go = "Beliz_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// дом кузины Изабеллы Роситы Фернандес
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_houseS4";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "Rosita's House";
	locations[n].image = "loading\inside\stonehouse.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].models.always.locators = "StoneHouse_lBelizIsa";
	locations[n].models.always.tavern = "StoneHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "StoneHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

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
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "houseS4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH5";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Смитов	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "House_Smithy";
	locations[n].id.label = "House Smithy";
	locations[n].image = "loading\inside\flamhouse.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//locations[n].fastreload = "Beliz";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\FlamHouse";
	locations[n].models.always.tavern = "FlamHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "FlamHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "FlamHouse_locators";
	locations[n].models.night.locators = "FlamHouse_Nlocators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "FlamHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "FlamHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload1";//город
	Locations[n].reload.l1.go = "Beliz_town";
	Locations[n].reload.l1.emerge = "houseH1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l3.name = "reload3";//в нашу комнату
	locations[n].reload.l3.go = "Smithy_HouseF3_Room2";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	
	locations[n].reload.l2.name = "reload4";//в комнату 
	locations[n].reload.l2.go = "Smithy_HouseF3_Room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l4.name = "reload2"; //погребок-с.
	locations[n].reload.l4.go = "Beliz_TownCave"; 
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Dungeon";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	/////////////////////комната алхимика 
	locations[n].id = "Smithy_HouseF3_Room";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\JinoRoom";
	locations[n].models.always.JinoRoom = "JinoRoom";
	locations[n].models.always.JinoRoom.level = 65538;
	locations[n].models.day.locators = "JinoRoom_locators";
	locations[n].models.night.locators = "JinoRoom_Nlocators";

	Locations[n].models.always.JinoRoomwindows = "JinoRoom_windows";
	Locations[n].models.always.JinoRoomwindows.tech = "LocationWindows";
	locations[n].models.always.JinoRoomwindows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.JinoRoomrand= "JinoRoom_rand";
	locations[n].models.day.charactersPatch = "JinoRoom_patch";
	//Night
	locations[n].models.night.charactersPatch = "JinoRoom_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "House_Smithy";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	n = n + 1;
	
	////////////комната для лечений 
	locations[n].id = "Smithy_HouseF3_Room2";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\murdoch_room";
	locations[n].models.always.murdoch_room = "murdoch_room";
	locations[n].models.always.murdoch_room.level = 65538;
	locations[n].models.day.locators = "murdoch_room_locators";
	locations[n].models.night.locators = "murdoch_room_Nlocators";

	Locations[n].models.always.murdoch_roomwindows = "murdoch_room_windows";
	Locations[n].models.always.murdoch_roomwindows.tech = "LocationWindows";
	locations[n].models.always.murdoch_roomwindows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	
	//locations[n].models.always.l1 = "murdoch_room_bed0";
	//locations[n].models.always.l1.tech = "DLightModel";
	
	//Day
	Locations[n].models.day.murdoch_roomrand = "murdoch_room_rand";
	locations[n].models.day.charactersPatch = "murdoch_room_patch";
	locations[n].models.day.l1 = "murdoch_room_bed0";
	locations[n].models.day.l1.tech = "DLightModel";
	//Night
	Locations[n].models.night.murdoch_roomrand = "murdoch_room_rand";
	locations[n].models.night.charactersPatch = "murdoch_room_patch";
	locations[n].models.night.l2 = "murdoch_room_bed1";
	locations[n].models.night.l2.tech = "DLightModel";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "House_Smithy";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	LAi_LocationFightDisable(&locations[n], true);
	
	locations[n].private1.items.recipe_totem_02 = 1;
	locations[n].private1.items.recipe_totem_02 = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Старый подвал
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Beliz_TownCave";
	Locations[n].id.label = "Dungeon";
	Locations[n].image = "loading\inside\dungeon_1.tga";
	//Town sack
	locations[n].townsack = "Beliz";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "Mein";
	locations[n].parent_colony = "Beliz";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\DungeonOld1";
	Locations[n].models.always.tavern.tech = "DLightModel";		
	Locations[n].models.always.locators = "DungeonOld1_locators";
	Locations[n].models.always.locators.tech = "DLightModel";
	locations[n].models.always.window.tech = "LocationWindows";			
	Locations[n].models.always.DungeonOld1 = "DungeonOld1";
	locations[n].models.always.DungeonOld1.level = 65538;
	//Day
	Locations[n].models.day.charactersPatch = "DungeonOld1_patch";
	//Night
	Locations[n].models.night.charactersPatch = "DungeonOld1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "House_Smithy";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Drugstore";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "basement1_back";
	locations[n].locators_radius.item.berglar1 = 3.0;
	locations[n].reload.l2.label = "Street";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Beliz_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	Locations[n].townsack = "Beliz";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitY";
	Locations[n].models.always.townExit = "townExitY";
	Locations[n].models.always.townWalls = "townExitY_wood";
	
	Locations[n].models.always.locators = "townExitY_locators";
		
	Locations[n].models.always.grassPatch = "townExitY_grass";
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
	locations[n].models.day.charactersPatch = "townExitY_patch";
	locations[n].models.day.fonars = "townExitY_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitY_patch";
	locations[n].models.night.fonars = "townExitY_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Beliz_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Beliz";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Beliz_Jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Beliz_Fort";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Beliz Fort";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	locations[n].locators_radius.quest.detector1 = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_ExitTown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_CaveEntrance_1";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
    locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Beliz_CaveEntrance_2";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру 1
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_CaveEntrance_1";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_Jungle_01";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].id.label = "Cave";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models	
	//Always
	locations[n].filespath.models = "locations\inside\cavernMedium1";
	locations[n].models.always.cavernMedium1 = "cavernMedium1";
	locations[n].models.always.cavernMedium1.sea_reflection = 1;
	
	locations[n].models.always.lamps = "cavernMedium1_lamps";	
	locations[n].models.always.locators = "cavernMedium1_locators";	

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "cavernMedium1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;
*/	
	//Day
	locations[n].models.day.charactersPatch = "cavernMedium1_patch";
	Locations[n].models.day.jumpPatch = "CavernMedium1_jump";
	//Night
	locations[n].models.night.charactersPatch = "cavernMedium1_patch";
	Locations[n].models.night.jumpPatch = "CavernMedium1_jump";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz_CaveEntrance_1";
	locations[n].reload.l1.emerge = "reload1";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Beliz_CaveEntrance_3";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].locators_radius.reload.reload2 = 1.3;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру 2
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_CaveEntrance_2";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_Cave_2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_Jungle_01";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Шахта
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_Cave_2";
	locations[n].id.label = "Cave";
    locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].nofire = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer2";
	locations[n].models.always.DungeonDuffer2 = "DungeonDuffer2";
	locations[n].models.always.locators = "DungeonDuffer2_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "DungeonDuffer2_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
	//Day
	locations[n].models.day.charactersPatch = "DungeonDuffer2_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonDuffer2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Beliz_CaveEntrance_2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта с разбитым кораблем №2 (c заглушкой на джунгли)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore_ship2";
	locations[n].id.label = "Shore_ship2";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore_ship2";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].deadlocked = true;
	locations[n].questflower = 1;
	locations[n].Chestgennot = true; // не генерить сундуки
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
	locations[n].reload.l1.go = "Tayasal_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 4.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс Каточе (c заглушкой на джунгли)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore6";
	locations[n].id.label = "Shore6";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore6";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].deadlocked = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore01";
	Locations[n].models.always.shore01 = "shore01";
	locations[n].models.always.shore01.sea_reflection = 1;
	Locations[n].models.always.shore01seabed = "shore01_sb";
	Locations[n].models.always.locators = "shore01_lcommon"; //заглушечный файл локаторов

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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Beliz_jungle_04";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Beliz_jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].questflower = 1;
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
	locations[n].reload.l1.go = "Shore6";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore6";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jungle_fort_exit";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].reload.l2.disable = true; //закрыто до поры
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход к форту
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jungle_fort_exit";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\DuelField";
	Locations[n].models.always.fort_exit = "DuelField";	
	Locations[n].models.always.locators = "duelfield_locators";		
	Locations[n].models.always.grassPatch = "duelfield_grass";
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
	locations[n].models.always.l4 = "DuelField_plan";
	locations[n].models.always.l5 = "duelfield_gate";
	//Day
	locations[n].models.day.fonar = "duelfield_fd";
	locations[n].models.day.charactersPatch = "duelfield_patch";
	//Night
	locations[n].models.night.fonar = "duelfield_fn";
	locations[n].models.night.charactersPatch = "duelfield_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jungle_fort";  
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Fort inside";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_jungle_04"; 
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// форт в джунглях
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jungle_fort";
	locations[n].id.label = "Fort inside";
	locations[n].image = "loading\outside\Fort_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "fort";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Fort2";
	Locations[n].models.always.fort = "Fort2";	
	Locations[n].models.always.locators = "Fort2_locators";		
	Locations[n].models.always.grassPatch = "Fort2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	//Day
	locations[n].models.day.fonar = "Fort2_fd";
	locations[n].models.day.charactersPatch = "Fort2_patch";
	//Night
	locations[n].models.night.fonar = "Fort2_fn";
	locations[n].models.night.charactersPatch = "Fort2_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Jungle_fort_exit";  
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Jungle_fort_ammo";  
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "ammo";

	n = n + 1;
	
	 ////////////////////// фортовый подвал ////////////////////////////
	Locations[n].id = "Jungle_fort_ammo";
	locations[n].id.label = "ammo";
	Locations[n].image = "loading\Arsenal_" + rand(5) + ".tga";
 	locations[n].islandId = "Mein";
	//Sound
	locations[n].type = "ammo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ammo";
	locations[n].models.always.ammo = "ammo";
	locations[n].models.always.lamps = "ammo_lamps";
	locations[n].models.always.locators = "ammo_locators";	
	//Day
	locations[n].models.day.charactersPatch = "ammo_patch";
	//Night
	locations[n].models.night.charactersPatch = "ammo_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
    //Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Jungle_fort";
	Locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.label = "Fort inside";
	Locations[n].reload.l1.autoreload = "0";
	
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// залив Косумель (c заглушкой на джунгли)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore7";
	locations[n].id.label = "Shore7";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore7";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].deadlocked = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore02";
	Locations[n].models.always.shore02 = "shore02";
	locations[n].models.always.shore02.sea_reflection = 1;
	Locations[n].models.always.shore02seabed = "shore02_sb";
	Locations[n].models.always.locators = "shore02_lcommon"; //заглушечный файл локаторов
		
	Locations[n].models.always.grassPatch = "shore02_grass";
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
	locations[n].models.day.charactersPatch = "shore02_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore02_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Common_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Четумаль
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore8";
	locations[n].id.label = "Shore8";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore8";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_jungle_03";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Beliz_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Shore8";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore15";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_CaveEntrance_3";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_CaveEntrance_3";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Beliz_Cave";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_jungle_03";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// лагуна Каратаска - путь к подземельям правосудия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore10";
	locations[n].id.label = "Shore10";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore10";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].deadlocked = true;
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
	locations[n].reload.l1.go = "Carataska_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Carataska_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	//Day
	locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle3_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore10";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore10";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Carataska_jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Carataska_CaveEntrance";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	
	locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Carataska_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
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
	locations[n].reload.l1.go = "Carataska_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Carataska_jungle_01";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	
	locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Carataska_Cave";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	//locations[n].questflower = 2;
	//Sound
	locations[n].type = "cave";
 	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernMedium1";
	locations[n].models.always.cavernMedium1 = "cavernMedium1";
	locations[n].models.always.cavernMedium1.sea_reflection = 1;
	locations[n].models.always.lamps = "cavernMedium1_lamps";	
	locations[n].models.always.locators = "cavernMedium1_locators";	
	locations[n].locators_radius.item.duhi1 = 0.0;
	//Day
	locations[n].models.day.charactersPatch = "cavernMedium1_patch";
	Locations[n].models.day.jumpPatch = "CavernMedium1_jump";
	//Night
	locations[n].models.night.charactersPatch = "cavernMedium1_patch";
	Locations[n].models.night.jumpPatch = "CavernMedium1_jump";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Carataska_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	locations[n].locators_radius.reload.reload2 = 0.0; 
	
	locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Carataska_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	locations[n].models.always.deadfall = "deadfall2";
	Locations[n].models.always.deadfall.locator.group = "quest";
	Locations[n].models.always.deadfall.locator.name = "deadfall";
	Locations[n].models.always.deadfall.tech = "DLightModel";
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
	locations[n].reload.l1.go = "Carataska_jungle_01"; 
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0; 

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Carataska_jungle_03"; // к подземельям правосудия
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 0.0; // проход завален
	locations[n].locators_radius.quest.deadfall = 4.5;
	locations[n].locators_radius.quest.detector1 = 6.0;
	locations[n].locators_radius.item.fire = 4.5; 
	
	locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Carataska_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.go = "Carataska_jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.5;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Ruins";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Ruins";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	
	locations[n].DisableEncounters = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Руины города (модель временная)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Ruins";
	locations[n].id.label = "Ruins";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "questisland";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].questflower = 1;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Ruins";
    Locations[n].models.always.ruins = "ruins1";
    Locations[n].models.always.l1 = "plan1";
    Locations[n].models.always.l1.level = 9;
    Locations[n].models.always.l1.tech = "LocationModelBlend";
    Locations[n].models.always.l2 = "plan2";
    Locations[n].models.always.l2.level = 8;
    Locations[n].models.always.l2.tech = "LocationModelBlend";
    Locations[n].models.always.l3 = "plan3";
    Locations[n].models.always.l3.level = 7;
    Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.locators = "ruins1_locators";
	
	Locations[n].models.always.grassPatch = "ruins1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
    //Day
    Locations[n].models.day.charactersPatch = "ruins1_patch";
    //Night
    Locations[n].models.night.charactersPatch = "ruins1_patch";
    //Environment
    Locations[n].environment.weather = "true";
    Locations[n].environment.sea = "false";	
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Judgement_dungeon_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "dungeon";
	locations[n].locators_radius.reload.reload2 = 1.3;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Carataska_jungle_03";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 1 (вход)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_01";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonOld1";
	locations[n].models.always.Dungeon = "DungeonOld1";
	locations[n].models.always.locators = "DungeonOld1_locators";
	locations[n].models.always.door = "door";
	Locations[n].models.always.door.locator.group = "quest";
	Locations[n].models.always.door.locator.name = "door";
	Locations[n].models.always.door.tech = "DLightModel";
	//Day
	locations[n].models.day.charactersPatch = "DungeonOld1_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonOld1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Ruins";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Ruins";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Judgement_dungeon_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "mines";
	locations[n].locators_radius.reload.reload2_back = 1.5;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	locations[n].private1.items.mineral14 = 20;
	locations[n].private1.items.mineral4 = 10;
	
	locations[n].private2.items.mineral8 = 35;
	locations[n].private2.items.mineral24 = 1;
	
	locations[n].private3.items.mineral30 = 15;
	locations[n].private3.items.mineral26 = 1;
	
	locations[n].private4.items.mineral31 = 25;
	locations[n].private4.items.mineral22 = 5;
	
	locations[n].private5.items.mineral9 = 13;
	locations[n].private5.items.mineral20 = 1;
	
	locations[n].private6.items.mineral23 = 50;
	locations[n].private6.items.mineral13 = 1;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 2 (заброшенные шахты)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_02";
	locations[n].id.label = "mines";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonOld5";
	locations[n].models.always.Dungeon = "DungeonOld5";
	locations[n].models.always.locators = "DungeonOld5_locators";
	locations[n].models.always.Trapdoor = "trapdoor";
	Locations[n].models.always.Trapdoor.locator.group = "reload";
	Locations[n].models.always.Trapdoor.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonOld5_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonOld5_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Judgement_dungeon_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "dungeon";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "mines";
	locations[n].locators_radius.reload.reload2 = 0.9;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 3 (заброшенные шахты)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_03";
	locations[n].id.label = "mines";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonOld3";
	locations[n].models.always.Dungeon = "DungeonOld3";
	locations[n].models.always.locators = "DungeonOld3_locators";
	locations[n].models.always.hatch = "hatch";
	Locations[n].models.always.hatch.locator.group = "reload";
	Locations[n].models.always.hatch.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonOld3_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonOld3_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "mines";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_04";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "mines";
	locations[n].locators_radius.reload.reload2 = 0.9;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	locations[n].private1.items.slave_02 = 18;
	locations[n].private1.items.jewelry13 = 32;
	
	locations[n].private2.items.slave_01 = 14;
	locations[n].private2.items.jewelry13 = 54;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 4 (заброшенные шахты)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_04";
	locations[n].id.label = "mines";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonOld4";
	locations[n].models.always.Dungeon = "DungeonOld4";
	locations[n].models.always.locators = "DungeonOld4_locators";
	locations[n].models.always.door = "door_wall";
	Locations[n].models.always.door.locator.group = "reload";
	Locations[n].models.always.door.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonOld4_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonOld4_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_03";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "mines";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_05";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	locations[n].private1.items.topor_05 = 11;
	locations[n].private1.items.jewelry12 = 28;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 5 (радиальные проходы)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_05";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonOld2";
	locations[n].models.always.locators = "DungeonOld2_locators";
	locations[n].models.always.Dungeon = "DungeonOld2";
	locations[n].models.always.treasure = "Treasures";
	Locations[n].models.always.treasure.locator.group = "monsters";
	Locations[n].models.always.treasure.locator.name = "monster3";
	locations[n].models.always.door = "door_old";
	Locations[n].models.always.door.locator.group = "reload";
	Locations[n].models.always.door.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonOld2_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonOld2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_04";
	locations[n].reload.l1.emerge = "reload2_2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "mines";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_06";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].reload.l2.disable = 1;
	
	locations[n].locators_radius.item.key = 1.0;
	
	locations[n].private1.items.key_scotland = 1; // ключ от двери
	locations[n].private1.items.Mineral15 = 1;
	locations[n].private1.items.Mineral7 = 1;
	locations[n].private1.items.jewelry40 = 1;
	
	locations[n].private2.items.chest_open = 40;
	
	locations[n].private3.items.pistol1 = 1;
	locations[n].private3.items.bullet = 1;
	locations[n].private3.items.gunpowder = 1;
	
	locations[n].private4.items.blade_05 = 1;
	locations[n].private4.items.mineral16 = 1;
	
	locations[n].private5.items.mineral18 = 5;
	locations[n].private5.items.mineral7 = 1;
	
	locations[n].private6.items.rat_poison = 1;
	
	locations[n].private7.items.jewelry51 = 15;
	
	locations[n].private8.items.Mineral5 = 1;
	locations[n].private8.items.mineral10 = 1;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 6 (подтопленные тоннели - путь к разрушенной церкви)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_06";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonVault3";
	locations[n].models.always.Dungeon = "DungeonVault3";
	locations[n].models.always.locators = "DungeonVault3_locators";	
	locations[n].models.always.door = "door_new";
	Locations[n].models.always.door.locator.group = "reload";
	Locations[n].models.always.door.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault3_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault3_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].MaxWaveHeigh = 0.5;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_05";
	locations[n].reload.l1.emerge = "reload2_2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "dungeon";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_07";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].locators_radius.reload.reload2 = 1.0;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	locations[n].private1.items.jewelry21 = 25; 
	
	locations[n].private2.items.jewelry17 = 25;
	
	locations[n].private3.items.jewelry23 = 14;
	
	locations[n].private4.items.Mineral17 = 44;
	
	locations[n].private5.items.topor_03 = 1;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 7 (путь к разрушенной церкви)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_07";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_2_4_inside";
	locations[n].models.always.cryptbig = "crypt_2_4_inside";
	locations[n].models.always.locators = "crypt_2_4_inside_l";
	//Day
	locations[n].models.day.charactersPatch = "crypt_2_4_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_2_4_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_church";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "ruins";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_06";
	locations[n].reload.l2.emerge = "reload2_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].locators_radius.reload.reload2 = 1.0;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	
	locations[n].private1.items.amulet_6 = 1;
	locations[n].private1.items.Mineral3 = 20;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - разрушенная церковь
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_church";
	locations[n].id.label = "ruins";
	locations[n].image = "loading\outside\ChurchRuin.tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Locations[n].lockCamAngle = 0.1;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ChurchRuin";
	locations[n].models.always.church = "churchRuin";
	locations[n].models.always.windows = "churchRuin_windows";
	locations[n].models.always.locators = "churchRuin_qlocators";
	locations[n].models.always.ground = "Ground_02";
	//Locations[n].models.always.ground.tech = "DLightModel";
	//Day
	locations[n].models.day.charactersPatch = "churchRuin_patch";
	//locations[n].models.day.fonar = "churchRuin_fd";
	//Night
	locations[n].models.night.charactersPatch = "churchRuin_patch";
	//locations[n].models.night.fonar = "churchRuin_fn";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Judgement_dungeon_07";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "dungeon";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Judgement_dungeon_08";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].locators_radius.reload.reload2_back = 0.0; // закрыто
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 8 (крипта)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_08";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\crypt_2_3_inside";
	locations[n].models.always.cryptbig = "crypt_2_3_inside";
	locations[n].models.always.locators = "crypt_2_3_inside_locators";
	//Day
	locations[n].models.day.charactersPatch = "crypt_2_3_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "crypt_2_3_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_church";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "ruins";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_09";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	
	locations[n].private1.items.amulet_7 = 1;
	locations[n].private1.items.jewelry45 = 10;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 9 (адские туннели)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_09";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_hell_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonVault4";
	locations[n].models.always.Dungeon = "DungeonVault4";
	locations[n].models.always.locators = "DungeonVault4_locators";	
	locations[n].models.always.fonars = "DungeonVault4_fonars";	
	locations[n].models.always.door = "door_hell";
	Locations[n].models.always.door.locator.group = "reload";
	Locations[n].models.always.door.locator.name = "reload2";
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault4_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault4_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].MaxWaveHeigh = 2.0;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_08";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "dungeon";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dungeon_10";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].locators_radius.reload.reload2 = 0.9;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	LAi_LocationFightDisable(&locations[n], true);
	
	locations[n].private1.items.jewelry10 = 100;
	
	locations[n].private2.items.jewelry5 = 1000;
	
	locations[n].private3.items.jewelry6 = 1000;
	
	locations[n].private4.items.jewelry5 = 750;
	locations[n].private4.items.jewelry6 = 750;
	
	locations[n].locators_radius.item.detector1 = 1.5;
	locations[n].locators_radius.item.detector2 = 1.5;
	for (int i=1; i<=112; i++) // горячие фонтанчики
	{
		string sTemp = "fontain"+i;
		locations[n].locators_radius.item.(sTemp) = 0.7;
	}
	for (i=1; i<=100; i++) // гейзеры
	{
		sTemp = "splash"+i;
		locations[n].locators_radius.item.(sTemp) = 0.9;
	}
	for (i=1; i<=10; i++) // дым
	{
		sTemp = "smoke"+i;
		locations[n].locators_radius.item.(sTemp) = 1.2;
	}
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье правосудия - 10 (адские туннели)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dungeon_10";
	locations[n].id.label = "dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Judgement_hell_dungeon";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\PrisonOld";
	locations[n].models.always.Prison = "Prison";
	locations[n].models.always.locators = "Prison_locators";
	locations[n].models.always.window = "Prison_window";
	locations[n].models.always.well_on = "well_on";
	Locations[n].models.always.well_on.locator.group = "reload";
	Locations[n].models.always.well_on.locator.name = "reload2";
	Locations[n].models.always.well_on.tech = "DLightModel";	
	//Day
	locations[n].models.day.charactersPatch = "Prison_patch";
	//Night
	locations[n].models.night.charactersPatch = "Prison_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].MaxWaveHeigh = 4.0;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Judgement_dungeon_09";
	locations[n].reload.l1.emerge = "reload2_2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "dungeon";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Judgement_dumpcave";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "FloodedCave";
	locations[n].locators_radius.reload.reload2 = 0.9;
	locations[n].locators_radius.item.detector1 = 1.0;
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	LAi_LocationFightDisable(&locations[n], true);
	
	for (i=1; i<=8; i++) // статичные гейзеры
	{
		sTemp = "fontain"+i;
		locations[n].locators_radius.item.(sTemp) = 0.9;
	}
	locations[n].locators_radius.item.splash6 = 0.9;
	locations[n].locators_radius.item.splash7 = 0.9;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Затопленная пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Judgement_dumpcave";
	locations[n].id.label = "FloodedCave";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "underwater";
	locations[n].changeAnimation = "swim"; //сменить анимацию на плавание
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernLow2";
	locations[n].models.always.cavernLow2 = "cavernLow2";
	
	locations[n].models.always.cavernLow1Crystals = "cavernLow2_crystals";
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
	locations[n].models.always.locators = "cavernLow2_locators";
	//Day
	locations[n].models.day.charactersPatch = "cavernLow2_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernLow2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	locations[n].underwater = true;
	Locations[n].QuestlockWeather = "Underwater";
	Locations[n].lockWeather = "Inside";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Carataska_cave";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "cave";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Judgement_dungeon_10";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	
	locations[n].DisableEncounters = true;
	locations[n].DisableOfficers = "1";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Аматике 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore9";
	locations[n].id.label = "Shore9";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore9";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].deadlocked = true;
	locations[n].questflower = 1;
	locations[n].Chestgennot = true; // не генерить сундуки
	//Models
	//Always
	locations[n].filespath.models = "locations\outside\Shores\grottoBig2";
	locations[n].models.always.grottoBig2 = "grottoBig2";
	locations[n].models.always.grottoBig2.sea_reflection = 1;
	Locations[n].models.always.seabed = "grottoBig2_sb";
	Locations[n].models.always.grassPatch = "grottoBig2_grass";
	//Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	locations[n].models.always.plan1 = "plan1";
	Locations[n].models.always.plan1.tech = "LocationWindows";
	locations[n].models.always.plan1.level = 10;	
	locations[n].models.always.plan2 = "plan2";
	Locations[n].models.always.plan2.tech = "LocationWindows";
	locations[n].models.always.plan2.level = 9;
	locations[n].models.always.locators = "grottoBig2_locators";	
	//Day
	locations[n].models.day.charactersPatch = "grottoBig2_patch";
	//Night
	locations[n].models.night.charactersPatch = "grottoBig2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Beliz_jungle_02";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Beliz_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8";
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
	locations[n].reload.l1.go = "Shore9";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore9";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tenotchitlan_Jungle_03";   //на теночитлан, где пирамида
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Tayasal_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].ItzaLand = true;
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
	//Day
	locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle3_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore_ship2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore_ship2";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_02";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_01";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.Reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_04";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.Reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_03";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.Reload3_back = 2.0;

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Tayasal_Jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_05";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_06";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
    locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_07";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_03";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_08";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Tayasal_jungle_06";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_04";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_08";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_04";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.Reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_11";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.Reload2_back = 2.0;
	locations[n].reload.l2.disable = true; //закрыто до поры patch-5

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_10";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.Reload3_back = 2.0;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_jungle_05";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_06";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_Jungle_09";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_jungle_09";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_Jungle_08";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_10";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_jungle_11";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "ExitTown";
	locations[n].locators_radius.reload.reload3_back = 2;
	locations[n].reload.l3.disable = true; //закрыто до поры

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Tayasal_jungle_10";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	locations[n].reload.l1.go = "Tayasal_Jungle_07";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_Jungle_09";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tayasal_CaveEntrance";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
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
	locations[n].reload.l1.go = "Tayasal_Grot";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_10";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tayasal_Grot";
	locations[n].id.label = "Grot";
    locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto1";
	locations[n].models.always.grotto1 = "grotto1";
	locations[n].models.always.grotto1alpha = "grotto1_alpha";
	Locations[n].models.always.grotto1alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto1alpha.level = 65532;
	locations[n].models.always.chest = "chest";	
	locations[n].models.always.locators = "grotto1_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "grotto1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
	//Day
	locations[n].models.day.charactersPatch = "grotto1_patch";
	//Night
	locations[n].models.night.charactersPatch = "grotto1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Tayasal_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Tayasal_jungle_11";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan";
	locations[n].ItzaLand = true;
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
	//Day
	locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle3_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Tayasal_jungle_07";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tayasal_jungle_09";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore5";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Tenochtitlan";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// лагуна Бисмуна-Рейя	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore118";
	locations[n].id.label = "Shore118";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore118";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].Chestgennot = true; // не генерить сундуки
	//Models
	//Always	
	locations[n].filespath.models = "locations\Outside\Shores\Shore12";
	Locations[n].models.always.shore12 = "rockshore";
	locations[n].models.always.shore12.sea_reflection = 1;
	Locations[n].models.always.shore12seabed = "rockshore_sb";
	Locations[n].models.always.locators = "rockshore_locators";
		
	Locations[n].models.always.grassPatch = "rockshore_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	//Day
	locations[n].models.day.charactersPatch = "rockshore_patch_day";
	//Night
	locations[n].models.night.charactersPatch = "rockshore_patch_day";		
	
	Locations[n].models.day.jumpPatch = "rockshore_jump_patch";
	Locations[n].models.night.jumpPatch = "rockshore_jump_patch"; 	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Iroquois_Jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 1;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_9";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 3.0;
	locations[n].locators_radius.reload.reload1_back = 1.5;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    locations[n].id = "Iroquois_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
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
	locations[n].reload.l1.go = "Shore118";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore118";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Iroquois_village";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Iroquois_CaveEntrance";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Iroquois_CaveEntrance";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].DisableEncounters = true;
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
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
	Locations[n].reload.l1.go = "Iroquois_Cave";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Grot";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Iroquois_Jungle_01";
	Locations[n].reload.l2.emerge = "reload3_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Iroquois_Cave";
	locations[n].id.label = "Grot";
                     locations[n].image = "loading\inside\cave.tga";
	//Sound
	locations[n].DisableEncounters = true;
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
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
	locations[n].reload.l1.go = "Iroquois_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Деревня ирокезов
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Iroquois_village";
	locations[n].id.label = "Village";
	Locations[n].image = "loading\Village.tga";
	locations[n].IroquoisVillage = true;
	//Sound
	locations[n].type = "Village";
	locations[n].islandId = "Mein";
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
	Locations[n].reload.l1.go = "Iroquois_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Iroquois_shack1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "shack";
	Locations[n].reload.l2.autoreload = "0";
	
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Iroquois_shack2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "shack";
	Locations[n].reload.l3.autoreload = "0";
	
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Iroquois_shack3";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "shack";
	Locations[n].reload.l4.autoreload = "0";

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №1 - большая
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Iroquois_shack1";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\Vigwam.tga";
	//Town sack
	locations[n].townsack = "Iroquois_village";
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
	locations[n].reload.l1.go = "Iroquois_village";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №2
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Iroquois_shack2";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\Vigwam.tga";
	//Town sack
	locations[n].townsack = "Iroquois_village";
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
	//locations[n].models.night.locators = "Hut_2_inside_ln";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Iroquois_village";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №3
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Iroquois_shack3";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\Vigwam.tga";
	//Town sack
	locations[n].townsack = "Iroquois_village";
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
	//locations[n].models.night.locators = "Hut_2_inside_ln";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Iroquois_village";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	n = n + 1;
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// лагуна Ауловер	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore117";
	locations[n].id.label = "Shore117";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore117";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Beliz";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.go = "Beliz_jungle_001";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Beliz";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Beliz_Jungle_001";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Beliz_Loguna_jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Beliz_Loguna_exit";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
      locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore117";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore117";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли 01
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Beliz_Loguna_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	//Models
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle3";
	Locations[n].models.always.jungle = "jungle3";	
	Locations[n].models.always.locators = "jungle3_locators";
	Locations[n].models.always.lcommon = "Jungle3_lcommon";
	Locations[n].models.always.locators = "Jungle3_mine_locators";
	Locations[n].models.always.locators = "Jungle3_Dollylocators";			
	Locations[n].models.always.grassPatch = "jungle3_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

                        Locations[n].models.always.somemodel1 = "bracing";
                        Locations[n].models.always.somemodel1.locator.group = "Item";
                        Locations[n].models.always.somemodel1.locator.name = "button01";
                        Locations[n].models.always.somemodel2 = "calendar";
                        Locations[n].models.always.somemodel2.locator.group = "Item";
                        Locations[n].models.always.somemodel2.locator.name = "button01";
                        Locations[n].models.always.somemodel3 = "dolly_F";
                        Locations[n].models.always.somemodel3.locator.group = "Item";
                        Locations[n].models.always.somemodel3.locator.name = "button01";

	Locations[n].models.always.l4 = "Jungle3_wall";
	Locations[n].models.always.l4.tech = "DLightModel";
			
	
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Beliz_Jungle_001";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 3.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Beliz_Cavern";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Animist Cave";
                        locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Beliz_Loguna_Grot";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Beliz_Loguna_Grot";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Beliz_Grot";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Beliz_Loguna_jungle_01";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Beliz_Grot";
	locations[n].id.label = "";
  locations[n].image = "loading\inside\Crot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Beliz_Loguna_Grot";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Leviathan Rock.";
	Locations[n].items.randitem1 = "blade300";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     	Locations[n].id = "Beliz_Loguna_exit";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Beliz_Jungle_001";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Beliz_Loguna_Cave_Exit";
	Locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Bel_Jungle_02";
	Locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore35";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Заброшенная шахта	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Beliz_Cavern";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].townsack = "Beliz";
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
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Beliz_Loguna_jungle_01";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Beliz_Loguna_Cave_Exit";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Beliz_Loguna_Cave";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Beliz_Loguna_exit";
	Locations[n].reload.l2.emerge = "reload2_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Beliz_Loguna_Cave";
	locations[n].id.label = "Cave";
     locations[n].image = "loading\inside\grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Beliz_Loguna_Cave_Exit";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].items.randitem1 = "blade38";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Bel_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Bel_jungle_03";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].reload.l2.disable = 0;  //закроем, но связка пусть будет для квестов.
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Beliz_Loguna_exit";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    	locations[n].id = "Muhachi_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Bel_Jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "MuhachiShore";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Muhachi_Cave";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Muhachi_Cave";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Muhachi_Grot";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Muhachi_Jungle_02";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Grot";
	locations[n].id.label = "Pyramid1Inside";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";	
	//Sound
	locations[n].type = "teno_inside";
	locations[n].id.label = "Incas Temple";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].islandIdAreal = "Tenotchitlan";
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Inside\Pyramid1Inside\";
	//Always
	Locations[n].models.always.pyramid1 = "Pyramid1Inside";
	Locations[n].models.always.pyramid2 = "Pyramid1_treasure";
	Locations[n].models.always.pyramid3 = "Pyramid1_other";
	Locations[n].models.always.locators = "Pyramid1_locators";
	Locations[n].models.always.pyramid1gold = "Pyramid1_gold";
	Locations[n].models.always.pyramid1gold.reflection = 0.15;
	Locations[n].models.always.pyramid1gold.tech = "EnvironmentShader";
	//Day
	locations[n].models.day.charactersPatch = "Pyramid1_patch";
	//Night
	locations[n].models.night.charactersPatch = "Pyramid1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	
	// лари, сундуки
	locations[n].private1.items.icollection = 10;
	locations[n].private1.items.jewelry14 = 500;
	locations[n].private1.items.jewelry15 = 400;
	locations[n].private1.items.Totem_001 = 1;
	
	locations[n].private2.items.icollection = 10;
	locations[n].private2.items.jewelry2 = 1000;
	locations[n].private2.items.jewelry10 = 100;
	locations[n].private2.items.Totem_002 = 1;
	
	locations[n].private3.items.icollection = 10;
	locations[n].private3.items.jewelry16 = 300;
	locations[n].private3.items.jewelry17 = 600;
	locations[n].private3.items.Totem_003 = 1;
	
	locations[n].private4.items.icollection = 10;
	locations[n].private4.items.jewelry18 = 450;
	locations[n].private4.items.jewelry20 = 700;
	locations[n].private4.items.Totem_004 = 1;
	
	locations[n].private5.items.icollection = 10;
	locations[n].private5.items.jewelry3 = 1000;
	locations[n].private5.items.Totem_005 = 1;
	
	locations[n].private6.items.icollection = 10;
	locations[n].private6.items.jewelry4 = 1000;
	locations[n].private6.items.Totem_006 = 1;
	
	locations[n].private7.items.icollection = 10;
	locations[n].private7.items.jewelry14 = 500;
	locations[n].private7.items.Totem_007 = 1;
	
	locations[n].private8.items.icollection = 10;
	locations[n].private8.items.jewelry1 = 1000;
	locations[n].private8.items.jewelry7 = 100;
	locations[n].private8.items.Totem_008 = 1;
	
	locations[n].private9.items.icollection = 10;
	locations[n].private9.items.jewelry21 = 250;
	locations[n].private9.items.jewelry23 = 750;
	locations[n].private9.items.Totem_009 = 1;
	
	locations[n].private10.items.icollection = 100;
	locations[n].private10.items.Totem_0010 = 1;
	
	locations[n].private11.items.icollection = 100;
	locations[n].private11.items.Totem_0011 = 1;
	
	locations[n].private12.items.icollection = 100;
	locations[n].private12.items.Totem_0012 = 1;
	
	locations[n].private13.items.icollection = 10;
	locations[n].private13.items.jewelry22 = 2000;
	locations[n].private13.items.Totem_0013 = 1;
	
	locations[n].private14.items.icollection = 10;
	locations[n].private14.items.jewelry8 = 1000;
	locations[n].private14.items.Totem_0014 = 1;
	
	locations[n].private15.items.icollection = 10;
	locations[n].private15.items.jewelry9 = 500;
	locations[n].private15.items.jewelry19 = 300;
	locations[n].private15.items.Totem_0015 = 1;
	
	locations[n].private16.items.potion2 = 1000;
	locations[n].private16.items.potion3 = 1000;
	locations[n].private16.items.potion4 = 1000;
	locations[n].private16.items.potion7 = 10;
	locations[n].private16.items.berserker_potion = 20;
	
	locations[n].private17.items.icollection = 100;
	
	locations[n].private18.items.jewelry5 = 2000;
	
	locations[n].private19.items.jewelry6 = 4000;
	
	locations[n].private20.items.icollection = 200;
	locations[n].private20.items.jewelry5 = 5000;
	locations[n].private20.items.jewelry6 = 10000;
	
	locations[n].private21.items.mushket_10 = 1;
	locations[n].private21.items.shotgun_cartridge = 1000;
	locations[n].private21.items.GunCap_colt = 1000;

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Muhachi_Cave";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	Locations[n].locators_radius.item.item1 = 1.1;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Dunes_Jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Muhachi_Jungle_04";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////// Джунгли	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Dunes_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].DisableEncounters = true;
	locations[n].Chestgennot = true; // не генерить сундуки
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Pirl";
	Locations[n].models.always.pirl = "pirl";	
	Locations[n].models.always.locators = "pirl_locators";		
	Locations[n].models.always.grassPatch = "pirl_grass";
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
	locations[n].models.day.charactersPatch = "pirl_patch";
	locations[n].models.day.fonar = "pirl_fd";
	//Night
	locations[n].models.night.charactersPatch = "pirl_patch";	
	locations[n].models.night.fonar = "pirl_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Muhachi_Jungle_03";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Jungle_house";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом в джунглях
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jungle_house";
	locations[n].id.label = "Jungle house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Beliz";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Beliz";
	locations[n].DisableEncounters = true;
	//locations[n].fastreload = "";
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
	Locations[n].models.day.mediumhouse02rand= "mediumhouse02_rand";
	locations[n].models.day.charactersPatch = "mediumhouse02_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
                         //Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Dunes_Jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	n = n + 1;	
	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_03";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_05";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                locations[n].id = "Muhachi_Jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_04";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_06";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_06";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_05";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_07";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore119";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore119";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Берег Ла-Эсперанза	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore119";
	locations[n].id.label = "Shore119";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore119";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].AztecLand = true;
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

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muhachi_Jungle_06";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 10;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Bel_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8";
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
	locations[n].reload.l1.go = "Bel_Jungle_02";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Tenochtitlan_1";   
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_06";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore120";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore120";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Залив Акахутла	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore120";
	locations[n].id.label = "Shore120";
	locations[n].worldmap = "Shore120";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_07";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 1;
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Muhachi_Jungle_10";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
                   locations[n].locators_radius.reload.reload2_back = 1.5;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_10";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Shore120";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore120";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Shore122";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore122";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Muhachi_Jungle_08";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Muhachi_Jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].DisableEncounters = true;
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_10";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore121";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore121";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Лагуна Де-Оломега	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore121";
	locations[n].id.label = "Shore121";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore121";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].AztecLand = true;
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
	locations[n].reload.l1.go = "Muhachi_Jungle_08";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Бухта Хутьяп 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore122";
	locations[n].id.label = "Shore122";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore122";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Pearl";
	locations[n].AztecLand = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\outside\Shores\grottoBig1";
	locations[n].models.always.grottoBig1 = "grottoBig1";
	locations[n].models.always.grottoBig1.sea_reflection = 1;
	Locations[n].models.always.seabed = "grottoBig1_sb";
	Locations[n].models.always.grassPatch = "grottoBig1_grass";
	//Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	locations[n].models.always.plan1 = "plan1";
	Locations[n].models.always.plan1.tech = "LocationWindows";
	locations[n].models.always.plan1.level = 10;	
	locations[n].models.always.plan2 = "plan2";
	Locations[n].models.always.plan2.tech = "LocationWindows";
	locations[n].models.always.plan2.level = 9;

	Locations[n].models.always.Waterfall1 = "water";
	Locations[n].models.always.Waterfall1.tech = "LocationWindows";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.Waterfall2 = "cfall";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
	Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 49;
	locations[n].models.always.locators = "grottoBig1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "grottoBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "grottoBig1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Muhachi_Jungle_10";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;
	n = n + 1;

	
	return n;
}
