#include "Section.hpp"
#include "Visitor.hpp"

void Section::accept(Visitor& v)
{
	v.visitSection(*this);
}