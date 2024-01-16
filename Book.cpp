#include "Book.hpp"
#include "Visitor.hpp"

void Book::accept(Visitor& v)
{
	v.visitBook(*this);
}
