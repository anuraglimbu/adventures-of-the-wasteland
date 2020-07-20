#include "Engine.h"

bool Engine::Execute()
{
	if (gameState == GameState::quit_game)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Engine::Process()
{
	parser.Read();
	switch (parser.Parse())
	{
		case 0:
			Quit();
			break;

		case 1:
			parser.Write("Just a command");
			break;

		default:
			parser.Write("Excuse me, i dont get it");
	}
}

void Engine::Quit()
{
	parser.Write("Do you really wish to quit the game?");
	if (parser.YesNo())
	{
		gameState = GameState::quit_game;
		parser.Write("closing the game");
	}
}