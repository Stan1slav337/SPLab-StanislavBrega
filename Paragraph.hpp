#pragma once

#include <iostream>
#include <string>

#include "Element.hpp"
#include "AlignStrategy.hpp"

class Paragraph : public Element
{
public:
	Paragraph(std::string text) : text(text), alignStrategy(nullptr) {};

	void print() override
	{
		if (alignStrategy == nullptr)
		{
			std::cout << "Normal " << text << std::endl;
			return;
		}

		alignStrategy->render(text);
	}

	void setAlignStrategy(AlignStrategy* newStrategy)
	{
		alignStrategy = newStrategy;
	}

private:
	std::string text;
	AlignStrategy* alignStrategy;
};