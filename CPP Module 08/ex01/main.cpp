#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// try{
		// 	sp.addNumber(12);
		// }
		// catch (const std::exception &e)
		// {
		// 	std::cout << e.what() << std::endl;
		// }

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	
	// {
	// 	Span sp = Span(10000);
	// 	std::vector<int> vec;
	// 	for (int i = 0; i < 10000; ++i)
	// 		vec.push_back(i);

	// 	sp.addNumbers(vec.begin(), vec.end());

	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// }


	// {
	// 	Span s = Span(1);
	// 	s.addNumber(1);
	// 	try{
	// 		std::cout << s.shortestSpan() << std::endl;
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	return 0;
}