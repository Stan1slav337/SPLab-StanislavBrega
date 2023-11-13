#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Image.hpp"
#include "Paragraph.hpp"
#include "Table.hpp"

class SubChapter
{
public:
	SubChapter(std::string name) : name(name) {};

	void print()
	{
		std::cout << "SubChapter " << name << std::endl;

		for (auto& paragraph : paragraphs)
			paragraph.print();

		for (auto& image : images)
			image.print();

		for (auto& table : tables)
			table.print();
	}

	void createNewImage(std::string name)
	{
		Image image(name);
		images.push_back(image);
	}

	void createNewParagraph(std::string name)
	{
		Paragraph paragraph(name);
		paragraphs.push_back(paragraph);
	}

	void createNewTable(std::string name)
	{
		Table table(name);
		tables.push_back(table);
	}

private:
	std::string name;
	std::vector<Image> images;
	std::vector<Paragraph> paragraphs;
	std::vector<Table> tables;
};