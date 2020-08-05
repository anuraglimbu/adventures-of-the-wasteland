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
	std::cout << "Help Text";
}