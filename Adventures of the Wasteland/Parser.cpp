#include "Parser.h"

void Parser::Read()
{
	Write(">>");
 	std::cin >> player_input;
	std::transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);
}

void Parser::ReadRaw()
{
	Write(">>");
	std::cin >> player_input;
}

int Parser::Parse()
{
	if (player_input == "quit" || player_input == "q") return 0;

	if (player_input == "go north" || player_input == "north" || player_input == "go n" || player_input == "n") return 1;

	if (player_input == "go south" || player_input == "south" || player_input == "go s" || player_input == "s") return 2;

	if (player_input == "go east" || player_input == "east" || player_input == "go e" || player_input == "e") return 3;

	if (player_input == "go west" || player_input == "west" || player_input == "go w" || player_input == "w") return 4;

	if (player_input == "help" || player_input == "h") return 5;

	return 999;
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

std::string Parser::getInput()
{
	return player_input;
}