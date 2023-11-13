#pragma once

#include <iostream>
#include <string>

class Author
{
public:
	Author(std::string name) : name(name) {};

	void print()
	{
		std::cout << "Author " << name << std::endl;
	}

private:
	std::string name;
};