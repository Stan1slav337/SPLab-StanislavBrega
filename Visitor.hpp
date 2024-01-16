#pragma once

#include "Book.hpp"
#include "Section.hpp"
#include "Paragraph.hpp"
#include "ImageProxy.hpp"
#include "Image.hpp"
#include "Table.hpp"

class Visitor
{
public:
	virtual void visitBook(Book&) = 0;
	virtual void visitSection(Section&) = 0;
	virtual void visitParagraph(Paragraph&) = 0;
	virtual void visitImageProxy(ImageProxy&) = 0;
	virtual void visitImage(Image&) = 0;
	virtual void visitTable(Table&) = 0;
};

