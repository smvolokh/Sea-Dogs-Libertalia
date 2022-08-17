void InitShips()
{
  ref refShip;

	for (int idx=0;idx<SHIP_TYPES_QUANTITY_WITH_FORT;idx++)
	{
		makeref(refShip,ShipsTypes[idx]);

		refship.index = idx;

		refship.InertiaAccelerationX = 0.2;		refship.InertiaBrakingX = 0.7;
		refship.InertiaAccelerationY = 0.4;		refship.InertiaBrakingY = 0.4;
		refship.InertiaAccelerationZ = 1.0;		refship.InertiaBrakingZ = 1.0;

		refship.Rocking.y 	= 0.5;
		refship.Rocking.az 	= 0.05;

		refship.NetGeraldSails = "";
		refship.Soundtype = "";

		refship.WaterLine 			= 0.0;
		refship.SpeedDependWeight 	= 0.0;
		refship.SubSeaDependWeight 	= 0.0;
		refship.TurnDependWeight 	= 0.0;
		refship.TurnDependSpeed 	= 0.0;

		refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
		refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
		refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;

        refship.WindAgainstSpeed   	= 1.0;//boal
		refship.CabinType          	= "Cabin_Small"; // потом припишем слово My_ и будет каютой для ГГ
        refShip.AbordageLocation	= "BOARDING_SMALL_DECK";
        refship.DeckType          	= "Low";
        
		refShip.MaxCaliber			= 6;
		refShip.Cannon				= CANNON_TYPE_CANNON_LBS6;
		refShip.CannonsQuantity		= 0;
		refShip.CannonsQuantityMin	= 0;

		aref cannonl, cannonr, cannonb, cannonf;

		refship.CanEncounter 	= true;
		refship.Type.Merchant 	= true;
		refship.Type.War 		= true;
		refship.Track.Enable 	= false;
		refShip.FireHeight 		= 3.0;

		refShip.Massa = 1500000.0;
		refShip.Volume = 900.0;
		refShip.lowpolycrew = 5;

		refShip.rcannon = 0;
		refShip.lcannon = 0;
		refShip.fcannon = 0;
		refShip.bcannon = 0;
		
		ShipsTypes[idx].Cannons.Borts.cannonl = "";
		ShipsTypes[idx].Cannons.Borts.cannonr = "";
		ShipsTypes[idx].Cannons.Borts.cannonf = "";
		ShipsTypes[idx].Cannons.Borts.cannonb = "";

		makearef(cannonl,ShipsTypes[idx].Cannons.Borts.cannonl);
		makearef(cannonr,ShipsTypes[idx].Cannons.Borts.cannonr);
		makearef(cannonf,ShipsTypes[idx].Cannons.Borts.cannonf);
		makearef(cannonb,ShipsTypes[idx].Cannons.Borts.cannonb);

		cannonf.FireZone	= Degree2Radian(30.0);
		cannonf.FireDir		= Degree2Radian(0.0);
		cannonf.FireAngMin	= -0.35;
		cannonf.FireAngMax	= 0.60;

		cannonr.FireZone	= Degree2Radian(80.0);
		cannonr.FireDir		= Degree2Radian(90.0);
		cannonr.FireAngMin	= -0.35;
		cannonr.FireAngMax	= 0.60;

		cannonb.FireZone	= Degree2Radian(30.0);
		cannonb.FireDir		= Degree2Radian(180.0);
		cannonb.FireAngMin	= -0.35;
		cannonb.FireAngMax	= 0.60;

		cannonl.FireZone	= Degree2Radian(80.0);
		cannonl.FireDir		= Degree2Radian(270.0);
		cannonl.FireAngMin	= -0.35;
		cannonl.FireAngMax	= 0.60;
	}
	
	///////////////////////////////////////////////////////////////////////////
	//// Лодка
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BOAT]);
	refShip.Name									= "Boat";
	refship.Soundtype								= "lugger";
	refShip.Class									= 6;
	refShip.Cannon									= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber								= 12;
	refShip.Weight									= Tonnes2CWT(10);
	refShip.Capacity								= 50;
	refShip.CannonsQuantity							= 0;
	refShip.CannonsQuantityMin						= 0;
	refShip.rcannon 								= 0;
	refShip.lcannon 								= 0;
	refShip.fcannon 								= 0;
	refShip.bcannon 								= 0;
	refShip.MaxCrew									= 10; 
	refShip.OptCrew									= 5; 
	refShip.MinCrew									= 1;
	refShip.SpeedRate								= 4;
	refShip.TurnRate								= 40;
	refShip.Price									= 100;
	refShip.HP										= 100;
	refShip.SP										= 100;
	refship.CanEncounter							= false;
	refship.Type.Merchant							= false;
	refship.Type.War								= false;
	refShip.lowpolycrew 							= 0;
	refship.WaterLine								= -0.3;

	refShip.Massa 									= 10000.0;
	refShip.Volume 									= 100.0;
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 0.4;	refship.InertiaBrakingY		= 0.2;
	refship.InertiaAccelerationZ	= 0.15;	refship.InertiaBrakingZ		= 0.05;
	
		//////////////////////////////////////////////////////////////////////////
	//// ОРДИНАРНЫЕ КОРАБЛИ
	//////////////////////////////////////////////////////////////////////////	
	
	///////////////////////////////////////////////////////////////////////////
	//// Баркас Tartane
	//////////////
/////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TARTANE]);
	refShip.Name				= "Tartane";
	refship.Soundtype			= "lugger";
	refShip.Class				= 6;
	refShip.Cannon				= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber			= 3;
	refShip.Weight				= Tonnes2CWT(10);
	refShip.Capacity			= 400;
	refShip.CannonsQuantity		= 0;
	refShip.CannonsQuantityMin		= 0;
	refShip.rcannon 			= 0;
	refShip.lcannon 			= 0;
	refShip.fcannon 			= 0;
	refShip.bcannon 			= 0;
	refShip.MaxCrew				= 10;
	refShip.OptCrew				= 5;
	refShip.MinCrew				= 1;	
	refShip.SpeedRate			= 12.0;
	refShip.TurnRate			= 70.0;
	refShip.Price				= 1500;
	refShip.HP					= 250;
	refShip.SP					= 100;
	refship.Type.Merchant			= true;
	refship.Type.War			= false;
	refShip.lowpolycrew 			= 3;

	refShip.Massa 				= 10000.0;
	refShip.Volume 									= 20.0;
	refship.WindAgainstSpeed   		= 1.0;
		
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 0.4;	refShip.Height.Bombs.DY		= 0.2;
	refShip.Height.Grapes.Y				= 1.3;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 6.5;	refShip.Height.Knippels.DY	= 5.8;
	refShip.Height.Balls.Y				= 0.4;	refShip.Height.Balls.DY		= 0.2;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	/// Плот Plot
	///////////////////////////////////////////////////////////////////////////

makeref(refShip,ShipsTypes[SHIP_PLOT]);
refShip.Name								= "Plot";
refship.Soundtype						= "lugger";
refShip.Class								= 6;
refShip.Cannon					= CANNON_TYPE_CANNON_LBS6;
refShip.MaxCaliber					= 8;
refShip.Weight						= Tonnes2CWT(10);
refShip.Capacity						= 50;
refShip.CannonsQuantity					= 5;
refShip.rcannon 						= 0;
refShip.lcannon 						= 0;
refShip.fcannon 						= 2;
refShip.bcannon 						= 3;
refShip.MaxCrew							= 15;
refShip.OptCrew							= 10;
refShip.MinCrew							= 3;	
refShip.SpeedRate						= 10.0;
refShip.TurnRate						= 60.0;
refShip.Price							= 500;
refShip.HP								= 150;
refShip.SP								= 100;

refship.Type.Merchant						= false;
refship.Type.War							= true;
	
refShip.lowpolycrew							= 3;

refShip.Massa = 50000.0;
refShip.Volume = 100.0;
refship.WindAgainstSpeed   					= 1.25;

refship.WaterLine				= -0.4;
refship.SpeedDependWeight			= 0.2;
refship.SubSeaDependWeight			= 0.4;
refship.TurnDependWeight			= 0.2;
    
refship.InertiaAccelerationX	= 3.0;
refship.InertiaBrakingX		= 2.0;
refship.InertiaAccelerationY	= 14;	
refship.InertiaBrakingY		= 5;
refship.InertiaAccelerationZ	= 5.0;
refship.InertiaBrakingZ		= 3.0;
	
refShip.Height.Bombs.Y				= 1.0;
refShip.Height.Bombs.DY		= 0.5;
refShip.Height.Grapes.Y				= 2.0;
refShip.Height.Grapes.DY	= 1.0;
refShip.Height.Knippels.Y			= 10.0;
refShip.Height.Knippels.DY	= 8.0;
refShip.Height.Balls.Y				= 1.0;
refShip.Height.Balls.DY		= 0.5;
refship.Track.Enable	= true;
refship.Track1.ZStart	= 0.20;
refship.Track1.LifeTime = 9;
refship.Track1.Width	= "1.0, 2.0";
refship.Track1.Speed	= "5.2, 6.2";

refship.Track2.ZStart	= -0.15;
refship.Track2.LifeTime = 7;
refship.Track2.Width	= "1.2, 2.0";
refship.Track2.Speed	= "0.15, 0.25";
	
//Nation
refship.nation.england	= false;
refship.nation.france	 = false;
refship.nation.holland	= false;
refship.nation.pirate	= true;
refship.nation.spain	= false;

///////////////////////////////////////////////////////////////////////////
	/// Gunboat		Канонерская лодка
	///////////////////////////////////////////////////////////////////////////

    makeref(refShip,ShipsTypes[SHIP_GUNBOAT]);
    refShip.Name			= "Gunboat";
    refShip.Soundtype			= "lugger";
    refShip.Class			= 6;
    refShip.Cannon			= CANNON_TYPE_CANNON_LBS6;
    refShip.MaxCaliber			= 8;
    refShip.Weight			= Tonnes2CWT(15);
    refShip.Capacity			= 300;
    refShip.CannonsQuantity		= 5;
    refShip.rcannon 				= 2;
    refShip.lcannon 				= 2;
    refShip.fcannon 				= 1;
    refShip.bcannon 				= 0;
    refShip.MaxCrew				= 20;
    refShip.OptCrew				= 15;
    refShip.MinCrew				= 5;	
    refShip.SpeedRate				= 11.0;
    refShip.TurnRate				= 65.0;


    refShip.Price			= 2500;
    refShip.HP				= 400;
    refShip.SP				= 100;

    refShip.Type.Merchant					= false;
    refShip.Type.War						= true;
    refship.WindAgainstSpeed   					= 1.25;
    refShip.lowpolycrew						= 3;

    refShip.Massa = 50000.0;
    refShip.Volume = 100.0;

    refShip.WaterLine					= -0.4;
    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.4;
    refShip.TurnDependWeight			= 0.2;

    refShip.InertiaAccelerationX	= 3.0;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 3.5;
    refShip.InertiaBrakingY		= 5;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 3.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "1.0, 2.0";
    refShip.Track1.Speed	= "5.2, 6.2";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "1.2, 2.0";
    refShip.Track2.Speed	= "0.15, 0.25";

//Nation
refship.nation.england	= true;
refship.nation.france	 = true;
refship.nation.holland	= true;
refship.nation.pirate	= false;
refship.nation.spain	= true;

///////////////////////////////////////////////////////////////////////////
	/// Dogger		Доггер
	///////////////////////////////////////////////////////////////////////////

    	makeref(refShip,ShipsTypes[SHIP_DOGGER]);
    	refShip.Name				= "Dogger";
    	refShip.Soundtype				= "lugger";
    	refShip.Class				= 6;
    	refShip.Cannon				= CANNON_TYPE_CANNON_LBS3;
    	refShip.MaxCaliber			= 3;
    	refShip.Weight				= Tonnes2CWT(20);
    	refShip.Capacity				= 600;
    	refShip.CannonsQuantity			= 8;
    	refShip.rcannon 							= 4;
    	refShip.lcannon 							= 4;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;
	refShip.MaxCrew							= 10;
	refShip.OptCrew							= 5;
	refShip.MinCrew							= 1;
    	refShip.SpeedRate						= 7.0;
    	refShip.TurnRate						= 45.0;
    	refShip.Price				= 4500;
    	refShip.HP					= 450;
    	refShip.SP					= 100;
    	refShip.Type.Merchant			= true;
    	refShip.Type.War			= false;

    	refShip.lowpolycrew = 3;
    	refship.WindAgainstSpeed   			= 1.35;

    	refShip.Massa = 10000.0;
    	refShip.Volume = 20.0;
    
    	refShip.WaterLine				= 0.0;
    	refShip.SpeedDependWeight			= 0.2;
    	refShip.SubSeaDependWeight			= 0.5;
    	refShip.TurnDependWeight			= 0.4;

    	refShip.InertiaAccelerationX 	= 3.0;
    	refShip.InertiaBrakingX		= 2.0;
    	refShip.InertiaAccelerationY	= 9;
    	refShip.InertiaBrakingY		= 5;
    	refShip.InertiaAccelerationZ	= 5.0;
    	refShip.InertiaBrakingZ		= 3.0;

    	refShip.Height.Bombs.Y				= 1.0;
    	refShip.Height.Bombs.DY		= 0.5;
    	refShip.Height.Grapes.Y				= 2.0;
    	refShip.Height.Grapes.DY	= 1.0;
    	refShip.Height.Knippels.Y			= 10.0;
    	refShip.Height.Knippels.DY	= 8.0;
    	refShip.Height.Balls.Y				= 1.0;
    	refShip.Height.Balls.DY		= 0.5;

    	refShip.Track.Enable	= true;
    	refShip.Track1.ZStart	= 0.20;
    	refShip.Track1.LifeTime = 9;
    	refShip.Track1.Width	= "1.0, 2.0";
    	refShip.Track1.Speed	= "5.2, 6.2";

    	refShip.Track2.ZStart	= -0.15;
    	refShip.Track2.LifeTime = 7;
    	refShip.Track2.Width	= "1.2, 2.0";
    	refShip.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	/// Ботик Botik
	///////////////////////////////////////////////////////////////////////////

    makeref(refShip,ShipsTypes[SHIP_BOTIK]);
    refShip.Name			= "Botik";
    refShip.Soundtype			= "lugger";
    refShip.Class			= 6;
    refShip.Cannon			= CANNON_TYPE_CANNON_LBS3;
    refShip.MaxCaliber			= 6;
    refShip.Weight			= Tonnes2CWT(10);
    refShip.Capacity			= 300;
    refShip.CannonsQuantity		= 8;
    refShip.rcannon 							= 4;
    refShip.lcannon 							= 4;
    refShip.fcannon 							= 0;
    refShip.bcannon 							= 0;
    refShip.MaxCrew							= 30;
    refShip.OptCrew							= 25;
    refShip.MinCrew							= 9;	
    refShip.SpeedRate							= 8.0;
    refShip.TurnRate							= 50.0;

    refShip.Price			= 3500;
    refShip.HP				= 300;
    refShip.SP				= 100;

    refShip.Type.Merchant					= true;
    refShip.Type.War						= true;
    refship.WindAgainstSpeed   			= 1.50;
    refShip.lowpolycrew						= 3;

    refShip.Massa = 50000.0;
    refShip.Volume = 100.0;

	refship.WaterLine					= -0.15;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refship.nation.england	= true;
	refship.nation.france	 = true;
refship.nation.holland	= true;
	refship.nation.pirate	= true;
refship.nation.spain	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Тартана WarTartane
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WAR_TARTANE]);
	refShip.Name						= "WarTartane";
	refship.Soundtype					= "lugger";
	refShip.Class						= 6;
	refShip.Cannon				= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber					= 6;
	refShip.Weight					= Tonnes2CWT(30);
	refShip.Capacity					= 400;
	refShip.CannonsQuantity				= 6; 
	refShip.CannonsQuantityMin				= 6;
	refShip.rcannon 							= 3; 
	refShip.lcannon 							= 3; 
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
    	refShip.MaxCrew							= 25;
    	refShip.OptCrew							= 20;
    	refShip.MinCrew							= 7;	
	refShip.SpeedRate						= 9.0;
	refShip.TurnRate						= 55.0;
	refShip.Price							= 5500;
	refShip.HP								= 400;
	refShip.SP								= 100;
	refship.CanEncounter						= true;
	refship.Type.Merchant						= true;
	refship.Type.War						= true;
	refShip.lowpolycrew							= 3;
	
	refShip.Massa 							= 50000.0;
	refShip.Volume 							= 100.0;

	refship.WaterLine						= 0.0;
	refship.SpeedDependWeight					= 0.2;
	refship.SubSeaDependWeight					= 0.4;
	refship.TurnDependWeight					= 0.2;
    	refship.WindAgainstSpeed   				= 1.25;
    
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 1.8;	refShip.Height.Grapes.DY	= 0.9;
	refShip.Height.Knippels.Y			= 6.7;	refShip.Height.Knippels.DY	= 6.7;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Барк Barque
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BARQUE]);
	refShip.Name            			= "Barque";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon				= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber					= 6;
	refShip.Weight					= Tonnes2CWT(350);
	refShip.Capacity       				= 1800;
	refShip.CannonsQuantity				= 14; 
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2; 
	refShip.MaxCrew         			= 62;
	refShip.OptCrew         			= 50;
	refShip.MinCrew         			= 26;
	refShip.SpeedRate					= 11.0;
	refShip.TurnRate        			= 33.0;
	refShip.Price           			= 29300;
	refShip.HP              			= 1500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 10;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.00;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.7;
	
	refShip.Height.Bombs.Y				= 3.3;	refShip.Height.Bombs.DY		= 1.6;
	refShip.Height.Grapes.Y				= 4.9;	refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 15.8;	refShip.Height.Knippels.DY	= 12.4;
	refShip.Height.Balls.Y				= 3.3;	refShip.Height.Balls.DY		= 1.6;	
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 7.5;
	refship.Track1.Width	= "6.0, 7.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 5.0;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Гафельный шлюп GafelSloop
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_GAFELSLOOP]);
	refShip.Name            			= "GafelSloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      		= 8;
	refShip.Weight					= Tonnes2CWT(90);
	refShip.Capacity        			= 700;
    refShip.CannonsQuantity				= 8;
	refShip.CannonsQuantityMin				= 6;
    refShip.rcannon 					= 4;
    refShip.lcannon 					= 4;
    refShip.fcannon 					= 0;
    refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 37;
	refShip.OptCrew         			= 25;
	refShip.MinCrew         			= 16;
	refShip.SpeedRate				= 15.0;
	refShip.TurnRate        			= 56.0;
	refShip.Price           			= 20000;
	refShip.HP              			= 700;
	refShip.SP              			= 100;

     refship.CabinType          	= "Cabin_Small"; 
	refship.DeckType           			= "Low";

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 8;

    refShip.Rocking.y = 0.45;
    refShip.Rocking.az = 0.02;

    refShip.WaterLine							= 0.3;

    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.3;
    refShip.TurnDependWeight			= 0.3;
    refship.WindAgainstSpeed   		     = 1.0;
	
	refShip.Height.Bombs.Y				= 2.1;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.1;	refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 13.5;	refShip.Height.Knippels.DY	= 10.5;
	refShip.Height.Balls.Y				= 2.1;	refShip.Height.Balls.DY		= 1.0;
	
    refShip.InertiaAccelerationX	= 8.0;
    refShip.InertiaBrakingX		= 8.0;
    refShip.InertiaAccelerationY	= 8;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 8.0;
    refShip.InertiaBrakingZ		= 8.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 2.5";
    refShip.Track1.Speed	= "5.2, 6.2";

    refShip.Track2.ZStart	= -0.05;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= true;
    refship.nation.holland	= true;
    refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Galiot Галиот
	///////////////////////////////////////////////////////////////////////////

makeref(refShip,ShipsTypes[SHIP_GALIOT]);
refShip.Name            			= "Galiot";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
refShip.MaxCaliber      		= 8;
refShip.Weight						= Tonnes2CWT(170);
refShip.Capacity        			= 1400;
refShip.CannonsQuantity				= 16;
refShip.CannonsQuantityMin				= 14;
refShip.rcannon 							= 6;
refShip.lcannon 							= 6;
refShip.fcannon 							= 2;
refShip.bcannon 							= 2;
refShip.MaxCrew         			= 72;
refShip.OptCrew         			= 60;
refShip.MinCrew         			= 30;
refShip.SpeedRate				= 10.0;
refShip.TurnRate        			= 27.0;
refShip.Price           			= 31200;
refShip.HP              			= 1400;
refShip.SP              			= 100;

	refship.DeckType           			= "Low";

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 8;

    refShip.Rocking.y = 0.6;
    refShip.Rocking.az = 0.035;

    refShip.WaterLine							= -0.0;

    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.2;
    refship.WindAgainstSpeed   			= 1.30;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 12.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
    refShip.InertiaAccelerationX	= 2.2;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY	= 8;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= true;
    refship.nation.holland	= true;
    refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Ketch Кеч
	///////////////////////////////////////////////////////////////////////////

makeref(refShip,ShipsTypes[SHIP_KETCH]);
refShip.Name            			= "Ketch";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
refShip.MaxCaliber      		= 8;
refShip.Weight						= Tonnes2CWT(150);
refShip.Capacity        			= 600;
refShip.CannonsQuantity		= 8;
refShip.CannonsQuantityMin		= 6;
refShip.rcannon 		= 4;
refShip.lcannon 		= 4;
refShip.fcannon 							= 0;
refShip.bcannon 							= 0;
refShip.MaxCrew         			= 37;
refShip.OptCrew         			= 25;
refShip.MinCrew         			= 16;
refShip.SpeedRate				= 15.5;
refShip.TurnRate        			= 61.0;
refShip.Price           			= 19300;
refShip.HP              			= 600;
refShip.SP              			= 100;

refship.CabinType          		= "New_Cabin1";
refship.DeckType           			= "Low";

refship.Type.Merchant				= true;
refship.Type.War					= true;
refShip.lowpolycrew 				= 16;

refShip.Rocking.y 		= 0.5;
refShip.Rocking.az 		= 0.035;

refShip.WaterLine		= 0.3;

refShip.SpeedDependWeight	= 0.0;
refShip.SubSeaDependWeight	= 0.2;
refShip.TurnDependWeight	= 0.6;
refship.WindAgainstSpeed   = 1.40;
	
    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
    refShip.InertiaAccelerationX	= 3.5;
    refShip.InertiaBrakingX		= 3.5;
    refShip.InertiaAccelerationY	= 4;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 4.5;
    refShip.InertiaBrakingZ		= 4.5;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 10;
    refShip.Track1.Width		= "4.0, 5.0";
    refShip.Track1.Speed		= "7.2, 9.2";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 7.5;
    refShip.Track2.Width		= "5.0, 7.0";
    refShip.Track2.Speed		= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= false;
    refship.nation.holland	= true;
    refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Yacht Яхта
	///////////////////////////////////////////////////////////////////////////
makeref(refShip,ShipsTypes[SHIP_YACHT]);
refShip.Name            			= "Yacht";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon          		= CANNON_TYPE_CANNON_LBS3;
refShip.MaxCaliber      		= 3;
refShip.Weight				= Tonnes2CWT(85);
refShip.Capacity        			= 400;
refShip.CannonsQuantity		= 16;
refShip.CannonsQuantityMin		= 14;
refShip.rcannon 							= 6;
refShip.lcannon 							= 6;
refShip.fcannon 							= 2;
refShip.bcannon 							= 2;
refShip.MaxCrew         			= 32;
refShip.OptCrew         			= 20;
refShip.MinCrew         			= 14;
refShip.SpeedRate				= 17.0;
refShip.TurnRate        			= 70.0;
refShip.Price           			= 100000;
refShip.HP              			= 700;
refShip.SP              			= 100;

refship.CabinType          			= "Cabin_Huge"; 
refship.DeckType           			= "Low";

refship.Type.Merchant				= false;
refship.Type.War					= true;
refShip.lowpolycrew 				= 8;

refShip.Rocking.y 		= 0.5;
refShip.Rocking.az 		= 0.035;

refShip.WaterLine						= -0.2;

refShip.SpeedDependWeight			= 0.2;
refShip.SubSeaDependWeight			= 0.6;
refShip.TurnDependWeight			= 0.2;
refship.WindAgainstSpeed   			= 1.10;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
    refShip.InertiaAccelerationX	= 2.0;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 8;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 4.0;
    refShip.InertiaBrakingZ		= 2.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= true;
    refship.nation.holland	= true;
    refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Snauw Снау
	///////////////////////////////////////////////////////////////////////////

makeref(refShip,ShipsTypes[SHIP_SNAUW]);
refShip.Name            			= "Snauw";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
refShip.MaxCaliber      		= 8;
refShip.Weight				= Tonnes2CWT(160);
refShip.Capacity        			= 1300;
refShip.CannonsQuantity		= 12;
refShip.CannonsQuantityMin		= 10;
refShip.rcannon 							= 6;
refShip.lcannon 							= 6;
refShip.fcannon 							= 0;
refShip.bcannon 							= 0;
refShip.MaxCrew         			= 62;
refShip.OptCrew         			= 50;
refShip.MinCrew         			= 26;
refShip.SpeedRate				= 12.0;
refShip.TurnRate        			= 39.0;
refShip.Price           			= 27400;
refShip.HP              			= 1200;
refShip.SP              			= 100;


refship.CabinType          = "New_Cabin1"; 
refship.DeckType           			= "Low";

refship.Type.Merchant				= true;
refship.Type.War					= true;
refShip.lowpolycrew 				= 8;

refShip.Rocking.y 		= 0.5;
refShip.Rocking.az 		= 0.035;

refShip.WaterLine							= -0.1;
refShip.SpeedDependWeight			= 0.3;
refShip.SubSeaDependWeight			= 0.6;
refShip.TurnDependWeight			= 0.7;
refship.WindAgainstSpeed   			= 0.65;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
    refShip.InertiaAccelerationX	= 3.5;
    refShip.InertiaBrakingX		= 3.5;
    refShip.InertiaAccelerationY	= 5.4;
    refShip.InertiaBrakingY		= 4.8;
    refShip.InertiaAccelerationZ	= 4.2;
    refShip.InertiaBrakingZ		= 3.5;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= false;
    refship.nation.holland	= true;
    refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Cutter Куттер
	///////////////////////////////////////////////////////////////////////////
makeref(refShip,ShipsTypes[SHIP_CUTTER]);
refShip.Name            			= "Cutter";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
refShip.MaxCaliber      		= 8;
refShip.Weight						= Tonnes2CWT(90);
refShip.Capacity        				= 800;
refShip.CannonsQuantity				= 10;
refShip.CannonsQuantityMin				= 8;
refShip.rcannon 							= 4;
refShip.lcannon 							= 4;
refShip.fcannon 							= 2;
refShip.bcannon 							= 2;
refShip.MaxCrew         			= 42;
refShip.OptCrew         			= 30;
refShip.MinCrew         			= 18;
refShip.SpeedRate				= 14.0;
refShip.TurnRate        			= 51.0;
refShip.Price           			= 24700;
refShip.HP              			= 800;
refShip.SP              			= 100;

refship.CabinType          = "Old_Cabin_Small"; 
refship.DeckType           			= "Low";

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 8;

    refShip.Rocking.y = 0.4;
    refShip.Rocking.az = 0.035;

    refShip.WaterLine							= -0.0;

    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.2;
    refship.WindAgainstSpeed   			= 1.30;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
    refShip.InertiaAccelerationX	= 0.2;
    refShip.InertiaBrakingX		= 0.5;
    refShip.InertiaAccelerationY	= 10;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 4.0;
    refShip.InertiaBrakingZ		= 3.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= false;
    refship.nation.holland	= false;
    refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Contraband Контрабандистский корабль
	///////////////////////////////////////////////////////////////////////////

makeref(refShip,ShipsTypes[SHIP_CONTRABAND]);
refShip.Name            			= "Contraband";
refship.Soundtype					= "lugger";
refShip.Class						= 5;
refShip.Cannon				= CANNON_TYPE_CANNON_LBS3;
refShip.MaxCaliber					= 6;
refShip.Weight						= Tonnes2CWT(200);
refShip.Capacity       				= 1600;
refShip.CannonsQuantity		= 4;
refShip.CannonsQuantityMin		= 2;
refShip.rcannon 							= 2;
refShip.lcannon 							= 2;
refShip.fcannon 							= 0;
refShip.bcannon 							= 0;
refShip.MaxCrew         			= 27;
refShip.OptCrew         			= 15;
refShip.MinCrew         			= 12;
refShip.SpeedRate				= 16.5;
refShip.TurnRate        			= 67.0;
refShip.Price           			= 18900;
refShip.HP              			= 1300;
refShip.SP              			= 100;

refship.CabinType          = "New_Cabin1"; 
refship.DeckType           			= "Low";

	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 8;

    refShip.Rocking.y = 0.5;
    refShip.Rocking.az = 0.04;

refShip.WaterLine							= 0.5;

    refShip.SpeedDependWeight			= 0.27;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.3;
    refship.WindAgainstSpeed   			= 0.60;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 15.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;
	
    refShip.InertiaAccelerationX	= 0.2;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 6;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width	= "4.0, 6.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
    refship.nation.england	= true;
    refship.nation.france	= true;
    refship.nation.spain	= true;
    refship.nation.holland	= true;
    refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	/// Chaloupe	Шалюп
	///////////////////////////////////////////////////////////////////////////

    makeref(refShip,ShipsTypes[SHIP_CHALOUPE]);
    refShip.Name			= "Chaloupe";
    refShip.Soundtype			= "lugger";
    refShip.Class			= 5;
    refShip.Cannon			= CANNON_TYPE_CANNON_LBS3;
    refShip.MaxCaliber			= 6;
    refShip.Weight			= Tonnes2CWT(30);
    refShip.Capacity			= 900;
    refShip.CannonsQuantity		= 10;
    refShip.CannonsQuantityMin		= 8;
    refShip.rcannon 							= 5;
    refShip.lcannon 							= 5;
    refShip.fcannon 							= 0;
    refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 47;
	refShip.OptCrew         			= 35;
	refShip.MinCrew         			= 20;
    refShip.SpeedRate							= 13.5;
    refShip.TurnRate							= 48.0;

    refShip.Price			= 22700;
    refShip.HP				= 900;
    refShip.SP				= 100;

refship.CabinType          = "New_Cabin1"; 
refship.DeckType           			= "Low";

    refShip.Type.Merchant					= true;
    refShip.Type.War						= true;
    refship.WindAgainstSpeed   			= 0.65;
    refShip.lowpolycrew						= 8;

    refShip.Massa = 50000.0;
    refShip.Volume = 100.0;

    refShip.WaterLine					= 0.2;
    refShip.SpeedDependWeight			= 0.1;
    refShip.SubSeaDependWeight			= 0.3;
    refShip.TurnDependWeight			= 0.2;

    refShip.InertiaAccelerationX	= 3.0;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 14;
    refShip.InertiaBrakingY		= 5;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 3.0;
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 13.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "1.0, 2.0";
    refShip.Track1.Speed	= "5.2, 6.2";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "1.2, 2.0";
    refShip.Track2.Speed	= "0.15, 0.25";

//Nation
refship.nation.england	= true;
refship.nation.france	 = true;
refship.nation.holland	= false;
refship.nation.pirate	= true;
refship.nation.spain	= false;

///////////////////////////////////////////////////////////////////////////
	//// Боевой шлюп Warsloop
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARSLOOP]);
	refShip.Name            			= "Warsloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	 = CANNON_TYPE_CULVERINE_LBS8;
	refShip.MaxCaliber      			= 12;
	refShip.Weight					= Tonnes2CWT(170);
	refShip.Capacity        			= 900;	
	refShip.CannonsQuantity				= 18; 
	refShip.CannonsQuantityMin				= 16;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 82;
	refShip.OptCrew         			= 70;
	refShip.MinCrew         			= 34;
	refShip.SpeedRate				= 9.5;
	refShip.TurnRate        			= 24.0;
	refShip.Price           			= 33100;
	refShip.HP              			= 1200;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 9;
	
	refship.Rocking.y 					= 0.35;
	refship.Rocking.az 					= 0.05;
	
	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.CabinType          = "Old_Cabin_Small"; 
	refship.DeckType           			= "Low";
	refship.WindAgainstSpeed   			= 1.30;

	refShip.Height.Bombs.Y				= 1.6;	refShip.Height.Bombs.DY		= 1.25;
	refShip.Height.Grapes.Y				= 2.75;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 13.2;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 1.6;	refShip.Height.Balls.DY		= 1.25;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.10;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Торговый шлюп Tradesloop
	///////////////////
////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TRADESLOOP]);
	refShip.Name            			= "Tradesloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon				= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber					= 6;
	refShip.Weight					= Tonnes2CWT(170);
	refShip.Capacity        			= 1700;	
	refShip.CannonsQuantity				= 16;
	refShip.CannonsQuantityMin				= 14;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 67;
	refShip.OptCrew         			= 55;
	refShip.MinCrew         			= 28;
	refShip.SpeedRate					= 10.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 30300;
	refShip.HP              			= 1400;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 8;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine						= 0.35;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.DeckType           			= "Low";
	refship.CabinType          = "Old_Cabin_Small"; 
	refship.WindAgainstSpeed   			= 1.30;

	refShip.Height.Bombs.Y				= 2.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.8;	refShip.Height.Grapes.DY	= 1.9;
	refShip.Height.Knippels.Y			= 15.2;	refShip.Height.Knippels.DY	= 13.9;
	refShip.Height.Balls.Y				= 2.0;	refShip.Height.Balls.DY		= 1.0;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate 	= false;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкий шлюп Lightsloop
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTSLOOP]);
	refShip.Name            			= "Lightsloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	= CANNON_TYPE_CULVERINE_LBS8;
	refShip.MaxCaliber      			= 12;
	refShip.Weight					= Tonnes2CWT(120);
	refShip.Capacity        			= 450;
    	refShip.CannonsQuantity		= 8;
	refShip.CannonsQuantityMin			= 6;
    refShip.rcannon 							= 3;
    refShip.lcannon 							= 3;
    refShip.fcannon 							= 1;
    refShip.bcannon 							= 1;

	refShip.MaxCrew         			= 42;
	refShip.OptCrew         			= 30;
	refShip.MinCrew         			= 18;
	refShip.SpeedRate				= 16.0;
	refShip.TurnRate        			= 64.0;
	refShip.Price           			= 21400;
	refShip.HP              			= 750;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;

    refShip.Rocking.y = 0.5;
    refShip.Rocking.az = 0.035;
	
    refShip.WaterLine							= -0.15;

refShip.SpeedDependWeight			= 0.4;
refShip.SubSeaDependWeight			= 0.5;
refShip.TurnDependWeight			= 0.2;
refship.DeckType           			= "Low";
refship.CabinType          	= "Cabin_Small"; 
refship.WindAgainstSpeed   			= 1.30;

    refShip.InertiaAccelerationX	= 1.0;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 15;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 3.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 13.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Каравелла-латина Latina
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LATINA]);
	refShip.Name            			= "Latina";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 1500;
    refShip.CannonsQuantity		= 20;
	refShip.CannonsQuantityMin			= 18;
    refShip.rcannon 		= 9;
    refShip.lcannon 		= 9;
    refShip.fcannon 		= 0;
    refShip.bcannon 		= 2;

	refShip.MaxCrew         			= 77;
	refShip.OptCrew         			= 65;
	refShip.MinCrew         			= 32;
	refShip.SpeedRate				= 9.0;
	refShip.TurnRate        			= 21.0;
	refShip.Price           			= 32655;
	refShip.HP              			= 1500;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;

    refShip.Rocking.y = 0.5;
    refShip.Rocking.az = 0.035;
	
    refShip.WaterLine		= 0.3;

    refShip.SpeedDependWeight	= 0.2;
    refShip.SubSeaDependWeight	= 0.6;
    refShip.TurnDependWeight	= 0.2;
refship.DeckType           			= "Low";
refship.CabinType          = "Old_Cabin_Small"; 
refship.WindAgainstSpeed   			= 1.55;

    refShip.InertiaAccelerationX	 = 3.0;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY 	= 3;
    refShip.InertiaBrakingY		 = 3;
    refShip.InertiaAccelerationZ	 = 3.0;
    refShip.InertiaBrakingZ		 = 3.0;

    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 12.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 0.5;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 10;
    refShip.Track1.Width		= "4.0, 5.0";
    refShip.Track1.Speed		= "7.2, 9.2";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 7.5;
    refShip.Track2.Width		= "5.0, 7.0";
    refShip.Track2.Speed		= "0.15, 0.25";

	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Каравелла-редонда Redonda
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_REDONDA]);
	refShip.Name            			= "Redonda";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity        			= 1000;
     refShip.CannonsQuantity		= 10;
	refShip.CannonsQuantityMin		= 8;
    refShip.rcannon 		= 4;
    refShip.lcannon 		= 4;
    refShip.fcannon 		= 0;
    refShip.bcannon 		= 2;

	refShip.MaxCrew         			= 52;
	refShip.OptCrew         			= 40;
	refShip.MinCrew         			= 22;
	refShip.SpeedRate				= 13.0;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 23600;
	refShip.HP              			= 1000;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;

    refShip.Rocking.y 		= 0.6;
    refShip.Rocking.az 		= 0.045;
	
    refShip.WaterLine		= 0.4;

    refShip.SpeedDependWeight	= 0.2;
    refShip.SubSeaDependWeight	= 0.6;
    refShip.TurnDependWeight	= 0.2;
refship.DeckType           			= "Low";
refship.CabinType          = "Old_Cabin_Small"; 
refship.WindAgainstSpeed   			= 1.25;

    refShip.InertiaAccelerationX 	= 3.0;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY 	= 3;
    refShip.InertiaBrakingY		= 3;
    refShip.InertiaAccelerationZ 	= 3.0;
    refShip.InertiaBrakingZ		= 3.0;

    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 0.5;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 10;
    refShip.Track1.Width		= "4.0, 5.0";
    refShip.Track1.Speed		= "7.2, 9.2";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 7.5;
    refShip.Track2.Width		= "5.0, 7.0";
    refShip.Track2.Speed		= "0.15, 0.25";

	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Торговая шхуна Schooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SCHOONER]);
	refShip.Name            			= "Schooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight					= Tonnes2CWT(250);
	refShip.Capacity        			= 2100;	

	refShip.CannonsQuantity				= 12; 
	refShip.CannonsQuantityMin				= 8;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 125;
	refShip.OptCrew         			= 80;
	refShip.MinCrew         			= 18;	
	refShip.SpeedRate				= 15.0;	
	refShip.TurnRate        			= 59.0;
	refShip.Price           			= 42300;	
	refShip.HP              			= 1500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 12;
	
	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.03;

	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.10;

	refship.CabinType          	= "Old_Cabin_Medium";
     refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.7;		refShip.Height.Bombs.DY		= 0.8;
	refShip.Height.Grapes.Y				= 2.9;		refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y			= 13.9;		refShip.Height.Knippels.DY	= 13.7;
	refShip.Height.Balls.Y				= 1.7;		refShip.Height.Balls.DY		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкая шхуна Lightschooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTSCHOONER]);
	refShip.Name            			= "Lightschooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;	
	
	refShip.Weight					= Tonnes2CWT(150);
	refShip.Capacity        			= 1900;

    refShip.CannonsQuantity				= 12;
	refShip.CannonsQuantityMin				= 8;
    refShip.rcannon 						= 4;
    refShip.lcannon 						= 4;
    refShip.fcannon 						= 2;
    refShip.bcannon 						= 2;

	refShip.MaxCrew         			= 115;
	refShip.OptCrew         			= 70;
	refShip.MinCrew         			= 15;	
	refShip.SpeedRate				= 15.5;
	refShip.TurnRate        			= 62.0;
	refShip.Price           			= 41150;
	refShip.HP              			= 1300;
	refShip.SP              			= 100;	

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 10;

    refShip.Rocking.y 		= 0.4;
    refShip.Rocking.az 		= 0.03;

	refship.WaterLine					= 0.2;

    refShip.SpeedDependWeight	= 0.2;
    refShip.SubSeaDependWeight	= 0.2;
    refShip.TurnDependWeight	= 0.3;
    refship.WindAgainstSpeed   	= 1.15;


     refship.DeckType           = "Medium";
	refship.CabinType          = "Old_Cabin_Medium";
	
    refShip.InertiaAccelerationX 	= 6.0;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY 	= 6;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ 	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 15.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 8;
    refShip.Track1.Width		= "1.2, 2.2";
    refShip.Track1.Speed		= "7.2, 8.2";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 6;
    refShip.Track2.Width		= "2.2, 3.2";
    refShip.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Гафельная шхуна GafelSchooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_GAFELSCHOONER]);
	refShip.Name            			= "GafelSchooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      		= 18;
	refShip.Weight					= Tonnes2CWT(180);
	refShip.Capacity        			= 3700;	

	refShip.CannonsQuantity				= 20;
	refShip.CannonsQuantityMin				= 16;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;

	refShip.MaxCrew         			= 205;
	refShip.OptCrew         			= 160;
	refShip.MinCrew         			= 42;	

	refShip.SpeedRate				= 11.0;	
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 50500;	
	refShip.HP              			= 3100;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 8;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine						= 0.0;
	refship.SpeedDependWeight			= 0.0;
	refship.SubSeaDependWeight			= 0.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.20;

     refship.DeckType           = "Medium";
	refship.CabinType          	= "Cabin_Small"; 
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

    	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	refship.nation.spain	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Баркентина Barkentine
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BARKENTINE]);
	refShip.Name            			= "Barkentine";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight					= Tonnes2CWT(300);
	refShip.MaxCrew         			= 165;
	refShip.OptCrew         			= 120;
	refShip.MinCrew         			= 30;	
	refShip.Capacity       				= 2900;
	refShip.CannonsQuantity				= 14; 
	refShip.CannonsQuantityMin				= 10;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.SpeedRate       			= 13.0;
	refShip.TurnRate        			= 47.0;	
	refShip.Price           			= 46300;	
	refShip.HP              			= 2300;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 12;
	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	refship.WaterLine					= 1.15;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	
	refship.WindAgainstSpeed   			= 1.25;
	
	refship.CabinType          		= "Old_Cabin_Medium";
     refship.DeckType           = "Medium";
		
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 3.5;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 4.8;		refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 16.7;		refShip.Height.Knippels.DY	= 12.8;
	refShip.Height.Balls.Y				= 3.5;		refShip.Height.Balls.DY		= 1.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Шнява Shnyava
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SHNYAVA]);
	refShip.Name            			= "Shnyava";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;
	refShip.Weight					= Tonnes2CWT(350);
	refShip.Capacity       			= 3100;
	refShip.CannonsQuantity				= 16;	
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 175;
	refShip.OptCrew         			= 130;
	refShip.MinCrew         			= 33;	
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 44.0;
	refShip.Price           			= 47200;
	refShip.HP              			= 2500;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 1.15;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.10;
	refship.CabinType          		= "Old_Cabin_Medium";
     refship.DeckType           = "Medium";
		
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 3.5;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 4.8;		refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 16.7;		refShip.Height.Knippels.DY	= 12.8;
	refShip.Height.Balls.Y				= 3.5;		refShip.Height.Balls.DY		= 1.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Флейт  Fleut
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FLEUT]);
	refShip.Name            			= "Fleut";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;	
	refShip.Weight					= Tonnes2CWT(450);	
	refShip.Capacity        			= 3300;	
	refShip.CannonsQuantity				= 16; 
	refShip.CannonsQuantityMin				= 12;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 185;
	refShip.OptCrew         			= 140;
	refShip.MinCrew         			= 36;	
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 48400;
	refShip.HP              			= 2700;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 1.2;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
	
	refship.CabinType          			= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 3.4;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 5.0;		refShip.Height.Grapes.DY	= 2.5;
	refShip.Height.Knippels.Y			= 17.8;		refShip.Height.Knippels.DY	= 13.3;
	refShip.Height.Balls.Y				= 3.4;		refShip.Height.Balls.DY		= 1.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;


	///////////////////////////////////////////////////////////////////////////
	//// Торговый флейт TradeFleut
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TRADEFLEUT]);
	refShip.Name            			= "TradeFleut";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;	
	refShip.Weight					= Tonnes2CWT(750);	
	refShip.Capacity        			= 3500;	
	refShip.CannonsQuantity			= 16;
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;
	
	refShip.MaxCrew         			= 195;
	refShip.OptCrew         			= 150;
	refShip.MinCrew         			= 39;	
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 49600;
	refShip.HP              			= 2900;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 16;
	
    refShip.Rocking.y 		= 0.54;
    refShip.Rocking.az 		= 0.035;
	
	refship.WaterLine					= -0.65;
    	refShip.SpeedDependWeight	= 0.15;
    	refShip.SubSeaDependWeight	= 0.8;
    	refShip.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
	
	refship.CabinType          		= "Old_Cabin_Medium"; 
	refship.DeckType           			= "Medium";
		
    refShip.InertiaAccelerationX	= 4.5;
    refShip.InertiaBrakingX		= 4.5;
    refShip.InertiaAccelerationY	= 6;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 4.0;
    refShip.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 3.4;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 5.0;		refShip.Height.Grapes.DY	= 2.5;
	refShip.Height.Knippels.Y			= 18.8;		refShip.Height.Knippels.DY			= 13.3;
	refShip.Height.Balls.Y				= 3.4;		refShip.Height.Balls.DY		= 1.7;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 12;
    refShip.Track1.Width		= "2.0, 3.0";
    refShip.Track1.Speed		= "8.0, 8.0";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 7.5;
    refShip.Track2.Width		= "6.0, 8.0";
    refShip.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Каравелла Caravel
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_CARAVEL]);
	refShip.Name            			= "Caravel";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;
	refShip.Weight					= Tonnes2CWT(850);
	refShip.Capacity        			= 4100;
	refShip.CannonsQuantity			= 20; 
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 225;
	refShip.OptCrew         			= 180;
	refShip.MinCrew         			= 48;	
	refShip.SpeedRate				= 10.0;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 52200;	
	refShip.HP              			= 3500;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	refship.CabinType          			= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";
	
	refship.WaterLine					= 1.0;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.25;
	
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 2.7;	refShip.Height.Bombs.DY		= 1.3;
	refShip.Height.Grapes.Y				= 4.3;	refShip.Height.Grapes.DY	= 2.1;
	refShip.Height.Knippels.Y			= 13.0;	refShip.Height.Knippels.DY	= 11.7;
	refShip.Height.Balls.Y				= 2.7;	refShip.Height.Balls.DY		= 1.3;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;
        	///////////////////////////////////////////////////////////////////////////
	//// Пинас Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE]);
	refShip.Name            			= "Pinnace";
	refship.Soundtype					= "frigate";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;	
	refShip.Weight					= Tonnes2CWT(800);	
	refShip.Capacity        			= 4500;
	refShip.CannonsQuantity			= 18; 
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew					= 200;
	refShip.OptCrew         			= 160;
	refShip.MinCrew         			= 42;	
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 33.0;
	refShip.Price           			= 60100;
	refShip.HP              			= 4200;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;

	refship.WaterLine					= 0.4;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 1.3;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
    refship.CabinType          			= "Cabin_Medium2";
    refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.5;		refShip.Height.Grapes.DY	= 2.7;
	refShip.Height.Knippels.Y			= 24.1;		refShip.Height.Knippels.DY	= 20.7;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Каракка Caracca
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARACCA]);
	refShip.Name            			= "Caracca";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;	
	refShip.Weight					= Tonnes2CWT(750);
	refShip.Capacity        			= 4800;
	refShip.CannonsQuantity				= 20; 
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew					= 215;
	refShip.OptCrew         			= 175;
	refShip.MinCrew         			= 46;	
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 62900;
	refShip.HP              			= 5100;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.6;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.95;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.75;
	
	refship.CabinType          			= "Cabin_Medium2"; // boal 28.03.05
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.7;		refShip.Height.Knippels.DY	= 12.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Навио Navio
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_NAVIO]);
	refShip.Name            			= "Navio";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(1100);
	refShip.Capacity        			= 8200;
	refShip.CannonsQuantity			= 36; 
	refShip.CannonsQuantityMin			= 28;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 465;
	refShip.OptCrew         			= 360;
	refShip.MinCrew         			= 45;
	refShip.SpeedRate				= 12.5;
	refShip.TurnRate        			= 42.0;
	refShip.Price           			= 81800;
	refShip.HP              			= 7200;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= -0.2;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;
	
///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый пинас HeavyPinnace
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_HEAVYPINNACE]);
	refShip.Name            			= "HeavyPinnace";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;	
	refShip.Weight					= Tonnes2CWT(2000);	
	refShip.Capacity        			= 11000;
	refShip.CannonsQuantity			= 62;	
	refShip.CannonsQuantityMin			= 54;
	refShip.rcannon 					= 28;
	refShip.lcannon 					= 28;
	refShip.fcannon 					= 2;
	refShip.bcannon 				= 4; 
	refShip.MaxCrew         			= 545;
	refShip.OptCrew         			= 440;
	refShip.MinCrew         			= 65;	
	refShip.SpeedRate				= 10.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 93100;
	refShip.HP              			= 10000;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y 				= 0.3;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= 1.8;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   			= 0.45;
    	refship.CabinType          			= "Cabin";
    	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 5.7;		refShip.Height.Bombs.DY		= 2.3;
	refShip.Height.Grapes.Y				= 6.3;		refShip.Height.Grapes.DY	= 3.1;
	refShip.Height.Knippels.Y			= 30.1;		refShip.Height.Knippels.DY	= 25.8;
	refShip.Height.Balls.Y				= 5.7;		refShip.Height.Balls.DY		= 2.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= false;
	refship.nation.france	= false
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Ост-Индец EastIndiaMan
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_EASTINDIAMAN]);
	refShip.Name            			= "EastIndiaMan";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(1000);
	refShip.Capacity        			= 7500;
	refShip.CannonsQuantity			= 36;	
	refShip.CannonsQuantityMin			= 28;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 6;	
	refShip.MaxCrew         			= 445;
	refShip.OptCrew         			= 340;
	refShip.MinCrew         			= 40;
	refShip.SpeedRate				= 13.0;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 80500;
	refShip.HP              			= 6500;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.55;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
      	
	///////////////////////////////////////////////////////////////////////////
	//// Курьерский люггер LuggerQuest
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_CAREERLUGGER]);
	refShip.Name            			= "LuggerQuest";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          	= CANNON_TYPE_CULVERINE_LBS8;
	refShip.MaxCaliber      			= 12;
	refShip.Weight					= Tonnes2CWT(120);	
	refShip.Capacity        			= 550;
	refShip.CannonsQuantity				= 10;
	refShip.CannonsQuantityMin			= 8;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 57;
	refShip.OptCrew         			= 45;
	refShip.MinCrew         			= 24;
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 25800;
	refShip.HP              			= 850;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;

	refship.WaterLine					= -0.2;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.60;
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;

	refship.CabinType          = "New_Cabin1";
	refship.DeckType           			= "Low";
	
	refShip.Height.Bombs.Y				= 1.65;	refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 2.64;	refShip.Height.Grapes.DY	= 0.5;
	refShip.Height.Knippels.Y			= 14.64; refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 1.65;	refShip.Height.Balls.DY		= 1.35;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Люггер Lugger
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LUGGER]);
	refShip.Name            			= "Lugger";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 8;
	refShip.Weight					= Tonnes2CWT(150);
	refShip.Capacity        			= 1100;
	refShip.CannonsQuantity				= 12;	//2,2,4,4	2,2,3,3
	refShip.CannonsQuantityMin			= 10;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;		
	refShip.MaxCrew         			= 57;
	refShip.OptCrew         			= 45;
	refShip.MinCrew         			= 24;
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 42.0;
	refShip.Price           			= 26500;
	refShip.HP              			= 1100;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;

     refship.CabinType          	= "Cabin_Small"; 
	refship.DeckType           			= "Low";

	refship.WaterLine					= 0.2;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.50;
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 2.1;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.1;	refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 10.5;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 2.1;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Шлюп Sloop
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SLOOP]);
	refShip.Name            			= "Sloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 8;
	refShip.Weight					= Tonnes2CWT(170);
	refShip.Capacity        			= 1300;	
	refShip.CannonsQuantity				= 14; // 2,2,5,5	2,2,4,4
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 67;
	refShip.OptCrew         			= 55;
	refShip.MinCrew         			= 28;
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 28200;
	refShip.HP              			= 1300;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.DeckType           			= "Small";
	refship.WindAgainstSpeed   			= 1.30;

	refShip.Height.Bombs.Y				= 1.6;	refShip.Height.Bombs.DY		= 1.25;
	refShip.Height.Grapes.Y				= 2.75;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 13.2;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 1.6;	refShip.Height.Balls.DY		= 1.25;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Бригантина Brigantine
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BRIGANTINE]);
	refShip.Name            			= "Brigantine";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight						= Tonnes2CWT(320);	
	refShip.Capacity        			= 1900;
	refShip.CannonsQuantity				= 16; 
	refShip.CannonsQuantityMin				= 12;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;		
	refShip.MaxCrew         			= 160;
	refShip.OptCrew         			= 130;
	refShip.MinCrew         			= 23;
	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 56.0;
	refShip.Price           			= 44900;
	refShip.HP              			= 2700;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.40;
	
	refship.CabinType         			= "Cabin_Medium"; 
	refship.DeckType           = "Medium";	

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y			= 13.2;		refShip.Height.Knippels.DY	= 11.6;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Военная Бригантина ArmedBrigantine
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ARMEDBRIGANTINE]);
	refShip.Name            			= "ArmedBrigantine";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(350);	
	refShip.Capacity        			= 2100;
	refShip.CannonsQuantity				= 16;
	refShip.CannonsQuantityMin				= 12;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 170;
	refShip.OptCrew         			= 140;
	refShip.MinCrew         			= 26;
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 45400;
	refShip.HP              			= 2900;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;
	
	refship.WaterLine				= 0.1;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;

	refship.WindAgainstSpeed   			= 1.40;
	
	refship.CabinType         			= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";	

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 17.0;		refShip.Height.Knippels.DY	= 12.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Боевая Бригантина BattleBrigantine
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLEBRIGANTINE]);
	refShip.Name            			= "BattleBrigantine";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(380);	
	refShip.Capacity        			= 2300;
    	refShip.CannonsQuantity				= 16;
	refShip.CannonsQuantityMin				= 12;
    	refShip.rcannon 							= 7;
    	refShip.lcannon 							= 7;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 2;	
	refShip.MaxCrew         			= 180;
	refShip.OptCrew         			= 150;
	refShip.MinCrew         			= 29;
	refShip.SpeedRate       			= 13.0;
	refShip.TurnRate        			= 47.0;
	refShip.Price           			= 46800;
	refShip.HP              			= 3100;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
    refShip.WaterLine							= 0.3;
    refShip.SpeedDependWeight			= 0.5;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.40;
	
	refship.CabinType         			= "Old_Cabin_Medium"; 
	refship.DeckType           = "Medium";	

    refShip.InertiaAccelerationX	= 5.5;
    refShip.InertiaBrakingX		= 5.5;
    refShip.InertiaAccelerationY	= 8;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 6.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 17.0;
    refShip.Height.Knippels.DY	= 11.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.8;
    refShip.GeraldSails.rey_b3.vscale		= 0.8;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width	= "4.0, 6.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
    	
	///////////////////////////////////////////////////////////////////////////
	//// Бриг Brig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BRIG]);
	refShip.Name            			= "Brig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight					= Tonnes2CWT(300);
	refShip.Capacity        			= 1700;
	refShip.CannonsQuantity				= 16; 
	refShip.CannonsQuantityMin				= 12;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 150;
	refShip.OptCrew         			= 120;
	refShip.MinCrew         			= 20;
	
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 53.0;
	refShip.Price           			= 43700;
	refShip.HP              			= 2500;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.55;

	refship.CabinType         			= "Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 3.3;		refShip.Height.Grapes.DY	= 1.6;
	refShip.Height.Knippels.Y			= 16.5;		refShip.Height.Knippels.DY	= 14.0;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 2.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Усиленный бриг Warbrig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARBRIG]);
	refShip.Name            			= "Warbrig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 3500;
    	refShip.CannonsQuantity		= 24;
	refShip.CannonsQuantityMin				= 20;
    	refShip.rcannon 					= 10;
    	refShip.lcannon 					= 10;
    	refShip.fcannon 					= 2;
    	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 240;
	refShip.OptCrew         			= 210;
	refShip.MinCrew         			= 47;
	
	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 52300;
	refShip.HP              			= 4100;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

    	refShip.Rocking.y = 0.5;
    	refShip.Rocking.az = 0.04;
	
	refShip.WaterLine				= 0.4;
    	refShip.SpeedDependWeight			= 0.27;
    	refShip.SubSeaDependWeight			= 0.3;
    	refShip.TurnDependWeight			= 0.3;

	refship.WindAgainstSpeed   		= 0.55;

	refship.CabinType          		= "Cabin_Medium"; 
	refship.DeckType           = "Medium";	

    refShip.InertiaAccelerationX	= 6.2;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 10;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 17.5;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.8;
    refShip.GeraldSails.rey_b3.vscale		= 0.8;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width	= "4.0, 6.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкий бриг Fastbrig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FASTBRIG]);
	refShip.Name            			= "Fastbrig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1500;
	refShip.CannonsQuantity		= 16;
	refShip.CannonsQuantityMin		= 12;
    	refShip.rcannon 							= 6;
    	refShip.lcannon 							= 6;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 140;
	refShip.OptCrew         			= 110;
	refShip.MinCrew         			= 17;
	
	refShip.SpeedRate       			= 15.0;
	refShip.TurnRate        			= 59.0;
	refShip.Price           			= 42400;
	refShip.HP              			= 2300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

    	refShip.Rocking.y = 0.5;
    	refShip.Rocking.az = 0.04;
	
	refShip.WaterLine					= 0.3;
    	refShip.SpeedDependWeight			= 0.27;
    	refShip.SubSeaDependWeight			= 0.8;
    	refShip.TurnDependWeight			= 0.3;

	refship.WindAgainstSpeed   			= 0.55;

	refship.CabinType          		= "Cabin_Small"; 
	refship.DeckType           = "Medium";	
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Торговый бриг Tradebrig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TRADEBRIG]);
	refShip.Name            			= "Tradebrig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight					= Tonnes2CWT(190);
	refShip.Capacity        			= 2300;
	refShip.CannonsQuantity			= 14;
	refShip.CannonsQuantityMin			= 10;
    	refShip.rcannon 				= 7;
    	refShip.lcannon 				= 7;
    	refShip.fcannon 				= 0;
    	refShip.bcannon 				= 0;

	refShip.MaxCrew         			= 135;
	refShip.OptCrew         			= 90;
	refShip.MinCrew         			= 21;	
	
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 56.0;
	refShip.Price           			= 43200;
	refShip.HP              			= 1700;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War				= false;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
  	refShip.WaterLine			= 0.0;
    	refShip.SpeedDependWeight		= 0.27;
    	refShip.SubSeaDependWeight		= 0.5;
    	refShip.TurnDependWeight		= 0.3;
	refship.WindAgainstSpeed   	= 0.55;

	refship.CabinType          = "Old_Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
    refShip.InertiaAccelerationX	= 5.5;
    refShip.InertiaBrakingX		= 5.5;
    refShip.InertiaAccelerationY	= 7;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 15.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale	= 0.8;
    refShip.GeraldSails.rey_b3.vscale	= 0.8;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 12;
    refShip.Track1.Width		= "2.0, 3.0";
    refShip.Track1.Speed		= "6.0, 8.0";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 7.5;
    refShip.Track2.Width		= "4.0, 6.0";
    refShip.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Военный бриг Armedbrig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ARMEDBRIG]);
	refShip.Name            			= "Armedbrig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight 			= Tonnes2CWT(290);
	refShip.Capacity        			= 2500;
    	refShip.CannonsQuantity 		= 18;
	refShip.CannonsQuantityMin		= 14;
    	refShip.rcannon 							= 9;
    	refShip.lcannon 							= 9;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 190;
	refShip.OptCrew         			= 160;
	refShip.MinCrew         			= 32;
	
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 47600;
	refShip.HP              			= 3300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
    	refShip.WaterLine = -0.32;
    	refShip.SpeedDependWeight = 0.3;
    	refShip.SubSeaDependWeight = 0.6;
    	refShip.TurnDependWeight = 0.4;
	refship.WindAgainstSpeed   			= 0.55;

	refship.CabinType         			= "Old_Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
    refShip.InertiaAccelerationX = 0.2;
    refShip.InertiaBrakingX = 2.0;
    refShip.InertiaAccelerationY = 12;
    refShip.InertiaBrakingY = 9;
    refShip.InertiaAccelerationZ = 6.0;
    refShip.InertiaBrakingZ = 4.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 1.0;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 15.0;
    refShip.Height.Knippels.DY = 10.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 1.0;

    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b2.vscale = 0.8;
    refShip.GeraldSails.rey_b3.vscale = 0.8;

    refShip.Track.Enable = true;
    refShip.Track1.ZStart = 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width = "2.0, 3.0";
    refShip.Track1.Speed = "6.0, 8.0";

    refShip.Track2.ZStart = -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width = "4.0, 6.0";
    refShip.Track2.Speed = "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Боевой бриг Battlebrig
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLEBRIG]);
	refShip.Name            			= "Battlebrig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight 			= Tonnes2CWT(400);

	refShip.Capacity        			= 2700;
    	refShip.CannonsQuantity 		= 18;
	refShip.CannonsQuantityMin		= 14;
    	refShip.rcannon 							= 8;
    	refShip.lcannon 							= 8;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 2;

	refShip.MaxCrew         			= 200;
	refShip.OptCrew         			= 170;
	refShip.MinCrew         			= 35;

	refShip.SpeedRate       			= 12.0;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 48500;
	refShip.HP              			= 3500;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
    	refShip.WaterLine = 0.45;
    	refShip.SpeedDependWeight = 0.3;
    	refShip.SubSeaDependWeight = 0.6;
    	refShip.TurnDependWeight = 0.3;
	refship.WindAgainstSpeed   			= 0.55;

	refship.CabinType         			= "Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
    refShip.InertiaAccelerationX	= 0.2;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 12;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 1.0;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 17.0;
    refShip.Height.Knippels.DY = 12.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 1.0;

    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b2.vscale = 0.8;
    refShip.GeraldSails.rey_b3.vscale = 0.8;

    refShip.Track.Enable = true;
    refShip.Track1.ZStart = 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width = "2.0, 3.0";
    refShip.Track1.Speed = "6.0, 8.0";

    refShip.Track2.ZStart = -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width = "4.0, 6.0";
    refShip.Track2.Speed = "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;


///////////////////////////////////////////////////////////////////////////
	//// Торговый корабль TradeShip
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TRADESHIP]);
	refShip.Name            			= "TradeShip";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      		= 16;
	refShip.Weight					= Tonnes2CWT(700);
	
	refShip.Capacity        			= 3900;
    	refShip.CannonsQuantity				= 20;
	refShip.CannonsQuantityMin				= 16;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 215;
	refShip.OptCrew         			= 170;
	refShip.MinCrew         			= 45;	
	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 51800;
	refShip.HP              			= 3300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 25;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.45;

	refship.CabinType         			= "Old_Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Военная шхуна Schooner_W
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SCHOONER_W]);
	refShip.Name            			= "Schooner_W";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	
	refShip.Weight					= Tonnes2CWT(220);
	refShip.Capacity        			= 2900;
	refShip.CannonsQuantity				= 18; 
	refShip.CannonsQuantityMin				= 14;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 210;
	refShip.OptCrew         			= 180;
	refShip.MinCrew         			= 38;
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 44.0;
	refShip.Price           			= 49300;
	refShip.HP              			= 3700;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.03;

	refship.WaterLine					= -0.2;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.15;
	
	refship.CabinType         			= "Cabin_Medium"; 
	refship.DeckType           = "Medium";	
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.7;		refShip.Height.Bombs.DY		= 0.8;
	refShip.Height.Grapes.Y				= 2.9;		refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y			= 13.9;		refShip.Height.Knippels.DY	= 13.7;
	refShip.Height.Balls.Y				= 1.7;		refShip.Height.Balls.DY		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;


///////////////////////////////////////////////////////////////////////////
	//// Боевая Шхуна WarSchooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARSCHOONER]);
	refShip.Name            			= "WarSchooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(1000);
	refShip.Capacity        			= 3300;

	refShip.CannonsQuantity				= 24;
	refShip.CannonsQuantityMin				= 20;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;

	refShip.MaxCrew         			= 230;
	refShip.OptCrew         			= 200;
	refShip.MinCrew         			= 44;

	refShip.SpeedRate				= 10.0;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 51600;
	refShip.HP              			= 3900;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine					= -1.1;

	refship.SpeedDependWeight			= 0.1;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;

	refship.WindAgainstSpeed   			= 1.15;
	
	refship.CabinType          		= "Old_Cabin_Medium";
	refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y = 1.0; 
	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; 
	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 13.0; 
	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; 
	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

    	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	refship.nation.spain	= false;

///////////////////////////////////////////////////////////////////////////
	//// Быстрая шхуна Fastschooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FASTSCHOONER]);
	refShip.Name            			= "Fastschooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;	
	
    	refShip.Weight					= Tonnes2CWT(220);
	refShip.Capacity        			= 1700;

    	refShip.CannonsQuantity			= 10;
	refShip.CannonsQuantityMin			= 6;
    refShip.rcannon 					= 4;
    refShip.lcannon 					= 4;
    refShip.fcannon 					= 0;
    refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 105;
	refShip.OptCrew         			= 60;
	refShip.MinCrew         			= 12;	
	refShip.SpeedRate				= 16.0;
	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 40900;
	refShip.HP              			= 1100;
	refShip.SP              			= 100;	

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 12;

    refShip.Rocking.y = 0.4;
    refShip.Rocking.az = 0.03;

    refShip.WaterLine					= 0.3;

    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.7;
    refShip.TurnDependWeight			= 0.3;
    refship.WindAgainstSpeed   			= 1.15;

	refship.CabinType          			= "Old_Cabin_Medium";
	refship.DeckType           = "Medium";
	
    refShip.InertiaAccelerationX	= 5.6;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 7;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 15.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 8;
    refShip.Track1.Width	= "1.2, 2.2";
    refShip.Track1.Speed	= "7.2, 8.2";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6;
    refShip.Track2.Width	= "2.2, 3.2";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Патрульная шхуна PatrolSchooner
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_PATROLSCHOONER]);
	refShip.Name            			= "PatrolSchooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(170);
	refShip.Capacity        			= 1100;

	refShip.CannonsQuantity		= 14;
	refShip.CannonsQuantityMin			= 10;
    	refShip.rcannon 							= 7;
    	refShip.lcannon 							= 7;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;

	refShip.MaxCrew         			= 120;
	refShip.OptCrew         			= 90;
	refShip.MinCrew         			= 11;
	refShip.SpeedRate				= 16.0;

	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 40700;

	refShip.HP              			= 1900;

	refShip.SP              			= 100;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.03;

	refShip.WaterLine					= -0.2;

    	refShip.SpeedDependWeight	= 0.2;
    	refShip.SubSeaDependWeight	= 0.2;
    	refShip.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   			= 1.15;

	refship.CabinType          		= "Cabin_Medium";
	refship.DeckType           		= "Medium";
	
    refShip.InertiaAccelerationX	= 0.2;
    refShip.InertiaBrakingX		= 2.0;
    refShip.InertiaAccelerationY	= 12;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.Height.Bombs.Y		= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y		= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 15.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.20;
    refShip.Track1.LifeTime 	= 8;
    refShip.Track1.Width		= "1.2, 2.2";
    refShip.Track1.Speed		= "7.2, 8.2";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 6;
    refShip.Track2.Width		= "2.2, 3.2";
    refShip.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france		= true;
	refship.nation.spain		= true;
	refship.nation.holland	= true;
	refship.nation.pirate		= false;

///////////////////////////////////////////////////////////////////////////
	//// Галеон SmallGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SMALLGALEON]);
	refShip.Name            			= "SmallGaleon";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight					= Tonnes2CWT(370);
	refShip.Capacity        			= 3100;
    	refShip.CannonsQuantity						= 18;
	refShip.CannonsQuantityMin						= 14;
    	refShip.rcannon 							= 8;
    	refShip.lcannon 							= 8;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 220;
	refShip.OptCrew         			= 190;
	refShip.MinCrew         			= 41;

	refShip.SpeedRate				= 11.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 50800;
	refShip.HP              			= 3700;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
    	refShip.WaterLine				= -0.7;
    	refShip.SpeedDependWeight			= 0.15;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          		= "Old_Cabin_Medium"; 
	refship.DeckType           			= "Medium";
		
    refShip.InertiaAccelerationX		= 3.2;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY		= 5;
    refShip.InertiaBrakingY			= 6;
    refShip.InertiaAccelerationZ		= 4.0;
    refShip.InertiaBrakingZ			= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.5;		refShip.Height.Knippels.DY		= 12.5;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 16.5;
    refShip.Track1.Width	= "5.2, 7.3";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 10.5;
    refShip.Track2.Width	= "6.0, 8.0";
    refShip.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france		= true;
	refship.nation.spain		= true;
	refship.nation.holland	= true;
	refship.nation.pirate		= true;

	///////////////////////////////////////////////////////////////////////////
	//// Лёгкий корвет LightCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTCORVETTE]);
	refShip.Name            			= "LightCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight					= Tonnes2CWT(550);
	refShip.Capacity        			= 1300;

	refShip.CannonsQuantity				= 16;
	refShip.CannonsQuantityMin				= 12;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;
	
	refShip.MaxCrew         			= 130;
	refShip.OptCrew         			= 100;
	refShip.MinCrew         			= 14;
	
	refShip.SpeedRate				= 15.5;
	refShip.TurnRate        			= 62.0;
	refShip.Price           			= 41500;
	refShip.HP              			= 2100;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= -0.5;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   		= 0.60;

	refship.CabinType          		= "Old_Cabin_Medium";
	refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 16.333;	refShip.Height.Knippels.DY	= 14.425;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкий пинас LightPinnace
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTPINNACE]);
	refShip.Name            			= "LightPinnace";
	refship.Soundtype					= "frigate";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;	
	refShip.Weight					= Tonnes2CWT(470);	
	refShip.Capacity        			= 2700;	
    	refShip.CannonsQuantity			= 14;
	refShip.CannonsQuantityMin			= 10;
    	refShip.rcannon 							= 6;
    	refShip.lcannon 							= 6;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 155;
	refShip.OptCrew         			= 110;
	refShip.MinCrew         			= 27;	

	refShip.SpeedRate				= 13.5;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 45100;
	refShip.HP              			= 2100;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;

    refShip.WaterLine							= 0.22;
    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.8;
    refShip.TurnDependWeight			= 0.25;
    refship.WindAgainstSpeed   			= 0.65;
    refship.CabinType          			= "Cabin_Medium";
    refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 4.2;
    refShip.InertiaBrakingX		= 4.0;
    refShip.InertiaAccelerationY	= 5;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 4.6;
    refShip.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.5;		refShip.Height.Grapes.DY	= 2.7;
	refShip.Height.Knippels.Y			= 27.1;		refShip.Height.Knippels.DY	= 20.7;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;	
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b1		= 1;
    refShip.GeraldSails.rey_b1.vscale		= 0.85;
    refShip.GeraldSails.rey_b2.vscale		= 0.65;
    refShip.GeraldSails.rey_b3.vscale		= 0.65;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.30;
    refShip.Track1.LifeTime = 14.5;
    refShip.Track1.Width	= "5.7, 7.9";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 8.5;
    refShip.Track2.Width	= "10.0, 12.0";
    refShip.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Полакка Polacca
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_POLACCA]);
	refShip.Name            			= "Polacca";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      		= 18;
	refShip.Weight				= Tonnes2CWT(300);
	refShip.Capacity        			= 2500;	
	refShip.CannonsQuantity			= 14;
	refShip.CannonsQuantityMin			= 10;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;

	refShip.MaxCrew         			= 145;
	refShip.OptCrew         			= 100;
	refShip.MinCrew         			= 24;	
	refShip.SpeedRate				= 14.0;
	refShip.TurnRate        			= 53.0;
	refShip.Price           			= 44300;
	refShip.HP              			= 1900;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 10;
	
    	refShip.Rocking.y = 0.5;
    	refShip.Rocking.az = 0.037;
	
	refship.WaterLine					= -0.35;

    refShip.SpeedDependWeight			= 0.4;
    refShip.SubSeaDependWeight			= 0.7;
    refShip.TurnDependWeight			= 0.6;
	
	refship.WindAgainstSpeed   			= 1.35;

refship.DeckType           			= "Medium";
refship.CabinType          = "Old_Cabin_Medium"; 

    refShip.InertiaAccelerationX 	= 3.7;
    refShip.InertiaBrakingX		= 3.9;
    refShip.InertiaAccelerationY	 = 5;
    refShip.InertiaBrakingY		= 7;
    refShip.InertiaAccelerationZ	 = 5.0;
    refShip.InertiaBrakingZ		= 6.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 16.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 8;
    refShip.Track1.Width	= "1.2, 2.2";
    refShip.Track1.Speed	= "7.2, 8.2";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6;
    refShip.Track2.Width	= "2.2, 3.2";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Лёгкий галеон Galeon_l
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_GALEON_L]);
	refShip.Name            			= "Galeon_l";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(720);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity			= 20; 
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 240;
	refShip.OptCrew					= 195;
	refShip.MinCrew         			= 32;
	refShip.SpeedRate				= 14.5;
	refShip.TurnRate        			= 54.0;
	refShip.Price           			= 67500;
	refShip.HP              			= 3600;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.85;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.95;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          		= "Cabin_Medium2"; 
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.7;		refShip.Height.Knippels.DY	= 12.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Испанский галеон SpaGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SPAGALEON]);
	refShip.Name            			= "SpaGaleon";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(900);
	refShip.Capacity        			= 4500;
    	refShip.CannonsQuantity			= 30;
	refShip.CannonsQuantityMin			= 24;
    	refShip.rcannon 					= 14;
    	refShip.lcannon 					= 14;
    	refShip.fcannon 					= 0;
    	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 315;
	refShip.OptCrew					= 270;
	refShip.MinCrew         			= 52;
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 39.0;
	refShip.Price           			= 72800;
	refShip.HP              			= 5100;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
    	refShip.lowpolycrew 					= 20;
	
    	refShip.Rocking.y 		= 0.65;
    	refShip.Rocking.az 		= 0.055;
	
    	refShip.WaterLine					= 0.0;
    	refShip.SpeedDependWeight				= 0.15;
    	refShip.SubSeaDependWeight				= 0.3;
    	refShip.TurnDependWeight				= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          		= "Cabin_Medium2"; 
	refship.DeckType           			= "Medium";
		
    refShip.InertiaAccelerationX	= 3.5;
    refShip.InertiaBrakingX		= 3.5;
    refShip.InertiaAccelerationY	= 6;
    refShip.InertiaBrakingY		= 5;
    refShip.InertiaAccelerationZ	= 4.5;
    refShip.InertiaBrakingZ		= 4.5;
	
	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 25.4;		refShip.Height.Knippels.DY	= 22.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale	= 0.98;
    refShip.GeraldSails.rey_b3.vscale	= 0.8;

    refShip.Track.Enable		= true;
    refShip.Track1.ZStart		= 0.0;
    refShip.Track1.LifeTime 	= 14.5;
    refShip.Track1.Width		= "5.2, 7.3";
    refShip.Track1.Speed		= "5.5, 6.5";

    refShip.Track2.ZStart		= -0.15;
    refShip.Track2.LifeTime 	= 8.5;
    refShip.Track2.Width		= "6.0, 8.0";
    refShip.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Английский галеон EngGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ENGGALEON]);
	refShip.Name            			= "EngGaleon";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity        			= 3300;
    	refShip.CannonsQuantity					= 22;
	refShip.CannonsQuantityMin					= 16;
    	refShip.rcannon 							= 9;
    	refShip.lcannon 							= 9;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 255;
	refShip.OptCrew					= 210;
	refShip.MinCrew         			= 36;
	refShip.SpeedRate				= 14.0;
	refShip.TurnRate        			= 51.0;
	refShip.Price           			= 68200;
	refShip.HP              			= 3900;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
    refship.Rocking.y = 0.45;
    refship.Rocking.az = 0.035;
	
    refship.WaterLine					= 0.9;
    refship.SpeedDependWeight			= 0.15;
    refship.SubSeaDependWeight			= 0.6;
    refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          		= "Cabin_Medium2"; 
	refship.DeckType           			= "Medium";
		
    refship.InertiaAccelerationX	= 3.2;
    refship.InertiaBrakingX		= 3.0;
    refship.InertiaAccelerationY	= 5;
    refship.InertiaBrakingY		= 6;
    refship.InertiaAccelerationZ	= 4.0;
    refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 19.7;		refShip.Height.Knippels.DY	= 13.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refship.Track.Enable	= true;
    refship.Track1.ZStart	= 0.20;
    refship.Track1.LifeTime = 16.5;
    refship.Track1.Width	= "5.2, 7.3";
    refship.Track1.Speed	= "6.0, 8.0";

    refship.Track2.ZStart	= -0.15;
    refship.Track2.LifeTime = 10.5;
    refship.Track2.Width	= "6.0, 8.0";
    refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
          		
	///////////////////////////////////////////////////////////////////////////
	//// Корвет Corvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_CORVETTE]);
	refShip.Name            			= "Corvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight				= Tonnes2CWT(600);
	refShip.Capacity        			= 2700;
	refShip.CannonsQuantity			= 20; 
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 225;
	refShip.OptCrew						= 180;
	refShip.MinCrew         			= 28;
	
	refShip.SpeedRate				= 15.0;
	refShip.TurnRate        			= 57.0;
	refShip.Price           			= 65500;
	refShip.HP              			= 3300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 16.0;	refShip.Height.Knippels.DY	= 14.0;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Боевой корвет BattleCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLECORVETTE]);
	refShip.Name            			= "BattleCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(900);
	refShip.Capacity        			= 4800;
    	refShip.CannonsQuantity					= 32;
	refShip.CannonsQuantityMin					= 26;
    	refShip.rcannon 							= 15;
    	refShip.lcannon 							= 15;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 2;
	
	refShip.MaxCrew         			= 330;
	refShip.OptCrew					= 285;
	refShip.MinCrew         			= 56;
	
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 73500;
	refShip.HP              			= 5400;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;

    refShip.Rocking.y = 0.4;
    refShip.Rocking.az = 0.035;
	
    refShip.WaterLine							= 0.3;
    refShip.SpeedDependWeight			= 0.3;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "CabineHZ";
	refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 5.0;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 4;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 0.5;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 14.5;
    refShip.Height.Knippels.DY = 11.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 0.5;

    refShip.GeraldSails.rey_b1 = 1;
    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b1.vscale = 0.9;
    refShip.GeraldSails.rey_b2.vscale = 0.7;
    refShip.GeraldSails.rey_b3.vscale = 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 14.5;
    refShip.Track1.Width	= "3.7, 3.9";
    refShip.Track1.Speed	= "7.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 8.5;
    refShip.Track2.Width	= "8.0, 9.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Военный корвет WarCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARCORVETTE]);
	refShip.Name            			= "WarCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 3900;
    	refShip.CannonsQuantity				= 28;
	refShip.CannonsQuantityMin				= 22;
    	refShip.rcannon 							= 14;
    	refShip.lcannon 							= 14;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;
	
	refShip.MaxCrew         			= 285;
	refShip.OptCrew					= 240;
	refShip.MinCrew         			= 44;
	
	refShip.SpeedRate				= 13.0;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 70800;
	refShip.HP              			= 4500;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;

    refShip.Rocking.y = 0.4;
    refShip.Rocking.az = 0.035;
	
    	refShip.WaterLine				= 0.2;
    	refShip.SpeedDependWeight			= 0.3;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "CabineHZ";
	refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 5.0;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 4;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 0.5;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 13.5;
    refShip.Height.Knippels.DY = 10.5;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 0.5;

    refShip.GeraldSails.rey_b1 = 1;
    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b1.vscale = 0.9;
    refShip.GeraldSails.rey_b2.vscale = 0.7;
    refShip.GeraldSails.rey_b3.vscale = 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 14.5;
    refShip.Track1.Width	= "3.7, 3.9";
    refShip.Track1.Speed	= "7.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 8.5;
    refShip.Track2.Width	= "8.0, 9.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Быстрый корвет FastCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FASTCORVETTE]);
	refShip.Name            			= "FastCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(800);
	refShip.Capacity        			= 2400;
	refShip.CannonsQuantity			= 22; 
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 210;
	refShip.OptCrew					= 165;
	refShip.MinCrew         			= 24;
	
	refShip.SpeedRate				= 15.5;
	refShip.TurnRate        			= 60.0;
	refShip.Price           			= 63700;
	refShip.HP              			= 3000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine				= 0.15;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.38;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 19.333;	refShip.Height.Knippels.DY	= 15.425;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Французский корвет FrenchCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FRENCHCORVETTE]);
	refShip.Name            			= "FrenchCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(450);
	refShip.Capacity        			= 4200;
    	refShip.CannonsQuantity			= 30;
	refShip.CannonsQuantityMin			= 24;
    	refShip.rcannon 					= 12;
    	refShip.lcannon 					= 12;
    	refShip.fcannon 					= 2;
    	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 300;
	refShip.OptCrew					= 255;
	refShip.MinCrew         			= 48;
	
	refShip.SpeedRate				= 12.5;
	refShip.TurnRate        			= 42.0;
	refShip.Price           			= 71400;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
    refShip.WaterLine							= -0.15;
    refShip.SpeedDependWeight			= 0.3;
    refShip.SubSeaDependWeight			= 0.3;
    refShip.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 8.0;
    refShip.InertiaBrakingX		= 8.0;
    refShip.InertiaAccelerationY	= 8;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 16.0;	refShip.Height.Knippels.DY	= 14.0;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.17;
    refShip.Track1.LifeTime = 12.5;
    refShip.Track1.Width	= "4.0, 5.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6.5;
    refShip.Track2.Width	= "5.0, 7.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый корвет HeavyCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_HEAVYCORVETTE]);
	refShip.Name            			= "HeavyCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(600);
	refShip.Capacity        			= 5100;
	refShip.CannonsQuantity			= 32;
	refShip.CannonsQuantityMin			= 26;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	
	refShip.MaxCrew         			= 345;
	refShip.OptCrew					= 300;
	refShip.MinCrew         			= 60;
	
	refShip.SpeedRate				= 11.0;
	refShip.TurnRate        			= 33.0;
	refShip.Price           			= 74200;
	refShip.HP              			= 5700;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;
	
	refship.WaterLine						= -0.10;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          		= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 11.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Корсарский корвет CorsairCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_CORSAIRCORVETTE]);
	refShip.Name            			= "CorsairCorvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(600);
	refShip.Capacity        			= 3600;
    	refShip.CannonsQuantity			= 26;
	refShip.CannonsQuantityMin			= 20;
    	refShip.rcannon 							= 13;
    	refShip.lcannon 							= 13;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;
	
	refShip.MaxCrew         			= 270;
	refShip.OptCrew					= 225;
	refShip.MinCrew         			= 40;
	
	refShip.SpeedRate				= 13.5;
	refShip.TurnRate        			= 48.0;
	refShip.Price           			= 69600;
	refShip.HP              			= 4200;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
    	refShip.WaterLine = 0.0;
    	refShip.SpeedDependWeight = 0.3;
    	refShip.SubSeaDependWeight = 0.6;
    	refShip.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 1.0;
    refShip.Height.Grapes.Y				= 3.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 18.0;
    refShip.Height.Knippels.DY	= 10.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 1.0;

    refShip.InertiaAccelerationX	= 3.8;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY	= 10;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 4.0;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.17;
    refShip.Track1.LifeTime = 12.5;
    refShip.Track1.Width	= "4.0, 5.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6.5;
    refShip.Track2.Width	= "5.0, 7.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france 	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкий фрегат LightFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTFRIGATE]);
	refShip.Name            			= "LightFrigate";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(480);
	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity			= 32; 
	refShip.CannonsQuantityMin			= 26;
    	refShip.rcannon 							= 15;
    	refShip.lcannon 							= 15;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 0;

	refShip.MaxCrew         			= 375;
	refShip.OptCrew					= 330;
	refShip.MinCrew         			= 68;
	
	refShip.SpeedRate				= 10.0;
	refShip.TurnRate        			= 27.0;
	refShip.Price           			= 76700;
	refShip.HP              			= 6300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;

    	refShip.Rocking.y = 0.4;
    	refShip.Rocking.az = 0.035;
	
    	refShip.WaterLine				= 0.2;
    	refShip.SpeedDependWeight			= 0.3;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 6.0;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 7;
    refShip.InertiaBrakingY		= 4;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 5.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 0.5;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 17.0;
    refShip.Height.Knippels.DY = 12.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 0.5;

    refShip.GeraldSails.rey_b1 = 1;
    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b1.vscale = 0.9;
    refShip.GeraldSails.rey_b2.vscale = 0.7;
    refShip.GeraldSails.rey_b3.vscale = 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 14.5;
    refShip.Track1.Width	= "3.7, 3.9";
    refShip.Track1.Speed	= "7.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 8.5;
    refShip.Track2.Width	= "8.0, 9.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Английский фрегат EngFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ENGFRIGATE]);
	refShip.Name            			= "EngFrigate";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight					= Tonnes2CWT(470);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity			= 32; 
	refShip.CannonsQuantityMin			= 26;
    	refShip.rcannon 							= 14;
    	refShip.lcannon 							= 14;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;
	
	refShip.MaxCrew         			= 360;
	refShip.OptCrew					= 315;
	refShip.MinCrew         			= 64;
	
	refShip.SpeedRate				= 10.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 75100;
	refShip.HP              			= 6000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

    	refShip.Rocking.y = 0.6;
    	refShip.Rocking.az = 0.035;

    	refShip.WaterLine				= -0.25;
    	refShip.SpeedDependWeight			= 0.3;
    	refShip.SubSeaDependWeight			= 0.4;
    	refShip.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          		= "Cabin_Medium2";
	refship.DeckType           			= "Medium";
	
    refShip.InertiaAccelerationX	= 8.0;
    refShip.InertiaBrakingX		= 8.0;
    refShip.InertiaAccelerationY	= 6;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 6.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 0.5;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 14.0;
    refShip.Height.Knippels.DY = 11.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 0.5;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.17;
    refShip.Track1.LifeTime = 12.5;
    refShip.Track1.Width	= "4.0, 5.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6.5;
    refShip.Track2.Width	= "5.0, 7.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	////  Малый Ост-Индец SmallEastIndiaMan
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SMALLEASTINDIAMAN]);
	refShip.Name            		= "SmallEastIndiaMan";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;	
	refShip.Weight					= Tonnes2CWT(850);
	refShip.Capacity        			= 6600;
	refShip.CannonsQuantity			= 32;
	refShip.CannonsQuantityMin			= 26;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew					= 260;
	refShip.OptCrew         			= 220;
	refShip.MinCrew         			= 58;	
	refShip.SpeedRate				= 10.0;
	refShip.TurnRate        			= 21.0;
	refShip.Price           			= 68000;
	refShip.HP              			= 6900;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	
	refship.WaterLine				= 0.6;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.92;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
	
	refship.CabinType         	= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 18.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Купеческий корабль MerchantShip
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_MERCHANTSHIP]);
	refShip.Name            			= "MerchantShip";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;	
	refShip.Weight					= Tonnes2CWT(600);
	
	refShip.Capacity        					= 5400;
	refShip.CannonsQuantity					= 26;
	refShip.CannonsQuantityMin					= 20;
    	refShip.rcannon 							= 13;
    	refShip.lcannon 							= 13;
    	refShip.fcannon 							= 0;
    	refShip.bcannon 							= 0;
	refShip.MaxCrew					= 230;
	refShip.OptCrew         			= 190;
	refShip.MinCrew         			= 50;	
	refShip.SpeedRate       			= 11.0;
	refShip.TurnRate        			= 27.0;
	refShip.Price           			= 64600;
	refShip.HP              			= 5700;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 16;

    	refShip.Rocking.y = 0.8;
    	refShip.Rocking.az = 0.025;
	
    	refShip.WaterLine				= 0.2;
    	refShip.SpeedDependWeight			= 0.3;
    	refShip.SubSeaDependWeight			= 0.4;
    	refShip.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;

	refship.CabinType         	= "Cabin_Medium2"; 
	refship.DeckType           = "Medium";	
	
    refShip.InertiaAccelerationX	= 8.0;
    refShip.InertiaBrakingX		= 8.0;
    refShip.InertiaAccelerationY	= 6;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 1.0;
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale		= 0.7;
    refShip.GeraldSails.rey_b3.vscale		= 0.7;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.17;
    refShip.Track1.LifeTime = 12.5;
    refShip.Track1.Width	= "4.0, 5.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 6.5;
    refShip.Track2.Width	= "5.0, 7.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Торговый пинас TradePinnace
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_TRADEPINNACE]);
	refShip.Name            			= "TradePinnace";
	refship.Soundtype					= "frigate";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;	
	refShip.Weight					= Tonnes2CWT(950);
	
	refShip.Capacity        					= 6000;
    	refShip.CannonsQuantity					= 26;
	refShip.CannonsQuantityMin					= 20;
    	refShip.rcannon 							= 11;
    	refShip.lcannon 							= 11;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;

	refShip.MaxCrew					= 245;
	refShip.OptCrew         			= 205;
	refShip.MinCrew         			= 54;	
	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 24.0;
	refShip.Price           			= 66800;
	refShip.HP              			= 6300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 20;

    refShip.Rocking.y = 0.4;
    refShip.Rocking.az = 0.035;

    refShip.WaterLine					= 0.5;
    refShip.SpeedDependWeight			= 0.2;
    refShip.SubSeaDependWeight			= 0.8;
    refShip.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;

	refship.CabinType         			= "Cabin"; 
	refship.DeckType           = "Medium";	
	
    refShip.InertiaAccelerationX	= 3.2;
    refShip.InertiaBrakingX		= 3.0;
    refShip.InertiaAccelerationY	= 5;
    refShip.InertiaBrakingY		= 5;
    refShip.InertiaAccelerationZ	= 4.0;
    refShip.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 1.0;
	
    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b1		= 1;
    refShip.GeraldSails.rey_b1.vscale		= 0.85;
    refShip.GeraldSails.rey_b2.vscale		= 0.65;
    refShip.GeraldSails.rey_b3.vscale		= 0.65;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.30;
    refShip.Track1.LifeTime = 14.5;
    refShip.Track1.Width	= "5.7, 7.9";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 8.5;
    refShip.Track2.Width	= "10.0, 12.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	//////////////////////////////////////////////////////////////////////////
	//// Шебека XebekVML
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XEBEKVML]);
	refShip.Name						= "XebekVML";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(500);
	refShip.Capacity   					= 2500;
	refShip.CannonsQuantity				= 22;
	refShip.CannonsQuantityMin				= 16;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 181;
	refShip.OptCrew        				= 145;
	refShip.MinCrew        				= 22;
	
	refShip.SpeedRate      				= 16.0;
	refShip.TurnRate       				= 62.0;
	refShip.Price          				= 61000;
	refShip.HP             				= 3000;
	refShip.SP             				= 100;

	refship.CabinType          		= "Cabin_Medium2";
	refship.DeckType           			= "Medium";

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.55;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.10;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

//////////////////////////////////////////////////////////////////////////
	//// Военная шебека WarXebec
	//////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARXEBEC]);
	refShip.Name						= "WarXebec";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(250);
	refShip.Capacity   					= 2200;
    	refShip.CannonsQuantity					= 20;
	refShip.CannonsQuantityMin					= 14;
    	refShip.rcannon 							= 8;
    	refShip.lcannon 							= 8;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew        				= 166;
	refShip.OptCrew        				= 130;
	refShip.MinCrew        				= 18;
	
	refShip.SpeedRate      				= 16.5;
	refShip.TurnRate       				= 65.0;
	refShip.Price          				= 60500;
	refShip.HP             				= 2700;
	refShip.SP             				= 100;

	refship.CabinType          		= "Cabin_Medium2";
	refship.DeckType           			= "Medium";

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 8;

	refship.WindAgainstSpeed   			= 1.55;
		
    refShip.Rocking.y 				= 0.5;
    refShip.Rocking.az 				= 0.035;

    refShip.WaterLine 		= 0.1;
    refShip.SpeedDependWeight = 0.3;
    refShip.SubSeaDependWeight = 0.3;
    refShip.TurnDependWeight = 0.8;
	
    refShip.InertiaAccelerationX	= 5.2;
    refShip.InertiaBrakingX		= 5.0;
    refShip.InertiaAccelerationY	= 9;
    refShip.InertiaBrakingY		= 6;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ		= 6.0;

    refShip.Height.Bombs.Y				= 1.0;
    refShip.Height.Bombs.DY		= 0.5;
    refShip.Height.Grapes.Y				= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y			= 10.0;
    refShip.Height.Knippels.DY	= 8.0;
    refShip.Height.Balls.Y				= 1.0;
    refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 9;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "8.0, 10.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7;
    refShip.Track2.Width	= "3.0, 4.5";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

//////////////////////////////////////////////////////////////////////////
	//// Боевая шебека BattleXebec
	//////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLEXEBEC]);
	refShip.Name						= "BattleXebec";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(280);
	refShip.Capacity   					= 3100;
    	refShip.CannonsQuantity				= 26;
	refShip.CannonsQuantityMin				= 20;
    	refShip.rcannon 						= 11;
    	refShip.lcannon 						= 11;
    	refShip.fcannon 						= 2;
    	refShip.bcannon 						= 2;
	refShip.MaxCrew        				= 211;
	refShip.OptCrew        				= 175;
	refShip.MinCrew        				= 30;
	
	refShip.SpeedRate      				= 15.0;
	refShip.TurnRate       				= 56.0;
	refShip.Price          				= 64700;
	refShip.HP             				= 3600;
	refShip.SP             				= 100;

	refship.CabinType          		= "Cabin_Medium";
	refship.DeckType           			= "Medium";

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.55;
		
    refShip.Rocking.y	= 0.5;
    refShip.Rocking.az	= 0.04;

    refShip.WaterLine	= 0.4;
    refShip.SpeedDependWeight		= 0.3;
    refShip.SubSeaDependWeight		= 0.9;
    refShip.TurnDependWeight		= 0.3;
	
    refShip.InertiaAccelerationX	= 4.2;
    refShip.InertiaBrakingX	= 4.0;
    refShip.InertiaAccelerationY	= 5;
    refShip.InertiaBrakingY	= 5;
    refShip.InertiaAccelerationZ	= 6.0;
    refShip.InertiaBrakingZ	= 2.0;

    refShip.Height.Bombs.Y	= 1.0;
    refShip.Height.Bombs.DY	= 1.0;
    refShip.Height.Grapes.Y	= 2.0;
    refShip.Height.Grapes.DY	= 1.0;
    refShip.Height.Knippels.Y	= 18.0;
    refShip.Height.Knippels.DY	= 12.0;
    refShip.Height.Balls.Y		= 1.0;
    refShip.Height.Balls.DY	= 1.0;

    refShip.GeraldSails.rey_b2		= 1;
    refShip.GeraldSails.rey_b3		= 1;
    refShip.GeraldSails.rey_b2.vscale	= 0.8;
    refShip.GeraldSails.rey_b3.vscale	= 0.8;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width	= "4.0, 6.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

//////////////////////////////////////////////////////////////////////////
	//// Усиленная шебека ArmedXebec
	//////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ARMEDXEBEC]);
	refShip.Name						= "ArmedXebec";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(500);
	refShip.Capacity   					= 3400;
    	refShip.CannonsQuantity					= 30;
	refShip.CannonsQuantityMin					= 24;
   	refShip.rcannon 							= 13;
    	refShip.lcannon 							= 13;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;
	refShip.MaxCrew        				= 226;
	refShip.OptCrew        				= 190;
	refShip.MinCrew        				= 34;
	
	refShip.SpeedRate      				= 14.5;
	refShip.TurnRate       				= 53.0;
	refShip.Price          				= 66100;
	refShip.HP             				= 3900;
	refShip.SP             				= 100;

	refship.CabinType          		= "Cabin_Medium";
	refship.DeckType           			= "Medium";

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 40;

	refship.WindAgainstSpeed   		= 1.60;
		
    refShip.Rocking.y = 0.5;
    refShip.Rocking.az = 0.04;

    refShip.WaterLine					= -0.15;
    refShip.SpeedDependWeight			= 0.3;
    refShip.SubSeaDependWeight			= 0.6;
    refShip.TurnDependWeight			= 0.3;
	
    refShip.InertiaAccelerationX	= 4.5;
    refShip.InertiaBrakingX		= 5.5;
    refShip.InertiaAccelerationY	= 5;
    refShip.InertiaBrakingY		= 8;
    refShip.InertiaAccelerationZ	= 5.0;
    refShip.InertiaBrakingZ		= 6.0;

    refShip.Height.Bombs.Y = 1.0;
    refShip.Height.Bombs.DY = 1.0;
    refShip.Height.Grapes.Y = 2.0;
    refShip.Height.Grapes.DY = 1.0;
    refShip.Height.Knippels.Y = 16.0;
    refShip.Height.Knippels.DY = 10.0;
    refShip.Height.Balls.Y = 1.0;
    refShip.Height.Balls.DY = 1.0;

    refShip.GeraldSails.rey_b2 = 1;
    refShip.GeraldSails.rey_b3 = 1;
    refShip.GeraldSails.rey_b2.vscale = 0.8;
    refShip.GeraldSails.rey_b3.vscale = 0.8;

    refShip.Track.Enable	= true;
    refShip.Track1.ZStart	= 0.20;
    refShip.Track1.LifeTime = 12;
    refShip.Track1.Width	= "2.0, 3.0";
    refShip.Track1.Speed	= "6.0, 8.0";

    refShip.Track2.ZStart	= -0.15;
    refShip.Track2.LifeTime = 7.5;
    refShip.Track2.Width	= "4.0, 6.0";
    refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
    	
	///////////////////////////////////////////////////////////////////////////
	//// Полакр Polacre
	///////////////////////////////////////////////////////////////////////////	

	makeref(refShip,ShipsTypes[SHIP_POLACRE]);
	refShip.Name						= "Polacre";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight					= Tonnes2CWT(550);
	refShip.Capacity   					= 2800;
	refShip.CannonsQuantity			= 22; 
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 9;
	refShip.lcannon 					= 9;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 196;
	refShip.OptCrew        				= 160;
	refShip.MinCrew        				= 26;

	refShip.SpeedRate      				= 15.5;
	refShip.TurnRate       				= 59.0;
	refShip.Price          				= 62300;
	refShip.HP             				= 3300;
	refShip.SP             				= 100;

	refship.CabinType          		= "Cabin_Medium";
	refship.DeckType           			= "Medium";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.35;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый галеон HeavyGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_HEAVYGALEON]);
	refShip.Name            			= "HeavyGaleon";
	refship.Soundtype					= "corvette";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;	
	refShip.Weight					= Tonnes2CWT(2500);

	refShip.Capacity        			= 10300;
	refShip.CannonsQuantity				= 56;
	refShip.CannonsQuantityMin				= 48;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 525;
	refShip.OptCrew         			= 420;
	refShip.MinCrew         			= 60;	
	refShip.SpeedRate				= 11.0;
	refShip.TurnRate        			= 33.0;
	refShip.Price           			= 89900;
	refShip.HP              			= 9300;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;
	
	refship.WaterLine				= -0.45;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.1;
	refship.TurnDependWeight			= 0.2;

	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4;	refship.InertiaBrakingX		= 2.5;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 4.5;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 22.0;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;


///////////////////////////////////////////////////////////////////////////
	//// Военный галеон WarGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARGALEON]);
	refShip.Name            			= "WarGaleon";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;	
	refShip.Weight					= Tonnes2CWT(1100);

	refShip.Capacity        			= 8900;
	refShip.CannonsQuantity				= 40;
	refShip.CannonsQuantityMin				= 32;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 485;
	refShip.OptCrew         			= 380;
	refShip.MinCrew         			= 50;
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 39.0;
	refShip.Price           			= 82400;
	refShip.HP              			= 7900;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine				= -0.2;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;

	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;
	
	refShip.Height.Bombs.Y				= 3.3;		refShip.Height.Bombs.DY		= 1.1;
	refShip.Height.Grapes.Y				= 4.6;		refShip.Height.Grapes.DY	= 1.8;
	refShip.Height.Knippels.Y			= 22.0;		refShip.Height.Knippels.DY	= 16.0;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Боевой галеон BattleGaleon
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLEGALEON]);
	refShip.Name            			= "BattleGaleon";
	refship.Soundtype					= "corvette";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;	
	refShip.Weight					= Tonnes2CWT(600);

	refShip.Capacity        			= 9600;
    	refShip.CannonsQuantity			= 50;
	refShip.CannonsQuantityMin			= 42;
    	refShip.rcannon 					= 24;
    	refShip.lcannon 					= 24;
    	refShip.fcannon 					= 0;
    	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 505;
	refShip.OptCrew         			= 400;
	refShip.MinCrew         			= 55;	
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 86600;
	refShip.HP              			= 8600;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
    	refShip.Rocking.y = 0.45;
    	refShip.Rocking.az = 0.035;

    	refShip.WaterLine			= -0.5;

    	refShip.SpeedDependWeight			= 0.15;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.2;

	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
    	refShip.InertiaAccelerationX	= 2.8;
    	refShip.InertiaBrakingX		= 3.3;
    	refShip.InertiaAccelerationY	= 5;
    	refShip.InertiaBrakingY		= 6;
    	refShip.InertiaAccelerationZ	= 5.0;
    	refShip.InertiaBrakingZ		= 4.5;
	
	refShip.Height.Bombs.Y				= 3.3;		refShip.Height.Bombs.DY		= 1.1;
	refShip.Height.Grapes.Y				= 4.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 21.5;		refShip.Height.Knippels.DY	= 16.5;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
    	refShip.GeraldSails.rey_a2		= 1;
    	refShip.GeraldSails.rey_a3		= 1;
    	refShip.GeraldSails.rey_a2.vscale		= 0.7;
    	refShip.GeraldSails.rey_a3.vscale		= 0.7;

    	refShip.Track.Enable	= true;
    	refShip.Track1.ZStart	= 0.20;
    	refShip.Track1.LifeTime = 16.5;
    	refShip.Track1.Width	= "5.2, 7.3";
    	refShip.Track1.Speed	= "6.0, 8.0";

    	refShip.Track2.ZStart	= -0.15;
    	refShip.Track2.LifeTime = 10.5;
    	refShip.Track2.Width	= "6.0, 8.0";
    	refShip.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Усиленный корвет ArmedCorvette
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ARMEDCORVETTE]);
	refShip.Name            			= "ArmedCorvette";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1200);

	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity			= 42;
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;

	refShip.MaxCrew         			= 357;
	refShip.OptCrew         			= 270;
	refShip.MinCrew         			= 36;

	
	refShip.SpeedRate       			= 15.5;
	refShip.TurnRate        			= 59.0;
	refShip.Price           			= 82000;
	refShip.HP              			= 6400;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= -0.1;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          		= "CabineHZ"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 21.5;	refShip.Height.Knippels.DY	= 14.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Рейдер Raider
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_RAIDER]);
	refShip.Name            			= "Raider";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(920);
	refShip.Capacity        			= 4900;
	refShip.CannonsQuantity			= 34;	
	refShip.CannonsQuantityMin			= 26;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 317;
	refShip.OptCrew         			= 230;
	refShip.MinCrew         			= 26;

	refShip.SpeedRate				= 16.5;
	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 80000;
	refShip.HP              			= 5600;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";	

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Приватир Privateer
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_PRIVATEER]);
	refShip.Name            			= "Privateer";
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(860);
	refShip.Capacity        			= 6100;
	refShip.CannonsQuantity 			= 46;
	refShip.CannonsQuantityMin			= 38;
	refShip.rcannon 				= 20;
	refShip.lcannon 				= 20;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 4;
	
	refShip.MaxCrew         			= 377;
	refShip.OptCrew         			= 290;
	refShip.MinCrew         			= 41;

	refShip.SpeedRate       			= 15.0;
	refShip.TurnRate        			= 56.0;
	refShip.Price           			= 83600;
	refShip.HP              			= 6800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;

	refShip.lowpolycrew = 20;

	refship.Rocking.y 						= 0.5;
	refship.Rocking.az 						= 0.035;

	refship.WaterLine = -0.85;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   			= 0.65;

	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y = 2.7;			refShip.Height.Bombs.DY = 1.3;
	refShip.Height.Grapes.Y = 4.3;			refShip.Height.Grapes.DY = 2.1;
	refShip.Height.Knippels.Y = 13.5;		refShip.Height.Knippels.DY = 12.2;
	refShip.Height.Balls.Y = 2.7;			refShip.Height.Balls.DY = 1.3;
	
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable					= true;
	refship.Track1.ZStart					= 0.25;
	refship.Track1.LifeTime				 	= 16.5;
	refship.Track1.Width					= "6.0, 8.2";
	refship.Track1.Speed					= "9.0, 9.0";

	refship.Track2.ZStart					= 0.0;
	refship.Track2.LifeTime 				= 13.5;
	refship.Track2.Width					= "8.0, 9.0";
	refship.Track2.Speed					= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
		
///////////////////////////////////////////////////////////////////////////
	//// Линейный фрегат LineFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LINEFRIGATE]);
	refShip.Name            			= "LineFrigate";
	refship.Soundtype					= "manowar";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1900);
	refShip.Capacity        			= 10100;
	refShip.CannonsQuantity			= 68;	
	refShip.CannonsQuantityMin			= 60;
	refShip.rcannon 					= 32;
	refShip.lcannon 					= 32;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	

	refShip.MaxCrew         			= 577;
	refShip.OptCrew         			= 490;
	refShip.MinCrew         			= 91;
	
	refShip.SpeedRate       			= 10.0;
	refShip.TurnRate        			= 26.0;
	refShip.Price           			= 93400;
	refShip.HP              			= 10800;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;
	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX		= 4.5;
	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY		= 3.5;
	refship.InertiaBrakingY		= 3.0;
	refship.InertiaAccelerationZ		= 4.5;
	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 5.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 20.5;		refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
	refShip.GeraldSails.rey_b2			= 1.0;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.hscale	= 0.7;
		
	refShip.GeraldSails.rey_b3			= 1.0;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.hscale	= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Усиленный Фрегат ArmedFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_ARMEDFRIGATE]);
	refShip.Name            			= "ArmedFrigate";
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(2000);
	refShip.Capacity        			= 9300;
	refShip.CannonsQuantity			= 62;
	refShip.CannonsQuantityMin			= 54;
    	refShip.rcannon 							= 29;
    	refShip.lcannon 							= 29;
    	refShip.fcannon 							= 2;
    	refShip.bcannon 							= 2;

	refShip.MaxCrew         			= 537;
	refShip.OptCrew         			= 450;
	refShip.MinCrew         			= 81;
	
	refShip.SpeedRate       			= 11.0;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 91800;
	refShip.HP              			= 10000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
    	refShip.lowpolycrew = 20;

    	refShip.Rocking.y = 0.4;
    	refShip.Rocking.az = 0.035;

    	refShip.WaterLine				= -0.6;
    	refShip.SpeedDependWeight			= 0.4;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin";
	refship.DeckType           			= "Big";
		
    	refShip.InertiaAccelerationX	= 3.0;
    	refShip.InertiaBrakingX		= 3.0;
    	refShip.InertiaAccelerationY	= 6;
    	refShip.InertiaBrakingY		= 4;
    	refShip.InertiaAccelerationZ	= 3.0;
    	refShip.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 5.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 22.5;		refShip.Height.Knippels.DY	= 15.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
    	refShip.GeraldSails.rey_b2		= 1;
    	refShip.GeraldSails.rey_b3		= 1;
    	refShip.GeraldSails.rey_b1		= 1;
    	refShip.GeraldSails.rey_b1.vscale		= 0.85;
    	refShip.GeraldSails.rey_b2.vscale		= 0.65;
    	refShip.GeraldSails.rey_b3.vscale		= 0.65;

    	refShip.Track.Enable	= true;
    	refShip.Track1.ZStart	= 0.30;
    	refShip.Track1.LifeTime = 14.5;
    	refShip.Track1.Width	= "5.7, 7.9";
    	refShip.Track1.Speed	= "6.0, 8.0";

   	refShip.Track2.ZStart	= -0.15;
    	refShip.Track2.LifeTime = 8.5;
    	refShip.Track2.Width	= "10.0, 12.0";
    	refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Боевой фрегат BattleFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLEFRIGATE]);
	refShip.Name            			= "BattleFrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1000);
	refShip.Capacity        			= 8500;
	refShip.CannonsQuantity			= 56;
	refShip.CannonsQuantityMin			= 48;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 497;
	refShip.OptCrew         			= 410;
	refShip.MinCrew         			= 71;
	
	refShip.SpeedRate       			= 12.0;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 89300;
	refShip.HP              			= 9200;
	refShip.SP              			= 100;
	
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.5;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          = "CabineHZ";
	refship.DeckType           = "Big"; 

	refship.InertiaAccelerationX 	= 0.2; 	refship.InertiaBrakingX 	= 2.0;
	refship.InertiaAccelerationY 	= 10; 	refship.InertiaBrakingY 	= 4;
	refship.InertiaAccelerationZ 	= 4.0; 	refship.InertiaBrakingZ 	= 2.0;

	refShip.Height.Bombs.Y 	= 1.0; 
	refShip.Height.Bombs.DY 		= 0.5;
	refShip.Height.Grapes.Y 	= 2.0; 
	refShip.Height.Grapes.DY 	= 1.0;
	refShip.Height.Knippels.Y 	= 13.5; 	refShip.Height.Knippels.DY 	= 9.0;
	refShip.Height.Balls.Y 		= 1.0; 	refShip.Height.Balls.DY 		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Военный фрегат WarFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARFRIGATE]);
	refShip.Name            			= "WarFrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(950);
	refShip.Capacity        			= 7700;
	refShip.CannonsQuantity			= 52;
	refShip.CannonsQuantityMin			= 44;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 457;
	refShip.OptCrew         			= 370;
	refShip.MinCrew         			= 61;
	
	refShip.SpeedRate       			= 13.0;
	refShip.TurnRate        			= 44.0;
	refShip.Price           			= 87900;
	refShip.HP              			= 8400;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= -0.8;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin";
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.1;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.2;	refShip.Height.Knippels.DY	= 17.3;
	refShip.Height.Balls.Y				= 3.1;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый фрегат Frigate_h
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FRIGATE_H]);
	refShip.Name            			= "Frigate_h";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1200);
	refShip.Capacity        			= 7300;
	refShip.CannonsQuantity			= 50;	
	refShip.CannonsQuantityMin			= 42;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 6;	
	refShip.MaxCrew         			= 437;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 56;
	
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 47.0;
	refShip.Price           			= 86700;
	refShip.HP              			= 8000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 5.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;		refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Испанский фрегат SpaFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_SPAFRIGATE]);
	refShip.Name            			= "SpaFrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1000);
	refShip.Capacity        			= 8100;
	refShip.CannonsQuantity			= 52;
	refShip.CannonsQuantityMin			= 44;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 477;
	refShip.OptCrew         			= 390;
	refShip.MinCrew         			= 66;
	
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 88900;
	refShip.HP              			= 8800;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine				= -0.8;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin";
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.1;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 20.2;	refShip.Height.Knippels.DY	= 18.3;
	refShip.Height.Balls.Y				= 3.1;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Патрульный фрегат PatrolFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_PATROLFRIGATE]);
	refShip.Name            			= "PatrolFrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(900);
	refShip.Capacity        			= 6500;
	refShip.CannonsQuantity			= 46;
	refShip.CannonsQuantityMin			= 38;
	refShip.rcannon 					= 21;
	refShip.lcannon 					= 21;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 397;
	refShip.OptCrew         			= 310;
	refShip.MinCrew         			= 46;

	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 53.0;
	refShip.Price           			= 84600;
	refShip.HP              			= 7200;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refShip.WaterLine					 = -0.5;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;

	refship.CabinType          			= "CabineHZ"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 2.7;	refShip.Height.Bombs.DY		= 0.8;
	refShip.Height.Grapes.Y				= 3.2;	refShip.Height.Grapes.DY	= 1.6;
	refShip.Height.Knippels.Y			= 22.5;	refShip.Height.Knippels.DY	= 17.7;
	refShip.Height.Balls.Y				= 2.7;	refShip.Height.Balls.DY		= 0.8;
	
	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;


///////////////////////////////////////////////////////////////////////////
	//// Фрегат Frigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_FRIGATE]);
	refShip.Name            			= "Frigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(950);
	refShip.Capacity        			= 6900;
	refShip.CannonsQuantity			= 46;
	refShip.CannonsQuantityMin			= 38;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	
	refShip.MaxCrew         			= 417;
	refShip.OptCrew         			= 330;
	refShip.MinCrew         			= 51;

	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 85500;	
	refShip.HP              			= 7600;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.15;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.50;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.7;	refShip.Height.Bombs.DY		= 1.8;
	refShip.Height.Grapes.Y				= 5.2;	refShip.Height.Grapes.DY	= 2.6;
	refShip.Height.Knippels.Y			= 23.0;	refShip.Height.Knippels.DY	= 21.7;
	refShip.Height.Balls.Y				= 3.7;	refShip.Height.Balls.DY		= 1.8;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Корсарский фрегат CorsairFrigate
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_CORSAIRFRIGATE]);
	refShip.Name            			= "CorsairFrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight					= Tonnes2CWT(1000);
	refShip.Capacity        			= 5300;
	refShip.CannonsQuantity		= 38;
	refShip.CannonsQuantityMin		= 30;
	refShip.rcannon 				= 18;
	refShip.lcannon 				= 18;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 0;
	
	refShip.MaxCrew         			= 337;
	refShip.OptCrew         			= 250;
	refShip.MinCrew         			= 31;

	refShip.SpeedRate       			= 16.0;
	refShip.TurnRate        			= 62.0;
	refShip.Price           			= 81500;	
	refShip.HP              			= 6000;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 			= 20;	
	refship.Rocking.y 			= 0.4;
	refship.Rocking.az 			= 0.035;
	
	refship.WaterLine			= -0.35;

	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 1.0;
	refship.TurnDependWeight		= 0.3;
	refship.WindAgainstSpeed   		= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.9;
	refShip.GeraldSails.rey_b2.vscale	= 0.7;
	refShip.GeraldSails.rey_b3.vscale	= 0.7;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "3.7, 3.9";
	refship.Track1.Speed		= "7.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Военный корабль WarShip
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARSHIP]);
	refShip.Name            			= "WarShip";
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;   	
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      		= 36;
	refShip.Weight				= Tonnes2CWT(2000);
	refShip.Capacity        			= 8900;
	refShip.CannonsQuantity			= 58;	
	refShip.CannonsQuantityMin			= 50;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	

	refShip.MaxCrew         			= 517;
	refShip.OptCrew         			= 430;
	refShip.MinCrew         			= 76;

	refShip.SpeedRate       			= 11.5;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 90900;
	refShip.HP              			= 9600;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine					= 0.7;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.15;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 0.40;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.3;
	refShip.Height.Grapes.Y				= 8.3;		refShip.Height.Grapes.DY	= 4.1;
	refShip.Height.Knippels.Y			= 32.1;		refShip.Height.Knippels.DY	= 25.8;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

///////////////////////////////////////////////////////////////////////////
	//// Боевой корабль BattleShip
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLESHIP]);
	refShip.Name            			= "BattleShip";
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;   	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      		= 36;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity        			= 9700;
	refShip.CannonsQuantity			= 66;
	refShip.CannonsQuantityMin			= 58;
	refShip.rcannon 					= 30;
	refShip.lcannon 					= 30;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;

	refShip.MaxCrew         			= 557;
	refShip.OptCrew         			= 470;
	refShip.MinCrew         			= 86;

	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 92200;
	refShip.HP              			= 10400;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;
	
	refship.WaterLine		= 0.05;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 1.614;	refShip.Height.Bombs.DY		= 0.346;
	refShip.Height.Grapes.Y				= 2.694;	refShip.Height.Grapes.DY	= 1.666;
	refShip.Height.Knippels.Y			= 13.333;	refShip.Height.Knippels.DY	= 11.425;
	refShip.Height.Balls.Y				= 1.614;	refShip.Height.Balls.DY		= 0.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Лёгкий линкор LightLineship
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LIGHTLINESHIP]);
	refShip.Name            			= "LightLineship";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;  
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(2500);
	refShip.Capacity        			= 11000;
    	refShip.CannonsQuantity				= 70;
	refShip.CannonsQuantityMin				= 60;
    	refShip.rcannon 					= 32;
    	refShip.lcannon 					= 32;
    	refShip.fcannon 					= 4;
    	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 617;
	refShip.OptCrew         			= 530;
	refShip.MinCrew         			= 99;

	refShip.SpeedRate				= 14.0;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 105000;
	refShip.HP              			= 11500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
    	refShip.lowpolycrew = 24;
    

    	refShip.Rocking.y = 0.5;
    	refShip.Rocking.az = 0.035;

    	refShip.WaterLine				= -0.5;

    	refShip.SpeedDependWeight			= 0.35;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX = 3.5;		refship.InertiaBrakingX = 3.0;
	refship.InertiaAccelerationY = 2.5;		refship.InertiaBrakingY = 2.5;
	refship.InertiaAccelerationZ = 3.5;		refship.InertiaBrakingZ = 3.0;

	refShip.Height.Bombs.Y = 3.5;			refShip.Height.Bombs.DY = 1.7;
	refShip.Height.Grapes.Y = 4.8;			refShip.Height.Grapes.DY = 2.4;
	refShip.Height.Knippels.Y = 16.7;		refShip.Height.Knippels.DY = 14.8;
	refShip.Height.Balls.Y = 3.5;			refShip.Height.Balls.DY = 1.7;

    	refShip.GeraldSails.rey_b2		= 1;
    	refShip.GeraldSails.rey_b3		= 1;
    	refShip.GeraldSails.rey_b1		= 1;
    	refShip.GeraldSails.rey_b1.vscale		= 0.8;
    	refShip.GeraldSails.rey_b2.vscale		= 0.65;
    	refShip.GeraldSails.rey_b3.vscale		= 0.55;

    	refShip.Track.Enable	= true;
    	refShip.Track1.ZStart	= 0.25;
    	refShip.Track1.LifeTime = 9.5;
    	refShip.Track1.Width	= "7.0, 7.5";
    	refShip.Track1.Speed	= "8.0, 9.0";

    	refShip.Track2.ZStart	= -0.15;
    	refShip.Track2.LifeTime = 7.5;
    	refShip.Track2.Width	= "8.0, 10.0";
    	refShip.Track2.Speed	= "1.0, 2.0";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Линейный корабль Lineship
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LINESHIP]);
	refShip.Name            			= "Lineship";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;   
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(2500);
	refShip.Capacity        			= 11500;
	refShip.CannonsQuantity			= 78;
	refShip.CannonsQuantityMin			= 68;
	refShip.rcannon 				= 37;
	refShip.lcannon 				= 37;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;

	refShip.MaxCrew         			= 642;
	refShip.OptCrew         			= 555;
	refShip.MinCrew         			= 105;

	refShip.SpeedRate				= 13.5;
	refShip.TurnRate        			= 47.0;
	refShip.Price           			= 110000;
	refShip.HP              			= 12000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine					= -0.7;
	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 5.8;		refShip.Height.Bombs.DY		= 2.4;
	refShip.Height.Grapes.Y				= 7.2;		refShip.Height.Grapes.DY	= 5.1;
	refShip.Height.Knippels.Y			= 31.6;		refShip.Height.Knippels.DY	= 23.8;
	refShip.Height.Balls.Y				= 5.8;		refShip.Height.Balls.DY		= 2.4;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 		= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 		= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый линкор HeavyLineship
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_HEAVYLINESHIP]);
	refShip.Name            			= "HeavyLineship";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;  
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(2500);
	refShip.Capacity        			= 12500;
	refShip.CannonsQuantity			= 84;
	refShip.CannonsQuantityMin			= 74;
	refShip.rcannon 					= 40;
	refShip.lcannon 					= 40;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 692;
	refShip.OptCrew         			= 605;
	refShip.MinCrew         			= 117;

	refShip.SpeedRate				= 12.5;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 120000;
	refShip.HP              			= 13000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	

	refship.WaterLine		= -0.25;
	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed            = 0.60;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 5.8;		refShip.Height.Bombs.DY		= 2.4;
	refShip.Height.Grapes.Y				= 7.2;		refShip.Height.Grapes.DY	= 5.1;
	refShip.Height.Knippels.Y			= 31.6;		refShip.Height.Knippels.DY	= 23.8;
	refShip.Height.Balls.Y				= 5.8;		refShip.Height.Balls.DY		= 2.4;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Военный линкор WarLineship
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_WARLINESHIP]);
	refShip.Name            			= "WarLineship";
	refship.Soundtype					= "lineship";
	refShip.Class					= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(3200);
	refShip.Capacity        			= 12000;
	refShip.CannonsQuantity			= 80;	
	refShip.CannonsQuantityMin			= 70;
	refShip.rcannon 					= 36;
	refShip.lcannon 					= 36;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 6;
		
	refShip.MaxCrew         			= 667;
	refShip.OptCrew         			= 580;
	refShip.MinCrew         			= 111;
	
	refShip.SpeedRate				= 13.0;
	refShip.TurnRate        			= 44.0;
	refShip.Price           			= 115000;
	refShip.HP              			= 12500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine				= -0.4;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.75;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 6.8;		refShip.Height.Bombs.DY		= 3.4;
	refShip.Height.Grapes.Y				= 7.5;		refShip.Height.Grapes.DY	= 4.0;
	refShip.Height.Knippels.Y			= 33.6;		refShip.Height.Knippels.DY	= 24.8;
	refShip.Height.Balls.Y				= 6.8;		refShip.Height.Balls.DY		= 3.4;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b1				= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.7;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Боевой линкор BattleLineship
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_BATTLELINESHIP]);
	refShip.Name            			= "BattleLineship";
	refship.Soundtype					= "lineship";
	refShip.Class					= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(3200);
	refShip.Capacity        			= 12500;
	refShip.CannonsQuantity			= 96;
	refShip.CannonsQuantityMin			= 86;
	refShip.rcannon 					= 46;
	refShip.lcannon 					= 46;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 717;
	refShip.OptCrew         			= 630;
	refShip.MinCrew         			= 123;
	
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 125000;
	refShip.HP              			= 13000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 24;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	
	refShip.WaterLine					= -0.5;
	refShip.SpeedDependWeight			= 0.3;
	refShip.SubSeaDependWeight			= 1.15;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.25;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.3;
	refShip.Height.Grapes.Y				= 12.0;		refShip.Height.Grapes.DY	= 6.2;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 30.0;
	refShip.Height.Balls.Y				= 8.6;		refShip.Height.Balls.DY		= 4.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;
	refShip.GeraldSails.rey_a2.vscale		= 0.65;
	refShip.GeraldSails.rey_a3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
                           
	///////////////////////////////////////////////////////////////////////////
	//// Французский линкор LSHIP_FRA
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LSHIP_FRA]);
	refShip.Name            			= "LSHIP_FRA";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(3000);
	refShip.Capacity        			= 10500;
	refShip.CannonsQuantity			= 64;
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 				= 24;
	refShip.lcannon 				= 24;
	refShip.fcannon 				= 8;
	refShip.bcannon 				= 8;	

	refShip.MaxCrew         			= 597;
	refShip.OptCrew         			= 510;
	refShip.MinCrew         			= 95;

	refShip.SpeedRate				= 13.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 11200;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	
	refShip.lowpolycrew 					= 24;
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az			 		= 0.15;
		
	refship.WaterLine					= 0.2;
	refship.SpeedDependWeight				= 0.35;
	refship.SubSeaDependWeight				= 0.75;
	refship.TurnDependWeight				= 0.4;
	refship.WindAgainstSpeed   			= 0.35;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;
	
	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.7;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 16.5;
	refship.Track1.Width		= "6.0, 8.2";
	refship.Track1.Speed		= "9.0, 9.0";

	refship.Track2.ZStart		= 0.0;
	refship.Track2.LifeTime 	= 13.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Голландский линкор LSHIP_HOL
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LSHIP_HOL]);
	refShip.Name            			= "LSHIP_HOL";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(2800);
	refShip.Capacity        			= 13000;
    	refShip.CannonsQuantity			= 92;
	refShip.CannonsQuantityMin			= 82;
    	refShip.rcannon 				= 43;
    	refShip.lcannon 				= 43;
    	refShip.fcannon 				= 2;
    	refShip.bcannon 				= 4;	

	refShip.MaxCrew         			= 742;
	refShip.OptCrew         			= 655;
	refShip.MinCrew         			= 129;
	
	refShip.SpeedRate				= 11.5;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 130000;
	refShip.HP              			= 13500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	
    	refShip.lowpolycrew = 20;
    	refShip.Rocking.y = 0.5;
    	refShip.Rocking.az = 0.035;

    	refShip.WaterLine				= 0.3;
    	refShip.SpeedDependWeight			= 0.4;
    	refShip.SubSeaDependWeight			= 0.6;
    	refShip.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
		
    	refShip.InertiaAccelerationX	= 4.0;
    	refShip.InertiaBrakingX		= 3.0;
    	refShip.InertiaAccelerationY	= 6;
    	refShip.InertiaBrakingY		= 4;
    	refShip.InertiaAccelerationZ	= 4.0;
    	refShip.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 4.4;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 5.0;		refShip.Height.Grapes.DY	= 1.8;
	refShip.Height.Knippels.Y			= 27.8;		refShip.Height.Knippels.DY	= 25.2;
	refShip.Height.Balls.Y				= 1.4;		refShip.Height.Balls.DY		= 1.0;
	
    	refShip.GeraldSails.rey_b2		= 1;
    	refShip.GeraldSails.rey_b3		= 1;
    	refShip.GeraldSails.rey_b1		= 1;
    	refShip.GeraldSails.rey_b1.vscale		= 0.85;
    	refShip.GeraldSails.rey_b2.vscale		= 0.65;
    	refShip.GeraldSails.rey_b3.vscale		= 0.65;

    	refShip.Track.Enable	= true;
    	refShip.Track1.ZStart	= 0.30;
    	refShip.Track1.LifeTime = 14.5;
    	refShip.Track1.Width	= "5.7, 7.9";
    	refShip.Track1.Speed	= "6.0, 8.0";

    	refShip.Track2.ZStart	= -0.15;
    	refShip.Track2.LifeTime = 8.5;
    	refShip.Track2.Width	= "10.0, 12.0";
    	refShip.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Испанский линкор LSHIP_SPA
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LSHIP_SPA]);
	refShip.Name            			= "LSHIP_SPA";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(3000);
	refShip.Capacity        			= 13500;
	refShip.CannonsQuantity			= 108; 
	refShip.CannonsQuantityMin			= 98;
	refShip.rcannon 				= 51;
	refShip.lcannon 				= 51;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 4;	

	refShip.MaxCrew         			= 767;
	refShip.OptCrew         			= 680;
	refShip.MinCrew         			= 135;

	refShip.SpeedRate				= 11.0;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 135000;
	refShip.HP              			= 14000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War				= true;

	refShip.lowpolycrew 				= 28;
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refShip.WaterLine 				= -0.4;
	refShip.SpeedDependWeight			= 0.3;
	refShip.SubSeaDependWeight			= 0.9;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 4.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;		refShip.Height.Knippels.DY	= 14.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// Английский линкор LSHIP_ENG
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LSHIP_ENG]);
	refShip.Name            			= "LSHIP_ENG";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(4200);
	refShip.Capacity        			= 14000;
	refShip.CannonsQuantity			= 106;
	refShip.CannonsQuantityMin			= 96;
	refShip.rcannon 				= 51;
	refShip.lcannon 				= 51;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;	

	refShip.MaxCrew         			= 792;
	refShip.OptCrew         			= 705;
	refShip.MinCrew         			= 141;	

	refShip.SpeedRate				= 10.5;
	refShip.TurnRate        			= 29.0;

	refShip.Price           			= 140000;
	refShip.HP              			= 14500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;

	refShip.lowpolycrew 				= 28;
	refship.Rocking.y 				= 0.3;
	refship.Rocking.az 				= 0.02;

	refship.WaterLine				= 0.1;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.Height.Bombs.Y				= 7.3;		refShip.Height.Bombs.DY		= 3.0;
	refShip.Height.Grapes.Y				= 10.2;		refShip.Height.Grapes.DY	= 4.8;
	refShip.Height.Knippels.Y			= 34.2;		refShip.Height.Knippels.DY	= 29.3;
	refShip.Height.Balls.Y				= 7.3;		refShip.Height.Balls.DY		= 3.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.75;
	refShip.GeraldSails.rey_b2.vscale		= 0.75;
	refShip.GeraldSails.rey_b3.vscale		= 0.75;
	refShip.GeraldSails.rey_b2.hscale		= 0.75;
	refShip.GeraldSails.rey_b3.hscale		= 0.75;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;
	
	//////////////////////////////////////////////////////////////////////////
	//// КВЕСТОВЫЕ КОРАБЛИ
	//////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////
	//// Легкая шебека "Мэйфэнг" -квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MAYFANG]);
	refShip.Name					= "Mayfang";
	refship.Soundtype				= "lugger";
	refShip.Class					= 4;
	refShip.Cannon  				= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  			= 20;
	refShip.Weight					= Tonnes2CWT(270);
	refShip.Capacity   				= 1900;
	refShip.CannonsQuantity			= 20;	// 4,2,7,7
	refShip.CannonsQuantityMin		= 20;
	refShip.rcannon 				= 7;
	refShip.lcannon 				= 7;
	refShip.fcannon 				= 4;
	refShip.bcannon 				= 2;	
	refShip.MaxCrew        			= 177;
	refShip.OptCrew        			= 140;
	refShip.MinCrew        			= 20;
	
	refShip.SpeedRate      			= 17.0;
	refShip.TurnRate       			= 65.0;
	refShip.Price          			= 30500;
	refShip.HP             			= 1950;
	refShip.SP             			= 100;
	refship.CabinType          		= "Cabin_Medium";
	refship.Type.Merchant			= false;
	refship.Type.War				= true;
	refship.QuestShip				= true; 

	refShip.lowpolycrew				= 12;
	refship.WindAgainstSpeed   		= 1.60;
		
	refship.Rocking.y				= 0.5;
	refship.Rocking.az				= 0.04;
	
	refship.WaterLine				= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 2.5;			refShip.Height.Bombs.DY	= 1.5;
	refShip.Height.Grapes.Y	= 2.76;			refShip.Height.Grapes.DY	= 0.5;
	refShip.Height.Knippels.Y	= 14.4;		refShip.Height.Knippels.DY	= 7.8;
	refShip.Height.Balls.Y		= 2.5;		refShip.Height.Balls.DY	= 1.5;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//////////////////////////////////////////////////////////////////////////
	//// Приватирский кеч "Мираж" - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MIRAGE]);
	refShip.Name				= "Mirage";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 20;
	refShip.Weight				= Tonnes2CWT(290);
	refShip.Capacity   			= 2300;
	refShip.CannonsQuantity		= 22;	//	4,2,6,6
	refShip.CannonsQuantityMin	= 22;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8
	refShip.fcannon 			= 4;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 240;
	refShip.OptCrew        		= 180;
	refShip.MinCrew        		= 16;	
	refShip.SpeedRate      		= 16.0;
	refShip.TurnRate       		= 45.0;
	refShip.Price          		= 36900;
	refShip.HP             		= 2350;
	refShip.SP             		= 100;
	
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.40;
	
	refship.Rocking.y			= 0.5;
	refship.Rocking.az			= 0.04;
	
	refship.WaterLine				= -0.02;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.2;		refShip.Height.Bombs.DY	= 0.6;
	refShip.Height.Grapes.Y		= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y	= 17.7;		refShip.Height.Knippels.DY	= 16.7;
	refShip.Height.Balls.Y		= 1.2;		refShip.Height.Balls.DY	= 0.6;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//// Патрульный бриг "Валькирия"  - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_VALCIRIA]);
	refShip.Name				= "Valciria";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 20;
	refShip.Weight				= Tonnes2CWT(310);
	refShip.Capacity   			= 2000;
	refShip.CannonsQuantity		= 20;	// 2,2,8,8
	refShip.CannonsQuantityMin	= 20;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 252;
	refShip.OptCrew        		= 178;
	refShip.MinCrew        		= 22;	
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 55.0;
	refShip.Price          		= 35300;
	refShip.HP             		= 2650;
	refShip.SP             		= 100;

	refship.CabinType          	= "Cabin_Medium"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//// Патрульный бриг "Черная Горгулья"  - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_VALCIRIA_QUEST]);
	refShip.Name				= "Valciria_quest";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 24;
	refShip.Weight				= Tonnes2CWT(310);
	refShip.Capacity   			= 2400;
	refShip.CannonsQuantity		= 20;	// 2,2,8,8
	refShip.CannonsQuantityMin	= 20;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 251;
	refShip.OptCrew        		= 175;
	refShip.MinCrew        		= 22;	
	refShip.SpeedRate      		= 17.7;
	refShip.TurnRate       		= 58.0;
	refShip.Price          		= 39500;
	refShip.HP             		= 2850;
	refShip.SP             		= 100;
	refship.EmblemedSails.normalTex = "ships\parus_silk_k.tga";
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;

	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Малый фрегат "Гриффондор" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE_QUEST]);
	refShip.Name            			= "Corvette_quest";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(780);
	refShip.Capacity        			= 3800;
	refShip.CannonsQuantity				= 34;	// 2,4,14,14
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 					= 14;
	refShip.lcannon 					= 14;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 312;
	refShip.OptCrew         			= 250;
	refShip.MinCrew         			= 45;
	
	refShip.SpeedRate					= 15.75;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 41100;
	refShip.HP              			= 4000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.65;
	refship.CabinType          			= "Cabin_Medium2"; 

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.3;		refShip.Height.Bombs.DY		= 0.6;
	refShip.Height.Grapes.Y				= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 14.7;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y				= 1.3;		refShip.Height.Balls.DY		= 0.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Быстрый фрегат "Фортуна" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_L]);
	refShip.Name            			= "ArabellaShip";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 4600;
	refShip.CannonsQuantity				= 42;	// 4,4,17,17
	refShip.CannonsQuantityMin			= 42;
	refShip.rcannon 					= 17;
	refShip.lcannon 					= 17;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 425;
	refShip.OptCrew         			= 375;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.25;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 67000;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";	

	///////////////////////////////////////////////////////////////////////////
	//// Проклятый "Калеуче" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CURSED_FDM]);
	refShip.Name            			= "Flyingdutchman";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight						= Tonnes2CWT(1500);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 56;	// 6,4,23,23
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 					= 23;
	refShip.lcannon 					= 23;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew         			= 777;
	refShip.OptCrew         			= 622;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 6666;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships/parus_common.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 24;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "CabineFDM"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Копия "Калеуче" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FDM]);
	refShip.Name            			= "Flyingdutchman_l";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1500);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 56;	// 6,4,23,23
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 					= 23;
	refShip.lcannon 					= 23;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew         			= 777;
	refShip.OptCrew         			= 622;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 6600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships/parus_FDM.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 24;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "CabineFDM"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Линейный корабль "Реус де Сан-Педро" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_QUEST]);
	refShip.Name            			= "Santisima";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 8500;
	refShip.CannonsQuantity				= 106; // 6,8,38,38
	refShip.CannonsQuantityMin			= 106;
	refShip.rcannon 					= 46;
	refShip.lcannon 					= 46;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 8;	
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 190;
	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 241600;
	refShip.HP              			= 12600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships\parus_silk.tga";

	refship.CanEncounter 				= false;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.0;		refShip.Height.Bombs.DY		= 4.0;
	refShip.Height.Grapes.Y				= 9.7;		refShip.Height.Grapes.DY	= 4.8;
	refShip.Height.Knippels.Y			= 34.7;		refShip.Height.Knippels.DY	= 26.0;
	refShip.Height.Balls.Y				= 8.0;		refShip.Height.Balls.DY		= 4.0;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_c1				= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Тяжелый корвет " Зебра "
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE_QUESTT]);
	refShip.Name            			= "Corvette_questt";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight								= Tonnes2CWT(1200);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity				= 46;
	refShip.rcannon 							= 21;
	refShip.lcannon 							= 21;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 430;
	refShip.OptCrew         			= 360;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 19.15;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 277000;
	refShip.HP              			= 7000;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.00;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.EmblemedSails.normalTex = "ships\parus_silk_k.tga";
	refship.CabinType          = "CabineHZ"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= "ships/Gerald/quest/rodger.tga";
	refShip.GeraldSails.rey_b2		= "ships/Gerald/quest/rodger.tga";
	refShip.GeraldSails.rey_b3		= "ships/Gerald/quest/rodger.tga";
	refShip.GeraldSails.rey_b4		= "ships/Gerald/quest/rodger.tga";
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	// Быстрый фрегат "Месть королевы Анны" - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATEQVEENT]);
	refShip.Name            			= "FrigateQveent";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity				= 52;	// 4,4,21,21
	refShip.CannonsQuantityMin			= 50;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 500;
	refShip.OptCrew         			= 430;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.25;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 297000;
	refShip.HP              			= 6800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= -0.6;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.EmblemedSails.normalTex = "ships\parus_FrigateQveent.tga";
	refship.CabinType          			= "Cabin_Quest"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	// Быстрый фрегат "Черная Жемчужина" - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_QUEST]);
	refShip.Name            			= "Frigate_quest";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity				= 36;	// 2,2,16,16
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 370;
	refShip.OptCrew         			= 300;
	refShip.MinCrew         			= 40;
	
	refShip.SpeedRate       			= 17.45;
	refShip.TurnRate        			= 37.35;
	refShip.Price           			= 200700;
	refShip.HP              			= 6700;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= -0.6;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.EmblemedSails.normalTex = "ships\parus_pearl.tga";
	refship.CabinType          			= "CabineHG"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Курьерский люггер
	///////////////////////////////////////////////////////////////////////////

	makeref(refShip,ShipsTypes[SHIP_LUGGERR]);
	refShip.Name            			= "Luggerr";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(145);
	refShip.Capacity        			= 800;
	refShip.CannonsQuantity				= 12;
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 70;
	refShip.OptCrew         			= 45;
	refShip.MinCrew         			= 15;
	
	refShip.SpeedRate       			= 16.75;
	refShip.TurnRate        			= 67.0;
	refShip.Price           			= 25000;
	refShip.HP              			= 850;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;

	refShip.lowpolycrew 				= 8;
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az				 	= 0.035;
	
	refship.WaterLine					= 0.0;	
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.60;
	refship.CabinType          			= "Old_Cabin_Small";
	refship.DeckType           			= "Small";
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 1.5;	refShip.Height.Bombs.DY		= 0.7;
	refShip.Height.Grapes.Y				= 2.7;	refShip.Height.Grapes.DY	= 1.3;
	refShip.Height.Knippels.Y			= 13.4;	refShip.Height.Knippels.DY	= 9.7;
	refShip.Height.Balls.Y				= 1.5;	refShip.Height.Balls.DY		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Линейный корабль "Солей Руаяль" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOLEYRU]);
	refShip.Name            			= "SoleyRu";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 9500;
	refShip.CannonsQuantity				= 112;
	refShip.CannonsQuantityMin			= 102;
	refShip.rcannon 					= 52;// 4,4,51,51	4,4,50,50	4,4,49,49	4,4,48,48	4,4,47,47	4,4,46,46
	refShip.lcannon 					= 52;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 190;
	
	refShip.SpeedRate					= 13.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 271600;
	refShip.HP              			= 12600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex = "ships\parus_SoleyRu.tga";

	refship.CanEncounter 				= false;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.2;
	refShip.Height.Grapes.Y				= 9.7;		refShip.Height.Grapes.DY	= 4.8;
	refShip.Height.Knippels.Y			= 34.7;		refShip.Height.Knippels.DY	= 26.0;
	refShip.Height.Balls.Y				= 8.0;		refShip.Height.Balls.DY		= 4.2;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_c1				= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//// Пиратский бриг "Морской волк"  - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGMIRAGESW]);
	refShip.Name				= "BrigMirageSW";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber  		= 24;
	refShip.Weight				= Tonnes2CWT(310);
	refShip.Capacity   			= 2400;
	refShip.CannonsQuantity		= 22;	// 4,2,6,6
	refShip.CannonsQuantityMin	= 22;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8;
	refShip.fcannon 			= 4;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 230;
	refShip.OptCrew        		= 165;
	refShip.MinCrew        		= 22;	
	refShip.SpeedRate      		= 17.7;
	refShip.TurnRate       		= 58.0;
	refShip.Price          		= 29000;
	refShip.HP             		= 2850;
	refShip.SP             		= 100;
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 16.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;

	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//// Пиратский бриг "Стрела"  - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BrigArrow]);
	refShip.Name				= "BrigArrow";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 24;
	refShip.Weight				= Tonnes2CWT(300);
	refShip.Capacity   			= 2400;
	refShip.CannonsQuantity		= 26;	// 2,2,11,11
	refShip.CannonsQuantityMin	= 24;
	refShip.rcannon 			= 10;
	refShip.lcannon 			= 10;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 240;
	refShip.OptCrew        		= 155;
	refShip.MinCrew        		= 20;	
	refShip.SpeedRate      		= 16.2;
	refShip.TurnRate       		= 53.0;
	refShip.Price          		= 29000;
	refShip.HP             		= 2650;
	refShip.SP             		= 100;
	refship.EmblemedSails.normalTex = "ships\parus_silk_k.tga";
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;

	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Фрегат "Россия"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ROSSIYA]);
	refShip.Name            			= "Rossiya";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 36;	// 2,2,16,16
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 420;
	refShip.OptCrew         			= 360;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.25;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 200770;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	///////////////////////////////////////////////////////////////////////////
	//// Тяжелый корвет "Сюрприз"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SURPRISE]);
	refShip.Name            			= "Surprise";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 36;
	refShip.Weight								= Tonnes2CWT(1200);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 400;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 65;
	
	refShip.SpeedRate       			= 19.15;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 217700;
	refShip.HP              			= 7000;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.05;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;

	refship.CabinType          = "CabineHZ"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b4		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	////  "Летучий Голландец" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLYINGDUTCHMAN_h]);
	refShip.Name            			= "Flyingdutchman_h";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1500);
	refShip.Capacity        			= 5200;
	refShip.CannonsQuantity				= 60;	// 6,2,26,26
	refShip.CannonsQuantityMin			= 60;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 2;			
	refShip.MaxCrew         			= 777;
	refShip.OptCrew         			= 622;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 15.8;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 7600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships/parus_common_torn.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 24;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "CabineFDM"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Тяжёлый Полакр
	///////////////////////////////////////////////////////////////////////////	
	makeref(refShip,ShipsTypes[SHIP_POLACRE_QUEST]);
	refShip.Name						= "Polacre_q";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon  		= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber  				= 24;
	refShip.Weight						= Tonnes2CWT(550);
	refShip.Capacity   					= 2950;
	refShip.CannonsQuantity				= 24; // 2,2,10,10    2,2,9,9	2,2,7,7 
	refShip.CannonsQuantityMin			= 20;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 246;
	refShip.OptCrew        				= 195;
	refShip.MinCrew        				= 24;
	
	refShip.SpeedRate      				= 15.0;
	refShip.TurnRate       				= 50.0;
	refShip.Price          				= 27900;
	refShip.HP             				= 3450;
	refShip.SP             				= 100;

	refship.CabinType          			= "Cabin_Medium2";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.35;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

        ///////////////////////////////////////////////////////////////////////////
	//// Галеон Гроза морей
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LA_MARIANNA]);
	refShip.Name            			= "La_Marianna";
	refship.Soundtype					= "lineship";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 36;
	refShip.Weight						= Tonnes2CWT(1700);
	refShip.Capacity        			= 6666;
	
	refShip.CannonsQuantity				= 38;	// 2,4,16,16	2,4,15,15	2,4,14,14	
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	
	refShip.MaxCrew         			= 666;
	refShip.OptCrew         			= 426;
	refShip.MinCrew         			= 66;	
	refShip.SpeedRate					= 16.6;
	refShip.TurnRate        			= 36.6;
	refShip.Price           			= 66666;
	refShip.HP              			= 6666;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= -0.48;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.66;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 0.5;
	refship.InertiaAccelerationY	= 2.0;	refship.InertiaBrakingY		= 0.5;
	refship.InertiaAccelerationZ	= 2.5;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

        ///////////////////////////////////////////////////////////////////////////
	//// Фрегат Арабелла
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ARABELLASHIPG]);
	refShip.Name            			= "ArabellaShipG";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1250);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity				= 52;	// 4,4,22,22	4,4,20,20	4,4,18,18
	refShip.CannonsQuantityMin			= 44;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 350;
	refShip.OptCrew         			= 300;
	refShip.MinCrew         			= 30;
	
	refShip.SpeedRate       			= 14.9;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 173700;
	refShip.HP              			= 7000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.29;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;		refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Воздушный шар
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BALLOON]);
	refShip.Name            			= "Balloon";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(120);	
	refShip.Capacity        			= 550;
	refShip.CannonsQuantity				= 4; // 1,1,1,1	1,1,1,1
	refShip.CannonsQuantityMin			= 4;
	refShip.rcannon 					= 1;
	refShip.lcannon 					= 1;
	refShip.fcannon 					= 1;
	refShip.bcannon 					= 1;	
	refShip.MaxCrew         			= 20;
	refShip.OptCrew         			= 15;
	refShip.MinCrew         			= 2;	
	refShip.SpeedRate       			= 3.7;
	refShip.TurnRate        			= 5.0;
	refShip.Price           			= 1500000;
	refShip.HP              			= 750;
	refShip.SP              			= 100;

	refship.CabinType          			= "BalloonCabine";
		
	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refShip.DisableChangedHull              	                                          = true;
	refShip.Balloon              			                     = true;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= -136.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= -180.00;

	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 1.65;	refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 2.64;	refShip.Height.Grapes.DY	= 0.5;
	refShip.Height.Knippels.Y			= 14.64; refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 1.65;	refShip.Height.Balls.DY		= 1.35;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

///////////////////////////////////////////////////////////////////////////
	//// "Черная Жемчужина"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BLACKPEARL]);
	refShip.Name            			= "BlackPearl";  
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(1000);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 36;
	refShip.CannonsQuantityMin			= 36;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;		
	refShip.MaxCrew         			= 375;
	refShip.OptCrew         			= 300;
	refShip.MinCrew         			= 45;	
	refShip.SpeedRate					= 17.5;
	refShip.TurnRate        			= 42.5;
	refShip.Price           			= 100000;
	refShip.HP              			= 5000;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships\parus_Black_Pearl.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew 				= 20;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.5;
	
	refship.CabinType          			= "CabineHG"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;

	refShip.GeraldSails.rey_b1.hscale		= 0.75;
	refShip.GeraldSails.rey_b2.hscale		= 0.75;
	refShip.GeraldSails.rey_b3.hscale		= 0.55;
	refShip.GeraldSails.rey_b1.vscale		= 0.75;
	refShip.GeraldSails.rey_b2.vscale		= 0.75;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 15.0;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.0;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Линкор "Виктори" и линкор "Le Superbe"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MANOWARV]);
	refShip.Name            			= "ManowarV";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(4200);
	refShip.Capacity        			= 9000;
	refShip.CannonsQuantity				= 106;
	refShip.CannonsQuantityMin			= 106;
	refShip.rcannon 					= 51;
	refShip.lcannon 					= 51;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 160;	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 151100;
	refShip.HP              			= 10850;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;

	refShip.lowpolycrew 				= 28;
	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.25;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.3;
	refShip.Height.Grapes.Y				= 12.5;		refShip.Height.Grapes.DY	= 6.2;
	refShip.Height.Knippels.Y			= 36.8;		refShip.Height.Knippels.DY	= 29.6;
	refShip.Height.Balls.Y				= 8.6;		refShip.Height.Balls.DY		= 4.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	// CSM -->
	if (CheckAttribute(refShip, "CSM.ChangeSkin"))
	{
		refShip.Name            			= "LeSuperbe";
		refShip.CannonsQuantity				= 78;
		refShip.CannonsQuantityMin			= 78;
		refShip.rcannon 					= 37;
		refShip.lcannon 					= 37;
		refShip.fcannon 					= 2;
		refShip.bcannon 					= 2;
		//
		refShip.MaxCrew         			= 810;
		refShip.OptCrew         			= 675;
		refShip.MinCrew         			= 110;
		//
		refShip.SpeedRate       			= 13.0;
		refShip.TurnRate        			= 27.6;
		//
		refShip.Price           			= 132000;
		refShip.HP              			= 9000;
		refShip.Capacity        			= 7000;
		//
		refship.WaterLine					= -0.5;
		//
		refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
		refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
		refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
		//
		refShip.Height.Bombs.Y				= 6.8;		refShip.Height.Bombs.DY		= 3.4;
		refShip.Height.Grapes.Y				= 8.2;		refShip.Height.Grapes.DY	= 4.1;
		refShip.Height.Knippels.Y			= 33.6;		refShip.Height.Knippels.DY	= 24.8;
		refShip.Height.Balls.Y				= 6.8;		refShip.Height.Balls.DY		= 3.4;
	}
	// CSM <--
	
	///////////////////////////////////////////////////////////////////////////
	//// Мановар "Солей Руаяль"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOLEYRU]);
	refShip.Name            			= "SoleyRu";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(4500);
	refShip.Capacity        			= 9500;
	refShip.CannonsQuantity				= 112;
	refShip.CannonsQuantityMin			= 112;
	refShip.rcannon 					= 52;
	refShip.lcannon 					= 52;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 825;
	refShip.MinCrew         			= 185;
	refShip.SpeedRate					= 10.7;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 250000;
	refShip.HP              			= 12000;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex		= "ships\parus_SoleyRu_new.tga";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;

	refShip.lowpolycrew 				= 28;
	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed  			= 0.25;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2.0;	refship.InertiaBrakingY		= 2.0;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.3;
	refShip.Height.Grapes.Y				= 12.5;		refShip.Height.Grapes.DY	= 6.2;
	refShip.Height.Knippels.Y			= 36.8;		refShip.Height.Knippels.DY	= 29.6;
	refShip.Height.Balls.Y				= 8.6;		refShip.Height.Balls.DY		= 4.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// "Месть королевы Анны"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QAR]);
	refShip.Name            			= "QAR";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(960);
	refShip.Capacity        			= 3250;
	refShip.CannonsQuantity				= 48;
	refShip.CannonsQuantityMin			= 48;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 420;
	refShip.OptCrew         			= 355;
	refShip.MinCrew         			= 50;
	refShip.SpeedRate       			= 17.3;
	refShip.TurnRate        			= 40.5;
	refShip.Price           			= 150000;
	refShip.HP              			= 4250;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships\parus_QAR.tga";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az					= 0.035;
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.6;//boal
	refship.CabinType          			= "Cabin_Quest"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.1;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.2;	refShip.Height.Knippels.DY	= 18.3;
	refShip.Height.Balls.Y				= 3.1;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Фрегат "Россия"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ROSSIYA]);
	refShip.Name            			= "Rossiya";
	refship.Soundtype					= "corvette";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(925);
	refShip.Capacity        			= 3800;
	refShip.CannonsQuantity				= 36;
	refShip.CannonsQuantityMin			= 36;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 370;
	refShip.OptCrew         			= 300;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.3;
	refShip.TurnRate        			= 37.2;
	refShip.Price           			= 68250;
	refShip.HP              			= 4500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 20;
	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2"; 

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.3;		refShip.Height.Bombs.DY		= 0.6;
	refShip.Height.Grapes.Y				= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 14.7;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y				= 1.3;		refShip.Height.Balls.DY		= 0.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Легкий фрегат "Сюрприз"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SURPRISE]);
	refShip.Name            			= "Surprise";
	refship.Soundtype					= "corvette";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(800);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity				= 32;	// 2,4,14,14
	refShip.CannonsQuantityMin			= 32;
	refShip.rcannon 					= 14;
	refShip.lcannon 					= 14;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 300;
	refShip.OptCrew         			= 250;
	refShip.MinCrew         			= 40;
	
	refShip.SpeedRate					= 17.25;
	refShip.TurnRate        			= 38.5;
	refShip.Price           			= 68100;
	refShip.HP              			= 4250;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.15;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.6;
	refship.CabinType          			= "Cabin_Medium2"; 

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;		refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Фрегат "Конституция"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CONSTITUTION]);
	refShip.Name            			= "Constitution";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1000);
	refShip.Capacity        			= 4050;
	refShip.CannonsQuantity				= 56;
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 455;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.27;
	refShip.TurnRate        			= 37.15;
	refShip.Price           			= 75000;
	refShip.HP              			= 5050;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	refship.WaterLine					= 0.50;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.5;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          = "CabineHZ";
	refship.DeckType           = "Big"; 

	refship.InertiaAccelerationX 	= 0.2; refship.InertiaBrakingX 	= 2.0;
	refship.InertiaAccelerationY 	= 10; refship.InertiaBrakingY 	= 4;
	refship.InertiaAccelerationZ 	= 4.0; refship.InertiaBrakingZ 	= 2.0;

	refShip.Height.Bombs.Y 		= 1.0; refShip.Height.Bombs.DY 		= 0.5;
	refShip.Height.Grapes.Y 	= 2.0; refShip.Height.Grapes.DY 	= 1.0;
	refShip.Height.Knippels.Y 	= 10.0; refShip.Height.Knippels.DY 	= 8.0;
	refShip.Height.Balls.Y 		= 1.0; refShip.Height.Balls.DY 		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//////////////////////////////////////////////////////////////////////////
	//// Бриг "Спиди"
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SPEEDY]);
	refShip.Name						= "Speedy";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  				= 20;
	refShip.Weight						= Tonnes2CWT(350);
	refShip.Capacity   					= 2000;
	refShip.CannonsQuantity				= 18;
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew        				= 175;
	refShip.OptCrew        				= 150;
	refShip.MinCrew        				= 20;
	
	refShip.SpeedRate      				= 16.0;
	refShip.TurnRate       				= 55.2;
	refShip.Price          				= 36000;
	refShip.HP             				= 3000;
	refShip.SP             				= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew					= 12;
	refship.Rocking.y					= 0.5;
	refship.Rocking.az					= 0.04;
	
	refship.WaterLine					= 0.10;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed    		= 1.20;
	
	refship.CabinType           		= "Cabin_Medium";
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Корвет "Пёс войны" и фрегат "Essex"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WARDOG]);
	refShip.Name            			= "Corvette_questCoAS";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(700);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity				= 40;
	refShip.CannonsQuantityMin			= 40;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 300;
	refShip.OptCrew         			= 240;
	refShip.MinCrew         			= 40;
	
	refShip.SpeedRate					= 17.2;
	refShip.TurnRate        			= 55.5;
	refShip.Price           			= 70000;
	refShip.HP              			= 3800;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y					= 0.7;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= -0.50;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.65;
	refship.CabinType          			= "Cabin_Medium2";

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.3;		refShip.Height.Bombs.DY		= 0.6;
	refShip.Height.Grapes.Y				= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 14.7;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y				= 1.3;		refShip.Height.Balls.DY		= 0.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	// CSM -->
	DeleteAttribute(refShip, "CSM.MastNoFall");
	if (CheckAttribute(refShip, "CSM.ChangeSkin"))
	{
		refShip.Name            			= "Essex";
		refShip.Class						= 2;
		refship.Soundtype					= "frigate";
		refShip.Weight						= Tonnes2CWT(900);
		refShip.CannonsQuantity				= 46;
		refShip.CannonsQuantityMin			= 46;
		refShip.rcannon 					= 21;
		refShip.lcannon 					= 21;
		refShip.fcannon 					= 2;
		refShip.bcannon 					= 2;
		//
		refShip.MaxCrew         			= 440;
		refShip.OptCrew         			= 365;
		refShip.MinCrew         			= 57;
		//
		refShip.SpeedRate       			= 17.0;
		refShip.TurnRate        			= 38.0;
		//
		refShip.Price           			= 70900;
		refShip.HP              			= 4700;
		refShip.Capacity        			= 3750;
		//
		refship.WaterLine					= 0.0;
		//
		refShip.lowpolycrew 				= 20;
		//
		refship.WindAgainstSpeed   			= 0.60;
		//
		refShip.CSM.MastNoFall				= true;
	}
	// CSM <--

	///////////////////////////////////////////////////////////////////////////
	//// Фрегат "Арабелла"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ARABELLA]);
	refShip.Name            			= "ArabellaShipCoAS";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(1000);
	refShip.Capacity        			= 3700;
	refShip.CannonsQuantity				= 52;
	refShip.CannonsQuantityMin			= 52;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 435;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 40;
	
	refShip.SpeedRate       			= 17.0;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 70000;
	refShip.HP              			= 5000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= -0.6;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin";
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.1;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.2;	refShip.Height.Knippels.DY	= 18.3;
	refShip.Height.Balls.Y				= 3.1;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Фрегат "Королева"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATEQUEEN]);
	refShip.Name            			= "FrigateQueen";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(950);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity				= 52;
	refShip.CannonsQuantityMin			= 52;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 415;
	refShip.OptCrew         			= 335;
	refShip.MinCrew         			= 37;
	
	refShip.SpeedRate       			= 17.15;
	refShip.TurnRate        			= 38.15;
	refShip.Price           			= 70000;
	refShip.HP              			= 4750;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew 				= 20;
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= -0.6;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin";
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.1;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.2;	refShip.Height.Knippels.DY	= 18.3;
	refShip.Height.Balls.Y				= 3.1;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//////////////////////////////////////////////////////////////////////////
	//// Бриг "Морской волк"
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGSW]);
	refShip.Name						= "BrigSW";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  				= 20;
	refShip.Weight						= Tonnes2CWT(350);
	refShip.Capacity   					= 2050;
	refShip.CannonsQuantity				= 24;
	refShip.CannonsQuantityMin			= 24;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew        				= 185;
	refShip.OptCrew        				= 152;
	refShip.MinCrew        				= 23;
	
	refShip.SpeedRate      				= 15.8;
	refShip.TurnRate       				= 54.5;
	refShip.Price          				= 35500;
	refShip.HP             				= 3200;
	refShip.SP             				= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew					= 12;
	refship.Rocking.y					= 0.5;
	refship.Rocking.az					= 0.04;
	
	refship.WaterLine					= -0.80;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed    		= 1.20;
	
	refship.CabinType           		= "Cabin_Medium";
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//////////////////////////////////////////////////////////////////////////
	//// Бриг "Королева"
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGQUEEN]);
	refShip.Name						= "BrigQueen";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  				= 20;
	refShip.Weight						= Tonnes2CWT(340);
	refShip.Capacity   					= 2000;
	refShip.CannonsQuantity				= 24;
	refShip.CannonsQuantityMin			= 24;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew        				= 182;
	refShip.OptCrew        				= 150;
	refShip.MinCrew        				= 22;
	
	refShip.SpeedRate      				= 15.85;
	refShip.TurnRate       				= 54.55;
	refShip.Price          				= 35500;
	refShip.HP             				= 3000;
	refShip.SP             				= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew					= 12;
	refship.Rocking.y					= 0.5;
	refship.Rocking.az					= 0.04;
	
	refship.WaterLine					= -0.80;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.20;
	
	refship.CabinType           		= "Cabin_Medium";
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.2;			refShip.Height.Bombs.DY	= 0.6;
	refShip.Height.Grapes.Y	= 3.1;			refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y	= 17.7;		refShip.Height.Knippels.DY	= 16.7;
	refShip.Height.Balls.Y		= 1.2;		refShip.Height.Balls.DY	= 0.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	/// Джонка Императрица
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LUGGERQUEST]);
	refShip.Name            			= "LuggerQuestCoAS";
	refship.Soundtype					= "lugger";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(200);
	refShip.Capacity       				= 1900;
	refShip.CannonsQuantity				= 10;
	refShip.rcannon 							= 5;
	refShip.lcannon 							= 5;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 197;
	refShip.OptCrew         			= 151;
	refShip.MinCrew         			= 29;
	refShip.SpeedRate				= 11;
	refShip.TurnRate        		= 40;
	refShip.Price           			= 30000;
	refShip.HP              				= 900;
	refShip.SP              				= 100;
	refship.EmblemedSails.normalTex = "ships\sail_Empress.tga";
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refship.QuestShip					= true;
 
	refShip.lowpolycrew 				= 10;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.25;
	
	refship.WaterLine				= 0.04;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.1;
	refship.CabinType          = "Cabin_Quest";
	refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 7.5;
	refship.Track1.Width				= "6.0, 7.0";
	refship.Track1.Speed				= "7.2, 9.2";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 5.0;
	refship.Track2.Width				= "6.0, 8.0";
	refship.Track2.Speed				= "0.15, 0.25";

///////////////////////////////////////////////////////////////////////////
	//// Проклятый "Солей Руаяль" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOLEYPIR]);
	refShip.Name            			= "SoleyPir";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 9500;
	refShip.CannonsQuantity				= 112;
	refShip.CannonsQuantityMin			= 102;
	refShip.rcannon 					= 52;
	refShip.lcannon 					= 52;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 190;
	
	refShip.SpeedRate					= 13.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 271600;
	refShip.HP              			= 12600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex = "ships\parus_common1.tga";

	refship.CanEncounter 				= false;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "CabineFDM";	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.2;
	refShip.Height.Grapes.Y				= 9.7;		refShip.Height.Grapes.DY	= 4.8;
	refShip.Height.Knippels.Y			= 34.7;		refShip.Height.Knippels.DY	= 26.0;
	refShip.Height.Balls.Y				= 8.0;		refShip.Height.Balls.DY		= 4.2;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_c1				= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

///////////////////////////////////////////////////////////////////////////
	/// Плавучая Крепость "Исполин"
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WATER_FORT]);
	refShip.Name            			= "WaterFort";
	refship.Soundtype					= "manowar";
	refShip.Class					= 1;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 42;
	refShip.Weight					= Tonnes2CWT(5000);
	refShip.Capacity        			= 12000;
	refShip.CannonsQuantity				= 68;
	refShip.rcannon 							= 34;
	refShip.lcannon 							= 34;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 1500;
	refShip.OptCrew         			= 1000;
	refShip.MinCrew         			= 500;

	refShip.SpeedRate					= 3.0;
	refShip.TurnRate        			= 2.0;
	refShip.Price           			= 1000000;
	refShip.HP              			= 30000;
	refShip.SP              			= 100;

	refship.CanEncounter 				= false;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 35;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02;

	refship.WaterLine						= -1.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 0.7;

	refship.CabinType          = "Cabin_Huge";
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 33.0;		refShip.Height.Knippels.DY	= 27.0;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// FORT
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FORT]);
	refShip.Name								= "Fort";
	refShip.isFort      						= true; // для удобства проверок на rRealShip
	refShip.Class								= 1;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber							= 48;
	refShip.Weight								= Tonnes2CWT(22500);
	refShip.Capacity							= 300000;
	refShip.CannonsQuantity						= 68;
	refShip.CannonsQuantityMin					= 68;
	refShip.rcannon 							= 68;
	refShip.lcannon 							= 0;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         					= 1800;
	refShip.OptCrew         					= 1600;
	refShip.MinCrew         					= 400;
	refShip.SpeedRate							= 0.0;
	refShip.TurnRate							= 0;
	refShip.Price								= 12000;
refShip.HP									= 1;
	refShip.SP									= 100;
	refShip.CanEncounter						= false;

	/// Check
	for (int i=0; i<SHIP_TYPES_QUANTITY_WITH_FORT-1; i++)
	{
	  	makeref(refShip, ShipsTypes[i]);
		if (!CheckAttribute(refShip,"Name")) { continue; }
		if (!CheckAttribute(refShip,"TurnRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have TurnRate attribute");
		}
		if (!CheckAttribute(refShip,"SpeedRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have SpeedRate attribute");
		}
		if (!CheckAttribute(refShip,"Class"))
		{
			Trace("ERROR: Ship " + i + " doesn't have class attribute");
		}
		else
		{
			int iClass = sti(refShip.Class);
			if (iClass > 6) { Trace("ERROR: Ship " + i + " class > 6"); }
			if (iClass < 1) { Trace("ERROR: Ship " + i + " class < 1"); }
		}
		refship.InertiaAccelerationY = stf(refship.InertiaAccelerationY) / 6.0;
		// boal 10/11/05 пробить оптимальный экипаж
		//refShip.OptCrew = sti(refShip.MaxCrew);
		//refShip.MaxCrew = makeint(sti(refShip.MaxCrew) * 1.25 + 0.5); // перегруз
		/// как говаривал мой папа - нахрена попу гармонь?  Приходится приводить к каноническому виду, править все буковки по файлу мне лень
		refShip.cannonr  = refShip.rcannon;
		refShip.cannonl  = refShip.lcannon;
		refShip.cannonf  = refShip.fcannon;
		refShip.cannonb  = refShip.bcannon;
	}
}