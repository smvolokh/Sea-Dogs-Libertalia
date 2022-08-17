void GothicRQuestComplete(string sQuestName, string qname)
{
	ref chr, chr2, loc;
	string sStr;
	aref ar1, ar2;	
	ref sld1, sld2;
                  iChar, n;
	int iChar = -1;
	ref sld, npchar;
	int iScl;
	string sVideoFile = "";
	string Ship;
	string Cabine;
	float x, y, z;
	aref arOldMapPos, arAll, arPass;
	int     iTemp, i, n, ShipType, Rank, iRank, fTemp; // нужно для вычислений любых целых (нации)
                        float locx, locy, locz;
	string  attrName, Model, Blade, Gun, sTemp, sQuestTown, sQuestTitle; // любые строки для вычислений
	bool   bOk;
	int iChurchGenBanditsCount;

	switch(sQuestName)
	{	

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Разное    
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "Tenoc_TeleportArrive_1":
	DeleteAttribute(pchar, "GenQuest.CannotWait");
	DeleteAttribute(pchar, "GenQuest.CirassExchangeDisable"); // кирасы можно одевать
	bDisableFastReload = false;//открыть переход
	break;
	                  
                   case "Trec_crew":
                   StartPostVideo("Tr_crew", 1);
	 DoQuestFunctionDelay("SetSchemeForSea", 7.0);		
	 break;

	case "Monbar_StartGameVideo":
                  //StartPostVideo("Title", 1);
	DoQuestFunctionDelay("Monbar_StartGame_1", 1.0); 
	// зажигаем огоньки
	chr = &Locations[FindLocation(pchar.location)];
                  PlaySound("VOICE\Russian\gotica\SFX\MFX_FEAR_CAST.wav");
	for (i=1; i<=10; i++)
	{
	CreateLocationParticles("item", "item", "torch"+i, 1.15, 0, 0, "");
	}
	CreateLocationParticles("large_smoke", "quest", "quest3", 1.00, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "quest3", 1.00, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "quest3", 1.00, 3, 3, "");
	CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
	break;

	case "Gothic_Alligator_01":
	LAi_SetGroundSitTypeNoGroup(pchar);
                   DoQuestFunctionDelay("Gothic_Alligator_1", 0.3);
	break;

	case "Gothic_Alligator_03":
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
                   DoQuestFunctionDelay("Gothic_Alligator_3", 0.1);
	break;

	case "Gothic_Alligator_05":
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
                   DoQuestFunctionDelay("Gothic_Alligator_5", 0.1);
	break;

	case "FiamatarToBoom":
	pchar.GenQuest.ShipSituation.Explosion = ShipSituation_4;//ба-бах!
	pchar.GenQuest.ShipSituation.Explosion.CapId = "FiamatarCap";
	AddComplexSelfExpToScill(200, 200, 200, 200);
	break;

//-------------------------------косяк из болотной травы-------------------------------------

	 case "Gothicfennisgrasstotal":
	 PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_9.wav");
	 LAi_SetActorType(pchar);
                      else LAi_ActorAnimation(pchar, "type afraid", "Gothicfennisgrasstotal_1",  3.5);
	 GetCharacterPos(PChar, &x, &y, &z);
	 y += 2.0;
	 z += 2.5;
	 x += 2;
	 locCameraToPos(x, y, z, false);
	 DoQuestCheckDelay("Gothicfennisgrasstotal_1", 1.0);	
                      break;

	 case "Gothicfennisgrasstotal_1":
                      LaunchBlast(pchar);
	 DoQuestCheckDelay("Gothicfennisgrasstotal_2", 2.0);
                      break;

	 case "Gothicfennisgrasstotal_2":
	 ResumeAllSounds();
	 SendMessage(&locCamera, "l", MSG_CAMERA_FOLLOW);
	 PlaySound("VOICE\Russian\gotica\SFX\MFX_SLEEP_CAST.wav");
	 LAi_SetPlayerType(PChar);
      LaunchBlast(pchar);
	 Log_Info("+ энергия");
    pchar.questTemp.Gothicfennisgrasstotal = true;
                      break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "Moe_Exit_1": // ГГ выиграл фехт
		 sld = characterFromId("Moe");
	                    LAi_SetCitizenType(sld);
	                     SetSelfSkill(sld, 60, 90, 90, 80, 80);
	                     SetCharacterPerk(sld, "BasicDefense");
	                     LAi_SetHP(sld, 800.0, 800.0);
	                     sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Moe.c";
	                     sld.dialog.currentnode = "First time";
		  DialogExit();
		  LAi_SetCurHPMax(pchar); 
		  LAi_GetCharacterMaxEnergy(pchar);
	                     LocatorReloadEnterDisable("Roseau_town", "reload13", false);
	break;

	case "Moe_HeroWin": // ГГ выиграл фехт
		LAi_group_Delete("EnemyFight");
		DoQuestCheckDelay("hide_weapons", 1.2);
		sld = characterFromId("Moe");
		if (sti(sld.quest.Moe_win == 0)) sld.dialog.currentnode = "Moe_17"; // с первого раза побил
		else sld.dialog.currentnode = "Moe_18";
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
	break;

	case "hide_weapons":
		LAi_SetFightMode(pchar, false);
		sld = characterFromId("Moe");
		LAi_SetGroundSitType(sld);
	break;

	
	case "Moe_HeroFail": // ГГ проиграл фехт
		LAi_group_Delete("EnemyFight");
		DoQuestCheckDelay("hide_weapon", 0.5);
		sld = characterFromId("Moe");
		sld.quest.Moe_win = sti(sld.quest.Moe_win)+1;
		if (sti(sld.quest.Moe_win == 1)) sld.dialog.currentnode = "Moe_19"; // один раз побили
		else 
		{
			if (sti(sld.quest.Moe_win == 2)) sld.dialog.currentnode = "Moe_20"; // два раза побили
			else sld.dialog.currentnode = "Moe_21"; //три раза побили
		}
		LAi_SetActorType(sld);

		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		LAi_SetImmortal(pchar, false);
	break;

		case "_XARDAS_1":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");                                          
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_00.wav");
		DoQuestCheckDelay("_XARDAS_2", 5.0);
		break;
		case "_XARDAS_2":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_01.wav");
		DoQuestCheckDelay("_XARDAS_3", 6.0);
		break;
		case "_XARDAS_3":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");                                          
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_02.wav");
		DoQuestCheckDelay("_XARDAS_4", 6.0);
		break;
		case "_XARDAS_4":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_03.wav");
		DoQuestCheckDelay("_XARDAS_5", 9.0);
		break;
		case "_XARDAS_5":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_04.wav");
		DoQuestCheckDelay("_XARDAS_6", 4.0);
		break;
		case "_XARDAS_6":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_05.wav");
		DoQuestCheckDelay("_XARDAS_7", 5.0);
		break;
		case "_XARDAS_7":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_06.wav");
		DoQuestCheckDelay("_XARDAS_8", 5.0);
		break;
		case "_XARDAS_8":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_07.wav");
		DoQuestCheckDelay("_XARDAS_9", 4.0);
		break;
		case "_XARDAS_9":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\XARDAS\INTRO_XARDAS_SPEECH_14_08.wav");
		DoQuestCheckDelay("_XARDAS_10", 6.0);
		break;
		case "_XARDAS_10":
	                  CreateLocationParticles("fire_incas_Simple", "quest", "quest3", 0.5, 0, 0, "");
                                    PlaySound("VOICE\Russian\gotica\SFX\ZOM_DIE03.wav");
                                    DoQuestFunctionDelay("Monbar_StartGame_2", 2.0);

		LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", true);//закроем верфь
		LocatorReloadEnterDisable("LeFransua_town", "reload3_back", true);//закроем резеденцию пиратов
		LocatorReloadEnterDisable("Fortfrance_town", "basement1", true);//закроем подземелье
		LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", true);//закроем базу
		LocatorReloadEnterDisable("Roseau_town", "reload13", true);//таверну закрыть
		LocatorReloadEnterDisable("Roseau_SecBrRoom", "reload2", true);//комнату в борделе закрыть
		LocatorReloadEnterDisable("Roseau_port", "reload3", false);//катакомбы закрыть
		//LocatorReloadEnterDisable("Shore30", "reload2_back", true);//закроем вход в тайную пещеру до поры до времени
	                    LocatorReloadEnterDisable("Guadeloupe_Cave", "reload2", true);//закроем вход в гробницу до поры до времени
		LocatorReloadEnterDisable("SantLous_town", "reload10", true);//закроем резеденцию Ли до поры до времени
                                         LocatorReloadEnterDisable("FortFrance_church IM", "reload3", true);//закроем вход в склеп до поры до времени 
                                         LocatorReloadEnterDisable("FortFrance_Graveyard_crypt", "reload2", true);//закроем вход в склеп до поры до времени 
                                         LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", true);//закроем вход в город до поры до времени 
                                         LocatorReloadEnterDisable("SentJons_town", "HouseF2", true);//закроем дом Моргана до поры до времени 
                                         LocatorReloadEnterDisable("VillaAlegria_town2", "reload4", true);//закроем дом Смита до поры до времени 
                                         LocatorReloadEnterDisable("House_Smithy", "reload1", true);//закроем дом Смита до поры до времени 
                                         LocatorReloadEnterDisable("VillaAlegria_town2", "basement1", true);//закроем черный ход в дом Смита до поры до времени 
                                         LocatorReloadEnterDisable("Dominica_Fishing_Settlement", "reload2", true);//закроем проход на маяк до поры до времени 
                                         LocatorReloadEnterDisable("Beliz_Loguna_exit", "reload3", true);//закроем Теночтитлан до поры до времени 

	i = FindIsland("IslaMona");
	Islands[i].visible = true;
	Islands[i].reload_enable = true;

		break;

  ////////////////////////////////////////////////////////////////////////
//----------------------------Супчик Тёклы-------------------------------------
  ////////////////////////////////////////////////////////////////////////

		case "Gothic_PlusSkill_Charisma"://Супчик Тёклы
            // boal оптимизация скилов -->
            PlaySound("VOICE\Russian\gotica\SFX\MFX_CONTROL_CAST.wav");
            DelBakSkillAttr(pchar);
            ClearCharacterExpRate(pchar);
            RefreshCharacterSkillExpRate(pchar);
            // boal оптимизация скилов <--
        	WaitDate("",0,0,1,0,1);
        	RecalculateJumpTable();
        	StoreDayUpdate();
	SetLaunchFrameFormParam("Чувство прилива харизмы...", "", 0, 4);
	LaunchFrameForm();
                    sld = characterFromId("SantLous_tavernkeeper");
	 sld.Dialog.Filename = "tavern\SantLous_Tavern.c";
	 sld.dialog.currentnode = "info_8";
	break;

		case "Gothic_PlusSkill_Intellect"://Супчик Тёклы
            // boal оптимизация скилов -->
            PlaySound("VOICE\Russian\gotica\SFX\MFX_CONTROL_CAST.wav");
            DelBakSkillAttr(pchar);
            ClearCharacterExpRate(pchar);
            RefreshCharacterSkillExpRate(pchar);
            // boal оптимизация скилов <--
        	WaitDate("",0,0,1,0,1);
        	RecalculateJumpTable();
        	StoreDayUpdate();
	SetLaunchFrameFormParam("Чувство прилива интеллекта...", "", 0, 4);
	LaunchFrameForm();
                    sld = characterFromId("SantLous_tavernkeeper");
	 sld.Dialog.Filename = "tavern\SantLous_Tavern.c";
	 sld.dialog.currentnode = "info_8";
	break;


  ////////////////////////////////////////////////////////////////////////
//----------------------------Горное дело-------------------------------------
  ////////////////////////////////////////////////////////////////////////

		case "OreTimer":
			int RandOre;
			int sound;
			
			int Stones;
			int Chance;


			if(GetItemsWeight(pchar) <= GetMaxItemsWeight(pchar)) // Проверим перевес инвентаря
			{
			
			if(pchar.questTemp.mining_type == "mining1") // Железная руда
			{
				LAi_ActorAnimation(pchar, "ore_go", "OreTimer", 3.0); // Цикл
				pchar.questTemp.TimerO = sti(pchar.questTemp.TimerO) + 1; // Запоминаем, что сделан удар киркой
				sound = PlaySound("interface\mining.wav");
	                                                         PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_" + rand(2) + ".wav");
				pchar.questTemp.mining_sound = sound;
				Log_TestInfo("Удар киркой: " + pchar.questTemp.TimerO);

				if(sti(pchar.questTemp.TimerO) >= 3) // Каждые 3 удара киркой
				{
					pchar.questTemp.TimerO = 0; // Обнуляем
					RandOre = 2 + makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) + rand( makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10 * 3) ) // Рандом в зависимости от скила
					
					if(sti(pchar.questTemp.Mining.Fatigue) < 200) // Проверим устал ли персонаж
					{
						Log_Info("Железная руда +" + RandOre + " ед. (" + makeint(RandOre*2.4) + " EXP)"); // Вывод инфы в лог
						AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, makeint(RandOre*2.4)); // 1 ед руды = 2.4 опыта
						TakeNItems(pchar, "jewelry103", RandOre); // Даем руду
						pchar.questTemp.Mining.Fatigue = sti(pchar.questTemp.Mining.Fatigue) + 14; // +7% усталости с каждой добычей
						
						Chance = makeint(7*(1.0+makefloat(GetCharacterSkill(pchar,SKILL_MINEPICKING))/200.0)*2);
						if(rand(100) <= Chance) // 7-10% найти драг. камень
						{
							Stones = 1+rand(4);
							
							if(rand(1) < 1)
							{
								TakeNItems(pchar, "jewelry1", Stones); // Аметист
								Log_Info("Найден аметист в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*7);
							}
							else
							{
								TakeNItems(pchar, "jewelry23", Stones); // Хризоберилл
								Log_Info("Найден хризоберилл в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*7);
							}
							else
							{
								TakeNItems(pchar, "jewelry12", Stones); // Медный самородок
								Log_Info("Найден медный самородок в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*7);
							}
							else
							{
								TakeNItems(pchar, "jewelry16", Stones); // опал
								Log_Info("Найден опал в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*7);
							}
							
							pchar.questTemp.stonescount = sti(pchar.questTemp.stonescount) + Stones;
			
						}
						
						pchar.questTemp.orecount = sti(pchar.questTemp.orecount) + RandOre;
			
					}
					else
					{
						Log_Info("Персонаж чувствует усталость. Необходим отдых");
						Log_Info("Вы вышли из режима добычи руды");
						StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                                                            DoQuestCheckDelay("NOTHINGTOGET", 0.1);
						pchar.questTemp.mining_type = "none";
						locCameraSleep(false);
						LAi_SetPlayerType(pchar);
						pchar.questTemp.TimerO = 0;
					}
				}
			}
			
 			if(pchar.questTemp.mining_type == "mining2") // Серебряная руда
			{
				LAi_ActorAnimation(pchar, "ore_go", "OreTimer", 3.0); // Цикл
				pchar.questTemp.TimerO = sti(pchar.questTemp.TimerO) + 1; // Запоминаем, что сделан удар киркой
				sound = PlaySound("interface\mining.wav");
	                                                         PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_" + rand(2) + ".wav");
				pchar.questTemp.mining_sound = sound;
				Log_TestInfo("Удар киркой: " + pchar.questTemp.TimerO);

				if(sti(pchar.questTemp.TimerO) >= 3) // Каждые 3 удара киркой
				{
					pchar.questTemp.TimerO = 0; // Обнуляем
					RandOre = makeint((2 + makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) + rand( makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10 * 2) ))/2) // Рандом в зависимости от скила
					
					if(sti(pchar.questTemp.Mining.Fatigue) < 200) // Проверим устал ли персонаж
					{
						Log_Info("Серебряная руда +" + RandOre + " ед. (" + makeint(RandOre*5) + " EXP)"); // Вывод инфы в лог
						AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, makeint(RandOre*5)); // 1 ед руды = 5 опыта
						TakeNItems(pchar, "jewelry104", RandOre); // Даем руду
						pchar.questTemp.Mining.Fatigue = sti(pchar.questTemp.Mining.Fatigue) + 18; // +9% усталости с каждой добычей
						
						Chance = makeint(9*(1.0+makefloat(GetCharacterSkill(pchar,SKILL_MINEPICKING))/200.0)*2);
						if(rand(100) <= Chance) // 9-13% найти драг. камень
						{
							Stones = 1+rand(4);
							
							if(rand(2) < 2) // 60% рубин, 30% изумруд
							{
								TakeNItems(pchar, "jewelry3", Stones); // Рубин
								Log_Info("Найден рубин в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*10);
							}
							else
							{
								TakeNItems(pchar, "jewelry4", Stones); // Изумрдуд
								Log_Info("Найден изумруд в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry7", Stones); // голубой янтарь
								Log_Info("Найден голубой янтарь в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry17", Stones); // гиацинт
								Log_Info("Найден гиацинт в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							
							pchar.questTemp.stonescount = sti(pchar.questTemp.stonescount) + Stones;
			
						}
						
						pchar.questTemp.orecount = sti(pchar.questTemp.orecount) + RandOre;
			
					}
					else
					{
						Log_Info("Персонаж чувствует усталость. Необходим отдых");
						Log_Info("Вы вышли из режима добычи руды");
						StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                                                            DoQuestCheckDelay("NOTHINGTOGET", 0.1);
						pchar.questTemp.mining_type = "none";
						locCameraSleep(false);
						LAi_SetPlayerType(pchar);
						pchar.questTemp.TimerO = 0;
					}
				}
			}
			
			if(pchar.questTemp.mining_type == "mining3") // Золотая руда
			{
				LAi_ActorAnimation(pchar, "ore_go", "OreTimer", 3.0); // Цикл
				pchar.questTemp.TimerO = sti(pchar.questTemp.TimerO) + 1; // Запоминаем, что сделан удар киркой
				sound = PlaySound("interface\mining.wav");
	                                                         PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_" + rand(2) + ".wav");
				pchar.questTemp.mining_sound = sound;
				Log_TestInfo("Удар киркой: " + pchar.questTemp.TimerO);

				if(sti(pchar.questTemp.TimerO) >= 3) // Каждые 3 удара киркой
				{
					pchar.questTemp.TimerO = 0; // Обнуляем
					RandOre = makeint((2 + makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) + rand( makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) ))/3) // Рандом в зависимости от скила
					
					if(sti(pchar.questTemp.Mining.Fatigue) < 200) // Проверим устал ли персонаж
					{
						Log_Info("Золотая руда +" + RandOre + " ед. (" + makeint(RandOre*10.2) + " EXP)"); // Вывод инфы в лог
						AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, makeint(RandOre*10.2)); // 1 ед руды = 10.2 опыта
						TakeNItems(pchar, "jewelry105", RandOre); // Даем руду
						pchar.questTemp.Mining.Fatigue = sti(pchar.questTemp.Mining.Fatigue) + 22; // +11% усталости с каждой добычей
						
						Chance = makeint(11*(1.0+makefloat(GetCharacterSkill(pchar,SKILL_MINEPICKING))/200.0)*2);
						if(rand(100) <= Chance) // 11-16% найти драг. камень
						{
							Stones = 1+rand(4);
							
							if(rand(1) < 1)
							{
								TakeNItems(pchar, "jewelry2", Stones); // Алмаз
								Log_Info("Найден алмаз в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*14);
							}
							else
							{
								TakeNItems(pchar, "jewelry8", Stones); // янтарь
								Log_Info("Найден янтарь в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry4", Stones); // изумруд
								Log_Info("Найден изумруд в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry13", Stones); // огненный опал
								Log_Info("Найден огненный опал в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							
							pchar.questTemp.stonescount = sti(pchar.questTemp.stonescount) + Stones;
			
						}
						
						pchar.questTemp.orecount = sti(pchar.questTemp.orecount) + RandOre;
			
					}
					else
					{
						Log_Info("Персонаж чувствует усталость. Необходим отдых");
						Log_Info("Вы вышли из режима добычи руды");
						StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                                                            DoQuestCheckDelay("NOTHINGTOGET", 0.1);
						pchar.questTemp.mining_type = "none";
						locCameraSleep(false);
						LAi_SetPlayerType(pchar);
						pchar.questTemp.TimerO = 0;
					}
				}
			}
			
			if(pchar.questTemp.mining_type == "mining4") // Уголь
			{
				LAi_ActorAnimation(pchar, "ore_go", "OreTimer", 3.0); // Цикл
				pchar.questTemp.TimerO = sti(pchar.questTemp.TimerO) + 1; // Запоминаем, что сделан удар киркой
				sound = PlaySound("interface\mining.wav");
	                                                         PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_" + rand(2) + ".wav");
				pchar.questTemp.mining_sound = sound;
				Log_TestInfo("Удар киркой: " + pchar.questTemp.TimerO);

				if(sti(pchar.questTemp.TimerO) >= 3) // Каждые 3 удара киркой
				{
					pchar.questTemp.TimerO = 0; // Обнуляем
					RandOre = makeint(2 + makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) + rand( makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10 * 4) )) // Рандом в зависимости от скила
					
					if(sti(pchar.questTemp.Mining.Fatigue) < 200) // Проверим устал ли персонаж
					{
						Log_Info("Уголь +" + RandOre + " ед. (" + makeint(RandOre*1.3) + " EXP)"); // Вывод инфы в лог
						AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, makeint(RandOre*1.3)); // 1 ед руды = 1.3 опыта
						TakeNItems(pchar, "jewelry102", RandOre); // Даем руду
						pchar.questTemp.Mining.Fatigue = sti(pchar.questTemp.Mining.Fatigue) + 10; // +5% усталости с каждой добычей
						
						Chance = makeint(5*(1.0+makefloat(GetCharacterSkill(pchar,SKILL_MINEPICKING))/200.0)*2);
						if(rand(100) <= Chance) // 5-7% найти драг. камень
						{
							Stones = 1+rand(4);
							
							if(rand(1) < 1)
							{
								TakeNItems(pchar, "jewelry20", Stones); // бирюза
								Log_Info("Найден бирюза в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*7);
							}
							else
							{
								TakeNItems(pchar, "jewelry21", Stones); // лазурит
								Log_Info("Найден лазурит в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*5);
							}
							else
							{
								TakeNItems(pchar, "jewelry22", Stones); // нефрит
								Log_Info("Найден нефрит в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*5);
							}
							else
							{
								TakeNItems(pchar, "jewelry1", Stones); // аметист
								Log_Info("Найден аметист в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*5);
							}
							
							pchar.questTemp.stonescount = sti(pchar.questTemp.stonescount) + Stones;
			
						}
						
						pchar.questTemp.orecount = sti(pchar.questTemp.orecount) + RandOre;
			
					}
					else
					{
						Log_Info("Персонаж чувствует усталость. Необходим отдых");
						Log_Info("Вы вышли из режима добычи руды");
						StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                                                            DoQuestCheckDelay("NOTHINGTOGET", 0.1);
						pchar.questTemp.mining_type = "none";
						locCameraSleep(false);
						LAi_SetPlayerType(pchar);
						pchar.questTemp.TimerO = 0;
					}
				}
			}

			if(pchar.questTemp.mining_type == "mining5") // Платиновая руда
			{
				LAi_ActorAnimation(pchar, "ore_go", "OreTimer", 3.0); // Цикл
				pchar.questTemp.TimerO = sti(pchar.questTemp.TimerO) + 1; // Запоминаем, что сделан удар киркой
				sound = PlaySound("interface\mining.wav");
	                                                         PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_" + rand(2) + ".wav");
				pchar.questTemp.mining_sound = sound;
				Log_TestInfo("Удар киркой: " + pchar.questTemp.TimerO);

				if(sti(pchar.questTemp.TimerO) >= 3) // Каждые 3 удара киркой
				{
					pchar.questTemp.TimerO = 0; // Обнуляем
					RandOre = makeint((2 + makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) + rand( makeint(makeint(GetCharacterSkill(pchar,SKILL_MINEPICKING)) / 10) ))/3) // Рандом в зависимости от скила
					
					if(sti(pchar.questTemp.Mining.Fatigue) < 200) // Проверим устал ли персонаж
					{
						Log_Info("Платиновая руда +" + RandOre + " ед. (" + makeint(RandOre*10.2) + " EXP)"); // Вывод инфы в лог
						AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, makeint(RandOre*10.2)); // 1 ед руды = 10.2 опыта
						TakeNItems(pchar, "jewelry108", RandOre); // Даем руду
						pchar.questTemp.Mining.Fatigue = sti(pchar.questTemp.Mining.Fatigue) + 22; // +11% усталости с каждой добычей
						
						Chance = makeint(11*(1.0+makefloat(GetCharacterSkill(pchar,SKILL_MINEPICKING))/200.0)*2);
						if(rand(100) <= Chance) // 3-9% найти драг. камень
						{
							Stones = 1+rand(4);
							
							if(rand(1) < 1)
							{
								TakeNItems(pchar, "jewelry2", Stones); // Алмаз
								Log_Info("Найден алмаз в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*14);
							}
							else
							{
								TakeNItems(pchar, "jewelry6", Stones); // серебряный самородок
								Log_Info("Найден серебряный самородок в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry4", Stones); // изумруд
								Log_Info("Найден изумруд в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*12);
							}
							else
							{
								TakeNItems(pchar, "jewelry10", Stones); // платиновый слиток
								Log_Info("Найден аметист в кол-ве " + Stones + " ед.");
								AddCharacterEXPToSkill(pchar, SKILL_MINEPICKING, Stones*5);
							}
							
							pchar.questTemp.stonescount = sti(pchar.questTemp.stonescount) + Stones;
			
						}
						
						pchar.questTemp.orecount = sti(pchar.questTemp.orecount) + RandOre;
			
					}
					else
					{
						Log_Info("Персонаж чувствует усталость. Необходим отдых");
						Log_Info("Вы вышли из режима добычи руды");
						StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                                                            DoQuestCheckDelay("NOTHINGTOGET", 0.1);
						pchar.questTemp.mining_type = "none";
						locCameraSleep(false);
						LAi_SetPlayerType(pchar);
						pchar.questTemp.TimerO = 0;
					}
				}
			}
			
			}
			else
			{
				Log_Info("Нет места в инвентаре");
				Log_Info("Вы вышли из режима добычи руды");
				StopSound(makeint(pchar.questTemp.mining_sound),0);
		                                      DoQuestCheckDelay("WISP", 0.1);
				pchar.questTemp.mining_type = "none";
				locCameraSleep(false);
				LAi_SetPlayerType(pchar);
				pchar.questTemp.TimerO = 0;
			}

        break;

	case "NOTHINGTOGET":
	PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\NOTHINGTOGET_" + rand(2) + ".wav");
	break;

	case "NOTNEAR":
	Log_Info("Для добычи руды вы должны иметь кирку в инвентаре");
	PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\NOTNEAR_" + rand(3) + ".wav");
	break;

	case "WISP":
	PlaySound("VOICE\Russian\GOTHIC\GG\WISP.wav");
	break;
		
		// <---Горное дело


  		////////////////////////////////////////////////////////////////////////
		//  Начало наёмники в городах		////////////////////////////////////////////////////////////////////////

	case "Monkey":
	                    PlaySound("VOICE\Russian\gotica\SFX\MONKEY.wav");
		sld = characterFromId("Francisco");
		sld.dialog.currentnode = "Monkey_1";
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_SetPlayerType(pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
	break;

	case "skeleton":
	                    PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT02.wav");
		sld = characterFromId("Francisco");
		sld.dialog.currentnode = "skeleton_1";
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_SetPlayerType(pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
	break;

	case "Orc":
	                   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT05.wav");
		sld = characterFromId("Francisco");
		sld.dialog.currentnode = "Orc_1";
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_SetPlayerType(pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
	break;

	case "Francisco_gate":
	                    PlaySound("interface\key.wav");//щелк!
		sld = characterFromId("Francisco");
		sld.dialog.currentnode = "gate_1";
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
		LAi_SetPlayerType(pchar);
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
	break;

		case "Berglars_Dexter":
                    LocatorReloadEnterDisable("VillaAlegria_prison", "reload30", false); 
	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "VillaAlegria_prison";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "reload";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "reload1";
	pchar.quest.Berglars_Dexter.function = "Birglars_Info_Inquisition";
        break; 
		case "Berglars_Dexter1": 
	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "church IM";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "Quest";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "LLquest6";
	pchar.quest.Berglars_Dexter.function = "BerglarsDexter";

        break; 		
  		////////////////////////////////////////////////////////////////////////
		//  Конец наёмники в городах		//////////////////////////////////////////////////////////////////////// 


////////////////////////////////////////////////////////////////////////
		//  Начало    Грабеж жемчужного промысла
		//////////////////////////////////////////////////////////////////////// 

		case "DestinyGiftPearlGen_checkSantaCatalina":

			if (locations[reload_cur_location_index].id == "shore116")
			{
				if (!CheckAttribute(&locations[reload_location_index], "DestinyGiftPearlSantaCatalina") || GetNpcQuestPastDayParam(&locations[reload_location_index], "DestinyGiftPearlSantaCatalina") > 30)
				{				
					LAi_group_Delete("DestinyGiftPearlGroup_1");
					iTemp = sti(colonies[FindColony("SantaCatalina")].nation); //принадлежность промысла нации, от Санта-Каталины
					SaveCurrentNpcQuestDateParam(&locations[reload_location_index], "DestinyGiftPearlSantaCatalina");
					sld = GetCharacter(NPC_GenerateCharacter("DestinyGiftPearlGuardMan_1", "officer_17", "man", "man", 10, iTemp, 31, true, "soldier"));
					ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto"+RandFromThreeDight(3, 4, 8));
			sld.city = "SantaCatalina"; //НЗГ Санта-Каталины
			LAi_group_MoveCharacter(sld, "DestinyGiftPearlGroup_1");
					LAi_SetActorType(sld);
					locations[FindLocation("DestinyGiftPearl_town_1")].DestinyGiftpearlVillage = true; //флаг генерить жемчужников
					bOk = true;	//мир				
					if (GetRelation2BaseNation(iTemp) != RELATION_FRIEND)
					{	
						if (GetDaysContinueNationLicence(iTemp) == -1)
						{
							if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50))) 
							{
	Log_SetStringToLog("Часового необходимо уничтожить!")			LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);					
							bOk = false; //война
							}
							else
							{
			AddCharacterExpToSkill(pchar, SKILL_SNEAK, 200);
							}
						}
					}
					if (bOk)
					{
		chrDisableReloadToLocation = true;
		sld.dialog.Filename = "Gothic_Quest\Pearl_dialog.c";
		sld.dialog.currentnode = "GuardMan";
			LAi_ActorDialog(sld, pchar, "", -1, 0);
					}					
				}
			}
			else //обратный путь
			{
				if (locations[reload_cur_location_index].id == "DestinyGiftPearl_town_1" && GetCharacterIndex("HeadMan_1") == -1)
				{
					iTemp = 0;
					for(i=0; i<MAX_CHARACTERS; i++)
					{
						if (characters[i].location == "DestinyGiftPearl_town_1")
						{
							characters[i].location = "none";
							iTemp++;
						}
					}
					if (iTemp > 0) //остатки жемчуга скоммуниздили оставшиеся в живых жемчужники
					{
						DeleteAttribute(&locations[FindLocation("DestinyGiftPearlTown1_Townhall")], "box1");
						DeleteAttribute(&locations[FindLocation("DestinyGiftPearlTown1_Townhall")], "box2");
					}
				}
			}
			pchar.quest.DestinyGiftPearlGen_SetNewInterrapt_1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.DestinyGiftPearlGen_SetNewInterrapt_1.win_condition.l1.location = "DestinyGiftPearl_Jungle_01";
			pchar.quest.DestinyGiftPearlGen_SetNewInterrapt_1.function = "DestinyGiftPearlGen_SetSantaCatalina";
		break;


        case "DestinyGiftToShore_ForSale":
			chrDisableReloadToLocation = false;
			LAi_SetCitizenTypeNoGroup(&characters[sti(pchar.quest.DestinyGiftToShore_ForSale.idx)]);
        break;


        case "DestinyGiftPearl_GuardManIsLife":
			sld = &characters[sti(pchar.quest.DestinyGiftPearl_GuardManIsLife.idx)];
			sld.dialog.Filename = "Gothic_Quest\Pearl_dialog.c";
 			sld.dialog.currentnode = "GuardManAllarm";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto10");
			LAi_SetActorTypeNoGroup(sld);
			LAi_ActorDialog(sld, pchar, "", 1.5, 0);			
        break;

		////////////////////////////////////////////////////////////////////////
		//  Конец    Грабеж жемчужного промысла
		//////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////////
//----------------------------Летучий Голландец-------------------------------------
  ////////////////////////////////////////////////////////////////////////
        case "Survive_In_Sea":
            DeleteSeaEnvironment();
            PChar.GenQuest.GhostShip.KillMe      = sti(PChar.GenQuest.GhostShip.KillMe) + 1;
            PChar.GenQuest.GhostShip.AskAbout    = 2; // опять будет
            Survive_In_Sea_Go2Land();
        break;
        
        case "GhostShip_Dead":
            if (CheckAttribute(pchar , "GenQuest.GhostShip.LastBattle"))
            {
                Log_Info("Призрак уничтожен, теперь он не вернётся!");
                AddQuestRecord("GhostShipQuest", "Dead_2");
				AddQuestUserData("GhostShipQuest", "sSex", GetSexPhrase("","а"));
                CloseQuestHeader("GhostShipQuest");

                AddCharacterExpToSkill(PChar, "Leadership", 300);
    		    AddCharacterExpToSkill(PChar, "Sailing", 2000);
    		    AddCharacterExpToSkill(PChar, "Accuracy", 2000);
    		    AddCharacterExpToSkill(PChar, "Cannons", 2000);
    		    AddCharacterExpToSkill(PChar, "Repair", 2000);
    		    AddCharacterExpToSkill(PChar, "Defence", 2000);
    		    AddCharacterExpToSkill(PChar, "Grappling", 2000);
		   		AddCharacterExpToSkill(PChar, "LeaderShip", 2000);
				AddCharacterExpToSkill(PChar, "Fortune", 2000);
    		    PChar.GenQuest.GhostShip.LastBattleEnd = true;
		   		DoQuestCheckDelay("sea_victory", 1.3);
    		    // меняем парус у корабля, если корабль взял ГГ
				sld = GetRealShip(sti(pchar.GenQuest.GhostShip.ShipType));
				DeleteAttribute(sld, "EmblemedSails.normalTex");
				
				AddSimpleRumourTip(LinkRandPhrase("О, сожри меня акула! Так вы и есть "+ GetSexPhrase("тот самый капитан","та морячка") +", что взял"+ GetSexPhrase("","а") +" ''Летучего Голландца''?! Разрази меня гром! Знатная, наверное, была баталия! Скажите, правду говорят, что его бывший капитан водил дружбу с самим Морским Дьяволом? А в команде у него были сплошь проклятые и отвергнутые Господом демоны, питающиеся кровью своих жертв?",
					"Капитан, а вы здесь весьма известны! Ходят слухи, что это вы упокоили старого Дейви Джонса и команду его мертвецов. Кто бы мог подумать, что ''Летучий Голландец'' перестанет быть призраком! Меняются времена, что ни говори... вот и еще одной легендой в этом мире стало меньше, хе-хе. Выпьем же за те тайны, которые океан хранит ещё в своих пучинах...",
					"Слыхали, что ''Летучий Голландец'' - этот неуловимый и непонятный человеку ужас морских стихий, нашел свой конец? И заметьте - от вполне смертных людей! Слышал я, один капитан смог разрушить проклятие и взял старого Дьявола призом, как простого купца... Вот так-то, в общем, бесславно и закончились бесчинства легендарного ''Корабля-Призрака''."), 
					60, 5, "habitue", "");	
            }
            else
            {
                Log_Info("Призрак повержен, но может ли он вернуться?");
                AddQuestRecord("GhostShipQuest", "Dead_1");
				AddQuestUserData("GhostShipQuest", "sSex", GetSexPhrase("ся","ась"));
                AddCharacterExpToSkill(PChar, "Sailing", 1000);
    		    AddCharacterExpToSkill(PChar, "Accuracy", 1000);
    		    AddCharacterExpToSkill(PChar, "Cannons", 1000);
    		    AddCharacterExpToSkill(PChar, "Repair", 1000);
    		    AddCharacterExpToSkill(PChar, "Defence", 1000);
    		    AddCharacterExpToSkill(PChar, "Grappling", 1000);
		   		AddCharacterExpToSkill(PChar, "LeaderShip", 1000);
				AddCharacterExpToSkill(PChar, "Fortune", 1000);
    		    PChar.GenQuest.GhostShip.DeadByMe = sti(PChar.GenQuest.GhostShip.DeadByMe) + 1;
    		    PChar.GenQuest.GhostShip.AskAbout    = 2; // опять будет

            }
        break;
        
		case "GhostCapt_OfferPrize":
			Sea_CabinStartNow();
			pchar.quest.GhostShipCapInCabin.win_condition.l1          = "location";
			pchar.quest.GhostShipCapInCabin.win_condition.l1.location = Get_My_Cabin();
			pchar.quest.GhostShipCapInCabin.win_condition             = "GhostShipCapInCabinOffer";					
		break;
		
		case "GhostShipCapInCabinOffer":
			chrDisableReloadToLocation = true;
			LAi_LockFightMode(pchar, true);	
			sld = CharacterFromID("GhostCapt");
			sld.name 	= "Дэйви";
			sld.lastname = "Джонс";
			sld.dialog.currentnode = "GhostCapt_Prize";
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.location, "rld", LAi_FindFarLocator("rld", locx, locy, locz));
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);		
		break;
		
		case "GhostShipCapInCabinDied":
			sld = CharacterFromID("GhostCapt");
			LAi_SetCurHP(sld, 0.0);
		break;

        case "GhostShipHelp": // битва в порту
            chrDisableReloadToLocation = true;
            Pchar.GenQuestFort.FarLocator = true;
			sTemp = "officers"; // не везде есть! :(
            for (i = 0; i < MAX_TOWN_CREW; i++)
            {
				sld = SetFantomSkeletForts(sTemp, "", "TOWN_BATTLE_SOLDIERS", "GhostShipCrew");
				sld.monster = true; // признак нежити
				sld.sex = "Skeleton"; 
				sld.viper = true;
				if (sld.location.locator == "")
				{
                    sTemp = "rld";
					sld = SetFantomSkeletForts(sTemp, "", "TOWN_BATTLE_SOLDIERS", "GhostShipCrew");
				sld.monster = true; // признак нежити
				sld.sex = "Skeleton"; 
				sld.viper = true;
				if (sld.location.locator == "") break;
				}
            }
            // наши
            Pchar.GenQuestFort.FarLocator = false;
            // помощь эскадре
            iTemp = sti(Characters[GetCharacterIndex(pchar.GenQuest.GhostShipWorkId)].nation);

            for (i = 0; i < MAX_ESCADRA_CREW; i++) //всегда 5 даем
            {
            	SetFantomGuardsMods("goto", "", iTemp, LAI_GROUP_PLAYER);
            }
            // натравим
            LAi_group_SetHearRadius("TOWN_BATTLE_SOLDIERS", 100.0);
            LAi_group_FightGroupsEx("TOWN_BATTLE_SOLDIERS", LAI_GROUP_PLAYER, true, Pchar, -1, false, false);
            LAi_group_SetRelation("TOWN_BATTLE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

            LAi_group_SetCheck("TOWN_BATTLE_SOLDIERS", "GhostShipHelp_Finish");
            LAi_SetFightMode(Pchar, true);
        break;

		case "GhostShipHelp_Finish":
            LAi_SetFightMode(Pchar, false);
            LAi_grp_alarmactive = false; // конец тревоги

            if (!CheckAttribute(pchar , "GenQuest.GhostShip.ChurchHelpStart"))
            {  // город
                sTemp = "GhostShipDone_" + pchar.GenQuest.GhostShipWorkId;
                pchar.GenQuest.(sTemp) = true;
                Log_Info("Мы отбились!");
                Statistic_AddValue(Pchar, "QuestGhostShipHelp_Done", 1);
                AddQuestRecord("GhostShipQuest", "help_t2");
            }
            else
            { // бухта
                pchar.GenQuest.GhostShip.ChurchHelp = true;
                Log_Info("Задание церкви выполнено!");
                DeleteAttribute(pchar , "GenQuest.GhostShip.ChurchHelpStart")
                //AddQuestTemplate("GhostShipQuest", "church_t2");
                Statistic_AddValue(Pchar, "QuestChurchHelpGhostShip_Done", 1);
            }
            PlaySound("interface\door_locked.wav");
            chrDisableReloadToLocation = false;
            bDisableFastReload         = false;
            SetLocationCapturedState(pchar.location, false);
        break;
        // помощь церкви
        case "GhostShipChurchShorePlace":
            Pchar.GenQuest.Hunter2Pause            = true;

            Pchar.GenQuest.GhostShip.ChurchHelpStart = true;

            chrDisableReloadToLocation = true;
            Pchar.GenQuestFort.FarLocator = true;
			sTemp = "officers"; // не везде есть! :(
            iTemp = 3 + rand(4);
            for (i = 0; i < iTemp; i++)
            {
				sld = SetFantomSkeletForts(sTemp, "", "SKEL_BATTLE_SOLDIERS", "GhostShipCrew");
				sld.monster = true; // признак нежити
				sld.sex = "Skeleton"; 
				sld.viper = true;
				if (sld.location.locator == "")
				{
                    sTemp = "reload"; // опасно - может быть лодка!
					sld = SetFantomSkeletForts(sTemp, "", "SKEL_BATTLE_SOLDIERS", "GhostShipCrew");
					sld.monster = true; // признак нежити
					sld.sex = "Skeleton"; 
					sld.viper = true;
				if (sld.location.locator == "") break;
				}
            }
            Pchar.GenQuestFort.FarLocator = false;

            // натравим
            LAi_group_SetHearRadius("SKEL_BATTLE_SOLDIERS", 100.0);
            LAi_group_FightGroupsEx("SKEL_BATTLE_SOLDIERS", LAI_GROUP_PLAYER, true, Pchar, -1, false, false);
            LAi_group_SetRelation("SKEL_BATTLE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

            LAi_group_SetCheck("SKEL_BATTLE_SOLDIERS", "GhostShipHelp_Finish");
            LAi_SetFightMode(Pchar, true);
        break;
        // GhostShipHelp <--

		//ОЗГ, Карлос Кассир
		case "CarlosDie":
			if (CheckAttribute(PChar, "quest.CarlosPlace")) Pchar.quest.CarlosPlace.over = "yes";
			if (CheckAttribute(PChar, "quest.HeadhunterTimer")) Pchar.quest.HeadhunterTimer.over = "yes";
			DoQuestCheckDelay("hide_weapon", 1.0);
			chrDisableReloadToLocation = false;
			LAi_LocationDisableOfficersGen(pchar.questTemp.Headhunter.City + "_ExitTown", false); //офицеров пускать
			locations[FindLocation(pchar.questTemp.Headhunter.City + "_ExitTown")].DisableEncounters = false; //энкаутеры закроем
			AddQuestRecord("Headhunt", "2");
			pchar.questTemp.Headhunter = "hunt_carlos_yes";
		break;
		
		//ОЗГ, наймиты Крысы
		case "RatHunters_Dead":
			chrDisableReloadToLocation = false;
			AddQuestRecord("Headhunt", "28");
			pchar.questTemp.Headhunter = "halen_still";
		break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "NarvalDestroyed":
			chrDisableReloadToLocation = false;
			pchar.questTemp.LSCC = "NarvalDestroyed";
			AddQuestRecord("ISS_MainLine", "13");
			int idxMent;
			string sOffName;
			for (i=1 ; i<=3; i++)
			{
				idxMent = GetCharacterIndex("Ment_" + i);
				if (idxMent != -1)
				{
					characters[idxMent].Dialog.CurrentNode = "AffterFightN";
					LAi_SetWarriorType(&characters[idxMent]);
					LAi_group_MoveCharacter(&characters[idxMent], LAI_GROUP_PLAYER_OWN);
				}
			}
			pchar.quest.NavalExitVelasco.win_condition.l1 = "ExitFromLocation";
			pchar.quest.NavalExitVelasco.win_condition.l1.location = pchar.location;
			pchar.quest.NavalExitVelasco.function = "NavalExitVelasco";
		break;

		case "LSCC_EnterComplite_1":			
			sld = characterFromId("LSCCMayor");
			LAi_SetActorType(sld);
			LAi_ActorTurnByLocator(sld, "quest", "stay1");
			LAi_SetStayType(sld);
			sld = characterFromId("Casper_head");
			if (sld.chr_ai.type == LAI_TYPE_STAY)
			{				
 				StartQuestMovie(true, true, true);
				SetMainCharacterIndex(GetCharacterIndex("Casper_head"));
				PChar   = GetMainCharacter();			
				locCameraToPos(77.3, 8.65, -30.9, false);
				LAi_SetActorType(PChar);
				LAi_ActorDialog(PChar, characterFromID("LSCCMayor"), "", 0, 0);
			}
		break;

		case "LSCC_EnterComplite_2":			
			sld = characterFromId("Casper_head");
			LAi_SetActorType(sld);
			LAi_ActorTurnByLocator(sld, "quest", "stay2");
			LAi_SetStayType(sld);
			sld = characterFromId("LSCCMayor");
			if (sld.chr_ai.type == LAI_TYPE_STAY)
			{			
 				StartQuestMovie(true, true, true);
				SetMainCharacterIndex(GetCharacterIndex("Casper_head"));
				PChar   = GetMainCharacter();			
				locCameraToPos(77.3, 8.65, -30.9, false);
				LAi_SetActorType(PChar);
				LAi_ActorDialog(PChar, characterFromID("LSCCMayor"), "", 0, 0);
			}
		break;

		case "LSCC_SesilAfraid":	
			sld = characterFromID("SesilGalard");
			LAi_SetActorTypeNoGroup(sld);
			LAi_ActorAfraid(sld, pchar, false);
		break;

		case "LSCC_SesilAfterFight":
			chrDisableReloadToLocation = false;			
			iTemp = GetCharacterIndex("SesilGalard");
			if (iTemp != -1 && !LAi_IsDead(&characters[iTemp]))
			{
				sld = &characters[iTemp];
				while (FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE) != "")
				{
					TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE));
				}
				sld.dialog.currentnode = "First time";
				sld.greeting = "Enc_RapersGirl_2";
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "TmpEnemy");
				LAi_ActorWaitDialog(sld, pchar);
				AddQuestRecord("ISS_MainLine", "28");
				AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("ел","ла"));
				AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("","а"));
				pchar.questTemp.LSCC = "toKnowAboutMechanic";
				AddSimpleRumourCityTip("Вы слышали, было совершено нападение на Сесил Галард!", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("Говорят, что вы спасли Сесил Галард, когда на неё напали.", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("На Сесил Галард напали в ее же доме, на налеоне 'Эва'!", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("Хорошо, что вы спасли бедную Сесил! Куда смотрит адмирал, непонятно...", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("М-да, если так пойдет дальше, то нам придется отбиваться от бандитов у себя в домах, как это сделала Сесил Галард.", "LostShipsCityy", 10, 1, "LSCC", "");
			}
			else
			{
				AddQuestRecord("ISS_MainLine", "29");
				AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("ел","ла"));
				AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("","а"));
				pchar.questTemp.LSCC = "SessilIsDead";
				AddSimpleRumourCityTip("Вы слышали, Сесил Галард убили в её же доме!", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("Говорят, что вы не сумели защитить бедную Сесил Галард...", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("М-да, очередная темная история с убийством. Знаете, как только вы появились в Городе, убийства следуют одно за другим. Теперь вот и Сесил Галард...", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("Жаль, что вам не удалось спасти Сесил. Она была очень хорошим человеком...", "LostShipsCityy", 10, 1, "LSCC", "");
				AddSimpleRumourCityTip("Очередное убийство. Теперь, вот, Сесил Галард мертва. А ведь она была старейшим жителем Города...", "LostShipsCityy", 10, 1, "LSCC", "");
			}
		break;

		case "LSCC_casperIsGone":			
			sld = &characters[sti(pchar.questTemp.LSCC.Armo.casperIdx)];
			LAi_ActorTurnByLocator(sld, "quest", "target");
			sld.checkChrDistance = 5; //проверять дистанцию до характерса
			sld.checkChrDistance.id = "Blaze"; //Id характерса
			sld.checkChrDistance.time = 0; //время повторной проверки
			sld.checkChrDistance.node = sld.id; //нода диалога
		break;

		case "LSCC_PrisonerAfterFight":		
			iTemp = GetCharacterIndex("LSCC_Prisoner1");
			if (!LAi_IsDead(&characters[iTemp]))
			{
				LAi_SetFightMode(pchar, false);
				characters[iTemp].dialog.currentnode = "AfterFightCasper";
				LAi_SetActorTypeNoGroup(&characters[iTemp]);
				LAi_ActorDialog(&characters[iTemp], pchar, "", -1.0, 0);
			}
		break;

		case "LSCC_PedroOpenedDoor":		
			sld = characterFromId("PedroHurtado");
            LAi_ActorTurnToLocator(sld, "goto", "goto04_5");
            LAi_ActorAnimation(sld, "Barman_idle", "LSCC_EndOpenDoor", 1.5);
            DoQuestFunctionDelay("LSCC_Click", 1.0);
		break;

		case "LSCC_EndOpenDoor":		
			sld = characterFromId("PedroHurtado");
			sld.dialog.currentNode = "StStart_Opened";
			LAi_ActorDialog(sld, pchar, "", 1.0, 0);
		break;

	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Пиратская линейка     начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "PiratesLine_toTavern":
			chrDisableReloadToLocation = true;
			bDisableFastReload = true; 
			FreeSitLocator("Vestpunt_tavern", "sit4");
			DoQuestReloadToLocation("Vestpunt_tavern", "sit", "sit4", "");			
			sld = characterFromID("QuestPirate1");        
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.5);		
		break;

		case "PiratesLine_q1_MorganGoTo":
            sld = characterFromID("Henry Morgan");
			sld.Dialog.CurrentNode = "PL_Q1_1";
            LAi_SetActorTypeNoGroup(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
		break;

		case "PQ5_Morgan_2":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Henry Morgan"));
			sld = characterFromID("CapGoodly"); 
			ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "goto", "goto1", "PQ5_Morgan_3", -1.0);
		break;

		case "PQ5_Morgan_3":
			SetMainCharacterIndex(GetCharacterIndex("CapGoodly"));
			PChar   = GetMainCharacter();			
			locCameraToPos(2.49, 2.65, -11.076, false);
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, characterFromID("Henry Morgan"), "", 0, 0);
		break;

		case "EdwardLoy_BlackLabel":
                                         StartPostVideo("Black_Label", 1);
		DoQuestCheckDelay("EdwardLoy_BlackLabel_1", 5.0);		
		break;
		case "EdwardLoy_BlackLabel_1":
		if (pchar.location == "LeFransua_House4")
		{
	                  QuestSetCurrentNode("EdwardLoy", "EdwardLoy_2");
                                     LAi_SetCitizenType(CharacterFromID("EdwardLoy"));
		DoQuestCheckDelay("EdwardLoy_BlackLabel_2", 0.1);
		}
		break;
		case "EdwardLoy_BlackLabel_2":
		PlayStereoSound("MUSIC\Risen2_Dark_Waters.mp3");
		break;

		case "PQ6_afterBattle":
			//убираем Джона Лидса
			chrDisableReloadToLocation = false;
			group_DeleteGroup("LidsGroup");
			LocatorReloadEnterDisable("Shore7", "boat", false); //откроем выход в море
			SetQuestHeader("Pir_Line_6_Jackman");
			AddQuestRecord("Pir_Line_6_Jackman", "4");
			AddQuestUserData("Pir_Line_6_Jackman", "sSex", GetSexPhrase("уничтожил своего 'родственничка', похож он был на меня очень сильно. Кто он, откуда, чем занимался","уничтожила свою 'сестричку', похожа она была на меня очень сильно. Кто она, откуда, чем занималась"));
			QuestSetCurrentNode("Torus", "PL_Q6_after");
		break;

		case "CitizSeekCap_afterCabinFight":
			sld = GetCharacter(NPC_GenerateCharacter(pchar.GenQuest.CitizSeekCap.label + "_" + pchar.GenQuest.CitizSeekCap.WifeCity, pchar.GenQuest.CitizSeekCap.model, pchar.GenQuest.CitizSeekCap.sex, pchar.GenQuest.CitizSeekCap.ani, 5, pchar.GenQuest.CitizSeekCap.nation, -1, false));
			sld.name = pchar.GenQuest.CitizSeekCap.WifeName;
			sld.lastname = pchar.GenQuest.CitizSeekCap.WifeLastname;
			sld.dialog.filename   = "Gothic_Quest\ForAll_dialog.c";
			sld.dialog.currentnode = pchar.GenQuest.CitizSeekCap.label + "_Board";
			sld.quest.SeekCap = pchar.GenQuest.CitizSeekCap.label;
			sld.quest.cribCity = pchar.GenQuest.CitizSeekCap.WifeCity;
			DeleteAttribute(pchar, "GenQuest.CitizSeekCap");
			LAi_SetStayType(sld);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.location, "rld", LAi_FindFarLocator("rld", locx, locy, locz));
			LAi_SetActorType(pchar);
			LAi_SetActorType(sld);
			SetActorDialogAny2Pchar(sld.id, "", 0.0, 0.0);
			LAi_ActorFollow(pchar, sld, "ActorDialog_Any2Pchar", -1);
		break;

		case "PQ8_jungle_afterFight":
			chrDisableReloadToLocation = false;
			pchar.questTemp.piratesLine = "Panama_inJungleIsOver";
			iTemp = GetCharacterIndex("Richard_Soukins");
			if(iTemp != -1 && !LAi_IsDead(&characters[iTemp]))
			{
				sld = &characters[iTemp];
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
				for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
				{
					iTemp = GetCharacterIndex("RSpirate_"+i);
					if(iTemp != -1)
					{
						LAi_group_MoveCharacter(&characters[iTemp], sld.chr_ai.group);
					}
				}
				for (i=1; i<=sti(pchar.questTemp.piratesLine.crewRichard); i++)
				{
					iTemp = GetCharacterIndex("RSmush_"+i);
					if(iTemp != -1)
					{
						LAi_group_MoveCharacter(&characters[iTemp], sld.chr_ai.group);
					}
				}
				for (i=1; i<=3; i++)
				{
					iTemp = GetCharacterIndex("RSofficer_"+i);
					if(iTemp != -1)
					{
						LAi_group_MoveCharacter(&characters[iTemp], sld.chr_ai.group);
					}
				}
			}
		break;

		case "PQ8_ExitTown_afterFight":
			LocatorReloadEnterDisable("Shore48", "boat", false); //откроем выход из бухты
			LocatorReloadEnterDisable("PortoBello_Jungle_01", "reload1_back", false); //открываем подходы к Панаме
			SetLocationCapturedState("Panama_town", true); //убираем всех из города
			sld = characterFromId("Henry Morgan");
			sld.dialog.currentNode = "PL_Q8_ExTPanama";
			ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Пиратская линейка     конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------ тюремный эскорт ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		case "PrisonEscort_begin":
		pchar.quest.PrisonEscortBegin.win_condition.l1 = "location";
		pchar.quest.PrisonEscortBegin.win_condition.l1.location = "Villemstad_town";
		pchar.quest.PrisonEscortBegin.win_condition = "PrisonEscort_Begin1";
		break;
		case "PrisonEscort_Begin1":
		DoQuestCheckDelay("PrisonEscort_Begin2", 1.0);
		break;
		case "PrisonEscort_Begin2":
	                        chrDisableReloadToLocation = true;//закрыть локацию
		iChar = NPC_GeneratePhantomCharacter("officer", HOLLAND, MAN, -1);
		chr = &characters[iChar];
		chr.id = "PrisonEscort_Officer";
		chr.greeting = "soldier_arest";
		chr.dialog.filename = "Gothic_Quest\Something1_dialog.c";
		chr.dialog.currentnode = "PrisonEscort_Officer";
	                         LAi_SetImmortal(chr, true);
	                         GetCharacterPos(pchar, &locx, &locy, &locz);
		 ChangeCharacterAddressGroup(chr, pchar.location, "officers", "reloadPr1_3");
	                          LAi_SetActorType(chr);
	                          LAi_ActorDialog(chr, pchar, "", -1, 0);

		iChar = NPC_GeneratePhantomCharacter("soldier", HOLLAND, MAN, -1);
		chr = &characters[iChar];
		chr.id = "PrisonEscort_Soldier";
		LAi_RemoveLoginTime(chr);
		LAi_SetActorType(chr);
		ChangeCharacterAddressGroup(chr, pchar.location, "officers", "reloadPr1_2");
		LAi_ActorFollow(chr, CharacterFromID("PrisonEscort_Officer"), "", -1);
		break;

		case "PrisonEscort_ToPrison":
	                        chrDisableReloadToLocation = false;
		ChangeCharacterAddressGroup(characterFromID("PrisonEscort_Officer"), "none", "", "");
		ChangeCharacterAddressGroup(characterFromID("PrisonEscort_Soldier"), "none", "", "");
		pchar.questTemp.PrisonEscort_quest = "to_prisone";			
		LAi_LocationDisableOfficersGen("Villemstad_prison", true);			
		DoQuestReloadToLocation("Villemstad_prison", "officers", "reload1_3", "PrisonEscort_DialogVsPrisonCeeper");
		break;

		case "PrisonEscort_DialogVsPrisonCeeper":
		LAi_SetActorType(pchar);
		LAi_ActorDialogNow(pchar, CharacterFromID("VillemstadJailOff"), "", 0.5);
		break;
		
		case "PrisonEscort_SartSearch":
		ChangeCharacterComplexReputation(pchar, "nobility", 1);		
		pchar.questTemp.PrisonEscort_quest = "start_search";
		SetQuestHeader("PrisonEscort1");
		AddQuestRecord("PrisonEscort1", "1");
		break;
		
		case "PrisonEscort_EmilioMovo":			
			pchar.questTemp.PrisonEscort_quest = "Emilio_Movo";
			iChar = NPC_GenerateCharacter("PrisonEscort_EmilioMovo", "pirate_8", "man", "man", sti(pchar.rank), PIRATE, -1, true, "marginal");
			chr = &characters[iChar];
			chr.name = "Эмилио";
			chr.lastname = "Мово";
			chr.model = "pirate_8";
			chr.greeting = "what_are_you_seek";
			chr.dialog.filename = "Gothic_Quest\Something1_dialog.c";
			chr.dialog.currentnode = "PrisonEscort_EmilioMovo";
			LAi_SetLoginTime(chr, 6.0, 22.0);
			ChangeCharacterAddressGroup(chr, "LeFransua_port", "goto", "goto18");
			LAi_SetCitizenType(chr);
		break;

		case "PrisonEscort_ToSea":
			AddQuestRecord("PrisonEscort1", "3");
			if(pchar.questTemp.PrisonEscort_quest == "Emilio_Movo_No_Money")
			{										
			pchar.quest.EmilioMovoNoMoney.win_condition.l1 = "location";
			pchar.quest.EmilioMovoNoMoney.win_condition.l1.location = "LeFransua_ExitTown";
			pchar.quest.EmilioMovoNoMoney.win_condition = "PrisonEscort_EmilioMovo_Attack";
			}
			else
			{
				AddMoneyToCharacter(pchar, -100);
				sld=(CharacterFromID("PrisonEscort_EmilioMovo"), 0);
			}

			pchar.questTemp.PrisonEscort_quest = "to_sea";
			iChar = NPC_GeneratePhantomCharacter("pirate", PIRATE, MAN, -1);
			chr = &characters[iChar];
			chr.id = "PrisonEscort_Captain";
	                                                chr.DontRansackCaptain = true;
	                                                chr.AnalizeShips = true;
	                                                chr.Alwaysenemy = true; // 260912
	                                                chr.Coastal_Captain = true;
	                                                chr.Ship.Mode = "pirate";			
	                                                FantomMakeSmallSailor(chr, SHIP_MAYFANG, "Вояджер", CANNON_TYPE_CANNON_LBS20, 50, 65, 65, 50, 90);
	                               SetShipSailsFromFile(chr, "ships/parus_silk_k.tga");
			string sGroup = "PrisonEscort_Captain_group";
			Group_FindOrCreateGroup(sGroup);			
			Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
			Group_LockTask(sGroup);
			Group_AddCharacter(sGroup, chr.id);
			Group_SetGroupCommander(sGroup, chr.id);			
			chr.mapEnc.type = "warrior";
			chr.mapEnc.worldMapShip = "quest_ship";
			chr.mapEnc.Name = "шебека 'Вояджер'";			
	                                                Map_CreateTrader("Shore38", "Shore30", "PrisonEscort_Captain", 10);//запуск энкаунтера - до Гваделупы
			
		pchar.quest.PrisonEscortCaptureShip.win_condition.l1 = "Character_Capture";
    		pchar.quest.PrisonEscortCaptureShip.win_condition.l1.character = "PrisonEscort_Captain";
    		pchar.quest.PrisonEscortCaptureShip.win_condition = "PrisonEscort_SinkShip";
    		
    		pchar.quest.PrisonEscortSinkShip.win_condition.l1 = "Character_sink";
    		pchar.quest.PrisonEscortSinkShip.win_condition.l1.character = "PrisonEscort_Captain";
    		pchar.quest.PrisonEscortSinkShip.win_condition = "PrisonEscort_CaptureShip";
		break;
		// Мово решил отомстить
		case "PrisonEscort_EmilioMovo_Attack":
		chrDisableReloadToLocation = true;			
		chr = CharacterFromID("PrisonEscort_EmilioMovo");
		chr.dialog.currentnode = "PrisonEscort_EmilioMovo_8";
		LAi_RemoveLoginTime(chr);
		LAi_NPC_equip(chr, 1, true, false);
		ChangeCharacterAddressGroup(chr, "LeFransua_ExitTown", "officers", "reload3_1");
		LAi_SetActorType(chr);
		LAi_ActorDialog(chr, pchar, "PrisonEscort_EmilioMovo_Fight", -1, 0.5);
		for(i=0; i<2; i++)
		{
		iChar = NPC_GeneratePhantomCharacter("pirate", PIRATE, MAN, -1);
		chr = &characters[iChar];
		chr.id = "EmilioMovo_Friend_"+i;
		LAi_RemoveLoginTime(chr);
		LAi_SetActorType(chr);
		ChangeCharacterAddressGroup(chr, "LeFransua_ExitTown", "officers", "reload3_2");
		LAi_ActorFollow(chr, CharacterFromID("PrisonEscort_EmilioMovo"), "", -1);
		}
		break;

		case "PrisonEscort_EmilioMovo_Fight":
		LAi_SetWarriorTypeNoGroup(CharacterFromID("PrisonEscort_EmilioMovo"));
		LAi_SetWarriorTypeNoGroup(CharacterFromID("EmilioMovo_Friend_0"));
		LAi_SetWarriorTypeNoGroup(CharacterFromID("EmilioMovo_Friend_1"));

		LAi_group_MoveCharacter(CharacterFromID("PrisonEscort_EmilioMovo"), "EnemyFight");
		LAi_group_MoveCharacter(CharacterFromID("EmilioMovo_Friend_0"), "EnemyFight");
		LAi_group_MoveCharacter(CharacterFromID("EmilioMovo_Friend_1"), "EnemyFight");

		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("EnemyFight", "PrisonEscort_EmilioMovo_Dead");
		break;

		case "PrisonEscort_EmilioMovo_Dead":
		LAi_SetFightMode(pchar, false);
			
		sld=(CharacterFromID("PrisonEscort_EmilioMovo"), 0);
		sld=(CharacterFromID("EmilioMovo_Friend_0"), 0);
		sld=(CharacterFromID("EmilioMovo_Friend_1"), 0);
			
		chrDisableReloadToLocation = false;
		bDisableFastReload = false;
		LAi_grp_playeralarm = 0;
		break;
		
		// Захватываем корабль
		case "PrisonEscort_SinkShip":
		DeleteQuestCheck("PrisonEscortCaptureShip");
		sld=(CharacterFromID("PrisonEscort_Captain"), 0);
		pchar.questTemp.PrisonEscort_quest = "sink_ship";			
		AddQuestRecord("PrisonEscort1", "5");
		break;
		
		// Топим корабль
		case "PrisonEscort_CaptureShip":
		DeleteQuestCheck("PrisonEscort_SinkShip");
		sld=(CharacterFromID("PrisonEscort_Captain"), 0);
		pchar.questTemp.PrisonEscort_quest = "Capture_ship";	
		AddQuestRecord("PrisonEscort1", "4");
		break;

		case "PrisonEscort_failed":
		DeleteAttribute(pchar, "questTemp.PrisonEscort_quest");
		AddQuestRecord("PrisonEscort1", "6");
		CloseQuestHeader("PrisonEscort1");
		break;

		case "PrisonEscort_complette":
                                      TakeItemFromCharacter(pchar, "PrisEscort_book");
		DeleteAttribute(pchar, "questTemp.PrisonEscort_quest");
		AddMoneyToCharacter(pchar, 15000);
		AddCharacterExpToSkill(pchar, "Sailing", 100);//навигация
		AddCharacterExpToSkill(pchar, "Sneak", 100);//скрытность
		AddCharacterExpToSkill(pchar, "Leadership", 80);
		ChangeCharacterComplexReputation(pchar, "nobility", 5);
		AddQuestRecord("PrisonEscort1", "7");
		CloseQuestHeader("PrisonEscort1");
		break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////

		case "Tenoc_youWinFight":
			pchar.questTemp.Tenoc = "YouWinGod"; //флаг конца линейки Тено
			LAi_SetFightMode(pchar, false);
			iTemp = GetCharacterIndex("AztecCitizen_1");
			if (iTemp != -1) characters[iTemp].dialog.currentnode = "Aztec1AF";
			iTemp = GetCharacterIndex("AztecCitizen_2");
			if (iTemp != -1) characters[iTemp].dialog.currentnode = "Aztec2AF";
			LocatorReloadEnterDisable("Tenochtitlan_1", "reload1_back", true);
			sld = characterFromId("Montesuma");
			sld.lastname = "II";
			sld.dialog.currentnode = "AfterGTemple";
			sld.reactionOnFightModeOn = true; 
			sld.BreakTmplAndFight = true;
			sld.SaveItemsForDead = true;
			sld.DontClearDead = true;
			sld.monster = true; 
			LAi_SetWarriorType(sld);
			LAi_warrior_SetStay(sld, true);
			LAi_RemoveLoginTime(sld);
			sld.viper = true;
			LAi_SetHP(sld, 700+MOD_SKILL_ENEMY_RATE*450, 700+MOD_SKILL_ENEMY_RATE*450);
			//GiveItem2Character(sld, "Totem_15");
			LAi_group_MoveCharacter(sld, "MontesumaGroup");

			ChangeCharacterAddressGroup(sld, "Tenochtitlan_1", "teleport", "fire1");
			pchar.quest.Tenoc_exitFromTenoc.win_condition.l1 = "locator";
			pchar.quest.Tenoc_exitFromTenoc.win_condition.l1.location = "Tenochtitlan_1";
			pchar.quest.Tenoc_exitFromTenoc.win_condition.l1.locator_group = "teleport";
			pchar.quest.Tenoc_exitFromTenoc.win_condition.l1.locator = "fire1";
			pchar.quest.Tenoc_exitFromTenoc.function = "Tenoc_exitFromTenoc";
			sld = characterFromId("DeadmansGod");
			sld.dialog.currentnode = "WinInTemple";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 1.0, 0);
		break;

		case "Tenoc_MontesumaArrived":
			sld = characterFromId("Montesuma");
			LAi_ActorTurnByLocator(sld, "quest", "quest1");
			LAi_SetWarriorTypeNoGroup(sld);
			LAi_warrior_SetStay(sld, true);
		break;

		case "Tenoc_GoDeadmansGod":
                                    PlaySound("VOICE\Russian\gotica\SFX\MFX_CONTROL_CAST.wav");
	                  DoQuestFunctionDelay("Tenoc_Temple", 3.2);
		break;

		case "Tenoc_Portal":
	                  pchar.quest.Tenoc_Portal_1.win_condition.l1 = "locator";
	                  pchar.quest.Tenoc_Portal_1.win_condition.l1.location = "Templee_17_1";
	                  pchar.quest.Tenoc_Portal_1.win_condition.l1.locator_group = "reload";
	                  pchar.quest.Tenoc_Portal_1.win_condition.l1.locator = "reload4";
		pchar.quest.Tenoc_Portal_1.win_condition = "Tenoc_Portal_1";
		n = Findlocation("Templee_17_1");
		locations[n].locators_radius.reload.reload6 = 1.2;
		break;

		case "Tenoc_Portal_1":
                                    PlaySound("VOICE\Russian\gotica\SFX\MFX_BREATHOFDEATH_CAST.wav");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
	                  pchar.quest.Tenoc_Portal_2.win_condition.l1 = "locator";
	                  pchar.quest.Tenoc_Portal_2.win_condition.l1.location = "Templee_great_2";
	                  pchar.quest.Tenoc_Portal_2.win_condition.l1.locator_group = "reload";
	                  pchar.quest.Tenoc_Portal_2.win_condition.l1.locator = "reload11";
		pchar.quest.Tenoc_Portal_2.win_condition = "Tenoc_Portal_2";
		break;

		case "Tenoc_Portal_2":
                                    PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEPORT_CAST.wav");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
	                  pchar.quest.Tenoc_Portal_3.win_condition.l1 = "locator";
	                  pchar.quest.Tenoc_Portal_3.win_condition.l1.location = "Templee_17_1";
	                  pchar.quest.Tenoc_Portal_3.win_condition.l1.locator_group = "reload";
	                  pchar.quest.Tenoc_Portal_3.win_condition.l1.locator = "reload6";
		pchar.quest.Tenoc_Portal_3.win_condition = "Tenoc_Portal_3";
		break;

		case "Tenoc_Portal_3":
                                    PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEPORT_CAST.wav");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload6", 1.20, 2, 2, "");
		DoQuestCheckDelay("Tenoc_Portal_1", 0.5);
		break;

		case "Tenoc_Portal_4":
                                    PlaySound("VOICE\Russian\gotica\SFX\MFX_BREATHOFDEATH_CAST.wav");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
	                  CreateLocationParticles("item", "reload", "reload11", 1.20, 2, 2, "");
		DoQuestCheckDelay("Tenoc_Portal_1", 0.5);
		break;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Квест Аскольда начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ==> Квест Аскольда.
	case "Ascold_begin":
                   pchar.questTemp.Ascold = "canTakeQuest";
	break;

	// выпивка с Аскольдом
	case "Ascold_DrinkWithFadey":
		LAi_SetActorType(pchar);
		LAi_ActorSetSitMode(pchar);
		InterfaceStates.Buttons.Save.enable = false;
		bDisableCharacterMenu = true;//лоченые интерфейсы
		DoQuestCheckDelay("Ascold_DrinkWithFadey_music", 0.8);
		DoQuestCheckDelay("Ascold_DrinkWithFadey_1", 90.0);
	break;
	
	case "Ascold_DrinkWithFadey_music":
		SetMusic("music_romantic2");
	break;
	
	case "Ascold_DrinkWithFadey_1":
		LAi_SetPlayerType(pchar);
		InterfaceStates.Buttons.Save.enable = true;
		bDisableCharacterMenu = false;//лоченые интерфейсы
		pchar.GenQuest.CamShuttle = 3;
		WaitDate("",0,0,0,5,5);
		DoQuestReloadToLocation("BasTer_houseSp1", "goto", "goto6", "Ascold_DrinkWithFadey_2");
	break;
	
	case "Ascold_DrinkWithFadey_2":
		sld = characterFromId("Ascold");
		LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		LAi_SetActorType(sld);
		LAi_ActorSetSitMode(sld);
	break;

        case "Ascold_AttackTenManowars":
	int iCannonType, iShipType;
	string sShipName;
	LocatorReloadEnterDisable("Tenotchitlan_Jungle_02", "reload3_back", true); //закроем до поры храм
	Island_SetReloadEnableGlobal("Caiman", false);
                   pchar.questTemp.Ascold = "ILookedThisAss";
            // ==> корабль, куда помещаем предметы
            i = rand(5)+1;
            pchar.questTemp.Ascold.Ship = "AscoldCaptainAttack_" + i;
            Log_QuestInfo("Журнал в мановаре с ID кэпа: " + pchar.questTemp.Ascold.Ship);
            // ==> меняем дейскрайб судового журнала
            ChangeItemDescribe("ShipsJournal_Ascold", "itmdescr_ShipsJournal_Ascold");
            Group_FindOrCreateGroup("Ascold_Spa_Attack");
           Group_SetType("Ascold_Spa_Attack", "war");
            // ==> Испанские кэпы
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			for (i = 1; i <=6; i++)
			{                
				Rank = 30 + rand(5);
				sTemp = "AscoldCaptainAttack_"+i;
				switch (i)
				{
				case 1:
				iCannonType = CANNON_TYPE_CANNON_LBS36;
				iShipType = SHIP_LSHIP_QUEST;
				sShipName = "Армада";
				Blade = "blade_13";
				break;
				case 2:
				iCannonType = CANNON_TYPE_CANNON_LBS32;
				iShipType = SHIP_LINESHIP;
				sShipName = "Сальвадор дель Мундо";
				Blade = "blade_19";
				break;
				case 3:
				iCannonType = CANNON_TYPE_CULVERINE_LBS18;
				iShipType = SHIP_VALCIRIA;
				sShipName = "Нуэстра Сеньора";
				Blade = "blade_13";
				break;
				case 4:
				iCannonType = CANNON_TYPE_CANNON_LBS24;
				iShipType = SHIP_POLACRE;
				sShipName = "Принсипе де Астуриас";
				Blade = "blade_14";
				break;
				case 5:
				iCannonType = CANNON_TYPE_CANNON_LBS20;
				iShipType = SHIP_CORVETTE;
				sShipName = "Санта Исавель";
				Blade = "blade_18";
				break;
				case 6:
				iCannonType = CANNON_TYPE_CANNON_LBS16;
				iShipType = SHIP_SCHOONER_W;
				sShipName = "Анхэль де ля Гуарда";
				Blade = "blade_22";
				break;
				}
				sld = GetCharacter(NPC_GenerateCharacter(sTemp, "off_spa_"+(rand(5)+1), "man", "man", Rank, SPAIN, -1, true, "quest"));	
				FantomMakeCoolSailor(sld, iShipType, sShipName, iCannonType, 90, 90, 90);
				FantomMakeCoolFighter(sld, Rank, 90, 90, Blade, "pistol5", "cartridge", 10);
				sld.DontRansackCaptain = true;
				sld.AnalizeShips = true;
				sld.SuperShooter  = true;
SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
				sld.ship.Crew.Morale = 100;
	                                                          LAi_SetCharacterUseBullet(sld, "cartridge");
                                                                             TakeNItems(sld, "grapeshot", 15);
	                                                          TakeNItems(sld, "bullet", 12);
	                                                          TakeNItems(sld, "cartridge", 9);
	                                                          TakeNItems(sld, "GunPowder", 13);
				ChangeCrewExp(sld, "Sailors", 100);
				ChangeCrewExp(sld, "Cannoners", 100);
				ChangeCrewExp(sld, "Soldiers", 100);
				SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
				Group_AddCharacter("Ascold_Spa_Attack", sTemp);
			}
            // ==> стравливание
	Group_SetGroupCommander("Ascold_Spa_Attack", "AscoldCaptainAttack_1");		
	//Group_SetPursuitGroup("Ascold_Spa_Attack", PLAYER_GROUP); //TO_DO
	Group_SetAddress("Ascold_Spa_Attack", "Caiman", "quest_ships", "quest_ship_6");
	Group_SetTaskAttack("Ascold_Spa_Attack", PLAYER_GROUP);
	Group_LockTask("Ascold_Spa_Attack");
            // ==> прерывание на убиение эскадры
            pchar.quest.Ascold_VictoryManowar.win_condition.l1 = "Group_Death";
            pchar.quest.Ascold_VictoryManowar.win_condition.l1.group = "Ascold_Spa_Attack";
            pchar.quest.Ascold_VictoryManowar.win_condition = "Ascold_VictoryManowar";
            pchar.quest.Ascold_DieHardManowar.win_condition.l1 = "MapEnter";
            pchar.quest.Ascold_DieHardManowar.win_condition = "Ascold_DieHardManowar";
            //SetTimerCondition("Ascold_ManowarRepair", 0, 0, 10, true);
            break;

                       case "Ascold_VictoryManowar":
	 //PChar.quest.Ascold_ManowarRepair.over = "yes";
	    DoQuestCheckDelay("sea_victory", 1.5);
	    LocatorReloadEnterDisable("Tenotchitlan_Jungle_02", "reload3_back", false); //откроем храм
	     Island_SetReloadEnableGlobal("Caiman", true);
                         group_DeleteGroup("Ascold_Spa_Attack");
	      pchar.quest.Ascold_DieHardManowar.over = "yes";
                         pchar.questTemp.Ascold = "Ascold_ManowarsDead";
                         DeleteAttribute(PChar, "questTemp.Ascold.Ship");
                         AddQuestRecord("Ascold", "9");
                         AddQuestUserData("Ascold", "sSex", GetSexPhrase("","а"));
                         pchar.quest.Temple_ArriveTohore.win_condition.l1 = "location";
                         pchar.quest.Temple_ArriveTohore.win_condition.l1.location = "Shore9";
                         pchar.quest.Temple_ArriveTohore.function = "Temple_ArriveTohore";
                         break;

                        case "Ascold_DieHardManowar":
                        Island_SetReloadEnableGlobal("Caiman", true);
                        group_DeleteGroup("Ascold_Spa_Attack");
                        pchar.quest.Ascold_VictoryManowar.over = "yes";
                        pchar.questTemp.Ascold = "Ascold_ManowarsNoDead";
                        DeleteAttribute(PChar, "questTemp.Ascold.Ship");
                        AddQuestRecord("Ascold", "9_1");
                        AddQuestUserData("Ascold", "sSex", GetSexPhrase("","а"));
                        break;


	case "Temple_MCSoldiersReset": // 160912
	chrDisableReloadToLocation = false;//открыть локацию
	for(i=1; i<=iTotalTemp; i++)
	{
	if (GetCharacterIndex("Temple_Oursoldier_"+i) != -1)
	{
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}	
              }
                   Pchar.quest.Ascold_FightNearTemple.win_condition.l1 = "location";
                   Pchar.quest.Ascold_FightNearTemple.win_condition.l1.location = "Temple";
                   Pchar.quest.Ascold_FightNearTemple.win_condition = "Ascold_FightNearTemple";
                   break;


              case "Ascold_FightNearTemple":
              chrDisableReloadToLocation = true; // закрыть выход из локации
              LAi_group_Delete("EnemyFight");

            for (i=1; i<=20; i++)
             {
                if (i==1 || i==15 || i==17 || i==19) 
                  {					
	sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "off_spa_"+(rand(5)+1), "man", "man", 25, SPAIN, 0, true, "soldier"));	
	FantomMakeCoolFighter(sld, 55, 80, 80, BLADE_LONG, "pistol5", "cartridge", 100);
                   }
	else
                  {
	sld = GetCharacter(NPC_GenerateCharacter("Enemy_"+i, "guard_spa_"+(rand(7)+1), "man", "man", 20, SPAIN, 0, true, "officer"));	
	FantomMakeCoolFighter(sld, 60, 70, 90, BLADE_LONG, "pistol2", "cartridge", 40);
                   }

            	LAi_SetWarriorType(sld);				
	if (i < 16) LAi_warrior_SetStay(sld, true);
	LAi_group_MoveCharacter(sld, "EnemyFight");				
                   ChangeCharacterAddressGroup(sld, "Temple", "goto",  "goto"+i);
                   LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
               //LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
                   LAi_group_SetCheck("EnemyFight", "Ascold_WinNearTemple");		
                    }

	// наши 
	for(i=1; i<=iTotalTemp; i++)
	{
	if (GetCharacterIndex("Temple_Oursoldier_"+i) != -1)
	{
	sld = characterFromID("Temple_Oursoldier_"+i);
	if (CheckAttribute(pchar, "questTemp.Temple.Ascold"))
	{
	if (i < 8) ChangeCharacterAddressGroup(sld, "Temple", "goto", "goto"+i);
	}
	else ChangeCharacterAddressGroup(sld, "Temple", "goto", "goto"+i);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	}
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "");
	LAi_SetFightMode(pchar, true);
	}
                    break;

                    case "Ascold_WinNearTemple":
                    chrDisableReloadToLocation = false;

		for(i=1; i<=iTotalTemp; i++)
			{
			sld = characterFromID("Temple_Oursoldier_"+i);
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}

                     LocatorReloadEnterDisable(pchar.location, "reload2", false);            
                     AddQuestRecord("Ascold", "14");
                     pchar.quest.Ascold_fightInsideTemple.win_condition.l1 = "location";			                     pchar.quest.Ascold_fightInsideTemple.win_condition.l1.location = "Temple_Inside";
                     pchar.quest.Ascold_fightInsideTemple.function = "Ascold_fightInsideTemple";	
                     break;

	case "Temple_OpenTheDoors": 
	chrDisableReloadToLocation = false;//открыть локацию
	LocatorReloadEnterDisable("Shore9", "boat", false);
                   DeleteAttribute(pchar, "GenQuest.CannotWait");//запрет ожидания
	locations[FindLocation("Beliz_jungle_02")].DisableEncounters = false; //энкаутеры закрыть
	for(i=2; i<=4; i++)
	{
	locations[FindLocation("Beliz_Jungle_0"+i)].DisableEncounters = false;
	}
	for(i=1; i<=iTotalTemp; i++)
	{
	if (GetCharacterIndex("Temple_Oursoldier_"+i) != -1)
	{
	sld = characterFromID("Temple_Oursoldier_"+i);
	sld.lifeday = 0;
	}
              }
                   break;


       
                   case "Ascold_InGraveAfterFight":
	pchar.questTemp.Ascold = "Ascold_MummyIsLive";
                   LAi_LocationFightDisable(&Locations[FindLocation("Guadeloupe_Cave")], true); 
	sld = GetCharacter(NPC_GenerateCharacter("LeifEricson", "Mummy", "skeleton", "skeleton", 100, PIRATE, -1, true, "quest"));	
	FantomMakeCoolFighter(sld, 100, 100, 100, "topor_06", "", "", 3000);
	sld.name = "Лейф";
	sld.lastname = "Эриксон";
	sld.Dialog.Filename = "Gothic_Quest\LeifEricson.c";
                   sld.SaveItemsForDead = true; // сохранять на трупе вещи
	GiveItem2Character(sld, "Azzy_bottle");
                   sld.DontClearDead = true; // не убирать труп через 200с
	ChangeCharacterAddressGroup(sld, pchar.location, "goto",  "locator1");
	LAi_SetImmortal(sld, true);
	LAi_CharacterPlaySound(sld, "Gr_LeifEricson");
	LAi_SetActorType(pchar);
	LAi_SetActorType(sld);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	SetActorDialogAny2Pchar("LeifEricson", "", -1, 0.0);
	LAi_ActorFollow(PChar, sld, "ActorDialog_Any2Pchar", 0.0);
                   break;

        case "Ascold_MummyFightTown":
            for (i=1; i<=6; i++)
            {
				sld = characterFromId("MySkel"+i);	
				sld.LifeDay = 0;
				ChangeCharacterAddress(sld, "none", "");
            }
    	    Pchar.GenQuestFort.fortCharacterIdx = GetCharIDXForTownAttack(pchar.location);
    	    DeleteQuestAttribute("Union_with_Escadra");
            sld = GetCharacter(sti(Pchar.GenQuestFort.fortCharacterIdx));
            SetLocationCapturedState("BasTer_town", true);
            DoQuestCheckDelay("Capture_Forts", 0.5);
            Ship_NationAgressive(sld, sld);
            Log_SetStringToLog("За свое тело я иcкромсаю всех лягушатников на этом острове!");
			characters[GetCharacterIndex("BasTer_Mayor")].dialog.captureNode = "Ascold_MummyAttack"; //капитулянтская нода мэра
        break;

                                       case "Ascold_XsardasIsFree":
                                                          DoQuestReloadToLocation("Terrain", "reload", "reload2", "Ascold_Xsardas_1");
         break;
		case "Ascold_Xsardas_1":
			ChangeShowIntarface();
			LAi_SetPlayerType(pchar);
			pchar.questTemp.Ascold.Xsardas = "true";
			DoQuestCheckDelay("TalkSelf_Quest", 0.1);
        break;
		case "Ascold_Xsardas_2":
			SetMusic("music_Gothic_terrain");
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "reload", "reload1");
			DoQuestCheckDelay("Ascold_Xsardas_2_1", 4.0);
			DeleteAttribute(pchar, "questTemp.Ascold.Xsardas"); // 021012
        break;
		case "Ascold_Xsardas_2_1":
                                      PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEKINESIS_CAST.wav");
		CreateLocationParticles("shadowstar", "reload", "reload1", 1.15, 0, 0, "");
		CreateLocationParticles("shadowstar", "reload", "reload1", 1.15, 0, 0, "");
		CreateLocationParticles("shadowstar", "reload", "reload1", 1.15, 0, 0, "");
		DoQuestCheckDelay("Ascold_Xsardas_2_2", 3.0);
        break;
		case "Ascold_Xsardas_2_2": // встреча с Ксардасом
			sld = GetCharacter(NPC_GenerateCharacter("Xsardas", "Xsardas", "man", "man", 1, PIRATE, 0, false, "quest"));
			sld.name = "Ксардас";
			sld.lastname = "";
			sld.greeting = "";
			sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Xsardas.c";
			sld.dialog.currentnode = "Xsardas";
			ChangeCharacterAddressGroup(sld, "Terrain", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload2", "", -1);
			DoQuestCheckDelay("Ascold_Xsardas_3", 15.5);
        break;
		case "Ascold_Xsardas_3": // Ксардас начинает разговор
			LAi_SetPlayerType(pchar);
			sld = characterFromId("Xsardas");
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			SetMusic("music_romantic");
        break;
		
                 case "Ascold_Xsardas_4": // Начало ГПК	
                 DoQuestFunctionDelay("Go_ShipsCityy", 1.0);
                 break;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Квест Аскольда-Аззи конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////



//==================================================================
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- Розо или Шарлотт-Таун ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

		case "Killwork_huber_hour_00":
	                   LocatorReloadEnterDisable("Roseau_town", "reload1_back", false);//город открыть
	                   LocatorReloadEnterDisable("Roseau_town", "gate_back", false);//город открыть
		break;

		case "OpenRoseauBrothel":
		sld = characterFromId("Torus");
		pchar.quest.Torus_Go.win_condition.l1 = "location";
		pchar.quest.Torus_Go.win_condition.l1.location = "Roseau_SecBrRoom";
		pchar.quest.Torus_Go.function = "InRoseauSecBrRoom";
		break;

		case "TorusTalkWithRoseauHostess":
	                   LAi_ActorTurnToCharacter(sld, characterFromID("Roseau_Hostess"));	
		LAi_SetPlayerType(PChar);
		sld = characterFromId("Torus");
		sld.Dialog.Filename = "Mayor\Torus.c";
		sld.dialog.currentnode = "RoseauCharlotte_Brothel";
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", 0, 0);
		break;

		case "DoubleTalkWithRoseauHostess":	
		sld = characterFromId("Roseau_Hostess");
 		LAi_ActorTurnToCharacter(sld, characterFromID("Roseau_Hostess"));
		sld.Dialog.Filename = "Mayor\Torus.c";
		sld.dialog.currentnode = "RoseauCharlotte_Brothel_5";
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", 0, 0);
		break;


	case "GothicTorus_RoseauCharlotte_01":
                   AddQuestRecord("RoseauCharlotte", "4"); 
	LocatorReloadEnterDisable("Roseau_exittown", "reload1_back", true);
	LAi_SetPlayerType(pchar);
	DoReloadCharacterToLocation("Roseau_exittown", "reload", "reload1_back");
	DeleteAttribute(pchar, "questTemp.GothicTorus_RoseauCharlotte"); // 021012
	break;

//=================== Розо или Шарлотт-Таун. Сон ГГ ===================

	case "GothicTorus_fake_1":
	GiveItem2Character(pchar, "potion2");
	GiveItem2Character(pchar, "potion1");
	PauseAllSounds();
	//Заставка
	SetLaunchFrameFormParam("Пророческий сон...", "Reload_To_Location", 1, 3); 
	SetLaunchFrameReloadLocationParam("LostShipsCity_town_fake", "goto", "goto02_5", "");
	LaunchFrameForm();	
                   LAi_SetActorType(pchar);
	pchar.questTemp.GothicTorus_fake.Xsardas = "true";
	DoQuestCheckDelay("TalkSelf_Quest", 7.0);
	break;

	case "GothicTorus_fake_01":
                   LAi_SetActorType(pchar);
	LAi_ActorTurnToLocator(pchar, "goto", "goto02_4");
	DoQuestCheckDelay("GothicTorus_fake_02", 4.0);
	DeleteAttribute(pchar, "questTemp.GothicTorus_fake.Xsardas"); // 021012
	break;

	case "GothicTorus_fake_02":
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_TELEKINESIS_CAST.wav");
	CreateLocationParticles("item", "goto", "goto02_4", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto02_4", 1.20, 2, 2, "");
	CreateLocationParticles("item", "goto", "goto02_4", 1.20, 2, 2, "");
	DoQuestCheckDelay("GothicTorus_fake_03", 4.0);
                   break;

	case "GothicTorus_fake_03":
	sld=characterFromID("Xsardas");
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Xsardas.c";
	sld.Dialog.CurrentNode = "GothicTorus_fake_night";
	ChangeCharacterAddressGroup(sld,"LostShipsCity_town_fake", "goto", "goto02_4"));
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "goto", "goto02_5", "", -1);
	
	sld = GetCharacter(NPC_GenerateCharacter("Maryy", "Mary", "woman", "mary", 10, Pirate, -1, true, "quest"));
	sld.name 	= "Мэри";
       	sld.lastname = "Каспер";
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Mary_dialog.c";
	sld.Dialog.CurrentNode = "First time";
	sld.greeting = "";
	GiveItem2Character(sld, "blade_17");
	sld.equip.blade = "blade_17";
	GiveItem2Character(sld, "pistol4");
	EquipCharacterbyItem(sld, "pistol4");
	GiveItem2Character(sld, "cirass6");
	EquipCharacterbyItem(sld, "cirass6");
	LAi_SetCharacterUseBullet(sld, "bullet");
                   TakeNItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	TakeNItems(sld, "potion2", 5);
	ChangeCharacterAddressGroup(sld,"LostShipsCity_town_fake", "goto", "goto06_0"));
	LAi_SetActorType(sld);
	Lai_SetImmortal(sld,true);
	
	sld2 = GetCharacter(NPC_GenerateCharacter("Capperr", "Chad", "man", "man", 1, PIRATE, -1, false, "quest"));
	sld2.name = "Чад";
	sld2.lastname = "Каппер";
	sld2.greeting = "";
	sld2.rank = 30;
	LAi_SetHP(sld2, 150+MOD_SKILL_ENEMY_RATE*30, 150+MOD_SKILL_ENEMY_RATE*30); 
	SetSelfSkill(sld2, 70, 80, 90, 90, 70);
	SetShipSkill(sld2, 40, 40, 60, 60, 80, 40, 100, 20, 20);
	SetSPECIAL(sld2, 9, 5, 9, 4, 4, 10, 6);
	SetCharacterPerk(sld2, "Energaiser");
	SetCharacterPerk(sld2, "BasicDefense");
	SetCharacterPerk(sld2, "AdvancedDefense");
	SetCharacterPerk(sld2, "ProfessionalDefense");
	SetCharacterPerk(sld2, "CriticalHit");
	SetCharacterPerk(sld2, "Tireless");
	SetCharacterPerk(sld2, "Gunman");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld2, "SwordplayProfessional");
	SetCharacterPerk(sld2, "HardHitter");
	SetCharacterPerk(sld2, "LongRangeGrappling");
	SetCharacterPerk(sld2, "GrapplingProfessional");
	GiveItem2Character(sld2, "blade_16");
	sld2.equip.blade = "blade_16";
	GiveItem2Character(sld2, "pistol4");
	EquipCharacterbyItem(sld2, "pistol4");
	LAi_SetCharacterUseBullet(sld2, "bullet");
                   TakeNItems(sld2, "bullet", 50);
	AddItems(sld2, "gunpowder", 50);
	ChangeCharacterAddressGroup(sld2,"LostShipsCity_town_fake", "goto", "goto06_1"));
	LAi_SetActorType(sld2);
	Lai_SetImmortal(sld2,true);	
	DoQuestCheckDelay("GothicTorus_fake_2", 11.0);
	break;

	case "GothicTorus_fake_2":
	ResumeAllSounds();
	sld=characterFromID("Maryy");
	sld2=characterFromID("Capperr");
	LAi_ActorAttack(sld, sld2, "");
	LAi_ActorAttack(sld2, sld, "");
	
	LAi_SetPlayerType(pchar);
	sld = characterFromId("Xsardas");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicTorus_fake_3":
	sld=characterFromID("Xsardas");
	LAi_SetActorType(sld);
                   LAi_SetActorType(pchar);
	LAi_ActorGoToLocation(sld, "goto", "goto02_4", "none", "", "", "", 12.0);	
	Lai_SetImmortal(sld,true);
	DoQuestCheckDelay("GothicTorus_fake_skel03", 20.0);
	
	pchar.quest.GothicTorus_fake_4.win_condition.l1 = "locator";
	pchar.quest.GothicTorus_fake_4.win_condition.l1.location = "LostShipsCity_town_fake";
	pchar.quest.GothicTorus_fake_4.win_condition.l1.locator_group = "item";
	pchar.quest.GothicTorus_fake_4.win_condition.l1.locator = "parol2";
	pchar.quest.GothicTorus_fake_4.win_condition = "GothicTorus_fake_4";
	//pchar.quest.GothicTorus_fake_4.win_condition = "GothicTorus_fake_4_win1";
	break;

	case "GothicTorus_fake_skel03":
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_CONTROL_CAST.wav");
	Lai_SetPlayerType(pchar);
	sld=GetCharacter(NPC_GenerateCharacter("Gothic_skel_1", "skel1", "skeleton", "skeleton", 2, pirate, -1, true, "quest"));
	ChangeCharacterAddressGroup(sld,"LostShipsCity_town_fake", "goto", "goto02_4");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.SaveItemsForDead   = false;

	sld=GetCharacter(NPC_GenerateCharacter("Gothic_skel_2", "skel2", "skeleton", "skeleton", 2, pirate, -1, true, "quest"));
	ChangeCharacterAddressGroup(sld,"LostShipsCity_town_fake", "goto", "goto02_4");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	sld.SaveItemsForDead   = false;

	sld=GetCharacter(NPC_GenerateCharacter("Gothic_skel_3", "skel3", "skeleton", "skeleton", 2, pirate, -1, true, "quest"));
	ChangeCharacterAddressGroup(sld,"LostShipsCity_town_fake", "goto", "goto02_4");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);
	sld.SaveItemsForDead   = false;
	sld.monster = true; // признак нежити
	sld.sex = "Skeleton"; 
	sld.viper = true;
	DoQuestCheckDelay("GothicTorus_fake_04", 4.0);	
	break;

	case "GothicTorus_fake_04":
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_WARN01.wav");
	DoQuestCheckDelay("GothicTorus_fake_05", 4.0);	
	break;

	case "GothicTorus_fake_05":
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE01.wav");
	DeleteAttribute(pchar, "questTemp.GothicTorus_fake.Xsardas"); // 021012
	DoQuestCheckDelay("GothicTorus_fake_06", 4.0);	
	break;

	case "GothicTorus_fake_06":
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_ATTACK01.wav");
	DoQuestCheckDelay("GothicTorus_fake_07", 4.0);	
	break;

	case "GothicTorus_fake_07":
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_ATTACK01.wav");
	DoQuestCheckDelay("GothicTorus_fake_08", 4.0);	
	break;
	
	case "GothicTorus_fake_08":
                   PlaySound("VOICE\Russian\gotica\SFX\DEM_DIE02.wav");	
	pchar.quest.GothicTorus_fake_4_win.win_condition.l1 = "NPC_Death";
	pchar.quest.GothicTorus_fake_4_win.win_condition.l1.character = GetCharacterIndex("Gothic_skel_1");
	pchar.quest.GothicTorus_fake_4_win.win_condition.l2 = "NPC_Death";
	pchar.quest.GothicTorus_fake_4_win.win_condition.l2.character = GetCharacterIndex("Gothic_skel_2");
	pchar.quest.GothicTorus_fake_4_win.win_condition.l3 = "NPC_Death";
	pchar.quest.GothicTorus_fake_4_win.win_condition.l3.character = GetCharacterIndex("Gothic_skel_3");
	pchar.quest.GothicTorus_fake_4_win.win_condition = "GothicTorus_fake_4_win";

	pchar.quest.GothicTorus_fake_4_win1.win_condition.l1 = "locator";
	pchar.quest.GothicTorus_fake_4_win1.win_condition.l1.location = "LostShipsCity_town_fake";
	pchar.quest.GothicTorus_fake_4_win1.win_condition.l1.locator_group = "item";
	pchar.quest.GothicTorus_fake_4_win1.win_condition.l1.locator = "parol2";
	pchar.quest.GothicTorus_fake_4_win1.win_condition = "GothicTorus_fake_4_win1";	
	break;
	
	case "GothicTorus_fake_4_win":
	Lai_SetPlayerType(pchar);
	DeleteQuestAttribute("GothicTorus_fake_4");
	sld=characterFromID("Xsardas");
	sld.Dialog.CurrentNode = "GothicTorus_fake_night_Sound";
	LAi_SetOfficerType(sld);	
	break;
		
	case "GothicTorus_fake_4_win1":
	sld2=characterFromID("Capperr");
	Lai_SetStayType(sld2);
	sld=characterFromID("Maryy");
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Mary_dialog.c";
	sld.Dialog.CurrentNode = "GothicTorus_fake";
	LAi_SetActorType(sld);
	LAi_ActorWaitDialog(sld, pchar);
	LAi_SetActorType(pchar);
	LAi_ActorDialogNow(pchar, sld, "",-1);
	break;
	
	case "GothicTorus_fake_4_win1_Mary":
	DeleteQuestAttribute("GothicTorus_fake_4_win1");
	sld=characterFromID("Maryy");
	sld2=characterFromID("Capperr");
	//ВЫСТРЕЛ!	
	 LAi_SetFightMode(sld2, true);
                    LAi_SetActorTypeNoGroup(sld2);
                    LAi_ActorTurnToCharacter(sld2, sld);
                    LAi_ActorAnimation(sld2, "Shot", "GothicTorus_fake_4_win1_Mary1", 1.5);
	break;
                   case "GothicTorus_fake_4_win1_Mary1":
                   PlaySound("People Fight\Afraid_death_woman_03.wav");
	sld=characterFromID("Maryy");
	SetCharacterTask_Dead(sld);
                   DoQuestCheckDelay("GothicTorus_fake_4_win1_Mary2", 4.0);
	break;
		
	case "GothicTorus_fake_4_win1_Mary2":
	Lai_SetStayType(pchar);
	DoQuestCheckDelay("GothicTorus_fake_4_win1_Mary3", 0.1);
	break;
	
	case "GothicTorus_fake_4_win1_Mary3":
	sld2=characterFromID("Capperr");
	sld2.Dialog.Filename = "Gothic_Quest\Gothic_npc\Mary_dialog.c";
	sld2.Dialog.CurrentNode = "GothicTorus_fake_night";
	LAi_SetActorType(sld2);
	LAi_ActorDialogNow(sld2, pchar, "",-1);
	break;
	
	case "GothicTorus_fake_4_win1_Mary4":
	LAi_RemoveCheckMinHP(characterFromID("Maryy"));
	DoQuestCheckDelay("GothicTorus_fake_4_win1_Mary5", 1.0);
	break;
	
	case "GothicTorus_fake_4_win1_Mary5":
	PauseAllSounds();
	Lai_SetStayType(pchar);
	DoReloadCharacterToLocation("Roseau_tavern_upstairs", "quest", "quest4");
	LAi_SetHP(pchar, LAi_GetCharacterMaxHP(pchar), LAi_GetCharacterMaxHP(pchar));
	pchar.questTemp.GothicTorus_RoseauCharlotte.fake = "true";
	DoQuestCheckDelay("TalkSelf_Quest", 3.0);
	break;

	case "GothicTorus_fake_tavern_morning1":
	Lai_SetPlayerType(pchar);
	sld2 = characterFromId("Capperr");
                   LAi_ActorGoToLocation(sld2, "reload", "reload1_back", "none", "", "", "", 10.0);
	sld = characterFromId("Maryy");
                   LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
	break;

	case "NoKillwork_Mayor_3":
		sld = characterFromId("Torus");
                                      ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		sld.dialog.currentnode = "NoKillwork_7";
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", 2.0, -1);
	break;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Квест, похищение донны Анны
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		case "GothicLeeTakeAnna_FightInHouse":
			chrDisableReloadToLocation = true;
			LAi_LocationFightDisable(loadedLocation, true); 
			LAi_group_Delete("PeaceGroup");
                                                              sld = characterFromId("AnnaDeLeiva");
	                                         sld.Dialog.Filename = "Gothic_Quest\GothicLine\AnnaDeLeiva.c";
	                                         sld.dialog.currentnode = "AnnaDeLeiva_TakeAnna";
			sld.RebirthPhantom = true; 
			LAi_NoRebirthEnable(sld);
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "PeaceGroup");
			ChangeCharacterAddressGroup(sld, "Havana_houseS1Bedroom", "goto","goto7");
			GetCharacterPos(pchar, &locx, &locy, &locz);
			LAi_group_Delete("EnemyFight");
			for (i=1; i<=5; i++)
			{
				Model = "guard_spa_"+(rand(7)+1);
				sTemp = 18;
				attrName = "SpaFighter"+i;
				if (i==1) 
				{	
					Model = "off_spa_6";
					sTemp = 23;
					attrName = "DeLeiva";
				}
				sld = GetCharacter(NPC_GenerateCharacter(attrName, Model, "man", "man", sTemp, SPAIN, 0, true, "officer"));
				FantomMakeCoolFighter(sld, sTemp, 70, 50, BLADE_LONG, "pistol2", "bullet", 40);
				LAi_SetWarriorType(sld);
				if (i==1) 
				{
					sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_1.c";
					sld.name = "Хосе";
					sld.lastname = "Рамирес де Лейва";
	                                                                                   TakeNItems(sld, "DOjeronRing", 1);
	                                                                                   sld.SaveItemsForDead = true; // сохранять на трупе вещи
		                                                               sld.DontClearDead = true; // не убирать труп через 200с
					ChangeCharacterAddressGroup(sld, "Havana_houseS1", "goto", "goto2");					
				}
				else 
				{
					LAi_warrior_DialogEnable(sld, false);	
					ChangeCharacterAddressGroup(sld, "Havana_houseS1", "goto", "goto5");
				}
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			sld = characterFromId("DeLeiva");
			LAi_SetActorTypeNoGroup(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			DoQuestCheckDelay("MainHeroFightModeOff", 1.0);
		break;

		case "GothicLeeTakeAnna_DelivShip":
		sld = characterFromId("AnnaDeLeiva");
			if (LAi_IsDead(sld))
			{
				AddQuestRecord("GothicLee_TakeAnna", "5");
 
				pchar.questTemp.GothicLee = "GothicLeeTakeAnna_BadResult";
				DeleteAttribute(sld, "RebirthPhantom");
				sld.LifeDay = 0;

			}
			else
			{
				AddQuestRecord("GothicLee_TakeAnna", "4");
			               AddPassenger(pchar, sld, false);
			               SetCharacterRemovable(sld, false);
			               pchar.questTemp.GothicLee = "GothicLeeTakeAnna_NiceResult";
		LAi_SetStayType(sld);
		LAi_CharacterDisableDialog(sld);
		ChangeCharacterAddressGroup(sld, "SantLous_townhall", "goto", "governor1");
			}
		break;


		//=================== Квест, решение проблем донны Анны  ===================

        case "GothicLee_InesDeLasCierras":
	                    PlaySound("interface\key.wav");//щелк!
		ChangeCharacterAddressGroup(characterFromID("InesDeLasCierras"), "none", "", "");
		DoQuestCheckDelay("GothicLee_InesDeLasCierras_1", 1.0);

        break;

        case "GothicLee_InesDeLasCierras_1":
	                    LocatorReloadEnterDisable("Havana_houseSp2", "reload3", false);
		sld = CharacterFromID("InesDeLasCierras");
		sld.dialog.currentnode = "Gothic_2_03";
		LAi_SetPlayerType(pchar);
		LAi_ActorDialog(sld, pchar, "", 2.0, 0);
		ChangeCharacterAddressGroup(sld, "CommonRoom_MH3", "barmen","stay");
        break;
		case "PlaySexx_1":
			ResetSound();
			iTemp = rand(13)+1;
			switch (iTemp)
			{
				case 1: fTemp = 18.2; break;
				case 2: fTemp = 5.1;  break;
				case 3: fTemp = 19.3; break;
				case 4: fTemp = 8.2;  break;
				case 5: fTemp = 11.3; break;
				case 6: fTemp = 18.2; break;
				case 7: fTemp = 18.2; break;
				case 8: fTemp = 9.3;  break;
				case 9: fTemp = 19.4; break;
				case 10:fTemp = 12.2; break;
				case 11:fTemp = 19.4; break;
				case 12:fTemp = 12.3; break;
				case 13:fTemp = 10.2; break;
				case 14:fTemp = 11.2; break;
			}			
                                         sGlobalTemp = iTemp;
		SetLaunchFrameFormParam("", "", 0, fTemp);
		SetLaunchFrameFormPic("loading\inside\censored2.tga");
                                         LaunchFrameForm();
		DoQuestCheckDelay("PlaySexx_2", 1.0);		
		break;
		case "PlaySexx_2":
                                         StartPostVideo("LoveScene", 1);
		DoQuestCheckDelay("PlaySexx_3", 5.0);		
		break;
		case "PlaySexx_3":
		PlayStereoSound("sex\sex" + sGlobalTemp + ".wav");
            AddTimeToCurrent(2, rand(30));
		if (pchar.location == "CommonRoom_MH3")
		{
	                      QuestSetCurrentNode("InesDeLasCierras", "Gothic_2_09");
                                           LAi_SetStayType(CharacterFromID("InesDeLasCierras"));
		}
		break;


        case "GothicLeeAnna_InShore":	
			chrDisableReloadToLocation = true;
			//==> братьев к маяку.          
			for (i=1; i<=2; i++)
            {
				if (i==1) sTemp = "officer_12";
				else sTemp = "officer_2";
				sld = GetCharacter(NPC_GenerateCharacter("DeLeivaBrother_"+i, sTemp, "man", "man", 35, SPAIN, -1, true, "soldier"));
				if (i==1)
				{
					sld.name = "Марио";
					sld.lastname = "Эстебан де Лейва";
					sld.money = 34780;
					FantomMakeCoolFighter(sld, 37, 95, 70, "newblade13", "pistol6", "bullet", 100);
				}
				else
				{
					sld.name = "Роберто";
					sld.lastname = "Винченцо де Лейва";
					sld.money = 41340;
					FantomMakeCoolFighter(sld, 34, 95, 70, "newblade15", "pistol4", "bullet", 100);
				}				
				sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_1.c";
				sld.SaveItemsForDead = true; // сохранять на трупе вещи
				sld.DontClearDead = true; // не убирать труп через 200с	
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_warrior_DialogEnable(sld, true);
				ChangeCharacterAddressGroup(sld, "Mayak10", "goto", "goto12");
				LAi_group_MoveCharacter(sld, "PeaceGroup");
			}	
			LAi_LocationFightDisable(&Locations[FindLocation("Mayak10")], true);	
        break;	

        case "AnnaHant_GoodWork":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "GothicLeeAnnaHant_GoodWork"; 
        break;
	
//==========================   Квест, поиски Библии  ========================

        case "GothicLee_SeekBible":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_SeekBible";
        break;

        case "SeekBible_SaveDeGraf":
            log_info("Нужно спасти фрегат де Графа!");
            Island_SetReloadEnableGlobal("Cuba1", false);//закрыть остров
            SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY); //ссорим ГГ и испанцев. 
            SetNationRelationBoth(SPAIN, HOLLAND, RELATION_ENEMY);
    		Group_FindOrCreateGroup("Spa_Attack");
			Group_SetType("Spa_Attack", "war");
            // ==> Испанские кэпы
            for (i=1; i<=5; i++)
            {
                switch (i)
                {
                    case 1:
                        ShipType = SHIP_SHNYAVA;
                        Model = "off_spa_1";
                        Rank = 28;
                        Blade = "blade_24";
                    break;
                    case 2:
                        ShipType = SHIP_XebekVML;
                        Model = "off_spa_2";
                        Rank = 26;
                        Blade = "blade_28";
                    break;
                    case 3:
                        ShipType = SHIP_CORVETTE;
                        Model = "off_spa_3";
                        Rank = 34;
                        Blade = "blade_28";
                    break;
                    case 4:
                        ShipType = SHIP_BRIG;
                        Model = "off_spa_4";
                        Rank = 30;
                        Blade = "blade_19";
                    break;
                    case 5:
                        ShipType = SHIP_POLACRE;
                        Model = "off_spa_5";
                        Rank = 36;
                        Blade = "blade_18";
                    break;
                }
                sld = GetCharacter(NPC_GenerateCharacter("CaptainAttack_"+i, Model, "man", "man", Rank, SPAIN, 0, true, "quest"));
                FantomMakeCoolSailor(sld, ShipType, "", CANNON_TYPE_CANNON_LBS12, 95, 90, 85);
                FantomMakeCoolFighter(sld, Rank, 96, 80, Blade, "pistol3", "bullet", 85);
			SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
    			Group_AddCharacter("Spa_Attack", "CaptainAttack_"+i);
            }
			Group_SetGroupCommander("Spa_Attack", "CaptainAttack_1");
            Group_SetPursuitGroup("Spa_Attack", PLAYER_GROUP);
			Group_SetAddress("Spa_Attack", "Cuba1", "", "");
            // ==> де Граф
            sld = GetCharacter(NPC_GenerateCharacter("LoranDeGraf", "mercen_14", "man", "man", 45, HOLLAND, -1, true, "quest"));
            sld.DeckDialogNode = "First time";
            sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_2.c";
        	sld.name 	= "Лоран";
        	sld.lastname = "де Граф";
			sld.greeting = "Gr_MiddPirate";
			sld.ShipEnemyDisable = true; //при попадании не враждебен
        	sld.Abordage.Enable = false; // НЕЛЬЗЯ!
            LAi_SetStayTypeNoGroup(sld);
            FantomMakeCoolSailor(sld, SHIP_ROSSIYA, "Коминте", CANNON_TYPE_CANNON_LBS32, 90, 80, 80);
            FantomMakeCoolFighter(sld, 45, 90, 70, "topor2", "pistol3", "bullet", 100);
            Group_AddCharacter("Quest_Group", "LoranDeGraf");
            Group_SetType("Quest_Group", "war");
            Group_SetGroupCommander("Quest_Group", "LoranDeGraf");
            Group_SetPursuitGroup("Quest_Group", PLAYER_GROUP);
            Group_SetAddress("Quest_Group", "Cuba1", "", "");
			// ==> стравливание
			Group_SetTaskAttack("Spa_Attack", "Quest_Group");
            Group_SetTaskAttack("Quest_Group", "Spa_Attack");
            Group_LockTask("Quest_Group");
			Group_LockTask("Spa_Attack");
            pchar.quest.SeekBible_WeWon.win_condition.l1 = "Group_Death";
			pchar.quest.SeekBible_WeWon.win_condition.l1.group = "Spa_Attack";
			pchar.quest.SeekBible_WeWon.win_condition = "SeekBible_WeWon";
    		pchar.quest.SeekBible_NotSavedDeGraf.win_condition.l1 = "NPC_Death";
			pchar.quest.SeekBible_NotSavedDeGraf.win_condition.l1.character = "LoranDeGraf";
			pchar.quest.SeekBible_NotSavedDeGraf.win_condition = "SeekBible_NotSavedDeGraf";
			pchar.quest.SeekBible_DieHard.win_condition.l1 = "MapEnter";
            pchar.quest.SeekBible_DieHard.win_condition = "SeekBible_DieHard";
        break;
        
        case "SeekBible_WeWon":
            DoQuestCheckDelay("sea_victory", 1.5);
            pchar.quest.SeekBible_NotSavedDeGraf.over = "yes";
            pchar.quest.SeekBible_DieHard.over = "yes";
            group_DeleteGroup("Spa_Attack");
            Island_SetReloadEnableGlobal("Cuba1", true);//на остров можно

            AddQuestRecord("GothicLee_3_SeekBible", "8");
            AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("ся","ась"));
            AddQuestUserData("GothicLee_3_SeekBible", "sSex1", GetSexPhrase("","а"));
            pchar.questTemp.GothicLee = "SeekBible_WeWon";

        break;

        case "SeekBible_DieHard":
            if (pchar.questTemp.GothicLee == "SeekBible_DeGrafIsDead")
            {
                group_DeleteGroup("Spa_Attack");
            }
            else
            {
                pchar.quest.SeekBible_WeWon.over = "yes";
                pchar.quest.SeekBible_NotSavedDeGraf.over = "yes";
                group_DeleteGroup("Spa_Attack");
                group_DeleteGroup("Quest_Group");
                Island_SetReloadEnableGlobal("Cuba1", true);//на остров можно

                AddQuestRecord("GothicLee_3_SeekBible", "6");
		AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("ся","ась"));
		AddQuestUserData("GothicLee_3_SeekBible", "sSex1", GetSexPhrase("","ла"));
                pchar.questTemp.GothicLee = "SeekBible_DeGrafDieHard";
            }
        break;
        case "SeekBible_NotSavedDeGraf":
            pchar.quest.SeekBible_WeWon.over = "yes";
            Island_SetReloadEnableGlobal("Cuba1", true);//на остров можно
            AddQuestRecord("GothicLee_3_SeekBible", "7");
            AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("ся","ась"));
           AddQuestUserData("GothicLee_3_SeekBible", "sSex1", GetSexPhrase("","а"));
            pchar.questTemp.GothicLee = "SeekBible_DeGrafIsDead";
        break;

        case "SeekBible_DeGrafToTavern":
            sld = characterFromId("LoranDeGraf");
            FreeSitLocator("Tortuga_tavern", "sit3");
            ChangeCharacterAddressGroup(sld, "Tortuga_tavern", "sit", "sit3");			
            LAi_SetSitTypeNoGroup(sld);
            group_DeleteGroup("Quest_Group");
        break;


                   case "SeekBible_FortFrance_Graveyard":
	pchar.quest.SeekBible_WeWon.win_condition.l1 = "locator";
	pchar.quest.SeekBible_WeWon.win_condition.l1.location = "FortFrance_church IM";
	pchar.quest.SeekBible_WeWon.win_condition.l1.locator_group = "reload";
	pchar.quest.SeekBible_WeWon.win_condition.l1.locator = "reload3";
	pchar.quest.SeekBible_WeWon.function = "SeekBible_FortFrance_Graveyard_1";
                   break;

	case "SeekBible_skeletcap":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN01.wav");
	sld = characterFromId("SeekBible_skel");
                   LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "SeekBible_skeletcap_1", 3.5);
	break;

	case "SeekBible_skeletcap_1":
	DoQuestFunctionDelay("SeekBible_LandSkelAttack", 0.1);
	break;

	case "SeekBible_LandSkelDie": // прибили скелет Самуэля
	LAi_group_Delete("EnemyFight");
	SetMusicAlarm("");
	chrDisableReloadToLocation = false;
	PlaySound("People Fight\Peace_man_death_07.wav");
	pchar.questTemp.GothicLee = "";
	AddComplexSelfExpToScill(100, 100, 100, 100);
	break;


//=================== Квест, спасение Горна ===================

        case "GothicLee_Gorn":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_5_1";
        break;

		case "RockBras_DelivShip":
			sld = characterFromId("Gorn");
			if (LAi_IsDead(sld))
			{
				AddQuestRecord("GothicLee_5_RockBras", "4");
				AddQuestUserData("GothicLee_5_RockBras", "sSex", GetSexPhrase("","а"));
				AddQuestUserData("GothicLee_5_RockBras", "sSex1", GetSexPhrase("","ла"));
				pchar.questTemp.GothicLee = "RockBras_RockIsDead";
				DeleteAttribute(sld, "RebirthPhantom");
				sld.LifeDay = 0;
			}
			else
			{
				AddQuestRecord("GothicLee_5_RockBras", "3");
				AddPassenger(pchar, sld, false);
				SetCharacterRemovable(sld, false);
				pchar.questTemp.GothicLee = "RockBras_RockIsSaved";
				LAi_SetStayTypeNoGroup(sld);
				LAi_CharacterDisableDialog(sld);
		ChangeCharacterAddressGroup(sld, "SantLous_townhall", "goto", "governor1");
			}
		break;

		case "Gorn_tavern":
            sld = GetCharacter(NPC_GenerateCharacter("Gorn", "Gorn", "man", "man", 30, PIRATE, -1, false, "quest"));
			FantomMakeCoolFighter(sld, 30, 90, 90, "", "", "", 80);
                                                sld.Dialog.Filename    = "Gothic_Quest\Gothic_npc\Gorn.c";
	                                sld.dialog.currentnode = "First time";
        	                                sld.name 	= "Горн";
        	                                sld.lastname 	= "";
	                                sld.nation = PIRATE;
			LAi_LoginInCaptureTown(sld, true);
			LAi_NoRebirthEnable(sld);
			LAi_SetLoginTime(sld, 0.0, 24.0);
			LAi_SetSitType(sld);			
			ChangeCharacterAddressGroup(sld, "SantLous_Tavern", "sit", "sit3");
		break;
//=================== Квест. Встреча с тремя корсарами ===================
        case "Gothic_Lee":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_6_1";
        break;
//=================== Квест. Во славу Франции ===================
        case "Gothic_Lee_SOLEYRU":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_7_1";
        break;

		case "GuardPP_Late":
			pchar.quest.GuardPP_Fight.over = "yes";
			pchar.questTemp.GothicLee = "GuardPP_Late";
			AddQuestRecord("GothicLee_7_GuardPortPax", "5");
			AddQuestUserData("GothicLee_7_GuardPortPax", "sSex", GetSexPhrase("","а"));
            SetCaptureTownByNation("PortPax", SPAIN);
            UpdateRelations();
            RefreshBattleInterface();
		break;

		case "GuardPP_Fight":
            Log_QuestInfo("Испанская эскадра установлена. Это будет великая битва...");
			pchar.quest.GuardPP_Late.over = "yes";
            Island_SetReloadEnableGlobal("Hispaniola2", false);
    		group_DeleteGroup("Spa_Attack");
    		Group_FindOrCreateGroup("Spa_Attack");
			Group_SetType("Spa_Attack", "war");
            // ==> Испанские кэпы
            for (i=1; i<=6; i++)
            {
                switch (i)
                {
					case 1:
                        ShipType = SHIP_LSHIP_QUEST;
                        Rank = 40;
                        Blade = "topor_04";
						iTemp = CANNON_TYPE_CANNON_LBS42;
                    break;
                    case 2:
                        ShipType = SHIP_HEAVYGALEON;
                        Rank = 30;
                        Blade = "blade_26";
						iTemp = CANNON_TYPE_CANNON_LBS36;
                    break;
                    case 3:
                        ShipType = SHIP_FRIGATE_H;
                        Rank = 38;
                        Blade = "blade_31";
						iTemp = CANNON_TYPE_CULVERINE_LBS36;
                    break;
                    case 4:
                        ShipType = SHIP_FRIGATE;
                        Rank = 35;
                        Blade = "blade_29";
						iTemp = CANNON_TYPE_CULVERINE_LBS36;
                    break;
                    case 5:
                        ShipType = SHIP_HEAVYGALEON;
                        Rank = 31;
                        Blade = "blade_28";
						iTemp = CANNON_TYPE_CANNON_LBS36;
                    break;
                    case 6:
                        ShipType = SHIP_SURPRISE;
                        Rank = 36;
                        Blade = "blade_30";
						iTemp = CANNON_TYPE_CULVERINE_LBS36;
                    break;
                }
                sld = GetCharacter(NPC_GenerateCharacter("CaptainAttack_"+i, "off_spa_"+(rand(1)+1), "man", "man", Rank, SPAIN, 0, true, "quest"));
				if (i==2 || i==5 || i==7) 
				{
					FantomMakeCoolSailor(sld, ShipType, "", iTemp, 80, 90, 70);
					FantomMakeCoolFighter(sld, Rank, 90, 90, Blade, "pistol3", "bullet", 100);
				SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
				}
				else
				{
					FantomMakeCoolSailor(sld, ShipType, "", iTemp, 100, 100, 90);
					FantomMakeCoolFighter(sld, Rank, 100, 90, Blade, "pistol5", "bullet", 200);
			SetShipSailsFromFile(sld, "ships/parus_sail_whole_white_spain.tga");
				}
    			Group_AddCharacter("Spa_Attack", "CaptainAttack_"+i);
            }
            // ==> стравливание
			Group_SetGroupCommander("Spa_Attack", "CaptainAttack_1");
			Group_SetTaskAttack("Spa_Attack", PLAYER_GROUP);
            Group_SetPursuitGroup("Spa_Attack", PLAYER_GROUP);
			Group_SetAddress("Spa_Attack", "Hispaniola2", "", "");
			Group_LockTask("Spa_Attack");
            pchar.quest.GuardPP_WiWon.win_condition.l1 = "Group_Death";
			pchar.quest.GuardPP_WiWon.win_condition.l1.group = "Spa_Attack";
			pchar.quest.GuardPP_WiWon.win_condition = "GuardPP_WiWon";
			pchar.quest.GuardPP_DieHard.win_condition.l1 = "MapEnter";
            pchar.quest.GuardPP_DieHard.win_condition = "GuardPP_DieHard";
        break;

        case "GuardPP_WiWon":
                                                              DoQuestCheckDelay("sea_victory", 1.5);
			Log_QuestInfo("Испанская эскадра разбита.");
			group_DeleteGroup("Spa_Attack");
			Island_SetReloadEnableGlobal("Hispaniola2", true);
			pchar.quest.GuardPP_DieHard.over = "yes";
			if (LAi_IsDead(characterFromId("SoleiRoyalCaptain")))
			{
				AddQuestRecord("GothicLee_7_GuardPortPax", "3");
				pchar.questTemp.GothicLee = "GuardPP_SoleiRoyalSunk";

			}
			else
			{
				pchar.questTemp.GothicLee = "GuardPP_GoodWork";
				AddQuestRecord("GothicLee_7_GuardPortPax", "2");
			}
        break;

        case "GuardPP_DieHard":
            Log_QuestInfo("Свалил с поля боя, линейке конец.");
            pchar.questTemp.GothicLee = "GuardPP_DieHard";
            AddQuestRecord("GothicLee_7_GuardPortPax", "4");
            group_DeleteGroup("Spa_Attack");
            Island_SetReloadEnableGlobal("Hispaniola2", true);
            pchar.quest.GuardPP_WiWon.over = "yes";
			sld = characterFromId("SoleiRoyalCaptain");
			RemoveCharacterCompanion(pchar, sld);
			sld.LifeDay = 0;
            SetCaptureTownByNation("PortPax", SPAIN);
            UpdateRelations();
            RefreshBattleInterface();
        break;

        //********************** Квест. Захват Санто-Доминго ************************
        case "Gothic_Lee_OccupySantoDomingo":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_10_0";
        break;

//********************** Квест N12, конец войны  **********************

        case "Gothic_Lee_EndOfWar":
			sld = CharacterFromID("Lee");
			sld.dialog.currentnode = "Gothic_12_1";
        break;

        case "EndOfWar_TakeOutShip":
			group_DeleteGroup("SoleiRoyal");
        break;
//==================================================================

//==================================================================
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Мистер и Миссис Смит" ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "Gothic_Ann_5":
	LocatorReloadEnterDisable("Guadeloupe_Mines", "reload1_back", false);// открыть
                  pchar.questTemp.GothicSmithy = "HaryHooms";
	break;

	case "Gothic_Smithy_End":
	sld=characterFromID("SmithyDavid");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
	break;

	case "Gothic_Smithy_Start":
	pchar.questTemp.GothicSmithy = "Smithy_DouwesenTavern";               
	break;

	case "Gothic_SmithyAugustaDeath":
	PauseAllSounds();
	Lai_SetStayType(pchar);
	pchar.questTemp.Gothic_Smithy_Augusta.Death = "true";
	DoQuestCheckDelay("TalkSelf_Quest", 1.0);
	break;

	case "Gothic_Smithy_Augusta_End":
                   LocatorReloadEnterDisable(pchar.location, "reload1_back",  false);
          	LAi_SetPlayerType(Pchar);
	DoQuestCheckDelay("Gothic_Smithy_AugustaDeath", 2.0);
	break;

	case "Gothic_Smithy_AugustaDeath":
	LocatorReloadEnterDisable("Douwesen_tavern", "reload2", true);
	pchar.questTemp.GothicSmithy = "SmithyTavern2";
    	AddQuestRecord("Gothic_Smithy", "6");
	break;

	case "OpenTheDoors_SmithyPiratDeath":
    	AddQuestRecord("Gothic_Smithy", "8");
                   bDisableFastReload = false;//открыть переход
                   LocatorReloadEnterDisable("FortOrange_port", "reload1_back", false);
                   LocatorReloadEnterDisable("FortOrange_port", "reload2_back", false);
                   LocatorReloadEnterDisable("FortOrange_town", "reload2", false);//закрыть выход в джунгли
                  DoQuestCheckDelay("Gothic_Smithy_Tavern_SantLous", 10.0);
	break;

	case "Gothic_Smithy_Tavern_SantLous":
                   sld = GetCharacter(NPC_GenerateCharacter("SmithyDavid", "huber_13", "man", "man", 30, PIRATE, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 80, 90, 90, "", "", "", 10);
	 sld.name 	= "Дэвид";
                    sld.lastname = "Смит";
	sld.greeting = "Gr_DAVID";
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_David.c";
	sld.Dialog.CurrentNode = "SmithyDavid_SantLous";
	LAi_LoginInCaptureTown(sld, true);
	LAi_NoRebirthEnable(sld);
	LAi_SetLoginTime(sld, 0.0, 24.0);
	LAi_SetSitType(sld);			
	ChangeCharacterAddressGroup(sld, "SantLous_Tavern", "sit", "sit8");
	break;

	case "OpenTheDoors_SmithyPiratBankDeath":
                   LocatorReloadEnterDisable("LeFransua_bank", "reload2", false);
	Log_Info("Необходимо всё тщательно обыскать.");
	break;


		case "GothicSmithy_GhostshipBoardingDeck": // расстановка абордажных групп
	                                    LAi_LocationFightDisable(&Locations[FindLocation("Deck_Galeon_Ship")], false);//разрешить драться
			PlaySound("interface\_GTBoard2.wav");
			PlaySound("interface\abordage_wining.wav");
			DoQuestFunctionDelay("Terrapin_SetMusic", 1.2);
			LAi_group_Delete("EnemyFight");
			bDisableCharacterMenu = true;//лочим F2
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
			// делаем расчет сил
			int pCrew = sti(pchar.Ship.Crew.Quantity); 
			int eRank = 20+MOD_SKILL_ENEMY_RATE;
			int pRank = makeint(pCrew*30/666);
			if (pRank < 1) pRank = 1;
			int pScl = makeint(pCrew*70/666)+(20-MOD_SKILL_ENEMY_RATE*2);
			if (pScl < 10) pScl = 10;
			n = 20;
			if (pCrew < 20) n = pCrew;
			// наши 
			for (i=1; i<=n; i++)
			{
				sld = GetCharacter(NPC_GenerateCharacter("GothicSmithy_pcrew_"+i, "citiz_"+(rand(9)+31), "man", "man", pRank, FRANCE, 2, true, "soldier"));
				FantomMakeCoolFighter(sld, pRank, 20, 20, RandPhraseSimple("blade_10","blade_11"), "pistol1", "bullet", 120);
				SetSelfSkill(sld, pScl, pScl, pScl, pScl, pScl);
				LAi_SetWarriorType(sld);
				if (i < 8) ChangeCharacterAddressGroup(sld, "Deck_Galeon_Ship", "quest", "quest1");
				else ChangeCharacterAddressGroup(sld, "Deck_Galeon_Ship", "quest", "quest2");
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}

			// враги
			for (i=1; i<=20; i++)
			{
				sld = GetCharacter(NPC_GenerateCharacter("GothicSmithy_ecrew_"+i, "citiz_"+(rand(9)+51), "man", "man", eRank, PIRATE, -1, true, "soldier"));
				FantomMakeCoolFighter(sld, eRank, 20, 20, RandPhraseSimple("blade_10","blade_11"), "pistol1", "bullet", 120);
				SetSelfSkill(sld, 70, 70, 70, 70, 70);
				LAi_SetWarriorType(sld);
				if (i < 8) ChangeCharacterAddressGroup(sld, "Deck_Galeon_Ship", "quest", "quest3");
				else ChangeCharacterAddressGroup(sld, "Deck_Galeon_Ship", "quest", "quest4");
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GothicSmithy_GhostshipSkelDie");

	//запускаем офицеров
	for(i=1; i<=3; i++)
	{
	int idx = GetOfficersIndex(pchar, i);
	if(idx < 0) continue;
	sld = &Characters[idx];
	ChangeCharacterAddressGroup(sld, "Deck_Galeon_Ship", "reload", "reload2");

	}
		break;

	                   case "GothicSmithy_GhostshipSkelDie": // перебили бандитов на палубе
	                   DoQuestCheckDelay("GothicSmithy_GhostshipCabinReload", 5.0);
	                   LAi_SetFightMode(pchar, false);
	                   AddComplexSelfExpToScill(100, 100, 100, 100);
		break;
		 
		case "GothicSmithy_GhostshipCabinReload": // в каюту
		SetLaunchFrameFormParam("", "", 0, 4);
		SetLaunchFrameFormPic("loading\Capdeck_1.tga");
		LaunchFrameForm();
		DoQuestCheckDelay("GothicSmithy_GhostshipCabinReloadGo", 4.0);
		break;
		
		case "GothicSmithy_GhostshipCabinReloadGo": // в каюту
		DoQuestReloadToLocation("Cabin", "rld", "loc0", "GothicSmithy_GhostshipBoardingCabin");
		break;
		
		case "GothicSmithy_GhostshipBoardingCabin": // в каюте
	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_THERESAFIGHT.wav");
		sld = characterFromId("KarSec");
		ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc0");
		LAi_group_Delete("EnemyFight");
		sld = characterFromId("KarSecc");
		ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc1");
		LAi_group_Delete("EnemyFight");
		sld = characterFromId("Carrol");
		ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc2");
		LAi_group_MoveCharacter(sld, "EnemyFight");
		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		AddDialogExitQuest("MainHeroFightModeOn");

	                   LAi_SetCheckMinHP(pchar, 10, true, "GothicSmithy_GhostshipCapitan");
		LAi_SetFightMode(pchar, true);

	                   LAi_SetCheckMinHP(sld, 20, true, "GothicSmithy_GhostshipCapitan");
		LAi_SetFightMode(sld, true);

		break;
		 
		case "GothicSmithy_GhostshipCapitan": // разговор
		LAi_SetFightMode(pchar, true);
		sld = characterFromId("Carrol");
	                   sld.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_Carrol.c";
	                   sld.Dialog.CurrentNode = "MartiniqueAbord";
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
	                   sld=characterFromID("KarSec");
		LAi_SetActorType(sld);
            	                   LAi_ActorTurnToCharacter(sld, pchar);
	                   sld=characterFromID("KarSecc");
		LAi_SetActorType(sld);
            	                   LAi_ActorTurnToCharacter(sld, pchar);
		break;

	                   case "GothicSmithy_Ghostship_Gun":
		LAi_SetFightMode(pchar, true);
	                   sld=characterFromID("Carrol");
		LAi_SetActorType(sld);
                                      LAi_SetGroundSitTypeNoGroup(pchar);
	                   sld.Dialog.FileName = "Gothic_Quest\GothicLine\Smithy_Carrol.c";
	                   sld.Dialog.CurrentNode = "MartiniqueAbord_Gun";
		LAi_ActorDialog(sld, pchar, "", 2.0, -1);
	                    break;

		case "GothicSmithy_GhostshipGetOut": // вырубили ГГ
	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_ITOOKYOURGOLD.wav");
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\DEAD.wav");
	                   sld=characterFromID("Carrol");
		LAi_SetActorType(sld);
	                   LAi_CharacterDisableDialog(sld);
		DoQuestCheckDelay("GothicSmithy_GhostshipGetOut_1", 2.0);
		break;
		 
		case "GothicSmithy_GhostshipGetOut_1": // вырубили ГГ
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\DEAD.wav");
		SetLaunchFrameFormParam("Вы потеряли сознание от полученных ран...", "", 0, 5);
		LaunchFrameForm();
		WaitDate("", 0, 0, 1, 5, 10); //крутим время
		RecalculateJumpTable();
		DoQuestCheckDelay("GothicSmithy_ReloadCoast", 5.0);
		locations[FindLocation("Shore38")].DisableEncounters = true; //энкаутеры закрыть
		break;
		
		case "GothicSmithy_ReloadCoast": // на берег
		// вычищаем все шторма и прочее
		Group_DeleteGroup("Umberto_Group");
		Group_DeleteGroup("Terri_Group");
		for (i=0; i<MAX_ISLANDS;i++)
		{				
		if (Islands[i].id == "Martinique")
		{
		DeleteAttribute(&Islands[i], "alwaysStorm");
		DeleteAttribute(&Islands[i], "storm");
		DeleteAttribute(&Islands[i], "QuestlockWeather");
		}
		}
		for (i=0; i<MAX_LOCATIONS;i++)
		{				
		if (Locations[i].id == "Deck_Galeon_Ship")
		{
		DeleteAttribute(&locations[i], "alwaysStorm");
		DeleteAttribute(&locations[i], "storm");
		DeleteAttribute(&locations[i], "QuestlockWeather");
		}
		}
		sld = characterFromId("Carrol");
		sld.lifeday = 0; // убираем ненужного НПС
		sld = characterFromId("KarSec");
		sld.lifeday = 0; // убираем ненужного НПС
		sld = characterFromId("KarSecc");
		sld.lifeday = 0; // убираем ненужного НПС
		sld = characterFromId("SmithyDavid");
		sld.lifeday = 0; // убираем ненужного НПС

		LAi_LocationFightDisable(&Locations[FindLocation("Deck_Galeon_Ship")], true);//запретить драться
		LAi_SetImmortal(pchar, false);
		Island_SetReloadEnableGlobal("Martinique", true);//на остров можно			
		bQuestDisableMapEnter = false;
		bDisableCharacterMenu = false;//разлочим F2
		InterfaceStates.Buttons.Save.enable = true;//разрешим сохраняться
		setCharacterShipLocation(pchar, "Shore38"));
		setWDMPointXZ("Shore38"); // корабль в бухту 
		DoQuestReloadToLocation("Shore89", "goto", "goto1", "");
                                      LAi_SetGroundSitTypeNoGroup(pchar);

                                      int iCrew = makeint(sti(pchar.Ship.Crew.Quantity)*0.67); 
                                      SetCrewQuantityOverMax(pchar, iCrew); // сносим треть команды
                                      sld.ship.HP = makeint(sti(pchar.ship.HP)*0.9); // портим корпус

		chrDisableReloadToLocation = true;//закрыть локацию
                                      DoQuestFunctionDelay("Gothic_SmithySeaShore_sailor", 7.0);
		break;

	                 case "Gothic_Smithy_sailor":
	                LocatorReloadEnterDisable("Shore38", "boat", true);
                                    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_HEALLASTSHRINE.wav");
                                    LAi_SetPlayerType(pchar);
	                 sld = characterFromId("Sailor_coast");
          	                 sld.name      = "матрос Билл";
          	                 sld.lastname      = "";
                                    sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\OtherNPC.c";
                                    sld.Dialog.CurrentNode = "Sailor_coast";
	                 LAi_SetActorType(sld);
                                    LAi_ActorDialog(sld, pchar, "", -1, 0);
	                 break;

	case "Gothic_SmithyPuertoRico_3":
                   LocatorReloadEnterDisable("VillaAlegria_town2", "reload31", false);
	sld = characterFromId("Senyan");
                   sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Senyan.c";
                   sld.Dialog.CurrentNode = "Senyan_PuertoRico_2";
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "Gothic_Milten_01":
	sld = characterFromId("Milten");
                   LAi_SetActorType(sld);
                   DoQuestFunctionDelay("Gothic_Milten_1", 0.1);
	break;

	case "Gothic_Milten_02":
	sld = characterFromId("Milten");
                   LAi_SetActorType(sld);
                   DoQuestFunctionDelay("Gothic_Milten_2", 0.1);
	break;


///////////////////////////////////////////////////////////////////////////////////////////////////////////	
///------------------------------------- "Завершающий этап Месть корсара." ----------------------------------------
///////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "OpenTheDoors_RevengeCorsairDeath":
                  chrDisableReloadToLocation = false;//открыть локацию
	Log_Info("Необходимо всё тщательно обыскать.");	
	break;

        case "time_over_Cumana_attack":
            // 50 дней на взятие Куманы, включая и походы за двумя пиратами, если геймер решит, что это ему нужно
            if (IsEntity(worldMap))
            {
                if (!bQuestCheckProcessFreeze) // можно показать
				{
	        		pchar.quest.time_over_Cumana_attack_Map_01.over = "yes"; // сброс, если уже откладывали
	        		pchar.quest.time_over_Cumana_attack_Map_02.over = "yes";
                   
                    makearef(arOldMapPos, worldMap.old);
                    WdmPrepareMapForAbordage(arOldMapPos);
                    MakeCloneShipDeck(pchar, true); // подмена палубы
                    DoReloadFromWorldMapToLocation("Ship_deck", "goto", "goto5");
	                ReloadFromWMtoL_complete();
	                
                    sld = characterFromID("Henry Morgan");
                    ChangeCharacterAddressGroup(sld, "Ship_deck", "goto", "goto6");
                    LAi_SetWarriorType(sld);
	                LAi_warrior_DialogEnable(sld, true);
	                sld.dialog.currentnode = "time_over_Cumana";
   	                // ==> антураж
                    for (i=1; i<5; i++)
        			{
                        attrName = "pirate_" + i;
                        sld = GetCharacter(NPC_GenerateCharacter(attrName, attrName, "man", "man", 15, PIRATE, 1, true, "quest"));
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
      				Pchar.quest.time_over_Cumana_attack_Map_01.win_condition.l1 = "MapEnter";
                    Pchar.quest.time_over_Cumana_attack_Map_01.win_condition = "time_over_Cumana_attack";
		        }
			}
			else
			{   // подождем выхода на карту, раз время прошло, но мы не на ней
			    Pchar.quest.time_over_Cumana_attack_Map_02.win_condition.l1 = "MapEnter";
                Pchar.quest.time_over_Cumana_attack_Map_02.win_condition = "time_over_Cumana_attack";
			}
        break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  Одержимые   
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "GothicObsession_afraid":
                 PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_3.wav");	
	break;


	case "GothicApostates_of_the_faith":
		
		pchar.quest.GothicApostates.win_condition.l1 = "location";
		pchar.quest.GothicApostates.win_condition.l1.location = "PuertoPrincipe_port";
		pchar.quest.GothicApostates.win_condition = "GothicApostates_PuertoPrincipe";
    break;
	
	
	case "GothicApostates_PuertoPrincipe":
                     chrDisableReloadToLocation = true;		    
	chr = GetCharacter(NPC_GenerateCharacter("GothicApostatesBerglar", "Apostates_1", "man", "man2", 22, SPAIN, -1, false, "quest"));
	FantomMakeCoolFighter(chr, 37, 95, 70, "blade_25", "pistol3", "bullet", 30);
	chr.name = "Фредерик";
	chr.lastname = "Бамер";
	chr.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	chr.dialog.currentnode = "Frederic";
	chr.greeting = "maybe_buisness";
	Lai_RemoveLoginTime(chr);
	LAi_SetImmortal(chr, true);
	ChangeCharacterAddressGroup(chr, "PuertoPrincipe_port", "goto", "goto7");
	LAi_SetWarriorTypeNoGroup(chr);
                     LAi_group_MoveCharacter(chr, "EnemyFight1");

	chr = GetCharacter(NPC_GenerateCharacter("GothicApostatesMonah", "monk_3", "man", "man2", 22, SPAIN, -1, false, "quest"));
	FantomMakeCoolFighter(chr, 34, 95, 70, "blade_30", "pistol1", "bullet", 20);
	chr.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	chr.dialog.currentnode = "Monah";
	Lai_RemoveLoginTime(chr);
	LAi_SetImmortal(chr, true);
	ChangeCharacterAddressGroup(chr, "PuertoPrincipe_port", "goto", "goto10");
	LAi_SetWarriorTypeNoGroup(chr);
                     LAi_group_MoveCharacter(chr, "EnemyFight2");
			
	LAi_group_FightGroups("EnemyFight1", "EnemyFight2", true);
	DoQuestCheckDelay("GothicApostates_PuertoPrincipe_selfdialog_1", 0.5);
                     break;
	
	case "GothicApostates_PuertoPrincipe_selfdialog_1":
	StartQuestMovie(false, false, true);
	LAi_SetActorType(pchar);			
	pchar.dialog.currentnode = "GothicApostates_start";
	LAi_ActorSelfDialog(pchar, "");
                     break;
	
//----------------------------Не берем квест----------------------------
 
                     case "GothicApostates_PuertoPrincipe_NoHelp":
	chrDisableReloadToLocation = true;//закрыть локацию
                     chr = CharacterFromID("GothicApostatesMonah")
	LAi_SetPlayerType(pchar);
	LAi_SetImmortal(chr, false);
                     LAi_KillCharacter(chr);
	chr.LifeDay = 0;				
	DeleteAttribute(pchar,"GothicApostates_PuertoPrincipe");  
	DoQuestCheckDelay("GothicApostates_PuertoPrincipe_End", 3.0);         
                     break;
	
                    case "GothicApostates_PuertoPrincipe_End":
                    PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
	sld = characterFromId("GothicApostatesBerglar");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload2_back", "none", "", "", "OpenTheDoors", -1);	
                    EndQuestMovie();
                    LAi_SetPlayerType(pchar);			
                    break;
	
//----------------------------Выбрали жида----------------------------

	case "GothicApostates_PuertoPrincipe_HelpMan":
	ChangeCharacterComplexReputation(pchar, "nobility", -10);
	chr = CharacterFromID("GothicApostatesMonah");
	LAi_SetImmortal(chr, false);			
	LAi_SetActorType(pchar);
	LAi_ActorFollow(pchar, CharacterFromID("GothicApostatesBerglar"), "GothicApostates_PuertoPrincipe_KillMonk", -1);
	break;
	
	case "GothicApostates_PuertoPrincipe_KillMonk":
	LAi_ActorAttack(pchar, CharacterFromID("GothicApostatesMonah"), "");			DoQuestCheckDelay("GothicApostates_PuertoPrincipe_MonkDead", 3.0);
	break;
	
	case "GothicApostates_PuertoPrincipe_MonkDead":
	chrDisableReloadToLocation = true;//закрыть локацию
	chr = CharacterFromID("GothicApostatesMonah");
	LAi_KillCharacter(chr);
	LAi_LockFightMode(pchar, true);
	LAi_SetPlayerType(pchar);
			
	locCameraTarget(pchar);
	locCameraFollow();
	EndQuestMovie();									
	chr = CharacterFromID("GothicApostatesBerglar");
	LAi_SetActorType(chr);
	chr.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	chr.dialog.currentnode = "Frederic";
	Lai_ActorDialogNow(chr, Pchar, "",-1);
	break;
	
	case "GothicApostates_APS":
	sld = characterFromId("GothicApostatesBerglar");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload2_back", "none", "", "", "OpenTheDoors", -1);
			
	SetQuestHeader("APS");
	AddQuestRecord("APS", "1");
	pchar.questTemp.APS = "APS_Tavern";			
	break;
	
	case "GothicApostates_APS_PuertoPrincipeTavern":
	
	chrDisableReloadToLocation = true;
	iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+2;
	iScl = 30 + 2*sti(pchar.rank);
	
	for (i=0; i<=3; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("GothicApostatesMonah_"+i, "monk_"+i, "man", "man2", 20, Spain, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, RandPhraseSimple("blade_10","blade_11"), "pistol1", "bullet", iScl*2);
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Monk_PuertoPrincipe_tavern";
	sld.greeting = "monk";
	LAi_RemoveLoginTime(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1_back");
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "Monks");
	LAi_SetImmortal(sld, true);
	}
	LAi_ActorDialog(sld, pchar, "", 3.0, 0.5);
	for (i=0; i<=3; i++)
	{	
	LAi_ActorFollow(CharacterFromID("GothicApostatesMonah_"+i), sld, "", -1);
	}
                     StartQuestMovie(false, false, true);			
					
	break;
	
	// Тут смерть по любому
	case "GothicApostates_ENDGAME":
	LAi_LocationFightDisable(&locations[FindLocation(pchar.location)], false);
	EndQuestMovie();

	for (i=0; i<=3; i++)
	{			
	LAi_SetWarriorTypeNoGroup(CharacterFromID("GothicApostatesMonah_"+i));
	LAi_group_FightGroups("Monks", LAI_GROUP_PLAYER, false);
	}
	break;
	
	// Cледуем за отцами
	case "GothicApostates_APS_Santiago":
	EndQuestMovie();
	for (i=0; i<=3; i++)
	{
	sld = characterFromId("GothicApostatesMonah_"+i);
	LAi_SetActorType(sld);			
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 0.1);
	}
	SetLaunchFrameFormParam("Прошло несколько дней"+ NewStr() +"", "", 0, 5);
	LaunchFrameForm();
	WaitDate("", 0, 0, 4, 0, 0); //крутим время
	RecalculateJumpTable();

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk3", "priest_sp1", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetActorType(sld);
	LAi_SetActorType(Pchar);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "goto", "goto11");
	DoQuestFunctionDelay("GothicApostates_Incquisitio", 0.1);//отбираем шмотки
	DoQuestCheckDelay("GothicApostates_APS_in_Santiago_continue", 2.0);

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk4", "Priest_1", "man", "man", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "sit5");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk5", "priest_sp2", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "bench1");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk6", "priest_sp3", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "bench2");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk7", "priest_sp2", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "bench3");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk8", "priest_sp3", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "bench4");

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_spSold1", "sold_spa_10", "man", "man", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "soldiers", "soldier1");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_spSold2", "sold_spa_11", "man", "man", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "soldiers", "soldier3");
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_spSold3", "sold_spa_12", "man", "man", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "soldiers", "soldier2");
	break;
	
	case "GothicApostates_APS_in_Santiago_continue":
	DoReloadCharacterToLocation("Santiago_Incquisitio2", "quest", "quest2");
	sld = CharacterFromID("Apostates_Monk3");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Monk_in_Santiago";
	sld.greeting = "monk";
	LAi_RemoveLoginTime(sld);
	LAi_SetActorType(sld);		
	LAi_ActorGoToLocator(sld, "goto", "goto12", "GothicApostates_APS_in_Santiago_continue2", -1);
	break;

	case "GothicApostates_APS_in_Santiago_continue2":
	sld = CharacterFromID("Apostates_Monk3");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Monk_in_Santiago";
                     LAi_SetActorType(sld);
	LAi_SetPlayerType(pchar);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_in_Santiago_continue3":
	sld = CharacterFromID("Apostates_Monk3");
	LAi_SetActorType(sld);
	LAi_SetActorType(Pchar);
	LAi_ActorTurnToLocator(Pchar, "quest", "barrel1");
                     LAi_ActorGoToLocator(sld, "goto", "goto29", "GothicApostates_APS_Santiago_prison_capture", -1);
	AddQuestRecord("APS", "2");
	break;
	
	case "GothicApostates_APS_Santiago_prison_capture":
	sld = CharacterFromID("Apostates_Monk3");
                     LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "sit", "armchait2");
	LAi_SetActorType(Pchar);
	LAi_ActorTurnToLocator(Pchar, "quest", "barrel1");

	SetLaunchFrameFormParam("Прошло несколько дней"+ NewStr() +"", "", 0, 5);
	LaunchFrameForm();
	WaitDate("", 0, 0, 3, 0, 0); //крутим время
	RecalculateJumpTable();
	DoQuestCheckDelay("GothicApostates_APS_BurnspSold", 3.5);
	break;

	case "GothicApostates_APS_BurnspSold":
	sld = CharacterFromID("Apostates_spSold3");
	LAi_SetActorType(sld);
                     LAi_ActorGoToLocator(sld, "goto", "goto29", "GothicApostates_APS_spSold3", -1);
	break;

	case "GothicApostates_APS_spSold3":
	LAi_SetActorType(Pchar);
	LAi_ActorTurnToLocator(Pchar, "goto", "goto29");

	pchar.name_old = pchar.name;
	pchar.lastname_old = pchar.lastname;
	pchar.name = "Священик и";
	pchar.lastname = "охраник";
	pchar.dialog.currentnode = "GothicApostates_spSolddialog";
	LAi_ActorSelfDialog(pchar, "GothicApostates_APS_spSold3_1");
	break;

	case "GothicApostates_APS_spSold3_1":
	LAi_SetActorType(pchar);
	LAi_SetActorType(CharacterFromID("Apostates_spSold3"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("Apostates_spSold3"));
	break;

	case "GothicApostates_APS_Burn":
	pchar.name = pchar.name_old;
	pchar.lastname = pchar.lastname_old;			
	DeleteAttribute(pchar, "name_old");
	DeleteAttribute(pchar, "lastname_old");

	sld = CharacterFromID("Apostates_spSold3");
	LAi_SetActorType(sld);
                     LAi_ActorRunToLocator(sld, "quest", "quest1", "", -1);

	for (i=1; i<=1; i++)
	{
	CreateLocationParticles("smoke", "quest", "barrel1", 0, 0, 0, "");
	}
	DoQuestCheckDelay("GothicApostates_APS_Burn1", 8.5);
	break;

	case "GothicApostates_APS_Burn1":
	for (i=1; i<=1; i++)
	{
	CreateLocationParticles("large_smoke", "quest", "barrel1", 0, 0, 0, "");
	CreateLocationParticles("ShipExplode", "quest", "barrel1", 1.0, 0, 0, "boom");
	CreateLocationParticles("blast_inv", "quest", "barrel1", 1.0, 0, 0, "");
	CreateLocationParticles("blast_dirt", "quest", "barrel1", 1.0, 0, 0, "");
	}
	CreateLocationParticles("large_smoke", "quest", "quest3", 0, 0, 0, "");
	CreateLocationParticles("ShipExplode", "quest", "quest3", 1.0, 0, 0, "boom");
	CreateLocationParticles("blast_inv", "quest", "quest3", 1.0, 0, 0, "");
	CreateLocationParticles("blast_dirt", "quest", "quest3", 1.0, 0, 0, "");
	PlaySound("Sea Battles\Vzriv_fort_001.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");
	PlaySound("Sea Battles\vzriv_pogreb_002.wav");

	DoQuestCheckDelay("GothicApostates_APS_Burn2", 0.1);
	break;

	case "GothicApostates_APS_Burn2":
                     LAi_KillCharacter(characterFromID("Apostates_Monk3"));
                     LAi_KillCharacter(characterFromID("Apostates_Monk4"));
                     LAi_KillCharacter(characterFromID("Apostates_Monk5"));
                     LAi_KillCharacter(characterFromID("Apostates_Monk6"));
                     LAi_KillCharacter(characterFromID("Apostates_Monk7"));
                     LAi_KillCharacter(characterFromID("Apostates_Monk8"));
                     LAi_KillCharacter(characterFromID("Apostates_spSold1"));
                     LAi_KillCharacter(characterFromID("Apostates_spSold2"));
 
	PlaySound("People Fight\Death_NPC_07.wav");
	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/1.5; // 1/3 жизни сносим 
	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "Ground_sitting", "", 1.0);
                     ChangeCharacterAddressGroup(PChar, "Santiago_Incquisitio2", "quest", "quest3");
	DoQuestCheckDelay("GothicApostates_APS_Burn3", 0.1);
	break;

	case "GothicApostates_APS_Burn3":
	chrDisableReloadToLocation = false;
	LAi_SetActorType(Pchar);
	LAi_ActorAnimation(Pchar, "Ground_StandUp", "GothicApostates_APS_Burn4", 3.5);
	break;

	case "GothicApostates_APS_Burn4":
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Man", "Apostates_2", "man", "man2", 10, PIRATE, -1, true, "quest"));
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Man_in_SantiagoPrison";
	sld.greeting = "";
	SetFantomParamFromRank(sld, 10, true);
	LAi_RemoveLoginTime(sld);
	LAi_SetPlayerType(pchar);	
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio2", "reload", "reload1");
	for (i=0; i<=3; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Man_"+i, "Apostates_"+(3+rand(7)), "man", "man2", 10, PIRATE, -1, true, "quest"));
	LAi_RemoveLoginTime(sld);
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, CharacterFromID("Apostates_Man"), "", -1);
	}		
	DoQuestCheckDelay("GothicApostates_APS_Santiago_prison_capture2", 1.0);
	break;

	case "GothicApostates_APS_Santiago_prison_capture2":			
	LAi_ActorGoToLocator(CharacterFromID("Apostates_Man"), "goto", "goto15", "GothicApostates_APS_Santiago_prison_capture3", -1);
	break;

	case "GothicApostates_APS_Santiago_prison_capture3":
	sld = CharacterFromID("Apostates_Man");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Man_in_SantiagoPrison";
                     LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_Santiago_prison_break":
	sld = CharacterFromID("Apostates_Man");
	LAi_SetActorType(sld);
                     LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Santiago_exittown", "goto", "goto2", "GothicApostates_APS_break", 12.0);
	for (i=0; i<=3; i++)
	{
	sld = characterFromId("Apostates_Man_"+i);
	LAi_SetActorType(sld);
                    LAi_ActorRunToLocation(sld, "reload", "reload1_back", "Santiago_exittown", "goto", "goto13", "OpenTheDoors", 11.0);	
	}
	sld = CharacterFromID("Apostates_spSold3");
	LAi_SetActorType(sld);
                     LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Santiago_exittown", "goto", "goto13", "", 14.0);		
	break;

	case "GothicApostates_APS_break":
	chrDisableReloadToLocation = false;
                     pchar.quest.GothicApostates_APS_1.win_condition.l1 = "location";
                     pchar.quest.GothicApostates_APS_1.win_condition.l1.location = "Santiago_exittown";
                     pchar.quest.GothicApostates_APS_1.win_condition = "GothicApostates_APS_1";
	break;

	case "GothicApostates_APS_1":
	chrDisableReloadToLocation = true;
	sld = CharacterFromID("Apostates_Man");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Man_in_SantiagoPrison_4";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_Santiago_shore":			
	sld = CharacterFromID("Apostates_Man");
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", -1);
	for (i=0; i<=3; i++)
	{
	sld = characterFromId("Apostates_Man_"+i);
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
	}
	sld = CharacterFromID("Apostates_spSold3");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
		
	pchar.location.from_sea = "Shore11"; //мыс Камагуэй
	setWDMPointXZ("Shore11");						
	AddQuestRecord("APS", "3");
	pchar.quest.GothicApostates_APS_Santiagoshore2.win_condition.l1 = "location";	pchar.quest.GothicApostates_APS_Santiagoshore2.win_condition.l1.location = "Cuba1";
	pchar.quest.GothicApostates_APS_Santiagoshore2.win_condition = "GothicApostates_APS_fight_near_Santiago";
			
	break;
	
	case "GothicApostates_APS_fight_near_Santiago":
	Island_SetReloadEnableGlobal("Cuba1", false);//на остров нельзя
	bQuestDisableMapEnter = true;//и на карту тоже нельзя
	Group_FindOrCreateGroup("GothicApostates_Attack");
	SelectLevelWarShipParameter();//автолевеллинг
    for (i = 1; i <= 2; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter("ApostatesSpain_"+i, "mercen_"+(rand(27)+1), "man", "man", sti(PChar.rank)+MOD_SKILL_ENEMY_RATE/2, SPAIN, 10, true, "hunter"));
	FantomMakeSmallSailor(sld, iGlobalTemp, "", iTotalTemp, 10+rand(5), 10+rand(5), 10+rand(5), 10+rand(5), 15+rand(5));
	FantomMakeCoolFighter(sld, sti(PChar.rank)+MOD_SKILL_ENEMY_RATE/2, 30, 30, sTotalTemp, "pistol2", "grapeshot", 30);
		if (i == 1)
		{
	sld.lastname = "";
		}
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.AnalizeShips = true;
        Group_AddCharacter("GothicApostates_Attack", "ApostatesSpain_"+i);
    }
                     Group_SetGroupCommander("GothicApostates_Attack", "ApostatesSpain_1");
	Group_SetTaskAttack("GothicApostates_Attack", PLAYER_GROUP);
	Group_SetPursuitGroup("GothicApostates_Attack", PLAYER_GROUP);
	Group_SetAddress("GothicApostates_Attack", "Cuba1", "", "");
	Group_LockTask("GothicApostates_Attack");
    
                     pchar.quest.GothicApostatesAttack_AfterBattle.win_condition.l1 = "Group_Death";
	pchar.quest.GothicApostatesAttack_AfterBattle.win_condition.l1.group = "GothicApostates_Attack";
	pchar.quest.GothicApostatesAttack_AfterBattle.function = "GothicApostates_Attack_AfterBattle";

	break;

	case "GothicApostates_APS_Trinidad":
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesFB", "Apostates_17", "man", "man2", 10, PIRATE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 30, 100, 70, "blade38", "pistol11", "bullet", 50);
	sld.name = "Филип";
	sld.lastname = "Бличер";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_FB";
	sld.greeting = "";
	sld.money = 30670;
	SetSelfSkill(sld, 50, 60, 100, 90, 80);
	SetCharacterPerk(sld, "CriticalHit");
	sld.SuperShooter  = true;
	LAi_SetImmortal(sld, false);
	sld.SaveItemsForDead  = true; 
	sld.DontClearDead = true;
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	LAi_SetCharacterUseBullet(sld, "bullet");
                     TakeNItems(sld, "grapeshot", 47);
	TakeNItems(sld, "bullet", 23);
	TakeNItems(sld, "cartridge", 30);
	TakeNItems(sld, "GunPowder", 35);
	LAi_RemoveLoginTime(sld);
	LAi_SetStayType(sld);
	ChangeCharacterAddressGroup(sld, "PortSpein_houseF4", "goto", "goto1");

                     pchar.quest.GothicApostates_APS_in_SanJuan_1.win_condition.l1 = "location";
                     pchar.quest.GothicApostates_APS_in_SanJuan_1.win_condition.l1.location = "PortSpein_houseF4";
                     pchar.quest.GothicApostates_APS_in_SanJuan_1.win_condition = "GothicApostates_APS_Trinidad_1";
		
	break;

	case "GothicApostates_APS_Trinidad_1":			
	LAi_SetActorType(pchar);
	StartQuestMovie(false, false, true);
	LAi_ActorGoToLocator(pchar, "goto", "goto2", "GothicApostates_APS_PortSpeinHouse", -1);
	break;
	
	case "GothicApostates_APS_PortSpeinHouse":
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_SpOfficer", "off_spa_4", "man", "man", 10, SPAIN, -1, true, "quest"));
	sld.name = "Комендант";
	sld.lastname = "";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_SpOfficerInStJuan";
	sld.greeting = "underarrest";
	LAi_RemoveLoginTime(sld);
	ChangeCharacterAddressGroup(sld, "PortSpein_houseF4", "reload", "reload1_back");
	LAi_SetActorType(sld);
	LAi_ActorWaitDialog(pchar, sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0.5);
	break;

	//локация фантомного форта ->

	case "GothicApostates_APS_END":	
                     LAi_LocationDisableOfficersGen("PortSpein_town", true);
	EndQuestMovie();
	LAi_SetActorType(pchar);		
	DoQuestReloadToLocation("Shore98", "quest", "quest4", "GothicApostates_APS_in_SanJuanHouse_ENDGAME_0");

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_SpOfficer1", "off_spa_5", "man", "man", 10, Spain, -1, true, "quest"));
	ChangeCharacterAddressGroup(sld, "Shore98", "quest", "quest9");

	sld = GetCharacter(NPC_GenerateCharacter("Killer_SpaSol_1", "mush_spa_"+(4+rand(2)), "man", "mushketer", iRank, Spain, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket2", "cartridge", iScl*2);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Shore98", "quest", "quest5");

	sld = GetCharacter(NPC_GenerateCharacter("Killer_SpaSol_2", "mush_spa_"+(4+rand(2)), "man", "mushketer", iRank, Spain, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket2", "cartridge", iScl*2);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Shore98", "quest", "quest6");

	sld = GetCharacter(NPC_GenerateCharacter("Killer_SpaSol_3", "mush_spa_"+(4+rand(2)), "man", "mushketer", iRank, Spain, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket2", "cartridge", iScl*2);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Shore98", "quest", "quest7");

	sld = GetCharacter(NPC_GenerateCharacter("Killer_SpaSol_4", "mush_spa_"+(4+rand(2)), "man", "mushketer", iRank, Spain, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket2", "cartridge", iScl*2);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Shore98", "quest", "quest8");

	DoQuestCheckDelay("GothicApostates_APS_in_SanJuanHouse_ENDGAME_0", 3.0);	
	break;

	case "GothicApostates_APS_in_SanJuanHouse_ENDGAME_0":
	sld = CharacterFromID("Apostates_SpOfficer1");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest7");

	LAi_SetActorType(PChar);
                     LAi_ActorTurnToCharacter(PChar, characterFromID("Killer_SpaSol_1"));

	sld = CharacterFromID("Killer_SpaSol_1");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest4");

	sld = CharacterFromID("Killer_SpaSol_2");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest4");

	sld = CharacterFromID("Killer_SpaSol_3");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest4");

	sld = CharacterFromID("Killer_SpaSol_4");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest4");
	DoQuestCheckDelay("GothicApostates_ENDGAME_1", 1.0);			
	break;

	case "GothicApostates_ENDGAME_1":
	PlaySound("ambient\church\zvon.wav");
	Log_Info("Взвод: Оружие на изготовку...");
	DoQuestCheckDelay("GothicApostates_ENDGAME_2", 4.0);
	break;
		
	case "GothicApostates_ENDGAME_2":
	PlaySound("ambient\church\zvon.wav");
	Log_Info("...По сообщнику и еретику за подсобничество дьяволу...");
	DoQuestCheckDelay("GothicApostates_ENDGAME_3", 4.0);
	break;

	case "GothicApostates_ENDGAME_3":
	sld = CharacterFromID("Apostates_SpOfficer1");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest4");
	PlaySound("ambient\church\zvon.wav");
	Log_Info("...ПЛИ...");
	DoQuestCheckDelay("GothicApostates_APS_Trinidad_ENDGAME_2", 2.0);
	break;
		
	case "GothicApostates_APS_Trinidad_ENDGAME_2":
	sld = CharacterFromID("Killer_SpaSol_1");
	LAi_SetActorType(sld);
                     LAi_ActorAnimation(sld, "Shot", "GothicApostates_APS_Trinidad_ENDGAME_3", 1.0);

	sld = CharacterFromID("Killer_SpaSol_2");
	LAi_SetActorType(sld);
                     LAi_ActorAnimation(sld, "Shot", "GothicApostates_APS_Trinidad_ENDGAME_3", 1.0);

	sld = CharacterFromID("Killer_SpaSol_3");
	LAi_SetActorType(sld);
                     LAi_ActorAnimation(sld, "Shot", "GothicApostates_APS_Trinidad_ENDGAME_3", 1.0);

	sld = CharacterFromID("Killer_SpaSol_4");
	LAi_SetActorType(sld);
                     LAi_ActorAnimation(sld, "Shot", "GothicApostates_APS_Trinidad_ENDGAME_3", 1.0);
	break;
		
	case "GothicApostates_APS_Trinidad_ENDGAME_3":
	PlaySound("People Fight\Player_Man_Shoot_01.WAV");
	DoQuestCheckDelay("GothicApostates_APS_Trinidad_ENDGAME_4", 1.0);
	break;
		
	case "GothicApostates_APS_Trinidad_ENDGAME_4":
	CreateLocationParticles("blood_big", "quest", "quest4", 1.7, 0, 0, "");
	PlaySound("People Fight\Death_NPC_05.WAV");
	LAi_KillCharacter(pchar);
	break;

	//локация фантомного форта ->

	// Продолжаем игру ->

	case "GothicApostates_APS_Trinidad_man":
	sld = CharacterFromID("ApostatesFB");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_FB";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);

	EndQuestMovie();			
	LAi_SetPlayerType(pchar);			
	ChangeCharacterAddressGroup(CharacterFromID("Apostates_SpOfficer"), "none", "", "");

	 for (i=1; i<=20; i++)
                      {
	 sld = GetCharacter(NPC_GenerateCharacter("Apostates_SpSold_"+i, "sold_Spa_"+(rand(7)+1), "man", "man", 30, Spain, -1, false, "soldier"));
                      FantomMakeCoolFighter(sld, 25, 70, 60, BLADE_LONG, "pistol2", "grapeshot", 20);
	 ChangeCharacterAddressGroup(sld, "PortSpein_town", "goto", "goto"+(rand(20)+i)); 
	 LAi_SetCheckMinHP(sld, 10, true, ""); // скрытое бессмертие
	 LAi_CharacterDisableDialog(sld);
	 LAi_SetCitizenType(sld);			
	 }
	break;
	
	case "GothicApostates_APS_from":
	// Flag_PIRATE();
	sld = CharacterFromID("ApostatesFB");
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
	LAi_ActorFollowEverywhere(sld, "", -1);

	pchar.quest.GothicApostatesAPS2.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS2.win_condition.l1.location = "PortSpein_town";
                     pchar.quest.GothicApostatesAPS2.win_condition.l1.locator_group = "reload";
	pchar.quest.GothicApostatesAPS2.win_condition.l1.locator = "houseF4";
	pchar.quest.GothicApostatesAPS2.win_condition = "GothicApostates_APS_fromPortSpein";
	break;
	
	case "GothicApostates_APS_fromPortSpein":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
	LAi_ActorFollowEverywhere(sld, "", -1);
	ChangeCharacterAddressGroup(sld, "PortSpein_town", "reload", "houseF4");

	for (i=1; i<=20; i++)
                    {
	sld=characterFromID("Apostates_SpSold_"+i);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "WAR_Apostates_SpSold");
	LAi_group_FightGroups("WAR_Apostates_SpSold", LAI_GROUP_PLAYER, true);
	}
                     Pchar.quest.GothicApostatesAPS_Sea.win_condition.l1 = "location";			Pchar.quest.GothicApostatesAPS_Sea.win_condition.l1.location = "Trinidad";
	Pchar.quest.GothicApostatesAPS_Sea.win_condition = "GothicApostates_APS_FB_Ship";		
	break;

	case "GothicApostates_APS_FB_Ship":					
	pchar.questTemp.APS = "APS_LaMar";	
	AddQuestRecord("APS", "4");

	for (i=1; i<=20; i++)
                     {
	 sld=characterFromID("Apostates_SpSold_"+i);
	 LAi_SetActorType(sld);
                      LAi_ActorGoToLocation(sld, "reload", "reload4_back", "none", "", "", "", 1.0);
	 LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	 }					
	sld = CharacterFromID("ApostatesFB");
	LAi_SetStayType(sld);
	ChangeCharacterAddressGroup(sld, "none", "", "");
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, false);
	break;

	case "GothicApostatesAPSbank":
	sld = CharacterFromID("ApostatesDN");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");
	DoQuestCheckDelay("GothicApostatesAPSbank1", 2.0);
	break;

	case "GothicApostatesAPSbank1":
	sld = characterFromId("ApostatesDN");
	sld.BreakTmplAndFight = true;
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "reload", "reload2", "GothicApostatesAPSbank2", -1.0);
	break;

	case "GothicApostatesAPSbank2":
                     PlaySound("interface\key.wav");//щелк!
	DoQuestCheckDelay("GothicApostatesAPSbank3", 2.0);
	break;

	case "GothicApostatesAPSbank3":
                     LocatorReloadEnterDisable("PortAntonio_bank", "reload2", false);//откроем дверку
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_2";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_bank":
	sld = CharacterFromID("ApostatesRK");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Second life";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);		
                     LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		
	sld = CharacterFromID("ApostatesFB");
	RemovePassenger(pchar, sld);
	ChangeCharacterAddressGroup(sld, "PortAntonio_Bank_residence", "goto", "goto9");
	LAi_SetActorType(sld);
	sld.dialog.currentnode = "Apostates_FB_6";
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));


	pchar.quest.GothicApostatesAPS_3.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_3.win_condition.l1.location = "PortAntonio_Bank_residence";
                     pchar.quest.GothicApostatesAPS_3.win_condition.l1.locator_group = "reload";
	pchar.quest.GothicApostatesAPS_3.win_condition.l1.locator = "reload1";
	pchar.quest.GothicApostatesAPS_3.win_condition = "GothicApostates_APS_bank1";			
	break;

	case "GothicApostates_APS_bank1":
	LAi_SetActorType(pchar);
	LAi_ActorGoToLocator(pchar, "goto", "goto6", "GothicApostates_APS_bank_dialog", -1);	
	break;

	case "GothicApostates_APS_bank_dialog":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
	LAi_ActorTurnToLocator(pchar, "goto", "goto10");
	DoQuestCheckDelay("GothicApostates_APS_bank_dialog1", 0.5);
	break;

	case "GothicApostates_APS_bank_dialog1":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesFB"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesFB"), pchar, "GothicApostates_APS_bank_dialog2", 0.5);
	break;

	case "GothicApostates_APS_bank_dialog2":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	DoQuestCheckDelay("GothicApostates_APS_bank_dialog3", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog3":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesRK"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesRK"), pchar, "GothicApostates_APS_bank_dialog4", 0.5);
	break;

	case "GothicApostates_APS_bank_dialog4":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
	DoQuestCheckDelay("GothicApostates_APS_bank_dialog5", 0.5);
	break;

	case "GothicApostates_APS_bank_dialog5":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesFB"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesFB"), pchar, "GothicApostates_APS_bank_dialog6", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog6":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	DoQuestCheckDelay("GothicApostates_APS_bank_dialog7", 0.5);
	break;

	case "GothicApostates_APS_bank_dialog7":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesRK"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesRK"), pchar, "GothicApostates_APS_bank_dialog8", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog8":
	sld = CharacterFromID("ApostatesFB");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesFB"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesFB"), pchar, "GothicApostates_APS_bank_dialog9", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog9":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	DoQuestCheckDelay("GothicApostates_APS_bank_dialog10", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog10":
	sld = CharacterFromID("ApostatesRK");
	LAi_SetActorType(sld);
                    LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("ApostatesRK"));
	LAi_ActorDialogNow(CharacterFromID("ApostatesRK"), pchar, "GothicApostates_APS_bank_dialog11", 0.5);
	break;
		
	case "GothicApostates_APS_bank_dialog11":
	LAi_ActorGoToLocation(CharacterFromID("ApostatesFB"), "reload", "reload1", "none", "", "", "GothicApostates_APS_bank2", -1);
	break;

	case "GothicApostates_APS_bank2":
	LAi_SetPlayerType(pchar);
	sld = CharacterFromID("ApostatesRK");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_3";
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	// Отказались от предложения ->

	 case "GothicApostates_APS_END":
	 PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
                      LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	sld = CharacterFromID("ApostatesRK");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_11";
	LAi_SetCitizenType(sld);
	AddCharacterExpToSkill(pchar, "LeaderShip", 50);
	CloseQuestHeader("APS");
	break;

	// Продолжение квеста ->

	case "GothicApostates_APS_usurer":
	pchar.questTemp.APS = "APS_usurer";	
	AddQuestRecord("APS", "5");
	sld = CharacterFromID("ApostatesRK");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_11";
	LAi_SetCitizenType(sld);

	sld = CharacterFromID("ApostatesLA");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "W_headclerk";
	break;
	
	case "GothicApostates_APS_church":
	AddQuestRecord("APS", "6");

	SetFunctionTimerCondition("GothicApostatesAPSChurchOver", 0, 0, 2, false);//таймер

	pchar.quest.GothicApostatesAPSChurch.win_condition.l1 = "Timer";
	pchar.quest.GothicApostatesAPSChurch.win_condition.l1.date.hour  = sti(GetTime());
	pchar.quest.GothicApostatesAPSChurch.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
	pchar.quest.GothicApostatesAPSChurch.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	pchar.quest.GothicApostatesAPSChurch.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
	pchar.quest.GothicApostatesAPSChurch.win_condition.l2 = "Hour";
	pchar.quest.GothicApostatesAPSChurch.win_condition.l2.start.hour = 0;
	pchar.quest.GothicApostatesAPSChurch.win_condition.l2.finish.hour = 4;
	pchar.quest.GothicApostatesAPSChurch.win_condition.l3 = "locator";
	pchar.quest.GothicApostatesAPSChurch.win_condition.l3.location = "SanJuan_church";
                     pchar.quest.GothicApostatesAPSChurch.win_condition.l3.locator_group = "reload";
	pchar.quest.GothicApostatesAPSChurch.win_condition.l3.locator = "reload1";
	pchar.quest.GothicApostatesAPSChurch.win_condition = "GothicApostatesAPSChurch";		break;
		
	case "GothicApostatesAPSChurch":							pchar.quest.GothicApostatesAPS_4.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_4.win_condition.l1.location = "SanJuan_church";
	pchar.quest.GothicApostatesAPS_4.win_condition = "GothicApostates_APSChurch_3";
	break;

	case "GothicApostates_APSChurch_3":
	pchar.quest.GothicApostatesAPSChurchOver.over = "yes";//снять прерывание		
	StartQuestMovie(false, false, true);
	LAi_SetActorType(pchar);
	LAi_ActorGoTolocator(pchar, "quest", "quest1", "GothicApostates_APSChurch_4", -1);
	break;

	case "GothicApostates_APSChurch_4":
	LAi_ActorTurnToLocator(pchar, "goto", "goto11");
	DoQuestCheckDelay("GothicApostates_APSChurch_5", 1.0);
	break;

	case "GothicApostates_APSChurch_5":
	locCameraToPos(0, 4, 2, 0);
	sld = characterFromId("Benua");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "APS_Benua";
	sld.greeting = "Gr_Church";
	Lai_RemoveLoginTime(sld);
	ChangeCharacterAddressGroup(sld, "SanJuan_church", "reload", "reload1");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "barmen", "stay", "GothicApostates_APSChurch_6", -1);

	sld = CharacterFromID("SanJuan_Priest");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocator(sld, "barmen", "bar2", "", -1);
	break;

	case "GothicApostates_APSChurch_6":
	LAi_ActorTurnToLocator(CharacterFromID("Benua"), "goto", "goto11");

	// Норман Эддисон(отступники)
	sld = GetCharacter(NPC_GenerateCharacter("ApostatesNI", "Apostates_11", "man", "man2", 30, SPAIN, -1, false, "quest"));
	sld.name = "Норман";
	sld.lastname = "Эддисон";
	sld.greeting = "";
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "ApostatesNI";
	sld.rank = 11;
	LAi_SetHP(sld, 250, 250);
	sld.money = 5000;
	sld.SaveItemsForDead = true;
	sld.DontClearDead = true;
	SetSelfSkill(sld, 60, 60, 65, 60, 50);
	SetShipSkill(sld, 50, 20, 20, 20, 20, 20, 70, 20, 70);
	SetSPECIAL(sld, 10, 6, 10, 7, 6, 10, 8);
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
	SetCharacterPerk(sld, "GrapplingProfessional");
	SetCharacterPerk(sld, "Brander");
	SetCharacterPerk(sld, "Troopers");
	SetCharacterPerk(sld, "LongRangeGrappling");
	SetCharacterPerk(sld, "MusketsShoot");
	GiveItem2Character(sld, "blade41");
	sld.equip.blade = "blade41";
	TakeNItems(sld, "potion2", 2);
	sld.HoldEquip = true; 	//не отдавать оружие
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "SanJuan_church", "reload", "reload1");
	LAi_ActorGoToLocator(sld, "goto", "goto11", "GothicApostates_APSChurch_7", -1);		
	break;

	case "GothicApostates_APSChurch_7":
	LAi_ActorTurnToLocator(CharacterFromID("ApostatesNI"), "quest", "detector1");		
	pchar.name_old = pchar.name;
	pchar.lastname_old = pchar.lastname;
	pchar.name = "Епископ и";
	pchar.lastname = "наемник";
	pchar.dialog.currentnode = "GothicApostates_dialog";
	LAi_ActorSelfDialog(pchar, "GothicApostates_APSChurch_8");
	break;

	case "GothicApostates_APSChurch_8":
	LAi_SetActorType(pchar);
	LAi_SetActorType(CharacterFromID("Benua"));
	LAi_ActorWaitDialog(pchar, CharacterFromID("Benua"));
	DoQuestCheckDelay("GothicApostates_APSChurch_fight", 0.5);
	break;

	case "GothicApostates_APSChurch_9":
	LAi_ActorDialogNow(CharacterFromID("Benua"), pchar, "GothicApostates_APSChurch_fight", 0.5);
	break;
	
	case "GothicApostates_APSChurch_fight":
	pchar.name = pchar.name_old;
	pchar.lastname = pchar.lastname_old;			
	DeleteAttribute(pchar, "name_old");
	DeleteAttribute(pchar, "lastname_old");
			
	sld = CharacterFromID("Benua");
	LAi_ActorGoToLocation(CharacterFromID("Benua"), "reload", "reload1", "none", "", "", "", 11);
	LAi_ActorGoToLocation(CharacterFromID("ApostatesNI"), "reload", "reload1", "none", "", "", "", 11);
	DoQuestCheckDelay("GothicApostates_APSChurch_fight1", 12.0);
	break;

	case "GothicApostates_APSChurch_fight1":
			
	chrDisableReloadToLocation = true;
	iScl = 20 + 2*sti(pchar.rank);			
	for (i=1; i<=4; i++)
	{
	sld = GetCharacter(NPC_GenerateCharacter("APS_marginal_"+i, "citiz_4"+i, "man", "man", iRank, PIRATE, -1, false, "soldier"));
	FantomMakeCoolFighter(sld, iRank, iScl, iScl, RandPhraseSimple("blade_05","blade_07"), "pistol1", "bullet", iScl*2);
	Lai_RemoveLoginTime(sld);
	ChangeCharacterAddressGroup(sld, "SanJuan_church", "reload", "reload1");
	LAi_SetStayTypeNoGroup(sld);
	LAi_group_MoveCharacter(sld, "monk_grp");
	}
			
	LAi_SetPlayerType(pchar);						
	locCameraTarget(pchar);
	locCameraFollow();
	EndQuestMovie();
			
	LAi_group_FightGroups("monk_grp", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("monk_grp", "GothicApostates_APSChurch_dead");
	LAi_LocationFightDisable(&locations[FindLocation(pchar.location)], false);
	LAi_SetFightMode(pchar, true);

	sld = GetCharacter(NPC_GenerateCharacter("Benua", "abbat", "man", "man_B", 20, FRANCE, -1, false, "quest"));
	sld.name = "аббат";
	sld.lastname = "Бенуа";
	sld.greeting = "Gr_Church";
                  sld.Dialog.Filename = "Quest\Sharlie\Benua.c";
	sld.dialog.currentnode = "First time";
	sld.rank = 25;
	GiveItem2Character(sld, "unarmed");
	sld.equip.blade = "unarmed";
	sld.equip.gun = "";
	LAi_SetImmortal(sld, true);
	LAi_SetStayType(sld);
	sld.location = "FortFrance_church";
	sld.location.group = "reload";
	sld.location.locator = "reload2_back";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	break;

	case "GothicApostates_APSChurch_dead":
	sld = CharacterFromID("SanJuan_Priest");
	sld.Dialog.Filename = "Common_church.c";
	sld.greeting = "padre_2";
	LAi_SetPriestType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	LAi_SetImmortal(sld, true);

	chrDisableReloadToLocation = false;
                     LocatorReloadEnterDisable("FortOrange_bank", "reload2", true);//закроем банк
	AddQuestRecord("APS", "8");
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_3";
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "FortOrange_bank", "officers", "reload2_1");	
	LAi_LocationFightDisable(&locations[FindLocation(pchar.location)], true);
	characters[GetCharacterIndex("ApostatesRK")].dialog.currentnode = "second_20";		
	break;

	case "GothicApostatesAPSbank4":
	sld = CharacterFromID("ApostatesDN");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");
	DoQuestCheckDelay("GothicApostatesAPSbank5", 2.0);
	break;

	case "GothicApostatesAPSbank5":
	sld = characterFromId("ApostatesDN");
	sld.BreakTmplAndFight = true;
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "reload", "reload2", "GothicApostatesAPSbank6", -1.0);
	break;

	case "GothicApostatesAPSbank6":
                     PlaySound("interface\key.wav");//щелк!
	DoQuestCheckDelay("GothicApostatesAPSbank7", 1.0);
	break;

	case "GothicApostatesAPSbank7":
                     LocatorReloadEnterDisable("FortOrange_bank", "reload2", false);//откроем дверку
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_8";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_message":
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_20";
	break;

	case "GothicApostates_APS_PortoBello":
	AddQuestRecord("APS", "10");
	SetFunctionTimerCondition("GothicApostatesAPSCPortoBelloOver", 0, 0, 10, false); //таймер
	pchar.quest.APS_usurerPortoBelloOver.win_condition.l1 = "location";//прерывание на выполнение
	pchar.quest.APS_usurerPortoBelloOver.win_condition.l1.location = "PortoBello_town";
	pchar.quest.APS_usurerPortoBelloOver.function = "GothicApostatesAPSCPortoBello";

	break;
	
	case "GothicApostates_APS_wait":
	AddQuestRecord("APS", "12");

	SetFunctionTimerCondition("GothicApostatesAPSwaitOver", 0, 0, 2, false);//таймер

	pchar.quest.GothicApostatesAPSwait.win_condition.l1 = "Timer";
	pchar.quest.GothicApostatesAPSwait.win_condition.l1.date.hour  = sti(GetTime());
	pchar.quest.GothicApostatesAPSwait.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
	pchar.quest.GothicApostatesAPSwait.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	pchar.quest.GothicApostatesAPSwait.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
	pchar.quest.GothicApostatesAPSwait.win_condition.l2 = "Hour";
	pchar.quest.GothicApostatesAPSwait.win_condition.l2.start.hour = 0;
	pchar.quest.GothicApostatesAPSwait.win_condition.l2.finish.hour = 5;
	pchar.quest.GothicApostatesAPSwait.win_condition.l3 = "locator";
	pchar.quest.GothicApostatesAPSwait.win_condition.l3.location = "PortoBello_town";
                     pchar.quest.GothicApostatesAPSwait.win_condition.l3.locator_group = "reload";
	pchar.quest.GothicApostatesAPSwait.win_condition.l3.locator = "reload8_back";
	pchar.quest.GothicApostatesAPSwait.win_condition = "GothicApostatesAPSwait";

	break;

	case "GothicApostatesAPSwait":
	LAi_LocationDisableOfficersGen("PortoBello_bank", true); //офицеров не пускать
	locations[FindLocation("PortoBello_town")].reload.l8.close_for_night = false;			pchar.quest.GothicApostatesAPS_5.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_5.win_condition.l1.location = "PortoBello_bank";
	pchar.quest.GothicApostatesAPS_5.win_condition = "GothicApostates_APSPortoBello_1";
	break;

	case "GothicApostates_APSPortoBello_1":
	pchar.quest.GothicApostatesAPSwaitOver.over = "yes";//снять прерывание
	chrDisableReloadToLocation = true;		
	sld = CharacterFromID("ApostatesNI");
	LAi_SetActorType(sld);
                     LAi_ActorTurnToCharacter(sld, characterFromID("PortoBello_usurer"));
	sld1 = CharacterFromID("PortoBello_usurer");
	LAi_SetActorType(sld1);
                     LAi_ActorTurnToCharacter(sld1, characterFromID("ApostatesNI"));
	ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto2");
	StartQuestMovie(false, false, true);
	LAi_SetActorType(pchar);
	LAi_ActorFollow(pchar, sld, "GothicApostates_APS_NIdialog", 2.0);
	break;

	case "GothicApostates_APS_NIdialog":
	pchar.old_name = pchar.name;
	pchar.old_lastname = pchar.lastname;
	pchar.name = "(Норман Эддисон и ";
	pchar.lastname = "ростовщик)";			
	pchar.dialog.currentnode = "GothicApostates_APS_dialogNI";
	LAi_ActorSelfDialog(pchar, "GothicApostates_APS_NIdialog3");
	break;

	case "GothicApostates_APS_NIdialog3":
	PlaySound("VOICE\Russian\Apostates_010.wav");
	pchar.name = pchar.old_name;
	pchar.lastname = pchar.old_lastname;
	DeleteAttribute(pchar, "old_name");
	DeleteAttribute(pchar, "old_lastname");
			
	sld = CharacterFromID("ApostatesNI");
	LAi_SetStayType(sld);
	LAi_ActorDialog(pchar, sld, "GothicApostates_APS_dialog4", -1, 0.5);
	break;

	case "GothicApostates_APS_dialog4":
	EndQuestMovie();			
	LAi_LocationFightDisable(&locations[FindLocation(pchar.location)], false);
	LAi_SetPlayerType(pchar);			
	sld = CharacterFromID("ApostatesNI");
	LAi_SetWarriorTypeNoGroup(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			
	LAi_SetCheckMinHP(sld, 5.0, true, "GothicApostates_APS_dialog5");
	break;

	case "GothicApostates_APS_dialog5":
	PlaySound("VOICE\Russian\Ransack_2.wav");
	LAi_LocationFightDisable(&locations[FindLocation(pchar.location)], true);
	LAi_SetActorType(pchar);
			
	sld = CharacterFromID("ApostatesNI");
	LAi_SetActorType(sld);
	LAi_ActorWaitDialog(pchar, sld);
	LAi_ActorDialog(sld, pchar, "GothicApostates_APS_dialog6", -1, 0.5);
	break;

	case "GothicApostates_APS_dialog6":
	PlaySound("VOICE\Russian\pirat_quest_2.wav");
	LAi_LocationDisableOfficersGen("PortoBello_bank", false);
	StartQuestMovie(false, false, true);			
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Mason", "Apostates_15", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Mason";
	Lai_RemoveLoginTime(sld);
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1_back");
	LAi_SetActorType(sld);
			
	LAi_ActorWaitDialog(pchar, sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0.5);
	break;

	case "GothicApostates_APS_dialog7":
	LAi_SetActorType(pchar);
	LAi_ActorGoToLocation(CharacterFromID("Apostates_Mason"), "reload", "reload1_back", "none", "", "", "", 5.0);
	LAi_ActorGoToLocation(CharacterFromID("ApostatesNI"), "reload", "reload1_back", "none", "", "", "GothicApostates_APS_dialogEnd", 5.0);
	break;

	case "GothicApostates_APS_dialogEnd":
                    LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);//закроем банк
	chrDisableReloadToLocation = false;
	AddQuestRecord("APS", "13");
	pchar.questTemp.APS = "APS_PortoBellofrom";
	EndQuestMovie();
	LAi_SetPlayerType(pchar);						
	sld = CharacterFromID("PortoBello_usurer");
	LAi_SetLoginTime(sld, 6.0, 22.0);
	LAi_SetBarmanType(sld);
	locations[FindLocation("PortoBello_town")].reload.l8.close_for_night = true;
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_PortoBellofrom";
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "PortAntonio_bank", "officers", "reload2_1");
	break;

	case "GothicApostates_APS_dialogEnd1":
	sld = CharacterFromID("ApostatesDN");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");
	DoQuestCheckDelay("GothicApostates_APS_dialogEnd2", 2.0);
	break;

	case "GothicApostates_APS_dialogEnd2":
	sld = characterFromId("ApostatesDN");
	sld.BreakTmplAndFight = true;
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "reload", "reload2", "GothicApostates_APS_dialogEnd3", -1.0);
	break;

	case "GothicApostates_APS_dialogEnd3":
                     PlaySound("interface\key.wav");//щелк!
	DoQuestCheckDelay("GothicApostates_APS_dialogEnd4", 1.0);
	break;

	case "GothicApostates_APS_dialogEnd4":
                     LocatorReloadEnterDisable("PortAntonio_bank", "reload2", false);//откроем дверку
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_PortoBellofrom_2";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostates_APS_dialogEnd5":
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_27";
	break;

	case "APSH_Ruins":
                    LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);//закроем банк
	AddQuestRecord("APSH", "8");
	LocatorReloadEnterDisable("church IM2", "reload2_back", true); // закроем склеп до победы над вейном
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_APSH";
	LAi_SetGuardianType(sld);
	ChangeCharacterAddressGroup(sld, "PortAntonio_bank", "officers", "reload2_1");
	break;

	case "APSH_Ruins1":
	sld = CharacterFromID("ApostatesDN");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");
	DoQuestCheckDelay("APSH_Ruins2", 2.0);
	break;

	case "APSH_Ruins2":
	sld = characterFromId("ApostatesDN");
	sld.BreakTmplAndFight = true;
	LAi_SetActorTypeNoGroup(sld);
	LAi_ActorRunToLocator(sld, "reload", "reload2", "APSH_Ruins3", -1.0);
	break;

	case "APSH_Ruins3":
                     PlaySound("interface\key.wav");//щелк!
	DoQuestCheckDelay("APSH_Ruins4", 1.0);
	break;

	case "APSH_Ruins4":
                     LocatorReloadEnterDisable("PortAntonio_bank", "reload2", false);//откроем дверку
	sld = CharacterFromID("ApostatesDN");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "Apostates_man_APSH_2";			
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "APSH_Ruins5":
	sld = characterFromId("ApostatesRK");			
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "second_55";
	break;

	case "APSH_Ruins7":
    LocatorReloadEnterDisable("Shore127", "reload2", false);//откроем пирамиду в заливе Маяро
	AddQuestRecord("APSH", "9");
	pchar.questTemp.APSH = "APSH_Myxir";
	
	sld = characterFromId("Myxir");
	LAi_SetCitizenType(sld);
	LAi_RemoveLoginTime(sld);
	// sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	ChangeCharacterAddressGroup(sld, "Temple_Trinidad_Inside_2", "reload", "reload7");
	
	sld = GetCharacter(NPC_GenerateCharacter("APSHIroquois_1", "Iroquois_"+(rand(5)+1), "man", "man", 25, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld, 25, 70, 70, LinkRandPhrase("slave_01","slave_02","topor_05"), "pistol3", "grapeshot", 50);
	LAi_SetGroundSitTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "Shore127", "goto", "ass1");

	sld = GetCharacter(NPC_GenerateCharacter("APSHIroquois_2", "Iroquois_"+(rand(5)+1), "man", "man", 25, PIRATE, -1, true, "native"));
	FantomMakeCoolFighter(sld, 25, 70, 70, LinkRandPhrase("slave_01","slave_02","topor_05"), "pistol3", "grapeshot", 50);
	LAi_SetGroundSitTypeNoGroup(sld);
	ChangeCharacterAddressGroup(sld, "Shore127", "goto", "ass3");
	
	PChar.quest.GothicApostatesAPS_6.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPS_6.win_condition.l1.location = "Shore127";
	PChar.quest.GothicApostatesAPS_6.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPS_6.win_condition.l1.locator = "sea";
	PChar.quest.GothicApostatesAPS_6.function = "APSH_SharliVein_Iroquois";

	break;

	case "APSH_Ruins_Iroquois":
	sld = characterFromId("APSHIroquois_1");
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);

	sld = characterFromId("APSHIroquois_2");
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
	break;

	case "APSHIroquois1":
                     chrDisableReloadToLocation = false;
	break;

	case "APSH_Ruins8":// смотрим на дым
  	PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
	CreateLocationParticles("large_smoke", "quest", "LLquest1", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "LLquest1", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "quest", "LLquest1", 1.70, 3, 3, "");
	DoQuestCheckDelay("APSH_Ruins9", 1.2);
	break;
	
	case "APSH_Ruins9":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_DIE03.wav");
	PlaySound("VOICE\Russian\gotica\SFX\TRO_DIE01.wav");
	iRank = MOD_SKILL_ENEMY_RATE*3+30;
	iTemp = MOD_SKILL_ENEMY_RATE*250+500;
	float fMft = 1.0+MOD_SKILL_ENEMY_RATE/10;
	sld = GetCharacter(NPC_GenerateCharacter("SharliVein", "skel1", "skeleton", "skeleton", iRank, PIRATE, -1, true, "quest"));
	SetSelfSkill(sld, 100, 100, 100, 100, 100);
	GiveItem2Character(sld, "blade_33");
	RemoveCharacterEquip(sld, GUN_ITEM_TYPE);
	sld.equip.blade = "blade_33";
	sld.name 	= "Чарли";
	sld.lastname  = "Вейн";
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "SharliVein";
	SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10);
	SelAllPerksToChar(sld, false);
	LAi_SetHP(sld, iTemp, iTemp);
	sld.MultiFighter = fMft; // мультифайтер
	sld.SaveItemsForDead   = true;// сохранять на трупе вещи
	TakeNItems(sld, "mapSharliVein", 1);
	sld.DontClearDead = true;
	ChangeCharacterAddressGroup(sld, "church IM2", "quest", "LLquest1");
	LAi_SetGroundSitTypeNoGroup(sld);
	DoQuestCheckDelay("APSH_Ruins10", 4.0);
	break;
	
	case "APSH_Ruins10":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN01.wav");
	sld = characterFromId("SharliVein");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "APSH_Ruins11", 3.5);
	break;
	
	case "APSH_Ruins11":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN02.wav");
	sld = characterFromId("SharliVein");
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "SharliVein";
                     LAi_SetActorType(sld);
                     LAi_SetPlayerType(pchar);
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
	break;
	
	case "APSH_SharliVein_dead":
                     chrDisableReloadToLocation = false;
                     LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);//закроем банк
	LocatorReloadEnterDisable("church IM2", "reload2_back", false); // откроем склеп с сокровищем после победы над вейном
	AddQuestRecord("APSH", "11");
	CloseQuestHeader("APSH");
	pchar.questTemp.APS = "APS_usurerSavLaMar";

    sld = characterFromId("ApostatesDN");//смотрителя убираем
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "First time3";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit3");
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	PChar.quest.GothicApostatesAPS_7.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPS_7.win_condition.l1.location = "Marigo_CryptBig2";
	PChar.quest.GothicApostatesAPS_7.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPS_7.win_condition.l1.locator = "reload1";
	PChar.quest.GothicApostatesAPS_7.function = "APSH_SharliVeinDestiny";

                    //заполним сундучок.	
                    pchar.GenQuestBox.Marigo_CryptBig2.box1.items.gold = 180000;		
                    pchar.GenQuestBox.Marigo_CryptBig2.box1.items.purse3 = 2;		
                    pchar.GenQuestBox.Marigo_CryptBig2.box1.items.icollection = 1;		
                    pchar.GenQuestBox.Marigo_CryptBig2.box1.items.pistol13 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box2.items.purse2 = 2;	
                    pchar.GenQuestBox.Marigo_CryptBig2.box2.items.totem_11 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box2.items.recipe_totem_11 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box2.items.blade48 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box2.items.sculMa3 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box3.items.purse1 = 2;	
                    pchar.GenQuestBox.Marigo_CryptBig2.box3.items.suit3 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box3.items.totem_13 = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box3.items.A_map_sm = 1;
                    pchar.GenQuestBox.Marigo_CryptBig2.box3.items.recipe_totem_13 = 1;
	break;
	
	case "GothicApostatesAPS_Jamaica_1":
	AddQuestRecord("APS", "22_1");
	break;

	case "GothicApostates_APS_SavLaMarfrom":
	AddQuestRecord("APS", "22");
	PChar.quest.GothicApostatesAPS_9.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPS_9.win_condition.l1.location = "PortAntonio_town";
	PChar.quest.GothicApostatesAPS_9.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPS_9.win_condition.l1.locator = "reload8_back";
	PChar.quest.GothicApostatesAPS_9.function = "GothicApostatesAPS_FortOrangetown";
	break;

	case "GothicApostatesAPS_FortOrangetown_1":
	LAi_ActorTurnToLocator(pchar, "reload", "reload8_back");
	DoQuestCheckDelay("GothicApostatesAPS_FortOrangetown_2", 1.0);
	break;


	case "GothicApostatesAPS_FortOrangetown_2":
	sld = CharacterFromID("ApostatesNI");
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload91"); // ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload19")
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload8_back", "none", "", "", "", -1);
	sld = CharacterFromID("ApostatesFB");
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload91");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload8_back", "none", "", "", "", -1);

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Monk3", "priest_sp1", "man", "man2", 10, SPAIN, -1, true, "quest"));
	SetFantomParamFromRank(sld, 10, true);
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload91");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload8_back", "none", "", "", "GothicApostatesAPS_FortOrangetown_3", -1);
	break;

	case "GothicApostatesAPS_FortOrangetown_3":
	DoQuestCheckDelay("GothicApostatesAPS_FortOrangetown_4", 15.0);
	break;

	case "GothicApostatesAPS_FortOrangetown_4":
	AddQuestRecord("APS", "23");
	sld = CharacterFromID("ApostatesNI");
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload8_back");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 4.0);
	sld = CharacterFromID("ApostatesFB");
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload8_back");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 4.0);
	sld = CharacterFromID("Apostates_Monk3");
	ChangeCharacterAddressGroup(sld, "PortAntonio_town", "reload", "reload8_back");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "GothicApostatesAPS_FortOrangetown_5", 3.0);
	break;

	case "GothicApostatesAPS_FortOrangetown_5":
	EndQuestMovie();
                     LAi_SetPlayerType(pchar);
	sld = CharacterFromID("PortAntonio_usurer");
	sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode = "usurerSavLaMar";
	ChangeCharacterAddressGroup(sld, "PortAntonio_bank", "goto", "goto5");
	LAi_SetGroundSitTypeNoGroup(sld);

	PChar.quest.GothicApostatesAPS_10.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPS_10.win_condition.l1.location = "PortAntonio_bank";
	PChar.quest.GothicApostatesAPS_10.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPS_10.win_condition.l1.locator = "reload1_back";
	PChar.quest.GothicApostatesAPS_10.function = "GothicApostatesAPS_FortOrangeBank";
	break;
	
	case "GothicApostatesAPS_BankSavLaMar":
	CreateLocationParticles("large_smoke", "reload", "reload2", 0.5, 0, 0, "");
	CreateLocationParticles("shipfire", "reload", "reload2", 0.5, 0, 0, "fortfire");
	sld = characterFromId("PortAntonio_usurer");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "GothicApostatesAPS_BankSavLaMar1", 3.5);
	break;

	case "GothicApostatesAPS_BankSavLaMar1":
	PlaySound("People Fight\Death_NPC_05.wav");
                     LAi_KillCharacter(characterFromID("PortAntonio_usurer"));
	DoQuestCheckDelay("GothicApostatesAPS_BankSavLaMar2", 2.0);
	break;

	case "GothicApostatesAPS_BankSavLaMar2":
	sld = characterFromId("PortAntonio_usurer");
	sld.lifeday = 0;
	LAi_SetActorType(sld);
	AddQuestRecord("APS", "24");
	//подготовим Сан Андреас (выход в джунгли)
	n = FindLocation("SanAndres_town");
	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "SanAndres_ExitTown";
	locations[n].reload.gate.emerge = "reload3";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	//прерывание на испанскую эскадру
	pchar.quest.APSH_Jamaica.win_condition.l1 = "location";
	pchar.quest.APSH_Jamaica.win_condition.l1.location = "Jamaica";
	pchar.quest.APSH_Jamaica.function = "GothicApostatesAPS_Jamaica";
	break;

	case "GothicApostatesAPS_Jamaica_6":
	chrDisableReloadToLocation = false;
	pchar.quest.APS_Shore_Over.over = "yes";
	break;

	case "GothicObsessionFisrtBattleWin":
                     PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_DIEMONSTER.wav");
                     sld = characterFromId("Bill Matthew");
                     sld.Dialog.Filename = "Gothic_Quest\Apostates\npc.c";
                     sld.Dialog.CurrentNode = "BillMatthew";
                     LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
                     LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	break;

	case "GothicObsession_cemeteryman":
	LAi_LocationDisableOfficersGen("Charles_Graveyard", true); //офицеров не пускать
 	pchar.quest.GothicApostatesAPS_11.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_11.win_condition.l1.location = "Charles_Graveyard";
	pchar.quest.GothicApostatesAPS_11.win_condition = "GothicObsession_cemeteryman_1";
	break;

	case "GothicObsession_afraid":
                     PlaySound("VOICE\Russian\GOTHIC\GG_AARGH\AARGH_3.wav");	
	break;

	case "GothicObsession_cemeteryman_1":
	chrDisableReloadToLocation = true;
 	StartQuestMovie(false, false, true);
                // Создаём одержимого Делвина в нормальном виде
	sld = GetCharacter(NPC_GenerateCharacter("ObsessionDevlin", "Devlin", "man", "man", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade53", "pistol13", "grapeshot", 30);
	sld.name = "незнакомец";
	sld.lastname = "";
	sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "ObsessionDevlin";
	sld.reputation = 100;
	LAi_SetHP(sld, 600.0, 600.0);
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
	LAi_SetCharacterUseBullet(sld, "cartridge");
                     TakeNItems(sld, "grapeshot", 26);
	TakeNItems(sld, "bullet", 19);
	TakeNItems(sld, "cartridge", 24);
	TakeNItems(sld, "GunPowder", 26);
	TakeNItems(sld, "potion2", 2);
	sld.HoldEquip = true; 	//не отдавать оружие
	sld.standUp = true; //вставать и нападать на врага
	LAi_SetImmortal(sld, true);
	LAi_SetActorType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

	LAi_SetActorType(pchar);
	LAi_ActorGoTolocator(pchar, "item", "read2", "GothicObsession_cemeteryman_2", -1);
	break;

	case "GothicObsession_cemeteryman_2":
	DoQuestCheckDelay("GothicObsession_cemeteryman_3", 5.0);
	break;

	case "GothicObsession_cemeteryman_3":
	LAi_LocationDisableOfficersGen("Charles_Graveyard", false);
	LAi_SetPlayerType(pchar);
					
	sld = characterFromId("ObsessionDevlin");
	sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "ObsessionDevlin";
	LAi_RemoveLoginTime(sld);
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", 3.0, 0.5);
                     ChangeCharacterAddressGroup(sld, pchar.location, "rld",  "loc16");
	break;

	case "GothicObsession_cemeteryman_4":
	LAi_ActorTurnToLocator(pchar, "item", "read4");
	DoQuestCheckDelay("GothicObsession_cemeteryman_5", 3.0);
	break;

	case "GothicObsession_cemeteryman_5":
	chrDisableReloadToLocation = false;
	RemoveItems(PChar, "Obsession_Coin", 1);
	PlaySound("People Fight\crab_fast1.wav");
	LaunchFrameForm();
	WaitDate("", 0, 0, 0, 15, 10); //крутим время
	RecalculateJumpTable();
	DoQuestCheckDelay("GothicObsession_cemeteryman_06", 0.1);
	DoQuestCheckDelay("GothicObsession_cemeteryman_6", 1.0);
	break;

	case "GothicObsession_cemeteryman_06":
	SetLaunchFrameFormParam("Вас оглушили ударом сзади", "", 0, 5);
	PlaySound("People Fight\Death_NPC_07.wav");
	break;

	case "GothicObsession_cemeteryman_6":
	PlaySound("interface\important_item.wav");
	sld = characterFromId("ObsessionDevlin");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 1.0);
	DoQuestReloadToLocation("Charles_KeepersHouse", "goto", "goto3", "GothicObsession_cemeteryman_7");
	break;

	case "GothicObsession_cemeteryman_7":
	LAi_SetPlayerType(pchar);
	sld = characterFromId("Charles_Cemeteryman");
	sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "CemeterymanTakeCoin";
	break;

	case "GothicObsession_cemeteryman_8":
	EndQuestMovie();
	AddQuestRecord("Obsession", "3");
	sld = characterFromId("Charles_Cemeteryman");
	sld.Dialog.FileName = "Common_cemeteryman.c";
	sld.Dialog.CurrentNode = "First time";

	sld = characterFromId("ApostatesRK");
	sld.Dialog.CurrentNode = "second_96";	
	break;
	
	case "GothicObsession_ShoreKiller":
	chrDisableReloadToLocation = false;
	AddQuestRecord("Obsession", "4");
	break;

	case "GothicObsessiontable":
	chrDisableReloadToLocation = false;
	AddQuestRecord("Obsession", "7");
	pchar.questTemp.GothicRumoursObsession = "Myxir_architects_table";
	break;

	case "GothicObsession_Devlin_1":// смотрим на дым
  	PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
	CreateLocationParticles("large_smoke", "reload", "reload1", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "reload", "reload1", 1.70, 3, 3, "");
	CreateLocationParticles("large_smoke", "reload", "reload1", 1.70, 3, 3, "");
	DoQuestCheckDelay("GothicObsession_Devlin_2", 1.2);
	break;

	case "GothicObsessionDevlin2":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_DIE03.wav");
	PlaySound("VOICE\Russian\gotica\SFX\TRO_DIE01.wav");
	sld = GetCharacter(NPC_GenerateCharacter("ObsessionDevlin", "Devlin", "man", "man", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade53", "pistol13", "grapeshot", 30);
	sld.name = "Делвин";
	sld.lastname = "Блейз";
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
                     sld.Dialog.CurrentNode = "ObsessionDevlin_2";
                     ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
	LAi_SetGroundSitTypeNoGroup(sld);
	DoQuestCheckDelay("GothicObsession_Devlin_3", 4.0);
	break;

	case "GothicObsession_Devlin_3":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN01.wav");
	sld = characterFromId("ObsessionDevlin");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "GothicObsession_Devlin_4", 3.5);
	break;

	case "GothicObsession_Devlin_4":
  	PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN02.wav");
	sld = characterFromId("ObsessionDevlin");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
                     sld.Dialog.CurrentNode = "ObsessionDevlin_2";
                     LAi_SetActorType(sld);
                     LAi_SetPlayerType(pchar);
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
	break;

	case "GothicApostatesAPS_Providence":	//первая постройка

    sld = characterFromID("ApostatesRK");//пересаживаем Магистра
    sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	LocatorReloadEnterDisable("SanAndres_town", "gate_back", false); // открываем дверь
	aref curTable;
	makearef(curTable,objFastReloadTable.table.SanAndres);
	curTable.l1.location = "SanAndres_store";
	curTable.l4.location = "SanAndres_townhall";
	LocatorReloadEnterDisable("SanAndres_town", "reload6_back", true);
	sld.Dialog.CurrentNode = "second_120";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");

	n = FindLocation("SanAndres_town");
	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "SanAndres_town_2";
	locations[n].reload.gate.emerge = "reload1_back";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "SanAndres Port";

	n = FindLocation("SanAndres_town_2");
	locations[n].reload.l4.name = "reload_2_3";
	locations[n].reload.l4.go = "SanAndres_ExitTown";
	locations[n].reload.l4.emerge = "reload3";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "ExitTown";

	n = FindLocation("SanAndres_ExitTown");
	locations[n].reload.l1.name = "reload3";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload_2_3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";
	break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  квест древние усыпальницы
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	case "Orc_tableStandUp":
	sld = characterFromId("Orc_table");
	LAi_SetActorType(sld);
	LAi_ActorAnimation(sld, "Ground_StandUp", "Orc_tableFight", 3.5);
                    PlaySound("VOICE\Russian\gotica\SFX\ORC_DIE01.wav");
                     break;
	
	case "Orc_tableFight":
	PlaySound("ambient\horror\horror2.wav");
	PlaySound("types\ORC_02.wav");
	LAi_SetPlayerType(Pchar);
	sld = characterFromId("Orc_table");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "tableAfterBattle");
                     break;

	case "tableAfterBattle":
                     chrDisableReloadToLocation = false;
                     AddQuestRecord("Architects", "1_1");
	AddComplexSelfExpToScill(200, 200, 200, 200);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_133";
	break;

	case "Skel_tableFight":
                     chrDisableReloadToLocation = false;
                     AddQuestRecord("Architects", "2_1");
                     AddComplexSelfExpToScill(200, 200, 200, 200);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_138";
	break;

	case "Skel_tableFight_2":
                     chrDisableReloadToLocation = false;
                     AddQuestRecord("Architects", "3_1");
                     AddComplexSelfExpToScill(200, 200, 200, 200);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_143";
	break;

	case "Skel_tableFight_3":
                     chrDisableReloadToLocation = false;
                     AddQuestRecord("Architects", "4_1");
                     AddComplexSelfExpToScill(200, 200, 200, 200);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_148";
	break;

	case "Skel_tableFight_4":
                     chrDisableReloadToLocation = false;
                     AddQuestRecord("Architects", "5_1");
                     AddComplexSelfExpToScill(200, 200, 200, 200);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_153";
	break;
	
	case "GothicApostatesAPS_Providence_2":	//вторая постройка
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_160";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");

	n = FindLocation("SanAndres_town_2");
	locations[n].reload.l4.name = "reload_2_3";
	locations[n].reload.l4.go = "SanAndres_town_3";
	locations[n].reload.l4.emerge = "reload_3_2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "SanAndres Port";

	n = FindLocation("SanAndres_town_3");
	locations[n].reload.l3.name = "reload_3_2";
	locations[n].reload.l3.go = "SanAndres_town_2";
	locations[n].reload.l3.emerge = "reload_2_3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	locations[n].reload.l4.name = "gate1_back";
	locations[n].reload.l4.go = "SanAndres_ExitTown_1";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "ExitTown";

	n = FindLocation("SanAndres_fort");
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_ExitTown_1";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	break;

	
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  скрытый квест древние усыпальницы воскрешение Куарходрона
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	case "GothicAPS_Quarhodron":

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Raven1", "Apostates_39", "man", "man2", 10, Spain, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade38", "pistol13", "grapeshot", 30);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Providence_Temple", "goto", "goto19");

	sld = GetCharacter(NPC_GenerateCharacter("Apostates_Raven2", "Apostates_40", "man", "man2", 10, Spain, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "blade39", "pistol13", "grapeshot", 30);
	LAi_SetActorType(sld);
	ChangeCharacterAddressGroup(sld, "Providence_Temple", "goto", "goto20");


                     LocatorReloadEnterDisable("Shore69", "reload2_back", false);//откроем проход
 	pchar.quest.GothicApostatesAPS_12.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_12.win_condition.l1.location = "Providence_Temple";
	pchar.quest.GothicApostatesAPS_12.win_condition = "GothicAPS_Quarhodron_1";
	break;
	
	case "GothicAPS_Quarhodron_1":
	//Locations[FindLocation("Providence_Temple")].models.always.l2 = "hram_door";
 	StartQuestMovie(false, false, true);
                     sld = characterFromId("Raven");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");

	LAi_SetActorType(pchar);
	LAi_ActorGoTolocator(pchar, "quest", "quest1", "GothicAPS_Quarhodron_2", -1);
	break;

	case "GothicAPS_Quarhodron_2":
	DoQuestCheckDelay("GothicAPS_Quarhodron_3", 5.0);
	break;

	case "GothicAPS_Quarhodron_3":					
	sld = characterFromId("Raven");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "quest", "quest1");
	DoQuestCheckDelay("GothicAPS_Quarhodron_4", 3.0);
	break;

	case "GothicAPS_Quarhodron_4":					
	sld = characterFromId("Raven");
	LAi_SetActorType(sld);
	LAi_ActorGoTolocator(sld, "quest", "quest2", "GothicAPS_Quarhodron_5", -1);
	break;

	case "GothicAPS_Quarhodron_5":
 	PlaySound("VOICE\Russian\gotica\RAVEN\BELIARPRAY.wav");			
	sld = characterFromId("Raven");
	LAi_SetActorType(sld);
	LAi_ActorTurnToLocator(sld, "reload", "reload2");
	DoQuestCheckDelay("GothicAPS_Quarhodron_6", 5.0);
	break;

	case "GothicAPS_Quarhodron_6":
 	PlaySound("VOICE\Russian\gotica\SFX\MINEAMBIENCE01.wav");				
	sld = characterFromId("Raven");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "Providence_Alcovee", "goto", "goto1", "GothicAPS_Quarhodron_7", -1);

	sld = characterFromId("Apostates_Raven1");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "Providence_Alcovee", "goto", "goto4", "", 7.0);

	sld = characterFromId("Apostates_Raven2");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload2", "Providence_Alcovee", "goto", "goto6", "", 7.0);
	break;

	case "GothicAPS_Quarhodron_7":
 	PlaySound("VOICE\Russian\gotica\SFX\MINEAMBIENCE01.wav");			                     LocatorReloadEnterDisable("Shore127", "reload2", false);	
	EndQuestMovie();
	LAi_SetPlayerType(pchar);
	pchar.questTemp.Quarhodron = "Quarhodron_Myxir";
	LocatorReloadEnterDisable("Providence_Temple", "reload2", true);
	Log_Info("Нужно сходить к Миксеру, поинтересоваться, что это за храм.");
	//Locations[FindLocation("Providence_Temple")].models.always.l2 = "";
	break;
	
	case "Gothic_CryptQuarhodron_1":
	sld = GetCharacter(NPC_GenerateCharacter("Quarhodron", "giant", "skeleton", "giant", 100, PIRATE, 0, true, "quest"));
	FantomMakeCoolFighter(sld, 100, 100, 100, "", "", "", 30);
	sld.name = "Куарходрон";
	sld.lastname = "";
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "CryptQuarhodron", "quest", "quest2");
	LAi_SetGroundSitTypeNoGroup(sld);
	DoQuestCheckDelay("Gothic_CryptQuarhodron_2", 4.0);
	break;
	
	case "Gothic_CryptQuarhodron_2":
                     PlaySound("VOICE\Russian\GOTHIC\QUARHODRON\DIA_ADDON_QUARHODRON_HELLO_11_03.wav");
	sld = characterFromId("Quarhodron");
                     LAi_SetActorType(sld); 
	LAi_ActorAnimation(sld, "Ground_StandUp", "Gothic_CryptQuarhodron_3", 3.5);
	break;

	case "Gothic_CryptQuarhodron_3":
	sld = characterFromId("Quarhodron");
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Quarhodron.c";
	sld.dialog.currentnode = "Quarhodron";
                     LAi_SetPlayerType(pchar);
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
	break;

	case "Gothic_CryptQuarhodron_4":
	sld = characterFromId("Quarhodron");
	LAi_SetActorType(sld);
	DoQuestCheckDelay("Gothic_CryptQuarhodron_5", 1.0);
	break;

	case "Gothic_CryptQuarhodron_5":
	CreateLocationParticles("fire_incas_Simple", "quest", "quest2"+i, 1.15, 0, 0, "");
	DoQuestCheckDelay("Gothic_CryptQuarhodron_6", 3.0);
	break;

	case "Gothic_CryptQuarhodron_6":
                    chrDisableReloadToLocation = false;
	PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav");
	CreateLocationParticles("fire_incas_Simple", "quest", "quest2"+i, 1.15, 0, 0, "");
	sld = characterFromId("Quarhodron");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "quest", "quest2", "none", "", "", "", 2.0);

	PChar.quest.CryptQuarhodron.win_condition.l1 = "locator";
	PChar.quest.CryptQuarhodron.win_condition.l1.location = "Providence_Temple";
	PChar.quest.CryptQuarhodron.win_condition.l1.locator_group = "reload";
	PChar.quest.CryptQuarhodron.win_condition.l1.locator = "reload2";
	PChar.quest.CryptQuarhodron.function = "Gothic_TempleQuarhodron";
	break;
	
	case "GothicTempleQuarhodron":
                    DoQuestFunctionDelay("Gothic_TempleQuarhodron_4", 2.0);
	break;
	
	case "GothicTempleRhademes":
	sld = characterFromId("Rhademes");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "teleport", "teleport6", "none", "", "", "GothicTempleRaven", -1);
	break;

	case "GothicTempleRaven":
	sld = characterFromId("Raven");
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Raven.c";
	sld.dialog.currentnode = "Raven";
                     LAi_SetPlayerType(pchar);
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
	break;

	case "GothicTempleRaven_1":
                     chrDisableReloadToLocation = true;
	sld = characterFromId("Raven");
	LAi_SetImmortal(sld, false);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	sld = characterFromId("Apostates_Raven1");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	sld = characterFromId("Apostates_Raven2");
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight");
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "GothicTempleRaven_2");
                     DoQuestFunctionDelay("GothicTempleRaven_3", 2.0);
	break;

	case "GothicTempleRaven_2":
                     chrDisableReloadToLocation = false;
	break;

	case "GothicTempleRaven_3":
	PlaySound("VOICE\Russian\gotica\SFX\MFX_SPAWN_CAST.wav");
	Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)/3;
	break;
	/*
	case "GothicApostatesAPSSanAndres15":
 	sld = CharacterFromID("Kristobal");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.currentnode = "Kristobal_2";
	LAi_SetActorType(sld);	
	LAi_ActorDialog(sld, pchar, "", 2.0, 0);
	break;
	*/

	case "GothicApostatesAPSSanAndres16":
 	sld = CharacterFromID("Kristobal");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.currentnode = "Kristobal_6";
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "APS_FirstBattleEnd":
 	sld = CharacterFromID("Florensio");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "Florensio";
	LAi_SetActorType(sld);
                     LAi_ActorDialog(sld, pchar, "", -1, 0);
	break;

	case "GothicApostatesAPSdialog1":
                   PlaySound("VOICE\Russian\HeadPirate03.wav");
	sld = CharacterFromID("Kristobal");
	LAi_SetActorType(sld);
                     LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
	DoQuestCheckDelay("GothicApostatesAPSdialog2", 0.5);
	break;

	case "GothicApostatesAPSdialog2":
	sld = CharacterFromID("Kristobal");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "Florensio_1";
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
                     LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
	break;

	case "GothicApostatesAPSdialog3":
                     PlaySound("VOICE\Russian\hunter04.wav");
	sld = CharacterFromID("Florensio");
	LAi_SetActorType(sld);
                     LAi_ActorTurnToCharacter(sld, characterFromID("Kristobal"));
	DoQuestCheckDelay("GothicApostatesAPSdialog4", 0.5);
	break;

	case "GothicApostatesAPSdialog4":
 	sld = CharacterFromID("Florensio");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "Florensio_2";
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
                     LAi_ActorTurnToCharacter(sld, characterFromID("Kristobal"));
	break;

	case "GothicApostatesAPSdialog5":
	sld = CharacterFromID("Kristobal");
	LAi_SetActorType(sld);
                     LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
	DoQuestCheckDelay("GothicApostatesAPSdialog6", 0.5);
	break;

	case "GothicApostatesAPSdialog6":
	sld = CharacterFromID("Kristobal");
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "Florensio_3";
	LAi_SetActorType(sld);
                     LAi_ActorDialogNow(sld, pchar, "", -1);
                    LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
	break;
	
	case "GothicApostatesAPSdialogEnd":
 	StartQuestMovie(false, false, true);
	LAi_SetActorType(pchar);
 	sld = CharacterFromID("Kristobal");
	LAi_SetWarriorType(sld);
                     LAi_group_MoveCharacter(sld, "EnemyFight1");

 	sld = CharacterFromID("Florensio");
	LAi_SetImmortal(sld, false);
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "EnemyFight2");
	LAi_group_FightGroups("EnemyFight1", "EnemyFight2", true);

	PChar.quest.GothicApostatesAPS1.win_condition.l1 = "NPC_Death";
	PChar.quest.GothicApostatesAPS1.win_condition.l1.character = "Florensio";
	PChar.quest.GothicApostatesAPS1.function = "GothicApostatesAPS_SanAndres_23";
	break;


	case "GothicApostatesAPSSanAndres29":
                     chrDisableReloadToLocation = false;
	sld = GetCharacter(NPC_GenerateCharacter("Apostates_iroquois", "iroquois_5", "man", "man", 10, PIRATE, -1, true, "native"));
	SetFantomParamFromRank(sld, 10, true);
	sld.name = "Венсенгуг";
	sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
	sld.dialog.currentnode   = "iroquois";
	LAi_SetActorType(sld);
	sld.lastname = "";
	LAi_SetImmortal(sld, true);
	ChangeCharacterAddressGroup(sld, "Iroquois_CaveEntrance", "reload", "reload2_back");
                     pchar.quest.APSBrachyura.win_condition.l1 = "location";
	pchar.quest.APSBrachyura.win_condition.l1.location = "Iroquois_CaveEntrance";
	pchar.quest.APSBrachyura.win_condition = "GothicApostatesAPSSanAndres029";
	break;

                  case "GothicApostatesAPSSanAndres029":
                   sld = CharacterFromID("Apostates_iroquois");
                   sld.dialog.filename = "Gothic_Quest\Apostates\npc.c";
                   sld.dialog.currentnode   = "iroquois";
                   LAi_SetImmortal(sld, false);
                   LAi_SetActorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   break;

                  case "GothicApostatesAPSBrachyura":
                  chrDisableReloadToLocation = true;
                  sld = CharacterFromID("Apostates_iroquois");
                  LAi_SetActorType(sld);
                  LAi_ActorGoToLocation(sld, "reload", "reload2_back", "none", "", "", "GothicApostatesAPSBrachyura_1", -1);
                   break;

	case "GothicApostatesAPSBrachyura_1":
                     chrDisableReloadToLocation = false;
	//AddQuestRecord("APS", "36");
	Island_SetReloadEnableGlobal("Beliz", false);//закрыть остров
	bQuestDisableMapEnter = true;//на карту тоже

	iRank = 13+MOD_SKILL_ENEMY_RATE/2;
	Group_FindOrCreateGroup("FrFlorensio");
	Group_SetType("FrFlorensio", "pirate");//тип группы
	//sld = GetCharacter(NPC_GenerateCharacter("FlorensioCap", "mercen_"+(rand(10)+1), "man", "man", iRank, PIRATE, -1, false, "quest"));
	sld = characterFromId("FlorensioCap");
	FantomMakeSmallSailor(sld, SHIP_FRIGATE_H, "Сантиссима Мадре", CANNON_TYPE_CANNON_LBS20, 40+rand(10), 30+rand(20), 30+rand(20), 30+rand(15), 25+rand(25));
	FantomMakeCoolFighter(sld, iRank, 60, 60, "topor_04", "pistol1", "bullet", 100); // приз - секира 090912
	sld.name = "Галиндо";
	sld.lastname = "Ольмос";
	sld.DontRansackCaptain = true; 
	sld.AnalizeShips = true;
	sld.Alwaysenemy = true; // 260912
	sld.Coastal_Captain = true;
	sld.Ship.Mode = "pirate";
	Character_SetAbordageEnable(sld, true);//можно абордировать
	sld.mapEnc.type = "war";

                     SetRandGeraldSail(sld, PIRATE);
	sld.AlwaysSandbankManeuver = true;
	SetCharacterPerk(sld, "MusketsShoot");
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 3;

	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	GiveItem2Character(sld, "sand_clock");
	LAi_SetCharacterUseBullet(sld, "bullet");
                     TakeNItems(sld, "grapeshot", 4);
	TakeNItems(sld, "bullet", 6);
	TakeNItems(sld, "cartridge", 5);
	TakeNItems(sld, "GunPowder", 12);
	GiveItem2Character(sld, "spyglass3");

	Group_AddCharacter("FrFlorensio", "FlorensioCap");			
                    Group_SetGroupCommander("FrFlorensio", "FlorensioCap");
	Group_SetTaskAttack("FrFlorensio", PLAYER_GROUP);
	Group_SetPursuitGroup("FrFlorensio", PLAYER_GROUP);
	Group_SetAddress("FrFlorensio", "Beliz", "quest_ships", "Quest_ship_9");
	Group_LockTask("FrFlorensio");

	pchar.quest.FrFlorensio_fail.win_condition.l1 = "NPC_Death";
	pchar.quest.FrFlorensio_fail.win_condition.l1.character = "FlorensioCap";
	pchar.quest.FrFlorensio_fail.function = "FrFlorensio_failed";
	break;

                    case "GothicApostatesAPSBrachyura_2":
                    chrDisableReloadToLocation = false;
	pchar.quest.GothicgoldItza.over = "yes";
                     pchar.GenQuestBox.Iroquois_Cave.box1.items.gold_Itza = 60606;
	pchar.quest.GothicAPSgold_1.win_condition.l1 = "item";
	pchar.quest.GothicAPSgold_1.win_condition.l1.item = "gold_Itza";
	pchar.quest.GothicAPSgold_1.function = "GothicApostatesAPS_goldItza";
                     break;
	
	case "GothicApostatesAPS_Providence_3":	//третья постройка
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_210";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");
	n = FindLocation("SanAndres_town_2");
	locations[n].reload.l2.name = "reload_1_4_back";
	locations[n].reload.l2.go = "SanAndres_town_4";
	locations[n].reload.l2.emerge = "reload_4_1_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "reload_1_3_back";
	locations[n].reload.l3.go = "SanAndres_town_3";
	locations[n].reload.l3.emerge = "reload_3_1_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	locations[n].reload.l5.name = "reload_2_4_back";
	locations[n].reload.l5.go = "SanAndres_town_4";
	locations[n].reload.l5.emerge = "reload_4_2_back";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "SanAndres Port";

	n = FindLocation("SanAndres_town_3");
	locations[n].reload.l1.name = "reload_3_1_back";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload_1_3_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload_3_2_back";
	locations[n].reload.l2.go = "SanAndres_town_4";
	locations[n].reload.l2.emerge = "reload_4_2_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "reload_3_2";
	locations[n].reload.l3.go = "SanAndres_town_2";
	locations[n].reload.l3.emerge = "reload_2_3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	locations[n].reload.l4.name = "gate1_back";
	locations[n].reload.l4.go = "SanAndres_ExitTown_1";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "ExitTown";

	n = FindLocation("SanAndres_town_4");
	locations[n].reload.l1.name = "reload_4_1_back";
	locations[n].reload.l1.go = "SanAndres_town_2";
	locations[n].reload.l1.emerge = "reload_1_4_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "SanAndres Port";

	locations[n].reload.l2.name = "reload_4_2_back";
	locations[n].reload.l2.go = "SanAndres_town_2";
	locations[n].reload.l2.emerge = "reload_2_4_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "SanAndres Port";

	locations[n].reload.l3.name = "gate2_back";
	locations[n].reload.l3.go = "SanAndres_ExitTown_2";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "SanAndres Port";

	n = FindLocation("Providence_Jungle_01");
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "SanAndres_ExitTown_2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "ExitTown";
	locations[n].locators_radius.reload.reload1_back = 2;

	break;

                   case "GothicApostatesAPSMaryCeleste6":
                   chrDisableReloadToLocation = false;
                   sld = characterFromId("SofiBrics");
                   LAi_SetActorType(sld);
                   LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "GothicApostatesAPSMaryCeleste7", -1);
                   break;

                   case "GothicApostatesAPSMaryCeleste7":
                   AddQuestRecord("APSMaryCeleste", "3");
                   bDisableCharacterMenu = false;//разлочим F2
                   sld = characterFromId("SofiBrics");
                   LAi_SetStayType(sld);
                   AddPassenger(pchar, sld, false);
                   SetCharacterRemovable(sld, false);

	pchar.quest.GothicApostatesAPS_13.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_13.win_condition.l1.location = "SanAndres_TownhallRoom";
                     pchar.quest.GothicApostatesAPS_13.win_condition.l1.locator_group = "reload";
	pchar.quest.GothicApostatesAPS_13.win_condition.l1.locator = "reload1";
	pchar.quest.GothicApostatesAPS_13.win_condition = "GothicApostatesAPSMaryCeleste8";
                   break;

                    case "GothicApostatesAPSMaryCeleste8":
	sld = CharacterFromID("SofiBrics");
	RemovePassenger(pchar, sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "goto", "goto3");
	LAi_SetActorType(sld);
                     sld = characterFromID("ApostatesRK");
                     sld.Dialog.FileName = "Gothic_Quest\Apostates\npc.c";
	sld.Dialog.CurrentNode = "second_228";
	LAi_SetImmortal(sld, true);
	LAi_LoginInCaptureTown(sld, false);
	LAi_SetSitType(sld);
	ChangeCharacterAddressGroup(sld, "SanAndres_TownhallRoom", "sit", "sit1");
                     break;


	}
}