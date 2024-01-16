#pragma once

#include "Element.hpp"

class Paragraph : public Element
{
public:
	Paragraph(std::string text) : text(text) {};

	std::string get() const override
	{
		return text;
	}

	void accept(Visitor&) override;

private:
	std::string text;
};