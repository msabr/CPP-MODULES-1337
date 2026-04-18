#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};

#endif