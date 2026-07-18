/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:49:13 by msabr             #+#    #+#             */
/*   Updated: 2026/07/18 17:49:14 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout<< "===========MAIN===========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
    std::cout<< "=========END BLOCK=========" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("unknown form", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }

    return 0;
}