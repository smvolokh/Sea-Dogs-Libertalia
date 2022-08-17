#include "battle_interface\msg_control.h"
#include "sea_ai\script_defines.h"
#include "battle_interface\landinterface.c"
#include "battle_interface\ispyglass.c"
#include "battle_interface\reload_tables.c"
#include "battle_interface\utils.c"
#include "battle_interface\ActivePerksShow.c"
#include "battle_interface\backgroundtask.c"
#include "battle_interface\WmInterface.c"

#define BI_ICONS_SHIPS_TEXTURE_NAME "battle_interface\icons.tga"

#define BI_ICONS_ST_NONE		0
#define BI_ICONS_ST_MYSHIPS		1
#define BI_ICONS_ST_COMMAND		2
#define BI_ICONS_ST_TARGETING		3

#define BI_ICONS_TEXTURE_COMMAND	0
#define BI_ICONS_TEXTURE_SHIP1		1
#define BI_ICONS_TEXTURE_ABILITY	2

#define 	FLAG_ADM		0	// ���������������� �����
#define 	FLAG_HOL		1	// ����������� �����
#define 	FLAG_ENG		2	// ���������� �����
#define 	FLAG_FRA		3	// ����������� �����
#define 	FLAG_SPA		4	// ��������� �����
#define 	FLAG_ALT		5	// �������������� ����� 
#define 	FLAG_WHT		6	// ����� �����
#define	FLAG_PIR		7	// ��������� �����

int bi_icons_ShowType;
int bi_icons_CommandMode;

int bi_idxSelectedPicture;

object BattleInterface;

bool bDisableSailTo = false;

bool bDisableMapEnter = false;

bool bReloadCanBe = false;
bool bMapEnter = false;
bool bSailTo=false;
bool bAttack=false;
bool bAbordage = false;
bool bDefend=false;

//speak interface
//bool bCanSpeak = false;
//bool bCanSneak = false;

bool bEnableIslandSailTo = false;

int BI_intRetValue;
int BI_retComValue;
int BI_ChargeState[5];
float BI_g_fRetVal;

int BI_intNRetValue[8];

object BI_objRetValue;
object objShipPointer;
// boal -->
bool boal_soundOn = true;
// boal <--

#event_handler("evntRandomSailDmg","ProcessRandomSailDmg");
#event_handler("evntGetSailStatus","procGetSailStatus");
//#event_handler("NextDay","ProcessDayRepair");
#event_handler("GetSailTextureData","procGetSailTextureData");
#event_handler("EventMastFall","procMastFall");
#event_handler("evntGetSmallFlagData","procGetSmallFlagData");

#event_handler(SHIP_CREATE,"BI_CreateShip");
#event_handler("GetRiggingData","procGetRiggingData");

void InitBattleInterface()
{
	BI_InitializeCommands();
	bi_icons_CommandMode = 0;
	BattleInterface.comstate = 0;
	BattleInterface.SelCharacter = -1;
	bi_idxSelectedPicture = -1;
	BattleInterface.boardRadius = 50;
	BattleInterface.freeDistance = MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER;

	SetParameterData();
		
	BattleInterface.blindSpeed = 0.003;
	BattleInterface.MaxWind = 30.0;
	BattleInterface.MaxShipSpeed = 20.0;
	if (iArcadeSails == 1) 
	{
		BattleInterface.ShipSpeedScaler = (1.0 / 2.5);
	} 
	else 
	{
		BattleInterface.ShipSpeedScaler = (1.0 / 1.0);
	}
	BattleInterface.ShowNavigator = InterfaceStates.BattleShow.Navigator;
	BattleInterface.ShowCommands = InterfaceStates.BattleShow.Command;
	BattleInterface.MainChrIndex = nMainCharacterIndex;
	CreateEntity(&BattleInterface,"battle_interface");
	DeleteAttribute(&BattleInterface,"CommandTextures");
	DeleteAttribute(&BattleInterface,"CommandShowParam");
	LayerAddObject(SEA_EXECUTE,&BattleInterface,-1);
	LayerAddObject(SEA_REALIZE,&BattleInterface,-1);
	
	SetEventHandler(SHIP_DELETE,"BI_DeleteShip",0);
	SetEventHandler(SHIP_DEAD,"BI_DeadShip",0);

	SetEventHandler("BI_CommandEndChecking","BI_CommandEndChecking",0);
	SetEventHandler("BI_LaunchCommand","BI_LaunchCommand",0);
	SetEventHandler("BI_GetChargeQuantity","BI_GetChargeQuantity",0);
	SetEventHandler("BI_SetPossibleCommands","BI_SetPossibleCommands",0);
	SetEventHandler("GetCurrentCharge","GetCurrentCharge",0);
	SetEventHandler("evntGetCharacterShipClass","biGetCharacterShipClass",0);
	SetEventHandler(BI_EVENT_SET_VISIBLE,"BI_CommandVisible",0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE,"BI_SetSeaState",0);
	SetEventHandler(BI_EVENT_GET_DATA,"BI_GetData",0);
	SetEventHandler(BI_EVENT_CHECK_SHIPSTATE_SHOW,"BI_GetSSShow",0);
	SetEventHandler("evntGetLandData","BI_GetLandData",0);
	SetEventHandler(BI_EVENT_GET_FORT_RELATION,"BI_GetFortRelation",0);
	SetEventHandler(EVENT_CHANGE_COMPANIONS,"RefreshBattleInterface",0);
	SetEventHandler("BI_CallUpdateShip","BI_UpdateShip",0);
	SetEventHandler("frame","BI_Frame",1);
	SetEventHandler("evntPerkAgainUsable","BI_PerkAgainUsable",0);
	SetEventHandler("evntSetUsingAbility","procSetUsingAbility",0);
	SetEventHandler("evntCheckEnableLocator","procCheckEnableLocator",0);
	SetEventHandler("evntCheckEnableShip","procCheckEnableShip",0);
	SetEventHandler("evntGetSRollSpeed","procGetSRollSpeed",0);
	SetEventHandler("DoSailHole","ProcessSailDamage",0);
	SetEventHandler("evntBISelectShip","procBISelectShip",0);

	procLoadIntoNew(); // ��������� ������� �������� ������
	SetEventHandler("Control Activation","BI_ProcessControlPress",0);
	
	CreateILogAndActions(LOG_FOR_SEA);
	Log_SetActiveAction("Nothing");
	ResetTimeScale(); // boal
}

ref BI_GetFortRelation()
{
	BI_intRetValue = BI_RELATION_NEUTRAL;
	aref arLoc = GetEventData();
	int chrIdx = Fort_FindCharacter(AISea.Island,"reload",arLoc.name);
	if(chrIdx>=0)
	{
		switch( SeaAI_GetRelation(chrIdx,nMainCharacterIndex) )
		{
		case RELATION_FRIEND:	BI_intRetValue = BI_RELATION_FRIEND;	break;
		case RELATION_NEUTRAL:	BI_intRetValue = BI_RELATION_NEUTRAL;	break;
		case RELATION_ENEMY:	BI_intRetValue = BI_RELATION_ENEMY;		break;
		}
	}
	/*string sColony = arLoc.colonyname;
	if (BI_intRetValue == BI_RELATION_ENEMY || CheckForDeclineLoadToColony(sColony) == 1)
	{
		bCanSneak = true;
	}      */
	return &BI_intRetValue;
}

ref BI_GetSSShow()
{
	BI_intRetValue = false;
	int charIdx = GetEventData();
	switch( GetCharacterEquipByGroup(pchar, SPYGLASS_ITEM_TYPE) )
	{
	case CHEAP_SPYGLASS:	BI_intRetValue = false;	break;
	case COMMON_SPYGLASS:	BI_intRetValue = true;	break;
	case GOOD_SPYGLASS:		BI_intRetValue = true;	break;
	case SUPERIOR_SPYGLASS:	BI_intRetValue = true;	break;
	}
	return &BI_intRetValue;
}

void BI_CommandVisible()
{
	int visibleFlag = GetEventData();
	SendMessage(&BattleInterface,"ll",BI_SET_VISIBLE,visibleFlag);
}

int bi_nReloadTarget=-1;
bool biold_bCanEnterToLand = false;
bool biold_bAbordageShipCanBe = false;
bool biold_bAbordageFortCanBe = false;
bool biold_bReloadCanBe = false;
bool biold_bMapEnter = false;
bool bOldNotEnoughBalls = false;

void BI_Frame()
{
	bool bYesUpdateCommand = false;
	if(bNotEnoughBalls!=bOldNotEnoughBalls)
	{
		bOldNotEnoughBalls = bNotEnoughBalls;
		if(bNotEnoughBalls)
		{
			SendMessage(&BattleInterface,"ll",BI_MSG_NOT_ENOUGH_BALLS_FLAG,true);
		}
		else
		{
			SendMessage(&BattleInterface,"ll",BI_MSG_NOT_ENOUGH_BALLS_FLAG,false);
		}
	}

	if(biold_bAbordageShipCanBe!=bAbordageShipCanBe)
	{
		bYesUpdateCommand = true;
		biold_bAbordageShipCanBe = bAbordageShipCanBe;
	}
	if(biold_bAbordageFortCanBe!=bAbordageFortCanBe)
	{
		bYesUpdateCommand = true;
		biold_bAbordageFortCanBe = bAbordageFortCanBe;
	}
	if(biold_bCanEnterToLand!=bCanEnterToLand)
	{
		bYesUpdateCommand = true;
		biold_bCanEnterToLand = bCanEnterToLand;
	}
	if(biold_bReloadCanBe!=bReloadCanBe)
	{
		bYesUpdateCommand = true;
		biold_bReloadCanBe = bReloadCanBe;
	}
	if(biold_bMapEnter!=bMapEnter)
	{
		bYesUpdateCommand = true;
		biold_bMapEnter = bMapEnter;
	}

	if(bYesUpdateCommand)
	{
		BI_SetCommandMode(-1,-1,-1,-1);
	}

	if(bAbordageShipCanBe)
	{
		Log_SetActiveAction("Board");
		// boal -->
		if (boal_soundOn)
		{
		    boal_soundOn = false;
            PlaySound("interface\_abordage"+rand(15)+".wav");
		}
		// boal <--
		return;
	}
	if(bAbordageFortCanBe)
	{
		Log_SetActiveAction("LandTroops");
		// boal -->
		if (boal_soundOn)
		{
		    boal_soundOn = false;
            PlaySound("interface\_Abandon0.wav");
		}
		// boal <--
		return;
	}
	if(bReloadCanBe)
	{
		Log_SetActiveAction("Reload");
		return;
	}
	if(bCanEnterToLand)
	{
		Log_SetActiveAction("Moor");
		// boal -->
		if (boal_soundOn)
		{
		    boal_soundOn = false;
            PlaySound("interface\_Yakordrop.wav");
  PlaySound("interface\_EvLand"+rand(1)+".wav");
		}
		// boal <--
		return;
	}
	// boal -->
	boal_soundOn = true;
	// boal <--
	if(bMapEnter)
	{
		Log_SetActiveAction("Map");
		return;
	}
	Log_SetActiveAction("Nothing");
}

void StartBattleInterface()
{
	bi_nReloadTarget = -1;
	bi_icons_ShowType = BI_ICONS_ST_MYSHIPS;
	BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
	BI_SetIslandData();
	InterfaceSpyGlassInit(false);
	objShipPointer.textures.friend = "battle_interface\Frendly.tga";
	objShipPointer.textures.enemy = "battle_interface\Enemy.tga";
	CreateEntity(&objShipPointer,"shippointer");
	LayerAddObject(SEA_EXECUTE,&objShipPointer,222222);
	LayerAddObject(SEA_REALIZE,&objShipPointer,-1);
}

void RefreshBattleInterface()
{
	BI_SetCommandMode(0,-1,-1,-1);
	SendMessage(&BattleInterface,"l",BI_MSG_REFRESH);
	BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
}

void DeleteBattleInterface()
{
    ResetTimeScale(); // boal
    
	Log_SetActiveAction("Nothing");
	InterfaceSpyGlassRelease();

    DeleteClass(&BattleInterface);
	DeleteClass(&objShipPointer);
	
	DelEventHandler(SHIP_DELETE, "BI_DeleteShip");
	DelEventHandler(SHIP_DEAD,"BI_DeadShip");
	DelEventHandler("BI_CommandEndChecking", "BI_CommandEndChecking");
	DelEventHandler("BI_LaunchCommand", "BI_LaunchCommand");
	DelEventHandler("BI_GetChargeQuantity","BI_GetChargeQuantity");
	DelEventHandler("BI_SetPossibleCommands","BI_SetPossibleCommands");
	DelEventHandler("GetCurrentCharge","GetCurrentCharge");
	DelEventHandler("evntGetCharacterShipClass","biGetCharacterShipClass");
	DelEventHandler(BI_EVENT_SET_VISIBLE,"BI_CommandVisible");
	DelEventHandler(BI_EVENT_SET_SEA_STATE,"BI_SetSeaState");
	DelEventHandler(BI_EVENT_GET_DATA,"BI_GetData");
	DelEventHandler(BI_EVENT_CHECK_SHIPSTATE_SHOW,"BI_GetSSShow");
	DelEventHandler("evntGetLandData","BI_GetLandData");
	DelEventHandler(BI_EVENT_GET_FORT_RELATION,"BI_GetFortRelation");
	DelEventHandler(EVENT_CHANGE_COMPANIONS,"RefreshBattleInterface");
	DelEventHandler("BI_CallUpdateShip","BI_UpdateShip");
	DelEventHandler("frame","BI_Frame");
	DelEventHandler("evntPerkAgainUsable","BI_PerkAgainUsable");
	DelEventHandler("evntSetUsingAbility","procSetUsingAbility");
	DelEventHandler("evntCheckEnableLocator","procCheckEnableLocator");
	DelEventHandler("evntCheckEnableShip","procCheckEnableShip");
	DelEventHandler("evntGetSRollSpeed","procGetSRollSpeed");
	DelEventHandler("Control Activation","BI_ProcessControlPress");
	DelEventHandler("DoSailHole","ProcessSailDamage");
	DelEventHandler("evntBISelectShip","procBISelectShip");

	// ��� ����� �������, ���� ������

	//DeleteClass(&BattleInterface);
	//DeleteClass(&objShipPointer);
}

ref BI_CommandEndChecking()
{
	BI_retComValue = 0;
	string comName = GetEventData();

	switch(comName)
	{
	// �����
    case "BI_Cabin":
		BI_retComValue = 0;
		break;
	// ������� ������ ��� ��������� --
	case "BI_Boat":
		BI_retComValue = BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT;
        BattleInterface.Commands.Boat.EffectRadius = DistanceToShipTalk;
		break;
	case "BI_Bomb":
		BI_retComValue = 0;
		break;
	case "cancel":
		BI_retComValue = -1;
		break;
	case "BI_Moor":
		BI_retComValue = 0;
		break;
	case "BI_SailTo":
		int iIsland = FindIsland(pchar.location);
		if(iIsland > 0 && !sti(Islands[iIsland].reload_enable))
		{
			bEnableIslandSailTo	= false;
		}
		if(bEnableIslandSailTo) {
			BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_FRIEND_FORT_SELECT+BI_COMMODE_NEUTRAL_FORT_SELECT+BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_DISEASED_TOWN+BI_COMMODE_NOTDISEASED_TOWN+BI_COMMODE_LAND_SELECT; //+BI_COMMODE_ALLLOCATOR_SELECT;
		} else {
			BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT;//+BI_COMMODE_ALLLOCATOR_SELECT;
		}
		if (bBettaTestMode || CheckAttribute(pchar, "CSM.SailToEffectRadius")) // --> CheatSurfMenu
		{
		    BattleInterface.Commands.SailTo.EffectRadius	= 900000;
		}
  		else
  		{
			if(iIsland > 0 && CheckAttribute(Islands[iIsland],"EffectRadius"))
			{
				BattleInterface.Commands.SailTo.EffectRadius = sti(Islands[iIsland].EffectRadius); 
			}
			else
			{
				string sSpyGlass = GetCharacterEquipByGroup(pchar, SPYGLASS_ITEM_TYPE);
				if(sSpyGlass != "")
				{
					ref rItm = ItemsFromID(sSpyGlass);
					BattleInterface.Commands.SailTo.EffectRadius	= 5000 + sti(rItm.radius);
				}
				else BattleInterface.Commands.SailTo.EffectRadius	= 5000; //boal
			}	
		}
		break;
	case "BI_Board":
		BI_retComValue = 0;
		break;
	case "BI_LandTroops":
		BI_retComValue = 0;
		break;
	case "BI_Map":
		BI_retComValue = 0;
		break;
	case "BI_Attack":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ENEMY_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
        BattleInterface.Commands.Attack.EffectRadius	= 2000; //boal
		break;
	case "BI_Abordage":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT;
		BattleInterface.Commands.Abordage.EffectRadius	= 2000; //boal
		break;
	case "BI_Defend":
		BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_FRIEND_FORT_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		BattleInterface.Commands.Defend.EffectRadius	= 2000; //boal
		break;
	case "BI_SailAway":
		BI_retComValue = 0;
		break;
	case "BI_HeaveToDrift":
		BI_retComValue = 0;
		break;
	case "BI_Reload":
		BI_retComValue = 0;
		break;
	case "BI_Charge":
		BI_retComValue = BI_COMMODE_CANNON_CHARGE;
		break;
	case "BI_Speed":
		BI_retComValue = BI_COMMODE_USER_ICONS;
		break;
	case "BI_CompanionCommand":
		BI_retComValue = BI_COMMODE_MY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
		
	case "BI_Brander":
		BI_retComValue = BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_ALLLOCATOR_SELECT;
		break;
	case "BI_ImmediateReload":
		BI_retComValue = 0;
		break;
	case "BI_LightRepair":
		BI_retComValue = 0;
		break;		
	case "BI_InstantRepair":
		BI_retComValue = 0;
		break;
		
	case "BI_Turn180":
		BI_retComValue = 0;
		break;
		
	case "BI_Ability":
		BI_retComValue = BI_COMMODE_ABILITY_ICONS;
		break;

	case "BI_ImmDeath":
		BI_retComValue = BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT+BI_COMMODE_FRIEND_FORT_SELECT+BI_COMMODE_NEUTRAL_FORT_SELECT+BI_COMMODE_ENEMY_FORT_SELECT;
		BattleInterface.Commands.ImmediateDeath.EffectRadius	= 900000;
	break;

	case "BI_InstantBoarding":
		BI_retComValue = BI_COMMODE_NEUTRAL_SHIP_SELECT+BI_COMMODE_FRIEND_SHIP_SELECT+BI_COMMODE_ENEMY_SHIP_SELECT;
	break;
	}

	return &BI_retComValue;
}

void BI_LaunchCommand()
{
	bool bOk;
	int charIdx = GetEventData();
	string commandName = GetEventData();
	int targetNum = GetEventData();
	string locName = GetEventData();
	ref chRef = GetCharacter(charIdx);
	if( LAi_IsDead(chRef) ) return;

	aref arFader;
	if( FindClass(arFader,"fader") ) {return;}

	if(targetNum==-1 && locName=="cancel") {
		SendMessage(&BattleInterface,"ls",MSG_BATTLE_LAND_MAKE_COMMAND,"cancel");
		return;
	}
	if(commandName=="cancel") {
		SendMessage(&BattleInterface,"ls",MSG_BATTLE_LAND_MAKE_COMMAND,"cancel");
		return;
	}

	string alternativeCommand;
	if( CheckAttribute( &BattleInterface, "AbilityIcons."+commandName+".quest" ) )
	{
		alternativeCommand = commandName;
		commandName = "BI_UseItemAbilitie";
	}

	switch(commandName)
	{
    case "BI_Cabin":
        Sea_CabinStartNow();
		break;
	case "BI_Boat":
		// Warship 09.07.09 ���� ������
		// ������ ��� �� ��� ������� ������ ����
		if(Characters[targetNum].id != "MaryCelesteCapitan" || PChar.QuestTemp.MaryCeleste != "OnDeck")
		{
			Sea_DeckBoatLoad(targetNum);
		}
		else
		{
			PlaySound("interface\knock.wav");
		}
    break;
	
	 case "BI_Bomb":
        if (GetCargoGoods(chRef, GOOD_POWDER) >= 200 && GetRemovable(chRef)) SetMineFree(chRef, 1); // fix ugeen 21.12.13
		else PlaySound("interface\knock.wav");
		break;
		
	case "BI_Charge":
		int chargeType=GOOD_BALLS;
		switch(targetNum)
		{
		case 1:
			//Log_SetStringToLog("Cannonballs");
			PlaySound("interface\_balls.wav");
			chargeType=GOOD_BALLS;
			break;
		case 2:
			//Log_SetStringToLog("Grapes");
			PlaySound("interface\_grapes.wav");
			chargeType=GOOD_GRAPES;
			break;
		case 3:
			//Log_SetStringToLog("Knippels");
			PlaySound("interface\_chain.wav");
			chargeType=GOOD_KNIPPELS;
			break;
		case 4:
			//Log_SetStringToLog("Bombs");
			PlaySound("interface\_bombs.wav");
			chargeType=GOOD_BOMBS;
			break;
		}
		Ship_ChangeCharge(chRef, chargeType);
		// ������� �� ����, ��� ������� ����� ������� ���� ���� �� � ��� ����, ��� �������� ����� ������, ������� ������� ���������� ��� ���
		chRef.ShipCannonChargeType = chargeType;
		break;
	case "BI_Map":
		if (bMapEnter)  // boal �� ����� ��� �����, � ��� ����
        {
            //pchar.location = "";
			Sea_MapLoad();
        }
        else
        {
            Log_SetStringToLog("����� �� ����� ������.");
        }
		break;
	case "BI_Moor":
		Sea_LandLoad();
		break;
	case "BI_Board":
		Sea_AbordageLoad(SHIP_ABORDAGE,true);
		break;
	case "BI_LandTroops":
		Sea_AbordageLoad(FORT_ABORDAGE,true);
		break;
	case "BI_SailAway":
		if (CheckAttribute(&characters[charIdx], "SeaAI.Task.Target"))  //fix
		{
			Ship_SetTaskRunAway(SECONDARY_TASK, charIdx, sti(characters[charIdx].SeaAI.Task.Target));
		}
		else
		{
			Ship_SetTaskRunAway(SECONDARY_TASK, charIdx, GetMainCharacterIndex()); // boal fix ���� ����� ���, �� �� �� ���������
		}
	break;
	case "BI_HeaveToDrift":
		Ship_SetTaskDrift(SECONDARY_TASK,charIdx);
		break;
	case "BI_Defend":
		Ship_SetTaskDefend(SECONDARY_TASK,charIdx,GetTargChrIndex(targetNum,locName));
		DeleteAttribute(chRef, "ShipCannonChargeType"); // ���� ����, ��� ������ ���������, �������� ������� ���������, �� ���� ������� ����� ��� ����� ��������
		break;
	case "BI_Attack":
		Ship_SetTaskAttack(SECONDARY_TASK,charIdx,GetTargChrIndex(targetNum,locName));
		DeleteAttribute(chRef, "ShipCannonChargeType"); // ���� ����, ��� ������ ���������, �������� ������� ���������, �� ���� ������� ����� ��� ����� ��������
	break;
	case "BI_Abordage":
		Ship_SetTaskAbordage(SECONDARY_TASK,charIdx,GetTargChrIndex(targetNum,locName));
	break;
	case "BI_Reload":
		if(bi_nReloadTarget!=-1)
		{
			LaunchTransferMain(chRef, GetCharacter(bi_nReloadTarget), "Transfer");
		}
		break;
	case "BI_SailTo":
		/*if(targetNum==-1)
		{ // �������� � ������� � ������ locName
			if( !IsEntity(&SailToFader) ) {SeaAI_SailToLocator(locName);}
		}
		else
		{ // ������� ����� � �������� targetNum
			if( !IsEntity(&SailToFader) ) {SeaAI_SailToCharacter(targetNum);}
		} */
		// boal 09.02.2004 -->
	    if (bDisableMapEnter && !bBettaTestMode && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && !CheckAttribute(pchar, "GenQuest.MapClosedNoBattle") && !CheckAttribute(pchar, "CSM.FreeSailing")) // --> CheatSurfMenu //Jason
	    {
           PlaySound("interface\knock.wav");
	       break;
	    }
	    if (!CheckEnemyCompanionDistance2GoAway(false) && !bBettaTestMode && !CheckAttribute(pchar, "CSM.FreeSailing")) // --> CheatSurfMenu // ��������� � ����
	    {
           PlaySound("interface\knock.wav");
	       break;
	    }
	    // boal 09.02.2004 <--
		if (targetNum == -1)
		{ // �������� � ������� � ������ locName
            bOk = true;

			if (MOD_SKILL_ENEMY_RATE >= 2 && !bBettaTestMode && !CheckAttribute(pchar, "CSM.FreeSailing")) // --> CheatSurfMenu
            {
                targetNum = Fort_FindCharacter(AISea.Island,"reload",locName);
                if (targetNum == -1)
                {
                    // ��� ����� �������� �� �����-���� ���� ���� �� �����
                    targetNum = Fort_FindCharacterByPort(AISea.Island, locName);
                }
            }
			if (targetNum >= 0)
			{
				if (GetRelation(sti(pchar.index), targetNum) == RELATION_ENEMY && !CheckAttribute(&Characters[targetNum], "CanBeSailTo"))
				{
                  	if (sti(Characters[targetNum].Fort.Mode) == FORT_NORMAL)
					{
						bOk = false;
					}
				}
			}
			if (bOk)
   			{
    			if( !IsEntity(&SailToFader) ) {trace("SailToLocator : " + locName); SeaAI_SailToLocator(locName); }
			}
			else
			{
                PlaySound("interface\knock.wav");
			}
		}
		else
		{ // ������� ����� � �������� targetNum
		    // boal ������ ������ � ������� ��� ���� ������ (�������� ������) -->
            if (GetRelation(sti(pchar.index), targetNum) != RELATION_ENEMY || CheckAttribute(&Characters[targetNum], "CanBeSailTo") || bBettaTestMode || CheckAttribute(pchar, "CSM.FreeSailing")) // --> CheatSurfMenu
            {
			    if( !IsEntity(&SailToFader) ) {SeaAI_SailToCharacter(targetNum); }
			}
			else
			{
                PlaySound("interface\knock.wav");
			}
			// boal ������ ������ � ������� ��� ���� ������ (�������� ������) <--
		}
		break;
	case "BI_Speed":
		switch(locName)
		{
		case "sail_none":
                PlaySound("ship\no_sail_"+rand(3)+".ogg");
			Ship_SetSailState(charIdx,0.0);
		break;
		case "sail_midi":
                PlaySound("ship\half_sail_"+rand(3)+".ogg");
			Ship_SetSailState(charIdx,0.5);
		break;
		case "sail_fast":
                PlaySound("ship\full_sail_"+rand(4)+".ogg");
			Ship_SetSailState(charIdx,1.0);
		break;
		}
		break;
	case "BI_CompanionCommand":
		BI_SetSpecCommandMode(BI_COMMODE_COMMAND_SELECT,-1,-1,targetNum,1);
		return;
		break;
	case "BI_ImmDeath":
		if(targetNum==-1)
		{ // ������ �����
			targetNum = Fort_FindCharacter(AISea.Island,"reload",locName);
			if(targetNum>=0)
			{
				Fort_SetAbordageMode(pchar, GetCharacter(targetNum));
			}
		}
		else
		{
			ShipDead(targetNum,KILL_BY_BALL,nMainCharacterIndex);
		}
		break;

	case "BI_InstantBoarding":
  		ActivateCharacterPerk(GetCharacter(charIdx),"InstantBoarding");
		CharacterPerkOff(GetCharacter(charIdx),"InstantBoarding");
		if( CheckSuccesfullBoard(GetCharacter(charIdx),GetCharacter(targetNum)) ) {
			Sea_AbordageStartNow(SHIP_ABORDAGE,targetNum,true,true);
		} else {
			Log_SetStringToLog( XI_ConvertString("failed to board") );
			Event("BI_LaunchCommand","lsls", charIdx, "BI_SailTo", targetNum, locName);
			return;
		}
		break;

	case "BI_Brander":
		//ActivateCharacterPerk(pchar,"Brander"); - ������������ ������
		Ship_SetTaskBrander(SECONDARY_TASK, charIdx, targetNum);
		break;
	case "BI_ImmediateReload":
		ActivateCharacterPerk(GetCharacter(charIdx),"ImmediateReload");
		PlaySound("interface\ImmediateReload.mp3");
		break;
	case "BI_LightRepair":
		ActivateCharacterPerk(GetCharacter(charIdx),"LightRepair");
		ActivateSpecRepair(GetCharacter(charIdx),0);
		PlaySound("interface\LightRepair.mp3");
		break;		
	case "BI_InstantRepair":
		ActivateCharacterPerk(GetCharacter(charIdx),"InstantRepair");
		ActivateSpecRepair(GetCharacter(charIdx),1);
		PlaySound("interface\InstantRepair.mp3");
		break;		
	case "BI_Turn180":
		ActivateCharacterPerk(GetCharacter(charIdx),"Turn180");
		Ship_Turn180(GetCharacter(charIdx));
		PlaySound("interface\Turn180.mp3");
		break;

	// items abilities
	case "BI_UseItemAbilitie":
		CompleteQuestName( BattleInterface.AbilityIcons.(alternativeCommand).quest, "");
	break;
	
	/*case "BI_Ability":
  		Event("evntSetUsingAbility","l", charIdx);
	break;*/
	}

	//BI_SetCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1);
	BI_SetSpecCommandMode(BI_COMMODE_MY_SHIP_SELECT,-1,-1,-1, 0);
}

void BI_SetIslandData()
{
    if( !CheckAttribute(AISea,"Island"))
	{
		trace("BI_SetIslandData - has bug");
		return; // boal 26.03.04 fix
	}
	int isln = FindIsland(AISea.Island);
	if(isln==-1) return;

	ref atmp;
	atmp = GetIslandByIndex(isln);
	SendMessage(&BattleInterface,"la",BI_MSG_SET_ISLAND,atmp);
}

void BI_UpdateShip()
{
	int charIndex = GetEventData();
	AddShipToInterface(charIndex);
}

void BI_CreateShip()
{
	int charIndex = GetEventData();
	if(charIndex>=0) ClearActiveChrPerks(GetCharacter(charIndex));
	if( IsEntity(&BattleInterface) ) {
		AddShipToInterface(charIndex);
	}
}

void AddShipToInterface(int charIndex)
{
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index for create ship");
		return;
	}
	ref chRef = GetCharacter(charIndex);
	int st = GetCharacterShipType(chRef);
	if( st==SHIP_NOTUSED )
	{
		Trace("WARNING!!! Character id = "+chRef.id+" hav`t ship.");
		return;
	}
	ref shipRef = GetRealShip(st);
	int myShip = false;
	int shipRelation = BI_RELATION_NEUTRAL;
	switch( SeaAI_GetRelation(charIndex,nMainCharacterIndex) )
	{
	case RELATION_FRIEND:
		shipRelation = BI_RELATION_FRIEND;
		break;
	case RELATION_ENEMY:
		shipRelation = BI_RELATION_ENEMY;
		break;
	}

	for(int i=0; i<COMPANION_MAX; i++)
	{
		if(GetCompanionIndex(pchar,i) == charIndex)
		{
			myShip = true;
		}
	}


	if( CharacterIsDead(chRef) )
	{
		if( !CheckAttribute(chRef,"ship.shipsink") || sti(chRef.ship.shipsink)==false )
			return;
	}

	/*if (myShip != true)
	{
		bCanSpeak = true;
	}*/
	//��������, ��������� ��������� ���������� � ����.
	//���� �� ���������� ����� ��������� �������� ������� ���������� � ���� - ��������������
	//� � ��� ��������� ����� �������, ���������� � �������, � � �������� �� ������� ��� ���������
	//� ���������, ��� ��������� ���� �������������
	//��� ������� �������� ������� ��� ��������� �������
	//bCanSpeak = false;

	SendMessage(&BattleInterface,"llaall",BI_IN_CREATE_SHIP,charIndex,chRef,shipRef,myShip,shipRelation);
}

void BI_DeleteShip()
{
	int charIndex = GetEventData();
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index");
		return;
	}
	if( IsCompanion(GetCharacter(charIndex)) )
	{
		RemoveCharacterCompanion(pchar,GetCharacter(charIndex));
	}
	DeleteAttribute(GetCharacter(charIndex),"ship.shipsink");
	RefreshBattleInterface();
}

void BI_DeadShip()
{
	int charIndex = GetEventData();
	if(charIndex==-1)
	{
		Trace("ERROR: Invalid character index");
		return;
	}
	if( IsCompanion(GetCharacter(charIndex)) )
	{
		RemoveCharacterCompanion(pchar,GetCharacter(charIndex));
	}
	Characters[charIndex].ship.shipsink = true;
	RefreshBattleInterface();
}

void BI_SetCommandMode(int commode, int texNum, int picNum, int chIdx)
{
	bi_icons_CommandMode = commode;
	SendMessage(&BattleInterface,"llllll",BI_IN_SET_COMMAND_MODE,commode,texNum,picNum,chIdx,-1);
}

void BI_SetSpecCommandMode(int commode, int texNum, int picNum, int chIdx, int comState)
{
	bi_icons_CommandMode = commode;
	SendMessage(&BattleInterface,"llllll",BI_IN_SET_COMMAND_MODE,commode,texNum,picNum,chIdx,comState);
}

void BI_SetPossibleCommands()
{
	int chIdx = GetEventData();
	int mainIdx = sti(pchar.index);

	if( chIdx<0 || CharacterIsDead(GetCharacter(chIdx)) )
	{
		aref aroot,arcur;
		makearef(aroot,BattleInterface.Commands);
		int q = GetAttributesNum(aroot);
		for(int i=0; i<q; i++)
		{
			arcur = GetAttributeN(aroot,i);
			arcur.enable = false;
		}
		//BattleInterface.Commands.Cancel.enable = true;
		return;
	}

	// ��� �������� ���������
	if(mainIdx==chIdx)
	{
		if (CheckAttribute(pchar, "CSM.KillEmAll")) // --> CheatSurfMenu
		{
			BattleInterface.Commands.ImmediateDeath.enable	= true;
			BattleInterface.Commands.InstantBoarding.enable	= true;
		}
		else
		{
			BattleInterface.Commands.ImmediateDeath.enable	= bBettaTestMode; // boal cheat
			BattleInterface.Commands.InstantBoarding.enable	= bBettaTestMode; // boal cheat
		}
		//speak interface
		//BattleInterface.Commands.Speak.enable			= bCanSpeak;
		//BattleInterface.Commands.Sneak.enable			= bCanSneak;
		
		BattleInterface.Commands.Moor.enable			= bCanEnterToLand;
		BattleInterface.Commands.Board.enable			= bAbordageShipCanBe;
		BattleInterface.Commands.SailAway.enable		= false;
		BattleInterface.Commands.HeaveToDrift.enable	= false;
		BattleInterface.Commands.Charge.enable			= false;//CheckAttribute(pchar,"Ship.Cannons.Charge.Type"); // 
		BattleInterface.Commands.LandTroops.enable		= bAbordageFortCanBe;
		BattleInterface.Commands.Attack.enable			= false;
		BattleInterface.Commands.Defend.enable			= false;
		BattleInterface.Commands.Reload.enable			= bReloadCanBe;
		BattleInterface.Commands.Abordage.enable		= false;
		BattleInterface.Commands.SailTo.enable			= !bDisableSailTo && bSailTo;
		/*if( !bEnableIslandSailTo && iArcadeSailTo != 1)
		{
			BattleInterface.Commands.SailTo.enable		= false;
		}*/
		BattleInterface.Commands.Map.enable				= bMapEnter;
		BattleInterface.Commands.Speed.enable			= false;//true;
		//BattleInterface.Commands.CCommand.enable		= GetCompanionQuantity(pchar)>1;
		//BattleInterface.Commands.Ability.enable			= true;
		//  �������� �� 7 �����
		if (sti(RealShips[sti(pchar.Ship.Type)].BaseType) > SHIP_WAR_TARTANE)
        {
            BattleInterface.Commands.Cabin.enable		= true;
        }
        BattleInterface.Commands.Boat.enable           = true;
	}
	// ��� ���������
	else
	{
		BattleInterface.Commands.Moor.enable			= false;
		BattleInterface.Commands.Board.enable			= false;
		BattleInterface.Commands.SailAway.enable		= true;
		BattleInterface.Commands.HeaveToDrift.enable	= true;
		BattleInterface.Commands.Charge.enable			= CheckAttribute(GetCharacter(chIdx), "Ship.Cannons.Charge.Type"); // 1.2.4
		BattleInterface.Commands.LandTroops.enable		= false;
		BattleInterface.Commands.Attack.enable			= bAttack;
		BattleInterface.Commands.Abordage.enable		= bAbordage;
		BattleInterface.Commands.Defend.enable			= bDefend;
		BattleInterface.Commands.Reload.enable			= false;
		BattleInterface.Commands.SailTo.enable			= false;
		BattleInterface.Commands.Map.enable				= false;
		BattleInterface.Commands.Speed.enable			= false;
		//BattleInterface.Commands.CCommand.enable		= false;
		//BattleInterface.Commands.Ability.enable			= true;
		//BattleInterface.Commands.Speak.enable			= false;
		//BattleInterface.Commands.Sneak.enable			= false;
		BattleInterface.Commands.ImmediateDeath.enable  = false; // boal
		BattleInterface.Commands.InstantBoarding.enable  = false; // boal
		BattleInterface.Commands.Cabin.enable			= false;
        BattleInterface.Commands.Boat.enable			= false; //boal
	}
    Event("evntSetUsingAbility","l", chIdx);
}

void BI_InitializeCommands()
{
	int idLngFile = LanguageOpenFile("commands_name.txt");

	DeleteAttribute(&BattleInterface,"Commands");
	DeleteAttribute(&BattleInterface,"AbilityIcons");

	BattleInterface.Commands.Cancel.enable			= false;
	BattleInterface.Commands.Cancel.picNum			= 1;
	BattleInterface.Commands.Cancel.selPicNum		= 0;
	BattleInterface.Commands.Cancel.texNum			= 2;
	BattleInterface.Commands.Cancel.event			= "Cancel";
	BattleInterface.Commands.Cancel.note			= LanguageConvertString(idLngFile, "sea_Cancel");

	BattleInterface.Commands.Moor.enable			= false;
	BattleInterface.Commands.Moor.picNum			= 29;
	BattleInterface.Commands.Moor.selPicNum			= 13;
	BattleInterface.Commands.Moor.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Moor.event				= "BI_Moor";
	BattleInterface.Commands.Moor.note				= LanguageConvertString(idLngFile, "sea_Moor");
	//
	BattleInterface.Commands.SailTo.enable			= false;
	BattleInterface.Commands.SailTo.picNum			= 16;
	BattleInterface.Commands.SailTo.selPicNum		= 0;
	BattleInterface.Commands.SailTo.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.SailTo.event			= "BI_SailTo";
	BattleInterface.Commands.SailTo.note			= LanguageConvertString(idLngFile, "sea_SailTo");
	//
	BattleInterface.Commands.Board.enable			= false;
	BattleInterface.Commands.Board.picNum			= 30;
	BattleInterface.Commands.Board.selPicNum		= 14;
	BattleInterface.Commands.Board.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Board.event			= "BI_Board";
	BattleInterface.Commands.Board.note				= LanguageConvertString(idLngFile, "sea_Board");
	//
	BattleInterface.Commands.LandTroops.enable		= false;
	BattleInterface.Commands.LandTroops.picNum		= 42;
	BattleInterface.Commands.LandTroops.selPicNum	= 45;
	BattleInterface.Commands.LandTroops.texNum		= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.LandTroops.event		= "BI_LandTroops";
	BattleInterface.Commands.LandTroops.note		= LanguageConvertString(idLngFile, "sea_LandTroops");
	//
	BattleInterface.Commands.Map.enable				= false;
	BattleInterface.Commands.Map.picNum				= 28;
	BattleInterface.Commands.Map.selPicNum			= 12;
	BattleInterface.Commands.Map.texNum				= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Map.event				= "BI_Map";
	BattleInterface.Commands.Map.note				= LanguageConvertString(idLngFile, "sea_Map");
	//
	BattleInterface.Commands.Attack.enable			= false;
	BattleInterface.Commands.Attack.picNum			= 49;
	BattleInterface.Commands.Attack.selPicNum		= 33;
	BattleInterface.Commands.Attack.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Attack.event			= "BI_Attack";
	BattleInterface.Commands.Attack.note			= LanguageConvertString(idLngFile, "sea_Attack");
	//
	BattleInterface.Commands.Abordage.enable		= false;
	BattleInterface.Commands.Abordage.picNum		= 30;
	BattleInterface.Commands.Abordage.selPicNum		= 14;
	BattleInterface.Commands.Abordage.texNum		= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Abordage.event			= "BI_Abordage";
	BattleInterface.Commands.Abordage.note			= LanguageConvertString(idLngFile, "sea_Abordage");
	//
	BattleInterface.Commands.Defend.enable			= false;
	BattleInterface.Commands.Defend.picNum			= 51;
	BattleInterface.Commands.Defend.selPicNum		= 35;
	BattleInterface.Commands.Defend.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Defend.event			= "BI_Defend";
	BattleInterface.Commands.Defend.note			= LanguageConvertString(idLngFile, "sea_Defend");
	//
	BattleInterface.Commands.SailAway.enable		= false;
	BattleInterface.Commands.SailAway.picNum		= 50;
	BattleInterface.Commands.SailAway.selPicNum		= 34;
	BattleInterface.Commands.SailAway.texNum		= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.SailAway.event			= "BI_SailAway";
	BattleInterface.Commands.SailAway.note			= LanguageConvertString(idLngFile, "sea_SailAway");
	//
	BattleInterface.Commands.HeaveToDrift.enable	= false;
	BattleInterface.Commands.HeaveToDrift.picNum	= 25;
	BattleInterface.Commands.HeaveToDrift.selPicNum	= 9;
	BattleInterface.Commands.HeaveToDrift.texNum	= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.HeaveToDrift.event		= "BI_HeaveToDrift";
	BattleInterface.Commands.HeaveToDrift.note		= LanguageConvertString(idLngFile, "sea_HeaveToDrift");
	//
	BattleInterface.Commands.Reload.enable			= false;
	BattleInterface.Commands.Reload.picNum			= 48;
	BattleInterface.Commands.Reload.selPicNum		= 32;
	BattleInterface.Commands.Reload.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Reload.event			= "BI_Reload";
	BattleInterface.Commands.Reload.note			= LanguageConvertString(idLngFile, "sea_Reload");
	//
	BattleInterface.Commands.Charge.enable			= false;
	BattleInterface.Commands.Charge.picNum			= 17;
	BattleInterface.Commands.Charge.selPicNum		= 1;
	BattleInterface.Commands.Charge.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Charge.event			= "BI_Charge";
	BattleInterface.Commands.Charge.note			= LanguageConvertString(idLngFile, "sea_Charge");
	//
	BattleInterface.Commands.Speed.enable			= false;
	BattleInterface.Commands.Speed.picNum			= 22;
	BattleInterface.Commands.Speed.selPicNum		= 6;
	BattleInterface.Commands.Speed.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Speed.event			= "BI_Speed";
	BattleInterface.Commands.Speed.note				= LanguageConvertString(idLngFile, "sea_Speed");
	//
	/*BattleInterface.Commands.CCommand.enable		= false;
	BattleInterface.Commands.CCommand.picNum		= 22;
	BattleInterface.Commands.CCommand.selPicNum		= 30;
	BattleInterface.Commands.CCommand.texNum		= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.CCommand.event			= "BI_CompanionCommand";
	BattleInterface.Commands.CCommand.note			= LanguageConvertString(idLngFile, "sea_CCommand");*/
	//
	BattleInterface.Commands.Ability.enable			= false;
	BattleInterface.Commands.Ability.picNum			= 27;
	BattleInterface.Commands.Ability.selPicNum		= 11;
	BattleInterface.Commands.Ability.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Ability.event			= "BI_Ability";
	BattleInterface.Commands.Ability.note			= LanguageConvertString(idLngFile, "sea_Ability");
	//
	
	BattleInterface.Commands.Boat.enable	= false;
	BattleInterface.Commands.Boat.picNum	= 26;
	BattleInterface.Commands.Boat.selPicNum	= 10;
	BattleInterface.Commands.Boat.texNum	= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Boat.event	= "BI_Boat";
	BattleInterface.Commands.Boat.note	= "������� ������";
	
	BattleInterface.Commands.Cabin.enable	= false;
	BattleInterface.Commands.Cabin.picNum	= 27;
	BattleInterface.Commands.Cabin.selPicNum	= 11;
	BattleInterface.Commands.Cabin.texNum	= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Cabin.event	= "BI_Cabin";
	BattleInterface.Commands.Cabin.note	    = "�����";
	
	BattleInterface.Commands.Bomb.enable	= false;
	BattleInterface.Commands.Bomb.picNum	= 67;
	BattleInterface.Commands.Bomb.selPicNum	= 66;
	BattleInterface.Commands.Bomb.texNum	= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Bomb.event	= "BI_Bomb";
	BattleInterface.Commands.Bomb.note	    = "�������� ����";
	
	BattleInterface.Commands.ImmediateDeath.enable	= false;
	BattleInterface.Commands.ImmediateDeath.picNum	= 43;    // ��� ���
	BattleInterface.Commands.ImmediateDeath.selPicNum	= 43;
	BattleInterface.Commands.ImmediateDeath.texNum	= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.ImmediateDeath.event	= "BI_ImmDeath";
	BattleInterface.Commands.ImmediateDeath.note	= LanguageConvertString(idLngFile, "sea_ImmediateDeath");

	BattleInterface.Commands.Brander.enable			= false;
	BattleInterface.Commands.Brander.picNum			= 52;
	BattleInterface.Commands.Brander.selPicNum		= 36;
	BattleInterface.Commands.Brander.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Brander.event			= "BI_Brander";
    BattleInterface.Commands.Brander.note	= GetConvertStr("Brander", "AbilityDescribe.txt");
    
	BattleInterface.Commands.ImmediateReload.enable			= false;
	BattleInterface.Commands.ImmediateReload.picNum			= 53;
	BattleInterface.Commands.ImmediateReload.selPicNum		= 37;
	BattleInterface.Commands.ImmediateReload.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.ImmediateReload.event			= "BI_ImmediateReload";
    BattleInterface.Commands.ImmediateReload.note	= GetConvertStr("ImmediateReload", "AbilityDescribe.txt");
    
	BattleInterface.Commands.InstantBoarding.enable			= false;
	BattleInterface.Commands.InstantBoarding.picNum			= 30;   // ��� ���
	BattleInterface.Commands.InstantBoarding.selPicNum		= 14;
	BattleInterface.Commands.InstantBoarding.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.InstantBoarding.event			= "BI_InstantBoarding";
    BattleInterface.Commands.InstantBoarding.note	= GetConvertStr("InstantBoarding", "AbilityDescribe.txt");
    
	BattleInterface.Commands.LightRepair.enable			= false;
	BattleInterface.Commands.LightRepair.picNum			= 54;
	BattleInterface.Commands.LightRepair.selPicNum		= 38;
	BattleInterface.Commands.LightRepair.texNum			= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.LightRepair.event			= "BI_LightRepair";
	BattleInterface.Commands.LightRepair.note	= GetConvertStr("LightRepair", "AbilityDescribe.txt");
	
	BattleInterface.Commands.InstantRepair.enable		= false;
	BattleInterface.Commands.InstantRepair.picNum		= 55;
	BattleInterface.Commands.InstantRepair.selPicNum	= 39;
	BattleInterface.Commands.InstantRepair.texNum		= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.InstantRepair.event		= "BI_InstantRepair";
	BattleInterface.Commands.InstantRepair.note	= GetConvertStr("InstantRepair", "AbilityDescribe.txt");

	BattleInterface.Commands.Turn180.enable				= false;
	BattleInterface.Commands.Turn180.picNum				= 56;
	BattleInterface.Commands.Turn180.selPicNum			= 40;
	BattleInterface.Commands.Turn180.texNum				= BI_ICONS_TEXTURE_COMMAND;
	BattleInterface.Commands.Turn180.event				= "BI_Turn180";
	BattleInterface.Commands.Turn180.note	= GetConvertStr("Turn180", "AbilityDescribe.txt");
	
	LanguageCloseFile(idLngFile);
}

ref BI_GetChargeQuantity()
{
	int chIdx = GetEventData();
	ref chr = GetCharacter(chIdx);
	BI_ChargeState[0] = 4;
	BI_ChargeState[1] = GetCargoGoods(chr,GOOD_BALLS);
	BI_ChargeState[2] = GetCargoGoods(chr,GOOD_GRAPES);
	BI_ChargeState[3] = GetCargoGoods(chr,GOOD_KNIPPELS);
	BI_ChargeState[4] = GetCargoGoods(chr,GOOD_BOMBS);

	return &BI_ChargeState;
}

ref GetCurrentCharge()
{
	BI_intNRetValue[0] = -1;

	if( CheckAttribute(pchar,"Ship.Cannons.Charge.Type") )
	{
		switch(sti(pchar.Ship.Cannons.Charge.Type))
		{
		///korsar328 1.12.2018 ������� � ������ ���� ����� ����� ��� �������� �������� ��� ��������, ����� ����� ���� ---->
		case GOOD_BALLS:
			BI_intNRetValue[0] = 32;
			BattleInterface.textinfo.Ammo.text = XI_convertString("Balls")+": "+sti(pchar.ship.cargo.goods.balls);
			BattleInterface.textinfo.Powder.text = XI_convertString("Powder")+": "+sti(pchar.ship.cargo.goods.powder);
			break;
		case GOOD_GRAPES:
			BI_intNRetValue[0] = 35;
			BattleInterface.textinfo.Ammo.text = XI_convertString("Grapes")+": "+sti(pchar.ship.cargo.goods.grapes);
			BattleInterface.textinfo.Powder.text = XI_convertString("Powder")+": "+sti(pchar.ship.cargo.goods.powder);
			break;
		case GOOD_KNIPPELS:
			BI_intNRetValue[0] = 34;
			BattleInterface.textinfo.Ammo.text = XI_convertString("Knippels")+": "+sti(pchar.ship.cargo.goods.knippels);
			BattleInterface.textinfo.Powder.text = XI_convertString("Powder")+": "+sti(pchar.ship.cargo.goods.powder);
			break;
		case GOOD_BOMBS:
			BI_intNRetValue[0] = 33;
			BattleInterface.textinfo.Ammo.text = XI_convertString("Bombs")+": "+sti(pchar.ship.cargo.goods.bombs);
			BattleInterface.textinfo.Powder.text = XI_convertString("Powder")+": "+sti(pchar.ship.cargo.goods.powder);
			break;
		/// korsar328 <----
		}
	}

	float fState = Ship_GetSailState(pchar);
	if( fState < 0.33 ) {
		BI_intNRetValue[1] = 20;
	} else {
		if( fState < 0.66 ) {
			BI_intNRetValue[1] = 19;
		} else {
			BI_intNRetValue[1] = 18;
		}
	}

	BI_intNRetValue[2] = 61;

	return &BI_intNRetValue;
}

ref biGetCharacterShipClass()
{
	int nChrIdx = GetEventData();
	BI_intRetValue = 1;
	if( nChrIdx>=0 && nChrIdx<TOTAL_CHARACTERS ) {
		BI_intRetValue = GetCharacterShipClass( &Characters[nChrIdx] );
	}
	return &BI_intRetValue;
}

void BI_SetSeaState()
{
	bool bTmp;
	bSailTo = GetEventData();
	bTmp = GetEventData();
	bMapEnter = GetEventData();
	bAttack = GetEventData();
	bAbordage = bAttack;

	bDefend = GetEventData();
	bReloadCanBe = GetEventData();
	bi_nReloadTarget = GetEventData();
	bEnableIslandSailTo = bMapEnter;
	if(bDisableMapEnter)	bMapEnter = false;

	// boal ���� ��� ������� - ������ ��� ����� � ���� bReloadCanBe = 0;//������� �������� ������ ����� ��� ����� ����.
}

void SetShipPictureDataByShipTypeName(string sType)
{
	switch(sType)
	{
		case "tartane": 		// ������
			BI_intNRetValue[0] = 0+0*16;
			BI_intNRetValue[1] = 0+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Plot": 		// ����
			BI_intNRetValue[0] = 0+0*16;
			BI_intNRetValue[1] = 0+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Gunboat": 		// ����������� �����
			BI_intNRetValue[0] = 0+0*16;
			BI_intNRetValue[1] = 0+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Dogger": 		// ������
			BI_intNRetValue[0] = 10+2*16;
			BI_intNRetValue[1] = 10+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Botik": 		// �����
			BI_intNRetValue[0] = 0+0*16;
			BI_intNRetValue[1] = 0+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarTartane":  	// �������
			BI_intNRetValue[0] = 2+0*16;
			BI_intNRetValue[1] = 2+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Barque":			// ����
			BI_intNRetValue[0] = 4+0*16;
			BI_intNRetValue[1] = 4+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "GafelSloop": 		// ��������� ����
			BI_intNRetValue[0] = 0+0*16;
			BI_intNRetValue[1] = 0+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Galiot":			// ������
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Ketch":			// ���
			BI_intNRetValue[0] = 14+3*16;
			BI_intNRetValue[1] = 14+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Yacht":			// ����
			BI_intNRetValue[0] = 10+0*16;
			BI_intNRetValue[1] = 10+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Snauw":			// ����
			BI_intNRetValue[0] = 0+1*16;
			BI_intNRetValue[1] = 0+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Cutter":			// ������
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Contraband":	// ���������������� �������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Chaloupe": 		// �����
			BI_intNRetValue[0] = 6+1*16;
			BI_intNRetValue[1] = 6+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Warsloop":			// ������ ����
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Tradesloop":			// �������� ����
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Lightsloop":			// ˸���� ����
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Latina":		// ���������-������
			BI_intNRetValue[0] = 8+2*16;
			BI_intNRetValue[1] = 8+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Redonda":			// ���������-�������
			BI_intNRetValue[0] = 14+0*16;
			BI_intNRetValue[1] = 14+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Schooner":		// �������� �����
			BI_intNRetValue[0] = 6+0*16;
			BI_intNRetValue[1] = 6+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Lightschooner":		// ˸���� �����
			BI_intNRetValue[0] = 2+2*16;
			BI_intNRetValue[1] = 2+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "GafelSchooner": // ��������� �����
			BI_intNRetValue[0] = 6+0*16;
			BI_intNRetValue[1] = 6+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "PatrolSchooner": // ���������� �����
			BI_intNRetValue[0] = 6+0*16;
			BI_intNRetValue[1] = 6+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "barkentine":		// ����������
			BI_intNRetValue[0] = 8+0*16;
			BI_intNRetValue[1] = 8+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "shnyava":			// �����
			BI_intNRetValue[0] = 10+0*16;
			BI_intNRetValue[1] = 10+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Fleut":			// �����
			BI_intNRetValue[0] = 12+0*16;
			BI_intNRetValue[1] = 12+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "TradeFleut":	// �������� �����
			BI_intNRetValue[0] = 12+0*16;
			BI_intNRetValue[1] = 12+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Caravel":			// ���������
			BI_intNRetValue[0] = 14+0*16;
			BI_intNRetValue[1] = 14+0*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Pinnace":			// �����
			BI_intNRetValue[0] = 0+1*16;
			BI_intNRetValue[1] = 0+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		
		case "Caracca":			// �������
			BI_intNRetValue[0] = 2+1*16;
			BI_intNRetValue[1] = 2+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Navio":			// �����
			BI_intNRetValue[0] = 4+1*16;
			BI_intNRetValue[1] = 4+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "EastIndiaMan":	// ���-�����
			BI_intNRetValue[0] = 6+1*16;
			BI_intNRetValue[1] = 6+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
             
		case "LuggerQuest":	// ���������� ������
			BI_intNRetValue[0] = 8+1*16;
			BI_intNRetValue[1] = 8+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Lugger":			// ������
			BI_intNRetValue[0] = 10+1*16;
			BI_intNRetValue[1] = 10+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "luggerr":			// ������
			BI_intNRetValue[0] = 10+1*16;
			BI_intNRetValue[1] = 10+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Sloop":			// ����
			BI_intNRetValue[0] = 12+1*16;
			BI_intNRetValue[1] = 12+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Brigantine":		// ����������
			BI_intNRetValue[0] = 14+1*16;
			BI_intNRetValue[1] = 14+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "ArmedBrigantine":	// ������� ����������
			BI_intNRetValue[0] = 14+1*16;
			BI_intNRetValue[1] = 14+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;


		case "BattleBrigantine":	// ������ ����������
			BI_intNRetValue[0] = 14+1*16;
			BI_intNRetValue[1] = 14+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Brig":			// ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Warbrig": // ��������� ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Fastbrig": // ˸���� ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Tradebrig": // �������� ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Armedbrig": // ������� ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Battlebrig": // ������ ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "TradeShip": // �������� �������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
                         
		case "Schooner_w":		// ������� �����
			BI_intNRetValue[0] = 2+2*16;
			BI_intNRetValue[1] = 2+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarSchooner":		// ������ �����
			BI_intNRetValue[0] = 2+2*16;
			BI_intNRetValue[1] = 2+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "FastSchooner":		// ������� �����
			BI_intNRetValue[0] = 2+2*16;
			BI_intNRetValue[1] = 2+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LightCorvette":		// ˸���� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LightPinnace":		// ˸���� �����
			BI_intNRetValue[0] = 0+1*16;
			BI_intNRetValue[1] = 0+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;


		case "SmallGaleon":		// ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

         case "Polacca":                // �������
			BI_intNRetValue[0] = 10+2*16;
			BI_intNRetValue[1] = 10+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Galeon_l":		// ˸���� ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "SpaGaleon":		// ��������� ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "EngGaleon":		// ���������� ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Corvette":		// ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleCorvette":		// ������ ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;


		case "WarCorvette":		// ������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;


		case "FastCorvette":		// ������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "FrenchCorvette":	// ����������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "HeavyCorvette":		// ������ ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "CorsairCorvette":	// ���������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LightFrigate":	// ˸���� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "EngFrigate":	// ���������� ������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "SpaFrigate":	// ��������� ������
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "SmallEastIndiaMan":	// ����� ���-�����
			BI_intNRetValue[0] = 0+1*16;
			BI_intNRetValue[1] = 0+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "MerchantShip":	// ���������� �������
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "HeavyPinnace":		// ������ �����
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "TradePinnace":		// �������� �����
			BI_intNRetValue[0] = 0+1*16;
			BI_intNRetValue[1] = 0+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "HeavyGaleon":		// ������ ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "ArmedCorvette":	 // ��������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Raider":			// ������
			BI_intNRetValue[0] = 14+2*16;
			BI_intNRetValue[1] = 14+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "XebekVML":		// ������
			BI_intNRetValue[0] = 8+2*16;
			BI_intNRetValue[1] = 8+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarXebec":		// ������� ������
			BI_intNRetValue[0] = 8+2*16;
			BI_intNRetValue[1] = 8+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleXebec":		// ������ ������
			BI_intNRetValue[0] = 8+2*16;
			BI_intNRetValue[1] = 8+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "ArmedXebec":			// ��������� ������
			BI_intNRetValue[0] = 12+3*16;
			BI_intNRetValue[1] = 12+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Polacre":			// ������
			BI_intNRetValue[0] = 10+2*16;
			BI_intNRetValue[1] = 10+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
				
		case "HeavyGaleon":		// ������� ������
			BI_intNRetValue[0] = 12+2*16;
			BI_intNRetValue[1] = 12+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;              
                                   case "La_Marianna":		// ������ ����� �����
			BI_intNRetValue[0] = 12+2*16;
			BI_intNRetValue[1] = 12+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
                           
		case "Frigate":			// ������
			BI_intNRetValue[0] = 14+2*16;
			BI_intNRetValue[1] = 14+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarFrigate":	// ������� ������
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
                                  
		case "Frigate_H":		// ������ ������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LineFrigate":		// �������� ������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "ArmedFrigate":		// ��������� ������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleFrigate":		// ������ ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Privateer":		// ��������
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "PatrolFrigate":		// ���������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "CorsairFrigate":		// ���������� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarGaleon":		// ������� ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleGaleon":		// ������ ������
			BI_intNRetValue[0] = 4+2*16;
			BI_intNRetValue[1] = 4+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleShip":		// ������ �������
		     	BI_intNRetValue[0] = 0+3*16;
		     	BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarShip":		// ������� �������
			BI_intNRetValue[0] = 2+3*16;
			BI_intNRetValue[1] = 2+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LightLineship":		// ˸���� ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Lineship":		// �������� �������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "HeavyLineship":		// ������ ������
			BI_intNRetValue[0] = 6+2*16;
			BI_intNRetValue[1] = 6+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WarLineship":	// ������� ������
			BI_intNRetValue[0] = 6+3*16;
			BI_intNRetValue[1] = 6+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BattleLineship":  // ������ ������
			BI_intNRetValue[0] = 10+3*16;
			BI_intNRetValue[1] = 10+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LSHIP_FRA":	// ����������� ������
			BI_intNRetValue[0] = 4+3*16;
			BI_intNRetValue[1] = 4+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "LSHIP_HOL":	// ����������� ������
			BI_intNRetValue[0] = 0+3*16;
			BI_intNRetValue[1] = 0+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LSHIP_SPA":	// ��������� ������
			BI_intNRetValue[0] = 8+3*16;
			BI_intNRetValue[1] = 8+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "LSHIP_ENG":	// ���������� ������
			BI_intNRetValue[0] = 10+3*16;
			BI_intNRetValue[1] = 10+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
                                     case "LineShipHeavy":          // ������ �������� �������
		        BI_intNRetValue[0] = 4+3*8;
		        BI_intNRetValue[1] = 4+3*8 + 1;
		        BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;	

                                    case "Shark":
		        BI_intNRetValue[0] = 2+3*16;
		        BI_intNRetValue[1] = 2+3*16 + 1;
		        BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Mayfang":			// ������ ������ "�������"
			BI_intNRetValue[0] = 12+3*16;
			BI_intNRetValue[1] = 12+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Mirage":			// ������������ ��� "�����"
			BI_intNRetValue[0] = 14+3*16;
			BI_intNRetValue[1] = 14+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Valciria":		// ���������� ���� "���������"
			BI_intNRetValue[0] = 0+4*16;
			BI_intNRetValue[1] = 0+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Valciria_quest":		// ���������� ���� "������ ��������"
			BI_intNRetValue[0] = 0+4*16;
			BI_intNRetValue[1] = 0+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Corvette_quest":	// ����� ������ "����������"
			BI_intNRetValue[0] = 2+4*16;
			BI_intNRetValue[1] = 2+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "ArabellaShip":	// ������� ������ "�������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

                                      case "ArabellaShipG":  // ������ ��������
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Flyingdutchman":	// ��������� "�������"
			BI_intNRetValue[0] = 6+4*16;
			BI_intNRetValue[1] = 6+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Flyingdutchman_l":// ����� "�������"
			BI_intNRetValue[0] = 8+4*16;
			BI_intNRetValue[1] = 8+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Flyingdutchman_h"://  "������� ���������"
			BI_intNRetValue[0] = 8+4*16;
			BI_intNRetValue[1] = 8+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Santisima":		// �������� ������� "���� �� ���-�����"
			BI_intNRetValue[0] = 10+4*16;
			BI_intNRetValue[1] = 10+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Polacre_q":			// ������ "������" // Addon 2016-1 Jason ��������� �������
			BI_intNRetValue[0] = 12+4*16;
			BI_intNRetValue[1] = 12+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "FRIGATEQVEENT":	// ������ "����� �������� ����"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "CORVETTE_QUESTT":	// ������� ������ "�����"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "FRIGATE_QUEST":	// ������ "������ ���������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "SOLEYRU":		// �������� ������� "����� ������"
			BI_intNRetValue[0] = 10+4*16;
			BI_intNRetValue[1] = 10+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

	case "SOLEYPIR":		//��������� �������� ������� "����� ������"
			BI_intNRetValue[0] = 6+4*16;
			BI_intNRetValue[1] = 6+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BrigMirageSW":			// ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "BrigArrow":			// ����
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Surprise":	// ������� ������ "�������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "WaterFort":	// �������� �������� "�������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Rossiya":	// ������ "������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Balloon":			// ��������� ���
			BI_intNRetValue[0] = 10+1*16;
			BI_intNRetValue[1] = 10+1*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

// CheatSurfMenu by Cheatsurfer -->
		// ���� ������ ��� ����� �������� ���������� ������, ����� ������� �� �������
		case "BlackPearl":      // ��
			BI_intNRetValue[0] = 8+4*16;
			BI_intNRetValue[1] = 8+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "ManowarV":  		// �������
			BI_intNRetValue[0] = 2+3*16;
			BI_intNRetValue[1] = 2+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "QAR": // "����� �������� ����"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
				
		case "Constitution":	// ������ "�����������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Speedy":			// ���� "�����"
			BI_intNRetValue[0] = 0+2*16;
			BI_intNRetValue[1] = 0+2*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "Corvette_questCoAS":	// ������ "ϸ� �����"
			BI_intNRetValue[0] = 2+4*16;
			BI_intNRetValue[1] = 2+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "ArabellaShipCoAS":	// ������ "��������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "FrigateQueen":	// ������ "��������"
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "BrigSW":			// ���� "������� ����"
			BI_intNRetValue[0] = 0+4*16;
			BI_intNRetValue[1] = 0+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "BrigQueen":		// ���� "��������"
			BI_intNRetValue[0] = 0+4*16;
			BI_intNRetValue[1] = 0+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		
		case "LuggerQuestCoAS":	// ������ "�����������"
			BI_intNRetValue[0] = 12+3*16;
			BI_intNRetValue[1] = 12+3*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "Essex":
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;

		case "LeSuperbe":
			BI_intNRetValue[0] = 4+4*16;
			BI_intNRetValue[1] = 4+4*16 + 1;
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_SHIP1;
		break;
		// CheatSurfMenu by Cheatsurfer <--

	}
	BI_intNRetValue[3] = false;
}

void SetShipPictureDataByShipType(int st)
{
	if(st>=0 && st<SHIP_TYPES_QUANTITY)
	{
		SetShipPictureDataByShipTypeName( ShipsTypes[st].name );
	}
}

ref BI_GetData()
{
	int dataType = GetEventData();
	int chrIdx;
	ref chRef;

	switch(dataType)
	{
	// �������� ����� �������� �������
	case BIDT_SHIPPICTURE:
		chRef = GetCharacter(GetEventData());
		if( CharacterIsDead(chRef) )
		{
			BI_intNRetValue[0] = 65;
			BI_intNRetValue[1] = 64; // ��������� ���������
			BI_intNRetValue[2] = BI_ICONS_TEXTURE_COMMAND;
			BI_intNRetValue[3] = true;
			break;
		}
		int st = sti(chRef.Ship.Type);
		if (!CheckAttribute(&RealShips[st], "basetype")) Log_TestInfo("BIDT_SHIPPICTURE ��� basetype � ������� ��� ID=" + chRef.id);
		st = sti(RealShips[st].basetype);
		SetShipPictureDataByShipType( st );
		break;

	case BIDT_GERALD_DATA:
		{
			chrIdx = GetEventData();
			if(chrIdx<0) break;
			chRef = GetCharacter(chrIdx);
			BI_intNRetValue[0] = 8;
			switch( SeaAI_GetRelation(chrIdx,nMainCharacterIndex) )
			{
				case RELATION_FRIEND:	
					BI_intNRetValue[1] = 7; 
				break;
				case RELATION_NEUTRAL:	
					BI_intNRetValue[1] = -1; 
				break;
				case RELATION_ENEMY:	
					BI_intNRetValue[1] = 6; 
				break;
			}
			BI_intNRetValue[2] = 8;
			switch( sti(chRef.nation) )
			{
				//case SMUGGLER:
				//	BI_intNRetValue[3] = 1;
				//break;
				case ENGLAND:		
					BI_intNRetValue[3] = 3; 
				break;
				case FRANCE:		
					BI_intNRetValue[3] = 2; 
				break;
				case SPAIN:			
					BI_intNRetValue[3] = 0; 
				break;
				case HOLLAND:		
					BI_intNRetValue[3] = 4; 
				break;
				case PIRATE:		
					BI_intNRetValue[3] = 5; 
				break;
			}

		}
		break;
	}
	return &BI_intNRetValue;
}

void SetParameterData()
{
	BattleInterface.CommandTextures.list.t0.name = "battle_interface\list_icons.tga";
	BattleInterface.CommandTextures.list.t0.xsize = 16;
	BattleInterface.CommandTextures.list.t0.ysize = 8;

	BattleInterface.CommandTextures.list.t1.name = "battle_interface\ship_icons1.tga";
	BattleInterface.CommandTextures.list.t1.xsize = 16;
	BattleInterface.CommandTextures.list.t1.ysize = 16;

	BattleInterface.CommandTextures.list.t2.name = "battle_interface\cancel.tga";
	BattleInterface.CommandTextures.list.t2.xsize = 2;
	BattleInterface.CommandTextures.list.t2.ysize = 1;

	BattleInterface.CommandTextures.list.t3.name = "battle_interface\small_nations.tga";
	BattleInterface.CommandTextures.list.t3.xsize = 8;
	BattleInterface.CommandTextures.list.t3.ysize = 1;

	BattleInterface.charge.charge1.picNum = 19; // balls
	BattleInterface.charge.charge1.selPicNum = 3;
	BattleInterface.charge.charge2.picNum = 18; // grapes
	BattleInterface.charge.charge2.selPicNum = 2;
	BattleInterface.charge.charge3.picNum = 21; // "Knippels"
	BattleInterface.charge.charge3.selPicNum = 5;
	BattleInterface.charge.charge4.picNum = 20; // bombs
	BattleInterface.charge.charge4.selPicNum = 4;

	BattleInterface.CommandTextures.ChargeTexNum = 0;
	BattleInterface.CommandTextures.CommandTexNum = 0;

	BattleInterface.CommandShowParam.maxShowQuantity = 10;
	BattleInterface.CommandShowParam.iconDistance = 4;
	BattleInterface.CommandShowParam.iconWidth = RecalculateHIcon(64);
	BattleInterface.CommandShowParam.iconHeight = RecalculateVIcon(64);
	BattleInterface.CommandShowParam.leftIconsOffset = sti(showWindow.left)+RecalculateHIcon(16);
	BattleInterface.CommandShowParam.downIconsOffset = sti(showWindow.bottom)-RecalculateVIcon(80);
	BattleInterface.CommandShowParam.buttonWidth = RecalculateHIcon(8);
	BattleInterface.CommandShowParam.buttonHeight = RecalculateVIcon(64);
	BattleInterface.CommandShowParam.buttonOffset = RecalculateHIcon(4);
	BattleInterface.CommandShowParam.buttonTexture = "battle_interface\lr_buttons.tga";
	BattleInterface.CommandShowParam.shipStateWidth = RecalculateHIcon(64);
	BattleInterface.CommandShowParam.shipStateHeight = RecalculateVIcon(16);
	BattleInterface.CommandShowParam.shipStateTexture = "battle_interface\indicators.tga";
	BattleInterface.CommandShowParam.shipStateOffset = RecalculateVIcon(0);
	BattleInterface.CommandShowParam.GeraldWidth = RecalculateHIcon(32);
	BattleInterface.CommandShowParam.GeraldHeight = RecalculateVIcon(32);
	BattleInterface.CommandShowParam.commandFont = "bold_numbers";
	BattleInterface.CommandShowParam.printXOffset = RecalculateHIcon(32);
	BattleInterface.CommandShowParam.printYOffset = RecalculateVIcon(-26);
	BattleInterface.CommandShowParam.commandNoteFont = "interface_normal";
	BattleInterface.CommandShowParam.noteXOffset = RecalculateHIcon(0);
	BattleInterface.CommandShowParam.noteYOffset = RecalculateVIcon(-30);
	BattleInterface.CommandShowParam.argbTFactorColor = argb(256,64,64,64);

	BattleInterface.UserIcons.ui1.enable = true;
	BattleInterface.UserIcons.ui1.pic = 25;
	BattleInterface.UserIcons.ui1.selpic = 9;
	BattleInterface.UserIcons.ui1.tex = 0;
	BattleInterface.UserIcons.ui1.name = "sail_none";
	//----------------------------------------------
	BattleInterface.UserIcons.ui2.enable = true;
	BattleInterface.UserIcons.ui2.pic = 24;
	BattleInterface.UserIcons.ui2.selpic = 8;
	BattleInterface.UserIcons.ui2.tex = 0;
	BattleInterface.UserIcons.ui2.name = "sail_midi";
	//----------------------------------------------
	BattleInterface.UserIcons.ui3.enable = true;
	BattleInterface.UserIcons.ui3.pic = 23;
	BattleInterface.UserIcons.ui3.selpic = 7;
	BattleInterface.UserIcons.ui3.tex = 0;
	BattleInterface.UserIcons.ui3.name = "sail_fast";

	//===============================================
	BattleInterface.MessageIcons.IconWidth = RecalculateHIcon(64);
	BattleInterface.MessageIcons.IconHeight = RecalculateVIcon(24);
	BattleInterface.MessageIcons.IconDist = RecalculateVIcon(2);
	BattleInterface.MessageIcons.IconBottom = sti(showWindow.bottom)-RecalculateVIcon(80+20);
	BattleInterface.MessageIcons.IconMaxQuantity = 4;
	BattleInterface.MessageIcons.BlendTime = 3.0;
	BattleInterface.MessageIcons.FallSpeed = 22.0;
	BattleInterface.MessageIcons.argbHighBlind = argb(255,128,128,128);
	BattleInterface.MessageIcons.argbLowBlind = argb(255,68,68,68);
	BattleInterface.MessageIcons.BlindUpTime = 0.5;
	BattleInterface.MessageIcons.BlindDownTime = 1.0;
	BattleInterface.MessageIcons.texture = "battle_interface\MessageIcons.tga";
	BattleInterface.MessageIcons.TexHSize = 2;
	BattleInterface.MessageIcons.TexVSize = 2;

	BattleInterface.navigation.aspectRatio				= showWindow.aspectRatio;
	BattleInterface.navigation.navigatorWidth			= RecalculateHIcon(256);
	BattleInterface.navigation.navigatorHeight			= RecalculateVIcon(256);
	BattleInterface.navigation.rightPos					= sti(showWindow.right) + RecalculateHIcon(24);
	BattleInterface.navigation.topPos					= sti(showWindow.top) - RecalculateVIcon(24);
	//BattleInterface.navigation.speedShowFont			= "bold_numbers";
	BattleInterface.navigation.speedShowFont			= "interface_normal";
	BattleInterface.navigation.speedOutYOffset			= RecalculateVIcon(196);
	BattleInterface.navigation.shipSpeedXOffset			= RecalculateHIcon(30);
	BattleInterface.navigation.windSpeedXOffset			= RecalculateHIcon(-30);
	//BattleInterface.navigation.fontScale				= 1.2;
	BattleInterface.navigation.fontScale				= 1.2;
	BattleInterface.navigation.windWidth				= 32;
	BattleInterface.navigation.windHeight				= 128;
	BattleInterface.navigation.compasTexture			= "battle_interface\compass.tga";
	BattleInterface.navigation.cannonsTexture			= "battle_interface\indicators_cannons_reload.tga";
	BattleInterface.navigation.emptyTexture				= "battle_interface\indicators_dark_and_center_ship.tga";
	BattleInterface.navigation.windTexture				= "battle_interface\wind_pointer.tga";
	BattleInterface.navigation.bestCourseTexture		= "battle_interface\best_courseS.tga";
	BattleInterface.navigation.leftChargeBegAngle		= 214;
	BattleInterface.navigation.leftChargeEndAngle		= 326;
	BattleInterface.navigation.rightChargeBegAngle		= 146;
	BattleInterface.navigation.rightChargeEndAngle		= 34;
	BattleInterface.navigation.forwardChargeBegAngle	= 343;
	BattleInterface.navigation.forwardChargeEndAngle	= 378;
	BattleInterface.navigation.backwardChargeBegAngle	= 198;
	BattleInterface.navigation.backwardChargeEndAngle	= 162;
	BattleInterface.navigation.mapRadius				= 55;
	BattleInterface.navigation.horizontRadius			= 400;
	BattleInterface.navigation.minScale					= 0.5;
	BattleInterface.navigation.maxScale					= 4;
	BattleInterface.navigation.curScale					= 2;
	BattleInterface.navigation.scaleStep				= 0.1;
	BattleInterface.navigation.argbReadyCannonColor		= argb(255,220,190,60);
	BattleInterface.navigation.argbChargeCannonColor	= argb(255,255,240,100);
	BattleInterface.navigation.argbDamageCannonColor	= argb(255,130,130,130);
	BattleInterface.navigation.argbSeaColor				= argb(255,10,30,80);
	BattleInterface.navigation.argbFireZoneColor		= argb(60,250,250,250);
	BattleInterface.navigation.argbEnemyShipColor		= argb(255,255,0,0);
	BattleInterface.navigation.argbFrendShipColor		= argb(255,0,255,0);
	BattleInterface.navigation.argbNeutralShipColor		= argb(255,128,128,128);
	BattleInterface.navigation.argbDeadShipColor		= argb(255,0,0,255);
	BattleInterface.navigation.argbBackMaxColor			= argb(255,0,0,128);
	BattleInterface.navigation.argbBackMinColor			= argb(0,0,0,128);
	BattleInterface.navigation.shipShowRadius			= 8.0;
	//
	BattleInterface.navigation.chargeTexture			= "battle_interface\list_icon2.tga";
	BattleInterface.navigation.chargeTextureGreed		= "8,8";
	BattleInterface.navigation.chargePos				= RecalculateHIcon(-30)+","+RecalculateVIcon(270);
	BattleInterface.navigation.chargePictureSize		= RecalculateHIcon(48)+","+RecalculateVIcon(48);
	//
	BattleInterface.navigation.sailstateTexture			= "battle_interface\list_icon2.tga";
	BattleInterface.navigation.sailstateTextureGreed	= "8,8";
	BattleInterface.navigation.sailstatePos				= RecalculateHIcon(30)+","+RecalculateVIcon(170);
	BattleInterface.navigation.sailstatePictureSize		= RecalculateHIcon(48)+","+RecalculateVIcon(48);
	//
	BattleInterface.navigation.windStateTexture			= "battle_interface\list_icon2.tga";
	BattleInterface.navigation.windTextureGreed			= "8,8";
	BattleInterface.navigation.windPos					= RecalculateHIcon(-30)+","+RecalculateVIcon(170);
	BattleInterface.navigation.windPictureSize			= RecalculateHIcon(48)+","+RecalculateVIcon(48);

	/*BattleInterface.imageslist.textinfoback1.texture = "battle_interface\textinfo_back.tga";
	BattleInterface.imageslist.textinfoback1.color = argb(96,64,64,64);
	BattleInterface.imageslist.textinfoback1.uv = "0.0,0.0,1.0,0.125";
	BattleInterface.imageslist.textinfoback1.pos = (sti(showWindow.right) - RecalculateHIcon(198)) + "," +
		RecalculateVIcon(192) + "," +
		(sti(showWindow.right) - RecalculateHIcon(10)) + "," +
		RecalculateVIcon(200);
	//
	BattleInterface.imageslist.textinfoback2.texture = "battle_interface\textinfo_back.tga";
	BattleInterface.imageslist.textinfoback2.color = argb(96,64,64,64);
	BattleInterface.imageslist.textinfoback2.uv = "0.0,0.125,1.0,0.875";
	BattleInterface.imageslist.textinfoback2.pos = (sti(showWindow.right) - RecalculateHIcon(198)) + "," +
		RecalculateVIcon(200) + "," +
		(sti(showWindow.right) - RecalculateHIcon(10)) + "," +
		RecalculateVIcon(420);
	//
	BattleInterface.imageslist.textinfoback3.texture = "battle_interface\textinfo_back.tga";
	BattleInterface.imageslist.textinfoback3.color = argb(96,64,64,64);
	BattleInterface.imageslist.textinfoback3.uv = "0.0,0.875,1.0,1.0";
	BattleInterface.imageslist.textinfoback3.pos = (sti(showWindow.right) - RecalculateHIcon(198)) + "," +
		RecalculateVIcon(420) + "," +
		(sti(showWindow.right) - RecalculateHIcon(10)) + "," +
		RecalculateVIcon(428);
	*/

	BattleInterface.imageslist.textinfoback4.texture = "battle_interface\CSM\csm_ship_powder_icon.tga";
	BattleInterface.imageslist.textinfoback4.color = argb(255,128,128,128);
	BattleInterface.imageslist.textinfoback4.uv = "0.0,0.0,1.0,1.0";
	BattleInterface.imageslist.textinfoback4.pos = (sti(showWindow.right) - RecalculateHIcon(98)) + "," + (sti(showWindow.top) + RecalculateVIcon(350)) + "," + (sti(showWindow.right) - RecalculateHIcon(50)) + "," + (sti(showWindow.top) + RecalculateVIcon(398));

	BattleInterface.textinfo.Date.font = "NAGIBATOR_228";
	BattleInterface.textinfo.Date.scale = 1.16;
	BattleInterface.textinfo.Date.pos.x = sti(showWindow.right) - RecalculateHIcon(129);
	BattleInterface.textinfo.Date.pos.y = RecalculateVIcon(197);
	BattleInterface.textinfo.Date.text = XI_convertString("Date:")+GetQuestBookData();//GetDataDay()+" "+XI_ConvertString("target_month_" + GetDataMonth())+" "+GetDataYear();
	BattleInterface.textinfo.Date.refreshable = true;
	//
	BattleInterface.textinfo.Location.font = "NAGIBATOR_228";
	BattleInterface.textinfo.Location.scale = 1.16;
	BattleInterface.textinfo.Location.pos.x = sti(showWindow.right) - RecalculateHIcon(112);
	BattleInterface.textinfo.Location.pos.y = RecalculateVIcon(223);
	BattleInterface.textinfo.Location.text = GetCurAkvatoriaName(false);
	//
	BattleInterface.textinfo.Speed.font = "interface_normal";
	BattleInterface.textinfo.Speed.scale = 1.3;
	BattleInterface.textinfo.Speed.color = argb(255,255,255,255);
	//BattleInterface.textinfo.Speed.shadow = false;
	BattleInterface.textinfo.Speed.pos.x = sti(showWindow.right) - RecalculateHIcon(104);
	BattleInterface.textinfo.Speed.pos.y = RecalculateVIcon(320);
	BattleInterface.textinfo.Speed.text = XI_convertString("Speed");
	//
	BattleInterface.textinfo.Ammo.font = "interface_normal";
	BattleInterface.textinfo.Ammo.scale = 1.2;
	BattleInterface.textinfo.Ammo.color = argb(255,255,255,255);
	//BattleInterface.textinfo.Ammo.shadow = false;
	BattleInterface.textinfo.Ammo.pos.x = sti(showWindow.right) - RecalculateHIcon(104);
	BattleInterface.textinfo.Ammo.pos.y = RecalculateVIcon(399);
	BattleInterface.textinfo.Ammo.text = XI_convertString("Ammunition");
	BattleInterface.textinfo.Ammo.refreshable = true;

	BattleInterface.textinfo.Ammo2.font = "interface_normal";
	BattleInterface.textinfo.Ammo2.scale = 1.2;
	BattleInterface.textinfo.Ammo2.color = argb(255,255,255,255);
	//BattleInterface.textinfo.Ammo2.shadow = false;
	BattleInterface.textinfo.Ammo2.pos.x = sti(showWindow.right) - RecalculateHIcon(75);
	BattleInterface.textinfo.Ammo2.pos.y = RecalculateVIcon(405);
	BattleInterface.textinfo.Ammo2.text = "";
	BattleInterface.textinfo.Ammo2.refreshable = true;

	///korsar328 ���������� ��������� ���� ������, �� ��� ���� ���� � �� ��������� � ������� ��������� ������� �� �������� ����� ������� ��� Ammunition ---->
    BattleInterface.textinfo.Powder.font = "interface_normal";
	BattleInterface.textinfo.Powder.scale = 1.2;
	BattleInterface.textinfo.Powder.color = argb(255,255,255,255);
	BattleInterface.textinfo.Powder.pos.x = sti(showWindow.right) - RecalculateHIcon(104);
	BattleInterface.textinfo.Powder.pos.y = RecalculateVIcon(422);
	BattleInterface.textinfo.Powder.text = XI_convertString("Ammunition");
	BattleInterface.textinfo.Powder.refreshable = true;
	//
	/* BattleInterface.LineInfo.speed.color = argb(255,0,0,0);
	BattleInterface.LineInfo.speed.begin.x = sti(showWindow.right) - RecalculateHIcon(168);
	BattleInterface.LineInfo.speed.begin.y = RecalculateVIcon(346);
	BattleInterface.LineInfo.speed.end.x = RecalculateHIcon(128);
	BattleInterface.LineInfo.speed.end.y = 0; */
	//
	/* BattleInterface.LineInfo.Ammo.color = argb(255,0,0,0);
	BattleInterface.LineInfo.Ammo.begin.x = sti(showWindow.right) - RecalculateHIcon(168);
	BattleInterface.LineInfo.Ammo.begin.y = RecalculateVIcon(423);
	BattleInterface.LineInfo.Ammo.end.x = RecalculateHIcon(128);
	BattleInterface.LineInfo.Ammo.end.y = 0; */
/// korsar328 <----

	if( CheckAttribute(&InterfaceStates,"ShowBattleMode") ) {
		BattleInterface.battleborder.used = InterfaceStates.ShowBattleMode;
	} else {
		BattleInterface.battleborder.used = false;
	}
	BattleInterface.battleborder.color1 = argb(255,255,255,255);
	BattleInterface.battleborder.color2 = argb(155,255,255,255);
	BattleInterface.battleborder.extpos = "0,0," + ShowWindow.right + "," + ShowWindow.bottom;
	BattleInterface.battleborder.intpos1 =
		RecalculateHIcon(20) + "," +
		RecalculateVIcon(20) + "," +
		(sti(ShowWindow.right)-RecalculateHIcon(20)) + "," +
		(sti(ShowWindow.bottom)-RecalculateVIcon(20));
	BattleInterface.battleborder.intpos2 =
		RecalculateHIcon(10) + "," +
		RecalculateVIcon(10) + "," +
		(sti(ShowWindow.right)-RecalculateHIcon(10)) + "," +
		(sti(ShowWindow.bottom)-RecalculateVIcon(10));
	BattleInterface.battleborder.speed = 1.5;
	BattleInterface.battleborder.texture = "battle_interface\battleborder.tga";

	BattleInterface.ShipIcon.sailorfontid			= "interface_normal";
	BattleInterface.ShipIcon.sailorfontcolor		= argb(255,255,255,168); //argb(255,255,255,255);
	BattleInterface.ShipIcon.sailorfontscale		= 1.1;

	BattleInterface.ShipIcon.shipnamefontid			= "NAGIBATOR_1488";
	BattleInterface.ShipIcon.shipnamefontcolor		= argb(255,255,255,255);
	BattleInterface.ShipIcon.shipnamefontscale		= 0.83;

	BattleInterface.ShipIcon.backtexturename		= "battle_interface\ShipBackIcon.tga";
	BattleInterface.ShipIcon.backcolor				= argb(255,128,128,128);
	BattleInterface.ShipIcon.backuv					= "0.0,0.0,1.0,1.0";
	BattleInterface.ShipIcon.backoffset				= "-2,-2";
	BattleInterface.ShipIcon.backiconsize			= "128,128";

	BattleInterface.ShipIcon.shipstatetexturename	= "battle_interface\ShipState.tga";
	BattleInterface.ShipIcon.shipstatecolor			= argb(255,128,128,128);
	BattleInterface.ShipIcon.shiphpuv				= "0.0,0.109,0.5,0.6875";
	BattleInterface.ShipIcon.shiphpoffset			= "-32,-13";
	BattleInterface.ShipIcon.shiphpiconsize			= "64,74";
	BattleInterface.ShipIcon.shipspuv				= "0.5,0.109,1.0,0.6875";
	BattleInterface.ShipIcon.shipspoffset			= "32,-13";
	BattleInterface.ShipIcon.shipspiconsize			= "64,74";

	BattleInterface.ShipIcon.shipclasstexturename	= "battle_interface\ShipClass.tga";
	BattleInterface.ShipIcon.shipclasscolor			= argb(255,102,102,102); //argb(255,128,128,128);
	BattleInterface.ShipIcon.shipclassuv			= "0.0,0.0,1.0,1.0";
	BattleInterface.ShipIcon.shipclassoffset		= "-14,-52";
	BattleInterface.ShipIcon.shipclassiconsize		= "64,16";
	BattleInterface.ShipIcon.gunchargeprogress		= "0.0625, 0.211, 0.359, 0.5, 0.633, 0.781, 0.983"; //Tymofei: �������� ��� ������ �������, � ���� �� �����, �� ������� ��� �������� - �����!

	BattleInterface.ShipIcon.shiptexturename		= "battle_interface\ship_icons2.tga";
	BattleInterface.ShipIcon.shipcolor				= argb(255,128,128,128);
	BattleInterface.ShipIcon.shipoffset				= "-14,-12";
	BattleInterface.ShipIcon.shipiconsize			= "64,64";

	BattleInterface.ShipIcon.commandlistverticaloffset = -40;

	BattleInterface.ShipIcon.iconoffset1 = "70,70";
	BattleInterface.ShipIcon.iconoffset2 = "70,198";
	BattleInterface.ShipIcon.iconoffset3 = "70,326";
	BattleInterface.ShipIcon.iconoffset4 = "70,454";
	BattleInterface.ShipIcon.iconoffset5 = "70,582";
	BattleInterface.ShipIcon.iconoffset6 = "70,710";
	BattleInterface.ShipIcon.iconoffset7 = "70,838";
	BattleInterface.ShipIcon.iconoffset8 = "70,966";

	BattleInterface.CommandList.CommandMaxIconQuantity = 10; //boal
	BattleInterface.CommandList.CommandIconSpace = 1;
	BattleInterface.CommandList.CommandIconLeft = 108;//157;
	BattleInterface.CommandList.CommandIconWidth = RecalculateHIcon(48);
	BattleInterface.CommandList.CommandIconHeight = RecalculateVIcon(48);

	BattleInterface.CommandList.CommandNoteFont = "interface_normal";
	BattleInterface.CommandList.CommandNoteColor = argb(255,255,255,255);
	BattleInterface.CommandList.CommandNoteScale = 1.0;
	BattleInterface.CommandList.CommandNoteOffset = RecalculateHIcon(0) + "," + RecalculateVIcon(-42);

	BattleInterface.CommandList.UDArrow_Texture = "battle_interface\arrowly.tga";
	BattleInterface.CommandList.UDArrow_UV_Up = "0.0,1.0,1.0,0.0";
	BattleInterface.CommandList.UDArrow_UV_Down = "0.0,0.0,1.0,1.0";
	BattleInterface.CommandList.UDArrow_Size = RecalculateHIcon(32) + "," + RecalculateVIcon(32);
	BattleInterface.CommandList.UDArrow_Offset_Up = RecalculateHIcon(-41) + "," + RecalculateVIcon(-30);
	BattleInterface.CommandList.UDArrow_Offset_Down = RecalculateHIcon(-41) + "," + RecalculateVIcon(46);

	/*BattleInterface.CommandList.ActiveIcon_Texture = "battle_interface\enter_list.tga";
	BattleInterface.CommandList.ActiveIcon_Offset = RecalculateHIcon(-49) + ",0";
	BattleInterface.CommandList.ActiveIcon_Size = RecalculateHIcon(48) + "," + RecalculateVIcon(48);
	BattleInterface.CommandList.ActiveIcon_UV1 = "0.5,0.0,1.0,1.0";
	BattleInterface.CommandList.ActiveIcon_UV2 = "0.0,0.0,0.5,1.0";
	BattleInterface.CommandList.ActiveIcon_Note = XI_ConvertString("MenuNote"); */

	BattleInterface.ShipInfoImages.RelationTexture = "battle_interface\ship_arrows1.tga";
	BattleInterface.ShipInfoImages.RelationOffset.x = 0.0;
	BattleInterface.ShipInfoImages.RelationOffset.y = 0.3;
	BattleInterface.ShipInfoImages.RelationOffset.z = 0.0;
	BattleInterface.ShipInfoImages.RelationSize = "0.75,0.5";
	BattleInterface.ShipInfoImages.RelationUV1 = "0.0,0.0,0.25,1.0"; // friend
	BattleInterface.ShipInfoImages.RelationUV2 = "0.25,0.0,0.5,1.0"; // enemy
	BattleInterface.ShipInfoImages.RelationUV3 = "0.5,0.0,0.75,1.0"; // neutral

	BattleInterface.ShipInfoImages.ProgressTexture = "battle_interface\indicators.tga";
	BattleInterface.ShipInfoImages.ProgressSize = "2.0,0.1";
	//
	BattleInterface.ShipInfoImages.ProgressBackOffset.x = 0.0;
	BattleInterface.ShipInfoImages.ProgressBackOffset.y = 0.65;
	BattleInterface.ShipInfoImages.ProgressBackOffset.z = 0.0;
	BattleInterface.ShipInfoImages.ProgressBackSize = "2.0,0.3";
	BattleInterface.ShipInfoImages.ProgressBackUV = "0.0,0.5,1.0,1.0";
	//
	BattleInterface.ShipInfoImages.HullOffset.x = 0.0;
	BattleInterface.ShipInfoImages.HullOffset.y = 0.75;
	BattleInterface.ShipInfoImages.HullOffset.z = 0.0;
	BattleInterface.ShipInfoImages.HullUV = "0.0,0.333,1.0,0.5";
	//
	BattleInterface.ShipInfoImages.SailOffset.x = 0.0;
	BattleInterface.ShipInfoImages.SailOffset.y = 0.65;
	BattleInterface.ShipInfoImages.SailOffset.z = 0.0;
	BattleInterface.ShipInfoImages.SailUV = "0.0,0.167,1.0,0.333";
	//
	BattleInterface.ShipInfoImages.CrewOffset.x = 0.0;
	BattleInterface.ShipInfoImages.CrewOffset.y = 0.55;
	BattleInterface.ShipInfoImages.CrewOffset.z = 0.0;
	BattleInterface.ShipInfoImages.CrewUV = "0.0,0.0,1.0,0.166";

	BattleInterface.ShifInfoVisible = InterfaceStates.enabledshipmarks;
}

ref ProcessSailDamage()
{
	// �� ���� ����
	int shootIdx = GetEventData();
	// ����
	int chrIdx = GetEventData();

	string sMastName = GetEventData();
	// ���������� ������
	string reyName = GetEventData();
	int groupNum = GetEventData();
	// ������ � ������
	int holeCount = GetEventData();
	int holeData = GetEventData();
	int maxHoleCount = GetEventData();
	// �������� ������
	float sailPower = GetEventData();

	ref chref = GetCharacter(chrIdx);
	
	if (LAi_IsImmortal(chref)) 
	{ 
		BI_g_fRetVal = 0;
		return &BI_g_fRetVal;
	}

	string groupName = ""+groupNum;
	aref arSail;
	makearef(arSail,chref.ship.sails.(reyName).(groupName));

	float sailDmg = 0.0;
	float sailDmgMax = GetCharacterShipSP(chref) * sailPower;
	if( !CheckAttribute(arSail,"dmg") )	{ sailDmg = 0.0; }

	if(sMastName=="*")
	{
		sailDmg = sailDmg + GetRigDamage(shootIdx,sti(AIBalls.CurrentBallType),chref);
		if(sailDmg>sailDmgMax)	{ sailDmg = sailDmgMax; }
		int needHole = GetNeedHoleFromDmg(sailDmg,sailDmgMax,maxHoleCount);
		if(holeCount!=needHole)
		{
			if(holeCount<needHole)
			{
				holeData = RandomHole2Sail(chrIdx,reyName,groupNum, maxHoleCount, holeData, needHole-holeCount);
				holeCount = needHole;
			}
			else
			{
				sailDmg = GetNeedDmgFromHole(holeCount,sailDmgMax,maxHoleCount);
			}
		}
	}
	else
	{
		if(sMastName!="#")	{ arSail.mastFall = sMastName; }
		sailDmg = sailDmgMax;
	}
	
	arSail.hc = holeCount;
	arSail.hd = holeData;
	arSail.mhc = maxHoleCount;
	arSail.sp = sailPower;
	arSail.dmg = sailDmg;

	BI_g_fRetVal = sailDmg;
	return &BI_g_fRetVal;
}

// ugeen -> ���� ������������� ����� �������
void ProcessHullDecrease()
{
	int i, cn, hp;
	ref chref;
	ref mchar = GetMainCharacter();
	
	if (!bSeaActive || mchar.location == mchar.SystemInfo.CabinType) // ���� � �����
	{
		for (i=0; i<COMPANION_MAX; i++)
		{
			cn = GetCompanionIndex(mchar,i);
			if(cn == -1) continue;
			chref = GetCharacter(cn);
	
			if(CheckAttribute(chref, "Ship.HP_penalty"))
			{
				hp = sti(RealShips[sti(chref.ship.type)].HP);	// ������� ��������
				if(hp > makeint(stf(chref.Ship.HP_penalty)) ) RealShips[sti(chref.ship.type)].HP = hp - makeint(stf(chref.Ship.HP_penalty)); 
				else RealShips[sti(chref.ship.type)].HP = 1;
				if( GetCurrentShipHP(chref) > sti(RealShips[sti(chref.ship.type)].HP) )
				{
					chref.ship.hp =	sti(RealShips[sti(chref.ship.type)].HP);
				}
				DeleteAttribute(chref, "Ship.HP_penalty");
			}	
		}
	}	
}
// <-- ugeen

bool CheckRepairPerks(ref chref)
{	
	if( CheckOfficersPerk(chref, "Carpenter") 		||
	    CheckOfficersPerk(chref, "LightRepair")		||
		CheckOfficersPerk(chref, "Builder")			||
		CheckOfficersPerk(chref, "SelfRepair"))	return true;
	return false;	
}

// ������� �� ��� 25/09/06
void ProcessDayRepair()
{
	int i, cn;
	float matQ, tmpf, repPercent;
	ref chref;
	ref mchar = GetMainCharacter();
	// boal 21.01.2004 �� ���� � ���� �� �����, �� ���� ��� ���� � ���� -->
	//if (bSeaActive == false || mchar.location == mchar.SystemInfo.CabinType) // ���� � �����
	if (!bSeaActive || mchar.location != mchar.SystemInfo.CabinType) // ��� ������ � ����� �� �������
	{		
		for (i=0; i<COMPANION_MAX; i++)
		{
			cn = GetCompanionIndex(mchar,i);
			if(cn==-1) continue;
			chref = GetCharacter(cn);
			if(CheckRepairPerks(chref))
			{	
				// ������ ������� �������
				if (GetHullPercent(chref) < 100.0 )
				{
					repPercent = GetHullRPD(chref);
					matQ = repPercent*GetHullPPP(chref);
					tmpf = GetRepairGoods(true,chref);
					if (tmpf > 0)
					{
						if (tmpf < matQ)	{ repPercent = tmpf/GetHullPPP(chref); }  
						repPercent = ProcessHullRepair(chref, repPercent);
						matQ = repPercent*GetHullPPP(chref);
						RemoveRepairGoods(true,chref,matQ);
						// boal  check skill -->
						AddCharacterExpToSkill(chref, "Repair", matQ / 3.0);
						// boal <--
					}
				}
				
				// ������ ������� �������
				if (GetSailPercent(chref) < GetAllSailsDamagePercent(chref) )
				{
					repPercent = GetSailRPD(chref);
					matQ = repPercent*GetSailSPP(chref);
					tmpf = GetRepairGoods(false,chref);
					
					if (tmpf > 0)
					{
						if (tmpf < matQ)	{ repPercent = tmpf/GetSailSPP(chref); }
						repPercent = ProcessSailRepair(chref,repPercent);
						matQ = repPercent*GetSailSPP(chref);
						RemoveRepairGoods(false,chref,matQ);
						// boal  check skill -->
						AddCharacterExpToSkill(chref, "Repair", matQ / 4.0);
						// boal <--
					}
				}
			}
		}
	}
	// boal 21.01.2004 <--
}

ref procGetSailTextureData()
{
	int st,i,sq;
	ref shref;
	aref arEmbl,arSail;
	string attrName;

	int chrIdx = GetEventData();

	DeleteAttribute(&BI_objRetValue,"");
    if (chrIdx>=0)
	{
		st = GetCharacterShipType(GetCharacter(chrIdx));
		if (st != SHIP_NOTUSED)
		{
			//string sUpgrade = "common";
			string sUpgrade = "usual0";
		
			shref = GetRealShip(st); 
		
			int iUpgrade = sti(shref.ship.upgrades.sails);  
			/*switch(iUpgrade)
			{
				case 1:
					sUpgrade = "common";
				break;
				case 2: 
					sUpgrade = "pat";
				break;
				case 3:
					sUpgrade = "silk";
				break;
			}*/
			// Jason: ����� ���� �������, ����������� � ���� �����
			switch(iUpgrade)
			{
				case 1:
					sUpgrade = "usual0";
				break;
				case 2: 
					sUpgrade = "usual1";
				break;
				case 3:
					sUpgrade = "usual2";
				break;
				case 4:
					sUpgrade = "usual3";
				break;
				case 5:
					sUpgrade = "usual4";
				break;
				case 6:
					sUpgrade = "wing"; // �����
				break;
				case 7:
					sUpgrade = "win0"; // ����� �������
				break;
				case 8:
					sUpgrade = "win1"; // ������� �������
				break;
				case 9:
					sUpgrade = "win2"; // ����-������� �����
				break;
				case 10:
					sUpgrade = "win3"; // �����������
				break;
				case 11:
					sUpgrade = "win4"; // ������� �����
				break;
				case 12:
					sUpgrade = "torn"; // �������
				break;
				case 13:
					sUpgrade = "silk"; // ����
				break;
			}
		
			string nationFileName = "ships\parus_" + sUpgrade + ".tga";
			string tmpStr;
		
			BI_objRetValue.normalTex = nationFileName;
			BI_objRetValue.geraldTex = "";//"ships\gerald\chuckskull.tga";
			BI_objRetValue.sailscolor = argb(255,255,255,255);  // ����� �����
		
			//BI_objRetValue.geraldTexPointer = 0; // (IDirect3DTexture8*)
			
			//if (CheckAttribute(&characters[chrIdx], "ShipSails.SailsColor"))
			if (CheckAttribute(shref, "ShipSails.SailsColor")) // 1.2.3 ���� ������ ������� �������, � �� ���
			{
				BI_objRetValue.sailscolor = sti(shref.ShipSails.SailsColor);
			}
			//if( CheckAttribute(&characters[chrIdx],"ShipSails.gerald_name") ) // �� ����������� ��� ������ ��������, ������ �� �  ship.
			if( CheckAttribute(shref,"ShipSails.gerald_name") ) // 1.2.3 ���� ������ ������� �������, � �� ���
			{
				BI_objRetValue.geraldTex = "Ships\Gerald\" + shref.ShipSails.gerald_name + ".tga";
			}
			/*
			switch(sti(Characters[chrIdx].nation))  // �� �������� ��� :(
			{
				case ENGLAND:	
					nationFileName = "ships\parus_" + sUpgrade + "_england.tga";		
				break;
				case FRANCE:	
					nationFileName = "ships\parus_" + sUpgrade + "_france.tga";		
				break;
				case SPAIN:		
					nationFileName = "ships\parus_" + sUpgrade + "_spain.tga";	
				break;
				case PIRATE:
					nationFileName = "ships\parus_" + sUpgrade + "_pirate.tga";
					//BI_objRetValue.normalTex = "ships\sail_Pirates.tga";
				break;
				case HOLLAND:	
					nationFileName = "ships\parus_" + sUpgrade + "_holland.tga";	
				break;
			}
			*/
			
			BI_objRetValue.maxSP = shref.sp;
			// boal -->
			if (CheckAttribute(shref, "EmblemedSails.normalTex")) // ��������� � ���� �����
		    {
		        BI_objRetValue.normalTex = shref.EmblemedSails.normalTex;
		        nationFileName           = shref.EmblemedSails.normalTex;
		    }
			if( CheckAttribute(&Characters[chrIdx],"Features.GeraldSails") && sti(Characters[chrIdx].Features.GeraldSails)==true) 
			{
				makearef(arEmbl,shref.GeraldSails);
			} else {
				makearef(arEmbl,shref.EmblemedSails);
			} 
			/*if (CheckAttribute(shref, "GeraldSails"))
		    {
		        makearef(arEmbl, shref.GeraldSails);  */
				// boal <--
			sq = GetAttributesNum(arEmbl);
			for(i=0; i<sq; i++)
			{
				arSail = GetAttributeN(arEmbl,i);
				attrName = GetAttributeName(arSail);
				tmpStr = GetAttributeValue(arSail);
				if( CheckAttribute(arSail,"hscale") ) {
					BI_objRetValue.(attrName).hscale = arSail.hscale;
				}
				if( CheckAttribute(arSail,"vscale") ) {
					BI_objRetValue.(attrName).vscale = arSail.vscale;
				}
				if(tmpStr=="1") {
					//BI_objRetValue.(attrName).Gerald = nationFileName;  
					BI_objRetValue.(attrName) = nationFileName;
				} else {
					BI_objRetValue.(attrName).Gerald = tmpStr;
				}
				//BI_objRetValue.(attrName).Gerald = "ships\chuckskull.tga"; // �������� ����� (���� �� �������, �� ������� BI_objRetValue.geraldTex ��� BI_objRetValue.geraldTexPointer)
				//BI_objRetValue.(attrName).hscale = 0.5; // ������� � ������� ������ (0.5 - ���� �������� �������� ������)
				//BI_objRetValue.(attrName).vscale = 0.5; // ���� ��� vscale, �� ������������ = scale
			}
			//}
		}
	}

	return &BI_objRetValue;
}

ref procGetRiggingData()
{
	int i,n,s;

	string datName = GetEventData();
	i = GetEventData();
	n = GetEventData();
	s = GetEventData();	// isSpecial Flag ??	
	
	if(datName == "GetShipFlagTexNum")
	{
		aref rCharacter = GetEventData();

		switch(n)
		{
		case HOLLAND: 	
			BI_intNRetValue[0] = GetHollandFlag(rCharacter);  
			BI_intNRetValue[1] = FLAG_HOL; 		
		break;	
		case ENGLAND: 	
			BI_intNRetValue[0] = GetEnglandFlag(rCharacter);  
			BI_intNRetValue[1] = FLAG_ENG; 		
		break;	
		case FRANCE: 	
			BI_intNRetValue[0] = GetFranceFlag(rCharacter);  
			BI_intNRetValue[1] = FLAG_FRA; 		
		break;
		case SPAIN: 	
			BI_intNRetValue[0] = GetSpainFlag(rCharacter);  
			BI_intNRetValue[1] = FLAG_SPA; 		
		break;
		case PIRATE: 	
			BI_intNRetValue[0] = GetPirateFlag(rCharacter); 
			BI_intNRetValue[1] = FLAG_PIR; 		
		break;								
		}
		if(n != PIRATE)
		{
			if(s == 1)	BI_intNRetValue[1] = GetShipFlagTextureNum(rCharacter); 	
			//else 		BI_intNRetValue[1] = FLAG_WHT; 
		}			
	}
	
	if(datName == "GetTownFlagTexNum")
	{				
		switch(n)
		{
			case HOLLAND: 	BI_intNRetValue[0] = 0; break;						
			case ENGLAND: 	BI_intNRetValue[0] = 1; break;
			case FRANCE: 	BI_intNRetValue[0] = 2; break;
			case SPAIN: 	BI_intNRetValue[0] = 3; break;						
			case PIRATE: 	
				BI_intNRetValue[0] = 0; 		
				BI_intNRetValue[1] = FLAG_PIR; 		
			break;
		}		
		if(n != PIRATE)
		{	
			if(s == 1) BI_intNRetValue[1] = FLAG_ADM; 
			else	   BI_intNRetValue[1] = FLAG_ADM; 	// ���������� ��� ��� ��� ����������, �� �� ��� ������ ����� �������� :( 
		}				
	}	
	return &BI_intNRetValue;
}

// --> ugeen
void SetTownFlag(ref loc, object mdl)
{
	if (!CheckAttribute(loc, "townsack")) return;
	int iNation = GetCityNation(loc.townsack);
	if(iNation == PIRATE) 
	{	
		SendMessage(&Flag, "lil", MSG_FLAG_INIT_TOWN, &mdl, iNation);
		return;
	}
	SendMessage(&Flag, "lil", MSG_FLAG_INIT_TOWN, &mdl, iNation);
}

void SetFortFlag(ref rModel)
{
	if (!CheckAttribute(rModel, "fortcmdridx")) return;
	int idx = sti(rModel.fortcmdridx);
	if (idx < 0) return;
	ref chr = GetCharacter(idx);
	int iNation = sti(chr.nation);
	if(iNation == PIRATE) 
	{		
		SendMessage(&Flag, "lil", MSG_FLAG_INIT_TOWN, &rModel, iNation);
		return;
	}		
	SendMessage(&Flag, "lil", MSG_FLAG_INIT_TOWN, &rModel, iNation);	
}

int GetPirateFlag(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;
	if(CheckAttribute(chr, "Flags.Pirate")) 
	{
		return sti(chr.Flags.Pirate);
	}	
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if (!CheckAttribute(cmdr, "Flags.Pirate")) 
	{
		cmdr.Flags.Pirate = rand(2);
	}	
	return sti(cmdr.Flags.Pirate); 
}

int GetHollandFlag(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;
	if(CheckAttribute(chr, "Flags.Holland")) 
	{
		return sti(chr.Flags.Holland);
	}	
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if (!CheckAttribute(cmdr, "Flags.Holland")) 
	{
		cmdr.Flags.Holland = rand(3);
	}	
	return sti(cmdr.Flags.Holland); 
}

int GetEnglandFlag(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;
	if(CheckAttribute(chr, "Flags.England")) 
	{
		return sti(chr.Flags.England);
	}	
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if (!CheckAttribute(cmdr, "Flags.England")) 
	{
		cmdr.Flags.England = rand(3);
	}	
	return sti(cmdr.Flags.England); 
}

int GetFranceFlag(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;
	if(CheckAttribute(chr, "Flags.France")) 
	{
		return sti(chr.Flags.France);
	}	
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if (!CheckAttribute(cmdr, "Flags.France")) 
	{
		cmdr.Flags.France = rand(3);
	}	
	return sti(cmdr.Flags.France); 
}

int GetSpainFlag(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;
	if(CheckAttribute(chr, "Flags.Spain")) 
	{
		return sti(chr.Flags.Spain);
	}	
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if (!CheckAttribute(cmdr, "Flags.Spain")) 
	{
		cmdr.Flags.Spain = rand(3);
	}	
	return sti(cmdr.Flags.Spain); 
}

bool IsShipCommander(ref chr)
{
	string sGroup = GetGroupIDFromCharacter(chr);
	if(sGroup == "") return 0;
	ref cmdr = Group_GetGroupCommander(sGroup);
	if(chr.id == cmdr.id) return true;
	return false;
}

bool IsShipMerchant(ref chr)
{
	if (CheckAttribute(chr, "RealEncounterType") && 
	    CheckAttribute(chr, "Ship.Mode") && 
		chr.Ship.Mode == "trade") return true;
	return false;
}

int GetShipFlagTextureNum(ref chr)
{
	if(!CheckAttribute(chr,"id")) return 0;	
	int iNation = sti(chr.nation);
	
	if(iNation == PIRATE) return FLAG_PIR;
	else
	{		
		//���� ������ - ����������� ����� ����
		if(CheckAttribute(chr,"surrendered")) return FLAG_WHT;			
		else
		{		
			//if(IsCompanion(chr) || IsMainCharacter(chr) || chr.id == "BoatChar") // �� , ����������, ������ � ������
			{
			//if(iNation != PIRATE) return FLAG_WHT;								
			//else				  return FLAG_PIR; 	
			}			
			else
			{			
			// ����������� ���������
			//if(IsShipCommander(chr)) return FLAG_WHT;								
				else
				{
					// ��������
			//if(IsShipMerchant(chr)) return FLAG_WHT;		
			// ��� ������ .. ������� �������, ������� � �.�.
			//else 					return FLAG_WHT;									
				}				
			}			
		}					
	}		
	return &BI_intNRetValue;
}
// <-- ugeen

void procBISelectShip()
{
	int chrIdx = GetEventData();
	int isMyChr = GetEventData();

	if(chrIdx==nMainCharacterIndex)	chrIdx = -1;

	float fShSpeed = 0.005;
	float fShAmp = 1.0;
	float fShW = 1.0;
	float fShH = 1.0;
	float fTop = 5.0;

	SendMessage(&objShipPointer,"lllfffff",MSG_SP_CHANGESHIP,chrIdx,isMyChr,fShSpeed,fShAmp,fShW,fShH,fTop);
}

ref procGetSmallFlagData()
{
	int chrIdx = GetEventData();
	BI_intNRetValue[0] = 3;
	BI_intNRetValue[1] = 0;
	if( chrIdx >= 0 ) {
		int iNation = sti(Characters[chrIdx].nation);
		switch( iNation )
		{
		case ENGLAND: BI_intNRetValue[1]=3; break;
		case FRANCE: BI_intNRetValue[1]=2; break;
		case SPAIN: BI_intNRetValue[1]=0; break;
		case HOLLAND: BI_intNRetValue[1]=4; break;
		case PIRATE: BI_intNRetValue[1]=5; break;
		//case SMUGGLER: BI_intNRetValue[1]=1; break;
		}

		BI_intNRetValue[2] = 7;
		switch( SeaAI_GetRelation(chrIdx,nMainCharacterIndex) )
		{
			case RELATION_FRIEND:	BI_intNRetValue[2] = 7; break;
			case RELATION_NEUTRAL:	BI_intNRetValue[2] = 7; break;
			case RELATION_ENEMY:	BI_intNRetValue[2] = 6; break;
		}
	}
	return &BI_intNRetValue;
}

void procMastFall()
{
	int chrIdx = GetEventData();
	string mastName = GetEventData();
	int bFirstFall = GetEventData();

	if(chrIdx<0) return;
	int mastNum = strcut(mastName,4,strlen(mastName)-1);

	//trace("For character "+chrIdx+" fall Mast name "+mastName+" has index "+mastNum);
	SendMessage(&Sailors, "lal", MSG_PEOPLES_ON_SHIP_MASTFALL, GetCharacter(chrIdx), mastNum);
}

bool CheckInstantRepairCondition(ref chref)
{
//boal -->
	if(MOD_SKILL_ENEMY_RATE > 5) return false;
    if (CheckOfficersPerk(chref,"InstantRepair")) return false;  // ��� � ����
    if (!GetOfficersPerkUsing(chref,"InstantRepair")) return false;  // ����� ��������?
//boal <--

	float chrShipHP = GetHullPercent(chref);
	float chrShipSP = GetSailPercent(chref);

	bool bYesHPRepair = chrShipHP < InstantRepairRATE;// boal 23.01.2004
	bool bYesSPRepair = chrShipSP < InstantRepairRATE; // boal 23.01.2004

	if( bYesHPRepair )	{ bYesHPRepair = GetCargoGoods(chref,GOOD_PLANKS)>0; }
	if( bYesSPRepair )	{ bYesSPRepair = GetCargoGoods(chref,GOOD_SAILCLOTH)>0; }

	return bYesHPRepair || bYesSPRepair;
}

void BI_PerkAgainUsable()
{
	BI_SetCommandMode(-1,-1,-1,-1);
}

float GetRepairGoods(bool bIsHull, ref chref)
{
	float fGoodsQ = 0.0;

	if( bIsHull )
	{
		fGoodsQ = GetCargoGoods(chref,GOOD_PLANKS);
		if( CheckAttribute(chref,"RepairMaterials.forHull") )   // ����������� ���������� �������� ����� ����� �� �������
		{	
			fGoodsQ += stf(chref.RepairMaterials.forHull);
		}
	}
	else
	{
		fGoodsQ = GetCargoGoods(chref,GOOD_SAILCLOTH);
		if( CheckAttribute(chref,"RepairMaterials.forSails") )
		{	
			fGoodsQ += stf(chref.RepairMaterials.forSails);
		}
	}

	return fGoodsQ;
}

void RemoveRepairGoods(bool bIsHull, ref chref, float matQ)
{
	int nGoodsQ = 0;
	float fGoodsQ = GetRepairGoods(bIsHull,chref);

	if( bIsHull )
	{
		if(fGoodsQ<=matQ)	{ DeleteAttribute(chref,"RepairMaterials.forHull"); }
		else
		{
			fGoodsQ -= matQ;
			nGoodsQ = makeint(fGoodsQ);
			chref.RepairMaterials.forHull = fGoodsQ - nGoodsQ;
		}
		SetCharacterGoods(chref,GOOD_PLANKS,nGoodsQ);
	}
	else
	{
		if(fGoodsQ<=matQ)	{ DeleteAttribute(chref,"RepairMaterials.forSails"); }
		else
		{
			fGoodsQ -= matQ;
			nGoodsQ = makeint(fGoodsQ);
			chref.RepairMaterials.forSails = fGoodsQ - nGoodsQ;
		}
		SetCharacterGoods(chref,GOOD_SAILCLOTH,nGoodsQ);
	}

}

float GetRigDamage(int shootIdx, int iBallType, ref damage_chr)
{
	ref rBall = GetGoodByType(iBallType);
	float fDistanceDamageMultiply = Bring2Range(1.2, 0.25, 0.0, stf(AIBalls.CurrentMaxBallDistance), stf(AIBalls.CurrentBallDistance));
	float fDmgRig = fDistanceDamageMultiply * stf(rBall.DamageRig);
	//float fDmgRig = stf(rBall.DamageRig);
    if (shootIdx>=0 )
	{
		ref shoot_chr = GetCharacter(shootIdx);
		if (CheckOfficersPerk(shoot_chr,"CannonProfessional") )	{ fDmgRig *= 1.3; }
		else
		{
			if( CheckOfficersPerk(shoot_chr,"SailsDamageUp") )	{ fDmgRig *= 1.15; }
		}
	}
	
	if (CheckOfficersPerk(damage_chr,"ShipDefenseProfessional") )	{ fDmgRig *= 0.65; } // fix
	else
	{
		if (CheckOfficersPerk(damage_chr,"AdvancedBattleState") )	{ fDmgRig *= 0.75; } // fix
		else
		{
			if (CheckOfficersPerk(damage_chr,"BasicBattleState") )	{ fDmgRig *= 0.85; } // fix
		}
	}
	
	fDmgRig = isEquippedAmuletUse(shoot_chr, "indian_8", fDmgRig, 1.05 );
	fDmgRig = isEquippedAmuletUse(damage_chr, "amulet_9", fDmgRig, 0.85 );
	// Addon 2016-1 Jason ��������� �������
	if (CheckAttribute(damage_chr, "SeaBoss")) { fDmgRig *= 0.1; }
		
	return fDmgRig;
}

void MakeSailDmg(int chrIdx, float dmg)
{
	object objSail;
	if( !FindClass(&objSail,"sail") )
	{
		return;
	}
	int iSailsUpgrade = 1;
	if(!CheckAttribute(&characters[chrIdx], "upgrades.sails"))
	{
		characters[chrIdx].upgrades.sails = 1;
	}
	//������� 1 ������� �������� (������ �� ���������))
	iSailsUpgrade = sti(characters[chrIdx].upgrades.sails) - 1;
	dmg = dmg + ((dmg/100)*iSailsUpgrade*5);
	SendMessage(&objSail,"lslf", MSG_SAIL_SCRIPT_PROCESSING,"RandomSailsDmg", chrIdx,dmg);
}

ref ProcessRandomSailDmg()
{
	BI_g_fRetVal = 0.0;
	//"lslfflll"
	int chrIdx = GetEventData();
	string nodeName = GetEventData();
	int grNum = GetEventData();
	float fDmg = GetEventData();
	float fSPow = GetEventData();
	int hc_new = GetEventData();
	int mhc = GetEventData();
	int hdat_new = GetEventData();

	if(chrIdx<0) return &BI_g_fRetVal;
	ref chref = GetCharacter(chrIdx);

	aref arSail;
	string groupName = ""+grNum;
	makearef(arSail,chref.ship.sails.(nodeName).(groupName));

	int hc_old = 0;
	if( CheckAttribute(arSail,"hc") )	hc_old = sti(arSail.hc);
	float fDmg_old = 0.0;
	if( CheckAttribute(arSail,"dmg") )	fDmg_old = stf(arSail.dmg);

	int itmp = hc_new;
	float sailDmgMax = GetCharacterShipSP(chref) * fSPow;

	float fTopDmg = sailDmgMax;
	if(itmp<mhc)	fTopDmg = GetNeedDmgFromHole(itmp+1,sailDmgMax,mhc) - 0.0001;
	if(fTopDmg>fDmg_old+fDmg)	fTopDmg = fDmg_old+fDmg;

	fDmg = fTopDmg-fDmg_old;
	if(fDmg<=0.0)	return &BI_g_fRetVal;
	chref.ship.SP = stf(chref.ship.SP)-fDmg;

	itmp = GetNeedHoleFromDmg(fTopDmg,sailDmgMax,mhc);
	if(itmp>hc_old)
	{
		BI_g_fRetVal = fDmg;
		arSail.hc = hc_new;
		arSail.hd = hdat_new;
	}
	else
	{
		BI_g_fRetVal = -fDmg;
		if( !CheckAttribute(arSail,"hc") )	arSail.hc = 0;
		if( !CheckAttribute(arSail,"hd") )	arSail.hd = 0;
	}

	arSail.mhc = mhc;
	arSail.sp = fSPow;
	arSail.dmg = fTopDmg;

	return &BI_g_fRetVal;
}

void GetSailStatus(int chrIdx)
{	
	object objSail;
	if( !FindClass(&objSail,"sail") )
	{
		return;
	}
	if(chrIdx < 0) return;
	ref chref = GetCharacter(chrIdx);
	if(CheckAttribute(chref,"ship.sailstatus")) DeleteAttribute(chref,"ship.sailstatus"));
	SendMessage(&objSail,"lsl", MSG_SAIL_SCRIPT_PROCESSING,"GetSailStatus", chrIdx);
}	

void procGetSailStatus()
{
	int chrIdx 		= GetEventData();
	string nodeName = GetEventData();
	int grNum 		= GetEventData();
	float fSPow 	= GetEventData();
	int hc 			= GetEventData();
	int mhc 		= GetEventData();
	
	if(chrIdx < 0) return;
	ref chref = GetCharacter(chrIdx);
	
	aref arSail;
	string groupName = ""+grNum;
	chref.ship.sailstatus = sti(chref.ship.sailstatus) + 1;
	
	makearef(arSail,chref.ship.sailstatus.(nodeName).(groupName));
	
	arSail.mhc 	= mhc;
	arSail.hc 	= hc;
	arSail.sp 	= fSPow;
}

void procSetUsingAbility()
{
	//Log_Info("procSetUsingAbility");
	int q;
	int chIdx = GetEventData();
	int mainIdx = sti(pchar.index);
	aref aroot,arcur;
	string tmpStr;

	if( chIdx<0 || CharacterIsDead(GetCharacter(chIdx)) )
	{
		makearef(aroot,BattleInterface.AbilityIcons);
		q = GetAttributesNum(aroot);
		for(int i=0; i<q; i++)
		{
			arcur = GetAttributeN(aroot,i);
			arcur.enable = false;
		}
		return;
	}

	// ��� �������� ���������
	if(mainIdx==chIdx)
	{
		
        BattleInterface.Commands.Bomb.enable = true;
		BattleInterface.Commands.Brander.enable			= false;
		//BattleInterface.AbilityIcons.Troopers.enable		= false;

        //if (bBettaTestMode) BattleInterface.AbilityIcons.InstantBoarding.enable	= bAttack;
		////////////////////////////////////////////
		BattleInterface.Commands.ImmediateReload.enable	= false; //GetCharacterPerkUsing
        if (!CheckOfficersPerk(pchar, "ImmediateReload") && GetOfficersPerkUsing(pchar, "ImmediateReload"))
        {
            BattleInterface.Commands.ImmediateReload.enable = true;
        }
		BattleInterface.Commands.LightRepair.enable		= false;
		if (!CheckOfficersPerk(pchar, "LightRepair") && GetOfficersPerkUsing(pchar,"LightRepair"))
		{
            if(GetHullPercent(pchar)<10.0 || GetSailPercent(pchar)<10.0)
			{
                BattleInterface.Commands.LightRepair.enable = true;
			}
		}
		BattleInterface.Commands.InstantRepair.enable	= CheckInstantRepairCondition(pchar);
		BattleInterface.Commands.Turn180.enable = false;
		if (!CheckOfficersPerk(pchar, "Turn180") && GetOfficersPerkUsing(pchar, "Turn180"))
        {
			BattleInterface.Commands.Turn180.enable = true;
        }
		// Set items abilities
		q = FindQuestUsableItem(&arcur,0);
		while( q>0 )
		{
			tmpStr = arcur.id;
			if( GetCharacterItem(pchar,arcur.id)>0 )
			{
				BattleInterface.AbilityIcons.(tmpStr).enable	= true;
				BattleInterface.AbilityIcons.(tmpStr).picNum	= arcur.quest.pic;
				BattleInterface.AbilityIcons.(tmpStr).texNum	= 9;
				BattleInterface.AbilityIcons.(tmpStr).event		= arcur.id;
				BattleInterface.AbilityIcons.(tmpStr).quest		= arcur.quest;
			}
			else
			{
				BattleInterface.AbilityIcons.(tmpStr).enable	= false;
			}
			q = FindQuestUsableItem(&arcur,q+1);
		}
	}

	else
	{
		BattleInterface.Commands.Brander.enable			= false;
		BattleInterface.Commands.Bomb.enable = true;
		if(bAttack && GetRemovable(GetCharacter(chIdx)) && GetOfficersPerkUsing(pchar,"Brander"))
		{
			BattleInterface.Commands.Brander.enable		= true;
		}
		//BattleInterface.AbilityIcons.Troopers.enable		= GetCharacterPerkUsing(pchar,"Troopers");

		BattleInterface.Commands.InstantRepair.enable	= CheckInstantRepairCondition(GetCharacter(chIdx));		
		BattleInterface.Commands.ImmediateReload.enable	= GetCharacterPerkUsing(GetCharacter(chIdx), "ImmediateReload");//false;
		BattleInterface.Commands.InstantBoarding.enable	= false;
		BattleInterface.Commands.LightRepair.enable		= GetCharacterPerkUsing(GetCharacter(chIdx), "LightRepair");//false;
		if (GetCharacterPerkUsing(GetCharacter(chIdx),"LightRepair"))
		{
            if(GetHullPercent(GetCharacter(chIdx))<10.0 || GetSailPercent(GetCharacter(chIdx))<10.0)
			{
                BattleInterface.Commands.LightRepair.enable = true;
			}
		}
		BattleInterface.Commands.Turn180.enable			= GetCharacterPerkUsing(GetCharacter(chIdx), "Turn180");//false;
	}
}

ref procCheckEnableLocator()
{
	BI_intRetValue = true;

	string comName = GetEventData();
	aref arLoc = GetEventData();

	if(comName=="BI_SailTo")
	{
		if( CheckAttribute(&AISea,"Island") && CheckAttribute(arLoc,"name") )
		{
			BI_intRetValue = Island_isGotoEnableLocal(AISea.Island,arLoc.name);
		}
	}

	return &BI_intRetValue;
}

ref procCheckEnableShip()
{
	BI_intRetValue = true;

	string comName = GetEventData();
	int cn = GetEventData();

	ref rCommander;

	if(cn>=0)
	{
		switch(comName)
		{
		case "BI_InstantBoarding":
			BI_intRetValue = true;
		break;
		
		/*case "BI_Speak":
			BI_intRetValue = true;
		break;*/
		}
	}

	return &BI_intRetValue;
}

void BI_ProcessControlPress()
{
	string ControlName = GetEventData();
	if( sti(InterfaceStates.Launched) != 0 ) {return;}

float fSailState; // Dolphin -> ��� �����
	if(ControlName == "Ship_TurnLeft") PlaySound("ship\turn_left_"+rand(5)+".ogg");
	if(ControlName == "Ship_TurnRight") PlaySound("ship\turn_right_"+rand(5)+".ogg");
	// <-

	switch(ControlName)
	{
		case "hk_charge1":
		PlaySound("interface\_balls_"+rand(3)+".mp3");
		Ship_ChangeCharge(pchar, GOOD_BALLS);
		break;
	
		case "hk_charge2":
		PlaySound("interface\_grapes_"+rand(9)+".mp3");
		Ship_ChangeCharge(pchar, GOOD_GRAPES);
		break;
	
		case "hk_charge3":
		PlaySound("interface\_chain_"+rand(6)+".mp3");
		Ship_ChangeCharge(pchar, GOOD_KNIPPELS);
		break;
	
		case "hk_charge4":
		PlaySound("interface\_bombs_"+rand(2)+".mp3");
		Ship_ChangeCharge(pchar, GOOD_BOMBS);
		break;
		
		case "BICommandsActivate": 
			PlaySound("interface\ok.wav"); // boal ����� �����!
					break;

		// Dolphin -> �����, �����...
		case "Ship_SailUp":
			fSailState = Ship_GetSailState(pchar);
			if(fSailState != 1.0) 
			{
				switch(fSailState)
				{
					case 0.5: PlaySound("ship\full_sail_"+rand(4)+".ogg"); break;
					case 0.0: PlaySound("ship\half_sail_"+rand(3)+".ogg"); break;
				}
			}
		break;

		case "Ship_SailDown":
			fSailState = Ship_GetSailState(pchar);
			if(fSailState != 0.0) 
			{
				switch(fSailState)
				{
					case 1.0: PlaySound("ship\half_sail_"+rand(3)+".ogg"); break;
					case 0.5: PlaySound("ship\no_sail_"+rand(3)+".ogg"); break;
				}
			}
		break;
	}
}

ref procGetSRollSpeed()
{
	int chrIdx = GetEventData();
	BI_g_fRetVal = 0.0;
	if(chrIdx>=0) BI_g_fRetVal = GetRSRollSpeed(GetCharacter(chrIdx));
	return &BI_g_fRetVal;
}
// �������� ������� ������
float GetRSRollSpeed(ref chref)
{
	int iShip = sti(chref.ship.type);
	if( iShip<0 || iShip>=REAL_SHIPS_QUANTITY ) {return 0.0;}
	
	float fRollSpeed = 0.5 + 0.05 * makefloat( GetSummonSkillFromNameToOld(chref,SKILL_SAILING) ); //fix skill
	int crewQ = GetCrewQuantity(chref);
	//int crewMin = sti(RealShips[iShip].MinCrew);
	if (!CheckAttribute(&RealShips[iShip], "MaxCrew"))
	{
		Log_TestInfo("GetRSRollSpeed ��� MaxCrew � ������� ��� ID=" + chref.id);
		return 0.0;
	}
 	int crewMax = sti(RealShips[iShip].MaxCrew);
 	int crewOpt = sti(RealShips[iShip].OptCrew);//boal
 	if (crewMax < crewQ) crewQ  = crewMax; // boal
	//if(crewQ < crewMin) fRollSpeed *= makefloat(crewQ)/makefloat(2*crewMin);
	//fRollSpeed = fRollSpeed * (0.5 + makefloat(crewQ)/makefloat(2*crewMax)); // ���������� �������� ��������� �� �������
	//fRollSpeed = fRollSpeed * makefloat(crewQ)/makefloat(crewMax);
	// ���� �������� 
	float  fExp;
	
	if (crewOpt <= 0) crewOpt = 0; // fix ��� ������������ ������� �� ����
	
	fExp = 0.05 + stf(GetCrewExp(chref, "Sailors") * crewQ) / stf(crewOpt * GetCrewExpRate());
	if (fExp > 1) fExp = 1;
	fRollSpeed = fRollSpeed * fExp;
	// ������
	float  fMorale = stf(stf(GetCharacterCrewMorale(chref)) / MORALE_MAX);
	fRollSpeed = fRollSpeed * (0.7 + fMorale / 2.0);

	if (iArcadeSails != 1)
	{
		fRollSpeed = fRollSpeed / 2.5;
	}
	if(CheckOfficersPerk(chref, "SailsMan"))
	{
		fRollSpeed = fRollSpeed * 1.1; // 10%
	}
	return fRollSpeed;
}

ref BI_GetLandData()
{
	int iTmp;
	string attrName;
	aref arLoc, arIsl, arList;
	arLoc = GetEventData();

	BI_intNRetValue[0] = 0;
	BI_intNRetValue[1] = BI_RELATION_NEUTRAL;
	BI_intNRetValue[2] = -1;
	BI_intNRetValue[3] = -1;
	BI_intNRetValue[4] = -1;
	BI_intNRetValue[5] = -1;
	BI_intNRetValue[6] = 0;

	if( CheckAttribute(arLoc,"fort.model") )
	{
		BI_intNRetValue[0] = 1; // ��� ����
		int chrIdx = Fort_FindCharacter(AISea.Island,"reload",arLoc.name);
		if(chrIdx>=0)
		{
			switch( SeaAI_GetRelation(chrIdx,nMainCharacterIndex) )
			{
			case RELATION_FRIEND:	BI_intNRetValue[1] = BI_RELATION_FRIEND; break;
			case RELATION_NEUTRAL:	BI_intNRetValue[1] = BI_RELATION_NEUTRAL; break;
			case RELATION_ENEMY:	BI_intNRetValue[1] = BI_RELATION_ENEMY; break;
			}
			BI_intNRetValue[5] = chrIdx;
		}
	}
	else
	{
		if( CheckAttribute(arLoc,"istown") && arLoc.istown=="1" )
		{
			iTmp = FindLocation( arLoc.go );
			if( iTmp>=0 ) {
				iTmp = FindColony( Locations[iTmp].fastreload );
				if( iTmp>=0 ) {
					BI_intNRetValue[0] = 2; // ��� �����
					switch( GetNationRelation2MainCharacter(sti(Colonies[iTmp].nation)) )
					{
					case RELATION_FRIEND:	BI_intNRetValue[1] = BI_RELATION_FRIEND; break;
					case RELATION_NEUTRAL:	BI_intNRetValue[1] = BI_RELATION_NEUTRAL; break;
					case RELATION_ENEMY:	BI_intNRetValue[1] = BI_RELATION_ENEMY; break;
					}
					BI_intNRetValue[6] = sti(Colonies[iTmp].disease);
				}
			}
		}
		else
		{// �� ����, �� ����� - �����!
			BI_intNRetValue[0] = 3; // ��� �����
		}
	}
	/*if( CheckAttribute(arLoc,"tex") && CheckAttribute(arLoc,"pic") )
	{
		makearef( arIsl, Islands[FindIsland(AISea.Island)] );
		attrName = "InterfaceTextures." + arLoc.tex;
		if( CheckAttribute(arIsl,attrName) )
		{
			BI_intNRetValue[2] = AddTextureToList( &BattleInterface, arIsl.(attrName), sti(arIsl.(attrName).h)*2, sti(arIsl.(attrName).v) );
			BI_intNRetValue[3] = sti(arLoc.pic);
			BI_intNRetValue[4] = sti(arLoc.pic) + sti(arIsl.(attrName).h);
		}
	}*/

	int g_LocLngFileID = LanguageOpenFile("LocLables.txt");
	if( CheckAttribute(arLoc,"label") ) {
		arLoc.labelLoc = LanguageConvertString(g_LocLngFileID,arLoc.label);
		if( arLoc.labelLoc == "" ) {
			Trace("Warning! Language: string <"+arLoc.label+"> hav`t translation into file <LocLables.txt>");
		}
	}
	LanguageCloseFile(g_LocLngFileID);

	if( BI_intNRetValue[2]<0 || BI_intNRetValue[3]<0 )
	{
		BI_intNRetValue[2] = 0;//AddTextureToList( &BattleInterface, "battle_interface\cicons_locators.tga", 8, 1 );
		switch (BI_intNRetValue[0])
		{
			case 1: // ����
				BI_intNRetValue[3] = 62;
				BI_intNRetValue[4] = 46;
			break;
			case 2: // �����
				BI_intNRetValue[3] = 63;
				BI_intNRetValue[4] = 47;
            break;
            case 3: // �����
				BI_intNRetValue[3] = 31;
				BI_intNRetValue[4] = 15;
            break;
		}
	}

	return &BI_intNRetValue;
}

int GetTargChrIndex(int targNum, string locName)
{
	if(targNum==-1) {
		return Fort_FindCharacter(AISea.Island,"reload",locName);
	} else {
		return targNum;
	}
}

bool CheckSuccesfullBoard(ref rBoarderChr, ref rSieger)
{
	if (bBettaTestMode) return true;
	if (bCSMKillEmAll) return true; // --> CheatSurfMenu by Cheatsurfer
	if (LAi_IsDead(rSieger)) return false;  // fix
	// skill = 1 -> k = 0.5; skill = 10 -> k = 2.0
	float k = 0.333 + GetSummonSkillFromNameToOld(rBoarderChr, SKILL_SNEAK)*0.167;

	// skill = 1 -> limit = 0.45 -> 0.2^0.5 (20%);   skill = 10 -> limit = 0.81 -> 0.9^2 (90%)
	float topLimit = 0.41 + GetSummonSkillFromNameToOld(rBoarderChr, SKILL_GRAPPLING)*0.04;

	if( pow(rand(1000)/1000.0, k) < topLimit ) return true;
	return false;
}

// ����� ��� ���� 1.2.3
// ��������� ���� �� �����
void SetRandGeraldSail(ref chr, int nation)
{
	string ret = "";
	int    st = GetCharacterShipType(chr);
	ref    shref;
	
	// 1.2.3 ��������� �� ���� �������� � �������, �� ���� ��� ������ ����������
	if (st != SHIP_NOTUSED)
	{
		shref = GetRealShip(st); 
		switch (nation)
		{
		    case ENGLAND:
		        ret = "eng_" + (1 + rand(23));
		    break;
	
	        case FRANCE:
	            ret = "fra_" + (1 + rand(26));
	        break;
	
	        case SPAIN:
	            ret = "spa_" + (1 + rand(32));
	        break;
	
	        case HOLLAND:
	            ret = "hol_" + (1 + rand(20));
	        break;
	
	        case PIRATE:
	            ret = "pir_" + (1 + rand(27));
	        break;
		}
		shref.ShipSails.Gerald_Name = ret;
	}		
}

void SetSailsColor(ref chr, int col)
{
	int    st = GetCharacterShipType(chr);
	ref    shref;
	
	if (st != SHIP_NOTUSED)
	{
		shref = GetRealShip(st); 
		
		shref.SailsColorIdx   = col;
		shref.ShipSails.SailsColor = SailsColors[col].color;
	}		
}

// Warship 04.06.09 ��������, ����� �� �� ������ ������� ��������� ��������� ����
bool CanSetSailsGerald(ref _char)
{
	int shipClass = GetCharacterShipClass(_char); // ���� ������� ���, ������ 7 (�����)
	
	if(shipClass > 4) // �������� �� ����� ������� > 4
	{
		return false;
	}

	return true;
}


