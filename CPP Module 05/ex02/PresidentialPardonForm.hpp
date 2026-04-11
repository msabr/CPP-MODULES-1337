#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm& other);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm& operator=(PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};

#endif