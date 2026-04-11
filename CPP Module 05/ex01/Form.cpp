#include "Form.hpp"

Form::Form(): name("none"), isSigned(false), gradeToSign(150), gradeToExecute(150){}

Form::Form(Form& other):  name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

Form::Form(const std::string n, const int gs, const int ge): name(n), isSigned(false), gradeToSign(gs), gradeToExecute(ge)
{
	if (gs > 150 || ge > 150)
		throw Form::GradeTooHighException();
	else if (gs < 1 || ge < 1)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(Form& other)
{
	this->isSigned = other.isSigned;
	return *this;
}

Form::~Form(){}

std::ostream &operator<<(std::ostream &out,const Form &other)
{
	out << "Form Name: " << other.getName() << std::endl
		<< "grade required to sign is:    " << other.getGradeToSign() << std::endl
		<< "grade required to execute is: " << other.getGradeToExecute() << std::endl;
	if (other.getisSigned())
		out << "status: is signe";
	else
		out << "status: is not signe";
	out << std::endl;
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::string Form::getName() const {return this->name;}

bool Form::getisSigned() const {return this->isSigned;}

int Form::getGradeToSign() const {return this->gradeToSign;}

int Form::getGradeToExecute() const {return this->gradeToExecute;}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}