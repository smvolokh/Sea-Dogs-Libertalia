// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� ��� ������?", "��� �� ������ ������?"), "��� �������, ��� �� ��� ����������, " + GetAddress_Form(NPChar) + "?", "������ ��� �� ������� �� ��������� ������ ������...", "��, �� ���� �������. �������� ��� ���!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � �����������. ��������...",
                      "�� ��, ������������� � ������ ���...", "���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "mayak")
			{
				link.l1 = "���������� ��������, ���� ��������, �������� ���� � ����� ������. ���� �������� ��� ���?";
                link.l1.go = "guardoftruth";
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "mayak_next")
			{
				link.l1 = "���� �� ������� �� ���� ��������, "+npchar.name+"?";
                link.l1.go = "guardoftruth_5";
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && CheckCharacterItem(pchar, "jewelry33") && CheckCharacterItem(pchar, "jewelry34") && CheckCharacterItem(pchar, "jewelry35"))
			{
				link.l1 = "��� ����� ������� ���� ��������. � ����� ����, ������� ��� �����.";
                link.l1.go = "guardoftruth_7";
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "inquisition")
			{
				link.l1 = "����, "+npchar.name+", ��� ������ ���� ��������?";
                link.l1.go = "guardoftruth_11";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "�������, ������. ��, ������, ������� �����, ��� ��� ���� �������� ����� � ���� ����...";
			link.l1 = "���������. ������, �� - ��� �������. ������ ������: ��� ���� ������� - ��� ����� �����, �������� ��� ������ ������� ���� ��������. � ������� ��� ��� ���� ��������������� - �� ������ ��������� ��� � ��������, ��� �������� ���� �� ��� ����-��...";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "";
			link.l1 = "�� �������� ��������� ����� ����� ������������. �� ������� ������� ������� - ��� ����� ������ �������, �� � ������� � ����� �������. ����� ����, ������� ���� �������� ��� ������ � �����, ��� � ��� �� ���� ������ ����� ��� ���. �����, ����� ����� ����������...";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ��� �����, ������. ��� ����� ������� � ������ ����, �� ������������. � �� ������ ��� ������� ������� ����.";
			link.l1 = "��� ��� �� ���. � ���� ������ ��� ������� ������� ������� '���-��������', ������ �������. �� ������ ������ ��� ����. �� ��������� ��� ������?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "��� ���� � ������ �������, ������, ���������� ���.";
			link.l1 = "�������. � ����������� � ��� �������� � ��� �����. ����� ��� ��� � ����� �� ������� �� ���� ��������. �� ��������, "+npchar.name+"!..";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			DialogExit();
			LocatorReloadEnterDisable("mayak9", "boat", false);
			ref sld = characterFromId("GOT_Marshe");
			LAi_SetStayType(sld);
			LAi_CharacterDisableDialog(sld);
			sld.lifeday = 0;
			pchar.questTemp.Guardoftruth = "mayak_wait";
			SetFunctionTimerCondition("GuardOT_MayakNextStage", 0, 0, 2, false);
			SetCharacterGoods(pchar, GOOD_CINNAMON, GetCargoGoods(pchar, GOOD_CINNAMON) + sti(pchar.questTemp.Guardoftruth.VanilleQty));
			AddQuestRecord("Guardoftruth", "21");
		break;
		
		case "guardoftruth_5":
			dialog.text = "��, ������. ��� ������ �� ��� ��������������. ���� �������� ����� ������� ����. ����� �� ������, ��� �� ��� ���� ������� �� ������ ������.";
			link.l1 = "���������. �����, �� ����� ����� ��������, "+npchar.name+". � ���� - �� ��������...";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			DialogExit();
			pchar.questTemp.Guardoftruth = "mayak_exit";
			GiveItem2Character(pchar, "specialletter");
			sld = ItemsFromID("specialletter");
			sld.text = "Letter_Vincento_next";
		break;
		
		case "guardoftruth_7":
			dialog.text = "�������. ������� �� ���, � ������� ������� ����.";
			link.l1 = "�� ���, �������! ����� �� ������� ������ ��� ��� ���������, ����� � � ���� ���������. � ������� �� ������ ���� �������� ����� � ����.";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			dialog.text = "�� ������! ��� ��� ������, ��� �� �� ��������?";
			link.l1 = "�������: ��� ������� ������, ��� ����������, � ��� � ����� � ���������... "+npchar.name+", �� �� ���� ���� ����������? ������� �� �������, ��� � ���� ������ ������� ����������� �������� � ����������, �� ���� �� ����� ����, ��� ����� ���� ��������?";
			link.l1.go = "guardoftruth_9";
		break;
		
		case "guardoftruth_9":
			dialog.text = "����� ���� ��������, ������... ��������� ������, � ������ ���� �������� � ����� ��������.";
			link.l1 = "������. �������� ������ �����!";
			link.l1.go = "guardoftruth_10";
		break;
		
		case "guardoftruth_10":
			DialogExit();
			pchar.questTemp.Guardoftruth = "mayak_wait";
			SetFunctionTimerCondition("GuardOT_MayakLastStage", 0, 0, 1, false);
		break;
		
		case "guardoftruth_11":
			dialog.text = "��� �������������� ������ ���, ������. �� ����������� � �������. ���, �� ������� ��� ��� ��� ������� - �������� �� ������, � ��� �� ����� ������ ��� �����������. �� ������, ��� �� ����� ������� ������ ���� ������ ���� �������, ����� ������� �� ������ ����� ������� ���������� ���.";
			link.l1 = "� �����. ��������� ���� - ������, ���������. �������, �������! ���������� ����������� � ����!";
			link.l1.go = "guardoftruth_12";
		break;
		
		case "guardoftruth_12":
			DialogExit();
			GiveItem2Character(pchar, "VerifyPaper");
			ChangeItemDescribe("VerifyPaper", "itmdescr_VincentoPaper");
			pchar.questTemp.Guardoftruth = "santiago";
			AddQuestRecord("Guardoftruth", "34");
			AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 400);//����������
			//GuardOT_SetPadreVincento();
	                                       DoQuestFunctionDelay("GuardOT_SetPadreVincento", 3.5);
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}