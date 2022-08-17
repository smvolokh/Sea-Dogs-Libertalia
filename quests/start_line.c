void StartlineQuestComplete(string sQuestName, string qname)
{
}


void Gothic_Start()
{
          PlaySound("Ship\Turn_Loop_01.wav");
}

void Gothic_SeaShore (string qName)//
{
	// ������ ������� ��
	sld = ItemsFromID("Loushammer");
                   sld.shown = true;
	sld.startLocation = "Xsardas_Dungeon";
	sld.startLocator = "bottle";

	sld = CharacterFromID("Baltram");//��� ���� ���������
	sld.dialog.currentnode = "Baltram_hallo";
                  pchar.GenQuestBox.LeFransua_HouseHut5.box1.items.topor_015 = 1;

}
void Gothic_ReadBookSailor() // ����� �����
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FOUNDTREASURE.wav");
	DoQuestFunctionDelay("Gothic_ReadBookSailor_1", 3.5);
}

void Gothic_ReadBookSailor_1() // ����� �����
{
 	PlaySound("Interface\BOOK_TURNPAGE02.wav");
	DoQuestFunctionDelay("Gothic_ReadBookSailor_2", 3.5);
}
void Gothic_ReadBookSailor_2() // ������ �����
{
 	PlaySound("Interface\CHAPTER.wav");
	AddCharacterExpToSkill(pchar, "LEADERSHIP", 500);
	AddCharacterExpToSkill(pchar, "SAILING", 500);
	AddCharacterExpToSkill(pchar, "REPAIR", 500);
	AddCharacterExpToSkill(pchar, "COMMERCE", 500);
	AddQuestRecordInfo("BookSailor", "1");
}

void Gothic_Alligator(string qName)
{
                 LAi_ActorAnimation(pchar, "Ground_StandUp", "Gothic_Alligator_01", 3.5);
	ChangeCharacterAddressGroup(pchar, "Shore89", "goto", "goto3");
}

void Gothic_Alligator_1(string qName)
{
                   SetLaunchFrameFormParam("������ ��������� �����..."+ NewStr() +"", "", 0, 5);
	WaitDate("", 0, 0, 0, 3, 30); //������ �����
	LaunchFrameForm();
	RefreshLandTime();
	RecalculateJumpTable();
	Whr_UpdateWeather();
                   DoQuestFunctionDelay("Gothic_Alligator_2", 1.0);
}

void Gothic_Alligator_2(string qName)
{
	sld = characterFromId("Alligator");
	LAi_CharacterDisableDialog(sld);
                   LAi_SetActorType(sld);
                   LAi_ActorAnimation(sld, "Ground_StandUp", "Gothic_Alligator_03", 3.5);
}

void Gothic_Alligator_3(string qName)
{
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
                   DoQuestFunctionDelay("Gothic_Alligator_4", 2.0);
}

void Gothic_Alligator_4(string qName)
{
	sld = characterFromId("Alligator");
                  LAi_CharacterEnableDialog(sld);
                   LAi_SetActorType(sld);
                   LAi_ActorTurnToLocator(sld, "goto", "goto3");
                   LAi_SetActorType(pchar);
                   LAi_ActorAnimation(pchar, "Ground_StandUp", "Gothic_Alligator_05", 3.5);
}

void Gothic_Alligator_5(string qName)
{
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
                   LAi_SetPlayerType(pchar);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "Alligator_9";
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	StartQuestMovie(true, true, true);
                   SetCharacterTask_None(GetMainCharacter());
                   LAi_LockFightMode(Pchar, true);
	InterfaceStates.Buttons.Save.enable = false;
}

void Gothic_Alligator_6(string qName)
{
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "Alligator_9";
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_Alligator_7(string qName)
{
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "Alligator_16";
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Gothic_Alligator_8(string qName)
{
                   LAi_SetActorType(pchar);
                   DoQuestFunctionDelay("Gothic_Alligator_9", 2.0);
}

void Gothic_Alligator_9(string qName)
{
                   DoQuestFunctionDelay("DEMENTHORTALK", 2.0);
	// �������
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sQuest = "";
	string VaterSkelName[4];
	VaterSkelName[0] = "VaterSkel_1";
	VaterSkelName[1] = "VaterSkel_2";
	VaterSkelName[2] = "VaterSkel_3";
	VaterSkelName[3] = "VaterSkel_4";
	for (int i=0; i<=2; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("VaterSkel_" + i, VaterSkelName[i], "skeleton", "skeleton", 35, PIRATE, 0, true, "quest"));
		FantomMakeCoolFighter(chr, iRank+2, 60, 60, LinkRandPhrase("blade_10","blade_06","blade_04"), "pistol05", "bullet", 50);
		chr.monster = true; // ������� ������
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		chr.gotoGroup = "reload";
		chr.gotoLocator = "reload3";
		LAi_SetActorType(chr); 
		ChangeCharacterAddressGroup(chr, "Shore89", "goto", "goto15");

			}

                   LAi_SetActorType(pchar);
                   LAi_ActorTurnToLocator(pchar, "goto", "goto15");
                   DoQuestFunctionDelay("Gothic_Alligator_10", 2.0);

}

void Gothic_Alligator_10(string qName)
{
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	for (int i=0; i<=2; i++)
	{
	chr = characterFromId("VaterSkel_" + i);
FantomMakeCoolFighter(chr, iRank+2, 60, 60, LinkRandPhrase("blade_10","blade_06","blade_04"), "pistol5", "bullet", 50);
		chr.monster = true; // ������� ������
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
                  LAi_ActorGoToLocation(chr, "reload", "reload1_back", "Shore89", "reload", "reload1_back", "", 100.0);
	}
                   DoQuestFunctionDelay("Gothic_Alligator_11", 40.0);
}

void Gothic_Alligator_11(string qName)
{
	sld = characterFromId("Alligator");
                   LAi_SetActorType(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
	sld.dialog.currentnode = "Alligator_30";
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
                   LAi_SetPlayerType(pchar);
}

void Gothic_Alligator_12(string qName)
{
	                   int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	                   int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	                  for (i=0; i <= 2; i++)
	                  {
	                   chr = characterFromId("VaterSkel_" + i);
	FantomMakeCoolFighter(chr, iRank+2, 60, 60, LinkRandPhrase("blade_10","blade_06","blade_04"), "pistol5", "bullet", 50);
		chr.monster = true; // ������� ������
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	                  }
	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("EnemyFight", "");
	LAi_SetFightMode(pchar, true);
	if (i == 2) 
	                    {
		TakeNItems(chr, "jewelry53", 2);
		TakeNItems(chr, "jewelry52", 4);
		TakeNItems(chr, "Destiny_GiftPearl", 3);
	                   }
	//���������� � ������
	for (int i=0; i<=2; i++)
	{
                   sld = characterFromId("Alligator");
                   LAi_SetWarriorType(sld);
                   LAi_ActorDialog(sld, pchar, "", -1, 0);
	           sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
                   sld.dialog.currentnode = "killVaterSkel";
                   LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);


	}

}

void Gothic_Alligator_NPC_Death()
{
	sld = characterFromId("Alligator");
                  LAi_SetActorType(sld);
                  LAi_ActorDialog(sld, pchar, "", -1, 0);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Alligator.c";
                  sld.dialog.currentnode = "killVaterSkel";
}


		// --> ������ �������������
void Abuyin_house_1(string qName)
{
	SendMessage(&locCamera, "lfffl", MSG_CAMERA_TOPOS, 1.19, 2.2, 1.23, false);
	sld = characterFromId("Abuyin");
	LAi_SetImmortal(sld, false);
	LAi_SetActorType(sld);
	LAi_SetActorType(Pchar);
                   LAi_ActorGoToLocation(sld, "barmen", "stay", "LeFransua_HouseInsideR1", "goto", "goto2", "Abuyin_house_2", -1);
                        LAi_ActorGoToLocation(Pchar, "goto", "goto5", "LeFransua_HouseInsideR1", "goto", "goto6", "Abuyin_house_2", -1);
	DoQuestFunctionDelay("Abuyin_house_2", 7.0);
}
void Abuyin_house_2(string qName)
{
	SendMessage(&locCamera, "lfffl", MSG_CAMERA_TOPOS, 2.50, 0.9, -2.70, false);
	sld = characterFromId("Abuyin");
	LAi_SetImmortal(sld, false);
	LAi_SetGroundSitTypeNoGroup(sld);
                   LAi_ActorTurnToCharacter(pchar, sld);

	CreateLocationParticles("item", "quest", "wall", 1.0, 0, 0, "");
	CreateLocationParticles("item", "quest", "wall", 1.0, 0, 0, "");
	CreateLocationParticles("item", "quest", "wall", 1.0, 0, 0, "");
	PlaySound("Ambient\CAVE\MYSTERY_07.wav");
	sld = characterFromId("Abuyin");
	ChangeCharacterAddressGroup(sld, "LeFransua_HouseInsideR1", "goto", "goto2");
	LAi_SetGroundSitTypeNoGroup(Pchar);
	ChangeCharacterAddressGroup(Pchar, "LeFransua_HouseInsideR1", "goto", "goto6");
	sTotalTemp = "wall";
	iTotalTemp = 4;	
}
void Abuyin_house_3(string qName)
{
	sld = characterFromId("Abuyin");
	LAi_SetImmortal(sld, false);
	LAi_SetBarmanType(sld);
	LAi_RemoveLoginTime(sld);
	sld.Dialog.Filename = "Gothic_Quest\Gothic_npc\Abuyin.c";
	sld.dialog.currentnode = "First time";
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	LAi_SetImmortal(sld, true);
	LAi_SetPlayerType(Pchar);
 	ChangeCharacterAddressGroup(sld, "LeFransua_HouseInsideR1", "goto", "goto2");

}

		// <--������ �������������

		// --> ����� �� �������

//-------------------------------------����-------------------------------------

void Gothic_Grog() // ����
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_Grog_1", 1.2);
}

void Gothic_Grog_1() //�������
{
 	PlaySound("Interface\podtverjd_001.wav");
	DoQuestFunctionDelay("Gothic_Grog_2", 1.0);
}

void Gothic_Grog_2() //������
{
  	PlaySound("Ambient\Tavern\glotok_001.wav");
	DoQuestFunctionDelay("Gothic_Grog_3", 1.2);
}
void Gothic_Grog_3() // ���������
{
  	PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
	pchar.GenQuest.CamShuttle = 3;
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	AddCharacterExpToSkill(pchar, "Leadership", 20);
}

//-------------------------------------���-------------------------------------

void Gothic_Rumm() // ���
{

 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_Rumm_1", 1.2);
}

void Gothic_Rumm_1() //�������
{
 	PlaySound("Interface\podtverjd_001.wav");
	DoQuestFunctionDelay("Gothic_Rumm_2", 1.0);
}

void Gothic_Rumm_2() //������
{
  	PlaySound("Ambient\Tavern\glotok_001.wav");
	DoQuestFunctionDelay("Gothic_Rumm_3", 1.2);
}
void Gothic_Rumm_3() // ���������
{
  	PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
	pchar.GenQuest.CamShuttle = 3;
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	AddCharacterExpToSkill(pchar, "FencingL", 10);
}

//-------------------------------------������� ������-------------------------------------

void Gothic_Schnellerhering() // ������� ������
{

 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_Schnellerhering_1", 1.2);
}

void Gothic_Schnellerhering_1() //�������
{
 	PlaySound("Interface\podtverjd_001.wav");
	DoQuestFunctionDelay("Gothic_Schnellerhering_2", 1.0);
}

void Gothic_Schnellerhering_2() //������
{
  	PlaySound("Ambient\Tavern\glotok_001.wav");
	DoQuestFunctionDelay("Gothic_Schnellerhering_3", 1.2);
}
void Gothic_Schnellerhering_3() // ���������
{
  	PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
	pchar.GenQuest.CamShuttle = 3;
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	AddCharacterExpToSkill(pchar, "FencingS", 10);
}

//-------------------------------------������� ��-------------------------------------

void Gothic_Loushammer() //������� ��
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_Loushammer_1", 1.2);
}

void Gothic_Loushammer_1() //�������
{
 	PlaySound("Interface\podtverjd_001.wav");
	DoQuestFunctionDelay("Gothic_Loushammer_2", 1.0);
}

void Gothic_Loushammer_2() //������
{
  	PlaySound("Ambient\Tavern\glotok_001.wav");
	DoQuestFunctionDelay("Gothic_Loushammer_3", 1.2);
}
void Gothic_Loushammer_3() // ���������
{
  	PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
	AddCharacterExpToSkill(pchar, "FencingH", 10);
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	pchar.GenQuest.CamShuttle = 3;
}

//-------------------------------------������� ����� ��-------------------------------------

void Gothic_Lousdoublehammer() //������� ����� ��
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\VERSTEHE.wav");
	DoQuestFunctionDelay("Gothic_Lousdoublehammer_1", 1.2);
}

void Gothic_Lousdoublehammer_1() //�������
{
 	PlaySound("Interface\podtverjd_001.wav");
	DoQuestFunctionDelay("Gothic_Lousdoublehammer_2", 1.0);
}

void Gothic_Lousdoublehammer_2() //������
{
  	PlaySound("Ambient\Tavern\glotok_001.wav");
	DoQuestFunctionDelay("Gothic_Lousdoublehammer_3", 1.2);
}
void Gothic_Lousdoublehammer_3() // ���������
{
  	PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
	AddCharacterExpToSkill(pchar, "Pistol", 20);
	LAi_SetCurHPMax(PChar);
	AddCharacterHealth(pchar, 50);
	pchar.GenQuest.CamShuttle = 3;
}

//-------------------------// <-- ����� �� �������


//-------------------------// --> ������������ -------------------------------------
void Gothic_OfficerReincarnation(ref rOff, ref rPassanger, aref _chr, int _step)
{

  	PlaySound("VOICE\Russian\gotica\SFX\MFX_DESTROYUNDEAD_CAST.wav");
	CreateLocationParticles("fire_incas_Simple", "goto", sTemp, 0.5, 0, 0, "");

	CreateLocationParticles("fire_incas_Simple", "goto", "top", 0.5, 0, 0, "");
	CreateLocationParticles("fire_incas_Simple", "goto", "top", 1.0, 0, 0, "");
	CreateLocationParticles("fire_incas_Simple", "goto", "top", 1.5, 0, 0, "");

 
        DoQuestFunctionDelay("OfficerReincarnation_1", 1.5);
}

void OfficerReincarnation_1();
{
	for (i=1; i<=3; i++)
	{
	CreateLocationParticles("blast_inv", "goto", "goto"+i, 1.0, 0, 0, "");
	}

}

//-------------------------// <-- ������������
				// --> ���� ������� �������

void GothicVaterSkel_Shore()
{
                   PlaySound("VOICE\Russian\gotica\SFX\TRO_GROWL02.wav");
	// �������� �������
	int iRank = 16+MOD_SKILL_ENEMY_RATE*2;
	int iHp = 200+MOD_SKILL_ENEMY_RATE*80;
	string sQuest = "";
	string VaterskelName[4];
	VaterSkelName[0] = "VaterSkel_1";
	VaterSkelName[1] = "VaterSkel_2";
	VaterSkelName[2] = "VaterSkel_3";
	VaterSkelName[3] = "VaterSkel_4";

	for (int i=1; i<=2; i++)
	{
		chr = GetCharacter(NPC_GenerateCharacter("VaterSkel"+i, "VaterSkel_"+(rand(3)+1), "skeleton", "skeleton", iRank, PIRATE, -1, false, "quest"));
		FantomMakeCoolFighter(chr, 30, 60, 60, LinkRandPhrase("blade_11","blade_12","blade_13"), "pistol1", "cartridge", 50);
	                    LAi_SetCharacterUseBullet(chr, "grapeshot");
                                         TakeNItems(chr, "grapeshot", 9);
	                    TakeNItems(chr, "bullet", 18);
	                    TakeNItems(chr, "GunPowder", 56);
		chr.monster = true; // ������� ������
		chr.sex = "Skeleton"; 
		chr.viper = true;
		chr.LSC_clan = true;
	                     chr.SaveItemsForDead   = true;// ��������� �� ����� ����
	                     chr.DontClearDead = true;
		LAi_CharacterDisableDialog(chr);
		LAi_SetWarriorType(chr);
		LAi_group_MoveCharacter(chr, "EnemyFight");
	                    ChangeCharacterAddressGroup(chr, "Hispaniola_Cave_2", "item", "item2");
		if(i == 2)
		{
		TakeNItems(chr, "jewelry8", 20);
		TakeNItems(chr, "fennis_grass", 10);
		TakeNItems(chr, "talisman8", 8);
		TakeNItems(chr, "cannabis7", 10);
		TakeNItems(chr, "purse3", 10);
		}
		else
		{
	                     sld = GetCharacter(NPC_GenerateCharacter("VaterSkelMush", "VaterSkel_3_mush", "man", "mushketer", 40, PIRATE, -1, true, "quest"));
	                     FantomMakeCoolFighter(sld, 40, 100, 100, "", "mushket1", "cartridge", 70);
		LAi_SetCharacterUseBullet(sld, "cartridge");
	                    TakeNItems(sld, "GunPowder", 56);
	                     SetCharacterPerk(sld, "Gunman");
		sld.monster = true; // ������� ������
		sld.sex = "Skeleton"; 
		sld.viper = true;
		sld.LSC_clan = true;
	                     sld.SaveItemsForDead   = true;// ��������� �� ����� ����
	                     sld.DontClearDead = true;
		LAi_CharacterDisableDialog(sld);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
	                    ChangeCharacterAddressGroup(sld, "Hispaniola_Cave_2", "item", "item3");
	          }
	}

	LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
	LAi_SetFightMode(pchar, true);

	pchar.quest.Caleuche_find_amulet.win_condition.l1 = "item";
	pchar.quest.Caleuche_find_amulet.win_condition.l1.item = "kaleuche_amulet1";
	pchar.quest.Caleuche_find_amulet.function = "Caleuche_FindFirstAmulet";
	// ����� ����� ���
	int n = Findlocation("KhaelRoa_port");
	locations[n].image = "loading\haelroa_" + rand(1) + ".tga";
	locations[n].type = "questisland";
	locations[n].locators_radius.reload.reload2 = 2;
	locations[n].questflower = 1;
	// ���� ������ ���������� ��� ����� ��������
	// �������� 9 �������� ������ - ��������� �������
	pchar.questTemp.Caleuche.Tile = rand(4);
	switch (sti(pchar.questTemp.Caleuche.Tile))
	{
		case 0: pchar.questTemp.Caleuche.NextTile = "step1"; break;
		case 1: pchar.questTemp.Caleuche.NextTile = "step4"; break;
		case 2: pchar.questTemp.Caleuche.NextTile = "step7"; break;
		case 3: pchar.questTemp.Caleuche.NextTile = "step7"; break;
		case 4: pchar.questTemp.Caleuche.NextTile = "step1"; break;
	}
	// �������� 6 ������� - ��������� ������������������
	pchar.questTemp.Caleuche.LeftLevers = rand(4);
	pchar.questTemp.Caleuche.RightLevers = rand(4);
	// ���� ���������
	sld = ItemsFromID("MerrimanBook");
	sld.picTexture = "ITEMS_18";
	sld.picIndex = 14;
	sld.model = "BrassBox";
	sld.shown = true; 
	sld.Weight = 8.0;
	sld.startLocation = "Havana_CryptDungeon";
	sld.startLocator = "item2";
	// ������ ��������
	sld = ItemsFromID("suit4");
	sld.B_CirassLevel = 0.15;
	sld.G_CirassLevel = 0.10;
	DeleteAttribute(sld, "critical");
 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  ������
/////////////////////////////////////////////////////////////////////////////////////////////////////////


void Gothic_Baltram_Caleuche()//���� ��������� �������
{
	SetFunctionTimerCondition("Gothic_Baltram_Caleuche_1", 0, 0, 20, false);
	sld = characterFromId("Baltram");
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	sld.dialog.currentnode = "BaltramCaleuche";
	LAi_SetImmortal(sld, true);
	LAi_SetLoginTime(sld, 8.0, 20.99);
	RemoveAllCharacterItems(sld, true);
	ChangeCharacterAddressGroup(sld, "FortOrange_town", "goto", "goto22");
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	LocatorReloadEnterDisable("FortFrance_town", "houseH6", true);//������� ��������� �������

}

void Gothic_Baltram_Caleuche_1(string qName)
{
                sld = characterFromId("Baltram");
                LAi_SetActorType(sld);
                LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
	        LocatorReloadEnterDisable("FortFrance_town", "houseH6", false);//������� ��������� �������

} 


void Gothic_BaltramMtraxx()//���� ��������� Addon 2016-1 Jason ��������� ������� 
{
	SetFunctionTimerCondition("Gothic_BaltramMtraxx_1", 0, 0, 3, false);
	sld = characterFromId("Baltram");
	sld.Dialog.FileName = "Gothic_Quest\GothicLine\Baltram.c";
	sld.dialog.currentnode = "Baltramrocur";
	LAi_SetImmortal(sld, true);
	LAi_SetLoginTime(sld, 8.0, 20.99);
	RemoveAllCharacterItems(sld, true);
	ChangeCharacterAddressGroup(sld, "Maracaibo_town", "goto", "goto2");
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

}

void Gothic_BaltramMtraxx_1(string qName)
{
                sld = characterFromId("Baltram");
                LAi_SetActorType(sld);
                LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
} 


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  ������� ������� ������
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void Monbar_StartGame_1(string qName)
{
                //DoQuestCheckDelay("_XARDAS_1", 0.1);
                sld = CharacterFromID("Xsardas");
                LAi_SetPriestType(sld);
                LAi_ActorAnimation(sld, "Bead", "", -1);
                LAi_ActorTurnToLocator(sld, "quest", "quest3"); 

}

void Monbar_StartGame_2(string qName)
{
                Pchar.BaseNation = FRANCE;
               //fix ������ ������
                DeleteAttribute(Pchar, "perks.list.FlagEng");
                DeleteAttribute(Pchar, "perks.list.FlagSpa");
                DeleteAttribute(Pchar, "perks.list.FlagHol");
                SetCharacterPerk(Pchar, "FlagFra");
                Flag_FRANCE();
                pchar.questTemp.GothicMonbar = "MonbarLineMyxir";
                pchar.questTemp.GothicXsardas = "MonbarLineXsardas";
               // ������ ������� ��
                sld = ItemsFromID("Loushammer");
                sld.shown = true;
                sld.startLocation = "Xsardas_Dungeon";
                sld.startLocator = "bottle";
                DoQuestReloadToLocation("Xsardas_Dungeon", "goto", "goto38", "");
                sld = CharacterFromID("Xsardas");
                ChangeCharacterAddressGroup(sld, pchar.location, "sit", "sit1");
                LAi_SetSitType(sld);
}

void Monbar_StartGame_3(string qName)
{
                  chrDisableReloadToLocation = false; 
                  LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);//������� ���� � ����� 
	sld = characterFromId("Sh_startsailor");
	LAi_SetActorType(sld);
	LAi_ActorGoToLocation(sld, "reload", "reload5", "none", "", "", "FortFrance_Graveyard", 10.0);

	for (i=1; i<=20; i++)//�������
	{
	sld = GetCharacter(NPC_GenerateCharacter("MaltaOfficer_"+i, "sold_fra_"+i, "man", "man", 20, FRANCE, -1, true, "soldier"));
	FantomMakeCoolFighter(sld, 20, 40, 40, "blade_13", "pistol3", "bullet", 70);
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	LAi_SetStayType(sld);
	LAi_CharacterDisableDialog(sld);
	ChangeCharacterAddressGroup(sld, "FortFrance_town", "rld", "loc"+i);
	}

}


