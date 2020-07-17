#include "Parser.h"

Parser::Parser()
{
	//std::cout << "Parser object created";
}

void Parser::Read()
{
	std::cout << "\n>>";
	std::cin >> player_input;
}

int Parser::Parse()
{
	if (player_input == "quit" || player_input == "q")
	{
		return 0;
	}

	return 1;
	
}

Parser::~Parser()
{

}