// ������ �����������, ������ � ���������� ������ LSC
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
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
//------------------------------------- ����� ������ �������� --------------------------------------------
		case "Narval_warning":

		dialog.text = LinkRandPhrase("������, ���������, ����� ��� ����� ������� ����! � ������!","���� �� ����������! � ���!","�� ��, ��������! ������ �� ���� ������� ������� �������!");
		link.l1 = "�-���!";
		link.l1.go = "check_fight";
		break;

		case "check_fight":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			LAi_group_MoveCharacter(NPChar, "PearlGroup_1");
			LAi_group_Attack(NPChar, Pchar);
		break;

				
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}