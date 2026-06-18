#include "Array.hpp"

int main()
{
	std::cout << "=== Default constructor ===" << std::endl;
	Array<int> a;
	std::cout << "a.getSize() = " << a.getSize() << std::endl;

	std::cout << "\n=== Constructor with size ===" << std::endl;
	Array<int> b(5);
	std::cout << "b.getSize() = " << b.getSize() << std::endl;
	for (unsigned int i = 0; i < b.getSize(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	std::cout << "\n=== Fill b ===" << std::endl;
	for (unsigned int i = 0; i < b.getSize(); ++i)
		b[i] = i * 10;
	for (unsigned int i = 0; i < b.getSize(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> c(b);
	c[0] = 999;
	std::cout << "After c[0] = 999:" << std::endl;
	std::cout << "b[0] = " << b[0] << " (should stay 0)" << std::endl;
	std::cout << "c[0] = " << c[0] << std::endl;

	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> d;
	d = b;
	d[1] = 555;
	std::cout << "After d[1] = 555:" << std::endl;
	std::cout << "b[1] = " << b[1] << " (should stay 10)" << std::endl;
	std::cout << "d[1] = " << d[1] << std::endl;

	std::cout << "\n=== Out of bounds test ===" << std::endl;
	try
	{
		std::cout << b[42] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Const operator[] test ===" << std::endl;
	const Array<int> e(b);
	std::cout << "e[2] = " << e[2] << std::endl;

	return 0;
}