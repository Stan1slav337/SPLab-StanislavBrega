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

	void addContent(Element* element)
	{
		contents.push_back(element);
	}

	void addAuthor(const Author author)
	{
		authors.push_back(author);
	}

	std::vector<Author> getAuthors() const
	{
		return authors;
	}

	std::vector<Element*> getContents() const
	{
		return contents;
	}

	std::string get() const override
	{
		return name;
	}

	void accept(Visitor&) override;

private:
	std::string name;
	std::vector<Author> authors;
	std::vector<Element*> contents;
};