/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:44:35 by msabr             #+#    #+#             */
/*   Updated: 2026/02/19 21:32:37 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"


class Form;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();
        int getGrade() const;
        std::string getName() const;
        class GradeTooHighException;
        class GradeTooLowException;
        void signForm(Form &form);
};

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw();
};

std::ostream &operator<<(std::ostream &out,const Bureaucrat &other);

#endif