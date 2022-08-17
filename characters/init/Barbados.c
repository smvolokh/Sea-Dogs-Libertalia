int CreateBarbadosCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// �������� ���������
	///////////////////////////////////////////////////////////////////////////////
	makeref(ch,Characters[n]);			//����������
	ch.id		= "Bridgetown_Mayor";
	ch.model	= "huber_11";
	ch.sex = "man";
	ch.name 	= "�������";
    ch.lastname = "���� �������";
	ch.City = "Bridgetown";
	ch.greeting = "mayor_2";
	ch.location = "Bridgetown_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	
	ch.Default	= "Bridgetown_townhall";
	ch.Default.group = "sit";
	ch.Default.locator = "sit1";
	
	ch.Dialog.Filename = "Common_Mayor.c";
	ch.nation = ENGLAND;
	ch.quest.type = "hovernor";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, BLADE_LONG);
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, BLADE_LONG); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.standUp = true; //�������� � �������� �� �����
	ch.MultiFighter = 2.5; // ������������
	ch.MultiShooter = 2.5;
	ch.SuperShooter  = true;
	LAi_SetImmortal(ch, true);
	LAi_SetHuberType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//��������
	ch.id		= "Bridgetown_Priest";
	ch.model	= "priest_3";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.location = "Bridgetown_church";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_church.c";
	ch.greeting = "padre_1";
	ch.nation = ENGLAND;
//	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ����������
	ch.id		= "Bridgetown_waitress";
	ch.model	= "women_12";
	ch.sex = "woman";
	ch.City = "Bridgetown";
	ch.location = "Bridgetown_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "waitress";
	ch.nation = ENGLAND;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//����������
	ch.id		= "Bridgetown_tavernkeeper";
	ch.model	= "Gaston";
	ch.greeting = "tonzag_1";
	ch.name 	= "������";
    ch.lastname = "��������";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.location = "Bridgetown_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = ENGLAND;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;


	makeref(ch,Characters[n]);			//��������
	ch.id		= "Bridgetown_trader";
	ch.model	= "trader_10";
	ch.greeting = "store_2";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.location = "Bridgetown_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = ENGLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//�������
	ch.id		= "Bridgetown_shipyarder";
	ch.model	= "shipowner_10";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.greeting = "shipyarder_2";
	ch.location = "Bridgetown_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = ENGLAND;
	ch.quest.shiping = "0";
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "topor_02");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "topor_02"); 
	SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
	ch.MultiFighter = 1.5; // ������������
	ch.MultiShooter = 1.5;
	ch.SuperShooter  = true;
	ch.standUp = true; //�������� � �������� �� �����
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.99);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
    n = n + 1;

	makeref(ch,Characters[n]);			//������
	ch.id		= "Bridgetown_usurer";
	ch.model	= "banker_10";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.Merchant.type = "jeweller"; 
	ch.location	= "Bridgetown_Bank";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Usurer_dialog.c";
	ch.nation = ENGLAND;
	ch.greeting = "usurer_2";
	ch.quest.shiping = "0";
	ch.UsurerDeposit = 9000; // *1000 �����
	ch.money = USURER_MIN_MONEY + rand(USURER_NORM);
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//��������� �����
	ch.id		= "Bridgetown_PortMan";
	ch.model	= "citiz_7";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.location	= "Bridgetown_PortOffice";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Portman.c";
	ch.nation = ENGLAND;
	LAi_SetHuberType(ch);
	ch.greeting = "portman_2";
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	n = n + 1;

	makeref(ch,Characters[n]);			//������� �������
	ch.id		= "Bridgetown_Hostess";
	ch.name		= "��������"
	ch.lastname = "";
	ch.model	= "maman_2";
	ch.model.animation = "woman_B";
	ch.sex = "woman";
	ch.City = "Bridgetown";
	ch.location	= "Bridgetown_SecBrRoom";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Common_Brothel.c";
	ch.greeting = "maman_1";
	ch.nation = ENGLAND;
	ch.questChurch = ""; //���� ��� �������������
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	n = n + 1;

    makeref(ch,Characters[n]);
	ch.name 	= "�������������";
	ch.lastname = "";
	ch.id		= "Bridgetown_Smuggler";
	ch.model    = "citiz_29";
	ch.sex      = "man";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.nation = PIRATE;
	GiveItem2Character(ch, BLADE_SABER);
	EquipCharacterbyItem(ch, BLADE_SABER);
	// ������� � ����������
	ch.Dialog.Filename = "Smuggler Agent_dialog.c";
	LAi_SetSitType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "smuggler";
	n = n + 1;
	
	makeref(ch,Characters[n]);			//���������� �����
	ch.id		= "Bridgetown_Lightman";
	ch.model	= "keeper_8";
	ch.model.animation = "man_B";
	ch.sex = "man";
	ch.City = "Bridgetown";
	ch.location = "Mayak2_Lighthouseroom";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Common_lighthouse.c";
	ch.greeting = "lighthouseman_1";
	ch.Merchant = true;
	ch.Merchant.type = "lightman";
	ch.money = TRADER_MIN_MONEY + rand(TRADER_NORM);
	ch.nation = ENGLAND;
	LAi_SetOwnerType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;
	
	return n;
}
