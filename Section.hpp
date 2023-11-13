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

	void print() override
	{
		std::cout << name << std::endl;
		
		for (auto *element : elements)
			element->print();
	}

	void add(Element* element)
	{
		elements.push_back(element);
	}

private:
	std::string name;
	std::vector<Element*> elements;
};