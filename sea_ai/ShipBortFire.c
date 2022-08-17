void Ship_BortFire()
{
	float	dx, dy, dz, d2x, d2y, d2z;
	float	ax = 0.0;
	float 	az = 0.0;
	float   vz = 0.0;
	aref	firedShip;
	string	bortName;
	ref rCharacter = GetCharacter(GetEventData());
	firedShip = GetEventData();
	bortName = GetEventData();
	dx = GetEventData();
	dy = GetEventData();
	dz = GetEventData();
	d2x = GetEventData();
	d2y = GetEventData();
	d2z = GetEventData();
    // boal fix charge 29.11.03 -->
    if (bortName == "cannonr" || bortName == "cannonl")
    { // ������ ��� ������ ���������.
        rCharacter.BOAL_ReadyCharge = "0";
    }
    //Log_SetStringToLog("Ship_BortFire " + rCharacter.id + " "+ bortName);
	// boal fix charge 29.11.03 <--
	
	// boal  05.12.03 check skill -->
	bool  bTempNotEnoughBalls = false;
	if (sti(rCharacter.index) == GetMainCharacterIndex())
	{
		ballNumber = 0;
        bTempNotEnoughBalls = bNotEnoughBalls;
	}
	bool bOfficer;
	bOfficer = (sti(rCharacter.index) == GetMainCharacterIndex()) || CheckAttribute(rCharacter, "Payment"); // ������ IsCompanion(rCharacter) ������ ��� ����� � ���� ��
	if (bDisableMapEnter && bOfficer && !bTempNotEnoughBalls) // use only in battle
	{
        if (bortName == "cannonr" || bortName == "cannonl")
        {
            AddCharacterExpToSkill(rCharacter, "Cannons", 3);
            ChangeCrewExp(rCharacter, "Cannoners", AIShip_isPerksUse(CheckCharacterPerk(rCharacter, "SeaWolf"), 0.28, 0.56));
        }
        else
        {
            AddCharacterExpToSkill(rCharacter, "Cannons", 1);
            ChangeCrewExp(rCharacter, "Cannoners", AIShip_isPerksUse(CheckCharacterPerk(rCharacter, "SeaWolf"), 0.1, 0.2));
        }
        //AddCharacterExpToSkill(rCharacter, "Accuracy", 1);
    }
    else
    {
    	if (bortName == "cannonr" || bortName == "cannonl")
        {
            ChangeCrewExp(rCharacter, "Cannoners", AIShip_isPerksUse(CheckCharacterPerk(rCharacter, "SeaWolf"), 0.08, 0.16));
        }
        else
        {
            ChangeCrewExp(rCharacter, "Cannoners", AIShip_isPerksUse(CheckCharacterPerk(rCharacter, "SeaWolf"), 0.03, 0.06));
        }
    }
    // boal <--

	SendMessage(&SeaOperator, "lisffffff", MSG_SEA_OPERATOR_FIRE, firedShip, bortName, dx, dy, dz, d2x, d2y, d2z);
/*	
	SetHeel_XZ(rCharacter,  &ax, &az);
	if (bortName == "cannonr" || bortName == "cannonl")
	{
		vz = MAX_VOLLEY_HEEL_ANGLE + sti(RealShips[sti(rCharacter.Ship.Type)].Class) * 0.04;
		if(bortName == "cannonr") az = az - vz;
		if(bortName == "cannonl") az = az + vz;
		SendMessage(rCharacter, "lff", MSG_SHIP_SET_HEEL_XZ, ax, az); 
		PostEvent("Ship_VolleyHeelEnd", 6000, "a", rCharacter);
	}
*/	
}

void Ship_VolleyHeelEnd()
{
	float	ax = 0.0;
	float 	az = 0.0;

	aref aCharacter = GetEventData();
	if(!LAi_IsDead(aCharacter))
	{
		SetHeel_XZ(aCharacter,  &ax, &az);	
		SendMessage(aCharacter, "lff", MSG_SHIP_SET_HEEL_XZ, ax, az); 	
	}	
}
