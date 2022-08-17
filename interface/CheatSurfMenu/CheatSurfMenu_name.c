
/*
	CheatSurfMenu by Cheatsurfer �� 07.01.2018 ��� ��� 1.6.0 (18.12.17)
	��������� ����� ��������� (� �� ������)
	27.04.18
*/

int iSND = 0;

void InitInterface(string iniName)
{
	if (!CheckAttribute(pchar, "CSM.ChangeName")) pchar.CSM.ChangeName = "MC";
	StartAboveForm(true);
	GameInterface.title = "CSM_title_name";
	switch (pchar.CSM.ChangeName)
	{
		case "MC":
			GameInterface.char_name.str = pchar.name;
			GameInterface.char_name_g.str = pchar.nameGen;
			GameInterface.char_name_d.str = pchar.nameDat;
			GameInterface.char_lastname.str = pchar.lastname;
			GameInterface.char_lastname_g.str = pchar.lastnameGen;
			GameInterface.char_lastname_d.str = pchar.lastnameDat;
			SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
			SetFormatedText("INFO_TEXT_1", "��� �����");
			SetFormatedText("INFO_TEXT_2", "���(����?)");
			SetFormatedText("INFO_TEXT_3", "���(����?)");
			SetFormatedText("INFO_TEXT_4", "������� �����");
			SetFormatedText("INFO_TEXT_5", "�������(����?)");
			SetFormatedText("INFO_TEXT_6", "�������(����?)");
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_1",5);
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_2",5);
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_3",5);
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_4",5);
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_5",5);
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_6",5);
		break;
		case "Update":
			SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,"RESOURCE\INI\interfaces\CheatSurfMenu\CheatSurfMenu_update.ini");
			SetFormatedText("INFO_TEXT_1",csmUpdateInfo());
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_1",5);
		break;
		case "Save":
			SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,"RESOURCE\INI\interfaces\CheatSurfMenu\CheatSurfMenu_save.ini");
			SetFormatedText("INFO_TEXT_1",csmSaveInfo());
			SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT_1",5);
		break;
	}
	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
//	PlaySound("Interface\s_korablami_001.wav");
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_ANY_EXIT );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_ANY_EXIT );
}

void IDoExit(int exitCode)
{
	EndAboveForm(true);
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("evntDoPostExit","DoPostExit");
	DelEventHandler("ievnt_command","ProcCommand");
	if(bSeaActive) { RefreshBattleInterface(); }
	interfaceResultCommand = exitCode;
	DeleteAttribute(pchar, "CSM.ChangeName");
	EndCancelInterface(true);
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	if (pchar.CSM.ChangeName == "MC")
	{
		switch (nodName)
		{
			case "B_CONFIRM": if (comName == "activate" || comName == "click") { CalculateInfoDataF1(); } break;
			case "B_CANCEL": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
		}
	}
	else
	{
		if (pchar.CSM.ChangeName == "Update")
		{
			switch (nodName)
			{
				case "B_CONFIRM": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
			}
		}
		else
		{
			if (pchar.CSM.ChangeName == "Save")
			{
				switch (nodName)
				{
					case "B_CONFIRM": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
					case "B_CONFIRM2": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
				}
			}
			else
			{
				switch (nodName)
				{
					case "B_CONFIRM": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
					case "B_CANCEL": if (comName == "activate" || comName == "click") { ProcessBreakExit(); } break;
				}
			}
		}
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoDataF1()
{
	ClearAllLogStrings();
	string myname = GetSubStringByNum(GameInterface.char_name.str, 0);
	string mynameG = GetSubStringByNum(GameInterface.char_name_g.str, 0);
	string mynameD = GetSubStringByNum(GameInterface.char_name_d.str, 0);
	string mylastname = GetSubStringByNum(GameInterface.char_lastname.str, 0);
	string mylastnameG = GetSubStringByNum(GameInterface.char_lastname_g.str, 0);
	string mylastnameD = GetSubStringByNum(GameInterface.char_lastname_d.str, 0);
	pchar.name = myname;
	pchar.nameGen = mynameG;
	pchar.nameDat = mynameD;
	pchar.lastname = mylastname;
	pchar.lastnameGen = mylastnameG;
	pchar.lastnameDat = mylastnameD;
	Log_info("��� ���������: " + GetFullName(pchar));
	if (iSND != 0) StopSound(iSND, 0);
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	ProcessCancelExit();
}

string csmUpdateInfo()
{
	return "������, ���� ���� ���������.\n����� ����, ������������ � � ��, ����� ������������� ���������� � �������� ������������.\n�� ��������� ��������� �������, �������� �� ��� (������ ��� Steam!): yadi.sk/d/Ebt7Wy0-3LL4iK\n���� ������ �� ���������� ������ ������ ���������� �� �����������, �� ��������� �����.";
}

string csmSaveInfo()
{
	return "����� �������� � ���������� �� ������������� �������� � ��.\n���� ���� � �� ���� ���������� � ����� ���������� �� ������������ ��� ���������������� ����, �� 100% ����� ������.\n���� ��������� ����� ����, ���� �������� ��.\n� ���� �� ���� ������ ����� �������� � ��, ���������� � ������ �������, �� ������ ����������� ��� ���������.";
}
