#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout<< "===========MAIN===========" << std::endl;
	try
	{
		Bureaucrat b("Mohammad", 75);
		Form f("form 1",100,1);
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<< "=========END BLOCK=========" << std::endl;
	try
	{
		Form f("form 1",151,1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<< "=========END BLOCK=========" << std::endl;
	try
	{
		Form f("form 1",0,1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<< "=========END BLOCK=========" << std::endl;
	try
	{
		Bureaucrat b("Mohammad", 75);
		Form f("form 1",100,1);
		std::cout << "Before: \n" << f ;
		f.beSigned(b);
		std::cout << "After: \n" << f ;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<< "=========END BLOCK=========" << std::endl;

	return 0;
}