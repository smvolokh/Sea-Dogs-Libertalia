
//   												Модификация 'New Abilities' v 0.1

//   Rasteador's Craft System - Переплавка предметов
//	Автор: Rasteador

//	E-Mail: rasteador@yandex.ru
//	Skype: Rasteador72
//	ICQ: 643100745 (редко туда захожу)

//	Специально для сайта: http://corsairs-bay.ucoz.ru/


int item1 // Уголь
int item2 // Железная руда
int item3 // Серебряная руда
int item4 // Золотая руда
int item5 // Слитки железа
int itemGO // Сколько слитков получится

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
	
	item1 = GetCharacterItem(pchar, "jewelry21") // Уголь
	item2 = GetCharacterItem(pchar, "jewelry22") // Железная руда
	item3 = GetCharacterItem(pchar, "jewelry23") // Серебряная руда
	item4 = GetCharacterItem(pchar, "jewelry24") // Золотая руда
	item5 = GetCharacterItem(pchar, "jewelry19") // Слитки железа
	pchar.questTemp.CraftMetal = 1
	
	if(item2 < 3 || item1 < 5)
	{
		itemGO = 0
		SetSelectable("BUTTON_METALGO", false);
	}
	else
	{
		SetSelectable("BUTTON_METALGO", true);
		
		// Расчет получаемых слитков
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
	
	SetFormatedText("METALS_GO", "(Слитков получится: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "Слитки железа");
	SetFormatedText("METALS_STR2", "3 железной руды (в наличии "+ sti(item2) +")"+ newstr() +"5 угля (в наличии "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "Необходимо:");
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

void Click1() // Железо
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
		
		// Расчет получаемых слитков
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
	
	SetFormatedText("METALS_GO", "(Слитков получится: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "Слитки железа");
	SetFormatedText("METALS_STR2", "3 железной руды (в наличии "+ sti(item2) +")"+ newstr() +"5 угля (в наличии "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "Необходимо:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm4");
}

void Click2() // Сталь
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
		
		// Расчет получаемых слитков
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
	
	SetFormatedText("METALS_GO", "(Слитков получится: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "Стальные слитки");
	SetFormatedText("METALS_STR2", "2 железных слитка (в наличии "+ sti(item5) +")"+ newstr() +"4 угля (в наличии "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "Необходимо:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm7");
}

void Click3() // Серебро
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
		
		// Расчет получаемых слитков
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
	
	SetFormatedText("METALS_GO", "(Слитков получится: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "Серебряные слитки");
	SetFormatedText("METALS_STR2", "4 серебряной руды (в наличии "+ sti(item3) +")"+ newstr() +"6 угля (в наличии "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "Необходимо:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm5");
}

void Click4() // Золото
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
		
		// Расчет получаемых слитков
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
	
	SetFormatedText("METALS_GO", "(Слитков получится: "+ sti(itemGO) +")");
	SetFormatedText("METALS_STR1", "Золотые слитки");
	SetFormatedText("METALS_STR2", "5 золотой руды (в наличии "+ sti(item4) +")"+ newstr() +"8 угля (в наличии "+ sti(item1) +")");
	SetFormatedText("METALS_STR3", "Необходимо:");
	SetNewGroupPicture("FACEPICT", "ITEMS_15", "itm6");
}

void ClickGO() // Кнопка "Переплавить"
{
	if(pchar.questTemp.CraftMetal == 1)
	{
		// Забираем руду и уголь
		TakeNItems(pchar, "jewelry22", -(makeint(itemGO*3))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*5)));
		
		TakeNItems(pchar, "jewelry19", itemGO); // Даем готовые слитки
		
		// Даем опыт в кузнечку и горное
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*5))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*5))
		
		// Логи
		Log_Info("Получено железных слитков: "+ sti(itemGO) +" шт.")
		Log_Info("+"+ makeint(itemGO*5) +" опыта в горное и кузнечное дело")
	}
	
	if(pchar.questTemp.CraftMetal == 2)
	{
		// Забираем руду и уголь
		TakeNItems(pchar, "jewelry19", -(makeint(itemGO*2))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*4)));
		
		TakeNItems(pchar, "jewelry20", itemGO); // Даем готовые слитки
		
		// Даем опыт в кузнечку и горное
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*10))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*10))
		
		// Логи
		Log_Info("Получено стальных слитков: "+ sti(itemGO) +" шт.")
		Log_Info("+"+ makeint(itemGO*10) +" опыта в горное и кузнечное дело")
	}
	
	if(pchar.questTemp.CraftMetal == 3)
	{
		// Забираем руду и уголь
		TakeNItems(pchar, "jewelry23", -(makeint(itemGO*4))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*6)));
		
		TakeNItems(pchar, "jewelry17", itemGO); // Даем готовые слитки
		
		// Даем опыт в кузнечку и горное
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*15))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*15))
		
		// Логи
		Log_Info("Получено серебряных слитков: "+ sti(itemGO) +" шт.")
		Log_Info("+"+ makeint(itemGO*15) +" опыта в горное и кузнечное дело")
	}
	
	if(pchar.questTemp.CraftMetal == 4)
	{
		// Забираем руду и уголь
		TakeNItems(pchar, "jewelry24", -(makeint(itemGO*5))); 
		TakeNItems(pchar, "jewelry21", -(makeint(itemGO*8)));
		
		TakeNItems(pchar, "jewelry5", itemGO); // Даем готовые слитки
		
		// Даем опыт в кузнечку и горное
		AddCharacterEXPtoSkill(pchar, SKILL_BLACKSMITH, makeint(itemGO*20))
		AddCharacterEXPtoSkill(pchar, SKILL_MINEPICKING, makeint(itemGO*20))
		
		// Логи
		Log_Info("Получено золотых слитков: "+ sti(itemGO) +" шт.")
		Log_Info("+"+ makeint(itemGO*20) +" опыта в горное и кузнечное дело")
	}
	
	AddTimeToCurrent(0, makeint(itemGO*20)); // Добавляем время
	IDoExit(RC_INTERFACE_DO_RESUME_GAME, true); // Закрываем интерфейс
	PlaySound("Ambient\Towns\hammer_01.WAV") // Проигрываем звук
}

void ResumeClick() // Закрываем главное меню крафта
{
	IDoExit(RC_INTERFACE_DO_RESUME_GAME, true);
}