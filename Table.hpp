#pragma once

#include <iostream>
#include <string>

#include "Element.hpp"

class Table : public Element
{
public:
	Table(std::string title) : title(title) {};

	void print() override
	{
		std::cout << "Table " << title << std::endl;
	}

private:
	std::string title;
};