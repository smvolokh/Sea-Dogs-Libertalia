
int LocationInitTrinidad(int n)
{
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �����
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_town";
	locations[n].id.label = "Street";
	locations[n].worldmap = "Trinidad";
	
	locations[n].townsack = "PortSpein";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
	
	locations[n].filespath.models = "locations\Town_PortSpein\Town\";
	locations[n].image = "loading\town_" + rand(1) + ".tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//==> ���� ��������� ������������ �� ������� �����, int �������� - ���� ��� ��� ���������(1-10)
	locations[n].questSeekCap = 3; 
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].houseEnc = true; //��� ����������� � �����
	//Models
	//Always
	locations[n].models.always.town = "PortSpein";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "PortSpein_signsA";
	locations[n].models.always.seabed = "PortSpein_sb";
	locations[n].models.always.locators = "PortSpein_locators";
	locations[n].models.always.grassPatch = "PortSpein_grass";
	
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
	locations[n].models.day.fonar = "PortSpein_fd";
	locations[n].models.day.charactersPatch = "PortSpein_patch_day";
	locations[n].models.day.rinok = "PortSpein_rinok";
	//Night
	locations[n].models.night.fonar = "PortSpein_fn";
	locations[n].models.night.charactersPatch = "PortSpein_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

    // --> ������� ��������� �������, ������ �������� �� 10 �������.
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Trinidad";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload2_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "PortSpein_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "PortSpein_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "PortSpein_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	locations[n].reload.l5.close_for_night = 1;

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "PortSpein_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "PortSpein_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	//locations[n].reload.l7.close_for_night = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "PortSpein_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Usurer House";
	locations[n].reload.l8.close_for_night = 1;

	locations[n].reload.l10.name = "reload10_back";
	locations[n].reload.l10.go = "PortSpein_PortOffice";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "PortOffice";
	locations[n].reload.l10.close_for_night = 1;

	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "PortSpein_ExitTown";
	locations[n].reload.gate.emerge = "reload4";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	
	locations[n].reload.jail.name = "reload_jail";
	locations[n].reload.jail.go = "PortSpein_prison";
	locations[n].reload.jail.emerge = "reload1";
	locations[n].reload.jail.autoreload = "0";
	locations[n].reload.jail.label = "Prison";
	
    // --> ��������� �������, ������ �������� �� 9 ������
	locations[n].reload.l11.name = "houseF2";
	locations[n].reload.l11.go = "PortSpein_houseF2";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "Comendant_House";
	locations[n].reload.l11.close_for_night = 1;

	locations[n].reload.l12.name = "houseF4";
	locations[n].reload.l12.go = "PortSpein_houseF4";
	locations[n].reload.l12.emerge = "reload1_back";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";

	locations[n].reload.l13.name = "houseF5";
	locations[n].reload.l13.go = "PortSpein_Crypt";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "Crypt";

	locations[n].reload.l14.name = "houseH4";
	locations[n].reload.l14.go = "PortSpein_houseH4";
	locations[n].reload.l14.emerge = "reload1_back";
	locations[n].reload.l14.autoreload = "0";
	locations[n].reload.l14.label = "House";

    // --> ������, ��������. ������ � ���������� � 20.
	locations[n].reload.l20.name = "houseS1";
	locations[n].reload.l20.go = "CommonCobHouse";
	locations[n].reload.l20.emerge = "reload1";
	locations[n].reload.l20.autoreload = "0";
	locations[n].reload.l20.label = "House";

	locations[n].reload.l21.name = "houseSp1";
	locations[n].reload.l21.go = "CommonPirateHouse";
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

	locations[n].reload.l25.name = "houseS3";
	locations[n].reload.l25.go = "CommonPirateHouse";
	locations[n].reload.l25.emerge = "reload1";
	locations[n].reload.l25.autoreload = "0";
	locations[n].reload.l25.label = "House";

	locations[n].reload.l26.name = "houseH2";
	locations[n].reload.l26.go = "CommonRoom_MH4";
	locations[n].reload.l26.emerge = "reload1";
	locations[n].reload.l26.autoreload = "0";
	locations[n].reload.l26.label = "House";

	locations[n].reload.l27.name = "houseS4";
	locations[n].reload.l27.go = "CommonStoneHouse";
	locations[n].reload.l27.emerge = "reload1";
	locations[n].reload.l27.autoreload = "0";
	locations[n].reload.l27.label = "House";
	
	locations[n].reload.l28.name = "houseF1";
	locations[n].reload.l28.go = "CommonRoom_MH9";
	locations[n].reload.l28.emerge = "reload1";
	locations[n].reload.l28.autoreload = "0";
	locations[n].reload.l28.label = "House";

	locations[n].reload.l29.name = "houseSp3";
	locations[n].reload.l29.go = "CommonResidence_BackHall";
	locations[n].reload.l29.emerge = "reload1";
	locations[n].reload.l29.autoreload = "0";
	locations[n].reload.l29.label = "House";

	locations[n].reload.l31.name = "houseF3";
	locations[n].reload.l31.go = "CommonRoom_MH2";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

	locations[n].reload.l32.name = "houseSp4";
	locations[n].reload.l32.go = "CommonDoubleflourHouse_2";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";
	
	locations[n].reload.l33.name = "houseH3";
	locations[n].reload.l33.go = "CommonRoom_MH10";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_tavern";
	locations[n].id.label = "Tavern11";
	locations[n].filespath.models = "locations\inside\tavern01\";
	locations[n].image = "loading\inside\tavern4.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].models.day.charactersPatch = "tavern01_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "PortSpein_tavern_upstairs";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Tavern upstairs";
	locations[n].reload.l2.disable = 1; // �������, �� ������ ������� ��� ��������� ����.
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ������� � �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_tavern_upstairs";
	locations[n].id.label = "Tavern upstairs";
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].image = "loading\inside\tavern.tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\store02\";
	locations[n].image = "loading\inside\shop_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortSpein";
  	locations[n].islandId = "Trinidad";
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
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
    ////////////////////////==> ������� � ��������
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonPackhouse_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ���������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_bank";
	locations[n].id.label = "Usurer House";
	locations[n].filespath.models = "locations\inside\Bank01\";
	locations[n].image = "loading\inside\bank_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PortSpein";
  	locations[n].islandId = "Trinidad";
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
	//locations[n].models.back = "back\redss_";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortSpein_town";
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
	// �����
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_Shipyard";
	locations[n].id.label = "Shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard01\";
	locations[n].image = "loading\inside\shipyard_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "PortSpein";
  	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
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
	// ����������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence01";
	locations[n].image = "loading\inside\residence_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
 	// ������
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonResidence_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "CommonResidence_4";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_church";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������� ����
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ��� ���������� ���-����
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_houseF2";
	locations[n].filespath.models = "locations\inside\CobHouse";
	locations[n].id.label = "Comendant_House";
	locations[n].image = "loading\inside\CobHouse_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
	////////////////////// prison ////////////////////////////
	Locations[n].id = "PortSpein_prison";
	locations[n].id.label = "Prison";
	locations[n].image = "loading\inside\prison_" + rand(1) + ".tga";
	locations[n].townsack = "PortSpein";
    locations[n].parent_colony = "PortSpein";
 	locations[n].fastreload = "PortSpein";
	locations[n].islandId = "Trinidad";
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
	Locations[n].reload.l1.go = "PortSpein_town";
	Locations[n].reload.l1.emerge = "reload_jail";
	Locations[n].reload.l1.autoreload = "0";
	
	locations[n].locators_radius.box.box1 = 0.8;
	locations[n].box1.QuestClosed = true;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ������	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_houseF4";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	//Sound
	locations[n].type = "house_Gotika";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "houseF4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ������	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_houseH4"; 
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\largehouse01.tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	//Sound
	locations[n].type = "house_Gotika";
	locations[n].islandId = "Trinidad";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Hut1";
	locations[n].models.always.locators = "Hut1_locators";
	locations[n].models.always.tavern = "Hut1";
	//Day
	locations[n].models.day.charactersPatch = "Hut1_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "houseH4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
		
	locations[n].private1.items.clock1 = 1;
	locations[n].private1.items.totem_02 = 1;
	locations[n].private1.items.indian_4 = 1;
	locations[n].private1.items.obereg_6 = 1;
	locations[n].private1.items.amulet_11 = 1;
	locations[n].private1.items.potion2 = 5;
	locations[n].private1.items.potion4 = 2;
	locations[n].private1.items.berserker_potion = 1;
	n = n + 1;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ������ ������� - 1
	/////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_Crypt";
	locations[n].id.label = "Crypt";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "PortSpein";
	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "houseF5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortSpein_Graveyard_crypt";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Crypt";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	//�����	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_Graveyard_crypt";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_1.tga";
	locations[n].MustSetReloadBack = true;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_Crypt";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Church";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "PortSpein_crypt2";
	Locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "crypt";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�����	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_crypt2";
	locations[n].id.label = "crypt";
	locations[n].image = "loading\crypt_0.tga";
	locations[n].MustSetReloadBack = true;
	//Sound
	locations[n].type = "crypt";
	locations[n].fastreload = "PortSpein";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_Graveyard_crypt";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "crypt";
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����� �� ������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "PortSpein_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(3) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "PortSpein_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "PortSpein";

	locations[n].reload.l2.name = "reload3_back";
	locations[n].reload.l2.go = "Trinidad_Jungle_02";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	locations[n].reload.l3.name = "reload2_back";
	locations[n].reload.l3.go = "Trinidad_Jungle_01";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;

	locations[n].reload.l4.name = "reload1_back";
	locations[n].reload.l4.go = "PortSpein_Fort";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "1";
	locations[n].reload.l4.label = "PortSpein Fort";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Trinidad_Jungle_01";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_ExitTown";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.Reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Trinidad_CaveEntrance";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Cave entrance";
	locations[n].locators_radius.reload.Reload2_back = 2.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Mayak1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "1";
	locations[n].reload.l3.label = "Mayak1";
	locations[n].locators_radius.reload.Reload3_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ���� ��������� � ������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Mayak1";
	locations[n].id.label = "Mayak1";
	locations[n].worldmap = "Mayak1";
	locations[n].image = "loading\outside\lighthouse_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "mayak";
 	locations[n].islandId = "Trinidad";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Lighthouse";
	Locations[n].models.always.lighthouse = "lighthouse";
	locations[n].models.always.lighthouse.sea_reflection = 1;
	Locations[n].models.always.lighthouseSeabed = "lighthouse_sb";
	Locations[n].models.always.locators = "lighthouse_locators";
	
	Locations[n].models.always.dooropen = "lighthouse_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouse_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouse_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouse_winday";
	locations[n].models.day.fonar = "lighthouse_fd";
	locations[n].models.day.charactersPatch = "lighthouse_patch";
	Locations[n].models.day.jumpPatch = "lighthouse_jamp";
	
	locations[n].models.day.glassinday = "lighthouse_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouse_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;	
	//Night
	locations[n].models.night.volumeLight= "lighthouse_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouse_fn";
	locations[n].models.night.winnight = "lighthouse_winnight";
	locations[n].models.night.winnight.tech = "LighthouseLight";
	locations[n].models.night.winnight.level = 66529;
	locations[n].models.night.charactersPatch = "lighthouse_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse_fonaronnight";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Trinidad_Jungle_01";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3.0;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_4";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 12.0;
	
	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "Mayak1_Lighthouseroom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.label = "room";
	locations[n].locators_radius.reload.reload2 = 1.0;
	n = n + 1;
	
	////////////////////////////////////////////////////////////////////////////////
	//////////������� �� �����
	////////////////////////////////////////////////////////////////////////////////
	
	locations[n].id = "Mayak1_Lighthouseroom";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse_" + rand(2) + ".tga";
	//Town sack
	locations[n].townsack = "PortSpein";
	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Mayak1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Mayak1";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ���� � ������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Trinidad_CaveEntrance";
	locations[n].id.label = "Cave entrance";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Trinidad_Grot";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	locations[n].locators_radius.reload.reload1_back = 1.3;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Trinidad_jungle_01";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Trinidad_Grot";
	locations[n].id.label = "Grot";
	locations[n].image = "loading\inside\Grot_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "cave";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Trinidad_CaveEntrance";
	locations[n].reload.l1.emerge = "reload1";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Trinidad_Jungle_02";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(9) + ".tga";
	//Sound
	locations[n].type = "jungle";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "PortSpein_ExitTown";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Shore60";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Shore60";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ��� �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore60";
	locations[n].id.label = "Shore60";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore60";
	//Sound
	locations[n].type = "seashore";
 	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Trinidad_Jungle_02";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
    locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////
	//����� ��������
	//////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore59";
	locations[n].id.label = "Shore59";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	//Sound
	locations[n].type = "seashore";
 	locations[n].islandId = "Trinidad";
	locations[n].DisableEncounters = true;
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Shore08";
	Locations[n].models.always.shore = "shore08";
	locations[n].models.always.shore.sea_reflection = 1;
	Locations[n].models.always.seabed = "shore08_sb";
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
	locations[n].reload.l1.go = "Common_jungle_01";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 9.0;

	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ����� �����, ��������	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Shore127";
	locations[n].id.label = "Shore127";
	Locations[n].image = "loading\outside\temple.tga";
	locations[n].worldmap = "Shore127";
	//Sound
	locations[n].type = "x_seashore";
	locations[n].islandId = "Trinidad";
	locations[n].deadlocked = true;
	locations[n].questflower = 1;
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\pyramid1\";
	Locations[n].models.always.pyramid1 = "pyramid1";
	locations[n].models.always.pyramid1.sea_reflection = 1;
	Locations[n].models.always.pyramid1seabed = "pyramid1_sb";
	Locations[n].models.always.locators = "pyramid1_locators";
	
	Locations[n].models.always.grassPatch = "pyramid1_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
			
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 99948;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 99947;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 99946;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 99945;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	locations[n].models.always.L5 = "xebec_wreck";
	Locations[n].models.always.L5.locator.group = "quest";
	Locations[n].models.always.L5.locator.name = "quest1";
	Locations[n].models.always.L5.tech = "DLightModel";
	locations[n].models.always.L6 = "Bfire";
	Locations[n].models.always.L6.locator.group = "goto";
	Locations[n].models.always.L6.locator.name = "fire";
	Locations[n].models.always.L6.tech = "DLightModel";
	locations[n].models.always.L7 = "leaf";
	Locations[n].models.always.L7.locator.group = "quest";
	Locations[n].models.always.L7.locator.name = "quest2";
	Locations[n].models.always.L7.tech = "DLightModel";
	locations[n].models.always.L8 = "leaf";
	Locations[n].models.always.L8.locator.group = "quest";
	Locations[n].models.always.L8.locator.name = "quest3";
	Locations[n].models.always.L8.tech = "DLightModel";
	locations[n].models.always.L9 = "leaf";
	Locations[n].models.always.L9.locator.group = "quest";
	Locations[n].models.always.L9.locator.name = "quest4";
	Locations[n].models.always.L9.tech = "DLightModel";
	locations[n].models.always.L10 = "leaf";
	Locations[n].models.always.L10.locator.group = "quest";
	Locations[n].models.always.L10.locator.name = "quest5";
	Locations[n].models.always.L10.tech = "DLightModel";
	
	//Waterfall
	Locations[n].models.always.Waterfall1 = "waterfall1";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.2;
                     Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 99950;
	
	Locations[n].models.always.Waterfall2 = "waterfall2";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
                     Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 99949;	
	//Day
	locations[n].models.day.charactersPatch = "pyramid1_patch";
	//Night
	locations[n].models.night.charactersPatch = "pyramid1_patch";		
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Common_jungle_01"; //�� ������������ �����
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_5";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Temple_Trinidad_Inside_2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �������� ������ �������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Temple_Trinidad_Inside_2";
	locations[n].id.label = "Pyramid1Inside";
	Locations[n].image = "loading\outside\TempleInside.tga";	
	//Sound
	locations[n].type = "teno_inside";
	locations[n].id.label = "Incas Temple";
 	locations[n].islandId = "Trinidad";
	//Models
	//Always
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TempleGreatInside_1";
	locations[n].models.always.TemplePointInside_1 = "TempleGreatInside_1";
	locations[n].models.always.locators = "TempleGreatInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleGreatInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleGreatInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Shore127";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l2.label = "Shore127";
	Locations[n].locators_radius.item.item1 = 1.1;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ����� �����	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore128";
	locations[n].id.label = "Shore128";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore128";
	locations[n].DisableEncounters = true;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Trinidad";
	locations[n].deadlocked = true;
	locations[n].questflower = 1;
	locations[n].Chestgennot = true; // �� �������� �������
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
	locations[n].reload.l1.go = "Common_jungle_01"; //�� ������������ �����
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_6";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����� ����������	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore129";
	locations[n].id.label = "Shore129";
	locations[n].image = "loading\outside\harbor_" + rand(5) + ".tga";
	locations[n].worldmap = "Shore129";
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Common_jungle_01"; //�� ������������ �����
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_7";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                   locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ���� ����������	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Shore130";
	locations[n].id.label = "Shore130";
	locations[n].image = "loading\outside\harbor3.tga";
	locations[n].worldmap = "Shore130";
	locations[n].fennisgrass = 1;
	//Sound
	locations[n].type = "seashore";
	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Strange_Grotto_2";
	locations[n].reload.l1.emerge = "reload3_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "cave";
	locations[n].locators_radius.reload.reload1_back = 3;

	locations[n].reload.l2.name = "boat";
	locations[n].reload.l2.go = "Trinidad";
	locations[n].reload.l2.emerge = "reload_8";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
                     locations[n].locators_radius.reload.boat = 9.0;
	n = n + 1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	// ������ ����	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Strange_Grotto_2";
	locations[n].id.label = "Grotto Strange";
    	locations[n].image = "loading\inside\cave3.tga";
	locations[n].RuinsZombie = 5; // ����� �������� � �������
	//Sound
	locations[n].type = "cave";
	locations[n].islandId = "Trinidad";
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
	locations[n].reload.l1.go = "Shore130";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore130";
	locations[n].locators_radius.reload.reload1_back = 2;
	
	n = n + 1;

	return n;
}