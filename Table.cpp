#include "Table.hpp"
#include "Visitor.hpp"

void Table::accept(Visitor& v)
{
	v.visitTable(*this);
}