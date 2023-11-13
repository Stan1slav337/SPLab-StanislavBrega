#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Section.hpp"
#include "Author.hpp"

class Book : public Section
{
public:
	Book(std::string name) : name(name) {};

	void print()
	{
		std::cout << "Book " << name << std::endl;

		std::cout << "\nAuthors:\n";
		for (auto& author : authors)
			author.print();

		std::cout << std::endl;
		for (auto* content : contents)
			content->print();
	}

	void addContent(Element* element)
	{
		contents.push_back(element);
	}

	void addAuthor(const Author author)
	{
		authors.push_back(author);
	}

private:
	std::string name;
	std::vector<Author> authors;
	std::vector<Element*> contents;
};