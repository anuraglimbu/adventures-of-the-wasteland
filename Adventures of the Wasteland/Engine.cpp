#include "Engine.h"

Engine::Engine()
{
	//std::cout << "Engine Object created";
}

bool Engine::Execute()
{
	if (this->quit_game == true)
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
	input.Read();
	switch (input.Parse())
	{
		case 0:
			std::cout << "\nQuit called";
			this->quit_game = true;
			break;

		case 1:
			std::cout << "\nJust a command";
			break;

		case 3:
			std::cout << "Enter Pressed";
			break;

		default:
			std::cout << "\nExcuse me, i dont get it";
	}
}

Engine::~Engine()
{

}