// клады из ВМЛ

//  Карты сокровищ  ГЕНЕРАТОР -->
string GetIslandForTreasure()
{
	int iNum, m;
	ref Itm;
	aref arDest, arImt;
	string sAttr;
	
	m = 0;
	string sCurIsland = GetCharacterCurrentIslandId(pchar);
	makearef(arDest, NullCharacter.TravelMap.Islands);
	iNum = GetAttributesNum(arDest);
	
	string sArray[50]; // динамические массивы в Шторме не организуешь :(
	for (int i = 0; i<iNum; i++)
	{
		arImt = GetAttributeN(arDest, i);
		sAttr = GetAttributeName(arImt);
		if(CheckAttribute(&NullCharacter,"TravelMap.Islands." + sAttr + ".Treasure"))
		{
			if(sCurIsland == sAttr || CheckTreasureMaps(sAttr)) continue;
			else
			{
				sArray[m] = sAttr;
				m++;		
			}	
		}
	}
	m = rand(m-1);
	return sArray[m];
}

bool CheckTreasureMaps(string sIsland)
{
	ref Itm;
	
	if(GetCharacterItem(pchar,"mapQuest") > 0)
	{
		itm = ItemsFromID("mapQuest");
		if(CheckAttribute(itm, "MapIslId") && itm.MapIslId == sIsland) return true;
	}		
	if(GetCharacterItem(pchar,"map_full") > 0)
	{
		itm = ItemsFromID("map_full");
		if(CheckAttribute(itm, "MapIslId") && itm.MapIslId == sIsland) return true;
	}	
	return false;
}

string GetLocationForTreasure(string island)
{
    int iNum;
	aref arDest, arImt;
	string sAttr;

	makearef(arDest, NullCharacter.TravelMap.Islands.(island).Treasure);
	iNum = GetAttributesNum(arDest);
    iNum = rand(iNum-1);
    
    arImt = GetAttributeN(arDest, iNum);
	return GetAttributeName(arImt);
}

string GetBoxForTreasure(string island, string location)
{
    int iNum;
	aref arDest, arImt;
	string sAttr;

	makearef(arDest, NullCharacter.TravelMap.Islands.(island).Treasure.(location));
	iNum = GetAttributesNum(arDest);
    iNum = rand(iNum-1);
    
    arImt = GetAttributeN(arDest, iNum);
	return GetAttributeValue(arImt);  // тут не атрибут, а значеие
}

void GenerateMapsTreasure(ref item, int iProbability1, int iProbability2)
{		
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_jam")) 		item.BoxTreasure.map_jam 		= 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_cayman")) 	item.BoxTreasure.map_cayman 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_barbados")) 	item.BoxTreasure.map_barbados 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_trinidad")) 	item.BoxTreasure.map_trinidad 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_Curacao")) 	item.BoxTreasure.map_Curacao 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_martiniqua")) item.BoxTreasure.map_martiniqua = 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_dominica")) 	item.BoxTreasure.map_dominica 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_puerto")) 	item.BoxTreasure.map_puerto 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_cuba")) 		item.BoxTreasure.map_cuba 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_hisp")) 		item.BoxTreasure.map_hisp 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_nevis")) 		item.BoxTreasure.map_nevis 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_guad")) 		item.BoxTreasure.map_guad 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_antigua")) 	item.BoxTreasure.map_antigua 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_TORTUGA")) 	item.BoxTreasure.map_TORTUGA 	= 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_terks")) 		item.BoxTreasure.map_terks 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_sm")) 		item.BoxTreasure.map_sm 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_bermudas")) 	item.BoxTreasure.map_bermudas 	= 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_Pearl")) 		item.BoxTreasure.map_Pearl 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_beliz")) 		item.BoxTreasure.map_beliz 		= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_santa")) 		item.BoxTreasure.map_santa 		= 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_maine_1")) 	item.BoxTreasure.map_maine_1	= 1;
	if(rand(iProbability2) == 1 && !CheckMainHeroMap("map_maine_2")) 	item.BoxTreasure.map_maine_2 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_panama")) 	item.BoxTreasure.map_panama 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_maracaibo")) 	item.BoxTreasure.map_maracaibo 	= 1;
	if(rand(iProbability1) == 1 && !CheckMainHeroMap("map_cumana")) 	item.BoxTreasure.map_cumana 	= 1;
}

void GenerateAdmiralMapsTreasure(ref item, int abl) // Jason, адмиральские карты по 1 шт 240912
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	if (rand(abl) == 1)
	{
		string amap = SelectAdmiralMaps();
		if (amap != "") item.BoxTreasure.(amap)	= 1;
	}
}


void FillMapForTreasure(ref item)
{
    item.MapIslId   = GetIslandForTreasure();
    item.MapLocId   = GetLocationForTreasure(item.MapIslId);
    item.MapBoxId   = GetBoxForTreasure(item.MapIslId, item.MapLocId);
    item.MapTypeIdx = rand(2);

    // генерим клад
	DeleteAttribute(item, "BoxTreasure");
	if (GetCharacterSPECIALSimple(pchar, SPECIAL_L) > rand(10)) FillBoxForTreasure(item, rand(1));
    else FillBoxForTreasure(item, rand(3));
    FillBoxForTreasureAddition(item);

    if (!CheckAttribute(Pchar, "GenQuest.TreasureBuild"))
    {
        if (rand(12+GetCharacterSPECIALSimple(pchar, SPECIAL_L)) == 1) item.MapTypeIdx = -1;
    }
    else
    {
     FillBoxForTreasureSuper(item);
	   if (GetCharacterSPECIALSimple(pchar, SPECIAL_L) > rand(10)) FillBoxForTreasureSuper(item);
    }
    DeleteAttribute(Pchar, "GenQuest.TreasureBuild"); //сборный

    if (sti(item.MapTypeIdx) != -1)
    {
        Pchar.quest.SetTreasureFromMap.win_condition.l1          = "location";
        Pchar.quest.SetTreasureFromMap.win_condition.l1.location = item.MapLocId;
        Pchar.quest.SetTreasureFromMap.win_condition             = "SetTreasureFromMap";
		
		pchar.GenQuest.Treasure.Vario = rand(5); // определяем событие
		locations[FindLocation(item.MapLocId)].DisableEncounters = true; //энкаутеры закрыть
    }
}
void FillBoxForTreasure(ref item, int i)
{
	// определяем тип
	switch (i)
	{
		// good
		case 0:
		    if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry2 = 2 + rand(300);
	        }
	        else
	        {
	            item.BoxTreasure.jewelry3 = 10 + rand(30);
	        }
			if (rand(1) == 1)
	        {
            	item.BoxTreasure.gold_dublon = 20 + rand(1000);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_08 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_09 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade37 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade8 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_04 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_05 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_11 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_12 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade50 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade6 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade7 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade10 = 3 + rand(50);
	        }
 		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade27 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_02 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_03 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_012 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_013 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_014 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_14 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade19 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade5 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade9 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol1 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol_02 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol_03 = 3 + rand(50);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.mushket1 = 1 + rand(10);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.mushket3 = 1 + rand(10);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.spyglass2 = 2 + rand(10);
	        }
  		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.BackPack2 = 2 + rand(10);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry3 = 1 + rand(30);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry5 = 5 + rand(60);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry40 = 15 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry41 = 15 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry42 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry43 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry44 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry45 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral2 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral5 = 5 + rand(100);
	        }
	        if (rand(4) == 1 && sti(pchar.rank) >= 2)
	        {
            	item.BoxTreasure.cirass2 = 2 + rand(10);
	        }
		   if (rand(4) == 1 && sti(pchar.rank) >= 2)
	        {
            	item.BoxTreasure.cirass3 = 2 + rand(10);
	        }
		   if (rand(4) == 1 && sti(pchar.rank) >= 2)
	        {
            	item.BoxTreasure.cirass6 = 2 + rand(10);
	        }
			GenerateMapsTreasure(item, 35, 70);
			GenerateAdmiralMapsTreasure(item, 40); // 240912
	    break;
	    // best
	    case 1:
            if (rand(2) == 1)
	        {
            	item.BoxTreasure.chest = 1 + rand(140);
	        }
	        else
	        {
	            item.BoxTreasure.jewelry53 = 10 + rand(30);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.icollection = 1 + rand(40);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry1 = 15 + rand(1000);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry53 = 15 + rand(1000);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry52 = 15 + rand(1000);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_15 = 1 + rand(5);
	        }
              if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade24 = 1 + rand(5);
	        }
 		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade25 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade26 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade28 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_16 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.topor_04 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade13 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade_13 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.blade38 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade12 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade14 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.newblade15 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol11 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol6 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol2 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol02 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol_06 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol9 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.pistol_08 = 1 + rand(5);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.spyglass3 = 1 + rand(3);
	        }
	   	   if (rand(3) == 1)
	        {
            	item.BoxTreasure.BackPack3 = 1 + rand(3);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.mushket_8 = 1 + rand(3);
	        }
	 	   if (rand(3) == 1)
	        {
            	item.BoxTreasure.mushket2 = 1 + rand(3);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.cirass1 = 1 + rand(3);
	        }
		   if (rand(3) == 1)
	        {
            	item.BoxTreasure.cirass7 = 1 + rand(3);
	        }
	        if (rand(1) == 1)
	        {
            	item.BoxTreasure.jewelry6 = 5 + rand(100);
	        }
	        if (rand(3) == 1 && sti(pchar.rank) >= 2)
	        {
            	item.BoxTreasure.cirass3 = 1;
	        }
			if (rand(1) == 1)
	        {
            	item.BoxTreasure.gold_dublon = 50 + rand(300);
	        }
			if (drand(4) == 1)
			{
				item.BoxTreasure.rat_poison = 1;
			}
			GenerateMapsTreasure(item, 25, 50);
			GenerateAdmiralMapsTreasure(item, 20); // 240912
	    break;
	    // bad
	    case 2:
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.slave_01 = 20 + rand(80);
	        }
	        else
	        {
                item.BoxTreasure.newblade3 = 5 + rand(100);//fix
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.blade_07 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.blade39 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.slave_02 = 5 + rand(100);
	        }

	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.newblade11 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.newblade2 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.newblade1 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.newblade4 = 5 + rand(100);
	        }
		   if (rand(2) == 1)
	        {
            	item.BoxTreasure.newblade23 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.topor_05 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.topor_07 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.pistol_01 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.pistol3 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.blade_03 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.jewelry16 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral4 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral6 = 5 + rand(200);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral7 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral9 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral10 = 25 + rand(300);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral1 = 15 + rand(300);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral11 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral12 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral13 = 5 + rand(100);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral16 = 5 + rand(200);
	        }
	        if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral23 = 10 + rand(100);
	        }
			if (rand(2) == 1)
	        {
            	item.BoxTreasure.mineral22 = 5 + rand(50);
	        }
			if (rand(2) == 1)
	        {
            	item.BoxTreasure.spyglass1 = 3 + rand(15);
	        }
			if (rand(2) == 1)
	        {
            	item.BoxTreasure.BackPack1 = 3 + rand(15);
	        }
	        if (rand(3) == 1)
	        {
            	item.BoxTreasure.mushket_01 = 3 + rand(15);
	        }
	        if (rand(3) == 1)
	        {
            	item.BoxTreasure.cirass5 = 3 + rand(15);
	        }
			if (rand(2) == 1)
	        {
            	item.BoxTreasure.Chest_open = 1 + rand(30);
	        }
	    break;

	    case 3:
	        FillBoxForTreasure(item, 0);
	    break;
	}
}

void FillBoxForTreasureAddition(ref item)
{
    float   nLuck   = GetCharacterSkillToOld(Pchar, SKILL_FORTUNE);

    if (5*nLuck > rand(55))
    {
	    if (GetCharacterItem(Pchar, "map_part1") == 0)
	    {
	        item.BoxTreasure.map_part1 = 1;
	    }
	    else
	    {
	        if (GetCharacterItem(Pchar, "map_part2") == 0)
		    {
		        item.BoxTreasure.map_part2 = 1;
		    }
	    }
	}
	// +1 вещи
	switch (rand(40))
	{
		case 1:
		    item.BoxTreasure.gold_dublon = rand(400) + 20; // 160912
		break;
		case 2:
		    item.BoxTreasure.jewelry10 = 1;
		break;
		case 3:
		    item.BoxTreasure.jewelry11 = 1;
		break;
		case 4:
		    item.BoxTreasure.jewelry12 = 1;
		break;
		case 5:
		    item.BoxTreasure.indian_6 = 1;
		break;
		case 6:
		    item.BoxTreasure.indian_2 = 1;
		break;
		case 7:
		    item.BoxTreasure.jewelry13 = 1;
		break;
		case 8:
		    item.BoxTreasure.indian_3 = 1;
		break;
		case 9:
		    item.BoxTreasure.indian_1 = 1;
		break;
		case 10:
		    item.BoxTreasure.indian_4 = 1;
		break;
		case 11:
		    item.BoxTreasure.indian_5 = 1;
		break;
		case 12:
		    item.BoxTreasure.indian_7 = 1;
		break;
		case 13:
		    item.BoxTreasure.indian_8 = 1;
		break;
		case 14:
		    item.BoxTreasure.indian_9 = 1;
		break;
		case 15:
		    item.BoxTreasure.indian_10 = 1;
		break;
		case 16:
		    item.BoxTreasure.indian_11 = 1;
		break;
		case 17:
		    item.BoxTreasure.amulet_1 = 1;
		break;
		case 18:
		    item.BoxTreasure.amulet_2 = 1;
		break;
		case 19:
		    item.BoxTreasure.amulet_3 = 1;
		break;
		case 20:
		    item.BoxTreasure.amulet_4 = 1;
		break;
		case 21:
		    item.BoxTreasure.amulet_5 = 1;
		break;
		case 22:
		    item.BoxTreasure.Mineral14 = 1;
		break;
		case 23:
		    item.BoxTreasure.Mineral15 = 1;
		break;
		case 24:
		    item.BoxTreasure.gold_dublon = rand(40) + 20; // 160912
		break;
		case 25:
		    item.BoxTreasure.amulet_6 = 1;
		break;
		case 26:
		    item.BoxTreasure.amulet_7 = 1;
		break;
		case 27:
		    item.BoxTreasure.amulet_8 = 1;
		break;
		case 28:
		    item.BoxTreasure.gold_dublon = rand(40) + 20;
		break;
	}
	GenerateMapsTreasure(item, 10, 20);
	
}

void FillBoxForTreasureSuper(ref item)
{
    float     nLuck   = GetCharacterSkillToOld(Pchar, SKILL_FORTUNE);
	int     i;
	string  itmName;

    if (3*nLuck > rand(21))// еще поди найди 2 куска
    {
		i = 0;
		itmName = "";
		while (itmName == "" && i < 15)
		{
            switch (rand(40)) // 170912
			{
                case 0:
        			itmName = "pistol4";
				break;
				case 1:
					itmName = "spyglass6";
				break;
				case 2:
					itmName = "spyglass5";
				break;
				case 3:
					itmName = "spyglass7";
				break;
				case 4:
					itmName = "mushket5";
				break;
				case 5:
        			itmName = "talisman8";
				break;
				case 6:
                    itmName = GetGeneratedItem("blade_30");
				break;
				case 7:
        			itmName = "spyglass4";
				break;
				case 8:
        			itmName = GetGeneratedItem("blade_17");
				break;
				case 9:
        			itmName = GetGeneratedItem("blade_21");
				break;
				case 10:
        			itmName = "cirass8";
				break;
				case 11:
        			itmName = GetGeneratedItem("blade_19");
				break;
				case 12:
        			itmName = "suit4";
				break;
				case 13:
        			itmName = GetGeneratedItem("blade_18");
				break;
				case 14:
        			itmName = GetGeneratedItem("blade_20");
				break;
				case 15:
        			itmName = GetGeneratedItem("blade_18");
				break;
				case 16:
        			itmName = GetGeneratedItem("blade_27");
				break;
				case 17:
        			itmName = GetGeneratedItem("blade_26");
				break;
				case 18:
        			itmName = GetGeneratedItem("newblade20");
				break;
				case 19:
        			itmName = GetGeneratedItem("newblade16");
				break;
				case 20:
        			itmName = GetGeneratedItem("newblade17");
				break;
				case 21:
        			itmName = GetGeneratedItem("topor_021");
				break;
				case 22:
        			itmName = GetGeneratedItem("blade_06");
				break;
				case 23:
        			itmName = GetGeneratedItem("newblade21");
				break;
				case 24:
        			itmName = GetGeneratedItem("blade_28");
				break;
				case 25:
        			itmName = GetGeneratedItem("newblade18");
				break;
				case 26:
        			itmName = "cirass4";
				break;
				case 27:
        			itmName = "pistol_04";
				break;
				case 28:
        			itmName = "pistol5";
				break;
				case 29:
        			itmName = "mushket2x2";
				break;
				case 30:
        			itmName = "Mushket_9";
				break;
				case 31:
        			itmName = "pistol8";
				break;
				case 32:
        			itmName = "mushket6";
				break;	
				case 33:
        			itmName = "grape_mushket";
				break;
				case 34:
        			itmName = "BackPack4";
				break;
			}
			if (GetCharacterItem(Pchar, itmName) > 0)
		    {
          		itmName = "";
		    }
		    i++;
	    }
	    if (itmName != "")
	    {
	        item.BoxTreasure.(itmName) = 1;
	    }
		GenerateAdmiralMapsTreasure(item, 15); // 240912
	}
}

void SetTreasureBoxFromMap()
{
    aref   item;
    ref    loc;
    string box;
    aref   arToBox;
    aref   arFromBox;

    if (GetCharacterItem(Pchar, "map_full")>0 )
    {
        Log_Info("Сокровища где-то рядом!");
        PlaySound("interface\notebook.wav");
		Statistic_AddValue(Pchar, "Treasure", 1);
        // немного веселой жизни
        if (rand(1) == 0) TraderHunterOnMap();
		else CoolTraderHunterOnMap();
        if( CheckAttribute(Pchar,"location.from_sea") )
        {
            if (rand(2) == 1) //33%
            {
                Pchar.quest.SetTreasureHunter.win_condition.l1          = "location";
                Pchar.quest.SetTreasureHunter.win_condition.l1.location = Pchar.location.from_sea;
                Pchar.quest.SetTreasureHunter.win_condition             = "";
                Pchar.quest.SetTreasureHunter.function    = "SetTreasureHunter";
            }
        }

        Items_FindItem("map_full", &item);

        box = item.MapBoxId;

        loc = &locations[FindLocation(item.MapLocId)];
        loc.(box).items = "";

        makearef(arToBox, loc.(box).items);
        makearef(arFromBox, item.BoxTreasure);
        CopyAttributes(arToBox, arFromBox);

        loc.(box) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
        loc.(box).Treasure =  true; // признак сокровища в сундуке

        DeleteAttribute(item, "MapIslId");
        TakeNItems(Pchar, "map_full", -1);
    }
}
//  Карты сокровищ  ГЕНЕРАТОР <--

// погодня за ГГ на карте
void  TraderHunterOnMap()
{
    // немного веселой жизни
    ref  sld;
    int  i;

    string sCapId = "Follower0";
    string sGroup = "Sea_" + sCapId + "1";

	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 5, PIRATE, 15, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld); //крутые парни
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = "Джентльмены удачи";
		sld.hunter = "pirate";
        Group_AddCharacter(sGroup, sCapId + i);
    }

    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
    Map_CreateWarrior("", sCapId + "1", 8);
}

void CoolTraderHunterOnMap()//Jason, быстрые ДУ
{
    ref  sld;
    int  i;

    string sCapId = "Follower0";
    string sGroup = "Sea_" + sCapId + "1";

	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 8, PIRATE, 15, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld); //крутые парни
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = "Джентльмены удачи";
		sld.hunter = "pirate";
        Group_AddCharacter(sGroup, sCapId + i);
    }

    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
    Map_CreateCoolWarrior("", sCapId + "1", 8);
}

void SetTreasureHunter(string temp)
{
    int    j, i, k;
	string sTemp, sCapId;
	ref    sld;
	bool   ok;

	if (chrDisableReloadToLocation) return; // идет некий другой квест с запретом выхода
	
    Pchar.GenQuest.Hunter2Pause            = true;
    
    j = GetOfficersQuantity(Pchar) + 2;
    
	sCapId = "LandHunter0";
    sTemp = "LAND_HUNTER";
	ok = true;
	arrayNPCModelHow = 0;
    for (i = 1; i <= j; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 5, PIRATE, 0, true, "hunter"));
        SetFantomParamHunter(sld); //крутые парни
        sld.Dialog.CurrentNode = "TreasureHunter";
        sld.dialog.filename = "Hunter_dialog.c";
        sld.greeting = "hunter";
        sld.location = "none"; // вот где порылась собака!!!!!!!!!!!

        SetModelPirate(sld);
        k = 0;
		while (!CheckNPCModelUniq(sld) && k < 10)
		{
		    k++;
			SetModelPirate(sld);
		}
		arrayNPCModel[arrayNPCModelHow] = sld.model;
		arrayNPCModelHow++;
		
        LAi_SetActorTypeNoGroup(sld);
        LAi_SetCheckMinHP(sld, (LAi_GetCharacterHP(sld) - 1), false, "Battle_Hunters_Land");
        if (PlaceCharacter(sld, "goto", "random_must_be_near") == "" && i == 1) // fix если вдруг нет в локации
        {
            ok = false;
            break;
        }
        LAi_ActorFollow(sld, pchar, "", 8.0);
        //LAi_Actor2WaitDialog(sld, pchar); // ждать диалог, но бежать
        LAi_group_MoveCharacter(sld, sTemp);
    }

	LAi_group_SetRelation(sTemp, LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
	LAi_group_SetRelation(sTemp, LAI_GROUP_PLAYER_OWN, LAI_GROUP_NEITRAL);

	LAi_group_ClearAllTargets();
	LAi_SetFightModeForOfficers(false);
	if (ok)
    {
        PChar.HunterCost = makeint(sti(Pchar.money) / 5) + rand(20)*1000; //сразу генерим
        PChar.HunterCost.Qty = i;
        PChar.HunterCost.TempHunterType = "";
        sld = characterFromID(sCapId + "1");
        LAi_type_actor_Reset(sld);
        LAi_ActorDialog(sld, pchar, "", 4.0, 0);
		chrDisableReloadToLocation = true;
		DoQuestCheckDelay("OpenTheDoors", 5.0);
    }
}

ref SetFantomSkeletForts(string group, string locator, string enemygroup, string _type)
// _type = "GhostShipCrew"   _type = "ParamHunter"  _type = "none"
{
    string emodel;
    ref    Cr;

    //emodel = GetRandSkelModel();
    emodel = GetRandVaterSkelModel();

    Cr = LAi_CreateFantomCharacterEx(emodel, "man", group, locator);

    if (Cr.location.locator != "")
    {
		if (_type == "GhostShipCrew" || _type == "ParamHunter")
		{
			SetFantomParamHunter(Cr);
		}
		else
		{
		    SetFantomParam(Cr);
		}
		LAi_SetWarriorType(Cr);
	    LAi_group_MoveCharacter(Cr, enemygroup);
	    LAi_NoRebirthEnable(Cr); //не показывать убитых при входе в локацию
	    LAi_LoginInCaptureTown(Cr, true); // для записи игры
	    if (_type == "GhostShipCrew")
	    {
		    // возможно дает вылеты от многих трупов Cr.DontClearDead = true;
		    Cr.GhostShipCrew = true;
	    }
    }
    return Cr;
}

///////////////////////////////////////////   Квест летучего голландца /////////////////////////////////
// летучий голландец
void  GhostShipOnMap()
{
    int  i;
    ref  rRealShip;

                     int iRank = 20+MOD_SKILL_ENEMY_RATE*2;
                     sld = GetCharacter(NPC_GenerateCharacter("GhostCapt", "Vaterskeletcap", "man", "man", iRank, PIRATE, -1, true, "quest"));
                     sld.name 	= "Дэйви";
                     sld.lastname = "Джонс";
	sld.dialog.FileName = "Gothic_Quest\GhostShip_dialog.c";
	sld.dialog.currentnode = "GhostCapt_LastDialog";
	FantomMakeCoolSailor(sld, SHIP_FDM, "Корабль-призрак", CANNON_TYPE_CANNON_LBS42, 90, 90, 90);
	FantomMakeCoolFighter(sld, iRank, 90, 90, "blade_19", "pistol8", "GunEchin", 200);
	sld.Ship.Name = "Летучий голландец";
sld.CanTakeMushket = true;
sld.DontRansackCaptain = true;
sld.AnalizeShips = true;
sld.CoolBrander = true;
	sld.DontHitInStorm = true; // не ломается в шторм
	sld.SaveItemsForDead   = true; // сохранять на трупе вещи
	sld.DontClearDead = true;  // не убирать труп через 200с
	sld.cirassId = Items_FindItemIdx("cirass4");
	GiveItem2Character(sld, "spyglass6");
	EquipCharacterbyItem(sld, "spyglass6");
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 100, 100, 100, 100, 100); 
SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100); 
	TakeNItems(sld, "GunEchin", 50);
                     TakeNItems(sld, "harpoon", 50);
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	LAi_SetCharacterUseBullet(sld, "GunEchin");
	sld.money = 6666666;
	TakeNItems(sld, "mushket2x2", 1);
	TakeNItems(sld, "indian11", 1);
	TakeNItems(sld, "sculMa3", 1);
	TakeNItems(sld, "gold_dublon", 666);
	TakeNItems(sld, "cannabis7", 1); // мангароса
	sld.GenQuest.CrewVaterSkelMode  = true; // на абордаже рыбьи хари
sld.Ship.Mode = "Vaterskel";
sld.MultiFighter = 2.5;
sld.MultiShooter = 2.5;
sld.equip.gun = "pistol8";
sld.sex = "Skeleton"; 
sld.monster = true; 
sld.viper = true;
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
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
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
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2");
SetCharacterPerk(sld, "Doctor3");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
LAi_SetImmortal(sld, true);
sld.Abordage.Enable = false; // запрет абордажа
sld.SuperShooter  = true;
LAi_SetHP(sld, 666, 666);
AddItems(sld, "bullet", 50);
AddItems(sld, "gunpowder", 50);
SetCharacterGoods(sld, GOOD_GOLD, 228);
sld.cirassId           = Items_FindItemIdx("cirass5");
    //sld = characterFromID("GhostCapt");

    SetBaseShipData(sld);
    rRealShip = &RealShips[sti(sld.Ship.Type)];

    Ship_SetTaskNone(SECONDARY_TASK, sti(sld.index));

    if (CheckAttribute(pchar , "GenQuest.GhostShip.LastBattle"))
    {
	   SetShipSailsFromFile(sld, "ships/parus_FDM.tga");
	    rRealShip.MaxCaliber = 42;
	    rRealShip.Cannon     = CANNON_TYPE_CANNON_LBS42;
	    rRealShip.HP         = 6666;
	    rRealShip.SpeedRate = 15.5;
	    rRealShip.TurnRate   = 32.0;	
          SetBaseShipData(sld);
          sld.ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	LAi_SetImmortal(sld, false);
sld.Abordage.Enable = true; // запрет абордажа
 Character_SetAbordageEnable(sld, true);
    }
    else
    {
        sld.ship.hp = 52000; // 13%
    }

    SetCrewQuantityOverMax(sld, 666);
    sld.mapEnc.type = "war";
    sld.mapEnc.Name = "Летучий голландец";
    sld.name 	= "Дэйви";
    sld.lastname = "Джонс";
    sld.mapEnc.worldMapShip = "Flying_dutch";
				
    sld.ship.Crew.Morale = 100;
    ChangeCrewExp(sld, "Sailors", 100);
	ChangeCrewExp(sld, "Cannoners", 100);
	ChangeCrewExp(sld, "Soldiers", 100);
	SetCharacterGoods(sld, GOOD_GOLD, 228);
				
                     Fantom_SetBalls(sld, "pirate");
                     Fantom_SetCharacterGoods(sld, GOOD_BALLS,  3900 + rand(300), 0);
	Fantom_SetCharacterGoods(sld, GOOD_BOMBS,  2900 + rand(300), 0);
	Fantom_SetCharacterGoods(sld, GOOD_POWDER, 6900 + rand(300), 0);

    LAi_SetCurHPMax(sld); // если он умер

    string sGroup = "Sea_GhostCapt";  // приставка "Sea_" + ИД важна
    Group_FindOrCreateGroup(sGroup);
	Group_AddCharacter(sGroup, "GhostCapt");
    Group_SetGroupCommander(sGroup, "GhostCapt");

    SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);

    Map_CreateWarrior("", "GhostCapt", 3);
    
    Pchar.quest.GhostShip_Dead.win_condition.l1 = "NPC_Death";
	Pchar.quest.GhostShip_Dead.win_condition.l1.character = "GhostCapt";
	Pchar.quest.GhostShip_Dead.win_condition = "GhostShip_Dead";    
}

void Survive_In_Sea_Go2Land()
{
    string  sTemp;
    int     iDay;
    ref 	ch;
	int 	n, i, idx;
    int 	storeArray[30];
    int 	howStore = 0;
    
	PChar.nation = GetBaseHeroNation();
    // трем всех офов и компаньонов, не квестовых
    iDay = GetPassengersQuantity(pchar);
    i = 0;
    n = 0;
 	while (i < iDay)
	{
		i++;
		idx = GetPassenger(pchar, n); // всегда первый в массиве со смещением, если не трем
		if (idx==-1) break;
		ch = GetCharacter(idx);
		if (GetRemovable(ch)) // квестовых не трогаем
		{
		    ch.LifeDay = 1; // чтоб не сразу потерся
		    RemovePassenger(pchar, ch);
			ChangeCharacterAddress(ch,"none","");
		}
		else
		{
		    n++;
		}

	}
    for (i=0; i<COMPANION_MAX; i++)
	{
		idx = GetCompanionIndex(pchar, i);
		if (idx != -1)
		{
            ch = GetCharacter(idx);
			if (GetShipRemovable(ch) && GetRemovable(ch))  // не трогаем квестовых и ПГГ
			{
			    ch.LifeDay = 1; // чтоб не сразу потерся
			    RemoveCharacterCompanion(pchar, ch);
			}
		}
	}
	
	DeleteAttribute(pchar, "ship");
	pchar.ship.name = "";
	pchar.ship.type = SHIP_NOTUSED;
	pchar.money = 0;

	SetCharacterShipLocation(pchar, "");

	// выбор города близ бухты
    for (n = 0; n < MAX_COLONIES; n++)
	{
  		if (colonies[n].nation == "none") continue; // необитайки
  		if (sti(colonies[n].nation) == PIRATE) continue;
  		if (colonies[n].from_sea == "") continue; // необитайки
  		if (!CheckAttribute(&Colonies[n], "islandLable") || Colonies[n].islandLable == "Mein") continue; // только острова
  		
        storeArray[howStore] = n;
   		howStore++;
    }

    makeref(ch,colonies[storeArray[rand(howStore-1)]]);
    setWDMPointXZ(ch.from_sea);
    pchar.location = ch.from_sea; // это порт, ниже ищем бухту

    // нулим предметы в каюте
    ref loc;
    if (Pchar.SystemInfo.CabinType != "")
    {
	    loc = &locations[FindLocation(Pchar.SystemInfo.CabinType)]; //"My_Cabin"

	    for (n = 1; n <= 4; n++)
	    {
	        sTemp = "box" + n;
			DeleteAttribute(loc, sTemp + ".items");
		    loc.(sTemp).items = "";
		    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
		    loc.(sTemp).money = 0;
	    }
    }
    loc = &locations[FindLocation("My_Deck")];
    for (n = 1; n <= 4; n++)
    {
        sTemp = "box" + n;
		DeleteAttribute(loc, sTemp + ".items");
	    loc.(sTemp).items = "";
	    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
	    loc.(sTemp).money = 0;
    }
	Pchar.GenQuest.Hunter2Pause = true;
    iDay = 5+rand(17);
    bQuestCheckProcessFreeze = true;
    WaitDate("",0,0,iDay, rand(10), 1); // прошло время
    bQuestCheckProcessFreeze = false;
	RemoveItems(PChar, "gold_dublon", -10000000000000000000);
	RemoveItems(PChar, "Chest", -10000000000000000000);
	RemoveItems(PChar, "icollection", -10000000000000000000);
	RemoveItems(PChar, "purse1", -10000000000000000000);
	RemoveItems(PChar, "purse2", -10000000000000000000);
	RemoveItems(PChar, "purse3", -10000000000000000000);
	RemoveItems(PChar, "jewelry6", -10000000000000000000);
	RemoveItems(PChar, "jewelry10", -10000000000000000000);
	RemoveItems(PChar, "jewelry5", -10000000000000000000);
	RemoveItems(PChar, "jewelry11", -10000000000000000000);
	RemoveItems(PChar, "jewelry12", -10000000000000000000);
	RemoveItems(PChar, "jewelry13", -10000000000000000000);
    
	// бухта контры
    pchar.location = SelectSmugglingLocation();
    
    pchar.Health.Damg = stf(pchar.chr_ai.hp_max)*40;
	// дает лог в + и - AddCharacterHealth(pchar, -30);
	Log_Info("О чудо! Я жив"+ GetSexPhrase("","а") +"!");
	if (sti(PChar.GenQuest.GhostShip.KillMe) <= 1)
	{
		AddQuestRecord("GhostShipQuest", "Survive_1");
		AddQuestUserData("GhostShipQuest", "sSex", GetSexPhrase("","а"));
	}
	else
	{
	    AddQuestRecord("GhostShipQuest", "Survive_2");
	    // добавить предмет Т102
	    if (sti(PChar.GenQuest.GhostShip.KillMe) == 2)
		{
		Log_Info("Вы нашли очень странный предмет.");
		TakeNItems(Pchar, "term_arm", 1);
	    	pchar.QuestTemp.TakeShotgun = true;
	    }
	}
	sGlobalTemp = "afterFDsink";
	bDisableMapEnter           = false;   // мир, был бой с ЛГ
	
	AddSimpleRumourTip(RandPhraseSimple("Слыхал я, " + GetAddress_Form(pchar) + ", что и вас настигло это проклятье морей. Я о корабле-призраке толкую... Да-а, этот 'Голландец' сколько уж лет воды бороздит, а управы-то на него и нету - не сыскал никто. Вечное заклятье, стало быть... А вот поговаривают, что в какой-то глухой деревушке западного мейна, вроде, индеец живёт - чуть ли не родственник самого проклятого капитана!.. И чего только люди не выдумают, чтоб языки почесать...",
		"Эх, капитан, угораздило же вас подвернуться на пути этого демона, что моряки 'Летучим Голландцем' прозвали. И ведь не знаешь, печалиться или радоваться - ведь немногие после такой встречи живы остались... А вот презабавную байку я слыхал, что где-то на западе, в джунглях, живёт человек, который, якобы, секрет этого призрака знает и грозится в одиночку всех его демонов упокоить... Хе-хе, шаман какой, или очередной самозванец - не иначе."), 60, 4, "habitue", "");
	
	SetLaunchFrameFormParam("Прошло " + iDay + " дней." + NewStr() +
	                        "Остров " + GetConvertStr(ch.islandLable, "LocLables.txt")+","+ NewStr() +
							"" + GetConvertStr(pchar.location, "LocLables.txt") + ".",
						                        "Reload_To_Location", 0.1, 7.0);
    SetLaunchFrameReloadLocationParam(pchar.location, "Smugglers", "Smuggler01", "");
	LaunchFrameForm();
}

void GhostShipInit()
{
	//============> Капитан призрака
	int iRank = 20+MOD_SKILL_ENEMY_RATE*2;
	Group_FindOrCreateGroup("GhostCapt_Attack");
	sld = GetCharacter(NPC_GenerateCharacter("GhostCapt", "Vaterskeletcap", "man", "man", iRank, PIRATE, -1, true, "quest"));
	sld.name 	= "Дэйви";
	sld.lastname = "Джонс";
	sld.rank = 55; 
	sld.dialog.FileName = "Gothic_Quest\GhostShip_dialog.c";
	sld.dialog.currentnode = "GhostCapt_LastDialog";
	FantomMakeCoolSailor(sld, SHIP_FDM, "Корабль-призрак", CANNON_TYPE_CANNON_LBS42, 90, 90, 90);
	FantomMakeCoolFighter(sld, iRank, 90, 90, "blade_19", "pistol8", "GunEchin", 200);
	sld.Ship.Name = "Летучий голландец";
	NullCharacterGoods(sld); // удаляем все товары, чтобы не стрелял
	LAi_SetImmortal(sld, true);
	sld.DontRansackCaptain = true;
	sld.AnalizeShips = true;
sld.CoolBrander = true;
sld.sex = "Skeleton"; 
sld.monster = true; 
sld.viper = true;
	sld.DontHitInStorm = true; // не ломается в шторм
	sld.Abordage.Enable = false; // запрет абордажа
	SetShipSailsFromFile(sld, "ships/parus_FDM.tga");
	TakeNItems(sld, "potion2", MOD_SKILL_ENEMY_RATE/2);
	LAi_SetCharacterUseBullet(sld, "GunEchin");
	sld.money = 6666666;
	sld.SaveItemsForDead   = true; // сохранять на трупе вещи
	sld.cirassId           = Items_FindItemIdx("cirass5");  // предмета нет, но влияение есть
	sld.AlwaysSandbankManeuver = true;  // тупым запрет тонуть об берег
	sld.GenQuest.CrewVaterSkelMode  = true; // на абордаже рыбьи хари
sld.Ship.Mode = "Vaterskel";
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
SetCharacterPerk(sld, "GrapplingProfessional");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "LongRangeGrappling");
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
SetCharacterPerk(sld, "Doctor1"); 
SetCharacterPerk(sld, "Doctor2");
SetCharacterPerk(sld, "Doctor3");
SetCharacterPerk(sld, "Turn180");
SetCharacterPerk(sld, "SailingProfessional");
SetCharacterGoods(sld, GOOD_GOLD, 228);
SetSPECIAL(sld, 10, 10, 10, 10, 10, 10, 10); 
SetSelfSkill(sld, 100, 100, 100, 100, 100); 
SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100); 
sld.equip.gun = "pistol8";
SetCharacterGoods(sld, GOOD_GOLD, 228);
	LAi_SetHP(sld, 666, 666);
                    sld.SuperShooter  = true;
	ref shTo = &RealShips[sti(sld.Ship.Type)];
	shTo.SpeedRate = 30.0;
	shTo.TurnRate = 70.0;
	SetCrewQuantityOverMax(sld, 666);
	Group_AddCharacter("GhostCapt_Attack", "GhostCapt_seacap");
    Group_SetGroupCommander("GhostCapt_Attack", "GhostCapt_seacap");
	Group_SetTaskAttack("GhostCapt_Attack", PLAYER_GROUP);
    Group_LockTask("GhostCapt_Attack");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	Sea_LoginGroupCurrentSea("GhostCapt_Attack");
	Group_SetTaskAttack("GhostCapt_Attack", PLAYER_GROUP);
	Ship_SetTaskAttack(SECONDARY_TASK, sti(sld.index), GetMainCharacterIndex());
	GiveItem2Character(sld, "blade_19");
	EquipCharacterByItem(sld, "blade_19");
	GiveItem2Character(sld, "pistol8");
	TakeNItems(sld, "GunEchin", 50);
	AddItems(sld, "harpoon", 50);
	AddItems(sld, "bullet", 50);
	AddItems(sld, "gunpowder", 50);
	pchar.GenQuest.GhostShip.ShipType   = sti(sld.Ship.Type); // запомним, потом пригодится, когда парус нужно сменить на целый
}


// квест шотгана - терминатора Т-102 появление в комнате таверны
void QuestShotgunT102()
{
	ref sld;
	sld = GetCharacter(NPC_GenerateCharacter("T102", "Terminator", "man", "man", 55, PIRATE, 0, false, "quest"));
	sld.dialog.filename      = "Gothic_Quest\T102_dialog.c";
    
    sld.name  = "Terminator";
    sld.lastname = "";
	TakeNItems(sld,"potion2", 30);
	LAi_SetHP(sld, 1600.0, 1600.0);
	
	ChangeCharacterAddressGroup(sld, PChar.location, "reload", "reload1");
	LAi_group_MoveCharacter(sld, "TmpEnemy");
	LAi_SetActorType(sld);
    LAi_SetActorType(pchar);

	SetActorDialogAny2Pchar(sld.id, "", 2.0, 0.0);
	LAi_ActorFollow(sld, pchar, "ActorDialog_Any2Pchar", 4.0);
    LAi_group_SetRelation("TmpEnemy", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
}

