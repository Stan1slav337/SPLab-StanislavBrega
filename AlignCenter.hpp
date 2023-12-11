#pragma once

#include "AlignStrategy.hpp"

class AlignCenter: public AlignStrategy
{
public:
	void render(std::string& text)
	{
		text = "       " + text;
		std::cout << text << std::endl;
	}
};