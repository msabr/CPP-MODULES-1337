#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("none"){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other), target(other.target){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
	{
		throw AForm::GradeTooLowException();
	}
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::srand(std::time(0));
		if (std::rand() % 2)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}