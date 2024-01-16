#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Element.hpp"

class Section: public Element
{
protected:
	Section() = default;

public:
	Section(std::string name) : name(name) {};

	void add(Element* element)
	{
		elements.push_back(element);
	}

	std::vector<Element*> getElements() const
	{
		return elements;
	}

	std::string get() const override
	{
		return name;
	}

	void accept(Visitor&) override;

private:
	std::string name;
	std::vector<Element*> elements;
};