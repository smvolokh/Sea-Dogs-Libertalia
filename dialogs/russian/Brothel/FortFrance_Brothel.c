// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;   
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, "+ GetSexPhrase("������� �������","���� ����") +"?", "���� �� ������, "+ GetSexPhrase("���������","��������") +"? ������� ���� �������..."), "����� �������?", "��-��, ������ ��� �� ��� ���� � �� �� - �������...",
                          ""+ GetSexPhrase("��, ����� �� �������� �����-������ �������� ����? � �� � ���� ��� ������������ � ��������� ���� ������ ������������ ������...","��, ����� �� �������� �����-������ �������� ����? ��������� �� ������, ��-��...") +"", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������...", "��, �� ������..."), "�� ����... ��� ��������...",
                      "�� ��, ������������� � ������ ���... ������.", "�� ������... � ������ ���...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// ==> ��������� ���� ��������� �������.
			//--> ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") && pchar.questTemp.Sharlie.Gigolo == "start")
			{
				link.l1 = "��������, ������, ��� ����� ������� �� ��� ����. ������ �� ������� � ����� ���������, � � ���� ����. �� ������ ��� ������?";
                link.l1.go = "Gigolo";
			}	
			//<-- ����� ��������

			//--> ���. �������
			if (pchar.questTemp.GothicLee == "SeekBible_toFFBrothel" && npchar.id == "FortFrance_Hostess") 
			{
				link.l1 = "������, � ���� � ��� ������ �� ��������! �� ������ ��� ������? � ��� � �������� �� ����� ����� ����� � ���������.";
                                                               link.l1.go = "Gothic_SeekBible_1";
			}	

			//<-- ���. �������

			if (pchar.questTemp.Sharp == "seekSharp" && GetNpcQuestPastDayWOInit(npchar, "quest.SharpTime") > 3 && !LAi_IsDead(&characters[GetCharacterIndex("Sharp")]))
			{
				link.l1 = "��������, " + npchar.name + ", � ��� �����. �� �� ������, ��� ��?";
				link.l1.go = "SharpPearl_1";
				SaveCurrentNpcQuestDateParam(npchar, "quest.SharpTime");
			}
            // <== ��������� ���� ��������� �������.
		break;
		
		//--> ����� ��������
		case "Gigolo":
			dialog.text = "�������, �������. ����� ������� ���� �����? �� ���������� ���� ����-������, ��� ���� �� �����?";
			link.l1 = "��� �� ��� �����. ��� ����� ������� �� ����� ������.";
			link.l1.go = "Gigolo_1";
		break;
		
		case "Gigolo_1":
			dialog.text = "�� ������ � ���� ������ �������?";
			link.l1 = "������ ������, � �� ��������� � ��� �������. � ������ ����, ��� ��� ������� ��������� ����������� � ������ ������.";
			link.l1.go = "Gigolo_2";
		break;
		
		case "Gigolo_2":
			dialog.text = "������... �����, � ������ ������ ������? ������ ������� ���� �� ������������?";
			link.l1 = "��... ��� ������� � ����, �, �����, ���� �� ������ �������� � ����� ���� �����, ������� �� ����� ������ ����� ������.";
			link.l1.go = "Gigolo_2_1";
			link.l2 = "��� ����� �������� ��������� � ������������� �������. ������ ������� � ���� ����� ������.";
			link.l2.go = "Gigolo_2_2";
		break;
		
		case "Gigolo_2_1":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand1) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 5000;
				dialog.text = "��� �� �� ����. ��� ������, �������, ����� ������ ���, ��� ��������, � ���������� ��������� ��������. ��� ����� ��������. �� ���� � ��� ���� ����� ����� ��������� ���� ����� ����, � �� ������� ������.";
				if (sti(pchar.money) >= 5000)
				{
					link.l1 = "��... ���������� �����. �� � �� ������ ������������ �� ����� �������. ���, ����� ������.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "���! � ���� ������ ��� ����� �����. ����� �������� � ����� ��������� �����.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 2500;
				dialog.text = "��, � �����-��, ��� � ���� - � ��� �������� �����, ������� �� ��������� �� ������, ������� � � ��������. �� ���� ���� �������� ��������� - �� ����� �������. �� ���� � ��� ���� ����� ��������� ��� ������ ������� ����.";
				if (sti(pchar.money) >= 2500)
				{
					link.l1 = "��� �������. ���, ����� ������.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "���! � ���� ������ ��� ����� �����. ����� �������� � ����� ��������� �����.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_2_2":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand2) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 4500;
				dialog.text = "��, �� �� ���� ����� ��������, ���������. � ��� ��� �� ��� ������� ������������� - ��� ������ ���������� �� ���������� ������� ����� ��������. �� ���� � ������ ���� �������� �������� ������ � ��������� ������ ���� � �� ������� ������.";
				if (sti(pchar.money) >= 4500)
				{
					link.l1 = "��... ���������� �����. �� � �� ������ ������������ �� ����� �������. ���, ����� ������.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "���! � ���� ������ ��� ����� �����. ����� �������� � ����� ��������� �����.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 3000;
				dialog.text = "��� ���? ��������, ����� �� ������ ������? ��� �������, � ��� ����� ������� - ���� ����� ������������� �������, ������ ��� ���� ��������� ������. �� ���� ��� ���� �������� - � ������ ����. � ���� ��� ������ ����.";
				if (sti(pchar.money) >= 3000)
				{
					link.l1 = "��� �������. ���, ����� ������.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "���! � ���� ������ ��� ����� �����. ����� �������� � ����� ��������� �����.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_3":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharlie.Gigolo.Money));
			dialog.text = "�������, �������. ������� ����������� � ����������� ����� ������ � ����� ����� ����. ����� ��� ������ ��������� �� ����� ���� ����. ���� �� �������� ������ �� �������� - �� �������� ������ ������, � ����� ���� �������� ����� ���������� ������\n� �� ������� �������� � ��� ���-������... ������������, ����� �������� � ���� ����������. �� ����� �� �����������, � ������ ������������.";
			link.l1 = "�� ���������. � ���� ��� ������� ��� �����, � �� ��� ����-�� ���. � ����������� ������ � �� ������. ����� �������!";
			link.l1.go = "Gigolo_4";
		break;
		
		case "Gigolo_4":
			DeleteAttribute(pchar, "GenQuest.CannotWait");
			DialogExit();
			AddQuestRecord("SharlieC", "2");
			pchar.questTemp.Sharlie.Gigolo = "girl";
			Sharlie_CreateGigoloGirl();
		break;

                                                //-->���. �������
        case "Gothic_SeekBible_1":
            dialog.text = "������� �������, ��� �������� � ��� � �������� �������, � �� ���� �����! ������� �� ���, ��� �����������...";
            link.l1 = "������, ��� �������� � ������� ��������...";
            link.l1.go = "Gothic_SeekBible_2";
        break;
        case "Gothic_SeekBible_2":
            dialog.text = "������������� � �������, ������ ��� ���� �����. ������� ��� ���������� ���� �� �����...";
            link.l1 = "������, ������� ���� ��������?";
            link.l1.go = "Gothic_SeekBible_3";
        break;
        case "Gothic_SeekBible_3":
            dialog.text = "�� ������, ��� ��� ��� ��������� �������� �� ��� � ��� ����. ���� ��� �����-��!";
            link.l1 = "�������... ������, �� �� ������� ��� � ���: ���-�� ������� ������� ���� �����, ����� ������...";
            link.l1.go = "Gothic_SeekBible_4";
        break;
        case "Gothic_SeekBible_4":
            dialog.text = "���, ������ � �� �������.";
            link.l1 = "� ����� ������� ���� ���������?";
            link.l1.go = "Gothic_SeekBible_5";
        break;
        case "Gothic_SeekBible_5":
            dialog.text = "����� � ���������. ������ ��� �� ����� ���� ���, ��������� ���.";
            link.l1 = "� ����? ��� � ��� ��� ��� � ��� ����?";
            link.l1.go = "Gothic_SeekBible_6";
        break;
        case "Gothic_SeekBible_6":
            dialog.text = "��� ����! ���, ��� ����! ���� � ���������. ����� ������������� ��� � ��������...";
            link.l1 = "������� ����, ����� ����������...";
            link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_toGirl";
        break;
			//<-- ���. �������

		// ������� ����, ������ ��������� ���������
		case "SharpPearl_1":
			if (drand(1) || bBettaTestMode)
			{
				if (sti(pchar.questTemp.Sharp.brothelChance) < 9)
				{	//�������� ������� � �����
					pchar.questTemp.Sharp.City = GetSharpCity();
					pchar.questTemp.Sharp.City.rumour = true; //���� ���� �����
					dialog.text = "��������� ��� ��������, ������� ���� ���������� � " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + ".";
					link.l1 = "���! ��������� ����, " + npchar.name + ". �� ��� ������� �������!";
					link.l1.go = "exit";
					pchar.questTemp.Sharp = "toSharp_going"; //� ������� ������ �� ��������
					ReOpenQuestHeader("SharpPearl");
					AddQuestRecord("SharpPearl", "1");
					AddQuestUserData("SharpPearl", "sCity", XI_ConvertString("Colony" + npchar.city + "Dat"));
					AddQuestUserData("SharpPearl", "sTarget", XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc"));
					if (GetIslandByCityName(pchar.questTemp.Sharp.City) != pchar.questTemp.Sharp.City)
					{
						AddQuestUserData("SharpPearl", "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(pchar.questTemp.Sharp.City) + "Dat"));
					}
					//��������� ��������� ����� �� �����
					group_DeleteGroup("Sharp_Group");
					sld = characterFromId("Sharp");
					string sGroup = "Sharp_Group";
					Group_FindOrCreateGroup(sGroup);
					Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
					Group_LockTask(sGroup);
					Group_AddCharacter(sGroup, sld.id);
					Group_SetGroupCommander(sGroup, sld.id);
					sld.mapEnc.type = "trade";
					sld.mapEnc.worldMapShip = "quest_ship";
					sld.mapEnc.Name = "���� '����������'";
					string sColony= SelectAnyColony(npchar.city); //�������, ������ ������ ����
					int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sColony), GetArealByCityName(pchar.questTemp.Sharp.City))+3; //���� ������� ���� � �������
					Map_CreateTrader(sColony, pchar.questTemp.Sharp.City, sld.id, daysQty);
					Log_TestInfo("���������� ���������� �� " + sColony + "  � " + pchar.questTemp.Sharp.City);
				}
				else
				{	//����, ���� �����, � �������!
					dialog.text = "����. �� � ���� � ��������� ��������. ���� �������, ���� �� ���� ������ �����.";
					link.l1 = "������, ���������, " + npchar.name + "...";
					link.l1.go = "SharpPearl_2";
				}
			}
			else
			{
				dialog.text = "�� ����, � ���� ��� ����� ��� �� ����.";
				link.l1 = "�������... �� ��� ��, ������� ����, " + npchar.name + ".";
				link.l1.go = "exit";
			}
		break;
		case "SharpPearl_2":
			dialog.text = "����������-�-��! ����� �� ���, �������, ���� ��� ����������!";
			link.l1 = "���, � ���� � ��� � ������, ��� � �������...";
			link.l1.go = "SharpPearl_3";
		break;
		case "SharpPearl_3":
			chrDisableReloadToLocation = true;
			pchar.questTemp.Sharp.count = 0; //������� ����� ��� ����. ����
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //���� �� �������
			pchar.questTemp.Sharp.price.evil = rand(1); //������ ��� ����, ��� ������
			sld = &characters[GetCharacterIndex("Sharp")];
			sld.dialog.currentnode = "BrothelSharp";
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
			LAi_SetActorTypeNoGroup(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

