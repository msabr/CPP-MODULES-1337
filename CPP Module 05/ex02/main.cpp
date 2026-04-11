#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout<< "===========MAIN===========" << std::endl;
    {
        Bureaucrat b("b", 137);
        AForm *f = new ShrubberyCreationForm("tree");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
	std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Bureaucrat b("b", 45);
        AForm *f = new RobotomyRequestForm("tree1");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
	std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Bureaucrat b("b", 5);
        AForm *f = new PresidentialPardonForm("tree2");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    std::cout<< "=========END BLOCK=========" << std::endl;

    return 0;
}