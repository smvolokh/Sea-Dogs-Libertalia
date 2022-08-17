// Правки для корабликов
void SM_FixShipsData()
{
	
	ref refShip;
	
	
	
	
	// Corvette =============================
	makeref(refShip,ShipsTypes[SHIP_CORVETTE]);
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	// ===================================
	
	
	
	
	// Lineship =============================
	makeref(refShip,ShipsTypes[SHIP_LINESHIP]);
	
	refShip.GeraldSails.rey_b1.vscale	= 0.7;
	refShip.GeraldSails.rey_b1.hscale	= 0.6;
	
	refShip.GeraldSails.rey_b2.vscale	= 0.75;
	refShip.GeraldSails.rey_b2.hscale	= 0.75;
	
	refShip.GeraldSails.rey_b3.vscale	= 0.75;
	refShip.GeraldSails.rey_b3.hscale	= 0.75;
	// ===================================
	
	
	
	
	// Fortune =============================
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_L]);
	
	refShip.GeraldSails.rey_b2.vscale	= 0.75;
	refShip.GeraldSails.rey_b2.hscale	= 0.75;
	
	refShip.GeraldSails.rey_b3.vscale	= 0.75;
	refShip.GeraldSails.rey_b3.hscale	= 0.75;
	
	//refShip.sails.(nodeName).(groupName)
	
	refship.CabinType          			= "Cabin_Huge"; 
	// ===================================
	
	
	
	
	// Heavy Frigate =========================
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_H]);
	
	refShip.GeraldSails.rey_b2.vscale	= 0.75;
	refShip.GeraldSails.rey_b2.hscale	= 0.75;
	
	refShip.GeraldSails.rey_b3.vscale	= 0.75;
	refShip.GeraldSails.rey_b3.hscale	= 0.75;
	// ===================================
	
	
	
	
	// Victory ==============================
	makeref(refShip,ShipsTypes[SHIP_MANOWARV]);
	
	refShip.GeraldSails.rey_b2.vscale	= 0.75;
	refShip.GeraldSails.rey_b2.hscale	= 0.75;
	
	refShip.GeraldSails.rey_b3.vscale	= 0.75;
	refShip.GeraldSails.rey_b3.hscale	= 0.75;
	// ===================================

}