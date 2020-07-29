#pragma once

#include <algorithm>
#include "Screen.h"

class Parser : public Screen
{
	public:
		void Read();
		void ReadRaw();
		int Parse();

		bool YesNo();
		std::string getInput();

	private:
		std::string player_input;
		std::string yes_no;
};

