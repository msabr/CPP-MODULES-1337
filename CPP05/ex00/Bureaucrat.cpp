/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:01:31 by msabr             #+#    #+#             */
/*   Updated: 2026/02/10 15:48:19 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::getGrade()
{
    return this->grade;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Default Constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        this->grade = obj.grade;
    }
    std::cout << "Copy Assignment Operator called" << std::endl;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int &grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw std::runtime_error("Grade too high");
    else if (grade > 150)
        throw std::runtime_error("Grade too low");
    std::cout << "Parameterized Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Deconstructor called" << std::endl;
    
}
