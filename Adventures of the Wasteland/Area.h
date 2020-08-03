#pragma once

#include <iostream>
#include <string>
#include <vector>

enum Areas
{
	dumpyard,
	plain,
	valley,
	mountain,
	wasteland
};

class Area
{
	public:
		Area(int areaCode);

		std::string getName();
		bool checkDirection(std::string dir);

		void welcomeMessage();

		Areas area; //The area type variable which determines area

		

	private:
		std::string name;
		bool shop;
		std::vector<int> shop_items;

		//directions
		bool north;
		bool south;
		bool west;
		bool east;
		bool north_west;
		bool north_east;
		bool south_west;
		bool south_east;
};

