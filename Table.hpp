#pragma once

#include <iostream>
#include <string>

class Table
{
public:
	Table(std::string title) : title(title) {};

	void print()
	{
		std::cout << "Table " << title << std::endl;
	}

private:
	std::string title;
};