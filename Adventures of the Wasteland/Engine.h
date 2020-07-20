#pragma once

#include "Parser.h"

class Engine 
{
	public:
		Engine();
		~Engine();

		bool Execute();
		void Process();
		void Quit();

	private:
		bool quit_game = false;
		Parser parser;

};

