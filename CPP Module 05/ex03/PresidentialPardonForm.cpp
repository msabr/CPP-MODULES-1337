#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("none"){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other): AForm(other), target(other.target){}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getisSigned() == false)
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}