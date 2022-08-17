
int LocationInitPortoBello(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ГОРОД
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "PortoBello";
	
	locations[n].townsack = "PortoBello";
	locations[n].fastreload = "PortoBello";
	locations[n].islandId = "Mein";
	
	locations[n].filespath.models = "locations\Town_PortoBello\Town\";
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
	locations[n].models.always.town = "PortoBello";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "PortoBello_signsA";
	locations[n].models.always.seabed = "PortoBello_sb";
	locations[n].models.always.locators = "PortoBello_locators";
	locations[n].models.always.grassPatch = "PortoBello_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	Locations[n].models.always.MillFan.locator.group = "WindMill";
	Locations[n].models.always.MillFan.locator.name ="Fan";	
	Locations[n].models.always.MillFan.rotate.x = 0.0;
	Locations[n].models.always.MillFan.rotate.y = 0.0;
	Locations[n].models.always.MillFan.rotate.z = 0.22;

	//Day
	locations[n].models.day.fonar = "PortoBello_fd";
	locations[n].models.day.charactersPatch = "PortoBello_patch_day";
	locations[n].models.day.rinok = "PortoBello_rinok";
	//Night
	locations[n].models.night.fonar = "PortoBello_fn";
	locations[n].models.night.charactersPatch = "PortoBello_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> Типовые городские локации, четкая фиксация на 10 номеров.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortoBello";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortoBello_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.lR1.name = "reloadR1";
	locations[n].reload.lR1.go = "PortoBello_TownhallRoom";
	locations[n].reload.lR1.emerge = "reload2";
	locations[n].reload.lR1.autoreload = "0";
	locations[n].reload.lR1.label = "Residence";
	locations[n].reload.lR1.close_for_night = 1;
	
	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortoBello_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l41.name = "reload41_back";
	locations[n].reload.l41.go = "PortoBello_tavern";
	locations[n].reload.l41.emerge = "reload4";
	locations[n].reload.l41.autoreload = "0";
	locations[n].reload.l41.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "PortoBello_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "PortoBello_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "PortoBello_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l71.name = "reload71_back";
	locations[n].reload.l71.go = "PortoBello_church";
	locations[n].reload.l71.emerge = "reload2";
	locations[n].reload.l71.autoreload = "0";
	locations[n].reload.l71.label = "Church";
	locations[n].reload.l71.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "PortoBello_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "PortoBello_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "PortoBello_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "PortoBello_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";

    // --> Квестовые локации.
	
	// --> Комоны, загрушки. Номера с начинаются с 20.
 	locations[n].reload.l20.name = "houseH4";
	locations[n].reload.l20.go = "CommonRoom_MH10";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseH2";
	locations[n].reload.l21.go = "CommonRoom_MH7";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";
	
	locations[n].reload.l22.name = "houseF2";
	locations[n].reload.l22.go = "CommonRoom_MH2";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseH1";
	locations[n].reload.l23.go = "CommonHut";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";
	
	locations[n].reload.l24.name = "houseF3";
	locations[n].reload.l24.go = "CommonRoom_MH2";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";
	
	locations[n].reload.l25.name = "houseS1";
	locations[n].reload.l25.go = "CommonPirateHouse";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";
	
	locations[n].reload.l26.name = "houseF1";
	locations[n].reload.l26.go = "CommonRoom_MH5";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";
	
 	locations[n].reload.l27.name = "houseH3";
	locations[n].reload.l27.go = "CommonRoom_MH7";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";
	
	locations[n].reload.l28.name = "houseSp2";
	locations[n].reload.l28.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

	locations[n].reload.l29.name = "houseS2";
	locations[n].reload.l29.go = "CommonStoneHouse";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";

 	locations[n].reload.l30.name = "houseS3";
	locations[n].reload.l30.go = "CommonFlamHouse";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";

 	locations[n].reload.l31.name = "houseS4";
	locations[n].reload.l31.go = "CommonPirateHouse";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

 	locations[n].reload.l32.name = "houseSp1";
	locations[n].reload.l32.go = "CommonDoubleflourHouse_1";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

 	locations[n].reload.l33.name = "houseS5";
	locations[n].reload.l33.go = "CommonCobHouse";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_tavern";
	locations[n].id.label = "Tavern9";
	locations[n].filespath.models = "locations\inside\tavern02\";
	locations[n].image = "loading\inside\tavern4.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PortoBello";
	locations[n].islandId = "Mein";
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.

    ////////////////////////==> подсобка таверны
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "CommonRoom_MH3";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortoBello_town";
	locations[n].reload.l4.emerge = "reload41";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// КОМНАТА В ТАВЕРНЕ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store04\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortoBello";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_town";
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
	locations[n].id = "PortoBello_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard03\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PortoBello";
 	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortoBello_Packhouse";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// СКЛАД НА ВЕРФИ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	locations[n].id = "PortoBello_Packhouse";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortoBello";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_Shipyard";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "shipyard";
	n = n + 1;

	
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence02";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PortoBello";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2"; //кабинет направо от входа
	locations[n].reload.l2.go = "PortoBello_TownhallRoom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "TownhallRoom";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_TownhallRoom";
	locations[n].id.label = "TownhallRoom";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortoBello";
 	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortoBello_town";
	locations[n].reload.l2.emerge = "reloadR1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	locations[n].locators_radius.reload.locator1 = 0.8;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_town";
	locations[n].reload.l2.emerge = "reload71";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "PortoBello_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "PortoBello";
    locations[n].parent_colony = "PortoBello";
 	locations[n].fastreload = "PortoBello";
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
	Locations[n].reload.l1.go = "PortoBello_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortoBello_Jungle_01";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_Plantation";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Plantation";
	locations[n].locators_radius.reload.reload2_back = 2.5;
	
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortoBello_fort";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "PortoBello Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "PortoBello_town";
	locations[n].reload.l4.emerge = "gate_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "PortoBello";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Плантация Порто-Белло
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\Plantation_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
	locations[n].citizens = true;    
	locations[n].soldiers = true;    
	locations[n].carrier = true;
	//Sound
	locations[n].type = "plantation";
	//Models
	//Always
	locations[n].filespath.models = "locations\BarbadosPlantation";
	locations[n].models.always.BarbadosPlantation = "BarbadosPlantation";	
	locations[n].models.always.reflect = "BarbadosPlantation_reflect";
	Locations[n].models.always.reflect.sea_reflection = 1;	
	locations[n].models.always.gate = "BarbadosPlantation_gateopen";	
	locations[n].models.always.locators = "BarbadosPlantation_locators_alt";	
	locations[n].models.always.grassPatch = "BarbadosPlantation_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.Waterfall = "waterfall";
	Locations[n].models.always.Waterfall.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall.level = 99949;	
	locations[n].models.always.plan1 = "plan1";
	locations[n].models.always.plan1.level = 9;	
	locations[n].models.always.plan2 = "plan2";
	locations[n].models.always.plan2.level = 8;	
	locations[n].models.always.plan3 = "plan3";
	locations[n].models.always.plan3.level = 7;	
	locations[n].models.always.plan4 = "plan4";
	locations[n].models.always.plan4.level = 6;
	
	locations[n].models.always.l1 = "BarbadosPlantation_wall";
	Locations[n].models.always.l1.tech = "DLightModel";
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
	
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortoBello_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2.5;

	//дома
	locations[n].reload.l3.name = "houseSp1";
	locations[n].reload.l3.go = "PortoBello_Plantation_Sp1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = false;
	locations[n].reload.l3.label = "house";

	locations[n].reload.l4.name = "houseS1";
	locations[n].reload.l4.go = "PortoBello_Plantation_S1";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = false;
	locations[n].reload.l4.label = "house";

	locations[n].reload.l5.name = "houseS2";
	locations[n].reload.l5.go = "PortoBello_Plantation_S2";
	locations[n].reload.l5.emerge = "reload2";
	locations[n].reload.l5.autoreload = false;
	locations[n].reload.l5.label = "house";

	locations[n].reload.l6.name = "houseF1";
	locations[n].reload.l6.go = "PortoBello_Plantation_F1";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = false;
	locations[n].reload.l6.label = "house";

	locations[n].reload.l7.name = "houseF2";
	locations[n].reload.l7.go = "PortoBello_Plantation_F2";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = false;
	locations[n].reload.l7.label = "house";

    locations[n].locators_radius.quest.detector1 = 5.0; //homo
    n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation_Sp1";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Plantation";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation_S1";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Plantation";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation_S2";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Plantation";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation_F1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Plantation";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Plantation_F2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortoBello";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Plantation";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;
	
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
	locations[n].questflower = 1;
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
	locations[n].reload.l1.go = "Panama_jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_Jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortoBello_ExitTown";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "ExitTown";
	locations[n].locators_radius.reload.reload3_back = 1.5;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    locations[n].id = "PortoBello_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Shore47";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l3.go = "PortoBello_Cave";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortoBello_Jungle_02";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот	// Addon 2016-1 Jason Пиратская линейка
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Cave";
	locations[n].id.label = "Grot";
 	locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto2";
	locations[n].models.always.grotto2 = "grotto2";
	locations[n].models.always.grotto2.sea_reflection = 1;
	locations[n].models.always.grotto2alpha = "grotto2_alpha";
	Locations[n].models.always.grotto2alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto2alpha.level = 65532;	
	locations[n].models.always.locators = "grotto2_locators";
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
	locations[n].reload.l1.go = "PortoBello_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// залив Москитос
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore47";
	locations[n].id.label = "Shore47";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore47";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "PortoBello_Jungle_02";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дарьенский залив
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore48";
	locations[n].id.label = "Shore48";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore48";
	//Sound
	locations[n].type = "x_seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "Panama_jungle_05";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Чирики-Гранте	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore114";
	locations[n].id.label = "Shore114";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore114";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// бухта Бокас-дель-Торо	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Shore115";
	locations[n].id.label = "Shore115";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore115";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 1;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 3.0;
	locations[n].locators_radius.reload.reload1_back = 1.5;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// лагуна Чирики
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore46";   
	locations[n].id.label = "Shore46";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore46";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore03";//бухту не менять, по вопросным квестам она нужна
	Locations[n].models.always.shore03 = "shore03";
	locations[n].models.always.shore03.sea_reflection = 1;
	Locations[n].models.always.shore03seabed = "shore03_sb";
	Locations[n].models.always.locators = "shore03_lcommon"; //заглушечный файл локаторов
		
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Shiriri_jungle_01";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "PortoBello";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shiriri_jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Shore46";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore46";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Shiriri_jungle_02";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
                locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Common_jungle_01"; //на зачарованный город
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                   locations[n].id = "Shiriri_jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "Shiriri_jungle_01";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shiriri_Cave";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Shiriri_jungle_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload3_back = 2.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                locations[n].id = "Shiriri_jungle_03";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
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
	locations[n].reload.l1.go = "Shiriri_jungle_02";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shiriri_jungle_04";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Dunes";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////// дюны	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Dunes";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	locations[n].DisableEncounters = true;
	locations[n].Chestgennot = true; // не генерить сундуки
 	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Portobello";
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
	locations[n].reload.l1.go = "Shiriri_jungle_03";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Amelia_house";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Dunes house";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	n = n + 1;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Амелии	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Amelia_house";
	locations[n].id.label = "Dunes house";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Portobello";
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
	locations[n].reload.l1.go = "Dunes";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                locations[n].id = "Shiriri_jungle_04";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "PortoBello";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle2";
	Locations[n].models.always.jungle = "jungle2";	
	Locations[n].models.always.locators = "jungle2_locators";
	Locations[n].models.always.locators = "Jungle2_lSentMartin02";	
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

	locations[n].models.always.well_small1 = "well_big";
	Locations[n].models.always.well_small1.locator.group = "reload";
	Locations[n].models.always.well_small1.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small1.tech = "DLightModel";

	locations[n].models.always.well_small2 = "dolly_F";
	Locations[n].models.always.well_small2.locator.group = "reload";
	Locations[n].models.always.well_small2.locator.name ="reloadW_back";	
	Locations[n].models.always.well_small2.tech = "DLightModel";

	//Day
	locations[n].models.day.charactersPatch = "jungle2_patch";
	locations[n].models.day.charactersPatch = "Jungle2_pSentMartin02";

	//Night
	locations[n].models.night.charactersPatch = "jungle2_patch";
	locations[n].models.night.charactersPatch = "Jungle2_pSentMartin02";
	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Shiriri_jungle_03";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shiriri_jungle_05";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortoBello_Indian_town";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 3;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Shiriri_jungle_05";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Shiriri_jungle_04";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shiriri_jungle_06"; 
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Джунгли 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                locations[n].id = "Shiriri_jungle_06";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
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
	
	Locations[n].models.always.l4 = "Jungle4_wall";	
	Locations[n].models.always.l4.tech = "DLightModel";
	//Day
	locations[n].models.day.charactersPatch = "jungle4_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle4_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shiriri_jungle_05";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shiriri_jungle_09"; 
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "DesMoines_mine";
	locations[n].reload.l3.emerge = "reload1_back"; 
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	Locations[n].reload.l3.disable = false;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в рудники
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shiriri_jungle_09";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Shiriri_Mines";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mines Destroy";
	locations[n].reload.l1.disable = 0;
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shiriri_jungle_06";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Копи	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shiriri_Mines";
	locations[n].image = "loading\Mine_" + rand(1) + ".tga";
	locations[n].id.label = "Mines Destroy";
	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
	//Models	
	//Always
	Locations[n].filespath.models = "Locations\Gothic\Colony\Mines";
	Locations[n].models.always.locators = "mine_l";
	Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "mine_p";
	//Night
	Locations[n].models.night.charactersPatch = "mine_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";		
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
	
	locations[n].locators_radius.item.duhi1 = 0.0;
	locations[n].locators_radius.box.box1 = 1.5;
	
	//Environment
	locations[n].environment.weather = "false";
	Locations[n].lockWeather = "Inside";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shiriri_jungle_09";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "torture_Shiriri";
	Locations[n].reload.l2.emerge = "Reload1_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Prison";
	Locations[n].locators_radius.reload.reload2_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "torture_Shiriri";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "Mein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Mein";
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
	Locations[n].reload.l1.go = "Shiriri_Mines";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";	
	Locations[n].reload.l1.label = "cave";
	n = n + 1;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Деревня индейцев	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "PortoBello_Indian_town";
	locations[n].id.label = "Village";
	locations[n].image = "loading\Village_" + rand(1) + ".tga";
	locations[n].indianVillage = true;
	//Sound
	locations[n].type = "Village";
	locations[n].islandId = "jungle";
	locations[n].islandIdAreal = "PearlIndian";
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
	Locations[n].reload.l1.go = "Shiriri_jungle_04";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "PortoBello_IndianlTown_shack1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "shack";
	Locations[n].reload.l2.autoreload = "0";
	
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "PortoBello_IndianlTown_shack2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "shack";
	Locations[n].reload.l3.autoreload = "0";
	
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "PortoBello_IndianlTown_shack3";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "shack";
	Locations[n].reload.l4.autoreload = "0";
	n = n + 1;		//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №1 - большая	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_IndianlTown_shack1";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "jungle";
	locations[n].islandIdAreal = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_1_inside";
	locations[n].models.always.Hut_1_inside = "Hut_1_inside";
	locations[n].models.always.Hut_1_inside.level = 65538;
	Locations[n].models.always.locators = "Hut_1_inside_locators";

	locations[n].models.always.back = "..\inside_back2";
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
	locations[n].reload.l1.go = "PortoBello_Indian_town";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].items.randitem2 = "indian016";
	Locations[n].items.randitem1 = "indian003";
	Locations[n].box.box1 = "Totem_004";	
	n = n + 1;		//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №2	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_IndianlTown_shack2";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "jungle";
	locations[n].islandIdAreal = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_2_inside";
	locations[n].models.always.Hut_2_inside = "Hut_2_inside";
	locations[n].models.always.Hut_2_inside.level = 65538;
	//locations[n].models.day.locators = "Hut_2_inside_locators";
	//locations[n].models.night.locators = "Hut_2_inside_ln";
	Locations[n].models.always.locators = "Hut_2_inside_locators";

	locations[n].models.always.Hut_2_back = "Hut_2_back";
	locations[n].models.always.Hut_2_back.level = 65538; 
	locations[n].models.always.back = "..\inside_back2";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.always.Hut_2_insiderand = "Hut_2_inside_rand_1";
	locations[n].models.day.charactersPatch = "Hut_2_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_2_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortoBello_Indian_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].box.box1 = "indian022";	
	n = n + 1;		//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №3	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_IndianlTown_shack3";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "jungle";
	locations[n].islandIdAreal = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut_2_inside";
	locations[n].models.always.Hut_2_inside = "Hut_2_inside";
	locations[n].models.always.Hut_2_inside.level = 65538;
	//locations[n].models.day.locators = "Hut_2_inside_locators";
	//locations[n].models.night.locators = "Hut_2_inside_ln";
	Locations[n].models.always.locators = "Hut_2_inside_locators";

	locations[n].models.always.Hut_2_back = "Hut_2_back";
	locations[n].models.always.Hut_2_back.level = 65538; 
	locations[n].models.always.back = "..\inside_back2";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.always.Hut_2_insiderand = "Hut_2_inside_rand_2";
	locations[n].models.day.charactersPatch = "Hut_2_inside_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_2_inside_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortoBello_Indian_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].box.box1 = "indian015";	
	n = n + 1;
//////////////////////////////////////////////////////////
////////////////Вход в грот////////////////////////////
////////////////////////////////////////////////////////////

                      Locations[n].id = "Shiriri_Cave";
                      locations[n].id.label = "Jungle";
                      locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
                       //Sound
                     locations[n].islandId = "Mein";
                     locations[n].type = "jungle";	
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
                   Locations[n].reload.l1.name = "reload2_back";
                   Locations[n].reload.l1.go = "Shiriri_jungle_02";
                   Locations[n].reload.l1.emerge = "reload2_back";
                   Locations[n].reload.l1.autoreload = "1";
                   Locations[n].reload.l1.label = "Jungle";
                  Locations[n].locators_radius.reload.reload1 = 3;

                 Locations[n].reload.l2.name = "reload1_back";
                 Locations[n].reload.l2.go = "Shiriri_Grot";
                 Locations[n].reload.l2.emerge = "reload1";
                 Locations[n].reload.l2.autoreload = "1";
                 Locations[n].reload.l2.label = "Cave";

               n = n + 1;

////////////////////////////////////////////////////////////////////////////
        //////////////Грот////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

                        Locations[n].id = "Shiriri_Grot";
                        locations[n].id.label = "Cave";
                        locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
                        //Sound
 	      locations[n].islandId = "Mein";
                         locations[n].type = "cave";
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
                    Locations[n].reload.l1.go = "Shiriri_Cave";
                    Locations[n].reload.l1.emerge = "reload1";
                    Locations[n].reload.l1.autoreload = "1";
                    Locations[n].reload.l1.label = "Jungle";
                    n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// Рудник 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        Locations[n].id = "DesMoines_Mine";
                        locations[n].id.label = "DesMoinesMine";	
                        locations[n].image = "loading\Mine_" + rand(1) + ".tga";
	     locations[n].worldmap = "PortoBello";
	     locations[n].islandId = "Mein";
	     locations[n].islandIdAreal = "PortoBello";
	    //Town sack
	     locations[n].townsack = "PortoBello";
                        //Sound
                        locations[n].type = "Mines";
	    locations[n].fastreload = "DesMoinesMine";
                      //Models
                         //Always
                        Locations[n].filespath.models = "Locations\Gothic\Mine";
                        Locations[n].models.always.locators = "mine_locators_addon";
                        Locations[n].models.always.cave = "mine";
                        Locations[n].models.always.cave.tech = "DLightModel";
                        Locations[n].models.always.grassPatch = "mine_grass";
	     locations[n].models.always.L1 = "mine_wall";
	     Locations[n].models.always.L1.tech = "DLightModel"; 
	//WindMill Fan
	locations[n].models.always.baraban = "baraban";
	Locations[n].models.always.baraban.tech = "DLightModel";		
	Locations[n].models.always.baraban.locator.group = "WindMill";
	Locations[n].models.always.baraban.locator.name ="Fan";	
	Locations[n].models.always.baraban.rotate.x = 0.0;
	Locations[n].models.always.baraban.rotate.y = 0.0;
	Locations[n].models.always.baraban.rotate.z = 0.3;	//0.3
                         //Day
                        Locations[n].models.day.charactersPatch = "mine_patch";
                       Locations[n].models.day.fonar = "mine_fd";
                     //Night
                       Locations[n].models.night.charactersPatch = "mine_patch";
                      Locations[n].models.night.fonar = "mine_fn";
                      //Environment
                      Locations[n].environment.weather = "true";
                      Locations[n].environment.sea = "false";
                     //Reload map
		
                       Locations[n].reload.l1.name = "reload1_back";
                       Locations[n].reload.l1.go = "Shiriri_jungle_06"; 
                       Locations[n].reload.l1.emerge = "reload3"; 
                       Locations[n].reload.l1.autoreload = "0";
                       Locations[n].reload.l1.label = "jungle";
                       Locations[n].locators_radius.reload.reload1_back = 2.0;
		
                       Locations[n].reload.l2.name = "reload2_back";
                       Locations[n].reload.l2.go = "Shiriri_jungle_07";
                       Locations[n].reload.l2.emerge = "reload3";
                       Locations[n].reload.l2.autoreload = "0";
                       Locations[n].reload.l2.label = "jungle";
                       Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload3_back";
                        Locations[n].reload.l3.go = "CommonStoneHouse";
                        Locations[n].reload.l3.emerge = "reload1";
                        Locations[n].reload.l3.autoreload = "0";
                        Locations[n].reload.l3.label = "House";

                        Locations[n].reload.l4.name = "reload4_back";
                        Locations[n].reload.l4.go = "Common_DesMoines_recidence";
                        Locations[n].reload.l4.emerge = "reload1";
                        Locations[n].reload.l4.autoreload = "0";
                        Locations[n].reload.l4.label = "House";

                       Locations[n].reload.l5.name = "reload6_back";
                       Locations[n].reload.l5.go = "CommonRoom_MH2";  
                       Locations[n].reload.l5.emerge = "reload1";
                       Locations[n].reload.l5.autoreload = "0";
                       Locations[n].reload.l5.label = "House";
		
	Locations[n].reload.l6.name = "reload7_back";
                        Locations[n].reload.l6.go = "CommonPirateHouse";
                        Locations[n].reload.l6.emerge = "reload1";
                        Locations[n].reload.l6.autoreload = "0";
                        Locations[n].reload.l6.label = "House";

	Locations[n].reload.l7.name = "reload5_back";
                        Locations[n].reload.l7.go = "DesMoines_tavern";
                        Locations[n].reload.l7.emerge = "reload1";
                        Locations[n].reload.l7.autoreload = "0";
                        Locations[n].reload.l7.label = "House";
		
	Locations[n].reload.l8.name = "reload8_back";
                        Locations[n].reload.l8.go = "CommonHut";
                        Locations[n].reload.l8.emerge = "reload1";
                        Locations[n].reload.l8.autoreload = "0";
                        Locations[n].reload.l8.label = "House";
		
	    Locations[n].reload.l9.name = "reload6_back";
                        Locations[n].reload.l9.go = ""; 
                        Locations[n].reload.l9.emerge = "reload1";
                        Locations[n].reload.l9.autoreload = "0";
                        Locations[n].reload.l9.label = "tavern";
		
	Locations[n].reload.l10.name = "reload10_back";
                        Locations[n].reload.l10.go = "CommonHut";
                        Locations[n].reload.l10.emerge = "reload1";
                        Locations[n].reload.l10.autoreload = "0";
                        Locations[n].reload.l10.label = "House";
		
	Locations[n].reload.l11.name = "reload11_back";
                        Locations[n].reload.l11.go = "CommonRoom_MH2"; 
                        Locations[n].reload.l11.emerge = "reload1";
                        Locations[n].reload.l11.autoreload = "0";
                        Locations[n].reload.l11.label = "House";
		
	Locations[n].reload.l13.name = "reload13_back";
                        Locations[n].reload.l13.go = "CommonRoom_MH2";
                        Locations[n].reload.l13.emerge = "reload1";
                        Locations[n].reload.l13.autoreload = "0";
                        Locations[n].reload.l13.label = "House";
		
	Locations[n].reload.l14.name = "reload14_back";
                        Locations[n].reload.l14.go = "CommonRoom_MH7";
                        Locations[n].reload.l14.emerge = "reload1";
                        Locations[n].reload.l14.autoreload = "0";
                        Locations[n].reload.l14.label = "House";
		
	Locations[n].reload.l15.name = "reload15_back";
                        Locations[n].reload.l15.go = "CommonPirateHouse";
                        Locations[n].reload.l15.emerge = "reload1";
                        Locations[n].reload.l15.autoreload = "0";
                        Locations[n].reload.l15.label = "House";

	Locations[n].reload.l16.name = "reload12_back";
                        Locations[n].reload.l16.go = "CommonHut"; 
                        Locations[n].reload.l16.emerge = "reload1";
                        Locations[n].reload.l16.autoreload = "0";
                        Locations[n].reload.l16.label = "House";

	Locations[n].reload.l17.name = "Househ4";
                        Locations[n].reload.l17.go = "CommonHut"; 
                        Locations[n].reload.l17.emerge = "reload1";
                        Locations[n].reload.l17.autoreload = "0";
                        Locations[n].reload.l17.label = "House";

	Locations[n].reload.l18.name = "reload9_back";
                        Locations[n].reload.l18.go = "CommonPirateHouse"; 
                        Locations[n].reload.l18.emerge = "reload1";
                        Locations[n].reload.l18.autoreload = "0";
                        Locations[n].reload.l18.label = "House";

                       Locations[n].goto.l19.name = "goto4";
                       Locations[n].goto.l19.go = "TainoPE_Dream_Undrvld";
                       Locations[n].goto.l19.emerge = "goto1";
                       Locations[n].goto.l19.autoreload = "0";
                       Locations[n].goto.l19.label = "Cave";
                       
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////	//////// Таверна	/////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_tavern";
	locations[n].id.label = "Tavern38";
	locations[n].filespath.models = "locations\inside\Tavern04\";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "DesMoines";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "DesMoines";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].models.always.tavern = "Tavern04";
	locations[n].models.always.locators = "Tavern04_locators";
	locations[n].models.always.window = "tavern04_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "Tavern04_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern04_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "DesMoines_mine";
	locations[n].reload.l1.emerge = "reload5_back";
	locations[n].reload.l1.autoreload = "0";
                   locations[n].reload.l1.label = "DesMoines mine";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "DesMoines_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.	
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
	////// Комната в таверне 	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortoBelloMines";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortoBelloMines";
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
	locations[n].reload.l1.go = "DesMoines_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

/////////////////// Резиденция ////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Common_DesMoines_recidence";
	locations[n].filespath.models = "locations\inside\CobHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\CobHouse_" + rand(1) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "";
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
	locations[n].reload.l1.go = "DesMoines_mine";
	locations[n].reload.l1.emerge = "reload4_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "DesMoines mine";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "DesMoines_mine_recidence_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

/////////////////// Комната в резиденции /////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_mine_recidence_upstairs";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\smallresidence_" + rand(1) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "";
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
	locations[n].reload.l1.go = "Common_DesMoines_recidence";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";
	n = n + 1;

	//////////////////////// Дом ночевки ГГ ///////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "DesMoines_mine_house";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].townsack = "";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "";
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
	locations[n].reload.l1.go = "DesMoines_mine";
	locations[n].reload.l1.emerge = "reload6_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "DesMoines mine";
	n = n + 1;

/////////////// подземелье (сон) ////////////////////////////
	locations[n].id = "TainoPE_Dream_Undrvld";
	locations[n].id.label = "Cave";
     locations[n].image = "loading\inside\cave_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";

	Locations[n].lockCamAngle = 0.4;
                Locations[n].camshuttle = 1;
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer3";
	locations[n].models.always.DungeonDuffer3 = "DungeonDuffer3";
	locations[n].models.always.locators = "DungeonDuffer3_locators";

//	locations[n].locators_radius.item.duhi1 = 1.3;
	
	Locations[n].models.always.rays = "DungeonDuffer3_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;
	//Day
	locations[n].models.day.charactersPatch = "DungeonDuffer3_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonDuffer3_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	n = n + 1;
/////////////// подземелье (просто) ////////////////////////////
	locations[n].id = "Taino_mine_undrGold";
	locations[n].id.label = "Cave";
                locations[n].image = "loading\inside\cave.tga";
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Mein";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer3";
	locations[n].models.always.DungeonDuffer3 = "DungeonDuffer3";
	locations[n].models.always.locators = "DungeonDuffer3_locators";
//	locations[n].locators_radius.item.duhi1 = 1.3;
	Locations[n].models.always.rays = "DungeonDuffer3_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;
// test!!	
//	Locations[n].models.always.l1 = "DungeonDuffer3_Gold";	
	//Day
	locations[n].models.day.charactersPatch = "DungeonDuffer3_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonDuffer3_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].goto.l1.name = "goto1";
	locations[n].goto.l1.go = "DesMoines_mine";
	locations[n].goto.l1.emerge = "goto4";
	locations[n].goto.l1.autoreload = "0";
	locations[n].goto.l1.label = "Cave";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                 locations[n].id = "Shiriri_jungle_07";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Town sack
	Locations[n].townsack = "Mein";
 	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "PortoBello_Shore110";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 3.0;

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "DesMoines_mine";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Street";
                        locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Shiriri_jungle_08";
	locations[n].reload.l3.emerge = "reload2_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        locations[n].id = "Shiriri_jungle_08";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
 	//Sound
	locations[n].type = "Mines";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Shiriri_jungle_07";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shiriri_Temple";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortoBello_Shore90";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Sea";
	locations[n].locators_radius.reload.reloadW_back = 2.3;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Shore90";
	locations[n].id.label = "SeaShore90";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "SeaSeaShore90";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
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
	locations[n].reload.l1.go = "Shiriri_jungle_08";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пляж	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortoBello_Shore110";
	locations[n].id.label = "SeaShore110";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "SeaSeaShore110";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Mein";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Incas Temple\Port";
	Locations[n].models.always.locators = "KRport_l";
	Locations[n].models.always.shore = "KRport";
	Locations[n].models.always.seabed = "KRport_sb";
	Locations[n].models.always.grasspatch = "KRport_g";	
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
/*	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";		
*/	
	//Day
	Locations[n].models.day.charactersPatch = "KRport_p";	
	//Night
	Locations[n].models.night.charactersPatch = "KRport_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Shiriri_jungle_07";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TEMPLE 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Shiriri_Temple";
	//Sound
	locations[n].type = "Alcove_2";
	locations[n].islandId = "Mein";
	locations[n].image = "loading\outside\temple_" + rand(1) + ".tga";
	locations[n].id.label = "Incas Temple";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Incas Templee\Templee\";
	Locations[n].models.always.locators = "hram_l";
	Locations[n].models.always.l1 = "Hram";
	Locations[n].models.always.grasspatch = "hram_g";	
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
	Locations[n].reload.l1.go = "Shiriri_jungle_08";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Shiriri_labirint_1";
	Locations[n].reload.l2.emerge = "reload27";
	Locations[n].reload.l2.autoreload = "1";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// LABIRINT 1	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Shiriri_Labirint_1";
	//Sound
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	locations[n].type = "Temple";
	locations[n].id.label = "Adanos";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Incas Templee\Labirintt\";
	Locations[n].models.always.locators = "lab1_l";
	Locations[n].models.always.l1 = "lab1";
	//Day
	Locations[n].models.day.charactersPatch = "lab1_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";
	
	//Reload map
	Locations[n].reload.l1.name = "reload27";
	Locations[n].reload.l1.go = "Shiriri_Temple";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	
	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Shiriri_labirint_2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
      
	Locations[n].reload.l22.name = "reload4_back";
	Locations[n].reload.l22.go = "Shiriri_labirint_2";
	Locations[n].reload.l22.emerge = "reload3";
	Locations[n].reload.l22.autoreload = "1";

    	Locations[n].reload.l3.name = "reload11";
	Locations[n].reload.l3.go = "Shiriri_labirint_2";
	Locations[n].reload.l3.emerge = "Reload12";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload11_back";
	Locations[n].reload.l23.go = "Shiriri_labirint_2";
	Locations[n].reload.l23.emerge = "Reload12";
	Locations[n].reload.l23.autoreload = "1";

	Locations[n].reload.l8.name = "reload26";
	Locations[n].reload.l8.go = "Shiriri_labirint_2";
	Locations[n].reload.l8.emerge = "reload25";
	Locations[n].reload.l8.autoreload = "1";

	Locations[n].reload.l28.name = "reload26_back";
	Locations[n].reload.l28.go = "Shiriri_labirint_2";
	Locations[n].reload.l28.emerge = "reload25";
	Locations[n].reload.l28.autoreload = "1";

    	Locations[n].reload.l9.name = "reload1";
	Locations[n].reload.l9.go = "Shiriri_labirint_3";
	Locations[n].reload.l9.emerge = "Reload2";
	Locations[n].reload.l9.autoreload = "1";

	Locations[n].reload.l29.name = "reload1_back";
	Locations[n].reload.l29.go = "Shiriri_labirint_3";
	Locations[n].reload.l29.emerge = "Reload2";
	Locations[n].reload.l29.autoreload = "1";

	Locations[n].reload.l10.name = "reload6";
	Locations[n].reload.l10.go = "Shiriri_labirint_3";
	Locations[n].reload.l10.emerge = "reload5";
	Locations[n].reload.l10.autoreload = "1";

	Locations[n].reload.l20.name = "reload6_back";
	Locations[n].reload.l20.go = "Shiriri_labirint_3";
	Locations[n].reload.l20.emerge = "reload5";
	Locations[n].reload.l20.autoreload = "1";
      
    	Locations[n].reload.l11.name = "reload7";
	Locations[n].reload.l11.go = "Shiriri_labirint_3";
	Locations[n].reload.l11.emerge = "Reload8";
	Locations[n].reload.l11.autoreload = "1";

    	Locations[n].reload.l21.name = "reload7_back";
	Locations[n].reload.l21.go = "Shiriri_labirint_3";
	Locations[n].reload.l21.emerge = "Reload8";
	Locations[n].reload.l21.autoreload = "1";

	Locations[n].reload.l12.name = "reload9";
	Locations[n].reload.l12.go = "Shiriri_labirint_3";
	Locations[n].reload.l12.emerge = "reload10";
	Locations[n].reload.l12.autoreload = "1";

	Locations[n].reload.l22.name = "reload9_back";
	Locations[n].reload.l22.go = "Shiriri_labirint_3";
	Locations[n].reload.l22.emerge = "reload10";
	Locations[n].reload.l22.autoreload = "1";
	n = n + 1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// LABIRINT 2
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Shiriri_Labirint_2";
	//Sound
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	locations[n].type = "Temple";
	locations[n].id.label = "Adanos";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Incas Templee\Labirintt\";
	Locations[n].models.always.locators = "lab2_l";
	Locations[n].models.always.l1 = "lab2";
	//Day
	Locations[n].models.day.charactersPatch = "lab2_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";
	
	//Reload map
	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Shiriri_labirint_1";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l22.name = "reload3_back";
	Locations[n].reload.l22.go = "Shiriri_labirint_1";
	Locations[n].reload.l22.emerge = "reload4";
	Locations[n].reload.l22.autoreload = "1";
      
    	Locations[n].reload.l3.name = "reload12";
	Locations[n].reload.l3.go = "Shiriri_labirint_1";
	Locations[n].reload.l3.emerge = "Reload11";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload12_back";
	Locations[n].reload.l23.go = "Shiriri_labirint_1";
	Locations[n].reload.l23.emerge = "Reload11";
	Locations[n].reload.l23.autoreload = "1";
	
	Locations[n].reload.l8.name = "reload25";
	Locations[n].reload.l8.go = "Shiriri_labirint_1";
	Locations[n].reload.l8.emerge = "reload26";
	Locations[n].reload.l8.autoreload = "1";

	Locations[n].reload.l28.name = "reload25_back";
	Locations[n].reload.l28.go = "Shiriri_labirint_1";
	Locations[n].reload.l28.emerge = "reload26";
	Locations[n].reload.l28.autoreload = "1";

    	Locations[n].reload.l9.name = "reload14";
	Locations[n].reload.l9.go = "Shiriri_labirint_3";
	Locations[n].reload.l9.emerge = "Reload13";
	Locations[n].reload.l9.autoreload = "1";

	Locations[n].reload.l29.name = "reload14_back";
	Locations[n].reload.l29.go = "Shiriri_labirint_3";
	Locations[n].reload.l29.emerge = "Reload13";
	Locations[n].reload.l29.autoreload = "1";

	Locations[n].reload.l10.name = "reload16";
	Locations[n].reload.l10.go = "Shiriri_labirint_3";
	Locations[n].reload.l10.emerge = "reload15";
	Locations[n].reload.l10.autoreload = "1";

	Locations[n].reload.l20.name = "reload16_back";
	Locations[n].reload.l20.go = "Shiriri_labirint_3";
	Locations[n].reload.l20.emerge = "reload15";
	Locations[n].reload.l20.autoreload = "1";      
    	n = n + 1;		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// LABIRINT 3	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Shiriri_Labirint_3";
	//Sound
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	locations[n].type = "Temple";
	locations[n].id.label = "Adanos";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Incas Templee\Labirintt\";
	Locations[n].models.always.locators = "lab3_l";
	Locations[n].models.always.l1 = "lab3";
	//Day
	Locations[n].models.day.charactersPatch = "lab3_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab3_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";

	//Reload map
	Locations[n].reload.l2.name = "reload13";
	Locations[n].reload.l2.go = "Shiriri_labirint_2";
	Locations[n].reload.l2.emerge = "reload14";
    	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l22.name = "reload13_back";
	Locations[n].reload.l22.go = "Shiriri_labirint_2";
	Locations[n].reload.l22.emerge = "reload14";
    	Locations[n].reload.l22.autoreload = "1";

    	Locations[n].reload.l3.name = "reload15";
	Locations[n].reload.l3.go = "Shiriri_labirint_2";
	Locations[n].reload.l3.emerge = "Reload16";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload15_back";
	Locations[n].reload.l23.go = "Shiriri_labirint_2";
	Locations[n].reload.l23.emerge = "Reload16";
	Locations[n].reload.l23.autoreload = "1";

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Shiriri_labirint_1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";

	Locations[n].reload.l24.name = "reload2_back";
	Locations[n].reload.l24.go = "Shiriri_labirint_1";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "1";
      
    	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Shiriri_labirint_1";
	Locations[n].reload.l5.emerge = "Reload6";
	Locations[n].reload.l5.autoreload = "1";

	Locations[n].reload.l25.name = "reload5_back";
	Locations[n].reload.l25.go = "Shiriri_labirint_1";
	Locations[n].reload.l25.emerge = "Reload6";
	Locations[n].reload.l25.autoreload = "1";

	Locations[n].reload.l6.name = "reload8";
	Locations[n].reload.l6.go = "Shiriri_labirint_1";
	Locations[n].reload.l6.emerge = "reload7";
	Locations[n].reload.l6.autoreload = "1";

	Locations[n].reload.l26.name = "reload8_back";
	Locations[n].reload.l26.go = "Shiriri_labirint_1";
	Locations[n].reload.l26.emerge = "reload7";
	Locations[n].reload.l26.autoreload = "1";
      
    	Locations[n].reload.l7.name = "reload10";
	Locations[n].reload.l7.go = "Shiriri_labirint_1";
	Locations[n].reload.l7.emerge = "Reload9";
	Locations[n].reload.l7.autoreload = "1";

	Locations[n].reload.l27.name = "reload10_back";
	Locations[n].reload.l27.go = "Shiriri_labirint_1";
	Locations[n].reload.l27.emerge = "Reload9";
	Locations[n].reload.l27.autoreload = "1";

	Locations[n].reload.l28.name = "reload30_back";
	Locations[n].reload.l28.go = "Treasure_Alcovee";
	Locations[n].reload.l28.emerge = "Reload1";
	Locations[n].reload.l28.autoreload = "1";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Treasure_Alcovee";
	//Sound
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
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
	Locations[n].reload.l2.go = "Shiriri_labirint_3";
	Locations[n].reload.l2.emerge = "reload30";
                   Locations[n].reload.l2.autoreload = "1";    
	n = n + 1;
	
	return n;
}
