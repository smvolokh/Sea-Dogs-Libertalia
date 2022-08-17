
int LocationInitJamaica(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "PortRoyal";
	
	locations[n].townsack = "PortRoyal";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	
	locations[n].filespath.models = "locations\Town_PortRoyal\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "PortRoyal";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "PortRoyal_signsA";
	locations[n].models.always.seabed = "PortRoyal_sb";
	locations[n].models.always.locators = "PortRoyal_locators";
	locations[n].models.always.grassPatch = "PortRoyal_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//River
	locations[n].models.always.Waterfall1 = "river1";
	locations[n].models.always.Waterfall1.uvslide.v0 = 0.2;
    locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall1.level = 50;
	
	locations[n].models.always.Waterfall2 = "river2";
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall2.level = 49;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.3;
	
	locations[n].models.always.L2 = "Barracks_Door";
    locations[n].models.always.L2.tech = "DLightModel";

	//Day
	locations[n].models.day.fonar = "PortRoyal_fd";
	locations[n].models.day.charactersPatch = "PortRoyal_patch_day";
	locations[n].models.day.rinok = "PortRoyal_rinok";
	//Night
	locations[n].models.night.fonar = "PortRoyal_fn";
	locations[n].models.night.charactersPatch = "PortRoyal_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortRoyal_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortRoyal_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "PortRoyal_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "PortRoyal_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "PortRoyal_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "PortRoyal_Bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "PortRoyal_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

 	locations[n].reload.l91.name = "reload91";
	locations[n].reload.l91.go = "PortRoyal_SecBrRoom";
	locations[n].reload.l91.emerge = "reload2";
	locations[n].reload.l91.autoreload = "0";
	locations[n].reload.l91.label = "Brothel";

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "PortRoyal_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "PortRoyal_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "PortRoyal_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации, 9 номеров.

	locations[n].reload.l11.name = "houseSp1";
	locations[n].reload.l11.go = "PortRoyal_houseSp1";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "House";
	
	locations[n].reload.l12.name = "houseSp4";
	locations[n].reload.l12.go = "PortRoyal_houseSp4";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "Loxly_house";
	locations[n].reload.l12.close_for_night = 1;

	// --> Комоны, загрушки. Номера с начинаются с 20.
   
	locations[n].reload.l20.name = "houseF1";
	locations[n].reload.l20.go = "PortRoyal_HouseHut5";
	locations[n].reload.l20.emerge = "reload1_back";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";
    
 	locations[n].reload.l21.name = "houseSp2";
	locations[n].reload.l21.go = "CommonStoneHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseSp3";
	locations[n].reload.l22.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseS1";
	locations[n].reload.l23.go = "PortRoyal_houseS1";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "Morgan's House";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_tavern";
	locations[n].id.label = "Tavern22";
	Locations[n].image = "loading\inside\tavern_eng.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\tavern03\";
	locations[n].models.always.tavern = "tavern03";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern03_locators";
	locations[n].models.always.window = "tavern03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "tavern03_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern03_patch";
	//Environment
	locations[n].environment.weather = "true";
    locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortRoyal_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\store02\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.camdetector.camera1 = 5;
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_storeRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "CommonPackhouse_1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната в магазине
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_storeRoom";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse10";
	locations[n].models.always.house = "mediumhouse10";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "mediumhouse10_PRlocators";
	locations[n].models.night.locators = "mediumhouse10_PRNlocators";

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
	locations[n].reload.l1.go = "PortRoyal_store";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "store";
	
	locations[n].locators_radius.item.item1 = 0.8;
	locations[n].locators_radius.item.item2 = 1.2;
	locations[n].locators_radius.item.item3 = 0.8;
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank02\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].models.always.locators = "Bank02_locators";
	locations[n].models.always.store = "Bank02";
	locations[n].models.always.window = "bank02_windows";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload8";
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
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard03\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].models.always.locators = "Shipyard03_locators";
	locations[n].models.always.shipyard = "Shipyard03";
	locations[n].models.always.shipyard.level = 65538;
	locations[n].models.always.window = "shipyard03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Shipyard03_patch";
	//Night
	locations[n].models.night.charactersPatch = "Shipyard03_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_Packhouse";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "packhouse";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// СКЛАД НА ВЕРФИ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	locations[n].id = "PortRoyal_Packhouse";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_Shipyard";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "shipyard";
	n = n + 1;


 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence03";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
 	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.locators = "Residence03_locators";
	locations[n].models.always.l1 = "Residence03";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence03_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence03_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_RoomTownhall";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///// приемная лорда Виндзора
	///////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Roomtownhall";
	locations[n].id.label = "TownhallRoom";
	locations[n].filespath.models = "locations\inside\Residence06";
	locations[n].image = "loading\inside\BigHouse_1.tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
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
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;

	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Room";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
    //Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchInside2";
	locations[n].models.always.churchInside2 = "churchInside2";
	locations[n].models.always.churchInside2.level = 65538;
	locations[n].models.always.locators = "churchInside2_locators";
	
	locations[n].models.always.backgroundInsides = "backgroundInsides";
	locations[n].models.always.backgroundInsides.level = 65529;
	
	Locations[n].models.always.churchInside2windows = "churchInside2_windows";
	Locations[n].models.always.churchInside2windows.tech = "LocationWindows";
	locations[n].models.always.churchInside2windows.level = 65539;
	
	Locations[n].models.always.churchInside2alpha = "churchInside2_alpha";
	Locations[n].models.always.churchInside2alpha.tech = "LocationWindows";
	locations[n].models.always.churchInside2alpha.level = 65540;
	
	Locations[n].models.always.churchInside2gold = "churchInside2_gold";
	Locations[n].models.always.churchInside2gold.reflection = 0.6;
	Locations[n].models.always.churchInside2gold.tech = "EnvironmentShader";
	locations[n].models.always.churchInside2gold.level = 65541;
	//Day
	locations[n].models.day.charactersPatch = "churchInside2_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInside2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	locations[n].brothel = true;
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortRoyal_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PortRoyal_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
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
	locations[n].reload.l1.go = "PortRoyal_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_town";
	locations[n].reload.l2.emerge = "reload91";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом рядом с магазином
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_houseSp1";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\largehouse_" + rand(1) + ".tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.largehouse01 = "largehouse01";
	locations[n].models.always.largehouse01.level = 65538;
	locations[n].models.day.locators = "largehouse01_locators";
	locations[n].models.night.locators = "largehouse01_Nlocators";

	Locations[n].models.always.largehouse01windows = "largehouse01_windows";
	Locations[n].models.always.largehouse01windows.tech = "LocationWindows";
	locations[n].models.always.largehouse01windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.largehouse01rand= "largehouse01_rand";
	locations[n].models.day.charactersPatch = "largehouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_houseSp1Room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната в доме
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_houseSp1Room";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse02";
	locations[n].models.always.largehouse02 = "largehouse02";
	locations[n].models.always.largehouse02.level = 65538;
	locations[n].models.day.locators = "largehouse02_PRlocators";
	locations[n].models.night.locators = "largehouse02_PRNlocators";

	Locations[n].models.always.largehouse02windows = "largehouse02_windows";
	Locations[n].models.always.largehouse02windows.tech = "LocationWindows";
	locations[n].models.always.largehouse02windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.largehouse02rand= "largehouse02_rand";
	locations[n].models.day.charactersPatch = "largehouse02_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_houseSp1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	n = n + 1;
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Контора Альберта Локсли
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_houseSp4";
	locations[n].id.label = "Loxly_house";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Jamaica";
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
	locations[n].models.night.locators = "BigHouseBack_locators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseSp4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonBedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	locations[n].box3.QuestClosed = true;
	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Моргана	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_houseS1"; // c переходом в малую резиденцию
	locations[n].id.label = "Morgan's House";
	locations[n].image = "loading\inside\smallresidence_" + rand(1) + ".tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouse02\";
	locations[n].models.always.models = "BigHouse02";
	locations[n].models.always.models.level = 65538;
	locations[n].models.always.boxes = "BigHouse02_boxes";
	locations[n].models.always.boxes.level = 65539;
	locations[n].models.always.window = "BigHouse02_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65540;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "BigHouse02_patch";
	locations[n].models.day.locators = "BigHouse02_PrLocators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse02_patch";
	locations[n].models.night.locators = "BigHouse02_PrNlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonBedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].private1.key = "keyMorgan";
	locations[n].private1.key.delItem = true;
	locations[n].private1.money = 5000;
	locations[n].private1.items.blade_25 = 1; // Рапира Моргана
	locations[n].private1.items.cirass4 = 1; // Миланский панцирь
	locations[n].private1.items.suit4 = 1; // Костюм Лампорта
	
	locations[n].private2.key = "keyMorgan";
	locations[n].private2.key.delItem = true;
	locations[n].private2.money = 10000;
	locations[n].private2.items.topor_01 = 1; // Макуауитль
	locations[n].private2.items.cirass3 = 1; // Парадная кираса
	locations[n].private2.items.suit_1 = 1; // французский мундир
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "PortRoyal_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "PortRoyal";
    locations[n].parent_colony = "PortRoyal";
 	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
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
	Locations[n].reload.l1.go = "PortRoyal_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_HouseHut5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "PortRoyal";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "PortRoyal_fort";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "PortRoyal Fort";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Jamaica_jungle_01";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "PortRoyal_Graveyard";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "1";
	locations[n].reload.l4.label = "Graveyard";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// городское кладбище
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_Graveyard";
	locations[n].id.label = "Graveyard";
	locations[n].image = "loading\Cemetery_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Mayak3";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Mayak3";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortRoyal_ExitTown";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "ExitTown";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PortRoyal_KeepersHouse";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "House";
	
	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "PortRoyal_CryptBig1";
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
	locations[n].id = "PortRoyal_KeepersHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_Graveyard";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	n = n + 1;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 1
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortRoyal_CryptBig1";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_Graveyard";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Common_CryptBig2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Crypt";
	
	locations[n].private1.key = "key_archy";
	locations[n].private1.key.delItem = true;
	locations[n].private1.items.arrowway = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Маяк Ямайки
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Mayak3";
	locations[n].id.label = "Mayak3";
	locations[n].worldmap = "Mayak3";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "mayak";
	locations[n].islandId = "Jamaica";	
	locations[n].soldiers = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\LighthouseJamaica";
	Locations[n].models.always.lighthouseJamaica = "lighthouseJamaica";
	locations[n].models.always.lighthouseJamaica.sea_reflection = 1;
	Locations[n].models.always.lighthouseJamaicaSeabed = "lighthouseJamaica_sb";
	Locations[n].models.always.locators = "lighthouseJamaica_locators";
	
	Locations[n].models.always.dooropen = "lighthouseJamaica_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouseInside_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouseJamaica_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouseJamaica_winday";
	locations[n].models.day.fonar = "lighthouseJamaica_fd";
	locations[n].models.day.charactersPatch = "lighthouseJamaica_patch";
	Locations[n].models.day.jumpPatch = "lighthouseJamaica_jamp";
	
	locations[n].models.day.glassinday = "lighthouseInside_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouseInside_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;	
	//Night	
	locations[n].models.night.volumeLight= "lighthouseJamaica_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouseJamaica_fn";
	locations[n].models.night.winnight = "lighthouseJamaica_winnight";
	locations[n].models.night.winnight.tech = "LighthouseLight";
	locations[n].models.night.winnight.level = 66529;
	locations[n].models.night.charactersPatch = "lighthouseJamaica_patch";
	Locations[n].models.night.jumpPatch = "lighthouseJamaica_jamp";
	
	locations[n].models.night.glassinnight = "lighthouseInside_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouseInside_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouseInside_fonaronnight";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortRoyal_Graveyard";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Graveyard";
	locations[n].locators_radius.reload.reload1_back = 3.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 12.0;

	locations[n].locators_radius.item.detector1 = 2.6;
	locations[n].locators_radius.item.detector2 = 2.6;
	locations[n].locators_radius.item.detector3 = 2.6;
	locations[n].locators_radius.item.detector4 = 2.6;
	locations[n].locators_radius.item.detector5 = 2.6;
	locations[n].locators_radius.item.detector6 = 2.6;
	locations[n].DisableEncounters = true;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_Jungle_07";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Jamaica_Grot";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica_jungle_07";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_Grot";
	locations[n].id.label = "Grot";
    locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Jamaica_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Shore36";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore36";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica_Jungle_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_Jungle_01";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Портленд
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore36";
	locations[n].id.label = "Shore36";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore36";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore08";
	Locations[n].models.always.shore08 = "shore08";
	locations[n].models.always.shore08.sea_reflection = 1;
	Locations[n].models.always.shore08seabed = "shore08_sb";
	Locations[n].models.always.locators = "shore08_locators";		
	Locations[n].models.always.grassPatch = "shore08_grass";
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
	locations[n].models.day.charactersPatch = "shore08_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore08_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica_jungle_02";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     locations[n].id = "Jamaica_Jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "Jamaica";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "FortOrange_ExitTown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Jamaica_jungle_02";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore35";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore35";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Порт Саванна-ла-мар
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_port";
	locations[n].id.label = "FortOrange Port";
	locations[n].image = "loading\seaStand.tga";
	locations[n].worldmap = "FortOrange_port";
	//Sound
	locations[n].type = "town";
	Locations[n].townsack = "FortOrange";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_SavannaLaMar\Port\";
	locations[n].models.always.town = "SavannaLaMarport";
	locations[n].models.always.locators = "SavannaLaMarport_locators";
	locations[n].models.always.seabed = "SavannaLaMarport_sb";
	locations[n].models.always.grassPatch = "SavannaLaMarport_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;
	//Day
	locations[n].models.day.fonar = "SavannaLaMarport_fd";
	locations[n].models.day.charactersPatch = "SavannaLaMarport_patch_day";
	locations[n].models.day.rinok = "SavannaLaMarport_rinok";
 	//Night
	locations[n].models.night.fonar = "SavannaLaMarport_fn";
	locations[n].models.night.charactersPatch = "SavannaLaMarport_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Саванна-ла-мар	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                Locations[n].id = "FortOrange_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "FortOrange";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 8; 
	//Sound
	locations[n].type = "town";
                locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_SavannaLaMar\Town\";
	locations[n].models.always.town = "SavannaLaMar";
	locations[n].models.always.locators = "SavannaLaMar_locators";
	locations[n].models.always.grassPatch = "SavannaLaMar_grass";
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
	locations[n].models.day.fonar = "SavannaLaMar_fd";
	locations[n].models.day.charactersPatch = "SavannaLaMar_patch_day";
 	//Night
	locations[n].models.night.fonar = "SavannaLaMar_fn";
	locations[n].models.night.charactersPatch = "SavannaLaMar_patch_night";

	Locations[n].models.day.jumppatch = "SavannaLaMar_jump_patch";
	Locations[n].models.night.jumppatch = "SavannaLaMar_jump_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload1_back"; 
	Locations[n].reload.l1.go = "FortOrange_ExitTown";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1 = 1.8;

	Locations[n].reload.l2.name = "gate_back"; 
	Locations[n].reload.l2.go = "FortOrange_port";
	Locations[n].reload.l2.emerge = "reload2_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "FortOrange Port";
	locations[n].locators_radius.reload.reload1 = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "FortOrange_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "FortOrange_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload13";
	locations[n].reload.l5.go = "FortOrange_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "FortOrange_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "FortOrange_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload10_back";
	locations[n].reload.l8.go = "FortOrange_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload11";
	locations[n].reload.l9.go = "FortOrange_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";
	//locations[n].reload.l9.disable = 1;

	locations[n].reload.l10.name = "reload12";
	locations[n].reload.l10.go = "FortOrange_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

    // --> Квестовые локации.

                 //Дом священника
	locations[n].reload.l11.name = "reload8";
	locations[n].reload.l11.go = "CommonStoneHouse";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "House_pressis";
                 
	locations[n].reload.l12.name = "reload9";
	locations[n].reload.l12.go = "CommonPirateHouse";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "";

	locations[n].reload.l13.name = "reload5_back";
	locations[n].reload.l13.go = "CommonRoom_MH5";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "House";
	
	
	locations[n].reload.l14.name = "reload8_back";
	locations[n].reload.l14.go = "House_HaryHooms";
	locations[n].reload.l14.emerge = "reload1";
	locations[n].reload.l14.autoreload = "0";
	locations[n].reload.l14.label = "House HaryHooms";
                
	locations[n].reload.l15.name = "reload17";
	locations[n].reload.l15.go = "FortOrange_House11";
	locations[n].reload.l15.emerge = "reload1";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "House";

	locations[n].reload.l16.name = "reload15";
	locations[n].reload.l16.go = "FortOrange_crypt2";
	locations[n].reload.l16.emerge = "reload1";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "crypt";
	LAi_LocationFightDisable(&Locations[n], true);

	locations[n].reload.l17.name = "reload18";
	locations[n].reload.l17.go = "HouseMonkJamaica";
	locations[n].reload.l17.emerge = "reload1_back";
	locations[n].reload.l17.autoreload = "0";
	locations[n].reload.l17.label = "Church";
	LAi_LocationFightDisable(&Locations[n], true);

    // --> Комоны, загрушки. Номера с начинаются с 20.

	locations[n].reload.l20.name = "reload10";
	locations[n].reload.l20.go = "FortOrange_houseSp2";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";
                
	locations[n].reload.l21.name = "reload19";
	locations[n].reload.l21.go = "CommonRoom_MH4";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l23.name = "reload16";
	locations[n].reload.l23.go = "CommonPirateHouse";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "reload9_back";
	locations[n].reload.l24.go = "CommonRoom_MH10";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "reload14";
	locations[n].reload.l25.go = "CommonRoom_MH3";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l22.name = "reload5";
	locations[n].reload.l22.go = "CommonHut";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";	

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Таверна Саванна-ла-мар	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 	locations[n].id = "FortOrange_tavern";
	locations[n].id.label = "Tavern31";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\tavern06\";
	locations[n].models.always.tavern = "tavern06";
	Locations[n].models.always.tavern.tech = "DLightModel";	
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern06_locators";
	Locations[n].models.always.locators.tech = "DLightModel";	
	locations[n].models.always.window = "tavern06_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Tavern06_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern06_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload4_back";
	locations[n].reload.l1.autoreload = "0";
                locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortOrange_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);

    ////////////////////////==> подсобка таверны
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "FortOrange_sklad";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "sklad";
	n = n + 1;

	Locations[n].id = "FortOrange_sklad";
	locations[n].id.label = "sklad";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad02";
	locations[n].models.always.locators = "sklad02_locators";
	locations[n].models.always.modelSklad = "sklad02";
	locations[n].models.always.modelSklad.level = 65538;
	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "sklad02_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad02_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "FortOrange_tavern";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "tavern31";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната в таверне наверху, Саванна-ла-мар	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "FortOrange_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_tavern";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Магазин Саванна-ла-мар
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_store";
	locations[n].id.label = "Store";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload6_back"; 
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
	// Резиденция Саванна-ла-мар
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	// стража
	locations[n].soldiers = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence01";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload3"; //кабинет направо от входа
	locations[n].reload.l2.go = "FortOrange_TownhallRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "TownhallRoom";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "CommonResidence_2";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	locations[n].brothel = true;	
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "Brothel_window";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload11";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortOrange_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "FortOrange_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
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
	locations[n].reload.l1.go = "FortOrange_Brothel";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ResBedRoom\";
	locations[n].models.always.houseResBedRoom = "bed";
	locations[n].models.always.locators = "bed_l";
	locations[n].models.always.window = "bed_w";
	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "bed_p";
	//Night
	locations[n].models.night.charactersPatch = "bed_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortOrange_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БАНК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload10_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;
	
	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church_1.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\church_IM\";
	Locations[n].models.always.l1 = "church_IM";
	Locations[n].models.always.locators = "church_IM_locators";
	Locations[n].models.always.window = "church_IM_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "church_IM_patch";
	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "church_IM_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload7_back";
	locations[n].reload.l1.autoreload = "0";
     locations[n].reload.l1.label = "Street";	

	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Монаха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseMonkJamaica";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload18";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_crypt2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload15";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload12";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload13";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;
	
	/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ ПИРАТА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "House_HaryHooms";
	locations[n].id.label = "House HaryHooms";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Bridgetown";
	locations[n].islandId = "Barbados";
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

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "FortOrange_town";
	Locations[n].reload.l1.emerge = "reload8_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "HaryHooms_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;
	*/
	
	// Дом Гарри Хомса	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "House_HaryHooms";
	locations[n].id.label = "House HaryHooms";
	Locations[n].image = "loading\inside\smallresidence.tga";
	//Town sack
	Locations[n].townsack = "FortOrange";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
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
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "FortOrange_town";
	Locations[n].reload.l1.emerge = "Reload8_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  Дом Самуила	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "House_Samuel";
	locations[n].id.label = "House Samuel";
	locations[n].image = "loading\inside\flamhouse.tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload19";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната отдыха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HaryHooms_upstairs";
	locations[n].id.label = "Bedroom01";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ResBedRoom\";
	locations[n].models.always.houseResBedRoom = "bed";
	locations[n].models.always.locators = "bed_l";
	locations[n].models.always.window = "bed_w";
	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "bed_p";
	//Night
	locations[n].models.night.charactersPatch = "bed_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "House_HaryHooms";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House HaryHooms";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом F3	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_HouseSp2";
	locations[n].filespath.models = "locations\inside\FlamHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\flamhouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "CommonRoom_MH3";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l3.name = "reload4";
	locations[n].reload.l3.go = "CommonRoom_MH4";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";

	locations[n].reload.l4.name = "reload2";
	locations[n].reload.l4.go = "CommonRoom_MH4";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Room";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Джимми Хиггинса	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortOrange_House11";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse01";
	locations[n].models.always.mediumhouse01 = "mediumhouse01";
	locations[n].models.always.mediumhouse01.level = 65538;
	locations[n].models.day.locators = "mediumhouse01_locators";
	locations[n].models.night.locators = "mediumhouse01_Nlocators";

	Locations[n].models.always.mediumhouse01windows = "mediumhouse01_windows";
	Locations[n].models.always.mediumhouse01windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse01windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse01rand= "mediumhouse01_rand";
	locations[n].models.day.charactersPatch = "mediumhouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
    //Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload17";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Изба грузчика	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "CommonHut";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "FortOrange";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortOrange";
 	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "FortOrange_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// выход из Саванна-ла-мар	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "FortOrange_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	Locations[n].townsack = "FortOrange";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
locations[n].filespath.models = "locations\Gothic\Town_SavannaLaMar\Exit\";
	Locations[n].models.always.locators = "SavannaLaMarExit_l";
	Locations[n].models.always.exit = "SavannaLaMarExit";
	Locations[n].models.always.grassPatch = "SavannaLaMarExit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.fonar = "SavannaLaMarExit_fd";
	Locations[n].models.day.charactersPatch = "SavannaLaMarExit_p";
	//Night
	Locations[n].models.night.fonar = "SavannaLaMarExit_fn";
	Locations[n].models.night.charactersPatch = "SavannaLaMarExit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "Reload1_back";
	locations[n].reload.l1.go = "Jamaica_Jungle_03";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

   	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "FortOrange_town";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Street";
	locations[n].locators_radius.reload.reload3 = 1.8;
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Блэк-Ривер	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore35";
	locations[n].id.label = "Shore35";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore35";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore10";
	Locations[n].models.always.shore10 = "shore10";
	locations[n].models.always.shore10.sea_reflection = 1;
	Locations[n].models.always.shore10seabed = "shore10_sb";
	Locations[n].models.always.locators = "shore10_locators";
		
	Locations[n].models.always.grassPatch = "shore10_grass";
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
	locations[n].models.day.charactersPatch = "shore10_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore10_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica_Jungle_03";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// мыс Саут-Негрил	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore84";
	locations[n].id.label = "Shore84";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore84";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Jamaica_Jungle_10"; 
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// залив Монтего-Бей	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore85";
	locations[n].id.label = "Shore85";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore85";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "FortOrange";
	locations[n].questflower = 1;
	locations[n].Chestgennot = true; // не генерить сундуки
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
	locations[n].reload.l1.go = "Jamaica_Jungle_10"; 
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Фалмут	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore86";
	locations[n].id.label = "Shore86";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore86";
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Jamaica_jungle_09";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Аннотто-Бей	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore87";
	locations[n].id.label = "Shore87";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore87";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "PortRoyal";
	locations[n].fennisgrass = 1;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore10";
	Locations[n].models.always.shore10 = "shore10";
	locations[n].models.always.shore10.sea_reflection = 1;
	Locations[n].models.always.shore10seabed = "shore10_sb";
	Locations[n].models.always.locators = "shore10_locators";
		
	Locations[n].models.always.grassPatch = "shore10_grass";
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
	locations[n].models.day.charactersPatch = "shore10_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore10_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica_jungle_04";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_9";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Очо-Риос	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore88";
	locations[n].id.label = "Shore88";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore88";
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore02";
	Locations[n].models.always.shore02 = "shore02";
	locations[n].models.always.shore02.sea_reflection = 1;
	Locations[n].models.always.shore02seabed = "shore02_sb";
	Locations[n].models.always.locators = "shore02_locators";
		
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica_jungle_08";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_10";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////мыс Морант	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore90";
	locations[n].id.label = "Shore90";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore90";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_Jungle_01";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_11";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Jamaica";
	locations[n].filespath.models = "locations\Town_PortAntonio\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Town sack
	locations[n].townsack = "PortAntonio";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "PortAntonio";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "PortAntonio_signsA";
	locations[n].models.always.seabed = "PortAntonio_sb";
	locations[n].models.always.locators = "PortAntonio_locators";
	locations[n].models.always.grassPatch = "PortAntonio_grass";
	
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
	Locations[n].models.always.MillFan.rotate.z = 0.2;

	//Day
	locations[n].models.day.fonar = "PortAntonio_fd";
	locations[n].models.day.charactersPatch = "PortAntonio_patch_day";
	locations[n].models.day.rinok = "PortAntonio_rinok";
	//Night
	locations[n].models.night.fonar = "PortAntonio_fn";
	locations[n].models.night.charactersPatch = "PortAntonio_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica";
	locations[n].reload.l1.emerge = "reload_12";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica";
	locations[n].reload.l2.emerge = "reload_12";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortAntonio_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortAntonio_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "PortAntonio_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "PortAntonio_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "PortAntonio_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "PortAntonio_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "PortAntonio_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

 	locations[n].reload.l91.name = "reload91";
	locations[n].reload.l91.go = "PortAntonio_SecBrRoom";
	locations[n].reload.l91.emerge = "reload2";
	locations[n].reload.l91.autoreload = "0";
	locations[n].reload.l91.label = "Brothel";

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "PortAntonio_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "PortAntonio_Rudnik";
	locations[n].reload.gate.emerge = "reload6";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "PortAntonioRudnik";
	
	locations[n].reload.jail.name = "reloadPr1";
	locations[n].reload.jail.go = "PortAntonio_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";
	
    // --> Квестовые локации.
	locations[n].reload.l11.name = "basement1";
	locations[n].reload.l11.go = "PortAntonio_crypt1";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "crypt";

	locations[n].reload.l12.name = "reload_jail";
	locations[n].reload.l12.go = "PortAntonio_crypt2";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "crypt";

	locations[n].reload.l13.name = "houseF3";
	locations[n].reload.l13.go = "Aaron_House";
	locations[n].reload.l13.emerge = "reload1_back";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "Aaron's House";

    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseF4";
	locations[n].reload.l20.go = "CommonRoom_MH";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseS1";
	locations[n].reload.l21.go = "CommonCobHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseF1";
	locations[n].reload.l22.go = "CommonRoom_MH5";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseS2";
	locations[n].reload.l23.go = "CommonFlamHouse";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseH2";
	locations[n].reload.l24.go = "CommonRoom_MH7";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseSp1";
	locations[n].reload.l25.go = "CommonResidence_BackHall";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseF2";
	locations[n].reload.l26.go = "CommonRoom_MH9";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";
	
	locations[n].reload.l27.name = "houseH1";
	locations[n].reload.l27.go = "CommonHut";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

	/*locations[n].reload.l28.name = "houseH11";
	locations[n].reload.l28.go = "CommonHut";
	locations[n].reload.l28.emerge = "reload2";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";*/
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Дом Чумакейро
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Aaron_House";
	locations[n].id.label = "Aaron's House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut3";
	locations[n].models.always.locators = "Hut3_locators";
	locations[n].models.always.tavern = "Hut3";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut3_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut3_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut3_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "PortAntonio_town";
	Locations[n].reload.l1.emerge = "houseF3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_crypt1";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "basement1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 2
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_crypt2";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload_jail";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_tavern";
	locations[n].id.label = "Tavern40";
	locations[n].filespath.models = "locations\inside\Tavern01\";
	locations[n].image = "loading\inside\tavern_hol.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortAntonio_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store01\";
locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
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
	// РОСТОВЩИК Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\bank01\";
locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].models.day.charactersPatch = "bank01_patch";
	//Night
	locations[n].models.night.charactersPatch = "bank01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload8_back";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortAntonio_Bank_residence";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КАБИНЕТ ГЛАВЫ БАНКИРСКОГО ДОМА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Bank_residence";
	locations[n].id.label = "Bank Director";
	locations[n].image = "loading\inside\BigHouse05.tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
	//Always
	locations[n].filespath.models = "locations\inside\Residence08";
	locations[n].models.always.locators = "Res08_locators";
	locations[n].models.always.l1 = "Res08";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "Res08_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;	
	//Day
	Locations[n].models.day.charactersPatch = "Res08_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Res08_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1"; // reload1;
	locations[n].reload.l1.go = "PortAntonio_Bank"; // "FortOrange_Bank";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Usurer House";
	
	// запрем сундуки
	locations[n].box1.closed = true;
	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
	locations[n].brothel = true;
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortAntonio_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PortAntonio_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortAntonio";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
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
	locations[n].reload.l1.go = "PortAntonio_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortAntonio_town";
	locations[n].reload.l2.emerge = "reload91";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1; 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard03\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PortAntonio";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].models.always.locators = "Shipyard03_locators";
	locations[n].models.always.shipyard = "Shipyard03";
	locations[n].models.always.shipyard.level = 65538;
	locations[n].models.always.window = "shipyard03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Shipyard03_patch";
	//Night
	locations[n].models.night.charactersPatch = "Shipyard03_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortAntonio_town";
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
	// РЕЗИДЕНЦИЯ Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence01";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "CommonResidence_2";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	n = n + 1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortAntonio_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "PortAntonio_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "PortAntonio";
    locations[n].parent_colony = "PortAntonio";
 	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
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
	Locations[n].reload.l1.go = "PortAntonio_town";
	Locations[n].reload.l1.emerge = "reloadPr1";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход Форт Оранж
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_VillaAlegria\exit";
	Locations[n].models.always.locators = "VillaAlegriaExit_locators";
	Locations[n].models.always.exit = "VillaAlegriaExit";
	Locations[n].models.always.grassPatch = "VillaAlegriaExit_grass";
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
	Locations[n].models.day.charactersPatch = "VillaAlegriaExit_patch";
	Locations[n].models.day.fonar = "VillaAlegriaExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "VillaAlegriaExit_patch";
	Locations[n].models.night.fonar = "VillaAlegriaExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
     	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "PortAntonio_Rudnik";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "PortAntonioRudnik";
	locations[n].locators_radius.reload.reload3 = 1.8;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "PortAntonio_Jungle_01";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "Hispaniola2";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "PortAntonio_ExitTown";
     locations[n].reload.l1.emerge = "reload1_back";  
     locations[n].reload.l1.autoreload = "0";
     locations[n].reload.l1.label = "ExitTown";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore90";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore90";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_jungle_04";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "jungle";
	locations[n].locators_radius.reload.reload3_back = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Рудник Форт Оранж //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_Rudnik";
     locations[n].id.label = "PortAntonioRudnik";
	locations[n].townsack = "PortAntonio";
    locations[n].parent_colony = "PortAntonio";
 	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
	locations[n].image = "loading\Mine_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortAntonio";
     //Sound
     locations[n].type = "PortAntonio";
      //Models
      //Always
	locations[n].filespath.models = "Locations\Outside\Canyon";
	locations[n].models.always.Canyon = "Canyon";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	
                   locations[n].models.always.locators = "canyon_locators";
                   locations[n].models.always.grassPatch = "canyon_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	//Day
	locations[n].models.day.charactersPatch = "canyon_patch";
	locations[n].models.day.fonar = "canyon_fd";
	//Night
	locations[n].models.night.charactersPatch = "canyon_patch";
	locations[n].models.night.fonar = "canyon_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
                   //Reload map	
	 locations[n].reload.l1.name = "reload1";
	 locations[n].reload.l1.go = "PortAntonio_ExitTown";
      locations[n].reload.l1.emerge = "Reload2";  
       locations[n].reload.l1.autoreload = "0";
       locations[n].reload.l1.label = "ExitTown";
       locations[n].locators_radius.reload.reload1 = 2.0;
	
	 locations[n].reload.l2.name = "reload2";
	 locations[n].reload.l2.go = "CommonRoom_MH4";
                   locations[n].reload.l2.emerge = "reload1";  
                   locations[n].reload.l2.autoreload = "0";
                   locations[n].reload.l2.label = "House";
	
	 locations[n].reload.l3.name = "reload3";
	 locations[n].reload.l3.go = "CommonRoom_MH7";
                   locations[n].reload.l3.emerge = "reload1";  
                   locations[n].reload.l3.autoreload = "0";
                   locations[n].reload.l3.label = "House";
	
	 locations[n].reload.l4.name = "reload4";
	 locations[n].reload.l4.go = "PortAntonio_mines";
                   locations[n].reload.l4.emerge = "reload1";  
                   locations[n].reload.l4.autoreload = "0";
                   locations[n].reload.l4.label = "mines";
	
locations[n].reload.l5.name = "reload5";
locations[n].reload.l5.go = "PortAntonio_Rudnik_Residence";
locations[n].reload.l5.emerge = "reload1";  
locations[n].reload.l5.autoreload = "0";
locations[n].reload.l5.label = "Cabinet";
locations[n].locators_radius.camdetector.camera1 = 5;
	
	locations[n].reload.l6.name = "reload6";
	locations[n].reload.l6.go = "PortAntonio_town";
      locations[n].reload.l6.emerge = "gate_back";  
       locations[n].reload.l6.autoreload = "0";
       locations[n].reload.l6.label = "PortAntonio";
       locations[n].locators_radius.reload.reload6 = 2.0;
	locations[n].locators_radius.rld.warrior = 5.0;
	n = n + 1;
//////////Кабинет
locations[n].id = "PortAntonio_Rudnik_Residence";
locations[n].id.label = "Cabinet";
locations[n].townsack = "PortAntonio";
locations[n].parent_colony = "PortAntonio";
 locations[n].fastreload = "PortAntonio";
locations[n].islandId = "Jamaica";
locations[n].image = "loading\inside\smallresidence_0.tga";
locations[n].MustSetReloadBack = true;
//Town sack
locations[n].townsack = "PortAntonio";
locations[n].lockWeather = "Inside";
//Sound
locations[n].type = "house";
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
locations[n].reload.l1.go = "PortAntonio_Rudnik";
locations[n].reload.l1.emerge = "reload5";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "PortAntonioRudnik";
n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Шахта
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortAntonio_mines";
	locations[n].id.label = "mines";
	locations[n].townsack = "PortAntonio";
    locations[n].parent_colony = "PortAntonio";
 	locations[n].fastreload = "PortAntonio";
	locations[n].islandId = "Jamaica";
    locations[n].image = "loading\Mine_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "mine";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer2";
	locations[n].models.always.DungeonDuffer2 = "DungeonDuffer2";
	locations[n].models.always.locators = "MinentownMine_locators";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortAntonio_Rudnik";
	locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "PortAntonioRudnik";
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Jamaica_jungle_05";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore87";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore87";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortAntonio_Jungle_01";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Jamaica_jungle_05";
	locations[n].id.label = "jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Town sack
	Locations[n].townsack = "Jamaica";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "Jamaica";
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
	Locations[n].reload.l1.name = "reload3_back";
	Locations[n].reload.l1.go = "Jamaica_jungle_04";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "jungle";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Jamaica_Jungle_07";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "jungle";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Jamaica_jungle_08";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "jungle";
	Locations[n].locators_radius.reload.reload3 = 3.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_Jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Jamaica_jungle_05";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Jamaica_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
     locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_Jungle_01";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Jamaica_jungle_05";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Shore88";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore88";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Jamaica_jungle_09";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_09";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
	locations[n].islandIdAreal = "Jamaica";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Jamaica_jungle_10";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shore86";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore86";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_jungle_08";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Jamaica_jungle_10";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "Shore84";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore84";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore85";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore85";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Jamaica_Jungle_09";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;
	return n;
}
