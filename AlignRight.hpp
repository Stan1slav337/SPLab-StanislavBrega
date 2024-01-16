#pragma once

#include "AlignStrategy.hpp"

class AlignRight : public AlignStrategy
{
public:
	void render(std::string text)
	{
		text = "                                    " + text;
		std::cout << text << std::endl;
	}
};