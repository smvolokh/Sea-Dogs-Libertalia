
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Waitress.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
            NextDiag.TempNode = "First time";
	PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_" + rand(37) + ".wav");
			
		    switch (Rand(4))
			{
				case 0:
					dialog.text = "������, ������" + GetSexPhrase("���","���") + ", � ������. ������� ���� ��� ������� - �� ������ ������� ���� ��� ���������!";
					link.l1 = "...";
					link.l1.go = "exit";
				break;

				case 1:
					dialog.text = "����������, �������, �� ����������� �������! ����� ��� ��� ������ �������� �������!";
					link.l1 = "���... ����� � �� �������" + GetSexPhrase("��","���") + ".";
					link.l1.go = "exit";
				break;

				case 2:
								dialog.text = "�, �������! �� ������ �� ������� � ��� ������� �������? � �� ����� ����������, �� ...";
					link.l1 = "���, ������ � �����! ����� � ������ ���!";					link.l1.go = "exit";
				break;

				case 3:
					dialog.text = "���� �� ������ ���-���� �������� - ����������, ����������, � �������. �� ����� �� �������.";
					link.l1 = "������� �� �����.";
					link.l1.go = "exit";
				break;

				case 4:
					dialog.text = "���� �� ������ ��� ������� ��������� � ��������� �������� - ������� ������� �� ����. ������� � ����� ���� ���� �� �������� ��� ���.";
					link.l1 = "���������.";
					link.l1.go = "exit";
				break;
			}			
		break;
	}
}
 
