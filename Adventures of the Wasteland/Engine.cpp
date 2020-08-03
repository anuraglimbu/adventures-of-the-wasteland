#include "Engine.h"

Engine::Engine()
{
	//Loading the areas into vectors
	currentArea = &dumpyard;
}

bool Engine::Execute()
{
	if (gameState == GameStates::quit_game)
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
			moveNorth();
			break;

		case 2:
			parser.Write("Go south command");
			moveSouth();
			break;

		case 3:
			parser.Write("Go west command");
			moveWest();
			break;

		case 4:
			parser.Write("Go east command");
			moveEast();
			break;

		case 5:
			parser.Write("Go north-west command");
			moveNorthWest();
			break;

		case 6:
			parser.Write("Go north-east command");
			moveNorthEast();
			break;

		case 7:
			parser.Write("Go south-west command");
			moveSouthWest();
			break;

		case 8:
			parser.Write("Go south-east command");
			moveSouthEast();
			break;

		case 9:
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
			gameState = GameStates::playing;
			break;
		}
		parser.Write("State your name:");
	}
}

//Player movement determination
void Engine::moveNorth()
{
	if(currentArea->checkDirection("n"))
	{
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &wasteland;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouth()
{
	if (currentArea->checkDirection("s"))
	{
		switch (currentArea->area)
		{
			case Areas::wasteland:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &dumpyard;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveWest()
{
	parser.Write("There's only a dense forest in that direction! You can't go that way.");
}

void Engine::moveEast()
{		
	parser.Write("There's only a dense forest in that direction! You can't go that way.");
}

void Engine::moveNorthWest()
{
	if (currentArea->checkDirection("nw"))
	{
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &plain;
				currentArea->welcomeMessage();
				break;

			case Areas::mountain:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveNorthEast()
{
	if (currentArea->checkDirection("ne"))
	{
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &mountain;
				currentArea->welcomeMessage();
				break;

			case Areas::plain:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthWest()
{
	if (currentArea->checkDirection("sw"))
	{
		switch (currentArea->area)
		{
			case Areas::mountain:
				currentArea = &dumpyard;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &plain;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthEast()
{
	if (currentArea->checkDirection("se"))
	{
		switch (currentArea->area)
		{
		case Areas::plain:
			currentArea = &dumpyard;
			currentArea->welcomeMessage();
			break;

		case Areas::valley:
			currentArea = &mountain;
			currentArea->welcomeMessage();
			break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::Quit()
{
	parser.Write("Do you really wish to quit the game?");
	if (parser.YesNo())
	{
		gameState = GameStates::quit_game;
		parser.Write("Closing the game");
	}
}