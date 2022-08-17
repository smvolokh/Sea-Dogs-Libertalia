// boal 13.05.05
int scx, scy, spx, spy, sgxy, ssxy, smxy;
int move_i, dir_i, dir_i_start;
bool openExit;
int  money_i, moneyOp_i;
string money_s;

ref npchar;

int cardsPack[36], cardsP[36], cardsN[36];
int howCard;

int howPchar, howNpchar;
int iRate, iMoneyP, iMoneyN, iChest, iExpRate;
int bStartGame;

int iTurnGame;
int iHeroLose, iHeroWin;

void InitInterface(string iniName)
{
    GameInterface.title = "";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("My_eventMoveImg","MoveImg",0);
	SetEventHandler("My_eStartGame","StartGame",0);
	SetEventHandler("My_eOpenCards","OpenCards",0);
	/*
	hearts_A,diamonds_A,clubs_A,spades_A  - 124x184
	blank - 124x184
	pack -  186x202
	gold, silver   - 100x100
	A - ace
	J - Jack
	Q - Queen
	K - King
	10..6 - other
	
	screen: -40..680 x -30..510  (720x540)
	*/
	
    sgxy = 50;
    ssxy = 70;
    
    scx = 114;
    scy = 170;
    
    spx = 172;
    spy = 188;
    
    openExit = false;  // ����� �� �������� ����
    
    pchar = GetMainCharacter();
    
    iRate  = sti(pchar.GenQuest.Cards.iRate); // ������ �������
    
    //pchar.GenQuest.Cards.npcharIdx = GetCharacterIndex("Filosof"); // test
    
    npchar = GetCharacter(sti(pchar.GenQuest.Cards.npcharIdx));
    
    switch (iRate)
    {
        case 100 :
            money_s = "silver";
            SetNewPicture("SCROLLPICT", "interfaces\card_desk_1.tga");
            iExpRate = 1;
        break;
        
        case 500 :
            money_s = "silver";
            SetNewPicture("SCROLLPICT", "interfaces\card_desk_1.tga");
            iExpRate = 2;
        break;
        
        case 1000 :
            money_s = "gold";
            SetNewPicture("SCROLLPICT", "interfaces\card_desk_1.tga");
            iExpRate = 3;
        break;

        case 5000 :
            money_s = "gold";
            SetNewPicture("SCROLLPICT", "interfaces\card_sukno2.tga");
            iExpRate = 6;
        break;
		
		case 10000 : // Jason ������ ������
            money_s = "gold";
            SetNewPicture("SCROLLPICT", "interfaces\card_sukno2.tga");
            iExpRate = 8;
        break;
    }
    if (money_s == "gold")
    {
        smxy = sgxy;
    }
    else
    {
        smxy = ssxy;
    }
    CreateImage("BLANK","","", 0, 0, 0, 0); // ���� ����
    
	CreateImage("Pack","CARDS","pack", 40, 203, 20 + spx, 199 + spy);

    SetNewPicture("ICON_2", "interfaces\PORTRAITS\64\face_" + pchar.faceId+ ".tga");
	SetNewPicture("ICON_1", "interfaces\PORTRAITS\64\face_" + npchar.faceId+ ".tga");
    
    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY, 613,348,SCRIPT_ALIGN_CENTER,1.1);
    CreateString(true,"MoneyInChest","",FONT_NORMAL,COLOR_MONEY,615,292,SCRIPT_ALIGN_CENTER,1.3);
    
    if (rand(1) == 1)
    {
        dir_i  = -1;  // ��� ����� - ����
    }
    else
    {
        dir_i  = 1;  // ��� ����� - ��
    }
    dir_i_start = dir_i; // �������� ��� �����
    
    CreateString(true,"Beta_P", "", "INTERFACE_NORMAL",COLOR_NORMAL, 280, 370, SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Beta_N", "", "INTERFACE_NORMAL",COLOR_NORMAL, 280, 210, SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Beta_Next", "", "INTERFACE_NORMAL",COLOR_NORMAL, 230, 250, SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Beta_MoneyN", "", "INTERFACE_NORMAL",COLOR_NORMAL, 530, 210, SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"Beta_WinLose", "", "INTERFACE_ULTRASMALL",COLOR_NORMAL, 530, 370, SCRIPT_ALIGN_LEFT,1.0);
    // ����� ����
    NewGameBegin();
    iTurnGame = 1; // ���� ������
    iHeroLose = 0;
    iHeroWin  = 0;
}

void ProcessBreakExit()
{
	Exit();
}

void ProcessCancelExit()
{
	Exit();
}

void Exit()
{
    if (openExit)
    {
        DelEventHandler("InterfaceBreak","ProcessBreakExit");
    	DelEventHandler("exitCancel","ProcessCancelExit");
    	DelEventHandler("ievnt_command","ProcessCommandExecute");
    	DelEventHandler("My_eventMoveImg","MoveImg");
    	DelEventHandler("My_eStartGame","StartGame");
    	DelEventHandler("My_eOpenCards","OpenCards");

        if (sti(pchar.GenQuest.Cards.SitType) == true)
    	{
			if(npchar.id == "AffairOfHonor_WolvesAndSheeps_Man")
			{
				DoQuestFunctionDelay("AffairOfHonor_AfterCards", 0.6);
			}
			else
			{
            DoQuestCheckDelay("exit_sit", 0.6);
    	}
    	}
        interfaceResultCommand = RC_INTERFACE_SALARY_EXIT;

    	Statistic_AddValue(Pchar, "GameCards_Win", iHeroWin);
    	AddCharacterExpToSkill(Pchar, SKILL_FORTUNE, iExpRate*5*iHeroWin);
    	AddCharacterExpToSkill(Pchar, SKILL_FORTUNE, iExpRate*2*iHeroLose);
    	Statistic_AddValue(Pchar, "GameCards_Lose", iHeroLose);
    	bQuestCheckProcessFreeze = true;
    	WaitDate("",0,0,0, 0, iTurnGame*15);
    	bQuestCheckProcessFreeze = false;
    	RefreshLandTime();
    	EndCancelInterface(true);
		// Jason ������ ������
		if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game")) // ���� ��������� ����
		{
			if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game.G1")) DoQuestCheckDelay("GoldenGirl_Game1Res", 1.0);
			if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game.G2")) DoQuestCheckDelay("GoldenGirl_Game2Res", 1.0);
			if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game.G3")) DoQuestCheckDelay("GoldenGirl_Game3Res", 1.0);
			if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game.G4")) DoQuestCheckDelay("GoldenGirl_Game4Res", 1.0);
		}
	}
	else
    {
        PlaySound("interface\knock.wav");
    }
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	ref chr = GetMainCharacter();

	switch(nodName)
	{
    	case "B_PACK":
    		if(comName=="activate" || comName=="click")
    		{
                if (openExit == true)
                {   // ��� ���� ����
                    if (bStartGame != 100)
                    {
                        dir_i = -dir_i_start;
                        dir_i_start = dir_i;
                        iTurnGame++;
                        NewGameBegin();
                        openExit = false;
                    }
                    else
                    {
                        PlaySound("interface\knock.wav");
                    }
                }
                else
                {   // �� ����� �����
                    if (bStartGame <2) break; // ��� �����
                    if (bStartGame == 100) break; // �����������
                    
                    if (dir_i == 1 && (iMoneyP - iRate) < 0)
                    {
                        PlaySound("interface\knock.wav");
                        SetFormatedText("INFO_TEXT", "���, ������� ���������? ���������� :)");
                        break;
                    }
                    if (dir_i == -1 && (iMoneyN - iRate) < 0)
                    {
                        PlaySound("interface\knock.wav");
                        SetFormatedText("INFO_TEXT", "� �� ����!!! ��� �� �����!");
                        break;
                    }
                    
                    if (dir_i == 1)
                    {
                        move_i = 0;
                        PlaySound("interface\took_item.wav");
                        PostEvent("My_eventMoveImg", 100);
                        
                        PutNextCoin();
                        money_i++;

                        iMoneyP = iMoneyP - iRate;
                        iChest += iRate;
                        howCard--;
                        cardsP[howPchar] = cardsPack[howCard];
                        howPchar++;
                    }
                    /*
                    else
                    {
                        PutNextCoinOp();
                        moneyOp_i++;
                        iMoneyN = iMoneyN - iRate;
                        iChest += iRate;
                        howCard--;
                        cardsN[howNpchar] = cardsPack[howCard];
                        howNpchar++;
                    }  */
                    ShowMoney();
                }
    		}
    	break;
    	
    	case "B_ICON_1":
    		if(comName=="activate" || comName=="click")
    		{
                if (dir_i == 1 && bStartGame != 100 && bStartGame > 1 && !openExit) // ������ �������� ���� ��� �����������
                {
                    dir_i = -1; // ����� ����
                    SetNextTip();
                    if (dir_i_start == -1)// ���� ������� ���� ������
                    {
                        SetFormatedText("INFO_TEXT", "�����������!!!");
                        bStartGame = 100;
                        PostEvent("My_eOpenCards", 2000);
                    }
                    else
                    {// ���� ������ ���� �������
                        SetFormatedText("INFO_TEXT", "���, ������ ��� �����.");
                        
                        move_i = 0;
                        PlaySound("interface\took_item.wav");
                        PostEvent("My_eventMoveImg", 500);
                        
                        PutNextCoinOp();
                        moneyOp_i++;
                        iMoneyN = iMoneyN - iRate;
                        iChest += iRate;
                        howCard--;
                        cardsN[howNpchar] = cardsPack[howCard];
                        howNpchar++;
                        ShowMoney();
                    }
                }
                else
                {
                    PlaySound("interface\knock.wav");
                }
    		}
    	break;
    	
    	case "B_ICON_2":
    		if(comName=="activate" || comName=="click")
    		{
                //PlaySound("interface\knock.wav");
    		}
    	break;
	}
}

void MoveImg()
{
    CreateImage("BLANK","CARDS","blank", 90+move_i*25, 210+ dir_i*move_i*22, 90 + scx+move_i*25, 210 + scy + dir_i*move_i*22);
    move_i++;
    if (move_i < 10)
    {
        PostEvent("My_eventMoveImg", 100);
    }
    else
    {
        CreateImage("BLANK","","", 0, 0, 0, 0);
        PlaySound("interface\button3.wav");
        // ���������� ��� ����� �� �����
        RedrawCards();
        
        // ������ ����, �� ����� ������� -->
        if (bStartGame < 2)
        {
            dir_i = -dir_i; // ����� ����
            bStartGame++;
            if (bStartGame == 1)  PostEvent("My_eStartGame", 500);
        }
        // ������ ����, �� ����� ������� <--
        SetNextTip();
        BetaInfo();
        CheckGame();
    }
}

void PutNextCoin()
{
    CreateImage("Money_"+money_i,"CARDS",money_s, 280+money_i*3, 280-money_i*3, 280+money_i*3 + smxy, 280-money_i*3 + smxy);
}
void PutNextCoinOp()
{
    CreateImage("Money_"+(18+moneyOp_i),"CARDS",money_s, 380+moneyOp_i*3, 280-moneyOp_i*3, 380+moneyOp_i*3 + smxy, 280-moneyOp_i*3 + smxy);
}

void PackShake()
{
    // ������ �����
    int  i;
    bool ok;
    int  nextCard;
    
    howCard = 0;
    while (howCard <36)
    {
        ok = false;
        while (!ok)
        {
            ok = true;
            nextCard = rand(35)+1;
            for (i=0; i<howCard; i++)
        	{
                if (nextCard == cardsPack[i])
                {
                    ok = false;
                    break;
                }
        	}
        	if (ok)
        	{
                cardsPack[howCard] = nextCard;
                //log_info(""+nextCard);
                howCard++;
                
        	}
    	}
    }
    /*howCard = 36;
    for (i=0; i<howCard; i++)
	{
        cardsPack[i] = i-20;
	}*/
}
void RedrawCards()
{
    int i;
    string sTemp;
    int k;
    k = scx;
    if (howPchar > 6)
    {
        k = scx/2;
    }
    for (i=0; i<howPchar; i++)
	{
        sTemp = "c"+cardsP[i];
        CreateImage("PCard"+i,"CARDS", NullCharacter.Cards.(sTemp).pic, 400 - howPchar*k/2 + i*k , 394, 400 - howPchar*k/2 + i*k + scx, 394 + scy);
	}
	k = scx;
	if (howNpchar > 6)
    {
        k = scx/2;
    }
	for (i=0; i<howNpchar; i++)
	{
        sTemp = "c"+cardsN[i];
        sTemp = NullCharacter.Cards.(sTemp).pic;
        if (!openExit)
        {
            sTemp = "blank";
        }
        CreateImage("PCard"+(18+i),"CARDS", sTemp, 400 - howNpchar*k/2 + i*k , 36, 400 - howNpchar*k/2 + i*k + scx, 36 + scy);
	}
    
}
void RedrawDeck()
{
    // ������� � �������
    int i;
    for (i=35; i>=0; i--)
	{
        CreateImage("Money_"+i,"","", 0, 0, 0, 0);
        CreateImage("PCard"+i, "", "", 0, 0, 0, 0);
	}
	money_i = 0; // ������ �������
    moneyOp_i = 0;
    iChest = 0; // �� ����
    
    iMoneyP = sti(pchar.Money);
    iMoneyN = sti(npchar.Money);
    ShowMoney();
    
    // ������ �����
    PackShake();
    howPchar  = 0; // ����� �� �����
    howNpchar = 0;
    SetNextTip();
    BetaInfo();
}

void SetNextTip()
{
    if (dir_i == 1)
    {
        if (bStartGame <2)
        {
            SetFormatedText("INFO_TEXT","������ ���� �����."+NewStr()+"����� ������!");
        }
        else
        {
            SetFormatedText("INFO_TEXT",LinkRandPhrase("���� ���!", "�����, �� ���� ���� �� �����...", RandSwear() + "���� ����� ����! �� ����������!"));
        }
    }
    else
    {
        if (bStartGame <2)
        {
            SetFormatedText("INFO_TEXT","������ ��� �����."+NewStr()+"����� ������!");
        }
        else
        {
            SetFormatedText("INFO_TEXT",LinkRandPhrase("��� ���!", "���������, ��� ��� �� �����...", "��-��, ����� �������..."));
        }
    }
}
int CountCardsP()
{
    int ret = 0;
    int i;
    string sTemp;
    
    for (i = 0; i < howPchar; i++)
    {
        sTemp = "c"+cardsP[i];
        ret += sti(NullCharacter.Cards.(sTemp).count);
    }
    return ret;
}

int CountCardsN()
{
    int ret = 0;
    int i;
    string sTemp;

    for (i = 0; i < howNpchar; i++)
    {
        sTemp = "c"+cardsN[i];
        ret += sti(NullCharacter.Cards.(sTemp).count);
    }
    return ret;
}
void BetaInfo()
{
    if (bBettaTestMode || isEquippedArtefactUse(pchar, "totem_13", 0.0, 2.0)) 
    {
        GameInterface.strings.Beta_P       = "���� ����� �����: " + CountCardsP();
        GameInterface.strings.Beta_N       = "����� ����� ���������: " + CountCardsN();
        GameInterface.strings.Beta_Next    = "������� ��������� �����: " + NextCardPack();
        GameInterface.strings.Beta_MoneyN  = "����� � ���������: " + MakeMoneyShow(iMoneyN, MONEY_SIGN,MONEY_DELIVER);
        GameInterface.strings.Beta_WinLose = "����� �����: " + (Statistic_AddValue(Pchar, "GameCards_Win", 0)+iHeroWin) + " ����� ���������: " + (Statistic_AddValue(Pchar, "GameCards_Lose", 0)+iHeroLose);
    }
}
int NextCardPack()
{
    string sTemp;
    int ret;
    
    sTemp = "c"+cardsPack[howCard-1];
    ret = sti(NullCharacter.Cards.(sTemp).count);
    
    return ret;
}
// ����� �����
void StartGame()
{
    move_i = 0;

    PlaySound("interface\took_item.wav");
    PostEvent("My_eventMoveImg", 100);

    if (dir_i == 1)
    {
        PutNextCoin();
        money_i++;

        iMoneyP = iMoneyP - iRate;

        howCard--;
        cardsP[howPchar] = cardsPack[howCard];
        howPchar++;
    }
    else
    {
        PutNextCoinOp();
        moneyOp_i++;
        iMoneyN = iMoneyN - iRate;
        howCard--;
        cardsN[howNpchar] = cardsPack[howCard];
        howNpchar++;
    }
    iChest += iRate;
    ShowMoney();
}

void ShowMoney()
{
    GameInterface.strings.Money        = MakeMoneyShow(iMoneyP,MONEY_SIGN,MONEY_DELIVER);
    GameInterface.strings.MoneyInChest = MakeMoneyShow(iChest,MONEY_SIGN,MONEY_DELIVER);
}

bool CheckGame()
{
    string sTemp;
    int   ok = 0;
    bool  ok1;
    bool  ret = false;
    
    if (CountCardsP() > 21)
    {
        ok = -1; // ������� ����
        sTemp = "��! �� � ���� �������! � �������.";
        iHeroLose++;
    }
    if (CountCardsN() > 21)
    {
        ok = 1; // ������� ��
        sTemp = RandSwear() + "� ���� �������! �� �������"+ GetSexPhrase("","�") +".";
        iHeroWin++;
    }
    if (ok != 0)
    {
        EndGameCount(ok);
        if (ok == 1) RedrawCards(); // ������� �������
        
		// Jason ������ ������
		if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game")) // ���� ��������� ����
		{
			if (ok == -1) // ������� ����
			{
				if (iMoneyP > iRate)
				{
					sTemp += NewStr() + RandPhraseSimple("������ ������!","����������!");
				}
				else
				{
					bStartGame = 100;//������� ������� ����� ����
					sTemp += NewStr() + "���, �������, � ��� ������ �� �������� ����� �� ������. �� ���������!";
					pchar.questTemp.GoldenGirl.Game.Fail = "true"; // �� ��������
				}
			}
			else
			{
				if (iMoneyN > iRate) // ���� ������ �� ����
				{
					if (iMoneyP > iRate)
					{
						sTemp += NewStr() + RandPhraseSimple("������ ������!","����������!");
					}
					else
					{
						bStartGame = 100;//������� ������� ����� ����
						sTemp += NewStr() + "���, ���� ������ ������ �������. �� ��������!";
						pchar.questTemp.GoldenGirl.Game.Fail = "true"; // �� ��������
					}
				}
				else
				{
					bStartGame = 100;//������� ������� ����� ����
					sTemp += NewStr() + "���, ��� ������ ������ �������. �� �������!";
					pchar.questTemp.GoldenGirl.Game.Win = "true"; // �� �������
				}
			}			
		}
		else
		{
			if (CheckNextGame() && rand(10) < 10) // ���� ������ �� ����
			{
				sTemp += NewStr() + RandPhraseSimple("��������?","��� �����?");
			}
			else
			{
				bStartGame = 100;//������� ������� ����� ����
				sTemp += NewStr() + "���, � ���� ������!";
			}
		}
        SetFormatedText("INFO_TEXT", sTemp);
        ret = true;
    }
    else
    {
        ok1 = (CountCardsN() > 16) && (CountCardsN() <22);
        // �����!!!!! -->
        if (!CheckAttribute(pchar, "questTemp.GoldenGirl.Game") && GetCharacterSkillToOld(pchar, SKILL_FORTUNE) + makeint(isEquippedArtefactUse(pchar, "totem_13", 0.0, 2.0)) < rand(12)) // Jason ������ ������
        {
            if (ok1 && (CountCardsN() + NextCardPack()) <= 21)
            {
                ok1 = false;
            }
            if (GetCharacterSkillToOld(pchar, SKILL_FORTUNE) - makeint(isEquippedArtefactUse(pchar, "totem_13", 0.0, 2.0)) < rand(10) && CountCardsN() < 17 && (CountCardsN() + NextCardPack()) > 21)
            {
                ok1 = true;
            }
        }
        // �����!!!!! <--
        
        if (ok1 || (iMoneyN - iRate) < 0)
        {
            if (dir_i == -1 && dir_i_start == 1)// ���� ����� ���������
            {
                SetFormatedText("INFO_TEXT", "��� ������. �����������!");
                bStartGame = 100;
                PostEvent("My_eOpenCards", 2000);
                ret = true;
            }
            if (dir_i == -1 && dir_i_start == -1)// ���� ��������
            {
                dir_i = 1;
                SetFormatedText("INFO_TEXT", "������ �� ����! ��� ������.");
                ret = true;
            }
        }
        else
        {
            if (dir_i == -1 && bStartGame >= 2) // ���� ������ ���
            {
                move_i = 0;
                PlaySound("interface\took_item.wav");
                PostEvent("My_eventMoveImg", 500);

                PutNextCoinOp();
                moneyOp_i++;
                iMoneyN = iMoneyN - iRate;
                iChest += iRate;
                howCard--;
                cardsN[howNpchar] = cardsPack[howCard];
                howNpchar++;
                ShowMoney();
                
                ret = true;
            }
        }
    }
    return ret;
}

void NewGameBegin()
{
    RedrawDeck(); // ����� ����
    bStartGame = 0;
    SetFormatedText("INFO_TEXT","����� �����. "+NewStr()+"������ ������.");
    PostEvent("My_eStartGame", 1000);
}

void EndGameCount(int who)
{
    openExit = true;
    if (who == 1) // ��
    {
        AddMoneyToCharacter(pchar, iChest - (sti(pchar.Money) - iMoneyP));
        AddMoneyToCharacter(npchar,  -(sti(npchar.Money) - iMoneyN));
    }
    else
    {
        AddMoneyToCharacter(pchar, -(sti(pchar.Money) - iMoneyP));
        AddMoneyToCharacter(npchar, iChest - (sti(npchar.Money) - iMoneyN));
    }
}

void OpenCards();
{
	int iRes = 0; // Jason ������ ������
    string sTemp;
    if (CountCardsP() > makefloat(CountCardsN() + 0.1*dir_i_start)) // ������������ ����, ��� ����� (�� ����� ���������)
    {
        EndGameCount(1);
        sTemp = RandSwear() + "�� �������"+ GetSexPhrase("","�") +". � ���� " + CountCardsP() +", � ���� " + CountCardsN()+"." ;
        iHeroWin++;
		iRes = 1; // Jason ������ ������ ������� ��
    }
    else
    {
        EndGameCount(-1);
        sTemp = "����� �� ���� �������. � ���� " + CountCardsN() +", � ���� " + CountCardsP()+". � �������!";
        iHeroLose++;
		iRes = -1; // Jason ������ ������ ������� ����
    }
	// Jason ������ ������
	if (CheckAttribute(pchar, "questTemp.GoldenGirl.Game")) // ���� ��������� ����
	{
		if (iRes == -1) // ������� ����
		{
			if (iMoneyP > iRate)
			{
				sTemp += NewStr() + RandPhraseSimple("������ ������!","����������!");
				bStartGame = 2;
			}
			else
			{
				bStartGame = 100;//������� ������� ����� ����
				sTemp += NewStr() + "���, �������, � ��� ������ �� �������� ����� �� ������. �� ���������!";
				pchar.questTemp.GoldenGirl.Game.Fail = "true"; // �� ��������
			}
		}
		else
		{
			if (iMoneyN > iRate) // ���� ������ �� ����
			{
				if (iMoneyP > iRate)
				{
					sTemp += NewStr() + RandPhraseSimple("������ ������!","����������!");
					bStartGame = 2;
				}
				else
				{
					bStartGame = 100;//������� ������� ����� ����
					sTemp += NewStr() + "���, ���� ������ ������ �������. �� ��������!";
					pchar.questTemp.GoldenGirl.Game.Fail = "true"; // �� ��������
				}
			}
			else
			{
				bStartGame = 100;//������� ������� ����� ����
				sTemp += NewStr() + "���, ��� ������ ������ �������. �� �������!";
				pchar.questTemp.GoldenGirl.Game.Win = "true"; // �� �������
			}	
		}
	}
	else
	{
		if (CheckNextGame() && rand(10) < 10) // ���� ������ �� ����
		{
			sTemp += NewStr() + RandPhraseSimple("��������?","��� �����?");
			bStartGame = 2;
		}
		else
		{
			bStartGame = 100;//������� ������� ����� ����
			sTemp += NewStr() + "���, � ���� ������!";
		}
	}
    SetFormatedText("INFO_TEXT", sTemp);
    RedrawCards();
}
bool CheckNextGame()
{
    bool ret = true;
    if (iRate*3 > iMoneyN) ret = false;
    if (iRate*3 > iMoneyP) ret = false;
    
    return ret;
}