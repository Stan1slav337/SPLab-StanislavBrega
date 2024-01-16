#include "Image.hpp"
#include "Visitor.hpp"

void Image::accept(Visitor& v)
{
	v.visitImage(*this);
}
