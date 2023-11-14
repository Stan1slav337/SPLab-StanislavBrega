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

	void print() override
	{
		Image* loadedImg = loadImage();
		loadedImg->print();
	}

private:
	Image* loadImage()
	{
		if (image == nullptr)
		{
			image = new Image(name);
		}
		return image;
	}

	std::string name;
	Image* image;
};