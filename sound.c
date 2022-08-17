// DEFINES
#define MUSIC_CHANGE_TIME  3000
#define MUSIC_SILENCE_TIME 180000.0
#define SOUNDS_FADE_TIME   200

#event_handler ("LoadSceneSound", "LoadSceneSound")
// PLAY
int Play3DSound(string name, float x, float y, float z)
{
	InitSound();
	//Trace("Play3DSound : "+name);
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, false, 0, x, y, z);
}

int Play3DSoundCached(string name, float x, float y, float z)
{
	InitSound();
	//Trace("Play3DSoundCached : "+name);
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, false, true, 0, x, y, z);
}

int Play3DSoundComplex(string name, float x, float y, float z, bool bLooped, bool bCached)
{
	InitSound();
	return SendMessage(Sound,"lsllllllfff",MSG_SOUND_PLAY, name, SOUND_WAV_3D, VOLUME_FX, false, bLooped, bCached, 0, x, y, z);
}

int PlayStereoSound(string name)
{
	InitSound();
	//Trace("PlayStereoSound : "+name);
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, false, false, false);
}

int PlayStereoSoundLooped(string name)
{
	InitSound();
	//Trace("PlayStereoSoundLooped : "+name);
	return SendMessage(Sound,"lsllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, false, true, false);
}

int PlayStereoSoundLooped_JustCache(string name)
{
	InitSound();
	//Trace("PlayStereoSoundLooped : "+name);
	return SendMessage(Sound,"lslllll",MSG_SOUND_PLAY, name, SOUND_WAV_STEREO, VOLUME_FX, true, true, false);
}

int PlayStereoOGG(string name)
{
	InitSound();
	//Trace("PlayStereoSound : "+name);
	return SendMessage(Sound,"lsllllll",MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_FX, false, false, false, 0); //fix boal
}

// OTHER METHODS
void StopSound(int id, int fade)
{
	InitSound();
	//Trace("StopSound : "+id);
	SendMessage(Sound, "lll", MSG_SOUND_STOP, id, fade);
}

void ResumeSound(int id, int fade)
{
	InitSound();
	//Trace("ResumeSound : "+id);
	SendMessage(Sound, "lll", MSG_SOUND_RESUME, id, fade);
}

void ReleaseSound(int id)
{
	InitSound();
	//Trace("ReleaseSound : "+id);
	SendMessage(Sound, "ll", MSG_SOUND_RELEASE, id);
}

// SOUND SCHEMES
void ResetSoundScheme()
{
	InitSound();
	//Trace("ResetSoundScheme");
	SendMessage(Sound,"l",MSG_SOUND_SCHEME_RESET);
}

void SetSoundScheme(string schemeName)
{
	InitSound();
	//Trace("SetSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_SET,schemeName);
}

void AddSoundScheme(string schemeName)
{
	InitSound();
	//Trace("AddSoundScheme: "+schemeName);
	SendMessage(Sound,"ls",MSG_SOUND_SCHEME_ADD,schemeName);
}

/* ����� ��� ������� ���������� �������� ����� � ���� �� ����!. ������ �����������
��� ������, ��� � �����. ������� ��� ����, ��� �� �� ���� ����, �������
�� �������� ���������� �� ������ ��� �������, ��� ��� ��-���� ��������
� ������������� */

void SetWeatherScheme(string scheme)
{
	if (Whr_IsStorm())
	{
		if (Whr_IsNight())
		{
			SetSoundScheme(scheme+"_night_storm");
		}
		else
		{
			SetSoundScheme(scheme+"_day_storm");
		}
	}
	else 
	{ 
		if (Whr_IsRain())
		{
			if (Whr_IsNight())
			{
					SetSoundScheme(scheme+"_night_rain");
			}
			else
			{
					SetSoundScheme(scheme+"_day_rain");
			}					
		}
		else
		{
			if (Whr_IsNight())
			{
					SetSoundScheme(scheme+"_night");
			}
			else
			{
					SetSoundScheme(scheme+"_day");
			}
		}
	}
}

/* void SetTimeScheme(string scheme)
{
	if (Whr_IsNight())
	{
		AddSoundScheme(scheme+"_night");
	}
	else
	{
		AddSoundScheme(scheme+"_day");
	}
}
*/
void SetSchemeForLocation (ref loc)
{
    ref mchref = GetMainCharacter();
    mchref.GenQuest.God_hit_us = false; // ����� �������� :)  (������ � �����)
    int iColony = -1; //boal music
    
    if(CheckAttribute(loc,"type"))
	{
		ResetSoundScheme();
		SetMusicAlarm(""); // ������ �� ������, ���� ���������� ��� ��������� ����� ����� - �����x boal 28.06.06
		switch (loc.type)
		{
			case "town":
				SetWeatherScheme("town");
				if (CheckAttribute(loc,"QuestCapture"))
				{
					SetMusicAlarm("music_military");
				}
				if (CheckAttribute(loc,"fastreload"))
				{
					iColony = FindColony(loc.fastreload);
				}
				if (iColony != -1)
				{
					if (CheckAttribute(loc,"QuestCapture")) SetMusicAlarm("music_military");
					else 
				{
					if (Whr_IsDay()) SetMusicAlarm(NationShortName(sti(Colonies[iColony].nation)) + "_music_day");
					else SetMusicAlarm(NationShortName(sti(Colonies[iColony].nation)) + "_music_night");
				}
				}
				else
				{
					SetMusicAlarm("music_gorod");
				}
			break;
			
			case "land": // �������� ����, �������� � ��� �����
				SetWeatherScheme("land");
				SetMusicAlarm("music_jungle");
			break;
			
			case "jungle":
				SetWeatherScheme("land");
				if (loc.id.label == "Village" || loc.id.label == "ExitTown" || loc.id.label == "Incas Temple")
				{
					switch (loc.id.label)
					{
						case "ExitTown":
							if (Whr_IsDay()) SetMusicAlarm("music_exittown");
							else SetMusicAlarm("music_nightjungle");
						break;
						case "Incas Temple":
							SetMusicAlarm("music_Incas_Temple");
						break;
						case "Village":
							SetMusicAlarm("music_village");
						break;
					}
				}
				else
				{
					if (Whr_IsDay()) SetMusicAlarm("music_jungle");
					else SetMusicAlarm("music_nightjungle");
				}
				DeleteAttribute(pchar, "CheckStateOk"); // ������ ���� ������������� �����������
			break;
			
			case "mayak":
				ResetSoundScheme();
				SetWeatherScheme("seashore");
				SetMusicAlarm("music_mayak");
			break;
			
			case "seashore": 
				ResetSoundScheme();
				SetWeatherScheme("seashore");
				SetMusicAlarm("music_shore");
				DeleteAttribute(pchar, "CheckStateOk"); // ������ ���� ������������� �����������
			break;
			
			case "cave": 
				SetSoundScheme("cave");
				SetMusicAlarm("music_cave");
				bMonstersGen = false; //�������� ���� ��������
			break;
			
			case "dungeon": 
				SetSoundScheme("dungeon");
				SetMusicAlarm("music_cave");
				bMonstersGen = false; //�������� ���� ��������
			break;
			
			case "reef":
				ResetSoundScheme();
				SetSoundScheme("reef");
				SetMusicAlarm("music_reef");
			break;
			
			case "mine":
				ResetSoundScheme();
				SetSoundScheme("mine");
				SetMusicAlarm("music_cave");
			break;
			
			case "inca_temple": // �� ������������
				SetSoundScheme("inca_temple");
				SetMusicAlarm("music_coridor");
			break;
			
			case "x_seashore":
				ResetSoundScheme();
				SetWeatherScheme("seashore");
				SetMusicAlarm("music_teno");
			break;
			
			case "x_jungle":
				ResetSoundScheme();
				SetWeatherScheme("land");
				SetMusicAlarm("music_teno");
			break;
			
			case "questisland":
				ResetSoundScheme();
				if (loc.id.label == "jungle") SetWeatherScheme("land");
				else SetWeatherScheme("seashore");
				SetMusicAlarm("music_questislands");
			break;
			
			case "plantation":
				ResetSoundScheme();
				SetWeatherScheme("land");
				SetMusicAlarm("music_plantation");
			break;
			
			case "house":
				SetSoundScheme("house");
				if (CheckAttribute(loc,"brothel") && sti(loc.brothel) == true)
				{
					SetMusicAlarm("music_brothel");
				}
				else
				{
					if (CheckAttribute(loc,"id.label") && loc.id.label == "portoffice")
					{
						SetMusicAlarm("music_portoffice");
					}
					else
					{
						SetMusicAlarm("music_gorod");
					}
				}
				mchref.GenQuest.God_hit_us = true; // ����� �������� :)
			break;
			
			case "tavern":
				SetSoundScheme("tavern");
				if (CheckAttribute(loc,"fastreload"))
				{
					iColony = FindColony(loc.fastreload);
				}
				if (iColony != -1)
				{
			    	SetMusicAlarm(NationShortName(sti(Colonies[iColony].nation)) + "_music_tavern");
				}
				else
				{
					SetMusicAlarm("music_tavern");
				}
			break;
			
			case "shop":
				SetSoundScheme("shop");
				if (CheckAttribute(loc,"id.label") && loc.id.label == "Usurer House")
				{
					SetMusicAlarm("music_bank");
				}
				else
				{
					SetMusicAlarm("music_shop");
				}
			break;
			
			case "residence":
				SetSoundScheme("residence");
				if (CheckAttribute(loc,"fastreload"))   // boal
				{
					iColony = FindColony(loc.fastreload);
				}
				if (iColony != -1)
				{
			    	SetMusicAlarm(NationShortName(sti(Colonies[iColony].nation)) + "_music_gubernator");
				}
				else
				{
					SetMusicAlarm("music_deck");
				}
			break;
			
			case "church":
				if (isDay()) SetSoundScheme("church");
				if (CheckAttribute(loc,"fastreload"))
				{
					iColony = FindColony(loc.fastreload);
				}
				if (iColony != -1)
				{
			    	SetMusicAlarm(NationShortName(sti(Colonies[iColony].nation)) + "_music_church");
				}
				else
				{
				SetMusicAlarm("music_church");
				}
			break;
			
			case "shipyard":
				SetSoundScheme("shipyard");
				SetMusicAlarm("music_shipyard");
                                                                PlaySound("Interface\DOOR_CLOSE02B.wav");
			break;
			
			case "fort_attack": // ������� ����, ���������� �������			
				SetSoundScheme("fort_attack");
				SetMusicAlarm("music_bitva");
			break;
			
			case "fort": // ���� ��� ������ ��������
				SetWeatherScheme("seashore");
				if (CheckAttribute(loc, "parent_colony"))
				{
					iColony = FindColony(loc.parent_colony);
				}
				if (iColony != -1)
				{
					if (CheckAttribute(loc,"QuestCapture")) SetMusicAlarm("music_military");
					else SetMusicAlarm("music_fort");
				}
				else
				{
					SetMusicAlarm("music_gorod");
				}
			break;
			
			case "deck": // ������ ������
				SetSoundScheme("deck");
				if (Whr_IsDay()) SetMusic("music_sea_day");
				else SetMusic("music_sea_night");
			break;
			
			case "deck_fight": // ������ ������
				SetSoundScheme("deck_fight");
				SetMusic("music_abordage");
			break;
			
			case "slave_deck": // ��������� ������
				SetSoundScheme("slave_deck");
				//SetMusicAlarm("music_spokplavanie");
			break;
			
			case "boarding_cabine":
				SetSoundScheme("cabine");
				SetMusic("music_abordage");
			break;
			
			case "sailing_cabine":
				SetSoundScheme("sail_cabine");
				if (Whr_IsDay()) SetMusicAlarm("music_sea_day");
				else SetMusicAlarm("music_sea_night");
			break;
			
			case "incquisitio":
				SetSoundScheme("incquisitio");
				SetMusicAlarm("music_incquisitio");
			break;
			
			case "jail":
				SetSoundScheme("jail");
				SetMusicAlarm("music_jail");
			break;
			
			case "ammo":
				SetSoundScheme("jail");
				SetMusicAlarm("music_jail");
			break;
			
			case "LostShipsCity":
				SetWeatherScheme("LostShipsCity");
				SetMusicAlarm("music_LostShipsCity");
			break;
			
			case "LSC_inside":
				SetWeatherScheme("LSC_inside");
				SetMusicAlarm("music_LostShipsCity");
			break;

			case "LostShipsCityy":
				SetWeatherScheme("LostShipsCityy");
				SetMusicAlarm("music_LostShipsCityy");
			break;
			
			case "LSC�_insidee":
				SetWeatherScheme("LSC�_insidee");
				SetMusicAlarm("music_LostShipsCityy");
			break;

			case "underwater":
				SetSoundScheme("underwater");
				SetMusicAlarm("music_underwater");
			break;

			case "underwaterr":
				SetSoundScheme("underwaterr");
				SetMusicAlarm("music_underwaterr");
			break;
			
			case "teno":
				SetWeatherScheme("land");
				SetMusicAlarm("music_teno");
			break;

			case "Tieyasal":
				SetWeatherScheme("land");
				SetMusicAlarm("music_Tieyasal");
			break;
			
			case "teno_inside":
				SetSoundScheme("teno_inside");
				SetMusicAlarm("music_teno_inside");
			break;

		                        case "Tenotchitlan":
			                        SetWeatherScheme("land");
			                        SetMusicAlarm("music_tenotchitlan");
			break;

			case "Tenotchitlan_1":
				SetWeatherScheme("land");
				SetMusicAlarm("music_tenotchitlan_1");
			break;

		                        case "tenotchitlan_inside":
			                       SetSoundScheme("tenotchitlan_inside");
			                       SetMusicAlarm("music_tenotchitlan_inside");
			break;

		                        case "Temple":
			                    SetSoundScheme("Incas_inside");
			                    SetMusicAlarm("music_Incas_Temple");
			break;
			
			case "Alcove": // �������
				SetSoundScheme("teno_inside");
				SetMusicAlarm("music_alcove");
			break;
			
			case "Alcovee":
				SetSoundScheme("teno_inside");
				SetMusicAlarm("music_alcovee");
			break;

			case "Alcove_2":
				SetWeatherScheme("teno_inside");
				SetMusicAlarm("music_alcove_2");
			break;

			case "Judgement_dungeon": // Addon 2016-1 Jason ��������� �������
				SetSoundScheme("dungeon");
				SetMusicAlarm("music_alcove");
			break;
			
			case "Judgement_hell_dungeon": 
				SetSoundScheme("dungeon");
				if (loc.id == "Judgement_dungeon_10") SetMusicAlarm("music_retribution_1");
				else SetMusicAlarm("music_retribution");
			break;


		case "crypt": 
			SetSoundScheme("crypt");
			SetMusicAlarm("music_crypt");
			break;
		case "Malta": 
			SetSoundScheme("Malta");
			SetMusicAlarm("music_Malta");
			break;
		case "Maltinis": 
			SetSoundScheme("Maltinis");
			SetMusicAlarm("music_Maltinis");
			break;
		case "house":
			SetSoundScheme("house");
			if (CheckAttribute(loc,"brothel") && sti(loc.brothel) == true)  // 1.2.3
			{
			    SetMusicAlarm("music_brothel");
			}
			else
			{
			    SetMusicAlarm("music_gorod");
			}
			mchref.GenQuest.God_hit_us = true; // ����� �������� :)
			break;

		case "house_Gotika":
			SetSoundScheme("house_Gotika");
			if (CheckAttribute(loc,"brothel") && sti(loc.brothel) == true)  // 1.2.3
			{
			    SetMusicAlarm("music_romantic_tavern");
			}
			else
			{
			    SetMusicAlarm("music_Gotika");
			}
			mchref.GenQuest.God_hit_us = true; // ����� �������� :)
			break;
		case "Blufeld":
			SetSoundScheme("music_Gotika");
			 SetMusicAlarm("music_Gotika");
			break;
		case "Villa":
			SetSoundScheme("music_brothel");
			 SetMusicAlarm("music_brothel");
			break;
		case "SantLous":
			SetSoundScheme("exit_town");
			SetMusicAlarm("music_exittown");
			break;
		case "PortAntonio": 
			SetSoundScheme("PortAntonio_Town");
			SetMusicAlarm("music_PortAntonio");
			break;
		case "Gothic":
			SetSoundScheme("Gothic_town");
			SetMusicAlarm("music_Gothic");
			break;
		case "Gothic_church":
			SetSoundScheme("Gothic_town");
			SetMusicAlarm("music_Gothic_church");
			break;
		case "Ruins":
			SetSoundScheme("Gothic_Ruins");
			SetMusicAlarm("music_Gothic_Ruins");
			break;
		case "Xsardas":
			SetSoundScheme("Xsardas_Dungeon");
			SetMusicAlarm("music_Xsardas");
			break;
		case "Mines":
			SetSoundScheme("minentown_mine");
			SetMusicAlarm("music_mine");
			break;
		case "Village":
			SetSoundScheme("Incas_Village");
			SetMusicAlarm("music_Incas_Village");
			break;
		case "cabine":
			SetSoundScheme("residence_cabine");
			SetMusicAlarm("music_residence_cabine");
			break;
		case "deck":
			SetSoundScheme("Ship_deck");
			SetMusicAlarm("music_Ship_deck");
			break;
		case "Hold":
			SetSoundScheme("Ship_Hold");
			SetMusicAlarm("music_Ship_Hold");
			break;
		case "Cannon":
			SetSoundScheme("Ship_Cannon");
			SetMusicAlarm("music_Ship_Cannon");
			break;
		case "exittown": 
			SetSoundScheme("exit_town");
			SetMusicAlarm("music_exittown");
			break;
		case "Port": 
			SetSoundScheme("Port_town");
			SetMusicAlarm("music_Port");
			break;
		case "SantLous": 
			SetSoundScheme("SantLous_town");
			SetMusicAlarm("music_SantLous");
			break;
		case "cave_Gotika": 
			SetSoundScheme("cave");
			SetMusicAlarm("music_cave_Gotika");
			bMonstersGen = false; //�������� ���� ��������
			break;
		case "terrain":
			SetSoundScheme("terrain");
			SetMusicAlarm("music_terrain");
			break;
		case "Gothic_terrain":
			SetSoundScheme("Gothic_terrain");
			SetMusicAlarm("music_Gothic_terrain");
			break;
		case "SEA_SONGS":
			SetSoundScheme("SEA_SONGS");
			SetMusicAlarm("music_SEA_SONGS");
			break;
		}
	}
	SetStaticSounds(loc);
}

void SetStaticSounds (ref loc)
{
	if(IsEntity(loc) != true) return;
	string locatorGroupName = "locators.sound";
	if(CheckAttribute(loadedLocation, locatorGroupName) == 0) return;
	aref locatorGroup;
	makearef(locatorGroup, loc.(locatorGroupName));
	int locatorCount = GetAttributesNum(locatorGroup);
	if(locatorCount <= 0) return;
	string locatorName, locatorType;
	int locatorNameLength;

	for(int i = 0; i < locatorCount; i++)
	{
		aref locator = GetAttributeN(locatorGroup, i);
		locatorName = GetAttributeName(locator);
		locatorNameLength = strlen(locatorName);
		locatorType = strcut(locatorName, 0, locatorNameLength-3);
		if ((locatorType == "nightinsects")||(locatorType == "torch"))
		{
			if (Whr_IsDay() && loc.type != "Dungeon" && loc.type != "cave" && loc.type != "fort_attack") continue;
   		}
		if (locatorType == "shipyard")
		{
			if (Whr_IsNight()) continue;
   		}
		if (locatorType == "church")
		{
			if (Whr_IsNight()) continue;
   		}
		if (locatorType == "windmill")
		{
			continue;
   		}

		//trace("Create 3D Sound <"+locatorType+ "> for locator <"+locatorName+ "> into pos:("+locator.x+","+locator.y+","+locator.z+")" );
		SendMessage(Sound, "lsllllllfff", MSG_SOUND_PLAY, locatorType, SOUND_WAV_3D, VOLUME_FX, 0, 1, 0, 0, stf(locator.x), stf(locator.y), stf(locator.z));
	}
	
}

void SetSchemeForSea ()
{
	ResetSoundScheme();

	// AddSoundScheme("sea");
	if (Whr_IsNight())
	{
		if (Whr_IsStorm())
		{
			AddSoundScheme("sea_night_storm");
			SetMusic("music_storm");
		}
		else 
		{ 
			if (pchar.Ship.POS.Mode == SHIP_WAR)
			{
				SetMusic("music_sea_battle");
			}
			else
			{
				if (Whr_IsDay()) SetMusic("music_sea_day");
				else SetMusic("music_sea_night");
			}
			if (Whr_IsRain())
			{
				AddSoundScheme("sea_night_rain");
			}
			else
			{
				AddSoundScheme("sea_night");
			}
		}
	}
	else // if Whr_IsDay
	{
		if (Whr_IsStorm())
		{
			AddSoundScheme("sea_day_storm");
			SetMusic("music_storm");
		}
		else 
		{ 
   			if (pchar.Ship.POS.Mode == SHIP_WAR)
			{
				SetMusic("music_sea_battle");
			}
			else
			{
				if (Whr_IsDay()) SetMusic("music_sea_day");
				else SetMusic("music_sea_night");
			}
			if (Whr_IsRain())
			{
				AddSoundScheme("sea_day_rain");
			}
			else
			{
				AddSoundScheme("sea_day");
			}
		}
	}
	ResumeAllSounds();
}

void SetSchemeForMap ()
{
	ResetSoundScheme();
	AddSoundScheme("sea_map");
	SetMusic("music_map");
	ResumeAllSounds();
	bFortCheckFlagYet = false; //eddy. ������ ���� ������������� ������ �����
}

// MUSIC
int musicID = -1;
int oldMusicID = -1;
int boardM = -1;
string musicName = "";
string oldMusicName = "";
void SetMusic(string name)
{
	if (pchar.location == "UnderWater") return; //�� ������ ����� ��� �����
	InitSound();
	//Trace("SETTING MUSIC: " + name);

	if (name == musicName)
	{
		SendMessage(Sound, "lll", MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
		return;
	}

	//Trace("SetMusic : "+name);
	if (oldMusicID >= 0)
	{
		SendMessage(Sound, "ll", MSG_SOUND_RELEASE, oldMusicID);
		oldMusicID = -1;
	}

	if (musicID >= 0)
	{
		SendMessage(Sound, "lll", MSG_SOUND_STOP, musicID, MUSIC_CHANGE_TIME);
		oldMusicID = musicID;
	}

	//int silenceTime = 20000 + MakeInt(frnd() * MUSIC_SILENCE_TIME);
	//musicID = SendMessage(Sound, "lslllllll", MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_MUSIC, true, true, false, MUSIC_CHANGE_TIME, silenceTime);
	//SendMessage(Sound, "llf", MSG_SOUND_SET_VOLUME, musicID, 1.0);
	// fix �������� - ��� ��������� �����
	musicID = SendMessage(Sound, "lslllllllf", MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_MUSIC, true, true, false, 0, MUSIC_CHANGE_TIME, 1.0);
	SendMessage(Sound, "lll", MSG_SOUND_RESUME, musicID, MUSIC_CHANGE_TIME);
	
	oldMusicName = musicName;
	musicName = name;
}

// Jason ����������� ���������� ����� dlc
void SetMusicOnce(string name)
{
	if (pchar.location == "UnderWater") return; //�� ������ ����� ��� �����
	InitSound();
	
	if (name == musicName)
	{
		SendMessage(Sound, "lll", MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
		return;
	}

	if (oldMusicID >= 0)
	{
		SendMessage(Sound, "ll", MSG_SOUND_RELEASE, oldMusicID);
		oldMusicID = -1;
	}

	if (musicID >= 0)
	{
		SendMessage(Sound, "lll", MSG_SOUND_STOP, musicID, MUSIC_CHANGE_TIME);
		oldMusicID = musicID;
	}
	musicID = SendMessage(Sound, "lslllllllf", MSG_SOUND_PLAY, name, SOUND_MP3_STEREO, VOLUME_MUSIC, false, false, false, 0, MUSIC_CHANGE_TIME, 1.0);
	SendMessage(Sound, "lll", MSG_SOUND_RESUME, musicID, MUSIC_CHANGE_TIME);
	
	oldMusicName = musicName;
	musicName = name;
}

void FadeOutMusic(int _time)
{
	if (musicID >= 0)
	{
		StopSound(musicID, _time);
		musicID = -1;
		musicName = "";
	}
}

// RELOAD
void PauseAllSounds()
{
	//Trace("PauseAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_STOP, 0, SOUNDS_FADE_TIME);
}

void ResumeAllSounds()
{
	//Trace("ResumeAllSounds");
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, SOUNDS_FADE_TIME);
}

// OLD VERSIONS
int PlaySoundDist3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

int PlaySoundLoc3D(string name, float x, float y, float z)
{
	return Play3DSoundCached(name, x,y,z);
}

int PlaySound3D(string name, float x, float y, float z)
{
	return Play3DSound(name, x,y,z);
}

void Sound_SetVolume(int iSoundID, float fVolume)
{
	SendMessage(Sound, "llf", MSG_SOUND_SET_VOLUME, iSoundID, fVolume);
}

int PlaySound(string name)
{
	return PlayStereoSound(name);
}

int PlaySoundComplex(string sSoundName, bool bSimpleCache, bool bLooped, bool bCached, int iFadeTime)
{
	return SendMessage(Sound,"lsllllll",MSG_SOUND_PLAY,VOLUME_FX,sSoundName,SOUND_WAV_3D,bSimpleCache,bLooped,bCached,iFadeTime);
}

void StopMusic()
{
}

void PlayMusic(string n)
{
}
//--------------------------------------------------------------------
// Sound Section
//--------------------------------------------------------------------
object Sound;

int alarmed = 0;
int oldAlarmed = 0;
bool seaAlarmed = false;
bool oldSeaAlarmed = false;
void SetMusicAlarm(string name)
{
	if (alarmed == 0)
	{
		SetMusic(name);
	}
	else
	{
  		if (loadedLocation.type == "x_jungle" || loadedLocation.type == "x_seashore" || loadedLocation.id.label == "Maze") SetMusic("music_teno"); // �������
		else
		{
			if (loadedLocation.id.label == "Alcove")
			{
				if (loadedLocation.type == "Alcove") SetMusic("music_alcove");
				else SetMusic("music_alcove_1");
			}
		else
		{
			if (loadedLocation.id == "shore67" || loadedLocation.id == "IslaDeVieques_HouseEntrance" || loadedLocation.id == "Shore_mask") SetMusic("music_q_battle");
		else
		{
  		SetMusic("music_bitva");
		if (LAi_boarding_process != 0)
		{
			if (!CheckAttribute(loadedLocation, "CabinType"))
			{
				boardM = 1; // ����� ������� ���� � �����
			}
		}
	}
}
}
}
}

void Sound_OnAllarm()
{
	Sound_OnAlarm(GetEventData());
}

int abordageSoundID;

void Sound_OnAlarm(bool _alarmed)
{
	alarmed = _alarmed;
	if (alarmed == oldAlarmed)
		return;

	if (alarmed != 0)
	{ //alarm on!
		if (loadedLocation.id == "shore67") SetMusic("music_q_battle");
		else SetMusic("music_bitva");
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldAlarmed = alarmed;
}

void Sound_OnSeaAlarm(bool _seaAlarmed)
{
	seaAlarmed = _seaAlarmed;
	if (seaAlarmed == oldSeaAlarmed)
		return;

	if (seaAlarmed)
	{ //alarm on!
		SetMusic("music_sea_battle");
	}
	else
	{ //alarm off
		SetMusic(oldMusicName);
	}
	oldSeaAlarmed = seaAlarmed;
}

// set music without any checks
void Sound_OnSeaAlarm555(bool _seaAlarmed, bool bHardAlarm)
{
	if (bHardAlarm) { oldSeaAlarmed = !_seaAlarmed; }
	
	Sound_OnSeaAlarm(_seaAlarmed);
}

void InitSound()
{
	//Trace("InitSound");
	if (!IsEntity(&Sound))
	{
		CreateEntity(&Sound, "Sound");
		SetEventHandler("eventAllarm", "Sound_OnAllarm", 0);
	}
	//SendMessage(Sound,"lf",MSG_SOUND_SET_MASTER_VOLUME,1.0);
}

void ResetSound()
{
	// fix -->
	if (musicID > 0)
	{
		StopSound(musicID,0);
	}
	if (oldMusicID > 0)
	{
		StopSound(oldMusicID,0);
	}
	ResetSoundScheme();
	// fix <--
	StopSound(0,0);
	ReleaseSound(0);
	musicName = "";
	oldMusicName = "";
	musicID = -1;    //fix boal �� ���� ������� ��
    oldMusicID = -1;
}

void LoadSceneSound()
{
	int i = FindLoadedLocation();
	if (i != -1)
	// Cheatsurfer -->
	// ������ � �������� ����� � �������� �� ������������. ������ �����, ��� ������� ���������� ������, ���� �� ������ �� ��������� �����. �����...
	{
		if (CheckAttribute(pchar, "CSM.JungleContinuousMusic"))
		{
			if (CheckAttribute(loadedLocation, "type") && loadedLocation.type == "jungle")
			{
				// ����������� ����� ���� ������ � ����������� ������� "Village" � "mines", �� � "Graveyard" ������� ����, �� ������.
				if (CheckAttribute(loadedLocation, "id.label") && loadedLocation.id.label != "Graveyard" && loadedLocation.id.label != "mines" && loadedLocation.id.label != "Village")
				{
					if (locations[reload_location_index].type != locations[reload_cur_location_index].type)
					{
						SetSchemeForLocation(&Locations[i]);
					}
					else
					{
						// ngMusicID > 0 = ���� ���������� �� ������� � ��������, �������� � seadogs.c, #f OnLoad()
						bool bX1 = (locations[reload_cur_location_index].id.label == "Village") || (locations[reload_cur_location_index].id.label == "Graveyard") || (locations[reload_cur_location_index].id.label == "mines");
						bool bX2 = (locations[reload_location_index].id.label == "jungle") || (locations[reload_location_index].type == "jungle");
						bool bX = bX1 && bX2;
						if (ngMusicID > 0 || bX)
						{
							SetSchemeForLocation(&Locations[i]);
							ngMusicID = 0;
						}
					}
				}
				else
				{
					SetSchemeForLocation(&Locations[i]);
				}
			}
			else
			{
				SetSchemeForLocation(&Locations[i]);
			}
		}
		else
		{
			SetSchemeForLocation(&Locations[i]);
		}
	}
	// Cheatsurfer <--
}