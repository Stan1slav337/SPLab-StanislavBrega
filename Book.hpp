#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Chapter.hpp"
#include "Author.hpp"

class Book
{
public:
	Book(std::string name) : name(name) {};

	void print()
	{
		std::cout << "Book " << name << std::endl;
	}

	size_t createChapter(std::string name)
	{
		Chapter chapter(name);
		chapters.push_back(chapter);
		return chapters.size() - 1UL;
	}

	Chapter& getChapter(size_t idx)
	{
		if (idx >= chapters.size())
			throw 1;
		return chapters[idx];
	}

	void addAuthor(const Author author)
	{
		authors.push_back(author);
	}

private:
	std::string name;
	std::vector<Chapter> chapters;
	std::vector<Author> authors;
};