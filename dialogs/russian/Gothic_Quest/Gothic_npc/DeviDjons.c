//����� �������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	string sName = GetName(PChar, "f");
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "� �������, � �������?";
			link.l1 = "��, �� ��� �� ������� �� ����?";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;

		case "DeviDjons_1":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_3.wav");
			dialog.text = "�� ������ ������� ������?";
			link.l1 = "";
			link.l1.go = "DeviDjons_2";
		break;


		case "DeviDjons_2":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_4.wav");
			dialog.text = "�� ���������� ���� ������ � ������ ��� �� ����� �� ������� ����� ����.";
			link.l1 = "";
			link.l1.go = "DeviDjons_3";
		break;

		case "DeviDjons_3":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_6.wav");
			dialog.text = "������ �� ���������������� ��� �������� ����� ������� ������� ����� �������.";
			link.l1 = "";
			link.l1.go = "DeviDjons_4";
		break;

		case "DeviDjons_4":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_5.wav");
			dialog.text = "���������� ���� ����!";
			link.l1 = "";
			link.l1.go = "DeviDjons_5";
		break;

		case "DeviDjons_5":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_7.wav");
			dialog.text = "���� �� ��� �� ��������!";
			link.l1 = "";
			link.l1.go = "DeviDjons_6";
		break;
		
		case "DeviDjons_6":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_8.wav");
			dialog.text = "�� ����� ����. �� ������ ������?";
			link.l1 = "����_�����?";
			link.l1.go = "DeviDjons_7";
			link.l2 = "� ������� " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+" ��������, ������ �������. � �� ���� �� �����!";
			link.l2.go = "DeviDjons_8";
		break;

		case "DeviDjons_7":
			DialogExit();
	                                                PlaySound("Ambient\CAVE\MYSTERY_07.wav");			
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			pchar.GenQuest.CannotWait = true;//������ ��������
			for (i=1; i<=3; i++)
			{
				sld = characterFromId("Vater_skeletcap_"+i);
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "TMP_FRIEND");
				LAi_ActorRunToLocation(sld, "box", "box1", "none", "", "", "OpenTheDoors", -1);
			}			
					
		break;

		case "DeviDjons_8":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_9.wav");
			dialog.text = "�� �������, ����� ������ � ������������?";
			link.l1 = "���� �� �������, ������� �����?";
			link.l1.go = "DeviDjons_9";			
		break;

		case "DeviDjons_9": 
			DialogExit();
			AddDialogExitQuestFunction("Vater_skel_ShoreFight");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		

		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}