#pragma once

#include <iostream>
#include <string>

class Image
{
public:
	Image(std::string name) : name(name) {};

	void print()
	{
		std::cout << "Image " << name << std::endl;
	}

private:
	std::string name;
};