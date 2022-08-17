#define GOODS_QUANTITY  	64
// порядок не менять !!! порядок важен для AI фантомов ! <-- ugeen

// боеприпасы
#define GOOD_BALLS	    	0
#define GOOD_GRAPES	    	1
#define GOOD_KNIPPELS		2
#define GOOD_BOMBS	    	3

// товары повседневного спроса
#define GOOD_FOOD       	4
#define GOOD_SAILCLOTH  	5
#define GOOD_PLANKS     	6
#define GOOD_BRICK      	7
#define GOOD_WHEAT      	8
#define GOOD_CLOTHES		9
#define GOOD_FISH	10
#define GOOD_VEGETABLES 	  11
#define GOOD_SOAP 	  12
#define GOOD_TIMBERS 	  13
#define GOOD_POTTERY	  14
#define GOOD_FRUITS     	15

// колониальные (экспортные) товары
#define GOOD_COFFEE	    	16
#define GOOD_CHOCOLATE		17
#define GOOD_TOBACCO		18
#define GOOD_SUGAR	    	19
#define GOOD_COTTON	    	20
#define GOOD_LEATHER		21
#define GOOD_EBONY      	22
#define GOOD_MAHOGANY 		23
#define GOOD_CINNAMON   	24
#define GOOD_COPRA      	25
#define GOOD_TEA    	26
#define GOOD_SALT	27
#define GOOD_PAPRIKA    	28

// привозные товары из Европы
#define GOOD_POWDER     	29
#define GOOD_WEAPON	    	30
#define GOOD_MEDICAMENT 	31
#define GOOD_WINE	    	32
#define GOOD_RUM	    	33
#define GOOD_PAPER 	  34
#define GOOD_HEMP 	  35
#define GOOD_PITCH 	  36
#define GOOD_VINEGAR	37
#define GOOD_TOOLS	38
#define GOOD_ALE	    	39


// уникальные товары
#define GOOD_SHIPSILK	    40
#define GOOD_ROPES	    	41
#define GOOD_SANDAL	    	42
#define GOOD_OIL        	43

// коронные товары
#define GOOD_SLAVES     	44
#define GOOD_IRON 	45
#define GOOD_COPPER 	46
#define GOOD_IVORY 	  47
#define GOOD_DYES 	  48
#define GOOD_SILK       	49
#define GOOD_GOLD       	50
#define GOOD_SILVER	    	51

//   орудия
#define GOOD_CANNON_3    	52
#define GOOD_CANNON_6    	53
#define GOOD_CANNON_12   	54
#define GOOD_CANNON_16   	55
#define GOOD_CANNON_20   	56
#define GOOD_CANNON_24   	57
#define GOOD_CANNON_32   	58
#define GOOD_CANNON_36   	59
#define GOOD_CANNON_42   	60

#define GOOD_CULVERINE_8  	61
#define GOOD_CULVERINE_18 	62
#define GOOD_CULVERINE_36 	63

object  Goods[GOODS_QUANTITY];

ref GetGoodByType(int iGoodType)
{
	return &Goods[iGoodType];
}

int FindGood(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) 
	{ 
		if (Goods[i].Name == sGood) return i; 
	}
	return -1;
}

ref GetGoodByID(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) 
	{ 
		if (Goods[i].Name == sGood) 
		{
			return &Goods[i];
		}
	}
	trace("WARNING! Goods ID (" + sGood +") not found!");
}

int GetGoodWeightByType(int iGoodType,int quantity)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int unitQuantity = (quantity+unitSize-1)/unitSize;
	int weight = makeint(unitQuantity*stf(Goods[iGoodType].Weight) + 0.05);
	return weight;
}

int GetGoodQuantityByWeight(int iGoodType,int weight)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int uqnt = makeint( weight / stf(Goods[iGoodType].Weight) );
	return unitSize*uqnt;
}