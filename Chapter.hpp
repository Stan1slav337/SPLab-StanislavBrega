#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "SubChapter.hpp"

class Chapter
{
public:
	Chapter(std::string name) : name(name) {};

	void print()
	{
		std::cout << "Chapter " << name << std::endl;
	}

	size_t createSubChapter(std::string name)
	{
		SubChapter subChapter(name);
		subChapters.push_back(subChapter);
		return subChapters.size() - 1UL;
	}

	SubChapter& getSubChapter(size_t idx)
	{
		if (idx >= subChapters.size())
			throw 1;
		return subChapters[idx];
	}

private:
	std::string name;
	std::vector<SubChapter> subChapters;
};