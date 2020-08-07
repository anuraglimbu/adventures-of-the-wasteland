#include "Screen.h"

void Screen::Write(std::string text)
{
	std::cout << "\n"<< text;
}

void Screen::EmptyLine()
{
	Write("");
}

void Screen::DashedLine()
{
	Write("==========================================================");
}

void Screen::showHelp()
{
	std::cout << "Type 'inventory' or 'inv' to access your inventory \n Type north to go north \n Type south to go south";
}