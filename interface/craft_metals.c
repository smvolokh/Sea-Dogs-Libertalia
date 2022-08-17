
//   												����������� 'New Abilities' v 0.1

//   Rasteador's Craft System - ���������� ���������
//	�����: Rasteador

//	E-Mail: rasteador@yandex.ru
//	Skype: Rasteador72
//	ICQ: 643100745 (����� ���� ������)

//	���������� ��� �����: http://corsairs-bay.ucoz.ru/


int item1 // �����
int item2 // �������� ����
int item3 // ���������� ����
int item4 // ������� ����
int item5 // ������ ������
int itemGO // ������� ������� ���������

void InitInterface_gm(string iniName)
{
	GameInterface.title = "titleGameMenu";

	SetTimeScale(0.0);
	locCameraSleep(true);

	EngineLayersOffOn(true);

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","IProcessFrame",0);
	
	SetEventHandler("Click1","Click1",0);
	SetEventHandler("Click2","Click2",0);
	SetEventHandler("Click3","Click3",0);
	SetEventHandler("Click4","Click4",0);
	SetEventHandler("ClickGO","ClickGO",0);
	SetEventHandler("ResumeClick","ResumeClick",0);
	
	item1 = GetCharacterItem(pchar, "jewelry21") // �����
	item2 = GetCharacterItem(pchar, "jewelry22") // �������� ����
	item3 = GetCharacterItem(pchar, "jewelry23") // ���������� ����
	item4 = GetCharacterItem(pchar, "jewelry24") // ������� ����
	item5 = GetCharacterItem(pchar, "jewelry19") // ������ ������
	pchar.questTemp.CraftMetal = 1
	
	if(item2 < 3 || item1 < 5)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// ������ ���������� �������
		if(makeint(item2/3) < makeint(item1/5))
		{
			itemGO = makeint(item1/5) + (makeint(item2/3) - makeint(item1/5))
		}
	
		if(makeint(item1/5) < makeint(item2/3))
		{
			itemGO = makeint(item2/3) + (makeint(item1/5) - makeint(item2/3))
		}
	
		if(makeint(item1/5) == makeint(item2/3))
		{
			itemGO = makeint(item1/5)
		}
	}
	
	SetFormatedText("METALS_GO", "(������� ���������: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "������ ������");
	SetFormatedText("METALS_STR2", "3 �������� ���� (� ������� "+ sti(item2) +")"+ newstr() +"5 ���� (� ������� "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "����������:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm4");

	InterfaceStates.showGameMenuOnExit = true;
}


void IProcessFrame()
{
}

void ProcessCancelExit()
{
	if(CheckAttribute(&InterfaceStates,"Buttons.Resume.enable") && sti(InterfaceStates.Buttons.Resume.enable) == true)
	IDoExit(RC_INTERFACE_DO_RESUME_GAME, true);
}

void IDoExit(int exitCode, bool bClear)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","IProcessFrame");

	DelEventHandler("LightWClick","LightWClick");
	DelEventHandler("WClick","WClick");
	DelEventHandler("HeavyWClick","HeavyWClick");
	DelEventHandler("MetalsClick","MetalsClick");
	DelEventHandler("ResumeClick","ResumeClick");

	SetTimeScale(1.0);
	TimeScaleCounter = 0;
	DelPerkFromActiveList("TimeSpeed");
	locCameraSleep(false);
	DeleteAttribute(pchar, "pause");

	interfaceResultCommand = exitCode;

	if( interfaceResultCommand == RC_INTERFACE_DO_RESUME_GAME ) {
		DeleteEntitiesByType("scrshoter");
	}
	EndCancelInterface(bClear);
}

void ProcessCommandExecute()
{
}

void Click1() // ������
{
	pchar.questTemp.CraftMetal = 1
	
	if(item2 < 3 || item1 < 5)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// ������ ���������� �������
		if(makeint(item2/3) < makeint(item1/5))
		{
			itemGO = makeint(item1/5) + (makeint(item2/3) - makeint(item1/5))
		}
	
		if(makeint(item1/5) < makeint(item2/3))
		{
			itemGO = makeint(item2/3) + (makeint(item1/5) - makeint(item2/3))
		}
	
		if(makeint(item1/5) == makeint(item2/3))
		{
			itemGO = makeint(item1/5)
		}
	}
	
	SetFormatedText("METALS_GO", "(������� ���������: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "������ ������");
	SetFormatedText("METALS_STR2", "3 �������� ���� (� ������� "+ sti(item2) +")"+ newstr() +"5 ���� (� ������� "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "����������:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm4");
}

void Click2() // �����
{
	pchar.questTemp.CraftMetal = 2
	
	if(item5 < 2 || item1 < 4)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// ������ ���������� �������
		if(makeint(item5/2) < makeint(item1/4))
		{
			itemGO = makeint(item1/4) + (makeint(item5/2) - makeint(item1/4))
		}
	
		if(makeint(item1/4) < makeint(item5/2))
		{
			itemGO = makeint(item5/2) + (makeint(item1/4) - makeint(item5/2))
		}
	
		if(makeint(item1/4) == makeint(item5/2))
		{
			itemGO = makeint(item1/4)
		}
	}
	
	SetFormatedText("METALS_GO", "(������� ���������: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "�������� ������");
	SetFormatedText("METALS_STR2", "2 �������� ������ (� ������� "+ sti(item5) +")"+ newstr() +"4 ���� (� ������� "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "����������:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm7");
}

void Click3() // �������
{
	pchar.questTemp.CraftMetal = 3
	
	if(item3 < 4 || item1 < 6)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// ������ ���������� �������
		if(makeint(item3/4) < makeint(item1/6))
		{
			itemGO = makeint(item1/6) + (makeint(item3/4) - makeint(item1/6))
		}
	
		if(makeint(item1/6) < makeint(item3/4))
		{
			itemGO = makeint(item3/4) + (makeint(item1/6) - makeint(item3/4))
		}
	
		if(makeint(item1/6) == makeint(item3/4))
		{
			itemGO = makeint(item1/6)
		}
	}
	
	SetFormatedText("METALS_GO", "(������� ���������: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "���������� ������");
	SetFormatedText("METALS_STR2", "4 ���������� ���� (� ������� "+ sti(item3) +")"+ newstr() +"6 ���� (� ������� "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "����������:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm5");
}

void Click4() // ������
{
	pchar.questTemp.CraftMetal = 4
	
	if(item4 < 5 || item1 < 8)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// ������ ���������� �������
		if(makeint(item4/5) < makeint(item1/8))
		{
			itemGO = makeint(item1/8) + (makeint(item4/5) - makeint(item1/8))
		}
	
		if(makeint(item1/8) < makeint(item4/5))
		{
			itemGO = makeint(item4/5) + (makeint(item1/8) - makeint(item4/5))
		}
	
		if(makeint(item1/8) == makeint(item4/5))
		{
			itemGO = makeint(item1/8)
		}
	}
	
	SetFormatedText("METALS_GO", "(������� ���������: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "������� ������");
	SetFormatedText("METALS_STR2", "5 ������� ���� (� ������� "+ sti(item4) +")"+ newstr() +"8 ���� (� ������� "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "����������:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm6");
}

void ClickGO() // ������ "�����������"
{
	if(pchar.questTemp.CraftMetal == 1)
	{
		// �������� ���� � �����
		TakeNItems(pchar, "jewelry22", -(makeint(itemGO*3))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*5)));
		
		TakeNItems(pchar, "jewelry19", itemGO); // ���� ������� ������
		
		// ���� ���� � �������� � ������
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*5))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*5))
		
		// ����
		Log_Info("�������� �������� �������: "+ sti(itemGO) +" ��.")
		Log_Info("+"+ makeint(itemGO*5) +" ����� � ������ � ��������� ����")
	}
	
	if(pchar.questTemp.CraftMetal == 2)
	{
		// �������� ���� � �����
		TakeNItems(pchar, "jewelry19", -(makeint(itemGO*2))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*4)));
		
		TakeNItems(pchar, "jewelry20", itemGO); // ���� ������� ������
		
		// ���� ���� � �������� � ������
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*10))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*10))
		
		// ����
		Log_Info("�������� �������� �������: "+ sti(itemGO) +" ��.")
		Log_Info("+"+ makeint(itemGO*10) +" ����� � ������ � ��������� ����")
	}
	
	if(pchar.questTemp.CraftMetal == 3)
	{
		// �������� ���� � �����
		TakeNItems(pchar, "jewelry23", -(makeint(itemGO*4))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*6)));
		
		TakeNItems(pchar, "jewelry17", itemGO); // ���� ������� ������
		
		// ���� ���� � �������� � ������
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*15))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*15))
		
		// ����
		Log_Info("�������� ���������� �������: "+ sti(itemGO) +" ��.")
		Log_Info("+"+ makeint(itemGO*15) +" ����� � ������ � ��������� ����")
	}
	
	if(pchar.questTemp.CraftMetal == 4)
	{
		// �������� ���� � �����
		TakeNItems(pchar, "jewelry24", -(makeint(itemGO*5))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*8)));
		
		TakeNItems(pchar, "jewelry5", itemGO); // ���� ������� ������
		
		// ���� ���� � �������� � ������
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*20))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*20))
		
		// ����
		Log_Info("�������� ������� �������: "+ sti(itemGO) +" ��.")
		Log_Info("+"+ makeint(itemGO*20) +" ����� � ������ � ��������� ����")
	}
	
	AddTimeToCurrent(0, makeint(itemGO*20)); // ��������� �����
	IDoExit(RC_INTERFACE_DO_RESUME_GAME, true); // ��������� ���������
	PlaySound("Ambient\Towns\hammer_01.WAV") // ����������� ����
}

void ResumeClick() // ��������� ������� ���� ������
{
	IDoExit(RC_INTERFACE_DO_RESUME_GAME, true);
}