#pragma once
#include "vectorException.h"
#include <cmath>
#include <complex>

template <typename T>
class vector
{
	int size;
	T* data;
	static double eps;
public:
	vector(const int size = 2);
	vector(const vector<T>& v);
	~vector();
	T& operator [] (const int index);
	template<class T> friend std::istream& operator>> (std::istream& in, vector<T>& v);
	template<class T> friend std::ostream& operator<< (std::ostream& out, const vector<T>& v);
	vector& operator = (const vector<T>& v);
	vector operator + (const vector<T>& v);
	vector operator - (const vector<T>& v);
	T operator * (const vector<T>& v);
	template<class T> friend vector<T> operator* (const T value, vector<T> v);
	vector operator * (const T value);
	vector operator / (const T value);
	bool operator == (const vector<T>& v) const;
	bool operator != (const vector<T>& v) const;
	static const double getEps();
	static void setEps(const double& value);
};