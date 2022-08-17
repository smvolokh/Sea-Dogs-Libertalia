// BOAL 21.01.17  Mods on_off mode
// ������� Libertalia!

#define VERSION_NUMBER1       "Libertalia " // �������: ��� + ��� modding base #1
#define VERSION_NUMBER2       "ver. 0.1. (27.12.2021). Pre-alpha release. work in progress. 
BlackSailsTeam."
#define VERSION_NUMBER3       "�������: ��� + Absolum + ��� + CSP + ��� + other modding base"

#define VERSION_NUM      99940  // ������� �����
#define VERSION_NUM_PRE  99940  // ��������� ����������

#define VERSION_WWW     ""

// Show special message for test game statment
#define MOD_BETTATESTMODE			"On"  // On -DEV version; Test - TST ver; Off - relize

// ���������� ��������� ����������
String sGlobalTemp;
String sTotalTemp;
string sNrvParol, sRvdParol;

// ��� ���������� ������������� ����������
int iGlobalTemp, iTotalTemp;

// quest.c bool    bQuestCheckProcessFreeze = false; // ��������� �������

// ������ ���� ������� �� ���� (������� � ����� ����)
bool    bDisableLandEncounters = false;
// ������ ���� �2
bool    bDisableCharacterMenu  = false;
// ���� - ����� �����
bool    bPlayerIsCheater =  false;  // �� �����������, ������
// ����� ����� �����
bool    bBettaTestMode = false;
// ���������� quest_reaction Log
bool    bQuestLogShow  = false;
// ���������� ���� �� �������
bool    bExpLogShow    = false;
// ������ ������� �������� - �������
bool    TestRansackCaptain = false;
// ����� ���������
bool    bLocatorShow  = false;
// �� �����, ��� ����
bool    bNoEatNoRats  = false;
// ����� ��� �� �����: ����� �� ���������� �� �������, ����� �� ��������� ����� � ���, ������� �� ����� ����� ����, ����� ������ ����� ���� (���� � ��������)
bool    bWorldAlivePause      = true;
// ����� �����
bool bPauseContrabandMetro = false;
// ��� ��� ���
bool bPGGLogShow = false;
// ���� ��������� ��������
bool bMonstersGen = false;
// ���� ��������� ���������� �����������
bool bLandEncountersGen = true;
// ���� � �������
bool bMainCharacterInBox = false;
// ���� � ����
bool bMainCharacterInFire = false;
// ������� ����
bool bMainMenu = false;
//�������� ������ ����
bool startGameWeather = false;
// ����������� ��������� ���� � �������� � ���� � � ���������� �� ����
bool bDrawBars = true;
// ����������� ���������� ������ � ����; ��� ���������� ������ ������������� � false !!!
bool bSteamAchievements	= false;
// �������������� �������, ��� ���������� ������ ������ � true
bool bAddonContent = false;
// bool bBalloonAction = false;

// --> ��������� ���������� ���������� �� ������ ������
bool bGlobalVar1 = false;
bool bGlobalVar2 = false;
bool bGlobalVar3 = false;
bool bGlobalVar4 = false;
bool bGlobalVar5 = false;

int iGlobalVar1 = 0;
int iGlobalVar2 = 0;
// <-- ��������� ���������� ���������� �� ������ ������

//int iScriptVersion = 15650;
int iScriptVersion = 57853; 
//int iScriptVersion = 54128;

// ����� � ������
bool 	bRains						= true;
// ��������� �������������� ��� �����
bool    bRechargePistolOnLine  		= true;  
// ��������� ������������
bool    bNewCodeOn                	= false;  // ��������� ��������
// ��� ������, ���� � ������ ����
bool    bHardcoreGame             	= false;
// ������� ����-����
//bool    bPayForSaveLoad           = true;
// ���������� � ���� � ������ ������
bool	bSeaBattleSave				= true;
// ������ ������
bool 	bPartitionSet 				= true;

///////////////////////////////////////////////////
//          complexity
//  Next Level rate
int MOD_EXP_RATE           = 10; // ��� ����... + (���������)
//  complexity of fantom skill
// 1- easy; 2; 3; 4;  5-medium; 6; 7; 8; 9;  10 - hard (please, do not set more 10 or less 1 it mays crash game
// ��� ��� - ������ ��������� 2 - ������,4,6,8 - �������, 10 - �������
int MOD_SKILL_ENEMY_RATE   = 10; 


// Killed body clear
#define MOD_DEAD_CLEAR           "On"
#define MOD_DEAD_CLEAR_TIME      100 // in sec.

#define CHAR_ITEMS_WEIGHT        70

#define InstantRepairRATE        65.0

// ��������� �� ������� ��� ���������
#define DistanceToShipTalk        950.0

//#define ShipyardMoneyInit        190000.0
//#define ShipyardMoneyMax         900000.0
//#define ShipyardMoneyAdd         2000

// boal 23.01.2004 ��������� 091004 ����� ������ ������ -->
int    startHeroType = 1;
int    MaxHeroQty		= 1;  // ������������ ���-�� ��
int    MaxPGGQty		= 10; // ������������ ���-�� ��� (+2 ���������� ��)
//int    heroFaceId    = 1;
// boal 23.01.2004 <--

int ItemDeadStartCount = 0; // ����������� � itemInit ����� ��� ��������� ������ (�����������)

#define STARTGAME_YEAR       1661
#define STARTGAME_MONTH      4
#define STARTGAME_DAY        23


// �������� ����������
#define FUNY_SHIP_NAME    "����������"
#define KEY_ENG_LINE	  "uFRklw7Ghww19ywWQ"

int TimeScaleCounter = 0;
// ������ ��������
bool chrDisableReloadToLocation = false;
// ��� ������� ����� � �� �����
bool bIsFortAtIsland = false;
float fFort_x, fFort_z;
int iFortNation, iFortCommander;
//������ � ����� ��������� ��� ��������� item
int ItemsForLocators_start, ItemsForLocators_end, Totems_start, Totems_end;

//==> �������� ��������� ������ �� ������� ������. ���� �� ����, �� ��������� �������������� ������ �
//==> �������� ������� ��� ����, ���� ��� - �����. 74632 - ������� �����. 95181, 74553
//GetEngineVersion();  ����� ��������!=)
//bAddonContent = GetDLCenabled();
/////////////////////////////