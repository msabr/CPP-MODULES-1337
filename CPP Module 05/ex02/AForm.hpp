/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:48:29 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:48:30 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAForm_HPP
#define AAForm_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm();
		AForm(AForm& other);
		AForm(const std::string n, const int gs, const int ge);
		AForm& operator=(AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getisSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
		
		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out,const AForm &other);

class AForm::GradeTooHighException: public std::exception
{
	public:
		const char* what() const throw();
};

class AForm::GradeTooLowException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif