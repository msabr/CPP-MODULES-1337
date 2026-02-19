/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:09:33 by msabr             #+#    #+#             */
/*   Updated: 2026/02/19 21:43:51 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;


class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form();
        Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();
        class GradeTooHighException;
        class GradeTooLowException;
        void beSigned(const Bureaucrat &b);
        void printAllInfo(std::ostream &out) const;
};

class Form::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw();
};

std::ostream &operator<<(std::ostream &out,const Form &other);

#endif