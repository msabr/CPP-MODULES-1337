/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:30:55 by msabr             #+#    #+#             */
/*   Updated: 2026/02/19 21:44:23 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Doc"), grade_to_sign(75) , grade_to_execute(75)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute>150)
        throw Form::GradeTooLowException();
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}

void Form::printAllInfo(std::ostream &out) const
{
    out   << name <<"\n"
                << grade_to_sign <<"\n"
                << grade_to_execute <<"\n";
    if (isSigned)
        out   << "is Signed" <<"\n";
    else
        out   << "is not Signed" <<"\n";
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}


std::ostream &operator<<(std::ostream &out, const Form &other)
{
    other.printAllInfo(out);
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

void Form::beSigned(const Bureaucrat &b)
{
    if (grade_to_sign >= grade_to_execute)
    {
        isSigned = !isSigned;
        std::cout << b.getName() << " signed " << name << std::endl;

    }
    else 
        throw Form::GradeTooLowException();
}