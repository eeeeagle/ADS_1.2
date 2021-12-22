#include "vector.inl"
#include <conio.h>

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}

int MenuInfo()
{
	system("cls");
	std::cout << "Select data type" << std::endl << std::endl;
	std::cout << "  [1] Int" << std::endl;
	std::cout << "  [2] Float" << std::endl;
	std::cout << "  [3] Double" << std::endl;
	std::cout << "  [4] Complex<Float>" << std::endl;
	std::cout << "  [5] Complex<Double>" << std::endl << std::endl;
	std::cout << "[ESC] Exit" << std::endl;
	while (true)
	{
		int key = GetKey();
		if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 27)
			return key;
	}
}

int TestInfo()
{
	system("cls");
	std::cout << "[Enter] Start test" << std::endl;
	std::cout << "[Space] Edit eps" << std::endl;
	std::cout << "  [ESC] Return" << std::endl;
	while (true)
	{
		int key = GetKey();
		if (key == 13 || key == 32 || key == 27)
			return key;
	}
}

template <typename T>
void Test(vector<T>& a, vector<T>& b)
{
	while (true)
	{
		int key = TestInfo();
		if (key == 27)
		{
			system("cls");
			return;
		}
		try
		{
			if (key == 32)
			{
				system("cls");
				std::cout << "Enter eps in range 0 < eps < 1" << std::endl;
				std::cout << "eps = ";
				double value = SetValue<double>();
				vector<T>::setEps(value);
 			}
			if (key == 13)
			{
			
				system("cls");
				std::cout << "TEST: vector<" << typeid(T).name() << ">" << std::endl << std::endl;

				std::cout << "Fill vector a:" << std::endl;
				std::cin >> a;
				std::cout << std::endl << "Fill vector b:" << std::endl;
				std::cin >> b;

				system("cls");
				std::cout << "Vector a = " << a << std::endl;
				std::cout << "Vector b = " << b << std::endl << std::endl;
				
				std::cout << "Vector a : Enter index = ";
				int index = SetValue<int>();
				std::cout << "a[" << index << "] = " << a[index] << std::endl;
				std::cout << "Vector b : Enter index = ";
				index = SetValue<int>();
				std::cout << "b[" << index << "] = " << b[index] << std::endl << std::endl;
				
				std::cout << "a + b = " << a + b << std::endl;
				std::cout << "a - b = " << a - b << std::endl;
				std::cout << "a * b = " << a * b << std::endl << std::endl;
				
				std::cout << "Enter value = ";
				T value = SetValue<T>();
				std::cout << "a * value = " << a * value << std::endl;
				std::cout << "value * b = " << value * b << std::endl;
				std::cout << "b / value = " << b / value << std::endl << std::endl;
				
				std::cout << "a == b : ";
				if (a == b)
					std::cout << "true" << std::endl;
				else
					std::cout << "false" << std::endl;

				std::cout << "a != b : ";
				if (a != b)
					std::cout << "true";
				else
					std::cout << "false";

				std::cout << std::endl << std::endl << "eps = " << vector<T>::getEps() << std::endl << std::endl;
			
				GetKey();
			}
		}
		catch (vectorException& err)
		{
			std::cout << std::endl << std::endl << "ERROR: " << err.getError() << std::endl;
			GetKey();
		}
	}	
}

int Menu()
{
	while (true)
	{
		int key = MenuInfo();
		system("cls");
		if (key == 27)
		{
			return 0;
		}
		if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53)
		{
			try
			{
				std::cout << "Enter vector a size = ";
				int sizeA = SetValue<int>();
				std::cout << "Enter vector b size = ";
				int sizeB = SetValue<int>();
				if (key == 49)
				{
					vector<int> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 50)
				{
					vector<float> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 51)
				{
					vector<double> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 52)
				{
					vector<std::complex<float>> a(sizeA), b(sizeB);
					Test(a, b);
				}
				if (key == 53)
				{
					vector<std::complex<double>> a(sizeA), b(sizeB);
					Test(a, b);
				}
			}
			catch (vectorException & err)
			{
				std::cout << std::endl << std::endl << "ERROR: " << err.getError() << std::endl;
				err.getError();
				GetKey();
			}
		}
	}
}


int main()
{
	return Menu();
}