#pragma once
#include <iostream>

class vectorException
{
	char* error;
public:
	vectorException(const char* str);
	~vectorException();
	char* getError() const;
};

class invalidValue : public vectorException
{
public:
	invalidValue();
};

class invalidIndex : public vectorException
{
public:
	invalidIndex();
};

class dimensionInequality  : public vectorException
{
public:
	dimensionInequality();
};

class zeroDividing : public vectorException
{
public:
	zeroDividing();
};

class epsInvalidRange : public vectorException
{
public:
	epsInvalidRange();
};