// ������ �� ������ - �������-���������� ����������� �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "done")
			{
				dialog.text = "��� ��� ������, "+pchar.name+". ��������, �������� ��� ���� �������. �, ��� ����� ������ - �� ��������� ������, ����������� �� ���, � ��������� �� � �������! �� �������� ���� � ������ �������, � � ���, ��� �� ������ � ���.";
				link.l1 = "������ � ���� �������� �� ��� ���������� ������, �������� �������� ������ ����� ���������� ��-��� ������?";
				link.l1.go = "serve";
				AddCharacterExpToSkill(pchar, "Sneak", 500);
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Hardcore_Tortuga") && CheckAttribute(pchar, "questTemp.Sharlie.LevasserDied"))
			{
				dialog.text = "��� ��� ������, "+pchar.name+". ��������, �������� ��� ���� �������. �, ��� ����� ������ - �� ��������� ������, ����������� �� ���! ����, ���� ������, � ������ ����� ������� ����, ������ ������� �����. ���� �������� ����������� ������\n�� �� ����� - ��� �� �����, ��� ������ �� ������. �� ��������� ���� ����, � � ���, ��� �� ������ � ���.";
				link.l1 = "������ � ���� �������� �� ��� ���������� ������, �������� �������� ������ ����� ���������� ��-��� ������?";
				link.l1.go = "serve";
				DeleteAttribute(pchar, "questTemp.Sharlie.Hardcore_Tortuga");
				DeleteAttribute(pchar, "questTemp.Sharlie.LevasserDied");
				break;
			}

			// Jason ��� 
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && GetCharacterIndex("Noel") == -1 && pchar.questTemp.Patria != "epizode_12_barondie" && pchar.questTemp.Patria != "epizode_12_baronfail" && pchar.questTemp.Patria != "epizode_12_baronkilled" && pchar.questTemp.Patria != "fail" && pchar.questTemp.Patria != "end")
			{
				if (CheckCharacterItem(pchar, "patent_fra"))
				{
					dialog.text = "��� ��� ������, "+pchar.name+". ������ ����� ��������� ��� ���������� � ������� ����������� ���������� �������� �� ������ ������� ���� �� ������ �� ��������� �����������. �� �������� ����������, ��� ����!";
					link.l1 = "������� �� ������� �����, �������. ���, ��� ���� ������ ���� ������.";
					link.l1.go = "patria";
					Patria_SetInspector();
				}
				else
				{
					dialog.text = "��� ��� ������, "+pchar.name+". ������ ����� ��������� ��� ���������� � ������� ����������� ���������� �������� �� ������ ������� ���� �� ������ �� ��������� �����������. �� �������� ����������, ��� ����! � ������� � ��� ��� ��� ���� ����������� ��������� �� ������ � ������-������� ����. ����� ������� ����� �������. �������, � ���� ��� �� ������ ����� �������������... �������� ������, ������� "+pchar.name+"!";
					link.l1 = "�������, �������. ���, ��� ���� ������ ���� ������, � ���� ��� ������� ��!";
					link.l1.go = "patria";
					if (!CheckCharacterItem(pchar, "suit1")) GiveItem2Character(pchar, "suit1");
					GiveItem2Character(pchar, "patent_fra");
					EquipCharacterbyItem(pchar, "patent_fra");
					pchar.GenQuest.BoardCrewType = 8;
					Items[sti(pchar.EquipedPatentId)].TitulCur = 2; 
					Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
					ChangeCharacterNationReputation(pchar, FRANCE, 100);
					Patria_SetInspector();
				}
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria != "fail" && pchar.questTemp.Patria != "end")
			{
				if (!CheckCharacterItem(pchar, "patent_fra"))
				{
					dialog.text = ""+pchar.name+", �� ���� ��������. � ���������� ����� ������������ ��������� �� �������� ������� � ������ � ����������� �����. � ���������� ������ �� ����� ���� � ����. ������ ���� ��������.";
					link.l1 = "��...";
					link.l1.go = "patria_patentfail";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_1_return")
				{
					dialog.text = "����, � ���������, "+pchar.name+". ������������!";
					if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton_Fail"))
					{
						link.l1 = "������� ���������, ����� � ������� ���-���� �������. �� ���� ������ �������: � ��� � ������ ������� '�������'. � ������������ �������� �� ����� �� �����, �� �� ���� �� ��������, �...";
						link.l1.go = "patria_8_1";
					}
					else
					{
						link.l1 = "������� ���������, ����� � ������� ���-���� �������.";
						link.l1.go = "patria_8";
					}
					break;
				}




				if (pchar.questTemp.Patria == "epizode_2_return")
				{
					dialog.text = "�����, �������! ��� ��� ������ � ������ �������!";
					link.l1 = "������������ ������ ���������, �������.";
					link.l1.go = "patria_14";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_3_return")
				{
					dialog.text = TimeGreeting()+", �������. ����� ������� �� ��������?";
					if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton_Fail"))
					{
						link.l1 = "������� ������������� ����������� ��������� �� ����-�-�����. � �������� ����������� ��������� ���� ���� ���������� ������ ������� ����������. � ��� ��� ���� ��������� ����������. ������ � ������� �������� ��� '�������' ��� ��������.";
						link.l1.go = "patria_26_1";
					}
					else
					{
						link.l1 = "������� ������������� ����������� ��������� �� ����-�-�����. � �������� ����������� ��������� ���� ���� ���������� ������ ������� ����������. � ��� ��� ���� ��������� ����������.";
						link.l1.go = "patria_26";
					}
					break;
				}
				if (pchar.questTemp.Patria == "epizode_4_return")
				{
					dialog.text = TimeGreeting()+", "+pchar.name+". ��� ������� ���� � ������� �����������?";
					link.l1 = "��� �������, �������. ����� ��������� �� ����� ����������, � ��� ����� �� ���� ������.";
					link.l1.go = "patria_31";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_5_return")
				{
					dialog.text = ""+pchar.name+", �����... �� ��� ���������?";
					link.l1 = "...";
					link.l1.go = "patria_36";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_6_return")
				{
					dialog.text = "�� �������� ��� ��� ������ ���, "+pchar.name+". ��� ������ ����������, ������������!";
					if (pchar.questTemp.HWIC.Detector == "holl_win" || pchar.questTemp.HWIC.Detector == "self_win") link.l1 = "���������� ��������: '��������� �������, ��� �� ������ �� � ���� �� ����-��������. ������ � ����. � ���������� ��������� �� ���������� - ����� ��������� ���-������'. ������� ��� ��������, ������ �������� ���� �������� �� ����������. �� ���� ���������� ����������.";
					else link.l1 = "������� ������������ ����������� ��������: '��� ��� ��������� �������� �� ����-��������, ������� ������� ����� ������� ��� ���������� ��������.' ����� ���� ���� ���������� ����������. �������� ������� ������������ ������ � �������. ��� ��� �������� ����������� ����������.";
					link.l1.go = "patria_43";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_7_go")
				{
					dialog.text = "�������, �� ���� ���. � ���� ���������� ������ � ���� ����, � �� ��������� ��������� ��� �������. ��������� ������� �� ���� ��������.";
					link.l1 = "����, �����?..";
					link.l1.go = "patria_51";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_7_continue" && pchar.location.from_sea == "Charles_town") // add-7
				{
					Patria_HunterShipChecker();
					if (CheckAttribute(pchar, "questTemp.Patria.Hunter.GiveShip"))
					{
						dialog.text = "���, ��� ����, ����, � ��� ���� ��������� ���-����� � �������. �������!";
						link.l1 = "������� ������� ���, ������� ������������ �������� ����������, �������.";
						link.l1.go = "patria_55";
					}
					else
					{
						dialog.text = "� ��� �� ��� �����-�� �������, "+pchar.name+"?";
						link.l1 = "���� ���, ���������. � ��� �����...";
						link.l1.go = "exit";
					}
					break;
				}
				if (pchar.questTemp.Patria == "epizode_8")
				{
					dialog.text = "�������, �������-�� �� �������! ������������ �������� � �����������!";
					link.l1 = "��������� �������?";
					link.l1.go = "patria_59";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_8_wait" && GetCompanionQuantity(pchar) < 8)
				{
					dialog.text = "�� ������ ������� � ������� ��� ���������� ������?";
					link.l1 = "��.";
					link.l1.go = "patria_64";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_8_return")
				{
					dialog.text = "������� "+pchar.name+", ��� �����! ��� ��� ������! ���� ����� �������� �� ���, ��� �� ��������� ���� ������-����������� ��������, ����������� �� ���� �������!";
					link.l1 = "� ������ �������� ���� ����, �������.";
					link.l1.go = "patria_66";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_9_start")
				{
					dialog.text = TimeGreeting()+", "+pchar.name+". ����, ��������� � ����?";
					link.l1 = "�������, �������. ��� ����� � � �����.";
					link.l1.go = "patria_69";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_9_return")
				{
					dialog.text = "� ��� �������������� � ���� �������� ����-�������� ������������ ����� �������! ��-��, ��� ����, �� �� ��������: � ����� �������� ������ � ����� ����������. ��������� ��� ��� ������ ����� ��������� �� �������, �� �� ���� �� ������������ � ���, ��� ��� ����������. ����������!";
					link.l1 = "����� ���������!";
					link.l1.go = "patria_76";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_10_return")
				{
					if (GetQuestPastDayParam("questTemp.Patria.Curacao.Date") < 30) sTemp = "����� ����� ������"; // � ����������� �� ������� ������� ���������
					else sTemp = "��� ������";
					dialog.text = "��� ������, ��� ����? ��������� ����� ������� �������?";
					link.l1 = "��� ������ �������, �������. ������� ����������� ��������, ���� ���������� �� ������, ������� ���������� "+sTemp+" � ������ �� �������.";
					link.l1.go = "patria_81";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_11_return")
				{
					dialog.text = "����� �����������! ����������, ����������, ��� ����! ��, ��� ������ - �� ������.";
					link.l1 = "�������, �������. ���������� ������� � ����� ��������� �����������, ��� ������������, ����-������� ������������ ��������� �������.";
					link.l1.go = "patria_85";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_continue")
				{
					dialog.text = "����, ���� ���, � ��� ��� ������ �����. �� ������ ���������?";
					link.l1 = "��, �������. ����� ������ ��� ������� �����. �� �������� � �����-�� ���������� ����?";
					link.l1.go = "patria_88";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_baronalive")
				{
					dialog.text = "��� ����, �� ������ ���������! �� ��������� ����! ��� ����� ������ �� ������ ���� �������� ��������� ��� �������� ��������.";
					link.l1 = "�����, ������ ����� �� ������ ����� ��������� � ������.";
					link.l1.go = "patria_103";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_barondie")
				{
					dialog.text = ""+pchar.name+", �� ������� � ������? ��� ��������� ������...";
					link.l1 = "��, �������. � ���, ��� ����� �����. � ���� ��� ����������.";
					link.l1.go = "patria_112";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_baronfail")
				{
					dialog.text = ""+pchar.name+", ��� ���� ������? ��� �����������, ��� ����� �������� � ��� �� ����...";
					link.l1 = "��, �������. �� ��� �� �����, � ����������� ���, ��... �� ����. ���������.";
					link.l1.go = "patria_x112";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_baronkilled")
				{
					dialog.text = ""+pchar.name+", ��� ���� ������? ��� �����������, ��� ����� �������� � ��� �� ����...";
					link.l1 = "��, �������. �� ��� �� �����, � ����������� ���, ��... ��� ����� � ��������� ���.";
					link.l1.go = "patria_y112";
					break;
				}
				if (pchar.questTemp.Patria == "epizode_12_baronwin")
				{
					dialog.text = "��� ����, �� ������ ���������! �� ��������� ����! ��� ����� ������ �� ������ ���� �������� ��������� ��� �������� ��������.";
					link.l1 = "��������, ������ �� ��� ���������� �����, � �����?.";
					link.l1.go = "patria_117";
					break;
				}
				dialog.text = "� ��� �� ��� �����-�� �������, "+pchar.name+"?";
				link.l1 = "���� ���, ���������. � ��� �����...";
				link.l1.go = "exit";
				break;
			}

			dialog.text = "��� ��� ������, �����?";
			link.l1 = "������ ����������, ������ ����� ����������. � ��� �����...";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// � ������ ��� ������ ����
		case "Puancie_Jail":
			dialog.text = "������ ����, "+pchar.name+". ��������� ������������� - ������ �� ������, � �...";
			link.l1 = "������ ����� ���� ��������� � �������� � ������? ��� ��������� ����������! � �� � ��� �� �������, �...";
			link.l1.go = "Puancie_Jail_1";			
		break;
		
		case "Puancie_Jail_1":
			dialog.text = "������, � ������� ��� �� ���������� ����! �� �������������� � �������-������������ ����������� ������� ���������� ����������! � ������ ��� ������� ��� ���� ������, ��� �� �� ����� �����, ��� ����� ����� ����. �� � ������������ �� ��� ������ ���� ����� ����������.";
			link.l1 = "��... ��������, ���� ���������.";
			link.l1.go = "Puancie_Jail_2";			
		break;
		
		case "Puancie_Jail_2":
			dialog.text = "���-�� �����. ��� �������� ������ ������� - �� ��� �� ������ ������� �� ������ � ��������� ��� ����� �� ���������. � ��������� ����� ����� ������� �������������� ���� ������������ � ����������� ����������, ������� � ����� ����� ������ ����������� ���� �������������� �����\n�� ������ �� ���� ����������� - �� ������������� "+GetFullName(pchar)+", � � �����, ����������� - ����� ������ � ��� ��������, ����� ��������� ��� �� �������. � �� ������� � ������ ����, ������ ���������!";
			link.l1 = "��� ��� ������� ���������, ���� ���������. ��� � ��������?";
			link.l1.go = "Puancie_Jail_3";			
		break;
		
		case "Puancie_Jail_3":
			dialog.text = "��, �� ��������. �� ������ ��� ������� ������� ����� ����� ������, �� � ���� ��������� �� �����. ����� �� ����� ������ �� �����?";
			link.l1 = "� �������� ���� �� ���� ������������� ��������� ������ ����� � ������ ��� �����, ����� �� ���� � ����� �������� ������ ���� �����...";
			link.l1.go = "Puancie_Jail_4";			
		break;
		
		case "Puancie_Jail_4":
			dialog.text = "��... ���������, � ����� �� ����� ��������� ������������. ����� �������� ������ �������� ������ �����, ��... �� �����. � ���� ��, �����, ������ ����� �� ���� ������������� ��������� �����, �� ������ ������������ �� ��� ���������������..";
			link.l1 = "�����, � ���� ���� ��������� ��������� ���� �������� � ������� �������� ��� �������...";
			link.l1.go = "Puancie_Jail_5";			
		break;
		
		case "Puancie_Jail_5":
			dialog.text = "��������� ����������, "+GetFullName(pchar)+", ������������ �������-����������� ����������� ������� � ��������� ���� ������ �����, �� ��������? ��������� ��� ����� �������.";
			link.l1 = "������, � ����������� �������... �� ��� � ���� ����� ������?";
			link.l1.go = "Puancie_Jail_6";			
		break;
		
		case "Puancie_Jail_6":
			dialog.text = "������ �� ����� ���������� ��� ������� � ��������� ���� ���� �� ������, ������������� ������������ ������. ���� ������ ������ ������, �� � �������� ��� �������������� ����� ��� �������� ����, � ���������� � ������� �������, ������� �� ���� ������� ������. ������� � ������� ������ ����������� � ���� ������������� � �� ����� ������ ��� �����������. ";
			link.l1 = "��� �� ��������� ��� ��������� ����?";
			link.l1.go = "Puancie_Jail_7";			
		break;
		
		case "Puancie_Jail_7":
			dialog.text = "� ���� �� ������, �������. ������� ������� ������ ��������� ������ � ������� � �����, �� ������� �������� ��������� ������. ����� ���������� �� �������� ����, �� ������ ��������� ���� � ���������. ��� � ������� ����� �� ����� � ����� �� �����. �� ���� ���. �������, �� ��� � ���� ����������, "+GetFullName(pchar)+". �������!";
			link.l1 = "��������, ���� ���������! �... ��� ����? �����, � ������?..";
			link.l1.go = "Puancie_Jail_8";			
		break;
		
		case "Puancie_Jail_8":
			dialog.text = "���� ���� ������������ � ������ ������ ���� �� �����. ����� �������!";
			link.l1 = "��...";
			link.l1.go = "Puancie_Jail_9";			
		break;
		
		case "Puancie_Jail_9":
			DialogExit();
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "Sharlie_GoFromPrison", 5);
			NextDiag.CurrentNode = "First time";
		break;
		
		// ���������� ������
		case "saga":
			bDisableFastReload = false;
			LocatorReloadEnterDisable("Charles_townhall", "reload1_back", false);
			dialog.text = "�-�, ��� � ��� "+GetFullName(pchar)+" ����������� ��������! �����, ����� ��� ��� ������. ��, ��������, ������� �������� �� ���� ������ ������?";
			link.l1 = "� ����� �������� ���� ������ �� ����� ����� ������� � ����� ����. �������, ��� ����� � ������ ������� ��� ��������.";
			if (sti(pchar.money) >= 1000000) link.l1.go = "saga_1";
			else link.l1.go = "saga_exit";			
		break;
		
		case "saga_exit":
			dialog.text = "��... �� ��� �� ������? ������� �������, � ��� ������������ ������� �����, ������� � �� �������.";
			link.l1 = "��������, �������. �, ������, ����� ������ � ����������� �������. ������ ������� � �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "saga_repeat";	
		break;
		
		case "saga_repeat":
			dialog.text = "�� �������� ������, "+pchar.name+"?";
			if (sti(pchar.money) >= 1000000)
			{
				link.l1 = "�������! �������, ��� ����� � ������ ������� ��� ��������.";
				link.l1.go = "saga_1";
			}
			else
			{
				link.l1 = "���� ��� ���...";
				link.l1.go = "exit";
				NextDiag.TempNode = "saga_repeat";
			}		
		break;
		
		case "saga_1":
			AddMoneyToCharacter(pchar, -1000000);
			dialog.text = "������������! � �������� � ��� ��� ������. �� �������� ���� � ��������� �������, "+pchar.name+"!";
			link.l1 = "����� � ����� �������� ������ �� ������������ ������ �� �����?";
			link.l1.go = "saga_2";			
		break;
		
		case "saga_2":
			dialog.text = "�� ����������. ������� ��������� �������� ������������... �� ������ � ���� ��������� ������� �� ����� �������. ����� �� ������� �������� ������ ����� ������� ����� ���� ������� �� ����� ������ ���������� ������\n������ �� �����, ��� ����������� �������, �������� �� ������, ��� ������ ������ �������� ������ ������������ ������� � ������������ ��������� �� �������������� �� ����� ������ � ������ ������...";
			link.l1 = "�� ���� ��� ������� �� ��������� �� �� ������ �������� ��������!";
			link.l1.go = "saga_3";			
		break;
		
		case "saga_3":
			dialog.text = "������ ��, ��� ����, ������ ��� ��� ��������� ����� ���������� � ��� ������������. ��� ���� ��� ��������, ���, ����� �� �������, �� �� ��������, ������� ������ ��� �����? ��� ���, ���� ������ ������������ ����� � ������ ��� ���������, ��������� ��� ������ ����. �����������, ��� � � ������� ���, ������ ������ � ����� �� �����. ���� ��������� � ��� ��� �������, �� � � ����� �� ��������, ��������";
			link.l1 = "��... �� ������. �� �� �� ���������� ��� ������, �������. ��� ��, � ����� ������� ����� ������� � �������.";
			link.l1.go = "saga_4";			
		break;
		
		case "saga_4":
			dialog.text = "�� ��� ������ ��������� ���, "+pchar.name+". ��������, ������� �� ������ ��������. �� ������ ������, ��� ��� ��������� ������� ������������ ������. � ������ ��������� ���������� �������� ��� �����, ��� �� ������� ������������ �� ��� ���������� ������������.";
			link.l1 = "� ��� �����. ��������� �����������!";
			link.l1.go = "saga_5";			
		break;
		
		case "saga_5":
			DialogExit();
			pchar.questTemp.Saga = "mishelle";//���� - �����
			AddQuestRecord("Sharlie", "21");
			NextDiag.CurrentNode = "First time";
		break;
		
		case "serve":
			dialog.text = "�� ������������, "+pchar.name+", � ����� �����. ������ ������� �������, � ��� ��������� � ���� ����� �����. ��� ������� ���� �������� - ��� ����, � ������ ���� �������.";
			link.l1 = "��������� �� ������ �����, �������. ������, � ���� ����� ������������ �� ���������?";
			link.l1.go = "serve_1";	
			Island_SetReloadEnableGlobal("Tortuga", true);
			CloseQuestHeader("Terrapin");
			SetFunctionTimerCondition("Terrapin_SetFontene", 0, 0, 5, false); // ������
		break;
		
		case "serve_1":
			dialog.text = "��������, ���� ���. �������, � ���� �������� ��� ���? � ���� �������� ��� ������������� �� ���� �����... � ����������� �������� �� ���� � ������ ������ �������� �� ���������, � � ����� ����������� ����� ���. �� ������ ���������� ���� ������ ������� ����� �� ������� �, ��� ������������� - ��������� ����������� � ������� ��� � ������������ ������. ����� ���� ����� �������\n������� "+GetFullName(pchar)+"! �������, ������ ��� ��� �����������, ������� �������, � ���� ����� ���������� ��� ������ �������� ������������ ����� � ����� ��� ���� ������������ ������� ������-������� ��� �������, ������ '����������'!\n��� ������ ������� ������� �� ������� ������ ���������� ����� ������������ � ����� ��������� ����������� �������, � ����� �������� ������� ������� �� ������� �� ������ ���������. �� ��������?";
			link.l1 = "����� ���������. �� ��� �� ���������� ������?";
			link.l1.go = "serve_2";		
		break;
		
		case "serve_2":
			dialog.text = "����� �������. ������� ���� ������ � ����� �� ������� ���������� ���������� ���������. ����, � ��� ������ ������.";
			link.l1 = "�� ����� ����������� �� ������������, ���� ���������! ����� �� ����� ������� �������!";
			link.l1.go = "serve_3";
			link.l2 = "����� ���������� ����������, �� � �������� ���� ��������� ���� ������ �����������.";
			link.l2.go = "serve_no";
		break;
		
		case "serve_no":
			ChangeCharacterComplexReputation(pchar, "fame", 7);
			dialog.text = "����� ����. � ��� ��������... �, ��� �� �����, � �������� ������� ��� ��� �� ����� ���������, ��� �����, ��� ��� � � ����� ���������. �� ��������� ������� ��������� ������. � ����� � � ������ ���� ������ ���\n� ���������, ��� ������ ������� �� ������ ����������� ���������, ����� ���. ����� ���, ������� ���, ����� �������� �����. �������, � ��� ��� ����� �������� ���������� ��� � �������\n��� �����, ��� ���� �� ������ ������ ����� ������, ������� �� ��� ��� ��������� �� ���� ������.";
			link.l1 = "������ � ���������? � ���������� ����������� � ����!";
			link.l1.go = "serve_exit";			
		break;
		
		case "serve_3":
			dialog.text = "��� ��� ��������� �����! ����� ��������� �������! ���������� ���, ����� "+GetFullName(pchar)+". ��� ��������� ������ ���������� ������-�������� ����� �������. ��������� ������� ��� ���� ������. ������ ��� � ��������� � ������ �������� ���!";
			link.l1 = "����� ���������!";
			link.l1.go = "serve_4";			
		break;
		
		case "serve_4":
			dialog.text = "� ���� ������������ ��������� ������ '����������'. ������ ���� ������������ ������� - ���. ����������� ��� ���������� �������� �� ����� ��� ���������� � ��� ���������� ������� ������� �� ��������� ����������!";
			link.l1 = "����� ���������!";
			link.l1.go = "serve_5";		
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			GiveItem2Character(pchar, "suit1");
			EquipCharacterbyItem(pchar, "suit1");
			GiveItem2Character(pchar, "patent_fra");
			EquipCharacterbyItem(pchar, "patent_fra");
			pchar.GenQuest.BoardCrewType = 8;
			Items[sti(pchar.EquipedPatentId)].TitulCur = 2; 
        	Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
			Log_Info("�� �������� ������ ������������ ������-�������� ����� �������");
			ChangeCharacterNationReputation(pchar, FRANCE, 100);
			ChangeCharacterComplexReputation(pchar, "fame", 12);
		break;
		
		case "serve_5":
			if (GetCompanionQuantity(pchar) > 7)
			{
				dialog.text = "������ �� ������ ������ ���� ������� ������� ������, ����� ������� ��� ���� �������. ���������� �� ������� ������� - � ����� ���������� ������������ '������������'.";
				link.l1 = "������. ��� � ��������.";
				link.l1.go = "serve_wait";		
			}
			else
			{
				dialog.text = "������ � '������������' � ���� ������ ������������ ��������� ��� ��� ������� � ��������� ������. ���� ������� ������ - ������ �������� ��� � ���� �� ������, ���� ��� - ������� �� �����, �� ��������� ��� �� ������ ����� ������.";
				link.l1 = "������ � ��������!";
				link.l1.go = "serve_6";
			}
		break;
		
		case "serve_6":
			dialog.text = "�� ����� �� ��������� ���������, �������, � ���� ���� ��� ��� � ��������� ��������. � ������ ��� �����, ��� �� ��������� ������� ��������� ������. � ����� � � ������ ���� ������ ���. � ���������, ��� ������ ������� �� ������ ����������� ���������, ����� ���. ��� ��� ������ ���������� ���������\n�������� ���� �� �����! ��� �����, ��� ���� �� ������ ������ ����� ������, ������� �� ��� ��� ��������� �� ���� ������.";
			link.l1 = "������ � ���������? � ���������� ����������� � ����!";
			link.l1.go = "serve_7";
		break;
		
		case "serve_7":
			DialogExit();
			CreateGriffondor();
			sld = characterFromId("GriffOfficer");
			SetCharacterRemovable(sld, true);
			SetCompanionIndex(pchar, -1, sti(sld.index));
			sld.loyality = MAX_LOYALITY;
			NextDiag.CurrentNode = "First time";
			DeleteAttribute(pchar, "questTemp.Terrapin");
			pchar.questTemp.Sharlie = "senpierbattle";
			pchar.questTemp.Sharlie.DefendSP = "true";
			AddQuestRecord("Sharlie", "24");
			pchar.quest.DefendSP_prepare.win_condition.l1 = "location";
			pchar.quest.DefendSP_prepare.win_condition.l1.location = "Martinique";
			pchar.quest.DefendSP_prepare.function = "DefendSP_PrepareMartinique";
			AddCharacterExpToSkill(pchar, "Leadership", 2000);
			AddCharacterExpToSkill(pchar, "Fortune", 500);
		break;
		
		case "serve_wait":
			DialogExit();
			NextDiag.CurrentNode = "serve_shipcheck";
		break;
		
		case "serve_shipcheck":
			dialog.text = "�� ������ ������� ��� ���� ������������ '����������'?";
			if (GetCompanionQuantity(pchar) > 7)
			{
				link.l1 = "���� ��� ���, � �������� ������� ����� �������...";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "��, �����.";
				link.l1.go = "serve_5a";
			}
			NextDiag.TempNode = "serve_wait";
		break;
		
		case "serve_5a":
			dialog.text = "�������! ������ � '������������' � ���� ������ ������������ ��������� ��� ��� ������� � ��������� ������. ���� ������� ������ - ������ �������� ��� � ���� �� ������, ���� ��� - ������� �� �����, �� ��������� ��� �� ������ ����� ������.";
			link.l1 = "������ � ��������!";
			link.l1.go = "serve_6";
		break;
		
		case "serve_exit":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			DeleteAttribute(pchar, "questTemp.Terrapin");
			pchar.questTemp.Sharlie = "senpierbattle";
			pchar.questTemp.Sharlie.DefendSP = "true";
			AddQuestRecord("Sharlie", "23");
			pchar.quest.DefendSP_prepare.win_condition.l1 = "location";
			pchar.quest.DefendSP_prepare.win_condition.l1.location = "Martinique";
			pchar.quest.DefendSP_prepare.function = "DefendSP_PrepareMartinique";
			AddCharacterExpToSkill(pchar, "Leadership", 1000);
			AddCharacterExpToSkill(pchar, "Fortune", 250);
		break;


		// Jason ���
		case "patria":
			dialog.text = "� ��� ������ ������, ���������! � ������, ��� �� ������� ������, � ������-�� �������� ���������! � � ���� ��� ������� ��� ��������� �������� ������� ��������� ���������, � �������, � ������, �� ���������� ��� �� �����������. ��� �����, ��� ��� �������� ������� � ����� ���������� �������.";
			link.l1 = "� ���� ��������, �����.";
			link.l1.go = "patria_1";
		break;
		
		case "patria_1":
			dialog.text = "�� ��������� ������� ����������� ��� ��������, ��������� � ��� �������. ����������� � ����� ����� �����, �������� ���� ����������� ����-������� �������� ��������. ������ �� ��������� � ����� ��������� ����� ������� �� ������� ���������� ����������� ��������� ��������� ��������� � ������ �������, � ����� �������� ����������� �������� �������� ������ � ����� �������. �� ������ ���������� ��������� ��� ��������� ��������� � ���������� � ���� ��������, ��� ��, ����������, � �������. �����, ��������� ����������� -  ������� "+ GetFullName(Pchar)+", ���� �� �������������� ������� �� ������ �������...";
			link.l1 = "";
			link.l1.go = "patria_2";
		break;
		
		case "patria_2":
			DialogExit();
			sld = characterFromId("Noel");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
		break;
		
		case "patria_3":
			dialog.text = "����, "+pchar.name+", ���� �� � ������� �������� ���������� �����������, � ������ ����� ���� ��������� ������. ����� �� ����� ������������ �������� �� ����������� ���������, � �������, ���� ��� � ������� �� ��� ���� �� �������� �� ���������, ������ �������� �� ��������� ������� ������� � �������������� ���������� ������� �����\n������ � ������� �� ������� ������� �������, � ������� ������� � ������ �������� 66-�������� ������� '�������'. ������� ������� � ������� �����, �� �� ������� �� �������, ������� �� ��������� ��� ���� ������������. ������ � '���������' �� ����������� � ������� ���������� ������� ��������, � ���������� �� �������� �������� ����������� � ������ ����� ���� �� ��������� �� ���� �� �����.";
			link.l1 = "�������, �� ��������, ��� ������� ���������� ���������?";
			link.l1.go = "patria_4";
		break;
		
		case "patria_4":
			dialog.text = "������, ��� �� � ����� ����, ��� '�������' � ���� ������� �������� ���� ���-���� � �����. ���������� ������ � ����������� �����, ����� ������, �����, �� �����������. ��������� ��� ��������������, ����������� ����, � ����� �������������� ����������, ��� ������� ��������� �������. � ����� �������� �������� ����� ������ ��������, � ��� ���������� ���������. � �� �� ��� ��������� �� ����� ����������� ������, ����������� ��� ������?";
			link.l1 = "��... �������, �������.";
			link.l1.go = "patria_5";
		break;
		
		case "patria_5":
			dialog.text = "�� ��� ��, ������� ��� ����?";
			link.l1 = "��� �����, ���� ���������.";
			link.l1.go = "patria_6";
		break;
		
		case "patria_6":
			dialog.text = "����� �����������. ������� ������ ��� �������� '��������' � �������������� ����� ����������. ���� �������� ������� � ����������� ��������� �������� ��������� ��� ���� ������������. "+pchar.name+", � �� ���������, ��� �� ������ �� ������ �������, � ��� ������� � ������������ ������, ������� ����, � ������ �������, ���������� ���� � �������. � ���� ��, �� ��� ����� � ����. �����, ������� "+pchar.name+"!";
			link.l1 = "";
			link.l1.go = "patria_7";
		break;
		
		case "patria_7":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			LAi_SetHuberType(npchar);
			AddQuestRecord("Patria", "1");
			pchar.questTemp.Patria = "epizode_1";
			Patria_SetEcliaton();
		break;
		
		case "patria_8_1":
			if (sti(pchar.money) >= 300000) AddMoneyToCharacter(pchar, -300000);
			else pchar.questTemp.Patria.NoMoney = "true";
			dialog.text = "'�������' �������? "+pchar.name+", ��� �� ����������! ��� ������ ������ �������? ��, ��� �� �� ���� �������! � ��� ������ � ����� ���������, � ��... ���, �� ��������������� �� ��� ����� �� ���. � ������ ������, � ��� ����� ����� ��������� �� �����. �� � ����� ���������� ������, ��� �� ���������, �� ����� ���� � ����.";
			link.l1 = "���... ����� ����, �����. ����, ��� ��� � � ����� ���� ����� ������ �� ��� �� �����-������, ���� ���� �������� �������. �� ��������, ��������, ��� ����� ����, ��� ��� ������ ����������.";
			link.l1.go = "patria_8_2";
		break;
		
		case "patria_8_2":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			pchar.questTemp.Patria = "fail";
			AddQuestRecord("Patria", "8");
			CloseQuestHeader("Patria");
			RemoveItems(pchar, "patent_fra", 1);
			pchar.GenQuest.BoardCrewType = 0;
			if (CheckAttribute(pchar, "questTemp.Patria.NoMoney"))
			{
				ChangeCharacterComplexReputation(pchar, "nobility", -20);
				ChangeCharacterNationReputation(pchar, FRANCE, -30);
				DeleteAttribute(pchar, "questTemp.Patria.NoMoney");
			}
			else
			{
				ChangeCharacterComplexReputation(pchar, "nobility", -5);
				ChangeCharacterNationReputation(pchar, FRANCE, -5);
			}
			pchar.quest.Patria_SanJoseReturnOver.over = "yes"; // ����� ������
		break;
		
		case "patria_8":
			if (sti(pchar.money) >= 300000)
			{
				dialog.text = "������������!";
				link.l1 = "���, �������, ����������, ������ �����.";
				link.l1.go = "patria_9";
			}
			else
			{
				dialog.text = "������������, "+pchar.name+", �� ��� �� ������?";
				link.l1 = "���, � ������� �� �������, ������ ��������!";
				link.l1.go = "patria_8_3";
			}
		break;
		
		case "patria_8_3":
			DialogExit();
			npchar.dialog.currentnode = "patria_8_4";
		break;
		
		case "patria_8_4":
			dialog.text = "����, "+pchar.name+", �� �������� ���������� ����� � ���������?";
			if (sti(pchar.money) >= 300000)
			{
				link.l1 = "��, ��� �����. ��� ��.";
				link.l1.go = "patria_9";
			}
			else
			{
				link.l1 = "��� ����!";
				link.l1.go = "patria_8_3";
			}
		break;
		
		case "patria_9":
			AddMoneyToCharacter(pchar, -300000);
			dialog.text = "� ���� �������, "+pchar.name+", �������, ��� � ������. ������� ���� ���������, � ��� �� ����� ������ ����������� ������ - 50 000 ����. ��������, ��� ����.";
			link.l1 = "���������, �������.";
			link.l1.go = "patria_10";
		break;
		
		case "patria_10":
			AddMoneyToCharacter(pchar, 50000);
			dialog.text = "� ��� ��� ��� ������� ����� ���������. ����� ����� �������� ��������� � ����������� � ������ ������ �������� ���� �������� �������. � ����� ��� ������� ������ �� ������� � ���������, �������� ������������� � ��� ����� � ��������� ��� �������. �� ������������, "+pchar.name+"?";
			link.l1 = "�������, �������.";
			link.l1.go = "patria_11";
		break;
		
		case "patria_11":
			dialog.text = "����� ��������� �� �������, ������� ����� ��� �� ����������� �� ����������� ���� � �� ���������� ����������� ������, ��� �� ��� ������.";
			link.l1 = "�������, ���������. ������� ����� ��������� �� ������ ������� �������, ����� ��� - ���� ����� ����� � ��������.";
			link.l1.go = "patria_12";
		break;
		
		case "patria_12":
			dialog.text = "�������. ����� ����� ������������ �� ��� �������. �������� ��� ����� ������ �����.";
			link.l1 = "��� �����, �������!";
			if (pchar.model == "Sharle_6") link.l1.go = "patria_13";
			else link.l1.go = "patria_13_1";
		break;
		
		case "patria_13_1":
			dialog.text = "� ���, "+pchar.name+": �� ����� ��� ������ ����������� �������! ����� ��� ���������. � ������ ����� �������� �� ��� ������ � �����, � ��������� ������ � ������ �� ���� ��� �����������. �� �� ������, � ���������� ������ ���� �� ����, � ������ ������� - �� ������� ���� �������� �������!";
			link.l1 = "����� ��������, �������, ����� ������ �� ����������.";
			link.l1.go = "patria_13";
		break;
		
		case "patria_13":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			AddQuestRecord("Patria", "9");
			pchar.questTemp.Patria = "epizode_2";
			Patria_VisiterBegin();
			pchar.quest.Patria_SanJoseReturnOver.over = "yes"; // ����� ������
			ChangeCharacterNationReputation(pchar, FRANCE, 10);
			ChangeCharacterComplexReputation(pchar, "nobility", 3); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
		break;
		
		case "patria_14":
			sld = characterFromId("Noel");
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto4");
			dialog.text = "� �� ������ �� ���������� � ���, ��� ���� ����������� ���������� ������������. ���� �����-������ ������� � ������� ��� �� ����-�-������?";
			link.l1 = "...";
			link.l1.go = "patria_15";
		break;
		
		case "patria_15":
			DialogExit(); // ������������ �� ����������
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Noel"));
			pchar = GetMainCharacter();			
			LAi_SetPlayerType(pchar);
			sld = characterFromId("Puancie");
			sld.dialog.currentnode = "patria_16";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
			bDisableCharacterMenu = true;//������� ����������
		break;
		
		case "patria_16":
			dialog.text = "";
			link.l1 = "��, �������, ���� ������� � �� ����� ��������. ��-������, ���������� ����-�-������ ������, ��� ������� ������� ����� �� ������� � ��� ����� �������� ������� ������� ��... ��-�-�, ��� ���... � ��������, ���. � ��� �� ������ �� ������� �������. � ������, ��� �� �� ����� �������� ��� ��� ��������, ��� �����, ��� ��������� ����-�-������ - ������ �� ���, ��� � ����� �� ����� �������.";
			link.l1.go = "patria_17";
		break;
		
		case "patria_17":
			dialog.text = "������� ��������� ��������� ����-�-�����? ��... ������. �� ������� ����������� � ���� ������ ���������. '�������' ��� ��� �������, �������� � ����� � ������ � ����...";
			link.l1 = "� ���, ���������: � ������ ������ ����-�������, ��� ����� �� ����� ������, ��������� ����������� ��������, � �������� ������ ���, ��� ��� ���������� ���������. ��� ���, �������?";
			link.l1.go = "patria_18";
		break;
		
		case "patria_18":
			dialog.text = "�-�-�... ��� ���, � � �� �� ����� �� ������ ���. ����-������� �������� ����������� ��������. ������, �����, ���� ������ � ������������� ����� ������ ��������� ���������� - ������� ���������, ����� ��� �������, �����������, � ����������� - �������� ������� ����, � ��, ��� ���� � �������� - ������ � �����������. ��� ���� ��������, ��� ��� ��� ����� �������� �������� ����\n������� ����-������� ��� ������� � ������������ ������ ����������� ����-������� �������� ��������, ������� ���������� ��� ��� �������� ������������ ����� �� ���� ���������� �������� �������� �� ������� � ����������. ��������� ��������� ��������� ��� ��������� ����������, ��������� ���� � ����, � ��� ���, ��� ������ �� ��������� ������������ �������, ����-������� ������������� ������� ����������� ��������.";
			link.l1 = "������ ��-��� ������ ����������� ���?";
			link.l1.go = "patria_19";
		break;
		
		case "patria_19":
			dialog.text = "�������. �� ��� � ��� ������ - �������� �������� ������ �� ����� � ������, ��� ������������ ��� ������� �������.";
			link.l1 = "��� �������, ��� ���� ������ ����� ���������� ����������� ����-������� �������� ��������, ����� ��� �������� �� �������. �������� ��� �� ������ ��� �������� - �������� ������� �� ���� � ������. ��� ����� �������� ��� �������, �, ������ ��������, ��� ������ ������� ���������� ����� ����������.";
			link.l1.go = "patria_20";
		break;
		
		case "patria_20":
			dialog.text = "������� ���� ��������� ������ � ����������, ��������� ����������� ����-������� �������� ��������, ������� ������ �����������. �� ������ ���� ���� ������� �� ��������� ������� - ���� ���-���� ��� ��� ����� ������������, � ������ �����.";
			link.l1 = "����� ����� ��������� ������� � ����������.";
			link.l1.go = "patria_21";
		break;
		
		case "patria_21":
			dialog.text = "�������� � ���, ��� ������� ����������� �������� ������� � �����������, �� ��������� � ��������� �� ����� �������� �� ����� �������...";
			link.l1 = "�� �����-�� �� �� ��� ������, � �������? ��� ��� �����, �� ���������� ������ ������� ��� �������� ���������� ��������� �������. ������ �� �� ��������� ������ ����������� �����������?";
			link.l1.go = "patria_22";
		break;
		
		case "patria_22":
			dialog.text = "������ ������ �����, ��� ���� �������� � ���� - ������� ��������, �������� ���������� ������������ ��������. �����, � ���� ��� ��������, �� ������������, ������ ����������� ������� �������.";
			link.l1 = "������, ����� � ���� ����. ���� ���� ��� �������� ����� �������, ��������� � ���������. ����, ��� �������� �� ����� ������������ ���� �� ���� ��� - ��� ����� ������������ � ������� ���������...";
			link.l1.go = "patria_23";
		break;
		
		case "patria_23":
			DialogExit();
			LAi_SetActorType(pchar); // 17-add
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			pchar = GetMainCharacter();			
			LAi_SetPlayerType(pchar);
			bDisableCharacterMenu = false;//������� ����������
			sld = characterFromId("Puancie");
			sld.dialog.currentnode = "patria_24";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
			ChangeCharacterNationReputation(pchar, FRANCE, 10);
		break;
		
		case "patria_24":
			dialog.text = "��-��, �� ����������� ������ �������� ��������� ������ �������� ��������! "+pchar.name+", ���������� � ������� '�������', ������������ � ��������� � ��������, ������������� �� ������� �������� ������ ����-�-������ �� ������� ��������. ���� ������� - ��������� ��. �������, �� ��� ��� �����, �� ����� ���� ��� ������. ���� �� ������ �� ������� - �� ������� ����� ����������, �� ����� ��� �����. ��� ��� � ������� �� �������, ��� ����� �����. �����, ��� ����!";
			link.l1 = "�������, �������. ���������� ������ � ����.";
			if (ChangeCharacterHunterScore(pchar, "holhunter", 0) > 10) link.l1.go = "patria_25_1";
			else link.l1.go = "patria_25_2";
		break;
		
		case "patria_25_1":
			dialog.text = "��, ���, "+pchar.name+": � ������, � ��� �������� � ������������ ��������? ����������, ������� ���� ������ ��� ����� ������, � ��������� ������� ��� ��������� ��������� ����������� �������. ��� �� ���������, ��� ����� ������ ��� ����� ����������.";
			link.l1 = "������, �����, � �����. ��� ����� �������.";
			link.l1.go = "patria_25";
		break;
		
		case "patria_25_2":
			dialog.text = "��, ���, "+pchar.name+": � ������� ��� ������������ �� ������ ������ - ��������� ���������� � �����������. � ������ ������� ��� ��������� ��������� ����������� �������. ��� �� ���������, ��� ����� ������ ��� ����� ����������.";
			link.l1 = "������, �����, � �����. ������� ���� � �����������.";
			link.l1.go = "patria_25";
		break;
		
		case "patria_25":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			LAi_SetHuberType(npchar);
			AddQuestRecord("Patria", "15");
			pchar.questTemp.Patria = "epizode_3";
			Patria_PortPaxBegin();
			ChangeCharacterComplexReputation(pchar, "nobility", 1); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;
		
		case "patria_26_1":
			dialog.text = "'�������' �������? "+pchar.name+", ��� �� ����������! ��� ������ ������ �������? ��, ��� �� �� ���� �������! � ��� ������ � ����� ���������, � ��... ���, �� ��������������� �� ��� ����� �� ���. � ������ ������, � ��� ����� ����� ��������� �� �����. �� � ����� ���������� ������, ��� �� ���������, �� ����� ���� � ����.";
			link.l1 = "���... ����� ����, �����. ����, ��� ��� � � ����� ���� ����� ������ �� ��� �� �����-������, ���� ���� �������� �������. �� ��������, ��������, ��� ����� ����, ��� ��� ������ ����������.";
			link.l1.go = "patria_26_2";
		break;
		
		case "patria_26_2":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			pchar.questTemp.Patria = "fail";
			AddQuestRecord("Patria", "19");
			CloseQuestHeader("Patria");
			RemoveItems(pchar, "patent_fra", 1);
			pchar.GenQuest.BoardCrewType = 0;
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
			ChangeCharacterNationReputation(pchar, FRANCE, -5);
			pchar.quest.Patria_PortPaxOver.over = "yes"; // ����� ������
		break;
		
		case "patria_26":
			dialog.text = "�������! ���� � ��� �� ����� ������ ����� ��������, ��� ��, ��� ������ ������� ������ ����������. � ������ ��������� ������� � ����-�-����� � ������� � ������ �� �������, � ������ ������� � ������ ������ ���������� ������ ������ �� �������, ��� ������� ���� �� ������������� ��� �� ������, ��� ��� ���� ��� ��������, "+pchar.name+", ��� ��� ����������� ������� �� �� ����������\n� ������ ������� �������� � ������ ���������� �������. ��-��, ��� ����, � ���� ��� ��� ����� ���������, ����� �� ���� ��� � �� ������, �� ������ ����������, � ��� �������� ��, ����� ��� ��������� ������ ��.";
			link.l1 = "� ���� ��������, �������.";
			link.l1.go = "patria_27";
		break;
		
		case "patria_27":
			dialog.text = "�� �� ������� ��� �������� � ����� ����� � ����-��������? ���� ���������� ������ ����������� ��������� ���� �������, � �� ����������� �� �������, � ����������, � ��������� �������� ������ �����������. �� ������ ���, � ����� �� ����� ��� ��� ������. ����� ��� ���� ����������� ����� � �������� ��� �������� �� ������� � �������� ������� ����������� ������ �� ����.";
			link.l1 = "��� ��� ������?";
			link.l1.go = "patria_28";
		break;
		
		case "patria_28":
			dialog.text = "��, �������. � ������� �� ������� ����������� ������������� �� ���. ����� ����� ��� ��� ������ ����� ��������� �� ����� ������� �� ��������� � ���������, � ������ ������� �������� ����-�������, ���� �� ��� ������ ������.";
			link.l1 = "������. � ���� ����?";
			link.l1.go = "patria_29";
		break;
		
		case "patria_29":
			dialog.text = "��������, "+pchar.name+". � ������������ �� �����������, ����� �� ����� ����� �����. � ����������� �� ����� � ������ ����������� ������� ��� ������, � ��������� �������! ��� ������ ��������� ����������, �� ��������� ����?";
			link.l1 = "�������, �������. �� ��������!";
			link.l1.go = "patria_30";
		break;
		
		case "patria_30":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			AddQuestRecord("Patria", "20");
			pchar.questTemp.Patria = "epizode_4";
			Patria_CureerBegin();
			pchar.quest.Patria_PortPaxOver.over = "yes"; // ����� ������
			GiveItem2Character(pchar, "Reserve_item_01");
			ChangeItemDescribe("Reserve_item_01", "itmdescr_Reserve_item_01_1");
			ChangeCharacterNationReputation(pchar, FRANCE, 10);
			ChangeCharacterComplexReputation(pchar, "nobility", 5); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 5);
			ChangeCharacterComplexReputation(pchar, "fame", 5);
		break;
		
		case "patria_31":
			RemoveItems(pchar, "Reserve_item_01", 1);
			dialog.text = "���������, �������, ������� ��� ����... (������)... �� ��� ��, �����������! ����� ���������� ��������, ��� ����� ����� ����� �������� ����-������� ��� ��������� � ��� ���������� ����������� ����� �� ���� ������� � ������ ����������. �����, ��� ����� ������ ����� ������ ���������� ������� - �������� ������ � ������ � ����������\n� ������ ����� ��������, �������! � ���� ��� ��� ��� ������� �������. ������: � ������ ������ ������ �� �������� � ������ �� ���� '��������'. ������� ��� ������������, ���������!";
			link.l1 = "����� ���������!";
			link.l1.go = "patria_32";
		break;
		
		case "patria_32":
			dialog.text = "� ������: ���������� ����-�-������ ������� �������� ����� � ������, ������ ������, ���������������� ���: 500 ������� ������ ���� � 500 ������ �����. ��� ��� ����� ����� ��������� �� ���������, ������� �� �������� �� ������ ��������. ����� ����, ��� ��� ����� ������������ ����� ������ ���� - 50 ������ �������. ��� ��� �����, ���������, �����, �� �����. ��� ����� ����� �� ������ � �������� �����������, � �� � ����� ������� ��� ��� ����� ������ ����� � ����� � ������� ���.";
			link.l1 = "���������, �������! ���������� �������!";
			link.l1.go = "patria_33";
		break;
		
		case "patria_33":
			dialog.text = "� ������ �� ������ ���������� �������: �� ��� �� ���� � ����������� �������� ����� �����. �� �������� ��� �� ����-������� � ���������� ��� ������. �� �, ��� �������, ������������� � ����, ��� ����� ����������� � �����������, � ����� �������� ���. �� ��������� �����, �������, ��� ������ ����� �������� ���� - ��� �������� ������� ��� � �������.";
			link.l1 = "��� ����. ��������� ����?";
			link.l1.go = "patria_34";
		break;
		
		case "patria_34":
			dialog.text = "�����. ���� ���� ������ �� ���� ������ ��� �� ������.";
			link.l1 = "...";
			link.l1.go = "patria_35";
		break;
		
		case "patria_35":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			AddQuestRecord("Patria", "25");
			pchar.GenQuest.BoardCrewType = 8;
			pchar.questTemp.Patria = "epizode_5";
			pchar.quest.Patria_CureerBackOver.over = "yes"; // ����� ������
			Items[sti(pchar.EquipedPatentId)].TitulCur = 4; 
        	Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
			pchar.quest.Patria_SanMartin_wait.win_condition.l1 = "Timer";
			pchar.quest.Patria_SanMartin_wait.win_condition.l1.date.hour  = 8+rand(2);
			pchar.quest.Patria_SanMartin_wait.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1+rand(1));
			pchar.quest.Patria_SanMartin_wait.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1+rand(1));
			pchar.quest.Patria_SanMartin_wait.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1+rand(1));
			pchar.quest.Patria_SanMartin_wait.win_condition.l2 = "Location_Type";
			pchar.quest.Patria_SanMartin_wait.win_condition.l2.location_type = "town";
			pchar.quest.Patria_SanMartin_wait.function = "Patria_SanMartinBaron";
			pchar.questTemp.Patria.Goods = "true"; // ������-�����
			bQuestDisableMapEnter = true;//������� �����
			pchar.GenQuest.MapClosedNoBattle = true;
			ChangeCharacterComplexReputation(pchar, "nobility", 1); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;
		
		case "patria_36":
			DialogExit(); // ������������ �� ����������
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Noel"));
			pchar = GetMainCharacter();			
			LAi_SetPlayerType(pchar);
			sld = characterFromId("Puancie");
			sld.dialog.currentnode = "patria_37";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
			bDisableCharacterMenu = true;//������� ����������
		break;
		
		case "patria_37":
			dialog.text = "";
			link.l1 = "��, �������, ��� ���������! ���� ����������� ������ � ����-�������� ��������� ��� ����� �� ����� ����� � ��������� �������� �� ���� ��������. ������ ��������� ���������� �������� � ��� ������� ��� ������� ����! ������, ������ ����� ���������� �� ����� ������ ������ ������������� ������ ������� � �����������, �������?";
			link.l1.go = "patria_38";
		break;
		
		case "patria_38":
			dialog.text = "���?!! ��� ������ ����������� �� ��� ������ ��������, ��� �� �����������...";
			link.l1 = "� ��������� ����� �����������, ��������, ������� ������ �������� �� �����������, �������������� ��� ������� ����� �� ���������! � ������� � ������! ��� �����������, �������? ���! ��� ��� ���� ���������� ���������! ������ � ��������!";
			link.l1.go = "patria_39";
		break;
		
		case "patria_39":
			dialog.text = "�����, � ����� ���... � �� ���� ���������. �� ���������� �������� ������ �������� �������� ����� �� ������� � �����������. � �������� ������� ���� ������� ���������� ���... � ������ � ������� ���� ����������� ��� ��� ����� � ������� ����.";
			link.l1 = "...";
			link.l1.go = "patria_40";
		break;
		
		case "patria_40":
			DialogExit();
			LAi_SetActorType(pchar); // 14-add
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			pchar = GetMainCharacter();			
			LAi_SetPlayerType(pchar);
			bDisableCharacterMenu = false;//������� ����������
			sld = characterFromId("Puancie");
			sld.dialog.currentnode = "patria_41";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.2);
		break;
		
		case "patria_41":
			dialog.text = ""+pchar.name+", ��� ����, ��� ����� ��������� � ����������. ��������, ���������� ��� ���. ���� �� ��� - ��������, ��� ��, � �������. ��� ������� ���������� �� ��������� � ���������� ����������. � ��������� �� ��� ���� � ��� ��������� � ������� �������� ��� ���������� ���. �����, �� ����� �� ������, ������������� � �������� ��� � ����������� �������.";
			link.l1 = "������ ����, �������. ������� ������� � ����������� � ����.";
			link.l1.go = "patria_42";
		break;
		
		case "patria_42":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			LAi_SetHuberType(npchar);
			AddQuestRecord("Patria", "29");
			pchar.questTemp.Patria = "epizode_6";
			Patria_DiplomatBegin();
			ChangeCharacterComplexReputation(pchar, "nobility", 3); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
		break;
		
		case "patria_43":
			dialog.text = "�� ���� ��������...";
			link.l1 = "����� ����, �� �������� ���� �� ���� ��������� ������ ����������� ������� �������. ��������� ���, ����������, �������, ��� ��� ����������?";
			link.l1.go = "patria_44";
		break;
		
		case "patria_44":
			dialog.text = "���� ���, ��� ��������, ��������� �� �������������, ������� �������� �� ��� ���-���� � ������ �������� � �� �����. ������������, � ��� � ��� ������� - ��, ��� �� ��������, �� ������ �������� ���� ����� ��������. �� ��������?";
			link.l1 = "�������, �������.";
			link.l1.go = "patria_45";
		break;
		
		case "patria_45":
			dialog.text = "������. � ������, ��� ���� ��������� ������� �� ����������� �����. ��� ���� ���������, �������, �� ������� �������� ��� ����-��������! ��� � �����... �� � ������ ��� �������� ���������� � ����-��������\n��� ������� �� ������ �������� �� ����-�������� ���� ���������� ������ ����. ������� ���� ����� �� �������������, �� ����� �� ��� ������ ������� ����� � �������� �� ���� � ��������� - ������ ���� �����. ��� �� ���� ���������, ��������� � �������� �������� �� �� �����, �������...";
			link.l1 = "... ���� ������� '���������' � ���� ����������� ����-������� �������� ��������...";
			link.l1.go = "patria_46";
		break;
		
		case "patria_46":
			dialog.text = "�� ������, � ������� - ����� �����������, "+pchar.name+"! ������ ���. ������ ��, ����� ��� ��������� �� ������, ����������, ��������, ����� ����� ������������ ������� ������ ���������, � ������� �� ��, ��� �� �� ������� ����������� ���� �������� ���� � ���������. �� ��� �� �����������. ����� �� ����� ������������ ��������� ���� � ������ ������������ �������-�����������! � �� ��� ��� �������.";
			link.l1 = "��� � �������, ����� ����� �� ������ ���� � �����...";
			link.l1.go = "patria_47";
		break;
		
		case "patria_47":
			dialog.text = "��� ����, �� ���������� �����, ������ �� ����� ����� �����������. ���������� ����, ��� ��� ���������: ��������� �� ����� ������������� ����������� ������, ����� ������� ��������������� ������, �� ���� - ���, � ����� �������: ��-����� �������� ������� ����-�������! ����� ����������, ����� ������ ������� �������� ������ ���������.";
			link.l1 = "�����?!";
			link.l1.go = "patria_48";
		break;
		
		case "patria_48":
			dialog.text = "������! ��� ����, ��� ����-�������� � ��� ��� �� �� ������, �� ���������?.. ����������� ���� � ������������ ������� �� ������ � �����, � ��� ������� � ������� ��������� ������ ������������������� �����... �� ������ ��������� ����������� ���������� �� �����! ���������� �������� � ���������. �� ��������?";
			link.l1 = "��������, �������. ��������� ������ �������� �� ���� ���������� � ��������.";
			link.l1.go = "patria_49";
		break;
		
		case "patria_49":
			dialog.text = "�������. � ������ ������ �������� ������� � �������� �������� �� ����������� �������, ����������! � ��, ��� ����, ��������� ����� ������ � ������� �� ��� ������ ����� ������ ����. � ���������� ��� ��� ������ �������.";
			link.l1 = "������, ���������. ��������� �����������.";
			link.l1.go = "patria_50";
		break;
		
		case "patria_50":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			LAi_SetHuberType(npchar);
			AddQuestRecord("Patria", "33");
			pchar.questTemp.Patria = "epizode_7";
			Patria_HunterBegin();
			pchar.quest.Patria_DiplomatTimeOver.over = "yes"; // ����� ������
			ChangeCharacterComplexReputation(pchar, "nobility", 1); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;
		
		case "patria_51":
			dialog.text = "� �� ������ ��� �� ������, � ������������ � ����. � ���� ���������� ���������, �� ����� ������ ����. ������� ������ ��� ���� �������� ���, ��� ������� ��������� ������ ����-�������, �� ������ ������� ������, ��� �����������. �� ��� � ����� ������������� ���� �������, "+pchar.name+".";
			link.l1 = "������ �����������.";
			link.l1.go = "patria_52";
		break;
		
		case "patria_52":
			dialog.text = "����-������� �������� ������������ ����� ��� ����������� ��������, ��������� � ������. ������� �������� ��������� ������ ����� � ������ �����������. �� ���� ������� ��� ���� ��� ��� ���� ������ �����������. �� ���� �������, �������!.. �� ����������� � ������� ����-�������� � ������ ��������� � ����������� �������� ���� ��������\n��� ��������� ������� ������ �������� ���������� ���-����� - �������, ������ ����������� ������� � ������� ������. ��� � ���� ���� ����. ��������� ���� ����� �������� �� ���� ������� � ��������� ������� � ������ �����������. ����� ����� �� ��������� ���������� �� ������������, � �����, �������� ������, ��, ��������, ������� ���� �������.";
			link.l1 = "������ ����. ��������� ����?";
			link.l1.go = "patria_53";
		break;
		
		case "patria_53":
			dialog.text = "��������, � ����� ����� ����������� ���, ��� ����.";
			link.l1 = "...";
			link.l1.go = "patria_54";
		break;
		
		case "patria_54":
			DialogExit();
			npchar.dialog.currentnode = "First time";
			AddQuestRecord("Patria", "34");
			pchar.questTemp.Patria = "epizode_7_continue";
			Patria_HunterContinue();
		break;
		
		case "patria_55":
			pchar.questTemp.Patria.Hunter = sti(pchar.questTemp.Patria.Hunter)+1;
			if (sti(pchar.questTemp.Patria.Hunter) > 4) // ��� ������
			{
				dialog.text = "�� ��������� ������� ���������, �������. ��������� �� �������� ������! � ��� ���������� ����� ������� �� ������� ������� - ������ ����� ����.";
				link.l1 = "��� ��� �������, �����!";
				link.l1.go = "patria_57";
			}
			else
			{
				dialog.text = "����, ��� �������� �������� � ��� ���� ��� "+FindRussianQtyString(5-sti(pchar.questTemp.Patria.Hunter))+" ����������� ���-������.";
				link.l1 = "��� �����, �������!";
				link.l1.go = "patria_56";
			}
		break;
		
		case "patria_56":
			DialogExit();
			AddQuestRecord("Patria", "35");
			AddQuestUserData("Patria", "sQty", 5-sti(pchar.questTemp.Patria.Hunter));
			DeleteAttribute(pchar, "questTemp.Patria.Hunter.GiveShip");
		break;
		
		case "patria_57":
			AddMoneyToCharacter(pchar, 200000);
			dialog.text = "� ������ ��������� �������, "+pchar.name+". �� ��������� ���. � � ���� ��������� ������������ �� ������������ - ��������, �� ��� �������, ��� ���������� � ���� ��� ������� ���������, ������ �������. �� ��������� �����, ��� ����� ��� �� ��� ������ �����.";
			link.l1 = "������, �����. ���� ����� ����� ���������� ������������.";
			link.l1.go = "patria_58";
		break;
		
		case "patria_58":
			DialogExit();
			AddQuestRecord("Patria", "36");
			pchar.questTemp.Patria = "epizode_7_end";
			pchar.quest.Patria_siege_begin.win_condition.l1 = "Timer";
			pchar.quest.Patria_siege_begin.win_condition.l1.date.hour  = 9.00;
			pchar.quest.Patria_siege_begin.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2);
			pchar.quest.Patria_siege_begin.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			pchar.quest.Patria_siege_begin.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2);
			pchar.quest.Patria_siege_begin.win_condition.l2 = "location";
			pchar.quest.Patria_siege_begin.win_condition.l2.location = "Charles_town";
			pchar.quest.Patria_siege_begin.function = "Patria_SiegeBegin";
			bQuestDisableMapEnter = true;//������� �����
			pchar.GenQuest.MapClosedNoBattle = true;
			ChangeCharacterNationReputation(pchar, FRANCE, 15);
			ChangeCharacterComplexReputation(pchar, "nobility", 5); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 5);
			ChangeCharacterComplexReputation(pchar, "fame", 5);
		break;
		
		case "patria_59":
			dialog.text = "��. ������, ���������� ����� ������ ��� �������� �������� � ������� � ��������. ���������� ������-����������� ������� ����� � ������ �����������. �������� ����� ����������� ��� ������ ��� �� �� ������������.";
			link.l1 = "�����?";
			link.l1.go = "patria_60";
		break;
		
		case "patria_60":
			dialog.text = "��������. �� ������ ����� ����� �� �����, � ��� ������� ��� �� ����. ����� ����������� ������, �������, ���� ���� �� ����� ������������� ���� ������.";
			link.l1 = "��� ���� �������?";
			link.l1.go = "patria_61";
		break;
		
		case "patria_61":
			dialog.text = "� ����-������, ��� �� �������, ������ ��������� ���������� ������� ������� ���������� ����� - �� ������ � ������� � ���� ��������� �����. �� ������ ������ ���� ��������� �������� � ��������� �� �������. ��� ����������� � �����������, ���������� ��� ��� ������ � ��������� ������.";
			link.l1 = "�� �������, ��������� ���������� ��� ������?";
			link.l1.go = "patria_62";
		break;
		
		case "patria_62":
			dialog.text = "�������, ��� ��. ������ ������ ������� ��� � ���, ��� ������� �� ������ ����� ������ ������������... ����� ����, "+pchar.name+", ��� ����� ��������� ����� �������� '��������', ������� ������ ��������� � ������� ���������, ����� �� �������� � ����-����������. ������� ���� '��������' ����������� ������� � ����������� ���. ��������� �� �� ������ ����������� �� ��� �����, � ��� � ������� ������ ��� ������� ���������� ������ - �� ������ ������� ��� � ������� �� ������ ������, � �� ���������� � ���������, ���� '�������' �� ���� �� ��...";
			link.l1 = "������ ����. ������ ����� ����� ������, �������� ���������� ������ � ��������� � ����-����� � ���������� ����� � ����� �������.";
			link.l1.go = "patria_63";
		break;
		
		case "patria_63":
			dialog.text = "��� �����. �� ������ ������� � ������� ��� ���� �������?";
			if (GetCompanionQuantity(pchar) > 7)
			{
				link.l1 = "������ �� ������� ���� ����� � ������� � ���.";
				link.l1.go = "patria_63_1";
			}
			else
			{
				link.l1 = "��.";
				link.l1.go = "patria_64";
			}
		break;
		
		case "patria_63_1":
			DialogExit();
			pchar.questTemp.Patria = "epizode_8_wait";
		break;
		
		case "patria_64":
			dialog.text = "�������. ������� ������, ������ ��� ����� � ������� ����� ������������.";
			link.l1 = "�� ����� ������ �������, �������!";
			link.l1.go = "patria_65";
		break;
		
		case "patria_65":
			DialogExit();
			AddQuestRecord("Patria", "38");
			pchar.questTemp.Patria = "epizode_8_continue";
			GiveItem2Character(pchar, "Reserve_item_01");
			ChangeItemDescribe("Reserve_item_01", "itmdescr_Reserve_item_01_3");
			Patria_SiegeCreateSquadron();
		break;
		
		case "patria_66":
			dialog.text = "��-��, ��� ����, ���� ���������� ��� ����� ��������. �� ��������� ������! � ������� ��� �� ������, ������ ���! �������, ����� ������� ����� ��� ��������� �����? � ��� ���� ����� ������. ������� �� ��� � ������� �� ����� ����� ���� ���� - ����� ��� ��� ���������� ������� ������ �����.";
			link.l1 = "��� �����, �����. ��������� ����?";
			link.l1.go = "patria_67";
		break;
		
		case "patria_67":
			dialog.text = "����� � ���������� ���������. ������ ��� ������ ��� ��������� ��������� ���� - ��� �� ���� ������, ��� � ����������� ��� ����������. � �� � ��������� ����������� ���� ��� ������� ������ �������.";
			link.l1 = "����� �� ������� ����� ������, �������.";
			link.l1.go = "patria_68";
		break;
		
		case "patria_68":
			DialogExit();
			AddQuestRecord("Patria", "45");
			pchar.questTemp.Patria = "epizode_8_end";
			Patria_SiegeEnd();
			ChangeCharacterNationReputation(pchar, FRANCE, 20);
			ChangeCharacterComplexReputation(pchar, "nobility", 10); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			ChangeCharacterComplexReputation(pchar, "fame", 10);
		break;
		
		case "patria_69":
			pchar.quest.Patria_BastionTimeOver.over = "yes"; //����� ������
			dialog.text = "�� ������� � ����������� ����� ���������� � � ��������� ��� ����������. ������ ������ ��� ������ � ����� ������ ����������. �� � ��� � ���� ������ ���������� ������� ����� �������� ���� � ������������ �������������� - ������ ����-������� ������ ���� ��������� �������. ��� ������ ���������� ������� ������� �������� - ���, "+pchar.name+"! ���� ���� ��� �� ��������� ����� �������� ����� �������, �� ������� ���������� � �������� ���\n��� ����� ���������. ������� ����� ���������� ����, ����� ������� ������������� ���������...(�������) ��� ����� ����������� ��������� ����-������ � ������� � �������� �������, � ������� � ��� �����������, � ������ �������� ��� ������...";
			link.l1 = "������ ������������� ���������, �������...";
			link.l1.go = "patria_70";
		break;
		
		case "patria_70":
			dialog.text = "� ��� ��������� �������, ��� ����. ���� ������� ����� �������. ����������� ���-���� � ���� �� ������ ������ ���� ��� � ����� ������� ��������� �� ������ �������� ������� - �������. ��� �������� ������ �������� ��������� � ��������� � ������� ��� ���� ������������ ��� �������. ���� ������� �� ���� ��������� ����� - � ������ ������� � ������� � ��� ������ ������� �� �����������. ����� � ����� ��� �������� �������� � ������� 20 000 ���� �� ������� �������� � ����������� ��� ������ ��������. ���, ��������...";
			link.l1 = "������, �����.";
			if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton_Fail")) link.l1.go = "patria_71";
			else link.l1.go = "patria_71_1";
		break;
		
		case "patria_71_1":
			dialog.text = "�����, ��� ������, � ����� ������������ �������� ������� '�������'. �� �������������� � ��������, ����� �� �����, � ��������� � ���������, �� ������ ����� ��� ��� ���� ������������ � ����� ������� ��� ��� ������.";
			link.l1 = "�������!";
			link.l1.go = "patria_71";
			pchar.questTemp.Patria.Ecliaton_Bastion = "true";
			sld = characterFromId("Ecliaton_Cap");
			sld.dialog.currentnode = "ecliaton_cap_7";
			sld.DeckDialogNode = "ecliaton_cap_7";
		break;
		
		case "patria_71":
			AddMoneyToCharacter(pchar, 20000);
			dialog.text = "� ������ ������ �����, �������. �� ��������� ���� ����������, ��������� ��������, ��� ������ ����-��������, � �������� ����������� ������� ��� ������. ������ ����� �������� �� ������������. �� ������ ������ �� ���� ����!";
			link.l1 = "������... (�������) ��� ��������� ������ �� ����-��������? �� �� ����� ����� ������� �� �� �������...";
			link.l1.go = "patria_72";
		break;
		
		case "patria_72":
			dialog.text = "(�������) ����� �������� ������� �����, �������� � ������ ���������� �����������, ������� ������� ������, �� ���������. ���� ��������� ������� � �� ��������� ������������, � ����������.";
			link.l1 = "������, � �����. ����� � �����������?";
			link.l1.go = "patria_73";
		break;
		
		case "patria_73":
			dialog.text = "��������, "+pchar.name+". �� ��� �� �������� ���� ������� �� �������� �����������. ������� �� ������� ������ ��� ������� � �������, � ����� �������� �������������, ������� ������ ������� �� � ����� �������!";
			link.l1 = "����� �������, �����!";
			link.l1.go = "patria_74";
		break;
		
		case "patria_74":
			TakeNItems(pchar, "chest", 10);
			Log_Info("�� �������� 10 �������� � ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "������ ������ ����. ����� �����, �������! ��� ��� � �������!";
			link.l1 = "�� �������, �������.";
			link.l1.go = "patria_75";
		break;
		
		case "patria_75":
			DialogExit();
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton_Bastion")) sTemp = "����� � ���� ������������ �����  � �������� ������� '�������'.";
			AddQuestRecord("Patria", "48");
			AddQuestUserData("Patria", "sText", sTemp);
			pchar.questTemp.Patria = "epizode_9_continue";
			SetFunctionTimerCondition("Patria_BastionSturmTimeOver", 0, 0, 62, false);
			// ������� ����-������� � �����
			int n = FindIsland("SentMartin");
			Islands[n].reload.l1.radius = 600.0;
			LocatorReloadEnterDisable("Marigo_ExitTown", "reload3", false); // ������� ��������� ������
			sld = CharacterFromID("Marigo Fort Commander");
			LAi_SetImmortal(sld, false);
			Character_SetAbordageEnable(sld, true);
			// ������� ��������� ������� �������
			pchar.TempPerks.QuestTroopers = true;
		break;
		
		case "patria_76":
			dialog.text = "��� �� ��� ������������ ��� �����-�� ��� �����, ��� �� �������� ��� ����-��������, ��, ��� ����?";
			link.l1 = "���������, ���� ������������������, ��� � ������ ��� ���� �� �������!";
			link.l1.go = "patria_77";
		break;
		
		case "patria_77":
			dialog.text = "�� ��������� ���� ��������� �� �����! ����-������� ��������� �������, ���������� ������� ������� ����. ��� ������� ������! �� �� �� ������ ���������������, ������ ���� ���������� ��������� �� �� ����. ��� ������ ������������� �� ���� ��� ������� ����������� ������ ������������� ������� ��������! ��������� ����� � ����-������ ������ ������� ������� �������: �� ���������� ������� ����� ������, ������ ���� �� �������. �� ��� ������� �����, � ���� ��� ���� ����� ��������� ����� ���� ���������, "+pchar.name+"\n���� ��������� ��������� �������� ������ �� ������ ���������. �������� �������� ������� ���������� � ������� - ������ ����� �� ����������. ���� �� �� � �����, "+pchar.name+": ��������� - ���������� ������������ � ������������. ���-����� � ������ '������ �������� �����' ��������� ��������� �� ������� �� �������� ������. � ��� ���-��� �������� �� ����, �� ���� �����������\n��� ��� ������ �� ������ �� ������ ���� ��� ������������ ���-�����. � ������ �� ����� ���������� �����������. ���-�� ����� ������ ���� ������� ����� ��������� � ������� ������� �������� � ������� �������. ���� ������: ����� ���� ������� � ��������� ��� ���-����� � ������. ������� ������������� �����������, ����� ����������� ������ �������� ���������� ����� �� ������. ��� ����� �����, "+pchar.name+", ����� ������� �� ������� ��� ������������... ��, �� ������ ����\n��� ����, ��� � ������ �� �������� ��� ������� �� �����, �� ���� ������������� ������ � ����������, � �������� ��� � ���� ������ ���.";
			link.l1 = "������ �� �����, �������, ��� �� ��� �� �����? ������� ����� � ��������� ��� ����� ������.";
			link.l1.go = "patria_78";
		break;
		
		case "patria_78":
			dialog.text = "����� ��� ��������� �����, ����-�������. � �� ����������� � �����������, ��� ����� ��������, ����� ����� �����, ��� �������� ��������� � �����������, � � ���������� � ���, ����� ����� �������, ����������� ��� �� ����������, ��������� ����� ���.";
			link.l1 = "���� �������� ����������, �������. ��������� �����������?";
			link.l1.go = "patria_79";
		break;
		
		case "patria_79":
			dialog.text = "��������. �����, ��� ����!";
			link.l1 = "...";
			link.l1.go = "patria_80";
		break;
		
		case "patria_80":
			DialogExit();
			Items[sti(pchar.EquipedPatentId)].TitulCur = 5; 
        	Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
			pchar.questTemp.Patria = "epizode_10_start";
			AddQuestRecord("Patria", "52");
			Patria_SlaveShipsStart();
			pchar.GenQuest.BoardCrewType = 9;
			ChangeCharacterNationReputation(pchar, FRANCE, 15);
			ChangeCharacterComplexReputation(pchar, "nobility", 10); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			ChangeCharacterComplexReputation(pchar, "fame", 10);
		break;
		
		case "patria_81":
			dialog.text = "�����������! ��� ��� �� ���������� ����� '����������', "+pchar.name+". �����-�� � �����, ��� ������ �� ����� - ������ ������� ������ �� �������, ������ ��� �� ��� ����� ������, �� �������� ���� �� ����� ������������� ���������. � �����, �� ��� ����������, ���� � ��������� � ������ �������� ���������� ��� ������� � ������ �����������.";
			link.l1 = "����� ���, ���������! �� ���� �����!";
			link.l1.go = "patria_82";
		break;
		
		case "patria_82":
			dialog.text = "��, ���� ���������� ������� �����, ��� ������� ����! ��-��! ������� �� � ��������� ���, ����-�������. ������������� �� ���������. �� ������?";
			link.l1 = "��� �����, �������. ��������� ������, ���������� �������� - � ����� � ����.";
			if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton_Fail")) link.l1.go = "patria_83";
			else link.l1.go = "patria_83_1";
		break;
		
		case "patria_83_1":
			dialog.text = "�� �������� ������� ������������ ��� '���������'. �� �������������� � ��������, ����� �� �����. ������ ���� ������ ��� ���� � ���������� � ������ ����� ����������� � ���� � ���.";
			link.l1 = "�����������. ������ ������� � ������������� ����������� - ��, ��� ����� ��� �������� �����.";
			link.l1.go = "patria_83";
			pchar.questTemp.Patria.Ecliaton_Curacao = "true";
			sld = characterFromId("Ecliaton_Cap");
			sld.dialog.currentnode = "ecliaton_cap_11";
			sld.DeckDialogNode = "ecliaton_cap_11";
		break;
		
		case "patria_83":
			dialog.text = "����������� �� �������, "+pchar.name+". ��� ����, ����� �����, ������ ��� ��� ������� � ����-��������.";
			link.l1 = "...";
			link.l1.go = "patria_84";
		break;
		
		case "patria_84":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_25";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.5);
			ChangeCharacterComplexReputation(pchar, "nobility", 2); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 2);
			ChangeCharacterComplexReputation(pchar, "fame", 2);
		break;
		
		case "patria_85":
			dialog.text = "� ���� ��� ��� ������� �� ������. ���� ���������� �� ��� ����-�������� ��������� �������. ��������������� ������ �� ��������. ��� ��� ��� ��� ���������� ���!";
			link.l1 = "���������, �����! ��� ������� ������ � �������!";
			link.l1.go = "patria_86";
		break;
		
		case "patria_86":
			dialog.text = "� ������, � ������, ��� ���� ������ ���������. � ������������ ��� �������� ������, � ������������ �������� ��� ��� ����� �����. ������� ���, ������� �����. �������� ��� ����� �������� � ���������� ���������. ������ ��������������� ��������� � ���� ����������. ����� ������� ��� ����� ����������� ����������. � ����� ����� �� � ���� ����� ���������� - � ���� ����� � ��� ����� ���������� ��������.";
			link.l1 = "������, �������. �� �������!";
			link.l1.go = "patria_87";
		break;
		
		case "patria_87":
			DialogExit();
			AddQuestRecord("Patria", "65"); // ����� �������� ������-���������-"+pchar.name+"
			pchar.questTemp.Patria = "epizode_12_start";
			ChangeCharacterNationReputation(pchar, FRANCE, 15);
			Patria_CondotierStart();
			ChangeCharacterComplexReputation(pchar, "nobility", 15); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 15);
			ChangeCharacterComplexReputation(pchar, "fame", 15);
		break;
		
		case "patria_88":
			dialog.text = "��, "+pchar.name+". � �����, ��� ����� ���������� ���, ��... ���, � ����� �������� ������� ��� ��������� ��� ��������������� ������ ���������. �� ��� ������ � ���� �������� ��� ��� ���: ������ ����� ���� � ���� �������� � ���������. ��� ������� ���� �����������, ���������� ��� ������������ �� ��������. � ������, ��� �� ��������� ������ ����� �����, ��� ���������� ������� ��� ������. �������. �� ��������, ���� ���?";
			link.l1 = "������ ������� � ������ �� ������, ���������, � ������ ������ ���� ����.";
			link.l1.go = "patria_89";
		break;
		
		case "patria_89":
			AddMoneyToCharacter(pchar, 300000); 
			TakeNItems(pchar, "chest", 5);
			dialog.text = "��, ����-�������, �������, �� �� ���� �� � ����� �� �������?.. �� ������ ����� �����, �� � �����? ��� �� ���������� ���� � ����� ����? �������, ��� ����� ������������ �������� ������������� ����������� �� ��������� ��������, �� ��� ������� ����... ��� � �������� � ���� ����������. ������ � ���, ��� �������, ���������� ����������� ��������� ��������� �����������! � ������������������ �����������, �������, � �� �� �����, ��� ����.";
			link.l1 = "��������� ��� �� ������ �����, ���� ������������������. � ���� ��������, ��� � ������ ����������� ����� � ���� �������. � ����� �������, ����������. �������, � ������ ���� �������� ���������� ������ ������? ���� ������������ � �����.";
			link.l1.go = "patria_90";
		break;
		
		case "patria_90":
			dialog.text = "������ ��������, "+pchar.name+"? �-��-��! ������ ������� � ����� ��������� �������� - � ��� �������� ��� ����������! ��, � ���������, � ���� �������� ������� �����������. �� ��� ����� �����, ��� ����, �� ������� ���� - ��� �������.";
			link.l1 = "��� �������, ������� ������ �� ����������, ��� �������. ���� � �����������, ������ ������� � ���������. ��� ������ ����������... ����������. ���?";
			link.l1.go = "patria_91";
		break;
		
		case "patria_91":
			dialog.text = "������������, ��� � �����, ������ ����� ���� ����, ��� � ��� ��� ����... � � ��� �������� ����� ���������� '��������', ����-�������...";
			link.l1 = "��� ���? � ��� �� ���?";
			link.l1.go = "patria_92";
		break;
		
		case "patria_92":
			dialog.text = "��� ��� � ���� ����� ��������, ����� ����� �����. �� �������, ��� ���� �� ���� ���������?";
			link.l1 = "���... �� ���-�� �������� � ����������� ����-������� �������� ��������. � ������ ������ ������� ����� �� �������, ��� � ����������?";
			link.l1.go = "patria_93";
		break;
		
		case "patria_93":
			dialog.text = "������. ������ ����������� ��������. �� ������� ��� � ���� ����� ������, ���� �� �������� ����������� ����� ����������� �������� � ������� ������������, �������� ���� ������� � ������ ���� �������� ��������. � ������� ����� ���, �, ���� �� �� � �����, "+pchar.name+", ������ ������ ���������� ��������� �������� �����. ��� ������ ��������� ���������� ��������� ���������� �� ���� �������� �����, �� �� ��������, � ��� �������� �����������\n����������� � ���� �������� � ����������, ��������������� ������� ��������, �������� ������ ������ ���������. ������ �������� ����� ��������� � ������������� �������� �����, ����� ������� �� ��������� �� ����� ����������. � ������� ����� �� ���-������, ��� � ����������, ��� �� ��������, ��� � ��������, � ��� ���.";
			link.l1 = "�� �� �� ��������� ��� ��� ������? ��� ��� �� �������?";
			link.l1.go = "patria_94";
		break;
		
		case "patria_94":
			dialog.text = "�������. � ��� ��, ��� ����� �������� ������� � ������� � ���������� ����� �������� �� �������� ���������, ��� ����� �� ������� ���. � ������������� �� ������� ������� � ������� ������, ������� ������������ ��� �����, �� ��� - ������ ��� �� �������. ��� ���� ������� ��������, � �� ������... ��� ���.";
			link.l1 = "��...";
			link.l1.go = "patria_95";
		break;
		
		case "patria_95":
			dialog.text = "�� � �� ���� ��������, ��� �� � ���� ��� ��������� - �������� ������� �� ����������, � ������ ����������� �� ������ ���... ��� � ����, ����-�������... ��� �� � ����.";
			link.l1 = "�������.";
			link.l1.go = "patria_96";
		break;
		
		case "patria_96":
			dialog.text = "������, ���� ���, � � ���� ��������� ������... ����, � �� ���������� ��������, ��� ����� ����� ������������ � ���� �������� �������� ��������, ��... ����� �� ���������. � �������� ��� �������� ����������� �� ������, ������ � ���� ������ �������� ��.";
			link.l1 = "���... ���, ��� � ����������?..";
			link.l1.go = "patria_97";
		break;
		
		case "patria_97":
			dialog.text = "��, �� ��� ��, �� ���� �� ���� ����������! ����� - ����������� ���� � ������, ���� �������� ��������! � ���� ��, ���������� ���������� ������ �� ����: �� ������ ������ ������� ������ ���������. ���� ����� ���� ���� � ����������� ����������� �������� �������� ���, ���������, "+pchar.name+"? ����� �����, ���������� �� �������, �������, ��� ��� ��������� ����������, ������������...";
			link.l1 = "� ��� ���� �����������, ���������?";
			link.l1.go = "patria_98";
		break;
		
		case "patria_98":
			dialog.text = "���, ��� ���, "+pchar.name+". � ������������ ���. ����� ����������� �������� � �������� �������, �����������, ��������... ��� ��������.";
			link.l1 = "������, ����� ���-�� ����� ���������, ������ ������ �����. ��... ��������, ��������?..";
			link.l1.go = "patria_99";
		break;
		
		case "patria_99":
			dialog.text = "� ����, � ��� ��������� ����, ��� ����? � �� ����������. � ��� ������������ ��. ������� ������ ������...";
			link.l1 = "������, �������. ������� ��� ����.";
			link.l1.go = "patria_100";
		break;
		
		case "patria_100":
			dialog.text = "������� ���, "+pchar.name+", ��� � ������ ������ �� �� ���������. ������ ���� ������� � ����. � ���� ��� ������� ���, ��� ����?";
			link.l1 = "����� ���, ���������. ��� ��� ����� ������?";
			link.l1.go = "patria_101";
		break;
		
		case "patria_101":
			dialog.text = "�� ������ � ����-�-������. ����� ����������� ��� ���������� ���� � ������ ���������, ��� �� ������...";
			link.l1 = "������. � ������ ��������� ����.";
			link.l1.go = "patria_102";
		break;
		
		case "patria_102":
			DialogExit();
			AddQuestRecord("Patria", "67");
			pchar.questTemp.Patria = "epizode_12_pirates";
			Patria_CondotierSail();
		break;
		
		case "patria_103":
			dialog.text = "������ ���. ����� ��� ��� ���������. ����� ����, ��� ��� �������� ��������... ������, �� ������ ��������� ���������, ����-�������! ��� ����� ����� � ��� ���������!";
			link.l1 = "� ������� �������� � ���, �������.";
			link.l1.go = "patria_104";
		break;
		
		case "patria_104":
			dialog.text = "��� ����, � � ����� ����� ����. � ���������� ��� 100 000 ���� - �������, ��� ������� ���� �������� � ��������...";
			link.l1 = "��� ������� ��� �������, ���������!";
			link.l1.go = "patria_105add";
		break;
		
		case "patria_105add":
			AddMoneyToCharacter(pchar, 100000); 
			dialog.text = "����� � ���������� ��� ��� ��������� �������. ������, �� ������� ���������� ���� ���� � ������� ������� ���� ������������� �� ���� ��������� ������! ����, ����-������� "+ GetFullName(Pchar)+", � ������ ��� ���� ������ �������������� ��� ������������ ������! ��� ������������ ������ ��� ��� �������� � ������ �������! ���� �� ������ ��������� � ������, ����� ����� ����� �������� ����������� ��� ������ - �� ������ ���� �� ������ ��� ������ ������: � ������� � � ���� ��������� �������! � ��� ���� ���������� ������� ������� � ������-������� �����!";
			link.l1 = "������ ������������ �� ������� ���! �������, ���������, �, �����, �� �������� �������� �����...";
			link.l1.go = "patria_105";
		break;
		
		case "patria_105":
			ref itm = ItemsFromID("blade_36");
			itm.picIndex = 16;
			itm.picTexture = "ITEMS_40";
			itm.price = 50000;
			itm.Weight = 3.0;
			itm.lenght = 1.05;
			itm.curve = 1.0;
			itm.Balance = 2.0;
			GiveItem2Character(pchar, "blade_36");
			Log_Info("�� �������� ����������� ���");
			PlaySound("interface\important_item.wav");
			dialog.text = "���������!.. � ���� �� ��������� �����, ��� ���� ��������� ��������. ��������, �������. ����-������� "+ GetFullName(Pchar)+", � �������� ��� ������������ ����-��������!";
			link.l1 = "����! � �� ���������?";
			link.l1.go = "patria_106";
		break;
		
		case "patria_106":
			ChangeCharacterComplexReputation(pchar, "nobility", 12); // 14-add
			ChangeCharacterComplexReputation(pchar, "authority", 12);
			ChangeCharacterComplexReputation(pchar, "fame", 12);
			dialog.text = "���, ��� ����. ������ �� ���������� �������������� ���� ����-��������.";
			link.l1 = "�������, ��������� ��� ����������. � �� ����� ���� ����������� � ������ ������� ��������! � ������ ������������� ����... ��� �� ���!";
			link.l1.go = "patria_107";
		break;
		
		case "patria_107":
			dialog.text = "������ �� ��������. ���� ���, �� ������������: �� ������ ����, ��� ������. ��� ������� ���� ������� �� ���� �������� ��������� �����������. � �� ������ ����������� ����������. "+pchar.name+", �� ����� �� ���������, ������ �� ����-������� ��������� ������ ��? ������ ����� ������� ������ ��� �����, � �� � ���� �� ��������� ��������. � ��� �� ����-�������� ������������ ����� ��� �������, �� ���������, � ��� �?";
			link.l1 = "������� ������?";
			link.l1.go = "patria_108";
		break;
		
		case "patria_108":
			dialog.text = "�������! � ������ �������� �������: � ����� ���, ������ �����, 15 �����, �� ������ �������� ����� ������� ������� � ������� �� �������� �������� � �����. ��� ��������� ����� �������� 100 000 ���� ����������.";
			link.l1 = "���! ����� ���! �������, �������. ��, ���� � �� ���� ����� �� ���������, �� � �������� ����� ������������. � ���� � ���� ������� �� �������?";
			link.l1.go = "patria_109";
		break;
		
		case "patria_109":
			dialog.text = "����� ������ - ����� � ���������, � �, ���� � ����� ����������, ����� ��� ������.";
			link.l1 = "������, ���������, ������������. ������ � ���� ����? ����� ��� ���� �� ����������?";
			link.l1.go = "patria_110";
		break;
		
		case "patria_110":
			dialog.text = "���� ���, ����������, �� ���� ��������, � ����, ��� ��� ������. �����, "+pchar.name+"!";
			link.l1 = "�������, �������!";
			if (pchar.questTemp.Patria == "epizode_12_baronwin") link.l1.go = "patria_119";
			else link.l1.go = "patria_111";
		break;
		
		case "patria_111":
			DialogExit();
			AddQuestRecord("Patria", "77");
			CloseQuestHeader("Patria");
			pchar.questTemp.Patria = "end"; // ����� �������
			pchar.questTemp.Patria.Governor = "true"; // "+pchar.name+" ����������
			sld = CharacterFromID(pchar.questTemp.Patria.SpanishID);
			SetCharacterRemovable(sld, true);
		break;
		
		case "patria_112":
			dialog.text = "���� ������, ����� ����! �����, �� ������ �� �������� ������. ��� �� ��������� � ����� ����, "+pchar.name+"? ������� ������. ��� �� �����������?";
			link.l1 = "������ ��� ����� ������� �� ���...";
			link.l1.go = "patria_113";
		break;
		
		case "patria_x112":
			dialog.text = "���� ������, ����� ����! �����, �� ������ �� �������� ������. �� ����� ������ ����� ����� ������ ��� ����� �������! �� ����� �� �������� ��� ������� � ��� ����?";
			link.l1 = "�� ���, �������! ������� ���!";
			link.l1.go = "patria_x113";
		break;
		
		case "patria_y112":
			dialog.text = "���� ������, ����� ����! �����, �� ������ �� �������� ������. ��� ����� �� �� ������� ��� ������� � ��� ����?";
			link.l1 = "�� ���, �������! ������� ���!";
			link.l1.go = "patria_y113";
		break;
		
		case "patria_x113":
			dialog.text = "����. �����, ���� ���, ��������, ��� �� ��� � �������. ��������� - ���� ���������, ���� ���? � �� �������� ������ ���������� �� ������������ �� ��� ������� ���������� � ����� ��������� ������ �� ���������... � ��� ����� ������, "+pchar.name+", ������ � �������� ��� ���� ��������. ��, �������, ���������, ������?";
			link.l1 = "�������.";
			link.l1.go = "patria_114";
		break;
		
		case "patria_y113":
			dialog.text = "����. �����, ���� ���, ��������, ��� �� ��� � �������. ������ �� ������� - ������� ����, ���� ���? � �� �������� ������ ���������� �� ������������ �� ��� ������� ���������� � ����� ��������� ������ �� ���������... � ��� ����� ������, "+pchar.name+", ������ � �������� ��� ���� ��������. ��, �������, ���������, ������?";
			link.l1 = "�������.";
			link.l1.go = "patria_114";
		break;
		
		case "patria_113":
			dialog.text = "����. �����, ���� ���, ��������, ��� �� ��� � �������. ������ - ���� ������, ���� ���? � �� �������� ������ ���������� �� ������������ �� ��� ������� ���������� � ����� ��������� ������ �� ���������... � ��� ����� ������, "+pchar.name+", ������ � �������� ��� ���� ��������. ��, �������, ���������, ������?";
			link.l1 = "�������.";
			link.l1.go = "patria_114";
		break;
		
		case "patria_114":
			dialog.text = "� ����� ������, ��� ����, �� ������� ���, ��� �����. � ��� �����, ��� ������ ������. � ���, ��� ������ ����� ���� � ����. ��� ��� �������� ��� ���, � � ������, ��� ���� ��������� ������� �� �������. � � �����, ��� ��� ��� ���� ����������� � ������.";
			link.l1 = "������, ���������, ������������. ������� ���������, ������ �����������, � �� ����������� - � �����. ������ � ���� ����?";
			link.l1.go = "patria_115";
		break;
		
		case "patria_115":
			dialog.text = "��������, "+pchar.name+". ����� ���!";
			link.l1 = "�������, �������!";
			link.l1.go = "patria_116";
		break;
		
		case "patria_116":
			DialogExit();
			AddQuestRecord("Patria", "78");
			CloseQuestHeader("Patria");
			pchar.questTemp.Patria = "end"; // ����� �������
			sld = CharacterFromID(pchar.questTemp.Patria.SpanishID);
			SetCharacterRemovable(sld, true);
		break;
		
		case "patria_117":
			dialog.text = "������ ���. ������, �� ������ ��������� ���������, ����-�������! ��� ����� ����� � ��� ���������!";
			link.l1 = "� ������� �������� � ���, �������.";
			link.l1.go = "patria_118";
		break;
		
		case "patria_118":
			dialog.text = "��� ����, � � ����� ����� ����. � ���������� ��� 100 000 ���� - �������, ��� ������� ���� �������� ��������, � ��� ������� ��������� ��� �� ������� �����.";
			link.l1 = "��� ������� ��� �������, ���������!";
			link.l1.go = "patria_105add";
		break;
		
		case "patria_119":
			DialogExit();
			AddQuestRecord("Patria", "87");
			pchar.questTemp.Patria = "europe";
			pchar.questTemp.Patria.Governor = "true"; // "+pchar.name+" ����������
			SetFunctionTimerCondition("Patria_EuropeTime", 0, 0, 175+rand(10), false); // ������
		break;
		
		case "patria_prison":
			dialog.text = "��� �� ���, "+pchar.name+"! ��� �� ��� ���... ��������� �� ����!";
			link.l1 = "���...";
			link.l1.go = "patria_prison_1";
		break;
		
		case "patria_prison_1":
			dialog.text = "� ����, ��� ��� ��. �� ������� ��������. ��� ������ ������� ����� ����� ������� �� �� ���� �������� �� ��������� ������������ ������� ����-��������, �� ������, ��� ��������� ������, ��, ��� �����, ��������� ����������� ������ �����������. ���� ��� ����� �� ����������, �� � ����: ��� ��� ��. ������, "+pchar.name+"?.. ������ ������: ������? ������? ������� ����? ��������? ��� ���� �������-�����������?";
			link.l1 = "� ���� ������� ��, ��� ������ ��� ������ �������: � ������� �������� � ���, �������! ������ ��� ��������, ���, ������.";
			link.l1.go = "patria_prison_2";
		break;
		
		case "patria_prison_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			bDisableFastReload = true;//������� �������
			LAi_SetActorType(npchar);
			SetFunctionTimerCondition("Patria_EuropePuancieClear", 0, 0, 5, false); // ������
			pchar.quest.Patria_Europe_final.win_condition.l1 = "location";
			pchar.quest.Patria_Europe_final.win_condition.l1.location = "Charles_town";
			pchar.quest.Patria_Europe_final.function = "Patria_EuropeFinal";
		break;
		
		case "patria_patentfail":
			pchar.GenQuest.BoardCrewType = 0;
			DialogExit();
			pchar.questTemp.Patria = "fail";
			CloseQuestHeader("Patria");
			// ������ �������, ���� ����
			if (CheckAttribute(pchar, "questTemp.Patria.Ecliaton"))
			{
				sld = characterFromId("Ecliaton_Cap");
				RemoveCharacterCompanion(pchar, sld);
				sld.lifeday = 0;
				DeleteAttribute(pchar, "questTemp.Patria.Ecliaton");
			}
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}