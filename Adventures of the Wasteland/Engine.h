#pragma once

#include "Parser.h"
#include "Player.h"
#include "Area.h"

enum class GameStates
{
	onboarding,
	playing,
	quit_game
};

class Engine 
{
	public:
		Engine();

		GameStates gameState = GameStates::onboarding;
		bool Execute();
		void Process();

		void Quit();
		void onboardPlayer();

		//player movements
		void moveNorth();
		void moveSouth();
		void moveWest();
		void moveEast();
		void moveNorthWest();
		void moveNorthEast();
		void moveSouthWest();
		void moveSouthEast();

	private:
		Parser parser;
		Player player;

		//Areas
		Area dumpyard = Area(0);
		Area plain = Area(1);
		Area mountain = Area(2);
		Area valley = Area(3);
		Area wasteland = Area(4);

		Area *currentArea; //points to the area we currently are in
};

