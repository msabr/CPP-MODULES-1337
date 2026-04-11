#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern& other);
		Intern& operator=(Intern& other);
		virtual ~Intern();

		AForm* makeForm(const std::string formName, const std::string target);
};

#endif