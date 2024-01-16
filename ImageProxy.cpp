#include "ImageProxy.hpp"
#include "Visitor.hpp"

void ImageProxy::accept(Visitor& v)
{
	v.visitImageProxy(*this);
}