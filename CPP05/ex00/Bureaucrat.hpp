/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:44:35 by msabr             #+#    #+#             */
/*   Updated: 2026/02/12 15:24:48 by msabr            ###   ########.fr       */
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
        int getGrade();
        class GradeTooHighException;
        class GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception 
{
    public: 
        const char* what() const throw();
};



std::ostream &operator<<(std::ostream &out,const Bureaucrat &obj);

#endif