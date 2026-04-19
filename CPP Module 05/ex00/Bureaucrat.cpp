#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none") , grade(150)
{
	std::cout << "Defaul constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& other): name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n, int g): name(n), grade(g)
{
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Parametred constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Defaul deconstructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
std::ostream &operator<<(std::ostream &out,const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade "
		<< other.getGrade() << "." << std::endl;
	return out;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
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


int Bureaucrat::getGrade() const
{
	return grade;
}

const std::string Bureaucrat::getName() const
{
	return name;
}
