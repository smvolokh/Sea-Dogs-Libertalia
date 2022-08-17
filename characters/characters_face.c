string	sEnManFaces = "30,35,10,6,32,33,42,43";
string	sFrManFaces = "19,27,29,31,32,33,43,43";
string	sSpManFaces = "25,37,38,44,7,32,33,42,43";
string	sHoManFaces = "11,26,28,36,32,33,42,43";
string	sPoManFaces = "12,30,39,32,33,42,43";
string	sPiManFaces = "0,1,13,14,2,23,24,3,40,5";

void SetRandomFaceToCharacter(ref rCharacter)
{
	string sFaceID = "1";
	if (rCharacter.sex == "man")
	{
		switch (sti(rCharacter.nation))
		{
			case ENGLAND:	
				sFaceID = GetRandSubString(sEnManFaces); 
			break;
			case FRANCE:	
				sFaceID = GetRandSubString(sFrManFaces); 
			break;
			case SPAIN:		
				sFaceID = GetRandSubString(sSpManFaces); 
				break;
			case PIRATE:	
				sFaceID = GetRandSubString(sPiManFaces); 
				break;
			case HOLLAND:	
				sFaceID = GetRandSubString(sHoManFaces); 
				break;
		}
	}
	else
	{
		sFaceID = "16";
	}
	
	rCharacter.FaceId = sti(sFaceID);
}

void FaceMaker(aref rCharacter)
{
	// Warship 07.07.09 Пасхалка с кораблем "Мэри Селест" - за место лица кэпа - море с облаками
	if(rCharacter.ID == "MaryCelesteCapitan")
	{
		rCharacter.FaceId = 333;
		return;
	}
	if (findsubstr(rCharacter.model, "banker", 0) != -1)
	{
		rCharacter.FaceId = 1;
		return;
	}
	if (findsubstr(rCharacter.model, "gipsy", 0) != -1)
	{
		rCharacter.FaceId = 2;
		return;
	}
	if (findsubstr(rCharacter.ID, "_Lightman", 0) != -1)
	{
		rCharacter.FaceId = 3;
		return;
	}

	switch (rCharacter.model)
	{
		case "beatrice":		rCharacter.FaceId = 0; break;
		case "beatriceA":		rCharacter.FaceId = 0; break;
		//case "devlin":			rCharacter.FaceId = 1; break;

		//case "barmen_1":		rCharacter.FaceId = 2; break;
		//case "barmen_2":		rCharacter.FaceId = 3; break;
		case "barmen_3":		rCharacter.FaceId = 4; break;
		case "HeadManPearl"	:		rCharacter.FaceId = 403; 	break;
		
		// --> ККС
		// французские офицеры
		case "off_fra_1"	:		rCharacter.FaceId = 5; 		break;
		case "off_fra_2"	:		rCharacter.FaceId = 6; 		break;
		case "off_fra_3"	:		rCharacter.FaceId = 7; 		break;
		case "off_fra_4"	:		rCharacter.FaceId = 8; 		break;
		case "off_fra_5"	:		rCharacter.FaceId = 9; 		break;
		case "off_fra_6"	:		rCharacter.FaceId = 10; 	break;
		// английские офицеры
		case "off_eng_1"	:		rCharacter.FaceId = 11; 	break;
		case "off_eng_2"	:		rCharacter.FaceId = 12; 	break;
		case "off_eng_3"	:		rCharacter.FaceId = 13; 	break;
		case "off_eng_4"	:		rCharacter.FaceId = 14; 	break;
		case "off_eng_5"	:		rCharacter.FaceId = 15; 	break;
		case "off_eng_6"	:		rCharacter.FaceId = 16; 	break;
		// голландские офицеры
		case "off_hol_1"	:		rCharacter.FaceId = 17; 	break;
		case "off_hol_2"	:		rCharacter.FaceId = 18; 	break;
		case "off_hol_3"	:		rCharacter.FaceId = 19; 	break;
		case "off_hol_4"	:		rCharacter.FaceId = 20; 	break;
		case "off_hol_5"	:		rCharacter.FaceId = 21; 	break;
		case "off_hol_6"	:		rCharacter.FaceId = 22; 	break;
		// испанские офицеры
		case "off_spa_1"	:		rCharacter.FaceId = 23; 	break;
		case "off_spa_2"	:		rCharacter.FaceId = 24; 	break;
		case "off_spa_3"	:		rCharacter.FaceId = 25; 	break;
		case "off_spa_4"	:		rCharacter.FaceId = 26; 	break;
		case "off_spa_5"	:		rCharacter.FaceId = 27; 	break;
		case "off_spa_6"	:		rCharacter.FaceId = 28; 	break;
		// наемники-контрактники,  торговые капитаны
		case "mercen_1"		: 		rCharacter.FaceId = 29;		break;
		case "mercen_2"		: 		rCharacter.FaceId = 30;		break;
		case "mercen_3"		: 		rCharacter.FaceId = 31;		break;
		case "mercen_4"		: 		rCharacter.FaceId = 32;		break;
		case "mercen_5"		: 		rCharacter.FaceId = 33;		break;
		case "mercen_6"		: 		rCharacter.FaceId = 34;		break;
		case "mercen_7"		: 		rCharacter.FaceId = 35;		break;
		case "mercen_8"		: 		rCharacter.FaceId = 36;		break;
		case "mercen_9"		: 		rCharacter.FaceId = 37;		break;
		case "mercen_10"	: 		rCharacter.FaceId = 38;		break;
		case "mercen_11"	: 		rCharacter.FaceId = 39;		break;
		case "mercen_12"	: 		rCharacter.FaceId = 40;		break;
		case "mercen_13"	: 		rCharacter.FaceId = 41;		break;
		case "mercen_14"	: 		rCharacter.FaceId = 42;		break;
		case "mercen_15"	: 		rCharacter.FaceId = 43;		break;
		// наёмники-компаньоны,  пиратские капитаны
		case "mercen_16"	: 		rCharacter.FaceId = 44;		break;
		case "mercen_17"	: 		rCharacter.FaceId = 45;		break;
		case "mercen_18"	: 		rCharacter.FaceId = 806;		break;
		case "mercen_19"	: 		rCharacter.FaceId = 47;		break;
		case "mercen_20"	: 		rCharacter.FaceId = 48;		break;
		case "mercen_21"	: 		rCharacter.FaceId = 49;		break;
		case "mercen_22"	: 		rCharacter.FaceId = 50;		break;
		case "mercen_23"	: 		rCharacter.FaceId = 51;		break;
		case "mercen_24"	: 		rCharacter.FaceId = 52;		break;
		case "mercen_25"	: 		rCharacter.FaceId = 53;		break;
		case "mercen_26"	: 		rCharacter.FaceId = 810;		break;
		case "mercen_27"	: 		rCharacter.FaceId = 55;		break;
		case "mercen_28"	: 		rCharacter.FaceId = 56;		break;
		case "mercen_29"	: 		rCharacter.FaceId = 823;		break;
		// гражданское население
		// дворяне
		case "citiz_1"		:		rCharacter.FaceId = 61; 	break;
		case "citiz_2"		:		rCharacter.FaceId = 62; 	break;
		case "citiz_3"		:		rCharacter.FaceId = 63; 	break;
		case "citiz_4"		:		rCharacter.FaceId = 64; 	break;
		case "citiz_5"		:		rCharacter.FaceId = 65; 	break;
		case "citiz_6"		:		rCharacter.FaceId = 66; 	break;
		case "citiz_7"		:		rCharacter.FaceId = 67; 	break;
		case "citiz_8"		:		rCharacter.FaceId = 68; 	break;
		case "citiz_9"		:		rCharacter.FaceId = 69; 	break;
		case "citiz_10"		:		rCharacter.FaceId = 70; 	break;
		// бюргеры
		case "citiz_11"		:		rCharacter.FaceId = 71; 	break;
		case "citiz_12"		:		rCharacter.FaceId = 72; 	break;
		case "citiz_13"		:		rCharacter.FaceId = 73; 	break;
		case "citiz_14"		:		rCharacter.FaceId = 74; 	break;
		case "citiz_15"		:		rCharacter.FaceId = 75; 	break;
		case "citiz_16"		:		rCharacter.FaceId = 76; 	break;
		case "citiz_17"		:		rCharacter.FaceId = 77; 	break;
		case "citiz_18"		:		rCharacter.FaceId = 78; 	break;
		case "citiz_19"		:		rCharacter.FaceId = 79; 	break;
		case "citiz_20"		:		rCharacter.FaceId = 80; 	break;
		// простолюдины (контрики)
		case "citiz_21"		:		rCharacter.FaceId = 81; 	break;
		case "citiz_22"		:		rCharacter.FaceId = 82; 	break;
		case "citiz_23"		:		rCharacter.FaceId = 83; 	break;
		case "citiz_24"		:		rCharacter.FaceId = 84; 	break;
		case "citiz_25"		:		rCharacter.FaceId = 85; 	break;
		case "citiz_26"		:		rCharacter.FaceId = 86; 	break;
		case "citiz_27"		:		rCharacter.FaceId = 87; 	break;
		case "citiz_28"		:		rCharacter.FaceId = 965; 	break;
		case "citiz_29"		:		rCharacter.FaceId = 89; 	break;
		case "citiz_30"		:		rCharacter.FaceId = 90; 	break;
		case "mush_ctz_1"	:		rCharacter.FaceId = 81; 	break;
		case "mush_ctz_2"	:		rCharacter.FaceId = 83; 	break;
		case "mush_ctz_3"	:		rCharacter.FaceId = 84; 	break;
		// матросы
		case "citiz_31"		:		rCharacter.FaceId = 91; 	break;
		case "citiz_32"		:		rCharacter.FaceId = 92; 	break;
		case "citiz_33"		:		rCharacter.FaceId = 93; 	break;
		case "citiz_34"		:		rCharacter.FaceId = 94; 	break;
		case "citiz_35"		:		rCharacter.FaceId = 95; 	break;
		case "citiz_36"		:		rCharacter.FaceId = 96; 	break;
		case "citiz_37"		:		rCharacter.FaceId = 97; 	break;
		case "citiz_38"		:		rCharacter.FaceId = 98; 	break;
		case "citiz_39"		:		rCharacter.FaceId = 99; 	break;
		case "citiz_40"		:		rCharacter.FaceId = 100; 	break;
		case "mush_ctz_4"	:		rCharacter.FaceId = 91; 	break;
		case "mush_ctz_5"	:		rCharacter.FaceId = 92; 	break;
		case "mush_ctz_6"	:		rCharacter.FaceId = 98; 	break;
		// пираты
		case "citiz_41"		:		rCharacter.FaceId = 101; 	break;
		case "citiz_42"		:		rCharacter.FaceId = 102; 	break;
		case "citiz_43"		:		rCharacter.FaceId = 103; 	break;
		case "citiz_44"		:		rCharacter.FaceId = 104; 	break;
		case "citiz_45"		:		rCharacter.FaceId = 105; 	break;
		case "citiz_46"		:		rCharacter.FaceId = 106; 	break;
		case "citiz_47"		:		rCharacter.FaceId = 107; 	break;
		case "citiz_48"		:		rCharacter.FaceId = 108; 	break;
		case "citiz_49"		:		rCharacter.FaceId = 109; 	break;
		case "citiz_50"		:		rCharacter.FaceId = 110; 	break;
		case "mush_ctz_7"	:		rCharacter.FaceId = 107; 	break;
		case "mush_ctz_8"	:		rCharacter.FaceId = 102; 	break;
		case "mush_ctz_9"	:		rCharacter.FaceId = 38; 	break;
		// ОЗК и Нарвалы
		case "citiz_51"		:		rCharacter.FaceId = 111; 	break;
		case "citiz_52"		:		rCharacter.FaceId = 112; 	break;
		case "citiz_53"		:		rCharacter.FaceId = 113; 	break;
		case "citiz_54"		:		rCharacter.FaceId = 114; 	break;
		case "citiz_55"		:		rCharacter.FaceId = 115; 	break;
		case "citiz_56"		:		rCharacter.FaceId = 116; 	break;
		case "citiz_57"		:		rCharacter.FaceId = 117; 	break;
		case "citiz_58"		:		rCharacter.FaceId = 118; 	break;
		case "citiz_59"		:		rCharacter.FaceId = 119; 	break;
		case "citiz_60"		:		rCharacter.FaceId = 120; 	break;	
		case "mush_ctz_10"	:		rCharacter.FaceId = 403; 	break;
		case "mush_ctz_11"	:		rCharacter.FaceId = 114; 	break;
		case "mush_ctz_12"	:		rCharacter.FaceId = 113; 	break;	
		// заключенные
		case "prizon_1"		:		rCharacter.FaceId = 137; 	break;		
		case "prizon_2"		:		rCharacter.FaceId = 138; 	break;		
		case "prizon_3"		:		rCharacter.FaceId = 139; 	break;		
		case "prizon_4"		:		rCharacter.FaceId = 140; 	break;		
		case "prizon_5"		:		rCharacter.FaceId = 141; 	break;		
		case "prizon_6"		:		rCharacter.FaceId = 142; 	break;		
		case "prizon_7"		:		rCharacter.FaceId = 143; 	break;		
		case "prizon_8"		:		rCharacter.FaceId = 144; 	break;		
		// дворянки
		case "women_1"		:		rCharacter.FaceId = 151; 	break;
		case "women_2"		:		rCharacter.FaceId = 152; 	break;
		case "women_3"		:		rCharacter.FaceId = 153; 	break;
		case "women_4"		:		rCharacter.FaceId = 154; 	break;
		case "women_5"		:		rCharacter.FaceId = 155; 	break;
		case "women_6"		:		rCharacter.FaceId = 156; 	break;
		// горожанки условно замужние
		case "women_7"		:		rCharacter.FaceId = 157; 	break;
		case "women_8"		:		rCharacter.FaceId = 158; 	break;
		case "women_9"		:		rCharacter.FaceId = 159; 	break;
		case "women_10"		:		rCharacter.FaceId = 160; 	break;
		// горожанки условно незамужние
		case "women_11"		:		rCharacter.FaceId = 161; 	break;
		case "women_12"		:		rCharacter.FaceId = 162; 	break;
		case "women_13"		:		rCharacter.FaceId = 163; 	break;
		case "women_14"		:		rCharacter.FaceId = 164; 	break;
		case "women_15"		:		rCharacter.FaceId = 165; 	break;
		case "women_16"		:		rCharacter.FaceId = 166; 	break;
		// старухи
		case "women_17"		:		rCharacter.FaceId = 167; 	break;
		case "women_18"		:		rCharacter.FaceId = 168; 	break;
		// шлюхи
		case "women_19"		:		rCharacter.FaceId = 169; 	break;
		case "women_20"		:		rCharacter.FaceId = 170; 	break;
		case "women_21"		:		rCharacter.FaceId = 171; 	break;
		case "women_22"		:		rCharacter.FaceId = 172; 	break;
		case "women_23"		:		rCharacter.FaceId = 173; 	break;
		case "women_24"		:		rCharacter.FaceId = 174; 	break;
		case "women_25"		:		rCharacter.FaceId = 175; 	break;
		case "women_26"		:		rCharacter.FaceId = 176; 	break;
		// монахи
		case "monk_1"		:		rCharacter.FaceId = 194; 	break;
		case "monk_2"		:		rCharacter.FaceId = 195; 	break;
		case "monk_3"		:		rCharacter.FaceId = 196; 	break;
		case "monk_4"		:		rCharacter.FaceId = 197; 	break;
		case "monk_5"		:		rCharacter.FaceId = 198; 	break;
		case "monk_6"		:		rCharacter.FaceId = 199; 	break;	

		// квестовые персонажи			
		// союзники Главных Героев
		case "Migel_2"		:     	rCharacter.FaceId = 204; 	break;		// Мигель Дичозо
		case "Maskog"		:     	rCharacter.FaceId = 205; 	break;		// Тиничгиту
		case "Maskog_mush"	:     	rCharacter.FaceId = 205; 	break;		// Тиничгиту - модель мушкетера		
		case "Archy"		:		rCharacter.FaceId = 206; 	break;		// Арчибальд Колкхаун
		case "Archy_mush"	:		rCharacter.FaceId = 206; 	break;		// Арчибальд Колкхаун - модель мушкетера		
		case "Alonso"		:		rCharacter.FaceId = 207; 	break;		// Алонсо де Мальдонадо
		case "Alonso_mush"	:		rCharacter.FaceId = 207; 	break;		// Алонсо де Мальдонадо - модель мушкетера
		
		// Пиратские бароны
		case "Jeckman"		:		rCharacter.FaceId = 208; 	break;		// Якоб Джекман
		case "Hawk_1"		:		rCharacter.FaceId = 209;	break;		// Натаниель Хоук
		case "Hawk_2"		:		rCharacter.FaceId = 209;	break;		// Натаниель Хоук
		case "Marlow"		:		rCharacter.FaceId = 210;	break;		// Захария Марлоу
		case "Terrax"		:		rCharacter.FaceId = 211;	break;		// Маркус Тиракс
		case "Barbazon"		:		rCharacter.FaceId = 212;	break;		// Жак Барбазон
		case "Svenson"		:		rCharacter.FaceId = 213;	break;		// Ян Свенсон
		
		// мультиквест "Голландский Гамбит"
		case "huber_1"		:		rCharacter.FaceId = 214;	break;		// Питер Стайвесант
		case "huber_25"		:		rCharacter.FaceId = 215;	break;		// Матиас Бек
		case "Lucas"		:		rCharacter.FaceId = 216;	break;		// Лукас Роденбург
		case "Fleetwood"	: 		rCharacter.FaceId = 217;	break;		// Ричард Флитвуд
		case "Merdok"		: 		rCharacter.FaceId = 218;	break;		// Джон Мердок
		case "VanBerg"		: 		rCharacter.FaceId = 219;	break;		// Якоб Ван Берг
		case "Longway"		: 		rCharacter.FaceId = 220;	break;		// Лонгвэй
		case "Gaston"		: 		rCharacter.FaceId = 221;	break;		// Плешивый Гастон
		case "Tonzag"		: 		rCharacter.FaceId = 221;	break;		// Эркюль Тонзаг
		case "Kneepel"		: 		rCharacter.FaceId = 222;	break;		// Чарли Книппель
		case "Meriman_1"	: 		rCharacter.FaceId = 223;	break;		// Жоаким Мериман
		case "Meriman_2"	: 		rCharacter.FaceId = 223;	break;		// Жоаким Мериман
		case "Solomon"      :		rCharacter.FaceId = 224;	break;		// Соломон Шнеур
		case "Aby"      	:		rCharacter.FaceId = 225;	break;		// Абигайль Шнеур		
		case "Rodriges"		: 		rCharacter.FaceId = 286;	break;		// Фернандо Родригес
		
		// квест "Долгий путь к виселице"
		case "Gino"			: 		rCharacter.FaceId = 226;	break;		// Джино Гвинейли
		case "Port_A"		: 		rCharacter.FaceId = 227;	break;		// Барт Португалец
		case "Port_B"		: 		rCharacter.FaceId = 227;	break;		// Барт Португалец
		case "Hugh"			: 		rCharacter.FaceId = 228;	break;		// Хьюго Авенделл
		case "VanShtal"		: 		rCharacter.FaceId = 229;	break;		// Питер Ван Шталь
		case "Vasces"		: 		rCharacter.FaceId = 230;	break;		// Эрнандо Васкес
		
		// Ица
		case "Itza_Kanek"	: 		rCharacter.FaceId = 231;	break;		// Канек - верховный жрец ица
		case "Itza_Urakan"	: 		rCharacter.FaceId = 232;	break;		// Уракан - военный вождь ица
		case "Itza_1"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_2"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_3"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_4"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_5"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_6"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_7"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "Itza_8"		: 		rCharacter.FaceId = 994;	break;		// воин ица
		case "mush_Itza_1"	: 		rCharacter.FaceId = 994;	break;		// мушкетёр ица
		case "mush_Itza_2"	: 		rCharacter.FaceId = 994;	break;		// мушкетёр ица
		case "mush_Itza_3"	: 		rCharacter.FaceId = 994;	break;		// мушкетёр ица

		// Ацтеки
	case "Aztec"			: 		rCharacter.FaceId = 994;	break;		// Монтесума
	case "AztecCitizen1"		: 		rCharacter.FaceId = 994;	break;		// Мешитли 
	case "AztecCitizen2"		: 		rCharacter.FaceId = 994;	break;		// Аутисоль
	case "AztecWarrior1"		: 		rCharacter.FaceId = 994;	break;		// ацтекский воин 
	case "AztecWarrior2"		: 		rCharacter.FaceId = 994;	break;		// ацтекский воин 
	case "AztecWarrior3"		: 		rCharacter.FaceId = 994;	break;		// ацтекский воин 
	case "AztecWarrior4"		: 		rCharacter.FaceId = 994;	break;		// ацтекский воин 
	case "AztecWarrior5"		: 		rCharacter.FaceId = 994;	break;		// ацтекский воин 

		// Ирокезы "капонги"
	case "Iroquois_1"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_2"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_3"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_4"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_5"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_6"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_7"		: 		rCharacter.FaceId = 995;	break; // воин
	case "Iroquois_8"		: 		rCharacter.FaceId = 995;	break; // воин
	case "mush_iroquois_1"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_2"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_3"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_4"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_5"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_6"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_7"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	case "mush_iroquois_8"	: 		rCharacter.FaceId = 995;	break; // мушкетёр
	
		
		// Макроквест
		case "DeLuck"		:		rCharacter.FaceId = 947;	break;		// Алехандро Пистолето
		case "Mendosa"		:		rCharacter.FaceId = 233;	break;		// Дон Рамон де Мендоса-и-Риба
		case "Vincento"		:		rCharacter.FaceId = 234;	break;		// Отец Винсенто
		case "Alexus"		:		rCharacter.FaceId = 235;	break;		// Мастер Алексус
		case "Shaman"		:		rCharacter.FaceId = 236;	break;		// Змеиный Глаз
		case "Moscovit"		:		rCharacter.FaceId = 237;	break;		// Фадей Московит
		case "Shark"		:		rCharacter.FaceId = 238;	break;		// Акула Додсон		
		case "Abbat"		:		rCharacter.FaceId = 239;	break;		// Аббат Бенуа
		case "Tomazo"		:		rCharacter.FaceId = 240;	break;		// Томазо
		case "Kumvana"		:		rCharacter.FaceId = 241;	break;		//  Кумвана (вождь мискито)
		case "Zikomo"		:		rCharacter.FaceId = 242;	break;		// Нгомбо Зикомо (жрец канибов)
		case "Canib"		:		rCharacter.FaceId = 243;	break;		// Монкитекуври (вождь канибов)
		case "Fox"			:		rCharacter.FaceId = 244;	break;		// полковник Фокс
		
		// Пиратская Сага+LSC
		case "Balthrop"		:		rCharacter.FaceId = 249;	break;		// Лоуренс Бэлтроп
		case "Rumba"		:		rCharacter.FaceId = 250;	break;		// Элиза МакАртур
		case "Eliza_0"		:		rCharacter.FaceId = 250;	break;		// Элиза МакАртур

		case "Gladys"		:		rCharacter.FaceId = 251;	break;		//  Глэдис МакАртур
		case "Donovan"		:		rCharacter.FaceId = 252;	break;		// Артур Донован
		case "Danny"		:		rCharacter.FaceId = 253;	break;		// Даниэль Хоук
		case "keeper_1"		:		rCharacter.FaceId = 254;	break;		// Альварес Ортего
		case "Norman_1"		:		rCharacter.FaceId = 255;	break;		// Абрахам Норман
		case "Norman_2"		:		rCharacter.FaceId = 255;	break;		// Абрахам Норман
		case "Baker"		:		rCharacter.FaceId = 256;	break;		// Раймонд Бейкер
		case "Ghost_1"		:		rCharacter.FaceId = 259;	break;		// Джессика (нежить)
		case "Black"		:		rCharacter.FaceId = 260;	break;		// Эдди Блэк
		case "Carpentero"	:		rCharacter.FaceId = 262;	break;		// Санчо Карпентеро
		case "Mechanic"		:		rCharacter.FaceId = 263;	break;		// Хенрик Ведекер
		case "Schmidt"		:		rCharacter.FaceId = 264;	break;		// Юрген Шмидт
		case "Ole"			:		rCharacter.FaceId = 265;	break;		// Оле Кристиансен (Белый мальчик)
		case "Chimiset"		:		rCharacter.FaceId = 266;	break;		// Чимисет
		case "Mary"			:		rCharacter.FaceId = 267;	break;		// Мэри Каспер
		case "Axel"			:		rCharacter.FaceId = 268;	break;		// Аксель Йост
		case "Dios"			:		rCharacter.FaceId = 269;	break;		// Хосе Диос
		case "Vensan"		:		rCharacter.FaceId = 270;	break;		// Бернар Венсан
		case "Rat"			:		rCharacter.FaceId = 271;	break;		// Поль Моллиган
		case "Molligan"		:		rCharacter.FaceId = 283;	break;		// Поль Моллиган
		case "Rozencraft"	:		rCharacter.FaceId = 288;	break;		// Михаэль Розенкрафт
		case "Valet"	:		rCharacter.FaceId = 275;	break;		// Давид Валет Факман
		
		// суп из черепахи
		case "Marten"		:		rCharacter.FaceId = 272;	break;		// Робер Мартэн
		case "Tibo"			:		rCharacter.FaceId = 273;	break;		// Анри Тибо
		case "Catherine"	:		rCharacter.FaceId = 274;	break;		// Катя Фокс
		
		// Страж Истины
		case "q_spa_off_1"	:		rCharacter.FaceId = 285;	break;		// пленный испанец
		case "q_spa_off_2"	:		rCharacter.FaceId = 285;	break;		// освобожденный испанец
		case "GayMarshe"	:		rCharacter.FaceId = 148;	break;		// Гай Марше
		
		// калеуче
		case "skeletcap" 	:		rCharacter.FaceId = 556;	break;		// капитан Калеуче
		case "Chavinavi_1" 	:		rCharacter.FaceId = 961;	break;		// Чавинави
		
		// прочие квесты
		case "AdamRainer" 	:		rCharacter.FaceId = 145;	break;		// Адам Рейнер
		case "CatRainer" 	:		rCharacter.FaceId = 147;	break;		// Катерина Рейнер
		case "q_eng_Cap_1" 	:		rCharacter.FaceId = 146;	break;		// капитан галеона
		case "HuanTubercul" :		rCharacter.FaceId = 150;	break;		// Хуан Чахотка
		case "Gontier" 		:		rCharacter.FaceId = 284;	break;		// Франсуа Гонтьер
		case "Doggerty" 	:		rCharacter.FaceId = 287;	break;		// Вудро Доггерти
		
		// // Addon-2016 Jason, французские миниквесты (ФМК)
		case "q_citizen_1" 	:		rCharacter.FaceId = 75;		break;		// Бертран Пинетт
		case "quest_off_eng":		rCharacter.FaceId = 304;	break;		// Каспар Грэттон
		case "quest_off_holl" :		rCharacter.FaceId = 19;		break;		// Каспар Грэттон
		case "quest_off_franc":		rCharacter.FaceId = 302;	break;		// Жан Дено
		case "quest_off_spain":		rCharacter.FaceId = 303; 	break;		// Хуан Дено
		case "Guide_1":				rCharacter.FaceId = 305; 	break;		// Грегуар Валинье
		case "Spain_Major":			rCharacter.FaceId = 306; 	break;		// Доминго Альбалате
		case "Levaser_Wife":		rCharacter.FaceId = 307; 	break;		// Марселина Левассер
		case "quest_pirat_1":		rCharacter.FaceId = 301; 	break;		// Хорхе Ортего-Хамон
		case "quest_pirat_2":		rCharacter.FaceId = 308; 	break;		// Сильвестр Маккой
		case "Prospero_mush":		rCharacter.FaceId = 278; 	break;		// Проспер Трубаль // may-16
		case "Kain":		rCharacter.FaceId = 856; 	break;		// Клод Дюран // may-16

		// Addon 2016-1 Jason Пиратская линейка
		case "Billy_Pirt" 	:		rCharacter.FaceId = 310		break;		// Билли Пирт
		case "Jan_Slave"	:		rCharacter.FaceId = 311;	break;		// Жан Пикар
		case "Jan_Pikar"	:		rCharacter.FaceId = 311;	break;		// Жан Пикар
		case "Jeffry"		:		rCharacter.FaceId = 312;	break;		// Джеффри Брук
		case "Tesak"		:		rCharacter.FaceId = 313;	break;		// Пол Чант
		case "Leprechaun"	:		rCharacter.FaceId = 314; 	break;		// Люка Байярд
		case "Mirabelle"	:		rCharacter.FaceId = 316; 	break;		// Мирабель
		case "Marco"		:		rCharacter.FaceId = 317; 	break;		// Игнасио Марко
		case "Enrique":		                rCharacter.FaceId = 441; 	break;		// дон Энрико // may-16
		case "Enrique_1":		        rCharacter.FaceId = 441; 	break;		// дон Энрико // may-16
		case "Enrique_Mush":	                rCharacter.FaceId = 441; 	break;		// дон Энрико // may-16

		// Jason НСО
		case "Boss_1"	 	:		rCharacter.FaceId = 331;	break;		// инспектор Ноэль Форже
		case "Off_Fra_Z"	:		rCharacter.FaceId = 332;	break;		// капитан Эклятона
		case "huber_9"		:		rCharacter.FaceId = 333;	break;		// Дойли
		case "Fox"			:		rCharacter.FaceId = 244;	break;		// Фокс
		case "Boss_2"		:		rCharacter.FaceId = 334;	break;		// начальник рудника

		// Пират Либерталии LH

	case "Baronet_1"	 	:		rCharacter.FaceId = 337;	break;		// баронет Уильям Кортни
	case "Baronet_2"	 	:		rCharacter.FaceId = 337;	break;		// баронет Уильям Кортни
		case "Marquesa"	:		rCharacter.FaceId = 338;	break;		// маркиза Джулиана Бото
		case "Angerran"		:	rCharacter.FaceId = 339;	break;		// Ангерран де Шиво
		// <-- ККС
		
	// Пират Либерталии Губернаторы
		case "huber_27"		:		rCharacter.FaceId = 1000;	break;	// Мартин Томас голландский губер Филипсбурга
	case "Huber_Hol_Fort"		:		rCharacter.FaceId = 970;	break; // Баудевейн Хендрикс голландский губер Форт Оранж
		case "huber_4"		:		rCharacter.FaceId = 8;	break;	// Жак Дил ду Парке губер Форт де Франс
		case "huber_8"		:		rCharacter.FaceId = 7;	break;	// Жереми Дешамп дю Мюссак губер Порт-о-Пренс
		case "huber_5"		:		rCharacter.FaceId = 246;	break;	// Клод Франсуа де Лион губер Бас-Тер
		case "huber_7"		:		rCharacter.FaceId = 247;	break;	// шевалье Тимолеон де Фонтене губер Тортуги
	case "Huber_Capster"		:		rCharacter.FaceId = 1001;	break;	// Бертран д'Ожерон губер Капстервиля
	case "Huber_Philip"		:		rCharacter.FaceId = 1002;	break; // Кристиан Бюиссон французский губер Филипсбурга
case "Hagen"		:		rCharacter.FaceId = 1003;	break; // Лорд Хаген французский губер Санто-Доминго

		case "officer_6":		rCharacter.FaceId = 806; break;
		case "officer_7":		rCharacter.FaceId = 812; break;
		case "officer_8":		rCharacter.FaceId = 823; break;
		case "officer_9":		rCharacter.FaceId = 814; break;
		case "officer_10":		rCharacter.FaceId = 815; break;
		case "officer_11":		rCharacter.FaceId = 816; break;
		case "officer_4":		rCharacter.FaceId = 809; break;
		
		//--> временно переименованные
		case "Espinosa":		rCharacter.FaceId = 414; break;
		case "Hero1":			rCharacter.FaceId = 415; break;
		case "Isterling":		rCharacter.FaceId = 416; break;
		case "Morgan":			rCharacter.FaceId = 417; break;
		case "SpaOfficer1":		rCharacter.FaceId = 418; break;
		case "SpaOfficer2":		rCharacter.FaceId = 419; break;
		case "Youngman":		rCharacter.FaceId = 420; break;
		case "Blood5":			rCharacter.FaceId = 421; break;
		case "blood_bomj":		rCharacter.FaceId = 421; break;
		case "Mechanic":		rCharacter.FaceId = 422; break;
		case "capitan_2":		rCharacter.FaceId = 423; break;
		case "capitan_3":		rCharacter.FaceId = 424; break;
		case "MusketeerEnglish_1":		rCharacter.FaceId = 425; break;
		case "MusketeerEnglish_2":		rCharacter.FaceId = 425; break;
		
		case "officer_12":		rCharacter.FaceId = 817; break;
		case "officer_13":		rCharacter.FaceId = 818; break;
		case "officer_14":		rCharacter.FaceId = 819; break;
		case "officer_15":		rCharacter.FaceId = 820; break;
		case "officer_16":		rCharacter.FaceId = 821; break;
		case "officer_17":		rCharacter.FaceId = 812; break;
		case "officer_18":		rCharacter.FaceId = 823; break;
		case "officer_19":		rCharacter.FaceId = 336; break;
		case "officer_20":		rCharacter.FaceId = 825; break;
		case "Jacob_Help":		rCharacter.FaceId = 957; break;
		case "Rober_Sur":		rCharacter.FaceId = 964; break;
		case "Eivory":		rCharacter.FaceId = 973; break;
		case "Orry":		rCharacter.FaceId = 974; break;
	case "Andre_Abel":		rCharacter.FaceId = 975; break;
		case "Duge":		rCharacter.FaceId = 976; break;

		case "Albermal":		rCharacter.FaceId = 958; break;
		case "Sailhard":		rCharacter.FaceId = 959; break;
		case "Diplomate":	rCharacter.FaceId = 960; break;

		case "girl_1":		rCharacter.FaceId = 350; break;
		case "girl_2":		rCharacter.FaceId = 351; break;
		case "girl_3":		rCharacter.FaceId = 352; break;
		case "girl_4":		rCharacter.FaceId = 353; break;
		case "girl_5":		rCharacter.FaceId = 354; break;
		case "girl_6":		rCharacter.FaceId = 355; break;
		case "girl_7":		rCharacter.FaceId = 356; break;
		case "girl_8":		rCharacter.FaceId = 357; break;
		case "head_pir":		rCharacter.FaceId = 358; break;
		//<-- временно переименованные
		
		case "huber_eng":		rCharacter.FaceId = 59; break;
		case "huber_fra":		rCharacter.FaceId = 60; break;
		
		//--> временно переименованные
		case "huber_spa":		rCharacter.FaceId = 361; break;
		case "huber_hol":		rCharacter.FaceId = 362; break;
		case "lady_1":		rCharacter.FaceId = 363; break;
		case "lady_2":		rCharacter.FaceId = 364; break;
		case "lady_3":		rCharacter.FaceId = 365; break;
		case "lady_4":		rCharacter.FaceId = 366; break;
		case "lady_5":		rCharacter.FaceId = 367; break;
		case "lady_6":		rCharacter.FaceId = 368; break;


		case "pirate_1":		rCharacter.FaceId = 377; break;
		case "pirate_2":		rCharacter.FaceId = 378; break;
		case "pirate_3":		rCharacter.FaceId = 379; break;
		case "pirate_4":		rCharacter.FaceId = 380; break;
		case "pirate_5":		rCharacter.FaceId = 381; break;
		case "pirate_6":		rCharacter.FaceId = 382; break;
		case "pirate_7":		rCharacter.FaceId = 383; break;
		case "pirate_8":		rCharacter.FaceId = 384; break;
		case "pirate_9":		rCharacter.FaceId = 385; break;
		case "pirate_10":		rCharacter.FaceId = 386; break;
		case "priest_1":		rCharacter.FaceId = 387; break;
		case "priest_2":		rCharacter.FaceId = 388; break;
		case "priest_3":		rCharacter.FaceId = 389; break;
		case "priest_4":		rCharacter.FaceId = 390; break;
		case "shipowner_1":		rCharacter.FaceId = 491; break;
		case "shipowner_2":		rCharacter.FaceId = 492; break;
		case "shipowner_3":		rCharacter.FaceId = 493; break;
		case "shipowner_4":		rCharacter.FaceId = 494; break;
		case "shipowner_5":		rCharacter.FaceId = 495; break;
		case "shipowner_6":		rCharacter.FaceId = 496; break;
		case "shipowner_7":		rCharacter.FaceId = 497; break;
		case "shipowner_8":		rCharacter.FaceId = 498; break;
		case "shipowner_9":		rCharacter.FaceId = 499; break;
		case "shipowner_10":	rCharacter.FaceId = 500; break;
		case "shipowner_11":	rCharacter.FaceId = 501; break;
		case "shipowner_12":	rCharacter.FaceId = 502; break;
		case "shipowner_13":	rCharacter.FaceId = 503; break;
		case "shipowner_14":	rCharacter.FaceId = 504; break;
		case "shipowner_15":	rCharacter.FaceId = 505; break;
		case "shipowner_16":	rCharacter.FaceId = 506; break;
		case "smuggler_boss":	rCharacter.FaceId = 507; break;


	// Пират Либерталии Французские вооруженные силы--> 				case "sold_fra_1"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_2"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_3"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_4"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_5"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_6"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_7"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_8"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_9"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_10"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_11"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_12"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_13"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_14"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_15"	:		rCharacter.FaceId = 996; 	break;
		case "sold_fra_16"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_1"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_2"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_3"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_4"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_5"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_6"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_7"	:		rCharacter.FaceId = 996; 	break;
		case "shturm_fra_8"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_1"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_2"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_3"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_4"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_5"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_6"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_7"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_8"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_1"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_2"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_3"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_4"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_5"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_6"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_7"	:		rCharacter.FaceId = 996; 	break;
		case "guard_fra_8"	:		rCharacter.FaceId = 996; 	break;
		case "Malta_1"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_2"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_3"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_4"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_5"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_6"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_7"	:			rCharacter.FaceId = 996; 	break;
		case "Malta_8"	:			rCharacter.FaceId = 996; 	break;
		case "mush_fra_1"	:		rCharacter.FaceId = 996; 	break;
		case "mush_fra_2"	:		rCharacter.FaceId = 996; 	break;
		case "mush_fra_3"	:		rCharacter.FaceId = 996; 	break;
		case "mush_fra_4"	:		rCharacter.FaceId = 996; 	break;
		case "mush_fra_5"	:		rCharacter.FaceId = 996; 	break;
		case "mush_fra_6"	:		rCharacter.FaceId = 996; 	break;
	case "shturm_mush_fra_1"	:		rCharacter.FaceId = 996; 	break;
	case "shturm_mush_fra_2"	:		rCharacter.FaceId = 996; 	break;
	case "shturm_mush_fra_3"	:		rCharacter.FaceId = 996; 	break;
	case "guard_mush_fra_1"	:		rCharacter.FaceId = 996; 	break;
	case "guard_mush_fra_2"	:		rCharacter.FaceId = 996; 	break;
	case "guard_mush_fra_3"	:		rCharacter.FaceId = 996; 	break;
	case "mush_Malta_1"	:			rCharacter.FaceId = 996; 	break;
	case "mush_Malta_2"	:			rCharacter.FaceId = 996; 	break;
	case "mush_Malta_3"	:			rCharacter.FaceId = 996; 	break;
	//<-- Пират Либерталии Французские вооруженные силы 
	// Пират Либерталии Голландские вооруженные силы--> 
		case "sold_hol_1"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_2"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_3"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_4"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_5"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_6"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_7"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_8"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_9"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_10"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_11"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_12"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_13"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_14"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_15"	:		rCharacter.FaceId = 997; 	break;
		case "sold_hol_16"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_1"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_2"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_3"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_4"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_5"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_6"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_7"	:		rCharacter.FaceId = 997; 	break;
		case "shturm_hol_8"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_1"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_2"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_3"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_4"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_5"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_6"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_7"	:		rCharacter.FaceId = 997; 	break;
		case "guard_hol_8"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_1"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_2"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_3"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_4"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_5"	:		rCharacter.FaceId = 997; 	break;
		case "mush_hol_6"	:		rCharacter.FaceId = 997; 	break;
	case "shturm_mush_hol_1"	:		rCharacter.FaceId = 997; 	break;
	case "shturm_mush_hol_2"	:		rCharacter.FaceId = 997; 	break;
	case "shturm_mush_hol_3"	:		rCharacter.FaceId = 997; 	break;
	case "guard_mush_hol_1"	:		rCharacter.FaceId = 997; 	break;
	case "guard_mush_hol_2"	:		rCharacter.FaceId = 997; 	break;
	case "guard_mush_hol_3"	:		rCharacter.FaceId = 997; 	break;
	//<-- Пират Либерталии Голландские вооруженные силы
	// Пират Либерталии Английские вооруженные силы--> 
		case "sold_eng_1"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_2"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_3"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_4"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_5"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_6"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_7"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_8"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_9"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_10"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_11"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_12"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_13"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_14"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_15"	:		rCharacter.FaceId = 998; 	break;
		case "sold_eng_16"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_1"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_2"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_3"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_4"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_5"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_6"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_7"	:		rCharacter.FaceId = 998; 	break;
		case "shturm_eng_8"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_1"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_2"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_3"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_4"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_5"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_6"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_7"	:		rCharacter.FaceId = 998; 	break;
		case "guard_eng_8"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_1"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_2"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_3"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_4"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_5"	:		rCharacter.FaceId = 998; 	break;
		case "mush_eng_6"	:		rCharacter.FaceId = 998; 	break;
	case "shturm_mush_eng_1"	:		rCharacter.FaceId = 998; 	break;
	case "shturm_mush_eng_2"	:		rCharacter.FaceId = 998; 	break;
	case "shturm_mush_eng_3"	:		rCharacter.FaceId = 998; 	break;
	case "guard_mush_eng_1"	:		rCharacter.FaceId = 998; 	break;
	case "guard_mush_eng_2"	:		rCharacter.FaceId = 998; 	break;
	case "guard_mush_eng_3"	:		rCharacter.FaceId = 998; 	break;
	//<-- Пират Либерталии Английские вооруженные силы
	// Пират Либерталии Испанские вооруженные силы--> 
		case "sold_spa_1"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_2"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_3"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_4"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_5"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_6"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_7"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_8"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_9"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_10"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_11"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_12"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_13"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_14"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_15"	:		rCharacter.FaceId = 999; 	break;
		case "sold_spa_16"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_1"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_2"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_3"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_4"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_5"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_6"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_7"	:		rCharacter.FaceId = 999; 	break;
		case "shturm_spa_8"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_1"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_2"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_3"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_4"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_5"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_6"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_7"	:		rCharacter.FaceId = 999; 	break;
		case "guard_spa_8"	:		rCharacter.FaceId = 999; 	break;
		case "Catalan_1"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_2"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_3"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_4"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_5"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_6"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_7"	:			rCharacter.FaceId = 999; 	break;
		case "Catalan_8"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_1"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_2"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_3"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_4"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_5"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_6"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_7"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_8"	:			rCharacter.FaceId = 999; 	break;
		case "Paladin_9"	:			rCharacter.FaceId = 999; 	break;
	case "Paladin_10"	:			rCharacter.FaceId = 999; 	break;
	case "Paladin_11"	:			rCharacter.FaceId = 999; 	break;
case "Paladin_capitan"	:			rCharacter.FaceId = 999; 	break;
	case "Paladin_Gaskon"	:			rCharacter.FaceId = 999; 	break;
case "Paladin_leitinat"	:			rCharacter.FaceId = 999; 	break;
		case "mush_spa_1"	:		rCharacter.FaceId = 999; 	break;
		case "mush_spa_2"	:		rCharacter.FaceId = 999; 	break;
		case "mush_spa_3"	:		rCharacter.FaceId = 999; 	break;
		case "mush_spa_4"	:		rCharacter.FaceId = 999; 	break;
		case "mush_spa_5"	:		rCharacter.FaceId = 999; 	break;
		case "mush_spa_6"	:		rCharacter.FaceId = 999; 	break;
	case "shturm_mush_spa_1"	:		rCharacter.FaceId = 999; 	break;
	case "shturm_mush_spa_2"	:		rCharacter.FaceId = 999; 	break;
	case "shturm_mush_spa_3"	:		rCharacter.FaceId = 999; 	break;
	case "guard_mush_spa_1"	:		rCharacter.FaceId = 999; 	break;
	case "guard_mush_spa_2"	:		rCharacter.FaceId = 999; 	break;
	case "mush_Catalan_1"		:		rCharacter.FaceId = 999; 	break;
	case "mush_Catalan_3"		:		rCharacter.FaceId = 999; 	break;
	case "mush_Catalan_3"		:		rCharacter.FaceId = 999; 	break;
//<-- Пират Либерталии Испанские вооруженные силы
		//<-- временно переименованные
		
		case "trader_1":		rCharacter.FaceId = 121; break;
		case "trader_2":		rCharacter.FaceId = 122; break;
		case "trader_3":		rCharacter.FaceId = 123; break;
		case "trader_4":		rCharacter.FaceId = 124; break;
		case "trader_5":		rCharacter.FaceId = 125; break;
		case "trader_6":		rCharacter.FaceId = 126; break;
		case "trader_7":		rCharacter.FaceId = 127; break;
		case "trader_8":		rCharacter.FaceId = 128; break;
		case "trader_9":		rCharacter.FaceId = 129; break;
		case "trader_10":		rCharacter.FaceId = 130; break;
		case "trader_11":		rCharacter.FaceId = 131; break;
		case "trader_12":		rCharacter.FaceId = 132; break;
		case "trader_13":		rCharacter.FaceId = 133; break;
		case "trader_13_1":		rCharacter.FaceId = 134; break;
		case "trader_14":		rCharacter.FaceId = 135; break;
		case "Pasquale":		rCharacter.FaceId = 136; break; 
		case "trader_15":		rCharacter.FaceId = 131; break;
		case "trader_16":		rCharacter.FaceId = 128; break;
		case "usurer_1":		rCharacter.FaceId = 156; break;
		case "usurer_2": 		rCharacter.FaceId = 157; break;
		case "usurer_3":		rCharacter.FaceId = 158; break;
		case "usurer_4":		rCharacter.FaceId = 159; break;
		case "usurer_5":		rCharacter.FaceId = 160; break;
		case "usurer_6":		rCharacter.FaceId = 161; break;
		case "usurer_7":		rCharacter.FaceId = 162; break;
		case "usurer_8":		rCharacter.FaceId = 163; break;
		case "usurer_9":		rCharacter.FaceId = 1; break;
		case "Diplomat": 	rCharacter.FaceId = 1; break;
		case "whore_1":			rCharacter.FaceId = 164; break;
		case "whore_2":			rCharacter.FaceId = 165; break;
		case "whore_3":			rCharacter.FaceId = 166; break;
		case "whore_4":			rCharacter.FaceId = 167; break;
		// 1.2.3 -->
		case "Daniel":			rCharacter.FaceId = 170; break;
		case "Researcher":		rCharacter.FaceId = 168; break;
		// 1.2.3 <--
		case "mushketer_1":		rCharacter.FaceId = 80; break;
		case "mushketer_2":		rCharacter.FaceId = 77; break;
		case "mushketer_3":		rCharacter.FaceId = 81; break;
		case "mushketer_4":		rCharacter.FaceId = 79; break;
		case "mushketer_5":		rCharacter.FaceId = 78; break;

		case "womens_1"		:		rCharacter.FaceId = 169; 	break;
		case "womens_2"		:		rCharacter.FaceId = 170; 	break;
		case "womens_3"		:		rCharacter.FaceId = 171; 	break;
		case "womens_4"		:		rCharacter.FaceId = 172; 	break;
		case "womens_5"		:		rCharacter.FaceId = 173; 	break;
		case "womens_6"		:		rCharacter.FaceId = 174; 	break;
		case "womens_7"		:		rCharacter.FaceId = 175; 	break;
		case "womens_8"		:		rCharacter.FaceId = 176; 	break;
		
		
		// новые модельки
		case "BigPirate":		rCharacter.FaceId = 210; break;
		case "chard":			rCharacter.FaceId = 211; break;
		case "chard2":			rCharacter.FaceId = 212; break;
		case "chard3":			rCharacter.FaceId = 213; break;
		case "officer_3":		rCharacter.FaceId = 808; break; //Норман Виго

		case "Catcher":		rCharacter.FaceId = 377; break; //Уолтер Катчер


		//ОЗГи
		case "ozg_carlos":		rCharacter.FaceId = 435; break; //Карлос Кассир
		case "ozg_horn":		rCharacter.FaceId = 436; break; //Ганнибал Холм
		case "ozg_piRat":		rCharacter.FaceId = 437; break; //Матиас Грин-Крыса
		case "ozg_miko":		rCharacter.FaceId = 438; break; //Мико Пистольеро
		case "ozg_martin":		rCharacter.FaceId = 439; break; //Мартин ван Хален
		case "QuestCaptain":	        rCharacter.FaceId = 440; break; //Джа Престон
		case "ozg_bonnet1":		rCharacter.FaceId = 441; break; //
		case "BahusCap":		rCharacter.FaceId = 979; break; //



		// Орион
		case "OffOrion":		rCharacter.FaceId = 291; break; //Мартин Блэкер
		// Мушкетеры
		case "quest_mush_1":		rCharacter.FaceId = 292; break; //саксонец
		case "quest_mush_2":		rCharacter.FaceId = 293; break; //пират
		// временное решение для девиц из борделя
		case "horse01": 		rCharacter.FaceId = 164; break;
		case "horse02": 		rCharacter.FaceId = 165; break;
		case "horse03": 		rCharacter.FaceId = 166; break;
		case "horse04": 		rCharacter.FaceId = 167; break;
		case "horse05": 		rCharacter.FaceId = 164; break;
		case "horse06": 		rCharacter.FaceId = 165; break;
		case "horse07": 		rCharacter.FaceId = 166; break;
		case "horse08": 		rCharacter.FaceId = 167; break;
		// CheatSurfMenu by Cheatsurfer -->
		case "Pitt":			rCharacter.FaceId = 710; break; // Джереми Питт
		case "Chard3a":			rCharacter.FaceId = 711; break; // Нед Огл
		// CheatSurfMenu by Cheatsurfer <--

		// новые модельки, забытые старые

		case "Constantino":	rCharacter.FaceId = 128; break;
		case "Researcher":		rCharacter.FaceId = 168; break;
		case "Blad":		rCharacter.FaceId = 203; break;
		case "Aztec":	                  rCharacter.FaceId = 231; break;
		case "Lorensia":		rCharacter.FaceId = 294; break;
		case "Lorensia11":		rCharacter.FaceId = 294; break;
                                     case "Chani":		rCharacter.FaceId = 400; break;
		case "Jack_V":		rCharacter.FaceId = 860; break;
                                     case "BlBorada":		rCharacter.FaceId = 402; break;
case "Tich":		rCharacter.FaceId = 402; break;
		case "JQ_JBallantre":	rCharacter.FaceId = 403; break;
		case "JQ_Robert":		rCharacter.FaceId = 404; break;
		case "Senyan":		rCharacter.FaceId = 405; break;//хитрый пират Сеньян
		case "Milten":		rCharacter.FaceId = 410; break;//Мильтон
		case "Mirrinda":		rCharacter.FaceId = 411; break;
		case "Fenia":		rCharacter.FaceId = 412; break;		
		case "Mirabella":		rCharacter.FaceId = 442; break;
		case "Alligator":		rCharacter.FaceId = 482; break;//Джек Аллигатор
		case "Dexterr":		rCharacter.FaceId = 57; break;//Декстер
		case "Angellica":		rCharacter.FaceId = 707; break;
		case "YokoDias":		rCharacter.FaceId = 708; break;
		case "Lucia":	                        rCharacter.FaceId = 558; break;
 		case "Davy_Jones":		rCharacter.FaceId = 557; break;
 		case "Vater_skeletcap":	rCharacter.FaceId = 557; break;
		case "Helper":		rCharacter.FaceId = 467; break;
		case "JudiFraider":		rCharacter.FaceId = 506; break;
		case "50_33_40Claire":	rCharacter.FaceId = 447; break;
		case "Beltrop":		rCharacter.FaceId = 404; break;
		case "LeFransua_Mayor":		rCharacter.FaceId = 435; break;
	                  case "alexander":		rCharacter.FaceId = 428; break;
                                     case "Alex_blade":		rCharacter.FaceId = 468; break;
                                     case "BeatriceR":		rCharacter.FaceId = 473; break;
                                     case "Avrora_1":		rCharacter.FaceId = 450; break;
                                     case "Avrora_2":		rCharacter.FaceId = 450; break;
                                     case "Gorn":		rCharacter.FaceId = 407; break;
                                     case "GothicM":		rCharacter.FaceId = 408; break;
                                     case "Sagitta":		rCharacter.FaceId = 521; break;
                                     case "Thekla_Wom_1":	rCharacter.FaceId = 274; break;
	                  case "Abuyin":		rCharacter.FaceId = 1; break;
                                     case "Xanna":		rCharacter.FaceId = 443; break;
		case "TedS":		rCharacter.FaceId = 428; break;	
		case "Sharp":		rCharacter.FaceId = 429; break;
		case "BSUnd":		rCharacter.FaceId = 431; break;
		case "Legran":		rCharacter.FaceId = 433; break;
		case "Torus":		rCharacter.FaceId = 955; break;
		case "Orwel":		rCharacter.FaceId = 295; break;	
		case "Lee":		rCharacter.FaceId = 404; break;
		case "AnnaDeLeiva":	rCharacter.FaceId = 274; break;
case "Dragoon_1":		rCharacter.FaceId = 555; break;
case "VaterSkel_4":		rCharacter.FaceId = 551; break;
case "VaterSkel_1":		rCharacter.FaceId = 552; break;
case "VaterSkel_2":		rCharacter.FaceId = 553; break;
case "VaterSkel_3":		rCharacter.FaceId = 554; break;
case "VaterSkel_4_mush":	rCharacter.FaceId = 551; break;
case "VaterSkel_1_mush":	rCharacter.FaceId = 552; break;
case "VaterSkel_2_mush":	rCharacter.FaceId = 553; break;
case "VaterSkel_3_mush":	rCharacter.FaceId = 554; break;
case "Vaterskeletcap":	rCharacter.FaceId = 557; break;
case "Orc":	          	rCharacter.FaceId = 434; break;

		case "Dasko":	rCharacter.FaceId = 805; break;
		case "Torres":	rCharacter.FaceId = 971; break;

		case "skel1":	rCharacter.FaceId = 448; break;
		case "skel2":	rCharacter.FaceId = 451; break;
		case "skel3":	rCharacter.FaceId = 449; break;
		case "skel4":	rCharacter.FaceId = 447; break;
		case "monkey":	rCharacter.FaceId = 950; break;

		case "skel_1":	rCharacter.FaceId = 446; break;
		case "skel_2":	rCharacter.FaceId = 445; break;
		case "skel_3":	rCharacter.FaceId = 444; break;
		case "skel_4":	rCharacter.FaceId = 443; break;
		case "skel_5":	rCharacter.FaceId = 442; break;	


	}
}

void CirassMaker(aref rCharacter)
{
/*
0 - ГГ
1 - Кирасиры (любая кираса)
2 - Любая скрытая защита
3 - Только корсет или ничего
4 - Берсерки (т.е. ничего) 
*/
	if(CheckAttribute(rCharacter,"cirassIDX")) return;
	rCharacter.cirassIDX = 1; // пока откроем возможность носить кирасы для всех
	switch (rCharacter.model)
	{
		// не носят броню в принципе
		case "mercen_1"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_2"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_3"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_4"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_5"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_6"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_7"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_8"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_9"		: 		rCharacter.cirassIDX = 4;		break;
		case "mercen_10"	: 		rCharacter.cirassIDX = 4;		break;
		
		// легкая защита
		case "mercen_11"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_12"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_13"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_14"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_15"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_16"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_17"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_18"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_19"	: 		rCharacter.cirassIDX = 2;		break;
		case "mercen_20"	: 		rCharacter.cirassIDX = 2;		break;
				
		// тяжелая защита
		case "mercen_21"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_22"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_23"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_24"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_25"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_26"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_27"	: 		rCharacter.cirassIDX = 1;		break;
		case "mercen_28"	: 		rCharacter.cirassIDX = 1;		break;	
		
		case "itza_1"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_2"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_3"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_4"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_5"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_6"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_7"		: 		rCharacter.cirassIDX = 2;		break;
		case "itza_8"		: 		rCharacter.cirassIDX = 2;		break;
	}
}

//Создадим вражеских фантомов
string GetRandSkelModel()
{
	string emodel = "mummy";

	switch (rand(3))
    {
        case 0: emodel = "Skel1";   break;
        case 1: emodel = "Skel2";   break;
        case 2: emodel = "Skel3";   break;
        case 3: emodel = "Skel4";   break;
    }
    return emodel;
}

string GetRandVaterSkelModel()
{
	string emodel = "mummy";

	switch (rand(3))
    {
        case 0: emodel = "VaterSkel_0";   break;
        case 1: emodel = "VaterSkel_1";   break;
        case 2: emodel = "VaterSkel_2";   break;
        case 3: emodel = "VaterSkel_3";   break;
    }
    return emodel;
}

string GetRandZombieModel()
{
	string emodel = "mummy";

	switch (rand(4))
    {
        case 0: emodel = "Zombie_1";   break;
        case 1: emodel = "Zombie_2";   break;
        case 2: emodel = "Zombie_3";   break;
        case 3: emodel = "Zombie_4";   break;
        case 4: emodel = "Zombie_5";   break;
    }
    return emodel;
}

// boal 22.04.04 выбор модели зависимо от типа
void SetCaptanModelByEncType(ref Chref, string sFantomType)
{
    string ModelPirate = "Albermal"; // значит баг
	
	int st = GetCharacterShipType(Chref);	

	if (sti(Chref.nation) == PIRATE) sFantomType = "pirate"; // иначе баг
	
	if(st != SHIP_NOTUSED) 	// есть корабль
	{
		ref rBaseShip = GetRealShip(sti(Chref.Ship.Type));
		int shClass = sti(rBaseShip.Class);
		switch (sFantomType)
		{
			case "trade":
				if(shClass >= 4) ModelPirate = "mercen_" + (rand(4) + 1);
				if(shClass == 3) ModelPirate = "mercen_" + (rand(4) + 11);
				if(shClass <  3) ModelPirate = "mercen_" + (rand(3) + 21);
				Chref.PhantomType = "citizen";
			break;
			case "pirate":
				if(shClass >= 4) ModelPirate = "mercen_" + (rand(4) + 6);
				if(shClass == 3) ModelPirate = "mercen_" + (rand(4) + 16);
				if(shClass <  3) ModelPirate = "mercen_" + (rand(3) + 25);
				Chref.PhantomType = "pirate";
			break;
			case "war":			
				if(shClass >= 4) 				ModelPirate = "off_" + NationShortName(sti(Chref.nation)) + "_" + (rand(2) + 1);
				if(shClass < 4 && shClass > 1)  ModelPirate = "off_" + NationShortName(sti(Chref.nation)) + "_" + (rand(1) + 4);
				if(shClass == 1)
				{
						if(sti(chref.Ship.Type) == SHIP_FORT) 	// командующие фортами
						{
							ModelPirate = "off_" + NationShortName(sti(Chref.nation)) + "_" + (rand(1) + 4);
						}
						else									// командующие линейными кораблями
						{
							ModelPirate = "off_" + NationShortName(sti(Chref.nation)) + "_6";
						}	
				}		
				Chref.PhantomType = "officer";
			break;		
		}
	}
	else									// корабль отсутствует
	{
		switch (sFantomType)
		{
			case "trade":
				switch( rand(2) )
				{
					case 0: ModelPirate = "mercen_" + (rand(4) + 1); 	break;
					case 1: ModelPirate = "mercen_" + (rand(4) + 11);	break;
					case 2: ModelPirate = "mercen_" + (rand(3) + 21);	break;
				}
				Chref.PhantomType = "citizen";
			break;
			case "pirate":
				switch( rand(2) )
				{
					case 0: ModelPirate = "mercen_" + (rand(4) + 6);	break;
					case 1: ModelPirate = "mercen_" + (rand(4) + 16);	break;
					case 2: ModelPirate = "mercen_" + (rand(3) + 25);	break;
				}
				Chref.PhantomType = "pirate";
			break;
			case "war":
				ModelPirate = "off_" + NationShortName(sti(Chref.nation)) + "_" + (rand(2) + 1);
				Chref.PhantomType = "officer";
			break;			
		}
	}
		
	Chref.model = ModelPirate;
	FaceMaker(Chref);
	CirassMaker(Chref);
}

void SetModelPirate(ref ChrefPirate)
{
    string ModelPirate;
    
    ModelPirate = "citiz_" + (rand(9) + 41);
    
    ChrefPirate.model = ModelPirate;
    FaceMaker(ChrefPirate);
	CirassMaker(ChrefPirate);
}

// Warship. Обновим персу модель и анимацию. Пока-что здесь
void Characters_RefreshModel(ref rChar)
{
	SendMessage(rChar, "lss", MSG_CHARACTER_SETMODEL, rChar.model, rChar.model.animation);
}

//Jason - национальная форма солдат по квестам, берутся модели от 10 до 16 - 'спецназ'
string GetRandQuestSoldierModel(int _iNation)
{
	string sModel = "sold_" + NationShortName(_iNation) + "_" + (rand(6)+10);

    return sModel;
}
//Пират Либерталии - национальная форма гвардии, используется для квестовых противников и топовых ПГГ
string GetRandQuestGuardModel(int _iNation)
{
	string sModel = "guard_" + NationShortName(_iNation) + "_" + (rand(7)+1);

    return sModel;
}
//Пират Либерталии - национальная форма милиционеров, используется для патрульных кораблей при контрабанде 
string GetRandQuestMilitiaModel(int _iNation)
{
	string sModel = "sold_" + NationShortName(_iNation) + "_" + (rand(7)+1);

    return sModel;
}
//Пират Либерталии - национальная форма каталонцев, используется для квестовых испанцев
string GetRandCatalanModel()
{
	string sModel = "Catalan_"+(rand(7)+1);
    return sModel;
}
//Пират Либерталии - национальная форма мальтийцев, используется для квестовых французов
string GetRandMaltaModel()
{
	string sModel = "Malta_"+(rand(7)+1);
    return sModel;
}
//Jason - для высших квестовых пиратских врагов - наемники
string GetRandQuestMercenaryModel()
{
	string sModel = "citiz_"+(51+(rand(9)));

    return sModel;
}

// Warship, 30.05.11. Две функции для установления персонажу национальной формы солдата или офицера -->
// Отличия от функции выше - используютя все модели.
// Jason: для солдат будем брать только от 1 до 9
void SetRandNationSoldierModel(ref _character)
{
	_character.model = "sold_" + NationShortName(sti(_character.nation)) + "_" + (1 + rand(8));
    FaceMaker(_character);
	CirassMaker(_character);
}

void SetRandNationOfficerModel(ref _character)
{
	_character.model = "off_" + NationShortName(sti(_character.nation)) + "_" + (1 + rand(5));
    FaceMaker(_character);
	CirassMaker(_character);
}
// <--

// Warship, 04.06.11. Просто установка модели.
void SetModel(ref _character, string _model)
{
	_character.model = _model;
    FaceMaker(_character);
	CirassMaker(_character);
}
