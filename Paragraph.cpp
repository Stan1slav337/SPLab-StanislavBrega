#include "Paragraph.hpp"
#include "Visitor.hpp"

void Paragraph::accept(Visitor& v)
{
	v.visitParagraph(*this);
}
