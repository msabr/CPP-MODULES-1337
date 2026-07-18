/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:49:21 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:49:22 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};

#endif