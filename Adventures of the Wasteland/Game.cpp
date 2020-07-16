#include "Game.h"

Game::Game()
{
	WelcomeScreen();
}

void Game::WelcomeScreen()
{
	std::cout << "Adventures of the Wasteland";
}

void Game::Execute()
{
	while(true)
	{
		std::cout << "\nGive a command:\n";
		std::cin >> inp;

		if (inp == "quit")
		{
			Quit();
			break;
		}
	}
}

void Game::Quit()
{
	std::cout << "\nDo you really wish to quit the game?";
	std::cin >> inp;
	if (inp == "yes")
	{
		std::cout << "closing the game";
	}
}

Game::~Game()
{

}
