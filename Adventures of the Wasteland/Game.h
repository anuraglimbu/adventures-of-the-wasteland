#pragma once

#include <iostream>
#include <string>

class Game
{
	public:
		Game();
		~Game();

		void WelcomeScreen();
		void Execute();
		void Quit();

	private:
		bool game_quit = false;
		std::string inp;
};

