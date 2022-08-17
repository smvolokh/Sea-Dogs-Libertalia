
int LocationInitMartinique(int n)
{	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Martinique";
	locations[n].filespath.models = "locations\Town_Martinique\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Town sack
	locations[n].townsack = "FortFrance";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].models.always.town = "Martinique";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Martinique_signsA";
	locations[n].models.always.L2 = "Malta_doors";
	locations[n].models.always.L2.tech = "DLightModel";
	locations[n].models.always.seabed = "Martinique_sb";
	locations[n].models.always.locators = "Martinique_locators";
	locations[n].models.always.grassPatch = "Martinique_grass";

	locations[n].models.always.Gallows = "Gallows1";
	Locations[n].models.always.Gallows.locator.group = "quest";
	Locations[n].models.always.Gallows.locator.name = "quest3";
	
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
	locations[n].models.day.fonar = "Martinique_fd";
	locations[n].models.day.charactersPatch = "Martinique_patch_day";
	locations[n].models.day.rinok = "Martinique_rinok";
	//Night
	locations[n].models.night.fonar = "Martinique_fn";
	locations[n].models.night.charactersPatch = "Martinique_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	
    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Martinique";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Martinique";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "FortFrance_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "FortFrance_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "FortFrance_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "FortFrance_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "FortFrance_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "FortFrance_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "FortFrance_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

 	locations[n].reload.l91.name = "reload91_back";
	locations[n].reload.l91.go = "FortFrance_SecBrRoom";
	locations[n].reload.l91.emerge = "reload2";
	locations[n].reload.l91.autoreload = "0";
	locations[n].reload.l91.label = "Brothel";

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "FortFrance_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "FortFrance_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "FortFrance_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";
	
    // --> Квестовые локации.
	locations[n].reload.l11.name = "basement1";
	locations[n].reload.l11.go = "FortFrance_Dungeon";
	locations[n].reload.l11.emerge = "reload2";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Dungeon";

	locations[n].reload.l12.name = "reloadPr1";
	locations[n].reload.l12.go = "FortFrance_Dungeon";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "Dungeon";

	locations[n].reload.l13.name = "houseS4";
	locations[n].reload.l13.go = "Martinique_House";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "House";

	Locations[n].reload.l14.name = "houseH6";
	Locations[n].reload.l14.go = "HouseBaltram";
	Locations[n].reload.l14.emerge = "reload1_back";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "House Baltram";

	locations[n].reload.l15.name = "houseH2";
	locations[n].reload.l15.go = "FortFrance_HouseHut2";
	locations[n].reload.l15.emerge = "reload1_back";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "House";

	locations[n].reload.l16.name = "houseH4";
	locations[n].reload.l16.go = "FortFrance_HouseHut4";
	locations[n].reload.l16.emerge = "reload1_back";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "House";

	locations[n].reload.l17.name = "houseH5";
	locations[n].reload.l17.go = "FortFrance_HouseHut5";
	locations[n].reload.l17.emerge = "reload1_back";
	locations[n].reload.l17.autoreload = "0";
	locations[n].reload.l17.label = "House";

	locations[n].reload.l18.name = "houseS7";
	locations[n].reload.l18.go = "FortFrance_HouseResidence";
	locations[n].reload.l18.emerge = "reload1";
	locations[n].reload.l18.autoreload = "0";
	locations[n].reload.l18.label = "House";

	locations[n].reload.l19.name = "houseS10";
	locations[n].reload.l19.go = "LibraryHouse";
	locations[n].reload.l19.emerge = "reload1";
	locations[n].reload.l19.autoreload = "0";
	locations[n].reload.l19.label = "House";

    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseF4";
	locations[n].reload.l20.go = "CommonRoom_MH";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseF3";
	locations[n].reload.l21.go = "CommonResidence_3";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseS1";
	locations[n].reload.l22.go = "CommonCobHouse";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseF1";
	locations[n].reload.l23.go = "CommonRoom_MH5";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseS2";
	locations[n].reload.l24.go = "CommonCobHouse";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseF7";
	locations[n].reload.l25.go = "CommonRoom_MH10";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseSp1";
	locations[n].reload.l26.go = "CommonResidence_BackHall";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

	locations[n].reload.l27.name = "houseF2";
	locations[n].reload.l27.go = "CommonRoom_MH";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";
	
	locations[n].reload.l28.name = "houseH1";
	locations[n].reload.l28.go = "CommonHut";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

	/*locations[n].reload.l29.name = "houseH11";
	locations[n].reload.l29.go = "CommonHut";
	locations[n].reload.l29.emerge = "reload2";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";*/

	locations[n].reload.l30.name = "houseF8";
	locations[n].reload.l30.go = "CommonRoom_MH9";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";

	locations[n].reload.l31.name = "houseF6";
	locations[n].reload.l31.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

	locations[n].reload.l32.name = "houseF5";
	locations[n].reload.l32.go = "CommonFlamHouse";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

	locations[n].reload.l33.name = "houseF9";
	locations[n].reload.l33.go = "CommonResidence_2";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";

	locations[n].reload.l34.name = "houseSp6";
	locations[n].reload.l34.go = "CommonPirateResidence";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";

	locations[n].reload.l35.name = "houseSp4";
	locations[n].reload.l35.go = "CommonResidence_3";
	locations[n].reload.l35.emerge = "reload1";
	locations[n].reload.l35.autoreload = "0";
	locations[n].reload.l35.label = "House";

	locations[n].reload.l36.name = "houseSp3";
	locations[n].reload.l36.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l36.emerge = "reload1";
	locations[n].reload.l36.autoreload = "0";
	locations[n].reload.l36.label = "House";

	locations[n].reload.l37.name = "houseS6";
	locations[n].reload.l37.go = "CommonFlamHouse";
	locations[n].reload.l37.emerge = "reload1";
	locations[n].reload.l37.autoreload = "0";
	locations[n].reload.l37.label = "House";

	locations[n].reload.l38.name = "houseS3";
	locations[n].reload.l38.go = "CommonStoneHouse";
	locations[n].reload.l38.emerge = "reload1";
	locations[n].reload.l38.autoreload = "0";
	locations[n].reload.l38.label = "House";

	locations[n].reload.l39.name = "houseS5";
	locations[n].reload.l39.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l39.emerge = "reload1";
	locations[n].reload.l39.autoreload = "0";
	locations[n].reload.l39.label = "House";

	n = n + 1;
  	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_tavern";
	locations[n].id.label = "Tavern24";
	locations[n].image = "loading\inside\tavern_2fr.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern01\";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortFrance_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store01\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
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
	// РОСТОВЩИК	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
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
	// БОРДЕЛЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
                   locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortFrance_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "FortFrance_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "FortFrance_town";
	locations[n].reload.l2.emerge = "reload91";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard03\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
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
	// РЕЗИДЕНЦИЯ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
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
	locations[n].locators_radius.reload.dialog_event = 0.2;
	locations[n].locators_radius.camdetector.dialog_event = 2.2;

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "FortFrance_town";
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
	// ЦЕРКОВЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
                     locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// База мальтийских рыцарей	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Dungeon";
	locations[n].id.label = "Malta";
	locations[n].image = "loading\Malta_" + rand(1) + ".tga";
	//Town sack
	locations[n].type = "Malta";
	locations[n].townsack = "FortFrance";
	locations[n].islandId = "Martinique";
	//Sound
	locations[n].fastreload = "FortFrance";
	locations[n].Maltains = true;
	//Always
	locations[n].filespath.models = "locations\inside\Maltains";
	locations[n].models.always.Maltains = "Malta_Base";
	locations[n].models.always.InquisitionMaltainsFonars = "Malta_fonars";
	locations[n].models.always.locators = "Malta_locators";
	
	//Day
	locations[n].models.day.charactersPatch = "Malta_patch";
	//Night
	locations[n].models.night.charactersPatch = "Malta_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "reloadPr1";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "FortFrance_town";
	locations[n].reload.l2.emerge = "basement1";
	locations[n].reload.l2.autoreload = "0";
    locations[n].reload.l2.label = "Street";
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "FortFrance_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "FortFrance";
    locations[n].parent_colony = "FortFrance";
 	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "FortFrance_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_House";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseS4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);

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
	locations[n].reload.l4.go = "FortFrance_Graveyard_Dungeon";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////	//Подземелье
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "FortFrance_Graveyard_Dungeon";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].type = "Dungeon";
	locations[n].townsack = "FortFrance";
	locations[n].islandId = "Martinique";
	//Sound
	//Always
	locations[n].filespath.models = "locations\Inside\DungeonVault2";
	locations[n].models.always.DungeonVault2 = "DungeonVault2";
	locations[n].models.always.InquisitionDungeonVault2Fonars = "DungeonVault2_fonars";
	locations[n].models.always.locators = "DungeonVault2_locators";

	//Day
	locations[n].models.day.charactersPatch = "DungeonVault2_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Martinique_House";
	Locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.label = "House";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	locations[n].locators_radius.item.berglar1 = 4.5;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Бальтрама	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseBaltram";
	locations[n].id.label = "House Baltram";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseH6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_HouseHut2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseH2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_HouseHut4";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseH4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_HouseHut5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseH5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_HouseResidence";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\CobHouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	Locations[n].QuestlockWeather = "20 Hour";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseS7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LibraryHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_0.tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "FortFrance_town";
	Locations[n].reload.l1.emerge = "houseS10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator1 = 0.8;

	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход в джунгли из Форт де Франс
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitY";
	Locations[n].models.always.townExit = "townExitY";
	Locations[n].models.always.townWalls = "townExitY_stone";
	
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
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "FortFrance";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "FortFrance_Graveyard";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Graveyard";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "FortFrance_fort";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "FortFrance Fort";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////
	//кладбище
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "FortFrance_Graveyard";
	locations[n].id.label = "Graveyard";
	Locations[n].image = "loading\Cemetery_3.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
	locations[n].fennisgrass = 1;
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

	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.go = "FortFrance_ExitTown";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Martinique_jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l3.name = "reload6";
	Locations[n].reload.l3.go = "FortFrance_Kolokol_house";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "FortFrance_church IM";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reload4";
	Locations[n].reload.l5.go = "FortFrance_CryptBig1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "FortFrance_KeepersHouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	n = n + 1; 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// крипта большая - 1
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_CryptBig1";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "FortFrance_Graveyard";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Common_CryptBig2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Crypt";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Колокольня
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "FortFrance_Kolokol_house";
	locations[n].label = "Kolokol house";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	Locations[n].townsack = "FortFrance";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "FortFrance_Graveyard";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	locations[n].reload.l1.label = "Graveyard";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "FortFrance_church IM";
	locations[n].id.label = "Muelle church";
	locations[n].image = "loading\inside\church.tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Church_Inside\";
	Locations[n].models.always.l1 = "church";
	locations[n].models.always.church = "Church";
	locations[n].models.always.church.level = 65538;
	Locations[n].models.always.locators = "church_locators";
	Locations[n].models.always.window = "church_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "church_patch";
	//Night
	Locations[n].models.night.charactersPatch = "church_patch";
	//Environment
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "FortFrance_Graveyard";
	Locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "FortFrance_Graveyard_crypt2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Dungeon";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "FortFrance_Graveyard_crypt";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Dungeon";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Старый подвал
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "FortFrance_Graveyard_crypt2";
	Locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "FortFrance";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "Martinique";
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	locations[n].VaterSkeletons = 4+MOD_SKILL_ENEMY_RATE/2; // число монстров в локации
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
	locations[n].reload.l1.go = "FortFrance_church IM";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "church";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortFrance_Graveyard_Grot";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Cave";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Затопленная пещера 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Graveyard_Grot";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].islandId = "cave";
	locations[n].islandId = "Martinique";
	locations[n].type = "underwater";
	locations[n].changeAnimation = "swim"; //сменить анимацию на плавание
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernMedium4";
	locations[n].models.always.cavernMedium4 = "cavernMedium4";
	locations[n].models.always.cavernMedium4.sea_reflection = 1;
	locations[n].models.always.locators = "cavernMedium4_locators";	
	//Day
	locations[n].models.day.charactersPatch = "cavernMedium4_patch";
	//Night
	locations[n].models.night.charactersPatch = "cavernMedium4_patch";
	//Environment
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
	locations[n].reload.l1.go = "FortFrance_Graveyard_crypt2";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Dungeon";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Shore89";
	locations[n].reload.l2.emerge = "reload3_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Shore89";
	locations[n].locators_radius.reload.reload2_back = 2;
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_church IM";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "FortFrance_crypt";
	Locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "FortFrance_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_0.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "FortFrance_Graveyard_crypt";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Дом	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "FortFrance_KeepersHouse";
	locations[n].id.label = "house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "FortFrance_Graveyard";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	n = n + 1;
	
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_jungle_02";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "FortFrance_Graveyard";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "ExitTown";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Martinique_jungle_04";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж Ламантен
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore38";
	locations[n].id.label = "Shore38";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore38";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_jungle_04";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Martinique";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Shore38";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore38";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Martinique_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Martinique_jungle_01";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_Grot";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Martinique_Jungle_04";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_Grot";
	locations[n].id.label = "Grot";
     locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Cave";
	locations[n].islandId = "Martinique";
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

	locations[n].models.always.rock2 = "rock2";
	Locations[n].models.always.rock2.locator.group = "box";
	Locations[n].models.always.rock2.locator.name = "mining2";	

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
	locations[n].reload.l1.go = "Martinique_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Martinique_jungle_03";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "LeFransua_ExitTown";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore39";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore39";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Martinique_Dunes_Jungle";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////	////// Джунгли	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                   locations[n].id = "Martinique_Dunes_Jungle";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].DisableEncounters = true;
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_jungle_03";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Martinique_jungle_house";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Дом в джунглях	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Martinique_jungle_house";
	locations[n].id.label = "Jungle house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "Martinique_Dunes_Jungle";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	n = n + 1;	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Бухта Ле Марен
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore39";
	locations[n].id.label = "Shore39";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore39";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Martinique";
	locations[n].Chestgennot = true; // не генерить сундуки
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
	locations[n].reload.l1.go = "Martinique_jungle_03";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Martinique";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Порт Ле Франсуа
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_port";
	locations[n].id.label = "LeFransua Port";
	locations[n].image = "loading\seaStand.tga";
	locations[n].worldmap = "LeFransua_port";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Town sack
	locations[n].townsack = "LeFransua";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_LeFransua\Port";
	Locations[n].models.always.locators = "LeFransuaPort_locators";
	Locations[n].models.always.seabed = "LeFransuaPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "LeFransuaPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.grasspatch = "LeFransuaPort_grass";
	//Day
	Locations[n].models.day.charactersPatch = "LeFransuaPort_patch_day";
	Locations[n].models.day.fonar = "LeFransuaPort_fd";
	locations[n].models.day.rinok = "LeFransuaPort_rinok";
	//Night
	Locations[n].models.night.fonar = "LeFransuaPort_fn";
	Locations[n].models.night.charactersPatch = "LeFransuaPort_patch_night";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Martinique";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Martinique";
	Locations[n].reload.l3.emerge = "reload_3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "LeFransua_PortOffice";
	Locations[n].reload.l4.emerge = "reload1_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "PortOffice";
	locations[n].reload.l4.close_for_night = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "LeFransua_HouseHut6";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "LeFransua_HouseHut5";
	Locations[n].reload.l6.emerge = "reload1_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  ПОРТОВЫЙ ОФИС	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\PortOffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_Port";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Port";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseHut6";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut6";
	locations[n].models.always.locators = "Hut6_locators";
	locations[n].models.always.tavern = "Hut6";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut6_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut6_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut6_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeFransua_Port";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseHut5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_Port";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              // Город Ле Франсуа
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_town";
	locations[n].id.label = "Street";
	locations[n].image = "loading\towns\pearl5.tga";
	locations[n].worldmap = "Martinique";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Sound
	locations[n].type = "town";
	Locations[n].townsack = "LeFransua";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_LeFransua\Town";
	Locations[n].models.always.locators = "LeFransua_locators";
	locations[n].models.always.town.sea_reflection = 1;
	Locations[n].models.always.town = "LeFransua";
	Locations[n].models.always.grassPatch = "LeFransua_grass";
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

	locations[n].models.always.L4 = "tree";
	Locations[n].models.always.L4.locator.group = "item";
	Locations[n].models.always.L4.locator.name = "flower1";
	Locations[n].models.always.L4.tech = "DLightModel";
	locations[n].models.always.L5 = "tree";
	Locations[n].models.always.L5.locator.group = "item";
	Locations[n].models.always.L5.locator.name = "flower2";
	Locations[n].models.always.L5.tech = "DLightModel";

	//Day
	Locations[n].models.day.fonar = "LeFransua_fd";
	Locations[n].models.day.charactersPatch = "LeFransua_patch";

	//Night
	Locations[n].models.night.fonar = "LeFransua_fn";
	Locations[n].models.night.charactersPatch = "LeFransua_patch";

	Locations[n].models.day.jumppatch = "LeFransua_jump_patch";
	Locations[n].models.night.jumppatch = "LeFransua_jump_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeFransua_port";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port";

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "LeFransua_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "LeFransua_tavern";
	locations[n].reload.l4.emerge = "reload4";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "LeFransua_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "LeFransua_brothel";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House";

	locations[n].reload.l7.name = "reload6_back";
	locations[n].reload.l7.go = "LeFransua_store";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Store";
	locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload7_back";
	locations[n].reload.l8.go = "LeFransua_church";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Church";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload8_back";
	locations[n].reload.l9.go = "LeFransua_bank";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Usurer House";
	locations[n].reload.l9.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "LeFransua_ExitTown";
	locations[n].reload.gate.emerge = "reload2";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";

    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.

	Locations[n].reload.l11.name = "reload1";
	Locations[n].reload.l11.go = "LeFransua_HouseInsideR1";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Abuyin_House";

	Locations[n].reload.l12.name = "reload18";
	Locations[n].reload.l12.go = "LeFransua_HouseHut7";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House";

	Locations[n].reload.l13.name = "reload17";
	Locations[n].reload.l13.go = "LeFransua_House4";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Loy_House";

    // --> Комоны, загрушки. Номера с начинаются с 20.

	Locations[n].reload.l20.name = "reload21";
	Locations[n].reload.l20.go = "CommonCobHouse";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "House";

	Locations[n].reload.l21.name = "reload7";
	Locations[n].reload.l21.go = "House_Samuel";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.close_for_night = 1;
	Locations[n].reload.l21.label = "House Samuel";

	Locations[n].reload.l22.name = "reload16";
	Locations[n].reload.l22.go = "CommonDoubleflourHouse_1";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "House";

	Locations[n].reload.l23.name = "reload13";
	Locations[n].reload.l23.go = "LeFransua_HouseInsideR16";
	Locations[n].reload.l23.emerge = "reload1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "House_booc";

	Locations[n].reload.l24.name = "reload1";
	Locations[n].reload.l24.go = "CommonPirateHouse";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.label = "House";

	Locations[n].reload.l25.name = "reload8";
	Locations[n].reload.l25.go = "CommonRoom_MH";
	Locations[n].reload.l25.emerge = "reload1";
	Locations[n].reload.l25.autoreload = "0";
	Locations[n].reload.l25.label = "House";

	Locations[n].reload.l26.name = "reload20";
	Locations[n].reload.l26.go = "House_David";
	Locations[n].reload.l26.emerge = "reload1";
	Locations[n].reload.l26.autoreload = "0";
	Locations[n].reload.l26.label = "HouseDavid";

	Locations[n].reload.l27.name = "reload10";
	Locations[n].reload.l27.go = "CommonRoom_MH3";
	Locations[n].reload.l27.emerge = "reload1";
	Locations[n].reload.l27.autoreload = "0";
	Locations[n].reload.l27.label = "House";

	Locations[n].reload.l28.name = "reload12";
	Locations[n].reload.l28.go = "CommonRoom_MH2";
	Locations[n].reload.l28.emerge = "reload1";
	Locations[n].reload.l28.autoreload = "0";
	Locations[n].reload.l28.label = "House";

	Locations[n].reload.l29.name = "reload6";
	Locations[n].reload.l29.go = "CommonDoubleflourHouse_2";
	Locations[n].reload.l29.emerge = "reload1";
	Locations[n].reload.l29.autoreload = "0";
	Locations[n].reload.l29.label = "House";

	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города Ле Франсуа	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	locations[n].citizens = true; 
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].fennisgrass = 5;
	//Sound
	locations[n].type = "jungle";
	Locations[n].townsack = "LeFransua";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_LeFransua\Exit";
	Locations[n].models.always.locators = "LeFransuaExit_locators";
	Locations[n].models.always.exit = "LeFransuaExit";
	locations[n].models.always.Exit.sea_reflection = 1;
	locations[n].models.always.wfl = "LeFransuaExit_wfl";
	Locations[n].models.always.rfl = "LeFransuaExit_rfl";
	locations[n].models.always.dno = "LeFransuaExit_dno";
	Locations[n].models.always.grassPatch = "LeFransuaExit_grass";
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

	locations[n].models.always.L5 = "tree";
	Locations[n].models.always.L5.locator.group = "item";
	Locations[n].models.always.L5.locator.name = "flower21";
	Locations[n].models.always.L5.tech = "DLightModel";
	locations[n].models.always.L6 = "tree";
	Locations[n].models.always.L6.locator.group = "item";
	Locations[n].models.always.L6.locator.name = "flower22";
	Locations[n].models.always.L6.tech = "DLightModel";
	locations[n].models.always.L7 = "tree";
	Locations[n].models.always.L7.locator.group = "item";
	Locations[n].models.always.L7.locator.name = "flower23";
	Locations[n].models.always.L7.tech = "DLightModel";
	locations[n].models.always.L8 = "tree";
	Locations[n].models.always.L8.locator.group = "item";
	Locations[n].models.always.L8.locator.name = "flower24";
	Locations[n].models.always.L8.tech = "DLightModel";
	locations[n].models.always.L9 = "tree";
	Locations[n].models.always.L9.locator.group = "item";
	Locations[n].models.always.L9.locator.name = "flower25";
	Locations[n].models.always.L9.tech = "DLightModel";
	locations[n].models.always.L10 = "tree";
	Locations[n].models.always.L10.locator.group = "item";
	Locations[n].models.always.L10.locator.name = "flower26";
	Locations[n].models.always.L10.tech = "DLightModel";
	locations[n].models.always.L11 = "tree";
	Locations[n].models.always.L11.locator.group = "item";
	Locations[n].models.always.L11.locator.name = "flower27";
	Locations[n].models.always.L11.tech = "DLightModel";
	locations[n].models.always.L12 = "tree";
	Locations[n].models.always.L12.locator.group = "item";
	Locations[n].models.always.L12.locator.name = "flower28";
	Locations[n].models.always.L12.tech = "DLightModel";
	locations[n].models.always.L13 = "tree";
	Locations[n].models.always.L13.locator.group = "item";
	Locations[n].models.always.L13.locator.name = "flower29";
	Locations[n].models.always.L13.tech = "DLightModel";
	locations[n].models.always.L14 = "tree";
	Locations[n].models.always.L14.locator.group = "item";
	Locations[n].models.always.L14.locator.name = "flower30";
	Locations[n].models.always.L14.tech = "DLightModel";
	locations[n].models.always.L15 = "tree";
	Locations[n].models.always.L15.locator.group = "item";
	Locations[n].models.always.L15.locator.name = "flower31";
	Locations[n].models.always.L15.tech = "DLightModel";

	locations[n].models.always.fence = "fence";
	Locations[n].models.always.fence.locator.group = "item";
	Locations[n].models.always.fence.locator.name = "flower32";
	Locations[n].models.always.fence.tech = "DLightModel";	

	locations[n].models.always.horse_fence = "horse_fence";
	Locations[n].models.always.horse_fence.locator.group = "item";
	Locations[n].models.always.horse_fence.locator.name = "flower33";
	Locations[n].models.always.horse_fence.tech = "DLightModel";

	locations[n].models.always.Field_Cannon_broken = "Field_Cannon_broken";
	Locations[n].models.always.Field_Cannon_broken.locator.group = "item";
	Locations[n].models.always.Field_Cannon_broken.locator.name = "flower34";
	Locations[n].models.always.Field_Cannon_broken.tech = "DLightModel";	

	locations[n].models.always.leaf1 = "leaf";
	Locations[n].models.always.leaf1.locator.group = "item";
	Locations[n].models.always.leaf1.locator.name = "flower35";
	Locations[n].models.always.leaf1.tech = "DLightModel";
	locations[n].models.always.leaf2 = "leaf";
	Locations[n].models.always.leaf2.locator.group = "item";
	Locations[n].models.always.leaf2.locator.name = "flower36";
	Locations[n].models.always.leaf2.tech = "DLightModel";
							

	//Waterfall
	Locations[n].models.always.wfl.uvslide.u0 = 0.6;
                  Locations[n].models.always.wfl.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl.tech = "LocationWaterFall";
	Locations[n].models.always.wfl.level = 48;
	Locations[n].models.always.wfl1 = "LeFransuaExit_wfl1";
	Locations[n].models.always.wfl1.uvslide.u0 = 0.6;
                  Locations[n].models.always.wfl1.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl1.tech = "LocationWaterFall";
	Locations[n].models.always.wfl1.level = 47;
	Locations[n].models.always.wfl2 = "LeFransuaExit_wfl2";
	Locations[n].models.always.wfl2.uvslide.u0 = 0.6;
                  Locations[n].models.always.wfl2.uvslide.u1 = 0.01;
	Locations[n].models.always.wfl2.tech = "LocationWaterFall";
	Locations[n].models.always.wfl2.level = 46;
	Locations[n].models.always.water = "LeFransuaExit_wtr";
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

	//Day
	Locations[n].models.day.charactersPatch = "LeFransuaExit_patch";
	Locations[n].models.day.fonar = "LeFransuaExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "LeFransuaExit_patch";
	Locations[n].models.night.fonar = "LeFransuaExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Martinique_jungle_02";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 4;
	Locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "LeFransua_town";
	Locations[n].reload.l2.emerge = "gate_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Street";

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "LeFransua_Cavern";
	Locations[n].reload.l3.emerge = "reload3_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Grot";

	Locations[n].reload.l4.name = "Reload4";
	Locations[n].reload.l4.go = "LeFransua_HouseExit1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House";

	Locations[n].reload.l5.name = "Reload5";
	Locations[n].reload.l5.go = "LeFransua_HouseExit2";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House";

	Locations[n].reload.l6.name = "Reload3";
	Locations[n].reload.l6.go = "LeFransua_HouseExit3";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseExit1";
	locations[n].id.label = "House_pressis";
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
	locations[n].reload.l1.go = "LeFransua_ExitTown";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "town_exit";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseExit2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut";
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
	locations[n].reload.l1.go = "LeFransua_ExitTown";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "town_exit";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseExit3";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse04";
	locations[n].models.always.mediumhouse04 = "mediumhouse04";
	locations[n].models.always.mediumhouse04.level = 65538;
	locations[n].models.day.locators = "mediumhouse04_locators";
	locations[n].models.night.locators = "mediumhouse04_Nlocators";

	Locations[n].models.always.mediumhouse04windows = "mediumhouse04_windows";
	Locations[n].models.always.mediumhouse04windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse04windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse04rand= "mediumhouse04_rand";
	locations[n].models.day.charactersPatch = "mediumhouse04_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeFransua_ExitTown";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "town_exit";
	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_bank";
	locations[n].id.label = "Usurer House";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload8_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "LeFransua_Bank_residence";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Bank Director";	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КАБИНЕТ ГЛАВЫ БАНКИРСКОГО ДОМА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_Bank_residence";
	locations[n].id.label = "Bank Director";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_Bank";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Usurer House";
	
	// запрем сундуки
	locations[n].box1.closed = true;	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_townhall";
	locations[n].id.label = "LeFransua_townhall";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Sound
	locations[n].islandId = "Martinique";
	locations[n].type = "residence";
	locations[n].fastreload = "LeFransua";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "CommonResidence_4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l3.name = "reload2"; //кабинет направо от входа
	locations[n].reload.l3.go = "LeFransua_TownhallRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Townhall_Barbazon";
	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "LeFransua_TownhallRoom";
	locations[n].id.label = "Townhall_Barbazon";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "LeFransua";
	//Models
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeFransua_townhall";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator1 = 0.8;

	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload14";
	locations[n].reload.l1.autoreload = "0";
     locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "LeFransua_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "LeFransua_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "LeFransua_SecBrRoom";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Always
	locations[n].filespath.models = "locations\inside\bedRoom1";
	locations[n].models.always.bedRoom1 = "bedRoom1";
	locations[n].models.always.bedRoom1.level = 65538;
	Locations[n].models.always.bedRoom1windows = "mediumhouse01_windows";
	Locations[n].models.always.bedRoom1windows.tech = "LocationWindows";
	locations[n].models.always.bedRoom1windows.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "bedRoom1_locators";
	Locations[n].models.day.bedRoom1rand = "bedRoom1_rand";
	locations[n].models.day.charactersPatch = "bedRoom1_patch";
	//Night
	locations[n].models.night.locators = "bedRoom1_Nlocators";
	locations[n].models.night.charactersPatch = "bedRoom1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeFransua_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Shipyard01\";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

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
	locations[n].id = "LeFransua_store";
	locations[n].id.label = "Store"
	locations[n].filespath.models = "locations\inside\Store03\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload6_back";
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
	// ТАВЕРНА
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_Tavern";
	locations[n].id.label = "Tavern25";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern02\";
	locations[n].models.always.tavern = "tavern02";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern02_locators";
	locations[n].models.always.window = "tavern02_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "tavern02_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload4_back";
	Locations[n].reload.l1.go = "LeFransua_Town";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "LeFransua_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "LeFransua_tavern_ups";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "packhouse";

	locations[n].reload.l4.name = "reload1_back";
	locations[n].reload.l4.go = "CommonRoom_MH10";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// подсобка таверны, Ле Франсуа
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_tavern_ups";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	locations[n].id.label = "packhouse";
	locations[n].MustSetReloadBack = true;
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_tavern";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "LeFransua_tavern";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church_1.tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload7_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Офис Лоаншарка
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_UsurerHouse";
	locations[n].id.label = "house";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\MediumHouse";
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";
	//Night
	Locations[n].models.night.charactersPatch = "MH_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Абуоина	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_HouseInsideR1";
	locations[n].id.label = "Abuyin_House";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse02";
	locations[n].models.always.largehouse02 = "largehouse02";
	locations[n].models.always.largehouse02.level = 65538;
	locations[n].models.always.locators = "largehouse02_locators";

	Locations[n].models.always.largehouse02windows = "largehouse02_windows";
	Locations[n].models.always.largehouse02windows.tech = "LocationWindows";
	locations[n].models.always.largehouse02windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.always.largehouse02rand= "largehouse02_rand";
	locations[n].models.day.charactersPatch = "largehouse02_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse02_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "LeFransua_HouseHut7";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut7";
	locations[n].models.always.locators = "Hut7_locators";
	locations[n].models.always.tavern = "Hut7";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut7_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut7_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut7_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "LeFransua_town_room";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l1.label = "house";
	n = n + 1;

	locations[n].id = "LeFransua_town_room";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\BigHouse08.tga";
	//Town sack
	Locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
 	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_HouseHut7";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
    	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_HouseInsideR16";
	locations[n].id.label = "House_booc";
	locations[n].image = "loading\inside\TwoFloorHouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\TwoFloorHouse";
	locations[n].models.always.house = "TwoFloorHouse";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "TwoFloorHouse_locators";
	locations[n].models.night.locators = "TwoFloorHouse_Nlocators";
	locations[n].models.always.window = "TwoFloorHouse_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.TwoFloorHouseRand= "TwoFloorHouse_rand";
	locations[n].models.day.charactersPatch = "TwoFloorHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "TwoFloorHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload13";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.item.item2 = 0.9;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Самуила	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "House_Samuel";
	locations[n].id.label = "House Samuel";
	locations[n].image = "loading\outside\DrinkingHouse.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\StoneHouse";
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
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "House_David";
	locations[n].id.label = "HouseDavid";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload20";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Эдварда Лоу	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "LeFransua_House4";
	locations[n].id.label = "Loy_House";
	locations[n].image = "loading\inside\flamhouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "LeFransua";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "LeFransua";
	locations[n].islandId = "Martinique";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "LeFransua_town";
	locations[n].reload.l1.emerge = "reload17";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);

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
	// Вход в пещеру
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "LeFransua_Cavern";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\cave_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
 	locations[n].islandId = "Martinique";
	locations[n].islandIdAreal = "Martinique";
	locations[n].questflower = 1;
	locations[n].mining4.key = "minepick";
	locations[n].VaterSkeletons = 4+MOD_SKILL_ENEMY_RATE/2; // число монстров в локации
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernMedium3";
	locations[n].models.always.cavernMedium3 = "cavernMedium3";
	locations[n].models.always.cavernMedium3.sea_reflection = 1;
	locations[n].models.always.locators = "cavernMedium3_locators";	
	//Day
	locations[n].models.day.charactersPatch = "cavernMedium3_patch";
	Locations[n].models.day.jumpPatch = "CavernMedium3_jump";
	//Night
	locations[n].models.night.charactersPatch = "cavernMedium3_patch";
	Locations[n].models.night.jumpPatch = "CavernMedium3_jump";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].MaxWaveHeigh = 0.9;
	//Reload map

	Locations[n].reload.l1.name = "reload3_back";
	Locations[n].reload.l1.go = "LeFransua_ExitTown";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "ExitTown";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "LeFransua_Lighthouse_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave entrance";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave";
	Locations[n].locators_radius.reload.reload2_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из пещеры
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "LeFransua_Lighthouse_01";
	locations[n].id.label = "Cave entrance";
locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Martinique";
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
	Locations[n].reload.l1.go = "LeFransua_Cavern";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Shore89";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore89";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                Пляж     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Shore89";
	locations[n].id.label = "Shore89";
//	locations[n].worldmap = "Shore89";
	Locations[n].image = "loading\outside\Sandshore.tga";
	Locations[n].name = "Ship";
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Martinique";
	locations[n].mining3.key = "minepick";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore11";
	Locations[n].models.always.shore11 = "sandshore";
	locations[n].models.always.shore11.sea_reflection = 1;
	Locations[n].models.always.shore11seabed = "sandshore_sb";
	Locations[n].models.always.locators = "sandshore_quest3";
	
	Locations[n].models.always.shore11_quest = "sandshore_quest";
	locations[n].models.always.shore11_quest.sea_reflection = 1;
	Locations[n].models.always.shore11_quest_seabed = "sandshorequest_sb";
	
	Locations[n].models.always.grassPatch = "sandshore_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	locations[n].models.always.l1.sea_reflection = 1;
	
	Locations[n].models.always.Waterfall1 = "WaterFall1";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.2;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;
	
	Locations[n].models.always.Waterfall2 = "WaterFall2";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 49;

	locations[n].models.always.rock2 = "rock2";
	Locations[n].models.always.rock2.locator.group = "box";
	Locations[n].models.always.rock2.locator.name = "mining3";
		
	//Day
	locations[n].models.day.charactersPatch = "sandshore_patch";
	//Night
	locations[n].models.night.charactersPatch = "sandshore_patch";	
	// Jump patch
	Locations[n].models.day.jumpPatch = "sandshore_jump_patch";
	Locations[n].models.night.jumpPatch = "sandshore_jump_patch";
	
	Locations[n].animals = "true";
	Locations[n].heaters_night_only = 1;
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.go = "LeFransua_Lighthouse_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "cave";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].items.randitem1 = "pistol4";

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "FortFrance_Graveyard_Grot";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Grot";
	locations[n].locators_radius.reload.reload3_back = 2;

	locations[n].reload.l3.name = "reload4_back";
	locations[n].reload.l3.go = "Shore89_Grot";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Grot";
	locations[n].locators_radius.reload.reload4_back = 0.5;

	locations[n].reload.l4.name = "boat";
	locations[n].reload.l4.go = "Martinique";
	locations[n].reload.l4.emerge = "reload_5";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пещера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      locations[n].id = "Shore89_Grot";
	locations[n].id.label = "Grot";
     locations[n].image = "loading\inside\cave_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Martinique";
	locations[n].mining4.key = "minepick";
	locations[n].mining5.key = "minepick";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto1";
	locations[n].models.always.grotto1 = "grotto1";
	locations[n].models.always.grotto1alpha = "grotto1_alpha";
	Locations[n].models.always.grotto1alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto1alpha.level = 65532;
	locations[n].models.always.locators = "grotto1_Kslocators";

	locations[n].models.always.L1 = "rock2";
	Locations[n].models.always.L1.locator.group = "box";
	Locations[n].models.always.L1.locator.name = "mining5";
	Locations[n].models.always.L1.tech = "DLightModel";
	locations[n].models.always.L2 = "rock2";
	Locations[n].models.always.L2.locator.group = "box";
	Locations[n].models.always.L2.locator.name = "mining4";
	Locations[n].models.always.L2.tech = "DLightModel";

	//Day
	locations[n].models.day.charactersPatch = "grotto1_patch";
	//Night
	locations[n].models.night.charactersPatch = "grotto1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].MaxWaveHeigh = 4.0;
	//Reload map

	locations[n].reload.l1.name = "reload3_back";
	locations[n].reload.l1.go = "LeFransua_Cavern";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";

	n = n + 1;
				
	return n;
}