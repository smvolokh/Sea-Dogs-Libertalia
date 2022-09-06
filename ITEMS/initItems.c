int InitItems()
{
	InitRandItems();
	ref itm;
	int n;

	for(n=0; n<ITEMS_QUANTITY; n++)
	{
		makeref(itm,Items[n]);
		itm.id = "item"+(n+1);
		itm.describe = "";
		itm.index = n;
		itm.model = "";
		itm.shown = false;
		itm.startLocation = "";
		itm.startLocator = "";
		itm.useLocation = "";
		itm.useLocator = "";
		itm.describe = "";
        itm.Weight = 0.0; // boal
        itm.uniq  = false;
        itm.price = 1;
        itm.ItemType = "VARIETY";
	}
	n = 0;


	// �����
	// �����
    	makeref(itm,Items[n]);
	itm.id = "BackPack1";
	itm.groupID = BACKPACK_ITEM_TYPE;
	itm.name = "itmname_BackPack1";
	itm.describe = "itmdescr_BackPack1";
	itm.folder = "items";
	itm.model = "1";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_38";
	itm.price = 5000;
	itm.Weight = 0.5;
	itm.BackPackWeight = 50;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "WEAPON";
	n++;

	// ������
    	makeref(itm,Items[n]);
	itm.id = "BackPack2";
	itm.groupID = BACKPACK_ITEM_TYPE;
	itm.name = "itmname_BackPack2";
	itm.describe = "itmdescr_BackPack2";
	itm.folder = "items";
	itm.model = "1";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_38";
	itm.price = 10000;
	itm.Weight = 2.0;
	itm.BackPackWeight = 100;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "WEAPON";
	n++;

	// �����
    	makeref(itm,Items[n]);
	itm.id = "BackPack3";
	itm.groupID = BACKPACK_ITEM_TYPE;
	itm.name = "itmname_BackPack3";
	itm.describe = "itmdescr_BackPack3";
	itm.folder = "items";
	itm.model = "1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_38";
	itm.price = 15000;
	itm.Weight = 3.5;
	itm.BackPackWeight = 150;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "WEAPON";
	n++;


	// �����
    	makeref(itm,Items[n]);
	itm.id = "BackPack4";
	itm.groupID = BACKPACK_ITEM_TYPE;
	itm.name = "itmname_BackPack4";
	itm.describe = "itmdescr_BackPack4";
	itm.folder = "items";
	itm.model = "1";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_38";
	itm.price = 20000;
	itm.Weight = 5.0;
	itm.BackPackWeight = 200;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "WEAPON";
	n++;

	// � ������ ���� ��� ��� ���������� ������
//==================PATENTS
    makeref(itm,Items[n]);
	itm.id = "patent_eng";
    itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "itmname_patent_england";
	itm.describe = "itmdescr_patent_england";
	itm.model = "";
    itm.quest = "eng_flag_rise";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_32";
	itm.price = 1000000;
	itm.Nation = ENGLAND; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

    makeref(itm,Items[n]);
	itm.id = "patent_fra";
    itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "itmname_patent_france";
	itm.describe = "itmdescr_patent_france";
	itm.model = "";
    itm.quest = "fra_flag_rise";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_32";
	itm.price = 1000000;
	itm.Nation = FRANCE; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

    makeref(itm,Items[n]);
	itm.id = "patent_spa";
    itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "itmname_patent_spain";
	itm.describe = "itmdescr_patent_spain";
	itm.model = "";
    itm.quest = "spa_flag_rise";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_32";
	itm.price = 1000000;
	itm.Nation = SPAIN; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

    makeref(itm,Items[n]);
	itm.id = "patent_hol";
    itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "itmname_patent_holland";
	itm.describe = "itmdescr_patent_holland";
	itm.model = "";
    itm.quest = "hol_flag_rise";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_32";
	itm.price = 1000000;
	itm.Nation = HOLLAND; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					�������� ������
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ������
	n = InitStdBlade(n,  "unarmed", "ITEMS_40",  12,   TGT_QUEST, 		B_POOR, "FencingL",17, 1.00, 1.00, 0,  0, 0, 		  1); // ������ Jason: ������ ������ � ������ ���� - ����� � ���������� ���������� ��� ������
	
// ������ � �����
//int InitStdBlade(������, ������, ��������, ��������, ������� ������, ��������, ��� ������, ����� � ������, �����, �����, ������������, ���-�� ������������, ������������� ����, ���� ���� �� ������������);
	n = InitStdBlade(n, "knife_01", "ITEMS_16",  7,    TGT_QUEST, 		B_POOR, "FencingL", 9, 0.50, 1.00, 0,  0, 0, 	   1000); // ����
		n = InitStdBlade(n, "blade48", "ITEMS_43", 14,    TGT_QUEST,  B_ORDINARY, "FencingL", 14, 0.95, 1.00, 0, 0, 0, 		  28000); // ���������� ������
	n = InitStdBlade(n, "slave_01", "ITEMS_51",  4,   TGT_YANKEE, 		B_POOR, "FencingL", 0, 0.70, 1.00, 0,  0, 0, 		200); // ������ 
	n = InitStdBlade(n, "blade_03", "ITEMS_51",  6, TGT_MARGINAL,   B_POOR, "FencingL", 0, 1.05, 1.00, 1, 10, 1, 		  0); // ��������
	n = InitStdBlade(n, "blade_27", "ITEMS_51",  12,    TGT_QUEST,       B_EXCELLENT, "FencingL", 2, 1.05, 1.00, 1, 15, 1, 		  0); // �����������
	n = InitStdBlade(n, "blade_01", "ITEMS_51",  5,   TGT_NATIVE,   B_POOR, "FencingL", 0, 0.90, 1.05, 1, 10, 1, 		  0); // ����-��
	n = InitStdBlade(n, "blade_25", "ITEMS_51", 16,    TGT_QUEST,  B_EXCELLENT, "FencingL", 0, 1.05, 1.10, 1, 15, 1, 		  0); // �������
	n = InitStdBlade(n, "blade_26", "ITEMS_51", 15,    TGT_QUEST,  B_EXCELLENT, "FencingL", 1, 1.15, 1.00, 1, 15, 1, 		  0); // �������
	n = InitStdBlade(n, "blade_08", "ITEMS_51",  8,  TGT_SOLDIER,   B_ORDINARY, "FencingL", 0, 1.10, 1.10, 1, 10, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_09", "ITEMS_51",  7,  TGT_SOLDIER,   B_ORDINARY, "FencingL", 1, 0.95, 1.00, 1, 10, 1, 		  0); // ���������
	n = InitStdBlade(n, "blade_15", "ITEMS_51",  10,  TGT_OFFICER,       B_GOOD, "FencingL", 0, 0.90, 1.05, 1, 15, 1, 		  0); // ��������
	n = InitStdBlade(n, "blade_16", "ITEMS_51",  9,  TGT_OFFICER,       B_GOOD, "FencingL", 1, 0.95, 1.00, 1, 15, 1, 		  0); // ����������
	n = InitStdBlade(n, "blade_18", "ITEMS_51", 13,  TGT_OFFICER,  B_EXCELLENT, "FencingL", 3, 1.05, 1.05, 1, 15, 1, 		  0); // ������������	
	n = InitStdBlade(n, "blade_22", "ITEMS_51",  11,  TGT_PERSIAN,       B_GOOD, "FencingL", 0, 1.00, 1.10, 1, 10, 1, 		  0); // ���� �������
	n = InitStdBlade(n, "blade42", "ITEMS_43", 15,    TGT_QUEST,  B_ORDINARY, "FencingL", 14, 0.95, 1.10, 0, 0, 0, 		  40000); // ������ ������
	n = InitStdBlade(n, "blade46", "ITEMS_43", 10,  TGT_QUEST,  B_POOR, "FencingL", 13, 1.05, 1.10, 0, 0, 0, 		  30000); // ������ ���
	n = InitStdBlade(n, "blade37", "ITEMS_54", 13,    TGT_QUEST,  B_ORDINARY, "FencingL", 1, 0.85, 1.15, 0, 0, 0, 		  41000); // ������ �������
	n = InitStdBlade(n, "blade39", "ITEMS_54", 15,    TGT_QUEST,  B_POOR, "FencingL", 1, 1.00, 1.05, 0, 0, 0, 		  32000); // ������� ������
	n = InitStdBlade(n, "newblade11", "ITEMS_54",  7,    TGT_MARGINAL, 	B_POOR, "FencingL", 18, 0.45, 1.00, 0,  0, 0, 500); // ������
	n = InitStdBlade(n, "newblade13", "ITEMS_11",  1,    TGT_OFFICER,       B_GOOD, "FencingL", 2, 1.05, 1.00, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "newblade18", "ITEMS_15",  1,    TGT_QUEST,  B_EXCELLENT, "FencingL", 18, 0.60, 1.00, 1,  15, 1, 	   0); // �����
	n = InitStdBlade(n, "newblade20", "ITEMS_15", 14,  TGT_OFFICER,  B_EXCELLENT, "FencingL", 2, 1.00, 1.00, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_17", "ITEMS_51", 14,  TGT_OFFICER,  B_EXCELLENT, "FencingL", 2, 1.00, 1.00, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "newblade8", "ITEMS_15",  4,  TGT_SOLDIER,   B_ORDINARY, "FencingL", 0, 1.15, 1.00, 1, 10, 1, 		  0); // ���������
	n = InitStdBlade(n, "newblade2", "ITEMS_16",  8, TGT_MARGINAL,   B_POOR, "FencingL", 0, 1.10, 1.10, 1, 10, 1, 		  0); // ������������ �����
	n = InitStdBlade(n, "q_blade_18", "ITEMS_16", 14,  TGT_QUEST,  B_EXCELLENT, "FencingL", 13, 1.20, 1.00, 0, 0, 0, 	  70000); // �����
	n = InitStdBlade(n, "q_blade_16", "ITEMS_15",  13,  TGT_QUEST,       B_EXCELLENT, "FencingL", 12, 1.00, 1.00, 0, 0, 0, 		  65000); // ������

// ����� � ������
//int InitStdBlade(������, ������, ��������, ��������, ������� ������, ��������, ��� ������, ����� � ������, �����, �����, ������������, ���-�� ������������, ������������� ����, ���� ���� �� ������������);
	n = InitStdBlade(n, "slave_02", "ITEMS_52", 1,   TGT_YANKEE,       B_POOR, "FencingS", 1, 0.60, 1.20, 1, 10, 1, 		  0); // ������ 
	n = InitStdBlade(n, "blade_02", "ITEMS_52", 2,   TGT_NATIVE,   B_ORDINARY, "FencingS", 1, 1.05, 0.95, 1, 10, 1, 		  0); // ����������
	n = InitStdBlade(n, "blade_04", "ITEMS_52",  6, TGT_MARGINAL,       B_ORDINARY, "FencingS", 1, 1.00, 1.00, 1, 15, 1, 		  0); // ����������
	n = InitStdBlade(n, "blade_05", "ITEMS_52", 3, TGT_MARGINAL,   B_ORDINARY, "FencingS", 2, 1.00, 1.05, 1, 10, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_10", "ITEMS_52",  7,  TGT_SOLDIER,      B_ORDINARY, "FencingS", 2, 0.90, 1.10, 1, 15, 1, 		  0); // ����
	n = InitStdBlade(n, "blade_11", "ITEMS_52",  5,  TGT_SOLDIER,   B_ORDINARY, "FencingS", 3, 0.85, 1.10, 1, 10, 1, 		  0); // ���������� �����
	n = InitStdBlade(n, "blade_12", "ITEMS_52",  4,  TGT_SOLDIER,   B_ORDINARY, "FencingS", 4, 0.90, 1.10, 1, 10, 1, 		  0); // ���������
	n = InitStdBlade(n, "blade_19", "ITEMS_52",  11,  TGT_OFFICER,  B_EXCELLENT, "FencingS", 5, 1.00, 1.15, 1, 15, 1,  	      0); // ������� �����
	n = InitStdBlade(n, "blade_20", "ITEMS_52",  10,  TGT_OFFICER,  B_EXCELLENT, "FencingS", 4, 0.90, 1.15, 1, 15, 1, 		  0); // �������
	n = InitStdBlade(n, "blade_23", "ITEMS_52",  9,  TGT_PERSIAN,       B_EXCELLENT, "FencingS", 1, 1.05, 1.10, 1, 10, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_28", "ITEMS_52", 13,    TGT_QUEST,  B_EXCELLENT, "FencingS", 3, 1.00, 1.10, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_29", "ITEMS_52",  12,    TGT_QUEST,  B_EXCELLENT, "FencingS", 4, 1.05, 1.10, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_30", "ITEMS_52",  8,    TGT_QUEST,      B_EXCELLENT, "FencingS", 5, 0.95, 1.15, 1, 15, 1, 		  0); // ���������� �������
	n = InitStdBlade(n, "blade38", "ITEMS_54", 14,    TGT_QUEST,  B_GOOD, "FencingS", 2, 1.05, 1.10, 0, 0, 0, 		  50000); // ������ ��������� ��������
	n = InitStdBlade(n, "blade41", "ITEMS_43", 13,    TGT_QUEST,  B_GOOD, "FencingS", 14, 0.90, 1.05, 0, 0, 0, 		  48000); // ������ ������ ������
	n = InitStdBlade(n, "blade49", "ITEMS_43", 16,    TGT_QUEST,  B_GOOD, "FencingS", 14, 0.75, 1.10, 0, 0, 0, 		  52000); // ����� ���������� 
	n = InitStdBlade(n, "blade50", "ITEMS_44", 1,    TGT_MARGINAL,  B_ORDINARY, "FencingS", 14, 0.90, 1.20, 1, 10, 1, 		  0); // �������� 
	n = InitStdBlade(n, "blade51", "ITEMS_44", 2,    TGT_QUEST,  B_GOOD, "FencingS", 14, 1.05, 1.10, 0, 0, 0, 		  51000); // ������ ������ 
	n = InitStdBlade(n, "blade52", "ITEMS_44", 3,    TGT_QUEST,  B_GOOD, "FencingS", 14, 1.05, 1.00, 0, 0, 0, 		  49000); // ������ ����������� 
	n = InitStdBlade(n, "newblade1", "ITEMS_16",  9,  TGT_MARGINAL,   B_POOR, "FencingS", 3, 0.90, 1.05, 1, 10, 1, 		  0); // ����������� �����
	n = InitStdBlade(n, "newblade3", "ITEMS_16", 6, TGT_MARGINAL,   B_POOR, "FencingS", 2, 1.00, 1.05, 1, 20, 1, 		  0); // ������
	n = InitStdBlade(n, "newblade4", "ITEMS_16",  5,  TGT_SOLDIER,   B_POOR, "FencingS", 4, 0.95, 1.10, 1, 10, 1, 		  0); // �������� �����
	n = InitStdBlade(n, "newblade6", "ITEMS_15", 11,  TGT_MARGINAL,  B_ORDINARY, "FencingS", 2, 0.90, 1.10, 1, 15, 1, 		  0); // ���������
		n = InitStdBlade(n, "newblade10", "ITEMS_44",  13,  TGT_SOLDIER,   B_ORDINARY, "FencingS", 4, 0.95, 1.05, 1, 10, 1, 		  0); // ������������� �����
	n = InitStdBlade(n, "newblade16", "ITEMS_15",  8,    TGT_SOLDIER,      B_EXCELLENT, "FencingS", 5, 0.85, 1.15, 1, 15, 1, 		  0); // ���������
	n = InitStdBlade(n, "newblade17", "ITEMS_16",  13,  TGT_OFFICER,  B_EXCELLENT, "FencingS", 4, 0.90, 1.15, 1, 15, 1, 		  0); // ��������
		n = InitStdBlade(n, "newblade23", "ITEMS_54",  6,  TGT_MARGINAL,  B_POOR, "FencingS", 4, 0.85, 1.05, 1, 15, 1, 		  0); // �����
		n = InitStdBlade(n, "newblade24", "ITEMS_44",  15,  TGT_OFFICER,  B_GOOD, "FencingS", 4, 1.00, 1.10, 1, 15, 1, 		  0); // ����������� �����
		n = InitStdBlade(n, "newblade25", "ITEMS_54",  16,  TGT_OFFICER,  B_GOOD, "FencingS", 4, 1.00, 1.15, 1, 15, 1, 		  0); // ��������� �����
		n = InitStdBlade(n, "newblade26", "ITEMS_8",  1,  TGT_MARGINAL,  B_GOOD, "FencingS", 4, 0.85, 1.20, 1, 15, 1, 		  0); // ������
		n = InitStdBlade(n, "newblade27", "ITEMS_54",  9,  TGT_SOLDIER,  B_ORDINARY, "FencingS", 4, 0.90, 1.10, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "newblade28", "ITEMS_6",  1,  TGT_MARGINAL,  B_GOOD, "FencingS", 5, 1.00, 1.20, 1, 15, 1,  	      0); // ������
	n = InitStdBlade(n, "q_blade_10", "ITEMS_11",  2,  TGT_QUEST,       B_EXCELLENT, "FencingS", 10, 1.00, 1.20, 0, 0, 0, 		  65000); // ������
	n = InitStdBlade(n, "q_blade_19", "ITEMS_11",  16,  TGT_QUEST,  B_EXCELLENT, "FencingS", 14, 1.00, 1.20, 0, 0, 0, 	  70000); // �����	

// ������ � ������+������� ������
//int InitStdBlade(������, ������, ��������, ��������, ������� ������, ��������, ��� ������, ����� � ������, �����, �����, ������������, ���-�� ������������, ������������� ����, ���� ���� �� ������������);
	n = InitStdBlade(n, "topor_01", "ITEMS_40", 3,   TGT_NATIVE,       B_GOOD, "FencingH", 3, 1.00, 1.10, 1, 15, 1, 		  0); // ����������
	n = InitStdBlade(n, "newblade29", "ITEMS_6", 3,   TGT_QUEST,       B_EXCELLENT, "FencingH", 3, 1.00, 1.10, 0, 0, 0, 		  15000); // ���������
	n = InitStdBlade(n, "topor_02", "ITEMS_52", 16, TGT_MARGINAL,   B_ORDINARY, "FencingH", 5, 0.80, 1.15, 1, 10, 1, 		  0); // �������
	n = InitStdBlade(n, "topor_03", "ITEMS_52", 15, TGT_MARGINAL,   B_ORDINARY, "FencingH", 6, 0.85, 1.15, 1, 10, 1, 		  0); // ��������
	n = InitStdBlade(n, "topor_04", "ITEMS_40",  6,    TGT_QUEST,       B_GOOD, "FencingH", 8, 0.90, 1.15, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "topor_05", "ITEMS_52", 14,   TGT_YANKEE,       B_POOR, "FencingH", 2, 0.70, 1.10, 1, 10, 1, 		  0); // ��������
	n = InitStdBlade(n, "topor_06", "ITEMS_40", 15,    TGT_QUEST,      B_EXCELLENT, "FencingH", 18, 0.80, 1.15, 0, 0, 0, 		6000); // ����������
	n = InitStdBlade(n, "topor_07", "ITEMS_44", 7, TGT_MARGINAL,   B_POOR, "FencingH", 6, 0.75, 1.15, 1, 10, 1, 0); // ��������
	n = InitStdBlade(n, "topor_08", "ITEMS_44",  8,    TGT_QUEST,       B_GOOD, "FencingH", 15, 0.80, 1.15, 0, 0, 0, 		  45000); // �������� ������
	n = InitStdBlade(n, "topor_09", "ITEMS_44",  9,    TGT_QUEST,       B_GOOD, "FencingH", 15, 0.65, 1.15, 0, 0, 0, 		  53000); // ����������
	n = InitStdBlade(n, "topor_010", "ITEMS_44",  10,    TGT_QUEST,       B_EXCELLENT, "FencingH", 15, 0.90, 1.15, 0, 0, 0, 		  63000); // ������ ������� 
	n = InitStdBlade(n, "topor_011", "ITEMS_44",  11,    TGT_QUEST,  B_EXCELLENT, "FencingH", 15, 0.95, 0.90, 0, 0, 0, 	  59000); //  ����� �������
	n = InitStdBlade(n, "topor_012", "ITEMS_44", 6, TGT_MARGINAL,   B_ORDINARY, "FencingH", 5, 0.70, 1.15, 1, 10, 1, 0); // ������� �����
	n = InitStdBlade(n, "topor_013", "ITEMS_11", 4, TGT_MARGINAL,   B_ORDINARY, "FencingH", 5, 0.70, 1.15, 1, 10, 1, 0); // ������
	n = InitStdBlade(n, "topor_014", "ITEMS_44", 16, TGT_MARGINAL,   B_ORDINARY, "FencingH", 6, 0.75, 1.15, 1, 10, 1, 0); // ���������� �����
	n = InitStdBlade(n, "topor_015", "ITEMS_49",  4, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.75, 1.00, 1,  10, 1, 		   0); // ����� ��� ������ ����
	n = InitStdBlade(n, "topor_016", "ITEMS_49",  2, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.85, 1.10, 1,  10, 1, 		   0); // �����
	n = InitStdBlade(n, "topor_017", "ITEMS_49",  1, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.85, 1.05, 1,  10, 1, 	   0); // �����
	n = InitStdBlade(n, "topor_018", "ITEMS_49",  4, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.85, 1.10, 1,  10, 1, 		   0); // �����
	n = InitStdBlade(n, "topor_019", "ITEMS_49",  3, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.85, 1.05, 1,  10, 1, 	   0); // ������
	n = InitStdBlade(n, "topor_020", "ITEMS_11",  7, TGT_YANKEE,         B_POOR, "FencingH", 0, 0.90, 1.00, 1,  10, 1, 	   0); // ���
	n = InitStdBlade(n, "topor_021", "ITEMS_54",  10,    TGT_QUEST,    B_EXCELLENT, "FencingH", 8, 0.70, 1.15, 1, 15, 0, 		  70000); // �����
	
// ������ � ����
//int InitStdBlade(������, ������, ��������, ��������, ������� ������, ��������, ��� ������, ����� � ������, �����, �����, ������������, ���-�� ������������, ������������� ����, ���� ���� �� ������������);
	n = InitStdBlade(n, "blade_06", "ITEMS_40",  4, TGT_MARGINAL,       B_EXCELLENT, "FencingH", 3, 1.00, 1.00, 1, 15, 1, 		  0); // ��������
	n = InitStdBlade(n, "blade_07", "ITEMS_40", 1, TGT_MARGINAL,   B_POOR, "FencingH", 4, 1.00, 1.00, 1, 10, 1, 		  0); // �����������
	n = InitStdBlade(n, "blade_13", "ITEMS_40",  5,  TGT_SOLDIER,       B_GOOD, "FencingH", 5, 0.95, 1.05, 1, 15, 1, 		  0); // ���������� �����
	n = InitStdBlade(n, "blade_14", "ITEMS_40", 2,  TGT_SOLDIER,   B_ORDINARY, "FencingH", 6, 1.05, 1.00, 1, 10, 1, 		  0); // ���������� �����
	n = InitStdBlade(n, "blade_21", "ITEMS_40",  7,  TGT_OFFICER,  B_EXCELLENT, "FencingH", 6, 0.95, 1.00, 1, 15, 1, 		  0); // �������
	n = InitStdBlade(n, "blade_24", "ITEMS_40",  8,  TGT_PERSIAN,  B_EXCELLENT, "FencingH", 2, 0.90, 1.15, 1, 10, 1, 		  0); // ������
	n = InitStdBlade(n, "blade_31", "ITEMS_40",  10,    TGT_QUEST,  B_EXCELLENT, "FencingH", 6, 1.05, 1.05, 1, 15, 1, 		  0); // ������
	n = InitStdBlade(n, "blade40", "ITEMS_43", 12,    TGT_QUEST,  B_GOOD, "FencingH", 14, 0.90, 1.10, 0, 0, 0, 		  10500); // ���������
	n = InitStdBlade(n, "blade43", "ITEMS_43", 6,    TGT_QUEST,  B_POOR, "FencingH", 13, 1.05, 1.05, 0, 0, 0, 		  31000); // ������������ �����
	n = InitStdBlade(n, "blade44", "ITEMS_43", 7,    TGT_QUEST,  B_ORDINARY, "FencingH", 14, 0.90, 1.00, 0, 0, 0, 		  44000); // ��������� ������
	n = InitStdBlade(n, "newblade19", "ITEMS_15", 6, TGT_SOLDIER,   B_ORDINARY, "FencingH", 4, 1.15, 1.00, 1, 10, 1, 	0); // �����
	n = InitStdBlade(n, "blade45", "ITEMS_43", 9,  TGT_QUEST,  B_POOR, "FencingH", 13, 0.90, 1.00, 0, 0, 0, 		  25000); // ������ ���
	n = InitStdBlade(n, "blade47", "ITEMS_43", 11,  TGT_QUEST,  B_ORDINARY, "FencingH", 13, 0.90, 1.05, 0, 0, 0, 		  39000); // ������ ������ ��������
	n = InitStdBlade(n, "blade53", "ITEMS_44",  4,    TGT_QUEST,  B_EXCELLENT, "FencingH", 15, 0.90, 1.20, 0, 0, 0, 		  60000); //  ���� ������ 
	n = InitStdBlade(n, "blade300", "ITEMS_54",  5,    TGT_QUEST,  B_EXCELLENT, "FencingH", 15, 0.95, 1.15, 0, 0, 0, 	  72000); //  ��� ��������
	n = InitStdBlade(n, "blade_32", "ITEMS_40",  9,    TGT_QUEST,  B_EXCELLENT, "FencingH", 7, 1.00, 1.10, 0, 0, 0, 		  60000); // �����
	n = InitStdBlade(n, "blade_33", "ITEMS_11",  8,    TGT_QUEST,  B_EXCELLENT, "FencingH",16, 1.00, 1.10, 0, 0, 0, 		  70000); // ��� ������
	n = InitStdBlade(n, "blade_36", "ITEMS_40",  16,    TGT_QUEST, B_EXCELLENT, "FencingH", 7, 1.00, 1.00, 0, 0, 0, 		  50000); // ����������� ���
	n = InitStdBlade(n, "blade301", "ITEMS_44",  5,    TGT_QUEST,  B_EXCELLENT, "FencingH", 15, 0.90, 1.10, 0, 0, 0, 	  80000); //  ������ �������
	n = InitStdBlade(n, "newblade5", "ITEMS_11",  6,    TGT_MARGINAL, B_ORDINARY, "FencingH", 0, 0.95, 1.15, 1, 10, 1, 		  0); // ��������
	n = InitStdBlade(n, "newblade9", "ITEMS_15",  9,  TGT_SOLDIER,    B_ORDINARY, "FencingH", 5, 0.95, 1.05, 1, 15, 1, 		  0); // ���������� �����
	n = InitStdBlade(n, "newblade12", "ITEMS_11",  3, TGT_OFFICER,       B_GOOD, "FencingH", 3, 0.95, 1.00, 1, 15, 1, 		  0); // �������
	n = InitStdBlade(n, "newblade14", "ITEMS_54", 12,  TGT_OFFICER,   B_GOOD, "FencingH", 6, 0.95, 1.00, 1, 10, 1, 		  0); // ��������
	n = InitStdBlade(n, "newblade15", "ITEMS_15", 12,  TGT_OFFICER,   B_GOOD, "FencingH", 6, 0.90, 1.00, 1, 10, 1, 		  0); // �������
	n = InitStdBlade(n, "newblade21", "ITEMS_11", 5,  TGT_OFFICER,   B_EXCELLENT, "FencingH", 6, 1.05, 1.00, 1, 10, 1, 		  0); // ���������� ���
	n = InitStdBlade(n, "newblade22", "ITEMS_54", 8, TGT_QUEST,    B_EXCELLENT, "FencingH", 2, 0.85, 1.00, 1, 15, 1, 0); // ������
	n = InitStdBlade(n, "newblade7", "ITEMS_15", 7,  TGT_MARGINAL,  B_ORDINARY, "FencingH", 2, 0.75, 1.00, 1, 15, 1, 		  0); // �����������
	n = InitStdBlade(n, "q_blade_13", "ITEMS_15",  5,  TGT_QUEST,  B_EXCELLENT, "FencingH", 11, 0.90, 1.05, 0, 0, 0, 		  65000); // ��������
	n = InitStdBlade(n, "q_blade_21", "ITEMS_15",  10,  TGT_QUEST,  B_EXCELLENT, "FencingH", 15, 1.00, 1.00, 0, 0, 0, 	  70000); // �������	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//										������������� ������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// ������� ���������
	//n = InitStdGun(������, �������������, ������, ��������, ��������, ��������, ���.�������, ����, ���. �����������, ����.�����������, ���, ���-�� �������, ��������);	
	n = InitStdGun(n, "pistol_01", 		    "pistol_01", 	"ITEMS_15", 	15,    0.1, 	1,  	1000, 	20.0, 	100.0, 	3.0, 	1, 	     B_POOR); // �������
	n = InitStdGun(n, "pistol1", 		    "pistol1", 	"ITEMS_37", 	12,    0.1, 	1,  	2000, 	40.0, 	200.0, 	4.0, 	1, 	     B_ORDINARY); // �������� ��������
	n = InitStdGun(n, "pistol_02", 		    "pistol_02", 	"ITEMS_15", 	16,    0.1, 	1,  	1500, 	30.0, 	150.0, 	5.0, 	1, 	     B_ORDINARY); // ������������ ��������
	n = InitStdGun(n, "pistol11",   	  "pistol11",  "ITEMS_44", 12, 0.001,  1,     3000,    60.0,    300.0, 3.0,    1,  B_GOOD); // �������� ��������
	n = InitStdGun(n, "pistol6",    	    "pistol6",  "ITEMS_37",  3, 0.001,  1,     3500,    45.0,   220.0,  3.5,    2,  B_GOOD); // ���-��������
	n = InitStdGun(n, "pistol_06",    	    "pistol_06",  "ITEMS_54",  11, 0.001,  1,     4000,    55.0,   270.0,  5.0,    2,  B_GOOD); // ��� ������
	n = InitStdGun(n, "pistol9",	      "pistol9", "ITEMS_40", 13, 0.0001,  1,	   4500,	50.0, 	250.0,	3.5,	2,	   B_UNIQUE); // ������������ ��������
	n = InitStdGun(n, "pistol5",    	    "pistol5",  "ITEMS_37",  8, 0.0001,  1,     5000,    90.0,   450.0,  2.5,    1,  B_EXCELLENT); // ���������� ��������
	n = InitStdGun(n, "pistol_05",    	    "pistol_05",  "ITEMS_37",  2, 0.0001,  1,     6000,    100.0,   460.0,  2.0,    1,  B_EXCELLENT); // �������� ����� �� �����
	n = InitStdGun(n, "pistol4",            "pistol4",  "ITEMS_37",  7, 0.0001,  1,     5500,    80.0,   400.0,  6.0,    4,  B_EXCELLENT); // 4-� ��������� ��������

	// ��������� ���������
	//n = InitStdGun(������, �������������, ������, ��������, ��������, ��������, ���.�������, ����, ���. �����������, ����.�����������, ���, ���-�� �������, ��������);
	n = InitStdGun(n, "pistol3",       	    "pistol3",  "ITEMS_37",  11, 0.01,  1,     1000,    15.0,   85.0,  4.0,    1,   B_POOR); // ����������
	n = InitStdGun(n, "pistol_03",       	    "pistol_03",  "ITEMS_16",  1, 0.01,  1,     2000,    20.0,   110.0,  6.0,    1,   B_ORDINARY); // �������
	n = InitStdGun(n, "pistol_08",       	    "pistol_08",  "ITEMS_43",  2, 0.0001,  1,     4000,    50.0,   260.0,  9.0,    1,   B_GOOD); // ���������� ��������
	n = InitStdGun(n, "pistol2", 	        "pistol2",  "ITEMS_37", 	9, 0.0001, 	1,     3000, 	30.0, 	160.0, 	4.5, 	3, 	 B_GOOD); // 3-� ��������� ��������
	n = InitStdGun(n, "pistol02", 	        "pistol02",  "ITEMS_6", 	2, 0.0001, 	1,     3500, 	40.0, 	210.0, 	5.0, 	2, 	 B_GOOD); // �����
	n = InitStdGun(n, "pistol_04",       	    "pistol_04",  "ITEMS_16",  3, 0.0001,  1,     6000,    80.0,   380.0,  6.0,    1,   B_EXCELLENT); // ���������� ��������
	n = InitStdGun(n, "pistol8",            "pistol8",  "ITEMS_37",  6, 0.0001,  1,    7000,    85.0,   390.0,  5.5,    1,     B_UNIQUE); // ����������

	// ������ ���������
	//n = InitStdGun(������, �������������, ������, ��������, ��������, ��������, ���.�������, ����, ���. �����������, ����.�����������, ���, ���-�� �������, ��������);
	n = InitStdGun(n, "pistol7",    	    "pistol7",  "ITEMS_37",  5, 0.0001,  1,    70000,    150.0,   560.0,  2.5,    5,     B_UNIQUE); // ��������� ������
	n = InitStdGun(n, "pistol10",            "pistol10",  "ITEMS_11",  14, 0.0001,  14,     100000,    200.0,   660.0,  3.0,    5,  B_UNIQUE); //��������

	// �������
	//n = InitStdGun(������, �������������, ������, ��������, ��������, ��������, ���.�������, ����, ���. �����������, ����.�����������, ���, ���-�� �������, ��������);
	n = InitStdGun(n, "mushket_01",   	    "mushket_01",  "ITEMS_8", 2, 0.0001,  1,     3500,   80.0,   420.0, 9.5,    1,       B_POOR); // �������
	n = InitStdGun(n, "mushket1",   	    "mushket",  "ITEMS_51", 2, 0.0001,  1,     7000,   130.0,   520.0, 17.5,    1,       B_ORDINARY); // ������
	n = InitStdGun(n, "mushket2",   	 "SeaCarbine",  "ITEMS_51", 1, 0.0001,  1,     12000,   180.0,   620.0, 14.0,    1,       B_GOOD); // �����
	n = InitStdGun(n, "mushket5",   	    "shtuzer",  "ITEMS_37",  13, 0.0001,  1,    20000,   230.0,   720.0, 12.0,    1,     B_UNIQUE); // ������������ ������
	n = InitStdGun(n, "mushket2x2",        "DBmusket",  "ITEMS_37", 14, 0.0001,  1,    22000,   200.0,   670.0, 15.0,    2,     B_UNIQUE); // ��������� ������
	n = InitStdGun(n, "mushket_10",        "mushket_10",  "ITEMS_11", 11, 0.0001,  1,    150000,   330.0,   820.0, 6.0,    5,     B_EXCELLENT); // ������

	// ���������
	//n = InitStdGun(������, �������������, ������, ��������, ��������, ��������, ���.�������, ����, ���. �����������, ����.�����������, ���, ���-�� �������, ��������);
	n = InitStdGun(n, "mushket3",   	  "Arguebuse",  "ITEMS_51", 3, 0.0001,  1,     6000,    120.0,    450.0, 10.5,    1,  B_ORDINARY); // ��������
	n = InitStdGun(n, "Mushket_8",   	  "Mushket_8",  "ITEMS_43", 5, 0.0001,  1,    11000,    170.0,    550.0, 13.0,    1,     B_GOOD); // ����������
	n = InitStdGun(n, "Mushket_9",   	  "Mushket_9",  "ITEMS_37", 4, 0.0001,  1,    18000,    220.0,    650.0, 14.0,    1,     B_EXCELLENT); // ��������
	n = InitStdGun(n, "mushket6",   	  "portugize",  "ITEMS_37", 16, 0.0001,  1,    23000,    170.0,    550.0, 12.5,    5,     B_UNIQUE); // �������� ��������
	n = InitStdGun(n, "mushkett2x2",        "mushkett2x2",  "ITEMS_6", 4, 0.0001,  1,    25000,   190.0,   580.0, 11.0,    2,     B_UNIQUE); //������������ ��������
	n = InitStdGun(n, "grape_mushket",       "mortar",  "ITEMS_37", 15, 0.0001,  1,     20000,   280.0,   820.0,  9.0,  1,     B_UNIQUE); // ���������
	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//										������ � �������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Jason: ����� ������ ������������ ��� ����� ������ �������� � �������������� �� ������� ������� �� ������� �� �����������: 0 - ��� ������, 1-4 - ������� ������. ������� 5 ������ ��� ���� ���������� ����������. ������ ����������� ������� ��� ������� 6 ��� ����, �.�. � ���� ��� �������� ������ ��� ����������� ����� ����� �����, �.�. ����� ���������� ������ � ���� �� �������� �� �����������. ����� 7 - �������� ������ ��������. ��� ����� � �����������. ������ �������, ��� ������� ���������� ������� �� �������������, ����� ����� ������ 0 - ��������� ������ ���������.
	//n = InitStdSuit( ������, �������������, ������, ��������, ��������, ����, ���, ��������, ���.�������, ������?, ������ ��, ������ PM, ���-�� �����);
	// ������� �������
	n = InitStdSuit(n, "cirass1",     	"1", "ITEMS_47",  8,  15000, 40,   0.01,  1, false, 0.35, 0.30, 0.9 ); // ���������� ������
	n = InitStdSuit(n, "cirass2",     	"2", "ITEMS_47",  9,  19000, 30,   0.01,  5, false, 0.25, 0.25, 0.8 ); // ���������� ������
	n = InitStdSuit(n, "cirass3",     	"3", "ITEMS_47",  10,  22000, 15,   0.01, 11, false, 0.20, 0.20, 0.7 ); // �������� ������
	n = InitStdSuit(n, "cirass4",     	"4", "ITEMS_47",  11,  30000, 18,   0.01, 20, false, 0.30, 0.30, 0.9 ); // ��������� �������
	n = InitStdSuit(n, "underwater",  	"5", "ITEMS_54",  3, 300000, 70, 0.0001, 20,  true, 0.35, 0.35, 1.0 ); // ���������� ����������
	// �������
	n = InitStdSuit(n,   "suit1", 		"6", "ITEMS_47",  16, 150000,  7, 0.0001, 20,  true, 0.10, 0.00, 0.2 ); // ����������� ���������� ������
	n = InitStdSuit(n,   "suit2", 		"6", "ITEMS_54", 1, 150000,  7, 0.0001, 20,  true, 0.10, 0.00, 0.2 ); // ���������� ���������� ������
	n = InitStdSuit(n,   "suit3", 		"6", "ITEMS_54", 2, 150000,  7, 0.0001, 20,  true, 0.10, 0.00, 0.2 ); // ��������� ���������� ������
	n = InitStdSuit(n,   "suit4", 		"7", "ITEMS_47",  15,   8000,  6, 0.0001,  1,  false, 0.15, 0.10, 0.6 ); // ������ ��������
	// ������ �������
	n = InitStdSuit(n, "cirass5",  		"0", "ITEMS_47",  12,   7000,  3,   0.01,  1, false, 0.05, 0.00, 0.0 ); // ������� ������
    n = InitStdSuit(n, "cirass6",  		"0", "ITEMS_47",  13,   8000,  6,   0.01, 10, false, 0.10, 0.05, 0.3 ); // ����� �������
	n = InitStdSuit(n, "cirass7",  		"0", "ITEMS_47",  14,   9000, 12,   0.01, 10, false, 0.20, 0.10, 0.5 ); // �������
	n = InitStdSuit(n, "cirass8",  		"0", "ITEMS_40", 14,  10000,  8,   0.01, 20, false, 0.15, 0.10, 0.4 ); // �������� ������
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//										������������������ ��������� - ������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	n = InitStdAmulet(n, "totem_01",  "Totem_1", "ITEMS_21",  3,  rand(5000) + 10000, 0.5, 0.001, 1,  30, ITEM_TOTEM, 1, 1, 		 "", 1); // ������ ������
	n = InitStdAmulet(n, "totem_02",  "Totem_2", "ITEMS_21",  8,  rand(5000) + 10000, 0.5, 0.001, 1,  90, ITEM_TOTEM, 1, 1, "boatswain", 1); // ���������
	n = InitStdAmulet(n, "totem_03",  "Totem_3", "ITEMS_21",  4,  rand(5000) + 10000, 0.5, 0.001, 1,  30, ITEM_TOTEM, 1, 1, 		 "", 1); // ������� ��������
	n = InitStdAmulet(n, "totem_04",  "Totem_4", "ITEMS_21",  2,  rand(5000) + 10000, 0.5, 0.001, 1,  90, ITEM_TOTEM, 1, 1,			 "", 1); // �������
	n = InitStdAmulet(n, "totem_06",  "Totem_6", "ITEMS_21",  6,  rand(5000) + 10000, 0.5, 0.001, 1, 120, ITEM_TOTEM, 1, 1, 		 "", 1); // ������			
	n = InitStdAmulet(n, "totem_05",  "Totem_5", "ITEMS_21",  9,  rand(5000) + 10000, 0.5, 0.001, 1, 360, ITEM_TOTEM, 1, 1, 		 "", 1); // �������� ���	
	n = InitStdAmulet(n, "totem_07",  "Totem_7", "ITEMS_21", 14,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1, 		 "", 1); // ����������
	n = InitStdAmulet(n, "totem_08",  "Totem_8", "ITEMS_21", 13,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1,  "cannoner", 1); // ���������� ����
	n = InitStdAmulet(n, "totem_09",  "Totem_9", "ITEMS_21",  5,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1, "boatswain", 1); // �������
	n = InitStdAmulet(n, "totem_10", "Totem_10", "ITEMS_21", 10,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1,   "fighter", 1); // ������ ����	
	n = InitStdAmulet(n, "totem_11", "Totem_11", "ITEMS_21", 11,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1,	         "", 1); // �����	
	n = InitStdAmulet(n, "totem_12", "Totem_12", "ITEMS_21", 12,  rand(5000) + 10000, 0.5, 0.001, 1,  90, ITEM_TOTEM, 1, 1,		     "", 1); // ��� ������
	n = InitStdAmulet(n, "totem_13", "Totem_13", "ITEMS_21",  7,  rand(5000) + 10000, 0.5, 0.001, 1,  45, ITEM_TOTEM, 1, 1,	         "", 1); // ������
		
	////////////////////////////////////////////////////////////////////////////////////////////
	// ��������������� �������� ������ ����� -->
	////////////////////////////////////////////////////////////////////////////////////////////
	iScriptItemStartNum = n; // ��������� ����� ��������������� ���������
	
	iScriptItemEndNum = n; // �������� ����� ��������������� ���������
	iScriptItemCount = iScriptItemStartNum-iScriptItemEndNum; // ����� ��������������� ���������
	////////////////////////////////////////////////////////////////////////////////////////////
	// <-- ��������������� �������� ������ �����
	////////////////////////////////////////////////////////////////////////////////////////////

	// <<<< ---------------  QUEST ITEMS  --------------------

	makeref(itm,Items[n]);
	itm.id = "gold";
	itm.name = "itmname_gold";
	itm.describe = "itmdescr_gold";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_25";
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "gold_dublon";
	itm.name = "itmname_gold_dublon";
	itm.describe = "itmdescr_gold_dublon";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_25";
	itm.price = 100;
	itm.Weight = 0.1;
	itm.multiobject = true;
	itm.multiobject.qty = 150;
	itm.multiobject.alchemy = false;
	itm.fixedprice = true;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "Chest";
	itm.name = "itmname_chest";
	itm.describe = "itmdescr_chest";
	itm.model = "stat1";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_25";
	itm.price 	= 15000; 
	itm.Weight 	= 16.2; 
	itm.fixedprice = true;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;

	makeref(itm,Items[n]);
	itm.id = "Chest_open";
	itm.name = "itmname_chest_open";
	itm.describe = "itmdescr_chest_open";
	itm.model = "stat1";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_25";
	itm.price 	= 25; 
	itm.Weight 	= 1.2;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "icollection";
	itm.name = "itmname_incas_collection";
	itm.describe = "itmdescr_incas_collection";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_31";
	itm.price = 100000;
	itm.Weight = 50;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;

	// boal ��� ���������� -->
	makeref(itm,Items[n]);
	itm.id = "letter_1";
	itm.name = "itmname_letter_1";
	itm.describe = "itmdescr_letter_1";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

                                                                // ������� ������ ������'�������'
	makeref(itm,Items[n]);
	itm.id = "PrisEscort_book";
	itm.name = "itmname_PrisEscort_book";
	itm.describe = "itmdescr_PrisEscort_book";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "letter_2";
	itm.name = "itmname_letter_2";
	itm.describe = "itmdescr_letter_2";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "letter_open";
	itm.name = "itmname_letter_open";
	itm.describe = "itmdescr_letter_open";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

    // boal ��� ���������� <--
	makeref(itm,Items[n]); //������� � ��������
	itm.id = "leather_bag";
	itm.name = "itmname_leather_bag";
	itm.describe = "itmdescr_leather_bag";
	itm.model = "";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_30";
	itm.price = 0;
	itm.Weight = 8.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������������ �����
	itm.id = "alchemy_tool";
	itm.name = "itmname_alchemy_tool";
	itm.describe = "itmdescr_alchemy_tool";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_18";
	itm.price = 5000;
	itm.Weight = 8.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
    // eddy �������� ������� <--
	makeref(itm,Items[n]);
	itm.id = "EngTradeLicence";
	itm.name = "itmname_EngTradeLicence";
	itm.describe = "itmdescr_EngTradeLicence";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_32";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "FraTradeLicence";
	itm.name = "itmname_FraTradeLicence";
	itm.describe = "itmdescr_FraTradeLicence";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_32";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "SpaTradeLicence";
	itm.name = "itmname_SpaTradeLicence";
	itm.describe = "itmdescr_SpaTradeLicence";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_32";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "HolTradeLicence";
	itm.name = "itmname_HolTradeLicence";
	itm.describe = "itmdescr_HolTradeLicence";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_32";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	// eddy �������� ������� <--

	makeref(itm,Items[n]); //��������� ������ �� ������ ����
	itm.id = "sicretLetter";
	itm.name = "itmname_sicretLetter";
	itm.describe = "itmdescr_sicretLetter";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "mapQuest";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "itmname_mapQuest";
	itm.describe = "itmdescr_mapQuest";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // ��������� �����
	itm.ItemType = "QUESTITEMS";
	itm.Atlas = 0;
	itm.mapType = "Special";
	n++;  

    makeref(itm,Items[n]);
	itm.id = "Bible";
	itm.name = "itmname_bible";
	itm.describe = "itmdescr_bible";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_31";
	itm.price = 0;
	itm.Weight = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); // ������ �����
	itm.id = "BlackLabel";
	itm.name = "itmname_BlackLabel";
	itm.describe = "itmdescr_BlackLabel";
	itm.model = "";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_8";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
    
    makeref(itm,Items[n]);
	itm.id = "MapsAtlas";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "itmname_MapsAtlas";
	itm.describe = "itmdescr_MapsAtlas";
	itm.model = ""; 
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.0;
	itm.ItemType = "QUESTITEMS";
	itm.MapType = "Special";
	itm.mapSpecial = "";
	n++;

	makeref(itm,Items[n]);
	itm.id = "Malyava";
	itm.name = "itmname_Malyava";
	itm.describe = "itmdescr_Malyava";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "PortmansBook";
	itm.name = "itmname_PortmansBook";
	itm.describe = "itmdescr_PortmansBook";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//Jason ����� � ������ - ������
	itm.id = "PostLetters";
	itm.name = "itmname_PostLetters";
	itm.describe = "itmdescr_PostLetters";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//Jason ����� � ������ - �����������
	itm.id = "ContraPostLetters";
	itm.name = "itmname_ContraPostLetters";
	itm.describe = "itmdescr_ContraPostLetters";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//Jason ������ ��� ������ �����������
	itm.id = "suit_1";
	itm.name = "itmname_suit_1";
	itm.describe = "itmdescr_suit_1";
	itm.model = "";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_33";
	itm.price = 0;
	itm.Weight = 6;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//Jason ������ �� ������ �������
	itm.id = "letter_consumption";
	itm.name = "itmname_letter_consumption";
	itm.describe = "itmdescr_letter_consumption";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//Jason ��������� ������ �� ����������
	itm.id = "letter_church";
	itm.name = "itmname_letter_church";
	itm.describe = "itmdescr_letter_church";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//Jason ������������ �� ����������
	itm.id = "prayer_book";
	itm.name = "itmname_prayer_book";
	itm.describe = "itmdescr_prayer_book";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_31";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//������
	itm.id = "fire";
	itm.name = "itmname_fire";
	itm.describe = "itmdescr_fire"; //���, �.�. �� �����
	itm.model = "Bfire";
	itm.picIndex = 16; //�����
	itm.picTexture = "ITEMS_35"; //�����
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	//Jason - ��������� �������� ��� ������������ ������� - ������� ������ � ���� ������
	makeref(itm,Items[n]);
	itm.id = "MerdokArchive";//����� ����� �������
	itm.name = "itmname_MerdokArchive";
	itm.describe = "itmdescr_MerdokArchive";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "Cipher";//���� � ������
	itm.name = "itmname_Cipher";
	itm.describe = "itmdescr_Cipher";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_22";
	itm.price = 10;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "JacobJournal";//������� ������ ��� �����
	itm.name = "itmname_JacobJournal";
	itm.describe = "itmdescr_JacobJournal";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "FleetwoodJournal";//������� ������ ��������
	itm.name = "itmname_FleetwoodJournal";
	itm.describe = "itmdescr_FleetwoodJournal";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "MC_Letter";//������ ������� ��������; �� ����; ��� ����������, 3 � 1
	itm.name = "itmname_MC_Letter";
	itm.describe = "itmdescr_MC_Letter";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "NPC_Letter";//������ ��������; �������
	itm.name = "itmname_NPC_Letter";
	itm.describe = "itmdescr_NPC_Letter";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "Drugstore_keys";//����� �� ���� �������
	itm.name = "itmname_Drugstore_keys";
	itm.describe = "itmdescr_Drugstore_keys";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_22";
	itm.price = 10;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "Finger";//����� ���������� �������
	itm.name = "itmname_Finger";
	itm.describe = "itmdescr_Finger";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GastonHead";//������ �������
	itm.name = "itmname_GastonHead";
	itm.describe = "itmdescr_GastonHead";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 3.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//�������
	itm.id = "lcheer";
	itm.name = "itmname_lcheer";
	itm.describe = "itmdescr_lcheer"; //���, �.�. �� �����
	itm.model = "lcheer";
	itm.picIndex = 16; //�����
	itm.picTexture = "ITEMS_35"; //�����
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	//Jason - ��������� �������� ��� ���� - ������� ������ � ���� ������
	makeref(itm,Items[n]); //�������� ������
	itm.id = "dolly0";
	itm.name = "itmname_dolly0";
	itm.describe = "itmdescr_dolly0"; //���, �.�. �� �����
	itm.model = "dolly_0";
	itm.picIndex = 16; //�����
	itm.picTexture = "ITEMS_35"; //�����
	itm.price = 0;
	itm.Weight = 100.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ������
	itm.id = "dolly5";
	itm.name = "itmname_dolly5";
	itm.describe = "itmdescr_dolly5"; //���, �.�. �� �����
	itm.model = "dolly_5";
	itm.picIndex = 16; //�����
	itm.picTexture = "ITEMS_35"; //�����
	itm.price = 0;
	itm.Weight = 100.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //�������� ������
	itm.id = "bucher_ring";
	itm.name = "itmname_bucher_ring";
	itm.describe = "itmdescr_bucher_ring";
	itm.model = "";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_33";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ����� ��������
	itm.id = "map_half_beatriss";
	itm.name = "itmname_map_half_beatriss";
	itm.describe = "itmdescr_map_half_beatriss";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ����� ������
	itm.id = "map_half_blaze";
	itm.name = "itmname_map_half_blaze";
	itm.describe = "itmdescr_map_half_blaze";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //����� �������� ����� - �� 2 ���������
	itm.id = "map_sharp_full";
	itm.name = "itmname_map_sharp_full";
	itm.describe = "itmdescr_map_sharp_full";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������ ��� �������� �����
	itm.id = "letter_svenson";
	itm.name = "itmname_letter_svenson";
	itm.describe = "itmdescr_letter_svenson";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������ � ���� � ���������� ������ �����
	itm.id = "letter_chad";
	itm.name = "itmname_letter_chad";
	itm.describe = "itmdescr_letter_chad";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������ ���� � ������� ����, 
	itm.id = "letter_chad_1";
	itm.name = "itmname_letter_chad_1";
	itm.describe = "itmdescr_letter_chad_1";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //����� LSC
	itm.id = "LSC_navigation_map";
	itm.name = "itmname_LSC_navigation_map";
	itm.describe = "itmdescr_LSC_navigation_map";
	itm.model = "";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� �� ���������
	itm.id = "key_capper";
	itm.name = "itmname_key_capper";
	itm.describe = "itmdescr_key_capper";
	itm.model = "keysimple";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� ������� ����
	itm.id = "key_mary";
	itm.name = "itmname_key_mary";
	itm.describe = "itmdescr_key_mary";
	itm.model = "keysimple";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����, ���������� ������ �� ��������
	itm.id = "key_gun";
	itm.name = "itmname_key_gun";
	itm.describe = "itmdescr_key_gun";
	itm.model = "keysimple";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // �������
	itm.id = "keys_skel";
	itm.name = "itmname_keys_skel";
	itm.describe = "itmdescr_keys_skel";
	itm.model = "keysimple";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_33";
	itm.Weight = 0.5;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� �� ����� �����-����
	itm.id = "sant_anna_key";
	itm.name = "itmname_sant_anna_key";
	itm.describe = "itmdescr_sant_anna_key";
	itm.model = "keysimple";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� ��������� �� ���������
	itm.id = "key_betancur";
	itm.name = "itmname_key_betancur";
	itm.describe = "itmdescr_key_betancur";
	itm.model = "keysimple";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //����� ������
	itm.id = "buben";
	itm.name = "itmname_buben";
	itm.describe = "itmdescr_buben";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_35";
	itm.price = 0;
	itm.Weight = 2.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ����������� ������
	itm.id = "smoking_tube";
	itm.name = "itmname_smoking_tube";
	itm.describe = "itmdescr_smoking_tube";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_35";
	itm.price = 0;
	itm.Weight = 1.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� �����
	itm.id = "cask_whisky";
	itm.name = "itmname_cask_whisky";
	itm.describe = "itmdescr_cask_whisky";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_35";
	itm.price = 5000;
	itm.Weight = 10;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� �� ����� ��������
	itm.id = "chemistry";
	itm.name = "itmname_chemistry";
	itm.describe = "itmdescr_chemistry";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ����� �����
	itm.id = "witches_hammer";
	itm.name = "itmname_witches_hammer";
	itm.describe = "itmdescr_witches_hammer";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.4;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ��� ��������
	itm.id = "splinter_js";
	itm.name = "itmname_splinter_js";
	itm.describe = "itmdescr_splinter_js";
	itm.model = "";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ��������� �����
	itm.id = "splinter_nh";
	itm.name = "itmname_splinter_nh";
	itm.describe = "itmdescr_splinter_nh";
	itm.model = "";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ������� �������
	itm.id = "splinter_mt";
	itm.name = "itmname_splinter_mt";
	itm.describe = "itmdescr_splinter_mt";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ������� ������
	itm.id = "splinter_zm";
	itm.name = "itmname_splinter_zm";
	itm.describe = "itmdescr_splinter_zm";
	itm.model = "";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� ���� ���������
	itm.id = "splinter_jb";
	itm.name = "itmname_splinter_jb";
	itm.describe = "itmdescr_splinter_jb";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������� � �������
	itm.id = "letter_parol";
	itm.name = "itmname_letter_parol";
	itm.describe = "itmdescr_letter_parol";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��� �����
	itm.id = "shark_teeth";
	itm.name = "itmname_shark_teeth";
	itm.describe = "itmdescr_shark_teeth";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_34";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //�������� �������� ��������
	itm.id = "letter_jess";
	itm.name = "itmname_letter_jess";
	itm.describe = "itmdescr_letter_jess";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //������ �������� ������
	itm.id = "letter_beatriss";
	itm.name = "itmname_letter_beatriss";
	itm.describe = "itmdescr_letter_beatriss";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� �������
	itm.id = "letter_baker";
	itm.name = "itmname_letter_baker";
	itm.describe = "itmdescr_letter_baker";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ ���� �����
	itm.id = "key_facioQ"; 
	itm.name = "itmname_key_facio";
	itm.describe = "itmdescr_key_facioQ";
	itm.model = "keymiddle";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ ��������
	itm.id = "Cromvel_depeshe"; 
	itm.name = "itmname_Cromvel_depeshe";
	itm.describe = "itmdescr_Cromvel_depeshe";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_26";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� ���������
	itm.id = "key_levasser";
	itm.name = "itmname_key_levasser";
	itm.describe = "itmdescr_key_levasser";
	itm.model = "keysimple";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����������� ������ ��� ��������� �������
	itm.id = "specialletter";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_specialletter";
	itm.describe = "itmdescr_specialletter";
	itm.text = "";
    itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����� ��� ������ ��������� �����
	itm.id = "Almanac";
	itm.name = "itmname_Almanac";
	itm.describe = "itmdescr_Almanac";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����������� �������
	itm.id = "VerifyPaper";
	itm.name = "itmname_VerifyPaper";
	itm.describe = "itmdescr_VerifyPaper";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_32";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������� ����� ���� ���������
	itm.id = "skinmap";
	itm.groupID	= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_skinmap";
	itm.describe = "itmdescr_skinmap";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_23";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.mark = 1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ ������ ����
	itm.id = "arrowway";
	itm.name = "itmname_arrowway";
	itm.describe = "itmdescr_arrowway";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_23";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� ��������
	itm.id = "key_archy"; 
	itm.name = "itmname_key_archy";
	itm.describe = "itmdescr_key_archy";
	itm.model = "keymiddle";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����� � ���������
	itm.id = "mark_map";
	itm.groupID	= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_mark_map";
	itm.describe = "itmdescr_mark_map";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.mark = 1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ��������� ����� ����������
	itm.id = "mask_false"; 
	itm.name = "itmname_mask_false";
	itm.describe = "itmdescr_mask_false";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_22";
	itm.Weight = 2.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
		
	makeref(itm,Items[n]); // ������������� ������ ������
	itm.id = "alexs_chest";
	itm.name = "itmname_alexs_chest";
	itm.describe = "itmdescr_alexs_chest";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_18";
	itm.price = 0;
	itm.Weight = 10.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	// �������� �� ������ �������
	makeref(itm,Items[n]); // ������ �1
	itm.id = "kaleuche_amulet1";
	itm.name = "itmname_kaleuche_amulet1";
	itm.describe = "itmdescr_kaleuche_amulet1";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ �2
	itm.id = "kaleuche_amulet2";
	itm.name = "itmname_kaleuche_amulet2";
	itm.describe = "itmdescr_kaleuche_amulet2";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ �3
	itm.id = "kaleuche_amulet3";
	itm.name = "itmname_kaleuche_amulet3";
	itm.describe = "itmdescr_kaleuche_amulet3";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������� �������
	itm.id = "kaleuche_letter";
	itm.name = "itmname_kaleuche_letter";
	itm.describe = "itmdescr_kaleuche_letter";
	itm.model = "";
	itm.picIndex = 16; 
	itm.picTexture = "ITEMS_26"; 
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� �� ������ ���������
	itm.id = "kaleuche_key";
	itm.name = "itmname_kaleuche_key";
	itm.describe = "itmdescr_kaleuche_key";
	itm.model = "";
	itm.picIndex = 6; 
	itm.picTexture = "ITEMS_36"; 
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	// Addon 2016-1 Jason ��������� ������� �������� �� ��������� �������
	makeref(itm,Items[n]); // ������ ���������
	itm.id = "wolfreeks_book";
	itm.groupID	= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_wolfreeks_book";
	itm.describe = "itmdescr_wolfreeks_book";
	itm.text = "";
    itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ ������
	itm.id = "Bunch";
	itm.name = "itmname_bunch";
	itm.describe = "itmdescr_bunch";
	itm.model = "";
	itm.picIndex = 13; 
	itm.picTexture = "ITEMS_17"; 
	itm.price = 5000;
	itm.Weight = 80.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // �������� ������
	itm.id = "Dove";
	itm.name = "itmname_Dove";
	itm.describe = "itmdescr_Dove";
	itm.model = "";
	itm.picIndex = 14; 
	itm.picTexture = "ITEMS_17"; 
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ��������� ��
	itm.id = "indian_poison";
	itm.groupID	= ITEM_SLOT_TYPE;
	itm.name = "itmname_indian_poison";
	itm.describe = "itmdescr_indian_poison";
    itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_17";
	itm.price = 2000;
	itm.Weight = 0.3;
	itm.Type = ITEM_AMULET;
	itm.time = 15;
	itm.ItemType = "ARTEFACT";
	n++;
	
	makeref(itm,Items[n]); // ����� ������ � �������
	itm.id = "mapEnrico";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "itmname_mapEnrico";
	itm.describe = "itmdescr_mapEnrico";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // ��������� �����
	itm.ItemType = "QUESTITEMS";
	itm.Atlas = 0;
	itm.mapType = "Special";
	n++;  
	
	// ��������� �������� ��� ��������� ���������� - 10 ��
	makeref(itm,Items[n]); //��������� ������� �1
	itm.id = "Reserve_item_01"; 
	itm.name = "itmname_Reserve_item_01";
	itm.describe = "itmdescr_Reserve_item_01";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �2
	itm.id = "Reserve_item_02"; 
	itm.name = "itmname_Reserve_item_02";
	itm.describe = "itmdescr_Reserve_item_02";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �3
	itm.id = "Reserve_item_03"; 
	itm.name = "itmname_Reserve_item_03";
	itm.describe = "itmdescr_Reserve_item_03";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �4
	itm.id = "Reserve_item_04"; 
	itm.name = "itmname_Reserve_item_04";
	itm.describe = "itmdescr_Reserve_item_04";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �5
	itm.id = "Reserve_item_05"; 
	itm.name = "itmname_Reserve_item_05";
	itm.describe = "itmdescr_Reserve_item_05";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �6
	itm.id = "Reserve_item_06"; 
	itm.name = "itmname_Reserve_item_06";
	itm.describe = "itmdescr_Reserve_item_06";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �7
	itm.id = "Reserve_item_07"; 
	itm.name = "itmname_Reserve_item_07";
	itm.describe = "itmdescr_Reserve_item_07";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �8
	itm.id = "Reserve_item_08"; 
	itm.name = "itmname_Reserve_item_08";
	itm.describe = "itmdescr_Reserve_item_08";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �9
	itm.id = "Reserve_item_09"; 
	itm.name = "itmname_Reserve_item_09";
	itm.describe = "itmdescr_Reserve_item_09";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �10
	itm.id = "Reserve_item_10"; 
	itm.name = "itmname_Reserve_item_10";
	itm.describe = "itmdescr_Reserve_item_10";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);            //������ ���������
	itm.id = "DestinyGiftPearl";
	itm.name = "itmname_DestinyGiftPearl";
	itm.describe = "itmdescr_DestinyGiftPearl";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_39";
	itm.price = 666;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	// ==> �������� �� ������ ��������
    makeref(itm,Items[n]);
	itm.id = "Powder_mummie";
	itm.name = "itmname_Powder_mummie";
	itm.describe = "itmdescr_Powder_mummie";
	itm.model = "pursel";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_12";
	itm.Weight = 0.5;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

                makeref(itm,Items[n]);
	itm.id = "ShipsJournal_Ascold";
	itm.name = "itmname_ShipsJournal_Ascold";
	itm.describe = "itmdescr_ShipsJournal_Ascold";
	itm.model = "NoteBook2"; 
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_22";
//	itm.shown = 0;
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "LegransMap";
	itm.name = "itmname_LegransMap";
	itm.describe = "itmdescr_LegransMap";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++; 

                makeref(itm,Items[n]);
	itm.id = "ShipsJournal";
	itm.name = "itmname_ShipsJournal";
	itm.describe = "itmdescr_ShipsJournal";
	itm.model = "NoteBook2"; 
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_26";
//	itm.shown = 0;
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++; 


//INDIAN TRINKETS

	makeref(itm,Items[n]);
	itm.id = "indian001"; // +1 sneak
	itm.name = "itmname_indian001";
	itm.describe = "itmdescr_indian001";
	itm.model = "pursel";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 30;
	itm.Weight = 0.3;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian002";
	itm.name = "itmname_indian002";
	itm.describe = "itmdescr_indian002";
	itm.model = "pursel";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 40;
	itm.Weight = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian003";
	itm.name = "itmname_indian003";
	itm.describe = "itmdescr_indian003";
	itm.model = "pursel";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 100;
	itm.Weight = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian004";
	itm.name = "itmname_indian004";
	itm.describe = "itmdescr_indian004";
	itm.model = "pursel";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 5;
	itm.Weight = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian005"; // +1 sneak
	itm.name = "itmname_indian005";
	itm.describe = "itmdescr_indian005";
	itm.model = "sapphire";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 130;
	itm.Weight = 1.5;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian006";
	itm.name = "itmname_indian006";
	itm.describe = "itmdescr_indian006";
	itm.model = "sapphire";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 600;
	itm.Weight = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian007"; // +1 sneak
	itm.name = "itmname_indian007";
	itm.describe = "itmdescr_indian007";
	itm.model = "sapphire";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 150;
	itm.Weight = 3.6;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian008";
	itm.name = "itmname_indian008";
	itm.describe = "itmdescr_indian008";
	itm.model = "sapphire";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 120;
	itm.Weight = 0.6;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian009";
	itm.name = "itmname_indian009";
	itm.describe = "itmdescr_indian009";
	itm.model = "sapphire";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 20;
	itm.Weight = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian010";
	itm.name = "itmname_indian010";
	itm.describe = "itmdescr_indian010";
	itm.model = "sapphire";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 210;
	itm.Weight = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian012";
	itm.name = "itmname_indian012";
	itm.describe = "itmdescr_indian012";
	itm.model = "sapphire";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 1230;
	itm.Weight = 0.7;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian013";
	itm.name = "itmname_indian013";
	itm.describe = "itmdescr_indian013";
	itm.model = "pursel";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 40;
	itm.Weight = 0.3;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian014";
	itm.name = "itmname_indian014";
	itm.describe = "itmdescr_indian014";
	itm.model = "pursel";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 110;
	itm.Weight = 0.3;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian015";
	itm.name = "itmname_indian015";
	itm.describe = "itmdescr_indian015";
	itm.model = "sapphire";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_48";
//	itm.shown = false;
	itm.price = 500;
	itm.Weight = 3;
	n++;

	makeref(itm,Items[n]);
	itm.id = "indian016";
	itm.name = "itmname_indian016";
	itm.describe = "itmdescr_indian016";
	itm.model = "sapphire";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_5";
//	itm.shown = false;
	itm.price = 15;
	itm.Weight = 1;
	n++;

    makeref(itm,Items[n]);
	itm.id = "indian017"; // +1 sneak
	itm.name = "itmname_indian017";
	itm.describe = "itmdescr_indian017";
	itm.model = "sapphire";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_9";
//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 2;
	n++;

    makeref(itm,Items[n]);
	itm.id = "indian018";
	itm.name = "itmname_indian018";
	itm.describe = "itmdescr_indian018";
	itm.model = "pursel";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 75;
	itm.Weight = 2;
	n++;

                makeref(itm,Items[n]);
	itm.id = "indian019";
	itm.name = "itmname_indian019";
	itm.describe = "itmdescr_indian019";
	itm.model = "pursel";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 950;
	itm.Weight = 2;
	n++;

    makeref(itm,Items[n]);
	itm.id = "indian020";
	itm.name = "itmname_indian020";
	itm.describe = "itmdescr_indian020";
	itm.model = "pursel";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 750;
	itm.Weight = 2;
	n++;

    makeref(itm,Items[n]);
	itm.id = "indian021";
	itm.name = "itmname_indian021";
	itm.describe = "itmdescr_indian021";
	itm.model = "sapphire";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 25;
	itm.Weight = 2;
	n++;

    makeref(itm,Items[n]);
	itm.id = "indian022";
	itm.name = "itmname_indian022";
	itm.describe = "itmdescr_indian022";
	itm.model = "pursel";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_7";
//	itm.shown = false;
	itm.price = 5;
	itm.Weight = 2;
	n++;
	                                               //������ ������
                  makeref(itm,Items[n]);
	itm.id = "Obsession_Coin";
	itm.name = "itmname_Obsession_Coin";
	itm.describe = "itmdescr_Obsession_Coin";
	itm.model = "pursel";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_50";
	itm.price = 5;
	itm.Weight = 2;
	n++;
	                                               //��� ������
                  makeref(itm,Items[n]);
	itm.id = "Obsession_Coins";
	itm.name = "itmname_Obsession_Coins";
	itm.describe = "itmdescr_Obsession_Coins";
	itm.model = "pursel";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_50";
	itm.price = 5;
	itm.Weight = 2;
	n++;

	                                               //����� �������
                  makeref(itm,Items[n]);
	itm.id = "Dragon_roses";
	itm.name = "itmname_Dragon_roses";
	itm.describe = "itmdescr_Dragon_roses";
	itm.model = "pursel";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_12";
	itm.price = 5;
	itm.Weight = 2;
	n++;

	                                               //������ �� ���������
	makeref(itm,Items[n]);
	itm.id = "BaltramNotice_0";
	itm.name = "itmname_BaltramNotice_0";
	itm.describe = "itmdescr_BaltramNotice_0";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); //����� �����
	itm.id = "mapAkil";
	itm.name = "itmname_mapAkil";
	itm.describe = "itmdescr_mapAkil";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;

 	//����� �����
      makeref(itm,Items[n]);
	itm.id = "sculMa1";
	itm.name = "itmname_sculMa1";
	itm.describe = "itmdescr_sculMa1";
	itm.model = "SkullAztec";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_9";
	itm.price = 100000;
	itm.Weight = 2.5;
	n++;

 	//������� �����
      makeref(itm,Items[n]);
	itm.id = "sculMa2";
	itm.name = "itmname_sculMa2";
	itm.describe = "itmdescr_sculMa2";
	itm.model = "SkullAztec";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_9";
	itm.price = 100000;
	itm.Weight = 2.5;
	n++;

 	//������� �����
      makeref(itm,Items[n]);
	itm.id = "sculMa3";
	itm.name = "itmname_sculMa3";
	itm.describe = "itmdescr_sculMa3";
	itm.model = "SkullAztec";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_9";
	itm.price = 100000;
	itm.Weight = 2.5;
	n++;

	////////////////////////////////////////////////////////////////////////////////////////////		
	//����� ���������� ��������� ��������, �������� � ��������� item
	//��������� ��� �������� ������ �����, �� ����� ������� ��������� ���������
	////////////////////////////////////////////////////////////////////////////////////////////

	ItemsForLocators_start = n; //��������� ����� ��� ����. ���������

	makeref(itm,Items[n]);
	itm.id = "Rock_letter";
	itm.name = "itmname_Rock_letter";
	itm.describe = "itmdescr_Rock_letter";
	itm.model = "StoneMap";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = 0; //������� �������� ��������, �.�. ����� �� ������ �� ����.������ ��������.
	string PutLocation, PutLocator;   //������ ���������.
    int WherePut = rand(3);
    switch(WherePut)
    {
        case 0:
            PutLocation = "Martinique_Grot";
            PutLocator  = "item"+(rand(2)+1);
        break;
        case 1:
            PutLocation = "Dominica_Grot";
            PutLocator  = "item"+(rand(2)+1);
        break;
        case 2:
            PutLocation = "SantLous_Grot";
            PutLocator  = "item"+(rand(2)+1);
        break;
        case 3:
            PutLocation = "Xsardas_Dungeon";
            PutLocator  = "item"+(rand(2)+1);
        break;
    }
	itm.startLocation = PutLocation;
	itm.startLocator = PutLocator;
	itm.useLocation = "";
	itm.useLocator = "";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;  
	
	makeref(itm,Items[n]);
	itm.id = "Azzy_bottle";
	itm.name = "itmname_Azzy_bottle";
	itm.describe = "itmdescr_Azzy_bottle";
	itm.model = "ToolBox";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_12";
	itm.shown = 1; //�� ���� ������� �� ��������� �� �������
	itm.useLocator = "button01";
	itm.Weight = 2.5;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

                makeref(itm,Items[n]);
	itm.id = "Ascold_rabble"; // ����������
	itm.name = "itmname_Ascold_rabble";
	itm.describe = "itmdescr_Ascold_rabble";
	itm.model = "kocherg";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_12";
	itm.shown = 0;
	itm.useLocation = "";
	itm.useLocator = "";
	itm.Weight = 1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);  //���� ��� ������� ���
	itm.id = "keyQuestLSCC";
	itm.name = "itmname_keyQuestLSCC";
	itm.describe = "itmdescr_keyQuestLSCC";
	itm.model = "keymiddle";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_12";
	itm.shown = 0; //������� ���� �������
	itm.startLocation = "Villemstad_houseSp5";
	itm.startLocator = "item2";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);	//����������
	itm.id = "Pinion";
	itm.name = "itmname_pinion";
	itm.describe = "itmdescr_pinion";
	itm.model = "Pinion";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_12";
	itm.shown = 1; 
	itm.startLocation = "UnderWaterr";
	itm.startLocator = "item" + (rand(4)+1);
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "OpenBook";
	itm.name = "itmname_OpenBook";
	itm.describe = "itmdescr_OpenBook";
	itm.model = "OpenBook";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_4";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	itm.shown = false;
	itm.startLocation = "Vestpunt_townhall";
	itm.startLocator = "item1";
	n++;

	makeref(itm,Items[n]);//��������
	itm.id = "Ladder";
	itm.name = "itmname_Ladder";
	itm.describe = "itmdescr_Ladder";
	itm.model = "Ladder";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_12";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);  //���� �� ������� �� ������ ������
	itm.id = "keyPanama";
	itm.name = "itmname_keyPanama";
	itm.describe = "itmdescr_keyPanama";
	itm.model = "keygrand";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	// Warship ��� ���� ��� �������� ������� �� ������, ������-�� �� ����, ���� � ������ ������� �� �������� ����������� ��
	makeref(itm, Items[n]);
	itm.id = "keyMorgan";
	itm.name = "itmname_keyMorgan";
	itm.describe = "itmdescr_keyMorgan";
	itm.model = "keygrand";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

                                     // <<<< ---------------  ������ �� ���  --------------------

	//��� �������� ������� ��������� ����� 
	Totems_start = n;

	makeref(itm,Items[n]); 
	itm.id = "Totem_001";//����� ����������
	itm.name = "itmname_Totem_001";
	itm.describe = "itmdescr_Totem_001";
	itm.model = "Totem1";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Shore_ship1";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_1_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);
	itm.id = "Totem_002";//����� ��������������
	itm.name = "itmname_Totem_002";
	itm.describe = "itmdescr_Totem_002";
	itm.model = "Totem2";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Shore55";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_2_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_003";//����� ������������
	itm.name = "itmname_Totem_003";
	itm.describe = "itmdescr_Totem_003";
	itm.model = "Totem3";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Tortuga_town";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_3_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_004";//����� ���������
	itm.name = "itmname_Totem_004";
	itm.describe = "itmdescr_Totem_004";
	itm.model = "Totem4";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "PortSpein_town";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_4_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_005";//����� ������������
	itm.name = "itmname_Totem_005";
	itm.describe = "itmdescr_Totem_005";
	itm.model = "Totem5";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Marigo_Cave";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_5_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_006";//����� �������������
	itm.name = "itmname_Totem_006";
	itm.describe = "itmdescr_Totem_006";
	itm.model = "Totem6";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Roseau_port";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_6_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_007";//����� ������������
	itm.name = "itmname_Totem_007";
	itm.describe = "itmdescr_Totem_007";
	itm.model = "Totem7";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Villemstad_townhall";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_7_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_008";//����� �������
	itm.name = "itmname_Totem_008";
	itm.describe = "itmdescr_Totem_008";
	itm.model = "Totem8";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Mayak8";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_8_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);// ������ �������
	itm.id = "Totem_0080";
	itm.name = "itmname_Totem_0080";
	itm.describe = "itmdescr_Totem_0080";
	itm.folder = "items";
	itm.model = "Totem8";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 1.1;
      itm.ItemType = "QUESTITEMS";
	n++;	

	makeref(itm,Items[n]);
	itm.id = "Totem_009";//����� ��������
	itm.name = "itmname_Totem_009";
	itm.describe = "itmdescr_Totem_009";
	itm.model = "Totem9";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Santiago_Incquisitio";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_9_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "Totem_0010";//����� �������������
	itm.name = "itmname_Totem_0010";
	itm.describe = "itmdescr_Totem_0010";
	itm.model = "Totem10";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_10_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "Totem_0011";//����� ��������
	itm.name = "itmname_Totem_0011";
	itm.describe = "itmdescr_Totem_0011";
	itm.model = "Totem11";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Bel_jungle_03";
	itm.startLocator = "item1";
	itm.useLocation = "Tenochtitlan_1";
	itm.useLocator = "button04";
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);//����� ���������
	itm.id = "Totem_0012";//���������� �� �������� ������ � ��������
	itm.name = "itmname_Totem_0012";
	itm.describe = "itmdescr_Totem_0012";
	itm.model = "Totem12";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Guadeloupe_Ruins";
	itm.startLocator = "flower3";
	itm.useLocation = "Templee_great_1";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);    //���� �� ���� ������� �� ������ ����
	itm.id = "Totem_0013"; //����� ������������
	itm.name = "itmname_Totem_0013";
	itm.describe = "itmdescr_Totem_0013";
	itm.model = "Totem13";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true;
	itm.startLocation = "Shore49"; 
	itm.startLocator = "qflower2";
	itm.useLocation = "Tenochtitlan_1";
	itm.useLocator = "button02";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);	//���� �� ���� ������� �� ������ ����
	itm.id = "Totem_0014";//����� �������
	itm.name = "itmname_Totem_0014";
	itm.describe = "itmdescr_Totem_0014";
	itm.model = "Totem14";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Panama_jungle_02";
	itm.startLocator = "item1";
	itm.useLocation = "Tenochtitlan_1";
	itm.useLocator = "button03";
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);	//���������� �� ������ �������� ������
	itm.id = "Totem_0015";//����� ����-������
	itm.name = "itmname_Totem_0015";
	itm.describe = "itmdescr_Totem_0015";
	itm.model = "Totem15";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "HouseMonkJamaica";
	itm.startLocator = "item1";
	itm.useLocation = "Templee_great_1";
	itm.useLocator = "button02";
	itm.ItemType = "QUESTITEMS";
	n++; 

	Totems_end = n;
	//��� �������� ������� �������� ����� 

	makeref(itm,Items[n]);
	itm.id = "TotemTentakli";
	itm.name = "itmname_TotemTentakli";
	itm.describe = "itmdescr_TotemTentakli";
	itm.model = "Totem_2";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.2;
	itm.shown = true; 
	itm.startLocation = "Temple";
	itm.startLocator = "TotemTentakli";
	itm.useLocator = "button01";
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "SkullAztecs";
	itm.name = "itmname_SkullAztecs";
	itm.describe = "itmdescr_SkullAztecs";
	itm.model = "SkullAztecs";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = 1; 
	itm.startLocation = "Templee_great_1";
	itm.startLocator = "item1";
	itm.price = 100000;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "KnifeAztecs";
	itm.name = "itmname_KnifeAztecs";
	itm.describe = "itmdescr_KnifeAztecs";
	itm.model = "KnifeAztecs";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_13";
	itm.shown = 0; 
	itm.useLocation = "Tenochtitlan_1";
	itm.useLocator = "button01";
	itm.price = 25000;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "Idol";//����
	itm.name = "itmname_Idol";
	itm.describe = "itmdescr_Idol";
	itm.model = "stat2";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_1";
	itm.Weight = 2.5;
	itm.shown = true; 
	itm.startLocation = "Templee_round_1";
	itm.startLocator = "item1";
	itm.useLocation = "";
	itm.useLocator = "button01";
	itm.price = 1000000;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� �������� ������
	itm.id = "architects_table";
	itm.name = "itmname_architects_table";
	itm.describe = "itmdescr_architects_table";
	itm.folder = "items";
	itm.model = "table";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 1.1;
                  itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);//�������� �������� �����������
	itm.id = "architects_table_1";
	itm.name = "itmname_architects_table_1";
	itm.describe = "itmdescr_architects_table_1";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ����� ������ (����������)
	itm.id = "architects_table_2";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_architects_table_2";
	itm.describe = "itmdescr_architects_table_2";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ����� ������ (����������)
	itm.id = "architects_table_3";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_architects_table_3";
	itm.describe = "itmdescr_architects_table_3";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ����� ������ (����������)
	itm.id = "architects_table_4";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_architects_table_4";
	itm.describe = "itmdescr_architects_table_4";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ����� ������ (����������)
	itm.id = "architects_table_5";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_architects_table_5";
	itm.describe = "itmdescr_architects_table_5";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ����� ������ (����������)
	itm.id = "architects_table_6";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_architects_table_6";
	itm.describe = "itmdescr_architects_table_6";
	itm.folder = "";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = false;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//����� ��������
	itm.id = "architects_table_7";
	itm.name = "itmname_architects_table_7";
	itm.describe = "itmdescr_architects_table_7"
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = true;
	itm.startLocation = "Xsardas_Dungeon"; 
	itm.startLocator = "item5";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);//������� ��������
	itm.id = "architects_table_8";
	itm.name = "itmname_architects_table_8";
	itm.describe = "itmdescr_architects_table_8";
	itm.model = "table1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_4";
	itm.shown = true;
	itm.startLocation = "";
	itm.startLocator = "";
	itm.price = 0;
	itm.Weight = 0.1;
                     itm.ItemType = "QUESTITEMS";
	n++;

                  // ---------------  QUEST ITEMS KKC --------------------
	
	makeref(itm,Items[n]); // ��������� ����� ����������
	itm.id = "mask_true"; 
	itm.name = "itmname_mask_true";
	itm.describe = "itmdescr_mask_true";
	itm.model = "guise";
	itm.shown = true;
	itm.startLocation = "Shore_mask";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_great";
	itm.useLocator = "button04";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_22";
	itm.Weight = 2.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "gold_Itza";
	itm.name = "itmname_gold_Itza";
	itm.describe = "itmdescr_gold_Itza";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_56";
	itm.price = 300;
	itm.Weight = 0.0; 
	itm.multiobject = true;
	itm.multiobject.qty = 150;
	itm.multiobject.alchemy = false;
	itm.fixedprice = true;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;
	
	makeref(itm,Items[n]); //��������� ��������� ����
	itm.id = "calendar_maya";
	itm.name = "itmname_calendar_maya";
	itm.describe = "itmdescr_calendar_maya";
	itm.model = "calendar";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_34";
	itm.shown = true;
	itm.useLocation = "Pearl_jungle_03";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	// �������� ����� ����
	makeref(itm,Items[n]); // ������ - ����
	itm.id = "Tablet_1";
	itm.name = "itmname_Tablet_1";
	itm.describe = "itmdescr_Tablet_1";
	itm.model = "Totem_7";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_AZTEC";
	itm.useLocation = "Tenochtitlan";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	makeref(itm,Items[n]); // �����-���� - ������
	itm.id = "Tablet_2";
	itm.name = "itmname_Tablet_2";
	itm.describe = "itmdescr_Tablet_2";
	itm.model = "Totem_14";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple_Treasure";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_great";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	makeref(itm,Items[n]); // ���, ����
	itm.id = "Tablet_3";
	itm.name = "itmname_Tablet_3";
	itm.describe = "itmdescr_Tablet_3";
	itm.model = "Totem_8";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_AZTEC";
	itm.useLocation = "Temple_great";
	itm.useLocator = "button02";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	makeref(itm,Items[n]); // �����, �����
	itm.id = "Tablet_4";
	itm.name = "itmname_Tablet_4";
	itm.describe = "itmdescr_Tablet_4";
	itm.model = "Totem_3";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple_round";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_great";
	itm.useLocator = "button03";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	makeref(itm,Items[n]); // ������, �����
	itm.id = "Tablet_5";
	itm.name = "itmname_Tablet_5";
	itm.describe = "itmdescr_Tablet_5";
	itm.model = "Totem_11";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple_great";
	itm.startLocator = "item1";
	itm.shown = true; 
	itm.useLocation = "Temple_2";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	makeref(itm,Items[n]); // ��-����, ��������
	itm.id = "Tablet_6";
	itm.name = "itmname_Tablet_6";
	itm.describe = "itmdescr_Tablet_6";
	itm.model = "Totem_10";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_AZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple_"+(rand(4)+1);
	itm.startLocator = "item"+(rand(9)+1);
	itm.useLocation = "Temple_6";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.Weight = 0.3;
	itm.ItemType = "QUESTITEMS";
	n++; 
	
	// ��������
	makeref(itm,Items[n]);
	itm.id = "purse1";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.result = "gold_dublon";
	itm.result.qty = 10;
	itm.name = "itmname_purse1";
	itm.describe = "itmdescr_purse1";
    itm.model = "purseM";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "purse2";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.result = "gold_dublon";
	itm.result.qty = 25;
	itm.name = "itmname_purse2";
	itm.describe = "itmdescr_purse2";
                     itm.model = "purseL";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 2.5;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "purse3";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.result = "gold_dublon";
	itm.result.qty = 50;
	itm.name = "itmname_purse3";
	itm.describe = "itmdescr_purse3";
                     itm.model = "purse";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 5.0;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "ShipyardsMap";
	itm.name = "itmname_ShipyardsMap";
	itm.describe = "itmdescr_ShipyardsMap";
	itm.model = "shipyardsMap";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "CaptainBook";
	itm.name = "itmname_CaptainBook";
	itm.describe = "itmdescr_CaptainBook";
	itm.model = "shipyardsMap";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //
	itm.id = "RingCapBook";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_ringcapbook";
	itm.describe = "itmdescr_ringcapbook";
                    itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������� �������� 070712
	itm.id = "ArchyBook";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_ArchyBook";
	itm.describe = "itmdescr_ArchyBook";
                     itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ������ �������� �����-��������
	itm.id = "SQCapBook";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_SQCapBook";
	itm.describe = "itmdescr_SQCapBook";
                     itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.startLocation = "SantaQuiteriaInside";
	itm.startLocator = "item1";
	itm.shown = true;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "MayorsRing";
	itm.name = "itmname_MayorsRing";
	itm.describe = "itmdescr_MayorsRing";
	itm.model = "RingSimGold";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_24";
	itm.Weight = 0.3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); // �������� ����
	itm.id = "stonekey"; 
	itm.name = "itmname_stonekey";
	itm.describe = "itmdescr_stonekey";
	itm.model = "keymiddle";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	// ����� ��� ������ ��������� ��������
	makeref(itm, Items[n]);
	itm.id = "key1";
	itm.name = "itmname_key1";
	itm.describe = "itmdescr_key1";
	itm.model = "keysimple";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm, Items[n]);
	itm.id = "key2";
	itm.name = "itmname_key2";
	itm.describe = "itmdescr_key2";
	itm.model = "keysimple";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm, Items[n]);
	itm.id = "key3";
	itm.name = "itmname_key3";
	itm.describe = "itmdescr_key3";
	itm.model = "keymiddle";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	    
	makeref(itm,Items[n]);
	itm.id = "SkullAztec";
	itm.name = "itmname_SkullAztec";
	itm.describe = "itmdescr_SkullAztec";
	itm.model = "SkullAztec";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_22";
	itm.price = 200000;
	itm.Weight = 2.5;
	itm.ItemType = "QUESTITEMS"; // 110912 
	n++;

	makeref(itm,Items[n]);//Jason - ���� � ������������ ��� ����������
	itm.id = "Tool";
	itm.name = "itmname_Tool";
	itm.describe = "itmdescr_Tool";
	itm.model = "ToolBox";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_18";
	itm.price = 0;
	itm.Weight = 2.0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); //����� ���������� - ��������� ��������
	itm.id = "Amminition_Tool";
	itm.name = "itmname_Amminition_Tool";
	itm.describe = "itmdescr_Amminition_Tool";
	itm.model = "ToolBox";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_18";
	itm.price = 3000;
	itm.Weight = 3.0;
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	// Jason - ������� ����� ��������� - �������� ��� ������� ��� ������
	makeref(itm,Items[n]);
	itm.id = "meteorite";
	itm.name = "itmname_meteorite";
	itm.describe = "itmdescr_meteorite";
	itm.model = "SkyStone";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_28";
	itm.price = 20000;
	itm.priceDublon = 200;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.Weight = 5.0;
	itm.TradeType = ITEM_TRADE_JEWELRY;
	n++;
	
	makeref(itm,Items[n]); //��������� �� ������
	itm.id = "letter_mine";
	itm.name = "itmname_letter_mine";
	itm.describe = "itmdescr_letter_mine";
	itm.model = "letter";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.shown = true;
	itm.startLocation = "Mine_residence";
	itm.startLocator = "item1";
	itm.ItemType = "QUESTITEMS";
	n++;
	
	// Jason: ������ - ���� ����, ����� ����� ���� �������� ��������
	makeref(itm,Items[n]);
	itm.id = "cannabis1";
	itm.name = "itmname_cannabis1";
	itm.describe = "itmdescr_cannabis1";
    itm.model = "flower";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_19";
	itm.price = 30;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "cannabis2";
	itm.name = "itmname_cannabis2";
	itm.describe = "itmdescr_cannabis2";
    itm.model = "flower";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_19";
	itm.price = 10;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "cannabis3";
	itm.name = "itmname_cannabis3";
	itm.describe = "itmdescr_cannabis3";
    itm.model = "flower";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_19";
	itm.price = 10;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "cannabis4";
	itm.name = "itmname_cannabis4";
	itm.describe = "itmdescr_cannabis4";
    itm.model = "flower";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_19";
	itm.price = 7;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "cannabis5";
	itm.name = "itmname_cannabis5";
	itm.describe = "itmdescr_cannabis5";
    itm.model = "flower";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_19";
	itm.price = 12;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "cannabis6";
	itm.name = "itmname_cannabis6";
	itm.describe = "itmdescr_cannabis6";
    itm.model = "flower";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_19";
	itm.price = 10;
	itm.Weight = 0.1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]); // Jason: ��������� ������ ��� ��������� ����������� - ���������
	itm.id = "cannabis7";
	itm.name = "itmname_cannabis7";
	itm.describe = "itmdescr_cannabis7";
    itm.model = "durman";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_35";
	itm.price = 500;
	itm.Weight = 0.5;
	itm.ItemType = "SUPPORT";
	n++;

	 makeref(itm,Items[n]); // Jason: ����� �� ���� �� ���������
	itm.id = "crowbar"; 
	itm.name = "itmname_crowbar";
	itm.describe = "itmdescr_crowbar";
	itm.model = "mushket";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_35";
	itm.Weight = 3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); // Jason: ���� �����
	itm.id = "key_facio"; 
	itm.name = "itmname_key_facio";
	itm.describe = "itmdescr_key_facio";
	itm.model = "keymiddle";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "MaltieBase_keys";//����� �� ��������� ���� ����������
	itm.name = "itmname_MaltieBase_keys";
	itm.describe = "itmdescr_MaltieBase_keys";
	itm.model = "ligament";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_22";
	itm.price = 0;
	itm.Weight = 1.5;
	itm.ItemType = "QUESTITEMS";
	n++;

	// �������� �� ������ �������
	makeref(itm,Items[n]); // ������� ���������
	itm.id = "MerrimanBook";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_MerrimanBook";
	itm.describe = "itmdescr_MerrimanBook";
    itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� ��� ����� ����� ���
	itm.id = "KhaelRoa_item"; 
	itm.name = "itmname_KhaelRoa_item";
	itm.describe = "itmdescr_KhaelRoa_item";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 2.0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� ��� ����� ������
	itm.id = "KaleucheOther_item"; 
	itm.name = "itmname_KaleucheOther_item";
	itm.describe = "itmdescr_KaleucheOther_item";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;

	// ����� ��� ��������� ������� // Addon 2016-1 Jason ��������� �������
	makeref(itm,Items[n]); // ���� ���������
	itm.id = "key_scotland"; 
	itm.name = "itmname_key_scotland";
	itm.describe = "itmdescr_key_scotland";
	itm.model = "keymiddle";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ���� � ����������� ������
	itm.id = "key_ruins"; 
	itm.name = "itmname_key_ruins";
	itm.describe = "itmdescr_key_ruins";
	itm.model = "keymiddle";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_36";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	// ��������� �������� ��� ��������� ���������� - +10 ��
	makeref(itm,Items[n]); //��������� ������� �11
	itm.id = "Reserve_item_11"; 
	itm.name = "itmname_Reserve_item_11";
	itm.describe = "itmdescr_Reserve_item_11";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �12
	itm.id = "Reserve_item_12"; 
	itm.name = "itmname_Reserve_item_12";
	itm.describe = "itmdescr_Reserve_item_12";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �13
	itm.id = "Reserve_item_13"; 
	itm.name = "itmname_Reserve_item_13";
	itm.describe = "itmdescr_Reserve_item_13";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �14
	itm.id = "Reserve_item_14"; 
	itm.name = "itmname_Reserve_item_14";
	itm.describe = "itmdescr_Reserve_item_14";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �15
	itm.id = "Reserve_item_15"; 
	itm.name = "itmname_Reserve_item_15";
	itm.describe = "itmdescr_Reserve_item_15";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �16
	itm.id = "Reserve_item_16"; 
	itm.name = "itmname_Reserve_item_16";
	itm.describe = "itmdescr_Reserve_item_16";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �17
	itm.id = "Reserve_item_17"; 
	itm.name = "itmname_Reserve_item_17";
	itm.describe = "itmdescr_Reserve_item_17";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �18
	itm.id = "Reserve_item_18"; 
	itm.name = "itmname_Reserve_item_18";
	itm.describe = "itmdescr_Reserve_item_18";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �19
	itm.id = "Reserve_item_19"; 
	itm.name = "itmname_Reserve_item_19";
	itm.describe = "itmdescr_Reserve_item_19";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); //��������� ������� �20
	itm.id = "Reserve_item_20"; 
	itm.name = "itmname_Reserve_item_20";
	itm.describe = "itmdescr_Reserve_item_20";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_36";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	n++;

	// �������� ������
	makeref(itm,Items[n]);
	itm.id = "BookFencing";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookFencing";
	itm.describe = "itmdescr_BookFencing";
	itm.model = "NoteBook3"; 
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.startLocation = "SantaCatalinaPirateResidence";
	itm.startLocator = "item1";
	itm.shown = true;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "BookTrader";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookTrader";
	itm.describe = "itmdescr_BookTrader";
	itm.model = "NoteBook1"; 
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "BookCanoneer";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookCanoneer";
	itm.describe = "itmdescr_BookCanoneer";
	itm.model = "NoteBook4"; 
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "BookSailor";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookSailor";
	itm.describe = "itmdescr_BookSailor";
	itm.model = "NoteBook4"; 
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.startLocation = "Xsardas_Dungeon";
	itm.startLocator = "item6";
	itm.shown = true;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "BookBoatSwain";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookBoatSwain";
	itm.describe = "itmdescr_BookBoatSwain";
	itm.model = "NoteBook4"; 
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);
	itm.id = "BookAgent";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BookAgent";
	itm.describe = "itmdescr_BookAgent";
	itm.model = "NoteBook2"; 
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_14";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);	//�������� ������
	itm.id = "letter_LSCC";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_letter_LSCC";
	itm.describe = "itmdescr_letter_LSCC";
	itm.model = "letter";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);	//������ ������� ������ ����������
	itm.id = "letter_LSCC_1";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_letter_LSCC_1";
	itm.describe = "itmdescr_letter_LSCC_1";
	itm.model = "letter";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);	//�������� ������ ����
	itm.id = "letter_LSCC_2";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_letter_LSCC_2";
	itm.describe = "itmdescr_letter_LSCC_2";
	itm.model = "letter";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
 
	                                               //������� ������ �.��������
	makeref(itm,Items[n]);
	itm.id = "SoukinsBook";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_SoukinsBook";
	itm.describe = "itmdescr_SoukinsBook";
	itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_22";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	itm.shown = false;
	itm.startLocation = "Vestpunt_townhall";
	itm.startLocator = "item1";
	n++;

	                                               //������ �� ���������
	makeref(itm,Items[n]);
	itm.id = "BaltramNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_BaltramNotice";
	itm.describe = "itmdescr_BaltramNotice";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	                                               //������ �� �����
	makeref(itm,Items[n]);
	itm.id = "AkilKillersNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_AkilKillersNotice";
	itm.describe = "itmdescr_AkilKillersNotice";
	itm.model = "";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                               //������� ��� �����
	makeref(itm,Items[n]);
	itm.id = "CarrolNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_CarrolNotice";
	itm.describe = "itmdescr_CarrolNotice";
	itm.model = "letter";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                                //������� �
	makeref(itm,Items[n]);
	itm.id = "MCorsairNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_MCorsairNotice";
	itm.describe = "itmdescr_MCorsairNotice";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                                //���������� ������ �������
	makeref(itm,Items[n]);
	itm.id = "MyxirNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_MyxirNotice";
	itm.describe = "itmdescr_MyxirNotice";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_8";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                                //���������� ������ �������
	makeref(itm,Items[n]);
	itm.id = "APSHMyxirNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_APSHMyxirNotice";
	itm.describe = "itmdescr_APSHMyxirNotice";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_8";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                                //���������� ������ �������
	makeref(itm,Items[n]);
	itm.id = "QuarhodronMyxirNotice";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_QuarhodronMyxirNotice";
	itm.describe = "itmdescr_QuarhodronMyxirNotice";
	itm.model = "";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_8";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;


	                                               //���
	makeref(itm,Items[n]);
	itm.id = "Rumm";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Rumm";
	itm.describe = "itmdescr_Rumm";
	itm.model = "vodka";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_55";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.potion.pic = 25;
	itm.potion.tex = 0; 
	itm.potion.health = 50.0;
	itm.potion.antidote = true;
	//navy -->
	itm.potion.drunk = 51;
	itm.potion.drunk.time = 5600;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                               //����
	makeref(itm,Items[n]);
	itm.id = "Grog";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Grog";
	itm.describe = "itmdescr_Grog";
	itm.model = "vodka";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_55";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.potion.pic = 25;
	itm.potion.tex = 0; 
	itm.potion.health = 50.0;
	itm.potion.antidote = true;
	//navy -->
	itm.potion.drunk = 51;
	itm.potion.drunk.time = 5600;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                               //������� ��
	makeref(itm,Items[n]);
	itm.id = "Loushammer";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Loushammer";
	itm.describe = "itmdescr_Loushammer";
	itm.model = "vodka";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_55";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.potion.pic = 26;
	itm.potion.tex = 0; 
	itm.potion.health = 175.0;
	itm.potion.health.speed = 7; // �������� ���������
	//navy -->
	itm.potion.drunk = 15;
	itm.potion.drunk.time = 8000;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                               //������� ������
	makeref(itm,Items[n]);
	itm.id = "Schnellerhering";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Schnellerhering";
	itm.describe = "itmdescr_Schnellerhering";
	itm.model = "vodka";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_1";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.potion.pic = 26;
	itm.potion.tex = 0; 
	itm.potion.health = 175.0;
	itm.potion.health.speed = 7; // �������� ���������
	//navy -->
	itm.potion.drunk = 15;
	itm.potion.drunk.time = 8000;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	                                               //������� ����� ��
	makeref(itm,Items[n]);
	itm.id = "Lousdoublehammer";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Lousdoublehammer";
	itm.describe = "itmdescr_Lousdoublehammer";
	itm.model = "vodka";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_55";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.potion.pic = 26;
	itm.potion.tex = 0; 
	itm.potion.health = 175.0;
	itm.potion.health.speed = 7; // �������� ���������
	//navy -->
	itm.potion.drunk = 15;
	itm.potion.drunk.time = 8000;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); // �������� �����
	itm.id = "fennis_grass";
	itm.name = "itmname_fennis_grass";
	itm.describe = "itmdescr_fennis_grass";
                   itm.model = "durman";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_35";
	itm.price = 500;
	itm.Weight = 0.5;
	itm.ItemType = "SUPPORT";
	n++;

			
	ItemsForLocators_end = n; //�������� ����� ��� ����. ���������

	// <<<< ---------------  QUEST ITEMS  --------------------
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//							�����
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	//int InitStdMap(ItemIndex, id, picTexture, picIndex, PriceModificator, Weight, ImageTga, ImageType, Atlas, MapType)
	n = InitStdMap(n, 		  "map_bad", "ITEMS_46",  1,  (rand(4) + 6) * 1000, 0.1, 0.005,        "map_2", "cabin_map",  0,   "Special"); // ������ �����
	n = InitStdMap(n,      "map_normal", "ITEMS_45",  14,  (rand(8) + 9) * 1020, 0.1, 0.001,        "map_1", "cabin_map",  0,   "Special"); // ������� �����
    n = InitStdMap(n,        "Map_Best", "ITEMS_27",  3, (rand(8) + 37) * 1000, 0.1, 0.001,     "map_good", "cabin_map",  0,   "Special"); // �������� �����
    n = InitStdMap(n,    "map_bermudas", "ITEMS_41",  4,  (rand(8) + 6) * 1050, 0.2,   0.0,     "cap_bermudas",          "",  1,	 	  ""); // ����-������	
	n = InitStdMap(n,         "map_jam", "ITEMS_41",  11,  (rand(8) + 6) * 1100, 0.2,   0.0,      "cap_Jamaica",          "",  1,	  	  ""); // ������	
	n = InitStdMap(n,      "map_cayman", "ITEMS_41",  12,  (rand(8) + 8) * 1015, 0.2,   0.0,       "cap_kayman",          "",  1,		  ""); // ������		
	n = InitStdMap(n,    "map_barbados", "ITEMS_41",  2,  (rand(8) + 6) * 1200, 0.2,   0.0,     "cap_barbados",          "",  1,		  ""); // ��������			
	n = InitStdMap(n,     "map_tortuga", "ITEMS_42",  8,  (rand(8) + 6) * 1070, 0.2,   0.0,      "cap_tortuga",          "",  1,	 	  ""); // �������				
	n = InitStdMap(n,     "map_curacao", "ITEMS_41",  7,  (rand(8) + 6) * 1300, 0.2,   0.0,      "cap_curacao",          "",  1,		  ""); // �������				
	n = InitStdMap(n,  "map_martiniqua", "ITEMS_41",  16,  (rand(8) + 6) * 1250, 0.2,   0.0,    "cap_martinica",          "",  1,	  	  ""); // ���������				
	n = InitStdMap(n,    "map_dominica", "ITEMS_41",  8,  (rand(8) + 7) * 1030, 0.2,   0.0,     "cap_dominica",          "",  1,	 	  ""); // ��������						
	n = InitStdMap(n,    "map_trinidad", "ITEMS_42",  9,  (rand(8) + 6) * 1080, 0.2,   0.0,     "cap_trinidad",          "",  1,		  ""); // �������� � ������							
	n = InitStdMap(n,      "map_puerto", "ITEMS_42",  2,  (rand(8) + 6) * 1500, 0.2,   0.0,       "cap_p_rico",          "",  1,		  ""); // ������-����								
	n = InitStdMap(n,        "map_cuba", "ITEMS_41",  5, (rand(8) + 12) * 1090, 0.2,   0.0,         "cap_cuba",          "",  1,		  ""); // ����								
	n = InitStdMap(n,        "map_hisp", "ITEMS_41",  10, (rand(8) + 12) * 1220, 0.2,   0.0,   "cap_hispaniola",          "",  1,		  ""); // ���������									
	n = InitStdMap(n,       "map_nevis", "ITEMS_42",  1,  (rand(8) + 6) * 1010, 0.2,   0.0,        "cap_nevis",          "",  1,	 	  ""); // ����-���������									
	n = InitStdMap(n,       "map_beliz", "ITEMS_41",  3,  (rand(8) + 9) * 1300, 0.2,   0.0,        "cap_beliz",          "",  1,		  ""); // �����									
	n = InitStdMap(n,        "map_guad", "ITEMS_41",  9,  (rand(8) + 6) * 1015, 0.2,   0.0,    "cap_guadelupa",          "",  1,		  ""); // ���������										
	n = InitStdMap(n,       "map_santa", "ITEMS_42",  6,  (rand(8) + 8) * 1280, 0.2,   0.0,        "cap_santa",          "",  1,		  ""); // ��������										
	n = InitStdMap(n,     "map_antigua", "ITEMS_41",  1,  (rand(8) + 6) * 1400, 0.2,   0.0,      "cap_antigua",          "",  1,		  ""); // ������� 											
	n = InitStdMap(n,       "map_terks", "ITEMS_42",  7,  (rand(8) + 9) * 1350, 0.2,   0.0,        "cap_terks",          "",  1,		  ""); // �����											
	n = InitStdMap(n,          "map_sm", "ITEMS_42",  5,  (rand(8) + 6) * 1500, 0.2,   0.0,     "cap_s_martin",          "",  1,		  ""); // ����-�������											
	n = InitStdMap(n,     "map_maine_1", "ITEMS_41",  13, (rand(8) + 17) * 1100, 0.2,   0.0,      "cap_maine_1",          "",  1,		  ""); // ����� �������, ����� (��������� + ���������)										
	n = InitStdMap(n,     "map_maine_2", "ITEMS_41",  14, (rand(8) + 18) * 1150, 0.2,   0.0,      "cap_maine_2",          "",  1,		  ""); // �������											
	n = InitStdMap(n,      "map_panama", "ITEMS_42",  3,  (rand(8) + 7) * 1200, 0.2,   0.0,       "cap_panama", 		 "",  1,		  ""); // ����� �������, ����� (������)												
	n = InitStdMap(n,      "map_cumana", "ITEMS_41",  6,  (rand(8) + 7) * 1400, 0.2,   0.0,       "cap_cumana",          "",  1,		  ""); // ������									
	n = InitStdMap(n,        "map_full", "ITEMS_27",  5,                     0, 0.4,   0.0,         "none",   "MapRead",  0,	  "Full"); 									
	n = InitStdMap(n,       "map_part1", "ITEMS_27",  6,                     0, 0.2,   0.0,         "none",   "MapRead",  0,	  "Part");									
	n = InitStdMap(n,       "map_part2", "ITEMS_27",  7,                     0, 0.2,   0.0,         "none",   "MapRead",  0,	  "Part");	
	n = InitStdMap(n,         "map_LSC", "ITEMS_27",  14,                20000, 0.2,   0.0,"LostShipsCity",          "",  0,   "Special");
	n = InitStdMap(n,         "map_LSCC", "ITEMS_42",  10,                20000, 0.2,   0.0,"LostShipsCityy",          "",  0,   "Special");		
	
	// ------------------------------ ������������ ����� 24 �� -----------------------------------------------
	n = InitStdMap(n,    "A_map_bermudas", "ITEMS_27",  8,  (rand(4) + 6) * 2000,  0.2,   0.0,     "bermudas",          "",  0,	 	  "Special"); // ����-������	
	n = InitStdMap(n,         "A_map_jam", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,      "Jamaica",          "",  0,	  	  "Special"); // ������	
	n = InitStdMap(n,      "A_map_cayman", "ITEMS_27",  8,  (rand(8) + 8) * 2000,  0.2,   0.0,       "kayman",          "",  0,		  "Special"); // ������		
	n = InitStdMap(n,    "A_map_barbados", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,     "barbados",          "",  0,		  "Special"); // ��������			
	n = InitStdMap(n,     "A_map_tortuga", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,      "tortuga",          "",  0,	 	  "Special"); // �������				
	n = InitStdMap(n,     "A_map_curacao", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,      "curacao",          "",  0,		  "Special"); // �������				
	n = InitStdMap(n,  "A_map_martiniqua", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,    "martinica",          "",  0,	  	  "Special"); // ���������				
	n = InitStdMap(n,    "A_map_dominica", "ITEMS_27",  8,  (rand(8) + 7) * 2000,  0.2,   0.0,     "dominica",          "",  0,	 	  "Special"); // ��������						
	n = InitStdMap(n,    "A_map_trinidad", "ITEMS_27",  8,  (rand(8) + 6) * 2000,  0.2,   0.0,     "trinidad",          "",  0,		  "Special"); // �������� � ������							
	n = InitStdMap(n,      "A_map_puerto", "ITEMS_27",  8,  (rand(8) + 6) * 2000, 0.2,   0.0,       "p_rico",          "",  0,		  "Special"); // ������-����								
	n = InitStdMap(n,        "A_map_cuba", "ITEMS_27",  8, (rand(8) + 12) * 2000, 0.2,   0.0,         "cuba",          "",  0,		  "Special"); // ����								
	n = InitStdMap(n,        "A_map_hisp", "ITEMS_27",  8, (rand(8) + 12) * 2000, 0.2,   0.0,   "hispaniola",          "",  0,		  "Special"); // ���������									
	n = InitStdMap(n,       "A_map_nevis", "ITEMS_27",  8,  (rand(8) + 6) * 2000, 0.2,   0.0,        "nevis",          "",  0,	 	  "Special"); // ����-���������									
	n = InitStdMap(n,       "A_map_beliz", "ITEMS_27",  8,  (rand(8) + 9) * 2000, 0.2,   0.0,        "beliz",          "",  0,		  "Special"); // �����									
	n = InitStdMap(n,        "A_map_guad", "ITEMS_27",  8,  (rand(8) + 6) * 2000, 0.2,   0.0,    "guadelupa",          "",  0,		  "Special"); // ���������										
	n = InitStdMap(n,       "A_map_santa", "ITEMS_27",  8,  (rand(8) + 8) * 2000, 0.2,   0.0,        "santa",          "",  0,		  "Special"); // ��������										
	n = InitStdMap(n,     "A_map_antigua", "ITEMS_27",  8,  (rand(8) + 6) * 2000, 0.2,   0.0,      "antigua",          "",  0,		  "Special"); // ������� 											
	n = InitStdMap(n,       "A_map_terks", "ITEMS_27",  8,  (rand(8) + 9) * 2000, 0.2,   0.0,        "terks",          "",  0,		  "Special"); // �����											
	n = InitStdMap(n,          "A_map_sm", "ITEMS_27",  8,  (rand(8) + 6) * 2000, 0.2,   0.0,     "s_martin",          "",  0,		  "Special"); // ����-�������											
	n = InitStdMap(n,     "A_map_maine_1", "ITEMS_27",  8, (rand(8) + 17) * 2000, 0.2,   0.0,      "maine_1",          "",  0,		  "Special"); // ����� �������, ����� (��������� + ���������)										
	n = InitStdMap(n,     "A_map_maine_2", "ITEMS_27",  8, (rand(8) + 18) * 2000, 0.2,   0.0,      "maine_2",          "",  0,		  "Special"); // �������											
	n = InitStdMap(n,      "A_map_panama", "ITEMS_27",  8,  (rand(8) + 7) * 2000, 0.2,   0.0,       "panama", 		   "",  0,		  "Special"); // ����� �������, ����� (������)												
	n = InitStdMap(n,      "A_map_cumana", "ITEMS_27",  8,  (rand(8) + 7) * 2000, 0.2,   0.0,       "cumana",          "",  0,		  "Special"); // ������			
	n = InitStdMap(n,      "A_map_perl", "ITEMS_27",  8,  (rand(8) + 7) * 2000,   0.2,   0.0,         "perl",          "",  0,		  "Special"); // �����������	

    //  ���������� ������
    ItemDeadStartCount = n;
    trace("���������� ������ � �������� "+ItemDeadStartCount);
    
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//							������� � ������� � �������� ������ ��������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//InitStdAmulet(������, �������������, ������, ��������, ��������, ����, ���, ��������, ����������� �������, ����� ��������, ���, ������������, ���-�� �� ������,��� �������, ���� ������������ -����� �� ���� �������);
	// ������� ������ � �������� (����������������� � �������)
	n = InitStdAmulet(n, "indian_1", "pursel",    "ITEMS_3",  1,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0, 	   	     "", 0); //�������� (1) (��� ����)
	n = InitStdAmulet(n, "indian_2", "pursel",    "ITEMS_3",  2,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0, 			 "", 0); //�������� (2) (��� ����)
	n = InitStdAmulet(n, "indian_3", "pursel",    "ITEMS_3",  3,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0, 			 "", 0); // ����������� ���� (1) (��� ����)
	n = InitStdAmulet(n, "indian_4", "pursel",    "ITEMS_3",  4,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0, 			 "", 0); // ����������� ���� (2) (��� ����)
	n = InitStdAmulet(n, "indian_5", "pursel",    "ITEMS_3",  5,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0,    "boatswain", 0); // ������� (��� �������)
	n = InitStdAmulet(n, "indian_6", "pursel",    "ITEMS_3",  6,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0,    "boatswain", 0); // ��������� ���� (1) (��� �������)
	n = InitStdAmulet(n, "indian_7", "pursel",    "ITEMS_3",  7,   rand(150) + 100, 0.5, 0.01, 1, 70, ITEM_INDIAN, 0, 0, 			 "", 0); // ������� (��� ����)
	// ������� ������ ��� ��������
	n = InitStdAmulet(n, "indian_8", "pursel",    "ITEMS_3",  8,   rand(100) +  50, 0.5, 0.01, 1, 50, ITEM_INDIAN, 0, 0,     "cannoner", 0); // �������� (1) (��� ��������)
	n = InitStdAmulet(n, "indian_9", "pursel",    "ITEMS_3",  9,   rand(100) +  50, 0.5, 0.01, 1, 50, ITEM_INDIAN, 0, 0,     "cannoner", 0); // �������� (2) (��� ��������)
	n = InitStdAmulet(n, "indian_10", "pursel",   "ITEMS_3", 10,   rand(100) +  50, 0.5, 0.01, 1, 50, ITEM_INDIAN, 0, 0, 			 "", 0); // �������� (1) (��� ����)
	n = InitStdAmulet(n, "indian_11", "pursel",   "ITEMS_3", 11,   rand(100) +  50, 0.5, 0.01, 1, 50, ITEM_INDIAN, 0, 0, 			 "", 0); // ���������� (1) (��� ����)
	
	// ������� ������ � �������� (����������������� � �������)
	n = InitStdAmulet(n,     "amulet_1", "pursel",    "ITEMS_3", 12,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 			 "", 0); // �������� (3) (��� ����)
	n = InitStdAmulet(n,     "amulet_2", "pursel",    "ITEMS_3", 13,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 			 "", 0); // �������� (4) (��� ����)
	n = InitStdAmulet(n,     "amulet_3", "pursel",    "ITEMS_3", 14,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 			 "", 0); // ����������� ���� (3) (��� ����)
	n = InitStdAmulet(n,     "amulet_4", "pursel",    "ITEMS_3", 15,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 			 "", 0); // ����������� ���� (4) (��� ����)
	n = InitStdAmulet(n,     "amulet_5", "pursel",    "ITEMS_3", 16,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0,     "cannoner", 0); // ������ (��� ��������)
	n = InitStdAmulet(n,     "amulet_6", "pursel",   "ITEMS_20",  1,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 	 		 "", 0); // �������� (2) (��� ����)
	n = InitStdAmulet(n,     "amulet_7", "pursel",   "ITEMS_20",  2,   rand(150) + 100, 0.5, 0.05, 1, 70, ITEM_AMULET, 0, 0, 			 "", 0); // �������� (3) (��� ����)
	// ������� ������ ��� ��������
	n = InitStdAmulet(n,     "amulet_8", "pursel",   "ITEMS_20",  3,   rand(100) +  50, 0.5, 0.05, 1, 50, ITEM_AMULET, 0, 0,    "carpenter", 0); // ������ (1) (��� ��������)
	n = InitStdAmulet(n,     "amulet_9", "pursel",   "ITEMS_20",  4,   rand(100) +  50, 0.5, 0.05, 1, 50, ITEM_AMULET, 0, 0,    "carpenter", 0); // ������ (2) (��� ��������)
	n = InitStdAmulet(n,    "amulet_10", "pursel",   "ITEMS_20",  5,   rand(100) +  50, 0.5, 0.05, 1, 50, ITEM_AMULET, 0, 0,       "doctor", 0); // ������ (3) (��� �����)
	n = InitStdAmulet(n,    "amulet_11", "pursel",   "ITEMS_20",  6,   rand(100) +  50, 0.5, 0.05, 1, 50, ITEM_AMULET, 0, 0,    "boatswain", 0); // ��������� ���� (2) (��� �������)

	
	// ������� ������ 
	n = InitStdAmulet(n,     "obereg_1", "pursel",   "ITEMS_20",  7,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0,    "carpenter", 0); // ������� (1) (��� ��������)
	n = InitStdAmulet(n,     "obereg_2", "pursel",   "ITEMS_20",  8,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0,    "carpenter", 0); // ������� (2) (��� ��������)
	n = InitStdAmulet(n,     "obereg_3", "pursel",   "ITEMS_20",  9,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0, 			 "", 0); // ����������� ��� (��� ����)
	n = InitStdAmulet(n,     "obereg_4", "pursel",   "ITEMS_20", 10,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0, 			 "", 0); // ���������� (2) (��� ����)
	n = InitStdAmulet(n,     "obereg_5", "pursel",   "ITEMS_20", 11,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0, 			 "", 0); // ������� (��� ����)
	n = InitStdAmulet(n,     "obereg_6", "pursel",   "ITEMS_20", 12,   rand(100) +  50, 0.5, 0.05, 1, 30, ITEM_OBEREG, 0, 0, 			 "", 0); // ��������� (��� ����)
	n = InitStdAmulet(n,     "obereg_7", "pursel",   "ITEMS_20", 13,   rand(100) +  50, 0.5, 0.05, 1, 30, ITEM_OBEREG, 0, 0,			 "", 0); // ��������� (��� ����)
	n = InitStdAmulet(n,     "obereg_8", "pursel",   "ITEMS_20", 14,   rand(100) +  50, 0.5, 0.05, 1, 30, ITEM_OBEREG, 0, 0, 			 "", 0); // �������� (��� ����)
	n = InitStdAmulet(n,     "obereg_9", "pursel",   "ITEMS_20", 15,   rand(100) +  50, 0.5, 0.05, 1, 30, ITEM_OBEREG, 0, 0,    "navigator", 0); // �������� (1) (��� ��������)
	n = InitStdAmulet(n,    "obereg_10", "pursel",   "ITEMS_20", 16,   rand(100) +  50, 0.5, 0.05, 1, 45, ITEM_OBEREG, 0, 0,    "navigator", 0); // �������� (2) (��� ��������)
	n = InitStdAmulet(n,    "obereg_11", "pursel",   "ITEMS_21",  1,   rand(100) +  50, 0.5, 0.05, 1, 30, ITEM_OBEREG, 0, 0,    "navigator", 0); // �������� (3) (��� ��������)
	n = InitStdAmulet(n,   "rat_poison", "potion",    "ITEMS_6", 16,   rand(150) + 450, 0.5, 0.05, 1, 60, ITEM_OBEREG, 0, 0,    "treasurer", 0); // ������ (������ ���������)

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//							��������� �����
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "spyglass1"; // ������� ��������� �����
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass1";
	itm.describe = "itmdescr_spyglass1";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_16";
	// boal 19.01.2004 -->
	itm.price = 250;
	itm.Weight = 1;
    // boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.radius = 250.0;
	itm.scope.texture = "eye_BadTub.tga";
	itm.scope.zoom = 2.5;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 0;
	itm.scope.show.sail = 0;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 0;
	itm.scope.show.mushketshot = 0;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass2"; // ������� ��������� �����
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass2";
	itm.describe = "itmdescr_spyglass2";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_16";
	// boal 19.01.2004 -->
	itm.price = 1500;
	itm.Weight = 1.5;
    // boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.radius = 500.0;
	itm.scope.texture = "eye_CommonTub.tga";
	itm.scope.zoom = 4.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 0;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 0;
	itm.scope.show.mushketshot = 0;
	itm.minlevel = 1;
	itm.rare = 0.07;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass3"; // ������� ��������� �����
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass3";
	itm.describe = "itmdescr_spyglass3";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_16";
	itm.price = 4500;
	// boal 19.01.2004 -->
	itm.Weight = 2;
    // boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.radius = 750.0;
	itm.scope.texture = "eye_GoodTub.tga";
	itm.scope.zoom = 7.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 0;
	itm.scope.show.mushketshot = 1;
	itm.minlevel = 1;
	itm.rare = 0.05;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass4"; // �������� ��������� �����
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass4";
	itm.describe = "itmdescr_spyglass4";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_47";
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.radius = 1000.0;
	itm.price = 12000;
	// boal 19.01.2004 -->
	itm.Weight = 2.5;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 10.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 0;
	itm.scope.show.mushketshot = 1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "spyglass5"; // ����������� ��������
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass5";
	itm.describe = "itmdescr_spyglass5";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_47";
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.price = 50000;
	// boal 19.01.2004 -->
	itm.Weight = 4.0;
	itm.radius = 1500.0;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 15.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 1;
	itm.scope.show.mushketshot = 1;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass6"; // ������������ ��������� �����
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass6";
	itm.describe = "itmdescr_spyglass6";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_15";
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.price = 20000;
	// boal 19.01.2004 -->
	itm.Weight = 3.0;
	itm.radius = 1250.0;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 13.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 1;
	itm.scope.show.mushketshot = 1;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "spyglass7"; // ������������ ��������
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "itmname_spyglass7";
	itm.describe = "itmdescr_spyglass7";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_15";
	itm.folder = "items";
	itm.model = "spyglass4";
	itm.price = 75000;
	// boal 19.01.2004 -->
	itm.Weight = 5.0;
	itm.radius = 1750.0;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 18.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 1;
	itm.scope.show.mushketshot = 1;
	itm.minlevel = 1;
	itm.rare = 0.00001;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//							������������� �����������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	makeref(itm,Items[n]); //�������� ����
	itm.id = "sand_clock";
	itm.name = "itmname_sand_clock";
	itm.describe = "itmdescr_sand_clock";
	itm.model = "";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_23";
	itm.price = 400;
	itm.Weight = 1.0;
	itm.minlevel = 2;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); //����������
	itm.id = "astrolab";
	itm.name = "itmname_astrolab";
	itm.describe = "itmdescr_astrolab";
	itm.model = "";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_23";
	itm.price = 4000;
	itm.Weight = 1.5;
	itm.minlevel = 3;
	itm.rare = 0.005;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); //����������� ������
	itm.id = "compass1";
	itm.name = "itmname_compass1";
	itm.describe = "itmdescr_compass1";
	itm.model = "";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_23";
	itm.price = 2000;
	itm.Weight = 0.5;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); //������������������ ���������
	itm.id = "clock1";
	itm.name = "itmname_clock1";
	itm.describe = "itmdescr_clock1";
	itm.model = "";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_23";
	itm.price = 10000;
	itm.Weight = 1.0;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); //������������ ��������
	itm.id = "sextant1";
	itm.name = "itmname_sextant1";
	itm.describe = "itmdescr_sextant1";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_23";
	itm.price = 25000;
	itm.Weight = 2.0;
	itm.ItemType = "QUESTITEM";
	n++;
	
	makeref(itm,Items[n]); //���������������� ���������
	itm.id = "clock2";
	itm.groupID	= ITEM_SLOT_TYPE;
	itm.name = "itmname_clock2";
	itm.describe = "itmdescr_clock2";
	itm.model = "";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_23";
	itm.price = 10000;
	itm.Weight = 1.0;
	itm.longitude = true; // ��������� ���������� ������� 
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.time			= 30;
	itm.ItemType 		= "ARTEFACT";
	itm.Type			= ITEM_OBEREG;	
	itm.TradeType 		= ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); //�������
	itm.id = "bussol";
	itm.groupID	= TOOL_ITEM_TYPE;
	itm.name = "itmname_bussol";
	itm.describe = "itmdescr_bussol";
	itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_23";
	itm.price = 30000;
	itm.Weight = 2.0;
	itm.latitude = true; // ��������� ���������� ������
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType 		= "SUPPORT";
	itm.TradeType 		= ITEM_TRADE_AMMUNITION;
	itm.kind			= "navigator";
	n++;
	
	makeref(itm,Items[n]); //��������� ������
	itm.id = "clock3";
	itm.name = "itmname_clock3";
	itm.describe = "itmdescr_clock3";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_23";
	itm.price = 30000;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEM";
	n++;
	
	makeref(itm,Items[n]); //  ��������� ��������
	itm.id = "sextant2";
	itm.groupID	= TOOL_ITEM_TYPE;
	itm.name = "itmname_sextant2";
	itm.describe = "itmdescr_sextant2";
	itm.model = "";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_23";
	itm.price = 50000;
	itm.Weight = 3.0;
	itm.longitude = true; // ��������� ���������� ������� 
	itm.latitude = true; // ��������� ���������� ������
	itm.multiobject = true;	
	itm.multiobject.alchemy = false;	
	itm.multiobject.qty = 1;
	itm.ItemType 		= "QUESTITEM";
	n++;

	makeref(itm,Items[n]); //  ��������� ��������
	itm.id = "sextant3";
	itm.groupID	= TOOL_ITEM_TYPE;
	itm.name = "itmname_sextant3";
	itm.describe = "itmdescr_sextant3";
	itm.model = "sextant2";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_23";
	itm.price = 50000;
	itm.Weight = 3.0;
	itm.longitude = true; // ��������� ���������� ������� 
	itm.latitude = true; // ��������� ���������� ������
	itm.multiobject = true;	
	itm.multiobject.alchemy = false;	
	itm.multiobject.qty = 1;
	itm.ItemType 		= "QUESTITEM";
	n++;
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//							������� � �����
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "potion1";
	itm.name = "itmname_potion1";
	itm.describe = "itmdescr_potion1";
	itm.model = "potion";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_19";
	itm.price = 100;
	itm.Weight = 0.8;
	itm.potion.pic = 21;
	itm.potion.tex = 0; 
	itm.potion.health = 40.0;
	itm.potion.penalty = 0.1;
	itm.minlevel = 0;
	itm.rare = 0.3;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion2";
	itm.name = "itmname_potion2";
	itm.describe = "itmdescr_potion2";
	itm.model = "potionbig";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_19";
	itm.price = 500;
	itm.Weight = 1;
	itm.potion.pic = 22;
	itm.potion.tex = 0; 
	itm.potion.health = 150.0;
	itm.potion.health.speed = 8; // �������� ���������
	itm.potion.penalty = 0.3;
	itm.minlevel = 1;
	itm.rare = 0.005;
	itm.SortIndex = 2;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion3";
	itm.name = "itmname_potion3";
	itm.describe = "itmdescr_potion3";
	itm.model = "Antidote";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_19";
	itm.price = 200;
	itm.Weight = 0.4;
	itm.potion.pic = 23;
	itm.potion.tex = 0; 
	itm.potion.antidote = true;
	itm.potion.penalty = 0.2;
	itm.minlevel = 1;
	itm.rare = 0.001;	
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion4";
	itm.name = "itmname_potion4";
	itm.describe = "itmdescr_potion4";
	itm.model = "balsam";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_19";
	itm.price = 900;
	itm.Weight = 0.4;
	itm.potion.pic = 24;
	itm.potion.tex = 0; 
	itm.potion.health = 130.0;
	itm.potion.health.speed = 8; // �������� ���������
	itm.potion.antidote = true;
	itm.potion.penalty = 0.4;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

//-----------ADDED BY VERRUCKT BROTHEL MOD------------------
	makeref(itm,Items[n]);
	itm.id = "potionrum";
	itm.name = "itmname_potionrum";
	itm.describe = "itmdescr_potionrum";
    itm.model = "vodka";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_19";
	itm.price = 150;
	itm.Weight = 2;
	itm.potion.pic = 25;
	itm.potion.tex = 0; 
	itm.potion.health = 50.0;
	itm.potion.antidote = true;
	//navy -->
	itm.potion.drunk = 51;
	itm.potion.drunk.time = 5600;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potionwine";
	itm.name = "itmname_potionwine";
	itm.describe = "itmdescr_potionwine";
    itm.model = "balsam";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_19";
	itm.price = 500;
	itm.Weight = 1;
	itm.potion.pic = 26;
	itm.potion.tex = 0; 
	itm.potion.health = 175.0;
	itm.potion.health.speed = 7; // �������� ���������
	//navy -->
	itm.potion.drunk = 15;
	itm.potion.drunk.time = 8000;
	//<--
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

    makeref(itm,Items[n]);
	itm.id = "potion5";
	itm.name = "itmname_potion5";
	itm.describe = "itmdescr_potion5";
    itm.model = "balsam";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_19";
	itm.price = 30;
	itm.Weight = 0.4;
	itm.potion.pic = 27;
	itm.potion.tex = 0; 
	itm.potion.health = 25.0;
	itm.minlevel = 1;
	itm.rare = 0.2;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;

	makeref(itm,Items[n]);
	itm.id = "potion6";
	itm.name = "itmname_potion6";
	itm.describe = "itmdescr_potion6";
    itm.model = "balsam";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_19";
	itm.price = 3000;
	itm.Weight = 0.2;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_POTION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "potion7";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_potion7";
	itm.describe = "itmdescr_potion7";
    itm.model = "balsam";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_19";
	itm.price = 8000;
	itm.Weight = 0.2;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "Ultimate_potion";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_Ultimate_potion";
	itm.describe = "itmdescr_Ultimate_potion";
    itm.model = "balsam";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_35";
	itm.price = 15000;
	itm.Weight = 2;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "berserker_potion";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_berserker_potion";
	itm.describe = "itmdescr_berserker_potion";
    itm.model = "balsam";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_35";
	itm.price = 5000;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "mangarosapower";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_mangarosapower";
	itm.describe = "itmdescr_mangarosapower";
    itm.model = "balsam";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_35";
	itm.price = 8000;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "mangarosafast";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_mangarosafast";
	itm.describe = "itmdescr_mangarosafast";
    itm.model = "balsam";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_35";
	itm.price = 8000;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "mangarosatotal";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_mangarosatotal";
	itm.describe = "itmdescr_mangarosatotal";
    itm.model = "balsam";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_35";
	itm.price = 8000;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.SortIndex = 2;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]); // ����� �� �������� �����
	itm.id = "fennisgrasstotal";
	itm.groupID		= SPECIAL_ITEM_TYPE;
	itm.name = "itmname_fennisgrasstotal";
	itm.describe = "itmdescr_fennisgrasstotal";
     itm.model = "";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_35";
	itm.price = 120;
	itm.Weight = 0.1;
	itm.usepowder = false;
	itm.minlevel = 0;
	itm.rare = 0.001;
	itm.SortIndex = 1;
	itm.multiobject = true;		
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_NORMAL;
	n++;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Jason: �������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// InitStdRecipies(������, ��, ������, ����);
	// ���������� ��������� recipe_ ����� �� ��� ����� ��������� ��� �� ����� - ��� ����������� ��� ���������
	// �������, ������� - ���� ���������� ��� ���������, �������� ������, ������� � ��������� - ���� ��� ����� ������, ������� ��� ������ - ���� �����
	n = InitStdRecipies(n, "recipe_powder_pellet", "powder_pellet", 3500);
	n = InitStdRecipies(n, "recipe_grenade", "grenade", 3500);
	n = InitStdRecipies(n, "recipe_harpoon", "harpoon", 2000);
	n = InitStdRecipies(n, "recipe_GunEchin", "GunEchin", 10000);
	n = InitStdRecipies(n, "recipe_potion2", "potion2", 7000);
	n = InitStdRecipies(n, "recipe_potion3", "potion3", 5000);
	n = InitStdRecipies(n, "recipe_berserker_potion", "berserker_potion", 12000);
	n = InitStdRecipies(n, "recipe_totem_01", "totem_01", 22000);
	n = InitStdRecipies(n, "recipe_totem_02", "totem_02", 21000);
	n = InitStdRecipies(n, "recipe_totem_03", "totem_03", 22500);
	n = InitStdRecipies(n, "recipe_totem_04", "totem_04", 25000);
	n = InitStdRecipies(n, "recipe_totem_05", "totem_05", 24000);
	n = InitStdRecipies(n, "recipe_totem_06", "totem_06", 21800);
	n = InitStdRecipies(n, "recipe_totem_07", "totem_07", 24100);
	n = InitStdRecipies(n, "recipe_totem_08", "totem_08", 25000);
	n = InitStdRecipies(n, "recipe_totem_09", "totem_09", 22700);
	n = InitStdRecipies(n, "recipe_totem_10", "totem_10", 21900);
	n = InitStdRecipies(n, "recipe_totem_11", "totem_11", 24500);
	n = InitStdRecipies(n, "recipe_totem_12", "totem_12", 23400);
	n = InitStdRecipies(n, "recipe_totem_13", "totem_13", 21600);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					���������� ������� � ���������
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//InitStdTalisman(������, �������������, ������, ��������, ������ ��������, ����, ���, ��� �������);
	n = InitStdTalisman(n, "talisman1", "", "ITEMS_21", 15, rand(5000), 0.5, 	 "treasurer"); // ��������
	n = InitStdTalisman(n, "talisman2", "", "ITEMS_21", 16, rand(5000), 0.5,  	 "navigator"); // �����������
	n = InitStdTalisman(n, "talisman3", "", "ITEMS_22",  1, rand(5000), 0.5,      "cannoner"); // �����������
	n = InitStdTalisman(n, "talisman4", "", "ITEMS_22",  4, rand(5000), 0.5,     "boatswain"); // ��� �������
	n = InitStdTalisman(n, "talisman6", "", "ITEMS_22",  5, rand(5000), 0.5,        "doctor"); // ��� ����������
	n = InitStdTalisman(n, "talisman7", "", "ITEMS_22",  3, rand(5000), 0.5,     "carpenter"); // ������� ���������� :)
	n = InitStdTalisman(n, "talisman8", "", "ITEMS_22",  2, rand(5000), 0.5,       "fighter"); // ��� ������ ����� - ��������������
	n = InitStdTalisman(n, "DOjeronRing", "RingJew", "ITEMS_24",  4, rand(5000), 0.5,       "fighter"); // ��� ������ ����� - �������������� � ������ ����
	n = InitStdTalisman(n, "talisman9", "", "ITEMS_5",  11, rand(5000), 0.5,       "treasurer"); // ��������
	n = InitStdTalisman(n, "DeSouzaCross", "sapphire", "ITEMS_12",  5, rand(5000), 0.3,       "fighter"); //����� ������� �� �����
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					��������� ������� � �������������
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	//InitStdItem( ������, �������������, ������, ��������, ������ ��������, ��������, ���. �������, ����, ���� � ��������, ���, ���)
	// �����
	n = InitStdItem( n,   "jewelry1", 	  "sapphire", "ITEMS_28",  15,   0.10,   1,   400,   4,  0.1,   ITEM_TRADE_JEWELRY); // �������
	n = InitStdItem( n,   "jewelry2",      "diamond", "ITEMS_28",   3,   0.05,   1,   700,   7,  0.1,   ITEM_TRADE_JEWELRY); // �����
	n = InitStdItem( n,   "jewelry3",         "ruby", "ITEMS_28",  11,   0.10,   0,   550,   6,  0.1,   ITEM_TRADE_JEWELRY); // �����
	n = InitStdItem( n,   "jewelry4",      "emerald", "ITEMS_28",  14,   0.10,   0,   500,   5,  0.1,   ITEM_TRADE_JEWELRY); // �������
	n = InitStdItem( n,   "jewelry5",     "sapphire", "ITEMS_28",   5,   0.05,   1,   250,   3,  0.5,   ITEM_TRADE_JEWELRY); // ������� ���������
	n = InitStdItem( n,   "jewelry6",     "sapphire", "ITEMS_28",   9,   0.10,   0,   150,   2,  0.4,   ITEM_TRADE_JEWELRY); // ���������� ���������	
	n = InitStdItem( n,   "jewelry7",       "pursel", "ITEMS_28",   1, 0.0001,   1,  1500,  15,  0.1,   ITEM_TRADE_JEWELRY); // ������� ������
	n = InitStdItem( n,   "jewelry8",       "pursel", "ITEMS_28",   2, 0.0001,   1,   450,   5,  0.1,   ITEM_TRADE_JEWELRY); // ������
	n = InitStdItem( n,   "jewelry9",       "pursel", "ITEMS_28",   4, 0.0001,   1,   200,   2,  0.1,   ITEM_TRADE_JEWELRY); // ������
	n = InitStdItem( n,  "jewelry10",       "pursel", "ITEMS_28",   6, 0.0001,   1,   220,   2,  0.1,   ITEM_TRADE_JEWELRY); // ���������� ���������
	n = InitStdItem( n,  "jewelry11",       "pursel", "ITEMS_28",   7, 0.0001,   1,   1500, 15,  1.1,   ITEM_TRADE_JEWELRY); // ������� ���������
	n = InitStdItem( n,  "jewelry12",       "pursel", "ITEMS_28",   8, 0.0001,   1,   150,   2,  0.3,   ITEM_TRADE_JEWELRY); // ������ ���������
	n = InitStdItem( n,  "jewelry13",       "pursel", "ITEMS_28",  10, 0.0001,   1,   150,   2,  0.5,   ITEM_TRADE_JEWELRY); // �������� ���������
	n = InitStdItem( n,  "jewelry14",       "pursel", "ITEMS_28",  12, 0.0001,   1,   180,   2,  0.1,   ITEM_TRADE_JEWELRY); // �������� ����
	n = InitStdItem( n,  "jewelry15",       "pursel", "ITEMS_28",  13, 0.0001,   1,   170,   2,  0.1,   ITEM_TRADE_JEWELRY); // ���������
	n = InitStdItem( n,  "jewelry16",       "pursel", "ITEMS_28",  16, 0.0001,   1,   350,   4,  0.1,   ITEM_TRADE_JEWELRY); // ����	
	n = InitStdItem( n,  "jewelry17",       "pursel", "ITEMS_29",   1,  0.001,   1,   300,   3,  0.1,   ITEM_TRADE_JEWELRY); // �������
	n = InitStdItem( n,  "jewelry18",       "pursel", "ITEMS_29",   2,  0.001,   1,   200,   2,  0.1,   ITEM_TRADE_JEWELRY); // ���������
	n = InitStdItem( n,  "jewelry19",       "pursel", "ITEMS_29",   3,  0.001,   1,   200,   2,  0.1,   ITEM_TRADE_JEWELRY); // ������
	n = InitStdItem( n,  "jewelry20",       "pursel", "ITEMS_29",   4,  0.001,   1,   400,   4,  0.1,   ITEM_TRADE_JEWELRY); // ������
	n = InitStdItem( n,  "jewelry21",       "pursel", "ITEMS_29",   5,  0.001,   1,   300,   3,  0.1,   ITEM_TRADE_JEWELRY); // �������
	n = InitStdItem( n,  "jewelry22",       "pursel", "ITEMS_29",   6,  0.001,   1,   250,   3,  0.1,   ITEM_TRADE_JEWELRY); // ������
	n = InitStdItem( n,  "jewelry23",       "pursel", "ITEMS_29",   7,  0.001,   1,   200,   2,  0.1,   ITEM_TRADE_JEWELRY); // �����������
	
	// ��������� ������� ���������
	n = InitStdItem( n,  "jewelry24",       "pursel", "ITEMS_24",   1, 0.0001,   1,     0,  50,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry25",       "pursel", "ITEMS_24",   2, 0.0001,   1,     0,  60,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry26",       "pursel", "ITEMS_24",   3, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry27",       "pursel", "ITEMS_24",   4, 0.0001,   1,     0,  50,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry28",       "pursel", "ITEMS_24",   5, 0.0001,   1,     0,  60,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry29",       "pursel", "ITEMS_24",   6, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry30",       "pursel", "ITEMS_24",   7, 0.0001,   1,     0,  50,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry31",       "pursel", "ITEMS_24",   8, 0.0001,   1,     0,  60,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry32",       "pursel", "ITEMS_24",   9, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry33",       "pursel", "ITEMS_24",  10, 0.0001,   1,     0,  50,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry34",       "pursel", "ITEMS_24",  11, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry35",       "pursel", "ITEMS_24",  12, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry36",       "pursel", "ITEMS_24",  13, 0.0001,   1,     0,  50,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry37",       "pursel", "ITEMS_24",  14, 0.0001,   1,     0,  60,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry38",       "pursel", "ITEMS_24",  15, 0.0001,   1,     0,  70,  0.2,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry39",       "pursel", "ITEMS_24",  16, 0.0001,   1,     0,  80,  0.2,   ITEM_TRADE_JEWELRY); 
	
	// ��������� ���������
	n = InitStdItem( n,  "jewelry40",       "pursel", "ITEMS_25",   1,   0.05,   1,   350,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry41",       "pursel", "ITEMS_25",   2,   0.05,   1,   300,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry42",       "pursel", "ITEMS_25",   3,   0.05,   1,   250,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry43",       "pursel", "ITEMS_25",   4,   0.05,   1,   280,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry44",       "pursel", "ITEMS_25",   5,   0.10,   1,   170,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry45",       "pursel", "ITEMS_25",   6,   0.20,   1,   150,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry46",       "pursel", "ITEMS_25",   7,   0.10,   1,    80,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry47",       "pursel", "ITEMS_25",   8,   0.20,   1,   130,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry48",       "pursel", "ITEMS_25",   9,   0.15,   1,   210,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry49",       "pursel", "ITEMS_25",  10,   0.25,   1,    90,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry50",       "pursel", "ITEMS_25",  11,   0.10,   1,   140,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry51",       "pursel", "ITEMS_25",  12,   0.10,   1,   240,   0,  0.1,   ITEM_TRADE_JEWELRY); 
	n = InitStdItem( n,  "jewelry52",     "pearlbig", "ITEMS_31",  10,   0.10,   0,    90,   0,  0.3,   ITEM_TRADE_JEWELRY);
	n = InitStdItem( n,  "jewelry53",   "pearlsmall", "ITEMS_31",   9,   0.20,   0,    40,   0,  0.1,   ITEM_TRADE_JEWELRY);





	n = InitStdItem( n,  "jewelry100",       "pursel", "ITEMS_53",  4, 0.05,   1,   40,   2,  7.1,   ITEM_TRADE_JEWELRY); // ������ ������
	n = InitStdItem( n,   "jewelry101",     "sapphire", "ITEMS_53",   7,   0.05,   1,   130,   2,  6.4,   ITEM_TRADE_JEWELRY); // ������ �����	
	n = InitStdItem( n,  "jewelry102",       "pursel", "ITEMS_53",   8,  0.05,   1,   2,   2,  3.6,   ITEM_TRADE_JEWELRY); // �����
	n = InitStdItem( n,  "jewelry103",       "pursel", "ITEMS_53",  1, 0.05,   1,   20,   2,  5.5,   ITEM_TRADE_JEWELRY); // �������� ����
	n = InitStdItem( n,   "jewelry104",     "sapphire", "ITEMS_53",   2,   0.05,   1,   450,   2,  4.4,   ITEM_TRADE_JEWELRY); // ���������� ����	
	n = InitStdItem( n,   "jewelry105",     "sapphire", "ITEMS_53",   3,   0.05,   1,   1050,   3,  2.5,   ITEM_TRADE_JEWELRY); // ������� ����
	n = InitStdItem( n,   "jewelry106",     "sapphire", "ITEMS_53",   6,   0.05,   1,   5250,   3,  1.0,   ITEM_TRADE_JEWELRY); // ������� ������
	n = InitStdItem( n,   "jewelry107",     "sapphire", "ITEMS_53",   5,   0.05,   1,   750,   3,  1.0,   ITEM_TRADE_JEWELRY); // ���������� ������
	n = InitStdItem( n,   "jewelry108",     "sapphire", "ITEMS_53",   2,   0.05,   1,   750,   3,  1.0,   ITEM_TRADE_JEWELRY); // ���������� ����
	n = InitStdItem( n,   "jewelry109",     "sapphire", "ITEMS_53",   5,   0.05,   1,   750,   3,  1.0,   ITEM_TRADE_JEWELRY); // ���������� ������
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					���������� ��� �������������� ������
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    makeref(itm,Items[n]); 
	itm.id = "bullet"; // ���� 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_bullet"; 
	itm.describe = "itmdescr_bullet";
	itm.model = "pursel";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_18";
	itm.price = 4;
	itm.Weight = 0.1;
	itm.usepowder = true;
	itm.minlevel =0;
	itm.rare = 0.3;
	itm.SortIndex = 1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "shotgun_bullet"; // ������������ ����
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_shotgun_bullet"; 
	itm.describe = "itmdescr_shotgun_bullet";
	itm.model = "pursel";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_18";
	itm.price = 4;
	itm.Weight = 0.1;
	itm.usepowder = true;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������
	itm.id = "grapeshot"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_grapeshot";
	itm.describe = "itmdescr_grapeshot";
	itm.model = "pursel";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_18";
	itm.price = 40;
	itm.Weight = 0.1;
	itm.usepowder = true;
	itm.minlevel =0;
	itm.rare = 0.01;
	itm.SortIndex = 1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������� ������
	itm.id = "cartridge"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_cartridge";
	itm.describe = "itmdescr_cartridge";
	itm.model = "pursel";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_18";
	itm.price = 100;
	itm.Weight = 0.1;
	itm.usepowder = false;
	itm.minlevel = 0;
	itm.rare = 0.001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������
	itm.id = "powder_pellet"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_powder_pellet";
	itm.describe = "itmdescr_powder_pellet";
	itm.model = "pursel";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_18";
	itm.price = 200;
	itm.Weight = 0.5;
	itm.usepowder = false;
	itm.minlevel = 0;
	itm.rare = 0.001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������
	itm.id = "grenade"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_grenade";
	itm.describe = "itmdescr_grenade";
	itm.model = "pursel";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_18";
	itm.price = 400;
	itm.Weight = 0.5;
	itm.usepowder = false;
	itm.minlevel = 0;
	itm.rare = 0.001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // ������
	itm.id = "harpoon"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_harpoon";
	itm.describe = "itmdescr_harpoon";
	itm.model = "pursel";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_18";
	itm.price = 500;
	itm.Weight = 1.0;
	itm.usepowder = true;
	itm.minlevel = 0;
	itm.rare = 0.01;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // Warship. �����
	itm.id = "GunPowder";
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_GunPowder";
	itm.describe = "itmdescr_GunPowder";
	itm.model = "pursel";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_18";
	itm.Weight = 0.1;
	itm.price = 8;
	itm.minlevel =0;
	itm.rare = 0.3;
	itm.SortIndex = 1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	/*makeref(itm,Items[n]); // ����� ��� ������
	itm.id = "GunPowder_colt";
	itm.name = "itmname_GunPowder_colt";
	itm.describe = "itmdescr_GunPowder_colt";
	itm.model = "pursel";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_18";
	//itm.shown = 0;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	itm.price = 8;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.3;
	itm.SortIndex = 1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;*/
	
	makeref(itm,Items[n]); // ������� ��� ������
	itm.id = "GunCap_colt"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_GunCap_colt";
	itm.describe = "itmdescr_GunCap_colt";
	itm.model = "pursel";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_18";
	itm.price = 20;
	itm.Weight = 0.1;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 20;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������� ��� ������
	itm.id = "shotgun_cartridge"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_shotgun_cartridge";
	itm.describe = "itmdescr_shotgun_cartridge";
	itm.model = "pursel";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_33";
	itm.price = 100;
	itm.Weight = 0.1;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // ������ �����
	itm.id = "GunEchin"; 
	itm.groupID = AMMO_ITEM_TYPE;
	itm.name = "itmname_GunEchin";
	itm.describe = "itmdescr_GunEchin";
	itm.model = "pursel";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_18";
	itm.price = 50;
	itm.Weight = 0.4;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = false;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	makeref(itm,Items[n]); // �������� �������
	itm.id = "OxyHydSilver";
	itm.name = "itmname_OxyHydSilver";
	itm.describe = "itmdescr_OxyHydSilver";
	itm.model = "pursel";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_29";
	itm.Weight = 0.1;
	itm.price = 30;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.SortIndex = 1;
	itm.multiobject = true;
	itm.multiobject.qty = 1;
	itm.multiobject.alchemy = true;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	n++;
	
	// ���������� ��� �������������� ������
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					������ ��������
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	makeref(itm,Items[n]); //���������� �����
	itm.id = "tailor_tool";
	itm.name = "itmname_tailor_tool";
	itm.describe = "itmdescr_tailor_tool";
	itm.model = "";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_18";
	itm.price = 1200;
	itm.Weight = 1.0;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_NORMAL;
	n++;
	
	makeref(itm,Items[n]); //��������� �����
	itm.id = "mechanic_tool";
	itm.name = "itmname_mechanic_tool";
	itm.describe = "itmdescr_mechanic_tool";
	itm.model = "";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_18";
	itm.price = 1500;
	itm.Weight = 5.0;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_NORMAL;
	n++;
	
	makeref(itm,Items[n]); //������
	itm.id = "tigel";
	itm.name = "itmname_tigel";
	itm.describe = "itmdescr_tigel";
	itm.model = "";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_31";
	itm.price = 2000;
	itm.Weight = 2.0;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_NORMAL;
	n++;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//					������ ����� 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	//InitStdItem( ������, �������������, ������, ��������, ������ ��������, ��������, ���. �������, ����, ���, ���)
	n = InitStdItem( n,   "mineral1", 	  "pursel", "ITEMS_31",  5,   0.20,   1,     5, 0,   2.0,   ITEM_TRADE_NORMAL); // ������ ������
	n = InitStdItem( n,   "mineral2", 	  "pursel", "ITEMS_30",  5,   0.02,   0,   130, 0,   0.1,   ITEM_TRADE_NORMAL); // ����������� �������
	n = InitStdItem( n,   "mineral3", 	"sapphire", "ITEMS_31",  4,   0.05,   0,    10, 0,   1.0,   ITEM_TRADE_NORMAL); // �����
	n = InitStdItem( n,   "mineral4", 	  "pursel", "ITEMS_31",  1,   0.05,   0,    25, 0,   2.0,   ITEM_TRADE_NORMAL);	// ���-��������
	n = InitStdItem( n,   "mineral5", 	  "pursel", "ITEMS_30",  3,   0.02,   0,    40, 0,   3.0,   ITEM_TRADE_NORMAL);	// ��������� ��������
	n = InitStdItem( n,   "mineral6", 	  "pursel", "ITEMS_30",  6,   0.40,   0,    20, 0,   1.0,   ITEM_TRADE_NORMAL); // ���������
	n = InitStdItem( n,   "mineral7", 	  "pursel", "ITEMS_30",  7,   0.20,   0,   140, 0,   0.8,   ITEM_TRADE_NORMAL);	// ���������� ������
	n = InitStdItem( n,   "mineral8", 	  "pursel", "ITEMS_29", 16,   0.05,   4,    30, 0,   1.0,   ITEM_TRADE_NORMAL);	// ������
	n = InitStdItem( n,   "mineral9", 	  "pursel", "ITEMS_30", 10,   0.10,   2,    80, 0,   1.0,   ITEM_TRADE_NORMAL);	// ������
                n = InitStdItem( n,  "mineral10", 	  "pursel", "ITEMS_30", 16,   0.10,   0,     4, 0,   1.0,   ITEM_TRADE_NORMAL);	// ������
                n = InitStdItem( n,  "mineral010", 	  "pursel", "ITEMS_38", 16,   0.10,   0,     4, 0,   1.0,   ITEM_TRADE_NORMAL);	// ������� ����
	n = InitStdItem( n,  "mineral11", 	"sapphire", "ITEMS_31", 11,   0.07,   4,   220, 0,   0.6,   ITEM_TRADE_NORMAL);	// ���������� ������
	n = InitStdItem( n,  "mineral12", 	"sapphire", "ITEMS_30", 14,   0.03,   5,    60, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������ ������
	n = InitStdItem( n,  "mineral13", 	  "pursel", "ITEMS_30", 12,   0.10,   1,    40, 0,   0.3,   ITEM_TRADE_NORMAL);	// ������
	n = InitStdItem( n,  "mineral14", 	  "pursel", "ITEMS_29", 14,   0.05,   3,    55, 0,   3.0,   ITEM_TRADE_NORMAL);	// ����� �������
	n = InitStdItem( n,  "mineral15", 	  "pursel", "ITEMS_30", 11,   0.05,   1,    30, 0,   0.1,   ITEM_TRADE_NORMAL);	// �������� ���
	n = InitStdItem( n,  "mineral16", 	  "pursel", "ITEMS_31",  8,   0.05,   1,    45, 0,   0.3,   ITEM_TRADE_NORMAL);	// ������
	n = InitStdItem( n,  "mineral17", 	  "elixir", "ITEMS_19", 16,   0.05,   1,    45, 0,   0.3,   ITEM_TRADE_NORMAL);	//������ ���������� ������
	n = InitStdItem( n,  "mineral18", 	  "elixir", "ITEMS_31",  7,   0.05,   1,   120, 0,   0.4,   ITEM_TRADE_NORMAL);	// ������� � ����������� �������		
	n = InitStdItem( n,  "mineral19", 	        "", "ITEMS_30",  4,   0.05,   1,    90, 0,   0.1,   ITEM_TRADE_NORMAL);	// ���������� �����		
	n = InitStdItem( n,  "mineral20", 	        "", "ITEMS_30", 13,   0.05,   1,    40, 0,   0.1,   ITEM_TRADE_NORMAL);	// ���������� �����			
	n = InitStdItem( n,  "mineral21", 	        "", "ITEMS_30",  2,   0.05,   1,   100, 0,   0.1,   ITEM_TRADE_NORMAL);	// ���������� ��������������		
	n = InitStdItem( n,  "mineral22", 	  "pursel", "ITEMS_31",  2,   0.07,   1,    20, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������	
	n = InitStdItem( n,  "mineral23", 	  "pursel", "ITEMS_31",  3,   0.03,   1,     5, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������	
	n = InitStdItem( n,  "mineral24", 	  "pursel", "ITEMS_30", 15,   0.10,   1,    40, 0,   0.2,   ITEM_TRADE_NORMAL);	// ������	
	n = InitStdItem( n,  "mineral25", 	  "pursel", "ITEMS_30",  9,   0.05,   2,    45, 0,   0.2,   ITEM_TRADE_NORMAL);	// ���������� �����	
	n = InitStdItem( n,  "mineral26", 	  "pursel", "ITEMS_30",  8,   0.05,   1,    30, 0,   0.1,   ITEM_TRADE_NORMAL);	// ��������� �����	
	n = InitStdItem( n,  "mineral27", 	  "pirsel", "ITEMS_29", 10,   0.05,   1,    60, 0,   0.3,   ITEM_TRADE_NORMAL);	// ������ � ��������	
	n = InitStdItem( n,  "mineral28", 	  "elixir", "ITEMS_29", 11,   0.05,   1,   140, 0,   0.3,   ITEM_TRADE_NORMAL);	// �������� �����	
	n = InitStdItem( n,  "mineral29", 	  "elixir", "ITEMS_29", 12,   0.05,   1,   170, 0,   0.4,   ITEM_TRADE_NORMAL);	// ������� �������	
	n = InitStdItem( n,  "mineral30", 	  "pursel", "ITEMS_29", 15,   0.01,   1,    80, 0,   0.2,   ITEM_TRADE_NORMAL);	// �������		
	n = InitStdItem( n,  "mineral31", 	  "pursel", "ITEMS_29", 13,   0.01,   1,    70, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������������ �����			
	n = InitStdItem( n,  "mineral32", 	  "pursel", "ITEMS_29",  9, 0.0001,   1,   700, 0,   0.3,   ITEM_TRADE_NORMAL);	// ���������		
	n = InitStdItem( n,  "mineral33", 	  "pursel", "ITEMS_31", 15,   0.01,   1,   120, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������ ��� ����		
	n = InitStdItem( n,  "mineral34", 	  "elixir", "ITEMS_31",  6,   0.05,   1,   100, 0,   0.1,   ITEM_TRADE_NORMAL);	// ������ �������		
	n = InitStdItem( n,  "mineral35", 	        "", "ITEMS_33",  4,   0.01,   1,   220, 0,   6.0,   ITEM_TRADE_NORMAL);	// �����
	n = InitStdItem( n,  "crab_pincers",        "", "ITEMS_35",  8, 0.0001,  20,   300, 0,   3.5,   ITEM_TRADE_NORMAL);	// ������
	n = InitStdItem( n,  "crab_jaw", 	        "", "ITEMS_35",  9, 0.0001,  20,   500, 0,   2.0,   ITEM_TRADE_NORMAL);	// �����
	
	trace("����� ��������� (����������� �������) "+n);
	trace("����� ��������������� ��������� - " + iScriptItemCount);
	trace("��������� ����������� �������: " + Items[ItemsForLocators_start].id);
	trace("�������� ����������� �������: " + Items[ItemsForLocators_end].id);
	
	InitGuns();
	InitMushkets();
	InitMultiObjectAmulets();
	InitItemsRarity();
	
	return n;
}

void InitRandItems()
{
	ref rnditem;

	makeref(rnditem,RandItems[0]);
	rnditem.id = POTION;
	rnditem.maxQuantity = 4;
	
    makeref(rnditem,RandItems[1]);
	rnditem.id = "Mineral9";  
	rnditem.maxQuantity = 2;

	makeref(rnditem,RandItems[2]);
	rnditem.id = "Mineral10";  
	rnditem.maxQuantity = 2;
	
	makeref(rnditem,RandItems[3]);
	rnditem.id = "jewelry16";
	rnditem.maxQuantity = 15;
	
	makeref(rnditem,RandItems[4]);
	rnditem.id = "jewelry1";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[5]);
	rnditem.id = "jewelry2";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[6]);
	rnditem.id = "jewelry3";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[7]);
	rnditem.id = "jewelry5";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[8]);
	rnditem.id = "jewelry6";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[9]);
	rnditem.id = "jewelry40";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[10]);
	rnditem.id = "jewelry41";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[11]);
	rnditem.id = "jewelry42";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[12]);
	rnditem.id = "jewelry43";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[13]);
	rnditem.id = "jewelry44";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[14]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[15]);
	rnditem.id = "mineral1";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[16]);
	rnditem.id = "potion1";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[17]);
	rnditem.id = "mineral17";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[18]);
	rnditem.id = "mineral13";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[19]);
	rnditem.id = "potion3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[20]);
	rnditem.id = "potion4";
	rnditem.maxQuantity = 1;

    // boal -->
	makeref(rnditem,RandItems[21]);
	rnditem.id = "Mineral11"; // Addon-2016 Jason
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[22]);
	rnditem.id = "Mineral19"; // Addon-2016 Jason
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[23]);
	rnditem.id = "cannabis5";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[24]);
	rnditem.id = "slave_01";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[25]);
	rnditem.id = "slave_02";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[26]);
	rnditem.id = "topor_05";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[27]);
	rnditem.id = "blade_03";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[28]);
	rnditem.id = "cannabis4";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[29]);
	rnditem.id = "newblade11";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[30]);
	rnditem.id = "cannabis3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[31]);
	rnditem.id = "jewelry1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[32]);
	rnditem.id = "Mineral19"; // Addon-2016 Jason
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[33]);
	rnditem.id = "blade_07";
	rnditem.maxQuantity = 1;

    makeref(rnditem,RandItems[34]);
	rnditem.id = "jewelry45";
	rnditem.maxQuantity = 4;

    makeref(rnditem,RandItems[35]);
	rnditem.id = "jewelry46";
	rnditem.maxQuantity = 4;

    makeref(rnditem,RandItems[36]);
	rnditem.id = "bullet"; // boal "Mineral1";
	rnditem.maxQuantity = 20;

	makeref(rnditem,RandItems[37]);
	rnditem.id = "mineral3";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[38]);
	rnditem.id = "Mineral4";  
	rnditem.maxQuantity = 1;

    makeref(rnditem,RandItems[39]);
	rnditem.id = "Mineral5";  
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[40]);
	rnditem.id = "Mineral6";  
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[41]);
	rnditem.id = "Mineral7";  
	rnditem.maxQuantity = 1;

    makeref(rnditem,RandItems[42]);
	rnditem.id = "potion5";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[43]);
	rnditem.id = "potionwine";
	rnditem.maxQuantity = 4;

	makeref(rnditem,RandItems[44]);
	rnditem.id = "potionrum";
	rnditem.maxQuantity = 4;
	// boal <--
	makeref(rnditem,RandItems[45]);
	rnditem.id = "cannabis3";  
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[46]);
	rnditem.id = "cannabis1";  
	rnditem.maxQuantity = 1;

    makeref(rnditem,RandItems[47]);
	rnditem.id = "cannabis2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[48]);
	rnditem.id = "cannabis4";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[49]);
	rnditem.id = "cannabis6";
	rnditem.maxQuantity = 1;
	
	makeref(rnditem,RandItems[50]);
	rnditem.id = "jewelry52";
	rnditem.maxQuantity = 4;
	
	makeref(rnditem,RandItems[51]);
	rnditem.id = "jewelry53";
	rnditem.maxQuantity = 7;

	makeref(rnditem,RandItems[52]);
	rnditem.id = "newblade4";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[53]);
	rnditem.id = "newblade3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[54]);
	rnditem.id = "newblade1";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[55]);
	rnditem.id = "newblade2";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[56]);
	rnditem.id = "topor_07";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[57]);
	rnditem.id = "newblade23";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[58]);
	rnditem.id = "pistol_01";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[59]);
	rnditem.id = "mushket_01";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[60]);
	rnditem.id = "pistol3";
	rnditem.maxQuantity = 1;

	makeref(rnditem,RandItems[61]);
	rnditem.id = "BackPack1";
	rnditem.maxQuantity = 1;
}

int InitStdItem( 	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex,
					float	Rare, 
					int 	MinLevel, 
					int		Price, 
					int		PriceDublon, 			
					float 	Weight,
					string  TradeType)
{
	ref	rItem;
	int	itmIndex;
	
	itmIndex = ItemIndex;
	makeref(rItem, Items[itmIndex]);
	
	rItem.id				= id;		
	rItem.model				= ModelID;
	rItem.name				= "itmname_" + id;
	rItem.describe			= "itmdescr_" + id;		
	rItem.picTexture		= picTexture;
	rItem.picIndex			= picIndex;	
	rItem.price				= Price;	
	rItem.rare 				= Rare;
	rItem.minlevel 			= MinLevel;
	rItem.Weight 			= Weight;
	rItem.TradeType 		= TradeType;
	
	if(PriceDublon > 0) 
	{
		rItem.PriceDublon				= PriceDublon;	
	}
	
	itmIndex++;
	return itmIndex;
}					

int InitStdBlade( 	int		ItemIndex, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex,
					string  TargetGroup,
					int     Quality,
					string  BladeType,
					int     BladeNum,
					float   Lenght,
					float   Curve,
					bool    isGenerable,
					int     GenerationQty, 
					bool 	isGenerablePrice,
					int     Price)
{
	ref	blade;
	int	bladeIndex;
	float MaxAttack = 0.0;
	
	bladeIndex = ItemIndex;
	makeref(blade, Items[bladeIndex]);
	
	blade.id				= ModelID;		
	blade.groupID 			= BLADE_ITEM_TYPE;
	blade.model				= ModelID;
	blade.name				= "itmname_" + ModelID;
	blade.describe			= "itmdescr_" + ModelID;		
	blade.folder 			= "items";
	blade.picTexture		= picTexture;
	blade.picIndex			= picIndex;
	blade.param.time 		= 0.1;
	blade.param.colorstart 	= argb(64, 64, 64, 64);
	blade.param.colorend 	= argb(0, 32, 32, 32);
	blade.ItemType 			= "WEAPON";
	blade.lenght 			= Lenght;
	blade.curve				= Curve;
 	blade.FencingType       = BladeType;
	blade.quality			= Quality;
	blade.target			= TargetGroup;
	blade.TradeType 		= ITEM_TRADE_AMMUNITION;
		
	if(isGenerable)				blade.Generation.qty 	= GenerationQty;
	if(isGenerablePrice)    	
	{
		blade.Generation.price 	= true; // ���� "�������� ����"	
	}
	else blade.price 	= Price;	
	
	switch (BladeType) 
	{
		case "FencingL" :
			blade.Weight 	= 2.0 + fRandSmall(1.0); 
			MaxAttack		= FencingL_MaxAttack;
		break;
		case "FencingS" :
			blade.Weight 	= 2.4 + fRandSmall(1.2);
			MaxAttack		= FencingS_MaxAttack;			
		break;
		case "FencingH" :
			blade.Weight 	= 3.0 + fRandSmall(1.5); 
			MaxAttack		= FencingH_MaxAttack;
		break;
	}
	
	blade.Balance = fRandSmall(2.0);
	if(ModelID == "unarmed") blade.Balance = 1.0;
	
	switch (Quality)
	{
		case B_POOR :
			blade.Attack 	= MaxAttack * (42.5 + fRandSmall(15.0))/100.0;			
			blade.rare 	 	= 0.1;
			blade.minlevel 	= 1;
			if(ModelID == "unarmed") blade.Attack = 15.0;
		break;
		case B_ORDINARY :
			blade.Attack 	= MaxAttack * (55.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.01;
			blade.minlevel 	= 1;
		break;
		case B_GOOD :
			blade.Attack 	= MaxAttack * (70.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.001;
			blade.minlevel 	= 10;
			if(TargetGroup == TGT_QUEST) // ��� ���������� ������ ����� ������� �� ���������
			{
				blade.Attack 	= MaxAttack * 0.85;	
			}
		break;
		case B_EXCELLENT :
			blade.Attack 	= MaxAttack * (85.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.0001;
			blade.minlevel 	= 15;
			if(TargetGroup == TGT_QUEST) // ��� ���������� ������ ����� ������� �� ���������
			{
				blade.Attack 	= MaxAttack;	
			}
		break;
	}
	
	switch (BladeType) 
	{
		case "FencingL" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(35.0 * (1.0/Curve + Lenght) * (stf(blade.Attack) * 2.0 - 30.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingS" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(25.0 * (Curve + Lenght) * (stf(blade.Attack) * 2.0 - 40.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingH" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(20.0 * ((Curve + 1.0) * 1.0/Lenght) * (stf(blade.Attack) * 2.0 - 50.0));
			}	
			else blade.price = Price;			
		break;
	}
	
	//trace("blade.id : " + blade.id + " blade.price : " + blade.price + " blade.Attack : " + blade.Attack + " blade.Balance : " + blade.Balance + " blade.Weight : " + blade.Weight);
	
	bladeIndex++;
	return bladeIndex;
}

int InitStdGun(	int		ItemIndex, 
				string 	id, 
				string 	ModelID, 
				string 	picTexture,
				int		picIndex, 
				float	Rare, 
				int 	MinLevel, 
				int		Price, 
				float 	DmgMin, 
				float 	DmgMax, 
				float 	Weight,
				int 	Charges, 
				int 	Quality )
{
	ref	gun;
	int	gunIndex;
	
	gunIndex = ItemIndex;
	makeref(gun, Items[gunIndex]);
	
	gun.id				= id;		
	gun.groupID			= GUN_ITEM_TYPE;
	gun.name			= "itmname_" + id;
	gun.describe		= "itmdescr_" + id;		
	gun.model			= ModelID;
	gun.folder 			= "items";
	gun.chargeQ			= Charges;
	gun.picTexture		= picTexture;
	gun.picIndex		= picIndex;
	gun.dmg_min			= DmgMin;
	gun.dmg_max			= DmgMax;
	gun.price			= Price;	
	gun.ItemType 		= "WEAPON";
	gun.rare 			= Rare;
	gun.quality 		= Quality;
	gun.minlevel 		= MinLevel;
	gun.Weight 			= Weight;
	gun.ChargeSpeed 	= 10.0; // by default
	gun.accuracy 		= 50.0; // by default
	gun.TradeType 		= ITEM_TRADE_AMMUNITION;
	
	gunIndex++;
	return gunIndex;
}

int InitStdTalisman(	int		ItemIndex, 
						string 	id, 
						string 	ModelID, 
						string 	picTexture,
						int		picIndex, 
						int		Price, 
						float 	Weight,
						string	kind 	)
{
	ref	talisman;
	int	talismanIndex;
	
	talismanIndex = ItemIndex;
	makeref(talisman, Items[talismanIndex]);
	
	talisman.id				= id;		
	talisman.groupID		= TALISMAN_ITEM_TYPE;
	talisman.name			= "itmname_" + id;
	talisman.describe		= "itmdescr_" + id;		
	talisman.model			= ModelID;
	talisman.picTexture		= picTexture;
	talisman.picIndex		= picIndex;
	talisman.price			= Price + 10000;	
	talisman.rare 			= 0.0001;
	talisman.minlevel 		= 1;
	talisman.Weight 		= Weight;
	talisman.unique			= true;	
	talisman.ItemType 		= "ARTEFACT";
	talisman.kind			= kind;
	talisman.TradeType 		= ITEM_TRADE_JEWELRY;
	
	talismanIndex++;
	return talismanIndex;
}

int InitStdAmulet(	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex, 
					int		Price, 
					float 	Weight,
					float	Rare, 
					int 	MinLevel, 
					int		Time,
					string  Type,
					bool	isMulti,
					int     outQty,
					string	kind,
					bool    reqAlchemy )
{
	ref	amulet;
	int	amuletIndex;
	
	amuletIndex = ItemIndex;
	makeref(amulet, Items[amuletIndex]);
	
	amulet.id				= id;		
	amulet.groupID			= ITEM_SLOT_TYPE;
	amulet.name				= "itmname_" + id;
	amulet.describe			= "itmdescr_" + id;		
	amulet.model			= ModelID;
	amulet.picTexture		= picTexture;
	amulet.picIndex			= picIndex;
	amulet.price			= Price;	
	amulet.rare 			= Rare;
	amulet.minlevel 		= MinLevel;
	amulet.Weight 			= Weight;
	amulet.time				= Time;
	amulet.ItemType 		= "ARTEFACT";
	amulet.Type				= Type;
	
	if(isMulti) 
	{
		amulet.multiobject		= true;
		amulet.multiobject.qty 	= outQty;
		if(reqAlchemy) 	amulet.multiobject.alchemy = true;
		else 			amulet.multiobject.alchemy = false;
	}	
	else
	{
		amulet.Monster.rare 	= Rare;
		amulet.Monster.min 		= 1;
		amulet.Monster.max 		= 1;
	}	
	if(kind != "") amulet.kind	= kind;	
	
	amulet.TradeType 		= ITEM_TRADE_ARTEFACT;
	
	amuletIndex++;
	return amuletIndex;
}					

int InitStdSuit(	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex, 
					int		Price, 
					float 	Weight,
					float	Rare, 
					int 	MinLevel,
					bool    isClothes,
					float	CirassLevel_blade,
					float   CirassLevel_gun, 
					float   Critical)
{
	ref	suit;
	int	suitIndex;
	
	suitIndex = ItemIndex;
	makeref(suit, Items[suitIndex]);
	
	suit.id					= id;		
	suit.groupID			= CIRASS_ITEM_TYPE;
	suit.name				= "itmname_" + id;
	suit.describe			= "itmdescr_" + id;		
	suit.folder 			= "items";
	suit.model				= ModelID;
	suit.picTexture			= picTexture;
	suit.picIndex			= picIndex;
	suit.price				= Price;	
	suit.rare 				= Rare;
	suit.minlevel 			= MinLevel;
	suit.Weight 			= Weight;
	suit.Clothes 			= isClothes;
	suit.B_CirassLevel 		= CirassLevel_blade;
	suit.G_CirassLevel 		= CirassLevel_gun;
	
	if(Critical > 0.0)
	{
		suit.critical			= Critical;
	}	
	
	suit.ItemType 			= "SUPPORT";
	suit.TradeType 			= ITEM_TRADE_AMMUNITION;
	
	suitIndex++;
	return suitIndex;
}					

int InitStdMap(		int		ItemIndex, 
					string 	id, 
					string 	picTexture,
					int		picIndex, 				
					int		Price, 
					float 	Weight,
					float   Rare,
					string  ImageTga,
					string  ImageType,
					int	    toAtlas,
					string 	MapType)
{
	ref	map;
	int	mapIndex;
	
	mapIndex = ItemIndex;
	makeref(map, Items[mapIndex]);
	
	map.id					= id;		
	map.groupID				= MAPS_ITEM_TYPE;
	map.name				= "itmname_" + id;
	map.describe			= "itmdescr_" + id;		
	map.model				= "";
	map.picTexture			= picTexture;
	map.picIndex			= picIndex;
	map.price				= Price;
	map.Weight 				= Weight;	
	map.imageTga 			= ImageTga;
	map.imageType 			= ImageType;
	map.Atlas 				= toAtlas;
	map.MapType 			= MapType;
	map.ItemType 			= "MAP";
	map.TradeType 			= ITEM_TRADE_MAP;
	
	if(Rare > 0.0) 
	{
		map.Rare			= Rare;
	}	
	
	mapIndex++;
	return mapIndex;
}

void InitStdItemRarity(	string id,			
						string sAttr,
						float  Rare,
						int    minQ,
						int    maxQ)
{
	ref rItem = ItemsFromID(id);
	rItem.(sAttr).rare 	=  Rare;
	rItem.(sAttr).min   =  minQ;
	rItem.(sAttr).max 	=  maxQ;
}						


void InitMultiObject(	string id,			
						string sAttr,       
						string component_id,
						string component_use,
						int    component_qty)
{
	ref rItem = ItemsFromID(id);
	rItem.component.(sAttr).id 	=  component_id;
	rItem.component.(sAttr).use =  component_use;
	rItem.component.(sAttr).qty =  component_qty;
}

//////////////////
int InitStdRecipies(int ItemIndex, string id, string result, int Price)
{
	ref	recipe;
	int	recipeIndex;
	
	recipeIndex = ItemIndex;
	makeref(recipe, Items[recipeIndex]);
	
	recipe.id			= id;	
	recipe.result 		= result;
	recipe.groupID		= SPECIAL_ITEM_TYPE;
	recipe.name			= "itmname_" + id;
	recipe.describe		= "itmdescr_" + id;		
	recipe.model		= "letter";
	recipe.picTexture	= "ITEMS_26";
	recipe.picIndex		= 16;
	recipe.price		= Price;	
	recipe.rare 		= 0.0001;
	recipe.minlevel 	= 1;
	recipe.Weight 		= 0.1;
	recipe.ItemType 	= "SUPPORT";
	//recipe.TradeType 	= ITEM_TRADE_POTION;
	
	recipeIndex++;
	return recipeIndex;
}
/////////////////

void InitMultiObjectAmulets()
{
	// ���������������� ���������
	InitMultiObject(		  "clock2",	"t1",      "clock1", 	"Component",    1);
	InitMultiObject(		  "clock2",	"t2",  "sand_clock", 	"Component",    1);
	// �������
	InitMultiObject(		  "bussol",	"t1",    "compass1", 	"Component",    1);
	InitMultiObject(		  "bussol",	"t2",    "astrolab", 	"Component",    1);
	// ��������� ��������
	InitMultiObject(		"sextant2",	"t1",    "sextant1", 	"Component",    1);
	InitMultiObject(		"sextant2",	"t2",      "clock3", 	"Component",    1);
	// ������
	InitMultiObject(		  "Chest",	"t1", "gold_dublon", 	"Component",  150);
	InitMultiObject(		  "Chest",	"t2",  "Chest_open", 	"Component",    1);
	// �������
	InitMultiObject(    "gold_dublon",	"t1",       "chest", 	"Component",    1);
	
	// �������
	InitMultiObject(		"potion2",	    "t1",       "potion5", 	  "Component", 	  1); // �������� ������
	InitMultiObject(		"potion2",	    "t2",     "cannabis1", 	  "Component", 	  3); // ������
	InitMultiObject(		"potion2",	    "t3",     "cannabis2", 	  "Component", 	  1); // ���������
	InitMultiObject(		"potion2",	    "t4",       "potion1", 	  "Component", 	  1); // �������� �����
	InitMultiObject(		"potion2",	    "t5",     "mineral17", 	  "Component", 	  1); // ������ ���������
	InitMultiObject(		"potion2",	    "t6",      "mineral9",    "Component", 	  1); // ������ ������
	InitMultiObject(		"potion2",	    "t7",      "mineral3",    "Component", 	  1); // �����
	InitMultiObject(		"potion2",	    "t8",      "jewelry8",    "Component", 	  1); // ������
	InitMultiObject(  		"potion2",	    "t9",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		"potion2",     "t10",     "mineral19",  "AlchemyTool", 	  1); // ���������� �����
	InitMultiObject(  		"potion2",     "t11",     "mineral27",  "AlchemyTool", 	  1); // ������ � ��������
	
	// �����������
	InitMultiObject(		"potion3",	    "t1",     "cannabis3", 	  "Component", 	  1); // �������
	InitMultiObject(		"potion3",	    "t2",     "cannabis4", 	  "Component", 	  1); // ����������
	InitMultiObject(		"potion3",	    "t3",     "cannabis5", 	  "Component", 	  1); // �������
	InitMultiObject(		"potion3",	    "t4",     "cannabis6", 	  "Component", 	  1); // �������� �����
	InitMultiObject(		"potion3",	    "t5",     "mineral17", 	  "Component", 	  1); // ������ ���������
	InitMultiObject(		"potion3",	    "t6",     "jewelry52",    "Component", 	  1); // ������� ���������
	InitMultiObject(  		"potion3",	    "t7",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		"potion3",      "t8",     "mineral27",  "AlchemyTool", 	  1); // ������ � ��������
	InitMultiObject(  		"potion3",      "t9",      "mineral1",  "AlchemyTool", 	  1); // ������ ������
	InitMultiObject(  		"potion3",     "t10",     "mineral20",  "AlchemyTool",    1); // ���������� �����
	InitMultiObject(  		"potion3", 	   "t11",      "mineral5",  "AlchemyTool", 	  1); // �������
	
	// ���������
	InitMultiObject(		"berserker_potion",	    "t1",     "cannabis6", 	  "Component", 	  1); // �������� �����
	InitMultiObject(		"berserker_potion",	    "t2",     "cannabis1", 	  "Component", 	  2); // ������
	InitMultiObject(		"berserker_potion",	    "t3",     "jewelry4", 	  "Component", 	  1); // �������
	InitMultiObject(		"berserker_potion",	    "t4",     "potionrum", 	  "Component", 	  1); // ���
	InitMultiObject(		"berserker_potion",	    "t5",     "mineral3", 	  "Component", 	  1); // �����
	InitMultiObject(		"berserker_potion",	    "t6",     "mineral17", 	  "Component", 	  1); // ���������
	InitMultiObject(  		"berserker_potion",	    "t7",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		"berserker_potion",     "t8",     "mineral27",  "AlchemyTool", 	1); // ������ � ��������
		
	// ��������� - ����
	InitMultiObject(		"mangarosapower",	    "t1",     "cannabis7", 	  "Component", 	  1); // ���������
	InitMultiObject(		"mangarosapower",	    "t2",     "cannabis4", 	  "Component", 	  1); // ����������
	InitMultiObject(		"mangarosapower",	    "t3",     "jewelry8", 	  "Component", 	  1); // ������
	InitMultiObject(		"mangarosapower",	    "t4",     "potionrum", 	  "Component", 	  1); // ���
	InitMultiObject(		"mangarosapower",	    "t5",     "potion5", 	  "Component", 	  1); // ������
	InitMultiObject(		"mangarosapower",	    "t6",     "jewelry53", 	  "Component", 	  3); // ������
	InitMultiObject(		"mangarosapower",	    "t7",     "mineral17", 	  "Component", 	  1); // ���������
	InitMultiObject(  		"mangarosapower",	    "t8",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		"mangarosapower",       "t9",     "mineral5",  "AlchemyTool", 	1); // �������
	InitMultiObject(  		"mangarosapower",      "t10",     "mineral1",  "AlchemyTool", 	1); // ������ ������
	
	// ��������� - ��������
	InitMultiObject(		"mangarosafast",	    "t1",     "cannabis7", 	  "Component", 	  1); // ���������
	InitMultiObject(		"mangarosafast",	    "t2",     "cannabis5", 	  "Component", 	  2); // �������
	InitMultiObject(		"mangarosafast",	    "t3",     "jewelry8", 	  "Component", 	  1); // ������
	InitMultiObject(		"mangarosafast",	    "t4",    "potionwine",   "Component", 	  1); // ����
	InitMultiObject(		"mangarosafast",	    "t5",     "cannabis3", 	  "Component", 	  1); // �������
	InitMultiObject(		"mangarosafast",	    "t6",     "jewelry52", 	  "Component", 	  2); // ������
	InitMultiObject(		"mangarosafast",	    "t7",     "mineral17", 	  "Component", 	  1); // ���������
	InitMultiObject(  		"mangarosafast",	    "t8",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		"mangarosafast",        "t9",     "mineral27",  "AlchemyTool", 	1); // ������-������
	InitMultiObject(  		"mangarosafast",       "t10",   "mineral11",  "AlchemyTool", 	1); // ���������� ������
	InitMultiObject(  		"mangarosafast",       "t11",   "mineral19",  "AlchemyTool", 	1); // ���������� �����
	
	// ��������� - ��������
	InitMultiObject(		"mangarosatotal",	    "t1",     "cannabis7", 	  "Component", 	  1); // ���������
	InitMultiObject(		"mangarosatotal",	    "t2",     "potion2", 	  "Component", 	  1); // �������
	InitMultiObject(		"mangarosatotal",	    "t3",     "jewelry7", 	  "Component", 	  1); // ������� ������
	InitMultiObject(		"mangarosatotal",	    "t4",     "jewelry53",   "Component", 	  3); // ������
	InitMultiObject(		"mangarosatotal",	    "t5",     "jewelry52", 	  "Component", 	  2); // ������
	InitMultiObject(		"mangarosatotal",	    "t6",     "mineral17", 	  "Component", 	  1); // ���������
	InitMultiObject(		"mangarosatotal",	    "t7",     "mineral5", 	  "AlchemyTool",  1); // �������
	InitMultiObject(  		"mangarosatotal",	    "t8",  	  "alchemy_tool",  "AlchemyTool", 1); // ������������ �����
	InitMultiObject(  		"mangarosatotal",     "t9",     "mineral27",  "AlchemyTool", 	1); // ������-������
	InitMultiObject(  		"mangarosatotal",     "t10",     "mineral9",  "AlchemyTool", 	1); // ������
	InitMultiObject(  		"mangarosatotal",     "t11",     "mineral20",  "AlchemyTool", 	1); // ���������� �����
		
	// �������� ������
	InitMultiObject(  	  	"cartridge",	"t1",  	     "bullet",    "Component", 	  1); // ����
	InitMultiObject(  	  	"cartridge",	"t2",     "gunpowder",    "Component", 	  1); // ��������������� �����

// ����� �� �������� ������
	InitMultiObject(  	  	"fennisgrasstotal",	"t1",  	     "Mineral7",    "AlchemyTool", 	  1); // ���������� ������
	InitMultiObject(  	  	"fennisgrasstotal",	"t2",     "fennis_grass",    "Component", 	  1); // �������� ������
	InitMultiObject(  	  	"fennisgrasstotal",	"t3",  	     "Mineral10",    "AlchemyTool", 	  1); // ������

	// �������
	InitMultiObject(  	"powder_pellet",	"t1",      "mineral1",    "Component", 	  1); // ������ ������
	InitMultiObject(  	"powder_pellet",	"t2",     "gunpowder",    "Component",   10); // ��������������� �����
	InitMultiObject(  	"powder_pellet",	"t3",      "mineral3",    "Component",    1); // ����� 
	InitMultiObject( 	"powder_pellet",	"t4",     "mineral22",    "Component",    1); // ������
	InitMultiObject(  	"powder_pellet",	"t5", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����	
	
	// �������
	InitMultiObject(  		  "grenade",	"t1",      "mineral1",    "Component", 	  1); // ������ ������
	InitMultiObject(  		  "grenade",	"t2",     "gunpowder",    "Component",   10); // ��������������� �����
	InitMultiObject(  		  "grenade",	"t3",        "bullet",    "Component",   15); // ����
	InitMultiObject(  		  "grenade",	"t4",      "mineral3",    "Component",    1); // �����
	InitMultiObject(          "grenade",	"t5",     "mineral22",    "Component",    1); // ������
	InitMultiObject(          "grenade",	"t6", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����	
	
	// ������
	InitMultiObject(  		  "harpoon",	"t1",      "slave_01",    "Component", 	  1); // ������
	InitMultiObject(  		  "harpoon",	"t2",     "mineral16",  "AlchemyTool",    1); // ������
	InitMultiObject(  		  "harpoon",	"t3", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����	
	
	// ������������ ����
	InitMultiObject(   "shotgun_bullet",	"t1",  	     "bullet",    "Component", 	  1); // ����
	InitMultiObject(   "shotgun_bullet",	"t2",         "tigel",  "AlchemyTool", 	  1); // ������
	InitMultiObject(   "shotgun_bullet",	"t3",     "mineral32",  "AlchemyTool",    1); // ���������
	InitMultiObject(   "shotgun_bullet",	"t4",      "mineral5",  "AlchemyTool",    1); // �������
	
	// ������� ��� ������
	InitMultiObject(      "GunCap_colt",	"t1",     "jewelry12",    "Component", 	  1); // ������ ������
	InitMultiObject(  	  "GunCap_colt",	"t2",      "mineral3",    "Component",    3); // �����
	InitMultiObject(  	  "GunCap_colt",	"t3",  "OxyHydSilver",    "Component",    1); // �������� �������
	InitMultiObject(      "GunCap_colt",	"t4",         "tigel",  "AlchemyTool", 	  1); // ������
	InitMultiObject(      "GunCap_colt",	"t5",      "mineral5",  "AlchemyTool",    1); // �������
	InitMultiObject(  	  "GunCap_colt",	"t6", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����	
	
	// ������������ ��������
	InitMultiObject("shotgun_cartridge",	"t1", 	   "GunPowder",    "Component",   1); // �����
	InitMultiObject("shotgun_cartridge",	"t2", "shotgun_bullet",    "Component",   1); // ������������ ����
	InitMultiObject("shotgun_cartridge",	"t3",       "mineral3",    "Component",   1); // �����
	InitMultiObject("shotgun_cartridge",	"t4",   "Tailor_Tool",   "AlchemyTool",   1); // ����� ��������
	
	// ������ �����
	InitMultiObject(  	     "GunEchin",	"t1",      "mineral3",    "Component",    1); // �����
	InitMultiObject(  	     "GunEchin",	"t2",     "mineral23",    "Component",    5); // ������
	InitMultiObject(  	     "GunEchin",	"t3",     "gunpowder",    "Component",    2); // �����
	InitMultiObject(         "GunEchin",	"t4",         "tigel",  "AlchemyTool", 	  1); // ������
	InitMultiObject(         "GunEchin",	"t5",      "mineral5",  "AlchemyTool",    1); // �������
	InitMultiObject(  	     "GunEchin",	"t6", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����	
	
	// �������� �������		
	InitMultiObject(     "OxyHydSilver",	"t1",      "jewelry6",    "Component",    1); // ���������� ���������
	InitMultiObject(     "OxyHydSilver",	"t2",     "Mineral29",    "Component",    1); // ������� �������
	InitMultiObject(     "OxyHydSilver",	"t3",     "Mineral28",    "Component",    1); // �������� �����
	InitMultiObject(     "OxyHydSilver",	"t4",  "alchemy_tool",  "AlchemyTool",    1); // ������������ �����
	InitMultiObject(     "OxyHydSilver",	"t5",      "mineral5",  "AlchemyTool",    1); // �������
	
	// �����_01 - ������ ������
	InitMultiObject(  		 "totem_01",	"t1",     "potionrum",    "Component", 	  1); // ������� ����			
	InitMultiObject(  		 "totem_01",	"t2",      "mineral9",    "Component", 	  1); // ������ ������			
	InitMultiObject(  		 "totem_01",	"t3",      "jewelry1",    "Component", 	  1); // �������	
	InitMultiObject(  		 "totem_01",	"t4",      "jewelry6",    "Component", 	  1); // ���������� ������	
	InitMultiObject(  		 "totem_01",	"t5",      "mineral5",  "AlchemyTool", 	  1); // ��������
	
	// �����_02 - ���������
	InitMultiObject(  		 "totem_02",	"t1",     "mineral13",    "Component", 	  3); // ������
	InitMultiObject(  		 "totem_02",	"t2",      "jewelry5",    "Component", 	  3); // ������� ���������
	InitMultiObject(  		 "totem_02",	"t3",     "mineral22",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_02",	"t4",     "cannabis6",    "Component", 	  1); // �������� �����
	InitMultiObject(  		 "totem_02",	"t5",     "mineral18",    "Component", 	  1); // �����
	InitMultiObject(  		 "totem_02",	"t6",      "jewelry3",    "Component", 	  1); // �����
	InitMultiObject(  		 "totem_02",	"t7",    "rat_poison",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_02",	"t8",   "tailor_tool",  "AlchemyTool", 	  1); // ���������� �����
	InitMultiObject(  		 "totem_02",	"t9",     "mineral27",  "AlchemyTool", 	  1); // ������ � ��������
	InitMultiObject(  		 "totem_02",   "t10",      "jewelry7",    "Component", 	  1); // ������� ������	
	
	// �����_03 - ������� ��������
	InitMultiObject(  		 "totem_03",	"t1",     "mineral14",    "Component", 	  1); // ����� �������
	InitMultiObject(  		 "totem_03",	"t2",      "mineral4",    "Component", 	  5); // ���-��������
	InitMultiObject(  		 "totem_03",	"t3",       "potion5",    "Component", 	  1); // �������� ������
	InitMultiObject(  		 "totem_03",	"t4",     "cannabis5",    "Component", 	  1); // �������
	InitMultiObject(  		 "totem_03",	"t5",     "jewelry17",    "Component", 	  1); // �������
	InitMultiObject(  		 "totem_03",	"t6",     "jewelry12",    "Component", 	  1); // ������ ������
	InitMultiObject(  		 "totem_03",	"t7",     "mineral27",  "AlchemyTool", 	  1); // ������ � ��������
	InitMultiObject(  		 "totem_03",	"t8",      "mineral5",  "AlchemyTool", 	  1); // ��������
	InitMultiObject(  		 "totem_03",	"t9",  "alchemy_tool",  "AlchemyTool", 	  1); // ������������ �����
	InitMultiObject(  		 "totem_03",   "t10",      "jewelry7",    "Component", 	  1); // ������� ������	

	// �����_04 - �������
	InitMultiObject(  		 "totem_04",	"t1",      "jewelry6",    "Component", 	  7); // ���������� ������	
	InitMultiObject(  		 "totem_04",	"t2",     "mineral30",    "Component", 	  1); // ������� ����
	InitMultiObject(  		 "totem_04",	"t3",      "mineral3",    "Component", 	  1); // �����
	InitMultiObject(  		 "totem_04",	"t4",     "jewelry12",    "Component", 	  1); // ������ ������
	InitMultiObject(  		 "totem_04",	"t5",     "cannabis5",    "Component", 	  1); // �������
	InitMultiObject(  		 "totem_04",	"t6",       "potion5",    "Component", 	  1); // �������� ������
	InitMultiObject(  		 "totem_04",	"t7",     "jewelry17",    "Component", 	  1); // �������
	InitMultiObject(  		 "totem_04",	"t8",      "jewelry7",    "Component", 	  1); // ������� ������
	InitMultiObject(  		 "totem_04",	"t9", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� ����������

	// �����_05 - �������� ��� - TODO!!
	InitMultiObject(  		 "totem_05",	"t1",     "mineral24",    "Component",    1); // ������
	InitMultiObject(  		 "totem_05",	"t2",      "mineral2",    "Component",    1); // ����������� �������
	InitMultiObject(  		 "totem_05",	"t3",     "jewelry13",    "Component",    1); // �������� ������
	InitMultiObject(  		 "totem_05",	"t4",     "jewelry22",    "Component",    1); // ������	
	InitMultiObject(  		 "totem_05",	"t5", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� ����������
	InitMultiObject(  		 "totem_05",	"t6",      "mineral6",  "AlchemyTool", 	  1); // ���������
	
	// �����_06 - ������
	InitMultiObject(  		 "totem_06",	"t1",      "mineral8",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_06",	"t2",      "mineral4",    "Component", 	  1); // ���-��������		
	InitMultiObject(  		 "totem_06",	"t3",     "jewelry18",    "Component", 	  1); // ���������
	InitMultiObject(  		 "totem_06",	"t4",     "jewelry12",    "Component", 	  1); // ������ ������	
	InitMultiObject(  		 "totem_06",	"t5",      "jewelry7",    "Component", 	  1); // ������� ������
	InitMultiObject(		 "totem_06",	"t6",     "mineral17", 	  "Component", 	  1); // ���������	
	InitMultiObject(  		 "totem_06",	"t7",     "mineral10",  "AlchemyTool", 	  1); // ������

	// �����_07 - ����������
	InitMultiObject(  		 "totem_07",	"t1",      "jewelry6",    "Component", 	  5); // ���������� ������
	InitMultiObject(  		 "totem_07",	"t2",     "jewelry21",    "Component", 	  1); // �������
	InitMultiObject(  		 "totem_07",	"t3",      "jewelry7",    "Component", 	  1); // ������� ������
	InitMultiObject(  		 "totem_07",	"t4", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� ����������
	InitMultiObject(  		 "totem_07",	"t5",      "mineral5",  "AlchemyTool", 	  1); // ��������
	
	// �����_08 - ���������� ����
	InitMultiObject(  		 "totem_08",	"t1",      "mineral7",    "Component", 	  1); // ���������� ������
	InitMultiObject(  		 "totem_08",	"t2",      "jewelry5",    "Component", 	  1); // ������� ���������
	InitMultiObject(  		 "totem_08",	"t3",     "cannabis1",    "Component", 	  3); // ������
	InitMultiObject(  		 "totem_08",	"t4",     "mineral22",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_08",	"t5",     "jewelry14",    "Component", 	  1); // �������� ����
	InitMultiObject(  		 "totem_08",	"t6",    "rat_poison",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_08",	"t7", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����
	InitMultiObject(  		 "totem_08",	"t8",      "jewelry7",    "Component", 	  1); // ������� ������
	
	// �����_09 - �������
	InitMultiObject(  		 "totem_09",	"t1",     "mineral25",    "Component", 	  1); // ���������� �����
	InitMultiObject(  		 "totem_09",	"t2",     "jewelry10",    "Component", 	  1); // ���������� ������		
	InitMultiObject(  		 "totem_09",	"t3",     "jewelry15",    "Component", 	  1); // ���������				
	InitMultiObject(  		 "totem_09",	"t4", "Mechanic_Tool",  "AlchemyTool", 	  1); // ��������� �����
	InitMultiObject(  		 "totem_09",	"t5",      "jewelry7",    "Component", 	  1); // ������� ������

	// �����_10 - ������ ����
	InitMultiObject(  		 "totem_10",	"t1",     "mineral15",    "Component", 	  1); // �������� ���
	InitMultiObject(  		 "totem_10",	"t2",     "jewelry45",    "Component", 	  1); // ������� �������
	InitMultiObject(  		 "totem_10",	"t3",     "jewelry19",    "Component", 	  1); // ������
	InitMultiObject(  		 "totem_10",	"t4",      "jewelry7",    "Component", 	  1); // ������� ������	

	// �����_11 - �����
	InitMultiObject(  		 "totem_11",	"t1",     "mineral14",    "Component", 	  1); // ����� �������	
	InitMultiObject(  		 "totem_11",	"t2",     "mineral31",    "Component", 	  2); // ������������ �����	
	InitMultiObject(  		 "totem_11",	"t3",     "jewelry11",    "Component", 	  1); // ��������
	InitMultiObject(  		 "totem_11",	"t4",     "jewelry16",    "Component",    1); // ����	
	InitMultiObject(  		 "totem_11",	"t5",      "jewelry7",    "Component", 	  1); // ������� ������	
	InitMultiObject(  		 "totem_11",	"t6",   "tailor_tool",  "AlchemyTool", 	  1); // ���������� �����

	// �����_12 - ��� ������
	InitMultiObject(  		 "totem_12",	"t1",     "mineral12",    "Component", 	  1); // ������ ������
	InitMultiObject(  		 "totem_12",	"t2",     "jewelry53",    "Component", 	  5); // ��������� ���������
	InitMultiObject(  		 "totem_12",	"t3",     "cannabis3",    "Component", 	  1); // �������	
	InitMultiObject(  		 "totem_12",	"t4",     "jewelry17",    "Component", 	  1); // �������	
	InitMultiObject(  		 "totem_12",	"t5",      "jewelry7",    "Component", 	  1); // ������� ������	
	InitMultiObject(  		 "totem_12",	"t6",     "mineral11",  "AlchemyTool", 	  1); // ���������� ������
	InitMultiObject(  		 "totem_12",	"t7",     "mineral27",  "AlchemyTool", 	  1); // ������ � ��������

	// �����_13 - ������ 
	InitMultiObject(  		 "totem_13",	"t1",     "mineral26",    "Component", 	  1); // ������ ����
	InitMultiObject(  		 "totem_13",	"t2",      "mineral3",    "Component", 	  1); // �����
	InitMultiObject(  		 "totem_13",	"t3",     "jewelry13",    "Component", 	  1); // �������� ������
	InitMultiObject(  		 "totem_13",	"t4",     "jewelry52",    "Component", 	  1); // ������� ���������	
	InitMultiObject(  		 "totem_13",	"t5",     "jewelry23",    "Component", 	  1); // �����������
	InitMultiObject(  		 "totem_13",	"t6",     "mineral21",  "AlchemyTool", 	  1); // ���������� ��������������
	InitMultiObject(  		 "totem_13",	"t7",      "jewelry7",    "Component", 	  1); // ������� ������
}
	 	
void InitGunExt(string id,			
				string sAttr,       
				string sBullet,     
				string sGunPowder,  
				float  DmgMin_NC,   
				float  DmgMax_NC,   
				float  DmgMin_C,    
				float  DmgMax_C,    
				float  EnergyP_NC,  
				float  EnergyP_C,   
				bool   Stun_NC,     
				bool   Stun_C,      
				bool   MultiDamage, 
				int    MisFire,     
				bool   SelfDamage,  
				bool   Explosion,   
				float  Accuracy,    
				int    ChargeSpeed, 
				int    Osechka,   
				bool   isDefault )
{
	ref gun = ItemsFromID(id);
	gun.type.(sAttr).bullet 		= sBullet;
	gun.type.(sAttr).gunpowder 		= sGunPowder;
	gun.type.(sAttr).DmgMin_NC		= DmgMin_NC;
	gun.type.(sAttr).DmgMax_NC		= DmgMax_NC;
	gun.type.(sAttr).DmgMin_C		= DmgMin_C;
	gun.type.(sAttr).DmgMax_C		= DmgMax_NC;
	gun.type.(sAttr).EnergyP_NC		= EnergyP_NC;
	gun.type.(sAttr).EnergyP_C		= EnergyP_C;
	gun.type.(sAttr).Stun_NC		= Stun_NC;
	gun.type.(sAttr).Stun_C			= Stun_C;
	gun.type.(sAttr).multidmg       = MultiDamage;
	gun.type.(sAttr).misfire        = MisFire;
	gun.type.(sAttr).SelfDamage     = SelfDamage;
	gun.type.(sAttr).Explosion      = Explosion;
	gun.type.(sAttr).Accuracy       = Accuracy;
	gun.type.(sAttr).ChargeSpeed    = ChargeSpeed;
	gun.type.(sAttr).Osechka       = Osechka;
	gun.type.(sAttr).Default        = isDefault;
	
	if(Stun_NC || Stun_C) gun.stun = true;
}

void InitMushketExt(string id, 
					float  DmgMin_butt,  
					float  DmgMax_butt, 
					float  DmgMin_bayonet, 
					float  DmgMax_bayonet, 
					string sAttack_butt, 
					string sAttack_bayonet )
{
	ref gun = ItemsFromID(id);
	gun.DmgMin_butt 	= DmgMin_butt;
	gun.DmgMax_butt 	= DmgMax_butt;
	gun.DmgMin_bayonet 	= DmgMin_bayonet;
	gun.DmgMax_bayonet 	= DmgMax_bayonet;
	gun.sAttack_butt 	= sAttack_butt;
	gun.sAttack_bayonet = sAttack_bayonet;	
}					
					
void InitMushkets()
{
	//InitMushketExt(id, DmgMin_butt, DmgMax_butt, DmgMin_bayonet, DmgMax_bayonet, sAttack_butt, sAttack_bayonet );	
	InitMushketExt(		"mushket_01",  10.0,  25.0,  10.0,  20.0, "FencingH", "FencingL" ); // �������
	InitMushketExt(		"mushket1",  40.0,  70.0,  15.0,  40.0, "FencingH", "FencingL" ); // ������
	InitMushketExt(		"mushket2",  15.0,  50.0,  40.0,  90.0, "FencingH", "FencingL" ); // �����
	InitMushketExt(		"mushket5",  15.0,  50.0,  15.0,  35.0, "FencingH", "FencingL" ); // ������������ ������
	InitMushketExt(	  "mushket2x2",  15.0,  55.0,  15.0,  40.0, "FencingH", "FencingL" );	// ��������� ������
	InitMushketExt(		"mushket3",  20.0,  45.0,  20.0,  35.0, "FencingH", "FencingL" ); // ��������
	InitMushketExt(		"mushket_8",  25.0,  50.0,  25.0,  40.0, "FencingH", "FencingL" ); // ����������
	InitMushketExt(		"mushket_9",  30.0,  55.0,  30.0,  45.0, "FencingH", "FencingL" ); // ��������
	InitMushketExt(		"mushket6",  15.0,  40.0,  15.0,  30.0, "FencingH", "FencingL" ); // �������� ��������
	InitMushketExt(	  "mushkett2x2",  15.0,  55.0,  15.0,  40.0, "FencingH", "FencingL" ); // ������������� ��������
	InitMushketExt("grape_mushket",  15.0,  40.0,   10.0,  25.0, "FencingH", "FencingL" ); // ���������
	InitMushketExt("mushket_10",  10.0,  35.0,   5.0,  20.0, "FencingH", "FencingL" ); // ������		
}
					
void InitGuns()
{
	//InitGunExt(id,	sAttr,  sBullet,  sGunPowder, DmgMin_NC, DmgMax_NC, DmgMin_C, DmgMax_C, EnergyP_NC, EnergyP_C, Stun_NC, Stun_C, MultiDamage, MisFire, SelfDamage, Explosion,Accuracy,ChargeSpeed, Osechka, isDefault);

// �������
	InitGunExt(		 "pistol_01", "t1",  	     "cartridge",               "",  20.0, 100.0,  20.0, 100.0,  0.0,  0.0, 1, 0, 0, 5, 0, 0, 50, 60, 35, 0);	
	InitGunExt(		 "pistol_01", "t2", 		    "bullet",      "gunpowder",  20.0, 100.0,  20.0, 100.0,  0.0,  0.0, 1, 0, 0, 6, 0, 0, 50, 70, 40, 1);

// �������� ��������
	InitGunExt(		 "pistol1", "t1",  	    "cartridge",               "",  40.0, 200.0,  40.0, 200.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 50, 50, 30, 0);	
	InitGunExt(		 "pistol1", "t2", 		    "bullet",      "gunpowder",  40.0, 200.0,  40.0, 200.0,  0.0,  0.0, 1, 0, 0, 5, 0, 0, 50, 60, 35, 1);
	
// ������������ ��������
	InitGunExt(		 "pistol_02", "t1",  	     "cartridge",               "",  30.0, 150.0,  30.0, 150.0,  0.0,  0.0, 1, 0, 0, 3, 0, 0, 60, 40, 25, 0);	
	InitGunExt(		 "pistol_02", "t2", 		    "bullet",      "gunpowder",  30.0, 150.0,  30.0, 150.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 60, 50, 30, 1);

// �������� ��������
	InitGunExt(		"pistol11", "t1", 		    "cartridge",      "", 60.0, 300.0, 60.0, 300.0, 0.0, 0.0, 1, 1, 0, 1, 0, 0, 65, 35, 25, 1);
	InitGunExt(		 "pistol11", "t2", 		    "bullet",      "gunpowder",  60.0, 300.0,  60.0, 300.0,  0.0,  0.0, 1, 1, 0, 2, 0, 0, 65, 45, 30, 1);

// ���-��������
	InitGunExt(		 "pistol6", "t1", 	     "cartridge",               "",  50.0, 250.0,  50.0, 250.0,  0.0,  0.0, 1, 0, 0, 2, 0, 0, 50, 50, 25, 0);	
	InitGunExt(		 "pistol6", "t2", 		    "bullet",      "gunpowder",  50.0, 250.0,  50.0, 250.0,  0.0,  0.0, 1, 0, 0, 3, 0, 0, 50, 60, 30, 1);

// ��� ������
	InitGunExt(		 "pistol_06", "t1", 	     "cartridge",               "",  55.0, 280.0,  55.0, 280.0,  0.0,  0.0, 1, 0, 0, 3, 0, 0, 55, 60, 30, 0);	
	InitGunExt(		 "pistol_06", "t2", 		    "bullet",      "gunpowder",  55.0, 280.0,  55.0, 280.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 55, 70, 35, 1);

// ����������� ��������
	InitGunExt(		 "pistol9", "t1", 	     "cartridge",               "",  45.0, 220.0,  45.0, 220.0,  0.0,  0.0, 1, 0, 0, 1, 0, 0, 60, 40, 30, 0);	
	InitGunExt(		 "pistol9", "t2", 		    "bullet",      "gunpowder",  45.0, 220.0,  45.0, 220.0,  0.0,  0.0, 1, 0, 0, 2, 0, 0, 60, 50, 35, 1);	

// ���������� ��������
	InitGunExt(		 "pistol5", "t1", 	     "cartridge",               "",  90.0, 450.0,  90.0, 450.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 70, 30, 20, 0);	
	InitGunExt(		 "pistol5", "t2", 		    "bullet",      "gunpowder",  90.0, 450.0,  90.0, 450.0,  0.0,  0.0, 1, 0, 0, 0, 1, 0, 70, 40, 25, 1);

// �������� ����� �� �����
	InitGunExt(		 "pistol_05", "t1", 	     "cartridge",               "",  100.0, 460.0,  100.0, 460.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 80, 25, 10, 0);	
	InitGunExt(		 "pistol_05", "t2", 		    "bullet",      "gunpowder",  100.0, 460.0,  100.0, 460.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 80, 35, 15, 1);

// 4-� ��������� ��������
	InitGunExt(		 "pistol4", "t1", 	     "cartridge",               "",  80.0, 400.0,  80.0, 400.0,  0.0,  0.0, 1, 0, 0, 1, 0, 0, 40, 60, 20, 0);	
	InitGunExt(		 "pistol4", "t2", 		    "bullet",      "gunpowder",  80.0, 400.0,  80.0, 400.0,  0.0,  0.0, 1, 0, 0, 2, 0, 0, 40, 70, 25, 1);	

// ��������� ������
	InitGunExt(		 "pistol7", "t1","shotgun_cartridge",    "GunCap_colt", 150.0, 560.0, 150.0, 560.0, 10.0, 10.0, 1, 1, 0, 0, 0, 0, 90, 20, 5, 1);

// ��������
	InitGunExt(		 "pistol10", "t1","shotgun_cartridge",    "GunCap_colt", 200.0, 660.0, 200.0, 660.0, 15.0, 15.0, 1, 1, 0, 0, 0, 0, 95, 15, 1, 1);

// ����������
	InitGunExt(		 "pistol3", "t1", 	     "grapeshot",      "gunpowder",  15.0,  85.0,  15.0,  85.0,  0.0,  0.0, 0, 1, 1, 6, 1, 1, 30, 65, 40, 1);
// �������
	InitGunExt(		 "pistol_03", "t1", 	     "grapeshot",      "gunpowder",  20.0,  110.0,  20.0,  110.0,  0.0,  0.0, 0, 1, 1, 5, 1, 1, 40, 55, 35, 1);
// ���������� ��������
	InitGunExt(		 "pistol_08", "t1", 	     "grapeshot",      "gunpowder",  50.0,  260.0,  50.0,  260.0,  0.0,  0.0, 0, 1, 1, 2, 1, 1, 50, 40, 30, 1);
	InitGunExt(		 "pistol_08", "t2", 		  "GunEchin",               "", 70.0, 310.0, 70.0, 310.0, 20.0, 20.0, 0, 1, 1, 1, 0, 0, 25, 50, 25, 0);
// ������������ ��������
	InitGunExt( 	 "pistol2", "t1", 	     "grapeshot",      "gunpowder",  30.0, 160.0,  30.0,  160.0,  0.0,  0.0, 0, 1, 1, 4, 1, 1, 40, 60, 30, 1);
// �����
	InitGunExt( 	 "pistol02", "t1", 	     "grapeshot",      "gunpowder",  40.0, 210.0,  40.0,  210.0,  0.0,  0.0, 0, 1, 1, 3, 1, 1, 45, 50, 30, 1);
// ���������� ��������
	InitGunExt(		 "pistol_04", "t1", 	     "grapeshot",      "gunpowder",  80.0,  380.0,  80.0,  380.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 60, 35, 25, 1);
// ����������
	InitGunExt(		 "pistol8", "t1", 	     "grapeshot",      "gunpowder",  85.0,  390.0,  85.0,  390.0,  5.0,  5.0, 1, 1, 1, 0, 1, 1, 65, 30, 20, 1);	
	InitGunExt(		 "pistol8", "t2", 		   "harpoon",      "gunpowder", 120.0, 500.0, 120.0, 500.0, 20.0, 20.0, 0, 1, 0, 0, 0, 0, 35, 40, 20, 0);	
	InitGunExt(		 "pistol8", "t3", 		  "GunEchin",               "", 100.0, 450.0, 100.0, 450.0, 20.0, 20.0, 0, 1, 1, 0, 0, 0, 35, 50, 15, 0);	


//InitGunExt(id,	sAttr,  sBullet,  sGunPowder, DmgMin_NC, DmgMax_NC, DmgMin_C, DmgMax_C, EnergyP_NC, EnergyP_C, Stun_NC, Stun_C, MultiDamage, MisFire, SelfDamage, Explosion,Accuracy,ChargeSpeed, Osechka, isDefault);

// �������	
	InitGunExt(		"mushket_01", "t1", 	     "cartridge",               "", 80.0, 420.0, 80.0, 420.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 60, 50, 35, 0);	
	InitGunExt(		"mushket_01", "t2", 		    "bullet",      "gunpowder", 80.0, 420.0, 80.0, 420.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 60, 70, 40, 1);
	InitGunExt(		"mushket_01", "t3", 	     "grapeshot",      "gunpowder",  70.0, 350.0,  70.0,  350.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 50, 60, 40, 1);	
// ������
	InitGunExt(		"mushket1", "t1", 	     "cartridge",               "", 130.0, 520.0, 130.0, 520.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 70, 60, 30, 0);	
	InitGunExt(		"mushket1", "t2", 		    "bullet",      "gunpowder", 130.0, 520.0, 130.0, 520.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 70, 70, 35, 1);	
// �����
	InitGunExt(		"mushket2", "t1", 	     "cartridge",               "", 180.0, 620.0, 180.0, 620.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 80, 40, 25, 0);	
	InitGunExt(		"mushket2", "t2", 		    "bullet",      "gunpowder", 180.0, 620.0, 180.0, 620.0,  0.0,  0.0, 1, 0, 0, 0, 0, 0, 80, 50, 30, 1);	
// ������������ ������
	InitGunExt(		"mushket5", "t1", 	     "cartridge",               "", 230.0, 720.0, 230.0, 720.0, 15.0, 15.0, 1, 1, 0, 0, 0, 0, 90, 30, 20, 0);	
	InitGunExt(		"mushket5", "t2", 		    "bullet",      "gunpowder", 230.0, 720.0, 230.0, 720.0, 15.0, 15.0, 1, 1, 0, 0, 0, 0, 90, 40, 25, 1);
// ��������� ������
	InitGunExt(	  "mushket2x2", "t1", 	     "cartridge",               "", 200.0, 670.0, 200.0, 670.0, 15.0, 15.0, 1, 1, 0, 0, 0, 0, 85, 35, 20, 0);	
	InitGunExt(	  "mushket2x2", "t2", 		    "bullet",      "gunpowder", 200.0, 670.0, 200.0, 670.0, 15.0, 15.0, 1, 1, 0, 0, 0, 0, 85, 45, 25, 1);


// ��������
	InitGunExt(		"mushket3", "t1", 	     "grapeshot",      "gunpowder",  120.0, 450.0,  120.0,  450.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 60, 65, 35, 1);	
// ����������
	InitGunExt(		"Mushket_8", "t1", 	     "grapeshot",      "gunpowder",  170.0, 550.0,  170.0,  550.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 70, 45, 30, 1);
// ��������
	InitGunExt(		"Mushket_9", "t1", 	     "grapeshot",      "gunpowder",  220.0, 650.0,  220.0, 650.0, 20.0, 20.0, 1, 1, 1, 0, 0, 1, 80, 35, 25, 1);	
	InitGunExt(		"Mushket_9", "t2", 	      "GunEchin",               "", 245.0, 700.0,  245.0, 700.0, 20.0, 20.0, 1, 1, 1, 0, 0, 1, 65, 45, 20, 0);
// ������������ ��������	
	InitGunExt(	  "mushkett2x2", "t2", 		    "grapeshot",      "gunpowder", 190.0, 580.0, 190.0, 580.0, 15.0, 15.0, 1, 1, 1, 0, 0, 0, 80, 40, 15, 1);	
// �������� ��������
	InitGunExt(		"mushket6", "t1", 	     "grapeshot",      "gunpowder",  170.0, 550.0,  170.0, 550.0, 20.0, 20.0, 1, 1, 1, 0, 0, 1, 75, 45, 25, 1);	
	InitGunExt(		"mushket6", "t2", 	      "GunEchin",               "", 200.0, 600.0,  200.0, 600.0, 20.0, 20.0, 1, 1, 1, 0, 0, 1, 60, 55, 20, 0);	


// ������
	InitGunExt(		 "mushket_10", "t1","shotgun_cartridge",    "GunCap_colt", 330.0, 820.0, 330.0, 820.0, 25.0, 25.0, 1, 1, 0, 0, 0, 0, 95, 20, 5, 1);	

// ���������
	InitGunExt("grape_mushket", "t1", 	       "grenade",               "", 280.0, 820.0,  280.0, 820.0, 10.0, 10.0, 1, 1, 0, 0, 0, 1, 90, 60, 30, 1);	
	InitGunExt("grape_mushket", "t2",    "powder_pellet",               "",  140.0, 410.0,   140.0, 410.0, 30.0, 50.0, 1, 1, 1, 0, 0, 1, 90, 60, 30, 0);		
}

void InitItemsRarity()
{
	// cirasses
	InitStdItemRarity(		  "cirass1", 		"Solder", 		0.003, 	1, 		1);
	InitStdItemRarity(		  "cirass1",       "Warrior", 		0.003, 	1, 		1);
	InitStdItemRarity(		  "cirass2",      "Solder_o", 		0.001, 	1, 		1);
	InitStdItemRarity(		  "cirass2",       "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		  "cirass3",      "Solder_o", 	   0.001, 	1, 		1);	
	InitStdItemRarity(		  "cirass5", 		"Solder", 		0.01, 	1, 		1);
	InitStdItemRarity(		  "cirass5",       "Warrior", 		0.01, 	1, 		1);
	InitStdItemRarity(		  "cirass6", 	    "Solder", 	   0.003, 	1, 		1);
	InitStdItemRarity(		  "cirass6",       "Warrior", 	   0.003, 	1, 		1);
	InitStdItemRarity(		  "cirass7", 		"Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		  "cirass7",       "Warrior", 	   0.001, 	1, 		1);
	// spyglasses
	InitStdItemRarity(		"spyglass1", 		"Solder", 		0.003, 	1, 		1);
	InitStdItemRarity(		"spyglass1",       "Warrior", 		0.003, 	1, 		1);
	InitStdItemRarity(		"spyglass2",        "Solder",      	0.001, 	1, 		1);
	InitStdItemRarity(		"spyglass2",       "Warrior",       0.001, 	1, 		1);	
	// potions
	InitStdItemRarity(		  "potion1", 	  "Solder_o", 		0.30, 	2, 		6);
	InitStdItemRarity(		  "potion1", 	    "Solder", 		0.10, 	1, 		3);
	InitStdItemRarity(		  "potion1", 	   "Warrior", 		0.10, 	1, 		4);
	InitStdItemRarity(		  "potion1", 	   "Monster", 		0.10, 	1, 		7);
	
	InitStdItemRarity(		  "potion2", 	  "Solder_o", 	  	0.02, 	1, 		3);
	InitStdItemRarity(		  "potion2", 	    "Solder", 	   	0.01, 	1, 		3);
	InitStdItemRarity(		  "potion2", 	   "Warrior", 	   	0.01, 	1, 		3);
	InitStdItemRarity(		  "potion2", 	   "Monster", 	   	0.01, 	1, 		5);
		
	InitStdItemRarity(		  "potion3", 	  "Solder_o", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		  "potion3", 	    "Solder", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		  "potion3", 	   "Warrior", 	   	0.01, 	1, 		1);

	InitStdItemRarity(		  "potion4", 	  "Solder_o", 	   	0.01, 	1, 		3);
	InitStdItemRarity(		  "potion4", 	    "Solder", 	   	0.01, 	1, 		3);
	InitStdItemRarity(		  "potion4", 	   "Warrior", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		  "potion4", 	   "Monster", 	   	0.01, 	1, 		3);
	
	InitStdItemRarity(		"potionrum", 	  "Solder_o", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"potionrum", 	    "Solder", 	    0.20, 	1, 		1);
	InitStdItemRarity(		"potionrum", 	   "Warrior", 	    0.20, 	1, 		1);

	InitStdItemRarity(	   "potionwine", 	  "Solder_o", 	    0.30, 	1, 		1);
	InitStdItemRarity(	   "potionwine", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(	   "potionwine", 	   "Warrior", 	   	0.05, 	1, 		1);
	
	InitStdItemRarity(		  "potion5", 	    "Solder", 	    0.10, 	1, 		9);
	InitStdItemRarity(		  "potion5", 	   "Warrior", 	    0.10, 	1, 		9);	
	// jewelry's
	InitStdItemRarity(		 "jewelry1", 	  "Solder_o", 	    0.10, 	1, 		4);
	InitStdItemRarity(		 "jewelry1", 	    "Solder", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry1", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry1", 	   "Monster", 	    0.10, 	1, 		4);
	InitStdItemRarity(		 "jewelry1", 	   "Citizen", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry1", 	 "Citizen_f", 	   	0.05, 	1, 		1);
	
	InitStdItemRarity(		 "jewelry2", 	  "Solder_o", 	    0.10, 	1, 		4);	
	InitStdItemRarity(		 "jewelry2", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry2", 	   "Monster", 	    0.10, 	1, 		4);
	
	InitStdItemRarity(		 "jewelry3", 	  "Solder_o", 	    0.10, 	1, 		4);	
	InitStdItemRarity(		 "jewelry3", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry3", 	   "Monster", 	    0.10, 	1, 		4);
	
	InitStdItemRarity(		 "jewelry4", 	  "Solder_o", 	    0.10, 	1, 		4);	
	InitStdItemRarity(		 "jewelry4", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		 "jewelry4", 	   "Monster", 	    0.10, 	1, 		4);
	
	InitStdItemRarity(		 "jewelry5", 	  "Solder_o", 	    0.20, 	1, 		4);	
	InitStdItemRarity(		 "jewelry5", 	   "Warrior", 	   	0.05, 	1, 		2);
	InitStdItemRarity(		 "jewelry5", 	   "Monster", 	    0.30, 	1, 		4);
		
	InitStdItemRarity(		 "jewelry6", 	    "Solder", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		 "jewelry6", 	   "Warrior", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		 "jewelry6", 	   "Citizen", 	    0.10, 	1, 		1);
	InitStdItemRarity(		 "jewelry6", 	 "Citizen_f", 	    0.30, 	1, 		1);
	
	InitStdItemRarity(		"jewelry40", 	  "Solder_o", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry40", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry40", 	   "Monster", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"jewelry40", 	 "Citizen_f", 	    0.20, 	1, 		1);
	
	InitStdItemRarity(		"jewelry41", 	    "Solder", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry41", 	   "Warrior", 	   	0.15, 	1, 		1);
	InitStdItemRarity(		"jewelry41", 	   "Citizen", 	   	0.15, 	1, 		1);
	InitStdItemRarity(		"jewelry41", 	 "Citizen_f", 	   	0.25, 	1, 		1);
	
	InitStdItemRarity(		"jewelry42", 	    "Solder", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		"jewelry42", 	   "Warrior", 	   	0.03, 	1, 		1);
	InitStdItemRarity(		"jewelry42", 	   "Citizen", 	   	0.20, 	1, 		1);
	InitStdItemRarity(		"jewelry42", 	 "Citizen_f", 	   	0.20, 	1, 		1);
	
	InitStdItemRarity(		"jewelry43", 	  "Solder_o", 	   	0.20, 	1, 		1);
	InitStdItemRarity(		"jewelry43", 	   "Warrior", 	   	0.02, 	1, 		1);
	InitStdItemRarity(		"jewelry43", 	   "Monster", 	   	0.30, 	1, 		1);
	InitStdItemRarity(		"jewelry43", 	   "Citizen", 	   	0.10, 	1, 		1);
	InitStdItemRarity(		"jewelry43", 	 "Citizen_f", 	   	0.30, 	1, 		1);

	InitStdItemRarity(		"jewelry44", 	  "Solder_o", 	   	0.20, 	1, 		5);
	InitStdItemRarity(		"jewelry44", 	   "Warrior", 	   	0.05, 	1, 		6);
	InitStdItemRarity(		"jewelry44", 	   "Monster", 	   	0.20, 	1, 		6);
	InitStdItemRarity(		"jewelry44", 	   "Citizen", 	   	0.10, 	1, 		5);
	InitStdItemRarity(		"jewelry44", 	 "Citizen_f", 	   	0.10, 	1, 		5);
	
	InitStdItemRarity(		"jewelry45", 	    "Solder", 	   	0.05, 	1, 		5);
	InitStdItemRarity(		"jewelry45", 	   "Warrior", 	   	0.05, 	1, 	   20);
	InitStdItemRarity(		"jewelry45", 	   "Citizen", 	   	0.15, 	1, 	   15);
	InitStdItemRarity(		"jewelry45", 	 "Citizen_f", 	   	0.10, 	1, 		5);
	
	InitStdItemRarity(		"jewelry46", 	  "Solder_o", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry46", 	   "Monster", 	   	0.01, 	1, 		4);
	InitStdItemRarity(		"jewelry46", 	   "Warrior", 	   	0.05, 	1, 	    2);
	InitStdItemRarity(		"jewelry46", 	 "Citizen_f", 	   	0.20, 	1, 		1);
	
	InitStdItemRarity(		"jewelry47", 	  "Solder_o", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry47", 	   "Warrior", 	   	0.01, 	1, 		2);
	InitStdItemRarity(		"jewelry47", 	   "Monster", 	    0.01, 	1, 		4);
	InitStdItemRarity(		"jewelry47", 	 "Citizen_f", 	   	0.20, 	1, 		1);
	
	InitStdItemRarity(		"jewelry48", 	  "Solder_o", 	    0.01, 	1, 		1);
	InitStdItemRarity(		"jewelry48", 	   "Warrior", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		"jewelry48", 	   "Monster", 	    0.02, 	1, 		4);
	InitStdItemRarity(		"jewelry48", 	 "Citizen_f", 	   	0.20, 	1, 		1);
	
	InitStdItemRarity(		"jewelry49", 	   "Warrior", 	   	0.10, 	1, 		4);
	InitStdItemRarity(		"jewelry49", 	   "Monster", 	    0.01, 	1, 		4);
	InitStdItemRarity(		"jewelry49", 	 "Citizen_f", 	   	0.40, 	1, 		1);
	
	InitStdItemRarity(		"jewelry49", 	    "Solder", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry49", 	   "Warrior", 	   	0.05, 	1, 		3);
	InitStdItemRarity(		"jewelry49", 	   "Monster", 	    0.10, 	1, 		5);
	InitStdItemRarity(		"jewelry49", 	   "Citizen", 	   	0.10, 	1, 		1);
	
	InitStdItemRarity(		"jewelry50", 	  "Solder_o", 	    0.20, 	1, 		1);
	InitStdItemRarity(		"jewelry50", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry50", 	   "Monster", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"jewelry50", 	 "Citizen_f", 	   	0.25, 	1, 		1);
	
	InitStdItemRarity(		"jewelry51", 	  "Solder_o", 	    0.20, 	1, 		1);
	InitStdItemRarity(		"jewelry51", 	   "Warrior", 	   	0.05, 	1, 		1);
	InitStdItemRarity(		"jewelry51", 	   "Monster", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"jewelry51", 	 "Citizen_f", 	   	0.25, 	1, 		1);
	
	InitStdItemRarity(		"jewelry52", 	  "Solder_o", 	   	0.20, 	1, 		5);
	InitStdItemRarity(		"jewelry52", 	   "Warrior", 	   	0.05, 	1, 		6);
	InitStdItemRarity(		"jewelry52", 	   "Monster", 	   	0.20, 	1, 		6);
	InitStdItemRarity(		"jewelry52", 	   "Citizen", 	   	0.10, 	1, 		5);
	InitStdItemRarity(		"jewelry52", 	 "Citizen_f", 	   	0.10, 	1, 		5);
	
	InitStdItemRarity(		"jewelry52", 	    "Solder", 	   	0.05, 	1, 		5);
	InitStdItemRarity(		"jewelry52", 	   "Warrior", 	   	0.05, 	1, 	   20);
	InitStdItemRarity(		"jewelry52", 	   "Citizen", 	   	0.15, 	1, 	   15);
	InitStdItemRarity(		"jewelry52", 	 "Citizen_f", 	   	0.10, 	1, 		5);
	
	// mineral's :)
	InitStdItemRarity(		 "mineral1", 	   "Citizen", 	   	0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral1", 	 "Citizen_f", 	   	0.30, 	1, 		1);
	
	InitStdItemRarity(		 "mineral2", 	   "Citizen", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		 "mineral2", 	 "Citizen_f", 	   	0.10, 	1, 		1);
	
	InitStdItemRarity(		 "mineral3", 	   "Citizen", 	   	0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral3", 	 "Citizen_f", 	   	0.10, 	1, 		1);
	
	InitStdItemRarity(		 "mineral4", 	    "Solder", 	    0.05, 	1, 		1);
	InitStdItemRarity(		 "mineral4", 	   "Warrior", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		 "mineral4", 	   "Monster", 	   0.005, 	1, 		3);
	InitStdItemRarity(		 "mineral4", 	   "Citizen", 	   	0.05, 	1, 		1);
	
	InitStdItemRarity(		 "mineral5", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral5", 	   "Citizen", 	   	0.01, 	1, 		1);
	
	InitStdItemRarity(		 "mineral6", 	 "Citizen_f", 	   	0.25, 	1, 		1);
	
	InitStdItemRarity(		 "mineral7", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral7", 	   "Warrior", 	    0.30, 	1, 		1);
	InitStdItemRarity(		 "mineral7", 	   "Monster", 	    0.10, 	1, 		3);
	InitStdItemRarity(		 "mineral7", 	   "Citizen", 	   	0.10, 	1, 		1);	

	InitStdItemRarity(		 "mineral8", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral8", 	   "Warrior", 	    0.10, 	1, 		1);
	InitStdItemRarity(		 "mineral8", 	   "Monster", 	    0.10, 	1, 		1);	
	
	InitStdItemRarity(		 "mineral9", 	    "Solder", 	     0.1, 	1, 		1);
	InitStdItemRarity(		 "mineral9", 	   "Warrior", 	     0.2, 	1, 		1);
	InitStdItemRarity(		 "mineral9", 	   "Monster", 	     0.1, 	1, 		1);		
	
	InitStdItemRarity(		"mineral10", 	    "Solder", 	     0.1, 	1, 		1);
	InitStdItemRarity(		"mineral10", 	   "Warrior", 	     0.1, 	1, 		1);
	InitStdItemRarity(		"mineral10", 	   "Monster", 	     0.1, 	1, 		1);	

	InitStdItemRarity(		"mineral11", 	 "Citizen_f", 	     0.1, 	1, 		1);
	InitStdItemRarity(		"mineral11", 	   "Warrior", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral11", 	   "Citizen", 	   	 0.1, 	1, 		1);		
		
	InitStdItemRarity(		"mineral13", 	  "Solder_o", 	     0.1, 	1, 		1);
	InitStdItemRarity(		"mineral13", 	   "Warrior", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral13", 	   "Monster", 	    0.05, 	1, 		1);
	
	InitStdItemRarity(		"mineral14", 	   "Monster", 	    0.15, 	1, 		1);
	
	InitStdItemRarity(		"mineral15", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"mineral15", 	   "Warrior", 	    0.15, 	1, 		1);
	InitStdItemRarity(		"mineral15", 	   "Monster", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral15", 	   "Citizen", 	   	0.10, 	1, 		1);		
	
	InitStdItemRarity(		"mineral16", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"mineral16", 	 "Citizen_f", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"mineral16", 	   "Warrior", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"mineral16", 	   "Monster", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"mineral16", 	   "Citizen", 	   	0.10, 	1, 		1);		
	
	InitStdItemRarity(		"mineral17", 	    "Solder", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"mineral17", 	 "Citizen_f", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"mineral17", 	   "Citizen", 	   	0.10, 	1, 		1);

	InitStdItemRarity(		"mineral18", 	  "Citizen", 	    0.01, 	1, 		1);
	InitStdItemRarity(		"mineral18", 	   "Warrior", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"mineral18", 	   "Soldier", 	    0.10, 	1, 		1);	
	
	InitStdItemRarity(		"mineral19", 	 "Citizen_f", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral19", 	   "Citizen", 	   	0.10, 	1, 		1);
	
	InitStdItemRarity(		"mineral20", 	 "Citizen_f", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral20", 	   "Citizen", 	   	0.05, 	1, 		1);
	
	InitStdItemRarity(		"mineral21", 	 "Citizen_f", 	    0.01, 	1, 		1);
	InitStdItemRarity(		"mineral21", 	   "Citizen", 	   	0.01, 	1, 		1);
	InitStdItemRarity(		"mineral21", 	 "Soldier_o", 	   	0.01, 	1, 		1);
	
	InitStdItemRarity(		"mineral22", 	    "Solder", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral22", 	   "Warrior", 	    0.01, 	1, 		1);
	InitStdItemRarity(		"mineral22", 	   "Citizen", 	   	0.05, 	1, 		1);		

	InitStdItemRarity(		"mineral23", 	    "Solder", 	    0.07, 	1, 		1);
	InitStdItemRarity(		"mineral23", 	   "Warrior", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral23", 	   "Citizen", 	   	0.10, 	1, 		1);		
	
	InitStdItemRarity(		"mineral24", 	    "Solder", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral24", 	   "Warrior", 	    0.05, 	1, 		1);
	InitStdItemRarity(		"mineral24", 	 "Soldier_o", 	   	0.10, 	1, 		1);		
	
	InitStdItemRarity(		"mineral25", 	 "Soldier_o", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"mineral26", 	   "Soldier", 	   	0.01, 	1, 		1);		
	InitStdItemRarity(		"mineral26", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"mineral27", 	 "Citizen_f", 	    0.01, 	1, 		1);
	
	InitStdItemRarity(		"mineral30", 	 "Soldier_o", 	    0.05, 	1, 		1);
	
	InitStdItemRarity(		"mineral31", 	   "Monster", 	   0.10, 	1, 		1);
	
	InitStdItemRarity(		"mineral33", 	   "Monster", 	   0.10, 	1, 		1);
	
	InitStdItemRarity(		"mineral34", 	 "Citizen_f", 	   0.10, 	1, 		1);
	
	InitStdItemRarity(		"mineral35", 	   "Citizen", 	   0.05, 	1, 		1);
	// �����
	InitStdItemRarity(		"cannabis1", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis1", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis1", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis1", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"cannabis2", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis2", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis2", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis2", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"cannabis3", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis3", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis3", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis3", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"cannabis4", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis4", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis4", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis4", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"cannabis5", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis5", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis5", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis5", 	   "Citizen", 	   	0.05, 	1, 		1);		
	
	InitStdItemRarity(		"cannabis6", 	    "Solder", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis6", 	 "Citizen_f", 	    0.10, 	1, 		1);
	InitStdItemRarity(		"cannabis6", 	   "Warrior", 	   0.001, 	1, 		1);
	InitStdItemRarity(		"cannabis6", 	   "Citizen", 	   	0.05, 	1, 		1);

	InitStdItemRarity(		"gold_dublon", 	  "Solder_o", 	    0.20, 	1, 		5);
	InitStdItemRarity(		"gold_dublon", 	    "Solder", 	    0.10, 	1, 		2);
	InitStdItemRarity(		"gold_dublon", 	   "Warrior", 	    0.15, 	1, 		3);
}

