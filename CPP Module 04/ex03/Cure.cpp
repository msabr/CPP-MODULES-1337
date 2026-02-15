/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:56:46 by msabr             #+#    #+#             */
/*   Updated: 2025/12/10 18:12:01 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
