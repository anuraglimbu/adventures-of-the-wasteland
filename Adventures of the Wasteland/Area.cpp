#include "Area.h"

Area::Area(int areaCode)
{
	switch(areaCode)
	{
		case 0:
			name = "The Dumpyard";
			area = Areas::dumpyard;
			shop = true;

			north = true;
			south = false;
			west = false;
			east = false;
			north_west = true;
			north_east = true;
			south_west = false;
			south_east = false;

			break;

		case 1:
			name = "Plain of the Armoured Warriors";
			area = Areas::plain;
			shop = true;

			north = false;
			south = false;
			west = false;
			east = true;
			north_west = false;
			north_east = true;
			south_west = false;
			south_east = true;
			
			break;

		case 2:
			name = "Mountain of the Shieldmakers";
			area = Areas::mountain;
			shop = true;

			north = false;
			south = false;
			west = true;
			east = false;
			north_west = true;
			north_east = false;
			south_west = true;
			south_east = false;

			break;
		
		case 3:
			name = "Valley of the Swordsmen";
			area = Areas::valley;
			shop = true;

			north = true;
			south = true;
			west = false;
			east = false;
			north_west = false;
			north_east = false;
			south_west = true;
			south_east = true;

			break;

		case 4:
			name = "The Wasteland";
			area = Areas::wasteland;
			shop = false;

			north = false;
			south = true;
			west = false;
			east = false;
			north_west = false;
			north_east = false;
			south_west = false;
			south_east = false;

			break;
	}
}

std::string Area::getName()
{
	return name;
}

void Area::welcomeMessage()
{
	std::cout << "Welcome to " << name <<std::endl;
}

bool Area::checkDirection(std::string dir) //returns whether the direction of movement from this area is valid or not
{
	if (dir == "n") return north;
	if (dir == "s") return south;
	if (dir == "w") return west;
	if (dir == "e") return east;
	if (dir == "nw") return north_west;
	if (dir == "ne") return north_east;
	if (dir == "sw") return south_west;
	if (dir == "se") return south_east;
	return false;
}