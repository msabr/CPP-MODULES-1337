#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form();
		Form(Form& other);
		Form(const std::string n, const int gs, const int ge);
		Form& operator=(Form& other);
		~Form();

		std::string getName() const;
		bool getisSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out,const Form &other);

class Form::GradeTooHighException: public std::exception
{
	public:
		const char* what() const throw();
};

class Form::GradeTooLowException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif