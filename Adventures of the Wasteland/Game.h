#pragma once

#include "Engine.h"

class Game
{
	public:
		Game();
		void WelcomeScreen();
		void Run();
	
	private:
		Engine game_engine;
};

