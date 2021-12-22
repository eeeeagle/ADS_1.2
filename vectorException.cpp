#include "vectorException.h"

vectorException::vectorException(const char* msg)
{
	int size = strlen(msg) + 1;
	error = new char[size];
	strncpy_s(error, size, msg, size - 1);
}

vectorException::~vectorException()
{
	delete[] error;
}

char* vectorException::getError() const
{
	return error;
}

invalidValue::invalidValue()
	: vectorException("Invalid value")
{};

invalidIndex::invalidIndex()
	: vectorException("Invalid index")
{};

dimensionInequality::dimensionInequality()
	: vectorException("Inequality of dimensions of vectors")
{};

zeroDividing::zeroDividing()
	: vectorException("Dividing to 0 is impossible")
{};

epsInvalidRange::epsInvalidRange()
	: vectorException("eps must be in range 0 < eps < 1")
{};