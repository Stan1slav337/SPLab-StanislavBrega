#pragma once

#include <iostream>
#include <string>
#include <thread>

#include "Picture.hpp"
#include "Element.hpp"
#include "Image.hpp"

class ImageProxy : public Element, public Picture
{
public:
	ImageProxy(std::string name) : name(name), image(nullptr) {};

	Image* loadImage()
	{
		if (image == nullptr)
		{
			image = new Image(name);
		}
		return image;
	}

	std::string get() const override
	{
		return name;
	}

	void accept(Visitor&) override;

private:
	std::string name;
	Image* image;
};