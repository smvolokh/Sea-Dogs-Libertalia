// ������ ���
void ProcessDialogEvent()
{
	ref NPChar, sld;
	string sTmp, sLoc;
	aref Link, NextDiag;

	ref    	rItm, rItem;
	string 	attr, attrLoc, sGun, sBullet, attrL, sAttr;
	int    	iTemp, iTax, iFortValue, i;
	aref 	rType;

	int iHour;
	int iRnd = -1;
	int iAns;
	string sLocation;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
	}
    if (CheckNPCQuestDate(npchar, "Card_date"))
	{
		SetNPCQuestDate(npchar, "Card_date");
		npchar.money = 5000 + (rand(10)+1) * makeint(100 * 	sti(PChar.rank) * (10.0 / MOD_SKILL_ENEMY_RATE));
	}
	switch(Dialog.CurrentNode)
	{

case "First time":
dialog.text = "������ ����, ������� ����! ��� ������ ���� ��� �������! � ���� ������ ����?";
link.l1 = "�����������! � ��� �������"+ GetSexPhrase("","�") +", �� ������ �� ��� ��������������? ������ �� ������ ������� ���� ����������.";
link.l1.go = "companion";
link.l2 = "���������, ����?";
link.l2.go = "Trade_1";
link.l3 = "����������, ����! �� �������� �� ��������, ��������� �� ���?";
link.l3.go = "Play_Game";
link.l4 = "� ������ ����� ����� ���������������� ����! �����!";
link.l4.go = "exit";	
break;

		case "companion":
		Dialog.Text = "���� �� ������� ���, ������, �� ������� ��� ;) �������� �� ���� Navy, ��������, ��� �� ��� ������� :)";
		link.l1 = "�����������!!!!";
		link.l1.go = "exit";
		//��� � ����.
		if (CheckAttribute(NPChar, "Companion_Talk") && GetNpcQuestPastDayParam(NPChar, "Companion_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("� ���� �� �������.", "�� ��� �������� �� ����, ����.");
			link.l1 = RandPhraseSimple("��� � ���"+ GetSexPhrase("","��") +" ������?!", "� ������. �����!");
			link.l1.go = "exit";
			break;
		}
		//������� ���?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("��� ���� �����? ��� � ���� ���� ������ � �����?", "������� ����� ������� �����, ����, � ����� ������ ���-�� ���������	...");
link.l1 = RandPhraseSimple("�� ����������, ����, ����� � ���� ����� �����!", "��, ��� ��������� �������������... �� ��������.");
			link.l1.go = "exit";
			break;
		}
		//�� ���� ������
		if (sti(pchar.questTemp.Indian.relation) < 89)
		{
			Dialog.Text = RandPhraseSimple("�� �� ���� ������, � �� ���	�� � �����.", "� �� ���� ���� �� �����, �� �� ���� ������.");
link.l1 = RandPhraseSimple("��, ��� ������...", "��� �, ��������� ����������.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//���� �� ����� ��� ����������
		if (GetCompanionQuantity(pchar) > 7)
		{
			Dialog.Text = RandPhraseSimple("� ���� ������ ����� �����, � �� ����� � �����.", "� ���� � ��� ����� �����, ����� ���� ��� ����?");
			link.l1 = "��... ����� ����� �� � ����.";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
break;
		}
		if (SetCompanionIndex(pchar, -1, sti(NPChar.index)) != -1)
		{
			Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
					RandPhraseSimple("� ����� �� �����, ����! ������ �� ����� ����� ������!", "�� ���� ������� ����, ������ �� ������ ����� ��������!"), 
					LinkRandPhrase("� ��������. ������ �� ����� ����� ������.", 
					"���� ��� ������������, ��� � ������ ���� �� �����! � ��������.", "� ����� �� �����. ������ � ��� ���� ������ �� �����, ����."));
			link.l1 = RandPhraseSimple("�������, ��� ���� � ����!", "�� �����! �� ����� �������� ��������.");
			link.l1.go = "exit_company";
			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
            	NPChar.Payment = true;
                
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			SetCharacterRemovable(NPChar, true);
			SaveCurrentNpcQuestDateParam(NPChar, "Companion.CheckRelation");
		}
		else
		{
			Dialog.Text = RandPhraseSimple("� ���� ������ ����� �����, � �� ����� � �����.", "� ���� � ��� ����� �����, ����� ���� ��� ����?");
			link.l1 = "��... ����� �� � ����.";
			link.l1.go = "exit";
		}
		break;

		
	// �� ��������
		case "tieyasal":
			dialog.text = "���� ������ ����, ����. � ����� �� ����� � � ���� �����!";
			link.l1 = "�������, ����! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ����� ������������?";
			link.l1 = "������� �����. � ���� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21_1");
			npchar.quest.Tieyasal = "teleport";
		break;

//  ������� ��� ���������� -->			
			case "Companion_Tasks":
			dialog.Text = "����������� ������.";
			Link.l1 = "��� �������� ��������.";
			Link.l1.go = "Companion_TaskBoarding";
			Link.l2 = "��� �������� ������ �������.";
			Link.l2.go = "Companion_TaskChange";
			Link.l3 = "���� ������.";
			Link.l3.go = "exit_company";
			break;

		case "Companion_TaskBoarding":
			dialog.Text = "��� �������?";
			Link.l1 = "� ���� ����� �� �� ���� ������� �� �������. �������� ���� � ���� �������.";
			Link.l1.go = "Companion_TaskBoardingNo";
			Link.l2 = "��� ����� ����� �� ���� ��������� ������� �� �������.";
			Link.l2.go = "Companion_TaskBoardingYes";
		break;
		
		case "Companion_TaskChange":
			dialog.Text = "��� �������?";
			Link.l1 = "� ���� ����� �� �� ����� ���� ������� ����� ��������. �� ������� �����.";
			Link.l1.go = "Companion_TaskChangeNo";
			Link.l2 = "����� ������ ����� ������ �� �������, ��������, ����� �������� ��������� �����, ����� ���� ����.";
			Link.l2.go = "Companion_TaskChangeYes";
		break;
		
		case "Companion_TaskBoardingNo":
			dialog.Text = "������.";
			Link.l1 = "������.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = false;
		break;
		
		case "Companion_TaskBoardingYes":
			dialog.Text = "����� ���������.";
			Link.l1 = "������.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = true;
		break;
		
		case "Companion_TaskChangeNo":
			dialog.Text = "��� �����.";
			Link.l1 = "������.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = false;
		break;
		
		case "Companion_TaskChangeYes":
			dialog.Text = "����� ���������.";
			Link.l1 = "������.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = true;
		break;
// ������� ��� ����������  <--

//  ������ -->	
	
		case "exit_quest":
			Dialog.Text = "� �� ������, ��� ��� ���� �� ���� �����!";
			link.l1 = "��-��. � �����...";
			link.l1.go = "exit_1488";
		break;

		case "exit_1488":
		NextDiag.CurrentNode = "exit_quest";
		DialogExit();
		break;
		
		case "Exit_ShowParam":
			NextDiag.CurrentNode = "First time";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;

	case "Exit_ShowParam_1488":
			NextDiag.CurrentNode = "Quest_1_End";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;


			case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "exit_duel":
			NextDiag.CurrentNode = "exit_1";
			DialogExit();
		break;

		case "exit_1":	
			Dialog.Text = "�� ������� � ����, ��������.";
			link.l1 = "������-������, �� �� �������������."; 
			link.l1.go = "exit_duel";
		break;	

		case "exit_sit":			
			NextDiag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

		case "exit_company":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
		break;

	case "exit_huber":
			NextDiag.CurrentNode = "Gover_Main";
			DialogExit();
		break;

case "exit_228":	
Dialog.Text = "���-�� ���?";
link.l1 = "�� ���, ������."; 
link.l1.go = "exit_uvol";
break;
	
case "exit_uvol":
NextDiag.CurrentNode = "exit_228";
DialogExit();
break;
	
case "exit_148":
NextDiag.CurrentNode = "Quest_1_End";
DialogExit();
break;

// ������ <--

//  ������� -->	

case "exit_2":
dialog.Text = "������ ����, ����!";
Link.l1 = "������ ��� �������!";
Link.l1.go = "prikaz";
if (CheckAttribute(NPChar, "IsCompanionClone"))
			{
	dialog.text = "��, ����?";
	Link.l1 = "� ���� ���� ��� ���� ��������� ��������.";
	Link.l1.go = "Companion_Tasks";
			}
	if (IsCompanion(NPChar))
			{
	dialog.Text = "����� �� ����� ������ � ����!";
	Link.l1 = "��, � ���� ���.";
	Link.l1.go = "exit_company";
			}
		break;

case "prikaz":
dialog.Text = "��, ����?";
if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l1 = ""+npchar.name+", � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. �� ����� ����������� �� ����� ���������?";
				Link.l1.go = "tieyasal";
			}
			
			if (isOfficer(Npchar)) // �������� ��� �������, ��� �������� ���
			{
				Link.l2 = "������ ��� ������!";
				Link.l2.go = "stay_follow";
			}

           		// boal ����� � �������
			if(CheckAttribute(NPChar, "treasurer") && NPChar.treasurer == 1)
			{
			    Link.l3 = "��� ��� ������ ����� � �������, " + GetStrSmallRegister(XI_ConvertString("treasurer")) + ".";
			    Link.l3.go = "QMASTER_1";
			        
			    // Warship. ����������� ������
			    if(!CheckAttribute(PChar, "TransferGoods.Enable"))
			    {
				    Link.l11 = "� ����, �����, �� ����� ������� � �������, �� ������� ������.";
				    Link.l11.go = "TransferGoodsEnable";
			    }
			    else
			    {
				    Link.l11 = "������, �������� ������ � �������� �� �����.";
				    Link.l11.go = "TransferGoodsDisable";
			    }
			}
			
			if (pchar.location != "My_Campus") // patch-5
			{
			Link.l4 = "� ����� �� �������� � ����� �������.";
			Link.l4.go = "AsYouWish";
			}
			
			
			// �� ��� ������� ��������� ����� �� ��� ���������  -->
			if(IsEntity(loadedLocation))
			{
				if(CheckAttribute(loadedLocation, "fastreload"))
				{
					iTemp = FindColony(loadedLocation.fastreload);
					if(iTemp != -1)
					{
						sld = GetColonyByIndex(iTemp);
						if(sti(sld.HeroOwn) == true && !CheckAttribute(sld, "OfficerIdx"))
						{
							NPChar.ColonyIdx = iTemp;
							Link.l5 = "� �������� ���� ����������� ����� ������!";
							Link.l5.go = "Gover_Hire";
						}
					}
				}
			}
			
			Link.l6 = "������. ������.";
			Link.l6.go = "exit_company";
		break;
		
		case "TransferGoodsEnable":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
	        {
				dialog.text = "�������, ����� ������?! ����� ������� ������� ���-������ ���������!";
				Link.l1 = "��, �� ����.";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
	        }
	        	
			PChar.TransferGoods.Enable = true;
		//	PChar.TransferGoods.TreasurerID = NPChar.id;
			Dialog.text = "����� ���������, "+ GetSexPhrase("��������","�������") +" �������!";
			Link.l1 = "������.";
			Link.l1.go = "TransferGoodsEnable_2";
        break;
        	
		case "TransferGoodsEnable_2":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
			LaunchTransferGoodsScreen(); // ��������� ����������� �������
		break;
		
		case "TransferGoodsDisable":
			DeleteAttribute(PChar, "TransferGoods.Enable");
			Dialog.text = "����� ���������, "+ GetSexPhrase("��������","�������") +" �������.";
			Link.l1 = "������.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;


case "QMASTER_1":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
			{
				dialog.text = "�������, �� � ��� ���� ��� �������!";
				Link.l1 = "�������, ��������...";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
			}
			
			dialog.text = "������������ ���������� ���� � ����� " +
			FloatToString(50.0 / (2.0+GetSummonSkillFromNameToOld(PChar, SKILL_REPAIR) + GetSummonSkillFromNameToOld(PChar,SKILL_SNEAK)), 1) +
			"% �� ���������� �����. �� "+GetCrewQuantity(PChar) + " �������� ����� " + makeint((GetCrewQuantity(PChar)+6) / 10) + " ��������� � ����. ��� ��� ����� ����������� �����.";
			Link.l1 = "�������.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;
        
        case "stay_follow":
            dialog.Text = "����� ����� ����������?";
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l4 = "� ����, ����� �� �������� �� ������������ ���������� �� ����.";
				Link.l4.go = "TargetDistance";
			}
            Link.l1 = "���� �����!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "������ �� ���� � �� ��������!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "����� �������� ��� ���������� ��� ������ �������������� ������.";
					Link.l3.go = "SetGunBullets";
				}	
			}		
		break;

		case "SetGunBullets":
			Dialog.Text = "����� ���� ���������� :";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = "exit_2";
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
		case "TargetDistance":
			dialog.text = "�� ����� ������, �������? ������� � ������, �� �� ����� 20-��.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "�������, ��� �� ������ ���!";
				link.l1 = "������, �������� �����...";
				link.l1.go = "exit_company";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "� ���� ������ �� �����, ������ �� ��������. ��� ��� ����������, �������?";
				link.l1 = "��, ������ ��� �� ���� � ���������.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "� ������� �������, ��� ����� 20 ������ �� ���� ��� ��������� ������.";
				link.l1 = "������, ������� �� ���������� � 20 ������.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "������ �����, �������� � ��������.";
			link.l1 = "������.";
			link.l1.go = "exit_company";
			npchar.MusketerDistance = iTemp;
		break;

		case "AsYouWish":
			// �������� �� ���� -->
			if (bSeaActive)
			{
				attr = Sea_FindNearColony();
				if (attr == "none")
				{
					dialog.text = "�������, ���� ��� � ��������� ������� ������ ��������� - ������� ������� � ����� ������� �� ������. ��� �� ������ ������ ��������� ���� �� ����?";
					Link.l1 = "��... ���, � �� ��� ����"+ GetSexPhrase("","�") +" � ����. ���������, ���� �� ����� � ����.";
					Link.l1.go = "exit_company";	
					break;	
				}
			}
			// �������� �� ���� <--
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) < 41) //����� ������ ������
			{
				dialog.text = RandPhraseSimple(LinkRandPhrase("��� ��� �������!","� ����� ��� �������?!","� ���� ��� �����?!"), RandPhraseSimple("�������, �� � ���� ���? �������� ����� ������� �� � ����, �� � ����!","���! � ��� ��� � ��� �� ������?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("� �����"+ GetSexPhrase("","�") +" ������� ������� � �������. �, ��������� ��� �� �������� ���� ��������������� � ���������,","���� ����������� ��������� �� ��� ������, ��� ������������� ��� �����, �������","����������� � ����������� � ���� ������� �� �����! �������"), LinkRandPhrase("��� ����� ��������, ��� �� ������ �������� ��� � ��������� �������, ��� ����� �������� � ������ ���. �������","��� ��������� ������� ���� ����������� �������, � �� �������"+ GetSexPhrase("","�") +" ������� �� ����������. ��� ���,","�� ��������� ��������� ����� � ����-�������� �� ����� � ����� ��� �����, �������� ������ �������� �� ������� ������. ��� �� ����� ������������ ����������, �������")) + " ��������� � ������ �����.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A1_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A1_strife";
				}
				break;	
			}
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) >= 41) // ����� ������ �����
			{
				dialog.text = RandPhraseSimple(RandPhraseSimple("���� � ������ ������� ������ �������?","��������� ����� ������� ����� ������ �������?"), RandPhraseSimple("����� �����������, �������","������ ����������. �� �������� �� ����� ���������."));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("���� ������������� �� ���������� ��� ��������� � ����� ������������.","� ���������, �� ���� �� ����� ��������� �������, � �������� ��� �� ������...","�� ������� ������, � �������� �� ������, �� ����� ���� ���� ����������. � �� ��������� ���� ������."), LinkRandPhrase("� ������������"+ GetSexPhrase("","�") +", ��� ������� � ���� ���� �������. ��� � ���� ���������� � ��� ��������, ������� ������ � ����� ������� �� �����?","������ �� ����, ������ �����, �� �����... �����, �� ������ �� ��������� ��������.","���� ����� �� ���������� ���� ������������, �� ������ � �������-�� ���"+ GetSexPhrase("��","��") +" ��������� ������."));
				Link.l1.go = "Get_out_A2";
				break;	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) >= 41) // ������ ������ ����� 
			{		
				dialog.text = RandPhraseSimple(RandPhraseSimple("��. ���� � ������ �������?","��� ��������� ���������. ���� � ������, ��� ��������� ��� �� ����������?"), RandPhraseSimple("����� �����������, �������.","�������, � ������ ��������� ������� ������ ���������?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("���� ���������� �� ���������� ���� ������������, �������","� ���������, �� ���� �� ����� ��������� �������. ��� ���,","��� ��������� ������� ���� ����������� ������. � �� �������"+ GetSexPhrase("","�") +" ������� �� ����������, ��� ���,"), LinkRandPhrase("�� ���� ����� �����, ��� ������ �� ���������� ������� � �������������. ����������� �� ��� ����� �� �����! � �� ����� �����������, ��� � ������ �� ���������"+ GetSexPhrase("","�") +" ���� �� ����... ��� ���,","���� ����������� �������� ������ ���� �����, �� ��� ���� ������� � ��������� ������ �������� ������. ��� ���,","���� ������������� �� ���������� ��� ��������� � ����� ������������. �������")) + " ��������� � ������ �����.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A3_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A3_strife";
				}	
				break;
	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) < 41) // ������ ������ ������
			{	
				dialog.text = RandPhraseSimple(LinkRandPhrase("�������, � ����� �� ������ ������ ��������! ����� ���������, ��� ���������?","�������, ��� �� ���� ��� �������?!","��� ��������� ��� ��������, �������?!"), RandPhraseSimple("��� �� ���, �������?! ��� ����� �� ���� ���������, � ��� - �� ����...","���! �����, �� ������ ���� ���� ��� ����������?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("�� ���������� ������� � ������� - ���� �� ����� � ���������� ��������. � � ��� ������� ����� ������"+ GetSexPhrase("","�") +". ��� ���,","�� ����� ���� �� �����������, �� ������ � �������-�� ���"+ GetSexPhrase("��","��") +" ��������� ������. ��� ���,","��� ����� ��������, ��� �� ������ �������� ��� � ��������� �������, ��� ����� �������� � ������ ���. �������"), LinkRandPhrase("��� ����� �� ����������, ��� ������� ������� �� ����� �� ��� �����, � �� ������� �������� ������������ ����������, ��� ���","� ������������"+ GetSexPhrase("","�") +", ��� ��� �������� ����� ��������. ������ � ����"+ GetSexPhrase("��","��") +" �� �� ���� ������ ���"+ GetSexPhrase("","�") +"? ��� ���,","������ ������� ������, �� ��������� ������� � ����-�������� �� ����� � ����� ��� �����. �������, �� �� �����, ��� ��� ����� ������������ ����������? ��� ���,")) + " ��������� � ����������.";
				Link.l1.go = "Get_out_A4";
				break;
			}
		break;
	
		case "Get_out_A1_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("��� ������ ���! �� �����, ���� ����. �� ������: � ��� � ������ �� �������. ��� ������� ������...","����������, ���� ���� � ������������ ��� ���� ���-�� �� �� ����. ��� ��� - ��������...", "�� � ���� � ����! ����������� �� ������ �����������. ���� ��� - '�����'!"), LinkRandPhrase("�� ��� � ��� ������� � �� ���������, �� �����, � �������� �����. ������� ����������� �������...","�� ���� ������ � ���� ������� �� ����� �����������. � ����-�������� ���� �� ������, ��� �� ������ - ���� ���������� �����...","������, �������, ���� ��-������. ��, ����� ���, � ���� �� ������ �����..."));
			Link.l1 = "����. ������ � �� ���� �������� ����� ��� �������. �� ������� �� ��� �������� � ����� ���������.";
			Link.l1.go = "exit_bad";
			Link.l2 = "��� � ������ � �����.";
			Link.l2.go = "Exit_Fire_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "�� ��������. � ����������"+ GetSexPhrase("","�") +" ���� �������� ������� "+sti(NPChar.rank)*500+" ����. �������, ��� ������ ��� �������.";
				Link.l3.go = "Get_out_�1_ForMoney";
			}
		break;

		case "Get_out_A1_strife":
			dialog.text = LinkRandPhrase("���������! ��� ������ '������ �����'?! �� ��� ���� � ���� ������ ��� ������� ����������, ���� �� ����� ���� ����������, ����� ����������!", "��! '������ �����'! �� �������, � ������� ���������� ����, ��� ������?!", "�������, �������, � ��������� �������� ��� ���� �� ��������. � �� ������� ���������� � �����, ��� � �������.");
			Link.l1 = "������, ���������. �� ���� ���� � �� ����� ��������� ������." ;
			Link.l1.go = "exit_bad";
			Link.l2 = "� �������� - ���� ������ ���������. ������ �������� ����.";
			Link.l2.go = "Get_out_A1_strife_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "�� ��������. � ����������"+ GetSexPhrase("","�") +" ���� �������� ������� "+sti(NPChar.rank)*500+" ����. �������, ��� ������ ��� �������.";
				Link.l3.go = "Get_out_�1_ForMoney";
			}
		break;

		case "Get_out_A1_strife_1":
			dialog.text = RandPhraseSimple("�� � � �� ���� �������� � ��� �������������. ������ ��� ����������� �������� ����� �� ���������!", "�� � ������ � ��� �� �������� �� ����� ������. ������ �������� ������� ��������� �����������!") + " "+sti(NPChar.rank)*1000+" ����, � �� ������� ���� � �����.";
			Link.l1 = "� ���������"+ GetSexPhrase("��","���") +"... ����� ��� ���������, � ����������� �� ����.";
			Link.l1.go = "exit_bad1";
			Link.l2 = "� ����� ������� ����� ���� ����, ���� �� ��������� ������� ���� ����? �� ��� ������� ��������� �� ��������������!";
			Link.l2.go = "Get_out_�1_strife_battle";
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l3 = "�����. ���� ���������� � �������� ��, � ��� �������.";
				Link.l3.go = "Get_out_�1_chang";
			}
		break;

		case "Get_out_�1_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "��, ��� ������ ������ ����. ��������!";
			Link.l1 = "�������, ���� ������ ������ �� �����������.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_�1_strife_battle":
			dialog.text = LinkRandPhrase("�������� ��� ������������ ��������� ��������. � ������ �� ������� ��� � ����� ����������! � ��� �������, ��� ����� �������� �� ����!", "��� �� ��������������, � ����������� �������� ������������ �������! � � � ������, ���� �� ��� ��� �� ������!", "� �������� ������� ����� ������� �� ������ � ���"+ GetSexPhrase("��� ���������","�� �����������") +" ��� ��. �� ��� ����� ����� ���� ����������� �������� ���������. ������ ���� �������������� ��������� ������.");
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l1 = "�����. ��� ���� ������... � ������ �������� ������!";
				Link.l1.go = "Get_out_�1_ForMoney_angry";
			}
			Link.l2 = "�� �����������! � �� ������� ������ ��������� �������� �� ���� �����!";
			Link.l2.go = "Get_out_�1_strife_death";
		break;

		case "Get_out_�1_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("good");
			dialog.text = "�����-�����, �������! ������, �����"+ GetSexPhrase("","�") +" �� ������ ���������� ���������!";
			Link.l1 = "����� ���, � ����� �� �����"+ GetSexPhrase("","�") +"!";
			Link.l1.go = "Get_out_fight";
		break;
	
		case "Get_out_�1_ForMoney_angry":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			OfficersReaction("bad");
			dialog.text = "��, ��� ������ ������ ����. ��������!";
			Link.l1 = "�������, ���� ������ ������ �� �����������.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_A2":
			dialog.text = RandPhraseSimple(LinkRandPhrase("�� ��� �, ������ �� ������. ��������, �������, �� ��������� �����...","����� ����, �������. ��, ����� ���, � ��������. ��������.","��, �������, ��� �� �������!.. ��������� ����������."), LinkRandPhrase("����, �������. ��� ����� ��������� ������� � ���.","��� ���� ��� ������... �� � ��� �� �����, ��������.","�� ������������� �� ���, �������. �� � ������ ���� �������. ��������."));
			Link.l1 = "����, � ���������"+ GetSexPhrase("","�") +". ����� ����� � ����� ��������� �����.";
			Link.l1.go = "exit_good";
			Link.l2 = "�� ���������. ����� ����...";
			Link.l2.go = "exit_fire_2";
			Link.l3 = "������... � ���� ������� ����������"+ GetSexPhrase("","�") +". ����� �� ������� ������� - ��� ��� ����� ����� ��������� �����...";
			Link.l3.go = "Return_items_A2";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l4 = "������... �� ���� ��������� ���� � ������� ������. ��� ����� "+sti(NPChar.rank)*500+" ����, ����������, ���� ������ ������ ����� ������.";
			}
			Link.l4.go = "Im_kind_A2";
		break;

		case "Return_items_A2":
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "�� � ��� ����, ������� ���������...";
			Link.l1 = "� ����"+ GetSexPhrase("","�") +", ��� �� ���� ��������� ������...";
			Link.l1.go = "Get_out_�2_chang";
		break;

		case "Im_kind_A2":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeOfficersLoyality("good_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "������� ���, �������! ����� ����������� ��������. � ���� ��� �������� ���-��� �� ����� �����, ����� ������� �� �������?";
			Link.l1 = "�� �������... ������ ����� ������� ������ �� ��� ��������...";
			Link.l1.go = "Get_out_�2_chang";
			Link.l2 = "�� �����. ������ ���� � ������ � ������ ��� ���� �������...";
			Link.l2.go = "exit_fire_2";
		break;

		case "Get_out_A3_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("�� ��� �, ���� ����. �� ������: � ��� � ������ �� �������, ���� ���� ������� �������� � ������.","����������, ���� ���������� ������� ��� ���� �� �� ����. ��� ���, ��� ���� ��� ������ ������ ���� ���������... � �� ����� ���������� ������� ������.","�� � ����������� �� ������ ������������. �� ����� ����� ���������� �������� � ����-�������� ����� ������. ������� �������, ������ ���� �������!"), LinkRandPhrase("����������, � ���� ���� ���� �� ����� � ����� ������. ������� � ������� ����� ����������� - �� � ��� ������ ������ �����������.","��, ���� �� ������ ��� ���������� � ������� ������� - �� ��� ��� ���� ����������. ������� ������ ���������� �� �������.","���� ������� ��, ��� ���� ��������� �������. ��������� ����������."));
			Link.l1 = "����. ������ �� ����� ������� ������ ���� ���������. �� ��� ��������� �������� � ����.";
			Link.l1.go = "exit_bad";
			Link.l2 = "���-���. �������� ��� ����� �����������.";
			Link.l2.go = "exit_fire_3";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "�������. ��� ���� �� ������ "+sti(NPChar.rank)*500+" ����. � �� ������ ��� �������, � ��� ����� ����� ����� ��������.";
				Link.l3.go = "Get_out_�3_ForMoney";
			}
		break;

		case "Get_out_�3_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("� �� ��� �������. ��������...", "��������� �� ���������. ��������� ����������.", "��� ������ �� � �������. ����� ��������...");
			Link.l1 = "� ����"+ GetSexPhrase("","�") +", ��� �� ���� ��������� ������...";
			Link.l1.go = "exit_fire_3";
		break;
	
		case "Get_out_A3_strife":
			dialog.text = LinkRandPhrase("��, �������, ��� ����� �������� � ������� ������ �� ����. �� �� �� ������ ��������� ���� � ������� ����� �� �������?", "�� ������������� �� ���, �������. �� � ����� ������ �����, ���� ������ ��������� �����������.", "� ��� ���� ������������� �� ��� ��� ������ �������? �����, ��� �������� ����������� ��� �� ��������.");
			Link.l1 = "�����, � ���������"+ GetSexPhrase("","�") +". ���� ���������, �� �� ��� ������� � ����� ���������.";
			Link.l1.go = "exit_bad";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l2 = "��, �� ���� ������ �� ����������. ����� "+sti(NPChar.rank)*500+" ����. �����, �� ������ ����� ������.";
				Link.l2.go = "Get_out_�3_ForMoney";
				Link.l3 = "� ��� ���� �����. ��, ��������� ���, �� ������� ���������� - ������� ����� �� �������.";
				Link.l3.go = "Return_items_A3";
			}
			Link.l4 = "���! � ��� �� ��������� ���������� ����� ����?! � ��� � ����"+ GetSexPhrase("","�") +", ��� �� ���������� ������ � ������������� �������.";
			Link.l4.go = "Get_out_A3_strife_1";
		break;

		case "Return_items_A3":
			dialog.text = "� ����, ��� �� ��� �������, �� ���������� ������� ������� ������, ����� � ������ "+sti(NPChar.rank)*1000+" ����. ��� ��� ������� ������� � � �����.";
			Link.l1 = "������, ����� ���� ������.";
			Link.l1.go = "Get_out_�3_chang";
			Link.l2 = "�� � ���� �� �� ���?! ��������� ����� ����� �� ��, ��� � ��� ���� ���������! ������, ����� ������ ��������, ��� ��������, ��-���� �������� ���� ��� ����� ��������� ������������.";
			Link.l2.go = "Get_out_A3_strife_1";
		break;

		case "Get_out_A3_strife_1":
			dialog.text = "�� �� ������ ���� ����������! �, ����� � �� ����� ������ �� �����, �� �� �� ������ ������. � �������� ������� ����, ���� ���"+ GetSexPhrase("���","��") +" ������ ��� ��!";
			Link.l1 = "���� ���� ��� �� ����, �� ������� - ������ �� ��������, �� ����� ������ �� ��������.";
			Link.l1.go = "Get_out_�3_strife_death";
		break;

		case "Get_out_�3_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("bad");
			dialog.text = "��, �� ��������������-�� � ������ � ����� ������!!";
			Link.l1 = "�� ��� �����! ��, ��� �, ��� ���������...";
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_A4":
			dialog.text = RandPhraseSimple(LinkRandPhrase("��� ��� ������! ��� ���� �� ������ ������, � ���� - ���, � ��� ��������� �������!","�� ��� � ��� �� ������� �����?! �� ������� ��������, ��� ���� ��� �� �������� ��� ���. �� � �� ����, ���� ������ �������...","��� �� ��! ��� ������ ���������� �� ��� - � �� �� �������������. ���� ��������� ���� �� ����� � �������� �� �����������!"), LinkRandPhrase("�� �����, ����� ���. ������ �� ������� ������� ��� ������ �����������.","�� ��� �, ���� ����. �� ������: ������� ������� ��� �� ����� �� �����.","������, �������, ���� ��-������. ��, ����� ��� - � ���� �� ������ �����..."));
			Link.l1 = "����. ������ �� ����� ������� ������ ���� ���������. �� ��� ��������� �������� � ����.";
			Link.l1.go = "exit_good";
			Link.l2 = RandPhraseSimple("�����-�����. � ��������� ����, ��� � ������� � ������� ����������.", "�����-�����. �� ����� �� ���� ������, ��� �� ������ ����.");
			Link.l2.go = "exit_fire_4";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "�������. ��� ���� �� ������ "+sti(NPChar.rank)*500+" ����. � �� ������ ��� �������, � ��� ����� ����� ����� ��������.";
				Link.l3.go = "Get_out_�4_ForMoney";
			}
			Link.l4 = "������... � ���� ������� ����������"+ GetSexPhrase("","�") +" - ������� ����� �� �������.";
			Link.l4.go = "Return_items_A4";
		break;

		case "Get_out_�4_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("��� �������, �������! ��� ��� �������...", "��������� �� ���������. ��������� ����������.", "��� ������ �� � �������. ����� ��������...");
			Link.l1 = "���������. ������ �� ������ �� ��� � ��������� �������.";
			Link.l1.go = "exit_fire_4";
		break;

		case "Return_items_A4":
			if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
			{
				dialog.text = LinkRandPhrase("��� ������ ��� � ���������� ���������! �� ������� ��� �� ��������! ��-���� � ������ �������...", "����, �� ���� ������� ������� ������. ��� �, ���������. ���� ������ ������ - �� �������...", "��������� �������! ������ ��� � ��������� ������. ��, ��������!.. ���������, ���� ��� �� �������...");
				Link.l1 = "�����-�����. �� ����� �� ���� ������, ��� �� ������ ����.";
				Link.l1.go = "Get_out_�4_chang_1";
			}
			else	
			{
				dialog.text = RandPhraseSimple("���� ��-������, �������, ������ ������� ������� ��� "+sti(NPChar.rank)*1000+" ����. ����� ������� ��� ������������ ��������� ��������.", "������. ������ �� ��� � ���� �������� "+sti(NPChar.rank)*1000+" ���� � �������� ����������� �� ������� ������.");
				if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
				{
					Link.l1 = "��� ��������! �����, ����� ���� ������.";
					Link.l1.go = "Get_out_�4_chang";
				}
				Link.l2 = "�� �� ����� ��������?! ������ ������� ������� ����� �� ��, ��� � ���"+ GetSexPhrase("","�") +" �� ���� ���"+ GetSexPhrase("","�") +"!";
				Link.l2.go = "Get_out_A4_strife";
				Link.l3 = "��-��! �� � �������"+ GetSexPhrase("","�") +"! ����� � ���� ���������� ������� �����, ��� ������� ������!";
				Link.l3.go = "exit_bad1";
			}
		break;

		case "Get_out_A4_strife":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "��, ����� ������ � �� ��������! � � ����� �� �������, ���� �� ������, ��� ������ ��� ������!";
			Link.l1 = RandPhraseSimple("������ �� ��������, ��� ������ ��� ������!", "������, ���� ������ ����� ������!");
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_fight":
			CheckForReleaseOfficer(GetCharacterIndex(Npchar.id));
			RemovePassenger(Pchar, Npchar);
			LAi_CharacterDisableDialog(NPChar);
			LAi_SetWarriorType(Npchar);
			LAi_group_MoveCharacter(Npchar, "TmpEnemy");
			LAi_group_SetHearRadius("TmpEnemy", 100.0);
			LAi_group_FightGroupsEx("TmpEnemy", LAI_GROUP_PLAYER, true, Pchar, -1, false, false);
			if (PChar.location == Get_My_Cabin() || findsubstr(PChar.location, "_tavern" , 0) != -1 || findsubstr(PChar.location, "_store" , 0) != -1)
            {
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
				LAi_group_SetCheck("TmpEnemy", "CannotFightCurLocation");
				LAi_group_SetCheck("TmpEnemy", "MainHeroFightModeOff");
            }
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

	    case "Get_out_�1_chang": // ��������� ������
			NextDiag.CurrentNode =  "Exit_228";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_�2_chang": // ��������� ������
			NextDiag.CurrentNode = "Fired_2";
			LAi_CharacterDisableDialog(NPChar);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_�3_chang": // ��������� ������
			NextDiag.CurrentNode = "Fired_3";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_�4_chang_1": // ��������� ������
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_�4_chang": // ��������� ������
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

	    case "exit_bad":
			Npchar.loyality = makeint(Npchar.loyality) - 3;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_bad1":
			Npchar.loyality = makeint(Npchar.loyality) - 2;
			ChangeOfficersLoyality("bad_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			NextDiag.CurrentNode = "exit_2";
		
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_good":
			Npchar.loyality = makeint(Npchar.loyality) - 1;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_fire_1":	//navy -->			
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_1";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = "exit_228";
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_2":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_2";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_3":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_3";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_4":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_4";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_5":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_1";
			OfficersReaction("good");
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "Fired_1":
			NextDiag.CurrentNode = "Fired_1";      
			dialog.text = "�� ���� ���? ��, �������, ��� �� ������! ���� ���� ������ �� ����� ����� �� �����.";
			Link.l1 = RandPhraseSimple("������-������. �������� ������.", "���-���. ���������� �� �����.");	
			Link.l1.go = "Exit_228";
		break;

		case "Fired_2":
			NextDiag.CurrentNode = "Fired_2"; 
			dialog.text = "���-�� ���, �������? ��� ��������, ��� �� ��� �� ������...";
			Link.l1 = "���, ������. ������ ����������� �����"+ GetSexPhrase("","�") +"...";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_3":
			NextDiag.CurrentNode = "Fired_3"; 
			dialog.text = "�������, ��� ������� ������, ��������� ���������. �� ������ �� �� ����� ����� ����� �������, ��� ����������.";
			Link.l1 = "���-���. �������� ������.";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_4":
			NextDiag.CurrentNode = "Fired_4"; 
			dialog.text = "�������, �� ����� ��� ����� ���� �������? �, ������� �� �������, ����� �� ��� ������, � �������� ������� ������������ �� ����...";
			Link.l1 = "���-���. ����� �� ��� ������, ������ ������ ������.";	 
			Link.l1.go = "Exit_228";
		break;
		
		// boal 05.09.03 offecer need to go to abordage -->
	    case "Boal_Stay":           //SetCharacterTask_Stay(Characters[Npchar.index]); // it's a mistic but here doesn't work :(
            //Log_SetStringToLog(Npchar.id +" "+Npchar.index);
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "���� �������� ����������!";
		    Link.l1 = "������.";
		    Link.l1.go = "exit_company";
		    Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
	    break;
		
	    case "Boal_Follow":
		    SetCharacterTask_FollowCharacter(Npchar, PChar); // it works here!!!
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "���� �������� ����������!";
		    Link.l1 = "������.";
		    Link.l1.go = "exit_company";
	    break;
        // boal 05.09.03 offecer need to go to abordage <--

//////////////////////////////    ������-��������� -->
		case "Gover_Hire":
            dialog.Text = "����� �� �����!";
            Link.l1 = "����� �� �������� � ������������ ������, � ���� ������ ���������� �� ��������� ��������.";
			Link.l1.go = "Exit_Gover_Hire";
            Link.l2 = "� ���������"+ GetSexPhrase("","�") +".";
            Link.l2.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
        break;

        case "Exit_Gover_Hire":
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            attr = sld.id + "_townhall";

            // ������ ��������� -->
			CheckForReleaseOfficer(sti(NPChar.index));
			RemovePassenger(pchar, NPChar);
			// ������ ��������� <--
		    sld.OfficerIdx = sti(NPChar.index);
			ChangeCharacterAddressGroup(NPChar, attr, "sit", "sit1");
			LAi_SetHuberTypeNoGroup(NPChar);
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
            LAi_LoginInCaptureTown(NPChar, true);
			//  �� -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_1");
			AddQuestUserData("Gen_CityCapture", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  �� <--
			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Main":
            iTemp = GetNpcQuestPastDayParam(NPChar, "GoverTalkDate");
            if (iTemp > 0)
            {
				dialog.Text = "����� ���� ����������? ��������� ��� ����� ��� " + FindRussianDaysString(iTemp) + " �����.";
			}
			else
			{
			    dialog.Text = "����� ���� ����������?";
			}

            Link.l1 = "����� ����� ������� �� " + NPCharSexPhrase(NPChar, "������", "�������") + " �� ������ ������?";
        	Link.l1.go = "Gover_Tax";
            Link.l8 = "�� " + NPCharSexPhrase(NPChar, "�����", "�����") + " ��� �� �������, � ������ ���� � ��������� ������.";
            Link.l8.go = "Gover_Fire";
			Link.l9 = "����� ��������.";
            Link.l9.go = "exit_huber";
            NextDiag.CurrentNode = "Gover_Main";
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
        break;

        case "Gover_Tax":
            iTemp = GetNpcQuestPastDayParam(NPChar, "StartTaxDate");
            iTax  = makeint((GetCharacterSkillSimple(NPChar, SKILL_COMMERCE) + GetCharacterSkillSimple(NPChar, SKILL_LEADERSHIP)) / 2);
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
			if (CheckAttribute(sld, "FortValue"))
			{
			    iFortValue = sti(sld.FortValue);
			}
			else
			{
			    iFortValue = 20;
			}
			NPChar.Gover_Tax_Sum = iFortValue*iTax*iTemp;
			dialog.Text = "��� ������ ��������� ��� �������� " + FindRussianMoneyString(iFortValue*iTax) + " � ����. �� " + FindRussianDaysString(iTemp) + " � " + NPCharSexPhrase(NPChar, "������", "�������") + " " + FindRussianMoneyString(sti(NPChar.Gover_Tax_Sum)) + ".";
			if (sti(NPChar.Gover_Tax_Sum) > 0)
			{
			    Link.l1 = "� ���� ������� ��� ����� �������.";
            	Link.l1.go = "Gover_Tax_Get";
			}
			Link.l2 = "��������� �� ������!";
            Link.l2.go = "exit_huber";
        break;

        case "Gover_Tax_Get":
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            AddMoneyToCharacter(Pchar, sti(NPChar.Gover_Tax_Sum));

			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Fire":
            dialog.Text = "������������! ���� ���������� ������ �� ��� ����.";
            Link.l8 = "��� � ������.";
            Link.l8.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
		sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            DeleteAttribute(sld, "OfficerIdx");
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
		AddDialogExitQuestFunction("PGG_BecomeHiredOfficer");
		
		DeleteAttribute(NPChar, "Quest.Officer");
		DeleteAttribute(NPChar, "PGGAi.Task");
		DeleteAttribute(NPChar, "PGGAi.LockService");	
		DeleteAttribute(NPChar, "OfficerIdx");
            //  �� -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_2");
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  �� <--
        break;
        //////////////////////////////    ������-��������� <--


//  ����  -->
case "Play_Game":
			dialog.text = "�����! ����� ������� �� ������ ��������... ������ ��������... � ����� ���� ������ �����?";
			link.l1 = "����������� � ����� �� �������� �������?";
			link.l1.go = "Cards_begin";
   			link.l2 = "�������� ������� � �����-������?";
			link.l2.go = "Dice_begin";
			link.l10 = "����� �������� ����, �� ���� ���� ����.";
			link.l10.go = "exit";
		break;

	//  ����� -->
        case "Card_Game":
            if (!CheckNPCQuestDate(npchar, "Card_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Card_date_Yet");
                dialog.text = "� �� ���� ������ � �����!";
    			link.l1 = "��� ����� ������.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Card_date_begin"))
				{
					dialog.text = "�����! ����� ������� �� ������ ��������... ������ ��������...";
	    			link.l1 = "������������.";
	    			link.l1.go = "Cards_begin";
	    			link.l2 = "�� ����� �������� ����?";
	    			link.l2.go = "Cards_Rule";
    			}
    			else
    			{
					dialog.text = "���� ��������, ��� ��� ���� ������������.";
	    			link.l1 = "��� ����� ������.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Cards_Rule":
   			dialog.text = CARDS_RULE;
			link.l1 = "��� �, ������� ������!";
			link.l1.go = "Cards_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Cards_begin":
			dialog.text = "�������! ����� ������ ����������� �� �������.";
			link.l1 = "������ �� 1000 ����.";
			link.l1.go = "Cards_Node_100";
			link.l2 = "������� �� 5000 ����.";
			link.l2.go = "Cards_Node_500";
	    		link.l3 = "������! �� ����� �������� ����?";
	    		link.l3.go = "Cards_Rule";
			link.l4 = "�������, ��� ����.";
			link.l4.go = "exit";
		break;

		case "Cards_Node_100":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "� �� ���� ������ � �����. ���� �������, ��� �� �������� � �����.";
                link.l1 = "��� ���� ���� ����!";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "������, " + GetAddress_Form(NPChar) + "? � ���� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "���! ���� ��������, ��� ��� ���� ������������...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 1000 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 1000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_Node_500":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "� �� ���� ������ � �����. ���� �������, ��� �� �������� � �����.";
                link.l1 = "��� ���� ���� ����!";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckCardsGameBigRate())
		    {
                dialog.text = "� ������, ��� �� ����� ������ �������. � �� ���� ������ � ����� �� ����� ������� ������.";
                link.l1 = "����� �� ����� ������ �������?";
			    link.l1.go = "Cards_Node_100";
				link.l2 = "������, ��� ����.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "������, " + GetAddress_Form(npchar) + "? � ���� ��� 15000 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "���� ��������, ��� ��� ���� ������������...";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 5000 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 5000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_begin_go":
            SetNPCQuestDate(npchar, "Card_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchCardsGame();
		break;
	    // ����� <--

	    //  ����� -->
        case "Dice_Game":
            if (!CheckNPCQuestDate(npchar, "Dice_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Dice_date_Yet");
                dialog.text = "� �� ���� ������ � �����!";
    			link.l1 = "��� ������.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Dice_date_begin"))
				{
					dialog.text = "�����! ����� ������� �� ������ ��������... ������ ��������...";
	    			link.l1 = "������������.";
	    			link.l1.go = "Dice_begin";
	    			link.l2 = "�� ����� �������� ����?";
	    			link.l2.go = "Dice_Rule";
    			}
    			else
    			{
					dialog.text = "���� ��������, ��� ��� ���� ������������.";
	    			link.l1 = "��� ����� ������.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Dice_Rule":
   			dialog.text = DICE_RULE;
			link.l1 = "��� �, ����� ������!";
			link.l1.go = "Dice_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Dice_begin":
			dialog.text = "������������! ������� ����������� �� �������.";
			link.l1 = "������ �� 500 ���� �� �����.";
			link.l1.go = "Dice_Node_100";
			link.l2 = "����� �� 2000 ���� �� �����.";
			link.l2.go = "Dice_Node_500";
			link.l3 = "������! �� ����� �������� ����?";
	    		link.l3.go = "Dice_Rule";
			link.l4 = "�������, ��� ����.";
			link.l4.go = "exit";
		break;

		case "Dice_Node_100":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� �� ���� ������ � �����. ���� �������, ��� �� �������� � �����.";
                link.l1 = "��� ���� ���� ����!";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "������, " + GetAddress_Form(NPChar) + "? � ���� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "���! ���� ��������, ��� ��� ���� ������������...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 500 �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 500;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_Node_500":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� ��� ����� ����� ��������������� ������. � �� ���� � ���� ������.";
                link.l1 = "��� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckDiceGameBigRate())
		    {
                dialog.text = "� ������, ��� �� ����� ������ �������. � �� ���� ������ � ����� �� ����� ������� ������.";
                link.l1 = "����� �� ����� ������ �������?";
			    link.l1.go = "Dice_Node_100";
				link.l2 = "��������, ��� ����.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "������, " + GetAddress_Form(NPChar) + "? � ���� ��� 15000 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "������, �� ���. ����� ������ �� ������� �� ����� ����.";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 2000 ����� �� �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 2000;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_begin_go":
            SetNPCQuestDate(npchar, "Dice_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchDiceGame();
		break;
	    // ����� <--

	// ���� <--

//  �������� -->
case "Trade_1":
		//������� ���?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("��� ���� �����? ��� � ���� ���� ������ � �����?", "������� ����� ������� �����, ����, � ����� ������ ���-�� ���������	...");
link.l1 = RandPhraseSimple("�� ����������, ����, ����� � ���� ����� �����!", "��, ��� ��������� �������������... �� ��������.");
			link.l1.go = "exit";
			break;
			}
			dialog.text = "������ �� � ���, ����.";
			link.l1 = "����� �������� ������.";
			link.l1.go = "Trade_2";
			link.l2 = "����� ��������, �� � ���������"+ GetSexPhrase("","�") +".";
			link.l2.go = "exit";
		break;
		
		case "Trade_2":
			FillShipStore(NPChar);
	    	pchar.shiptrade.character = NPChar.id;
   			NextDiag.TempNode = "First time";
		    DialogExit();
		    DeleteAttribute(pchar, "PriceList.StoreManIdx"); // �� ����� ��� �� ��������
		    LaunchStore(SHIP_STORE);
		break;

// �������� <--

	}
}