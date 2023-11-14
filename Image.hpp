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
			std::this_thread::sleep_for(std::chrono::seconds(3));
		} 
		catch(...)
		{
			std::cout << "ERROR" << std::endl;
		}
	};

	void print() override
	{
		std::cout << "Image " << name << std::endl;
	}

private:
	std::string name;
};