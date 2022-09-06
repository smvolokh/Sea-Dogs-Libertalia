int SM_SupportTeamSkipFrame = 0;
int SM_totalFighters = 0;
int SM_ShipCrewBeforeBoarding = 0;
bool SM_battleActive = false;
bool SM_leftShip = false;
bool SM_landVisited = false; // ��� ������ ������
bool SM_removeAfterUnload = false;
string SM_skippedLoc[15];



// �������������
void SM_SupportTeamInit()
{
	
	// ���������� ��������� ����, �� ������� �������� �� �����
	SM_skippedLoc[0] = "Cabin"; // new!!! - �� ������� ����������, ������ � ����� ���� 1�1
	SM_skippedLoc[1] = "My_Campus"; // new!!! - � ��� ������� ������ ����������� �����
	SM_skippedLoc[2] = "_store";
	SM_skippedLoc[3] = "_tavern_upstairs";
	SM_skippedLoc[4] = "_Bank";
	SM_skippedLoc[5] = "_TownhallRoom";
	SM_skippedLoc[6] = "_PortOffice";
	SM_skippedLoc[7] = "_Packhouse";
	SM_skippedLoc[8] = "_church";
	SM_skippedLoc[9] = "_prison";
	SM_skippedLoc[10] = "_KeepersHouse";
	SM_skippedLoc[11] = "_Lighthouseroom";
	SM_skippedLoc[12] = "_bedroom";
	SM_skippedLoc[13] = "_Brothel";
	SM_skippedLoc[14] = "_SecBrRoom";
	
}



// ����������� � �����, ������� ���������
void SM_SupportTeamOnLoad()
{
	
	if (!CheckAttribute(pchar, "SupportTeamType"))
		return;
	
	SM_SupportTeamSkipFrame = 50;
	SM_battleActive = false;
	
	//SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	SetEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad", 0);
	SetEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload", 0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState", 0);
	
	//Log_info("SM_OnGameLoad!");
}



// ��������� � �������� ��������� ����� ��� � �� (n - �������, m - ���������)
void SM_AddSupportTeam(int n, int m)
{	
	if (SM_totalFighters)
		SM_RemoveSupportTeamImmediately(false); // �� ������ ������, ���� �������� ������ �� ����������� ������
	
	// ���������� �� ����� ������
	// SM_ShipCrewBeforeBoarding = GetCrewQuantity(pchar);
	
	SM_totalFighters = n + m;
	
	AddCharacterCrew(pchar, -SM_totalFighters);
	
	int crewType;
	string  smodel;
	string  ani;
	
	float locx, locy, locz;
	GetCharacterPos(pchar, &locx, &locy, &locz);
	
	int iRank = pchar.rank + 2; // ���� ���
	
	int weaponQuantity = sti(GetCargoGoods(pchar, GOOD_WEAPON)); // �������, ����� ������ ������ � �����
	int goodItemsMultipler = 1.0; // ��������� ��� ����� ������, ���� ������ ������ � ����� ������ ������������, �� ����� �������� ��� ������� ���� + ������ ������
	int bestItemsMultipler = 2.0; // ��������� ��� ����� ������, ���� ������ ������ � ����� ������ ������������, �� ����� �������� ��� �������� ���� + ������� �������
	bool mushketerSuccess; // ������� �� ������� ���������
	
	int powderQuantity = sti(GetCargoGoods(pchar, GOOD_POWDER)); // ���� �����
	float powderPerSld = 10.0; // ��� ������� ��� ������� ��������� ������
	int powderAndBullets = 10; // ����������� ���-�� ������� (����� �������������)
	
	object vpistols; // �������� ��������
	object vmushkets; // �������� ��������
	object vcirasses; // �������� �����
	object vblades; // �������� ������
	
	int crewQuantity = GetCrewQuantity(pchar); // ������� ����������� �������
	int medicamentQuantity = sti(GetCargoGoods(pchar, GOOD_MEDICAMENT)); // �������, ����� ������ �������� � �����
	int goodHpMultipler = 2; // ��������� ��� ����� �������� � �������, ���� �������� � ����� ������ ������������, �� + � �� + ������� ��������
	int bestIHpMultipler = 3; // ��������� ��� ����� �������� � �������, ���� �������� � ����� ������ ������������, �� ++ � �� + ������� ��������
	
	float bonusHpMultiper = 1; // ����� � ��
	int potions = 0; // ����� �������
	string potionType = ""; // ��� �������
	int itemsPerSld = 0; // ������� ������ �������� ��������� �� ��� �� �����.
	
	int rumQuantity = sti(GetCargoGoods(pchar, GOOD_RUM)); // ���� �� ��� (��� ��� ������� - ���)
	int rum = 0; // ��� (��� �������)
	float rumPerSld = 0.5; // �� 1 ��� �� 50% �� �����
	int wineQuantity = sti(GetCargoGoods(pchar, GOOD_WINE)); // ���� �� ���� (��� ��� ������� - ������)
	int wine = 0; // ���� (��� �������)
	float winePerSld = 0.5; // �� 1 ��� �� 50% �� �����


	// 1. � ����� ���� ��������, ������ ����� 2 ������� � ����� � ��
	if (medicamentQuantity < crewQuantity)
	{
		bonusHpMultiper = 0.5;
		potions = 2;
		potionType = "potion1";
		itemsPerSld = 1;
	}
	
	// 2. �������� ���� �� ����. ���� ������� � ����������� ��
	if (medicamentQuantity >= crewQuantity)
	{
		bonusHpMultiper = 1.0;
		potions = 8;
		potionType = "potion1";
		itemsPerSld = 4;
	}
	
	// 3. �������� �����, ������� ������� + ����� � ��
	if (medicamentQuantity > crewQuantity * goodHpMultipler)
	{
		bonusHpMultiper = 2.0;
		potions = 8;
		potionType = "potion2";
		itemsPerSld = 8;
	}
	
	// 4. �������� ����� �����, 
	if (medicamentQuantity > crewQuantity * bestIHpMultipler)
	{
		bonusHpMultiper = 3.0;
		potions = 16;
		potionType = "potion2";
		itemsPerSld = 16;
	}
	
	// 5. ���� ���� ���, ����� � ���
	if (rumQuantity/crewQuantity * 10 > SM_totalFighters * rumPerSld)
	{
		rum = 5;
	}

	// 6. ���� ���� ����, ����� � ���
	if (wineQuantity/crewQuantity * 10 > SM_totalFighters * winePerSld)
	{
		wine = 5;
	}
	
	// 7. ��������� �����, ���� ���, �� ������ ���� �� ��������� ���������, ����� �� ��������
	if (powderQuantity > crewQuantity * powderPerSld)
	{
		powderAndBullets = 50;
	}
	
	// 8. ��� �������
	if (weaponQuantity < SM_totalFighters)
	{
		vblades.b0 = "slave_01"; // ������
		vblades.b1 = "slave_02"; // ������
		vblades.b2 = "topor_05"; // ��������
		vmushkets.m0 = "mushket3"; vmushkets.b0 = "grapeshot"; // ��������� ��������
		SM_RemoveSupportTeam();
		Log_info("������������ �������� ��� ����� ������!");
	}
	
	// 9. ������� ������ �������
	if (weaponQuantity >= SM_totalFighters)
	{
		vblades.b0 = "blade_03"; // ��������
		vblades.b1 = "newblade11"; // ������
		vblades.b2 = "newblade2"; // ������������ �����
		vblades.b3 = "newblade3"; // ������
		vblades.b4 = "newblade4"; // �������� �����
		vblades.b5 = "newblade1"; // ����������� �����
		vblades.b6 = "topor_05"; // ��������
		vblades.b7 = "topor_07"; // ��������
		vblades.b8 = "blade_07"; // �����������
		vblades.b9 = "newblade23"; // �����

		vcirasses.c0 = "cirass5"; // ������

		vpistols.g0 = "pistol3"; vpistols.b0 = "grapeshot"; 			// ����������
		vmushkets.m0 = "mushket_01"; vmushkets.b0 = "grapeshot"; // �������
	}
	
	// 10. ����� ������� ������ � ����
	if (weaponQuantity/crewQuantity * 6.5 > SM_totalFighters * goodItemsMultipler)
	{
		vblades.b0 = "blade_08"; // ������
		vblades.b1 = "blade_09"; // ���������
		vblades.b2 = "newblade8"; // ���������
		vblades.b3 = "blade_04"; // ����������
		vblades.b4 = "blade_05"; // ������
		vblades.b5 = "blade_10"; // ����
		vblades.b6 = "blade_11"; // ���������� �����
		vblades.b7 = "blade_12"; // ���������
		vblades.b8 = "blade50"; // ������ ��� 
		vblades.b9 = "newblade6"; // ���������
		vblades.b10 = "newblade7"; // �����������
		vblades.b11 = "newblade10"; // ������������� �����
		vblades.b12 = "topor_02"; // �������
		vblades.b13 = "topor_03"; // ��������
		vblades.b14 = "topor_012"; // ������� �����
		vblades.b15 = "topor_013"; // ������
		vblades.b16 = "topor_014"; // ���������� �����
		vblades.b17 = "blade_14"; // ���������� �����
		vblades.b18 = "newblade19"; // �����
		vblades.b19 = "newblade5"; // ��������
		vblades.b20 = "newblade9"; // ���������� �����
		vblades.b21 = "newblade27"; // ������

		vcirasses.c0 = "cirass6"; // ����� �������
		vcirasses.c1 = "cirass2"; // ���������� ������
		
		vpistols.g0 = "pistol_03"; vpistols.b0 = "grapeshot"; 		// �������
		vmushkets.m0 = "mushket3"; vmushkets.b0 = "grapeshot"; // ��������
	}
	
	// 11. ����� �������� ������
	if (weaponQuantity/crewQuantity * 9.0 > SM_totalFighters * bestItemsMultipler)
	{
		vblades.b0 = "blade_15"; // ��������
		vblades.b1 = "blade_16"; // ����������
		vblades.b2 = "newblade13"; // ������
		vblades.b3 = "topor_04"; // ������
		vblades.b4 = "blade_13"; // ���������� �����
		vblades.b5 = "newblade12"; // �������
		vblades.b6 = "newblade14"; // ��������
		vblades.b7 = "newblade15"; // �������
		vblades.b8 = "newblade24"; // ����������� �����
		vblades.b9 = "newblade25"; // ��������� �����
		vblades.b10 = "newblade26"; // ������
		vblades.b11 = "newblade28"; // ������
		
		vcirasses.c0 = "cirass1"; // ���������� ������
		vcirasses.c1 = "cirass7"; // �������
		
		
		vpistols.g0 = "pistol2"; vpistols.b0 = "grapeshot"; 			// 3-� ��������� ��������
		vpistols.g1 = "pistol02"; vpistols.b1 = "grapeshot"; 			// �����
		vpistols.g2 = "pistol_08"; vpistols.b2 = "grapeshot"; 		// ���������� ��������
		vmushkets.m0 = "Mushket_8"; vmushkets.b0 = "grapeshot"; // ����������
	}
	
	// 12. ��� ���������� ������� (������� ��� ��������)
	crewType = 0;
	if (CheckAttribute(pchar, "GenQuest.BoardCrewType"))
		crewType = pchar.GenQuest.BoardCrewType;
	
	// 13. ���������� �������
	for (i = 0; i < n; i++)
	{
		CSM_GetModelByCrewType(crewType, &smodel, &ani, false);
		sld = GetCharacter(NPC_GenerateCharacter("SM_Support_sold_"+ i, smodel, "man", ani, iRank, PIRATE, -1, true, "soldier"));
		sld.SuperShooter = true;
		SelAllPerksToChar(sld, false);
		
		SM_EquipSupport(sld, vblades, vcirasses, vpistols, powderAndBullets, bonusHpMultiper, potions, potionType, rum, wine, false);
		SM_ApplyFirstAISettings(sld);
		
		if (!SM_NeedToSkipLocation()) // ���� �� � �����
		{
			ChangeCharacterAddressGroup(sld, loadedLocation.id, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	// 14. ���������
	for (i = n; i < SM_totalFighters; i++)
	{
		mushketerSuccess = CSM_GetModelByCrewType(crewType, &smodel, &ani, true);
		sld = GetCharacter(NPC_GenerateCharacter("SM_Support_sold_"+ i, smodel, "man", ani, iRank, PIRATE, -1, true, "soldier"));
		sld.SuperShooter = true;
		SelAllPerksToChar(sld, false);
	
		SM_EquipSupport(sld, vblades, vcirasses, vmushkets, powderAndBullets, bonusHpMultiper, potions, potionType, rum, wine, mushketerSuccess);
		SM_ApplyFirstAISettings(sld);
		
		if (!SM_NeedToSkipLocation()) // ���� �� � �����
		{
			ChangeCharacterAddressGroup(sld, loadedLocation.id, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	// 15. �������
	RemoveCharacterGoods(pchar, GOOD_WEAPON, SM_totalFighters); // ������ ���� �������� 1 ��. ������, ���� ������� ���, �� � �����, ��� ����� ����� ������...
	RemoveCharacterGoods(pchar, GOOD_FOOD, SM_totalFighters); // ����� � ����� ���...
	RemoveCharacterGoods(pchar, GOOD_MEDICAMENT, itemsPerSld * SM_totalFighters); // ��������, ��������
	RemoveCharacterGoods(pchar, GOOD_RUM, rumPerSld * SM_totalFighters); // ���
	RemoveCharacterGoods(pchar, GOOD_WINE, winePerSld * SM_totalFighters); // ����
	RemoveCharacterGoods(pchar, GOOD_POWDER, powderPerSld * SM_totalFighters); // � �����, ���� ���� �������� �����, ����� ������
	
	RemoveCharacterCrew(pchar, 0); // � ��������� ����� ������� �� �����, ��� ���� ��� ����...
	
	// 16. ������ ��������� � ���������
	if (!SM_NeedToSkipLocation())
		SM_MoveOfficersToPchar();
	
	//SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	SetEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad", 0);
	SetEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload", 0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState", 0);
	
	SM_leftShip = false; // ��� �� �������� �����
	
	PlaySound("interface\_GTTown2.wav");
	Log_info("����� ������ � ������� �������!");
}

// ������ ���� �������
void SM_EquipSupport(ref curSld, object vblades, object vcirasses, object vguns, int powderAndBullets, float bonusHpMultiper, int potions, string potionType, int rum, int wine, bool isMushketer)
{
	int fightSkills = 100; // ������
	
	string blade = SM_GetRandomItemFrom(vblades);
	
	string gun, bullet;
	if (GetAttributesNum(vguns) > 0)
		SM_GetGunAndBullets(vguns, &gun, &bullet);
	else
		gun = ""; bullet = "";
	if (findsubstr(gun, "mushket", 0) != -1 && !isMushketer) // ���� ������� �� ��������� ����� ������
	{
		gun = "pistol8"; // ����������
		bullet = "grapeshot"; // ������
	}
	
	string cirass = SM_GetRandomItemFrom(vcirasses);
	
	// ���������
	FantomMakeCoolFighter(curSld, pchar.rank, fightSkills, fightSkills, blade, gun, "grapeshot", 0); // �������� �����
	float maxSldHp = LAi_GetCharacterHP(curSld) * bonusHpMultiper/2.0;
	SetPcharSelfSkills22NPC(curSld);
	SetPcharShipSkills22NPC(curSld);
	SetPcharPerks22NPC(curSld);
	curSld.rank = sti(pchar.rank);
	curSld.SuperShooter = true;
	LAi_SetHP(curSld, maxSldHp, maxSldHp);

	curSld.cirassId = Items_FindItemIdx(cirass);
	
	if (gun != "")
	{
		TakenItems(curSld, bullet, powderAndBullets);
		if (bullet != "cartridge" || bullet != "GunEchin")
			TakenItems(curSld, "GunPowder", powderAndBullets);
	}
	
	if (isMushketer)
		curSld.MusketerDistance = 2;
	
	TakenItems(curSld, potionType, potions); // ������ �������
	TakenItems(curSld, "potionrum", rum); // ���
	TakenItems(curSld, "potionwine", wine); // ����
}



// ��������� � �������� ��������� ��������� (�������, �����, ��� ������ � ��.)
void SM_ApplyFirstAISettings(ref curSld)
{
	// ����� ������� �� ����������� ������, ��� � �����.
	curSld.dialog.FileName = "Quest\Saga\OtherNPC.c";
	curSld.dialog.currentnode = "Svensons_sold";
	switch(rand(3))
	{
		case 0: curSld.greeting = "Voice\Russian\pirat_guard_1.WAV"; break;
		case 1: curSld.greeting = "Voice\Russian\pirat_guard_2.WAV"; break;
		case 2: curSld.greeting = "Voice\Russian\pirat_guard_3.WAV"; break;
		case 3: curSld.greeting = "Voice\Russian\pirat_guard_4.WAV"; break;
	}
	
	if (!SM_NeedToSkipLocation()) // ���� �� � �����
	{
		LAi_ActorFollow(curSld, pchar, "", -1);
		LAi_Actor2WaitDialog(curSld, pchar);
	}
	
	LAi_SetActorType(curSld);
	LAi_Actor2WaitDialog(curSld, pchar);
	LAi_LoginInCaptureTown(curSld, true); // ���������� �� ������� � ������
}	


// ����� �� ���� ����� ���� ����
string SM_GetRandomItemFrom(object items)
{
	aref aItems;
	makearef(aItems, items);
	return GetAttributeValue(GetAttributeN(aItems, rand(GetAttributesNum(items) - 1)));
}



// ������� ����� � ��� ������� � ����
void SM_GetGunAndBullets(object guns, string gun, string bullet)
{
	aref aGuns;
	makearef(aGuns, guns);
	int index = rand(GetAttributesNum(guns) / 2 - 1) * 2;
	gun = GetAttributeValue(GetAttributeN(aGuns, index));
	bullet = GetAttributeValue(GetAttributeN(aGuns, index + 1));
}

// ������� ������
void SM_RemoveSupportTeam()
{
	
	ref ms = GetRealShip(sti(pchar.Ship.Type));
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_"+ i);
		if (CheckAttribute(sld, "index") && sld.index != -1)
		{
			LAi_SetWarriorType(sld);
			LAi_type_warrior_SetWateState(sld); // ������ ��� ����
			sld.lifeday = 0;
		}
	}
	
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	DelEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad");
	
	SM_removeAfterUnload = true;

}

// ���������� ����� ���� ���������� ��� �� ������
void SM_RemoveSupportTeamImmediately(bool removeAttribute)
{	
	
	if (removeAttribute)
		DeleteAttribute(pchar, "SupportTeamType");
	
	SM_removeAfterUnload = false;
	SM_leftShip = false;
	
	// fix ��� ������ ��� �������� - ������������� ������������ �������
	if (SM_ShipCrewBeforeBoarding != 0)
	{
		SetCrewQuantity(pchar, SM_ShipCrewBeforeBoarding); // fix ��� ����������������� ��������/������
		SM_ShipCrewBeforeBoarding = 0;
	}
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_"+ i);
		if (LAi_GetCharacterHP(sld) > 1)
		{
			ChangeCharacterAddress(sld, "none", "");
			if (GetCrewQuantity(pchar) < GetMaxCrewQuantity(pchar)) // ���� ������� ���, ���������� ��� � �������, ��� ���� ��������� �� ��������� �����...
				AddCharacterCrew(pchar, 1);
		}
	}
	
	SM_totalFighters = 0;
	
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	DelEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad");
	DelEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload");
	DelEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState");
	
	PlaySound("interface\notebook.wav");
	Log_info("����� ��� ��������!");
	AddCharacterCrew(pchar, 0);	
}



// TODO: ���������� �������� �� ������ � ���������� � ��������� ���, ���� ��� ��� �����...
void SM_ST_OnEnterFrame()
{
	SM_SupportTeamSkipFrame++;
	if (SM_SupportTeamSkipFrame < 100) // ����������� �� ������� (������������ ����� ������ 100 ������)
		return;
	else
		SM_SupportTeamSkipFrame = 0;
	
	if (SM_ScanForEnemyByRange(80)) // ���� �� ����
	{ 
		
		if (!SM_battleActive) // ���� ���� �����, � ����� �������
		{ 
			
			for (i = 0; i < SM_totalFighters; i++)
			{
				sld = characterFromId("SM_Support_sold_" + i);
				if (CheckAttribute(sld, "index") && sld.index != -1)
				{
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
					LAi_SetFightMode(sld, true);
					LAi_warrior_SetCommander(sld, pchar);
					if (!CheckAttribute(pchar, "CSM.BoardingCrewGodMode")) LAi_SetImmortal(sld, false);  // ������� ���������� �� ����� �����
					if (CheckAttribute(pchar, "animal"))
						sld.animal = true;
					else
						DeleteAttribute(sld, "animal");
					//Log_info("LAi_SetWarriorType : " + i);
				}
			}
			
			LAi_CharacterPlaySound(pchar, "warrior"); // ����������
			
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // ������ ���� ������
			
			SM_battleActive = true;
			//Log_info("SM_battleActive : true");
			return;
		}
		
	}
	else
	{
		
		if (SM_battleActive) // ���� ������ ���, �� ����� �������
		{
			
			for (i = 0; i < SM_totalFighters; i++)
			{
				sld = characterFromId("SM_Support_sold_" + i);
				if (CheckAttribute(sld, "index") && sld.index != -1)
				{
					LAi_SetFightMode(sld, false);
					LAi_SetActorType(sld);
					LAi_ActorFollow(sld, pchar, "", -1); // LAi_ActorFollowEverywhere(sld, "", -1); ��� �� ����.. � ������ �� ����. ������������ �����, �.�. ���� ��������.
					LAi_Actor2WaitDialog(sld, pchar);
					LAi_SetImmortal(sld, true); // fix: ����� ������� ����� ��������, ��� ��� ����� ����� ����������
					
					//Log_info("LAi_SetActorType : " + i);
				}
			}
			// ������������ ������� ������ (�� ������������ ���������, �� ����� ����� +�� ��� ������ ������)
			// ��� ������ ��� �����, ��� ������ �����
			SM_ExpCompensator((rand(18) + SM_totalFighters) * pchar.rank);
			
			SM_battleActive = false;
			
			//Log_info("SM_battleActive : false");
			return;
		}
		
		// ���������� ��������, ���� ��������� �� ����. ������ ��������� ����� ��������� ������.
		for (i = 0; i < SM_totalFighters; i++)
		{
			sld = characterFromId("SM_Support_sold_" + i);
			if (CheckAttribute(sld, "index") && sld.index != -1)
			{
				LAi_type_actor_Reset(sld);
				LAi_ActorFollow(sld, pchar, "", -1);
				LAi_Actor2WaitDialog(sld, pchar);
			}
			
		}
		
	}
	
}



// ����� ���������� ����� ��������� ������� ����� �� � ���� � ������.
void SM_ExpCompensator(int value)
{
	int index;
	
	AddCharacterExpToSkill(pchar, "Leadership", value); 
	AddComplexSelfExpToScill(value, value, value, value);
	
	for (i = 1; i < 4; i++)
	{
		index = GetOfficersIndex(pchar, i);
		
		if (index != -1)
		{
			sld = GetCharacter(index);
			AddCharacterExpToSkill(sld, "Leadership", value); 
			AddCharacterExpToSkill(sld, "FencingL", value);
			AddCharacterExpToSkill(sld, "FencingS", value);
			AddCharacterExpToSkill(sld, "FencingH", value);
			AddCharacterExpToSkill(sld, "Pistol", value);
			
			//Log_info("AddCharacterExpToSkill : " + value);
		}
	}

}



// ��� �������� ����� �������...
void SM_OnLocationLoad()
{
	// ���� ����� ������, ��� �������������� �� ��... ��� ��� ����� ���� ��������, � ������� ��� �� ��������
	if (pchar.location == "underwater" || pchar.location == "LostShipsCity_town")
	{
		SM_RemoveSupportTeamImmediately(true);
		return;
	}
	
	// ���� ��������� �� �����, ����� ���������� �������������. ����� �������� � ��� �����.
	if (isShipInside(pchar.location))
	{
		
		if (SM_leftShip)
		{
			SM_leftShip = false;
			SM_RemoveSupportTeamImmediately(true);
			return;
		}
		
	}
	else
	{
		SM_leftShip = true; // �������� ����� �� �� �������
		//Log_info("�������� �����");
	}
	
	if (SM_NeedToSkipLocation()) // ��� ������� �� � ����, ������ �����. �� ����� �� ���������...
		return;
	
	SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	
	float locx, locy, locz;
	GetCharacterPos(pchar, &locx, &locy, &locz);
	
	string locator = "";
	if (CheckAttribute(loadedLocation, "locators.reload"))
		locator = "reload";
	if (CheckAttribute(loadedLocation, "locators.rld"))
		locator = "rld";
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_" + i);
		if (CheckAttribute(sld, "index") && sld.index != -1 && LAi_GetCharacterHP(sld) > 0)
		{
			
			LAi_SetActorType(sld);
			
			ChangeCharacterAddressGroup(sld, loadedLocation.id, locator, LAi_FindNearestFreeLocator(locator, locx, locy, locz));
			
			LAi_ActorFollow(sld, pchar, "", -1);
			LAi_Actor2WaitDialog(sld, pchar);
			
			// ����� � 99% ������������ ��� ������ ������� � 1 �����, �������� ��� ���. �� ����, ������ �������
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	SM_MoveOfficersToPchar();
}



// ���� �� ���� ������� �����
bool SM_NeedToSkipLocation()
{
	
	/*int j; // i ��� ������, ����������, �.�. �� ��������� �����
	
	if (CheckAttribute(pchar, "CSM.StartNewGame"))
	{
		for (j = 0; j < 15; j++)
			if (findsubstr(pchar.location, SM_skippedLoc[j], 0) != -1)
				return true;
	}
	else
	{*/
		if (HasSubStr(pchar.location, "Cabin") || // updated
			HasSubStr(pchar.location, "My_Campus") || // updated
			HasSubStr(pchar.location, "_store") ||
			HasSubStr(pchar.location, "_tavern_upstairs") ||
			HasSubStr(pchar.location, "_Bank") ||
			HasSubStr(pchar.location, "_TownhallRoom") ||
			HasSubStr(pchar.location, "_PortOffice") ||
			HasSubStr(pchar.location, "_Packhouse") ||
			HasSubStr(pchar.location, "_church") ||
			HasSubStr(pchar.location, "_prison") ||
			HasSubStr(pchar.location, "_KeepersHouse") ||
			HasSubStr(pchar.location, "_Lighthouseroom") ||
			HasSubStr(pchar.location, "_bedroom") ||
			HasSubStr(pchar.location, "_Brothel") ||
			HasSubStr(pchar.location, "_SecBrRoom") ||
			loadedLocation.type == "underwater" ||
			pchar.location == "Terrain")
			return true;
	//}

	return false;
}



// ���� ������� � �������, ���� ������� ����� ������
void SM_OnLocationUnload()
{
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	
	if (SM_removeAfterUnload) {
		SM_RemoveSupportTeamImmediately(true)
		SM_removeAfterUnload = false;
		return;
	}
	
	SM_battleActive = false;
	for (i = 0; i < SM_totalFighters; i++)
	{
		
		sld = characterFromId("SM_Support_sold_" + i);
		if (CheckAttribute(sld, "index") && sld.index != -1)
		{
			LAi_SetActorType(sld);
			LAi_SetImmortal(sld, true);
			//Log_info("SM_OnLocationUnload: LAi_SetActorType : " + i);
		}
		
	}
	
	//Log_info("SM_OnLocationUnload: " + pchar.location );
}



// ����� � ����
void SM_OnSeaState()
{
	
	if (SM_leftShip)
	{
		SM_leftShip = false;
		SM_RemoveSupportTeamImmediately(true);
		return;
	}
	
	//Log_info("SM_OnSeaState");
}



// ���� ����� �� ���������� ������. ���� ����, �� true
bool SM_ScanForEnemyByRange(int value)
{
	if (!IsEntity(loadedLocation))
		return false;
	
	int n = FindNearCharacters(pchar, value, -1.0, -1.0, 0.001, false, true);
	
	for (i = 0; i < n; i++)
	{
		if (!CheckAttribute(chrFindNearCharacters[i], "index"))
			continue;
		
		sld = GetCharacter(sti(chrFindNearCharacters[i].index));
		if (LAi_group_IsEnemy(pchar, sld) && // ���� ����
			GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE) != "" && // �������� �����
			!CheckAttribute(sld, "chr_ai.hpchecker") && // ��� ���, ��������� �����?
			sld.chr_ai.type != LAI_TYPE_CARRY && // �� � ������� ���������
			sld.chr_ai.type != LAI_TYPE_POOR && // �� ����
			sld.chr_ai.type != LAI_TYPE_SIT && // �� �����
			sld.chr_ai.type != LAI_TYPE_STUNNED && // �� ��������
			sld.chr_ai.type != LAI_TYPE_LAY) // �� ����
			return true;
	}
	
	return false;
}

// ����� ������� ������� ������ ��� �� �� (��� ������ � ����� ���������� ��������� �� �� ����������), ���� ��������� ��� � ���������, ����� � ����� ��������� ��������� ������� 
void SM_SeparateNPC(ref leader, ref npc, int index, int total)
{	
	float locx, locy, locz, rezX, rezZ, distance = 0.001; // ���� ������� ������, ����� ���������� � �������, �� ����� �����, ��� �� ��� �������
	
	GetCharacterPos(leader, &locx, &locy, &locz); 
	
	rezX = cos(6.28 * index / total) * distance + locx;
	rezZ = sin(6.28 * index / total) * distance + locz;
	
	TeleportCharacterToPos(npc, rezX, locy, rezZ);
}

void SetPcharSelfSkills22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	if (CheckAttribute(pchar, "skill.Leadership") > 0)	{ rChar.skill.Leadership = sti(pchar.skill.Leadership); }
	if (CheckAttribute(pchar, "skill.FencingL") > 0)	{ rChar.skill.FencingL	= sti(pchar.skill.FencingL); }
	if (CheckAttribute(pchar, "skill.FencingS") > 0)	{ rChar.skill.FencingS	= sti(pchar.skill.FencingS); }
	if (CheckAttribute(pchar, "skill.FencingH") > 0)	{ rChar.skill.FencingH	= sti(pchar.skill.FencingH); }
	if (CheckAttribute(pchar, "skill.Pistol") > 0)		{ rChar.skill.Pistol 	= sti(pchar.skill.Pistol); }
	if (CheckAttribute(pchar, "skill.Fortune") > 0)		{ rChar.skill.Fortune	= sti(pchar.skill.Fortune); }
	if (CheckAttribute(pchar, "skill.Sneak") > 0)		{ rChar.skill.Sneak		= sti(pchar.skill.Sneak); }
}

void SetPcharShipSkills22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	if (CheckAttribute(pchar, "skill.Sailing") > 0)		{ rChar.skill.Sailing	= sti(pchar.skill.Sailing); }
	if (CheckAttribute(pchar, "skill.Commerce") > 0)	{ rChar.skill.Commerce	= sti(pchar.skill.Commerce); }
	if (CheckAttribute(pchar, "skill.Accuracy") > 0)	{ rChar.skill.Accuracy 	= sti(pchar.skill.Accuracy); }
	if (CheckAttribute(pchar, "skill.Cannons") > 0)		{ rChar.skill.Cannons 	= sti(pchar.skill.Cannons); }
	if (CheckAttribute(pchar, "skill.Repair") > 0)		{ rChar.skill.Repair 	= sti(pchar.skill.Repair); }
	if (CheckAttribute(pchar, "skill.Grappling") > 0)	{ rChar.skill.Grappling = sti(pchar.skill.Grappling); }
	if (CheckAttribute(pchar, "skill.Defence") > 0)		{ rChar.skill.Defence 	= sti(pchar.skill.Defence); }
}

void SetPcharPerks22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	DeleteAttribute(rChar, "perks.list");
	// Personal
	if (CheckAttribute(pchar, "perks.list.BasicDefense") > 0)			{ rChar.perks.list.BasicDefense = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedDefense") > 0)		{ rChar.perks.list.AdvancedDefense = "1"; }
if (CheckAttribute(pchar, "perks.list.ProfessionalDefense") > 0)		{ rChar.perks.list.ProfessionalDefense = "1"; }
	if (CheckAttribute(pchar, "perks.list.CriticalHit") > 0)			{ rChar.perks.list.CriticalHit = "1"; }
	if (CheckAttribute(pchar, "perks.list.HPPlus") > 0)					{ rChar.perks.list.HPPlus = "1"; }
	if (CheckAttribute(pchar, "perks.list.Tireless") > 0)				{ rChar.perks.list.Tireless = "1"; }
	if (CheckAttribute(pchar, "perks.list.EnergyPlus") > 0)				{ rChar.perks.list.EnergyPlus = "1"; }
	if (CheckAttribute(pchar, "perks.list.Sliding") > 0)				{ rChar.perks.list.Sliding = "1"; }
	if (CheckAttribute(pchar, "perks.list.SwordplayProfessional") > 0)	{ rChar.perks.list.SwordplayProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.HardHitter") > 0)				{ rChar.perks.list.HardHitter = "1"; }
	if (CheckAttribute(pchar, "perks.list.BladeDancer") > 0)			{ rChar.perks.list.BladeDancer = "1"; }
	if (CheckAttribute(pchar, "perks.list.Gunman") > 0)					{ rChar.perks.list.Gunman = "1"; }
	if (CheckAttribute(pchar, "perks.list.GunProfessional") > 0)		{ rChar.perks.list.GunProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Sniper") > 0)		{ rChar.perks.list.Sniper = "1"; }
	if (CheckAttribute(pchar, "perks.list.Grus") > 0)					{ rChar.perks.list.Grus = "1"; }
	if (CheckAttribute(pchar, "perks.list.IronWill") > 0)				{ rChar.perks.list.IronWill = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipEscape") > 0)				{ rChar.perks.list.ShipEscape = "1"; }
	// Ship
	if (CheckAttribute(pchar, "perks.list.Brander") > 0) 				{ rChar.perks.list.Brander = "1"; }
	if (CheckAttribute(pchar, "perks.list.Troopers") > 0) 				{ rChar.perks.list.Troopers = "1"; }
	if (CheckAttribute(pchar, "perks.list.LongRangeGrappling") > 0) 	{ rChar.perks.list.LongRangeGrappling = "1"; }
	if (CheckAttribute(pchar, "perks.list.GrapplingProfessional") > 0)	{ rChar.perks.list.GrapplingProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.MusketsShoot") > 0) 			{ rChar.perks.list.MusketsShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.BasicCommerce") > 0) 			{ rChar.perks.list.BasicCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedCommerce") > 0) 		{ rChar.perks.list.AdvancedCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.ProfessionalCommerce") > 0) 	{ rChar.perks.list.ProfessionalCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.FastReload") > 0) 			{ rChar.perks.list.FastReload = "1"; }
	if (CheckAttribute(pchar, "perks.list.ImmediateReload") > 0) 		{ rChar.perks.list.ImmediateReload = "1"; }
	if (CheckAttribute(pchar, "perks.list.HullDamageUp") > 0) 			{ rChar.perks.list.HullDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailsDamageUp") > 0) 			{ rChar.perks.list.SailsDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.CrewDamageUp") > 0) 			{ rChar.perks.list.CrewDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.CriticalShoot") > 0) 			{ rChar.perks.list.CriticalShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.LongRangeShoot") > 0) 		{ rChar.perks.list.LongRangeShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.CannonProfessional") > 0) 	{ rChar.perks.list.CannonProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Carpenter") > 0) 				{ rChar.perks.list.Carpenter = "1"; }
	if (CheckAttribute(pchar, "perks.list.LightRepair") > 0) 			{ rChar.perks.list.LightRepair = "1"; }
	if (CheckAttribute(pchar, "perks.list.Builder") > 0) 				{ rChar.perks.list.Builder = "1"; }
	if (CheckAttribute(pchar, "perks.list.BasicBattleState") > 0) 		{ rChar.perks.list.BasicBattleState = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedBattleState") > 0) 	{ rChar.perks.list.AdvancedBattleState = "1"; }
	if (CheckAttribute(pchar, "perks.list.SelfRepair") > 0) 			{ rChar.perks.list.SelfRepair = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipDefenseProfessional") > 0) { rChar.perks.list.ShipDefenseProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipSpeedUp") > 0) 			{ rChar.perks.list.ShipSpeedUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipTurnRateUp") > 0) 		{ rChar.perks.list.ShipTurnRateUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.StormProfessional") > 0) 		{ rChar.perks.list.StormProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.WindCatcher") > 0) 			{ rChar.perks.list.WindCatcher = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailsMan") > 0) 				{ rChar.perks.list.SailsMan = "1"; }
	if (CheckAttribute(pchar, "perks.list.Turn180") > 0) 				{ rChar.perks.list.Turn180 = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailingProfessional") > 0) 	{ rChar.perks.list.SailingProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor1") > 0) 				{ rChar.perks.list.Doctor1 = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor2") > 0) 				{ rChar.perks.list.Doctor2 = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor3") > 0) 				{ rChar.perks.list.Doctor3 = "1"; }
}

// ���� ��� �� ���������� � ���� ������ � �� ����� ���
void SM_MoveOfficersToPchar()
{
	int i, index;
	float locx, locy, locz;
	ref of;
	string locator = "";
	
	GetCharacterPos(pchar, &locx, &locy, &locz);
	if (CheckAttribute(loadedLocation, "locators.reload"))
		locator = "reload";
	if (CheckAttribute(loadedLocation, "locators.rld"))
		locator = "rld";
	
	for (i = 1; i <= 3; i++)
	{
		index = GetOfficersIndex(pchar, i);
		if (index == -1)
			continue;
		of = GetCharacter(index);
		
		ChangeCharacterAddressGroup(of, loadedLocation.id, locator, LAi_FindNearestFreeLocator(locator, locx, locy, locz));
		
		SM_SeparateNPC(pchar, of, i, 3);
	}
}



