
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	rootина
	09.07.19  //  Пират Либерталии
*/

#include "interface\CheatSurfMenu\CheatSurfMenu_hotkeys.c"

// Сокращение Log_SetStringToLog
void vLog(string sStr)
{
	Log_SetStringToLog(sStr);
}

// Сокращение CheckAttribute
int csmCA(object oChar, string sAttr)
{
	return CheckAttribute(&oChar, sAttr);
}

// Сокращение DeleteAttribute
void csmDA(object oChar, string sAttr)
{
	DeleteAttribute(&oChar, sAttr);
}

// Изменение P.I.R.A.T.E.S. офицерам -->
void ChangePIRATESNavigator(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESBoatswain(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESCannoner(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESDoctor(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESTreasurer(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESCarpenter(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterA(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterB(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterC(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}
// <--

// Вывод полного имени офицера -->
string GetOfficerName(int iOfficer)
{
	ref rChar;
	string sOffName = "";
	int ion;
	bool bContinue = false;
	if (iOfficer < 1 || iOfficer > 9)
	{
		iOfficer = 1;
	}

	switch (iOfficer)
	{
		case 1:
			if (sti(pchar.Fellows.Passengers.navigator) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
				bContinue = true;
			}
		break;
		case 2:
			if (sti(pchar.Fellows.Passengers.boatswain) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
				bContinue = true;
			}
		break;
		case 3:
			if (sti(pchar.Fellows.Passengers.cannoner) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
				bContinue = true;
			}
		break;
		case 4:
			if (sti(pchar.Fellows.Passengers.doctor) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
				bContinue = true;
			}
		break;
		case 5:
			if (sti(pchar.Fellows.Passengers.treasurer) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
				bContinue = true;
			}
		break;
		case 6:
			if (sti(pchar.Fellows.Passengers.carpenter) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
				bContinue = true;
			}
		break;
		case 7:
			ion = GetOfficersIndex(pchar, 1);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
		case 8:
			ion = GetOfficersIndex(pchar, 2);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
		case 9:
			ion = GetOfficersIndex(pchar, 3);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
	}
	if (bContinue)
	{
		sOffName = " (" + GetFullName(rChar) + ")";
	}
	return sOffName;
}
// <--

// Вывод полного имени компаньона -->
string GetCompanionName(int iCompanionIdx)
{
	ref rChar;
	string sCompName = "";
	int icn;
	bool bContinue = false;
	if (iCompanionIdx < 1 || iCompanionIdx > 8)
	{
		iCompanionIdx = 1;
	}

	switch (iCompanionIdx)
	{
		case 1:
			icn = GetCompanionIndex(pchar, 1);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 2:
			icn = GetCompanionIndex(pchar, 2);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 3:
			icn = GetCompanionIndex(pchar, 3);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;

		case 4:
			icn = GetCompanionIndex(pchar, 4);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 5:
			icn = GetCompanionIndex(pchar, 5);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 6:
			icn = GetCompanionIndex(pchar, 6);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 7:
			icn = GetCompanionIndex(pchar, 7);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
	}
	if (bContinue)
	{
		sCompName = " (" + GetFullName(rChar) + ")";
	}
	return sCompName;
}
// <--

// Фикс пропадания музыки и звуковой схемы после воспроизведения видео в игре -->
void CSMSoundFix(string qName)
{
	if (IsEntity(&worldMap))
	{
		ResetSound();
		SetSchemeForMap();
	}
	else
	{
		if (IsEntity(&AISea) && !IsEntity(loadedlocation))
		{
			ResetSound();
			SetSchemeForSea();
		}
		else
		{
			ResetSound();
			LoadSceneSound();
		}
	}
}
// <--

void CSM_OnNewGame()
{
	pchar.CSM.StartNewGame = true;
//	pchar.CSM.Test = true;
	//
	csmInitItems();
	//
	if (!CheckAttribute(pchar, "CSM.WavesType"))
	{
		pchar.CSM.WavesType = -1;
		SM_WavesEnable();
		Whr_UpdateWeather();
		DoQuestFunctionDelay("CSMEnhancedSea", 0.5);
	}
}

void CSM_OnSave()
{
//
}

void CSM_OnLoad()
{
	ref sld, rItm;
	int i, ic, ip, icn, ipn;
	string sCheat, sT;

	// постоянные процедуры -->
	csmDelAttrs();
	//
	ShipsInit();
	//
	if (!CheckAttribute(pchar, "CSM.ContinuousMusicReset"))
	{
		if (CheckAttribute(pchar, "CSM.JungleContinuousMusic") && pchar.CSM.JungleContinuousMusic == true)
		{
			if (CheckAttribute(loadedLocation, "type") && loadedLocation.type == "jungle")
			{
				if (loadedLocation.type == locations[reload_cur_location_index].type)
				{
					pchar.CSM.ContinuousMusicReset = true;
				}
			}
		}
	}
	//
	DoQuestFunctionDelay("CSMCheckUpdates", 1.0);
	// <--

	// AoE трехствольному дробовику -->
	rItm = ItemsFromID("pistol2");
	rItm.type.t1.multidmg = true;

	// фикс говорилки официанткам, забыл про них
	if (!CheckAttribute(pchar, "CSM.WaitressVoiceFix")) DoQuestFunctionDelay("csmWaitressVoice", 0.1);

	// фикс клонирования офов из ЧМ -->
	if (!CheckAttribute(pchar, "CSM.OfficersFix"))
	{
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				csmFixOfficers(sld);
			}
		}
		for (ip = 0; ip < GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				csmFixOfficers(sld);
			}
		}
		pchar.CSM.OfficersFix = true;
	}
	// <--

	// старые фиксы -->
	if (!CheckAttribute(pchar, "CSM.StartNewGame") && !CheckAttribute(pchar, "CSM.FirstLaunch"))
	{
		//
//		pchar.CSM.Test = true;
		//
		if (GetItemsWeight(pchar) > GetMaxItemsWeight(pchar))
		{
			pchar.CSM.CargoTank = true;
			CheckAndSetOverloadMode(GetMainCharacter());
		}
		//
		csmInitItems();
		//
		if (!CheckAttribute(pchar, "CSM.WavesType"))
		{
			pchar.CSM.WavesType = -1;
			SM_WavesEnable();
			Whr_UpdateWeather();
			DoQuestFunctionDelay("CSMEnhancedSea", 1.0);
		}
		if (CheckAttribute(pchar, "CSM.OfficersSalary"))
		{
			for (ic = 1; ic < COMPANION_MAX; ic++)
			{
				icn = GetCompanionIndex(pchar, ic);
				if (icn != -1)
				{
					sld = GetCharacter(icn);
					if (GetRemovable(sld))
					{
						sld.Payment = true;
					}
				}
			}
			for (ip = 0; ip < GetPassengersQuantity(pchar); ip++)
			{
				ipn = GetPassenger(pchar, ip);
				if (ipn != -1)
				{
					sld = GetCharacter(ipn);
					if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
					{
						sld.Payment = true;
					}
				}
			}
		}
/*
		for (i = 1; i <= 70; i++)
		{
			sCheat = ".F" + i;
			DeleteAttribute(pchar, "Statistic.Cheats" + (sCheat));
		}
*/
		//
		pchar.CSM.FirstLaunch = true;
	}
	// <--
}

void csmInitItems()
{
	if (CheckAttribute(pchar, "InitItemsDone")) return;
	ref rItem;
	//
	rItem = ItemsFromID("blade_36");
	if (CheckAttribute(rItem, "picIndex") && rItem.picIndex != 16)
	{
		rItem.picIndex = 16;
		rItem.picTexture = "ITEMS_17";
		rItem.price = 10000;
		rItem.Weight = 3.0;
		rItem.lenght = 1.05;
		rItem.curve = 1.0;
		rItem.balance = 1.9;
	}
	//
	pchar.CSM.InitItemsDone = true;
}

void CheatSurfMenuWelcome(string qName)
{
	ClearAllLogStrings();
	DoQuestFunctionDelay("csmWaitressVoice", 0.1);
	pchar.CSM.Welcome = true;
	PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info("Чит-меню готово к использованию!");
}

string csmMenuText(int iType)
{
	if (iType < 0 || iType > 1) iType = 0;

	string sText = "Hello, world!";

	switch (iType)
	{
		case 0:
			sText = "Приветствую, корсар!" +
					"\nДанное чит-меню (далее ЧМ) делалось и тестировалось на русской Steam-версии игры Корсары: Каждому Своё, версии 1.6.0 (18.12.17)" +
					"\n Автором ЧМ является Cheatsurfer и его коллеги, я (Пират Либерталии) лишь адаптировал и корректировал это меню для своих целей, а потому никоим образом не претендую на авторство этого меню и его функций" +
					"\nНажмите 'Esc' (или клик по 'крестику' справа вверху) и запустите любое меню ещё раз." +
					"\nСпасибо за внимание и приятной игры!";
		break;
		case 1:
			sText = "Чтобы увидеть весь список команд, используйте колесо мыши (кликнув по тексту) или скролл правее." +
					"\nКаждую кнопку можно нажимать для повторения или отмены действия сколько угодно раз. Выход по 'Esc'." +
		break;
	}

	return sText;
}

void csmDelAttrs()
{
	DeleteAttribute(pchar, "CSM.ChangeModels");
	DeleteAttribute(pchar, "CSM.Test");
//	DeleteAttribute(pchar, "CSM.ChangeModelM");
//	DeleteAttribute(pchar, "CSM.ChangeModelW");
}

// переиначенный CalculateCheatsInfo()
void csmCheatsInfo(int iMenu)
{
	int i;
	string sCheat;
	string sMenu = "CSM1";

	if (iMenu < 0 || iMenu > 8) iMenu = 0;

	switch (iMenu)
	{
		case 0: sMenu = "CSM1"; break;
		case 1: sMenu = "CSM2"; break;
		case 2: sMenu = "CSM3"; break;
		case 3: sMenu = "CSM4"; break;
		case 4: sMenu = "CSM5"; break;
		case 5: sMenu = "CSM6"; break;
		case 6: sMenu = "CSM7"; break;
		case 7: sMenu = "CSM8"; break;
		case 8: sMenu = "CSM9"; break;
	}

	for (i = 1; i <= 70; i++)
	{
		sCheat = (sMenu) + ".F" + i;
		if(Statistic_AddValue(PChar, "Cheats." + sCheat, 0) == 0)
			PChar.Statistic.Cheats.(sCheat) = 0;
	}

	aref arAllCheats;
	makearef(arAllCheats, PChar.Statistic.Cheats.(sMenu));
	int iAllCheats = GetAttributesNum(arAllCheats);
	int iAllCheatsCount = 0;

	SetFormatedText("INFO_TEXT2", "Использовавшиеся читы:");

	for (i = 0; i < iAllCheats; i++)
	{
		sCheat = GetAttributeName(GetAttributeN(arAllCheats, i));
		int iCurCheatCount = Statistic_AddValue(PChar, "Cheats." + (sMenu) + "." + sCheat, 0);
		if(iCurCheatCount == 0) continue; // Если чит не юзался - пропускаем
		if(HasSubStr(sCheat, "F"))
			AddLineToFormatedText("INFO_TEXT2", XI_ConvertString("D_" + sCheat) + " - " + iCurCheatCount + " раз.");
		else
			AddLineToFormatedText("INFO_TEXT2", sCheat + " - " + iCurCheatCount + " раз.");
		iAllCheatsCount = iAllCheatsCount + iCurCheatCount;
	}

	PChar.Statistic.Cheats.(sMenu) = iAllCheatsCount;
	AddLineToFormatedText("INFO_TEXT2", XI_ConvertString("Total") + " " + iAllCheatsCount + " раз.");

	if(iAllCheatsCount == 0) // Исли 0, значит читов не юзали
		SetFormatedText("INFO_TEXT2", "\n\nЧитов не использовалось!");
}



/* --> by Sticksъ : чтоб все в одном месте было + возможность создавать мушкетеров

Example:

string  model;
string  ani;
bool sldIsMush;

sldIsMush = CSM_GetModelByCrewType(pChar.GenQuest.BoardCrewType, &model, &ani, false);
sld = GetCharacter(NPC_GenerateCharacter("newSld", model, "man", ani, iRank, PIRATE, -1, true, "soldier"));
*/
	
bool CSM_GetModelByCrewType(int crewType, ref model, ref ani, bool tryToFindMushketer)
{
	
	object models;
	int totalVars;
	int rndVar;
	
	// если tryToFindMushketer = true и для типа команды имеются подходящие модели мушкетёров, то можем их тут создать.
	if (tryToFindMushketer)
	{
		
		switch (crewType)
		{
			
			case 0:
			//   	 модель						   					 анимация
			//         v												v
				models.v0 = "mush_ctz_" + (rand(2) + 4);		models.a0 = "mushketer"; // матрос с ружьем
				break;
			
			// Англия ..............................................................................
			
			case 1:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				break;
			case 2:
				models.v0 = "shturm_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-солдаты
				break;
			case 3:
				models.v0 = "guard_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 4:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_eng_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_eng_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 5:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_eng_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_eng_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // матрос с ружьем
				break;
			case 6:
				models.v0 = "guard_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-гвардейцы
				models.v1 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a1 = "mushketer"; // Рыбьи Хари
				break;
			// Франция .............................................................................
			
			case 7:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				break;
			case 8:
				models.v0 = "shturm_mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-солдаты
				break;
			case 9:
				models.v0 = "guard_mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 10:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_fra_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_fra_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 11:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_fra_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_fra_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // матрос с ружьем
				break;
			case 12:
				models.v0 = "mush_Malta_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мальтийцы-мушкетёры
				break;
				
			// Испания .............................................................................
			
			case 13:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				break;
			case 14:
				models.v0 = "shturm_mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-солдаты
				break;
			case 15:
				models.v0 = "guard_mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 16:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_spa_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_spa_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 17:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_spa_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_spa_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // матрос с ружьем
				break;
			case 18:
				models.v0 = "mush_Catalan_" + (rand(2) + 1);		models.a0 = "mushketer"; // Каталонцы-мушкетёры
				break;
			
			// Голландия ...........................................................................
			
			case 19:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				break;
			case 20:
				models.v0 = "shturm_mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-солдаты
				break;
			case 21:
				models.v0 = "guard_mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 22:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_hol_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_hol_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				break;
			case 23:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // Мушкетёры-менты
				models.v1 = "shturm_mush_hol_" + (rand(2) + 1);		models.a1 = "mushketer"; // Мушкетёры-солдаты
				models.v2 = "guard_mush_hol_" + (rand(2) + 1);		models.a2 = "mushketer"; // Мушкетёры-гвардейцы
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // матрос с ружьем
				break;

				// Деловые люди ................................................................................
			
			case 24:
				//models.v0 = "mush_ctz_" + (rand(2) +  4);		models.a0 = "mushketer"; // матрос с ружьем
				//models.v1 = "mush_ctz_" + (rand(2) +  7);		models.a1 = "mushketer"; // пират с ружьем
				models.v2 = "mush_ctz_" + (rand(2) +  1);		models.a2 = "mushketer"; // торгаш с ружьём
				models.v3 = "mush_ctz_" + (rand(2) + 10);		models.a3 = "mushketer"; // наёмник с ружьём
				break;
	
			// Попы ................................................................................
			
			case 25:
				/* У попов вроде нет мушкетеров, идем в солдаты */
				models.v0 = "Priest_" + (rand(2) + 2) + "_mush";		models.a0 = "mushketer";
				break;
				
			// Пираты ..............................................................................
			
			case 26:
				models.v0 = "mush_ctz_" + (rand(2) + 7);		models.a0 = "mushketer"; // пират с ружьем
				break;
			
			// Бродяги ............................................................................
			
			case 27:
				/* надо узнавать, есть ли нищие или зэки с ружьями.. может от Ривадос сюда негров добавить :) */
				models.v0 = "mush_ctz_" + (rand(2) + 7);		models.a0 = "mushketer"; // пират с ружьем
				break;
			
			// Ирокезы ..............................................
			
			case 28:
				models.v0 = "mush_iroquois_" + (rand(7) +  1);		models.a0 = "mushketer"; // Ирокезы-мушкетёры
				break;
				
			// Индейцы ............................................................................
			
			case 29:
				/* из индейцев только Тичингиту умеет юзать ружье.. Хотя вот есть "Canib_mush", надо проверить что это */
				models.v0 = "mush_cnb_" + (rand(2) + 1);		models.a0 = "mushketer";
				models.v1 = "mush_Itza_" + (rand(2) + 1);		models.a1 = "mushketer";
				models.v2 = "mush_msk_" + (rand(2) + 1);		models.a2 = "mushketer";
				break;
				
			//Американцы............................................................................
			
			case 30:
			models.v0 = "mush_usa_" + (rand(2) + 1);		
			models.a0 = "mushketer"; 
				break;	
				
			// Скелеты ............................................................................
			
			case 31:
				/* надо узнавать, берут ли скелеты ружья... */
				models.v0 = "skel" + rand(4) + "_mush";					models.a0 = "mushketer";
				break;
			
			// Рыбы ...............................................................................
			
			case 32:
				/* надо узнавать, берут ли рыбы ружья... */
				models.v0 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a0 = "mushketer"; // кроме босса, он боец
				break;
			
			// Скелеты и рыбы .....................................................................
			
			case 33:
				/* надо узнавать, берут ли скелеты или рыбы ружья... */
				models.v0 = "skel" + rand(4) + "_mush";					models.a0 = "mushketer";
				models.v1 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a1 = "mushketer"; // кроме босса, он боец
				break;
		}
		
		totalVars = GetAttributesNum(models);
		if (totalVars > 0)
		{
			GRMAF(models, totalVars, model, ani);
			return true; // если мушкетер нашелся, то и все
		}
	}
	
	// а тут пошла обычная солдатня
	
	switch (crewType)
	{
		
		case 0:
			models.v0 = "citiz_" + (rand(9) + 31);			models.a0 = "man"; // матрос
			break;
		
		// Англия .................................................................................
		
		case 1:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			break;
		case 2:
			models.v0 = "shturm_eng_" + (rand(7) + 1);		models.a0 = "man"; // Солдаты
			break;
		case 3:
			models.v0 = "guard_eng_" + (rand(7) + 1);		models.a0 = "man"; // Гвардия
			break;
		case 4:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_eng_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_eng_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			break;
		case 5:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_eng_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_eng_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // матрос
			break;
		case 6:
			models.v0 = "VaterSkel_" + (rand(3) + 1);			models.a0 = "man"; // рыбий монстр
			models.v1 = "guard_eng_" + (rand(7) + 1);		models.a1 = "man"; // Гвардия
			break;

		// Франция ................................................................................
		
		case 7:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			break;
		case 8:
			models.v0 = "shturm_fra_" + (rand(7) + 1);		models.a0 = "man"; // Солдаты
			break;
		case 9:
			models.v0 = "guard_fra_" + (rand(7) + 1);		models.a0 = "man"; // Гвардия
			break;
		case 10:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_fra_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_fra_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			break;
		case 11:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_fra_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_fra_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // матрос
			break;
		case 12:
			models.v0 = "Malta_" + (rand(7) + 1);		models.a0 = "man"; // Мальтийцы
			break;
			
		// Испания ................................................................................
		
		case 13:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			break;
		case 14:
			models.v0 = "shturm_spa_" + (rand(7) + 1);		models.a0 = "man"; // Солдаты
			break;
		case 15:
			models.v0 = "guard_spa_" + (rand(7) + 1);		models.a0 = "man"; // Гвардия
			break;
		case 16:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_spa_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_spa_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			break;
		case 17:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_spa_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_spa_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // матрос
			break;
		case 18:
			models.v0 = "Catalan_" + (rand(7) + 1);		models.a0 = "man"; // Каталонцы
			break;
			
		// Голландия ..............................................................................
		
		case 19:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			break;
		case 20:
			models.v0 = "shturm_hol_" + (rand(7) + 1);		models.a0 = "man"; // Солдаты
			break;
		case 21:
			models.v0 = "guard_hol_" + (rand(7) + 1);		models.a0 = "man"; // Гвардия
			break;
		case 22:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_hol_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_hol_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			break;
		case 23:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // Милиция
			models.v1 = "shturm_hol_" + (rand(7) + 1);		models.a1 = "man"; // Солдаты
			models.v2 = "guard_hol_" + (rand(7) + 1);		models.a2 = "man"; // Гвардия
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // матрос
			break;

		// Деловые люди ..................................................

		case 24:
			models.v0 = "mercen_" + (rand(12) + 16);		models.a0 = "man"; // шишка
			break;
		
		// Попы ...................................................................................
		
		case 25:
			models.v0 = "monk_" + (rand(5) + 1);			models.a0 = "man_B"; // монах
			// todo: может добавить инквизиторов и попов?
			break;
			
		// Пираты .................................................................................
		
		case 26:
			models.v0 = "citiz_" + (rand(9) + 41);			models.a0 = "man"; // пират
			break;
		
		// Бродяги ................................................................................
		
		case 27:
			models.v0 = "panhandler_" + (rand(5) + 1);		models.a0 = "man"; // нищий
			models.v1 = "prison_" + (rand(4) + 1);			models.a1 = "man_B"; // зэк
			models.v2 = "prizon_" + (rand(7) + 1);			models.a2 = "man_B"; // беглый
			break;

		// Ирокезы ..................................................
		
		case 28:
			models.v0 = "Iroquois_" + (rand(7) + 1);		models.a0 = "man"; // Ирокезы
			break;
			
		// Индейцы ................................................................................
		
		case 29:
			models.v0 = "Canib_" + (1 + rand(5));			models.a0 = "man"; // каннибал
			models.v1 = "Itza_" + (1 + rand(7));			models.a1 = "man"; // ица
			models.v2 = "AztecWarrior" + (1 + rand(4));		models.a2 = "man"; // ацтек
			models.v3 = "Miskito_" + (1 + rand(5));			models.a3 = "man"; // мистико
			break;

		//Американцы................................................................................
		
		case 30:
		models.v0 = "sold_usa_" + (rand(7) + 1);					models.a0 = "man"; 
			break;

		// Скелеты ................................................................................
		
		case 31:
		models.v0 = "Skel" + rand(4);							models.a0 = "man"; // скелет
		models.v1 = "SkelK2_" + rand(4);						models.a1 = "man_B"; // скелет из К2
		break;
		
		// Рыбы ...................................................................................
		
		case 32:
		models.v0 = "VaterSkel_" + (rand(3) + 1);					models.a0 = "man"; // рыбий монстр
		break;
		
		// Скелеты и рыбы .........................................................................
		
		case 33:
		models.v0 = "Skel" + rand(4);							models.a0 = "man"; // скелет
		models.v1 = "SkelK2_" + rand(4);						models.a1 = "man_B"; // скелет из К2
		models.v2 = "VaterSkel_" + (rand(3) + 1);					models.a2 = "man"; // рыбий монстр
		break;
	}
	
	totalVars = GetAttributesNum(models);
	if (totalVars > 0)
		GRMAF(models, totalVars, model, ani);
	
	return false;
}

// к предыдущему методу (get random model i animation from)
void GRMAF(object models, int totalVars, ref model, ref ani)
{
	aref aModels;
	makearef(aModels, models);
	int index = rand(totalVars / 2 - 1) * 2;
	model = GetAttributeValue(GetAttributeN(aModels, index));
	ani = GetAttributeValue(GetAttributeN(aModels, index + 1));
}

void CSM_LoadNextWeather()
{
    iCurWeatherNum++;
    if (iCurWeatherNum > 23)
        iCurWeatherNum = 0;
    CSM_LoadWeatherContinue();
}
 
void CSM_LoadPrevWeather()
{
    iCurWeatherNum--;
    if (iCurWeatherNum < 0)
        iCurWeatherNum = 23;
    CSM_LoadWeatherContinue();
}
 
void CSM_LoadWeatherContinue()
{
    if (!isEntity(&Weather)) return;
    iCurWeatherHour = iCurWeatherNum;
    SetCurrentTime(iCurWeatherNum, 0);
    Weather.Time.time = GetTime();
    CreateWeatherEnvironment();
    MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);
}

// взять случайный звук для пушки с таким-то калибром
string CSM_GetRandomCannonSoundByCaliber(int caliber)
{
	if (caliber <= 8)
		return "asm_little_" + (rand(5) + 1);
	else if (caliber > 8 && caliber <= 20)
		return "asm_medium_" + (rand(5) + 1);
	else
		return "asm_heavy_" + (rand(5) + 1);
	
	return "";
}
// by Sticksъ <--



void CSMAnimationFix(string qName)
{
	ClearAllLogStrings();
	Log_info("Если анимация персонажа 'сломалась', её можно восстановить в меню 'Персонаж' (опции #65 и #68)!");
}

void CSMCheckUpdates(string qName)
{
	aref arFader;
	if (FindClass(arFader, "fader")) return;

	bool bTest = false;

	pchar.CSM.Version = "ver. 1.6.0 (18.12.17)";

	if (bTest)
	{
		pchar.CSM.Version = " " + VERSION_NUMBER2;
	}

	if (pchar.CSM.Version != VERSION_NUMBER2)
	{
		ClearAllLogStrings();
		log_info("Текущая версия игры: " + VERSION_NUMBER2);
		log_info("Нужная версия игры для ЧМ: " + pchar.CSM.Version);
		PlaySound("_CheatSurfMenu_\NationRelationChange.wav");
		pchar.CSM.ChangeName = "Update";
		CSMLaunchMenuName();
	}

	if (SHIP_TYPES_QUANTITY != 64) DoQuestFunctionDelay("CSMCheckSave", 0.25);
}

void CSMChangeName(string qName)
{
	CSMLaunchMenuName();
}

void CSMCheckSave(string qName)
{
	ClearAllLogStrings();
	PlaySound("_CheatSurfMenu_\WTF.wav");
	pchar.CSM.ChangeName = "Save";
	CSMLaunchMenuName();
}

void CSMEnhancedSea(string qName)
{
	ClearAllLogStrings();
	log_info("Включено улучшение водной поверхности от Sticks.");
	log_info("Эту опцию можно изменить \ отключить в меню 'Прочее', #46.");
}

void csmWaitressVoice(string qName)
{
	if (CheckAttribute(pchar, "CSM.WaitressVoiceFix")) return;

	ref rChar;
	int iChar;

	for (iChar = 0; iChar < TOTAL_CHARACTERS; iChar++)
	{
		rChar = GetCharacter(iChar);
		if (CheckAttribute(rChar, "chr_ai.type") && rChar.chr_ai.type == LAI_TYPE_WAITRESS)
		{
			rChar.greeting = "waitress_voice";
		}
	}

	pchar.CSM.WaitressVoiceFix = true;
}

void SetBasePerks(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;

	// Скрытые и бонусные перки возвращаем
	SetCharacterPerk(rChar, "Energaiser");
	switch (rChar.id)
	{
		case "HelenaClon": SetCharacterPerk(rChar, "HT1"); break;
		case "MaryClon": SetCharacterPerk(rChar, "HT1"); break;
		case "DanielleClon": SetCharacterPerk(rChar, "HT1"); break;
		case "KnippelClon": SetCharacterPerk(rChar, "HT4"); break;
		case "LongwayClon": SetCharacterPerk(rChar, "HT3"); break;
		case "TichingituClon": SetCharacterPerk(rChar, "HT4"); break;
		case "TonzagClon": SetCharacterPerk(rChar, "HT3"); break;
		case "SteampunkGirl": SetCharacterPerk(rChar, "HT2"); break;
		case "Angellica": SetCharacterPerk(rChar, "HT1"); break;
		case "Yoko": SetCharacterPerk(rChar, "HT1"); break;
		case "Douglas": SetCharacterPerk(rChar, "HT4"); break;
		case "JaPreston": SetCharacterPerk(rChar, "HT3"); break;
		case "Magnus": SetCharacterPerk(rChar, "HT4"); break;
		case "Nicolas": SetCharacterPerk(rChar, "HT4"); break;
		case "CSMDevlinBlaze": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMBeatriceSharp": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMJessikaBradford": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMPiterBlood": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMMichelDeGrammont": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMWillaimPatterson": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMBartPortugal": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMDiegoEspinosa": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMPitt": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMOgl": SetCharacterPerk(rChar, "HT1"); break;
		case "Vincento_Capellan": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMBlackBeard": SetCharacterPerk(rChar, "HT3"); SetCharacterPerk(rChar, "HT4"); break;
		case "CSMLawrenceBeltrop": SetCharacterPerk(rChar, "HT3"); SetCharacterPerk(rChar, "HT4"); break;
		case "CSMJWorkman": SetCharacterPerk(rChar, "HT3"); break;
		case "FleetwoodClon": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMChani": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMCiri": SetCharacterPerk(rChar, "HT1"); SetCharacterPerk(rChar, "HT3"); break;
		case "CSM_JanPikar": SetCharacterPerk(rChar, "HT1"); break;
	}
	if (HasSubStr(rChar.id, "CSMNavalOfficer")) SetCharacterPerk(rChar, "HT1");
}

// фикс клонирования офов в ЧМ
void csmFixOfficers(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;

	if (rChar.id == "HelenaClon" || rChar.id == "MaryClon" || rChar.id == "DanielleClon" || rChar.id == "KnippelClon" || rChar.id == "LongwayClon" || rChar.id == "TichingituClon" || rChar.id == "TonzagClon" ||
		rChar.id == "SteampunkGirl" || rChar.id == "Angellica" || rChar.id == "Yoko" || rChar.id == "Douglas" || rChar.id == "JaPreston" || rChar.id == "Magnus" || rChar.id == "Nicolas" || rChar.id == "CSMDevlinBlaze" ||
		rChar.id == "CSMBeatriceSharp" || rChar.id == "CSMJessikaBradford" || rChar.id == "CSMPiterBlood" || rChar.id == "CSMMichelDeGrammont" || rChar.id == "CSMWillaimPatterson" || rChar.id == "CSMBartPortugal" ||
		rChar.id == "CSMDiegoEspinosa" || rChar.id == "CSMPitt" || rChar.id == "CSMOgl" || rChar.id == "Vincento_Capellan" || rChar.id == "CSMBlackBeard" || rChar.id == "CSMLawrenceBeltrop" || rChar.id == "CSMJWorkman" ||
		rChar.id == "FleetwoodClon" || rChar.id == "CSMChani" || rChar.id == "CSMCiri" || HasSubStr(rChar.id, "CSMNavalOfficer"))
	{
		rChar.CSM.NPC = true;
		rChar.CSM.CommonAttributes = true;
	}
}

// фикс ситуации с энкаунтером "перехватчик", если у нации ГГ нет врагов
void csm_EnemyNationHunterOnMap(bool _fast)//охотники вражеской нации
{
    ref  sld;
    int  i, iNation;
    string sCapId = "FollowerNation0"; // patch
    string sGroup = "Sea_" + sCapId + "1";
	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	iNation = GetEnemyNationToMainCharacter();//вражеская нация
	if (iNation < 0 || iNation > 4) iNation = PIRATE;
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_" + NationShortName(iNation) + "_" + (rand(1) + 1), "man", "man", sti(PChar.rank) + 5, iNation, 6, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld);
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = "перехватчики";
		sld.hunter = ""+iNation+"";
        Group_AddCharacter(sGroup, sCapId + i);
    }
    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
	if (_fast) Map_CreateCoolWarrior("", sCapId + "1", 6);
	else Map_CreateWarrior("", sCapId + "1", 6);
}

// --> Быстрая смена мушкета. На основе кода dolphin'а (аддон КИП)
#event_handler("csmEventSwapWeapon", "csmSwapWeapon");
void csmSwapWeapon()
{
	int i = 0;
	bool bBullet = false;
	ref rGun, rCharge;
	string sAttr, sCharge;
	string sMusket = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);

	LAi_LockFightMode(pchar, false);

	if (HasSubStr(sMusket, "mushket"))
	{
		SetMainCharacterToMushketer("", false);
		pchar.CSM.PrevMusket = sMusket;
	}
	else
	{
		if (csmCA(pchar, "CSM.PrevMusket"))
		{
			if (CheckCharacterItem(pchar, pchar.CSM.PrevMusket))
			{
				// 2do: нужно бы шмонать весь инвентарь и, если есть, цеплять лучший мушкет
				SetMainCharacterToMushketer(pchar.CSM.PrevMusket, true);

				rGun = ItemsFromID(pchar.CSM.PrevMusket);

				for (i = 1; i <= 2; i++)
				{
					sAttr = "t" + i;
					sCharge = rGun.type.(sAttr).bullet;

					if (CheckCharacterItem(pchar, sCharge))
					{
						bBullet = true;
						LAi_SetCharacterUseBullet(pchar, sCharge);
						LAi_GunSetUnload(pchar); // 2do: мб докодить запоминалку зарядов
						rCharge = ItemsFromID(sCharge);
						vLog("Используемый тип боеприпасов для '" + GetConvertStr(rGun.name, "ItemsDescribe.txt") + "': " + GetConvertStr(rCharge.name, "ItemsDescribe.txt"));
						break;
					}
				}

				csmDA(pchar, "CSM.PrevMusket");
				csmSFM();

				if (!bBullet)
				{
					csmSound("WTF", 0);
					vLog("Подходящих боеприпасов для '" + GetConvertStr(rGun.name, "ItemsDescribe.txt") + "' не найдено!");
				}
			}

			return;
		}
		else
			return;
	}

	csmSFM();
}

void csmSFM()
{
	if (LAi_grp_playeralarm > 0)
	{
		if (!LAi_CheckFightMode(pchar))
			PostEvent("csmEventSwapWeaponFight", 100);
		else
			SendMessage(&pchar, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
	}
}

#event_handler("csmEventSwapWeaponFight", "csmSwapWeaponFight");
void csmSwapWeaponFight()
{
	LAi_LockFightMode(pchar, false);
	LAi_SetFightMode(pchar, true);
}

void csmSwapWeaponBack()
{
	string sMusket = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);

	if (csmCA(pchar, "CSM.IsFireNow"))
	{
		vLog(PChar.name + " в данный момент занят" + GetSexPhrase("", "а") + " стрельбой!");
		return;
	}
	else
	{
		LAi_SetFightMode(pchar, false);
		LAi_LockFightMode(pchar, true);

		// "временнЫе подушки", чтобы модель не похерило при смене анимации
		if (HasSubStr(sMusket, "mushket"))
			PostEvent("csmEventSwapWeapon", 500);
		else
			PostEvent("csmEventSwapWeapon", 1700);
	}
}

#event_handler("csmEventSwapWeaponIsFireNowDel", "csmSwapWeaponIsFireNowDel");
void csmSwapWeaponIsFireNowDel()
{
	csmDA(pchar, "CSM.IsFireNow");
}
// <-- Быстрая смена мушкета

int csmSound(string sFile, int iType)
{
	string sType = ".wav";

	if (sFile == "")
		sFile = "WTF";

	if (iType < 0 || iType > 2)
		iType = 0;

	switch (iType)
	{
		case 0: sType = ".wav"; break;
		case 1: sType = ".ogg"; break;
		case 2: sType = ".mp3"; break;
	}

	return PlaySound("_CheatSurfMenu_\" + sFile + sType);
}

// 2do: 20may17 удалить всю эту дичь потом, сейчас нигде не юзается, оставлено для совместимости сейвов -->
bool bCSMSkipStartVids = true;
bool bCSMDeletePerks = false;
bool bCSMGotAllHidePerks = false;
bool bCSMShowHelpHints = false;
bool bCSMCheckAndIdentifyShips = true;
bool bCSMKillEmAll = false;
bool bCSMFreeSailing = false;
bool bCSMSailToEffectRadius = false;
bool bCSMAllItemsInTrade = false;
bool bCSMAllShipsInTrade = false;
bool bCSMSkipShips = false;
bool bCSMMachineGunCannons = false;
bool bCSMCirassPenalty = true;
bool bCSMDeleteShipsInStock = true;
bool bCSMEnergyDrain = true;
bool bCSMTreasureMapTrader = false;
bool bCSMShipHullPenalty = true;
bool bCSMBoardingCrewGodMode = false;
bool bCSMShipCapellanHatePirates = true;
bool bCSMShipInstantRepair = false;
bool bCSMShipMutinies = true;
int iCSMBaseWeight = 70;
float fCSMBonusEnergy = 1.0;
// <-- 2do: del