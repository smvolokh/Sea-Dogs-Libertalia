
int LocationInitProvidence(int n)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_town";
	locations[n].id.label = "SanAndres Port";
	locations[n].worldmap = "Providence";
	
	locations[n].townsack = "SanAndres";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	
	locations[n].image = "loading\Town.tga";	
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\Port\";
	Locations[n].models.always.l1 = "ApostatesPort";
	Locations[n].models.always.locators = "ApostatesPort_locators";	
	locations[n].models.always.SanAndresport.sea_reflection = 1;
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.portseabed = "ApostatesPort_sb";			
	Locations[n].models.always.grassPatch = "Apostatesport_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	//Day
	locations[n].models.day.charactersPatch = "ApostatesPort_patch_day";
	locations[n].models.day.fonars = "ApostatesPort_fd";
	Locations[n].models.day.jumpPatch = "ApostatesPort_jump_patch";
	Locations[n].models.day.rinok = "ApostatesPort_rinok";
	//Night
	locations[n].models.night.charactersPatch = "ApostatesPort_patch_night";
	locations[n].models.night.fonars = "ApostatesPort_fn";
	Locations[n].models.night.jumpPatch = "ApostatesPort_jump_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	
    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Providence";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Providence";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload4_back";
	locations[n].reload.l3.go = "SanAndres_townhall_port";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload6_back";
	locations[n].reload.l4.go = "SanAndres_store_port";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Store";
	locations[n].reload.l4.close_for_night = 1;

	locations[n].reload.l5.name = "reload10_back";
	locations[n].reload.l5.go = "SanAndres_PortOffice";
	locations[n].reload.l5.emerge = "reload1_back";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "PortOffice";
	locations[n].reload.l5.close_for_night = 1;
	
	
	locations[n].reload.l6.name = "gate_back";
	locations[n].reload.l6.go = "SanAndres_town_2";
	locations[n].reload.l6.emerge = "reload1_back";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "SanAndres Port";
	
	LocatorReloadEnterDisable("SanAndres_town", "gate_back", true); // Закроем, потому что еще нет ничего там

	//locations[n].reload.gate.name = "gate_back";
	//locations[n].reload.gate.go = "SanAndres_ExitTown";
	//locations[n].reload.gate.emerge = "reload3";
	//locations[n].reload.gate.autoreload = "0";
	//locations[n].reload.gate.label = "ExitTown";
	
    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.

	locations[n].reload.l11.name = "basement1";
	locations[n].reload.l11.go = "SanAndres_Dungeon";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Dungeon";

    // --> Комоны, заглушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseH1";
	locations[n].reload.l20.go = "CommonRoom_MH";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseH2";
	locations[n].reload.l21.go = "CommonRoom_MH4";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "reload3_back";
	locations[n].reload.l22.go = "CommonRoom_MH2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";
		
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_store_port";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store03\";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town";
	locations[n].reload.l1.emerge = "reload6_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";
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
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_townhall_port";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SanAndres_town";
	locations[n].reload.l1.emerge = "reload4_back";
	locations[n].reload.l1.autoreload = "0";
                     locations[n].reload.l1.label = "SanAndres Port";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town";
	locations[n].reload.l1.emerge = "reload10_back";
	locations[n].reload.l1.autoreload = "0";
                     locations[n].reload.l1.label = "SanAndres Port";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД2
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_town_2";
	locations[n].id.label = "SanAndres Port";
	locations[n].worldmap = "Providence";
	
	locations[n].townsack = "SanAndres";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	
	locations[n].image = "loading\Town.tga";	
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\Town_02\";
	locations[n].models.always.town = "Town02";
	Locations[n].models.always.town.tech = "DLightModel";
	locations[n].models.always.town.sea_reflection = 1;	
	Locations[n].models.always.locators = "Town02_locators";
	Locations[n].models.always.grassPatch = "Town02_grass";
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

	//River
	Locations[n].models.always.dno = "Town02_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Town02_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Town02_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Town02_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";	
	//Day
	Locations[n].models.day.fonar = "Town02_fd";
	Locations[n].models.day.charactersPatch = "Town02_patch";
	Locations[n].models.day.rinok = "Town02_rinok";
	//Night
	Locations[n].models.night.fonar = "Town02_fn";
	Locations[n].models.night.charactersPatch = "Town02_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload_1_4_back";
	//locations[n].reload.l2.go = "SanAndres_town_4";
	locations[n].reload.l2.emerge = "reload_4_1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "reload_1_3_back";
	//locations[n].reload.l3.go = "SanAndres_town_3";
	locations[n].reload.l3.emerge = "reload_3_1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	//locations[n].reload.l4.name = "reload_2_3";
	//locations[n].reload.l4.go = "SanAndres_town_3";
	//locations[n].reload.l4.emerge = "reload_3_2";
	//locations[n].reload.l4.autoreload = "0";
	//locations[n].reload.l4.label = "SanAndres Port";

	locations[n].reload.l5.name = "reload_2_4_back";
	//locations[n].reload.l5.go = "SanAndres_town_4";
	locations[n].reload.l5.emerge = "reload_4_2_back";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "SanAndres Port";

	locations[n].reload.l6.name = "reload4_back";
	locations[n].reload.l6.go = "SanAndres_tavern";
	locations[n].reload.l6.emerge = "reload1_back";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Tavern";

	locations[n].reload.l7.name = "reload3_back";
	locations[n].reload.l7.go = "SanAndres_townhall";
	locations[n].reload.l7.emerge = "reload1_back";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Residence";

	locations[n].reload.l8.name = "reload5_back";
	locations[n].reload.l8.go = "SanAndres_shipyard";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Shipyard";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload6_back";
	locations[n].reload.l9.go = "SanAndres_store";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Store";
	locations[n].reload.l9.close_for_night = 1;

	locations[n].reload.l10.name = "reload8_back";
	locations[n].reload.l10.go = "SanAndres_bank";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "Usurer House";
	locations[n].reload.l10.close_for_night = 1;


    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.
	locations[n].reload.l11.name = "houseF2";
	locations[n].reload.l11.go = "SanAndres_houseF2";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "House";
	locations[n].reload.l11.close_for_night = 1;

	locations[n].reload.l12.name = "houseH2";
	locations[n].reload.l12.go = "SanAndres_houseH2";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";

    // --> Комоны, заглушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseS1";
	locations[n].reload.l20.go = "CommonCobHouse";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseF1";
	locations[n].reload.l21.go = "CommonRoom_MH2";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
	
	locations[n].reload.l22.name = "houseSp2";
	locations[n].reload.l22.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";
	
	locations[n].reload.l23.name = "houseH1";
	locations[n].reload.l23.go = "CommonRoom_MH";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseS2";
	locations[n].reload.l24.go = "CommonFlamHouse";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseSp3";
	locations[n].reload.l25.go = "CommonPirateHouse";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseF3";
	locations[n].reload.l26.go = "CommonResidence_BackHall";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

	locations[n].reload.l27.name = "houseF4";
	locations[n].reload.l27.go = "CommonStoneHouse";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_tavern";
	locations[n].id.label = "Tavern10";
	locations[n].filespath.models = "locations\inside\tavern03\";
	locations[n].image = "loading\inside\tavern.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "Providence";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].models.night.charactersPatch = "tavern08_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload4_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanAndres_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);

    ////////////////////////==> подсобка таверны
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PuertoPrincipe_sklad";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "sklad";
	n = n + 1;
				
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ НАВЕРХУ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_tavern";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern10";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store03\";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_2";
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
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard02\";
	locations[n].image = "loading\inside\shipyard.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_2";
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
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\residence.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
                     locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "SanAndres_TownhallRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "TownhallRoom";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_TownhallRoom"; //кабинет
	locations[n].id.label = "TownhallRoom";
	locations[n].image = "loading\inside\BigHouse01.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence12";
	locations[n].models.always.locators = "Res12_locators";
	locations[n].models.always.l1 = "Res12";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "Res12_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Res12_patch";
	//Night
	locations[n].models.night.charactersPatch = "Res12_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SanAndres_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "SanAndres_TownhallbedRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Bedroom01";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната отдыха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_TownhallbedRoom";
	locations[n].id.label = "Bedroom01";
	locations[n].image = "loading\inside\BigHouse08.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
 	locations[n].islandId = "Providence";
	//Models
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
	locations[n].reload.l1.go = "SanAndres_TownhallRoom";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "TownhallRoom";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload8_back";
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
	// Квестовый дом
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_houseF2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
 	locations[n].islandId = "Providence";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Квестовый дом
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_houseH2";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
 	locations[n].islandId = "Providence";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "houseH2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД3
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "SanAndres_town_3";
	locations[n].id.label = "SanAndres Port";
	locations[n].worldmap = "Providence";
	
	locations[n].townsack = "SanAndres";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].fennisgrass = 1;
	
	locations[n].image = "loading\Town.tga";	
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\Town_03\";
	locations[n].models.always.town = "Town03";
	Locations[n].models.always.town.tech = "DLightModel";
	locations[n].models.always.town.sea_reflection = 1;	
	Locations[n].models.always.locators = "Town03_locators";
	Locations[n].models.always.grassPatch = "Town03_grass";
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

	//River
	Locations[n].models.always.dno = "Town03_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Town03_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Town03_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Town03_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";
	//Day
	Locations[n].models.day.fonar = "Town03_fd";
	Locations[n].models.day.charactersPatch = "Town03_patch";
	//Night
	Locations[n].models.night.fonar = "Town03_fn";
	Locations[n].models.night.charactersPatch = "Town03_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload_3_1_back";
	//locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload_1_3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload_3_2_back";
	//locations[n].reload.l2.go = "SanAndres_town_4";
	locations[n].reload.l2.emerge = "reload_4_2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "reload_3_2";
	//locations[n].reload.l3.go = "SanAndres_town_2";
	locations[n].reload.l3.emerge = "reload_2_3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	locations[n].reload.l4.name = "gate1_back";
	//locations[n].reload.l4.go = "SanAndres_ExitTown_1";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "ExitTown";

	locations[n].reload.l5.name = "reload7_back";
	locations[n].reload.l5.go = "SanAndres_church";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "SanAndres Port";

	locations[n].reload.l6.name = "reload71_back";
	locations[n].reload.l6.go = "SanAndres_church";
	locations[n].reload.l6.emerge = "reload3";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "SanAndres Port";

    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.

	locations[n].reload.l11.name = "basement2";
	locations[n].reload.l11.go = "SanAndres_Dungeon";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Dungeon";

	locations[n].reload.l12.name = "reload_1";
	locations[n].reload.l12.go = "SanAndres_house_1";
	locations[n].reload.l12.emerge = "reload1_back";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";

    // --> Комоны, заглушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseH1";
	locations[n].reload.l20.go = "CommonRoom_MH";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseH2";
	locations[n].reload.l21.go = "CommonRoom_MH4";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseH3";
	locations[n].reload.l22.go = "CommonRoom_MH2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseH4";
	locations[n].reload.l23.go = "CommonRoom_MH3";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseH7";
	locations[n].reload.l24.go = "CommonRoom_MH7";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseF3";
	locations[n].reload.l25.go = "CommonRoom_MH9";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseF4";
	locations[n].reload.l26.go = "CommonRoom_MH10";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

	locations[n].reload.l27.name = "houseF1";
	locations[n].reload.l27.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";

	locations[n].reload.l28.name = "houseS2";
	locations[n].reload.l28.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

	locations[n].reload.l29.name = "houseS3";
	locations[n].reload.l29.go = "CommonPirateResidence";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";

	locations[n].reload.l30.name = "houseF2";
	locations[n].reload.l30.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "SanAndres_town_3";
	locations[n].reload.l1.emerge = "reload7_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "SanAndres_town_3";
	locations[n].reload.l2.emerge = "reload71_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "SanAndres_Crypt";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Church";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Вход в склеп
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_Crypt";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_church";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "SanAndres_crypt2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_crypt2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "SanAndres";
 	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_Crypt";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////	//Подземелье
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "SanAndres_Dungeon";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon.tga";
	//Town sack
	locations[n].type = "Dungeon";
	locations[n].townsack = "SanAndres";
	locations[n].islandId = "Providence";
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
	Locations[n].reload.l1.go = "SanAndres_town_3";
	Locations[n].reload.l1.emerge = "basement2";
	locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	locations[n].locators_radius.item.berglar1 = 4.5;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_house_1";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	//Sound
	locations[n].type = "house_Gotika";
 	locations[n].islandId = "Providence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut8";
	locations[n].models.always.locators = "Hut8_locators";
	locations[n].models.always.tavern = "Hut8";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut8_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut8_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut8_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_town_3";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                     locations[n].id = "SanAndres_ExitTown_1";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
                     //Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\TownExit2\";
	Locations[n].models.always.townExit = "townExit2";	
	Locations[n].models.always.locators = "townExit2_locators";		
	Locations[n].models.always.grassPatch = "townExit2_grass";
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
	locations[n].models.day.charactersPatch = "townExit2_patch";
	locations[n].models.day.fonars = "townExit2_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExit2_patch";
	locations[n].models.night.fonars = "townExit2_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "SanAndres_town_3";
	locations[n].reload.l1.emerge = "gate1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";
	locations[n].locators_radius.reload.reload2 = 1.8;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "SanAndres_fort";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "SanAndres Fort";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД4
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "SanAndres_town_4";
	locations[n].id.label = "SanAndres Port";
	locations[n].worldmap = "Providence";
	
	locations[n].townsack = "SanAndres";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	
	locations[n].image = "loading\Town.tga";	
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\Town_04\";
	locations[n].models.always.town = "Town04";
	Locations[n].models.always.town.tech = "DLightModel";
	locations[n].models.always.town.sea_reflection = 1;	
	Locations[n].models.always.locators = "Town04_locators";
	Locations[n].models.always.grassPatch = "Town04_grass";
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

	//River
	Locations[n].models.always.dno = "Town04_rb";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Town04_re";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Town04_rb";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Town04_rt";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";
	
	//Day
	Locations[n].models.day.fonar = "Town04_fd";
	Locations[n].models.day.charactersPatch = "Town04_patch_day";
	Locations[n].models.day.rinok = "Town04_rinok";
	//Night
	Locations[n].models.night.fonar = "Town04_fn";
	Locations[n].models.night.charactersPatch = "Town04_patch_night";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload_4_1_back";
	//locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload_1_4_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload_4_2_back";
	//locations[n].reload.l2.go = "SanAndres_town_2";
	locations[n].reload.l2.emerge = "reload_2_4_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "gate2_back";
	//locations[n].reload.l3.go = "SanAndres_ExitTown_2";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	locations[n].reload.l4.name = "reload9_back";
	locations[n].reload.l4.go = "SanAndres_brothel";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Brothel";

    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.

	locations[n].reload.l11.name = "basement3";
	locations[n].reload.l11.go = "SanAndres_Dungeon_2";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Dungeon";

    // --> Комоны, заглушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseH1";
	locations[n].reload.l20.go = "CommonRoom_MH";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseH2";
	locations[n].reload.l21.go = "CommonRoom_MH4";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseF1";
	locations[n].reload.l22.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseS1";
	locations[n].reload.l23.go = "CommonRoom_MH10";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseSp1";
	locations[n].reload.l24.go = "CommonPirateResidence";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";

	locations[n].reload.l25.name = "houseF2";
	locations[n].reload.l25.go = "CommonRoom_MH9";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_4";
	locations[n].reload.l1.emerge = "reload9_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "SanAndres_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "SanAndres_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "SanAndres_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\BigHouse03.tga";
 	//Town sack
	locations[n].townsack = "SanAndres";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "SanAndres";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Старый подвал
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "SanAndres_Dungeon_2";
	Locations[n].id.label = "Dungeon";
	Locations[n].image = "loading\inside\dungeon_1.tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "SanAndres";
	locations[n].parent_colony = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town_4";
	locations[n].reload.l1.emerge = "basement3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].locators_radius.item.berglar1 = 3.0;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                     locations[n].id = "SanAndres_ExitTown_2";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
                     //Models
	//Always
	locations[n].filespath.models = "locations\Gothic\Town_Apostates\TownExit1\";
	Locations[n].models.always.townExit = "townExit1";	
	Locations[n].models.always.locators = "townExit1_locators";		
	Locations[n].models.always.grassPatch = "townExit1_grass";
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
	locations[n].models.day.charactersPatch = "townExit1_patch";
	locations[n].models.day.fonars = "townExit1_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExit1_patch";
	locations[n].models.night.fonars = "townExit1_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "SanAndres_town_4";
	locations[n].reload.l1.emerge = "gate2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";
	locations[n].locators_radius.reload.reload2 = 1.8;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Providence_Jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";

	n = n + 1;











	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                     locations[n].id = "SanAndres_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "SanAndres";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";
	locations[n].locators_radius.reload.reload2 = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Providence_Jungle_01";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "SanAndres_fort";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "SanAndres Fort";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Providence_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "SanAndres_ExitTown";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore68";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore68";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Providence_jungle_02";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Providence_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "Providence_jungle_01";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.Reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Providence_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.Reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore69";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Shore69";
	locations[n].locators_radius.reload.Reload3_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Providence_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l3.go = "CryptQuarhodron";
	locations[n].reload.l3.emerge = "reload4";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Crypt Quarhodron";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Providence_jungle_02";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Гробница предводителя Куарходрона 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "CryptQuarhodron";
	locations[n].id.label = "Crypt Quarhodron";
                     locations[n].image = "loading\inside\cave.tga";
	//Sound
	locations[n].type = "Crypt";
	locations[n].islandId = "Providence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\cavernBig1";
	locations[n].models.always.cavernBig1 = "cavernBig1";
	locations[n].models.always.lamps = "cavernBig1_lamps";	
	locations[n].models.always.locators = "cavernBig1_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "grotto1_rays";
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
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Providence_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Бухта Ингальядо
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore68";
	locations[n].id.label = "Shore68";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore68";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "Providence_Jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Providence";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж Санта-Мария-дель-Мар
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore69";
	locations[n].id.label = "Shore69";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore69";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "Providence_Jungle_02";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Providence_Ruins";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
                     locations[n].locators_radius.reload.reload2_back = 1.5;

	locations[n].reload.l3.name = "boat";
	locations[n].reload.l3.go = "Providence";
	locations[n].reload.l3.emerge = "reload_3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Руины в джунглях	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Providence_Ruins";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "Alcove_2";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "Shore69";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore69";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "CryptCardimon";
	locations[n].reload.l2.emerge = "reload3_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Crypt Cardimon";
	locations[n].locators_radius.reload.reload2 = 1.3;

	n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Гробница жреца Кардимона	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "CryptCardimon";
	locations[n].id.label = "Crypt Cardimon";
    	locations[n].image = "loading\inside\cave3.tga";
	locations[n].RuinsZombie = 5; // число монстров в локации
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Providence";
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
	locations[n].reload.l1.go = "Providence_Ruins";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload4";
	locations[n].reload.l2.go = "Providence_Temple";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TEMPLE 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Providence_Temple";
	//Sound
	locations[n].type = "Alcove_2";
	locations[n].islandId = "Providence";
	locations[n].image = "loading\outside\temple_1.tga";
	locations[n].id.label = "Incas Temple";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Incas Temple\Temple\";
	Locations[n].models.always.locators = "hram_locators";
	Locations[n].models.always.l1 = "Hram";
	Locations[n].models.always.grasspatch = "hram_g";
	Locations[n].models.always.l2 = "hram_door";
	Locations[n].models.always.l2.tech = "DLightModel";	
	//Day
	Locations[n].models.day.charactersPatch = "Hram_p";
	Locations[n].models.day.jumppatch = "hram_j";
	//Night
	Locations[n].models.night.charactersPatch = "Hram_p";
	Locations[n].models.night.jumppatch = "hram_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "CryptCardimon";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Providence_Alcovee";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Providence_Alcovee";
	//Sound
	locations[n].image = "loading\outside\TempleInside.tga";
	locations[n].type = "Alcovee";
	locations[n].id.label = "Alcovee";
	//Models
	//Always
	Locations[n].models.always.locators = "Alcovee_l";
	Locations[n].models.always.l1 = "alcovee";
	//Rays
	Locations[n].filespath.models = "locations\Gothic\Incas Templee\Alcovee\";
	Locations[n].models.always.l2 = "rays";
	Locations[n].models.always.l2.level = 100;
	Locations[n].models.always.l2.tech = "LocVisRays";
	Locations[n].models.always.l2.uvslide.u1 = -0.02;
	Locations[n].models.always.l2.uvslide.v1 = -0.02;
	//Artifact
	Locations[n].models.always.l3 = "artifact";
	Locations[n].models.always.l3.locator.name = "artifact";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.rotate.x = 0.0;
	Locations[n].models.always.l3.rotate.y = 0.777;
	Locations[n].models.always.l3.rotate.z = 0.0;
	Locations[n].models.always.l3.tech = "EnvironmentShader";
	Locations[n].models.always.l3.reflection = 0.4;
	//Bird
	Locations[n].models.always.l4 = "Bird";
	Locations[n].models.always.l4.locator.name = "Bird";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "EnvironmentShader";
	Locations[n].models.always.l4.reflection = 0.4;
	//Blue portal
	Locations[n].models.always.blue1 = "Blueport";
	Locations[n].models.always.blue1.level = 100;
	Locations[n].models.always.blue1.tech = "LocVisRays";
	Locations[n].models.always.blue1.uvslide.u0 = 0.06;
	Locations[n].models.always.blue1.uvslide.v0 = 0.00;
	Locations[n].models.always.blue1.uvslide.u1 = 0.16;
	Locations[n].models.always.blue1.uvslide.v1 = 0.00;
	//Day
	Locations[n].models.day.charactersPatch = "alcovee_p";
	//Night
	Locations[n].models.night.charactersPatch = "alcovee_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcovee";
	//Reload map
	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Providence_Temple";
	Locations[n].reload.l2.emerge = "reload2";
                     Locations[n].reload.l2.autoreload = "1";    
	n = n + 1;

	return n;
}
