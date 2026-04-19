#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none") , grade(150){}

Bureaucrat::Bureaucrat(Bureaucrat& other): name(other.name), grade(other.grade){}

Bureaucrat::Bureaucrat(const std::string n, int g): name(n), grade(g)
{
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (g < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out,const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade "
		<< other.getGrade() << "." << std::endl;
	return out;
}

void Bureaucrat::increment()
{
	if (grade <= 1 )
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade >= 150 )
		throw Bureaucrat::GradeTooLowException();
	grade++;
}


int Bureaucrat::getGrade() const {return grade;}

const std::string Bureaucrat::getName() const {return name;}


void Bureaucrat::signForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}