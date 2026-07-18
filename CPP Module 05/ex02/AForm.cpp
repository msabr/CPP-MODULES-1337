/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:48:27 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:48:28 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("none"), isSigned(false), gradeToSign(150), gradeToExecute(150){}

AForm::AForm(AForm& other):  name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

AForm::AForm(const std::string n, const int gs, const int ge): name(n), isSigned(false), gradeToSign(gs), gradeToExecute(ge)
{
	if (gs > 150 || ge > 150)
		throw AForm::GradeTooLowException();
	else if (gs < 1 || ge < 1)
		throw AForm::GradeTooHighException();
}

AForm& AForm::operator=(AForm& other)
{
	this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm(){}

std::ostream &operator<<(std::ostream &out,const AForm &other)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::string AForm::getName() const {return this->name;}

bool AForm::getisSigned() const {return this->isSigned;}

int AForm::getGradeToSign() const {return this->gradeToSign;}

int AForm::getGradeToExecute() const {return this->gradeToExecute;}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getisSigned() == false)
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
		std::cout << "AForm executed" << std::endl;
}