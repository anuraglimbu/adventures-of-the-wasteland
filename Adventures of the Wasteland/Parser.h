#pragma once
#include <iostream>
#include <string>

class Parser
{
	public:
		Parser();
		~Parser();

		void Read();
		int Parse();

	private:
		std::string player_input;
};

