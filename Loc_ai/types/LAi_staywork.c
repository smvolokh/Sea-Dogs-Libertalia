//Made by MAXIMUS from LAi_Sit.c//
/*
���: �������, ������ ����� � ��������, �������� �� �������, ������� �� ������

	������������ �������:
		stay
		dialog
*/



#define LAI_TYPE_STAYWORK		"staywork"


//�������������
void LAi_type_staywork_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	bool isNew = false;
                   string actionStaywork;
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		isNew = true;
	}else{
		if(chr.chr_ai.type != LAI_TYPE_STAYWORK) isNew = true;
	}
	if(isNew == true)
	{
	else
	{
		chr.chr_ai.tmpl.animation = actionStaywork;
	}

	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_STAYWORK;
	//��������� �������� ���������
	if(actionStaywork == "Barman_idle") SendMessage(chr, "lslss", MSG_CHARACTER_EX_MSG, "TieItem", 10, "HandsItems\topor_015", "Saber_hand");

	}
	//��������� �������� ���������
                    LAi_SetDefaultStayworkAnimation(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);

}

//��������������� ���� ���������
void LAi_type_staywork_CharacterUpdate(aref chr, float dltTime)
{
	string snd = "male-citizen";
	if(CheckAttribute(chr,"sex") && chr.sex=="woman") snd = "female-citizen";
	if(CheckAttribute(chr,"worklocator"))
	{
		if(HasSubStr(chr.worklocator,"wheel")) snd = "OBJECTS\wheel.wav";
		if(HasSubStr(chr.worklocator,"cannon"))
		{
			switch(Rand(2))
			{
				case 0: snd = "AMBIENT\TOWN\knife.wav"; break;
				case 1: snd = "AMBIENT\TAVERN\drop"+sti(Rand(3)+3)+".wav"; break;
				case 2: snd = "PEOPLE\step_iron.wav"; break;
			}
			if(FindNearCharacters(chr, 2.5, -1.0, 30.0, 0.1, false, false)>0) LAi_CharacterPlaySound(chr, snd);
		}
		CharacterTurnByLoc(chr, chr.worklocator.group, chr.worklocator);
	}
	if(rand(300)==123) { LAi_CharacterPlaySound(chr, snd); }
	else
	{
		if(FindNearCharacters(chr, 2.5, -1.0, 30.0, 0.1, false, false)>0)
		{
			if(rand(100)==10) { LAi_CharacterPlaySound(chr, snd); }
		}
	}
}

//�������� ��������� � �������
bool LAi_type_staywork_CharacterLogin(aref chr)
{
	return true;
}

//�������� ��������� �� �������
bool LAi_type_staywork_CharacterLogoff(aref chr)
{
	return true;
}

//���������� ������ ���������
void LAi_type_staywork_TemplateComplite(aref chr, string tmpl)
{
	LAi_tmpl_player_InitTemplate(chr);
}

//�������� � ������� ������� ������
void LAi_type_staywork_NeedDialog(aref chr, aref by)
{
}

//������ �� ������, ���� ���������� true �� � ���� ������ ����� ������ ������
bool LAi_type_staywork_CanDialog(aref chr, aref by)
{
	//���� ��� �������, �� �������
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG) return false;
	//���������� �� ������
	return true;
}

//������ ������
void LAi_type_staywork_StartDialog(aref chr, aref by)
{
	//���� �� �������, ��������� ������ ��� ������� ����������
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_tmpl_SetActivatedDialog(chr, by);
	LAi_tmpl_dialog_NoAni(chr);
}

//��������� ������
void LAi_type_staywork_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
}

//�������� �������� ������� ���������
void LAi_type_staywork_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//�������� �������� ������������������ ���������
void LAi_type_staywork_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//�������� ���������
void LAi_type_staywork_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


//�������� ��������
void LAi_type_staywork_Attacked(aref chr, aref by)
{
	
}