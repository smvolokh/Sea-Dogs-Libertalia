int SM_SailsAutorepairingSkipFrame = 0;

// Загрузились с сэйва
void SM_SailsAutorepairingOnLoad()
{
	if (CheckAttribute(pchar, "CSM.SailsAutorepairing"))
	{
		SetEventHandler("frame", "SM_SailsAutorepairingOnEnterFrame", 0);
	}
}

void SM_EnableSailsAutorepairing()
{
	pchar.CSM.SailsAutorepairing = true;
	pchar.CSM.MastNoFall = true;
	SetEventHandler("frame", "SM_SailsAutorepairingOnEnterFrame", 0);
	
	Log_info("Sails Autorepairing Enabled.");
}

void SM_DisableSailsAutorepairing()
{
	DeleteAttribute(pchar, "CSM.SailsAutorepairing");
	DeleteAttribute(pchar, "CSM.MastNoFall");
	DelEventHandler("frame", "SM_SailsAutorepairingOnEnterFrame");
	
	Log_info("Sails Autorepairing Disabled.");
}

void SM_SailsAutorepairingOnEnterFrame()
{	
	if (!bSeaActive) // если не в море то и не надо
		return;
	
	SM_SailsAutorepairingSkipFrame++;
	if (SM_SailsAutorepairingSkipFrame < 500)
		return;
	else
		SM_SailsAutorepairingSkipFrame = 0;
	
	SM_RepairSails();
}

void SM_RepairSails()
{
	if (sti(Pchar.Ship.Type) == SHIP_NOTUSED || Pchar.ship.SP >= 99) // чтоб не мучить (+ баг с 99% после починки)
		return;
	
	MakeSailDmg(1, 40.0); // так надо, хоть и бред
	
	ProcessSailRepair(pchar, 100.0);
}