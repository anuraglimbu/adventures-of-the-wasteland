#include "Game.h"

Game::Game()
{
	WelcomeScreen();
}

void Game::WelcomeScreen()
{
	std::cout << "Adventures of the Wasteland";
	std::cout << "\nIntro stuff goes here";
}

void Game::Run()
{
	while(game_engine.Execute())
	{
		game_engine.Process();
	}
}
