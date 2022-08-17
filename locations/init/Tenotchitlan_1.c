
int LocationInitTenotchitlan_1(int n)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Tenochtitlan_1";
	locations[n].id.label = "Tenochtitlan_1";
	locations[n].filespath.models = "locations\Gothic\Tenochtitlan_1";
	locations[n].image = "loading\outside\TenochtitlanCity.tga";
	//Sound
	locations[n].type = "Tenotchitlan";
	locations[n].islandId = "Mein";
	locations[n].islandIdAreal = "Tenotchitlan_1";
	locations[n].gotoFire = true; //локаторы teleport вспыхивают и ранят
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	//Models
	//Always
	locations[n].models.always.Tenochtitlan_1 = "Tenochtitlan_1";
	locations[n].models.always.reflect = "Tenochtitlan_1_reflect";
	locations[n].models.always.reflect.sea_reflection = 1;
	locations[n].models.always.seabed = "Tenochtitlan_1_sb";
	locations[n].models.always.grassPatch = "Tenochtitlan_1_grass";
	Locations[n].models.day.jumpPatch = "Tenochtitlan_1_jamp";
	Locations[n].models.night.jumpPatch = "Tenochtitlan_1_jamp";
	locations[n].models.always.locators = "Tenochtitlan_1_locators";
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 12;
	locations[n].models.always.plan = "plan2";
	locations[n].models.always.plan.level = 11;
	locations[n].models.always.plan = "plan3";
	locations[n].models.always.plan.level = 10;
	locations[n].models.always.plan = "plan4";
	locations[n].models.always.plan.level = 9;	
	//Day
	locations[n].models.day.charactersPatch = "Tenochtitlan_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tenochtitlan_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Bel_jungle_03";
	locations[n].reload.l1.emerge = "reload2_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	//---------- храм №1 ----------
	locations[n].reload.l2.name = "reloadTemple1";
	locations[n].reload.l2.go = "Templee_1_1";
	locations[n].reload.l2.emerge = "reload1";
	//---------- храм №2 ----------
	locations[n].reload.l3.name = "reloadTemple2";
	locations[n].reload.l3.go = "Templee_2_1";
	locations[n].reload.l3.emerge = "reload2";
	//---------- храм №3 ----------
	locations[n].reload.l4.name = "reloadTemple3";
	locations[n].reload.l4.go = "Templee_3_1";
	locations[n].reload.l4.emerge = "reload3";
	//---------- храм №4 ----------
	locations[n].reload.l5.name = "reloadTemple4";
	locations[n].reload.l5.go = "Templee_4_1";
	locations[n].reload.l5.emerge = "reload4";
	//---------- храм №5 ----------
	locations[n].reload.l6.name = "reloadTemple5";
	locations[n].reload.l6.go = "Templee_5_1";
	locations[n].reload.l6.emerge = "reload5";
	//---------- храм №6 ----------
	locations[n].reload.l7.name = "reloadTemple6";
	locations[n].reload.l7.go = "Templee_6_1";
	locations[n].reload.l7.emerge = "reload1";
	//---------- храм №7 ----------
	locations[n].reload.l8.name = "reloadTemple7";
	locations[n].reload.l8.go = "Templee_7_1";
	locations[n].reload.l8.emerge = "reload2";
	//---------- храм №8 ----------
	locations[n].reload.l9.name = "reloadTemple8";
	locations[n].reload.l9.go = "Templee_8_1";
	locations[n].reload.l9.emerge = "reload3";
	//---------- храм №9 ----------
	locations[n].reload.l10.name = "reloadTemple9";
	locations[n].reload.l10.go = "Templee_9_1";
	locations[n].reload.l10.emerge = "reload4";
	//---------- храм №10 ----------
	locations[n].reload.l11.name = "reloadTemple10";
	locations[n].reload.l11.go = "Templee_10_1";
	locations[n].reload.l11.emerge = "reload5";
	//---------- храм №11 ----------
	locations[n].reload.l12.name = "reloadTemple11";
	locations[n].reload.l12.go = "Templee_11_1";
	locations[n].reload.l12.emerge = "reload5";
	//---------- храм №12 ----------
	locations[n].reload.l13.name = "reloadTemple12";
	locations[n].reload.l13.go = "Templee_12_1";
	locations[n].reload.l13.emerge = "reload4";
	//---------- храм №13 ----------
	locations[n].reload.l14.name = "reloadTemple13";
	locations[n].reload.l14.go = "Templee_13_1";
	locations[n].reload.l14.emerge = "reload3";
	//---------- храм №14 ----------
	locations[n].reload.l15.name = "reloadTemple14";
	locations[n].reload.l15.go = "Templee_14_1";
	locations[n].reload.l15.emerge = "reload2";
	//---------- храм №15 ----------
	locations[n].reload.l16.name = "reloadTemple15";
	locations[n].reload.l16.go = "Templee_15_1";
	locations[n].reload.l16.emerge = "reload1";
	//---------- храм №16 ----------
	locations[n].reload.l17.name = "reloadTemple16";
	locations[n].reload.l17.go = "Templee_16_1";
	locations[n].reload.l17.emerge = "reload5";
	//---------- храм №17----------
	locations[n].reload.l18.name = "reloadTemple17";
	locations[n].reload.l18.go = "Templee_17_1";
	locations[n].reload.l18.emerge = "reload4";
	//---------- храм №18----------
	locations[n].reload.l19.name = "reloadTemple18";
	locations[n].reload.l19.go = "Templee_18_1";
	locations[n].reload.l19.emerge = "reload3";
	//---------- храм №19----------
	locations[n].reload.l20.name = "reloadTemple19";
	locations[n].reload.l20.go = "Templee_19_1";
	locations[n].reload.l20.emerge = "reload2";
	//---------- храм №20----------
	locations[n].reload.l21.name = "reloadTemple20";
	locations[n].reload.l21.go = "Templee_20_1";
	locations[n].reload.l21.emerge = "reload1";
	//---------- храм №21----------
	locations[n].reload.l22.name = "reloadTemple21";
	locations[n].reload.l22.go = "Templee_21_1";
	locations[n].reload.l22.emerge = "reload5";
	//---------- храм №22----------
	locations[n].reload.l23.name = "reloadTemple22";
	locations[n].reload.l23.go = "Templee_22_1";
	locations[n].reload.l23.emerge = "reload4";
	//---------- храм №23----------
	locations[n].reload.l24.name = "reloadTemple23";
	locations[n].reload.l24.go = "Templee_23_1";
	locations[n].reload.l24.emerge = "reload3";
	//---------- храм №24----------
	locations[n].reload.l25.name = "reloadTemple24";
	locations[n].reload.l25.go = "Templee_24_1";
	locations[n].reload.l25.emerge = "reload2";
	//---------- храм №25----------
	locations[n].reload.l26.name = "reloadTemple25";
	locations[n].reload.l26.go = "Templee_25_1";
	locations[n].reload.l26.emerge = "reload1";
	//---------- храм №26----------
	locations[n].reload.l27.name = "reloadTemple26";
	locations[n].reload.l27.go = "Templee_26_1";
	locations[n].reload.l27.emerge = "reload5";
	//---------- храм №27----------
	locations[n].reload.l28.name = "reloadTemple27";
	locations[n].reload.l28.go = "Templee_27_1";
	locations[n].reload.l28.emerge = "reload4";
	//---------- храм №28----------
	locations[n].reload.l29.name = "reloadTemple28";
	locations[n].reload.l29.go = "Templee_28_1";
	locations[n].reload.l29.emerge = "reload3";
	//---------- храм №29----------
	locations[n].reload.l30.name = "reloadTemple29";
	locations[n].reload.l30.go = "Templee_29_1";
	locations[n].reload.l30.emerge = "reload2";
	//---------- храм №30----------
	locations[n].reload.l31.name = "reloadTemple30";
	locations[n].reload.l31.go = "Templee_30_1";
	locations[n].reload.l31.emerge = "reload1";


	//---------- храм большой ----------
	locations[n].reload.l32.name = "reloadTemple32";
	locations[n].reload.l32.go = "Templee_great_1";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.disable = true;
	locations[n].reload.l33.name = "reloadTemple33";
	locations[n].reload.l33.go = "Templee_great_1";
	locations[n].reload.l33.emerge = "reload2";
	locations[n].reload.l33.disable = true;
	locations[n].reload.l34.name = "reloadTemple34";
	locations[n].reload.l34.go = "Templee_great_1";
	locations[n].reload.l34.emerge = "reload3";
	locations[n].reload.l34.disable = true;

	locations[n].reload.l35.name = "reloadTemple41";
	locations[n].reload.l35.go = "Templee_great_1";
	locations[n].reload.l35.emerge = "reload4";
	locations[n].reload.l35.disable = true;
	locations[n].reload.l36.name = "reloadTemple42";
	locations[n].reload.l36.go = "Templee_great_1";
	locations[n].reload.l36.emerge = "reload5";
	locations[n].reload.l36.disable = true;
	locations[n].reload.l37.name = "reloadTemple43";
	locations[n].reload.l37.go = "Templee_great_1";
	locations[n].reload.l37.emerge = "reload6";
	locations[n].reload.l37.disable = true;

	locations[n].reload.l38.name = "reloadTemple40";
	locations[n].reload.l38.go = "Templee_great_1";
	locations[n].reload.l38.emerge = "reload7";
	locations[n].reload.l38.disable = true;
	locations[n].reload.l39.name = "reloadTemple39";
	locations[n].reload.l39.go = "Templee_great_1";
	locations[n].reload.l39.emerge = "reload8";
	locations[n].reload.l39.disable = true;
	//---------- храм круглый ----------
	locations[n].reload.l40.name = "reloadTemple31";
	locations[n].reload.l40.go = "Templee_round_1";
	locations[n].reload.l40.emerge = "reload1";
	locations[n].reload.l40.disable = true;
	locations[n].locators_radius.item.button01 = 1.4;
	//---------- храм черепков ----------
	locations[n].reload.l41.name = "reloadTemple35";
	locations[n].reload.l41.go = "Templee_Skulls_1";
	locations[n].reload.l41.emerge = "reload1";
	locations[n].reload.l42.name = "reloadTemple36";
	locations[n].reload.l42.go = "Templee_Skulls_1";
	locations[n].reload.l42.emerge = "reload2";
	locations[n].reload.l43.name = "reloadTemple37";
	locations[n].reload.l43.go = "Templee_Skulls_1";
	locations[n].reload.l43.emerge = "reload3";
	//---------- подводные храмы ----------
	locations[n].reload.l44.name = "reloadU1_back";
	locations[n].reload.l44.go = "Templee_Underwater_right_1";
	locations[n].reload.l44.emerge = "reload1";
	locations[n].reload.l44.autoreload = "1";
	locations[n].locators_radius.reload.reloadU1_back = 3.0;
	locations[n].reload.l45.name = "reloadU2_back";
	locations[n].reload.l45.go = "Templee_Underwater_left_1";
	locations[n].reload.l45.emerge = "reload1";
	locations[n].reload.l45.autoreload = "1";
	locations[n].locators_radius.reload.reloadU2_back = 3.0;

	string sTemp;
	for(int i=1; i<=20; i++)
	{
		sTemp = "fire" + i;
		locations[n].locators_radius.teleport.(sTemp) = 4.1;
	}
	int iTenoc = n;

	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Храмы Тотемов
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//----------------- Храм №1 ------------------------	
	locations[n].id = "Templee_1_1";
	locations[n].id.label = "Xochiquetzal_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx1 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple1";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №2 ------------------------
	locations[n].id = "Templee_2_1";
	locations[n].id.label = "Mictlantecuhtli_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx2 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple2";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №3 ------------------------
	locations[n].id = "Templee_3_1";
	locations[n].id.label = "Quetzalcoatl_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx3 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple3";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №4 ------------------------
	locations[n].id = "Templee_4_1";
	locations[n].id.label = "Mixcoatl_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx4 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple4";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №5 ------------------------
	locations[n].id = "Templee_5_1";
	locations[n].id.label = "Tezcatlipoca_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx5 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple5";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №6 ------------------------
	locations[n].id = "Templee_6_1";
	locations[n].id.label = "Chalchiuhtlicue_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx6 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple6";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №7 ------------------------
	locations[n].id = "Templee_7_1";
	locations[n].id.label = "Huitzilopochtli_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx7 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple7";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №8 ------------------------
	locations[n].id = "Templee_8_1";
	locations[n].id.label = "Tlaloc_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx8 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple8";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №9 ------------------------
	locations[n].id = "Templee_9_1";
	locations[n].id.label = "Mayahuel_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx9 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple9";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №10 ------------------------
	locations[n].id = "Templee_10_1";
	locations[n].id.label = "Tonacatecuhtli_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[iTenoc].temples.idx10 = n; //в локацию Теночтитлана индекс храма
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple10";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №11 ------------------------
	locations[n].id = "Templee_11_1";
	locations[n].id.label = "Teopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple11";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №12 ------------------------
	locations[n].id = "Templee_12_1";
	locations[n].id.label = "Teopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple12";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №13 ------------------------
	locations[n].id = "Templee_13_1";
	locations[n].id.label = "Teopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple13";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №14 ------------------------
	locations[n].id = "Templee_14_1";
	locations[n].id.label = "Teopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple14";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №15 ------------------------
	locations[n].id = "Templee_15_1";
	locations[n].id.label = "Teopan_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleSecondInside_1\";
	Locations[n].models.always.Temple = "TempleSecondInside_1";
	Locations[n].models.always.locators = "TempleSecondInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleSecondInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleSecondInside_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple15";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Tenochtitlan_1";
	locations[n].reload.l2.emerge = "reloadTemple15";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Tenochtitlan_1";
	locations[n].reload.l3.emerge = "reloadTemple15";
	n = n + 1;
	//----------------- Храм №16 ------------------------
	locations[n].id = "Templee_16_1";
	locations[n].id.label = "Moiotlan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple16";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №17 ------------------------
	locations[n].id = "Templee_17_1";
	locations[n].id.label = "Moiotlan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple17";

	locations[n].reload.l2.name = "reload6";
	locations[n].reload.l2.go = "Templee_great_2";
	locations[n].reload.l2.emerge = "reload11";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "TempleGreatInside_1";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №18------------------------
	locations[n].id = "Templee_18_1";
	locations[n].id.label = "Moiotlan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple18";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №19------------------------
	locations[n].id = "Templee_19_1";
	locations[n].id.label = "Moiotlan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple19";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №20------------------------
	locations[n].id = "Templee_20_1";
	locations[n].id.label = "Moiotlan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple20";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №21------------------------
	locations[n].id = "Templee_21_1";
	locations[n].id.label = "Kuipopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple21";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №22------------------------
	locations[n].id = "Templee_22_1";
	locations[n].id.label = "Kuipopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple22";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №23------------------------
	locations[n].id = "Templee_23_1";
	locations[n].id.label = "Kuipopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple23";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №24------------------------
	locations[n].id = "Templee_24_1";
	locations[n].id.label = "Kuipopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple24";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №25------------------------
	locations[n].id = "Templee_25_1";
	locations[n].id.label = "Kuipopan_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple25";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №26------------------------
	locations[n].id = "Templee_26_1";
	locations[n].id.label = "Astacalko_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload5";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple26";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №27------------------------
	locations[n].id = "Templee_27_1";
	locations[n].id.label = "Astacalko_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple27";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №28-----------------------
	locations[n].id = "Templee_28_1";
	locations[n].id.label = "Astacalko_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple28";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №29-----------------------
	locations[n].id = "Templee_29_1";
	locations[n].id.label = "Astacalko_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TemplePointInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	locations[n].models.always.TemplePointInside_1 = "TemplePointInside_1";
	locations[n].models.always.locators = "TemplePointInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TemplePointInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TemplePointInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple29";
	locations[n].locators_radius.reload.reload6 = 0.0;
	n = n + 1;
	//----------------- Храм №30-----------------------
	locations[n].id = "Templee_30_1";
	locations[n].id.label = "Astacalko_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].smallGodTemple = 0; //кол-во посещений храма геймером
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleSecondInside_1\";
	Locations[n].models.always.Temple = "TempleSecondInside_1";
	Locations[n].models.always.locators = "TempleSecondInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleSecondInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleSecondInside_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple30";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Tenochtitlan_1";
	locations[n].reload.l2.emerge = "reloadTemple30";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Tenochtitlan_1";
	locations[n].reload.l3.emerge = "reloadTemple30";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Большой Храм
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Templee_great_1";
	locations[n].id.label = "TempleGreatInside_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TempleGreatInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].changeAnimation = "man_A"; //сменить анимацию на обычную
	locations[n].greatTemplee = true;
	//Models
	//Always
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple32";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Tenochtitlan_1";
	locations[n].reload.l2.emerge = "reloadTemple33";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Tenochtitlan_1";
	locations[n].reload.l3.emerge = "reloadTemple34";

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Tenochtitlan_1";
	locations[n].reload.l4.emerge = "reloadTemple41";
	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "Tenochtitlan_1";
	locations[n].reload.l5.emerge = "reloadTemple42";
	locations[n].reload.l6.name = "reload6";
	locations[n].reload.l6.go = "Tenochtitlan_1";
	locations[n].reload.l6.emerge = "reloadTemple43";

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "Tenochtitlan_1";
	locations[n].reload.l7.emerge = "reloadTemple40";
	locations[n].reload.l8.name = "reload8";
	locations[n].reload.l8.go = "Tenochtitlan_1";
	locations[n].reload.l8.emerge = "reloadTemple39";

	locations[n].reload.l9.name = "reload9";
	locations[n].reload.l9.go = "Templee_Underwater_right_1";
	locations[n].reload.l9.emerge = "reload2";
	locations[n].reload.l9.autoreload = "1";
	locations[n].reload.l10.name = "reload10";
	locations[n].reload.l10.go = "Templee_Underwater_left_1";
	locations[n].reload.l10.emerge = "reload2";
	locations[n].reload.l10.autoreload = "1";

	locations[n].locators_radius.reload.reload9 = 1.2;
	locations[n].locators_radius.reload.reload10 = 1.2;
	//каменные сундуки
	locations[n].private1.closed = true;
	locations[n].private1.items.KnifeAztecs = 1;
	locations[n].private1.items.talisman1 = 1;
	locations[n].private1.items.totem_12 = 1;
	locations[n].private1.items.indian_3 = 1;
	locations[n].private1.items.indian_10 = 1;
	locations[n].private1.items.obereg_2 = 1;
	locations[n].private1.items.potion7 = 10;
	locations[n].private1.items.cannabis1 = 20;
	locations[n].private1.items.cannabis4 = 20;
	locations[n].private1.items.cannabis7 = 5;
	locations[n].private1.items.jewelry22 = 100; // всякое уже не очень нужное барахло

	locations[n].private2.closed = true;
	locations[n].private2.money = 120100;
	locations[n].private2.items.indian010 = 11;
	locations[n].private2.items.indian011 = 12;
	locations[n].private2.items.indian012 = 15;
	locations[n].private2.items.indian013 = 7;
	locations[n].private2.items.indian014 = 9;
	locations[n].private2.items.indian015 = 4;
	locations[n].private2.items.indian016 = 13;
	locations[n].private2.items.indian017 = 8;
	locations[n].private2.items.indian018 = 6;
	locations[n].private2.items.indian019 = 12;
	locations[n].private2.items.indian020 = 4;
	locations[n].private2.items.indian021 = 7;
	locations[n].private2.items.indian022 = 11;

	locations[n].private3.items.Totem_0012 = 1;
	locations[n].private3.items.indian007 = 1;
	locations[n].private3.items.indian008 = 2;
	locations[n].private3.items.indian009 = 2;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Большой Храм2
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Templee_great_2";
	locations[n].id.label = "TempleGreatInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	locations[n].idxTenoc = iTenoc; //индекс Теночтитлана
	locations[n].changeAnimation = "man"; //сменить анимацию на обычную
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
	locations[n].reload.l1.name = "reload11";
	locations[n].reload.l1.go = "Templee_17_1";
	locations[n].reload.l1.emerge = "reload6";

	locations[n].reload.l2.name = "reload8";
	locations[n].reload.l2.go = "Temple_Treasure_1";
	locations[n].reload.l2.emerge = "reload1";

	locations[n].reload.l3.name = "reload1";
	locations[n].reload.l3.go = "Templee_Skulls_2";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l4.name = "reload2";
	locations[n].reload.l4.go = "Templee_Skulls_2";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l5.name = "reload3";
	locations[n].reload.l5.go = "Templee_Skulls_2";
	locations[n].reload.l5.emerge = "reload3";

	locations[n].reload.l6.name = "reload4";
	locations[n].reload.l6.go = "Templee_Skulls_3";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l7.name = "reload5";
	locations[n].reload.l7.go = "Templee_Skulls_3";
	locations[n].reload.l7.emerge = "reload2";
	locations[n].reload.l8.name = "reload6";
	locations[n].reload.l8.go = "Templee_Skulls_3";
	locations[n].reload.l8.emerge = "reload3";
	n = n + 1;

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Круглый Храм
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Templee_round_1";
	locations[n].id.label = "TempleRoundInside_1";
	locations[n].filespath.models = "locations\Gothic\TenochtitlanInside_1\TempleRoundInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";	
	//Sound
	locations[n].type = "tenotchitlan_inside";
	//Models
	//Always
	locations[n].models.always.TempleRoundInside_1 = "TempleRoundInside_1";
	locations[n].models.always.locators = "TempleRoundInside_1_locators";
	//Day
	locations[n].models.day.charactersPatch = "TempleRoundInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleRoundInside_1_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple31";
	locations[n].locators_radius.item.item1 = 1.6;
	
	locations[n].DisableOfficers = "1";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Храм Черепов
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Templee_Skulls_1";
	locations[n].id.label = "TempleSecondInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleSecondInside_1\";
	Locations[n].models.always.Temple = "TempleSecondInside_1";
	Locations[n].models.always.locators = "TempleSecondInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleSecondInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleSecondInside_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadTemple35";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Tenochtitlan_1";
	locations[n].reload.l2.emerge = "reloadTemple36";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Tenochtitlan_1";
	locations[n].reload.l3.emerge = "reloadTemple37";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Храм Черепов2
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Templee_Skulls_2";
	locations[n].id.label = "TempleSecondInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleSecondInside_1\";
	Locations[n].models.always.Temple = "TempleSecondInside_1";
	Locations[n].models.always.locators = "TempleSecondInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleSecondInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleSecondInside_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Templee_great_2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Templee_great_2";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Templee_great_2";
	locations[n].reload.l3.emerge = "reload3";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Храм Черепов3
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Templee_Skulls_3";
	locations[n].id.label = "TempleSecondInside_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleSecondInside_1\";
	Locations[n].models.always.Temple = "TempleSecondInside_1";
	Locations[n].models.always.locators = "TempleSecondInside_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleSecondInside_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleSecondInside_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Templee_great_2";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Templee_great_2";
	locations[n].reload.l2.emerge = "reload5";
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Templee_great_2";
	locations[n].reload.l3.emerge = "reload6";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан сокровищница
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Temple_Treasure_1";
	locations[n].id.label = "TempleTreasure";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound
	locations[n].type = "tenotchitlan_inside";
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
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Templee_great_2";
	locations[n].reload.l1.emerge = "reload8";
	
	// лари, сундуки
	locations[n].private1.key = "keys_skel";
	locations[n].private1.items.icollection = 10;
	locations[n].private1.items.jewelry14 = 500;
	locations[n].private1.items.jewelry15 = 400;
	
	locations[n].private2.key = "keys_skel";
	locations[n].private2.items.icollection = 10;
	locations[n].private2.items.jewelry2 = 1000;
	locations[n].private2.items.jewelry10 = 100;
	
	locations[n].private3.key = "keys_skel";
	locations[n].private3.items.icollection = 10;
	locations[n].private3.items.jewelry16 = 300;
	locations[n].private3.items.jewelry17 = 600;
	
	locations[n].private4.key = "keys_skel";
	locations[n].private4.items.icollection = 10;
	locations[n].private4.items.jewelry18 = 450;
	locations[n].private4.items.jewelry20 = 700;
	
	locations[n].private5.key = "keys_skel";
	locations[n].private5.items.icollection = 10;
	locations[n].private5.items.jewelry3 = 1000;
	
	locations[n].private6.key = "keys_skel";
	locations[n].private6.items.icollection = 10;
	locations[n].private6.items.jewelry4 = 1000;
	
	locations[n].private7.key = "keys_skel";
	locations[n].private7.items.icollection = 10;
	locations[n].private7.items.jewelry14 = 500;
	
	locations[n].private8.key = "keys_skel";
	locations[n].private8.items.icollection = 10;
	locations[n].private8.items.jewelry1 = 1000;
	locations[n].private8.items.jewelry7 = 100;
	
	locations[n].private9.key = "keys_skel";
	locations[n].private9.items.icollection = 10;
	locations[n].private9.items.jewelry21 = 250;
	locations[n].private9.items.jewelry23 = 750;
	
	locations[n].private10.key = "keys_skel";
	locations[n].private10.items.icollection = 100;
	
	locations[n].private11.key = "keys_skel";
	locations[n].private11.items.icollection = 100;
	
	locations[n].private12.key = "keys_skel";
	locations[n].private12.items.icollection = 100;
	
	locations[n].private13.key = "keys_skel";
	locations[n].private13.items.icollection = 10;
	locations[n].private13.items.jewelry22 = 2000;
	
	locations[n].private14.key = "keys_skel";
	locations[n].private14.items.icollection = 10;
	locations[n].private14.items.jewelry8 = 1000;
	
	locations[n].private15.key = "keys_skel";
	locations[n].private15.items.icollection = 10;
	locations[n].private15.items.jewelry9 = 500;
	locations[n].private15.items.jewelry19 = 300;
	
	locations[n].private16.key = "keys_skel";
	locations[n].private16.items.potion2 = 1000;
	locations[n].private16.items.potion3 = 1000;
	locations[n].private16.items.potion4 = 1000;
	locations[n].private16.items.potion7 = 10;
	locations[n].private16.items.berserker_potion = 20;
	
	locations[n].private17.key = "keys_skel";
	locations[n].private17.items.icollection = 100;
	
	locations[n].private18.key = "keys_skel";
	locations[n].private18.items.jewelry5 = 2000;
	
	locations[n].private19.key = "keys_skel";
	locations[n].private19.items.jewelry6 = 4000;
	
	locations[n].private20.key = "keys_skel";
	locations[n].private20.items.icollection = 200;
	locations[n].private20.items.jewelry5 = 5000;
	locations[n].private20.items.jewelry6 = 10000;
	
	locations[n].private21.key = "keys_skel";
	locations[n].private21.items.mushket6 = 1;
	
	locations[n].DisableOfficers = "1";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Затопленный Храм левый
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Templee_Underwater_left_1";
	locations[n].id.label = "TempleUnderwater_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound	
	locations[n].type = "underwater";
	locations[n].changeAnimation = "swim"; //сменить анимацию на плавание
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleUnderwater_1\";
	Locations[n].models.always.Temple = "TempleUnderwater_1";
	//Locations[n].models.always.Temple.tech = "DLightModel";
	Locations[n].models.always.reflect = "TempleUnderwater_1_reflect";
	//Locations[n].models.always.reflect.tech = "DLightModel";
	Locations[n].models.always.reflect.sea_reflection = 1;
	Locations[n].models.always.locators = "TempleUnderwater_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleUnderwater_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleUnderwater_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].underwater = true;
	Locations[n].QuestlockWeather = "Underwater";
	Locations[n].lockWeather = "Inside";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadU2";
	locations[n].reload.l1.autoreload = "1";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Templee_great_1";
	locations[n].reload.l2.emerge = "reload10";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 0.4;
	locations[n].locators_radius.reload.reload2_back = 0.4;
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Теночтитлан Затопленный Храм правый
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Templee_Underwater_right_1";
	locations[n].id.label = "TempleUnderwater_1";
	locations[n].image = "loading\outside\TempleInside_" + rand(1) + ".tga";
	//Sound	
	locations[n].type = "underwater";
	locations[n].changeAnimation = "swim"; //сменить анимацию на плавание
	//Models
	//Always
	Locations[n].filespath.models = "Locations\Gothic\TenochtitlanInside_1\TempleUnderwater_1\";
	Locations[n].models.always.Temple = "TempleUnderwater_1";
	//Locations[n].models.always.Temple.tech = "DLightModel";
	Locations[n].models.always.reflect = "TempleUnderwater_1_reflect";
	//Locations[n].models.always.reflect.tech = "DLightModel";
	Locations[n].models.always.reflect.sea_reflection = 1;
	Locations[n].models.always.locators = "TempleUnderwater_1_locators";	
	//Day
	locations[n].models.day.charactersPatch = "TempleUnderwater_1_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleUnderwater_1_patch";			
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	locations[n].underwater = true;
	Locations[n].QuestlockWeather = "Underwater";
	Locations[n].lockWeather = "Inside";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Tenochtitlan_1";
	locations[n].reload.l1.emerge = "reloadU1";
	locations[n].reload.l1.autoreload = "1";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Templee_great_1";
	locations[n].reload.l2.emerge = "reload9";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 0.4;
	locations[n].locators_radius.reload.reload2_back = 0.4;
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	
	return n;
}
