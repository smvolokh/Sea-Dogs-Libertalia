// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	bool ok;
    int iTest;
    ref rColony;
    string sFrom_sea = "";
    switch (Dialog.CurrentNode)
	{
		case "quests":
			//������
			if (CheckAttribute(pchar, "questTemp.Regata.Go") && !CheckAttribute(npchar, "quest.regatatalk"))
			{
				dialog.text = "��� ��� ������? �-�, �� �������� ������! ���?";
				link.l1 = "��, ������ ���, ������. ��� ����� ���������� � ��� �������� ������.";
				link.l1.go = "Regata_check";
				break;
			}
			//������
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����������, ���� �� �� �� ����� �����, �� �� ����� ���� ��������� ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "��������, �� �������� ���� ���� ������ �� ����������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//����������� ������
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoBridgetown" && !CheckAttribute(npchar, "quest.HWICTalked"))
            {
                link.l1 = "� ����������� � ��������, ������� ���������. �������, ������, ��� �� � ��� ������ ���������� �� ���������? ��, ��� �� ����-�����. ���� �� ������� ��������, �������, ������� �� ������ �� ������ �������. � � ��� �� �������� �� ��������, �� ��� �����, �������, �����-�� ������...";
                link.l1.go = "PortofficeDone";
            }
			// ����� ������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "barbados")
			{
				link.l1 = "� �������� ���������� ����������� ��� ����������� ������ '��������������' ��� ������������� ��� �����. �� ������ ��� �������� � ��� ���� �������. �� ����������, ��� ��� ����� �������� ����� �������?";
                link.l1.go = "guardoftruth";
			}
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && !CheckAttribute(npchar, "quest.garpiya"))
			{
				if (CheckAttribute(npchar, "questTemp.caleuche"))
				{
					link.l1 = "� �� ������ ������ �� �������� ���������.";
					link.l1.go = "caleuche_2";
				}
				else
				{
					link.l1 = "� ������, ��� � ����� ����� ����� ������ ������ �������� ��������... ��� �����. �� �� ����������, ��� ��� ��� ���������?";
					link.l1.go = "caleuche";
				}
			}
		break;

		//����������� ������
		case "PortofficeDone":
			dialog.text = "���������� �� �� ���������, �� �� ����-����� ���, � ���������. ������� ������, ��� ����������� - �����, ��������.";
			link.l1 = "��, ����. �����, ����� �� ��������.";
			link.l1.go = "exit";	
			npchar.quest.HWICTalked = "true";
			pchar.questTemp.HWIC.Eng.BridgeCounter = sti(pchar.questTemp.HWIC.Eng.BridgeCounter)+1;
			AddQuestRecord("Holl_Gambit", "2-9");
			if (sti(pchar.questTemp.HWIC.Eng.BridgeCounter) == 7) 
			{
				AddQuestRecord("Holl_Gambit", "2-6");
				pchar.quest.GotoBridgetownOver.over = "yes";//����� ������
				pchar.questTemp.HWIC.Eng = "SeekVanBerg";
				pchar.quest.VanBergAttack_Check.win_condition.l1 = "MapEnter";
				pchar.quest.VanBergAttack_Check.function = "VanBergAttackCheck";
			}
		break;

		//������
		case "Regata_check":
		iTest = FindColony(npchar.city); 
		if (iTest != -1)
		{
			rColony = GetColonyByIndex(iTest);
			sFrom_sea = rColony.from_sea;
		}
		ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
		{
			if (CheckAttribute(pchar, "questTemp.Regata.Breach") || !CheckAttribute(pchar, "questTemp.Regata.Sentjons") || GetCompanionQuantity(pchar) > 1 || sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_LUGGER || pchar.Ship.Name != "�a���-K��ep���")
			{
				dialog.text = "��... �� �������� ������� ������ � � �������� ��� ������������������. ���! � ���������� ������� �� �� ����������. � ��� ���������� ������ � ����-�����.";
				link.l1 = "��... ����! �����, ������ �� ��������� - �� ��������� ���������. �� ��������!";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Regata");
			}
			else
			{
				pchar.questTemp.Regata.FourthTransitionTime = GetPastTime("hour", sti(pchar.questTemp.Regata.StartYear), sti(pchar.questTemp.Regata.StartMonth), sti(pchar.questTemp.Regata.StartDay), stf(pchar.questTemp.Regata.StartTime), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());//�������� �� � ����� �� 1+2+3+4 �������
				dialog.text = "��� �� ��������, �������, � ��� ����� ��������� ���������� - ����� � �����. ��������� � ����� ��������, ���������� ��� ����. �� ������ ������������\n���, ��������: ������� "+ GetFullName(pchar) +", ������� - "+pchar.Ship.Name+"... ��������� ������� �� ������ ������ � ����� - "+sti(pchar.questTemp.Regata.FourthTransitionTime)+". ���, ��� ��������� ������������, ������ ���������� ����.";
				link.l1 = "�������, � �� ����� � ������ �����?";
				link.l1.go = "Regata_info";
			}
		}
		else
		{
			dialog.text = "�� ���� ������� - � ������� ��� ���? ���-�� � ��� �� ����.";
			link.l1 = "����� ��������, ���. � ���������� ������� ���� ������� � ����.";
			link.l1.go = "exit";
		}
		break;
		
		case "Regata_info":
			int n=1;
			string sTemp, sName, sShip;
			for (int i=1; i <=5; i++)
			{
				if (i==1) sTemp = "a";
				if (i==2) sTemp = "b";
				if (i==3) sTemp = "c";
				if (i==4) sTemp = "d";
				if (i==5) sTemp = "e";
				if (pchar.questTemp.Regata.AdversaryFourthTransition.Time.(sTemp) < sti(pchar.questTemp.Regata.FourthTransitionTime))
				{
					n++;
					sName = pchar.questTemp.Regata.AdversaryName.(sTemp);//��� ���������� ����������
					sShip = pchar.questTemp.Regata.AdversaryShipName.(sTemp);//��� �������
				}
			}
			if (n==1)
			{
			dialog.text = "��, �� ��... ��������, ��� ������ ������� �� �� �����. �� �� ������ �����. ";
			link.l1 = "�������, ������� �� ����������.";
			link.l1.go = "exit";
			}
			else
			{
				if (n==6)
				{
				dialog.text = "��, �� ��... ��������, ��� ������ ������� �� �� �����. �� �� ��������� �����.";
				link.l1 = "�������, ������� �� ����������.";
				link.l1.go = "exit";
				}
				else
				{
					if (n==2)
					{
						dialog.text = "��, �� ��... ��������, ��� ������ ������� �� �� �����. �� �� ������ �����. ����� ���� ������ "+sName+" �� ������� "+sShip+".";
						link.l1 = "�������, ������� �� ����������.";
						link.l1.go = "exit";
					}
					else
					{
						dialog.text = "��, �� ��... ��������, ��� ������ ������� �� �� �����. �� �� "+n+" �����. ��� ��������� �������� ������� - "+sName+" �� ������� "+sShip+".";
						link.l1 = "�������, ������� �� ����������.";
						link.l1.go = "exit";
					}
				}
			}
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Defence", 30);//������
			AddCharacterExpToSkill(pchar, "Repair", 30);//�������
			AddCharacterExpToSkill(pchar, "Fortune", 30);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 30);//����������
			npchar.quest.regatatalk = "true";
			pchar.questTemp.Regata.Bridgetown = "true";//������� ����������
			pchar.quest.Regata_Check1.win_condition.l1 = "location";
			pchar.quest.Regata_Check1.win_condition.l1.location = "Curacao";
			pchar.quest.Regata_Check1.function = "RegataCheck";//�������� 1
			pchar.quest.Regata_Check2.win_condition.l1 = "location";
			pchar.quest.Regata_Check2.win_condition.l1.location = "Caracas";
			pchar.quest.Regata_Check2.function = "RegataCheck";//�������� 2
			pchar.quest.Regata_Check3.win_condition.l1 = "location";
			pchar.quest.Regata_Check3.win_condition.l1.location = "PortoBello";
			pchar.quest.Regata_Check3.function = "RegataCheck";//�������� 3
			pchar.quest.Regata_Check.win_condition.l1 = "location";
			pchar.quest.Regata_Check.win_condition.l1.location = "Jamaica";
			pchar.quest.Regata_Check.function = "RegataCheck";//�������� 4
			pchar.questTemp.Regata.AttackIsland = "Curacao";
			pchar.questTemp.Regata.AttackNation = HOLLAND;
			pchar.quest.Regata_Attack.win_condition.l1 = "location";
			pchar.quest.Regata_Attack.win_condition.l1.location = "Curacao";
			pchar.quest.Regata_Attack.function = "RegataAttack_Brigantine";
			pchar.quest.Regata_Attack1.win_condition.l1 = "location";
			pchar.quest.Regata_Attack1.win_condition.l1.location = "Curacao";
			pchar.quest.Regata_Attack1.function = "RegataAttack_Corvette";//������ ������
			pchar.quest.Regata_Hunter.win_condition.l1 = "location";
			pchar.quest.Regata_Hunter.win_condition.l1.location = "Barbados";
			pchar.quest.Regata_Hunter.function = "RegataAttack_Hunter";//�� � ���������
			pchar.quest.Regata_Finish.win_condition.l1 = "location";
			pchar.quest.Regata_Finish.win_condition.l1.location = "Jamaica";
			pchar.quest.Regata_Finish.function = "RegataFinishSea";
			pchar.quest.Regata_Finish1.win_condition.l1 = "location";
			pchar.quest.Regata_Finish1.win_condition.l1.location = "Portroyal_town";
			pchar.quest.Regata_Finish1.function = "RegataFinishTown";//����� ������
			//��������
			pchar.quest.Regata_Siege.win_condition.l1 = "location";
			pchar.quest.Regata_Siege.win_condition.l1.location = "Bridgetown_town";
			pchar.quest.Regata_Siege.function = "RegataSiegeOfficer";//�� ����� �� ������ �������
		break;
		//������
		
		// ����� ������
		case "guardoftruth":
			dialog.text = "��, ���� ������ �������� � ���, ����������� � ����� ��������� ����� ������� ��� ����. �������� � ������ ����������... ��... ���, ������ ���. ��������, �� ����� ������ �� ����.";
			link.l1 = "����. ����� ����... ���� ������ ������.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			DialogExit();
			AddQuestRecord("Guardoftruth", "13");
			pchar.questTemp.Guardoftruth = "barbados1";
		break;
		
		// �������
		case "caleuche":
			dialog.text = "���, ��� ����� �������� �����. ��� ��� ���������, ��� ������, � ��� ��� ������ �������. ������, ������� �� ����� ��� ���� ��������? ��� ����� ��������?";
			link.l1 = "";
			Link.l1.edit = 2;
			link.l1.go = "caleuche_name";
			link.l2 = "��������� � ���, ��� � �� ����, ��� ���������� ��� �������. ��� ����� ��������, �������� �����������-���������, ���������...";
			link.l2.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "������, � ������� � ��������� - � �������, � ����� ��������� ����������. ��� �������, ��� ���������� ������ ����� ������ ��������, ��� �� ��������� ��� �����.";
			link.l1 = "������, � ��������� �������� � ������� � ���.";
			link.l1.go = "exit";
			npchar.questTemp.caleuche = "true";
		break;
		
		case "caleuche_2":
			dialog.text = "��? �� ��������? ������ ���.";
			link.l1 = "";
			Link.l1.edit = 2;
			link.l1.go = "caleuche_name";
		break;
		
		case "caleuche_name":
			if (GetStrSmallRegister(dialogEditStrings[2]) == "������")
			{
				dialog.text = "'������'? �� �������, � ���� ������ '������', �� �������� ����� ���������� �������. �� � ���������� �� ����� ��� �� ����������. � ������, ��� ��� ������ �� ������ ����������� ����-������� ��������. ��� ��� ��� ����� � ����������.";
				link.l1 = "������� ��������! �� ��� ����� �������.";
				link.l1.go = "caleuche_3";
			}
			else
			{
				dialog.text = "��� ��� �� � ��� �� �������, � ���������. �� �������, ��� ��� ������� ����� � ����������?";
				link.l1 = "������. �����, ���� ��� ��������, �����, ��������...";
				link.l1.go = "exit";
			}
		break;
		
		case "caleuche_3":
			DialogExit();
			AddQuestRecord("Caleuche", "18");
			pchar.questTemp.Caleuche.Garpiya = "gwik"; 
			npchar.quest.garpiya = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}


