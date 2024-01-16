#pragma once

#include <iostream>
#include <string>

#include "Element.hpp"

class Table : public Element
{
public:
	Table(std::string title) : title(title) {};

	std::string get() const override
	{
		return title;
	}

	void accept(Visitor&) override;

private:
	std::string title;
};