// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������, " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//--> Jason, ����� ��������
			if (!CheckAttribute(npchar, "quest.Rum") && CheckAttribute(pchar, "questTemp.Sharlie.Lock") && pchar.questTemp.Sharlie == "ship" && makeint(environment.time) > 5.0 && makeint(environment.time) < 19.0)
			{
				link.l1 = "�����, � ��� ������. �����, � ��� ���� �����-������ ���������, ������� �� ������ �� �������� ���?";
                link.l1.go = "Sharlie_rum";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Rum") && pchar.questTemp.Sharlie.Rum == "regard")
			{
				link.l1 = "� �������� ���� �������. ������ � ����� ��������� � ����� �� ������� � ������� ����� �����.";
                link.l1.go = "Sharlie_rum_5";
			}	
			//<-- ����� ��������
			
			//Jason, ����������
			if (CheckAttribute(PChar, "questTemp.Portugal") && pchar.questTemp.Portugal == "ToMartinique" && !CheckAttribute(npchar, "quest.Portugal"))
			{
				link.l1 = "��� ����� ����� ������� � ���� �� ���-��� ��� - � ���� �� ����� �������, ��� ����� ��������� � �����������.";
				link.l1.go = "Portugal";
			}
			if (CheckAttribute(PChar, "questTemp.Portugal") && pchar.questTemp.Portugal == "MartiniqueGovernorEnd")
			{
				link.l1 = "�������, ��� ����, �������� � ���� �������, ���� �� �����? ������ ��������� ����, �� ������� �����.";
				link.l1.go = "Portugal_2";
			}
			//����������
			// Jason ����� � ���������
			if (!CheckAttribute(npchar, "quest.LongHappy") && CheckAttribute(PChar, "questTemp.LongHappy.MarryRum") && LongHappy_CheckTavernGoods())
			{
				link.l1 = "� ��������� �������� ��������� �������� ��� ����� �����. �������, �� ��� � �����?";
				link.l1.go = "LH_tavern_SP";
			}
			if (CheckAttribute(npchar, "quest.LongHappy.Nomoney") && LongHappy_CheckTavernGoods() && sti(Pchar.money) >= 100000+sti(pchar.questTemp.LongHappy.MarryMoney))
			{
				link.l1 = "� ������ ��� ����������� ��� ����� ���������.";
				link.l1.go = "LH_tavern_SP_3";
			}
		break;
		
		//--> Jason, ����� ��������
		case "Sharlie_rum":
			dialog.text = "���������? ��... �� ��������� ��������������� ������� ���������. � ������ ������ �������... ���� � ���� ���� ������. ��� �� ������ ������ ���������, �� ������� ��������������� � ������� - ������� ������ � �������� �������\n������ ��� �������� ���������� ���� �������� - ������, ������� ������ ��� �� ������...";
			link.l1 = "����������, ����������, �������, ������, ��� �� ���� �� ������ ��� ��������? �������, � �� �������, �� �� �� ������ ������ - ����������.";
			link.l1.go = "Sharlie_rum_1";
		break;
		
		case "Sharlie_rum_1":
			switch(rand(4))
			{
				case 0:
					pchar.questTemp.Sharlie.Rum.Pass = "������ ����� �������� ����";
				break;
				case 1:
					pchar.questTemp.Sharlie.Rum.Pass = "����� � ����� ����� �����";
				break;
				case 2:
					pchar.questTemp.Sharlie.Rum.Pass = "�� ����� ����� ������ �����";
				break;
				case 3:
					pchar.questTemp.Sharlie.Rum.Pass = "����� ������ ��� �������";
				break;
				case 4:
					pchar.questTemp.Sharlie.Rum.Pass = "�������� ���� �� �����";
				break;
			}
			dialog.text = "������. ������ ������: ��� ����� ��������� � ��� ������� ��������� ������ �������� ��������� ���� � ����� �������� ���������� - �� ������ ������� ������ ��� ����������� �� ���� ����� ������, � ����� �� ���� ����� ���� ������ �������� ������ � ������ �����\n������� ������� � ������� ��������� � ������ ����� �������� �������� �����, ������ ��� ��������� '�������'. ��� ����� ����� ����� ��� ����� � ��������� � ���� �� ����\n��� ���� ���� � ����� ������������ ����� ������ � ����� ��������� �� ����� - ��� ����� ����� �����, ���� �������. ����� ����, ��� ��������� �� ������, � ��� �������� �������. ��� ����� ������� ��� ������: '"+pchar.questTemp.Sharlie.Rum.Pass+"'\n���� ������� �����������, ��� ������ ������� - ��� ������ ��������� �� ���� � ������ �� ���������. ������� � � �� ���� �������� ��� ���� ��������� �������, ������� �������� � ����. ��������� ������.";
			link.l1 = "'"+pchar.questTemp.Sharlie.Rum.Pass+"'.";
			link.l1.go = "Sharlie_rum_2";
		break;
		
		case "Sharlie_rum_2":
			dialog.text = "�������. ��������� ��� ���� ��� ��������� ���, � ����� - �������� ���-������. ����� �� ������ - '����� ����, �����'. ����� ����� �� ������ ����� ����������� ����� � ��������� ����, ������� ����� ��������� � ����� ���������� ��������� �� ������� - ��� ��� ��������\n��� � ��� ������. �� ����� �� ������� �� ���� �� ������ ���������� ������ - ������ ��������� � �����. ���� ��� ��� �� ����� ������� � �� ������ ��������� ��� ������� - �� �� ���������� � ������� ��� ���� ����� ����.";
			link.l1 = "� ���� ��� �� ������, ��� ��� ������ ����� �������? � ������, ��� �� ��������. ��� ������?";
			link.l1.go = "Sharlie_rum_3";
			link.l2 = "�� ���� �� ����������� ��� �������� ������������? ��... ������, � �� ���� ��������� ����� ������. ����� ���� ��������, ����� �������, ��� � ������ �� ������.";
			link.l2.go = "Sharlie_rum_exit";
		break;
		
		case "Sharlie_rum_exit":
			dialog.text = "��� ������, �����. ���� ��������� � ���� ���.";
			link.l1 = "�������. ����� ����� �������, "+npchar.name+".";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Sharlie.Rum");
		break;
		
		case "Sharlie_rum_3":
			dialog.text = "������ ����� � �����, ������� ����� � �����, � ���� ������. �� ����������� - �� ����� �������� �� ����� ����-����� ����� ����, � '�������' ����� ����� ��� ������ �� ���� ����. ��, � �������� ��� ���������� ������� ��� ��� ��������� ����� - ���, �������, �����-������, �� �����, ��� ������. ���� �������� ��������� �� �������� ����������� �������, ��� ��� ����� �� ����� ������� ���� �� �����. � �� �������� ������!";
			link.l1 = "� �����. �� �������, "+npchar.name+"!";
			link.l1.go = "Sharlie_rum_4";
		break;
		
		case "Sharlie_rum_4":
			DialogExit();
			AddQuestRecord("SharlieB", "1");
			GiveItem2Character(pchar, "spyglass1"); 
			Log_Info("�� �������� ��������� �����");
			PlaySound("interface\important_item.wav");
			pchar.quest.Sharlie_rum.win_condition.l1 = "locator";
			pchar.quest.Sharlie_rum.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_rum.win_condition.l1.locator_group = "rld";
			pchar.quest.Sharlie_rum.win_condition.l1.locator = "loc0";
			pchar.quest.Sharlie_rum.win_condition.l2 = "HardHour";
			pchar.quest.Sharlie_rum.win_condition.l2.hour = 19.00;
			pchar.quest.Sharlie_rum.function = "Rum_CreateBarkas";
			SetFunctionTimerCondition("Rum_CreateBarkasOver", 0, 0, 1, false);
			pchar.questTemp.Sharlie.Rum = "true";
			npchar.quest.Rum = "true";
		break;
		
		case "Sharlie_rum_5":
			dialog.text = "������������! � ����, ��� �� ��� ����� ����������. ��� ���� ������?";
			link.l1 = "��, ��� ��� ����������...";
			link.l1.go = "Sharlie_rum_6";
		break;
		
		case "Sharlie_rum_6":
			dialog.text = "��� ���� ������� - ���� �����. ��������� ����� �������� ����. � ��� ��������� ������� - �������� ��� ��� ������� ����. ����� ����, ��� �� ��� ����������, �� ����� �������, ������ �� ���� ����� �����.";
			link.l1 = "�������! ���� ������� � ���� ��������! �� �������!";
			link.l1.go = "Sharlie_rum_7";
		break;
		
		case "Sharlie_rum_7":
			DialogExit();
			AddMoneyToCharacter(pchar, 5000);
			TakeNItems(pchar, "potionrum", 3);
			AddQuestRecord("SharlieB", "5");
			CloseQuestHeader("SharlieB");
			DeleteAttribute(pchar, "questTemp.Sharlie.Rum");
		break;
		//<-- ����� ��������
		
		//����������
		case "Portugal":
			dialog.text = "�� ��� �������, ���� � ���� �������. ������� 50 ���� - � �� ��� ��� ��� ����.";
			if (sti(pchar.money) >= 50)
			{
				link.l1 = "���, �����.";
				link.l1.go = "Portugal_1";
			}
			else
			{
				link.l1 = "������ ������ � �������� ������ � �������.";
				link.l1.go = "exit";
			}
		break;
		
		case "Portugal_1":
			ref sld;
			DialogExit();
			AddMoneyToCharacter(pchar, -50);
			npchar.quest.Portugal = "true";
			LocatorReloadEnterDisable("Fortfrance_tavern", "reload2_back", false);
			pchar.quest.Portugal_Ill3.over = "yes";
			LocatorReloadEnterDisable("Fortfrance_town", "reload1_back", true);
			LocatorReloadEnterDisable("Fortfrance_town", "reload2_back", true);
			LocatorReloadEnterDisable("Fortfrance_town", "gate_back", true);//������� ������ �� ������
			sld = characterFromId("Portugal");
			ChangeCharacterAddressGroup(sld, "FortFrance_tavern_upstairs", "goto", "goto3");
			sld = characterFromId("PortugalDoctor");
			ChangeCharacterAddressGroup(sld, "FortFrance_tavern_upstairs", "goto", "goto1");
			pchar.quest.Portugal_tavernroom.win_condition.l1 = "location";
			pchar.quest.Portugal_tavernroom.win_condition.l1.location = "FortFrance_tavern_upstairs";
			pchar.quest.Portugal_tavernroom.function = "PortugalInTavernRoom";
		break;
		
		case "Portugal_2":
			dialog.text = "�� ������ ��, ��� �� ����� ��� �����, ����. ����� ���� ������ �����-�� ����, � ���� ���� ����� ���������� ������� � �� ����� ������ � ����, � ��������� ���, ������� �� ���������. � �������� ����, �� ���� ��������� ��� �� ���� ������... �� ����� �� ���� � ����� ��� ��� ���������. � ����������, ������, ��� ������ �����... ��, � � ������ � � ��� ��� ������ ����?";
			link.l1 = "����, " + npchar.name + ", �� �� �����, � ���������. ��� �� ��� �����? ���� ��� �����������?";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			dialog.text = "�� ����� ������ ������... ����, ���! ��������, ���������� ������� ���-�� ��� �������. ����� ��� ������� ��� ������, ������ ����� ����-�� �� ������ ������� ������� �����. ��� � ���, ������� ����... � �� ������ ������, �� ���� ��������� �� �������� ������, ��� � ���� �������� ����... ���������? ���� ��� ������, ��� � ��� ��� ��������� ��� �� �...";
			if (pchar.money >= 1000)
			{
				link.l1 = "�� �����, �� ���� �� ����� ������, ����� ����, �� ��������. �� ��� ����� �����, �������. ���, ������ 1000 ����.";
				link.l1.go = "Portugal_4";
			}
			link.l2 = "�� �����, �� ������� � �� ���. � ��������� ��� � ���� ������, � �� ���� ����� �������.";
			link.l2.go = "Portugal_5";
		break;
		
		case "Portugal_4":
			AddMoneyToCharacter(pchar, -1000);
			dialog.text = "�������, ����. ��� ����, � ����� -  �� ����� ����������, �� ������ ������, ��� ���. � ������ ������� � ��, ���� ����� ��������� � �� ��� ��� ������� � ����� � ���������� ��� ����� � ������� ������, ������ ��� � ������.";
			link.l1 = "�������, �� ��� ������ �� ������ ���������� �����. ��������� �� ����������, ��� ����.";
			link.l1.go = "Portugal_6";
		break;
		
		case "Portugal_5":
			dialog.text = "�� ���� �� ���� ������� � ������ ������, �������.";
			link.l1 = "��-��... ������ �������� ���.";
			link.l1.go = "Portugal_6";
		break;
		
		case "Portugal_6":
			DialogExit();
			sld = characterFromId("Avendel");
			sld.dialog.currentnode = "Avendel_seapatrol_9";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		//����������
		
		// Jason ����� � ���������
		case "LH_tavern_SP":
			npchar.quest.LongHappy = "true";
			dialog.text = "��, ���� ��������� ��������, �� � ������ �� � ������� ��� - ��� �� ��������� � ������ ������ �������, �� � ���� ��� ��� �������. �� ��� ����� ���������  � ���� ����� ���������� ���, ����� ������� ������ V. ������, ���� ���� ������� ������. ��� ���, ���� ������ ������� �������� ����� - ��� ����������� ������������ ����� ����� ����, ��� �� ��� ��������. �� ������ �����������, ��� �������.";
			link.l1 = "�� � ������ �� ���! � ��� �� ������ ��� ��� � �������� �������, ����� � ������... ����������, � ����, ��� �� �� ������, ��� � ������, ����� �������� ������ ����� ��������� ������ � ����������. ����������� �������, ���? �����, � ���� �������, � � �� �������� ���������� - ������� �� ������ ������?";
			link.l1.go = "LH_tavern_SP_1";
		break;
		
		case "LH_tavern_SP_1":
			dialog.text = "��� ��� ����� ������ ������� � �� ����������� - ������ ��� � ������ ����. ���� ����� ������� �������� ��� �������, ��������� ��� �����!";
			if (sti(Pchar.money) >= 100000+sti(pchar.questTemp.LongHappy.MarryMoney))
			{
				link.l1 = "�� �� ���������� - ����� ���������, ��� ���������. � ��, ����� �� ������� �� ��� � ��������, ���� ���� ���� ������� ������ �����.";
				link.l1.go = "LH_tavern_SP_4";
			}
			else
			{
				link.l1 = "�� � ����� �������� ����� ���������! �������, � ����� �������.";
				link.l1.go = "LH_tavern_SP_2";
			}
		break;
		
		case "LH_tavern_SP_2":
			DialogExit();
			npchar.quest.LongHappy.Nomoney = "true";
		break;
		
		case "LH_tavern_SP_3":
			dialog.text = "�������! ���� ����� ������� �������� ��� �������, ��������� ��� �����!";
			link.l1 = "�� �� ���������� - ����� ���������, ��� ���������. � ��, ����� �� ������� �� ��� � ��������, ���� ���� ���� ������� ������ �����.";
			link.l1.go = "LH_tavern_SP_4";
		break;
		
		case "LH_tavern_SP_4":
			DialogExit();
			RemoveCharacterGoods(pchar, GOOD_RUM, sti(pchar.questTemp.LongHappy.MarryRum));
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.LongHappy.MarryMoney));
			AddMoneyToCharacter(pchar, -100000);
			DeleteAttribute(npchar, "quest.LongHappy.Nomoney");
			pchar.questTemp.LongHappy.DrinkReady = "true";
			pchar.questTemp.LongHappy.MarrySP = "true";
			DeleteAttribute(pchar, "questTemp.LongHappy.MarryMoney");
			DeleteAttribute(pchar, "questTemp.LongHappy.MarryRum");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}