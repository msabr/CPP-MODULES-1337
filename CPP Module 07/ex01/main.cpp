#include "Iter.hpp"

int main( void )
{
	int		array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print);

	std::string	str_array[] = {"Hello", "World", "!"};
	iter(str_array, 3, print);

	float	float_array[] = {1.1f, 2.2f, 3.3f};
	iter(float_array, 3, print);

	return 0;
}