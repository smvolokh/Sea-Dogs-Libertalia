
/*
	CheatSurfMenu by Cheatsurfer �� 07.01.2018 ��� ��� 1.6.0 (18.12.17)
	������� �������
*/

int iSNDc = 0;

// ��������� ��������, ���������� HP � �������, �������� ����������, ������������ ������ ��� �� � ��� ������������
void CSMHotKeyF4()
{
	ref sld;
	int io, ion;
	ClearAllLogStrings();
	if (stf(pchar.health.Hp) < stf(pchar.health.MaxHp))
	{
		pchar.health.Hp = stf(pchar.health.MaxHp);
		Log_info("�������� ����������� ��������!");
	}
	else
	{
		Log_info("��������� �������� � ������ �������!");
	}
	if ((stf(pchar.chr_ai.hp) < stf(pchar.chr_ai.hp_max)) || (stf(pchar.chr_ai.energy) < stf(pchar.chr_ai.energyMax)))
	{
		LAi_SetCurHPMax(pchar);
		Log_info("HP � ������� ����������!");
	}
	else
	{
		Log_info("HP � ������� � �����!");
	}
	if (CheckAttribute(pchar, "chr_ai.poison"))
	{
		DeleteAttribute(pchar, "chr_ai.poison");
		Log_info("���������� ��������!");
	}
	else
	{
		Log_info("���������� ���!");
	}
	if (GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE) != "")
	{
		if(stf(pchar.chr_ai.charge) < stf(pchar.chr_ai.charge_max))
		{
			pchar.chr_ai.charge = stf(pchar.chr_ai.charge_max);
			Log_info("������������� ������ ������������!");
		}
		else
		{
			Log_info("����������� �������������� ������ �� ���������.");
		}
	}
	else
	{
		Log_info("������������� ������ �� ������������.");
	}
	for (io = 1; io <= 3; io++)
	{
		ion = GetOfficersIndex(pchar, io);
		if (ion < 0) continue;
		sld = GetCharacter(ion);
		LAi_SetCurHPMax(sld);
		if (GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE) != "")
		{
			sld.chr_ai.charge = stf(sld.chr_ai.charge_max);
		}
	}
	if (iSNDc != 0)
	{
		StopSound(iSNDc, 0);
	}
	iSNDc = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Statistic_AddValue(PChar, "Cheats.F4", 1);
}

// ����� ���������� ������������ �����
void CSMHotKeyF5()
{
	ClearAllLogStrings();
	if (!IsEntity(loadedLocation))
	{
		Log_info("����� ��� �� ��������!");
		return;
	}
	ref rXep;
	int i, iXep;
	int iXeps = FindNearCharacters(pchar, 50, -1.0, -1.0, 0.001, false, true);
	string sXep;
	bool bTarget = false;
	for (i = 0; i < iXeps; i++)
	{
		if (!CheckAttribute(chrFindNearCharacters[i], "index"))
		{
			break;
		}
		iXep = sti(chrFindNearCharacters[i].index);
		rXep = GetCharacter(iXep);
		if (LAi_IsImmortal(rXep) || !LAi_group_IsEnemy(pchar, rXep) || CheckAttribute(rXep, "chr_ai.hpchecker") || GetCharacterEquipByGroup(rXep, BLADE_ITEM_TYPE) == "" || rXep.chr_ai.type == LAI_TYPE_CARRY)
		{
			continue;
		}
		sXep = GetFullName(rXep);
		LAi_KillCharacter(rXep);
		bTarget = true;
		Log_Info("" + sXep + " " + NPCharSexPhrase(rXep, "��� ����!", "���� �����!"));
		if (iSNDc != 0)
		{
			StopSound(iSNDc, 0);
		}
		iSNDc = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
		break;
	}
	if (!bTarget)
	{
		Log_info("�� ���� ����� ���������� ������!");
		if (iSNDc != 0)
		{
			StopSound(iSNDc, 0);
		}
		iSNDc = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	Statistic_AddValue(PChar, "Cheats.F5", 1);
}

// ������ / �������� HUD
void CSMHotKeyF7()
{
	ClearAllLogStrings();
	ChangeShowIntarface();
	Statistic_AddValue(PChar, "Cheats.F7", 1);
}
