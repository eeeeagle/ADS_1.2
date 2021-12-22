#include "vector.h"

template <typename T>
double vector<T>::eps = 0.001;

template <typename T> 
T SetValue();

template<>
int SetValue()
{
	int value = 0;
	std::cin >> value;
	return value;
}

template<>
float SetValue()
{
	float value = 0.0;
	std::cin >> value;
	return value;
}

template<>
double SetValue()
{
	double value = 0.0;
	std::cin >> value;
	return value;
}

template<>
std::complex<float> SetValue()
{
	float real = 0.0, imag = 0.0;
	std::cout << "real = ";
	std::cin >> real;
	std::cout << "\timag = ";
	std::cin >> imag;
	return std::complex<float>(real, imag);
}

template<>
std::complex<double> SetValue()
{
	double real = 0.0, imag = 0.0;
	std::cout << "real = ";
	std::cin >> real;
	std::cout << "\timag = ";
	std::cin >> imag;
	return std::complex<double>(real, imag);
}

template <typename T>
vector<T>::vector(const int size)
	: size(size)
{
	if (size < 0)
		throw invalidValue();
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

template <typename T>
vector<T>::vector(const vector<T>& v)
	: size(v.size)
{
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

template <typename T>
vector<T>::~vector()
{
	delete[] data;
}

template <typename T> 
T& vector<T>::operator[](const int index)
{
	if (index < 0 || index >= size)
		throw invalidIndex();
	return data[index];
}

template <typename T> 
std::istream& operator>> (std::istream& in, vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
	{
		std::cout << "[" << i << "] = ";
		v.data[i] = SetValue<T>();
	}
	return in;
}

template <typename T> 
std::ostream& operator<< (std::ostream& out, const vector<T>& v)
{
	out << "[";
	for (int i = 0; i < v.size; i++)
	{
		out << v.data[i];
		if (i != v.size - 1)
			out << "  ";
	}
	out << "]";
	return out;
}

template <typename T> 
vector<T>& vector<T>::operator=(const vector<T>& v)
{
	delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

template <typename T> 
vector<T> vector<T>::operator+(const vector<T>& v)
{
	if (size != v.size)
		throw dimensionInequality();
	vector res(*this);
	for (int i = 0; i < size; i++)
		res.data[i] += v.data[i];
	return res;
}

template <typename T> 
vector<T> vector<T>::operator-(const vector<T>& v)
{
	if (size != v.size)
		throw dimensionInequality();
	vector res(*this);
	for (int i = 0; i < size; i++)
		res.data[i] -= v.data[i];
	return res;
}

template <typename T> 
T vector<T>::operator*(const vector<T>& v)
{
	if (size != v.size)
		throw dimensionInequality();
	T res = 0;
	for (int i = 0; i < size; i++)
		res += data[i] * v.data[i];
	return res;
}

template <typename T> 
vector<T> vector<T>::operator*(const T value)
{
	vector res(*this);
	for (int i = 0; i < size; i++)
		res[i] *= value;
	return res;
}

template <typename T> 
vector<T> operator* (const T value, vector<T> v)
{
	return (v * value);
}

template <typename T> 
vector<T> vector<T>::operator/ (const T value)
{
	if (value == (T)0)
		throw zeroDividing();
	vector res(*this);
	for (int i = 0; i < size; i++)
		res[i] /= value;
	return res;
}

template <typename T> 
bool vector<T>::operator==(const vector<T>& v) const
{
	if (size != v.size)
		throw dimensionInequality();
	T res = 0;
	for (int i = 0; i < size; i++)
		res += data[i] - v.data[i];
	if (abs(res) >= eps)
		return false;
	return true;
}

template <typename T>
bool vector<T>::operator!=(const vector<T>& v) const
{
	return !(*this == v);
}

template <typename T>
const double vector<T>::getEps()
{
	return vector<T>::eps;
}

template <typename T>
void vector<T>::setEps(const double& value)
{
	if (value <= 0.0 || value >= 1.0)
		throw epsInvalidRange();
	vector<T>::eps = value;
}