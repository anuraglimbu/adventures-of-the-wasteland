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

	Quit();
}

void Game::Quit()
{
	std::cout << "\nDo you really wish to quit the game?";
	std::cin >> inp;
	if (inp == "yes" || inp == "y")
	{
		std::cout << "closing the game";
	}
}

Game::~Game()
{

}
