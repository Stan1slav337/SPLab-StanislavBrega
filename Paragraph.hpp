#pragma once

#include <iostream>
#include <string>

class Paragraph
{
public:
	Paragraph(std::string text) : text(text) {};

	void print()
	{
		std::cout << "Paragraph " << text << std::endl;
	}

private:
	std::string text;
};