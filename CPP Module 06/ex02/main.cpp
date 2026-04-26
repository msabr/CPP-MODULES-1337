#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 4; i++)
	{
		Base *obj = generate();

		std::cout << "Via pointer : ";
		identify(obj);

		std::cout << "Via reference: ";
		identify(*obj);

		std::cout << "---\n";
		delete obj;
	}
	return 0;
}