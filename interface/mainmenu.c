string isUsersName="";

//ref rCharacter; // boal
int iChar;

void InitInterface(string iniName)    
{    
    GameInterface.title = "titleMainMenu"; //заголовок окна, прописать в common.ini иначе будет пустым
    Event("DoInfoShower","sl","MainMenuLaunch",false);

    aref arScrShoter;
    if( !FindClass(&arScrShoter,"scrshoter") ) {
  CreateScreenShoter();
    }
    SetEventHandler("InterfaceBreak","ProcessBreakExit",0)
    SetEventHandler("exitCancel","ProcessCancelExit",0);
    SetEventHandler("ConfirmYes","ProcessDelete_yes",0);
    SetEventHandler("ConfirmNo","ProcessDelete_no",0);
    SetEventHandler("ResumeGamePress","ResumeGamePress",0);
    SetEventHandler("QuitPress","QuitPress",0);
    SetEventHandler("evntLowStorageBreak","LowStorageNext",0);
    SetEventHandler("UpPress","UpPress",0);
    SetEventHandler("DownPress","DownPress",0);
    SetEventHandler("ievnt_command","ProcCommand",0);
    SetEventHandler("BreakExit","procBreakExit",0);
  
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    // boal ver num -->
	     
        CreateString(true,"Version",VERSION_NUMBER1 + GetVerNum(),FONT_NORMAL,COLOR_NORMAL,400,545,SCRIPT_ALIGN_CENTER,0.9);
        CreateString(true,"site",VERSION_NUMBER3,FONT_NORMAL,COLOR_NORMAL,400,575,SCRIPT_ALIGN_CENTER,0.9);
    // boal ver num <--
    
    SetEventHandler("backgroundcommand","ProcCommand",0);
    ResetSound(); // new
    GameInterface.SavePath = "SAVE";
    oldMusicID = 0;
    musicName = "";
    SetMusic("music_MainMenu"); //музыка в главном меню, прописана в music_aliases.ini
}

void NewGamePress()
{
	IDoExit( RC_INTERFACE_DO_NEW_GAME, true );
}

void LoadPress()
{
	IDoExit( RC_INTERFACE_DO_LOAD_GAME, false );
}

void SavePress()
{
	IDoExit( RC_INTERFACE_DO_SAVE_GAME, false );
}

void OptionsPress()
{
	IDoExit( RC_INTERFACE_DO_OPTIONS, false );
}

void ControlsPress()
{
	IDoExit( RC_INTERFACE_DO_CONTROLS, false );
}

void CreditsPress()
{
	IDoExit( RC_INTERFACE_DO_CREDITS, false );

	/*SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);
	bMainMenuLaunchAfterVideo = true;
	StartPostVideo("credits",1);*/
}

void QuitPress()
{
    DelEventHandler("frame","QuitPress");
	EngineLayersOffOn(false);
	IDoExit(-1, false);
	ExitProgram();
}

void procGameQuit()
{
	ExitProgram();
}

void IDoExit(int exitCode, bool bClear)
{
	InterfaceStates.BackEnvironmentIsCreated = true;

	DelEventHandler("backgroundcommand","ProcCommand");
	
	interfaceResultCommand = exitCode;
	EndCancelInterface(bClear);
}

void ExitCancel()
{
	IDoExit(-1,true);
}

void ProcCommand()
{
    string comName = GetEventData();
    string nodName = GetEventData();

    switch(nodName)
    {
    
    case "B_NEWGAME":   NewGamePress(); break;
    case "B_LOAD":  LoadPress(); break;
    case "B_SAVE":  SavePress(); break;
    case "B_OPTIONS":  OptionsPress(); break;
    //case "Multiplayer":    MultiPress(); break;
    case "B_CREDITS":  CreditsPress(); break;
    case "Exit":  SetEventHandler("frame","QuitPress",0);  break;
    }
}

object InterfaceBackScene;

void MenuCreateLogo()
{
	InterfaceBackScene.Logo.locator = "";
	InterfaceBackScene.Logo.model = "mainmenu\AOPBoard";
	if( !Whr_IsNight() ) {
		InterfaceBackScene.Logo.technique = "InterfaceBackScene_Logo";
	}
	SendMessage(&InterfaceBackScene, "ls", 10, "Logo" );
}

