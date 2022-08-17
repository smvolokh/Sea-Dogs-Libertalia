
int LocationInitSentMartin(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "SentMartin";
	
	locations[n].townsack = "Marigo";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
	
	locations[n].filespath.models = "locations\Town_StMartin\Town\";
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
	locations[n].models.always.town = "StMartin";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "StMartin_signsA";
	locations[n].models.always.locators = "StMartin_locators";
	locations[n].models.always.seabed = "StMartin_sb";
	locations[n].models.always.grassPatch = "StMartin_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.1;

	//Day
	locations[n].models.day.fonar = "StMartin_fd";
	locations[n].models.day.charactersPatch = "StMartin_patch_day";
	locations[n].models.day.rinok = "StMartin_rinok";
	//Night
	locations[n].models.night.fonar = "StMartin_fn";
	locations[n].models.night.charactersPatch = "StMartin_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l0.name = "reload1";
	locations[n].reload.l0.go = "SentMartin";
	locations[n].reload.l0.emerge = "reload_1";
	locations[n].reload.l0.autoreload = "0";
	locations[n].reload.l0.label = "Sea";
	locations[n].locators_radius.reload.reload1 = 0.2;

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SentMartin";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Marigo_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.lR1.name = "reloadR1";
	locations[n].reload.lR1.go = "Marigo_TownhallRoom";
	locations[n].reload.lR1.emerge = "reload2";
	locations[n].reload.lR1.autoreload = "0";
	locations[n].reload.lR1.label = "Residence";
	locations[n].reload.lR1.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Marigo_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Marigo_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Marigo_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Shipyard";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Marigo_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Marigo_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "Marigo_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";
	
 	locations[n].reload.l91.name = "reload91";
	locations[n].reload.l91.go = "Marigo_SecBrRoom";
	locations[n].reload.l91.emerge = "reload2";
	locations[n].reload.l91.autoreload = "0";
	locations[n].reload.l91.label = "Brothel";

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "Marigo_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "Marigo_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "Marigo_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации.
	locations[n].reload.l11.name = "houseF1";
	locations[n].reload.l11.go = "Marigo_houseF1";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "House";
	
	locations[n].reload.l12.name = "houseSp2";
	locations[n].reload.l12.go = "Marigo_houseSp2";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";
	locations[n].reload.l12.disable = true; //закрыто до поры

	locations[n].reload.l13.name = "houseH2";
	locations[n].reload.l13.go = "Marigo_houseH2";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "House";
	locations[n].reload.l13.disable  = true; //дом закрыт до нужного момента
    
    // --> Комоны, загрушки. Номера с начинаются с 20.
	locations[n].reload.l20.name = "houseSp1";
	locations[n].reload.l20.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseS1";
	locations[n].reload.l21.go = "CommonPirateHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
    
	/*locations[n].reload.l22.name = "houseSp2";
	locations[n].reload.l22.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";*/
    
	locations[n].reload.l23.name = "houseH1";
	locations[n].reload.l23.go = "CommonRoom_MH9";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseS2";
	locations[n].reload.l24.go = "CommonFlamHouse";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";	
	n = n + 1;	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_tavern";
	locations[n].id.label = "Tavern8";
	locations[n].filespath.models = "locations\inside\tavern03\";
	locations[n].image = "loading\inside\tavern_hol.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Marigo_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_tavern_upstairs";
	locations[n].id.label = "Marigo_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store04\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
	//Models
	//Always
	locations[n].models.always.locators = "Store04_locators";
	locations[n].models.always.store = "Store04";
	locations[n].models.always.window = "store04_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "Store04_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
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
	locations[n].id = "Marigo_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence02";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
 	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Marigo_TownhallRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "TownhallRoom";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_TownhallRoom"; //кабинет
	locations[n].id.label = "TownhallRoom";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouse01_2Door";
	locations[n].models.always.model = "BigHouse01_2Door";
	locations[n].models.always.model.level = 65538;
	locations[n].models.day.locators = "BigHouse01_2Door_locators";
	locations[n].models.night.locators = "BigHouse01_2Door_Nlocators";
	locations[n].models.always.window = "BigHouse01_2Door_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouse01_2Door_patch";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse01_2Door_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Marigo_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Marigo_town";
	locations[n].reload.l2.emerge = "reloadR1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Marigo_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Marigo_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Marigo_town";
	locations[n].reload.l2.emerge = "reload91";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом по квесту Португальца	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_houseF1";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Marigo_RoomHouseF1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// комната с Португальцем
	////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_RoomHouseF1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_houseF1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	n = n + 1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Агнес Кристиансен	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_houseSp2";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\intside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "houseSp2"; // patch-8
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH6";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	
	locations[n].box1.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом представителя Голландской Вест-Индской компании
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_houseH2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_0.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
	locations[n].noFight = true; //до поры не даем тут драться
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "houseH2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.item.item1 = 0.9;
	n = n + 1;

	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "Marigo_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "Marigo";
    locations[n].parent_colony = "Marigo";
 	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	Locations[n].reload.l1.go = "Marigo_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Выход из города	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	//Sound
	locations[n].type = "exittown";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Marigo";

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Marigo_jungle_01";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Marigo_jungle_03";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "Marigo_Fort";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "1";
	locations[n].reload.l4.label = "Marigo Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Marigo_Graveyard";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Marigo_Plantation";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Плантация Мариго	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\Plantation_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_jungle_03";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	//дома
	locations[n].reload.l2.name = "houseSp1";
	locations[n].reload.l2.go = "MarigoPlantation_Sp1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = false;
	locations[n].reload.l2.label = "house";

	locations[n].reload.l3.name = "houseS1";
	locations[n].reload.l3.go = "MarigoPlantation_S1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = false;
	locations[n].reload.l3.label = "house";

	locations[n].reload.l4.name = "houseS2";
	locations[n].reload.l4.go = "MarigoPlantation_S2";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = false;
	locations[n].reload.l4.label = "house";

	locations[n].reload.l5.name = "houseF1";
	locations[n].reload.l5.go = "MarigoPlantation_F1";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = false;
	locations[n].reload.l5.label = "house";

	locations[n].reload.l6.name = "houseF2";
	locations[n].reload.l6.go = "MarigoPlantation_F2";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = false;
	locations[n].reload.l6.label = "house";

    locations[n].locators_radius.quest.detector1 = 5.0; //homo
    n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "MarigoPlantation_Sp1";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\intside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Plantation";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "MarigoPlantation_S1";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Plantation";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "MarigoPlantation_S2";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Plantation";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "MarigoPlantation_F1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Plantation";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "MarigoPlantation_F2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Plantation";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//кладбище
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Marigo_Graveyard";
	locations[n].id.label = "Graveyard";
	Locations[n].image = "loading\Cemetery_2.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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

	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Marigo_jungle_03";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Shore103";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Shore103";
	locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l3.name = "reload6";
	Locations[n].reload.l3.go = "Marigo_Kolokol_house";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Marigo_church IM";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reload4";
	Locations[n].reload.l5.go = "Marigo_CryptBig1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "Marigo_KeepersHouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	n = n + 1; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Вход в склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_CryptBig1";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	Locations[n].reload.l1.go = "Marigo_Graveyard";//Mosh
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Graveyard";
	Locations[n].items.randitem1 = "blade12";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Marigo_CryptBig2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "crypt";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_CryptBig2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_0.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "church IM2";
	locations[n].reload.l1.emerge = "LLquest3"; // reload2
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";

	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Колокольня
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Marigo_Kolokol_house";
	locations[n].label = "Kolokol house";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	Locations[n].townsack = "Villemstad";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	Locations[n].reload.l1.go = "Marigo_Graveyard";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.label = "Graveyard";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Marigo_church IM";
	locations[n].id.label = "Muelle church";
	locations[n].image = "loading\inside\church.tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\church_2\";
	Locations[n].models.always.l1 = "church2";
	locations[n].models.always.tavern = "Church2";
	locations[n].models.always.tavern.level = 65538;
	Locations[n].models.always.locators = "church2_locators";
	Locations[n].models.always.window = "church2_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "church2_patch";
	//Night
	Locations[n].models.night.charactersPatch = "church2_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigo_Graveyard";
	Locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Graveyard";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Marigo_Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Mines";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_church IM";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Marigo_Graveyard_crypt";
	Locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	Locations[n].box3.items.blade37 = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Marigo_Graveyard_crypt";
	Locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "crypt";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Дом	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Marigo_KeepersHouse";
	locations[n].id.label = "house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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
	Locations[n].reload.l1.go = "Marigo_Graveyard";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Graveyard";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Залив Грейт	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore103";
	locations[n].id.label = "Shore103";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore103";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Ruins";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Graveyard";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "SentMartin";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////
	//Руины в джунглях
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Marigo_Ruins";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	locations[n].RuinsZombie = 3; // число монстров в локации
	//Sound
	locations[n].type = "jungle";
	locations[n].fastreload = "Marigo";
 	locations[n].islandId = "SentMartin";
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

	locations[n].models.always.l4 = "church_back";
	Locations[n].models.always.l4.locator.group = "quest";
	Locations[n].models.always.l4.locator.name = "quest1";
	Locations[n].models.always.l4.tech = "DLightModel";

	//Day
	locations[n].models.day.charactersPatch = "ruins1_patch";
	//Night
	locations[n].models.night.charactersPatch = "ruins1_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Shore103";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Shore103";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Marigo_Ruins_crypt";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "church IM2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1; 

	//////////////////////////////////////////////////////////////////////////////////////////	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "church IM2";
	locations[n].id.label = "Muelle_church";
	locations[n].image = "loading\outside\ChurchRuin.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].islandId = "Marigo";
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
	Locations[n].reload.l1.go = "Marigo_Ruins";
	Locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	
	/*
	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "MarigoGraveyard_crypt";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "crypt";
	locations[n].locators_radius.Quest.LLquest6 = 3.0;
	*/

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "MarigoGraveyard_crypt2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "crypt";
	
	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Marigo_CryptBig2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "crypt";
	Locations[n].locators_radius.reload.reload2_back = 2;
	
	n = n + 1;
	

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Вход в пещеру	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Cave";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 1.3;
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Fishing_Settlement_Exit";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Пещера	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Cave";
	locations[n].id.label = "Cave";
	locations[n].image = "loading\inside\Cave_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
 	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Marigo_Jungle_02";
	locations[n].reload.l2.emerge = "reloadW";
	locations[n].locators_radius.reload.reload2 = 2.0;
	locations[n].locators_radius.item.berglar1 = 3.5;
	locations[n].locators_radius.item.CheckReload1 = 3.5;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "Marigo_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_ExitTown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Marigo_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	// locations[n].reload.l3.name = "reload3_back";
	// locations[n].reload.l3.go = "Marigo_CaveEntrance";
	// locations[n].reload.l3.emerge = "reload2";
	// locations[n].reload.l3.autoreload = "1";
	// locations[n].reload.l3.label = "Jungle";
	// locations[n].locators_radius.reload.reload2_back = 2.0;
	
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Fishing_Settlement_Exit";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Marigo_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "SentMartin";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle2";
	Locations[n].models.always.jungle = "jungle2";	
	Locations[n].models.always.locators = "jungle2_lSentMartin02";		
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

	locations[n].models.always.well_small = "well_big";
	Locations[n].models.always.well_small.locator.group = "reload";
	Locations[n].models.always.well_small.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small.tech = "DLightModel";
	//Day
	locations[n].models.day.charactersPatch = "jungle2_pSentMartin02";
	//Night
	locations[n].models.night.charactersPatch = "jungle2_pSentMartin02";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shore41";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore41";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore40";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore40";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Marigo_jungle_01";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;

	locations[n].reload.l4.name = "reloadW_back";
	locations[n].reload.l4.go = "Marigo_Cave";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Jungle";
	locations[n].locators_radius.reload.reloadW_back = 2.3;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Пляж41	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore41";
	locations[n].id.label = "Shore41";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore41";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Jungle_02";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "SentMartin";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                locations[n].locators_radius.reload.boat = 9.0;

	
	// для захвата корабля с суши
	locations[n].reload.l3.name = "boarding";
	locations[n].reload.l3.go = "none";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Boarding";
	locations[n].reload.l3.disable = true;
	locations[n].locators_radius.reload.boarding = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж40
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore40";
	locations[n].id.label = "Shore40";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore40";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Marigo_Jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "SentMartin";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	////////////////////////////////////////////////////////
    // Рыбацкое поселение Выход
    ////////////////////////////////////////////////////////
	locations[n].id = "Fishing_Settlement_Exit";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";

    //Town sack
	locations[n].townsack = "Marigo";
 	locations[n].islandId = "SentMartin";
	locations[n].type = "Village";
	
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\smugglerLairExit";
	Locations[n].models.always.smugglerLairExit = "smugglerLairExit";	
	Locations[n].models.always.locators = "smugglerLairExit_locators";		
	Locations[n].models.always.grassPatch = "smugglerLairExit_grass";
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
	locations[n].models.day.charactersPatch = "smugglerLairExit_patch";
	locations[n].models.day.fonars = "smugglerLairExit_fd";
	//Night
	locations[n].models.night.charactersPatch = "smugglerLairExit_patch";
	locations[n].models.night.fonars = "smugglerLairExit_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Fishing_Settlement_Town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Fishing_Settlement_Town";
	
	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Marigo_jungle_01";
	Locations[n].reload.l2.emerge = "reload3_back";
	Locations[n].reload.l2.autoreload = true;
	Locations[n].reload.l2.label = "gungle";
	
	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Marigo_CaveEntrance";
	Locations[n].reload.l3.emerge = "reload2_back";
	Locations[n].reload.l3.autoreload = true;
	Locations[n].reload.l3.label = "cave";
	n = n + 1;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Рыбацкое поселение Деревня
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Fishing_Settlement_Town";
	locations[n].id.label = "Streets";
	locations[n].image = "loading\inside\Town_0.tga";
	locations[n].townsack = "Marigo";
 	locations[n].islandId = "SentMartin";
                   locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].quest_loc = true;
	//Sound
	locations[n].type = "Village";
	LAi_LocationFantomsGen(&locations[n], true);	    
	//Models
	//Always
	locations[n].filespath.models = "locations\PirateFort";
	Locations[n].models.always.fort = "piratefort";	
	Locations[n].models.always.locators = "piratefort_locators";		
	Locations[n].models.always.grassPatch = "piratefort_grass";
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
	locations[n].models.day.fonar = "piratefort_fd";
	locations[n].models.day.charactersPatch = "piratefort_patch";
	//Night
	locations[n].models.night.fonar = "piratefort_fn";
	locations[n].models.night.charactersPatch = "piratefort_patch";	
	//Environment

	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Fishing_Settlement_Exit";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Exit";
	locations[n].locators_radius.reload.reload2_back = 1.8;
	
	Locations[n].reload.l2.name = "Reload4";
	Locations[n].reload.l2.go = "Fishing_HouseHut";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

	locations[n].reload.l3.name = "reload6";            //Tavern
	locations[n].reload.l3.go = "Fishing_Settlement_tavern";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Tavern";

	locations[n].reload.l14.name = "reload2";
	locations[n].reload.l14.go = "Settlement_store";
	locations[n].reload.l14.emerge = "reload1";
	locations[n].reload.l14.autoreload = "0";
	locations[n].reload.l14.label = "Store";
	Locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l15.name = "reload3";
	locations[n].reload.l15.go = "HouseJuleGotie";
	locations[n].reload.l15.emerge = "reload1";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "HouseJuleGotie";

	Locations[n].reload.l6.name = "reload5";
	Locations[n].reload.l6.go = "Settlement_townhall";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Townhall";
	Locations[n].reload.l6.close_for_night = 1;
                     n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Settlement_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Fishing_Settlement_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Streets";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Магазин	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Settlement_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store01\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Fishing_Settlement_town";
	locations[n].reload.l1.emerge = "reload2"; 
	locations[n].reload.l1.autoreload = "0";
     locations[n].reload.l1.label = "Streets";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Изба рыбака	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Fishing_HouseHut";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Fishing_Settlement_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";            //podval:)
	locations[n].reload.l2.go = "Fishing_Settlement";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Dungeon";
	locations[n].reload.l2.disable = 0;
	n = n + 1;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Podval	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                Locations[n].id = "Fishing_Settlement";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	locations[n].islandId = "SentMartin";
	//Sound
	locations[n].type = "Dungeon";
 	locations[n].islandId = "SentMartin";
    //Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1 = "DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1Stuff = "DungeonDuffer1_stuff";
	locations[n].models.always.locators = "DungeonDuffer1_locators";

	locations[n].locators_radius.item.duhi1 = 1.3;
	
	Locations[n].models.always.rays = "DungeonDuffer1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
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
	Locations[n].reload.l1.go = "Fishing_HouseHut";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House";
	locations[n].locators_radius.item.berglar1 = 6.0;
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Marigo_CaveEntrance_2";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "jungle";
	LAi_LocationFightDisable(&Locations[n], false);
	n = n + 1;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Fishing_Settlement_tavern";
	locations[n].id.label = "Tavern26";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	locations[n].usurer_hunters = true;
	locations[n].quest_loc = true;
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	locations[n].islandId = "SentMartin";
	//Sound
	locations[n].type = "tavern";
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
	locations[n].reload.l1.go = "Fishing_Settlement_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Streets";
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Fishing_Settlement_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "room";

    ////////////////////////==> подсобка таверны
	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Fishing_Settlement_Packhouse";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Room";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Fishing_Settlement_tavern_upstairs";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\tavern.tga";
	locations[n].islandId = "SentMartin";

	//Town sack
	locations[n].townsack = "StMartin";
	Locations[n].lockWeather = "Inside";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Fishing_Settlement";
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
	locations[n].reload.l1.go = "Fishing_Settlement_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Склад	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Fishing_Settlement_Packhouse";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
	locations[n].islandId = "SentMartin";
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
	Locations[n].reload.l1.go = "Fishing_Settlement_tavern";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern26";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ДОМ ЖУЛЯ ГОТЬЕ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseJuleGotie";
	locations[n].id.label = "House Jule Gotie";
	locations[n].image = "loading\inside\largehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Marigo";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigo";
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
	locations[n].reload.l1.go = "Fishing_Settlement_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Streets";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

locations[n].id = "Shore104";
	locations[n].id.label = "Shore104";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore104";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Strange_Grotto_3";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "SentMartin";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ТАЙНЫЙ ГРОТ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Strange_Grotto_3";
	locations[n].id.label = "Grotto Strange";
    	locations[n].image = "loading\inside\cave3.tga";
	locations[n].GrottoMonkey = 5; // число монстров в локации
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "SentMartin";
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
	locations[n].reload.l1.go = "Shore104";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore104";
	locations[n].locators_radius.reload.reload1_back = 2;
	
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Залив Гвана	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore105";
	locations[n].id.label = "Shore105";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore105";
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "SentMartin";
	locations[n].deadlocked = true;
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
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "SentMartin";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
	
	return n;
}
