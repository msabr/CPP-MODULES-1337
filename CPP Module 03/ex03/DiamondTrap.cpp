/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:31:15 by msabr             #+#    #+#             */
/*   Updated: 2025/09/20 18:20:11 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), name("") {
    std::cout << "DiamondTrap Default constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string n) : ScavTrap(), FragTrap(), name(n) {
    std::cout << "DiamondTrap Parameterized constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap Copy constructor called for " << this->name << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        *this = other;
    }
    std::cout << "DiamondTrap Copy assignment operator called for " << this->name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called for " << this->name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}




