//������� ������ ���
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":

	                 PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_WEITER_15_00.wav");
	                 dialog.text = "";
		link.l1 = "� ��� ��� ������ ������?";
		link.l1.go = "exit";

		if(CheckAttribute(pchar, "questTemp.GothicXsardas") && pchar.questTemp.GothicXsardas == "MonbarLineXsardas" && !CheckAttribute(npchar, "quest.MonbarLineXsardas"))
                                   {
                                    dialog.text = "�������-��! (���������) � ����� ���� ������� ������� ����.";
            	                  link.l1 = "...";
                                    link.l1.go = "Xsardas_hello";
       	                  }	
	
		break;
		
		case "exit_1":                            
	                                    DoQuestFunctionDelay("Xsardas_Dialog_exit_1", 2.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();			
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


		case "XsardasGothic":
			dialog.text = "";
			if (!CheckAttribute(npchar, "quest.Xsardas_161"))
			{
			link.l1 = "� ��� ����� ���� ���� ������?";
			link.l1.go = "Xsardas_161";
			}
			if (!CheckAttribute(npchar, "quest.Xsardas_163"))
			{
			link.l2 = "� ������ �������� ������ ������ ��� ���� ������!";
			link.l2.go = "Xsardas_163";
			}
			if (!CheckAttribute(npchar, "quest.Xsardas_170"))
			{
			link.l3 = "��� � ����� ����� ���������� �� �����?";
			link.l3.go = "Xsardas_170";
			}
			if (!CheckAttribute(npchar, "quest.Xsardas_172"))
			{
			link.l4 = "� ��� ��� ��������� �� ������?";
			link.l4.go = "Xsardas_172";
			}
			if (CheckAttribute(pchar, "questTemp.Gothic") && pchar.questTemp.Gothic == "Totemitems")
			{
			if (!CheckAttribute(npchar, "quest.Xsardas_90"))
			{
			link.l5 = "��� �� ������ ������� �� ���� ������� ��������?";
			link.l5.go = "Xsardas_90";
			}
                                                                        }	
			link.l10 = "�����.";
			link.l10.go = "Xsardas_100";
                                                       
		break;

////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_161":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_ARTEFAKT_15_00.wav");
			dialog.text = "";
			link.l1 = "� ��� ����� ���� ���� ������?";
			link.l1.go = "Xsardas_162";
	                                                AddComplexSelfExpToScill(100, 100, 100, 100);
	                                                AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		break;
		case "Xsardas_162":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_127", 0.1);
			npchar.quest.Xsardas_161 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 

////////////////////////////////////////////////////////////////////////////////////////////////
		case "Xsardas_163":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_00.wav");
			dialog.text = "";
			link.l1 = "� ������ �������� ������ ������ ��� ���� ������!";
			link.l1.go = "Xsardas_164";
		break;
		case "Xsardas_164":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_143", 0.1);
			npchar.quest.Xsardas_163 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Xsardas_165":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_02.wav");
			dialog.text = "";
			link.l1 = "� ������ ���� ��� ��������?";
			link.l1.go = "Xsardas_166";
		break; 
		case "Xsardas_166":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_145", 0.1);
			npchar.quest.Xsardas_165 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Xsardas_167":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_04.wav");
			dialog.text = "";
			link.l1 = "����������� ��� �� ���� � ��� �������������� ������ ���� ������, � ������ �������� ������, ��� ��� ������?";
			link.l1.go = "Xsardas_168";
		break; 
		case "Xsardas_168":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_147", 0.1);
			npchar.quest.Xsardas_167 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_170":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_EQUIPMENT_15_00.wav");
			dialog.text = "";
			link.l1 = "��� � ����� ����� ���������� �� �����?";
			link.l1.go = "Xsardas_171";
		break;
		case "Xsardas_171":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_149", 0.1);
			npchar.quest.Xsardas_170 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_172":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_KHORINIS_15_00.wav");
			dialog.text = "";
			link.l1 = "� ��� ��� ��������� �� ������?";
			link.l1.go = "Xsardas_173";
		break;
		case "Xsardas_173":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_153", 0.1);
			npchar.quest.Xsardas_172 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

	//---------------------------------------- ������ �������------------------------------------------------

		case "Xsardas":
                                                       PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_00.wav");	                                                
			dialog.text = "�������-��! (���������) � ����� ���� ������� ������� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_1";
		break;
		case "Xsardas_1":
                                                         PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_15_01.wav");	                                              
			dialog.text = "";
			link.l1 = "� �������� ���� ���, ��� ��� - �� �������� ��� ������ ��� ����� ������.";
			link.l1.go = "Xsardas_2";
		break;
		case "Xsardas_2":
                                                         PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_02.wav");	                                              
			dialog.text = "��, ��� � ����, ������ ����� ����� �������� ������������ ����� � ����, �� ������ �� ���� - �� ����� ������������ ���� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_3";
		break;
		case "Xsardas_3":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_03.wav");
			dialog.text = "";
			link.l1 = "�� �� ������ ���� � ��� ������ ���������� �������, � ������ ��� ������....!";
			link.l1.go = "Xsardas_4";
		break;
		case "Xsardas_4":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_04.wav");
			dialog.text = "��� ������ - �� ������� ���, �� ��� ���, �� �� � ����� ����� ���������� �����, ������� ����������� ������.";
			link.l1 = "";
			link.l1.go = "Xsardas_5";
		break;
		case "Xsardas_5":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_05.wav");
			dialog.text = "";
			link.l1 = "�� �������� �� �����!";
			link.l1.go = "Xsardas_6";
		break;
		case "Xsardas_6":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_06.wav");
			dialog.text = "� ������ � ������� ����� ������� ���������!";
			link.l1 = "";
			link.l1.go = "Xsardas_7";
		break;
		case "Xsardas_7":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_07.wav");
			dialog.text = "����� ��������� ������� ������ - ������ ����� � �������� ����� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_8";
		break;
		case "Xsardas_8":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_08.wav");
			dialog.text = "��� ��� ������ ���� ��������� ���� - ����� ���� �������� ��� ������� ������������.";
			link.l1 = "";
			link.l1.go = "Xsardas_9";
		break;
		case "Xsardas_9":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_09.wav");
			dialog.text = "��� ��������� �������� ���� - ����� � ��� ����� - ��� ���� �������...";
			link.l1 = "";
			link.l1.go = "Xsardas_10";
		break;
		case "Xsardas_10":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_10.wav");
			dialog.text = "";
			link.l1 = "(���������) �������!";
			link.l1.go = "Xsardas_11";
		break;
		case "Xsardas_11":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_11.wav");
			dialog.text = "��� �������� ������� ����, � �������� �� ����������� ���� �����.";
			link.l1 = "";
			link.l1.go = "Xsardas_12";
		break;
		case "Xsardas_12":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_12.wav");
			dialog.text = "� ��� ������� �� ���� ���� ����� ����� �� ������ �������.";
			link.l1 = "";
			link.l1.go = "Xsardas_13";
		break;
		case "Xsardas_13":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_13.wav");
			dialog.text = "";
			link.l1 = "� ��� ��� ����� ������?";
			link.l1.go = "Xsardas_14";
		break;
		case "Xsardas_14":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_14.wav");
			dialog.text = "������ ���� ����� ��������� �� ������ �� ���� - � ������ �������� ����� �������� � ��� ��������� � �����.";
			link.l1 = "";
			link.l1.go = "Xsardas_15";
		break;
		case "Xsardas_15":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_15.wav");
			dialog.text = "� ��� ����� ���� �������. �� ������ ����������!!!";
			link.l1 = "";
			link.l1.go = "Xsardas_16";
		break;
		case "Xsardas_16":
	                                    PlaySound("VOICE\Russian\gotica\GG\SVM_1_BERZERK.wav");
			DialogExit();
			DoQuestCheckDelay("Ascold_Xsardas_4", 5.0);
		break;





		case "Xsardas_010":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_18", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Xsardas_12":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_13.wav");
			dialog.text = "";
			link.l1 = "� ��� ��� ����� ������?";
			link.l1.go = "Xsardas_13";
		break;
		case "Xsardas_13":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_21", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Xsardas_14":
			dialog.text = "";
			if (!CheckAttribute(npchar, "quest.Xsardas_20"))
			{
			link.l1 = "��� �� ����� �������?";
			link.l1.go = "Xsardas_20";
			}
			if (!CheckAttribute(npchar, "quest.Xsardas_30"))
			{
			link.l2 = "����� ����� ��������� ������� �� ���� ����!";
			link.l2.go = "Xsardas_30";
			}
			if (!CheckAttribute(npchar, "quest.Xsardas_40"))
			{
			link.l3 = "��� ����� ������.";
			link.l3.go = "Xsardas_40";
			}
			link.l4 = "�����.";
			link.l4.go = "Xsardas_50";
		break;

		case "Xsardas_20":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_TODO_15_00.wav");
			dialog.text = "";
			link.l1 = "��� �� ����� �������?";
			link.l1.go = "Xsardas_21";
		break;
		case "Xsardas_21":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_24", 0.1);
			npchar.quest.Xsardas_20 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 

		case "Xsardas_30":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_AWAY_15_00.wav");
			dialog.text = "";
			link.l1 = "����� ����� ��������� ������� �� ���� ����!";
			link.l1.go = "Xsardas_31";
		break;

		case "Xsardas_31":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_30", 0.1);
			npchar.quest.Xsardas_30 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 

		case "Xsardas_40":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_WEAPON_15_00.wav");
			dialog.text = "";
			link.l1 = "��� ����� ������!";
			link.l1.go = "Xsardas_41";
		break;

		case "Xsardas_41":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_34", 0.1);
			npchar.quest.Xsardas_40 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 

		case "Xsardas_50":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_37", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 

		case "Xsardas_60":
			dialog.text = "";
			link.l1 = "� ��� ����� ���� ���� ������?";
			link.l1.go = "Xsardas_61";
			link.l2 = "� ������ �������� ������ ������ ��� ���� ������!";
			link.l2.go = "Xsardas_63";
			link.l3 = "��� � ����� ����� ���������� �� �����?";
			link.l3.go = "Xsardas_70";
			link.l4 = "� ��� ��� ��������� �� ������.";
			link.l4.go = "Xsardas_72";
			link.l5 = "� ���������� ����������� � ����!(�����)";
			link.l5.go = "Xsardas_75";
		break;
////////////////////////////////////////////////////////////////////////////////////////////////
		case "Xsardas_61":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_ARTEFAKT_15_00.wav");
			dialog.text = "";
			link.l1 = "� ��� ����� ���� ���� ������?";
			link.l1.go = "Xsardas_62";
		break;
		case "Xsardas_62":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_ARTEFAKT_14_01", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break; 
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_63":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_00.wav");
			dialog.text = "";
			link.l1 = "� ������ �������� ������ ������ ��� ���� ������!";
			link.l1.go = "Xsardas_64";
		break;
		case "Xsardas_64":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_43", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Xsardas_65":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_02.wav");
			dialog.text = "";
			link.l1 = "� ������ ���� ��� ��������?";
			link.l1.go = "Xsardas_66";
		break; 
		case "Xsardas_66":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_45", 2.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Xsardas_67":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_PALADIN_15_04.wav");
			dialog.text = "";
			link.l1 = "����������� ��� �� ���� � ��� �������������� ������ ���� ������, � ������ �������� ������, ��� ��� ������?";
			link.l1.go = "Xsardas_68";
		break; 
		case "Xsardas_68":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_47", 5.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_70":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_EQUIPMENT_15_00.wav");
			dialog.text = "";
			link.l1 = "��� � ����� ����� ���������� �� �����?";
			link.l1.go = "Xsardas_71";
		break;
		case "Xsardas_71":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_49", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////
		case "Xsardas_72":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_KHORINIS_15_00.wav");
			dialog.text = "";
			link.l1 = "� ��� ��� ��������� �� ������?";
			link.l1.go = "Xsardas_73";
		break;
		case "Xsardas_73":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_53", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_75":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_FIRSTEXIT_15_00.wav");
			dialog.text = "";
			link.l1 = "� ���������� ����������� � ����!";
			link.l1.go = "Xsardas_76";
			npchar.quest.Xsardas_75 = "true";
		break;
		case "Xsardas_76":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_56", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Xsardas_77":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_KDFSECRET_15_00.wav");
			dialog.text = "";
			link.l1 = "������ ���� ���� �� ������ ����� � ����.";
			link.l1.go = "Xsardas_78";
		break;
		case "Xsardas_78":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_59", 0.1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
////////////////////////////////////////////////////////////////////////////////////////////////

		case "Xsardas_90":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_STONEPLATE_15_00.wav");
			dialog.text = "";
			link.l1 = "��� �� ������ ������� �� ���� ������� ��������?";
			link.l1.go = "Xsardas_91";
		break;
		case "Xsardas_91":
	                                                DoQuestFunctionDelay("Xsardas_Dialog_91", 2.0);
			npchar.quest.Xsardas_90 = "true";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;






		case "Xsardas_100": 
 			DialogExit(); 
			NextDiag.CurrentNode = NextDiag.TempNode;
		                        chrDisableReloadToLocation = false;//������� �������
		                         LAi_SetBarmanType(sld);
	                                                 LAi_RemoveLoginTime(sld);
	                                                 sld = characterFromId("Xsardas");
                                                                         LAi_ActorGoToLocator(sld, "quest", "quest1", "Xsardas", -1.0);
	                                                DoQuestFunctionDelay("Gothic_END2", 20.0);                                                                                     		
		break;
							




		
		case "GothicTorus_fake_night":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_14_00.wav");
			dialog.text = "������� - ��, � � �� �����, ��� ��� � ����� ��������� ���������� �����!";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_1";
		break;

		case "GothicTorus_fake_night_1":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_15_01.wav");
			dialog.text = "";
			link.l1 = "� �������� ���� ���, ��� ����� ��� ������ �������� ��� ����� ������!";
			link.l1.go = "GothicTorus_fake_night_2";
		break;

		case "GothicTorus_fake_night_1":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_14_02.wav");
			dialog.text = "��� ��� � ����, �� ����� ������ ��������� ����� ����� ��������.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_2";
		break;

		case "GothicTorus_fake_night_2":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_14_03.wav");
			dialog.text = "� ��� ����� ���������, ��� �� ����� �������� ���� �� ����������� �����.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_3";
		break;

		case "GothicTorus_fake_night_3":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_14_04.wav");
			dialog.text = "�� ������ �� ���� ������ - �� �� �����!";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_4";
		break;

		case "GothicTorus_fake_night_4":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_14_05.wav");
			dialog.text = "� ��� ���� ������� ����� ������!";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_5";
		break;

		case "GothicTorus_fake_night_5":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_DMTSINDDA_15_01.wav");
			dialog.text = "";
			link.l1 = "��� ���� ����� ��������� �����?";
			link.l1.go = "GothicTorus_fake_night_6";
		break;

		case "GothicTorus_fake_night_6":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_DMTSINDDA_14_02.wav");
			dialog.text = "���� ����� ��� �� �������� �� ����� ���� � ��������� ��������� ������ ������.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_7";
		break;

		case "GothicTorus_fake_night_7":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_DMTSINDDA_14_03.wav");
		dialog.text = "�� ��������� ��� ������ ��� ��������� ��� ����� �� ���� � ������� �� �������� �����.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_8";
		break;

		case "GothicTorus_fake_night_8":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_DMTSINDDA_14_04.wav");
			dialog.text = "���� � ������ ��������, ����� ��� �� ��� �� ���� ������ ����� ����� �����, �� ������ ��� ���������� ������� ��������.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_9";
		break;

		case "GothicTorus_fake_night_9":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_ADD_15_00.wav");
			dialog.text = "";
			link.l1 = "� ��� ������ �� ������ ���������?";
			link.l1.go = "GothicTorus_fake_night_10";
		break;
		
		case "GothicTorus_fake_night_10":
			dialog.text = "���� ��� �� ����������, �� ������ ������ � ����� ���� �� ������.....";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_11";
		break;
		
		case "GothicTorus_fake_night_11":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_15.wav");
			dialog.text = "� ��� ����� ���� �������.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_exit";
		break;

		case "GothicTorus_fake_exit":
			AddDialogExitQuest("GothicTorus_fake_3");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "GothicLee_fake_night_Sound":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "Exit";
			NextDiag.TempNode = "GothicTorus_fake_night_Sound";
		break;


	//---------------------------------------- ������ �������------------------------------------------------

		case "Xsardas_hello":
                                                       PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_00.wav");	                                                
			dialog.text = "�������-��! (���������) � ����� ���� ������� ������� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_1";
		break;
		case "Xsardas_hello_1":
                                                         PlaySound("VOICE\Russian\gotica\XARDAS\DIA_ADDON_XARDAS_HELLO_15_01.wav");	                                              
			dialog.text = "";
			link.l1 = "� �������� ���� ���, ��� ��� - �� �������� ��� ������ ��� ����� ������.";
			link.l1.go = "Xsardas_hello_2";
		break;
		case "Xsardas_hello_2":
                                                         PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_02.wav");	                                              
			dialog.text = "��, ��� � ����, ������ ����� ����� �������� ������������ ����� � ����, �� ������ �� ���� - �� ����� ������������ ���� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_3";
		break;
		case "Xsardas_hello_3":
	                                                PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_03.wav");
			dialog.text = "";
			link.l1 = "�� �� ������ ���� � ��� ������ ���������� �������, � ������ ��� ������....!";
			link.l1.go = "Xsardas_hello_4";
		break;
		case "Xsardas_hello_4":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_04.wav");
			dialog.text = "��� ������ - �� ������� ���, �� ��� ���, �� �� � ����� ����� ���������� �����, ������� ����������� ������.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_5";
		break;
		case "Xsardas_hello_5":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_05.wav");
			dialog.text = "";
			link.l1 = "�� �������� �� �����!";
			link.l1.go = "Xsardas_hello_6";
		break;
		case "Xsardas_hello_6":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_06.wav");
			dialog.text = "� ������ � ������� ����� ������� ���������!";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_7";
		break;
		case "Xsardas_hello_7":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_07.wav");
			dialog.text = "����� ��������� ������� ������ - ������ ����� � �������� ����� ����.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_8";
		break;
		case "Xsardas_hello_8":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_08.wav");
			dialog.text = "��� ��� ������ ���� ��������� ���� - ����� ���� �������� ��� ������� ������������.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_9";
		break;
		case "Xsardas_hello_9":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_09.wav");
			dialog.text = "��� ��������� �������� ���� - ����� � ��� ����� - ��� ���� �������...";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_10";
		break;
		case "Xsardas_hello_10":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_10.wav");
			dialog.text = "";
			link.l1 = "(���������) �������!";
			link.l1.go = "Xsardas_hello_11";
		break;
		case "Xsardas_hello_11":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_11.wav");
			dialog.text = "��� �������� ������� ����, � �������� �� ����������� ���� �����.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_12";
		break;
		case "Xsardas_hello_12":
	                                    PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_12.wav");
			dialog.text = "� ��� ������� �� ���� ���� ����� ����� �� ������ �������.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_13";
		break;
		case "Xsardas_hello_13":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_15_13.wav");
			dialog.text = "";
			link.l1 = "� ��� ��� ����� ������?";
			link.l1.go = "Xsardas_hello_14";
		break;
		case "Xsardas_hello_14":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_14.wav");
			dialog.text = "������ ���� ����� ��������� �� ������ �� ���� - � ������ �������� ����� �������� � ��� ��������� � �����.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_15";
		break;
		case "Xsardas_hello_15":
	                                   PlaySound("VOICE\Russian\gotica\XARDAS\DIA_XARDAS_HELLO_14_15.wav");
			dialog.text = "� ��� ����� ���� �������.";
			link.l1 = "";
			link.l1.go = "Xsardas_hello_exit";
		break;

		case "Xsardas_hello_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.MonbarLineXsardas = "true";
		break;


		
	}
}