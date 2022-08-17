int LocationInitDominica(int n)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Остров Доминика	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Порт Шарлот-Таун
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_port";
	locations[n].id.label = "Roseau port";
	Locations[n].image = "loading\Roseau_Port.tga";
	locations[n].worldmap = "Dominica";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	//Sound
	locations[n].type = "town";
	Locations[n].townsack = "Roseau";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_Roseau\port";
	Locations[n].models.always.locators = "Roseauport_locators";
	Locations[n].models.always.l1 = "Roseauport";
	locations[n].models.always.Roseauport.sea_reflection = 1;
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "Roseauport_sb";
	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.grassPatch = "Roseauport_grass";

	//Day
	Locations[n].models.day.fonar = "Roseauport_fd";
	Locations[n].models.day.charactersPatch = "Roseauport_patch_day";
	Locations[n].models.day.rinok = "Roseauport_rinok";
	Locations[n].models.day.jumpPatch = "Roseauport_j";
	//Night
	Locations[n].models.night.fonar = "Roseauport_fn";
	Locations[n].models.night.charactersPatch = "Roseauport_patch_night";
	Locations[n].models.night.jumpPatch = "Roseauport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Exittwon";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Dominica";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
      locations[n].locators_radius.reload.boat = 9.0;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Dominica_Dungeon";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Exittwon";
	locations[n].locators_radius.reload.reload1_back = 2;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// КАТАКОМБЫ 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Dominica_Dungeon";
	Locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	//Sound
	locations[n].type = "cave_Gotika";
	locations[n].islandId = "Dominica";
	locations[n].parent_colony = "Roseau";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\DungeonOld2";
	Locations[n].models.always.tavern.tech = "DLightModel";		
	Locations[n].models.always.locators = "DungeonOld2_locators";
	locations[n].models.always.Dungeon = "DungeonOld2";
	locations[n].models.always.treasure = "Treasures";
	Locations[n].models.always.treasure.locator.group = "monsters";
	Locations[n].models.always.treasure.locator.name = "monster3";
	locations[n].models.always.door = "door_old";
	Locations[n].models.always.door.locator.group = "reload";
	Locations[n].models.always.door.locator.name = "reload2";

	Locations[n].models.always.locators.tech = "DLightModel";
	locations[n].models.always.window.tech = "LocationWindows";			
	Locations[n].models.always.DungeonOld2 = "DungeonOld2";
	locations[n].models.always.DungeonOld2.level = 65538;

	locations[n].models.always.Treasures1 = "Treasures";
	Locations[n].models.always.Treasures1.locator.group = "Upgrades";
	Locations[n].models.always.Treasures1.locator.name = "Treasures";

	//Day
	Locations[n].models.day.charactersPatch = "DungeonOld2_patch";
	//Night
	Locations[n].models.night.charactersPatch = "DungeonOld2_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Roseau_port";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Roseau port";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Roseau_Dungeon";
	locations[n].reload.l2.emerge = "reload2_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "dungeon";
	locations[n].reload.l2.disable = 1;

                          //заполним сундучки.
	locations[n].private1.items.pistol10 = 1;
	
	locations[n].private8.items.indian001 = 1;
	locations[n].private8.items.indian002 = 1;
	locations[n].private8.items.indian003 = 2;
	locations[n].private8.items.map_tortuga = 1;

	locations[n].private2.items.indian007 = 1;
	locations[n].private2.items.indian008 = 1;
	locations[n].private2.items.indian009 = 2;

	locations[n].private3.items.indian013 = 1;
	locations[n].private3.items.indian012 = 1;
	locations[n].private3.items.indian014 = 2;

	locations[n].private4.items.indian018 = 1;
	locations[n].private4.items.indian019 = 1;
	locations[n].private4.items.indian020 = 1;
	locations[n].private4.items.indian021 = 1;
	locations[n].private4.items.indian022 = 1;
	locations[n].private4.items.key1 = 1; // ключ от двери

	locations[n].private5.items.indian017 = 1;
	locations[n].private5.items.indian016 = 1;
	locations[n].private5.items.indian015 = 1;
	locations[n].private5.items.indian005 = 1;
	locations[n].private5.items.indian006 = 1;

	locations[n].private6.items.indian004 = 1;
	locations[n].private6.items.indian005 = 1;
	locations[n].private6.items.indian006 = 1;

	locations[n].private7.items.indian010 = 1;
	locations[n].private7.items.indian011 = 1;
	locations[n].private7.items.indian012 = 1;

	locations[n].locators_radius.item.key = 1.0;	
	n = n + 1;	

/////////////////////////////////////////////////////////////////////////////
	// Город Шарлотт-Таун	/////////////////////////////////////////////////////////////////////////////	
	locations[n].id = "Roseau_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Dominican";
	
	locations[n].townsack = "Roseau";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
	
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;

	//==> флаг генерации квестодателя по розыску кэпов, int значение - шанс что сам заговорит(1-10)
	locations[n].questSeekCap = 7; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //для энкаунтеров в домах
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_Roseau\town";
	Locations[n].models.always.locators = "Roseau_locators";
	Locations[n].models.always.grassPatch = "Roseau_grass";
	Locations[n].models.always.town = "Roseau";
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.fonar = "Roseau_fd";
	Locations[n].models.day.charactersPatch = "Roseau_patch_day";
	Locations[n].models.day.rinok = "Roseau_rinok";
	//Night
	Locations[n].models.night.fonar = "Roseau_fn";
	Locations[n].models.night.charactersPatch = "Roseau_patch_night";

	Locations[n].models.day.jumpPatch = "Roseau_jump_patch";
	Locations[n].models.night.jumpPatch = "Roseau_jump_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
   // --> Типовые городские локации, четкая фиксация на 10 номеров.

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Roseau_port";
	Locations[n].reload.l2.emerge = "reload2_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Port";

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Roseau_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Residence";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "reload4_back";
	Locations[n].reload.l4.go = "Roseau_tavern";
	Locations[n].reload.l4.emerge = "reload1_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern";

	Locations[n].reload.l5.name = "reload5_back";
	Locations[n].reload.l5.go = "Roseau_Shipyard";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard";
	Locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Roseau_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "reload7_back";
	Locations[n].reload.l7.go = "Roseau_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church";

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Roseau_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "PortOffice";

	locations[n].reload.l9.name = "reload9_back";
	locations[n].reload.l9.go = "Roseau_brothel";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "Brothel";

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "Roseau_PortOffice";
	locations[n].reload.l10.emerge = "reload1_back";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "Roseau_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";

    // --> Квестовые локации, четкая фиксация на 9 едениц, откр/закр только по квестам, обычно всегда открыты.
	
	Locations[n].reload.l11.name = "houseSp1";
	Locations[n].reload.l11.go = "Roseau_HouseHut5";
	Locations[n].reload.l11.emerge = "reload1_back";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "House";

	locations[n].reload.l12.name = "basement1_back";
	locations[n].reload.l12.go = "Roseau_TownCave";
	locations[n].reload.l12.emerge = "reload1_back";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "Dungeon";

	locations[n].reload.l13.name = "houseF1";
	locations[n].reload.l13.go = "Roseau_houseF1";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "House";

	Locations[n].reload.l14.name = "houseS2";
	Locations[n].reload.l14.go = "Constantino_House";
	Locations[n].reload.l14.emerge = "reload1_back";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "House_Constantino";


    // --> Квестовые локации.

    // --> Комоны, загрушки. Номера с начинаютсљ с 20.

	Locations[n].reload.l20.name = "houseS1";
	Locations[n].reload.l20.go = "CommonStoneHouse";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "House";

	Locations[n].reload.l21.name = "houseH1";
	Locations[n].reload.l21.go = "CommonRoom_MH3";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "House";

	Locations[n].reload.l22.name = "houseH2";
	Locations[n].reload.l22.go = "CommonRoom_MH5";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "House";

	Locations[n].reload.l23.name = "houseH3";
	locations[n].reload.l23.go = "CommonRoom_MH10";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";

	Locations[n].reload.l24.name = "houseH4";
	Locations[n].reload.l24.go = "CommonRoom_MH4";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.label = "House";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_townhall";
	locations[n].id.label = "Residence";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_Tavern";
	locations[n].id.label = "Tavern35";
	Locations[n].image = "loading\inside\Tavern_pir.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
	//Models
	//Always
locations[n].filespath.models = "locations\inside\tavern011\";
	locations[n].models.always.tavern = "tavern011";
	Locations[n].models.always.tavern.tech = "DLightModel";	
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "tavern011_locators";
	Locations[n].models.always.locators.tech = "DLightModel";	
	locations[n].models.always.window = "tavern011_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;

	locations[n].models.always.L1 = "lcheer";
	Locations[n].models.always.L1.locator.group = "sit";
	Locations[n].models.always.L1.locator.name = "sit_bar_1";
	Locations[n].models.always.L1.tech = "DLightModel";
	locations[n].models.always.L2 = "lcheer";
	Locations[n].models.always.L2.locator.group = "sit";
	Locations[n].models.always.L2.locator.name = "sit_bar_2";
	Locations[n].models.always.L2.tech = "DLightModel";
	locations[n].models.always.L3 = "lcheer";
	Locations[n].models.always.L3.locator.group = "sit";
	Locations[n].models.always.L3.locator.name = "sit_bar_3";
	Locations[n].models.always.L3.tech = "DLightModel";

	//Day
	locations[n].models.day.charactersPatch = "tavern011_patch";
	Locations[n].models.day.jumpPatch = "tavern011_jump";
	//Night
	locations[n].models.night.charactersPatch = "tavern011_patch";
	Locations[n].models.night.jumpPatch = "tavern011_jump";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "reload4_back"; 
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Roseau_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	LAi_LocationFightDisable(&locations[n], true);

    ////////////////////////==> подсобка таверны
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Roseau_sklad";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "sklad";
	n = n + 1;

	Locations[n].id = "Roseau_sklad";
	locations[n].id.label = "sklad";
	locations[n].image = "loading\inside\sklad_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_tavern";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "tavern9";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Комната в таверне наверху	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_tavern_upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].id.label = "Tavern upstairs";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_tavern";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Магазин
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_store";
	locations[n].id.label = "Dominica store";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_town";
	Locations[n].reload.l1.emerge = "reload6_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Roseau_room_store";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

	n = n + 1;

	Locations[n].id = "Roseau_room_store";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\smallresidence_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "Roseau";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\pirateresidence";	
	Locations[n].models.always.locators = "resp_l";
	Locations[n].models.always.l1 = "resp";
	Locations[n].models.always.window = "resp_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "resp_p";
	//Night
	Locations[n].models.night.charactersPatch = "resp_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcresp_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Roseau_store";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Store";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Верфь
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "Roseau";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_town";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&Locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Roseau_Dungeon";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
                    Locations[n].reload.l2.disable = 1;
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Подземелье Розы
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_Dungeon";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_Shipyard";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Dominica_Dungeon";
	locations[n].reload.l2.emerge = "reload2_2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Dungeon";
	locations[n].locators_radius.reload.reload2_back = 1.5;
	
	locations[n].private1.key = "key3"; // сундучок Алекса
	locations[n].private1.key.delItem = true;
	locations[n].private1.items.alexs_chest = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Портовое управление
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_town";
	Locations[n].reload.l1.emerge = "reload10_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Roseau_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].image = "loading\inside\brothell_hall_" + rand(1) + ".tga";
	//Town sack
	Locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_Town";
	Locations[n].reload.l1.emerge = "reload9_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Roseau_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Roseau_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].image = "loading\inside\brothell_room_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_Brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
 	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_Brothel";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Roseau_brothel_BackDoor";
	locations[n].reload.l2.emerge = "reload1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Roseau_brothel_BackDoor";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\buduar.tga";
 	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
	locations[n].brothel = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\brothel_BackDoor";
	locations[n].models.always.tavern = "brothel_BackDoor";
                locations[n].models.day.locators = "brothel_BackDoor_Locators"; 
	//Day
	locations[n].models.day.charactersPatch = "brothel_BackDoor_patch";
	//Night
	locations[n].models.night.charactersPatch = "brothel_BackDoor_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Roseau_SecBrRoom";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////
	//Церковь
//////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church_1.tga";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_Town";
	Locations[n].reload.l1.emerge = "reload7_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Podval
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_TownCave";
	locations[n].id.label = "Dungeon";
	locations[n].image = "loading\inside\dungeon_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "Roseau";
	locations[n].fastreload = "Dominica";
	locations[n].islandId = "Dominica";
	locations[n].mining1.key = "minepick";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1 = "DungeonDuffer1";
	locations[n].models.always.DungeonDuffer1Stuff = "DungeonDuffer1_stuff";
	locations[n].models.always.locators = "DungeonDuffer1_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
/*	
	Locations[n].models.always.rays = "DungeonDuffer1_rays";
	Locations[n].models.always.rays.level = 49;
	Locations[n].models.always.rays.tech= "LocVisRays";
	Locations[n].models.always.rays.uvslide.u1 = -0.03;
	Locations[n].models.always.rays.uvslide.v1 = -0.03;	
*/	
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
	Locations[n].reload.l1.go = "Roseau_town";
	Locations[n].reload.l1.emerge = "basement1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	locations[n].locators_radius.item.berglar1 = 6.0;
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dominica_Lighthouse_01";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle";
	LAi_LocationFightDisable(&Locations[n], false);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// РОСТОВЩИК
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Roseau_bank";
	locations[n].id.label = "Usurer House";
	locations[n].image = "loading\inside\Priem_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "shop";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "reload8_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "street";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "Roseau_Roomtownhall";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].box1.QuestClosed = true;
	locations[n].box2.QuestClosed = true;
	locations[n].box3.QuestClosed = true;

	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "Roseau_Office_Room";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.disable = 1; // закроем, но связку сделаем для квестовых нужд.
	locations[n].reload.l3.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната отдыха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_Office_Room";
	locations[n].id.label = "Bedroom01";
	locations[n].image = "loading\inside\bedroom_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_bank";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Usurer House";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_Roomtownhall";
	locations[n].id.label = "TownhallRoom";
	Locations[n].image = "loading\inside\smallresidence_1.tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
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
	locations[n].reload.l1.go = "Roseau_bank";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_HouseHut5";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Лачуга	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Constantino_House";
	locations[n].id.label = "House_Constantino";
	locations[n].image = "loading\inside\hut_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_houseF1"; 
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\largehouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.largehouse01 = "largehouse01";
	locations[n].models.always.largehouse01.level = 65538;
	locations[n].models.always.locators = "largehouse01_locators";

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
	locations[n].reload.l1.go = "Roseau_town";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Roseau_houseF1Room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната отдыха	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Roseau_houseF1Room";
	locations[n].id.label = "Bedroom01";
	locations[n].image = "loading\inside\Gost_" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Roseau";
 	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Roseau_houseF1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Roseau_exittown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Sound
	locations[n].type = "exittown";
	Locations[n].townsack = "Roseau";
	locations[n].fastreload = "Roseau";
	locations[n].islandId = "Dominica";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Town_Roseau\exit";
	Locations[n].models.always.townExit = "RoseauExit";	
	Locations[n].models.always.locators = "RoseauExit_locators";		
	Locations[n].models.always.grassPatch = "RoseauExit_grass";
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
	locations[n].models.day.charactersPatch = "RoseauExit_patch";
	locations[n].models.day.fonars = "RoseauExit_fd";
	//Night
	locations[n].models.night.charactersPatch = "RoseauExit_patch";
	locations[n].models.night.fonars = "RoseauExit_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Dominica_Jungle_02";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Shore26";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2.0;

                   Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Roseau_town";
	Locations[n].reload.l3.emerge = "gate_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Street";
	locations[n].locators_radius.reload.reload3 = 1.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из подвала	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Dominica_Lighthouse_01";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_3.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Roseau_TownCave";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Dungeon";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Dominica_Lighthouse_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Mayak12";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// МАЯК	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_Lighthouse_02";
	locations[n].id.label = "Mayak12";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "x_seashore";
	locations[n].islandId = "Dominica";
	locations[n].islandIdAreal = "Dominica";
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\Mayak";
	Locations[n].models.always.locators = "mayak_l";
	Locations[n].models.always.shore = "mayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Mayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Mayak_g";

	Locations[n].models.window = "Mayak_win";
	Locations[n].models.light = "Mayak_fl";
	Locations[n].models.light.level = 66530;
	Locations[n].models.light.tech = "LighthouseLight";

	Locations[n].models.always.grassPatch = "lighthouse_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";	

	//Day
	Locations[n].models.day.charactersPatch = "mayak_p";
	Locations[n].models.day.fonar = "Mayak_fd";
	//Night
	Locations[n].models.night.charactersPatch = "mayak_p";
	Locations[n].models.night.fonar = "Mayak_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Dominica_Lighthouse_01";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Mayak";
	locations[n].locators_radius.reload.reload1 = 9.0;
	locations[n].locators_radius.reload.reload1_back = 9.0;

	Locations[n].reload.l2.name = "reload5";
	Locations[n].reload.l2.go = "Dominica_Lighthouse_Inside";
	Locations[n].reload.l2.emerge = "Reload1";
	locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Lighthouse";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Dominica_Lighthouse";
	Locations[n].reload.l3.emerge = "Reload1";
	locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Mayak_House_Jack";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ВНУТРИ МАЯКА
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_Lighthouse_Inside";
	locations[n].id.label = "MayakHouse";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Roseau";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Dominica";
	locations[n].islandIdAreal = "Dominica";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Gothic\Mayak_inside";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "iMayak_sb";
	Locations[n].models.always.seabed.foam = "1";

	Locations[n].models.always.locators = "imayak_l";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.window = "iMayak_w";
	//Day
	Locations[n].models.day.charactersPatch = "imayak_p";
	Locations[n].models.day.jumpPatch = "imayak_j";
	//Night
	Locations[n].models.night.charactersPatch = "imayak_p";
	Locations[n].models.night.jumpPatch = "imayak_j";

	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Dominica_Lighthouse_02";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Mayak12";
	Locations[n].locators_radius.reload.Reload1 = 1.5;

	Locations[n].items.randitem1 = "spyglass4";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ДОМ МАЯКА
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	locations[n].id = "Dominica_Lighthouse";
	locations[n].id.label = "Mayak_House_Jack";
	Locations[n].image = "loading\inside\stonehouse_2.tga";
	//Town sack
	locations[n].townsack = "Roseau";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Dominica";
	locations[n].islandIdAreal = "Dominica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Pirate_House";
	locations[n].models.always.house = "PirH";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "PirH_w";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "PirH_l";
	locations[n].models.day.charactersPatch = "PirH_p";
	//Night
	locations[n].models.night.locators = "PirH_l_n";
	locations[n].models.night.charactersPatch = "PirH_p";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Dominica_Lighthouse_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mayak12";

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс Скотс Хед	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore27";
	locations[n].id.label = "Shore27";
	locations[n].image = "loading\outside\Sandshore.tga";
	locations[n].worldmap = "Dominica";
	locations[n].questflower = 1;
	locations[n].Chestgennot = true; // не генерить сундуки
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Dominica";
	//locations[n].DisableEncounters = true;
	locations[n].onUninhabitedIsland = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore11";
	Locations[n].models.always.shore11 = "sandshore";
	locations[n].models.always.shore11.sea_reflection = 1;
	Locations[n].models.always.shore11seabed = "sandshore_sb";
	Locations[n].models.always.locators = "sandshore_locators";
	
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
	locations[n].reload.l1.name = "reload2_back";
	locations[n].reload.l1.go = "Dominica_Jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Dominica";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 6.0;
	
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Dominica_GrotS";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Grot";
	locations[n].locators_radius.reload.reload3_back = 2;
	
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Shore27";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore27";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Dominica_Jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "jungle";
                       locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Dominica_CaveEntrance";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2;
	n = n + 1;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Dominica";
	locations[n].DisableEncounters = true;
	locations[n].onUninhabitedIsland = true;
	locations[n].dolly = 3;
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
	locations[n].reload.l1.go = "Dominica_Jungle_01";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Indian_town";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Village";
	locations[n].locators_radius.reload.reload2_back = 2;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Roseau_exittown";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "ExitTown";
	locations[n].locators_radius.reload.reload3_back = 2;
	locations[n].locators_radius.item.dolly3 = 1.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Деревня карибов	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Indian_town";
	locations[n].id.label = "Villagee";
	locations[n].image = "loading\Village_" + rand(1) + ".tga";
	locations[n].indianVillage = true;
	//Sound
	locations[n].type = "Village";
	locations[n].islandId = "Dominica";
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
	Locations[n].reload.l1.go = "Dominica_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "IndianlTown_shack1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "shack";
	Locations[n].reload.l2.autoreload = "0";
	
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "IndianlTown_shack2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.label = "shack";
	Locations[n].reload.l3.autoreload = "0";
	
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "IndianlTown_shack3";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "shack";
	Locations[n].reload.l4.autoreload = "0";

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №1 - большая
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "IndianlTown_shack1";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Indian_town";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].items.randitem2 = "indian010";
	Locations[n].items.randitem1 = "indian001";
	Locations[n].box.box1 = "Totem_0012";
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №2
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "IndianlTown_shack2";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Indian_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].box.box1 = "Totem_001";
	
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//// хижина №3
	/////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "IndianlTown_shack3";
	locations[n].id.label = "shack";
	locations[n].image = "loading\inside\vigwam_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Indian_town";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.go = "Indian_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	Locations[n].box.box1 = "Totem_002";
	
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Вход в грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].islandId = "Dominica";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Dominica_Grot";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Dominica_Jungle_01";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Dominica_Grot";
	locations[n].id.label = "Grot";
     locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "Cave";
	locations[n].islandId = "Dominica";
	locations[n].onUninhabitedIsland = true;
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Dominica_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Cave entrance";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].mining2.key = "minepick";
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// мыс Касл Брус	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore26";
	locations[n].id.label = "Shore26";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore26";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Dominica";
	locations[n].DisableEncounters = true;
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
	locations[n].reload.l1.go = "Roseau_exittown";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Dominica";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;


	return n;

}