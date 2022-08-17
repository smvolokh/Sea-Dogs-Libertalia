
void InitInterface(string iniName)
{
	GameInterface.title = "titleBalloon";
    	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetStartInformation();
	
	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("HeightTempUptade","HeightTempUptade",0);
	SetEventHandler("RClickLeft","RClickLeft",0);
	SetEventHandler("RClickRight","RClickRight",0);
}

void ProcessBreakExit()
{
	IDoExit(RC_INTERFACE_SALARY_EXIT);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_SALARY_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("HeightTempUptade","HeightTempUptade");
	DelEventHandler("RClickLeft","RClickLeft");
	DelEventHandler("RClickRight","RClickRight");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
		case "LEFT":
			if(comName=="activate" || comName=="click")
			{
				SelectHeight(true);
			}
		break;
		
		case "RIGHT":
			if(comName=="activate" || comName=="click")
			{
				SelectHeight(false);
			}
		break;
		
		case "SELECT_HEIGHT_RESET":
			if(comName=="activate" || comName=="click")
			{
				SelectHeightReset();
			}
		break;
		
		case "SELECT_HEIGHT_INSTALL":
			if(comName=="activate" || comName=="click")
			{
				SelectHeightInstall();
			}
		break;
	}
}

//////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////
void SelectHeight(bool bLeft)
{
	float   fTmp;

	if(bLeft)
	{
		GameInterface.HEIGHT_STRING.str = sti(GameInterface.HEIGHT_STRING.str) - 1;
	}
	else
	{
		GameInterface.HEIGHT_STRING.str = sti(GameInterface.HEIGHT_STRING.str) + 1;
	}
		
	if(sti(GameInterface.HEIGHT_STRING.str) > BALLOON_MAX_HEIGHT) { GameInterface.HEIGHT_STRING.str = BALLOON_MAX_HEIGHT; }
	if(sti(GameInterface.HEIGHT_STRING.str) < BALLOON_MIN_HEIGHT) { GameInterface.HEIGHT_STRING.str = BALLOON_MIN_HEIGHT; }

}

void SelectHeightReset()
{
	int iCurHeight = GetCurBalloonHeight();
	GameInterface.HEIGHT_STRING.str = iCurHeight;
}

void SelectHeightInstall()
{
	HeightTempUptade();
	
	int iNewHeight = sti(GameInterface.HEIGHT_STRING.str);
	SetBalloonNewHeight(iNewHeight);
	
	SetStartInformation();
}

//////////////////////////////////////////////////////////////////
// Uptade Info
//////////////////////////////////////////////////////////////////
void HeightTempUptade()
{
	if(sti(GameInterface.HEIGHT_STRING.str) > BALLOON_MAX_HEIGHT) { GameInterface.HEIGHT_STRING.str = BALLOON_MAX_HEIGHT; }
	if(sti(GameInterface.HEIGHT_STRING.str) < BALLOON_MIN_HEIGHT) { GameInterface.HEIGHT_STRING.str = BALLOON_MIN_HEIGHT; }
}

void RClickLeft()
{
	GameInterface.HEIGHT_STRING.str = BALLOON_MIN_HEIGHT;
}

void RClickRight()
{
	GameInterface.HEIGHT_STRING.str = BALLOON_MAX_HEIGHT;
}

	
//////////////////////////////////////////////////////////////////
// Info
//////////////////////////////////////////////////////////////////
void SetStartInformation()
{
	int iCurHeight = GetCurBalloonHeight();
	GameInterface.HEIGHT_STRING.str = iCurHeight;

	CreateString(true,"BalloonParams", "Характеристики полёта", FONT_CAPTION, COLOR_NORMAL, 390,48,SCRIPT_ALIGN_CENTER,1.0);
	SetFormatedText("BALLOON_HEIGHT", "Установка высоты полёта");
	SetFormatedText("BALLOON_CUR_HEIGHT", "Текущая высота полёта: " + iCurHeight + " м.");

}


	//CreateImage("EquipmentHeader", "MAIN_ICONS", "skillborder", 154,170,646,201);
	
	