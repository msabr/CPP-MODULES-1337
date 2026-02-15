/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:06:59 by msabr             #+#    #+#             */
/*   Updated: 2025/12/10 18:31:11 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Ice::~Ice(){}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}