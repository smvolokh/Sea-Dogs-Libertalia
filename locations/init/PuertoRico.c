
int LocationInitPuertoRico(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "SanJuan";
	
	locations[n].townsack = "SanJuan";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
	
	locations[n].filespath.models = "locations\Town_PuertoRico\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 6; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "SanJuan";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "SanJuan_signsA";
	locations[n].models.always.seabed = "SanJuan_sb";
	locations[n].models.always.locators = "SanJuan_locators";
	locations[n].models.always.grassPatch = "SanJuan_grass";
	
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
	locations[n].models.day.fonar = "SanJuan_fd";
	locations[n].models.day.charactersPatch = "SanJuan_patch_day";
	locations[n].models.day.rinok = "SanJuan_rinok";
	//Night
	locations[n].models.night.fonar = "SanJuan_fn";
	locations[n].models.night.charactersPatch = "SanJuan_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PuertoRico";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "SanJuan_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "SanJuan_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "SanJuan_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "SanJuan_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "SanJuan_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "SanJuan_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "SanJuan_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "SanJuan_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "SanJuan_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

	// --> Квествоые локации.

    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseS1";
	locations[n].reload.l20.go = "CommonFlamHouse";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseS2";
	locations[n].reload.l21.go = "CommonPirateHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
	locations[n].reload.l21.close_for_night = 1;
	
	locations[n].reload.l22.name = "houseS4";
	locations[n].reload.l22.go = "CommonStoneHouse";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";
	
	locations[n].reload.l23.name = "houseSp1";
	locations[n].reload.l23.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

 	locations[n].reload.l24.name = "houseH2";
	locations[n].reload.l24.go = "CommonRoom_MH3";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

 	locations[n].reload.l25.name = "houseF2";
	locations[n].reload.l25.go = "CommonRoom_MH4";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

 	locations[n].reload.l26.name = "houseH1";
	locations[n].reload.l26.go = "CommonRoom_MH9";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

 	locations[n].reload.l27.name = "houseSp2";
	locations[n].reload.l27.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

 	locations[n].reload.l28.name = "houseS3";
	locations[n].reload.l28.go = "CommonPirateHouse";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

 	locations[n].reload.l29.name = "houseSp3";
	locations[n].reload.l29.go = "CommonRoom_MH10";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";

 	locations[n].reload.l30.name = "houseH3";
	locations[n].reload.l30.go = "CommonRoom_MH7";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";
	
 	locations[n].reload.l31.name = "houseF1";
	locations[n].reload.l31.go = "CommonRoom_MH5";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

 	locations[n].reload.l32.name = "houseSp5";
	locations[n].reload.l32.go = "CommonFlamHouse";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

 	locations[n].reload.l33.name = "houseSp4";
	locations[n].reload.l33.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";

 	locations[n].reload.l34.name = "houseF3";
	locations[n].reload.l34.go = "CommonRoom_MH2";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";
	
	locations[n].reload.l35.name = "houseSp6";
	locations[n].reload.l35.go = "CommonCobHouse";
	locations[n].reload.l35.emerge = "reload1";
	locations[n].reload.l35.autoreload = "0";
	locations[n].reload.l35.label = "House";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_tavern";
	locations[n].id.label = "Tavern28";
	locations[n].filespath.models = "locations\inside\tavern03\";
	locations[n].image = "loading\inside\tavern4.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
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
	locations[n].reload.l1.go = "SanJuan_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanJuan";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\store02\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
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
	locations[n].models.day.charactersPatch = "store02_patch";
	//Night
	locations[n].models.night.charactersPatch = "store02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//locations[n].models.back = "back\redms_";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanJuan_town";
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
	locations[n].id = "SanJuan_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SanJuan";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_town";
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
	locations[n].id = "SanJuan_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "SanJuan";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_town";
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
	locations[n].id = "SanJuan_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence03";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchInsideBig1";
	locations[n].models.always.churchInside2 = "churchInsideBig1";
	locations[n].models.always.churchInside2.level = 65538;
	locations[n].models.always.locators = "churchInsideBig1_locators";

	Locations[n].models.always.churchInside2windows = "churchInsideBig1_windows";
	Locations[n].models.always.churchInside2windows.tech = "LocationWindows";
	locations[n].models.always.churchInside2windows.level = 65541;

	Locations[n].models.always.churchInside2alpha = "churchInsideBig1_alpha";
	Locations[n].models.always.churchInside2alpha.tech = "LocationWindows";
	locations[n].models.always.churchInside2alpha.level = 65540;

	Locations[n].models.always.churchInside2gold = "churchInsideBig1_gold";
	Locations[n].models.always.churchInside2gold.reflection = 0.6;
	Locations[n].models.always.churchInside2gold.tech = "EnvironmentShader";
	locations[n].models.always.churchInside2gold.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "churchInsideBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInsideBig1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SanJuan_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.quest.detector1 = 0.8;
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "SanJuan_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "SanJuan";
    locations[n].parent_colony = "SanJuan";
 	locations[n].fastreload = "SanJuan";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "SanJuan_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "SanJuan";
	//Sound
	locations[n].type = "exittown";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitY";
	Locations[n].models.always.townExit = "townExitY";
	Locations[n].models.always.townWalls = "townExitY_stucco";
	
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
	locations[n].reload.l1.go = "SanJuan_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanJuan";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "SanJuan_fort";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "SanJuan Fort";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore45";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore45";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "SanJuan_Jungle_02";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// пляж Фахардо
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore45";
	locations[n].id.label = "Shore45";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore45";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_CaveEntrance";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_03";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "SanJuan_jungle_01";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].id.label = "Cave";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "SanJuan_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "SanJuan_Jungle_03";
	locations[n].reload.l2.emerge = "reloadW";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2 = 2;
	locations[n].locators_radius.item.CheckReload1 = 3.5;
	
///	locations[n].box1.key = "key2";
///	locations[n].box1.items.ArtRing5 = 1;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_Jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle1\";
	Locations[n].models.always.jungle = "jungle1";
	Locations[n].models.always.locators = "jungle1_lPuerto03";		
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

	locations[n].models.always.well_small = "well_big";
	Locations[n].models.always.well_small.locator.group = "reload";
	Locations[n].models.always.well_small.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small.tech = "DLightModel";
	//Day
	locations[n].models.day.charactersPatch = "jungle1_pPuerto03";
	//Night
	locations[n].models.night.charactersPatch = "jungle1_pPuerto03";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanJuan_Jungle_05";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_02";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reloadW_back";
	locations[n].reload.l3.go = "SanJuan_Cave";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reloadW_back = 2.3;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Порт Вилья Алегрия
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "VillaAlegria_town";
	locations[n].id.label = "VillaAlegria Port";
	Locations[n].image = "loading\outside\seaStand.tga";
	locations[n].worldmap = "VillaAlegria_port";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Town sack
	locations[n].townsack = "VillaAlegria";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_VillaAlegria\port";
	Locations[n].models.always.locators = "VillaAlegriaPort_locators";
	Locations[n].models.always.l1 = "VillaAlegriaPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "VillaAlegriaPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "VillaAlegriaPort_grass";
	Locations[n].models.always.add = "VillaAlegriaPort_SD";
	//Day
	Locations[n].models.day.charactersPatch = "VillaAlegriaPort_patch";
	Locations[n].models.day.fonar = "VillaAlegriaPort_fd";
	//Night
	Locations[n].models.night.charactersPatch = "VillaAlegriaPort_patch";
	Locations[n].models.night.fonar= "VillaAlegriaPort_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "VillaAlegria_town2";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                 locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "VillaAlegriaPort_HouseHut1";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "House";

	locations[n].reload.l4.name = "reload3";
	locations[n].reload.l4.go = "VillaAlegriaPort_HouseHut2";
	locations[n].reload.l4.emerge = "reload1_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "House";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegriaPort_HouseHut1";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_town";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegriaPort_HouseHut2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "VillaAlegria_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Город Вилья Алегрия 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "VillaAlegria_town2";
	locations[n].id.label = "Street";
	locations[n].worldmap = "PuertoRico";

	locations[n].townsack = "VillaAlegria";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 7; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_VillaAlegria\Town\";
	Locations[n].models.always.locators = "VillaAlegriaTown_locators";
	Locations[n].models.always.town = "VillaAlegriaTown";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.koster = "koster";
	Locations[n].models.always.grassPatch = "VillaAlegriaTown_grass";
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
	locations[n].models.day.fonar = "VillaAlegriaTown_fd";
	Locations[n].models.day.rinok = "VillaAlegriaTown_rinok";
	Locations[n].models.day.charactersPatch = "VillaAlegriaTown_patch_day";
	//Night
	Locations[n].models.night.fonar = "VillaAlegriaTown_fn";
	locations[n].models.night.charactersPatch = "VillaAlegriaTown_patch_night";

	Locations[n].models.day.jumppatch = "VillaAlegriaTown_jump_patch";
	Locations[n].models.night.jumppatch = "VillaAlegriaTown_jump_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "gate_back";
	Locations[n].reload.l1.go = "VillaAlegria_ExitTown";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "VillaAlegria_town";
	Locations[n].reload.l2.emerge = "Reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Port";

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "VillaAlegria_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "residence";
	locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "reload4_back";
	Locations[n].reload.l4.go = "VillaAlegria_tavern";
	Locations[n].reload.l4.emerge = "reload1_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern";

	Locations[n].reload.l5.name = "reload5_back";
	Locations[n].reload.l5.go = "VillaAlegria_Shipyard";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "reload6_back";
	Locations[n].reload.l6.go = "VillaAlegria_Store";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "reload7_back";
	Locations[n].reload.l7.go = "VillaAlegria_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church";

	Locations[n].reload.l8.name = "reload8_back";
	Locations[n].reload.l8.go = "VillaAlegria_bank";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Usurer House";
	Locations[n].reload.l8.close_for_night = 1;

  	Locations[n].reload.l9.name = "reload9_back";
	Locations[n].reload.l9.go = "VillaAlegria_brothel";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Brothel";

	Locations[n].reload.l10.name = "reload10_back";
	Locations[n].reload.l10.go = "VillaAlegria_PortOffice";
	Locations[n].reload.l10.emerge = "reload1_back";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "PortOffice";
	Locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "VillaAlegria_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

	Locations[n].reload.l11.name = "reload2_back";
	Locations[n].reload.l11.go = "VillaAlegria_Rudnik";
	Locations[n].reload.l11.emerge = "Reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "VillaAlegriaRudnik";

    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.

	Locations[n].reload.l12.name = "houseS2";
	Locations[n].reload.l12.go = "VillaAlegria_houseS2";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House";

	Locations[n].reload.l13.name = "houseSp1";
	Locations[n].reload.l13.go = "House_Smithy";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "House Smithy";

	Locations[n].reload.l14.name = "basement1_back";
	Locations[n].reload.l14.go = "VillaAlegria_TownCave";
	Locations[n].reload.l14.emerge = "reload2";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Dungeon";

	locations[n].reload.l15.name = "houseS1";
	locations[n].reload.l15.go = "VillaAlegria_PirateHouse";
	locations[n].reload.l15.emerge = "reload1_back";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "House";

	locations[n].reload.l16.name = "houseH7";
	locations[n].reload.l16.go = "VillaAlegria_HouseHut7";
	locations[n].reload.l16.emerge = "reload1_back";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "House";

	locations[n].reload.l17.name = "houseH4";
	locations[n].reload.l17.go = "VillaAlegria_HouseHut4";
	locations[n].reload.l17.emerge = "reload1_back";
	locations[n].reload.l17.autoreload = "0";
	locations[n].reload.l17.label = "House";

	locations[n].reload.l18.name = "houseF4";
	locations[n].reload.l18.go = "VillaAlegria_LibraryHouseF4";
	locations[n].reload.l18.emerge = "reload1";
	locations[n].reload.l18.autoreload = "0";
	locations[n].reload.l18.label = "House";

	locations[n].reload.l19.name = "houseF5";
	locations[n].reload.l19.go = "VillaAlegria_HouseF5";
	locations[n].reload.l19.emerge = "reload1";
	locations[n].reload.l19.autoreload = "0";
	locations[n].reload.l19.label = "House";

    // --> Комоны, загрушки. Номера с начинаются с 20.

	locations[n].reload.l20.name = "houseF3";
	locations[n].reload.l20.go = "CommonFlamHouse";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseSp6";
	locations[n].reload.l21.go = "CommonPirateHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
	locations[n].reload.l21.close_for_night = 1;
	
	locations[n].reload.l22.name = "houseS4";
	locations[n].reload.l22.go = "CommonStoneHouse";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";
	
	locations[n].reload.l23.name = "houseSp4";
	locations[n].reload.l23.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

 	locations[n].reload.l24.name = "houseH2";
	locations[n].reload.l24.go = "CommonRoom_MH3";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

 	locations[n].reload.l25.name = "houseF2";
	locations[n].reload.l25.go = "CommonRoom_MH4";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

 	locations[n].reload.l26.name = "houseH1";
	locations[n].reload.l26.go = "CommonRoom_MH9";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

 	locations[n].reload.l27.name = "houseSp2";
	locations[n].reload.l27.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

 	locations[n].reload.l28.name = "houseS3";
	locations[n].reload.l28.go = "CommonPirateHouse";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

 	locations[n].reload.l29.name = "houseSp3";
	locations[n].reload.l29.go = "CommonRoom_MH10";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";

 	locations[n].reload.l30.name = "houseH3";
	locations[n].reload.l30.go = "CommonRoom_MH7";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";
	
 	locations[n].reload.l31.name = "houseF1";
	locations[n].reload.l31.go = "CommonPirateHouse";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

 	locations[n].reload.l32.name = "houseSp5";
	locations[n].reload.l32.go = "CommonFlamHouse";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

 	locations[n].reload.l33.name = "houseH5";
	locations[n].reload.l33.go = "CommonRoom_MH2";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";

 	locations[n].reload.l34.name = "houseH6";
	locations[n].reload.l34.go = "CommonRoom_MH5";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";

 	locations[n].reload.l35.name = "houseS5";
	locations[n].reload.l35.go = "CommonStoneHouse";
	locations[n].reload.l35.emerge = "reload1";
	locations[n].reload.l35.autoreload = "0";
	locations[n].reload.l35.label = "House";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence02";
	locations[n].models.always.locators = "Residence02_locators";
	locations[n].models.always.l1 = "Residence02";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence02_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence02_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "VillaAlegria_town2";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "VillaAlegria_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_town2";
	locations[n].reload.l1.emerge = "reload5_back";
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
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
locations[n].id = "VillaAlegria_store";
locations[n].id.label = "Store";
locations[n].filespath.models = "locations\inside\Store01\";
locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_town2";
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
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_Tavern";
	locations[n].id.label = "Tavern32";
	locations[n].image = "loading\inside\tavern4.tga";
	locations[n].habitues = 1;
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].models.day.charactersPatch = "tavern06_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern06_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "VillaAlegria_Town2";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "VillaAlegria_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	Locations[n].reload.l2.disable = true;
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.

    ////////////////////////==> подсобка таверны
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "sklad_Tavern";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "sklad";
	LAi_LocationFightDisable(&locations[n], true);	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//СКЛАД В ТАВЕРНЕ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "sklad_Tavern";
	locations[n].id.label = "sklad";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Tavern";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ НАВЕРХУ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "VillaAlegria_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "VillaAlegria_tavern";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_houseS1Bedroom";
	locations[n].id.label = "Bedroom";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
	//Models
	locations[n].filespath.models = "locations\inside\bedRoom1";
	locations[n].models.always.bedRoom1 = "bedRoom1";
	locations[n].models.always.bedRoom1.level = 65538;
	Locations[n].models.always.bedRoom1windows = "mediumhouse01_windows";
	Locations[n].models.always.bedRoom1windows.tech = "LocationWindows";
	locations[n].models.always.bedRoom1windows.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "bedRoom1_lHavana";
	Locations[n].models.day.bedRoom1rand = "bedRoom1_rand";
	locations[n].models.day.charactersPatch = "bedRoom1_patch";
	//Night
	locations[n].models.night.locators = "bedRoom1_lNHavana";
	locations[n].models.night.charactersPatch = "bedRoom1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "VillaAlegria_houseF2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Room";
	locations[n].locators_radius.item.item1 = 1.0; //увеличиваем радиус проверочного локатора, иначем могет быть баг.
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Городская тюрьма	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "VillaAlegria_prison";
	locations[n].id.label = "Incquisitio";
	locations[n].image = "loading\inside\inquisitio_" + rand(1) + ".tga";
	locations[n].townsack = "VillaAlegria";
	locations[n].parent_colony = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	//Sound
	locations[n].type = "Maltinis";
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].locators_radius.camdetector.camera13 = 2.5;//Mosh
	Locations[n].locators_radius.camdetector.camera12 = 0.5;//Mosh
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\prison";
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l";
	Locations[n].models.always.window = "Pri_w";
	//Locations[n].models.always.flame = "prison_flame";
	//Day
	Locations[n].models.day.charactersPatch = "Pri_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pri_p";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "VillaAlegria_town2";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload30";
	Locations[n].reload.l2.go = "VillaAlegria_Cave_prison";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Prison";
	locations[n].reload.l2.disable = true;
	n = n + 1;
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "VillaAlegria_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "VillaAlegria_Town2";
	Locations[n].reload.l1.emerge = "reload9_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "VillaAlegria_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "VillaAlegria_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "VillaAlegria_SecBrRoom_Residence";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	locations[n].id = "VillaAlegria_SecBrRoom_Residence"; // третья комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\buduar.tga";
 	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	locations[n].brothel = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].models.always.locators = "bed_l";
	Locations[n].models.always.l1 = "bed";
	Locations[n].models.always.window = "bed_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "bed_p";
	//Night
	Locations[n].models.night.charactersPatch = "bed_p";	
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "VillaAlegria_SecBrRoom";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "VillaAlegria_Town2";
	Locations[n].reload.l1.emerge = "reload8_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "VillaAlegria_Bank_residence";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Bank Director";

	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КАБИНЕТ ГЛАВЫ БАНКИРСКОГО ДОМА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_Bank_residence";
	locations[n].id.label = "Bank Director";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	//Always
	locations[n].filespath.models = "locations\Inside\BigHouse05";
	locations[n].models.always.house = "BigHouse05";
	locations[n].models.always.window = "BigHouse05_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "BigHouse05_patch";
	locations[n].models.day.locators = "BigHouse05_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse05_patch";
	locations[n].models.night.locators = "BigHouse05_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "VillaAlegria_Bank";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Usurer House";
	
	// запрем сундуки
	locations[n].box1.closed = true;
	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Town2";
	locations[n].reload.l1.emerge = "reload10_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лаборатория	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_LibraryHouseF4";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_0.tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Library";
	locations[n].models.always.locators = "ResP_locators";
	locations[n].models.always.l1 = "ResP";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "ResP_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;	
	//Day
	Locations[n].models.day.charactersPatch = "ResP_patch";
	//Night
	Locations[n].models.night.charactersPatch = "ResP_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "VillaAlegria_Town2";
	Locations[n].reload.l1.emerge = "houseF4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator1 = 0.8;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_HouseHut7";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "VillaAlegria_Town2";
	locations[n].reload.l1.emerge = "houseH7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_HouseHut4";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Town2";
	locations[n].reload.l1.emerge = "houseH4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Смитов	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "House_Smithy";
	locations[n].id.label = "House Smithy";
	locations[n].image = "loading\inside\flamhouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "VillaAlegria_Town2";
	Locations[n].reload.l1.emerge = "houseSp1";
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
	locations[n].reload.l4.go = "VillaAlegria_TownCave"; 
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Dungeon";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	/////////////////////комната алхимика 
	locations[n].id = "Smithy_HouseF3_Room";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "PuertoRico";
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
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].id = "VillaAlegria_TownCave";
	Locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "PuertoRico";
	locations[n].parent_colony = "VillaAlegria";
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
	locations[n].reload.l2.go = "VillaAlegria_Town2";
	locations[n].reload.l2.emerge = "basement1_back";
	locations[n].locators_radius.item.berglar1 = 3.0;
	locations[n].reload.l2.label = "Street";
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом коменданта Фернандо Гонсалесa
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_houseS2";
	locations[n].filespath.models = "locations\inside\CobHouse";
	locations[n].id.label = "Comendant_House_2";
	locations[n].image = "loading\inside\CobHouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].models.always.tavern = "CobHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "CobHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "CobHouse_locators";
	locations[n].models.night.locators = "CobHouse_Nlocators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "CobHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "CobHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "VillaAlegria_town2";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "VillaAlegria_houseS2_Bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Спальня	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_houseS2_Bedroom";
	locations[n].id.label = "Bedroom01";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_houseS2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Comendant_House_2";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;


////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_PirateHouse";
	locations[n].filespath.models = "locations\inside\CobHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\CobHouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_town2";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Библиотека	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_HouseF5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_0.tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	locations[n].noFight = true;	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Library";
	locations[n].models.always.locators = "ResP_locators";
	locations[n].models.always.l1 = "ResP";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "ResP_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;	
	//Day
	Locations[n].models.day.charactersPatch = "ResP_patch";
	//Night
	Locations[n].models.night.charactersPatch = "ResP_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "VillaAlegria_town2";
	Locations[n].reload.l1.emerge = "HouseF5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.locator1 = 0.8;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "VillaAlegria_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "PuertoRico";
	locations[n].mining1.key = "minepick";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
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
	Locations[n].reload.l1.go = "VillaAlegria_town2";
	Locations[n].reload.l1.emerge = "gate_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_05";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanJuan_Jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "VillaAlegria_ExitTown";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_03";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Shore94";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanJuan Fort";
	locations[n].locators_radius.reload.reloadW_back = 2.3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера  с выходом в бухту
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_Cave_prison";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	locations[n].id.label = "dungeon";
	//Sound
	locations[n].townsack = "VillaAlegria";
	locations[n].type = "Dungeon";
 	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonVault1";
	locations[n].models.always.DungeonVault1 = "DungeonVault1";
	locations[n].models.always.InquisitionDungeonVault1Fonars = "DungeonVault1_fonars";
	locations[n].models.always.locators = "DungeonVault1_locators";	

	locations[n].locators_radius.item.duhi1 = 1.3;
	
	Locations[n].models.always.rays = "DungeonVault1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Shore111";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore111";

	locations[n].reload.l2.name = "reload1";
	locations[n].reload.l2.go = "VillaAlegria_prison";
	locations[n].reload.l2.emerge = "reload30";
	locations[n].reload.l2.label = "prison";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж Надежды
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore111";
	locations[n].id.label = "Shore111";
	locations[n].worldmap = "Shore111";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	Locations[n].name = "Leviathan Rock";
	//Sound
	locations[n].type = "seashore";
 	locations[n].islandId = "PuertoRico";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Shore113";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Shore113";
	locations[n].locators_radius.reload.reload1_back = 1;
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "VillaAlegria_Cave_prison";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Cave";
                   locations[n].locators_radius.reload.reload2_back = 1.5;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////	//скалы Янкендара
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Shore113";
	locations[n].id.label = "Shore113";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore113";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Serpentine";
	Locations[n].models.always.locators = "pass2_locators";
	Locations[n].models.always.jungle = "pass2";
	locations[n].models.always.passage.sea_reflection = 1;
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.grassPatch = "pass2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	//Day
	Locations[n].models.day.charactersPatch = "pass2_patch";
	//Night
	Locations[n].models.night.charactersPatch = "pass2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.go = "Shore111";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Shore111";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Graveyard_church";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////	//Забытая церьковь
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Graveyard_church";
	locations[n].id.label = "GraveyardChurch";
	Locations[n].image = "loading\Cemetery_3.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].islandId = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "Shore113";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore113";
	locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload6";
	Locations[n].reload.l2.go = "Kolokol_house";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload5";
	Locations[n].reload.l3.go = "church IM";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "crypt_church1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Graveyard_house";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	n = n + 1; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Вход в склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "crypt_church1";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].islandId = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "Graveyard_church";//Mosh
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Muelle church";
	Locations[n].items.randitem1 = "blade12";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Graveyard_crypt_2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload2_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Graveyard_crypt_2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_0.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].islandId = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "crypt_church1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////
	//Колокольня
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Kolokol_house";
	locations[n].label = "Kolokol house";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	Locations[n].townsack = "PuertoRico";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "Graveyard_church";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "church IM";
	locations[n].id.label = "Muelle church";
	locations[n].image = "loading\outside\ChurchRuin.tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "Graveyard_church";
	Locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Muelle church";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "crypt";
	locations[n].locators_radius.Quest.LLquest6 = 3.0;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Graveyard_crypt2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "crypt";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Graveyard_crypt2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "church IM";
	Locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "church IM";
	Locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//домик смотрителя	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Graveyard_house";
	locations[n].id.label = "house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
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
	Locations[n].reload.l1.go = "Graveyard_church";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Churchh";
	n = n + 1;



//////////////////////////////////////////////////////////////////////////////////////////
	//
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
	//
//////////////////////////////////////////////////////////////////////////////////////////


	// VillaAlegria_church -------------------------------------------------
	Locations[n].id = "VillaAlegria_church";
	locations[n].id.label = "church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\churchInside1";
	locations[n].models.always.churchInside1 = "churchInside1";
	locations[n].models.always.churchInside1.level = 65538;	
	locations[n].models.always.locators = "churchInside1_locators";
	
	Locations[n].models.always.churchInside1windows = "churchInside1_windows";
	Locations[n].models.always.churchInside1windows.tech = "LocationWindows";
	locations[n].models.always.churchInside1windows.level = 65539;	
	
	locations[n].models.always.backgroundInsides = "backgroundInsides";
	locations[n].models.always.backgroundInsides.level = 65529;		
	//Day
	locations[n].models.day.charactersPatch = "churchInside1_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInside1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "VillaAlegria_town2";
	Locations[n].reload.l1.emerge = "reload7_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	// -----------------Mosh D24--------------------

	Locations[n].id = "VillaAlegria_house_Figuiera";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "VillaAlegria";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "VillaAlegria";
 	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse03_2";
	locations[n].models.always.mediumhouse03 = "mediumhouse03_2";
	locations[n].models.always.mediumhouse03.level = 65538;
	locations[n].models.always.locators = "mediumhouse03_2_locators";

	Locations[n].models.always.mediumhouse03windows = "mediumhouse03_2_windows";
	Locations[n].models.always.mediumhouse03windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse03windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "mediumhouse03_2_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse03_2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "VillaAlegria_town2";//Mosh
	Locations[n].reload.l1.emerge = "reload17";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Рудник Вилья Аллегрия //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_Rudnik";
     locations[n].id.label = "VillaAlegriaRudnik";
	locations[n].townsack = "VillaAlegria";
    locations[n].parent_colony = "VillaAlegria";
 	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
	locations[n].image = "loading\Mine_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "VillaAlegria";
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
                   Locations[n].reload.l1.name = "reload6";
	Locations[n].reload.l1.go = "SanJuan_Jungle_04";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

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
	 locations[n].reload.l4.go = "VillaAlegria_mines";
       locations[n].reload.l4.emerge = "reload1";  
        locations[n].reload.l4.autoreload = "0";
        locations[n].reload.l4.label = "mines";
	
		locations[n].reload.l5.name = "reload5";
		locations[n].reload.l5.go = "VillaAlegria_Rudnik_Residence";
		locations[n].reload.l5.emerge = "reload1";  
		locations[n].reload.l5.autoreload = "0";
		locations[n].reload.l5.label = "Cabinet";
		locations[n].locators_radius.camdetector.camera1 = 5;

	Locations[n].reload.l6.name = "reload1";
	Locations[n].reload.l6.go = "VillaAlegria_town2";
	Locations[n].reload.l6.emerge = "reload2_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 1.0;
	n = n + 1;

//////////Кабинет
locations[n].id = "VillaAlegria_Rudnik_Residence";
locations[n].id.label = "Cabinet";
locations[n].townsack = "VillaAlegria";
locations[n].parent_colony = "VillaAlegria";
 locations[n].fastreload = "VillaAlegria";
locations[n].islandId = "PuertoRico";
locations[n].image = "loading\inside\smallresidence_0.tga";
locations[n].MustSetReloadBack = true;
//Town sack
locations[n].townsack = "VillaAlegria";
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
locations[n].reload.l1.go = "VillaAlegria_Rudnik";
locations[n].reload.l1.emerge = "reload5";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "VillaAlegriaRudnik";
n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Шахта
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "VillaAlegria_mines";
	locations[n].id.label = "mines";
	locations[n].townsack = "VillaAlegria";
    locations[n].parent_colony = "VillaAlegria";
 	locations[n].fastreload = "VillaAlegria";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Rudnik";
	locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "VillaAlegriaRudnik";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                locations[n].id = "SanJuan_Jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "VillaAlegria_Rudnik";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "VillaAlegriaRudnik";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PuertoRico_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoRico_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PuertoRico_Grot";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanJuan_Jungle_04";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoRico_Grot";
	locations[n].id.label = "Grot";
	locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "PuertoRico";
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
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
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
	locations[n].reload.l1.go = "PuertoRico_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Shore112";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Shore112";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////Пляж Хананси
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// -------------------------------------------------
	Locations[n].id = "Shore112";
	locations[n].id.label = "Shore112";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore112";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Serpentine";
	Locations[n].models.always.locators = "pass2_locators";
	Locations[n].models.always.jungle = "pass2";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "pass2_grass";
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

	Locations[n].models.always.StoneMap = "StoneMap";
	Locations[n].models.always.StoneMap.locator.group = "item";
	Locations[n].models.always.StoneMap.locator.name = "item1";

	//Day
	Locations[n].models.day.charactersPatch = "pass2_patch";
	//Night
	Locations[n].models.night.charactersPatch = "pass2_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "PuertoRico_Grot";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Grot";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Shore44";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l1.label = "Shore44";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// бухта Маягуэс	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore44";
	locations[n].id.label = "Shore44";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore44";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore05";
	Locations[n].models.always.shore05 = "shore05";
	locations[n].models.always.shore05.sea_reflection = 1;
	Locations[n].models.always.shore05seabed = "shore05_sb";
	Locations[n].models.always.locators = "shore05_locators"; 
		
	Locations[n].models.always.grassPatch = "shore05_grass";
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
	locations[n].models.day.charactersPatch = "shore05_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore05_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore112";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Shore112";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        // бухта Понсе
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore81";
	locations[n].id.label = "Shore81";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore81";
	//Sound
	locations[n].type = "x_seashore";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Strange_Grotto_1";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Horinis_Jungle_01";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ТАЙНЫЙ ГРОТ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Strange_Grotto_1";
	locations[n].id.label = "Grotto Strange";
    	locations[n].image = "loading\inside\cave3.tga";
	locations[n].RuinsZombie = 5; // число монстров в локации
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "PuertoRico";
	locations[n].questflower = 1;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernBig1";
	locations[n].models.always.cavernBig1 = "cavernBig1";
	locations[n].models.always.lamps = "cavernBig1_lamps";	
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
	locations[n].reload.l1.name = "reload3_back";
	locations[n].reload.l1.go = "Strange_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	
	locations[n].reload.l2.name = "reload4";
	locations[n].reload.l2.go = "Shore81";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Shore81";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Strange_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l1.go = "Strange_Grotto_1";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        // Лагуна Аресибо
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore82";
	locations[n].id.label = "Shore82";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore82";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
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
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Гуаяма	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore95";
	locations[n].id.label = "Shore95";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore95";
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
	locations[n].deadlocked = true;
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
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	////////////////////////////////////////////////////////////
	/// бухта Агуадилья	
	////////////////////////////////////////////////////////////
	//ID
	Locations[n].id = "Shore94";
	locations[n].id.label = "Shore94";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore05";
	Locations[n].models.always.shore05 = "shore05";
	locations[n].models.always.shore05.sea_reflection = 1;
	Locations[n].models.always.shore05seabed = "shore05_sb";
	Locations[n].models.always.locators = "shore05_locators"; 
		
	Locations[n].models.always.grassPatch = "shore05_grass";
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
	locations[n].models.day.charactersPatch = "shore05_patch";
	//Night
	locations[n].models.night.charactersPatch = "shore05_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanJuan_Jungle_05";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PuertoRico";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;
	
	return n;
}
