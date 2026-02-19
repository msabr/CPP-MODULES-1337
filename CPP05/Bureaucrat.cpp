/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:42:33 by msabr             #+#    #+#             */
/*   Updated: 2026/02/17 14:42:38 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string n, int g);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();
};

Bureaucrat::Bureaucrat(): name("Default") , grade(75)
{
    std::cout << "Default Constractor" << std::endl ;
}
Bureaucrat::Bureaucrat(const std::string n, int g): name(n) , grade(g)
{
    std::cout << "Parametred Constractor" << std::endl ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade)
{
    // this->name = other.name
    // this->grade = other.grade;
    
    std::cout << "Copy Constractor" << std::endl ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}