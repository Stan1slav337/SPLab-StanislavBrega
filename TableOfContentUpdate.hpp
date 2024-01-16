#pragma once

#include "Visitor.hpp"
#include "AlignLeft.hpp"

#include <algorithm>

struct page
{
	std::string name{};
	bool newChapter{ false };
};

class TableOfContentUpdate : public Visitor
{
public:
	TableOfContentUpdate()
	{
		pages.clear();
		std::cout << "TableOfContent" << std::endl;
	}

	void visitBook(Book& b) override
	{
		pages.push_back({ b.get() , true });
		for (auto* content : b.getContents())
			content->accept(*this);
	}

	void visitSection(Section& s) override
	{
		pages.push_back({ s.get() , true });
		for (auto* element : s.getElements())
			element->accept(*this);
	}

	void visitParagraph(Paragraph& p) override
	{
		pages.push_back({ p.get() , false });
	}

	void visitImageProxy(ImageProxy& ip) override
	{
		Image* loadedImg = ip.loadImage();
		loadedImg->accept(*this);
	}

	void visitImage(Image& i) override
	{
		pages.push_back({ i.get() , false });
	}

	void visitTable(Table& t) override
	{
		pages.push_back({ t.get() , false });
	}

	void showTable()
	{
		size_t maxLen = 0;
		for (auto pageX : pages)
		{
			maxLen = std::max(maxLen, pageX.name.size());
		}

		for (size_t idx = 0U; idx < pages.size(); ++idx)
		{
			if (idx == 0U)
				continue;

			std::string pageName = pages[idx].name;
			bool isNewChapter    = pages[idx].newChapter;

			if (isNewChapter)
			{
				std::cout << pageName << " ";
				for (int i = 0; i < maxLen - pageName.size() + 8; ++i)
					std::cout << '.';
				std::cout << " " << idx << std::endl;
			}
		}
	}

private:
	static std::vector<page> pages;
};

