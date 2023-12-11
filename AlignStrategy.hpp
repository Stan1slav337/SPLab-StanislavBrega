#pragma once

#include <iostream>
#include <string>

class AlignStrategy
{
public:
	virtual void render(std::string&) = 0;
};