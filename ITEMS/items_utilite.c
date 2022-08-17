bool IsQuestUsedItem(string itmID)
{
	aref arItm;
	if( Items_FindItem(itmID,&arItm)<0 ) return false;
	if( CheckAttribute(arItm,"price") && sti(arItm.price)>0 ) return false;
	return true;
}

void DoCharacterUsedItem(ref chref, string itmID)
{
	aref arItm;
	if( Items_FindItem(itmID,&arItm)<0 ) return;
	TakeItemFromCharacter(chref,itmID);

	 // Warship 13.06.09 fix - если только отравлен, а жизни полные (а такое бывает), то нечего и строку в лог выводить об прибавлении жизней
	if(CheckAttribute(arItm,"potion.health") && LAi_GetCharacterHP(chref) < LAi_GetCharacterMaxHP(chref))
	{
		LAi_UseHealthBottle(chref,stf(arItm.potion.health));
		if(sti(chref.index)==GetMainCharacterIndex()) {
			Log_SetStringToLog( XI_ConvertString("Health Up"));
		}
		// boal
		if( CheckAttribute(arItm,"potion.health.speed") )
		{
			LAi_UseHealthBottleSpeed(chref, stf(arItm.potion.health.speed));
		}
	}
	
	// Warship 13.06.09 fix - если не отравлен, то нечего и строку в лог выводить
	if(CheckAttribute(arItm,"potion.antidote") && LAi_IsPoison(chref) && !CheckAttribute(chref, "GenQuest.Hotwater")) // Addon 2016-1 Jason Пиратская линейка
	{
		LAi_UseAtidoteBottle(chref);
		if(sti(chref.index)==GetMainCharacterIndex()) {
			Log_SetStringToLog( XI_ConvertString("You are cured from poison") );
		}
		else{
			Log_SetStringToLog(GetFullName(chref) + XI_ConvertString("are cured from poison") );
		}
	}
	
	// ugeen --> плата в здоровье за пользование лечилками
	if(CheckAttribute(arItm,"potion.penalty") && sti(chref.index) == GetMainCharacterIndex())
	{
		AddCharacterHealth(chref, -stf(arItm.potion.penalty));
	}
	
	//navy --> алкоголь
	if (CheckAttribute(arItm, "potion.drunk"))
	{
		LAi_AlcoholSetDrunk(chref, stf(arItm.potion.drunk), stf(arItm.potion.drunk.time));
		if(sti(chref.index)==GetMainCharacterIndex())
		{
			Log_SetStringToLog( XI_ConvertString("You're get drunk") );
		}
	}
	//<--
	if(sti(chref.index)==GetMainCharacterIndex()) PlaySound("Ambient\Tavern\glotok_001.wav");
	if( CheckAttribute(arItm,"potion.sound") )
	{
		PlaySound(arItm.potion.sound);
	}
}

float MinHealthPotionForCharacter(ref chref)
{
	float ftmp;
	bool isFinded = false;

	for(int n=0; n<ITEMS_QUANTITY; n++)
	{
		if( CheckAttribute(&Items[n],"potion") )
		{
			if(CheckAttribute(&Items[n],"potion.health"))
			{
				if( GetCharacterItem(chref,Items[n].id)>0 )
				{
					if(isFinded)
					{
						if( stf(Items[n].potion.health)<ftmp )
						{
							ftmp = stf(Items[n].potion.health);
						}
					}else{
						ftmp = stf(Items[n].potion.health);
						isFinded = true;
					}
				}
			}
		}
	}
	if(!isFinded) return 0.0;
	return ftmp;
}

string FindHealthForCharacter(ref chref,float fHealth)
{
	string sret = "";
	float fdelta = fHealth + 100.0;
	float ftmp;

	for(int n=0; n<ITEMS_QUANTITY; n++)
	{
		if( CheckAttribute(&Items[n],"potion") )
		{
			if( CheckAttribute(&Items[n],"potion.health") )
			{
				if( GetCharacterItem(chref,Items[n].id)>0 )
				{
					ftmp = stf(Items[n].potion.health);
					if( ftmp<fHealth )	{ftmp = fHealth - ftmp;}
					else	{ftmp = ftmp - fHealth;}
					if(ftmp<fdelta)
					{
						fdelta = ftmp;
						sret = Items[n].id;
					}
				}
			}
		}
	}

	return sret;
}

int FindPotionFromChr(ref chref, ref arFind, int startIdx)
{
	int i;
	aref arItm;
	for(i=startIdx; i<ITEMS_QUANTITY; i++)
	{
		makearef(arItm,Items[i]);
		if( CheckAttribute(arItm,"potion") && GetCharacterItem(chref,Items[i].id)>0 )
		{
			arFind = arItm;
			return i;
		}
	}
	return -1;
}

int UseBestPotion(ref chref, bool needAntidote)
{
	int i;
	int curPotionID = -1;
	int curPotionHealAmt = 0;
	int newPotionHealAmt = 0;
	bool potionTooGood = false;
	bool bValidPot;
	int reqHealAmt = LAi_GetCharacterMaxHP(chref) - LAi_GetCharacterHP(chref);
	reqHealAmt = makeint(MakeFloat(reqHealAmt) * 1.2)
	if (reqHealAmt <=0 && !needAntidote) 
	{
		return -1;
	}
	
	aref arItm;
	for(i=1; i<ITEMS_QUANTITY; i++)
	{
		makearef(arItm,Items[i]);
		bValidPot = false;

		if (!needAntidote && CheckAttribute(arItm,"potion.health") && !CheckAttribute(arItm,"potion.antidote")) 
		{
			bValidPot = true;
		}
		else 
		{
			if (needAntidote && CheckAttribute(arItm,"potion.antidote")) 
			{
				bValidPot = true;
			}
		}
		if( bValidPot && (GetCharacterItem(chref,arItm.id) > 0))
		{
			if (CheckAttribute(arItm,"potion.health"))
				newPotionHealAmt = arItm.potion.health;
			else
				newPotionHealAmt = 0;
								
			if (potionTooGood) 
			{
				if (newPotionHealAmt < curPotionHealAmt) 
				{
					curPotionID = i;
					curPotionHealAmt = newPotionHealAmt;
				}
			}
			else
			{
				if ((newPotionHealAmt + 1) > curPotionHealAmt) 
				{
					if (curPotionHealAmt == 0 || newPotionHealAmt <= reqHealAmt) 
					{
						curPotionID = i;
						curPotionHealAmt = newPotionHealAmt;
					}
				}
			}
			if (curPotionHealAmt > reqHealAmt) 
			{
				potionTooGood = true;
			}
		}
	}
	if (CheckAttribute(chref, "GenQuest.Potion_choice"))
	{
		if (CheckCharacterItem(pchar, chref.GenQuest.Potion_choice))
		{
			DoCharacterUsedItem(pchar, chref.GenQuest.Potion_choice);
		return 1;
	}
		else
		{
			PlaySound("interface\notebook.wav");
			log_info("Выбранное лечебное зелье отсутствует в инвентаре!");
			log_info("Активирован автоматический выбор лечебного зелья");
			DeleteAttribute(pchar, "GenQuest.Potion_choice");
			return 0;
		}
	}
	else
	{
		if (curPotionID > 0) 
		{
			DoCharacterUsedItem(pchar, Items[curPotionID].id);
			return 1;
		}
	else return 0;
}
}

int FindQuestUsableItem(ref arFind, int startIdx)
{
	int i;
	aref arItm;
	bool bSeaInterface = bSeaActive && !bAbordageStarted;

	if(startIdx<0) startIdx=0;
	for(i=startIdx; i<ITEMS_QUANTITY; i++)
	{
		makearef(arItm,Items[i]);
		if( CheckAttribute(arItm,"quest") && CheckAttribute(arItm,"quest.tex"))// boal 16.03.2004
		{
			if( bSeaInterface && arItm.quest.tex=="QuestCommands" )
			{
				arFind = arItm;
				return i;
			}
		}
	}

	return -1;
}

bool EnablePotionUsing(ref mc, aref arItm)
{
	if( CheckAttribute(arItm,"potion.health") ) {
		if( LAi_GetCharacterHP(mc)<LAi_GetCharacterMaxHP(mc) ) {
			return true;
		}
	}
	
	return false;
}

// Warship 13.06.09 Для противоядий
bool EnableAntidoteUsing(ref _char, aref _item)
{
	if(CheckAttribute(_item, "potion.antidote") && LAi_IsPoison(_char) && CheckCharacterItem(_char, _item.Id))
	{
		return true;
	}
	
	return false;
}

bool FindCharacterAntidote(ref _char, ref _itemId)
{
	int itemIndex;
	ref item;
	
	for(itemIndex = 0; itemIndex < ITEMS_QUANTITY; itemIndex++)
	{
		item = &Items[itemIndex];
		
		if(EnableAntidoteUsing(_char, item))
		{
			_itemID = item.ID;
			return true;
		}
	}
	
	return false;
}

int FindItem(string sItemID)
{
/*
	for(int i = 0; i < TOTAL_ITEMS; i++)
	{
		if(CheckAttribute(Items[i], "ID") && Items[i].id == sItemID)
		{
			return i;
		}
	}
	return -1;
*/	
	// Warship 07.07.09 Перевел на движковую функцию - по-идее, так должно работать быстрее
	return NativeFindCharacter(&Items, sItemID);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Warship 08.05.09 НОВАЯ СИСТЕМА ПРЕДМЕТОВ -->
//      Ugeen --> 10.02.10 добавлена первичная генерация предметов и выбор из массива сгенерированных предметов
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ugeen --> начальная генерация генерируемых предметов
void GenerateGenerableItems()
{
	ref itemRef;

	for(int i = 0; i < ITEMS_QUANTITY; i++)
	{
		itemRef = &Items[i];	
		if(CheckAttribute(itemRef, "id") && CheckAttribute(itemRef, "Generation.Qty") && !CheckAttribute(itemRef, "GeneratedAll"))
		{
			for(int j = 0; j < sti(itemRef.Generation.Qty); j++) 
			{
				GenerateItem(itemRef.id);
			}	
			//SetItemPrice(itemRef.id);
			itemRef.GeneratedAll = true;
		}		
	}
}

//ugeen --> вернем случайный ID сгенерированного зараннее предмета
string GetGeneratedItem(string _itemId)
{
	int itemsQty = 0;
	String generatedItems[TOTAL_ITEMS];
	
	if(!IsGenerableItem(_itemId)) // Генерящийся ли предмет
	{
		return _itemID;
	}
	
	for(int i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
	{
		if(CheckAttribute(&Items[i], "DefItemID") && Items[i].DefItemID == _itemId)
		{
			generatedItems[itemsQty] = Items[i].ID;
			itemsQty++;
		}
	}
		
	if(itemsQty == 0)
	{
		return _itemId; // Ничего не нашлось
	}
		
	return generatedItems[rand(itemsQty - 1)];
}

//ugeen --> вернем  ID сгенерированного зараннее предмета с наилучшими характеристиками
string GetBestGeneratedItem(string _itemId)
{
	int itemsQty = 0;
	String generatedItems[TOTAL_ITEMS];
	String tmpItem;
	bool bOk;
	int itemIndex1, itemIndex2; 
	ref rItem1, rItem2;

	if(!IsGenerableItem(_itemId)) // Генерящийся ли предмет
	{
		return _itemID;
	}	

	for(int i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
	{
		if(CheckAttribute(&Items[i], "DefItemID") && Items[i].DefItemID == _itemId && Items[i].groupID == BLADE_ITEM_TYPE)
		{
			generatedItems[itemsQty] = Items[i].ID;
			
			itemIndex1 = GetItemIndex(generatedItems[itemsQty]);
			rItem1 = &Items[itemIndex1];			
//			trace("unsorted : blade.id : " + rItem1.id + " blade.Attack : " + rItem1.Attack + " blade.balance : " + rItem1.balance + " blade.Weight : " + rItem1.Weight);			
			itemsQty++;					
		}
	}
	
	if(itemsQty == 0)
	{
		return _itemId; // Ничего не нашлось
	}

	// сортируем элементы массива
	bOk = true;
	while (bOk)
	{
		bOk = false;
		for(int j = 0; j < (itemsQty - 1); j++)
		{
			itemIndex1 = GetItemIndex(generatedItems[j]);
			itemIndex2 = GetItemIndex(generatedItems[j + 1]);
		
			rItem1 = &Items[itemIndex1];
			rItem2 = &Items[itemIndex2];
		
			if( stf(rItem1.Attack) > stf(rItem2.Attack) )
			{
				tmpItem = generatedItems[j];
				generatedItems[j] = generatedItems[j + 1];
				generatedItems[j + 1] = tmpItem;
				bOk = true;
			}	
			else
			{
				if(stf(rItem1.Attack) == stf(rItem2.Attack))
				{
					if( stf(rItem1.Weight) < stf(rItem2.Weight) )
					{
						tmpItem = generatedItems[j];
						generatedItems[j] = generatedItems[j + 1];
						generatedItems[j + 1] = tmpItem;
						bOk = true;					
					}
				}
			}
		}
	}
/*	
	for(int k = 0; k < itemsQty; k++)
	{		
		itemIndex1 = GetItemIndex(generatedItems[k]);
		rItem1 = &Items[itemIndex1];
		trace("sorted : blade.id : " + rItem1.id + " blade.Attack : " + rItem1.Attack + " blade.balance : " + rItem1.balance + " blade.Weight : " + rItem1.Weight);		
	}	
*/	
	return generatedItems[itemsQty - 1];
}

//  вернем определенный ID сгенерированного предмета
string GetGeneratedItemNum(string _itemId, int Num)
{
	int itemsQty = 0;
	String generatedItems[TOTAL_ITEMS];
	
	if(!IsGenerableItem(_itemId)) // Генерящийся ли предмет
	{
		return _itemID;
	}
	
	for(int i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
	{
		if(CheckAttribute(&Items[i], "DefItemID") && Items[i].DefItemID == _itemId)
		{
			generatedItems[itemsQty] = Items[i].ID;
			itemsQty++;
		}
	}
		
	if(itemsQty == 0 || itemsQty < Num)
	{
		return _itemId; // Ничего не нашлось
	}
				
	return generatedItems[itemsQty + Num];
}

/*
void SetItemPrice(String _itemId)
{
	int priceMod;
	ref item = &Items[GetItemIndex(_itemId)];
	
	switch(item.FencingType)
	{
		case "FencingLight": // Легкое оружие
			priceMod = 4;
		break;
		
		case "Fencing": // Среднее оружие
			priceMod = 5;
		break;
		
		case "FencingHeavy": // Тяжелое оружие
			priceMod = 7;
		break;
	}
	if(CheckAttribute(item, "Weight") && stf(item.Weight) > 0.0)
	{
		item.price = priceMod * (stf(item.dmg_min) * stf(item.dmg_max)) / stf(item.Weight);
	}	
}
*/

// Создадим предмет, вернет АйДи нового предмета
String GenerateItem(String _itemId)
{
	int i, defItemIndex, priceMod;
	int itemsQty = 0;
	int itemIndex = FindFirstEmptyItem();
	float MaxAttack = 0.0;
	ref item, realItem;
	String generatedItems[TOTAL_ITEMS];
	
	if(!IsGenerableItem(_itemId)) // Генерящийся ли предмет
	{
		return _itemID;
	}
	
	if(itemIndex == -1) // Нету свободных слотов - вернем случайный существующий
	{
		for(i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
		{
			if(CheckAttribute(&Items[i], "DefItemID") && Items[i].DefItemID == _itemId)
			{
				generatedItems[itemsQty] = Items[i].ID;
				itemsQty++;
			}
		}
		
		if(itemsQty == 0)
		{
			return _itemId; // Ничего не нашлось
		}
		
		return generatedItems[rand(itemsQty - 1)];
	}
	
	defItemIndex = GetItemIndex(_itemId);
	item = &Items[defItemIndex];
	realItem = &Items[itemIndex];
	
	CopyAttributes(realItem, item); // Копируем аттрибуты
	
	switch (realItem.FencingType) 
	{
		case "FencingL" :
			realItem.Weight 	= 2.0 + fRandSmall(1.0); 
			MaxAttack			= FencingL_MaxAttack;
		break;
		case "FencingS" :
			realItem.Weight 	= 2.4 + fRandSmall(1.2);
			MaxAttack			= FencingS_MaxAttack;			
		break;
		case "FencingH" :
			realItem.Weight 	= 3.0 + fRandSmall(1.5); 
			MaxAttack			= FencingH_MaxAttack;
		break;
	}
	
	realItem.Balance = fRandSmall(2.0);
	
	switch (sti(realItem.quality))
	{
		case B_POOR :
			realItem.Attack 	= MaxAttack * (42.5 + fRandSmall(15.0))/100.0;			
		break;
		case B_ORDINARY :
			realItem.Attack 	= MaxAttack * (55.0 + fRandSmall(15.0))/100.0;
		break;
		case B_GOOD :
			realItem.Attack 	= MaxAttack * (70.0 + fRandSmall(15.0))/100.0;
			if(realItem.target == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				realItem.Attack 	= MaxAttack * 0.85;	
			}
		break;
		case B_EXCELLENT :
			realItem.Attack 	= MaxAttack * (85.0 + fRandSmall(15.0))/100.0;
			if(realItem.target == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				realItem.Attack 	= MaxAttack;	
			}
		break;
	}
	
	switch (realItem.FencingType) 
	{
		case "FencingL" :
			if(sti(realItem.Generation.price)) 
			{
				realItem.price  = makeint(35.0 * (1.0/stf(realItem.curve) + stf(realItem.lenght)) * (stf(realItem.Attack) * 2.0 - 30.0));
			}	
		break;
		case "FencingS" :
			if(sti(realItem.Generation.price)) 
			{
				realItem.price  = makeint(25.0 * (stf(realItem.curve) + stf(realItem.lenght)) * (stf(realItem.Attack) * 2.0 - 40.0));
			}	
		break;
		case "FencingH" :
			if(sti(realItem.Generation.price)) 
			{
				realItem.price  = makeint(20.0 * ((stf(realItem.curve) + 1.0) * 1.0/stf(realItem.lenght)) * (stf(realItem.Attack) * 2.0 - 50.0));
			}	
		break;
	}	

	realItem.ID = _itemId + "_" + itemIndex; // Новый АйДи предмету
	realItem.Index = itemIndex; // Новый индекс
	realItem.Generated = true; // Сгенерированный предмет
	realItem.DefItemID = _itemId; // Запомним АйДи и индекс начального предмета
	realItem.DefItemIndex = defItemIndex;
	
	return realItem.ID;
}

// Найдем первый пустой слот для предмета
int FindFirstEmptyItem()
{
	for(int i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
	{
		if(!CheckAttribute(&Items[i], "ID") || Items[i].ID == "0")
		{
			return i;
		}
	}	
	return -1;
}

// Проверим на пустые предметы и удалим их
// Метод выполняется долго - лучше вызывать его при переходах между локациями (как щас и сделано)
void RefreshGeneratedItems()
{
	ref item;
	int curLastIndex = FindFirstEmptyItem();

	for(int i = ITEMS_QUANTITY; i < TOTAL_ITEMS; i++)
	{
		item = &Items[i];
		
		if(!CheckAttribute(item, "ID")) continue; // Пустой слот
		
		RefreshGeneratedItem(item.ID);
	}
	
	trace("Произведено удаление пустых предметов");
	trace("Первый свободный элемент (было/стало) == (" + curLastIndex + "/"+ FindFirstEmptyItem() + ")");
}

// Метод рефреша для конкретного предмета. Вернет булево значение - удалился предмет или нет
bool RefreshGeneratedItem(String _itemID)
{
	int i, j;
	int itemIndex = GetItemIndex(_itemID);
	String curSimpleBox, curPrivateBox;
	ref reference;
	
	if(itemIndex == -1) return false;

	for(i = 0; i < nLocationsNum; i++)
	{
		reference = &Locations[i];
		
		for(j = 1; j < MAX_HANDLED_BOXES; j++)
		{
			curSimpleBox = "box" + j;
			curPrivateBox = "private" + j;
			
			if(!CheckAttribute(reference, curSimpleBox) && !CheckAttribute(reference, curPrivateBox)) break;
			
			// Симпл боксы
			if(CheckAttribute(reference, curSimpleBox + ".Items." + _itemID))
			{
				return false;
			}
			
			// Приваты
			if(CheckAttribute(reference, curPrivateBox + ".Items." + _itemID))
			{
				return false;
			}
		}
	}
	
	for(i = 0; i < TOTAL_CHARACTERS; i++)
	{
		reference = &Characters[i];
			
		// Проверка на торговца, у которого уже можно отобрать предметы
		if(CheckAttribute(reference, "Merchant") && CheckNPCQuestDate(reference, "Item_date"))
		{
			DeleteAttribute(reference, "items");
			continue;
		}
		
		if(CheckAttribute(reference, "Items." + _itemID))
		{
			return false;
		}
	}
		
//	DeleteAttribute(&Items[itemIndex], ""); // Потрем все аттрибуты
	return true;
}

// Проверка, уникален ли каждый предмет "серии", или же идентичен
bool IsGenerableItem(String _itemID)
{
	int itemIndex = GetItemIndex(_itemID);
	ref itemRef;
	
	if(itemIndex == -1)
	{
		return false;
	}
	
	itemRef = &Items[itemIndex];
	
	if(CheckAttribute(itemRef, "Generation") && !CheckAttribute(itemRef, "Generated"))
	{
		return true;
	}
	
	return false;
}

string SelectGeneratedItem(string TargetGroup, string Quality, string BladeType)
{
	ref item;
	int itemsQty = 0;
	string generatedItems[TOTAL_ITEMS];
	bool bOk1, bOk2, bOk3;
	
	if(TargetGroup == "" && Quality == "" && BladeType == "") return "";
	
	for(int i = 0; i < ITEMS_QUANTITY; i++)
	{
		item = &Items[i];
		if(CheckAttribute(item, "groupID") && (item.groupID == BLADE_ITEM_TYPE))
		{		
			bOk1 = item.target == TargetGroup || TargetGroup == "";
			bOk2 = item.quality == Quality || Quality == "";
			bOk3 = item.FencingType == BladeType || BladeType == "";
		
			if(bOk1 && bOk2 && bOk3)
			{
				generatedItems[itemsQty] = Items[i].ID;
				itemsQty++;
			}
		}	
	}

	if(itemsQty == 0)
	{
		return ""; // Ничего не нашлось
	}
		
	return generatedItems[rand(itemsQty - 1)];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//										<-- Warship НОВАЯ СИСТЕМА ПРЕДМЕТОВ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Warship Проверка на оружие
bool IsBlade(String _itemID)
{
	int itemIndex = GetItemIndex(_itemID);
	ref item;
	
	if(itemIndex == -1)
	{
		return false;
	}
	
	item = &Items[itemIndex];

	if(CheckAttribute(&item, "groupID"))
	{
		if(item.groupID == BLADE_ITEM_TYPE)
		{
			return true;
		}
	}
	
	return false;
}

// eddy -->
/////////////////////// ==> Items-методы
int GetItemIndex(string _ItemID)
{
	return FindItem(_ItemID);
}

ref ItemsFromID(string _Items)
{
	if(GetItemIndex(_Items) == -1) 
	{
		trace("Bad index for item : " + _Items);
	}
	return &items[GetItemIndex(_Items)];
}

void ChangeItemDescribe(string _Items, string _Describe)
{
    Items[GetItemIndex(_Items)].describe = _Describe;
}

void BackItemDescribe(string _Items)
{
    ref ItemAR = ItemsFromID(_Items);
    ItemAR.describe = "itmdescr_" + ItemAR.id;
}

void ChangeItemName(string _Items, string _Name)
{
    Items[GetItemIndex(_Items)].name = _Name;
}

void BackItemName(string _Items)
{
    ref ItemAR = ItemsFromID(_Items);
    ItemAR.name = "itmname_" + ItemAR.id;
}
///////////////////////  Items-методы <--


void QuestCheckEnterLocItem(aref _location, string _locator) /// <<<проверка вхождения ГГ в локаторы группы Item.<<<
{
	ref sld;
	int i;

	//======> Генератор инквизиции.
	if (_location.id == "Santiago_Incquisitio" && CheckNPCQuestDate(_location, "AttackGuard_date") && sti(Colonies[FindColony(_location.fastreload)].nation) == SPAIN && findsubstr(_locator, "detector" , 0) != -1) 
	{
		SetNPCQuestDate(_location, "AttackGuard_date"); //одна засада в день.
		LAi_group_AttackGroup("SPAIN_CITIZENS", LAI_GROUP_PLAYER);
		StartIncquisitioAttack();
		//==>Гот.линейка, квест. Горн, даем диалог.
		if (pchar.questTemp.GothicLee == "RockBras_toSeekPlace") LAi_ActorWaitDialog(characterFromId("Gorn"), pchar);
		TakeNationLicence(HOLLAND);
		log_info("Торговая лицензия аннулирована!");
	}

	//======> установка метки нахождения в локаторе item1 в погребке
	if (pchar.questTemp.LSCC == "toInterception" && _location.id == "FleuronTavernn" && _locator == "detector1")
	{        
		pchar.questTemp.LSCC.itemState = true;
	}

	//======> Генератор маяка Порт Рояля.
	if (_location.id == "Mayak3") 	
	{
		int iNation = GetCityNation(GetCityNameByIsland(GiveArealByLocation(_location)));
		if(iNation == -1) return;
		string sGroup = GetNationNameByType(iNation)  + "_mayak";
		LAi_group_AttackGroup(sGroup, LAI_GROUP_PLAYER);
	}

	//======> детектор в тюрьме, вторжение без разрешения
	if (_location.type == "jail" && !sti(pchar.questTemp.jailCanMove) && _locator == "detector1")
	{	
		pchar.questTemp.jailCanMove = true; //чтобы не срабатывало 2 раза
		if (!LAi_grp_alarmactive && !IsLocationCaptured(_location.id))
		{
			string slai_group = GetNationNameByType(GetCityNation(_location.parent_colony)) + "_citizens";
			LAi_group_AttackGroup(slai_group, LAI_GROUP_PLAYER);
			LAi_SetFightMode(pchar, true);
		}
	}
	// Jason -------------------- локатор-детектор у рудника бандитов -----------------------------------
	if (_location.id == "Mine_01" && CheckAttribute(_location, "mine_bandits") && _locator == "detector1")
	{	
		DoQuestCheckDelay("Saga_MineBanditsTalk", 0.5);
	}
	// Jason -------------------- локаторы parol и underwater в LSC -----------------------------------
	// проверяем пароль нарвалов - КПП Сан-Габриэль
	bool bTalk;
	if (_locator == "parol1")
	{
		bTalk = (!CheckAttribute(pchar, "questTemp.LSC.parol_nrv")) && (!CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) && (!LAi_group_IsEnemy(pchar, &Characters[GetCharacterIndex("NarvalProt_2")]));
		if (bTalk || CheckAttribute(pchar, "GenQuest.NarvalConflict"))
		{
			DoQuestCheckDelay("hide_weapon", 0.5);
		sld = characterFromId("NarvalProt_2");
		LAi_SetActorType(sld);
		LAi_ActorDialogNow(sld, pchar, "", -1);
	}
	}
	// проверяем пароль ривадос - КПП Фурия
	if (_locator == "parol2")
	{
		bTalk = (!CheckAttribute(pchar, "questTemp.LSC.parol_rvd")) && (!CheckAttribute(pchar, "rvd_friend")) && (!LAi_group_IsEnemy(pchar, &Characters[GetCharacterIndex("RivadosProt_6")]));
		if (bTalk || CheckAttribute(pchar, "GenQuest.RivadosConflict"))
		{
			DoQuestCheckDelay("hide_weapon", 0.5);
		sld = characterFromId("RivadosProt_6");
		LAi_SetActorType(sld);
		LAi_ActorDialogNow(sld, pchar, "", -1);
	}
	}
	// проверяем пароль ривадос - КПП Веласко
	if (_locator == "parol3")
	{
		bTalk = (!CheckAttribute(pchar, "questTemp.LSC.parol_rvd")) && (!CheckAttribute(pchar, "rvd_friend")) && (!LAi_group_IsEnemy(pchar, &Characters[GetCharacterIndex("RivadosProt_8")]));
		if (bTalk || CheckAttribute(pchar, "GenQuest.RivadosConflict"))
		{
			DoQuestCheckDelay("hide_weapon", 0.5);
		sld = characterFromId("RivadosProt_8");
		LAi_SetActorType(sld);
		LAi_ActorDialogNow(sld, pchar, "", -1);
	}
	}
	// стучимся в дверь к Натаниэлю Хоуку на Диффиндур - это прикол такой, чтобы диалоги читали :)
	if (_locator == "parol4" && CheckAttribute(pchar, "questTemp.LSC.DiffIndoor"))
	{
		sld = &Locations[FindLocation("LostShipsCity_town")];
		if(CheckAttribute(sld, "diffIndoor") && GetNpcQuestPastDayParam(sld, "knock_date") > 0) DeleteAttribute(sld, "diffIndoor");
		if (!CheckAttribute(sld, "diffIndoor"))
		{
			SaveCurrentNpcQuestDateParam(sld, "knock_date");
			DoQuestCheckDelay("TalkSelf_Quest", 0.1);
			sld.diffIndoor = true;
		}
	}
	// проверка возможности погружения с платформы Феникс
	if (_locator == "underwater" && CheckAttribute(pchar, "questTemp.LSC.immersion") && IsEquipCharacterByItem(pchar, "underwater") && stf(environment.time) >= 7.00 && stf(environment.time) < 21.00)
	{
		PlaySound("Sea Battles\bolshoy_vsplesk_002.wav");
		DoQuestReloadToLocation("underwater", "reload", "reload1", "");
	}

	// проверка возможности погружения с платформы Феникс по ГПК
	if (_locator == "underwater" && CheckAttribute(pchar, "questTemp.LSCC.immersion") && IsEquipCharacterByItem(pchar, "underwater") && stf(environment.time) >= 7.00 && stf(environment.time) < 21.00)
	{
		PlaySound("Sea Battles\bolshoy_vsplesk_002.wav");
		DoQuestReloadToLocation("underwaterr", "reload", "reload1", "");
	}

	// Jason --------------------огненные и водные локаторы на рифе -----------------------------------
	if (_location.id == "Shore67")
	{	
		if (CheckAttribute(_location, "hell_fire_1"))
		{
			for (i=1; i<=25; i++)
			{
				if (_locator == "fire"+i) MakeHellFireDamage();
			}
			for (i=1; i<=5; i++)
			{
				if (_locator == "splash"+i)
				{
					iGlobalTemp = i;
					MakeHellSplashDamage();
				}
			}
		}
		if (CheckAttribute(_location, "hell_fire_2"))
		{
			for (i=26; i<=40; i++)
			{
				if (_locator == "fire"+i) MakeHellFireDamage();
			}
		}
	}
	// пасхальные приколы :)
	if (findsubstr(_location.id, "Graveyard" , 0) != -1)
	{
		for (i=1; i<=9; i++)
		{
			if (_locator == "read"+i) ShowRipInscription(i, _location.id);
		}
	}
	// локатор на базе мальтийцев
	if (CheckAttribute(pchar, "questTemp.Sharlie.DefendSP.SeekKey") && _location.id == "FortFrance_Dungeon" && _locator == "key")
    {
		DefendSP_OpenMishelleCasemate();
	}
	// палуба галеона
	if (CheckAttribute(pchar, "questTemp.Guardoftruth.Attack") && _location.id == "Deck_Galeon_Ship")
    {
		for (i=1; i<=8; i++)
		{
			string sNum = "num"+i;
			if (_locator == "kick"+i && !CheckAttribute(pchar, "questTemp.Guardoftruth.Attack.num"+i+".kick") && !LAi_CheckFightMode(pchar))
			{
				pchar.questTemp.Guardoftruth.num = i;
				LAi_SetActorType(pchar);
				sld = characterFromId("GuardOT_galeonguard_"+i);
				LAi_ActorTurnToCharacter(pchar, sld);
				LAi_ActorAnimation(pchar, "attack_break_1", "", 1.1);
				DoQuestFunctionDelay("GuardOT_KickGuard", 1.1);
				pchar.questTemp.Guardoftruth.Attack.(sNum).kick = true;
			}
		}
	}
	// локаторы вспышек в гроте Стража
	if (_location.id == "shore_mask")
	{
		if (CheckAttribute(pchar, "questTemp.Ksochitam.GuardMaskFire"))
		{
			if (_locator == "fire"+(sti(pchar.questTemp.Ksochitam.GuardMaskFire.l1)) || _locator == "fire"+(sti(pchar.questTemp.Ksochitam.GuardMaskFire.l2)) || _locator == "fire"+(sti(pchar.questTemp.Ksochitam.GuardMaskFire.l3)) || _locator == "fire"+(sti(pchar.questTemp.Ksochitam.GuardMaskFire.l4)) || _locator == "fire"+(sti(pchar.questTemp.Ksochitam.GuardMaskFire.l5)))
			{
				LaunchIncasFire(pchar, true);
				LAi_ApplyCharacterDamage(pchar, MOD_SKILL_ENEMY_RATE*30, "other");
				LAi_CheckKillCharacter(pchar);				
			}			
		}
		if (CheckAttribute(pchar, "questTemp.Ksochitam.GuardMaskFight"))
		{
			for (i=1; i<=4; i++)
			{
				if (_locator == "incasfire"+i)
				{
					CreateLocationParticles("fire_incas_Simple", "item", "incasfire"+i, 0, 0, 0, "fortfire");
					LaunchIncasFire(pchar, true);
					LAi_ApplyCharacterDamage(pchar, 500, "other");
					LAi_CheckKillCharacter(pchar);				
				}
			}
		}
	} 	// 270812
	// локаторы защиты в большом храме
	if (_location.id == "Temple_great")
    {
		if (CheckAttribute(pchar, "questTemp.Tieyasal.Defend") && _locator == "defend1") Tieyasal_TempleDefendActivation();
		if (CheckAttribute(pchar, "questTemp.Tieyasal.LockLadder") && _locator == "defend2") Tieyasal_TempleDefendActivation();
		if (CheckAttribute(pchar, "questTemp.Tieyasal.Shooter") && _locator == "defend3") Tieyasal_TempleDefendActivation();
		if (CheckAttribute(pchar, "questTemp.Tieyasal.LockGate") && _locator == "defend4") Tieyasal_TempleDefendActivation();
	}
	// калеуче - головоломки 'девять каменных плит' и 'шесть рычагов'
	if (_location.id == "labirint_3")
    {
		if (CheckAttribute(pchar, "questTemp.Caleuche.NextTile") && findsubstr(_locator, "step" , 0) != -1)
		{
			if (_locator == pchar.questTemp.Caleuche.NextTile) Caleuche_NineStoneTiles();
			else Caleuche_NineStoneDelete();
		}
		if (CheckAttribute(pchar, "questTemp.Caleuche.LeverL") && findsubstr(_locator, "column1" , 0) != -1)
		{
			pchar.questTemp.Caleuche.Lever.Count = sti(pchar.questTemp.Caleuche.Lever.Count)+1;
			pchar.questTemp.Caleuche.Lever.Locator = _locator;
			Caleuche_ThreeLeverAim();
		}
		if (CheckAttribute(pchar, "questTemp.Caleuche.LeverR") && findsubstr(_locator, "column2" , 0) != -1)
		{
			pchar.questTemp.Caleuche.Lever.Count = sti(pchar.questTemp.Caleuche.Lever.Count)+1;
			pchar.questTemp.Caleuche.Lever.Locator = _locator;
			Caleuche_SixLeverAim();
		}
	}

	// Addon 2016-1 Jason Пиратская линейка
	if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution.Fire") && _location.id == "Carataska_jungle_02")
    {
		if (_locator == "fire") Mtraxx_RetributionBurn();
	}
	if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution.DoorOpen") && _location.id == "Judgement_dungeon_05" && CheckCharacterItem(pchar, "key_scotland"))
    {
		if (_locator == "key")
		{
			RemoveItems(pchar, "key_scotland", 1);
			PlaySound("interface\key.wav");
			DeleteAttribute(pchar, "questTemp.Mtraxx.Retribution.DoorOpen");
			LocatorReloadEnterDisable("Judgement_dungeon_05", "reload2", false);
			DoQuestReloadToLocation("Judgement_dungeon_06", "reload", "reload1", "Mtraxx_RetributionDoorOpen");
		}
	}
	if (_location.id == "Judgement_dungeon_09") // адские туннели-1
    {
		if (_locator == "detector1")
		{
			DeleteAttribute(pchar, "GenQuest.Hotwater");
		}
		if (_locator == "detector2")
		{
			pchar.GenQuest.Hotwater = true;
			DoQuestFunctionDelay("Mtraxx_RetributionHellHotWater", 0.5);
			DoQuestFunctionDelay("Mtraxx_RetributionHellCough", 5.0);
		}
		if (findsubstr(_locator, "fontain" , 0) != -1)
		{
			i = 30+MOD_SKILL_ENEMY_RATE*4;
			PlaySound("People\hotwater1.wav");
			LAi_ApplyCharacterDamage(pchar, i, "other");
			LAi_CheckKillCharacter(pchar);
		}
		if (findsubstr(_locator, "smoke" , 0) != -1)
		{
			i = rand(3)+1;
			PlaySound("ambient\land\cough_0"+i+".wav");
			i = 20+MOD_SKILL_ENEMY_RATE*2;
			LAi_ApplyCharacterDamage(pchar, i, "other");
			LAi_CheckKillCharacter(pchar);
		}
		if (CheckAttribute(pchar, "questTemp.Mtraxx.HellSplash"))
		{
			if (_locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l1)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l2)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l3)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l4)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l5)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l6)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l7)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l8)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l9)) || _locator == "splash"+(sti(pchar.questTemp.Mtraxx.HellSplash.l10)))
			{
				Mtraxx_RetributionHellSplashReaction();			
			}		
		}
	}

	if (_location.id == "Judgement_dungeon_10") // адские туннели-2
    {
		if (_locator == "detector1" && !CheckAttribute(pchar, "GenQuest.Hotwater"))
		{
			pchar.GenQuest.Hotwater = true;
		}
		if (findsubstr(_locator, "fontain" , 0) != -1)
		{
			Mtraxx_RetributionHellSplashReaction();
		}
		if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash"))
		{
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l1"))
			{
				if (_locator == "splash1_1" || _locator == "splash1_2" || _locator == "splash1_3") Mtraxx_RetributionHellSplashReaction();	
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l2"))
			{
				if (_locator == "splash2_1" || _locator == "splash2_2" || _locator == "splash3_3") Mtraxx_RetributionHellSplashReaction();	
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l3"))
			{
				if (_locator == "splash3_1" || _locator == "splash3_2" || _locator == "splash3_3") Mtraxx_RetributionHellSplashReaction();	
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l4"))
			{
				if (_locator == "splash4_1" || _locator == "splash4_2" || _locator == "splash4_3") Mtraxx_RetributionHellSplashReaction();	
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l5"))
			{
				if (_locator == "splash5_1" || _locator == "splash5_2" || _locator == "splash5_3") Mtraxx_RetributionHellSplashReaction();	
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l6") && _locator == "splash6") Mtraxx_RetributionHellSplashReaction();	
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Hell1Splash.l7") && _locator == "splash7") Mtraxx_RetributionHellSplashReaction();	
		}
	}
}


void QuestCheckExitLocItem(aref _location, string _locator) /// <<<проверка выхода ГГ из локаторов группы Item.<<<
{

	//=======> Квест Аскольда, нашли гробницу.
    if (_location.id == "Guadeloupe_Cave" && _locator == "detector1")
    {
        if (pchar.questTemp.Ascold == "Ascold_SeekGrave" || pchar.questTemp.Ascold == "Ascold_CantSeekGrave")
        {
            Log_QuestInfo("Прерывание на нахождение входа в пещеру сработало.");
            pchar.questTemp.Ascold = "Ascold_NotEnterFoundGrave";
    		DoQuestCheckDelay("TalkSelf_Quest", 0.1); //диалог сам-на-сам
        }
    }

	//=======> Квест Аскольда, ГГ добрался до мумии, но бутылки еще не имеет. Вместо прерывания на локатор.
    if (_location.id == "Guadeloupe_Cave" && _locator == "button02")
    {
		if (pchar.questTemp.Ascold == "Ascold_SeekRockLetter" || pchar.questTemp.Ascold == "Ascold_EnterGrave")
		{
			pchar.questTemp.Ascold = "Ascold_FoundMummy";
			characters[GetCharacterIndex("Ascold")].dialog.currentnode = "Found_Grave";
		}
	}

	//=======> Энкаунтеры заманухи в пещеру, открываем закрытый релоад на колодце.
    if (_locator == "CheckReload1" && CheckAttribute(pchar, "GenQuest.OpenTheRopeExit") && pchar.GenQuest.OpenTheRopeExit == pchar.location)
    {
		DeleteAttribute(pchar, "GenQuest.OpenTheRopeExit");
		LocatorReloadEnterDisable(pchar.location, "reload2", false);
	}
}

	//=======> Пиратка, квест №5
    if (_location.id == "Pirates_houseSp1" && pchar.questTemp.piratesLine == "PL5Hunter_exitReload")
    {
		pchar.questTemp.piratesLine = "PL5Hunter_executeReload";
		StartQuestMovie(true, true, true);
		SetMainCharacterIndex(GetCharacterIndex("Orry"));
        PChar   = GetMainCharacter();			
		locCameraToPos(1.34, 2.1, 1.68, false);
		LAi_SetActorType(CharacterFromID("Aivory"));
		LAi_SetActorType(pchar);
		SetActorDialogAny2Pchar("Aivory", "", 3.0, 0.0);
		LAi_ActorFollow(PChar, CharacterFromID("Aivory"), "ActorDialog_Any2Pchar", 4.0);
	}

	//======> установка метки нахождения в локаторе item1 в погребке
	if (pchar.questTemp.LSCC == "toInterception" && _location.id == "FleuronTavernn" && _locator == "detector1")
	{        
		pchar.questTemp.LSCC.itemState = false;
	}

void QuestCheckUseButton(aref _location, string _locator, string _itemId) /// <<< квестовые действия при установке предметов в button <<<
{
	// календарь майя 270812
	if (_location.id == "Pearl_Jungle_03" && _locator == "button01")
    {
		PlaySound("Ambient\Teno_inside\big_ring.wav");
		CreateLocationParticles("fire_incas_Simple", "item", "dolly1", 1.15, 0, 0, "");
		SetItemModelOnLocation(_location, "calendar", "dolly1");
		DeleteAttribute(pchar, "questTemp.NotTeleportation");
		pchar.questTemp.Dolly_Tieyasal = "true";
		AddQuestRecord("Tieyasal", "18");
    }
	// скрижали богов майя
	if (_location.id == "Temple_great")
    {
		if (_locator == "button01") // солнце
		{
			PlaySound("Ambient\Teno_inside\big_ring.wav");
			CreateLocationParticles("shadowstar", "item", "button01", 2, 0, 0, "");
			_location.sun = true;
			SetItemModelOnLocation(_location, "totem_14", _locator);
			Tieyasal_CheckThreeTablets();
		}
		if (_locator == "button02") // вода
		{
			PlaySound("Ambient\Teno_inside\big_ring.wav");
			CreateLocationParticles("fountain", "item", "button02", 2, 0, 0, "");
			_location.rain = true;
			SetItemModelOnLocation(_location, "totem_8", _locator);
			Tieyasal_CheckThreeTablets();
		}
		if (_locator == "button03") // огонь
		{
			PlaySound("Ambient\Teno_inside\big_ring.wav");
			CreateLocationParticles("torch", "item", "button03", 2, 0, 0, "");
			_location.fire = true;
			SetItemModelOnLocation(_location, "totem_3", _locator);
			Tieyasal_CheckThreeTablets();
		}
		if (_locator == "button04") // для маски
		{
			PlaySound("Ambient\Teno_inside\big_ring.wav");
			Tieyasal_MaskTerminationStart();
		} // 010912
    }
	if (_location.id == "Tenochtitlan" && _locator == "button01") // открываем круглый храм
    {
		LocatorReloadEnterDisable("Tenochtitlan", "reloadTemple31", false);
		SetItemModelOnLocation(_location, "totem_7", _locator);
		PlaySound("Ambient\Teno_inside\big_ring.wav");
		Log_Info("Открыт храм Кукулькана");
		AddQuestRecord("Tieyasal", "30");
	}
	if (_location.id == "Temple_2" && _locator == "button01") // 
    {
		PlaySound("Ambient\Teno_inside\big_ring.wav");
		SetItemModelOnLocation(_location, "totem_11", _locator);
		pchar.questTemp.Tieyasal.wartotem = "true";
		Tieyasal_CheckTwoTablets();
	}
	if (_location.id == "Temple_6" && _locator == "button01") // 
    {
		PlaySound("Ambient\Teno_inside\big_ring.wav");
		SetItemModelOnLocation(_location, "totem_10", _locator);
		pchar.questTemp.Tieyasal.tradetotem = "true";
		Tieyasal_CheckTwoTablets();
	}
	// калеуче
	if (_location.id == "Treasure_Alcove" && _locator == "button01")
    {
		PlaySound("Ambient\Teno_inside\big_ring.wav");
		SetItemModelOnLocation(_location, "skullaztec", _locator);
		if (CheckAttribute(pchar, "questTemp.Caleuche.QuestionFail")) Caleuche_PutSkull();
		else Caleuche_GiveGrant();
    }

    //==> Квест Аскольда, вскрытие лампы и появление Аззи на верфи 
    if (_location.id == (pchar.questTemp.Ascold.ShipyarderColony + "_shipyard") && _locator == "button01")
    {
		LAi_SetActorType(PChar);
		DoQuestCheckDelay("TalkSelf_Quest", 0.2);
    }

	//==> Пиратка, квест №7
    if (_location.id == "Vestpunt_town" && _locator == "button01")
    {
		ref loc = &locations[FindLocation("Vestpunt_townhall")];
		loc.reload.l2.name = "reload2";
		loc.reload.l2.go = "Vestpunt_town";
		loc.reload.l2.emerge = "reload9";
		loc.reload.l2.autoreload = "0";
		loc.reload.l2.label = "Street";
		DoQuestFunctionDelay("PQ7_loadToRecidence", 2.0);
	}

	//установки тотемов в храмах
    if (findsubstr(_location.id == "Tenochtitlan_1" && _itemId, "Totem_" , 0) != -1)
    {
		SetItemModelOnLocation(_location, _itemId, _locator);
		SetAztecUsedTotem(_location, _itemId, _locator);
	}

	//открываем доступ в храм к шотгану
	if (_location.id == "Tenochtitlan_1" && _itemId == "KnifeAztecs") // открываем круглый храм
    {
		SetItemModelOnLocation(_location, _itemId, _locator);
		LocatorReloadEnterDisable("Tenochtitlan_1", "reloadTemple31", false);
	}

}
//проверка взятия предметов из локатора item
void QuestCheckTakeItem(aref _location, string _itemId)
{
	//генератор - "Спихнуть судовые документы" 
	if (_itemId == "CaptainBook")
	{
		ReOpenQuestHeader("GiveShipLetters");
		AddQuestRecord("GiveShipLetters", "1");			
		AddQuestUserData("GiveShipLetters", "sSex", GetSexPhrase("","а"));			
	}
	//квест поиски кольца мэра в борделях
	if (_itemId == "MayorsRing")
	{
		AddQuestRecord("SeekMayorsRing", "6");
		AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + pchar.questTemp.different.TakeMayorsRing.city + "Gen"));
	}
	// скрижали майя 010912
	if (findsubstr(_itemId, "Tablet" , 0) != -1)
	{
		ref sld = ItemsFromID(_itemId);
		sld.shown = "0";
	}
	// Addon 2016-1 Jason Пиратская линейка
	if (_itemId == "key_ruins")
	{
		Mtraxx_RetributionLocatorRadius();
	}

	//линейка ГПК, разборки с представителем в Мариго
	if (_itemId == "letter_LSCC_1")
	{
		AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("ся","ась"));
		AddQuestUserData("ISS_PoorsMurder", "sName", pchar.questTemp.LSCC.poorName);
		DeleteAttribute(pchar, "questTemp.LSCС.poorName");
		int n = FindIsland("LostShipsCityy");
		Islands[n].visible = true;
		Islands[n].reload_enable = true;
		Islands[n].alwaysStorm = true; //живем в штормах
		Islands[n].MaxSeaHeight = 2.0;
		Islands[n].storm = true;
		Islands[n].tornado = true;
		n = GetCharacterIndex("PoorKillSponsor");
		if (n != -1 && !LAi_IsDead(&characters[n])) 
		{
		chrDisableReloadToLocation = true; 
		LAi_LocationFightDisable(loadedLocation, false);
		LAi_group_Attack(&characters[n], pchar);
		pchar.quest.PQ8_afterFight.win_condition.l1 = "NPC_Death";
		pchar.quest.PQ8_afterFight.win_condition.l1.character = "PoorKillSponsor";
		pchar.quest.PQ8_afterFight.win_condition = "OpenTheDoors";
		}
	}

	//линейка ГПК, квест со скелетом Декстера. найденный ключ адмирала
	if (_itemId == "keyPanama" && CheckAttribute(pchar, "questTemp.LSCC.lostDecster") && pchar.questTemp.LSCC.lostDecster == "admiralLostKey")
	{
 	               PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
		pchar.quest.LSCC_admiralFoundOwnKey.over = "yes"; //снимаем таймер
		AddQuestRecord("LSCC_findDekster", "12");
		CloseQuestHeader("LSCC_findDekster");
		pchar.questTemp.LSCC.lostDecster = "over";
	}

	//взятие нефритового черепа
	if (_itemId == "SkullAztecs")
	{
	DoQuestFunctionDelay("LoginDeadmansGod", 0.2);
	}
}

void StartIncquisitioAttack()
{
	ref sld;
    for (int i=1; i<=5; i++)
    {
		sld = GetCharacter(NPC_GenerateCharacter("IncqAddGuard_"+i, "Paladin_"+(rand(10)+1), "man", "man2", 35, SPAIN, 1, true, "soldier"));
		FantomMakeCoolFighter(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+15, 100, 100, "newblade15", "pistol11", "bullet", 100);//спецназ
        LAi_SetWarriorType(sld);
        LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");            
        ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio", "goto", LAi_FindRandomLocator("goto"));
    }
}

void SetItemModelOnLocation(ref loc, string model, string locator)
{
	loc.models.always.totem = model;
	loc.models.always.totem.locator.group = "item";
	loc.models.always.totem.locator.name = locator;
	loc.models.always.totem.tech = "DLightModel";
}


