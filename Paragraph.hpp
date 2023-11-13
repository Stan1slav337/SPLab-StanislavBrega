#pragma once

#include <iostream>
#include <string>

#include "Element.hpp"

class Paragraph : public Element
{
public:
	Paragraph(std::string text) : text(text) {};

	void print() override
	{
		std::cout << "Paragraph " << text << std::endl;
	}

private:
	std::string text;
};