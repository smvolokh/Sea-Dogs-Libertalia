
int LocationInitPuertoPrincipe(int n)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Порт Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_port";
	locations[n].id.label = "PuertoPrincipe Port";
	locations[n].image = "loading\seaStand.tga";
	locations[n].worldmap = "PuertoPrincipe_port";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	//Sound
	locations[n].type = "town";
	Locations[n].townsack = "PuertoPrincipe";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\GpiratePort";
	Locations[n].models.always.l1 = "GpiratePort";
	Locations[n].models.always.locators = "GpiratePort_locators";	
	locations[n].models.always.PuertoPrincipeport.sea_reflection = 1;
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.portseabed = "GpiratePort_sb";			
	Locations[n].models.always.grassPatch = "GpiratePort_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	//Day
	locations[n].models.day.charactersPatch = "GpiratePort_patch";
	locations[n].models.day.fonars = "GpiratePort_fd";
	Locations[n].models.day.jumpPatch = "GpiratePort_jump_patch";
	//Night
	locations[n].models.night.charactersPatch = "GpiratePort_patch";
	locations[n].models.night.fonars = "GpiratePort_fn";
	Locations[n].models.night.jumpPatch = "GpiratePort_jump_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Cuba1";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Cave_Gpirate";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Grot";

	locations[n].reload.l4.name = "HouseH3";
	locations[n].reload.l4.go = "PuertoPrincipe_PortOffice";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "PortOffice";
	locations[n].reload.l4.close_for_night = 1;

	locations[n].reload.l5.name = "HouseH2";
	locations[n].reload.l5.go = "CommonHut";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "House";

	Locations[n].reload.l6.name = "HouseH1";
	Locations[n].reload.l6.go = "PuertoPrincipe_HouseHut5";
	Locations[n].reload.l6.emerge = "reload1_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_HouseHut5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_port";
	locations[n].reload.l1.emerge = "HouseH1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "PuertoPrincipe Port";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_town";
	locations[n].id.label = "Street";
	locations[n].image = "loading\towns\pearl3.tga";
	locations[n].worldmap = "PuertoPrincipe_town";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].fennisgrass = 1;
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "PuertoPrincipe";
 	locations[n].islandId = "Cuba";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\GpirateTown";
	Locations[n].models.always.port = "GpirateTown";
	Locations[n].models.always.locators = "GpirateTown_locators";	
	locations[n].models.always.port.sea_reflection = 1;		
	Locations[n].models.always.grassPatch = "GpirateTown_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	// склад
	locations[n].models.always.storehouse = "storehouse1";
	Locations[n].models.always.storehouse.locator.group = "Upgrades";
	Locations[n].models.always.storehouse.locator.name = "storehouse";
	// дерево
	locations[n].models.always.tree = "tree1";
	Locations[n].models.always.tree.locator.group = "Upgrades";
	Locations[n].models.always.tree.locator.name = "tree";
	Locations[n].models.always.tree.tech = "DLightModel";
	
	//Day
	locations[n].models.day.charactersPatch = "GpirateTown_patch_day";
	locations[n].models.day.fonars = "GpirateTown_fd";
	locations[n].models.day.rinok = "GpirateTown_rinok";
	//Night
	locations[n].models.night.charactersPatch = "GpirateTown_patch_night";
	locations[n].models.night.fonars = "GpirateTown_fn";

	Locations[n].models.day.jumppatch = "GpirateTown_jump_patch";
	Locations[n].models.night.jumppatch = "GpirateTown_jump_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
    // --> Типовые городские локации, четкаљ фиксациљ на 10 номеров.
	Locations[n].reload.l1.name = "reload2_back"; 
	Locations[n].reload.l1.go = "PuertoPrincipe_port";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "PuertoPrincipe Port";
	locations[n].locators_radius.reload.reload1 = 1.8;

	locations[n].reload.l2.name = "gate_back";
	locations[n].reload.l2.go = "PuertoPrincipe_ExitTown";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "ExitTown";

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PuertoPrincipe_townhall";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PuertoPrincipe_tavern";
	locations[n].reload.l4.emerge = "reload1_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l9.name = "houseS4";
	locations[n].reload.l9.go = "PuertoPrincipe_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

	locations[n].reload.l6.name = "reload7_back";
	locations[n].reload.l6.go = "PuertoPrincipe_church";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Church";
	locations[n].reload.l6.close_for_night = 1;


    // --> Комоны, загрушки. Номера с начинаются с 20.

	locations[n].reload.l19.name = "housef1";
	locations[n].reload.l19.go = "PuertoPrincipe_bank";
	locations[n].reload.l19.emerge = "reload1";
	locations[n].reload.l19.autoreload = "0";
	locations[n].reload.l19.label = "Store";
	locations[n].reload.l19.close_for_night = 1;

	locations[n].reload.l20.name = "houseS1";
	locations[n].reload.l20.go = "PuertoPrincipe_store";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "Store";
	locations[n].reload.l20.close_for_night = 1;

	locations[n].reload.l21.name = "houseS1777";
	locations[n].reload.l21.go = "CommonFlamHouse";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House";

	locations[n].reload.l22.name = "houseS2";
	locations[n].reload.l22.go = "CommonPirateHouse";
	locations[n].reload.l22.emerge = "reload1";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "House";

	locations[n].reload.l23.name = "houseSp2";
	locations[n].reload.l23.go = "CommonRoom_MH4";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	locations[n].reload.l24.name = "houseH1";
	locations[n].reload.l24.go = "CommonRoom_MH3";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";

	locations[n].reload.l25.name = "houseH5";
	locations[n].reload.l25.go = "CommonCobHouse";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "reload6_back";
	locations[n].reload.l26.go = "PuertoPrincipe_Shipyard";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "Shipyard";
	locations[n].reload.l26.close_for_night = 1;

      n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Таверна Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	locations[n].id = "PuertoPrincipe_tavern";
	locations[n].id.label = "Tavern13";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\tavern12\";
	locations[n].models.always.tavern = "tavern12";
	Locations[n].models.always.tavern.tech = "DLightModel";	
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern12_locators";
	Locations[n].models.always.locators.tech = "DLightModel";	
	locations[n].models.always.window = "tavern12_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;

	//Day
	locations[n].models.day.charactersPatch = "tavern12_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern12_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "reload4_back"; 
	locations[n].reload.l1.autoreload = "0";
                    locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PuertoPrincipe_tavern_upstairs";
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
	locations[n].reload.l3.label = "packhouse";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// подсобка таверны
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	locations[n].id = "PuertoPrincipe_sklad";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "tavern";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната в таверне наверху, Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern7";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Магазин Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_store";
	locations[n].id.label = "Store";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "houseS1"; 
	locations[n].reload.l1.autoreload = "0";
                     locations[n].reload.l1.label = "Street";

    ////////////////////////==> комната в магазине
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonRoom_MH10";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_townhall";
	locations[n].id.label = "Townhall";
	locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PuertoPrincipe";
 	locations[n].islandId = "Cuba";
 	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Residence11";
	locations[n].models.always.locators = "Res11_locators";
	locations[n].models.always.l1 = "Res11";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "Res11_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;	
	//Day
	Locations[n].models.day.charactersPatch = "Res11_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Res11_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.item.item1 = 0.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "CommonResidence_4";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "house";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "reload7_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "HouseMonk";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Church";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "PuertoPrincipe_Crypt";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Church";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Вход в склеп
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_Crypt";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_church";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PuertoPrincipe_crypt2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//Склеп	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_crypt2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "PuertoPrincipe";
 	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_Crypt";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	Locations[n].locators_radius.reload.reload1 = 3.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города Пуэрто-Принсипе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	//Sound
	locations[n].type = "jungle";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
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

     	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "PuertoPrincipe_town";
	Locations[n].reload.l1.emerge = "gate_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.reload.reload3 = 1.8;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Cuba_Jungle_03";
	locations[n].reload.l2.emerge = "reload2_back";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PuertoPrincipe_jungle_house";
	locations[n].reload.l3.emerge = "reload1_back";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "House";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Хижина	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_jungle_house";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Sound
	locations[n].type = "House";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_ExitTown";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "jungle";
	locations[n].locators_radius.item.bottle = 1.3;

	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Barbados";
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
	locations[n].reload.l1.go = "PuertoPrincipe_port";
	locations[n].reload.l1.emerge = "HouseH3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "PuertoPrincipe Port";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel\";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "houseS4";
	locations[n].reload.l1.autoreload = "0";
     locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PuertoPrincipe_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "PuertoPrincipe_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room\";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
 	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ВЕРФЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard02\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "reload6_back";
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
	// РОСТОВЩИК
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PuertoPrincipe_Bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank02\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_town";
	locations[n].reload.l1.emerge = "housef1";
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
	// Дом Монаха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "HouseMonk";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\Comnata_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PuertoPrincipe";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
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
	locations[n].reload.l1.go = "PuertoPrincipe_church";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот Самюэля	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Cave_Gpirate";
	locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	locations[n].id.label = "Grot";
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "cave";
	locations[n].fastreload = "PuertoPrincipe";
	locations[n].islandId = "Cuba";
	locations[n].mining2.key = "minepick";
	locations[n].mining3.key = "minepick";
	locations[n].mining4.key = "minepick";
	locations[n].mining1.key = "minepick";
	locations[n].questflower = 1;
	locations[n].fennisgrass = 1;
	//Models	
	//Always
	Locations[n].filespath.models = "Locations\Gothic\MINE2";
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
	locations[n].reload.l1.go = "PuertoPrincipe_port";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "PuertoPrincipe Port";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2_back = 2;

	n = n + 1;


	return n;
}
