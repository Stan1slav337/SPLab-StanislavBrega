#pragma once

#include <iostream>
#include <string>

#include "Element.hpp"

class Image : public Element
{
public:
	Image(std::string name) : name(name) {};

	void print() override
	{
		std::cout << "Image " << name << std::endl;
	}

private:
	std::string name;
};