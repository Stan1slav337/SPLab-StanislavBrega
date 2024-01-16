#pragma once

#include "Visitor.hpp"
#include "AlignLeft.hpp"

class RenderContentVisitor : public Visitor
{
	struct page
	{
		std::string name{};
		bool newChapter{ false };
	};

public:
	RenderContentVisitor() : alignStrategy(new AlignLeft{}) {}

	void visitBook(Book& b) override
	{
		alignStrategy->render("Book " + b.get());

		alignStrategy->render("\nAuthors:\n");
		for (auto& author : b.getAuthors())
			author.print();

		alignStrategy->render("\n");
		for (auto* content : b.getContents())
			content->accept(*this);
	}

	void visitSection(Section& s) override
	{
		alignStrategy->render(s.get());

		for (auto* element : s.getElements())
			element->accept(*this);
	}

	void visitParagraph(Paragraph& p) override
	{
		alignStrategy->render(p.get());
	}

	void visitImageProxy(ImageProxy& ip) override
	{
		Image* loadedImg = ip.loadImage();
		loadedImg->accept(*this);
	}

	void visitImage(Image& i) override
	{
		alignStrategy->render("Image " + i.get());
	}

	void visitTable(Table& t) override
	{
		alignStrategy->render("Table " + t.get());
	}

	void setAlignStrategy(AlignStrategy* newStrategy)
	{
		alignStrategy = newStrategy;
	}
	
private:
	AlignStrategy* alignStrategy;
};

