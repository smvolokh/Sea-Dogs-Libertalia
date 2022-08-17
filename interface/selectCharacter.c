// BOAL переделка для SLib 02.07.06
#define DEFAULT_NAME "Игра"
#define DEFAULT_PASS ""

bool isOkExit = false;
 int idLngFile = -1;
string sCharacterName;

bool g_bToolTipStarted = false;
int heroQty = 0;
string totalInfo;
string CurTable, CurRow, CurCol = 0;
int iSelected, iSelectedCol;
ref	nulChr;

int iBackPistol = -1;
int iBackPartition = -1;

void InitInterface(string iniName)
{
	SetMusic("music_select");
	nulChr = &NullCharacter;
	GameInterface.title = "titleCharacterSelect";
	GameInterface.faces.current = 1;
	
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetMainCharacterIndex(1);

	sCharacterName = pchar.id;

	SetNewGroupPicture("ENGLAND", "NATIONS", "England");
	SetNewGroupPicture("FRANCE", "NATIONS", "France");
	SetNewGroupPicture("SPAIN", "NATIONS", "Spain");
	SetNewGroupPicture("HOLLAND", "NATIONS", "Holland");
	SetNewGroupPicture("PIRATE", "NATIONS", "Pirate");
	
	SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"BLAZE", 5, 1);
	SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"FRANCE", 5, 1);

	GameInterface.PROFILE_NAME.str = DEFAULT_NAME;
	GameInterface.PROFILE_PASS.str = DEFAULT_PASS;
	
    LoadStartGameParam(); // boal
    MOD_EXP_RATE =  10; // задаем в начале игры (выбор, от 5 до 15, 10 - середина по умолчанию, 15 - медлено)
    GameInterface.nodes.EXP_SLIDE.value = 0.5;
    SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"EXP_SLIDE", 0, 0.5);
    
    if (startHeroType < 1) startHeroType = 1; // fix
    if (startHeroType > sti(GetNewMainCharacterParam("hero_qty"))) startHeroType = sti(GetNewMainCharacterParam("hero_qty")); // fix
    
	SetEventHandler("exitCancel", "exitCancel", 0);
	SetEventHandler("exitOk", "exitOk", 0);
	SetEventHandler("selectEngland", "selectEngland", 0);
	SetEventHandler("selectFrance", "selectFrance", 0);
	SetEventHandler("selectSpain", "selectSpain", 0);
	SetEventHandler("selectHolland", "selectHolland", 0);
	SetEventHandler("selectPirate", "selectPirate", 0);
	SetEventHandler("confirmChangeProfileName", "confirmChangeProfileName", 0);
	SetEventHandler("MouseRClickUP","HideInfo",0);
	SetEventHandler("ShowInfo","ShowInfo",0);

	SetEventHandler("noteOk","procNoteOk",0);

	SetEventHandler("frame","IProcessFrame",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);


	if (!CheckAttribute(&GameInterface, "SavePath"))
		GameInterface.SavePath = "SAVE";

	EI_CreateFrame("CHARACTER_BIG_PICTURE_BORDER",50,76,300,358); // tak from CHARACTER_BIG_PICTURE
    EI_CreateHLine("CHARACTER_BIG_PICTURE_BORDER", 54,107,296,1, 4);
		
    heroQty   = sti(GetNewMainCharacterParam("hero_qty"));
    
    if (!CheckAttribute(&NullCharacter, "HeroParam.HeroType") || !CheckAttribute(&NullCharacter, "HeroParam.nation"))
    {   // иначе уже загружен и выбран ГГ, смотрим настройки и идем обратно
		SetVariable(true);
	}
	else
	{
	    SetVariable(false);
	}
	TmpI_ShowLevelComplexity();
	SetByDefault();
	DisableEnable_CheckProcess();
}

void SetByDefault()
{
    CheckButton_SetState("CHECK_ENCOUNTERS", iEncountersRate, true);

	if (iArcadeSails == 1)// 1 0
    {
    	CheckButton_SetState("CHECK_ARCADESAIL", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_ARCADESAIL", 2, true);
    }
    if (bRechargePistolOnLine)// 1 0
    {
    	CheckButton_SetState("CHECK_PISTOL", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_PISTOL", 1, false);
    }
    if (bHardcoreGame)// 1 0
    {
    	CheckButton_SetState("CHECK_HARDCORE", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_HARDCORE", 1, false);
    }

	if (bSeaBattleSave)// 1 0
    {
    	CheckButton_SetState("CHECK_SEABATTLESAVE", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_SEABATTLESAVE", 1, false);
    }	
	
	if (bRains)// 1 0
    {
    	CheckButton_SetState("CHECK_RAINS", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_RAINS", 1, false);
    }		
	
	if (bPartitionSet)// 1 0
    {
    	CheckButton_SetState("CHECK_PARTITION", 1, true);
    }
    else
    {
        CheckButton_SetState("CHECK_PARTITION", 1, false);
    }
}

void IProcessFrame()
{
	if(GetCurrentNode() == "PROFILE_NAME")
	{
		if(!CheckAttribute(&characters[GetCharacterIndex(sCharacterName)], "profile.name"))
		{
			confirmChangeProfileName();
		}

		if(characters[GetCharacterIndex(sCharacterName)].profile.name!= GameInterface.PROFILE_NAME.str)
		{
			confirmChangeProfileName();
		}
	}
	///
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_ENCOUNTERS", 3, 1))
	{
		iEncountersRate = 1;
	}
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_ENCOUNTERS", 3, 2))
	{
		iEncountersRate = 2;
	}
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_ENCOUNTERS", 3, 3))
	{
		iEncountersRate = 3;
	}
	////
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_ARCADESAIL", 3, 1))
	{
		iArcadeSails = 1;
	}
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_ARCADESAIL", 3, 2))
	{
		iArcadeSails = 0;
	}
	///
 	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_PISTOL", 3, 1))
	{
		bRechargePistolOnLine = true;
	}
	else
	{
		bRechargePistolOnLine = false;
	}
	///
 	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_HARDCORE", 3, 1))
	{
		bHardcoreGame = true;
	}
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_SEABATTLESAVE", 3, 1))
	{
		bSeaBattleSave = true;
	}
	else
	{
		bSeaBattleSave = false;
	}		
	
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_RAINS", 3, 1))
	{
		bRains = true;
	}
	else
	{
		bRains = false;
	}		
	
	if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_PARTITION", 3, 1))	
	{
		bPartitionSet = true;
	}
	else
	{
		bHardcoreGame = false;
	}
}

void exitCancel()
{
	if( CheckAttribute(&InterfaceStates,"showGameMenuOnExit") && sti(InterfaceStates.showGameMenuOnExit) == true)
	{	
		isOkExit = true;
		IDoExit(RC_INTERFACE_LAUNCH_GAMEMENU, true);
		return;
	}
	IDoExit(RC_INTERFACE_CHARACTER_SELECT_EXIT, true);
	ReturnToMainMenu();
}

void exitOk()
{
	if( !IsCorrectProfileName() )
	{
		ShowNoteText(true);
		return;
	}

	confirmChangeProfileName();

	if (!ProfileExists())
	{
		CreateProfileFolders();

        isOkExit = true;
		IDoExit(RC_INTERFACE_CHARACTER_SELECT_EXIT, true);
	} 
	else 
	{

		ShowConfirmWindow(true);
	}
}

bool IsCorrectProfileName()
{
	int n,nLen;
	string str,sCurProfileName;

	sCurProfileName = GameInterface.PROFILE_NAME.str;
	nLen = strlen(sCurProfileName);
	if( nLen==0 ) {return false;}

	for( n=0; n<nLen; n++ )
	{
		str = GetSymbol(&sCurProfileName,n);
		if( str=="*" ) {return false;}
		if( str=="?" ) {return false;}
		if( str=="\" ) {return false;}
		if( str=="/" ) {return false;}
	}
	return true;
}

void ShowNoteText(bool bShow)
{
	if( bShow ) {
		XI_WindowDisable("MAIN_WINDOW", true);

		XI_WindowDisable("NOTE_WINDOW", false);
		XI_WindowShow("NOTE_WINDOW", true);

		SetCurrentNode("NOTE_WINDOW_OK");
	} else {
		XI_WindowDisable("MAIN_WINDOW", false);

		XI_WindowDisable("NOTE_WINDOW", true);
		XI_WindowShow("NOTE_WINDOW", false);

		SetCurrentNode("PROFILE_NAME");
	}
}

void procNoteOk()
{
	ShowNoteText(false);
}

void DisableEnable_CheckProcess() // ugeen 2016
{
	if (MOD_SKILL_ENEMY_RATE == 10)
	{
		if(SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_PISTOL", 3, 1)) // если перезарядка включена
		{
			iBackPistol = 1; // сохраняем предыдущее значение
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CHECK_PISTOL", 2, 1, 0 ); // отключаем
		}
		else
		{
			iBackPistol = 0; // сохраняем предыдущее значение
		}
		
		if(!SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE, "CHECK_PARTITION", 3, 1)) // если раздел добычи отключен
		{
			iBackPartition = 0; // сохраняем предыдущее значение
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CHECK_PARTITION", 2, 1, 1 ); // включаем
		}
		else
		{
			iBackPartition = 1; // сохраняем предыдущее значение
		}
	
		SetClickable("CHECK_PISTOL", false);
		SetClickable("CHECK_PARTITION", false);	
		
		Button_SetEnable("CHECK_PISTOL", false);
		Button_SetEnable("CHECK_PARTITION", false);	

				
	}
	else
	{
		if( iBackPistol > -1 ) // восстанавливаем предыдущее значение
		{
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CHECK_PISTOL", 2, 1, iBackPistol );
			iBackPistol = -1;
		}
		
		if( iBackPartition > -1 )
		{
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CHECK_PARTITION", 2, 1, iBackPartition );
			iBackPartition = -1;
		}
		
		SetClickable("CHECK_PISTOL", true);
		SetClickable("CHECK_PARTITION", true);

		Button_SetEnable("CHECK_PISTOL", true);
		Button_SetEnable("CHECK_PARTITION", true);	
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
        case "LEFTCHANGE_COMPLEX":
			if(comName=="click")
			{
				if (MOD_SKILL_ENEMY_RATE > 1)
				{
					MOD_SKILL_ENEMY_RATE -= 1;
				}
				TmpI_ShowLevelComplexity();
				DisableEnable_CheckProcess();
			}
		break;

		case "RIGHTCHANGE_COMPLEX":
			if(comName=="click")
			{
			    if (MOD_SKILL_ENEMY_RATE < 10)
			    {
	               MOD_SKILL_ENEMY_RATE += 1;
	            }
	            TmpI_ShowLevelComplexity();
				DisableEnable_CheckProcess();
			}
		break;
		
		case "CONFIRM_WINDOW_MB_YES":

			if (comName == "click" || comName == "activate")
			{
				//DeleteProfile();
				//exitOk();
				isOkExit = true;
				SaveStartGameParam(); // boal
				IDoExit(RC_INTERFACE_CHARACTER_SELECT_EXIT, true);
			}

			if (comName == "deactivate")
			{

				ShowConfirmWindow(false);
			}

			break;

		case "CONFIRM_WINDOW_MB_NO":

			if (comName == "click" || comName == "activate")
			{
				ShowConfirmWindow(false);
			}

			if (comName == "deactivate")
			{

				ShowConfirmWindow(false);
			}

			break;
			
		////////////////////////////////
		case "OK_BUTTON":
    		if(comName=="leftstep")
    		{
    		    ProcessCommandExecuteLeft();
    		}
    		if(comName=="rightstep")
    		{
                ProcessCommandExecuteRight();
    		}
    	break;
    	case "CANCEL_BUTTON":
    		if(comName=="leftstep")
    		{
    		    ProcessCommandExecuteLeft();
    		}
    		if(comName=="rightstep")
    		{
                ProcessCommandExecuteRight();
    		}
    	break;
    	case "SETUP_BUTTON":
    		if(comName=="activate" || comName=="click")
    		{
			//	 ProcessSetGameOptionsExit();
    		}
    		if(comName=="leftstep")
    		{
    		    ProcessCommandExecuteLeft();
    		}
    		if(comName=="rightstep")
    		{
                ProcessCommandExecuteRight();
    		}
    	break;
		case "LEFTCHANGE_CHARACTER":
    		if(comName=="click")
    		{
    		    ProcessCommandExecuteLeft();
    		}
    	break;

    	case "RIGHTCHANGE_CHARACTER":
    		if(comName=="click")
    		{
    		    ProcessCommandExecuteRight();
    		}
    	break;

    	case "LEFTCHANGE_TYPE":
    		if(comName=="click")
    		{
    		    ProcessCommandExecuteTypeLeft();
    		}
    	break;

    	case "RIGHTCHANGE_TYPE":
    		if(comName=="click")
    		{
    		    ProcessCommandExecuteTypeRight();
    		}
    	break;
    	
    	case "FACEPICT":
    		if(comName=="click")
    		{
          		totalInfo = GetConvertStr("hero_" + startHeroType, "HeroDescribe.txt");
				SetInfoText();
    		}
    	break;
	}

}

void ShowConfirmWindow(bool show)
{
	if (show)
	{
		SetCurrentNode("CONFIRM_WINDOW_MB_NO");

		XI_WindowDisable("MAIN_WINDOW", true);
		XI_WindowDisable("CONFIRM_WINDOW", false);
		XI_WindowShow("CONFIRM_WINDOW", true);
		EI_CreateFrame("CONFIRM_WINDOW_BORDERS",190,190,610,360);

	} 
	else 
	{
		XI_WindowDisable("CONFIRM_WINDOW", true);
		XI_WindowShow("CONFIRM_WINDOW", false);
		XI_WindowDisable("MAIN_WINDOW", false);
		SetCurrentNode("OK_BUTTON");
	}
}

//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------
void CreateProfileFolders()
{
	String folder = GameInterface.SavePath + "\";
	folder+= pchar.profile.name;

	if (XI_CheckFolder(folder)) return;

	if(!XI_CreateFolder(folder)) 
		trace("Could not create profile folder");
}
//----------------------------------------------------------------------------------------------------
void DeleteProfile()
{
	String folder;

	folder = GameInterface.SavePath + "\"+ pchar.profile.name;

	int nSaveNum= 0;
	string saveName;
	int nSaveSize;

	String path = GameInterface.SavePath;
	GameInterface.SavePath = folder;

    while( SendMessage(&GameInterface,"llee",MSG_INTERFACE_SAVE_FILE_FIND,nSaveNum,&saveName,&nSaveSize)!=0 )
    {
		nSaveNum++;
		SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,saveName);
    }

	GameInterface.SavePath = path;
	XI_DeleteFolder(folder);
}
//----------------------------------------------------------------------------------------------------
bool ProfileExists()
{
	String folder = GameInterface.SavePath + "\";


	folder+= pchar.profile.name;

	return (XI_CheckFolder(folder)); 
}
//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------
void SelectNation(int iNation)
{
	/////////////////////////////////////////////////////
	string sNationPict;
	for (int i=0; i<MAX_NATIONS; i++)
	{
		sNationPict = GetNationNameByType(i);

		SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,sNationPict, 5, 0);
	}

	sNationPict = GetNationNameByType(iNation);
	SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,sNationPict, 5, 1);
	/////////////////////////////////////////////////////
	NullCharacter.HeroParam.Nation = iNation;
	totalInfo = GetRPGText(Nations[iNation].Name + "_descr");
	SetInfoText();
}

void selectEngland()
{
	SelectNation(England);	
}

void selectFrance()
{
    //homo блокировка нации для Монбара
    if (startHeroType == 228) SelectNation(FRANCE);
	else SelectNation(France);

}

void selectSpain()
{
    //homo блокировка нации для Монбара
    if (startHeroType == 228) SelectNation(FRANCE);
	else SelectNation(SPAIN);

}

void selectHolland()
{
    //homo блокировка нации для Монбара
    if (startHeroType == 228) SelectNation(FRANCE);
	else SelectNation(HOLLAND);

}

void selectPirate()
{
    	//homo блокировка нации для Монбара
	if (startHeroType == 228) SelectNation(FRANCE);
	else SelectNation(PIRATE);
}

void IDoExit(int exitCode, bool bCode)
{
	DelEventHandler("exitCancel", "exitCancel");
	DelEventHandler("exitOk", "exitOk");
	DelEventHandler("selectEngland", "selectEngland");
	DelEventHandler("selectFrance", "selectFrance");
	DelEventHandler("selectSpain", "selectSpain");
	DelEventHandler("selectHolland", "selectHolland");
	DelEventHandler("selectPirate", "selectPirate");
	DelEventHandler("MouseRClickUP","HideInfo");
	DelEventHandler("ShowInfo","ShowInfo");

	DelEventHandler("noteOk","procNoteOk");
	
	DelEventHandler("frame","IProcessFrame");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	if(isOkExit == false)
	{
		EndCancelInterface(bCode);
	}
	else
	{
        MOD_EXP_RATE = makeint(5 + 10.0 * (1.0 - stf(GameInterface.nodes.EXP_SLIDE.value)));  // 0т 5 до 15
		trace("MOD_EXP_RATE = " + MOD_EXP_RATE);
		interfaceResultCommand = exitCode;
		EndCancelInterface(bCode);
	}
}

void confirmChangeProfileName()
{	
	PlayerProfile.name = GameInterface.PROFILE_NAME.str;
	pchar.profile.name = GameInterface.PROFILE_NAME.str;
}


void confirmChangeProfilePass()
{	
	PlayerProfile.password = GameInterface.PROFILE_PASS.str;
	pchar.profile.pass = GameInterface.PROFILE_PASS.str;
	SetCurrentNode("OK_BUTTON");
}


void ShowInfo()
{
	g_bToolTipStarted = true;
	string sHeader = "TEST";
	string sNode = GetCurrentNode();

	string sText1, sText2, sText3, sPicture, sGroup, sGroupPicture;
	sPicture = "none";
	sGroup = "none";
	sGroupPicture = "none";

	switch(sNode)
	{
		case "ENGLAND":
			sHeader = XI_ConvertString("England");
			sText1 = GetRPGText("England_descr");
		break;

		case "FRANCE":
			sHeader = XI_ConvertString("France");
			sText1 = GetRPGText("France_descr");
		break;

		case "HOLLAND":
			sHeader = XI_ConvertString("Holland");
			sText1 = GetRPGText("Holland_descr");
		break;

		case "SPAIN":
			sHeader = XI_ConvertString("Spain");
			sText1 = GetRPGText("Spain_descr");
		break;

		case "PIRATE":
			sHeader = XI_ConvertString("Pirate");
			sText1 = GetRPGText("Pirate_descr");
		break;
		
		case "COMPLEX_TYPE":
			sHeader = XI_ConvertString("m_Complexity");
			sText1 = GetRPGText("LevelComplexity_desc");
		break;
		
		case "CHECK_ENCOUNTERS":
			sHeader = XI_ConvertString("EncountersRate");
			sText1 = GetRPGText("EncountersRate_desc");
		break;
		
		case "CHECK_ARCADESAIL":
			sHeader = XI_ConvertString("Sailing Mode");
			sText1 = GetRPGText("ArcadeSailMode_desc");
		break;
		
		case "CHECK_PISTOL":
			sHeader = XI_ConvertString("New Fight Mode");
			sText1 = GetRPGText("RechargePistolOnLine_desc");
		break;
		
		case "CHECK_HARDCORE":
			sHeader = XI_ConvertString("HardcoreGame");
			sText1 = GetRPGText("HardcoreGame_desc");
		break;
		
		case "EXP_SLIDE":
			sHeader = GetRPGText("EXP_SLIDE");
			sText1 = GetRPGText("EXP_SLIDE_desc");
		break;

		case "CHECK_PARTITION":
			sHeader = XI_ConvertString("Partition Set");
			sText1 = GetRPGText("Partition_hint");
		break;
                                    case "CHECK_SEABATTLESAVE":
			sHeader = XI_ConvertString("Sea Battle Save");
			sText1 = GetRPGText("SeaBattleSave_desc");
		break;
                                    case "CHECK_RAINS":
			sHeader = XI_ConvertString("Rains");
			sText1 = GetRPGText("Rains_desc");
		break;
	}

	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	if( g_bToolTipStarted ) {
		g_bToolTipStarted = false;
		CloseTooltip();
		SetCurrentNode("OK_BUTTON");
	}
}

void ProcessCommandExecuteLeft()
{
    if (startHeroType > 1)
    {
       startHeroType--;
    }
    else
    {
       startHeroType = heroQty;
    }
    SetVariable(true);
}

void ProcessCommandExecuteRight()
{
    if (startHeroType < heroQty)
    {
       startHeroType++;
    }
    else
    {
       startHeroType = 1;
    }
    SetVariable(true);
}

void SetVariable(bool _init)
{
    idLngFile = LanguageOpenFile("HeroDescribe.txt");
    SetFormatedText("HERO_NAME", GetNewMainCharacterName());
    if (_init)
    {
    	NullCharacter.HeroParam.HeroType = GetNewMainCharacterType(startHeroType);
    	NullCharacter.HeroParam.nation = GetNewMainCharacterNation(startHeroType);
	}
    SetFormatedText("HERO_TYPE", XI_ConvertString(NullCharacter.HeroParam.HeroType));

    SetNewPicture("FACEPICT", "interfaces\portraits\256\face_" + GetNewMainCharacterFace() + ".tga");
    SelectNation(sti(NullCharacter.HeroParam.nation));
    totalInfo = LanguageConvertString(idLngFile, "hero_" + startHeroType);
    SetInfoText();
    LanguageCloseFile(idLngFile);
}


string GetCharacterType(string type, int direction)
{
    switch (type)
	{
        case "Master":
            if (direction > 0)
            {
    	    	type = "Merchant";
    	    }
    	    else
    	    {
    	        type = "SecretAgent";
    	    }
	    break;

	    case "Merchant":
            if (direction > 0)
            {
    	    	type = "Corsair";
    	    }
    	    else
    	    {
    	        type = "Master";
    	    }
	    break;

	    case "Corsair":
            if (direction > 0)
            {
    	    	type = "Adventurer";
    	    }
    	    else
    	    {
    	        type = "Merchant";
    	    }
	    break;
		
	    case "Adventurer":
            if (direction > 0)
            {
    	    	type = "Inquisitor";
    	    }
    	    else
    	    {
    	        type = "Corsair";
    	    }
	    break;
		
	    case "Inquisitor":
            if (direction > 0)
            {
    	    	type = "SecretAgent";
    	    }
    	    else
    	    {
    	        type = "Adventurer";
    	    }
	    break;
		
	    case "SecretAgent":
            if (direction > 0)
            {
    	    	type = "Master";
    	    }
    	    else
    	    {
    	        type = "Inquisitor";
    	    }
	    break;
	}

	return type;
}

void SetCharacterSPECIAL(string type, ref ch)
{
	switch (type)
	{
		case "Merchant":
			SetSPECIAL(ch, 5, 6, 7, 5, 8, 7, 8);
			SetSelfSkill(ch, 15, 5, 3, 8, 10);
			SetShipSkill(ch, 12, 5, 6, 3, 3, 5, 3, 3, 15);
		break;
		case "Corsair":
			SetSPECIAL(ch, 9, 5, 7, 6, 6, 8, 5);
			SetSelfSkill(ch, 4, 15, 4, 6, 8);
			SetShipSkill(ch, 15, 15, 3, 3, 3, 5, 3, 3, 8);
		break;
		case "Adventurer":
			SetSPECIAL(ch, 10, 5, 8, 7, 4, 8, 4);
			SetSelfSkill(ch, 3, 5, 15, 7, 7);
			SetShipSkill(ch, 5, 3, 3, 8, 3, 10, 8, 3, 5);
		break;
		case "SecretAgent":
			SetSPECIAL(ch, 7, 9, 7, 4, 5, 6, 9);
			SetSelfSkill(ch, 5, 5, 5, 15, 20);
			SetShipSkill(ch, 10, 3, 15, 12, 3, 3, 5, 3, 12);
		break;

	}
}

void ProcessCommandExecuteTypeLeft()
{
    idLngFile = LanguageOpenFile("HeroDescribe.txt");

    NullCharacter.HeroParam.HeroType = GetCharacterType(NullCharacter.HeroParam.HeroType, -1);

    SetFormatedText("HERO_TYPE", XI_ConvertString(NullCharacter.HeroParam.HeroType));

    totalInfo = LanguageConvertString(idLngFile, NullCharacter.HeroParam.HeroType);
    SetInfoText();
    LanguageCloseFile(idLngFile);
}

void ProcessCommandExecuteTypeRight()
{
    idLngFile = LanguageOpenFile("HeroDescribe.txt");

    NullCharacter.HeroParam.HeroType = GetCharacterType(NullCharacter.HeroParam.HeroType, 1);

    SetFormatedText("HERO_TYPE", XI_ConvertString(NullCharacter.HeroParam.HeroType));

    totalInfo = LanguageConvertString(idLngFile, NullCharacter.HeroParam.HeroType);
    SetInfoText();
    LanguageCloseFile(idLngFile);
}

void SetInfoText()
{
    SetFormatedText("INFO_TEXT", totalInfo);
    SetVAligmentFormatedText("INFO_TEXT");
}

void TmpI_ShowLevelComplexity()
{
    SetFormatedText("COMPLEX_TYPE", GetLevelComplexity(MOD_SKILL_ENEMY_RATE));
}