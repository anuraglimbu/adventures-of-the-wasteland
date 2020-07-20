#pragma once

#include "Parser.h"

enum class GameState
{
	onboarding,
	fighting,
	shopping,
	quit_game
};

class Engine 
{
	public:
		bool Execute();
		void Process();
		void Quit();

	private:
		GameState gameState = GameState::onboarding;
		Parser parser;

};

