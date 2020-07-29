#pragma once

#include "Parser.h"
#include "Player.h"

enum class GameState
{
	onboarding,
	playing,
	quit_game
};

enum class PlayerState
{
	fighting,
	shopping,
	travelling
};

class Engine 
{
	public:
		GameState gameState = GameState::onboarding;
		bool Execute();
		void Process();

		void Quit();
		void onboardPlayer();

	private:
		Parser parser;
		Player player;
};

