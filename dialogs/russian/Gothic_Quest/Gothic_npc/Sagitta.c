// ������� ������ 
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
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
                                      case "First time":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_17_01.wav");
			dialog.text = "������, ��� ���� ����� �� ���� � ����� � ������?";
			link.l1 = "������.";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicSagitta") && pchar.questTemp.GothicSagitta == "Delivery" && !CheckAttribute(npchar, "quest.Delivery"))
			{
				link.l1 = "�� ����� ������ ����!";
				link.l1.go = "Sagitta_hallo_1";
			}
		break;
		
		
		case "Sagitta_hallo_1":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ����� ������ ����!";
			link.l1.go = "Sagitta_hallo_2";
		break;

		case "Sagitta_hallo_2":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WAS_17_01.wav");
			dialog.text = "� ���� �����, �������, ������� ���� ����� � ��������� �������.";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_3";
		break;

		case "Sagitta_hallo_3":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WAS_17_02.wav");
			dialog.text = "��� ��� ����, �� ��� ��� ��, ��� �����.";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_4";
		break;

		case "Sagitta_hallo_4":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_15_00.wav");
			dialog.text = "";
			link.l1 = "��� ��?";
			link.l1.go = "Sagitta_hallo_5";
		break;

		case "Sagitta_hallo_5":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_01.wav");
			dialog.text = "��, ��� ������� �� ������ ��� ���!!!";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_6";
		break;

		case "Sagitta_hallo_6":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_02.wav");
			dialog.text = "���� �������� ������� ������������� � ��� ��������!";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_7";
		break;

		case "Sagitta_hallo_7":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_03.wav");
			dialog.text = "�� ����� �� �����, ��� ���������� ���������� ������, ������ ������� � � �������� �����.";
			link.l1 = "";
			link.l1.go = "Sagitta_Thekla";
		break;

		case "Sagitta_Thekla":
			dialog.text = "";
			link.l1 = "� ���� ��� ���� ������� �� Ҹ���, ��������� �����.";
			link.l1.go = "Sagitta_Thekla_1";
		break;

		case "Sagitta_Thekla_1":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_THEKLA_17_01.wav");
			dialog.text = "��, �� ������ - �� � ������� � ��� ��������� ���� �����!";
			link.l1 = "�������.";
			link.l1.go = "Sagitta_Thekla_2";
		break;

		case "Sagitta_Thekla_2":
			PlaySound("interface\important_item.wav");
		                   RemoveItems(PChar, "tailor_tool", 1);
			dialog.text = "�� ������ ������� ���� ������, ��� ���������� �������� ��������� ���� �������!";
			link.l1 = "� ��� �� ��������, � ��� ��� ������.";
			link.l1.go = "Sagitta_Thekla_3";
		break;

		case "Sagitta_Thekla_3":
			dialog.text = "�� � ��� � ���� �� ����, ������� ������ �� ������ �� ������� �������� ������ ������ �� ����� �������� ���������� ������� ����\n ������ �� ������ �����, ���� ������� ����� � ���� ������� ������ ���, ��� ��� � �������� ������� ��� �������� � ������� ������� � ��� �������� ����� ���������, ����� ��� ����� ������� ������� ��� ��������\n������� � � ���� � ����� ������� �������� ��������, � ������ �������, ���� ��� ���� ���� ��������������, �� ��������� ���� �������.";
                                                         link.l1 = "�� �� ����, �� ��������� ����, ������� ���� � �������, ��� - �� � ��� - �� �� ����� �������� �� ����� ������.";
                                                        link.l1.go = "Sagitta_Thekla_exit";
                                                         link.l2 = "��... �������, � �������� ���� ������� � ������ � �����.";
                                                        link.l2.go = "Sagitta_Thekla_4";
		break;

		case "Sagitta_Thekla_exit":
                                      chrDisableReloadToLocation = false;//������� �������
	                   PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_TEACHALCHEMYREQUEST_NEIN_17_01.wav");
		dialog.text = "����� ������ ������� �� ����� �� ������ ������...";
		link.l1 = "...";
		link.l1.go = "exit";			
		npchar.quest.Delivery = "true";
		AddQuestRecord("Delivery", "2_1");
	                   AddDialogExitQuestFunction("No_StartSagitta");
		break;

		case "Sagitta_Thekla_4": 
                                      chrDisableReloadToLocation = false;//������� �������
	                   PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_TEACHALCHEMYREQUEST_WO_JA_17_01.wav");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		TakeNItems(pchar, "PortmansBook", 1);
		Log_Info("�� �������� ������� ������");
		PlaySound("interface\important_item.wav");	
		npchar.quest.Delivery = "true";
		AddQuestRecord("Delivery", "2");
	                   AddDialogExitQuestFunction("GothicDelivery");
		break;


		case "Smithy_SagittaAnn":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "���� �� ������ �� ����!";
			link.l1 = "��������� �������, �� ��� �������, ����� �� ������ ������������. ��� ��� �������?";
			link.l1.go = "SagittaAnn_1";
		break;
		
		case "SagittaAnn_1":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "�� �������, �� � ��� �� ����, ����� �������������� ���, � �� ����!!!";
			link.l1 = "��� ����! � ��� ������!!!";
			link.l1.go = "SagittaAnn_2";
		break;

		case "SagittaAnn_2":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "�� ������, �������� - ������!!!";
			link.l1 = "...";
			link.l1.go = "SagittaAnn_3";
		break;

		case "SagittaAnn_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuestFunction("Gothic_SagittaAnn_3");
		break;








		
		case "Sagitta_2":
			dialog.text = "��, ����� ������ � ����, ��� �� ��� �������� ��������, � ������� ������ ����. �����, �� ������ ���������� ������� ��������, � ������ ������ ���� � ���������� ���� �� ������ ���. ��� ���� ���������?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "��� ���, ������.";
				link.l1.go = "Sagitta_3";
			}
			else
			{
				link.l1 = "��...";
				link.l1.go = "Sagitta_exit";
			}
		break;
		
		case "Sagitta_exit":
			dialog.text = "��, � ��� �� ��� ��� ��������� ��������? ��� � ���� ���������. ��� ��� ����� ������, ������, ���� � �� ������������. �������� �������.";
			link.l1 = "��...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Sagitta_wait";
		break;
		
		case "Sagitta_wait":
			dialog.text = "����� ��? �� ������ �� �����, ������...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "�� �������, �������. � ������� ��� � ������ �� ���-�� �������. ���, � ������ ���������. ������.";
				link.l1.go = "Sagitta_3";
			}
			else
			{
				link.l1 = "...";
				link.l1.go = "Sagitta_exit";
			}
			NextDiag.TempNode = "Sagitta_wait";
		break;
		
		case "Sagitta_3":
			dialog.text = "���... ������, �� ���-���� ���-�� ������. � �� ������, ����� � ���������� ���� ������� ����� ����� �� ����� ��������?";
			link.l1 = "������ ���. ��, �������, �� ���������, � �������...";
			link.l1.go = "Sagitta_4";
		break;
		
		case "Sagitta_4":
			dialog.text = "��� �� �� ����� �� �������, �������! �� ����� �� ������ �� �����. �� ��� ��, � �� ������ ���������� �������� � ���������, ������� ��� �� ���� ������, � ������� �� ��������� ��� ������ �������� �� ���������� ������...";
			link.l1 = "�������, ����� ��� ��� �����������, �������� ���� ���� �� � ����� ������ - ��� �� ����� ���������� �� ���������?";
			link.l1.go = "Sagitta_5";
		break;
		
		case "Sagitta_5":
			dialog.text = "�����������, ������, �� � ����� �� �����. � �������� ���� - � �� ������, ������ �� �������, ��� ���. �� �� ����� ������ � ���� ���� �� �����������, ���, �� �� �����. ��� �� �������� ������ �������: �� ��������� ���������� �����, �������������� �� ���������� �����������. ��� ����� ������� ���� ����� �������, ���������� � �������, ���� ������� ����������� ����������� �� ���� ����.";
			link.l1 = "����� ���������! ������ ���� ����.";
			link.l1.go = "Sagitta_6";
		break;
		
		case "Sagitta_6":
			dialog.text = "� ���� ������� ���� �������� ���� �����. �� ������ ������ � ����� ���� ������� ��������� � ������ ������� �����.";
			link.l1 = "�������� �� ���� ���� ������ ��������� - ��� ������ ������?";
			link.l1.go = "Sagitta_7";
		break;
		
		case "Sagitta_7":
			dialog.text = "����� ���������� ����� �����, �� ������ ������� �������� �������. �������� ���� ����� ��������� � �������������� �������������� ����� �����\n������ ����� ������� ���� ���� � ������������. �� ����������� ������, ������ �������� ������������� ������ � ��� � ���������� ������ ��������\n������ ����� ����� ���� ��������, ��������, ������������, � ����� ������� �����\n������ ����� �������� � ���� ������� ������� � �������, �� ����� ������. ������ ��� ����� ������� ���� �������, ����������� � ���� � ������� ����� ���������\n����� ��� ����� �� ��������� ������������ ������ �� ��������. ����������� �� ������� ������ �� ������, � �� ������, ��� ���������� �������� ����������� - � ��������� ������ �� ������ �� ����� �������, �� �������� - �������� ����������\n�� ���, �������, �� ����� �������� ���� ����� ������, ��� ���� ����� ����� �� �����������?";
			if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
			{
				link.l1 = "��, � �����.";
				link.l1.go = "Sagitta_8";
			}
			link.l2 = "� ���� ������� ��������. ��� ��������� �������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Sagitta_next";
		break;
		
		case "Sagitta_next":
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "�-�, ��� ��, �������! �� ���, �������� ���� ��� �����?";
				link.l1 = "���� �����, �������. ������� ����!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�-�, ��� ��! �� ������ ������ � ���� �������� ����� �� ���������, ���?";
				if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
				{
					link.l1 = "������. �� ���� � � ������.";
					link.l1.go = "Sagitta_8";
				}
				link.l2 = "���� ���, �������. ������ �������� ���������.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "Sagitta_next";
		break;
		
		case "Sagitta_8":
			dialog.text = "����� ������. ����� ������ �� ������ ����������?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "������ ����� ���� � ������������.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "������ ����� �������� � ������������.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "������ ������������ �����.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "������. � ������� ��� '���� ������'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, �������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "������. � ������� ��� '�����'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, �������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "������. � ������� ��� '����� ����'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, �������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "Sagitta_next";
			RemoveItems(pchar, "gold_dublon", 300);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("�� ������ 300 �������� � ������� ���������");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;


	}
} 



