#pragma once

#include <algorithm>
#include "Screen.h"

class Parser : public Screen
{
	public:
		Parser();
		~Parser();

		void Read();
		int Parse();

		bool YesNo();

	private:
		std::string player_input;
		std::string yes_no;
};

