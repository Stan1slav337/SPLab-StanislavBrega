#pragma once

#include "AlignStrategy.hpp"

class AlignLeft : public AlignStrategy
{
public:
	void render(std::string text)
	{
		std::cout << text << std::endl;
	}
};