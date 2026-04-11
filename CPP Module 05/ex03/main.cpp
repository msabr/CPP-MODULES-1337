#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout<< "===========MAIN===========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("unknown form", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }

    return 0;
}