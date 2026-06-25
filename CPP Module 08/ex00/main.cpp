#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++){
		vec.push_back(i);
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 0);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
