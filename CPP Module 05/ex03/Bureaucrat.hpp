#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat& other);
		Bureaucrat(const std::string n, int g);
		Bureaucrat& operator=(Bureaucrat &other);
		~Bureaucrat();

		void increment();
		void decrement();
		int getGrade() const;
		const std::string getName() const;

		void signForm(AForm &AForm);
		void executeForm(AForm const &form) const;

		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out,const Bureaucrat &other);

class Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		const char* what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif