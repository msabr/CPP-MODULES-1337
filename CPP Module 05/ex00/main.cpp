#include "Bureaucrat.hpp"

int main(void)
{
	std::cout<< "===========MAIN===========" << std::endl;
    try
    {
        Bureaucrat b("Mohammad", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    try
    {
        Bureaucrat b("Mohammad", 75);
        std::cout << b ;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    try
    {
        Bureaucrat b("Mohammad", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    try
    {
        Bureaucrat b("Mohammad", 1);
        std::cout << b;
        b.increment();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    try
    {
        Bureaucrat b("Mohammad", 150);
        std::cout << b;
        b.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;

    return 0;
}