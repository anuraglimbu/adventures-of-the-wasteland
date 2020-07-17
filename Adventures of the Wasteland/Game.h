#pragma once

#include <iostream>
#include <string>

#include "Engine.h"

class Game
{
	public:
		Game();
		~Game();

		void WelcomeScreen();
		void Run();
		void Quit();

	private:
		bool game_quit = false;
		std::string inp;
		Engine game_engine;
};

