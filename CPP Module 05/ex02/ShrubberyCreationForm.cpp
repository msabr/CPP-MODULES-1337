#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("none"){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other): AForm(other), target(other.target){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getisSigned())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file((this->target + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "            @          " << std::endl;
			file << "           /\\           " << std::endl;
			file << "          /**\\          " << std::endl;
			file << "         /****\\         " << std::endl;
			file << "        /******\\        " << std::endl;
			file << "       /********\\       " << std::endl;
			file << "      /**********\\      " << std::endl;
			file << "     /************\\     " << std::endl;
			file << "    /**************\\    " << std::endl;
			file << "   /****************\\   " << std::endl;
			file << "  /******************\\  " << std::endl;
			file << " /********************\\ " << std::endl;
			file << "/**********************\\" << std::endl;
			file << "          ||||          " << std::endl;
			file << "          ||||          " << std::endl;
			file << "          ||||          " << std::endl;
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
		else
			std::cout << "Error: could not create the file." << std::endl;
	}
}

