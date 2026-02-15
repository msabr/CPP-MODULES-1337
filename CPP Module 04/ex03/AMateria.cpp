/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:59:37 by msabr             #+#    #+#             */
/*   Updated: 2025/12/10 19:02:37 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}
