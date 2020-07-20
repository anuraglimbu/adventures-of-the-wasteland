#include "Parser.h"

Parser::Parser()
{

}

void Parser::Read()
{
	Write(">>");
	std::cin >> player_input;
	std::transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);
}

int Parser::Parse()
{
	if (player_input == "quit" || player_input == "q")
	{
		return 0;
	}

	if (player_input == "")
	{
		return 5;
	}
	return 1;
}

bool Parser::YesNo()
{
	std::cin >> yes_no;
	std::transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
	if (yes_no == "yes" || yes_no == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}

Parser::~Parser(){}