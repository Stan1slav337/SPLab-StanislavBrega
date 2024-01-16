#pragma once

#include <iostream>
#include <string>
#include <thread>

#include "Element.hpp"

class Image : public Element
{
public:
	Image(std::string name) : name(name) 
	{
		try 
		{
			//std::this_thread::sleep_for(std::chrono::seconds(3));
		} 
		catch(...)
		{
			std::cout << "ERROR" << std::endl;
		}
	};

	std::string get() const override
	{
		return name;
	}

	void accept(Visitor&) override;

private:
	std::string name;
};