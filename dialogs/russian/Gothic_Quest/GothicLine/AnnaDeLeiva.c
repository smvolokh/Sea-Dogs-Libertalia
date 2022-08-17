
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	int i, iTemp;
                    float locx, locy, locz;
	string sTemp,sTemp1, str, str1;
	int	s1,s2,s3,s4,s5,p1,iColony;
	string attrName;
                    string attrLoc;
                    attrLoc   = Dialog.CurrentNode;
  
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\Isabella04.wav");
			dialog.text = "� ������� ����� ���������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";

			
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toAnna")// �����, ����� ���� � ����������
            {
    			dialog.text = "��� ������� ������� ��?";
    			link.l1 = "��, �����. ��� ���� ���� �����"+ GetSexPhrase("��","��") +"?";
    			link.l1.go = "Gothic_2_1";
            }

			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toHavana")
            {
    			dialog.text = "�������������, ������"+ GetSexPhrase("","���") +", ��� �� ������?";
    			link.l1 = "���� ������. �� � ��������� ���� �����, �� ������������, �����...";
    			link.l1.go = "exit";
            }
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_SeekHoseBrothers")
            {
    			dialog.text = "�������������, ������"+ GetSexPhrase("","���") +", ��� �� ������?";
    			link.l1 = "���� ������. �� � ��������� ���� �����, �� ������������, �����...";
    			link.l1.go = "exit";
            }

			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork")// �����, ����� ���� ����� ���������� ������
            {
				dialog.text = NPCStringReactionRepeat("������"+ GetSexPhrase("","���") +", �� ��� ������ ��� �������� ��� �����. ������, ��� � ���� ���� �� ������ ������� �����.",
					         "������������ �����, �������. ���� ��� ������.", "� ��� ��� ������������ �������...", "������� ��� �� ���: ������������, �������...", "block", 0, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������, ���������� �������� ���� ������ ��� ����������� ��� ����������� ���������, � ����� �� ��, ��� ��� � ��� ����������... �� ����� ������, ����� ����, ��� ������ � ��� ������� �������� � ��������.", 
					      "� � ��� ���"+ GetSexPhrase("","�") +" ������ ��� ��.", "� ��� ��� � ���"+ GetSexPhrase("","�") +" ��� ������...", "������������, �������...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("Gothic_2_8", "none", "none", "none", npchar, Dialog.CurrentNode);

            }
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "empty")// �����, ����� ���� ����� ���������� ������
            {
				dialog.text = NPCStringReactionRepeat("������"+ GetSexPhrase("","���") +", �� ��� ������ ��� �������� ��� �����. ������, ��� � ���� ���� �� ������ ������� �����.",
					         "������������ �����, �������. ���� ��� ������.", "� ��� ��� ������������ �������...", "������� ��� �� ���: ������������, �������...", "block", 0, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������, ���������� �������� ���� ������ ��� ����������� ��� ����������� ���������, � ����� �� ��, ��� ��� � ��� ����������... �� ����� ������, ����� ����, ��� ������ � ��� ������� �������� � ��������.", 
					      "� � ��� ���"+ GetSexPhrase("","�") +" ������ ��� ��.", "� ��� ��� � ���"+ GetSexPhrase("","�") +" ��� ������...", "������������, �������...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("Gothic_2_8", "none", "none", "none", npchar, Dialog.CurrentNode);
            }

		break;
		
		case "AnnaDeLeiva":
	                                               PlaySound("VOICE\Russian\Isabella02.wav");
				dialog.text = "���� ��������� �������, ������� ��� �� �������� � ���� ��������. � ���� �� ���� ��� ��� �������������?";
				link.l1 = "��, �� �� ����� ���� �� �������� �� ����, ��� �������?";
				link.l1.go = "AnnaDeLeivaSex";
				link.l2 = "������, �� �����, � ������ ����� ������ ������� �����...";
				link.l2.go = "exit1";
				break;

		case "exit1":
				dialog.text = "�� ����� �����������?";
				link.l1 = "�, ��...";
				link.l1.go = "exit";
				break;				
								
		case "AnnaDeLeivaSex":
 	                                PlaySound("VOICE\Russian\gotica\GG\YES_00.wav");
			dialog.text = "�� �� � ���, � ��� ��...? ������ ����� ������ �� ������, ���� �� �� ������?";
			link.l1 = "��...! �� ��� �� �� ��� ��� ��������.";
			link.l1.go = "AnnaDeLeivaSex_Yes";
		break;

        case "AnnaDeLeivaSex_Yes":
			sld = CharacterFromID("AnnaDeLeiva");
			LAi_SetActorType(sld);
			LAi_ActorTurnToCharacter(sld, pchar);
            pchar.GenQuest.BrothelCount = 0;
            AddCharacterExpToSkill(pchar, "Leadership", 100);
            AddCharacterExpToSkill(pchar, "Fencing", -50);// ��������
            AddCharacterExpToSkill(pchar, "Pistol", -50);
            AddCharacterHealth(pchar, 10);
            ChangeCharacterComplexReputation(pchar, "nobility", 1);

   			AddDialogExitQuest("PlaySex_1");
			NextDiag.CurrentNode = "AnnaDeLeivaLife_afterSex";
			DialogExit();
        break;


        case "AnnaDeLeivaLife_afterSex":
			dialog.text = "�...� ��, �����, �.... ������ �� � �������?";
			link.l1 = "��������?";
			link.l1.go = "exit";
        break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

//********************************* ��������� ����� ����. ����� �3 **********************************

 		case "AnnaDeLeiva_TakeAnna":
    			dialog.text = "����! ��� ���������? �� ������� �� �������� ��? ��� ��� ��� �� ���?";
    			link.l1 = "��������, �� ����, ��������� ��� ��� ��� ������� ��� ���, �� � ��������"+ GetSexPhrase("","�") +" ���"+ GetSexPhrase("","�") +" ����� ������ �������. � ��� ��� ������� �� ����������� � ��������, ����� ���������� ������! ������� �� � ����-��� ���� ���.";
    			link.l1.go = "Gothic_1";
		break;

 		case "Gothic_1":
			dialog.text = "���� �����... ����� �������, � ����� �� ������... �� ����� ������, ������� � ������ ���, � ����� ���� �����...";
			link.l1 = "� ����, �������, �������"+ GetSexPhrase("��","���") +"... � ����� ��� ��������� �� ����. ������ �����������, ��������...";
			link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_HavanaOut";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1 = "location";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1.location = "Cuba2";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition = "GothicLeeTakeAnna_DelivShip";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

 		case "Gothic_2_1":
			dialog.text = "� �������� ������ �� ������ �� ���� ������� ���� �� ��� �������. �������-���������� ������ ���������� ������������� ������ ����� ���� � �������, ��� � ���� ������� �. ��, ��� ��� � ����! �� ��� ���������������� ��������� �����, ��� ������ ������ ��� ���������, � � �� ����, ��� ��������.\n"+
				          "�����"+ GetSexPhrase("�","���") +", � ����� ��� ����������� � ������ � ��������, ��������� ��� ��������.";
			link.l1 = "�����, �� ������ ������������ �� ����.";
    		link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_toHavana";
			AddQuestRecord("GothicLee_2_KillAnnaHanters", "2");			
			sld = GetCharacter(NPC_GenerateCharacter("InesDeLasCierras", "Womens_8", "woman", "woman", 10, SPAIN, -1, false, "soldier"));
			sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_2.c";
			sld.name = "����";
			sld.lastname = "�� ��� �������";
			sld.greeting = "";
			LAi_SetCitizenType(sld);
		                     LocatorReloadEnterDisable("Havana_houseSp2", "reload3", true);
			ChangeCharacterAddressGroup(sld, "Havana_houseSp2", "goto","goto2");
		break;

 		case "Gothic_2_8":
			dialog.text = "�� ������ ���� ��������� � �� � ������������� ����������.";
			link.l1 = "��� ������ ����� �� ������, �������� ���. � �����"+ GetSexPhrase("","�") +" ����������� ���� ������� ����������...";
    		link.l1.go = "Gothic_2_9";
		break;
 		case "Gothic_2_9":
			dialog.text = "��, ������"+ GetSexPhrase("","���") +" " + pchar.name + ", ��� � ���� ������������� ���?";
			link.l1 = "����� ����, � ����� ��� ���������� � �������� ��, �� ���� �����������.";
    		link.l1.go = "Gothic_2_10";
			link.l2 = "����� ����, �� ����� ��������������, ����� ��������� �� ������.";
    		link.l2.go = "AnnaDeLeivaSex_2";
		break;
 		case "Gothic_2_10":
			dialog.text = "���������� ������� ���� �������, � �������� �������� �� �� ������ ����� �� ����������.";
			link.l1 = "�����, �� ������� ���� ������������ �������� ������. �������, �� � �������.";
    		link.l1.go = "exit";
		//npchar.LifeDay = 0;
		break;

		case "AnnaDeLeivaSex_2":
 	                     PlaySound("VOICE\Russian\gotica\GG\YES_00.wav");
		dialog.text = "� �� ���� �� ��� ������� �� ��� ������...? ������, � ��������� ��� � ���� �� �� ������?";
			link.l1 = "��, ����������, ��� �� �� ��� �� �����.";
			link.l1.go = "AnnaDeLeivaSex_Yes";
		break;


	}
}