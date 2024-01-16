#pragma once

#include <string>

#include "Visitee.hpp"

class Element : public Visitee
{
public:
	virtual std::string get() const = 0;
}; 