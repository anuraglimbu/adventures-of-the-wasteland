#pragma once

#include <iostream>

#include "Parser.h"

class Engine
{
	public:
		Engine();
		~Engine();

		bool Execute();
		void Process();

	private:
		bool quit_game = false;
		Parser input;

};

