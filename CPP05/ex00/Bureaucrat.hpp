/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:44:35 by msabr             #+#    #+#             */
/*   Updated: 2026/02/15 12:30:46 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string &name, int &grade);
        Bureaucrat& operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        int getGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception 
{
    public:
        virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception 
{
    public:
        virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream &out,const Bureaucrat &obj);

#endif