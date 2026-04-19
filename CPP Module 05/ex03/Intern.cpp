#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(Intern& other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}
AForm	*Intern::makeForm(const std::string formName, const std::string target)
{
	std::string	forms[] = {"shrobbery creation", "robotomy request", "presidential pardon"};
	int i;
	for (i = 0;forms[i] != formName; i++)
	if (i >= 3)
	{
		std::cerr << "Invalid form name." << std::endl;
		return (NULL);
	}
	AForm		*form;
	switch (i)
	{
		case (0):
			form = new ShrubberyCreationForm(target);
		case (1):
			form = new RobotomyRequestForm(target);
		case (2):
			form = new PresidentialPardonForm(target);
	}
	std::cout << "Intern created." << std::endl;
	return (form);
}


