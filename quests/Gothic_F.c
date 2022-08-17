void GothicFQuestComplete(string sQuestName, string qname)
{
ref sld, rCharacter, chr, chr2, loc;
ref sld1, sld2, npchar;

int     iTemp, i, hcrew; // нужно для вычислений любых целых (нации)
float   locx, locy, locz;
string  sTemp; // любые строки для вычислений
bool    bOk;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  разное с оптимизации   начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
////   Миниквесты        начало   ГПК
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Квест Аскольда (мумия)
////////////////////////////////////////////////////////////////////////////////////////////////////////


void Ascold_GuadeloupeToCave(string qName)
{

		pchar.quest.Ascold_GuadeloupeToCave.win_condition.l1 = "locator";
		pchar.quest.Ascold_GuadeloupeToCave.win_condition.l1.location = "Guadeloupe_Cave";
		pchar.quest.Ascold_GuadeloupeToCave.win_condition.l1.locator_group = "item";
		pchar.quest.Ascold_GuadeloupeToCave.win_condition.l1.locator = "detector1";
		pchar.quest.Ascold_GuadeloupeToCave.function = "AscoldGuadeloupeToCave";
}

void AscoldGuadeloupeToCave(string qName)
{
            pchar.questTemp.Ascold = "Ascold_NotEnterFoundGrave";
            DoQuestCheckDelay("TalkSelf_Quest", 0.1); //диалог сам-на-сам
}
void Ascold_GoCave(string qName)// в пещере
{
	pchar.quest.Ascold_GoCave.win_condition.l1 = "locator";
	pchar.quest.Ascold_GoCave.win_condition.l1.location = "Guadeloupe_Cave";
	pchar.quest.Ascold_GoCave.win_condition.l1.locator_group = "item";
	pchar.quest.Ascold_GoCave.win_condition.l1.locator = "button01";
	pchar.quest.Ascold_GoCave.function = "AscoldGoCave_1";
}
void AscoldGoCave_1(string qName)// в пещере
{
                     PlaySound("VOICE\Russian\gotica\SFX\AMBIENTTONE_03_DARK.wav");
                     LAi_SetActorType(pchar);
                     DoQuestFunctionDelay("AscoldGoCave_2", 0.1);
}
void AscoldGoCave_2(string qName)// в пещере
{
          LAi_SetBarmanType(pchar);
          DoQuestFunctionDelay("AscoldGoCave_3", 4.0);
}
void AscoldGoCave_3(string qName)// в пещере
{
         PlaySound("VOICE\Russian\GOTHIC\GG\SCOPENSLASTDOOR.wav");
         LAi_SetBarmanType(pchar);
         DoQuestFunctionDelay("AscoldGoCave_4", 7.0);
}
void AscoldGoCave_4(string qName)// в пещере
{
         PlaySound("VOICE\Russian\gotica\SFX\AIRBAG_OUT.wav");
         LocatorReloadEnterDisable("Guadeloupe_Cave", "reload3_back", false);
         DoQuestFunctionDelay("AscoldGoCave_5", 3.5);
}
void AscoldGoCave_5(string qName)// в пещере
{
         PlaySound("VOICE\Russian\gotica\SFX\MFX_SLEEP_CAST.wav");
         TakeItemFromCharacter(pchar, "Rock_letter");
         DoQuestFunctionDelay("AscoldGoCave_6", 4.0);
}
void AscoldGoCave_6(aref _location)// в пещере
{
		//==> перебиваем иниты пещеры Гваделупы
		locations[FindLocation("Guadeloupe_Cave")].reload.l1.name = "reload3_back"; 
		locations[FindLocation("Guadeloupe_CaveEntrance")].reload.l1.emerge = "reload3"; 
		//==> перемещаемся на reload5
         DoQuestFunctionDelay("AscoldGoCave_7", 2.0);
}
void AscoldGoCave_7()// в пещере
{
                  StartPostVideo("Teleport", 1);
                  DoQuestFunctionDelay("Ascold_OpenTheGrave", 0.1);
}
 void Ascold_OpenTheGrave(string qName)
{
	DoReloadCharacterToLocation("Guadeloupe_Cave", "reload", "reload5");
                   LAi_SetPlayerType(pchar); 
                   sld = characterFromId("Ascold");
	sld.dialog.currentnode = "Found_Grave";
}
void Ascold_Open_rabble(string qName)// в пещере
{
	pchar.quest.Ascold_Open_rabble.win_condition.l1 = "locator";
	pchar.quest.Ascold_Open_rabble.win_condition.l1.location = "Guadeloupe_Cave";
	pchar.quest.Ascold_Open_rabble.win_condition.l1.locator_group = "item";
	pchar.quest.Ascold_Open_rabble.win_condition.l1.locator = "button02";
	pchar.quest.Ascold_Open_rabble.function = "AscoldOpen_1";
}
void AscoldOpen_1(string qName)// в пещере
{
                     PlaySound("VOICE\Russian\gotica\SFX\SLEEPERCAVE_01.wav");
                     PlaySound("VOICE\Russian\gotica\SFX\ZOMBIE_01.wav");
                     LAi_SetActorType(pchar);
                     DoQuestFunctionDelay("AscoldOpen_2", 4.0);
}
void AscoldOpen_2(string qName)// в пещере
{
         PlaySound("VOICE\Russian\gotica\SFX\AIRBAG_IN.wav");
         TakeItemFromCharacter(pchar, "Ascold_rabble");
          LAi_ActorTurnToLocator(pchar, "item", "button02");
          LAi_SetBarmanType(pchar);
          DoQuestFunctionDelay("AscoldOpen_3", 4.0);
}
void AscoldOpen_3(string qName)// в пещере
{
         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
          LAi_SetBarmanType(pchar);
          DoQuestFunctionDelay("AscoldOpen_4", 3.0);
}
void AscoldOpen_4(aref _location)
{
                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
			sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "Skel"+i, "skeleton", "skeleton", 30, PIRATE, 0, true, "quest"));	
			FantomMakeCoolFighter(sld, 30, 85, 85, "topor_03", "pistol3", "bullet", 100);  
		sld.monster = true; // признак нежити
		sld.sex = "Skeleton"; 
		sld.viper = true;
            LAi_SetWarriorType(sld);				
			LAi_group_MoveCharacter(sld, "EnemyFight");				
            ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "Ascold_InGraveAfterFight");
        chrDisableReloadToLocation = true;
}

void Ascold_LeifIsDead(string qName)
{
                LocatorReloadEnterDisable("Guadeloupe_Cave", "reload3_back", false);
}

void LeifIsDead(string qName)
{
	pchar.quest.LeifIsDead.win_condition.l1 = "locator";
	pchar.quest.LeifIsDead.win_condition.l1.location = "Guadeloupe_Cave";
	pchar.quest.LeifIsDead.win_condition.l1.locator_group = "reload";
	pchar.quest.LeifIsDead.win_condition.l1.locator = "reload5";
	pchar.quest.LeifIsDead.function = "Ascold_LandSkelAttack";
}

void Ascold_LandSkelAttack(string qName) // Мумия атакует
{
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	sld = characterFromId("LeifEricson");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	DoQuestFunctionDelay("Ascold_MummySkelAttack", 14.0);
	CreateLocationParticles("large_smoke", "goto", "goto"+i, 0.9, 0, 0, "");
}

void Ascold_MummySkelAttack(string qName)
{
                Log_QuestInfo("Со скелетами надо подраться.");
	PlaySound("VOICE\Russian\gotica\SFX\ZOM_DIE01.wav");
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (int i=1; i<=3; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("LeifEricson_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);
		sld.monster = true; // признак нежити
		sld.sex = "Skeleton"; 
		sld.viper = true;
		LAi_SetWarriorType(sld);
		ChangeCharacterAddressGroup(sld, "Guadeloupe_Cave", "goto", "goto"+i);
	CreateLocationParticles("large_smoke", "goto", "goto"+i, 0.9, 0, 0, "");
		LAi_group_MoveCharacter(sld, "EnemyFight");
			}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "Ascold_LandSkelDie");
	LAi_SetFightMode(pchar, true);
	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "Guadeloupe_Cave", "reload", "reload5");
	pchar.quest.Ascold_MummySkelAttack.win_condition.l1 = "locator";
	pchar.quest.Ascold_MummySkelAttack.win_condition.l1.location = "Guadeloupe_Cave";
	pchar.quest.Ascold_MummySkelAttack.win_condition.l1.locator_group = "reload";
	pchar.quest.Ascold_MummySkelAttack.win_condition.l1.locator = "reload5";
	pchar.quest.Ascold_MummySkelAttack.function = "Ascold_MummySkelAttack_1";

	}
}
void Ascold_MummySkelAttack_1(string qName) // в пещере
{
           PlaySound("VOICE\Russian\gotica\SFX\ZOM_DIE02.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////Квест, уничтожение экспедиции по Аскольду
//////////////////////////////////////////////////////////////////////////////////////

void Temple_ArriveTohore(string qName) // прибыли в бухту Аматике
{
	pchar.GenQuest.Hunter2Pause = true; // ОЗГи на паузу
	chrDisableReloadToLocation = true;//закрыть локацию
	pchar.GenQuest.CannotWait = true;//запрет ожидания
	// устанавливаем солдат+офицер
	int iRank = 25+MOD_SKILL_ENEMY_RATE+5;
	int iScl = 70;
	iTotalTemp = 6;
	if (CheckAttribute(pchar, "questTemp.Temple.Ascold")) iTotalTemp = 10;
	for (int i=1; i<=iTotalTemp; i++)
	{
		if (i == 1)
		{
			sld = GetCharacter(NPC_GenerateCharacter("Temple_Oursoldier_"+i, "mercen_24", "man", "man", iRank+5, FRANCE, -1, true, "soldier"));
			FantomMakeCoolFighter(sld, iRank+5, iScl+5, iScl+5, "blade_21", "pistol4", "bullet", iScl*2+100);
			sld.dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
			sld.dialog.currentnode = "seashore_officer";
			if (CheckAttribute(pchar, "questTemp.Temple.Ascold")) sld.dialog.currentnode = "seashore_officer_0";
		}
		else
		{
			if (i == 2 || i == 3)
			{
				sld = GetCharacter(NPC_GenerateCharacter("Temple_Oursoldier_"+i, "mush_ctz_"+(4+rand(2)), "man", "mushketer", iRank, FRANCE, -1, false, "soldier"));
				FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket1", "cartridge", iScl*2+50);
			}
			else
			{
				sld = GetCharacter(NPC_GenerateCharacter("Temple_Oursoldier_"+i, "citiz_"+(31+rand(9)), "man", "man", iRank, FRANCE, -1, true, "soldier"));
				FantomMakeCoolFighter(sld, iRank, iScl, iScl, RandPhraseSimple("blade_10","blade_11"), "pistol1", "bullet", iScl*2+50);
			}
			LAi_CharacterDisableDialog(sld);
		}
		ChangeCharacterAddressGroup(sld, "Shore9", "goto", "goto1");
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}
}

void Temple_officerGoJungle(string qName) // джунгли перед пирамидой
{
	chrDisableReloadToLocation = true;
	for(int i=1; i<=iTotalTemp; i++)
	{
		if (GetCharacterIndex("Temple_Oursoldier_"+i) != -1)
		{
			sld = characterFromID("Temple_Oursoldier_"+i);
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload3_back", "none", "", "", "", 7); // 160912
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
	}
	DoQuestCheckDelay("Temple_MCSoldiersReset", 11.0); // 160912
}

void Ascold_fightInsideTemple(string qName)
{

	if (MOD_SKILL_ENEMY_RATE > 5) chrDisableReloadToLocation = true;
	characters[GetCharacterIndex("Ascold")].dialog.currentnode = "Ascold_KilledTemple";
	AddQuestRecord("Ascold", "11");
	AddQuestUserData("Ascold", "sSex", GetSexPhrase("","а"));
    //--------------------------- испанцы ------------------------------
	LAi_group_Delete("EnemyFight");
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
 	sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_off", "off_spa_5", "man", "man", Rank, SPAIN, -1, true, "soldier"));
    FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_24", "pistol4", "bullet", 120);	
	LAi_SetActorType(sld);
	GiveItem2Character(sld, "sculMa1");
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
    LAi_group_MoveCharacter(sld, "EnemyFight");	
	ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto9");
	for (i=1; i<=8; i++)
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==12) sTemp = "off_spa_6";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, -1, true, "soldier"));
        FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_23", "pistol3", "bullet", 50);
		DeleteAttribute(sld, "SuperShooter");
		sld.BreakTmplAndFightGroup = true;
		LAi_SetActorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);
    }
    for (i=10; i<=13; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_spa_"+(rand(5)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);		
		sld.MusketerDistance = 0;
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "Temple_OpenTheDoors");
	DoQuestFunctionDelay("Ascold_actorSetWarrior", 2.5);

	// наши из засады
	for(i=1; i<=iTotalTemp; i++)
	{
		if (GetCharacterIndex("Temple_Oursoldier_"+i) != -1)
		{
		sld = characterFromID("Temple_Oursoldier_"+i);
		if (CheckAttribute(pchar, "questTemp.Temple.Ascold"))
		{
		if (i < 8) ChangeCharacterAddressGroup(sld, "Temple_Inside", "reload", "reload1");
		}
		else ChangeCharacterAddressGroup(sld, "Temple_Inside", "reload", "reload1");
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "");
	LAi_SetFightMode(pchar, true);
	}
}

void Ascold_actorSetWarrior(string qName)
{
	iTemp = GetCharacterIndex("SpaEnemy_off");
	if (iTemp != -1 && !LAi_IsDead(&characters[iTemp])) LAi_SetWarriorTypeNoGroup(&characters[iTemp]);
	for (i=1; i<=8; i++)
    {
		iTemp = GetCharacterIndex("SpaEnemy_"+i);	
		if (iTemp != -1 && !LAi_IsDead(&characters[iTemp])) LAi_SetWarriorTypeNoGroup(&characters[iTemp]);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////Квест, поиски индийских побрякушек по Аскольду
//////////////////////////////////////////////////////////////////////////////////////

void Roseau_night_0(string qName)
{
                pchar.GenQuest.CannotWait = true;//запрет ожидания
	bDisableFastReload = true;//закрыть переход
                 AddQuestRecord("Ascold", "3_0");
}

void Roseau_night(string qName)
{ 
	pchar.quest.Roseau_night.win_condition.l1 = "locator";
	pchar.quest.Roseau_night.win_condition.l1.location = "Roseau_town";		                        pchar.quest.Roseau_night.win_condition.l1.locator_group = "reload";
	pchar.quest.Roseau_night.win_condition.l1.locator = "reload1_back";
	pchar.quest.Roseau_night.win_condition.l2 = "HardHour";
	pchar.quest.Roseau_night.win_condition.l2.hour = 0.01;
	pchar.quest.Roseau_night.function = "Roseau_night_1";
	SetFunctionTimerCondition("Roseau_night_2", 0, 0, 1, false);

}

void Roseau_night_1(string qName)
{
	pchar.quest.Roseau_night_1.win_condition.l1 = "locator";
	pchar.quest.Roseau_night_1.win_condition.l1.location = "Roseau_port";		                        pchar.quest.Roseau_night_1.win_condition.l1.locator_group = "reload";
	pchar.quest.Roseau_night_1.win_condition.l1.locator = "reload2_back";
	pchar.quest.Roseau_night_1.function = "Roseau_night_port";
}

void Roseau_night_2(string qName)
{
	LocatorReloadEnterDisable("Roseau_town", "reload1_back", false);//город открыть
	LocatorReloadEnterDisable("Roseau_town", "gate_back", false);//город открыть
}

void Roseau_night_port(string qName) // ночью в порту
{
                     PlaySound("VOICE\Russian\gotica\SFX\MYSTERY_07.wav");
	     LAi_SetActorType(pchar);
                     DoQuestFunctionDelay("night_port_1", 0.3);

	ref chr;
	for(int n = 0; n < MAX_CHARACTERS; n++)
	{
		makeref(chr, Characters[n]);
		if (CheckAttribute(chr, "patrol") && chr.city == "Roseau_port")
		{
			chr.lifeday = 0;
			ChangeCharacterAddressGroup(chr, "none", "", "");
		}
	}
}
void night_port_1()
{
                     PlaySound("VOICE\Russian\gotica\SFX\CS_PRAYER_ORCVISION.wav");
	LAi_ActorGoToLocator(pchar, "goto", "goto14", "", -1);
	string sQuest = "";
	string VaterskelName[10];
	VaterskelName[0] = "Vaterskeletcap";
	VaterskelName[1] = "VaterSkel_1";
	VaterskelName[2] = "VaterSkel_2";
	VaterskelName[3] = "VaterSkel_3";
	VaterskelName[4] = "VaterSkel_4";
	VaterskelName[5] = "VaterSkel_1";
	VaterskelName[6] = "VaterSkel_2";
	VaterskelName[7] = "VaterSkel_3";
	VaterskelName[8] = "VaterSkel_4";
	VaterskelName[9] = "VaterSkel_1";
	for (i=0; i<10; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("VaterSkel_" + i, VaterSkelName[i], "skeleton", "skeleton", 35, PIRATE, 0, true, "quest"));
		sld.gotoGroup = "reload";
		sld.gotoLocator = "reload3";
		LAi_SetActorType(sld);
		ChangeCharacterAddressGroup(sld, "Roseau_port", "randitem", "randitem2");
	}
	DoQuestFunctionDelay("night_port_2", 0.2);
}

void night_port_2(string qName)
{
                     PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
	for (i=0; i<10; i++)
	{
	sld = characterFromId("VaterSkel_" + i);
                     LAi_ActorGoToLocation(sld, "reload", "reload3", "none", "", "", "", 60.0);
	}
	DoQuestFunctionDelay("night_port_3", 10.0);
}
void night_port_3(string qName)
{
                    PlaySound("VOICE\Russian\gotica\SFX\CS_PRAYER_ORCVISION.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
	LAi_ActorTurnToLocator(pchar, "goto", "goto1");
	DoQuestFunctionDelay("night_port_4", 15.0);
}
void night_port_4(string qName)
{
                    PlaySound("VOICE\Russian\gotica\SFX\MFX_BREATHOFDEATH_INVEST.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav");
	LAi_ActorTurnToLocator(pchar, "goto", "goto12");
	DoQuestFunctionDelay("night_port_5", 25.0);	
}
void night_port_5(string qName)
{
                    PlaySound("VOICE\Russian\gotica\SFX\MYSTERY_03.wav");
	LAi_SetPlayerType(pchar);
	LocatorReloadEnterDisable("Roseau_port", "reload3", false);//катакомбы откроем
                 DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bDisableFastReload = false;//открыть переход
	         DoQuestFunctionDelay("ThreeObjectDominicaDungeon_5", 0.3);

	pchar.quest.ThreeObject_Dominica_Dungeon.win_condition.l1 = "locator";
	pchar.quest.ThreeObject_Dominica_Dungeon.win_condition.l1.location = "Dominica_Dungeon";
	pchar.quest.ThreeObject_Dominica_Dungeon.win_condition.l1.locator_group = "reload";
	pchar.quest.ThreeObject_Dominica_Dungeon.win_condition.l1.locator = "reload1";
	pchar.quest.ThreeObject_Dominica_Dungeon.function = "ThreeObjectDominicaDungeon";
}
void ThreeObjectDominicaDungeon()
{
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
	DoQuestFunctionDelay("ThreeObjectDominicaDungeon_1", 35.0);
}	
void ThreeObjectDominicaDungeon_1(string qName)
{
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\CS_PRAYER_ORCVISION.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	for (int i=1; i<=10; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("VaterSkel_1_"+i, "VaterSkel_"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	LAi_SetWarriorType(sld);
	ChangeCharacterAddressGroup(sld, "Dominica_Dungeon", "monsters", "monster"+i);
	CreateLocationParticles("large_smoke", "monsters", "monster"+i, 0.9, 0, 0, "");
	LAi_group_MoveCharacter(sld, "EnemyFight");
			}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "ThreeObject_LandVaterskelDie");
	LAi_SetFightMode(pchar, true);

	pchar.quest.ThreeObjectDominicaDungeon_1.win_condition.l1 = "locator";
	pchar.quest.ThreeObjectDominicaDungeon_1.win_condition.l1.location = "Dominica_Dungeon";
	pchar.quest.ThreeObjectDominicaDungeon_1.win_condition.l1.locator_group = "box";
	pchar.quest.ThreeObjectDominicaDungeon_1.win_condition.l1.locator = "private1";
	pchar.quest.ThreeObjectDominicaDungeon_1.function = "ThreeObjectDominicaDungeon_3";

}

void ThreeObjectDominicaDungeon_3()
{
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
	DoQuestFunctionDelay("ThreeObjectDominicaDungeon_4", 20.0);
}
void ThreeObjectDominicaDungeon_4(string qName)
{
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\CS_PRAYER_ORCVISION.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (int i=1; i<=10; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("Vaterskel_2_"+i, "Vaterskel_"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	LAi_SetWarriorType(sld);
	ChangeCharacterAddressGroup(sld, "Dominica_Dungeon", "monsters", "monster"+i);
	CreateLocationParticles("large_smoke", "monsters", "monster"+i, 0.9, 0, 0, "");
	LAi_group_MoveCharacter(sld, "EnemyFight");
			}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "ThreeObject_LandVaterskelDie");
	LAi_SetFightMode(pchar, true);
}

void ThreeObjectDominicaDungeon_5()
{
	pchar.quest.ThreeObjectDominicaDungeon_2.win_condition.l1 = "locator";
	pchar.quest.ThreeObjectDominicaDungeon_2.win_condition.l1.location = "Dominica_Dungeon";
	pchar.quest.ThreeObjectDominicaDungeon_2.win_condition.l1.locator_group = "box";
	pchar.quest.ThreeObjectDominicaDungeon_2.win_condition.l1.locator = "private4";
	pchar.quest.ThreeObjectDominicaDungeon_2.function = "ThreeObjectDominicaDungeon_6";
}

void ThreeObjectDominicaDungeon_6()
{
                    PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
                    PlaySound("VOICE\Russian\gotica\SFX\EARTHQUAKE.wav");
                    AddQuestRecord("Ascold", "3_1");

	pchar.quest.ThreeObjectDominicaDungeon_6.win_condition.l1 = "locator";
	pchar.quest.ThreeObjectDominicaDungeon_6.win_condition.l1.location = "Dominica_Dungeon";
	pchar.quest.ThreeObjectDominicaDungeon_6.win_condition.l1.locator_group = "reload";
	pchar.quest.ThreeObjectDominicaDungeon_6.win_condition.l1.locator = "reload2";
	pchar.quest.ThreeObjectDominicaDungeon_6.function = "ThreeObjectDominicaDungeon_key";
}

void ThreeObjectDominicaDungeon_key()
{
	PlaySound("interface\key.wav");//щелк!
	RemoveItems(PChar, "key1", 1);
	LocatorReloadEnterDisable("Dominica_Dungeon", "reload2", false);//дверку приоткроем
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Начало наёмники в городах
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//==> грабители
void BirglarsPirateResidence(string qName)
{
	PlaySound("interface\key.wav");//щелк!
	RemoveItems(PChar, "key1", 1);
	LocatorReloadEnterDisable("SantaCatalina_PirateHouse", "reload2", false);//дверку приоткроем

}
void Gothic_BookFencing() // взяли книгу
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_BookFencing_1", 3.5);
}
void Gothic_BookFencing_1() // взяли книгу
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_BookFencing_2", 3.5);
}
void Gothic_BookFencing_2() // прочли книгу
{
 	PlaySound("Interface\CHAPTER.wav");
	AddCharacterExpToSkill(pchar, "FencingL", 500);
	AddCharacterExpToSkill(pchar, "FencingS", 500);
	AddCharacterExpToSkill(pchar, "FencingH", 500);
	AddCharacterExpToSkill(pchar, "Pistol", 500);
	AddQuestRecordInfo("BookFencing", "1");
}

void Birglars_Info_Inquisition(string qName)
{
           LocatorReloadEnterDisable("VillaAlegria_prison", "reload_jail", false);//откроем тюрьму
            //chrDisableReloadToLocation = true;
            sld = GetCharacter(NPC_GenerateCharacter("Francisco", "abbat", "man", "man_B", 15, SPAIN, 0, false, "quest"));
            sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_2.c";
             sld.name 	= "Франциско";
             sld.lastname = "де Сан-Агостиньо";
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto14");
             LAi_SetWarriorType(sld);
             LAi_SetActorTypeNoGroup(sld);
             LAi_ActorDialog(sld, pchar, "", -1, 0);
             pchar.questTemp.GothicLee = "Francisco";

            sld = GetCharacter(NPC_GenerateCharacter("Orc", "Orc", "Orc", "Orc", 15, PIRATE, 0, false, "quest"));
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto9");
           sld.Dialog.Filename = "Gothic_Quest\npc\Monster.c";
            sld.dialog.currentnode   = "First time_ORC";
             LAi_SetActorType(sld);

            sld = GetCharacter(NPC_GenerateCharacter("skeleton", "skel"+(rand(3)+1), "skeleton", "skeleton", 15, PIRATE, 0, false, "quest"));
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto11");
            sld.Dialog.Filename = "Gothic_Quest\npc\Monster.c";
            sld.dialog.currentnode   = "First time_skel";
             LAi_SetActorType(sld);

            sld = GetCharacter(NPC_GenerateCharacter("VaterSkel", "VaterSkel_3", "skeleton", "skeleton", 15, PIRATE, 0, false, "quest"));
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto10");
            sld.Dialog.Filename = "Gothic_Quest\npc\Monster.c";
            sld.dialog.currentnode   = "First time_ZOMBIE";
             LAi_SetActorType(sld);

            sld = GetCharacter(NPC_GenerateCharacter("Monkey", "Monkey_2", "Monkey", "Monkey", 15, PIRATE, 0, false, "quest"));
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto7");
            sld.Dialog.Filename = "Gothic_Quest\npc\Monster.c";
            sld.dialog.currentnode   = "First time_MONKEY";
             LAi_SetActorType(sld);

            sld = GetCharacter(NPC_GenerateCharacter("Monkey", "Monkey_2", "Monkey", "Monkey", 15, PIRATE, 0, false, "quest"));
             ChangeCharacterAddressGroup(sld, "VillaAlegria_prison", "goto","goto8");
            sld.Dialog.Filename = "Gothic_Quest\npc\Monster.c";
            sld.dialog.currentnode   = "First time_MONKEY";
             LAi_SetActorType(sld);
}
void Birglars_fight(string qName)
{
	if (GetCharacterIndex("Berglar" + pchar.quest.(qName).city) != -1)
	{
		LAi_SetFightMode(pchar, false);
		LAi_LockFightMode(pchar, true);		
		sTemp = "berglar" + pchar.quest.(qName).city;
		pchar.questTemp.tugs.(sTemp) = "over";
		sld = characterFromId("Berglar" + pchar.quest.(qName).city);
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", 2.0, 0);
	}
}

void BerglarsDexter(string qName)
{
		sld = characterFromId("Dexterr");
	                   sld.dialog.filename   = "Gothic_Quest\Berglars.c";
	                   sld.dialog.currentnode = "Final_fight";
	                   LAi_SetImmortal(sld, false);
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", 5, 0);

	// находим
	pchar.quest.BerglarsDexter.win_condition.l1 = "item";
	pchar.quest.BerglarsDexter.win_condition.l1.item = "blade300";
	pchar.quest.BerglarsDexter.function = "Gothic_Pathfinder";

}
void BerglarsDexterFinal(string qName)
{
	pchar.GenQuest.Berglars = true;
	for(int i=1; i<=4; i++)
	{
		PlaySound("Ambient\LAND\door_02.wav");
	}
	LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
	// ранг и скиллы нападающих будут зависеть от степени осведомленности героя
	int iRank = 25+MOD_SKILL_ENEMY_RATE*2;
	if (CheckAttribute(pchar, "questTemp.Ksochitam.SQCapBookRead")) iRank = iRank-15;
	if (CheckAttribute(pchar, "questTemp.Tieyasal.MigelKnow")) iRank = iRank-15;
	if (iRank < 20) iRank = 20;
	int iScl = 90;
	if (CheckAttribute(pchar, "questTemp.Ksochitam.SQCapBookRead")) iScl = iScl-20;
	if (CheckAttribute(pchar, "questTemp.Tieyasal.MigelKnow")) iScl = iScl-20;
	if (iScl < 20) iScl = 20;
	int n = 2;
	if (MOD_SKILL_ENEMY_RATE > 5) n++;
	if (MOD_SKILL_ENEMY_RATE > 7) n++;
	if (MOD_SKILL_ENEMY_RATE > 9) n++;
	log_info("Врагов в засаде - "+n+" штук");

	for(i=1; i<=3; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("DexterFinal_mushketer_"+i, "mush_ctz_"+(rand(2)+10), "man", "mushketer", iRank, PIRATE, -1, false, "soldier"));
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket1", "cartridge", iScl*2+100);
		ChangeCharacterAddressGroup(sld, "church IM", "quest", "LLquest"+i);
		sld.MusketerDistance = 0;
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "Berglars_DexterFinal");
	LAi_SetFightMode(pchar, true);

}
void BerglarsDexterFinal_1(string qName)//открываем дверь
{
	//запускаем офицеров
	PlaySound("Ambient\LAND\door_01.wav");
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "church IM", "reload", "reload1");

	}

}
void BerglarsDexterFinalKey(string qName)//открываем дверь
{
	sld = CharacterFromID("Abuyin");//Даём нуду Абуину 1 предсказание
	sld.dialog.currentnode = "WEISSAGUNG_1";

	PlaySound("interface\key.wav");//щелк!
	RemoveItems(PChar, "key2", 1);
	LocatorReloadEnterDisable("church IM", "reload2_back", false);//дверку приоткроем
	pchar.GenQuestBox.Graveyard_crypt = true;
	pchar.GenQuestBox.Graveyard_crypt.box2.items.talisman6 = 1;
	pchar.GenQuestBox.Graveyard_crypt.box2.items.gold_dublon = 1;
	pchar.GenQuestBox.Graveyard_crypt.box3.items.recipe_totem_09 = 1;
	pchar.GenQuestBox.Graveyard_crypt.box3.items.recipe_berserker_potion = 1;
	pchar.GenQuestBox.Graveyard_crypt.box3.items.mechanic_tool = 1;
	pchar.GenQuestBox.Graveyard_crypt.box4.items.gold_dublon = 721;
	pchar.GenQuestBox.Graveyard_crypt.box4.items.sculMa3 = 1;
	pchar.GenQuestBox.Graveyard_crypt.box4.items.bussol = 1;
	pchar.GenQuestBox.Graveyard_crypt.box4.items.berserker_potion = 3;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Конец наёмники в городах
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  //кораблик с капитаном, который имеет мушкет несчастного мушкетера
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetMushketFromSeaToMap(string qName)
{
	sld = characterFromId("MushketCap");
	//в морскую группу кэпа
	string sGroup = "MushketCapShip";
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	sld.quest = "InMap"; //личный флаг искомого кэпа
	sld.cityShore = GetIslandRandomShoreId(GetArealByCityName(sld.city));
	sld.quest.targetCity = SelectAnyColony(sld.city); //определим колонию, в бухту которой он придет
	sld.quest.targetShore = GetIslandRandomShoreId(GetArealByCityName(sld.quest.targetCity));
	Log_TestInfo("Кэп с мушкетом вышел из: " + sld.city + " и направился в: " + sld.quest.targetShore);
	//==> на карту
	sld.mapEnc.type = "trade";
	//выбор типа кораблика на карте
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "Бриг ''Стрела''";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //дней доехать даем с запасом
	Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, daysQty);
	//меняем сроки проверки по Id кэпа в базе нпс-кэпов
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Генератор жемчужного промысла Sharp    начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sharp_loginNearIsland(string qName)
{	
	if (GetQuestPastMinutesParam("questTemp.Sharp") < 10) 
	{
		sld = &characters[GetCharacterIndex("Sharp")];
		LAi_SetCurHPMax(sld);
		sld.nation = pchar.nation; //нация Шарпа всегда как у ГГ
		SetCrewQuantityFull(sld);
		DeleteAttribute(sld, "ship.sails");// убрать дыры на парусах
		DeleteAttribute(sld, "ship.blots");
		DeleteAttribute(sld, "ship.masts");// вернуть сбитые мачты
		SetBaseShipData(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
		Group_AddCharacter("Sharp_Group", "Sharp");			
		Group_SetGroupCommander("Sharp_Group", "Sharp");
		Group_SetAddress("Sharp_Group", pchar.questTemp.Sharp.Island, "quest_ships", "quest_ship_"+(rand(1)+1));
		Group_SetTaskRunaway("Sharp_Group", PLAYER_GROUP);
		pchar.Quest.Sharp_landOver1.win_condition.l1 = "Location_Type";
		pchar.Quest.Sharp_landOver1.win_condition.l1.location_type = "town";
		pchar.Quest.Sharp_landOver1.function = "Sharp_Over";
		pchar.Quest.Sharp_landOver2.win_condition.l1 = "Location_Type";
		pchar.Quest.Sharp_landOver2.win_condition.l1.location_type = "seashore";
		pchar.quest.Sharp_landOver2.function = "Sharp_Over";
	    Pchar.quest.Sharp_mapOver.win_condition.l1 = "MapEnter";
		pchar.quest.Sharp_mapOver.function = "Sharp_Over";
	}
	else
	{
		AddQuestRecord("SharpPearl", "12");
		AddQuestUserData("SharpPearl", "sSex", GetSexPhrase("","а"));
		CloseQuestHeader("SharpPearl");
		pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
		pchar.questTemp.Sharp.brothelChance = rand(10);
	}
}

void Sharp_Over(string qName)
{
	group_DeleteGroup("Sharp_Group");
	pchar.quest.Sharp_landOver1.over = "yes";
	pchar.quest.Sharp_landOver2.over = "yes";
	pchar.quest.Sharp_mapOver.over = "yes";
	//даем запись в СЖ, если не нашел Шарпа
	if (pchar.questTemp.Sharp == "toSharp_going")
	{
		AddQuestRecord("SharpPearl", "4");
		CloseQuestHeader("SharpPearl");
		pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
		pchar.questTemp.Sharp.brothelChance = rand(10);
	}
}

//------------ жемчужный промысел ----------------
void SeaPearl_login(string qName)
{
	characters[GetCharacterIndex("Sharp")].DeckDialogNode = "NewDeckSharp"; //новая нода на палубу Шарпу
	pchar.quest.SeaPearl_Late.over = "yes";
	LAi_group_Delete("EnemyFight");
	group_DeleteGroup("DestinyGiftPearlGroup");
	iTemp = sti(pchar.questTemp.Sharp.PearlAreal.qtyShips);
	Group_FindOrCreateGroup("DestinyGiftPearlGroup");
	Group_SetType("PearlGroup", "trade");
	for (int j = 1; j <= iTemp; j++)
	{                
		sTemp = "PearlCapitain_" + j;
		sld = GetCharacter(NPC_GenerateCharacter(sTemp, "trader_"+(rand(15)+1), "man", "man", 10, PIRATE, 30, true, "quest"));	
		sld.Ship.Type = GenerateShip(SHIP_TARTANE, false);
		SetRandomNameToShip(sld);
		SetBaseShipData(sld);
		SetCrewQuantityFull(sld);
		Fantom_SetBalls(sld, "pirate");
		sld.ShipTaskLock = true;
		sld.Abordage.Enable = false;
		sld.SinkTenPercent = true; //экономия в АИ шипов
		sld.PearlTartane = true; //тартана ловцов жемчуга, можно грабить
		LAi_group_MoveCharacter(sld, "EnemyFight");
		Group_AddCharacter("DestinyGiftPearlGroup", sTemp);
	}
    // ==> стравливание
	Group_SetGroupCommander("DestinyGiftPearlGroup", "PearlCapitain_1");			
	Group_SetTaskRunaway("DestinyGiftPearlGroup", PLAYER_GROUP);
	Group_SetAddress("DestinyGiftPearlGroup", pchar.questTemp.Sharp.PearlAreal.Island, "quest_ships", pchar.questTemp.Sharp.PearlAreal.locator);	
	Group_LockTask("DestinyGiftPearlGroup");
	pchar.quest.SeaPearl_DieHard1.win_condition.l1 = "ExitFromLocation";
	pchar.quest.SeaPearl_DieHard1.win_condition.l1.location = pchar.questTemp.Sharp.PearlAreal.Island;
	pchar.quest.SeaPearl_DieHard1.function = "SeaPearl_DieHard";
	Pchar.quest.SeaPearl_DieHard2.win_condition.l1 = "MapEnter";
	pchar.quest.SeaPearl_DieHard2.function = "SeaPearl_DieHard";
}

void SeaPearl_Late(string qName)
{	
	pchar.quest.SeaPearl_login.over = "yes";
	AddQuestRecord("SharpPearl", "9");
	AddQuestUserData("SharpPearl", "sSex", GetSexPhrase("","а"));
	AddQuestUserData("SharpPearl", "iDay", FindRussianDaysString(sti(pchar.questTemp.Sharp.PearlAreal.terms)));
	AddQuestUserData("SharpPearl", "sTarget", GetConvertStr(pchar.questTemp.Sharp.PearlAreal.Shore, "LocLables.txt"));
	pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
	pchar.questTemp.Sharp.brothelChance = rand(10);
	DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
}

void SeaPearl_DieHard(string qName)
{
	group_DeleteGroup("DestinyGiftPearlGroup");
	pchar.quest.SeaPearl_DieHard1.over = "yes";
	pchar.quest.SeaPearl_DieHard2.over = "yes";
	if (pchar.questTemp.Sharp == "SeaPearl_success")
	{	//успешное нападение
		AddQuestRecord("SharpPearl", "7");
		AddQuestUserData("SharpPearl", "iSmall", pchar.questTemp.Sharp.PearlAreal.SmallPearlQty);
		AddQuestUserData("SharpPearl", "iBig", pchar.questTemp.Sharp.PearlAreal.BigPearlQty);
	}
	else
	{	//неудачное нападение
		AddQuestRecord("SharpPearl", "8");
		AddQuestUserData("SharpPearl", "sSex", GetSexPhrase("ел","ла"));
		AddQuestUserData("SharpPearl", "sSex1", GetSexPhrase("","а"));
	}
	pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
	pchar.questTemp.Sharp.brothelChance = rand(10);
	DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
	CloseQuestHeader("SharpPearl");
}

void SharpSeekSpy_loginSpy(string qName)
{
	if (rand(1) && !IsDay())
	{
		LAi_group_Delete("EnemyFight");
		AddQuestRecord("SharpPearl_SeekSpy", "3");
		sld = GetCharacter(NPC_GenerateCharacter("Emillio", "mercen_14", "man", "man", 20, SPAIN, 0, true, "quest"));
		sld.name = "Эмилио";
		sld.lastname = "Гарсиа";
		sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
		sld.dialog.currentnode = "SharpSeekSpy_Emi";
		LAi_SetActorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto5");
		rCharacter = GetCharacter(NPC_GenerateCharacter("QuestMan_5", "pirate_6", "man", "man", 20, SPAIN, 0, true, "quest"));
		rCharacter.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
		rCharacter.dialog.currentnode = "SharpSeekSpy_fri";
		LAi_SetActorType(rCharacter);
		LAi_group_MoveCharacter(rCharacter, "EnemyFight");
		ChangeCharacterAddressGroup(rCharacter, pchar.location, "goto", "goto6");
		DoQuestCheckDelay("CannotFightCurLocation", 1.0);
		pchar.questTemp.Sharp.SeekSpy = "inDelNorte";
		pchar.quest.SharpSeekSpy_script.win_condition.l1 = "locator";
		pchar.quest.SharpSeekSpy_script.win_condition.l1.location = "Shore55";
		pchar.quest.SharpSeekSpy_script.win_condition.l1.locator_group = "quest";
		pchar.quest.SharpSeekSpy_script.win_condition.l1.locator = "SharpSeekSpy";
		pchar.quest.SharpSeekSpy_script.function = "SharpSeekSpy_script";
	}
	else
	{
		SetTimerFunction("SharpSeekSpy_again", 0, 0, 3);
	}
}

void SharpSeekSpy_script(string qName)
{
	if (GetCharacterIndex("Emillio") != -1)
	{
		LAi_ActorTurnToCharacter(characterFromId("QuestMan_5"), pchar);
		sld = characterFromId("Emillio");
		sld.dialog.currentnode = "SharpSeekSpy_Emi";
		LAi_ActorDialog(sld, pchar, "", 0, 0);
	}
	else
	{
		pchar.questTemp.Sharp.SeekSpy = "over";
	}
}

void SharpSeekSpy_again(string qName)
{
	pchar.quest.SharpSeekSpy_loginSpy.win_condition.l1 = "location";
	pchar.quest.SharpSeekSpy_loginSpy.win_condition.l1.location = "Shore55";
	pchar.quest.SharpSeekSpy_loginSpy.function = "SharpSeekSpy_loginSpy";	
}

void SharpSeekSpy_caveDialog()
{
	sld = characterFromId("QuestMan_5");
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "SharpSeekSpy_fri";
	LAi_ActorDialog(sld, pchar, "", 0, 0);
}

void SharpSeekSpy_caveDialog_2()
{
	sld = characterFromId("Emillio");
	sld.dialog.currentnode = "SharpSeekSpy_Emi_1";
	LAi_ActorDialog(sld, pchar, "", 0, 0);
}

void SharpSeekSpy_caveDialog_3()
{
	DoQuestCheckDelay("CanFightCurLocation", 0.0);
	sld = characterFromId("Emillio");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	sld = characterFromId("QuestMan_5");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
    pchar.quest.SharpSeekSpy_afterFight.win_condition.l1 = "NPC_Death";
	pchar.quest.SharpSeekSpy_afterFight.win_condition.l1.character = "Emillio";
    pchar.quest.SharpSeekSpy_afterFight.win_condition.l2 = "NPC_Death";
	pchar.quest.SharpSeekSpy_afterFight.win_condition.l2.character = "QuestMan_5";
	pchar.quest.SharpSeekSpy_afterFight.function = "SharpSeekSpy_afterFight";
}

void SharpSeekSpy_afterFight(string qName)
{
	AddQuestRecord("SharpPearl_SeekSpy", "4");
	pchar.questTemp.Sharp.SeekSpy = "alwaysKnow";
	pchar.questTemp.Sharp = "seekSharp"; //можно снова поискать Шарпа
	CloseQuestHeader("SharpPearl");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Генератор жемчужного промысла Sharp   конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  бриг Черная Горгулья начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void BlueBird_inCavern(string qName)
{
	pchar.questTemp.BlueBird = "seenCarriers";
	DoQuestCheckDelay("TalkSelf_Quest", 0.2); //диалог сам-на-сам
}

void BlueBird_endCaveDialog()
{
	LAi_SetActorType(pchar);
	LAi_ActorTurnByLocator(pchar, "goto", "goto1");
	string sQuest = "";
	string CarrierName[10];
	CarrierName[0] = "GenresBag1";
	CarrierName[1] = "GenresBag2";
	CarrierName[2] = "GenresBarrel1";
	CarrierName[3] = "GenresBarrel2";
	CarrierName[4] = "GenresBarrelTop1";
	CarrierName[5] = "GenresBarrelTop2";
	CarrierName[6] = "GenresBottle1";
	CarrierName[7] = "GenresBottle2";
	CarrierName[8] = "GenresChest1";
	CarrierName[9] = "GenresChest2";
	for (i=0; i<10; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("Carrier_" + i, CarrierName[i], "man", "genres", 35, PIRATE, 0, true, "quest"));
		sld.gotoGroup = "reload";
		sld.gotoLocator = "reload1_back";
		LAi_SetCarrierType(sld);
		ChangeCharacterAddressGroup(sld, "Bermudes_Cavern", "reload", "reload2");
	}
	DoQuestFunctionDelay("BlueBird_endCaveScript", 33.0);
}

void BlueBird_endCaveScript(string qName)
{
	LAi_LocationDisableMonstersGen("Bermudes_Cavern", false); //монстров генерить
	LAi_LocationDisableOfficersGen("Bermudes_Cavern", false); //офицеров пускать
	for (i=0; i<10; i++)
	{
		sld = characterFromId("Carrier_" + i);
		ChangeCharacterAddress(sld, "none", "");
	}
	AddQuestRecord("Xebeca_BlueBird", "6");
	AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("ел","ла"));
	LAi_SetPlayerType(pchar);
	pchar.questTemp.BlueBird = "toSeaBattle";
	pchar.quest.BlueBird_seaBattle.win_condition.l1 = "location";
	pchar.quest.BlueBird_seaBattle.win_condition.l1.location = "Bermudes";
	pchar.quest.BlueBird_seaBattle.function = "BlueBird_seaBattle";	
}

void BlueBird_seaBattle(string qName)
{
        int iRank = 15+MOD_SKILL_ENEMY_RATE;
        int iScl = 50;
	LAi_group_Delete("EnemyFight");
	group_DeleteGroup("BlueBird_Group");
	sld = GetCharacter(NPC_GenerateCharacter("BlueBirdCapitain", "QuestCaptain", "man", "man", iRank, PIRATE, -1, true, "quest")); // patch
	sld.name 	= "Джа";
      sld.lastname = "Престон";
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.dialog.filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "BlueBirdCapitain";
	FantomMakeSmallSailor(sld, SHIP_VALCIRIA_QUEST, "Чёрная Горгулья", CANNON_TYPE_CULVERINE_LBS18, 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "blade38", "pistol6", "cartridge", 50);
	sld.greeting = "Gr_BlueBirdCapitain";
	SetSelfSkill(sld, 50, 50, 50, 50, 50);
	SetShipSkill(sld, 35, 10, 45, 45, 45, 35, 45, 35, 25);
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 2;
	DeleteAttribute(sld, "AboardToFinalDeck");
	sld.AlwaysSandbankManeuver = true;
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.SuperShooter = true;
	sld.DontClearDead = true;
	sld.AlwaysEnemy = true;
	sld.SuperShooter  = true;
	sld.equip.blade = "blade38";
	sld.Abordage.Enable = true;
	sld.SuperShooter  = true;
	sld.Ship.Name = "Чёрная Горгулья"; 
	sld.equip.gun = "pistol6";
	sld.DontRansackCaptain = true;
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	GiveItem2Character(sld, "indian5");
	GiveItem2Character(sld, "jewelry15");
	GiveItem2Character(sld, "icollection");
	GiveItem2Character(sld, "spyglass6");
	EquipCharacterbyItem(sld, "spyglass6");
	sld.Ship.Type = GenerateShipExt(SHIP_VALCIRIA_QUEST, true, sld); 
	sld.Ship.Stopped = true; 
	sld.Ship.Mode = "mercenary";
	sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
	SetCrewQuantityFull(sld);
	sld.ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
	SetCharacterGoods(sld, GOOD_BALLS, 500);
	SetCharacterGoods(sld, GOOD_GRAPES, 500);
	SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
	SetCharacterGoods(sld, GOOD_BOMBS, 500);
	SetCharacterGoods(sld, GOOD_FOOD, 300); 
	SetCharacterGoods(sld, GOOD_POWDER, 2500);
	SetCharacterGoods(sld, GOOD_WEAPON, 300);
	SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
	SetCharacterGoods(sld, GOOD_RUM, 150); 
	SetCharacterGoods(sld, GOOD_PLANKS, 50);
	SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
	SetCharacterGoods(sld, GOOD_SILVER, 500);
	SetCharacterGoods(sld, GOOD_GOLD, 250);
	UpgradeShipParameter(sld, "Capacity");
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "HP");//корпус
	UpgradeShipParameter(sld, "SpeedRate");//скорость
	UpgradeShipParameter(sld, "MaxCrew"); 
	sld.ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
	LAi_SetCharacterUseBullet(sld, "cartridge");
      TakeNItems(sld, "bullet", 50);
	TakeNItems(sld, "cartridge", 50);
	TakeNItems(sld, "grapeshot", 50);
	TakeNItems(sld, "GunPowder", 100);
	GiveItem2Character(sld, "recipe_totem_13");
	GiveItem2Character(sld, "totem_13");
	LAi_group_MoveCharacter(sld, "EnemyFight");
	Group_AddCharacter("BlueBird_Group", "BlueBirdCapitain");			
	Group_SetType("BlueBird_Group", "pirate");
	Group_SetGroupCommander("BlueBird_Group", "BlueBirdCapitain");
	sTemp = "quest_ship_10";
	if (pchar.location.from_sea == "Shore_ship1") sTemp = "quest_ship_8";
	Group_SetAddress("BlueBird_Group", "Bermudes", "quest_ships", sTemp);
	Group_SetTaskAttack("BlueBird_Group", PLAYER_GROUP);


	pchar.quest.BlueBird_over.win_condition.l1 = "NPC_Death";
	pchar.quest.BlueBird_over.win_condition.l1.character = "BlueBirdCapitain";
	pchar.quest.BlueBird_over.function = "BlueBird_over";
/*
	pchar.quest.BlueBird_DieHard1.win_condition.l1 = "ExitFromLocation";
	pchar.quest.BlueBird_DieHard1.win_condition.l1.location = "Bermudes";
	pchar.quest.BlueBird_DieHard1.function = "BlueBird_DieHard";
	Pchar.quest.BlueBird_DieHard2.win_condition.l1 = "MapEnter";
	pchar.quest.BlueBird_DieHard2.function = "BlueBird_DieHard";
*/	
	pchar.quest.BlueBird_DieHard1.win_condition.l1 = "MapEnter";
	pchar.quest.BlueBird_DieHard1.function = "BlueBird_DieHard";
}

void BlueBird_over(string qName)
{
	pchar.quest.BlueBird_DieHard1.over = "yes";
	pchar.quest.BlueBird_DieHard2.over = "yes";
	AddQuestRecord("Xebeca_BlueBird", "7");
	pchar.questTemp.BlueBird = "weWon";
	// Вуазье сбежал, ставим другого торгаша  <-- ugeen
	sld = characterFromId("Pirates_trader");
	sld.name = "Паскуале";
	sld.lastname = "Вуазье";
	sld.model = "Pasquale";
	LAi_SetOwnerType(sld);
	// дадим слух
	AddSimpleRumourCity("А, судар"+ GetSexPhrase("ь","ыня") +"! Вы же ещё не знаете главной новости! Оказывается, он скупал все товары, что местные пираты добывали с торговых судов. Для этого дела у него целый пакгауз отведён был.\n"+
		"Да что толку - торгаш с него никудышный - всё никак не найдёт простофилю, который бы согласился склад арендовать... В политику бы ему - там таким ушлым самое место, хе-хе...","Pirates", 30, 3, "");
	// --> ugeen
}

void BlueBird_DieHard(string qName)
{
	sld = characterFromId("BlueBirdCapitain");
	sld.lifeDay = 0;
	group_DeleteGroup("BlueBird_Group");
	pchar.quest.BlueBird_over.over = "yes";
	pchar.quest.BlueBird_DieHard1.over = "yes";
	//pchar.quest.BlueBird_DieHard2.over = "yes";
	AddQuestRecord("Xebeca_BlueBird", "8");
	pchar.questTemp.BlueBird = "DieHard";
}

//возмездие торгашам. нападение на личный флейт торговца
void BlueBird_loginFleut(string qName)
{

		LAi_group_Delete("EnemyFight");
		group_DeleteGroup("BlueBird_Group");
		sld = GetCharacter(NPC_GenerateCharacter("BlueBirdTrader", "", "man", "man", 20, sti(pchar.questTemp.BlueBird.nation), 30, true, "quest"));							
		sld.dialog.filename = "Gothic_Quest\ForAll_dialog.c";
		sld.dialog.currentnode = "BlueBirdTrader";
		sld.greeting = "CapSinkShip";		
		SetCaptanModelByEncType(sld, "trade");
		FantomMakeCoolSailor(sld, SHIP_TRADEFLEUT,                                          pchar.questTemp.BlueBird.Ship.Name, CANNON_TYPE_CULVERINE_LBS18, 70, 70, 70);
		sld.Ship.name = "Золотой век";
		sld.Ship.Mode = "trade"; //торговец
		sld.DontRansackCaptain = true;
		SetCharacterGoods(sld, GOOD_BALLS, 900); 
		SetCharacterGoods(sld, GOOD_GRAPES, 550); 
		SetCharacterGoods(sld, GOOD_KNIPPELS, 400); 
		SetCharacterGoods(sld, GOOD_BOMBS, 600); 
		SetCharacterGoods(sld, GOOD_FOOD, 900); 
		SetCharacterGoods(sld, GOOD_POWDER, 2500); 
		SetCharacterGoods(sld, GOOD_WEAPON, 350); 
		SetCharacterGoods(sld, GOOD_MEDICAMENT, 300); 
		SetCharacterGoods(sld, GOOD_RUM, 200); 
		SetCharacterGoods(sld, GOOD_PLANKS, 100);
		SetCharacterGoods(sld, GOOD_SAILCLOTH, 100);
		SetCharacterGoods(sld, GOOD_TEA, 777);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		Group_AddCharacter("BlueBird_Group", "BlueBirdTrader");			
		Group_SetGroupCommander("BlueBird_Group", "BlueBirdTrader");
	                    Group_SetAddress("BlueBird_Group", "Guadeloupe", "quest_ships", sTemp);
		//Group_SetAddress("BlueBird_Group", pchar.questTemp.BlueBird.Island, "quest_ships", "quest_ship_"+(rand(5)+1));
		Group_SetTaskRunaway("BlueBird_Group", PLAYER_GROUP);
		pchar.questTemp.BlueBird = "attackFleut"; //флаг квеста
		//прерывания на уход из локации
		pchar.Quest.BlueBirdFleut_over1.win_condition.l1 = "Location_Type";
		pchar.Quest.BlueBirdFleut_over1.win_condition.l1.location_type = "town";
		pchar.Quest.BlueBirdFleut_over1.function = "BlueBirdFleut_over";

		pchar.Quest.BlueBirdFleut_over2.win_condition.l1 = "Location_Type";
		pchar.Quest.BlueBirdFleut_over2.win_condition.l1.location_type = "seashore";
		pchar.Quest.BlueBirdFleut_over2.function = "BlueBirdFleut_over";
		Pchar.quest.BlueBirdFleut_over3.win_condition.l1 = "MapEnter";
		pchar.Quest.BlueBirdFleut_over3.function = "BlueBirdFleut_over";
		//прерывание на абордаж
    	pchar.quest.BlueBirdFleut_board.win_condition.l1 = "NPC_death";
    	pchar.quest.BlueBirdFleut_board.win_condition.l1.character = "BlueBirdTrader";
    	pchar.quest.BlueBirdFleut_board.function = "BlueBirdFleut_board";
	}
	else
	{
		AddQuestRecord("Xebeca_BlueBird", "11");
		AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("ел","ла"));
		AddQuestUserData("Xebeca_BlueBird", "sIsland", XI_ConvertString(pchar.questTemp.BlueBird.Island + "Gen"));
	
}

void BlueBirdFleut_over(string qName)
{
	LAi_group_Delete("EnemyFight");
	group_DeleteGroup("BlueBird_Group");
	pchar.Quest.BlueBirdFleut_over1.over = "yes";
	pchar.Quest.BlueBirdFleut_over2.over = "yes";
	pchar.Quest.BlueBirdFleut_over3.over = "yes";
	pchar.Quest.BlueBirdFleut_board.over = "yes";
	AddQuestRecord("Xebeca_BlueBird", "12");
	AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("ел","ла"));
	AddQuestUserData("Xebeca_BlueBird", "sIsland", XI_ConvertString(pchar.questTemp.BlueBird.Island + "Gen"));
	pchar.questTemp.BlueBird = "returnMoney"; //иначе ивент на слухе не сработает
}
//флейт абордирован, задание выполнено
void BlueBirdFleut_board(string qName)
{
	pchar.Quest.BlueBirdFleut_over1.over = "yes";
	pchar.Quest.BlueBirdFleut_over2.over = "yes";
	pchar.Quest.BlueBirdFleut_over3.over = "yes";
	pchar.questTemp.BlueBird.count = sti(pchar.questTemp.BlueBird.count) + 1; //счетчик потопленных флейтов
	AddQuestRecord("Xebeca_BlueBird", "13");
	AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("ым","ой"));
	AddQuestUserData("Xebeca_BlueBird", "sIsland", XI_ConvertString(pchar.questTemp.BlueBird.Island + "Gen"));
	pchar.questTemp.BlueBird = "returnMoney"; //иначе ивент на слухе не сработает
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  бриг Черная Горгулья конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  //zagolski. начальный квест пирата
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void pirateStartQuest_Smuggler_fc(string qName)
{

	AddQuestRecord("pSQ", "4");
	chrDisableReloadToLocation = true;
	//int iRank = makeint(sti(pchar.rank)+MOD_SKILL_ENEMY_RATE/2);
                int iRank = 17+MOD_SKILL_ENEMY_RATE/2;

    	for (i=1; i<=3; i++)
    	{
		sld = GetCharacter(NPC_GenerateCharacter("psq1_"+i, "sold_"+NationShortName(sti(pchar.questTemp.pirateStartQuest.City2Nation))+"_"+(rand(4)+1), "man", "man", iRank, sti(pchar.questTemp.pirateStartQuest.City2Nation), 0, true, "quest"));
		SetFantomParamFromRank(sld, iRank, true);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "pirateStartQuest_Smuggler_group");
		ChangeCharacterAddressGroup(sld, pchar.questTemp.pirateStartQuest.City2 +"_ExitTown", "goto", LAi_FindNearestFreeLocator2Pchar("goto"));
	}
	LAi_group_SetRelation("pirateStartQuest_Smuggler_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("pirateStartQuest_Smuggler_group", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("pirateStartQuest_Smuggler_group", "OpenTheDoors");
}

void pirateStartQuest_Smuggler_fc2(string qName)
{
    	LAi_group_SetRelation("pirateStartQuest_Smuggler_group", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
	//int iRank = makeint(sti(pchar.rank)+MOD_SKILL_ENEMY_RATE/2);
 int iRank = 10+MOD_SKILL_ENEMY_RATE/2;

    	for (i=1; i<=3; i++)
    	{
		sld = GetCharacter(NPC_GenerateCharacter("psq2_"+i, "citiz_"+(i+40), "man", "man", iRank, PIRATE, -1, true, "quest"));
	SetFantomParamFromRank(sld, iRank, true);
	sld.dialog.filename = "Gothic_Quest\pSQ_Smuggler_dialog.c";
	sld.dialog.currentnode = "First time";
	sld.greeting = "Gr_Smuggler_OnShore";
	LAi_SetImmortal(sld, true);
	LAi_SetGuardianType(sld);
	LAi_SetCharacterUseBullet(sld, "cartridge");
                     TakeNItems(sld, "grapeshot", 6);
	TakeNItems(sld, "bullet", 12);
	TakeNItems(sld, "cartridge", 9);
	TakeNItems(sld, "GunPowder", 24);
	LAi_group_MoveCharacter(sld, "pirateStartQuest_Smuggler_group");
	ChangeCharacterAddressGroup(sld, pchar.questTemp.pirateStartQuest.Shore, "Smugglers", "Smuggler0" + i);
	}
}

void pirateStartQuest_Lether_fc(string qName)
{
	if (GetCharacterItem(pchar, "letter_open") == 0)
	{
		GiveItem2Character(pchar, "letter_open");
		ChangeItemDescribe("letter_open", "itmdescr_letter_open_pirateStartQuest");
	}

	SetTimerFunction("pirateStartQuest_Bahus_fc", 0, 0, 1);
}

void pirateStartQuest_Bahus_fc(string qName)
{
	pchar.quest.pirateStartQuest_Bahus_seaBattle.win_condition.l1 = "location";
	pchar.quest.pirateStartQuest_Bahus_seaBattle.win_condition.l1.location = pchar.questTemp.pirateStartQuest.Areal;
	pchar.quest.pirateStartQuest_Bahus_seaBattle.function = "pirateStartQuest_Bahus_seaBattle";
}

void pirateStartQuest_Bahus_seaBattle(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("pSQB_Captain", "BahusCap", "man", "man", 6, PIRATE, 1, true, "quest"));
		FantomMakeCoolFighter(sld, 40, 40, 40, "blade_15", "pistol_08", "grapeshot", 70);
	FantomMakeCoolSailor(sld, SHIP_FLEUT, "Бахус", CANNON_TYPE_CANNON_LBS12, 50, 30, 30);
      sld.name 	= "Сиренсио";
      sld.lastname = "Беграччи";
	SetCharacterGoods(sld, GOOD_SLAVES, 300);
	SetCrewQuantity(sld, 129);
	sld.ship.Crew.Morale = 20;
	sld.SaveItemsForDead  = true; 
	sld.DontClearDead = true;
	ChangeCrewExp(sld, "Sailors", 50);
	ChangeCrewExp(sld, "Cannoners", 30);
	ChangeCrewExp(sld, "Soldiers", 20);
	LAi_SetCharacterUseBullet(sld, "bullet");
     TakeNItems(sld, "grapeshot", 39);
	TakeNItems(sld, "bullet", 11);
	TakeNItems(sld, "cartridge", 7);
	TakeNItems(sld, "GunPowder", 34);

	Group_AddCharacter("pSQB_Group", "pSQB_Captain");			
	Group_SetType("pSQB_Group", "Pirate");
	Group_SetGroupCommander("pSQB_Group", "pSQB_Captain");
	Group_SetAddress("pSQB_Group", pchar.questTemp.pirateStartQuest.Areal, "quest_ships", "quest_ship_"+(1+rand(2)));
Group_LockTask("pSQB_Group");
}

void pirateStartQuest_seaBattle(string qName)
{
	LAi_group_SetRelation("pirateStartQuest_Smuggler_group", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);

	sld = GetCharacter(NPC_GenerateCharacter("pSQ_Captain", "officer_3", "man", "man", 8, PIRATE, -1, true, "quest"));
		FantomMakeCoolFighter(sld, 9, 50, 50, "newblade26", "pistol9", "bullet", 70);
	FantomMakeCoolSailor(sld, SHIP_LUGGERR, "Септима", CANNON_TYPE_CANNON_LBS12, 40, 40, 40);
     sld.name 	= "Норман";
     sld.lastname = "Виго";
	sld.MultiFighter = 1.5; // мультифайтер
	sld.MultiShooter = 1.5;
	sld.SuperShooter  = true;
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_11.tga");
	sld.AlwaysSandbankManeuver = true;
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	SetCharacterPerk(sld, "MusketsShoot");

	sld.ship.Crew.Morale = 50;
	ChangeCrewExp(sld, "Sailors", 50);
	ChangeCrewExp(sld, "Cannoners", 50);
	ChangeCrewExp(sld, "Soldiers", 50);
	GiveItem2Character(sld, "cirass1");
	GiveItem2Character(sld, "jewelry9");
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetCharacterGoods(sld, GOOD_SHIPSILK, 25);
	SetCharacterGoods(sld, GOOD_ROPES, 25);
	SetCharacterGoods(sld, GOOD_SANDAL, 25);
	SetCharacterGoods(sld, GOOD_OIL, 25);
	UpgradeShipParameter(sld, "Capacity");
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "HP");//корпус
	UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
	UpgradeShipParameter(sld, "MaxCrew");
	LAi_SetCharacterUseBullet(sld, "bullet");
     TakeNItems(sld, "grapeshot", 4);
	TakeNItems(sld, "bullet", 6);
	TakeNItems(sld, "cartridge", 5);
	TakeNItems(sld, "GunPowder", 12);

	bQuestDisableMapEnter = true;//закрыть карту
	Island_SetReloadEnableGlobal("Martinique", false);//на остров нельзя
	
	LAi_group_MoveCharacter(sld, "pirateStartQuest_Smuggler_group");
	Group_AddCharacter("pSQ_Group", "pSQ_Captain");			
	Group_SetType("pSQ_Group", "Pirate");
	Group_SetGroupCommander("pSQ_Group", "pSQ_Captain");
	Group_SetAddress("pSQ_Group", pchar.questTemp.pirateStartQuest.Areal, "quest_ships", "quest_ship_4");
	Group_SetTaskAttack("pSQ_Group", PLAYER_GROUP);
	Group_LockTask("pSQ_Group");

	pchar.quest.pirateStartQuest_seaBattle_over.win_condition.l1 = "NPC_Death";
	pchar.quest.pirateStartQuest_seaBattle_over.win_condition.l1.character = "pSQ_Captain";
	pchar.quest.pirateStartQuest_seaBattle_over.function = "pirateStartQuest_seaBattle_over";
}

void pirateStartQuest_seaBattle_over(string qName)
{
	DoQuestCheckDelay("sea_victory", 1.5);
	pchar.questTemp.pirateStartQuest = "5";
	bQuestDisableMapEnter = false;//открыть карту
	Island_SetReloadEnableGlobal("Martinique", true);
	AddQuestRecord("pSQ", "8");
	AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);
}

// Warship Квест "Сопровождение флейта ''Орион''" -->

void Andre_Abel_Quest_1Day_Left(string sQuest)	// Провал квеста 
{
	ref rChar = CharacterFromID("Andre_Abel");
	rChar.LifeDay = 0;
	LAi_CharacterDisableDialog(rChar);
	ChangeCharacterAddressGroup(rChar, "none", "", "");
	AddQuestRecord("Andre_Abel_Quest", "2");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
}

void Andre_Abel_Quest_2Days_Left(string sQuest)	// Провал квеста - не решили свои дела за два дня
{
	ref rChar = CharacterFromID("Andre_Abel");
	rChar.LifeDay = 0;
	LAi_CharacterDisableDialog(rChar);
//	ChangeCharacterAddressGroup(rChar, "none", "", "");
	AddQuestRecord("Andre_Abel_Quest", "2");
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
}

void Andre_Abel_Quest_Delete_Andre_From_Tavern(string sQuest)	// Убираем Абеля из таверны
{
	ref rChar = CharacterFromID("Andre_Abel");
	ChangeCharacterAddressGroup(rChar, "none", "", "");
	// Присоединяем Андрэ Абеля к игроку в качестве компаньона
	SetCompanionIndex(Pchar, -1, GetCharacterIndex(rChar.id));
	SetCharacterRemovable(rChar, false);	// нельзя сменить
	LAi_SetImmortal(rChar, false);	// можно убить
//	rChar.Dialog.CurrentNode = "Andre_Abel_To_Sea_1";
}

void Andre_Abel_Quest_15_Days_Is_Left(string sQuest)	// Не успели в Порт-о-Принс за 15 дней
{
	ref rChar = CharacterFromID("Andre_Abel");
	rChar.LifeDay = 0;
	AddQuestRecord("Andre_Abel_Quest", "4");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
	RemoveCharacterCompanion(PChar, rChar);
	QuestSetCurrentNode("Andre_Abel", "Andre_Abel_15Days_Left_1");
	PChar.Quest.Andre_Abel_Quest_Andre_Is_Dead.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Delete_Andre_From_Tavern.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Battle_With_Pirates_Squadron.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Speak_In_PortPax.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Pirates_Is_Dead.over = "yes";
	PChar.Quest.Andre_Abel_Quest_EnterMap.over = "yes";
}

void Andre_Abel_Quest_Andre_Is_Dead(string sQuest)	// Андрэ Абеля потопили
{
	AddQuestRecord("Andre_Abel_Quest", "5");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","ла"));
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
	PChar.Quest.Andre_Abel_Quest_15_Days_Is_Left.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Speak_In_PortPax.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Battle_With_Pirates_Squadron.over = "yes";
}

void Andre_Abel_Quest_Battle_With_Pirates_Squadron(string sQuest)	// Выполнилось прерывание на Hispaniola2. Боевка с пиратами
{
	Log_TestInfo("Сгенерилась пиратская эскадра.");
	ref rChar;
	string sName, sLastName, sModel, sShipName;
	PChar.Quest.Andre_Abel_Quest_Andre_Is_Dead.over = "yes";
	Group_FindOrCreateGroup("Andre_Abel_Quest_Pirates_Ships");
	for(int i=1; i<=3; i++)
	{
		switch(i)
		{
			case 1:
				sName = "Кристиан";
				sLastName = "Копнер";
				sModel = "citiz_51";
				sShipName = "Аврора";
				break;
				
			case 2:
				sName = "Роберт";
				sLastName = "Недервин";
				sModel = "citiz_52";
				sShipName = "Антилопа";
				break;
				
			case 3:
				sName = "Томас";
				sLastName = "Чамберс";
				sModel = "citiz_55";
				sShipName = "Сьюзан";
				break;
		}
	
		rChar = GetCharacter(NPC_GenerateCharacter("Andre_Abel_Quest_Pirate_" + i, sModel, "man", "man", 15, PIRATE, -1, true, "quest"));
		FantomMakeCoolFighter(rChar, 35, 40, 35, "newblade26", "pistol3", "bullet", 10);
		FantomMakeCoolSailor(rChar, RandShipFromShipClass(PChar), sShipName, CANNON_TYPE_CANNON_LBS24, 75, 70, 65);
		rChar.name = sName;
		rChar.Lastname = sLastName;
		Group_AddCharacter("Andre_Abel_Quest_Pirates_Ships", "Andre_Abel_Quest_Pirate_" + i);
	}
	
	Group_SetType("Andre_Abel_Quest_Pirates_Ships", "war");
	Group_SetGroupCommander("Andre_Abel_Quest_Pirates_Ships", "Andre_Abel_Quest_Pirate_1");
	Group_SetTaskAttack("Andre_Abel_Quest_Pirates_Ships", PLAYER_GROUP);
	Group_LockTask("Andre_Abel_Quest_Pirates_Ships");
	Group_SetAddress("Andre_Abel_Quest_Pirates_Ships", "Hispaniola2", "", "");
	Group_SetPursuitGroup("Andre_Abel_Quest_Pirates_Ships", PLAYER_GROUP);
//	Island_SetReloadEnableGlobal("Hispaniola2", false); // На берег нельзя
	SetFunctionLocationCondition("Andre_Abel_Quest_Speak_In_PortPax", "PortPax_town", false);
	SetFunctionNPCDeathCondition("Andre_Abel_Quest_Andre_Is_Dead_2", "Andre_Abel", false);
	SetFunctionInterruptionToShips("Andre_Abel_Quest_Pirates_Ships", "Andre_Abel_Quest_Pirates_Is_Dead", "Andre_Abel_Quest_EnterMap");
}

void Andre_Abel_Quest_Andre_Is_Dead_2(string sQuest) // Абеля потопили при боевке с пиратами
{
	AddQuestRecord("Andre_Abel_Quest", "6");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","ла"));
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
//	Island_SetReloadEnableGlobal("Hispaniola2", true);
	PChar.Quest.Andre_Abel_Quest_Speak_In_PortPax.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Pirates_Is_Dead.over = "yes";
	PChar.Quest.Andre_Abel_Quest_EnterMap.over = "yes";
}

void Andre_Abel_Quest_EnterMap(string sQuest)	// Свалили
{
	ref rChar = CharacterFromID("Andre_Abel");
	AddQuestRecord("Andre_Abel_Quest", "7");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
	Group_DeleteGroup("Andre_Abel_Quest_Pirates_Ships");
	RemoveCharacterCompanion(PChar, rChar);
//	Island_SetReloadEnableGlobal("Hispaniola2", true);
	PChar.Quest.Andre_Abel_Quest_Speak_In_PortPax.over = "yes";
	PChar.Quest.Andre_Abel_Quest_Andre_Is_Dead_2.over = "yes";	// Не храним лишние прерывания
}

void Andre_Abel_Quest_Pirates_Is_Dead(string sQuest)	// Победили пиратскую эскадру
{
	DoQuestCheckDelay("sea_victory", 1.5);
	AddQuestRecord("Andre_Abel_Quest", "8");
	SetFunctionNPCDeathCondition("Andre_Abel_Quest_Andre_Is_Dead_3", "Andre_Abel", false);
//	SetFunctionLocationCondition("Andre_Abel_Quest_Speak_In_PortPax", "PortPax_town", false);
//	Island_SetReloadEnableGlobal("Hispaniola2", true);
	PChar.Quest.Andre_Abel_Quest_Andre_Is_Dead_2.over = "yes";
}

void Andre_Abel_Quest_Andre_Is_Dead_3(string sQuest)	// Абеля утопил кто-то в порту
{
	AddQuestRecord("Andre_Abel_Quest", "5");
	CloseQuestHeader("Andre_Abel_Quest");
	DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
	PChar.Quest.Andre_Abel_Quest_Speak_In_PortPax.over = "yes";
}

void Andre_Abel_Quest_Speak_In_PortPax(string sQuest)	// Разговор с Абелем в порту Порт-о-Принса
{
	ref rChar = CharacterFromID("Andre_Abel");
	RemoveCharacterCompanion(PChar, rChar);
	rChar.Dialog.CurrentNode = "Andre_Abel_In_PortPax";
	LAi_LocationDisableOfficersGen("PortPax_town", true);
	LAi_SetImmortal(rChar, true);
	ChangeCharacterAddressGroup(rChar, "PortPax_town", "quest", "quest1");
	LAi_SetActorType(rChar);
	LAi_ActorDialog(rChar, PChar, "", -1, 5);
	bDisableFastReload = true;
	chrDisableReloadToLocation = true;
	PChar.Quest.Andre_Abel_Quest_Andre_Is_Dead_3.over = "yes";
}

void Andre_Abel_Quest_Dialog_In_PortPax_Tavern()	// В таверне...
{
	ref rChar = CharacterFromID("Andre_Abel");
	QuestSetCurrentNode("Andre_Abel", "Andre_Abel_In_Tavern_1");
	LAi_ActorDialog(rChar, PChar, "", -1, 5);
}

void Andre_Abel_Quest_After_First_Torus_Dialog()	// Торус выставил игрока из своей резиденции
{
	AddQuestRecord("Andre_Abel_Quest", "11");
	QuestSetCurrentNode("Henry Morgan", "Andre_Abel_Quest_Morgan_Dialog_1");
                   sld = CharacterFromID("Torus");
 	sld.City = "Roseau";
	sld.location	= "Roseau_Roomtownhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Mayor\Torus.c";
	sld.greeting = "Gr_Torus";
}

void Andre_Abel_Quest_Curasao_10Days_Left(string sQuest)	// Не успели к Стэвезанту за 10 дней
{
	AddQuestRecord("Andre_Abel_Quest", "15");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
	TakeItemFromCharacter(PChar, "letter_1");
	ChangeCharacterAddressGroup(CharacterFromID("Andre_Abel"), "none", "", "");
	ref rChar = CharacterFromID("Villemstad_Mayor");
	rChar.Dialog.CurrentNode = rChar.Dialog.TempNode; // Вернем ноду диалога Ген-Губеру
	PChar.QuestTemp.Andre_Abel_Quest_PortPax_TavernOwner_Speek = true;
	if(!CheckAttribute(PChar, "Quest.Andre_Abel_Quest_In_Curacao_Townhall"))
	{
		rChar = CharacterFromID("Andre_Abel_Quest_Officer_1");
		rChar.LifeDay = 0;
	}
	PChar.Quest.Andre_Abel_Quest_In_Curacao_Townhall.over = "yes";
}

void Andre_Abel_Quest_In_Curacao_Townhall(string sQuest)	// Зашли в резиденцию Виллемстеда
{
	ref rChar = GetCharacter(NPC_GenerateCharacter("Andre_Abel_Quest_Officer_1", "off_hol_2", "man", "man", 20, HOLLAND, -1, true, "quest"));
	FantomMakeCoolFighter(rChar, 15, 60, 65, "blade_24", "pistol3", "bullet", 100);
	rChar.Dialog.FileName = "Gothic_Quest\Other_Quests_NPC.c";
	rChar.greeting = "soldier_common";
	LAi_SetGuardianType(rChar);
	LAi_SetImmortal(rChar, true);
	ChangeCharacterAddressGroup(rChar, "Villemstad_Townhall", "goto", "goto6");
	string slai_group = "HOLLAND_citizens"; 
	LAi_group_MoveCharacter(rChar, slai_group); 
}

void Andre_Abel_Quest_In_Prison()	// В тюрьме...
{
	AddQuestRecord("Andre_Abel_Quest", "17");
	ref rChar = GetCharacter(NPC_GenerateCharacter("Jack_V", "Jack_V", "man", "man_B", 10, PIRATE, -1, true, "quest"));
	rChar.rank = 15;
	SetSelfSkill(rChar, 45, 60, 45, 100, 100);
	SetShipSkill(rChar, 50, 20, 25, 25, 65, 20, 20, 50, 15);
	SetSPECIAL(rChar, 8, 9, 6, 3, 9, 7, 10);
	LAi_SetHP(rChar, 250, 250);
	SetCharacterPerk(rChar, "Energaiser");
	SetCharacterPerk(rChar, "BasicDefense");
	SetCharacterPerk(rChar, "ShipSpeedUp");
	SetCharacterPerk(rChar, "ShipTurnRateUp");
	SetCharacterPerk(rChar, "StormProfessional"); 
	SetCharacterPerk(rChar, "WindCatcher"); 
	SetCharacterPerk(rChar, "SailsMan");
	SetCharacterPerk(rChar, "Turn180");
	SetCharacterPerk(rChar, "SailingProfessional");
	SetCharacterPerk(rChar, "ByWorker");
	SetCharacterPerk(rChar, "Gunman"); 
	SetCharacterPerk(rChar, "GunProfessional"); 
	SetCharacterPerk(rChar, "Sniper"); 
	ChangeCharacterAddressGroup(rChar, "Villemstad_prison", "goto", "goto24");
	rChar.Dialog.Filename = "Gothic_Quest\Other_Quests_NPC.c";
	rChar.greeting = "";
	rChar.name = "Джек";
	rChar.Lastname = "Воробей";
	rChar.reputation = 60;
	rChar.alignment = "good";
	rChar.MultiFighter = 2.0; // мультифайтер
	rChar.MultiShooter = 2.0;
	LAi_SetStayType(rChar);
	RemoveAllCharacterItems(rChar, true);
	rChar = CharacterFromID("Andre_Abel_Quest_Officer_1");
	ChangeCharacterAddressGroup(rChar, "none", "", ""); // Убираем солдера из резиденции
	
	PChar.QuestTemp.JailCanMove = false; // Если было - уберем
	PChar.QuestTemp.Andre_Abel_Quest_In_Prison = true;

	ref location = &Locations[FindLocation("Villemstad_prison")];	
	
	// Перекладываем предметы ГГ в сундук 
	aref arItems, boxItems;
	ref rItem;
	string sName;
	makearef(arItems, PChar.items);
	makearef(boxItems, location.box1.items);
	int iItemsNum = GetAttributesNum(arItems);
	for(int i=0; i<iItemsNum; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		rItem = ItemsFromID(sName);
		if (rItem.ItemType != "QUESTITEMS")
		{
			boxItems.(sName) = PChar.items.(sName);
		}
	}
	location.box1.money = PChar.money;	
	location.box1 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear())
		
	RemoveAllCharacterItems(PChar, true);	
}

void Andre_Abel_Quest_Runaway_From_Prison()	// По другую сторону решетки
{
	ref rChar = CharacterFromID("Jack_V");
	AddQuestRecord("Andre_Abel_Quest", "18");
	
	rChar.location = "Villemstad_town";	// Нужно для того, чтобы он появился в локации форта
	rChar.location.group = "reload";
	rChar.location.locator = "reload_jail";
	LAi_SetOfficerType(rChar);

	LAi_Group_MoveCharacter(rChar, LAI_GROUP_PLAYER);
	QuestSetCurrentNode("Henry Morgan", "Andre_Abel_Quest_Morgan_Dialog_11");
	
	LAi_Group_Attack(PChar, CharacterFromID("VillemstadJailOff"));	// Как будто мы его ударили
	Flag_PIRATE();
	
	PChar.Quest.Andre_Abel_Quest_In_Sea_After_Prison.win_condition.l1 = "EnterToSea";
	PChar.Quest.Andre_Abel_Quest_In_Sea_After_Prison.function = "Andre_Abel_Quest_In_Sea_After_Prison";

}

void Andre_Abel_Quest_Martin_Bleker_Is_Dead(string sQuest)	// Джека убили
{
	Log_TestInfo("Джека убили");
	PChar.Quest.Andre_Abel_Quest_Liberty.over = "yes";
}

void Andre_Abel_Quest_Liberty(string sQuest)	// Локация выхода из Виллемстада
{
	ref rChar = CharacterFromID("Jack_V");
	ChangeCharacterAddressGroup(rChar, "Villemstad_ExitTown", "reload", "reload4");
	chrDisableReloadToLocation = true;
	LAi_SetActorType(rChar);
	DeleteAttribute(PChar, "QuestTemp.Andre_Abel_Quest_In_Prison");
	QuestSetCurrentNode("Jack_V", "Andre_Abel_Quest_In_Liberty_1");
	LAi_ActorDialog(rChar, PChar, "", -1, 5);
	PChar.Quest.Andre_Abel_Quest_Martin_Bleker_Is_Dead.over = "yes";
}

void Andre_Abel_Quest_Delete_Martin(string sQuest)	// Попрощались с Джеком
{
	ref rChar = CharacterFromID("Jack_V");
	ChangeCharacterAddressGroup(rChar, "none", "", "");
}

void Andre_Abel_Quest_In_Sea_After_Prison(string sQuest)	// Вышли в море
{
	AddQuestRecord("Andre_Abel_Quest", "20");
	AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("ся","ась"));
}

// <-- Квест "Сопровождение флейта 'Орион'"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Черная Борода (Охота на волков)
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//--> ОЗГ, Карлос Кассир
void SelectCarlosCity() //выбираем город
{
	switch (rand(2))
	{
		case 0:
			pchar.questTemp.Headhunter.City = "Bridgetown";
			pchar.questTemp.Headhunter.Cityname = "Бриджтауне";
			break;
		case 1:
			pchar.questTemp.Headhunter.City = "Portroyal";
			pchar.questTemp.Headhunter.Cityname = "Порт-Рояле";
			break;

		case 2:
			pchar.questTemp.Headhunter.City = "Bridgetown";
			pchar.questTemp.Headhunter.Cityname = "Бриджтауне";
			break;

	}
}

void CreateCarlos()//создаем Карлоса
{

	sld = GetCharacter(NPC_GenerateCharacter("Carlos", "ozg_carlos", "man", "man", 20, PIRATE, -1, false, "quest"));
	sld.name = "Карлос";
	sld.lastname = "Кассир";
     sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "Carlos";
     sld.greeting = "pirat_common";
     FantomMakeCoolFighter(sld, 70, 70, 70, "newblade14", "pistol11", "bullet", 50);
    	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	LAi_SetHP(sld, 300+MOD_SKILL_ENEMY_RATE*20, 300+MOD_SKILL_ENEMY_RATE*20); 
	sld.MultiFighter = 2.0;
	sld.MultiShooter = 2.0;
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Gunman");
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper"); 
SetCharacterPerk(sld, "HPPlus"); 
SetCharacterPerk(sld, "EnergyPlus");
SetCharacterPerk(sld, "SwordplayProfessional");
SetCharacterPerk(sld, "ProfessionalDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "BladeDancer");
SetCharacterPerk(sld, "Grus"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
GiveItem2Character(sld, "cirass7"); 
EquipCharacterbyItem(sld, "cirass7"); 
AddItems(sld, "gold_dublon", 500); 
SetSelfSkill(sld, 55, 40, 70, 75, 45); 
SetShipSkill(sld, 75, 40, 40, 45, 65, 55, 65, 45, 75); 
AddItems(sld, "gunpowder", 50); 
LAi_SetCharacterUseBullet(sld, "Bullet"); 
sld.SuperShooter  = true;
TakeNItems(sld, "potion2", 5);
    LAi_SetCitizenType(sld);

    if(pchar.questTemp.Headhunter.Chance == 1)
    {
   	    LAi_SetSitTypeNoGroup(sld);
        ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_tavern", "sit","sit2");
    }
    else
    {
   	    LAi_SetStayTypeNoGroup(sld);
        ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_Brothel_room", "goto","goto3");
        
		sld1 = GetCharacter(NPC_GenerateCharacter("Qhorse", "women_26", "woman", "towngirl", 10, ENGLAND, 1, false, "quest"));
        LAi_SetActorTypeNoGroup(sld1);
		ChangeCharacterAddressGroup(sld1, pchar.questTemp.Headhunter.City + "_Brothel_room", "goto","goto1");
        int n = FindLocation(pchar.questTemp.Headhunter.City + "_Brothel");
        locations[n].reload.l2.disable = false;
    }
}

void CarlosDuel(string qName)
{
	pchar.quest.CarlosPlace.win_condition.l1 = "Location";
	pchar.quest.CarlosPlace.win_condition.l1.location = pchar.questTemp.Headhunter.City + "_ExitTown";
	pchar.quest.CarlosPlace.function = "CarlosPlace";
}

void CarlosDuelOver(string qName)//не пришли на стрелку
{
	pchar.quest.CarlosPlace.over = "yes";
	LAi_LocationDisableOfficersGen(pchar.questTemp.Headhunter.City + "_ExitTown", false);//офицеров пускать
	locations[FindLocation(pchar.questTemp.Headhunter.City + "_ExitTown")].DisableEncounters = false; //энкаутеры откроем
	sld = characterFromId("Carlos");
	sld.lifeDay = 0;
	AddQuestRecord("Headhunt", "2_2");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","ла"));
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
}

void CarlosPlace(string qName)
{
	pchar.quest.CarlosDuelOver.over = "yes";
	LAi_SetPlayerType(pchar);
	LAi_group_Delete("EnemyFight"); 
	iTemp = sti(pchar.rank) + MOD_SKILL_ENEMY_RATE + 5; //это ранг от сложности
	for (i=2; i<=4; i++)
    {
		if (i == 4)
        {
			sld = GetCharacter(NPC_GenerateCharacter("Carloshelper_"+i, "Bandit_mush_1", "man", "mushketer", iTemp, PIRATE, -1, true, "quest"));                    
 		FantomMakeCoolFighter(sld, 30, 100, 100, "", "grape_mushket", "grenade", 200);
		LAi_SetHP(sld, 250+MOD_SKILL_ENEMY_RATE*20, 250+MOD_SKILL_ENEMY_RATE*20);  
		TakeNItems(sld, "grenade", 70); // may-16
		LAi_SetCharacterUseBullet(sld, "grenade");
	SetSelfSkill(sld, 100, 100, 100, 100, 100); 
	SetShipSkill(sld, 100, 1, 1, 1, 1, 1, 1, 1, 100); 
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.SuperShooter  = true;
	TakeNItems(sld, "potion2", 2);
		sld.MultiFighter = 1.5;
		sld.MultiShooter = 1.5;
		}	
		else
        {
			sld = GetCharacter(NPC_GenerateCharacter("Carloshelper_"+i, "Bandit_"+i, "man", "man", iTemp, PIRATE, -1, true, "quest"));
		FantomMakeCoolFighter(sld, iTemp, 100, 100, "topor_04", "pistol_08", "grapeshot", 50);  
		sld.MultiFighter = 1.5;
		sld.MultiShooter = 1.5;
	SetSelfSkill(sld, 100, 100, 100, 100, 100); 
	SetShipSkill(sld, 100, 1, 1, 1, 1, 1, 1, 1, 100); 
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
		TakeNItems(sld, "potion2", 2);
	AddItems(sld, "gunpowder", 50); 
	LAi_SetCharacterUseBullet(sld, "grapeshot"); 
	sld.SuperShooter  = true;
		LAi_SetHP(sld, 200+MOD_SKILL_ENEMY_RATE*20, 200+MOD_SKILL_ENEMY_RATE*20); 
		}
		LAi_SetWarriorType(sld); 
		LAi_warrior_DialogEnable(sld, false);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_ExitTown", "goto", "goto6");
    }
    sld = characterFromID("Carlos");
	sld.Dialog.Filename = "Gothic_Quest\Other_Quests_NPC.c"; //диалоговый файл, из которого говорить будет
	sld.dialog.currentnode = "talk_off_town_Carlos"; // диалоговый узел
	if (CheckAttribute(sld, "CityType"))
	{
		DeleteAttribute(sld, "City"); // чтоб не было ругани с нацией
		DeleteAttribute(sld, "CityType");
	}
	ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_ExitTown", "goto", "goto1");
	LAi_SetActorType(pchar);
    LAi_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, pchar);
    SetActorDialogAny2Pchar(sld.id, "", 0.0, 0.0);
	LAi_ActorFollow(pchar, sld, "ActorDialog_Any2Pchar", -1);
}
//<-- ОЗГ, Карлос Кассир
		
void SelectHoumCity()//выберем колонию для Холма
{
	switch (sti(pchar.questTemp.Headhunter.Chance))
	{
		case 0:
			pchar.questTemp.Headhunter.City = "Bridgetown";
			pchar.questTemp.Headhunter.Cityname = "Бриджтауне";
			pchar.questTemp.Headhunter.Island = "Barbados";
		break;
		case 1:
			pchar.questTemp.Headhunter.City = "Sentjons";
			pchar.questTemp.Headhunter.Cityname = "Сент-Джонсе";
			pchar.questTemp.Headhunter.Island = "Antigua";
		break;
		case 2:
			pchar.questTemp.Headhunter.City = "Portroyal";
			pchar.questTemp.Headhunter.Cityname = "Порт-Рояле";
			pchar.questTemp.Headhunter.Island = "Jamaica";
		break;

		case 3:
			pchar.questTemp.Headhunter.City = "Beliz";
			pchar.questTemp.Headhunter.Cityname = "Белизе";
			pchar.questTemp.Headhunter.Island = "Beliz";
		break;

		case 4:
			pchar.questTemp.Headhunter.City = "SantaCatalina";
			pchar.questTemp.Headhunter.Cityname = "Блуфилдс";
			pchar.questTemp.Headhunter.Island = "SantaCatalina";
		break;
	}
}

void CreateHoum()//создадим Холма
{

	sld = GetCharacter(NPC_GenerateCharacter("Houm", "ozg_horn", "man", "man", 25, ENGLAND, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 25, 50, 50, "blade_19", "pistol6", "bullet", 70);
	FantomMakeCoolSailor(sld, SHIP_ARMEDCORVETTE, "Мертвая голова", CANNON_TYPE_CANNON_LBS32, 70, 70, 70);
	sld.name = "Ганнибал";
	sld.lastname = "Холм";
    sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "Houm";
    sld.greeting = "Gr_HeadPirates";
	sld.Ship.Mode = "mercenary";
    DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
    sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.AlwaysEnemy = true;
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_12.tga");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterGoods(sld, GOOD_SILVER, 556);//положить в трюм серебро
	LAi_SetCitizenType(sld);
	LAi_SetImmortal(sld, true);
	sld.ship.Crew.Morale = 70;
	ChangeCrewExp(sld, "Sailors", 70);
	ChangeCrewExp(sld, "Cannoners", 70);
	ChangeCrewExp(sld, "Soldiers", 70);
    
    if(pchar.questTemp.Headhunter.Chance1 == 0)
    {
   	    LAi_SetSitTypeNoGroup(sld);
		FreeSitLocator(pchar.questTemp.Headhunter.City + "_tavern", "sit1");
        ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_tavern", "sit", "sit1");
    }
    else
    {
		LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
		ChangeCharacterAddressGroup(sld, pchar.questTemp.Headhunter.City + "_town", "quest", "quest1");
    }
}

void Headhunter_CreateHoumShips(string qName)//cоздание кораблей Хоума
{

    Island_SetReloadEnableGlobal(pchar.questTemp.Headhunter.Island, false);
    Group_FindOrCreateGroup("Houm_Attack");//создать группу
	Group_SetType("Houm_Attack", "war");//тип группы
	
		sld = CharacterFromID("Houm");
		LAi_SetImmortal(sld, false);
		Group_AddCharacter("Houm_Attack", "Houm");//добавим Хоума в группу
		sld = GetCharacter(NPC_GenerateCharacter("Houm_helper", "pirate_1", "man", "man", 35, ENGLAND, -1, true, "quest"));//создание кэпа-помощника
		sld.name = "Андре";
		sld.lastname = "Деготь";
		FantomMakeCoolSailor(sld, SHIP_LIGHTCORVETTE, "", CANNON_TYPE_CANNON_LBS24, 70, 70, 70);//создание кораблика
		FantomMakeCoolFighter(sld, 35, 60, 60, "blade_15", "pistol5", "bullet", 90);//создание фантома кэпа
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_10.tga");
		sld.Ship.Mode = "mercenary";
		sld.AlwaysEnemy = true;
		sld.Abordage.Enable = false;
		Group_AddCharacter("Houm_Attack", "Houm_helper");//добавление в группу
 
    // ==> стравливание
	Group_SetGroupCommander("Houm_Attack", "Houm");
	Group_SetTaskAttack("Houm_Attack", PLAYER_GROUP);
	Group_SetPursuitGroup("Houm_Attack", PLAYER_GROUP);
	Group_SetAddress("Houm_Attack", pchar.questTemp.Headhunter.Island, "quest_ships", "quest_ship_6");
	Group_LockTask("Houm_Attack");
			
    // ==> прерывание на убиение эскадры
    pchar.quest.Headhunter_AfterBattle.win_condition.l1 = "Group_Death";//условие победы
	pchar.quest.Headhunter_AfterBattle.win_condition.l1.group = "Houm_Attack";//какую группу уничтожить
	pchar.quest.Headhunter_AfterBattle.function = "Headhunter_HoumAttack_AfterBattle";//это победа
	pchar.quest.Headhunter_DieHard.win_condition.l1 = "MapEnter";//условие на слинять
    pchar.quest.Headhunter_DieHard.function = "Headhunter_HoumAttack_DieHard";//это слинял
}

void Headhunter_HoumAttack_AfterBattle(string qName)//реакция на победу
{
	Group_DeleteGroup("Houm_Attack");
	Island_SetReloadEnableGlobal(pchar.questTemp.Headhunter.Island, true);
    pchar.quest.Headhunter_DieHard.over = "yes";
	AddQuestRecord("Headhunt", "7");
	pchar.questTemp.Headhunter = "hunt_houm_yes";
}

void Headhunter_HoumAttack_DieHard(string qName)//реакция на поражение
{
	Group_DeleteGroup("Houm_Attack");
    Island_SetReloadEnableGlobal(pchar.questTemp.Headhunter.Island, true);
    pchar.quest.Headhunter_AfterBattle.over = "yes";
	AddQuestRecord("Headhunt", "8");
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
	ChangeOfficersLoyality("bad_all", 1);
}

void Headhunter_PinasseOver(string qName)//не сообразили, куда идти за 30 дней
{
	pchar.quest.Headhunter_Rattortuga.over = "yes";
	sld = characterFromId("RatOfficer");
	sld.lifeDay = 0;
	AddQuestRecord("Headhunt", "10");
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
}

void Headhunter_CreateRatpinasse(string qName)//создание пинаса Аделаида с перпомом
{
	pchar.quest.Headhunter_PinasseOver.over = "yes";

	Group_FindOrCreateGroup("PinasseC");//создать группу
	Group_SetType("PinasseC", "war");//тип группы
	
	sld = GetCharacter(NPC_GenerateCharacter("RatSeaOfficer", "officer_15", "man", "man", 35, FRANCE, -1, true, "quest"));//создание кэпа
	sld.name = "Первый помощник";
	sld.lastname = "Барнс";
	FantomMakeCoolSailor(sld, SHIP_PINNACE, "Аделаида", CANNON_TYPE_CANNON_LBS36, 100, 100, 100);//создание кораблей
	FantomMakeCoolFighter(sld, 35, 80, 80, "blade_15", "pistol2", "bullet", 90);//создание фантома кэпа
	sld.DontRansackCaptain = true; 
	DeleteAttribute(sld, "AlwaysFriend");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	sld.Ship.Mode = "mercenary";
	Group_AddCharacter("PinasseC", "RatSeaOfficer");//добавление в группу
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_17.tga");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "MusketsShoot");
	sld.ship.Crew.Morale = 100;
	ChangeCrewExp(sld, "Sailors", 100);
	ChangeCrewExp(sld, "Cannoners", 100);
	ChangeCrewExp(sld, "Soldiers", 100);
		
	Group_SetGroupCommander("PinasseC", "RatSeaOfficer");
	Group_SetTaskAttack("PinasseC", PLAYER_GROUP);
	Group_SetAddress("PinasseC", "Tortuga", "quest_ships", "quest_ship_1");
	Group_LockTask("PinasseC");
	AddQuestRecord("Headhunt", "15");
			
    // ==> прерывание на убиение эскадры
    pchar.quest.HeadhunterC_AfterBattle.win_condition.l1 = "Group_Death";
	pchar.quest.HeadhunterC_AfterBattle.win_condition.l1.group = "PinasseC";
	pchar.quest.HeadhunterC_AfterBattle.function = "PinasseC_AfterBattle";
}

void PinasseC_AfterBattle(string qName)//реакция на досрочное уничтожение пинаса
{
	sld = characterFromId("RatOfficer");
	sld.lifeDay = 0;
	AddQuestRecord("Headhunt", "16");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
	ChangeCharacterHunterScore(PChar, "frahunter", 30); //начислить НЗГ
	pchar.questTemp.Headhunter = "end_quest";
	CloseQuestHeader("Headhunt");
	Group_DeleteGroup("PinasseC");
}

void CreateRatOfficer()//посадим в таверну самого Крысу - не будем модель прятать
{

	sld = GetCharacter(NPC_GenerateCharacter("RatOfficer", "ozg_piRat", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Матиас";
	sld.lastname = "Грин";
    sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "RatOfficer";
    sld.greeting = "pirat_common";
    GiveItem2Character(sld, "blade_15");
	EquipCharacterbyItem(sld, "blade_15");
    DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
    LAi_SetCitizenType(sld);
   	LAi_SetSitTypeNoGroup(sld);
    ChangeCharacterAddressGroup(sld, "Tortuga_tavern", "sit","sit3");
}

void Headhunter_Ratgulf(string qName)//высадились в заливе
{
	pchar.quest.HeadhunterC_AfterBattle.over = "yes";
	Group_DeleteGroup("PinasseC");
	pchar.quest.Headhunter_RatgulfOver.over = "yes";
	if (GetCompanionQuantity(pchar) > 1 || 2-sti(RealShips[sti(pchar.ship.type)].Class) > 0)
	{
		AddQuestRecord("Headhunt", "19_1");
		AddQuestUserData("Headhunt", "sSex", GetSexPhrase("ся","ась"));
		CloseQuestHeader("Headhunt");
		pchar.questTemp.Headhunter = "end_quest";
	}
	else
	{
		AddQuestRecord("Headhunt", "19");
		pchar.quest.HeadhunterRatgulfTimer.win_condition.l1 = "Timer";
		pchar.quest.HeadhunterRatgulfTimer.win_condition.l1.date.hour  = sti(GetTime() + 24);
		pchar.quest.HeadhunterRatgulfTimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, rand(1));
		pchar.quest.HeadhunterRatgulfTimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, rand(1));
		pchar.quest.HeadhunterRatgulfTimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, rand(1));
		pchar.quest.HeadhunterRatgulfTimer.function = "Headhunter_CreateRatTruepinasse_prepare";
	                        SetTimerFunction("Headhunter_Ratgulf2Over", 0, 0, 5);
		
	}
}

void Headhunter_CreateRatTruepinasse_prepare(string qName)
{
	pchar.quest.Headhunter_RatgulfPinasse.win_condition.l1 = "location";
    pchar.quest.Headhunter_RatgulfPinasse.win_condition.l1.location = "Beliz";//отправляем в локацию
    pchar.quest.Headhunter_RatgulfPinasse.function = "Headhunter_CreateRatTruepinasse";
}

void Headhunter_RatOfficerOver(string qName)//просрочили поговорить с Крысой
{
	pchar.quest.HeadhunterC_AfterBattle.over = "yes";
	Group_DeleteGroup("PinasseC");
	sld = characterFromId("RatOfficer");
	sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "RatOfficer_5";
	sld.lifeDay = 0;
	AddQuestRecord("Headhunt", "17_1");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("ся","ась"));
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
}

void Headhunter_RatgulfOver(string qName)//просрочили дойти до залива
{
	pchar.quest.HeadhunterC_AfterBattle.over = "yes";
	pchar.quest.Headhunter_Ratgulf.over = "yes";
	Group_DeleteGroup("PinasseC");
	AddQuestRecord("Headhunt", "20");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("ся","лась"));
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
}

void Headhunter_Ratgulf2Over(string qName)//страдали фигней вместо поисков после высадки в заливе
{
	pchar.quest.Headhunter_RatgulfPinasse.over = "yes";
	AddQuestRecord("Headhunt", "20_1");
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
}

void Headhunter_CreateRatTruepinasse(string qName)//создание пинаса Аделаида с Крысой
{
	pchar.quest.Headhunter_Ratgulf2Over.over = "yes";

	Group_FindOrCreateGroup("PinasseT");//создать группу
	Group_SetType("PinasseT", "war");//тип группы
	Island_SetReloadEnableGlobal("Beliz", false);
	
	sld = GetCharacter(NPC_GenerateCharacter("RatCaptain", "ozg_piRat", "man", "man", 25, PIRATE, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 25, 70, 70, "blade_19", "pistol6", "bullet", 21);
	FantomMakeCoolSailor(sld, SHIP_PINNACE, "Аделаида", CANNON_TYPE_CANNON_LBS32, 70, 70, 70);
	sld.name = "Матиас";
	sld.lastname = "Грин";
	sld.DontRansackCaptain = true; 
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	sld.Ship.Mode = "mercenary";
	Group_AddCharacter("PinasseT", "RatCaptain");//добавление в группу
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_17.tga");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "MusketsShoot");
	sld.ship.Crew.Morale = 100;
	ChangeCrewExp(sld, "Sailors", 100);
	ChangeCrewExp(sld, "Cannoners", 100);
	ChangeCrewExp(sld, "Soldiers", 100);

		
	// ==> стравливание
	Group_SetGroupCommander("PinasseT", "RatCaptain");
	Group_SetTaskAttack("PinasseT", PLAYER_GROUP);
	Group_SetAddress("PinasseT", "Beliz", "quest_ships", "Quest_ship_8");
	Group_LockTask("PinasseT");
	AddQuestRecord("Headhunt", "21");
			
    // ==> прерывание на убиение эскадры
    pchar.quest.Headhunter_AfterBattle.win_condition.l1 = "Group_Death";
	pchar.quest.Headhunter_AfterBattle.win_condition.l1.group = "PinasseT";
	pchar.quest.Headhunter_AfterBattle.function = "Headhunter_Pinassetrue_AfterBattle";
	pchar.quest.Headhunter_DieHard.win_condition.l1 = "MapEnter";//условие на слинять
    pchar.quest.Headhunter_DieHard.function = "Headhunter_Pinassetrue_DieHard";//это слинял
}

void Headhunter_Pinassetrue_DieHard(string qName)//реакция на поражение
{
	Group_DeleteGroup("PinasseT");
    Island_SetReloadEnableGlobal("Beliz", true);
    pchar.quest.Headhunter_AfterBattle.over = "yes";
	AddQuestRecord("Headhunt", "22");
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";
	ChangeOfficersLoyality("bad_all", 1);
}

void Headhunter_Pinassetrue_AfterBattle(string qName)//реакция на победу
{
	if (!CheckAttribute(pchar, "GenQuest.LastQuestPrisonerIdx"))
	{
		Group_DeleteGroup("PinasseT");
		Island_SetReloadEnableGlobal("Beliz", true);
		pchar.quest.Headhunter_DieHard.over = "yes";
		AddQuestRecord("Headhunt", "24");
		pchar.questTemp.Headhunter = "hunt_rat_yes2";
	}
	else
	{
		characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)].id = "RatCaptain"; //базар в каюте, проверка ИД кэпа
	}
}

void Headhunter_HalenOver(string qName)//опоздали за 10 дней до Кюрасао
{
	AddQuestRecord("Headhunt", "26_1");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("Headhunt");
	pchar.questTemp.Headhunter = "end_quest";	
}

void RatHunters_inRoom(string qName)//идем в комнату
{
	chrDisableReloadToLocation = true;
	LocatorReloadEnterDisable(locations[reload_location_index].fastreload + "_tavern", "reload2_back", true);
	DoQuestCheckDelay("TalkSelf_Quest", 5.0);
}

void RatHunters_Sleep()//спим в комнате
{
	SetLaunchFrameFormParam("Прошло восемь часов...", "", 0, 6);
    LaunchFrameForm();
    WaitDate("", 0, 0, 0, 8, 10); //крутим время
    RecalculateJumpTable();
	DoQuestFunctionDelay("RatHunters_Enter", 0.5);
}

void RatHunters_Enter(string qName)//пришли киллеры
{	
	LAi_SetFightMode(pchar, false);
	LAi_LockFightMode(pchar, true);
	int iTemp = sti(pchar.rank) + MOD_SKILL_ENEMY_RATE;
	for (i=1; i<=2; i++)
	{
		ref sld = GetCharacter(NPC_GenerateCharacter("RatHunters"+i, "officer_7", "man", "man", iTemp, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld, iTemp, 50, 50, "topor_04", "pistol5", "bullet", 50);
		LAi_SetActorType(sld);
		if (i == 1)
		{
			LAi_CharacterDisableDialog(sld);
         	ChangeCharacterAddressGroup(sld, "Villemstad_tavern_upstairs", "goto", "goto2");
		}
		else
		{
			sld.dialog.Filename = "Gothic_Quest\Other_quests_NPC.c";
			sld.dialog.currentnode = "RatHunters";	
			sld.greeting = "Gr_HUNTER"; 
         	ChangeCharacterAddressGroup(sld, "Villemstad_tavern_upstairs", "goto", "goto3");
			LAi_ActorDialog(sld, pchar, "", 2.0, 0); 
		}
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	LAi_group_MoveCharacter(sld, "EnemyFight");
}

void CreateHalen()//создаем Халена и ближайшее окружение
{

	sld = GetCharacter(NPC_GenerateCharacter("Halen", "ozg_martin", "man", "man", 30, HOLLAND, -1, false, "quest"));
	sld.name = "Мартин";
	sld.lastname = "ван Хален";
    sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "Halen";
    sld.greeting = "pirat_common";
    FantomMakeCoolFighter(sld, 30, 70, 70, "blade_32", "pistol3", "bullet", 100);
    ChangeCharacterAddressGroup(sld, "Villemstad_town", "reload", "reload3");
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	GiveItem2Character(sld, "cirass5");
	EquipCharacterbyItem(sld, "cirass5");
	LAi_SetCheckMinHP(sld, (LAi_GetCharacterHP(sld) - 1), false, "Headhunter_FightInPort");//сработает на атаку Халена
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "Headhunter_HalenOut", -1);//сработает, если Хален уйдет
	LAi_Actor2WaitDialog(sld, pchar);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	LocatorReloadEnterDisable("Villemstad_town", "gate_back", false);
	LocatorReloadEnterDisable("Villemstad_town", "reload1_back", false);
	LocatorReloadEnterDisable("Villemstad_town", "reload2_back", false);
	for (i=1; i<=10; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("AddSolder"+i, "Sold_hol_"+(rand(7)+1), "man", "man", 20, HOLLAND, 1, true, "quest"));
		sld.Dialog.Filename = "Common_Soldier.c";
		sld.city = "Villemstad";
		sld.citytype = "soldier";
		FantomMakeCoolFighter(sld, 20, 50, 50, "blade_16", "pistol3", "bullet", 50);
        LAi_SetPatrolType(sld);
		ChangeCharacterAddressGroup(sld, "Villemstad_town", "goto", "goto"+i);    
		LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	}
	LAi_group_SetLookRadius("HOLLAND_CITIZENS", 100);
	LAi_group_SetHearRadius("HOLLAND_CITIZENS", 100);
	pchar.quest.Headhunter_FightInPort.win_condition.l1 = "location";
	pchar.quest.Headhunter_FightInPort.win_condition.l1.location = "Curacao";
	pchar.quest.Headhunter_FightInPort.function = "Headhunter_SeabattleInPort";
}

void Headhunter_SeabattleInPort(string qName)//создание корвета Халена
{

	Group_FindOrCreateGroup("Halen_frigate");//создать группу
	Group_SetType("Halen_frigate", "war");//тип группы
		
	if (GetCharacterIndex("Halen") == -1)
	{
		sld = GetCharacter(NPC_GenerateCharacter("Halen1", "QuestCaptain", "man", "man", 25, HOLLAND, -1, true, "quest"));
	}
	else
	{
		sld = GetCharacter(NPC_GenerateCharacter("Halen1", "ozg_martin", "man", "man", 25, HOLLAND, -1, true, "quest"));//создание кэпа
		sld.name = "Мартин";
		sld.lastname = "ван Хален";
	}
	sld.DontRansackCaptain = true; 
	FantomMakeCoolSailor(sld, SHIP_CORSAIRCORVETTE, "Любовник удачи", CANNON_TYPE_CANNON_LBS24, 70, 70, 70);//создание кораблей
	FantomMakeCoolFighter(sld, 30, 70, 70, "blade_34", "pistol6", "bullet", 100);//создание фантома кэпа
	sld.GenQuest.CrewGuardMode  = true;
	sld.Ship.Mode = "guard";
	Group_AddCharacter("Halen_frigate", "Halen1");//добавление в группу
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_2.tga");
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "MusketsShoot");
	if (GetCharacterIndex("Halen") != -1)
	{
		GiveItem2Character(sld, "cirass5");
	}
	sld.ship.Crew.Morale = 80;
	ChangeCrewExp(sld, "Sailors", 80);
	ChangeCrewExp(sld, "Cannoners", 80);
	ChangeCrewExp(sld, "Soldiers", 80);
		
	// ==> стравливание
	Group_SetGroupCommander("Halen_frigate", "Halen1");
	Group_SetTaskAttack("Halen_frigate", PLAYER_GROUP);
	Group_SetAddress("Halen_frigate", "Curacao", "quest_ships", "Quest_ship_2");
	Group_LockTask("Halen_frigate");
			
    // ==> прерывание на убиение эскадры
                   pchar.quest.Headhunter_AfterBattle.win_condition.l1 = "Group_Death";
	pchar.quest.Headhunter_AfterBattle.win_condition.l1.group = "Halen_frigate";
	pchar.quest.Headhunter_AfterBattle.function = "Headhunter_Halen_frigate_AfterBattle";
	pchar.quest.Headhunter_DieHard.win_condition.l1 = "MapEnter";//условие на слинять
                   pchar.quest.Headhunter_DieHard.function = "Headhunter_Halen_frigate_DieHard";//это слинял
}

void Headhunter_Halen_frigate_DieHard(string qName)//ушли на карту
{
	Group_DeleteGroup("Halen_frigate");
                   Island_SetReloadEnableGlobal("Curacao", true);
                   pchar.quest.Headhunter_AfterBattle.over = "yes";
	if (GetCharacterIndex("Halen") == -1 || GetCharacterIndex("Halen1") == -1)
	{
		AddQuestRecord("Headhunt", "31");
		pchar.questTemp.Headhunter = "hunt_halen_yes";
		ChangeCharacterHunterScore(PChar, "holhunter", 30);
	}
	else
	{
		AddQuestRecord("Headhunt", "30");
		CloseQuestHeader("Headhunt");
		pchar.questTemp.Headhunter = "end_quest";
		ChangeOfficersLoyality("bad_all",1);
	}
	characters[GetCharacterIndex("Halen")].lifeDay = 0;
}

void Headhunter_Halen_frigate_AfterBattle(string qName)//потопили корвет
{
	Group_DeleteGroup("Halen_frigate");
	Island_SetReloadEnableGlobal("Curacao", true);
                   pchar.quest.Headhunter_DieHard.over = "yes";
	AddQuestRecord("Headhunt", "31");
	pchar.questTemp.Headhunter = "hunt_halen_yes";
	ChangeCharacterHunterScore(PChar, "holhunter", 30);
	characters[GetCharacterIndex("Halen")].lifeDay = 0;
}

void CreateMiko()//создадим Мико Пистольеро
{
                    int iRank = 20+MOD_SKILL_ENEMY_RATE;
                    int iScl = 75;
	sld = GetCharacter(NPC_GenerateCharacter("Miko", "ozg_miko", "man", "man", iRank+5, PIRATE, -1, true, "quest")); // patch
	FantomMakeCoolFighter(sld, iRank+5, iScl+15, iScl+15, "blade_28", "pistol4", "bullet", iScl*2+29);
	sld.name = "Мико";
	sld.lastname = "Пистольеро";
                   sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "Miko";
                   sld.greeting = "pirat_common";
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	GiveItem2Character(sld, "indian10");
	GiveItem2Character(sld, "Totem_5");
	GiveItem2Character(sld, "sculMa1");
	LAi_SetCitizenType(sld);
	LAi_SetCharacterUseBullet(sld, "cartridge");
                   TakeNItems(sld, "grapeshot", 24);
	TakeNItems(sld, "bullet", 26);
	TakeNItems(sld, "cartridge", 35);
	TakeNItems(sld, "GunPowder", 31);
	LAi_group_MoveCharacter(sld, "Pearlgroup_2");
	ChangeCharacterAddressGroup(sld, "Vestpunt_town", "goto", "goto15");
	for (i=2; i<=5; i++)//добавим охраны в поселение
	{
		sld = GetCharacter(NPC_GenerateCharacter("AddPearlguard"+i, "Pirate_"+(rand(9)+1), "man", "man", 25, SPAIN, -1, true, "quest"));
		sld.Dialog.Filename = "Pearl_dialog.c";
		sld.dialog.currentnode = "PearlMan";
		sld.city = "Vestpunt_town";
		sld.citytype = "soldier";
		sld.greeting = "pirat_common";
		FantomMakeCoolFighter(sld, 25, 50, 50, "blade_09", "pistol3", "bullet", 100);
                                      LAi_SetPatrolType(sld);
		ChangeCharacterAddressGroup(sld, "Vestpunt_town", "goto", "goto"+i);    
		LAi_group_MoveCharacter(sld, "Pearlgroup_2");
	}
	LAi_group_SetLookRadius("Vestpunt_town", 50);
	LAi_group_SetHearRadius("Vestpunt_town", 50);
}

void Miko_die(string qName)
{
	chrDisableReloadToLocation = false;
	pchar.quest.Headhunter_Jahunters.win_condition.l1 = "location";
	pchar.quest.Headhunter_Jahunters.win_condition.l1.location = "Vestpunt_Port";
	pchar.quest.Headhunter_Jahunters.function = "Headhunter_Jahunters";	
}
		
void Headhunter_Jahunters(string qName)//наймиты бороды в бухте
{

	chrDisableReloadToLocation = false;
	for (i=1; i<=6; i++)
	{
		ref sld = GetCharacter(NPC_GenerateCharacter("JaHunters"+i, "officer_17", "man", "man", 25, PIRATE, -1, true, "quest"));
		FantomMakeCoolFighter(sld, 25, 60, 60, "topor_04", "pistol4", "bullet", 70);
		LAi_SetActorType(sld);
		if (i == 1)
		{
			sld.dialog.Filename = "Gothic_Quest\Other_quests_NPC.c";
			sld.dialog.currentnode = "JaHunters_0";	
			sld.greeting = "Gr_HUNTER"; 
			ChangeCharacterAddressGroup(sld, "Vestpunt_Port", "goto", "goto7");
			LAi_ActorDialog(sld, pchar, "", 10.0, 0); 
			LAi_SetImmortal(sld, true);
		}
		else
		{
			LAi_CharacterDisableDialog(sld);
			ChangeCharacterAddressGroup(sld, "Vestpunt_Port", "goto", "goto6");
		}
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	sld = GetCharacter(NPC_GenerateCharacter("JaMush", "officer_17_mush", "man", "mushketer", 35, PIRATE, -1, true, "quest"));                    
    FantomMakeCoolFighter(sld, iTemp, 80, 80, "", "mushket1", "cartridge", 100);
	ChangeCharacterAddressGroup(sld, "Vestpunt_Port", "goto", "goto9");
	LAi_group_MoveCharacter(sld, "EnemyFight");	
}		
		
void Create_Ja(string qName)//cоздаем Фрегат с бородой
{
                    int iRank = 20+MOD_SKILL_ENEMY_RATE;
                    int iScl = 85;
	Group_FindOrCreateGroup("BlueBird_Group2");
	bQuestDisableMapEnter = true;
	sld = GetCharacter(NPC_GenerateCharacter("Jafarry", "BlBorada", "man", "man", iRank+5, PIRATE, -1, true, "quest")); // patch
	FantomMakeCoolFighter(sld, iRank+15, iScl+25, iScl+25, "blade51", "pistol11", "bullet", iScl*2+29);
	 FantomMakeCoolSailor(sld, SHIP_FRIGATEQVEENT, "Месть королевы Анны", CANNON_TYPE_CANNON_LBS36, iScl+25, iScl+25, iScl+25);
	sld.name 	= "Чёрная Борода";
     sld.lastname = "";
	sld.dialog.filename = "Gothic_Quest\Other_quests_NPC.c";
	sld.dialog.currentnode = "Ja_talk";
	sld.greeting = "CapSinkShip";
	sld.HeroModel = "Tich,Tich_1,Tich_2,Tich_3,Tich_4,protocusto,Tich,Tich";
	sld.CanTakeMushket = true;
	sld.SuperShooter  = true;
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "AboardToFinalDeck");
	sld.AlwaysSandbankManeuver = true;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.WatchFort = true; //видеть форты
	sld.AlwaysEnemy = true;
	sld.DontRansackCaptain = true;
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	sld.Ship.Mode = "mercenary";
	sld.ship.Crew.Morale = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Sailors = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Cannoners = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Soldiers = MOD_SKILL_ENEMY_RATE*6+40;
	sld.Coastal_Captain = true; 
	sld.DontDeskTalk = true;
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	SetCharacterPerk(sld, "MusketsShoot");
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "HP");//корпус

	GiveItem2Character(sld, "indian5");
	GiveItem2Character(sld, "jewelry15");
	GiveItem2Character(sld, "icollection");
	RemoveItems(sld, "spyglass6", 1);
	GiveItem2Character(sld, "spyglass6");
	EquipCharacterbyItem(sld, "spyglass6");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
     TakeNItems(sld, "grapeshot", 34);
	TakeNItems(sld, "bullet", 32);
	TakeNItems(sld, "cartridge", 36);
	TakeNItems(sld, "GunPowder", 33);
	TakeNItems(sld, "potion2", 5);
	GiveItem2Character(sld, "BackPack4");
	Group_AddCharacter("BlueBird_Group2", "Jafarry");
	
	Group_SetGroupCommander("BlueBird_Group2", "Jafarry");
	Group_SetAddress("BlueBird_Group2", "Curacao", "quest_ships", "Quest_ship_9");
	Group_SetTaskAttack("BlueBird_Group2", PLAYER_GROUP);
	Group_LockTask("BlueBird_Group2");
	AddQuestRecord("Headhunt", "36");
	
	pchar.quest.Headhunter_AfterBattleJa.win_condition.l1 = "Group_Death";
	pchar.quest.Headhunter_AfterBattleJa.win_condition.l1.group = "BlueBird_Group2";
	pchar.quest.Headhunter_AfterBattleJa.function = "Ja_over";
}

void Ja_over(string qName)//уничтожили Бороду
{
	Group_DeleteGroup("BlueBird_Group2");
	bQuestDisableMapEnter = false;
	AddQuestRecord("Headhunt", "37");
	AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
	pchar.questTemp.Headhunter = "hunt_ja_yes";

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Пиратская линейка     начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void PiratesLine_q1_tavernEnd()
{
	chrDisableReloadToLocation = false; 
	bDisableFastReload = false; 
	LAI_SetPlayerType(pchar);           
    DoReloadCharacterToLocation("Vestpunt_tavern", "tables", "stay1");
    sld = CharacterFromID("QuestPirate1");
    LAI_SetSitType(sld);
}

void PiratesLine_q1_arrest(string qName)
{
	chrDisableReloadToLocation = true; 
	bDisableFastReload = true; 
	//LocatorReloadEnterDisable("Portroyal_town", "houseS1", true); //закроем дом Моргана
	GetCharacterPos(pchar, &locx, &locy, &locz);
    for (i=1; i<=3; i++)
    {
		sld = GetCharacter(NPC_GenerateCharacter("QuestSold_"+i, "sold_eng_"+i, "man", "man", 20, ENGLAND, 0, true, "soldier"));
		sld.City = "PortRoyal";
		//sld.CityType = "soldier";
		sld.BreakTmplAndFightGroup = true; //реагировать на атаку
		sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
		sld.dialog.currentnode = "ArrestInPR";
		LAi_SetActorType(sld);
		LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
		ChangeCharacterAddressGroup(sld, pchar.location, "patrol", "patrol16");
		if (i == 1) LAi_ActorDialog(sld, pchar, "", -1, 0);
		else LAi_ActorFollow(sld, characterFromId("QuestSold_1"), "", -1);
	}	
	sld = characterFromId("QuestPirate2");
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));	
	LAi_SetActorTypeNoGroup(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
	LAi_ActorFollow(sld, pchar, "", -1);
}

void PiratesLine_q1_toPrison()
{
	sld = characterFromId("QuestPirate2");
	sld.lifeDay = 0;
	ChangeCharacterAddress(sld, "none", "");
	RemovePassenger(pchar, sld);
	DoReloadCharacterToLocation("PortRoyal_prison",  "goto", "goto9");
	RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
	RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
	LAi_LocationFightDisable(&Locations[FindLocation("PortRoyal_prison")], true);
    DoQuestFunctionDelay("PiratesLine_q1_MorganInPrison", 10.0);
    sld = characterFromId("Henry Morgan");
    LAi_SetStayTypeNoGroup(sld);
    ChangeCharacterAddressGroup(sld, "PortRoyal_prison", "goto", "goto13");
	locations[FindLocation("PortRoyal_town")].loginNpc = true;
}

void PiratesLine_q1_MorganInPrison(string qName)
{
    sld = characterFromID("Henry Morgan");
    LAi_SetActorTypeNoGroup(sld);
    LAi_ActorGoToLocator(sld, "goto", "goto23", "PiratesLine_q1_MorganGoTo", -1);
}

void PiratesLine_q1_MorganEnd()
{
	chrDisableReloadToLocation = false; 
	bDisableFastReload = false; 
	LocatorReloadEnterDisable("Portroyal_town", "houseS1", false); //откроем дом Моргана
	LAi_LocationFightDisable(&Locations[FindLocation("PortRoyal_prison")], false);
	pchar.questTemp.jailCanMove = true; //чтобы спокойно выйти из тюрьмы
	AddQuestRecord("Pir_Line_1_JohnBolton", "4");
	DoQuestReloadToLocation("PortRoyal_prison", "goto", "goto12", "");
    sld = characterFromId("Henry Morgan");
    LAi_SetHuberTypeNoGroup(sld);
    ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
}

//пиратка, квест №3, поиски Лоу
void PiratesLine_Loy(string qName)
{
    int iRank = 20+MOD_SKILL_ENEMY_RATE;
    int iScl = 55;
	sld = GetCharacter(NPC_GenerateCharacter("EdwardLoy", "officer_10", "man", "man", iRank+5, PIRATE, -1, true, "quest")); // patch
	FantomMakeCoolFighter(sld, iRank+5, iScl+15, iScl+15, "blade_26", "pistol_04", "grapeshot", iScl*2+100);
	 FantomMakeCoolSailor(sld, SHIP_BRIGSW, "Морской волк", CANNON_TYPE_CANNON_LBS24, iScl+5, iScl+5, iScl+5);
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 2;
	sld.WatchFort = true; //видеть форты
	sld.name = "Эдвард";
	sld.lastname = "Лоу";
	sld.rank = 30;
	sld.city = "LeFransua";
	sld.location	= "LeFransua_House4";
	sld.location.group = "goto";
	sld.location.locator = "goto1";
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "EdwardLoy";
	sld.greeting = "";
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.Ship.Mode = "mercenary";
	sld.ship.Crew.Morale = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Sailors = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Cannoners = MOD_SKILL_ENEMY_RATE*6+20;
	sld.Ship.Crew.Exp.Soldiers = MOD_SKILL_ENEMY_RATE*6+40;
	sld.Coastal_Captain = true; 
	sld.DontDeskTalk = true;
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	SetCharacterPerk(sld, "MusketsShoot");
	SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_16.tga");
	SetCharacterGoods(sld, GOOD_SHIPSILK, 100);
	SetCharacterGoods(sld, GOOD_ROPES, 100);
	SetCharacterGoods(sld, GOOD_SANDAL, 100);
	SetCharacterGoods(sld, GOOD_OIL, 100);
	UpgradeShipParameter(sld, "Capacity");
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "HP");//корпус
	UpgradeShipParameter(sld, "SpeedRate");//скорость
	UpgradeShipParameter(sld, "MaxCrew"); 

	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	GiveItem2Character(sld, "sand_clock");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                   TakeNItems(sld, "bullet", 20);
	TakeNItems(sld, "gunpowder", 31);
                   TakeNItems(sld, "grapeshot", 24);
	TakeNItems(sld,"potion2", 5);
	GiveItem2Character(sld, "BackPack3");
	TakeNItems(sld,"map_cumana", 1);
}

void PiratesLine_q3_LoyHouse(string qName)
{
	AddQuestRecord("Pir_Line_3_KillLoy", "2");
	AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("ся","ась"));
	AddQuestUserData("Pir_Line_3_KillLoy", "sSex1", GetSexPhrase("","а"));
	pchar.questTemp.piratesLine = "KillLoy_toSeek";
}

void PiratesLine_q3_loginSeaWolf(string qName)
{
	if (GetCompanionQuantity(pchar) <= 1 && 5-sti(RealShips[sti(pchar.ship.type)].Class) <= 0)
	{
		sld = characterFromId("EdwardLoy");
		sld.dialog.currentnode   = "SeaWolf";
		pchar.questTemp.piratesLine = "KillLoy_SeaWolfBattle";
		AddQuestRecord("Pir_Line_3_KillLoy", "15");
		AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("ел","ла"));
		AddQuestUserData("Pir_Line_3_KillLoy", "sSex1", GetSexPhrase("","а"));		
		//Group_SetType("SW_Group", "pirate");
		//sTemp = "quest_ship_" + (rand(4)+5);
		Group_AddCharacter("SW_Group", "EdwardLoy");	
		Group_SetGroupCommander("SW_Group", "EdwardLoy");
		Group_SetTaskAttack("SW_Group", PLAYER_GROUP);
		Group_SetAddress("SW_Group", "Cumana", "quest_ships", sTemp);

		pchar.Quest.PiratesLine_q3_over1.win_condition.l1 = "Location_Type";
		pchar.Quest.PiratesLine_q3_over1.win_condition.l1.location_type = "town";
		pchar.Quest.PiratesLine_q3_over1.function = "PiratesLine_q3_over";
		pchar.Quest.PiratesLine_q3_over2.win_condition.l1 = "Location_Type";
		pchar.Quest.PiratesLine_q3_over2.win_condition.l1.location_type = "seashore";
		pchar.quest.PiratesLine_q3_over2.function = "PiratesLine_q3_over";
	}
	else
	{
		pchar.quest.PiratesLine_q3_SeaWolfAgain.win_condition.l1 = "ExitFromLocation";
		pchar.quest.PiratesLine_q3_SeaWolfAgain.win_condition.l1.location = "Cumana";
		pchar.quest.PiratesLine_q3_SeaWolfAgain.function = "PiratesLine_q3_SeaWolfAgain";	
	}
}

void PiratesLine_q3_SeaWolfAgain(string qName)
{
	pchar.quest.PiratesLine_q3_loginSeaWolf.win_condition.l1 = "location";
	pchar.quest.PiratesLine_q3_loginSeaWolf.win_condition.l1.location = "Cumana";
	pchar.quest.PiratesLine_q3_loginSeaWolf.function = "PiratesLine_q3_loginSeaWolf";	
}

void PiratesLine_q3_over(string qName)
{
	pchar.quest.PiratesLine_q3_over1.over = "yes";
	pchar.quest.PiratesLine_q3_over2.over = "yes";
	if (GetCharacterIndex("EdwardLoy") == -1)
	{
		QuestSetCurrentNode("Henry Morgan", "PL_Q3_GoodWork");
		if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_BRIGSW && pchar.ship.name == "Морской волк")
		{
			AddQuestRecord("Pir_Line_3_KillLoy", "17");
			pchar.questTemp.piratesLine.T1 = "KillLoy_GoodWork";
 //выполнено все, корсарский бриг захвачен		
		}
		else
		{
			AddQuestRecord("Pir_Line_3_KillLoy", "18");
			pchar.questTemp.piratesLine.T1 = "KillLoy_LoyIsDied"; //Лоу убит, корсарский бриг не захвачен
		DoQuestCheckDelay("sea_victory", 1.3);
		}
	}
	else
	{
		AddQuestRecord("Pir_Line_3_KillLoy", "16");
		AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","ла"));
		pchar.questTemp.piratesLine = "KillLoy_loose"; //Лоу остался жив, полный провал
		sld = characterFromId("EdwardLoy");
		sld.lifeDay = 0;
		QuestSetCurrentNode("Henry Morgan", "PL_Q3_notFound");
	}
	group_DeleteGroup("SW_Group");
	DeleteAttribute(pchar, "GenQuest.CannotTakeShip");
}

//пиратка, квест №4, грабежи жемчужных тартан
void PQ4_SeaPearl_login(string qName)
{
	pchar.quest.PQ4_SeaPearl_Late.over = "yes";
	LAi_group_Delete("EnemyFight");
	group_DeleteGroup("PearlGroup");
	iTemp = sti(pchar.questTemp.Sharp.PearlAreal.qtyShips);
	Group_FindOrCreateGroup("PearlGroup");
	Group_SetType("PearlGroup", "trade");
	for (int j = 1; j <= iTemp; j++)
	{        
		sTemp = "PearlCapitain_" + j;
		sld = GetCharacter(NPC_GenerateCharacter(sTemp, "Miskito_"+(rand(5)+1), "man", "man", 10, PIRATE, 30, true, "quest"));	
		sld.Ship.Type = GenerateShip(SHIP_TARTANE, false);
		SetRandomNameToShip(sld);
		SetBaseShipData(sld);
		SetCrewQuantityFull(sld);
		Fantom_SetBalls(sld, "pirate");
		sld.ShipTaskLock = true;
		sld.Abordage.Enable = false;
		sld.SinkTenPercent = true; //экономия в АИ шипов
		sld.PearlTartane = true; //тартана ловцов жемчуга, можно грабить
		LAi_group_MoveCharacter(sld, "EnemyFight");
		Group_AddCharacter("PearlGroup", sTemp);
	}
    // ==> стравливание
	Group_SetGroupCommander("PearlGroup", "PearlCapitain_1");			
	Group_SetTaskRunaway("PearlGroup", PLAYER_GROUP);
	Group_SetAddress("PearlGroup", pchar.questTemp.Sharp.PearlAreal.Island, "quest_ships", pchar.questTemp.Sharp.PearlAreal.locator);	
	Group_LockTask("PearlGroup");
	pchar.quest.PQ4_SeaPearl_DieHard1.win_condition.l1 = "ExitFromLocation";
	pchar.quest.PQ4_SeaPearl_DieHard1.win_condition.l1.location = pchar.questTemp.Sharp.PearlAreal.Island;
	pchar.quest.PQ4_SeaPearl_DieHard1.function = "PQ4_SeaPearl_DieHard";
	Pchar.quest.PQ4_SeaPearl_DieHard2.win_condition.l1 = "MapEnter";
	pchar.quest.PQ4_SeaPearl_DieHard2.function = "PQ4_SeaPearl_DieHard";
}

void PQ4_SeaPearl_Late(string qName)
{	
	pchar.quest.PQ4_SeaPearl_login.over = "yes";
	AddQuestRecord("Pir_Line_4_Pearl", "2");
	AddQuestUserData("Pir_Line_4_Pearl", "sSex", GetSexPhrase("","а"));
	pchar.questTemp.piratesLine = "PearlQ4_late";
	sld = characterFromId("Henry Morgan");
    LAi_SetHuberTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
	QuestSetCurrentNode("Henry Morgan", "PL_Q4_late");
}

void PQ4_SeaPearl_DieHard(string qName)
{
	group_DeleteGroup("PearlGroup");
	pchar.quest.PQ4_SeaPearl_DieHard1.over = "yes";
	pchar.quest.PQ4_SeaPearl_DieHard2.over = "yes";
	if (pchar.questTemp.Sharp == "SeaPearl_success")
	{	//успешное нападение
		AddQuestRecord("Pir_Line_4_Pearl", "3");
		AddQuestUserData("Pir_Line_4_Pearl", "iSmall", pchar.questTemp.Sharp.PearlAreal.SmallPearlQty);
		AddQuestUserData("Pir_Line_4_Pearl", "iBig", pchar.questTemp.Sharp.PearlAreal.BigPearlQty);
		pchar.questTemp.piratesLine = "PearlQ4_goodWork";
		QuestSetCurrentNode("Henry Morgan", "PL_Q4_goodWork");
		pchar.questTemp.piratesLine.Qty.SmallPearl = pchar.questTemp.Sharp.PearlAreal.SmallPearlQty;
		pchar.questTemp.piratesLine.Qty.BigPearl = pchar.questTemp.Sharp.PearlAreal.BigPearlQty;
	}
	else
	{	//неудачное нападение
		AddQuestRecord("Pir_Line_4_Pearl", "4");
		AddQuestUserData("Pir_Line_4_Pearl", "sSex", GetSexPhrase("","ла"));
		pchar.questTemp.piratesLine = "PearlQ4_badWork";
		QuestSetCurrentNode("Henry Morgan", "PL_Q4_badWork");
	}
	pchar.questTemp.Sharp = "seekSharp"; //опять начинаем с борделей
	pchar.questTemp.Sharp.brothelChance = rand(10);
	DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
	CloseQuestHeader("SharpPearl");
}

//пиратка, квест №5, работа ОЗГа
void PQ5_meetInPortRoyal(string qName)
{
	chrDisableReloadToLocation = true;
	sld = GetCharacter(NPC_GenerateCharacter("CapGoodly", "officer_9", "man", "man", 20, PIRATE, -1, true, "quest"));
	sld.name = "Капитан";
	sld.lastname = "Гудли";
	sld.rank = 20;
	sld.city = "PortRoyal";
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "PQ5CapGoodly";
	sld.greeting = "Gr_EvilPirate";
    ChangeCharacterAddressGroup(sld, "PortRoyal_town", "patrol", "patrol16");
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	LAi_ActorDialog(sld, pchar, "", 2.0, 0);

//---------- тюремный эскорт  начало ветки охота на волков
	pchar.quest.PrisonEscortBegin.win_condition.l1 = "location";
	pchar.quest.PrisonEscortBegin.win_condition.l1.location = "Villemstad_town";
	pchar.quest.PrisonEscortBegin.win_condition = "PrisonEscort_Begin1";

}

void PQ5_inOrryHouse(string qName)
{
	pchar.questTemp.piratesLine = "PL5Hunter_exitReload";
	LAi_LocationFightDisable(&locations[FindLocation("Pirates_houseSp1")], true); //закроем боевки
	chrDisableReloadToLocation = true; 
	LAi_group_Delete("EnemyFight");

	sld = GetCharacter(NPC_GenerateCharacter("Aivory", "Eivory", "man", "man", 30, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 30, 100, 100, "newblade17", "pistol02", "grapeshot", 45);
	sld.name = "Джон";
	sld.lastname = "Эйвори";
	sld.city = "Pirates";
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "PQ5Hero";
	sld.greeting = "Gr_MiddPirate";
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.SuperShooter  = true;
	sld.equip.gun = "pistol02";
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	AddItems(sld, "gunpowder", 50);
	AddItems(sld, "gold_dublon", 563);
	TakeNItems(sld,"potion2", 3);
	LAi_SetStayType(sld);
	LAi_SetCharacterUseBullet(sld, "grapeshot");
    ChangeCharacterAddressGroup(sld, "Pirates_houseSp1", "goto", "goto1");

	sld = GetCharacter(NPC_GenerateCharacter("Orry", "Orry", "man", "man", 27, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 27, 100, 100, "newblade16", "pistol_06", "bullet", 32);
	sld.name = "Орри";
	sld.lastname = "Брюс";
	sld.city = "Pirates";
	sld.money = 51600;
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld,"potion2", 3);
	sld.equip.gun = "pistol_06";
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.SuperShooter  = true;
	sld.SaveItemsForDead   = true; // сохранять на трупе вещи
	sld.DontClearDead = true;  // не убирать труп через 200с
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "PQ5Orry";
	sld.greeting = "pirat_quest";
	LAi_SetStayType(sld);
	LAi_SetCharacterUseBullet(sld, "bullet");
    ChangeCharacterAddressGroup(sld, "Pirates_houseSp1", "goto", "goto2");

	pchar.quest.PQ5_afterFight.win_condition.l1 = "NPC_Death";
	pchar.quest.PQ5_afterFight.win_condition.l1.character = "Aivory";
	pchar.quest.PQ5_afterFight.win_condition.l2 = "NPC_Death";
	pchar.quest.PQ5_afterFight.win_condition.l2.character = "Orry";
	pchar.quest.PQ5_afterFight.function = "PQ5_afterFight";
}

void PQ5_afterChangeMainHero()
{
	LAi_LocationFightDisable(&locations[FindLocation("Pirates_houseSp1")], false);
    SetMainCharacterIndex(1);
    PChar = GetMainCharacter();
    LAi_SetPlayerType(PChar);
	locCameraTarget(PChar)
    locCameraFollow();	
	rCharacter = characterFromID("Orry");
	LAi_SetActorType(rCharacter);
	LAi_ActorTurnToCharacter(rCharacter, pchar);
	sld = characterFromID("Aivory");
	sld.dialog.currentnode = "PQ5Aivory";
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	EndQuestMovie();
}

void PQ5_afterChangeMainHero2()
{	
	rCharacter = characterFromID("Orry");
	LAi_group_MoveCharacter(rCharacter, "EnemyFight");
	sld = characterFromID("Aivory");			
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
}

void PQ5_afterFight(string qName)
{
	AddQuestRecord("Pir_Line_5_Hunter", "11");
	AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_4 + "Gen"));
	pchar.questTemp.piratesLine = "PL5Hunter_toMorgan";
	chrDisableReloadToLocation = false; 
	Pchar.quest.PQ5_inPortPoyalTavern.win_condition.l1 = "location";
	Pchar.quest.PQ5_inPortPoyalTavern.win_condition.l1.location = "PortRoyal_tavern";
	Pchar.quest.PQ5_inPortPoyalTavern.function = "PQ5_inPortPoyalTavern";
}

void PQ5_inPortPoyalTavern(string qName)
{
	FreeSitLocator("PortRoyal_tavern", "sit3");
	sld = characterFromID("CapGoodly");
	sld.dialog.currentnode = "PQ5CapGoodlyEnd";
	LAi_SetSitTypeNoGroup(sld);
    ChangeCharacterAddressGroup(sld, "PortRoyal_tavern", "sit", "sit3");
}

void PQ5_Morgan_1()
{
	LAi_SetActorType(pchar);
	LAi_ActorGoToLocator(pchar, "goto", "goto2", "PQ5_Morgan_2", -1.0);
}

void PQ5_Morgan_4()
{
    SetMainCharacterIndex(1);
    PChar = GetMainCharacter();
    LAi_SetPlayerType(PChar);
	locCameraTarget(PChar)
    locCameraFollow();	
	rCharacter = characterFromID("CapGoodly");
	LAi_SetActorType(rCharacter);
	LAi_ActorTurnToCharacter(rCharacter, pchar);
	sld = characterFromID("Henry Morgan");
	LAi_SetActorType(pchar);
	LAi_ActorDialog(pchar, sld, "", 0, 0);
}

void PQ5_Morgan_5()
{
	LAi_group_Delete("EnemyFight");
	LAi_SetPlayerType(pchar);
	sld = characterFromID("CapGoodly");
	LAi_group_MoveCharacter(sld, "EnemyFight");
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	pchar.quest.PQ5_Morgan_afterFight.win_condition.l1 = "NPC_Death";
	pchar.quest.PQ5_Morgan_afterFight.win_condition.l1.character = "CapGoodly";
	pchar.quest.PQ5_Morgan_afterFight.function = "PQ5_Morgan_afterFight";
	LAi_SetFightMode(pchar, true);
}

void PQ5_Morgan_afterFight(string qName)
{
	QuestSetCurrentNode("Henry Morgan", "PL_Q5_afterFight");
	AddQuestRecord("Pir_Line_5_Hunter", "13");
	AddQuestUserData("Pir_Line_5_Hunter", "sSex", GetSexPhrase("","а"));
}

//пиратка, квест №6, двойник
void PQ6_ShoreBattle(string qName)
{
                     LAi_group_Delete("EnemyFight"); 
	LocatorReloadEnterDisable("Shore7", "boat", true); //закроем выход в море
	int iRank = 22+MOD_SKILL_ENEMY_RATE;
	int iScl = 55;
	//устанавливаем наших
	// мушкетеры
	int m = makeint(MOD_SKILL_ENEMY_RATE/2);
	if (m < 2) m = 2;
	for (i=1; i<=m; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("OwnPirate_"+i, "mush_ctz_"+(rand(2)+4), "man", "mushketer", iRank, PIRATE, 1, false, "soldier")); // 291112
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket3", "cartridge", iScl*2);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto"+i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}
	// солдаты

    for (i=1; i<=5; i++)
    {
		sld = GetCharacter(NPC_GenerateCharacter("OwnPirate_"+i, "citiz_3"+i, "man", "man", iRank, PIRATE, 1, false, "soldier")); // 291112
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "blade_10", "pistol3", "grapeshot", iScl*2);
                                          LAi_SetWarriorType(sld);
		LAi_warrior_DialogEnable(sld, false);
                                          LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto"+i);
    }
	// устанавливаем врагов
	// мушкетеры
	for (i=1; i<=2; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("QuestPirate_"+i, "mush_ctz_"+(rand(2)+7), "man", "mushketer", iRank, PIRATE, -1, false, "soldier"));
		FantomMakeCoolFighter(sld, iRank+2, iScl+5, iScl+5, "", "mushket3", "cartridge", iScl*2);
		sld.MusketerDistance = 0;
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto"+i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}

	// солдаты
	for (i=1; i<=5; i++)
    {
		sld = GetCharacter(NPC_GenerateCharacter("QuestPirate_"+i, "citiz_4"+i, "man", "man", iRank, PIRATE, -1, false, "soldier"));
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "blade_10", "pistol3", "grapeshot", iScl*2);

        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        PlaceCharacter(sld, "goto", PChar.location);
    }
   // LAi_group_SetLookRadius("EnemyFight", 100);
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
    Pchar.quest.PQ6_JungleDialog.win_condition.l1 = "location";
    Pchar.quest.PQ6_JungleDialog.win_condition.l1.location = "Common_jungle_01";
    Pchar.quest.PQ6_JungleDialog.function = "PQ6_JungleDialog";
}

void PQ6_JungleDialog(string qName)
{
	LAi_LocationFightDisable(&Locations[FindLocation("Common_jungle_01")], true);
	chrDisableReloadToLocation = true;
	string sModel = pchar.model;
	sld = GetCharacter(NPC_GenerateCharacter("QuestPirateHead", sModel, "man", pchar.model.animation, 30, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 30, 90, 90, "blade_27", "pistol6", "bullet", 100);
	sld.name = pchar.name;
	sld.lastname = pchar.lastname;
    sld.dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode = "QuestPirateHead";
	sld.SaveItemsForDead = true;
	ChangeCharacterAddressGroup(sld, "Common_jungle_01", "goto", "goto1");
    LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_ActorDialog(sld, pchar, "", 2.0, 0);
}

void PQ6_JungleBattle()
{
	LAi_LocationFightDisable(loadedLocation, false);
	LAi_SetFightMode(pchar, true);
	int iRank = 22+MOD_SKILL_ENEMY_RATE;
	int iScl = 55;
	int m = makeint(MOD_SKILL_ENEMY_RATE/2);
	//устанавливаем наших
	// мушкетеры
	for (i=1; i<=3; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("QuestPirate2_"+i, "mush_ctz_"+(rand(2)+4), "man", "mushketer", iTemp, sti(pchar.nation), 0, true, "soldier"));
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket3", "cartridge", iScl*2);
        ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}

	string sTemp = NationShortName(sti(pchar.nation));
    for (i=1; i<=7; i++)
    {
        iTemp = 10 + rand(10);
		sld = GetCharacter(NPC_GenerateCharacter("OwnPirate2_"+i, "citiz_3"+i, "man", "man", iTemp, sti(pchar.nation), 0, true, "soldier"));
        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
        ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
    }
	//враги
	for (i=1; i<=(MOD_SKILL_ENEMY_RATE + 7); i++)
    {
        iTemp = 17 + rand(10);
		sld = GetCharacter(NPC_GenerateCharacter("QuestPirate2_"+i, "citiz_4"+i, "man", "man", iTemp, PIRATE, -1, true, "soldier"));
        FantomMakeCoolFighter(sld, iTemp, 90, 90, "blade_10", "pistol3", "grapeshot", 100);
        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, "Common_jungle_01", "goto", "goto2");
    }
	// устанавливаем врагов
	// мушкетеры
	for (i=1; i<=3; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("QuestPirate2_"+i, "mush_ctz_"+(rand(2)+7), "man", "mushketer", "mushketer", iTemp, sti(pchar.nation), 0, true, "soldier"));
		FantomMakeCoolFighter(sld, iRank+2, iScl+5, iScl+5, "", "mushket3", "cartridge", iScl*2);
		sld.MusketerDistance = 0;
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto"+i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}

    LAi_group_SetLookRadius("EnemyFight", 100);
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "PQ6_afterBattle");
}

//пиратка, квест №7, мочим Соукинса
void PQ7_FriendLinney(string qName)
{
	if (GetQuestPastMinutesParam("questTemp.piratesLine") < 20)
	{
		sld = GetCharacter(NPC_GenerateCharacter("FriendLinney", "", "man", "man", 20, sti(pchar.nation), 5, true, "soldier"));							
		SetCaptanModelByEncType(sld, "pirate");
		sld.dialog.filename = "Gothic_Quest\PiratesLine_dialog.c";
		sld.DeckDialogNode = "FriendLinney";
		sld.greeting = "Gr_MiddPirate";
		FantomMakeCoolFighter(sld, 20, 80, 70, "blade_26", "pistol3", "bullet", 20);
		FantomMakeCoolSailor(sld, SHIP_LUGGER, "", CANNON_TYPE_CULVERINE_LBS18, 70, 70, 70);
		sld.AlwaysSandbankManeuver = true;
		sld.DontRansackCaptain = true;
		sld.Ship.Mode = "mercenary";
		DeleteAttribute(sld, "SinkTenPercent");
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
		DeleteAttribute(sld, "AboardToFinalDeck");
		DeleteAttribute(sld, "SinkTenPercent");
		DeleteAttribute(sld, "DontRansackCaptain");		
		sld.AlwaysFriend = true;
		sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
		Group_AddCharacter("FriendLinney_Group", "FriendLinney");			
		Group_SetType("FriendLinney_Group", "pirate");
		Group_SetGroupCommander("FriendLinney_Group", "FriendLinney");
		Group_SetAddress("FriendLinney_Group", "Hispaniola1", "quest_ships", "quest_ship_4");
		Group_SetTaskNone("FriendLinney_Group");
	}
	else
	{
		AddQuestRecord("Pir_Line_7_Soukins", "3");
		AddQuestUserData("Pir_Line_7_Soukins", "sSex", GetSexPhrase("","а"));
		pchar.questTemp.piratesLine = "Soukins_LaVegaLate";
		QuestSetCurrentNode("Henry Morgan", "PL_Q7_LaVegaLate");
	}
}

void PQ7_LoginLeon()
{
	LAi_group_Delete("EnemyFight");
	group_DeleteGroup("FriendLinney_Group"); //сносим друга Стива Линнея
	sld = GetCharacter(NPC_GenerateCharacter("LeonCapitain", "", "man", "man", 25, PIRATE, 30, true, "quest"));							
	SetCaptanModelByEncType(sld, "pirate");
	sld.dialog.filename = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode = "LeonCapitain";
	FantomMakeCoolFighter(sld, 25, 80, 80, "blade_27", "pistol6", "bullet", 50);
	FantomMakeCoolSailor(sld, SHIP_CORVETTE_QUEST, "Леон", CANNON_TYPE_CULVERINE_LBS18, 80, 80, 80);
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.Ship.Mode = "mercenary";
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.DontRansackCaptain = true;
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	LAi_group_MoveCharacter(sld, "EnemyFight");

	string sGroup = "Leon_Group";
	Group_FindOrCreateGroup(sGroup);
	Group_SetType(sGroup,"trade");
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 

	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	
	sld.mapEnc.type = "warrior";
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "Пиратский корвет ''Леон''";
	Map_CreateWarrior("shore33", "LeonCapitain", 30);
	Log_TestInfo("Пиратский корвет ''Леон''!");
}

void PQ7_inSoukinsResidence(string qName)
{
	QuestSetCurrentNode("Henry Morgan", "PL_Q7_BadWork"); //нода, если ничего не сделал
	if (IsLoginTime())
	{
		DoQuestFunctionDelay("PQ7_inSoukinsResidence_2", 1.5);
	}
}

void PQ7_inSoukinsResidence_2(string qName)
{
	LAi_SetActorType(pchar);
	sld = characterFromId("Richard_Soukins");
	QuestSetCurrentNode("Richard_Soukins", "PL_Q7_5");
	LAi_ActorDialog(pchar, sld, "", 0, 0);
}

void PQ7_loadToRecidence(string qName)
{
	DoQuestReloadToLocation("Vestpunt_townhall", "reload", "reload1", "");
}


void Gothic_SoukinsBook() // взяли книгу
{
	LocatorReloadEnterDisable("Vestpunt_townhall", "reload2", true);//закроем 
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_SoukinsBook_1", 3.5);
}

void Gothic_SoukinsBook_1() // взяли книгу
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_SoukinsBook_2", 3.5);
}
void Gothic_SoukinsBook_2() // прочли книгу
{
 	PlaySound("Interface\CHAPTER.wav");
	AddQuestRecordInfo("SoukinsBook", "1");
	DoQuestFunctionDelay("Gothic_SoukinsBook_3", 1.5);
}

void Gothic_SoukinsBook_3() //
{
	AddQuestRecord("Pir_Line_7_Soukins", "9");
	SaveCurrentQuestDateParam("questTemp.piratesLine");
	pchar.questTemp.piratesLine = "Soukins_catchBattleship";
	Pchar.quest.PQ7_setBattleShip.win_condition.l1 = "MapEnter";
	Pchar.quest.PQ7_setBattleShip.function = "PQ7_setBattleShip";
}

void PQ7_setBattleShip(string qName)
{
	if (GetQuestPastMinutesParam("questTemp.piratesLine") > 100)
	{
		Log_TestInfo("Искомый галеон с драгоценностями не будет установлен. Не успел вовремя выйти в море!");
		pchar.questTemp.piratesLine = "Soukins_battlshipLate";
		AddQuestRecord("Pir_Line_7_Soukins", "10");
		AddQuestUserData("Pir_Line_7_Soukins", "sSex", GetSexPhrase("","а"));
	}
	else
	{
		sld = GetCharacter(NPC_GenerateCharacter("QuestCap_PL7", "off_spa_4", "man", "man", 40, SPAIN, -1, true, "soldier"));							
		sld.dialog.filename = "Gothic_Quest\PiratesLine_dialog.c";
		sld.dialog.currentnode = "QuestCap_PL7";
		sld.DeckDialogNode = "QuestCap_PL7_inDeck";
		sld.greeting = "CapSinkShip";
		AddItems(sld, "gunpowder", 50);
		TakeNItems(sld,"potion2", 5);
		sld.equip.gun = "pistol4";
		sld.SuperShooter  = true;
		FantomMakeCoolFighter(sld, 40, 90, 90, "blade_29", "pistol4", "bullet", 200);
		FantomMakeCoolSailor(sld, SHIP_BATTLEGALEON, "Кастилия", CANNON_TYPE_CANNON_LBS32, 90, 90, 90);
		LAi_SetHP(sld, 350+MOD_SKILL_ENEMY_RATE*10, 350+MOD_SKILL_ENEMY_RATE*10);
		DeleteAttribute(sld, "SinkTenPercent");
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
		DeleteAttribute(sld, "AboardToFinalDeck");
		DeleteAttribute(sld, "SinkTenPercent");
		DeleteAttribute(sld, "DontRansackCaptain");
		sld.AlwaysSandbankManeuver = true;
		sld.AnalizeShips = true; 
		sld.DontRansackCaptain = true;
		GiveItem2Character(sld, "cirass4");
		EquipCharacterbyItem(sld, "cirass4");
		GiveItem2Character(sld, "spyglass6");
		EquipCharacterbyItem(sld, "spyglass6");
	LAi_SetCharacterUseBullet(sld, "bullet");
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterGoods(sld, GOOD_SILVER, 600);
	SetCharacterGoods(sld, GOOD_GOLD, 300);
	UpgradeShipParameter(sld, "Capacity");
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "HP");//корпус
	UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
	UpgradeShipParameter(sld, "MaxCrew"); 

		string sGroup = "Quest_Ship";
		Group_FindOrCreateGroup(sGroup);
		Group_SetType(sGroup,"trade");
		Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
		Group_LockTask(sGroup);
		Group_AddCharacter(sGroup, sld.id);
		Group_SetGroupCommander(sGroup, sld.id);
		SetRandGeraldSail(sld, sti(sld.Nation)); 
		
		SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);

		sld.mapEnc.type = "trade";
		sld.mapEnc.worldMapShip = "quest_ship";
		sld.mapEnc.Name = "Галеон с драгоценностями";
		Map_CreateTraderXZ(1009.22, -992.708, 988.514, 515.407, "QuestCap_PL7", 15);
		Log_TestInfo("Искомый галеон с драгоценностями начал движение!");	
	}
}

void PQ7_winBattleShip(string qName)
{
	pchar.questTemp.piratesLine = "Soukins_battlshipWin";
	QuestSetCurrentNode("Henry Morgan", "PL_Q7_GoodWork");
	AddQuestRecord("Pir_Line_7_Soukins", "13");
	pchar.quest.PQ7_BattleShip_dieHard.over = "yes";
}

void PQ8_timeOver(string qName) //убираем моргана
{
	pchar.questTemp.piratesLine = "over";
	sld = characterFromId("Henry Morgan");
	ChangeCharacterAddress(sld, "none", "");
	AddQuestRecord("Pir_Line_8_Panama", "2");
	AddQuestUserData("Pir_Line_8_Panama", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("Pir_Line_8_Panama");
	SetTimerFunction("PQ8_openPanama", 0, 0, 40);
	QuestSetCurrentNode("Oliver_Green", "PL_Q8_over"); //ноду секретарю
}

void PQ8_openPanama(string qName) //откроем Панаму
{
	LocatorReloadEnterDisable("Shore48", "reload1_back", false); 
	LocatorReloadEnterDisable("PortoBello_Jungle_01", "reload1_back", false);
	sld = characterFromId("Henry Morgan");
	sld.dialog.currentnode = "First time";
    ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
    LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
}

void PQ8_openPanama_2(string qName) //откроем Панаму
{
	sld = characterFromId("Henry Morgan");
	if (pchar.questTemp.piratesLine == "Panama_backToShip") 
	{
		SetTimerFunction("PQ8_openPanama_3", 0, 0, 360); 
	}
	else 
	{
		sld.dialog.currentnode = "I_know_you_good";
		ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
		LAi_SetImmortal(sld, true);
		LAi_LoginInCaptureTown(sld, false);
		LAi_SetHuberType(sld);
		LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	}

    //Возвращаем на место Соукинса
	iTemp = GetCharacterIndex("Richard_Soukins");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}                   
		LAi_SetHuberType(&characters[iTemp]);
		LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
        ChangeCharacterAddressGroup(&characters[iTemp], "Vestpunt_townhall", "sit", "sit1");
        characters[iTemp].dialog.currentnode = "First time";
    }
	LocatorReloadEnterDisable("Panama_ExitTown", "reload4", false); 
	SetLocationCapturedState("Panama_town", false);
	bDisableLandEncounters = false;
	pchar.quest.PL_Q8_backFight_1.over = "yes"; //на всякий случай
}

void PQ8_openPanama_3(string qName) //Морган после поездки в Лондон
{
	sld = characterFromId("Henry Morgan");
	sld.dialog.currentnode = "PL_Q8_afterPanama";
	ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
}

void PQ8_PanamaTimerOver(string qName)
{
    if (IsEntity(worldMap))
    {
        if (!bQuestCheckProcessFreeze) // можно показать
		{
	        pchar.quest.PQ8_PanamaTimerOver_01.over = "yes"; // сброс, если уже откладывали
	        pchar.quest.PQ8_PanamaTimerOver_02.over = "yes";
			pchar.quest.PQ8_EnterPortoBello.over = "yes"; //снимаем прерывание на вход
            
            aref arOldMapPos;
			makearef(arOldMapPos, worldMap.old);
            WdmPrepareMapForAbordage(arOldMapPos);
            MakeCloneShipDeck(pchar, true); // подмена палубы
            DoReloadFromWorldMapToLocation("Ship_deck", "goto", "goto5");
	        ReloadFromWMtoL_complete();
	        
            sld = characterFromID("Henry Morgan");
            ChangeCharacterAddressGroup(sld, "Ship_deck", "goto", "goto6");
            LAi_SetWarriorType(sld);
	        LAi_warrior_DialogEnable(sld, true);
	        sld.dialog.currentnode = "PL_Q8_timeOver";
   	        // ==> антураж
            for (i=1; i<5; i++)
        	{
                sTemp = "pirate_" + i;
                sld = GetCharacter(NPC_GenerateCharacter(sTemp, sTemp, "man", "man", 15, PIRATE, 1, true, "soldier"));
                sld.dialog.Filename = "Gothic_Quest\sailors_dialog.c";
	            sld.dialog.currentnode = "Morgan_wait_you";
                LAi_SetWarriorType(sld);
                LAi_warrior_DialogEnable(sld, true);
                LAi_SetLoginTime(sld, 0.0, 24.0);
                LAi_SetHP(sld, 100.0, 100.0);
                ChangeCharacterAddressGroup(sld, "Ship_deck", "goto", "goto"+i);
            }
            pchar.quest.Munity = "";  // признак выхода с палубы (закрыто, а то можно не говорить)
            LAi_LockFightMode(pchar, true);
		}
		else
		{   // отложим до разморозки (пролет табличек)
      		Pchar.quest.PQ8_PanamaTimerOver_01.win_condition.l1 = "MapEnter";
            Pchar.quest.PQ8_PanamaTimerOver_01.function = "PQ8_PanamaTimerOver";
		}
	}
	else
	{   // подождем выхода на карту, раз время прошло, но мы не на ней
		Pchar.quest.PQ8_PanamaTimerOver_02.win_condition.l1 = "MapEnter";
        Pchar.quest.PQ8_PanamaTimerOver_02.function = "PQ8_PanamaTimerOver";
	}
}

void PQ8_EnterPortoBello()
{
	sld = characterFromId("Henry Morgan");
	LAi_SetImmortal(sld, false);
	pchar.quest.PQ8_PanamaTimerOver.over = "yes"; //снимаем таймер 
	//bQuestDisableMapEnter = true;
}

void PQ8_MorganInPortoBello()
{
	chrDisableReloadToLocation = true; 
	DoQuestFunctionDelay("PQ8_MorganInPortoBello_2", 3.0);	
}

void PQ8_MorganInPortoBello_2(string qName)
{	
	sld = characterFromId("Henry Morgan");
	LAi_LoginInCaptureTown(sld, true); 
	LAi_SetCurHPMax(sld);
	sld.dialog.currentNode = "PL_Q8_PBResidence";
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
    LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void PQ8_PBExitResidence(string qName)
{
	iTemp = GetCharacterIndex("Henry Morgan");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}   				
		ChangeCharacterAddress(&characters[iTemp], "none", "");
	}
	iTemp = GetCharacterIndex("Torus");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}   				
		ChangeCharacterAddress(&characters[iTemp], "none", "");
	}
	iTemp = GetCharacterIndex("LEE");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}   				
		ChangeCharacterAddress(&characters[iTemp], "none", "");
	}
	sld = characterFromId("Richard_Soukins");
	sld.DeckDialogNode = "PL_Q8_deck_2";
	AddQuestRecord("Pir_Line_8_Panama", "5");
	pchar.Quest.PQ8_fromPBport.win_condition.l1 = "EnterToSea";
	pchar.Quest.PQ8_fromPBport.function = "PQ8_fromPBport";
	SetTimerFunction("PQ8_controlShore48", 0, 0, 2);
}

void PQ8_fromPBport(string qName)
{
	pchar.Quest.PQ8_controlShore48_1.win_condition.l1 = "Location_Type";
	pchar.Quest.PQ8_controlShore48_1.win_condition.l1.location_type = "town";
	pchar.Quest.PQ8_controlShore48_1.function = "PQ8_controlShore48";
	pchar.Quest.PQ8_controlShore48_2.win_condition.l1 = "Location_Type";
	pchar.Quest.PQ8_controlShore48_2.win_condition.l1.location_type = "x_seashore";
	pchar.Quest.PQ8_controlShore48_2.function = "PQ8_controlShore48";
}

void PQ8_controlShore48(string qName)
{
	pchar.Quest.PQ8_controlShore48.over = "yes";
	pchar.Quest.PQ8_controlShore48_1.over = "yes";
	pchar.Quest.PQ8_controlShore48_2.over = "yes";
	if (pchar.location == "Shore48")
	{	//ГГ вовремя и на месте -->
		LAi_LocationFightDisable(&Locations[FindLocation("Shore48")], true); //закрываем локацию для боевки
		LocatorReloadEnterDisable("Shore48", "boat", true); //Не даем выходить в море
		chrDisableReloadToLocation = true; 
		bDisableLandEncounters = true; //энкаунтеры не генерим
		pchar.questTemp.piratesLine = "Panama_inShore";
		pchar.questTemp.piratesLine.crewHero = makeint(GetCrewQuantity(pchar) / 100 / 2);	//запомним кол-во десанта от ГГ
		if (sti(pchar.questTemp.piratesLine.crewHero) > 5) pchar.questTemp.piratesLine.crewHero = 5;
		pchar.questTemp.piratesLine.crewRichard = 3;   //запомним кол-во десанта от Соукинса
		//бойцы ГГ. предположительно ГГ имет 3 абордажника.
		SetCrewQuantity(pchar, GetMinCrewQuantity(pchar)); //минимальную команду на шип
		iTemp = sti(pchar.questTemp.piratesLine.crewHero) ; //число обычных солдат ГГ
        for (i=1; i<=iTemp; i++)
        {
            sld = GetCharacter(NPC_GenerateCharacter("MHpirate_"+i, "citiz_4"+i, "man", "man", sti(pchar.rank), PIRATE, -1, true, "soldier"));
            LAi_SetWarriorType(sld);
			TakeNItems(sld,"potion1", rand(2)+1);
			LAi_warrior_DialogEnable(sld, false);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
            ChangeCharacterAddressGroup(sld, "Shore48", "goto",  "goto12");
        }	
        for (i=1; i<=iTemp; i++) //мушкетеры ГГ
        {
            sld = GetCharacter(NPC_GenerateCharacter("MHmush_"+i, "mush_ctz_4"+i, "man", "mushketer", sti(pchar.rank), PIRATE, -1, false, "soldier"));
            LAi_SetWarriorType(sld);
			TakeNItems(sld,"potion1", rand(2)+1);
			LAi_warrior_DialogEnable(sld, false);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
            ChangeCharacterAddressGroup(sld, "Shore48", "goto",  "goto12");
        }
		//бойцы Соукинса
		iTemp = sti(pchar.questTemp.piratesLine.crewRichard) ; //число обычных солдат Соукинса
        for (i=1; i<=iTemp; i++)
        {
            sld = GetCharacter(NPC_GenerateCharacter("RSpirate_"+i, "citiz_4"+i, "man", "man", 25, PIRATE, -1, true, "soldier"));
            LAi_SetWarriorType(sld);
			TakeNItems(sld,"potion1", rand(2)+1);
			LAi_warrior_DialogEnable(sld, false);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
            ChangeCharacterAddressGroup(sld, "Shore48", "goto",  "goto2");
		}
        for (i=1; i<=iTemp; i++) //мушкетеры Соукинса
        {
            sld = GetCharacter(NPC_GenerateCharacter("RSmush_"+i, "mush_ctz_"+(rand(11)+1), "man", "mushketer", 25, PIRATE, -1, false, "soldier"));
            LAi_SetWarriorType(sld);
			LAi_warrior_DialogEnable(sld, false);
			TakeNItems(sld,"potion1", rand(2)+1);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
            ChangeCharacterAddressGroup(sld, "Shore48", "goto",  "goto2");
		}
		//офицеры Соукинса
        for (i=1; i<=3; i++)
        {
            sld = GetCharacter(NPC_GenerateCharacter("RSofficer_"+i, "mercen_"+(rand(29)+1), "man", "man", 30, PIRATE, -1, true, "soldier"));
            FantomMakeCoolFighter(sld, 30, 90, 90, "blade_28", "pistol4", "bullet", 100);
			LAi_SetWarriorType(sld);
			LAi_warrior_DialogEnable(sld, false);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
            ChangeCharacterAddressGroup(sld, "Shore48", "goto",  "goto4");
		}
		//сам Соукинс
		sld = characterFromId("Richard_Soukins");
		sld.dialog.currentNode = "Shore48";
		LAi_SetImmortal(sld, false);
		LAi_NoRebirthEnable(sld);
		GiveItem2Character(sld, "blade_23");
		EquipCharacterbyItem(sld, "blade_23");
		GiveItem2Character(sld, "pistol4");
		EquipCharacterbyItem(sld, "pistol4");
		TakeNItems(sld,"potion1", 5);
		RemoveCharacterCompanion(pchar, sld); //убираем Соукинса из компаньонов
		ChangeCharacterAddressGroup(sld, "Shore48", "goto", "goto11");	
		LAi_SetActorType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
		LAi_ActorDialog(sld, pchar, "", -1.0, 0);
		//прерывание на вход в джанглы
		pchar.Quest.PQ8_jungle_05.win_condition.l1 = "location";
		pchar.Quest.PQ8_jungle_05.win_condition.l1.location = "Panama_jungle_05";
		pchar.Quest.PQ8_jungle_05.function = "PQ8_jungle_05";
	}
	else
	{	//ГГ не успел или не туда зашел -->
		iTemp = GetCharacterIndex("Richard_Soukins");
		if (iTemp != -1)
		{
			if(IsCompanion(&characters[iTemp]))  
			{
				RemoveCharacterCompanion(pchar, &characters[iTemp]);
			}                   
			LAi_SetHuberType(&characters[iTemp]);
			LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
            ChangeCharacterAddressGroup(&characters[iTemp], "Vestpunt_townhall", "sit", "sit1");
            characters[iTemp].dialog.currentnode = "First time";
        }
        //Возвращаем на место Торуса
		iTemp = GetCharacterIndex("Torus");
		if (iTemp != -1)
		{              
			LAi_SetHuberType(&characters[iTemp]);
			LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
            ChangeCharacterAddressGroup(&characters[iTemp], "Roseau_townhall", "sit", "sit3");
            characters[iTemp].dialog.currentnode = "First time";
        }
		AddQuestRecord("Pir_Line_8_Panama", "6");
		AddQuestUserData("Pir_Line_8_Panama", "sSex", GetSexPhrase("ся","ась"));
		AddQuestUserData("Pir_Line_8_Panama", "sSex", GetSexPhrase("","а"));
		CloseQuestHeader("Pir_Line_8_Panama");
		SetTimerFunction("PQ8_openPanama", 0, 0, 40);
		LocatorReloadEnterDisable("Shore48", "reload1_back", true); //закрывем подходы к Панаме
		LocatorReloadEnterDisable("PortoBello_Jungle_01", "reload1_back", true);
		pchar.questTemp.piratesLine = "over";
	}
}

void PQ8_jungle_05(string qName)
{ 
	chrDisableReloadToLocation = true;
	pchar.questTemp.piratesLine = "Panama_inJungle";
	//--------------------------- наши ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc5");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc6");
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc7");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc8");
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc"+i);
		}
	}
	//сам Соукинс
	iTemp = GetCharacterIndex("Richard_Soukins");
	if(iTemp != -1 && !LAi_IsDead(&characters[iTemp]))
	{
		sld = &characters[iTemp];
		LAi_SetCurHPMax(sld);
		LAi_SetStayType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		ChangeCharacterAddressGroup(sld, pchar.location, "rld", "loc0");
	}
    //--------------------------- испанцы ------------------------------
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
	for (i=12; i<=18; i++) //max - 21
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==16) sTemp = "off_spa_2";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, -1, true, "soldier"));       
	FantomMakeCoolFighter(sld, sti(pchar.rank), 80, 80, "blade_19", "pistol6", "bullet", 80);
		sld.BreakTmplAndFightGroup = true; 
		LAi_SetActorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }
	iTemp = 8;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 6;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 3;
	for (i=1; i<=iTemp; i++) //max - 11
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "spa_mush_"+(rand(5)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		sld.MusketerDistance = 0;
		LAi_SetWarriorType(sld);
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "PQ8_jungle_afterFight");
	pchar.Quest.PQ8_jungle_04.win_condition.l1 = "location";
	pchar.Quest.PQ8_jungle_04.win_condition.l1.location = "Panama_jungle_04";
	pchar.Quest.PQ8_jungle_04.function = "PQ8_jungle_04";
}


void PQ8_jungle_04(string qName)
{ 
	chrDisableReloadToLocation = true;
	pchar.questTemp.piratesLine = "Panama_inJungle";
	//--------------------------- наши ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc5");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc6");
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc7");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc8");
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc"+i);
		}
	}
	//сам Соукинс
	iTemp = GetCharacterIndex("Richard_Soukins");
	if(iTemp != -1 && !LAi_IsDead(&characters[iTemp]))
	{
		sld = &characters[iTemp];
		LAi_SetCurHPMax(sld);
		LAi_SetStayType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		ChangeCharacterAddressGroup(sld, pchar.location, "rld", "loc0");
	}
    //--------------------------- испанцы ------------------------------
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
	for (i=11; i<=13; i++)
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==14) sTemp = "off_spa_2";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, -1, true, "soldier"));      
        FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_23", "pistol4", "bullet", 100);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }
	for (i=14; i<=17; i++) //индейцы
    {
        if (i==14 || i==16) sTemp = "indsair2";
		else sTemp = "indsar1";
        sld = GetCharacter(NPC_GenerateCharacter("IndEnemy_"+i, "Canib_"+(rand(5)+1), "man", "man", 25, SPAIN, 10, true, "soldier"));
		FantomMakeCoolFighter(sld, Rank, 90, 90, "topor_02", "","", 5);
        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }
	iTemp = 10;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 7;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 4;
    for (i=1; i<=iTemp; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_cnb_"+(rand(2)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "PQ8_jungle_afterFight");
	pchar.Quest.PQ8_jungle_03.win_condition.l1 = "location";
	pchar.Quest.PQ8_jungle_03.win_condition.l1.location = "Panama_jungle_03";
	pchar.Quest.PQ8_jungle_03.function = "PQ8_jungle_03";
}

void PQ8_jungle_03(string qName)
{ 
	chrDisableReloadToLocation = true;
	pchar.questTemp.piratesLine = "Panama_inJungle";
	//--------------------------- наши ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc5");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc6");
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc7");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc8");
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc"+i);
		}
	}
	//сам Соукинс
	iTemp = GetCharacterIndex("Richard_Soukins");
	if(iTemp != -1 && !LAi_IsDead(&characters[iTemp]))
	{
		sld = &characters[iTemp];
		LAi_SetCurHPMax(sld);
		LAi_SetStayType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		ChangeCharacterAddressGroup(sld, pchar.location, "rld", "loc0");
	}
    //--------------------------- испанцы ------------------------------
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
	for (i=11; i<=16; i++)
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==13) sTemp = "off_spa_5";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_21", "pistol4", "bullet", 120);
		sld.BreakTmplAndFightGroup = true; 
		LAi_SetActorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }
	iTemp = 10;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 7;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 4;
    for (i=1; i<=iTemp; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_spa_"+(rand(5)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		sld.MusketerDistance = 0;
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "PQ8_jungle_afterFight");
	pchar.Quest.PQ8_ExitTown.win_condition.l1 = "location";
	pchar.Quest.PQ8_ExitTown.win_condition.l1.location = "Panama_ExitTown";
	pchar.Quest.PQ8_ExitTown.function = "PQ8_ExitTown";
}

void PQ8_ExitTown(string qName)
{ 
	iTemp = GetCharacterIndex("Richard_Soukins");
	if(LAi_IsDead(&characters[iTemp]))
	{	//Соукинс мертв, задание выполнено
		AddQuestRecord("Pir_Line_8_Panama", "7");	
		pchar.questTemp.piratesLine = "Panama_RichardGoodWork";
		sld = GetCharacter(NPC_GenerateCharacter("Vestpunt_mayor", "VanHoorn", "man_B", "man", 5, PIRATE, -1, true, "quest"));
	sld.name = "Николас"; 
	sld.lastname = "ван Хоорн";
	sld.rank = 35; 
	sld.model = "VanHoorn"; 
	sld.model.animation = "man_B"; 
	sld.sex = "man";
	sld.id = "Vestpunt_mayor";
	sld.FaceId = 963;
	sld.reputation = "20";
	sld.alignment = "bad";
	sld.nation = PIRATE
	sld.money = "300000";
	sld.SuperShooter  = true;
	sld.SaveItemsForDead  = true; 
	sld.DontClearDead = true;
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.City = "Vestpunt";
	sld.location	= "Vestpunt_townhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.greeting = "pirat_common";
	sld.Dialog.Filename = "Mayor\Vestpunt_Mayor.c";
	sld.dialog.currentnode   = "First time";
	SetSPECIAL(sld, 9, 9, 9, 9, 7, 10, 4);
	SetSelfSkill(sld, 85, 95, 95, 80, 95);
	SetShipSkill(sld, 95, 95, 95, 95, 100, 95, 100, 95, 95);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "ImmediateReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "Turn180");
	SetCharacterPerk(sld, "SailingProfessional");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "Gunman"); 
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HPPlus");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "HardHitter"); 
	SetCharacterPerk(sld, "Sniper");
	GiveItem2Character(sld, "pistol_04");
	sld.equip.gun = "pistol_04";
	GiveItem2Character(sld, "newblade16");
	sld.equip.blade = "newblade16";
	GiveItem2Character(sld, "spyglass4"); 
	EquipCharacterbyItem(sld, "spyglass4");
	GiveItem2Character(sld, "cirass3"); 
	EquipCharacterbyItem(sld, "cirass3"); 
	GiveItem2Character(sld, "bussol"); 
	EquipCharacterbyItem(sld, "bussol"); 
	LAi_SetCharacterUseBullet(sld, "grapeshot"); 
	TakeNItems(sld, "grapeshot", 100); 
	AddItems(sld, "gunpowder", 100);
	TakeNItems(sld, "potion2", 15);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(sld);
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);
	LAi_SetHP(sld, 450+MOD_SKILL_ENEMY_RATE*10, 450+MOD_SKILL_ENEMY_RATE*10);  
	}
	else
	{	//Соукинс жив, задание провалено
		AddQuestRecord("Pir_Line_8_Panama", "8");	
		pchar.questTemp.piratesLine = "Panama_RichardBadWork";
		sld = &characters[iTemp];
		LAi_SetCurHPMax(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		ChangeCharacterAddressGroup(sld, pchar.location, "rld", "loc2");
	}

	chrDisableReloadToLocation = true;
//	pchar.questTemp.piratesLine = "Panama_inExitTown"; // Warship FIX 19.07.09 - Затирало флаг по Соукинсу

	//--------------------------- наши ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].lifeDay = 10;
			SaveCurrentNpcQuestDateParam(&characters[iTemp], "LifeTimeCreate");
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc15");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].lifeDay = 10;
			SaveCurrentNpcQuestDateParam(&characters[iTemp], "LifeTimeCreate");
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc16");
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].lifeDay = 10;
			SaveCurrentNpcQuestDateParam(&characters[iTemp], "LifeTimeCreate");
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc17");
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].lifeDay = 10;
			SaveCurrentNpcQuestDateParam(&characters[iTemp], "LifeTimeCreate");
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc18");
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].lifeDay = 10;
			SaveCurrentNpcQuestDateParam(&characters[iTemp], "LifeTimeCreate");
			LAi_group_MoveCharacter(&characters[iTemp], LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(&characters[iTemp], pchar.location, "rld",  "loc"+(i+10));
		}
	}
    //--------------------------- люди Моргана ------------------------------

    for (i=1; i<=5; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("MHpirate_"+i, "mush_ctz_"+(rand(11)+1), "man", "mushketer", 25, PIRATE, 10, false, "soldier"));
        LAi_SetWarriorType(sld);
		LAi_warrior_DialogEnable(sld, false);
        LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "loc20");
	}
    for (i=1; i<=5; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("MHpirate_"+i, "mush_ctz_"+(rand(11)+1), "man", "mushketer", 25, PIRATE, 10, false, "soldier"));
        LAi_SetWarriorType(sld);
		LAi_warrior_DialogEnable(sld, false);
        LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "loc19");
	}


    //--------------------------- испанцы ------------------------------
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
	for (i=11; i<=16; i++)
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==13) sTemp = "off_spa_4";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_21", "pistol4", "bullet", 120);
		sld.BreakTmplAndFightGroup = true; 
		LAi_SetActorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }

	for (i=14; i<=17; i++) //индейцы
    {
        if (i==14 || i==16) sTemp = "indsair2";
		else sTemp = "indsar1";
        sld = GetCharacter(NPC_GenerateCharacter("IndEnemy_"+i, "Canib_"+(rand(5)+1), "man", "man", 25, SPAIN, 10, true, "soldier"));
		FantomMakeCoolFighter(sld, Rank, 90, 90, "topor_02", "","", 5);
        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
    }

	iTemp = 10;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 7;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 4;
    for (i=1; i<=iTemp; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_cnb_"+(rand(2)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}

	iTemp = 10;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 7;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 4;
    for (i=1; i<=iTemp; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_spa_"+(rand(5)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		sld.MusketerDistance = 0;
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "PQ8_ExitTown_afterFight");
}

void PQ8_piratesInPanama(string qName)
{
	DeleteAttribute(&colonies[FindColony("PortoBello")], "notCaptured"); //Порто Белло можно себе
	//фантома мэра Панамы - резиденцию
	rCharacter = characterFromId("Panama_Mayor");
	sld = GetCharacter(NPC_GenerateCharacter("FantomMayor", rCharacter.model, "man", "man", sti(rCharacter.rank), sti(rCharacter.nation), -1, false, "soldier"));
	sld.quest.type = "hovernor";
	sld.City = "Panama";
	sld.location = "Panama_TownhallRoom";
	sld.greeting = "spa_gov_common";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
    sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
	sld.Dialog.CurrentNode = "PQ8_Mayor";
	LAi_SetStayType(sld);
	LAi_LoginInCaptureTown(sld, true);
	//--------------------------- наши ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_PirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_PirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_RsPirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_RsPirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_RsPirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
	}
    //--------------------------- люди Моргана ------------------------------
    for (i=1; i<=5; i++)
    {
        iTemp = GetCharacterIndex("HMpirate_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_MPirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
	}
    for (i=1; i<=5; i++)
    {
        iTemp = GetCharacterIndex("HMmush_"+i);
		if(iTemp != -1)
		{
			sld = &characters[iTemp];
			LAi_warrior_DialogEnable(sld, true);
			LAi_LoginInCaptureTown(sld, true);
			sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
			sld.Dialog.CurrentNode = "PQ8_MPirInPan";
			PlaceCharacter(sld, "goto", pchar.location);
		}
	}
}	

void PQ8_MorganInPanama_1(string qName)
{
	chrDisableReloadToLocation = true;
	//делаем видимым ключ
	sld = ItemsFromID("keyPanama");
	sld.shown = true; 
	sld.startLocation = "Panama_ExitTown";
	sld.startLocator = "item4";
	BackItemDescribe("keyPanama");
	BackItemName("keyPanama");
	//Моргана в город и на диалог
	GetCharacterPos(pchar, &locx, &locy, &locz);
	sld = characterFromId("Henry Morgan");
	sld.dialog.currentNode = "PL_Q8_Panama1";
	LAi_LoginInCaptureTown(sld, true);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void PL_Q8_ResEnterBox(string qName)
{
	if (CheckCharacterItem(pchar, "keyPanama"))
    {
		TakeItemFromCharacter(pchar, "keyPanama");
		chrDisableReloadToLocation = true;
		sld = characterFromId("Henry Morgan");
		sld.dialog.currentNode = "PL_Q8_Panama2";		
		ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		LAi_SetActorType(sld);
		LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
	}
	else
	{
		Pchar.quest.PL_Q8_ResEnterBox_2.win_condition.l1 = "ExitFromLocation";
        Pchar.quest.PL_Q8_ResEnterBox_2.win_condition.l1.location = pchar.location;
        Pchar.quest.PL_Q8_ResEnterBox_2.function = "PL_Q8_ResEnterBox_2";
	}
}

void PL_Q8_ResEnterBox_2(string qName)
{
	pchar.quest.PL_Q8_ResEnterBox.win_condition.l1 = "locator";
	pchar.quest.PL_Q8_ResEnterBox.win_condition.l1.location = "Panama_TownhallRoom";
	pchar.quest.PL_Q8_ResEnterBox.win_condition.l1.locator_group = "box";
	pchar.quest.PL_Q8_ResEnterBox.win_condition.l1.locator = "private1";
	pchar.quest.PL_Q8_ResEnterBox.function = "PL_Q8_ResEnterBox";
}

void PL_Q8_inPanamaFort2(string qName)
{
	//возвращаем Торуса Шардонэ
	iTemp = GetCharacterIndex("Torus");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}               
		LAi_SetHuberType(&characters[iTemp]);
		LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
        ChangeCharacterAddressGroup(&characters[iTemp], "Roseau_townhall", "sit", "sit3");
        characters[iTemp].dialog.currentnode = "I_know_you_good";
    }

	//возвращаем Генерала Ли
	iTemp = GetCharacterIndex("LEE");
	if (iTemp != -1)
	{
		if(IsCompanion(&characters[iTemp]))  
		{
			RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}               
		LAi_SetHuberType(&characters[iTemp]);
		LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
        ChangeCharacterAddressGroup(&characters[iTemp], "SantLous_townhall", "sit", "sit1");
    }


	Pchar.quest.PL_Q8_inPanamaPirates_1.win_condition.l1 = "location";
	Pchar.quest.PL_Q8_inPanamaPirates_1.win_condition.l1.location = "Panama_town";
	Pchar.quest.PL_Q8_inPanamaPirates_1.function = "PL_Q8_inPanamaPirates_1";
}

void PL_Q8_inPanamaPirates_1(string qName)
{
	chrDisableReloadToLocation = true;	
	//--------------------------- меняем ноды у оставшихся пиратов ------------------------------
	//расставляем бойцов ГГ
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHpirate_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewHero); i++)
    {
        iTemp = GetCharacterIndex("MHmush_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
    }
    //расставляем бойцов Соукинса
	for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSpirate_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
    }
    for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
    {
        iTemp = GetCharacterIndex("RSmush_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
    }
    //офицеры Соукинса
	for (i=1; i<=3; i++)
    {
        iTemp = GetCharacterIndex("RSofficer_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
	}
    //--------------------------- люди Моргана ------------------------------
    for (i=1; i<=5; i++)
    {
        iTemp = GetCharacterIndex("HMpirate_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
	}
    for (i=1; i<=5; i++)
    {
        iTemp = GetCharacterIndex("HMmush_"+i);
		if(iTemp != -1)
		{
			characters[iTemp].Dialog.CurrentNode = "PQ8_FackMorgan";
		}
	}	
	//разговорный пират
	GetCharacterPos(pchar, &locx, &locy, &locz);
	sld = GetCharacter(NPC_GenerateCharacter("QuestPirate", "citiz_3"+i, "man", "man", 25, PIRATE, 0, true, "soldier"));
	sld.Dialog.Filename = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentNode = "PL_Q8_QFackMorgan";
	LAi_LoginInCaptureTown(sld, true);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto10");
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void PL_Q8_backFight_1(string qName) 
{
    int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	if (Rank < 1) Rank = 1;
	for (i=1; i<=8; i++)
    {
        sTemp = "sold_spa_"+(rand(15)+1);
		if (i==2) sTemp = "SpaOfficer2";
 		sld = GetCharacter(NPC_GenerateCharacter("SpaEnemy_"+i, sTemp, "man", "man", Rank, SPAIN, 12, true, "soldier"));
	FantomMakeCoolFighter(sld, sti(pchar.rank), 90, 90, "blade_26", "pistol4", "bullet", 120);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "loc1");
    }
	iTemp = 10;
	if (MOD_SKILL_ENEMY_RATE < 5) iTemp = 7;
    if (MOD_SKILL_ENEMY_RATE == 1) iTemp = 4;
    for (i=1; i<=iTemp; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("SpaMush_"+i, "mush_cnb_"+(rand(2)+1), "man", "mushketer", Rank, SPAIN, -1, false, "soldier"));
		if (MOD_SKILL_ENEMY_RATE > 5) TakeNItems(sld,"potion1", rand(MOD_SKILL_ENEMY_RATE)+1);
		LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc"+i);
	}
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Пиратская линейка     конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Линейка Теночтитлана          начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//перец, что сваливает из Тено
void Tenoc_startInShore(string qName)
{
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true);
	sld = GetCharacter(NPC_GenerateCharacter("QuestMan_Shore", "shipowner_3", "man", "man", 100, PIRATE, 0, false, "quest"));
	sld.name = "Ренгар";
	sld.lastname = "Риччи";
 	PlaySound("VOICE\Russian\GOTHIC\RENGARU_04.wav");
	sld.dialog.filename   = "Gothic_Quest\Tenochtitlan\ForAll_Teno.c";
	sld.dialog.currentnode   = "Shore53";
	ChangeCharacterAddressGroup(sld, "Bel_jungle_02", "goto", "goto2");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 5.0, 0);

}

void Tenoc_startInShore_2()
{
	pchar.questTemp.Tenoc = "toMontesuma"; //флаг квеста
	sld = characterFromId("QuestMan_Shore");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload3_back", "none", "", "", "CanFightCurLocation", 10.0);
	//Ставим Монтесуму
	sld = GetCharacter(NPC_GenerateCharacter("Montesuma", "Aztec", "man", "man", 50, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 80, 100, 100, "newblade29","", "", 50);
	sld.name = "Монтесума";
	sld.lastname = "";
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	sld.viper = true;
	sld.FaceId = 761;
	sld.location = "Tenochtitlan_1";
	sld.location.group = "quest";
	sld.location.locator = "quest2";
	sld.dialog.filename   = "Gothic_Quest\Tenochtitlan\Montesuma.c";
	sld.dialog.currentnode   = "First time";
	sld.greeting = "Gr_Montesuma";
	sld.reactionOnFightModeOn = true; 
	sld.BreakTmplAndFight = true;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	LAi_SetWarriorType(sld);
	LAi_warrior_SetStay(sld, true);
	LAi_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	//GiveItem2Character(sld, "Totem_0015");
	LAi_group_MoveCharacter(sld, "MontesumaGroup");
	//ставим прерывание на вход в Теночтитлан
	pchar.quest.Tenoc_createAztecTwin.win_condition.l1 = "location";
	pchar.quest.Tenoc_createAztecTwin.win_condition.l1.location = "Tenochtitlan_1";
	pchar.quest.Tenoc_createAztecTwin.function = "Tenoc_createAztecTwin";

	pchar.quest.Tenoc_talkWithTwin.win_condition.l1 = "locator";
	pchar.quest.Tenoc_talkWithTwin.win_condition.l1.location = "Tenochtitlan_1";
	pchar.quest.Tenoc_talkWithTwin.win_condition.l1.locator_group = "teleport";
	pchar.quest.Tenoc_talkWithTwin.win_condition.l1.locator = "fire20";
	pchar.quest.Tenoc_talkWithTwin.function = "Tenoc_talkWithTwin";
	//открываем квест в СЖ
	SetQuestHeader("Tenochtitlan");
	AddQuestRecord("Tenochtitlan", "1");
	AddQuestUserData("Tenochtitlan", "sSex", GetSexPhrase("","а"));
}

//ставим ацтеков граждан
void Tenoc_createAztecTwin(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("AztecCitizen_1", "AztecCitizen1", "man", "man", 15, PIRATE, -1, false, "quest"));
	sld.name = "Мешитли";
	sld.lastname = "";
	sld.dialog.filename   = "Gothic_Quest\Tenochtitlan\AztecCitizens.c";
	sld.dialog.currentnode   = "AztecFT";
	sld.greeting = "cit_common";
	LAi_SetLoginTime(sld, 7.0, 20.0);
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "AztecCitizenGroup");
	ChangeCharacterAddressGroup(sld, "Tenochtitlan_1", "goto", "goto23");

	sld = GetCharacter(NPC_GenerateCharacter("AztecCitizen_2", "AztecCitizen2", "man", "man", 15, PIRATE, -1, false, "quest"));
	sld.name = "Ауисотль";
	sld.lastname = "";
	sld.dialog.filename   = "Gothic_Quest\Tenochtitlan\AztecCitizens.c";
	sld.dialog.currentnode   = "AztecFT2";
	sld.greeting = "cit_common";
	LAi_SetLoginTime(sld, 7.0, 20.0);
	LAi_SetImmortal(sld, true);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "AztecCitizenGroup");  
	ChangeCharacterAddressGroup(sld, "Tenochtitlan_1", "goto", "goto14");	
	//Монтесуму на ГГ
	sld = characterFromId("Montesuma");
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorDialog(sld, pchar, "", 5.0, 0);
}

void Tenoc_talkWithTwin(string qName)
{
	sld = characterFromId("AztecCitizen_1");
	LAi_ActorDialog(sld, pchar, "", 2.5, 0);
}

void Tenoc_MontesumaGoQuest1()
{
	AddQuestRecord("Tenochtitlan", "2");
	AddQuestUserData("Tenochtitlan", "sSex", GetSexPhrase("","а"));
	sld = characterFromId("Montesuma");
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "quest", "quest1", "Tenoc_MontesumaArrived", -1);
}

//бог мертвых разгневан
void LoginDeadmansGod()
{
	chrDisableReloadToLocation = true;//закрыть локацию
                  PlaySound("VOICE\Russian\gotica\SFX\OPENPORTAL.wav");
	for (i=1; i<=8; i++)
	{
	CreateLocationParticles("blast_inv", "item", "torch"+i, 1.15, 0, 0, "");
	}
	CreateLocationParticles("item", "quest", "quest1", 1.20, 2, 2, "");
	CreateLocationParticles("item", "quest", "quest1", 1.20, 2, 2, "");
	CreateLocationParticles("item", "quest", "quest1", 1.20, 2, 2, "");

	DoQuestFunctionDelay("LoginDeadmansGod_0", 5.0);
}

void LoginDeadmansGod_00()
{
                  PlaySound("VOICE\Russian\gotica\SFX\MFX_BARRIERE_SHOOT.wav");
	for (i=1; i<=8; i++)
	{
	CreateLocationParticles("shipfire", "item", "torch"+i, 1.15, 0, 0, "");
	}
	DoQuestFunctionDelay("FIRE_SMALL", 1.0);
}

void LoginDeadmansGod_0()
{
	sld = GetCharacter(NPC_GenerateCharacter("DeadmansGod", "Orc", "Skeleton", "man", 100, PIRATE, 0, true, "Orc"));
	FantomMakeCoolFighter(sld, 50, 100, 100, "newblade29", "", "", 3000); 
	sld.name = "Миктлантекутли";
	sld.lastname = "";
	sld.MultiFighter = 3.0; // мультифайтер
	sld.MultiShooter = 3.0;
	LAi_SetActorType(sld);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
sld.monster = true; // признак нежити
sld.sex = "Skeleton"; 
sld.viper = true;
LAi_SetHP(sld, 1000+MOD_SKILL_ENEMY_RATE*1000, 1000+MOD_SKILL_ENEMY_RATE*1000);
	CreateLocationParticles("large_smoke", "goto", "goto1", 0.5, 0, 0, "");
	DoQuestFunctionDelay("Terrapin_SetMusic", 1.2);
	DoQuestFunctionDelay("LoginDeadmansGod_1", 3.5);
	DoQuestFunctionDelay("FIRE_SMALL", 1.0);

}

void LoginDeadmansGod_1()
{
	sld = characterFromId("DeadmansGod");
	sld.dialog.filename   = "Gothic_Quest\Tenochtitlan\Mictlantecuhtli.c";
	sld.dialog.currentnode   = "InGreateTemple";
	ChangeCharacterAddressGroup(sld, "Templee_great_1", "goto", "goto1");
	CreateLocationParticles("fire_incas_Simple", "goto", "goto1", 0.5, 0, 0, "");
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 0.0, 0);
	LAi_CharacterPlaySound(sld, "DeadmansGod");
}


void Tenoc_fightInTemple()
{
	LAi_LocationFightDisable(loadedLocation, false);
	LAi_SetFightMode(pchar, true);
	sld = characterFromId("DeadmansGod");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "tenoc_monsters_group");
	LAi_group_SetRelation("tenoc_monsters_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("tenoc_monsters_group", LAI_GROUP_PLAYER, true);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	LAi_SetCheckMinHP(sld, 5.0, true, "Tenoc_youWinFight");
}

void Tenoc_Temple()
{
                 DoQuestReloadToLocation("Templee_great_1", "goto", "goto1", "");
}

void Tenoc_exitFromTenoc(string qName)
{
	chrDisableReloadToLocation = false;
	sld = characterFromId("Montesuma");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 0.0, 0);
}

void Tenoc_clearGroups(string qName)
{
	LAi_group_Delete("AztecCitizenGroup");
	LAi_group_Delete("MontesumaGroup");
	LAi_group_Delete("tenoc_monsters_group");
	ChangeItemDescribe("SkullAztecs", "itmdescr_SkullAztecAdd");
	AddQuestRecord("Tenochtitlan", "6");
	CloseQuestHeader("Tenochtitlan");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Линейка Теночтитлана         конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Зачарованный город        начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void MC_startInCaracas(string qName)
{
	if (GetHour() > 9.0 && GetHour() < 20.0 && !LAi_IsCapturedLocation)
	{
		pchar.questTemp.MC = "toCaracas"; //флаг квеста	
		bDisableFastReload = true;
		iTemp = FindLocation("Caracas_town");
		DeleteAttribute(&locations[iTemp], "citizens"); //уберем горожан
		DeleteAttribute(&locations[iTemp], "carrier");	//уберем грузчиков 
		DeleteAttribute(&locations[iTemp], "questSeekCap");	//уберем квестодателя
		//закроем выходы из города
		locations[iTemp].reload.l1.disable = true;
		locations[iTemp].reload.l2.disable = true;
		locations[iTemp].reload.l3.disable = true;
		locations[iTemp].reload.l4.disable = true;
		locations[iTemp].reload.l41.disable = true;
		locations[iTemp].reload.l5.disable = true;
		locations[iTemp].reload.l6.disable = true;
		locations[iTemp].reload.l7.disable = true;
		locations[iTemp].reload.l8.disable = true;
		locations[iTemp].reload.l10.disable = true;
		locations[iTemp].reload.gate.disable = true;
		//очистим таверну
		iTemp = FindLocation("Caracas_tavern");
		DeleteAttribute(&locations[iTemp], "habitues"); //уберем в таверне наполнение нпс
		locations[iTemp].reload.l1.disable = true;
		locations[iTemp].reload.l4.disable = true;
		sld = characterFromId("Caracas_waitress"); //официантку тоже
		ChangeCharacterAddress(sld, "none", "");	
		//ставим горожан
		for (i=1; i<=12; i++)
		{
			sld = GetCharacter(NPC_GenerateCharacter("CaracasCit_"+i, "citiz_"+i, "man", "man", 10, SPAIN, -1, true, "quest"));
			sld.dialog.filename = "Gothic_Quest\MagicCity.c";
			sld.dialog.currentnode = "CaracasMan"; 
			sld.greeting = "cit_common";
			sld.BreakTmplAndFightGroup = true;
			LAi_SetActorType(sld);
			LAi_ActorWaitDialog(sld, pchar);
			LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");	
			ChangeCharacterAddressGroup(sld, "Caracas_town", "quest", "MCquest"+i);
		}
	}
	else
	{
		pchar.quest.MC_startAgain.win_condition.l1 = "MapEnter";
		pchar.quest.MC_startAgain.function = "MC_startAgain";
	}
}

void MC_startAgain(string qName)
{
	pchar.quest.MC_startInCaracas.win_condition.l1 = "location";
	pchar.quest.MC_startInCaracas.win_condition.l1.location = "Caracas_town";
	pchar.quest.MC_startInCaracas.function = "MC_startInCaracas";
}

void MC_endCaracas()
{
	bDisableFastReload = false;
	pchar.questTemp.MC = "toMaracaibo"; //флаг квеста	
	//вернем город
	iTemp = FindLocation("Caracas_town");
	locations[iTemp].citizens = true; 
	locations[iTemp].carrier = true; 
	locations[iTemp].questSeekCap = 8; 
	DeleteAttribute(&locations[iTemp], "reload.l1.disable");	
	DeleteAttribute(&locations[iTemp], "reload.l2.disable");
	DeleteAttribute(&locations[iTemp], "reload.l3.disable");
	DeleteAttribute(&locations[iTemp], "reload.l4.disable");
	DeleteAttribute(&locations[iTemp], "reload.l41.disable");
	DeleteAttribute(&locations[iTemp], "reload.l5.disable");
	DeleteAttribute(&locations[iTemp], "reload.l6.disable");
	DeleteAttribute(&locations[iTemp], "reload.l7.disable");
	DeleteAttribute(&locations[iTemp], "reload.l8.disable");
	DeleteAttribute(&locations[iTemp], "reload.l10.disable");
	DeleteAttribute(&locations[iTemp], "reload.gate.disable");
	DeleteAttribute(&locations[iTemp], "hidden_effects");
	//вернем таверну
	iTemp = FindLocation("Caracas_tavern");
	locations[iTemp].habitues = true;
	DeleteAttribute(&locations[iTemp], "reload.l1.disable");
	DeleteAttribute(&locations[iTemp], "reload.l4.disable");
	sld = characterFromId("Caracas_waitress"); //официантку тоже
	sld.location = "Caracas_tavern";
	sld.location.group = "waitress";
	sld.location.locator = "barmen";
	SetQuestHeader("MagicCity");
	AddQuestRecord("MagicCity", "1");
	pchar.quest.MC_DesMoinesInShore.win_condition.l1 = "location";
	pchar.quest.MC_DesMoinesInShore.win_condition.l1.location = "Shore_ship3";
	pchar.quest.MC_DesMoinesInShore.function = "MC_DesMoinesInShore";
}

void MC_DesMoinesInShore(string qName)
{
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true);
	LAi_group_Delete("EnemyFight");
    for (i=1; i<=MOD_SKILL_ENEMY_RATE; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("ShoreGuard"+i, "mercen_"+(i+10), "man", "man", 20, PIRATE, 0, true, "quest"));
        FantomMakeCoolFighter(sld, 20, 70, 70, "topor_04", "pistol3", "bullet", 50);
		sld.dialog.filename = "Gothic_Quest\MagicCity.c";
		sld.dialog.currentnode = "ShoreGuard";
		sld.greeting = "Gr_ShoreGuard";
		sld.BreakTmplAndFightGroup = true; 
		sld.reactionOnFightModeOn = true; 
                                 LAi_SetActorType(sld);			
                                 LAi_group_MoveCharacter(sld, "EnemyFight");				
		PlaceCharacter(sld, "goto", "random_free");
		LAi_ActorDialog(sld, pchar, "", -1.0, 0);
    }
}

// фрегат Авроры
void SetAvroraFromSeaToMap(string qName)
{
	sld = characterFromId("Avrora");
	//в морскую группу кэпа
	string sGroup = "AvroraGroup";
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	sld.quest = "InMap"; //личный флаг искомого кэпа
	sld.cityShore = GetIslandRandomShoreId(GetArealByCityName(sld.city));
	sld.quest.targetCity = SelectAnyColony(sld.city); //определим колонию, в бухту которой он придет
	sld.quest.targetShore = GetIslandRandomShoreId(GetArealByCityName(sld.quest.targetCity));
	Log_TestInfo("Кэп фрегата Queen вышел из: " + sld.city + " и направился в: " + sld.quest.targetShore);
	//==> на карту
	sld.mapEnc.type = "trade";
	//выбор типа кораблика на карте
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "Фрегат ''Чёрная Жемчужина''";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //дней доехать даем с запасом
	Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, daysQty);
	//меняем сроки проверки по Id кэпа в базе нпс-кэпов
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Зачарованный город     eddy     конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// ----------------- Развод на секс хозяйку офиса ---------------------
void SexWithOffice_nulls(string qName) //нулим квест 
{
	if (pchar.questTemp.different.OfficeSex == "toRoomm")
	{
		sld = characterFromId("W_officer");
		ChangeCharacterAddressGroup(sld,"Roseau_bank", "barmen", "stay");
		LocatorReloadEnterDisable("Roseau_bank", "reload2", true);
	}
	LAi_SetOwnerTypeNoGroup(sld);
	sld.dialog.currentnode = "W_officer";
	sld.quest.NotGoneToSex = true; //не пришел. Секса больше не будет
	DeleteAttribute(pchar, "questTemp.different.OfficeSex");
	pchar.questTemp.different = "free";
}

void SexWithOffice_goToRoomm()  
{
	chrDisableReloadToLocation = true;
	sld = characterFromId("W_officer");
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "Roseau_Office_Room", "goto", "goto6", "OpenTheDoors", -1);
                     pchar.quest.SexWithOffice_inRoomm.win_condition.l1 = "location";
                     pchar.quest.SexWithOffice_inRoomm.win_condition.l1.location = "Roseau_Office_Room";
	pchar.quest.SexWithOffice_inRoomm.function = "SexWithOffice_inRoomm";
                     LocatorReloadEnterDisable("Roseau_bank", "reload2", false);
}

void SexWithOffice_inRoomm(string qName)
{
	DoQuestFunctionDelay("SexWithOffice_inRoomm_2", 1.5);
	LocatorReloadEnterDisable("Roseau_bank", "reload2", false);
}

void SexWithOffice_inRoomm_2(string qName)
{
	sld = characterFromId("W_officer");
	sld.dialog.currentnode = "Office_inSexRoomm";
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorDialog(sld, pchar, "", 0, 0);
}

void SexWithOffice_fackk()
{
	pchar.questTemp.HorseQty = sti(pchar.questTemp.HorseQty) + 1;
	DoQuestCheckDelay("PlaySex_1", 1.0);
	pchar.questTemp.different = "HostessSex";
}

void SexWithOffice(string qName) 
{
	sld = characterFromId("W_officer");
	sld.dialog.currentnode = "W_officer";
	LAi_SetOwnerTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld,"Roseau_bank", "barmen", "stay");
LocatorReloadEnterDisable("Roseau_bank", "reload2", true);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Линейка ГПК           начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void Gothic_letter_LSCC() // нашли вскрытое письмо
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_01", 2.5);
}
void Gothic_letter_LSCC_01() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_02", 2.5);
}
void Gothic_letter_LSCC_02() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("letter_LSCC", "1");
                   pchar.questTemp.LSCC = "CanFoundStuvesantKey";
}


void Gothic_letter_LSCC_1() // нашли письмо Оливера Траста начальству
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_001", 2.5);
}
void Gothic_letter_LSCC_001() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_002", 2.5);
}
void Gothic_letter_LSCC_002() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("letter_LSCC_1", "1");
	DoQuestFunctionDelay("Gothic_letter_LSCC_003", 1.5);
}
void Gothic_letter_LSCC_003() // 
{
	AddQuestRecord("ISS_PoorsMurder", "11");
                   pchar.questTemp.LSCC = "readyGoLSCC";
}



void Gothic_letter_LSCC_2() // Послание Тизера Дэна в сундуке
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_0001", 2.5);
}
void Gothic_letter_LSCC_0001() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_letter_LSCC_0002", 2.5);
}
void Gothic_letter_LSCC_0002() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("letter_LSCC_2", "1");
                   TakeNItems(pchar, "letter_LSCC_2", 1);
}




void ISS_MurderSignExecute(string qName)
{
	pchar.questTemp.LSCC.killCost = sti(pchar.questTemp.LSCC.killCost)-1;
	pchar.questTemp.LSCC = "PoorMurderBegin";
	if (sti(pchar.questTemp.LSCC.killCost) <= 0)
	{
		pchar.questTemp.LSCC = "PoorMurderExecute";
		DeleteAttribute(pchar, "questTemp.LSCC.killCost");
		SetQuestHeader("ISS_PoorsMurder");
		AddQuestRecord("ISS_PoorsMurder", "2");
	}
}

void LSCC_enterStuvesantBox(string qName)
{
	AddQuestRecord("ISS_PoorsMurder", "5");
	AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("ел","ла"));
	pchar.questTemp.LSCC = "toVillemstadTavern";
	//посадим воришку в таверну
	FreeSitLocator("Villemstad_tavern", "sit1");
	sld = GetCharacter(NPC_GenerateCharacter("GiveKeyMan", "shipowner_10", "man", "man", 10, HOLLAND, -1, false, "quest"));
	sld.name = "Хилл";
	sld.lastname = "Корнер";
	sld.city = "Villemstad";
	sld.location	= "Villemstad_tavern";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.dialog.filename   = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode   = "GiveKeyMan";
	sld.greeting = "Gr_Master";
	LAi_SetSitType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
}

void LSCC_openMasterHouse(string qName)
{	
	LocatorReloadEnterDisable("Villemstad_town", "houseSp5", false);
	//делаем видимым ключ
	sld = ItemsFromID("keyQuestLSCC");
	sld.shown = true; 
	pchar.quest.LSCC_enterMasterHouse.win_condition.l1 = "location";
	pchar.quest.LSCC_enterMasterHouse.win_condition.l1.location = "Villemstad_houseSp5";
	pchar.quest.LSCC_enterMasterHouse.function = "LSCC_enterMasterHouse";	
}

void LSCC_enterMasterHouse(string qName)
{
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(&Locations[FindLocation("Villemstad_houseSp5")], true);
	//ставим Мастера Ключей
	sld = characterFromId("GiveKeyMan");
	sld.dialog.currentnode = "GiveKeyManInside";
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Villemstad_houseSp5", "barmen", "bar1");
    LAi_SetActorType(pchar);
    LAi_SetActorType(sld);
    SetActorDialogAny2Pchar("GiveKeyMan", "", 0.0, 1.0);
	LAi_ActorFollow(pchar, sld, "ActorDialog_Any2Pchar", -1);
}

void LSCC_enterSoldiers()
{	
	LAi_SetPlayerType(pchar);
	LAi_group_Delete("EnemyFight"); 
	pchar.questTemp.LSCC = "CanFoundStuvesantKey";
	sld = characterFromId("GiveKeyMan"); 
	LAi_CharacterDisableDialog(sld);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_TmpEnemy);
	LAi_group_SetRelation(LAI_GROUP_TmpEnemy, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	iTemp = sti(pchar.rank) + MOD_SKILL_ENEMY_RATE - 2;
	int iNum = sti((2+MOD_SKILL_ENEMY_RATE)/2);
	for (i=1; i<=iNum; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("MKSold"+i, "sold_hol_"+(rand(7)+1), "man", "man", iTemp, HOLLAND, 0, true, "quest"));
		SetFantomParamFromRank(sld, iTemp, true);         
		LAi_SetWarriorType(sld); 
		//LAi_warrior_SetStay(sld, true);
		LAi_warrior_DialogEnable(sld, false);
        LAi_group_MoveCharacter(sld, "EnemyFight");
        ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto3");
    }
    sld = GetCharacter(NPC_GenerateCharacter("MKOfficer", "off_hol_2", "man", "man", iTemp, HOLLAND, 0, true, "quest"));
	SetFantomParamFromRank(sld, iTemp, true);
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "MK_HollOfficer";
	sld.greeting = "soldier_arest";
    LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
	LAi_ActorDialog(sld, pchar, "", 1.0, 0);
}


void Go_ShipsCityy(string qName) //живем в штормах
{
	for (int i=0;i<MAX_LOCATIONS;i++)
	{				
		if (Locations[i].id == "LostShipsCityy_town")
		{
			Locations[i].alwaysStorm = true; 
			Locations[i].storm = true;
			Locations[i].tornado = true; 
			Locations[i].QuestlockWeather = true;
			Locations[i].MaxWaveHeigh = true;
		}
	}

	for(i=0; i<MAX_LOCATIONS; i++)
	{				
		if (CheckAttribute(&locations[i], "fastreload") && locations[i].fastreload == "LostShipsCityy")
		{
			Locations[i].alwaysStorm = true; 
			Locations[i].storm = true;
			Locations[i].tornado = true; 
			Locations[i].QuestlockWeather = true;
			Locations[i].MaxWaveHeigh = true;
		}
	} 
                 DoReloadCharacterToLocation("LostShipsCityy_town","reload","reload_ring");
}


void FirstLoginLostShipsCityy(string qName) //первоначальная генерация нпс в ГПК
{
	//начальные настройки
	pchar.questTemp.LSCC = "AdmiralIsWaiting";
	bDisableFastReload = true; //закроем переход
	i = FindLocation("LostShipsCityy_town");
	locations[i].private11.items.letter_LSCC_2 = 1;
	//восстанавливаем флаги и пр. в игре вне ГПК
	//CloseQuestHeader("ISS_PoorsMurder");
	//sld = characterFromId("Villemstad_Mayor"); //чтобы мог переезжать
	//DeleteAttribute(sld, "notMoveAble");
	//DeleteAttribute(&colonies[FindColony("Villemstad")], "notCaptured"); //Виллемстад можно себе
	LAi_group_Delete("TmpEnemy"); //группа граждан ГПК
	LAi_group_Delete(LAI_GROUP_TmpEnemy); //группа граждан которых можно валить безнаказанно
	//группы кланов -->
	LAi_group_Delete("PearlGroup_1"); //для кланов заюзаем пока группы жемчужников
	LAi_group_Register("PearlGroup_1");
	LAi_group_SetRelation("PearlGroup_1", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_SetLookRadius("PearlGroup_1", 50);
	LAi_group_SetHearRadius("PearlGroup_1", 20);
	LAi_group_SetSayRadius("PearlGroup_1", 20);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, 0);
	LAi_group_Delete("PearlGroup_2");
	LAi_group_Register("PearlGroup_2");
	LAi_group_SetRelation("PearlGroup_2", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_SetLookRadius("PearlGroup_2", 50);
	LAi_group_SetHearRadius("PearlGroup_2", 20);
	LAi_group_SetSayRadius("PearlGroup_2", 20);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, 0);
	//<-- группы кланов
	//сносим все корабли и компаньонов
	int cn;
	for (i=0; i<=COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(pchar, i);
		if(cn != -1)
		{
			sld = &characters[cn];
			if (i == 0)
			{	//снимаем корабль ГГ
				DeleteAttribute(pchar, "ship");
				pchar.ship.name = "";
				pchar.ship.type = SHIP_NOTUSED;
				SetCharacterShipLocation(pchar, "");
			}
			else
			{
				RemoveCharacterCompanion(pchar, sld);
				sld.lifeDay = 0;
				LAi_KillCharacter(sld);
				i--;
			}
		}
	}
	
	//сносим всех пассажиров и офицеров
	/*
	for (i=0; i<=PASSENGERS_MAX; i++)
	{
		cn = GetPassenger(pchar, i);
		if(cn != -1)
		{
			sld = &characters[cn];
			RemovePassenger(pchar, sld);
			sld.lifeDay = 0;
			LAi_KillCharacter(sld);
			i--;
		}
	}
	*/

     //адмирала на стрем, чтобы ГГ долго не гулял
    PChar.quest.LSCC_stormTimer_1.win_condition.l1            = "Timer";
    PChar.quest.LSCC_stormTimer_1.win_condition.l1.date.hour  = 23;
    PChar.quest.LSCC_stormTimer_1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
    PChar.quest.LSCC_stormTimer_1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
    PChar.quest.LSCC_stormTimer_1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
    PChar.quest.LSCC_stormTimer_1.function = "LSCC_stormTimer_1";
	//Начальные слухи
	AddSimpleRumourCityTip("Будте очень острожны с Августо Брамсом. Чертов чернокнижник...", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Я вам рекомендую держаться подальше от Августо Брамса. Это - страшный человек...", "LostShipsCityy", 10, 1, "LSCC", "");

}

//снять шторм
void LSCC_stormTimer_1(string qName)
{
	for (int i=0;i<MAX_LOCATIONS;i++)
	{				
		if (Locations[i].id == "LostShipsCityy_town")
		{
			DeleteAttribute(&locations[i], "alwaysStorm");
			DeleteAttribute(&locations[i], "storm");
			DeleteAttribute(&locations[i], "tornado");	
			DeleteAttribute(&locations[i], "QuestlockWeather");
			DeleteAttribute(&locations[i], "MaxWaveHeigh");
		}
	}

	for(i=0; i<MAX_LOCATIONS; i++)
	{				
		if (CheckAttribute(&locations[i], "fastreload") && locations[i].fastreload == "LostShipsCityy")
		{
			DeleteAttribute(&locations[i], "alwaysStorm");
			DeleteAttribute(&locations[i], "storm");
			DeleteAttribute(&locations[i], "tornado");	
			DeleteAttribute(&locations[i], "QuestlockWeather");
			DeleteAttribute(&locations[i], "MaxWaveHeigh");
		}
	}

	//адмирал ловит ГГ, если тот еще не явился к нему
	if (pchar.questTemp.LSCC == "AdmiralIsWaiting")
	{
	pchar.quest.LSCC_admiralOwnFind.win_condition.l1 = "location";
	pchar.quest.LSCC_admiralOwnFind.win_condition.l1.location = "LostShipsCityy_town";
	pchar.quest.LSCC_admiralOwnFind.function = "LSCC_admiralOwnFind";
	}
}

void LSCC_admiralOwnFind(string qName)
{
	chrDisableReloadToLocation = true;
	DoQuestFunctionDelay("LSCC_admiralOwnFind_1", 1+rand(2));
}
void LSCC_admiralOwnFind_1(string qName)
{
	sld = characterFromId("LSCCMayor");
	sld.dialog.currentnode = "FoundHero";
	PlaceCharacter(sld, "goto", "random_must_be_near");
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorDialog(sld, pchar, "", 2.0, 0);
}


void LSCC_admiralTakeAll()
{
	chrDisableReloadToLocation = false;
	//установим типовые ключи -->
	sld = ItemsFromID("key1");
	sld.shown = true;
	sld.startLocation = "LostShipsCityy_town";
	sld.startLocator = "item1";
	//--
	sld = ItemsFromID("key2");
	sld.shown = true;
	sld.startLocation = "VelascoShipInside11";
	sld.startLocator = "item1";
	//--
	sld = ItemsFromID("key3");
	sld.shown = true;
	sld.startLocation = "EsmeraldaStoreBigg";
	sld.startLocator = "item1";
	//откроем кланы
	ref rLoc = &locations[FindLocation("LostShipsCityy_town")];
	DeleteAttribute(rLoc, "reload.l61.disable");
	DeleteAttribute(rLoc, "reload.l70.disable");
	DeleteAttribute(rLoc, "reload.l72.disable");
	pchar.questTemp.LSCC = "AfterAdmiral";
	StoreEquippedMaps(pchar); // ugeen --> сохраним карты из атласа дабы Чад не прибрал
	RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
	RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
	RemoveCharacterEquip(pchar, SPYGLASS_ITEM_TYPE);
	RemoveCharacterEquip(pchar, PATENT_ITEM_TYPE);
	RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
	RemoveCharacterEquip(pchar, MAPS_ITEM_TYPE);
	pchar.MapsAtlasCount = 0; 	
	//сносим все предметы, кроме квестовых -->
    aref arItems;
	string sName;
    makearef(arItems, pchar.items);
    int	Qty = GetAttributesNum(arItems);
    for (int a=0; a<Qty; a++)
    {
        sName = GetAttributeName(GetAttributeN(arItems, a));
		rLoc = ItemsFromID(sName);
		if (rLoc.ItemType == "QUESTITEMS")
		{
			pchar.questTemp.items.(sName) = pchar.items.(sName);
		}
    }
	DeleteAttribute(pchar, "items");
	pchar.items = "";
	makearef(arItems, pchar.questTemp.items);
                   Qty = GetAttributesNum(arItems);
                   for (a=0; a<Qty; a++)
                  {
                   sName = GetAttributeName(GetAttributeN(arItems, a));
                   TakeNItems(pchar, sName, sti(arItems.(sName)));
                  }
	DeleteAttribute(pchar, "questTemp.items");
	if(CheckCharacterItem(pchar, "MapsAtlas")) 
	{
		EquipCharacterByAtlas(pchar);	// экипируем атласом, если он есть
		RestoreEquippedMaps(pchar); 	// вернем карты в атлас в 1 экземпляре, все остальное Чадушке или в сундук Тизера
		RefreshEquippedMaps(pchar);
	}	
	//<-- сносим все предметы, кроме квестовых	
	//проверим, не залезал и ГГ в сундучок Тизера -->
	int iLoc = FindLocation("LostShipsCityy_town");
	if (CheckAttribute(&locations[iLoc], "private11.equip"))
	{
		DeleteAttribute(&locations[iLoc], "private11.money"); //если залезал, то заберем денюжки, хи-хи...
	}
	//<-- проверим, не залезал и ГГ в сундучок Тизера
	AddQuestRecord("ISS_MainLine", "3");
	AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("я гол, как сокол","у меня ничего нет"));
	AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("ин","к"));
	//------->>> пул нужных слухов для наводок на квесты		AddSimpleRumourCityTip("", "LostShipsCityy", 10, 1, "LSCC", "");
	//освобождение мужа Элис Тейлор
	LSCC_beginElisHusband();	
	AddSimpleRumourCityTip("Вы знаете, муж Элис Тейлор попал в тюрьму, адмирал посадил его за дебош у него в резиденции. И теперь бедняга Элис просит помочь ей вызволить супруга.", "LostShipsCityy", 10, 1, "LSCC", "LSCC_rumourElisHusband");
	//квест со скелетом Лейтона Декстера
	AddSimpleRumourCityTip("Леа Тоорс недавно вспоминала Лейтона Декстера. Пропал человек буквально в никуда...", "LostShipsCityy", 10, 1, "LSCC", "LSCC_rumourLostDecster");
	//наводка на Доминика Легро с вином
	AddSimpleRumourCityTip("Вы знаете, Доминик Легро ищет бутылку вина. Я не понимаю, как будто сложно её купить где-нибудь.", "LostShipsCityy", 10, 1, "LSCC", "");
}

void LSCC_returnBarmen(string qName)
{
	bDisableFastReload = false; //откроем переход
	pchar.questTemp.LSCC = "toWineCellarLate";
	sld = characterFromId("LSCCBarmen");
	LAi_SetBarmanTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "FleuronTavernn", "barmen",  "stay");
}

void LSCC_returnBarmen_2(string qName)
{
	sld = characterFromId("LSCCBarmen");
	LAi_CharacterEnableDialog(sld);
	LAi_SetBarmanTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "FleuronTavernn", "barmen",  "stay");
}

void LSCC_enterToProtector(string qName)
{
                    chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true); 
                     DoQuestFunctionDelay("LSCC_enterToProtector_1", 7.0);
}

void LSCC_enterToProtector_1(string qName)
{
	LAi_group_Delete("EnemyFight"); 
    sld = GetCharacter(NPC_GenerateCharacter("LSCCQuestMent", "off_hol_6", "man", "man", 25, PIRATE, 0, true, "soldier"));
	FantomMakeCoolFighter(sld, 25, 70, 70, "blade_28", "pistol5", "bullet", 50);
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "LSCCQuestMent";
	LAi_SetCharacterUseBullet(sld, "bullet");
                   TakeNItems(sld, "grapeshot", 11);
	TakeNItems(sld, "bullet", 15);
	TakeNItems(sld, "cartridge", 10);
	TakeNItems(sld, "GunPowder", 14);
                   LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
	LAi_ActorDialog(sld, pchar, "", 1.0, 0);
}

void LSCC_KillOneNarval(string qName)
{
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true); 
                   DoQuestFunctionDelay("LSCC_KillOneNarval_1", 3.0 + frand(4.0));
}

void LSCC_KillOneNarval_1(string qName)
{
	LAi_group_Delete("EnemyFight"); 
    sld = GetCharacter(NPC_GenerateCharacter("LSCCQuestNarval", "officer_8", "man", "man", 25, PIRATE, 0, true, "soldier"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_28", "pistol4", "bullet", 150);
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "LSCCQuestNarval";
	sld.greeting = "Narval";
	ChangeItemName("DOjeronRing", "itmname_DOjeronRingNarval");
	ChangeItemDescribe("DOjeronRing", "itmdescr_DOjeronRingNarval");
	ref itm;
	itm = ItemsFromID("DOjeronRing");
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_4";
	GiveItem2Character(sld, "DOjeronRing");
	LAi_SetCharacterUseBullet(sld, "bullet");
                   TakeNItems(sld, "grapeshot", 13);
	TakeNItems(sld, "bullet", 12);
	TakeNItems(sld, "cartridge", 16);
	TakeNItems(sld, "GunPowder", 14);
	sld.SaveItemsForDead   = true; // сохранять на трупе вещи
	sld.DontClearDead = true;  // не убирать труп через 200с
                   LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload2");
	LAi_ActorDialog(sld, pchar, "", 1.0, 0);
}

void NavalEnterOfficers(string qName)
{
	int idxMent;
	string sOffName;
	chrDisableReloadToLocation = true;
	for (i=1 ; i<=3; i++)
	{
		idxMent = GetCharacterIndex("Ment_" + i);
		if (idxMent != -1)
		{
			ChangeCharacterAddressGroup(&characters[idxMent], "VelascoShipInside11", "officers", "officer_"+i);
			characters[idxMent].Dialog.CurrentNode = "AffterFightN";
			LAi_SetWarriorType(&characters[idxMent]);
			LAi_group_MoveCharacter(&characters[idxMent], LAI_GROUP_PLAYER);
		}
	}
	LAi_group_SetCheck("PearlGroup_1", "NarvalDestroyed");
	LAi_SetImmortal(characterFromId("Narval_head"), false);
}

void NavalExitVelasco(string qName)
{
	int idxMent;
	string sOffName;
	for (i=1 ; i<=3; i++)
	{
		idxMent = GetCharacterIndex("Ment_" + i);
		if (idxMent != -1)
		{
			sld = &characters[idxMent];
			ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
			sld.Dialog.CurrentNode = "First time";
			sld.cityTape = "ment"; //тип нпс
			LAi_SetLSCoutTypeNoGroup(sld);
		}
	}
	//распространим слухи
	AddSimpleRumourCityTip("Говорят, что вы убили всех ''нарвалов''! Вот это да!..", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Н-да, благодаря вам клана ''Нарвал'' более не существует. Ну что же, граждане благодарны вам.", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Хм, вы, конечно, герой и все такое, но, может быть, не стоило так радикально с ''нарвалами'' разбираться?..", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Дайте посмотреть на человека, который внес свое имя в летописи Города! ''Нарвалы'' здорово меня утомили, скажу я вам.", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Благодаря вам ''Веласко'' теперь свободен.", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Честно говоря, я сильно сомневаюсь, что именно клан ''Нарвал'' был причастен к убийству миллиционера и Лабора. Очень сомневаюсь...", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("После уничтожения ''нарвалов'' трудно предположить, как поведут себя ''касперы''...", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("А вы герой, скажу я вам. Не успели появиться в городе, а уже такие дела вершите. Уничтожить целый клан ''Нарвалов''!...", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("''Нарвалы'' сами виноваты в своей судьбе. Я полностью одобряю решение адмирала уничтожить их. Так что, вы молодец.", "LostShipsCityy", 10, 1, "LSCC", "");
	AddSimpleRumourCityTip("Как вы сумели справиться с ''нарвалами'' - ума не приложу. Это были очень хорошие бойцы, очень...", "LostShipsCityy", 10, 1, "LSCC", "");
}

void LSCC_scriptInterception(string qName)
{
	if (pchar.location == "FleuronTavernn")
	{
		LAi_SetActorType(pchar);
		sld = characterFromId("LSCCMayor");
		sld.Dialog.CurrentNode = "Interception";
		LAi_SetActorType(sld);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto3");
		LAi_ActorGoToLocator(sld, "quest", "stay1", "LSCC_EnterComplite_1", -1);
		sld = characterFromId("Casper_head");
		LAi_SetActorType(sld);
		ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		LAi_ActorGoToLocator(sld, "quest", "stay2", "LSCC_EnterComplite_2", -1);		
	}
	else
	{
		pchar.questTemp.LSCC = "InterceptionLate";
		AddQuestRecord("ISS_MainLine", "19");
		AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","ла"));
		AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","а"));
	}
}

void LCS_EndScriptInterception()
{
    //на место камеру и пр.
	SetMainCharacterIndex(1);
    PChar = GetMainCharacter();
    LAi_SetPlayerType(PChar);
	locCameraTarget(PChar)
    locCameraFollow();
    EndQuestMovie(); 
	//разводим адмирала и каспера
	sld = characterFromId("LSCCMayor");
	sld.Dialog.CurrentNode = "First time";
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "goto", "goto3", "", -1.0);
	sld = characterFromId("Casper_head");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "reload", "reload1", "", -1.0);	
	//прерывание на возврат адмирала и каспера на места
	pchar.quest.LCS_EndScriptInterception_2.win_condition.l1 = "ExitFromLocation";
	pchar.quest.LCS_EndScriptInterception_2.win_condition.l1.location = pchar.location;
	pchar.quest.LCS_EndScriptInterception_2.function = "LCS_EndScriptInterception_2";
	if (pchar.questTemp.LSCC == "InterceptionOk")
	AddQuestRecord("ISS_MainLine", "22");
	AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("как полный кретин","как полная дура"));
	AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("","а"));
	else
	AddQuestRecord("ISS_MainLine", "20");
	AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("ся","ась"));
	AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("","а"));

}

void LCS_EndScriptInterception_2(string qName)
{
	sld = characterFromId("LSCCMayor");
	sld.Dialog.CurrentNode = "First time";
	sld.location.going = "toTavern"; //посадим в таверну, ведь он туда пошел
	SaveCurrentNpcQuestDateParam(sld, "location");
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");	
	ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "sit", "sit1");

	sld = characterFromId("Casper_head");
	sld.Dialog.CurrentNode = "First time";
	//LAi_SetImmortal(sld, false);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	ChangeCharacterAddressGroup(sld, "SanGabrielMechanicc", "goto", "goto1");
}


void LSCC_changeBarmen(string qName)
{
	if (pchar.location != "FleuronTavernn") 
	{
		pchar.questTemp.LSCC = "barmenIsDead";
		sld = characterFromId("LSCCBarmen");
                                         sld.name = "Санчо";
                                         sld.lastname = "Карпентеро";
		sld.model = "Carpentero";
	                     sld.greeting = "Carpentero";
        SendMessage(sld, "lss", MSG_CHARACTER_SETMODEL, sld.model, sld.model.animation);
		AddSimpleRumourCityTip("Вы слышали, Хилл Брюннер убит!!!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("Вы слышали последние ужасные известия? Нет? Хилл Брюннер убит!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("Хилл Брюннер, хозяин нашей таверны, был найден в своем погребе мертвым. Вот так!..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("Кто-то убил хозяина таверны Хилла Брюннера! Сначала Андрэ Лабор, теперь вот Хилл Брюннер. М-да, ужасные новости!..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("А вы знаете, что Хилла Брюннера убили? Зарезали в его же винном погребе!!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("Хилл Брюннер мертв! Очень и очень жаль этого человека. С его уходом в мир иной Город многое потерял, ведь он был старейшим жителем!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
		AddSimpleRumourCityTip("Вы знаете, Хилл Брюннер мертв! Что теперь будет с таверной?..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	}
	else
	{
		pchar.quest.LSCC_changeBarmen_2.win_condition.l1 = "ExitFromLocation";
		pchar.quest.LSCC_changeBarmen_2.win_condition.l1.location = pchar.location;
		pchar.quest.LSCC_changeBarmen_2.function = "LSCC_changeBarmen_2";
	}
}

void LSCC_changeBarmen_2(string qName)
{
	                   pchar.questTemp.LSCC = "barmenIsDead";
	                    sld = characterFromId("LSCCBarmen");
                                         sld.name = "Санчо";
                                         sld.lastname = "Карпентеро";
		sld.model = "Carpentero";
	                     sld.greeting = "";
    SendMessage(sld, "lss", MSG_CHARACTER_SETMODEL, sld.model, sld.model.animation);
	AddSimpleRumourCityTip("Вы слышали, Хилл Брюннер убит!!!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	AddSimpleRumourCityTip("Вы слышали последние ужасные известия? Нет? Хилл Брюннер убит!", "LostShipsCityy", 10, 1, "LSCC", "LSC_HillBrunnerDead");
	AddSimpleRumourCityTip("Хилл Брюннер, хозяин нашей таверны, был найден в своем погребе мертвым. Вот так!..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	AddSimpleRumourCityTip("Кто-то убил хозяина таверны Хилла Брюннера! Сначала Андрэ Лабор, теперь вот Хилл Брюннер. М-да, ужасные новости!..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	AddSimpleRumourCityTip("А вы знаете, что Хилла Брюннера убили? Зарезали в его же винном погребе!!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	AddSimpleRumourCityTip("Хилл Брюннер мертв! Очень и очень жаль этого человека. С его уходом в мир иной Город многое потерял, ведь он был старейшим жителем!", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
	AddSimpleRumourCityTip("Вы знаете, Хилл Брюннер мертв! Что теперь будет с таверной?..", "LostShipsCityy", 10, 1, "LSCC", "LSCC_HillBrunnerDead");
}

void LSCC_SaveSesilGalard(string qName)
{
	if (pchar.location.locator == "reload1") sTemp = "goto5";
	else sTemp = "goto4";
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true);
	sld = characterFromId("SesilGalard");
	sld.dialog.currentnode = "HelpMe";
	sld.greeting = "Enc_RapersGirl_1";
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	GiveItem2Character(sld, "unarmed");
	EquipCharacterbyItem(sld, "unarmed");
	ChangeCharacterAddressGroup(sld, pchar.location, "goto",  sTemp);
	LAi_ActorDialog(sld, pchar, "", 1.0, 0);
}

void LSCC_SaveSesilGalard_2()
{	
	LAi_SetFightMode(pchar, true);
	LAi_LocationFightDisable(loadedLocation, false);
	//Сесилия
	sld = characterFromID("SesilGalard");
	LAi_SetActorTypeNoGroup(sld);
	if (pchar.location.locator == "reload1") 
	{		
		LAi_ActorRunToLocator(sld, "barmen", "bar2", "LSCC_SesilAfraid", -1);	
	}
	else 
	{
		LAi_ActorRunToLocator(sld, "barmen", "stay", "LSCC_SesilAfraid", -1);	
	}
	//клановцы
	LAi_group_Delete("EnemyFight");
	iTemp = 10+MOD_SKILL_ENEMY_RATE*2;
    for (i=1; i<=3; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("LSCCBandit"+i, "officer_"+(i+3), "man", "man", iTemp, PIRATE, 0, true, "soldier"));
        FantomMakeCoolFighter(sld, iTemp, 80, 80, "topor_04", "pistol6", "bullet", 50);
        LAi_SetCharacterUseBullet(sld, "bullet");
        TakeNItems(sld, "grapeshot", 12);
        TakeNItems(sld, "bullet", 10);
        TakeNItems(sld, "cartridge", 11);
        TakeNItems(sld, "GunPowder", 15);
        LAi_SetWarriorType(sld);			
        LAi_group_MoveCharacter(sld, "EnemyFight");				
        if (i == 2)
			ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload2");
		else
			ChangeCharacterAddressGroup(sld, pchar.location, "quest",  "start"+i);
    }
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
    LAi_group_SetCheck("EnemyFight", "LSCC_SesilAfterFight");
}

//вход к касперам на Сан Габриэль
void LSCC_enterCasper(string qName)
{	
	//если тюремщик Томас Бойл с нами
	iTemp = GetCharacterIndex("LSCC_Prisoner1");
	if (iTemp != -1 && characters[iTemp].location == "SanGabrielMechanicc") 
	{
		characters[iTemp].reactionOnFightModeOn = true; //среагировать на обнаженку оружия
		characters[iTemp].lifeDay = 0;
		LAi_warrior_DialogEnable(&characters[iTemp], true);
		LAi_group_SetCheck("PearlGroup_2", "LSCC_PrisonerAfterFight");
	}
	//касперы
	iTemp = GetCharacterIndex("Casper_head");
	if (iTemp != -1 && characters[iTemp].location == "SanGabrielMechanicc") 
	{
		chrDisableReloadToLocation = true;
		LAi_group_SetCheck("PearlGroup_2", "OpenTheDoors");
		AddSimpleRumourCityTip("Говорят, что вы убили всех ''касперов''! Однако...", "LostShipsCityy", 10, 1, "LSCC", "");
		AddSimpleRumourCityTip("Не скажу, что мне жаль этих отморозков ''касперов''. Туда им и дорога...", "LostShipsCityy", 10, 1, "LSCC", "");
		AddSimpleRumourCityTip("Однако, вы лихой вояка! Сначала ''нарвалы'', потом ''касперы''! Лихо...", "LostShipsCityy", 10, 1, "LSCC", "");
		AddSimpleRumourCityTip("Да, неплохо вы поработали шпагой. Клан ''Каспер'' канул в лету... Что же, отлично!", "LostShipsCityy", 10, 1, "LSCC", "");
		AddSimpleRumourCityTip("Знаете, ''касперы'' особо мне не досаждали. Поэтому их массовая гибель мне не так уж и приятна....", "LostShipsCityy", 10, 1, "LSCC", "");
	}
	//откроем возможность попасть к механику.
	LocatorReloadEnterDisable("SanGabrielMechanicc", "reload2", false);
	LocatorReloadEnterDisable("LostShipsCityy_town", "reload55", false);
	pchar.questTemp.LSCC = "toSeekMechanikCanMove";
	DeleteAttribute(pchar, "questTemp.LSCC.Armo");
}

//прерывание на завал каспера от Армо
void LSCC_KillOneCasper(string qName)
{
	pchar.quest.LSCC_checkCasperDead.over = "yes"; 
	if (sti(pchar.questTemp.LSCC.Armo) < 5)
	{		
		iTemp = sti(pchar.quest.(qName).casperIdx);
		pchar.questTemp.LSCC.Armo = sti(pchar.questTemp.LSCC.Armo) + 1; //на следующего...
		pchar.questTemp.LSCC.Armo.waiting = true;
		AddQuestRecord("ISS_MainLine", "36");
		AddQuestUserData("ISS_MainLine", "sName", GetFullName(&characters[iTemp]));
		AddSimpleRumourCityTip("Говорят, что вчера ночью кто-то дрался на флейте ''Церес Смити''.", "LostShipsCityy", 2, 1, "LSCC", "");
		AddSimpleRumourCityTip("Элис Тейлор, хозяйка флейта ''Церес Смити'', слышала вчера ночью возню на палубе. Все это очень напоминало серьезную рубку...", "LostShipsCityy", 2, 1, "LSCC", "");
	}
	else
	{	//засада после третьего каспера
		DoQuestFunctionDelay("LSCC_KillOneCasper_3", 4.0);
		chrDisableReloadToLocation = true;
	}
}

void LSCC_KillOneCasper_3(string qName)
{
	LAi_SetFightMode(pchar, false);
	LAi_LockFightMode(pchar, true);
	GetCharacterPos(pchar, &locx, &locy, &locz);
	sld = characterFromId("Casper_6");
	sld.dialog.currentnode = "FackYou";
	LAi_SetActorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", LAi_FindNearestLocator("reload", locx, locy, locz));
	LAi_ActorDialog(sld, pchar, "", -1.0, 0);
}
//таймер завален ли каспер от Армо
void LSCC_checkCasperDead(string qName)
{
	pchar.quest.LSCC_KillOneCasper.over = "yes"; 
	iTemp = sti(pchar.quest.(qName).casperIdx);
	if (!LAi_IsDead(&characters[iTemp]))
	{
		pchar.questTemp.LSCC.Armo = 11; //профукал каспера
		sld = &characters[iTemp];
		sld.dialog.currentnode   = "First time";
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "PearlGroup_2");
		ChangeCharacterAddressGroup(sld, "SanGabrielMechanicc", "goto", "goto9");
	}
}

void LSCC_3CarperAttackArmo()
{
	LAi_SetFightMode(pchar, true);
	chrDisableReloadToLocation = false;
	GetCharacterPos(pchar, &locx, &locy, &locz);
	//меняем убитую Армо
	sld = characterFromId("LSCCwaitress");
                     sld.dialog.currentnode = "ArmoIsDead";
	sld.name = "Флора";
                     sld.lastname = "Прескотт";
	sld.model = "Women_21";
	sld.sex = "woman";
	sld.model.animation	= "woman";
    SendMessage(sld, "lss", MSG_CHARACTER_SETMODEL, sld.model, sld.model.animation);
    AddSimpleRumourCityTip("Вы слышали, убили бедную Армо Дюлин! Эх, какая хорошая девушка была...", "LostShipsCityy", 10, 1, "LSCC", "");
    AddSimpleRumourCityTip("Боже мой, теперь, вот, и Армо мертва. Пожалуй, пора искать надежное убежище...", "LostShipsCityy", 10, 1, "LSCC", "");
    AddSimpleRumourCityTip("Куда смотрит адмирал?! Убиты уже несколько человек, а теперь вот и бедняжка Армо...", "LostShipsCityy", 10, 1, "LSCC", "");
	//первый каспер
	sld = characterFromId("Casper_6");
	sld.quest.checkCasper = true; //для обработки в АИ warrior
	LAi_SetWarriorTypeNoGroup(sld);
	//второй
	sld = characterFromId("Casper_7");
	sld.quest.checkCasper = true; //для обработки в АИ warrior
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
	//третий
	sld = characterFromId("Casper_8");
	sld.quest.checkCasper = true; //для обработки в АИ warrior
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
	AddQuestRecord("ISS_MainLine", "39");
	AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("ся","ась"));
}



void LSCC_PrepareUnderwater_Check(string qName)// ремонт водолазного костюма - проверка
{
	log_Testinfo("Костюм починен!");
	pchar.questTemp.LSCC = "underwater_check";
}
void LSCC_PrepareUnderwater(string qName)// готовы к первому погружению
{
	log_Testinfo("К погружению готовы!");
	pchar.questTemp.LSCC = "underwater_prepare";
}

void LSCC_takeUnderwater(string qName)// выдача скафандра
{
	GiveItem2Character(pchar, "underwater"); 
	PlaySound("interface\notebook.wav");
	Log_Info("Вы получили водолазный скафандр");
}

void LSCC_ReadyUnderwater(string qName)// готовы к погружениям
{
	log_Testinfo("К погружению готовы!");
	pchar.questTemp.LSCC.UW_ready = "true";
}

void LSCC_underwaterDeathTimer(string qName)
{
	GameOver("sea");
}

void LSCC_FindUnderwaterDolly(string qName) // нашли статую
{
	pchar.questTemp.LSCC.FindDolly = "true";
	pchar.questTemp.Saga.BaronReturn = "second_teleport";
	ref rLoc = &Locations[FindLocation("underwaterr")];

	AddCharacterExpToSkill(pchar, "Fortune", 100);//везение
}



//начать малый шторм
void LSCC_SmallStormIsBegin()
{
	for (int i=0;i<MAX_LOCATIONS;i++)
	{				
		if (Locations[i].id == "LostShipsCityy_town")
		{
			Locations[i].alwaysStorm = true; 
			Locations[i].storm = true;
			Locations[i].tornado = true; 
			Locations[i].QuestlockWeather = true;
			Locations[i].MaxWaveHeigh = true;
		}
	}

	for(i=0; i<MAX_LOCATIONS; i++)
	{				
		if (CheckAttribute(&locations[i], "fastreload") && locations[i].fastreload == "LostShipsCityy")
		{
			Locations[i].alwaysStorm = true; 
			Locations[i].storm = true;
			Locations[i].tornado = true; 
			Locations[i].QuestlockWeather = true;
			Locations[i].MaxWaveHeigh = true;
		}
	} 
	//пустим слух о шторме
	AddSimpleRumourCityTip("Погода портиться. Видимо опять будет шторм.", "LostShipsCityy", 5, 1, "LSCC", "");
	AddSimpleRumourCityTip("М-да, кажется опять шторм надвигается.", "LostShipsCityy", 5, 1, "LSCC", "");
	AddSimpleRumourCityTip("Ох, как же надоели эти штормы! Вот, кажется снова начинается...", "LostShipsCityy", 5, 1, "LSCC", "");
	AddSimpleRumourCityTip("Погода испортилась. Видимо, будет шторм.", "LostShipsCityy", 5, 1, "LSCC", "");
	AddSimpleRumourCityTip("Начинается шторм. Опять несколько дней будем сидеть по домам.", "LostShipsCityy", 5, 1, "LSCC", "");
	//расставим нпс на свои места, штормовые. ограничиваем хождение по городу
	LAi_group_Delete("EnemyFight");
	for(i=0; i<MAX_CHARACTERS; i++)
	{	
		makeref(sld, characters[i]);
		if (CheckAttribute(sld, "city") && sld.city == "LostShipsCityy")
		{	
			if (sld.cityTape == "mayor")
			{
				//LAi_SetImmortal(sld, false);
				DeleteAttribute(sld, "location.going");
				sld.cityTape = "notMove";  //не перемещаться более
				LAi_SetHuberType(sld); //садим за стол
				LAi_group_MoveCharacter(sld, "EnemyFight");	
				ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "sit", "sit1");
			}
			if (sld.cityTape == "ment")
			{
				if (sld.id == "Ment_6")
				{
					LAi_SetImmortal(sld, false);
					DeleteAttribute(sld, "location.going");
					sld.cityTape = "notMove";  //не перемещаться более
					LAi_SetLSCoutTypeNoGroup(sld);
					LAi_group_MoveCharacter(sld, "EnemyFight");
					ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
				}
				else
				{
					sTemp = sld.id;
					sTemp = "goto" + strcut(sTemp, 5, 5);
					LAi_SetImmortal(sld, false);
					DeleteAttribute(sld, "location.going");
					sld.cityTape = "notMove";  //не перемещаться более
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, "EnemyFight");
					ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "goto", sTemp);
				}				
			}
			if (sld.cityTape == "citizenHome")
			{
				DeleteAttribute(sld, "location.going");
				sld.cityTape = "notMove";  //не перемещаться более
				LAi_SetOwnerTypeNoGroup(sld);
				ChangeCharacterAddressGroup(sld, sld.location.baseLocation, "barmen", "stay");
			}
			if (sld.cityTape == "prisonerHead" || sld.cityTape == "prisoner")
			{
				LAi_SetImmortal(sld, false);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
		}
	}
}

void LSCC_afterArestMachanic(string qName)
{
	sld = &characters[sti(pchar.questTemp.LSCC.lastManId)];
	LAi_SetStayTypeNoGroup(sld);			
	ChangeCharacterAddressGroup(sld, "SanGabrielMechanicc", "barmen",  "stay");
	sld = characterFromId("LSCC_Mechanic");
	ChangeCharacterAddress(sld, "none", "");
	DeleteAttribute(pchar, "questTemp.LSCC.lastManId");
}

void LSCC_fightEnterResidence(string qName)
{
	chrDisableReloadToLocation = true;
	LAi_LocationFightDisable(loadedLocation, true);
	//отравляем наверх
	string sLocator;
	iTemp = GetCharacterIndex("Ment_1")
	if (iTemp != -1)
	{
		sld = &characters[iTemp];
		LAi_CharacterReincarnation(sld, false, false);
		LAi_SetLSCoutTypeNoGroup(sld);
		ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
		LAi_warrior_DialogEnable(sld, false);
	}
	//------------------------
	iTemp = GetCharacterIndex("Ment_2")
	if (iTemp != -1)
	{
		sld = &characters[iTemp];
		LAi_CharacterReincarnation(sld, false, false);
		LAi_SetLSCoutTypeNoGroup(sld);
		ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
		LAi_warrior_DialogEnable(sld, false);
	}
	//------------------------
	iTemp = GetCharacterIndex("Ment_3")
	if (iTemp != -1)
	{
		sld = &characters[iTemp];
		LAi_CharacterReincarnation(sld, false, false);
		LAi_SetLSCoutTypeNoGroup(sld);
		ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", sld.location.baseLocator);
		LAi_warrior_DialogEnable(sld, false);
	}
	//в резиденции
	iTemp = GetCharacterIndex("Ment_4")
	if (iTemp != -1)
	{
		sld = &characters[iTemp];
		LAi_SetWarriorTypeNoGroup(sld); 
		LAi_warrior_DialogEnable(sld, false);
		LAi_warrior_SetStay(sld, true);
		ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "goto", "goto2");
	}
	iTemp = GetCharacterIndex("Ment_5")
	if (iTemp != -1)
	{
		sld = &characters[iTemp];
		LAi_SetWarriorTypeNoGroup(sld); 
		LAi_warrior_DialogEnable(sld, false);
		LAi_warrior_SetStay(sld, true);
		ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "goto", "goto3");
	}	
	sld = characterFromId("LSCCMayor");
	sld.dialog.currentnode = "fightTalking";
	LAi_SetImmortal(sld, false);
	LAi_SetActorTypeNoGroup(sld); 
	ChangeCharacterAddressGroup(sld, "SanAugustineResidencee", "goto", "goto10");
	LAi_ActorDialog(sld, pchar, "", -1.0, 0);
}

void LSCC_figtInResidence()
{
	sld = characterFromId("Ment_6");
	GetCharacterPos(pchar, &locx, &locy, &locz);
	LAi_SetWarriorTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
    pchar.quest.LSCC_figtInResidence_1.win_condition.l1 = "NPC_Death";
    pchar.quest.LSCC_figtInResidence_1.win_condition.l1.character = "LSCCMayor";
    pchar.quest.LSCC_figtInResidence_1.win_condition.l2 = "NPC_Death";
    pchar.quest.LSCC_figtInResidence_1.win_condition.l2.character = "Ment_4";
    pchar.quest.LSCC_figtInResidence_1.win_condition.l3 = "NPC_Death";
    pchar.quest.LSCC_figtInResidence_1.win_condition.l3.character = "Ment_5";
    pchar.quest.LSCC_figtInResidence_1.function= "LSCC_figtInResidence_1";
	LAi_SetFightMode(pchar, true);
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
}

void LSCC_figtInResidence_1(string qName)
{
	sld = characterFromId("Ment_6");
	if (!CharacterIsDead(sld))
	{
		sld.dialog.currentnode = "MentOffIsLife";
		LAi_SetActorTypeNoGroup(sld); 
		LAi_ActorDialog(sld, pchar, "", -1.0, 0);
	}
	else
	{
		AddQuestRecord("ISS_MainLine", "65");
		chrDisableReloadToLocation = false;
	}
	pchar.quest.LSCC_enterToPrison.win_condition.l1 = "location";
	pchar.quest.LSCC_enterToPrison.win_condition.l1.location = "TartarusPrisonn";
	pchar.quest.LSCC_enterToPrison.function = "LSCC_enterToPrison";
}

void LSCC_enterToPrison(string qName)
{
	chrDisableReloadToLocation = true;
	sld = characterFromId("LSCC_Mechanic");
	sld.dialog.currentnode = "inPrison";
	LAi_SetImmortal(sld, true);
	LAi_SetGroundSitType(sld);
	ChangeCharacterAddressGroup(sld, "TartarusPrisonn", "quest", "prison3");
}


//начать большой шторм
void LSCC_BigStormIsBegin()
{
	bDisableFastReload = true; 
	for(i=0; i<MAX_LOCATIONS; i++)
	{				
		if (locations[i].id == "LostShipsCityy_town")
		{	//закрываем релоады
			locations[i].notCrateFoam = true; //не рисовать пену
			DeleteAttribute(&locations[i], "reload.l2.disable"); //открываем выход с ГПК
			locations[i].reload.l231.disable = true;
			for(int n=3; n<=73; n++)
			{	
				sTemp = "l" + n;
				locations[i].reload.(sTemp).disable = true; 
			}
			DeleteAttribute(&locations[i], "reload.l2.disable"); //откроем выход из ГПК

			locations[i].locators_radius.reload.reload2_back = 16.0;
			pchar.location.from_sea = "LostShipsCityy_town";
			//второй патч ГПК
			locations[i].models.day.charactersPatch = "LostShipsCityy_patch_end";
			locations[i].models.night.charactersPatch = "LostShipsCityy_patch_end";	
			//погода
			DeleteAttribute(&locations[i], "alwaysStorm");	
			DeleteAttribute(&locations[i], "QuestlockWeather");
			DeleteAttribute(&locations[i], "MaxWaveHeigh");		
			locations[i].alwaysStorm_2 = true; //живем в штормах
			locations[i].alwaysStorm_2.WaveHeigh = true; //поднять уровень воды до 2.5 для низкого волнения
			locations[i].storm = true;
			locations[i].tornado = true;
		}
	}
	//снять шторм с острова ГПК
	i = FindIsland("LostShipsCityy");
	Islands[i].reload.l2.emerge = "reload2_back";
	Islands[i].reload_enable = false;

	//прерывание на удаление острова ГПК и снятие шторма с ареала
	pchar.quest.LSCC_closeLine.win_condition.l1 = "location";
	pchar.quest.LSCC_closeLine.win_condition.l1.location = "LostShipsCityy";
	pchar.quest.LSCC_closeLine.function = "LSCC_closeLine";
	SetTimerFunction("LSCC_takeStormIsland", 0, 0, 10);
}


void LSCC_closeLine(string qName)
{
	AddQuestRecord("ISS_MainLine", "69");
	AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("ISS_MainLine");
	CloseQuestHeader("TakeVineToPrisoner");
	CloseQuestHeader("LSCC_findDekster");
	CloseQuestHeader("ISS_ElisHusband");
	CloseQuestHeader("ISS_takeStoreMoney");
	CloseQuestHeader("ISS_takeCandles");
	bQuestDisableMapEnter = false;
	bDisableFastReload = false; 
	TakeItemFromCharacter(pchar, "keyPanama");

                    /// возвращаем дату
	/*					
	Environment.date.year = sti(qDateY);
	Environment.date.month = sti(qDateM);
	Environment.date.day = sti(qDateD);
	worldMap.date.year = sti(qDateY);
	worldMap.date.month = sti(qDateM);
	worldMap.date.day = sti(qDateD);
	*/
	//проверим наличие займа у банкира ГПК
	sld = characterFromId("LSCC_Usurer");
	if (CheckAttribute(sld, "quest.loan.qtyMoney") && sti(sld.quest.loan.qtyMoney) > 0)
	{			
                    SetTimerFunction("LSCC_climeUsurer", 0, 3 + rand(3), 0);
	pchar.questTemp.LSCC_climeUsurer.qtyMoney = sti(sld.quest.loan.qtyMoney) * 5; //сколько денег к возврату
	}
	//убираем жителей ГПК из игры
	for(i=0; i<MAX_LOCATIONS; i++)
	{	
	sld = &characters[i];
	if (CheckAttribute(sld, "city") && sld.city == "LostShipsCityy")
	sld.lifeDay = 0;	
	}
}

void LSCC_takeStormIsland(string qName)
{	
	for (int i=0;i<MAX_LOCATIONS;i++)
	{				
		if (Locations[i].id == "LostShipsCityy_town")
		{
			DeleteAttribute(&locations[i], "alwaysStorm");
			DeleteAttribute(&locations[i], "storm");
			DeleteAttribute(&locations[i], "tornado");	
			DeleteAttribute(&locations[i], "QuestlockWeather");
			DeleteAttribute(&locations[i], "MaxWaveHeigh");
		}
	}

	for(i=0; i<MAX_LOCATIONS; i++)
	{				
		if (CheckAttribute(&locations[i], "fastreload") && locations[i].fastreload == "LostShipsCityy")
		{
			DeleteAttribute(&locations[i], "alwaysStorm");
			DeleteAttribute(&locations[i], "storm");
			DeleteAttribute(&locations[i], "tornado");	
			DeleteAttribute(&locations[i], "QuestlockWeather");
			DeleteAttribute(&locations[i], "MaxWaveHeigh");
		}
	}
}

//------------ посетить жилые помещения магазина ----------->>>>>>
void LCS_SetPedroHurtado(string qName)
{
	sld = characterFromId("PedroHurtado");
	sld.cityTape = "quest"; //тип нпс
	DeleteAttribute(sld, "location.going");
	LAi_SetLoginTime(sld, 10.0, 19.00);
	LAi_SetStayTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "goto", "goto04_6");
}

void LSCC_PedroRunOpenDoor()
{
	sld = characterFromId("PedroHurtado");
	sld.BreakTmplAndFight = true;
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "reload", "reload48", "LSCC_PedroOpenedDoor", -1.0);
}

void LSCC_Click(string qName)
{	
	PlaySound("interface\key.wav");
	LocatorReloadEnterDisable("LostShipsCityy_town", "reload48", false);
	chrDisableReloadToLocation = true;
}

void LSCC_PedroGoWaiting()
{
	sld = characterFromId("PedroHurtado");
	LAi_RemoveLoginTime(sld);
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorTurnToLocator(sld, "goto", "goto04_6");
	chrDisableReloadToLocation = false;
	pchar.quest.LSCC_EnterStoreBig.win_condition.l1 = "locator";
	pchar.quest.LSCC_EnterStoreBig.win_condition.l1.location = "EsmeraldaStoreBigg";
	pchar.quest.LSCC_EnterStoreBig.win_condition.l1.locator_group = "reload";
	pchar.quest.LSCC_EnterStoreBig.win_condition.l1.locator = "reload2";
	pchar.quest.LSCC_EnterStoreBig.function = "LSCC_EnterStoreBig";
}

void LSCC_EnterStoreBig(string qName)
{	
	//охрана
	chrDisableReloadToLocation = true;
	LAi_group_Delete("EnemyFight");
	iTemp = 8+MOD_SKILL_ENEMY_RATE*2;
    for (i=1; i<=3; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("LSCStBandit"+i, "mercen_"+(i+20), "man", "man", iTemp, PIRATE, 0, true, "quest"));
        FantomMakeCoolFighter(sld, iTemp, 80, 80, "topor_04", "pistol6", "bullet", 50);
        LAi_SetWarriorType(sld);			
        LAi_group_MoveCharacter(sld, "EnemyFight");				
		ChangeCharacterAddressGroup(sld, pchar.location, "quest",  "quest"+i);
    }
    LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
    LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
	pchar.quest.LCS_HeroOutFromStory.win_condition.l1 = "ExitFromLocation";
	pchar.quest.LCS_HeroOutFromStory.win_condition.l1.location = pchar.location;
	pchar.quest.LCS_HeroOutFromStory.function = "LCS_HeroOutFromStory";
}

void LCS_HeroOutFromStory(string qName)
{
	LocatorReloadEnterDisable("LostShipsCityy_town", "reload48", false);//пусть открытой дверь останется
	sld = characterFromId("PedroHurtado");	
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorDialog(sld, pchar, "", 1.0, 0);
	AddSimpleRumourCityTip("Говорят, что кто-то ограбил хозяина магазина Эрика Йоста...", "LostShipsCityy", 10, 1, "LSCC", "");
}
//<<<<<<-------- посетить жилые помещения магазина ----------------

//------------ должок ростовщика ГПК ----------->>>>>>
void LSCC_climeUsurer(string qName)
{
	pchar.quest.LSCC_climeUsurer_2.win_condition.l1 = "Location_Type";
	pchar.quest.LSCC_climeUsurer_2.win_condition.l1.location_type = "shop";
	pchar.quest.LSCC_climeUsurer_2.function = "LSCC_climeUsurer_2";	
}

void LSCC_climeUsurer_2(string qName)
{
	chrDisableReloadToLocation = true;
	sld = characterFromId(loadedLocation.fastreload + "_trader");
	LAi_CharacterDisableDialog(sld);
	//запишем данные для возврата в локацию
	pchar.questTemp.LSCC_climeUsurer.idx = sld.id;
	pchar.questTemp.LSCC_climeUsurer.location = pchar.location;
	pchar.questTemp.LSCC_climeUsurer.group = pchar.location.group;
	pchar.questTemp.LSCC_climeUsurer.locator = pchar.location.locator;
	DoQuestFunctionDelay("LSCC_climeUsurer_3", 3.5);
}

void LSCC_climeUsurer_3(string qName)
{
 	//перемещаем ГГ
	DoQuestReloadToLocation("Temple_Skulls_1", "goto", "goto1", "");	
	DoQuestFunctionDelay("LSCC_climeUsurer_4", 10.0);
	//вернем хозяину магазина возможность диалога
	sld = characterFromId(pchar.questTemp.LSCC_climeUsurer.idx);
	LAi_CharacterEnableDialog(sld);
}

void LSCC_climeUsurer_4(string qName)
{
	//ставим бога мертвых	
	LAi_LockFightMode(Pchar, false);
	LAi_LocationFightDisable(loadedLocation, true);
	sld = GetCharacter(NPC_GenerateCharacter("DeadmansGod", "mictlantecuhtli", "skeleton", "man", 100, PIRATE, 0, true, "quest"));
    	FantomMakeCoolFighter(sld, 50, 100, 100, "newblade29", "", "", 3000); 
	sld.name = "Миктлантекутли";
	sld.lastname = "";
	sld.dialog.filename   = "Gothic_Quest\Mictlantecuhtli.c";
	sld.dialog.currentnode   = "ClimeUsurer";
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "Templee_Skulls_1", "goto", "goto2");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 5.0, 0);	
}

void ClimeUsurer_haveMoney()
{
	DoQuestFunctionDelay("ClimeUsurer_haveMoney_1", 1.0);	
}

void ClimeUsurer_haveMoney_1(string qName)
{
	chrDisableReloadToLocation = false;
	LAi_LocationFightDisable(&locations[FindLocation("Templee_Skulls_1")], false);
	DoQuestReloadToLocation(pchar.questTemp.LSCC_climeUsurer.location, pchar.questTemp.LSCC_climeUsurer.group, pchar.questTemp.LSCC_climeUsurer.locator, "");	
	DeleteAttribute(pchar, "questTemp.LSCC_climeUsurer");
}

void ClimeUsurer_noMoney()
{
	LAi_LocationFightDisable(loadedLocation, false);
	sld = characterFromId("DeadmansGod");
	ChangeCharacterAddress(sld, "none", "");
	//если Аззи в дружбанах, то выручает ГГ
	if (pchar.questTemp.Azzy == "over")
	{
		DoQuestFunctionDelay("LSCC_climeUsurer_Azzy", 30.0);
	}
}

void LSCC_climeUsurer_Azzy(string qName)
{
	LAi_LockFightMode(Pchar, false);
	LAi_LocationFightDisable(loadedLocation, true);
	sld = GetCharacter(NPC_GenerateCharacter("Azzy", "Azzy", "man", "man", 22, PIRATE, 0, false, "quest"));
	sld.name = "демон";
	sld.lastname = "Аззи";
	sld.Dialog.Filename = "Gothic_Quest\Azzy_dialog.c";
	sld.dialog.currentnode = "ClimeUsurer";
	GiveItem2Character(sld, "blade_28");
	sld.equip.blade = "blade_28";
	sld.rank 	= 100;
	sld.reputation = "0";
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100);
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
	LAi_SetLoginTime(sld, 0.0, 24.0);
	LAi_SetHP(sld, 10000.0, 10000.0);
	sld.greeting = "Gr_Azzy";
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto2");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 5.0, 0);
}
//<<<<<<-------- должок ростовщика ГПК ----------------    

//------------ освободить мужа Элис Тейлор ----------->>>>>>
void LSCC_ElisHusbandSet(string qName)
{
	sld = characterFromId("MaximTailor");
	sld.dialog.currentnode = "First time";
	sld.watchBoxes = true;
	GiveItem2Character(sld, "blade_15");
	GiveItem2Character(sld, "pistol2");
	EquipCharacterbyItem(sld, "blade_15");
 	EquipCharacterbyItem(sld, "pistol2");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	ChangeCharacterAddressGroup(sld, "CeresSmithyy", "goto", "goto1");
}
//<<<<<<-------- освободить мужа Элис Тейлор ----------------

//------------ квест скелета Лейтона Декстера ----------->>>>>>
void LSCC_admiralFoundOwnKey(string qName)
{
	sld = ItemsFromID("keyPanama");
	sld.shown = false;
	AddQuestRecord("LSCC_findDekster", "11");
	AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("","а"));
	CloseQuestHeader("LSCC_findDekster");
	pchar.questTemp.LSCC.lostDecster = "over";
}
//<<<<<<-------- квест скелета Лейтона Декстера ----------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Линейка ГПК           конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Розо" или "Шарлотт-Таун" ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void GothicTorus_StartRoseauCharlotte(string qName)//начало истории 
{
	Log_Info("Квест Розо или Шарлотт-Таун стартанул!!!");
	pchar.questTemp.GothicTorus = "RoseauCharlotte";
}

void RoseauCharlotte_toBrothel(string qName)
{
          pchar.GenQuest.CannotWait = true;//запрет ожидания
          pchar.GenQuest.CantRun = true;//запрет бега
          bDisableFastReload = true;//закрыть переход
          LocatorReloadEnterDisable("Roseau_port", "reload1_back", true);//порт закрыть
          LocatorReloadEnterDisable("Shore26", "boat", true);//бухту закрыть
          LocatorReloadEnterDisable("Shore27", "boat", true);//мыс закрыть
          LAi_SetActorType(pchar);
          LAi_ActorTurnToLocator(pchar, "reload", "reload1");
          DoQuestFunctionDelay("RoseauCharlotte_toBrothel_1", 4.0);
}

void RoseauCharlotte_toBrothel_1(string qName)
{
            LAi_SetPlayerType(pchar);
            sld = characterFromId("Torus");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1", "Roseau_bank", "reload", "reload2", "", 10.0);

           pchar.quest.RoseauCharlotte_toBrothel_01.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_toBrothel_01.win_condition.l1.location = "Roseau_bank";
           pchar.quest.RoseauCharlotte_toBrothel_01.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_toBrothel_01.win_condition.l1.locator = "reload2";
           pchar.quest.RoseauCharlotte_toBrothel_01.function = "RoseauCharlotte_toBrothel_01";
}

void RoseauCharlotte_toBrothel_01(string qName)
{
            sld = characterFromId("Torus");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1", "Roseau_town", "goto", "goto29", "", 10.0);

           pchar.quest.RoseauCharlotte_toBrothel_02.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_toBrothel_02.win_condition.l1.location = "Roseau_town";
           pchar.quest.RoseauCharlotte_toBrothel_02.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_toBrothel_02.win_condition.l1.locator = "reload8_back";
           pchar.quest.RoseauCharlotte_toBrothel_02.function = "RoseauCharlotte_toBrothel_02";
}

void RoseauCharlotte_toBrothel_02(string qName)
{
            sld = characterFromId("Torus");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload9_back", "Roseau_Brothel", "reload", "reload1_back", "", 14.0);

           pchar.quest.RoseauCharlotte_toBrothel_03.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_toBrothel_03.win_condition.l1.location = "Roseau_Brothel";
           pchar.quest.RoseauCharlotte_toBrothel_03.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_toBrothel_03.win_condition.l1.locator = "reload1_back";
           pchar.quest.RoseauCharlotte_toBrothel_03.function = "RoseauCharlotte_toBrothel_03";
}

void RoseauCharlotte_toBrothel_03(string qName)
{
            RemoveCharacterCompanion(pchar, characterFromID("Torus"));
            sld = characterFromId("Torus");
            sld.Dialog.Filename = "Mayor\Torus.c";
            sld.dialog.currentnode = "RoseauCharlotte_10";
            LAi_SetImmortal(sld, true);//защита от дурака
            LAi_SetActorType(sld);
            LAi_ActorDialog(sld, pchar, "", -1, 0);
            ChangeCharacterAddressGroup(sld, "Roseau_Brothel", "goto", "goto3");

             sld2 = CharacterFromID("Roseau_Hostess");
             LAi_SetActorType(sld2);
             LAi_ActorGoToLocator(sld2, "goto", "goto8", "", -1.0);
}

void InRoseauSecBrRoom(string qName)//вошли в бордель
{
	sld = CharacterFromID("Torus");
	LAi_ActorTurnToCharacter(sld2, characterFromID("Roseau_Hostess"));
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "goto", "goto3", "", -1.0);

	LAi_SetActorType(pchar);
	LAi_ActorGoToLocator(pchar, "goto", "goto9", "TorusTalkWithRoseauHostess", -1.0);

	sld2 = CharacterFromID("Roseau_Hostess");
	LAi_ActorTurnToCharacter(sld2, characterFromID("Torus"));
}

void RoseauCharlotte_SecBrBrothel(string qName)
{
	LocatorReloadEnterDisable("Roseau_SecBrRoom", "reload2", false);//комнату в борделе открыть
	sld2 = characterFromId("Roseau_Hostess");
                   LAi_SetOwnerType(sld2);
	sld2.Dialog.Filename = "Common_Brothel.c";
                   sld2.dialog.currentnode = "First time";
	sld = CharacterFromID("Torus");
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                    sld.Dialog.Filename = "Mayor\Torus.c";
	sld.dialog.currentnode = "RoseauCharlotte_Brothel_6";
}

void RoseauCharlotte_BackDoor(string qName)
{
            sld = characterFromId("Torus");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload2", "Roseau_brothel_BackDoor", "reload", "reload1_back", "", 10.0);

           pchar.quest.RoseauCharlotte_BackDoor_01.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_BackDoor_01.win_condition.l1.location = "Roseau_SecBrRoom";
           pchar.quest.RoseauCharlotte_BackDoor_01.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_BackDoor_01.win_condition.l1.locator = "reload2";
           pchar.quest.RoseauCharlotte_BackDoor_01.function = "RoseauCharlotte_BackDoor_01";
}

void RoseauCharlotte_BackDoor_01(string qName)//вошли
{
	sld = CharacterFromID("Torus");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "quest", "quest_1", "", -1.0);
                   DoQuestFunctionDelay("RoseauCharlotte_BackDoor_02", 15.0);
}

void RoseauCharlotte_BackDoor_02(string qName)//вошли
{
	sld = CharacterFromID("Torus");
	LAi_SetActorType(sld);
	LAi_ActorTurnToCharacter(sld, pchar);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   sld.Dialog.Filename = "Mayor\Torus.c";
	sld.dialog.currentnode = "RoseauCharlotte_BackDoor";
}

void RoseauCharlotte_BackDoor_03(string qName)
{
          AddQuestRecord("RoseauCharlotte", "1");
          sld = CharacterFromID("Torus");
          LAi_SetActorType(sld);
          LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 30.0);

         // кладем Книгу агента
         sld = ItemsFromID("BookAgent");
         sld.shown = true;
         sld.startLocation = "Roseau_SecBrRoom";
         sld.startLocator = "item2" 

           pchar.quest.RoseauCharlotte_BackDoor_04.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_BackDoor_04.win_condition.l1.location = "Roseau_brothel_BackDoor";
           pchar.quest.RoseauCharlotte_BackDoor_04.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_BackDoor_04.win_condition.l1.locator = "reload1_back";
           pchar.quest.RoseauCharlotte_BackDoor_04.function = "RoseauCharlotte_BackDoor_04";
}

void Gothic_ReadBookAgent() // взяли книгу
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadBookAgent_1", 3.5);
}

void Gothic_ReadBookAgent_1() // взяли книгу
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadBookAgent_2", 3.5);
}
void Gothic_ReadBookAgent_2() // прочли книгу
{
 	PlaySound("Interface\CHAPTER.wav");
	AddCharacterExpToSkill(pchar, "LEADERSHIP", 500);
	AddCharacterExpToSkill(pchar, "Fortune", 500);//везение
	AddCharacterExpToSkill(pchar, "Sneak", 500);//скрытность
	AddQuestRecordInfo("BookAgent", "1");
}

void RoseauCharlotte_BackDoor_04(string qName)
{ 
           pchar.quest.RoseauCharlotte_BackDoor_05.win_condition.l1 = "locator";
           pchar.quest.RoseauCharlotte_BackDoor_05.win_condition.l1.location = "Roseau_SecBrRoom";
           pchar.quest.RoseauCharlotte_BackDoor_05.win_condition.l1.locator_group = "reload";
           pchar.quest.RoseauCharlotte_BackDoor_05.win_condition.l1.locator = "reload2";
           pchar.quest.RoseauCharlotte_BackDoor_05.function = "RoseauCharlotte_BackDoor_05";
}

void RoseauCharlotte_BackDoor_05(string qName)
{ 
	sld2 = characterFromId("Roseau_Hostess");
	LAi_SetActorType(sld2);
	LAi_ActorGoToLocator(sld2, "reload", "reload2", "", -1.0);
                   DoQuestFunctionDelay("RoseauCharlotte_BackDoor_06", 3.0);
}
void RoseauCharlotte_BackDoor_06(string qName)
{ 
                   //DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания
                   DeleteAttribute(pchar, "GenQuest.CantRun");//запрет бега
 	LocatorReloadEnterDisable("Roseau_SecBrRoom", "reload2", true);//комнату в борделе закрыть
                   PlaySound("interface\key.wav");//щелк!
	sld2 = characterFromId("Roseau_Hostess");
                   LAi_SetOwnerType(sld2);
	sld2.Dialog.Filename = "Common_Brothel.c";
                   sld2.dialog.currentnode = "First time";
                   pchar.questTemp.GothicTorus = "KillworkRoseauCharlotte"; 

                   sld = CharacterFromID("Torus");
	sld.location	= "Roseau_Roomtownhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	sld.greeting = "Gr_Torus";
	sld.Dialog.Filename = "Mayor\Torus.c";
                   sld.dialog.currentnode = "First time"; 
}

void KillworkRoseaugirl(string qName)
{ 
	sld = characterFromId("Roseaugirl_1");
                   pchar.questTemp.GothicTorus = "Killwork"; 
}

void KillworkRoseaugirl_1(string qName)
{ 
                   AddQuestRecord("RoseauCharlotte", "2"); 
}

void Killwork_huber(string qName)
{ 
                   AddQuestRecord("RoseauCharlotte", "3"); 
}

void Killwork_huber_hour(string qName)
{
            LocatorReloadEnterDisable("Roseau_town", "reload1_back", true);//город закрыть
            LocatorReloadEnterDisable("Roseau_town", "gate_back", true);//город закрыть
            sld = characterFromId("Roseau_Mayor");
            ChangeCharacterAddressGroup(sld, "Roseau_town", "reload", "reload3_back");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "gate_back", "Roseau_exittown", "goto", "goto17", "Killwork_huber_hour_00", 25.0);
            sld2 = GetCharacter(NPC_GenerateCharacter("ScooFuckGirl", "squaw_3", "woman", "woman_B", 1, FRANCE, -1, true, "quest"));
           SetFantomParamFromRank(sld2, 1, true);
            LAi_SetActorType(sld2);
            LAi_SetImmortal(sld2, true);
           ChangeCharacterAddressGroup(sld2, "Roseau_exittown", "goto", "goto3");

           pchar.quest.Killwork_huber_hour_01.win_condition.l1 = "locator";
           pchar.quest.Killwork_huber_hour_01.win_condition.l1.location = "Roseau_exittown";
           pchar.quest.Killwork_huber_hour_01.win_condition.l1.locator_group = "reload";
           pchar.quest.Killwork_huber_hour_01.win_condition.l1.locator = "reload3";
           pchar.quest.Killwork_huber_hour_01.function = "Killwork_huber_hour_01";

}

void Killwork_huber_hour_01(string qName)
{ 
            pchar.GenQuest.CantRun = true;//запрет бега
            sld = characterFromId("Roseau_Mayor");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Shore26", "Smugglers", "Smuggler02", "", 35.0);
            sld2 = characterFromId("ScooFuckGirl");
            LAi_SetActorType(sld2);
            LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "Shore26", "Smugglers", "Smugglerload", "", 55.0);

           pchar.quest.Killwork_huber_hour_02.win_condition.l1 = "locator";
           pchar.quest.Killwork_huber_hour_02.win_condition.l1.location = "Roseau_exittown";
           pchar.quest.Killwork_huber_hour_02.win_condition.l1.locator_group = "reload";
           pchar.quest.Killwork_huber_hour_02.win_condition.l1.locator = "reload1_back";
           pchar.quest.Killwork_huber_hour_02.function = "Killwork_huber_hour_02";

}

void Killwork_huber_hour_02(string qName)
{ 
           LAi_SetActorType(pchar);
           LAi_ActorGoToLocator(pchar, "goto", "goto6", "", -1);
           DoQuestFunctionDelay("Killwork_huber_hour_03", 25.0);
}

void Killwork_huber_hour_03(string qName)
{ 
                    sld = characterFromId("Roseau_Mayor");
                    LAi_SetBarmanType(sld);
	 LAi_RemoveLoginTime(sld);
                    LAi_ActorTurnToLocator(sld, "Smugglers", "Smugglerload");
                    LAi_ActorTurnToLocator(pchar, "Smugglers", "Smugglerload");
                    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte", 4.0);
}

void Killwork_huber_hour_04(string qName)
{
                    sld2 = characterFromId("ScooFuckGirl");
                    SetCharacterTask_Dead(sld2); 
                    DoQuestFunctionDelay("Killwork_huber_hour_Sex", 4.0);
}

void Killwork_huber_hour_Sex(string qName)
{
                    sld = characterFromId("Roseau_Mayor");
                    LAi_SetGroundSitTypeNoGroup(sld); 
                    LAi_ActorAnimation(sld, "Ground_StandUp", "", 3.5);
                    DoQuestFunctionDelay("Killwork_huber_hour_05", 4.0);
}

void Killwork_huber_hour_05(string qName)
{
                   pchar.questTemp.GothicTorus = "NoKillwork"; 
                   sld = CharacterFromID("Roseau_tavernkeeper");
                   sld.dialog.currentnode = "NoKillwork";
                    PlaySound("Sex\sex2.wav");
                   DeleteAttribute(pchar, "GenQuest.CantRun");//запрет бега
                    LAi_SetActorType(pchar);
	 pchar.questTemp.GothicTorus_RoseauCharlotte.Killwork = "true";
	 DoQuestCheckDelay("TalkSelf_Quest", 3.0);

                 pchar.quest.Killwork_huber_hour_05.win_condition.l1 = "locator";
                 pchar.quest.Killwork_huber_hour_05.win_condition.l1.location = "Roseau_tavern_upstairs";
                 pchar.quest.Killwork_huber_hour_05.win_condition.l1.locator_group = "reload";
                 pchar.quest.Killwork_huber_hour_05.win_condition.l1.locator = "reload1_back";
                 pchar.quest.Killwork_huber_hour_05.function = "GothicTorus_HEALLASTSHRINE";
}

void GothicTorus_HEALLASTSHRINE(string qName)//вошли в комнату в таверне
{
	LAi_SetActorType(pchar);
	LAi_ActorGoToLocator(pchar, "reload", "reload_window", "", -1.0);
                   DoQuestFunctionDelay("GothicTorus_HEALLASTSHRINE_01", 5.0);
}

void GothicTorus_HEALLASTSHRINE_01(string qName)//молитва
{
          PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_HEALLASTSHRINE.wav");
          LAi_ActorTurnToLocator(pchar, "goto", "goto1");
          DoQuestFunctionDelay("GothicTorus_fake", 8.0);
}

void GothicTorus_fake(string qName)
{
                   DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания 
	LocatorReloadEnterDisable("Roseau_exittown", "reload1_back", false);
	LocatorReloadEnterDisable("Roseau_tavern", "reload2", true);//закроем комнату в таверне
	sld2 = characterFromId("ScooFuckGirl");
                   LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "none", "", "", "", 10.0);
                   sld = CharacterFromID("Roseau_Mayor");
	sld.location	= "Roseau_townhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	sld.greeting = "hovernor";
	sld.Dialog.Filename = "Common_Mayor.c";
                   sld.dialog.currentnode = "First time";
                    LAi_SetActorType(pchar);
	 DoQuestCheckDelay("GothicTorus_fake_1", 3.0);
}

void NoKillwork_Mayor(string qName)
{
          pchar.GenQuest.CannotWait = true;//запрет ожидания
          LAi_SetActorType(pchar);
          LAi_ActorTurnToLocator(pchar, "reload", "reload1");
          DoQuestFunctionDelay("NoKillwork_Mayor_1", 4.0);
}

void NoKillwork_Mayor_1(string qName)
{
            sld = characterFromId("Torus");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 10.0);
            DoQuestFunctionDelay("NoKillwork_Mayor_2", 15.0);
}

void NoKillwork_Mayor_2(string qName)
{
                   LAi_SetPlayerType(pchar);
	SetLaunchFrameFormParam("Прошел час"+ NewStr() +"", "", 0, 5);
	LaunchFrameForm();
	WaitDate("", 0, 0, 0, 1, 10); //крутим время
	RecalculateJumpTable();
	DoQuestCheckDelay("NoKillwork_Mayor_3", 1.0);
}

void NoKillwork_Mayor_4(string qName)
{
            LAi_SetPlayerType(pchar);
            sld = CharacterFromID("Torus");
            LAi_SetActorType(sld);
           LAi_ActorGoToLocator(sld, "goto", "goto4", "", -1);
            DoQuestFunctionDelay("NoKillwork_Mayor_5", 5.0);
}

void NoKillwork_Mayor_5(string qName)
{
                   sld = CharacterFromID("Torus");
                  ChangeCharacterAddressGroup(sld, pchar.location, "sit", "sit1");
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	sld.greeting = "Gr_Torus";
	//sld.Dialog.Filename = "Mayor\Torus.c";
                   sld.dialog.currentnode = "NoKillwork_9";

}

void NoKillwork_JACK(string qName)
{
                 LocatorReloadEnterDisable("Roseau_TownCave", "reload2", false);
                 pchar.questTemp.GothicTorus = "JACKSettlement"; 
}

    //--------------------------- Смертельный заход ------------------------------

void JACK_Settlement_0(string qName)
{
                   AddQuestRecord("RoseauCharlotte", "5");
                   sld = characterFromId("Roseau_Mayor");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 4.0); 
	pchar.quest.JACK_Settlement.win_condition.l1 = "Hour";
	pchar.quest.JACK_Settlement.win_condition.l1.start.hour = 0;
	pchar.quest.JACK_Settlement.win_condition.l1.finish.hour = 5;
	pchar.quest.JACK_Settlement.win_condition.l2 = "locator";
	pchar.quest.JACK_Settlement.win_condition.l2.location = "Roseau_TownCave";
	pchar.quest.JACK_Settlement.win_condition.l2.locator_group = "reload";
	pchar.quest.JACK_Settlement.win_condition.l2.locator = "reload1_back";
	pchar.quest.JACK_Settlement.function = "JACK_Settlement";
}

void JACK_Settlement(string qName)
{
         LocatorReloadEnterDisable("Roseau_TownCave", "reload1_back", true);
         LocatorReloadEnterDisable("Roseau_TownCave", "reload2", true);
         PlaySound("VOICE\Russian\gotica\SFX\AMBIENTCRAWLERSCREAM.wav");
         sld = GetCharacter(NPC_GenerateCharacter("Dieenemy", "Dieenemy", "man", "man", 25, PIRATE, -1, false, "quest"));
          FantomMakeCoolFighter(sld, 25, 50, 50, "blade_19", "pistol6", "bullet", 70);
          ChangeCharacterAddressGroup(sld, "Roseau_TownCave", "monsters", "monster8");
	 LAi_SetImmortal(sld, true);
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
		sld2 = GetCharacter(NPC_GenerateCharacter("Dieenemyskel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		sld2.monster = true; // признак нежити
		sld2.sex = "Skeleton"; 
		sld2.viper = true;
	       LAi_SetImmortal(sld2, true);
		LAi_SetWarriorType(sld2);
		LAi_SetImmortal(sld2, true);//защита от дурака
		ChangeCharacterAddressGroup(sld2, "Roseau_TownCave", "monsters", "monster35");
	                   CreateLocationParticles("large_smoke", "item", "Berglar1"+i, 0.9, 0, 0, "");
		LAi_CharacterDisableDialog(sld2);//запрет диалога
		LAi_SetActorType(sld2);
		LAi_ActorFollow(sld2, sld, "", -1);
	}

           LAi_SetActorType(pchar);
           LAi_ActorGoToLocator(pchar, "officers", "reload1_2", "", -1);
           DoQuestFunctionDelay("JACK_Settlement_1", 10.0);
}

void JACK_Settlement_1(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
            sld = CharacterFromID("Dieenemy");
            LAi_SetActorType(sld);
            LAi_SetWarriorType(sld2);
            LAi_ActorGoToLocator(sld, "item", "Berglar1", "", -1);
            DoQuestFunctionDelay("JACK_Settlement_2", 21.0);
}

void JACK_Settlement_2(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");
            sld = CharacterFromID("Dieenemy");
            LAi_SetActorType(sld);
            LAi_SetWarriorType(sld2);
            LAi_ActorTurnToLocator(sld, "monsters", "monster8");
            DoQuestFunctionDelay("JACK_Settlement_3", 3.0);
}

void JACK_Settlement_3(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE01.wav");
            sld = CharacterFromID("Dieenemy");
            LAi_SetActorType(sld);
            LAi_SetWarriorType(sld2);
            LAi_ActorTurnToLocator(sld, "officers", "reload1_2");
            DoQuestFunctionDelay("DIEENEMY", 2.0);
            DoQuestFunctionDelay("JACK_Settlement_4", 3.0);
}

void JACK_Settlement_4(string qName)
{
                   PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
	CreateLocationParticles("item", "officers", "reload1_2", 1.70, 3, 3, "");
	CreateLocationParticles("item", "officers", "reload1_2", 1.70, 3, 3, "");
	CreateLocationParticles("item", "officers", "reload1_2", 1.70, 3, 3, "");

	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/2; // 1/2 жизни сносим 
	Log_Info("Ищущий поглотил ваши силы - умения в оружии снизились на 30 единиц!");

                  sld = CharacterFromID("Dieenemy");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "monsters", "monster8", "none", "", "", "", 10.0);
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
	sld2 = GetCharacter(NPC_GenerateCharacter("Dieenemyskel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
	sld2.monster = true; // признак нежити
	sld2.sex = "Skeleton"; 
	sld2.viper = true;
	LAi_SetWarriorType(sld2);
                   LAi_group_MoveCharacter(sld2, "EnemyFight");
                   ChangeCharacterAddressGroup(sld2, pchar.location, "",  "");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
                    }
                   LAi_SetPlayerType(pchar);
                   DoQuestFunctionDelay("JACK_Settlement_5", 7.0);
}

void JACK_Settlement_5(string qName)
{
           PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
           DoQuestFunctionDelay("JACK_Settlement_6", 7.0);
}

void JACK_Settlement_6(string qName)
{
           PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
           DoQuestFunctionDelay("JACK_Settlement_5", 7.0);
}

    //--------------------------- Продолжение ------------------------------

void JACK_SettlementOver(string qName)
{
                   AddQuestRecord("RoseauCharlotte", "6");
                   pchar.questTemp.GothicTorus = "ChaniSettlement"; 
}

void JACK_SettlementOver_Mayor(string qName)
{
            sld = characterFromId("Roseau_Mayor");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto9");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocator(sld, "goto", "goto8", "", -1);
            DoQuestFunctionDelay("JACK_SettlementOver_Mayor_1", 4.0);
}

void JACK_SettlementOver_Mayor_1(string qName)
{
                   sld = CharacterFromID("Roseau_Mayor");
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   sld.dialog.currentnode = "JACKSettlement_7";
}

void ChaniSettlement_0(string qName)
{
                   AddQuestRecord("RoseauCharlotte", "7");
                   LocatorReloadEnterDisable("Roseau_town", "basement1_back", true);
	pchar.quest.ChaniSettlement_1.win_condition.l1 = "Hour";
	pchar.quest.ChaniSettlement_1.win_condition.l1.start.hour = 0;
	pchar.quest.ChaniSettlement_1.win_condition.l1.finish.hour = 5;
	pchar.quest.ChaniSettlement_1.win_condition.l2 = "locator";
	pchar.quest.ChaniSettlement_1.win_condition.l2.location = "Roseau_tavern";
	pchar.quest.ChaniSettlement_1.win_condition.l2.locator_group = "reload";
	pchar.quest.ChaniSettlement_1.win_condition.l2.locator = "reload1_back";
	pchar.quest.ChaniSettlement_1.function = "ChaniSettlement_1";
}

void ChaniSettlement_1(string qName)
{
            sld = characterFromId("Chani");
            ChangeCharacterAddressGroup(sld, "Roseau_town", "reload", "gate_back");
            LAi_SetImmortal(sld, true);
            LAi_SetActorType(sld);
            DoQuestFunctionDelay("ChaniSettlement_01", 0.1);
}

void ChaniSettlement_01(string qName)
{
                   sld = CharacterFromID("Chani");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocator(sld, "goto", "goto25", "", -1);
                   DoQuestFunctionDelay("ChaniSettlement_02", 5.1);
}

void ChaniSettlement_02(string qName)
{
                   sld = CharacterFromID("Chani");
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   sld.dialog.currentnode = "Chani_7";
}

void ChaniSettlement_2(string qName)
{
            sld = characterFromId("Chani");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "basement1_back", "Roseau_TownCave", "reload", "reload1_back", "", 20.0);
 
                 pchar.quest.ChaniSettlement_3.win_condition.l1 = "locator";
                 pchar.quest.ChaniSettlement_3.win_condition.l1.location = "Roseau_town";
                 pchar.quest.ChaniSettlement_3.win_condition.l1.locator_group = "reload";
                 pchar.quest.ChaniSettlement_3.win_condition.l1.locator = "basement1_back";
                 pchar.quest.ChaniSettlement_3.function = "ChaniSettlement_3";
}

void ChaniSettlement_3(string qName)
{
            sld = characterFromId("Chani");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocator(sld, "officers", "reload1_1", "", -1);
           DoQuestFunctionDelay("ChaniSettlement_03", 4.0);
}

void ChaniSettlement_03(string qName)
{
                   sld = CharacterFromID("Chani");
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   sld.dialog.currentnode = "Chani_8";
}

void Chani_Dieenemy(string qName)
{
         LocatorReloadEnterDisable("Roseau_TownCave", "reload1_back", true);
         LocatorReloadEnterDisable("Roseau_TownCave", "reload2", true);
         PlaySound("VOICE\Russian\gotica\SFX\AMBIENTCRAWLERSCREAM.wav");
         chr = GetCharacter(NPC_GenerateCharacter("Dieenemy", "Dieenemy", "man", "man", 25, PIRATE, -1, false, "quest"));
          FantomMakeCoolFighter(chr, 25, 50, 50, "blade_19", "pistol6", "bullet", 70);
          ChangeCharacterAddressGroup(chr, "Roseau_TownCave", "monsters", "monster8");
	 LAi_SetImmortal(chr, true);
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
		chr2 = GetCharacter(NPC_GenerateCharacter("Dieenemyskel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		chr2.monster = true; // признак нежити
		chr2.sex = "Skeleton"; 
		chr2.viper = true;
	              LAi_SetImmortal(chr2, true);
		LAi_SetWarriorType(chr2);
		LAi_SetImmortal(chr2, true);//защита от дурака
		ChangeCharacterAddressGroup(chr2, "Roseau_TownCave", "monsters", "monster35");
	                   CreateLocationParticles("large_smoke", "item", "Berglar1"+i, 0.9, 0, 0, "");
		LAi_CharacterDisableDialog(chr2);//запрет диалога
		LAi_SetActorType(chr2);
		LAi_ActorFollow(chr2, chr, "", -1);
	}

            sld = characterFromId("Chani");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocator(sld, "officers", "reload1_2", "", -1);

            LAi_SetActorType(pchar);
            LAi_ActorGoToLocator(pchar, "officers", "reload1_1", "", -1);
            DoQuestFunctionDelay("Chani_Dieenemy_01", 4.0);
}

void Chani_Dieenemy_01(string qName)
{
            LAi_ActorTurnToLocator(sld, "item", "Berglar1");
            LAi_ActorTurnToLocator(pchar, "item", "Berglar1");
            DoQuestFunctionDelay("Chani_Dieenemy_1", 7.0);
}

void Chani_Dieenemy_1(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
            PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEKINESIS_BRIDGE.wav");
            chr = CharacterFromID("Dieenemy");
            LAi_SetActorType(chr);
            LAi_SetWarriorType(chr2);
            LAi_ActorGoToLocator(chr, "item", "Berglar1", "", -1);
            DoQuestFunctionDelay("Chani_Dieenemy_2", 21.0);
            DoQuestFunctionDelay("MAGIC_DEEP", 9.0);

           CreateLocationParticles("shadowstar", "officers", "reload1_2", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload1_2", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload1_2", 1.70, 3, 3, "");

           CreateLocationParticles("shadowstar", "officers", "reload1_1", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload1_1", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload1_1", 1.70, 3, 3, "");
}

void Chani_Dieenemy_2(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");
            chr = CharacterFromID("Dieenemy");
            LAi_SetActorType(chr);
            LAi_SetWarriorType(chr2);
            LAi_ActorTurnToLocator(chr, "monsters", "monster8");
            DoQuestFunctionDelay("Chani_Dieenemy_3", 3.0);
}

void Chani_Dieenemy_3(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
            PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE01.wav");
            chr = CharacterFromID("Dieenemy");
            LAi_SetActorType(chr);
            LAi_SetWarriorType(chr2);
            LAi_ActorTurnToLocator(chr, "officers", "reload1_2");
            DoQuestFunctionDelay("Chani_Dieenemy_4", 3.0);
}

void Chani_Dieenemy_4(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");
            chr = CharacterFromID("Dieenemy");
            LAi_SetActorType(chr);
            LAi_SetWarriorType(chr2);
            LAi_ActorTurnToLocator(chr, "officers", "reload1_1");
            DoQuestFunctionDelay("RUNCOWARD", 2.0);
            DoQuestFunctionDelay("Chani_Dieenemy_5", 3.0);
}

void Chani_Dieenemy_5(string qName)
{
                  chr = CharacterFromID("Dieenemy");
                  LAi_SetActorType(chr);
                  LAi_ActorGoToLocation(chr, "monsters", "monster8", "none", "", "", "", 10.0);
	// нечисть
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
		chr2 = GetCharacter(NPC_GenerateCharacter("Dieenemyskel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		chr2.monster = true; // признак нежити
		chr2.sex = "Skeleton"; 
		chr2.viper = true;
	                   LAi_SetImmortal(chr2, true);
		LAi_SetWarriorType(chr2);
		LAi_SetImmortal(chr2, true);//защита от дурака
	                   CreateLocationParticles("large_smoke", "item", "Berglar1"+i, 0.9, 0, 0, "");
		LAi_CharacterDisableDialog(chr2);//запрет диалога
		LAi_SetActorType(chr2);
		LAi_ActorFollow(chr2, chr, "", -1);
                        }
                  DoQuestFunctionDelay("Chani_Dieenemy_6", 10.0);
}

void Chani_Dieenemy_6(string qName)
{
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
		chr2 = GetCharacter(NPC_GenerateCharacter("Dieenemyskel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		chr2.monster = true; // признак нежити
		chr2.sex = "Skeleton"; 
		chr2.viper = true;
                                      LAi_ActorGoToLocation(chr2, "monsters", "monster8", "none", "", "", "", 10.0);
                        }

                  DoQuestFunctionDelay("Chani_Dieenemy_7", 7.0);
}

void Chani_Dieenemy_7(string qName)
{
                 LocatorReloadEnterDisable("Roseau_TownCave", "reload1_back", false);
                  LocatorReloadEnterDisable("Roseau_TownCave", "reload2", false);                   
                   sld = CharacterFromID("Chani");
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   sld.dialog.currentnode = "Chani_15";
                   LAi_SetPlayerType(pchar);
}

void Chani_Dieenemy_8(string qName)
{
                  sld = CharacterFromID("Chani");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Roseau_town", "goto", "goto22", "", 5.0);
                  pchar.quest.Chani_Dieenemy_9.win_condition.l1 = "locator";
                  pchar.quest.Chani_Dieenemy_9.win_condition.l1.location = "Roseau_town";
                  pchar.quest.Chani_Dieenemy_9.win_condition.l1.locator_group = "reload";
                  pchar.quest.Chani_Dieenemy_9.win_condition.l1.locator = "basement1_back";
                  pchar.quest.Chani_Dieenemy_9.function = "Chani_Dieenemy_9";
}

void Chani_Dieenemy_9(string qName)
{
                   AddQuestRecord("RoseauCharlotte", "8");
                   pchar.questTemp.GothicTorus = "ChaniSettlementGoTorus"; 
                  sld = CharacterFromID("Chani");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "gate_back", "none", "", "", "", 25.0);
}

    //--------------------------- Конец квеста без борьбы ------------------------------

void No_ChaniSettlement(string qName)
{
          sld = CharacterFromID("Roseau_Lightman");
          LAi_SetActorType(sld);
          LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 15.0);
          AddQuestRecord("RoseauCharlotte", "9");
          LocatorReloadEnterDisable("Roseau_TownCave", "reload2", true);
          bDisableFastReload = false;//открыть переход
          LocatorReloadEnterDisable("Roseau_port", "reload1_back", false);//порт открыть
          LocatorReloadEnterDisable("Shore26", "boat", false);//бухту открыть
          LocatorReloadEnterDisable("Shore27", "boat", false);//мыс открыть
          DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания
          CloseQuestHeader("RoseauCharlotte");
          DoQuestFunctionDelay("No_ChaniSettlement_1", 4.0);
}

void No_ChaniSettlement_1(string qName)
{
          LocatorReloadEnterDisable("SantLous_town", "reload10", false);//откроем резеденцию Ли
          pchar.questTemp.GothicLee = "Start_Lee";
          PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
}
    //--------------------------- Продолжение ------------------------------

void Yes_ChaniSettlement(string qName)
{
          LAi_SetActorType(pchar);
          LAi_ActorTurnToLocator(pchar, "reload", "reload1");
          DoQuestFunctionDelay("Yes_ChaniSettlement_1", 4.0);
}

void Yes_ChaniSettlement_1(string qName)
{
            LocatorReloadEnterDisable("Roseau_TownCave", "reload2", false);
            AddQuestRecord("RoseauCharlotte", "10");
            sld = characterFromId("Torus");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 10.0);
            DoQuestFunctionDelay("Yes_ChaniSettlement_2", 5.0);
}

void Yes_ChaniSettlement_2(string qName)
{
                   LAi_SetPlayerType(pchar);
}

void PRESENT(string qName)
{
                   pchar.questTemp.GothicTorus = "RoseauCharlottePRESENT";
	pchar.quest.MayakDieenemy.win_condition.l1 = "Hour";
	pchar.quest.MayakDieenemy.win_condition.l1.start.hour = 0;
	pchar.quest.MayakDieenemy.win_condition.l1.finish.hour = 5;
	pchar.quest.MayakDieenemy.win_condition.l2 = "locator";
	pchar.quest.MayakDieenemy.win_condition.l2.location = "Dominica_Lighthouse_01";
	pchar.quest.MayakDieenemy.win_condition.l2.locator_group = "reload";
	pchar.quest.MayakDieenemy.win_condition.l2.locator = "reload1_back";
	pchar.quest.MayakDieenemy.function = "MayakDieenemy"; 
}

void MayakDieenemy(string qName) //перед маяком
{
 	LocatorReloadEnterDisable(pchar.location, "reload2_back",  true);
                   PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
                   pchar.questTemp.GothicTorus = "RoseauCharlotteMayakDieenemy";
	LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);//запретить драться
        for (int i=1; i<=3; i++)
           {
	if (i == 1)
	{
	sld = GetCharacter(NPC_GenerateCharacter("Torus", "Torus", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "blade300", "pistol1", "bullet", 50);
	sld.name 	= "Торус";
	sld.lastname = "Шардонэ";
	sld.greeting = "Gr_Torus";
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "Torus_MayakDieenemy";
	LAi_SetGroundSitTypeNoGroup(sld);
	LAi_SetHP(sld, 500, 500); // увеличиваем  НР
	sld.cirassId = Items_FindItemIdx("cirass1");
	GiveItem2Character(sld, "blade300");
	sld.equip.blade = "blade300";
	GiveItem2Character(sld, "pistol11");
	EquipCharacterbyItem(sld, "pistol11");
                   TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	LAi_SetCheckMinHP(sld, 10, true, ""); // скрытое бессмертие
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "ass3");
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	}
	else
	{
		if (i == 2)
		{
	sld = GetCharacter(NPC_GenerateCharacter("FISK", "trader_6", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "blade48", "pistol1", "bullet", 50);
	sld.name 	= "Фиск";
	sld.lastname = "";
	sld.greeting = "Gr_FISK";
                   LAi_SetGroundSitTypeNoGroup(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "FISK_MayakDieenemy";
	LAi_SetHP(sld, 500, 500); // увеличиваем  НР
	sld.cirassId = Items_FindItemIdx("cirass1");
	GiveItem2Character(sld, "blade300");
	sld.equip.blade = "blade300";
	GiveItem2Character(sld, "pistol3");
	EquipCharacterbyItem(sld, "pistol3");
                   TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	LAi_SetCheckMinHP(sld, 10, true, ""); // скрытое бессмертие
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "ass2");
	}
	else
	{
	sld = GetCharacter(NPC_GenerateCharacter("SKIP", "shipowner_12_1", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "blade43", "pistol1", "bullet", 50);
	sld.name 	= "Скип";
	sld.lastname = "";
	sld.greeting = "Gr_SKIP";
	LAi_SetGroundSitTypeNoGroup(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "SKIP_MayakDieenemy";
	LAi_SetHP(sld, 500, 500); // увеличиваем  НР
	sld.cirassId = Items_FindItemIdx("cirass1");
                   TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	LAi_SetCheckMinHP(sld, 10, true, ""); // скрытое бессмертие
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "ass4");
			}
		}
	LAi_group_MoveCharacter(sld, "TMP_FRIEND");
        }
	// костер
	ref location = &Locations[FindLocation(pchar.location)];
	ref rItm = ItemsFromID("fire");
	rItm.shown = true;
	rItm.startLocation = location.id;
	rItm.startLocator = "fire";
	location.fire = true;

}

void MayakDieenemy_1(string qName) //перед маяком
{
            PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
            sld2 = characterFromId("Chani");
            LAi_SetActorType(sld2);
            ChangeCharacterAddressGroup(sld2, pchar.location, "reload", "reload1_back");

           sld = GetCharacter(NPC_GenerateCharacter("ChaniMush", "mush_cnb_2", "man", "mushketer", 20, PIRATE, 1, false, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	GiveItem2Character(sld, "unarmed");
	sld.equip.blade = "unarmed";
	GiveItem2Character(sld, "mushket1");
	EquipCharacterbyItem(sld, "mushket1");
	sld.MushketType = "mushket1";
	sld.MushketBulletType = "bullet";
	TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion1", 5);
	LAi_SetCharacterUseBullet(sld, "bullet");
	LAi_SetHP(sld, 150, 150);
	SetSelfSkill(sld, 10, 10, 10, 100, 50);
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "BasicDefense");
	sld.MusketerDistance = 20;
	sld.SuperShooter = true;
                   LAi_SetActorType(sld);
                   ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1_back");
                   DoQuestFunctionDelay("MayakDieenemy_2", 2.0);
}

void MayakDieenemy_2(string qName) //
{
                  sld2 = CharacterFromID("Chani");
                  LAi_SetActorType(sld2);
                  LAi_ActorDialog(sld2, pchar, "", -1, 0);
                  LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "Dominica_Lighthouse_01", "goto", "ass1", "", 5.0);

}

void MayakDieenemy_3(string qName) //
{
            LocatorReloadEnterDisable(pchar.location, "reload2_back",  false);
             sld2 = characterFromId("Chani");
            LAi_SetActorType(sld2);
            LAi_ActorGoToLocation(sld2, "monsters", "monster3", "Dominica_Lighthouse_01", "monsters", "monster3", "", 10.0);

                   sld = characterFromId("ChaniMush");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "goto", "ass1", "Dominica_Lighthouse_01", "goto", "ass1", "", 9.0);
 
	for (i=1; i<=3; i++)
	{
            sld = characterFromId("Torus");
            LAi_SetActorType(sld);
            LAi_ActorAnimation(sld, "Ground_StandUp", "MayakDieenemy_4", 3.5);

            sld = characterFromId("FISK");
            LAi_SetActorType(sld);
            LAi_ActorAnimation(sld, "Ground_StandUp", "MayakDieenemy_4", 3.5);
 
            sld = characterFromId("SKIP");
            LAi_SetActorType(sld);
            LAi_ActorAnimation(sld, "Ground_StandUp", "MayakDieenemy_4", 3.5);
	}
            DeleteAttribute(&locations[FindLocation(pchar.location)], "fire");
            DoQuestFunctionDelay("MayakDieenemy_4", 11.0);
}

void MayakDieenemy_4(string qName) //
{
           PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEKINESIS_BRIDGE.wav");
           CreateLocationParticles("shadowstar", "officers", "reload2_3", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_3", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_3", 1.70, 3, 3, "");

           CreateLocationParticles("shadowstar", "officers", "reload2_2", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_2", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_2", 1.70, 3, 3, "");

           CreateLocationParticles("shadowstar", "officers", "reload2_1", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_1", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "officers", "reload2_1", 1.70, 3, 3, "");

	for (i=1; i<=4; i++)
	{
            sld = characterFromId("Torus");
            LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Dominica_Lighthouse_02", "goto", "goto7", "", 10.0);

            sld = characterFromId("FISK");
            LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Dominica_Lighthouse_02", "goto", "goto29", "", 10.0);

            sld = characterFromId("SKIP");
            LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Dominica_Lighthouse_02", "officers", "reload1_1", "", 10.0);

             sld = CharacterFromID("ChaniMush");
            LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Dominica_Lighthouse_02", "reload", "reload1_back", "", 10.0);
	}
                  pchar.quest.MayakDieenemy_5.win_condition.l1 = "locator";
                  pchar.quest.MayakDieenemy_5.win_condition.l1.location = "Dominica_Lighthouse_02";
                  pchar.quest.MayakDieenemy_5.win_condition.l1.locator_group = "reload";
                  pchar.quest.MayakDieenemy_5.win_condition.l1.locator = "reload1_back";
                  pchar.quest.MayakDieenemy_5.function = "MayakDieenemy_5";

	CreateLocationParticles("fire_incas_Simple", "goto", sTemp, 0.5, 0, 0, "");
	LAi_SetWarriorType(chr);
	LAi_group_MoveCharacter(chr, "TmpEnemy");
	LAi_group_SetRelation("TmpEnemy", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);

}

void MayakDieenemy_5(string qName) //
{
	for (i=1; i<=4; i++)
	{
            sld = characterFromId("Torus");
            LAi_SetWarriorType(sld);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

            sld = characterFromId("FISK");
            LAi_SetWarriorType(sld);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

            sld = characterFromId("SKIP");
            LAi_SetWarriorType(sld);
            LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

            sld2 = characterFromId("ChaniMush");
            LAi_CharacterDisableDialog(sld2);
            LAi_SetWarriorType(sld2);
            LAi_group_MoveCharacter(sld2, LAI_GROUP_PLAYER);
	}

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";

	// скелеты - крутые
	for (i=1; i<=30; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_skel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		chr.MultiFighter = 1.5; // мультифайтер
		chr.MultiShooter = 1.5;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "reload", "reload5");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}

	//Ищущий
	chr2 = characterFromId("Dieenemy");
	FantomMakeCoolFighter(chr2, iRank+4, 80, 80, "topor_04", "pistol11", "bullet", 20);
	SetSPECIAL(chr2, 8, 6, 8, 5, 5, 10, 6);
	LAi_SetHP(chr2, iHp, iHp);
	if (MOD_SKILL_ENEMY_RATE > 4)
	{
		chr2.cirassId = Items_FindItemIdx("cirass1");
		SetCharacterPerk(chr2, "Energaiser");
		SetCharacterPerk(chr2, "SwordplayProfessional");
		SetCharacterPerk(chr2, "HardHitter");
		TakeNItems(pchar, "potion2", MOD_SKILL_ENEMY_RATE-5);
	}
	float fMft = MOD_SKILL_ENEMY_RATE/10;
	chr2.MultiFighter = 2.5; // мультифайтер
	chr2.MultiShooter = 2.5;
	chr2.LSC_clan = true;
	chr2.monster = true; // признак нежити
	chr2.sex = "Skeleton"; 
	chr2.viper = true;
	chr2.SaveItemsForDead = true;
	chr2.DontClearDead = true;
	GiveItem2Character(chr2, "");
	LAi_CharacterDisableDialog(chr2);
	LAi_SetGuardianType(chr2);
                   LAi_ActorTurnToLocator(chr2, "officers", "reload1_2");
                   LAi_SetImmortal(chr2, true);
	ChangeCharacterAddressGroup(chr2, "Dominica_Lighthouse_02", "goto", "goto23");

	// прерывание на локатор-детектор
	pchar.quest.MayakDieenemy_6.win_condition.l1 = "locator";
	pchar.quest.MayakDieenemy_6.win_condition.l1.location = "Dominica_Lighthouse_02";
	pchar.quest.MayakDieenemy_6.win_condition.l1.locator_group = "reload";
	pchar.quest.MayakDieenemy_6.win_condition.l1.locator = "reload1_back";
	pchar.quest.MayakDieenemy_6.function = "MayakDieenemy_6";
}

void MayakDieenemy_6(string qName) //
{
                  LocatorReloadEnterDisable("Dominica_Lighthouse_02", "reload5", true);
                  DoQuestFunctionDelay("DIEENEMY", 2.0);
                  DoQuestFunctionDelay("ZOM_ATTACK", 5.0);
                  chr2 = CharacterFromID("Dieenemy");
                  LAi_SetActorType(chr2);
                  LAi_ActorGoToLocation(chr2, "reload", "reload5", "none", "", "", "", 25.0);
                  DoQuestFunctionDelay("MayakDieenemy_7", 30.0);
}

void MayakDieenemy_7(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                   DoQuestFunctionDelay("DIEENEMY", 2.0);
	CreateLocationParticles("item", "goto", "goto18", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto18", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto18", 1.20, 2, 2, "");
                  DoQuestFunctionDelay("ORC_ATTACK", 1.0);
                  DoQuestFunctionDelay("MayakDieenemy_8", 4.0);
}

void MayakDieenemy_8(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_WARN01.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc1_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "goto", "goto18");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}

                  DoQuestFunctionDelay("MayakDieenemy_9", 20.0);
}

void MayakDieenemy_9(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                   DoQuestFunctionDelay("DIEENEMY", 2.0);
                  DoQuestFunctionDelay("ORC_ATTACK", 7.0);
                  DoQuestFunctionDelay("ZOM_ATTACK", 8.0);
	CreateLocationParticles("item", "goto", "goto14", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto14", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto14", 1.20, 2, 2, "");
                   DoQuestFunctionDelay("MayakDieenemy_10", 4.0);
}
void MayakDieenemy_10(string qName) //
{

                   PlaySound("VOICE\Russian\gotica\SFX\DEM_WARN01.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc2_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "goto", "goto14");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
                  DoQuestFunctionDelay("MayakDieenemy_11", 20.0);
}

void MayakDieenemy_11(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                  DoQuestFunctionDelay("DIEENEMY", 2.0);
                  DoQuestFunctionDelay("ORC_ATTACK", 7.0);
                  DoQuestFunctionDelay("ZOM_ATTACK", 8.0);
	CreateLocationParticles("item", "goto", "goto16", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto16", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto16", 1.20, 2, 2, "");
                  DoQuestFunctionDelay("MayakDieenemy_12", 4.0);
}
void MayakDieenemy_12(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_WARN01.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc3_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "goto", "goto16");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
                  DoQuestFunctionDelay("MayakDieenemy_13", 20.0);
}

void MayakDieenemy_13(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                  DoQuestFunctionDelay("DIEENEMY", 2.0);
                  DoQuestFunctionDelay("ORC_ATTACK", 7.0);
                  DoQuestFunctionDelay("ZOM_ATTACK", 8.0);
	CreateLocationParticles("item", "goto", "goto23", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto23", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto23", 1.20, 2, 2, "");
                  DoQuestFunctionDelay("MayakDieenemy_14", 4.0);
}
void MayakDieenemy_14(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_ATTACK01.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc4_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "goto", "goto23");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
                   DoQuestFunctionDelay("MayakDieenemy_15", 20.0);
}

void MayakDieenemy_15(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_ATTACK01.wav");
                  DoQuestFunctionDelay("DIEENEMY", 2.0);
                  DoQuestFunctionDelay("ORC_ATTACK", 7.0);
	CreateLocationParticles("item", "goto", "goto11", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto11", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto11", 1.20, 2, 2, "");
                  DoQuestFunctionDelay("MayakDieenemy_16", 4.0);
}

void MayakDieenemy_16(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc5_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_02", "goto", "goto11");
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
	
                  DoQuestFunctionDelay("MayakDieenemy_17", 10.0);
}

void MayakDieenemy_17(string qName) //
{
                   pchar.questTemp.GothicTorus = "ChaniMayakDieenemy";
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");
                   DoQuestFunctionDelay("ORC_ATTACK", 7.0);
                   DoQuestFunctionDelay("ZOM_ATTACK", 8.0);

                   sld = CharacterFromID("Torus");
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "Torus_Mayak_Dieenemy";

                   sld = CharacterFromID("FISK");
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "FISK_Mayak_Dieenemy";

                   sld = CharacterFromID("SKIP");
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "SKIP_Mayak_Dieenemy";		
}

void MayakDieenemy_18(string qName) //
{
                  sld2 = CharacterFromID("Chani");
                  LAi_SetActorType(sld2);
                  ChangeCharacterAddressGroup(sld2, pchar.location, "reload", "reload1_back");

	for (i=1; i<=3; i++)
	{
                  sld = characterFromId("FISK");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 35.0);

                  sld = characterFromId("SKIP");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 35.0);

                  sld2 = CharacterFromID("ChaniMush");
                  LAi_CharacterDisableDialog(sld2);
                  LAi_SetActorType(sld2);
                  LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "none", "", "", "", 35.0);

	}
                  DoQuestFunctionDelay("MayakDieenemy_19", 2.0);	
}

void MayakDieenemy_19(string qName) //
{
                  sld2 = CharacterFromID("Chani");
                  LAi_SetActorType(sld2);
                  LAi_ActorDialog(sld2, pchar, "", -1, 0);
                  LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "Dominica_Lighthouse_02", "goto", "goto7", "", 7.0);

}

void MayakDieenemy_20(string qName) //
{
                  sld2 = CharacterFromID("Chani");
                  LAi_SetActorType(sld2);
                  LAi_ActorDialog(sld2, pchar, "", -1, 0);
                   LAi_ActorTurnToLocator(sld2, "reload", "reload5");
                  LAi_ActorRunToLocation(sld2, "goto", "goto20", "Dominica_Lighthouse_02", "goto", "goto20", "", 35.0);
                  DoQuestFunctionDelay("MayakDieenemy_21", 37.0);	

}
void MayakDieenemy_21(string qName) //
{
           LocatorReloadEnterDisable("Dominica_Lighthouse_02", "reload5", false);
           PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEKINESIS_BRIDGE.wav");
           CreateLocationParticles("shadowstar", "reload", "reload5", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "reload", "reload5", 1.70, 3, 3, "");
           CreateLocationParticles("shadowstar", "reload", "reload5", 1.70, 3, 3, "");
           // прерывание на локатор-детектор
           pchar.quest.MayakDieenemy_22.win_condition.l1 = "locator";
           pchar.quest.MayakDieenemy_22.win_condition.l1.location = "Dominica_Lighthouse_Inside";
           pchar.quest.MayakDieenemy_22.win_condition.l1.locator_group = "reload";
           pchar.quest.MayakDieenemy_22.win_condition.l1.locator = "reload1";
           pchar.quest.MayakDieenemy_22.function = "MayakDieenemy_22"; 
}

void MayakDieenemy_22(string qName) //
{
                    chrDisableReloadToLocation = true;//закрыть локацию
                    DoQuestFunctionDelay("DIEENEMY", 2.0);
                    DoQuestFunctionDelay("ZOM_ATTACK", 4.0);

                   chr = GetCharacter(NPC_GenerateCharacter("Dieenemy", "Dieenemy", "man", "man", 100, PIRATE, -1, false, "quest"));
	FantomMakeCoolFighter(chr, 100, 100, 100, "topor_04", "pistol11", "bullet", 20);
	LAi_SetHP(chr, 1000.0, 1000.0);
	LAi_SetImmortal(chr, false);
	GiveItem2Character(chr, "");
	ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_Inside", "goto", "goto2");
	LAi_SetWarriorType(chr);
	LAi_group_MoveCharacter(chr, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	DoQuestFunctionDelay("MayakDieenemy_23", 10.0);
}

void MayakDieenemy_23(string qName) //
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
	CreateLocationParticles("item", "goto", "goto2", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto2", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto2", 1.20, 2, 2, "");
	CreateLocationParticles("fire_incas_Simple", "goto", sTemp, 0.5, 0, 0, "");
                   DoQuestFunctionDelay("MayakDieenemy_24", 4.0);
}

void MayakDieenemy_24(string qName) //
{
                   DoQuestFunctionDelay("ORC_ATTACK", 2.0);
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_Orc1_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Dominica_Lighthouse_Inside", "goto", "goto2");
		LAi_group_MoveCharacter(chr, "EnemyFight");
		if(i == 1)
		{
			chr.SaveItemsForDead   = true;
			TakeNItems(chr, "blade53", 1);
		}
	}

	//Торуса в помощь
	for(i=1; i<=1; i++)
	{
                   sld = characterFromId("Torus");
                   LAi_SetWarriorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.dialog.currentnode = "Torus_Mayak";
                   LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	ChangeCharacterAddressGroup(sld, "Dominica_Lighthouse_Inside", "reload", "reload1");
	}

}

void MayakDieenemy_25(string qName) //
{
           chrDisableReloadToLocation = false;//открыть локацию
            sld = characterFromId("Torus");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload1", "Dominica_Lighthouse_02", "reload", "reload5", "", 5.0);
           // прерывание на локатор-детектор
           pchar.quest.MayakDieenemy_26.win_condition.l1 = "locator";
           pchar.quest.MayakDieenemy_26.win_condition.l1.location = "Dominica_Lighthouse_02";
           pchar.quest.MayakDieenemy_26.win_condition.l1.locator_group = "reload";
           pchar.quest.MayakDieenemy_26.win_condition.l1.locator = "reload5";
           pchar.quest.MayakDieenemy_26.function = "MayakDieenemy_26"; 
}

void MayakDieenemy_26(string qName) //
{
                  pchar.questTemp.GothicTorus = "ChaniMayak";
                  sld = characterFromId("Torus");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Dominica_Lighthouse_02", "reload", "reload1_back", "", 75.0);

                  sld2 = CharacterFromID("Chani");
                  LAi_SetActorType(sld2);
                  LAi_ActorDialog(sld2, pchar, "", -1, 0);

}

void MayakDieenemy_27(string qName) //
{
          AddQuestRecord("RoseauCharlotte", "11");
          DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания
          sld2 = CharacterFromID("Chani");
          LAi_SetActorType(sld2);
          LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "none", "", "", "", 100.0);
           // прерывание на локатор-детектор
           pchar.quest.MayakDieenemy_28.win_condition.l1 = "locator";
           pchar.quest.MayakDieenemy_28.win_condition.l1.location = "Dominica_Lighthouse_02";
           pchar.quest.MayakDieenemy_28.win_condition.l1.locator_group = "reload";
           pchar.quest.MayakDieenemy_28.win_condition.l1.locator = "reload1_back";
           pchar.quest.MayakDieenemy_28.function = "MayakDieenemy_28"; 

}

void MayakDieenemy_28(string qName) //
{
                 pchar.questTemp.GothicTorus = "MayakNoDieenemy";

                  sld = CharacterFromID("Torus");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 120.0);

                  sld = CharacterFromID("W_headclerk");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 120.0);
                   DoQuestFunctionDelay("MayakDieenemy_29", 110.0);
}

void MayakDieenemy_29(string qName) //
{
                  bDisableFastReload = false;//открыть переход
                  DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания
                  LocatorReloadEnterDisable("Roseau_port", "reload1_back", false);//порт открыть
                  LocatorReloadEnterDisable("Shore26", "boat", false);//бухту открыть
                  LocatorReloadEnterDisable("Shore27", "boat", false);//мыс открыть
                  CloseQuestHeader("RoseauCharlotte");
                 // Одержимые
                  SetTimerFunction("Gothic_Obsession", 0, 0, 10);

                  LocatorReloadEnterDisable("SantLous_town", "reload10", false);//откроем резеденцию Ли
                  pchar.questTemp.GothicLee = "Start_Lee";
                  LAi_SetPlayerType(Pchar);

                   sld = CharacterFromID("Torus");
 	sld.City = "Roseau";
	sld.location	= "Roseau_townhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Mayor\Torus.c";
	sld.greeting = "Gr_Torus";
	sld.nation = PIRATE;
	sld.quest.type = "hovernor";
	SetFantomParamFromRank(sld, sld.Rank, true);
	SetRandSPECIAL(sld);
                   SetSelfSkill(sld, 90, 90, 90, 60, 70);
	LAi_SetHP(sld, 500, 500); // увеличиваем  НР
	sld.cirassId = Items_FindItemIdx("cirass1");
	GiveItem2Character(sld, "blade300");
	sld.equip.blade = "blade300";
	GiveItem2Character(sld, "pistol11");
	EquipCharacterbyItem(sld, "pistol11");
                   TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);


            sld2 = GetCharacter(NPC_GenerateCharacter("Torusofficer1_"+i, "mercen_"+(rand(29)+1), "man", "man", 30, PIRATE, -1, true, "soldier"));
            FantomMakeCoolFighter(sld2, 30, 90, 90, "blade_28", "pistol4", "bullet", 100);
            LAi_SetStayType(sld2);
            sld2.dialog.filename    = "Gothic_Quest\npc\Captain.c";
            sld2.greeting = "town_pirate";
            LAi_group_MoveCharacter(sld2, "PIRATE_CITIZENS");
            ChangeCharacterAddressGroup(sld2, "Roseau_townhall", "goto",  "goto1");

            sld2 = GetCharacter(NPC_GenerateCharacter("Torusofficer2_"+i, "mercen_"+(rand(29)+1), "man", "man", 30, PIRATE, -1, true, "soldier"));
            FantomMakeCoolFighter(sld2, 30, 90, 90, "blade_28", "pistol4", "bullet", 100);
            LAi_SetStayType(sld2);
            sld2.dialog.filename    = "Gothic_Quest\npc\Captain.c";
            sld2.greeting = "town_pirate";
            LAi_group_MoveCharacter(sld2, "PIRATE_CITIZENS");
            ChangeCharacterAddressGroup(sld2, "Roseau_townhall", "goto",  "goto2");


                   sld = CharacterFromID("W_headclerk");
	sld.model	= "QSharp";
	sld.sex = "man";
	sld.name 	= "Раймондэ";
                   sld.lastname = "Оберто";
 	sld.City = "Roseau";
	sld.location	= "Roseau_Roomtownhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Gothic_Quest\Office_Rosea.c";
	sld.dialog.currentnode = "W_headclerk";
	sld.nation = PIRATE;
	sld.greeting = "official";
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);
	sld.item_date = "";
	sld.Merchant.type = "company";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
}


void MayakNoDieenemy_1(string qName) //Джека на маяк
{ 
	sld = characterFromId("Roseau_Lightman");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Roseau_town", "reload", "reload1_back", "Jack_Golighthouse_1", -1);
					
	PChar.quest.Jack_Golighthouse_1.win_condition.l1 = "locator";
	PChar.quest.Jack_Golighthouse_1.win_condition.l1.location = "Roseau_town";
	PChar.quest.Jack_Golighthouse_1.win_condition.l1.locator_group = "reload";
	PChar.quest.Jack_Golighthouse_1.win_condition.l1.locator = "reload1_back";
	PChar.quest.Jack_Golighthouse_1.function = "Jack_Golighthouse_1";
}

void Jack_Golighthouse_1(string qName)
{
	sld = characterFromId("Roseau_Lightman");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "basement1_back", "Roseau_TownCave", "reload", "reload1_back", "Jack_Golighthouse_2", -1);

	PChar.quest.Jack_Golighthouse_2.win_condition.l1 = "locator";
	PChar.quest.Jack_Golighthouse_2.win_condition.l1.location = "Roseau_TownCave";
	PChar.quest.Jack_Golighthouse_2.win_condition.l1.locator_group = "reload";
	PChar.quest.Jack_Golighthouse_2.win_condition.l1.locator = "reload1_back";
	PChar.quest.Jack_Golighthouse_2.function = "Jack_Golighthouse_2";

}

void Jack_Golighthouse_2(string qName)
{
	sld = characterFromId("Roseau_Lightman");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2", "Dominica_Lighthouse_01", "reload", "reload1_back", "Jack_Golighthouse_3", -1);

	PChar.quest.Jack_Golighthouse_3.win_condition.l1 = "locator";
	PChar.quest.Jack_Golighthouse_3.win_condition.l1.location = "Dominica_Lighthouse_01";
	PChar.quest.Jack_Golighthouse_3.win_condition.l1.locator_group = "reload";
	PChar.quest.Jack_Golighthouse_3.win_condition.l1.locator = "reload1_back";
	PChar.quest.Jack_Golighthouse_3.function = "Jack_Golighthouse_3";

}

void Jack_Golighthouse_3(string qName)
{
	sld = characterFromId("Roseau_Lightman");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2_back", "Dominica_Lighthouse_02", "goto", "goto29", "Jack_Golighthouse_4", -1);

	PChar.quest.Jack_Golighthouse_4.win_condition.l1 = "locator";
	PChar.quest.Jack_Golighthouse_4.win_condition.l1.location = "Dominica_Lighthouse_02";
	PChar.quest.Jack_Golighthouse_4.win_condition.l1.locator_group = "reload";
	PChar.quest.Jack_Golighthouse_4.win_condition.l1.locator = "reload1_back";
	PChar.quest.Jack_Golighthouse_4.function = "Jack_Golighthouse_4";
}

void Jack_Golighthouse_4(string qName)
{
	sld = characterFromId("Roseau_Lightman");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", -1);

	PChar.quest.Jack_Golighthouse_5.win_condition.l1 = "locator";
	PChar.quest.Jack_Golighthouse_5.win_condition.l1.location = "Dominica_Lighthouse_02";
	PChar.quest.Jack_Golighthouse_5.win_condition.l1.locator_group = "reload";
	PChar.quest.Jack_Golighthouse_5.win_condition.l1.locator = "reload2";
	PChar.quest.Jack_Golighthouse_5.function = "Jack_Golighthouse_5";
}

void Jack_Golighthouse_5(string qName)
{
                   pchar.questTemp.GothicTorus = "JackMayak";
	                                                                                      //Смотритель маяка
	sld.id		= "Roseau_Lightman";
	sld.name 	= "Джек";
	sld.lastname = "";
	sld.model	= "keeper_8";
	sld.model.animation = "man_B";
	sld.sex = "man";
	sld.City = "Roseau";
	sld.location = "Dominica_Lighthouse";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetHuberType(sld);
	sld.Merchant.type = "lightman";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	sld.nation = PIRATE;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	LAi_SetPlayerType(Pchar);

}


void Jack_Golighthouse_6(string qName)
{
	sld = characterFromId("Roseau_Lightman");
	sld.Dialog.Filename = "Common_lighthouse.c";
                   DeleteAttribute(pchar, "GenQuest.CantRun");//запрет бега

	AddComplexSeaExpToScill(600, 500, 500, 0, 300, 500, 0);
	ChangeCharacterComplexReputation(pchar, "fame", 10);
	ChangeCharacterComplexReputation(pchar, "authority", 20);

	PChar.GenQuestBox.Dominica_Lighthouse_Inside = true;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.ArtRing6 = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.newblade17 = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.gold = 100000;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.gold_dublon = 250;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.Chest = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.Chestt = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.icollection = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.icollectionn = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.GoldenBar = 50;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.totem_08 = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.totem_12 = 1;
	PChar.GenQuestBox.Dominica_Lighthouse_Inside.box1.items.pistol10 = 1;
}
		// <--Джек смотритель маяка


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Квест, похищение донны Анны
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void GothicLee_Havana_FightInHouse(string qName)
{
	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "Havana_houseS1", "reload", "reload1");
	}
}
void GothicLee_townhall(string qName)
{
           LocatorReloadEnterDisable("SantLous_townhall", "reload1_back", true);
           LocatorReloadEnterDisable("SantLous_townhall", "reload2", true);
            sld = characterFromId("AnnaDeLeiva");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "SantLous_townhall_room", "barmen", "bar1", 20.0);	
}
void GothicLee_townhall_room(string qName)
{
            sld = characterFromId("LEE");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 10.0);
            DoQuestFunctionDelay("GothicLee_townhall_room_01", 7.0);
}

void GothicLee_townhall_room_01(string qName)
{
            PlaySound("Interface\DOOR_CLOSE02B.wav");
            DoQuestFunctionDelay("GothicLee_townhall_room_02", 3.0);
}

void GothicLee_townhall_room_02(string qName)
{
            PlaySound("interface\key.wav");//щелк!
            DoQuestFunctionDelay("GothicLee_sex_townhallroom", 3.0);
}

void GothicLee_sex_townhallroom(string qName)
{
                     LocatorReloadEnterDisable("SantLous_townhall", "reload1_back", false);
                     PlaySound("Sex\sex11.wav");
	  SetFunctionTimerCondition("LEE_townhallroom", 0, 0, 2, false);
}

void LEE_townhallroom(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("AnnaDeLeiva", "Catherine", "woman", "woman", 10, SPAIN, -1, false, "quest"));
	sld.name = "Анна Рамирес";
	sld.lastname = "де Ли";
	sld.Dialog.Filename = "Gothic_Quest\GothicLine\AnnaDeLeiva.c";
	sld.dialog.currentnode = "AnnaDeLeiva";
	ChangeCharacterAddressGroup(sld, "SantLous_townhall_room", "barmen","bar1");
	LAi_SetStayType(sld);
	LAi_SetImmortal(sld, true);

                   sld = characterFromId("LEE");
	sld.City = "SantLous";
	sld.location	= "SantLous_townhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Mayor\LEE.c";
	LAi_SetHuberType(sld);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////Квест, поиски Библии
//////////////////////////////////////////////////////////////////////////////////////

void SeekBible_FortFrance_Graveyard_1(string qName)
{
                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_KEYMISSING.wav");
	pchar.quest.SeekBible_WeWon1.win_condition.l1 = "locator";
	pchar.quest.SeekBible_WeWon1.win_condition.l1.location = "FortFrance_Graveyard_crypt";
	pchar.quest.SeekBible_WeWon1.win_condition.l1.locator_group = "reload";
	pchar.quest.SeekBible_WeWon1.win_condition.l1.locator = "reload1";
	pchar.quest.SeekBible_WeWon1.function = "SeekBible_crypt";
}


void SeekBible_hour(string qName) // в скрипте
{
           LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload1", true);
           LocatorReloadEnterDisable("FortFrance_church IM", "reload3", false);  
}
void SeekBible_crypt(string qName) // в скрипте
{
                     PlaySound("VOICE\Russian\gotica\SFX\AMBIENTTONE_03_DARK.wav");
                     LAi_SetActorType(pchar);
	LAi_ActorGoToLocator(pchar, "reload", "reload2", "", -1);
                     DoQuestFunctionDelay("SeekBible_crypt_1", 12.0);
}
void SeekBible_crypt_1(string qName) // в скрипте
{
         LAi_SetBarmanType(pchar);
         DoQuestFunctionDelay("SeekBible_crypt_2", 4.0);
}
void SeekBible_crypt_2(string qName) // в скрипте
{
         PlaySound("VOICE\Russian\GOTHIC\GG\SCOPENSLASTDOOR.wav");
         DoQuestFunctionDelay("SeekBible_crypt_3", 8.0);
}
void SeekBible_crypt_3(string qName) // в скрипте
{
          //RemoveItems(PChar, "LegransMap", 1);
           LAi_SetPlayerType(pchar);
         PlaySound("VOICE\Russian\gotica\SFX\AIRBAG_OUT.wav");
           LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload2", false); 
           LocatorReloadEnterDisable("FortFrance_church IM", "reload2", true); 
           DoQuestFunctionDelay("SeekBible_crypt_4", 4.0);
}

void SeekBible_crypt_4(string qName) // в скрипте
{
       PlaySound("Ambient\CAVE\MYSTERY_03.wav");
	pchar.quest.SeekBible_crypt_3.win_condition.l1 = "locator";
	pchar.quest.SeekBible_crypt_3.win_condition.l1.location = "FortFrance_Graveyard_crypt";
	pchar.quest.SeekBible_crypt_3.win_condition.l1.locator_group = "reload";
	pchar.quest.SeekBible_crypt_3.win_condition.l1.locator = "reload1";
	pchar.quest.SeekBible_crypt_3.function = "SeekBible_crypt_5";
}

void SeekBible_crypt_5(string qName) // в скрипте
{
 	PlaySound("Ambient\CAVE\MYSTERY_03.wav");
	LAi_group_Delete("EnemyFight");
	LAi_SetActorType(pchar);
	LAi_ActorTurnToLocator(pchar, "goto", "goto8");
	CreateLocationParticles("large_smoke", "goto", "goto8", 0.7, 0, 0, "");
	DoQuestFunctionDelay("SeekBible_SetLandSkel", 7.0);
	DoQuestFunctionDelay("Terrapin_SetMusic", 1.2);
}

void SeekBible_SetLandSkel(string qName)
{
	PlaySound("Types\skel.wav");
	int iRank = 45+MOD_SKILL_ENEMY_RATE*3;
	int iHp = 400+MOD_SKILL_ENEMY_RATE*80;
	sld = GetCharacter(NPC_GenerateCharacter("SeekBible_skel", "skeletcap", "skeleton", "skeleton", iRank, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, iRank, 100, 100, "topor_010", "", "", 50);
	SetSPECIAL(sld, 10, 10, 10, 3, 3, 10, 10);
	LAi_SetHP(sld, iHp, iHp);
	if (MOD_SKILL_ENEMY_RATE > 4)
	{
		sld.cirassId = Items_FindItemIdx("cirass1");
		SetCharacterPerk(sld, "Energaiser");
		SetCharacterPerk(sld, "SwordplayProfessional");
		SetCharacterPerk(sld, "HardHitter");
	}
	float fMft = MOD_SKILL_ENEMY_RATE/10;
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.name = "Самуэль";
	sld.lastname = "Кохэно";
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	LAi_SetActorType(sld);
	LAi_ActorAnimation(sld, "Ground_sitting", "SeekBible_skeletcap", 3.0);
	ChangeCharacterAddressGroup(sld, "FortFrance_Graveyard_crypt", "goto", "goto8");
	CreateLocationParticles("fire_incas_Simple", "goto", "goto8", 0.7, 0, 0, "");
	DoQuestFunctionDelay("DIEENEMY", 10.0);
}

void SeekBible_LandSkelAttack(string qName) // в скрипте
{
 	PlaySound("Ambient\CAVE\MYSTERY_03.wav");
	sld = characterFromId("SeekBible_skel");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload1");
	DoQuestFunctionDelay("SeekBible_LandSkelAttack_1", 3.0);
}

void SeekBible_LandSkelAttack_1(string qName) // скелет Самуэль атакует
{
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	PlaySound("Reef\reef_01.wav");
	LAi_SetPlayerType(pchar);
	sld = characterFromId("SeekBible_skel");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	DoQuestFunctionDelay("Terrapin_SetMusic", 0.5);
	DoQuestFunctionDelay("SeekBibleskel", 20.5);
	CreateLocationParticles("large_smoke", "goto", "goto"+i, 0.9, 0, 0, "");

	PChar.quest.SeekBibleskel.win_condition.l1 = "NPC_Death";
	PChar.quest.SeekBibleskel.win_condition.l1.character = "SeekBible_skel";
	PChar.quest.SeekBibleskel.function = "SeekBible_crypt_7";
}

void SeekBibleskel(string qName)
{
                     Log_QuestInfo("Со скелетами надо подраться.");
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	// нечисть
	int iRank = 36+MOD_SKILL_ENEMY_RATE*2;
	for (int i=1; i<=5; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("SeekBible_skel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);
		sld.monster = true; // признак нежити
		sld.sex = "Skeleton"; 
		sld.viper = true;
		LAi_SetWarriorType(sld);
		ChangeCharacterAddressGroup(sld, "FortFrance_Graveyard_crypt", "monsters", "monster"+i);
	CreateLocationParticles("large_smoke", "monsters", "monster"+i, 0.9, 0, 0, "");
		LAi_group_MoveCharacter(sld, "EnemyFight");
			}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "SeekBible_LandSkelDie");
	LAi_SetFightMode(pchar, true);
	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "FortFrance_Graveyard_crypt", "reload", "reload1");
                  LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload1", false);
	pchar.quest.SeekBible_crypt_6.win_condition.l1 = "locator";
	pchar.quest.SeekBible_crypt_6.win_condition.l1.location = "FortFrance_Graveyard";
	pchar.quest.SeekBible_crypt_6.win_condition.l1.locator_group = "reload";
	pchar.quest.SeekBible_crypt_6.win_condition.l1.locator = "reload5";
	pchar.quest.SeekBible_crypt_6.function = "SeekBible_crypt_6";

	}
}
void SeekBible_crypt_6(string qName) // в скрипте
{
           PlaySound("VOICE\Russian\gotica\SFX\CHAPTER_01.wav");
           LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload1", false);
           LocatorReloadEnterDisable("FortFrance_church IM", "reload2", false);
           pchar.questTemp.GothicLee = "SeekBible_IHaveMap";  
}

void SeekBible_crypt_7(string qName) // в скрипте
{
                   LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload1", false);
                   pchar.quest.SeekBible_crypt_7.win_condition.l1 = "locator";
	pchar.quest.SeekBible_crypt_7.win_condition.l1.location = "FortFrance_Graveyard";
	pchar.quest.SeekBible_crypt_7.win_condition.l1.locator_group = "reload";
	pchar.quest.SeekBible_crypt_7.win_condition.l1.locator = "reload5";
	pchar.quest.SeekBible_crypt_7.function = "SeekBible_crypt_6";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////Квест. Захват Санто-Доминго
//////////////////////////////////////////////////////////////////////////////////////

void GothicLee_Mayor_death(string qName)
{
            sld = characterFromId("SantoDomingo_Mayor");
            ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
            LAi_SetActorType(sld);
            LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 13.0);
            DoQuestFunctionDelay("GothicLee_Mayor_death_01", 12.0);
}

void GothicLee_Mayor_death_01(string qName)
{
            PlaySound("Interface\DOOR_CLOSE02B.wav");
            DoQuestFunctionDelay("GothicLee_Mayor_death_02", 3.0);
}

void GothicLee_Mayor_death_02(string qName)
{
           LocatorReloadEnterDisable("SantoDomingo_townhall", "reload2", true);
            PlaySound("interface\key.wav");//щелк!
            DoQuestFunctionDelay("GothicLee_Mayor_death_03", 3.0);
}

void GothicLee_Mayor_death_03(string qName)
{
            PlaySound("People Fight\MushketShot.wav");
            DoQuestFunctionDelay("GothicLee_Mayor_death_04", 4.0);
}

void GothicLee_Mayor_death_04(string qName)
{
            AddQuestRecord("GothicLee_10_OccupySantoDomingo", "2");
            chrDisableReloadToLocation = false;
            SetFunctionTimerCondition("GothicLee_MayorHAGEN_townhall", 0, 0, 2, false);
}

void GothicLee_MayorHAGEN_townhall(string qName)
{
                   LocatorReloadEnterDisable("SantoDomingo_townhall", "reload2", false);
	sld = GetCharacter(NPC_GenerateCharacter("HAGEN", "Hagen", "man", "man", 10, FRANCE, -1, false, "quest"));
	sld.name = "Лорд Хаген";
                   sld.lastname = "";
	sld.City = "SantoDomingo";
	sld.location	= "SantoDomingo_townhall";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.greeting = "Gr_HAGEN";
	sld.Dialog.Filename = "Common_Mayor.c";
	sld.nation = FRANCE;
	sld.quest.type = "hovernor";
	GiveItem2Character(sld, GUN_COMMON);
	GiveItem2Character(sld, BLADE_LONG);
	EquipCharacterbyItem(sld, GUN_COMMON); 
	EquipCharacterbyItem(sld, BLADE_LONG); 
	SetRandSPECIAL(sld);
     SetSelfSkill(sld, 90, 90, 90, 60, 70);
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_SetHuberType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	LAi_SetImmortal(sld, true);
	// переделываем Священика
	sld = characterFromId("SantoDomingo_Priest");
	sld.model = "priest_2";
	Characters_RefreshModel(sld);
	sld.name 	= "Жан";
    	sld.lastname = "Бребеф";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем ОФициантку
	sld = characterFromId("SantoDomingo_waitress");
	sld.model = "women_16";
	Characters_RefreshModel(sld);
	sld.name 	= "Шарлотта";
    	sld.lastname = "Корде";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Трактирщика
	sld = characterFromId("SantoDomingo_tavernkeeper");
	sld.model = "barmen_3";
	Characters_RefreshModel(sld);
	sld.name 	= "Жан-Поль";
    	sld.lastname = "Марат";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Торговца
	sld = characterFromId("SantoDomingo_trader");
	sld.model = "trader_3";
	Characters_RefreshModel(sld);
	sld.name 	= "Поль";
    	sld.lastname = "Баррас";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Корабела
	sld = characterFromId("SantoDomingo_shipyarder");
	sld.model = "shipowner_5";
	Characters_RefreshModel(sld);
	sld.name 	= "Жан";
    	sld.lastname = "Лафит";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Банкира
	sld = characterFromId("SantoDomingo_usurer");
	sld.model = "citiz_11";
	Characters_RefreshModel(sld);
	sld.name 	= "Максимильян";
    	sld.lastname = "Робеспьер";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Начальника порта
	sld = characterFromId("SantoDomingo_PortMan");
	sld.model = "citiz_17";
	Characters_RefreshModel(sld);
	sld.name 	= "Жорж";
    	sld.lastname = "Дантон";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	// переделываем Хозяйку борделя
	sld = characterFromId("SantoDomingo_Hostess");
	sld.model.animation = "towngirl";
	sld.model = "women_5";
	Characters_RefreshModel(sld);
	sld.name 	= "Олимпия";
    	sld.lastname = "";
	sld.nation = FRANCE;
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Посылка для Сагитты" ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void GothicSagitta_Start(string qName)//начало истории 
{
	LAi_LocationDisableOfficersGen("Guadeloupe_Mines", true); //офицеров не пускать
	PChar.quest.GothicSagitta_Start_1.win_condition.l1 = "locator";
	PChar.quest.GothicSagitta_Start_1.win_condition.l1.location = "Guadeloupe_Mines";
	PChar.quest.GothicSagitta_Start_1.win_condition.l1.locator_group = "goto";
	PChar.quest.GothicSagitta_Start_1.win_condition.l1.locator = "goto8";
	PChar.quest.GothicSagitta_Start_1.function = "GothicSagitta_1";
}

void GothicSagitta_1(string qName)
{
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                   DoQuestFunctionDelay("GothicSagitta_2", 5.0);
}

void GothicSagitta_2(string qName)
{
                   chrDisableReloadToLocation = true;//закрыть локацию
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_ATTACK01.wav");
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Dieenemy_skel_"+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Guadeloupe_Mines", "goto", "goto5");
		LAi_group_MoveCharacter(chr, "EnemyFight");
                                       DoQuestFunctionDelay("GothicSagitta_3", 5.0);
	}
}

void GothicSagitta_3(string qName)
{
          PlaySound("VOICE\Russian\gotica\SFX\MFX_SLEEP_CAST.wav");
          DoQuestFunctionDelay("GothicSagitta_4", 2.0);
}

void GothicSagitta_4(string qName)
{
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_MONSTERKILLED.wav");
	LAi_LocationDisableOfficersGen("Guadeloupe_Mines", false); //офицеров пускать
	//Сагитту в помощь
	for(i=1; i<=1; i++)
	{
	pchar.questTemp.GothicSagitta = "Delivery";
                   sld = characterFromId("Sagitta");
                   LAi_SetWarriorType(sld);
                   LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	ChangeCharacterAddressGroup(sld, "Guadeloupe_Mines", "reload", "reload2");
                 }
}

void No_StartSagitta(string qName)
{
          CloseQuestHeader("Delivery");
          DoQuestFunctionDelay("No_StartSagitta_1", 4.0);
}

void No_StartSagitta_1(string qName)
{
          PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
}

void No_Baltram(string qName)
{
          CloseQuestHeader("Delivery");
          DoQuestFunctionDelay("No_Baltram_1", 4.0);
}

void No_Baltram_1(string qName)
{
          PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
}

void GothicDelivery()
{
	ref chr = GetCharacter(NPC_GenerateCharacter("Baltram", "trader_16", "man", "man", 1, ENGLAND, -1, true, "quest"));
	chr.name = "Бальтрам";
	chr.lastname = "";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	chr.Dialog.CurrentNode = "1";
	chr.greeting = "Gr_QuestMan";	
	LAi_SetOwnerType(chr);
	LAi_SetImmortal(chr, true);
	ChangeCharacterAddressGroup(chr, "HouseBaltram", "goto", "goto3");
}

void Gothic_Akil()
{		
	ref chr = GetCharacter(NPC_GenerateCharacter("Akil", "trader_14", "man", "man", 1, FRANCE, -1, true, "quest"));
	chr.name = "Акил";
	chr.lastname = "";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Akil.c";
	chr.Dialog.CurrentNode = "1_1";
	chr.greeting = "";
	chr.nonTable = true;
	LAi_SetOwnerType(chr);
	LAi_SetImmortal(chr, true);	
	ChangeCharacterAddressGroup(chr, "Martinique_Dunes_Jungle", "goto", "locator8");	
}

void GothicDelivery_Baltram(string qName)//уходим
{
                   sld = characterFromId("Akil");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 3.0);
                   DoQuestFunctionDelay("GothicAkil", 4.0);
}

void GothicAkil()
{
                   sld = characterFromId("Akil");
	sld.location = "Martinique_jungle_house";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetSitType(sld);

	chr = characterFromId("Baltram");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	chr.dialog.currentnode = "1_24";
	LAi_SetCitizenType(chr);
	LAi_ActorDialog(chr, pchar, "", -1, 0);
}

void GothicDelivery_taimer()
{
	SetTimerFunction("GothicDelivery_taimer_End", 0, 0, 3);
                   sld = characterFromId("Akil");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 4.0);
}

void GothicDelivery_taimer_End()
{
	chr = characterFromId("Baltram");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	chr.dialog.currentnode = "2_1";
	LAi_SetCitizenType(chr);
	LAi_ActorDialog(chr, pchar, "", -1, 0);
}

void GothicDeliveryCancel()
{
	PChar.UneasyDelivery.Cancel = true;
	AddQuestRecord("Delivery", "3");
	CloseQuestHeader("Delivery");	
	Characters[GetCharacterIndex("Baltram")].LifeDay = 0;
}

void GothicDeliverySilk()//погрузка шелка
{
	SetLaunchFrameFormParam("Прошел час"+ NewStr() +"Шелк погружен на ваш корабль", "", 0, 5);
	LaunchFrameForm();
	WaitDate("", 0, 0, 0, 1, 10); //крутим время
	RecalculateJumpTable();
	DoQuestFunctionDelay("GothicDeliveryBye", 5.5);
}

void GothicDeliveryBye(string qName)//уходим
{
	chr = characterFromId("Baltram");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	chr.dialog.currentnode = "2_4";
	RemoveCharacterGoods(chr, GOOD_SHIPSILK, 50);
	SetCharacterGoods(pchar, GOOD_SHIPSILK, 50);
	LAi_SetActorType(chr);
	LAi_ActorDialog(chr, pchar, "", 1.0, -1);
}

void GothicDeliveryAgree()
{
	TakeNItems(PChar, "BaltramNotice_0", 1);
	PChar.Gothic_Delivery = "2";
	AddQuestRecord("Delivery", "4");

	chr = characterFromId("Baltram");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	chr.dialog.currentnode = "First time";
	LAi_SetCitizenType(chr);
	LAi_ActorDialog(chr, pchar, "", -1, 0);	
	
	ref chr = GetCharacter(NPC_GenerateCharacter("Akil", "trader_14", "man", "man", 1, FRANCE, -1, true, "quest"));
	chr.name = "Акил";
	chr.lastname = "";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Akil.c";
	chr.Dialog.CurrentNode = "1";
	chr.greeting = "Gr_QuestMan";
	chr.nonTable = true;
	LAi_SetOwnerType(chr);
	LAi_SetImmortal(chr, true);
	
	ChangeCharacterAddressGroup(chr, "HouseAkil", "barmen", "stay");	
}
void GothicDeliveryTimer()
{
	PChar.Gothic_Delivery = "3";
	AddQuestRecord("Delivery", "5");
	
	SetTimerFunction("GothicDeliveryTimerEnd", 0, 0, 5);
}
void GothicDeliveryTimerEnd(string qName)
{
	PChar.GothicDelivery = "4";

	PChar.quest.GothicDeliveryDialogWithPrenol.win_condition.l1 = "location";
	PChar.quest.GothicDeliveryDialogWithPrenol.win_condition.l1.location = "HouseAkil";
	PChar.quest.GothicDeliveryDialogWithPrenol.function = "GothicDeliveryDialogWithAkil";
}

void GothicDeliveryDialogWithAkil(string qName)
{
	chrDisableReloadToLocation = true;
	
	ref chr = CharacterFromID("Akil");
	chr.Dialog.CurrentNode = "10";
	
	ChangeCharacterAddressGroup(chr, "HouseAkil", "goto", "goto4");
	ChangeCharacterAddressGroup(PChar, "HouseAkil", "goto", "goto1");
	chr.DialogCharacter2Character(PChar, chr, 1.0, true);

                   int Rank = sti(pchar.rank) - 5 + MOD_SKILL_ENEMY_RATE;
	chr = GetCharacter(NPC_GenerateCharacter("Akil Killer 1", "citiz_2", "man", "man", Rank, PIRATE, 0, true, "quest"));
	ChangeCharacterAddressGroup(chr, "HouseAkil", "reload", "reload2");
	chr.FoodToCharacter(chr, 5, 30);
	LAi_SetStayType(chr);
	
	chr = GetCharacter(NPC_GenerateCharacter("Akil Killer 2", "citiz_3", "man", "man", Rank, PIRATE, 0, true, "quest"));
	ChangeCharacterAddressGroup(chr, "HouseAkil", "reload", "reload2");
	chr.FoodToCharacter(chr, 5, 30);
	LAi_SetStayType(chr);
	
	chr = GetCharacter(NPC_GenerateCharacter("Akil Killer 3", "citiz_8", "man", "man", Rank, PIRATE, 0, true, "quest"));
	ChangeCharacterAddressGroup(chr, "HouseAkil", "reload", "reload2");
	chr.FoodToCharacter(chr, 5, 30);
	LAi_SetStayType(chr);
}

void GothicDeliveryAkilExit()
{
	LAi_SetActorType(CharacterFromID("Akil"));
	LAi_ActorRunToLocation(CharacterFromID("Akil"), "reload", "reload1", "none", "", "", "", -1);
	
	DoQuestFunctionDelay("GothicDeliveryBattleWithPirates", 3.0);
}

void GothicDeliveryBattleWithPirates(string _tmp)
{
	LAi_SetPlayerType(PChar);
	
	LAi_SetWarriorType(CharacterFromID("Akil Killer 1"));
	LAi_SetWarriorType(CharacterFromID("Akil Killer 2"));
	LAi_SetWarriorType(CharacterFromID("Akil Killer 3"));
	
	LAi_group_MoveCharacter(CharacterFromID("Akil Killer 1"), "EnemyFight");
	LAi_group_MoveCharacter(CharacterFromID("Akil Killer 2"), "EnemyFight");
	LAi_group_MoveCharacter(CharacterFromID("Akil Killer 3"), "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l1.character = "Akil Killer 1";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l2 = "NPC_Death";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l2.character = "Akil Killer 2";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l3 = "NPC_Death";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.win_condition.l3.character = "Akil Killer 3";
	PChar.quest.GothicDeliveryBattleWithPiratesWinner.function = "GothicDeliveryBattleWithPiratesWinner";
}

void GothicDeliveryBattleWithPiratesWinner(string qName)
{
	chrDisableReloadToLocation = false;
	
	AddQuestRecord("Delivery", "6");
	PChar.Gothic_Delivery = "6";
	
	FreeSitLocator("PortPax_church", "sit10");
	LAi_SetSitType(CharacterFromID("Akil"));
	ChangeCharacterAddressGroup(CharacterFromID("Akil"), "PortPax_church", "sit", "sit10");

	Characters[GetCharacterIndex("Akil")].Dialog.CurrentNode = "11";
}

void GothicDeliveryAkilBackToHouse()
{
	ChangeCharacterAddressGroup(CharacterFromID("Akil"), "PortPax_church", "barmen", "bar2");
	LAi_SetActorType(CharacterFromID("Akil"));
	LAi_ActorGoToLocation(CharacterFromID("Akil"), "reload", "reload1", "none", "", "", "", -1);
		
	AddQuestRecord("Delivery", "7");
	PChar.Gothic_Delivery = "7";	
	DoQuestFunctionDelay("GothicDeliveryLuteroNeedKill", 20.0);
}

void GothicDeliveryLuteroNeedKill(string qName)
{
	LAi_SetOwnerType(CharacterFromID("Akil"));
	ChangeCharacterAddressGroup(CharacterFromID("Akil"), "HouseAkil", "barmen", "stay");
	
	ref chr  = GetCharacter(NPC_GenerateCharacter("Lutero", "trader_9", "man", "man", 1, ENGLAND, -1, true, "quest"));
	chr.name = "Лютеро";
	chr.lastname = "";
	chr.greeting = "Gr_QuestMan";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Lutero.c";
	chr.Dialog.CurrentNode = "First Time";
	LAi_SetSitType(chr);
	LAi_SetImmortal(chr, true);
	
	FreeSitLocator("Fishing_Settlement_tavern", "sit6");
	ChangeCharacterAddressGroup(chr, "Fishing_Settlement_tavern", "sit", "sit6");
}

void GothicDeliveryAntiguaDialogExit()
{	
	PChar.Gothic_Delivery = "7";
	ref chr = CharacterFromID("Lutero");
	chr.Dialog.CurrentNode = "1";
}

void GothicDeliveryLuteroFirstSitDialog()
{
                   ref chr = CharacterFromID("Lutero");
	chr.Dialog.CurrentNode = "3";
	
	FreeSitLocator("Fishing_Settlement_tavern", "sit5");
	ChangeCharacterAddressGroup(PChar, "Fishing_Settlement_tavern", "sit", "sit5");
	LAi_SetSitType(PChar);
	LAi_SetActorType(chr);
	LAi_ActorSetSitMode(chr);
	LAi_ActorDialogNow(chr, PChar, "", -1);
}

void GothicDeliveryLuteroDialogExit()
{
	PChar.Gothic_Delivery = "8";	
	ChangeCharacterAddressGroup(PChar, "Fishing_Settlement_tavern", "goto", "goto1");
	LAi_SetActorType(PChar);
	LAi_SetPlayerType(PChar);	
	LAi_SetSitType(CharacterFromID("Lutero"));

	AddQuestRecord("Delivery", "8");	
	ChangeCharacterAddress(CharacterFromID("Akil"), "None", "");
                   pchar.GenQuestBox.HouseAkil.box1.items.BaltramNotice = 1;	
}



void Gothic_ReadBaltramNotice() // нашли письмо
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadBaltramNotice_1", 3.5);
}

void Gothic_ReadBaltramNotice_1() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadBaltramNotice_2", 3.5);
}
void Gothic_ReadBaltramNotice_2() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("BaltramNotice", "1");
	DoQuestFunctionDelay("Gothic_ReadBaltramNotice_3", 7.5);
}

void Gothic_ReadBaltramNotice_3() //
{
	AddQuestRecord("Delivery", "9");
	DoQuestFunctionDelay("GothicDeliveryFindNotice", 10.5);
}

void GothicDeliveryFindNotice(string qName)
{
	PChar.Gothic_Delivery = "9";
		
	PChar.quest.GothicDeliveryPiratesKillTillman2.win_condition.l1 = "location";
	PChar.quest.GothicDeliveryPiratesKillTillman2.win_condition.l1.location = "HouseBaltram";
	PChar.quest.GothicDeliveryPiratesKillTillman2.function = "GothicDeliveryPiratesKillBaltram2";

}

void GothicDeliveryPiratesKillBaltram2(string qName)
{
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_HELP.wav");
	LAi_SetActorType(PChar);
	chr=characterFromID("Baltram");
                   LAi_SetActorType(chr);
	DoQuestFunctionDelay("GothicDeliveryPiratesKillBaltram", 0.1);
}

void GothicDeliveryPiratesKillBaltram(string _tmp)
{
	float x, y, z;
	GetCharacterPos(PChar, &x, &y, &z);
	y += 1.5;
	z += 8.0;
	x -= 1;
	locCameraToPos(x, y, z, false);
	
	StartQuestMovie(true, true, true);
	InterfaceStates.Buttons.Save.enable = false;	
	chrDisableReloadToLocation = true;
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_KILLENEMY.wav");

	ref chr;
	int iRank = 25+MOD_SKILL_ENEMY_RATE;
	int iScl = 60;

	for(int i=1; i<=3; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("Baltram Killer "+i, "citiz_"+(46+i), "man", "man", iRank, PIRATE, 0, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank, iScl, iScl, RandPhraseSimple("blade_06","blade_10"), "pistol1", "bullet", iScl*2);
		ChangeCharacterAddressGroup(chr, "HouseBaltram", "goto", "goto" + i);
		chr.FoodToCharacter(chr, 5, 30);
		LAi_SetActorType(chr);
		LAi_ActorAttack(chr, CharacterFromID("Baltram"), "");
		
		if(i == 1)
		{
			chr.SaveItemsForDead   = true;
			TakeNItems(chr, "AkilKillersNotice", 1);
		}
	}
	LAi_SetHP(CharacterFromID("Baltram"), 70.0, 70.0);
	LAi_SetImmortal(CharacterFromID("Baltram"), false);
	LAi_ActorAfraid(CharacterFromID("Baltram"), CharacterFromID("Baltram Killer 1"), true);

	DoQuestFunctionDelay("GothicDeliveryPiratesKillBaltram_1", 2.0);	
}

void GothicDeliveryPiratesKillBaltram_1(string qName)
{
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_DEAD.wav");
	chr=characterFromID("Baltram");
	SetCharacterTask_Dead(chr);
	DoQuestFunctionDelay("GothicDeliveryBaltramDead", 1.0);
}

void GothicDeliveryBaltramDead(string qName)
{
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_STUPIDBEASTKILLED.wav");
	InterfaceStates.Buttons.Save.enable = true;
	EndQuestMovie();
	
	LAi_Fade("", "");
	locCameraFollow();

	LAi_SetPlayerType(PChar);
	
	ref chr;
	for(int i=1; i<=3; i++)
	{
		chr = CharacterFromID("Baltram Killer " + i);
		 LAi_SetWarriorType(chr);
		 LAi_group_MoveCharacter(chr, "EnemyFight");
		
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l1.character = "Baltram Killer 1";
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l2 = "NPC_Death";
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l2.character = "Baltram Killer 2";
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l3 = "NPC_Death";
	PChar.quest.GothicDeliveryBaltramKillersDead.win_condition.l3.character = "Baltram Killer 3";
	PChar.quest.GothicDeliveryBaltramKillersDead.function = "GothicDeliveryBaltramKillersDead";

	DoQuestFunctionDelay("GothicDeliveryOfficers", 15.0);
}

void GothicDeliveryOfficers(string qName)
{
	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "HouseBaltram", "reload", "reload1");

	}
}

void GothicDeliveryBaltramKillersDead(string qName)
{
	PlayStereoSound("new_round");
	Log_Info("Необходимо всё тщательно обыскать.");
	
	PChar.quest.GothicDeliveryFindAkilKillersNotice.win_condition.l1 = "item";
	PChar.quest.GothicDeliveryFindAkilKillersNotice.win_condition.l1.item = "AkilKillersNotice";
	PChar.quest.GothicDeliveryFindAkilKillersNotice.function = "GothicDeliveryFindAkilKillersNotice";
	
}

void GothicDeliveryFindAkilKillersNotice(string qName)
{
	chrDisableReloadToLocation = false;	
	PChar.Gothic_Delivery = "10";
	Characters[GetCharacterIndex("Baltram")].LifeDay = 0;	
}




void Gothic_ReadAkilKillersNotice() // нашли письмо
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadAkilKillersNotice_1", 3.5);
}

void Gothic_ReadAkilKillersNotice_1() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadAkilKillersNotice_2", 3.5);
}
void Gothic_ReadAkilKillersNotice_2() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("AkilKillersNotice", "1");
	DoQuestFunctionDelay("Gothic_ReadAkilKillersNotice_3", 7.5);
}



void Gothic_ReadAkilKillersNotice_3() //
{
	AddQuestRecord("Delivery", "10");
}
void GothicDeliveryLuteroReadNotice()
{
	AddQuestRecord("Delivery", "11");
	PChar.Gothic_Delivery = "11";
	
	ref chr = GetCharacter(NPC_GenerateCharacter("Charly Grand Pipiska", "mush_cnb_2", "man", "mushketer", 1, PIRATE, -1, true, "quest"));	
	chr.name = "Чарли";
	chr.lastname = "Большая Пиписка";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Charly Grand Pipiska.c";
	chr.Dialog.CurrentNode = "1";
	chr.greeting = "Gr_PearlIndian";
	SetFantomParamFromRank(chr, 10, true);
	GiveItem2Character(chr, "unarmed");
	chr.equip.blade = "unarmed";
	GiveItem2Character(chr, "mushket1");
	EquipCharacterbyItem(chr, "mushket1");
	chr.MushketType = "mushket1";
	chr.MushketBulletType = "bullet";
	TakeNItems(chr, "bullet", 50);
	AddItems(chr, "gunpowder", 50);
	TakeNItems(chr, "potion1", 5);
	LAi_SetCharacterUseBullet(chr, "bullet");
	LAi_SetHP(chr, 150, 150);
	SetSelfSkill(chr, 10, 10, 10, 100, 50);
	SetCharacterPerk(chr, "Gunman");
	SetCharacterPerk(chr, "BasicDefense");
	chr.MusketerDistance = 20;
	chr.SuperShooter = true;
	LAi_SetImmortal(chr, true);
	LAi_SetCitizenType(chr);
	ChangeCharacterAddressGroup(chr, "Dominica_Jungle_02", "goto", "goto12");	
}

void GothicDeliveryDialogWithCharlyFailed()
{
	LAi_SetActorType(CharacterFromID("Charly Grand Pipiska"));
	LAi_ActorRunToLocation(CharacterFromID("Charly Grand Pipiska"), "reload", "reload1_back", "none", "", "", "", -1);
	
	Characters[GetCharacterIndex("Lutero")].LifeDay = 0;
	Characters[GetCharacterIndex("Charly Grand Pipiska")].LifeDay = 0;
	
	PChar.Delivery = "END";
	AddQuestRecord("Delivery", "12");
	CloseQuestHeader("Delivery");
		
	PChar.quest.GothicDeliveryPearlOpen.win_condition.l1 = "ExitFromLocation";
	PChar.quest.GothicDeliveryPearlOpen.win_condition.l1.location = PChar.location;
	PChar.quest.GothicDeliveryPearlOpen.function = "GothicDeliveryPearlOpen";
}

void GothicDeliveryDialogWithCharlyGood()
{
	PChar.Gothic_Delivery = "12";
	AddQuestRecord("Delivery", "13");
                  chr = CharacterFromID("Charly Grand Pipiska");
                  LAi_CharacterDisableDialog(chr);
                  LAi_SetActorType(chr);
                  LAi_ActorGoToLocation(chr, "reload", "reload1_back", "none", "", "", "", 30.0);

	DoQuestFunctionDelay("GothicDeliveryDialogBobMcCain", 1.5);
}

void GothicDeliveryDialogBobMcCain()
{	
	ref chr = GetCharacter(NPC_GenerateCharacter("Bob McCain", "pirate_7", "man", "man", 1, PIRATE, -1, true, "quest"));
	chr.name = "Боб";
	chr.lastname = "Маккейн";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Bob McCain.c";
	chr.Dialog.CurrentNode = "First Time";
	chr.greeting = "Gr_Tavern_Mate_1";
	LAi_SetSitType(chr);
	LAi_SetImmortal(chr, true);
	FreeSitLocator("Pirates_tavern", "sit_base1");
	
	ChangeCharacterAddressGroup(chr, "Pirates_tavern", "sit", "sit_base1");
	
	PChar.quest.GothicDeliveryPearlOpen.win_condition.l1 = "ExitFromLocation";
	PChar.quest.GothicDeliveryPearlOpen.win_condition.l1.location = PChar.location;
	PChar.quest.GothicDeliveryPearlOpen.function = "GothicDeliveryPearlOpen";
}

void GothicDeliveryDialogWithBermudesBarmen()
{
	PChar.Gothic_Delivery = "13";
	ref chr = CharacterFromID("Bob McCain");
	chr.Dialog.CurrentNode = "1";
}

void GothicDeliveryDialogWithMcCain()
{	
	ref chr = CharacterFromID("Bob McCain");
	chr.Dialog.CurrentNode = "4";

	FreeSitLocator("Pirates_tavern", "sit_front1");
	ChangeCharacterAddressGroup(PChar, "Pirates_tavern", "sit", "sit_front1");
	LAi_SetSitType(PChar);
	LAi_SetActorType(chr);
	LAi_ActorSetSitMode(chr);
	LAi_ActorDialogNow(chr, PChar, "", -1);
}

void GothicDeliveryDialogWithMcCainEnd()
{
	AddQuestRecord("Delivery", "14");
	PChar.Gothic_Delivery = "14";

	ChangeCharacterAddressGroup(PChar, "Pirates_tavern", "goto", "goto2");
	LAi_SetPlayerType(PChar);
	LAi_SetSitType(CharacterFromID("Bob McCain"));
	LAi_LocationDisableOfficersGen("Shore3", true); //офицеров не пускать	
	Characters[GetCharacterIndex("Bob McCain")].LifeDay = 0;
		
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l1 = "Hour";
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l1.start.hour = 0;
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l1.finish.hour = 23;
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l2 = "locator";
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l2.location = "Pirates_town";
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l2.locator_group = "reload";
	pchar.quest.GothicDeliveryInBermudesShore2.win_condition.l2.locator = "reload1_back";
	pchar.quest.GothicDeliveryInBermudesShore2.function = "GothicDeliveryInBermudesShore2";
}

void GothicDeliveryInBermudesShore2(string qName)
{
	PChar.quest.GothicDeliveryInBermudesShore3.win_condition.l1 = "location";
	PChar.quest.GothicDeliveryInBermudesShore3.win_condition.l1.location = "Shore3";
	PChar.quest.GothicDeliveryInBermudesShore3.function = "GothicDeliveryInBermudesShore3";
}

void GothicDeliveryInBermudesShore3(string qName)
{
                   LAi_SetActorType(pchar);
                   LAi_ActorGoToLocator(pchar, "goto", "goto3", "", -1);
	DoQuestFunctionDelay("GothicDeliveryInBermudesShore", 5.0);

	LAi_SetActorType(CharacterFromID("Akil"));
	ChangeCharacterAddressGroup(CharacterFromID("Akil"), "Shore3", "goto", "goto13");
	
	ref chr2;
	int Rank = Rank(PChar, MOD_SKILL_ENEMY_RATE);
	chr2 = GetCharacter(NPC_GenerateCharacter("Alvares", "GothicN_2", "man", "man", Rank, PIRATE, 0, true, "quest"));
	chr2.name = "Алварес";
	chr2.lastname = "";
	chr2.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
	chr2.Dialog.CurrentNode = "1";
	chr2.greeting = "Gr_ArenaMember";
	chr2.QuestDuelEquipCharacterSkills(chr2, true);
	LAi_NPC_Equip(chr2, sti(chr.rank), true, true);
                   LAi_SetWarriorType(chr2);
	LAi_SetStayType(chr2);
	chr2.rank = 30;
	LAi_SetHP(chr2, 550, 550); 
	SetSelfSkill(chr2, 95, 50, 50, 90, 50);
	SetShipSkill(chr2, 90, 25, 5, 5, 5, 5, 5, 15, 30);
	SetSPECIAL(chr2, 6, 6, 8, 3, 9, 10, 4);
	SetCharacterPerk(chr2, "CriticalHit");
	chr2.SuperShooter  = true;
	chr2.SaveItemsForDead   = true;// сохранять на трупе вещи
	chr2.DontClearDead = true;
	SetCharacterPerk(chr2, "Energaiser");
	SetCharacterPerk(chr2, "BasicDefense");
	SetCharacterPerk(chr2, "ProfessionalDefense");
	SetCharacterPerk(chr2, "AdvancedDefense");
	SetCharacterPerk(chr2, "CriticalHit");
	SetCharacterPerk(chr2, "Tireless");
	SetCharacterPerk(chr2, "HardHitter");
	SetCharacterPerk(chr2, "Sliding");
	SetCharacterPerk(chr2, "BladeDancer");
	SetCharacterPerk(chr2, "SwordplayProfessional");
	SetCharacterPerk(chr2, "Gunman");
	SetCharacterPerk(chr2, "GunProfessional");
	SetCharacterPerk(chr2, "Sniper");
	GiveItem2Character(chr2, "pistol1");
	GiveItem2Character(chr2, "blade40");
	chr2.equip.blade = "blade40";
	TakeNItems(chr2, "Mineral7", 1);
	TakeNItems(chr2, "Mineral10", 1);
	LAi_SetCharacterUseBullet(chr2, "bullet");
                   TakeNItems(chr2, "grapeshot", 27);
	TakeNItems(chr2, "bullet", 13);
	TakeNItems(chr2, "cartridge", 10);
	TakeNItems(chr2, "GunPowder", 14);
	TakeNItems(chr2, "mapAkil", 1);
                   LAi_SetActorType(chr2);
                   LAi_ActorTurnToLocator(chr2, "goto", "goto13");
	ChangeCharacterAddressGroup(chr2, "Shore3", "goto", "goto2");
	chr.FoodToCharacter(chr2, 5, 30);

	sld = GetCharacter(NPC_GenerateCharacter("Angardo", "GothicN_5", "man", "man", 1, PIRATE, 0, true, "quest"));
	sld.name = "Ангардо";
	sld.lastname = "";
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
	sld.Dialog.CurrentNode = "6";
	sld.rank = 32;
	LAi_SetHP(sld, 550, 550); 
	SetSelfSkill(sld, 95, 50, 50, 90, 50);
	SetShipSkill(sld, 90, 25, 5, 5, 5, 5, 5, 15, 30);
	SetSPECIAL(sld, 6, 6, 8, 3, 9, 10, 4);
	sld.SuperShooter  = true;
	sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	sld.DontClearDead = true;
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "Doctor1");
	GiveItem2Character(sld, "topor_09");
	sld.equip.blade = "topor_09";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	GiveItem2Character(sld, "cirass6");
	EquipCharacterbyItem(sld, "cirass6");
	LAi_SetCharacterUseBullet(sld, "bullet");
                   TakeNItems(sld, "bullet", 9);
	AddItems(sld, "gunpowder", 11);
	TakeNItems(sld, "potion2", 5);
                   LAi_SetActorType(sld);
                   LAi_ActorTurnToLocator(sld, "goto", "goto13");
	ChangeCharacterAddressGroup(sld, "Shore3", "goto", "goto12");

}

void GothicDeliveryInBermudesShore(string _tmp)
{
	chrDisableReloadToLocation = true;	
	DoQuestFunctionDelay("GothicDeliveryInBermudesShore_1", 1.0);

                   chr2 = CharacterFromID("Akil");
                   LAi_SetActorType(chr);
                   LAi_ActorTurnToLocator(chr, "goto", "goto2");
}

void GothicDeliveryInBermudesShore_1(string _tmp)
{
	chrDisableReloadToLocation = true;		
	ChangeCharacterAddressGroup(PChar, "Shore3", "goto", "goto3");		
	DoQuestFunctionDelay("GothicDeliveryDialogKillersWithAkil", 1.0);

                   chr2 = CharacterFromID("Akil");
                   LAi_SetActorType(chr);
                   LAi_ActorTurnToLocator(chr, "goto", "goto2");

                   sld = CharacterFromID("Angardo");
                   LAi_SetActorType(sld);
                   LAi_ActorTurnToLocator(sld, "goto", "goto13");

                   chr2 = CharacterFromID("Alvares");
                   LAi_SetActorType(chr2);
                   LAi_ActorTurnToLocator(chr2, "goto", "goto13");
}

void GothicDeliveryDialogKillersWithAkil(string _tmp)
{
                     LAi_SetActorType(pchar);
                     LAi_ActorTurnToLocator(pchar, "goto", "goto13");
                     LAi_ActorTurnToLocator(chr, "goto", "goto2");
	 SetDialogCharacter2Character(PChar, CharacterFromID("Alvares"), 0.001, true);
}

void GothicDeliveryDialogKillers_Akil()
{
	LAi_SetPlayerType(PChar);
                   chr = CharacterFromID("Akil");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Akil.c";
                   chr.dialog.currentnode = "12";
	LAi_SetActorType(chr);
	LAi_ActorTurnToCharacter(chr, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Akil"), 0.001, true);
}

void GothicDeliveryDialogKillers_Angardo()
{
                   sld = CharacterFromID("Angardo");
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
                   sld.dialog.currentnode = "6_1";
	LAi_SetActorType(sld);
                   LAi_ActorTurnToLocator(chr, "goto", "goto2");
	LAi_ActorTurnToCharacter(sld, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Angardo"), 0.001, true);
}

void GothicDeliveryDialogKillers_Alvares()
{
                   chr2 = CharacterFromID("Alvares");
	chr2.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
                   chr2.dialog.currentnode = "5_1";
	LAi_SetActorType(chr2);
                   LAi_ActorTurnToLocator(chr, "goto", "goto2");
	LAi_ActorTurnToCharacter(chr2, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Alvares"), 0.001, true);
}

void GothicDeliveryDialogKillers_Akil_1()
{
                   chr = CharacterFromID("Akil");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Akil.c";
                   chr.dialog.currentnode = "12_2";
	LAi_SetActorType(chr);
                   LAi_ActorTurnToLocator(sld, "goto", "goto13");
	LAi_ActorTurnToCharacter(chr, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Akil"), 0.001, true);
}

void GothicDeliveryDialogKillers_Angardo_1()
{
                   sld = CharacterFromID("Angardo");
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
                   sld.dialog.currentnode = "6_4";
	LAi_SetActorType(sld);
	LAi_ActorTurnToCharacter(sld, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Angardo"), 0.001, true);
}


void GothicDeliveryDialogKillers_Alvares_1()
{
                   chr2 = CharacterFromID("Alvares");
	chr2.Dialog.FileName = "Gothic_Quest\GothicLine\Akil Killer.c";
                   chr2.dialog.currentnode = "5_4";
	LAi_SetActorType(chr2);
                   LAi_ActorTurnToLocator(chr, "goto", "goto12");
	LAi_ActorTurnToCharacter(chr2, pchar);
	SetDialogCharacter2Character(PChar, CharacterFromID("Alvares"), 0.001, true);
}


void GothicDeliveryAkilKill()
{			
	LAi_SetHP(CharacterFromID("Akil"), 25.0, 25.0);
	LAi_SetImmortal(CharacterFromID("Akil"), false);
	
	LAi_SetActorType(CharacterFromID("Angardo"));
	LAi_ActorAttack(CharacterFromID("Angardo"), CharacterFromID("Akil"), "");
	
	LAi_SetStayType(CharacterFromID("Akil"));
	LAi_ActorAfraid(CharacterFromID("Akil"), CharacterFromID("Alvares"), false);
	
	PChar.quest.GothicDeliveryAkilDead.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicDeliveryAkilDead.win_condition.l1.character = "Akil";
	PChar.quest.GothicDeliveryAkilDead.function = "GothicDeliveryAkilDead";

                 DoQuestFunctionDelay("GothicDeliveryBattleAlvares", 0.1);
}

void GothicDeliveryAkilDead(string qName)
{
                 PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_DEAD.wav");
                 DoQuestFunctionDelay("GothicDeliveryBattleWithAkilKillers", 0.1);
}

void GothicDeliveryBattleAlvares(string qName)
{
	LAi_SetPlayerType(PChar);
	LAi_SetWarriorType(CharacterFromID("Alvares"));
	LAi_group_MoveCharacter(CharacterFromID("Alvares"), "EnemyFight");
}

void GothicDeliveryBattleWithAkilKillers()
{			
	LAi_SetWarriorType(CharacterFromID("Angardo"));
	LAi_group_MoveCharacter(CharacterFromID("Angardo"), "EnemyFight");
	
	LAi_SetPlayerType(PChar);
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	
	PChar.quest.GothicDeliveryBattleWithAkilKillersWinner.win_condition.l1 = "NPC_Death";
	        PChar.quest.GothicDeliveryBattleWithAkilKillersWinner.win_condition.l1.character = "Alvares";
	PChar.quest.GothicDeliveryBattleWithAkilKillersWinner.win_condition.l2 = "NPC_Death";
	                                            PChar.quest.GothicDeliveryBattleWithAkilKillersWinner.win_condition.l2.character = "Angardo";
	PChar.quest.GothicDeliveryBattleWithAkilKillersWinner.function = "GothicDeliveryBattleWithAkilKillersWinner";
}

void GothicDeliveryBattleWithAkilKillersWinner(string qName)
{
	LAi_LocationDisableOfficersGen("Shore3", false); //офицеров пускать
	LAi_SetPlayerType(PChar);
	Log_Info("Надобы обыскать трупы, найти карту Акила.");

	chr2 = characterFromId("Alvares");
	LAi_KillCharacter(chr2);
	pchar.quest.GothicDeliveryMoney.win_condition.l1 = "item";
	pchar.quest.GothicDeliveryMoney.win_condition.l1.item = "mapAkil";
	pchar.quest.GothicDeliveryMoney.function = "GothicDeliveryFindAkilMoney";
}

void GothicDeliveryFindAkilMoney()
{
	AddQuestRecord("Delivery", "15");
	chrDisableReloadToLocation = false;
                    //заполним сундучок.	
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.gold = 300000;		
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.gold_dublon = 427;		
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.icollection = 1;		
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.DestinyGiftPearl = 13;
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.totem_12 = 1;
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.blade49 = 1;
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.mineral19 = 100;
                    pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.tailor_tool = 1;
			pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.kaleuche_amulet1 = 1;
	 pchar.GenQuestBox.Hispaniola_Cave_2.box1.items.sculMa2 = 1;

	PChar.quest.GothicLine_Money.win_condition.l1 = "locator";
	PChar.quest.GothicLine_Money.win_condition.l1.location = "Hispaniola_Cave_2";
	PChar.quest.GothicLine_Money.win_condition.l1.locator_group = "goto";
	PChar.quest.GothicLine_Money.win_condition.l1.locator = "goto1";
	PChar.quest.GothicLine_Money.function = "GothicDeliveryMoney";
}

void GothicDeliveryMoney()
{
                 DoQuestFunctionDelay("GothicDeliveryMoney_1", 1.0);
}

void GothicDeliveryMoney_1()
{
                   PlaySound("VOICE\Russian\gotica\SFX\MYSTERIOUS_AMBIENCE.wav");
	TakeNItems(PChar, "mapAkil", -1);
	Log_Info("Сокровища Акилы где - то рядом.");

	pchar.quest.GothicMoney1.win_condition.l1 = "item";
	pchar.quest.GothicMoney1.win_condition.l1.item = "gold";
	pchar.quest.GothicMoney1.function = "GothicDeliveryMoney_2";

	pchar.quest.GothicMoney2.win_condition.l1 = "item";
	pchar.quest.GothicMoney2.win_condition.l1.item = "DestinyGiftPearl";
	pchar.quest.GothicMoney2.function = "GothicVaterskel_Shore";
}

void GothicDeliveryMoney_2()
{
	AddQuestRecord("Delivery", "16");
}

void GothicDeliveryLuteroCancelMoney()
{
	AddQuestRecord("Delivery", "17");
	CloseQuestHeader("Delivery");
	PChar.Gothic_Delivery = "END";

	ChangeCharacterComplexReputation(pchar,"nobility", -20);
                   sld = characterFromId("Lutero");
                   ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto2");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 4.0);
}

void GothicDeliveryLuteroYesMoney()
{
                    pchar.questTemp.GothicThekla = "SoupThekla";
	AddQuestRecord("Delivery", "18");
	CloseQuestHeader("Delivery");
	PChar.Gothic_Delivery = "END";

                   ChangeCharacterComplexReputation(pchar,"nobility", 10);
                   sld = characterFromId("Lutero");
                   ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto2");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload3", "none", "", "", "", 4.0);
                   DoQuestFunctionDelay("GothicLutero", 4.0);
}

void GothicLutero()
{
                   sld = characterFromId("Lutero");
	sld.City = "Marigo";
	sld.location = "Fishing_Settlement_Packhouse";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Gothic_Quest\GothicLine\Lutero_ItemTrader.c";
	sld.greeting = "Gr_LUTERO";
	LAi_SetHuberType(sld);
	sld.Merchant.type = "armourer";
	sld.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	sld.nation = PIRATE;
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Мистер и Миссис Смит" ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void Gothic_SagittaAnn(string qName)
{
	ref chr = GetCharacter(NPC_GenerateCharacter("AnnHooms", "Women_4", "woman", "woman", 1, ENGLAND, -1, true, "quest"));
	chr.name = "Энн";
	chr.lastname = "Хомс";
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_AnnHooms.c";
	chr.Dialog.CurrentNode = "First time";
	chr.greeting = "Gr_QuestMan";	
	LAi_SetOwnerType(chr);
	LAi_SetImmortal(chr, true);
                   LAi_ActorTurnToLocator(chr, "Officers", "reload2_2");
	ChangeCharacterAddressGroup(chr, "Guadeloupe_Mines", "Officers", "reload2_3");

                   sld = CharacterFromID("Sagitta");
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Sagitta.c";
	sld.dialog.currentnode   = "Smithy_SagittaAnn";
	LAi_SetActorType(sld);
	LAi_SetImmortal(sld, true);
                   LAi_ActorTurnToLocator(sld, "Officers", "reload2_3");
	ChangeCharacterAddressGroup(sld, "Guadeloupe_Mines", "Officers", "reload2_2");

	PChar.quest.Gothic_SagittaAnn_1.win_condition.l1 = "locator";
	PChar.quest.Gothic_SagittaAnn_1.win_condition.l1.location = "Guadeloupe_Mines";
	PChar.quest.Gothic_SagittaAnn_1.win_condition.l1.locator_group = "goto";
	PChar.quest.Gothic_SagittaAnn_1.win_condition.l1.locator = "goto8";
	PChar.quest.Gothic_SagittaAnn_1.function = "Gothic_SagittaAnn_1";
}

void Gothic_SagittaAnn_1(string qName)
{
                   LocatorReloadEnterDisable("Guadeloupe_Mines", "reload1_back", true);//закрыть

                   LAi_SetActorType(pchar);
                   LAi_ActorGoToLocator(pchar, "goto", "goto3", "", -1);

                   sld = CharacterFromID("Sagitta");
                   LAi_SetActorType(sld);
                   LAi_ActorTurnToLocator(sld, "Officers", "reload2_3");

                   chr = CharacterFromID("AnnHooms");
                   LAi_SetActorType(chr);
                   LAi_ActorTurnToLocator(chr, "Officers", "reload2_2");

	DoQuestFunctionDelay("Gothic_SagittaAnn_2", 10.0);
}

void Gothic_SagittaAnn_2(string qName)
{
                    sld = CharacterFromID("Sagitta");
                    LAi_SetActorType(sld);
                    LAi_ActorTurnToLocator(sld, "Officers", "reload2_3");
	 SetDialogCharacter2Character(PChar, CharacterFromID("Sagitta"), 0.001, true);
}

void Gothic_SagittaAnn_3(string qName)
{
 	LAi_SetPlayerType(PChar);

                   chr = CharacterFromID("AnnHooms");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_AnnHooms.c";
                  chr.dialog.currentnode = "First time";
	LAi_SetActorType(chr);
                  LAi_ActorDialog(chr, pchar, "", -1, 0);
}

void Gothic_SagittaAnn_4(string qName)
{
    	AddQuestRecord("Gothic_Smithy", "1");
	
                  chr = CharacterFromID("AnnHooms");
	LAi_SetActorType(chr);
                   LAi_ActorGoToLocation(chr, "reload", "reload1_back", "none", "", "", "Gothic_Ann_5", 15.0);

                   sld = CharacterFromID("Sagitta");
	 LAi_SetCitizenType(sld);
}

void Gothic_SagittaAnn_End(string qName)
{
 	LAi_SetPlayerType(PChar);
                   chr = CharacterFromID("AnnHooms");
	LAi_SetActorType(chr);
                   LAi_ActorGoToLocation(chr, "reload", "reload1_back", "none", "", "", "Gothic_Ann_5", 15.0);
}

void GothicSmithy_AnnHooms(string qName)
{
                   chr = CharacterFromID("AnnHooms");
	chr.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_AnnHooms.c";
                   chr.dialog.currentnode = "First_time";
	chr.City = "FortOrange";
	chr.location = "HaryHooms_upstairs";
	chr.location.group = "goto";
	chr.location.locator = "goto5";
	chr.nation = ENGLAND;
	LAi_SetWaitressType(chr);
	LAi_RemoveLoginTime(chr);
	LAi_group_MoveCharacter(chr, "ENGLAND_CITIZENS");
	LAi_SetImmortal(chr, true);
}

void Gothic_Smithy_Tavern(string qName)
{
   	AddQuestRecord("Gothic_Smithy", "2");
                  pchar.questTemp.GothicSmithy = "SmithyTavern";
	SetTimerFunction("GothicSmithy_AnnHooms", 0, 0, 30);
}

void Gothic_Smithy_Tavern_1(string qName)
{
                  LocatorReloadEnterDisable(pchar.location, "reload2",  false);

	sld = GetCharacter(NPC_GenerateCharacter("SmithyDavid", "huber_13", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "", "", "", );
	sld.sex = "man";
	sld.name 	= "Дэвид";
                   sld.lastname = "Смит";
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_David.c";
	sld.Dialog.CurrentNode = "First time";
	sld.nation = PIRATE;
	sld.greeting = "Gr_DAVID";
	sld.money = "70000";
	Lai_SetStayType(sld);
	LAi_RemoveLoginTime(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);
	sld.talker = 10;
	sld.SaveItemsForDead   = true;
	sld.DontClearDead = true;
          	ChangeCharacterAddressGroup(sld,"FortOrange_tavern_upstairs", "goto", "goto2");
}

void Gothic_Smithy_Tavern_2(string qName)
{
                  LocatorReloadEnterDisable(pchar.location, "reload2",  false);

	ref chr = GetCharacter(NPC_GenerateCharacter("SmithyAugusta", "Women_5", "woman", "woman", 1, ENGLAND, -1, true, "quest"));
	chr.name = "Августа";
	chr.lastname = "";
	chr.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
	chr.Dialog.CurrentNode = "Augusta";
	chr.greeting = "";
	chr.SaveItemsForDead   = true; // сохранять на трупе вещи
	chr.DontClearDead = true;  // не убирать труп через 200с
	GiveItem2Character(chr, "slave_02");
	EquipCharacterByItem(chr, "slave_02");
	LAi_SetWarriorType(chr);	
	LAi_SetActorTypeNoGroup(chr);
                   LAi_ActorDialog(chr, pchar, "", -1, 0);
	ChangeCharacterAddressGroup(chr, "Vestpunt_tavern_upstairs", "goto", "goto3");
}

void Gothic_Smithy_TavernAugusta(string qName)
{
                   LocatorReloadEnterDisable(pchar.location, "reload1_back",  true);

                   chr = CharacterFromID("SmithyAugusta");
        	LAi_SetHP(chr, 1.0, 1.0);
	LAi_SetWarriorType(chr);
	LAi_group_MoveCharacter(chr, "Smithy_Augusta_War");
	LAi_group_FightGroups("Smithy_Augusta_War", LAI_GROUP_PLAYER, true);

	Pchar.quest.Gothic_TavernAugusta_War.win_condition.l1 = "NPC_Death";
	Pchar.quest.Gothic_TavernAugusta_War.win_condition.l1.character = "SmithyAugusta";
	Pchar.quest.Gothic_TavernAugusta_War.function = "Gothic_TavernAugusta_Death";

}
void Gothic_TavernAugusta_Death(string qName)
{
                   sld = CharacterFromID("SmithyDavid");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
	DeleteAttribute(pchar, "quest.Smithy_DouwesenTavern");
	DoQuestCheckDelay("Gothic_SmithyAugustaDeath", 1.1);
}


void Gothic_Smithy_Tavern_4(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("Senyan", "Senyan", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "blade50", "pistol11", "bullet", 10); 
          	sld.name      = "Сеньян";
          	sld.lastname      = "";
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
          	ChangeCharacterAddressGroup(sld,"FortOrange_tavern", "reload", "reload1_back");
                  DoQuestFunctionDelay("Gothic_Smithy_Tavern_5", 0.2);
}

void Gothic_Smithy_Tavern_5(string qName)
{
                  sld = CharacterFromID("Senyan");
        	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
	sld.Dialog.CurrentNode = "Senyan";
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_Smithy_Senyan(string qName)
{
                   bDisableFastReload = true;//закрыть переход
                   LocatorReloadEnterDisable("FortOrange_town", "reload2", true);//закрыть выход в джунгли

   	AddQuestRecord("Gothic_Smithy", "7");
                   sld = CharacterFromID("Senyan");
	LAi_SetActorType(sld);
                     LAi_ActorGoToLocation(sld, "reload", "reload2_back", "none", "", "", "", -1);

	PChar.quest.Gothic_Smithy_pirat.win_condition.l1 = "locator";
	PChar.quest.Gothic_Smithy_pirat.win_condition.l1.location = "FortOrange_port";
	PChar.quest.Gothic_Smithy_pirat.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_Smithy_pirat.win_condition.l1.locator = "reload2_back";
	PChar.quest.Gothic_Smithy_pirat.function = "Gothic_Smithy_pirat";
}

void Gothic_Smithy_pirat(string qName)
{
                                      LocatorReloadEnterDisable("FortOrange_port", "reload1_back", true);
                                      LocatorReloadEnterDisable("FortOrange_port", "reload2_back", true);

                                      // генерим тела на пирсе
	                   sld = GetCharacter(NPC_GenerateCharacter("SmithyPirat", "mercen_16", "man", "man", 20, PIRATE, 1, false, "quest"));
	                   FantomMakeCoolFighter(sld, 80, 80, 90, "blade_19", "pistol6", "bullet", 10);
	                   sld.name 	= "Пройдоха";
	                   sld.lastname = "Вилли";
          		sld.greeting = ""; 
	                   LAi_SetActorType(sld);
                                      LAi_ActorDialog(sld, pchar, "", -1, 0);
                                        ChangeCharacterAddressGroup(sld, "FortOrange_port", "officers", "reload1_1");

	// пираты 3шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
		sld2 = GetCharacter(NPC_GenerateCharacter("SmithyPirat_"+i, "citiz_"+(40+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		sld2.monster = true; 
	                   LAi_SetImmortal(sld2, true);
		LAi_SetWarriorType(sld2);
		LAi_SetImmortal(sld2, true);//защита от дурака
		ChangeCharacterAddressGroup(sld2, "FortOrange_port", "officers", "reload1_2");
		LAi_CharacterDisableDialog(sld2);//запрет диалога
		LAi_SetActorType(sld2);
		LAi_ActorFollow(sld2, sld, "", -1);
	}
                  DoQuestFunctionDelay("Gothic_Smithy_pirat_1", 2.0);	
}

void Gothic_Smithy_pirat_1()
{
                  sld = CharacterFromID("SmithyPirat");
                  sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                  sld.Dialog.CurrentNode = "Pirat";
                  LAi_SetActorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_Smithy_piratFight(string qName)
{
                   LAi_SetPlayerType(pchar);
                   sld = CharacterFromID("SmithyPirat");
	LAi_SetWarriorType(sld);
                   LAi_group_MoveCharacter(sld, "EnemyFight");
	// пираты 3шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=3; i++)
	{
	sld2 = GetCharacter(NPC_GenerateCharacter("SmithyPirat_"+i, "citiz_"+(40+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
	LAi_SetWarriorType(sld2);
                   LAi_group_MoveCharacter(sld2, "EnemyFight");
	LAi_SetImmortal(sld2, false);//защита от дурака
                   ChangeCharacterAddressGroup(sld2, pchar.location, "",  "");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "OpenTheDoors_SmithyPiratDeath");
                    }
}


void Gothic_Smithy_pirat_house(string qName)
{
                 LocatorReloadEnterDisable("LeFransua_town", "reload8_back", false);
                 LocatorReloadEnterDisable("LeFransua_bank", "reload2", true);
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral2 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral6 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.CarrolNotice = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.gold_dublon = 72;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral14 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral17 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral19 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral21 = 1;
                 pchar.GenQuestBox.LeFransua_Bank_residence.box1.items.mineral26 = 1;

	PChar.quest.Gothic_Smithy_pirat_house_1.win_condition.l1 = "locator";
	PChar.quest.Gothic_Smithy_pirat_house_1.win_condition.l1.location = "LeFransua_bank";
	PChar.quest.Gothic_Smithy_pirat_house_1.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_Smithy_pirat_house_1.win_condition.l1.locator = "reload2";
	PChar.quest.Gothic_Smithy_pirat_house_1.function = "Gothic_Smithy_pirat_house_1";
}


void Gothic_Smithy_pirat_house_1(string qName)
{

                  LocatorReloadEnterDisable("LeFransua_bank", "reload1_back", true);
 	PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1014_BANDIT_KILLER_06_00.wav");
	int iRank = 22+MOD_SKILL_ENEMY_RATE*2;
	int iScl = 70;
	LAi_group_Register("Mine_enemy");
	LAi_group_SetLookRadius("Mine_enemy", 20);
	LAi_group_SetHearRadius("Mine_enemy", 15);		
	LAi_group_SetHearRadius(LAI_GROUP_PLAYER, 5);
	for (i=1; i<=5; i++) // бандюки
	{
		sld = GetCharacter(NPC_GenerateCharacter("Mine_Bandos_mines_"+i, "citiz_"+(rand(9)+51), "man", "man", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld, iRank, iScl, iScl, "blade_10", "pistol1", "bullet", iScl*2+50);
		ChangeCharacterAddressGroup(sld, "LeFransua_bank", "reload", "reload1");
	LAi_SetWarriorType(sld);
	LAi_warrior_SetStay(sld, true);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "OpenTheDoors_SmithyPiratBankDeath");
	}	
}


void Gothic_ReadCarrolNotice() // нашли письмо
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadCarrolNotice_1", 3.5);
}

void Gothic_ReadCarrolNotice_1() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadCarrolNotice_2", 2.5);
}
void Gothic_ReadCarrolNotice_2() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("CarrolNotice", "1");
	DoQuestFunctionDelay("Gothic_ReadCarrolNotice_3", 4.5);
}

void Gothic_LeFransuaTavern_2() //
{
          AddQuestRecord("Gothic_Smithy", "010");
}

void Gothic_ReadCarrolNotice_3() //
{
                   LocatorReloadEnterDisable("LeFransua_bank", "reload1_back", false);
	pchar.questTemp.GothicSmithy = "Smithy_LeFransuaTavern_Sec2";
	AddQuestRecord("Gothic_Smithy", "10");
	DoQuestFunctionDelay("Gothic_Smithy_FindNotice", 5.5);

	// устанавливаем фрегат Черный Ворон
	sld = GetCharacter(NPC_GenerateCharacter("Terri", "mercen_28", "man", "man", 20, PIRATE, 5, true, "soldier"));	
	FantomMakeCoolFighter(sld, 20, 80, 70, "blade_21", "pistol2", "bullet", 20);
	FantomMakeCoolSailor(sld, SHIP_SURPRISE, "Черный Ворон", CANNON_TYPE_CULVERINE_LBS18, 70, 70, 70);
	sld.name = "Терри";
	sld.lastname = "Коттамди";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld.DontRansackCaptain = true;
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "MusketsShoot");

	LAi_group_MoveCharacter(sld, "EnemyFight");		
	Group_AddCharacter("Terri_Group", "Terri");
	Group_SetType("Terri_Group", "pirate");
	Group_SetGroupCommander("Terri_Group", "Terri");
	Group_SetAddress("Terri_Group", "Martinique", "Quest_Ships", "Quest_Ship_10");
	Group_SetTaskAttack("Terri_Group", PLAYER_GROUP);

	pchar.quest.Gothic_Smithy_Martinique.win_condition.l1 = "location";
	pchar.quest.Gothic_Smithy_Martinique.win_condition.l1.location = "Martinique";
	pchar.quest.Gothic_Smithy_Martinique.function = "Gothic_Smithy_Martinique";
}

void Gothic_Smithy_Martinique(string qName) // устанавливаем фрегат Тристан
{
	Island_SetReloadEnableGlobal("Martinique", false);//закрыть остров
	bQuestDisableMapEnter = true;//на карту тоже
	pchar.nation = PIRATE; // принудительно

	for (int i=0;i<MAX_ISLANDS;i++)
	{				
		if (Islands[i].id == "Martinique")
		{
			Islands[i].alwaysStorm = true; 
			Islands[i].storm = true;
		}
	}

	int iRank = 20+MOD_SKILL_ENEMY_RATE;
	int iScl = 55;
	Group_FindOrCreateGroup("Umberto_Group");
	Group_SetType("Umberto_Group", "pirate");//тип группы
	SetCaptanModelByEncType(sld1, "war");
	// устанавливаем корвет Тристан
	sld1 = GetCharacter(NPC_GenerateCharacter("Umberto", "mercen_26", "man", "man", iRank, PIRATE, -1, true, "quest")); // patch
	FantomMakeSmallSailor(sld1, SHIP_FRIGATE_H, "Тристан", CANNON_TYPE_CULVERINE_LBS18, iScl, iScl, iScl, iScl, iScl);
	FantomMakeCoolFighter(sld1, iRank, iScl, iScl, "blade_13", "pistol5", "bullet", iScl*2);
	sld1.name = "Умберто";
	sld1.lastname = "Черри";
	int hcrew = GetMaxCrewQuantity(sld1);
	DeleteAttribute(sld1, "SinkTenPercent");
	DeleteAttribute(sld1, "AboardToFinalDeck");
	DeleteAttribute(sld1, "SinkTenPercent");
	DeleteAttribute(sld1, "DontRansackCaptain");
	sld1.AlwaysSandbankManeuver = true;
	sld1.SaveItemsForDead = true;
	sld1.DontClearDead = true;
	sld1.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	sld1.DontRansackCaptain = true;
	SetCharacterPerk(sld1, "FastReload");
	SetCharacterPerk(sld1, "HullDamageUp");
	SetCharacterPerk(sld1, "SailsDamageUp");
	SetCharacterPerk(sld1, "CrewDamageUp");
	SetCharacterPerk(sld1, "CriticalShoot");
	SetCharacterPerk(sld1, "LongRangeShoot");
	SetCharacterPerk(sld1, "CannonProfessional");
	SetCharacterPerk(sld1, "ShipDefenseProfessional");
	SetCharacterPerk(sld1, "SwordplayProfessional");
	SetCharacterPerk(sld1, "BasicDefense");
	SetCharacterPerk(sld1, "AdvancedDefense");
	SetCharacterPerk(sld1, "ProfessionalDefense");
	SetCharacterPerk(sld1, "CriticalHit");
	SetCharacterPerk(sld1, "Sliding");
	SetCharacterPerk(sld1, "MusketsShoot");	
	Group_AddCharacter("Umberto_Group", "Umberto");
	SetCharacterRelationBoth(sti(sld1.index), GetMainCharacterIndex(), RELATION_FRIEND); // тестить

	LAi_group_MoveCharacter(sld, "EnemyFight");
	Group_SetGroupCommander("Umberto_Group", "Umberto");
	Group_SetTaskNone("Umberto_Group");//нет задачи
	Group_SetAddress("Umberto_Group", "Martinique", "Quest_Ships", "quest_ship_10");
	Group_SetTaskAttack("Umberto_Group", PLAYER_GROUP);
	
        DoQuestFunctionDelay("Gothic_SmithyAfterBattle", 100.0);	
}

void Gothic_SmithyAfterBattle(string qName) // 
{
		 log_info("Бандиты догадались, ловушка не сработала!");
	                    AddQuestRecord("Gothic_Smithy", "11");
		 pchar.questTemp.Gothic.Smithy_attack = "true";


                                    PChar.quest.GothicSmithy_GhostshipBoarding_1.win_condition.l1 = "NPC_Death";                                                                                                                                                                                                                               PChar.quest.GothicSmithy_GhostshipBoarding_1.win_condition.l1.character = "Umberto";
                                    PChar.quest.GothicSmithy_GhostshipBoarding_1.function = "GothicSmithy_GhostshipBoarding_1";

                                    PChar.quest.GothicSmithy_GhostshipBoarding_2.win_condition.l2 = "NPC_Death"; 
                                    PChar.quest.GothicSmithy_GhostshipBoarding_2.win_condition.l2.character = "Terri";
                                    PChar.quest.GothicSmithy_GhostshipBoarding_2.function = "GothicSmithy_GhostshipBoarding_2";

}

void GothicSmithy_GhostshipBoarding_1(string qName)
{
	DoQuestCheckDelay("sea_victory", 1.5);
                   DoQuestFunctionDelay("GothicSmithy_GhostshipBoarding_3", 4.0);
}

void GothicSmithy_GhostshipBoarding_3(string qName)
{
                   DoQuestFunctionDelay("Gothic_SmithyAfterBattle_1", 2.0);

	sld = GetCharacter(NPC_GenerateCharacter("KarSec", "mercen_17", "man", "man", 70, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 70, 50, 50, "blade_12", "pistol1", "bullet", 50);
	sld.name = "Эшли";
	sld.lastname = "Курти";
	LAi_CharacterDisableDialog(sld);
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_SetFightMode(pchar, true);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc0");

	sld = GetCharacter(NPC_GenerateCharacter("KarSecc", "citiz_56", "man", "man", 60, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 60, 50, 50, "blade_12", "pistol1", "bullet", 50);
	sld.name = "Барри";
	sld.lastname = "Флостер";
	LAi_CharacterDisableDialog(sld);
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
	LAi_SetFightMode(pchar, true);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc1");

	sld = GetCharacter(NPC_GenerateCharacter("Carrol", "lorensia9", "woman", "Lorensia", 80, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 80, 50, 50, "blade_26", "pistol1", "bullet", 16);
	sld.name = "Кэрол";
	sld.lastname = "Смит";
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_Carrol.c";
	sld.Dialog.CurrentNode = "First time";
	//LAi_SetImmortal(sld, true);
	LAi_SetWarriorType(sld);
	LAi_SetFightMode(pchar, true);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc2");
}

void Gothic_SmithyAfterBattle_1(string qName) // 
{
	SetLaunchFrameFormParam(".", "", 0, 18);
	SetLaunchFrameFormPic("loading\Boarding_A5.tga");
                   LaunchFrameForm();
                   DoQuestFunctionDelay("GothicSmithyBattle", 0.1);
}

void GothicSmithy_GhostshipBoardingGo(string qName) // Кэрол идет на абордаж
{
	for (int i=0;i<MAX_LOCATIONS;i++)
	{				
		if (Locations[i].id == "Deck_Galeon_Ship")
		{
			Locations[i].alwaysStorm = true; 
			Locations[i].storm = true;
		}
	}
	LAi_LocationFightDisable(&Locations[FindLocation("Deck_Galeon_Ship")], false);//разрешить драться
	DoQuestReloadToLocation("Deck_Galeon_Ship", "reload", "reload2", "GothicSmithy_GhostshipBoardingDeck");
}

void Gothic_SmithySeaShore_sailor()
{
                   LAi_SetActorType(pchar);
                   LAi_ActorAnimation(pchar, "Ground_StandUp", "Gothic_Smithy_sailor", 3.5);

	int iRank = 12+MOD_SKILL_ENEMY_RATE;
	sld = GetCharacter(NPC_GenerateCharacter("Sailor_coast", "citiz_37", "man", "man", iRank, FRANCE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, iRank, 10, 10, "blade_05", "", "bullet", iRank);
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.Dialog.CurrentNode = "Sailor_coast";
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   ChangeCharacterAddressGroup(sld, "Shore89", "reload", "reload2_back");
}

void Gothic_SmithySeaShore(string qName)
{
	chrDisableReloadToLocation = false;//открыть локацию
                  sld = characterFromId("Sailor_coast");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload2_back", "none", "", "", "", 25.0);

	sld = GetCharacter(NPC_GenerateCharacter("Senyan", "Senyan", "man", "man", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "blade50", "pistol11", "bullet", 10); 
          	sld.name      = "Сеньян";
          	sld.lastname      = "";
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
                   sld.Dialog.CurrentNode = "Senyan_coast";
	sld.rank = 16;
	LAi_SetHP(sld, 250, 250);
	sld.money = 2000;
	LAi_NPC_EquipPerk(sld, "fantom");
	sld.perks.list.BasicDefense = true;
                     sld.perks.list.ProfessionalDefense = true;
	sld.loyality = MAX_LOYALITY;
	sld.Payment = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 30, 30, 30, 30, 30, 30, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense ");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Ciras");
	GiveItem2Character(sld, "blade50");
	sld.equip.blade = "blade50";
	GiveItem2Character(sld, "pistol11");
	EquipCharacterbyItem(sld, "pistol11");
                   TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	LAi_SetCharacterUseBullet(sld, "bullet");
                    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.HoldEquip = true; 	//не отдавать оружие
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   ChangeCharacterAddressGroup(sld, "Shore38", "goto", "goto8");

}

void Gothic_SmithySeaShore_1(string qName)
{
                 LocatorReloadEnterDisable("Shore38", "boat", false);
                 AddQuestRecord("Gothic_Smithy", "13");
                 sld = characterFromId("Senyan");
                 LAi_SetActorType(sld);
                 LAi_ActorGoToLocation(sld, "reload", "sea", "none", "", "", "", 4.0);
                 sld = characterFromId("Sailor_coast");
                 sld.lifeday = 0;

	//PChar.quest.Gothic_SmithyPuertoRico.win_condition.l1 = "locator";
	//PChar.quest.Gothic_SmithyPuertoRico.win_condition.l1.location = "VillaAlegria_Town2";
	//PChar.quest.Gothic_SmithyPuertoRico.win_condition.l1.locator_group = "reload";
	//PChar.quest.Gothic_SmithyPuertoRico.win_condition.l1.locator = "reload4";
	//PChar.quest.Gothic_SmithyPuertoRico.function = "Gothic_SmithyPuertoRico";
}


void Gothic_SmithyFortOrange(string qName)
{

}





























void Gothic_SmithyPuertoRico(string qName)
{
                   PlaySound("Interface\Door_Kick.wav");
}

void Gothic_SenyanTalk(string qName)
{

	chrDisableReloadToLocation = true;//закрыть локацию
	sld = characterFromId("Senyan");
	switch (sld.quest.talk)
	{
	case "Senyan_PuertoRico": sld.dialog.currentnode = "PuertoRico"; break; //Сеньян говорит где черный вход
	}
	GetCharacterPos(pchar, &locx, &locy, &locz);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_SmithyPuertoRico_2(string qName)
{
	chrDisableReloadToLocation = false;//открыть локацию
	sld = characterFromId("Senyan");
	LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload31", "VillaAlegria_TownCave", "officers", "reload2_1", "Gothic_SmithyPuertoRico_3", -1);

	PChar.quest.Gothic_SmithyPuertoRico_3.win_condition.l1 = "locator";
	PChar.quest.Gothic_SmithyPuertoRico_3.win_condition.l1.location = "House_Smithy";
	PChar.quest.Gothic_SmithyPuertoRico_3.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_SmithyPuertoRico_3.win_condition.l1.locator = "reload2";
	PChar.quest.Gothic_SmithyPuertoRico_3.function = "Gothic_SmithyPuertoRico_3";

}

void Gothic_SmithyPuertoRico_3(string qName)
{
                    LocatorReloadEnterDisable("House_Smithy", "reload3", true);//закроем дом Смита до поры до времени 
                   PlaySound("Sex\sex14.wav");
	//Джулия
	sld = GetCharacter(NPC_GenerateCharacter("July", "lorensia3", "woman", "Lorensia", 35, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 35, 65, 65, "", "", "", 0);
	sld.name = "Джулия";
	sld.lastname = "Смит";
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                   sld.Dialog.CurrentNode = "Smithy_July";
	LAi_SetSitType(sld);
                   ChangeCharacterAddressGroup(sld, "Smithy_HouseF3_Room2", "sit", "sit1");

	//Милтен
	sld = GetCharacter(NPC_GenerateCharacter("Milten", "Milten", "man", "man_A", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 80, 90, "", "", "", 10); 
          	sld.name      = "Милтен";
          	sld.lastname      = "";
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Milten.c";
                   sld.Dialog.CurrentNode = "First time";
	LAi_SetLayType(sld);
	ChangeCharacterAddressGroup(sld, "Smithy_HouseF3_Room2", "quest", "quest1");

	PChar.quest.Gothic_SmithyPuertoRico_4.win_condition.l1 = "locator";
	PChar.quest.Gothic_SmithyPuertoRico_4.win_condition.l1.location = "House_Smithy";
	PChar.quest.Gothic_SmithyPuertoRico_4.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_SmithyPuertoRico_4.win_condition.l1.locator = "reload3";
	PChar.quest.Gothic_SmithyPuertoRico_4.function = "Gothic_SmithyPuertoRico_4";

}

void Gothic_SmithyPuertoRico_10(string qName)
{
                    LocatorReloadEnterDisable("House_Smithy", "reload3", false);//откроем 
}

void Gothic_SmithyPuertoRico_11(string qName)
{
 	sld = characterFromId("Milten");
                   LAi_SetGroundSitTypeNoGroup(sld);
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_12", 3.0);
}

void Gothic_SmithyPuertoRico_12(string qName)
{
	sld = characterFromId("Milten");
                   LAi_SetActorType(sld);
                   LAi_ActorAnimation(sld, "Ground_StandUp", "Gothic_Milten_01", 3.5);

}

void Gothic_Milten_1(string qName)
{
	sld = characterFromId("Milten");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "goto", "goto1", "Smithy_HouseF3_Room2", "barmen", "bar1", "Gothic_Milten_02", 5.0);

}

void Gothic_Milten_2(string qName)
{
	sld = characterFromId("Milten");
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Milten.c";
                   sld.Dialog.CurrentNode = "Milten_hallo_1";
                   LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}














void Gothic_SmithyPuertoRico_20(string qName)
{
	pchar.quest.Senyan_PuertoRicoCave.win_condition.l1 = "locator";
	pchar.quest.Senyan_PuertoRicoCave.win_condition.l1.location = "House_Smithy";
	pchar.quest.Senyan_PuertoRicoCave.win_condition.l1.locator_group = "reload";
	pchar.quest.Senyan_PuertoRicoCave.win_condition.l1.locator = "reload3";
	pchar.quest.Senyan_PuertoRicoCave.function = "Gothic_SmithyPuertoRico_21";
}

void Gothic_SmithyPuertoRico_21(string qName)
{
	chrDisableReloadToLocation = true;//закрыть локацию
	sld = characterFromId("Senyan");
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
                   sld.Dialog.CurrentNode = "PuertoRicoCave";
	GetCharacterPos(pchar, &locx, &locy, &locz);
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);

}

void Gothic_SmithyPuertoRico_22(string qName)
{
	chrDisableReloadToLocation = false;//открыть локацию

}





/////////////////////////////////////////////////////////////////////////////////////////////////////////
////   Миниквесты: продолжение....
/////////////////////////////////////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Завершающий этап Месть корсара." ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void Gothic_IslaMona_Mirabella(string qName)
{
	LocatorReloadEnterDisable("LaVega_town", "reload6", true); // закроем вход к Маркусу

}

void Gothic_RevengeCorsair(string qName)
{
	AddQuestRecord("RevengeCorsair", "1");
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_toLaVegaTavern";
	LocatorReloadEnterDisable("LaVega_town", "reload6", true); // закроем вход к Маркусу
}

void Gothic_RevengeCorsair_1(string qName)
{
	AddQuestRecord("RevengeCorsair", "2");
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_Tavern";
}

void Gothic_RevengeCorsair_2(string qName)
{
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_Oliver";
                  sld = characterFromID("Henry Morgan");//убераем Моргана
	          LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 1.0);
}

void Gothic_RevengeCorsair_3(string qName)
{
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_Usurer";
	AddQuestRecord("RevengeCorsair", "4");

}

void Gothic_RevengeCorsair_4(string qName)
{
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_Billy";
	AddQuestRecord("RevengeCorsair", "5");
                  // продублируем Билли Сипатого
	sld = GetCharacter(NPC_GenerateCharacter("Siplyi", "Billy_Pirt", "man", "man", 25, ENGLAND, -1, true, "quest"));
	FantomMakeCoolSailor(sld, SHIP_TARTANE, "Летучая рыба", CANNON_TYPE_NONECANNON, 70, 70, 70);
	FantomMakeCoolFighter(sld, 25, 70, 70, "blade_06", "pistol1", "bullet", 150);
	sld.name = "Билли";
	sld.lastname = "Пирт";
	sld.dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
	sld.DeckDialogNode = "Billy";
	sld.greeting = "";
	LAi_SetHP(sld, 250, 250);
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	sld.Ship.Mode = "pirate";
	LAi_SetImmortal(sld, true);
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable  = true;
	Group_AddCharacter("Mtr_Billi", "Siplyi");
	Group_SetGroupCommander("Mtr_Billi", "Siplyi");
	Group_SetAddress("Mtr_Billi", "Jamaica", "quest_ships", "quest_ship_9");
	Group_SetTaskNone("Mtr_Billi");
	Group_LockTask("Mtr_Billi");
}

void Gothic_RevengeCorsair_5(string qName)
{
	AddQuestRecord("RevengeCorsair", "6");

	PChar.quest.Gothic_RevengeCorsair_6.win_condition.l1 = "location";
	PChar.quest.Gothic_RevengeCorsair_6.win_condition.l1.location = "PortRoyal_HouseHut5";
	PChar.quest.Gothic_RevengeCorsair_6.function = "Gothic_RevengeCorsair_6";
}

void Gothic_RevengeCorsair_6(string qName)
{ 
	sld = CharacterFromID("Siplyi");// удаляем Билли
	sld.lifeday = 0;
	Group_DeleteGroup("Mtr_Billi");

                  sld = characterFromID("Henry Morgan");//возвращаем Моргана
	sld.Dialog.Filename = "Gothic_Quest\Morgan.c";
	sld.dialog.currentnode = "I_know_you_good";
	ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
	 LAi_SetImmortal(sld, true);
	 LAi_LoginInCaptureTown(sld, false);
	 LAi_SetHuberType(sld);
	 LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");

                                      // генерим тела в доме
	                   sld = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat", "mercen_16", "man", "man", 20, PIRATE, 1, false, "quest"));
	                   FantomMakeCoolFighter(sld, 80, 80, 90, "blade_19", "pistol4", "bullet", 10);
	                   sld.name 	= "Ряженный";
	                   sld.lastname = "Жавер";
          		 sld.greeting = ""; 
	                   sld.SuperShooter  = true;
	                   sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	                  LAi_SetCharacterUseBullet(sld, "bullet");
                                    TakeNItems(sld, "grapeshot", 27);
	                  TakeNItems(sld, "bullet", 13);
	                  TakeNItems(sld, "cartridge", 10);
	                  TakeNItems(sld, "GunPowder", 14);
	                  TakeNItems(sld, "MCorsairNotice", 1);
	                  LAi_SetActorType(sld);
                                    LAi_ActorDialog(sld, pchar, "", -1, 0);
                                    ChangeCharacterAddressGroup(sld, "PortRoyal_HouseHut5", "goto", "goto2");

	// пираты 2шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=2; i++)
	{
		sld2 = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat_"+i, "citiz_"+(40+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		sld2.monster = true; 
	                   LAi_SetImmortal(sld2, true);
		LAi_SetWarriorType(sld2);
		LAi_SetImmortal(sld2, true);//защита от дурака
		ChangeCharacterAddressGroup(sld2, "PortRoyal_HouseHut5", "goto", "goto1");
		LAi_CharacterDisableDialog(sld2);//запрет диалога
	                  LAi_SetCharacterUseBullet(sld2, "bullet");
                                    TakeNItems(sld2, "bullet", 50);
	                  AddItems(sld2, "gunpowder", 50);
	                  TakeNItems(sld2, "potion2", 5);
		LAi_SetActorType(sld2);
		LAi_ActorFollow(sld2, sld, "", -1);
	}
                  DoQuestFunctionDelay("Gothic_RevengeCorsair_7", 2.0);	
}

void Gothic_RevengeCorsair_7(string qName)
{
                  chrDisableReloadToLocation = true;//закрыть локацию
                  sld = CharacterFromID("RevengeCorsairPirat");
                  sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                  sld.Dialog.CurrentNode = "RevengeCorsair_Pirat";
                  LAi_SetActorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_RevengeCorsair_8(string qName)
{
                   LAi_SetPlayerType(pchar);
                   sld = CharacterFromID("RevengeCorsairPirat");
	LAi_SetWarriorType(sld);
                   LAi_group_MoveCharacter(sld, "EnemyFight");
	// пираты 2шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=2; i++)
	{
	sld2 = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat_"+i, "citiz_"+(40+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
	LAi_SetWarriorType(sld2);
                   LAi_group_MoveCharacter(sld2, "EnemyFight");
	LAi_SetImmortal(sld2, false);//защита от дурака
                   ChangeCharacterAddressGroup(sld2, pchar.location, "",  "");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "OpenTheDoors_RevengeCorsairDeath");
                    }

}

void Gothic_ReadMCorsairNotice() // нашли письмо
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadMCorsairNotice_1", 3.5);
}

void Gothic_ReadMCorsairNotice_1() // взяли письмо
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadMCorsairNotice_2", 3.5);
}
void Gothic_ReadMCorsairNotice_2() // прочли письмо
{
 	PlaySound("Interface\LOGENTRY.wav");
	AddQuestRecordInfo("MCorsairNotice", "1");
	DoQuestFunctionDelay("Gothic_ReadMCorsairNotice_3", 7.5);
}

void Gothic_ReadMCorsairNotice_3() //
{
    	AddQuestRecord("RevengeCorsair", "7");
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_Dominica";
}


void Gothic_RevengeCorsair_9(string qName)
{
                  pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_toTorus";
}

void Gothic_RevengeCorsair_10(string qName)
{
    	AddQuestRecord("RevengeCorsair", "8");
		
	LAi_group_Delete("EnemyFight");
        string sGroup = "Sea_TerraxCap1";
	group_DeleteGroup("Terrax_Group");
	Group_FindOrCreateGroup(sGroup);
	int iScl = MOD_SKILL_ENEMY_RATE*2+30;

	sld = GetCharacter(NPC_GenerateCharacter("TerraxCap", "quest_pirat_1", "man", "man", 20, PIRATE, 15, true, "quest"));
	FantomMakeSmallSailor(sld, SHIP_LINESHIP, "Красный дракон", CANNON_TYPE_CULVERINE_LBS36, 50, 45, 45, 50, 60);
	        FantomMakeCoolFighter(sld, 50, 110, 110, "blade_19", "pistol4", "bullet", 30);
		SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_7.tga");
	        sld.name = "Руперт";
	        sld.lastname = "Крессдайн";
		SetBaseShipData(sld);
		int hcrew = GetMaxCrewQuantity(sld);
		SetCrewQuantity(sld, hcrew);
		SetCrewQuantityFull(sld);
		sld.AlwaysEnemy = true;
		sld.DontRansackCaptain = true;
		sld.Coastal_Captain = true; //не ссорить нации
		sld.lifeDay = 15;
		sld.AnalizeShips = true;
		sld.WatchFort = true; //видеть форты
		sld.skill.Sailing = iScl+rand(10);
		sld.skill.Defence = iScl+rand(10);
		sld.skill.Accuracy = iScl+rand(10);
		sld.skill.Cannons = iScl+rand(10);
		sld.Ship.Crew.Morale = iScl+10;
		sld.Ship.Crew.Exp.Sailors = iScl;
		sld.Ship.Crew.Exp.Cannoners = iScl;
		sld.Ship.Crew.Exp.Soldiers = iScl;
		SetCharacterPerk(sld, "HullDamageUp");
		SetCharacterPerk(sld, "SailsDamageUp");
		SetCharacterPerk(sld, "CrewDamageUp");
		SetCharacterPerk(sld, "CriticalShoot");
		if (MOD_SKILL_ENEMY_RATE > 6) SetCharacterPerk(sld, "MusketsShoot");
		SetCharacterPerk(sld, "AdvancedBattleState");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "ShipSpeedUp");
		DeleteAttribute(sld, "SinkTenPercent");
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
		if (i == 2) SetCharacterGoods(sld, GOOD_SILVER, sti(pchar.questTemp.HWIC.Eng.SlvQty));//положить в трюм серебро
		sld.mapEnc.type = "war";
		sld.mapEnc.worldMapShip = "quest_ship";
                sld.mapEnc.Name = "военный корабль ''Красный дракон''";
                Group_AddCharacter("Terrax_Group", "TerraxCap");
	        Group_SetGroupCommander("Terrax_Group", "TerraxCap");
                Group_SetTaskAttackInMap("Terrax_Group", PLAYER_GROUP);
	        Map_CreateTrader("SantLous_Port", "Shore87", "TerraxCap", 16);//запуск энкаунтера

	pchar.quest.RevengeCorsair_Abordage.win_condition.l1 = "Character_Capture";
	pchar.quest.RevengeCorsair_Abordage.win_condition.l1.character = "TerraxCap";
	pchar.quest.RevengeCorsair_Abordage.function = "RevengeCorsair_AfterBattle";//взяли на абордаж
	pchar.quest.RevengeCorsair_Sink.win_condition.l1 = "Character_sink";
	pchar.quest.RevengeCorsair_Sink.win_condition.l1.character = "TerraxCap";
	pchar.quest.RevengeCorsair_Sink.function = "RevengeCorsair_AfterBattle_sink";//потопили
	pchar.quest.RevengeCorsair_Over.win_condition.l1 = "Character_Over";
	pchar.quest.RevengeCorsair_Over.win_condition.l1.character = "TerraxCap";
	pchar.quest.RevengeCorsair_Over.function = "RevengeCorsair_Over";//опоздали или не нашли
}

void RevengeCorsair_AfterBattle(string qName)//после боя
{
	pchar.GenQuest.DontPartition = true; // отключить дележ
	pchar.quest.RevengeCorsair_Over.over = "yes";
	AddComplexSeaExpToScill(150, 150, 150, 150, 150, 150, 0);
	DoQuestCheckDelay("sea_victory", 1.5);
	ChangeCharacterComplexReputation(pchar, "fame", 1);
    	AddQuestRecord("RevengeCorsair", "9");

	PChar.quest.Gothic_RevengeCorsair_13.win_condition.l1 = "location";
	PChar.quest.Gothic_RevengeCorsair_13.win_condition.l1.location = "Roseau_houseF1";
	PChar.quest.Gothic_RevengeCorsair_13.function = "Gothic_RevengeCorsair_13";
}

void RevengeCorsair_Over(string qName)//опоздали или не нашли 
{
	pchar.quest.RevengeCorsair_Abordage.over = "yes";
	pchar.quest.RevengeCorsair_Sink.over = "yes";
	CloseQuestHeader("RevengeCorsair");
    	AddQuestRecord("RevengeCorsair", "8_1");
	LocatorReloadEnterDisable("LaVega_town", "reload6", false); // откроем вход к Маркусу
}

void RevengeCorsair_AfterBattle_sink(string qName)//опоздали или не нашли 
{
	pchar.quest.RevengeCorsair_Abordage.over = "yes";
	pchar.quest.RevengeCorsair_Sink.over = "yes";
	CloseQuestHeader("RevengeCorsair");
    	AddQuestRecord("RevengeCorsair", "8_2");
	LocatorReloadEnterDisable("LaVega_town", "reload6", false); // откроем вход к Маркусу
}

void Gothic_RevengeCorsair_13(string qName)
{
	sld = CharacterFromID("TerraxCap");// удаляем капитана Тиракса
	sld.lifeday = 0;
	Group_DeleteGroup("Terrax_Group");

        sld = characterFromId("Terrax");
        sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
        sld.dialog.currentnode = "Terrax_1";
        LAi_SetImmortal(sld, true);//защита от дурака
        LAi_SetPriestType(sld);
        LAi_ActorAnimation(sld, "Bead", "", -1);
	sld.location = "Roseau_houseF1Room";
	sld.location.group = "goto";
	sld.location.locator = "goto7";

	//SetFunctionTimerCondition("Gothic_RevengeCorsair_14", 0, 0, 25, false);

                                      // генерим тела в доме
	                   sld = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat2", "officer_18", "man", "man", 20, PIRATE, 1, false, "quest"));
	                   FantomMakeCoolFighter(sld, 80, 80, 90, "blade_19", "pistol4", "bullet", 10);
	                   sld.name 	= "Сильвер";
	                   sld.lastname = "Бывалый";
          		 sld.greeting = ""; 
	                   sld.SuperShooter  = true;
	                   sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	                  LAi_SetCharacterUseBullet(sld, "bullet");
                                    TakeNItems(sld, "grapeshot", 27);
	                  TakeNItems(sld, "bullet", 13);
	                  TakeNItems(sld, "cartridge", 10);
	                  TakeNItems(sld, "GunPowder", 14);
	                  LAi_SetActorType(sld);
                                    LAi_ActorDialog(sld, pchar, "", -1, 0);
                                    ChangeCharacterAddressGroup(sld, "Roseau_houseF1", "goto", "goto2");

	// пираты 2шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=2; i++)
	{
		sld2 = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat2_"+i, "officer_"+(35+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
		sld2.monster = true; 
	                   LAi_SetImmortal(sld2, true);
		LAi_SetWarriorType(sld2);
		LAi_SetImmortal(sld2, true);//защита от дурака
		ChangeCharacterAddressGroup(sld2, "Roseau_houseF1", "goto", "goto1");
		LAi_CharacterDisableDialog(sld2);//запрет диалога
	                  LAi_SetCharacterUseBullet(sld2, "bullet");
                                    TakeNItems(sld2, "bullet", 50);
	                  AddItems(sld2, "gunpowder", 50);
	                  TakeNItems(sld2, "potion2", 5);
		LAi_SetActorType(sld2);
		LAi_ActorFollow(sld2, sld, "", -1);
                     }
                  DoQuestFunctionDelay("Gothic_RevengeCorsair_14", 2.0);	
}

void Gothic_RevengeCorsair_14(string qName)
{
                  chrDisableReloadToLocation = true;//закрыть локацию
                  sld = CharacterFromID("RevengeCorsairPirat2");
                  sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                  sld.Dialog.CurrentNode = "RevengeCorsair_Pirat2";
                  LAi_SetActorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);

}

void Gothic_RevengeCorsair_15(string qName)
{
        LAi_SetPlayerType(pchar);
        sld = CharacterFromID("RevengeCorsairPirat2");
	LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "EnemyFight");
	// пираты 2шт.
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for (i=1; i<=2; i++)
	{
	sld2 = GetCharacter(NPC_GenerateCharacter("RevengeCorsairPirat2_"+i, "mercen_"+(20+i), "man", "man", iRank, PIRATE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld2, iRank, 50, 50, LinkRandPhrase("blade_03","blade_05","blade_07"), "pistol1", "bullet", 120);//группа поддержки
	LAi_SetWarriorType(sld2);
                   LAi_group_MoveCharacter(sld2, "EnemyFight");
	LAi_SetImmortal(sld2, false);//защита от дурака
                   ChangeCharacterAddressGroup(sld2, pchar.location, "",  "");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	LAi_group_SetCheck("EnemyFight", "OpenTheDoors_RevengeCorsairDeath");
                    }

}

void Gothic_RevengeCorsair_16(string qName)
{
sld = GetCharacter(NPC_GenerateCharacter("Henry Morgan", "Morgan", "man", "man", 20, PIRATE, 1, true, "quest"));
FantomMakeCoolFighter(sld, 100, 100, 100, "blade_25", "", "", 100);
sld.Dialog.Filename = "Gothic_Quest\Morgan.c";
sld.dialog.currentnode = "I_know_you_good";
sld.name = "Генри";
sld.lastname = "Морган";
ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
LAi_SetImmortal(sld, true);
LAi_SetHuberType(sld)
sld.greeting = "Gr_Morgan";
AddQuestRecord("RevengeCorsair", "10");
LocatorReloadEnterDisable("Roseau_town", "houseF1", true); // закроем вход к Маркусу
pchar.questTemp.RevengeCorsair = "Kumana"; 
}

void Gothic_RevengeCorsair_17(string qName)// уходим на Исла-Тесеро
{
	PChar.quest.Gothic_RevengeCorsair_16.win_condition.l1 = "locator";
	PChar.quest.Gothic_RevengeCorsair_16.win_condition.l1.location = "Pirates_town";
	PChar.quest.Gothic_RevengeCorsair_16.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_RevengeCorsair_16.win_condition.l1.locator = "reload1_back";
	PChar.quest.Gothic_RevengeCorsair_16.function = "Gothic_RevengeCorsair_18";
}

void Gothic_RevengeCorsair_18(string qName)//
{
                    pchar.questTemp.GothicRevengeCorsair = "RevengeCorsair_toBermudes";
    	AddQuestRecord("RevengeCorsair", "17");

}

void Gothic_RevengeCorsair_18_1(string qName)//
{
	                     LocatorReloadEnterDisable("LaVega_town", "reload6", false);//откроем резиденцию
		//Маркуса на место
		iTemp = GetCharacterIndex("Terrax");
		if (iTemp != -1)
		{
		if(IsCompanion(&characters[iTemp]))  
		{
		RemoveCharacterCompanion(pchar, &characters[iTemp]);
		}   				
		LAi_SetHuberType(&characters[iTemp]);
		LAi_group_MoveCharacter(&characters[iTemp], "PIRATE_CITIZENS");
                ChangeCharacterAddressGroup(&characters[iTemp], "LaVega_townhall", "sit", "sit1");
                characters[iTemp].dialog.currentnode = "First time";
		} 		

}

void Gothic_RevengeCorsair_19(string qName)//
{
    	AddQuestRecord("RevengeCorsair", "18");
	SetFunctionTimerCondition("Gothic_RevengeCorsair_20", 0, 0, 4, false);
	LocatorReloadEnterDisable("Pirates_town", "reload1_back", true);//закроем выход в море

}

void Gothic_RevengeCorsair_20(string qName)//
{
    	AddQuestRecord("RevengeCorsair", "19");
	PChar.nation	= PIRATE;
	LocatorReloadEnterDisable("Pirates_town", "reload1_back", false);//откроем выход в море
	PChar.quest.Gothic_RevengeCorsair_19.win_condition.l1 = "locator";
	PChar.quest.Gothic_RevengeCorsair_19.win_condition.l1.location = "Pirates_town";
	PChar.quest.Gothic_RevengeCorsair_19.win_condition.l1.locator_group = "reload";
	PChar.quest.Gothic_RevengeCorsair_19.win_condition.l1.locator = "reload1_back";
	PChar.quest.Gothic_RevengeCorsair_19.function = "Gothic_RevengeCorsair_22";
PChar.quest.Gothic_RevengeCorsair_19.function = "Gothic_RevengeCorsair_22";
}

void Gothic_RevengeCorsair_21(string qName)//
{
	DoQuestFunctionDelay("Gothic_RevengeCorsair_22", 10.0);
	DoQuestFunctionDelay("Gothic_RevengeCorsair_23", 10.0);
}

void Gothic_RevengeCorsair_22(string qName)//Ставим испанцев Энрико
{
	log_info("Испанская эскадра на горизонте!");
	PlaySound("interface\notebook.wav");
	PlaySound("VOICE\Russian\EvilPirates02.wav");
	bQuestDisableMapEnter = true;//закрыть карту
	Group_FindOrCreateGroup("RevengeCorsair_GoldSeaGroup");
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+7;
	if (iRank > 45) iRank = 45;
	int iShip, Ship1, Ship2, Ship3, iCannon, Cannon1, Cannon2, iSpace;
	
	switch (MOD_SKILL_ENEMY_RATE)
	{
		case 2:
			Ship1 = SHIP_SMALLGALEON;
			Ship3 = SHIP_POLACCA;
			Cannon1 = CANNON_TYPE_CANNON_LBS20;
			Cannon2 = CANNON_TYPE_CANNON_LBS16;
		break;
		
		case 4:
			Ship1 = SHIP_GALEON_L	;
			Ship3 = SHIP_POLACRE;
			Cannon1 = CANNON_TYPE_CANNON_LBS24;
			Cannon2 = CANNON_TYPE_CANNON_LBS20;
		break;
		
		case 6:
			Ship1 = SHIP_SPAGALEON;
			Ship3 = SHIP_XEBEKVML	;
			Cannon1 = CANNON_TYPE_CANNON_LBS24;
			Cannon2 = CANNON_TYPE_CANNON_LBS20;
		break;
		
		case 8:
			Ship1 = SHIP_HEAVYGALEON;
			Ship3 = SHIP_BATTLEGALEON;
			Cannon1 = CANNON_TYPE_CANNON_LBS32;
			Cannon2 = CANNON_TYPE_CANNON_LBS24;
		break;
		
		case 10:
			Ship1 = SHIP_ARMEDFRIGATE;
			Ship3 = SHIP_SPAFRIGATE;
			Cannon1 = CANNON_TYPE_CANNON_LBS36;
			Cannon2 = CANNON_TYPE_CANNON_LBS32;
		break;
	}
	for (int i=1; i<=3; i++)
	{
		switch (i)
		{
			case 1:
				iShip = Ship1;
				iCannon = Cannon1;
			break;
			
			case 2:
				iShip = SHIP_LSHIP_SPA;
				iCannon = CANNON_TYPE_CANNON_LBS42;
				if (MOD_SKILL_ENEMY_RATE < 6) iCannon = CANNON_TYPE_CANNON_LBS36;
			break;
			
			case 3:
				iShip = Ship3;
				iCannon = Cannon2;
			break;
		}
		sld = GetCharacter(NPC_GenerateCharacter("RevengeCorsair_GoldCap_"+i, "off_spa_"+i, "man", "man", iRank, SPAIN, -1, true, "quest"));
		FantomMakeCoolSailor(sld, iShip, "", iCannon, 80, 80, 80);
		FantomMakeCoolFighter(sld, iRank, 100, 100, LinkRandPhrase("blade_17","blade_20","blade_21"), "pistol5", "bullet", 250);
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
		sld.DontRansackCaptain = true;
		sld.AnalizeShips = true;
		sld.AlwaysEnemy = true;
		sld.GenQuest.CrewGuardMode  = true;
		sld.Ship.Mode = "guard";
		SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
		Group_SetAddress("RevengeCorsair_GoldSeaGroup", "Bermudes", "", "");
		sld.ship.Crew.Morale = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Sailors = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Cannoners = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Soldiers = 60+MOD_SKILL_ENEMY_RATE*4;
		if (MOD_SKILL_ENEMY_RATE > 4) SetCharacterPerk(sld, "MusketsShoot");
		if (i == 1) 
		{
			iSpace = GetCharacterFreeSpace(sld, GOOD_PAPRIKA);
			iSpace = makeint(iSpace/2 + rand(iSpace/2));
			Fantom_SetCharacterGoods(sld, GOOD_PAPRIKA, iSpace, 1);
		}
		if (i == 2) 
		{
			sld.ship.name = "Де ла Нина";
			UpgradeShipParameter(sld, "Capacity");
			NullCharacterGoods(sld);
			AddCharacterGoods(sld, GOOD_BALLS, 1500);
			AddCharacterGoods(sld, GOOD_GRAPES, 1000);
			AddCharacterGoods(sld, GOOD_KNIPPELS, 800);
			AddCharacterGoods(sld, GOOD_BOMBS, 1700);
			AddCharacterGoods(sld, GOOD_POWDER, 5000);
			AddCharacterGoods(sld, GOOD_WEAPON, 700);
			AddCharacterGoods(sld, GOOD_FOOD, 1000);
			AddCharacterGoods(sld, GOOD_MEDICAMENT, 250);
			AddCharacterGoods(sld, GOOD_RUM, 100);
			//AddCharacterGoods(sld, GOOD_GOLD, 1300+rand(100));
		}
		if (i == 3) 
		{
			iSpace = GetCharacterFreeSpace(sld, GOOD_TOBACCO);
			iSpace = makeint(iSpace/2 + rand(iSpace/2));
			Fantom_SetCharacterGoods(sld, GOOD_TOBACCO, iSpace, 1);
		}
		Group_AddCharacter("RevengeCorsair_GoldSeaGroup", "RevengeCorsair_GoldCap_"+i);
	}
	Group_SetGroupCommander("RevengeCorsair_GoldSeaGroup", "RevengeCorsair_GoldCap_1");
	Group_SetAddress("RevengeCorsair_GoldSeaGroup", "Bermudes", "quest_ships", "quest_ship_6");
	Group_SetTaskAttack("RevengeCorsair_GoldSeaGroup", PLAYER_GROUP);
	Group_LockTask("RevengeCorsair_GoldSeaGroup");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	Ship_SetTaskAttack(SECONDARY_TASK, sti(sld.index), GetMainCharacterIndex());
	// на корабль Моргана
	int Hour = 2;
	if (MOD_SKILL_ENEMY_RATE < 4) Hour = 1;
	if (MOD_SKILL_ENEMY_RATE > 6) Hour = 3;
	pchar.quest.Gothic_RevengeCorsair_boss.win_condition.l1 = "Timer";
	pchar.quest.Gothic_RevengeCorsair_boss.win_condition.l1.date.hour  = sti(GetTime() + Hour);
	pchar.quest.Gothic_RevengeCorsair_boss.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
	pchar.quest.Gothic_RevengeCorsair_boss.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	pchar.quest.Gothic_RevengeCorsair_boss.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
	pchar.quest.Gothic_RevengeCorsair_boss.function = "Gothic_RevengeCorsair_23";
	// реакции
	pchar.quest.Gothic_RevengeCorsair_goldcheck.win_condition.l1 = "Group_Death";
	pchar.quest.Gothic_RevengeCorsair_goldcheck.win_condition.l1.group = "RevengeCorsair_GoldSeaGroup";
	pchar.quest.Gothic_RevengeCorsair_goldcheck.function = "Gothic_RevengeCorsairGoldCheck";


}

void Gothic_RevengeCorsair_23(string qName)//
{
	Group_FindOrCreateGroup("Henry Morgan_SeaGroup");
	sld = CharacterFromID("Henry Morgan");
	FantomMakeCoolSailor(sld, SHIP_LSHIP_QUEST, "Ужасающий", CANNON_TYPE_CULVERINE_LBS36, 110, 110, 110);
	FantomMakeCoolFighter(sld, 50, 110, 110, "blade_25", "pistol4", "bullet", 300);
	sld.DeckDialogNode = "Gothic_RevengeCorsair_quests_ship";
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Doctor3");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "SailingProfessional");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "Carpenter");
	SetCharacterPerk(sld, "Builder");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	RevengeCorsair_MorganSetShipParameter();
	SetCharacterGoods(sld, GOOD_BALLS, 3500);
	SetCharacterGoods(sld, GOOD_GRAPES, 2000);
	SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
	SetCharacterGoods(sld, GOOD_BOMBS, 3500);
	SetCharacterGoods(sld, GOOD_POWDER, 10500);
	SetCharacterGoods(sld, GOOD_WEAPON, 1000);
	SetCharacterGoods(sld, GOOD_FOOD, 2000);
	SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
	SetCharacterGoods(sld, GOOD_RUM, 200);
	SetCharacterGoods(sld, GOOD_PLANKS, 100);
	SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
	SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_18.tga");
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	sld.AlwaysSandbankManeuver = true;
	Character_SetAbordageEnable(sld, false); // нельзя абордировать
	sld.Tasks.CanBoarding = false; // запрет идти на абордаж - дубль
	sld.Tasks.CanChangeShipAfterBoarding = false; // запрет меняться кораблями - дубль
	sld.Ship.Mode = "mercenary";
	sld.Abordage.Enable = false;
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable = true; 
	sld.DontDeskTalk = true;
	LAi_SetImmortal(sld, false);
	sld.ShipHideImmortal = 1000; // непотопляемый корабль
	sld.SeaBoss = 0.8; // получает на 80% меньше урона корпусу, 10% урона парусам
	Group_AddCharacter("Henry Morgan_SeaGroup", "Henry Morgan");
	Group_SetGroupCommander("Henry Morgan_SeaGroup", "Henry Morgan");
	Group_SetTaskAttack("Henry Morgan_SeaGroup", "RevengeCorsair_GoldSeaGroup");
	Group_LockTask("Henry Morgan_SeaGroup");
	Group_SetAddress("RevengeCorsair_GoldSeaGroup", "Bermudes", "quest_ships", "quest_ship_6");
	Sea_LoginGroupCurrentSea("Henry Morgan_SeaGroup");
	DoQuestFunctionDelay("Gothic_RevengeCorsairMorganCommand", 3.0);
	pchar.quest.Gothic_RevengeCorsair_ship_fail.win_condition.l1 = "NPC_Death";
	pchar.quest.Gothic_RevengeCorsair_ship_fail.win_condition.l1.character = "Henry Morgan";
	pchar.quest.Gothic_RevengeCorsair_ship_fail.function = "RevengeCorsair_MorganGameOver"; // для шибко грамотных
}

void RevengeCorsair_MorganGameOver(string qName) // прибьем корабль особо умных, чтобы не выделывались
{
	Log_Info("На корабле "+pchar.ship.name+" взорвалась крюйт-камера!");
	Ship_Detonate(pchar, true, true); 
	PlaySound("Sea Battles\Vzriv_fort_001.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
}

void RevengeCorsair_MorganSetShipParameter()
{
	sld = CharacterFromID("Henry Morgan");
	SetSelfSkill(sld, 90, 90, 90, 90, 90);
	SetShipSkill(sld, 75, 90, 100, 100, 100, 100, 100, 100, 80);
	RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;
	RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 56;
	RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
	RealShips[sti(sld.Ship.Type)].SpeedRate = 13.5;
	RealShips[sti(sld.Ship.Type)].TurnRate = 29.5;
	RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
	RealShips[sti(sld.Ship.Type)].HP = 8000;
	RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 0.42;
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_pirate_8.tga");
	UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "WindAgainstSpeed");//бейд
	DeleteAttribute(sld, "ship.hulls");
	int hcrew = GetMaxCrewQuantity(sld);
	SetCrewQuantity(sld, hcrew);
	sld.Ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
}

void Gothic_RevengeCorsairMorganCommand(string qName) // 
{
	ref chr = CharacterFromID("Henry Morgan");
	sld = CharacterFromID("RevengeCorsair_GoldCap_1");
	Ship_SetTaskAttack(SECONDARY_TASK, sti(chr.index), sti(sld.index));
	SetCharacterRemovable(chr, false);
	chr.CompanionEnemyEnable = false; //всегда друзья
	SetCompanionIndex(pchar, -1, sti(chr.index));
	chr.loyality = MAX_LOYALITY;
}

void Gothic_RevengeCorsairGoldCheck(string qName) // 
{
    	AddQuestRecord("RevengeCorsair", "20");
	Group_DeleteGroup("RevengeCorsair_GoldSeaGroup");	
	sld = CharacterFromID("Henry Morgan");
	DeleteAttribute(sld, "DontDeskTalk");
	RemoveCharacterCompanion(pchar, sld);
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable = true; 
	LAi_SetImmortal(sld, true);
	Group_AddCharacter("Henry Morgan_SeaGroup", "Henry Morgan");
	Group_SetGroupCommander("Henry Morgan_SeaGroup", "Henry Morgan");
	Group_SetTaskNone("Henry Morgan_SeaGroup");
	Group_LockTask("Henry Morgan_SeaGroup");

}

void Gothic_RevengeCorsairComplete(string qName) // 
{
	Group_DelCharacter("Henry Morgan_SeaGroup", "Henry Morgan");
	Group_DeleteGroup("Henry Morgan_SeaGroup");
        sld = characterFromID("Henry Morgan");//возвращаем Моргана
	sld.Dialog.Filename = "Gothic_Quest\Morgan.c";
	sld.dialog.currentnode = "I_know_you_good";
	ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetHuberType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	// НЗГ
	ChangeCharacterComplexReputation(pchar, "nobility", 1);
	ChangeCharacterComplexReputation(pchar, "authority", 2);
	ChangeCharacterComplexReputation(pchar, "fame", 2);
	OfficersReaction("bad");
	OfficersReaction("bad");
	ChangeCharacterHunterScore(PChar, "spahunter", 20);
}

void Gothic_RevengeCorsair_24(string qName) // 
{
	bQuestDisableMapEnter = false;//открыть карту
	sld = GetCharacter(NPC_GenerateCharacter("Zorro", "Enrique_1", "man", "man", 40, SPAIN, -1, false, "quest"));
	sld.name = "дон Энрико";
	sld.lastname = "";
        sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
        sld.dialog.currentnode = "Zorro_1";
	sld.money = 16450;
	sld.rank = 21;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 100, 25, 25, 90, 37);
	SetShipSkill(sld, 25, 25, 25, 30, 25, 20, 35, 25, 30);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "ProfessionalDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "IronWill");
	SetCharacterPerk(sld, "ShipEscape");
	SetCharacterPerk(sld, "Doctor1");
	GiveItem2Character(sld, "pistol1");
	GiveItem2Character(sld, "blade_17"); 
	sld.equip.blade = "blade_17"; 
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	TakeNItems(sld, "jewelry4", 25+rand(10));
	TakeNItems(sld, "bullet", 1);
	TakeNItems(sld, "GunPowder", 1);
	sld.location = "Shore131";
	sld.location.group = "goto";
	sld.location.locator = "goto8";
	LAi_SetStayType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

}

void Gothic_RevengeCorsair_25(string qName) // 
{
	sld = CharacterFromID("Zorro");
	LAi_SetWarriorType(sld);
                    LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_SetImmortal(sld, false);//защита от дурака
                     ChangeCharacterAddressGroup(sld, pchar.location, "",  "");
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
	
}

void Gothic_RevengeCorsair_26(string qName) // 
{
	sld = CharacterFromID("Zorro");
	LAi_SetOwnerType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	LAi_SetImmortal(sld, true);//защита от дурака
                     SetFunctionTimerCondition("Gothic_RevengeCorsair_27", 0, 0, 60, false);

}

void Gothic_RevengeCorsair_27(string qName) // 
{
	sld = GetCharacter(NPC_GenerateCharacter("Zorro", "skel1", "man", "skeleton", 40, SPAIN, -1, false, "quest"));
	sld.name = "дон Энрико";
	sld.lastname = "";
                     sld.greeting = "Gr_skel"; 
	sld.money = 16450;
	sld.rank = 21;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 100, 25, 25, 90, 37);
	SetShipSkill(sld, 25, 25, 25, 30, 25, 20, 35, 25, 30);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
	SetCharacterPerk(sld, "Energaiser"); 
	SetCharacterPerk(sld, "BasicDefense"); 
	SetCharacterPerk(sld, "AdvancedDefense"); 
	SetCharacterPerk(sld, "ProfessionalDefense"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional"); 
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "HPPlus"); 
	SetCharacterPerk(sld, "EnergyPlus");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "Grus"); 
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "IronWill");
	SetCharacterPerk(sld, "ShipEscape");
	SetCharacterPerk(sld, "Doctor1");
	GiveItem2Character(sld, "pistol1");
	GiveItem2Character(sld, "blade_17"); 
	sld.equip.blade = "blade_17"; 
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	TakeNItems(sld, "jewelry4", 25+rand(10));
	TakeNItems(sld, "bullet", 1);
	TakeNItems(sld, "GunPowder", 1);
	sld.location = "Shore131";
	sld.location.group = "goto";
	sld.location.locator = "goto8";
	LAi_SetWarriorType(sld);
     LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_SetImmortal(sld, false);//защита от дурака
	//стравливаем
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);

}




/////////////////////////////////////////////////////////////////////////////////////
// Одержимые
/////////////////////////////////////////////////////////////////////////////////////
void Gothic_Obsession(string qName)
{		
	pchar.questTemp.GothicRumoursObsession = "Obsession";
}

void GothicObsessioninStart(string qName)
{
	PChar.quest.DisappearPeopleStart.win_condition.l1 = "Location_Type";
	PChar.quest.DisappearPeopleStart.win_condition.l1.location_type = "town";
	PChar.quest.DisappearPeopleStart.function = "GothicObsessionStart";
}

void GothicObsessionStart(string qName)
{
	AddQuestRecord("Obsession", "1");	
	PChar.quest.GothicObsessionFisrtBattle.win_condition.l1 = "location";
	PChar.quest.GothicObsessionFisrtBattle.win_condition.l1.location = "PortPax_Graveyard";
	PChar.quest.GothicObsessionFisrtBattle.function = "GothicObsessionFisrtBattle";
}

void GothicObsessionFisrtBattle(string qName)
{	
	StartQuestMovie(true, true, true);
	InterfaceStates.Buttons.Save.enable = false;
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	PlaySound("Absolum\Robbins Captured.mp3");	
	chrDisableReloadToLocation = true;	
	LAi_SetActorType(PChar);

	sld = GetCharacter(NPC_GenerateCharacter("Bill Matthew", "mercen_" + (rand(29)+1), "man", "man", 15, PIRATE, 0, true, "soldier"));
	sld.name = "Билл";
	sld.lastname = "Метью";
	LAi_SetWarriorType(sld);
	LAi_SetImmortal(sld, true);
                  LAi_group_MoveCharacter(sld, "BILL_MATTHEW");
	ChangeCharacterAddressGroup(sld, "PortPax_Graveyard", "goto", "goto7");
	
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	for(int i=1; i<=22; i++)
	{

		sld = GetCharacter(NPC_GenerateCharacter("Bill Matthew Killer " + i, "skel" + (rand(3)+1), "man", "skeleton", iRank, PIRATE, 0, true, "soldier"));
		sld.monster = true; // признак нежити
		sld.sex = "Skeleton"; 
		sld.viper = true;
		sld.NotRemoved = true;
	                  ChangeCharacterAddressGroup(sld, "PortPax_Graveyard", "rld", "loc" + i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "BILL_MATTHEW_KILLERS");
	}
	
	LAi_group_SetRelation("BILL_MATTHEW_KILLERS", "BILL_MATTHEW", LAI_GROUP_ENEMY);
	LAi_group_FightGroups("BILL_MATTHEW_KILLERS", "BILL_MATTHEW", true);
		
	DoQuestFunctionDelay("GothicObsessionFisrtBattleStart", 8.0);
}

void GothicObsessionFisrtBattleStart(string qName)
{
	EndQuestMovie();
                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_DIEMONSTER.wav");
	InterfaceStates.Buttons.Save.enable = true;
	LAi_SetPlayerType(PChar);	
	sld = CharacterFromID("Bill Matthew");
                  LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	
	LAi_group_Delete("BILL_MATTHEW");
	LAi_group_Delete("BILL_MATTHEW_KILLERS");	
	for(int i=1; i<=22; i++)
	{
		sld = CharacterFromID("Bill Matthew Killer " + i);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

	PChar.quest.GothicObsessionFisrtBattleWin.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicObsessionFisrtBattleWin.win_condition.l1.character = "Bill Matthew Killer " + i;
	PChar.quest.GothicObsessionFisrtBattleWin.function = "GothicObsessionFisrtBattleWin";	
}

void GothicObsessionFisrtBattleWin(string qName)
{
                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_DIEMONSTER.wav");
                  sld = characterFromId("Bill Matthew");
	sld.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
	sld.Dialog.CurrentNode = "BillMatthew";
                  LAi_SetWarriorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void GothicObsessionTakeCoin()
{
                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOODKILL.wav");
	chrDisableReloadToLocation = false;	
                  sld = characterFromId("Bill Matthew");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload2_back", "none", "", "", "", -1);
	
	AddQuestRecord("Obsession", "2");
	pchar.questTemp.GothicRumoursObsession = "ObsessionTakeCoin";
	
	PChar.quest.GothicObsessionTwoMeeting.win_condition.l1 = "Location_Type";
	PChar.quest.GothicObsessionTwoMeeting.win_condition.l1.location_type = "seashore";
	PChar.quest.GothicObsessionTwoMeeting.function = "GothicObsessionTwoMeeting";
}

void GothicObsessionTwoMeeting(string qName)
{
	LAi_SetActorType(PChar);	
	chrDisableReloadToLocation = true;
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	// скелеты - крутые
	for(int i=1; i<=18; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("GothicObsession in Shore Killer "+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		ChangeCharacterAddressGroup(chr, PChar.location, "goto", "goto" + i);
		LAi_SetActorType(chr);
		LAi_ActorTurnToCharacter(chr, PChar);
	}		
	DoQuestFunctionDelay("GothicObsessionTwoMeetingBattle", 3.0);
}

void GothicObsessionTwoMeetingBattle(string qName)
{
	LAi_SetPlayerType(PChar);
	ref chr;
	for(int i=1; i<=18; i++)
	{
		chr = CharacterFromID("GothicObsession in Shore Killer " + i);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

	PChar.quest.GothicObsessionTwoMeetingBattleWin.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicObsessionTwoMeetingBattleWin.win_condition.l1.character = "GothicObsession in Shore Killer";
	PChar.quest.GothicObsessionTwoMeetingBattleWin.function = "GothicObsessionTwoMeetingBattleWin";

}

void GothicObsessionTwoMeetingBattleWin(string qName)
{
	chrDisableReloadToLocation = false;
	AddQuestRecord("Obsession", "3");
	SetTimerFunction("GothicObsessionFriMeetingBattleWin", 0, 0, 10);
}
void GothicObsessionFriMeetingBattleWin(string qName)
{
	PChar.quest.GothicObsessionFriMeeting.win_condition.l1 = "Location_Type";
	PChar.quest.GothicObsessionFriMeeting.win_condition.l1.location_type = "seashore";
	PChar.quest.GothicObsessionFriMeeting.function = "GothicObsessionFriMeeting";
}

void GothicObsessionFriMeeting(string qName)
{
	LAi_SetActorType(PChar);	
	chrDisableReloadToLocation = true;
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	// скелеты - крутые
	for(int i=1; i<=18; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("GothicObsession in Shore Killer "+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		ChangeCharacterAddressGroup(chr, PChar.location, "goto", "goto" + i);
		LAi_SetActorType(chr);
		LAi_ActorTurnToCharacter(chr, PChar);
	}		
	DoQuestFunctionDelay("GothicObsessionFriMeetingBattle", 3.0);
}

void GothicObsessionFriMeetingBattle(string qName)
{
	LAi_SetPlayerType(PChar);
	ref chr;
	for(int i=1; i<=18; i++)
	{
		chr = CharacterFromID("GothicObsession in Shore Killer " + i);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

	PChar.quest.GothicObsessionFoMeetingBattleWin.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicObsessionFoMeetingBattleWin.win_condition.l1.character = "GothicObsession in Shore Killer";
	PChar.quest.GothicObsessionFoMeetingBattleWin.function = "GothicObsessionFoMeetingBattleWin";
}

void GothicObsessionFoMeetingBattleWin(string qName)
{
	chrDisableReloadToLocation = false;
	AddQuestRecord("Obsession", "3");
	SetTimerFunction("GothicObsessionFoMeetingBattleWin", 0, 0, 10);
}

void GothicObsessionFoMeeting(string qName)
{
	LAi_SetActorType(PChar);	
	chrDisableReloadToLocation = true;
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	// скелеты - крутые
	for(int i=1; i<=18; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("GothicObsession in Shore Killer "+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		ChangeCharacterAddressGroup(chr, PChar.location, "goto", "goto" + i);
		LAi_SetActorType(chr);
		LAi_ActorTurnToCharacter(chr, PChar);
	}		
	DoQuestFunctionDelay("GothicObsessionFoMeetingBattle", 3.0);
}

void GothicObsessionFoMeetingBattle(string qName)
{
	LAi_SetPlayerType(PChar);
	ref chr;
	for(int i=1; i<=18; i++)
	{
		chr = CharacterFromID("GothicObsession in Shore Killer " + i);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

}


void GothicObsession_Myxir(string qName)
{
	pchar.questTemp.GothicRumoursObsession = "MyxirTakeCoin";
	// ЗДЕСЬ ВОЗВРАЩАЕМ МИКСЕРА ИЗ ХРАМА
	sld = CharacterFromID("Myxir");
	LAi_SetCitizenType(sld);
	LAi_RemoveLoginTime(sld);
	// sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "LibraryHouse", "goto", "goto8");
}

void GothicObsession_MyxirTakeCoin(string qName)
{
	AddQuestRecord("Obsession", "4");
	// ЗДЕСЬ ВОЗВРАЩАЕМ МИКСЕРА ИЗ ХРАМА
	sld = CharacterFromID("Myxir");
	LAi_SetCitizenType(sld);
	LAi_RemoveLoginTime(sld);
	// sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "LibraryHouse", "goto", "goto8");
	sld = ItemsFromID("architects_table");
                  sld.shown = true;
	sld.startLocation = "Temple";
	sld.startLocator = "item2";

	PChar.quest.GothicObsessionFindTable.win_condition.l1 = "location";
	PChar.quest.GothicObsessionFindTable.win_condition.l1.location = "Temple";
	PChar.quest.GothicObsessionFindTable.function = "GothicObsessionFindTable";
}

void GothicObsessionFindTable()
{
	chrDisableReloadToLocation = true;
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");

	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	// скелеты - крутые
	for(int i=1; i<=20; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("GothicObsession in Temple "+i, "skel"+(rand(3)+1), "skeleton", "skeleton", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade_18","blade_19","blade_21"), sTemp, "bullet", 170);
		chr.monster = true; // признак нежити
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		ChangeCharacterAddressGroup(chr, "Temple", "goto", "goto" + (i+12));
		LAi_SetWarriorType(chr);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	}
	
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);

                  DoQuestFunctionDelay("GothicObsessionFind_Orc", 30.0);		
}

void GothicObsessionFind_Orc(string qName) //
{
                  PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
                  DoQuestFunctionDelay("DIEENEMY", 2.0);
	CreateLocationParticles("item", "reload", "reload2", 1.20, 2, 2, "");
	CreateLocationParticles("item", "reload", "reload2", 1.20, 2, 2, "");
	CreateLocationParticles("item", "reload", "reload2", 1.20, 2, 2, "");
                  DoQuestFunctionDelay("ORC_ATTACK", 1.0);
                  DoQuestFunctionDelay("GothicObsession_Orc_attack", 4.0);
}

void GothicObsession_Orc_attack(string qName) //
{
                 PlaySound("VOICE\Russian\gotica\SFX\DEM_WARN01.wav");
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sTemp = "pistol1";
	if (MOD_SKILL_ENEMY_RATE > 4) sTemp = "pistol5";
	if (MOD_SKILL_ENEMY_RATE > 6) sTemp = "pistol6";
	if (MOD_SKILL_ENEMY_RATE > 8) sTemp = "pistol4";
	for (i=1; i<=15; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("GothicObsession in Temple_Orc_"+i, "Orc", "Orc", "Orc", iRank+4, PIRATE, -1, true, "soldier"));
		FantomMakeCoolFighter(chr, iRank+4, 70, 70, LinkRandPhrase("blade53","blade53","blade53"), sTemp, "bullet", 170);
		chr.monster = true; 
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		ChangeCharacterAddressGroup(chr, "Temple", "reload", "reload2");
		LAi_group_MoveCharacter(chr, "EnemyFight");

	}
                  pchar.quest.GothicObsessiontable.win_condition.l1 = "Group_Death";
	pchar.quest.GothicObsessiontable.win_condition.l1.group = "GothicObsession in Temple_Orc_"+i;
	pchar.quest.GothicObsessiontable.function = "GothicObsessiontable";
}

void GothicApostatesAPSarchitects(string qName)
{
	AddQuestRecord("Obsession", "7_1");
}

void GothicObsessiontable()
{
	chrDisableReloadToLocation = false;
	PChar.quest.GothicObsessiontable_1.win_condition.l1 = "locator";
	PChar.quest.GothicObsessiontable_1.win_condition.l1.location = "Temple";
	PChar.quest.GothicObsessiontable_1.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicObsessiontable_1.win_condition.l1.locator = "reload1_back";
	PChar.quest.GothicObsessiontable_1.function = "GothicObsessiontable_1";
}

void GothicObsessiontable_1()
{
	AddQuestRecord("Obsession", "6");
	pchar.questTemp.GothicRumoursObsession = "Myxir_architects_table";
}

void GothicObsession_table_Myxir(string qName)
{
           sld = CharacterFromID("Myxir");
           LAi_SetActorType(sld);
           LAi_ActorGoToLocator(sld, "goto", "goto5", "", -1);
           DoQuestFunctionDelay("GothicObsession_table_Myxir_1", 3.0);
}

void GothicObsession_table_Myxir_1(string qName)
{
                  sld = CharacterFromID("Myxir");
                  ChangeCharacterAddressGroup(sld, pchar.location, "sit", "sit1");
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);
                  sld.dialog.currentnode = "Myxir_architects_table_2";
}

void Gothic_ReadMyxirNotice() // нашли письмо
{
	if (pchar.location == Get_My_Cabin())
	{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
                  DoQuestFunctionDelay("Gothic_ReadMyxirNotice_1", 3.0);
                   }
	else 
	{
		PlaySound("interface\knock.wav");
		log_info("Для вызова духа лучше расположиться в каюте");
                                    PlaySound("VOICE\Russian\GOTHIC\GG\DOESNTWORK.wav");
	}
}

void Gothic_ReadMyxirNotice_1(string qName)
{
                 PlaySound("VOICE\Russian\gotica\SFX\MFX_BARRIERE_SHOOT.wav");
                 DoQuestFunctionDelay("Gothic_ReadMyxirNotice_2", 2.0);
}

void Gothic_ReadMyxirNotice_2(string qName)
{
                 chrDisableReloadToLocation = true;
                 PlaySound("VOICE\Russian\GOTHIC\GG\STONEPLATE_1.wav");
                 Log_Info("Я приказываю тебе Делвин Блейз явится в мир живых ...");
                 pchar.questTemp.Gothic.MyxirNotice = "true";
                 RemoveItems(PChar, "MyxirNotice", 1);
                 DoQuestFunctionDelay("GothicObsession_Devlin", 2.0);
}

void GothicObsession_Devlin()
{
                  PlaySound("VOICE\Russian\gotica\SFX\MYSTERY_06.wav");
	CreateLocationParticles("fire_incas_Simple", "rld", "loc1", 0.5, 0, 0, "");
                  DoQuestFunctionDelay("GothicObsession_Devlin_1", 2.0);
                // Создаём одержимого Делвина в нормальном виде
	sld = GetCharacter(NPC_GenerateCharacter("ObsessionDevlin", "BSharp_0", "man", "man", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade53", "pistol2", "grapeshot", 30);
	sld.name = "Фиамотар";
	sld.lastname = "";
	LAi_SetActorType(sld);
                  LAi_SetActorType(pchar);
                  LAi_ActorTurnToLocator(pchar, "rld", "aloc1");
}

void GothicObsession_Devlin_1()
{
                 PlaySound("VOICE\Russian\gotica\SFX\DIA_SCHWARZMAGIER_HELLO_09_03.wav");
                  sld = characterFromId("ObsessionDevlin");
	sld.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
	sld.Dialog.CurrentNode = "ObsessionDevlin";
	LAi_SetActorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);
                  LAi_SetPlayerType(pchar);
	LAi_SetImmortal(sld, true);
                  ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc1");
}

void GothicObsession_Devlin_2()
{ 
	sld = characterFromId("ObsessionDevlin");
                  ChangeCharacterAddressGroup(sld, "none", "", ""); 
                  PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
	CreateLocationParticles("item", "rld", "aloc3", 1.70, 3, 3, "");
	CreateLocationParticles("item", "rld", "aloc3", 1.70, 3, 3, "");
	CreateLocationParticles("item", "rld", "aloc3", 1.70, 3, 3, "");
	LAi_SetActorType(pchar);
                  LAi_ActorAnimation(pchar, "afraid", "GothicObsession_afraid", 1.2);
	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/2; // 1/2 жизни сносим 
	Log_Info("Фиамотар поглотил ваши силы - умения в оружии снизились на 30 единиц!");
                  DoQuestFunctionDelay("GothicObsession_Devlin_3", 3.0);
}

void GothicObsession_Devlin_3()
{
                  PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav"); 
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
                // Создаём одержимого Делвина скелета
	sld = GetCharacter(NPC_GenerateCharacter("ObsessionDevlinskel", "BSUnd", "man", "man", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade53", "pistol2", "grapeshot", 30);
	sld.name = "Фиамотар";
	sld.lastname = "";
	sld.LSC_clan = true;
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	LAi_SetActorType(sld);
                  LAi_SetPlayerType(pchar);
                  ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "aloc1");
                  DoQuestFunctionDelay("GothicObsession_Devlin_4", 1.0);
}

void GothicObsession_Devlin_4()
{
                  PlaySound("VOICE\Russian\gotica\SFX\MYSTERY_07.wav");
	CreateLocationParticles("fire_incas_Simple", "rld", "aloc1", 0.5, 0, 0, "");
	sld = characterFromId("ObsessionDevlinskel");
	sld.Dialog.FileName = "Gothic_Quest\Gothic_npc\OtherNPC.c";
	sld.Dialog.CurrentNode = "ObsessionDevlin_3";
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 0.0, 0);
}

void GothicObsession_Devlin_5()
{
                 chrDisableReloadToLocation = false;
                  PlaySound("VOICE\Russian\gotica\SFX\DEM_AMBIENT01.wav");
	sld = characterFromId("ObsessionDevlinskel");
                  ChangeCharacterAddressGroup(sld, "none", "", ""); 
                  DoQuestFunctionDelay("GothicObsessionBattle", 1.0);
}

void GothicObsessionBattle(string qName)
{
	Island_SetReloadEnableGlobal("Martinique", false);//закрыть остров
	bQuestDisableMapEnter = true;//на карту тоже
                  DoQuestCheckDelay("Trec_crew", 1.0);
	int iRank = 15+MOD_SKILL_ENEMY_RATE;

	Group_FindOrCreateGroup("Fiamatar_Attack");
	// устанавливаем Фиамотар
	sld = GetCharacter(NPC_GenerateCharacter("FiamatarCap", "BSUnd", "man", "man", iRank, PIRATE, -1, true, "quest"));
	sld.name = "Фиамотар";
	sld.lastname = "";
	FantomMakeCoolSailor(sld, SHIP_FLYINGDUTCHMAN_h, "Фиамотар", CANNON_TYPE_CANNON_LBS36, 100, 100, 100);
	FantomMakeCoolFighter(sld, iRank, 100, 100, "blade53", "pistol5", "bullet", 400);
	sld.MultiFighter = 2.5; // мультифайтер
	sld.MultiShooter = 2.5;
	GiveItem2Character(sld, "spyglass3");
	sld.cirassId = Items_FindItemIdx("cirass1");
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.GenQuest.CrewSkelMode = true;
	sld.Ship.Mode = "skel";
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	sld.AlwaysEnemy = true;
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.WatchFort = true; //видеть форты
	sld.DontHitInStorm = true; // не ломается в шторм
	sld.AlwaysSandbankManeuver = true;
	sld.SinkTenPercent = false;
	SetShipSailsFromFile(sld, "ships/parus_common.tga");
	SetSailsColor(sld, 8);//черный рваный парус
	ref shTo = &RealShips[sti(sld.Ship.Type)];
	shTo.SpeedRate = 30.0;
	shTo.TurnRate = 70.0;
	SetCrewQuantityOverMax(sld, 666);
SetCharacterPerk(sld, "Energaiser"); 
SetCharacterPerk(sld, "BasicDefense"); 
SetCharacterPerk(sld, "AdvancedDefense"); 
SetCharacterPerk(sld, "ProfessionalDefense"); 
SetCharacterPerk(sld, "Tireless"); 
SetCharacterPerk(sld, "CriticalHit"); 
SetCharacterPerk(sld, "Sliding"); 
SetCharacterPerk(sld, "SwordplayProfessional"); 
SetCharacterPerk(sld, "BladeDancer"); 
SetCharacterPerk(sld, "Gunman"); 
SetCharacterPerk(sld, "GunProfessional"); 
SetCharacterPerk(sld, "Sniper");
SetCharacterPerk(sld, "IronWill"); 
SetCharacterPerk(sld, "ShipEscape"); 
SetCharacterPerk(sld, "Troopers"); 
SetCharacterPerk(sld, "MusketsShoot"); 
SetCharacterPerk(sld, "CrewDamageUp"); 
SetCharacterPerk(sld, "BasicCommerce"); 
SetCharacterPerk(sld, "AdvancedCommerce"); 
SetCharacterPerk(sld, "HullDamageUp"); 
SetCharacterPerk(sld, "SailsDamageUp"); 
SetCharacterPerk(sld, "CriticalShoot"); 
SetCharacterPerk(sld, "Carpenter"); 
SetCharacterPerk(sld, "LightRepair"); 
SetCharacterPerk(sld, "StormProfessional"); 
SetCharacterPerk(sld, "WindCatcher"); 
SetCharacterPerk(sld, "SailsMan"); 
SetCharacterPerk(sld, "ShipSpeedUp"); 
SetCharacterPerk(sld, "ShipTurnRateUp"); 
	sld.ship.Crew.Morale = 60+MOD_SKILL_ENEMY_RATE*4;
	sld.Ship.Crew.Exp.Sailors = 60+MOD_SKILL_ENEMY_RATE*4;
	sld.Ship.Crew.Exp.Cannoners = 60+MOD_SKILL_ENEMY_RATE*4;
	sld.Ship.Crew.Exp.Soldiers = 60+MOD_SKILL_ENEMY_RATE*4;
	AddCharacterGoods(sld, GOOD_BALLS, 3300);
	AddCharacterGoods(sld, GOOD_GRAPES, 500);
	AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
	AddCharacterGoods(sld, GOOD_BOMBS, 1500);
	AddCharacterGoods(sld, GOOD_POWDER, 6000);
	TakeNItems(sld, "potion2", 10);
	TakeNItems(sld, "Dragon_roses", 1);
	TakeNItems(sld, "Obsession_Coins", 1);
	sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	sld.cirassId = Items_FindItemIdx("cirass1");
	Group_AddCharacter("Fiamatar_Attack", "FiamatarCap");
                  Group_SetGroupCommander("Fiamatar_Attack", "FiamatarCap");
	Group_SetTaskAttack("Fiamatar_Attack", PLAYER_GROUP);
	Group_SetAddress("Fiamatar_Attack", "Martinique", "", "");
                  Group_LockTask("Fiamatar_Attack");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	Sea_LoginGroupCurrentSea("Fiamatar_Attack");
	Group_SetTaskAttack("Fiamatar_Attack", PLAYER_GROUP);
	Ship_SetTaskAttack(SECONDARY_TASK, sti(sld.index), GetMainCharacterIndex());
	
	
	PChar.quest.GothicObsessionAtSentMartinWinner.win_condition.l1 = "Group_Death";
	PChar.quest.GothicObsessionAtSentMartinWinner.win_condition.l1.group = "Fiamatar_Attack";
	PChar.quest.GothicObsessionAtSentMartinWinner.function = "GothicObsessionAtMartiniqueWinner";

}

void GothicObsessionAtMartiniqueWinner(string qName)
{
	Island_SetReloadEnableGlobal("Trinidad", true);//открыть остров
	bQuestDisableMapEnter = false; // patch-4
	DoQuestCheckDelay("sea_victory", 1.5);
	AddQuestRecord("Obsession", "8"); // AddQuestRecord("Obsession", "8");
	Group_DeleteGroup("Fiamatar_Attack");
	AddComplexSeaExpToScill(150, 150, 150, 150, 150, 150, 0);
	ChangeCharacterComplexReputation(pchar, "fame", 5);
                     CloseQuestHeader("Obsession");
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_110";
}



////////////////////////////////////////////////////////////////////////
//----------------------------Отступники веры-------------------------------------
  ////////////////////////////////////////////////////////////////////////

void GothicApostates_Incquisitio(string qName)//В инквизиции
{
	ref location = &Locations[FindLocation("Santiago_Incquisitio2")];		
	// Перекладываем предметы ГГ в сундук 
	aref arItems, boxItems;
	ref rItem;
	string sName;
	makearef(arItems, PChar.items);
	makearef(boxItems, location.box2.items);
	int iItemsNum = GetAttributesNum(arItems);
	for(int i=0; i<iItemsNum; i++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, i));
		rItem = ItemsFromID(sName);
		if (rItem.ItemType != "QUESTITEMS")
		{
			boxItems.(sName) = PChar.items.(sName);
		}
	}
	location.box2.money = PChar.money;	
	location.box2 = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear())
		
	RemoveAllCharacterItems(PChar, true);	
}

void GothicApostates_Attack_AfterBattle(string qName)//после боя
{
	Island_SetReloadEnableGlobal("Cuba1", true);
	bQuestDisableMapEnter = false;
	DoQuestCheckDelay("sea_victory", 1.5);

	pchar.quest.GothicApostates_APS1.win_condition.l1 = "location";
	pchar.quest.GothicApostates_APS1.win_condition.l1.location = "PortSpein_town";
	pchar.quest.GothicApostates_APS1.win_condition = "GothicApostates_APS_Trinidad";
}

void GothicApostatesAPSChurchOver(string qName)
{
                    LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	DeleteQuestCheck("GothicApostates_APSChurch_1");
	AddQuestRecord("APS", "7");
	CloseQuestHeader("APS");
	DeleteAttribute(pchar, "APS");
	sld = characterFromId("ApostatesDN");//смотрителя убираем
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 1.0);
}

void GothicApostatesAPSCPortoBelloEND(string qName)//опоздали
{
                     LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	AddQuestRecord("APS", "11");
	CloseQuestHeader("APS");
	DeleteAttribute(pchar, "APS");
	sld = characterFromId("ApostatesDN");//смотрителя убираем
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 1.0);
}


void GothicApostatesAPSCPortoBelloOver(string qName)//опоздали
{
	pchar.questTemp.APS = "APS_usurerPortoBelloOver";
	pchar.quest.APS_usurerPortoBello.over = "yes";//снять прерывание
}

void GothicApostatesAPSCPortoBello(string qName)
{
	pchar.quest.APS_usurerPortoBelloOver.over = "yes";//снять прерывание
	pchar.questTemp.APS = "APS_usurerPortoBello";
}

void GothicApostatesAPSwaitOver(string qName)
{
                    LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	AddQuestRecord("APS", "11");
	CloseQuestHeader("APS");
	DeleteAttribute(pchar, "APS");
	sld = characterFromId("ApostatesDN");//смотрителя убираем
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 1.0);
}

//----------------------------Отступники веры золотой конвой-------------------------------------

void GothicApostatesAPSGoldShip()//создаем золотой конвой
{
	SetFunctionTimerCondition("APSGoldConvoy_Over", 0, 0, 25, false);
	AddQuestRecord("APS", "17");
	string sCapId = "APSGoldCap";
                     string sGroup = "Sea_" + sCapId + "1";
	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	pchar.questTemp.APS.Spa.GldQty = 1800 + rand(500);
	int iRank = 13+MOD_SKILL_ENEMY_RATE;
	int iScl = MOD_SKILL_ENEMY_RATE*2+30;
	for (int i = 1; i <= 3; i++)
                    {
	sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "citiz_41", "man", "man", iRank, SPAIN, 15, true, "soldier"));
	SetRandomNameToCharacter(sld);
	SetRandomNameToShip(sld);
	switch (i)
	{
	case 1: iTemp = SHIP_WARSCHOONER; break;
	case 2: iTemp = SHIP_ManowarV; break;
	case 3: iTemp = SHIP_CORVETTE; break;
	}
	sld.Ship.Type = GenerateShipExt(iTemp, 1, sld);
	SetBaseShipData(sld);
	SetCaptanModelByEncType(sld, "war");
	int hcrew = GetMaxCrewQuantity(sld);
	SetCrewQuantity(sld, hcrew);
	SetCrewQuantityFull(sld);
	sld.AlwaysEnemy = true;
	sld.DontRansackCaptain = true;
	sld.Coastal_Captain = true; //не ссорить нации
	sld.lifeDay = 15;
	sld.AnalizeShips = true;
	sld.WatchFort = true; //видеть форты
	sld.skill.Sailing = iScl+rand(10);
	sld.skill.Defence = iScl+rand(10);
	sld.skill.Accuracy = iScl+rand(10);
	sld.skill.Cannons = iScl+rand(10);
	sld.Ship.Crew.Morale = iScl+10;
	sld.Ship.Crew.Exp.Sailors = iScl;
	sld.Ship.Crew.Exp.Cannoners = iScl;
	sld.Ship.Crew.Exp.Soldiers = iScl;
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	if (MOD_SKILL_ENEMY_RATE > 6) SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "ShipSpeedUp");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	if (i == 2) SetCharacterGoods(sld, GOOD_GOLD, sti(pchar.questTemp.APS.Spa.GldQty));//положить в трюм золото
	sld.mapEnc.type = "war";
	sld.mapEnc.worldMapShip = "quest_ship";
                    sld.mapEnc.Name = "золотой конвой";
                    Group_AddCharacter(sGroup, sCapId + i);
	}
	Group_SetGroupCommander(sGroup, sCapId+ "1");
                     Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
                     Group_LockTask(sGroup);
	Map_CreateTrader("Shore101", "Shore109", sCapId + "1", 15);//запуск энкаунтера
	
	pchar.quest.APSGoldConvoy_Abordage.win_condition.l1 = "Character_Capture";
	pchar.quest.APSGoldConvoy_Abordage.win_condition.l1.character = "APSGoldCap2";
	pchar.quest.APSGoldConvoy_Abordage.function = "APSGoldConvoy_AfterBattle";//взяли на абордаж
	pchar.quest.APSGoldConvoy_Sink.win_condition.l1 = "Character_sink";
	pchar.quest.APSGoldConvoy_Sink.win_condition.l1.character = "APSGoldCap2";
	pchar.quest.APSGoldConvoy_Sink.function = "APSGoldConvoy_LinkorSink";//потопили
}

void APSGoldConvoy_AfterBattle(string qName)//после боя
{
	pchar.GenQuest.DontPartition = true; // отключить дележ
	pchar.quest.APSGoldConvoy_Over.over = "yes";
	int amount = sti(pchar.questTemp.APS.Spa.GldQty) - GetSquadronGoods(pchar, GOOD_GOLD);
	int iHal = 0;
	for(i = 0; i < COMPANION_MAX; i++)
	{
		iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
			sld = GetCharacter(iTemp);
			pchar.questTemp.APS.Spa.CompanionIndex = sld.Index;
			if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MANOWARV ) iHal++;
		}
	}
	if (iHal > 0)//признак наличия ТГ в компаньонах
	{
		/*
		if (amount <= 0)
		{
			AddQuestRecord("APS", "18");
		}
		else if (amount > 0 && amount < pchar.questTemp.APS.Spa.GldQty)
		{
			AddQuestRecord("APS", "18_2");
		}
		*/
		AddQuestRecord("APS", "18");
	}
	else
	{
		if (amount <= 0)
		{
			AddQuestRecord("APS", "18_1");
		}
		else 
		{
			if (amount > 0 && amount < sti(pchar.questTemp.APS.Spa.GldQty))
			{
				AddQuestRecord("APS", "18_2");
			}
		}
		else
		{
			AddQuestRecord("APS", "18_3");
		}
	}

	//AddQuestRecord("APS", "18");
	AddComplexSeaExpToScill(100, 100, 100, 100, 100, 100, 0);
	DoQuestCheckDelay("sea_victory", 1.5);
	ChangeCharacterComplexReputation(pchar, "fame", 1);
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_38";//после захвата продолжаем квест
}

void APSGoldConvoy_LinkorSink(string qName) // линкор потоплен = слив квеста
{
	pchar.GenQuest.DontPartition = true; // отключить дележ
	pchar.quest.APSGoldConvoy_Over.over = "yes";
	AddQuestRecord("APS", "18_3");
	AddComplexSeaExpToScill(100, 100, 100, 100, 100, 100, 0);
	DoQuestCheckDelay("sea_victory", 1.5);
	ChangeCharacterComplexReputation(pchar, "fame", 1);
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_38";//после захвата продолжаем квест
}

void APSGoldConvoy_Over(string qName)//опоздали или не нашли конвой
{
                    LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	pchar.quest.APSGoldConvoy_Abordage.over = "yes";
	pchar.quest.APSGoldConvoy_Sink.over = "yes";
	AddQuestRecord("APS", "19");
	CloseQuestHeader("APS");
	DeleteAttribute(pchar, "APS");
	sld = characterFromId("ApostatesDN");//смотрителя убираем
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 1.0);
}

void APSGoldConvoy_Remove()//удаляем товар и корабль
{
	AddQuestRecord("APS", "21");
	RemoveCharacterGoods(pchar, GOOD_GOLD, sti(pchar.questTemp.APS.Spa.GldQty));
	//удаляем мановар
	if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_MANOWARV)
	{
	pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
	pchar.Ship.name = "Лодка";
	SetBaseShipData(pchar);
	SetCrewQuantityOverMax(PChar, 0);//сажаем на тартану
	}
	else
	{
	for(i = 1; i < COMPANION_MAX; i++)
	{
	int iTemp = GetCompanionIndex(PChar, i);
	if(iTemp > 0)
	{
	ref chr = GetCharacter(iTemp);
	if(sti(RealShips[sti(chr.ship.type)].basetype) == SHIP_MANOWARV)
	{
	pchar.questTemp.APS.Spa.CompanionIndex = chr.Index;
	sld = GetCharacter(sti(pchar.questTemp.APS.Spa.CompanionIndex));
		}
	}
}
	RemoveCharacterCompanion(PChar, sld);
	AddPassenger(PChar, sld, false);//удалим тока 1 последний в списке ОИ - пусть будет хоть так
	}
}

void GothicApostatesAPS_Work(string qName)
{
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_40";
}

//--------Отступники веры промежуточный квест (Чарли Вейн )-------------------------------------

void CharlieVayneStart(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("GregSnow", "Bandit_1", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Грэг";
	sld.lastname = "Сноу";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "GregSnow";
	sld.greeting = "Gr_Tavern_Mate_1";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);
	FreeSitLocator("PortRoyal_tavern", "sit_base1");
	ChangeCharacterAddressGroup(sld, "PortRoyal_tavern", "sit", "sit_base1");
}

void CharlieVayneTalkWithSnow(string qName)
{
	sld = characterFromId("GregSnow");
	sld.Dialog.CurrentNode = "GregSnow_1";
	
	FreeSitLocator("PortRoyal_tavern", "sit_front1");
	ChangeCharacterAddressGroup(PChar, "PortRoyal_tavern", "sit", "sit_front1");
	LAi_SetSitType(PChar);
	LAi_SetActorType(sld);
	LAi_ActorSetSitMode(sld);
	LAi_ActorDialogNow(sld, PChar, "", -1);
}


void CharlieVayneTalkWithSnowEnd(string qName)
{
	AddQuestRecord("APSH", "3");
	sld = characterFromId("GregSnow");
	sld.lifeday = 0;
	LAi_SetSitType(sld);	
	LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "PortRoyal_tavern", "goto", "goto4");
			
	sld = GetCharacter(NPC_GenerateCharacter("GarrisOMayli", "Bandit_5", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Гаррис";
	sld.lastname = "О'Мэйли";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "GarrisOMayli";
	sld.greeting = "cit_common";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "HouseGarrisOMayli", "sit", "sit1");
}


void CharlieVayneFindRobertBlake()
{
	AddQuestRecord("APSH", "4");
	sld = CharacterFromID("GarrisOMayli");
	sld.lifeday = 0;

                     string sGroup = "Sea_RobertBlake1";
                     Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	sld = GetCharacter(NPC_GenerateCharacter("RobertBlake", "citiz_41", "man", "man", 20, PIRATE, 15, true, "quest"));
	FantomMakeSmallSailor(sld, SHIP_WARSCHOONER, "Лебедь", CANNON_TYPE_CANNON_LBS16, 50, 45, 45, 50, 60);
	sld.name = "Роберт";
	sld.lastname = "Блэйк";
	SetCaptanModelByEncType(sld, "war");
	LAi_SetHP(sld, 100+MOD_SKILL_ENEMY_RATE*30, 100+MOD_SKILL_ENEMY_RATE*30);
	sld.AlwaysEnemy = true;
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	sld.Coastal_Captain = true; //не ссорить нации
	sld.Ship.Crew.Morale = MOD_SKILL_ENEMY_RATE*10;
	sld.Ship.Crew.Exp.Sailors = MOD_SKILL_ENEMY_RATE*10;
	sld.Ship.Crew.Exp.Cannoners = MOD_SKILL_ENEMY_RATE*10;
	sld.Ship.Crew.Exp.Soldiers = MOD_SKILL_ENEMY_RATE*10;
	UpgradeShipParameter(sld, "SpeedRate");
	UpgradeShipParameter(sld, "Capacity");
	UpgradeShipParameter(sld, "WindAgainstSpeed");
	UpgradeShipParameter(sld, "TurnRate");
	if (MOD_SKILL_ENEMY_RATE > 4) TakeNItems(sld, "potion2", 3);
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "ShipSpeedUp");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	sld.mapEnc.type = "war";
	sld.mapEnc.worldMapShip = "quest_ship";
                     sld.mapEnc.Name = "шхуна 'Лебедь'";
                     Group_AddCharacter(sGroup, "RobertBlake");
	Group_SetGroupCommander(sGroup, "RobertBlake");
                     Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Map_CreateTrader("Shore46", "Shore131", "RobertBlake", 16);//запуск энкаунтера с лагуны Чирики до Сундука мертвеца
	pchar.quest.APSHRobertBlake_AfterBattle.win_condition.l1 = "Group_Death";
	pchar.quest.APSHRobertBlake_AfterBattle.win_condition.l1.group = sGroup;
	pchar.quest.APSHRobertBlake_AfterBattle.function = "APSHRobertBlake_AfterBattle";

}

void APSHRobertBlake_AfterBattle(string qName)//утопили Блэйка
{
	pchar.quest.APSHRobertBlakeOnMapOver.over = "yes";
	Group_DeleteGroup("Sea_RobertBlake1");
	Log_testInfo("ЛЕБЕДЬ УТОНУЛ!");
	AddQuestRecord("APSH", "6");
	CloseQuestHeader("APSH");
}

void APSHRobertBlakeOnMapOver(string qName)//не перехватили Блэйка
{
	pchar.quest.APSHRobertBlake_AfterBattle.over = "yes"; //снять прерывание
	Group_DeleteGroup("Sea_RobertBlake1");
	AddQuestRecord("APSH", "7");
	CloseQuestHeader("APSH");
}

void APSH_Ruins6(string qName)
{
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_62";
}

void GothicAPSH_architects(string qName)
{
	sld = characterFromId("Myxir");
	// вернуть после всего
	// ch.location	= "LibraryHouse";
	// ch.location.group = "goto";
	// ch.location.locator = "goto1";
	//
	//
	// sld.dialog.filename = "Gothic_Quest\Gothic_npc\Myxir.c";
	sld.dialog.currentnode = "APSH_Myxir_table_2";
}

void APSH_SharliVein_Iroquois(string qName)
{
	// костер
	ref rItm = ItemsFromID("fire");
	rItm.shown = true;
	rItm.startLocation = "Shore127";
	rItm.startLocator = "fire";
	CreateFireParticles("goto", "fire"); //костер
                     DoQuestFunctionDelay("APSH_SharliVein_Iroquois_1", 7.0);
}

void APSH_SharliVein_Iroquois_1(string qName)
{
	sld = characterFromId("APSHIroquois_1");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "APSH_Ruins_Iroquois", 3.5);

	sld = characterFromId("APSHIroquois_2");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "APSH_Ruins_Iroquois", 3.5);
}

void APSH_Iroquois(string qName)
{
                     chrDisableReloadToLocation = true;
	PlaySound("interface\abordage_wining.wav");
	for (int i=1; i<=8; i++) 
	{
	if (i < 4)
	{
	sld = GetCharacter(NPC_GenerateCharacter("APSHIroquois_"+i, "mush_iroquois_"+i, "man", "mushketer", 25, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld, 25, 70, 70, "", "mushket1", "cartridge", 170);
	LAi_SetCharacterUseBullet(sld, "cartridge");
	if (MOD_SKILL_ENEMY_RATE > 2) sld.cirassId = Items_FindItemIdx("cirass1");
	}
	else
	{
	sld = GetCharacter(NPC_GenerateCharacter("APSHIroquois_"+i, "Iroquois_"+(rand(5)+1), "man", "man", 25, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld, 25, 70, 70, LinkRandPhrase("slave_01","slave_02","topor_05"), "pistol3", "grapeshot", 50);
	if (MOD_SKILL_ENEMY_RATE > 2) sld.cirassId = Items_FindItemIdx("cirass2");
	}
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	ChangeCharacterAddressGroup(sld, "Shore127", "reload", "reload1_back");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	LAi_group_SetCheck("EnemyFight", "APSHIroquois1");
}

void GothicAPSH_ReadMyxirNotice() // нашли заклятие стражи мёртвых
{
                     if (PChar.location == "church IM2")
	{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
                     DoQuestFunctionDelay("GothicAPSH_ReadMyxirNotice_1", 3.0);
                     }
	else 
	{
	PlaySound("interface\knock.wav");
	log_info("Для вызова духа необходимa деревня в заливе Крейт");
                     PlaySound("VOICE\Russian\GOTHIC\GG\DOESNTWORK.wav");
	}
}

void GothicAPSH_ReadMyxirNotice_1(string qName)
{
                 PlaySound("VOICE\Russian\gotica\SFX\MFX_BARRIERE_SHOOT.wav");
                 DoQuestFunctionDelay("GothicAPSH_ReadMyxirNotice_2", 2.0);
}

void GothicAPSH_ReadMyxirNotice_2(string qName)
{
                 chrDisableReloadToLocation = true;
                 PlaySound("VOICE\Russian\GOTHIC\GG\STONEPLATE_2.wav");
                 Log_Info("Я приказываю тебе Чарли Вейн явится в мир живых ...");
                 pchar.questTemp.Gothic.APSHMyxirNotice = "true";
                 RemoveItems(PChar, "APSHMyxirNotice", 1);
                 DoQuestFunctionDelay("APSH_Ruins_SharliVein", 2.0);
}

void APSH_Ruins_SharliVein(string qName)
{
                    LAi_SetActorType(pchar);
                    LAi_ActorTurnToLocator(pchar, "quest", "LLquest1");
 	PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
	PlaySound("Weather\Thunder_Q.wav");
	CreateLocationParticles("fire_incas_Simple", "quest", "LLquest1", 0.5, 0, 0, "");
	CreateLocationParticles("fire_incas_Simple", "quest", "LLquest1", 1.0, 0, 0, "");
	CreateLocationParticles("fire_incas_Simple", "quest", "LLquest1", 1.5, 0, 0, "");
	CreateLocationParticles("Firering", "quest", "LLquest1", 1.0, 0, 0, "");
	DoQuestCheckDelay("APSH_Ruins8", 1.2);
}

void APSH_SharliVein_ATTACK(string qName)
{
	 sld = characterFromId("SharliVein");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");

                     LAi_group_MoveCharacter(sld, "EnemyFight");
                     LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
                     LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "APSH_SharliVein_dead");
                     LAi_SetFightMode(pchar, true);
	DoQuestFunctionDelay("APSH_SharliVein_ATTACK_1", 0.1);
}

void APSH_SharliVein_ATTACK_1(string qName)
{
                     PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
	CreateLocationParticles("item", "reload", "reload2_back", 1.20, 2, 2, "");
	CreateLocationParticles("item", "reload", "reload3_back", 1.20, 2, 2, "");
	CreateLocationParticles("fire_incas_Simple", "goto", sTemp, 0.5, 0, 0, "");
                     DoQuestFunctionDelay("APSH_SharliVein_ATTACK_2", 4.0);
}

void APSH_SharliVein_ATTACK_2(string qName) //
{
	                     sld = GetCharacter(NPC_GenerateCharacter("SharliVeinmush_1", "mush_skel_1", "man", "mushketer", 40, PIRATE, -1, true, "quest"));
	                     FantomMakeCoolFighter(sld, 40, 100, 100, "", "mushket1", "cartridge", 70);
		LAi_SetCharacterUseBullet(sld, "cartridge");
	                    TakeNItems(sld, "GunPowder", 56);
	                     SetCharacterPerk(sld, "Gunman");
		sld.monster = true; 
		sld.LSC_clan = true;
	                     sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	                     sld.DontClearDead = true;
		LAi_CharacterDisableDialog(sld);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	                    ChangeCharacterAddressGroup(sld, "church IM2", "reload", "reload2_back");

	                     sld = GetCharacter(NPC_GenerateCharacter("SharliVeinmush_2", "mush_skel_2", "man", "mushketer", 40, PIRATE, -1, true, "quest"));
	                     FantomMakeCoolFighter(sld, 40, 100, 100, "", "mushket1", "cartridge", 70);
		LAi_SetCharacterUseBullet(sld, "cartridge");
	                    TakeNItems(sld, "GunPowder", 56);
	                     SetCharacterPerk(sld, "Gunman");
		sld.monster = true; 
		sld.LSC_clan = true;
	                     sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	                     sld.DontClearDead = true;
		LAi_CharacterDisableDialog(sld);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	                    ChangeCharacterAddressGroup(sld, "church IM2", "reload", "reload3_back");
}

void APSH_SharliVeinDestiny()
{
                 DoQuestFunctionDelay("APSH_SharliVeinDestiny_1", 1.0);
}

void APSH_SharliVeinDestiny_1()
{
	TakeNItems(PChar, "mapSharliVein", -1);
	Log_Info("Сокровища Чарли Вейна где - то рядом.");
}


//--------Отступники веры продолжаем-------------------------------------

void GothicApostatesAPS_Jamaica(string qName) 
{
	Flag_PIRATE();
	bQuestDisableMapEnter = true;//закрыть карту
	Island_SetReloadEnableGlobal("Jamaica", false);//на остров нельзя
	DoQuestFunctionDelay("GothicApostatesAPS_Jamaica_2", 10.0);

	Group_FindOrCreateGroup("GothicApostatesAPS_GoldSeaGroup");
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+7;
	if (iRank > 45) iRank = 45;
	int iShip, Ship1, Ship3, iCannon, Cannon1, Cannon2, iSpace;
	
	
	switch (MOD_SKILL_ENEMY_RATE)
	{
		case 2:
			Ship1 = SHIP_FRIGATE;
			Ship3 = SHIP_FRIGATE_H;
			Cannon1 = CANNON_TYPE_CANNON_LBS20;
			Cannon2 = CANNON_TYPE_CANNON_LBS16;
		break;
		
		case 4:
			Ship1 = SHIP_CORVETTE;
			Ship3 = SHIP_WARSCHOONER;
			Cannon1 = CANNON_TYPE_CULVERINE_LBS18;
			Cannon2 = CANNON_TYPE_CANNON_LBS20;
		break;
		
		case 6:
			Ship1 = SHIP_NAVIO;
			Ship3 = SHIP_HEAVYGALEON;
			Cannon1 = CANNON_TYPE_CANNON_LBS24;
			Cannon2 = CANNON_TYPE_CULVERINE_LBS18;
		break;
		
		case 8:
			Ship1 = SHIP_FRIGATE;
			Ship3 = SHIP_FRIGATE;
			Cannon1 = CANNON_TYPE_CANNON_LBS32;
			Cannon2 = CANNON_TYPE_CANNON_LBS24;
		break;
		
		case 10:
			Ship1 = SHIP_BATTLEGALEON;
			Ship3 = SHIP_POLACRE;
			Cannon1 = CANNON_TYPE_CANNON_LBS32;
			Cannon2 = CANNON_TYPE_CANNON_LBS16;
		break;
	}
	
	for (int i=1; i<=3; i++)
	{
		switch (i)
		{
			case 1:
				iShip = Ship1;
				iCannon = Cannon1;
			break;
			
			case 2:
				iShip = SHIP_LSHIP_SPA;
				iCannon = CANNON_TYPE_CANNON_LBS24;
				if (MOD_SKILL_ENEMY_RATE < 4) iCannon = CANNON_TYPE_CULVERINE_LBS18;
			break;
			
			case 3:
				iShip = Ship3;
				iCannon = Cannon2;
			break;
		}
		sld = GetCharacter(NPC_GenerateCharacter("GothicApostatesAPS_GoldCap_"+i, "off_spa_"+i, "man", "man", iRank, SPAIN, -1, true, "quest"));
		FantomMakeCoolSailor(sld, iShip, "", iCannon, 80, 80, 80);
		FantomMakeCoolFighter(sld, iRank, 100, 100, LinkRandPhrase("blade_17","blade_20","blade_21"), "pistol5", "bullet", 250);
		DeleteAttribute(sld, "SaveItemsForDead");
		DeleteAttribute(sld, "DontClearDead");
		sld.DontRansackCaptain = true;
		sld.AnalizeShips = true;
		sld.AlwaysEnemy = true;
		sld.Ship.Mode = "war";
		sld.ship.Crew.Morale = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Sailors = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Cannoners = 60+MOD_SKILL_ENEMY_RATE*4;
		sld.Ship.Crew.Exp.Soldiers = 60+MOD_SKILL_ENEMY_RATE*4;
		if (MOD_SKILL_ENEMY_RATE > 4) SetCharacterPerk(sld, "MusketsShoot");
		if (i == 1) 
		{
			iSpace = GetCharacterFreeSpace(sld, GOOD_PAPRIKA);
			iSpace = makeint(iSpace/2 + rand(iSpace/2));
			Fantom_SetCharacterGoods(sld, GOOD_PAPRIKA, iSpace, 1);
		}
		if (i == 2) 
		{
			sld.ship.name = "Инквизитор";
			UpgradeShipParameter(sld, "Capacity");
			SetRandGeraldSail(sld, SPAIN);
			NullCharacterGoods(sld);
			AddCharacterGoods(sld, GOOD_BALLS, 1500);
			AddCharacterGoods(sld, GOOD_GRAPES, 1000);
			AddCharacterGoods(sld, GOOD_KNIPPELS, 800);
			AddCharacterGoods(sld, GOOD_BOMBS, 1700);
			AddCharacterGoods(sld, GOOD_POWDER, 5000);
			AddCharacterGoods(sld, GOOD_WEAPON, 700);
			AddCharacterGoods(sld, GOOD_FOOD, 1000);
			AddCharacterGoods(sld, GOOD_MEDICAMENT, 250);
			AddCharacterGoods(sld, GOOD_RUM, 100);
		}
		if (i == 3) 
		{
			iSpace = GetCharacterFreeSpace(sld, GOOD_TOBACCO);
			iSpace = makeint(iSpace/2 + rand(iSpace/2));
			Fantom_SetCharacterGoods(sld, GOOD_TOBACCO, iSpace, 1);
		}
		Group_AddCharacter("GothicApostatesAPS_GoldSeaGroup", "GothicApostatesAPS_GoldCap_"+i);
	}
	Group_SetAddress("GothicApostatesAPS_GoldSeaGroup", "Jamaica", "Quest_Ships", "quest_ship_20");
	Group_AddCharacter("GothicApostatesAPS_GoldSeaGroup", "GothicApostatesAPS_GoldCap_1");
    Group_SetGroupCommander("GothicApostatesAPS_GoldSeaGroup", "GothicApostatesAPS_GoldCap_1");
	Group_SetTaskAttack("GothicApostatesAPS_GoldSeaGroup", PLAYER_GROUP);
    Group_LockTask("GothicApostatesAPS_GoldSeaGroup");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	Sea_LoginGroupCurrentSea("GothicApostatesAPS_GoldSeaGroup");

}

void GothicApostatesAPS_Jamaica_2(string qName) //бой с инквизиией
{
	log_info("Испанский конвой на горизонте!");
	PlaySound("interface\notebook.wav");
	PlaySound("interface\_EvEnemy0.wav");
	PlaySound("interface\shipsbell.wav");
	DoQuestFunctionDelay("GothicApostatesAPS_GoldSeaGroupSound", 10.0);
	// на корабль Магистра
	/*
	int Hour = 2;
	if (MOD_SKILL_ENEMY_RATE < 4) Hour = 1;
	if (MOD_SKILL_ENEMY_RATE > 6) Hour = 3;
	*/
	int Hour = 1;
	Log_Info("Силы не равные, постарайтесь продержаться, братья своих не бросают.");
	pchar.quest.GothicApostatesAPS_boss.win_condition.l1 = "Timer";
	pchar.quest.GothicApostatesAPS_boss.win_condition.l1.date.hour  = sti(GetTime() + Hour);
	pchar.quest.GothicApostatesAPS_boss.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
	pchar.quest.GothicApostatesAPS_boss.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	pchar.quest.GothicApostatesAPS_boss.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
	pchar.quest.GothicApostatesAPS_boss.function = "GothicApostatesAPS_Jamaica_3";
	// реакции
	pchar.quest.GothicApostatesAPS_goldcheck.win_condition.l1 = "Group_Death";
	pchar.quest.GothicApostatesAPS_goldcheck.win_condition.l1.group = "GothicApostatesAPS_GoldSeaGroup";
	pchar.quest.GothicApostatesAPS_goldcheck.function = "GothicApostatesAPSGoldCheck";
}

void GothicApostatesAPS_GoldSeaGroupSound(string qName)
{
	PlaySound("interface\shipsbell.wav");
                     PlaySound("interface\SeaDogs.wav");
}


void GothicApostatesAPS_Jamaica_3(string qName)
{
	Log_Info("Магистр спешит на помощь");
	Group_FindOrCreateGroup("ApostatesRK_SeaGroup");
	sld = CharacterFromID("ApostatesRK");
	FantomMakeCoolSailor(sld, SHIP_ManowarV, "Гильдия Масон", CANNON_TYPE_CULVERINE_LBS36, 110, 110, 110);
	FantomMakeCoolFighter(sld, 50, 110, 110, "blade_19", "pistol4", "bullet", 300);
	sld.DeckDialogNode = "GothicApostatesAPS_quests_ship";
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "WindCatcher");
	SetCharacterPerk(sld, "SailsMan");
	SetCharacterPerk(sld, "SailingProfessional");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "Carpenter");
	SetCharacterPerk(sld, "Builder");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	GothicApostatesAPS_ApostatesRKSetShipParameter();
	SetCharacterGoods(sld, GOOD_BALLS, 3500);
	SetCharacterGoods(sld, GOOD_GRAPES, 2000);
	SetCharacterGoods(sld, GOOD_KNIPPELS, 1500);
	SetCharacterGoods(sld, GOOD_BOMBS, 3500);
	SetCharacterGoods(sld, GOOD_POWDER, 10500);
	SetCharacterGoods(sld, GOOD_WEAPON, 1000);
	SetCharacterGoods(sld, GOOD_FOOD, 2000);
	SetCharacterGoods(sld, GOOD_MEDICAMENT, 700);
	SetCharacterGoods(sld, GOOD_RUM, 200);
	SetCharacterGoods(sld, GOOD_PLANKS, 100);
	SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
	sld.AlwaysSandbankManeuver = true;
	Character_SetAbordageEnable(sld, false); // нельзя абордировать
	sld.Tasks.CanBoarding = false; // запрет идти на абордаж - дубль
	sld.Tasks.CanChangeShipAfterBoarding = false; // запрет меняться кораблями - дубль
	sld.Ship.Mode = "mercenary";
	sld.Abordage.Enable = false;
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable = true; 
	sld.DontDeskTalk = true;
	LAi_SetImmortal(sld, false);
	sld.ShipHideImmortal = 1000; // непотопляемый корабль
	sld.SeaBoss = 0.8; // получает на 80% меньше урона корпусу, 10% урона парусам
	Group_AddCharacter("ApostatesRK_SeaGroup", "ApostatesRK");
	Group_SetGroupCommander("ApostatesRK_SeaGroup", "ApostatesRK");
	Group_SetTaskAttack("ApostatesRK_SeaGroup", "GothicApostatesAPS_GoldSeaGroup");
	Group_LockTask("ApostatesRK_SeaGroup");
	//Group_SetAddress("GothicApostatesAPS_GoldSeaGroup", "Jamaica", "quest_ships", "quest_ship_7");
	Sea_LoginGroupCurrentSea("ApostatesRK_SeaGroup");
	DoQuestFunctionDelay("GothicApostatesAPSApostatesRKCommand", 3.0);
	pchar.quest.GothicApostatesAPS_ship_fail.win_condition.l1 = "NPC_Death";
	pchar.quest.GothicApostatesAPS_ship_fail.win_condition.l1.character = "ApostatesRK";
	pchar.quest.GothicApostatesAPS_ship_fail.function = "GothicApostatesAPS_ApostatesRKGameOver"; // для шибко грамотных
}

void GothicApostatesAPS_ApostatesRKGameOver(string qName) // прибьем корабль особо умных, чтобы не выделывались
{
	Log_Info("На корабле "+pchar.ship.name+" взорвалась крюйт-камера!");
	Ship_Detonate(pchar, true, true); 
	PlaySound("Sea Battles\Vzriv_fort_001.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
}

void GothicApostatesAPS_ApostatesRKSetShipParameter()
{
	sld = CharacterFromID("ApostatesRK");
	SetSelfSkill(sld, 90, 90, 90, 90, 90);
	SetShipSkill(sld, 75, 90, 100, 100, 100, 100, 100, 100, 80);
	RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;
	RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 56;
	RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
	RealShips[sti(sld.Ship.Type)].SpeedRate = 13.5;
	RealShips[sti(sld.Ship.Type)].TurnRate = 29.5;
	RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
	RealShips[sti(sld.Ship.Type)].HP = 8000;
	RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 0.42;
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 2;
	SetSailsColor(sld, 8);//черный парус
                     SetRandGeraldSail(sld, PIRATE);//Гербы
	UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
	UpgradeShipParameter(sld, "TurnRate");//маневренность
	UpgradeShipParameter(sld, "WindAgainstSpeed");//бейд
	DeleteAttribute(sld, "ship.hulls");
	int hcrew = GetMaxCrewQuantity(sld);
	SetCrewQuantity(sld, hcrew);
	sld.Ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
}

void GothicApostatesAPSApostatesRKCommand(string qName) // 
{
	PlaySound("interface\shipsbell.wav");
                     PlaySound("interface\SeaDogs.wav");
	ref chr = CharacterFromID("ApostatesRK");
	sld = CharacterFromID("GothicApostatesAPS_GoldCap_1");
	Ship_SetTaskAttack(SECONDARY_TASK, sti(chr.index), sti(sld.index));
	SetCharacterRemovable(chr, false);
	chr.CompanionEnemyEnable = false; //всегда друзья
	SetCompanionIndex(pchar, -1, sti(chr.index));
	chr.loyality = MAX_LOYALITY;
}

void GothicApostatesAPSGoldCheck(string qName)
{
    	AddQuestRecord("APS", "25");
	pchar.quest.GothicApostatesAPS_ship_fail.over = "yes"; 
	Group_DeleteGroup("GothicApostatesAPS_GoldSeaGroup");
	pchar.GenQuest.MapClosedNoBattle = true;	
	sld = CharacterFromID("ApostatesRK");
	DeleteAttribute(sld, "DontDeskTalk");
	RemoveCharacterCompanion(pchar, sld);
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable = true; 
	LAi_SetImmortal(sld, true);
	Group_AddCharacter("ApostatesRK_SeaGroup", "ApostatesRK");
	Group_SetGroupCommander("ApostatesRK_SeaGroup", "ApostatesRK");
	Group_SetTaskNone("ApostatesRK_SeaGroup");
	Group_LockTask("ApostatesRK_SeaGroup");

}

void GothicApostatesAPSComplete(string qName)
{
	Group_DelCharacter("ApostatesRK_SeaGroup", "ApostatesRK");
	Group_DeleteGroup("ApostatesRK_SeaGroup");
	// НЗГ
	ChangeCharacterComplexReputation(pchar, "nobility", 1);
	ChangeCharacterComplexReputation(pchar, "authority", 2);
	ChangeCharacterComplexReputation(pchar, "fame", 2);
	OfficersReaction("bad");
	OfficersReaction("bad");
	ChangeCharacterHunterScore(PChar, "spahunter", 20);
}


void CheckIslandAPS_Coordinates(string qName)//проверка наличия координат острова у ГГ
{
	bQuestDisableMapEnter = false;//открыть карту
	Island_SetReloadEnableGlobal("Jamaica", true);
	AddQuestRecord("APS", "26");
	pchar.questTemp.GothicAPS_Coordinates = "true"; //атрибут координат на поиск острова через каюту
	SetFunctionTimerCondition("APS_Shore_Over", 0, 0, 2, false);
	PChar.quest.GothicApostatesAPS_Shore.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPS_Shore.win_condition.l1.location = "Shore85";
	PChar.quest.GothicApostatesAPS_Shore.win_condition.l1.locator_group = "encdetector";
	PChar.quest.GothicApostatesAPS_Shore.win_condition.l1.locator = "enc01";
	PChar.quest.GothicApostatesAPS_Shore.function = "GothicApostatesAPS_Jamaica_4";

}

void GothicAPSPrepareSearchingFor()//подготовка-сценка
{
	chrDisableReloadToLocation = true;//закрыть локацию
	LAi_SetBarmanType(pchar);
	DoQuestCheckDelay("TalkSelf_Quest", 15.0);
}

void GothicAPSSearchingForIslandOnMap(string qName)//подготовим остров к посещению
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\IRDORATHTHEREYOUARE.wav");
	AddQuestRecord("APS", "27");
	chrDisableReloadToLocation = false;//открыть локацию
	i = FindIsland("Providence");//ждет своего героя!
	Islands[i].visible = true;
	Islands[i].reload_enable = true;
                     DeleteAttribute(pchar, "questTemp.GothicAPS_FindIsland"); // 021012
                     sld = characterFromID("ApostatesRK");//ставим Магистра в резиденцию
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_70";
	ChangeCharacterAddressGroup(sld, "SanAndres_townhall_port", "sit", "sit1");
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

                     sld = characterFromID("ApostatesLA");
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "W_headclerk";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit4");
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

}

void GothicApostatesAPS_FortOrangetown()
{
	StartQuestMovie(false, false, true);
	LAi_SetActorType(pchar);
	LAi_ActorGoTolocator(pchar, "patrol", "patrol5", "GothicApostatesAPS_FortOrangetown_1", -1);
}

void GothicApostatesAPS_FortOrangeBank()
{
                    LocatorReloadEnterDisable("PortAntonio_town", "reload8_back", true);//закроем банк
	CreateLocationParticles("large_smoke", "reload", "reload2", 0.5, 0, 0, "");
	CreateLocationParticles("shipfire", "reload", "reload2", 0.5, 0, 0, "fortfire");
}

//скрытый квест на добивку
void GothicApostatesAPS_Jamaica_4(string qName) ставим инквизитора с его друзьями
{
	LAi_LocationFightDisable(&Locations[FindLocation("Shore85")], true);//запретить драться
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+5;
	int iScl = 30 + 2*sti(pchar.rank);
	sld = characterFromId("ApostatesFB");
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_FB_Shore";
	LAi_CharacterEnableDialog(sld);
	LAi_SetImmortal(sld, false);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetCurHPMax(sld);
	ChangeCharacterAddressGroup(sld, "Shore85", "quest", "SharpSeekSpy");
	LAi_SetGuardianType(sld);
	sld.protector = true;
	sld.protector.CheckAlways = 1;//всегда проверять
	sld.viper = true;
	if (MOD_SKILL_ENEMY_RATE > 2)
	{
		sld.MultiFighter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
		sld.MultiShooter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
	}
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.money = 2900;
	RemoveItems(sld, "potion2", GetCharacterItem(sld, "potion2"));
	RemoveItems(sld, "potion3", GetCharacterItem(sld, "potion3"));
	TakeNItems(sld, "potion2", makeint(MOD_SKILL_ENEMY_RATE/2));
	TakeNItems(sld, "potion3", 2);
	if (MOD_SKILL_ENEMY_RATE > 4) TakeNItems(sld, "potion4", 2);
	TakeNItems(sld, "indian_poison", 1); // яд таино
	TakeNItems(sld, "purse3", 1);
	TakeNItems(sld, "map_jam", 1);
	TakeNItems(sld, "cannabis7", 3);

	sld = characterFromId("ApostatesNI");
	LAi_CharacterEnableDialog(sld);
	LAi_SetImmortal(sld, false);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetCurHPMax(sld);
	ChangeCharacterAddressGroup(sld, "Shore85", "goto", "goto5");
	LAi_SetStayType(sld);
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	LAi_CharacterDisableDialog(sld);
	sld.viper = true;
	if (MOD_SKILL_ENEMY_RATE > 2)
	{
		sld.MultiFighter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
		sld.MultiShooter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
	}

	sld = characterFromId("Apostates_Monk3");
	LAi_CharacterEnableDialog(sld);
	LAi_SetImmortal(sld, false);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetCurHPMax(sld);
	ChangeCharacterAddressGroup(sld, "Shore85", "quest", "quest2");
	LAi_SetGuardianType(sld);
	LAi_SetStayType(sld);
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	LAi_CharacterDisableDialog(sld);
	sld.viper = true;
	if (MOD_SKILL_ENEMY_RATE > 2)
	{
		sld.MultiFighter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
		sld.MultiShooter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
	}
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_SpOfficer", "off_spa_4", "man", "man", 10, SPAIN, -1, true, "quest"));
                     FantomMakeCoolFighter(sld, 25, 70, 60, BLADE_LONG, "pistol2", "grapeshot", 20);
	LAi_CharacterEnableDialog(sld);
	LAi_SetImmortal(sld, false);
	LAi_RemoveCheckMinHP(sld);
	LAi_SetCurHPMax(sld);
	ChangeCharacterAddressGroup(sld, "Shore85", "goto", "goto6");
	LAi_SetGuardianType(sld);
	LAi_SetStayType(sld);
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	LAi_CharacterDisableDialog(sld);
	sld.viper = true;
	if (MOD_SKILL_ENEMY_RATE > 2)
	{
		sld.MultiFighter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
		sld.MultiShooter = 1.0+stf(MOD_SKILL_ENEMY_RATE/10);
	}
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;

}


void GothicApostatesAPS_Jamaica_5() // бой с остатками инквизиции
{
	LAi_LocationFightDisable(&Locations[FindLocation("Shore85")], false);
	chrDisableReloadToLocation = true;
	LAi_group_Delete("EnemyFight");
	sld = characterFromId("ApostatesFB");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");

	sld = characterFromId("ApostatesNI");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");

	sld = characterFromId("Apostates_Monk3");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");

	sld = characterFromId("Apostates_SpOfficer");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");

	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "GothicApostatesAPS_Jamaica_6");
	LAi_SetFightMode(pchar, true);
}

void APS_Shore_Over()
{
	sld = characterFromId("ApostatesFB");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 0.1);

	sld = characterFromId("ApostatesNI");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 0.1);

	sld = characterFromId("Apostates_Monk3");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 0.1);

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_SpOfficer", "off_spa_4", "man", "man", 10, SPAIN, -1, true, "quest"));
                     FantomMakeCoolFighter(sld, 25, 70, 60, BLADE_LONG, "pistol2", "grapeshot", 20);
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 0.1);

}

void GothicApostatesAPS_SanAndres_1(string qName)
{
	LAi_SetPlayerType(PChar);
                     SetFunctionTimerCondition("GothicApostatesAPS_SanAndres_2", 0, 0, 1, false);
	//ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto1");

	Group_FindOrCreateGroup("Providence_GuardAdd");
	Group_SetType("Providence_GuardAdd", "pirate");
	sld = GetCharacter(NPC_GenerateCharacter("ProvidenceGuardCapAdd", "Apostates_1", "man", "man2", 40, PIRATE, -1, true, "quest"));
	sld.name = "Фредерик";
	sld.lastname = "Бамер";
	FantomMakeSmallSailor(sld, SHIP_MANOWARV, "Гильдия Масон", CANNON_TYPE_CANNON_LBS42, 90+rand(10), 80+rand(20), 80+rand(20), 80+rand(15), 75+rand(25));
	SetFantomParamFromRank(sld, 40, true); 
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	sld.DontRansackCaptain = true;
	sld.AlwaysFriend = true;
	SetCharacterPerk(sld, "MusketsShoot");
	sld.AnalizeShips = true;
	sld.DontHitInStorm = true; // не ломается в шторм
	sld.SinkTenPercent = false;
	sld.Abordage.Enable = false; // запрет абордажа
	sld.AlwaysSandbankManeuver = true;
	sld.CompanionEnemyEnable = false; //всегда друзья
	sld.MultiFighter = 2.5; // мультифайтер
	sld.ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
	Group_AddCharacter("Providence_GuardAdd", "ProvidenceGuardCapAdd");
	Group_SetGroupCommander("Providence_GuardAdd", "ProvidenceGuardCapAdd");
	Group_SetTaskNone("Providence_GuardAdd");//нет задачи
	Group_SetAddress("Providence_GuardAdd", "Providence", "Islandships1", "ship_1");

}

void GothicApostatesAPS_SanAndres_2(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_90";
	
	PChar.quest.GothicObsessionFisrtBattle.win_condition.l1 = "location";
	PChar.quest.GothicObsessionFisrtBattle.win_condition.l1.location = "PortPax_Graveyard";
	PChar.quest.GothicObsessionFisrtBattle.function = "GothicObsessionFisrtBattle";
}

void GothicApostatesAPS_SanAndres_3(string qName)
{
	AddQuestRecord("Obsession", "1");
}

void GothicApostatesAPS_SanAndres_4(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_122";
	
	FreeSitLocator("SanAndres_TownhallRoom", "sit2");
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "sit", "sit2");
	LAi_SetSitType(PChar);
	LAi_SetActorType(sld);
	LAi_ActorSetSitMode(sld);
	LAi_ActorDialogNow(sld, PChar, "", -1);
}

void GothicApostatesAPS_SanAndres_5(string qName)
{
                     SetFunctionTimerCondition("GothicApostatesAPS_SanAndres_6", 0, 0, 1, false);
	LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto8");

}

void GothicApostatesAPS_SanAndres_6(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_130";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  квест древние усыпальницы
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void GothicApostatesAPS_architects(string qName)
{
      LocatorReloadEnterDisable("Shore81", "reload2_back", false);//откроем пещеру в бухта Понсе
      AddQuestRecord("Architects", "1");
      PChar.quest.StrangeGrotto_00.win_condition.l1 = "locator";
      PChar.quest.StrangeGrotto_00.win_condition.l1.location = "Strange_Grotto_1";
      PChar.quest.StrangeGrotto_00.win_condition.l1.locator_group = "quest";
      PChar.quest.StrangeGrotto_00.win_condition.l1.locator = "quest2";
      PChar.quest.StrangeGrotto_00.function = "StrangeGrotto_00";

}

void StrangeGrotto_00(string qName)
{
      PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_IN.wav");
      DoQuestFunctionDelay("StrangeGrotto_01", 1.5);
}

void StrangeGrotto_01(string qName)
{
        chrDisableReloadToLocation = true;
         log_info("Вы нашли пюпитры Замка учёных (Библиотека)!");
         TakeNItems(pchar, "architects_table_2", 1);

         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
         DoQuestFunctionDelay("StrangeGrotto_02", 1.5);
}

void StrangeGrotto_02(string qName)
{
	CreateLocationParticles("ShipExplode", "quest", "quest1", 1.0, 0, 0, "boom");
	CreateLocationParticles("blast_inv", "item", "button02", 1.0, 0, 0, "");
	CreateLocationParticles("blast_dirt", "item", "button02", 1.0, 0, 0, "");
	CreateFireParticles("item", "button02");

                      PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_OUT.wav");
                      DoQuestFunctionDelay("StrangeGrotto_03", 3.5);

	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "jump", "SitInGrot", 1.0);
	ChangeCharacterAddressGroup(Pchar, "Strange_Grotto_1", "reload", "reload5");
	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/3;
                     PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_DEAD.wav");
}

void StrangeGrotto_03(string qName)
{
	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "Ground_StandUp", "", 3.5);
	CreateLocationParticles("large_smoke", "goto", "locator1", 1.15, 0, 0, "");

                     PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_2.wav");
                     DoQuestFunctionDelay("StrangeGrotto_04", 3.8);
}

void StrangeGrotto_04(string qName)
{
                     PlaySound("VOICE\Russian\gotica\SFX\ORC_HAPPY01.wav");
	LAi_group_Delete("EnemyFight");
	PlaySound("ambient\horror\horror2.wav");
	LAi_SetStayType(Pchar);
	sld = GetCharacter(NPC_GenerateCharacter("Orc_table", "Orc", "man", "skeleton", 20+MOD_SKILL_ENEMY_RATE*3, PIRATE, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 20+MOD_SKILL_ENEMY_RATE*3, 70, 70, "blade53", "pistol05", "bullet", MOD_SKILL_ENEMY_RATE*60);
                    TakeNItems(sld, "GunPowder", 56);
	SetCharacterPerk(sld, "Gunman");
	sld.name = "Orc";
	sld.lastname = "";
	sld.greeting = "";
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	sld.monster = true; // признак нежити
	sld.MultiFighter = 1.0+MOD_SKILL_ENEMY_RATE/20; // мультифайтер
	ChangeCharacterAddressGroup(sld, "Strange_Grotto_1", "goto", "locator1");
	LAi_SetActorType(sld);
	LAi_ActorAnimation(sld, "Ground_sitting", "Orc_tableStandUp", 1.0);
}

void GothicApostatesAPS_architects_2()
{
      LocatorReloadEnterDisable("Shore130", "reload1_back", false);//откроем пещеру пляжа Шарлотвилл
      AddQuestRecord("Architects", "2");
      PChar.quest.StrangeGrotto_06.win_condition.l1 = "locator";
      PChar.quest.StrangeGrotto_06.win_condition.l1.location = "Strange_Grotto_2";
      PChar.quest.StrangeGrotto_06.win_condition.l1.locator_group = "quest";
      PChar.quest.StrangeGrotto_06.win_condition.l1.locator = "quest2";
      PChar.quest.StrangeGrotto_06.function = "StrangeGrotto_06";
}

void StrangeGrotto_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_IN.wav");
   DoQuestFunctionDelay("StrangeGrotto_07", 1.5);
}

void StrangeGrotto_07(string qName)
{
        chrDisableReloadToLocation = true;
         log_info("Вы нашли пюпитры Замка учёных (Библиотека)!");
         TakeNItems(pchar, "architects_table_3", 1);

         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
         DoQuestFunctionDelay("StrangeGrotto_08", 1.5);
}

void StrangeGrotto_08(string qName)
{
                   chrDisableReloadToLocation = true;
                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
           sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "Skel"+i, "skeleton", "skeleton", 30, PIRATE, 0, true, "quest"));	
            FantomMakeCoolFighter(sld, 30, 85, 85, "topor_03", "pistol3", "bullet", 100);  
            LAi_SetWarriorType(sld);				
            LAi_group_MoveCharacter(sld, "EnemyFight");				
            ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "Skel_tableFight");
}

void GothicApostatesAPS_architects_3()
{
      LocatorReloadEnterDisable("Shore104", "reload1_back", false);//откроем пещеру залива Бэк
      AddQuestRecord("Architects", "3");
      PChar.quest.StrangeGrotto_09.win_condition.l1 = "locator";
      PChar.quest.StrangeGrotto_09.win_condition.l1.location = "Strange_Grotto_3";
      PChar.quest.StrangeGrotto_09.win_condition.l1.locator_group = "quest";
      PChar.quest.StrangeGrotto_09.win_condition.l1.locator = "quest2";
      PChar.quest.StrangeGrotto_09.function = "StrangeGrotto_09";
}

void StrangeGrotto_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_IN.wav");
   DoQuestFunctionDelay("StrangeGrotto_010", 1.5);
}

void StrangeGrotto_010(string qName)
{
        chrDisableReloadToLocation = true;
         log_info("Вы нашли пюпитры Замка учёных (Библиотека)!");
         TakeNItems(pchar, "architects_table_4", 1);

         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
         DoQuestFunctionDelay("StrangeGrotto_011", 1.5);
}

void StrangeGrotto_011(string qName)
{
                   chrDisableReloadToLocation = true;
                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
                      sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "mush_skel_"+i, "man", "mushketer", 30, PIRATE, 0, true, "quest"));	
                      FantomMakeCoolFighter(sld, 40, 100, 100, "", "mushket3", "cartridge", 70);
	 LAi_SetCharacterUseBullet(sld, "cartridge");
	 TakeNItems(sld, "GunPowder", 56);
	 SetCharacterPerk(sld, "Gunman");
	 sld.monster = true; 
	 sld.LSC_clan = true;
	 sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	 sld.DontClearDead = true;
	 LAi_CharacterDisableDialog(sld);
                      LAi_SetWarriorType(sld);				
                      LAi_group_MoveCharacter(sld, "EnemyFight");				
                      ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "Skel_tableFight_2");
}

void GothicApostatesAPS_architects_4()
{
      LocatorReloadEnterDisable("Shore126", "reload1_back", false);//откроем пещеру острова Надежды
      AddQuestRecord("Architects", "4");
      PChar.quest.StrangeGrotto_012.win_condition.l1 = "locator";
      PChar.quest.StrangeGrotto_012.win_condition.l1.location = "Strange_Grotto_4";
      PChar.quest.StrangeGrotto_012.win_condition.l1.locator_group = "quest";
      PChar.quest.StrangeGrotto_012.win_condition.l1.locator = "quest2";
      PChar.quest.StrangeGrotto_012.function = "StrangeGrotto_012";
}

void StrangeGrotto_012(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_IN.wav");
   DoQuestFunctionDelay("StrangeGrotto_013", 1.5);
}

void StrangeGrotto_013(string qName)
{
        chrDisableReloadToLocation = true;
         log_info("Вы нашли пюпитры Замка учёных (Библиотека)!");
         TakeNItems(pchar, "architects_table_5", 1);

         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
         DoQuestFunctionDelay("StrangeGrotto_014", 1.5);
}

void StrangeGrotto_014(string qName)
{
                   chrDisableReloadToLocation = true;
                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
                      sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "mush_Vaterskel_"+i, "man", "mushketer", 30, PIRATE, 0, true, "quest"));	
                      FantomMakeCoolFighter(sld, 40, 100, 100, "", "mushket2", "cartridge", 70);
	 LAi_SetCharacterUseBullet(sld, "cartridge");
	 TakeNItems(sld, "GunPowder", 56);
	 SetCharacterPerk(sld, "Gunman");
	 sld.monster = true; 
	 sld.LSC_clan = true;
	 sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	 sld.DontClearDead = true;
	 LAi_CharacterDisableDialog(sld);
                      LAi_SetWarriorType(sld);				
                      LAi_group_MoveCharacter(sld, "EnemyFight");				
                      ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "Skel_tableFight_3");
}

void GothicApostatesAPS_architects_5()
{
      LocatorReloadEnterDisable("Cartahena_Ruins", "reload2_back", false);//откроем проход в подземелья
      AddQuestRecord("Architects", "5");
      PChar.quest.StrangeGrotto_015.win_condition.l1 = "locator";
      PChar.quest.StrangeGrotto_015.win_condition.l1.location = "Strange_Grotto_5";
      PChar.quest.StrangeGrotto_015.win_condition.l1.locator_group = "quest";
      PChar.quest.StrangeGrotto_015.win_condition.l1.locator = "quest2";
      PChar.quest.StrangeGrotto_015.function = "StrangeGrotto_015";
}

void StrangeGrotto_015(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_IN.wav");
   DoQuestFunctionDelay("StrangeGrotto_016", 1.5);
}

void StrangeGrotto_016(string qName)
{
        chrDisableReloadToLocation = true;
         log_info("Вы нашли пюпитры Замка учёных (Библиотека)!");
         TakeNItems(pchar, "architects_table_6", 1);

         PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav"); 
         CreateLocationParticles("large_smoke", "item", "button02", 0.7, 0, 0, "");
         DoQuestFunctionDelay("StrangeGrotto_017", 1.5);
}

void StrangeGrotto_017(string qName)
{
	for (int i=1; i<=1; i++)
	{
	CreateLocationParticles("large_smoke", "quest", "quest1", 0, 0, 0, "");
	CreateLocationParticles("ShipExplode", "quest", "quest1", 1.0, 0, 0, "boom");
	CreateLocationParticles("blast_inv", "item", "button02", 1.0, 0, 0, "");
	CreateLocationParticles("blast_dirt", "item", "button02", 1.0, 0, 0, "");
	}
	CreateLocationParticles("large_smoke", "item", "button02", 0, 0, 0, "");
	CreateLocationParticles("ShipExplode", "item", "button02", 1.0, 0, 0, "boom");
	CreateLocationParticles("blast_inv", "item", "button02", 1.0, 0, 0, "");
	CreateLocationParticles("blast_dirt", "item", "button02", 1.0, 0, 0, "");
	PlaySound("Sea Battles\Vzriv_fort_001.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");

                      PlaySound("VOICE\Russian\gotica\SFX\BELLOWS_OUT.wav");
                      DoQuestFunctionDelay("StrangeGrotto_018", 3.5);

	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "jump", "SitInGrot", 1.0);
	ChangeCharacterAddressGroup(Pchar, "Strange_Grotto_5", "reload", "reload5");
	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/3;
                     PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_DEAD.wav");
}

void StrangeGrotto_018(string qName)
{
	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "Ground_StandUp", "", 3.5);
	CreateLocationParticles("large_smoke", "goto", "locator1", 1.15, 0, 0, "");

                     PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_2.wav");
                     DoQuestFunctionDelay("StrangeGrotto_019", 3.8);
}

void StrangeGrotto_019(string qName)
{
                   chrDisableReloadToLocation = true;
                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
                      sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "Orc", "Orc", "Orc", 30, PIRATE, 0, true, "quest"));	
 	FantomMakeCoolFighter(sld, 20+MOD_SKILL_ENEMY_RATE*3, 70, 70, "blade53", "pistol05", "bullet", MOD_SKILL_ENEMY_RATE*60);
                     TakeNItems(sld, "GunPowder", 56);
	 LAi_SetCharacterUseBullet(sld, "cartridge");
	 TakeNItems(sld, "GunPowder", 56);
	 SetCharacterPerk(sld, "Gunman");
	 sld.name = "Orc";
	 sld.lastname = "";
	 sld.greeting = "";
	 sld.SaveItemsForDead = true;
	 sld.DontClearDead = true;
	 sld.monster = true; // признак нежити
	 sld.MultiFighter = 1.0+MOD_SKILL_ENEMY_RATE/20; // мультифайтер
	 LAi_CharacterDisableDialog(sld);
                      LAi_SetWarriorType(sld);				
                      LAi_group_MoveCharacter(sld, "EnemyFight");				
                      ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "Skel_tableFight_4");
}

void GothicApostatesAPS_SanAndres_7(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_162";
	
	FreeSitLocator("SanAndres_TownhallRoom", "sit2");
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "sit", "sit2");
	LAi_SetSitType(PChar);
	LAi_SetActorType(sld);
	LAi_ActorSetSitMode(sld);
	LAi_ActorDialogNow(sld, PChar, "", -1);
}

void GothicApostatesAPS_SanAndres_8(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_164";
                     SetFunctionTimerCondition("GothicApostatesAPS_SanAndres_9", 0, 0, 5, false);
                     LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto8");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  скрытый квест древние усыпальницы воскрешение Куарходрона
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void GothicApostatesAPS_Quarhodron_Myxir(string qName)
{
                   bDisableFastReload = true;//закрыть переход
                   SetFunctionTimerCondition("GothicApostatesAPS_SanAndres_9", 0, 0, 5, false);
                   LAi_SetPlayerType(PChar);
                   ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto8");

	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_164";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");

	sld = GetCharacter(NPC_GenerateCharacter("Senyan", "Senyan", "man", "man", 20, PIRATE, 1, false, "quest"));
          	sld.name      = "Сеньян";
          	sld.lastname      = "";
	sld.rank = 10;
	LAi_SetHP(sld, 350, 350);
	sld.money = 2000;
	sld.perks.list.BasicDefense = true;
                     sld.perks.list.AdvancedDefense = true;
	sld.loyality = MAX_LOYALITY;
	sld.Payment = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 90, 95, 90, 80, 90);
	SetShipSkill(sld, 50, 60, 70, 30, 30, 70, 60, 90, 30);
	SetSPECIAL(sld, 9, 10, 9, 10, 10, 10, 9);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "ByWorker");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "Doctor2");
	SetCharacterPerk(sld, "Ciras");
	GiveItem2Character(sld, "blade50");
	sld.equip.blade = "blade50";
	GiveItem2Character(sld, "pistol11");
	EquipCharacterbyItem(sld, "pistol11");
                    TakeNItems(sld, "grapeshot", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 2);
	LAi_SetCharacterUseBullet(sld, "bullet");
                    TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	sld.HoldEquip = true; 	//не отдавать оружие
	LAi_SetImmortal(sld, true);
        	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
	sld.Dialog.CurrentNode = "Senyan_Raven";
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
          	ChangeCharacterAddressGroup(sld,"SanAndres_town_2", "reload", "reload4_back");

                     PChar.quest.GothicSmithyRaven.win_condition.l1 = "locator";
                     PChar.quest.GothicSmithyRaven.win_condition.l1.location = "SanAndres_town_2";
                     PChar.quest.GothicSmithyRaven.win_condition.l1.locator_group = "reload";
                     PChar.quest.GothicSmithyRaven.win_condition.l1.locator = "reload3_back";
                     PChar.quest.GothicSmithyRaven.function = "Gothic_Smithy_Raven";
}

void Gothic_Smithy_Raven(string qName)
{
                     bDisableFastReload = false;//открыть переход
                     sld = CharacterFromID("Senyan");
        	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
	sld.Dialog.CurrentNode = "Senyan_Raven";
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void GothicApostatesAPS_Quarhodron_Myxir_1(string qName)
{
      LocatorReloadEnterDisable("Providence_CaveEntrance", "reload1_back", false);
      PChar.quest.APS_Quarhodron.win_condition.l1 = "locator";
      PChar.quest.APS_Quarhodron.win_condition.l1.location = "CryptQuarhodron";
      PChar.quest.APS_Quarhodron.win_condition.l1.locator_group = "quest";
      PChar.quest.APS_Quarhodron.win_condition.l1.locator = "quest1";
      PChar.quest.APS_Quarhodron.function = "GothicQuarhodron_ReadMyxirNotice";
}

void GothicQuarhodron_ReadMyxirNotice() // нашли заклятие стражи мёртвых
{
                     if (PChar.location == "CryptQuarhodron")
	{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
                     DoQuestFunctionDelay("GothicQuarhodron_ReadMyxirNotice_1", 3.0);
                     }
	else 
	{
	PlaySound("interface\knock.wav");
	log_info("Для вызова духа необходимa гробница Куарходрона");
                     PlaySound("VOICE\Russian\GOTHIC\GG\DOESNTWORK.wav");
	}
}

void GothicQuarhodron_ReadMyxirNotice_1(string qName)
{
                 PlaySound("VOICE\Russian\gotica\SFX\MFX_BARRIERE_SHOOT.wav");
                 DoQuestFunctionDelay("GothicQuarhodron_ReadMyxirNotice_2", 2.0);
}

void GothicQuarhodron_ReadMyxirNotice_2(string qName)
{
                 chrDisableReloadToLocation = true;
                 PlaySound("VOICE\Russian\GOTHIC\GG\SUMMONANCIENTGHOST.wav");
                 Log_Info("Явись ко мне Куарходрон древний предводитель касты воинов ...");
                 pchar.questTemp.Gothic.QuarhodronMyxirNotice = "true";
                 //RemoveItems(PChar, "QuarhodronMyxirNotice", 1);
                 DoQuestFunctionDelay("Gothic_CryptQuarhodron", 2.0);
}

void Gothic_CryptQuarhodron(string qName)
{
  	PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
	CreateLocationParticles("large_smoke", "quest", "quest2", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "quest2", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "quest2", 1.70, 3, 3, "");
	DoQuestCheckDelay("Gothic_CryptQuarhodron_1", 1.2);
}

void Gothic_TempleQuarhodron(string qName)
{
	RemoveItems(PChar, "architects_table_1", 1);
	PlaySound("interface\important_item.wav");
                     DoQuestFunctionDelay("Gothic_TempleQuarhodron_1", 2.0);

	int n = FindLocation("Providence_Temple");
	//Locations[n].models.always.l2 = "";
	//Locations[n].models.always.l2.tech = "";
	LocatorReloadEnterDisable("Providence_Temple", "reload2", false);
}

void Gothic_TempleQuarhodron_1(string qName)
{
                     PlaySound("VOICE\Russian\GOTHIC\GG\SCOPENSLASTDOOR.wav");
                     DoQuestFunctionDelay("Gothic_TempleQuarhodron_2", 4.0);
}

void Gothic_TempleQuarhodron_2(string qName)
{
                     LocatorReloadEnterDisable("Providence_Temple", "reload2", false);
 	PlaySound("VOICE\Russian\gotica\SFX\MINEAMBIENCE01.wav");
                     DoQuestFunctionDelay("Gothic_TempleQuarhodron_3", 3.0);
}

void Gothic_TempleQuarhodron_3(string qName)
{
	DoQuestReloadToLocation("Providence_Temple", "quest", "quest2", "GothicTempleQuarhodron");
}

void Gothic_TempleQuarhodron_4(string qName)
{
 	PlaySound("VOICE\Russian\gotica\OPENPORTAL.wav");
	// подсказки
	pchar.quest.Gothic_support1.win_condition.l1 = "locator";
	pchar.quest.Gothic_support1.win_condition.l1.location = "Providence_Alcovee";
	pchar.quest.Gothic_support1.win_condition.l1.locator_group = "teleport";
	pchar.quest.Gothic_support1.win_condition.l1.locator = "teleport0";
	pchar.quest.Gothic_support1.function = "Gothic_TeleportSupport";
	pchar.quest.Gothic_support2.win_condition.l1 = "locator";
	pchar.quest.Gothic_support2.win_condition.l1.location = "Providence_Alcovee";
	pchar.quest.Gothic_support2.win_condition.l1.locator_group = "teleport";
	pchar.quest.Gothic_support2.win_condition.l1.locator = "teleport1";
	pchar.quest.Gothic_support2.function = "Gothic_TeleportSupport";
}

void Gothic_TeleportSupport(string qName)
{
	log_info("Для использования нажмите 'Т'");
	sld = GetCharacter(NPC_GenerateCharacter("Rhademes", "giant", "skeleton", "giant", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "", "", "", 30);
	sld.name = "Радемес";
	sld.lastname = "";
 	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Rhademes.c";
	sld.dialog.currentnode = "Rhademes";
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
	ChangeCharacterAddressGroup(sld, "Providence_Alcovee", "goto", "goto2");
	pchar.quest.GothicRhademes.win_condition.l1 = "locator";
	pchar.quest.GothicRhademes.win_condition.l1.location = "Providence_Alcovee";
	pchar.quest.GothicRhademes.win_condition.l1.locator_group = "teleport";
	pchar.quest.GothicRhademes.win_condition.l1.locator = "teleport6";
	pchar.quest.GothicRhademes.function = "Gothic_Rhademes";
}

void Gothic_TeleportStart() // телепортация по алькову
{
	if (CheckAttribute(pchar, "questTemp.Gothic.LockTeleport"))
	{
		log_info("Портал заблокирован!");
		return;
	}
	PlaySound("Ambient\Teno_inside\teleporter.wav");
	switch (sGlobalTemp)
	{
	case "teleport0": 
	ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "quest", "teleport");
	break;
	case "teleport1": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport2"); break;
	case "teleport2": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport1"); break;
	case "teleport3": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport4"); break;
	case "teleport4": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport3"); break;
	case "teleport5": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport6"); break;
	case "teleport6": ChangeCharacterAddressGroup(pchar, "Providence_Alcovee", "teleport", "teleport5"); break;
	}
}

void Gothic_Rhademes(string qName)
{
                     sld = CharacterFromID("Rhademes");
 	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Rhademes.c";
	sld.dialog.currentnode = "Rhademes";
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Продолжение
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void GothicApostatesAPS_SanAndres_9(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_165";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");
}

void GothicApostatesAPS_SanAndres_10(string qName)
{
	sld = GetCharacter(NPC_GenerateCharacter("Balsemio", "GregPir_1", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Бальсемио";
	sld.lastname = "Монтехо";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Balsemio";
	sld.greeting = "";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);
	FreeSitLocator("SanAndres_tavern", "sit4");
	ChangeCharacterAddressGroup(sld, "SanAndres_tavern", "sit", "sit4");
}

void GothicApostatesAPS_SanAndres_11(string qName)
{
	LAi_Fade("", "");	
	sld = CharacterFromID("Balsemio");
	sld.Dialog.CurrentNode = "Balsemio_1";	
	FreeSitLocator("SanAndres_tavern", "sit5");
	ChangeCharacterAddressGroup(PChar, "SanAndres_tavern", "sit", "sit3");
	LAi_SetSitType(PChar);
	LAi_SetActorType(sld);
	LAi_ActorSetSitMode(sld);
	LAi_ActorDialogNow(sld, PChar, "", -1);
}

void GothicApostatesAPS_SanAndres_12(string qName)
{
	LAi_Fade("", "");
	AddQuestRecord("APS", "28");
                     pchar.questTemp.APS = "APS_sailorSanAndres";
	sld = CharacterFromID("Balsemio");
	LAi_SetSitType(sld);	
	LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "SanAndres_tavern", "goto", "goto4");	
}

void GothicApostatesAPS_SanAndres_13(string qName)
{
	AddQuestRecord("APS", "29");
                     pchar.questTemp.APS = "APS_sailorSanAndresChurch";
	sld = CharacterFromID("Balsemio");
	sld.lifeday = 0;
}

void GothicApostatesAPS_SanAndres_14(string qName)
{
	AddQuestRecord("APS", "30");
	sld = GetCharacter(NPC_GenerateCharacter("Kristobal", "Apostates_37", "man", "man2", 20, SPAIN, -1, false, "soldier"));
	FantomMakeCoolFighter(sld, 30, 100, 70, "blade37", "pistol11", "grapeshot", 50);
	sld.name = "Кристобаль";
	sld.lastname = "Эскаланте";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.currentnode = "Kristobal";
	sld.greeting = ""; 
	sld.rank = 20;
	sld.city = "SanAndres";
	sld.location	= "SanAndres_town_3";
	sld.location.group = "quest";
	sld.location.locator = "quest1";
	sld.reputation = 30;
	LAi_SetHP(sld, 300.0, 300.0);
	SetSPECIAL(sld, 7, 6, 8, 6, 8, 7, 5);
	SetSelfSkill(sld, 45, 85, 55, 50, 55);
                     SetShipSkill(sld, 50, 60, 60, 60, 70, 60, 70, 60, 55);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "ShipSpeedUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "Doctor1");
	SetCharacterPerk(sld, "BasicCommerce");
	SetCharacterPerk(sld, "AdvancedCommerce");
	sld.SuperShooter = true;
	LAi_SetImmortal(sld, true);
	GiveItem2Character(sld, "pistol2");
	LAi_SetCharacterUseBullet(sld, "grapeshot");
                    TakeNItems(sld, "grapeshot", 44);
	TakeNItems(sld, "bullet", 23);
	TakeNItems(sld, "cartridge", 38);
	TakeNItems(sld, "GunPowder", 56);
	sld.talker = 10; //начать диалог
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
}

void GothicApostatesAPS_SanAndres_15(string qName)
{
	sld = CharacterFromID("Kristobal");
	
	pchar.quest.sa_kris.win_condition.l1 = "locator";
	pchar.quest.sa_kris.win_condition.l1.location = "SanAndres_Dungeon";
	pchar.quest.sa_kris.win_condition.l1.locator_group = "reload";
	pchar.quest.sa_kris.win_condition.l1.locator = "reload1";
	pchar.quest.sa_kris.function = "GothicApostatesAPSSanAndres15";
	
	LAi_SetActorType(sld);
	
	LAi_ActorRunToLocation(sld, "reload", "basement2", "SanAndres_Dungeon", "monsters", "monster10", "", -1);
}

void GothicApostatesAPSSanAndres15(string qName)
{
	sld = CharacterFromID("Kristobal");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.currentnode = "Kristobal_2";
	LAi_SetActorType(sld);	
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}


void GothicApostatesAPS_SanAndres_16(string qName)
{
	sld = CharacterFromID("Kristobal");
	LAi_SetImmortal(sld, false);	
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	Lai_SetCheckMinHP(sld, 5.0, true, "GothicApostatesAPSSanAndres16");
}

void GothicApostatesAPS_SanAndres_17(string qName)
{
	AddQuestRecord("APS", "31");
	sld = CharacterFromID("Kristobal");
	LAi_RemoveCheckMinHP(sld);
	LAi_UseAtidoteBottle(sld);
	LAi_SetImmortal(sld, true);
	SetCharacterRemovable(sld, false);
	AddPassenger(PChar, sld, 0);
	LAi_SetActorType(sld);
	LAi_ActorFollowEverywhere(sld, "", -1);
	LAi_group_MoveCharacter(sld, LAI_GROUP_DEFAULT);

	sld = GetCharacter(NPC_GenerateCharacter("DiegoMarkes", "GregPir_8", "man", "man", 30, PIRATE, -1, false, "quest"));
	sld.name = "Диего";
	sld.lastname = "Маркес";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "DiegoMarkes";
	sld.greeting = "";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "HouseShore101", "sit", "sit1"); // CommonRoom_MH2
}

void GothicApostatesAPS_SanAndres_18(string qName)
{
	AddQuestRecord("APS", "32");
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_175";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");
}

void GothicApostatesAPS_SanAndres_19(string qName)
{
	AddQuestRecord("APS", "33");
	int iRank = 13+MOD_SKILL_ENEMY_RATE/2;
	Group_FindOrCreateGroup("FrFlorensio");
	Group_SetType("FrFlorensio", "pirate");
	
	sld = GetCharacter(NPC_GenerateCharacter("FlorensioCap", "mercen_"+(rand(10)+1), "man", "man", iRank, PIRATE, -1, false, "quest"));
	FantomMakeSmallSailor(sld, SHIP_FRIGATE_H, "Сантиссима Мадре", CANNON_TYPE_CANNON_LBS20, 40+rand(10), 30+rand(20), 30+rand(20), 30+rand(15), 25+rand(25));
	FantomMakeCoolFighter(sld, iRank, 60, 60, "blade_14", "pistol1", "bullet", 100);
	sld.name = "Галиндо";
	sld.lastname = "Ольмос";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "First time2";	        
	sld.DeckDialogNode = "FlorensioCap";		
	sld.Abordage.Enable = false;

	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	sld.DontRansackCaptain = true;
	sld.AlwaysFriend = true;
	SetCharacterPerk(sld, "MusketsShoot");
	sld.AnalizeShips = true;
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 3;
                     Group_AddCharacter("FrFlorensio", "FlorensioCap");
	Group_SetGroupCommander("FrFlorensio", "FlorensioCap");
	Group_SetTaskNone("FrFlorensio");//нет задачи
	Group_SetAddress("FrFlorensio", "Beliz", "quest_ships", "Quest_ship_12");
	
}

void GothicApostatesAPS_SanAndres_20(string qName)
{
	AddQuestRecord("APS", "34");
	PChar.quest.GothicApostatesAPSFisrtBattle.win_condition.l1 = "location";
	PChar.quest.GothicApostatesAPSFisrtBattle.win_condition.l1.location = "Iroquois_Jungle_01";
	PChar.quest.GothicApostatesAPSFisrtBattle.function = "GothicApostatesAPS_SanAndres_21";

}

void GothicApostatesAPS_SanAndres_21(string qName)
{		
	chrDisableReloadToLocation = true;
	LAi_LocationDisableOfficersGen("Iroquois_Cave", true); //офицеров не пускать
	int oRank = sti(pchar.rank)+5;
	int eRank = sti(pchar.rank);
	int oScl = 20 + 2*sti(pchar.rank);	
	sld = GetCharacter(NPC_GenerateCharacter("Florensio", "Apostates_36", "man", "man2", 15, SPAIN, -1, true, "quest"));
                     FantomMakeCoolFighter(sld, 25, 70, 60, BLADE_LONG, "pistol2", "grapeshot", 20);
	sld.name = "Флоренсио";
	sld.lastname = "Алегрия";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "Florensio";	  
	sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	//TakeNItems(sld, "amulet_12", 1);
	LAi_SetActorType(sld);
	LAi_SetImmortal(sld, true);
                     LAi_group_MoveCharacter(sld, "Florensio");
	ChangeCharacterAddressGroup(sld, "Iroquois_Jungle_01", "goto", "goto2");
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	for (int i=1; i<=7; i++)
	{
		if (i == 7)
		{
		sld = GetCharacter(NPC_GenerateCharacter("Florensio_sailor_"+i, "mush_ctz_", "man", "mushketer", oRank, FRANCE, -1, false, "soldier"));
		FantomMakeCoolFighter(sld, oRank, oScl, oScl, "", "mushket3", "grapeshot", oScl*3);
		TakeNItems(pchar, "grapeshot", 40);
		TakeNItems(pchar, "gunpowder", 40);
		LAi_SetCharacterUseBullet(sld, "grapeshot");
		ChangeCharacterAddressGroup(sld, "Iroquois_Jungle_01", "goto", "goto8");
		}
		else
		{
		sld = GetCharacter(NPC_GenerateCharacter("Florensio_sailor_"+i, "mercen_"+i, "man", "man", oRank, FRANCE, -1, false, "soldier"));
		FantomMakeCoolFighter(sld, oRank, oScl, oScl, LinkRandPhrase("blade_08","blade_11","blade_14"), "pistol1", "bullet", oScl*2);
		}
		ChangeCharacterAddressGroup(sld, "Iroquois_Jungle_01", "goto", "goto7");
		LAi_SetWarriorType(sld);
                                          LAi_group_MoveCharacter(sld, "Florensio");
	                     LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}
	PlaySound("interface\abordage_wining.wav");
	LAi_group_Delete("EnemyFight");
	for (i=1; i<=10; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("FlorensioKiller"+i, "mush_iroquois_"+i, "man", "mushketer", 25, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld, 25, 70, 70, "", "mushket1", "cartridge", 170);
	LAi_SetCharacterUseBullet(sld, "cartridge");
	ChangeCharacterAddressGroup(sld, "Iroquois_Jungle_01", "goto", "goto3");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "APS_FirstBattleEnd");
	//LAi_SetFightMode(pchar, true);
}

void GothicApostatesAPS_SanAndres_23(string qName)
{
                     chrDisableReloadToLocation = false;
	AddQuestRecord("APS", "35");
	EndQuestMovie();
                     LAi_SetPlayerType(pchar);
	for (int i=1; i<=7; i++)
	{
	sld = CharacterFromID("Florensio_sailor_"+i);
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 6.0);
                      }
	sld = CharacterFromID("Kristobal");
	LAi_RemoveCheckMinHP(sld);
	LAi_UseAtidoteBottle(sld);
	LAi_SetImmortal(sld, true);
	SetCharacterRemovable(sld, false);
	AddPassenger(PChar, sld, 0);
	LAi_SetActorType(sld);
	LAi_ActorFollowEverywhere(sld, "", -1);
	LAi_group_MoveCharacter(sld, LAI_GROUP_DEFAULT);
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.gold_Itza = 60606;
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.indian015 = 5;
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.indian018 = 1;
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.indian022 = 2;
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.indian010 = 1;

	pchar.quest.GothicAPSMoney.win_condition.l1 = "item";
	pchar.quest.GothicAPSMoney.win_condition.l1.item = "amulet_12";
	pchar.quest.GothicAPSMoney.function = "GothicApostatesAPS_SanAndres_24";

	pchar.quest.GothicgoldItza.win_condition.l2 = "item";
	pchar.quest.GothicgoldItza.win_condition.l2.item = "gold_Itza";
	pchar.quest.GothicgoldItza.function = "GothicApostatesAPS_Fail";

	pchar.quest.GothicAPSbox.win_condition.l3 = "locator";
	pchar.quest.GothicAPSbox.win_condition.l3.location = "Iroquois_Cave";
	pchar.quest.GothicAPSbox.win_condition.l3.locator_group = "box";
	pchar.quest.GothicAPSbox.win_condition.l3.locator = "box1";
	pchar.quest.GothicAPSbox.function = "GothicApostatesAPS_SanAndres_028";
}

void GothicApostatesAPS_SanAndres_24(string qName)
{
	AddQuestRecord("APS", "38");
	pchar.quest.GothicgoldItza.over = "yes";
	pchar.quest.GothicAPSgold.win_condition.l1 = "item";
	pchar.quest.GothicAPSgold.win_condition.l1.item = "gold_Itza";
	pchar.quest.GothicAPSgold.function = "GothicApostatesAPS_SanAndres_28";
}

void GothicApostatesAPS_Fail(string qName)//тут смерть не иначе
{
	pchar.quest.GothicgoldItza1.win_condition.l1 = "item";
	pchar.quest.GothicgoldItza1.win_condition.l1.item = "gold_Itza";
	pchar.quest.GothicgoldItza1.function = "GothicApostatesAPS_SanAndres_26";
}

void GothicApostatesAPS_SanAndres_26(string qName)
{
                   chrDisableReloadToLocation = true;
                   bDisableCharacterMenu = true;//лочим F2
                   RemoveItems(PChar, "architects_runaP", 1);
                   sld = CharacterFromID("Kristobal");
                   LAi_SetImmortal(sld, false);
                   LAi_SetActorType(sld);
                   LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

                   PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT01.wav");
                   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
                   LAi_SetPlayerType(pchar); 

		for (int i=1; i<=3; i++)
        {
                      sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "Orc1", "Orc", "Orc", 30, PIRATE, 0, true, "quest"));	
 	FantomMakeCoolFighter(sld, 20+MOD_SKILL_ENEMY_RATE*3, 70, 70, "blade53", "pistol05", "bullet", MOD_SKILL_ENEMY_RATE*60);
                     TakeNItems(sld, "GunPowder", 56);
	 LAi_SetCharacterUseBullet(sld, "cartridge");
	 TakeNItems(sld, "GunPowder", 56);
	 SetCharacterPerk(sld, "Gunman");
	 sld.name = "Orc";
	 sld.lastname = "";
	 sld.greeting = "";
	 LAi_SetImmortal(sld, true);
	 sld.SaveItemsForDead = true;
	 sld.DontClearDead = true;
	 sld.monster = true; // признак нежити
	 sld.MultiFighter = 1.0+MOD_SKILL_ENEMY_RATE/20; // мультифайтер
	 LAi_CharacterDisableDialog(sld);
                      LAi_SetWarriorType(sld);				
                      LAi_group_MoveCharacter(sld, "EnemyFight");				
                      ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "goto"+i);	
        }
        LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
        LAi_group_SetCheck("EnemyFight", "");
        DoQuestFunctionDelay("GothicApostatesAPS_SanAndres_26", 4.0);
}

void GothicApostatesAPS_SanAndres_27(string qName)
{
                   PlaySound("VOICE\Russian\DeadmansGod.wav");
}

void GothicApostatesAPS_SanAndres_028(string qName)
{
                   sld = CharacterFromID("Kristobal");
                   sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
                   sld.dialog.currentnode   = "Kristobal_11";
                   LAi_SetImmortal(sld, false);
                   LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void GothicApostatesAPS_SanAndres_28(string qName)
{
                   sld = CharacterFromID("Kristobal");
                   sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
                   sld.dialog.currentnode   = "Kristobal_11";
                   LAi_SetImmortal(sld, false);
                   LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void GothicApostatesAPS_SanAndres_29(string qName)
{
                    chrDisableReloadToLocation = true;
                    bDisableCharacterMenu = true;//лочим F2
                     sld = CharacterFromID("Kristobal");
                     LAi_SetHP(sld, 600, 600);
                     LAi_SetImmortal(sld, false);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
                    LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
                    LAi_group_SetCheck("EnemyFight", "GothicApostatesAPSSanAndres29");
}

void FrFlorensio_failed(string qName)
{
	AddQuestRecord("APS", "37");
 	Island_SetReloadEnableGlobal("Beliz", true);
	bQuestDisableMapEnter = false;
                     bDisableCharacterMenu = false;//разлочим F2
	DoQuestCheckDelay("sea_victory", 1.5);
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_205";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");

	pchar.quest.GothicAPSBrachyura.win_condition.l3 = "locator";
	pchar.quest.GothicAPSBrachyura.win_condition.l3.location = "Shore28";
	pchar.quest.GothicAPSBrachyura.win_condition.l3.locator_group = "reload";
	pchar.quest.GothicAPSBrachyura.win_condition.l3.locator = "reload2_back";
	pchar.quest.GothicAPSBrachyura.function = "GothicApostatesAPS_Brachyura";

}

void GothicApostatesAPS_SanAndres_30(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_209";
	SetTimerCondition("GothicApostatesAPS_Providence_3", 0, 0, 50, false);
}

void GothicApostatesAPS_SanAndres_030(string qName)
{
	LocatorReloadEnterDisable("SanAndres_townhall", "reload2", true);//закроем резеденцию Магистра
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_0209";
	SetTimerCondition("GothicApostatesAPS_Providence_3", 0, 0, 180, false);
}

void GothicApostatesAPS_Brachyura(string qName)
{
	chrDisableReloadToLocation = true;
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+5;
	int iScl = 40 + 2*sti(pchar.rank);

	sld1 = GetCharacter(NPC_GenerateCharacter("Brachyura", "crabBigKing", "crab", "crabBig", 40+(MOD_SKILL_ENEMY_RATE), PIRATE, -1, false, "quest"));
	sld1.name = "Бракхаур";
	sld1.lastname = "";
	GiveItem2Character(sld1, "unarmed");
	EquipCharacterbyItem(sld1, "unarmed");
	LAi_SetHP(sld1, 2000.0, 2000.0);
	sld1.animal = true;
	SetCharacterPerk(sld1, "BasicDefense");
	SetCharacterPerk(sld1, "AdvancedDefense");
	SetCharacterPerk(sld1, "CriticalHit");
	sld1.SaveItemsForDead = true;
	sld1.DontClearDead = true;
	TakeNItems(sld1, "Destiny_BluePearl", 44);
	TakeNItems(sld1, "jewelry53", 103);
	TakeNItems(sld1, "jewelry52", 91);
	TakeNItems(sld1, "Destiny_GiftPearl", 13);
	TakeNItems(sld1, "sculMa1", 1);
	TakeNItems(sld1, "amulet_12", 1);
	LAi_SetWarriorTypeNoGroup(sld1);
                     LAi_group_MoveCharacter(sld1, "EnemyFight1");
	ChangeCharacterAddressGroup(sld1, "Shore80", "reload", "sea");

	sld = GetCharacter(NPC_GenerateCharacter("Gothic_indian_Brachyura_"+i, "mush_cnb_"+(2+rand(1)), "man", "mushketer", iRank, PIRATE, -1, false, "native"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket2", "cartridge", iScl*2);
	LAi_CharacterDisableDialog(sld);
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "sea");
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, "Shore80", "smugglers", "smuggler03");

	for (i=0; i<=4; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("Gothic_indian_Brachyura_"+i, "canib_"+(rand(2)+4), "man", "man", 20, PIRATE, -1, false, "native"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, RandPhraseSimple("blade_01","blade_02"), "", "", iScl*2);
	LAi_CharacterDisableDialog(sld);
	LAi_SetActorType(sld);
	else LAi_ActorAnimation(sld, "Bead2", "", -1);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	ChangeCharacterAddressGroup(sld, "Shore80", "goto", "goto9");
	}

	sld2 = GetCharacter(NPC_GenerateCharacter("iroquoisShore", "iroquois_2", "man", "man", 10, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld2, iRank, iScl, iScl, RandPhraseSimple("blade_01","blade_02"), "", "", iScl*2);
                     LAi_SetHP(sld2, 30, 30);
	LAi_SetWarriorTypeNoGroup(sld2);
                     LAi_group_MoveCharacter(sld2, "EnemyFight2");
	ChangeCharacterAddressGroup(sld2, "Shore80", "goto", "goto43");

	LAi_group_FightGroups("EnemyFight1", "EnemyFight2", true);

	PChar.quest.GothicBrachyuraAPS1.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicBrachyuraAPS1.win_condition.l1.character = "iroquoisShore";
	PChar.quest.GothicBrachyuraAPS1.function = "GothicBrachyuraAPS_1";

}

void GothicBrachyuraAPS_1(string qName)
{
	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "Shore80", "reload", "reload3_back");
	}
 	sld1 = CharacterFromID("Brachyura");
	LAi_SetActorType(sld1);
                    LAi_group_MoveCharacter(sld1, "EnemyFight1");
	LAi_group_SetRelation("EnemyFight1", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight1", LAI_GROUP_PLAYER, true);

	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "GothicApostatesAPSBrachyura_2");
}

void GothicApostatesAPS_goldItza(string qName)
{
	AddQuestRecord("APS", "39");
	sld = GetCharacter(NPC_GenerateCharacter("Kristobal", "Apostates_37", "man", "man2", 20, SPAIN, -1, false, "soldier"));
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 0.1);
}

//--------Отступники веры Мэри Селеста-------------------------------------

void GothicApostatesAPS_SanAndres_31(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_212";
	
	FreeSitLocator("SanAndres_TownhallRoom", "sit2");
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "sit", "sit2");
	LAi_SetSitType(PChar);
	LAi_SetActorType(sld);
	LAi_ActorSetSitMode(sld);
	LAi_ActorDialogNow(sld, PChar, "", -1);
}

void GothicApostatesAPS_After3_Building(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_229";
	LAi_SetHuberType(sld);
	LAi_SetImmortal(sld, true);
	LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto8");
}

void GothicApostatesAPS_MaryCeleste(string qName)
{
	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_227";
	AddQuestRecord("APSMaryCeleste", "1");
                     LAi_SetPlayerType(PChar);
	ChangeCharacterAddressGroup(PChar, "SanAndres_TownhallRoom", "goto", "goto8");
	pchar.quest.APSMaryCeleste.win_condition.l1 = "locator";
	pchar.quest.APSMaryCeleste.win_condition.l1.location = "PuertoPrincipe_town";
	pchar.quest.APSMaryCeleste.win_condition.l1.locator_group = "item";
	pchar.quest.APSMaryCeleste.win_condition.l1.locator = "read1";
	pchar.quest.APSMaryCeleste.function = "GothicApostatesAPS_MaryCeleste_1";

}

void GothicApostatesAPS_MaryCeleste_1(string qName)
{
	AddQuestRecord("APSMaryCeleste", "2");
	pchar.questTemp.APS = "APS_MaryCelesteChurch";
}

void GothicApostatesAPS_MaryCeleste_2(string qName)
{
	chr = GetCharacter(NPC_GenerateCharacter("SofiBrics", "WitchGirl", "woman", "Witch", 1, ENGLAND, -1, true, "quest"));
	chr.name = "Софи";
	chr.lastname = "Брикс";
                     chr.dialog.filename = "Gothic_Quest\Apostates\npc.c";
                     chr.dialog.currentnode   = "SofiBrics";
	chr.greeting = "";
	LAi_SetCitizenType(chr);
	LAi_SetImmortal(chr, true);
	ChangeCharacterAddressGroup(chr, "PuertoPrincipe_crypt2", "goto", "goto2");
}

void GothicApostatesAPS_MaryCeleste_3(string qName)
{
                    bDisableCharacterMenu = true;//лочим F2
 	pchar.quest.APSMaryCeleste_1.win_condition.l1 = "location";
	pchar.quest.APSMaryCeleste_1.win_condition.l1.location = "PuertoPrincipe_town";
	pchar.quest.APSMaryCeleste_1.function = "GothicApostatesAPS_MaryCeleste_4";
}

void GothicApostatesAPS_MaryCeleste_4(string qName)
{
                     chrDisableReloadToLocation = true;
 	 sld = characterFromId("SofiBrics");
	 LAi_SetActorType(sld);
	  ChangeCharacterAddressGroup(sld, "PuertoPrincipe_town", "reload", "reload7_back");
                       DoQuestFunctionDelay("GothicApostatesAPS_MaryCeleste_5", 1.0);
}

void GothicApostatesAPS_MaryCeleste_5(string qName)
{
 	  sld = characterFromId("SofiBrics");
	  LAi_SetActorType(sld);
	  LAi_ActorGoToLocation(sld, "reload", "reload2_back", "PuertoPrincipe_port", "reload", "reload2_back", "GothicApostatesAPSMaryCeleste6", -1);
}

void GothicApostatesAPS_MaryCeleste_6(string qName)
{
	
}

//-------------------------------косяк из болотной травки-------------------------------------

void Gothic_fennisgrasstotal() 
{
                      LAi_SetActorType(pchar);
	 DoQuestCheckDelay("Gothicfennisgrasstotal", 2.0);
}















