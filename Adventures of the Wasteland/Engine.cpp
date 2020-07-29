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
			parser.Write("Go north command");
			break;

		case 2:
			parser.Write("Go south command");
			break;

		case 3:
			parser.Write("Go east command") ;
			break;

		case 4:
			parser.Write("Go west command");
			break;

		case 5:
			parser.showHelp();
			break;

		default:
			parser.Write("Excuse me, i dont get it");
	}
}

void Engine::onboardPlayer()
{
	while(true)
	{
		parser.ReadRaw();
		parser.Write("You will be called by this name from now on, are you sure?(y/n)");
		if(parser.YesNo())
		{
			player.SetPlayerName(parser.getInput());
			std::cout << "Well nice to meet you, " << player.GetPlayerName() <<".";
			parser.Write("You can ask for help by just typing 'help'");
			gameState = GameState::playing;
			break;
		}
		parser.Write("State your name:");
	}
}

void Engine::Quit()
{
	parser.Write("Do you really wish to quit the game?");
	if (parser.YesNo())
	{
		gameState = GameState::quit_game;
		parser.Write("Closing the game");
	}
}